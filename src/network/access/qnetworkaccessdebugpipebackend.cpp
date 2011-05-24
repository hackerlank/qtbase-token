begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnetworkaccessdebugpipebackend_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdatastream.h"
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|"private/qnoncontiguousbytedevice_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|QT_BUILD_INTERNAL
name|enum
type|{
DECL|enumerator|ReadBufferSize
name|ReadBufferSize
init|=
literal|16384
decl_stmt|,
DECL|enumerator|WriteBufferSize
name|WriteBufferSize
init|=
name|ReadBufferSize
end_decl_stmt
begin_function
DECL|enumerator|WriteBufferSize
unit|};
name|QNetworkAccessBackend
modifier|*
DECL|function|create
name|QNetworkAccessDebugPipeBackendFactory
operator|::
name|create
parameter_list|(
name|QNetworkAccessManager
operator|::
name|Operation
name|op
parameter_list|,
specifier|const
name|QNetworkRequest
modifier|&
name|request
parameter_list|)
specifier|const
block|{
comment|// is it an operation we know of?
switch|switch
condition|(
name|op
condition|)
block|{
case|case
name|QNetworkAccessManager
operator|::
name|GetOperation
case|:
case|case
name|QNetworkAccessManager
operator|::
name|PutOperation
case|:
break|break;
default|default:
comment|// no, we can't handle this operation
return|return
literal|0
return|;
block|}
name|QUrl
name|url
init|=
name|request
operator|.
name|url
argument_list|()
decl_stmt|;
if|if
condition|(
name|url
operator|.
name|scheme
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"debugpipe"
argument_list|)
condition|)
return|return
operator|new
name|QNetworkAccessDebugPipeBackend
return|;
return|return
literal|0
return|;
block|}
end_function
begin_constructor
DECL|function|QNetworkAccessDebugPipeBackend
name|QNetworkAccessDebugPipeBackend
operator|::
name|QNetworkAccessDebugPipeBackend
parameter_list|()
member_init_list|:
name|bareProtocol
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|hasUploadFinished
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|hasDownloadFinished
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|hasEverythingFinished
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|bytesDownloaded
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|bytesUploaded
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QNetworkAccessDebugPipeBackend
name|QNetworkAccessDebugPipeBackend
operator|::
name|~
name|QNetworkAccessDebugPipeBackend
parameter_list|()
block|{
comment|// this is signals disconnect, not network!
name|socket
operator|.
name|disconnect
argument_list|(
name|this
argument_list|)
expr_stmt|;
comment|// we're not interested in the signals at this point
block|}
end_destructor
begin_function
DECL|function|open
name|void
name|QNetworkAccessDebugPipeBackend
operator|::
name|open
parameter_list|()
block|{
name|socket
operator|.
name|connectToHost
argument_list|(
name|url
argument_list|()
operator|.
name|host
argument_list|()
argument_list|,
name|url
argument_list|()
operator|.
name|port
argument_list|(
literal|12345
argument_list|)
argument_list|)
expr_stmt|;
name|socket
operator|.
name|setReadBufferSize
argument_list|(
name|ReadBufferSize
argument_list|)
expr_stmt|;
comment|// socket ready read -> we can push from socket to downstream
name|connect
argument_list|(
operator|&
name|socket
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|socketReadyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|socket
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
name|SLOT
argument_list|(
name|socketError
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|socket
argument_list|,
name|SIGNAL
argument_list|(
name|disconnected
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|socketDisconnected
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|socket
argument_list|,
name|SIGNAL
argument_list|(
name|connected
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|socketConnected
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// socket bytes written -> we can push more from upstream to socket
name|connect
argument_list|(
operator|&
name|socket
argument_list|,
name|SIGNAL
argument_list|(
name|bytesWritten
argument_list|(
name|qint64
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|socketBytesWritten
argument_list|(
name|qint64
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|bareProtocol
operator|=
name|url
argument_list|()
operator|.
name|queryItemValue
argument_list|(
name|QLatin1String
argument_list|(
literal|"bare"
argument_list|)
argument_list|)
operator|==
name|QLatin1String
argument_list|(
literal|"1"
argument_list|)
expr_stmt|;
if|if
condition|(
name|operation
argument_list|()
operator|==
name|QNetworkAccessManager
operator|::
name|PutOperation
condition|)
block|{
name|uploadByteDevice
operator|=
name|createUploadByteDevice
argument_list|()
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|uploadByteDevice
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
name|uploadReadyReadSlot
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"uploadReadyReadSlot"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|socketReadyRead
name|void
name|QNetworkAccessDebugPipeBackend
operator|::
name|socketReadyRead
parameter_list|()
block|{
name|pushFromSocketToDownstream
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|downstreamReadyWrite
name|void
name|QNetworkAccessDebugPipeBackend
operator|::
name|downstreamReadyWrite
parameter_list|()
block|{
name|pushFromSocketToDownstream
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|socketBytesWritten
name|void
name|QNetworkAccessDebugPipeBackend
operator|::
name|socketBytesWritten
parameter_list|(
name|qint64
parameter_list|)
block|{
name|pushFromUpstreamToSocket
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|uploadReadyReadSlot
name|void
name|QNetworkAccessDebugPipeBackend
operator|::
name|uploadReadyReadSlot
parameter_list|()
block|{
name|pushFromUpstreamToSocket
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pushFromSocketToDownstream
name|void
name|QNetworkAccessDebugPipeBackend
operator|::
name|pushFromSocketToDownstream
parameter_list|()
block|{
name|QByteArray
name|buffer
decl_stmt|;
if|if
condition|(
name|socket
operator|.
name|state
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|ConnectingState
condition|)
block|{
return|return;
block|}
forever|forever
block|{
if|if
condition|(
name|hasDownloadFinished
condition|)
return|return;
name|buffer
operator|.
name|resize
argument_list|(
name|ReadBufferSize
argument_list|)
expr_stmt|;
name|qint64
name|haveRead
init|=
name|socket
operator|.
name|read
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|ReadBufferSize
argument_list|)
decl_stmt|;
if|if
condition|(
name|haveRead
operator|==
operator|-
literal|1
condition|)
block|{
name|hasDownloadFinished
operator|=
literal|true
expr_stmt|;
comment|// this ensures a good last downloadProgress is emitted
name|setHeader
argument_list|(
name|QNetworkRequest
operator|::
name|ContentLengthHeader
argument_list|,
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
name|possiblyFinish
argument_list|()
expr_stmt|;
break|break;
block|}
elseif|else
if|if
condition|(
name|haveRead
operator|==
literal|0
condition|)
block|{
break|break;
block|}
else|else
block|{
comment|// have read something
name|buffer
operator|.
name|resize
argument_list|(
name|haveRead
argument_list|)
expr_stmt|;
name|bytesDownloaded
operator|+=
name|haveRead
expr_stmt|;
name|QByteDataBuffer
name|list
decl_stmt|;
name|list
operator|.
name|append
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// important because of implicit sharing!
name|writeDownstreamData
argument_list|(
name|list
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|pushFromUpstreamToSocket
name|void
name|QNetworkAccessDebugPipeBackend
operator|::
name|pushFromUpstreamToSocket
parameter_list|()
block|{
comment|// FIXME
if|if
condition|(
name|operation
argument_list|()
operator|==
name|QNetworkAccessManager
operator|::
name|PutOperation
condition|)
block|{
if|if
condition|(
name|hasUploadFinished
condition|)
return|return;
forever|forever
block|{
if|if
condition|(
name|socket
operator|.
name|bytesToWrite
argument_list|()
operator|>=
name|WriteBufferSize
condition|)
return|return;
name|qint64
name|haveRead
decl_stmt|;
specifier|const
name|char
modifier|*
name|readPointer
init|=
name|uploadByteDevice
operator|->
name|readPointer
argument_list|(
name|WriteBufferSize
argument_list|,
name|haveRead
argument_list|)
decl_stmt|;
if|if
condition|(
name|haveRead
operator|==
operator|-
literal|1
condition|)
block|{
comment|// EOF
name|hasUploadFinished
operator|=
literal|true
expr_stmt|;
name|emitReplyUploadProgress
argument_list|(
name|bytesUploaded
argument_list|,
name|bytesUploaded
argument_list|)
expr_stmt|;
name|possiblyFinish
argument_list|()
expr_stmt|;
break|break;
block|}
elseif|else
if|if
condition|(
name|haveRead
operator|==
literal|0
operator|||
name|readPointer
operator|==
literal|0
condition|)
block|{
comment|// nothing to read right now, we will be called again later
break|break;
block|}
else|else
block|{
name|qint64
name|haveWritten
decl_stmt|;
name|haveWritten
operator|=
name|socket
operator|.
name|write
argument_list|(
name|readPointer
argument_list|,
name|haveRead
argument_list|)
expr_stmt|;
if|if
condition|(
name|haveWritten
operator|<
literal|0
condition|)
block|{
comment|// write error!
name|QString
name|msg
init|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QNetworkAccessDebugPipeBackend"
argument_list|,
literal|"Write error writing to %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|url
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|,
name|socket
operator|.
name|errorString
argument_list|()
argument_list|)
decl_stmt|;
name|error
argument_list|(
name|QNetworkReply
operator|::
name|ProtocolFailure
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|finished
argument_list|()
expr_stmt|;
return|return;
block|}
else|else
block|{
name|uploadByteDevice
operator|->
name|advanceReadPointer
argument_list|(
name|haveWritten
argument_list|)
expr_stmt|;
name|bytesUploaded
operator|+=
name|haveWritten
expr_stmt|;
name|emitReplyUploadProgress
argument_list|(
name|bytesUploaded
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
comment|//QCoreApplication::processEvents();
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|possiblyFinish
name|void
name|QNetworkAccessDebugPipeBackend
operator|::
name|possiblyFinish
parameter_list|()
block|{
if|if
condition|(
name|hasEverythingFinished
condition|)
return|return;
name|hasEverythingFinished
operator|=
literal|true
expr_stmt|;
if|if
condition|(
operator|(
name|operation
argument_list|()
operator|==
name|QNetworkAccessManager
operator|::
name|GetOperation
operator|)
operator|&&
name|hasDownloadFinished
condition|)
block|{
name|socket
operator|.
name|close
argument_list|()
expr_stmt|;
name|finished
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|operation
argument_list|()
operator|==
name|QNetworkAccessManager
operator|::
name|PutOperation
operator|)
operator|&&
name|hasUploadFinished
condition|)
block|{
name|socket
operator|.
name|close
argument_list|()
expr_stmt|;
name|finished
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|closeDownstreamChannel
name|void
name|QNetworkAccessDebugPipeBackend
operator|::
name|closeDownstreamChannel
parameter_list|()
block|{
name|qWarning
argument_list|(
literal|"QNetworkAccessDebugPipeBackend::closeDownstreamChannel() %d"
argument_list|,
name|operation
argument_list|()
argument_list|)
expr_stmt|;
empty_stmt|;
comment|//if (operation() == QNetworkAccessManager::GetOperation)
comment|//    socket.disconnectFromHost();
block|}
end_function
begin_function
DECL|function|socketError
name|void
name|QNetworkAccessDebugPipeBackend
operator|::
name|socketError
parameter_list|()
block|{
name|qWarning
argument_list|(
literal|"QNetworkAccessDebugPipeBackend::socketError() %d"
argument_list|,
name|socket
operator|.
name|error
argument_list|()
argument_list|)
expr_stmt|;
name|QNetworkReply
operator|::
name|NetworkError
name|code
decl_stmt|;
switch|switch
condition|(
name|socket
operator|.
name|error
argument_list|()
condition|)
block|{
case|case
name|QAbstractSocket
operator|::
name|RemoteHostClosedError
case|:
return|return;
comment|// socketDisconnected will be called
case|case
name|QAbstractSocket
operator|::
name|NetworkError
case|:
name|code
operator|=
name|QNetworkReply
operator|::
name|UnknownNetworkError
expr_stmt|;
break|break;
default|default:
name|code
operator|=
name|QNetworkReply
operator|::
name|ProtocolFailure
expr_stmt|;
break|break;
block|}
name|error
argument_list|(
name|code
argument_list|,
name|QNetworkAccessDebugPipeBackend
operator|::
name|tr
argument_list|(
literal|"Socket error on %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|url
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|,
name|socket
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|finished
argument_list|()
expr_stmt|;
name|disconnect
argument_list|(
operator|&
name|socket
argument_list|,
name|SIGNAL
argument_list|(
name|disconnected
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|socketDisconnected
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|socketDisconnected
name|void
name|QNetworkAccessDebugPipeBackend
operator|::
name|socketDisconnected
parameter_list|()
block|{
name|pushFromSocketToDownstream
argument_list|()
expr_stmt|;
if|if
condition|(
name|socket
operator|.
name|bytesToWrite
argument_list|()
operator|==
literal|0
condition|)
block|{
comment|// normal close
block|}
else|else
block|{
comment|// abnormal close
name|QString
name|msg
init|=
name|QNetworkAccessDebugPipeBackend
operator|::
name|tr
argument_list|(
literal|"Remote host closed the connection prematurely on %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|url
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|)
decl_stmt|;
name|error
argument_list|(
name|QNetworkReply
operator|::
name|RemoteHostClosedError
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|finished
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|socketConnected
name|void
name|QNetworkAccessDebugPipeBackend
operator|::
name|socketConnected
parameter_list|()
block|{ }
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
