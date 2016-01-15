begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qpixmap.h"
end_include
begin_include
include|#
directive|include
file|<private/qfont_p.h>
end_include
begin_include
include|#
directive|include
file|"qpixmap_raster_p.h"
end_include
begin_include
include|#
directive|include
file|"qnativeimage_p.h"
end_include
begin_include
include|#
directive|include
file|"qimage_p.h"
end_include
begin_include
include|#
directive|include
file|"qpaintengine.h"
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
file|<QBuffer>
end_include
begin_include
include|#
directive|include
file|<QImageReader>
end_include
begin_include
include|#
directive|include
file|<private/qimage_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qsimd_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qdrawhelper_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|qt_toRasterPixmap
name|QPixmap
name|qt_toRasterPixmap
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
name|QPlatformPixmap
modifier|*
name|data
init|=
operator|new
name|QRasterPlatformPixmap
argument_list|(
name|image
operator|.
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
name|image
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
return|;
block|}
end_function
begin_function
DECL|function|qt_toRasterPixmap
name|QPixmap
name|qt_toRasterPixmap
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
block|{
if|if
condition|(
name|pixmap
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|QPixmap
argument_list|()
return|;
if|if
condition|(
name|QPixmap
argument_list|(
name|pixmap
argument_list|)
operator|.
name|data_ptr
argument_list|()
operator|->
name|classId
argument_list|()
operator|==
name|QPlatformPixmap
operator|::
name|RasterClass
condition|)
return|return
name|pixmap
return|;
return|return
name|qt_toRasterPixmap
argument_list|(
name|pixmap
operator|.
name|toImage
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|QRasterPlatformPixmap
name|QRasterPlatformPixmap
operator|::
name|QRasterPlatformPixmap
parameter_list|(
name|PixelType
name|type
parameter_list|)
member_init_list|:
name|QPlatformPixmap
argument_list|(
name|type
argument_list|,
name|RasterClass
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QRasterPlatformPixmap
name|QRasterPlatformPixmap
operator|::
name|~
name|QRasterPlatformPixmap
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|createCompatiblePlatformPixmap
name|QPlatformPixmap
modifier|*
name|QRasterPlatformPixmap
operator|::
name|createCompatiblePlatformPixmap
parameter_list|()
specifier|const
block|{
return|return
operator|new
name|QRasterPlatformPixmap
argument_list|(
name|pixelType
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QRasterPlatformPixmap
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
name|QImage
operator|::
name|Format
name|format
decl_stmt|;
if|if
condition|(
name|pixelType
argument_list|()
operator|==
name|BitmapType
condition|)
name|format
operator|=
name|QImage
operator|::
name|Format_MonoLSB
expr_stmt|;
else|else
name|format
operator|=
name|QNativeImage
operator|::
name|systemFormat
argument_list|()
expr_stmt|;
name|image
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
name|w
operator|=
name|width
expr_stmt|;
name|h
operator|=
name|height
expr_stmt|;
name|d
operator|=
name|image
operator|.
name|depth
argument_list|()
expr_stmt|;
name|is_null
operator|=
operator|(
name|w
operator|<=
literal|0
operator|||
name|h
operator|<=
literal|0
operator|)
expr_stmt|;
if|if
condition|(
name|pixelType
argument_list|()
operator|==
name|BitmapType
operator|&&
operator|!
name|image
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|image
operator|.
name|setColorCount
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|image
operator|.
name|setColor
argument_list|(
literal|0
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|color0
argument_list|)
operator|.
name|rgba
argument_list|()
argument_list|)
expr_stmt|;
name|image
operator|.
name|setColor
argument_list|(
literal|1
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|color1
argument_list|)
operator|.
name|rgba
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|setSerialNumber
argument_list|(
name|image
operator|.
name|cacheKey
argument_list|()
operator|>>
literal|32
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fromData
name|bool
name|QRasterPlatformPixmap
operator|::
name|fromData
parameter_list|(
specifier|const
name|uchar
modifier|*
name|buffer
parameter_list|,
name|uint
name|len
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
parameter_list|)
block|{
name|QByteArray
name|a
init|=
name|QByteArray
operator|::
name|fromRawData
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|buffer
argument_list|)
argument_list|,
name|len
argument_list|)
decl_stmt|;
name|QBuffer
name|b
argument_list|(
operator|&
name|a
argument_list|)
decl_stmt|;
name|b
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QImage
name|image
init|=
name|QImageReader
argument_list|(
operator|&
name|b
argument_list|,
name|format
argument_list|)
operator|.
name|read
argument_list|()
decl_stmt|;
if|if
condition|(
name|image
operator|.
name|isNull
argument_list|()
condition|)
return|return
literal|false
return|;
name|createPixmapForImage
argument_list|(
name|image
argument_list|,
name|flags
argument_list|,
comment|/* inplace = */
literal|true
argument_list|)
expr_stmt|;
return|return
operator|!
name|isNull
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|fromImage
name|void
name|QRasterPlatformPixmap
operator|::
name|fromImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|sourceImage
parameter_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
parameter_list|)
block|{
name|QImage
name|image
init|=
name|sourceImage
decl_stmt|;
name|createPixmapForImage
argument_list|(
name|image
argument_list|,
name|flags
argument_list|,
comment|/* inplace = */
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fromImageInPlace
name|void
name|QRasterPlatformPixmap
operator|::
name|fromImageInPlace
parameter_list|(
name|QImage
modifier|&
name|sourceImage
parameter_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
parameter_list|)
block|{
name|createPixmapForImage
argument_list|(
name|sourceImage
argument_list|,
name|flags
argument_list|,
comment|/* inplace = */
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fromImageReader
name|void
name|QRasterPlatformPixmap
operator|::
name|fromImageReader
parameter_list|(
name|QImageReader
modifier|*
name|imageReader
parameter_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|flags
argument_list|)
expr_stmt|;
name|QImage
name|image
init|=
name|imageReader
operator|->
name|read
argument_list|()
decl_stmt|;
if|if
condition|(
name|image
operator|.
name|isNull
argument_list|()
condition|)
return|return;
name|createPixmapForImage
argument_list|(
name|image
argument_list|,
name|flags
argument_list|,
comment|/* inplace = */
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// from qbackingstore.cpp
end_comment
begin_function_decl
specifier|extern
name|void
name|qt_scrollRectInImage
parameter_list|(
name|QImage
modifier|&
name|img
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|copy
name|void
name|QRasterPlatformPixmap
operator|::
name|copy
parameter_list|(
specifier|const
name|QPlatformPixmap
modifier|*
name|data
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|fromImage
argument_list|(
name|data
operator|->
name|toImage
argument_list|(
name|rect
argument_list|)
operator|.
name|copy
argument_list|()
argument_list|,
name|Qt
operator|::
name|NoOpaqueDetection
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|scroll
name|bool
name|QRasterPlatformPixmap
operator|::
name|scroll
parameter_list|(
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
if|if
condition|(
operator|!
name|image
operator|.
name|isNull
argument_list|()
condition|)
name|qt_scrollRectInImage
argument_list|(
name|image
argument_list|,
name|rect
argument_list|,
name|QPoint
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|fill
name|void
name|QRasterPlatformPixmap
operator|::
name|fill
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|uint
name|pixel
decl_stmt|;
if|if
condition|(
name|image
operator|.
name|depth
argument_list|()
operator|==
literal|1
condition|)
block|{
name|int
name|gray
init|=
name|qGray
argument_list|(
name|color
operator|.
name|rgba
argument_list|()
argument_list|)
decl_stmt|;
comment|// Pick the best approximate color in the image's colortable.
if|if
condition|(
name|qAbs
argument_list|(
name|qGray
argument_list|(
name|image
operator|.
name|color
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|-
name|gray
argument_list|)
operator|<
name|qAbs
argument_list|(
name|qGray
argument_list|(
name|image
operator|.
name|color
argument_list|(
literal|1
argument_list|)
argument_list|)
operator|-
name|gray
argument_list|)
condition|)
name|pixel
operator|=
literal|0
expr_stmt|;
else|else
name|pixel
operator|=
literal|1
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|image
operator|.
name|depth
argument_list|()
operator|>=
literal|15
condition|)
block|{
name|int
name|alpha
init|=
name|color
operator|.
name|alpha
argument_list|()
decl_stmt|;
if|if
condition|(
name|alpha
operator|!=
literal|255
condition|)
block|{
if|if
condition|(
operator|!
name|image
operator|.
name|hasAlphaChannel
argument_list|()
condition|)
block|{
name|QImage
operator|::
name|Format
name|toFormat
init|=
name|qt_alphaVersionForPainting
argument_list|(
name|image
operator|.
name|format
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|image
operator|.
name|isNull
argument_list|()
operator|&&
name|qt_depthForFormat
argument_list|(
name|image
operator|.
name|format
argument_list|()
argument_list|)
operator|==
name|qt_depthForFormat
argument_list|(
name|toFormat
argument_list|)
condition|)
block|{
name|image
operator|.
name|detach
argument_list|()
expr_stmt|;
name|image
operator|.
name|d
operator|->
name|format
operator|=
name|toFormat
expr_stmt|;
block|}
else|else
block|{
name|image
operator|=
name|QImage
argument_list|(
name|image
operator|.
name|width
argument_list|()
argument_list|,
name|image
operator|.
name|height
argument_list|()
argument_list|,
name|toFormat
argument_list|)
expr_stmt|;
block|}
block|}
block|}
name|pixel
operator|=
name|qPremultiply
argument_list|(
name|color
operator|.
name|rgba
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QPixelLayout
modifier|*
name|layout
init|=
operator|&
name|qPixelLayouts
index|[
name|image
operator|.
name|format
argument_list|()
index|]
decl_stmt|;
name|layout
operator|->
name|convertFromARGB32PM
argument_list|(
operator|&
name|pixel
argument_list|,
operator|&
name|pixel
argument_list|,
literal|1
argument_list|,
name|layout
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|image
operator|.
name|format
argument_list|()
operator|==
name|QImage
operator|::
name|Format_Alpha8
condition|)
block|{
name|pixel
operator|=
name|qAlpha
argument_list|(
name|color
operator|.
name|rgba
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|image
operator|.
name|format
argument_list|()
operator|==
name|QImage
operator|::
name|Format_Grayscale8
condition|)
block|{
name|pixel
operator|=
name|qGray
argument_list|(
name|color
operator|.
name|rgba
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|pixel
operator|=
literal|0
expr_stmt|;
comment|// ### what about 8 bit indexed?
block|}
name|image
operator|.
name|fill
argument_list|(
name|pixel
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasAlphaChannel
name|bool
name|QRasterPlatformPixmap
operator|::
name|hasAlphaChannel
parameter_list|()
specifier|const
block|{
return|return
name|image
operator|.
name|hasAlphaChannel
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|toImage
name|QImage
name|QRasterPlatformPixmap
operator|::
name|toImage
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|image
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QImageData
modifier|*
name|data
init|=
cast|const_cast
argument_list|<
name|QImage
operator|&
argument_list|>
argument_list|(
name|image
argument_list|)
operator|.
name|data_ptr
argument_list|()
decl_stmt|;
if|if
condition|(
name|data
operator|->
name|paintEngine
operator|&&
name|data
operator|->
name|paintEngine
operator|->
name|isActive
argument_list|()
operator|&&
name|data
operator|->
name|paintEngine
operator|->
name|paintDevice
argument_list|()
operator|==
operator|&
name|image
condition|)
block|{
return|return
name|image
operator|.
name|copy
argument_list|()
return|;
block|}
block|}
return|return
name|image
return|;
block|}
end_function
begin_function
DECL|function|toImage
name|QImage
name|QRasterPlatformPixmap
operator|::
name|toImage
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|rect
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|image
return|;
name|QRect
name|clipped
init|=
name|rect
operator|.
name|intersected
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|uint
name|du
init|=
name|uint
argument_list|(
name|d
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|du
operator|%
literal|8
operator|==
literal|0
operator|)
operator|&&
operator|(
operator|(
operator|(
name|uint
argument_list|(
name|clipped
operator|.
name|x
argument_list|()
argument_list|)
operator|*
name|du
operator|)
operator|)
operator|%
literal|32
operator|==
literal|0
operator|)
condition|)
block|{
name|QImage
name|newImage
argument_list|(
name|image
operator|.
name|scanLine
argument_list|(
name|clipped
operator|.
name|y
argument_list|()
argument_list|)
operator|+
name|clipped
operator|.
name|x
argument_list|()
operator|*
operator|(
name|du
operator|/
literal|8
operator|)
argument_list|,
name|clipped
operator|.
name|width
argument_list|()
argument_list|,
name|clipped
operator|.
name|height
argument_list|()
argument_list|,
name|image
operator|.
name|bytesPerLine
argument_list|()
argument_list|,
name|image
operator|.
name|format
argument_list|()
argument_list|)
decl_stmt|;
name|newImage
operator|.
name|setDevicePixelRatio
argument_list|(
name|image
operator|.
name|devicePixelRatio
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|newImage
return|;
block|}
else|else
block|{
return|return
name|image
operator|.
name|copy
argument_list|(
name|clipped
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|paintEngine
name|QPaintEngine
modifier|*
name|QRasterPlatformPixmap
operator|::
name|paintEngine
parameter_list|()
specifier|const
block|{
return|return
name|image
operator|.
name|paintEngine
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|metric
name|int
name|QRasterPlatformPixmap
operator|::
name|metric
parameter_list|(
name|QPaintDevice
operator|::
name|PaintDeviceMetric
name|metric
parameter_list|)
specifier|const
block|{
name|QImageData
modifier|*
name|d
init|=
name|image
operator|.
name|d
decl_stmt|;
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|0
return|;
comment|// override the image dpi with the screen dpi when rendering to a pixmap
switch|switch
condition|(
name|metric
condition|)
block|{
case|case
name|QPaintDevice
operator|::
name|PdmWidth
case|:
return|return
name|w
return|;
case|case
name|QPaintDevice
operator|::
name|PdmHeight
case|:
return|return
name|h
return|;
case|case
name|QPaintDevice
operator|::
name|PdmWidthMM
case|:
return|return
name|qRound
argument_list|(
name|d
operator|->
name|width
operator|*
literal|25.4
operator|/
name|qt_defaultDpiX
argument_list|()
argument_list|)
return|;
case|case
name|QPaintDevice
operator|::
name|PdmHeightMM
case|:
return|return
name|qRound
argument_list|(
name|d
operator|->
name|height
operator|*
literal|25.4
operator|/
name|qt_defaultDpiY
argument_list|()
argument_list|)
return|;
case|case
name|QPaintDevice
operator|::
name|PdmNumColors
case|:
return|return
name|d
operator|->
name|colortable
operator|.
name|size
argument_list|()
return|;
case|case
name|QPaintDevice
operator|::
name|PdmDepth
case|:
return|return
name|this
operator|->
name|d
return|;
case|case
name|QPaintDevice
operator|::
name|PdmDpiX
case|:
return|return
name|qt_defaultDpiX
argument_list|()
return|;
case|case
name|QPaintDevice
operator|::
name|PdmPhysicalDpiX
case|:
return|return
name|qt_defaultDpiX
argument_list|()
return|;
case|case
name|QPaintDevice
operator|::
name|PdmDpiY
case|:
return|return
name|qt_defaultDpiX
argument_list|()
return|;
case|case
name|QPaintDevice
operator|::
name|PdmPhysicalDpiY
case|:
return|return
name|qt_defaultDpiY
argument_list|()
return|;
case|case
name|QPaintDevice
operator|::
name|PdmDevicePixelRatio
case|:
return|return
name|image
operator|.
name|devicePixelRatio
argument_list|()
return|;
case|case
name|QPaintDevice
operator|::
name|PdmDevicePixelRatioScaled
case|:
return|return
name|image
operator|.
name|devicePixelRatio
argument_list|()
operator|*
name|QPaintDevice
operator|::
name|devicePixelRatioFScale
argument_list|()
return|;
default|default:
name|qWarning
argument_list|(
literal|"QRasterPlatformPixmap::metric(): Unhandled metric type %d"
argument_list|,
name|metric
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|createPixmapForImage
name|void
name|QRasterPlatformPixmap
operator|::
name|createPixmapForImage
parameter_list|(
name|QImage
modifier|&
name|sourceImage
parameter_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
parameter_list|,
name|bool
name|inPlace
parameter_list|)
block|{
name|QImage
operator|::
name|Format
name|format
decl_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|NoFormatConversion
condition|)
name|format
operator|=
name|sourceImage
operator|.
name|format
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|pixelType
argument_list|()
operator|==
name|BitmapType
condition|)
block|{
name|format
operator|=
name|QImage
operator|::
name|Format_MonoLSB
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|sourceImage
operator|.
name|depth
argument_list|()
operator|==
literal|1
condition|)
block|{
name|format
operator|=
name|sourceImage
operator|.
name|hasAlphaChannel
argument_list|()
condition|?
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
else|:
name|QImage
operator|::
name|Format_RGB32
expr_stmt|;
block|}
else|else
block|{
name|QImage
operator|::
name|Format
name|opaqueFormat
init|=
name|QNativeImage
operator|::
name|systemFormat
argument_list|()
decl_stmt|;
name|QImage
operator|::
name|Format
name|alphaFormat
init|=
name|qt_alphaVersionForPainting
argument_list|(
name|opaqueFormat
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|sourceImage
operator|.
name|hasAlphaChannel
argument_list|()
condition|)
block|{
name|format
operator|=
name|opaqueFormat
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|flags
operator|&
name|Qt
operator|::
name|NoOpaqueDetection
operator|)
operator|==
literal|0
operator|&&
operator|!
cast|const_cast
argument_list|<
name|QImage
operator|&
argument_list|>
argument_list|(
name|sourceImage
argument_list|)
operator|.
name|data_ptr
argument_list|()
operator|->
name|checkForAlphaPixels
argument_list|()
condition|)
block|{
name|format
operator|=
name|opaqueFormat
expr_stmt|;
block|}
else|else
block|{
name|format
operator|=
name|alphaFormat
expr_stmt|;
block|}
block|}
block|}
comment|// image has alpha format but is really opaque, so try to do a
comment|// more efficient conversion
if|if
condition|(
name|format
operator|==
name|QImage
operator|::
name|Format_RGB32
operator|&&
operator|(
name|sourceImage
operator|.
name|format
argument_list|()
operator|==
name|QImage
operator|::
name|Format_ARGB32
operator|||
name|sourceImage
operator|.
name|format
argument_list|()
operator|==
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
operator|)
condition|)
block|{
name|inPlace
operator|=
name|inPlace
operator|&&
name|sourceImage
operator|.
name|isDetached
argument_list|()
expr_stmt|;
name|image
operator|=
name|sourceImage
expr_stmt|;
if|if
condition|(
operator|!
name|inPlace
condition|)
name|image
operator|.
name|detach
argument_list|()
expr_stmt|;
if|if
condition|(
name|image
operator|.
name|d
condition|)
name|image
operator|.
name|d
operator|->
name|format
operator|=
name|QImage
operator|::
name|Format_RGB32
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|inPlace
operator|&&
name|sourceImage
operator|.
name|d
operator|->
name|convertInPlace
argument_list|(
name|format
argument_list|,
name|flags
argument_list|)
condition|)
block|{
name|image
operator|=
name|sourceImage
expr_stmt|;
block|}
else|else
block|{
name|image
operator|=
name|sourceImage
operator|.
name|convertToFormat
argument_list|(
name|format
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|image
operator|.
name|d
condition|)
block|{
name|w
operator|=
name|image
operator|.
name|d
operator|->
name|width
expr_stmt|;
name|h
operator|=
name|image
operator|.
name|d
operator|->
name|height
expr_stmt|;
name|d
operator|=
name|image
operator|.
name|d
operator|->
name|depth
expr_stmt|;
block|}
else|else
block|{
name|w
operator|=
name|h
operator|=
name|d
operator|=
literal|0
expr_stmt|;
block|}
name|is_null
operator|=
operator|(
name|w
operator|<=
literal|0
operator|||
name|h
operator|<=
literal|0
operator|)
expr_stmt|;
if|if
condition|(
name|image
operator|.
name|d
condition|)
name|image
operator|.
name|d
operator|->
name|devicePixelRatio
operator|=
name|sourceImage
operator|.
name|devicePixelRatio
argument_list|()
expr_stmt|;
comment|//ensure the pixmap and the image resulting from toImage() have the same cacheKey();
name|setSerialNumber
argument_list|(
name|image
operator|.
name|cacheKey
argument_list|()
operator|>>
literal|32
argument_list|)
expr_stmt|;
if|if
condition|(
name|image
operator|.
name|d
condition|)
name|setDetachNumber
argument_list|(
name|image
operator|.
name|d
operator|->
name|detach_no
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|buffer
name|QImage
modifier|*
name|QRasterPlatformPixmap
operator|::
name|buffer
parameter_list|()
block|{
return|return
operator|&
name|image
return|;
block|}
end_function
begin_function
DECL|function|devicePixelRatio
name|qreal
name|QRasterPlatformPixmap
operator|::
name|devicePixelRatio
parameter_list|()
specifier|const
block|{
return|return
name|image
operator|.
name|devicePixelRatio
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setDevicePixelRatio
name|void
name|QRasterPlatformPixmap
operator|::
name|setDevicePixelRatio
parameter_list|(
name|qreal
name|scaleFactor
parameter_list|)
block|{
name|image
operator|.
name|setDevicePixelRatio
argument_list|(
name|scaleFactor
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
