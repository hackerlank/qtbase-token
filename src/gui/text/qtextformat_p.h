begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTFORMAT_P_H
end_ifndef
begin_define
DECL|macro|QTEXTFORMAT_P_H
define|#
directive|define
name|QTEXTFORMAT_P_H
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
file|"QtGui/qtextformat.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvector.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_GUI_EXPORT
name|QTextFormatCollection
block|{
name|public
label|:
name|QTextFormatCollection
argument_list|()
block|{}
operator|~
name|QTextFormatCollection
argument_list|()
expr_stmt|;
name|QTextFormatCollection
argument_list|(
specifier|const
name|QTextFormatCollection
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|QTextFormatCollection
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QTextFormatCollection
operator|&
name|rhs
operator|)
decl_stmt|;
specifier|inline
name|QTextFormat
name|objectFormat
argument_list|(
name|int
name|objectIndex
argument_list|)
decl|const
block|{
return|return
name|format
argument_list|(
name|objectFormatIndex
argument_list|(
name|objectIndex
argument_list|)
argument_list|)
return|;
block|}
specifier|inline
name|void
name|setObjectFormat
parameter_list|(
name|int
name|objectIndex
parameter_list|,
specifier|const
name|QTextFormat
modifier|&
name|format
parameter_list|)
block|{
name|setObjectFormatIndex
argument_list|(
name|objectIndex
argument_list|,
name|indexForFormat
argument_list|(
name|format
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|int
name|objectFormatIndex
argument_list|(
name|int
name|objectIndex
argument_list|)
decl|const
decl_stmt|;
name|void
name|setObjectFormatIndex
parameter_list|(
name|int
name|objectIndex
parameter_list|,
name|int
name|formatIndex
parameter_list|)
function_decl|;
name|int
name|createObjectIndex
parameter_list|(
specifier|const
name|QTextFormat
modifier|&
name|f
parameter_list|)
function_decl|;
name|int
name|indexForFormat
parameter_list|(
specifier|const
name|QTextFormat
modifier|&
name|f
parameter_list|)
function_decl|;
name|bool
name|hasFormatCached
argument_list|(
specifier|const
name|QTextFormat
operator|&
name|format
argument_list|)
decl|const
decl_stmt|;
name|QTextFormat
name|format
argument_list|(
name|int
name|idx
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|QTextBlockFormat
name|blockFormat
argument_list|(
name|int
name|index
argument_list|)
decl|const
block|{
return|return
name|format
argument_list|(
name|index
argument_list|)
operator|.
name|toBlockFormat
argument_list|()
return|;
block|}
specifier|inline
name|QTextCharFormat
name|charFormat
argument_list|(
name|int
name|index
argument_list|)
decl|const
block|{
return|return
name|format
argument_list|(
name|index
argument_list|)
operator|.
name|toCharFormat
argument_list|()
return|;
block|}
specifier|inline
name|QTextListFormat
name|listFormat
argument_list|(
name|int
name|index
argument_list|)
decl|const
block|{
return|return
name|format
argument_list|(
name|index
argument_list|)
operator|.
name|toListFormat
argument_list|()
return|;
block|}
specifier|inline
name|QTextTableFormat
name|tableFormat
argument_list|(
name|int
name|index
argument_list|)
decl|const
block|{
return|return
name|format
argument_list|(
name|index
argument_list|)
operator|.
name|toTableFormat
argument_list|()
return|;
block|}
specifier|inline
name|QTextImageFormat
name|imageFormat
argument_list|(
name|int
name|index
argument_list|)
decl|const
block|{
return|return
name|format
argument_list|(
name|index
argument_list|)
operator|.
name|toImageFormat
argument_list|()
return|;
block|}
specifier|inline
name|int
name|numFormats
argument_list|()
specifier|const
block|{
return|return
name|formats
operator|.
name|count
argument_list|()
return|;
block|}
typedef|typedef
name|QVector
operator|<
name|QTextFormat
operator|>
name|FormatVector
expr_stmt|;
name|FormatVector
name|formats
decl_stmt|;
name|QVector
operator|<
name|qint32
operator|>
name|objFormats
expr_stmt|;
name|QMultiHash
operator|<
name|uint
operator|,
name|int
operator|>
name|hashes
expr_stmt|;
specifier|inline
name|QFont
name|defaultFont
argument_list|()
specifier|const
block|{
return|return
name|defaultFnt
return|;
block|}
name|void
name|setDefaultFont
parameter_list|(
specifier|const
name|QFont
modifier|&
name|f
parameter_list|)
function_decl|;
name|private
label|:
name|QFont
name|defaultFnt
decl_stmt|;
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
comment|// QTEXTFORMAT_P_H
end_comment
end_unit
