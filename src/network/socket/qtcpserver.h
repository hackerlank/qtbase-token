begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTCPSERVER_H
end_ifndef
begin_define
DECL|macro|QTCPSERVER_H
define|#
directive|define
name|QTCPSERVER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qabstractsocket.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qhostaddress.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QTcpServerPrivate
name|class
name|QTcpServerPrivate
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
end_ifndef
begin_decl_stmt
DECL|variable|QNetworkProxy
name|class
name|QNetworkProxy
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QTcpSocket
name|class
name|QTcpSocket
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QTcpServer
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QTcpServer
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QTcpServer
argument_list|()
block|;
name|bool
name|listen
argument_list|(
argument|const QHostAddress&address = QHostAddress::Any
argument_list|,
argument|quint16 port =
literal|0
argument_list|)
block|;
name|void
name|close
argument_list|()
block|;
name|bool
name|isListening
argument_list|()
specifier|const
block|;
name|void
name|setMaxPendingConnections
argument_list|(
argument|int numConnections
argument_list|)
block|;
name|int
name|maxPendingConnections
argument_list|()
specifier|const
block|;
name|quint16
name|serverPort
argument_list|()
specifier|const
block|;
name|QHostAddress
name|serverAddress
argument_list|()
specifier|const
block|;
name|qintptr
name|socketDescriptor
argument_list|()
specifier|const
block|;
name|bool
name|setSocketDescriptor
argument_list|(
argument|qintptr socketDescriptor
argument_list|)
block|;
name|bool
name|waitForNewConnection
argument_list|(
argument|int msec =
literal|0
argument_list|,
argument|bool *timedOut =
literal|0
argument_list|)
block|;
name|virtual
name|bool
name|hasPendingConnections
argument_list|()
specifier|const
block|;
name|virtual
name|QTcpSocket
operator|*
name|nextPendingConnection
argument_list|()
block|;
name|QAbstractSocket
operator|::
name|SocketError
name|serverError
argument_list|()
specifier|const
block|;
name|QString
name|errorString
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|void
name|setProxy
argument_list|(
specifier|const
name|QNetworkProxy
operator|&
name|networkProxy
argument_list|)
block|;
name|QNetworkProxy
name|proxy
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|protected
operator|:
name|virtual
name|void
name|incomingConnection
argument_list|(
argument|qintptr handle
argument_list|)
block|;
name|void
name|addPendingConnection
argument_list|(
name|QTcpSocket
operator|*
name|socket
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|newConnection
argument_list|()
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QTcpServer
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTcpServer
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTCPSERVER_H
end_comment
end_unit
