begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTABLEVIEW_H
end_ifndef
begin_define
DECL|macro|QTABLEVIEW_H
define|#
directive|define
name|QTABLEVIEW_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qabstractitemview.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_TABLEVIEW
DECL|variable|QHeaderView
name|class
name|QHeaderView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTableViewPrivate
name|class
name|QTableViewPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QTableView
range|:
name|public
name|QAbstractItemView
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool showGrid READ showGrid WRITE setShowGrid
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::PenStyle gridStyle READ gridStyle WRITE setGridStyle
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool sortingEnabled READ isSortingEnabled WRITE setSortingEnabled
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool wordWrap READ wordWrap WRITE setWordWrap
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool cornerButtonEnabled READ isCornerButtonEnabled WRITE setCornerButtonEnabled
argument_list|)
name|public
operator|:
name|explicit
name|QTableView
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QTableView
argument_list|()
block|;
name|void
name|setModel
argument_list|(
argument|QAbstractItemModel *model
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setRootIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setSelectionModel
argument_list|(
argument|QItemSelectionModel *selectionModel
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|doItemsLayout
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QHeaderView
operator|*
name|horizontalHeader
argument_list|()
specifier|const
block|;
name|QHeaderView
operator|*
name|verticalHeader
argument_list|()
specifier|const
block|;
name|void
name|setHorizontalHeader
argument_list|(
name|QHeaderView
operator|*
name|header
argument_list|)
block|;
name|void
name|setVerticalHeader
argument_list|(
name|QHeaderView
operator|*
name|header
argument_list|)
block|;
name|int
name|rowViewportPosition
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|int
name|rowAt
argument_list|(
argument|int y
argument_list|)
specifier|const
block|;
name|void
name|setRowHeight
argument_list|(
argument|int row
argument_list|,
argument|int height
argument_list|)
block|;
name|int
name|rowHeight
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|int
name|columnViewportPosition
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|int
name|columnAt
argument_list|(
argument|int x
argument_list|)
specifier|const
block|;
name|void
name|setColumnWidth
argument_list|(
argument|int column
argument_list|,
argument|int width
argument_list|)
block|;
name|int
name|columnWidth
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|bool
name|isRowHidden
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|void
name|setRowHidden
argument_list|(
argument|int row
argument_list|,
argument|bool hide
argument_list|)
block|;
name|bool
name|isColumnHidden
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|void
name|setColumnHidden
argument_list|(
argument|int column
argument_list|,
argument|bool hide
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
name|bool
name|showGrid
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|PenStyle
name|gridStyle
argument_list|()
specifier|const
block|;
name|void
name|setGridStyle
argument_list|(
argument|Qt::PenStyle style
argument_list|)
block|;
name|void
name|setWordWrap
argument_list|(
argument|bool on
argument_list|)
block|;
name|bool
name|wordWrap
argument_list|()
specifier|const
block|;
name|void
name|setCornerButtonEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|isCornerButtonEnabled
argument_list|()
specifier|const
block|;
name|QRect
name|visualRect
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|scrollTo
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|ScrollHint hint = EnsureVisible
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QModelIndex
name|indexAt
argument_list|(
argument|const QPoint&p
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setSpan
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|int rowSpan
argument_list|,
argument|int columnSpan
argument_list|)
block|;
name|int
name|rowSpan
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|;
name|int
name|columnSpan
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|;
name|void
name|clearSpans
argument_list|()
block|;
name|void
name|sortByColumn
argument_list|(
argument|int column
argument_list|,
argument|Qt::SortOrder order
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|selectRow
argument_list|(
argument|int row
argument_list|)
block|;
name|void
name|selectColumn
argument_list|(
argument|int column
argument_list|)
block|;
name|void
name|hideRow
argument_list|(
argument|int row
argument_list|)
block|;
name|void
name|hideColumn
argument_list|(
argument|int column
argument_list|)
block|;
name|void
name|showRow
argument_list|(
argument|int row
argument_list|)
block|;
name|void
name|showColumn
argument_list|(
argument|int column
argument_list|)
block|;
name|void
name|resizeRowToContents
argument_list|(
argument|int row
argument_list|)
block|;
name|void
name|resizeRowsToContents
argument_list|()
block|;
name|void
name|resizeColumnToContents
argument_list|(
argument|int column
argument_list|)
block|;
name|void
name|resizeColumnsToContents
argument_list|()
block|;
name|void
name|sortByColumn
argument_list|(
argument|int column
argument_list|)
block|;
name|void
name|setShowGrid
argument_list|(
argument|bool show
argument_list|)
block|;
name|protected
name|Q_SLOTS
operator|:
name|void
name|rowMoved
argument_list|(
argument|int row
argument_list|,
argument|int oldIndex
argument_list|,
argument|int newIndex
argument_list|)
block|;
name|void
name|columnMoved
argument_list|(
argument|int column
argument_list|,
argument|int oldIndex
argument_list|,
argument|int newIndex
argument_list|)
block|;
name|void
name|rowResized
argument_list|(
argument|int row
argument_list|,
argument|int oldHeight
argument_list|,
argument|int newHeight
argument_list|)
block|;
name|void
name|columnResized
argument_list|(
argument|int column
argument_list|,
argument|int oldWidth
argument_list|,
argument|int newWidth
argument_list|)
block|;
name|void
name|rowCountChanged
argument_list|(
argument|int oldCount
argument_list|,
argument|int newCount
argument_list|)
block|;
name|void
name|columnCountChanged
argument_list|(
argument|int oldCount
argument_list|,
argument|int newCount
argument_list|)
block|;
name|protected
operator|:
name|QTableView
argument_list|(
name|QTableViewPrivate
operator|&
argument_list|,
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|void
name|scrollContentsBy
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QStyleOptionViewItem
name|viewOptions
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|timerEvent
argument_list|(
argument|QTimerEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|int
name|horizontalOffset
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|verticalOffset
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QModelIndex
name|moveCursor
argument_list|(
argument|CursorAction cursorAction
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setSelection
argument_list|(
argument|const QRect&rect
argument_list|,
argument|QItemSelectionModel::SelectionFlags command
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QRegion
name|visualRegionForSelection
argument_list|(
argument|const QItemSelection&selection
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QModelIndexList
name|selectedIndexes
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|updateGeometries
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|viewportSizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|sizeHintForRow
argument_list|(
argument|int row
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|sizeHintForColumn
argument_list|(
argument|int column
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|verticalScrollbarAction
argument_list|(
argument|int action
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|horizontalScrollbarAction
argument_list|(
argument|int action
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isIndexHidden
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|selectionChanged
argument_list|(
argument|const QItemSelection&selected
argument_list|,
argument|const QItemSelection&deselected
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|currentChanged
argument_list|(
argument|const QModelIndex&current
argument_list|,
argument|const QModelIndex&previous
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|friend
name|class
name|QAccessibleItemView
block|;
name|int
name|visualIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTableView
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QTableView
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_selectRow(int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_selectColumn(int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateSpanInsertedRows(QModelIndex,int,int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateSpanInsertedColumns(QModelIndex,int,int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateSpanRemovedRows(QModelIndex,int,int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateSpanRemovedColumns(QModelIndex,int,int)
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TABLEVIEW
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTABLEVIEW_H
end_comment
end_unit
