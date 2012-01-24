begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONTSUBSET_P_H
end_ifndef
begin_define
DECL|macro|QFONTSUBSET_P_H
define|#
directive|define
name|QFONTSUBSET_P_H
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QFontSubset
block|{
name|public
label|:
name|QFontSubset
argument_list|(
argument|QFontEngine *fe
argument_list|,
argument|int obj_id =
literal|0
argument_list|)
block|:
name|object_id
argument_list|(
name|obj_id
argument_list|)
operator|,
name|noEmbed
argument_list|(
name|false
argument_list|)
operator|,
name|fontEngine
argument_list|(
name|fe
argument_list|)
operator|,
name|downloaded_glyphs
argument_list|(
literal|0
argument_list|)
operator|,
name|standard_font
argument_list|(
argument|false
argument_list|)
block|{
name|fontEngine
operator|->
name|ref
operator|.
name|ref
argument_list|()
block|;
name|addGlyph
argument_list|(
literal|0
argument_list|)
block|; }
operator|~
name|QFontSubset
argument_list|()
block|{
if|if
condition|(
operator|!
name|fontEngine
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|delete
name|fontEngine
decl_stmt|;
block|}
name|QByteArray
name|toTruetype
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|widthArray
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|createToUnicodeMap
argument_list|()
specifier|const
expr_stmt|;
name|QVector
operator|<
name|int
operator|>
name|getReverseMap
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|glyphName
argument_list|(
name|unsigned
name|int
name|glyph
argument_list|,
specifier|const
name|QVector
operator|<
name|int
operator|>
name|reverseMap
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QByteArray
name|glyphName
parameter_list|(
name|unsigned
name|short
name|unicode
parameter_list|,
name|bool
name|symbol
parameter_list|)
function_decl|;
name|int
name|addGlyph
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
specifier|const
name|int
name|object_id
decl_stmt|;
name|bool
name|noEmbed
decl_stmt|;
name|QFontEngine
modifier|*
name|fontEngine
decl_stmt|;
name|QList
operator|<
name|int
operator|>
name|glyph_indices
expr_stmt|;
name|mutable
name|int
name|downloaded_glyphs
decl_stmt|;
name|mutable
name|bool
name|standard_font
decl_stmt|;
name|int
name|nGlyphs
argument_list|()
specifier|const
block|{
return|return
name|glyph_indices
operator|.
name|size
argument_list|()
return|;
block|}
name|mutable
name|QFixed
name|emSquare
decl_stmt|;
name|mutable
name|QVector
operator|<
name|QFixed
operator|>
name|widths
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFONTSUBSET_P_H
end_comment
end_unit
