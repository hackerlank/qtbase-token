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
file|<QtNetwork>
end_include
begin_include
include|#
directive|include
file|"client.h"
end_include
begin_constructor
DECL|function|Client
name|Client
operator|::
name|Client
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|parent
argument_list|)
block|{
name|hostLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Server name:"
argument_list|)
argument_list|)
expr_stmt|;
name|hostLineEdit
operator|=
operator|new
name|QLineEdit
argument_list|(
literal|"fortune"
argument_list|)
expr_stmt|;
name|hostLabel
operator|->
name|setBuddy
argument_list|(
name|hostLineEdit
argument_list|)
expr_stmt|;
name|statusLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"This examples requires that you run the "
literal|"Fortune Server example as well."
argument_list|)
argument_list|)
expr_stmt|;
name|statusLabel
operator|->
name|setWordWrap
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|getFortuneButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Get Fortune"
argument_list|)
argument_list|)
expr_stmt|;
name|getFortuneButton
operator|->
name|setDefault
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|quitButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Quit"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
operator|new
name|QDialogButtonBox
expr_stmt|;
name|buttonBox
operator|->
name|addButton
argument_list|(
name|getFortuneButton
argument_list|,
name|QDialogButtonBox
operator|::
name|ActionRole
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|addButton
argument_list|(
name|quitButton
argument_list|,
name|QDialogButtonBox
operator|::
name|RejectRole
argument_list|)
expr_stmt|;
name|socket
operator|=
operator|new
name|QLocalSocket
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|hostLineEdit
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|enableGetFortuneButton
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|getFortuneButton
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
name|requestNewFortune
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitButton
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
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|socket
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|readFortune
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|socket
argument_list|,
name|SIGNAL
argument_list|(
name|error
argument_list|(
name|QLocalSocket
operator|::
name|LocalSocketError
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|displayError
argument_list|(
name|QLocalSocket
operator|::
name|LocalSocketError
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|hostLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|hostLineEdit
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|statusLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Fortune Client"
argument_list|)
argument_list|)
expr_stmt|;
name|hostLineEdit
operator|->
name|setFocus
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|requestNewFortune
name|void
name|Client
operator|::
name|requestNewFortune
parameter_list|()
block|{
name|getFortuneButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|blockSize
operator|=
literal|0
expr_stmt|;
name|socket
operator|->
name|abort
argument_list|()
expr_stmt|;
name|socket
operator|->
name|connectToServer
argument_list|(
name|hostLineEdit
operator|->
name|text
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readFortune
name|void
name|Client
operator|::
name|readFortune
parameter_list|()
block|{
name|QDataStream
name|in
argument_list|(
name|socket
argument_list|)
decl_stmt|;
name|in
operator|.
name|setVersion
argument_list|(
name|QDataStream
operator|::
name|Qt_4_0
argument_list|)
expr_stmt|;
if|if
condition|(
name|blockSize
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|socket
operator|->
name|bytesAvailable
argument_list|()
operator|<
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
name|quint16
argument_list|)
condition|)
return|return;
name|in
operator|>>
name|blockSize
expr_stmt|;
block|}
if|if
condition|(
name|in
operator|.
name|atEnd
argument_list|()
condition|)
return|return;
name|QString
name|nextFortune
decl_stmt|;
name|in
operator|>>
name|nextFortune
expr_stmt|;
if|if
condition|(
name|nextFortune
operator|==
name|currentFortune
condition|)
block|{
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|requestNewFortune
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|currentFortune
operator|=
name|nextFortune
expr_stmt|;
name|statusLabel
operator|->
name|setText
argument_list|(
name|currentFortune
argument_list|)
expr_stmt|;
name|getFortuneButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|displayError
name|void
name|Client
operator|::
name|displayError
parameter_list|(
name|QLocalSocket
operator|::
name|LocalSocketError
name|socketError
parameter_list|)
block|{
switch|switch
condition|(
name|socketError
condition|)
block|{
case|case
name|QLocalSocket
operator|::
name|ServerNotFoundError
case|:
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Fortune Client"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The host was not found. Please check the "
literal|"host name and port settings."
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|ConnectionRefusedError
case|:
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Fortune Client"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The connection was refused by the peer. "
literal|"Make sure the fortune server is running, "
literal|"and check that the host name and port "
literal|"settings are correct."
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|PeerClosedError
case|:
break|break;
default|default:
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Fortune Client"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The following error occurred: %1."
argument_list|)
operator|.
name|arg
argument_list|(
name|socket
operator|->
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|getFortuneButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enableGetFortuneButton
name|void
name|Client
operator|::
name|enableGetFortuneButton
parameter_list|()
block|{
name|getFortuneButton
operator|->
name|setEnabled
argument_list|(
operator|!
name|hostLineEdit
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
