begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CODEPARSER_H
end_ifndef
begin_define
DECL|macro|CODEPARSER_H
define|#
directive|define
name|CODEPARSER_H
end_define
begin_include
include|#
directive|include
file|<qset.h>
end_include
begin_include
include|#
directive|include
file|"node.h"
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
DECL|variable|QDocDatabase
name|class
name|QDocDatabase
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|CodeParser
block|{
name|Q_DECLARE_TR_FUNCTIONS
argument_list|(
argument|QDoc::CodeParser
argument_list|)
name|public
label|:
name|CodeParser
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|CodeParser
argument_list|()
expr_stmt|;
name|virtual
name|void
name|initializeParser
parameter_list|(
specifier|const
name|Config
modifier|&
name|config
parameter_list|)
function_decl|;
name|virtual
name|void
name|terminateParser
parameter_list|()
function_decl|;
name|virtual
name|QString
name|language
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|QStringList
name|headerFileNameFilter
parameter_list|()
function_decl|;
name|virtual
name|QStringList
name|sourceFileNameFilter
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|parseHeaderFile
parameter_list|(
specifier|const
name|Location
modifier|&
name|location
parameter_list|,
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|)
function_decl|;
name|virtual
name|void
name|parseSourceFile
parameter_list|(
specifier|const
name|Location
modifier|&
name|location
parameter_list|,
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|doneParsingHeaderFiles
parameter_list|()
function_decl|;
name|virtual
name|void
name|doneParsingSourceFiles
parameter_list|()
init|=
literal|0
function_decl|;
name|bool
name|isParsingH
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isParsingCpp
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isParsingQdoc
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|QString
operator|&
name|currentFile
argument_list|()
specifier|const
block|{
return|return
name|currentFile_
return|;
block|}
name|void
name|checkModuleInclusion
parameter_list|(
name|Node
modifier|*
name|n
parameter_list|)
function_decl|;
specifier|static
name|void
name|initialize
parameter_list|(
specifier|const
name|Config
modifier|&
name|config
parameter_list|)
function_decl|;
specifier|static
name|void
name|terminate
parameter_list|()
function_decl|;
specifier|static
name|CodeParser
modifier|*
name|parserForLanguage
parameter_list|(
specifier|const
name|QString
modifier|&
name|language
parameter_list|)
function_decl|;
specifier|static
name|CodeParser
modifier|*
name|parserForHeaderFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|)
function_decl|;
specifier|static
name|CodeParser
modifier|*
name|parserForSourceFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|QString
name|titleFromName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
specifier|static
name|void
name|setLink
argument_list|(
name|Node
operator|*
name|node
argument_list|,
name|Node
operator|::
name|LinkType
name|linkType
argument_list|,
specifier|const
name|QString
operator|&
name|arg
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|QString
modifier|&
name|currentOutputSubdirectory
parameter_list|()
block|{
return|return
name|currentSubDir_
return|;
block|}
name|protected
label|:
specifier|const
name|QSet
operator|<
name|QString
operator|>
operator|&
name|commonMetaCommands
argument_list|()
expr_stmt|;
name|void
name|processCommonMetaCommand
parameter_list|(
specifier|const
name|Location
modifier|&
name|location
parameter_list|,
specifier|const
name|QString
modifier|&
name|command
parameter_list|,
specifier|const
name|ArgLocPair
modifier|&
name|arg
parameter_list|,
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
specifier|static
name|void
name|extractPageLinkAndDesc
parameter_list|(
specifier|const
name|QString
modifier|&
name|arg
parameter_list|,
name|QString
modifier|*
name|link
parameter_list|,
name|QString
modifier|*
name|desc
parameter_list|)
function_decl|;
name|QString
name|currentFile_
decl_stmt|;
name|QDocDatabase
modifier|*
name|qdb_
decl_stmt|;
name|private
label|:
specifier|static
name|QString
name|currentSubDir_
decl_stmt|;
specifier|static
name|QList
operator|<
name|CodeParser
operator|*
operator|>
name|parsers
expr_stmt|;
specifier|static
name|bool
name|showInternal
decl_stmt|;
specifier|static
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
name|nameToTitle
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
end_unit
