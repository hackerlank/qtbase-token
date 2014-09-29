begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIMAGE_H
end_ifndef
begin_define
DECL|macro|QIMAGE_H
define|#
directive|define
name|QIMAGE_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qtransform.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpaintdevice.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qrgb.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpixelformat.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMatrix
name|class
name|QMatrix
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTransform
name|class
name|QTransform
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|QList
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QList
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QVector
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QVector
expr_stmt|;
end_expr_stmt
begin_struct_decl
struct_decl|struct
name|QImageData
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|QImageDataMisc
name|class
name|QImageDataMisc
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|QImageDataMisc
comment|// internal
end_comment
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
end_if
begin_decl_stmt
name|class
name|QImageTextKeyLang
block|{
name|public
label|:
name|QT_DEPRECATED
name|QImageTextKeyLang
argument_list|(
specifier|const
name|char
operator|*
name|k
argument_list|,
specifier|const
name|char
operator|*
name|l
argument_list|)
operator|:
name|key
argument_list|(
name|k
argument_list|)
operator|,
name|lang
argument_list|(
argument|l
argument_list|)
block|{ }
name|QT_DEPRECATED
name|QImageTextKeyLang
argument_list|()
block|{ }
name|QByteArray
name|key
expr_stmt|;
name|QByteArray
name|lang
decl_stmt|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QImageTextKeyLang
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|key
operator|<
name|other
operator|.
name|key
operator|||
operator|(
name|key
operator|==
name|other
operator|.
name|key
operator|&&
name|lang
operator|<
name|other
operator|.
name|lang
operator|)
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QImageTextKeyLang
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|key
operator|==
name|other
operator|.
name|key
operator|&&
name|lang
operator|==
name|other
operator|.
name|lang
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QImageTextKeyLang
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
name|private
label|:
name|friend
name|class
name|QImage
decl_stmt|;
name|QImageTextKeyLang
argument_list|(
argument|bool
comment|/*dummy*/
argument_list|)
block|{}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|QImageCleanupFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|QImageCleanupFunction
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QImage
range|:
name|public
name|QPaintDevice
block|{
name|public
operator|:
expr|enum
name|InvertMode
block|{
name|InvertRgb
block|,
name|InvertRgba
block|}
block|;     enum
name|Format
block|{
name|Format_Invalid
block|,
name|Format_Mono
block|,
name|Format_MonoLSB
block|,
name|Format_Indexed8
block|,
name|Format_RGB32
block|,
name|Format_ARGB32
block|,
name|Format_ARGB32_Premultiplied
block|,
name|Format_RGB16
block|,
name|Format_ARGB8565_Premultiplied
block|,
name|Format_RGB666
block|,
name|Format_ARGB6666_Premultiplied
block|,
name|Format_RGB555
block|,
name|Format_ARGB8555_Premultiplied
block|,
name|Format_RGB888
block|,
name|Format_RGB444
block|,
name|Format_ARGB4444_Premultiplied
block|,
name|Format_RGBX8888
block|,
name|Format_RGBA8888
block|,
name|Format_RGBA8888_Premultiplied
block|,
name|Format_BGR30
block|,
name|Format_A2BGR30_Premultiplied
block|,
name|Format_RGB30
block|,
name|Format_A2RGB30_Premultiplied
block|,
name|Format_Alpha8
block|,
name|Format_Grayscale8
block|,
if|#
directive|if
literal|0
comment|// reserved for future use
block|Format_Grayscale16,
endif|#
directive|endif
ifndef|#
directive|ifndef
name|Q_QDOC
name|NImageFormats
endif|#
directive|endif
block|}
block|;
name|QImage
argument_list|()
block|;
name|QImage
argument_list|(
argument|const QSize&size
argument_list|,
argument|Format format
argument_list|)
block|;
name|QImage
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|Format format
argument_list|)
block|;
name|QImage
argument_list|(
argument|uchar *data
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|Format format
argument_list|,
argument|QImageCleanupFunction cleanupFunction =
literal|0
argument_list|,
argument|void *cleanupInfo =
literal|0
argument_list|)
block|;
name|QImage
argument_list|(
argument|const uchar *data
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|Format format
argument_list|,
argument|QImageCleanupFunction cleanupFunction =
literal|0
argument_list|,
argument|void *cleanupInfo =
literal|0
argument_list|)
block|;
name|QImage
argument_list|(
argument|uchar *data
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|int bytesPerLine
argument_list|,
argument|Format format
argument_list|,
argument|QImageCleanupFunction cleanupFunction =
literal|0
argument_list|,
argument|void *cleanupInfo =
literal|0
argument_list|)
block|;
name|QImage
argument_list|(
argument|const uchar *data
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|int bytesPerLine
argument_list|,
argument|Format format
argument_list|,
argument|QImageCleanupFunction cleanupFunction =
literal|0
argument_list|,
argument|void *cleanupInfo =
literal|0
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_IMAGEFORMAT_XPM
name|explicit
name|QImage
argument_list|(
specifier|const
name|char
operator|*
specifier|const
name|xpm
index|[]
argument_list|)
block|;
endif|#
directive|endif
name|explicit
name|QImage
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|char
operator|*
name|format
operator|=
literal|0
argument_list|)
block|;
name|QImage
argument_list|(
specifier|const
name|QImage
operator|&
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QImage
argument_list|(
name|QImage
operator|&&
name|other
argument_list|)
operator|:
name|QPaintDevice
argument_list|()
block|,
name|d
argument_list|(
literal|0
argument_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|; }
endif|#
directive|endif
operator|~
name|QImage
argument_list|()
block|;
name|QImage
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QImage
operator|&
operator|)
block|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QImage
operator|&
name|operator
operator|=
operator|(
name|QImage
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
specifier|inline
name|void
name|swap
argument_list|(
argument|QImage&other
argument_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|; }
name|bool
name|isNull
argument_list|()
specifier|const
block|;
name|int
name|devType
argument_list|()
specifier|const
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QImage
operator|&
operator|)
specifier|const
block|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QImage
operator|&
operator|)
specifier|const
block|;
name|operator
name|QVariant
argument_list|()
specifier|const
block|;
name|void
name|detach
argument_list|()
block|;
name|bool
name|isDetached
argument_list|()
specifier|const
block|;
name|QImage
name|copy
argument_list|(
argument|const QRect&rect = QRect()
argument_list|)
specifier|const
block|;
specifier|inline
name|QImage
name|copy
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
specifier|const
block|{
return|return
name|copy
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
return|;
block|}
name|Format
name|format
argument_list|()
specifier|const
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_REF_QUALIFIERS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_COMPILING_QIMAGE_COMPAT_CPP
argument_list|)
name|QImage
name|convertToFormat
argument_list|(
argument|Format f
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
specifier|const
operator|&
name|Q_REQUIRED_RESULT
block|{
return|return
name|convertToFormat_helper
argument_list|(
name|f
argument_list|,
name|flags
argument_list|)
return|;
block|}
name|QImage
name|convertToFormat
argument_list|(
argument|Format f
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
operator|&&
name|Q_REQUIRED_RESULT
block|{
if|if
condition|(
name|convertToFormat_inplace
argument_list|(
name|f
argument_list|,
name|flags
argument_list|)
condition|)
return|return
name|std
operator|::
name|move
argument_list|(
operator|*
name|this
argument_list|)
return|;
else|else
return|return
name|convertToFormat_helper
argument_list|(
name|f
argument_list|,
name|flags
argument_list|)
return|;
block|}
else|#
directive|else
name|QImage
name|convertToFormat
argument_list|(
argument|Format f
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
specifier|const
name|Q_REQUIRED_RESULT
block|;
endif|#
directive|endif
name|QImage
name|convertToFormat
argument_list|(
argument|Format f
argument_list|,
argument|const QVector<QRgb>&colorTable
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
specifier|const
name|Q_REQUIRED_RESULT
block|;
name|int
name|width
argument_list|()
specifier|const
block|;
name|int
name|height
argument_list|()
specifier|const
block|;
name|QSize
name|size
argument_list|()
specifier|const
block|;
name|QRect
name|rect
argument_list|()
specifier|const
block|;
name|int
name|depth
argument_list|()
specifier|const
block|;
name|int
name|colorCount
argument_list|()
specifier|const
block|;
name|int
name|bitPlaneCount
argument_list|()
specifier|const
block|;
name|QRgb
name|color
argument_list|(
argument|int i
argument_list|)
specifier|const
block|;
name|void
name|setColor
argument_list|(
argument|int i
argument_list|,
argument|QRgb c
argument_list|)
block|;
name|void
name|setColorCount
argument_list|(
name|int
argument_list|)
block|;
name|bool
name|allGray
argument_list|()
specifier|const
block|;
name|bool
name|isGrayscale
argument_list|()
specifier|const
block|;
name|uchar
operator|*
name|bits
argument_list|()
block|;
specifier|const
name|uchar
operator|*
name|bits
argument_list|()
specifier|const
block|;
specifier|const
name|uchar
operator|*
name|constBits
argument_list|()
specifier|const
block|;
name|int
name|byteCount
argument_list|()
specifier|const
block|;
name|uchar
operator|*
name|scanLine
argument_list|(
name|int
argument_list|)
block|;
specifier|const
name|uchar
operator|*
name|scanLine
argument_list|(
argument|int
argument_list|)
specifier|const
block|;
specifier|const
name|uchar
operator|*
name|constScanLine
argument_list|(
argument|int
argument_list|)
specifier|const
block|;
name|int
name|bytesPerLine
argument_list|()
specifier|const
block|;
name|bool
name|valid
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|bool
name|valid
argument_list|(
argument|const QPoint&pt
argument_list|)
specifier|const
block|;
name|int
name|pixelIndex
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|int
name|pixelIndex
argument_list|(
argument|const QPoint&pt
argument_list|)
specifier|const
block|;
name|QRgb
name|pixel
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|QRgb
name|pixel
argument_list|(
argument|const QPoint&pt
argument_list|)
specifier|const
block|;
name|void
name|setPixel
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|uint index_or_rgb
argument_list|)
block|;
name|void
name|setPixel
argument_list|(
argument|const QPoint&pt
argument_list|,
argument|uint index_or_rgb
argument_list|)
block|;
name|QVector
operator|<
name|QRgb
operator|>
name|colorTable
argument_list|()
specifier|const
block|;
name|void
name|setColorTable
argument_list|(
specifier|const
name|QVector
operator|<
name|QRgb
operator|>
name|colors
argument_list|)
block|;
comment|// ### Qt 6: remove const
name|qreal
name|devicePixelRatio
argument_list|()
specifier|const
block|;
name|void
name|setDevicePixelRatio
argument_list|(
argument|qreal scaleFactor
argument_list|)
block|;
name|void
name|fill
argument_list|(
argument|uint pixel
argument_list|)
block|;
name|void
name|fill
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|void
name|fill
argument_list|(
argument|Qt::GlobalColor color
argument_list|)
block|;
name|bool
name|hasAlphaChannel
argument_list|()
specifier|const
block|;
name|void
name|setAlphaChannel
argument_list|(
specifier|const
name|QImage
operator|&
name|alphaChannel
argument_list|)
block|;
name|QImage
name|alphaChannel
argument_list|()
specifier|const
block|;
name|QImage
name|createAlphaMask
argument_list|(
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_IMAGE_HEURISTIC_MASK
name|QImage
name|createHeuristicMask
argument_list|(
argument|bool clipTight = true
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|QImage
name|createMaskFromColor
argument_list|(
argument|QRgb color
argument_list|,
argument|Qt::MaskMode mode = Qt::MaskInColor
argument_list|)
specifier|const
block|;
specifier|inline
name|QImage
name|scaled
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|Qt::AspectRatioMode aspectMode = Qt::IgnoreAspectRatio
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|{
return|return
name|scaled
argument_list|(
name|QSize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|aspectMode
argument_list|,
name|mode
argument_list|)
return|;
block|}
name|QImage
name|scaled
argument_list|(
argument|const QSize&s
argument_list|,
argument|Qt::AspectRatioMode aspectMode = Qt::IgnoreAspectRatio
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
name|QImage
name|scaledToWidth
argument_list|(
argument|int w
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
name|QImage
name|scaledToHeight
argument_list|(
argument|int h
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
name|QImage
name|transformed
argument_list|(
argument|const QMatrix&matrix
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
specifier|static
name|QMatrix
name|trueMatrix
argument_list|(
argument|const QMatrix&
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
name|QImage
name|transformed
argument_list|(
argument|const QTransform&matrix
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
specifier|static
name|QTransform
name|trueMatrix
argument_list|(
argument|const QTransform&
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_REF_QUALIFIERS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_COMPILING_QIMAGE_COMPAT_CPP
argument_list|)
name|QImage
name|mirrored
argument_list|(
argument|bool horizontally = false
argument_list|,
argument|bool vertically = true
argument_list|)
specifier|const
operator|&
block|{
return|return
name|mirrored_helper
argument_list|(
name|horizontally
argument_list|,
name|vertically
argument_list|)
return|;
block|}
name|QImage
operator|&&
name|mirrored
argument_list|(
argument|bool horizontally = false
argument_list|,
argument|bool vertically = true
argument_list|)
operator|&&
block|{
name|mirrored_inplace
argument_list|(
name|horizontally
argument_list|,
name|vertically
argument_list|)
block|;
return|return
name|qMove
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
name|QImage
name|rgbSwapped
argument_list|()
specifier|const
operator|&
block|{
return|return
name|rgbSwapped_helper
argument_list|()
return|;
block|}
name|QImage
operator|&&
name|rgbSwapped
argument_list|()
operator|&&
block|{
name|rgbSwapped_inplace
argument_list|()
block|;
return|return
name|qMove
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
else|#
directive|else
name|QImage
name|mirrored
argument_list|(
argument|bool horizontally = false
argument_list|,
argument|bool vertically = true
argument_list|)
specifier|const
block|;
name|QImage
name|rgbSwapped
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|void
name|invertPixels
argument_list|(
name|InvertMode
operator|=
name|InvertRgb
argument_list|)
block|;
name|bool
name|load
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|,
specifier|const
name|char
operator|*
name|format
argument_list|)
block|;
name|bool
name|load
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|char
operator|*
name|format
operator|=
literal|0
argument_list|)
block|;
name|bool
name|loadFromData
argument_list|(
argument|const uchar *buf
argument_list|,
argument|int len
argument_list|,
argument|const char *format =
literal|0
argument_list|)
block|;
specifier|inline
name|bool
name|loadFromData
argument_list|(
argument|const QByteArray&data
argument_list|,
argument|const char* aformat=
literal|0
argument_list|)
block|{
return|return
name|loadFromData
argument_list|(
name|reinterpret_cast
operator|<
specifier|const
name|uchar
operator|*
operator|>
operator|(
name|data
operator|.
name|constData
argument_list|()
operator|)
argument_list|,
name|data
operator|.
name|size
argument_list|()
argument_list|,
name|aformat
argument_list|)
return|;
block|}
name|bool
name|save
argument_list|(
argument|const QString&fileName
argument_list|,
argument|const char* format=
literal|0
argument_list|,
argument|int quality=-
literal|1
argument_list|)
specifier|const
block|;
name|bool
name|save
argument_list|(
argument|QIODevice *device
argument_list|,
argument|const char* format=
literal|0
argument_list|,
argument|int quality=-
literal|1
argument_list|)
specifier|const
block|;
specifier|static
name|QImage
name|fromData
argument_list|(
argument|const uchar *data
argument_list|,
argument|int size
argument_list|,
argument|const char *format =
literal|0
argument_list|)
block|;
specifier|inline
specifier|static
name|QImage
name|fromData
argument_list|(
argument|const QByteArray&data
argument_list|,
argument|const char *format =
literal|0
argument_list|)
block|{
return|return
name|fromData
argument_list|(
name|reinterpret_cast
operator|<
specifier|const
name|uchar
operator|*
operator|>
operator|(
name|data
operator|.
name|constData
argument_list|()
operator|)
argument_list|,
name|data
operator|.
name|size
argument_list|()
argument_list|,
name|format
argument_list|)
return|;
block|}
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|inline
name|int
name|serialNumber
argument_list|()
specifier|const
block|{
return|return
name|cacheKey
argument_list|()
operator|>>
literal|32
return|;
block|}
endif|#
directive|endif
name|qint64
name|cacheKey
argument_list|()
specifier|const
block|;
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
block|;
comment|// Auxiliary data
name|int
name|dotsPerMeterX
argument_list|()
specifier|const
block|;
name|int
name|dotsPerMeterY
argument_list|()
specifier|const
block|;
name|void
name|setDotsPerMeterX
argument_list|(
name|int
argument_list|)
block|;
name|void
name|setDotsPerMeterY
argument_list|(
name|int
argument_list|)
block|;
name|QPoint
name|offset
argument_list|()
specifier|const
block|;
name|void
name|setOffset
argument_list|(
specifier|const
name|QPoint
operator|&
argument_list|)
block|;
name|QStringList
name|textKeys
argument_list|()
specifier|const
block|;
name|QString
name|text
argument_list|(
argument|const QString&key = QString()
argument_list|)
specifier|const
block|;
name|void
name|setText
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|,
specifier|const
name|QString
operator|&
name|value
argument_list|)
block|;
name|QPixelFormat
name|pixelFormat
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|;
specifier|static
name|QPixelFormat
name|toPixelFormat
argument_list|(
argument|QImage::Format format
argument_list|)
name|Q_DECL_NOTHROW
block|;
specifier|static
name|QImage
operator|::
name|Format
name|toImageFormat
argument_list|(
argument|QPixelFormat format
argument_list|)
name|Q_DECL_NOTHROW
block|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|inline
name|QString
name|text
argument_list|(
argument|const char* key
argument_list|,
argument|const char* lang=
literal|0
argument_list|)
specifier|const
block|;
name|QT_DEPRECATED
specifier|inline
name|QList
operator|<
name|QImageTextKeyLang
operator|>
name|textList
argument_list|()
specifier|const
block|;
name|QT_DEPRECATED
specifier|inline
name|QStringList
name|textLanguages
argument_list|()
specifier|const
block|;
name|QT_DEPRECATED
specifier|inline
name|QString
name|text
argument_list|(
argument|const QImageTextKeyLang&
argument_list|)
specifier|const
block|;
name|QT_DEPRECATED
specifier|inline
name|void
name|setText
argument_list|(
specifier|const
name|char
operator|*
name|key
argument_list|,
specifier|const
name|char
operator|*
name|lang
argument_list|,
specifier|const
name|QString
operator|&
argument_list|)
block|;
endif|#
directive|endif
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|inline
name|int
name|numColors
argument_list|()
specifier|const
block|;
name|QT_DEPRECATED
specifier|inline
name|void
name|setNumColors
argument_list|(
name|int
argument_list|)
block|;
name|QT_DEPRECATED
specifier|inline
name|int
name|numBytes
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|protected
operator|:
name|virtual
name|int
name|metric
argument_list|(
argument|PaintDeviceMetric metric
argument_list|)
specifier|const
block|;
name|QImage
name|mirrored_helper
argument_list|(
argument|bool horizontal
argument_list|,
argument|bool vertical
argument_list|)
specifier|const
block|;
name|QImage
name|rgbSwapped_helper
argument_list|()
specifier|const
block|;
name|void
name|mirrored_inplace
argument_list|(
argument|bool horizontal
argument_list|,
argument|bool vertical
argument_list|)
block|;
name|void
name|rgbSwapped_inplace
argument_list|()
block|;
name|QImage
name|convertToFormat_helper
argument_list|(
argument|Format format
argument_list|,
argument|Qt::ImageConversionFlags flags
argument_list|)
specifier|const
block|;
name|bool
name|convertToFormat_inplace
argument_list|(
argument|Format format
argument_list|,
argument|Qt::ImageConversionFlags flags
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QWSOnScreenSurface
block|;
name|QImageData
operator|*
name|d
block|;
name|friend
name|class
name|QRasterPlatformPixmap
block|;
name|friend
name|class
name|QBlittablePlatformPixmap
block|;
name|friend
name|class
name|QPixmapCacheEntry
block|;
name|public
operator|:
typedef|typedef
name|QImageData
modifier|*
name|DataPtr
typedef|;
specifier|inline
name|DataPtr
operator|&
name|data_ptr
argument_list|()
block|{
return|return
name|d
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QImage
argument_list|)
end_macro
begin_comment
comment|// Inline functions...
end_comment
begin_expr_stmt
specifier|inline
name|bool
name|QImage
operator|::
name|valid
argument_list|(
argument|const QPoint&pt
argument_list|)
specifier|const
block|{
return|return
name|valid
argument_list|(
name|pt
operator|.
name|x
argument_list|()
argument_list|,
name|pt
operator|.
name|y
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|pixelIndex
specifier|inline
name|int
name|QImage
operator|::
name|pixelIndex
argument_list|(
argument|const QPoint&pt
argument_list|)
specifier|const
block|{
return|return
name|pixelIndex
argument_list|(
name|pt
operator|.
name|x
argument_list|()
argument_list|,
name|pt
operator|.
name|y
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|pixel
specifier|inline
name|QRgb
name|QImage
operator|::
name|pixel
argument_list|(
argument|const QPoint&pt
argument_list|)
specifier|const
block|{
return|return
name|pixel
argument_list|(
name|pt
operator|.
name|x
argument_list|()
argument_list|,
name|pt
operator|.
name|y
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setPixel
specifier|inline
name|void
name|QImage
operator|::
name|setPixel
argument_list|(
argument|const QPoint&pt
argument_list|,
argument|uint index_or_rgb
argument_list|)
block|{
name|setPixel
argument_list|(
name|pt
operator|.
name|x
argument_list|()
argument_list|,
name|pt
operator|.
name|y
argument_list|()
argument_list|,
name|index_or_rgb
argument_list|)
block|; }
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|*
literal|100
operator|+
name|__GNUC_MINOR__
operator|>=
literal|406
operator|)
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|push
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wdeprecated-declarations"
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4996
name|)
endif|#
directive|endif
DECL|function|text
specifier|inline
name|QString
name|QImage
operator|::
name|text
argument_list|(
argument|const char* key
argument_list|,
argument|const char* lang
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QString
argument_list|()
return|;
name|QString
name|k
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|key
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|lang
operator|&&
operator|*
name|lang
condition|)
name|k
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
name|lang
argument_list|)
expr_stmt|;
end_if
begin_return
return|return
name|text
argument_list|(
name|k
argument_list|)
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|textList
name|QList
operator|<
name|QImageTextKeyLang
operator|>
name|QImage
operator|::
name|textList
argument_list|()
specifier|const
block|{
name|QList
operator|<
name|QImageTextKeyLang
operator|>
name|imageTextKeys
block|;
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|imageTextKeys
return|;
name|QStringList
name|keys
operator|=
name|textKeys
argument_list|()
expr_stmt|;
end_expr_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|keys
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|int
name|index
init|=
name|keys
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|>
literal|0
condition|)
block|{
name|QImageTextKeyLang
name|tkl
parameter_list|(
name|true
parameter_list|)
function_decl|;
name|tkl
operator|.
name|key
operator|=
name|keys
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|left
argument_list|(
name|index
argument_list|)
operator|.
name|toLatin1
argument_list|()
expr_stmt|;
name|tkl
operator|.
name|lang
operator|=
name|keys
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|mid
argument_list|(
name|index
operator|+
literal|1
argument_list|)
operator|.
name|toLatin1
argument_list|()
expr_stmt|;
name|imageTextKeys
operator|+=
name|tkl
expr_stmt|;
block|}
block|}
end_for
begin_return
return|return
name|imageTextKeys
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|textLanguages
name|QStringList
name|QImage
operator|::
name|textLanguages
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QStringList
argument_list|()
return|;
name|QStringList
name|keys
operator|=
name|textKeys
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QStringList
name|languages
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|keys
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|int
name|index
init|=
name|keys
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|>
literal|0
condition|)
name|languages
operator|+=
name|keys
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|mid
argument_list|(
name|index
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
end_for
begin_return
return|return
name|languages
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|text
name|QString
name|QImage
operator|::
name|text
argument_list|(
argument|const QImageTextKeyLang&kl
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QString
argument_list|()
return|;
name|QString
name|k
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|kl
operator|.
name|key
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|kl
operator|.
name|lang
operator|.
name|isEmpty
argument_list|()
condition|)
name|k
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
name|kl
operator|.
name|lang
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
end_if
begin_return
return|return
name|text
argument_list|(
name|k
argument_list|)
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|setText
name|void
name|QImage
operator|::
name|setText
argument_list|(
argument|const char* key
argument_list|,
argument|const char* lang
argument_list|,
argument|const QString&s
argument_list|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return;
name|detach
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// In case detach() ran out of memory
end_comment
begin_if
if|if
condition|(
operator|!
name|d
condition|)
return|return;
end_if
begin_decl_stmt
name|QString
name|k
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|key
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|lang
operator|&&
operator|*
name|lang
condition|)
name|k
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
name|lang
argument_list|)
expr_stmt|;
end_if
begin_expr_stmt
name|setText
argument_list|(
name|k
argument_list|,
name|s
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
unit|}
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|*
literal|100
operator|+
name|__GNUC_MINOR__
operator|>=
literal|406
operator|)
end_if
begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|pop
end_pragma
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
end_elif
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|inline
DECL|function|numColors
name|int
name|QImage
operator|::
name|numColors
argument_list|()
specifier|const
block|{
return|return
name|colorCount
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setNumColors
specifier|inline
name|void
name|QImage
operator|::
name|setNumColors
argument_list|(
argument|int n
argument_list|)
block|{
name|setColorCount
argument_list|(
name|n
argument_list|)
block|; }
DECL|function|numBytes
specifier|inline
name|int
name|QImage
operator|::
name|numBytes
argument_list|()
specifier|const
block|{
return|return
name|byteCount
argument_list|()
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QImage stream functions
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DATASTREAM
argument_list|)
end_if
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QImage
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QImage
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QImage
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QIMAGE_H
end_comment
end_unit
