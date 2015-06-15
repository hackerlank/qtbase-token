begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTABLEVIEW_P_H
end_ifndef
begin_define
DECL|macro|QTABLEVIEW_P_H
define|#
directive|define
name|QTABLEVIEW_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
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
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLinkedList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSet>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|"private/qabstractitemview_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TABLEVIEW
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/** \internal * * This is a list of span with a binary index to look up quickly a span at a certain index. * * The index is a map of map. * spans are mentaly divided into sub spans so that the start of any subspans doesn't overlap * with any other subspans. There is no real representation of the subspans. * The key of the first map is the row where the subspan starts, the value of the first map is * a list (map) of all subspans that starts at the same row.  It is indexed with its row */
name|class
name|Q_AUTOTEST_EXPORT
name|QSpanCollection
block|{
name|public
label|:
struct|struct
name|Span
block|{
name|int
name|m_top
decl_stmt|;
name|int
name|m_left
decl_stmt|;
name|int
name|m_bottom
decl_stmt|;
name|int
name|m_right
decl_stmt|;
name|bool
name|will_be_deleted
decl_stmt|;
name|Span
argument_list|()
operator|:
name|m_top
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|m_left
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|m_bottom
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|m_right
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|will_be_deleted
argument_list|(
argument|false
argument_list|)
block|{ }
name|Span
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|int rowCount
argument_list|,
argument|int columnCount
argument_list|)
operator|:
name|m_top
argument_list|(
name|row
argument_list|)
operator|,
name|m_left
argument_list|(
name|column
argument_list|)
operator|,
name|m_bottom
argument_list|(
name|row
operator|+
name|rowCount
operator|-
literal|1
argument_list|)
operator|,
name|m_right
argument_list|(
name|column
operator|+
name|columnCount
operator|-
literal|1
argument_list|)
operator|,
name|will_be_deleted
argument_list|(
argument|false
argument_list|)
block|{ }
specifier|inline
name|int
name|top
argument_list|()
specifier|const
block|{
return|return
name|m_top
return|;
block|}
specifier|inline
name|int
name|left
argument_list|()
specifier|const
block|{
return|return
name|m_left
return|;
block|}
specifier|inline
name|int
name|bottom
argument_list|()
specifier|const
block|{
return|return
name|m_bottom
return|;
block|}
specifier|inline
name|int
name|right
argument_list|()
specifier|const
block|{
return|return
name|m_right
return|;
block|}
specifier|inline
name|int
name|height
argument_list|()
specifier|const
block|{
return|return
name|m_bottom
operator|-
name|m_top
operator|+
literal|1
return|;
block|}
specifier|inline
name|int
name|width
argument_list|()
specifier|const
block|{
return|return
name|m_right
operator|-
name|m_left
operator|+
literal|1
return|;
block|}
block|}
struct|;
operator|~
name|QSpanCollection
argument_list|()
block|{
name|qDeleteAll
argument_list|(
name|spans
argument_list|)
block|;     }
name|void
name|addSpan
argument_list|(
name|Span
operator|*
name|span
argument_list|)
expr_stmt|;
name|void
name|updateSpan
parameter_list|(
name|Span
modifier|*
name|span
parameter_list|,
name|int
name|old_height
parameter_list|)
function_decl|;
name|Span
modifier|*
name|spanAt
argument_list|(
name|int
name|x
argument_list|,
name|int
name|y
argument_list|)
decl|const
decl_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|QList
operator|<
name|Span
operator|*
operator|>
name|spansInRect
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
specifier|const
expr_stmt|;
name|void
name|updateInsertedRows
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
name|void
name|updateInsertedColumns
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
name|void
name|updateRemovedRows
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
name|void
name|updateRemovedColumns
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|QT_BUILD_INTERNAL
name|bool
name|checkConsistency
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
typedef|typedef
name|QLinkedList
operator|<
name|Span
operator|*
operator|>
name|SpanList
expr_stmt|;
name|SpanList
name|spans
decl_stmt|;
comment|//lists of all spans
name|private
label|:
comment|//the indexes are negative so the QMap::lowerBound do what i need.
typedef|typedef
name|QMap
operator|<
name|int
operator|,
name|Span
operator|*
operator|>
name|SubIndex
expr_stmt|;
typedef|typedef
name|QMap
operator|<
name|int
operator|,
name|SubIndex
operator|>
name|Index
expr_stmt|;
name|Index
name|index
decl_stmt|;
name|bool
name|cleanSpanSubIndex
parameter_list|(
name|SubIndex
modifier|&
name|subindex
parameter_list|,
name|int
name|end
parameter_list|,
name|bool
name|update
init|=
name|false
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QSpanCollection
operator|::
name|Span
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QTableViewPrivate
range|:
name|public
name|QAbstractItemViewPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTableView
argument_list|)
name|public
operator|:
name|QTableViewPrivate
argument_list|()
operator|:
name|showGrid
argument_list|(
name|true
argument_list|)
block|,
name|gridStyle
argument_list|(
name|Qt
operator|::
name|SolidLine
argument_list|)
block|,
name|rowSectionAnchor
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|columnSectionAnchor
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|columnResizeTimerID
argument_list|(
literal|0
argument_list|)
block|,
name|rowResizeTimerID
argument_list|(
literal|0
argument_list|)
block|,
name|horizontalHeader
argument_list|(
literal|0
argument_list|)
block|,
name|verticalHeader
argument_list|(
literal|0
argument_list|)
block|,
name|sortingEnabled
argument_list|(
name|false
argument_list|)
block|,
name|geometryRecursionBlock
argument_list|(
name|false
argument_list|)
block|,
name|visualCursor
argument_list|(
argument|QPoint()
argument_list|)
block|{
name|wrapItemText
operator|=
name|true
block|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|overwrite
operator|=
name|true
block|;
endif|#
directive|endif
block|}
name|void
name|init
argument_list|()
block|;
name|void
name|trimHiddenSelections
argument_list|(
argument|QItemSelectionRange *range
argument_list|)
specifier|const
block|;
specifier|inline
name|bool
name|isHidden
argument_list|(
argument|int row
argument_list|,
argument|int col
argument_list|)
specifier|const
block|{
return|return
name|verticalHeader
operator|->
name|isSectionHidden
argument_list|(
name|row
argument_list|)
operator|||
name|horizontalHeader
operator|->
name|isSectionHidden
argument_list|(
name|col
argument_list|)
return|;
block|}
specifier|inline
name|int
name|visualRow
argument_list|(
argument|int logicalRow
argument_list|)
specifier|const
block|{
return|return
name|verticalHeader
operator|->
name|visualIndex
argument_list|(
name|logicalRow
argument_list|)
return|;
block|}
specifier|inline
name|int
name|visualColumn
argument_list|(
argument|int logicalCol
argument_list|)
specifier|const
block|{
return|return
name|horizontalHeader
operator|->
name|visualIndex
argument_list|(
name|logicalCol
argument_list|)
return|;
block|}
specifier|inline
name|int
name|logicalRow
argument_list|(
argument|int visualRow
argument_list|)
specifier|const
block|{
return|return
name|verticalHeader
operator|->
name|logicalIndex
argument_list|(
name|visualRow
argument_list|)
return|;
block|}
specifier|inline
name|int
name|logicalColumn
argument_list|(
argument|int visualCol
argument_list|)
specifier|const
block|{
return|return
name|horizontalHeader
operator|->
name|logicalIndex
argument_list|(
name|visualCol
argument_list|)
return|;
block|}
specifier|inline
name|int
name|accessibleTable2Index
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|{
specifier|const
name|int
name|vHeader
operator|=
name|verticalHeader
operator|?
literal|1
operator|:
literal|0
block|;
return|return
operator|(
name|index
operator|.
name|row
argument_list|()
operator|+
operator|(
name|horizontalHeader
condition|?
literal|1
else|:
literal|0
operator|)
operator|)
operator|*
operator|(
name|index
operator|.
name|model
argument_list|()
operator|->
name|columnCount
argument_list|()
operator|+
name|vHeader
operator|)
operator|+
name|index
operator|.
name|column
argument_list|()
operator|+
name|vHeader
return|;
block|}
name|int
name|sectionSpanEndLogical
argument_list|(
argument|const QHeaderView *header
argument_list|,
argument|int logical
argument_list|,
argument|int span
argument_list|)
specifier|const
block|;
name|int
name|sectionSpanSize
argument_list|(
argument|const QHeaderView *header
argument_list|,
argument|int logical
argument_list|,
argument|int span
argument_list|)
specifier|const
block|;
name|bool
name|spanContainsSection
argument_list|(
argument|const QHeaderView *header
argument_list|,
argument|int logical
argument_list|,
argument|int spanLogical
argument_list|,
argument|int span
argument_list|)
specifier|const
block|;
name|void
name|drawAndClipSpans
argument_list|(
argument|const QRegion&area
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|,
argument|QBitArray *drawn
argument_list|,
argument|int firstVisualRow
argument_list|,
argument|int lastVisualRow
argument_list|,
argument|int firstVisualColumn
argument_list|,
argument|int lastVisualColumn
argument_list|)
block|;
name|void
name|drawCell
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|QStyleOptionViewItem
operator|&
name|option
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|int
name|widthHintForIndex
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|int hint
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|)
specifier|const
block|;
name|int
name|heightHintForIndex
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|int hint
argument_list|,
argument|QStyleOptionViewItem&option
argument_list|)
specifier|const
block|;
name|bool
name|showGrid
block|;
name|Qt
operator|::
name|PenStyle
name|gridStyle
block|;
name|int
name|rowSectionAnchor
block|;
name|int
name|columnSectionAnchor
block|;
name|int
name|columnResizeTimerID
block|;
name|int
name|rowResizeTimerID
block|;
name|QVector
operator|<
name|int
operator|>
name|columnsToUpdate
block|;
name|QVector
operator|<
name|int
operator|>
name|rowsToUpdate
block|;
name|QHeaderView
operator|*
name|horizontalHeader
block|;
name|QHeaderView
operator|*
name|verticalHeader
block|;
name|QWidget
operator|*
name|cornerWidget
block|;
name|bool
name|sortingEnabled
block|;
name|bool
name|geometryRecursionBlock
block|;
name|QPoint
name|visualCursor
block|;
comment|// (Row,column) cell coordinates to track through span navigation.
name|QSpanCollection
name|spans
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
name|QSpanCollection
operator|::
name|Span
name|span
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|;
specifier|inline
name|int
name|rowSpan
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|{
return|return
name|span
argument_list|(
name|row
argument_list|,
name|column
argument_list|)
operator|.
name|height
argument_list|()
return|;
block|}
specifier|inline
name|int
name|columnSpan
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|{
return|return
name|span
argument_list|(
name|row
argument_list|,
name|column
argument_list|)
operator|.
name|width
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|hasSpans
argument_list|()
specifier|const
block|{
return|return
operator|!
name|spans
operator|.
name|spans
operator|.
name|isEmpty
argument_list|()
return|;
block|}
specifier|inline
name|int
name|rowSpanHeight
argument_list|(
argument|int row
argument_list|,
argument|int span
argument_list|)
specifier|const
block|{
return|return
name|sectionSpanSize
argument_list|(
name|verticalHeader
argument_list|,
name|row
argument_list|,
name|span
argument_list|)
return|;
block|}
specifier|inline
name|int
name|columnSpanWidth
argument_list|(
argument|int column
argument_list|,
argument|int span
argument_list|)
specifier|const
block|{
return|return
name|sectionSpanSize
argument_list|(
name|horizontalHeader
argument_list|,
name|column
argument_list|,
name|span
argument_list|)
return|;
block|}
specifier|inline
name|int
name|rowSpanEndLogical
argument_list|(
argument|int row
argument_list|,
argument|int span
argument_list|)
specifier|const
block|{
return|return
name|sectionSpanEndLogical
argument_list|(
name|verticalHeader
argument_list|,
name|row
argument_list|,
name|span
argument_list|)
return|;
block|}
specifier|inline
name|int
name|columnSpanEndLogical
argument_list|(
argument|int column
argument_list|,
argument|int span
argument_list|)
specifier|const
block|{
return|return
name|sectionSpanEndLogical
argument_list|(
name|horizontalHeader
argument_list|,
name|column
argument_list|,
name|span
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isRowHidden
argument_list|(
argument|int row
argument_list|)
specifier|const
block|{
return|return
name|verticalHeader
operator|->
name|isSectionHidden
argument_list|(
name|row
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isColumnHidden
argument_list|(
argument|int column
argument_list|)
specifier|const
block|{
return|return
name|horizontalHeader
operator|->
name|isSectionHidden
argument_list|(
name|column
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isCellEnabled
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|{
return|return
name|isIndexEnabled
argument_list|(
name|model
operator|->
name|index
argument_list|(
name|row
argument_list|,
name|column
argument_list|,
name|root
argument_list|)
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isVisualRowHiddenOrDisabled
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|{
name|int
name|r
operator|=
name|logicalRow
argument_list|(
name|row
argument_list|)
block|;
name|int
name|c
operator|=
name|logicalColumn
argument_list|(
name|column
argument_list|)
block|;
return|return
name|isRowHidden
argument_list|(
name|r
argument_list|)
operator|||
operator|!
name|isCellEnabled
argument_list|(
name|r
argument_list|,
name|c
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isVisualColumnHiddenOrDisabled
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|{
name|int
name|r
operator|=
name|logicalRow
argument_list|(
name|row
argument_list|)
block|;
name|int
name|c
operator|=
name|logicalColumn
argument_list|(
name|column
argument_list|)
block|;
return|return
name|isColumnHidden
argument_list|(
name|c
argument_list|)
operator|||
operator|!
name|isCellEnabled
argument_list|(
name|r
argument_list|,
name|c
argument_list|)
return|;
block|}
name|QRect
name|visualSpanRect
argument_list|(
argument|const QSpanCollection::Span&span
argument_list|)
specifier|const
block|;
name|void
name|_q_selectRow
argument_list|(
argument|int row
argument_list|)
block|;
name|void
name|_q_selectColumn
argument_list|(
argument|int column
argument_list|)
block|;
name|void
name|selectRow
argument_list|(
argument|int row
argument_list|,
argument|bool anchor
argument_list|)
block|;
name|void
name|selectColumn
argument_list|(
argument|int column
argument_list|,
argument|bool anchor
argument_list|)
block|;
name|void
name|_q_updateSpanInsertedRows
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|void
name|_q_updateSpanInsertedColumns
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|void
name|_q_updateSpanRemovedRows
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|void
name|_q_updateSpanRemovedColumns
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TABLEVIEW
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTABLEVIEW_P_H
end_comment
end_unit
