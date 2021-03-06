begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTUREGLYPHCACHE_P_H
end_ifndef
begin_define
DECL|macro|QTEXTUREGLYPHCACHE_P_H
define|#
directive|define
name|QTEXTUREGLYPHCACHE_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
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
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<qimage.h>
end_include
begin_include
include|#
directive|include
file|<qobject.h>
end_include
begin_include
include|#
directive|include
file|<qtransform.h>
end_include
begin_include
include|#
directive|include
file|<private/qfontengineglyphcache_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_DEFAULT_TEXTURE_GLYPH_CACHE_WIDTH
end_ifndef
begin_define
DECL|macro|QT_DEFAULT_TEXTURE_GLYPH_CACHE_WIDTH
define|#
directive|define
name|QT_DEFAULT_TEXTURE_GLYPH_CACHE_WIDTH
value|256
end_define
begin_endif
endif|#
directive|endif
end_endif
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
DECL|variable|QTextItemInt
name|class
name|QTextItemInt
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QTextureGlyphCache
range|:
name|public
name|QFontEngineGlyphCache
block|{
name|public
operator|:
name|QTextureGlyphCache
argument_list|(
argument|QFontEngine::GlyphFormat format
argument_list|,
argument|const QTransform&matrix
argument_list|)
operator|:
name|QFontEngineGlyphCache
argument_list|(
name|format
argument_list|,
name|matrix
argument_list|)
block|,
name|m_current_fontengine
argument_list|(
literal|0
argument_list|)
block|,
name|m_w
argument_list|(
literal|0
argument_list|)
block|,
name|m_h
argument_list|(
literal|0
argument_list|)
block|,
name|m_cx
argument_list|(
literal|0
argument_list|)
block|,
name|m_cy
argument_list|(
literal|0
argument_list|)
block|,
name|m_currentRowHeight
argument_list|(
literal|0
argument_list|)
block|{ }
operator|~
name|QTextureGlyphCache
argument_list|()
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
name|Coord
block|{
name|int
name|x
block|;
name|int
name|y
block|;
name|int
name|w
block|;
name|int
name|h
block|;
name|int
name|baseLineX
block|;
name|int
name|baseLineY
block|;
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|w
operator|==
literal|0
operator|||
name|h
operator|==
literal|0
return|;
block|}
expr|}
block|;
name|bool
name|populate
argument_list|(
argument|QFontEngine *fontEngine
argument_list|,
argument|int numGlyphs
argument_list|,
argument|const glyph_t *glyphs
argument_list|,
argument|const QFixedPoint *positions
argument_list|)
block|;
name|bool
name|hasPendingGlyphs
argument_list|()
specifier|const
block|{
return|return
operator|!
name|m_pendingGlyphs
operator|.
name|isEmpty
argument_list|()
return|;
block|}
block|;
name|void
name|fillInPendingGlyphs
argument_list|()
block|;
name|virtual
name|void
name|createTextureData
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|resizeTextureData
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|glyphPadding
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|void
name|fillTexture
argument_list|(
argument|const Coord&coord
argument_list|,
argument|glyph_t glyph
argument_list|,
argument|QFixed subPixelPosition
argument_list|)
operator|=
literal|0
block|;
specifier|inline
name|void
name|createCache
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
block|{
name|m_w
operator|=
name|width
block|;
name|m_h
operator|=
name|height
block|;
name|createTextureData
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
block|;     }
specifier|inline
name|void
name|resizeCache
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
block|{
name|resizeTextureData
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
block|;
name|m_w
operator|=
name|width
block|;
name|m_h
operator|=
name|height
block|;     }
specifier|inline
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|m_h
operator|==
literal|0
return|;
block|}
name|QHash
operator|<
name|GlyphAndSubPixelPosition
block|,
name|Coord
operator|>
name|coords
block|;
name|virtual
name|int
name|maxTextureWidth
argument_list|()
specifier|const
block|{
return|return
name|QT_DEFAULT_TEXTURE_GLYPH_CACHE_WIDTH
return|;
block|}
name|virtual
name|int
name|maxTextureHeight
argument_list|()
specifier|const
block|{
return|return
operator|-
literal|1
return|;
block|}
name|QImage
name|textureMapForGlyph
argument_list|(
argument|glyph_t g
argument_list|,
argument|QFixed subPixelPosition
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|int
name|calculateSubPixelPositionCount
argument_list|(
argument|glyph_t
argument_list|)
specifier|const
block|;
name|QFontEngine
operator|*
name|m_current_fontengine
block|;
name|QHash
operator|<
name|GlyphAndSubPixelPosition
block|,
name|Coord
operator|>
name|m_pendingGlyphs
block|;
name|int
name|m_w
block|;
comment|// image width
name|int
name|m_h
block|;
comment|// image height
name|int
name|m_cx
block|;
comment|// current x
name|int
name|m_cy
block|;
comment|// current y
name|int
name|m_currentRowHeight
block|;
comment|// Height of last row
block|}
block|;
DECL|function|qHash
specifier|inline
name|uint
name|qHash
argument_list|(
argument|const QTextureGlyphCache::GlyphAndSubPixelPosition&g
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
name|class
name|Q_GUI_EXPORT
name|QImageTextureGlyphCache
operator|:
name|public
name|QTextureGlyphCache
block|{
name|public
operator|:
name|QImageTextureGlyphCache
argument_list|(
argument|QFontEngine::GlyphFormat format
argument_list|,
argument|const QTransform&matrix
argument_list|)
operator|:
name|QTextureGlyphCache
argument_list|(
argument|format
argument_list|,
argument|matrix
argument_list|)
block|{ }
operator|~
name|QImageTextureGlyphCache
argument_list|()
block|;
name|virtual
name|void
name|createTextureData
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|resizeTextureData
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|fillTexture
argument_list|(
argument|const Coord&c
argument_list|,
argument|glyph_t glyph
argument_list|,
argument|QFixed subPixelPosition
argument_list|)
name|Q_DECL_OVERRIDE
block|;
specifier|inline
specifier|const
name|QImage
operator|&
name|image
argument_list|()
specifier|const
block|{
return|return
name|m_image
return|;
block|}
name|private
operator|:
name|QImage
name|m_image
block|; }
block|;
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
