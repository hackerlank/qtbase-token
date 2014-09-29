begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnetworkaccessfilebackend_p.h"
end_include
begin_include
include|#
directive|include
file|"qfileinfo.h"
end_include
begin_include
include|#
directive|include
file|"qurlinfo_p.h"
end_include
begin_include
include|#
directive|include
file|"qdir.h"
end_include
begin_include
include|#
directive|include
file|"private/qnoncontiguousbytedevice_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|supportedSchemes
name|QStringList
name|QNetworkAccessFileBackendFactory
operator|::
name|supportedSchemes
parameter_list|()
specifier|const
block|{
name|QStringList
name|schemes
decl_stmt|;
name|schemes
operator|<<
name|QStringLiteral
argument_list|(
literal|"file"
argument_list|)
operator|<<
name|QStringLiteral
argument_list|(
literal|"qrc"
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
name|schemes
operator|<<
name|QStringLiteral
argument_list|(
literal|"assets"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|schemes
return|;
block|}
end_function
begin_function
name|QNetworkAccessBackend
modifier|*
DECL|function|create
name|QNetworkAccessFileBackendFactory
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
operator|.
name|compare
argument_list|(
name|QLatin1String
argument_list|(
literal|"qrc"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|==
literal|0
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
operator|||
name|url
operator|.
name|scheme
argument_list|()
operator|.
name|compare
argument_list|(
name|QLatin1String
argument_list|(
literal|"assets"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|==
literal|0
endif|#
directive|endif
operator|||
name|url
operator|.
name|isLocalFile
argument_list|()
condition|)
block|{
return|return
operator|new
name|QNetworkAccessFileBackend
return|;
block|}
elseif|else
if|if
condition|(
operator|!
name|url
operator|.
name|scheme
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|&&
name|url
operator|.
name|authority
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|(
name|url
operator|.
name|scheme
argument_list|()
operator|.
name|length
argument_list|()
operator|>
literal|1
operator|)
condition|)
block|{
comment|// check if QFile could, in theory, open this URL via the file engines
comment|// it has to be in the format:
comment|//    prefix:path/to/file
comment|// or prefix:/path/to/file
comment|//
comment|// this construct here must match the one below in open()
name|QFileInfo
name|fi
argument_list|(
name|url
operator|.
name|toString
argument_list|(
name|QUrl
operator|::
name|RemoveAuthority
operator||
name|QUrl
operator|::
name|RemoveFragment
operator||
name|QUrl
operator|::
name|RemoveQuery
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|fi
operator|.
name|exists
argument_list|()
operator|||
operator|(
name|op
operator|==
name|QNetworkAccessManager
operator|::
name|PutOperation
operator|&&
name|fi
operator|.
name|dir
argument_list|()
operator|.
name|exists
argument_list|()
operator|)
condition|)
return|return
operator|new
name|QNetworkAccessFileBackend
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_constructor
DECL|function|QNetworkAccessFileBackend
name|QNetworkAccessFileBackend
operator|::
name|QNetworkAccessFileBackend
parameter_list|()
member_init_list|:
name|uploadByteDevice
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|totalBytes
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|hasUploadFinished
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QNetworkAccessFileBackend
name|QNetworkAccessFileBackend
operator|::
name|~
name|QNetworkAccessFileBackend
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|open
name|void
name|QNetworkAccessFileBackend
operator|::
name|open
parameter_list|()
block|{
name|QUrl
name|url
init|=
name|this
operator|->
name|url
argument_list|()
decl_stmt|;
if|if
condition|(
name|url
operator|.
name|host
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"localhost"
argument_list|)
condition|)
name|url
operator|.
name|setHost
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
comment|// do not allow UNC paths on Unix
if|if
condition|(
operator|!
name|url
operator|.
name|host
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// we handle only local files
name|error
argument_list|(
name|QNetworkReply
operator|::
name|ProtocolInvalidOperationError
argument_list|,
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QNetworkAccessFileBackend"
argument_list|,
literal|"Request for opening non-local file %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|url
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|finished
argument_list|()
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
comment|// !defined(Q_OS_WIN)
if|if
condition|(
name|url
operator|.
name|path
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|url
operator|.
name|setPath
argument_list|(
name|QLatin1String
argument_list|(
literal|"/"
argument_list|)
argument_list|)
expr_stmt|;
name|setUrl
argument_list|(
name|url
argument_list|)
expr_stmt|;
name|QString
name|fileName
init|=
name|url
operator|.
name|toLocalFile
argument_list|()
decl_stmt|;
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|url
operator|.
name|scheme
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"qrc"
argument_list|)
condition|)
block|{
name|fileName
operator|=
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
operator|+
name|url
operator|.
name|path
argument_list|()
expr_stmt|;
block|}
else|else
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
if|if
condition|(
name|url
operator|.
name|scheme
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"assets"
argument_list|)
condition|)
name|fileName
operator|=
name|QLatin1String
argument_list|(
literal|"assets:"
argument_list|)
operator|+
name|url
operator|.
name|path
argument_list|()
expr_stmt|;
else|else
endif|#
directive|endif
name|fileName
operator|=
name|url
operator|.
name|toString
argument_list|(
name|QUrl
operator|::
name|RemoveAuthority
operator||
name|QUrl
operator|::
name|RemoveFragment
operator||
name|QUrl
operator|::
name|RemoveQuery
argument_list|)
expr_stmt|;
block|}
block|}
name|file
operator|.
name|setFileName
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
if|if
condition|(
name|operation
argument_list|()
operator|==
name|QNetworkAccessManager
operator|::
name|GetOperation
condition|)
block|{
if|if
condition|(
operator|!
name|loadFileInfo
argument_list|()
condition|)
return|return;
block|}
name|QIODevice
operator|::
name|OpenMode
name|mode
decl_stmt|;
switch|switch
condition|(
name|operation
argument_list|()
condition|)
block|{
case|case
name|QNetworkAccessManager
operator|::
name|GetOperation
case|:
name|mode
operator|=
name|QIODevice
operator|::
name|ReadOnly
expr_stmt|;
break|break;
case|case
name|QNetworkAccessManager
operator|::
name|PutOperation
case|:
name|mode
operator|=
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Truncate
expr_stmt|;
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
break|break;
default|default:
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"QNetworkAccessFileBackend::open"
argument_list|,
literal|"Got a request operation I cannot handle!!"
argument_list|)
expr_stmt|;
return|return;
block|}
name|mode
operator||=
name|QIODevice
operator|::
name|Unbuffered
expr_stmt|;
name|bool
name|opened
init|=
name|file
operator|.
name|open
argument_list|(
name|mode
argument_list|)
decl_stmt|;
comment|// could we open the file?
if|if
condition|(
operator|!
name|opened
condition|)
block|{
name|QString
name|msg
init|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QNetworkAccessFileBackend"
argument_list|,
literal|"Error opening %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|this
operator|->
name|url
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|,
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
decl_stmt|;
comment|// why couldn't we open the file?
comment|// if we're opening for reading, either it doesn't exist, or it's access denied
comment|// if we're opening for writing, not existing means it's access denied too
if|if
condition|(
name|file
operator|.
name|exists
argument_list|()
operator|||
name|operation
argument_list|()
operator|==
name|QNetworkAccessManager
operator|::
name|PutOperation
condition|)
name|error
argument_list|(
name|QNetworkReply
operator|::
name|ContentAccessDenied
argument_list|,
name|msg
argument_list|)
expr_stmt|;
else|else
name|error
argument_list|(
name|QNetworkReply
operator|::
name|ContentNotFoundError
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
DECL|function|uploadReadyReadSlot
name|void
name|QNetworkAccessFileBackend
operator|::
name|uploadReadyReadSlot
parameter_list|()
block|{
if|if
condition|(
name|hasUploadFinished
condition|)
return|return;
forever|forever
block|{
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
operator|-
literal|1
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
name|file
operator|.
name|flush
argument_list|()
expr_stmt|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
name|finished
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
name|file
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
literal|"QNetworkAccessFileBackend"
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
name|file
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
block|}
name|file
operator|.
name|flush
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|closeDownstreamChannel
name|void
name|QNetworkAccessFileBackend
operator|::
name|closeDownstreamChannel
parameter_list|()
block|{
if|if
condition|(
name|operation
argument_list|()
operator|==
name|QNetworkAccessManager
operator|::
name|GetOperation
condition|)
block|{
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|downstreamReadyWrite
name|void
name|QNetworkAccessFileBackend
operator|::
name|downstreamReadyWrite
parameter_list|()
block|{
name|Q_ASSERT_X
argument_list|(
name|operation
argument_list|()
operator|==
name|QNetworkAccessManager
operator|::
name|GetOperation
argument_list|,
literal|"QNetworkAccessFileBackend"
argument_list|,
literal|"We're being told to download data but operation isn't GET!"
argument_list|)
expr_stmt|;
name|readMoreFromFile
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loadFileInfo
name|bool
name|QNetworkAccessFileBackend
operator|::
name|loadFileInfo
parameter_list|()
block|{
name|QFileInfo
name|fi
argument_list|(
name|file
argument_list|)
decl_stmt|;
name|setHeader
argument_list|(
name|QNetworkRequest
operator|::
name|LastModifiedHeader
argument_list|,
name|fi
operator|.
name|lastModified
argument_list|()
argument_list|)
expr_stmt|;
name|setHeader
argument_list|(
name|QNetworkRequest
operator|::
name|ContentLengthHeader
argument_list|,
name|fi
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
comment|// signal we're open
name|metaDataChanged
argument_list|()
expr_stmt|;
if|if
condition|(
name|fi
operator|.
name|isDir
argument_list|()
condition|)
block|{
name|error
argument_list|(
name|QNetworkReply
operator|::
name|ContentOperationNotPermittedError
argument_list|,
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QNetworkAccessFileBackend"
argument_list|,
literal|"Cannot open %1: Path is a directory"
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
argument_list|)
expr_stmt|;
name|finished
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|readMoreFromFile
name|bool
name|QNetworkAccessFileBackend
operator|::
name|readMoreFromFile
parameter_list|()
block|{
name|qint64
name|wantToRead
decl_stmt|;
while|while
condition|(
operator|(
name|wantToRead
operator|=
name|nextDownstreamBlockSize
argument_list|()
operator|)
operator|>
literal|0
condition|)
block|{
comment|// ### FIXME!!
comment|// Obtain a pointer from the ringbuffer!
comment|// Avoid extra copy
name|QByteArray
name|data
decl_stmt|;
name|data
operator|.
name|reserve
argument_list|(
name|wantToRead
argument_list|)
expr_stmt|;
name|qint64
name|actuallyRead
init|=
name|file
operator|.
name|read
argument_list|(
name|data
operator|.
name|data
argument_list|()
argument_list|,
name|wantToRead
argument_list|)
decl_stmt|;
if|if
condition|(
name|actuallyRead
operator|<=
literal|0
condition|)
block|{
comment|// EOF or error
if|if
condition|(
name|file
operator|.
name|error
argument_list|()
operator|!=
name|QFile
operator|::
name|NoError
condition|)
block|{
name|QString
name|msg
init|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QNetworkAccessFileBackend"
argument_list|,
literal|"Read error reading from %1: %2"
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
name|file
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
return|return
literal|false
return|;
block|}
name|finished
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
name|data
operator|.
name|resize
argument_list|(
name|actuallyRead
argument_list|)
expr_stmt|;
name|totalBytes
operator|+=
name|actuallyRead
expr_stmt|;
name|QByteDataBuffer
name|list
decl_stmt|;
name|list
operator|.
name|append
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|data
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
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
