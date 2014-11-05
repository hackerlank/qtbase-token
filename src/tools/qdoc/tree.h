begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   tree.h */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TREE_H
end_ifndef
begin_define
DECL|macro|TREE_H
define|#
directive|define
name|TREE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstack.h>
end_include
begin_include
include|#
directive|include
file|"node.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDocDatabase
name|class
name|QDocDatabase
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|TargetRec
struct|struct
name|TargetRec
block|{
DECL|member|public
name|public
label|:
DECL|member|Target
DECL|member|Keyword
DECL|member|Contents
DECL|member|Class
DECL|member|Function
DECL|member|Page
enum|enum
name|Type
block|{
name|Unknown
block|,
name|Target
block|,
name|Keyword
block|,
name|Contents
block|,
name|Class
block|,
name|Function
block|,
name|Page
block|,
name|Subtitle
block|}
enum|;
DECL|function|TargetRec
name|TargetRec
argument_list|(
argument|const QString& name
argument_list|,
argument|const QString& title
argument_list|,
argument|TargetRec::Type type
argument_list|,
argument|Node* node
argument_list|,
argument|int priority
argument_list|)
block|:
name|node_
argument_list|(
name|node
argument_list|)
operator|,
name|ref_
argument_list|(
name|name
argument_list|)
operator|,
name|title_
argument_list|(
name|title
argument_list|)
operator|,
name|priority_
argument_list|(
name|priority
argument_list|)
operator|,
name|type_
argument_list|(
argument|type
argument_list|)
block|{ }
DECL|function|isEmpty
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|ref_
operator|.
name|isEmpty
argument_list|()
return|;
block|}
DECL|variable|node_
name|Node
modifier|*
name|node_
decl_stmt|;
DECL|variable|ref_
name|QString
name|ref_
decl_stmt|;
DECL|variable|title_
name|QString
name|title_
decl_stmt|;
DECL|variable|priority_
name|int
name|priority_
decl_stmt|;
DECL|variable|type_
name|Type
name|type_
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
struct|struct
name|TargetLoc
block|{
name|public
label|:
name|TargetLoc
argument_list|(
argument|const QString& t
argument_list|,
argument|const QString& fileName
argument_list|,
argument|const QString& text
argument_list|,
argument|bool broken = false
argument_list|)
block|:
name|target_
argument_list|(
name|t
argument_list|)
operator|,
name|fileName_
argument_list|(
name|fileName
argument_list|)
operator|,
name|text_
argument_list|(
name|text
argument_list|)
operator|,
name|broken_
argument_list|(
argument|broken
argument_list|)
block|{ }
name|QString
name|target_
expr_stmt|;
name|QString
name|fileName_
decl_stmt|;
name|QString
name|text_
decl_stmt|;
name|bool
name|broken_
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
typedef|typedef
name|QMultiMap
operator|<
name|QString
operator|,
name|TargetRec
operator|*
operator|>
name|TargetMap
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|QMultiMap
operator|<
name|QString
operator|,
name|DocNode
operator|*
operator|>
name|DocNodeMultiMap
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|QmlClassNode
operator|*
operator|>
name|QmlTypeMap
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|QMultiMap
operator|<
name|QString
operator|,
specifier|const
name|ExampleNode
operator|*
operator|>
name|ExampleNodeMap
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|QVector
operator|<
name|TargetLoc
operator|*
operator|>
name|TargetList
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|TargetList
operator|*
operator|>
name|TargetListMap
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|Tree
block|{
name|private
label|:
name|friend
name|class
name|QDocForest
decl_stmt|;
name|friend
name|class
name|QDocDatabase
decl_stmt|;
typedef|typedef
name|QMap
operator|<
name|PropertyNode
operator|::
name|FunctionRole
operator|,
name|QString
operator|>
name|RoleMap
expr_stmt|;
typedef|typedef
name|QMap
operator|<
name|PropertyNode
operator|*
operator|,
name|RoleMap
operator|>
name|PropertyMap
expr_stmt|;
name|Tree
argument_list|(
specifier|const
name|QString
operator|&
name|module
argument_list|,
name|QDocDatabase
operator|*
name|qdb
argument_list|)
expr_stmt|;
operator|~
name|Tree
argument_list|()
expr_stmt|;
name|Node
modifier|*
name|findNodeForInclude
argument_list|(
specifier|const
name|QStringList
operator|&
name|path
argument_list|)
decl|const
decl_stmt|;
name|ClassNode
modifier|*
name|findClassNode
argument_list|(
specifier|const
name|QStringList
operator|&
name|path
argument_list|,
specifier|const
name|Node
operator|*
name|start
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|NamespaceNode
modifier|*
name|findNamespaceNode
argument_list|(
specifier|const
name|QStringList
operator|&
name|path
argument_list|)
decl|const
decl_stmt|;
name|FunctionNode
modifier|*
name|findFunctionNode
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|parentPath
parameter_list|,
specifier|const
name|FunctionNode
modifier|*
name|clone
parameter_list|)
function_decl|;
specifier|const
name|Node
modifier|*
name|findFunctionNode
argument_list|(
specifier|const
name|QString
operator|&
name|target
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|Node
operator|::
name|Genus
name|genus
argument_list|)
decl_stmt|;
name|Node
modifier|*
name|findNodeRecursive
argument_list|(
specifier|const
name|QStringList
operator|&
name|path
argument_list|,
name|int
name|pathIndex
argument_list|,
specifier|const
name|Node
operator|*
name|start
argument_list|,
name|Node
operator|::
name|Type
name|type
argument_list|)
decl|const
decl_stmt|;
name|Node
modifier|*
name|findNodeRecursive
argument_list|(
specifier|const
name|QStringList
operator|&
name|path
argument_list|,
name|int
name|pathIndex
argument_list|,
name|Node
operator|*
name|start
argument_list|,
specifier|const
name|NodeTypeList
operator|&
name|types
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|Node
modifier|*
name|findNodeForTarget
argument_list|(
specifier|const
name|QStringList
operator|&
name|path
argument_list|,
specifier|const
name|QString
operator|&
name|target
argument_list|,
specifier|const
name|Node
operator|*
name|node
argument_list|,
name|int
name|flags
argument_list|,
name|Node
operator|::
name|Genus
name|genus
argument_list|,
name|QString
operator|&
name|ref
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|Node
modifier|*
name|matchPathAndTarget
argument_list|(
specifier|const
name|QStringList
operator|&
name|path
argument_list|,
name|int
name|idx
argument_list|,
specifier|const
name|QString
operator|&
name|target
argument_list|,
specifier|const
name|Node
operator|*
name|node
argument_list|,
name|int
name|flags
argument_list|,
name|Node
operator|::
name|Genus
name|genus
argument_list|,
name|QString
operator|&
name|ref
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|Node
modifier|*
name|findNode
argument_list|(
specifier|const
name|QStringList
operator|&
name|path
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
comment|// = 0,
name|int
name|findFlags
argument_list|,
comment|// = 0,
name|Node
operator|::
name|Genus
name|genus
argument_list|)
decl|const
decl_stmt|;
comment|// = Node::DontCare) const;
name|QmlClassNode
modifier|*
name|findQmlTypeNode
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|path
parameter_list|)
function_decl|;
name|Node
modifier|*
name|findNodeByNameAndType
argument_list|(
specifier|const
name|QStringList
operator|&
name|path
argument_list|,
name|Node
operator|::
name|Type
name|type
argument_list|)
decl|const
decl_stmt|;
name|InnerNode
modifier|*
name|findRelatesNode
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|path
parameter_list|)
function_decl|;
name|QString
name|getRef
argument_list|(
specifier|const
name|QString
operator|&
name|target
argument_list|,
specifier|const
name|Node
operator|*
name|node
argument_list|)
decl|const
decl_stmt|;
name|void
name|insertTarget
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QString
operator|&
name|title
argument_list|,
name|TargetRec
operator|::
name|Type
name|type
argument_list|,
name|Node
operator|*
name|node
argument_list|,
name|int
name|priority
argument_list|)
decl_stmt|;
name|void
name|resolveTargets
parameter_list|(
name|InnerNode
modifier|*
name|root
parameter_list|)
function_decl|;
specifier|const
name|Node
modifier|*
name|findUnambiguousTarget
argument_list|(
specifier|const
name|QString
operator|&
name|target
argument_list|,
name|QString
operator|&
name|ref
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|DocNode
modifier|*
name|findDocNodeByTitle
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|)
decl|const
decl_stmt|;
name|void
name|addPropertyFunction
argument_list|(
name|PropertyNode
operator|*
name|property
argument_list|,
specifier|const
name|QString
operator|&
name|funcName
argument_list|,
name|PropertyNode
operator|::
name|FunctionRole
name|funcRole
argument_list|)
decl_stmt|;
name|void
name|resolveInheritance
parameter_list|(
name|InnerNode
modifier|*
name|n
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|resolveInheritanceHelper
parameter_list|(
name|int
name|pass
parameter_list|,
name|ClassNode
modifier|*
name|cn
parameter_list|)
function_decl|;
name|void
name|resolveProperties
parameter_list|()
function_decl|;
name|void
name|resolveCppToQmlLinks
parameter_list|()
function_decl|;
name|void
name|fixInheritance
parameter_list|(
name|NamespaceNode
modifier|*
name|rootNode
init|=
literal|0
parameter_list|)
function_decl|;
name|NamespaceNode
modifier|*
name|root
parameter_list|()
block|{
return|return
operator|&
name|root_
return|;
block|}
specifier|const
name|FunctionNode
modifier|*
name|findFunctionNode
argument_list|(
specifier|const
name|QStringList
operator|&
name|path
argument_list|,
specifier|const
name|Node
operator|*
name|relative
operator|=
literal|0
argument_list|,
name|int
name|findFlags
operator|=
literal|0
argument_list|,
name|Node
operator|::
name|Genus
name|genus
operator|=
name|Node
operator|::
name|DontCare
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|NamespaceNode
operator|*
name|root
argument_list|()
specifier|const
block|{
return|return
operator|&
name|root_
return|;
block|}
name|FunctionNode
modifier|*
name|findVirtualFunctionInBaseClasses
parameter_list|(
name|ClassNode
modifier|*
name|classe
parameter_list|,
name|FunctionNode
modifier|*
name|clone
parameter_list|)
function_decl|;
name|NodeList
name|allBaseClasses
argument_list|(
specifier|const
name|ClassNode
operator|*
name|classe
argument_list|)
decl|const
decl_stmt|;
name|QString
name|refForAtom
parameter_list|(
specifier|const
name|Atom
modifier|*
name|atom
parameter_list|)
function_decl|;
specifier|const
name|CNMap
operator|&
name|groups
argument_list|()
specifier|const
block|{
return|return
name|groups_
return|;
block|}
specifier|const
name|CNMap
operator|&
name|modules
argument_list|()
specifier|const
block|{
return|return
name|modules_
return|;
block|}
specifier|const
name|CNMap
operator|&
name|qmlModules
argument_list|()
specifier|const
block|{
return|return
name|qmlModules_
return|;
block|}
specifier|const
name|CNMap
modifier|&
name|getCollections
argument_list|(
name|Node
operator|::
name|Type
name|t
argument_list|)
decl|const
block|{
if|if
condition|(
name|t
operator|==
name|Node
operator|::
name|Group
condition|)
return|return
name|groups_
return|;
if|if
condition|(
name|t
operator|==
name|Node
operator|::
name|Module
condition|)
return|return
name|modules_
return|;
return|return
name|qmlModules_
return|;
block|}
name|CollectionNode
modifier|*
name|getCorrespondingCollection
parameter_list|(
name|CollectionNode
modifier|*
name|cn
parameter_list|)
function_decl|;
name|GroupNode
modifier|*
name|getGroup
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|ModuleNode
modifier|*
name|getModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|QmlModuleNode
modifier|*
name|getQmlModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|GroupNode
modifier|*
name|findGroup
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|ModuleNode
modifier|*
name|findModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|QmlModuleNode
modifier|*
name|findQmlModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|GroupNode
modifier|*
name|addGroup
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|ModuleNode
modifier|*
name|addModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|QmlModuleNode
modifier|*
name|addQmlModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|GroupNode
modifier|*
name|addToGroup
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
name|ModuleNode
modifier|*
name|addToModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
name|QmlModuleNode
modifier|*
name|addToQmlModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
name|QmlClassNode
modifier|*
name|lookupQmlType
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
block|{
return|return
name|qmlTypeMap_
operator|.
name|value
argument_list|(
name|name
argument_list|)
return|;
block|}
name|void
name|insertQmlType
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
name|QmlClassNode
modifier|*
name|n
parameter_list|)
function_decl|;
name|void
name|addExampleNode
parameter_list|(
name|ExampleNode
modifier|*
name|n
parameter_list|)
block|{
name|exampleNodeMap_
operator|.
name|insert
argument_list|(
name|n
operator|->
name|title
argument_list|()
argument_list|,
name|n
argument_list|)
expr_stmt|;
block|}
name|ExampleNodeMap
modifier|&
name|exampleNodeMap
parameter_list|()
block|{
return|return
name|exampleNodeMap_
return|;
block|}
specifier|const
name|Node
modifier|*
name|checkForCollision
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|void
name|setIndexFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|t
parameter_list|)
block|{
name|indexFileName_
operator|=
name|t
expr_stmt|;
block|}
name|bool
name|treeHasBeenAnalyzed
argument_list|()
specifier|const
block|{
return|return
name|treeHasBeenAnalyzed_
return|;
block|}
name|bool
name|docsHaveBeenGenerated
argument_list|()
specifier|const
block|{
return|return
name|docsHaveBeenGenerated_
return|;
block|}
name|void
name|setTreeHasBeenAnalyzed
parameter_list|()
block|{
name|treeHasBeenAnalyzed_
operator|=
name|true
expr_stmt|;
block|}
name|void
name|setdocsHaveBeenGenerated
parameter_list|()
block|{
name|docsHaveBeenGenerated_
operator|=
name|true
expr_stmt|;
block|}
name|QString
name|getNewLinkTarget
parameter_list|(
specifier|const
name|Node
modifier|*
name|t
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|QString
modifier|&
name|text
parameter_list|,
name|bool
name|broken
parameter_list|)
function_decl|;
name|TargetList
modifier|*
name|getTargetList
parameter_list|(
specifier|const
name|QString
modifier|&
name|module
parameter_list|)
function_decl|;
name|QStringList
name|getTargetListKeys
parameter_list|()
block|{
return|return
name|targetListMap_
operator|->
name|keys
argument_list|()
return|;
block|}
name|public
label|:
specifier|const
name|QString
operator|&
name|moduleName
argument_list|()
specifier|const
block|{
return|return
name|module_
return|;
block|}
specifier|const
name|QString
operator|&
name|indexFileName
argument_list|()
specifier|const
block|{
return|return
name|indexFileName_
return|;
block|}
name|long
name|incrementLinkCount
parameter_list|()
block|{
return|return
operator|--
name|linkCount_
return|;
block|}
name|void
name|clearLinkCount
parameter_list|()
block|{
name|linkCount_
operator|=
literal|0
expr_stmt|;
block|}
name|long
name|linkCount
argument_list|()
specifier|const
block|{
return|return
name|linkCount_
return|;
block|}
name|private
label|:
name|bool
name|treeHasBeenAnalyzed_
decl_stmt|;
name|bool
name|docsHaveBeenGenerated_
decl_stmt|;
name|long
name|linkCount_
decl_stmt|;
name|QString
name|module_
decl_stmt|;
name|QString
name|indexFileName_
decl_stmt|;
name|QDocDatabase
modifier|*
name|qdb_
decl_stmt|;
name|NamespaceNode
name|root_
decl_stmt|;
name|PropertyMap
name|unresolvedPropertyMap
decl_stmt|;
name|DocNodeMultiMap
name|docNodesByTitle_
decl_stmt|;
name|TargetMap
name|nodesByTargetRef_
decl_stmt|;
name|TargetMap
name|nodesByTargetTitle_
decl_stmt|;
name|CNMap
name|groups_
decl_stmt|;
name|CNMap
name|modules_
decl_stmt|;
name|CNMap
name|qmlModules_
decl_stmt|;
name|QmlTypeMap
name|qmlTypeMap_
decl_stmt|;
name|ExampleNodeMap
name|exampleNodeMap_
decl_stmt|;
name|TargetListMap
modifier|*
name|targetListMap_
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
end_unit
