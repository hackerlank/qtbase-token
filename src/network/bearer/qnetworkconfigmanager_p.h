begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKCONFIGURATIONMANAGERPRIVATE_H
end_ifndef
begin_define
DECL|macro|QNETWORKCONFIGURATIONMANAGERPRIVATE_H
define|#
directive|define
name|QNETWORKCONFIGURATIONMANAGERPRIVATE_H
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
file|"qnetworkconfigmanager.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkconfiguration_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QBearerEngine
name|class
name|QBearerEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTimer
name|class
name|QTimer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QNetworkConfigurationManagerPrivate
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QNetworkConfigurationManagerPrivate
argument_list|()
block|;
name|virtual
operator|~
name|QNetworkConfigurationManagerPrivate
argument_list|()
block|;
name|QNetworkConfiguration
name|defaultConfiguration
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QNetworkConfiguration
operator|>
name|allConfigurations
argument_list|(
argument|QNetworkConfiguration::StateFlags filter
argument_list|)
specifier|const
block|;
name|QNetworkConfiguration
name|configurationFromIdentifier
argument_list|(
argument|const QString&identifier
argument_list|)
specifier|const
block|;
name|bool
name|isOnline
argument_list|()
specifier|const
block|;
name|QNetworkConfigurationManager
operator|::
name|Capabilities
name|capabilities
argument_list|()
specifier|const
block|;
name|void
name|performAsyncConfigurationUpdate
argument_list|()
block|;
name|QList
operator|<
name|QBearerEngine
operator|*
operator|>
name|engines
argument_list|()
specifier|const
block|;
name|void
name|enablePolling
argument_list|()
block|;
name|void
name|disablePolling
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|updateConfigurations
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|configurationAdded
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
name|config
argument_list|)
block|;
name|void
name|configurationRemoved
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
name|config
argument_list|)
block|;
name|void
name|configurationChanged
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
name|config
argument_list|)
block|;
name|void
name|configurationUpdateComplete
argument_list|()
block|;
name|void
name|onlineStateChanged
argument_list|(
argument|bool isOnline
argument_list|)
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|configurationAdded
argument_list|(
argument|QNetworkConfigurationPrivatePointer ptr
argument_list|)
block|;
name|void
name|configurationRemoved
argument_list|(
argument|QNetworkConfigurationPrivatePointer ptr
argument_list|)
block|;
name|void
name|configurationChanged
argument_list|(
argument|QNetworkConfigurationPrivatePointer ptr
argument_list|)
block|;
name|void
name|pollEngines
argument_list|()
block|;
name|private
operator|:
name|Q_INVOKABLE
name|void
name|startPolling
argument_list|()
block|;
name|QTimer
operator|*
name|pollTimer
block|;
name|private
operator|:
name|mutable
name|QMutex
name|mutex
block|;
name|QList
operator|<
name|QBearerEngine
operator|*
operator|>
name|sessionEngines
block|;
name|QSet
operator|<
name|QString
operator|>
name|onlineConfigurations
block|;
name|QSet
operator|<
name|QBearerEngine
operator|*
operator|>
name|pollingEngines
block|;
name|QSet
operator|<
name|QBearerEngine
operator|*
operator|>
name|updatingEngines
block|;
name|int
name|forcedPolling
block|;
name|bool
name|updating
block|;
name|bool
name|firstUpdate
block|; }
decl_stmt|;
end_decl_stmt
begin_function_decl
name|Q_NETWORK_EXPORT
name|QNetworkConfigurationManagerPrivate
modifier|*
name|qNetworkConfigurationManagerPrivate
parameter_list|()
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_BEARERMANAGEMENT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QNETWORKCONFIGURATIONMANAGERPRIVATE_H
end_comment
end_unit
