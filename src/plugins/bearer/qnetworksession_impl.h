begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKSESSION_IMPL_H
end_ifndef
begin_define
DECL|macro|QNETWORKSESSION_IMPL_H
define|#
directive|define
name|QNETWORKSESSION_IMPL_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|"qbearerengine_impl.h"
end_include
begin_include
include|#
directive|include
file|<QtNetwork/private/qnetworkconfigmanager_p.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/private/qnetworksession_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QBearerEngineImpl
name|class
name|QBearerEngineImpl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkSessionPrivateImpl
range|:
name|public
name|QNetworkSessionPrivate
block|{
name|Q_OBJECT
name|public
operator|:
name|QNetworkSessionPrivateImpl
argument_list|()
operator|:
name|engine
argument_list|(
literal|0
argument_list|)
block|,
name|startTime
argument_list|(
literal|0
argument_list|)
block|,
name|lastError
argument_list|(
name|QNetworkSession
operator|::
name|UnknownSessionError
argument_list|)
block|,
name|sessionTimeout
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|currentPolicies
argument_list|(
name|QNetworkSession
operator|::
name|NoPolicy
argument_list|)
block|,
name|opened
argument_list|(
argument|false
argument_list|)
block|{}
operator|~
name|QNetworkSessionPrivateImpl
argument_list|()
block|{}
comment|//called by QNetworkSession constructor and ensures
comment|//that the state is immediately updated (w/o actually opening
comment|//a session). Also this function should take care of
comment|//notification hooks to discover future state changes.
name|void
name|syncStateWithInterface
argument_list|()
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
name|QNetworkInterface
name|currentInterface
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|QVariant
name|sessionProperty
argument_list|(
argument|const QString& key
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setSessionProperty
argument_list|(
argument|const QString& key
argument_list|,
argument|const QVariant& value
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|open
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|close
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|stop
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|migrate
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|accept
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|ignore
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|reject
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QString
name|errorString
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
comment|//must return translated string
name|QNetworkSession
operator|::
name|SessionError
name|error
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|quint64
name|bytesWritten
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|quint64
name|bytesReceived
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|quint64
name|activeTime
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QNetworkSession
operator|::
name|UsagePolicies
name|usagePolicies
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setUsagePolicies
argument_list|(
argument|QNetworkSession::UsagePolicies
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|networkConfigurationsChanged
argument_list|()
block|;
name|void
name|configurationChanged
argument_list|(
argument|QNetworkConfigurationPrivatePointer config
argument_list|)
block|;
name|void
name|forcedSessionClose
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
name|config
argument_list|)
block|;
name|void
name|connectionError
argument_list|(
argument|const QString&id
argument_list|,
argument|QBearerEngineImpl::ConnectionError error
argument_list|)
block|;
name|void
name|decrementTimeout
argument_list|()
block|;
name|private
operator|:
name|void
name|updateStateFromServiceNetwork
argument_list|()
block|;
name|void
name|updateStateFromActiveConfig
argument_list|()
block|;
name|private
operator|:
name|QBearerEngineImpl
operator|*
name|engine
block|;
name|quint64
name|startTime
block|;
name|QNetworkSession
operator|::
name|SessionError
name|lastError
block|;
name|int
name|sessionTimeout
block|;
name|QNetworkSession
operator|::
name|UsagePolicies
name|currentPolicies
block|;
name|bool
name|opened
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
comment|// QNETWORKSESSION_IMPL_H
end_comment
end_unit
