begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qandroidbearerengine.h"
end_include
begin_include
include|#
directive|include
file|"../../qnetworksession_impl.h"
end_include
begin_include
include|#
directive|include
file|"wrappers/androidconnectivitymanager.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|networkConfType
specifier|static
name|QString
name|networkConfType
parameter_list|(
specifier|const
name|AndroidNetworkInfo
modifier|&
name|networkInfo
parameter_list|)
block|{
switch|switch
condition|(
name|networkInfo
operator|.
name|getType
argument_list|()
condition|)
block|{
case|case
name|AndroidNetworkInfo
operator|::
name|Mobile
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"Mobile"
argument_list|)
return|;
case|case
name|AndroidNetworkInfo
operator|::
name|Wifi
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"WiFi"
argument_list|)
return|;
case|case
name|AndroidNetworkInfo
operator|::
name|Wimax
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"WiMax"
argument_list|)
return|;
case|case
name|AndroidNetworkInfo
operator|::
name|Ethernet
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"Ethernet"
argument_list|)
return|;
case|case
name|AndroidNetworkInfo
operator|::
name|Bluetooth
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"Bluetooth"
argument_list|)
return|;
default|default:
break|break;
block|}
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isMobile
specifier|static
specifier|inline
name|bool
name|isMobile
parameter_list|(
name|QNetworkConfiguration
operator|::
name|BearerType
name|type
parameter_list|)
block|{
if|if
condition|(
name|type
operator|==
name|QNetworkConfiguration
operator|::
name|BearerWLAN
operator|||
name|type
operator|==
name|QNetworkConfiguration
operator|::
name|BearerWiMAX
operator|||
name|type
operator|==
name|QNetworkConfiguration
operator|::
name|BearerBluetooth
operator|||
name|type
operator|==
name|QNetworkConfiguration
operator|::
name|BearerEthernet
operator|||
name|type
operator|==
name|QNetworkConfiguration
operator|::
name|BearerUnknown
condition|)
block|{
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|getBearerType
specifier|static
name|QNetworkConfiguration
operator|::
name|BearerType
name|getBearerType
parameter_list|(
specifier|const
name|AndroidNetworkInfo
modifier|&
name|networkInfo
parameter_list|)
block|{
switch|switch
condition|(
name|networkInfo
operator|.
name|getType
argument_list|()
condition|)
block|{
case|case
name|AndroidNetworkInfo
operator|::
name|Mobile
case|:
block|{
switch|switch
condition|(
name|networkInfo
operator|.
name|getSubtype
argument_list|()
condition|)
block|{
case|case
name|AndroidNetworkInfo
operator|::
name|Gprs
case|:
case|case
name|AndroidNetworkInfo
operator|::
name|Edge
case|:
case|case
name|AndroidNetworkInfo
operator|::
name|Iden
case|:
comment|// 2G
return|return
name|QNetworkConfiguration
operator|::
name|Bearer2G
return|;
case|case
name|AndroidNetworkInfo
operator|::
name|Umts
case|:
comment|// BearerWCDMA (3 .5 .75 G)
case|case
name|AndroidNetworkInfo
operator|::
name|Hsdpa
case|:
comment|// 3G (?) UMTS
case|case
name|AndroidNetworkInfo
operator|::
name|Hsupa
case|:
comment|// 3G (?) UMTS
return|return
name|QNetworkConfiguration
operator|::
name|BearerWCDMA
return|;
case|case
name|AndroidNetworkInfo
operator|::
name|Cdma
case|:
comment|// CDMA ISA95[AB]
case|case
name|AndroidNetworkInfo
operator|::
name|Cdma1xRTT
case|:
comment|// BearerCDMA2000 (3G)
case|case
name|AndroidNetworkInfo
operator|::
name|Ehrpd
case|:
comment|// CDMA Bridge thing?!?
return|return
name|QNetworkConfiguration
operator|::
name|BearerCDMA2000
return|;
case|case
name|AndroidNetworkInfo
operator|::
name|Evdo0
case|:
comment|// BearerEVDO
case|case
name|AndroidNetworkInfo
operator|::
name|EvdoA
case|:
comment|// BearerEVDO
case|case
name|AndroidNetworkInfo
operator|::
name|EvdoB
case|:
comment|// BearerEVDO
return|return
name|QNetworkConfiguration
operator|::
name|BearerEVDO
return|;
case|case
name|AndroidNetworkInfo
operator|::
name|Hspa
case|:
case|case
name|AndroidNetworkInfo
operator|::
name|Hspap
case|:
comment|// HSPA+
return|return
name|QNetworkConfiguration
operator|::
name|BearerHSPA
return|;
case|case
name|AndroidNetworkInfo
operator|::
name|Lte
case|:
comment|// BearerLTE (4G)
return|return
name|QNetworkConfiguration
operator|::
name|BearerLTE
return|;
default|default:
break|break;
block|}
block|}
case|case
name|AndroidNetworkInfo
operator|::
name|Wifi
case|:
return|return
name|QNetworkConfiguration
operator|::
name|BearerWLAN
return|;
case|case
name|AndroidNetworkInfo
operator|::
name|Wimax
case|:
return|return
name|QNetworkConfiguration
operator|::
name|BearerWiMAX
return|;
case|case
name|AndroidNetworkInfo
operator|::
name|Bluetooth
case|:
case|case
name|AndroidNetworkInfo
operator|::
name|MobileDun
case|:
return|return
name|QNetworkConfiguration
operator|::
name|BearerBluetooth
return|;
case|case
name|AndroidNetworkInfo
operator|::
name|Ethernet
case|:
return|return
name|QNetworkConfiguration
operator|::
name|BearerEthernet
return|;
case|case
name|AndroidNetworkInfo
operator|::
name|MobileMms
case|:
case|case
name|AndroidNetworkInfo
operator|::
name|MobileSupl
case|:
case|case
name|AndroidNetworkInfo
operator|::
name|MobileHipri
case|:
case|case
name|AndroidNetworkInfo
operator|::
name|Dummy
case|:
case|case
name|AndroidNetworkInfo
operator|::
name|UnknownType
case|:
break|break;
block|}
return|return
name|QNetworkConfiguration
operator|::
name|BearerUnknown
return|;
block|}
end_function
begin_constructor
DECL|function|QAndroidBearerEngine
name|QAndroidBearerEngine
operator|::
name|QAndroidBearerEngine
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QBearerEngineImpl
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_connectivityManager
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QAndroidBearerEngine
name|QAndroidBearerEngine
operator|::
name|~
name|QAndroidBearerEngine
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|getInterfaceFromId
name|QString
name|QAndroidBearerEngine
operator|::
name|getInterfaceFromId
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
block|{
specifier|const
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
return|return
name|m_configurationInterface
operator|.
name|value
argument_list|(
name|id
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|hasIdentifier
name|bool
name|QAndroidBearerEngine
operator|::
name|hasIdentifier
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
block|{
specifier|const
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
return|return
name|m_configurationInterface
operator|.
name|contains
argument_list|(
name|id
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|connectToId
name|void
name|QAndroidBearerEngine
operator|::
name|connectToId
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
block|{
name|Q_EMIT
name|connectionError
argument_list|(
name|id
argument_list|,
name|OperationNotSupported
argument_list|)
decl_stmt|;
block|}
end_function
begin_function
DECL|function|disconnectFromId
name|void
name|QAndroidBearerEngine
operator|::
name|disconnectFromId
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
block|{
name|Q_EMIT
name|connectionError
argument_list|(
name|id
argument_list|,
name|OperationNotSupported
argument_list|)
decl_stmt|;
block|}
end_function
begin_function
DECL|function|sessionStateForId
name|QNetworkSession
operator|::
name|State
name|QAndroidBearerEngine
operator|::
name|sessionStateForId
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
block|{
specifier|const
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|QNetworkConfigurationPrivatePointer
name|ptr
init|=
name|accessPointConfigurations
operator|.
name|value
argument_list|(
name|id
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
operator|!
name|ptr
operator|||
operator|!
name|ptr
operator|->
name|isValid
operator|)
operator|||
name|m_connectivityManager
operator|==
literal|0
condition|)
return|return
name|QNetworkSession
operator|::
name|Invalid
return|;
specifier|const
name|QMutexLocker
name|configLocker
argument_list|(
operator|&
name|ptr
operator|->
name|mutex
argument_list|)
decl_stmt|;
comment|// Don't re-order...
if|if
condition|(
operator|(
name|ptr
operator|->
name|state
operator|&
name|QNetworkConfiguration
operator|::
name|Active
operator|)
operator|==
name|QNetworkConfiguration
operator|::
name|Active
condition|)
block|{
return|return
name|QNetworkSession
operator|::
name|Connected
return|;
block|}
elseif|else
if|if
condition|(
operator|(
name|ptr
operator|->
name|state
operator|&
name|QNetworkConfiguration
operator|::
name|Discovered
operator|)
operator|==
name|QNetworkConfiguration
operator|::
name|Discovered
condition|)
block|{
return|return
name|QNetworkSession
operator|::
name|Disconnected
return|;
block|}
elseif|else
if|if
condition|(
operator|(
name|ptr
operator|->
name|state
operator|&
name|QNetworkConfiguration
operator|::
name|Defined
operator|)
operator|==
name|QNetworkConfiguration
operator|::
name|Defined
condition|)
block|{
return|return
name|QNetworkSession
operator|::
name|NotAvailable
return|;
block|}
elseif|else
if|if
condition|(
operator|(
name|ptr
operator|->
name|state
operator|&
name|QNetworkConfiguration
operator|::
name|Undefined
operator|)
operator|==
name|QNetworkConfiguration
operator|::
name|Undefined
condition|)
block|{
return|return
name|QNetworkSession
operator|::
name|NotAvailable
return|;
block|}
return|return
name|QNetworkSession
operator|::
name|Invalid
return|;
block|}
end_function
begin_function
DECL|function|capabilities
name|QNetworkConfigurationManager
operator|::
name|Capabilities
name|QAndroidBearerEngine
operator|::
name|capabilities
parameter_list|()
specifier|const
block|{
return|return
name|AndroidTrafficStats
operator|::
name|isTrafficStatsSupported
argument_list|()
condition|?
name|QNetworkConfigurationManager
operator|::
name|ForcedRoaming
operator||
name|QNetworkConfigurationManager
operator|::
name|DataStatistics
else|:
name|QNetworkConfigurationManager
operator|::
name|ForcedRoaming
return|;
block|}
end_function
begin_function
DECL|function|createSessionBackend
name|QNetworkSessionPrivate
modifier|*
name|QAndroidBearerEngine
operator|::
name|createSessionBackend
parameter_list|()
block|{
return|return
operator|new
name|QNetworkSessionPrivateImpl
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|defaultConfiguration
name|QNetworkConfigurationPrivatePointer
name|QAndroidBearerEngine
operator|::
name|defaultConfiguration
parameter_list|()
block|{
return|return
name|QNetworkConfigurationPrivatePointer
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|requiresPolling
name|bool
name|QAndroidBearerEngine
operator|::
name|requiresPolling
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|bytesWritten
name|quint64
name|QAndroidBearerEngine
operator|::
name|bytesWritten
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|QNetworkConfigurationPrivatePointer
name|ptr
init|=
name|accessPointConfigurations
operator|.
name|value
argument_list|(
name|id
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ptr
operator|||
operator|!
name|ptr
operator|->
name|isValid
condition|)
return|return
literal|0
return|;
return|return
name|isMobile
argument_list|(
name|ptr
operator|->
name|bearerType
argument_list|)
condition|?
name|AndroidTrafficStats
operator|::
name|getMobileTxBytes
argument_list|()
else|:
name|AndroidTrafficStats
operator|::
name|getTotalTxBytes
argument_list|()
operator|-
name|AndroidTrafficStats
operator|::
name|getMobileTxBytes
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|bytesReceived
name|quint64
name|QAndroidBearerEngine
operator|::
name|bytesReceived
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|QNetworkConfigurationPrivatePointer
name|ptr
init|=
name|accessPointConfigurations
operator|.
name|value
argument_list|(
name|id
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ptr
operator|||
operator|!
name|ptr
operator|->
name|isValid
condition|)
return|return
literal|0
return|;
return|return
name|isMobile
argument_list|(
name|ptr
operator|->
name|bearerType
argument_list|)
condition|?
name|AndroidTrafficStats
operator|::
name|getMobileRxBytes
argument_list|()
else|:
name|AndroidTrafficStats
operator|::
name|getTotalRxBytes
argument_list|()
operator|-
name|AndroidTrafficStats
operator|::
name|getMobileRxBytes
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|startTime
name|quint64
name|QAndroidBearerEngine
operator|::
name|startTime
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|id
argument_list|)
expr_stmt|;
return|return
name|Q_UINT64_C
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|initialize
name|void
name|QAndroidBearerEngine
operator|::
name|initialize
parameter_list|()
block|{
if|if
condition|(
name|m_connectivityManager
operator|!=
literal|0
condition|)
return|return;
name|m_connectivityManager
operator|=
name|AndroidConnectivityManager
operator|::
name|getInstance
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_connectivityManager
operator|==
literal|0
condition|)
return|return;
name|updateConfigurations
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|m_connectivityManager
argument_list|,
operator|&
name|AndroidConnectivityManager
operator|::
name|activeNetworkChanged
argument_list|,
name|this
argument_list|,
operator|&
name|QAndroidBearerEngine
operator|::
name|updateConfigurations
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|requestUpdate
name|void
name|QAndroidBearerEngine
operator|::
name|requestUpdate
parameter_list|()
block|{
name|updateConfigurations
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateConfigurations
name|void
name|QAndroidBearerEngine
operator|::
name|updateConfigurations
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
if|if
condition|(
name|m_connectivityManager
operator|==
literal|0
condition|)
return|return;
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|QStringList
name|oldKeys
init|=
name|accessPointConfigurations
operator|.
name|keys
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QNetworkInterface
argument_list|>
name|interfaces
init|=
name|QNetworkInterface
operator|::
name|allInterfaces
argument_list|()
decl_stmt|;
if|if
condition|(
name|interfaces
operator|.
name|isEmpty
argument_list|()
condition|)
name|interfaces
operator|=
name|QNetworkInterface
operator|::
name|allInterfaces
argument_list|()
expr_stmt|;
comment|// Create a configuration for each of the main types (WiFi, Mobile, Bluetooth, WiMax, Ethernet)
foreach|foreach
control|(
specifier|const
name|AndroidNetworkInfo
modifier|&
name|netInfo
decl|,
name|m_connectivityManager
operator|->
name|getAllNetworkInfo
argument_list|()
control|)
block|{
if|if
condition|(
operator|!
name|netInfo
operator|.
name|isValid
argument_list|()
condition|)
continue|continue;
specifier|const
name|QString
name|name
init|=
name|networkConfType
argument_list|(
name|netInfo
argument_list|)
decl_stmt|;
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
continue|continue;
name|QNetworkConfiguration
operator|::
name|BearerType
name|bearerType
init|=
name|getBearerType
argument_list|(
name|netInfo
argument_list|)
decl_stmt|;
name|QString
name|interfaceName
decl_stmt|;
name|QNetworkConfiguration
operator|::
name|StateFlag
name|state
init|=
name|QNetworkConfiguration
operator|::
name|Defined
decl_stmt|;
if|if
condition|(
name|netInfo
operator|.
name|isAvailable
argument_list|()
condition|)
block|{
if|if
condition|(
name|netInfo
operator|.
name|isConnected
argument_list|()
condition|)
block|{
comment|// Attempt to map an interface to this configuration
while|while
condition|(
operator|!
name|interfaces
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QNetworkInterface
name|interface
init|=
name|interfaces
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
comment|// ignore loopback interface
if|if
condition|(
operator|!
name|interface
operator|.
name|isValid
argument_list|()
condition|)
continue|continue;
if|if
condition|(
name|interface
operator|.
name|flags
argument_list|()
operator|&
name|QNetworkInterface
operator|::
name|IsLoopBack
condition|)
continue|continue;
comment|// There is no way to get the interface from the NetworkInfo, so
comment|// look for an active interface...
if|if
condition|(
name|interface
operator|.
name|flags
argument_list|()
operator|&
name|QNetworkInterface
operator|::
name|IsRunning
operator|&&
operator|!
name|interface
operator|.
name|addressEntries
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|state
operator|=
name|QNetworkConfiguration
operator|::
name|Active
expr_stmt|;
name|interfaceName
operator|=
name|interface
operator|.
name|name
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
block|}
block|}
specifier|const
name|QString
name|key
init|=
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|"android:%1:%2"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|name
argument_list|)
operator|.
name|arg
argument_list|(
name|interfaceName
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|id
init|=
name|QString
operator|::
name|number
argument_list|(
name|qHash
argument_list|(
name|key
argument_list|)
argument_list|)
decl_stmt|;
name|m_configurationInterface
index|[
name|id
index|]
operator|=
name|interfaceName
expr_stmt|;
name|oldKeys
operator|.
name|removeAll
argument_list|(
name|id
argument_list|)
expr_stmt|;
if|if
condition|(
name|accessPointConfigurations
operator|.
name|contains
argument_list|(
name|id
argument_list|)
condition|)
block|{
name|QNetworkConfigurationPrivatePointer
name|ptr
init|=
name|accessPointConfigurations
operator|.
name|value
argument_list|(
name|id
argument_list|)
decl_stmt|;
name|bool
name|changed
init|=
literal|false
decl_stmt|;
block|{
specifier|const
name|QMutexLocker
name|confLocker
argument_list|(
operator|&
name|ptr
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ptr
operator|->
name|isValid
condition|)
block|{
name|ptr
operator|->
name|isValid
operator|=
literal|true
expr_stmt|;
name|changed
operator|=
literal|true
expr_stmt|;
block|}
comment|// Don't reset the bearer type to 'Unknown'
if|if
condition|(
name|ptr
operator|->
name|bearerType
operator|!=
name|QNetworkConfiguration
operator|::
name|BearerUnknown
operator|&&
name|ptr
operator|->
name|bearerType
operator|!=
name|bearerType
condition|)
block|{
name|ptr
operator|->
name|bearerType
operator|=
name|bearerType
expr_stmt|;
name|changed
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|ptr
operator|->
name|name
operator|!=
name|name
condition|)
block|{
name|ptr
operator|->
name|name
operator|=
name|name
expr_stmt|;
name|changed
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|ptr
operator|->
name|id
operator|!=
name|id
condition|)
block|{
name|ptr
operator|->
name|id
operator|=
name|id
expr_stmt|;
name|changed
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|ptr
operator|->
name|state
operator|!=
name|state
condition|)
block|{
name|ptr
operator|->
name|state
operator|=
name|state
expr_stmt|;
name|changed
operator|=
literal|true
expr_stmt|;
block|}
block|}
comment|// Unlock configuration
if|if
condition|(
name|changed
condition|)
block|{
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|Q_EMIT
name|configurationChanged
argument_list|(
name|ptr
argument_list|)
decl_stmt|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|QNetworkConfigurationPrivatePointer
name|ptr
argument_list|(
operator|new
name|QNetworkConfigurationPrivate
argument_list|)
decl_stmt|;
name|ptr
operator|->
name|name
operator|=
name|name
expr_stmt|;
name|ptr
operator|->
name|isValid
operator|=
literal|true
expr_stmt|;
name|ptr
operator|->
name|id
operator|=
name|id
expr_stmt|;
name|ptr
operator|->
name|state
operator|=
name|state
expr_stmt|;
name|ptr
operator|->
name|type
operator|=
name|QNetworkConfiguration
operator|::
name|InternetAccessPoint
expr_stmt|;
name|ptr
operator|->
name|bearerType
operator|=
name|bearerType
expr_stmt|;
name|accessPointConfigurations
operator|.
name|insert
argument_list|(
name|id
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|Q_EMIT
name|configurationAdded
argument_list|(
name|ptr
argument_list|)
decl_stmt|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
block|}
block|}
while|while
condition|(
operator|!
name|oldKeys
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QNetworkConfigurationPrivatePointer
name|ptr
init|=
name|accessPointConfigurations
operator|.
name|take
argument_list|(
name|oldKeys
operator|.
name|takeFirst
argument_list|()
argument_list|)
decl_stmt|;
name|m_configurationInterface
operator|.
name|remove
argument_list|(
name|ptr
operator|->
name|id
argument_list|)
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|Q_EMIT
name|configurationRemoved
argument_list|(
name|ptr
argument_list|)
decl_stmt|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
block|}
block|}
comment|// Unlock engine
endif|#
directive|endif
comment|// QT_NO_NETWORKINTERFACE
name|Q_EMIT
name|updateCompleted
argument_list|()
decl_stmt|;
block|}
end_function
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
end_unit
