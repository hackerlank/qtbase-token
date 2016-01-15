begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbusservicewatcher.h"
end_include
begin_include
include|#
directive|include
file|"qdbusconnection.h"
end_include
begin_include
include|#
directive|include
file|"qdbusutil_p.h"
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qdbusconnection_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QDBusServiceWatcherPrivate
class|class
name|QDBusServiceWatcherPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QDBusServiceWatcher
parameter_list|)
specifier|public
private|:
DECL|function|QDBusServiceWatcherPrivate
name|QDBusServiceWatcherPrivate
parameter_list|(
specifier|const
name|QDBusConnection
modifier|&
name|c
parameter_list|,
name|QDBusServiceWatcher
operator|::
name|WatchMode
name|wm
parameter_list|)
member_init_list|:
name|connection
argument_list|(
name|c
argument_list|)
member_init_list|,
name|watchMode
argument_list|(
name|wm
argument_list|)
block|{     }
DECL|member|servicesWatched
name|QStringList
name|servicesWatched
decl_stmt|;
DECL|member|connection
name|QDBusConnection
name|connection
decl_stmt|;
DECL|member|watchMode
name|QDBusServiceWatcher
operator|::
name|WatchMode
name|watchMode
decl_stmt|;
name|void
name|_q_serviceOwnerChanged
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|void
name|setConnection
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|services
parameter_list|,
specifier|const
name|QDBusConnection
modifier|&
name|c
parameter_list|,
name|QDBusServiceWatcher
operator|::
name|WatchMode
name|watchMode
parameter_list|)
function_decl|;
name|void
name|addService
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|)
function_decl|;
name|void
name|removeService
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|_q_serviceOwnerChanged
name|void
name|QDBusServiceWatcherPrivate
operator|::
name|_q_serviceOwnerChanged
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|oldOwner
parameter_list|,
specifier|const
name|QString
modifier|&
name|newOwner
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QDBusServiceWatcher
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|serviceOwnerChanged
argument_list|(
name|service
argument_list|,
name|oldOwner
argument_list|,
name|newOwner
argument_list|)
emit|;
if|if
condition|(
name|oldOwner
operator|.
name|isEmpty
argument_list|()
condition|)
emit|emit
name|q
operator|->
name|serviceRegistered
argument_list|(
name|service
argument_list|)
emit|;
elseif|else
if|if
condition|(
name|newOwner
operator|.
name|isEmpty
argument_list|()
condition|)
emit|emit
name|q
operator|->
name|serviceUnregistered
argument_list|(
name|service
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|setConnection
name|void
name|QDBusServiceWatcherPrivate
operator|::
name|setConnection
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|s
parameter_list|,
specifier|const
name|QDBusConnection
modifier|&
name|c
parameter_list|,
name|QDBusServiceWatcher
operator|::
name|WatchMode
name|wm
parameter_list|)
block|{
if|if
condition|(
name|connection
operator|.
name|isConnected
argument_list|()
condition|)
block|{
comment|// remove older rules
for|for
control|(
specifier|const
name|QString
modifier|&
name|s
range|:
name|qAsConst
argument_list|(
name|servicesWatched
argument_list|)
control|)
name|removeService
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
name|connection
operator|=
name|c
expr_stmt|;
name|watchMode
operator|=
name|wm
expr_stmt|;
name|servicesWatched
operator|=
name|s
expr_stmt|;
if|if
condition|(
name|connection
operator|.
name|isConnected
argument_list|()
condition|)
block|{
comment|// add new rules
for|for
control|(
specifier|const
name|QString
modifier|&
name|s
range|:
name|qAsConst
argument_list|(
name|servicesWatched
argument_list|)
control|)
name|addService
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|addService
name|void
name|QDBusServiceWatcherPrivate
operator|::
name|addService
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|)
block|{
name|QDBusConnectionPrivate
modifier|*
name|d
init|=
name|QDBusConnectionPrivate
operator|::
name|d
argument_list|(
name|connection
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|&&
name|d
operator|->
name|shouldWatchService
argument_list|(
name|service
argument_list|)
condition|)
name|d
operator|->
name|watchService
argument_list|(
name|service
argument_list|,
name|watchMode
argument_list|,
name|q_func
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|_q_serviceOwnerChanged
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
end_function
begin_function
DECL|function|removeService
name|void
name|QDBusServiceWatcherPrivate
operator|::
name|removeService
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|)
block|{
name|QDBusConnectionPrivate
modifier|*
name|d
init|=
name|QDBusConnectionPrivate
operator|::
name|d
argument_list|(
name|connection
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|&&
name|d
operator|->
name|shouldWatchService
argument_list|(
name|service
argument_list|)
condition|)
name|d
operator|->
name|unwatchService
argument_list|(
name|service
argument_list|,
name|watchMode
argument_list|,
name|q_func
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|_q_serviceOwnerChanged
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
end_function
begin_comment
comment|/*!     \class QDBusServiceWatcher     \since 4.6     \inmodule QtDBus      \brief The QDBusServiceWatcher class allows the user to watch for a bus service change.      A QDBusServiceWatcher object can be used to notify the application about     an ownership change of a service name on the bus. It has three watch     modes:      \list       \li Watching for service registration only.       \li Watching for service unregistration only.       \li Watching for any kind of service ownership change (the default mode).     \endlist      Besides being created or deleted, services may change owners without a     unregister/register operation happening. So the serviceRegistered()     and serviceUnregistered() signals may not be emitted if that     happens.      This class is more efficient than using the     QDBusConnectionInterface::serviceOwnerChanged() signal because it allows     one to receive only the signals for which the class is interested in.      \sa QDBusConnection */
end_comment
begin_comment
comment|/*!     \enum QDBusServiceWatcher::WatchModeFlag      QDBusServiceWatcher supports three different watch modes, which are configured by this flag:      \value WatchForRegistration watch for service registration only, ignoring     any signals related to other service ownership change.      \value WatchForUnregistration watch for service unregistration only,     ignoring any signals related to other service ownership change.      \value WatchForOwnerChange watch for any kind of service ownership     change. */
end_comment
begin_comment
comment|/*!     \property QDBusServiceWatcher::watchMode      The \c watchMode property holds the current watch mode for this     QDBusServiceWatcher object. The default value for this property is     QDBusServiceWatcher::WatchForOwnershipChange. */
end_comment
begin_comment
comment|/*!     \property QDBusServiceWatcher::watchedServices      The \c servicesWatched property holds the list of services watched.      Note that modifying this list with setServicesWatched() is an expensive     operation. If you can, prefer to change it by way of addWatchedService()     and removeWatchedService(). */
end_comment
begin_comment
comment|/*!     \fn void QDBusServiceWatcher::serviceRegistered(const QString&serviceName)      This signal is emitted whenever this object detects that the service \a     serviceName became available on the bus.      \sa serviceUnregistered(), serviceOwnerChanged() */
end_comment
begin_comment
comment|/*!     \fn void QDBusServiceWatcher::serviceUnregistered(const QString&serviceName)      This signal is emitted whenever this object detects that the service \a     serviceName was unregistered from the bus and is no longer available.      \sa serviceRegistered(), serviceOwnerChanged() */
end_comment
begin_comment
comment|/*!     \fn void QDBusServiceWatcher::serviceOwnerChanged(const QString&serviceName, const QString&oldOwner, const QString&newOwner)      This signal is emitted whenever this object detects that there was a     service ownership change relating to the \a serviceName service. The \a     oldOwner parameter contains the old owner name and \a newOwner is the new     owner. Both \a oldOwner and \a newOwner are unique connection names.      Note that this signal is also emitted whenever the \a serviceName service     was registered or unregistered. If it was registered, \a oldOwner will     contain an empty string, whereas if it was unregistered, \a newOwner will     contain an empty string.      If you need only to find out if the service is registered or unregistered     only, without being notified that the ownership changed, consider using     the specific modes for those operations. This class is more efficient if     you use the more specific modes.      \sa serviceRegistered(), serviceUnregistered() */
end_comment
begin_comment
comment|/*!     Creates a QDBusServiceWatcher object. Note that until you set a     connection with setConnection(), this object will not emit any signals.      The \a parent parameter is passed to QObject to set the parent of this     object. */
end_comment
begin_constructor
DECL|function|QDBusServiceWatcher
name|QDBusServiceWatcher
operator|::
name|QDBusServiceWatcher
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QDBusServiceWatcherPrivate
argument_list|(
name|QDBusConnection
argument_list|(
name|QString
argument_list|()
argument_list|)
argument_list|,
name|WatchForOwnerChange
argument_list|)
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Creates a QDBusServiceWatcher object and attaches it to the \a connection     connection. Also, this function immediately starts watching for \a     watchMode changes to service \a service.      The \a parent parameter is passed to QObject to set the parent of this     object. */
end_comment
begin_constructor
DECL|function|QDBusServiceWatcher
name|QDBusServiceWatcher
operator|::
name|QDBusServiceWatcher
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QDBusConnection
modifier|&
name|connection
parameter_list|,
name|WatchMode
name|watchMode
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QDBusServiceWatcherPrivate
argument_list|(
name|connection
argument_list|,
name|watchMode
argument_list|)
argument_list|,
name|parent
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|setConnection
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|service
argument_list|,
name|connection
argument_list|,
name|watchMode
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the QDBusServiceWatcher object and releases any resources     associated with it. */
end_comment
begin_destructor
DECL|function|~QDBusServiceWatcher
name|QDBusServiceWatcher
operator|::
name|~
name|QDBusServiceWatcher
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Returns the list of D-Bus services that are being watched.      \sa setWatchedServices() */
end_comment
begin_function
DECL|function|watchedServices
name|QStringList
name|QDBusServiceWatcher
operator|::
name|watchedServices
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|servicesWatched
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the list of D-Bus services being watched to be \a services.      Note that setting the entire list means removing all previous rules for     watching services and adding new ones. This is an expensive operation and     should be avoided, if possible. Instead, use addWatchedService() and     removeWatchedService() if you can to manipulate entries in the list. */
end_comment
begin_function
DECL|function|setWatchedServices
name|void
name|QDBusServiceWatcher
operator|::
name|setWatchedServices
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|services
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDBusServiceWatcher
argument_list|)
expr_stmt|;
if|if
condition|(
name|services
operator|==
name|d
operator|->
name|servicesWatched
condition|)
return|return;
name|d
operator|->
name|setConnection
argument_list|(
name|services
argument_list|,
name|d
operator|->
name|connection
argument_list|,
name|d
operator|->
name|watchMode
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Adds \a newService to the list of services to be watched by this object.     This function is more efficient than setWatchedServices() and should be     used whenever possible to add services. */
end_comment
begin_function
DECL|function|addWatchedService
name|void
name|QDBusServiceWatcher
operator|::
name|addWatchedService
parameter_list|(
specifier|const
name|QString
modifier|&
name|newService
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDBusServiceWatcher
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|servicesWatched
operator|.
name|contains
argument_list|(
name|newService
argument_list|)
condition|)
return|return;
name|d
operator|->
name|addService
argument_list|(
name|newService
argument_list|)
expr_stmt|;
name|d
operator|->
name|servicesWatched
operator|<<
name|newService
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Removes the \a service from the list of services being watched by this     object. Note that D-Bus notifications are asynchronous, so there may     still be signals pending delivery about \a service. Those signals will     still be emitted whenever the D-Bus messages are processed.      This function returns \c true if any services were removed. */
end_comment
begin_function
DECL|function|removeWatchedService
name|bool
name|QDBusServiceWatcher
operator|::
name|removeWatchedService
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDBusServiceWatcher
argument_list|)
expr_stmt|;
name|d
operator|->
name|removeService
argument_list|(
name|service
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|servicesWatched
operator|.
name|removeOne
argument_list|(
name|service
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|watchMode
name|QDBusServiceWatcher
operator|::
name|WatchMode
name|QDBusServiceWatcher
operator|::
name|watchMode
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|watchMode
return|;
block|}
end_function
begin_function
DECL|function|setWatchMode
name|void
name|QDBusServiceWatcher
operator|::
name|setWatchMode
parameter_list|(
name|WatchMode
name|mode
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDBusServiceWatcher
argument_list|)
expr_stmt|;
if|if
condition|(
name|mode
operator|==
name|d
operator|->
name|watchMode
condition|)
return|return;
name|d
operator|->
name|setConnection
argument_list|(
name|d
operator|->
name|servicesWatched
argument_list|,
name|d
operator|->
name|connection
argument_list|,
name|mode
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the QDBusConnection that this object is attached to.      \sa setConnection() */
end_comment
begin_function
DECL|function|connection
name|QDBusConnection
name|QDBusServiceWatcher
operator|::
name|connection
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|connection
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the D-Bus connection that this object is attached to be \a     connection. All services watched will be transferred to this connection.      Note that QDBusConnection objects are reference counted:     QDBusServiceWatcher will keep a reference for this connection while it     exists. The connection is not closed until the reference count drops to     zero, so this will ensure that any notifications are received while this     QDBusServiceWatcher object exists.      \sa connection() */
end_comment
begin_function
DECL|function|setConnection
name|void
name|QDBusServiceWatcher
operator|::
name|setConnection
parameter_list|(
specifier|const
name|QDBusConnection
modifier|&
name|connection
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDBusServiceWatcher
argument_list|)
expr_stmt|;
if|if
condition|(
name|connection
operator|.
name|name
argument_list|()
operator|==
name|d
operator|->
name|connection
operator|.
name|name
argument_list|()
condition|)
return|return;
name|d
operator|->
name|setConnection
argument_list|(
name|d
operator|->
name|servicesWatched
argument_list|,
name|connection
argument_list|,
name|d
operator|->
name|watchMode
argument_list|)
expr_stmt|;
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
comment|// QT_NO_DBUS
end_comment
begin_include
include|#
directive|include
file|"moc_qdbusservicewatcher.cpp"
end_include
end_unit
