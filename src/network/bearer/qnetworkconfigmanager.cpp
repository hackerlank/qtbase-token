begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnetworkconfigmanager.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkconfigmanager_p.h"
end_include
begin_include
include|#
directive|include
file|"qbearerengine_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_function_decl
name|QT_BEGIN_NAMESPACE
DECL|macro|Q_GLOBAL_STATIC_QAPP_DESTRUCTION
define|#
directive|define
name|Q_GLOBAL_STATIC_QAPP_DESTRUCTION
parameter_list|(
name|TYPE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|static QGlobalStatic<TYPE> this_##NAME                             \                 = { Q_BASIC_ATOMIC_INITIALIZER(0), false };             \     static void NAME##_cleanup()                                        \     {                                                                   \         delete this_##NAME.pointer;                                     \         this_##NAME.pointer = 0;                                        \     }                                                                   \     static TYPE *NAME()                                                 \     {                                                                   \         if (!this_##NAME.pointer) {                                     \             TYPE *x = new TYPE;                                         \             if (!this_##NAME.pointer.testAndSetOrdered(0, x))           \                 delete x;                                               \             else {                                                      \                 qAddPostRoutine(NAME##_cleanup);                        \                 this_##NAME.pointer->updateConfigurations();            \             }                                                           \         }                                                               \         return this_##NAME.pointer;                                     \     }
name|Q_GLOBAL_STATIC_QAPP_DESTRUCTION
parameter_list|(
name|QNetworkConfigurationManagerPrivate
parameter_list|,
name|connManager
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|qNetworkConfigurationManagerPrivate
name|QNetworkConfigurationManagerPrivate
modifier|*
name|qNetworkConfigurationManagerPrivate
parameter_list|()
block|{
return|return
name|connManager
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \class QNetworkConfigurationManager      \brief The QNetworkConfigurationManager class manages the network configurations provided     by the system.      \since 4.7      \inmodule QtNetwork     \ingroup network      QNetworkConfigurationManager provides access to the network configurations known to the system and     enables applications to detect the system capabilities (with regards to network sessions) at runtime.      A QNetworkConfiguration abstracts a set of configuration options describing how a     network interface has to be configured to connect to a particular target network.     QNetworkConfigurationManager maintains and updates the global list of     QNetworkConfigurations. Applications can access and filter this list via     allConfigurations(). If a new configuration is added or an existing one is removed or changed     the configurationAdded(), configurationRemoved() and configurationChanged() signals are emitted     respectively.      The defaultConfiguration() can be used when intending to immediately create a new     network session without caring about the particular configuration. It returns     a \l QNetworkConfiguration::Discovered configuration. If there are not any     discovered ones an invalid configuration is returned.      Some configuration updates may require some time to perform updates. A WLAN scan is     such an example. Unless the platform performs internal updates it may be required to     manually trigger configuration updates via QNetworkConfigurationManager::updateConfigurations().     The completion of the update process is indicted by emitting the updateCompleted()     signal. The update process ensures that every existing QNetworkConfiguration instance     is updated. There is no need to ask for a renewed configuration list via allConfigurations().      \sa QNetworkConfiguration */
end_comment
begin_comment
comment|/*!      \fn void QNetworkConfigurationManager::configurationAdded(const QNetworkConfiguration&config)      This signal is emitted whenever a new network configuration is added to the system. The new     configuration is specified by \a config. */
end_comment
begin_comment
comment|/*!     \fn void QNetworkConfigurationManager::configurationRemoved(const QNetworkConfiguration&config)      This signal is emitted when a configuration is about to be removed from the system. The removed     configuration, specified by \a config, is invalid but retains name and identifier. */
end_comment
begin_comment
comment|/*!     \fn void QNetworkConfigurationManager::updateCompleted()      This signal is emitted when the configuration update has been completed. Such an update can     be initiated via \l updateConfigurations(). */
end_comment
begin_comment
comment|/*! \fn void QNetworkConfigurationManager::configurationChanged(const QNetworkConfiguration&config)      This signal is emitted when the \l {QNetworkConfiguration::state()}{state} of \a config changes. */
end_comment
begin_comment
comment|/*!     \fn void QNetworkConfigurationManager::onlineStateChanged(bool isOnline)      This signal is emitted when the device changes from online to offline mode or vice versa.     \a isOnline represents the new state of the device.      The state is considered to be online for as long as     \l{allConfigurations()}{allConfigurations}(QNetworkConfiguration::Active) returns a list with     at least one entry. */
end_comment
begin_comment
comment|/*!     \enum QNetworkConfigurationManager::Capability      Specifies the system capabilities of the bearer API. The possible values are:      \value CanStartAndStopInterfaces Network sessions and their underlying access points can be                                      started and stopped. If this flag is not set QNetworkSession                                      can only monitor but not influence the state of access points.                                      On some platforms this feature may require elevated user                                      permissions. This option is platform specific and may not                                      always be available.     \value DirectConnectionRouting   Network sessions and their sockets can be bound to a                                      particular network interface. Any packet that passes through                                      the socket goes to the specified network interface and thus                                      disregards standard routing table entries. This may be useful                                      when two interfaces can reach overlapping IP ranges or an                                      application has specific needs in regards to target networks.                                      This option is platform specific and may not always be                                      available.     \value SystemSessionSupport      If this flag is set the underlying platform ensures that a                                      network interface is not shut down until the last network                                      session has been \l{QNetworkSession::close()}{closed()}. This                                      works across multiple processes. If the platform session                                      support is missing this API can only ensure the above behavior                                      for network sessions within the same process.                                      In general mobile platforms (such as Symbian/S60) have such                                      support whereas most desktop platform lack this capability.     \value ApplicationLevelRoaming   The system gives applications control over the systems roaming                                      behavior. Applications can initiate roaming (in case the                                      current link is not suitable) and are consulted if the system                                      has identified a more suitable access point.     \value ForcedRoaming             The system disconnects an existing access point and reconnects                                      via a more suitable one. The application does not have any                                      control over this process and has to reconnect its active                                      sockets.     \value DataStatistics            If this flag is set QNetworkSession can provide statistics                                      about transmitted and received data.     \value NetworkSessionRequired    If this flag is set the platform requires that a network                                      session is created before network operations can be performed. */
end_comment
begin_comment
comment|/*!     Constructs a QNetworkConfigurationManager with the given \a parent.      Note that to ensure a valid list of current configurations immediately available, updating     is done during construction which causes some delay. */
end_comment
begin_constructor
DECL|function|QNetworkConfigurationManager
name|QNetworkConfigurationManager
operator|::
name|QNetworkConfigurationManager
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{
name|QNetworkConfigurationManagerPrivate
modifier|*
name|priv
init|=
name|qNetworkConfigurationManagerPrivate
argument_list|()
decl_stmt|;
name|connect
argument_list|(
name|priv
argument_list|,
name|SIGNAL
argument_list|(
name|configurationAdded
argument_list|(
name|QNetworkConfiguration
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|configurationAdded
argument_list|(
name|QNetworkConfiguration
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|priv
argument_list|,
name|SIGNAL
argument_list|(
name|configurationRemoved
argument_list|(
name|QNetworkConfiguration
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|configurationRemoved
argument_list|(
name|QNetworkConfiguration
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|priv
argument_list|,
name|SIGNAL
argument_list|(
name|configurationChanged
argument_list|(
name|QNetworkConfiguration
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|configurationChanged
argument_list|(
name|QNetworkConfiguration
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|priv
argument_list|,
name|SIGNAL
argument_list|(
name|onlineStateChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|onlineStateChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|priv
argument_list|,
name|SIGNAL
argument_list|(
name|configurationUpdateComplete
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|updateCompleted
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|priv
operator|->
name|enablePolling
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Frees the resources associated with the QNetworkConfigurationManager object. */
end_comment
begin_destructor
DECL|function|~QNetworkConfigurationManager
name|QNetworkConfigurationManager
operator|::
name|~
name|QNetworkConfigurationManager
parameter_list|()
block|{
name|QNetworkConfigurationManagerPrivate
modifier|*
name|priv
init|=
name|connManager
argument_list|()
decl_stmt|;
if|if
condition|(
name|priv
condition|)
name|priv
operator|->
name|disablePolling
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Returns the default configuration to be used. This function always returns a discovered     configuration; otherwise an invalid configuration.      In some cases it may be required to call updateConfigurations() and wait for the     updateCompleted() signal before calling this function.      \sa allConfigurations() */
end_comment
begin_function
DECL|function|defaultConfiguration
name|QNetworkConfiguration
name|QNetworkConfigurationManager
operator|::
name|defaultConfiguration
parameter_list|()
specifier|const
block|{
name|QNetworkConfigurationManagerPrivate
modifier|*
name|priv
init|=
name|connManager
argument_list|()
decl_stmt|;
if|if
condition|(
name|priv
condition|)
return|return
name|priv
operator|->
name|defaultConfiguration
argument_list|()
return|;
return|return
name|QNetworkConfiguration
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the list of configurations which comply with the given \a filter.      By default this function returns all (defined and undefined) configurations.      A wireless network with a particular SSID may only be accessible in a     certain area despite the fact that the system has a valid configuration     for it. Therefore the filter flag may be used to limit the list to     discovered and possibly connected configurations only.      If \a filter is set to zero this function returns all possible configurations.      Note that this function returns the states for all configurations as they are known at     the time of this function call. If for instance a configuration of type WLAN is defined     the system may have to perform a WLAN scan in order to determine whether it is     actually available. To obtain the most accurate state updateConfigurations() should     be used to update each configuration's state. Note that such an update may require     some time. It's completion is signalled by updateCompleted(). In the absence of a     configuration update this function returns the best estimate at the time of the call.     Therefore, if WLAN configurations are of interest, it is recommended that     updateConfigurations() is called once after QNetworkConfigurationManager     instantiation (WLAN scans are too time consuming to perform in constructor).     After this the data is kept automatically up-to-date as the system reports     any changes. */
end_comment
begin_function
DECL|function|allConfigurations
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|QNetworkConfigurationManager
operator|::
name|allConfigurations
parameter_list|(
name|QNetworkConfiguration
operator|::
name|StateFlags
name|filter
parameter_list|)
specifier|const
block|{
name|QNetworkConfigurationManagerPrivate
modifier|*
name|priv
init|=
name|connManager
argument_list|()
decl_stmt|;
if|if
condition|(
name|priv
condition|)
return|return
name|priv
operator|->
name|allConfigurations
argument_list|(
name|filter
argument_list|)
return|;
return|return
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the QNetworkConfiguration for \a identifier; otherwise returns an     invalid QNetworkConfiguration.      \sa QNetworkConfiguration::identifier() */
end_comment
begin_function
DECL|function|configurationFromIdentifier
name|QNetworkConfiguration
name|QNetworkConfigurationManager
operator|::
name|configurationFromIdentifier
parameter_list|(
specifier|const
name|QString
modifier|&
name|identifier
parameter_list|)
specifier|const
block|{
name|QNetworkConfigurationManagerPrivate
modifier|*
name|priv
init|=
name|connManager
argument_list|()
decl_stmt|;
if|if
condition|(
name|priv
condition|)
return|return
name|priv
operator|->
name|configurationFromIdentifier
argument_list|(
name|identifier
argument_list|)
return|;
return|return
name|QNetworkConfiguration
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the system is considered to be connected to another device via an active     network interface; otherwise returns false.      This is equivalent to the following code snippet:      \snippet doc/src/snippets/code/src_network_bearer_qnetworkconfigmanager.cpp 0      \sa onlineStateChanged() */
end_comment
begin_function
DECL|function|isOnline
name|bool
name|QNetworkConfigurationManager
operator|::
name|isOnline
parameter_list|()
specifier|const
block|{
name|QNetworkConfigurationManagerPrivate
modifier|*
name|priv
init|=
name|connManager
argument_list|()
decl_stmt|;
if|if
condition|(
name|priv
condition|)
return|return
name|priv
operator|->
name|isOnline
argument_list|()
return|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the capabilities supported by the current platform. */
end_comment
begin_function
DECL|function|capabilities
name|QNetworkConfigurationManager
operator|::
name|Capabilities
name|QNetworkConfigurationManager
operator|::
name|capabilities
parameter_list|()
specifier|const
block|{
name|QNetworkConfigurationManagerPrivate
modifier|*
name|priv
init|=
name|connManager
argument_list|()
decl_stmt|;
if|if
condition|(
name|priv
condition|)
return|return
name|priv
operator|->
name|capabilities
argument_list|()
return|;
return|return
name|QNetworkConfigurationManager
operator|::
name|Capabilities
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Initiates an update of all configurations. This may be used to initiate WLAN scans or other     time consuming updates which may be required to obtain the correct state for configurations.      This call is asynchronous. On completion of this update the updateCompleted() signal is     emitted. If new configurations are discovered or old ones were removed or changed the update     process may trigger the emission of one or multiple configurationAdded(),     configurationRemoved() and configurationChanged() signals.      If a configuration state changes as a result of this update all existing QNetworkConfiguration     instances are updated automatically.      \sa allConfigurations() */
end_comment
begin_function
DECL|function|updateConfigurations
name|void
name|QNetworkConfigurationManager
operator|::
name|updateConfigurations
parameter_list|()
block|{
name|QNetworkConfigurationManagerPrivate
modifier|*
name|priv
init|=
name|connManager
argument_list|()
decl_stmt|;
if|if
condition|(
name|priv
condition|)
name|priv
operator|->
name|performAsyncConfigurationUpdate
argument_list|()
expr_stmt|;
block|}
end_function
begin_include
include|#
directive|include
file|"moc_qnetworkconfigmanager.cpp"
end_include
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
