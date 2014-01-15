begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QLALR project on Qt Labs. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"grammar_p.h"
end_include
begin_include
include|#
directive|include
file|"lalr.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfile.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<cstdlib>
end_include
begin_decl_stmt
name|class
name|Recognizer
range|:
name|protected
name|grammar
block|{
name|public
operator|:
name|Recognizer
argument_list|(
argument|Grammar *grammar
argument_list|,
argument|bool no_lines
argument_list|)
block|;
operator|~
name|Recognizer
argument_list|()
block|;
name|bool
name|parse
argument_list|(
specifier|const
name|QString
operator|&
name|input_file
operator|=
name|QString
argument_list|()
argument_list|)
block|;
specifier|inline
name|QString
name|decls
argument_list|()
specifier|const
block|{
return|return
name|_M_decls
return|;
block|}
specifier|inline
name|QString
name|impls
argument_list|()
specifier|const
block|{
return|return
name|_M_impls
return|;
block|}
name|protected
operator|:
specifier|inline
name|void
name|reallocateStack
argument_list|()
block|;
specifier|inline
name|QString
operator|&
name|sym
argument_list|(
argument|int index
argument_list|)
block|{
return|return
name|sym_stack
index|[
name|tos
operator|+
name|index
operator|-
literal|1
index|]
return|;
block|}
name|protected
operator|:
comment|// scanner
name|int
name|nextToken
argument_list|()
block|;
specifier|inline
name|void
name|inp
argument_list|()
block|{
if|if
condition|(
name|_M_currentChar
operator|!=
name|_M_lastChar
condition|)
block|{
name|ch
operator|=
operator|*
name|_M_currentChar
operator|++
expr_stmt|;
if|if
condition|(
name|ch
operator|==
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
condition|)
operator|++
name|_M_line
expr_stmt|;
block|}
else|else
name|ch
operator|=
name|QChar
argument_list|()
expr_stmt|;
block|}
name|QString
name|expand
argument_list|(
argument|const QString&text
argument_list|)
specifier|const
block|;
name|protected
operator|:
comment|// recognizer
name|int
name|tos
block|;
name|int
name|stack_size
block|;
name|QVector
operator|<
name|QString
operator|>
name|sym_stack
block|;
name|int
operator|*
name|state_stack
block|;
name|QString
name|_M_contents
block|;
name|QString
operator|::
name|const_iterator
name|_M_firstChar
block|;
name|QString
operator|::
name|const_iterator
name|_M_lastChar
block|;
name|QString
operator|::
name|const_iterator
name|_M_currentChar
block|;
comment|// scanner
name|QChar
name|ch
block|;
name|int
name|_M_line
block|;
name|int
name|_M_action_line
block|;
name|Grammar
operator|*
name|_M_grammar
block|;
name|RulePointer
name|_M_current_rule
block|;
name|QString
name|_M_input_file
block|;
name|QString
name|_M_decls
block|;
name|QString
name|_M_impls
block|;
name|QString
name|_M_current_value
block|;
name|bool
name|_M_no_lines
block|; }
decl_stmt|;
end_decl_stmt
end_unit
