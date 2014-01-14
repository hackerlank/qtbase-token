begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsdirect2dbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dhelpers.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2ddevicecontext.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_include
include|#
directive|include
file|<QtGui/QColor>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_using
using|using
name|Microsoft
operator|::
name|WRL
operator|::
name|ComPtr
using|;
end_using
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QWindowsDirect2DBitmapPrivate
class|class
name|QWindowsDirect2DBitmapPrivate
block|{
public|public:
DECL|function|QWindowsDirect2DBitmapPrivate
name|QWindowsDirect2DBitmapPrivate
parameter_list|(
name|ID2D1DeviceContext
modifier|*
name|dc
init|=
literal|0
parameter_list|,
name|ID2D1Bitmap1
modifier|*
name|bm
init|=
literal|0
parameter_list|)
member_init_list|:
name|bitmap
argument_list|(
name|bm
argument_list|)
member_init_list|,
name|deviceContext
argument_list|(
operator|new
name|QWindowsDirect2DDeviceContext
argument_list|(
name|dc
argument_list|)
argument_list|)
block|{
name|deviceContext
operator|->
name|get
argument_list|()
operator|->
name|SetTarget
argument_list|(
name|bm
argument_list|)
expr_stmt|;
block|}
DECL|function|bitmapProperties
name|D2D1_BITMAP_PROPERTIES1
name|bitmapProperties
parameter_list|()
specifier|const
block|{
name|FLOAT
name|dpiX
decl_stmt|,
name|dpiY
decl_stmt|;
name|QWindowsDirect2DContext
operator|::
name|instance
argument_list|()
operator|->
name|d2dFactory
argument_list|()
operator|->
name|GetDesktopDpi
argument_list|(
operator|&
name|dpiX
argument_list|,
operator|&
name|dpiY
argument_list|)
expr_stmt|;
return|return
name|D2D1
operator|::
name|BitmapProperties1
argument_list|(
name|D2D1_BITMAP_OPTIONS_TARGET
argument_list|,
name|D2D1
operator|::
name|PixelFormat
argument_list|(
name|DXGI_FORMAT_B8G8R8A8_UNORM
argument_list|,
name|D2D1_ALPHA_MODE_PREMULTIPLIED
argument_list|)
argument_list|,
name|dpiX
argument_list|,
name|dpiY
argument_list|)
return|;
block|}
DECL|function|resize
name|bool
name|resize
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
specifier|const
name|void
modifier|*
name|data
init|=
literal|0
parameter_list|,
name|int
name|pitch
init|=
literal|0
parameter_list|)
block|{
name|deviceContext
operator|->
name|get
argument_list|()
operator|->
name|SetTarget
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|bitmap
operator|.
name|Reset
argument_list|()
expr_stmt|;
name|D2D1_SIZE_U
name|size
init|=
block|{
name|width
block|,
name|height
block|}
decl_stmt|;
name|HRESULT
name|hr
init|=
name|deviceContext
operator|->
name|get
argument_list|()
operator|->
name|CreateBitmap
argument_list|(
name|size
argument_list|,
name|data
argument_list|,
name|pitch
argument_list|,
name|bitmapProperties
argument_list|()
argument_list|,
name|bitmap
operator|.
name|ReleaseAndGetAddressOf
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|hr
argument_list|)
condition|)
name|deviceContext
operator|->
name|get
argument_list|()
operator|->
name|SetTarget
argument_list|(
name|bitmap
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|qWarning
argument_list|(
literal|"%s: Could not create bitmap: %#x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|)
expr_stmt|;
return|return
name|SUCCEEDED
argument_list|(
name|hr
argument_list|)
return|;
block|}
DECL|function|toImage
name|QImage
name|toImage
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
if|if
condition|(
operator|!
name|bitmap
condition|)
return|return
name|QImage
argument_list|()
return|;
name|ComPtr
argument_list|<
name|ID2D1Bitmap1
argument_list|>
name|mappingCopy
decl_stmt|;
name|HRESULT
name|hr
init|=
name|S_OK
decl_stmt|;
name|D2D1_SIZE_U
name|size
init|=
name|bitmap
operator|->
name|GetPixelSize
argument_list|()
decl_stmt|;
name|D2D1_BITMAP_PROPERTIES1
name|properties
init|=
name|bitmapProperties
argument_list|()
decl_stmt|;
name|properties
operator|.
name|bitmapOptions
operator|=
name|D2D1_BITMAP_OPTIONS_CANNOT_DRAW
operator||
name|D2D1_BITMAP_OPTIONS_CPU_READ
expr_stmt|;
name|hr
operator|=
name|deviceContext
operator|->
name|get
argument_list|()
operator|->
name|CreateBitmap
argument_list|(
name|size
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|properties
argument_list|,
operator|&
name|mappingCopy
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: Could not create bitmap: %#x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|)
expr_stmt|;
return|return
name|QImage
argument_list|()
return|;
block|}
name|hr
operator|=
name|mappingCopy
operator|->
name|CopyFromBitmap
argument_list|(
name|NULL
argument_list|,
name|bitmap
operator|.
name|Get
argument_list|()
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: Could not copy from bitmap: %#x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|)
expr_stmt|;
return|return
name|QImage
argument_list|()
return|;
block|}
name|D2D1_MAPPED_RECT
name|mappedRect
decl_stmt|;
name|hr
operator|=
name|mappingCopy
operator|->
name|Map
argument_list|(
name|D2D1_MAP_OPTIONS_READ
argument_list|,
operator|&
name|mappedRect
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: Could not map: %#x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|)
expr_stmt|;
return|return
name|QImage
argument_list|()
return|;
block|}
return|return
name|QImage
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|uchar
operator|*
argument_list|>
argument_list|(
name|mappedRect
operator|.
name|bits
argument_list|)
argument_list|,
name|size
operator|.
name|width
argument_list|,
name|size
operator|.
name|height
argument_list|,
name|mappedRect
operator|.
name|pitch
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
operator|.
name|copy
argument_list|(
name|rect
argument_list|)
return|;
block|}
DECL|member|deviceContext
name|QScopedPointer
argument_list|<
name|QWindowsDirect2DDeviceContext
argument_list|>
name|deviceContext
decl_stmt|;
DECL|member|bitmap
name|ComPtr
argument_list|<
name|ID2D1Bitmap1
argument_list|>
name|bitmap
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QWindowsDirect2DBitmap
name|QWindowsDirect2DBitmap
operator|::
name|QWindowsDirect2DBitmap
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QWindowsDirect2DBitmapPrivate
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QWindowsDirect2DBitmap
name|QWindowsDirect2DBitmap
operator|::
name|QWindowsDirect2DBitmap
parameter_list|(
name|ID2D1Bitmap1
modifier|*
name|bitmap
parameter_list|,
name|ID2D1DeviceContext
modifier|*
name|dc
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QWindowsDirect2DBitmapPrivate
argument_list|(
name|dc
argument_list|,
name|bitmap
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QWindowsDirect2DBitmap
name|QWindowsDirect2DBitmap
operator|::
name|~
name|QWindowsDirect2DBitmap
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|resize
name|bool
name|QWindowsDirect2DBitmap
operator|::
name|resize
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWindowsDirect2DBitmap
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|resize
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|fromImage
name|bool
name|QWindowsDirect2DBitmap
operator|::
name|fromImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWindowsDirect2DBitmap
argument_list|)
expr_stmt|;
name|QImage
name|converted
init|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|,
name|flags
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|resize
argument_list|(
name|converted
operator|.
name|width
argument_list|()
argument_list|,
name|converted
operator|.
name|height
argument_list|()
argument_list|,
name|converted
operator|.
name|constBits
argument_list|()
argument_list|,
name|converted
operator|.
name|bytesPerLine
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|bitmap
name|ID2D1Bitmap1
modifier|*
name|QWindowsDirect2DBitmap
operator|::
name|bitmap
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindowsDirect2DBitmap
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|bitmap
operator|.
name|Get
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|deviceContext
name|QWindowsDirect2DDeviceContext
modifier|*
name|QWindowsDirect2DBitmap
operator|::
name|deviceContext
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindowsDirect2DBitmap
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|deviceContext
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|fill
name|void
name|QWindowsDirect2DBitmap
operator|::
name|fill
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWindowsDirect2DBitmap
argument_list|)
expr_stmt|;
name|d
operator|->
name|deviceContext
operator|->
name|begin
argument_list|()
expr_stmt|;
name|d
operator|->
name|deviceContext
operator|->
name|get
argument_list|()
operator|->
name|Clear
argument_list|(
name|to_d2d_color_f
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|deviceContext
operator|->
name|end
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toImage
name|QImage
name|QWindowsDirect2DBitmap
operator|::
name|toImage
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWindowsDirect2DBitmap
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|toImage
argument_list|(
name|rect
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|size
name|QSize
name|QWindowsDirect2DBitmap
operator|::
name|size
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindowsDirect2DBitmap
argument_list|)
expr_stmt|;
name|D2D1_SIZE_U
name|size
init|=
name|d
operator|->
name|bitmap
operator|->
name|GetPixelSize
argument_list|()
decl_stmt|;
return|return
name|QSize
argument_list|(
name|size
operator|.
name|width
argument_list|,
name|size
operator|.
name|height
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit