begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_decl_stmt
name|class
name|Tree
block|{
name|private
label|:
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
name|QDocDatabase
operator|*
name|qdb
argument_list|)
expr_stmt|;
operator|~
name|Tree
argument_list|()
expr_stmt|;
comment|/* API members */
name|ClassNode
modifier|*
name|findClassNode
argument_list|(
specifier|const
name|QStringList
operator|&
name|path
argument_list|,
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
comment|/* internal members */
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
name|Node
operator|::
name|Type
name|type
argument_list|,
name|Node
operator|::
name|SubType
name|subtype
argument_list|,
name|bool
name|acceptCollision
operator|=
name|false
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
operator|=
literal|0
argument_list|,
name|int
name|findFlags
operator|=
literal|0
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
name|start
argument_list|,
name|int
name|findFlags
argument_list|,
name|bool
name|qml
argument_list|)
decl|const
decl_stmt|;
comment|// ---------------------------------------------------------------------
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
argument_list|,
name|Node
operator|::
name|SubType
name|subtype
argument_list|,
name|Node
operator|*
name|start
argument_list|,
name|bool
name|acceptCollision
operator|=
name|false
argument_list|)
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
name|NameCollisionNode
modifier|*
name|checkForCollision
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|NameCollisionNode
modifier|*
name|findCollisionNode
argument_list|(
specifier|const
name|QString
operator|&
name|name
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
name|public
label|:
specifier|static
name|bool
name|debug_
decl_stmt|;
name|private
label|:
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
