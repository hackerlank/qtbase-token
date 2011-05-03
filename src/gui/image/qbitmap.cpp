begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qpixmapdata_p.h"
end_include
begin_include
include|#
directive|include
file|"qimage.h"
end_include
begin_include
include|#
directive|include
file|"qvariant.h"
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|<private/qgraphicssystem_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QBitmap     \brief The QBitmap class provides monochrome (1-bit depth) pixmaps.      \ingroup painting     \ingroup shared      The QBitmap class is a monochrome off-screen paint device used     mainly for creating custom QCursor and QBrush objects,     constructing QRegion objects, and for setting masks for pixmaps     and widgets.      QBitmap is a QPixmap subclass ensuring a depth of 1, except for     null objects which have a depth of 0. If a pixmap with a depth     greater than 1 is assigned to a bitmap, the bitmap will be     dithered automatically.      Use the QColor objects Qt::color0 and Qt::color1 when drawing on a     QBitmap object (or a QPixmap object with depth 1).      Painting with Qt::color0 sets the bitmap bits to 0, and painting     with Qt::color1 sets the bits to 1. For a bitmap, 0-bits indicate     background (or transparent pixels) and 1-bits indicate foreground     (or opaque pixels). Use the clear() function to set all the bits     to Qt::color0. Note that using the Qt::black and Qt::white colors     make no sense because the QColor::pixel() value is not necessarily     0 for black and 1 for white.      The QBitmap class provides the transformed() function returning a     transformed copy of the bitmap; use the QTransform argument to     translate, scale, shear, and rotate the bitmap. In addition,     QBitmap provides the static fromData() function which returns a     bitmap constructed from the given \c uchar data, and the static     fromImage() function returning a converted copy of a QImage     object.      Just like the QPixmap class, QBitmap is optimized by the use of     implicit data sharing. For more information, see the \l {Implicit     Data Sharing} documentation.      \sa  QPixmap, QImage, QImageReader, QImageWriter */
end_comment
begin_comment
comment|/*! \typedef QBitmap::DataPtr   \internal  */
end_comment
begin_comment
comment|/*!     Constructs a null bitmap.      \sa QPixmap::isNull() */
end_comment
begin_constructor
DECL|function|QBitmap
name|QBitmap
operator|::
name|QBitmap
parameter_list|()
member_init_list|:
name|QPixmap
argument_list|(
name|QSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QPixmapData
operator|::
name|BitmapType
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QBitmap::QBitmap(int width, int height)      Constructs a bitmap with the given \a width and \a height. The pixels     inside are uninitialized.      \sa clear() */
end_comment
begin_constructor
DECL|function|QBitmap
name|QBitmap
operator|::
name|QBitmap
parameter_list|(
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
member_init_list|:
name|QPixmap
argument_list|(
name|QSize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|QPixmapData
operator|::
name|BitmapType
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a bitmap with the given \a size.  The pixels in the     bitmap are uninitialized.      \sa clear() */
end_comment
begin_constructor
DECL|function|QBitmap
name|QBitmap
operator|::
name|QBitmap
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
member_init_list|:
name|QPixmap
argument_list|(
name|size
argument_list|,
name|QPixmapData
operator|::
name|BitmapType
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QBitmap::clear()      Clears the bitmap, setting all its bits to Qt::color0. */
end_comment
begin_comment
comment|/*!     Constructs a bitmap that is a copy of the given \a pixmap.      If the pixmap has a depth greater than 1, the resulting bitmap     will be dithered automatically.      \sa QPixmap::depth(), fromImage(), fromData() */
end_comment
begin_constructor
DECL|function|QBitmap
name|QBitmap
operator|::
name|QBitmap
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
block|{
name|QBitmap
operator|::
name|operator
name|=
parameter_list|(
name|pixmap
parameter_list|)
function_decl|;
block|}
end_constructor
begin_comment
comment|/*!     \fn QBitmap::QBitmap(const QImage&image)      Constructs a bitmap that is a copy of the given \a image.      Use the static fromImage() function instead. */
end_comment
begin_comment
comment|/*!     Constructs a bitmap from the file specified by the given \a     fileName. If the file does not exist, or has an unknown format,     the bitmap becomes a null bitmap.      The \a fileName and \a format parameters are passed on to the     QPixmap::load() function. If the file format uses more than 1 bit     per pixel, the resulting bitmap will be dithered automatically.      \sa QPixmap::isNull(), QImageReader::imageFormat() */
end_comment
begin_constructor
DECL|function|QBitmap
name|QBitmap
operator|::
name|QBitmap
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|)
member_init_list|:
name|QPixmap
argument_list|(
name|QSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QPixmapData
operator|::
name|BitmapType
argument_list|)
block|{
name|load
argument_list|(
name|fileName
argument_list|,
name|format
argument_list|,
name|Qt
operator|::
name|MonoOnly
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \overload      Assigns the given \a pixmap to this bitmap and returns a reference     to this bitmap.      If the pixmap has a depth greater than 1, the resulting bitmap     will be dithered automatically.      \sa QPixmap::depth()  */
end_comment
begin_function
DECL|function|operator =
name|QBitmap
modifier|&
name|QBitmap
operator|::
name|operator
name|=
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
block|{
comment|// a null pixmap
name|QBitmap
name|bm
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QBitmap
operator|::
name|operator
name|=
parameter_list|(
name|bm
parameter_list|)
function_decl|;
block|}
elseif|else
if|if
condition|(
name|pixmap
operator|.
name|depth
argument_list|()
operator|==
literal|1
condition|)
block|{
comment|// 1-bit pixmap
name|QPixmap
operator|::
name|operator
name|=
parameter_list|(
name|pixmap
parameter_list|)
function_decl|;
comment|// shallow assignment
block|}
else|else
block|{
comment|// n-bit depth pixmap
name|QImage
name|image
decl_stmt|;
name|image
operator|=
name|pixmap
operator|.
name|toImage
argument_list|()
expr_stmt|;
comment|// convert pixmap to image
operator|*
name|this
operator|=
name|fromImage
argument_list|(
name|image
argument_list|)
expr_stmt|;
comment|// will dither image
block|}
return|return
operator|*
name|this
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_constructor
DECL|function|QBitmap
name|QBitmap
operator|::
name|QBitmap
parameter_list|(
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
specifier|const
name|uchar
modifier|*
name|bits
parameter_list|,
name|bool
name|isXbitmap
parameter_list|)
block|{
operator|*
name|this
operator|=
name|fromData
argument_list|(
name|QSize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|bits
argument_list|,
name|isXbitmap
condition|?
name|QImage
operator|::
name|Format_MonoLSB
else|:
name|QImage
operator|::
name|Format_Mono
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QBitmap
name|QBitmap
operator|::
name|QBitmap
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|uchar
modifier|*
name|bits
parameter_list|,
name|bool
name|isXbitmap
parameter_list|)
block|{
operator|*
name|this
operator|=
name|fromData
argument_list|(
name|size
argument_list|,
name|bits
argument_list|,
name|isXbitmap
condition|?
name|QImage
operator|::
name|Format_MonoLSB
else|:
name|QImage
operator|::
name|Format_Mono
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!   Destroys the bitmap. */
end_comment
begin_destructor
DECL|function|~QBitmap
name|QBitmap
operator|::
name|~
name|QBitmap
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \fn void QBitmap::swap(QBitmap&other)     \since 4.8      Swaps bitmap \a other with this bitmap. This operation is very     fast and never fails. */
end_comment
begin_comment
comment|/*!    Returns the bitmap as a QVariant. */
end_comment
begin_function
DECL|function|operator QVariant
name|QBitmap
operator|::
name|operator
name|QVariant
parameter_list|()
specifier|const
block|{
return|return
name|QVariant
argument_list|(
name|QVariant
operator|::
name|Bitmap
argument_list|,
name|this
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QBitmap&QBitmap::operator=(const QImage&image)     \overload      Converts the given \a image to a bitmap, and assigns the result to     this bitmap. Returns a reference to the bitmap.      Use the static fromImage() function instead. */
end_comment
begin_comment
comment|/*!     Returns a copy of the given \a image converted to a bitmap using     the specified image conversion \a flags.      \sa fromData() */
end_comment
begin_function
DECL|function|fromImage
name|QBitmap
name|QBitmap
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
if|if
condition|(
name|image
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|QBitmap
argument_list|()
return|;
name|QImage
name|img
init|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_MonoLSB
argument_list|,
name|flags
argument_list|)
decl_stmt|;
comment|// make sure image.color(0) == Qt::color0 (white)
comment|// and image.color(1) == Qt::color1 (black)
specifier|const
name|QRgb
name|c0
init|=
name|QColor
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
operator|.
name|rgb
argument_list|()
decl_stmt|;
specifier|const
name|QRgb
name|c1
init|=
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
operator|.
name|rgb
argument_list|()
decl_stmt|;
if|if
condition|(
name|img
operator|.
name|color
argument_list|(
literal|0
argument_list|)
operator|==
name|c0
operator|&&
name|img
operator|.
name|color
argument_list|(
literal|1
argument_list|)
operator|==
name|c1
condition|)
block|{
name|img
operator|.
name|invertPixels
argument_list|()
expr_stmt|;
name|img
operator|.
name|setColor
argument_list|(
literal|0
argument_list|,
name|c1
argument_list|)
expr_stmt|;
name|img
operator|.
name|setColor
argument_list|(
literal|1
argument_list|,
name|c0
argument_list|)
expr_stmt|;
block|}
name|QScopedPointer
argument_list|<
name|QPixmapData
argument_list|>
name|data
argument_list|(
name|QGraphicsSystem
operator|::
name|createDefaultPixmapData
argument_list|(
name|QPixmapData
operator|::
name|BitmapType
argument_list|)
argument_list|)
decl_stmt|;
name|data
operator|->
name|fromImage
argument_list|(
name|img
argument_list|,
name|flags
operator||
name|Qt
operator|::
name|MonoOnly
argument_list|)
expr_stmt|;
return|return
name|QPixmap
argument_list|(
name|data
operator|.
name|take
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Constructs a bitmap with the given \a size, and sets the contents to     the \a bits supplied.      The bitmap data has to be byte aligned and provided in in the bit     order specified by \a monoFormat. The mono format must be either     QImage::Format_Mono or QImage::Format_MonoLSB. Use     QImage::Format_Mono to specify data on the XBM format.      \sa fromImage()  */
end_comment
begin_function
DECL|function|fromData
name|QBitmap
name|QBitmap
operator|::
name|fromData
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|uchar
modifier|*
name|bits
parameter_list|,
name|QImage
operator|::
name|Format
name|monoFormat
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|monoFormat
operator|==
name|QImage
operator|::
name|Format_Mono
operator|||
name|monoFormat
operator|==
name|QImage
operator|::
name|Format_MonoLSB
argument_list|)
expr_stmt|;
name|QImage
name|image
argument_list|(
name|size
argument_list|,
name|monoFormat
argument_list|)
decl_stmt|;
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
name|rgb
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
name|rgb
argument_list|()
argument_list|)
expr_stmt|;
comment|// Need to memcpy each line separatly since QImage is 32bit aligned and
comment|// this data is only byte aligned...
name|int
name|bytesPerLine
init|=
operator|(
name|size
operator|.
name|width
argument_list|()
operator|+
literal|7
operator|)
operator|/
literal|8
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
name|size
operator|.
name|height
argument_list|()
condition|;
operator|++
name|y
control|)
name|memcpy
argument_list|(
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
argument_list|,
name|bits
operator|+
name|bytesPerLine
operator|*
name|y
argument_list|,
name|bytesPerLine
argument_list|)
expr_stmt|;
return|return
name|QBitmap
operator|::
name|fromImage
argument_list|(
name|image
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a copy of this bitmap, transformed according to the given     \a matrix.      \sa QPixmap::transformed()  */
end_comment
begin_function
DECL|function|transformed
name|QBitmap
name|QBitmap
operator|::
name|transformed
parameter_list|(
specifier|const
name|QTransform
modifier|&
name|matrix
parameter_list|)
specifier|const
block|{
name|QBitmap
name|bm
init|=
name|QPixmap
operator|::
name|transformed
argument_list|(
name|matrix
argument_list|)
decl_stmt|;
return|return
name|bm
return|;
block|}
end_function
begin_comment
comment|/*!   \overload   \obsolete    This convenience function converts the \a matrix to a QTransform   and calls the overloaded function. */
end_comment
begin_function
DECL|function|transformed
name|QBitmap
name|QBitmap
operator|::
name|transformed
parameter_list|(
specifier|const
name|QMatrix
modifier|&
name|matrix
parameter_list|)
specifier|const
block|{
return|return
name|transformed
argument_list|(
name|QTransform
argument_list|(
name|matrix
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_comment
comment|/*!     \fn QBitmap QBitmap::xForm(const QMatrix&matrix) const      Returns a copy of this bitmap, transformed according to the given     \a matrix.      Use transformed() instead. */
end_comment
begin_comment
comment|/*!     \fn QBitmap::QBitmap(const QSize&size, bool clear)      Constructs a bitmap with the given \a size. If \a clear is true,     the bits are initialized to Qt::color0.      Use the corresponding QBitmap() constructor instead, and then call     the clear() function if the \a clear parameter is true. */
end_comment
begin_comment
comment|/*!     \fn QBitmap::QBitmap(int width, int height, bool clear)      Constructs a bitmap with the given \a width and \a height.  If \a     clear is true, the bits are initialized to Qt::color0.      Use the corresponding QBitmap() constructor instead, and then call     the clear() function if the \a clear parameter is true. */
end_comment
begin_comment
comment|/*!     \fn QBitmap::QBitmap(int width, int height, const uchar *bits, bool isXbitmap)      Constructs a bitmap with the given \a width and \a height, and     sets the contents to the \a bits supplied. The \a isXbitmap flag     should be true if \a bits was generated by the X11 bitmap     program.      Use the static fromData() function instead. If \a isXbitmap is     true, use the default bit order(QImage_FormatMonoLSB) otherwise     use QImage::Format_Mono.      \omit     The X bitmap bit order is little endian.  The QImage     documentation discusses bit order of monochrome images. Opposed to     QImage, the data has to be byte aligned.      Example (creates an arrow bitmap):     \snippet doc/src/snippets/code/src_gui_image_qbitmap.cpp 0     \endomit */
end_comment
begin_comment
comment|/*!   \fn QBitmap::QBitmap(const QSize&size, const uchar *bits, bool isXbitmap)      \overload      Constructs a bitmap with the given \a size, and sets the contents     to the \a bits supplied. The \a isXbitmap flag should be true if     \a bits was generated by the X11 bitmap program.      \omit     The X bitmap bit order is little endian.  The QImage documentation     discusses bit order of monochrome images.     \endomit      Use the static fromData() function instead. If \a isXbitmap is     true, use the default bit order(QImage_FormatMonoLSB) otherwise     use QImage::Format_Mono. */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
