begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSYNTAXHIGHLIGHTER_H
end_ifndef
begin_define
DECL|macro|QSYNTAXHIGHLIGHTER_H
define|#
directive|define
name|QSYNTAXHIGHLIGHTER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYNTAXHIGHLIGHTER
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtextobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QTextDocument
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSyntaxHighlighterPrivate
name|class
name|QSyntaxHighlighterPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextCharFormat
name|class
name|QTextCharFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFont
name|class
name|QFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QColor
name|class
name|QColor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextBlockUserData
name|class
name|QTextBlockUserData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QSyntaxHighlighter
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSyntaxHighlighter
argument_list|)
name|public
operator|:
name|QSyntaxHighlighter
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|QSyntaxHighlighter
argument_list|(
name|QTextDocument
operator|*
name|parent
argument_list|)
block|;
name|virtual
operator|~
name|QSyntaxHighlighter
argument_list|()
block|;
name|void
name|setDocument
argument_list|(
name|QTextDocument
operator|*
name|doc
argument_list|)
block|;
name|QTextDocument
operator|*
name|document
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|rehighlight
argument_list|()
block|;
name|void
name|rehighlightBlock
argument_list|(
specifier|const
name|QTextBlock
operator|&
name|block
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|void
name|highlightBlock
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
operator|=
literal|0
block|;
name|void
name|setFormat
argument_list|(
argument|int start
argument_list|,
argument|int count
argument_list|,
argument|const QTextCharFormat&format
argument_list|)
block|;
name|void
name|setFormat
argument_list|(
argument|int start
argument_list|,
argument|int count
argument_list|,
argument|const QColor&color
argument_list|)
block|;
name|void
name|setFormat
argument_list|(
argument|int start
argument_list|,
argument|int count
argument_list|,
argument|const QFont&font
argument_list|)
block|;
name|QTextCharFormat
name|format
argument_list|(
argument|int pos
argument_list|)
specifier|const
block|;
name|int
name|previousBlockState
argument_list|()
specifier|const
block|;
name|int
name|currentBlockState
argument_list|()
specifier|const
block|;
name|void
name|setCurrentBlockState
argument_list|(
argument|int newState
argument_list|)
block|;
name|void
name|setCurrentBlockUserData
argument_list|(
name|QTextBlockUserData
operator|*
name|data
argument_list|)
block|;
name|QTextBlockUserData
operator|*
name|currentBlockUserData
argument_list|()
specifier|const
block|;
name|QTextBlock
name|currentBlock
argument_list|()
specifier|const
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QSyntaxHighlighter
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_reformatBlocks(int from, int charsRemoved, int charsAdded)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_delayedRehighlight()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SYNTAXHIGHLIGHTER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSYNTAXHIGHLIGHTER_H
end_comment
end_unit
