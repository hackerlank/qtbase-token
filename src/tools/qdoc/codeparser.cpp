begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   codeparser.cpp */
end_comment
begin_include
include|#
directive|include
file|"codeparser.h"
end_include
begin_include
include|#
directive|include
file|"node.h"
end_include
begin_include
include|#
directive|include
file|"tree.h"
end_include
begin_include
include|#
directive|include
file|"config.h"
end_include
begin_include
include|#
directive|include
file|"generator.h"
end_include
begin_include
include|#
directive|include
file|"qdocdatabase.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|macro|COMMAND_COMPAT
define|#
directive|define
name|COMMAND_COMPAT
value|Doc::alias(QLatin1String("compat"))
DECL|macro|COMMAND_DEPRECATED
define|#
directive|define
name|COMMAND_DEPRECATED
value|Doc::alias(QLatin1String("deprecated"))
comment|// ### don't document
DECL|macro|COMMAND_INGROUP
define|#
directive|define
name|COMMAND_INGROUP
value|Doc::alias(QLatin1String("ingroup"))
DECL|macro|COMMAND_INMODULE
define|#
directive|define
name|COMMAND_INMODULE
value|Doc::alias(QLatin1String("inmodule"))
comment|// ### don't document
DECL|macro|COMMAND_INQMLMODULE
define|#
directive|define
name|COMMAND_INQMLMODULE
value|Doc::alias(QLatin1String("inqmlmodule"))
DECL|macro|COMMAND_INTERNAL
define|#
directive|define
name|COMMAND_INTERNAL
value|Doc::alias(QLatin1String("internal"))
DECL|macro|COMMAND_MAINCLASS
define|#
directive|define
name|COMMAND_MAINCLASS
value|Doc::alias(QLatin1String("mainclass"))
DECL|macro|COMMAND_NONREENTRANT
define|#
directive|define
name|COMMAND_NONREENTRANT
value|Doc::alias(QLatin1String("nonreentrant"))
DECL|macro|COMMAND_OBSOLETE
define|#
directive|define
name|COMMAND_OBSOLETE
value|Doc::alias(QLatin1String("obsolete"))
DECL|macro|COMMAND_PAGEKEYWORDS
define|#
directive|define
name|COMMAND_PAGEKEYWORDS
value|Doc::alias(QLatin1String("pagekeywords"))
DECL|macro|COMMAND_PRELIMINARY
define|#
directive|define
name|COMMAND_PRELIMINARY
value|Doc::alias(QLatin1String("preliminary"))
DECL|macro|COMMAND_INPUBLICGROUP
define|#
directive|define
name|COMMAND_INPUBLICGROUP
value|Doc::alias(QLatin1String("inpublicgroup"))
DECL|macro|COMMAND_REENTRANT
define|#
directive|define
name|COMMAND_REENTRANT
value|Doc::alias(QLatin1String("reentrant"))
DECL|macro|COMMAND_SINCE
define|#
directive|define
name|COMMAND_SINCE
value|Doc::alias(QLatin1String("since"))
DECL|macro|COMMAND_SUBTITLE
define|#
directive|define
name|COMMAND_SUBTITLE
value|Doc::alias(QLatin1String("subtitle"))
DECL|macro|COMMAND_THREADSAFE
define|#
directive|define
name|COMMAND_THREADSAFE
value|Doc::alias(QLatin1String("threadsafe"))
DECL|macro|COMMAND_TITLE
define|#
directive|define
name|COMMAND_TITLE
value|Doc::alias(QLatin1String("title"))
DECL|macro|COMMAND_WRAPPER
define|#
directive|define
name|COMMAND_WRAPPER
value|Doc::alias(QLatin1String("wrapper"))
DECL|member|currentSubDir_
name|QString
name|CodeParser
operator|::
name|currentSubDir_
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|parsers
name|QList
argument_list|<
name|CodeParser
modifier|*
argument_list|>
name|CodeParser
operator|::
name|parsers
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|showInternal
name|bool
name|CodeParser
operator|::
name|showInternal
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|nameToTitle
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|CodeParser
operator|::
name|nameToTitle
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!   The constructor adds this code parser to the static   list of code parsers.  */
end_comment
begin_constructor
DECL|function|CodeParser
name|CodeParser
operator|::
name|CodeParser
parameter_list|()
block|{
name|qdb_
operator|=
name|QDocDatabase
operator|::
name|qdocDB
argument_list|()
expr_stmt|;
name|parsers
operator|.
name|prepend
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   The destructor removes this code parser from the static   list of code parsers.  */
end_comment
begin_destructor
DECL|function|~CodeParser
name|CodeParser
operator|::
name|~
name|CodeParser
parameter_list|()
block|{
name|parsers
operator|.
name|removeAll
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!   Initialize the code parser base class.  */
end_comment
begin_function
DECL|function|initializeParser
name|void
name|CodeParser
operator|::
name|initializeParser
parameter_list|(
specifier|const
name|Config
modifier|&
name|config
parameter_list|)
block|{
name|showInternal
operator|=
name|config
operator|.
name|getBool
argument_list|(
name|QLatin1String
argument_list|(
name|CONFIG_SHOWINTERNAL
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Terminating a code parser is trivial.  */
end_comment
begin_function
DECL|function|terminateParser
name|void
name|CodeParser
operator|::
name|terminateParser
parameter_list|()
block|{
comment|// nothing.
block|}
end_function
begin_function
DECL|function|headerFileNameFilter
name|QStringList
name|CodeParser
operator|::
name|headerFileNameFilter
parameter_list|()
block|{
return|return
name|sourceFileNameFilter
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|parseHeaderFile
name|void
name|CodeParser
operator|::
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
block|{
name|parseSourceFile
argument_list|(
name|location
argument_list|,
name|filePath
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|doneParsingHeaderFiles
name|void
name|CodeParser
operator|::
name|doneParsingHeaderFiles
parameter_list|()
block|{
name|doneParsingSourceFiles
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   All the code parsers in the static list are initialized here,   after the qdoc configuration variables have been set.  */
end_comment
begin_function
DECL|function|initialize
name|void
name|CodeParser
operator|::
name|initialize
parameter_list|(
specifier|const
name|Config
modifier|&
name|config
parameter_list|)
block|{
name|QList
argument_list|<
name|CodeParser
modifier|*
argument_list|>
operator|::
name|ConstIterator
name|p
init|=
name|parsers
operator|.
name|constBegin
argument_list|()
decl_stmt|;
while|while
condition|(
name|p
operator|!=
name|parsers
operator|.
name|constEnd
argument_list|()
condition|)
block|{
operator|(
operator|*
name|p
operator|)
operator|->
name|initializeParser
argument_list|(
name|config
argument_list|)
expr_stmt|;
operator|++
name|p
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   All the code parsers in the static list are terminated here.  */
end_comment
begin_function
DECL|function|terminate
name|void
name|CodeParser
operator|::
name|terminate
parameter_list|()
block|{
name|QList
argument_list|<
name|CodeParser
modifier|*
argument_list|>
operator|::
name|ConstIterator
name|p
init|=
name|parsers
operator|.
name|constBegin
argument_list|()
decl_stmt|;
while|while
condition|(
name|p
operator|!=
name|parsers
operator|.
name|constEnd
argument_list|()
condition|)
block|{
operator|(
operator|*
name|p
operator|)
operator|->
name|terminateParser
argument_list|()
expr_stmt|;
operator|++
name|p
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|parserForLanguage
name|CodeParser
modifier|*
name|CodeParser
operator|::
name|parserForLanguage
parameter_list|(
specifier|const
name|QString
modifier|&
name|language
parameter_list|)
block|{
name|QList
argument_list|<
name|CodeParser
modifier|*
argument_list|>
operator|::
name|ConstIterator
name|p
init|=
name|parsers
operator|.
name|constBegin
argument_list|()
decl_stmt|;
while|while
condition|(
name|p
operator|!=
name|parsers
operator|.
name|constEnd
argument_list|()
condition|)
block|{
if|if
condition|(
operator|(
operator|*
name|p
operator|)
operator|->
name|language
argument_list|()
operator|==
name|language
condition|)
return|return
operator|*
name|p
return|;
operator|++
name|p
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|parserForHeaderFile
name|CodeParser
modifier|*
name|CodeParser
operator|::
name|parserForHeaderFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|)
block|{
name|QString
name|fileName
init|=
name|QFileInfo
argument_list|(
name|filePath
argument_list|)
operator|.
name|fileName
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|CodeParser
modifier|*
argument_list|>
operator|::
name|ConstIterator
name|p
init|=
name|parsers
operator|.
name|constBegin
argument_list|()
decl_stmt|;
while|while
condition|(
name|p
operator|!=
name|parsers
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|QStringList
name|headerPatterns
init|=
operator|(
operator|*
name|p
operator|)
operator|->
name|headerFileNameFilter
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|pattern
decl|,
name|headerPatterns
control|)
block|{
name|QRegExp
name|re
argument_list|(
name|pattern
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|,
name|QRegExp
operator|::
name|Wildcard
argument_list|)
decl_stmt|;
if|if
condition|(
name|re
operator|.
name|exactMatch
argument_list|(
name|fileName
argument_list|)
condition|)
return|return
operator|*
name|p
return|;
block|}
operator|++
name|p
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|parserForSourceFile
name|CodeParser
modifier|*
name|CodeParser
operator|::
name|parserForSourceFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|)
block|{
name|QString
name|fileName
init|=
name|QFileInfo
argument_list|(
name|filePath
argument_list|)
operator|.
name|fileName
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|CodeParser
modifier|*
argument_list|>
operator|::
name|ConstIterator
name|p
init|=
name|parsers
operator|.
name|constBegin
argument_list|()
decl_stmt|;
while|while
condition|(
name|p
operator|!=
name|parsers
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|QStringList
name|sourcePatterns
init|=
operator|(
operator|*
name|p
operator|)
operator|->
name|sourceFileNameFilter
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|pattern
decl|,
name|sourcePatterns
control|)
block|{
name|QRegExp
name|re
argument_list|(
name|pattern
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|,
name|QRegExp
operator|::
name|Wildcard
argument_list|)
decl_stmt|;
if|if
condition|(
name|re
operator|.
name|exactMatch
argument_list|(
name|fileName
argument_list|)
condition|)
return|return
operator|*
name|p
return|;
block|}
operator|++
name|p
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|commonMetaCommands_
specifier|static
name|QSet
argument_list|<
name|QString
argument_list|>
name|commonMetaCommands_
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!   Returns the set of strings representing the common metacommands.  */
end_comment
begin_function
DECL|function|commonMetaCommands
specifier|const
name|QSet
argument_list|<
name|QString
argument_list|>
modifier|&
name|CodeParser
operator|::
name|commonMetaCommands
parameter_list|()
block|{
if|if
condition|(
name|commonMetaCommands_
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|commonMetaCommands_
operator|<<
name|COMMAND_COMPAT
operator|<<
name|COMMAND_DEPRECATED
operator|<<
name|COMMAND_INGROUP
operator|<<
name|COMMAND_INMODULE
operator|<<
name|COMMAND_INQMLMODULE
operator|<<
name|COMMAND_INTERNAL
operator|<<
name|COMMAND_MAINCLASS
operator|<<
name|COMMAND_NONREENTRANT
operator|<<
name|COMMAND_OBSOLETE
operator|<<
name|COMMAND_PAGEKEYWORDS
operator|<<
name|COMMAND_PRELIMINARY
operator|<<
name|COMMAND_INPUBLICGROUP
operator|<<
name|COMMAND_REENTRANT
operator|<<
name|COMMAND_SINCE
operator|<<
name|COMMAND_SUBTITLE
operator|<<
name|COMMAND_THREADSAFE
operator|<<
name|COMMAND_TITLE
operator|<<
name|COMMAND_WRAPPER
expr_stmt|;
block|}
return|return
name|commonMetaCommands_
return|;
block|}
end_function
begin_comment
comment|/*!   The topic command has been processed. Now process the other   metacommands that were found. These are not the text markup   commands.  */
end_comment
begin_function
DECL|function|processCommonMetaCommand
name|void
name|CodeParser
operator|::
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
block|{
if|if
condition|(
name|command
operator|==
name|COMMAND_COMPAT
condition|)
block|{
name|location
operator|.
name|warning
argument_list|(
name|tr
argument_list|(
literal|"\\compat command used, but Qt3 compatibility is no longer supported"
argument_list|)
argument_list|)
expr_stmt|;
name|node
operator|->
name|setStatus
argument_list|(
name|Node
operator|::
name|Compat
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|command
operator|==
name|COMMAND_DEPRECATED
condition|)
block|{
name|node
operator|->
name|setStatus
argument_list|(
name|Node
operator|::
name|Obsolete
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|command
operator|==
name|COMMAND_INGROUP
operator|)
operator|||
operator|(
name|command
operator|==
name|COMMAND_INPUBLICGROUP
operator|)
condition|)
block|{
comment|// Note: \ingroup and \inpublicgroup are now the same.
comment|// Not that they were ever different.
name|qdb_
operator|->
name|addToGroup
argument_list|(
name|arg
operator|.
name|first
argument_list|,
name|node
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|command
operator|==
name|COMMAND_INMODULE
condition|)
block|{
name|qdb_
operator|->
name|addToModule
argument_list|(
name|arg
operator|.
name|first
argument_list|,
name|node
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|command
operator|==
name|COMMAND_INQMLMODULE
condition|)
block|{
name|qdb_
operator|->
name|addToQmlModule
argument_list|(
name|arg
operator|.
name|first
argument_list|,
name|node
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|command
operator|==
name|COMMAND_MAINCLASS
condition|)
block|{
name|node
operator|->
name|setStatus
argument_list|(
name|Node
operator|::
name|Main
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|command
operator|==
name|COMMAND_OBSOLETE
condition|)
block|{
if|if
condition|(
name|node
operator|->
name|status
argument_list|()
operator|!=
name|Node
operator|::
name|Compat
condition|)
name|node
operator|->
name|setStatus
argument_list|(
name|Node
operator|::
name|Obsolete
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|command
operator|==
name|COMMAND_NONREENTRANT
condition|)
block|{
name|node
operator|->
name|setThreadSafeness
argument_list|(
name|Node
operator|::
name|NonReentrant
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|command
operator|==
name|COMMAND_PRELIMINARY
condition|)
block|{
name|node
operator|->
name|setStatus
argument_list|(
name|Node
operator|::
name|Preliminary
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|command
operator|==
name|COMMAND_INTERNAL
condition|)
block|{
if|if
condition|(
operator|!
name|showInternal
condition|)
block|{
name|node
operator|->
name|setAccess
argument_list|(
name|Node
operator|::
name|Private
argument_list|)
expr_stmt|;
name|node
operator|->
name|setStatus
argument_list|(
name|Node
operator|::
name|Internal
argument_list|)
expr_stmt|;
if|if
condition|(
name|node
operator|->
name|type
argument_list|()
operator|==
name|Node
operator|::
name|QmlPropertyGroup
condition|)
block|{
specifier|const
name|QmlPropertyGroupNode
modifier|*
name|qpgn
init|=
cast|static_cast
argument_list|<
specifier|const
name|QmlPropertyGroupNode
operator|*
argument_list|>
argument_list|(
name|node
argument_list|)
decl_stmt|;
name|NodeList
operator|::
name|ConstIterator
name|p
init|=
name|qpgn
operator|->
name|childNodes
argument_list|()
operator|.
name|constBegin
argument_list|()
decl_stmt|;
while|while
condition|(
name|p
operator|!=
name|qpgn
operator|->
name|childNodes
argument_list|()
operator|.
name|constEnd
argument_list|()
condition|)
block|{
if|if
condition|(
operator|(
operator|*
name|p
operator|)
operator|->
name|type
argument_list|()
operator|==
name|Node
operator|::
name|QmlProperty
condition|)
block|{
operator|(
operator|*
name|p
operator|)
operator|->
name|setAccess
argument_list|(
name|Node
operator|::
name|Private
argument_list|)
expr_stmt|;
operator|(
operator|*
name|p
operator|)
operator|->
name|setStatus
argument_list|(
name|Node
operator|::
name|Internal
argument_list|)
expr_stmt|;
block|}
operator|++
name|p
expr_stmt|;
block|}
block|}
block|}
block|}
elseif|else
if|if
condition|(
name|command
operator|==
name|COMMAND_REENTRANT
condition|)
block|{
name|node
operator|->
name|setThreadSafeness
argument_list|(
name|Node
operator|::
name|Reentrant
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|command
operator|==
name|COMMAND_SINCE
condition|)
block|{
name|node
operator|->
name|setSince
argument_list|(
name|arg
operator|.
name|first
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|command
operator|==
name|COMMAND_WRAPPER
condition|)
block|{
name|node
operator|->
name|setWrapper
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|command
operator|==
name|COMMAND_PAGEKEYWORDS
condition|)
block|{
name|node
operator|->
name|addPageKeywords
argument_list|(
name|arg
operator|.
name|first
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|command
operator|==
name|COMMAND_SUBTITLE
condition|)
block|{
if|if
condition|(
name|node
operator|->
name|type
argument_list|()
operator|==
name|Node
operator|::
name|Document
condition|)
block|{
name|DocNode
modifier|*
name|dn
init|=
cast|static_cast
argument_list|<
name|DocNode
operator|*
argument_list|>
argument_list|(
name|node
argument_list|)
decl_stmt|;
name|dn
operator|->
name|setSubTitle
argument_list|(
name|arg
operator|.
name|first
argument_list|)
expr_stmt|;
block|}
else|else
name|location
operator|.
name|warning
argument_list|(
name|tr
argument_list|(
literal|"Ignored '\\%1'"
argument_list|)
operator|.
name|arg
argument_list|(
name|COMMAND_SUBTITLE
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|command
operator|==
name|COMMAND_THREADSAFE
condition|)
block|{
name|node
operator|->
name|setThreadSafeness
argument_list|(
name|Node
operator|::
name|ThreadSafe
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|command
operator|==
name|COMMAND_TITLE
condition|)
block|{
if|if
condition|(
name|node
operator|->
name|type
argument_list|()
operator|==
name|Node
operator|::
name|Document
condition|)
block|{
name|DocNode
modifier|*
name|dn
init|=
cast|static_cast
argument_list|<
name|DocNode
operator|*
argument_list|>
argument_list|(
name|node
argument_list|)
decl_stmt|;
name|dn
operator|->
name|setTitle
argument_list|(
name|arg
operator|.
name|first
argument_list|)
expr_stmt|;
if|if
condition|(
name|dn
operator|->
name|subType
argument_list|()
operator|==
name|Node
operator|::
name|Example
condition|)
block|{
name|ExampleNode
operator|::
name|exampleNodeMap
operator|.
name|insert
argument_list|(
name|dn
operator|->
name|title
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|ExampleNode
operator|*
argument_list|>
argument_list|(
name|dn
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|nameToTitle
operator|.
name|insert
argument_list|(
name|dn
operator|->
name|name
argument_list|()
argument_list|,
name|arg
operator|.
name|first
argument_list|)
expr_stmt|;
block|}
else|else
name|location
operator|.
name|warning
argument_list|(
name|tr
argument_list|(
literal|"Ignored '\\%1'"
argument_list|)
operator|.
name|arg
argument_list|(
name|COMMAND_TITLE
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   Find the page title given the page \a name and return it.  */
end_comment
begin_function
DECL|function|titleFromName
specifier|const
name|QString
name|CodeParser
operator|::
name|titleFromName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
specifier|const
name|QString
name|t
init|=
name|nameToTitle
operator|.
name|value
argument_list|(
name|name
argument_list|)
decl_stmt|;
return|return
name|t
return|;
block|}
end_function
begin_comment
comment|/*!   \internal  */
end_comment
begin_function
DECL|function|extractPageLinkAndDesc
name|void
name|CodeParser
operator|::
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
block|{
name|QRegExp
name|bracedRegExp
argument_list|(
name|QLatin1String
argument_list|(
literal|"\\{([^{}]*)\\}(?:\\{([^{}]*)\\})?"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|bracedRegExp
operator|.
name|exactMatch
argument_list|(
name|arg
argument_list|)
condition|)
block|{
operator|*
name|link
operator|=
name|bracedRegExp
operator|.
name|cap
argument_list|(
literal|1
argument_list|)
expr_stmt|;
operator|*
name|desc
operator|=
name|bracedRegExp
operator|.
name|cap
argument_list|(
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|desc
operator|->
name|isEmpty
argument_list|()
condition|)
operator|*
name|desc
operator|=
operator|*
name|link
expr_stmt|;
block|}
else|else
block|{
name|int
name|spaceAt
init|=
name|arg
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|arg
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|".html"
argument_list|)
argument_list|)
operator|&&
name|spaceAt
operator|!=
operator|-
literal|1
condition|)
block|{
operator|*
name|link
operator|=
name|arg
operator|.
name|left
argument_list|(
name|spaceAt
argument_list|)
operator|.
name|trimmed
argument_list|()
expr_stmt|;
operator|*
name|desc
operator|=
name|arg
operator|.
name|mid
argument_list|(
name|spaceAt
argument_list|)
operator|.
name|trimmed
argument_list|()
expr_stmt|;
block|}
else|else
block|{
operator|*
name|link
operator|=
name|arg
expr_stmt|;
operator|*
name|desc
operator|=
name|arg
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|/*!   \internal  */
end_comment
begin_function
DECL|function|setLink
name|void
name|CodeParser
operator|::
name|setLink
parameter_list|(
name|Node
modifier|*
name|node
parameter_list|,
name|Node
operator|::
name|LinkType
name|linkType
parameter_list|,
specifier|const
name|QString
modifier|&
name|arg
parameter_list|)
block|{
name|QString
name|link
decl_stmt|;
name|QString
name|desc
decl_stmt|;
name|extractPageLinkAndDesc
argument_list|(
name|arg
argument_list|,
operator|&
name|link
argument_list|,
operator|&
name|desc
argument_list|)
expr_stmt|;
name|node
operator|->
name|setLink
argument_list|(
name|linkType
argument_list|,
name|link
argument_list|,
name|desc
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns true if the file being parsed is a .h file.  */
end_comment
begin_function
DECL|function|isParsingH
name|bool
name|CodeParser
operator|::
name|isParsingH
parameter_list|()
specifier|const
block|{
return|return
name|currentFile_
operator|.
name|endsWith
argument_list|(
literal|".h"
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   Returns true if the file being parsed is a .cpp file.  */
end_comment
begin_function
DECL|function|isParsingCpp
name|bool
name|CodeParser
operator|::
name|isParsingCpp
parameter_list|()
specifier|const
block|{
return|return
name|currentFile_
operator|.
name|endsWith
argument_list|(
literal|".cpp"
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   Returns true if the file being parsed is a .qdoc file.  */
end_comment
begin_function
DECL|function|isParsingQdoc
name|bool
name|CodeParser
operator|::
name|isParsingQdoc
parameter_list|()
specifier|const
block|{
return|return
name|currentFile_
operator|.
name|endsWith
argument_list|(
literal|".qdoc"
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   For each node that will produce a documentation page, this function   ensures that the node belongs to a module. Normally, the qdoc comment   for an entity that will produce a documentation page will contain an   \inmodule command to tell qdoc which module the entity belongs to.    But now that we normally run qdoc on each module in two passes. The   first produces an index file; the second pass generates the docs   after reading all the index files it needs.    This means that all the pages generated during each pass 2 run of   qdoc almost certainly belong to a single module, and the name of   that module is, as a rule, used as the project name in the qdocconf   file used when running qdoc on the module.    So this function first asks if the node \a n has a non-empty module   name. If it it does not have a non-empty module name, it sets the   module name to be the project name.    In some cases it prints a qdoc warning that it has done this. Namely,   for C++ classes and namespaces.  */
end_comment
begin_function
DECL|function|checkModuleInclusion
name|void
name|CodeParser
operator|::
name|checkModuleInclusion
parameter_list|(
name|Node
modifier|*
name|n
parameter_list|)
block|{
if|if
condition|(
name|n
operator|->
name|moduleName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
switch|switch
condition|(
name|n
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|Node
operator|::
name|Class
case|:
if|if
condition|(
name|n
operator|->
name|access
argument_list|()
operator|!=
name|Node
operator|::
name|Private
operator|&&
operator|!
name|n
operator|->
name|doc
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|n
operator|->
name|setModuleName
argument_list|(
name|Generator
operator|::
name|defaultModuleName
argument_list|()
argument_list|)
expr_stmt|;
name|n
operator|->
name|doc
argument_list|()
operator|.
name|location
argument_list|()
operator|.
name|warning
argument_list|(
name|tr
argument_list|(
literal|"Class %1 has no \\inmodule command; "
literal|"using project name by default: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|n
operator|->
name|name
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|Generator
operator|::
name|defaultModuleName
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|Node
operator|::
name|Namespace
case|:
if|if
condition|(
name|n
operator|->
name|access
argument_list|()
operator|!=
name|Node
operator|::
name|Private
operator|&&
operator|!
name|n
operator|->
name|name
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|n
operator|->
name|doc
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|n
operator|->
name|setModuleName
argument_list|(
name|Generator
operator|::
name|defaultModuleName
argument_list|()
argument_list|)
expr_stmt|;
name|n
operator|->
name|doc
argument_list|()
operator|.
name|location
argument_list|()
operator|.
name|warning
argument_list|(
name|tr
argument_list|(
literal|"Namespace %1 has no \\inmodule command; "
literal|"using project name by default: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|n
operator|->
name|name
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|Generator
operator|::
name|defaultModuleName
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|Node
operator|::
name|Document
case|:
if|if
condition|(
name|n
operator|->
name|access
argument_list|()
operator|!=
name|Node
operator|::
name|Private
operator|&&
operator|!
name|n
operator|->
name|doc
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|n
operator|->
name|subType
argument_list|()
operator|==
name|Node
operator|::
name|HeaderFile
condition|)
block|{
name|n
operator|->
name|setModuleName
argument_list|(
name|Generator
operator|::
name|defaultModuleName
argument_list|()
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|n->doc().location().warning(tr("Header file with title \"%1\" has no \\inmodule command; "                                                    "using project name by default: %2")                                                 .arg(n->title()).arg(Generator::defaultModuleName()));
endif|#
directive|endif
block|}
elseif|else
if|if
condition|(
name|n
operator|->
name|subType
argument_list|()
operator|==
name|Node
operator|::
name|Page
condition|)
block|{
name|n
operator|->
name|setModuleName
argument_list|(
name|Generator
operator|::
name|defaultModuleName
argument_list|()
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|n->doc().location().warning(tr("Page with title \"%1\" has no \\inmodule command; "                                                    "using project name by default: %2")                                                 .arg(n->title()).arg(Generator::defaultModuleName()));
endif|#
directive|endif
block|}
elseif|else
if|if
condition|(
name|n
operator|->
name|subType
argument_list|()
operator|==
name|Node
operator|::
name|Example
condition|)
block|{
name|n
operator|->
name|setModuleName
argument_list|(
name|Generator
operator|::
name|defaultModuleName
argument_list|()
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|n->doc().location().warning(tr("Example with title \"%1\" has no \\inmodule command; "                                                    "using project name by default: %2")                                                 .arg(n->title()).arg(Generator::defaultModuleName()));
endif|#
directive|endif
block|}
block|}
break|break;
default|default:
break|break;
block|}
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
