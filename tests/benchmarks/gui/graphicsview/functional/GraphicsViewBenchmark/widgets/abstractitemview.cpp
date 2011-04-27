begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QGraphicsLayout>
end_include
begin_include
include|#
directive|include
file|"abstractitemview.h"
end_include
begin_include
include|#
directive|include
file|"abstractviewitem.h"
end_include
begin_include
include|#
directive|include
file|"scrollbar.h"
end_include
begin_constructor
DECL|function|AbstractItemView
name|AbstractItemView
operator|::
name|AbstractItemView
parameter_list|(
name|QGraphicsWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|AbstractScrollArea
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_model
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_rootIndex
argument_list|()
member_init_list|,
name|m_container
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_selectionModel
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_currentIndex
argument_list|()
member_init_list|,
name|m_scroller
argument_list|()
block|{
name|setRootIndex
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*virtual*/
end_comment
begin_destructor
DECL|function|~AbstractItemView
name|AbstractItemView
operator|::
name|~
name|AbstractItemView
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|setModel
name|void
name|AbstractItemView
operator|::
name|setModel
parameter_list|(
name|QAbstractItemModel
modifier|*
name|model
parameter_list|,
name|AbstractViewItem
modifier|*
name|prototype
parameter_list|)
block|{
if|if
condition|(
name|m_model
operator|==
name|model
operator|||
operator|!
name|model
condition|)
return|return;
if|if
condition|(
name|m_model
condition|)
block|{
name|disconnect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_modelDestroyed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|dataChanged
argument_list|(
name|QModelIndex
argument_list|,
name|QModelIndex
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|dataChanged
argument_list|(
name|QModelIndex
argument_list|,
name|QModelIndex
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|rowsInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|rowsInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|rowsRemoved
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|rowsRemoved
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|rowsAboutToBeRemoved
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|rowsAboutToBeRemoved
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|rowsAboutToBeInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|rowsAboutToBeInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|columnsInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|columnsInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|columnsAboutToBeInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|columnsAboutToBeInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|columnsRemoved
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|columnsRemoved
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|columnsAboutToBeRemoved
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|columnsAboutToBeRemoved
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|modelReset
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|reset
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|layoutChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_layoutChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_model
operator|=
literal|0
expr_stmt|;
block|}
name|setSelectionModel
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|m_currentIndex
operator|=
name|QModelIndex
argument_list|()
expr_stmt|;
name|m_rootIndex
operator|=
name|QModelIndex
argument_list|()
expr_stmt|;
name|m_model
operator|=
name|model
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
name|m_model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|==
name|m_model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
literal|"AbstractItemView::setModel"
argument_list|,
literal|"A model should return the exact same index "
literal|"(including its internal id/pointer) when asked for it twice in a row."
argument_list|)
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
name|m_model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|.
name|parent
argument_list|()
operator|==
name|QModelIndex
argument_list|()
argument_list|,
literal|"AbstractItemView::setModel"
argument_list|,
literal|"The parent of a top level index should be invalid"
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|modelDestroyed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|dataChanged
argument_list|(
name|QModelIndex
argument_list|,
name|QModelIndex
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|dataChanged
argument_list|(
name|QModelIndex
argument_list|,
name|QModelIndex
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|rowsAboutToBeInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|rowsAboutToBeInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|rowsInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|rowsInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|rowsAboutToBeRemoved
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|rowsAboutToBeRemoved
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|rowsRemoved
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|rowsRemoved
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|modelReset
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|reset
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_model
argument_list|,
name|SIGNAL
argument_list|(
name|layoutChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|layoutChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|setSelectionModel
argument_list|(
operator|new
name|QItemSelectionModel
argument_list|(
name|m_model
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|prototype
operator|&&
name|m_container
condition|)
block|{
name|m_container
operator|->
name|setItemPrototype
argument_list|(
name|prototype
argument_list|)
expr_stmt|;
name|m_container
operator|->
name|reset
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|setContainer
name|void
name|AbstractItemView
operator|::
name|setContainer
parameter_list|(
name|AbstractItemContainer
modifier|*
name|container
parameter_list|)
block|{
name|m_container
operator|=
name|container
expr_stmt|;
name|m_container
operator|->
name|setItemView
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_container
operator|->
name|setParentItem
argument_list|(
name|viewport
argument_list|()
argument_list|)
expr_stmt|;
name|viewport
argument_list|()
operator|->
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemClipsChildrenToShape
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|m_scroller
operator|.
name|setScrollable
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|installEventFilter
argument_list|(
operator|&
name|m_scroller
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|setRootIndex
name|void
name|AbstractItemView
operator|::
name|setRootIndex
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
block|{
name|m_rootIndex
operator|=
name|index
expr_stmt|;
comment|// TODO fix this if we change index, container should be updated? Or do we need root index?
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|indexCount
name|int
name|AbstractItemView
operator|::
name|indexCount
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_model
condition|)
return|return
name|m_model
operator|->
name|rowCount
argument_list|(
name|m_rootIndex
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|model
name|QAbstractItemModel
modifier|*
name|AbstractItemView
operator|::
name|model
parameter_list|()
specifier|const
block|{
return|return
name|m_model
return|;
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|nextIndex
name|QModelIndex
name|AbstractItemView
operator|::
name|nextIndex
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|m_model
condition|)
return|return
name|QModelIndex
argument_list|()
return|;
if|if
condition|(
name|index
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|m_model
operator|->
name|index
argument_list|(
name|index
operator|.
name|row
argument_list|()
operator|+
literal|1
argument_list|,
literal|0
argument_list|,
name|m_rootIndex
argument_list|)
return|;
else|else
return|return
name|m_model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_rootIndex
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|previousIndex
name|QModelIndex
name|AbstractItemView
operator|::
name|previousIndex
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|m_model
condition|)
return|return
name|QModelIndex
argument_list|()
return|;
if|if
condition|(
name|index
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|m_model
operator|->
name|index
argument_list|(
name|index
operator|.
name|row
argument_list|()
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
name|m_rootIndex
argument_list|)
return|;
else|else
return|return
name|m_model
operator|->
name|index
argument_list|(
name|m_model
operator|->
name|rowCount
argument_list|(
name|m_rootIndex
argument_list|)
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
name|m_rootIndex
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|setItemPrototype
name|void
name|AbstractItemView
operator|::
name|setItemPrototype
parameter_list|(
name|AbstractViewItem
modifier|*
name|prototype
parameter_list|)
block|{
if|if
condition|(
name|prototype
operator|&&
name|m_container
condition|)
block|{
name|m_container
operator|->
name|setItemPrototype
argument_list|(
name|prototype
argument_list|)
expr_stmt|;
name|m_container
operator|->
name|reset
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setSelectionModel
name|void
name|AbstractItemView
operator|::
name|setSelectionModel
parameter_list|(
name|QItemSelectionModel
modifier|*
name|smodel
parameter_list|)
block|{
if|if
condition|(
name|smodel
operator|&&
name|smodel
operator|->
name|model
argument_list|()
operator|!=
name|m_model
condition|)
block|{
return|return;
block|}
if|if
condition|(
name|m_selectionModel
condition|)
block|{
name|disconnect
argument_list|(
name|m_selectionModel
argument_list|,
name|SIGNAL
argument_list|(
name|selectionChanged
argument_list|(
name|QItemSelection
argument_list|,
name|QItemSelection
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|currentSelectionChanged
argument_list|(
name|QItemSelection
argument_list|,
name|QItemSelection
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|m_selectionModel
argument_list|,
name|SIGNAL
argument_list|(
name|currentChanged
argument_list|(
name|QModelIndex
argument_list|,
name|QModelIndex
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|currentIndexChanged
argument_list|(
name|QModelIndex
argument_list|,
name|QModelIndex
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
operator|delete
name|m_selectionModel
expr_stmt|;
name|m_selectionModel
operator|=
literal|0
expr_stmt|;
block|}
name|m_selectionModel
operator|=
name|smodel
expr_stmt|;
if|if
condition|(
name|m_selectionModel
condition|)
block|{
name|connect
argument_list|(
name|m_selectionModel
argument_list|,
name|SIGNAL
argument_list|(
name|selectionChanged
argument_list|(
name|QItemSelection
argument_list|,
name|QItemSelection
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|currentSelectionChanged
argument_list|(
name|QItemSelection
argument_list|,
name|QItemSelection
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_selectionModel
argument_list|,
name|SIGNAL
argument_list|(
name|currentChanged
argument_list|(
name|QModelIndex
argument_list|,
name|QModelIndex
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|currentIndexChanged
argument_list|(
name|QModelIndex
argument_list|,
name|QModelIndex
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|currentIndexChanged
name|void
name|AbstractItemView
operator|::
name|currentIndexChanged
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|current
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|previous
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|previous
argument_list|)
if|if
condition|(
name|current
operator|!=
name|m_currentIndex
condition|)
name|m_currentIndex
operator|=
name|current
expr_stmt|;
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|currentSelectionChanged
name|void
name|AbstractItemView
operator|::
name|currentSelectionChanged
parameter_list|(
specifier|const
name|QItemSelection
modifier|&
name|selected
parameter_list|,
specifier|const
name|QItemSelection
modifier|&
name|deselected
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|selected
argument_list|)
name|Q_UNUSED
argument_list|(
argument|deselected
argument_list|)
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|dataChanged
name|void
name|AbstractItemView
operator|::
name|dataChanged
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|topLeft
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|bottomRight
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|topLeft
argument_list|)
name|Q_UNUSED
argument_list|(
argument|bottomRight
argument_list|)
comment|// TODO implement if we like to edit view items.
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|rowsAboutToBeInserted
name|void
name|AbstractItemView
operator|::
name|rowsAboutToBeInserted
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|index
argument_list|)
name|Q_UNUSED
argument_list|(
argument|start
argument_list|)
name|Q_UNUSED
argument_list|(
argument|end
argument_list|)
comment|// TODO implement
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|rowsAboutToBeRemoved
name|void
name|AbstractItemView
operator|::
name|rowsAboutToBeRemoved
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|index
argument_list|)
name|Q_UNUSED
argument_list|(
argument|start
argument_list|)
name|Q_UNUSED
argument_list|(
argument|end
argument_list|)
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|rowsRemoved
name|void
name|AbstractItemView
operator|::
name|rowsRemoved
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|parent
argument_list|)
name|Q_UNUSED
argument_list|(
argument|start
argument_list|)
name|Q_UNUSED
argument_list|(
argument|end
argument_list|)
if|if
condition|(
name|start
operator|<=
name|m_currentIndex
operator|.
name|row
argument_list|()
operator|&&
name|m_currentIndex
operator|.
name|row
argument_list|()
operator|<=
name|end
condition|)
block|{
name|QModelIndex
name|newCurrentIndex
init|=
name|m_model
operator|->
name|index
argument_list|(
name|start
argument_list|,
literal|0
argument_list|,
name|m_rootIndex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|newCurrentIndex
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|newCurrentIndex
operator|=
name|m_model
operator|->
name|index
argument_list|(
name|qMax
argument_list|(
literal|0
argument_list|,
name|start
operator|-
literal|1
argument_list|)
argument_list|,
literal|0
argument_list|,
name|m_rootIndex
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|m_selectionModel
condition|)
block|{
name|m_selectionModel
operator|->
name|setCurrentIndex
argument_list|(
name|newCurrentIndex
argument_list|,
name|QItemSelectionModel
operator|::
name|NoUpdate
argument_list|)
expr_stmt|;
block|}
block|}
for|for
control|(
name|int
name|i
init|=
name|end
init|;
name|i
operator|>=
name|start
condition|;
operator|--
name|i
control|)
comment|//The items are already removed from the model.
name|m_container
operator|->
name|removeItem
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
comment|// Indexes are already invalid.
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|reset
name|void
name|AbstractItemView
operator|::
name|reset
parameter_list|()
block|{
name|m_rootIndex
operator|=
name|QModelIndex
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_container
condition|)
name|m_container
operator|->
name|reset
argument_list|()
expr_stmt|;
name|setCurrentIndex
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
name|ScrollBar
modifier|*
name|sb
init|=
name|verticalScrollBar
argument_list|()
decl_stmt|;
if|if
condition|(
name|sb
condition|)
name|sb
operator|->
name|setSliderSize
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|rowsInserted
name|void
name|AbstractItemView
operator|::
name|rowsInserted
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_container
condition|)
return|return;
for|for
control|(
name|int
name|i
init|=
name|start
init|;
name|i
operator|<=
name|end
condition|;
operator|++
name|i
control|)
name|m_container
operator|->
name|addItem
argument_list|(
name|m_model
operator|->
name|index
argument_list|(
name|i
argument_list|,
literal|0
argument_list|,
name|parent
argument_list|)
argument_list|)
expr_stmt|;
name|refreshContainerGeometry
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|modelDestroyed
name|void
name|AbstractItemView
operator|::
name|modelDestroyed
parameter_list|()
block|{
name|m_model
operator|=
literal|0
expr_stmt|;
name|setSelectionModel
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|reset
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|layoutChanged
name|void
name|AbstractItemView
operator|::
name|layoutChanged
parameter_list|()
block|{
name|m_container
operator|->
name|reset
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|event
name|bool
name|AbstractItemView
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|bool
name|result
init|=
name|AbstractScrollArea
operator|::
name|event
argument_list|(
name|e
argument_list|)
decl_stmt|;
if|if
condition|(
name|e
operator|&&
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|LayoutRequest
condition|)
block|{
name|refreshContainerGeometry
argument_list|()
expr_stmt|;
name|result
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|e
operator|&&
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|GraphicsSceneResize
condition|)
block|{
name|m_scroller
operator|.
name|stopScrolling
argument_list|()
expr_stmt|;
name|refreshContainerGeometry
argument_list|()
expr_stmt|;
name|m_container
operator|->
name|resize
argument_list|(
name|this
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
operator|-
name|verticalScrollBar
argument_list|()
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|m_container
operator|->
name|preferredHeight
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|verticalScrollBar
argument_list|()
operator|->
name|sliderPosition
argument_list|()
operator|>
name|verticalScrollBar
argument_list|()
operator|->
name|sliderSize
argument_list|()
condition|)
name|verticalScrollBar
argument_list|()
operator|->
name|setSliderPosition
argument_list|(
name|verticalScrollBar
argument_list|()
operator|->
name|sliderSize
argument_list|()
argument_list|)
expr_stmt|;
name|result
operator|=
literal|true
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|setCurrentIndex
name|void
name|AbstractItemView
operator|::
name|setCurrentIndex
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
name|QItemSelectionModel
operator|::
name|SelectionFlags
name|selectionFlag
parameter_list|)
block|{
if|if
condition|(
name|m_selectionModel
condition|)
name|m_selectionModel
operator|->
name|setCurrentIndex
argument_list|(
name|index
argument_list|,
name|selectionFlag
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|refreshContainerGeometry
name|void
name|AbstractItemView
operator|::
name|refreshContainerGeometry
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_container
operator|||
operator|!
name|m_model
condition|)
return|return;
if|if
condition|(
name|m_container
operator|->
name|layout
argument_list|()
operator|&&
operator|!
name|m_container
operator|->
name|layout
argument_list|()
operator|->
name|isActivated
argument_list|()
condition|)
name|m_container
operator|->
name|layout
argument_list|()
operator|->
name|activate
argument_list|()
expr_stmt|;
name|ScrollBar
modifier|*
name|sb
init|=
name|verticalScrollBar
argument_list|()
decl_stmt|;
if|if
condition|(
name|sb
condition|)
block|{
name|AbstractViewItem
modifier|*
name|item
init|=
name|m_container
operator|->
name|itemAt
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|item
condition|)
block|{
name|qreal
name|oneItemH
init|=
name|item
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
decl_stmt|;
name|sb
operator|->
name|setSliderSize
argument_list|(
name|oneItemH
operator|*
name|m_model
operator|->
name|rowCount
argument_list|(
name|m_rootIndex
argument_list|)
operator|-
name|size
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|sb
operator|->
name|isVisible
argument_list|()
operator|&&
name|verticalScrollBarPolicy
argument_list|()
operator|!=
name|Qt
operator|::
name|ScrollBarAlwaysOff
operator|&&
name|contentsRect
argument_list|()
operator|.
name|height
argument_list|()
operator|<
name|m_container
operator|->
name|boundingRect
argument_list|()
operator|.
name|height
argument_list|()
condition|)
name|sb
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|scrollContentsBy
name|void
name|AbstractItemView
operator|::
name|scrollContentsBy
parameter_list|(
name|qreal
name|dx
parameter_list|,
name|qreal
name|dy
parameter_list|)
block|{
name|AbstractScrollArea
operator|::
name|scrollContentsBy
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|viewport
argument_list|()
operator|||
operator|!
name|m_container
operator|||
operator|(
name|m_container
operator|&&
name|m_container
operator|->
name|itemCount
argument_list|()
operator|<=
literal|0
operator|)
operator|||
operator|!
name|m_model
operator|||
operator|(
name|m_model
operator|&&
name|m_model
operator|->
name|rowCount
argument_list|()
operator|<=
literal|0
operator|)
operator|||
operator|(
name|viewport
argument_list|()
operator|&&
name|viewport
argument_list|()
operator|->
name|boundingRect
argument_list|()
operator|.
name|height
argument_list|()
operator|<
name|contentsRect
argument_list|()
operator|.
name|height
argument_list|()
operator|)
condition|)
return|return;
name|qreal
name|itemH
init|=
literal|1
decl_stmt|;
name|AbstractViewItem
modifier|*
name|item
init|=
name|m_container
operator|->
name|itemAt
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|item
operator|&&
name|item
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
operator|>
literal|1
condition|)
block|{
name|itemH
operator|=
name|item
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|item
operator|&&
name|item
operator|->
name|preferredHeight
argument_list|()
operator|>
literal|1
condition|)
block|{
name|itemH
operator|=
name|item
operator|->
name|preferredHeight
argument_list|()
expr_stmt|;
block|}
name|qreal
name|vpx
init|=
name|m_container
operator|->
name|pos
argument_list|()
operator|.
name|x
argument_list|()
decl_stmt|;
name|qreal
name|vpy
init|=
name|m_container
operator|->
name|pos
argument_list|()
operator|.
name|y
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|vpy
operator|+
name|m_container
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
operator|-
name|dy
operator|>
name|pos
argument_list|()
operator|.
name|y
argument_list|()
operator|+
name|size
argument_list|()
operator|.
name|height
argument_list|()
operator|)
operator|&&
operator|(
name|qAbs
argument_list|(
name|dy
argument_list|)
operator|<
name|itemH
operator|)
operator|&&
operator|(
name|vpy
operator|-
name|dy
operator|<=
literal|0
operator|)
condition|)
block|{
name|m_container
operator|->
name|setPos
argument_list|(
name|vpx
argument_list|,
name|vpy
operator|-
name|dy
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qreal
name|vPos
init|=
name|verticalScrollBar
argument_list|()
operator|->
name|sliderPosition
argument_list|()
decl_stmt|;
name|int
name|startRow
init|=
name|m_model
operator|->
name|index
argument_list|(
name|vPos
operator|/
name|itemH
argument_list|,
literal|0
argument_list|)
operator|.
name|row
argument_list|()
decl_stmt|;
name|int
name|itemsInContainer
init|=
name|m_container
operator|->
name|itemCount
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|itemsInContainer
condition|;
operator|++
name|i
control|)
block|{
name|AbstractViewItem
modifier|*
name|changedItem
init|=
name|m_container
operator|->
name|itemAt
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|changedItem
operator|->
name|setModelIndex
argument_list|(
name|m_model
operator|->
name|index
argument_list|(
name|startRow
operator|+
name|i
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
operator|(
name|QT_VERSION
operator|>=
literal|0x040600
operator|)
name|m_container
operator|->
name|setListItemCaching
argument_list|(
name|listItemCaching
argument_list|()
argument_list|,
name|i
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|qreal
name|diff
init|=
name|vPos
operator|-
name|startRow
operator|*
name|itemH
decl_stmt|;
if|if
condition|(
name|diff
operator|<
literal|0
condition|)
name|m_container
operator|->
name|setPos
argument_list|(
name|vpx
argument_list|,
name|diff
argument_list|)
expr_stmt|;
else|else
name|m_container
operator|->
name|setPos
argument_list|(
name|vpx
argument_list|,
operator|-
name|diff
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|changeTheme
name|void
name|AbstractItemView
operator|::
name|changeTheme
parameter_list|()
block|{
if|if
condition|(
name|m_container
condition|)
name|m_container
operator|->
name|themeChange
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateViewContent
name|void
name|AbstractItemView
operator|::
name|updateViewContent
parameter_list|()
block|{
if|if
condition|(
name|m_container
condition|)
name|m_container
operator|->
name|updateContent
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
