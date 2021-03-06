begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2009 David Faure<dfaure@kdab.net> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKPROXY_P_H
end_ifndef
begin_define
DECL|macro|QNETWORKPROXY_P_H
define|#
directive|define
name|QNETWORKPROXY_P_H
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
comment|// of the QLibrary class.  This header file may change from
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
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QSystemConfigurationProxyFactory
range|:
name|public
name|QNetworkProxyFactory
block|{
name|public
operator|:
name|QSystemConfigurationProxyFactory
argument_list|()
operator|:
name|QNetworkProxyFactory
argument_list|()
block|{}
name|virtual
name|QList
operator|<
name|QNetworkProxy
operator|>
name|queryProxy
argument_list|(
argument|const QNetworkProxyQuery& query
argument_list|)
block|{
name|QList
operator|<
name|QNetworkProxy
operator|>
name|proxies
operator|=
name|QNetworkProxyFactory
operator|::
name|systemProxyForQuery
argument_list|(
name|query
argument_list|)
block|;
comment|// Make sure NoProxy is in the list, so that QTcpServer can work:
comment|// it searches for the first proxy that can has the ListeningCapability capability
comment|// if none have (as is the case with HTTP proxies), it fails to bind.
comment|// NoProxy allows it to fallback to the 'no proxy' case and bind.
name|proxies
operator|.
name|append
argument_list|(
name|QNetworkProxy
operator|::
name|NoProxy
argument_list|)
block|;
return|return
name|proxies
return|;
block|}
expr|}
block|;
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_NETWORKINTERFACE
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
