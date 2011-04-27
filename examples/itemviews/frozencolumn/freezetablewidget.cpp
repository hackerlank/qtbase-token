begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"freezetablewidget.h"
end_include
begin_comment
comment|//! [constructor]
end_comment
begin_constructor
DECL|function|FreezeTableWidget
name|FreezeTableWidget
operator|::
name|FreezeTableWidget
parameter_list|(
name|QAbstractItemModel
modifier|*
name|model
parameter_list|)
block|{
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|frozenTableView
operator|=
operator|new
name|QTableView
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|init
argument_list|()
expr_stmt|;
comment|//connect the headers and scrollbars of both tableviews together
name|connect
argument_list|(
name|horizontalHeader
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|sectionResized
argument_list|(
name|int
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
name|updateSectionWidth
argument_list|(
name|int
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
name|verticalHeader
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|sectionResized
argument_list|(
name|int
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
name|updateSectionHeight
argument_list|(
name|int
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
name|frozenTableView
operator|->
name|verticalScrollBar
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|verticalScrollBar
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|setValue
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|verticalScrollBar
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|frozenTableView
operator|->
name|verticalScrollBar
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|setValue
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [constructor]
end_comment
begin_destructor
DECL|function|~FreezeTableWidget
name|FreezeTableWidget
operator|::
name|~
name|FreezeTableWidget
parameter_list|()
block|{
operator|delete
name|frozenTableView
expr_stmt|;
block|}
end_destructor
begin_comment
comment|//! [init part1]
end_comment
begin_function
DECL|function|init
name|void
name|FreezeTableWidget
operator|::
name|init
parameter_list|()
block|{
name|frozenTableView
operator|->
name|setModel
argument_list|(
name|model
argument_list|()
argument_list|)
expr_stmt|;
name|frozenTableView
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|NoFocus
argument_list|)
expr_stmt|;
name|frozenTableView
operator|->
name|verticalHeader
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
name|frozenTableView
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|setResizeMode
argument_list|(
name|QHeaderView
operator|::
name|Fixed
argument_list|)
expr_stmt|;
name|viewport
argument_list|()
operator|->
name|stackUnder
argument_list|(
name|frozenTableView
argument_list|)
expr_stmt|;
comment|//! [init part1]
comment|//! [init part2]
name|frozenTableView
operator|->
name|setStyleSheet
argument_list|(
literal|"QTableView { border: none;"
literal|"background-color: #8EDE21;"
literal|"selection-background-color: #999}"
argument_list|)
expr_stmt|;
comment|//for demo purposes
name|frozenTableView
operator|->
name|setSelectionModel
argument_list|(
name|selectionModel
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|col
init|=
literal|1
init|;
name|col
operator|<
name|model
argument_list|()
operator|->
name|columnCount
argument_list|()
condition|;
name|col
operator|++
control|)
name|frozenTableView
operator|->
name|setColumnHidden
argument_list|(
name|col
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|frozenTableView
operator|->
name|setColumnWidth
argument_list|(
literal|0
argument_list|,
name|columnWidth
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|frozenTableView
operator|->
name|setHorizontalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAlwaysOff
argument_list|)
expr_stmt|;
name|frozenTableView
operator|->
name|setVerticalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAlwaysOff
argument_list|)
expr_stmt|;
name|frozenTableView
operator|->
name|show
argument_list|()
expr_stmt|;
name|updateFrozenTableGeometry
argument_list|()
expr_stmt|;
name|setHorizontalScrollMode
argument_list|(
name|ScrollPerPixel
argument_list|)
expr_stmt|;
name|setVerticalScrollMode
argument_list|(
name|ScrollPerPixel
argument_list|)
expr_stmt|;
name|frozenTableView
operator|->
name|setVerticalScrollMode
argument_list|(
name|ScrollPerPixel
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [init part2]
end_comment
begin_comment
comment|//! [sections]
end_comment
begin_function
DECL|function|updateSectionWidth
name|void
name|FreezeTableWidget
operator|::
name|updateSectionWidth
parameter_list|(
name|int
name|logicalIndex
parameter_list|,
name|int
parameter_list|,
name|int
name|newSize
parameter_list|)
block|{
if|if
condition|(
name|logicalIndex
operator|==
literal|0
condition|)
block|{
name|frozenTableView
operator|->
name|setColumnWidth
argument_list|(
literal|0
argument_list|,
name|newSize
argument_list|)
expr_stmt|;
name|updateFrozenTableGeometry
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|updateSectionHeight
name|void
name|FreezeTableWidget
operator|::
name|updateSectionHeight
parameter_list|(
name|int
name|logicalIndex
parameter_list|,
name|int
parameter_list|,
name|int
name|newSize
parameter_list|)
block|{
name|frozenTableView
operator|->
name|setRowHeight
argument_list|(
name|logicalIndex
argument_list|,
name|newSize
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [sections]
end_comment
begin_comment
comment|//! [resize]
end_comment
begin_function
DECL|function|resizeEvent
name|void
name|FreezeTableWidget
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|QTableView
operator|::
name|resizeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|updateFrozenTableGeometry
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [resize]
end_comment
begin_comment
comment|//! [navigate]
end_comment
begin_function
DECL|function|moveCursor
name|QModelIndex
name|FreezeTableWidget
operator|::
name|moveCursor
parameter_list|(
name|CursorAction
name|cursorAction
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
parameter_list|)
block|{
name|QModelIndex
name|current
init|=
name|QTableView
operator|::
name|moveCursor
argument_list|(
name|cursorAction
argument_list|,
name|modifiers
argument_list|)
decl_stmt|;
if|if
condition|(
name|cursorAction
operator|==
name|MoveLeft
operator|&&
name|current
operator|.
name|column
argument_list|()
operator|>
literal|0
operator|&&
name|visualRect
argument_list|(
name|current
argument_list|)
operator|.
name|topLeft
argument_list|()
operator|.
name|x
argument_list|()
operator|<
name|frozenTableView
operator|->
name|columnWidth
argument_list|(
literal|0
argument_list|)
condition|)
block|{
specifier|const
name|int
name|newValue
init|=
name|horizontalScrollBar
argument_list|()
operator|->
name|value
argument_list|()
operator|+
name|visualRect
argument_list|(
name|current
argument_list|)
operator|.
name|topLeft
argument_list|()
operator|.
name|x
argument_list|()
operator|-
name|frozenTableView
operator|->
name|columnWidth
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|horizontalScrollBar
argument_list|()
operator|->
name|setValue
argument_list|(
name|newValue
argument_list|)
expr_stmt|;
block|}
return|return
name|current
return|;
block|}
end_function
begin_comment
comment|//! [navigate]
end_comment
begin_function
DECL|function|scrollTo
name|void
name|FreezeTableWidget
operator|::
name|scrollTo
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
name|ScrollHint
name|hint
parameter_list|)
block|{
if|if
condition|(
name|index
operator|.
name|column
argument_list|()
operator|>
literal|0
condition|)
name|QTableView
operator|::
name|scrollTo
argument_list|(
name|index
argument_list|,
name|hint
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [geometry]
end_comment
begin_function
DECL|function|updateFrozenTableGeometry
name|void
name|FreezeTableWidget
operator|::
name|updateFrozenTableGeometry
parameter_list|()
block|{
name|frozenTableView
operator|->
name|setGeometry
argument_list|(
name|verticalHeader
argument_list|()
operator|->
name|width
argument_list|()
operator|+
name|frameWidth
argument_list|()
argument_list|,
name|frameWidth
argument_list|()
argument_list|,
name|columnWidth
argument_list|(
literal|0
argument_list|)
argument_list|,
name|viewport
argument_list|()
operator|->
name|height
argument_list|()
operator|+
name|horizontalHeader
argument_list|()
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [geometry]
end_comment
end_unit
