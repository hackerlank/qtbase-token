begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
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
comment|//! [1] //! [2]
block|{
name|textEdit
operator|=
operator|new
name|QPlainTextEdit
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
name|readSettings
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|textEdit
operator|->
name|document
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|contentsChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|documentWasModified
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|setCurrentFile
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|setUnifiedTitleAndToolBarOnMac
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|closeEvent
name|void
name|MainWindow
operator|::
name|closeEvent
parameter_list|(
name|QCloseEvent
modifier|*
name|event
parameter_list|)
comment|//! [3] //! [4]
block|{
if|if
condition|(
name|maybeSave
argument_list|()
condition|)
block|{
name|writeSettings
argument_list|()
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|newFile
name|void
name|MainWindow
operator|::
name|newFile
parameter_list|()
comment|//! [5] //! [6]
block|{
if|if
condition|(
name|maybeSave
argument_list|()
condition|)
block|{
name|textEdit
operator|->
name|clear
argument_list|()
expr_stmt|;
name|setCurrentFile
argument_list|(
literal|""
argument_list|)
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
DECL|function|open
name|void
name|MainWindow
operator|::
name|open
parameter_list|()
comment|//! [7] //! [8]
block|{
if|if
condition|(
name|maybeSave
argument_list|()
condition|)
block|{
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
name|loadFile
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|save
name|bool
name|MainWindow
operator|::
name|save
parameter_list|()
comment|//! [9] //! [10]
block|{
if|if
condition|(
name|curFile
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
return|return
name|saveAs
argument_list|()
return|;
block|}
else|else
block|{
return|return
name|saveFile
argument_list|(
name|curFile
argument_list|)
return|;
block|}
block|}
end_function
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_function
DECL|function|saveAs
name|bool
name|MainWindow
operator|::
name|saveAs
parameter_list|()
comment|//! [11] //! [12]
block|{
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getSaveFileName
argument_list|(
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|false
return|;
return|return
name|saveFile
argument_list|(
name|fileName
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_function
DECL|function|about
name|void
name|MainWindow
operator|::
name|about
parameter_list|()
comment|//! [13] //! [14]
block|{
name|QMessageBox
operator|::
name|about
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"About Application"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The<b>Application</b> example demonstrates how to "
literal|"write modern GUI applications using Qt, with a menu bar, "
literal|"toolbars, and a status bar."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_function
DECL|function|documentWasModified
name|void
name|MainWindow
operator|::
name|documentWasModified
parameter_list|()
comment|//! [15] //! [16]
block|{
name|setWindowModified
argument_list|(
name|textEdit
operator|->
name|document
argument_list|()
operator|->
name|isModified
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_function
DECL|function|createActions
name|void
name|MainWindow
operator|::
name|createActions
parameter_list|()
comment|//! [17] //! [18]
block|{
name|newAct
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
literal|"&New"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|newAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|New
argument_list|)
expr_stmt|;
name|newAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Create a new file"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|newAct
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
name|newFile
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [19]
name|openAct
operator|=
operator|new
name|QAction
argument_list|(
name|QIcon
argument_list|(
literal|":/images/open.png"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"&Open..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|openAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Open
argument_list|)
expr_stmt|;
name|openAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Open an existing file"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|openAct
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
name|open
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [18] //! [19]
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
literal|"&Save"
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
literal|"Save the document to disk"
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
name|saveAsAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Save&As..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|saveAsAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|SaveAs
argument_list|)
expr_stmt|;
name|saveAsAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Save the document under a new name"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|saveAsAct
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
name|saveAs
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [20]
name|exitAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|exitAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Quit
argument_list|)
expr_stmt|;
comment|//! [20]
name|exitAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Exit the application"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|exitAct
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
comment|//! [21]
name|cutAct
operator|=
operator|new
name|QAction
argument_list|(
name|QIcon
argument_list|(
literal|":/images/cut.png"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Cu&t"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
comment|//! [21]
name|cutAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Cut
argument_list|)
expr_stmt|;
name|cutAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Cut the current selection's contents to the "
literal|"clipboard"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|cutAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|textEdit
argument_list|,
name|SLOT
argument_list|(
name|cut
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|copyAct
operator|=
operator|new
name|QAction
argument_list|(
name|QIcon
argument_list|(
literal|":/images/copy.png"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"&Copy"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|copyAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Copy
argument_list|)
expr_stmt|;
name|copyAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Copy the current selection's contents to the "
literal|"clipboard"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|copyAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|textEdit
argument_list|,
name|SLOT
argument_list|(
name|copy
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|pasteAct
operator|=
operator|new
name|QAction
argument_list|(
name|QIcon
argument_list|(
literal|":/images/paste.png"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"&Paste"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|pasteAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Paste
argument_list|)
expr_stmt|;
name|pasteAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Paste the clipboard's contents into the current "
literal|"selection"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|pasteAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|textEdit
argument_list|,
name|SLOT
argument_list|(
name|paste
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
comment|//! [22]
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
comment|//! [22]
comment|//! [23]
name|cutAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
comment|//! [23] //! [24]
name|copyAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|textEdit
argument_list|,
name|SIGNAL
argument_list|(
name|copyAvailable
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|cutAct
argument_list|,
name|SLOT
argument_list|(
name|setEnabled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|textEdit
argument_list|,
name|SIGNAL
argument_list|(
name|copyAvailable
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|copyAct
argument_list|,
name|SLOT
argument_list|(
name|setEnabled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [24]
end_comment
begin_comment
comment|//! [25] //! [26]
end_comment
begin_function
DECL|function|createMenus
name|void
name|MainWindow
operator|::
name|createMenus
parameter_list|()
comment|//! [25] //! [27]
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
name|newAct
argument_list|)
expr_stmt|;
comment|//! [28]
name|fileMenu
operator|->
name|addAction
argument_list|(
name|openAct
argument_list|)
expr_stmt|;
comment|//! [28]
name|fileMenu
operator|->
name|addAction
argument_list|(
name|saveAct
argument_list|)
expr_stmt|;
comment|//! [26]
name|fileMenu
operator|->
name|addAction
argument_list|(
name|saveAsAct
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
name|exitAct
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
name|cutAct
argument_list|)
expr_stmt|;
name|editMenu
operator|->
name|addAction
argument_list|(
name|copyAct
argument_list|)
expr_stmt|;
name|editMenu
operator|->
name|addAction
argument_list|(
name|pasteAct
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
begin_comment
comment|//! [27]
end_comment
begin_comment
comment|//! [29] //! [30]
end_comment
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
name|newAct
argument_list|)
expr_stmt|;
comment|//! [29] //! [31]
name|fileToolBar
operator|->
name|addAction
argument_list|(
name|openAct
argument_list|)
expr_stmt|;
comment|//! [31]
name|fileToolBar
operator|->
name|addAction
argument_list|(
name|saveAct
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
name|cutAct
argument_list|)
expr_stmt|;
name|editToolBar
operator|->
name|addAction
argument_list|(
name|copyAct
argument_list|)
expr_stmt|;
name|editToolBar
operator|->
name|addAction
argument_list|(
name|pasteAct
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [30]
end_comment
begin_comment
comment|//! [32]
end_comment
begin_function
DECL|function|createStatusBar
name|void
name|MainWindow
operator|::
name|createStatusBar
parameter_list|()
comment|//! [32] //! [33]
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
comment|//! [33]
end_comment
begin_comment
comment|//! [34] //! [35]
end_comment
begin_function
DECL|function|readSettings
name|void
name|MainWindow
operator|::
name|readSettings
parameter_list|()
comment|//! [34] //! [36]
block|{
name|QSettings
name|settings
argument_list|(
literal|"QtProject"
argument_list|,
literal|"Application Example"
argument_list|)
decl_stmt|;
name|QPoint
name|pos
init|=
name|settings
operator|.
name|value
argument_list|(
literal|"pos"
argument_list|,
name|QPoint
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
argument_list|)
operator|.
name|toPoint
argument_list|()
decl_stmt|;
name|QSize
name|size
init|=
name|settings
operator|.
name|value
argument_list|(
literal|"size"
argument_list|,
name|QSize
argument_list|(
literal|400
argument_list|,
literal|400
argument_list|)
argument_list|)
operator|.
name|toSize
argument_list|()
decl_stmt|;
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|pos
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [35] //! [36]
end_comment
begin_comment
comment|//! [37] //! [38]
end_comment
begin_function
DECL|function|writeSettings
name|void
name|MainWindow
operator|::
name|writeSettings
parameter_list|()
comment|//! [37] //! [39]
block|{
name|QSettings
name|settings
argument_list|(
literal|"QtProject"
argument_list|,
literal|"Application Example"
argument_list|)
decl_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
literal|"pos"
argument_list|,
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
literal|"size"
argument_list|,
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [38] //! [39]
end_comment
begin_comment
comment|//! [40]
end_comment
begin_function
DECL|function|maybeSave
name|bool
name|MainWindow
operator|::
name|maybeSave
parameter_list|()
comment|//! [40] //! [41]
block|{
if|if
condition|(
name|textEdit
operator|->
name|document
argument_list|()
operator|->
name|isModified
argument_list|()
condition|)
block|{
name|QMessageBox
operator|::
name|StandardButton
name|ret
decl_stmt|;
name|ret
operator|=
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Application"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The document has been modified.\n"
literal|"Do you want to save your changes?"
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Save
operator||
name|QMessageBox
operator|::
name|Discard
operator||
name|QMessageBox
operator|::
name|Cancel
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
name|QMessageBox
operator|::
name|Save
condition|)
return|return
name|save
argument_list|()
return|;
elseif|else
if|if
condition|(
name|ret
operator|==
name|QMessageBox
operator|::
name|Cancel
condition|)
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [41]
end_comment
begin_comment
comment|//! [42]
end_comment
begin_function
DECL|function|loadFile
name|void
name|MainWindow
operator|::
name|loadFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
comment|//! [42] //! [43]
block|{
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
name|ReadOnly
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
literal|"Application"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Cannot read file %1:\n%2."
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
name|in
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QApplication
operator|::
name|setOverrideCursor
argument_list|(
name|Qt
operator|::
name|WaitCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|textEdit
operator|->
name|setPlainText
argument_list|(
name|in
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QApplication
operator|::
name|restoreOverrideCursor
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|setCurrentFile
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"File loaded"
argument_list|)
argument_list|,
literal|2000
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [43]
end_comment
begin_comment
comment|//! [44]
end_comment
begin_function
DECL|function|saveFile
name|bool
name|MainWindow
operator|::
name|saveFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
comment|//! [44] //! [45]
block|{
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
literal|"Application"
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
return|return
literal|false
return|;
block|}
name|QTextStream
name|out
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QApplication
operator|::
name|setOverrideCursor
argument_list|(
name|Qt
operator|::
name|WaitCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|out
operator|<<
name|textEdit
operator|->
name|toPlainText
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QApplication
operator|::
name|restoreOverrideCursor
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|setCurrentFile
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"File saved"
argument_list|)
argument_list|,
literal|2000
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [45]
end_comment
begin_comment
comment|//! [46]
end_comment
begin_function
DECL|function|setCurrentFile
name|void
name|MainWindow
operator|::
name|setCurrentFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
comment|//! [46] //! [47]
block|{
name|curFile
operator|=
name|fileName
expr_stmt|;
name|textEdit
operator|->
name|document
argument_list|()
operator|->
name|setModified
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|setWindowModified
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QString
name|shownName
init|=
name|curFile
decl_stmt|;
if|if
condition|(
name|curFile
operator|.
name|isEmpty
argument_list|()
condition|)
name|shownName
operator|=
literal|"untitled.txt"
expr_stmt|;
name|setWindowFilePath
argument_list|(
name|shownName
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [47]
end_comment
begin_comment
comment|//! [48]
end_comment
begin_function
DECL|function|strippedName
name|QString
name|MainWindow
operator|::
name|strippedName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fullFileName
parameter_list|)
comment|//! [48] //! [49]
block|{
return|return
name|QFileInfo
argument_list|(
name|fullFileName
argument_list|)
operator|.
name|fileName
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [49]
end_comment
end_unit
