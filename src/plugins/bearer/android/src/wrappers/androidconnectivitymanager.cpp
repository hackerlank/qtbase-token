begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"androidconnectivitymanager.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qjni_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qjnihelpers_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|exceptionCheckAndClear
specifier|static
specifier|inline
name|bool
name|exceptionCheckAndClear
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|)
block|{
if|if
condition|(
operator|!
name|env
operator|->
name|ExceptionCheck
argument_list|()
condition|)
return|return
literal|false
return|;
ifdef|#
directive|ifdef
name|QT_DEBUG
name|env
operator|->
name|ExceptionDescribe
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|// QT_DEBUG
name|env
operator|->
name|ExceptionClear
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_struct
DECL|struct|AndroidConnectivityManagerInstance
struct|struct
name|AndroidConnectivityManagerInstance
block|{
DECL|function|AndroidConnectivityManagerInstance
name|AndroidConnectivityManagerInstance
parameter_list|()
member_init_list|:
name|connManager
argument_list|(
operator|new
name|AndroidConnectivityManager
argument_list|)
block|{    }
DECL|function|~AndroidConnectivityManagerInstance
name|~
name|AndroidConnectivityManagerInstance
parameter_list|()
block|{
operator|delete
name|connManager
expr_stmt|;
block|}
DECL|member|connManager
name|AndroidConnectivityManager
modifier|*
name|connManager
decl_stmt|;
block|}
struct|;
end_struct
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|AndroidConnectivityManagerInstance
argument_list|,
argument|androidConnManagerInstance
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|networkReceiverClass
specifier|static
specifier|const
name|char
name|networkReceiverClass
index|[]
init|=
literal|"org/qtproject/qt5/android/bearer/QtNetworkReceiver"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|trafficStatsClass
specifier|static
specifier|const
name|char
name|trafficStatsClass
index|[]
init|=
literal|"android/net/TrafficStats"
decl_stmt|;
end_decl_stmt
begin_comment
comment|/**  * Returns the number of bytes transmitted over the mobile network since last device boot.  */
end_comment
begin_function
DECL|function|getMobileTxBytes
name|qint64
name|AndroidTrafficStats
operator|::
name|getMobileTxBytes
parameter_list|()
block|{
return|return
name|QJNIObjectPrivate
operator|::
name|callStaticMethod
argument_list|<
name|jlong
argument_list|>
argument_list|(
name|trafficStatsClass
argument_list|,
literal|"getMobileTxBytes"
argument_list|,
literal|"()J"
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/**  * Returns the number of bytes received over the mobile network since last device boot.  */
end_comment
begin_function
DECL|function|getMobileRxBytes
name|qint64
name|AndroidTrafficStats
operator|::
name|getMobileRxBytes
parameter_list|()
block|{
return|return
name|QJNIObjectPrivate
operator|::
name|callStaticMethod
argument_list|<
name|jlong
argument_list|>
argument_list|(
name|trafficStatsClass
argument_list|,
literal|"getMobileRxBytes"
argument_list|,
literal|"()J"
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/**  * Returns the total transmitted bytes since last device boot.  */
end_comment
begin_function
DECL|function|getTotalTxBytes
name|qint64
name|AndroidTrafficStats
operator|::
name|getTotalTxBytes
parameter_list|()
block|{
return|return
name|QJNIObjectPrivate
operator|::
name|callStaticMethod
argument_list|<
name|jlong
argument_list|>
argument_list|(
name|trafficStatsClass
argument_list|,
literal|"getTotalTxBytes"
argument_list|,
literal|"()J"
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/**  * Returns the total received bytes since last device boot.  */
end_comment
begin_function
DECL|function|getTotalRxBytes
name|qint64
name|AndroidTrafficStats
operator|::
name|getTotalRxBytes
parameter_list|()
block|{
return|return
name|QJNIObjectPrivate
operator|::
name|callStaticMethod
argument_list|<
name|jlong
argument_list|>
argument_list|(
name|trafficStatsClass
argument_list|,
literal|"getTotalRxBytes"
argument_list|,
literal|"()J"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isTrafficStatsSupported
name|bool
name|AndroidTrafficStats
operator|::
name|isTrafficStatsSupported
parameter_list|()
block|{
comment|// Before API level 18 DataStatistics might not be supported, so make sure that we get something
comment|// else then -1 from from getXXBytes().
return|return
operator|(
name|AndroidTrafficStats
operator|::
name|getMobileRxBytes
argument_list|()
operator|!=
operator|-
literal|1
operator|&&
name|AndroidTrafficStats
operator|::
name|getTotalRxBytes
argument_list|()
operator|!=
operator|-
literal|1
operator|)
return|;
block|}
end_function
begin_function
DECL|function|stateForName
specifier|static
name|AndroidNetworkInfo
operator|::
name|NetworkState
name|stateForName
parameter_list|(
specifier|const
name|QString
modifier|&
name|stateName
parameter_list|)
block|{
if|if
condition|(
name|stateName
operator|==
name|QLatin1String
argument_list|(
literal|"CONNECTED"
argument_list|)
condition|)
return|return
name|AndroidNetworkInfo
operator|::
name|Connected
return|;
elseif|else
if|if
condition|(
name|stateName
operator|==
name|QLatin1String
argument_list|(
literal|"CONNECTING"
argument_list|)
condition|)
return|return
name|AndroidNetworkInfo
operator|::
name|Connecting
return|;
elseif|else
if|if
condition|(
name|stateName
operator|==
name|QLatin1String
argument_list|(
literal|"DISCONNECTED"
argument_list|)
condition|)
return|return
name|AndroidNetworkInfo
operator|::
name|Disconnected
return|;
elseif|else
if|if
condition|(
name|stateName
operator|==
name|QLatin1String
argument_list|(
literal|"DISCONNECTING"
argument_list|)
condition|)
return|return
name|AndroidNetworkInfo
operator|::
name|Disconnecting
return|;
elseif|else
if|if
condition|(
name|stateName
operator|==
name|QLatin1String
argument_list|(
literal|"SUSPENDED"
argument_list|)
condition|)
return|return
name|AndroidNetworkInfo
operator|::
name|Suspended
return|;
return|return
name|AndroidNetworkInfo
operator|::
name|UnknownState
return|;
block|}
end_function
begin_function
DECL|function|getDetailedState
name|AndroidNetworkInfo
operator|::
name|NetworkState
name|AndroidNetworkInfo
operator|::
name|getDetailedState
parameter_list|()
specifier|const
block|{
name|QJNIObjectPrivate
name|enumObject
init|=
name|m_networkInfo
operator|.
name|callObjectMethod
argument_list|(
literal|"getDetailedState"
argument_list|,
literal|"()Landroid/net/NetworkInfo$DetailedState;"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|enumObject
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|UnknownState
return|;
name|QJNIObjectPrivate
name|enumName
init|=
name|enumObject
operator|.
name|callObjectMethod
argument_list|<
name|jstring
argument_list|>
argument_list|(
literal|"name"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|enumName
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|UnknownState
return|;
return|return
name|stateForName
argument_list|(
name|enumName
operator|.
name|toString
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|getExtraInfo
name|QString
name|AndroidNetworkInfo
operator|::
name|getExtraInfo
parameter_list|()
specifier|const
block|{
name|QJNIObjectPrivate
name|extraInfo
init|=
name|m_networkInfo
operator|.
name|callObjectMethod
argument_list|<
name|jstring
argument_list|>
argument_list|(
literal|"getExtraInfo"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|extraInfo
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|extraInfo
operator|.
name|toString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|getReason
name|QString
name|AndroidNetworkInfo
operator|::
name|getReason
parameter_list|()
specifier|const
block|{
name|QJNIObjectPrivate
name|reason
init|=
name|m_networkInfo
operator|.
name|callObjectMethod
argument_list|<
name|jstring
argument_list|>
argument_list|(
literal|"getReason"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|reason
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|reason
operator|.
name|toString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|getState
name|AndroidNetworkInfo
operator|::
name|NetworkState
name|AndroidNetworkInfo
operator|::
name|getState
parameter_list|()
specifier|const
block|{
name|QJNIObjectPrivate
name|enumObject
init|=
name|m_networkInfo
operator|.
name|callObjectMethod
argument_list|(
literal|"getState"
argument_list|,
literal|"()Landroid/net/NetworkInfo$State;"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|enumObject
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|UnknownState
return|;
name|QJNIObjectPrivate
name|enumName
init|=
name|enumObject
operator|.
name|callObjectMethod
argument_list|<
name|jstring
argument_list|>
argument_list|(
literal|"name"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|enumName
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|UnknownState
return|;
return|return
name|stateForName
argument_list|(
name|enumName
operator|.
name|toString
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|getSubtype
name|AndroidNetworkInfo
operator|::
name|NetworkSubType
name|AndroidNetworkInfo
operator|::
name|getSubtype
parameter_list|()
specifier|const
block|{
return|return
name|AndroidNetworkInfo
operator|::
name|NetworkSubType
argument_list|(
name|m_networkInfo
operator|.
name|callMethod
argument_list|<
name|jint
argument_list|>
argument_list|(
literal|"getSubtype"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|getSubtypeName
name|QString
name|AndroidNetworkInfo
operator|::
name|getSubtypeName
parameter_list|()
specifier|const
block|{
name|QJNIObjectPrivate
name|subtypeName
init|=
name|m_networkInfo
operator|.
name|callObjectMethod
argument_list|<
name|jstring
argument_list|>
argument_list|(
literal|"getSubtypeName"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|subtypeName
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|subtypeName
operator|.
name|toString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|getType
name|AndroidNetworkInfo
operator|::
name|NetworkType
name|AndroidNetworkInfo
operator|::
name|getType
parameter_list|()
specifier|const
block|{
return|return
name|AndroidNetworkInfo
operator|::
name|NetworkType
argument_list|(
name|m_networkInfo
operator|.
name|callMethod
argument_list|<
name|jint
argument_list|>
argument_list|(
literal|"getType"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|getTypeName
name|QString
name|AndroidNetworkInfo
operator|::
name|getTypeName
parameter_list|()
specifier|const
block|{
name|QJNIObjectPrivate
name|typeName
init|=
name|m_networkInfo
operator|.
name|callObjectMethod
argument_list|<
name|jstring
argument_list|>
argument_list|(
literal|"getTypeName"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|typeName
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|typeName
operator|.
name|toString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isAvailable
name|bool
name|AndroidNetworkInfo
operator|::
name|isAvailable
parameter_list|()
specifier|const
block|{
return|return
name|m_networkInfo
operator|.
name|callMethod
argument_list|<
name|jboolean
argument_list|>
argument_list|(
literal|"isAvailable"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isConnected
name|bool
name|AndroidNetworkInfo
operator|::
name|isConnected
parameter_list|()
specifier|const
block|{
return|return
name|m_networkInfo
operator|.
name|callMethod
argument_list|<
name|jboolean
argument_list|>
argument_list|(
literal|"isConnected"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isConnectedOrConnecting
name|bool
name|AndroidNetworkInfo
operator|::
name|isConnectedOrConnecting
parameter_list|()
specifier|const
block|{
return|return
name|m_networkInfo
operator|.
name|callMethod
argument_list|<
name|jboolean
argument_list|>
argument_list|(
literal|"isConnectedOrConnecting"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isFailover
name|bool
name|AndroidNetworkInfo
operator|::
name|isFailover
parameter_list|()
specifier|const
block|{
return|return
name|m_networkInfo
operator|.
name|callMethod
argument_list|<
name|jboolean
argument_list|>
argument_list|(
literal|"isFailover"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isRoaming
name|bool
name|AndroidNetworkInfo
operator|::
name|isRoaming
parameter_list|()
specifier|const
block|{
return|return
name|m_networkInfo
operator|.
name|callMethod
argument_list|<
name|jboolean
argument_list|>
argument_list|(
literal|"isRoaming"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isValid
name|bool
name|AndroidNetworkInfo
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|m_networkInfo
operator|.
name|isValid
argument_list|()
return|;
block|}
end_function
begin_constructor
DECL|function|AndroidConnectivityManager
name|AndroidConnectivityManager
operator|::
name|AndroidConnectivityManager
parameter_list|()
block|{
name|QJNIEnvironmentPrivate
name|env
decl_stmt|;
if|if
condition|(
operator|!
name|registerNatives
argument_list|(
name|env
argument_list|)
condition|)
return|return;
name|m_connectivityManager
operator|=
name|QJNIObjectPrivate
operator|::
name|callStaticObjectMethod
argument_list|(
name|networkReceiverClass
argument_list|,
literal|"getConnectivityManager"
argument_list|,
literal|"(Landroid/app/Activity;)Landroid/net/ConnectivityManager;"
argument_list|,
name|QtAndroidPrivate
operator|::
name|activity
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_connectivityManager
operator|.
name|isValid
argument_list|()
condition|)
return|return;
name|QJNIObjectPrivate
operator|::
name|callStaticMethod
argument_list|<
name|void
argument_list|>
argument_list|(
name|networkReceiverClass
argument_list|,
literal|"registerReceiver"
argument_list|,
literal|"(Landroid/app/Activity;)V"
argument_list|,
name|QtAndroidPrivate
operator|::
name|activity
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|getInstance
name|AndroidConnectivityManager
modifier|*
name|AndroidConnectivityManager
operator|::
name|getInstance
parameter_list|()
block|{
return|return
name|androidConnManagerInstance
operator|->
name|connManager
operator|->
name|isValid
argument_list|()
condition|?
name|androidConnManagerInstance
operator|->
name|connManager
else|:
literal|0
return|;
block|}
end_function
begin_destructor
DECL|function|~AndroidConnectivityManager
name|AndroidConnectivityManager
operator|::
name|~
name|AndroidConnectivityManager
parameter_list|()
block|{
name|QJNIObjectPrivate
operator|::
name|callStaticMethod
argument_list|<
name|void
argument_list|>
argument_list|(
name|networkReceiverClass
argument_list|,
literal|"unregisterReceiver"
argument_list|,
literal|"(Landroid/app/Activity;)V"
argument_list|,
name|QtAndroidPrivate
operator|::
name|activity
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|getActiveNetworkInfo
name|AndroidNetworkInfo
name|AndroidConnectivityManager
operator|::
name|getActiveNetworkInfo
parameter_list|()
specifier|const
block|{
name|QJNIObjectPrivate
name|networkInfo
init|=
name|m_connectivityManager
operator|.
name|callObjectMethod
argument_list|(
literal|"getActiveNetworkInfo"
argument_list|,
literal|"()Landroid/net/NetworkInfo;"
argument_list|)
decl_stmt|;
return|return
name|networkInfo
return|;
block|}
end_function
begin_function
DECL|function|getAllNetworkInfo
name|QList
argument_list|<
name|AndroidNetworkInfo
argument_list|>
name|AndroidConnectivityManager
operator|::
name|getAllNetworkInfo
parameter_list|()
specifier|const
block|{
name|QJNIEnvironmentPrivate
name|env
decl_stmt|;
name|QJNIObjectPrivate
name|objArray
init|=
name|m_connectivityManager
operator|.
name|callObjectMethod
argument_list|(
literal|"getAllNetworkInfo"
argument_list|,
literal|"()[Landroid/net/NetworkInfo;"
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|AndroidNetworkInfo
argument_list|>
name|list
decl_stmt|;
if|if
condition|(
operator|!
name|objArray
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|list
return|;
specifier|const
name|jsize
name|length
init|=
name|env
operator|->
name|GetArrayLength
argument_list|(
cast|static_cast
argument_list|<
name|jarray
argument_list|>
argument_list|(
name|objArray
operator|.
name|object
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|exceptionCheckAndClear
argument_list|(
name|env
argument_list|)
condition|)
return|return
name|list
return|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|length
condition|;
operator|++
name|i
control|)
block|{
name|jobject
name|lref
init|=
name|env
operator|->
name|GetObjectArrayElement
argument_list|(
cast|static_cast
argument_list|<
name|jobjectArray
argument_list|>
argument_list|(
name|objArray
operator|.
name|object
argument_list|()
argument_list|)
argument_list|,
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|exceptionCheckAndClear
argument_list|(
name|env
argument_list|)
condition|)
break|break;
name|list
operator|<<
name|AndroidNetworkInfo
argument_list|(
name|lref
argument_list|)
expr_stmt|;
name|env
operator|->
name|DeleteLocalRef
argument_list|(
name|lref
argument_list|)
expr_stmt|;
block|}
return|return
name|list
return|;
block|}
end_function
begin_function
DECL|function|getBackgroundDataSetting
name|bool
name|AndroidConnectivityManager
operator|::
name|getBackgroundDataSetting
parameter_list|()
specifier|const
block|{
return|return
name|m_connectivityManager
operator|.
name|callMethod
argument_list|<
name|jboolean
argument_list|>
argument_list|(
literal|"getBackgroundDataSetting"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|getNetworkInfo
name|AndroidNetworkInfo
name|AndroidConnectivityManager
operator|::
name|getNetworkInfo
parameter_list|(
name|int
name|networkType
parameter_list|)
specifier|const
block|{
name|QJNIObjectPrivate
name|networkInfo
init|=
name|m_connectivityManager
operator|.
name|callObjectMethod
argument_list|(
literal|"getNetworkInfo"
argument_list|,
literal|"(I)Landroid/net/NetworkInfo;"
argument_list|,
name|networkType
argument_list|)
decl_stmt|;
return|return
name|networkInfo
return|;
block|}
end_function
begin_function
DECL|function|getNetworkPreference
name|int
name|AndroidConnectivityManager
operator|::
name|getNetworkPreference
parameter_list|()
specifier|const
block|{
return|return
name|m_connectivityManager
operator|.
name|callMethod
argument_list|<
name|jint
argument_list|>
argument_list|(
literal|"getNetworkPreference"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isActiveNetworkMetered
name|bool
name|AndroidConnectivityManager
operator|::
name|isActiveNetworkMetered
parameter_list|()
specifier|const
block|{
comment|// This function was added in JB
if|if
condition|(
name|QtAndroidPrivate
operator|::
name|androidSdkVersion
argument_list|()
operator|<
literal|16
condition|)
return|return
literal|false
return|;
return|return
name|m_connectivityManager
operator|.
name|callMethod
argument_list|<
name|jboolean
argument_list|>
argument_list|(
literal|"isActiveNetworkMetered"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isNetworkTypeValid
name|bool
name|AndroidConnectivityManager
operator|::
name|isNetworkTypeValid
parameter_list|(
name|int
name|networkType
parameter_list|)
block|{
return|return
name|QJNIObjectPrivate
operator|::
name|callStaticMethod
argument_list|<
name|jboolean
argument_list|>
argument_list|(
literal|"android/net/ConnectivityManager"
argument_list|,
literal|"isNetworkTypeValid"
argument_list|,
literal|"(I)Z"
argument_list|,
name|networkType
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|requestRouteToHost
name|bool
name|AndroidConnectivityManager
operator|::
name|requestRouteToHost
parameter_list|(
name|int
name|networkType
parameter_list|,
name|int
name|hostAddress
parameter_list|)
block|{
return|return
name|m_connectivityManager
operator|.
name|callMethod
argument_list|<
name|jboolean
argument_list|>
argument_list|(
literal|"requestRouteToHost"
argument_list|,
literal|"(II)Z"
argument_list|,
name|networkType
argument_list|,
name|hostAddress
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setNetworkPreference
name|void
name|AndroidConnectivityManager
operator|::
name|setNetworkPreference
parameter_list|(
name|int
name|preference
parameter_list|)
block|{
name|m_connectivityManager
operator|.
name|callMethod
argument_list|<
name|void
argument_list|>
argument_list|(
literal|"setNetworkPreference"
argument_list|,
literal|"(I)V"
argument_list|,
name|preference
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|startUsingNetworkFeature
name|int
name|AndroidConnectivityManager
operator|::
name|startUsingNetworkFeature
parameter_list|(
name|int
name|networkType
parameter_list|,
specifier|const
name|QString
modifier|&
name|feature
parameter_list|)
block|{
name|QJNIObjectPrivate
name|jfeature
init|=
name|QJNIObjectPrivate
operator|::
name|fromString
argument_list|(
name|feature
argument_list|)
decl_stmt|;
return|return
name|m_connectivityManager
operator|.
name|callMethod
argument_list|<
name|jint
argument_list|>
argument_list|(
literal|"startUsingNetworkFeature"
argument_list|,
literal|"(ILjava/lang/String;)I"
argument_list|,
name|networkType
argument_list|,
name|jfeature
operator|.
name|object
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|stopUsingNetworkFeature
name|int
name|AndroidConnectivityManager
operator|::
name|stopUsingNetworkFeature
parameter_list|(
name|int
name|networkType
parameter_list|,
specifier|const
name|QString
modifier|&
name|feature
parameter_list|)
block|{
name|QJNIObjectPrivate
name|jfeature
init|=
name|QJNIObjectPrivate
operator|::
name|fromString
argument_list|(
name|feature
argument_list|)
decl_stmt|;
return|return
name|m_connectivityManager
operator|.
name|callMethod
argument_list|<
name|jint
argument_list|>
argument_list|(
literal|"stopUsingNetworkFeature"
argument_list|,
literal|"(ILjava/lang/String;)I"
argument_list|,
name|networkType
argument_list|,
name|jfeature
operator|.
name|object
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|activeNetworkInfoChanged
specifier|static
name|void
name|activeNetworkInfoChanged
parameter_list|()
block|{
name|Q_EMIT
name|androidConnManagerInstance
operator|->
name|connManager
operator|->
name|activeNetworkChanged
argument_list|()
decl_stmt|;
block|}
end_function
begin_function
DECL|function|registerNatives
name|bool
name|AndroidConnectivityManager
operator|::
name|registerNatives
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|)
block|{
name|QJNIObjectPrivate
name|networkReceiver
argument_list|(
name|networkReceiverClass
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|networkReceiver
operator|.
name|isValid
argument_list|()
condition|)
return|return
literal|false
return|;
name|jclass
name|clazz
init|=
name|env
operator|->
name|GetObjectClass
argument_list|(
name|networkReceiver
operator|.
name|object
argument_list|()
argument_list|)
decl_stmt|;
specifier|static
name|JNINativeMethod
name|method
init|=
block|{
literal|"activeNetworkInfoChanged"
block|,
literal|"()V"
block|,
expr|reinterpret_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|activeNetworkInfoChanged
operator|)
block|}
decl_stmt|;
specifier|const
name|bool
name|ret
init|=
operator|(
name|env
operator|->
name|RegisterNatives
argument_list|(
name|clazz
argument_list|,
operator|&
name|method
argument_list|,
literal|1
argument_list|)
operator|==
name|JNI_OK
operator|)
decl_stmt|;
name|env
operator|->
name|DeleteLocalRef
argument_list|(
name|clazz
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
