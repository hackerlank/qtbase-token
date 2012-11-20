begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qpixmap_blitter_p.h"
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|<qimage.h>
end_include
begin_include
include|#
directive|include
file|<qscreen.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qblittable_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qdrawhelper_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qfont_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BLITTABLE
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|global_ser_no
specifier|static
name|int
name|global_ser_no
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QBlittablePlatformPixmap
name|QBlittablePlatformPixmap
operator|::
name|QBlittablePlatformPixmap
parameter_list|()
member_init_list|:
name|QPlatformPixmap
argument_list|(
name|QPlatformPixmap
operator|::
name|PixmapType
argument_list|,
name|BlitterClass
argument_list|)
member_init_list|,
name|m_alpha
argument_list|(
literal|false
argument_list|)
ifdef|#
directive|ifdef
name|QT_BLITTER_RASTEROVERLAY
member_init_list|,
name|m_rasterOverlay
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_unmergedCopy
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
comment|//QT_BLITTER_RASTEROVERLAY
block|{
name|setSerialNumber
argument_list|(
operator|++
name|global_ser_no
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QBlittablePlatformPixmap
name|QBlittablePlatformPixmap
operator|::
name|~
name|QBlittablePlatformPixmap
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QT_BLITTER_RASTEROVERLAY
operator|delete
name|m_rasterOverlay
expr_stmt|;
operator|delete
name|m_unmergedCopy
expr_stmt|;
endif|#
directive|endif
comment|//QT_BLITTER_RASTEROVERLAY
block|}
end_destructor
begin_function
DECL|function|blittable
name|QBlittable
modifier|*
name|QBlittablePlatformPixmap
operator|::
name|blittable
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_blittable
condition|)
block|{
name|QBlittablePlatformPixmap
modifier|*
name|that
init|=
cast|const_cast
argument_list|<
name|QBlittablePlatformPixmap
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|that
operator|->
name|m_blittable
operator|.
name|reset
argument_list|(
name|this
operator|->
name|createBlittable
argument_list|(
name|QSize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|m_alpha
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|m_blittable
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setBlittable
name|void
name|QBlittablePlatformPixmap
operator|::
name|setBlittable
parameter_list|(
name|QBlittable
modifier|*
name|blittable
parameter_list|)
block|{
name|resize
argument_list|(
name|blittable
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|blittable
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|m_blittable
operator|.
name|reset
argument_list|(
name|blittable
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QBlittablePlatformPixmap
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
name|m_blittable
operator|.
name|reset
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|m_engine
operator|.
name|reset
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|d
operator|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|depth
argument_list|()
expr_stmt|;
name|w
operator|=
name|width
expr_stmt|;
name|h
operator|=
name|height
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
name|setSerialNumber
argument_list|(
operator|++
name|global_ser_no
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|metric
name|int
name|QBlittablePlatformPixmap
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
name|w
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
name|h
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
name|PdmDepth
case|:
return|return
literal|32
return|;
case|case
name|QPaintDevice
operator|::
name|PdmDpiX
case|:
comment|// fall-through
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
comment|// fall-through
case|case
name|QPaintDevice
operator|::
name|PdmPhysicalDpiY
case|:
return|return
name|qt_defaultDpiY
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
DECL|function|fill
name|void
name|QBlittablePlatformPixmap
operator|::
name|fill
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
if|if
condition|(
name|blittable
argument_list|()
operator|->
name|capabilities
argument_list|()
operator|&
name|QBlittable
operator|::
name|AlphaFillRectCapability
condition|)
block|{
name|blittable
argument_list|()
operator|->
name|unlock
argument_list|()
expr_stmt|;
name|blittable
argument_list|()
operator|->
name|alphaFillRect
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|color
argument_list|,
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|color
operator|.
name|alpha
argument_list|()
operator|==
literal|255
operator|&&
name|blittable
argument_list|()
operator|->
name|capabilities
argument_list|()
operator|&
name|QBlittable
operator|::
name|SolidRectCapability
condition|)
block|{
name|blittable
argument_list|()
operator|->
name|unlock
argument_list|()
expr_stmt|;
name|blittable
argument_list|()
operator|->
name|fillRect
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|color
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Need to be backed with an alpha channel now. It would be nice
comment|// if we could just change the format, e.g. when going from
comment|// RGB32 -> ARGB8888.
if|if
condition|(
name|color
operator|.
name|alpha
argument_list|()
operator|!=
literal|255
operator|&&
operator|!
name|hasAlphaChannel
argument_list|()
condition|)
block|{
name|m_blittable
operator|.
name|reset
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|m_engine
operator|.
name|reset
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|m_alpha
operator|=
literal|true
expr_stmt|;
block|}
name|uint
name|pixel
init|=
name|PREMUL
argument_list|(
name|color
operator|.
name|rgba
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QPixelLayout
modifier|*
name|layout
init|=
operator|&
name|qPixelLayouts
index|[
name|blittable
argument_list|()
operator|->
name|lock
argument_list|()
operator|->
name|format
argument_list|()
index|]
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|layout
operator|->
name|convertFromARGB32PM
argument_list|)
expr_stmt|;
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
comment|//so premultiplied formats are supported and ARGB32 and RGB32
name|blittable
argument_list|()
operator|->
name|lock
argument_list|()
operator|->
name|fill
argument_list|(
name|pixel
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|buffer
name|QImage
modifier|*
name|QBlittablePlatformPixmap
operator|::
name|buffer
parameter_list|()
block|{
return|return
name|blittable
argument_list|()
operator|->
name|lock
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|toImage
name|QImage
name|QBlittablePlatformPixmap
operator|::
name|toImage
parameter_list|()
specifier|const
block|{
return|return
name|blittable
argument_list|()
operator|->
name|lock
argument_list|()
operator|->
name|copy
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|hasAlphaChannel
name|bool
name|QBlittablePlatformPixmap
operator|::
name|hasAlphaChannel
parameter_list|()
specifier|const
block|{
return|return
name|blittable
argument_list|()
operator|->
name|lock
argument_list|()
operator|->
name|hasAlphaChannel
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|fromImage
name|void
name|QBlittablePlatformPixmap
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
name|m_alpha
operator|=
name|image
operator|.
name|hasAlphaChannel
argument_list|()
expr_stmt|;
name|resize
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
argument_list|)
expr_stmt|;
name|markRasterOverlay
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
expr_stmt|;
name|QImage
modifier|*
name|thisImg
init|=
name|buffer
argument_list|()
decl_stmt|;
name|QImage
name|correctFormatPic
init|=
name|image
decl_stmt|;
if|if
condition|(
name|correctFormatPic
operator|.
name|format
argument_list|()
operator|!=
name|thisImg
operator|->
name|format
argument_list|()
condition|)
name|correctFormatPic
operator|=
name|correctFormatPic
operator|.
name|convertToFormat
argument_list|(
name|thisImg
operator|->
name|format
argument_list|()
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|uchar
modifier|*
name|mem
init|=
name|thisImg
operator|->
name|bits
argument_list|()
decl_stmt|;
specifier|const
name|uchar
modifier|*
name|bits
init|=
name|correctFormatPic
operator|.
name|bits
argument_list|()
decl_stmt|;
name|int
name|bytesCopied
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|bytesCopied
operator|<
name|correctFormatPic
operator|.
name|byteCount
argument_list|()
condition|)
block|{
name|memcpy
argument_list|(
name|mem
argument_list|,
name|bits
argument_list|,
name|correctFormatPic
operator|.
name|bytesPerLine
argument_list|()
argument_list|)
expr_stmt|;
name|mem
operator|+=
name|thisImg
operator|->
name|bytesPerLine
argument_list|()
expr_stmt|;
name|bits
operator|+=
name|correctFormatPic
operator|.
name|bytesPerLine
argument_list|()
expr_stmt|;
name|bytesCopied
operator|+=
name|correctFormatPic
operator|.
name|bytesPerLine
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|devicePixelRatio
name|qreal
name|QBlittablePlatformPixmap
operator|::
name|devicePixelRatio
parameter_list|()
specifier|const
block|{
return|return
name|m_devicePixelRatio
return|;
block|}
end_function
begin_function
DECL|function|setDevicePixelRatio
name|void
name|QBlittablePlatformPixmap
operator|::
name|setDevicePixelRatio
parameter_list|(
name|qreal
name|scaleFactor
parameter_list|)
block|{
name|m_devicePixelRatio
operator|=
name|scaleFactor
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintEngine
name|QPaintEngine
modifier|*
name|QBlittablePlatformPixmap
operator|::
name|paintEngine
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_engine
condition|)
block|{
name|QBlittablePlatformPixmap
modifier|*
name|that
init|=
cast|const_cast
argument_list|<
name|QBlittablePlatformPixmap
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|that
operator|->
name|m_engine
operator|.
name|reset
argument_list|(
operator|new
name|QBlitterPaintEngine
argument_list|(
name|that
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|m_engine
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|QT_BLITTER_RASTEROVERLAY
end_ifdef
begin_decl_stmt
DECL|variable|showRasterOverlay
specifier|static
name|bool
name|showRasterOverlay
init|=
operator|!
name|qEnvironmentVariableIsEmpty
argument_list|(
literal|"QT_BLITTER_RASTEROVERLAY"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|mergeOverlay
name|void
name|QBlittablePlatformPixmap
operator|::
name|mergeOverlay
parameter_list|()
block|{
if|if
condition|(
name|m_unmergedCopy
operator|||
operator|!
name|showRasterOverlay
condition|)
return|return;
name|m_unmergedCopy
operator|=
operator|new
name|QImage
argument_list|(
name|buffer
argument_list|()
operator|->
name|copy
argument_list|()
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
name|buffer
argument_list|()
argument_list|)
decl_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_SourceOver
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
operator|*
name|overlay
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unmergeOverlay
name|void
name|QBlittablePlatformPixmap
operator|::
name|unmergeOverlay
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_unmergedCopy
operator|||
operator|!
name|showRasterOverlay
condition|)
return|return;
name|QPainter
name|p
argument_list|(
name|buffer
argument_list|()
argument_list|)
decl_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
operator|*
name|m_unmergedCopy
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
operator|delete
name|m_unmergedCopy
expr_stmt|;
name|m_unmergedCopy
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|overlay
name|QImage
modifier|*
name|QBlittablePlatformPixmap
operator|::
name|overlay
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_rasterOverlay
operator|||
name|m_rasterOverlay
operator|->
name|size
argument_list|()
operator|!=
name|QSize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
condition|)
block|{
name|m_rasterOverlay
operator|=
operator|new
name|QImage
argument_list|(
name|w
argument_list|,
name|h
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
expr_stmt|;
name|m_rasterOverlay
operator|->
name|fill
argument_list|(
literal|0x00000000
argument_list|)
expr_stmt|;
name|uint
name|color
init|=
operator|(
name|qrand
argument_list|()
operator|%
literal|11
operator|)
operator|+
literal|7
decl_stmt|;
name|m_overlayColor
operator|=
name|QColor
argument_list|(
name|Qt
operator|::
name|GlobalColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|m_overlayColor
operator|.
name|setAlpha
argument_list|(
literal|0x88
argument_list|)
expr_stmt|;
block|}
return|return
name|m_rasterOverlay
return|;
block|}
end_function
begin_function
DECL|function|markRasterOverlayImpl
name|void
name|QBlittablePlatformPixmap
operator|::
name|markRasterOverlayImpl
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
block|{
if|if
condition|(
operator|!
name|showRasterOverlay
condition|)
return|return;
name|QRectF
name|transformationRect
init|=
name|clipAndTransformRect
argument_list|(
name|rect
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|transformationRect
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QPainter
name|p
argument_list|(
name|overlay
argument_list|()
argument_list|)
decl_stmt|;
name|p
operator|.
name|setBrush
argument_list|(
name|m_overlayColor
argument_list|)
expr_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|transformationRect
argument_list|,
name|QBrush
argument_list|(
name|m_overlayColor
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|unmarkRasterOverlayImpl
name|void
name|QBlittablePlatformPixmap
operator|::
name|unmarkRasterOverlayImpl
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
block|{
if|if
condition|(
operator|!
name|showRasterOverlay
condition|)
return|return;
name|QRectF
name|transformationRect
init|=
name|clipAndTransformRect
argument_list|(
name|rect
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|transformationRect
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QPainter
name|p
argument_list|(
name|overlay
argument_list|()
argument_list|)
decl_stmt|;
name|QColor
name|color
argument_list|(
literal|0x00
argument_list|,
literal|0x00
argument_list|,
literal|0x00
argument_list|,
literal|0x00
argument_list|)
decl_stmt|;
name|p
operator|.
name|setBrush
argument_list|(
name|color
argument_list|)
expr_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|transformationRect
argument_list|,
name|QBrush
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|clipAndTransformRect
name|QRectF
name|QBlittablePlatformPixmap
operator|::
name|clipAndTransformRect
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
specifier|const
block|{
name|QRectF
name|transformationRect
init|=
name|rect
decl_stmt|;
name|paintEngine
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_engine
operator|->
name|state
argument_list|()
condition|)
block|{
name|transformationRect
operator|=
name|m_engine
operator|->
name|state
argument_list|()
operator|->
name|matrix
operator|.
name|mapRect
argument_list|(
name|rect
argument_list|)
expr_stmt|;
specifier|const
name|QClipData
modifier|*
name|clipData
init|=
name|m_engine
operator|->
name|clip
argument_list|()
decl_stmt|;
if|if
condition|(
name|clipData
condition|)
block|{
if|if
condition|(
name|clipData
operator|->
name|hasRectClip
condition|)
block|{
name|transformationRect
operator|&=
name|clipData
operator|->
name|clipRect
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|clipData
operator|->
name|hasRegionClip
condition|)
block|{
specifier|const
name|QVector
argument_list|<
name|QRect
argument_list|>
name|rects
init|=
name|clipData
operator|->
name|clipRegion
operator|.
name|rects
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|rects
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|transformationRect
operator|&=
name|rects
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
return|return
name|transformationRect
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_BLITTER_RASTEROVERLAY
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_BLITTABLE
end_comment
end_unit
