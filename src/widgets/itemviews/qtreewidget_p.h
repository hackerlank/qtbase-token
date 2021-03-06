begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTREEWIDGET_P_H
end_ifndef
begin_define
DECL|macro|QTREEWIDGET_P_H
define|#
directive|define
name|QTREEWIDGET_P_H
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
comment|// This file is not part of the Qt API. This header file may change
end_comment
begin_comment
comment|// from version to version without notice, or even be removed.
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
file|<QtCore/qabstractitemmodel.h>
end_include
begin_include
include|#
directive|include
file|<private/qabstractitemmodel_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpair.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbasictimer.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qtreewidget.h>
end_include
begin_include
include|#
directive|include
file|<private/qtreeview_p.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qheaderview.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TREEWIDGET
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTreeWidgetItem
name|class
name|QTreeWidgetItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTreeWidgetItemIterator
name|class
name|QTreeWidgetItemIterator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTreeModelPrivate
name|class
name|QTreeModelPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTreeModel
range|:
name|public
name|QAbstractItemModel
block|{
name|Q_OBJECT
name|friend
name|class
name|QTreeWidget
block|;
name|friend
name|class
name|QTreeWidgetPrivate
block|;
name|friend
name|class
name|QTreeWidgetItem
block|;
name|friend
name|class
name|QTreeWidgetItemPrivate
block|;
name|friend
name|class
name|QTreeWidgetItemIterator
block|;
name|friend
name|class
name|QTreeWidgetItemIteratorPrivate
block|;
name|public
operator|:
name|explicit
name|QTreeModel
argument_list|(
argument|int columns =
literal|0
argument_list|,
argument|QTreeWidget *parent =
literal|0
argument_list|)
block|;
operator|~
name|QTreeModel
argument_list|()
block|;
specifier|inline
name|QTreeWidget
operator|*
name|view
argument_list|()
specifier|const
block|{
return|return
name|qobject_cast
operator|<
name|QTreeWidget
operator|*
operator|>
operator|(
name|QObject
operator|::
name|parent
argument_list|()
operator|)
return|;
block|}
name|void
name|clear
argument_list|()
block|;
name|void
name|setColumnCount
argument_list|(
argument|int columns
argument_list|)
block|;
name|QTreeWidgetItem
operator|*
name|item
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|void
name|itemChanged
argument_list|(
name|QTreeWidgetItem
operator|*
name|item
argument_list|)
block|;
name|QModelIndex
name|index
argument_list|(
argument|const QTreeWidgetItem *item
argument_list|,
argument|int column
argument_list|)
specifier|const
block|;
name|QModelIndex
name|index
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|const QModelIndex&parent
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QModelIndex
name|parent
argument_list|(
argument|const QModelIndex&child
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|rowCount
argument_list|(
argument|const QModelIndex&parent
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|columnCount
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasChildren
argument_list|(
argument|const QModelIndex&parent
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|int role = Qt::DisplayRole
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|setData
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|const QVariant&value
argument_list|,
argument|int role
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QMap
operator|<
name|int
block|,
name|QVariant
operator|>
name|itemData
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|headerData
argument_list|(
argument|int section
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|int role
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|setHeaderData
argument_list|(
argument|int section
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|const QVariant&value
argument_list|,
argument|int role
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|Qt
operator|::
name|ItemFlags
name|flags
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|sort
argument_list|(
argument|int column
argument_list|,
argument|Qt::SortOrder order
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|ensureSorted
argument_list|(
argument|int column
argument_list|,
argument|Qt::SortOrder order
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|,
argument|const QModelIndex&parent
argument_list|)
block|;
specifier|static
name|bool
name|itemLessThan
argument_list|(
specifier|const
name|QPair
operator|<
name|QTreeWidgetItem
operator|*
argument_list|,
name|int
operator|>
operator|&
name|left
argument_list|,
specifier|const
name|QPair
operator|<
name|QTreeWidgetItem
operator|*
argument_list|,
name|int
operator|>
operator|&
name|right
argument_list|)
block|;
specifier|static
name|bool
name|itemGreaterThan
argument_list|(
specifier|const
name|QPair
operator|<
name|QTreeWidgetItem
operator|*
argument_list|,
name|int
operator|>
operator|&
name|left
argument_list|,
specifier|const
name|QPair
operator|<
name|QTreeWidgetItem
operator|*
argument_list|,
name|int
operator|>
operator|&
name|right
argument_list|)
block|;
specifier|static
name|QList
operator|<
name|QTreeWidgetItem
operator|*
operator|>
operator|::
name|iterator
name|sortedInsertionIterator
argument_list|(
argument|const QList<QTreeWidgetItem*>::iterator&begin
argument_list|,
argument|const QList<QTreeWidgetItem*>::iterator&end
argument_list|,
argument|Qt::SortOrder order
argument_list|,
argument|QTreeWidgetItem *item
argument_list|)
block|;
name|bool
name|insertRows
argument_list|(
argument|int row
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex&
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|insertColumns
argument_list|(
argument|int column
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex&
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|removeRows
argument_list|(
argument|int row
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
name|Q_DECL_OVERRIDE
block|;
comment|// dnd
name|QStringList
name|mimeTypes
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QMimeData
operator|*
name|mimeData
argument_list|(
argument|const QModelIndexList&indexes
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|dropMimeData
argument_list|(
argument|const QMimeData *data
argument_list|,
argument|Qt::DropAction action
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|const QModelIndex&parent
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|Qt
operator|::
name|DropActions
name|supportedDropActions
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QMimeData
operator|*
name|internalMimeData
argument_list|()
specifier|const
block|;
specifier|inline
name|QModelIndex
name|createIndexFromItem
argument_list|(
argument|int row
argument_list|,
argument|int col
argument_list|,
argument|QTreeWidgetItem *item
argument_list|)
specifier|const
block|{
return|return
name|createIndex
argument_list|(
name|row
argument_list|,
name|col
argument_list|,
name|item
argument_list|)
return|;
block|}
name|protected
operator|:
name|QTreeModel
argument_list|(
name|QTreeModelPrivate
operator|&
argument_list|,
name|QTreeWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|emitDataChanged
argument_list|(
argument|QTreeWidgetItem *item
argument_list|,
argument|int column
argument_list|)
block|;
name|void
name|beginInsertItems
argument_list|(
argument|QTreeWidgetItem *parent
argument_list|,
argument|int row
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|endInsertItems
argument_list|()
block|;
name|void
name|beginRemoveItems
argument_list|(
argument|QTreeWidgetItem *parent
argument_list|,
argument|int row
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|endRemoveItems
argument_list|()
block|;
name|void
name|sortItems
argument_list|(
argument|QList<QTreeWidgetItem*> *items
argument_list|,
argument|int column
argument_list|,
argument|Qt::SortOrder order
argument_list|)
block|;
name|void
name|timerEvent
argument_list|(
argument|QTimerEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|QTreeWidgetItem
operator|*
name|rootItem
block|;
name|QTreeWidgetItem
operator|*
name|headerItem
block|;
name|mutable
name|QModelIndexList
name|cachedIndexes
block|;
name|QList
operator|<
name|QTreeWidgetItemIterator
operator|*
operator|>
name|iterators
block|;
name|mutable
name|QBasicTimer
name|sortPendingTimer
block|;
name|mutable
name|bool
name|skipPendingSort
block|;
comment|//while doing internal operation we don't care about sorting
name|bool
specifier|inline
name|executePendingSort
argument_list|()
specifier|const
block|;
name|bool
name|isChanging
argument_list|()
specifier|const
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTreeModel
argument_list|)
name|public
operator|:
expr|struct
name|SkipSorting
block|{
specifier|const
name|QTreeModel
operator|*
specifier|const
name|model
block|;
specifier|const
name|bool
name|previous
block|;
name|SkipSorting
argument_list|(
specifier|const
name|QTreeModel
operator|*
name|m
argument_list|)
operator|:
name|model
argument_list|(
name|m
argument_list|)
block|,
name|previous
argument_list|(
argument|model->skipPendingSort
argument_list|)
block|{
name|model
operator|->
name|skipPendingSort
operator|=
name|true
block|; }
operator|~
name|SkipSorting
argument_list|()
block|{
name|model
operator|->
name|skipPendingSort
operator|=
name|previous
block|; }
block|}
block|;
name|friend
expr|struct
name|SkipSorting
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_INCLUDE_NAMESPACE
include|#
directive|include
file|"private/qabstractitemmodel_p.h"
name|QT_END_INCLUDE_NAMESPACE
name|class
name|QTreeModelPrivate
range|:
name|public
name|QAbstractItemModelPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTreeModel
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTreeWidgetItemPrivate
block|{
name|public
label|:
name|QTreeWidgetItemPrivate
argument_list|(
name|QTreeWidgetItem
operator|*
name|item
argument_list|)
operator|:
name|q
argument_list|(
name|item
argument_list|)
operator|,
name|disabled
argument_list|(
name|false
argument_list|)
operator|,
name|selected
argument_list|(
name|false
argument_list|)
operator|,
name|rowGuess
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|policy
argument_list|(
argument|QTreeWidgetItem::DontShowIndicatorWhenChildless
argument_list|)
block|{}
name|void
name|propagateDisabled
argument_list|(
name|QTreeWidgetItem
operator|*
name|item
argument_list|)
expr_stmt|;
name|void
name|sortChildren
argument_list|(
name|int
name|column
argument_list|,
name|Qt
operator|::
name|SortOrder
name|order
argument_list|,
name|bool
name|climb
argument_list|)
decl_stmt|;
name|QTreeWidgetItem
modifier|*
name|q
decl_stmt|;
name|QVariantList
name|display
decl_stmt|;
name|uint
name|disabled
range|:
literal|1
decl_stmt|;
name|uint
name|selected
range|:
literal|1
decl_stmt|;
name|int
name|rowGuess
decl_stmt|;
name|QTreeWidgetItem
operator|::
name|ChildIndicatorPolicy
name|policy
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|executePendingSort
specifier|inline
name|bool
name|QTreeModel
operator|::
name|executePendingSort
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|skipPendingSort
operator|&&
name|sortPendingTimer
operator|.
name|isActive
argument_list|()
operator|&&
operator|!
name|isChanging
argument_list|()
condition|)
block|{
name|sortPendingTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
name|int
name|column
init|=
name|view
argument_list|()
operator|->
name|header
argument_list|()
operator|->
name|sortIndicatorSection
argument_list|()
decl_stmt|;
name|Qt
operator|::
name|SortOrder
name|order
operator|=
name|view
argument_list|()
operator|->
name|header
argument_list|()
operator|->
name|sortIndicatorOrder
argument_list|()
expr_stmt|;
name|QTreeModel
modifier|*
name|that
init|=
name|const_cast
operator|<
name|QTreeModel
operator|*
operator|>
operator|(
name|this
operator|)
decl_stmt|;
name|that
operator|->
name|sort
argument_list|(
name|column
argument_list|,
name|order
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_expr_stmt
begin_return
return|return
name|false
return|;
end_return
begin_label
unit|}  class
name|QTreeWidgetPrivate
label|:
end_label
begin_decl_stmt
name|public
name|QTreeViewPrivate
block|{
name|friend
name|class
name|QTreeModel
decl_stmt|;
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTreeWidget
argument_list|)
name|public
label|:
name|QTreeWidgetPrivate
argument_list|()
operator|:
name|QTreeViewPrivate
argument_list|()
operator|,
name|explicitSortColumn
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
specifier|inline
name|QTreeModel
operator|*
name|treeModel
argument_list|()
specifier|const
block|{
return|return
name|qobject_cast
operator|<
name|QTreeModel
operator|*
operator|>
operator|(
name|model
operator|)
return|;
block|}
specifier|inline
name|QModelIndex
name|index
argument_list|(
specifier|const
name|QTreeWidgetItem
operator|*
name|item
argument_list|,
name|int
name|column
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|treeModel
argument_list|()
operator|->
name|index
argument_list|(
name|item
argument_list|,
name|column
argument_list|)
return|;
block|}
specifier|inline
name|QTreeWidgetItem
modifier|*
name|item
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
block|{
return|return
name|treeModel
argument_list|()
operator|->
name|item
argument_list|(
name|index
argument_list|)
return|;
block|}
name|void
name|_q_emitItemPressed
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
function_decl|;
name|void
name|_q_emitItemClicked
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
function_decl|;
name|void
name|_q_emitItemDoubleClicked
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
function_decl|;
name|void
name|_q_emitItemActivated
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
function_decl|;
name|void
name|_q_emitItemEntered
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
function_decl|;
name|void
name|_q_emitItemChanged
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
function_decl|;
name|void
name|_q_emitItemExpanded
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
function_decl|;
name|void
name|_q_emitItemCollapsed
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
function_decl|;
name|void
name|_q_emitCurrentItemChanged
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|previous
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
function_decl|;
name|void
name|_q_sort
parameter_list|()
function_decl|;
name|void
name|_q_dataChanged
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
function_decl|;
name|void
name|_q_selectionChanged
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
function_decl|;
comment|// used by QTreeWidgetItem::sortChildren to make sure the column argument is used
name|int
name|explicitSortColumn
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
begin_comment
comment|// QT_NO_TREEWIDGET
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTREEWIDGET_P_H
end_comment
end_unit
