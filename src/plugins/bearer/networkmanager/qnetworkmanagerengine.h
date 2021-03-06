begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKMANAGERENGINE_P_H
end_ifndef
begin_define
DECL|macro|QNETWORKMANAGERENGINE_P_H
define|#
directive|define
name|QNETWORKMANAGERENGINE_P_H
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
begin_include
include|#
directive|include
file|"../qbearerengine_impl.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkmanagerservice.h"
end_include
begin_include
include|#
directive|include
file|"../linux_common/qofonoservice_linux_p.h"
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QNetworkManagerEngine
range|:
name|public
name|QBearerEngineImpl
block|{
name|Q_OBJECT
name|public
operator|:
name|QNetworkManagerEngine
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QNetworkManagerEngine
argument_list|()
block|;
name|bool
name|networkManagerAvailable
argument_list|()
specifier|const
block|;
name|QString
name|getInterfaceFromId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|bool
name|hasIdentifier
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|void
name|connectToId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|void
name|disconnectFromId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|Q_INVOKABLE
name|void
name|initialize
argument_list|()
block|;
name|Q_INVOKABLE
name|void
name|requestUpdate
argument_list|()
block|;
name|QNetworkSession
operator|::
name|State
name|sessionStateForId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|quint64
name|bytesWritten
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|quint64
name|bytesReceived
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|quint64
name|startTime
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|QNetworkConfigurationManager
operator|::
name|Capabilities
name|capabilities
argument_list|()
specifier|const
block|;
name|QNetworkSessionPrivate
operator|*
name|createSessionBackend
argument_list|()
block|;
name|QNetworkConfigurationPrivatePointer
name|defaultConfiguration
argument_list|()
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|interfacePropertiesChanged
argument_list|(
specifier|const
name|QMap
operator|<
name|QString
argument_list|,
name|QVariant
operator|>
operator|&
name|properties
argument_list|)
block|;
name|void
name|activeConnectionPropertiesChanged
argument_list|(
specifier|const
name|QMap
operator|<
name|QString
argument_list|,
name|QVariant
operator|>
operator|&
name|properties
argument_list|)
block|;
name|void
name|deviceAdded
argument_list|(
specifier|const
name|QDBusObjectPath
operator|&
name|path
argument_list|)
block|;
name|void
name|deviceRemoved
argument_list|(
specifier|const
name|QDBusObjectPath
operator|&
name|path
argument_list|)
block|;
name|void
name|newConnection
argument_list|(
specifier|const
name|QDBusObjectPath
operator|&
name|path
argument_list|,
name|QNetworkManagerSettings
operator|*
name|settings
operator|=
literal|0
argument_list|)
block|;
name|void
name|removeConnection
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|void
name|updateConnection
argument_list|()
block|;
name|void
name|activationFinished
argument_list|(
name|QDBusPendingCallWatcher
operator|*
name|watcher
argument_list|)
block|;
name|void
name|deviceConnectionsChanged
argument_list|(
specifier|const
name|QStringList
operator|&
name|activeConnectionsList
argument_list|)
block|;
name|void
name|newAccessPoint
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|void
name|removeAccessPoint
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|void
name|scanFinished
argument_list|()
block|;
name|void
name|wiredCarrierChanged
argument_list|(
name|bool
argument_list|)
block|;
name|void
name|nmRegistered
argument_list|(
specifier|const
name|QString
operator|&
name|serviceName
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|void
name|nmUnRegistered
argument_list|(
specifier|const
name|QString
operator|&
name|serviceName
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|void
name|ofonoRegistered
argument_list|(
specifier|const
name|QString
operator|&
name|serviceName
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|void
name|ofonoUnRegistered
argument_list|(
specifier|const
name|QString
operator|&
name|serviceName
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|private
operator|:
name|QNetworkConfigurationPrivate
operator|*
name|parseConnection
argument_list|(
specifier|const
name|QString
operator|&
name|settingsPath
argument_list|,
specifier|const
name|QNmSettingsMap
operator|&
name|map
argument_list|)
block|;
name|QNetworkManagerSettingsConnection
operator|*
name|connectionFromId
argument_list|(
argument|const QString&id
argument_list|)
specifier|const
block|;
name|QNetworkManagerInterface
operator|*
name|managerInterface
block|;
name|QNetworkManagerSettings
operator|*
name|systemSettings
block|;
name|QHash
operator|<
name|QString
block|,
name|QNetworkManagerInterfaceDeviceWired
operator|*
operator|>
name|wiredDevices
block|;
name|QHash
operator|<
name|QString
block|,
name|QNetworkManagerInterfaceDeviceWireless
operator|*
operator|>
name|wirelessDevices
block|;
name|QHash
operator|<
name|QString
block|,
name|QNetworkManagerConnectionActive
operator|*
operator|>
name|activeConnectionsList
block|;
name|QList
operator|<
name|QNetworkManagerSettingsConnection
operator|*
operator|>
name|connections
block|;
name|QList
operator|<
name|QNetworkManagerInterfaceAccessPoint
operator|*
operator|>
name|accessPoints
block|;
name|QHash
operator|<
name|QString
block|,
name|QNetworkManagerInterfaceDevice
operator|*
operator|>
name|interfaceDevices
block|;
name|QMap
operator|<
name|QString
block|,
name|QString
operator|>
name|configuredAccessPoints
block|;
comment|//ap, settings path
name|QHash
operator|<
name|QString
block|,
name|QString
operator|>
name|connectionInterfaces
block|;
comment|// ac, interface
name|QOfonoManagerInterface
operator|*
name|ofonoManager
block|;
name|QHash
operator|<
name|QString
block|,
name|QOfonoDataConnectionManagerInterface
operator|*
operator|>
name|ofonoContextManagers
block|;
name|QNetworkConfiguration
operator|::
name|BearerType
name|currentBearerType
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|QString
name|contextName
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|bool
name|isConnectionActive
argument_list|(
specifier|const
name|QString
operator|&
name|settingsPath
argument_list|)
block|;
name|QDBusServiceWatcher
operator|*
name|ofonoWatcher
block|;
name|QDBusServiceWatcher
operator|*
name|nmWatcher
block|;
name|bool
name|isActiveContext
argument_list|(
specifier|const
name|QString
operator|&
name|contextPath
argument_list|)
block|;
name|bool
name|nmAvailable
block|;
name|void
name|setupConfigurations
argument_list|()
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
comment|// QT_NO_DBUS
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
