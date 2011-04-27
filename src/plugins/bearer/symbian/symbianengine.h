begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SYMBIANENGINE_H
end_ifndef
begin_define
DECL|macro|SYMBIANENGINE_H
define|#
directive|define
name|SYMBIANENGINE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/private/qbearerengine_p.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkconfigmanager.h>
end_include
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_include
include|#
directive|include
file|<rconnmon.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|SNAP_FUNCTIONALITY_AVAILABLE
end_ifdef
begin_include
include|#
directive|include
file|<cmmanager.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Uncomment and compile QtBearer to gain detailed state tracing
end_comment
begin_comment
comment|// #define QT_BEARERMGMT_SYMBIAN_DEBUG
end_comment
begin_define
DECL|macro|QT_BEARERMGMT_CONFIGURATION_SNAP_PREFIX
define|#
directive|define
name|QT_BEARERMGMT_CONFIGURATION_SNAP_PREFIX
value|QLatin1String("S_")
end_define
begin_define
DECL|macro|QT_BEARERMGMT_CONFIGURATION_IAP_PREFIX
define|#
directive|define
name|QT_BEARERMGMT_CONFIGURATION_IAP_PREFIX
value|QLatin1String("I_")
end_define
begin_decl_stmt
DECL|variable|CCommsDatabase
name|class
name|CCommsDatabase
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEventLoop
name|class
name|QEventLoop
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTimer
name|class
name|QTimer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|QT_BEGIN_NAMESPACE
DECL|variable|QNetworkSessionPrivate
name|class
name|QNetworkSessionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|AccessPointsAvailabilityScanner
name|class
name|AccessPointsAvailabilityScanner
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|SymbianNetworkConfigurationPrivate
range|:
name|public
name|QNetworkConfigurationPrivate
block|{
name|public
operator|:
name|SymbianNetworkConfigurationPrivate
argument_list|()
block|;
operator|~
name|SymbianNetworkConfigurationPrivate
argument_list|()
block|;
specifier|inline
name|TUint32
name|numericIdentifier
argument_list|()
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
block|;
return|return
name|numericId
return|;
block|}
specifier|inline
name|TUint
name|connectionIdentifier
argument_list|()
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
block|;
return|return
name|connectionId
return|;
block|}
specifier|inline
name|QString
name|configMappingName
argument_list|()
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
block|;
return|return
name|mappingName
return|;
block|}
name|QString
name|mappingName
block|;
comment|// So called IAP id from the platform. Remains constant as long as the
comment|// platform is aware of the configuration ie. it is stored in the databases
comment|// --> does not depend on whether connections are currently open or not.
comment|// In practice is the same for the lifetime of the QNetworkConfiguration.
name|TUint32
name|numericId
block|;
comment|// So called connection id, or connection monitor ID. A dynamic ID assigned
comment|// by RConnectionMonitor whenever a new connection is opened. ConnectionID and
comment|// numericId/IAP id have 1-to-1 mapping during the lifetime of the connection at
comment|// connection monitor. Notably however it changes whenever a new connection to
comment|// a given IAP is created. In a sense it is constant during the time the
comment|// configuration remains between states Discovered..Active..Discovered, do not
comment|// however relay on this.
name|TUint
name|connectionId
block|; }
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|toSymbianConfig
specifier|inline
name|SymbianNetworkConfigurationPrivate
modifier|*
name|toSymbianConfig
parameter_list|(
name|QNetworkConfigurationPrivatePointer
name|ptr
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|SymbianNetworkConfigurationPrivate
operator|*
operator|>
operator|(
name|ptr
operator|.
name|data
argument_list|()
operator|)
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|QBearerEngine
DECL|variable|CActive
name|class
name|SymbianEngine
range|:
name|public
name|QBearerEngine
decl_stmt|,
name|public
name|CActive
decl_stmt|,
name|public
name|MConnectionMonitorObserver
block|{
name|Q_OBJECT
name|public
range|:
name|SymbianEngine
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
name|virtual
operator|~
name|SymbianEngine
argument_list|()
expr_stmt|;
name|bool
name|hasIdentifier
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
function_decl|;
name|Q_INVOKABLE
name|void
name|initialize
parameter_list|()
function_decl|;
name|Q_INVOKABLE
name|void
name|requestUpdate
parameter_list|()
function_decl|;
name|QNetworkConfigurationManager
operator|::
name|Capabilities
name|capabilities
argument_list|()
specifier|const
expr_stmt|;
name|QNetworkSessionPrivate
modifier|*
name|createSessionBackend
parameter_list|()
function_decl|;
name|QNetworkConfigurationPrivatePointer
name|defaultConfiguration
parameter_list|()
function_decl|;
name|QStringList
name|accessPointConfigurationIdentifiers
parameter_list|()
function_decl|;
name|QNetworkConfigurationPrivatePointer
name|configurationFromSsid
parameter_list|(
specifier|const
name|QString
modifier|&
name|ssid
parameter_list|)
function_decl|;
comment|// For QNetworkSessionPrivateImpl to indicate about state changes
name|void
name|configurationStateChangeReport
argument_list|(
name|TUint32
name|accessPointId
argument_list|,
name|QNetworkSession
operator|::
name|State
name|newState
argument_list|)
decl_stmt|;
name|Q_SIGNALS
label|:
name|void
name|onlineStateChanged
parameter_list|(
name|bool
name|isOnline
parameter_list|)
function_decl|;
name|void
name|configurationStateChanged
argument_list|(
name|quint32
name|accessPointId
argument_list|,
name|quint32
name|connMonId
argument_list|,
name|QNetworkSession
operator|::
name|State
name|newState
argument_list|)
decl_stmt|;
name|public
name|Q_SLOTS
range|:
name|void
name|updateConfigurations
argument_list|()
decl_stmt|;
name|void
name|delayedConfigurationUpdate
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|updateStatesToSnaps
parameter_list|()
function_decl|;
name|bool
name|changeConfigurationStateTo
argument_list|(
name|QNetworkConfigurationPrivatePointer
name|ptr
argument_list|,
name|QNetworkConfiguration
operator|::
name|StateFlags
name|newState
argument_list|)
decl_stmt|;
name|bool
name|changeConfigurationStateAtMinTo
argument_list|(
name|QNetworkConfigurationPrivatePointer
name|ptr
argument_list|,
name|QNetworkConfiguration
operator|::
name|StateFlags
name|newState
argument_list|)
decl_stmt|;
name|bool
name|changeConfigurationStateAtMaxTo
argument_list|(
name|QNetworkConfigurationPrivatePointer
name|ptr
argument_list|,
name|QNetworkConfiguration
operator|::
name|StateFlags
name|newState
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|SNAP_FUNCTIONALITY_AVAILABLE
name|void
name|updateMobileBearerToConfigs
parameter_list|(
name|TConnMonBearerInfo
name|bearerInfo
parameter_list|)
function_decl|;
name|SymbianNetworkConfigurationPrivate
modifier|*
name|configFromConnectionMethodL
parameter_list|(
name|RCmConnectionMethod
modifier|&
name|connectionMethod
parameter_list|)
function_decl|;
else|#
directive|else
name|bool
name|readNetworkConfigurationValuesFromCommsDb
parameter_list|(
name|TUint32
name|aApId
parameter_list|,
name|SymbianNetworkConfigurationPrivate
modifier|*
name|apNetworkConfiguration
parameter_list|)
function_decl|;
name|void
name|readNetworkConfigurationValuesFromCommsDbL
parameter_list|(
name|TUint32
name|aApId
parameter_list|,
name|SymbianNetworkConfigurationPrivate
modifier|*
name|apNetworkConfiguration
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
name|updateConfigurationsL
parameter_list|()
function_decl|;
name|void
name|updateActiveAccessPoints
parameter_list|()
function_decl|;
name|void
name|updateAvailableAccessPoints
parameter_list|()
function_decl|;
name|void
name|accessPointScanningReady
parameter_list|(
name|TBool
name|scanSuccessful
parameter_list|,
name|TConnMonIapInfo
name|iapInfo
parameter_list|)
function_decl|;
name|void
name|startCommsDatabaseNotifications
parameter_list|()
function_decl|;
name|void
name|stopCommsDatabaseNotifications
parameter_list|()
function_decl|;
name|void
name|updateConfigurationsAfterRandomTime
parameter_list|()
function_decl|;
name|QNetworkConfigurationPrivatePointer
name|defaultConfigurationL
parameter_list|()
function_decl|;
name|TBool
name|GetS60PlatformVersion
argument_list|(
name|TUint
operator|&
name|aMajor
argument_list|,
name|TUint
operator|&
name|aMinor
argument_list|)
decl|const
decl_stmt|;
name|void
name|startMonitoringIAPData
parameter_list|(
name|TUint32
name|aIapId
parameter_list|)
function_decl|;
name|QNetworkConfigurationPrivatePointer
name|dataByConnectionId
parameter_list|(
name|TUint
name|aConnectionId
parameter_list|)
function_decl|;
name|protected
label|:
comment|// From CActive
name|void
name|RunL
parameter_list|()
function_decl|;
name|void
name|DoCancel
parameter_list|()
function_decl|;
name|private
label|:
comment|// MConnectionMonitorObserver
name|void
name|EventL
parameter_list|(
specifier|const
name|CConnMonEventBase
modifier|&
name|aEvent
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|SNAP_FUNCTIONALITY_AVAILABLE
name|QNetworkConfigurationPrivatePointer
name|configurationFromEasyWlan
parameter_list|(
name|TUint32
name|apId
parameter_list|,
name|TUint
name|connectionId
parameter_list|)
function_decl|;
endif|#
directive|endif
name|private
label|:
comment|// Data
name|bool
name|iFirstUpdate
decl_stmt|;
name|CCommsDatabase
modifier|*
name|ipCommsDB
decl_stmt|;
name|RConnectionMonitor
name|iConnectionMonitor
decl_stmt|;
name|TBool
name|iWaitingCommsDatabaseNotifications
decl_stmt|;
name|TBool
name|iOnline
decl_stmt|;
name|TBool
name|iInitOk
decl_stmt|;
name|TBool
name|iUpdateGoingOn
decl_stmt|;
name|TBool
name|iUpdatePending
decl_stmt|;
name|TBool
name|iScanInQueue
decl_stmt|;
name|AccessPointsAvailabilityScanner
modifier|*
name|ipAccessPointsAvailabilityScanner
decl_stmt|;
name|QNetworkConfigurationPrivatePointer
name|defaultConfig
decl_stmt|;
name|friend
name|class
name|QNetworkSessionPrivate
decl_stmt|;
name|friend
name|class
name|AccessPointsAvailabilityScanner
decl_stmt|;
ifdef|#
directive|ifdef
name|SNAP_FUNCTIONALITY_AVAILABLE
name|RCmManager
name|iCmManager
decl_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|AccessPointsAvailabilityScanner
range|:
name|public
name|CActive
block|{
name|public
operator|:
name|AccessPointsAvailabilityScanner
argument_list|(
name|SymbianEngine
operator|&
name|owner
argument_list|,
name|RConnectionMonitor
operator|&
name|connectionMonitor
argument_list|)
block|;
operator|~
name|AccessPointsAvailabilityScanner
argument_list|()
block|;
name|void
name|StartScanning
argument_list|()
block|;
name|protected
operator|:
comment|// From CActive
name|void
name|RunL
argument_list|()
block|;
name|void
name|DoCancel
argument_list|()
block|;
name|private
operator|:
comment|// Data
name|SymbianEngine
operator|&
name|iOwner
block|;
name|RConnectionMonitor
operator|&
name|iConnectionMonitor
block|;
name|TConnMonIapInfoBuf
name|iIapBuf
block|;
name|TBool
name|iScanActive
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
end_unit
