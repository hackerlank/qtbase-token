begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsnativeimage.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscontext.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpaintengine_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpaintengine_raster_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|bmiHeader
name|BITMAPINFOHEADER
name|bmiHeader
decl_stmt|;
DECL|member|redMask
name|DWORD
name|redMask
decl_stmt|;
DECL|member|greenMask
name|DWORD
name|greenMask
decl_stmt|;
DECL|member|blueMask
name|DWORD
name|blueMask
decl_stmt|;
block|}
DECL|typedef|BITMAPINFO_MASK
name|BITMAPINFO_MASK
typedef|;
end_typedef
begin_comment
comment|/*!     \class QWindowsNativeImage     \brief Windows Native image      Note that size can be 0 (widget autotests with zero size), which     causes CreateDIBSection() to fail.      \sa QWindowsBackingStore     \internal     \ingroup qt-lighthouse-win */
end_comment
begin_function
DECL|function|createDC
specifier|static
specifier|inline
name|HDC
name|createDC
parameter_list|()
block|{
name|HDC
name|display_dc
init|=
name|GetDC
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|HDC
name|hdc
init|=
name|CreateCompatibleDC
argument_list|(
name|display_dc
argument_list|)
decl_stmt|;
name|ReleaseDC
argument_list|(
literal|0
argument_list|,
name|display_dc
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|hdc
argument_list|)
expr_stmt|;
return|return
name|hdc
return|;
block|}
end_function
begin_function
DECL|function|createDIB
specifier|static
specifier|inline
name|HBITMAP
name|createDIB
parameter_list|(
name|HDC
name|hdc
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|QImage
operator|::
name|Format
name|format
parameter_list|,
name|uchar
modifier|*
modifier|*
name|bitsIn
parameter_list|)
block|{
name|BITMAPINFO_MASK
name|bmi
decl_stmt|;
name|memset
argument_list|(
operator|&
name|bmi
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|bmi
argument_list|)
argument_list|)
expr_stmt|;
name|bmi
operator|.
name|bmiHeader
operator|.
name|biSize
operator|=
sizeof|sizeof
argument_list|(
name|BITMAPINFOHEADER
argument_list|)
expr_stmt|;
name|bmi
operator|.
name|bmiHeader
operator|.
name|biWidth
operator|=
name|width
expr_stmt|;
name|bmi
operator|.
name|bmiHeader
operator|.
name|biHeight
operator|=
operator|-
name|height
expr_stmt|;
comment|// top-down.
name|bmi
operator|.
name|bmiHeader
operator|.
name|biPlanes
operator|=
literal|1
expr_stmt|;
name|bmi
operator|.
name|bmiHeader
operator|.
name|biSizeImage
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|format
operator|==
name|QImage
operator|::
name|Format_RGB16
condition|)
block|{
name|bmi
operator|.
name|bmiHeader
operator|.
name|biBitCount
operator|=
literal|16
expr_stmt|;
name|bmi
operator|.
name|bmiHeader
operator|.
name|biCompression
operator|=
name|BI_BITFIELDS
expr_stmt|;
name|bmi
operator|.
name|redMask
operator|=
literal|0xF800
expr_stmt|;
name|bmi
operator|.
name|greenMask
operator|=
literal|0x07E0
expr_stmt|;
name|bmi
operator|.
name|blueMask
operator|=
literal|0x001F
expr_stmt|;
block|}
else|else
block|{
name|bmi
operator|.
name|bmiHeader
operator|.
name|biBitCount
operator|=
literal|32
expr_stmt|;
name|bmi
operator|.
name|bmiHeader
operator|.
name|biCompression
operator|=
name|BI_RGB
expr_stmt|;
name|bmi
operator|.
name|redMask
operator|=
literal|0
expr_stmt|;
name|bmi
operator|.
name|greenMask
operator|=
literal|0
expr_stmt|;
name|bmi
operator|.
name|blueMask
operator|=
literal|0
expr_stmt|;
block|}
name|uchar
modifier|*
name|bits
init|=
name|Q_NULLPTR
decl_stmt|;
name|HBITMAP
name|bitmap
init|=
name|CreateDIBSection
argument_list|(
name|hdc
argument_list|,
cast|reinterpret_cast
argument_list|<
name|BITMAPINFO
operator|*
argument_list|>
argument_list|(
operator|&
name|bmi
argument_list|)
argument_list|,
name|DIB_RGB_COLORS
argument_list|,
cast|reinterpret_cast
argument_list|<
name|void
operator|*
operator|*
argument_list|>
argument_list|(
operator|&
name|bits
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|!
name|bitmap
operator|||
operator|!
name|bits
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"%s: CreateDIBSection failed."
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
operator|*
name|bitsIn
operator|=
name|bits
expr_stmt|;
return|return
name|bitmap
return|;
block|}
end_function
begin_constructor
DECL|function|QWindowsNativeImage
name|QWindowsNativeImage
operator|::
name|QWindowsNativeImage
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|QImage
operator|::
name|Format
name|format
parameter_list|)
member_init_list|:
name|m_hdc
argument_list|(
name|createDC
argument_list|()
argument_list|)
member_init_list|,
name|m_bitmap
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_null_bitmap
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|width
operator|!=
literal|0
operator|&&
name|height
operator|!=
literal|0
condition|)
block|{
name|uchar
modifier|*
name|bits
decl_stmt|;
name|m_bitmap
operator|=
name|createDIB
argument_list|(
name|m_hdc
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|format
argument_list|,
operator|&
name|bits
argument_list|)
expr_stmt|;
name|m_null_bitmap
operator|=
cast|static_cast
argument_list|<
name|HBITMAP
argument_list|>
argument_list|(
name|SelectObject
argument_list|(
name|m_hdc
argument_list|,
name|m_bitmap
argument_list|)
argument_list|)
expr_stmt|;
name|m_image
operator|=
name|QImage
argument_list|(
name|bits
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|m_image
operator|.
name|paintEngine
argument_list|()
operator|->
name|type
argument_list|()
operator|==
name|QPaintEngine
operator|::
name|Raster
argument_list|)
expr_stmt|;
cast|static_cast
argument_list|<
name|QRasterPaintEngine
operator|*
argument_list|>
argument_list|(
name|m_image
operator|.
name|paintEngine
argument_list|()
argument_list|)
operator|->
name|setDC
argument_list|(
name|m_hdc
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_image
operator|=
name|QImage
argument_list|(
name|width
argument_list|,
name|height
argument_list|,
name|format
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|GdiFlush
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_constructor
begin_destructor
DECL|function|~QWindowsNativeImage
name|QWindowsNativeImage
operator|::
name|~
name|QWindowsNativeImage
parameter_list|()
block|{
if|if
condition|(
name|m_hdc
condition|)
block|{
if|if
condition|(
name|m_bitmap
condition|)
block|{
if|if
condition|(
name|m_null_bitmap
condition|)
name|SelectObject
argument_list|(
name|m_hdc
argument_list|,
name|m_null_bitmap
argument_list|)
expr_stmt|;
name|DeleteObject
argument_list|(
name|m_bitmap
argument_list|)
expr_stmt|;
block|}
name|DeleteDC
argument_list|(
name|m_hdc
argument_list|)
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|systemFormat
name|QImage
operator|::
name|Format
name|QWindowsNativeImage
operator|::
name|systemFormat
parameter_list|()
block|{
specifier|static
specifier|const
name|int
name|depth
init|=
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|screenDepth
argument_list|()
decl_stmt|;
return|return
name|depth
operator|==
literal|16
condition|?
name|QImage
operator|::
name|Format_RGB16
else|:
name|QImage
operator|::
name|Format_RGB32
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
