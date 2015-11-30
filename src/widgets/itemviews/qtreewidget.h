begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTREEWIDGET_H
end_ifndef
begin_define
DECL|macro|QTREEWIDGET_H
define|#
directive|define
name|QTREEWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qtreeview.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qtreewidgetitemiterator.h>
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_TREEWIDGET
DECL|variable|QTreeWidget
name|class
name|QTreeWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTreeModel
name|class
name|QTreeModel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidgetItemData
name|class
name|QWidgetItemData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTreeWidgetItemPrivate
name|class
name|QTreeWidgetItemPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QTreeWidgetItem
block|{
name|friend
name|class
name|QTreeModel
decl_stmt|;
name|friend
name|class
name|QTreeWidget
decl_stmt|;
name|friend
name|class
name|QTreeWidgetPrivate
decl_stmt|;
name|friend
name|class
name|QTreeWidgetItemIterator
decl_stmt|;
name|friend
name|class
name|QTreeWidgetItemPrivate
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
name|QTreeWidgetItem
parameter_list|(
name|int
name|type
init|=
name|Type
parameter_list|)
function_decl|;
name|explicit
name|QTreeWidgetItem
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|strings
parameter_list|,
name|int
name|type
init|=
name|Type
parameter_list|)
function_decl|;
name|explicit
name|QTreeWidgetItem
parameter_list|(
name|QTreeWidget
modifier|*
name|view
parameter_list|,
name|int
name|type
init|=
name|Type
parameter_list|)
function_decl|;
name|QTreeWidgetItem
argument_list|(
argument|QTreeWidget *view
argument_list|,
argument|const QStringList&strings
argument_list|,
argument|int type = Type
argument_list|)
empty_stmt|;
name|QTreeWidgetItem
argument_list|(
argument|QTreeWidget *view
argument_list|,
argument|QTreeWidgetItem *after
argument_list|,
argument|int type = Type
argument_list|)
empty_stmt|;
name|explicit
name|QTreeWidgetItem
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|parent
parameter_list|,
name|int
name|type
init|=
name|Type
parameter_list|)
function_decl|;
name|QTreeWidgetItem
argument_list|(
argument|QTreeWidgetItem *parent
argument_list|,
argument|const QStringList&strings
argument_list|,
argument|int type = Type
argument_list|)
empty_stmt|;
name|QTreeWidgetItem
argument_list|(
argument|QTreeWidgetItem *parent
argument_list|,
argument|QTreeWidgetItem *after
argument_list|,
argument|int type = Type
argument_list|)
empty_stmt|;
name|QTreeWidgetItem
argument_list|(
specifier|const
name|QTreeWidgetItem
operator|&
name|other
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|QTreeWidgetItem
argument_list|()
expr_stmt|;
name|virtual
name|QTreeWidgetItem
operator|*
name|clone
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|QTreeWidget
operator|*
name|treeWidget
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
name|void
name|setExpanded
parameter_list|(
name|bool
name|expand
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|isExpanded
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|void
name|setFirstColumnSpanned
parameter_list|(
name|bool
name|span
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|isFirstColumnSpanned
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|void
name|setDisabled
parameter_list|(
name|bool
name|disabled
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|isDisabled
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|ChildIndicatorPolicy
block|{
name|ShowIndicator
block|,
name|DontShowIndicator
block|,
name|DontShowIndicatorWhenChildless
block|}
enum|;
name|void
name|setChildIndicatorPolicy
argument_list|(
name|QTreeWidgetItem
operator|::
name|ChildIndicatorPolicy
name|policy
argument_list|)
decl_stmt|;
name|QTreeWidgetItem
operator|::
name|ChildIndicatorPolicy
name|childIndicatorPolicy
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|ItemFlags
name|flags
argument_list|()
specifier|const
expr_stmt|;
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
argument_list|(
name|int
name|column
argument_list|)
decl|const
block|{
return|return
name|data
argument_list|(
name|column
argument_list|,
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
name|int
name|column
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
specifier|inline
name|QIcon
name|icon
argument_list|(
name|int
name|column
argument_list|)
decl|const
block|{
return|return
name|qvariant_cast
operator|<
name|QIcon
operator|>
operator|(
name|data
argument_list|(
name|column
argument_list|,
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
name|int
name|column
parameter_list|,
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
function_decl|;
specifier|inline
name|QString
name|statusTip
argument_list|(
name|int
name|column
argument_list|)
decl|const
block|{
return|return
name|data
argument_list|(
name|column
argument_list|,
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
name|int
name|column
parameter_list|,
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
argument_list|(
name|int
name|column
argument_list|)
decl|const
block|{
return|return
name|data
argument_list|(
name|column
argument_list|,
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
name|int
name|column
parameter_list|,
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
argument_list|(
name|int
name|column
argument_list|)
decl|const
block|{
return|return
name|data
argument_list|(
name|column
argument_list|,
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
name|int
name|column
parameter_list|,
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
argument_list|(
name|int
name|column
argument_list|)
decl|const
block|{
return|return
name|qvariant_cast
operator|<
name|QFont
operator|>
operator|(
name|data
argument_list|(
name|column
argument_list|,
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
name|int
name|column
parameter_list|,
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
function_decl|;
specifier|inline
name|int
name|textAlignment
argument_list|(
name|int
name|column
argument_list|)
decl|const
block|{
return|return
name|data
argument_list|(
name|column
argument_list|,
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
name|column
parameter_list|,
name|int
name|alignment
parameter_list|)
block|{
name|setData
argument_list|(
name|column
argument_list|,
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
argument_list|(
name|int
name|column
argument_list|)
decl|const
block|{
return|return
name|qvariant_cast
operator|<
name|QColor
operator|>
operator|(
name|data
argument_list|(
name|column
argument_list|,
name|Qt
operator|::
name|BackgroundColorRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setBackgroundColor
parameter_list|(
name|int
name|column
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|setData
argument_list|(
name|column
argument_list|,
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
argument_list|(
name|int
name|column
argument_list|)
decl|const
block|{
return|return
name|qvariant_cast
operator|<
name|QBrush
operator|>
operator|(
name|data
argument_list|(
name|column
argument_list|,
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
name|int
name|column
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|brush
parameter_list|)
block|{
name|setData
argument_list|(
name|column
argument_list|,
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
argument_list|(
name|int
name|column
argument_list|)
decl|const
block|{
return|return
name|qvariant_cast
operator|<
name|QColor
operator|>
operator|(
name|data
argument_list|(
name|column
argument_list|,
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
name|int
name|column
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|setData
argument_list|(
name|column
argument_list|,
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
argument_list|(
name|int
name|column
argument_list|)
decl|const
block|{
return|return
name|qvariant_cast
operator|<
name|QBrush
operator|>
operator|(
name|data
argument_list|(
name|column
argument_list|,
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
name|int
name|column
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|brush
parameter_list|)
block|{
name|setData
argument_list|(
name|column
argument_list|,
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
argument_list|(
argument|int column
argument_list|)
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
name|column
argument_list|,
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
name|int
name|column
argument_list|,
name|Qt
operator|::
name|CheckState
name|state
argument_list|)
block|{
name|setData
argument_list|(
name|column
argument_list|,
name|Qt
operator|::
name|CheckStateRole
argument_list|,
name|state
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|QSize
name|sizeHint
argument_list|(
name|int
name|column
argument_list|)
decl|const
block|{
return|return
name|qvariant_cast
operator|<
name|QSize
operator|>
operator|(
name|data
argument_list|(
name|column
argument_list|,
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
name|int
name|column
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
name|setData
argument_list|(
name|column
argument_list|,
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
name|column
argument_list|,
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
name|column
parameter_list|,
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
name|QTreeWidgetItem
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
name|QTreeWidgetItem
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QTreeWidgetItem
operator|&
name|other
operator|)
decl_stmt|;
specifier|inline
name|QTreeWidgetItem
operator|*
name|parent
argument_list|()
specifier|const
block|{
return|return
name|par
return|;
block|}
specifier|inline
name|QTreeWidgetItem
modifier|*
name|child
argument_list|(
name|int
name|index
argument_list|)
decl|const
block|{
if|if
condition|(
name|index
operator|<
literal|0
operator|||
name|index
operator|>=
name|children
operator|.
name|size
argument_list|()
condition|)
return|return
name|Q_NULLPTR
return|;
name|executePendingSort
argument_list|()
expr_stmt|;
return|return
name|children
operator|.
name|at
argument_list|(
name|index
argument_list|)
return|;
block|}
specifier|inline
name|int
name|childCount
argument_list|()
specifier|const
block|{
return|return
name|children
operator|.
name|count
argument_list|()
return|;
block|}
specifier|inline
name|int
name|columnCount
argument_list|()
specifier|const
block|{
return|return
name|values
operator|.
name|count
argument_list|()
return|;
block|}
specifier|inline
name|int
name|indexOfChild
argument_list|(
name|QTreeWidgetItem
operator|*
name|child
argument_list|)
decl|const
decl_stmt|;
name|void
name|addChild
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|child
parameter_list|)
function_decl|;
name|void
name|insertChild
parameter_list|(
name|int
name|index
parameter_list|,
name|QTreeWidgetItem
modifier|*
name|child
parameter_list|)
function_decl|;
name|void
name|removeChild
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|child
parameter_list|)
function_decl|;
name|QTreeWidgetItem
modifier|*
name|takeChild
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
name|void
name|addChildren
argument_list|(
specifier|const
name|QList
operator|<
name|QTreeWidgetItem
operator|*
operator|>
operator|&
name|children
argument_list|)
decl_stmt|;
name|void
name|insertChildren
argument_list|(
name|int
name|index
argument_list|,
specifier|const
name|QList
operator|<
name|QTreeWidgetItem
operator|*
operator|>
operator|&
name|children
argument_list|)
decl_stmt|;
name|QList
operator|<
name|QTreeWidgetItem
operator|*
operator|>
name|takeChildren
argument_list|()
expr_stmt|;
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
specifier|inline
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
argument_list|)
block|{
name|sortChildren
argument_list|(
name|column
argument_list|,
name|order
argument_list|,
name|false
argument_list|)
expr_stmt|;
block|}
name|protected
label|:
name|void
name|emitDataChanged
parameter_list|()
function_decl|;
name|private
label|:
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
name|QVariant
name|childrenCheckState
argument_list|(
name|int
name|column
argument_list|)
decl|const
decl_stmt|;
name|void
name|itemChanged
parameter_list|()
function_decl|;
name|void
name|executePendingSort
argument_list|()
specifier|const
expr_stmt|;
name|int
name|rtti
decl_stmt|;
comment|// One item has a vector of column entries. Each column has a vector of (role, value) pairs.
name|QVector
operator|<
name|QVector
operator|<
name|QWidgetItemData
operator|>
expr|>
name|values
expr_stmt|;
name|QTreeWidget
modifier|*
name|view
decl_stmt|;
name|QTreeWidgetItemPrivate
modifier|*
name|d
decl_stmt|;
name|QTreeWidgetItem
modifier|*
name|par
decl_stmt|;
name|QList
operator|<
name|QTreeWidgetItem
operator|*
operator|>
name|children
expr_stmt|;
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
name|QTreeWidgetItem
operator|::
name|setText
argument_list|(
argument|int column
argument_list|,
argument|const QString&atext
argument_list|)
block|{
name|setData
argument_list|(
name|column
argument_list|,
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
name|QTreeWidgetItem
operator|::
name|setIcon
argument_list|(
argument|int column
argument_list|,
argument|const QIcon&aicon
argument_list|)
block|{
name|setData
argument_list|(
name|column
argument_list|,
name|Qt
operator|::
name|DecorationRole
argument_list|,
name|aicon
argument_list|)
block|; }
ifndef|#
directive|ifndef
name|QT_NO_STATUSTIP
DECL|function|setStatusTip
specifier|inline
name|void
name|QTreeWidgetItem
operator|::
name|setStatusTip
argument_list|(
argument|int column
argument_list|,
argument|const QString&astatusTip
argument_list|)
block|{
name|setData
argument_list|(
name|column
argument_list|,
name|Qt
operator|::
name|StatusTipRole
argument_list|,
name|astatusTip
argument_list|)
block|; }
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
DECL|function|setToolTip
specifier|inline
name|void
name|QTreeWidgetItem
operator|::
name|setToolTip
argument_list|(
argument|int column
argument_list|,
argument|const QString&atoolTip
argument_list|)
block|{
name|setData
argument_list|(
name|column
argument_list|,
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
name|QTreeWidgetItem
operator|::
name|setWhatsThis
argument_list|(
argument|int column
argument_list|,
argument|const QString&awhatsThis
argument_list|)
block|{
name|setData
argument_list|(
name|column
argument_list|,
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
name|QTreeWidgetItem
operator|::
name|setFont
argument_list|(
argument|int column
argument_list|,
argument|const QFont&afont
argument_list|)
block|{
name|setData
argument_list|(
name|column
argument_list|,
name|Qt
operator|::
name|FontRole
argument_list|,
name|afont
argument_list|)
block|; }
DECL|function|indexOfChild
specifier|inline
name|int
name|QTreeWidgetItem
operator|::
name|indexOfChild
argument_list|(
argument|QTreeWidgetItem *achild
argument_list|)
specifier|const
block|{
name|executePendingSort
argument_list|()
block|;
return|return
name|children
operator|.
name|indexOf
argument_list|(
name|achild
argument_list|)
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
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
name|QTreeWidgetItem
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
name|QTreeWidgetItem
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
DECL|variable|QTreeWidgetPrivate
name|class
name|QTreeWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QTreeWidget
range|:
name|public
name|QTreeView
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|int columnCount READ columnCount WRITE setColumnCount
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int topLevelItemCount READ topLevelItemCount
argument_list|)
name|friend
name|class
name|QTreeModel
block|;
name|friend
name|class
name|QTreeWidgetItem
block|;
name|public
operator|:
name|explicit
name|QTreeWidget
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QTreeWidget
argument_list|()
block|;
name|int
name|columnCount
argument_list|()
specifier|const
block|;
name|void
name|setColumnCount
argument_list|(
argument|int columns
argument_list|)
block|;
name|QTreeWidgetItem
operator|*
name|invisibleRootItem
argument_list|()
specifier|const
block|;
name|QTreeWidgetItem
operator|*
name|topLevelItem
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|int
name|topLevelItemCount
argument_list|()
specifier|const
block|;
name|void
name|insertTopLevelItem
argument_list|(
argument|int index
argument_list|,
argument|QTreeWidgetItem *item
argument_list|)
block|;
name|void
name|addTopLevelItem
argument_list|(
name|QTreeWidgetItem
operator|*
name|item
argument_list|)
block|;
name|QTreeWidgetItem
operator|*
name|takeTopLevelItem
argument_list|(
argument|int index
argument_list|)
block|;
name|int
name|indexOfTopLevelItem
argument_list|(
argument|QTreeWidgetItem *item
argument_list|)
specifier|const
block|;
name|void
name|insertTopLevelItems
argument_list|(
argument|int index
argument_list|,
argument|const QList<QTreeWidgetItem*>&items
argument_list|)
block|;
name|void
name|addTopLevelItems
argument_list|(
specifier|const
name|QList
operator|<
name|QTreeWidgetItem
operator|*
operator|>
operator|&
name|items
argument_list|)
block|;
name|QTreeWidgetItem
operator|*
name|headerItem
argument_list|()
specifier|const
block|;
name|void
name|setHeaderItem
argument_list|(
name|QTreeWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|setHeaderLabels
argument_list|(
specifier|const
name|QStringList
operator|&
name|labels
argument_list|)
block|;
specifier|inline
name|void
name|setHeaderLabel
argument_list|(
specifier|const
name|QString
operator|&
name|label
argument_list|)
block|;
name|QTreeWidgetItem
operator|*
name|currentItem
argument_list|()
specifier|const
block|;
name|int
name|currentColumn
argument_list|()
specifier|const
block|;
name|void
name|setCurrentItem
argument_list|(
name|QTreeWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|setCurrentItem
argument_list|(
argument|QTreeWidgetItem *item
argument_list|,
argument|int column
argument_list|)
block|;
name|void
name|setCurrentItem
argument_list|(
argument|QTreeWidgetItem *item
argument_list|,
argument|int column
argument_list|,
argument|QItemSelectionModel::SelectionFlags command
argument_list|)
block|;
name|QTreeWidgetItem
operator|*
name|itemAt
argument_list|(
argument|const QPoint&p
argument_list|)
specifier|const
block|;
specifier|inline
name|QTreeWidgetItem
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
argument|const QTreeWidgetItem *item
argument_list|)
specifier|const
block|;
name|int
name|sortColumn
argument_list|()
specifier|const
block|;
name|void
name|sortItems
argument_list|(
argument|int column
argument_list|,
argument|Qt::SortOrder order
argument_list|)
block|;
name|void
name|editItem
argument_list|(
argument|QTreeWidgetItem *item
argument_list|,
argument|int column =
literal|0
argument_list|)
block|;
name|void
name|openPersistentEditor
argument_list|(
argument|QTreeWidgetItem *item
argument_list|,
argument|int column =
literal|0
argument_list|)
block|;
name|void
name|closePersistentEditor
argument_list|(
argument|QTreeWidgetItem *item
argument_list|,
argument|int column =
literal|0
argument_list|)
block|;
name|QWidget
operator|*
name|itemWidget
argument_list|(
argument|QTreeWidgetItem *item
argument_list|,
argument|int column
argument_list|)
specifier|const
block|;
name|void
name|setItemWidget
argument_list|(
argument|QTreeWidgetItem *item
argument_list|,
argument|int column
argument_list|,
argument|QWidget *widget
argument_list|)
block|;
specifier|inline
name|void
name|removeItemWidget
argument_list|(
argument|QTreeWidgetItem *item
argument_list|,
argument|int column
argument_list|)
block|;
name|bool
name|isItemSelected
argument_list|(
argument|const QTreeWidgetItem *item
argument_list|)
specifier|const
block|;
name|void
name|setItemSelected
argument_list|(
argument|const QTreeWidgetItem *item
argument_list|,
argument|bool select
argument_list|)
block|;
name|QList
operator|<
name|QTreeWidgetItem
operator|*
operator|>
name|selectedItems
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QTreeWidgetItem
operator|*
operator|>
name|findItems
argument_list|(
argument|const QString&text
argument_list|,
argument|Qt::MatchFlags flags
argument_list|,
argument|int column =
literal|0
argument_list|)
specifier|const
block|;
name|bool
name|isItemHidden
argument_list|(
argument|const QTreeWidgetItem *item
argument_list|)
specifier|const
block|;
name|void
name|setItemHidden
argument_list|(
argument|const QTreeWidgetItem *item
argument_list|,
argument|bool hide
argument_list|)
block|;
name|bool
name|isItemExpanded
argument_list|(
argument|const QTreeWidgetItem *item
argument_list|)
specifier|const
block|;
name|void
name|setItemExpanded
argument_list|(
argument|const QTreeWidgetItem *item
argument_list|,
argument|bool expand
argument_list|)
block|;
name|bool
name|isFirstItemColumnSpanned
argument_list|(
argument|const QTreeWidgetItem *item
argument_list|)
specifier|const
block|;
name|void
name|setFirstItemColumnSpanned
argument_list|(
argument|const QTreeWidgetItem *item
argument_list|,
argument|bool span
argument_list|)
block|;
name|QTreeWidgetItem
operator|*
name|itemAbove
argument_list|(
argument|const QTreeWidgetItem *item
argument_list|)
specifier|const
block|;
name|QTreeWidgetItem
operator|*
name|itemBelow
argument_list|(
argument|const QTreeWidgetItem *item
argument_list|)
specifier|const
block|;
name|void
name|setSelectionModel
argument_list|(
argument|QItemSelectionModel *selectionModel
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|scrollToItem
argument_list|(
argument|const QTreeWidgetItem *item
argument_list|,
argument|QAbstractItemView::ScrollHint hint = EnsureVisible
argument_list|)
block|;
name|void
name|expandItem
argument_list|(
specifier|const
name|QTreeWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|collapseItem
argument_list|(
specifier|const
name|QTreeWidgetItem
operator|*
name|item
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
argument|QTreeWidgetItem *item
argument_list|,
argument|int column
argument_list|)
block|;
name|void
name|itemClicked
argument_list|(
argument|QTreeWidgetItem *item
argument_list|,
argument|int column
argument_list|)
block|;
name|void
name|itemDoubleClicked
argument_list|(
argument|QTreeWidgetItem *item
argument_list|,
argument|int column
argument_list|)
block|;
name|void
name|itemActivated
argument_list|(
argument|QTreeWidgetItem *item
argument_list|,
argument|int column
argument_list|)
block|;
name|void
name|itemEntered
argument_list|(
argument|QTreeWidgetItem *item
argument_list|,
argument|int column
argument_list|)
block|;
name|void
name|itemChanged
argument_list|(
argument|QTreeWidgetItem *item
argument_list|,
argument|int column
argument_list|)
block|;
name|void
name|itemExpanded
argument_list|(
name|QTreeWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|itemCollapsed
argument_list|(
name|QTreeWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|currentItemChanged
argument_list|(
name|QTreeWidgetItem
operator|*
name|current
argument_list|,
name|QTreeWidgetItem
operator|*
name|previous
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
argument|const QList<QTreeWidgetItem *>&items
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
argument|const QList<QTreeWidgetItem*> items
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|virtual
name|bool
name|dropMimeData
argument_list|(
argument|QTreeWidgetItem *parent
argument_list|,
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
name|QList
operator|<
name|QTreeWidgetItem
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
argument|const QTreeWidgetItem *item
argument_list|,
argument|int column =
literal|0
argument_list|)
specifier|const
block|;
name|QModelIndex
name|indexFromItem
argument_list|(
argument|QTreeWidgetItem *item
argument_list|,
argument|int column =
literal|0
argument_list|)
specifier|const
block|;
comment|// ### Qt 6: remove
name|QTreeWidgetItem
operator|*
name|itemFromIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|void
name|dropEvent
argument_list|(
argument|QDropEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
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
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTreeWidget
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QTreeWidget
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
argument|void _q_emitItemExpanded(const QModelIndex&index)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitItemCollapsed(const QModelIndex&index)
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
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_selectionChanged(const QItemSelection&selected, const QItemSelection&deselected)
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|removeItemWidget
specifier|inline
name|void
name|QTreeWidget
operator|::
name|removeItemWidget
argument_list|(
argument|QTreeWidgetItem *item
argument_list|,
argument|int column
argument_list|)
block|{
name|setItemWidget
argument_list|(
name|item
argument_list|,
name|column
argument_list|,
name|Q_NULLPTR
argument_list|)
block|; }
DECL|function|itemAt
specifier|inline
name|QTreeWidgetItem
operator|*
name|QTreeWidget
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
DECL|function|setHeaderLabel
specifier|inline
name|void
name|QTreeWidget
operator|::
name|setHeaderLabel
argument_list|(
argument|const QString&alabel
argument_list|)
block|{
name|setHeaderLabels
argument_list|(
name|QStringList
argument_list|(
name|alabel
argument_list|)
argument_list|)
block|; }
DECL|function|setSelected
specifier|inline
name|void
name|QTreeWidgetItem
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
name|QTreeWidgetItem
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
name|QTreeWidgetItem
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
name|QTreeWidgetItem
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
begin_expr_stmt
DECL|function|setExpanded
specifier|inline
name|void
name|QTreeWidgetItem
operator|::
name|setExpanded
argument_list|(
argument|bool aexpand
argument_list|)
block|{
if|if
condition|(
name|view
condition|)
name|view
operator|->
name|setItemExpanded
argument_list|(
name|this
argument_list|,
name|aexpand
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isExpanded
specifier|inline
name|bool
name|QTreeWidgetItem
operator|::
name|isExpanded
argument_list|()
specifier|const
block|{
return|return
operator|(
name|view
operator|?
name|view
operator|->
name|isItemExpanded
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
DECL|function|setFirstColumnSpanned
specifier|inline
name|void
name|QTreeWidgetItem
operator|::
name|setFirstColumnSpanned
argument_list|(
argument|bool aspan
argument_list|)
block|{
if|if
condition|(
name|view
condition|)
name|view
operator|->
name|setFirstItemColumnSpanned
argument_list|(
name|this
argument_list|,
name|aspan
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isFirstColumnSpanned
specifier|inline
name|bool
name|QTreeWidgetItem
operator|::
name|isFirstColumnSpanned
argument_list|()
specifier|const
block|{
return|return
operator|(
name|view
operator|?
name|view
operator|->
name|isFirstItemColumnSpanned
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
DECL|function|setDisabled
specifier|inline
name|void
name|QTreeWidgetItem
operator|::
name|setDisabled
argument_list|(
argument|bool disabled
argument_list|)
block|{
name|setFlags
argument_list|(
name|disabled
operator|?
operator|(
name|flags
argument_list|()
operator|&
operator|~
name|Qt
operator|::
name|ItemIsEnabled
operator|)
operator|:
name|flags
argument_list|()
operator||
name|Qt
operator|::
name|ItemIsEnabled
argument_list|)
block|; }
DECL|function|isDisabled
specifier|inline
name|bool
name|QTreeWidgetItem
operator|::
name|isDisabled
argument_list|()
specifier|const
block|{
return|return
operator|!
operator|(
name|flags
argument_list|()
operator|&
name|Qt
operator|::
name|ItemIsEnabled
operator|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TREEWIDGET
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTREEWIDGET_H
end_comment
end_unit
