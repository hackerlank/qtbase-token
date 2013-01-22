begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnetworkreplydataimpl_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qdataurl_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMetaObject>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QNetworkReplyDataImplPrivate
name|QNetworkReplyDataImplPrivate
operator|::
name|QNetworkReplyDataImplPrivate
parameter_list|()
member_init_list|:
name|QNetworkReplyPrivate
argument_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~QNetworkReplyDataImplPrivate
name|QNetworkReplyDataImplPrivate
operator|::
name|~
name|QNetworkReplyDataImplPrivate
parameter_list|()
block|{ }
end_destructor
begin_destructor
DECL|function|~QNetworkReplyDataImpl
name|QNetworkReplyDataImpl
operator|::
name|~
name|QNetworkReplyDataImpl
parameter_list|()
block|{ }
end_destructor
begin_constructor
DECL|function|QNetworkReplyDataImpl
name|QNetworkReplyDataImpl
operator|::
name|QNetworkReplyDataImpl
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
name|QNetworkReplyDataImplPrivate
argument_list|()
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QNetworkReplyDataImpl
argument_list|)
expr_stmt|;
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
name|QUrl
name|url
init|=
name|req
operator|.
name|url
argument_list|()
decl_stmt|;
name|QString
name|mimeType
decl_stmt|;
name|QByteArray
name|payload
decl_stmt|;
if|if
condition|(
name|qDecodeDataUrl
argument_list|(
name|url
argument_list|,
name|mimeType
argument_list|,
name|payload
argument_list|)
condition|)
block|{
name|qint64
name|size
init|=
name|payload
operator|.
name|size
argument_list|()
decl_stmt|;
name|setHeader
argument_list|(
name|QNetworkRequest
operator|::
name|ContentTypeHeader
argument_list|,
name|mimeType
argument_list|)
expr_stmt|;
name|setHeader
argument_list|(
name|QNetworkRequest
operator|::
name|ContentLengthHeader
argument_list|,
name|size
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
name|d
operator|->
name|decodedData
operator|.
name|setData
argument_list|(
name|payload
argument_list|)
expr_stmt|;
name|d
operator|->
name|decodedData
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
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
name|size
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|qint64
argument_list|,
name|size
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
else|else
block|{
comment|// something wrong with this URI
specifier|const
name|QString
name|msg
init|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QNetworkAccessDataBackend"
argument_list|,
literal|"Invalid URI: %1"
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
name|ProtocolFailure
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
name|ProtocolFailure
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
block|}
block|}
end_constructor
begin_function
DECL|function|close
name|void
name|QNetworkReplyDataImpl
operator|::
name|close
parameter_list|()
block|{
name|QNetworkReply
operator|::
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|abort
name|void
name|QNetworkReplyDataImpl
operator|::
name|abort
parameter_list|()
block|{
name|QNetworkReply
operator|::
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bytesAvailable
name|qint64
name|QNetworkReplyDataImpl
operator|::
name|bytesAvailable
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QNetworkReplyDataImpl
argument_list|)
expr_stmt|;
return|return
name|QNetworkReply
operator|::
name|bytesAvailable
argument_list|()
operator|+
name|d
operator|->
name|decodedData
operator|.
name|bytesAvailable
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isSequential
name|bool
name|QNetworkReplyDataImpl
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
name|QNetworkReplyDataImpl
operator|::
name|size
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QNetworkReplyDataImpl
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|decodedData
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|readData
name|qint64
name|QNetworkReplyDataImpl
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
name|QNetworkReplyDataImpl
argument_list|)
expr_stmt|;
comment|// TODO idea:
comment|// Instead of decoding the whole data into new memory, we could decode on demand.
comment|// Note that this might be tricky to do.
return|return
name|d
operator|->
name|decodedData
operator|.
name|read
argument_list|(
name|data
argument_list|,
name|maxlen
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qnetworkreplydataimpl_p.cpp"
end_include
end_unit
