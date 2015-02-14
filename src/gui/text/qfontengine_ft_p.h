begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONTENGINE_FT_P_H
end_ifndef
begin_define
DECL|macro|QFONTENGINE_FT_P_H
define|#
directive|define
name|QFONTENGINE_FT_P_H
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
file|"private/qfontengine_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FREETYPE
end_ifndef
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_FREETYPE_H
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WIN
end_ifndef
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qmutex.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFontEngineFTRawFont
name|class
name|QFontEngineFTRawFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFontconfigDatabase
name|class
name|QFontconfigDatabase
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*  * This class represents one font file on disk (like Arial.ttf) and is shared between all the font engines  * that show this font file (at different pixel sizes).  */
end_comment
begin_decl_stmt
name|class
name|QFreetypeFace
block|{
name|public
label|:
name|void
name|computeSize
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|fontDef
parameter_list|,
name|int
modifier|*
name|xsize
parameter_list|,
name|int
modifier|*
name|ysize
parameter_list|,
name|bool
modifier|*
name|outline_drawing
parameter_list|)
function_decl|;
name|QFontEngine
operator|::
name|Properties
name|properties
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|getSfntTable
argument_list|(
name|uint
name|tag
argument_list|,
name|uchar
operator|*
name|buffer
argument_list|,
name|uint
operator|*
name|length
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QFreetypeFace
modifier|*
name|getFace
argument_list|(
specifier|const
name|QFontEngine
operator|::
name|FaceId
operator|&
name|face_id
argument_list|,
specifier|const
name|QByteArray
operator|&
name|fontData
operator|=
name|QByteArray
argument_list|()
argument_list|)
decl_stmt|;
name|void
name|release
argument_list|(
specifier|const
name|QFontEngine
operator|::
name|FaceId
operator|&
name|face_id
argument_list|)
decl_stmt|;
comment|// locks the struct for usage. Any read/write operations require locking.
name|void
name|lock
parameter_list|()
block|{
name|_lock
operator|.
name|lock
argument_list|()
expr_stmt|;
block|}
name|void
name|unlock
parameter_list|()
block|{
name|_lock
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
name|FT_Face
name|face
decl_stmt|;
name|int
name|xsize
decl_stmt|;
comment|// 26.6
name|int
name|ysize
decl_stmt|;
comment|// 26.6
name|FT_Matrix
name|matrix
decl_stmt|;
name|FT_CharMap
name|unicode_map
decl_stmt|;
name|FT_CharMap
name|symbol_map
decl_stmt|;
enum|enum
block|{
name|cmapCacheSize
init|=
literal|0x200
block|}
enum|;
name|glyph_t
name|cmapCache
index|[
name|cmapCacheSize
index|]
decl_stmt|;
name|int
name|fsType
argument_list|()
specifier|const
expr_stmt|;
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
specifier|static
name|void
name|addGlyphToPath
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_GlyphSlot
name|g
parameter_list|,
specifier|const
name|QFixedPoint
modifier|&
name|point
parameter_list|,
name|QPainterPath
modifier|*
name|path
parameter_list|,
name|FT_Fixed
name|x_scale
parameter_list|,
name|FT_Fixed
name|y_scale
parameter_list|)
function_decl|;
specifier|static
name|void
name|addBitmapToPath
parameter_list|(
name|FT_GlyphSlot
name|slot
parameter_list|,
specifier|const
name|QFixedPoint
modifier|&
name|point
parameter_list|,
name|QPainterPath
modifier|*
name|path
parameter_list|)
function_decl|;
name|private
label|:
name|friend
name|class
name|QFontEngineFT
decl_stmt|;
name|friend
name|class
name|QtFreetypeData
decl_stmt|;
name|friend
block|struct
name|QScopedPointerDeleter
operator|<
name|QFreetypeFace
operator|>
expr_stmt|;
name|QFreetypeFace
argument_list|()
operator|:
name|_lock
argument_list|(
argument|QMutex::Recursive
argument_list|)
block|{}
operator|~
name|QFreetypeFace
argument_list|()
block|{}
name|void
name|cleanup
argument_list|()
expr_stmt|;
name|QAtomicInt
name|ref
decl_stmt|;
name|QMutex
name|_lock
decl_stmt|;
name|QByteArray
name|fontData
decl_stmt|;
name|void
modifier|*
name|hbFace
decl_stmt|;
name|qt_destroy_func_t
name|hbFace_destroy_func
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// If this is exported this breaks compilation of the windows
end_comment
begin_comment
comment|// plugin as qfontengine_ft_p.h/.cpp are also compiled there
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WIN
end_ifndef
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QFontEngineFT
range|:
name|public
name|QFontEngine
else|#
directive|else
name|class
name|QFontEngineFT
operator|:
name|public
name|QFontEngine
endif|#
directive|endif
block|{
name|public
operator|:
comment|/* we don't cache glyphs that are too large anyway, so we can make this struct rather small */
expr|struct
name|Glyph
block|{
operator|~
name|Glyph
argument_list|()
block|;
name|short
name|linearAdvance
block|;
name|unsigned
name|char
name|width
block|;
name|unsigned
name|char
name|height
block|;
name|signed
name|char
name|x
block|;
name|signed
name|char
name|y
block|;
name|signed
name|char
name|advance
block|;
name|signed
name|char
name|format
block|;
name|uchar
operator|*
name|data
block|;     }
block|;      struct
name|GlyphInfo
block|{
name|unsigned
name|short
name|width
block|;
name|unsigned
name|short
name|height
block|;
name|short
name|x
block|;
name|short
name|y
block|;
name|short
name|xOff
block|;
name|short
name|yOff
block|;     }
block|;      struct
name|GlyphAndSubPixelPosition
block|{
name|GlyphAndSubPixelPosition
argument_list|(
argument|glyph_t g
argument_list|,
argument|QFixed spp
argument_list|)
operator|:
name|glyph
argument_list|(
name|g
argument_list|)
block|,
name|subPixelPosition
argument_list|(
argument|spp
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|GlyphAndSubPixelPosition
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|glyph
operator|==
name|other
operator|.
name|glyph
operator|&&
name|subPixelPosition
operator|==
name|other
operator|.
name|subPixelPosition
return|;
block|}
name|glyph_t
name|glyph
block|;
name|QFixed
name|subPixelPosition
block|;     }
block|;      struct
name|QGlyphSet
block|{
name|QGlyphSet
argument_list|()
block|;
operator|~
name|QGlyphSet
argument_list|()
block|;
name|FT_Matrix
name|transformationMatrix
block|;
name|bool
name|outline_drawing
block|;
name|void
name|removeGlyphFromCache
argument_list|(
argument|glyph_t index
argument_list|,
argument|QFixed subPixelPosition
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
specifier|inline
name|bool
name|useFastGlyphData
argument_list|(
argument|glyph_t index
argument_list|,
argument|QFixed subPixelPosition
argument_list|)
specifier|const
block|{
return|return
operator|(
name|index
operator|<
literal|256
operator|&&
name|subPixelPosition
operator|==
literal|0
operator|)
return|;
block|}
specifier|inline
name|Glyph
operator|*
name|getGlyph
argument_list|(
argument|glyph_t index
argument_list|,
argument|QFixed subPixelPosition =
literal|0
argument_list|)
specifier|const
block|;
name|void
name|setGlyph
argument_list|(
argument|glyph_t index
argument_list|,
argument|QFixed spp
argument_list|,
argument|Glyph *glyph
argument_list|)
block|;
specifier|inline
name|bool
name|isGlyphMissing
argument_list|(
argument|glyph_t index
argument_list|)
specifier|const
block|{
return|return
name|missing_glyphs
operator|.
name|contains
argument_list|(
name|index
argument_list|)
return|;
block|}
specifier|inline
name|void
name|setGlyphMissing
argument_list|(
argument|glyph_t index
argument_list|)
specifier|const
block|{
name|missing_glyphs
operator|.
name|insert
argument_list|(
name|index
argument_list|)
block|; }
name|private
operator|:
name|mutable
name|QHash
operator|<
name|GlyphAndSubPixelPosition
block|,
name|Glyph
operator|*
operator|>
name|glyph_data
block|;
comment|// maps from glyph index to glyph data
name|mutable
name|QSet
operator|<
name|glyph_t
operator|>
name|missing_glyphs
block|;
name|mutable
name|Glyph
operator|*
name|fast_glyph_data
index|[
literal|256
index|]
block|;
comment|// for fast lookup of glyphs< 256
name|mutable
name|int
name|fast_glyph_count
block|;     }
block|;
name|virtual
name|QFontEngine
operator|::
name|FaceId
name|faceId
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QFontEngine
operator|::
name|Properties
name|properties
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QFixed
name|emSquareSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|supportsSubPixelPositions
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|default_hint_style
operator|==
name|HintLight
operator|||
name|default_hint_style
operator|==
name|HintNone
return|;
block|}
name|virtual
name|bool
name|getSfntTableData
argument_list|(
argument|uint tag
argument_list|,
argument|uchar *buffer
argument_list|,
argument|uint *length
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|int
name|synthesized
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QFixed
name|ascent
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QFixed
name|descent
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QFixed
name|leading
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QFixed
name|xHeight
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QFixed
name|averageCharWidth
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|qreal
name|maxCharWidth
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|qreal
name|minLeftBearing
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|qreal
name|minRightBearing
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QFixed
name|lineThickness
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QFixed
name|underlinePosition
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|glyph_t
name|glyphIndex
argument_list|(
argument|uint ucs4
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|doKerning
argument_list|(
argument|QGlyphLayout *
argument_list|,
argument|ShaperFlags
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|supportsTransformation
argument_list|(
argument|const QTransform&transform
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|glyph_metrics_t
name|boundingBox
argument_list|(
argument|const QGlyphLayout&glyphs
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|glyph_metrics_t
name|boundingBox
argument_list|(
argument|glyph_t glyph
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|glyph_metrics_t
name|boundingBox
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|const QTransform&matrix
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|recalcAdvances
argument_list|(
argument|QGlyphLayout *glyphs
argument_list|,
argument|ShaperFlags flags
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QImage
name|alphaMapForGlyph
argument_list|(
argument|glyph_t g
argument_list|)
name|Q_DECL_OVERRIDE
block|{
return|return
name|alphaMapForGlyph
argument_list|(
name|g
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|virtual
name|QImage
name|alphaMapForGlyph
argument_list|(
argument|glyph_t
argument_list|,
argument|QFixed
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QImage
name|alphaMapForGlyph
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|QFixed subPixelPosition
argument_list|,
argument|const QTransform&t
argument_list|)
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|glyph_metrics_t
name|alphaMapBoundingBox
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|QFixed subPixelPosition
argument_list|,
argument|const QTransform&matrix
argument_list|,
argument|QFontEngine::GlyphFormat format
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QImage
operator|*
name|lockedAlphaMapForGlyph
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|QFixed subPixelPosition
argument_list|,
argument|GlyphFormat neededFormat
argument_list|,
argument|const QTransform&t
argument_list|,
argument|QPoint *offset
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|hasInternalCaching
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|cacheEnabled
return|;
block|}
name|virtual
name|void
name|unlockAlphaMapForGlyph
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|removeGlyphFromCache
argument_list|(
argument|glyph_t glyph
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|int
name|glyphMargin
argument_list|(
argument|QFontEngine::GlyphFormat
comment|/* format */
argument_list|)
name|Q_DECL_OVERRIDE
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|int
name|glyphCount
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;      enum
name|Scaling
block|{
name|Scaled
block|,
name|Unscaled
block|}
block|;
name|FT_Face
name|lockFace
argument_list|(
argument|Scaling scale = Scaled
argument_list|)
specifier|const
block|;
name|void
name|unlockFace
argument_list|()
specifier|const
block|;
name|FT_Face
name|non_locked_face
argument_list|()
specifier|const
block|;
specifier|inline
name|bool
name|drawAntialiased
argument_list|()
specifier|const
block|{
return|return
name|antialias
return|;
block|}
specifier|inline
name|bool
name|invalid
argument_list|()
specifier|const
block|{
return|return
name|xsize
operator|==
literal|0
operator|&&
name|ysize
operator|==
literal|0
return|;
block|}
specifier|inline
name|bool
name|isBitmapFont
argument_list|()
specifier|const
block|{
return|return
name|defaultFormat
operator|==
name|Format_Mono
return|;
block|}
specifier|inline
name|Glyph
operator|*
name|loadGlyph
argument_list|(
argument|uint glyph
argument_list|,
argument|QFixed subPixelPosition
argument_list|,
argument|GlyphFormat format = Format_None
argument_list|,
argument|bool fetchMetricsOnly = false
argument_list|)
specifier|const
block|{
return|return
name|loadGlyph
argument_list|(
name|cacheEnabled
operator|?
operator|&
name|defaultGlyphSet
operator|:
literal|0
argument_list|,
name|glyph
argument_list|,
name|subPixelPosition
argument_list|,
name|format
argument_list|,
name|fetchMetricsOnly
argument_list|)
return|;
block|}
name|Glyph
operator|*
name|loadGlyph
argument_list|(
argument|QGlyphSet *set
argument_list|,
argument|uint glyph
argument_list|,
argument|QFixed subPixelPosition
argument_list|,
argument|GlyphFormat = Format_None
argument_list|,
argument|bool fetchMetricsOnly = false
argument_list|)
specifier|const
block|;
name|Glyph
operator|*
name|loadGlyphFor
argument_list|(
argument|glyph_t g
argument_list|,
argument|QFixed subPixelPosition
argument_list|,
argument|GlyphFormat format
argument_list|,
argument|const QTransform&t
argument_list|)
block|;
name|QGlyphSet
operator|*
name|loadTransformedGlyphSet
argument_list|(
specifier|const
name|QTransform
operator|&
name|matrix
argument_list|)
block|;
name|QFontEngineFT
argument_list|(
specifier|const
name|QFontDef
operator|&
name|fd
argument_list|)
block|;
name|virtual
operator|~
name|QFontEngineFT
argument_list|()
block|;
name|bool
name|init
argument_list|(
argument|FaceId faceId
argument_list|,
argument|bool antiaalias
argument_list|,
argument|GlyphFormat defaultFormat = Format_None
argument_list|,
argument|const QByteArray&fontData = QByteArray()
argument_list|)
block|;
name|bool
name|init
argument_list|(
argument|FaceId faceId
argument_list|,
argument|bool antialias
argument_list|,
argument|GlyphFormat format
argument_list|,
argument|QFreetypeFace *freetypeFace
argument_list|)
block|;
name|virtual
name|int
name|getPointInOutline
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|int flags
argument_list|,
argument|quint32 point
argument_list|,
argument|QFixed *xpos
argument_list|,
argument|QFixed *ypos
argument_list|,
argument|quint32 *nPoints
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|setDefaultHintStyle
argument_list|(
argument|HintStyle style
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QFontEngine
operator|*
name|cloneWithSize
argument_list|(
argument|qreal pixelSize
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|initFromFontEngine
argument_list|(
specifier|const
name|QFontEngineFT
operator|*
name|fontEngine
argument_list|)
block|;
name|HintStyle
name|defaultHintStyle
argument_list|()
specifier|const
block|{
return|return
name|default_hint_style
return|;
block|}
name|protected
operator|:
name|QFreetypeFace
operator|*
name|freetype
block|;
name|mutable
name|int
name|default_load_flags
block|;
name|HintStyle
name|default_hint_style
block|;
name|bool
name|antialias
block|;
name|bool
name|transform
block|;
name|bool
name|embolden
block|;
name|bool
name|obliquen
block|;
name|SubpixelAntialiasingType
name|subpixelType
block|;
name|int
name|lcdFilterType
block|;
name|bool
name|embeddedbitmap
block|;
name|bool
name|cacheEnabled
block|;
name|bool
name|forceAutoHint
block|;
name|private
operator|:
name|friend
name|class
name|QFontEngineFTRawFont
block|;
name|friend
name|class
name|QFontconfigDatabase
block|;
name|friend
name|class
name|QBasicFontDatabase
block|;
name|friend
name|class
name|QFontEngineMultiFontConfig
block|;
name|int
name|loadFlags
argument_list|(
argument|QGlyphSet *set
argument_list|,
argument|GlyphFormat format
argument_list|,
argument|int flags
argument_list|,
argument|bool&hsubpixel
argument_list|,
argument|int&vfactor
argument_list|)
specifier|const
block|;
name|bool
name|shouldUseDesignMetrics
argument_list|(
argument|ShaperFlags flags
argument_list|)
specifier|const
block|;
name|GlyphFormat
name|defaultFormat
block|;
name|FT_Matrix
name|matrix
block|;
name|QList
operator|<
name|QGlyphSet
operator|>
name|transformedGlyphSets
block|;
name|mutable
name|QGlyphSet
name|defaultGlyphSet
block|;
name|QFontEngine
operator|::
name|FaceId
name|face_id
block|;
name|int
name|xsize
block|;
name|int
name|ysize
block|;
name|mutable
name|QFixed
name|lbearing
block|;
name|mutable
name|QFixed
name|rbearing
block|;
name|QFixed
name|line_thickness
block|;
name|QFixed
name|underline_position
block|;
name|FT_Size_Metrics
name|metrics
block|;
name|mutable
name|bool
name|kerning_pairs_loaded
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|function|qHash
specifier|inline
name|uint
name|qHash
argument_list|(
specifier|const
name|QFontEngineFT
operator|::
name|GlyphAndSubPixelPosition
operator|&
name|g
argument_list|)
block|{
return|return
operator|(
name|g
operator|.
name|glyph
operator|<<
literal|8
operator|)
operator||
operator|(
name|g
operator|.
name|subPixelPosition
operator|*
literal|10
operator|)
operator|.
name|round
argument_list|()
operator|.
name|toInt
argument_list|()
return|;
block|}
end_decl_stmt
begin_expr_stmt
DECL|function|getGlyph
specifier|inline
name|QFontEngineFT
operator|::
name|Glyph
operator|*
name|QFontEngineFT
operator|::
name|QGlyphSet
operator|::
name|getGlyph
argument_list|(
argument|glyph_t index
argument_list|,
argument|QFixed subPixelPosition
argument_list|)
specifier|const
block|{
if|if
condition|(
name|useFastGlyphData
argument_list|(
name|index
argument_list|,
name|subPixelPosition
argument_list|)
condition|)
return|return
name|fast_glyph_data
index|[
name|index
index|]
return|;
end_expr_stmt
begin_return
return|return
name|glyph_data
operator|.
name|value
argument_list|(
name|GlyphAndSubPixelPosition
argument_list|(
name|index
argument_list|,
name|subPixelPosition
argument_list|)
argument_list|)
return|;
end_return
begin_function_decl
unit|}  extern
name|FT_Library
name|qt_getFreetype
parameter_list|()
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FREETYPE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFONTENGINE_FT_P_H
end_comment
end_unit
