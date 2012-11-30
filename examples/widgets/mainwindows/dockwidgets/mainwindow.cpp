begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTDIALOG
end_ifndef
begin_include
include|#
directive|include
file|<QtPrintSupport>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
name|textEdit
operator|=
operator|new
name|QTextEdit
expr_stmt|;
name|setCentralWidget
argument_list|(
name|textEdit
argument_list|)
expr_stmt|;
name|createActions
argument_list|()
expr_stmt|;
name|createMenus
argument_list|()
expr_stmt|;
name|createToolBars
argument_list|()
expr_stmt|;
name|createStatusBar
argument_list|()
expr_stmt|;
name|createDockWindows
argument_list|()
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Dock Widgets"
argument_list|)
argument_list|)
expr_stmt|;
name|newLetter
argument_list|()
expr_stmt|;
name|setUnifiedTitleAndToolBarOnMac
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|newLetter
name|void
name|MainWindow
operator|::
name|newLetter
parameter_list|()
block|{
name|textEdit
operator|->
name|clear
argument_list|()
expr_stmt|;
name|QTextCursor
name|cursor
argument_list|(
name|textEdit
operator|->
name|textCursor
argument_list|()
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
name|QTextFrame
modifier|*
name|topFrame
init|=
name|cursor
operator|.
name|currentFrame
argument_list|()
decl_stmt|;
name|QTextFrameFormat
name|topFrameFormat
init|=
name|topFrame
operator|->
name|frameFormat
argument_list|()
decl_stmt|;
name|topFrameFormat
operator|.
name|setPadding
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|topFrame
operator|->
name|setFrameFormat
argument_list|(
name|topFrameFormat
argument_list|)
expr_stmt|;
name|QTextCharFormat
name|textFormat
decl_stmt|;
name|QTextCharFormat
name|boldFormat
decl_stmt|;
name|boldFormat
operator|.
name|setFontWeight
argument_list|(
name|QFont
operator|::
name|Bold
argument_list|)
expr_stmt|;
name|QTextCharFormat
name|italicFormat
decl_stmt|;
name|italicFormat
operator|.
name|setFontItalic
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QTextTableFormat
name|tableFormat
decl_stmt|;
name|tableFormat
operator|.
name|setBorder
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|tableFormat
operator|.
name|setCellPadding
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|tableFormat
operator|.
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertTable
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
name|tableFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"The Firm"
argument_list|,
name|boldFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"321 City Street"
argument_list|,
name|textFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Industry Park"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Some Country"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|setPosition
argument_list|(
name|topFrame
operator|->
name|lastPosition
argument_list|()
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|QDate
operator|::
name|currentDate
argument_list|()
operator|.
name|toString
argument_list|(
literal|"d MMMM yyyy"
argument_list|)
argument_list|,
name|textFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Dear "
argument_list|,
name|textFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"NAME"
argument_list|,
name|italicFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|","
argument_list|,
name|textFormat
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|3
condition|;
operator|++
name|i
control|)
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"Yours sincerely,"
argument_list|)
argument_list|,
name|textFormat
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|3
condition|;
operator|++
name|i
control|)
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"The Boss"
argument_list|,
name|textFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"ADDRESS"
argument_list|,
name|italicFormat
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|print
name|void
name|MainWindow
operator|::
name|print
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_PRINTDIALOG
name|QTextDocument
modifier|*
name|document
init|=
name|textEdit
operator|->
name|document
argument_list|()
decl_stmt|;
name|QPrinter
name|printer
decl_stmt|;
name|QPrintDialog
name|dlg
argument_list|(
operator|&
name|printer
argument_list|,
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|dlg
operator|.
name|exec
argument_list|()
operator|!=
name|QDialog
operator|::
name|Accepted
condition|)
block|{
return|return;
block|}
name|document
operator|->
name|print
argument_list|(
operator|&
name|printer
argument_list|)
expr_stmt|;
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"Ready"
argument_list|)
argument_list|,
literal|2000
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|save
name|void
name|MainWindow
operator|::
name|save
parameter_list|()
block|{
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getSaveFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Choose a file name"
argument_list|)
argument_list|,
literal|"."
argument_list|,
name|tr
argument_list|(
literal|"HTML (*.html *.htm)"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QFile
name|file
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|WriteOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
condition|)
block|{
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Dock Widgets"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Cannot write file %1:\n%2."
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|QTextStream
name|out
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|QApplication
operator|::
name|setOverrideCursor
argument_list|(
name|Qt
operator|::
name|WaitCursor
argument_list|)
expr_stmt|;
name|out
operator|<<
name|textEdit
operator|->
name|toHtml
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|restoreOverrideCursor
argument_list|()
expr_stmt|;
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"Saved '%1'"
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
argument_list|,
literal|2000
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|undo
name|void
name|MainWindow
operator|::
name|undo
parameter_list|()
block|{
name|QTextDocument
modifier|*
name|document
init|=
name|textEdit
operator|->
name|document
argument_list|()
decl_stmt|;
name|document
operator|->
name|undo
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|insertCustomer
name|void
name|MainWindow
operator|::
name|insertCustomer
parameter_list|(
specifier|const
name|QString
modifier|&
name|customer
parameter_list|)
block|{
if|if
condition|(
name|customer
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QStringList
name|customerList
init|=
name|customer
operator|.
name|split
argument_list|(
literal|", "
argument_list|)
decl_stmt|;
name|QTextDocument
modifier|*
name|document
init|=
name|textEdit
operator|->
name|document
argument_list|()
decl_stmt|;
name|QTextCursor
name|cursor
init|=
name|document
operator|->
name|find
argument_list|(
literal|"NAME"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|cursor
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|customerList
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QTextCursor
name|oldcursor
init|=
name|cursor
decl_stmt|;
name|cursor
operator|=
name|document
operator|->
name|find
argument_list|(
literal|"ADDRESS"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|cursor
operator|.
name|isNull
argument_list|()
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|customerList
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|customerList
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
block|}
else|else
name|oldcursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|addParagraph
name|void
name|MainWindow
operator|::
name|addParagraph
parameter_list|(
specifier|const
name|QString
modifier|&
name|paragraph
parameter_list|)
block|{
if|if
condition|(
name|paragraph
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QTextDocument
modifier|*
name|document
init|=
name|textEdit
operator|->
name|document
argument_list|()
decl_stmt|;
name|QTextCursor
name|cursor
init|=
name|document
operator|->
name|find
argument_list|(
name|tr
argument_list|(
literal|"Yours sincerely,"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|cursor
operator|.
name|isNull
argument_list|()
condition|)
return|return;
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|PreviousBlock
argument_list|,
name|QTextCursor
operator|::
name|MoveAnchor
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|paragraph
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|about
name|void
name|MainWindow
operator|::
name|about
parameter_list|()
block|{
name|QMessageBox
operator|::
name|about
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"About Dock Widgets"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The<b>Dock Widgets</b> example demonstrates how to "
literal|"use Qt's dock widgets. You can enter your own text, "
literal|"click a customer to add a customer name and "
literal|"address, and click standard paragraphs to add them."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createActions
name|void
name|MainWindow
operator|::
name|createActions
parameter_list|()
block|{
name|newLetterAct
operator|=
operator|new
name|QAction
argument_list|(
name|QIcon
argument_list|(
literal|":/images/new.png"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"&New Letter"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|newLetterAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|New
argument_list|)
expr_stmt|;
name|newLetterAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Create a new form letter"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|newLetterAct
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
name|newLetter
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|saveAct
operator|=
operator|new
name|QAction
argument_list|(
name|QIcon
argument_list|(
literal|":/images/save.png"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"&Save..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|saveAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Save
argument_list|)
expr_stmt|;
name|saveAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Save the current form letter"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|saveAct
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
name|save
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|printAct
operator|=
operator|new
name|QAction
argument_list|(
name|QIcon
argument_list|(
literal|":/images/print.png"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"&Print..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|printAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Print
argument_list|)
expr_stmt|;
name|printAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Print the current form letter"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|printAct
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
name|print
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|undoAct
operator|=
operator|new
name|QAction
argument_list|(
name|QIcon
argument_list|(
literal|":/images/undo.png"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"&Undo"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|undoAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Undo
argument_list|)
expr_stmt|;
name|undoAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Undo the last editing action"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|undoAct
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
name|undo
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|quitAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Quit"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|quitAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Quit
argument_list|)
expr_stmt|;
name|quitAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Quit the application"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitAct
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
name|aboutAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&About"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|aboutAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Show the application's About box"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|aboutAct
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
name|about
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|aboutQtAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"About&Qt"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|aboutQtAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Show the Qt library's About box"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|aboutQtAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|aboutQt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createMenus
name|void
name|MainWindow
operator|::
name|createMenus
parameter_list|()
block|{
name|fileMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&File"
argument_list|)
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|newLetterAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|saveAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|printAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|quitAct
argument_list|)
expr_stmt|;
name|editMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Edit"
argument_list|)
argument_list|)
expr_stmt|;
name|editMenu
operator|->
name|addAction
argument_list|(
name|undoAct
argument_list|)
expr_stmt|;
name|viewMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&View"
argument_list|)
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|helpMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Help"
argument_list|)
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutAct
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutQtAct
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createToolBars
name|void
name|MainWindow
operator|::
name|createToolBars
parameter_list|()
block|{
name|fileToolBar
operator|=
name|addToolBar
argument_list|(
name|tr
argument_list|(
literal|"File"
argument_list|)
argument_list|)
expr_stmt|;
name|fileToolBar
operator|->
name|addAction
argument_list|(
name|newLetterAct
argument_list|)
expr_stmt|;
name|fileToolBar
operator|->
name|addAction
argument_list|(
name|saveAct
argument_list|)
expr_stmt|;
name|fileToolBar
operator|->
name|addAction
argument_list|(
name|printAct
argument_list|)
expr_stmt|;
name|editToolBar
operator|=
name|addToolBar
argument_list|(
name|tr
argument_list|(
literal|"Edit"
argument_list|)
argument_list|)
expr_stmt|;
name|editToolBar
operator|->
name|addAction
argument_list|(
name|undoAct
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|createStatusBar
name|void
name|MainWindow
operator|::
name|createStatusBar
parameter_list|()
block|{
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"Ready"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|createDockWindows
name|void
name|MainWindow
operator|::
name|createDockWindows
parameter_list|()
block|{
name|QDockWidget
modifier|*
name|dock
init|=
operator|new
name|QDockWidget
argument_list|(
name|tr
argument_list|(
literal|"Customers"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|dock
operator|->
name|setAllowedAreas
argument_list|(
name|Qt
operator|::
name|LeftDockWidgetArea
operator||
name|Qt
operator|::
name|RightDockWidgetArea
argument_list|)
expr_stmt|;
name|customerList
operator|=
operator|new
name|QListWidget
argument_list|(
name|dock
argument_list|)
expr_stmt|;
name|customerList
operator|->
name|addItems
argument_list|(
name|QStringList
argument_list|()
operator|<<
literal|"John Doe, Harmony Enterprises, 12 Lakeside, Ambleton"
operator|<<
literal|"Jane Doe, Memorabilia, 23 Watersedge, Beaton"
operator|<<
literal|"Tammy Shea, Tiblanka, 38 Sea Views, Carlton"
operator|<<
literal|"Tim Sheen, Caraba Gifts, 48 Ocean Way, Deal"
operator|<<
literal|"Sol Harvey, Chicos Coffee, 53 New Springs, Eccleston"
operator|<<
literal|"Sally Hobart, Tiroli Tea, 67 Long River, Fedula"
argument_list|)
expr_stmt|;
name|dock
operator|->
name|setWidget
argument_list|(
name|customerList
argument_list|)
expr_stmt|;
name|addDockWidget
argument_list|(
name|Qt
operator|::
name|RightDockWidgetArea
argument_list|,
name|dock
argument_list|)
expr_stmt|;
name|viewMenu
operator|->
name|addAction
argument_list|(
name|dock
operator|->
name|toggleViewAction
argument_list|()
argument_list|)
expr_stmt|;
name|dock
operator|=
operator|new
name|QDockWidget
argument_list|(
name|tr
argument_list|(
literal|"Paragraphs"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|paragraphsList
operator|=
operator|new
name|QListWidget
argument_list|(
name|dock
argument_list|)
expr_stmt|;
name|paragraphsList
operator|->
name|addItems
argument_list|(
name|QStringList
argument_list|()
operator|<<
literal|"Thank you for your payment which we have received today."
operator|<<
literal|"Your order has been dispatched and should be with you "
literal|"within 28 days."
operator|<<
literal|"We have dispatched those items that were in stock. The "
literal|"rest of your order will be dispatched once all the "
literal|"remaining items have arrived at our warehouse. No "
literal|"additional shipping charges will be made."
operator|<<
literal|"You made a small overpayment (less than $5) which we "
literal|"will keep on account for you, or return at your request."
operator|<<
literal|"You made a small underpayment (less than $1), but we have "
literal|"sent your order anyway. We'll add this underpayment to "
literal|"your next bill."
operator|<<
literal|"Unfortunately you did not send enough money. Please remit "
literal|"an additional $. Your order will be dispatched as soon as "
literal|"the complete amount has been received."
operator|<<
literal|"You made an overpayment (more than $5). Do you wish to "
literal|"buy more items, or should we return the excess to you?"
argument_list|)
expr_stmt|;
name|dock
operator|->
name|setWidget
argument_list|(
name|paragraphsList
argument_list|)
expr_stmt|;
name|addDockWidget
argument_list|(
name|Qt
operator|::
name|RightDockWidgetArea
argument_list|,
name|dock
argument_list|)
expr_stmt|;
name|viewMenu
operator|->
name|addAction
argument_list|(
name|dock
operator|->
name|toggleViewAction
argument_list|()
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|customerList
argument_list|,
name|SIGNAL
argument_list|(
name|currentTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|insertCustomer
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|paragraphsList
argument_list|,
name|SIGNAL
argument_list|(
name|currentTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|addParagraph
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
end_unit
