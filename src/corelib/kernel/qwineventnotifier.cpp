begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwineventnotifier.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINRT
end_ifdef
begin_include
include|#
directive|include
file|"qeventdispatcher_winrt_p.h"
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"qeventdispatcher_win_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qcoreapplication.h"
end_include
begin_include
include|#
directive|include
file|<private/qthread_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QWinEventNotifierPrivate
class|class
name|QWinEventNotifierPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QWinEventNotifier
parameter_list|)
specifier|public
private|:
DECL|function|QWinEventNotifierPrivate
name|QWinEventNotifierPrivate
parameter_list|()
member_init_list|:
name|handleToEvent
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|enabled
argument_list|(
literal|false
argument_list|)
block|{}
DECL|function|QWinEventNotifierPrivate
name|QWinEventNotifierPrivate
parameter_list|(
name|HANDLE
name|h
parameter_list|,
name|bool
name|e
parameter_list|)
member_init_list|:
name|handleToEvent
argument_list|(
name|h
argument_list|)
member_init_list|,
name|enabled
argument_list|(
name|e
argument_list|)
block|{}
DECL|member|handleToEvent
name|HANDLE
name|handleToEvent
decl_stmt|;
DECL|member|enabled
name|bool
name|enabled
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \class QWinEventNotifier     \inmodule QtCore     \since 5.0     \brief The QWinEventNotifier class provides support for the Windows Wait functions.      The QWinEventNotifier class makes it possible to use the wait     functions on windows in a asynchronous manner. With this class,     you can register a HANDLE to an event and get notification when     that event becomes signalled. The state of the event is not modified     in the process so if it is a manual reset event you will need to     reset it after the notification.      Once you have created a event object using Windows API such as     CreateEvent() or OpenEvent(), you can create an event notifier to     monitor the event handle. If the event notifier is enabled, it will     emit the activated() signal whenever the corresponding event object     is signalled.      The setEnabled() function allows you to disable as well as enable the     event notifier. It is generally advisable to explicitly enable or     disable the event notifier. A disabled notifier does nothing when the     event object is signalled (the same effect as not creating the     event notifier).  Use the isEnabled() function to determine the     notifier's current status.      Finally, you can use the setHandle() function to register a new event     object, and the handle() function to retrieve the event handle.      \b{Further information:}     Although the class is called QWinEventNotifier, it can be used for     certain other objects which are so-called synchronization     objects, such as Processes, Threads, Waitable timers.      \warning This class is only available on Windows. */
end_comment
begin_comment
comment|/*!     \fn void QWinEventNotifier::activated(HANDLE hEvent)      This signal is emitted whenever the event notifier is enabled and     the corresponding HANDLE is signalled.      The state of the event is not modified in the process, so if it is a     manual reset event, you will need to reset it after the notification.      The object is passed in the \a hEvent parameter.      \sa handle() */
end_comment
begin_comment
comment|/*!     Constructs an event notifier with the given \a parent. */
end_comment
begin_constructor
DECL|function|QWinEventNotifier
name|QWinEventNotifier
operator|::
name|QWinEventNotifier
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
name|QWinEventNotifierPrivate
argument_list|,
name|parent
argument_list|)
block|{}
end_constructor
begin_comment
comment|/*!     Constructs an event notifier with the given \a parent. It enables     the notifier, and watches for the event \a hEvent.      The notifier is enabled by default, i.e. it emits the activated() signal     whenever the corresponding event is signalled. However, it is generally     advisable to explicitly enable or disable the event notifier.      \sa setEnabled(), isEnabled() */
end_comment
begin_constructor
DECL|function|QWinEventNotifier
name|QWinEventNotifier
operator|::
name|QWinEventNotifier
parameter_list|(
name|HANDLE
name|hEvent
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
name|QWinEventNotifierPrivate
argument_list|(
name|hEvent
argument_list|,
literal|false
argument_list|)
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QWinEventNotifier
argument_list|)
expr_stmt|;
name|QAbstractEventDispatcher
modifier|*
name|eventDispatcher
init|=
name|d
operator|->
name|threadData
operator|->
name|eventDispatcher
operator|.
name|load
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|eventDispatcher
condition|)
block|{
name|qWarning
argument_list|(
literal|"QWinEventNotifier: Can only be used with threads started with QThread"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|eventDispatcher
operator|->
name|registerEventNotifier
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|enabled
operator|=
literal|true
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys this notifier. */
end_comment
begin_destructor
DECL|function|~QWinEventNotifier
name|QWinEventNotifier
operator|::
name|~
name|QWinEventNotifier
parameter_list|()
block|{
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Register the HANDLE \a hEvent. The old HANDLE will be automatically     unregistered.      \b Note: The notifier will be disabled as a side effect and needs     to be re-enabled.      \sa handle(), setEnabled() */
end_comment
begin_function
DECL|function|setHandle
name|void
name|QWinEventNotifier
operator|::
name|setHandle
parameter_list|(
name|HANDLE
name|hEvent
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinEventNotifier
argument_list|)
expr_stmt|;
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|d
operator|->
name|handleToEvent
operator|=
name|hEvent
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the HANDLE that has been registered in the notifier.      \sa setHandle() */
end_comment
begin_function
DECL|function|handle
name|HANDLE
name|QWinEventNotifier
operator|::
name|handle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinEventNotifier
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|handleToEvent
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the notifier is enabled; otherwise returns false.      \sa setEnabled() */
end_comment
begin_function
DECL|function|isEnabled
name|bool
name|QWinEventNotifier
operator|::
name|isEnabled
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinEventNotifier
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|enabled
return|;
block|}
end_function
begin_comment
comment|/*!     If \a enable is true, the notifier is enabled; otherwise the notifier     is disabled.      \sa isEnabled(), activated() */
end_comment
begin_function
DECL|function|setEnabled
name|void
name|QWinEventNotifier
operator|::
name|setEnabled
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinEventNotifier
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|enabled
operator|==
name|enable
condition|)
comment|// no change
return|return;
name|d
operator|->
name|enabled
operator|=
name|enable
expr_stmt|;
name|QAbstractEventDispatcher
modifier|*
name|eventDispatcher
init|=
name|d
operator|->
name|threadData
operator|->
name|eventDispatcher
operator|.
name|load
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|eventDispatcher
condition|)
comment|// perhaps application is shutting down
return|return;
if|if
condition|(
name|enable
condition|)
name|eventDispatcher
operator|->
name|registerEventNotifier
argument_list|(
name|this
argument_list|)
expr_stmt|;
else|else
name|eventDispatcher
operator|->
name|unregisterEventNotifier
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QWinEventNotifier
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinEventNotifier
argument_list|)
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|ThreadChange
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|enabled
condition|)
block|{
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"setEnabled"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|,
name|Q_ARG
argument_list|(
name|bool
argument_list|,
literal|true
argument_list|)
argument_list|)
expr_stmt|;
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
name|QObject
operator|::
name|event
argument_list|(
name|e
argument_list|)
expr_stmt|;
comment|// will activate filters
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|WinEventAct
condition|)
block|{
emit|emit
name|activated
argument_list|(
name|d
operator|->
name|handleToEvent
argument_list|,
name|QPrivateSignal
argument_list|()
argument_list|)
emit|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
