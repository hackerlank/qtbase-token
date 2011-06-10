begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
end_if
begin_include
include|#
directive|include
file|<private/qt_x11_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FONTCONFIG
end_ifndef
begin_include
include|#
directive|include
file|<fontconfig/fontconfig.h>
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
begin_include
include|#
directive|include
file|"private/qharfbuzz_copy_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFontEngineFTRawFont
name|class
name|QFontEngineFTRawFont
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*  * This struct represents one font file on disk (like Arial.ttf) and is shared between all the font engines  * that show this font file (at different pixel sizes).  */
end_comment
begin_struct
DECL|struct|QFreetypeFace
struct|struct
name|QFreetypeFace
block|{
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
DECL|function|lock
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
DECL|function|unlock
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
DECL|member|face
name|FT_Face
name|face
decl_stmt|;
DECL|member|hbFace
name|HB_Face
name|hbFace
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_FONTCONFIG
DECL|member|charset
name|FcCharSet
modifier|*
name|charset
decl_stmt|;
endif|#
directive|endif
DECL|member|xsize
name|int
name|xsize
decl_stmt|;
comment|// 26.6
DECL|member|ysize
name|int
name|ysize
decl_stmt|;
comment|// 26.6
DECL|member|matrix
name|FT_Matrix
name|matrix
decl_stmt|;
DECL|member|unicode_map
name|FT_CharMap
name|unicode_map
decl_stmt|;
DECL|member|symbol_map
name|FT_CharMap
name|symbol_map
decl_stmt|;
DECL|enumerator|cmapCacheSize
enum|enum
block|{
name|cmapCacheSize
init|=
literal|0x200
block|}
enum|;
DECL|member|cmapCache
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
name|HB_Error
name|getPointInOutline
parameter_list|(
name|HB_Glyph
name|glyph
parameter_list|,
name|int
name|flags
parameter_list|,
name|hb_uint32
name|point
parameter_list|,
name|HB_Fixed
modifier|*
name|xpos
parameter_list|,
name|HB_Fixed
modifier|*
name|ypos
parameter_list|,
name|hb_uint32
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
parameter_list|,
name|bool
init|=
name|false
parameter_list|)
function_decl|;
DECL|member|private
name|private
label|:
name|friend
name|class
name|QFontEngineFT
decl_stmt|;
DECL|member|QFreetypeFace
name|friend
name|class
name|QScopedPointerDeleter
operator|<
name|QFreetypeFace
operator|>
expr_stmt|;
DECL|function|QFreetypeFace
name|QFreetypeFace
argument_list|()
operator|:
name|_lock
argument_list|(
argument|QMutex::Recursive
argument_list|)
block|{}
DECL|function|~QFreetypeFace
operator|~
name|QFreetypeFace
argument_list|()
block|{}
DECL|member|ref
name|QAtomicInt
name|ref
expr_stmt|;
DECL|member|_lock
name|QMutex
name|_lock
decl_stmt|;
DECL|member|fontData
name|QByteArray
name|fontData
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QFontEngineFT
range|:
name|public
name|QFontEngine
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
block|;
name|unsigned
name|int
name|uploadedToServer
operator|:
literal|1
block|;     }
block|;      enum
name|SubpixelAntialiasingType
block|{
name|Subpixel_None
block|,
name|Subpixel_RGB
block|,
name|Subpixel_BGR
block|,
name|Subpixel_VRGB
block|,
name|Subpixel_VBGR
block|}
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_XRENDER
argument_list|)
typedef|typedef
name|XGlyphInfo
name|GlyphInfo
typedef|;
else|#
directive|else
block|struct
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
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_struct
struct|struct
name|GlyphAndSubPixelPosition
block|{
name|GlyphAndSubPixelPosition
argument_list|(
argument|glyph_t g
argument_list|,
argument|QFixed spp
argument_list|)
block|:
name|glyph
argument_list|(
name|g
argument_list|)
operator|,
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
decl_stmt|;
name|QFixed
name|subPixelPosition
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
struct|struct
name|QGlyphSet
block|{
name|QGlyphSet
argument_list|()
expr_stmt|;
operator|~
name|QGlyphSet
argument_list|()
expr_stmt|;
name|FT_Matrix
name|transformationMatrix
decl_stmt|;
name|unsigned
name|long
name|id
decl_stmt|;
comment|// server sided id, GlyphSet for X11
name|bool
name|outline_drawing
decl_stmt|;
name|void
name|removeGlyphFromCache
parameter_list|(
name|glyph_t
name|index
parameter_list|,
name|QFixed
name|subPixelPosition
parameter_list|)
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
specifier|inline
name|bool
name|useFastGlyphData
argument_list|(
name|glyph_t
name|index
argument_list|,
name|QFixed
name|subPixelPosition
argument_list|)
decl|const
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
modifier|*
name|getGlyph
argument_list|(
name|glyph_t
name|index
argument_list|,
name|QFixed
name|subPixelPosition
operator|=
literal|0
argument_list|)
decl|const
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
block|}
name|void
name|setGlyph
parameter_list|(
name|glyph_t
name|index
parameter_list|,
name|QFixed
name|spp
parameter_list|,
name|Glyph
modifier|*
name|glyph
parameter_list|)
function_decl|;
name|private
label|:
name|mutable
name|QHash
operator|<
name|GlyphAndSubPixelPosition
operator|,
name|Glyph
operator|*
operator|>
name|glyph_data
expr_stmt|;
comment|// maps from glyph index to glyph data
name|mutable
name|Glyph
modifier|*
name|fast_glyph_data
index|[
literal|256
index|]
decl_stmt|;
comment|// for fast lookup of glyphs< 256
name|mutable
name|int
name|fast_glyph_count
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|virtual
name|QFontEngine
operator|::
name|FaceId
name|faceId
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|QFontEngine
operator|::
name|Properties
name|properties
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|QFixed
name|emSquareSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|bool
name|supportsSubPixelPositions
argument_list|()
specifier|const
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
end_expr_stmt
begin_decl_stmt
name|virtual
name|bool
name|getSfntTableData
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
end_decl_stmt
begin_expr_stmt
name|virtual
name|int
name|synthesized
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|QFixed
name|ascent
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|QFixed
name|descent
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|QFixed
name|leading
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|QFixed
name|xHeight
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|QFixed
name|averageCharWidth
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|qreal
name|maxCharWidth
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|qreal
name|minLeftBearing
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|qreal
name|minRightBearing
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|QFixed
name|lineThickness
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|QFixed
name|underlinePosition
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|void
name|doKerning
argument_list|(
name|QGlyphLayout
operator|*
argument_list|,
name|QTextEngine
operator|::
name|ShaperFlags
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|inline
name|virtual
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|QFontEngine
operator|::
name|Freetype
return|;
block|}
end_expr_stmt
begin_expr_stmt
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
literal|"freetype"
return|;
block|}
end_expr_stmt
begin_function_decl
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
end_function_decl
begin_function_decl
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
function_decl|;
end_function_decl
begin_decl_stmt
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
end_decl_stmt
begin_decl_stmt
name|virtual
name|void
name|addOutlineToPath
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
name|glyphs
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
end_decl_stmt
begin_decl_stmt
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
name|QTextEngine
operator|::
name|ShaperFlags
name|flags
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|virtual
name|glyph_metrics_t
name|boundingBox
parameter_list|(
specifier|const
name|QGlyphLayout
modifier|&
name|glyphs
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|glyph_metrics_t
name|boundingBox
parameter_list|(
name|glyph_t
name|glyph
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
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
end_function_decl
begin_decl_stmt
name|virtual
name|void
name|recalcAdvances
argument_list|(
name|QGlyphLayout
operator|*
name|glyphs
argument_list|,
name|QTextEngine
operator|::
name|ShaperFlags
name|flags
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function
name|virtual
name|QImage
name|alphaMapForGlyph
parameter_list|(
name|glyph_t
name|g
parameter_list|)
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
end_function
begin_function_decl
name|virtual
name|QImage
name|alphaMapForGlyph
parameter_list|(
name|glyph_t
parameter_list|,
name|QFixed
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|QImage
name|alphaRGBMapForGlyph
parameter_list|(
name|glyph_t
parameter_list|,
name|QFixed
name|subPixelPosition
parameter_list|,
name|int
name|margin
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|t
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|virtual
name|glyph_metrics_t
name|alphaMapBoundingBox
argument_list|(
name|glyph_t
name|glyph
argument_list|,
name|QFixed
name|subPixelPosition
argument_list|,
specifier|const
name|QTransform
operator|&
name|matrix
argument_list|,
name|QFontEngine
operator|::
name|GlyphFormat
name|format
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|virtual
name|void
name|removeGlyphFromCache
parameter_list|(
name|glyph_t
name|glyph
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|virtual
name|int
name|glyphCount
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_enum
enum|enum
name|Scaling
block|{
name|Scaled
block|,
name|Unscaled
block|}
enum|;
end_enum
begin_decl_stmt
name|FT_Face
name|lockFace
argument_list|(
name|Scaling
name|scale
operator|=
name|Scaled
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|void
name|unlockFace
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|FT_Face
name|non_locked_face
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
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
end_expr_stmt
begin_expr_stmt
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
end_expr_stmt
begin_expr_stmt
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
end_expr_stmt
begin_decl_stmt
specifier|inline
name|Glyph
modifier|*
name|loadGlyph
argument_list|(
name|uint
name|glyph
argument_list|,
name|QFixed
name|subPixelPosition
argument_list|,
name|GlyphFormat
name|format
operator|=
name|Format_None
argument_list|,
name|bool
name|fetchMetricsOnly
operator|=
name|false
argument_list|)
decl|const
block|{
return|return
name|loadGlyph
argument_list|(
operator|&
name|defaultGlyphSet
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
end_decl_stmt
begin_decl_stmt
name|Glyph
modifier|*
name|loadGlyph
argument_list|(
name|QGlyphSet
operator|*
name|set
argument_list|,
name|uint
name|glyph
argument_list|,
name|QFixed
name|subPixelPosition
argument_list|,
name|GlyphFormat
operator|=
name|Format_None
argument_list|,
name|bool
name|fetchMetricsOnly
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function
name|QGlyphSet
modifier|*
name|defaultGlyphs
parameter_list|()
block|{
return|return
operator|&
name|defaultGlyphSet
return|;
block|}
end_function
begin_expr_stmt
name|GlyphFormat
name|defaultGlyphFormat
argument_list|()
specifier|const
block|{
return|return
name|defaultFormat
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|inline
name|Glyph
modifier|*
name|cachedGlyph
argument_list|(
name|glyph_t
name|g
argument_list|)
decl|const
block|{
return|return
name|defaultGlyphSet
operator|.
name|getGlyph
argument_list|(
name|g
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_decl_stmt
begin_function_decl
name|QGlyphSet
modifier|*
name|loadTransformedGlyphSet
parameter_list|(
specifier|const
name|QTransform
modifier|&
name|matrix
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QFixed
name|subPixelPositionForX
parameter_list|(
name|QFixed
name|x
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|loadGlyphs
parameter_list|(
name|QGlyphSet
modifier|*
name|gs
parameter_list|,
specifier|const
name|glyph_t
modifier|*
name|glyphs
parameter_list|,
name|int
name|num_glyphs
parameter_list|,
specifier|const
name|QFixedPoint
modifier|*
name|positions
parameter_list|,
name|GlyphFormat
name|format
init|=
name|Format_Render
parameter_list|)
function_decl|;
end_function_decl
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_QWS
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
end_if
begin_function
name|virtual
name|void
name|draw
parameter_list|(
name|QPaintEngine
modifier|*
comment|/*p*/
parameter_list|,
name|qreal
comment|/*x*/
parameter_list|,
name|qreal
comment|/*y*/
parameter_list|,
specifier|const
name|QTextItemInt
modifier|&
comment|/*si*/
parameter_list|)
block|{}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QFontEngineFT
argument_list|(
specifier|const
name|QFontDef
operator|&
name|fd
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
operator|~
name|QFontEngineFT
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|bool
name|init
parameter_list|(
name|FaceId
name|faceId
parameter_list|,
name|bool
name|antiaalias
parameter_list|,
name|GlyphFormat
name|defaultFormat
init|=
name|Format_None
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|fontData
init|=
name|QByteArray
argument_list|()
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|init
parameter_list|(
name|FaceId
name|faceId
parameter_list|,
name|bool
name|antialias
parameter_list|,
name|GlyphFormat
name|format
parameter_list|,
name|QFreetypeFace
modifier|*
name|freetypeFace
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|HB_Error
name|getPointInOutline
parameter_list|(
name|HB_Glyph
name|glyph
parameter_list|,
name|int
name|flags
parameter_list|,
name|hb_uint32
name|point
parameter_list|,
name|HB_Fixed
modifier|*
name|xpos
parameter_list|,
name|HB_Fixed
modifier|*
name|ypos
parameter_list|,
name|hb_uint32
modifier|*
name|nPoints
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|setDefaultHintStyle
parameter_list|(
name|HintStyle
name|style
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|virtual
name|QFontEngine
modifier|*
name|cloneWithSize
argument_list|(
name|qreal
name|pixelSize
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|bool
name|initFromFontEngine
parameter_list|(
specifier|const
name|QFontEngineFT
modifier|*
name|fontEngine
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|HintStyle
name|defaultHintStyle
argument_list|()
specifier|const
block|{
return|return
name|default_hint_style
return|;
block|}
end_expr_stmt
begin_label
name|protected
label|:
end_label
begin_function_decl
name|void
name|freeGlyphSets
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|virtual
name|bool
name|uploadGlyphToServer
argument_list|(
name|QGlyphSet
operator|*
name|set
argument_list|,
name|uint
name|glyphid
argument_list|,
name|Glyph
operator|*
name|g
argument_list|,
name|GlyphInfo
operator|*
name|info
argument_list|,
name|int
name|glyphDataSize
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|virtual
name|unsigned
name|long
name|allocateServerGlyphSet
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|freeServerGlyphSet
parameter_list|(
name|unsigned
name|long
name|id
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QFreetypeFace
modifier|*
name|freetype
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|default_load_flags
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|HintStyle
name|default_hint_style
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|antialias
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|transform
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|embolden
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|SubpixelAntialiasingType
name|subpixelType
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|lcdFilterType
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|canUploadGlyphsToServer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|embeddedbitmap
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|friend
name|class
name|QFontEngineFTRawFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|loadFlags
argument_list|(
name|QGlyphSet
operator|*
name|set
argument_list|,
name|GlyphFormat
name|format
argument_list|,
name|int
name|flags
argument_list|,
name|bool
operator|&
name|hsubpixel
argument_list|,
name|int
operator|&
name|vfactor
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|GlyphFormat
name|defaultFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|FT_Matrix
name|matrix
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QList
operator|<
name|QGlyphSet
operator|>
name|transformedGlyphSets
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|mutable
name|QGlyphSet
name|defaultGlyphSet
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QFontEngine
operator|::
name|FaceId
name|face_id
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|int
name|xsize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|ysize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|QFixed
name|lbearing
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|QFixed
name|rbearing
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QFixed
name|line_thickness
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QFixed
name|underline_position
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|FT_Size_Metrics
name|metrics
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|bool
name|kerning_pairs_loaded
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
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
