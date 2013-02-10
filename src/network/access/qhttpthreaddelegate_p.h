begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QHTTPTHREADDELEGATE_H
end_ifndef
begin_define
DECL|macro|QHTTPTHREADDELEGATE_H
define|#
directive|define
name|QHTTPTHREADDELEGATE_H
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
comment|// of the Network Access API.  This header file may change from
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
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QThreadStorage>
end_include
begin_include
include|#
directive|include
file|<QNetworkProxy>
end_include
begin_include
include|#
directive|include
file|<QSslConfiguration>
end_include
begin_include
include|#
directive|include
file|<QSslError>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QNetworkReply>
end_include
begin_include
include|#
directive|include
file|"qhttpnetworkrequest_p.h"
end_include
begin_include
include|#
directive|include
file|"qhttpnetworkconnection_p.h"
end_include
begin_include
include|#
directive|include
file|<QSharedPointer>
end_include
begin_include
include|#
directive|include
file|"qsslconfiguration.h"
end_include
begin_include
include|#
directive|include
file|"private/qnoncontiguousbytedevice_p.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkaccessauthenticationmanager_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_HTTP
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAuthenticator
name|class
name|QAuthenticator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHttpNetworkReply
name|class
name|QHttpNetworkReply
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEventLoop
name|class
name|QEventLoop
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkAccessCache
name|class
name|QNetworkAccessCache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkAccessCachedHttpConnection
name|class
name|QNetworkAccessCachedHttpConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QHttpThreadDelegate
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QHttpThreadDelegate
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QHttpThreadDelegate
argument_list|()
block|;
comment|// incoming
name|bool
name|ssl
block|;
ifndef|#
directive|ifndef
name|QT_NO_SSL
name|QSslConfiguration
name|incomingSslConfiguration
block|;
endif|#
directive|endif
name|QHttpNetworkRequest
name|httpRequest
block|;
name|qint64
name|downloadBufferMaximumSize
block|;
name|qint64
name|readBufferMaxSize
block|;
name|qint64
name|bytesEmitted
block|;
comment|// From backend, modified by us for signal compression
name|QSharedPointer
operator|<
name|QAtomicInt
operator|>
name|pendingDownloadData
block|;
name|QSharedPointer
operator|<
name|QAtomicInt
operator|>
name|pendingDownloadProgress
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|QNetworkProxy
name|cacheProxy
block|;
name|QNetworkProxy
name|transparentProxy
block|;
endif|#
directive|endif
name|QSharedPointer
operator|<
name|QNetworkAccessAuthenticationManager
operator|>
name|authenticationManager
block|;
name|bool
name|synchronous
block|;
comment|// outgoing, Retrieved in the synchronous HTTP case
name|QByteArray
name|synchronousDownloadData
block|;
name|QList
operator|<
name|QPair
operator|<
name|QByteArray
block|,
name|QByteArray
operator|>
expr|>
name|incomingHeaders
block|;
name|int
name|incomingStatusCode
block|;
name|QString
name|incomingReasonPhrase
block|;
name|bool
name|isPipeliningUsed
block|;
name|qint64
name|incomingContentLength
block|;
name|QNetworkReply
operator|::
name|NetworkError
name|incomingErrorCode
block|;
name|QString
name|incomingErrorDetail
block|;
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|QSharedPointer
operator|<
name|QNetworkSession
operator|>
name|networkSession
block|;
endif|#
directive|endif
name|protected
operator|:
comment|// The zerocopy download buffer, if used:
name|QSharedPointer
operator|<
name|char
operator|>
name|downloadBuffer
block|;
comment|// The QHttpNetworkConnection that is used
name|QNetworkAccessCachedHttpConnection
operator|*
name|httpConnection
block|;
name|QByteArray
name|cacheKey
block|;
name|QHttpNetworkReply
operator|*
name|httpReply
block|;
comment|// Used for implementing the synchronous HTTP, see startRequestSynchronously()
name|QEventLoop
operator|*
name|synchronousRequestLoop
block|;
name|signals
operator|:
name|void
name|authenticationRequired
argument_list|(
specifier|const
name|QHttpNetworkRequest
operator|&
name|request
argument_list|,
name|QAuthenticator
operator|*
argument_list|)
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
argument_list|,
name|QAuthenticator
operator|*
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_SSL
name|void
name|encrypted
argument_list|()
block|;
name|void
name|sslErrors
argument_list|(
specifier|const
name|QList
operator|<
name|QSslError
operator|>
operator|&
argument_list|,
name|bool
operator|*
argument_list|,
name|QList
operator|<
name|QSslError
operator|>
operator|*
argument_list|)
block|;
name|void
name|sslConfigurationChanged
argument_list|(
specifier|const
name|QSslConfiguration
argument_list|)
block|;
endif|#
directive|endif
name|void
name|downloadMetaData
argument_list|(
name|QList
operator|<
name|QPair
operator|<
name|QByteArray
argument_list|,
name|QByteArray
operator|>
expr|>
argument_list|,
name|int
argument_list|,
name|QString
argument_list|,
name|bool
argument_list|,
name|QSharedPointer
operator|<
name|char
operator|>
argument_list|,
name|qint64
argument_list|)
block|;
name|void
name|downloadProgress
argument_list|(
name|qint64
argument_list|,
name|qint64
argument_list|)
block|;
name|void
name|downloadData
argument_list|(
name|QByteArray
argument_list|)
block|;
name|void
name|error
argument_list|(
name|QNetworkReply
operator|::
name|NetworkError
argument_list|,
specifier|const
name|QString
argument_list|)
block|;
name|void
name|downloadFinished
argument_list|()
block|;
name|public
name|slots
operator|:
comment|// This are called via QueuedConnection from user thread
name|void
name|startRequest
argument_list|()
block|;
name|void
name|abortRequest
argument_list|()
block|;
name|void
name|readBufferSizeChanged
argument_list|(
argument|qint64 size
argument_list|)
block|;
name|void
name|readBufferFreed
argument_list|(
argument|qint64 size
argument_list|)
block|;
comment|// This is called with a BlockingQueuedConnection from user thread
name|void
name|startRequestSynchronously
argument_list|()
block|;
name|protected
name|slots
operator|:
comment|// From QHttp*
name|void
name|readyReadSlot
argument_list|()
block|;
name|void
name|finishedSlot
argument_list|()
block|;
name|void
name|finishedWithErrorSlot
argument_list|(
argument|QNetworkReply::NetworkError errorCode
argument_list|,
argument|const QString&detail = QString()
argument_list|)
block|;
name|void
name|synchronousFinishedSlot
argument_list|()
block|;
name|void
name|synchronousFinishedWithErrorSlot
argument_list|(
argument|QNetworkReply::NetworkError errorCode
argument_list|,
argument|const QString&detail = QString()
argument_list|)
block|;
name|void
name|headerChangedSlot
argument_list|()
block|;
name|void
name|synchronousHeaderChangedSlot
argument_list|()
block|;
name|void
name|dataReadProgressSlot
argument_list|(
argument|qint64 done
argument_list|,
argument|qint64 total
argument_list|)
block|;
name|void
name|cacheCredentialsSlot
argument_list|(
specifier|const
name|QHttpNetworkRequest
operator|&
name|request
argument_list|,
name|QAuthenticator
operator|*
name|authenticator
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_SSL
name|void
name|encryptedSlot
argument_list|()
block|;
name|void
name|sslErrorsSlot
argument_list|(
specifier|const
name|QList
operator|<
name|QSslError
operator|>
operator|&
name|errors
argument_list|)
block|;
endif|#
directive|endif
name|void
name|synchronousAuthenticationRequiredSlot
argument_list|(
specifier|const
name|QHttpNetworkRequest
operator|&
name|request
argument_list|,
name|QAuthenticator
operator|*
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|void
name|synchronousProxyAuthenticationRequiredSlot
argument_list|(
specifier|const
name|QNetworkProxy
operator|&
argument_list|,
name|QAuthenticator
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|protected
operator|:
comment|// Cache for all the QHttpNetworkConnection objects.
comment|// This is per thread.
specifier|static
name|QThreadStorage
operator|<
name|QNetworkAccessCache
operator|*
operator|>
name|connections
block|;  }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// This QNonContiguousByteDevice is connected to the QNetworkAccessHttpBackend
end_comment
begin_comment
comment|// and represents the PUT/POST data.
end_comment
begin_decl_stmt
name|class
name|QNonContiguousByteDeviceThreadForwardImpl
range|:
name|public
name|QNonContiguousByteDevice
block|{
name|Q_OBJECT
name|protected
operator|:
name|bool
name|wantDataPending
block|;
name|qint64
name|m_amount
block|;
name|char
operator|*
name|m_data
block|;
name|QByteArray
name|m_dataArray
block|;
name|bool
name|m_atEnd
block|;
name|qint64
name|m_size
block|;
name|public
operator|:
name|QNonContiguousByteDeviceThreadForwardImpl
argument_list|(
argument|bool aE
argument_list|,
argument|qint64 s
argument_list|)
operator|:
name|QNonContiguousByteDevice
argument_list|()
block|,
name|wantDataPending
argument_list|(
name|false
argument_list|)
block|,
name|m_amount
argument_list|(
literal|0
argument_list|)
block|,
name|m_data
argument_list|(
literal|0
argument_list|)
block|,
name|m_atEnd
argument_list|(
name|aE
argument_list|)
block|,
name|m_size
argument_list|(
argument|s
argument_list|)
block|{     }
operator|~
name|QNonContiguousByteDeviceThreadForwardImpl
argument_list|()
block|{     }
specifier|const
name|char
operator|*
name|readPointer
argument_list|(
argument|qint64 maximumLength
argument_list|,
argument|qint64&len
argument_list|)
block|{
if|if
condition|(
name|m_amount
operator|>
literal|0
condition|)
block|{
name|len
operator|=
name|m_amount
expr_stmt|;
return|return
name|m_data
return|;
block|}
if|if
condition|(
name|m_atEnd
condition|)
block|{
name|len
operator|=
operator|-
literal|1
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|wantDataPending
condition|)
block|{
name|len
operator|=
literal|0
expr_stmt|;
name|wantDataPending
operator|=
name|true
expr_stmt|;
name|emit
name|wantData
parameter_list|(
name|maximumLength
parameter_list|)
function_decl|;
block|}
else|else
block|{
comment|// Do nothing, we already sent a wantData signal and wait for results
name|len
operator|=
literal|0
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
name|bool
name|advanceReadPointer
argument_list|(
argument|qint64 a
argument_list|)
block|{
if|if
condition|(
name|m_data
operator|==
literal|0
condition|)
return|return
name|false
return|;
name|m_amount
operator|-=
name|a
block|;
name|m_data
operator|+=
name|a
block|;
comment|// To main thread to inform about our state
name|emit
name|processedData
argument_list|(
name|a
argument_list|)
block|;
comment|// FIXME possible optimization, already ask user thread for some data
return|return
name|true
return|;
block|}
end_decl_stmt
begin_function
name|bool
name|atEnd
parameter_list|()
block|{
if|if
condition|(
name|m_amount
operator|>
literal|0
condition|)
return|return
name|false
return|;
else|else
return|return
name|m_atEnd
return|;
block|}
end_function
begin_function
name|bool
name|reset
parameter_list|()
block|{
name|m_amount
operator|=
literal|0
expr_stmt|;
name|m_data
operator|=
literal|0
expr_stmt|;
comment|// Communicate as BlockingQueuedConnection
name|bool
name|b
init|=
name|false
decl_stmt|;
name|emit
name|resetData
argument_list|(
operator|&
name|b
argument_list|)
decl_stmt|;
return|return
name|b
return|;
block|}
end_function
begin_function
name|qint64
name|size
parameter_list|()
block|{
return|return
name|m_size
return|;
block|}
end_function
begin_decl_stmt
name|public
name|slots
range|:
comment|// From user thread:
name|void
name|haveDataSlot
argument_list|(
argument|QByteArray dataArray
argument_list|,
argument|bool dataAtEnd
argument_list|,
argument|qint64 dataSize
argument_list|)
block|{
name|wantDataPending
operator|=
name|false
block|;
name|m_dataArray
operator|=
name|dataArray
block|;
name|m_data
operator|=
name|const_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|m_dataArray
operator|.
name|constData
argument_list|()
operator|)
block|;
name|m_amount
operator|=
name|dataArray
operator|.
name|size
argument_list|()
block|;
name|m_atEnd
operator|=
name|dataAtEnd
block|;
name|m_size
operator|=
name|dataSize
block|;
comment|// This will tell the HTTP code (QHttpNetworkConnectionChannel) that we have data available now
name|emit
name|readyRead
argument_list|()
block|;     }
name|signals
operator|:
comment|// void readyRead(); in parent class
comment|// void readProgress(qint64 current, qint64 total); happens in the main thread with the real bytedevice
comment|// to main thread:
name|void
name|wantData
argument_list|(
name|qint64
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|processedData
parameter_list|(
name|qint64
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|resetData
parameter_list|(
name|bool
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_HTTP
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QHTTPTHREADDELEGATE_H
end_comment
end_unit
