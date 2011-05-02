begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_RAWFONT
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qrawfont.h"
end_include
begin_include
include|#
directive|include
file|"qrawfont_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qthread.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qendian.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!    \class QRawFont    \brief The QRawFont class provides access to a single physical instance of a font.    \since 4.8     \ingroup text    \mainclass     \note QRawFont is a low level class. For most purposes QFont is a more appropriate class.     Most commonly, when presenting text in a user interface, the exact fonts used    to render the characters is to some extent unknown. This can be the case for several    reasons: For instance, the actual, physical fonts present on the target system could be    unexpected to the developers, or the text could contain user selected styles, sizes or    writing systems that are not supported by font chosen in the code.     Therefore, Qt's QFont class really represents a query for fonts. When text is interpreted,    Qt will do its best to match the text to the query, but depending on the support, different    fonts can be used behind the scenes.     For most use cases, this is both expected and necessary, as it minimizes the possibility of    text in the user interface being undisplayable. In some cases, however, more direct control    over the process might be useful. It is for these use cases the QRawFont class exists.     A QRawFont object represents a single, physical instance of a given font in a given pixel size.    I.e. in the typical case it represents a set of TrueType or OpenType font tables and uses a    user specified pixel size to convert metrics into logical pixel units. In can be used in    combination with the QGlyphs class to draw specific glyph indexes at specific positions, and    also have accessors to some relevant data in the physical font.     QRawFont only provides support for the main font technologies: GDI and DirectWrite on Windows    platforms, FreeType on Symbian and Linux platforms and CoreText on Mac OS X. For other    font back-ends, the APIs will be disabled.     QRawFont can be constructed in a number of ways:    \list    \o \l It can be constructed by calling QTextLayout::glyphs() or QTextFragment::glyphs(). The          returned QGlyphs objects will contain QRawFont objects which represent the actual fonts          used to render each portion of the text.    \o \l It can be constructed by passing a QFont object to QRawFont::fromFont(). The function          will return a QRawFont object representing the font that will be selected as response to          the QFont query and the selected writing system.    \o \l It can be constructed by passing a file name or QByteArray directly to the QRawFont          constructor, or by calling loadFromFile() or loadFromData(). In this case, the          font will not be registered in QFontDatabase, and it will not be available as part of          regular font selection.    \endlist     QRawFont is considered local to the thread in which it is constructed (either using a    constructor, or by calling loadFromData() or loadFromFile()). The QRawFont cannot be moved to a    different thread, but will have to be recreated in the thread in question.     \note For the requirement of caching glyph indexes and font selections for static text to avoid    reshaping and relayouting in the inner loop of an application, a better choice is the QStaticText    class, since it optimizes the memory cost of the cache and also provides the possibility of paint    engine specific caches for an additional speed-up. */
end_comment
begin_comment
comment|/*!     \enum QRawFont::AntialiasingType      This enum represents the different ways a glyph can be rasterized in the function     alphaMapForGlyph().      \value PixelAntialiasing Will rasterize by measuring the coverage of the shape on whole pixels.            The returned image contains the alpha values of each pixel based on the coverage of            the glyph shape.     \value SubPixelAntialiasing Will rasterize by measuring the coverage of each subpixel,            returning a separate alpha value for each of the red, green and blue components of            each pixel. */
end_comment
begin_comment
comment|/*!    Constructs an invalid QRawFont. */
end_comment
begin_constructor
DECL|function|QRawFont
name|QRawFont
operator|::
name|QRawFont
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QRawFontPrivate
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!    Constructs a QRawFont representing the font contained in the file referenced by \a fileName,    with \a pixelSize size in pixels, and the selected \a hintingPreference.     \note The referenced file must contain a TrueType or OpenType font. */
end_comment
begin_constructor
DECL|function|QRawFont
name|QRawFont
operator|::
name|QRawFont
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|int
name|pixelSize
parameter_list|,
name|QFont
operator|::
name|HintingPreference
name|hintingPreference
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QRawFontPrivate
argument_list|)
block|{
name|loadFromFile
argument_list|(
name|fileName
argument_list|,
name|pixelSize
argument_list|,
name|hintingPreference
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!    Constructs a QRawFont representing the font contained in \a fontData.     \note The data must contain a TrueType or OpenType font. */
end_comment
begin_constructor
DECL|function|QRawFont
name|QRawFont
operator|::
name|QRawFont
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fontData
parameter_list|,
name|int
name|pixelSize
parameter_list|,
name|QFont
operator|::
name|HintingPreference
name|hintingPreference
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QRawFontPrivate
argument_list|)
block|{
name|loadFromData
argument_list|(
name|fontData
argument_list|,
name|pixelSize
argument_list|,
name|hintingPreference
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!    Creates a QRawFont which is a copy of \a other. */
end_comment
begin_constructor
DECL|function|QRawFont
name|QRawFont
operator|::
name|QRawFont
parameter_list|(
specifier|const
name|QRawFont
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!    Destroys the QRawFont */
end_comment
begin_destructor
DECL|function|~QRawFont
name|QRawFont
operator|::
name|~
name|QRawFont
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!   Assigns \a other to this QRawFont. */
end_comment
begin_function
DECL|function|operator =
name|QRawFont
modifier|&
name|QRawFont
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QRawFont
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!    Returns true if the QRawFont is valid and false otherwise. */
end_comment
begin_function
DECL|function|isValid
name|bool
name|QRawFont
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|thread
operator|==
literal|0
operator|||
name|d
operator|->
name|thread
operator|==
name|QThread
operator|::
name|currentThread
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|fontEngine
operator|!=
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!    Replaces the current QRawFont with the contents of the file references by \a fileName.     The file must reference a TrueType or OpenType font.     \sa loadFromData() */
end_comment
begin_function
DECL|function|loadFromFile
name|void
name|QRawFont
operator|::
name|loadFromFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|int
name|pixelSize
parameter_list|,
name|QFont
operator|::
name|HintingPreference
name|hintingPreference
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
name|loadFromData
argument_list|(
name|file
operator|.
name|readAll
argument_list|()
argument_list|,
name|pixelSize
argument_list|,
name|hintingPreference
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!    Replaces the current QRawFont with the contents of \a fontData.     The \a fontData must contain a TrueType or OpenType font.     \sa loadFromFile() */
end_comment
begin_function
DECL|function|loadFromData
name|void
name|QRawFont
operator|::
name|loadFromData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fontData
parameter_list|,
name|int
name|pixelSize
parameter_list|,
name|QFont
operator|::
name|HintingPreference
name|hintingPreference
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|cleanUp
argument_list|()
expr_stmt|;
name|d
operator|->
name|hintingPreference
operator|=
name|hintingPreference
expr_stmt|;
name|d
operator|->
name|thread
operator|=
name|QThread
operator|::
name|currentThread
argument_list|()
expr_stmt|;
name|d
operator|->
name|platformLoadFromData
argument_list|(
name|fontData
argument_list|,
name|pixelSize
argument_list|,
name|hintingPreference
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!    This function returns a rasterized image of the glyph at a given \a glyphIndex in the underlying    font, if the QRawFont is valid, otherwise it will return an invalid QImage.     If \a antialiasingType is set to QRawFont::SubPixelAntialiasing, then the resulting image will be    in QImage::Format_RGB32 and the RGB values of each pixel will represent the subpixel opacities of    the pixel in the rasterization of the glyph. Otherwise, the image will be in the format of    QImage::Format_A8 and each pixel will contain the opacity of the pixel in the rasterization.     \sa pathForGlyph(), QPainter::drawGlyphs() */
end_comment
begin_function
DECL|function|alphaMapForGlyph
name|QImage
name|QRawFont
operator|::
name|alphaMapForGlyph
parameter_list|(
name|quint32
name|glyphIndex
parameter_list|,
name|AntialiasingType
name|antialiasingType
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|transform
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
name|QImage
argument_list|()
return|;
if|if
condition|(
name|antialiasingType
operator|==
name|SubPixelAntialiasing
condition|)
return|return
name|d
operator|->
name|fontEngine
operator|->
name|alphaRGBMapForGlyph
argument_list|(
name|glyphIndex
argument_list|,
name|QFixed
argument_list|()
argument_list|,
literal|0
argument_list|,
name|transform
argument_list|)
return|;
else|else
return|return
name|d
operator|->
name|fontEngine
operator|->
name|alphaMapForGlyph
argument_list|(
name|glyphIndex
argument_list|,
name|QFixed
argument_list|()
argument_list|,
name|transform
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!    This function returns the shape of the glyph at a given \a glyphIndex in the underlying font    if the QRawFont is valid. Otherwise, it returns an empty QPainterPath.     The returned glyph will always be unhinted.     \sa alphaMapForGlyph(), QPainterPath::addText() */
end_comment
begin_function
DECL|function|pathForGlyph
name|QPainterPath
name|QRawFont
operator|::
name|pathForGlyph
parameter_list|(
name|quint32
name|glyphIndex
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
name|QPainterPath
argument_list|()
return|;
name|QFixedPoint
name|position
decl_stmt|;
name|QPainterPath
name|path
decl_stmt|;
name|d
operator|->
name|fontEngine
operator|->
name|addGlyphsToPath
argument_list|(
operator|&
name|glyphIndex
argument_list|,
operator|&
name|position
argument_list|,
literal|1
argument_list|,
operator|&
name|path
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
name|path
return|;
block|}
end_function
begin_comment
comment|/*!    Returns true if this QRawFont is equal to \a other. Otherwise, returns false. */
end_comment
begin_function
DECL|function|operator ==
name|bool
name|QRawFont
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QRawFont
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
name|d
operator|->
name|fontEngine
operator|==
name|other
operator|.
name|d
operator|->
name|fontEngine
return|;
block|}
end_function
begin_comment
comment|/*!    Returns the ascent of this QRawFont in pixel units.     \sa QFontMetricsF::ascent() */
end_comment
begin_function
DECL|function|ascent
name|qreal
name|QRawFont
operator|::
name|ascent
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
literal|0.0
return|;
return|return
name|d
operator|->
name|fontEngine
operator|->
name|ascent
argument_list|()
operator|.
name|toReal
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!    Returns the descent of this QRawFont in pixel units.     \sa QFontMetricsF::descent() */
end_comment
begin_function
DECL|function|descent
name|qreal
name|QRawFont
operator|::
name|descent
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
literal|0.0
return|;
return|return
name|d
operator|->
name|fontEngine
operator|->
name|descent
argument_list|()
operator|.
name|toReal
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!    Returns the pixel size set for this QRawFont. The pixel size affects how glyphs are    rasterized, the size of glyphs returned by pathForGlyph(), and is used to convert    internal metrics from design units to logical pixel units.     \sa setPixelSize() */
end_comment
begin_function
DECL|function|pixelSize
name|qreal
name|QRawFont
operator|::
name|pixelSize
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
literal|0.0
return|;
return|return
name|d
operator|->
name|fontEngine
operator|->
name|fontDef
operator|.
name|pixelSize
return|;
block|}
end_function
begin_comment
comment|/*!    Returns the number of design units define the width and height of the em square    for this QRawFont. This value is used together with the pixel size when converting design metrics    to pixel units, as the internal metrics are specified in design units and the pixel size gives    the size of 1 em in pixels.     \sa pixelSize(), setPixelSize() */
end_comment
begin_function
DECL|function|unitsPerEm
name|qreal
name|QRawFont
operator|::
name|unitsPerEm
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
literal|0.0
return|;
return|return
name|d
operator|->
name|fontEngine
operator|->
name|emSquareSize
argument_list|()
operator|.
name|toReal
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!    Returns the family name of this QRawFont. */
end_comment
begin_function
DECL|function|familyName
name|QString
name|QRawFont
operator|::
name|familyName
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|d
operator|->
name|fontEngine
operator|->
name|fontDef
operator|.
name|family
return|;
block|}
end_function
begin_comment
comment|/*!    Returns the style of this QRawFont.     \sa QFont::style() */
end_comment
begin_function
DECL|function|style
name|QFont
operator|::
name|Style
name|QRawFont
operator|::
name|style
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
name|QFont
operator|::
name|StyleNormal
return|;
return|return
name|QFont
operator|::
name|Style
argument_list|(
name|d
operator|->
name|fontEngine
operator|->
name|fontDef
operator|.
name|style
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!    Returns the weight of this QRawFont.     \sa QFont::weight() */
end_comment
begin_function
DECL|function|weight
name|int
name|QRawFont
operator|::
name|weight
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|int
argument_list|(
name|d
operator|->
name|fontEngine
operator|->
name|fontDef
operator|.
name|weight
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!    Converts a string of unicode points to glyph indexes using the CMAP table in the    underlying font. Note that in cases where there are other tables in the font that affect the    shaping of the text, the returned glyph indexes will not correctly represent the rendering    of the text. To get the correctly shaped text, you can use QTextLayout to lay out and shape the    text, and then call QTextLayout::glyphs() to get the set of glyph index list and QRawFont pairs.     \sa advancesForGlyphIndexes(), QGlyphs, QTextLayout::glyphs(), QTextFragment::glyphs() */
end_comment
begin_function
DECL|function|glyphIndexesForString
name|QVector
argument_list|<
name|quint32
argument_list|>
name|QRawFont
operator|::
name|glyphIndexesForString
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
name|QVector
argument_list|<
name|quint32
argument_list|>
argument_list|()
return|;
name|int
name|nglyphs
init|=
name|text
operator|.
name|size
argument_list|()
decl_stmt|;
name|QVarLengthGlyphLayoutArray
name|glyphs
argument_list|(
name|nglyphs
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|fontEngine
operator|->
name|stringToCMap
argument_list|(
name|text
operator|.
name|data
argument_list|()
argument_list|,
name|text
operator|.
name|size
argument_list|()
argument_list|,
operator|&
name|glyphs
argument_list|,
operator|&
name|nglyphs
argument_list|,
name|QTextEngine
operator|::
name|GlyphIndicesOnly
argument_list|)
condition|)
block|{
name|glyphs
operator|.
name|resize
argument_list|(
name|nglyphs
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|fontEngine
operator|->
name|stringToCMap
argument_list|(
name|text
operator|.
name|data
argument_list|()
argument_list|,
name|text
operator|.
name|size
argument_list|()
argument_list|,
operator|&
name|glyphs
argument_list|,
operator|&
name|nglyphs
argument_list|,
name|QTextEngine
operator|::
name|GlyphIndicesOnly
argument_list|)
condition|)
block|{
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"stringToCMap shouldn't fail twice"
argument_list|)
expr_stmt|;
return|return
name|QVector
argument_list|<
name|quint32
argument_list|>
argument_list|()
return|;
block|}
block|}
name|QVector
argument_list|<
name|quint32
argument_list|>
name|glyphIndexes
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
name|nglyphs
condition|;
operator|++
name|i
control|)
name|glyphIndexes
operator|.
name|append
argument_list|(
name|glyphs
operator|.
name|glyphs
index|[
name|i
index|]
argument_list|)
expr_stmt|;
return|return
name|glyphIndexes
return|;
block|}
end_function
begin_comment
comment|/*!    Returns the QRawFont's advances for each of the \a glyphIndexes in pixel units. The advances    give the distance from the position of a given glyph to where the next glyph should be drawn    to make it appear as if the two glyphs are unspaced.     \sa QTextLine::horizontalAdvance(), QFontMetricsF::width() */
end_comment
begin_function
DECL|function|advancesForGlyphIndexes
name|QVector
argument_list|<
name|QPointF
argument_list|>
name|QRawFont
operator|::
name|advancesForGlyphIndexes
parameter_list|(
specifier|const
name|QVector
argument_list|<
name|quint32
argument_list|>
modifier|&
name|glyphIndexes
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
name|QVector
argument_list|<
name|QPointF
argument_list|>
argument_list|()
return|;
name|int
name|numGlyphs
init|=
name|glyphIndexes
operator|.
name|size
argument_list|()
decl_stmt|;
name|QVarLengthGlyphLayoutArray
name|glyphs
argument_list|(
name|numGlyphs
argument_list|)
decl_stmt|;
name|qMemCopy
argument_list|(
name|glyphs
operator|.
name|glyphs
argument_list|,
name|glyphIndexes
operator|.
name|data
argument_list|()
argument_list|,
name|numGlyphs
operator|*
sizeof|sizeof
argument_list|(
name|quint32
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|fontEngine
operator|->
name|recalcAdvances
argument_list|(
operator|&
name|glyphs
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QVector
argument_list|<
name|QPointF
argument_list|>
name|advances
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
name|numGlyphs
condition|;
operator|++
name|i
control|)
name|advances
operator|.
name|append
argument_list|(
name|QPointF
argument_list|(
name|glyphs
operator|.
name|advances_x
index|[
name|i
index|]
operator|.
name|toReal
argument_list|()
argument_list|,
name|glyphs
operator|.
name|advances_y
index|[
name|i
index|]
operator|.
name|toReal
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|advances
return|;
block|}
end_function
begin_comment
comment|/*!    Returns the hinting preference used to construct this QRawFont.     \sa QFont::hintingPreference() */
end_comment
begin_function
DECL|function|hintingPreference
name|QFont
operator|::
name|HintingPreference
name|QRawFont
operator|::
name|hintingPreference
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
name|QFont
operator|::
name|PreferDefaultHinting
return|;
return|return
name|d
operator|->
name|hintingPreference
return|;
block|}
end_function
begin_comment
comment|/*!    Retrieves the sfnt table named \a tagName from the underlying physical font, or an empty    byte array if no such table was found. The returned font table's byte order is Big Endian, like    the sfnt format specifies. The \a tagName must be four characters long and should be formatted    in the default endianness of the current platform. */
end_comment
begin_function
DECL|function|fontTable
name|QByteArray
name|QRawFont
operator|::
name|fontTable
parameter_list|(
specifier|const
name|char
modifier|*
name|tagName
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
name|QByteArray
argument_list|()
return|;
specifier|const
name|quint32
modifier|*
name|tagId
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|quint32
operator|*
argument_list|>
argument_list|(
name|tagName
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|fontEngine
operator|->
name|getSfntTable
argument_list|(
name|qToBigEndian
argument_list|(
operator|*
name|tagId
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// From qfontdatabase.cpp
end_comment
begin_function_decl
specifier|extern
name|QList
argument_list|<
name|QFontDatabase
operator|::
name|WritingSystem
argument_list|>
name|qt_determine_writing_systems_from_truetype_bits
parameter_list|(
name|quint32
name|unicodeRange
index|[
literal|4
index|]
parameter_list|,
name|quint32
name|codePageRange
index|[
literal|2
index|]
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/*!    Returns a list of writing systems supported by the font according to designer supplied    information in the font file. Please note that this does not guarantee support for a    specific unicode point in the font. You can use the supportsCharacter() to check support    for a single, specific character.     \note The list is determined based on the unicode ranges and codepage ranges set in the font's    OS/2 table and requires such a table to be present in the underlying font file.     \sa supportsCharacter() */
end_comment
begin_function
DECL|function|supportedWritingSystems
name|QList
argument_list|<
name|QFontDatabase
operator|::
name|WritingSystem
argument_list|>
name|QRawFont
operator|::
name|supportedWritingSystems
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|isValid
argument_list|()
condition|)
block|{
name|QByteArray
name|os2Table
init|=
name|fontTable
argument_list|(
literal|"OS/2"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|os2Table
operator|.
name|isEmpty
argument_list|()
operator|&&
name|os2Table
operator|.
name|size
argument_list|()
operator|>
literal|86
condition|)
block|{
name|char
modifier|*
name|data
init|=
name|os2Table
operator|.
name|data
argument_list|()
decl_stmt|;
name|quint32
modifier|*
name|bigEndianUnicodeRanges
init|=
cast|reinterpret_cast
argument_list|<
name|quint32
operator|*
argument_list|>
argument_list|(
name|data
operator|+
literal|42
argument_list|)
decl_stmt|;
name|quint32
modifier|*
name|bigEndianCodepageRanges
init|=
cast|reinterpret_cast
argument_list|<
name|quint32
operator|*
argument_list|>
argument_list|(
name|data
operator|+
literal|78
argument_list|)
decl_stmt|;
name|quint32
name|unicodeRanges
index|[
literal|4
index|]
decl_stmt|;
name|quint32
name|codepageRanges
index|[
literal|2
index|]
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
literal|4
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
operator|<
literal|2
condition|)
name|codepageRanges
index|[
name|i
index|]
operator|=
name|qFromBigEndian
argument_list|(
name|bigEndianCodepageRanges
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|unicodeRanges
index|[
name|i
index|]
operator|=
name|qFromBigEndian
argument_list|(
name|bigEndianUnicodeRanges
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
return|return
name|qt_determine_writing_systems_from_truetype_bits
argument_list|(
name|unicodeRanges
argument_list|,
name|codepageRanges
argument_list|)
return|;
block|}
block|}
return|return
name|QList
argument_list|<
name|QFontDatabase
operator|::
name|WritingSystem
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the font has a glyph that corresponds to the given \a character.      \sa supportedWritingSystems() */
end_comment
begin_function
DECL|function|supportsCharacter
name|bool
name|QRawFont
operator|::
name|supportsCharacter
parameter_list|(
specifier|const
name|QChar
modifier|&
name|character
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
literal|false
return|;
return|return
name|d
operator|->
name|fontEngine
operator|->
name|canRender
argument_list|(
operator|&
name|character
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!    Returns true if the font has a glyph that corresponds to the UCS-4 encoded character \a ucs4.     \sa supportedWritingSystems() */
end_comment
begin_function
DECL|function|supportsCharacter
name|bool
name|QRawFont
operator|::
name|supportsCharacter
parameter_list|(
name|quint32
name|ucs4
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
literal|false
return|;
name|QString
name|str
init|=
name|QString
operator|::
name|fromUcs4
argument_list|(
operator|&
name|ucs4
argument_list|,
literal|1
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|fontEngine
operator|->
name|canRender
argument_list|(
name|str
operator|.
name|constData
argument_list|()
argument_list|,
name|str
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// qfontdatabase.cpp
end_comment
begin_function_decl
specifier|extern
name|int
name|qt_script_for_writing_system
parameter_list|(
name|QFontDatabase
operator|::
name|WritingSystem
name|writingSystem
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/*!    Fetches the physical representation based on a \a font query. The physical font returned is    the font that will be preferred by Qt in order to display text in the selected \a writingSystem. */
end_comment
begin_function
DECL|function|fromFont
name|QRawFont
name|QRawFont
operator|::
name|fromFont
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|,
name|QFontDatabase
operator|::
name|WritingSystem
name|writingSystem
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
name|QTextLayout
name|layout
argument_list|(
name|QFontDatabase
operator|::
name|writingSystemSample
argument_list|(
name|writingSystem
argument_list|)
argument_list|,
name|font
argument_list|)
decl_stmt|;
name|layout
operator|.
name|beginLayout
argument_list|()
expr_stmt|;
name|QTextLine
name|line
init|=
name|layout
operator|.
name|createLine
argument_list|()
decl_stmt|;
name|layout
operator|.
name|endLayout
argument_list|()
expr_stmt|;
name|QList
argument_list|<
name|QGlyphs
argument_list|>
name|list
init|=
name|layout
operator|.
name|glyphs
argument_list|()
decl_stmt|;
if|if
condition|(
name|list
operator|.
name|size
argument_list|()
condition|)
block|{
comment|// Pick the one matches the family name we originally requested,
comment|// if none of them match, just pick the first one
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|list
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QGlyphs
name|glyphs
init|=
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QRawFont
name|rawfont
init|=
name|glyphs
operator|.
name|font
argument_list|()
decl_stmt|;
if|if
condition|(
name|rawfont
operator|.
name|familyName
argument_list|()
operator|==
name|font
operator|.
name|family
argument_list|()
condition|)
return|return
name|rawfont
return|;
block|}
return|return
name|list
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|font
argument_list|()
return|;
block|}
return|return
name|QRawFont
argument_list|()
return|;
else|#
directive|else
name|QFontPrivate
modifier|*
name|font_d
init|=
name|QFontPrivate
operator|::
name|get
argument_list|(
name|font
argument_list|)
decl_stmt|;
name|int
name|script
init|=
name|qt_script_for_writing_system
argument_list|(
name|writingSystem
argument_list|)
decl_stmt|;
name|QFontEngine
modifier|*
name|fe
init|=
name|font_d
operator|->
name|engineForScript
argument_list|(
name|script
argument_list|)
decl_stmt|;
if|if
condition|(
name|fe
operator|!=
literal|0
operator|&&
name|fe
operator|->
name|type
argument_list|()
operator|==
name|QFontEngine
operator|::
name|Multi
condition|)
block|{
name|QFontEngineMulti
modifier|*
name|multiEngine
init|=
cast|static_cast
argument_list|<
name|QFontEngineMulti
operator|*
argument_list|>
argument_list|(
name|fe
argument_list|)
decl_stmt|;
name|fe
operator|=
name|multiEngine
operator|->
name|engine
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|fe
operator|==
literal|0
condition|)
block|{
name|multiEngine
operator|->
name|loadEngine
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|fe
operator|=
name|multiEngine
operator|->
name|engine
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|fe
operator|!=
literal|0
condition|)
block|{
name|QRawFont
name|rawFont
decl_stmt|;
name|rawFont
operator|.
name|d
operator|.
name|data
argument_list|()
operator|->
name|fontEngine
operator|=
name|fe
expr_stmt|;
name|rawFont
operator|.
name|d
operator|.
name|data
argument_list|()
operator|->
name|fontEngine
operator|->
name|ref
operator|.
name|ref
argument_list|()
expr_stmt|;
name|rawFont
operator|.
name|d
operator|.
name|data
argument_list|()
operator|->
name|hintingPreference
operator|=
name|font
operator|.
name|hintingPreference
argument_list|()
expr_stmt|;
return|return
name|rawFont
return|;
block|}
else|else
block|{
return|return
name|QRawFont
argument_list|()
return|;
block|}
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*!    Sets the pixel size with which this font should be rendered to \a pixelSize. */
end_comment
begin_function
DECL|function|setPixelSize
name|void
name|QRawFont
operator|::
name|setPixelSize
parameter_list|(
name|qreal
name|pixelSize
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|fontEngine
operator|==
literal|0
condition|)
return|return;
name|detach
argument_list|()
expr_stmt|;
name|QFontEngine
modifier|*
name|oldFontEngine
init|=
name|d
operator|->
name|fontEngine
decl_stmt|;
name|d
operator|->
name|fontEngine
operator|=
name|d
operator|->
name|fontEngine
operator|->
name|cloneWithSize
argument_list|(
name|pixelSize
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|fontEngine
operator|!=
literal|0
condition|)
name|d
operator|->
name|fontEngine
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
name|oldFontEngine
operator|->
name|ref
operator|.
name|deref
argument_list|()
expr_stmt|;
if|if
condition|(
name|oldFontEngine
operator|->
name|cache_count
operator|==
literal|0
operator|&&
name|oldFontEngine
operator|->
name|ref
operator|==
literal|0
condition|)
operator|delete
name|oldFontEngine
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|detach
name|void
name|QRawFont
operator|::
name|detach
parameter_list|()
block|{
if|if
condition|(
name|d
operator|->
name|ref
operator|!=
literal|1
condition|)
name|d
operator|.
name|detach
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|cleanUp
name|void
name|QRawFontPrivate
operator|::
name|cleanUp
parameter_list|()
block|{
name|platformCleanUp
argument_list|()
expr_stmt|;
if|if
condition|(
name|fontEngine
operator|!=
literal|0
condition|)
block|{
name|fontEngine
operator|->
name|ref
operator|.
name|deref
argument_list|()
expr_stmt|;
if|if
condition|(
name|fontEngine
operator|->
name|cache_count
operator|==
literal|0
operator|&&
name|fontEngine
operator|->
name|ref
operator|==
literal|0
condition|)
operator|delete
name|fontEngine
expr_stmt|;
name|fontEngine
operator|=
literal|0
expr_stmt|;
block|}
name|hintingPreference
operator|=
name|QFont
operator|::
name|PreferDefaultHinting
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_RAWFONT
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
