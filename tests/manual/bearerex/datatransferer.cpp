begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QUrl>
end_include
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_include
include|#
directive|include
file|<QDataStream>
end_include
begin_include
include|#
directive|include
file|"datatransferer.h"
end_include
begin_constructor
DECL|function|DataTransferer
name|DataTransferer
operator|::
name|DataTransferer
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_dataTransferOngoing
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|dataTransferOngoing
name|bool
name|DataTransferer
operator|::
name|dataTransferOngoing
parameter_list|()
block|{
return|return
name|m_dataTransferOngoing
return|;
block|}
end_function
begin_comment
comment|// -------- Based on QTcp
end_comment
begin_constructor
DECL|function|DataTransfererQTcp
name|DataTransfererQTcp
operator|::
name|DataTransfererQTcp
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|DataTransferer
argument_list|(
name|parent
argument_list|)
block|{
name|qDebug
argument_list|(
literal|"BearerEx DataTransferer QTcp created."
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|m_qsocket
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
name|readyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|m_qsocket
argument_list|,
name|SIGNAL
argument_list|(
name|connected
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|connected
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|m_qsocket
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
name|this
argument_list|,
name|SLOT
argument_list|(
name|error
argument_list|(
name|QAbstractSocket
operator|::
name|SocketError
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~DataTransfererQTcp
name|DataTransfererQTcp
operator|::
name|~
name|DataTransfererQTcp
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"BearerEx DataTransferer QTcp destroyed."
argument_list|)
expr_stmt|;
name|m_qsocket
operator|.
name|abort
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|transferData
name|bool
name|DataTransfererQTcp
operator|::
name|transferData
parameter_list|()
block|{
if|if
condition|(
name|m_dataTransferOngoing
condition|)
block|{
return|return
literal|false
return|;
block|}
name|qDebug
argument_list|(
literal|"BearerEx datatransfer for QTcp requested."
argument_list|)
expr_stmt|;
comment|// Connect to host
name|QUrl
name|url
argument_list|(
literal|"http://www.google.com.au"
argument_list|)
decl_stmt|;
name|m_qsocket
operator|.
name|connectToHost
argument_list|(
name|url
operator|.
name|host
argument_list|()
argument_list|,
name|url
operator|.
name|port
argument_list|(
literal|80
argument_list|)
argument_list|)
expr_stmt|;
comment|// m_qsocket.connectToHost("http://www.google.com", 80);
comment|// Wait for connected() signal.
name|m_dataTransferOngoing
operator|=
literal|true
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|connected
name|void
name|DataTransfererQTcp
operator|::
name|connected
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"BearerEx DataTransfererQtcp connected, requesting data."
argument_list|)
expr_stmt|;
comment|// Establish HTTP request
comment|//QByteArray request("GET / HTTP/1.1 \nHost: www.google.com\n\n");
name|QByteArray
name|request
argument_list|(
literal|"GET / HTTP/1.1\n\n"
argument_list|)
decl_stmt|;
comment|// QByteArray request("GET /index.html HTTP/1.1 \n Host: www.google.com \n\n");
name|qint64
name|dataWritten
init|=
name|m_qsocket
operator|.
name|write
argument_list|(
name|request
argument_list|)
decl_stmt|;
name|m_qsocket
operator|.
name|flush
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"BearerEx DataTransferQTcp wrote "
operator|<<
name|dataWritten
operator|<<
literal|" bytes"
expr_stmt|;
comment|// Start waiting for readyRead() of error()
block|}
end_function
begin_function
DECL|function|readyRead
name|void
name|DataTransfererQTcp
operator|::
name|readyRead
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"BearerEx DataTransfererQTcp readyRead() with "
expr_stmt|;
name|qint64
name|bytesAvailable
init|=
name|m_qsocket
operator|.
name|bytesAvailable
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|bytesAvailable
operator|<<
literal|" bytes available."
expr_stmt|;
comment|// QDataStream in(&m_qsocket);
name|QByteArray
name|array
init|=
name|m_qsocket
operator|.
name|readAll
argument_list|()
decl_stmt|;
name|QString
name|data
init|=
name|QString
operator|::
name|fromAscii
argument_list|(
name|array
argument_list|)
decl_stmt|;
comment|// in>> data;
name|qDebug
argument_list|()
operator|<<
literal|"BearerEx DataTransferQTcp data received: "
operator|<<
name|data
expr_stmt|;
name|m_dataTransferOngoing
operator|=
literal|false
expr_stmt|;
comment|// m_qsocket.error() returns uninitialized value in case no error has occurred,
comment|// so emit '0'
emit|emit
name|finished
argument_list|(
literal|0
argument_list|,
name|bytesAvailable
argument_list|,
literal|"QAbstractSocket::SocketError"
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|error
name|void
name|DataTransfererQTcp
operator|::
name|error
parameter_list|(
name|QAbstractSocket
operator|::
name|SocketError
name|socketError
parameter_list|)
block|{
name|qDebug
argument_list|(
literal|"BearerEx DataTransfererQTcp error(), aborting socket."
argument_list|)
expr_stmt|;
name|m_qsocket
operator|.
name|abort
argument_list|()
expr_stmt|;
name|m_dataTransferOngoing
operator|=
literal|false
expr_stmt|;
emit|emit
name|finished
argument_list|(
name|socketError
argument_list|,
literal|0
argument_list|,
literal|"QAbstractSocket::SocketError"
argument_list|)
emit|;
block|}
end_function
begin_comment
comment|// -------- Based on QHttp
end_comment
begin_constructor
DECL|function|DataTransfererQHttp
name|DataTransfererQHttp
operator|::
name|DataTransfererQHttp
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|DataTransferer
argument_list|(
name|parent
argument_list|)
block|{
name|connect
argument_list|(
operator|&
name|m_qhttp
argument_list|,
name|SIGNAL
argument_list|(
name|done
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|done
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"BearerEx DataTransferer QHttp created."
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~DataTransfererQHttp
name|DataTransfererQHttp
operator|::
name|~
name|DataTransfererQHttp
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"BearerEx DataTransferer QHttp destroyed."
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|transferData
name|bool
name|DataTransfererQHttp
operator|::
name|transferData
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"BearerEx datatransfer for QHttp requested."
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_dataTransferOngoing
condition|)
block|{
return|return
literal|false
return|;
block|}
name|QString
name|urlstring
argument_list|(
literal|"http://www.google.com"
argument_list|)
decl_stmt|;
name|QUrl
name|url
argument_list|(
name|urlstring
argument_list|)
decl_stmt|;
name|m_qhttp
operator|.
name|setHost
argument_list|(
name|url
operator|.
name|host
argument_list|()
argument_list|,
name|QHttp
operator|::
name|ConnectionModeHttp
argument_list|,
name|url
operator|.
name|port
argument_list|()
operator|==
operator|-
literal|1
condition|?
literal|0
else|:
name|url
operator|.
name|port
argument_list|()
argument_list|)
expr_stmt|;
name|m_qhttp
operator|.
name|get
argument_list|(
name|urlstring
argument_list|)
expr_stmt|;
name|m_dataTransferOngoing
operator|=
literal|true
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|done
name|void
name|DataTransfererQHttp
operator|::
name|done
parameter_list|(
name|bool
comment|/*error*/
parameter_list|)
block|{
name|qDebug
argument_list|(
literal|"BearerEx DatatransfererQHttp reply was finished (error code is type QHttp::Error)."
argument_list|)
expr_stmt|;
name|qint64
name|dataReceived
init|=
literal|0
decl_stmt|;
name|quint32
name|errorCode
init|=
name|m_qhttp
operator|.
name|error
argument_list|()
decl_stmt|;
if|if
condition|(
name|m_qhttp
operator|.
name|error
argument_list|()
operator|==
name|QHttp
operator|::
name|NoError
condition|)
block|{
name|QString
name|result
argument_list|(
name|m_qhttp
operator|.
name|readAll
argument_list|()
argument_list|)
decl_stmt|;
name|dataReceived
operator|=
name|result
operator|.
name|length
argument_list|()
expr_stmt|;
block|}
name|m_dataTransferOngoing
operator|=
literal|false
expr_stmt|;
emit|emit
name|finished
argument_list|(
name|errorCode
argument_list|,
name|dataReceived
argument_list|,
literal|"QHttp::Error"
argument_list|)
emit|;
block|}
end_function
begin_comment
comment|// -------- Based on QNetworkAccessManager
end_comment
begin_constructor
DECL|function|DataTransfererQNam
name|DataTransfererQNam
operator|::
name|DataTransfererQNam
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|DataTransferer
argument_list|(
name|parent
argument_list|)
block|{
name|connect
argument_list|(
operator|&
name|m_qnam
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|(
name|QNetworkReply
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|replyFinished
argument_list|(
name|QNetworkReply
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"BearerEx DataTransferer QNam created."
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~DataTransfererQNam
name|DataTransfererQNam
operator|::
name|~
name|DataTransfererQNam
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"BearerEx DataTransferer QNam destroyed."
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|transferData
name|bool
name|DataTransfererQNam
operator|::
name|transferData
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"BearerEx datatransfer for QNam requested."
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_dataTransferOngoing
condition|)
block|{
return|return
literal|false
return|;
block|}
name|m_qnam
operator|.
name|get
argument_list|(
name|QNetworkRequest
argument_list|(
name|QUrl
argument_list|(
literal|"http://www.google.com"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_dataTransferOngoing
operator|=
literal|true
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|replyFinished
name|void
name|DataTransfererQNam
operator|::
name|replyFinished
parameter_list|(
name|QNetworkReply
modifier|*
name|reply
parameter_list|)
block|{
name|qDebug
argument_list|(
literal|"BearerEx DatatransfererQNam reply was finished (error code is type QNetworkReply::NetworkError)."
argument_list|)
expr_stmt|;
name|qint64
name|dataReceived
init|=
literal|0
decl_stmt|;
name|quint32
name|errorCode
init|=
operator|(
name|quint32
operator|)
name|reply
operator|->
name|error
argument_list|()
decl_stmt|;
if|if
condition|(
name|reply
operator|->
name|error
argument_list|()
operator|==
name|QNetworkReply
operator|::
name|NoError
condition|)
block|{
name|QString
name|result
argument_list|(
name|reply
operator|->
name|readAll
argument_list|()
argument_list|)
decl_stmt|;
name|dataReceived
operator|=
name|result
operator|.
name|length
argument_list|()
expr_stmt|;
block|}
name|m_dataTransferOngoing
operator|=
literal|false
expr_stmt|;
emit|emit
name|finished
argument_list|(
name|errorCode
argument_list|,
name|dataReceived
argument_list|,
literal|"QNetworkReply::NetworkError"
argument_list|)
emit|;
name|reply
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
