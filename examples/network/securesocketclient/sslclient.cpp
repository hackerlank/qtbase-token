begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"certificateinfo.h"
end_include
begin_include
include|#
directive|include
file|"sslclient.h"
end_include
begin_include
include|#
directive|include
file|"ui_sslclient.h"
end_include
begin_include
include|#
directive|include
file|"ui_sslerrors.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QScrollBar>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QStyle>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QToolButton>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QSslCipher>
end_include
begin_constructor
DECL|function|SslClient
name|SslClient
operator|::
name|SslClient
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|socket
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|padLock
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|executingDialog
argument_list|(
literal|false
argument_list|)
block|{
name|form
operator|=
operator|new
name|Ui_Form
expr_stmt|;
name|form
operator|->
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|form
operator|->
name|hostNameEdit
operator|->
name|setSelection
argument_list|(
literal|0
argument_list|,
name|form
operator|->
name|hostNameEdit
operator|->
name|text
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|form
operator|->
name|sessionOutput
operator|->
name|setHtml
argument_list|(
name|tr
argument_list|(
literal|"&lt;not connected&gt;"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|form
operator|->
name|hostNameEdit
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
name|updateEnabledState
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|form
operator|->
name|connectButton
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
name|secureConnect
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|form
operator|->
name|sendButton
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
name|sendData
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~SslClient
name|SslClient
operator|::
name|~
name|SslClient
parameter_list|()
block|{
operator|delete
name|form
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|updateEnabledState
name|void
name|SslClient
operator|::
name|updateEnabledState
parameter_list|()
block|{
name|bool
name|unconnected
init|=
operator|!
name|socket
operator|||
name|socket
operator|->
name|state
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|UnconnectedState
decl_stmt|;
name|form
operator|->
name|hostNameEdit
operator|->
name|setReadOnly
argument_list|(
operator|!
name|unconnected
argument_list|)
expr_stmt|;
name|form
operator|->
name|hostNameEdit
operator|->
name|setFocusPolicy
argument_list|(
name|unconnected
condition|?
name|Qt
operator|::
name|StrongFocus
else|:
name|Qt
operator|::
name|NoFocus
argument_list|)
expr_stmt|;
name|form
operator|->
name|hostNameLabel
operator|->
name|setEnabled
argument_list|(
name|unconnected
argument_list|)
expr_stmt|;
name|form
operator|->
name|portBox
operator|->
name|setEnabled
argument_list|(
name|unconnected
argument_list|)
expr_stmt|;
name|form
operator|->
name|portLabel
operator|->
name|setEnabled
argument_list|(
name|unconnected
argument_list|)
expr_stmt|;
name|form
operator|->
name|connectButton
operator|->
name|setEnabled
argument_list|(
name|unconnected
operator|&&
operator|!
name|form
operator|->
name|hostNameEdit
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|bool
name|connected
init|=
name|socket
operator|&&
name|socket
operator|->
name|state
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|ConnectedState
decl_stmt|;
name|form
operator|->
name|sessionOutput
operator|->
name|setEnabled
argument_list|(
name|connected
argument_list|)
expr_stmt|;
name|form
operator|->
name|sessionInput
operator|->
name|setEnabled
argument_list|(
name|connected
argument_list|)
expr_stmt|;
name|form
operator|->
name|sessionInputLabel
operator|->
name|setEnabled
argument_list|(
name|connected
argument_list|)
expr_stmt|;
name|form
operator|->
name|sendButton
operator|->
name|setEnabled
argument_list|(
name|connected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|secureConnect
name|void
name|SslClient
operator|::
name|secureConnect
parameter_list|()
block|{
if|if
condition|(
operator|!
name|socket
condition|)
block|{
name|socket
operator|=
operator|new
name|QSslSocket
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|socket
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|QAbstractSocket
operator|::
name|SocketState
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|socketStateChanged
argument_list|(
name|QAbstractSocket
operator|::
name|SocketState
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|socket
argument_list|,
name|SIGNAL
argument_list|(
name|encrypted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|socketEncrypted
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
name|sslErrors
argument_list|(
name|QList
argument_list|<
name|QSslError
argument_list|>
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|sslErrors
argument_list|(
name|QList
argument_list|<
name|QSslError
argument_list|>
argument_list|)
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
name|socketReadyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|socket
operator|->
name|connectToHostEncrypted
argument_list|(
name|form
operator|->
name|hostNameEdit
operator|->
name|text
argument_list|()
argument_list|,
name|form
operator|->
name|portBox
operator|->
name|value
argument_list|()
argument_list|)
expr_stmt|;
name|updateEnabledState
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|socketStateChanged
name|void
name|SslClient
operator|::
name|socketStateChanged
parameter_list|(
name|QAbstractSocket
operator|::
name|SocketState
name|state
parameter_list|)
block|{
if|if
condition|(
name|executingDialog
condition|)
return|return;
name|updateEnabledState
argument_list|()
expr_stmt|;
if|if
condition|(
name|state
operator|==
name|QAbstractSocket
operator|::
name|UnconnectedState
condition|)
block|{
name|form
operator|->
name|hostNameEdit
operator|->
name|setPalette
argument_list|(
name|QPalette
argument_list|()
argument_list|)
expr_stmt|;
name|form
operator|->
name|hostNameEdit
operator|->
name|setFocus
argument_list|()
expr_stmt|;
name|form
operator|->
name|cipherLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"<none>"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|padLock
condition|)
name|padLock
operator|->
name|hide
argument_list|()
expr_stmt|;
name|socket
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
name|socket
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|socketEncrypted
name|void
name|SslClient
operator|::
name|socketEncrypted
parameter_list|()
block|{
if|if
condition|(
operator|!
name|socket
condition|)
return|return;
comment|// might have disconnected already
name|form
operator|->
name|sessionOutput
operator|->
name|clear
argument_list|()
expr_stmt|;
name|form
operator|->
name|sessionInput
operator|->
name|setFocus
argument_list|()
expr_stmt|;
name|QPalette
name|palette
decl_stmt|;
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|,
name|QColor
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|192
argument_list|)
argument_list|)
expr_stmt|;
name|form
operator|->
name|hostNameEdit
operator|->
name|setPalette
argument_list|(
name|palette
argument_list|)
expr_stmt|;
name|QSslCipher
name|ciph
init|=
name|socket
operator|->
name|sessionCipher
argument_list|()
decl_stmt|;
name|QString
name|cipher
init|=
name|QString
argument_list|(
literal|"%1, %2 (%3/%4)"
argument_list|)
operator|.
name|arg
argument_list|(
name|ciph
operator|.
name|authenticationMethod
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|ciph
operator|.
name|name
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|ciph
operator|.
name|usedBits
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|ciph
operator|.
name|supportedBits
argument_list|()
argument_list|)
decl_stmt|;
empty_stmt|;
name|form
operator|->
name|cipherLabel
operator|->
name|setText
argument_list|(
name|cipher
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|padLock
condition|)
block|{
name|padLock
operator|=
operator|new
name|QToolButton
expr_stmt|;
name|padLock
operator|->
name|setIcon
argument_list|(
name|QIcon
argument_list|(
literal|":/encrypted.png"
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|padLock
operator|->
name|setCursor
argument_list|(
name|Qt
operator|::
name|ArrowCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|padLock
operator|->
name|setToolTip
argument_list|(
name|tr
argument_list|(
literal|"Display encryption details."
argument_list|)
argument_list|)
expr_stmt|;
name|int
name|extent
init|=
name|form
operator|->
name|hostNameEdit
operator|->
name|height
argument_list|()
operator|-
literal|2
decl_stmt|;
name|padLock
operator|->
name|resize
argument_list|(
name|extent
argument_list|,
name|extent
argument_list|)
expr_stmt|;
name|padLock
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|Ignored
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QHBoxLayout
argument_list|(
name|form
operator|->
name|hostNameEdit
argument_list|)
decl_stmt|;
name|layout
operator|->
name|setMargin
argument_list|(
name|form
operator|->
name|hostNameEdit
operator|->
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_DefaultFrameWidth
argument_list|)
argument_list|)
expr_stmt|;
name|layout
operator|->
name|setSpacing
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addStretch
argument_list|()
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|padLock
argument_list|)
expr_stmt|;
name|form
operator|->
name|hostNameEdit
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|padLock
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
name|displayCertificateInfo
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|padLock
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|socketReadyRead
name|void
name|SslClient
operator|::
name|socketReadyRead
parameter_list|()
block|{
name|appendString
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|socket
operator|->
name|readAll
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sendData
name|void
name|SslClient
operator|::
name|sendData
parameter_list|()
block|{
name|QString
name|input
init|=
name|form
operator|->
name|sessionInput
operator|->
name|text
argument_list|()
decl_stmt|;
name|appendString
argument_list|(
name|input
operator|+
literal|'\n'
argument_list|)
expr_stmt|;
name|socket
operator|->
name|write
argument_list|(
name|input
operator|.
name|toUtf8
argument_list|()
operator|+
literal|"\r\n"
argument_list|)
expr_stmt|;
name|form
operator|->
name|sessionInput
operator|->
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sslErrors
name|void
name|SslClient
operator|::
name|sslErrors
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QSslError
argument_list|>
modifier|&
name|errors
parameter_list|)
block|{
name|QDialog
name|errorDialog
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|Ui_SslErrors
name|ui
decl_stmt|;
name|ui
operator|.
name|setupUi
argument_list|(
operator|&
name|errorDialog
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|certificateChainButton
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
name|displayCertificateInfo
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QSslError
modifier|&
name|error
decl|,
name|errors
control|)
name|ui
operator|.
name|sslErrorList
operator|->
name|addItem
argument_list|(
name|error
operator|.
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
name|executingDialog
operator|=
literal|true
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|errorDialog
operator|.
name|showMaximized
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|errorDialog
operator|.
name|exec
argument_list|()
operator|==
name|QDialog
operator|::
name|Accepted
condition|)
name|socket
operator|->
name|ignoreSslErrors
argument_list|()
expr_stmt|;
name|executingDialog
operator|=
literal|false
expr_stmt|;
comment|// did the socket state change?
if|if
condition|(
name|socket
operator|->
name|state
argument_list|()
operator|!=
name|QAbstractSocket
operator|::
name|ConnectedState
condition|)
name|socketStateChanged
argument_list|(
name|socket
operator|->
name|state
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|displayCertificateInfo
name|void
name|SslClient
operator|::
name|displayCertificateInfo
parameter_list|()
block|{
name|CertificateInfo
modifier|*
name|info
init|=
operator|new
name|CertificateInfo
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|info
operator|->
name|setCertificateChain
argument_list|(
name|socket
operator|->
name|peerCertificateChain
argument_list|()
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|info
operator|->
name|showMaximized
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|info
operator|->
name|exec
argument_list|()
expr_stmt|;
name|info
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|appendString
name|void
name|SslClient
operator|::
name|appendString
parameter_list|(
specifier|const
name|QString
modifier|&
name|line
parameter_list|)
block|{
name|QTextCursor
name|cursor
argument_list|(
name|form
operator|->
name|sessionOutput
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
name|End
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|line
argument_list|)
expr_stmt|;
name|form
operator|->
name|sessionOutput
operator|->
name|verticalScrollBar
argument_list|()
operator|->
name|setValue
argument_list|(
name|form
operator|->
name|sessionOutput
operator|->
name|verticalScrollBar
argument_list|()
operator|->
name|maximum
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
