begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_include
include|#
directive|include
file|"qstring.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_include
include|#
directive|include
file|"qatomic.h"
end_include
begin_include
include|#
directive|include
file|"qmutex_p.h"
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
operator|&&
name|defined
argument_list|(
name|wakeup
argument_list|)
end_if
begin_undef
DECL|macro|wakeup
undef|#
directive|undef
name|wakeup
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_include
include|#
directive|include
file|<mach/mach.h>
end_include
begin_include
include|#
directive|include
file|<mach/task.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<linux/futex.h>
end_include
begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
DECL|function|report_error
specifier|static
name|void
name|report_error
parameter_list|(
name|int
name|code
parameter_list|,
specifier|const
name|char
modifier|*
name|where
parameter_list|,
specifier|const
name|char
modifier|*
name|what
parameter_list|)
block|{
if|if
condition|(
name|code
operator|!=
literal|0
condition|)
name|qWarning
argument_list|(
literal|"%s: %s failure: %s"
argument_list|,
name|where
argument_list|,
name|what
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|code
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|QMutexPrivate
name|QMutexPrivate
operator|::
name|QMutexPrivate
parameter_list|(
name|QMutex
operator|::
name|RecursionMode
name|mode
parameter_list|)
member_init_list|:
name|QMutexData
argument_list|(
name|mode
argument_list|)
member_init_list|,
name|maximumSpinTime
argument_list|(
name|MaximumSpinTimeThreshold
argument_list|)
member_init_list|,
name|averageWaitTime
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|owner
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|count
argument_list|(
literal|0
argument_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
name|kern_return_t
name|r
init|=
name|semaphore_create
argument_list|(
name|mach_task_self
argument_list|()
argument_list|,
operator|&
name|mach_semaphore
argument_list|,
name|SYNC_POLICY_FIFO
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|r
operator|!=
name|KERN_SUCCESS
condition|)
name|qWarning
argument_list|(
literal|"QMutex: failed to create semaphore, error %d"
argument_list|,
name|r
argument_list|)
expr_stmt|;
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
name|wakeup
operator|=
literal|false
expr_stmt|;
name|report_error
argument_list|(
name|pthread_mutex_init
argument_list|(
operator|&
name|mutex
argument_list|,
name|NULL
argument_list|)
argument_list|,
literal|"QMutex"
argument_list|,
literal|"mutex init"
argument_list|)
expr_stmt|;
name|report_error
argument_list|(
name|pthread_cond_init
argument_list|(
operator|&
name|cond
argument_list|,
name|NULL
argument_list|)
argument_list|,
literal|"QMutex"
argument_list|,
literal|"cv init"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_constructor
begin_destructor
DECL|function|~QMutexPrivate
name|QMutexPrivate
operator|::
name|~
name|QMutexPrivate
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
name|kern_return_t
name|r
init|=
name|semaphore_destroy
argument_list|(
name|mach_task_self
argument_list|()
argument_list|,
name|mach_semaphore
argument_list|)
decl_stmt|;
if|if
condition|(
name|r
operator|!=
name|KERN_SUCCESS
condition|)
name|qWarning
argument_list|(
literal|"QMutex: failed to destroy semaphore, error %d"
argument_list|,
name|r
argument_list|)
expr_stmt|;
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
name|report_error
argument_list|(
name|pthread_cond_destroy
argument_list|(
operator|&
name|cond
argument_list|)
argument_list|,
literal|"QMutex"
argument_list|,
literal|"cv destroy"
argument_list|)
expr_stmt|;
name|report_error
argument_list|(
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mutex
argument_list|)
argument_list|,
literal|"QMutex"
argument_list|,
literal|"mutex destroy"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_destructor
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_function
DECL|function|wait
name|bool
name|QMutexPrivate
operator|::
name|wait
parameter_list|(
name|int
name|timeout
parameter_list|)
block|{
if|if
condition|(
name|contenders
operator|.
name|fetchAndAddAcquire
argument_list|(
literal|1
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|// lock acquired without waiting
return|return
literal|true
return|;
block|}
name|kern_return_t
name|r
decl_stmt|;
if|if
condition|(
name|timeout
operator|<
literal|0
condition|)
block|{
do|do
block|{
name|r
operator|=
name|semaphore_wait
argument_list|(
name|mach_semaphore
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|r
operator|==
name|KERN_ABORTED
condition|)
do|;
if|if
condition|(
name|r
operator|!=
name|KERN_SUCCESS
condition|)
name|qWarning
argument_list|(
literal|"QMutex: infinite wait failed, error %d"
argument_list|,
name|r
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|mach_timespec_t
name|ts
decl_stmt|;
name|ts
operator|.
name|tv_nsec
operator|=
operator|(
operator|(
name|timeout
operator|%
literal|1000
operator|)
operator|*
literal|1000
operator|)
operator|*
literal|1000
expr_stmt|;
name|ts
operator|.
name|tv_sec
operator|=
operator|(
name|timeout
operator|/
literal|1000
operator|)
expr_stmt|;
name|r
operator|=
name|semaphore_timedwait
argument_list|(
name|mach_semaphore
argument_list|,
name|ts
argument_list|)
expr_stmt|;
block|}
name|contenders
operator|.
name|deref
argument_list|()
expr_stmt|;
return|return
name|r
operator|==
name|KERN_SUCCESS
return|;
block|}
end_function
begin_function
DECL|function|wakeUp
name|void
name|QMutexPrivate
operator|::
name|wakeUp
parameter_list|()
block|{
name|semaphore_signal
argument_list|(
name|mach_semaphore
argument_list|)
expr_stmt|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
end_elif
begin_function
DECL|function|_q_futex
specifier|static
specifier|inline
name|int
name|_q_futex
parameter_list|(
specifier|volatile
name|int
modifier|*
name|addr
parameter_list|,
name|int
name|op
parameter_list|,
name|int
name|val
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|timeout
parameter_list|,
name|int
modifier|*
name|addr2
parameter_list|,
name|int
name|val2
parameter_list|)
block|{
return|return
name|syscall
argument_list|(
name|SYS_futex
argument_list|,
name|addr
argument_list|,
name|op
argument_list|,
name|val
argument_list|,
name|timeout
argument_list|,
name|addr2
argument_list|,
name|val2
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|wait
name|bool
name|QMutexPrivate
operator|::
name|wait
parameter_list|(
name|int
name|timeout
parameter_list|)
block|{
while|while
condition|(
name|contenders
operator|.
name|fetchAndStoreAcquire
argument_list|(
literal|2
argument_list|)
operator|>
literal|0
condition|)
block|{
name|struct
name|timespec
name|ts
decl_stmt|,
modifier|*
name|pts
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|timeout
operator|>=
literal|0
condition|)
block|{
name|ts
operator|.
name|tv_nsec
operator|=
operator|(
operator|(
name|timeout
operator|%
literal|1000
operator|)
operator|*
literal|1000
operator|)
operator|*
literal|1000
expr_stmt|;
name|ts
operator|.
name|tv_sec
operator|=
operator|(
name|timeout
operator|/
literal|1000
operator|)
expr_stmt|;
name|pts
operator|=
operator|&
name|ts
expr_stmt|;
block|}
name|int
name|r
init|=
name|_q_futex
argument_list|(
operator|&
name|contenders
operator|.
name|_q_value
argument_list|,
name|FUTEX_WAIT
argument_list|,
literal|2
argument_list|,
name|pts
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|r
operator|!=
literal|0
operator|&&
name|errno
operator|==
name|ETIMEDOUT
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
DECL|function|wakeUp
name|void
name|QMutexPrivate
operator|::
name|wakeUp
parameter_list|()
block|{
operator|(
name|void
operator|)
name|contenders
operator|.
name|fetchAndStoreRelease
argument_list|(
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|_q_futex
argument_list|(
operator|&
name|contenders
operator|.
name|_q_value
argument_list|,
name|FUTEX_WAKE
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_comment
comment|// !Q_OS_MAC&& !Q_OS_LINUX
end_comment
begin_function
DECL|function|wait
name|bool
name|QMutexPrivate
operator|::
name|wait
parameter_list|(
name|int
name|timeout
parameter_list|)
block|{
if|if
condition|(
name|contenders
operator|.
name|fetchAndAddAcquire
argument_list|(
literal|1
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|// lock acquired without waiting
return|return
literal|true
return|;
block|}
name|report_error
argument_list|(
name|pthread_mutex_lock
argument_list|(
operator|&
name|mutex
argument_list|)
argument_list|,
literal|"QMutex::lock"
argument_list|,
literal|"mutex lock"
argument_list|)
expr_stmt|;
name|int
name|errorCode
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|!
name|wakeup
condition|)
block|{
if|if
condition|(
name|timeout
operator|<
literal|0
condition|)
block|{
name|errorCode
operator|=
name|pthread_cond_wait
argument_list|(
operator|&
name|cond
argument_list|,
operator|&
name|mutex
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|struct
name|timeval
name|tv
decl_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|tv
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|timespec
name|ti
decl_stmt|;
name|ti
operator|.
name|tv_nsec
operator|=
operator|(
name|tv
operator|.
name|tv_usec
operator|+
operator|(
name|timeout
operator|%
literal|1000
operator|)
operator|*
literal|1000
operator|)
operator|*
literal|1000
expr_stmt|;
name|ti
operator|.
name|tv_sec
operator|=
name|tv
operator|.
name|tv_sec
operator|+
operator|(
name|timeout
operator|/
literal|1000
operator|)
operator|+
operator|(
name|ti
operator|.
name|tv_nsec
operator|/
literal|1000000000
operator|)
expr_stmt|;
name|ti
operator|.
name|tv_nsec
operator|%=
literal|1000000000
expr_stmt|;
name|errorCode
operator|=
name|pthread_cond_timedwait
argument_list|(
operator|&
name|cond
argument_list|,
operator|&
name|mutex
argument_list|,
operator|&
name|ti
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|errorCode
condition|)
block|{
if|if
condition|(
name|errorCode
operator|==
name|ETIMEDOUT
condition|)
block|{
if|if
condition|(
name|wakeup
condition|)
name|errorCode
operator|=
literal|0
expr_stmt|;
break|break;
block|}
name|report_error
argument_list|(
name|errorCode
argument_list|,
literal|"QMutex::lock()"
argument_list|,
literal|"cv wait"
argument_list|)
expr_stmt|;
block|}
block|}
name|wakeup
operator|=
literal|false
expr_stmt|;
name|report_error
argument_list|(
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mutex
argument_list|)
argument_list|,
literal|"QMutex::lock"
argument_list|,
literal|"mutex unlock"
argument_list|)
expr_stmt|;
name|contenders
operator|.
name|deref
argument_list|()
expr_stmt|;
return|return
name|errorCode
operator|==
literal|0
return|;
block|}
end_function
begin_function
DECL|function|wakeUp
name|void
name|QMutexPrivate
operator|::
name|wakeUp
parameter_list|()
block|{
name|report_error
argument_list|(
name|pthread_mutex_lock
argument_list|(
operator|&
name|mutex
argument_list|)
argument_list|,
literal|"QMutex::unlock"
argument_list|,
literal|"mutex lock"
argument_list|)
expr_stmt|;
name|wakeup
operator|=
literal|true
expr_stmt|;
name|report_error
argument_list|(
name|pthread_cond_signal
argument_list|(
operator|&
name|cond
argument_list|)
argument_list|,
literal|"QMutex::unlock"
argument_list|,
literal|"cv signal"
argument_list|)
expr_stmt|;
name|report_error
argument_list|(
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mutex
argument_list|)
argument_list|,
literal|"QMutex::unlock"
argument_list|,
literal|"mutex unlock"
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !Q_OS_MAC&& !Q_OS_LINUX
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_THREAD
end_comment
end_unit
