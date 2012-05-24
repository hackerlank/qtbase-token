begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   cppcodeparser.h */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CPPCODEPARSER_H
end_ifndef
begin_define
DECL|macro|CPPCODEPARSER_H
define|#
directive|define
name|CPPCODEPARSER_H
end_define
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|"codeparser.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|ClassNode
name|class
name|ClassNode
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|CodeChunk
name|class
name|CodeChunk
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|CppCodeParserPrivate
name|class
name|CppCodeParserPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FunctionNode
name|class
name|FunctionNode
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|InnerNode
name|class
name|InnerNode
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Tokenizer
name|class
name|Tokenizer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|CppCodeParser
range|:
name|public
name|CodeParser
block|{
name|public
operator|:
name|CppCodeParser
argument_list|()
block|;
operator|~
name|CppCodeParser
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
name|headerFileNameFilter
argument_list|()
block|;
name|virtual
name|QStringList
name|sourceFileNameFilter
argument_list|()
block|;
name|virtual
name|void
name|parseHeaderFile
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
argument_list|,
name|Tree
operator|*
name|tree
argument_list|)
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
argument_list|,
name|Tree
operator|*
name|tree
argument_list|)
block|;
name|virtual
name|void
name|doneParsingHeaderFiles
argument_list|(
name|Tree
operator|*
name|tree
argument_list|)
block|;
name|virtual
name|void
name|doneParsingSourceFiles
argument_list|(
name|Tree
operator|*
name|tree
argument_list|)
block|;
specifier|const
name|FunctionNode
operator|*
name|findFunctionNode
argument_list|(
argument|const QString& synopsis
argument_list|,
argument|Tree *tree
argument_list|,
argument|Node *relative =
literal|0
argument_list|,
argument|bool fuzzy = false
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
name|Node
operator|*
name|processTopicCommand
argument_list|(
specifier|const
name|Doc
operator|&
name|doc
argument_list|,
specifier|const
name|QString
operator|&
name|command
argument_list|,
specifier|const
name|ArgLocPair
operator|&
name|arg
argument_list|)
block|;
name|virtual
name|Node
operator|*
name|processTopicCommandGroup
argument_list|(
specifier|const
name|QString
operator|&
name|command
argument_list|,
specifier|const
name|ArgList
operator|&
name|args
argument_list|)
block|;
name|bool
name|splitQmlPropertyArg
argument_list|(
specifier|const
name|QString
operator|&
name|arg
argument_list|,
name|QString
operator|&
name|type
argument_list|,
name|QString
operator|&
name|module
argument_list|,
name|QString
operator|&
name|element
argument_list|,
name|QString
operator|&
name|name
argument_list|)
block|;
name|bool
name|splitQmlMethodArg
argument_list|(
specifier|const
name|QString
operator|&
name|arg
argument_list|,
name|QString
operator|&
name|type
argument_list|,
name|QString
operator|&
name|module
argument_list|,
name|QString
operator|&
name|element
argument_list|)
block|;
name|virtual
name|QSet
operator|<
name|QString
operator|>
name|otherMetaCommands
argument_list|()
block|;
name|virtual
name|void
name|processOtherMetaCommand
argument_list|(
specifier|const
name|Doc
operator|&
name|doc
argument_list|,
specifier|const
name|QString
operator|&
name|command
argument_list|,
specifier|const
name|ArgLocPair
operator|&
name|argLocPair
argument_list|,
name|Node
operator|*
name|node
argument_list|)
block|;
name|void
name|processOtherMetaCommands
argument_list|(
specifier|const
name|Doc
operator|&
name|doc
argument_list|,
name|Node
operator|*
name|node
argument_list|)
block|;
name|protected
operator|:
name|void
name|reset
argument_list|(
name|Tree
operator|*
name|tree
argument_list|)
block|;
name|void
name|readToken
argument_list|()
block|;
specifier|const
name|Location
operator|&
name|location
argument_list|()
block|;
name|QString
name|previousLexeme
argument_list|()
block|;
name|QString
name|lexeme
argument_list|()
block|;
name|private
operator|:
name|bool
name|match
argument_list|(
argument|int target
argument_list|)
block|;
name|bool
name|skipTo
argument_list|(
argument|int target
argument_list|)
block|;
name|bool
name|matchCompat
argument_list|()
block|;
name|bool
name|matchModuleQualifier
argument_list|(
name|QString
operator|&
name|name
argument_list|)
block|;
name|bool
name|matchTemplateAngles
argument_list|(
name|CodeChunk
operator|*
name|type
operator|=
literal|0
argument_list|)
block|;
name|bool
name|matchTemplateHeader
argument_list|()
block|;
name|bool
name|matchDataType
argument_list|(
name|CodeChunk
operator|*
name|type
argument_list|,
name|QString
operator|*
name|var
operator|=
literal|0
argument_list|)
block|;
name|bool
name|matchParameter
argument_list|(
name|FunctionNode
operator|*
name|func
argument_list|)
block|;
name|bool
name|matchFunctionDecl
argument_list|(
argument|InnerNode *parent
argument_list|,
argument|QStringList *parentPathPtr =
literal|0
argument_list|,
argument|FunctionNode **funcPtr =
literal|0
argument_list|,
argument|const QString&templateStuff = QString()
argument_list|,
argument|Node::Type type = Node::Function
argument_list|,
argument|bool attached = false
argument_list|)
block|;
name|bool
name|matchBaseSpecifier
argument_list|(
argument|ClassNode *classe
argument_list|,
argument|bool isClass
argument_list|)
block|;
name|bool
name|matchBaseList
argument_list|(
argument|ClassNode *classe
argument_list|,
argument|bool isClass
argument_list|)
block|;
name|bool
name|matchClassDecl
argument_list|(
name|InnerNode
operator|*
name|parent
argument_list|,
specifier|const
name|QString
operator|&
name|templateStuff
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|bool
name|matchNamespaceDecl
argument_list|(
name|InnerNode
operator|*
name|parent
argument_list|)
block|;
name|bool
name|matchUsingDecl
argument_list|()
block|;
name|bool
name|matchEnumItem
argument_list|(
name|InnerNode
operator|*
name|parent
argument_list|,
name|EnumNode
operator|*
name|enume
argument_list|)
block|;
name|bool
name|matchEnumDecl
argument_list|(
name|InnerNode
operator|*
name|parent
argument_list|)
block|;
name|bool
name|matchTypedefDecl
argument_list|(
name|InnerNode
operator|*
name|parent
argument_list|)
block|;
name|bool
name|matchProperty
argument_list|(
name|InnerNode
operator|*
name|parent
argument_list|)
block|;
name|bool
name|matchDeclList
argument_list|(
name|InnerNode
operator|*
name|parent
argument_list|)
block|;
name|bool
name|matchDocsAndStuff
argument_list|()
block|;
name|bool
name|makeFunctionNode
argument_list|(
argument|const QString&synopsis
argument_list|,
argument|QStringList *parentPathPtr
argument_list|,
argument|FunctionNode **funcPtr
argument_list|,
argument|InnerNode *root =
literal|0
argument_list|,
argument|Node::Type type = Node::Function
argument_list|,
argument|bool attached = false
argument_list|)
block|;
name|FunctionNode
operator|*
name|makeFunctionNode
argument_list|(
argument|const Doc& doc
argument_list|,
argument|const QString& sig
argument_list|,
argument|InnerNode* parent
argument_list|,
argument|Node::Type type
argument_list|,
argument|bool attached
argument_list|,
argument|QString qdoctag
argument_list|)
block|;
name|void
name|parseQiteratorDotH
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
name|void
name|instantiateIteratorMacro
argument_list|(
specifier|const
name|QString
operator|&
name|container
argument_list|,
specifier|const
name|QString
operator|&
name|includeFile
argument_list|,
specifier|const
name|QString
operator|&
name|macroDef
argument_list|,
name|Tree
operator|*
name|tree
argument_list|)
block|;
name|void
name|createExampleFileNodes
argument_list|(
name|FakeNode
operator|*
name|fake
argument_list|)
block|;
name|protected
operator|:
name|QMap
operator|<
name|QString
block|,
name|Node
operator|::
name|Type
operator|>
name|nodeTypeMap
block|;
name|Tree
operator|*
name|tree_
block|;
name|Tokenizer
operator|*
name|tokenizer
block|;
name|int
name|tok
block|;
name|Node
operator|::
name|Access
name|access
block|;
name|FunctionNode
operator|::
name|Metaness
name|metaness
block|;
name|QString
name|moduleName
block|;
name|QStringList
name|lastPath
block|;
name|QRegExp
name|varComment
block|;
name|QRegExp
name|sep
block|;
name|QSet
operator|<
name|QString
operator|>
name|activeNamespaces_
block|;
name|private
operator|:
name|QString
name|sequentialIteratorDefinition
block|;
name|QString
name|mutableSequentialIteratorDefinition
block|;
name|QString
name|associativeIteratorDefinition
block|;
name|QString
name|mutableAssociativeIteratorDefinition
block|;
name|QMap
operator|<
name|QString
block|,
name|QString
operator|>
name|sequentialIteratorClasses
block|;
name|QMap
operator|<
name|QString
block|,
name|QString
operator|>
name|mutableSequentialIteratorClasses
block|;
name|QMap
operator|<
name|QString
block|,
name|QString
operator|>
name|associativeIteratorClasses
block|;
name|QMap
operator|<
name|QString
block|,
name|QString
operator|>
name|mutableAssociativeIteratorClasses
block|;
specifier|static
name|QStringList
name|exampleFiles
block|;
specifier|static
name|QStringList
name|exampleDirs
block|;
name|QString
name|exampleNameFilter
block|;
name|QString
name|exampleImageFilter
block|; }
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|COMMAND_CLASS
define|#
directive|define
name|COMMAND_CLASS
value|Doc::alias("class")
end_define
begin_define
DECL|macro|COMMAND_CONTENTSPAGE
define|#
directive|define
name|COMMAND_CONTENTSPAGE
value|Doc::alias("contentspage")
end_define
begin_define
DECL|macro|COMMAND_DITAMAP
define|#
directive|define
name|COMMAND_DITAMAP
value|Doc::alias("ditamap")
end_define
begin_define
DECL|macro|COMMAND_ENUM
define|#
directive|define
name|COMMAND_ENUM
value|Doc::alias("enum")
end_define
begin_define
DECL|macro|COMMAND_EXAMPLE
define|#
directive|define
name|COMMAND_EXAMPLE
value|Doc::alias("example")
end_define
begin_define
DECL|macro|COMMAND_EXTERNALPAGE
define|#
directive|define
name|COMMAND_EXTERNALPAGE
value|Doc::alias("externalpage")
end_define
begin_define
DECL|macro|COMMAND_FILE
define|#
directive|define
name|COMMAND_FILE
value|Doc::alias("file")
end_define
begin_define
DECL|macro|COMMAND_FN
define|#
directive|define
name|COMMAND_FN
value|Doc::alias("fn")
end_define
begin_define
DECL|macro|COMMAND_GROUP
define|#
directive|define
name|COMMAND_GROUP
value|Doc::alias("group")
end_define
begin_define
DECL|macro|COMMAND_HEADERFILE
define|#
directive|define
name|COMMAND_HEADERFILE
value|Doc::alias("headerfile")
end_define
begin_define
DECL|macro|COMMAND_INDEXPAGE
define|#
directive|define
name|COMMAND_INDEXPAGE
value|Doc::alias("indexpage")
end_define
begin_define
DECL|macro|COMMAND_INHEADERFILE
define|#
directive|define
name|COMMAND_INHEADERFILE
value|Doc::alias("inheaderfile")
end_define
begin_define
DECL|macro|COMMAND_MACRO
define|#
directive|define
name|COMMAND_MACRO
value|Doc::alias("macro")
end_define
begin_define
DECL|macro|COMMAND_MODULE
define|#
directive|define
name|COMMAND_MODULE
value|Doc::alias("module")
end_define
begin_define
DECL|macro|COMMAND_NAMESPACE
define|#
directive|define
name|COMMAND_NAMESPACE
value|Doc::alias("namespace")
end_define
begin_define
DECL|macro|COMMAND_OVERLOAD
define|#
directive|define
name|COMMAND_OVERLOAD
value|Doc::alias("overload")
end_define
begin_define
DECL|macro|COMMAND_NEXTPAGE
define|#
directive|define
name|COMMAND_NEXTPAGE
value|Doc::alias("nextpage")
end_define
begin_define
DECL|macro|COMMAND_PAGE
define|#
directive|define
name|COMMAND_PAGE
value|Doc::alias("page")
end_define
begin_define
DECL|macro|COMMAND_PREVIOUSPAGE
define|#
directive|define
name|COMMAND_PREVIOUSPAGE
value|Doc::alias("previouspage")
end_define
begin_define
DECL|macro|COMMAND_PROPERTY
define|#
directive|define
name|COMMAND_PROPERTY
value|Doc::alias("property")
end_define
begin_define
DECL|macro|COMMAND_REIMP
define|#
directive|define
name|COMMAND_REIMP
value|Doc::alias("reimp")
end_define
begin_define
DECL|macro|COMMAND_RELATES
define|#
directive|define
name|COMMAND_RELATES
value|Doc::alias("relates")
end_define
begin_define
DECL|macro|COMMAND_STARTPAGE
define|#
directive|define
name|COMMAND_STARTPAGE
value|Doc::alias("startpage")
end_define
begin_define
DECL|macro|COMMAND_TYPEDEF
define|#
directive|define
name|COMMAND_TYPEDEF
value|Doc::alias("typedef")
end_define
begin_define
DECL|macro|COMMAND_VARIABLE
define|#
directive|define
name|COMMAND_VARIABLE
value|Doc::alias("variable")
end_define
begin_define
DECL|macro|COMMAND_QMLABSTRACT
define|#
directive|define
name|COMMAND_QMLABSTRACT
value|Doc::alias("qmlabstract")
end_define
begin_define
DECL|macro|COMMAND_QMLCLASS
define|#
directive|define
name|COMMAND_QMLCLASS
value|Doc::alias("qmlclass")
end_define
begin_define
DECL|macro|COMMAND_QMLPROPERTY
define|#
directive|define
name|COMMAND_QMLPROPERTY
value|Doc::alias("qmlproperty")
end_define
begin_define
DECL|macro|COMMAND_QMLATTACHEDPROPERTY
define|#
directive|define
name|COMMAND_QMLATTACHEDPROPERTY
value|Doc::alias("qmlattachedproperty")
end_define
begin_define
DECL|macro|COMMAND_QMLINHERITS
define|#
directive|define
name|COMMAND_QMLINHERITS
value|Doc::alias("inherits")
end_define
begin_define
DECL|macro|COMMAND_QMLSIGNAL
define|#
directive|define
name|COMMAND_QMLSIGNAL
value|Doc::alias("qmlsignal")
end_define
begin_define
DECL|macro|COMMAND_QMLATTACHEDSIGNAL
define|#
directive|define
name|COMMAND_QMLATTACHEDSIGNAL
value|Doc::alias("qmlattachedsignal")
end_define
begin_define
DECL|macro|COMMAND_QMLMETHOD
define|#
directive|define
name|COMMAND_QMLMETHOD
value|Doc::alias("qmlmethod")
end_define
begin_define
DECL|macro|COMMAND_QMLATTACHEDMETHOD
define|#
directive|define
name|COMMAND_QMLATTACHEDMETHOD
value|Doc::alias("qmlattachedmethod")
end_define
begin_define
DECL|macro|COMMAND_QMLDEFAULT
define|#
directive|define
name|COMMAND_QMLDEFAULT
value|Doc::alias("default")
end_define
begin_define
DECL|macro|COMMAND_QMLREADONLY
define|#
directive|define
name|COMMAND_QMLREADONLY
value|Doc::alias("readonly")
end_define
begin_define
DECL|macro|COMMAND_QMLBASICTYPE
define|#
directive|define
name|COMMAND_QMLBASICTYPE
value|Doc::alias("qmlbasictype")
end_define
begin_define
DECL|macro|COMMAND_QMLMODULE
define|#
directive|define
name|COMMAND_QMLMODULE
value|Doc::alias("qmlmodule")
end_define
begin_define
DECL|macro|COMMAND_AUDIENCE
define|#
directive|define
name|COMMAND_AUDIENCE
value|Doc::alias("audience")
end_define
begin_define
DECL|macro|COMMAND_CATEGORY
define|#
directive|define
name|COMMAND_CATEGORY
value|Doc::alias("category")
end_define
begin_define
DECL|macro|COMMAND_PRODNAME
define|#
directive|define
name|COMMAND_PRODNAME
value|Doc::alias("prodname")
end_define
begin_define
DECL|macro|COMMAND_COMPONENT
define|#
directive|define
name|COMMAND_COMPONENT
value|Doc::alias("component")
end_define
begin_define
DECL|macro|COMMAND_AUTHOR
define|#
directive|define
name|COMMAND_AUTHOR
value|Doc::alias("author")
end_define
begin_define
DECL|macro|COMMAND_PUBLISHER
define|#
directive|define
name|COMMAND_PUBLISHER
value|Doc::alias("publisher")
end_define
begin_define
DECL|macro|COMMAND_COPYRYEAR
define|#
directive|define
name|COMMAND_COPYRYEAR
value|Doc::alias("copyryear")
end_define
begin_define
DECL|macro|COMMAND_COPYRHOLDER
define|#
directive|define
name|COMMAND_COPYRHOLDER
value|Doc::alias("copyrholder")
end_define
begin_define
DECL|macro|COMMAND_PERMISSIONS
define|#
directive|define
name|COMMAND_PERMISSIONS
value|Doc::alias("permissions")
end_define
begin_define
DECL|macro|COMMAND_LIFECYCLEVERSION
define|#
directive|define
name|COMMAND_LIFECYCLEVERSION
value|Doc::alias("lifecycleversion")
end_define
begin_define
DECL|macro|COMMAND_LIFECYCLEWSTATUS
define|#
directive|define
name|COMMAND_LIFECYCLEWSTATUS
value|Doc::alias("lifecyclestatus")
end_define
begin_define
DECL|macro|COMMAND_LICENSEYEAR
define|#
directive|define
name|COMMAND_LICENSEYEAR
value|Doc::alias("licenseyear")
end_define
begin_define
DECL|macro|COMMAND_LICENSENAME
define|#
directive|define
name|COMMAND_LICENSENAME
value|Doc::alias("licensename")
end_define
begin_define
DECL|macro|COMMAND_LICENSEDESCRIPTION
define|#
directive|define
name|COMMAND_LICENSEDESCRIPTION
value|Doc::alias("licensedescription")
end_define
begin_define
DECL|macro|COMMAND_RELEASEDATE
define|#
directive|define
name|COMMAND_RELEASEDATE
value|Doc::alias("releasedate")
end_define
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
