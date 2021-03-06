begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|,
name|QKeySequence
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+Q"
argument_list|,
literal|"File|Exit"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|actionsMenu
init|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&Actions"
argument_list|)
argument_list|)
decl_stmt|;
name|actionsMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Highlight List Items"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|highlightListItems
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|actionsMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Show Current List"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showList
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|insertMenu
init|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&Insert"
argument_list|)
argument_list|)
decl_stmt|;
name|insertMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&List"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|insertList
argument_list|()
argument_list|)
argument_list|,
name|QKeySequence
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+L"
argument_list|,
literal|"Insert|List"
argument_list|)
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
name|insertMenu
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|actionsMenu
argument_list|)
expr_stmt|;
name|editor
operator|=
operator|new
name|QTextEdit
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|document
operator|=
operator|new
name|QTextDocument
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|editor
operator|->
name|setDocument
argument_list|(
name|document
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|editor
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Text Document List Items"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|highlightListItems
name|void
name|MainWindow
operator|::
name|highlightListItems
parameter_list|()
block|{
name|QTextCursor
name|cursor
init|=
name|editor
operator|->
name|textCursor
argument_list|()
decl_stmt|;
name|QTextList
modifier|*
name|list
init|=
name|cursor
operator|.
name|currentList
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|list
condition|)
return|return;
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
comment|//! [0]
for|for
control|(
name|int
name|index
init|=
literal|0
init|;
name|index
operator|<
name|list
operator|->
name|count
argument_list|()
condition|;
operator|++
name|index
control|)
block|{
name|QTextBlock
name|listItem
init|=
name|list
operator|->
name|item
argument_list|(
name|index
argument_list|)
decl_stmt|;
comment|//! [0]
name|QTextBlockFormat
name|newBlockFormat
init|=
name|listItem
operator|.
name|blockFormat
argument_list|()
decl_stmt|;
name|newBlockFormat
operator|.
name|setBackground
argument_list|(
name|Qt
operator|::
name|lightGray
argument_list|)
expr_stmt|;
name|QTextCursor
name|itemCursor
init|=
name|cursor
decl_stmt|;
name|itemCursor
operator|.
name|setPosition
argument_list|(
name|listItem
operator|.
name|position
argument_list|()
argument_list|)
expr_stmt|;
comment|//itemCursor.movePosition(QTextCursor::StartOfBlock);
name|itemCursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|EndOfBlock
argument_list|,
name|QTextCursor
operator|::
name|KeepAnchor
argument_list|)
expr_stmt|;
name|itemCursor
operator|.
name|setBlockFormat
argument_list|(
name|newBlockFormat
argument_list|)
expr_stmt|;
comment|/* //! [1]         processListItem(listItem); //! [1]         */
comment|//! [2]
block|}
comment|//! [2]
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showList
name|void
name|MainWindow
operator|::
name|showList
parameter_list|()
block|{
name|QTextCursor
name|cursor
init|=
name|editor
operator|->
name|textCursor
argument_list|()
decl_stmt|;
name|QTextFrame
modifier|*
name|frame
init|=
name|cursor
operator|.
name|currentFrame
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|frame
condition|)
return|return;
name|QTreeWidget
modifier|*
name|treeWidget
init|=
operator|new
name|QTreeWidget
decl_stmt|;
name|treeWidget
operator|->
name|setColumnCount
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QStringList
name|headerLabels
decl_stmt|;
name|headerLabels
operator|<<
name|tr
argument_list|(
literal|"Lists"
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|setHeaderLabels
argument_list|(
name|headerLabels
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|parentItem
init|=
literal|0
decl_stmt|;
name|QTreeWidgetItem
modifier|*
name|item
decl_stmt|;
name|QTreeWidgetItem
modifier|*
name|lastItem
init|=
literal|0
decl_stmt|;
name|parentItems
operator|.
name|clear
argument_list|()
expr_stmt|;
name|previousItems
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|//! [3]
name|QTextFrame
operator|::
name|iterator
name|it
decl_stmt|;
for|for
control|(
name|it
operator|=
name|frame
operator|->
name|begin
argument_list|()
init|;
operator|!
operator|(
name|it
operator|.
name|atEnd
argument_list|()
operator|)
condition|;
operator|++
name|it
control|)
block|{
name|QTextBlock
name|block
init|=
name|it
operator|.
name|currentBlock
argument_list|()
decl_stmt|;
if|if
condition|(
name|block
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QTextList
modifier|*
name|list
init|=
name|block
operator|.
name|textList
argument_list|()
decl_stmt|;
if|if
condition|(
name|list
condition|)
block|{
name|int
name|index
init|=
name|list
operator|->
name|itemNumber
argument_list|(
name|block
argument_list|)
decl_stmt|;
comment|//! [3]
if|if
condition|(
name|index
operator|==
literal|0
condition|)
block|{
name|parentItems
operator|.
name|append
argument_list|(
name|parentItem
argument_list|)
expr_stmt|;
name|previousItems
operator|.
name|append
argument_list|(
name|lastItem
argument_list|)
expr_stmt|;
name|listStructures
operator|.
name|append
argument_list|(
name|list
argument_list|)
expr_stmt|;
name|parentItem
operator|=
name|lastItem
expr_stmt|;
name|lastItem
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|parentItem
operator|!=
literal|0
condition|)
name|item
operator|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|parentItem
argument_list|,
name|lastItem
argument_list|)
expr_stmt|;
else|else
name|item
operator|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|treeWidget
argument_list|,
name|lastItem
argument_list|)
expr_stmt|;
block|}
else|else
block|{
while|while
condition|(
name|parentItem
operator|!=
literal|0
operator|&&
name|listStructures
operator|.
name|last
argument_list|()
operator|!=
name|list
condition|)
block|{
name|listStructures
operator|.
name|pop_back
argument_list|()
expr_stmt|;
name|parentItem
operator|=
name|parentItems
operator|.
name|takeLast
argument_list|()
expr_stmt|;
name|lastItem
operator|=
name|previousItems
operator|.
name|takeLast
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|parentItem
operator|!=
literal|0
condition|)
name|item
operator|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|parentItem
argument_list|,
name|lastItem
argument_list|)
expr_stmt|;
else|else
name|item
operator|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|treeWidget
argument_list|,
name|lastItem
argument_list|)
expr_stmt|;
block|}
name|item
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|block
operator|.
name|text
argument_list|()
argument_list|)
expr_stmt|;
name|lastItem
operator|=
name|item
expr_stmt|;
comment|/* //! [4]                 processListItem(list, index); //! [4]                 */
comment|//! [5]
block|}
comment|//! [5] //! [6]
block|}
comment|//! [6] //! [7]
block|}
comment|//! [7]
name|treeWidget
operator|->
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"List Contents"
argument_list|)
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insertList
name|void
name|MainWindow
operator|::
name|insertList
parameter_list|()
block|{
name|QTextCursor
name|cursor
init|=
name|editor
operator|->
name|textCursor
argument_list|()
decl_stmt|;
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
name|QTextList
modifier|*
name|list
init|=
name|cursor
operator|.
name|currentList
argument_list|()
decl_stmt|;
name|QTextListFormat
name|listFormat
decl_stmt|;
if|if
condition|(
name|list
condition|)
name|listFormat
operator|=
name|list
operator|->
name|format
argument_list|()
expr_stmt|;
name|listFormat
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|ListDisc
argument_list|)
expr_stmt|;
name|listFormat
operator|.
name|setIndent
argument_list|(
name|listFormat
operator|.
name|indent
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertList
argument_list|(
name|listFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
