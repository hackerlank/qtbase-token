begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeventloop.h"
end_include
begin_include
include|#
directive|include
file|"qabstracteventdispatcher.h"
end_include
begin_include
include|#
directive|include
file|"qcoreapplication.h"
end_include
begin_include
include|#
directive|include
file|"qelapsedtimer.h"
end_include
begin_include
include|#
directive|include
file|"qobject_p.h"
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
DECL|class|QEventLoopPrivate
class|class
name|QEventLoopPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QEventLoop
parameter_list|)
specifier|public
private|:
DECL|function|QEventLoopPrivate
specifier|inline
name|QEventLoopPrivate
parameter_list|()
member_init_list|:
name|exit
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|inExec
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|returnCode
argument_list|(
operator|-
literal|1
argument_list|)
block|{ }
DECL|member|exit
DECL|member|inExec
name|bool
name|exit
decl_stmt|,
name|inExec
decl_stmt|;
DECL|member|returnCode
name|int
name|returnCode
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \class QEventLoop     \brief The QEventLoop class provides a means of entering and leaving an event loop.      At any time, you can create a QEventLoop object and call exec()     on it to start a local event loop. From within the event loop,     calling exit() will force exec() to return.      \sa QAbstractEventDispatcher */
end_comment
begin_comment
comment|/*!     \enum QEventLoop::ProcessEventsFlag      This enum controls the types of events processed by the     processEvents() functions.      \value AllEvents All events. Note that     \l{QEvent::DeferredDelete}{DeferredDelete} events are processed     specially. See QObject::deleteLater() for more details.      \value ExcludeUserInputEvents Do not process user input events,     such as ButtonPress and KeyPress. Note that the events are not     discarded; they will be delivered the next time processEvents() is     called without the ExcludeUserInputEvents flag.      \value ExcludeSocketNotifiers Do not process socket notifier     events. Note that the events are not discarded; they will be     delivered the next time processEvents() is called without the     ExcludeSocketNotifiers flag.      \value WaitForMoreEvents Wait for events if no pending events are     available.      \omitvalue X11ExcludeTimers     \omitvalue EventLoopExec     \omitvalue DialogExec      \sa processEvents() */
end_comment
begin_comment
comment|/*!     Constructs an event loop object with the given \a parent. */
end_comment
begin_constructor
DECL|function|QEventLoop
name|QEventLoop
operator|::
name|QEventLoop
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
name|QEventLoopPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QEventLoop
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QCoreApplication
operator|::
name|instance
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventLoop: Cannot be used without QApplication"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|d
operator|->
name|threadData
operator|->
name|eventDispatcher
condition|)
block|{
name|QThreadPrivate
operator|::
name|createEventDispatcher
argument_list|(
name|d
operator|->
name|threadData
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_comment
comment|/*!     Destroys the event loop object. */
end_comment
begin_destructor
DECL|function|~QEventLoop
name|QEventLoop
operator|::
name|~
name|QEventLoop
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Processes pending events that match \a flags until there are no     more events to process. Returns true if pending events were handled;     otherwise returns false.      This function is especially useful if you have a long running     operation and want to show its progress without allowing user     input; i.e. by using the \l ExcludeUserInputEvents flag.      This function is simply a wrapper for     QAbstractEventDispatcher::processEvents(). See the documentation     for that function for details. */
end_comment
begin_function
DECL|function|processEvents
name|bool
name|QEventLoop
operator|::
name|processEvents
parameter_list|(
name|ProcessEventsFlags
name|flags
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QEventLoop
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|threadData
operator|->
name|eventDispatcher
condition|)
return|return
literal|false
return|;
return|return
name|d
operator|->
name|threadData
operator|->
name|eventDispatcher
operator|->
name|processEvents
argument_list|(
name|flags
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Enters the main event loop and waits until exit() is called.     Returns the value that was passed to exit().      If \a flags are specified, only events of the types allowed by     the \a flags will be processed.      It is necessary to call this function to start event handling. The     main event loop receives events from the window system and     dispatches these to the application widgets.      Generally speaking, no user interaction can take place before     calling exec(). As a special case, modal widgets like QMessageBox     can be used before calling exec(), because modal widgets     use their own local event loop.      To make your application perform idle processing (i.e. executing a     special function whenever there are no pending events), use a     QTimer with 0 timeout. More sophisticated idle processing schemes     can be achieved using processEvents().      \sa QApplication::quit(), exit(), processEvents() */
end_comment
begin_function
DECL|function|exec
name|int
name|QEventLoop
operator|::
name|exec
parameter_list|(
name|ProcessEventsFlags
name|flags
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QEventLoop
argument_list|)
expr_stmt|;
comment|//we need to protect from race condition with QThread::exit
name|QMutexLocker
name|locker
argument_list|(
operator|&
cast|static_cast
argument_list|<
name|QThreadPrivate
operator|*
argument_list|>
argument_list|(
name|QObjectPrivate
operator|::
name|get
argument_list|(
name|d
operator|->
name|threadData
operator|->
name|thread
argument_list|)
argument_list|)
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|threadData
operator|->
name|quitNow
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
name|d
operator|->
name|inExec
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventLoop::exec: instance %p has already called exec()"
argument_list|,
name|this
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
struct|struct
name|LoopReference
block|{
name|QEventLoopPrivate
modifier|*
name|d
decl_stmt|;
name|QMutexLocker
modifier|&
name|locker
decl_stmt|;
name|bool
name|exceptionCaught
decl_stmt|;
name|LoopReference
parameter_list|(
name|QEventLoopPrivate
modifier|*
name|d
parameter_list|,
name|QMutexLocker
modifier|&
name|locker
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|d
argument_list|)
member_init_list|,
name|locker
argument_list|(
name|locker
argument_list|)
member_init_list|,
name|exceptionCaught
argument_list|(
literal|true
argument_list|)
block|{
name|d
operator|->
name|inExec
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|exit
operator|=
literal|false
expr_stmt|;
operator|++
name|d
operator|->
name|threadData
operator|->
name|loopLevel
expr_stmt|;
name|d
operator|->
name|threadData
operator|->
name|eventLoops
operator|.
name|push
argument_list|(
name|d
operator|->
name|q_func
argument_list|()
argument_list|)
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
name|~
name|LoopReference
parameter_list|()
block|{
if|if
condition|(
name|exceptionCaught
condition|)
block|{
name|qWarning
argument_list|(
literal|"Qt has caught an exception thrown from an event handler. Throwing\n"
literal|"exceptions from an event handler is not supported in Qt. You must\n"
literal|"reimplement QApplication::notify() and catch all exceptions there.\n"
argument_list|)
expr_stmt|;
block|}
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
name|QEventLoop
modifier|*
name|eventLoop
init|=
name|d
operator|->
name|threadData
operator|->
name|eventLoops
operator|.
name|pop
argument_list|()
decl_stmt|;
name|Q_ASSERT_X
argument_list|(
name|eventLoop
operator|==
name|d
operator|->
name|q_func
argument_list|()
argument_list|,
literal|"QEventLoop::exec()"
argument_list|,
literal|"internal error"
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|eventLoop
argument_list|)
expr_stmt|;
comment|// --release warning
name|d
operator|->
name|inExec
operator|=
literal|false
expr_stmt|;
operator|--
name|d
operator|->
name|threadData
operator|->
name|loopLevel
expr_stmt|;
block|}
block|}
struct|;
name|LoopReference
name|ref
argument_list|(
name|d
argument_list|,
name|locker
argument_list|)
decl_stmt|;
comment|// remove posted quit events when entering a new event loop
name|QCoreApplication
modifier|*
name|app
init|=
name|QCoreApplication
operator|::
name|instance
argument_list|()
decl_stmt|;
if|if
condition|(
name|app
operator|&&
name|app
operator|->
name|thread
argument_list|()
operator|==
name|thread
argument_list|()
condition|)
name|QCoreApplication
operator|::
name|removePostedEvents
argument_list|(
name|app
argument_list|,
name|QEvent
operator|::
name|Quit
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|d
operator|->
name|exit
condition|)
name|processEvents
argument_list|(
name|flags
operator||
name|WaitForMoreEvents
operator||
name|EventLoopExec
argument_list|)
expr_stmt|;
name|ref
operator|.
name|exceptionCaught
operator|=
literal|false
expr_stmt|;
return|return
name|d
operator|->
name|returnCode
return|;
block|}
end_function
begin_comment
comment|/*!     Process pending events that match \a flags for a maximum of \a     maxTime milliseconds, or until there are no more events to     process, whichever is shorter.     This function is especially useful if you have a long running     operation and want to show its progress without allowing user     input, i.e. by using the \l ExcludeUserInputEvents flag.      \bold{Notes:}     \list     \o This function does not process events continuously; it        returns after all available events are processed.     \o Specifying the \l WaitForMoreEvents flag makes no sense        and will be ignored.     \endlist */
end_comment
begin_function
DECL|function|processEvents
name|void
name|QEventLoop
operator|::
name|processEvents
parameter_list|(
name|ProcessEventsFlags
name|flags
parameter_list|,
name|int
name|maxTime
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QEventLoop
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|threadData
operator|->
name|eventDispatcher
condition|)
return|return;
name|QElapsedTimer
name|start
decl_stmt|;
name|start
operator|.
name|start
parameter_list|()
constructor_decl|;
while|while
condition|(
name|processEvents
argument_list|(
name|flags
operator|&
operator|~
name|WaitForMoreEvents
argument_list|)
condition|)
block|{
if|if
condition|(
name|start
operator|.
name|elapsed
argument_list|()
operator|>
name|maxTime
condition|)
break|break;
block|}
block|}
end_function
begin_comment
comment|/*!     Tells the event loop to exit with a return code.      After this function has been called, the event loop returns from     the call to exec(). The exec() function returns \a returnCode.      By convention, a \a returnCode of 0 means success, and any non-zero     value indicates an error.      Note that unlike the C library function of the same name, this     function \e does return to the caller -- it is event processing that     stops.      \sa QCoreApplication::quit(), quit(), exec() */
end_comment
begin_function
DECL|function|exit
name|void
name|QEventLoop
operator|::
name|exit
parameter_list|(
name|int
name|returnCode
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QEventLoop
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|threadData
operator|->
name|eventDispatcher
condition|)
return|return;
name|d
operator|->
name|returnCode
operator|=
name|returnCode
expr_stmt|;
name|d
operator|->
name|exit
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|threadData
operator|->
name|eventDispatcher
operator|->
name|interrupt
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the event loop is running; otherwise returns     false. The event loop is considered running from the time when     exec() is called until exit() is called.      \sa exec() exit()  */
end_comment
begin_function
DECL|function|isRunning
name|bool
name|QEventLoop
operator|::
name|isRunning
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QEventLoop
argument_list|)
expr_stmt|;
return|return
operator|!
name|d
operator|->
name|exit
return|;
block|}
end_function
begin_comment
comment|/*!     Wakes up the event loop.      \sa QAbstractEventDispatcher::wakeUp() */
end_comment
begin_function
DECL|function|wakeUp
name|void
name|QEventLoop
operator|::
name|wakeUp
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QEventLoop
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|threadData
operator|->
name|eventDispatcher
condition|)
return|return;
name|d
operator|->
name|threadData
operator|->
name|eventDispatcher
operator|->
name|wakeUp
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Tells the event loop to exit normally.      Same as exit(0).      \sa QCoreApplication::quit(), exit() */
end_comment
begin_function
DECL|function|quit
name|void
name|QEventLoop
operator|::
name|quit
parameter_list|()
block|{
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
