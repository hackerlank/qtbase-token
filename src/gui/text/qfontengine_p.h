begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WIN
end_ifdef
begin_include
include|#
directive|include
file|"QtCore/qt_windows.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_MAC
end_ifdef
begin_include
include|#
directive|include
file|"private/qt_mac_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmap.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qcache.h"
end_include
begin_include
include|#
directive|include
file|"private/qcore_mac_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<private/qfontengineglyphcache_p.h>
end_include
begin_struct_decl
struct_decl|struct
name|glyph_metrics_t
struct_decl|;
end_struct_decl
begin_typedef
DECL|typedef|glyph_t
typedef|typedef
name|unsigned
name|int
name|glyph_t
typedef|;
end_typedef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QChar
name|class
name|QChar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPainterPath
name|class
name|QPainterPath
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextEngine
name|class
name|QTextEngine
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
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QFontEngine
range|:
name|public
name|QObject
block|{
name|public
operator|:
expr|enum
name|Type
block|{
name|Box
block|,
name|Multi
block|,
comment|// X11 types
name|XLFD
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
comment|// S60 types
name|S60FontEngine
block|,
comment|// Cannot be simply called "S60". Reason is qt_s60Data.h
name|DirectWrite
block|,
name|TestFontEngine
operator|=
literal|0x1000
block|}
block|;      enum
name|GlyphFormat
block|{
name|Format_None
block|,
name|Format_Render
operator|=
name|Format_None
block|,
name|Format_Mono
block|,
name|Format_A8
block|,
name|Format_A32
block|}
block|;
name|QFontEngine
argument_list|()
block|;
name|virtual
operator|~
name|QFontEngine
argument_list|()
block|;
comment|// all of these are in unscaled metrics if the engine supports uncsaled metrics,
comment|// otherwise in design metrics
block|struct
name|Properties
block|{
name|QByteArray
name|postscriptName
block|;
name|QByteArray
name|copyright
block|;
name|QRectF
name|boundingBox
block|;
name|QFixed
name|emSquare
block|;
name|QFixed
name|ascent
block|;
name|QFixed
name|descent
block|;
name|QFixed
name|leading
block|;
name|QFixed
name|italicAngle
block|;
name|QFixed
name|capHeight
block|;
name|QFixed
name|lineWidth
block|;     }
block|;
name|virtual
name|Properties
name|properties
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|getUnscaledGlyph
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|QPainterPath *path
argument_list|,
argument|glyph_metrics_t *metrics
argument_list|)
block|;
name|QByteArray
name|getSfntTable
argument_list|(
argument|uint
comment|/*tag*/
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|getSfntTableData
argument_list|(
argument|uint
comment|/*tag*/
argument_list|,
argument|uchar *
comment|/*buffer*/
argument_list|,
argument|uint *
comment|/*length*/
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
expr|struct
name|FaceId
block|{
name|FaceId
argument_list|()
operator|:
name|index
argument_list|(
literal|0
argument_list|)
block|,
name|encoding
argument_list|(
literal|0
argument_list|)
block|{}
name|QByteArray
name|filename
block|;
name|QByteArray
name|uuid
block|;
name|int
name|index
block|;
name|int
name|encoding
block|;     }
block|;
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
expr|enum
name|SynthesizedFlags
block|{
name|SynthesizedItalic
operator|=
literal|0x1
block|,
name|SynthesizedBold
operator|=
literal|0x2
block|,
name|SynthesizedStretch
operator|=
literal|0x4
block|}
block|;
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
argument|const QChar *str
argument_list|,
argument|int len
argument_list|,
argument|QGlyphLayout *glyphs
argument_list|,
argument|int *nglyphs
argument_list|,
argument|QTextEngine::ShaperFlags flags
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/**      * This is a callback from harfbuzz. The font engine uses the font-system in use to find out the      * advances of each glyph and set it on the layout.      */
name|virtual
name|void
name|recalcAdvances
argument_list|(
argument|QGlyphLayout *
argument_list|,
argument|QTextEngine::ShaperFlags
argument_list|)
specifier|const
block|{}
name|virtual
name|void
name|doKerning
argument_list|(
argument|QGlyphLayout *
argument_list|,
argument|QTextEngine::ShaperFlags
argument_list|)
specifier|const
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_WS_QPA
argument_list|)
name|virtual
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
operator|=
literal|0
block|;
endif|#
directive|endif
name|virtual
name|void
name|addGlyphsToPath
argument_list|(
argument|glyph_t *glyphs
argument_list|,
argument|QFixedPoint *positions
argument_list|,
argument|int nglyphs
argument_list|,
argument|QPainterPath *path
argument_list|,
argument|QTextItem::RenderFlags flags
argument_list|)
block|;
name|void
name|getGlyphPositions
argument_list|(
argument|const QGlyphLayout&glyphs
argument_list|,
argument|const QTransform&matrix
argument_list|,
argument|QTextItem::RenderFlags flags
argument_list|,
argument|QVarLengthArray<glyph_t>&glyphs_out
argument_list|,
argument|QVarLengthArray<QFixedPoint>&positions
argument_list|)
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
name|void
name|addBitmapFontToPath
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|const QGlyphLayout&
argument_list|,
argument|QPainterPath *
argument_list|,
argument|QTextItem::RenderFlags
argument_list|)
block|;
comment|/**      * Create a qimage with the alpha values for the glyph.      * Returns an image indexed_8 with index values ranging from 0=fully transparent to 255=opaque      */
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
argument|int margin
argument_list|,
argument|const QTransform&t
argument_list|)
block|;
name|virtual
name|glyph_metrics_t
name|alphaMapBoundingBox
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|QFixed
comment|/*subPixelPosition*/
argument_list|,
argument|const QTransform&matrix
argument_list|,
argument|GlyphFormat
comment|/*format*/
argument_list|)
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
argument_list|(
name|glyph_t
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
operator|=
literal|0
block|;
name|virtual
name|glyph_metrics_t
name|boundingBox
argument_list|(
argument|glyph_t glyph
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|glyph_metrics_t
name|boundingBox
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|const QTransform&matrix
argument_list|)
block|;
name|glyph_metrics_t
name|tightBoundingBox
argument_list|(
specifier|const
name|QGlyphLayout
operator|&
name|glyphs
argument_list|)
block|;
name|virtual
name|QFixed
name|ascent
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QFixed
name|descent
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QFixed
name|leading
argument_list|()
specifier|const
operator|=
literal|0
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
operator|=
literal|0
block|;
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
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|canRender
argument_list|(
argument|const QChar *string
argument_list|,
argument|int len
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|Type
name|type
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|int
name|glyphCount
argument_list|()
specifier|const
block|;
name|virtual
name|QFontEngine
operator|*
name|cloneWithSize
argument_list|(
argument|qreal
comment|/*pixelSize*/
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|HB_Font
name|harfbuzzFont
argument_list|()
specifier|const
block|;
name|HB_Face
name|harfbuzzFace
argument_list|()
specifier|const
block|;
name|virtual
name|HB_Error
name|getPointInOutline
argument_list|(
argument|HB_Glyph glyph
argument_list|,
argument|int flags
argument_list|,
argument|hb_uint32 point
argument_list|,
argument|HB_Fixed *xpos
argument_list|,
argument|HB_Fixed *ypos
argument_list|,
argument|hb_uint32 *nPoints
argument_list|)
block|;
name|void
name|setGlyphCache
argument_list|(
name|void
operator|*
name|key
argument_list|,
name|QFontEngineGlyphCache
operator|*
name|data
argument_list|)
block|;
name|QFontEngineGlyphCache
operator|*
name|glyphCache
argument_list|(
argument|void *key
argument_list|,
argument|QFontEngineGlyphCache::Type type
argument_list|,
argument|const QTransform&transform
argument_list|)
specifier|const
block|;
specifier|static
specifier|const
name|uchar
operator|*
name|getCMap
argument_list|(
argument|const uchar *table
argument_list|,
argument|uint tableSize
argument_list|,
argument|bool *isSymbolFont
argument_list|,
argument|int *cmapSize
argument_list|)
block|;
specifier|static
name|quint32
name|getTrueTypeGlyphIndex
argument_list|(
argument|const uchar *cmap
argument_list|,
argument|uint unicode
argument_list|)
block|;
specifier|static
name|QByteArray
name|convertToPostscriptFontFamilyName
argument_list|(
specifier|const
name|QByteArray
operator|&
name|fontFamily
argument_list|)
block|;      enum
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
block|;
name|virtual
name|void
name|setDefaultHintStyle
argument_list|(
argument|HintStyle
argument_list|)
block|{ }
name|QAtomicInt
name|ref
block|;
name|QFontDef
name|fontDef
block|;
name|uint
name|cache_cost
block|;
comment|// amount of mem used in kb by the font
name|int
name|cache_count
block|;
name|uint
name|fsType
operator|:
literal|16
block|;
name|bool
name|symbol
block|;
name|mutable
name|HB_FontRec
name|hbFont
block|;
name|mutable
name|HB_Face
name|hbFace
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_QWS
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_QPA
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
block|struct
name|KernPair
block|{
name|uint
name|left_right
block|;
name|QFixed
name|adjust
block|;
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
expr|}
block|;
name|QVector
operator|<
name|KernPair
operator|>
name|kerning_pairs
block|;
name|void
name|loadKerningPairs
argument_list|(
argument|QFixed scalingFactor
argument_list|)
block|;
endif|#
directive|endif
name|int
name|glyphFormat
block|;
name|protected
operator|:
specifier|static
specifier|const
name|QVector
operator|<
name|QRgb
operator|>
operator|&
name|grayPalette
argument_list|()
block|;
name|QFixed
name|lastRightBearing
argument_list|(
argument|const QGlyphLayout&glyphs
argument_list|,
argument|bool round = false
argument_list|)
block|;
name|private
operator|:
expr|struct
name|GlyphCacheEntry
block|{
name|void
operator|*
name|context
block|;
name|QExplicitlySharedDataPointer
operator|<
name|QFontEngineGlyphCache
operator|>
name|cache
block|;
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
expr|}
block|;
name|mutable
name|QLinkedList
operator|<
name|GlyphCacheEntry
operator|>
name|m_glyphCaches
block|; }
block|;
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
expr|,
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
DECL|function|qHash
specifier|inline
name|uint
name|qHash
argument_list|(
argument|const QFontEngine::FaceId&f
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
DECL|variable|QGlyph
name|class
name|QGlyph
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_QWS
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_QWS_QPF
DECL|variable|QFontEngineQPF1Data
name|class
name|QFontEngineQPF1Data
block|;
name|class
name|QFontEngineQPF1
operator|:
name|public
name|QFontEngine
block|{
name|public
operator|:
name|QFontEngineQPF1
argument_list|(
specifier|const
name|QFontDef
operator|&
argument_list|,
specifier|const
name|QString
operator|&
name|fn
argument_list|)
block|;
operator|~
name|QFontEngineQPF1
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
argument|QTextEngine::ShaperFlags flags
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|recalcAdvances
argument_list|(
argument|QGlyphLayout *
argument_list|,
argument|QTextEngine::ShaperFlags
argument_list|)
specifier|const
block|;
name|virtual
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
block|;
name|virtual
name|qreal
name|minRightBearing
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
name|QFixed
name|lineThickness
argument_list|()
specifier|const
block|;
name|virtual
name|Type
name|type
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
specifier|inline
specifier|const
name|char
operator|*
name|name
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
name|QFontEngineQPF1Data
operator|*
name|d
block|; }
block|;
endif|#
directive|endif
comment|// QT_NO_QWS_QPF
endif|#
directive|endif
comment|// QWS
name|class
name|QFontEngineBox
operator|:
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
argument|QTextEngine::ShaperFlags flags
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|recalcAdvances
argument_list|(
argument|QGlyphLayout *
argument_list|,
argument|QTextEngine::ShaperFlags
argument_list|)
specifier|const
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
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
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|Q_WS_X11
name|int
name|cmap
argument_list|()
specifier|const
block|;
endif|#
directive|endif
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
block|;
name|class
name|Q_GUI_EXPORT
name|QFontEngineMulti
operator|:
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
argument|QTextEngine::ShaperFlags flags
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
argument|QTextEngine::ShaperFlags
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|doKerning
argument_list|(
argument|QGlyphLayout *
argument_list|,
argument|QTextEngine::ShaperFlags
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
argument|int margin
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
name|protected
operator|:
name|friend
name|class
name|QPSPrintEnginePrivate
block|;
name|friend
name|class
name|QPSPrintEngineFontMulti
block|;
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
name|QVector
operator|<
name|QFontEngine
operator|*
operator|>
name|engines
block|; }
block|;
name|class
name|QTestFontEngine
operator|:
name|public
name|QFontEngineBox
block|{
name|public
operator|:
name|QTestFontEngine
argument_list|(
argument|int size
argument_list|)
operator|:
name|QFontEngineBox
argument_list|(
argument|size
argument_list|)
block|{}
name|virtual
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|TestFontEngine
return|;
block|}
expr|}
block|;
name|QT_END_NAMESPACE
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WIN
end_ifdef
begin_include
include|#
directive|include
file|"private/qfontengine_win_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_FREETYPE
argument_list|)
end_if
begin_include
include|#
directive|include
file|"private/qfontengine_ft_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFONTENGINE_P_H
end_comment
end_unit
