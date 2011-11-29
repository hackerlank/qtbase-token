begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qthread.h"
end_include
begin_include
include|#
directive|include
file|"qthreadstorage.h"
end_include
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_include
include|#
directive|include
file|"qmutexpool_p.h"
end_include
begin_include
include|#
directive|include
file|"qreadwritelock.h"
end_include
begin_include
include|#
directive|include
file|"qabstracteventdispatcher.h"
end_include
begin_include
include|#
directive|include
file|<qeventloop.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|"qthread_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qcoreapplication_p.h"
end_include
begin_comment
comment|/* #ifdef Q_OS_WIN32 # include "qt_windows.h" #else # include<unistd.h> # include<netinet/in.h> # include<sys/utsname.h> # include<sys/socket.h> */
end_comment
begin_comment
comment|/* #  elif defined(Q_OS_HPUX) #   include<sys/pstat.h> #  elif defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD) || defined(Q_OS_MAC) #   include<sys/sysctl.h> #  endif #endif */
end_comment
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*   QThreadData */
end_comment
begin_constructor
DECL|function|QThreadData
name|QThreadData
operator|::
name|QThreadData
parameter_list|(
name|int
name|initialRefCount
parameter_list|)
member_init_list|:
name|_ref
argument_list|(
name|initialRefCount
argument_list|)
member_init_list|,
name|thread
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|threadId
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|quitNow
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|loopLevel
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|eventDispatcher
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|canWait
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|isAdopted
argument_list|(
literal|false
argument_list|)
block|{
comment|// fprintf(stderr, "QThreadData %p created\n", this);
block|}
end_constructor
begin_destructor
DECL|function|~QThreadData
name|QThreadData
operator|::
name|~
name|QThreadData
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|_ref
operator|.
name|load
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// In the odd case that Qt is running on a secondary thread, the main
comment|// thread instance will have been dereffed asunder because of the deref in
comment|// QThreadData::current() and the deref in the pthread_destroy. To avoid
comment|// crashing during QCoreApplicationData's global static cleanup we need to
comment|// safeguard the main thread here.. This fix is a bit crude, but it solves
comment|// the problem...
if|if
condition|(
name|this
operator|->
name|thread
operator|==
name|QCoreApplicationPrivate
operator|::
name|theMainThread
condition|)
block|{
name|QCoreApplicationPrivate
operator|::
name|theMainThread
operator|=
literal|0
expr_stmt|;
block|}
name|QThread
modifier|*
name|t
init|=
name|thread
decl_stmt|;
name|thread
operator|=
literal|0
expr_stmt|;
operator|delete
name|t
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|postEventList
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QPostEvent
modifier|&
name|pe
init|=
name|postEventList
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|pe
operator|.
name|event
condition|)
block|{
operator|--
name|pe
operator|.
name|receiver
operator|->
name|d_func
argument_list|()
operator|->
name|postedEvents
expr_stmt|;
name|pe
operator|.
name|event
operator|->
name|posted
operator|=
literal|false
expr_stmt|;
operator|delete
name|pe
operator|.
name|event
expr_stmt|;
block|}
block|}
comment|// fprintf(stderr, "QThreadData %p destroyed\n", this);
block|}
end_destructor
begin_function
DECL|function|ref
name|void
name|QThreadData
operator|::
name|ref
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_THREAD
operator|(
name|void
operator|)
name|_ref
operator|.
name|ref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|_ref
operator|.
name|load
argument_list|()
operator|!=
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|deref
name|void
name|QThreadData
operator|::
name|deref
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_THREAD
if|if
condition|(
operator|!
name|_ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|this
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*   QAdoptedThread */
end_comment
begin_constructor
DECL|function|QAdoptedThread
name|QAdoptedThread
operator|::
name|QAdoptedThread
parameter_list|(
name|QThreadData
modifier|*
name|data
parameter_list|)
member_init_list|:
name|QThread
argument_list|(
operator|*
operator|new
name|QThreadPrivate
argument_list|(
name|data
argument_list|)
argument_list|)
block|{
comment|// thread should be running and not finished for the lifetime
comment|// of the application (even if QCoreApplication goes away)
ifndef|#
directive|ifndef
name|QT_NO_THREAD
name|d_func
argument_list|()
operator|->
name|running
operator|=
literal|true
expr_stmt|;
name|d_func
argument_list|()
operator|->
name|finished
operator|=
literal|false
expr_stmt|;
name|init
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|// fprintf(stderr, "new QAdoptedThread = %p\n", this);
block|}
end_constructor
begin_destructor
DECL|function|~QAdoptedThread
name|QAdoptedThread
operator|::
name|~
name|QAdoptedThread
parameter_list|()
block|{
comment|// fprintf(stderr, "~QAdoptedThread = %p\n", this);
block|}
end_destructor
begin_function
DECL|function|run
name|void
name|QAdoptedThread
operator|::
name|run
parameter_list|()
block|{
comment|// this function should never be called
name|qFatal
argument_list|(
literal|"QAdoptedThread::run(): Internal error, this implementation should never be called."
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_comment
comment|/*   QThreadPrivate */
end_comment
begin_constructor
DECL|function|QThreadPrivate
name|QThreadPrivate
operator|::
name|QThreadPrivate
parameter_list|(
name|QThreadData
modifier|*
name|d
parameter_list|)
member_init_list|:
name|QObjectPrivate
argument_list|()
member_init_list|,
name|running
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|finished
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|terminated
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|isInFinish
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|exited
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|returnCode
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|stackSize
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|priority
argument_list|(
name|QThread
operator|::
name|InheritPriority
argument_list|)
member_init_list|,
name|data
argument_list|(
name|d
argument_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
name|thread_id
operator|=
literal|0
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|handle
operator|=
literal|0
expr_stmt|;
name|id
operator|=
literal|0
expr_stmt|;
name|waiters
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|terminationEnabled
operator|=
literal|true
expr_stmt|;
name|terminatePending
operator|=
literal|false
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|data
condition|)
name|data
operator|=
operator|new
name|QThreadData
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QThreadPrivate
name|QThreadPrivate
operator|::
name|~
name|QThreadPrivate
parameter_list|()
block|{
name|data
operator|->
name|deref
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \class QThread     \brief The QThread class provides platform-independent threads.      \ingroup thread      A QThread represents a separate thread of control within the     program; it shares data with all the other threads within the     process but executes independently in the way that a separate     program does on a multitasking operating system. Instead of     starting in \c main(), QThreads begin executing in run().  By     default, run() starts the event loop by calling exec() (see     below). To create your own threads, subclass QThread and     reimplement run(). For example:      \snippet doc/src/snippets/code/src_corelib_thread_qthread.cpp 0      This will create a QTcpSocket in the thread and then execute the     thread's event loop. Use the start() method to begin execution.     Execution ends when you return from run(), just as an application     does when it leaves main(). QThread will notifiy you via a signal     when the thread is started(), finished(), and terminated(), or     you can use isFinished() and isRunning() to query the state of     the thread. Use wait() to block until the thread has finished     execution.      Each thread gets its own stack from the operating system. The     operating system also determines the default size of the stack.     You can use setStackSize() to set a custom stack size.      Each QThread can have its own event loop. You can start the event     loop by calling exec(); you can stop it by calling exit() or     quit(). Having an event loop in a thread makes it possible to     connect signals from other threads to slots in this thread, using     a mechanism called \l{Qt::QueuedConnection}{queued     connections}. It also makes it possible to use classes that     require the event loop, such as QTimer and QTcpSocket, in the     thread. Note, however, that it is not possible to use any widget     classes in the thread.      In extreme cases, you may want to forcibly terminate() an     executing thread. However, doing so is dangerous and discouraged.     Please read the documentation for terminate() and     setTerminationEnabled() for detailed information.      The static functions currentThreadId() and currentThread() return     identifiers for the currently executing thread. The former     returns a platform specific ID for the thread; the latter returns     a QThread pointer.      QThread also provides platform independent sleep functions in     varying resolutions. Use sleep() for full second resolution,     msleep() for millisecond resolution, and usleep() for microsecond     resolution.      \sa {Thread Support in Qt}, QThreadStorage, QMutex, QSemaphore, QWaitCondition,         {Mandelbrot Example}, {Semaphores Example}, {Wait Conditions Example} */
end_comment
begin_comment
comment|/*!     \fn Qt::HANDLE QThread::currentThreadId()      Returns the thread handle of the currently executing thread.      \warning The handle returned by this function is used for internal     purposes and should not be used in any application code.      \warning On Windows, the returned value is a pseudo-handle for the     current thread. It can't be used for numerical comparison. i.e.,     this function returns the DWORD (Windows-Thread ID) returned by     the Win32 function getCurrentThreadId(), not the HANDLE     (Windows-Thread HANDLE) returned by the Win32 function     getCurrentThread(). */
end_comment
begin_comment
comment|/*!     \fn int QThread::idealThreadCount()      Returns the ideal number of threads that can be run on the system. This is done querying     the number of processor cores, both real and logical, in the system. This function returns -1     if the number of processor cores could not be detected. */
end_comment
begin_comment
comment|/*!     \fn void QThread::yieldCurrentThread()      Yields execution of the current thread to another runnable thread,     if any. Note that the operating system decides to which thread to     switch. */
end_comment
begin_comment
comment|/*!     \fn void QThread::start(Priority priority)      Begins execution of the thread by calling run(), which should be     reimplemented in a QThread subclass to contain your code. The     operating system will schedule the thread according to the \a     priority parameter. If the thread is already running, this     function does nothing.      The effect of the \a priority parameter is dependent on the     operating system's scheduling policy. In particular, the \a priority     will be ignored on systems that do not support thread priorities     (such as on Linux, see http://linux.die.net/man/2/sched_setscheduler     for more details).      \sa run(), terminate() */
end_comment
begin_comment
comment|/*!     \fn void QThread::started()      This signal is emitted when the thread starts executing.      \sa finished(), terminated() */
end_comment
begin_comment
comment|/*!     \fn void QThread::finished()      This signal is emitted when the thread has finished executing.      \sa started(), terminated() */
end_comment
begin_comment
comment|/*!     \fn void QThread::terminated()      This signal is emitted when the thread is terminated.      \sa started(), finished() */
end_comment
begin_comment
comment|/*!     \enum QThread::Priority      This enum type indicates how the operating system should schedule     newly created threads.      \value IdlePriority scheduled only when no other threads are            running.      \value LowestPriority scheduled less often than LowPriority.     \value LowPriority scheduled less often than NormalPriority.      \value NormalPriority the default priority of the operating            system.      \value HighPriority scheduled more often than NormalPriority.     \value HighestPriority scheduled more often than HighPriority.      \value TimeCriticalPriority scheduled as often as possible.      \value InheritPriority use the same priority as the creating            thread. This is the default. */
end_comment
begin_comment
comment|/*!     Returns a pointer to a QThread which represents the currently     executing thread. */
end_comment
begin_function
DECL|function|currentThread
name|QThread
modifier|*
name|QThread
operator|::
name|currentThread
parameter_list|()
block|{
name|QThreadData
modifier|*
name|data
init|=
name|QThreadData
operator|::
name|current
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|data
operator|!=
literal|0
argument_list|)
expr_stmt|;
return|return
name|data
operator|->
name|thread
return|;
block|}
end_function
begin_comment
comment|/*!     Constructs a new thread with the given \a parent. The thread does     not begin executing until start() is called.      \sa start() */
end_comment
begin_constructor
DECL|function|QThread
name|QThread
operator|::
name|QThread
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|(
operator|new
name|QThreadPrivate
operator|)
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QThread
argument_list|)
expr_stmt|;
comment|// fprintf(stderr, "QThreadData %p created for thread %p\n", d->data, this);
name|d
operator|->
name|data
operator|->
name|thread
operator|=
name|this
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*! \internal  */
end_comment
begin_constructor
DECL|function|QThread
name|QThread
operator|::
name|QThread
parameter_list|(
name|QThreadPrivate
modifier|&
name|dd
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QThread
argument_list|)
expr_stmt|;
comment|// fprintf(stderr, "QThreadData %p taken from private data for thread %p\n", d->data, this);
name|d
operator|->
name|data
operator|->
name|thread
operator|=
name|this
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the thread.      Note that deleting a QThread object will not stop the execution     of the thread it represents. Deleting a running QThread (i.e.     isFinished() returns false) will probably result in a program     crash. You can wait() on a thread to make sure that it has     finished. */
end_comment
begin_destructor
DECL|function|~QThread
name|QThread
operator|::
name|~
name|QThread
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QThread
argument_list|)
expr_stmt|;
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|isInFinish
condition|)
block|{
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|wait
argument_list|()
expr_stmt|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|d
operator|->
name|running
operator|&&
operator|!
name|d
operator|->
name|finished
operator|&&
operator|!
name|d
operator|->
name|data
operator|->
name|isAdopted
condition|)
name|qWarning
argument_list|(
literal|"QThread: Destroyed while thread is still running"
argument_list|)
expr_stmt|;
name|d
operator|->
name|data
operator|->
name|thread
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_destructor
begin_comment
comment|/*!     Returns true if the thread is finished; otherwise returns false.      \sa isRunning() */
end_comment
begin_function
DECL|function|isFinished
name|bool
name|QThread
operator|::
name|isFinished
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QThread
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|finished
operator|||
name|d
operator|->
name|isInFinish
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the thread is running; otherwise returns false.      \sa isFinished() */
end_comment
begin_function
DECL|function|isRunning
name|bool
name|QThread
operator|::
name|isRunning
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QThread
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|running
operator|&&
operator|!
name|d
operator|->
name|isInFinish
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the maximum stack size for the thread to \a stackSize. If \a     stackSize is greater than zero, the maximum stack size is set to     \a stackSize bytes, otherwise the maximum stack size is     automatically determined by the operating system.      \warning Most operating systems place minimum and maximum limits     on thread stack sizes. The thread will fail to start if the stack     size is outside these limits.      \sa stackSize() */
end_comment
begin_function
DECL|function|setStackSize
name|void
name|QThread
operator|::
name|setStackSize
parameter_list|(
name|uint
name|stackSize
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QThread
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|Q_ASSERT_X
argument_list|(
operator|!
name|d
operator|->
name|running
argument_list|,
literal|"QThread::setStackSize"
argument_list|,
literal|"cannot change stack size while the thread is running"
argument_list|)
expr_stmt|;
name|d
operator|->
name|stackSize
operator|=
name|stackSize
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the maximum stack size for the thread (if set with     setStackSize()); otherwise returns zero.      \sa setStackSize() */
end_comment
begin_function
DECL|function|stackSize
name|uint
name|QThread
operator|::
name|stackSize
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QThread
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|stackSize
return|;
block|}
end_function
begin_comment
comment|/*!     Enters the event loop and waits until exit() is called, returning the value     that was passed to exit(). The value returned is 0 if exit() is called via     quit().      It is necessary to call this function to start event handling.      \sa quit(), exit() */
end_comment
begin_function
DECL|function|exec
name|int
name|QThread
operator|::
name|exec
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QThread
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|d
operator|->
name|data
operator|->
name|quitNow
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|exited
condition|)
block|{
name|d
operator|->
name|exited
operator|=
literal|false
expr_stmt|;
return|return
name|d
operator|->
name|returnCode
return|;
block|}
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|QEventLoop
name|eventLoop
decl_stmt|;
name|int
name|returnCode
init|=
name|eventLoop
operator|.
name|exec
argument_list|()
decl_stmt|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
name|d
operator|->
name|exited
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|returnCode
operator|=
operator|-
literal|1
expr_stmt|;
return|return
name|returnCode
return|;
block|}
end_function
begin_comment
comment|/*!     Tells the thread's event loop to exit with a return code.      After calling this function, the thread leaves the event loop and     returns from the call to QEventLoop::exec(). The     QEventLoop::exec() function returns \a returnCode.      By convention, a \a returnCode of 0 means success, any non-zero value     indicates an error.      Note that unlike the C library function of the same name, this     function \e does return to the caller -- it is event processing     that stops.           No QEventLoops will be started anymore in this thread  until      QThread::exec() has been called again. If the eventloop in QThread::exec()     is not running then the next call to QThread::exec() will also return     immediately.      \sa quit() QEventLoop */
end_comment
begin_function
DECL|function|exit
name|void
name|QThread
operator|::
name|exit
parameter_list|(
name|int
name|returnCode
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QThread
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|d
operator|->
name|exited
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|returnCode
operator|=
name|returnCode
expr_stmt|;
name|d
operator|->
name|data
operator|->
name|quitNow
operator|=
literal|true
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|d
operator|->
name|data
operator|->
name|eventLoops
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QEventLoop
modifier|*
name|eventLoop
init|=
name|d
operator|->
name|data
operator|->
name|eventLoops
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|eventLoop
operator|->
name|exit
argument_list|(
name|returnCode
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Tells the thread's event loop to exit with return code 0 (success).     Equivalent to calling QThread::exit(0).      This function does nothing if the thread does not have an event     loop.      \sa exit() QEventLoop */
end_comment
begin_function
DECL|function|quit
name|void
name|QThread
operator|::
name|quit
parameter_list|()
block|{
name|exit
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     The starting point for the thread. After calling start(), the     newly created thread calls this function. The default     implementation simply calls exec().      You can reimplemented this function to do other useful     work. Returning from this method will end the execution of the     thread.      \sa start() wait() */
end_comment
begin_function
DECL|function|run
name|void
name|QThread
operator|::
name|run
parameter_list|()
block|{
operator|(
name|void
operator|)
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal     Initializes the QThread system. */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_function_decl
name|void
name|qt_create_tls
parameter_list|()
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|initialize
name|void
name|QThread
operator|::
name|initialize
parameter_list|()
block|{
if|if
condition|(
name|qt_global_mutexpool
condition|)
return|return;
name|qt_global_mutexpool
operator|=
name|QMutexPool
operator|::
name|instance
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|qt_create_tls
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*! \internal     Cleans up the QThread system. */
end_comment
begin_function
DECL|function|cleanup
name|void
name|QThread
operator|::
name|cleanup
parameter_list|()
block|{
name|qt_global_mutexpool
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \fn void QThread::setPriority(Priority priority)     \since 4.1      This function sets the \a priority for a running thread. If the     thread is not running, this function does nothing and returns     immediately.  Use start() to start a thread with a specific     priority.      The \a priority argument can be any value in the \c     QThread::Priority enum except for \c InheritPriorty.      The effect of the \a priority parameter is dependent on the     operating system's scheduling policy. In particular, the \a priority     will be ignored on systems that do not support thread priorities     (such as on Linux, see http://linux.die.net/man/2/sched_setscheduler     for more details).      \sa Priority priority() start() */
end_comment
begin_comment
comment|/*!     \since 4.1      Returns the priority for a running thread.  If the thread is not     running, this function returns \c InheritPriority.      \sa Priority setPriority() start() */
end_comment
begin_function
DECL|function|priority
name|QThread
operator|::
name|Priority
name|QThread
operator|::
name|priority
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QThread
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
comment|// mask off the high bits that are used for flags
return|return
name|Priority
argument_list|(
name|d
operator|->
name|priority
operator|&
literal|0xffff
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QThread::sleep(unsigned long secs)      Forces the current thread to sleep for \a secs seconds.      \sa msleep(), usleep() */
end_comment
begin_comment
comment|/*!     \fn void QThread::msleep(unsigned long msecs)      Causes the current thread to sleep for \a msecs milliseconds.      \sa sleep(), usleep() */
end_comment
begin_comment
comment|/*!     \fn void QThread::usleep(unsigned long usecs)      Causes the current thread to sleep for \a usecs microseconds.      \sa sleep(), msleep() */
end_comment
begin_comment
comment|/*!     \fn void QThread::terminate()      Terminates the execution of the thread. The thread may or may not     be terminated immediately, depending on the operating systems     scheduling policies. Use QThread::wait() after terminate() for     synchronous termination.      When the thread is terminated, all threads waiting for the thread     to finish will be woken up.      \warning This function is dangerous and its use is discouraged.     The thread can be terminated at any point in its code path.     Threads can be terminated while modifying data. There is no     chance for the thread to clean up after itself, unlock any held     mutexes, etc. In short, use this function only if absolutely     necessary.      Termination can be explicitly enabled or disabled by calling     QThread::setTerminationEnabled(). Calling this function while     termination is disabled results in the termination being     deferred, until termination is re-enabled. See the documentation     of QThread::setTerminationEnabled() for more information.      \sa setTerminationEnabled() */
end_comment
begin_comment
comment|/*!     \fn bool QThread::wait(unsigned long time)      Blocks the thread until either of these conditions is met:      \list     \o The thread associated with this QThread object has finished        execution (i.e. when it returns from \l{run()}). This function        will return true if the thread has finished. It also returns        true if the thread has not been started yet.     \o \a time milliseconds has elapsed. If \a time is ULONG_MAX (the         default), then the wait will never timeout (the thread must         return from \l{run()}). This function will return false if the         wait timed out.     \endlist      This provides similar functionality to the POSIX \c     pthread_join() function.      \sa sleep(), terminate() */
end_comment
begin_comment
comment|/*!     \fn void QThread::setTerminationEnabled(bool enabled)      Enables or disables termination of the current thread based on the     \a enabled parameter. The thread must have been started by     QThread.      When \a enabled is false, termination is disabled.  Future calls     to QThread::terminate() will return immediately without effect.     Instead, the termination is deferred until termination is enabled.      When \a enabled is true, termination is enabled.  Future calls to     QThread::terminate() will terminate the thread normally.  If     termination has been deferred (i.e. QThread::terminate() was     called with termination disabled), this function will terminate     the calling thread \e immediately.  Note that this function will     not return in this case.      \sa terminate() */
end_comment
begin_else
else|#
directive|else
end_else
begin_comment
comment|// QT_NO_THREAD
end_comment
begin_constructor
DECL|function|QThread
name|QThread
operator|::
name|QThread
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|(
operator|new
name|QThreadPrivate
operator|)
argument_list|,
operator|(
name|QObject
operator|*
operator|)
literal|0
argument_list|)
block|{
name|Q_D
argument_list|(
name|QThread
argument_list|)
expr_stmt|;
name|d
operator|->
name|data
operator|->
name|thread
operator|=
name|this
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|currentThread
name|QThread
modifier|*
name|QThread
operator|::
name|currentThread
parameter_list|()
block|{
return|return
name|QThreadData
operator|::
name|current
argument_list|()
operator|->
name|thread
return|;
block|}
end_function
begin_function
DECL|function|current
name|QThreadData
modifier|*
name|QThreadData
operator|::
name|current
parameter_list|()
block|{
specifier|static
name|QThreadData
modifier|*
name|data
init|=
literal|0
decl_stmt|;
comment|// reinterpret_cast<QThreadData *>(pthread_getspecific(current_thread_data_key));
if|if
condition|(
operator|!
name|data
condition|)
block|{
name|QScopedPointer
argument_list|<
name|QThreadData
argument_list|>
name|newdata
argument_list|(
operator|new
name|QThreadData
argument_list|)
decl_stmt|;
name|newdata
operator|->
name|thread
operator|=
operator|new
name|QAdoptedThread
argument_list|(
name|newdata
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|data
operator|=
name|newdata
operator|.
name|take
argument_list|()
expr_stmt|;
name|data
operator|->
name|deref
argument_list|()
expr_stmt|;
block|}
return|return
name|data
return|;
block|}
end_function
begin_comment
comment|/*! \internal  */
end_comment
begin_constructor
DECL|function|QThread
name|QThread
operator|::
name|QThread
parameter_list|(
name|QThreadPrivate
modifier|&
name|dd
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QThread
argument_list|)
expr_stmt|;
comment|// fprintf(stderr, "QThreadData %p taken from private data for thread %p\n", d->data, this);
name|d
operator|->
name|data
operator|->
name|thread
operator|=
name|this
expr_stmt|;
block|}
end_constructor
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_THREAD
end_comment
begin_comment
comment|/*!     Returns a pointer to the event dispatcher object for the thread. If no event     dispatcher exists for the thread, this function returns 0. */
end_comment
begin_function
DECL|function|eventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QThread
operator|::
name|eventDispatcher
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QThread
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|data
operator|->
name|eventDispatcher
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the event dispatcher for the thread to \a eventDispatcher. This is     only possible as long as there is no event dispatcher installed for the     thread yet. That is, before the thread has been started with start() or, in     case of the main thread, before QCoreApplication has been instantiated.     This method takes ownership of the object. */
end_comment
begin_function
DECL|function|setEventDispatcher
name|void
name|QThread
operator|::
name|setEventDispatcher
parameter_list|(
name|QAbstractEventDispatcher
modifier|*
name|eventDispatcher
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QThread
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|data
operator|->
name|eventDispatcher
operator|!=
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QThread::setEventDispatcher: An event dispatcher has already been created for this thread"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|eventDispatcher
operator|->
name|moveToThread
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|eventDispatcher
operator|->
name|thread
argument_list|()
operator|==
name|this
condition|)
comment|// was the move successful?
name|d
operator|->
name|data
operator|->
name|eventDispatcher
operator|=
name|eventDispatcher
expr_stmt|;
else|else
name|qWarning
argument_list|(
literal|"QThread::setEventDispatcher: Could not move event dispatcher to target thread"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
