begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNATIVESOCKETENGINE_P_H
end_ifndef
begin_define
DECL|macro|QNATIVESOCKETENGINE_P_H
define|#
directive|define
name|QNATIVESOCKETENGINE_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QLibrary class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
file|"private/qabstractsocketengine_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WIN
end_ifndef
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|<netinet/in.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<winsock2.h>
end_include
begin_include
include|#
directive|include
file|<ws2tcpip.h>
end_include
begin_include
include|#
directive|include
file|<mswsock.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_define
DECL|macro|QT_SOCKLEN_T
define|#
directive|define
name|QT_SOCKLEN_T
value|int
end_define
begin_define
DECL|macro|QT_SOCKOPTLEN_T
define|#
directive|define
name|QT_SOCKOPTLEN_T
value|int
end_define
begin_comment
comment|// The following definitions are copied from the MinGW header mswsock.h which
end_comment
begin_comment
comment|// was placed in the public domain. The WSASendMsg and WSARecvMsg functions
end_comment
begin_comment
comment|// were introduced with Windows Vista, so some Win32 headers are lacking them.
end_comment
begin_comment
comment|// There are no known versions of Windows CE or Embedded that contain them.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|WSAID_WSARECVMSG
end_ifndef
begin_typedef
DECL|typedef|LPFN_WSARECVMSG
typedef|typedef
name|INT
function_decl|(
name|WINAPI
modifier|*
name|LPFN_WSARECVMSG
function_decl|)
parameter_list|(
name|SOCKET
name|s
parameter_list|,
name|LPWSAMSG
name|lpMsg
parameter_list|,
name|LPDWORD
name|lpdwNumberOfBytesRecvd
parameter_list|,
name|LPWSAOVERLAPPED
name|lpOverlapped
parameter_list|,
name|LPWSAOVERLAPPED_COMPLETION_ROUTINE
name|lpCompletionRoutine
parameter_list|)
function_decl|;
end_typedef
begin_define
DECL|macro|WSAID_WSARECVMSG
define|#
directive|define
name|WSAID_WSARECVMSG
value|{0xf689d7c8,0x6f1f,0x436b,{0x8a,0x53,0xe5,0x4f,0xe3,0x51,0xc3,0x22}}
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WSAID_WSASENDMSG
end_ifndef
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|lpMsg
name|LPWSAMSG
name|lpMsg
decl_stmt|;
DECL|member|dwFlags
name|DWORD
name|dwFlags
decl_stmt|;
DECL|member|lpNumberOfBytesSent
name|LPDWORD
name|lpNumberOfBytesSent
decl_stmt|;
DECL|member|lpOverlapped
name|LPWSAOVERLAPPED
name|lpOverlapped
decl_stmt|;
DECL|member|lpCompletionRoutine
name|LPWSAOVERLAPPED_COMPLETION_ROUTINE
name|lpCompletionRoutine
decl_stmt|;
block|}
DECL|typedef|WSASENDMSG
DECL|typedef|LPWSASENDMSG
name|WSASENDMSG
operator|,
typedef|*
name|LPWSASENDMSG
typedef|;
end_typedef
begin_typedef
DECL|typedef|LPFN_WSASENDMSG
typedef|typedef
name|INT
function_decl|(
name|WSAAPI
modifier|*
name|LPFN_WSASENDMSG
function_decl|)
parameter_list|(
name|SOCKET
name|s
parameter_list|,
name|LPWSAMSG
name|lpMsg
parameter_list|,
name|DWORD
name|dwFlags
parameter_list|,
name|LPDWORD
name|lpNumberOfBytesSent
parameter_list|,
name|LPWSAOVERLAPPED
name|lpOverlapped
parameter_list|,
name|LPWSAOVERLAPPED_COMPLETION_ROUTINE
name|lpCompletionRoutine
parameter_list|)
function_decl|;
end_typedef
begin_define
DECL|macro|WSAID_WSASENDMSG
define|#
directive|define
name|WSAID_WSASENDMSG
value|{0xa441e712,0x754f,0x43ca,{0x84,0xa7,0x0d,0xee,0x44,0xcf,0x60,0x6d}}
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_union
DECL|union|qt_sockaddr
union|union
name|qt_sockaddr
block|{
DECL|member|a
name|sockaddr
name|a
decl_stmt|;
DECL|member|a4
name|sockaddr_in
name|a4
decl_stmt|;
DECL|member|a6
name|sockaddr_in6
name|a6
decl_stmt|;
block|}
union|;
end_union
begin_decl_stmt
DECL|variable|QNativeSocketEnginePrivate
name|class
name|QNativeSocketEnginePrivate
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
name|class
name|Q_AUTOTEST_EXPORT
name|QNativeSocketEngine
range|:
name|public
name|QAbstractSocketEngine
block|{
name|Q_OBJECT
name|public
operator|:
name|QNativeSocketEngine
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QNativeSocketEngine
argument_list|()
block|;
name|bool
name|initialize
argument_list|(
argument|QAbstractSocket::SocketType type
argument_list|,
argument|QAbstractSocket::NetworkLayerProtocol protocol = QAbstractSocket::IPv4Protocol
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|initialize
argument_list|(
argument|qintptr socketDescriptor
argument_list|,
argument|QAbstractSocket::SocketState socketState = QAbstractSocket::ConnectedState
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|qintptr
name|socketDescriptor
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isValid
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|connectToHost
argument_list|(
argument|const QHostAddress&address
argument_list|,
argument|quint16 port
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|connectToHostByName
argument_list|(
argument|const QString&name
argument_list|,
argument|quint16 port
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|bind
argument_list|(
argument|const QHostAddress&address
argument_list|,
argument|quint16 port
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|listen
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|int
name|accept
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|close
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|qint64
name|bytesAvailable
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|qint64
name|read
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|qint64
name|write
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|)
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|QT_NO_UDPSOCKET
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
name|bool
name|joinMulticastGroup
argument_list|(
argument|const QHostAddress&groupAddress
argument_list|,
argument|const QNetworkInterface&iface
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|leaveMulticastGroup
argument_list|(
argument|const QHostAddress&groupAddress
argument_list|,
argument|const QNetworkInterface&iface
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QNetworkInterface
name|multicastInterface
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|setMulticastInterface
argument_list|(
argument|const QNetworkInterface&iface
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|qint64
name|readDatagram
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|,
argument|QIpPacketHeader * =
literal|0
argument_list|,
argument|PacketHeaderOptions = WantNone
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|qint64
name|writeDatagram
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|,
argument|const QIpPacketHeader&
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasPendingDatagrams
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|qint64
name|pendingDatagramSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
comment|// QT_NO_UDPSOCKET
name|qint64
name|bytesToWrite
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|qint64
name|receiveBufferSize
argument_list|()
specifier|const
block|;
name|void
name|setReceiveBufferSize
argument_list|(
argument|qint64 bufferSize
argument_list|)
block|;
name|qint64
name|sendBufferSize
argument_list|()
specifier|const
block|;
name|void
name|setSendBufferSize
argument_list|(
argument|qint64 bufferSize
argument_list|)
block|;
name|int
name|option
argument_list|(
argument|SocketOption option
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|setOption
argument_list|(
argument|SocketOption option
argument_list|,
argument|int value
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|waitForRead
argument_list|(
argument|int msecs =
literal|30000
argument_list|,
argument|bool *timedOut =
literal|0
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|waitForWrite
argument_list|(
argument|int msecs =
literal|30000
argument_list|,
argument|bool *timedOut =
literal|0
argument_list|)
name|Q_DECL_OVERRIDE
block|;
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
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isReadNotificationEnabled
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setReadNotificationEnabled
argument_list|(
argument|bool enable
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isWriteNotificationEnabled
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setWriteNotificationEnabled
argument_list|(
argument|bool enable
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isExceptionNotificationEnabled
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setExceptionNotificationEnabled
argument_list|(
argument|bool enable
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|public
name|Q_SLOTS
operator|:
comment|// non-virtual override;
name|void
name|connectionNotification
argument_list|()
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QNativeSocketEngine
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QNativeSocketEngine
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSocketNotifier
name|class
name|QSocketNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNativeSocketEnginePrivate
range|:
name|public
name|QAbstractSocketEnginePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QNativeSocketEngine
argument_list|)
name|public
operator|:
name|QNativeSocketEnginePrivate
argument_list|()
block|;
operator|~
name|QNativeSocketEnginePrivate
argument_list|()
block|;
name|qintptr
name|socketDescriptor
block|;
name|QSocketNotifier
operator|*
name|readNotifier
block|,
operator|*
name|writeNotifier
block|,
operator|*
name|exceptNotifier
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|LPFN_WSASENDMSG
name|sendmsg
block|;
name|LPFN_WSARECVMSG
name|recvmsg
block|;
endif|#
directive|endif
block|enum
name|ErrorString
block|{
name|NonBlockingInitFailedErrorString
block|,
name|BroadcastingInitFailedErrorString
block|,
name|NoIpV6ErrorString
block|,
name|RemoteHostClosedErrorString
block|,
name|TimeOutErrorString
block|,
name|ResourceErrorString
block|,
name|OperationUnsupportedErrorString
block|,
name|ProtocolUnsupportedErrorString
block|,
name|InvalidSocketErrorString
block|,
name|HostUnreachableErrorString
block|,
name|NetworkUnreachableErrorString
block|,
name|AccessErrorString
block|,
name|ConnectionTimeOutErrorString
block|,
name|ConnectionRefusedErrorString
block|,
name|AddressInuseErrorString
block|,
name|AddressNotAvailableErrorString
block|,
name|AddressProtectedErrorString
block|,
name|DatagramTooLargeErrorString
block|,
name|SendDatagramErrorString
block|,
name|ReceiveDatagramErrorString
block|,
name|WriteErrorString
block|,
name|ReadErrorString
block|,
name|PortInuseErrorString
block|,
name|NotSocketErrorString
block|,
name|InvalidProxyTypeString
block|,
name|TemporaryErrorString
block|,
name|UnknownSocketErrorString
operator|=
operator|-
literal|1
block|}
block|;
name|void
name|setError
argument_list|(
argument|QAbstractSocket::SocketError error
argument_list|,
argument|ErrorString errorString
argument_list|)
specifier|const
block|;
name|QHostAddress
name|adjustAddressProtocol
argument_list|(
argument|const QHostAddress&address
argument_list|)
specifier|const
block|;
comment|// native functions
name|int
name|option
argument_list|(
argument|QNativeSocketEngine::SocketOption option
argument_list|)
specifier|const
block|;
name|bool
name|setOption
argument_list|(
argument|QNativeSocketEngine::SocketOption option
argument_list|,
argument|int value
argument_list|)
block|;
name|bool
name|createNewSocket
argument_list|(
argument|QAbstractSocket::SocketType type
argument_list|,
argument|QAbstractSocket::NetworkLayerProtocol&protocol
argument_list|)
block|;
name|bool
name|nativeConnect
argument_list|(
argument|const QHostAddress&address
argument_list|,
argument|quint16 port
argument_list|)
block|;
name|bool
name|nativeBind
argument_list|(
argument|const QHostAddress&address
argument_list|,
argument|quint16 port
argument_list|)
block|;
name|bool
name|nativeListen
argument_list|(
argument|int backlog
argument_list|)
block|;
name|int
name|nativeAccept
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
name|bool
name|nativeJoinMulticastGroup
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
block|;
name|bool
name|nativeLeaveMulticastGroup
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
block|;
name|QNetworkInterface
name|nativeMulticastInterface
argument_list|()
specifier|const
block|;
name|bool
name|nativeSetMulticastInterface
argument_list|(
specifier|const
name|QNetworkInterface
operator|&
name|iface
argument_list|)
block|;
endif|#
directive|endif
name|qint64
name|nativeBytesAvailable
argument_list|()
specifier|const
block|;
name|bool
name|nativeHasPendingDatagrams
argument_list|()
specifier|const
block|;
name|qint64
name|nativePendingDatagramSize
argument_list|()
specifier|const
block|;
name|qint64
name|nativeReceiveDatagram
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxLength
argument_list|,
argument|QIpPacketHeader *header
argument_list|,
argument|QAbstractSocketEngine::PacketHeaderOptions options
argument_list|)
block|;
name|qint64
name|nativeSendDatagram
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 length
argument_list|,
argument|const QIpPacketHeader&header
argument_list|)
block|;
name|qint64
name|nativeRead
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxLength
argument_list|)
block|;
name|qint64
name|nativeWrite
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 length
argument_list|)
block|;
name|int
name|nativeSelect
argument_list|(
argument|int timeout
argument_list|,
argument|bool selectForRead
argument_list|)
specifier|const
block|;
name|int
name|nativeSelect
argument_list|(
argument|int timeout
argument_list|,
argument|bool checkRead
argument_list|,
argument|bool checkWrite
argument_list|,
argument|bool *selectForRead
argument_list|,
argument|bool *selectForWrite
argument_list|)
specifier|const
block|;
name|void
name|nativeClose
argument_list|()
block|;
name|bool
name|checkProxy
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|address
argument_list|)
block|;
name|bool
name|fetchConnectionParameters
argument_list|()
block|;
specifier|static
name|uint
name|scopeIdFromString
argument_list|(
specifier|const
name|QString
operator|&
name|scopeid
argument_list|)
block|;
comment|/*! \internal         Sets \a address and \a port in the \a aa sockaddr structure and the size in \a sockAddrSize.         The address \a is converted to IPv6 if the current socket protocol is also IPv6.      */
name|void
name|setPortAndAddress
argument_list|(
argument|quint16 port
argument_list|,
argument|const QHostAddress&address
argument_list|,
argument|qt_sockaddr *aa
argument_list|,
argument|QT_SOCKLEN_T *sockAddrSize
argument_list|)
block|{
if|if
condition|(
name|address
operator|.
name|protocol
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|IPv6Protocol
operator|||
name|address
operator|.
name|protocol
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|AnyIPProtocol
operator|||
name|socketProtocol
operator|==
name|QAbstractSocket
operator|::
name|IPv6Protocol
operator|||
name|socketProtocol
operator|==
name|QAbstractSocket
operator|::
name|AnyIPProtocol
condition|)
block|{
name|memset
argument_list|(
operator|&
name|aa
operator|->
name|a6
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|sockaddr_in6
argument_list|)
argument_list|)
expr_stmt|;
name|aa
operator|->
name|a6
operator|.
name|sin6_family
operator|=
name|AF_INET6
expr_stmt|;
name|aa
operator|->
name|a6
operator|.
name|sin6_scope_id
operator|=
name|scopeIdFromString
argument_list|(
name|address
operator|.
name|scopeId
argument_list|()
argument_list|)
expr_stmt|;
name|aa
operator|->
name|a6
operator|.
name|sin6_port
operator|=
name|htons
argument_list|(
name|port
argument_list|)
expr_stmt|;
name|Q_IPV6ADDR
name|tmp
init|=
name|address
operator|.
name|toIPv6Address
argument_list|()
decl_stmt|;
name|memcpy
argument_list|(
operator|&
name|aa
operator|->
name|a6
operator|.
name|sin6_addr
argument_list|,
operator|&
name|tmp
argument_list|,
sizeof|sizeof
argument_list|(
name|tmp
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|sockAddrSize
operator|=
sizeof|sizeof
argument_list|(
name|sockaddr_in6
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|memset
argument_list|(
operator|&
name|aa
operator|->
name|a
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|sockaddr_in
argument_list|)
argument_list|)
expr_stmt|;
name|aa
operator|->
name|a4
operator|.
name|sin_family
operator|=
name|AF_INET
expr_stmt|;
name|aa
operator|->
name|a4
operator|.
name|sin_port
operator|=
name|htons
argument_list|(
name|port
argument_list|)
expr_stmt|;
name|aa
operator|->
name|a4
operator|.
name|sin_addr
operator|.
name|s_addr
operator|=
name|htonl
argument_list|(
name|address
operator|.
name|toIPv4Address
argument_list|()
argument_list|)
expr_stmt|;
operator|*
name|sockAddrSize
operator|=
sizeof|sizeof
argument_list|(
name|sockaddr_in
argument_list|)
expr_stmt|;
block|}
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QNATIVESOCKETENGINE_P_H
end_comment
end_unit
