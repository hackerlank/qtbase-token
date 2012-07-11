begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTSOCKETENGINE_P_H
end_ifndef
begin_define
DECL|macro|QABSTRACTSOCKETENGINE_P_H
define|#
directive|define
name|QABSTRACTSOCKETENGINE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtNetwork/qhostaddress.h"
end_include
begin_include
include|#
directive|include
file|"QtNetwork/qabstractsocket.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAuthenticator
name|class
name|QAuthenticator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractSocketEnginePrivate
name|class
name|QAbstractSocketEnginePrivate
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
end_ifndef
begin_decl_stmt
DECL|variable|QNetworkInterface
name|class
name|QNetworkInterface
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QNetworkProxy
name|class
name|QNetworkProxy
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAbstractSocketEngineReceiver
block|{
name|public
label|:
name|virtual
operator|~
name|QAbstractSocketEngineReceiver
argument_list|()
block|{}
name|virtual
name|void
name|readNotification
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|writeNotification
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|closeNotification
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|exceptionNotification
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|connectionNotification
parameter_list|()
init|=
literal|0
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|virtual
name|void
name|proxyAuthenticationRequired
parameter_list|(
specifier|const
name|QNetworkProxy
modifier|&
name|proxy
parameter_list|,
name|QAuthenticator
modifier|*
name|authenticator
parameter_list|)
init|=
literal|0
function_decl|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QAbstractSocketEngine
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
specifier|static
name|QAbstractSocketEngine
operator|*
name|createSocketEngine
argument_list|(
argument|QAbstractSocket::SocketType socketType
argument_list|,
argument|const QNetworkProxy&
argument_list|,
argument|QObject *parent
argument_list|)
block|;
specifier|static
name|QAbstractSocketEngine
operator|*
name|createSocketEngine
argument_list|(
argument|qintptr socketDescriptor
argument_list|,
argument|QObject *parent
argument_list|)
block|;
name|QAbstractSocketEngine
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;      enum
name|SocketOption
block|{
name|NonBlockingSocketOption
block|,
name|BroadcastSocketOption
block|,
name|ReceiveBufferSocketOption
block|,
name|SendBufferSocketOption
block|,
name|AddressReusable
block|,
name|BindExclusively
block|,
name|ReceiveOutOfBandData
block|,
name|LowDelayOption
block|,
name|KeepAliveOption
block|,
name|MulticastTtlOption
block|,
name|MulticastLoopbackOption
block|,
name|TypeOfServiceOption
block|}
block|;
name|virtual
name|bool
name|initialize
argument_list|(
argument|QAbstractSocket::SocketType type
argument_list|,
argument|QAbstractSocket::NetworkLayerProtocol protocol = QAbstractSocket::IPv4Protocol
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|initialize
argument_list|(
argument|qintptr socketDescriptor
argument_list|,
argument|QAbstractSocket::SocketState socketState = QAbstractSocket::ConnectedState
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|qintptr
name|socketDescriptor
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|isValid
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|connectToHost
argument_list|(
argument|const QHostAddress&address
argument_list|,
argument|quint16 port
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|connectToHostByName
argument_list|(
argument|const QString&name
argument_list|,
argument|quint16 port
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|bind
argument_list|(
argument|const QHostAddress&address
argument_list|,
argument|quint16 port
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|listen
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|int
name|accept
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|close
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|qint64
name|bytesAvailable
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|qint64
name|read
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|qint64
name|write
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|)
operator|=
literal|0
block|;
ifndef|#
directive|ifndef
name|QT_NO_UDPSOCKET
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
name|virtual
name|bool
name|joinMulticastGroup
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|groupAddress
argument_list|,
specifier|const
name|QNetworkInterface
operator|&
name|iface
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|leaveMulticastGroup
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|groupAddress
argument_list|,
specifier|const
name|QNetworkInterface
operator|&
name|iface
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QNetworkInterface
name|multicastInterface
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|setMulticastInterface
argument_list|(
specifier|const
name|QNetworkInterface
operator|&
name|iface
argument_list|)
operator|=
literal|0
block|;
endif|#
directive|endif
comment|// QT_NO_NETWORKINTERFACE
name|virtual
name|qint64
name|readDatagram
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|,
argument|QHostAddress *addr =
literal|0
argument_list|,
argument|quint16 *port =
literal|0
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|qint64
name|writeDatagram
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|,
argument|const QHostAddress&addr
argument_list|,
argument|quint16 port
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|hasPendingDatagrams
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|qint64
name|pendingDatagramSize
argument_list|()
specifier|const
operator|=
literal|0
block|;
endif|#
directive|endif
comment|// QT_NO_UDPSOCKET
name|virtual
name|qint64
name|bytesToWrite
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|int
name|option
argument_list|(
argument|SocketOption option
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|setOption
argument_list|(
argument|SocketOption option
argument_list|,
argument|int value
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|waitForRead
argument_list|(
argument|int msecs =
literal|30000
argument_list|,
argument|bool *timedOut =
literal|0
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|waitForWrite
argument_list|(
argument|int msecs =
literal|30000
argument_list|,
argument|bool *timedOut =
literal|0
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|waitForReadOrWrite
argument_list|(
argument|bool *readyToRead
argument_list|,
argument|bool *readyToWrite
argument_list|,
argument|bool checkRead
argument_list|,
argument|bool checkWrite
argument_list|,
argument|int msecs =
literal|30000
argument_list|,
argument|bool *timedOut =
literal|0
argument_list|)
operator|=
literal|0
block|;
name|QAbstractSocket
operator|::
name|SocketError
name|error
argument_list|()
specifier|const
block|;
name|QString
name|errorString
argument_list|()
specifier|const
block|;
name|QAbstractSocket
operator|::
name|SocketState
name|state
argument_list|()
specifier|const
block|;
name|QAbstractSocket
operator|::
name|SocketType
name|socketType
argument_list|()
specifier|const
block|;
name|QAbstractSocket
operator|::
name|NetworkLayerProtocol
name|protocol
argument_list|()
specifier|const
block|;
name|QHostAddress
name|localAddress
argument_list|()
specifier|const
block|;
name|quint16
name|localPort
argument_list|()
specifier|const
block|;
name|QHostAddress
name|peerAddress
argument_list|()
specifier|const
block|;
name|quint16
name|peerPort
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isReadNotificationEnabled
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|setReadNotificationEnabled
argument_list|(
argument|bool enable
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|isWriteNotificationEnabled
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|setWriteNotificationEnabled
argument_list|(
argument|bool enable
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|isExceptionNotificationEnabled
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|setExceptionNotificationEnabled
argument_list|(
argument|bool enable
argument_list|)
operator|=
literal|0
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|readNotification
argument_list|()
block|;
name|void
name|writeNotification
argument_list|()
block|;
name|void
name|closeNotification
argument_list|()
block|;
name|void
name|exceptionNotification
argument_list|()
block|;
name|void
name|connectionNotification
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|void
name|proxyAuthenticationRequired
argument_list|(
specifier|const
name|QNetworkProxy
operator|&
name|proxy
argument_list|,
name|QAuthenticator
operator|*
name|authenticator
argument_list|)
block|;
endif|#
directive|endif
name|public
operator|:
name|void
name|setReceiver
argument_list|(
name|QAbstractSocketEngineReceiver
operator|*
name|receiver
argument_list|)
block|;
name|protected
operator|:
name|QAbstractSocketEngine
argument_list|(
name|QAbstractSocketEnginePrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|setError
argument_list|(
argument|QAbstractSocket::SocketError error
argument_list|,
argument|const QString&errorString
argument_list|)
specifier|const
block|;
name|void
name|setState
argument_list|(
argument|QAbstractSocket::SocketState state
argument_list|)
block|;
name|void
name|setSocketType
argument_list|(
argument|QAbstractSocket::SocketType socketType
argument_list|)
block|;
name|void
name|setProtocol
argument_list|(
argument|QAbstractSocket::NetworkLayerProtocol protocol
argument_list|)
block|;
name|void
name|setLocalAddress
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|address
argument_list|)
block|;
name|void
name|setLocalPort
argument_list|(
argument|quint16 port
argument_list|)
block|;
name|void
name|setPeerAddress
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|address
argument_list|)
block|;
name|void
name|setPeerPort
argument_list|(
argument|quint16 port
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QAbstractSocketEngine
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QAbstractSocketEngine
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAbstractSocketEnginePrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QAbstractSocketEngine
argument_list|)
name|public
operator|:
name|QAbstractSocketEnginePrivate
argument_list|()
block|;
name|mutable
name|QAbstractSocket
operator|::
name|SocketError
name|socketError
block|;
name|mutable
name|bool
name|hasSetSocketError
block|;
name|mutable
name|QString
name|socketErrorString
block|;
name|QAbstractSocket
operator|::
name|SocketState
name|socketState
block|;
name|QAbstractSocket
operator|::
name|SocketType
name|socketType
block|;
name|QAbstractSocket
operator|::
name|NetworkLayerProtocol
name|socketProtocol
block|;
name|QHostAddress
name|localAddress
block|;
name|quint16
name|localPort
block|;
name|QHostAddress
name|peerAddress
block|;
name|quint16
name|peerPort
block|;
name|QAbstractSocketEngineReceiver
operator|*
name|receiver
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QSocketEngineHandler
block|{
name|protected
label|:
name|QSocketEngineHandler
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QSocketEngineHandler
argument_list|()
expr_stmt|;
name|virtual
name|QAbstractSocketEngine
modifier|*
name|createSocketEngine
argument_list|(
name|QAbstractSocket
operator|::
name|SocketType
name|socketType
argument_list|,
specifier|const
name|QNetworkProxy
operator|&
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|QAbstractSocketEngine
modifier|*
name|createSocketEngine
parameter_list|(
name|qintptr
name|socketDescriptor
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
init|=
literal|0
function_decl|;
name|private
label|:
name|friend
name|class
name|QAbstractSocketEngine
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QABSTRACTSOCKETENGINE_P_H
end_comment
end_unit
