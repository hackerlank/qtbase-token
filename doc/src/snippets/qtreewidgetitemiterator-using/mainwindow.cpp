begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|itemsMenu
init|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&Items"
argument_list|)
argument_list|)
decl_stmt|;
name|insertAction
operator|=
name|itemsMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Insert Item"
argument_list|)
argument_list|)
expr_stmt|;
name|removeAction
operator|=
name|itemsMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Remove Item"
argument_list|)
argument_list|)
expr_stmt|;
name|removeAction
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|itemsMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|ascendingAction
operator|=
name|itemsMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Sort in&Ascending Order"
argument_list|)
argument_list|)
expr_stmt|;
name|descendingAction
operator|=
name|itemsMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Sort in&Descending Order"
argument_list|)
argument_list|)
expr_stmt|;
name|autoSortAction
operator|=
name|itemsMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Automatically Sort Items"
argument_list|)
argument_list|)
expr_stmt|;
name|autoSortAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|itemsMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|QAction
modifier|*
name|findItemsAction
init|=
name|itemsMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Find Items"
argument_list|)
argument_list|)
decl_stmt|;
name|findItemsAction
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+F"
argument_list|)
argument_list|)
expr_stmt|;
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
name|itemsMenu
argument_list|)
expr_stmt|;
comment|/*  For convenient quoting:     QTreeWidget *treeWidget = new QTreeWidget(this); */
name|treeWidget
operator|=
operator|new
name|QTreeWidget
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|setColumnCount
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|QStringList
name|headers
decl_stmt|;
name|headers
operator|<<
name|tr
argument_list|(
literal|"Subject"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Default"
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|setHeaderLabels
argument_list|(
name|headers
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
name|ascendingAction
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
name|sortAscending
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|autoSortAction
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
name|updateSortItems
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|descendingAction
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
name|sortDescending
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|findItemsAction
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
name|findItems
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|insertAction
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
name|insertItem
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|removeAction
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
name|removeItem
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|treeWidget
argument_list|,
name|SIGNAL
argument_list|(
name|currentItemChanged
argument_list|(
name|QTreeWidgetItem
operator|*
argument_list|,
name|QTreeWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateMenus
argument_list|(
name|QTreeWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|setupTreeItems
argument_list|()
expr_stmt|;
name|updateMenus
argument_list|(
name|treeWidget
operator|->
name|currentItem
argument_list|()
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|treeWidget
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Tree Widget"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setupTreeItems
name|void
name|MainWindow
operator|::
name|setupTreeItems
parameter_list|()
block|{
name|QTreeWidgetItem
modifier|*
name|planets
init|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|treeWidget
argument_list|)
decl_stmt|;
name|planets
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|tr
argument_list|(
literal|"Planets"
argument_list|)
argument_list|)
expr_stmt|;
operator|(
operator|new
name|QTreeWidgetItem
argument_list|(
name|planets
argument_list|)
operator|)
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|tr
argument_list|(
literal|"Mercury"
argument_list|)
argument_list|)
expr_stmt|;
operator|(
operator|new
name|QTreeWidgetItem
argument_list|(
name|planets
argument_list|)
operator|)
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|tr
argument_list|(
literal|"Venus"
argument_list|)
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|earthItem
init|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|planets
argument_list|)
decl_stmt|;
name|earthItem
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|tr
argument_list|(
literal|"Earth"
argument_list|)
argument_list|)
expr_stmt|;
name|earthItem
operator|->
name|setText
argument_list|(
literal|1
argument_list|,
name|tr
argument_list|(
literal|"Yes"
argument_list|)
argument_list|)
expr_stmt|;
operator|(
operator|new
name|QTreeWidgetItem
argument_list|(
name|planets
argument_list|)
operator|)
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|tr
argument_list|(
literal|"Mars"
argument_list|)
argument_list|)
expr_stmt|;
operator|(
operator|new
name|QTreeWidgetItem
argument_list|(
name|planets
argument_list|)
operator|)
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|tr
argument_list|(
literal|"Jupiter"
argument_list|)
argument_list|)
expr_stmt|;
operator|(
operator|new
name|QTreeWidgetItem
argument_list|(
name|planets
argument_list|)
operator|)
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|tr
argument_list|(
literal|"Saturn"
argument_list|)
argument_list|)
expr_stmt|;
operator|(
operator|new
name|QTreeWidgetItem
argument_list|(
name|planets
argument_list|)
operator|)
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|tr
argument_list|(
literal|"Uranus"
argument_list|)
argument_list|)
expr_stmt|;
operator|(
operator|new
name|QTreeWidgetItem
argument_list|(
name|planets
argument_list|)
operator|)
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|tr
argument_list|(
literal|"Neptune"
argument_list|)
argument_list|)
expr_stmt|;
operator|(
operator|new
name|QTreeWidgetItem
argument_list|(
name|planets
argument_list|)
operator|)
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|tr
argument_list|(
literal|"Pluto"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|findItems
name|void
name|MainWindow
operator|::
name|findItems
parameter_list|()
block|{
name|QString
name|itemText
init|=
name|QInputDialog
operator|::
name|getText
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Find Items"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Text to find:"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|itemText
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
comment|//! [0]
name|QTreeWidgetItemIterator
name|it
argument_list|(
name|treeWidget
argument_list|)
decl_stmt|;
while|while
condition|(
operator|*
name|it
condition|)
block|{
if|if
condition|(
operator|(
operator|*
name|it
operator|)
operator|->
name|text
argument_list|(
literal|0
argument_list|)
operator|==
name|itemText
condition|)
operator|(
operator|*
name|it
operator|)
operator|->
name|setSelected
argument_list|(
literal|true
argument_list|)
expr_stmt|;
operator|++
name|it
expr_stmt|;
block|}
comment|//! [0]
block|}
end_function
begin_function
DECL|function|insertItem
name|void
name|MainWindow
operator|::
name|insertItem
parameter_list|()
block|{
name|QTreeWidgetItem
modifier|*
name|currentItem
init|=
name|treeWidget
operator|->
name|currentItem
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|currentItem
condition|)
return|return;
name|QString
name|itemText
init|=
name|QInputDialog
operator|::
name|getText
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Insert Item"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Input text for the new item:"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|itemText
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QTreeWidgetItem
modifier|*
name|parent
init|=
name|currentItem
operator|->
name|parent
argument_list|()
decl_stmt|;
name|QTreeWidgetItem
modifier|*
name|newItem
decl_stmt|;
if|if
condition|(
name|parent
condition|)
name|newItem
operator|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|parent
argument_list|,
name|treeWidget
operator|->
name|currentItem
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|newItem
operator|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|treeWidget
argument_list|,
name|treeWidget
operator|->
name|currentItem
argument_list|()
argument_list|)
expr_stmt|;
name|newItem
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|itemText
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeItem
name|void
name|MainWindow
operator|::
name|removeItem
parameter_list|()
block|{
name|QTreeWidgetItem
modifier|*
name|currentItem
init|=
name|treeWidget
operator|->
name|currentItem
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|currentItem
condition|)
return|return;
name|QTreeWidgetItem
modifier|*
name|parent
init|=
name|currentItem
operator|->
name|parent
argument_list|()
decl_stmt|;
name|int
name|index
decl_stmt|;
if|if
condition|(
name|parent
condition|)
block|{
name|index
operator|=
name|parent
operator|->
name|indexOfChild
argument_list|(
name|treeWidget
operator|->
name|currentItem
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|parent
operator|->
name|takeChild
argument_list|(
name|index
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|index
operator|=
name|treeWidget
operator|->
name|indexOfTopLevelItem
argument_list|(
name|treeWidget
operator|->
name|currentItem
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|treeWidget
operator|->
name|takeTopLevelItem
argument_list|(
name|index
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|sortAscending
name|void
name|MainWindow
operator|::
name|sortAscending
parameter_list|()
block|{
name|treeWidget
operator|->
name|sortItems
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|AscendingOrder
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sortDescending
name|void
name|MainWindow
operator|::
name|sortDescending
parameter_list|()
block|{
name|treeWidget
operator|->
name|sortItems
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|DescendingOrder
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateMenus
name|void
name|MainWindow
operator|::
name|updateMenus
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|current
parameter_list|)
block|{
name|insertAction
operator|->
name|setEnabled
argument_list|(
name|current
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|removeAction
operator|->
name|setEnabled
argument_list|(
name|current
operator|!=
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateSortItems
name|void
name|MainWindow
operator|::
name|updateSortItems
parameter_list|()
block|{
name|ascendingAction
operator|->
name|setEnabled
argument_list|(
operator|!
name|autoSortAction
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|descendingAction
operator|->
name|setEnabled
argument_list|(
operator|!
name|autoSortAction
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|setSortingEnabled
argument_list|(
name|autoSortAction
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
