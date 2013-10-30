begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONTENGINE_P_H
end_ifndef
begin_define
DECL|macro|QFONTENGINE_P_H
define|#
directive|define
name|QFONTENGINE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtCore/qglobal.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qatomic.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qvarlengtharray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLinkedList>
end_include
begin_include
include|#
directive|include
file|"private/qtextengine_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qfont_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qfontengineglyphcache_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPainterPath
name|class
name|QPainterPath
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QGlyphLayout
struct_decl|;
end_struct_decl
begin_define
DECL|macro|MAKE_TAG
define|#
directive|define
name|MAKE_TAG
parameter_list|(
name|ch1
parameter_list|,
name|ch2
parameter_list|,
name|ch3
parameter_list|,
name|ch4
parameter_list|)
value|(\     (((quint32)(ch1))<< 24) | \     (((quint32)(ch2))<< 16) | \     (((quint32)(ch3))<< 8) | \     ((quint32)(ch4)) \    )
end_define
begin_comment
comment|// ### this only used in getPointInOutline(), refactor it and then remove these magic numbers
end_comment
begin_enum
DECL|enum|HB_Compat_Error
enum|enum
name|HB_Compat_Error
block|{
DECL|enumerator|Err_Ok
name|Err_Ok
init|=
literal|0x0000
block|,
DECL|enumerator|Err_Not_Covered
name|Err_Not_Covered
init|=
literal|0xFFFF
block|,
DECL|enumerator|Err_Invalid_Argument
name|Err_Invalid_Argument
init|=
literal|0x1A66
block|,
DECL|enumerator|Err_Invalid_SubTable_Format
name|Err_Invalid_SubTable_Format
init|=
literal|0x157F
block|,
DECL|enumerator|Err_Invalid_SubTable
name|Err_Invalid_SubTable
init|=
literal|0x1570
block|}
enum|;
end_enum
begin_typedef
DECL|typedef|qt_destroy_func_t
typedef|typedef
name|void
function_decl|(
modifier|*
name|qt_destroy_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QFontEngine
block|{
name|public
label|:
enum|enum
name|Type
block|{
name|Box
block|,
name|Multi
block|,
comment|// MS Windows types
name|Win
block|,
comment|// Apple Mac OS types
name|Mac
block|,
comment|// QWS types
name|Freetype
block|,
name|QPF1
block|,
name|QPF2
block|,
name|Proxy
block|,
name|DirectWrite
block|,
name|TestFontEngine
init|=
literal|0x1000
block|}
enum|;
enum|enum
name|GlyphFormat
block|{
name|Format_None
block|,
name|Format_Render
init|=
name|Format_None
block|,
name|Format_Mono
block|,
name|Format_A8
block|,
name|Format_A32
block|,
name|Format_ARGB
block|}
enum|;
enum|enum
name|ShaperFlag
block|{
name|RightToLeft
init|=
literal|0x0001
block|,
name|DesignMetrics
init|=
literal|0x0002
block|,
name|GlyphIndicesOnly
init|=
literal|0x0004
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|ShaperFlags
argument_list|,
argument|ShaperFlag
argument_list|)
name|QFontEngine
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QFontEngine
argument_list|()
expr_stmt|;
comment|// all of these are in unscaled metrics if the engine supports uncsaled metrics,
comment|// otherwise in design metrics
struct|struct
name|Properties
block|{
name|QByteArray
name|postscriptName
decl_stmt|;
name|QByteArray
name|copyright
decl_stmt|;
name|QRectF
name|boundingBox
decl_stmt|;
name|QFixed
name|emSquare
decl_stmt|;
name|QFixed
name|ascent
decl_stmt|;
name|QFixed
name|descent
decl_stmt|;
name|QFixed
name|leading
decl_stmt|;
name|QFixed
name|italicAngle
decl_stmt|;
name|QFixed
name|capHeight
decl_stmt|;
name|QFixed
name|lineWidth
decl_stmt|;
block|}
struct|;
name|virtual
name|Properties
name|properties
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|void
name|getUnscaledGlyph
parameter_list|(
name|glyph_t
name|glyph
parameter_list|,
name|QPainterPath
modifier|*
name|path
parameter_list|,
name|glyph_metrics_t
modifier|*
name|metrics
parameter_list|)
function_decl|;
name|QByteArray
name|getSfntTable
argument_list|(
name|uint
comment|/*tag*/
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|getSfntTableData
argument_list|(
name|uint
comment|/*tag*/
argument_list|,
name|uchar
operator|*
comment|/*buffer*/
argument_list|,
name|uint
operator|*
comment|/*length*/
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
struct|struct
name|FaceId
block|{
name|FaceId
argument_list|()
operator|:
name|index
argument_list|(
literal|0
argument_list|)
operator|,
name|encoding
argument_list|(
literal|0
argument_list|)
block|{}
name|QByteArray
name|filename
expr_stmt|;
name|QByteArray
name|uuid
decl_stmt|;
name|int
name|index
decl_stmt|;
name|int
name|encoding
decl_stmt|;
block|}
struct|;
name|virtual
name|FaceId
name|faceId
argument_list|()
specifier|const
block|{
return|return
name|FaceId
argument_list|()
return|;
block|}
enum|enum
name|SynthesizedFlags
block|{
name|SynthesizedItalic
init|=
literal|0x1
block|,
name|SynthesizedBold
init|=
literal|0x2
block|,
name|SynthesizedStretch
init|=
literal|0x4
block|}
enum|;
name|virtual
name|int
name|synthesized
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|bool
name|supportsSubPixelPositions
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|QFixed
name|subPixelPositionForX
argument_list|(
name|QFixed
name|x
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QFixed
name|emSquareSize
argument_list|()
specifier|const
block|{
return|return
name|ascent
argument_list|()
return|;
block|}
comment|/* returns 0 as glyph index for non existent glyphs */
name|virtual
name|bool
name|stringToCMap
argument_list|(
specifier|const
name|QChar
operator|*
name|str
argument_list|,
name|int
name|len
argument_list|,
name|QGlyphLayout
operator|*
name|glyphs
argument_list|,
name|int
operator|*
name|nglyphs
argument_list|,
name|ShaperFlags
name|flags
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|recalcAdvances
argument_list|(
name|QGlyphLayout
operator|*
argument_list|,
name|ShaperFlags
argument_list|)
decl|const
block|{}
name|virtual
name|void
name|doKerning
argument_list|(
name|QGlyphLayout
operator|*
argument_list|,
name|ShaperFlags
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|addGlyphsToPath
argument_list|(
name|glyph_t
operator|*
name|glyphs
argument_list|,
name|QFixedPoint
operator|*
name|positions
argument_list|,
name|int
name|nglyphs
argument_list|,
name|QPainterPath
operator|*
name|path
argument_list|,
name|QTextItem
operator|::
name|RenderFlags
name|flags
argument_list|)
decl_stmt|;
name|void
name|getGlyphPositions
argument_list|(
specifier|const
name|QGlyphLayout
operator|&
name|glyphs
argument_list|,
specifier|const
name|QTransform
operator|&
name|matrix
argument_list|,
name|QTextItem
operator|::
name|RenderFlags
name|flags
argument_list|,
name|QVarLengthArray
operator|<
name|glyph_t
operator|>
operator|&
name|glyphs_out
argument_list|,
name|QVarLengthArray
operator|<
name|QFixedPoint
operator|>
operator|&
name|positions
argument_list|)
decl_stmt|;
name|virtual
name|void
name|addOutlineToPath
argument_list|(
name|qreal
argument_list|,
name|qreal
argument_list|,
specifier|const
name|QGlyphLayout
operator|&
argument_list|,
name|QPainterPath
operator|*
argument_list|,
name|QTextItem
operator|::
name|RenderFlags
name|flags
argument_list|)
decl_stmt|;
name|void
name|addBitmapFontToPath
argument_list|(
name|qreal
name|x
argument_list|,
name|qreal
name|y
argument_list|,
specifier|const
name|QGlyphLayout
operator|&
argument_list|,
name|QPainterPath
operator|*
argument_list|,
name|QTextItem
operator|::
name|RenderFlags
argument_list|)
decl_stmt|;
comment|/**      * Create a qimage with the alpha values for the glyph.      * Returns an image indexed_8 with index values ranging from 0=fully transparent to 255=opaque      */
comment|// ### Refactor this into a smaller and more flexible API.
name|virtual
name|QImage
name|alphaMapForGlyph
parameter_list|(
name|glyph_t
parameter_list|)
function_decl|;
name|virtual
name|QImage
name|alphaMapForGlyph
parameter_list|(
name|glyph_t
name|glyph
parameter_list|,
name|QFixed
name|subPixelPosition
parameter_list|)
function_decl|;
name|virtual
name|QImage
name|alphaMapForGlyph
parameter_list|(
name|glyph_t
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|t
parameter_list|)
function_decl|;
name|virtual
name|QImage
name|alphaMapForGlyph
parameter_list|(
name|glyph_t
parameter_list|,
name|QFixed
name|subPixelPosition
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|t
parameter_list|)
function_decl|;
name|virtual
name|QImage
name|alphaRGBMapForGlyph
parameter_list|(
name|glyph_t
parameter_list|,
name|QFixed
name|subPixelPosition
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|t
parameter_list|)
function_decl|;
name|virtual
name|QImage
name|bitmapForGlyph
parameter_list|(
name|glyph_t
parameter_list|,
name|QFixed
name|subPixelPosition
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|t
parameter_list|)
function_decl|;
name|virtual
name|QImage
modifier|*
name|lockedAlphaMapForGlyph
parameter_list|(
name|glyph_t
name|glyph
parameter_list|,
name|QFixed
name|subPixelPosition
parameter_list|,
name|GlyphFormat
name|neededFormat
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|t
init|=
name|QTransform
argument_list|()
parameter_list|,
name|QPoint
modifier|*
name|offset
init|=
literal|0
parameter_list|)
function_decl|;
name|virtual
name|void
name|unlockAlphaMapForGlyph
parameter_list|()
function_decl|;
name|virtual
name|bool
name|hasInternalCaching
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|glyph_metrics_t
name|alphaMapBoundingBox
parameter_list|(
name|glyph_t
name|glyph
parameter_list|,
name|QFixed
comment|/*subPixelPosition*/
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|matrix
parameter_list|,
name|GlyphFormat
comment|/*format*/
parameter_list|)
block|{
return|return
name|boundingBox
argument_list|(
name|glyph
argument_list|,
name|matrix
argument_list|)
return|;
block|}
name|virtual
name|void
name|removeGlyphFromCache
parameter_list|(
name|glyph_t
parameter_list|)
function_decl|;
name|virtual
name|glyph_metrics_t
name|boundingBox
parameter_list|(
specifier|const
name|QGlyphLayout
modifier|&
name|glyphs
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|glyph_metrics_t
name|boundingBox
parameter_list|(
name|glyph_t
name|glyph
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|glyph_metrics_t
name|boundingBox
parameter_list|(
name|glyph_t
name|glyph
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|matrix
parameter_list|)
function_decl|;
name|glyph_metrics_t
name|tightBoundingBox
parameter_list|(
specifier|const
name|QGlyphLayout
modifier|&
name|glyphs
parameter_list|)
function_decl|;
name|virtual
name|QFixed
name|ascent
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QFixed
name|descent
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QFixed
name|leading
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QFixed
name|xHeight
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QFixed
name|averageCharWidth
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QFixed
name|lineThickness
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QFixed
name|underlinePosition
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|qreal
name|maxCharWidth
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|qreal
name|minLeftBearing
argument_list|()
specifier|const
block|{
return|return
name|qreal
argument_list|()
return|;
block|}
name|virtual
name|qreal
name|minRightBearing
argument_list|()
specifier|const
block|{
return|return
name|qreal
argument_list|()
return|;
block|}
name|virtual
name|void
name|getGlyphBearings
parameter_list|(
name|glyph_t
name|glyph
parameter_list|,
name|qreal
modifier|*
name|leftBearing
init|=
literal|0
parameter_list|,
name|qreal
modifier|*
name|rightBearing
init|=
literal|0
parameter_list|)
function_decl|;
name|virtual
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|canRender
parameter_list|(
specifier|const
name|QChar
modifier|*
name|string
parameter_list|,
name|int
name|len
parameter_list|)
init|=
literal|0
function_decl|;
specifier|inline
name|bool
name|canRender
parameter_list|(
name|uint
name|ucs4
parameter_list|)
block|{
name|QChar
name|utf16
index|[
literal|2
index|]
decl_stmt|;
name|int
name|utf16len
init|=
literal|1
decl_stmt|;
if|if
condition|(
name|QChar
operator|::
name|requiresSurrogates
argument_list|(
name|ucs4
argument_list|)
condition|)
block|{
name|utf16
index|[
literal|0
index|]
operator|=
name|QChar
operator|::
name|highSurrogate
argument_list|(
name|ucs4
argument_list|)
expr_stmt|;
name|utf16
index|[
literal|1
index|]
operator|=
name|QChar
operator|::
name|lowSurrogate
argument_list|(
name|ucs4
argument_list|)
expr_stmt|;
operator|++
name|utf16len
expr_stmt|;
block|}
else|else
block|{
name|utf16
index|[
literal|0
index|]
operator|=
name|QChar
argument_list|(
name|ucs4
argument_list|)
expr_stmt|;
block|}
return|return
name|canRender
argument_list|(
name|utf16
argument_list|,
name|utf16len
argument_list|)
return|;
block|}
name|virtual
name|bool
name|supportsTransformation
argument_list|(
specifier|const
name|QTransform
operator|&
name|transform
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|Type
name|type
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|int
name|glyphCount
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|int
name|glyphMargin
argument_list|(
name|QFontEngineGlyphCache
operator|::
name|Type
name|type
argument_list|)
block|{
return|return
name|type
operator|==
name|QFontEngineGlyphCache
operator|::
name|Raster_RGBMask
condition|?
literal|2
else|:
literal|0
return|;
block|}
name|virtual
name|QFontEngine
modifier|*
name|cloneWithSize
argument_list|(
name|qreal
comment|/*pixelSize*/
argument_list|)
decl|const
block|{
return|return
literal|0
return|;
block|}
name|void
operator|*
name|harfbuzzFont
argument_list|()
specifier|const
expr_stmt|;
name|void
operator|*
name|harfbuzzFace
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsScript
argument_list|(
name|QChar
operator|::
name|Script
name|script
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|int
name|getPointInOutline
parameter_list|(
name|glyph_t
name|glyph
parameter_list|,
name|int
name|flags
parameter_list|,
name|quint32
name|point
parameter_list|,
name|QFixed
modifier|*
name|xpos
parameter_list|,
name|QFixed
modifier|*
name|ypos
parameter_list|,
name|quint32
modifier|*
name|nPoints
parameter_list|)
function_decl|;
name|void
name|clearGlyphCache
parameter_list|(
specifier|const
name|void
modifier|*
name|key
parameter_list|)
function_decl|;
name|void
name|setGlyphCache
parameter_list|(
specifier|const
name|void
modifier|*
name|key
parameter_list|,
name|QFontEngineGlyphCache
modifier|*
name|data
parameter_list|)
function_decl|;
name|QFontEngineGlyphCache
modifier|*
name|glyphCache
argument_list|(
specifier|const
name|void
operator|*
name|key
argument_list|,
name|QFontEngineGlyphCache
operator|::
name|Type
name|type
argument_list|,
specifier|const
name|QTransform
operator|&
name|transform
argument_list|)
decl|const
decl_stmt|;
specifier|static
specifier|const
name|uchar
modifier|*
name|getCMap
parameter_list|(
specifier|const
name|uchar
modifier|*
name|table
parameter_list|,
name|uint
name|tableSize
parameter_list|,
name|bool
modifier|*
name|isSymbolFont
parameter_list|,
name|int
modifier|*
name|cmapSize
parameter_list|)
function_decl|;
specifier|static
name|quint32
name|getTrueTypeGlyphIndex
parameter_list|(
specifier|const
name|uchar
modifier|*
name|cmap
parameter_list|,
name|uint
name|unicode
parameter_list|)
function_decl|;
specifier|static
name|QByteArray
name|convertToPostscriptFontFamilyName
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fontFamily
parameter_list|)
function_decl|;
enum|enum
name|HintStyle
block|{
name|HintNone
block|,
name|HintLight
block|,
name|HintMedium
block|,
name|HintFull
block|}
enum|;
name|virtual
name|void
name|setDefaultHintStyle
parameter_list|(
name|HintStyle
parameter_list|)
block|{ }
name|QAtomicInt
name|ref
decl_stmt|;
name|QFontDef
name|fontDef
decl_stmt|;
name|mutable
name|void
modifier|*
name|font_
decl_stmt|;
name|mutable
name|qt_destroy_func_t
name|font_destroy_func
decl_stmt|;
name|mutable
name|void
modifier|*
name|face_
decl_stmt|;
name|mutable
name|qt_destroy_func_t
name|face_destroy_func
decl_stmt|;
name|uint
name|cache_cost
decl_stmt|;
comment|// amount of mem used in kb by the font
name|uint
name|fsType
range|:
literal|16
decl_stmt|;
name|bool
name|symbol
decl_stmt|;
struct|struct
name|KernPair
block|{
name|uint
name|left_right
decl_stmt|;
name|QFixed
name|adjust
decl_stmt|;
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|KernPair
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|left_right
operator|<
name|other
operator|.
name|left_right
return|;
block|}
block|}
struct|;
name|QVector
operator|<
name|KernPair
operator|>
name|kerning_pairs
expr_stmt|;
name|void
name|loadKerningPairs
parameter_list|(
name|QFixed
name|scalingFactor
parameter_list|)
function_decl|;
name|int
name|glyphFormat
decl_stmt|;
name|QImage
name|currentlyLockedAlphaMap
decl_stmt|;
name|int
name|m_subPixelPositionCount
decl_stmt|;
comment|// Number of positions within a single pixel for this cache
specifier|inline
name|QVariant
name|userData
argument_list|()
specifier|const
block|{
return|return
name|m_userData
return|;
block|}
name|bool
name|smoothScalable
decl_stmt|;
name|protected
label|:
name|QFixed
name|lastRightBearing
parameter_list|(
specifier|const
name|QGlyphLayout
modifier|&
name|glyphs
parameter_list|,
name|bool
name|round
init|=
name|false
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setUserData
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|userData
parameter_list|)
block|{
name|m_userData
operator|=
name|userData
expr_stmt|;
block|}
name|private
label|:
struct|struct
name|GlyphCacheEntry
block|{
specifier|const
name|void
modifier|*
name|context
decl_stmt|;
name|QExplicitlySharedDataPointer
operator|<
name|QFontEngineGlyphCache
operator|>
name|cache
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|GlyphCacheEntry
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|context
operator|==
name|other
operator|.
name|context
operator|&&
name|cache
operator|==
name|other
operator|.
name|cache
return|;
block|}
block|}
struct|;
name|mutable
name|QLinkedList
operator|<
name|GlyphCacheEntry
operator|>
name|m_glyphCaches
expr_stmt|;
name|private
label|:
name|QVariant
name|m_userData
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QFontEngine::ShaperFlags
argument_list|)
end_macro
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QFontEngine
operator|::
name|FaceId
operator|&
name|f1
operator|,
specifier|const
name|QFontEngine
operator|::
name|FaceId
operator|&
name|f2
operator|)
block|{
return|return
operator|(
name|f1
operator|.
name|index
operator|==
name|f2
operator|.
name|index
operator|)
operator|&&
operator|(
name|f1
operator|.
name|encoding
operator|==
name|f2
operator|.
name|encoding
operator|)
operator|&&
operator|(
name|f1
operator|.
name|filename
operator|==
name|f2
operator|.
name|filename
operator|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
DECL|function|qHash
specifier|inline
name|uint
name|qHash
argument_list|(
specifier|const
name|QFontEngine
operator|::
name|FaceId
operator|&
name|f
argument_list|)
block|{
return|return
name|qHash
argument_list|(
operator|(
name|f
operator|.
name|index
operator|<<
literal|16
operator|)
operator|+
name|f
operator|.
name|encoding
argument_list|)
operator|+
name|qHash
argument_list|(
name|f
operator|.
name|filename
operator|+
name|f
operator|.
name|uuid
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
DECL|variable|QGlyph
name|class
name|QGlyph
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFontEngineBox
range|:
name|public
name|QFontEngine
block|{
name|public
operator|:
name|QFontEngineBox
argument_list|(
argument|int size
argument_list|)
block|;
operator|~
name|QFontEngineBox
argument_list|()
block|;
name|virtual
name|bool
name|stringToCMap
argument_list|(
argument|const QChar *str
argument_list|,
argument|int len
argument_list|,
argument|QGlyphLayout *glyphs
argument_list|,
argument|int *nglyphs
argument_list|,
argument|ShaperFlags flags
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|recalcAdvances
argument_list|(
argument|QGlyphLayout *
argument_list|,
argument|ShaperFlags
argument_list|)
specifier|const
block|;
name|void
name|draw
argument_list|(
argument|QPaintEngine *p
argument_list|,
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|const QTextItemInt&si
argument_list|)
block|;
name|virtual
name|void
name|addOutlineToPath
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|const QGlyphLayout&glyphs
argument_list|,
argument|QPainterPath *path
argument_list|,
argument|QTextItem::RenderFlags flags
argument_list|)
block|;
name|virtual
name|glyph_metrics_t
name|boundingBox
argument_list|(
specifier|const
name|QGlyphLayout
operator|&
name|glyphs
argument_list|)
block|;
name|virtual
name|glyph_metrics_t
name|boundingBox
argument_list|(
argument|glyph_t glyph
argument_list|)
block|;
name|virtual
name|QFontEngine
operator|*
name|cloneWithSize
argument_list|(
argument|qreal pixelSize
argument_list|)
specifier|const
block|;
name|virtual
name|QFixed
name|ascent
argument_list|()
specifier|const
block|;
name|virtual
name|QFixed
name|descent
argument_list|()
specifier|const
block|;
name|virtual
name|QFixed
name|leading
argument_list|()
specifier|const
block|;
name|virtual
name|qreal
name|maxCharWidth
argument_list|()
specifier|const
block|;
name|virtual
name|qreal
name|minLeftBearing
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|qreal
name|minRightBearing
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|QImage
name|alphaMapForGlyph
argument_list|(
name|glyph_t
argument_list|)
block|;
name|virtual
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|canRender
argument_list|(
argument|const QChar *string
argument_list|,
argument|int len
argument_list|)
block|;
name|virtual
name|Type
name|type
argument_list|()
specifier|const
block|;
specifier|inline
name|int
name|size
argument_list|()
specifier|const
block|{
return|return
name|_size
return|;
block|}
name|private
operator|:
name|friend
name|class
name|QFontPrivate
block|;
name|int
name|_size
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QFontEngineMulti
range|:
name|public
name|QFontEngine
block|{
name|public
operator|:
name|explicit
name|QFontEngineMulti
argument_list|(
argument|int engineCount
argument_list|)
block|;
operator|~
name|QFontEngineMulti
argument_list|()
block|;
name|virtual
name|bool
name|stringToCMap
argument_list|(
argument|const QChar *str
argument_list|,
argument|int len
argument_list|,
argument|QGlyphLayout *glyphs
argument_list|,
argument|int *nglyphs
argument_list|,
argument|ShaperFlags flags
argument_list|)
specifier|const
block|;
name|virtual
name|glyph_metrics_t
name|boundingBox
argument_list|(
specifier|const
name|QGlyphLayout
operator|&
name|glyphs
argument_list|)
block|;
name|virtual
name|glyph_metrics_t
name|boundingBox
argument_list|(
argument|glyph_t glyph
argument_list|)
block|;
name|virtual
name|void
name|recalcAdvances
argument_list|(
argument|QGlyphLayout *
argument_list|,
argument|ShaperFlags
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|doKerning
argument_list|(
argument|QGlyphLayout *
argument_list|,
argument|ShaperFlags
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|addOutlineToPath
argument_list|(
argument|qreal
argument_list|,
argument|qreal
argument_list|,
argument|const QGlyphLayout&
argument_list|,
argument|QPainterPath *
argument_list|,
argument|QTextItem::RenderFlags flags
argument_list|)
block|;
name|virtual
name|void
name|getGlyphBearings
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|qreal *leftBearing =
literal|0
argument_list|,
argument|qreal *rightBearing =
literal|0
argument_list|)
block|;
name|virtual
name|QFixed
name|ascent
argument_list|()
specifier|const
block|;
name|virtual
name|QFixed
name|descent
argument_list|()
specifier|const
block|;
name|virtual
name|QFixed
name|leading
argument_list|()
specifier|const
block|;
name|virtual
name|QFixed
name|xHeight
argument_list|()
specifier|const
block|;
name|virtual
name|QFixed
name|averageCharWidth
argument_list|()
specifier|const
block|;
name|virtual
name|QImage
name|alphaMapForGlyph
argument_list|(
name|glyph_t
argument_list|)
block|;
name|virtual
name|QImage
name|alphaMapForGlyph
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|QFixed subPixelPosition
argument_list|)
block|;
name|virtual
name|QImage
name|alphaMapForGlyph
argument_list|(
name|glyph_t
argument_list|,
specifier|const
name|QTransform
operator|&
name|t
argument_list|)
block|;
name|virtual
name|QImage
name|alphaMapForGlyph
argument_list|(
argument|glyph_t
argument_list|,
argument|QFixed subPixelPosition
argument_list|,
argument|const QTransform&t
argument_list|)
block|;
name|virtual
name|QImage
name|alphaRGBMapForGlyph
argument_list|(
argument|glyph_t
argument_list|,
argument|QFixed subPixelPosition
argument_list|,
argument|const QTransform&t
argument_list|)
block|;
name|virtual
name|QFixed
name|lineThickness
argument_list|()
specifier|const
block|;
name|virtual
name|QFixed
name|underlinePosition
argument_list|()
specifier|const
block|;
name|virtual
name|qreal
name|maxCharWidth
argument_list|()
specifier|const
block|;
name|virtual
name|qreal
name|minLeftBearing
argument_list|()
specifier|const
block|;
name|virtual
name|qreal
name|minRightBearing
argument_list|()
specifier|const
block|;
name|virtual
specifier|inline
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|QFontEngine
operator|::
name|Multi
return|;
block|}
name|virtual
name|bool
name|canRender
argument_list|(
argument|const QChar *string
argument_list|,
argument|int len
argument_list|)
block|;
specifier|inline
name|virtual
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|{
return|return
literal|"Multi"
return|;
block|}
name|QFontEngine
operator|*
name|engine
argument_list|(
argument|int at
argument_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|at
operator|<
name|engines
operator|.
name|size
argument_list|()
argument_list|)
block|;
return|return
name|engines
operator|.
name|at
argument_list|(
name|at
argument_list|)
return|;
block|}
specifier|inline
name|void
name|ensureEngineAt
argument_list|(
argument|int at
argument_list|)
block|{
if|if
condition|(
name|at
operator|>=
name|engines
operator|.
name|size
argument_list|()
operator|||
name|engines
operator|.
name|at
argument_list|(
name|at
argument_list|)
operator|==
literal|0
condition|)
name|loadEngine
argument_list|(
name|at
argument_list|)
expr_stmt|;
block|}
name|virtual
name|bool
name|shouldLoadFontEngineForCharacter
argument_list|(
argument|int at
argument_list|,
argument|uint ucs4
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|setFallbackFamiliesList
argument_list|(
argument|const QStringList&
argument_list|)
block|{}
name|protected
operator|:
name|friend
name|class
name|QRawFont
block|;
name|virtual
name|void
name|loadEngine
argument_list|(
argument|int at
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|ensureFallbackFamiliesQueried
argument_list|()
block|{}
name|QVector
operator|<
name|QFontEngine
operator|*
operator|>
name|engines
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTestFontEngine
range|:
name|public
name|QFontEngineBox
block|{
name|public
operator|:
name|QTestFontEngine
argument_list|(
argument|int size
argument_list|)
block|;
name|virtual
name|Type
name|type
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFONTENGINE_P_H
end_comment
end_unit
