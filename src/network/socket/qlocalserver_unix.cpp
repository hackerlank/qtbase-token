begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_include
include|#
directive|include
file|"qtemporarydir.h"
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
name|QByteArray
name|encodedTempPath
decl_stmt|;
specifier|const
name|QByteArray
name|encodedFullServerName
init|=
name|QFile
operator|::
name|encodeName
argument_list|(
name|fullServerName
argument_list|)
decl_stmt|;
name|QScopedPointer
argument_list|<
name|QTemporaryDir
argument_list|>
name|tempDir
decl_stmt|;
comment|// Check any of the flags
if|if
condition|(
name|socketOptions
operator|&
name|QLocalServer
operator|::
name|WorldAccessOption
condition|)
block|{
name|QFileInfo
name|serverNameFileInfo
argument_list|(
name|fullServerName
argument_list|)
decl_stmt|;
name|tempDir
operator|.
name|reset
argument_list|(
operator|new
name|QTemporaryDir
argument_list|(
name|serverNameFileInfo
operator|.
name|absolutePath
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|tempDir
operator|->
name|isValid
argument_list|()
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
return|return
literal|false
return|;
block|}
name|encodedTempPath
operator|=
name|QFile
operator|::
name|encodeName
argument_list|(
name|tempDir
operator|->
name|path
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/s"
argument_list|)
argument_list|)
expr_stmt|;
block|}
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
name|encodedFullServerName
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
if|if
condition|(
name|socketOptions
operator|&
name|QLocalServer
operator|::
name|WorldAccessOption
condition|)
block|{
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
name|encodedTempPath
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
name|encodedTempPath
operator|.
name|constData
argument_list|()
argument_list|,
name|encodedTempPath
operator|.
name|size
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|::
name|memcpy
argument_list|(
name|addr
operator|.
name|sun_path
argument_list|,
name|encodedFullServerName
operator|.
name|constData
argument_list|()
argument_list|,
name|encodedFullServerName
operator|.
name|size
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
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
if|if
condition|(
name|socketOptions
operator|&
name|QLocalServer
operator|::
name|WorldAccessOption
condition|)
block|{
name|mode_t
name|mode
init|=
literal|000
decl_stmt|;
if|if
condition|(
name|socketOptions
operator|&
name|QLocalServer
operator|::
name|UserAccessOption
condition|)
name|mode
operator||=
name|S_IRWXU
expr_stmt|;
if|if
condition|(
name|socketOptions
operator|&
name|QLocalServer
operator|::
name|GroupAccessOption
condition|)
name|mode
operator||=
name|S_IRWXG
expr_stmt|;
if|if
condition|(
name|socketOptions
operator|&
name|QLocalServer
operator|::
name|OtherAccessOption
condition|)
name|mode
operator||=
name|S_IRWXO
expr_stmt|;
if|if
condition|(
operator|::
name|chmod
argument_list|(
name|encodedTempPath
operator|.
name|constData
argument_list|()
argument_list|,
name|mode
argument_list|)
operator|==
operator|-
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
if|if
condition|(
operator|::
name|rename
argument_list|(
name|encodedTempPath
operator|.
name|constData
argument_list|()
argument_list|,
name|encodedFullServerName
operator|.
name|constData
argument_list|()
argument_list|)
operator|==
operator|-
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
begin_function
DECL|function|listen
name|bool
name|QLocalServerPrivate
operator|::
name|listen
parameter_list|(
name|qintptr
name|socketDescriptor
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLocalServer
argument_list|)
expr_stmt|;
comment|// Attach to the localsocket
name|listenSocket
operator|=
name|socketDescriptor
expr_stmt|;
operator|::
name|fcntl
argument_list|(
name|listenSocket
argument_list|,
name|F_SETFD
argument_list|,
name|FD_CLOEXEC
argument_list|)
expr_stmt|;
operator|::
name|fcntl
argument_list|(
name|listenSocket
argument_list|,
name|F_SETFL
argument_list|,
operator|::
name|fcntl
argument_list|(
name|listenSocket
argument_list|,
name|F_GETFL
argument_list|)
operator||
name|O_NONBLOCK
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_LINUX
name|struct
operator|::
name|sockaddr_un
name|addr
decl_stmt|;
name|QT_SOCKLEN_T
name|len
init|=
sizeof|sizeof
argument_list|(
name|addr
argument_list|)
decl_stmt|;
name|memset
argument_list|(
operator|&
name|addr
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|addr
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
literal|0
operator|==
operator|::
name|getsockname
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
name|len
argument_list|)
condition|)
block|{
comment|// check for absract sockets
if|if
condition|(
name|addr
operator|.
name|sun_family
operator|==
name|PF_UNIX
operator|&&
name|addr
operator|.
name|sun_path
index|[
literal|0
index|]
operator|==
literal|0
condition|)
block|{
name|addr
operator|.
name|sun_path
index|[
literal|0
index|]
operator|=
literal|'@'
expr_stmt|;
block|}
name|QString
name|name
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|addr
operator|.
name|sun_path
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|fullServerName
operator|=
name|name
expr_stmt|;
name|serverName
operator|=
name|fullServerName
operator|.
name|mid
argument_list|(
name|fullServerName
operator|.
name|lastIndexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|serverName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|serverName
operator|=
name|fullServerName
expr_stmt|;
block|}
block|}
block|}
else|#
directive|else
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
endif|#
directive|endif
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
name|pollfd
name|pfd
init|=
name|qt_make_pollfd
argument_list|(
name|listenSocket
argument_list|,
name|POLLIN
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|qt_poll_msecs
argument_list|(
operator|&
name|pfd
argument_list|,
literal|1
argument_list|,
name|msec
argument_list|)
condition|)
block|{
case|case
literal|0
case|:
if|if
condition|(
name|timedOut
condition|)
operator|*
name|timedOut
operator|=
literal|true
expr_stmt|;
return|return;
break|break;
default|default:
if|if
condition|(
operator|(
name|pfd
operator|.
name|revents
operator|&
name|POLLNVAL
operator|)
operator|==
literal|0
condition|)
block|{
name|_q_onNewConnection
argument_list|()
expr_stmt|;
return|return;
block|}
name|errno
operator|=
name|EBADF
expr_stmt|;
comment|// FALLTHROUGH
case|case
operator|-
literal|1
case|:
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
break|break;
block|}
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
