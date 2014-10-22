begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QHTTPNETWORKCONNECTION_H
end_ifndef
begin_define
DECL|macro|QHTTPNETWORKCONNECTION_H
define|#
directive|define
name|QHTTPNETWORKCONNECTION_H
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
file|<QtNetwork/qnetworkrequest.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkreply.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qabstractsocket.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworksession.h>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<qauthenticator.h>
end_include
begin_include
include|#
directive|include
file|<qnetworkproxy.h>
end_include
begin_include
include|#
directive|include
file|<qbuffer.h>
end_include
begin_include
include|#
directive|include
file|<qtimer.h>
end_include
begin_include
include|#
directive|include
file|<qsharedpointer.h>
end_include
begin_include
include|#
directive|include
file|<private/qhttpnetworkheader_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qhttpnetworkrequest_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qhttpnetworkreply_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qhttpnetworkconnectionchannel_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_HTTP
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SSL
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
end_ifndef
begin_include
include|#
directive|include
file|<private/qsslcontext_openssl_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<private/qsslsocket_p.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qsslsocket.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qsslerror.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<QtNetwork/qtcpsocket.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QHttpNetworkRequest
name|class
name|QHttpNetworkRequest
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHttpNetworkReply
name|class
name|QHttpNetworkReply
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHttpThreadDelegate
name|class
name|QHttpThreadDelegate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QByteArray
name|class
name|QByteArray
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHostInfo
name|class
name|QHostInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHttpNetworkConnectionPrivate
name|class
name|QHttpNetworkConnectionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QHttpNetworkConnection
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|ConnectionType
block|{
name|ConnectionTypeHTTP
block|,
name|ConnectionTypeSPDY
block|}
block|;
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|explicit
name|QHttpNetworkConnection
argument_list|(
argument|const QString&hostName
argument_list|,
argument|quint16 port =
literal|80
argument_list|,
argument|bool encrypt = false
argument_list|,
argument|ConnectionType connectionType = ConnectionTypeHTTP
argument_list|,
argument|QObject *parent =
literal|0
argument_list|,
argument|QSharedPointer<QNetworkSession> networkSession                                     = QSharedPointer<QNetworkSession>()
argument_list|)
block|;
name|QHttpNetworkConnection
argument_list|(
argument|quint16 channelCount
argument_list|,
argument|const QString&hostName
argument_list|,
argument|quint16 port =
literal|80
argument_list|,
argument|bool encrypt = false
argument_list|,
argument|QObject *parent =
literal|0
argument_list|,
argument|QSharedPointer<QNetworkSession> networkSession = QSharedPointer<QNetworkSession>()
argument_list|,
argument|ConnectionType connectionType = ConnectionTypeHTTP
argument_list|)
block|;
else|#
directive|else
name|explicit
name|QHttpNetworkConnection
argument_list|(
argument|const QString&hostName
argument_list|,
argument|quint16 port =
literal|80
argument_list|,
argument|bool encrypt = false
argument_list|,
argument|ConnectionType connectionType = ConnectionTypeHTTP
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
name|QHttpNetworkConnection
argument_list|(
argument|quint16 channelCount
argument_list|,
argument|const QString&hostName
argument_list|,
argument|quint16 port =
literal|80
argument_list|,
argument|bool encrypt = false
argument_list|,
argument|QObject *parent =
literal|0
argument_list|,
argument|ConnectionType connectionType = ConnectionTypeHTTP
argument_list|)
block|;
endif|#
directive|endif
operator|~
name|QHttpNetworkConnection
argument_list|()
block|;
comment|//The hostname to which this is connected to.
name|QString
name|hostName
argument_list|()
specifier|const
block|;
comment|//The HTTP port in use.
name|quint16
name|port
argument_list|()
specifier|const
block|;
comment|//add a new HTTP request through this connection
name|QHttpNetworkReply
operator|*
name|sendRequest
argument_list|(
specifier|const
name|QHttpNetworkRequest
operator|&
name|request
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
comment|//set the proxy for this connection
name|void
name|setCacheProxy
argument_list|(
specifier|const
name|QNetworkProxy
operator|&
name|networkProxy
argument_list|)
block|;
name|QNetworkProxy
name|cacheProxy
argument_list|()
specifier|const
block|;
name|void
name|setTransparentProxy
argument_list|(
specifier|const
name|QNetworkProxy
operator|&
name|networkProxy
argument_list|)
block|;
name|QNetworkProxy
name|transparentProxy
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|bool
name|isSsl
argument_list|()
specifier|const
block|;
name|QHttpNetworkConnectionChannel
operator|*
name|channels
argument_list|()
specifier|const
block|;
name|ConnectionType
name|connectionType
argument_list|()
block|;
name|void
name|setConnectionType
argument_list|(
argument|ConnectionType type
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_SSL
name|void
name|setSslConfiguration
argument_list|(
specifier|const
name|QSslConfiguration
operator|&
name|config
argument_list|)
block|;
name|void
name|ignoreSslErrors
argument_list|(
argument|int channel = -
literal|1
argument_list|)
block|;
name|void
name|ignoreSslErrors
argument_list|(
argument|const QList<QSslError>&errors
argument_list|,
argument|int channel = -
literal|1
argument_list|)
block|;
name|QSharedPointer
operator|<
name|QSslContext
operator|>
name|sslContext
argument_list|()
block|;
name|void
name|setSslContext
argument_list|(
name|QSharedPointer
operator|<
name|QSslContext
operator|>
name|context
argument_list|)
block|;
endif|#
directive|endif
name|void
name|preConnectFinished
argument_list|()
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QHttpNetworkConnection
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QHttpNetworkConnection
argument_list|)
name|friend
name|class
name|QHttpThreadDelegate
block|;
name|friend
name|class
name|QHttpNetworkReply
block|;
name|friend
name|class
name|QHttpNetworkReplyPrivate
block|;
name|friend
name|class
name|QHttpNetworkConnectionChannel
block|;
name|friend
name|class
name|QHttpProtocolHandler
block|;
name|friend
name|class
name|QSpdyProtocolHandler
block|;
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_startNextRequest()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_hostLookupFinished(QHostInfo)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_connectDelayedChannel()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|// private classes
end_comment
begin_typedef
DECL|typedef|QHttpNetworkRequest
DECL|typedef|HttpMessagePair
typedef|typedef
name|QPair
operator|<
name|QHttpNetworkRequest
operator|,
name|QHttpNetworkReply
operator|*
operator|>
name|HttpMessagePair
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QHttpNetworkConnectionPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QHttpNetworkConnection
argument_list|)
name|public
operator|:
specifier|static
specifier|const
name|int
name|defaultHttpChannelCount
block|;
specifier|static
specifier|const
name|int
name|defaultPipelineLength
block|;
specifier|static
specifier|const
name|int
name|defaultRePipelineLength
block|;      enum
name|ConnectionState
block|{
name|RunningState
operator|=
literal|0
block|,
name|PausedState
operator|=
literal|1
block|}
block|;      enum
name|NetworkLayerPreferenceState
block|{
name|Unknown
block|,
name|HostLookupPending
block|,
name|IPv4
block|,
name|IPv6
block|,
name|IPv4or6
block|}
block|;
name|QHttpNetworkConnectionPrivate
argument_list|(
argument|const QString&hostName
argument_list|,
argument|quint16 port
argument_list|,
argument|bool encrypt
argument_list|,
argument|QHttpNetworkConnection::ConnectionType type
argument_list|)
block|;
name|QHttpNetworkConnectionPrivate
argument_list|(
argument|quint16 channelCount
argument_list|,
argument|const QString&hostName
argument_list|,
argument|quint16 port
argument_list|,
argument|bool encrypt
argument_list|,
argument|QHttpNetworkConnection::ConnectionType type
argument_list|)
block|;
operator|~
name|QHttpNetworkConnectionPrivate
argument_list|()
block|;
name|void
name|init
argument_list|()
block|;
name|void
name|pauseConnection
argument_list|()
block|;
name|void
name|resumeConnection
argument_list|()
block|;
name|ConnectionState
name|state
block|;
name|NetworkLayerPreferenceState
name|networkLayerState
block|;      enum
block|{
name|ChunkSize
operator|=
literal|4096
block|}
block|;
name|int
name|indexOf
argument_list|(
argument|QAbstractSocket *socket
argument_list|)
specifier|const
block|;
name|QHttpNetworkReply
operator|*
name|queueRequest
argument_list|(
specifier|const
name|QHttpNetworkRequest
operator|&
name|request
argument_list|)
block|;
name|void
name|requeueRequest
argument_list|(
specifier|const
name|HttpMessagePair
operator|&
name|pair
argument_list|)
block|;
comment|// e.g. after pipeline broke
name|bool
name|dequeueRequest
argument_list|(
name|QAbstractSocket
operator|*
name|socket
argument_list|)
block|;
name|void
name|prepareRequest
argument_list|(
name|HttpMessagePair
operator|&
name|request
argument_list|)
block|;
name|QHttpNetworkRequest
name|predictNextRequest
argument_list|()
block|;
name|void
name|fillPipeline
argument_list|(
name|QAbstractSocket
operator|*
name|socket
argument_list|)
block|;
name|bool
name|fillPipeline
argument_list|(
name|QList
operator|<
name|HttpMessagePair
operator|>
operator|&
name|queue
argument_list|,
name|QHttpNetworkConnectionChannel
operator|&
name|channel
argument_list|)
block|;
comment|// read more HTTP body after the next event loop spin
name|void
name|readMoreLater
argument_list|(
name|QHttpNetworkReply
operator|*
name|reply
argument_list|)
block|;
name|void
name|copyCredentials
argument_list|(
argument|int fromChannel
argument_list|,
argument|QAuthenticator *auth
argument_list|,
argument|bool isProxy
argument_list|)
block|;
name|void
name|startHostInfoLookup
argument_list|()
block|;
name|void
name|startNetworkLayerStateLookup
argument_list|()
block|;
name|void
name|networkLayerDetected
argument_list|(
argument|QAbstractSocket::NetworkLayerProtocol protocol
argument_list|)
block|;
comment|// private slots
name|void
name|_q_startNextRequest
argument_list|()
block|;
comment|// send the next request from the queue
name|void
name|_q_hostLookupFinished
argument_list|(
argument|QHostInfo info
argument_list|)
block|;
name|void
name|_q_connectDelayedChannel
argument_list|()
block|;
name|void
name|createAuthorization
argument_list|(
name|QAbstractSocket
operator|*
name|socket
argument_list|,
name|QHttpNetworkRequest
operator|&
name|request
argument_list|)
block|;
name|QString
name|errorDetail
argument_list|(
argument|QNetworkReply::NetworkError errorCode
argument_list|,
argument|QAbstractSocket *socket
argument_list|,
argument|const QString&extraDetail = QString()
argument_list|)
block|;
name|void
name|removeReply
argument_list|(
name|QHttpNetworkReply
operator|*
name|reply
argument_list|)
block|;
name|QString
name|hostName
block|;
name|quint16
name|port
block|;
name|bool
name|encrypt
block|;
name|bool
name|delayIpv4
block|;
specifier|const
name|int
name|channelCount
block|;
name|QTimer
name|delayedConnectionTimer
block|;
name|QHttpNetworkConnectionChannel
operator|*
name|channels
block|;
comment|// parallel connections to the server
name|bool
name|shouldEmitChannelError
argument_list|(
name|QAbstractSocket
operator|*
name|socket
argument_list|)
block|;
name|qint64
name|uncompressedBytesAvailable
argument_list|(
argument|const QHttpNetworkReply&reply
argument_list|)
specifier|const
block|;
name|qint64
name|uncompressedBytesAvailableNextBlock
argument_list|(
argument|const QHttpNetworkReply&reply
argument_list|)
specifier|const
block|;
name|void
name|emitReplyError
argument_list|(
argument|QAbstractSocket *socket
argument_list|,
argument|QHttpNetworkReply *reply
argument_list|,
argument|QNetworkReply::NetworkError errorCode
argument_list|)
block|;
name|bool
name|handleAuthenticateChallenge
argument_list|(
argument|QAbstractSocket *socket
argument_list|,
argument|QHttpNetworkReply *reply
argument_list|,
argument|bool isProxy
argument_list|,
argument|bool&resend
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|QNetworkProxy
name|networkProxy
block|;
name|void
name|emitProxyAuthenticationRequired
argument_list|(
specifier|const
name|QHttpNetworkConnectionChannel
operator|*
name|chan
argument_list|,
specifier|const
name|QNetworkProxy
operator|&
name|proxy
argument_list|,
name|QAuthenticator
operator|*
name|auth
argument_list|)
block|;
endif|#
directive|endif
comment|//The request queues
name|QList
operator|<
name|HttpMessagePair
operator|>
name|highPriorityQueue
block|;
name|QList
operator|<
name|HttpMessagePair
operator|>
name|lowPriorityQueue
block|;
name|int
name|preConnectRequests
block|;
name|QHttpNetworkConnection
operator|::
name|ConnectionType
name|connectionType
block|;
ifndef|#
directive|ifndef
name|QT_NO_SSL
name|QSharedPointer
operator|<
name|QSslContext
operator|>
name|sslContext
block|;
endif|#
directive|endif
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
name|friend
name|class
name|QHttpNetworkConnectionChannel
block|; }
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
comment|// QT_NO_HTTP
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
