begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"locationdialog.h"
end_include
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|"settingstree.h"
end_include
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
name|settingsTree
operator|=
operator|new
name|SettingsTree
expr_stmt|;
name|setCentralWidget
argument_list|(
name|settingsTree
argument_list|)
expr_stmt|;
name|locationDialog
operator|=
literal|0
expr_stmt|;
name|createActions
argument_list|()
expr_stmt|;
name|createMenus
argument_list|()
expr_stmt|;
name|autoRefreshAct
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|fallbacksAct
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Settings Editor"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|500
argument_list|,
literal|600
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|openSettings
name|void
name|MainWindow
operator|::
name|openSettings
parameter_list|()
block|{
if|if
condition|(
operator|!
name|locationDialog
condition|)
name|locationDialog
operator|=
operator|new
name|LocationDialog
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|locationDialog
operator|->
name|exec
argument_list|()
condition|)
block|{
name|QSettings
modifier|*
name|settings
init|=
operator|new
name|QSettings
argument_list|(
name|locationDialog
operator|->
name|format
argument_list|()
argument_list|,
name|locationDialog
operator|->
name|scope
argument_list|()
argument_list|,
name|locationDialog
operator|->
name|organization
argument_list|()
argument_list|,
name|locationDialog
operator|->
name|application
argument_list|()
argument_list|)
decl_stmt|;
name|setSettingsObject
argument_list|(
name|settings
argument_list|)
expr_stmt|;
name|fallbacksAct
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|openIniFile
name|void
name|MainWindow
operator|::
name|openIniFile
parameter_list|()
block|{
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Open INI File"
argument_list|)
argument_list|,
literal|""
argument_list|,
name|tr
argument_list|(
literal|"INI Files (*.ini *.conf)"
argument_list|)
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
block|{
name|QSettings
modifier|*
name|settings
init|=
operator|new
name|QSettings
argument_list|(
name|fileName
argument_list|,
name|QSettings
operator|::
name|IniFormat
argument_list|)
decl_stmt|;
name|setSettingsObject
argument_list|(
name|settings
argument_list|)
expr_stmt|;
name|fallbacksAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|openPropertyList
name|void
name|MainWindow
operator|::
name|openPropertyList
parameter_list|()
block|{
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Open Property List"
argument_list|)
argument_list|,
literal|""
argument_list|,
name|tr
argument_list|(
literal|"Property List Files (*.plist)"
argument_list|)
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
block|{
name|QSettings
modifier|*
name|settings
init|=
operator|new
name|QSettings
argument_list|(
name|fileName
argument_list|,
name|QSettings
operator|::
name|NativeFormat
argument_list|)
decl_stmt|;
name|setSettingsObject
argument_list|(
name|settings
argument_list|)
expr_stmt|;
name|fallbacksAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|openRegistryPath
name|void
name|MainWindow
operator|::
name|openRegistryPath
parameter_list|()
block|{
name|QString
name|path
init|=
name|QInputDialog
operator|::
name|getText
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Open Registry Path"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Enter the path in the Windows registry:"
argument_list|)
argument_list|,
name|QLineEdit
operator|::
name|Normal
argument_list|,
literal|"HKEY_CURRENT_USER\\"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QSettings
modifier|*
name|settings
init|=
operator|new
name|QSettings
argument_list|(
name|path
argument_list|,
name|QSettings
operator|::
name|NativeFormat
argument_list|)
decl_stmt|;
name|setSettingsObject
argument_list|(
name|settings
argument_list|)
expr_stmt|;
name|fallbacksAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
end_function
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
literal|"About Settings Editor"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The<b>Settings Editor</b> example shows how to access "
literal|"application settings using Qt."
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
name|openSettingsAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Open Application Settings..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|openSettingsAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Open
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|openSettingsAct
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
name|openSettings
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|openIniFileAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Open I&NI File..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|openIniFileAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+N"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|openIniFileAct
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
name|openIniFile
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|openPropertyListAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Open Mac&Property List..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|openPropertyListAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+P"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|openPropertyListAct
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
name|openPropertyList
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|openRegistryPathAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Open Windows&Registry Path..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|openRegistryPathAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+G"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|openRegistryPathAct
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
name|openRegistryPath
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|refreshAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Refresh"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|refreshAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+R"
argument_list|)
argument_list|)
expr_stmt|;
name|refreshAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|refreshAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|settingsTree
argument_list|,
name|SLOT
argument_list|(
name|refresh
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
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
name|autoRefreshAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Auto-Refresh"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|autoRefreshAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+A"
argument_list|)
argument_list|)
expr_stmt|;
name|autoRefreshAct
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|autoRefreshAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|autoRefreshAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|settingsTree
argument_list|,
name|SLOT
argument_list|(
name|setAutoRefresh
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|autoRefreshAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|refreshAct
argument_list|,
name|SLOT
argument_list|(
name|setDisabled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|fallbacksAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Fallbacks"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|fallbacksAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+F"
argument_list|)
argument_list|)
expr_stmt|;
name|fallbacksAct
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|fallbacksAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|fallbacksAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|settingsTree
argument_list|,
name|SLOT
argument_list|(
name|setFallbacksEnabled
argument_list|(
name|bool
argument_list|)
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
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|openPropertyListAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|Q_OS_WIN
name|openRegistryPathAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
name|openSettingsAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|openIniFileAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|openPropertyListAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|openRegistryPathAct
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
name|refreshAct
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
name|optionsMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Options"
argument_list|)
argument_list|)
expr_stmt|;
name|optionsMenu
operator|->
name|addAction
argument_list|(
name|autoRefreshAct
argument_list|)
expr_stmt|;
name|optionsMenu
operator|->
name|addAction
argument_list|(
name|fallbacksAct
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
DECL|function|setSettingsObject
name|void
name|MainWindow
operator|::
name|setSettingsObject
parameter_list|(
name|QSettings
modifier|*
name|settings
parameter_list|)
block|{
name|settings
operator|->
name|setFallbacksEnabled
argument_list|(
name|fallbacksAct
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|settingsTree
operator|->
name|setSettingsObject
argument_list|(
name|settings
argument_list|)
expr_stmt|;
name|refreshAct
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|autoRefreshAct
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QString
name|niceName
init|=
name|settings
operator|->
name|fileName
argument_list|()
decl_stmt|;
name|niceName
operator|.
name|replace
argument_list|(
literal|"\\"
argument_list|,
literal|"/"
argument_list|)
expr_stmt|;
name|int
name|pos
init|=
name|niceName
operator|.
name|lastIndexOf
argument_list|(
literal|"/"
argument_list|)
decl_stmt|;
if|if
condition|(
name|pos
operator|!=
operator|-
literal|1
condition|)
name|niceName
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
name|pos
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|settings
operator|->
name|isWritable
argument_list|()
condition|)
name|niceName
operator|=
name|tr
argument_list|(
literal|"%1 (read only)"
argument_list|)
operator|.
name|arg
argument_list|(
name|niceName
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"%1 - %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|niceName
argument_list|)
operator|.
name|arg
argument_list|(
name|tr
argument_list|(
literal|"Settings Editor"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
