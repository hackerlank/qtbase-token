begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBSPTREE_P_H
end_ifndef
begin_define
DECL|macro|QBSPTREE_P_H
define|#
directive|define
name|QBSPTREE_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
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
file|<qvector.h>
end_include
begin_include
include|#
directive|include
file|<qrect.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QBspTree
block|{
name|public
label|:
struct|struct
name|Node
block|{
enum|enum
name|Type
block|{
name|None
init|=
literal|0
block|,
name|VerticalPlane
init|=
literal|1
block|,
name|HorizontalPlane
init|=
literal|2
block|,
name|Both
init|=
literal|3
block|}
enum|;
specifier|inline
name|Node
argument_list|()
operator|:
name|pos
argument_list|(
literal|0
argument_list|)
operator|,
name|type
argument_list|(
argument|None
argument_list|)
block|{}
name|int
name|pos
expr_stmt|;
name|Type
name|type
decl_stmt|;
block|}
struct|;
typedef|typedef
name|Node
operator|::
name|Type
name|NodeType
expr_stmt|;
struct|struct
name|Data
block|{
name|Data
argument_list|(
name|void
operator|*
name|p
argument_list|)
operator|:
name|ptr
argument_list|(
argument|p
argument_list|)
block|{}
name|Data
argument_list|(
argument|int n
argument_list|)
operator|:
name|i
argument_list|(
argument|n
argument_list|)
block|{}
expr|union
block|{
name|void
operator|*
name|ptr
block|;
name|int
name|i
block|;         }
expr_stmt|;
block|}
struct|;
typedef|typedef
name|QBspTree
operator|::
name|Data
name|QBspTreeData
expr_stmt|;
typedef|typedef
name|void
name|callback
argument_list|(
name|QVector
operator|<
name|int
operator|>
operator|&
name|leaf
argument_list|,
specifier|const
name|QRect
operator|&
name|area
argument_list|,
name|uint
name|visited
argument_list|,
name|QBspTreeData
name|data
argument_list|)
typedef|;
name|QBspTree
argument_list|()
expr_stmt|;
name|void
name|create
parameter_list|(
name|int
name|n
parameter_list|,
name|int
name|d
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
name|void
name|destroy
parameter_list|()
function_decl|;
specifier|inline
name|void
name|init
parameter_list|(
specifier|const
name|QRect
modifier|&
name|area
parameter_list|,
name|NodeType
name|type
parameter_list|)
block|{
name|init
argument_list|(
name|area
argument_list|,
name|depth
argument_list|,
name|type
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|void
name|climbTree
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|callback
modifier|*
name|function
parameter_list|,
name|QBspTreeData
name|data
parameter_list|)
function_decl|;
specifier|inline
name|int
name|leafCount
argument_list|()
specifier|const
block|{
return|return
name|leaves
operator|.
name|count
argument_list|()
return|;
block|}
specifier|inline
name|QVector
operator|<
name|int
operator|>
operator|&
name|leaf
argument_list|(
argument|int i
argument_list|)
block|{
return|return
name|leaves
index|[
name|i
index|]
return|;
block|}
specifier|inline
name|void
name|insertLeaf
parameter_list|(
specifier|const
name|QRect
modifier|&
name|r
parameter_list|,
name|int
name|i
parameter_list|)
block|{
name|climbTree
argument_list|(
name|r
argument_list|,
operator|&
name|insert
argument_list|,
name|i
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|removeLeaf
parameter_list|(
specifier|const
name|QRect
modifier|&
name|r
parameter_list|,
name|int
name|i
parameter_list|)
block|{
name|climbTree
argument_list|(
name|r
argument_list|,
operator|&
name|remove
argument_list|,
name|i
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|protected
label|:
name|void
name|init
parameter_list|(
specifier|const
name|QRect
modifier|&
name|area
parameter_list|,
name|int
name|depth
parameter_list|,
name|NodeType
name|type
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
name|void
name|climbTree
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|callback
modifier|*
name|function
parameter_list|,
name|QBspTreeData
name|data
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
specifier|inline
name|int
name|parentIndex
argument_list|(
name|int
name|i
argument_list|)
decl|const
block|{
return|return
operator|(
name|i
operator|&
literal|1
operator|)
condition|?
operator|(
operator|(
name|i
operator|-
literal|1
operator|)
operator|/
literal|2
operator|)
else|:
operator|(
operator|(
name|i
operator|-
literal|2
operator|)
operator|/
literal|2
operator|)
return|;
block|}
specifier|inline
name|int
name|firstChildIndex
argument_list|(
name|int
name|i
argument_list|)
decl|const
block|{
return|return
operator|(
operator|(
name|i
operator|*
literal|2
operator|)
operator|+
literal|1
operator|)
return|;
block|}
specifier|static
name|void
name|insert
argument_list|(
name|QVector
operator|<
name|int
operator|>
operator|&
name|leaf
argument_list|,
specifier|const
name|QRect
operator|&
name|area
argument_list|,
name|uint
name|visited
argument_list|,
name|QBspTreeData
name|data
argument_list|)
decl_stmt|;
specifier|static
name|void
name|remove
argument_list|(
name|QVector
operator|<
name|int
operator|>
operator|&
name|leaf
argument_list|,
specifier|const
name|QRect
operator|&
name|area
argument_list|,
name|uint
name|visited
argument_list|,
name|QBspTreeData
name|data
argument_list|)
decl_stmt|;
name|private
label|:
name|uint
name|depth
decl_stmt|;
name|mutable
name|uint
name|visited
decl_stmt|;
name|QVector
operator|<
name|Node
operator|>
name|nodes
expr_stmt|;
name|mutable
name|QVector
operator|<
name|QVector
operator|<
name|int
operator|>
expr|>
name|leaves
expr_stmt|;
comment|// the leaves are just indices into the items
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
comment|// QBSPTREE_P_H
end_comment
end_unit
