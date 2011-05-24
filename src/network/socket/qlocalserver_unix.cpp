begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlocalserver.h"
end_include
begin_include
include|#
directive|include
file|"qlocalserver_p.h"
end_include
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
file|"qnet_unix_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LOCALSERVER
end_ifndef
begin_include
include|#
directive|include
file|<sys/socket.h>
end_include
begin_include
include|#
directive|include
file|<sys/un.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qdatetime.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_VXWORKS
end_ifdef
begin_include
include|#
directive|include
file|<selectLib.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|init
name|void
name|QLocalServerPrivate
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|removeServer
name|bool
name|QLocalServerPrivate
operator|::
name|removeServer
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|QString
name|fileName
decl_stmt|;
if|if
condition|(
name|name
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
block|{
name|fileName
operator|=
name|name
expr_stmt|;
block|}
else|else
block|{
name|fileName
operator|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|QDir
operator|::
name|tempPath
argument_list|()
argument_list|)
expr_stmt|;
name|fileName
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|name
expr_stmt|;
block|}
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|fileName
argument_list|)
condition|)
return|return
name|QFile
operator|::
name|remove
argument_list|(
name|fileName
argument_list|)
return|;
else|else
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|listen
name|bool
name|QLocalServerPrivate
operator|::
name|listen
parameter_list|(
specifier|const
name|QString
modifier|&
name|requestedServerName
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLocalServer
argument_list|)
expr_stmt|;
comment|// determine the full server path
if|if
condition|(
name|requestedServerName
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
block|{
name|fullServerName
operator|=
name|requestedServerName
expr_stmt|;
block|}
else|else
block|{
name|fullServerName
operator|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|QDir
operator|::
name|tempPath
argument_list|()
argument_list|)
expr_stmt|;
name|fullServerName
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|requestedServerName
expr_stmt|;
block|}
name|serverName
operator|=
name|requestedServerName
expr_stmt|;
comment|// create the unix socket
name|listenSocket
operator|=
name|qt_safe_socket
argument_list|(
name|PF_UNIX
argument_list|,
name|SOCK_STREAM
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|listenSocket
condition|)
block|{
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalServer::listen"
argument_list|)
argument_list|)
expr_stmt|;
name|closeServer
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Construct the unix address
name|struct
operator|::
name|sockaddr_un
name|addr
decl_stmt|;
name|addr
operator|.
name|sun_family
operator|=
name|PF_UNIX
expr_stmt|;
if|if
condition|(
sizeof|sizeof
argument_list|(
name|addr
operator|.
name|sun_path
argument_list|)
operator|<
operator|(
name|uint
operator|)
name|fullServerName
operator|.
name|toLatin1
argument_list|()
operator|.
name|size
argument_list|()
operator|+
literal|1
condition|)
block|{
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalServer::listen"
argument_list|)
argument_list|)
expr_stmt|;
name|closeServer
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
operator|::
name|memcpy
argument_list|(
name|addr
operator|.
name|sun_path
argument_list|,
name|fullServerName
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|,
name|fullServerName
operator|.
name|toLatin1
argument_list|()
operator|.
name|size
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
comment|// In SYMBIAN OS it can currently happen that accept is called twice,
comment|// once from waitForNewConnection and once via QSocketNotfier activity
comment|//
comment|// As an workaround, we set the socket to non blocking so possible
comment|// subsequent call to accept will not block in any case
comment|//
comment|// This change can be removed once more generic fix to select thread
comment|// synchronization problem is implemented.
name|int
name|flags
init|=
name|fcntl
argument_list|(
name|listenSocket
argument_list|,
name|F_GETFL
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|flags
operator|||
operator|-
literal|1
operator|==
operator|(
name|fcntl
argument_list|(
name|listenSocket
argument_list|,
name|F_SETFL
argument_list|,
name|flags
operator||
name|O_NONBLOCK
argument_list|)
operator|)
condition|)
block|{
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalServer::listen"
argument_list|)
argument_list|)
expr_stmt|;
name|closeServer
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
endif|#
directive|endif
comment|// bind
if|if
condition|(
operator|-
literal|1
operator|==
name|QT_SOCKET_BIND
argument_list|(
name|listenSocket
argument_list|,
operator|(
name|sockaddr
operator|*
operator|)
operator|&
name|addr
argument_list|,
sizeof|sizeof
argument_list|(
name|sockaddr_un
argument_list|)
argument_list|)
condition|)
block|{
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalServer::listen"
argument_list|)
argument_list|)
expr_stmt|;
comment|// if address is in use already, just close the socket, but do not delete the file
if|if
condition|(
name|errno
operator|==
name|EADDRINUSE
condition|)
name|QT_CLOSE
argument_list|(
name|listenSocket
argument_list|)
expr_stmt|;
comment|// otherwise, close the socket and delete the file
else|else
name|closeServer
argument_list|()
expr_stmt|;
name|listenSocket
operator|=
operator|-
literal|1
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// listen for connections
if|if
condition|(
operator|-
literal|1
operator|==
name|qt_safe_listen
argument_list|(
name|listenSocket
argument_list|,
literal|50
argument_list|)
condition|)
block|{
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalServer::listen"
argument_list|)
argument_list|)
expr_stmt|;
name|closeServer
argument_list|()
expr_stmt|;
name|listenSocket
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|error
operator|!=
name|QAbstractSocket
operator|::
name|AddressInUseError
condition|)
name|QFile
operator|::
name|remove
argument_list|(
name|fullServerName
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|Q_ASSERT
argument_list|(
operator|!
name|socketNotifier
argument_list|)
expr_stmt|;
name|socketNotifier
operator|=
operator|new
name|QSocketNotifier
argument_list|(
name|listenSocket
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|,
name|q
argument_list|)
expr_stmt|;
name|q
operator|->
name|connect
argument_list|(
name|socketNotifier
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_onNewConnection
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|socketNotifier
operator|->
name|setEnabled
argument_list|(
name|maxPendingConnections
operator|>
literal|0
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     \internal      \sa QLocalServer::closeServer()  */
end_comment
begin_function
DECL|function|closeServer
name|void
name|QLocalServerPrivate
operator|::
name|closeServer
parameter_list|()
block|{
if|if
condition|(
operator|-
literal|1
operator|!=
name|listenSocket
condition|)
name|QT_CLOSE
argument_list|(
name|listenSocket
argument_list|)
expr_stmt|;
name|listenSocket
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|socketNotifier
condition|)
block|{
name|socketNotifier
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
comment|// Otherwise, closed socket is checked before deleter runs
name|socketNotifier
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
name|socketNotifier
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|fullServerName
operator|.
name|isEmpty
argument_list|()
condition|)
name|QFile
operator|::
name|remove
argument_list|(
name|fullServerName
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal      We have received a notification that we can read on the listen socket.     Accept the new socket.  */
end_comment
begin_function
DECL|function|_q_onNewConnection
name|void
name|QLocalServerPrivate
operator|::
name|_q_onNewConnection
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QLocalServer
argument_list|)
expr_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|listenSocket
condition|)
return|return;
operator|::
name|sockaddr_un
name|addr
decl_stmt|;
name|QT_SOCKLEN_T
name|length
init|=
sizeof|sizeof
argument_list|(
name|sockaddr_un
argument_list|)
decl_stmt|;
name|int
name|connectedSocket
init|=
name|qt_safe_accept
argument_list|(
name|listenSocket
argument_list|,
operator|(
name|sockaddr
operator|*
operator|)
operator|&
name|addr
argument_list|,
operator|&
name|length
argument_list|)
decl_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|connectedSocket
condition|)
block|{
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalSocket::activated"
argument_list|)
argument_list|)
expr_stmt|;
name|closeServer
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|socketNotifier
operator|->
name|setEnabled
argument_list|(
name|pendingConnections
operator|.
name|size
argument_list|()
operator|<=
name|maxPendingConnections
argument_list|)
expr_stmt|;
name|q
operator|->
name|incomingConnection
argument_list|(
name|connectedSocket
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|waitForNewConnection
name|void
name|QLocalServerPrivate
operator|::
name|waitForNewConnection
parameter_list|(
name|int
name|msec
parameter_list|,
name|bool
modifier|*
name|timedOut
parameter_list|)
block|{
name|fd_set
name|readfds
decl_stmt|;
name|FD_ZERO
argument_list|(
operator|&
name|readfds
argument_list|)
expr_stmt|;
name|FD_SET
argument_list|(
name|listenSocket
argument_list|,
operator|&
name|readfds
argument_list|)
expr_stmt|;
name|timeval
name|timeout
decl_stmt|;
name|timeout
operator|.
name|tv_sec
operator|=
name|msec
operator|/
literal|1000
expr_stmt|;
name|timeout
operator|.
name|tv_usec
operator|=
operator|(
name|msec
operator|%
literal|1000
operator|)
operator|*
literal|1000
expr_stmt|;
name|int
name|result
init|=
operator|-
literal|1
decl_stmt|;
name|result
operator|=
name|qt_safe_select
argument_list|(
name|listenSocket
operator|+
literal|1
argument_list|,
operator|&
name|readfds
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|(
name|msec
operator|==
operator|-
literal|1
operator|)
condition|?
literal|0
else|:
operator|&
name|timeout
argument_list|)
expr_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|result
condition|)
block|{
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalServer::waitForNewConnection"
argument_list|)
argument_list|)
expr_stmt|;
name|closeServer
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|result
operator|>
literal|0
condition|)
name|_q_onNewConnection
argument_list|()
expr_stmt|;
if|if
condition|(
name|timedOut
condition|)
operator|*
name|timedOut
operator|=
operator|(
name|result
operator|==
literal|0
operator|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setError
name|void
name|QLocalServerPrivate
operator|::
name|setError
parameter_list|(
specifier|const
name|QString
modifier|&
name|function
parameter_list|)
block|{
if|if
condition|(
name|EAGAIN
operator|==
name|errno
condition|)
return|return;
switch|switch
condition|(
name|errno
condition|)
block|{
case|case
name|EACCES
case|:
name|errorString
operator|=
name|QLocalServer
operator|::
name|tr
argument_list|(
literal|"%1: Permission denied"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|error
operator|=
name|QAbstractSocket
operator|::
name|SocketAccessError
expr_stmt|;
break|break;
case|case
name|ELOOP
case|:
case|case
name|ENOENT
case|:
case|case
name|ENAMETOOLONG
case|:
case|case
name|EROFS
case|:
case|case
name|ENOTDIR
case|:
name|errorString
operator|=
name|QLocalServer
operator|::
name|tr
argument_list|(
literal|"%1: Name error"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|error
operator|=
name|QAbstractSocket
operator|::
name|HostNotFoundError
expr_stmt|;
break|break;
case|case
name|EADDRINUSE
case|:
name|errorString
operator|=
name|QLocalServer
operator|::
name|tr
argument_list|(
literal|"%1: Address in use"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|error
operator|=
name|QAbstractSocket
operator|::
name|AddressInUseError
expr_stmt|;
break|break;
default|default:
name|errorString
operator|=
name|QLocalServer
operator|::
name|tr
argument_list|(
literal|"%1: Unknown error %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
operator|.
name|arg
argument_list|(
name|errno
argument_list|)
expr_stmt|;
name|error
operator|=
name|QAbstractSocket
operator|::
name|UnknownSocketError
expr_stmt|;
if|#
directive|if
name|defined
name|QLOCALSERVER_DEBUG
name|qWarning
argument_list|()
operator|<<
name|errorString
operator|<<
literal|"fullServerName:"
operator|<<
name|fullServerName
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LOCALSERVER
end_comment
end_unit
