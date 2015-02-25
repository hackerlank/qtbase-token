begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qwaitcondition.h"
end_include
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_include
include|#
directive|include
file|"qreadwritelock.h"
end_include
begin_include
include|#
directive|include
file|"qatomic.h"
end_include
begin_include
include|#
directive|include
file|"qstring.h"
end_include
begin_include
include|#
directive|include
file|"qelapsedtimer.h"
end_include
begin_include
include|#
directive|include
file|"private/qcore_unix_p.h"
end_include
begin_include
include|#
directive|include
file|"qmutex_p.h"
end_include
begin_include
include|#
directive|include
file|"qreadwritelock_p.h"
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<sys/time.h>
end_include
begin_include
include|#
directive|include
file|<time.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|Q_OS_ANDROID
comment|// pthread_condattr_setclock is available only since Android 5.0. On older versions, there's
comment|// a private function for relative waits (hidden in 5.0).
comment|// Use weakref so we can determine at runtime whether each of them is present.
specifier|static
name|int
name|local_condattr_setclock
argument_list|(
name|pthread_condattr_t
operator|*
argument_list|,
name|clockid_t
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|weakref
argument_list|(
literal|"pthread_condattr_setclock"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|int
name|local_cond_timedwait_relative
argument_list|(
name|pthread_cond_t
operator|*
argument_list|,
name|pthread_mutex_t
operator|*
argument_list|,
specifier|const
name|timespec
operator|*
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|weakref
argument_list|(
literal|"__pthread_cond_timedwait_relative"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function
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
begin_function
DECL|function|qt_initialize_pthread_cond
name|void
name|qt_initialize_pthread_cond
parameter_list|(
name|pthread_cond_t
modifier|*
name|cond
parameter_list|,
specifier|const
name|char
modifier|*
name|where
parameter_list|)
block|{
name|pthread_condattr_t
name|condattr
decl_stmt|;
name|pthread_condattr_init
argument_list|(
operator|&
name|condattr
argument_list|)
expr_stmt|;
if|#
directive|if
operator|(
name|_POSIX_MONOTONIC_CLOCK
operator|-
literal|0
operator|>=
literal|0
operator|)
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
if|if
condition|(
name|local_condattr_setclock
operator|&&
name|QElapsedTimer
operator|::
name|clockType
argument_list|()
operator|==
name|QElapsedTimer
operator|::
name|MonotonicClock
condition|)
name|local_condattr_setclock
argument_list|(
operator|&
name|condattr
argument_list|,
name|CLOCK_MONOTONIC
argument_list|)
expr_stmt|;
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_HAIKU
argument_list|)
if|if
condition|(
name|QElapsedTimer
operator|::
name|clockType
argument_list|()
operator|==
name|QElapsedTimer
operator|::
name|MonotonicClock
condition|)
name|pthread_condattr_setclock
argument_list|(
operator|&
name|condattr
argument_list|,
name|CLOCK_MONOTONIC
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|report_error
argument_list|(
name|pthread_cond_init
argument_list|(
name|cond
argument_list|,
operator|&
name|condattr
argument_list|)
argument_list|,
name|where
argument_list|,
literal|"cv init"
argument_list|)
expr_stmt|;
name|pthread_condattr_destroy
argument_list|(
operator|&
name|condattr
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qt_abstime_for_timeout
name|void
name|qt_abstime_for_timeout
parameter_list|(
name|timespec
modifier|*
name|ts
parameter_list|,
name|int
name|timeout
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_MAC
comment|// on Mac, qt_gettime() (on qelapsedtimer_mac.cpp) returns ticks related to the Mach absolute time
comment|// that doesn't work with pthread
comment|// Mac also doesn't have clock_gettime
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
name|ts
operator|->
name|tv_sec
operator|=
name|tv
operator|.
name|tv_sec
expr_stmt|;
name|ts
operator|->
name|tv_nsec
operator|=
name|tv
operator|.
name|tv_usec
operator|*
literal|1000
expr_stmt|;
else|#
directive|else
operator|*
name|ts
operator|=
name|qt_gettime
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|ts
operator|->
name|tv_sec
operator|+=
name|timeout
operator|/
literal|1000
expr_stmt|;
name|ts
operator|->
name|tv_nsec
operator|+=
name|timeout
operator|%
literal|1000
operator|*
name|Q_UINT64_C
argument_list|(
literal|1000
argument_list|)
operator|*
literal|1000
expr_stmt|;
name|normalizedTimespec
argument_list|(
operator|*
name|ts
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|QWaitConditionPrivate
class|class
name|QWaitConditionPrivate
block|{
public|public:
DECL|member|mutex
name|pthread_mutex_t
name|mutex
decl_stmt|;
DECL|member|cond
name|pthread_cond_t
name|cond
decl_stmt|;
DECL|member|waiters
name|int
name|waiters
decl_stmt|;
DECL|member|wakeups
name|int
name|wakeups
decl_stmt|;
DECL|function|wait_relative
name|int
name|wait_relative
parameter_list|(
name|unsigned
name|long
name|time
parameter_list|)
block|{
name|timespec
name|ti
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_ANDROID
if|if
condition|(
name|local_cond_timedwait_relative
condition|)
block|{
name|ti
operator|.
name|tv_sec
operator|=
name|time
operator|/
literal|1000
expr_stmt|;
name|ti
operator|.
name|tv_nsec
operator|=
name|time
operator|%
literal|1000
operator|*
name|Q_UINT64_C
argument_list|(
literal|1000
argument_list|)
operator|*
literal|1000
expr_stmt|;
return|return
name|local_cond_timedwait_relative
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
return|;
block|}
endif|#
directive|endif
name|qt_abstime_for_timeout
argument_list|(
operator|&
name|ti
argument_list|,
name|time
argument_list|)
expr_stmt|;
return|return
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
return|;
block|}
DECL|function|wait
name|bool
name|wait
parameter_list|(
name|unsigned
name|long
name|time
parameter_list|)
block|{
name|int
name|code
decl_stmt|;
forever|forever
block|{
if|if
condition|(
name|time
operator|!=
name|ULONG_MAX
condition|)
block|{
name|code
operator|=
name|wait_relative
argument_list|(
name|time
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|code
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
if|if
condition|(
name|code
operator|==
literal|0
operator|&&
name|wakeups
operator|==
literal|0
condition|)
block|{
comment|// many vendors warn of spurious wakeups from
comment|// pthread_cond_wait(), especially after signal delivery,
comment|// even though POSIX doesn't allow for it... sigh
continue|continue;
block|}
break|break;
block|}
name|Q_ASSERT_X
argument_list|(
name|waiters
operator|>
literal|0
argument_list|,
literal|"QWaitCondition::wait"
argument_list|,
literal|"internal error (waiters)"
argument_list|)
expr_stmt|;
operator|--
name|waiters
expr_stmt|;
if|if
condition|(
name|code
operator|==
literal|0
condition|)
block|{
name|Q_ASSERT_X
argument_list|(
name|wakeups
operator|>
literal|0
argument_list|,
literal|"QWaitCondition::wait"
argument_list|,
literal|"internal error (wakeups)"
argument_list|)
expr_stmt|;
operator|--
name|wakeups
expr_stmt|;
block|}
name|report_error
argument_list|(
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mutex
argument_list|)
argument_list|,
literal|"QWaitCondition::wait()"
argument_list|,
literal|"mutex unlock"
argument_list|)
expr_stmt|;
if|if
condition|(
name|code
operator|&&
name|code
operator|!=
name|ETIMEDOUT
condition|)
name|report_error
argument_list|(
name|code
argument_list|,
literal|"QWaitCondition::wait()"
argument_list|,
literal|"cv wait"
argument_list|)
expr_stmt|;
return|return
operator|(
name|code
operator|==
literal|0
operator|)
return|;
block|}
block|}
class|;
end_class
begin_constructor
DECL|function|QWaitCondition
name|QWaitCondition
operator|::
name|QWaitCondition
parameter_list|()
block|{
name|d
operator|=
operator|new
name|QWaitConditionPrivate
expr_stmt|;
name|report_error
argument_list|(
name|pthread_mutex_init
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|,
name|NULL
argument_list|)
argument_list|,
literal|"QWaitCondition"
argument_list|,
literal|"mutex init"
argument_list|)
expr_stmt|;
name|qt_initialize_pthread_cond
argument_list|(
operator|&
name|d
operator|->
name|cond
argument_list|,
literal|"QWaitCondition"
argument_list|)
expr_stmt|;
name|d
operator|->
name|waiters
operator|=
name|d
operator|->
name|wakeups
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaitCondition
name|QWaitCondition
operator|::
name|~
name|QWaitCondition
parameter_list|()
block|{
name|report_error
argument_list|(
name|pthread_cond_destroy
argument_list|(
operator|&
name|d
operator|->
name|cond
argument_list|)
argument_list|,
literal|"QWaitCondition"
argument_list|,
literal|"cv destroy"
argument_list|)
expr_stmt|;
name|report_error
argument_list|(
name|pthread_mutex_destroy
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
argument_list|,
literal|"QWaitCondition"
argument_list|,
literal|"mutex destroy"
argument_list|)
expr_stmt|;
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|wakeOne
name|void
name|QWaitCondition
operator|::
name|wakeOne
parameter_list|()
block|{
name|report_error
argument_list|(
name|pthread_mutex_lock
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
argument_list|,
literal|"QWaitCondition::wakeOne()"
argument_list|,
literal|"mutex lock"
argument_list|)
expr_stmt|;
name|d
operator|->
name|wakeups
operator|=
name|qMin
argument_list|(
name|d
operator|->
name|wakeups
operator|+
literal|1
argument_list|,
name|d
operator|->
name|waiters
argument_list|)
expr_stmt|;
name|report_error
argument_list|(
name|pthread_cond_signal
argument_list|(
operator|&
name|d
operator|->
name|cond
argument_list|)
argument_list|,
literal|"QWaitCondition::wakeOne()"
argument_list|,
literal|"cv signal"
argument_list|)
expr_stmt|;
name|report_error
argument_list|(
name|pthread_mutex_unlock
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
argument_list|,
literal|"QWaitCondition::wakeOne()"
argument_list|,
literal|"mutex unlock"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|wakeAll
name|void
name|QWaitCondition
operator|::
name|wakeAll
parameter_list|()
block|{
name|report_error
argument_list|(
name|pthread_mutex_lock
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
argument_list|,
literal|"QWaitCondition::wakeAll()"
argument_list|,
literal|"mutex lock"
argument_list|)
expr_stmt|;
name|d
operator|->
name|wakeups
operator|=
name|d
operator|->
name|waiters
expr_stmt|;
name|report_error
argument_list|(
name|pthread_cond_broadcast
argument_list|(
operator|&
name|d
operator|->
name|cond
argument_list|)
argument_list|,
literal|"QWaitCondition::wakeAll()"
argument_list|,
literal|"cv broadcast"
argument_list|)
expr_stmt|;
name|report_error
argument_list|(
name|pthread_mutex_unlock
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
argument_list|,
literal|"QWaitCondition::wakeAll()"
argument_list|,
literal|"mutex unlock"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|wait
name|bool
name|QWaitCondition
operator|::
name|wait
parameter_list|(
name|QMutex
modifier|*
name|mutex
parameter_list|,
name|unsigned
name|long
name|time
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mutex
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|mutex
operator|->
name|isRecursive
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QWaitCondition: cannot wait on recursive mutexes"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|report_error
argument_list|(
name|pthread_mutex_lock
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
argument_list|,
literal|"QWaitCondition::wait()"
argument_list|,
literal|"mutex lock"
argument_list|)
expr_stmt|;
operator|++
name|d
operator|->
name|waiters
expr_stmt|;
name|mutex
operator|->
name|unlock
argument_list|()
expr_stmt|;
name|bool
name|returnValue
init|=
name|d
operator|->
name|wait
argument_list|(
name|time
argument_list|)
decl_stmt|;
name|mutex
operator|->
name|lock
argument_list|()
expr_stmt|;
return|return
name|returnValue
return|;
block|}
end_function
begin_function
DECL|function|wait
name|bool
name|QWaitCondition
operator|::
name|wait
parameter_list|(
name|QReadWriteLock
modifier|*
name|readWriteLock
parameter_list|,
name|unsigned
name|long
name|time
parameter_list|)
block|{
if|if
condition|(
operator|!
name|readWriteLock
operator|||
name|readWriteLock
operator|->
name|d
operator|->
name|accessCount
operator|==
literal|0
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|readWriteLock
operator|->
name|d
operator|->
name|accessCount
operator|<
operator|-
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"QWaitCondition: cannot wait on QReadWriteLocks with recursive lockForWrite()"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|report_error
argument_list|(
name|pthread_mutex_lock
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
argument_list|,
literal|"QWaitCondition::wait()"
argument_list|,
literal|"mutex lock"
argument_list|)
expr_stmt|;
operator|++
name|d
operator|->
name|waiters
expr_stmt|;
name|int
name|previousAccessCount
init|=
name|readWriteLock
operator|->
name|d
operator|->
name|accessCount
decl_stmt|;
name|readWriteLock
operator|->
name|unlock
argument_list|()
expr_stmt|;
name|bool
name|returnValue
init|=
name|d
operator|->
name|wait
argument_list|(
name|time
argument_list|)
decl_stmt|;
if|if
condition|(
name|previousAccessCount
operator|<
literal|0
condition|)
name|readWriteLock
operator|->
name|lockForWrite
argument_list|()
expr_stmt|;
else|else
name|readWriteLock
operator|->
name|lockForRead
argument_list|()
expr_stmt|;
return|return
name|returnValue
return|;
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
comment|// QT_NO_THREAD
end_comment
end_unit
