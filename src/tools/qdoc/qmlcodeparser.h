begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   qmlcodeparser.h */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMLCODEPARSER_H
end_ifndef
begin_define
DECL|macro|QMLCODEPARSER_H
define|#
directive|define
name|QMLCODEPARSER_H
end_define
begin_include
include|#
directive|include
file|<qset.h>
end_include
begin_include
include|#
directive|include
file|"qqmljsengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qqmljslexer_p.h"
end_include
begin_include
include|#
directive|include
file|"qqmljsparser_p.h"
end_include
begin_include
include|#
directive|include
file|"codeparser.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|Config
name|class
name|Config
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Node
name|class
name|Node
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Tree
name|class
name|Tree
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QmlCodeParser
range|:
name|public
name|CodeParser
block|{
name|public
operator|:
name|QmlCodeParser
argument_list|()
block|;
name|virtual
operator|~
name|QmlCodeParser
argument_list|()
block|;
name|virtual
name|void
name|initializeParser
argument_list|(
specifier|const
name|Config
operator|&
name|config
argument_list|)
block|;
name|virtual
name|void
name|terminateParser
argument_list|()
block|;
name|virtual
name|QString
name|language
argument_list|()
block|;
name|virtual
name|QStringList
name|sourceFileNameFilter
argument_list|()
block|;
name|virtual
name|void
name|parseSourceFile
argument_list|(
specifier|const
name|Location
operator|&
name|location
argument_list|,
specifier|const
name|QString
operator|&
name|filePath
argument_list|)
block|;
name|virtual
name|void
name|doneParsingSourceFiles
argument_list|()
block|;
comment|/* Copied from src/declarative/qml/qdeclarativescriptparser.cpp */
name|void
name|extractPragmas
argument_list|(
name|QString
operator|&
name|script
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|QSet
operator|<
name|QString
operator|>
name|topicCommands
argument_list|()
block|;
name|virtual
name|QSet
operator|<
name|QString
operator|>
name|otherMetaCommands
argument_list|()
block|;
name|private
operator|:
name|QQmlJS
operator|::
name|Engine
name|engine
block|;
name|QQmlJS
operator|::
name|Lexer
operator|*
name|lexer
block|;
name|QQmlJS
operator|::
name|Parser
operator|*
name|parser
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
