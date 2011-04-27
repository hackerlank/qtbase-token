begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SSLCLIENT_H
end_ifndef
begin_define
DECL|macro|SSLCLIENT_H
define|#
directive|define
name|SSLCLIENT_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QWidget>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QAbstractSocket>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QSslSocket>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSslSocket
name|class
name|QSslSocket
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QToolButton
name|class
name|QToolButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Ui_Form
name|class
name|Ui_Form
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|SslClient
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|SslClient
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|SslClient
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|updateEnabledState
argument_list|()
block|;
name|void
name|secureConnect
argument_list|()
block|;
name|void
name|socketStateChanged
argument_list|(
argument|QAbstractSocket::SocketState state
argument_list|)
block|;
name|void
name|socketEncrypted
argument_list|()
block|;
name|void
name|socketReadyRead
argument_list|()
block|;
name|void
name|sendData
argument_list|()
block|;
name|void
name|sslErrors
argument_list|(
specifier|const
name|QList
operator|<
name|QSslError
operator|>
operator|&
name|errors
argument_list|)
block|;
name|void
name|displayCertificateInfo
argument_list|()
block|;
name|private
operator|:
name|void
name|appendString
argument_list|(
specifier|const
name|QString
operator|&
name|line
argument_list|)
block|;
name|QSslSocket
operator|*
name|socket
block|;
name|QToolButton
operator|*
name|padLock
block|;
name|Ui_Form
operator|*
name|form
block|;
name|bool
name|executingDialog
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
