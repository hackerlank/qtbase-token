begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenVG module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QVGFONTGLYPHCACHE_H
end_ifndef
begin_define
DECL|macro|QVGFONTGLYPHCACHE_H
define|#
directive|define
name|QVGFONTGLYPHCACHE_H
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
file|<QtCore/qvarlengtharray.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qfontengine_p.h>
end_include
begin_include
include|#
directive|include
file|"qvg_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QVGPaintEnginePrivate
name|class
name|QVGPaintEnginePrivate
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QVG_NO_DRAW_GLYPHS
end_ifndef
begin_decl_stmt
name|class
name|QVGFontGlyphCache
block|{
name|public
label|:
name|QVGFontGlyphCache
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QVGFontGlyphCache
argument_list|()
expr_stmt|;
name|virtual
name|void
name|cacheGlyphs
parameter_list|(
name|QVGPaintEnginePrivate
modifier|*
name|d
parameter_list|,
name|QFontEngine
modifier|*
name|fontEngine
parameter_list|,
specifier|const
name|glyph_t
modifier|*
name|g
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
name|void
name|setScaleFromText
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|,
name|QFontEngine
modifier|*
name|fontEngine
parameter_list|)
function_decl|;
name|VGFont
name|font
decl_stmt|;
name|VGfloat
name|scaleX
decl_stmt|;
name|VGfloat
name|scaleY
decl_stmt|;
name|bool
name|invertedGlyphs
decl_stmt|;
name|uint
name|cachedGlyphsMask
index|[
literal|256
operator|/
literal|32
index|]
decl_stmt|;
name|QSet
operator|<
name|glyph_t
operator|>
name|cachedGlyphs
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
end_if
begin_decl_stmt
name|class
name|QSymbianVGFontGlyphCache
range|:
name|public
name|QVGFontGlyphCache
block|{
name|public
operator|:
name|QSymbianVGFontGlyphCache
argument_list|()
block|;
name|void
name|cacheGlyphs
argument_list|(
argument|QVGPaintEnginePrivate *d
argument_list|,
argument|QFontEngine *fontEngine
argument_list|,
argument|const glyph_t *g
argument_list|,
argument|int count
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
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
comment|// QVGFONTGLYPHCACHE_H
end_comment
end_unit
