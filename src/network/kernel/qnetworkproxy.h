begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKPROXY_H
end_ifndef
begin_define
DECL|macro|QNETWORKPROXY_H
define|#
directive|define
name|QNETWORKPROXY_H
end_define
begin_include
include|#
directive|include
file|<QtNetwork/qhostaddress.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkrequest.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QUrl
name|class
name|QUrl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkConfiguration
name|class
name|QNetworkConfiguration
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkProxyQueryPrivate
name|class
name|QNetworkProxyQueryPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QNetworkProxyQuery
block|{
name|public
label|:
enum|enum
name|QueryType
block|{
name|TcpSocket
block|,
name|UdpSocket
block|,
name|TcpServer
init|=
literal|100
block|,
name|UrlRequest
block|}
enum|;
name|QNetworkProxyQuery
argument_list|()
expr_stmt|;
name|explicit
name|QNetworkProxyQuery
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|requestUrl
parameter_list|,
name|QueryType
name|queryType
init|=
name|UrlRequest
parameter_list|)
function_decl|;
name|QNetworkProxyQuery
argument_list|(
argument|const QString&hostname
argument_list|,
argument|int port
argument_list|,
argument|const QString&protocolTag = QString()
argument_list|,
argument|QueryType queryType = TcpSocket
argument_list|)
empty_stmt|;
name|explicit
name|QNetworkProxyQuery
parameter_list|(
name|quint16
name|bindPort
parameter_list|,
specifier|const
name|QString
modifier|&
name|protocolTag
init|=
name|QString
argument_list|()
parameter_list|,
name|QueryType
name|queryType
init|=
name|TcpServer
parameter_list|)
function_decl|;
name|QNetworkProxyQuery
argument_list|(
specifier|const
name|QNetworkProxyQuery
operator|&
name|other
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|QNetworkProxyQuery
argument_list|(
argument|const QNetworkConfiguration&networkConfiguration
argument_list|,
argument|const QUrl&requestUrl
argument_list|,
argument|QueryType queryType = UrlRequest
argument_list|)
empty_stmt|;
name|QNetworkProxyQuery
argument_list|(
argument|const QNetworkConfiguration&networkConfiguration
argument_list|,
argument|const QString&hostname
argument_list|,
argument|int port
argument_list|,
argument|const QString&protocolTag = QString()
argument_list|,
argument|QueryType queryType = TcpSocket
argument_list|)
empty_stmt|;
name|QNetworkProxyQuery
argument_list|(
argument|const QNetworkConfiguration&networkConfiguration
argument_list|,
argument|quint16 bindPort
argument_list|,
argument|const QString&protocolTag = QString()
argument_list|,
argument|QueryType queryType = TcpServer
argument_list|)
empty_stmt|;
endif|#
directive|endif
operator|~
name|QNetworkProxyQuery
argument_list|()
expr_stmt|;
name|QNetworkProxyQuery
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QNetworkProxyQuery
operator|&
name|other
operator|)
decl_stmt|;
name|void
name|swap
parameter_list|(
name|QNetworkProxyQuery
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QNetworkProxyQuery
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QNetworkProxyQuery
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
name|QueryType
name|queryType
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setQueryType
parameter_list|(
name|QueryType
name|type
parameter_list|)
function_decl|;
name|int
name|peerPort
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPeerPort
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
name|QString
name|peerHostName
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPeerHostName
parameter_list|(
specifier|const
name|QString
modifier|&
name|hostname
parameter_list|)
function_decl|;
name|int
name|localPort
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLocalPort
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
name|QString
name|protocolTag
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setProtocolTag
parameter_list|(
specifier|const
name|QString
modifier|&
name|protocolTag
parameter_list|)
function_decl|;
name|QUrl
name|url
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|QNetworkConfiguration
name|networkConfiguration
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setNetworkConfiguration
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|networkConfiguration
parameter_list|)
function_decl|;
endif|#
directive|endif
name|private
label|:
name|QSharedDataPointer
operator|<
name|QNetworkProxyQueryPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QNetworkProxyQuery
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QNetworkProxyPrivate
name|class
name|QNetworkProxyPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QNetworkProxy
block|{
name|public
label|:
enum|enum
name|ProxyType
block|{
name|DefaultProxy
block|,
name|Socks5Proxy
block|,
name|NoProxy
block|,
name|HttpProxy
block|,
name|HttpCachingProxy
block|,
name|FtpCachingProxy
block|}
enum|;
enum|enum
name|Capability
block|{
name|TunnelingCapability
init|=
literal|0x0001
block|,
name|ListeningCapability
init|=
literal|0x0002
block|,
name|UdpTunnelingCapability
init|=
literal|0x0004
block|,
name|CachingCapability
init|=
literal|0x0008
block|,
name|HostNameLookupCapability
init|=
literal|0x0010
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|Capabilities
argument_list|,
argument|Capability
argument_list|)
name|QNetworkProxy
argument_list|()
expr_stmt|;
name|QNetworkProxy
argument_list|(
argument|ProxyType type
argument_list|,
argument|const QString&hostName = QString()
argument_list|,
argument|quint16 port =
literal|0
argument_list|,
argument|const QString&user = QString()
argument_list|,
argument|const QString&password = QString()
argument_list|)
empty_stmt|;
name|QNetworkProxy
argument_list|(
specifier|const
name|QNetworkProxy
operator|&
name|other
argument_list|)
expr_stmt|;
name|QNetworkProxy
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QNetworkProxy
operator|&
name|other
operator|)
decl_stmt|;
operator|~
name|QNetworkProxy
argument_list|()
expr_stmt|;
name|void
name|swap
parameter_list|(
name|QNetworkProxy
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QNetworkProxy
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QNetworkProxy
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
name|void
name|setType
argument_list|(
name|QNetworkProxy
operator|::
name|ProxyType
name|type
argument_list|)
decl_stmt|;
name|QNetworkProxy
operator|::
name|ProxyType
name|type
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCapabilities
parameter_list|(
name|Capabilities
name|capab
parameter_list|)
function_decl|;
name|Capabilities
name|capabilities
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isCachingProxy
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isTransparentProxy
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setUser
parameter_list|(
specifier|const
name|QString
modifier|&
name|userName
parameter_list|)
function_decl|;
name|QString
name|user
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPassword
parameter_list|(
specifier|const
name|QString
modifier|&
name|password
parameter_list|)
function_decl|;
name|QString
name|password
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setHostName
parameter_list|(
specifier|const
name|QString
modifier|&
name|hostName
parameter_list|)
function_decl|;
name|QString
name|hostName
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPort
parameter_list|(
name|quint16
name|port
parameter_list|)
function_decl|;
name|quint16
name|port
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|void
name|setApplicationProxy
parameter_list|(
specifier|const
name|QNetworkProxy
modifier|&
name|proxy
parameter_list|)
function_decl|;
specifier|static
name|QNetworkProxy
name|applicationProxy
parameter_list|()
function_decl|;
comment|// "cooked" headers
name|QVariant
name|header
argument_list|(
name|QNetworkRequest
operator|::
name|KnownHeaders
name|header
argument_list|)
decl|const
decl_stmt|;
name|void
name|setHeader
argument_list|(
name|QNetworkRequest
operator|::
name|KnownHeaders
name|header
argument_list|,
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
decl_stmt|;
comment|// raw headers:
name|bool
name|hasRawHeader
argument_list|(
specifier|const
name|QByteArray
operator|&
name|headerName
argument_list|)
decl|const
decl_stmt|;
name|QList
operator|<
name|QByteArray
operator|>
name|rawHeaderList
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|rawHeader
argument_list|(
specifier|const
name|QByteArray
operator|&
name|headerName
argument_list|)
decl|const
decl_stmt|;
name|void
name|setRawHeader
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|headerName
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
function_decl|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QNetworkProxyPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QNetworkProxy::Capabilities
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QNetworkProxyFactory
block|{
name|public
label|:
name|QNetworkProxyFactory
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QNetworkProxyFactory
argument_list|()
expr_stmt|;
name|virtual
name|QList
operator|<
name|QNetworkProxy
operator|>
name|queryProxy
argument_list|(
specifier|const
name|QNetworkProxyQuery
operator|&
name|query
operator|=
name|QNetworkProxyQuery
argument_list|()
argument_list|)
operator|=
literal|0
expr_stmt|;
specifier|static
name|void
name|setUseSystemConfiguration
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
specifier|static
name|void
name|setApplicationProxyFactory
parameter_list|(
name|QNetworkProxyFactory
modifier|*
name|factory
parameter_list|)
function_decl|;
specifier|static
name|QList
operator|<
name|QNetworkProxy
operator|>
name|proxyForQuery
argument_list|(
specifier|const
name|QNetworkProxyQuery
operator|&
name|query
argument_list|)
expr_stmt|;
specifier|static
name|QList
operator|<
name|QNetworkProxy
operator|>
name|systemProxyForQuery
argument_list|(
specifier|const
name|QNetworkProxyQuery
operator|&
name|query
operator|=
name|QNetworkProxyQuery
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_NETWORK_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QNetworkProxy
operator|&
name|proxy
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QNetworkProxy
argument_list|)
name|QT_END_HEADER
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_NETWORKPROXY
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QHOSTINFO_H
end_comment
end_unit
