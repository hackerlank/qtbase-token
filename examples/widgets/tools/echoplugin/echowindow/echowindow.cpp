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
file|"echowindow.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|EchoWindow
name|EchoWindow
operator|::
name|EchoWindow
parameter_list|()
block|{
name|createGUI
argument_list|()
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
literal|"Echo Plugin Example"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|loadPlugin
argument_list|()
condition|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
literal|"Error"
argument_list|,
literal|"Could not load the plugin"
argument_list|)
expr_stmt|;
name|lineEdit
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|button
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|sendEcho
name|void
name|EchoWindow
operator|::
name|sendEcho
parameter_list|()
block|{
name|QString
name|text
init|=
name|echoInterface
operator|->
name|echo
argument_list|(
name|lineEdit
operator|->
name|text
argument_list|()
argument_list|)
decl_stmt|;
name|label
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|createGUI
name|void
name|EchoWindow
operator|::
name|createGUI
parameter_list|()
block|{
name|lineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|label
operator|=
operator|new
name|QLabel
expr_stmt|;
name|label
operator|->
name|setFrameStyle
argument_list|(
name|QFrame
operator|::
name|Box
operator||
name|QFrame
operator|::
name|Plain
argument_list|)
expr_stmt|;
name|button
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Send Message"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|lineEdit
argument_list|,
name|SIGNAL
argument_list|(
name|editingFinished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|sendEcho
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|button
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|sendEcho
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|layout
operator|=
operator|new
name|QGridLayout
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Message:"
argument_list|)
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|lineEdit
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Answer:"
argument_list|)
argument_list|)
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|label
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|button
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|layout
operator|->
name|setSizeConstraint
argument_list|(
name|QLayout
operator|::
name|SetFixedSize
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
DECL|function|loadPlugin
name|bool
name|EchoWindow
operator|::
name|loadPlugin
parameter_list|()
block|{
name|QDir
name|pluginsDir
argument_list|(
name|qApp
operator|->
name|applicationDirPath
argument_list|()
argument_list|)
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
if|if
condition|(
name|pluginsDir
operator|.
name|dirName
argument_list|()
operator|.
name|toLower
argument_list|()
operator|==
literal|"debug"
operator|||
name|pluginsDir
operator|.
name|dirName
argument_list|()
operator|.
name|toLower
argument_list|()
operator|==
literal|"release"
condition|)
name|pluginsDir
operator|.
name|cdUp
argument_list|()
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
if|if
condition|(
name|pluginsDir
operator|.
name|dirName
argument_list|()
operator|==
literal|"MacOS"
condition|)
block|{
name|pluginsDir
operator|.
name|cdUp
argument_list|()
expr_stmt|;
name|pluginsDir
operator|.
name|cdUp
argument_list|()
expr_stmt|;
name|pluginsDir
operator|.
name|cdUp
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
name|pluginsDir
operator|.
name|cd
argument_list|(
literal|"plugins"
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QString
name|fileName
decl|,
name|pluginsDir
operator|.
name|entryList
argument_list|(
name|QDir
operator|::
name|Files
argument_list|)
control|)
block|{
name|QPluginLoader
name|pluginLoader
argument_list|(
name|pluginsDir
operator|.
name|absoluteFilePath
argument_list|(
name|fileName
argument_list|)
argument_list|)
decl_stmt|;
name|QObject
modifier|*
name|plugin
init|=
name|pluginLoader
operator|.
name|instance
argument_list|()
decl_stmt|;
if|if
condition|(
name|plugin
condition|)
block|{
name|echoInterface
operator|=
name|qobject_cast
argument_list|<
name|EchoInterface
operator|*
argument_list|>
argument_list|(
name|plugin
argument_list|)
expr_stmt|;
if|if
condition|(
name|echoInterface
condition|)
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
begin_comment
comment|//! [3]
end_comment
end_unit
