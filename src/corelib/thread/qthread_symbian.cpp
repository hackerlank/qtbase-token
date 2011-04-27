begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qthread.h"
end_include
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|<private/qcoreapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qeventdispatcher_symbian_p.h>
end_include
begin_include
include|#
directive|include
file|"qthreadstorage.h"
end_include
begin_include
include|#
directive|include
file|"qthread_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qsystemerror_p.h>
end_include
begin_include
include|#
directive|include
file|<sched.h>
end_include
begin_include
include|#
directive|include
file|<hal.h>
end_include
begin_include
include|#
directive|include
file|<hal_data.h>
end_include
begin_comment
comment|// You only find these enumerations on Symbian^3 onwards, so we need to provide our own
end_comment
begin_comment
comment|// to remain compatible with older releases. They won't be called by pre-Sym^3 SDKs.
end_comment
begin_comment
comment|// HALData::ENumCpus
end_comment
begin_define
DECL|macro|QT_HALData_ENumCpus
define|#
directive|define
name|QT_HALData_ENumCpus
value|119
end_define
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_THREAD
DECL|enumerator|ThreadPriorityResetFlag
name|enum
type|{
name|ThreadPriorityResetFlag
init|=
literal|0x80000000
end_decl_stmt
begin_comment
unit|};
comment|// Utility functions for getting, setting and clearing thread specific data.
end_comment
begin_function
DECL|function|get_thread_data
specifier|static
name|QThreadData
modifier|*
name|get_thread_data
parameter_list|()
block|{
return|return
cast|reinterpret_cast
argument_list|<
name|QThreadData
operator|*
argument_list|>
argument_list|(
name|Dll
operator|::
name|Tls
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|set_thread_data
specifier|static
name|void
name|set_thread_data
parameter_list|(
name|QThreadData
modifier|*
name|data
parameter_list|)
block|{
name|qt_symbian_throwIfError
argument_list|(
name|Dll
operator|::
name|SetTls
argument_list|(
name|data
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clear_thread_data
specifier|static
name|void
name|clear_thread_data
parameter_list|()
block|{
name|Dll
operator|::
name|FreeTls
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init_symbian_thread_handle
specifier|static
name|void
name|init_symbian_thread_handle
parameter_list|(
name|RThread
modifier|&
name|thread
parameter_list|)
block|{
name|thread
operator|=
name|RThread
argument_list|()
expr_stmt|;
name|TThreadId
name|threadId
init|=
name|thread
operator|.
name|Id
argument_list|()
decl_stmt|;
name|qt_symbian_throwIfError
argument_list|(
name|thread
operator|.
name|Open
argument_list|(
name|threadId
argument_list|,
name|EOwnerProcess
argument_list|)
argument_list|)
expr_stmt|;
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
name|QThreadData
modifier|*
name|data
init|=
name|get_thread_data
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|data
condition|)
block|{
name|void
modifier|*
name|a
decl_stmt|;
if|if
condition|(
name|QInternal
operator|::
name|activateCallbacks
argument_list|(
name|QInternal
operator|::
name|AdoptCurrentThread
argument_list|,
operator|&
name|a
argument_list|)
condition|)
block|{
name|QThread
modifier|*
name|adopted
init|=
cast|static_cast
argument_list|<
name|QThread
operator|*
argument_list|>
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|adopted
argument_list|)
expr_stmt|;
name|data
operator|=
name|QThreadData
operator|::
name|get2
argument_list|(
name|adopted
argument_list|)
expr_stmt|;
name|set_thread_data
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|adopted
operator|->
name|d_func
argument_list|()
operator|->
name|running
operator|=
literal|true
expr_stmt|;
name|adopted
operator|->
name|d_func
argument_list|()
operator|->
name|finished
operator|=
literal|false
expr_stmt|;
cast|static_cast
argument_list|<
name|QAdoptedThread
operator|*
argument_list|>
argument_list|(
name|adopted
argument_list|)
operator|->
name|init
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|data
operator|=
operator|new
name|QThreadData
expr_stmt|;
name|QT_TRY
block|{
name|set_thread_data
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|data
operator|->
name|thread
operator|=
operator|new
name|QAdoptedThread
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
name|QT_CATCH
argument_list|(
argument|...
argument_list|)
block|{
name|clear_thread_data
argument_list|()
expr_stmt|;
name|data
operator|->
name|deref
argument_list|()
expr_stmt|;
name|data
operator|=
literal|0
expr_stmt|;
name|QT_RETHROW
expr_stmt|;
block|}
name|data
operator|->
name|deref
argument_list|()
expr_stmt|;
block|}
name|data
operator|->
name|isAdopted
operator|=
literal|true
expr_stmt|;
name|data
operator|->
name|threadId
operator|=
name|QThread
operator|::
name|currentThreadId
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|QCoreApplicationPrivate
operator|::
name|theMainThread
condition|)
name|QCoreApplicationPrivate
operator|::
name|theMainThread
operator|=
name|data
operator|->
name|thread
expr_stmt|;
block|}
return|return
name|data
return|;
block|}
end_function
begin_class
DECL|class|QCAdoptedThreadMonitor
class|class
name|QCAdoptedThreadMonitor
super|:
specifier|public
name|CActive
block|{
public|public:
DECL|function|QCAdoptedThreadMonitor
name|QCAdoptedThreadMonitor
parameter_list|(
name|QThread
modifier|*
name|thread
parameter_list|)
member_init_list|:
name|CActive
argument_list|(
name|EPriorityStandard
argument_list|)
member_init_list|,
name|data
argument_list|(
name|QThreadData
operator|::
name|get2
argument_list|(
name|thread
argument_list|)
argument_list|)
block|{
name|CActiveScheduler
operator|::
name|Add
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|data
operator|->
name|symbian_thread_handle
operator|.
name|Logon
argument_list|(
name|iStatus
argument_list|)
expr_stmt|;
name|SetActive
argument_list|()
expr_stmt|;
block|}
DECL|function|~QCAdoptedThreadMonitor
name|~
name|QCAdoptedThreadMonitor
parameter_list|()
block|{
name|Cancel
argument_list|()
expr_stmt|;
block|}
DECL|function|DoCancel
name|void
name|DoCancel
parameter_list|()
block|{
name|data
operator|->
name|symbian_thread_handle
operator|.
name|LogonCancel
argument_list|(
name|iStatus
argument_list|)
expr_stmt|;
block|}
name|void
name|RunL
parameter_list|()
function_decl|;
private|private:
DECL|member|data
name|QThreadData
modifier|*
name|data
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|QCAddAdoptedThread
class|class
name|QCAddAdoptedThread
super|:
specifier|public
name|CActive
block|{
public|public:
DECL|function|QCAddAdoptedThread
name|QCAddAdoptedThread
parameter_list|()
member_init_list|:
name|CActive
argument_list|(
name|EPriorityStandard
argument_list|)
block|{
name|CActiveScheduler
operator|::
name|Add
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
DECL|function|ConstructL
name|void
name|ConstructL
parameter_list|()
block|{
name|User
operator|::
name|LeaveIfError
argument_list|(
name|monitorThread
operator|.
name|Open
argument_list|(
name|RThread
argument_list|()
operator|.
name|Id
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|start
argument_list|()
expr_stmt|;
block|}
DECL|function|~QCAddAdoptedThread
name|~
name|QCAddAdoptedThread
parameter_list|()
block|{
name|Cancel
argument_list|()
expr_stmt|;
name|monitorThread
operator|.
name|Close
argument_list|()
expr_stmt|;
block|}
DECL|function|DoCancel
name|void
name|DoCancel
parameter_list|()
block|{
name|User
operator|::
name|RequestComplete
argument_list|(
name|stat
argument_list|,
name|KErrCancel
argument_list|)
expr_stmt|;
block|}
DECL|function|start
name|void
name|start
parameter_list|()
block|{
name|iStatus
operator|=
name|KRequestPending
expr_stmt|;
name|SetActive
argument_list|()
expr_stmt|;
name|stat
operator|=
operator|&
name|iStatus
expr_stmt|;
block|}
DECL|function|RunL
name|void
name|RunL
parameter_list|()
block|{
if|if
condition|(
name|iStatus
operator|.
name|Int
argument_list|()
operator|!=
name|KErrNone
condition|)
return|return;
name|QMutexLocker
name|adoptedThreadMonitorMutexlock
argument_list|(
operator|&
name|adoptedThreadMonitorMutex
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|threadsToAdd
operator|.
name|size
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
name|i
operator|--
control|)
block|{
comment|// Create an active object to monitor the thread
operator|new
operator|(
name|ELeave
operator|)
name|QCAdoptedThreadMonitor
argument_list|(
name|threadsToAdd
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|count
operator|++
expr_stmt|;
name|threadsToAdd
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
name|start
argument_list|()
expr_stmt|;
block|}
DECL|function|add
specifier|static
name|void
name|add
parameter_list|(
name|QThread
modifier|*
name|thread
parameter_list|)
block|{
name|QMutexLocker
name|adoptedThreadMonitorMutexlock
argument_list|(
operator|&
name|adoptedThreadMonitorMutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|adoptedThreadAdder
condition|)
block|{
name|RThread
name|monitorThread
decl_stmt|;
name|qt_symbian_throwIfError
argument_list|(
name|monitorThread
operator|.
name|Create
argument_list|(
name|KNullDesC
argument_list|()
argument_list|,
operator|&
name|monitorThreadFunc
argument_list|,
literal|1024
argument_list|,
operator|&
name|User
operator|::
name|Allocator
argument_list|()
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|TRequestStatus
name|started
decl_stmt|;
name|monitorThread
operator|.
name|Rendezvous
argument_list|(
name|started
argument_list|)
expr_stmt|;
name|monitorThread
operator|.
name|Resume
argument_list|()
expr_stmt|;
name|User
operator|::
name|WaitForRequest
argument_list|(
name|started
argument_list|)
expr_stmt|;
name|monitorThread
operator|.
name|Close
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|RThread
argument_list|()
operator|.
name|Id
argument_list|()
operator|==
name|adoptedThreadAdder
operator|->
name|monitorThread
operator|.
name|Id
argument_list|()
condition|)
return|return;
name|adoptedThreadAdder
operator|->
name|threadsToAdd
operator|.
name|push_back
argument_list|(
name|thread
argument_list|)
expr_stmt|;
if|if
condition|(
name|adoptedThreadAdder
operator|->
name|stat
condition|)
block|{
name|adoptedThreadAdder
operator|->
name|monitorThread
operator|.
name|RequestComplete
argument_list|(
name|adoptedThreadAdder
operator|->
name|stat
argument_list|,
name|KErrNone
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|monitorThreadFuncL
specifier|static
name|void
name|monitorThreadFuncL
parameter_list|()
block|{
name|CActiveScheduler
modifier|*
name|scheduler
init|=
operator|new
operator|(
name|ELeave
operator|)
name|CActiveScheduler
argument_list|()
decl_stmt|;
name|CleanupStack
operator|::
name|PushL
argument_list|(
name|scheduler
argument_list|)
expr_stmt|;
name|CActiveScheduler
operator|::
name|Install
argument_list|(
name|scheduler
argument_list|)
expr_stmt|;
name|adoptedThreadAdder
operator|=
operator|new
operator|(
name|ELeave
operator|)
name|QCAddAdoptedThread
argument_list|()
expr_stmt|;
name|CleanupStack
operator|::
name|PushL
argument_list|(
name|adoptedThreadAdder
argument_list|)
expr_stmt|;
name|adoptedThreadAdder
operator|->
name|ConstructL
argument_list|()
expr_stmt|;
name|QCAddAdoptedThread
modifier|*
name|adder
init|=
name|adoptedThreadAdder
decl_stmt|;
name|RThread
operator|::
name|Rendezvous
argument_list|(
name|KErrNone
argument_list|)
expr_stmt|;
name|CActiveScheduler
operator|::
name|Start
argument_list|()
expr_stmt|;
name|CleanupStack
operator|::
name|PopAndDestroy
argument_list|(
name|adder
argument_list|)
expr_stmt|;
name|CleanupStack
operator|::
name|PopAndDestroy
argument_list|(
name|scheduler
argument_list|)
expr_stmt|;
block|}
DECL|function|monitorThreadFunc
specifier|static
name|int
name|monitorThreadFunc
parameter_list|(
name|void
modifier|*
parameter_list|)
block|{
name|_LIT
argument_list|(
name|KMonitorThreadName
argument_list|,
literal|"adoptedMonitorThread"
argument_list|)
expr_stmt|;
name|RThread
operator|::
name|RenameMe
argument_list|(
name|KMonitorThreadName
argument_list|()
argument_list|)
expr_stmt|;
name|CTrapCleanup
modifier|*
name|cleanup
init|=
name|CTrapCleanup
operator|::
name|New
argument_list|()
decl_stmt|;
name|TRAPD
argument_list|(
name|ret
argument_list|,
name|monitorThreadFuncL
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|cleanup
expr_stmt|;
return|return
name|ret
return|;
block|}
DECL|function|threadDied
specifier|static
name|void
name|threadDied
parameter_list|()
block|{
name|QMutexLocker
name|adoptedThreadMonitorMutexlock
argument_list|(
operator|&
name|adoptedThreadMonitorMutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|adoptedThreadAdder
condition|)
block|{
name|adoptedThreadAdder
operator|->
name|count
operator|--
expr_stmt|;
if|if
condition|(
name|adoptedThreadAdder
operator|->
name|count
operator|<=
literal|0
operator|&&
name|adoptedThreadAdder
operator|->
name|threadsToAdd
operator|.
name|size
argument_list|()
operator|==
literal|0
condition|)
block|{
name|CActiveScheduler
operator|::
name|Stop
argument_list|()
expr_stmt|;
name|adoptedThreadAdder
operator|=
literal|0
expr_stmt|;
block|}
block|}
block|}
private|private:
DECL|member|threadsToAdd
name|QVector
argument_list|<
name|QThread
modifier|*
argument_list|>
name|threadsToAdd
decl_stmt|;
DECL|member|monitorThread
name|RThread
name|monitorThread
decl_stmt|;
DECL|member|adoptedThreadMonitorMutex
specifier|static
name|QMutex
name|adoptedThreadMonitorMutex
decl_stmt|;
DECL|member|adoptedThreadAdder
specifier|static
name|QCAddAdoptedThread
modifier|*
name|adoptedThreadAdder
decl_stmt|;
DECL|member|count
name|int
name|count
decl_stmt|;
DECL|member|stat
name|TRequestStatus
modifier|*
name|stat
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|member|adoptedThreadMonitorMutex
name|QMutex
name|QCAddAdoptedThread
operator|::
name|adoptedThreadMonitorMutex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|adoptedThreadAdder
name|QCAddAdoptedThread
modifier|*
name|QCAddAdoptedThread
operator|::
name|adoptedThreadAdder
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|RunL
name|void
name|QCAdoptedThreadMonitor
operator|::
name|RunL
parameter_list|()
block|{
if|if
condition|(
name|data
operator|->
name|isAdopted
condition|)
block|{
name|QThread
modifier|*
name|thread
init|=
name|data
operator|->
name|thread
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|thread
argument_list|)
expr_stmt|;
name|QThreadPrivate
modifier|*
name|thread_p
init|=
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
name|thread
argument_list|)
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|thread_p
operator|->
name|finished
argument_list|)
expr_stmt|;
name|thread_p
operator|->
name|finish
argument_list|(
name|thread
argument_list|)
expr_stmt|;
block|}
name|data
operator|->
name|deref
argument_list|()
expr_stmt|;
name|QCAddAdoptedThread
operator|::
name|threadDied
argument_list|()
expr_stmt|;
operator|delete
name|this
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|QAdoptedThread
operator|::
name|init
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QThread
argument_list|)
expr_stmt|;
name|d
operator|->
name|thread_id
operator|=
name|RThread
argument_list|()
operator|.
name|Id
argument_list|()
expr_stmt|;
comment|// type operator to TUint
name|init_symbian_thread_handle
argument_list|(
name|d
operator|->
name|data
operator|->
name|symbian_thread_handle
argument_list|)
expr_stmt|;
name|QCAddAdoptedThread
operator|::
name|add
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*    QThreadPrivate */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_C_CALLBACKS
argument_list|)
end_if
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
DECL|typedef|QtThreadCallback
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|QtThreadCallback
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|Q_C_CALLBACKS
argument_list|)
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_THREAD
end_comment
begin_function
DECL|function|createEventDispatcher
name|void
name|QThreadPrivate
operator|::
name|createEventDispatcher
parameter_list|(
name|QThreadData
modifier|*
name|data
parameter_list|)
block|{
name|data
operator|->
name|eventDispatcher
operator|=
operator|new
name|QEventDispatcherSymbian
expr_stmt|;
name|data
operator|->
name|eventDispatcher
operator|->
name|startingUp
argument_list|()
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_function
DECL|function|start
name|void
modifier|*
name|QThreadPrivate
operator|::
name|start
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|QThread
modifier|*
name|thr
init|=
cast|reinterpret_cast
argument_list|<
name|QThread
operator|*
argument_list|>
argument_list|(
name|arg
argument_list|)
decl_stmt|;
name|QThreadData
modifier|*
name|data
init|=
name|QThreadData
operator|::
name|get2
argument_list|(
name|thr
argument_list|)
decl_stmt|;
comment|// do we need to reset the thread priority?
if|if
condition|(
name|int
argument_list|(
name|thr
operator|->
name|d_func
argument_list|()
operator|->
name|priority
argument_list|)
operator|&
name|ThreadPriorityResetFlag
condition|)
block|{
name|thr
operator|->
name|setPriority
argument_list|(
name|QThread
operator|::
name|Priority
argument_list|(
name|thr
operator|->
name|d_func
argument_list|()
operator|->
name|priority
operator|&
operator|~
name|ThreadPriorityResetFlag
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// On symbian, threads other than the main thread are non critical by default
comment|// This means a worker thread can crash without crashing the application - to
comment|// use this feature, we would need to use RThread::Logon in the main thread
comment|// to catch abnormal thread exit and emit the finished signal.
comment|// For the sake of cross platform consistency, we set the thread as process critical
comment|// - advanced users who want the symbian behaviour can change the critical
comment|// attribute of the thread again once the app gains control in run()
name|User
operator|::
name|SetCritical
argument_list|(
name|User
operator|::
name|EProcessCritical
argument_list|)
expr_stmt|;
name|data
operator|->
name|threadId
operator|=
name|QThread
operator|::
name|currentThreadId
argument_list|()
expr_stmt|;
name|set_thread_data
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|thr
operator|->
name|d_func
argument_list|()
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|data
operator|->
name|quitNow
operator|=
name|thr
operator|->
name|d_func
argument_list|()
operator|->
name|exited
expr_stmt|;
block|}
comment|// ### TODO: allow the user to create a custom event dispatcher
name|createEventDispatcher
argument_list|(
name|data
argument_list|)
expr_stmt|;
emit|emit
name|thr
operator|->
name|started
argument_list|()
emit|;
name|thr
operator|->
name|run
argument_list|()
expr_stmt|;
name|QThreadPrivate
operator|::
name|finish
argument_list|(
name|arg
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|finish
name|void
name|QThreadPrivate
operator|::
name|finish
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|bool
name|lockAnyway
parameter_list|,
name|bool
name|closeNativeHandle
parameter_list|)
block|{
name|QThread
modifier|*
name|thr
init|=
cast|reinterpret_cast
argument_list|<
name|QThread
operator|*
argument_list|>
argument_list|(
name|arg
argument_list|)
decl_stmt|;
name|QThreadPrivate
modifier|*
name|d
init|=
name|thr
operator|->
name|d_func
argument_list|()
decl_stmt|;
name|QMutexLocker
name|locker
argument_list|(
name|lockAnyway
condition|?
operator|&
name|d
operator|->
name|mutex
else|:
literal|0
argument_list|)
decl_stmt|;
name|d
operator|->
name|isInFinish
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|priority
operator|=
name|QThread
operator|::
name|InheritPriority
expr_stmt|;
name|bool
name|terminated
init|=
name|d
operator|->
name|terminated
decl_stmt|;
name|void
modifier|*
name|data
init|=
operator|&
name|d
operator|->
name|data
operator|->
name|tls
decl_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
if|if
condition|(
name|terminated
condition|)
emit|emit
name|thr
operator|->
name|terminated
argument_list|()
emit|;
emit|emit
name|thr
operator|->
name|finished
argument_list|()
emit|;
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|(
literal|0
argument_list|,
name|QEvent
operator|::
name|DeferredDelete
argument_list|)
expr_stmt|;
name|QThreadStorageData
operator|::
name|finish
argument_list|(
operator|(
name|void
operator|*
operator|*
operator|)
name|data
argument_list|)
expr_stmt|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
name|d
operator|->
name|terminated
operator|=
literal|false
expr_stmt|;
name|QAbstractEventDispatcher
modifier|*
name|eventDispatcher
init|=
name|d
operator|->
name|data
operator|->
name|eventDispatcher
decl_stmt|;
if|if
condition|(
name|eventDispatcher
condition|)
block|{
name|d
operator|->
name|data
operator|->
name|eventDispatcher
operator|=
literal|0
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|eventDispatcher
operator|->
name|closingDown
argument_list|()
expr_stmt|;
operator|delete
name|eventDispatcher
expr_stmt|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
block|}
name|d
operator|->
name|thread_id
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|closeNativeHandle
condition|)
name|d
operator|->
name|data
operator|->
name|symbian_thread_handle
operator|.
name|Close
argument_list|()
expr_stmt|;
name|d
operator|->
name|running
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|finished
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|isInFinish
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|thread_done
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/**************************************************************************  ** QThread  *************************************************************************/
end_comment
begin_function
DECL|function|currentThreadId
name|Qt
operator|::
name|HANDLE
name|QThread
operator|::
name|currentThreadId
parameter_list|()
block|{
return|return
operator|(
name|Qt
operator|::
name|HANDLE
operator|)
operator|(
name|TUint
operator|)
name|RThread
argument_list|()
operator|.
name|Id
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|idealThreadCount
name|int
name|QThread
operator|::
name|idealThreadCount
parameter_list|()
block|{
name|int
name|cores
init|=
literal|1
decl_stmt|;
if|if
condition|(
name|QSysInfo
operator|::
name|symbianVersion
argument_list|()
operator|>=
name|QSysInfo
operator|::
name|SV_SF_3
condition|)
block|{
name|TInt
name|inumcpus
decl_stmt|;
name|TInt
name|err
decl_stmt|;
name|err
operator|=
name|HAL
operator|::
name|Get
argument_list|(
operator|(
name|HALData
operator|::
name|TAttribute
operator|)
name|QT_HALData_ENumCpus
argument_list|,
name|inumcpus
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|==
name|KErrNone
condition|)
block|{
name|cores
operator|=
name|qMax
argument_list|(
name|inumcpus
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|cores
return|;
block|}
end_function
begin_function
DECL|function|yieldCurrentThread
name|void
name|QThread
operator|::
name|yieldCurrentThread
parameter_list|()
block|{
name|sched_yield
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*  \internal     helper function to do thread sleeps */
end_comment
begin_function
DECL|function|thread_sleep
specifier|static
name|void
name|thread_sleep
parameter_list|(
name|unsigned
name|long
name|remaining
parameter_list|,
name|unsigned
name|long
name|scale
parameter_list|)
block|{
comment|// maximum Symbian wait is 2^31 microseconds
name|unsigned
name|long
name|maxWait
init|=
name|KMaxTInt
operator|/
name|scale
decl_stmt|;
do|do
block|{
name|unsigned
name|long
name|waitTime
init|=
name|qMin
argument_list|(
name|maxWait
argument_list|,
name|remaining
argument_list|)
decl_stmt|;
name|remaining
operator|-=
name|waitTime
expr_stmt|;
name|User
operator|::
name|AfterHighRes
argument_list|(
name|waitTime
operator|*
name|scale
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|remaining
condition|)
do|;
block|}
end_function
begin_function
DECL|function|sleep
name|void
name|QThread
operator|::
name|sleep
parameter_list|(
name|unsigned
name|long
name|secs
parameter_list|)
block|{
name|thread_sleep
argument_list|(
name|secs
argument_list|,
literal|1000000ul
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|msleep
name|void
name|QThread
operator|::
name|msleep
parameter_list|(
name|unsigned
name|long
name|msecs
parameter_list|)
block|{
name|thread_sleep
argument_list|(
name|msecs
argument_list|,
literal|1000ul
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|usleep
name|void
name|QThread
operator|::
name|usleep
parameter_list|(
name|unsigned
name|long
name|usecs
parameter_list|)
block|{
name|thread_sleep
argument_list|(
name|usecs
argument_list|,
literal|1ul
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|calculateSymbianPriority
name|TThreadPriority
name|calculateSymbianPriority
parameter_list|(
name|QThread
operator|::
name|Priority
name|priority
parameter_list|)
block|{
comment|// Both Qt& Symbian use limited enums; this matches the mapping previously done through conversion to Posix granularity
name|TThreadPriority
name|symPriority
decl_stmt|;
switch|switch
condition|(
name|priority
condition|)
block|{
case|case
name|QThread
operator|::
name|IdlePriority
case|:
name|symPriority
operator|=
name|EPriorityMuchLess
expr_stmt|;
break|break;
case|case
name|QThread
operator|::
name|LowestPriority
case|:
case|case
name|QThread
operator|::
name|LowPriority
case|:
name|symPriority
operator|=
name|EPriorityLess
expr_stmt|;
break|break;
case|case
name|QThread
operator|::
name|NormalPriority
case|:
name|symPriority
operator|=
name|EPriorityNormal
expr_stmt|;
break|break;
case|case
name|QThread
operator|::
name|HighPriority
case|:
name|symPriority
operator|=
name|EPriorityMore
expr_stmt|;
break|break;
case|case
name|QThread
operator|::
name|HighestPriority
case|:
case|case
name|QThread
operator|::
name|TimeCriticalPriority
case|:
name|symPriority
operator|=
name|EPriorityMuchMore
expr_stmt|;
break|break;
case|case
name|QThread
operator|::
name|InheritPriority
case|:
default|default:
name|symPriority
operator|=
name|RThread
argument_list|()
operator|.
name|Priority
argument_list|()
expr_stmt|;
break|break;
block|}
return|return
name|symPriority
return|;
block|}
end_function
begin_function
DECL|function|start
name|void
name|QThread
operator|::
name|start
parameter_list|(
name|Priority
name|priority
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
if|if
condition|(
name|d
operator|->
name|isInFinish
condition|)
name|d
operator|->
name|thread_done
operator|.
name|wait
argument_list|(
name|locker
operator|.
name|mutex
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|running
condition|)
return|return;
name|d
operator|->
name|running
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|finished
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|terminated
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|returnCode
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|exited
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|priority
operator|=
name|priority
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|stackSize
operator|==
literal|0
condition|)
comment|// The default stack size on Symbian is very small, making even basic
comment|// operations like file I/O fail, so we increase it by default.
name|d
operator|->
name|stackSize
operator|=
literal|0x14000
expr_stmt|;
comment|// Maximum stack size on Symbian.
name|int
name|code
init|=
name|d
operator|->
name|data
operator|->
name|symbian_thread_handle
operator|.
name|Create
argument_list|(
name|KNullDesC
argument_list|,
operator|(
name|TThreadFunction
operator|)
name|QThreadPrivate
operator|::
name|start
argument_list|,
name|d
operator|->
name|stackSize
argument_list|,
name|NULL
argument_list|,
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|code
operator|==
name|KErrNone
condition|)
block|{
name|d
operator|->
name|thread_id
operator|=
name|d
operator|->
name|data
operator|->
name|symbian_thread_handle
operator|.
name|Id
argument_list|()
expr_stmt|;
name|TThreadPriority
name|symPriority
init|=
name|calculateSymbianPriority
argument_list|(
name|priority
argument_list|)
decl_stmt|;
name|d
operator|->
name|data
operator|->
name|symbian_thread_handle
operator|.
name|SetPriority
argument_list|(
name|symPriority
argument_list|)
expr_stmt|;
name|d
operator|->
name|data
operator|->
name|symbian_thread_handle
operator|.
name|Resume
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QThread::start: Thread creation error: %s"
argument_list|,
name|qPrintable
argument_list|(
name|QSystemError
argument_list|(
name|code
argument_list|,
name|QSystemError
operator|::
name|NativeError
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|running
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|finished
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|thread_id
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|data
operator|->
name|symbian_thread_handle
operator|.
name|Close
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|terminate
name|void
name|QThread
operator|::
name|terminate
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
if|if
condition|(
operator|!
name|d
operator|->
name|thread_id
condition|)
return|return;
if|if
condition|(
operator|!
name|d
operator|->
name|running
condition|)
return|return;
if|if
condition|(
operator|!
name|d
operator|->
name|terminationEnabled
condition|)
block|{
name|d
operator|->
name|terminatePending
operator|=
literal|true
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|terminated
operator|=
literal|true
expr_stmt|;
comment|// "false, false" meaning:
comment|// 1. lockAnyway = false. Don't lock the mutex because it's already locked
comment|//    (see above).
comment|// 2. closeNativeSymbianHandle = false. We don't want to close the thread handle,
comment|//    because we need it here to terminate the thread.
name|QThreadPrivate
operator|::
name|finish
argument_list|(
name|this
argument_list|,
literal|false
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|d
operator|->
name|data
operator|->
name|symbian_thread_handle
operator|.
name|Terminate
argument_list|(
name|KErrNone
argument_list|)
expr_stmt|;
name|d
operator|->
name|data
operator|->
name|symbian_thread_handle
operator|.
name|Close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|wait
name|bool
name|QThread
operator|::
name|wait
parameter_list|(
name|unsigned
name|long
name|time
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
if|if
condition|(
name|d
operator|->
name|thread_id
operator|==
operator|(
name|TUint
operator|)
name|RThread
argument_list|()
operator|.
name|Id
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QThread::wait: Thread tried to wait on itself"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|d
operator|->
name|finished
operator|||
operator|!
name|d
operator|->
name|running
condition|)
return|return
literal|true
return|;
while|while
condition|(
name|d
operator|->
name|running
condition|)
block|{
comment|// Check if thread still exists. Needed because kernel will kill it without notification
comment|// before global statics are deleted at application exit.
if|if
condition|(
name|d
operator|->
name|data
operator|->
name|symbian_thread_handle
operator|.
name|Handle
argument_list|()
operator|&&
name|d
operator|->
name|data
operator|->
name|symbian_thread_handle
operator|.
name|ExitType
argument_list|()
operator|!=
name|EExitPending
condition|)
block|{
comment|// Cannot call finish here as wait is typically called from another thread.
comment|// It won't be necessary anyway, as we should never get here under normal operations;
comment|// all QThreads are EProcessCritical and therefore cannot normally exit
comment|// undetected (i.e. panic) as long as all thread control is via QThread.
return|return
literal|true
return|;
block|}
if|if
condition|(
operator|!
name|d
operator|->
name|thread_done
operator|.
name|wait
argument_list|(
name|locker
operator|.
name|mutex
argument_list|()
argument_list|,
name|time
argument_list|)
condition|)
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
DECL|function|setTerminationEnabled
name|void
name|QThread
operator|::
name|setTerminationEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
name|QThread
modifier|*
name|thr
init|=
name|currentThread
argument_list|()
decl_stmt|;
name|Q_ASSERT_X
argument_list|(
name|thr
operator|!=
literal|0
argument_list|,
literal|"QThread::setTerminationEnabled()"
argument_list|,
literal|"Current thread was not started with QThread."
argument_list|)
expr_stmt|;
name|QThreadPrivate
modifier|*
name|d
init|=
name|thr
operator|->
name|d_func
argument_list|()
decl_stmt|;
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
name|terminationEnabled
operator|=
name|enabled
expr_stmt|;
if|if
condition|(
name|enabled
operator|&&
name|d
operator|->
name|terminatePending
condition|)
block|{
name|d
operator|->
name|terminated
operator|=
literal|true
expr_stmt|;
comment|// "false" meaning:
comment|// -  lockAnyway = false. Don't lock the mutex because it's already locked
comment|//    (see above).
name|QThreadPrivate
operator|::
name|finish
argument_list|(
name|thr
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
comment|// don't leave the mutex locked!
name|User
operator|::
name|Exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// may be some other cleanup required? what if AS or cleanup stack?
block|}
block|}
end_function
begin_function
DECL|function|setPriority
name|void
name|QThread
operator|::
name|setPriority
parameter_list|(
name|Priority
name|priority
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
if|if
condition|(
operator|!
name|d
operator|->
name|running
condition|)
block|{
name|qWarning
argument_list|(
literal|"QThread::setPriority: Cannot set priority, thread is not running"
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|priority
operator|=
name|priority
expr_stmt|;
comment|// copied from start() with a few modifications:
name|TThreadPriority
name|symPriority
init|=
name|calculateSymbianPriority
argument_list|(
name|priority
argument_list|)
decl_stmt|;
name|d
operator|->
name|data
operator|->
name|symbian_thread_handle
operator|.
name|SetPriority
argument_list|(
name|symPriority
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_THREAD
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
