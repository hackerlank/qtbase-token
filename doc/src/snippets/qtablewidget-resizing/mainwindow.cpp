begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
name|QMenu
modifier|*
name|fileMenu
init|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&File"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|quitAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|)
decl_stmt|;
name|quitAction
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+Q"
argument_list|)
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|tableMenu
init|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&Table"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|tableWidthAction
init|=
name|tableMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Change Table&Width"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|tableHeightAction
init|=
name|tableMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Change Table&Height"
argument_list|)
argument_list|)
decl_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|fileMenu
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tableMenu
argument_list|)
expr_stmt|;
comment|//! [0]
name|tableWidget
operator|=
operator|new
name|QTableWidget
argument_list|(
name|this
argument_list|)
expr_stmt|;
comment|//! [0]
name|tableWidget
operator|->
name|setSelectionMode
argument_list|(
name|QAbstractItemView
operator|::
name|ExtendedSelection
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|tableWidthAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|changeWidth
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|tableHeightAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|changeHeight
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|setupTableItems
argument_list|()
expr_stmt|;
name|setCentralWidget
argument_list|(
name|tableWidget
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Table Widget Resizing"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setupTableItems
name|void
name|MainWindow
operator|::
name|setupTableItems
parameter_list|()
block|{
comment|//! [1]
name|tableWidget
operator|->
name|setRowCount
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|tableWidget
operator|->
name|setColumnCount
argument_list|(
literal|5
argument_list|)
expr_stmt|;
comment|//! [1]
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|tableWidget
operator|->
name|rowCount
argument_list|()
condition|;
operator|++
name|row
control|)
block|{
for|for
control|(
name|int
name|column
init|=
literal|0
init|;
name|column
operator|<
name|tableWidget
operator|->
name|columnCount
argument_list|()
condition|;
operator|++
name|column
control|)
block|{
comment|//! [2]
name|QTableWidgetItem
modifier|*
name|newItem
init|=
operator|new
name|QTableWidgetItem
argument_list|(
name|tr
argument_list|(
literal|"%1"
argument_list|)
operator|.
name|arg
argument_list|(
operator|(
name|row
operator|+
literal|1
operator|)
operator|*
operator|(
name|column
operator|+
literal|1
operator|)
argument_list|)
argument_list|)
decl_stmt|;
name|tableWidget
operator|->
name|setItem
argument_list|(
name|row
argument_list|,
name|column
argument_list|,
name|newItem
argument_list|)
expr_stmt|;
comment|//! [2]
block|}
block|}
block|}
end_function
begin_function
DECL|function|changeWidth
name|void
name|MainWindow
operator|::
name|changeWidth
parameter_list|()
block|{
name|bool
name|ok
decl_stmt|;
name|int
name|newWidth
init|=
name|QInputDialog
operator|::
name|getInteger
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Change table width"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Input the number of columns required (1-20):"
argument_list|)
argument_list|,
name|tableWidget
operator|->
name|columnCount
argument_list|()
argument_list|,
literal|1
argument_list|,
literal|20
argument_list|,
literal|1
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
condition|)
name|tableWidget
operator|->
name|setColumnCount
argument_list|(
name|newWidth
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|changeHeight
name|void
name|MainWindow
operator|::
name|changeHeight
parameter_list|()
block|{
name|bool
name|ok
decl_stmt|;
name|int
name|newHeight
init|=
name|QInputDialog
operator|::
name|getInteger
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Change table height"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Input the number of rows required (1-20):"
argument_list|)
argument_list|,
name|tableWidget
operator|->
name|rowCount
argument_list|()
argument_list|,
literal|1
argument_list|,
literal|20
argument_list|,
literal|1
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
condition|)
name|tableWidget
operator|->
name|setRowCount
argument_list|(
name|newHeight
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
