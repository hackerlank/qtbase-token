begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qbsptree_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QBspTree
name|QBspTree
operator|::
name|QBspTree
parameter_list|()
member_init_list|:
name|depth
argument_list|(
literal|6
argument_list|)
member_init_list|,
name|visited
argument_list|(
literal|0
argument_list|)
block|{}
end_constructor
begin_function
DECL|function|create
name|void
name|QBspTree
operator|::
name|create
parameter_list|(
name|int
name|n
parameter_list|,
name|int
name|d
parameter_list|)
block|{
comment|// simple heuristics to find the best tree depth
if|if
condition|(
name|d
operator|==
operator|-
literal|1
condition|)
block|{
name|int
name|c
decl_stmt|;
for|for
control|(
name|c
operator|=
literal|0
init|;
name|n
condition|;
operator|++
name|c
control|)
name|n
operator|=
name|n
operator|/
literal|10
expr_stmt|;
name|depth
operator|=
name|c
operator|<<
literal|1
expr_stmt|;
block|}
else|else
block|{
name|depth
operator|=
name|d
expr_stmt|;
block|}
name|depth
operator|=
name|qMax
argument_list|(
name|depth
argument_list|,
name|uint
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|nodes
operator|.
name|resize
argument_list|(
operator|(
literal|1
operator|<<
name|depth
operator|)
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// resize to number of nodes
name|leaves
operator|.
name|resize
argument_list|(
literal|1
operator|<<
name|depth
argument_list|)
expr_stmt|;
comment|// resize to number of leaves
block|}
end_function
begin_function
DECL|function|destroy
name|void
name|QBspTree
operator|::
name|destroy
parameter_list|()
block|{
name|leaves
operator|.
name|clear
argument_list|()
expr_stmt|;
name|nodes
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|climbTree
name|void
name|QBspTree
operator|::
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
block|{
if|if
condition|(
name|nodes
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
operator|++
name|visited
expr_stmt|;
name|climbTree
argument_list|(
name|rect
argument_list|,
name|function
argument_list|,
name|data
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|climbTree
name|void
name|QBspTree
operator|::
name|climbTree
parameter_list|(
specifier|const
name|QRect
modifier|&
name|area
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
block|{
if|if
condition|(
name|index
operator|>=
name|nodes
operator|.
name|count
argument_list|()
condition|)
block|{
comment|// the index points to a leaf
name|Q_ASSERT
argument_list|(
operator|!
name|nodes
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|function
argument_list|(
name|leaf
argument_list|(
name|index
operator|-
name|nodes
operator|.
name|count
argument_list|()
argument_list|)
argument_list|,
name|area
argument_list|,
name|visited
argument_list|,
name|data
argument_list|)
expr_stmt|;
return|return;
block|}
name|Node
operator|::
name|Type
name|t
init|=
operator|(
name|Node
operator|::
name|Type
operator|)
name|nodes
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|.
name|type
decl_stmt|;
name|int
name|pos
init|=
name|nodes
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|.
name|pos
decl_stmt|;
name|int
name|idx
init|=
name|firstChildIndex
argument_list|(
name|index
argument_list|)
decl_stmt|;
if|if
condition|(
name|t
operator|==
name|Node
operator|::
name|VerticalPlane
condition|)
block|{
if|if
condition|(
name|area
operator|.
name|left
argument_list|()
operator|<
name|pos
condition|)
name|climbTree
argument_list|(
name|area
argument_list|,
name|function
argument_list|,
name|data
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// back
if|if
condition|(
name|area
operator|.
name|right
argument_list|()
operator|>=
name|pos
condition|)
name|climbTree
argument_list|(
name|area
argument_list|,
name|function
argument_list|,
name|data
argument_list|,
name|idx
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|// front
block|}
else|else
block|{
if|if
condition|(
name|area
operator|.
name|top
argument_list|()
operator|<
name|pos
condition|)
name|climbTree
argument_list|(
name|area
argument_list|,
name|function
argument_list|,
name|data
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// back
if|if
condition|(
name|area
operator|.
name|bottom
argument_list|()
operator|>=
name|pos
condition|)
name|climbTree
argument_list|(
name|area
argument_list|,
name|function
argument_list|,
name|data
argument_list|,
name|idx
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|// front
block|}
block|}
end_function
begin_function
DECL|function|init
name|void
name|QBspTree
operator|::
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
block|{
name|Node
operator|::
name|Type
name|t
init|=
name|Node
operator|::
name|None
decl_stmt|;
comment|// t should never have this value
if|if
condition|(
name|type
operator|==
name|Node
operator|::
name|Both
condition|)
comment|// if both planes are specified, use 2d bsp
name|t
operator|=
operator|(
name|depth
operator|&
literal|1
operator|)
condition|?
name|Node
operator|::
name|HorizontalPlane
else|:
name|Node
operator|::
name|VerticalPlane
expr_stmt|;
else|else
name|t
operator|=
name|type
expr_stmt|;
name|QPoint
name|center
init|=
name|area
operator|.
name|center
argument_list|()
decl_stmt|;
name|nodes
index|[
name|index
index|]
operator|.
name|pos
operator|=
operator|(
name|t
operator|==
name|Node
operator|::
name|VerticalPlane
condition|?
name|center
operator|.
name|x
argument_list|()
else|:
name|center
operator|.
name|y
argument_list|()
operator|)
expr_stmt|;
name|nodes
index|[
name|index
index|]
operator|.
name|type
operator|=
name|t
expr_stmt|;
name|QRect
name|front
init|=
name|area
decl_stmt|;
name|QRect
name|back
init|=
name|area
decl_stmt|;
if|if
condition|(
name|t
operator|==
name|Node
operator|::
name|VerticalPlane
condition|)
block|{
name|front
operator|.
name|setLeft
argument_list|(
name|center
operator|.
name|x
argument_list|()
argument_list|)
expr_stmt|;
name|back
operator|.
name|setRight
argument_list|(
name|center
operator|.
name|x
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// front includes the center
block|}
else|else
block|{
comment|// t == Node::HorizontalPlane
name|front
operator|.
name|setTop
argument_list|(
name|center
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|back
operator|.
name|setBottom
argument_list|(
name|center
operator|.
name|y
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|int
name|idx
init|=
name|firstChildIndex
argument_list|(
name|index
argument_list|)
decl_stmt|;
if|if
condition|(
operator|--
name|depth
condition|)
block|{
name|init
argument_list|(
name|back
argument_list|,
name|depth
argument_list|,
name|type
argument_list|,
name|idx
argument_list|)
expr_stmt|;
name|init
argument_list|(
name|front
argument_list|,
name|depth
argument_list|,
name|type
argument_list|,
name|idx
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|insert
name|void
name|QBspTree
operator|::
name|insert
parameter_list|(
name|QVector
argument_list|<
name|int
argument_list|>
modifier|&
name|leaf
parameter_list|,
specifier|const
name|QRect
modifier|&
parameter_list|,
name|uint
parameter_list|,
name|QBspTreeData
name|data
parameter_list|)
block|{
name|leaf
operator|.
name|append
argument_list|(
name|data
operator|.
name|i
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|remove
name|void
name|QBspTree
operator|::
name|remove
parameter_list|(
name|QVector
argument_list|<
name|int
argument_list|>
modifier|&
name|leaf
parameter_list|,
specifier|const
name|QRect
modifier|&
parameter_list|,
name|uint
parameter_list|,
name|QBspTreeData
name|data
parameter_list|)
block|{
name|int
name|i
init|=
name|leaf
operator|.
name|indexOf
argument_list|(
name|data
operator|.
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|i
operator|!=
operator|-
literal|1
condition|)
name|leaf
operator|.
name|remove
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
