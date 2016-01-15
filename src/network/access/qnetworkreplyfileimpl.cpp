begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnetworkreplyfileimpl_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdatetime.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFileInfo>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QNetworkReplyFileImplPrivate
name|QNetworkReplyFileImplPrivate
operator|::
name|QNetworkReplyFileImplPrivate
parameter_list|()
member_init_list|:
name|QNetworkReplyPrivate
argument_list|()
member_init_list|,
name|realFileSize
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QNetworkReplyFileImpl
name|QNetworkReplyFileImpl
operator|::
name|~
name|QNetworkReplyFileImpl
parameter_list|()
block|{ }
end_destructor
begin_constructor
DECL|function|QNetworkReplyFileImpl
name|QNetworkReplyFileImpl
operator|::
name|QNetworkReplyFileImpl
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|,
specifier|const
name|QNetworkRequest
modifier|&
name|req
parameter_list|,
specifier|const
name|QNetworkAccessManager
operator|::
name|Operation
name|op
parameter_list|)
member_init_list|:
name|QNetworkReply
argument_list|(
operator|*
operator|new
name|QNetworkReplyFileImplPrivate
argument_list|()
argument_list|,
name|parent
argument_list|)
block|{
name|setRequest
argument_list|(
name|req
argument_list|)
expr_stmt|;
name|setUrl
argument_list|(
name|req
operator|.
name|url
argument_list|()
argument_list|)
expr_stmt|;
name|setOperation
argument_list|(
name|op
argument_list|)
expr_stmt|;
name|setFinished
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QNetworkReply
operator|::
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QNetworkReplyFileImplPrivate
modifier|*
name|d
init|=
operator|(
name|QNetworkReplyFileImplPrivate
operator|*
operator|)
name|d_func
argument_list|()
decl_stmt|;
name|QUrl
name|url
init|=
name|req
operator|.
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
name|QString
name|msg
init|=
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
decl_stmt|;
name|setError
argument_list|(
name|QNetworkReply
operator|::
name|ProtocolInvalidOperationError
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"error"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|,
name|Q_ARG
argument_list|(
name|QNetworkReply
operator|::
name|NetworkError
argument_list|,
name|QNetworkReply
operator|::
name|ProtocolInvalidOperationError
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"finished"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
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
name|QFileInfo
name|fi
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|fi
operator|.
name|isDir
argument_list|()
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
literal|"Cannot open %1: Path is a directory"
argument_list|)
operator|.
name|arg
argument_list|(
name|url
operator|.
name|toString
argument_list|()
argument_list|)
decl_stmt|;
name|setError
argument_list|(
name|QNetworkReply
operator|::
name|ContentOperationNotPermittedError
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"error"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|,
name|Q_ARG
argument_list|(
name|QNetworkReply
operator|::
name|NetworkError
argument_list|,
name|QNetworkReply
operator|::
name|ContentOperationNotPermittedError
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"finished"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|realFile
operator|.
name|setFileName
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
name|bool
name|opened
init|=
name|d
operator|->
name|realFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Unbuffered
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
name|d
operator|->
name|realFile
operator|.
name|fileName
argument_list|()
argument_list|,
name|d
operator|->
name|realFile
operator|.
name|errorString
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|realFile
operator|.
name|exists
argument_list|()
condition|)
block|{
name|setError
argument_list|(
name|QNetworkReply
operator|::
name|ContentAccessDenied
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"error"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|,
name|Q_ARG
argument_list|(
name|QNetworkReply
operator|::
name|NetworkError
argument_list|,
name|QNetworkReply
operator|::
name|ContentAccessDenied
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|setError
argument_list|(
name|QNetworkReply
operator|::
name|ContentNotFoundError
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"error"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|,
name|Q_ARG
argument_list|(
name|QNetworkReply
operator|::
name|NetworkError
argument_list|,
name|QNetworkReply
operator|::
name|ContentNotFoundError
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"finished"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
return|return;
block|}
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
name|d
operator|->
name|realFileSize
operator|=
name|fi
operator|.
name|size
argument_list|()
expr_stmt|;
name|setHeader
argument_list|(
name|QNetworkRequest
operator|::
name|ContentLengthHeader
argument_list|,
name|d
operator|->
name|realFileSize
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"metaDataChanged"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"downloadProgress"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|,
name|Q_ARG
argument_list|(
name|qint64
argument_list|,
name|d
operator|->
name|realFileSize
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|qint64
argument_list|,
name|d
operator|->
name|realFileSize
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"readyRead"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"finished"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|close
name|void
name|QNetworkReplyFileImpl
operator|::
name|close
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QNetworkReplyFileImpl
argument_list|)
expr_stmt|;
name|QNetworkReply
operator|::
name|close
argument_list|()
expr_stmt|;
name|d
operator|->
name|realFile
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|abort
name|void
name|QNetworkReplyFileImpl
operator|::
name|abort
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QNetworkReplyFileImpl
argument_list|)
expr_stmt|;
name|QNetworkReply
operator|::
name|close
argument_list|()
expr_stmt|;
name|d
operator|->
name|realFile
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bytesAvailable
name|qint64
name|QNetworkReplyFileImpl
operator|::
name|bytesAvailable
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QNetworkReplyFileImpl
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|realFile
operator|.
name|isOpen
argument_list|()
condition|)
return|return
name|QNetworkReply
operator|::
name|bytesAvailable
argument_list|()
return|;
return|return
name|QNetworkReply
operator|::
name|bytesAvailable
argument_list|()
operator|+
name|d
operator|->
name|realFile
operator|.
name|bytesAvailable
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isSequential
name|bool
name|QNetworkReplyFileImpl
operator|::
name|isSequential
parameter_list|()
specifier|const
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|size
name|qint64
name|QNetworkReplyFileImpl
operator|::
name|size
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QNetworkReplyFileImpl
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|realFileSize
return|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|readData
name|qint64
name|QNetworkReplyFileImpl
operator|::
name|readData
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxlen
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QNetworkReplyFileImpl
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|realFile
operator|.
name|isOpen
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
name|qint64
name|ret
init|=
name|d
operator|->
name|realFile
operator|.
name|read
argument_list|(
name|data
argument_list|,
name|maxlen
argument_list|)
decl_stmt|;
if|if
condition|(
name|bytesAvailable
argument_list|()
operator|==
literal|0
operator|&&
name|d
operator|->
name|realFile
operator|.
name|isOpen
argument_list|()
condition|)
name|d
operator|->
name|realFile
operator|.
name|close
argument_list|()
expr_stmt|;
if|if
condition|(
name|ret
operator|==
literal|0
operator|&&
name|bytesAvailable
argument_list|()
operator|==
literal|0
condition|)
return|return
operator|-
literal|1
return|;
else|else
block|{
name|setAttribute
argument_list|(
name|QNetworkRequest
operator|::
name|HttpStatusCodeAttribute
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|QNetworkRequest
operator|::
name|HttpReasonPhraseAttribute
argument_list|,
name|QLatin1String
argument_list|(
literal|"OK"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qnetworkreplyfileimpl_p.cpp"
end_include
end_unit
