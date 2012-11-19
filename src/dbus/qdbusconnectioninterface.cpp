begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbusconnectioninterface.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMetaMethod>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|"qdbus_symbols_p.h"
end_include
begin_comment
comment|// for the DBUS_* constants
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*  * Implementation of interface class QDBusConnectionInterface  */
comment|/*!     \class QDBusConnectionInterface     \inmodule QtDBus     \since 4.2      \brief The QDBusConnectionInterface class provides access to the D-Bus bus daemon service.      The D-Bus bus server daemon provides one special interface \c     org.freedesktop.DBus that allows clients to access certain     properties of the bus, such as the current list of clients     connected. The QDBusConnectionInterface class provides access to that     interface.      The most common uses of this class are to register and unregister     service names on the bus using the registerService() and     unregisterService() functions, query about existing names using     the isServiceRegistered(), registeredServiceNames() and     serviceOwner() functions, and to receive notification that a     client has registered or de-registered through the     serviceRegistered(), serviceUnregistered() and serviceOwnerChanged()     signals. */
comment|/*!     \enum QDBusConnectionInterface::ServiceQueueOptions      Flags for determining how a service registration should behave, in     case the service name is already registered.      \value DontQueueService     If an application requests a name that                                 is already owned, no queueing will be                                 performed. The registeredService()                                 call will simply fail.                                 This is the default.      \value QueueService         Attempts to register the requested                                 service, but do not try to replace it                                 if another application already has it                                 registered. Instead, simply put this                                 application in queue, until it is                                 given up. The serviceRegistered()                                 signal will be emitted when that                                 happens.      \value ReplaceExistingService If another application already has                                 the service name registered, attempt                                 to replace it.      \sa ServiceReplacementOptions */
comment|/*!     \enum QDBusConnectionInterface::ServiceReplacementOptions      Flags for determining if the D-Bus server should allow another     application to replace a name that this application has registered     with the ReplaceExistingService option.      The possible values are:      \value DontAllowReplacement Do not allow another application to                                 replace us. The service must be                                 explicitly unregistered with                                 unregisterService() for another                                 application to acquire it.                                 This is the default.      \value AllowReplacement     Allow other applications to replace us                                 with the ReplaceExistingService option                                 to registerService() without                                 intervention. If that happens, the                                 serviceUnregistered() signal will be                                 emitted.      \sa ServiceQueueOptions */
comment|/*!     \enum QDBusConnectionInterface::RegisterServiceReply      The possible return values from registerService():      \value ServiceNotRegistered The call failed and the service name was not registered.     \value ServiceRegistered    The caller is now the owner of the service name.     \value ServiceQueued        The caller specified the QueueService flag and the                                 service was already registered, so we are in queue.      The serviceRegistered() signal will be emitted when the service is     acquired by this application. */
comment|/*!     \internal */
DECL|function|staticInterfaceName
specifier|const
name|char
modifier|*
name|QDBusConnectionInterface
operator|::
name|staticInterfaceName
parameter_list|()
block|{
return|return
literal|"org.freedesktop.DBus"
return|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QDBusConnectionInterface
name|QDBusConnectionInterface
operator|::
name|QDBusConnectionInterface
parameter_list|(
specifier|const
name|QDBusConnection
modifier|&
name|connection
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDBusAbstractInterface
argument_list|(
name|QLatin1String
argument_list|(
name|DBUS_SERVICE_DBUS
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|DBUS_PATH_DBUS
argument_list|)
argument_list|,
name|DBUS_INTERFACE_DBUS
argument_list|,
name|connection
argument_list|,
name|parent
argument_list|)
block|{
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|NameAcquired
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|serviceRegistered
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|NameLost
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|serviceUnregistered
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|NameOwnerChanged
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|serviceOwnerChanged
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_destructor
DECL|function|~QDBusConnectionInterface
name|QDBusConnectionInterface
operator|::
name|~
name|QDBusConnectionInterface
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Returns the unique connection name of the primary owner of the     name \a name. If the requested name doesn't have an owner, returns     a \c org.freedesktop.DBus.Error.NameHasNoOwner error. */
end_comment
begin_function
DECL|function|serviceOwner
name|QDBusReply
argument_list|<
name|QString
argument_list|>
name|QDBusConnectionInterface
operator|::
name|serviceOwner
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
return|return
name|internalConstCall
argument_list|(
name|QDBus
operator|::
name|AutoDetect
argument_list|,
name|QLatin1String
argument_list|(
literal|"GetNameOwner"
argument_list|)
argument_list|,
name|QList
argument_list|<
name|QVariant
argument_list|>
argument_list|()
operator|<<
name|name
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \property QDBusConnectionInterface::registeredServiceNames   \brief holds the registered service names    Lists all names currently registered on the bus. */
end_comment
begin_function
DECL|function|registeredServiceNames
name|QDBusReply
argument_list|<
name|QStringList
argument_list|>
name|QDBusConnectionInterface
operator|::
name|registeredServiceNames
parameter_list|()
specifier|const
block|{
return|return
name|internalConstCall
argument_list|(
name|QDBus
operator|::
name|AutoDetect
argument_list|,
name|QLatin1String
argument_list|(
literal|"ListNames"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the service name \a serviceName has is currently     registered. */
end_comment
begin_function
DECL|function|isServiceRegistered
name|QDBusReply
argument_list|<
name|bool
argument_list|>
name|QDBusConnectionInterface
operator|::
name|isServiceRegistered
parameter_list|(
specifier|const
name|QString
modifier|&
name|serviceName
parameter_list|)
specifier|const
block|{
return|return
name|internalConstCall
argument_list|(
name|QDBus
operator|::
name|AutoDetect
argument_list|,
name|QLatin1String
argument_list|(
literal|"NameHasOwner"
argument_list|)
argument_list|,
name|QList
argument_list|<
name|QVariant
argument_list|>
argument_list|()
operator|<<
name|serviceName
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the Unix Process ID (PID) for the process currently     holding the bus service \a serviceName. */
end_comment
begin_function
DECL|function|servicePid
name|QDBusReply
argument_list|<
name|uint
argument_list|>
name|QDBusConnectionInterface
operator|::
name|servicePid
parameter_list|(
specifier|const
name|QString
modifier|&
name|serviceName
parameter_list|)
specifier|const
block|{
return|return
name|internalConstCall
argument_list|(
name|QDBus
operator|::
name|AutoDetect
argument_list|,
name|QLatin1String
argument_list|(
literal|"GetConnectionUnixProcessID"
argument_list|)
argument_list|,
name|QList
argument_list|<
name|QVariant
argument_list|>
argument_list|()
operator|<<
name|serviceName
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the Unix User ID (UID) for the process currently holding     the bus service \a serviceName. */
end_comment
begin_function
DECL|function|serviceUid
name|QDBusReply
argument_list|<
name|uint
argument_list|>
name|QDBusConnectionInterface
operator|::
name|serviceUid
parameter_list|(
specifier|const
name|QString
modifier|&
name|serviceName
parameter_list|)
specifier|const
block|{
return|return
name|internalConstCall
argument_list|(
name|QDBus
operator|::
name|AutoDetect
argument_list|,
name|QLatin1String
argument_list|(
literal|"GetConnectionUnixUser"
argument_list|)
argument_list|,
name|QList
argument_list|<
name|QVariant
argument_list|>
argument_list|()
operator|<<
name|serviceName
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Requests that the bus start the service given by the name \a name. */
end_comment
begin_function
DECL|function|startService
name|QDBusReply
argument_list|<
name|void
argument_list|>
name|QDBusConnectionInterface
operator|::
name|startService
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
return|return
name|call
argument_list|(
name|QLatin1String
argument_list|(
literal|"StartServiceByName"
argument_list|)
argument_list|,
name|name
argument_list|,
name|uint
argument_list|(
literal|0
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Requests to register the service name \a serviceName on the     bus. The \a qoption flag specifies how the D-Bus server should behave     if \a serviceName is already registered. The \a roption flag     specifies if the server should allow another application to     replace our registered name.      If the service registration succeeds, the serviceRegistered()     signal will be emitted. If we are placed in queue, the signal will     be emitted when we obtain the name. If \a roption is     AllowReplacement, the serviceUnregistered() signal will be emitted     if another application replaces this one.      \sa unregisterService() */
end_comment
begin_function
name|QDBusReply
argument_list|<
name|QDBusConnectionInterface
operator|::
name|RegisterServiceReply
argument_list|>
DECL|function|registerService
name|QDBusConnectionInterface
operator|::
name|registerService
parameter_list|(
specifier|const
name|QString
modifier|&
name|serviceName
parameter_list|,
name|ServiceQueueOptions
name|qoption
parameter_list|,
name|ServiceReplacementOptions
name|roption
parameter_list|)
block|{
comment|// reconstruct the low-level flags
name|uint
name|flags
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|qoption
condition|)
block|{
case|case
name|DontQueueService
case|:
name|flags
operator|=
name|DBUS_NAME_FLAG_DO_NOT_QUEUE
expr_stmt|;
break|break;
case|case
name|QueueService
case|:
name|flags
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|ReplaceExistingService
case|:
name|flags
operator|=
name|DBUS_NAME_FLAG_DO_NOT_QUEUE
operator||
name|DBUS_NAME_FLAG_REPLACE_EXISTING
expr_stmt|;
break|break;
block|}
switch|switch
condition|(
name|roption
condition|)
block|{
case|case
name|DontAllowReplacement
case|:
break|break;
case|case
name|AllowReplacement
case|:
name|flags
operator||=
name|DBUS_NAME_FLAG_ALLOW_REPLACEMENT
expr_stmt|;
break|break;
block|}
name|QDBusMessage
name|reply
init|=
name|call
argument_list|(
name|QLatin1String
argument_list|(
literal|"RequestName"
argument_list|)
argument_list|,
name|serviceName
argument_list|,
name|flags
argument_list|)
decl_stmt|;
comment|//    qDebug()<< "QDBusConnectionInterface::registerService"<< serviceName<< "Reply:"<< reply;
comment|// convert the low-level flags to something that we can use
if|if
condition|(
name|reply
operator|.
name|type
argument_list|()
operator|==
name|QDBusMessage
operator|::
name|ReplyMessage
condition|)
block|{
name|uint
name|code
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|reply
operator|.
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toUInt
argument_list|()
condition|)
block|{
case|case
name|DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER
case|:
case|case
name|DBUS_REQUEST_NAME_REPLY_ALREADY_OWNER
case|:
name|code
operator|=
name|uint
argument_list|(
name|ServiceRegistered
argument_list|)
expr_stmt|;
break|break;
case|case
name|DBUS_REQUEST_NAME_REPLY_EXISTS
case|:
name|code
operator|=
name|uint
argument_list|(
name|ServiceNotRegistered
argument_list|)
expr_stmt|;
break|break;
case|case
name|DBUS_REQUEST_NAME_REPLY_IN_QUEUE
case|:
name|code
operator|=
name|uint
argument_list|(
name|ServiceQueued
argument_list|)
expr_stmt|;
break|break;
block|}
name|reply
operator|.
name|setArguments
argument_list|(
name|QVariantList
argument_list|()
operator|<<
name|code
argument_list|)
expr_stmt|;
block|}
return|return
name|reply
return|;
block|}
end_function
begin_comment
comment|/*!     Releases the claim on the bus service name \a serviceName, that     had been previously registered with registerService(). If this     application had ownership of the name, it will be released for     other applications to claim. If it only had the name queued, it     gives up its position in the queue. */
end_comment
begin_function
name|QDBusReply
argument_list|<
name|bool
argument_list|>
DECL|function|unregisterService
name|QDBusConnectionInterface
operator|::
name|unregisterService
parameter_list|(
specifier|const
name|QString
modifier|&
name|serviceName
parameter_list|)
block|{
name|QDBusMessage
name|reply
init|=
name|call
argument_list|(
name|QLatin1String
argument_list|(
literal|"ReleaseName"
argument_list|)
argument_list|,
name|serviceName
argument_list|)
decl_stmt|;
if|if
condition|(
name|reply
operator|.
name|type
argument_list|()
operator|==
name|QDBusMessage
operator|::
name|ReplyMessage
condition|)
block|{
name|bool
name|success
init|=
name|reply
operator|.
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toUInt
argument_list|()
operator|==
name|DBUS_RELEASE_NAME_REPLY_RELEASED
decl_stmt|;
name|reply
operator|.
name|setArguments
argument_list|(
name|QVariantList
argument_list|()
operator|<<
name|success
argument_list|)
expr_stmt|;
block|}
return|return
name|reply
return|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|connectNotify
name|void
name|QDBusConnectionInterface
operator|::
name|connectNotify
parameter_list|(
specifier|const
name|QMetaMethod
modifier|&
name|signal
parameter_list|)
block|{
comment|// translate the signal names to what we really want
comment|// this avoids setting hooks for signals that don't exist on the bus
specifier|static
specifier|const
name|QMetaMethod
name|serviceRegisteredSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QDBusConnectionInterface
operator|::
name|serviceRegistered
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|QMetaMethod
name|serviceUnregisteredSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QDBusConnectionInterface
operator|::
name|serviceUnregistered
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|QMetaMethod
name|serviceOwnerChangedSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QDBusConnectionInterface
operator|::
name|serviceOwnerChanged
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|QMetaMethod
name|NameAcquiredSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QDBusConnectionInterface
operator|::
name|NameAcquired
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|QMetaMethod
name|NameLostSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QDBusConnectionInterface
operator|::
name|NameLost
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|QMetaMethod
name|NameOwnerChangedSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QDBusConnectionInterface
operator|::
name|NameOwnerChanged
argument_list|)
decl_stmt|;
if|if
condition|(
name|signal
operator|==
name|serviceRegisteredSignal
condition|)
name|QDBusAbstractInterface
operator|::
name|connectNotify
argument_list|(
name|NameAcquiredSignal
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|signal
operator|==
name|serviceUnregisteredSignal
condition|)
name|QDBusAbstractInterface
operator|::
name|connectNotify
argument_list|(
name|NameLostSignal
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|signal
operator|==
name|serviceOwnerChangedSignal
condition|)
block|{
specifier|static
name|bool
name|warningPrinted
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|warningPrinted
condition|)
block|{
name|qWarning
argument_list|(
literal|"Connecting to deprecated signal QDBusConnectionInterface::serviceOwnerChanged(QString,QString,QString)"
argument_list|)
expr_stmt|;
name|warningPrinted
operator|=
literal|true
expr_stmt|;
block|}
name|QDBusAbstractInterface
operator|::
name|connectNotify
argument_list|(
name|NameOwnerChangedSignal
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|disconnectNotify
name|void
name|QDBusConnectionInterface
operator|::
name|disconnectNotify
parameter_list|(
specifier|const
name|QMetaMethod
modifier|&
name|signal
parameter_list|)
block|{
comment|// translate the signal names to what we really want
comment|// this avoids setting hooks for signals that don't exist on the bus
specifier|static
specifier|const
name|QMetaMethod
name|serviceRegisteredSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QDBusConnectionInterface
operator|::
name|serviceRegistered
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|QMetaMethod
name|serviceUnregisteredSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QDBusConnectionInterface
operator|::
name|serviceUnregistered
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|QMetaMethod
name|serviceOwnerChangedSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QDBusConnectionInterface
operator|::
name|serviceOwnerChanged
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|QMetaMethod
name|NameAcquiredSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QDBusConnectionInterface
operator|::
name|NameAcquired
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|QMetaMethod
name|NameLostSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QDBusConnectionInterface
operator|::
name|NameLost
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|QMetaMethod
name|NameOwnerChangedSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QDBusConnectionInterface
operator|::
name|NameOwnerChanged
argument_list|)
decl_stmt|;
if|if
condition|(
name|signal
operator|==
name|serviceRegisteredSignal
condition|)
name|QDBusAbstractInterface
operator|::
name|disconnectNotify
argument_list|(
name|NameAcquiredSignal
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|signal
operator|==
name|serviceUnregisteredSignal
condition|)
name|QDBusAbstractInterface
operator|::
name|disconnectNotify
argument_list|(
name|NameLostSignal
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|signal
operator|==
name|serviceOwnerChangedSignal
condition|)
name|QDBusAbstractInterface
operator|::
name|disconnectNotify
argument_list|(
name|NameOwnerChangedSignal
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// signals
end_comment
begin_comment
comment|/*!     \fn QDBusConnectionInterface::serviceRegistered(const QString&serviceName)      This signal is emitted by the D-Bus server when the bus service     name (unique connection name or well-known service name) given by     \a serviceName is acquired by this application.      Acquisition happens after this application has requested a name using     registerService(). */
end_comment
begin_comment
comment|/*!     \fn QDBusConnectionInterface::serviceUnregistered(const QString&serviceName)      This signal is emitted by the D-Bus server when this application     loses ownership of the bus service name given by \a serviceName. */
end_comment
begin_comment
comment|/*!     \fn QDBusConnectionInterface::serviceOwnerChanged(const QString&name, const QString&oldOwner, const QString&newOwner)     \deprecated      Use QDBusServiceWatcher instead.      This signal is emitted by the D-Bus server whenever a service     ownership change happens in the bus, including apparition and     disparition of names.      This signal means the application \a oldOwner lost ownership of     bus name \a name to application \a newOwner. If \a oldOwner is an     empty string, it means the name \a name has just been created; if     \a newOwner is empty, the name \a name has no current owner and is     no longer available.      \note connecting to this signal will make the application listen for and     receive every single service ownership change on the bus. Depending on     how many services are running, this make the application be activated to     receive more signals than it needs. To avoid this problem, use the     QDBusServiceWatcher class, which can listen for specific changes. */
end_comment
begin_comment
comment|/*!   \fn void QDBusConnectionInterface::callWithCallbackFailed(const QDBusError&error, const QDBusMessage&call)    This signal is emitted when there is an error during a   QDBusConnection::callWithCallback(). \a error specifies the error.   \a call is the message that couldn't be delivered.    \sa QDBusConnection::callWithCallback()  */
end_comment
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
end_unit
