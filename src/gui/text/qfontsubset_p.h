begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|explicit
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
ifndef|#
directive|ifndef
name|QT_NO_PDF
name|addGlyph
argument_list|(
literal|0
argument_list|)
block|;
endif|#
directive|endif
block|}
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
ifndef|#
directive|ifndef
name|QT_NO_PDF
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
operator|&
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
endif|#
directive|endif
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
name|QVector
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
