begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"interactivewidget.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QToolBox>
end_include
begin_constructor
DECL|function|InteractiveWidget
name|InteractiveWidget
operator|::
name|InteractiveWidget
parameter_list|()
block|{
name|m_onScreenWidget
operator|=
operator|new
name|OnScreenWidget
argument_list|<
name|QWidget
argument_list|>
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|m_onScreenWidget
operator|->
name|setMinimumSize
argument_list|(
literal|320
argument_list|,
literal|240
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|m_onScreenWidget
argument_list|)
expr_stmt|;
name|ui_textEdit
operator|=
operator|new
name|QTextEdit
argument_list|()
expr_stmt|;
name|ui_textEdit
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|panelContent
init|=
operator|new
name|QWidget
argument_list|()
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vlayout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|panelContent
argument_list|)
decl_stmt|;
name|vlayout
operator|->
name|setMargin
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|vlayout
operator|->
name|setSpacing
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// create and populate the command toolbox
name|m_commandsToolBox
operator|=
operator|new
name|QToolBox
argument_list|()
expr_stmt|;
name|QListWidget
modifier|*
name|currentListWidget
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
name|PaintCommands
operator|::
name|PaintCommandInfos
name|paintCommandInfo
decl|,
name|PaintCommands
operator|::
name|s_commandInfoTable
control|)
block|{
if|if
condition|(
name|paintCommandInfo
operator|.
name|isSectionHeader
argument_list|()
condition|)
block|{
name|currentListWidget
operator|=
operator|new
name|QListWidget
argument_list|()
expr_stmt|;
name|m_commandsToolBox
operator|->
name|addItem
argument_list|(
name|currentListWidget
argument_list|,
name|QIcon
argument_list|(
literal|":/icons/tools.png"
argument_list|)
argument_list|,
literal|"commands - "
operator|+
name|paintCommandInfo
operator|.
name|identifier
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|currentListWidget
argument_list|,
name|SIGNAL
argument_list|(
name|itemActivated
argument_list|(
name|QListWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|cmdSelected
argument_list|(
name|QListWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|(
operator|new
name|QListWidgetItem
argument_list|(
name|paintCommandInfo
operator|.
name|identifier
argument_list|,
name|currentListWidget
argument_list|)
operator|)
operator|->
name|setToolTip
argument_list|(
name|paintCommandInfo
operator|.
name|syntax
argument_list|)
expr_stmt|;
block|}
block|}
comment|// create and populate the enumerations toolbox
name|m_enumsToolBox
operator|=
operator|new
name|QToolBox
argument_list|()
expr_stmt|;
typedef|typedef
name|QPair
argument_list|<
name|QString
argument_list|,
name|QStringList
argument_list|>
name|EnumListType
typedef|;
foreach|foreach
control|(
name|EnumListType
name|enumInfos
decl|,
name|PaintCommands
operator|::
name|s_enumsTable
control|)
block|{
name|currentListWidget
operator|=
operator|new
name|QListWidget
argument_list|()
expr_stmt|;
name|m_commandsToolBox
operator|->
name|addItem
argument_list|(
name|currentListWidget
argument_list|,
name|QIcon
argument_list|(
literal|":/icons/enum.png"
argument_list|)
argument_list|,
literal|"enums - "
operator|+
name|enumInfos
operator|.
name|first
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|currentListWidget
argument_list|,
name|SIGNAL
argument_list|(
name|itemActivated
argument_list|(
name|QListWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|enumSelected
argument_list|(
name|QListWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QString
name|enumItem
decl|,
name|enumInfos
operator|.
name|second
control|)
operator|new
name|QListWidgetItem
argument_list|(
name|enumItem
argument_list|,
name|currentListWidget
argument_list|)
expr_stmt|;
block|}
comment|// add other widgets and layout
name|vlayout
operator|->
name|addWidget
argument_list|(
name|m_commandsToolBox
argument_list|)
expr_stmt|;
name|vlayout
operator|->
name|addWidget
argument_list|(
name|m_enumsToolBox
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|run
init|=
operator|new
name|QPushButton
argument_list|(
literal|"&Run"
argument_list|)
decl_stmt|;
name|QPushButton
modifier|*
name|load
init|=
operator|new
name|QPushButton
argument_list|(
literal|"&Load"
argument_list|)
decl_stmt|;
name|QPushButton
modifier|*
name|save
init|=
operator|new
name|QPushButton
argument_list|(
literal|"&Save"
argument_list|)
decl_stmt|;
name|run
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|NoFocus
argument_list|)
expr_stmt|;
name|vlayout
operator|->
name|addSpacing
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|vlayout
operator|->
name|addWidget
argument_list|(
name|run
argument_list|)
expr_stmt|;
name|vlayout
operator|->
name|addWidget
argument_list|(
name|load
argument_list|)
expr_stmt|;
name|vlayout
operator|->
name|addWidget
argument_list|(
name|save
argument_list|)
expr_stmt|;
name|QDockWidget
modifier|*
name|panel
init|=
operator|new
name|QDockWidget
argument_list|(
literal|"Commands"
argument_list|)
decl_stmt|;
name|panel
operator|->
name|setWidget
argument_list|(
name|panelContent
argument_list|)
expr_stmt|;
name|addDockWidget
argument_list|(
name|Qt
operator|::
name|LeftDockWidgetArea
argument_list|,
name|panel
argument_list|)
expr_stmt|;
name|QDockWidget
modifier|*
name|editor
init|=
operator|new
name|QDockWidget
argument_list|(
literal|"Editor"
argument_list|)
decl_stmt|;
name|editor
operator|->
name|setWidget
argument_list|(
name|ui_textEdit
argument_list|)
expr_stmt|;
name|addDockWidget
argument_list|(
name|Qt
operator|::
name|RightDockWidgetArea
argument_list|,
name|editor
argument_list|)
expr_stmt|;
comment|// connect gui signals
name|connect
argument_list|(
name|run
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|run
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|load
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|load
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|save
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|save
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/***************************************************************************************************/
end_comment
begin_function
DECL|function|run
name|void
name|InteractiveWidget
operator|::
name|run
parameter_list|()
block|{
name|m_onScreenWidget
operator|->
name|m_commands
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QString
name|script
init|=
name|ui_textEdit
operator|->
name|toPlainText
argument_list|()
decl_stmt|;
name|QStringList
name|lines
init|=
name|script
operator|.
name|split
argument_list|(
literal|"\n"
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|lines
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|m_onScreenWidget
operator|->
name|m_commands
operator|.
name|append
argument_list|(
name|lines
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|m_onScreenWidget
operator|->
name|repaint
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/***************************************************************************************************/
end_comment
begin_function
DECL|function|cmdSelected
name|void
name|InteractiveWidget
operator|::
name|cmdSelected
parameter_list|(
name|QListWidgetItem
modifier|*
name|item
parameter_list|)
block|{
if|if
condition|(
name|ui_textEdit
operator|->
name|textCursor
argument_list|()
operator|.
name|atBlockStart
argument_list|()
condition|)
block|{
name|ui_textEdit
operator|->
name|insertPlainText
argument_list|(
name|PaintCommands
operator|::
name|findCommandById
argument_list|(
name|item
operator|->
name|text
argument_list|()
argument_list|)
operator|->
name|sample
operator|+
literal|"\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ui_textEdit
operator|->
name|moveCursor
argument_list|(
name|QTextCursor
operator|::
name|EndOfLine
argument_list|)
expr_stmt|;
name|ui_textEdit
operator|->
name|insertPlainText
argument_list|(
literal|"\n"
operator|+
name|PaintCommands
operator|::
name|findCommandById
argument_list|(
name|item
operator|->
name|text
argument_list|()
argument_list|)
operator|->
name|sample
argument_list|)
expr_stmt|;
block|}
name|ui_textEdit
operator|->
name|setFocus
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/***************************************************************************************************/
end_comment
begin_function
DECL|function|enumSelected
name|void
name|InteractiveWidget
operator|::
name|enumSelected
parameter_list|(
name|QListWidgetItem
modifier|*
name|item
parameter_list|)
block|{
name|ui_textEdit
operator|->
name|insertPlainText
argument_list|(
name|item
operator|->
name|text
argument_list|()
argument_list|)
expr_stmt|;
name|ui_textEdit
operator|->
name|setFocus
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/***************************************************************************************************/
end_comment
begin_function
DECL|function|load
name|void
name|InteractiveWidget
operator|::
name|load
parameter_list|()
block|{
name|QString
name|fname
init|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|,
name|QString
argument_list|(
literal|"Load QPaintEngine Script"
argument_list|)
argument_list|,
name|QFileInfo
argument_list|(
name|m_filename
argument_list|)
operator|.
name|absoluteFilePath
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"QPaintEngine Script (*.qps);;All files (*.*)"
argument_list|)
argument_list|)
decl_stmt|;
name|load
argument_list|(
name|fname
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/***************************************************************************************************/
end_comment
begin_function
DECL|function|load
name|void
name|InteractiveWidget
operator|::
name|load
parameter_list|(
specifier|const
name|QString
modifier|&
name|fname
parameter_list|)
block|{
if|if
condition|(
operator|!
name|fname
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|m_filename
operator|=
name|fname
expr_stmt|;
name|ui_textEdit
operator|->
name|clear
argument_list|()
expr_stmt|;
name|QFile
name|file
argument_list|(
name|fname
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
expr_stmt|;
name|QTextStream
name|textFile
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|QString
name|script
init|=
name|textFile
operator|.
name|readAll
argument_list|()
decl_stmt|;
name|ui_textEdit
operator|->
name|setPlainText
argument_list|(
name|script
argument_list|)
expr_stmt|;
name|m_onScreenWidget
operator|->
name|m_filename
operator|=
name|fname
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/***************************************************************************************************/
end_comment
begin_function
DECL|function|save
name|void
name|InteractiveWidget
operator|::
name|save
parameter_list|()
block|{
name|QString
name|script
init|=
name|ui_textEdit
operator|->
name|toPlainText
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|script
operator|.
name|endsWith
argument_list|(
literal|"\n"
argument_list|)
condition|)
name|script
operator|+=
name|QString
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|QString
name|fname
init|=
name|QFileDialog
operator|::
name|getSaveFileName
argument_list|(
name|this
argument_list|,
name|QString
argument_list|(
literal|"Save QPaintEngine Script"
argument_list|)
argument_list|,
name|QFileInfo
argument_list|(
name|m_filename
argument_list|)
operator|.
name|absoluteFilePath
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"QPaintEngine Script (*.qps);;All files (*.*)"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fname
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|m_filename
operator|=
name|fname
expr_stmt|;
name|QFile
name|file
argument_list|(
name|fname
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Truncate
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
expr_stmt|;
name|QTextStream
name|textFile
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|textFile
operator|<<
name|script
expr_stmt|;
name|m_onScreenWidget
operator|->
name|m_filename
operator|=
name|fname
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/***************************************************************************************************/
end_comment
begin_function
DECL|function|eventFilter
name|bool
name|InteractiveWidget
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|,
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|qobject_cast
argument_list|<
name|QTextEdit
operator|*
argument_list|>
argument_list|(
name|o
argument_list|)
operator|&&
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|KeyPress
condition|)
block|{
name|QKeyEvent
modifier|*
name|ke
init|=
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
if|if
condition|(
name|ke
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Tab
condition|)
block|{
name|m_commandsToolBox
operator|->
name|currentWidget
argument_list|()
operator|->
name|setFocus
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
elseif|else
if|if
condition|(
name|ke
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Return
operator|&&
name|ke
operator|->
name|modifiers
argument_list|()
operator|==
name|Qt
operator|::
name|ControlModifier
condition|)
block|{
name|run
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
end_unit
