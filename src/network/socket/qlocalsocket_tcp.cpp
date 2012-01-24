begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlocalsocket.h"
end_include
begin_include
include|#
directive|include
file|"qlocalsocket_p.h"
end_include
begin_include
include|#
directive|include
file|"qlocalserver.h"
end_include
begin_include
include|#
directive|include
file|<qhostaddress.h>
end_include
begin_include
include|#
directive|include
file|<qsettings.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QLocalSocketPrivate
name|QLocalSocketPrivate
operator|::
name|QLocalSocketPrivate
parameter_list|()
member_init_list|:
name|QIODevicePrivate
argument_list|()
member_init_list|,
name|tcpSocket
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|ownsTcpSocket
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|state
argument_list|(
name|QLocalSocket
operator|::
name|UnconnectedState
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|init
name|void
name|QLocalSocketPrivate
operator|::
name|init
parameter_list|()
block|{
name|setSocket
argument_list|(
operator|new
name|QLocalUnixSocket
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setSocket
name|void
name|QLocalSocketPrivate
operator|::
name|setSocket
parameter_list|(
name|QLocalUnixSocket
modifier|*
name|socket
parameter_list|)
block|{
if|if
condition|(
name|ownsTcpSocket
condition|)
operator|delete
name|tcpSocket
expr_stmt|;
name|ownsTcpSocket
operator|=
literal|false
expr_stmt|;
name|tcpSocket
operator|=
name|socket
expr_stmt|;
name|Q_Q
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
comment|// QIODevice signals
name|q
operator|->
name|connect
argument_list|(
name|tcpSocket
argument_list|,
name|SIGNAL
argument_list|(
name|aboutToClose
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SIGNAL
argument_list|(
name|aboutToClose
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|q
operator|->
name|connect
argument_list|(
name|tcpSocket
argument_list|,
name|SIGNAL
argument_list|(
name|bytesWritten
argument_list|(
name|qint64
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SIGNAL
argument_list|(
name|bytesWritten
argument_list|(
name|qint64
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|q
operator|->
name|connect
argument_list|(
name|tcpSocket
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// QAbstractSocket signals
name|q
operator|->
name|connect
argument_list|(
name|tcpSocket
argument_list|,
name|SIGNAL
argument_list|(
name|connected
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SIGNAL
argument_list|(
name|connected
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|q
operator|->
name|connect
argument_list|(
name|tcpSocket
argument_list|,
name|SIGNAL
argument_list|(
name|disconnected
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SIGNAL
argument_list|(
name|disconnected
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|q
operator|->
name|connect
argument_list|(
name|tcpSocket
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
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_stateChanged
argument_list|(
name|QAbstractSocket
operator|::
name|SocketState
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|q
operator|->
name|connect
argument_list|(
name|tcpSocket
argument_list|,
name|SIGNAL
argument_list|(
name|error
argument_list|(
name|QAbstractSocket
operator|::
name|SocketError
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_error
argument_list|(
name|QAbstractSocket
operator|::
name|SocketError
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|q
operator|->
name|connect
argument_list|(
name|tcpSocket
argument_list|,
name|SIGNAL
argument_list|(
name|readChannelFinished
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SIGNAL
argument_list|(
name|readChannelFinished
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|tcpSocket
operator|->
name|setParent
argument_list|(
name|q
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|_q_error
name|void
name|QLocalSocketPrivate
operator|::
name|_q_error
parameter_list|(
name|QAbstractSocket
operator|::
name|SocketError
name|socketError
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
name|QString
name|function
init|=
name|QLatin1String
argument_list|(
literal|"QLocalSocket"
argument_list|)
decl_stmt|;
name|QLocalSocket
operator|::
name|LocalSocketError
name|error
init|=
operator|(
name|QLocalSocket
operator|::
name|LocalSocketError
operator|)
name|socketError
decl_stmt|;
name|QString
name|errorString
init|=
name|generateErrorString
argument_list|(
name|error
argument_list|,
name|function
argument_list|)
decl_stmt|;
name|q
operator|->
name|setErrorString
argument_list|(
name|errorString
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|error
argument_list|(
name|error
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|_q_stateChanged
name|void
name|QLocalSocketPrivate
operator|::
name|_q_stateChanged
parameter_list|(
name|QAbstractSocket
operator|::
name|SocketState
name|newState
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
name|QLocalSocket
operator|::
name|LocalSocketState
name|currentState
init|=
name|state
decl_stmt|;
switch|switch
condition|(
name|newState
condition|)
block|{
case|case
name|QAbstractSocket
operator|::
name|UnconnectedState
case|:
name|state
operator|=
name|QLocalSocket
operator|::
name|UnconnectedState
expr_stmt|;
name|serverName
operator|.
name|clear
argument_list|()
expr_stmt|;
name|fullServerName
operator|.
name|clear
argument_list|()
expr_stmt|;
break|break;
case|case
name|QAbstractSocket
operator|::
name|ConnectingState
case|:
name|state
operator|=
name|QLocalSocket
operator|::
name|ConnectingState
expr_stmt|;
break|break;
case|case
name|QAbstractSocket
operator|::
name|ConnectedState
case|:
name|state
operator|=
name|QLocalSocket
operator|::
name|ConnectedState
expr_stmt|;
break|break;
case|case
name|QAbstractSocket
operator|::
name|ClosingState
case|:
name|state
operator|=
name|QLocalSocket
operator|::
name|ClosingState
expr_stmt|;
break|break;
default|default:
if|#
directive|if
name|defined
name|QLOCALSOCKET_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"QLocalSocket::Unhandled socket state change:"
operator|<<
name|newState
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
if|if
condition|(
name|currentState
operator|!=
name|state
condition|)
emit|emit
name|q
operator|->
name|stateChanged
argument_list|(
name|state
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|generateErrorString
name|QString
name|QLocalSocketPrivate
operator|::
name|generateErrorString
parameter_list|(
name|QLocalSocket
operator|::
name|LocalSocketError
name|error
parameter_list|,
specifier|const
name|QString
modifier|&
name|function
parameter_list|)
specifier|const
block|{
name|QString
name|errorString
decl_stmt|;
switch|switch
condition|(
name|error
condition|)
block|{
case|case
name|QLocalSocket
operator|::
name|ConnectionRefusedError
case|:
name|errorString
operator|=
name|QLocalSocket
operator|::
name|tr
argument_list|(
literal|"%1: Connection refused"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|PeerClosedError
case|:
name|errorString
operator|=
name|QLocalSocket
operator|::
name|tr
argument_list|(
literal|"%1: Remote closed"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|ServerNotFoundError
case|:
name|errorString
operator|=
name|QLocalSocket
operator|::
name|tr
argument_list|(
literal|"%1: Invalid name"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|SocketAccessError
case|:
name|errorString
operator|=
name|QLocalSocket
operator|::
name|tr
argument_list|(
literal|"%1: Socket access error"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|SocketResourceError
case|:
name|errorString
operator|=
name|QLocalSocket
operator|::
name|tr
argument_list|(
literal|"%1: Socket resource error"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|SocketTimeoutError
case|:
name|errorString
operator|=
name|QLocalSocket
operator|::
name|tr
argument_list|(
literal|"%1: Socket operation timed out"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|DatagramTooLargeError
case|:
name|errorString
operator|=
name|QLocalSocket
operator|::
name|tr
argument_list|(
literal|"%1: Datagram too large"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|ConnectionError
case|:
name|errorString
operator|=
name|QLocalSocket
operator|::
name|tr
argument_list|(
literal|"%1: Connection error"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|UnsupportedSocketOperationError
case|:
name|errorString
operator|=
name|QLocalSocket
operator|::
name|tr
argument_list|(
literal|"%1: The socket operation is not supported"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|OperationError
case|:
name|errorString
operator|=
name|QLocalSocket
operator|::
name|tr
argument_list|(
literal|"%1: Operation not permitted when socket is in this state"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|UnknownSocketError
case|:
default|default:
name|errorString
operator|=
name|QLocalSocket
operator|::
name|tr
argument_list|(
literal|"%1: Unknown error"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
block|}
return|return
name|errorString
return|;
block|}
end_function
begin_function
DECL|function|errorOccurred
name|void
name|QLocalSocketPrivate
operator|::
name|errorOccurred
parameter_list|(
name|QLocalSocket
operator|::
name|LocalSocketError
name|error
parameter_list|,
specifier|const
name|QString
modifier|&
name|function
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|error
condition|)
block|{
case|case
name|QLocalSocket
operator|::
name|ConnectionRefusedError
case|:
name|tcpSocket
operator|->
name|setSocketError
argument_list|(
name|QAbstractSocket
operator|::
name|ConnectionRefusedError
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|PeerClosedError
case|:
name|tcpSocket
operator|->
name|setSocketError
argument_list|(
name|QAbstractSocket
operator|::
name|RemoteHostClosedError
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|ServerNotFoundError
case|:
name|tcpSocket
operator|->
name|setSocketError
argument_list|(
name|QAbstractSocket
operator|::
name|HostNotFoundError
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|SocketAccessError
case|:
name|tcpSocket
operator|->
name|setSocketError
argument_list|(
name|QAbstractSocket
operator|::
name|SocketAccessError
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|SocketResourceError
case|:
name|tcpSocket
operator|->
name|setSocketError
argument_list|(
name|QAbstractSocket
operator|::
name|SocketResourceError
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|SocketTimeoutError
case|:
name|tcpSocket
operator|->
name|setSocketError
argument_list|(
name|QAbstractSocket
operator|::
name|SocketTimeoutError
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|DatagramTooLargeError
case|:
name|tcpSocket
operator|->
name|setSocketError
argument_list|(
name|QAbstractSocket
operator|::
name|DatagramTooLargeError
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|ConnectionError
case|:
name|tcpSocket
operator|->
name|setSocketError
argument_list|(
name|QAbstractSocket
operator|::
name|NetworkError
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|UnsupportedSocketOperationError
case|:
name|tcpSocket
operator|->
name|setSocketError
argument_list|(
name|QAbstractSocket
operator|::
name|UnsupportedSocketOperationError
argument_list|)
expr_stmt|;
break|break;
case|case
name|QLocalSocket
operator|::
name|UnknownSocketError
case|:
default|default:
name|tcpSocket
operator|->
name|setSocketError
argument_list|(
name|QAbstractSocket
operator|::
name|UnknownSocketError
argument_list|)
expr_stmt|;
block|}
name|QString
name|errorString
init|=
name|generateErrorString
argument_list|(
name|error
argument_list|,
name|function
argument_list|)
decl_stmt|;
name|q
operator|->
name|setErrorString
argument_list|(
name|errorString
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|error
argument_list|(
name|error
argument_list|)
emit|;
comment|// errors cause a disconnect
name|tcpSocket
operator|->
name|setSocketState
argument_list|(
name|QAbstractSocket
operator|::
name|UnconnectedState
argument_list|)
expr_stmt|;
name|bool
name|stateChanged
init|=
operator|(
name|state
operator|!=
name|QLocalSocket
operator|::
name|UnconnectedState
operator|)
decl_stmt|;
name|state
operator|=
name|QLocalSocket
operator|::
name|UnconnectedState
expr_stmt|;
name|q
operator|->
name|close
argument_list|()
expr_stmt|;
if|if
condition|(
name|stateChanged
condition|)
name|q
operator|->
emit|emit
name|stateChanged
argument_list|(
name|state
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|connectToServer
name|void
name|QLocalSocket
operator|::
name|connectToServer
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|OpenMode
name|openMode
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
argument_list|()
operator|==
name|ConnectedState
operator|||
name|state
argument_list|()
operator|==
name|ConnectingState
condition|)
return|return;
name|d
operator|->
name|errorString
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|ConnectingState
expr_stmt|;
emit|emit
name|stateChanged
argument_list|(
name|d
operator|->
name|state
argument_list|)
emit|;
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|d
operator|->
name|errorOccurred
argument_list|(
name|ServerNotFoundError
argument_list|,
name|QLatin1String
argument_list|(
literal|"QLocalSocket::connectToServer"
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|serverName
operator|=
name|name
expr_stmt|;
specifier|const
name|QLatin1String
name|prefix
argument_list|(
literal|"QLocalServer/"
argument_list|)
decl_stmt|;
if|if
condition|(
name|name
operator|.
name|startsWith
argument_list|(
name|prefix
argument_list|)
condition|)
name|d
operator|->
name|fullServerName
operator|=
name|name
expr_stmt|;
else|else
name|d
operator|->
name|fullServerName
operator|=
name|prefix
operator|+
name|name
expr_stmt|;
name|QSettings
name|settings
argument_list|(
name|QLatin1String
argument_list|(
literal|"Trolltech"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"Qt"
argument_list|)
argument_list|)
decl_stmt|;
name|bool
name|ok
decl_stmt|;
specifier|const
name|quint16
name|port
init|=
name|settings
operator|.
name|value
argument_list|(
name|d
operator|->
name|fullServerName
argument_list|)
operator|.
name|toUInt
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
block|{
name|d
operator|->
name|errorOccurred
argument_list|(
name|ServerNotFoundError
argument_list|,
name|QLatin1String
argument_list|(
literal|"QLocalSocket::connectToServer"
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|tcpSocket
operator|->
name|connectToHost
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|,
name|port
argument_list|,
name|openMode
argument_list|)
expr_stmt|;
name|QIODevice
operator|::
name|open
argument_list|(
name|openMode
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setSocketDescriptor
name|bool
name|QLocalSocket
operator|::
name|setSocketDescriptor
parameter_list|(
name|qintptr
name|socketDescriptor
parameter_list|,
name|LocalSocketState
name|socketState
parameter_list|,
name|OpenMode
name|openMode
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
name|QAbstractSocket
operator|::
name|SocketState
name|newSocketState
init|=
name|QAbstractSocket
operator|::
name|UnconnectedState
decl_stmt|;
switch|switch
condition|(
name|socketState
condition|)
block|{
case|case
name|ConnectingState
case|:
name|newSocketState
operator|=
name|QAbstractSocket
operator|::
name|ConnectingState
expr_stmt|;
break|break;
case|case
name|ConnectedState
case|:
name|newSocketState
operator|=
name|QAbstractSocket
operator|::
name|ConnectedState
expr_stmt|;
break|break;
case|case
name|ClosingState
case|:
name|newSocketState
operator|=
name|QAbstractSocket
operator|::
name|ClosingState
expr_stmt|;
break|break;
case|case
name|UnconnectedState
case|:
name|newSocketState
operator|=
name|QAbstractSocket
operator|::
name|UnconnectedState
expr_stmt|;
break|break;
block|}
name|QIODevice
operator|::
name|open
argument_list|(
name|openMode
argument_list|)
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|socketState
expr_stmt|;
comment|// Is our parent a localServer? Then it wants us to use its remote socket.
name|QLocalServer
modifier|*
name|localServer
init|=
name|qobject_cast
argument_list|<
name|QLocalServer
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|localServer
condition|)
block|{
foreach|foreach
control|(
name|QObject
modifier|*
name|child
decl|,
name|localServer
operator|->
name|children
argument_list|()
control|)
block|{
name|QTcpSocket
modifier|*
name|childTcpSocket
init|=
name|qobject_cast
argument_list|<
name|QTcpSocket
operator|*
argument_list|>
argument_list|(
name|child
argument_list|)
decl_stmt|;
if|if
condition|(
name|childTcpSocket
operator|&&
name|childTcpSocket
operator|->
name|socketDescriptor
argument_list|()
operator|==
name|socketDescriptor
condition|)
block|{
name|d
operator|->
name|setSocket
argument_list|(
cast|static_cast
argument_list|<
name|QLocalUnixSocket
operator|*
argument_list|>
argument_list|(
name|childTcpSocket
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
block|}
comment|// We couldn't find the socket in the children list of our server.
comment|// So it might be that the user wants to set a socket descriptor.
return|return
name|d
operator|->
name|tcpSocket
operator|->
name|setSocketDescriptor
argument_list|(
name|socketDescriptor
argument_list|,
name|newSocketState
argument_list|,
name|openMode
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|socketDescriptor
name|qintptr
name|QLocalSocket
operator|::
name|socketDescriptor
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalSocket
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|tcpSocket
operator|->
name|socketDescriptor
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|readData
name|qint64
name|QLocalSocket
operator|::
name|readData
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|c
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|tcpSocket
operator|->
name|readData
argument_list|(
name|data
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|writeData
name|qint64
name|QLocalSocket
operator|::
name|writeData
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|c
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|tcpSocket
operator|->
name|writeData
argument_list|(
name|data
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|abort
name|void
name|QLocalSocket
operator|::
name|abort
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
name|d
operator|->
name|tcpSocket
operator|->
name|abort
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bytesAvailable
name|qint64
name|QLocalSocket
operator|::
name|bytesAvailable
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalSocket
argument_list|)
expr_stmt|;
return|return
name|QIODevice
operator|::
name|bytesAvailable
argument_list|()
operator|+
name|d
operator|->
name|tcpSocket
operator|->
name|bytesAvailable
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|bytesToWrite
name|qint64
name|QLocalSocket
operator|::
name|bytesToWrite
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalSocket
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|tcpSocket
operator|->
name|bytesToWrite
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|canReadLine
name|bool
name|QLocalSocket
operator|::
name|canReadLine
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalSocket
argument_list|)
expr_stmt|;
return|return
name|QIODevice
operator|::
name|canReadLine
argument_list|()
operator|||
name|d
operator|->
name|tcpSocket
operator|->
name|canReadLine
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|close
name|void
name|QLocalSocket
operator|::
name|close
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
name|d
operator|->
name|tcpSocket
operator|->
name|close
argument_list|()
expr_stmt|;
name|d
operator|->
name|serverName
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|fullServerName
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QIODevice
operator|::
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|waitForBytesWritten
name|bool
name|QLocalSocket
operator|::
name|waitForBytesWritten
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|tcpSocket
operator|->
name|waitForBytesWritten
argument_list|(
name|msecs
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|flush
name|bool
name|QLocalSocket
operator|::
name|flush
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|tcpSocket
operator|->
name|flush
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|disconnectFromServer
name|void
name|QLocalSocket
operator|::
name|disconnectFromServer
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
name|d
operator|->
name|tcpSocket
operator|->
name|disconnectFromHost
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|error
name|QLocalSocket
operator|::
name|LocalSocketError
name|QLocalSocket
operator|::
name|error
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalSocket
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|d
operator|->
name|tcpSocket
operator|->
name|error
argument_list|()
condition|)
block|{
case|case
name|QAbstractSocket
operator|::
name|ConnectionRefusedError
case|:
return|return
name|QLocalSocket
operator|::
name|ConnectionRefusedError
return|;
case|case
name|QAbstractSocket
operator|::
name|RemoteHostClosedError
case|:
return|return
name|QLocalSocket
operator|::
name|PeerClosedError
return|;
case|case
name|QAbstractSocket
operator|::
name|HostNotFoundError
case|:
return|return
name|QLocalSocket
operator|::
name|ServerNotFoundError
return|;
case|case
name|QAbstractSocket
operator|::
name|SocketAccessError
case|:
return|return
name|QLocalSocket
operator|::
name|SocketAccessError
return|;
case|case
name|QAbstractSocket
operator|::
name|SocketResourceError
case|:
return|return
name|QLocalSocket
operator|::
name|SocketResourceError
return|;
case|case
name|QAbstractSocket
operator|::
name|SocketTimeoutError
case|:
return|return
name|QLocalSocket
operator|::
name|SocketTimeoutError
return|;
case|case
name|QAbstractSocket
operator|::
name|DatagramTooLargeError
case|:
return|return
name|QLocalSocket
operator|::
name|DatagramTooLargeError
return|;
case|case
name|QAbstractSocket
operator|::
name|NetworkError
case|:
return|return
name|QLocalSocket
operator|::
name|ConnectionError
return|;
case|case
name|QAbstractSocket
operator|::
name|UnsupportedSocketOperationError
case|:
return|return
name|QLocalSocket
operator|::
name|UnsupportedSocketOperationError
return|;
case|case
name|QAbstractSocket
operator|::
name|UnknownSocketError
case|:
return|return
name|QLocalSocket
operator|::
name|UnknownSocketError
return|;
default|default:
if|#
directive|if
name|defined
name|QLOCALSOCKET_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"QLocalSocket error not handled:"
operator|<<
name|d
operator|->
name|tcpSocket
operator|->
name|error
argument_list|()
expr_stmt|;
endif|#
directive|endif
break|break;
block|}
return|return
name|UnknownSocketError
return|;
block|}
end_function
begin_function
DECL|function|isValid
name|bool
name|QLocalSocket
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalSocket
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|tcpSocket
operator|->
name|isValid
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|readBufferSize
name|qint64
name|QLocalSocket
operator|::
name|readBufferSize
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalSocket
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|tcpSocket
operator|->
name|readBufferSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setReadBufferSize
name|void
name|QLocalSocket
operator|::
name|setReadBufferSize
parameter_list|(
name|qint64
name|size
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
name|d
operator|->
name|tcpSocket
operator|->
name|setReadBufferSize
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|waitForConnected
name|bool
name|QLocalSocket
operator|::
name|waitForConnected
parameter_list|(
name|int
name|msec
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
argument_list|()
operator|!=
name|ConnectingState
condition|)
return|return
operator|(
name|state
argument_list|()
operator|==
name|ConnectedState
operator|)
return|;
return|return
name|d
operator|->
name|tcpSocket
operator|->
name|waitForConnected
argument_list|(
name|msec
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|waitForDisconnected
name|bool
name|QLocalSocket
operator|::
name|waitForDisconnected
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
argument_list|()
operator|==
name|UnconnectedState
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QLocalSocket::waitForDisconnected() is not allowed in UnconnectedState"
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
operator|(
name|d
operator|->
name|tcpSocket
operator|->
name|waitForDisconnected
argument_list|(
name|msecs
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|waitForReadyRead
name|bool
name|QLocalSocket
operator|::
name|waitForReadyRead
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
argument_list|()
operator|==
name|QLocalSocket
operator|::
name|UnconnectedState
condition|)
return|return
literal|false
return|;
return|return
operator|(
name|d
operator|->
name|tcpSocket
operator|->
name|waitForReadyRead
argument_list|(
name|msecs
argument_list|)
operator|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
