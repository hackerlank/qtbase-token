begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLISTWIDGET_H
end_ifndef
begin_define
DECL|macro|QLISTWIDGET_H
define|#
directive|define
name|QLISTWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qlistview.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qitemselectionmodel.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_LISTWIDGET
DECL|variable|QListWidget
name|class
name|QListWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QListModel
name|class
name|QListModel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidgetItemData
name|class
name|QWidgetItemData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QListWidgetItemPrivate
name|class
name|QListWidgetItemPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QListWidgetItem
block|{
name|friend
name|class
name|QListModel
decl_stmt|;
name|friend
name|class
name|QListWidget
decl_stmt|;
name|public
label|:
enum|enum
name|ItemType
block|{
name|Type
init|=
literal|0
block|,
name|UserType
init|=
literal|1000
block|}
enum|;
name|explicit
name|QListWidgetItem
parameter_list|(
name|QListWidget
modifier|*
name|view
init|=
name|Q_NULLPTR
parameter_list|,
name|int
name|type
init|=
name|Type
parameter_list|)
function_decl|;
name|explicit
name|QListWidgetItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QListWidget
modifier|*
name|view
init|=
name|Q_NULLPTR
parameter_list|,
name|int
name|type
init|=
name|Type
parameter_list|)
function_decl|;
name|explicit
name|QListWidgetItem
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QListWidget
modifier|*
name|view
init|=
name|Q_NULLPTR
parameter_list|,
name|int
name|type
init|=
name|Type
parameter_list|)
function_decl|;
name|QListWidgetItem
argument_list|(
specifier|const
name|QListWidgetItem
operator|&
name|other
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|QListWidgetItem
argument_list|()
expr_stmt|;
name|virtual
name|QListWidgetItem
operator|*
name|clone
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|QListWidget
operator|*
name|listWidget
argument_list|()
specifier|const
block|{
return|return
name|view
return|;
block|}
specifier|inline
name|void
name|setSelected
parameter_list|(
name|bool
name|select
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|isSelected
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|void
name|setHidden
parameter_list|(
name|bool
name|hide
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|isHidden
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|Qt
operator|::
name|ItemFlags
name|flags
argument_list|()
specifier|const
block|{
return|return
name|itemFlags
return|;
block|}
name|void
name|setFlags
argument_list|(
name|Qt
operator|::
name|ItemFlags
name|flags
argument_list|)
decl_stmt|;
specifier|inline
name|QString
name|text
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|(
name|Qt
operator|::
name|DisplayRole
argument_list|)
operator|.
name|toString
argument_list|()
return|;
block|}
specifier|inline
name|void
name|setText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
specifier|inline
name|QIcon
name|icon
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QIcon
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|DecorationRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
function_decl|;
specifier|inline
name|QString
name|statusTip
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|(
name|Qt
operator|::
name|StatusTipRole
argument_list|)
operator|.
name|toString
argument_list|()
return|;
block|}
specifier|inline
name|void
name|setStatusTip
parameter_list|(
specifier|const
name|QString
modifier|&
name|statusTip
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
specifier|inline
name|QString
name|toolTip
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|(
name|Qt
operator|::
name|ToolTipRole
argument_list|)
operator|.
name|toString
argument_list|()
return|;
block|}
specifier|inline
name|void
name|setToolTip
parameter_list|(
specifier|const
name|QString
modifier|&
name|toolTip
parameter_list|)
function_decl|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
specifier|inline
name|QString
name|whatsThis
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|(
name|Qt
operator|::
name|WhatsThisRole
argument_list|)
operator|.
name|toString
argument_list|()
return|;
block|}
specifier|inline
name|void
name|setWhatsThis
parameter_list|(
specifier|const
name|QString
modifier|&
name|whatsThis
parameter_list|)
function_decl|;
endif|#
directive|endif
specifier|inline
name|QFont
name|font
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QFont
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|FontRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setFont
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
function_decl|;
specifier|inline
name|int
name|textAlignment
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|(
name|Qt
operator|::
name|TextAlignmentRole
argument_list|)
operator|.
name|toInt
argument_list|()
return|;
block|}
specifier|inline
name|void
name|setTextAlignment
parameter_list|(
name|int
name|alignment
parameter_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|TextAlignmentRole
argument_list|,
name|alignment
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|QColor
name|backgroundColor
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QColor
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|BackgroundColorRole
argument_list|)
operator|)
return|;
block|}
name|virtual
name|void
name|setBackgroundColor
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|BackgroundColorRole
argument_list|,
name|color
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|QBrush
name|background
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QBrush
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|BackgroundRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setBackground
parameter_list|(
specifier|const
name|QBrush
modifier|&
name|brush
parameter_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|BackgroundRole
argument_list|,
name|brush
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|QColor
name|textColor
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QColor
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|TextColorRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setTextColor
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|TextColorRole
argument_list|,
name|color
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|QBrush
name|foreground
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QBrush
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|ForegroundRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setForeground
parameter_list|(
specifier|const
name|QBrush
modifier|&
name|brush
parameter_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|ForegroundRole
argument_list|,
name|brush
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|Qt
operator|::
name|CheckState
name|checkState
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Qt
operator|::
name|CheckState
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|CheckStateRole
argument_list|)
operator|.
name|toInt
argument_list|()
operator|)
return|;
block|}
specifier|inline
name|void
name|setCheckState
argument_list|(
name|Qt
operator|::
name|CheckState
name|state
argument_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|CheckStateRole
argument_list|,
name|static_cast
operator|<
name|int
operator|>
operator|(
name|state
operator|)
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QSize
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|SizeHintRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setSizeHint
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|SizeHintRole
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
name|virtual
name|QVariant
name|data
argument_list|(
name|int
name|role
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|setData
parameter_list|(
name|int
name|role
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
name|virtual
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QListWidgetItem
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|virtual
name|void
name|read
parameter_list|(
name|QDataStream
modifier|&
name|in
parameter_list|)
function_decl|;
name|virtual
name|void
name|write
argument_list|(
name|QDataStream
operator|&
name|out
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
name|QListWidgetItem
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QListWidgetItem
operator|&
name|other
operator|)
decl_stmt|;
specifier|inline
name|int
name|type
argument_list|()
specifier|const
block|{
return|return
name|rtti
return|;
block|}
name|private
label|:
name|int
name|rtti
decl_stmt|;
name|QVector
operator|<
name|void
operator|*
operator|>
name|dummy
expr_stmt|;
name|QListWidget
modifier|*
name|view
decl_stmt|;
name|QListWidgetItemPrivate
modifier|*
name|d
decl_stmt|;
name|Qt
operator|::
name|ItemFlags
name|itemFlags
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|setText
specifier|inline
name|void
name|QListWidgetItem
operator|::
name|setText
argument_list|(
argument|const QString&atext
argument_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|DisplayRole
argument_list|,
name|atext
argument_list|)
block|; }
DECL|function|setIcon
specifier|inline
name|void
name|QListWidgetItem
operator|::
name|setIcon
argument_list|(
argument|const QIcon&aicon
argument_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|DecorationRole
argument_list|,
name|aicon
argument_list|)
block|; }
DECL|function|setStatusTip
specifier|inline
name|void
name|QListWidgetItem
operator|::
name|setStatusTip
argument_list|(
argument|const QString&astatusTip
argument_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|StatusTipRole
argument_list|,
name|astatusTip
argument_list|)
block|; }
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
DECL|function|setToolTip
specifier|inline
name|void
name|QListWidgetItem
operator|::
name|setToolTip
argument_list|(
argument|const QString&atoolTip
argument_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|ToolTipRole
argument_list|,
name|atoolTip
argument_list|)
block|; }
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
DECL|function|setWhatsThis
specifier|inline
name|void
name|QListWidgetItem
operator|::
name|setWhatsThis
argument_list|(
argument|const QString&awhatsThis
argument_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|WhatsThisRole
argument_list|,
name|awhatsThis
argument_list|)
block|; }
endif|#
directive|endif
DECL|function|setFont
specifier|inline
name|void
name|QListWidgetItem
operator|::
name|setFont
argument_list|(
argument|const QFont&afont
argument_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|FontRole
argument_list|,
name|afont
argument_list|)
block|; }
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|Q_WIDGETS_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|out
operator|,
specifier|const
name|QListWidgetItem
operator|&
name|item
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_WIDGETS_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|in
operator|,
name|QListWidgetItem
operator|&
name|item
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QListWidgetPrivate
name|class
name|QListWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QListWidget
range|:
name|public
name|QListView
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|int count READ count
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int currentRow READ currentRow WRITE setCurrentRow NOTIFY currentRowChanged USER true
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool sortingEnabled READ isSortingEnabled WRITE setSortingEnabled
argument_list|)
name|friend
name|class
name|QListWidgetItem
block|;
name|friend
name|class
name|QListModel
block|;
name|public
operator|:
name|explicit
name|QListWidget
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QListWidget
argument_list|()
block|;
name|void
name|setSelectionModel
argument_list|(
argument|QItemSelectionModel *selectionModel
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QListWidgetItem
operator|*
name|item
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|int
name|row
argument_list|(
argument|const QListWidgetItem *item
argument_list|)
specifier|const
block|;
name|void
name|insertItem
argument_list|(
argument|int row
argument_list|,
argument|QListWidgetItem *item
argument_list|)
block|;
name|void
name|insertItem
argument_list|(
argument|int row
argument_list|,
argument|const QString&label
argument_list|)
block|;
name|void
name|insertItems
argument_list|(
argument|int row
argument_list|,
argument|const QStringList&labels
argument_list|)
block|;
specifier|inline
name|void
name|addItem
argument_list|(
argument|const QString&label
argument_list|)
block|{
name|insertItem
argument_list|(
name|count
argument_list|()
argument_list|,
name|label
argument_list|)
block|; }
specifier|inline
name|void
name|addItem
argument_list|(
name|QListWidgetItem
operator|*
name|item
argument_list|)
block|;
specifier|inline
name|void
name|addItems
argument_list|(
argument|const QStringList&labels
argument_list|)
block|{
name|insertItems
argument_list|(
name|count
argument_list|()
argument_list|,
name|labels
argument_list|)
block|; }
name|QListWidgetItem
operator|*
name|takeItem
argument_list|(
argument|int row
argument_list|)
block|;
name|int
name|count
argument_list|()
specifier|const
block|;
name|QListWidgetItem
operator|*
name|currentItem
argument_list|()
specifier|const
block|;
name|void
name|setCurrentItem
argument_list|(
name|QListWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|setCurrentItem
argument_list|(
argument|QListWidgetItem *item
argument_list|,
argument|QItemSelectionModel::SelectionFlags command
argument_list|)
block|;
name|int
name|currentRow
argument_list|()
specifier|const
block|;
name|void
name|setCurrentRow
argument_list|(
argument|int row
argument_list|)
block|;
name|void
name|setCurrentRow
argument_list|(
argument|int row
argument_list|,
argument|QItemSelectionModel::SelectionFlags command
argument_list|)
block|;
name|QListWidgetItem
operator|*
name|itemAt
argument_list|(
argument|const QPoint&p
argument_list|)
specifier|const
block|;
specifier|inline
name|QListWidgetItem
operator|*
name|itemAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|QRect
name|visualItemRect
argument_list|(
argument|const QListWidgetItem *item
argument_list|)
specifier|const
block|;
name|void
name|sortItems
argument_list|(
argument|Qt::SortOrder order = Qt::AscendingOrder
argument_list|)
block|;
name|void
name|setSortingEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|isSortingEnabled
argument_list|()
specifier|const
block|;
name|void
name|editItem
argument_list|(
name|QListWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|openPersistentEditor
argument_list|(
name|QListWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|closePersistentEditor
argument_list|(
name|QListWidgetItem
operator|*
name|item
argument_list|)
block|;
name|QWidget
operator|*
name|itemWidget
argument_list|(
argument|QListWidgetItem *item
argument_list|)
specifier|const
block|;
name|void
name|setItemWidget
argument_list|(
name|QListWidgetItem
operator|*
name|item
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|)
block|;
specifier|inline
name|void
name|removeItemWidget
argument_list|(
name|QListWidgetItem
operator|*
name|item
argument_list|)
block|;
name|bool
name|isItemSelected
argument_list|(
argument|const QListWidgetItem *item
argument_list|)
specifier|const
block|;
name|void
name|setItemSelected
argument_list|(
argument|const QListWidgetItem *item
argument_list|,
argument|bool select
argument_list|)
block|;
name|QList
operator|<
name|QListWidgetItem
operator|*
operator|>
name|selectedItems
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QListWidgetItem
operator|*
operator|>
name|findItems
argument_list|(
argument|const QString&text
argument_list|,
argument|Qt::MatchFlags flags
argument_list|)
specifier|const
block|;
name|bool
name|isItemHidden
argument_list|(
argument|const QListWidgetItem *item
argument_list|)
specifier|const
block|;
name|void
name|setItemHidden
argument_list|(
argument|const QListWidgetItem *item
argument_list|,
argument|bool hide
argument_list|)
block|;
name|void
name|dropEvent
argument_list|(
argument|QDropEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|scrollToItem
argument_list|(
argument|const QListWidgetItem *item
argument_list|,
argument|QAbstractItemView::ScrollHint hint = EnsureVisible
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|itemPressed
argument_list|(
name|QListWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|itemClicked
argument_list|(
name|QListWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|itemDoubleClicked
argument_list|(
name|QListWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|itemActivated
argument_list|(
name|QListWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|itemEntered
argument_list|(
name|QListWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|itemChanged
argument_list|(
name|QListWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|currentItemChanged
argument_list|(
name|QListWidgetItem
operator|*
name|current
argument_list|,
name|QListWidgetItem
operator|*
name|previous
argument_list|)
block|;
name|void
name|currentTextChanged
argument_list|(
specifier|const
name|QString
operator|&
name|currentText
argument_list|)
block|;
name|void
name|currentRowChanged
argument_list|(
argument|int currentRow
argument_list|)
block|;
name|void
name|itemSelectionChanged
argument_list|()
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
argument|QEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QStringList
name|mimeTypes
argument_list|()
specifier|const
block|;
if|#
directive|if
name|QT_VERSION
operator|>=
name|QT_VERSION_CHECK
argument_list|(
literal|6
operator|,
literal|0
operator|,
literal|0
argument_list|)
name|virtual
name|QMimeData
operator|*
name|mimeData
argument_list|(
argument|const QList<QListWidgetItem *>&items
argument_list|)
specifier|const
block|;
else|#
directive|else
name|virtual
name|QMimeData
operator|*
name|mimeData
argument_list|(
argument|const QList<QListWidgetItem*> items
argument_list|)
specifier|const
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|virtual
name|bool
name|dropMimeData
argument_list|(
argument|int index
argument_list|,
argument|const QMimeData *data
argument_list|,
argument|Qt::DropAction action
argument_list|)
block|;
name|virtual
name|Qt
operator|::
name|DropActions
name|supportedDropActions
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|QList
operator|<
name|QListWidgetItem
operator|*
operator|>
name|items
argument_list|(
argument|const QMimeData *data
argument_list|)
specifier|const
block|;
name|QModelIndex
name|indexFromItem
argument_list|(
argument|QListWidgetItem *item
argument_list|)
specifier|const
block|;
name|QListWidgetItem
operator|*
name|itemFromIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|private
operator|:
name|void
name|setModel
argument_list|(
argument|QAbstractItemModel *model
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|Qt
operator|::
name|SortOrder
name|sortOrder
argument_list|()
specifier|const
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QListWidget
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QListWidget
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitItemPressed(const QModelIndex&index)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitItemClicked(const QModelIndex&index)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitItemDoubleClicked(const QModelIndex&index)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitItemActivated(const QModelIndex&index)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitItemEntered(const QModelIndex&index)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitItemChanged(const QModelIndex&index)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitCurrentItemChanged(const QModelIndex&previous, const QModelIndex&current)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sort()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_dataChanged(const QModelIndex&topLeft, const QModelIndex&bottomRight)
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|removeItemWidget
specifier|inline
name|void
name|QListWidget
operator|::
name|removeItemWidget
argument_list|(
argument|QListWidgetItem *aItem
argument_list|)
block|{
name|setItemWidget
argument_list|(
name|aItem
argument_list|,
name|Q_NULLPTR
argument_list|)
block|; }
DECL|function|addItem
specifier|inline
name|void
name|QListWidget
operator|::
name|addItem
argument_list|(
argument|QListWidgetItem *aitem
argument_list|)
block|{
name|insertItem
argument_list|(
name|count
argument_list|()
argument_list|,
name|aitem
argument_list|)
block|; }
DECL|function|itemAt
specifier|inline
name|QListWidgetItem
operator|*
name|QListWidget
operator|::
name|itemAt
argument_list|(
argument|int ax
argument_list|,
argument|int ay
argument_list|)
specifier|const
block|{
return|return
name|itemAt
argument_list|(
name|QPoint
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setSelected
specifier|inline
name|void
name|QListWidgetItem
operator|::
name|setSelected
argument_list|(
argument|bool aselect
argument_list|)
block|{
if|if
condition|(
name|view
condition|)
name|view
operator|->
name|setItemSelected
argument_list|(
name|this
argument_list|,
name|aselect
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isSelected
specifier|inline
name|bool
name|QListWidgetItem
operator|::
name|isSelected
argument_list|()
specifier|const
block|{
return|return
operator|(
name|view
operator|?
name|view
operator|->
name|isItemSelected
argument_list|(
name|this
argument_list|)
operator|:
name|false
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setHidden
specifier|inline
name|void
name|QListWidgetItem
operator|::
name|setHidden
argument_list|(
argument|bool ahide
argument_list|)
block|{
if|if
condition|(
name|view
condition|)
name|view
operator|->
name|setItemHidden
argument_list|(
name|this
argument_list|,
name|ahide
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isHidden
specifier|inline
name|bool
name|QListWidgetItem
operator|::
name|isHidden
argument_list|()
specifier|const
block|{
return|return
operator|(
name|view
operator|?
name|view
operator|->
name|isItemHidden
argument_list|(
name|this
argument_list|)
operator|:
name|false
operator|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LISTWIDGET
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLISTWIDGET_H
end_comment
end_unit
