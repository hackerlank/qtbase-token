begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qpixmap.h"
end_include
begin_include
include|#
directive|include
file|"qpixmap_raster_p.h"
end_include
begin_include
include|#
directive|include
file|"qbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qimage.h"
end_include
begin_include
include|#
directive|include
file|"qwidget.h"
end_include
begin_include
include|#
directive|include
file|"qpainter.h"
end_include
begin_include
include|#
directive|include
file|"qdatastream.h"
end_include
begin_include
include|#
directive|include
file|"qbuffer.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"qfile.h"
end_include
begin_include
include|#
directive|include
file|"qfileinfo.h"
end_include
begin_include
include|#
directive|include
file|"qdatetime.h"
end_include
begin_include
include|#
directive|include
file|"qpixmapcache.h"
end_include
begin_include
include|#
directive|include
file|"qimagereader.h"
end_include
begin_include
include|#
directive|include
file|"qimagewriter.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|"qt_windows.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WINCE
argument_list|)
end_if
begin_include
include|#
directive|include
file|<winbase.h>
end_include
begin_include
include|#
directive|include
file|"qguifunctions_wince.h"
end_include
begin_function_decl
specifier|extern
name|bool
name|qt_wince_is_high_dpi
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|bool
name|qt_wince_is_pocket_pc
parameter_list|()
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|CAPTUREBLT
end_ifndef
begin_define
DECL|macro|CAPTUREBLT
define|#
directive|define
name|CAPTUREBLT
value|((DWORD)0x40000000)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|grabWindow
name|QPixmap
name|QPixmap
operator|::
name|grabWindow
parameter_list|(
name|WId
name|winId
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
block|{
name|RECT
name|r
decl_stmt|;
name|GetClientRect
argument_list|(
name|winId
argument_list|,
operator|&
name|r
argument_list|)
expr_stmt|;
if|if
condition|(
name|w
operator|<
literal|0
condition|)
name|w
operator|=
name|r
operator|.
name|right
operator|-
name|r
operator|.
name|left
expr_stmt|;
if|if
condition|(
name|h
operator|<
literal|0
condition|)
name|h
operator|=
name|r
operator|.
name|bottom
operator|-
name|r
operator|.
name|top
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_WINCE_WM
if|if
condition|(
name|qt_wince_is_pocket_pc
argument_list|()
condition|)
block|{
name|QWidget
modifier|*
name|widget
init|=
name|QWidget
operator|::
name|find
argument_list|(
name|winId
argument_list|)
decl_stmt|;
if|if
condition|(
name|qobject_cast
argument_list|<
name|QDesktopWidget
operator|*
argument_list|>
argument_list|(
name|widget
argument_list|)
condition|)
block|{
name|RECT
name|rect
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|AdjustWindowRectEx
argument_list|(
operator|&
name|rect
argument_list|,
name|WS_BORDER
operator||
name|WS_CAPTION
argument_list|,
name|FALSE
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|int
name|magicNumber
init|=
name|qt_wince_is_high_dpi
argument_list|()
condition|?
literal|4
else|:
literal|2
decl_stmt|;
name|y
operator|+=
name|rect
operator|.
name|top
operator|-
name|magicNumber
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|// Create and setup bitmap
name|HDC
name|display_dc
init|=
name|GetDC
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|HDC
name|bitmap_dc
init|=
name|CreateCompatibleDC
argument_list|(
name|display_dc
argument_list|)
decl_stmt|;
name|HBITMAP
name|bitmap
init|=
name|CreateCompatibleBitmap
argument_list|(
name|display_dc
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
decl_stmt|;
name|HGDIOBJ
name|null_bitmap
init|=
name|SelectObject
argument_list|(
name|bitmap_dc
argument_list|,
name|bitmap
argument_list|)
decl_stmt|;
comment|// copy data
name|HDC
name|window_dc
init|=
name|GetDC
argument_list|(
name|winId
argument_list|)
decl_stmt|;
name|BitBlt
argument_list|(
name|bitmap_dc
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
name|window_dc
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|SRCCOPY
ifndef|#
directive|ifndef
name|Q_WS_WINCE
operator||
name|CAPTUREBLT
endif|#
directive|endif
argument_list|)
expr_stmt|;
comment|// clean up all but bitmap
name|ReleaseDC
argument_list|(
name|winId
argument_list|,
name|window_dc
argument_list|)
expr_stmt|;
name|SelectObject
argument_list|(
name|bitmap_dc
argument_list|,
name|null_bitmap
argument_list|)
expr_stmt|;
name|DeleteDC
argument_list|(
name|bitmap_dc
argument_list|)
expr_stmt|;
name|QPixmap
name|pixmap
init|=
name|QPixmap
operator|::
name|fromWinHBITMAP
argument_list|(
name|bitmap
argument_list|)
decl_stmt|;
name|DeleteObject
argument_list|(
name|bitmap
argument_list|)
expr_stmt|;
name|ReleaseDC
argument_list|(
literal|0
argument_list|,
name|display_dc
argument_list|)
expr_stmt|;
return|return
name|pixmap
return|;
block|}
end_function
begin_function
DECL|function|toWinHBITMAP
name|HBITMAP
name|QPixmap
operator|::
name|toWinHBITMAP
parameter_list|(
name|HBitmapFormat
name|format
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|isNull
argument_list|()
condition|)
return|return
literal|0
return|;
name|HBITMAP
name|bitmap
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|data
operator|->
name|classId
argument_list|()
operator|==
name|QPlatformPixmap
operator|::
name|RasterClass
condition|)
block|{
name|QRasterPlatformPixmap
modifier|*
name|d
init|=
cast|static_cast
argument_list|<
name|QRasterPlatformPixmap
operator|*
argument_list|>
argument_list|(
name|data
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|w
init|=
name|d
operator|->
name|image
operator|.
name|width
argument_list|()
decl_stmt|;
name|int
name|h
init|=
name|d
operator|->
name|image
operator|.
name|height
argument_list|()
decl_stmt|;
name|HDC
name|display_dc
init|=
name|GetDC
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|// Define the header
name|BITMAPINFO
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
name|w
expr_stmt|;
name|bmi
operator|.
name|bmiHeader
operator|.
name|biHeight
operator|=
operator|-
name|h
expr_stmt|;
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
name|bmiHeader
operator|.
name|biSizeImage
operator|=
name|w
operator|*
name|h
operator|*
literal|4
expr_stmt|;
comment|// Create the pixmap
name|uchar
modifier|*
name|pixels
init|=
literal|0
decl_stmt|;
name|bitmap
operator|=
name|CreateDIBSection
argument_list|(
name|display_dc
argument_list|,
operator|&
name|bmi
argument_list|,
name|DIB_RGB_COLORS
argument_list|,
operator|(
name|void
operator|*
operator|*
operator|)
operator|&
name|pixels
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ReleaseDC
argument_list|(
literal|0
argument_list|,
name|display_dc
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|bitmap
condition|)
block|{
name|qErrnoWarning
argument_list|(
literal|"QPixmap::toWinHBITMAP(), failed to create dibsection"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
operator|!
name|pixels
condition|)
block|{
name|qErrnoWarning
argument_list|(
literal|"QPixmap::toWinHBITMAP(), did not allocate pixel data"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|// Copy over the data
name|QImage
operator|::
name|Format
name|imageFormat
init|=
name|QImage
operator|::
name|Format_ARGB32
decl_stmt|;
if|if
condition|(
name|format
operator|==
name|NoAlpha
condition|)
name|imageFormat
operator|=
name|QImage
operator|::
name|Format_RGB32
expr_stmt|;
elseif|else
if|if
condition|(
name|format
operator|==
name|PremultipliedAlpha
condition|)
name|imageFormat
operator|=
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
expr_stmt|;
specifier|const
name|QImage
name|image
init|=
name|d
operator|->
name|image
operator|.
name|convertToFormat
argument_list|(
name|imageFormat
argument_list|)
decl_stmt|;
name|int
name|bytes_per_line
init|=
name|w
operator|*
literal|4
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
operator|++
name|y
control|)
name|memcpy
argument_list|(
name|pixels
operator|+
name|y
operator|*
name|bytes_per_line
argument_list|,
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
argument_list|,
name|bytes_per_line
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QPlatformPixmap
modifier|*
name|data
init|=
operator|new
name|QRasterPlatformPixmap
argument_list|(
name|depth
argument_list|()
operator|==
literal|1
condition|?
name|QPlatformPixmap
operator|::
name|BitmapType
else|:
name|QPlatformPixmap
operator|::
name|PixmapType
argument_list|)
decl_stmt|;
name|data
operator|->
name|fromImage
argument_list|(
name|toImage
argument_list|()
argument_list|,
name|Qt
operator|::
name|AutoColor
argument_list|)
expr_stmt|;
return|return
name|QPixmap
argument_list|(
name|data
argument_list|)
operator|.
name|toWinHBITMAP
argument_list|(
name|format
argument_list|)
return|;
block|}
return|return
name|bitmap
return|;
block|}
end_function
begin_function
DECL|function|fromWinHBITMAP
name|QPixmap
name|QPixmap
operator|::
name|fromWinHBITMAP
parameter_list|(
name|HBITMAP
name|bitmap
parameter_list|,
name|HBitmapFormat
name|format
parameter_list|)
block|{
comment|// Verify size
name|BITMAP
name|bitmap_info
decl_stmt|;
name|memset
argument_list|(
operator|&
name|bitmap_info
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|BITMAP
argument_list|)
argument_list|)
expr_stmt|;
name|int
name|res
init|=
name|GetObject
argument_list|(
name|bitmap
argument_list|,
sizeof|sizeof
argument_list|(
name|BITMAP
argument_list|)
argument_list|,
operator|&
name|bitmap_info
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|res
condition|)
block|{
name|qErrnoWarning
argument_list|(
literal|"QPixmap::fromWinHBITMAP(), failed to get bitmap info"
argument_list|)
expr_stmt|;
return|return
name|QPixmap
argument_list|()
return|;
block|}
name|int
name|w
init|=
name|bitmap_info
operator|.
name|bmWidth
decl_stmt|;
name|int
name|h
init|=
name|bitmap_info
operator|.
name|bmHeight
decl_stmt|;
name|BITMAPINFO
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
name|w
expr_stmt|;
name|bmi
operator|.
name|bmiHeader
operator|.
name|biHeight
operator|=
operator|-
name|h
expr_stmt|;
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
name|bmiHeader
operator|.
name|biSizeImage
operator|=
name|w
operator|*
name|h
operator|*
literal|4
expr_stmt|;
name|QImage
name|result
decl_stmt|;
comment|// Get bitmap bits
name|uchar
modifier|*
name|data
init|=
operator|(
name|uchar
operator|*
operator|)
name|qMalloc
argument_list|(
name|bmi
operator|.
name|bmiHeader
operator|.
name|biSizeImage
argument_list|)
decl_stmt|;
name|HDC
name|display_dc
init|=
name|GetDC
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|GetDIBits
argument_list|(
name|display_dc
argument_list|,
name|bitmap
argument_list|,
literal|0
argument_list|,
name|h
argument_list|,
name|data
argument_list|,
operator|&
name|bmi
argument_list|,
name|DIB_RGB_COLORS
argument_list|)
condition|)
block|{
name|QImage
operator|::
name|Format
name|imageFormat
init|=
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
decl_stmt|;
name|uint
name|mask
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|format
operator|==
name|NoAlpha
condition|)
block|{
name|imageFormat
operator|=
name|QImage
operator|::
name|Format_RGB32
expr_stmt|;
name|mask
operator|=
literal|0xff000000
expr_stmt|;
block|}
comment|// Create image and copy data into image.
name|QImage
name|image
argument_list|(
name|w
argument_list|,
name|h
argument_list|,
name|imageFormat
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|image
operator|.
name|isNull
argument_list|()
condition|)
block|{
comment|// failed to alloc?
name|int
name|bytes_per_line
init|=
name|w
operator|*
sizeof|sizeof
argument_list|(
name|QRgb
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
operator|++
name|y
control|)
block|{
name|QRgb
modifier|*
name|dest
init|=
operator|(
name|QRgb
operator|*
operator|)
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
specifier|const
name|QRgb
modifier|*
name|src
init|=
operator|(
specifier|const
name|QRgb
operator|*
operator|)
operator|(
name|data
operator|+
name|y
operator|*
name|bytes_per_line
operator|)
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|w
condition|;
operator|++
name|x
control|)
block|{
specifier|const
name|uint
name|pixel
init|=
name|src
index|[
name|x
index|]
decl_stmt|;
if|if
condition|(
operator|(
name|pixel
operator|&
literal|0xff000000
operator|)
operator|==
literal|0
operator|&&
operator|(
name|pixel
operator|&
literal|0x00ffffff
operator|)
operator|!=
literal|0
condition|)
name|dest
index|[
name|x
index|]
operator|=
name|pixel
operator||
literal|0xff000000
expr_stmt|;
else|else
name|dest
index|[
name|x
index|]
operator|=
name|pixel
operator||
name|mask
expr_stmt|;
block|}
block|}
block|}
name|result
operator|=
name|image
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QPixmap::fromWinHBITMAP(), failed to get bitmap bits"
argument_list|)
expr_stmt|;
block|}
name|ReleaseDC
argument_list|(
literal|0
argument_list|,
name|display_dc
argument_list|)
expr_stmt|;
name|qFree
argument_list|(
name|data
argument_list|)
expr_stmt|;
return|return
name|fromImage
argument_list|(
name|result
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_createIconMask
name|HBITMAP
name|qt_createIconMask
parameter_list|(
specifier|const
name|QBitmap
modifier|&
name|bitmap
parameter_list|)
block|{
name|QImage
name|bm
init|=
name|bitmap
operator|.
name|toImage
argument_list|()
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_Mono
argument_list|)
decl_stmt|;
name|int
name|w
init|=
name|bm
operator|.
name|width
argument_list|()
decl_stmt|;
name|int
name|h
init|=
name|bm
operator|.
name|height
argument_list|()
decl_stmt|;
name|int
name|bpl
init|=
operator|(
operator|(
name|w
operator|+
literal|15
operator|)
operator|/
literal|16
operator|)
operator|*
literal|2
decl_stmt|;
comment|// bpl, 16 bit alignment
name|uchar
modifier|*
name|bits
init|=
operator|new
name|uchar
index|[
name|bpl
operator|*
name|h
index|]
decl_stmt|;
name|bm
operator|.
name|invertPixels
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
name|y
operator|++
control|)
name|memcpy
argument_list|(
name|bits
operator|+
name|y
operator|*
name|bpl
argument_list|,
name|bm
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
argument_list|,
name|bpl
argument_list|)
expr_stmt|;
name|HBITMAP
name|hbm
init|=
name|CreateBitmap
argument_list|(
name|w
argument_list|,
name|h
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
name|bits
argument_list|)
decl_stmt|;
operator|delete
index|[]
name|bits
expr_stmt|;
return|return
name|hbm
return|;
block|}
end_function
begin_function
DECL|function|toWinHICON
name|HICON
name|QPixmap
operator|::
name|toWinHICON
parameter_list|()
specifier|const
block|{
name|QBitmap
name|maskBitmap
init|=
name|mask
argument_list|()
decl_stmt|;
if|if
condition|(
name|maskBitmap
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|maskBitmap
operator|=
name|QBitmap
argument_list|(
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|maskBitmap
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|color1
argument_list|)
expr_stmt|;
block|}
name|ICONINFO
name|ii
decl_stmt|;
name|ii
operator|.
name|fIcon
operator|=
literal|true
expr_stmt|;
name|ii
operator|.
name|hbmMask
operator|=
name|qt_createIconMask
argument_list|(
name|maskBitmap
argument_list|)
expr_stmt|;
name|ii
operator|.
name|hbmColor
operator|=
name|toWinHBITMAP
argument_list|(
name|QPixmap
operator|::
name|Alpha
argument_list|)
expr_stmt|;
name|ii
operator|.
name|xHotspot
operator|=
literal|0
expr_stmt|;
name|ii
operator|.
name|yHotspot
operator|=
literal|0
expr_stmt|;
name|HICON
name|hIcon
init|=
name|CreateIconIndirect
argument_list|(
operator|&
name|ii
argument_list|)
decl_stmt|;
name|DeleteObject
argument_list|(
name|ii
operator|.
name|hbmColor
argument_list|)
expr_stmt|;
name|DeleteObject
argument_list|(
name|ii
operator|.
name|hbmMask
argument_list|)
expr_stmt|;
return|return
name|hIcon
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WIN
end_ifdef
begin_ifndef
ifndef|#
directive|ifndef
name|Q_WS_WINCE
end_ifndef
begin_function
DECL|function|qt_fromWinHBITMAP
specifier|static
name|QImage
name|qt_fromWinHBITMAP
parameter_list|(
name|HDC
name|hdc
parameter_list|,
name|HBITMAP
name|bitmap
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
block|{
name|BITMAPINFO
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
name|w
expr_stmt|;
name|bmi
operator|.
name|bmiHeader
operator|.
name|biHeight
operator|=
operator|-
name|h
expr_stmt|;
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
name|bmiHeader
operator|.
name|biSizeImage
operator|=
name|w
operator|*
name|h
operator|*
literal|4
expr_stmt|;
name|QImage
name|image
argument_list|(
name|w
argument_list|,
name|h
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl_stmt|;
if|if
condition|(
name|image
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|image
return|;
comment|// Get bitmap bits
name|uchar
modifier|*
name|data
init|=
operator|(
name|uchar
operator|*
operator|)
name|qMalloc
argument_list|(
name|bmi
operator|.
name|bmiHeader
operator|.
name|biSizeImage
argument_list|)
decl_stmt|;
if|if
condition|(
name|GetDIBits
argument_list|(
name|hdc
argument_list|,
name|bitmap
argument_list|,
literal|0
argument_list|,
name|h
argument_list|,
name|data
argument_list|,
operator|&
name|bmi
argument_list|,
name|DIB_RGB_COLORS
argument_list|)
condition|)
block|{
comment|// Create image and copy data into image.
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
operator|++
name|y
control|)
block|{
name|void
modifier|*
name|dest
init|=
operator|(
name|void
operator|*
operator|)
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
name|void
modifier|*
name|src
init|=
name|data
operator|+
name|y
operator|*
name|image
operator|.
name|bytesPerLine
argument_list|()
decl_stmt|;
name|memcpy
argument_list|(
name|dest
argument_list|,
name|src
argument_list|,
name|image
operator|.
name|bytesPerLine
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"qt_fromWinHBITMAP(), failed to get bitmap bits"
argument_list|)
expr_stmt|;
block|}
name|qFree
argument_list|(
name|data
argument_list|)
expr_stmt|;
return|return
name|image
return|;
block|}
end_function
begin_function
DECL|function|fromWinHICON
name|QPixmap
name|QPixmap
operator|::
name|fromWinHICON
parameter_list|(
name|HICON
name|icon
parameter_list|)
block|{
name|bool
name|foundAlpha
init|=
literal|false
decl_stmt|;
name|HDC
name|screenDevice
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
name|screenDevice
argument_list|)
decl_stmt|;
name|ReleaseDC
argument_list|(
literal|0
argument_list|,
name|screenDevice
argument_list|)
expr_stmt|;
name|ICONINFO
name|iconinfo
decl_stmt|;
name|bool
name|result
init|=
name|GetIconInfo
argument_list|(
name|icon
argument_list|,
operator|&
name|iconinfo
argument_list|)
decl_stmt|;
comment|//x and y Hotspot describes the icon center
if|if
condition|(
operator|!
name|result
condition|)
name|qWarning
argument_list|(
literal|"QPixmap::fromWinHICON(), failed to GetIconInfo()"
argument_list|)
expr_stmt|;
name|int
name|w
init|=
name|iconinfo
operator|.
name|xHotspot
operator|*
literal|2
decl_stmt|;
name|int
name|h
init|=
name|iconinfo
operator|.
name|yHotspot
operator|*
literal|2
decl_stmt|;
name|BITMAPINFOHEADER
name|bitmapInfo
decl_stmt|;
name|bitmapInfo
operator|.
name|biSize
operator|=
sizeof|sizeof
argument_list|(
name|BITMAPINFOHEADER
argument_list|)
expr_stmt|;
name|bitmapInfo
operator|.
name|biWidth
operator|=
name|w
expr_stmt|;
name|bitmapInfo
operator|.
name|biHeight
operator|=
name|h
expr_stmt|;
name|bitmapInfo
operator|.
name|biPlanes
operator|=
literal|1
expr_stmt|;
name|bitmapInfo
operator|.
name|biBitCount
operator|=
literal|32
expr_stmt|;
name|bitmapInfo
operator|.
name|biCompression
operator|=
name|BI_RGB
expr_stmt|;
name|bitmapInfo
operator|.
name|biSizeImage
operator|=
literal|0
expr_stmt|;
name|bitmapInfo
operator|.
name|biXPelsPerMeter
operator|=
literal|0
expr_stmt|;
name|bitmapInfo
operator|.
name|biYPelsPerMeter
operator|=
literal|0
expr_stmt|;
name|bitmapInfo
operator|.
name|biClrUsed
operator|=
literal|0
expr_stmt|;
name|bitmapInfo
operator|.
name|biClrImportant
operator|=
literal|0
expr_stmt|;
name|DWORD
modifier|*
name|bits
decl_stmt|;
name|HBITMAP
name|winBitmap
init|=
name|CreateDIBSection
argument_list|(
name|hdc
argument_list|,
operator|(
name|BITMAPINFO
operator|*
operator|)
operator|&
name|bitmapInfo
argument_list|,
name|DIB_RGB_COLORS
argument_list|,
operator|(
name|VOID
operator|*
operator|*
operator|)
operator|&
name|bits
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|HGDIOBJ
name|oldhdc
init|=
operator|(
name|HBITMAP
operator|)
name|SelectObject
argument_list|(
name|hdc
argument_list|,
name|winBitmap
argument_list|)
decl_stmt|;
name|DrawIconEx
argument_list|(
name|hdc
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|icon
argument_list|,
name|iconinfo
operator|.
name|xHotspot
operator|*
literal|2
argument_list|,
name|iconinfo
operator|.
name|yHotspot
operator|*
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|DI_NORMAL
argument_list|)
expr_stmt|;
name|QImage
name|image
init|=
name|qt_fromWinHBITMAP
argument_list|(
name|hdc
argument_list|,
name|winBitmap
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
operator|&&
operator|!
name|foundAlpha
condition|;
name|y
operator|++
control|)
block|{
name|QRgb
modifier|*
name|scanLine
init|=
cast|reinterpret_cast
argument_list|<
name|QRgb
operator|*
argument_list|>
argument_list|(
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|w
condition|;
name|x
operator|++
control|)
block|{
if|if
condition|(
name|qAlpha
argument_list|(
name|scanLine
index|[
name|x
index|]
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|foundAlpha
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
block|}
if|if
condition|(
operator|!
name|foundAlpha
condition|)
block|{
comment|//If no alpha was found, we use the mask to set alpha values
name|DrawIconEx
argument_list|(
name|hdc
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|icon
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|DI_MASK
argument_list|)
expr_stmt|;
name|QImage
name|mask
init|=
name|qt_fromWinHBITMAP
argument_list|(
name|hdc
argument_list|,
name|winBitmap
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
name|y
operator|++
control|)
block|{
name|QRgb
modifier|*
name|scanlineImage
init|=
cast|reinterpret_cast
argument_list|<
name|QRgb
operator|*
argument_list|>
argument_list|(
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
argument_list|)
decl_stmt|;
name|QRgb
modifier|*
name|scanlineMask
init|=
name|mask
operator|.
name|isNull
argument_list|()
condition|?
literal|0
else|:
cast|reinterpret_cast
argument_list|<
name|QRgb
operator|*
argument_list|>
argument_list|(
name|mask
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|w
condition|;
name|x
operator|++
control|)
block|{
if|if
condition|(
name|scanlineMask
operator|&&
name|qRed
argument_list|(
name|scanlineMask
index|[
name|x
index|]
argument_list|)
operator|!=
literal|0
condition|)
name|scanlineImage
index|[
name|x
index|]
operator|=
literal|0
expr_stmt|;
comment|//mask out this pixel
else|else
name|scanlineImage
index|[
name|x
index|]
operator||=
literal|0xff000000
expr_stmt|;
comment|// set the alpha channel to 255
block|}
block|}
block|}
comment|//dispose resources created by iconinfo call
name|DeleteObject
argument_list|(
name|iconinfo
operator|.
name|hbmMask
argument_list|)
expr_stmt|;
name|DeleteObject
argument_list|(
name|iconinfo
operator|.
name|hbmColor
argument_list|)
expr_stmt|;
name|SelectObject
argument_list|(
name|hdc
argument_list|,
name|oldhdc
argument_list|)
expr_stmt|;
comment|//restore state
name|DeleteObject
argument_list|(
name|winBitmap
argument_list|)
expr_stmt|;
name|DeleteDC
argument_list|(
name|hdc
argument_list|)
expr_stmt|;
return|return
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|image
argument_list|)
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_comment
comment|//ifndef Q_WS_WINCE
end_comment
begin_function
DECL|function|fromWinHICON
name|QPixmap
name|QPixmap
operator|::
name|fromWinHICON
parameter_list|(
name|HICON
name|icon
parameter_list|)
block|{
name|HDC
name|screenDevice
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
name|screenDevice
argument_list|)
decl_stmt|;
name|ReleaseDC
argument_list|(
literal|0
argument_list|,
name|screenDevice
argument_list|)
expr_stmt|;
name|ICONINFO
name|iconinfo
decl_stmt|;
name|bool
name|result
init|=
name|GetIconInfo
argument_list|(
name|icon
argument_list|,
operator|&
name|iconinfo
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|result
condition|)
name|qWarning
argument_list|(
literal|"QPixmap::fromWinHICON(), failed to GetIconInfo()"
argument_list|)
expr_stmt|;
name|int
name|w
init|=
literal|0
decl_stmt|;
name|int
name|h
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|iconinfo
operator|.
name|xHotspot
operator|||
operator|!
name|iconinfo
operator|.
name|yHotspot
condition|)
block|{
comment|// We could not retrieve the icon size via GetIconInfo,
comment|// so we try again using the icon bitmap.
name|BITMAP
name|bm
decl_stmt|;
name|int
name|result
init|=
name|GetObject
argument_list|(
name|iconinfo
operator|.
name|hbmColor
argument_list|,
sizeof|sizeof
argument_list|(
name|BITMAP
argument_list|)
argument_list|,
operator|&
name|bm
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|result
condition|)
name|result
operator|=
name|GetObject
argument_list|(
name|iconinfo
operator|.
name|hbmMask
argument_list|,
sizeof|sizeof
argument_list|(
name|BITMAP
argument_list|)
argument_list|,
operator|&
name|bm
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|result
condition|)
block|{
name|qWarning
argument_list|(
literal|"QPixmap::fromWinHICON(), failed to retrieve icon size"
argument_list|)
expr_stmt|;
return|return
name|QPixmap
argument_list|()
return|;
block|}
name|w
operator|=
name|bm
operator|.
name|bmWidth
expr_stmt|;
name|h
operator|=
name|bm
operator|.
name|bmHeight
expr_stmt|;
block|}
else|else
block|{
comment|// x and y Hotspot describes the icon center
name|w
operator|=
name|iconinfo
operator|.
name|xHotspot
operator|*
literal|2
expr_stmt|;
name|h
operator|=
name|iconinfo
operator|.
name|yHotspot
operator|*
literal|2
expr_stmt|;
block|}
specifier|const
name|DWORD
name|dwImageSize
init|=
name|w
operator|*
name|h
operator|*
literal|4
decl_stmt|;
name|BITMAPINFO
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
name|BITMAPINFO
argument_list|)
expr_stmt|;
name|bmi
operator|.
name|bmiHeader
operator|.
name|biWidth
operator|=
name|w
expr_stmt|;
name|bmi
operator|.
name|bmiHeader
operator|.
name|biHeight
operator|=
operator|-
name|h
expr_stmt|;
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
name|bmiHeader
operator|.
name|biSizeImage
operator|=
name|dwImageSize
expr_stmt|;
name|uchar
modifier|*
name|bits
decl_stmt|;
name|HBITMAP
name|winBitmap
init|=
name|CreateDIBSection
argument_list|(
name|hdc
argument_list|,
operator|&
name|bmi
argument_list|,
name|DIB_RGB_COLORS
argument_list|,
operator|(
name|void
operator|*
operator|*
operator|)
operator|&
name|bits
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|winBitmap
condition|)
name|memset
argument_list|(
name|bits
argument_list|,
literal|0xff
argument_list|,
name|dwImageSize
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|winBitmap
condition|)
block|{
name|qWarning
argument_list|(
literal|"QPixmap::fromWinHICON(), failed to CreateDIBSection()"
argument_list|)
expr_stmt|;
return|return
name|QPixmap
argument_list|()
return|;
block|}
name|HGDIOBJ
name|oldhdc
init|=
operator|(
name|HBITMAP
operator|)
name|SelectObject
argument_list|(
name|hdc
argument_list|,
name|winBitmap
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|DrawIconEx
argument_list|(
name|hdc
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|icon
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|DI_NORMAL
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"QPixmap::fromWinHICON(), failed to DrawIcon()"
argument_list|)
expr_stmt|;
name|uint
name|mask
init|=
literal|0xff000000
decl_stmt|;
comment|// Create image and copy data into image.
name|QImage
name|image
argument_list|(
name|w
argument_list|,
name|h
argument_list|,
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|image
operator|.
name|isNull
argument_list|()
condition|)
block|{
comment|// failed to alloc?
name|int
name|bytes_per_line
init|=
name|w
operator|*
sizeof|sizeof
argument_list|(
name|QRgb
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
operator|++
name|y
control|)
block|{
name|QRgb
modifier|*
name|dest
init|=
operator|(
name|QRgb
operator|*
operator|)
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
specifier|const
name|QRgb
modifier|*
name|src
init|=
operator|(
specifier|const
name|QRgb
operator|*
operator|)
operator|(
name|bits
operator|+
name|y
operator|*
name|bytes_per_line
operator|)
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|w
condition|;
operator|++
name|x
control|)
block|{
name|dest
index|[
name|x
index|]
operator|=
name|src
index|[
name|x
index|]
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
operator|!
name|DrawIconEx
argument_list|(
name|hdc
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|icon
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|DI_MASK
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"QPixmap::fromWinHICON(), failed to DrawIcon()"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|image
operator|.
name|isNull
argument_list|()
condition|)
block|{
comment|// failed to alloc?
name|int
name|bytes_per_line
init|=
name|w
operator|*
sizeof|sizeof
argument_list|(
name|QRgb
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
operator|++
name|y
control|)
block|{
name|QRgb
modifier|*
name|dest
init|=
operator|(
name|QRgb
operator|*
operator|)
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
specifier|const
name|QRgb
modifier|*
name|src
init|=
operator|(
specifier|const
name|QRgb
operator|*
operator|)
operator|(
name|bits
operator|+
name|y
operator|*
name|bytes_per_line
operator|)
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|w
condition|;
operator|++
name|x
control|)
block|{
if|if
condition|(
operator|!
name|src
index|[
name|x
index|]
condition|)
name|dest
index|[
name|x
index|]
operator|=
name|dest
index|[
name|x
index|]
operator||
name|mask
expr_stmt|;
block|}
block|}
block|}
name|SelectObject
argument_list|(
name|hdc
argument_list|,
name|oldhdc
argument_list|)
expr_stmt|;
comment|//restore state
name|DeleteObject
argument_list|(
name|winBitmap
argument_list|)
expr_stmt|;
name|DeleteDC
argument_list|(
name|hdc
argument_list|)
expr_stmt|;
return|return
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|image
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//ifndef Q_WS_WINCE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//ifdef Q_WS_WIN
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
