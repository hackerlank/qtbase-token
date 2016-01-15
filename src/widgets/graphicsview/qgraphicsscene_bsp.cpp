begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qgraphicsscene_bsp_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<private/qgraphicsitem_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QGraphicsSceneInsertItemBspTreeVisitor
class|class
name|QGraphicsSceneInsertItemBspTreeVisitor
super|:
specifier|public
name|QGraphicsSceneBspTreeVisitor
block|{
public|public:
DECL|member|item
name|QGraphicsItem
modifier|*
name|item
decl_stmt|;
name|void
name|visit
parameter_list|(
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
modifier|*
name|items
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|items
operator|->
name|prepend
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|QGraphicsSceneRemoveItemBspTreeVisitor
class|class
name|QGraphicsSceneRemoveItemBspTreeVisitor
super|:
specifier|public
name|QGraphicsSceneBspTreeVisitor
block|{
public|public:
DECL|member|item
name|QGraphicsItem
modifier|*
name|item
decl_stmt|;
name|void
name|visit
parameter_list|(
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
modifier|*
name|items
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|items
operator|->
name|removeAll
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|QGraphicsSceneFindItemBspTreeVisitor
class|class
name|QGraphicsSceneFindItemBspTreeVisitor
super|:
specifier|public
name|QGraphicsSceneBspTreeVisitor
block|{
public|public:
DECL|member|foundItems
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
modifier|*
name|foundItems
decl_stmt|;
DECL|member|onlyTopLevelItems
name|bool
name|onlyTopLevelItems
decl_stmt|;
name|void
name|visit
parameter_list|(
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
modifier|*
name|items
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|items
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QGraphicsItem
modifier|*
name|item
init|=
name|items
operator|->
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|onlyTopLevelItems
operator|&&
name|item
operator|->
name|d_ptr
operator|->
name|parent
condition|)
name|item
operator|=
name|item
operator|->
name|topLevelItem
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|item
operator|->
name|d_func
argument_list|()
operator|->
name|itemDiscovered
operator|&&
name|item
operator|->
name|d_ptr
operator|->
name|visible
condition|)
block|{
name|item
operator|->
name|d_func
argument_list|()
operator|->
name|itemDiscovered
operator|=
literal|1
expr_stmt|;
name|foundItems
operator|->
name|prepend
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
class|;
end_class
begin_constructor
DECL|function|QGraphicsSceneBspTree
name|QGraphicsSceneBspTree
operator|::
name|QGraphicsSceneBspTree
parameter_list|()
member_init_list|:
name|leafCnt
argument_list|(
literal|0
argument_list|)
block|{
name|insertVisitor
operator|=
operator|new
name|QGraphicsSceneInsertItemBspTreeVisitor
expr_stmt|;
name|removeVisitor
operator|=
operator|new
name|QGraphicsSceneRemoveItemBspTreeVisitor
expr_stmt|;
name|findVisitor
operator|=
operator|new
name|QGraphicsSceneFindItemBspTreeVisitor
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QGraphicsSceneBspTree
name|QGraphicsSceneBspTree
operator|::
name|~
name|QGraphicsSceneBspTree
parameter_list|()
block|{
operator|delete
name|insertVisitor
expr_stmt|;
operator|delete
name|removeVisitor
expr_stmt|;
operator|delete
name|findVisitor
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|initialize
name|void
name|QGraphicsSceneBspTree
operator|::
name|initialize
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|int
name|depth
parameter_list|)
block|{
name|this
operator|->
name|rect
operator|=
name|rect
expr_stmt|;
name|leafCnt
operator|=
literal|0
expr_stmt|;
name|nodes
operator|.
name|resize
argument_list|(
operator|(
literal|1
operator|<<
operator|(
name|depth
operator|+
literal|1
operator|)
operator|)
operator|-
literal|1
argument_list|)
expr_stmt|;
name|nodes
operator|.
name|fill
argument_list|(
name|Node
argument_list|()
argument_list|)
expr_stmt|;
name|leaves
operator|.
name|resize
argument_list|(
literal|1
operator|<<
name|depth
argument_list|)
expr_stmt|;
name|leaves
operator|.
name|fill
argument_list|(
name|QList
argument_list|<
name|QGraphicsItem
operator|*
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|initialize
argument_list|(
name|rect
argument_list|,
name|depth
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clear
name|void
name|QGraphicsSceneBspTree
operator|::
name|clear
parameter_list|()
block|{
name|leafCnt
operator|=
literal|0
expr_stmt|;
name|nodes
operator|.
name|clear
argument_list|()
expr_stmt|;
name|leaves
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insertItem
name|void
name|QGraphicsSceneBspTree
operator|::
name|insertItem
parameter_list|(
name|QGraphicsItem
modifier|*
name|item
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
block|{
name|insertVisitor
operator|->
name|item
operator|=
name|item
expr_stmt|;
name|climbTree
argument_list|(
name|insertVisitor
argument_list|,
name|rect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeItem
name|void
name|QGraphicsSceneBspTree
operator|::
name|removeItem
parameter_list|(
name|QGraphicsItem
modifier|*
name|item
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
block|{
name|removeVisitor
operator|->
name|item
operator|=
name|item
expr_stmt|;
name|climbTree
argument_list|(
name|removeVisitor
argument_list|,
name|rect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeItems
name|void
name|QGraphicsSceneBspTree
operator|::
name|removeItems
parameter_list|(
specifier|const
name|QSet
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
modifier|&
name|items
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|leaves
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
name|newItemList
decl_stmt|;
specifier|const
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
modifier|&
name|oldItemList
init|=
name|leaves
index|[
name|i
index|]
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|oldItemList
operator|.
name|size
argument_list|()
condition|;
operator|++
name|j
control|)
block|{
name|QGraphicsItem
modifier|*
name|item
init|=
name|oldItemList
operator|.
name|at
argument_list|(
name|j
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|items
operator|.
name|contains
argument_list|(
name|item
argument_list|)
condition|)
name|newItemList
operator|<<
name|item
expr_stmt|;
block|}
name|leaves
index|[
name|i
index|]
operator|=
name|newItemList
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|items
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
name|QGraphicsSceneBspTree
operator|::
name|items
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|bool
name|onlyTopLevelItems
parameter_list|)
specifier|const
block|{
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
name|tmp
decl_stmt|;
name|findVisitor
operator|->
name|foundItems
operator|=
operator|&
name|tmp
expr_stmt|;
name|findVisitor
operator|->
name|onlyTopLevelItems
operator|=
name|onlyTopLevelItems
expr_stmt|;
name|climbTree
argument_list|(
name|findVisitor
argument_list|,
name|rect
argument_list|)
expr_stmt|;
comment|// Reset discovery bits.
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|tmp
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|tmp
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|d_ptr
operator|->
name|itemDiscovered
operator|=
literal|0
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_function
begin_function
DECL|function|leafCount
name|int
name|QGraphicsSceneBspTree
operator|::
name|leafCount
parameter_list|()
specifier|const
block|{
return|return
name|leafCnt
return|;
block|}
end_function
begin_function
DECL|function|debug
name|QString
name|QGraphicsSceneBspTree
operator|::
name|debug
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
specifier|const
name|Node
modifier|*
name|node
init|=
operator|&
name|nodes
operator|.
name|at
argument_list|(
name|index
argument_list|)
decl_stmt|;
name|QString
name|tmp
decl_stmt|;
if|if
condition|(
name|node
operator|->
name|type
operator|==
name|Node
operator|::
name|Leaf
condition|)
block|{
name|QRectF
name|rect
init|=
name|rectForIndex
argument_list|(
name|index
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|leaves
index|[
name|node
operator|->
name|leafIndex
index|]
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|tmp
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"[%1, %2, %3, %4] contains %5 items\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|rect
operator|.
name|left
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|rect
operator|.
name|top
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|rect
operator|.
name|width
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|rect
operator|.
name|height
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|leaves
index|[
name|node
operator|->
name|leafIndex
index|]
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|node
operator|->
name|type
operator|==
name|Node
operator|::
name|Horizontal
condition|)
block|{
name|tmp
operator|+=
name|debug
argument_list|(
name|firstChildIndex
argument_list|(
name|index
argument_list|)
argument_list|)
expr_stmt|;
name|tmp
operator|+=
name|debug
argument_list|(
name|firstChildIndex
argument_list|(
name|index
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|tmp
operator|+=
name|debug
argument_list|(
name|firstChildIndex
argument_list|(
name|index
argument_list|)
argument_list|)
expr_stmt|;
name|tmp
operator|+=
name|debug
argument_list|(
name|firstChildIndex
argument_list|(
name|index
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|tmp
return|;
block|}
end_function
begin_function
DECL|function|initialize
name|void
name|QGraphicsSceneBspTree
operator|::
name|initialize
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|int
name|depth
parameter_list|,
name|int
name|index
parameter_list|)
block|{
name|Node
modifier|*
name|node
init|=
operator|&
name|nodes
index|[
name|index
index|]
decl_stmt|;
if|if
condition|(
name|index
operator|==
literal|0
condition|)
block|{
name|node
operator|->
name|type
operator|=
name|Node
operator|::
name|Horizontal
expr_stmt|;
name|node
operator|->
name|offset
operator|=
name|rect
operator|.
name|center
argument_list|()
operator|.
name|x
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|depth
condition|)
block|{
name|Node
operator|::
name|Type
name|type
decl_stmt|;
name|QRectF
name|rect1
decl_stmt|,
name|rect2
decl_stmt|;
name|qreal
name|offset1
decl_stmt|,
name|offset2
decl_stmt|;
if|if
condition|(
name|node
operator|->
name|type
operator|==
name|Node
operator|::
name|Horizontal
condition|)
block|{
name|type
operator|=
name|Node
operator|::
name|Vertical
expr_stmt|;
name|rect1
operator|.
name|setRect
argument_list|(
name|rect
operator|.
name|left
argument_list|()
argument_list|,
name|rect
operator|.
name|top
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|rect2
operator|.
name|setRect
argument_list|(
name|rect1
operator|.
name|left
argument_list|()
argument_list|,
name|rect1
operator|.
name|bottom
argument_list|()
argument_list|,
name|rect1
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
operator|-
name|rect1
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|offset1
operator|=
name|rect1
operator|.
name|center
argument_list|()
operator|.
name|x
argument_list|()
expr_stmt|;
name|offset2
operator|=
name|rect2
operator|.
name|center
argument_list|()
operator|.
name|x
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|type
operator|=
name|Node
operator|::
name|Horizontal
expr_stmt|;
name|rect1
operator|.
name|setRect
argument_list|(
name|rect
operator|.
name|left
argument_list|()
argument_list|,
name|rect
operator|.
name|top
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|rect2
operator|.
name|setRect
argument_list|(
name|rect1
operator|.
name|right
argument_list|()
argument_list|,
name|rect1
operator|.
name|top
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
operator|-
name|rect1
operator|.
name|width
argument_list|()
argument_list|,
name|rect1
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|offset1
operator|=
name|rect1
operator|.
name|center
argument_list|()
operator|.
name|y
argument_list|()
expr_stmt|;
name|offset2
operator|=
name|rect2
operator|.
name|center
argument_list|()
operator|.
name|y
argument_list|()
expr_stmt|;
block|}
name|int
name|childIndex
init|=
name|firstChildIndex
argument_list|(
name|index
argument_list|)
decl_stmt|;
name|Node
modifier|*
name|child
init|=
operator|&
name|nodes
index|[
name|childIndex
index|]
decl_stmt|;
name|child
operator|->
name|offset
operator|=
name|offset1
expr_stmt|;
name|child
operator|->
name|type
operator|=
name|type
expr_stmt|;
name|child
operator|=
operator|&
name|nodes
index|[
name|childIndex
operator|+
literal|1
index|]
expr_stmt|;
name|child
operator|->
name|offset
operator|=
name|offset2
expr_stmt|;
name|child
operator|->
name|type
operator|=
name|type
expr_stmt|;
name|initialize
argument_list|(
name|rect1
argument_list|,
name|depth
operator|-
literal|1
argument_list|,
name|childIndex
argument_list|)
expr_stmt|;
name|initialize
argument_list|(
name|rect2
argument_list|,
name|depth
operator|-
literal|1
argument_list|,
name|childIndex
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|node
operator|->
name|type
operator|=
name|Node
operator|::
name|Leaf
expr_stmt|;
name|node
operator|->
name|leafIndex
operator|=
name|leafCnt
operator|++
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|climbTree
name|void
name|QGraphicsSceneBspTree
operator|::
name|climbTree
parameter_list|(
name|QGraphicsSceneBspTreeVisitor
modifier|*
name|visitor
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|int
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|nodes
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
specifier|const
name|Node
modifier|&
name|node
init|=
name|nodes
operator|.
name|at
argument_list|(
name|index
argument_list|)
decl_stmt|;
specifier|const
name|int
name|childIndex
init|=
name|firstChildIndex
argument_list|(
name|index
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|node
operator|.
name|type
condition|)
block|{
case|case
name|Node
operator|::
name|Leaf
case|:
block|{
name|visitor
operator|->
name|visit
argument_list|(
cast|const_cast
argument_list|<
name|QList
argument_list|<
name|QGraphicsItem
operator|*
argument_list|>
operator|*
argument_list|>
argument_list|(
operator|&
name|leaves
index|[
name|node
operator|.
name|leafIndex
index|]
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|Node
operator|::
name|Vertical
case|:
if|if
condition|(
name|rect
operator|.
name|left
argument_list|()
operator|<
name|node
operator|.
name|offset
condition|)
block|{
name|climbTree
argument_list|(
name|visitor
argument_list|,
name|rect
argument_list|,
name|childIndex
argument_list|)
expr_stmt|;
if|if
condition|(
name|rect
operator|.
name|right
argument_list|()
operator|>=
name|node
operator|.
name|offset
condition|)
name|climbTree
argument_list|(
name|visitor
argument_list|,
name|rect
argument_list|,
name|childIndex
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|climbTree
argument_list|(
name|visitor
argument_list|,
name|rect
argument_list|,
name|childIndex
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|Node
operator|::
name|Horizontal
case|:
if|if
condition|(
name|rect
operator|.
name|top
argument_list|()
operator|<
name|node
operator|.
name|offset
condition|)
block|{
name|climbTree
argument_list|(
name|visitor
argument_list|,
name|rect
argument_list|,
name|childIndex
argument_list|)
expr_stmt|;
if|if
condition|(
name|rect
operator|.
name|bottom
argument_list|()
operator|>=
name|node
operator|.
name|offset
condition|)
name|climbTree
argument_list|(
name|visitor
argument_list|,
name|rect
argument_list|,
name|childIndex
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|climbTree
argument_list|(
name|visitor
argument_list|,
name|rect
argument_list|,
name|childIndex
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|rectForIndex
name|QRectF
name|QGraphicsSceneBspTree
operator|::
name|rectForIndex
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|index
operator|<=
literal|0
condition|)
return|return
name|rect
return|;
name|int
name|parentIdx
init|=
name|parentIndex
argument_list|(
name|index
argument_list|)
decl_stmt|;
name|QRectF
name|rect
init|=
name|rectForIndex
argument_list|(
name|parentIdx
argument_list|)
decl_stmt|;
specifier|const
name|Node
modifier|*
name|parent
init|=
operator|&
name|nodes
operator|.
name|at
argument_list|(
name|parentIdx
argument_list|)
decl_stmt|;
if|if
condition|(
name|parent
operator|->
name|type
operator|==
name|Node
operator|::
name|Horizontal
condition|)
block|{
if|if
condition|(
name|index
operator|&
literal|1
condition|)
name|rect
operator|.
name|setRight
argument_list|(
name|parent
operator|->
name|offset
argument_list|)
expr_stmt|;
else|else
name|rect
operator|.
name|setLeft
argument_list|(
name|parent
operator|->
name|offset
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|index
operator|&
literal|1
condition|)
name|rect
operator|.
name|setBottom
argument_list|(
name|parent
operator|->
name|offset
argument_list|)
expr_stmt|;
else|else
name|rect
operator|.
name|setTop
argument_list|(
name|parent
operator|->
name|offset
argument_list|)
expr_stmt|;
block|}
return|return
name|rect
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_GRAPHICSVIEW
end_comment
end_unit
