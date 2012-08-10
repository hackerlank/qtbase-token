begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|"qelapsedtimer.h"
end_include
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
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<asm/unistd.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_LINUX_FUTEX
end_ifndef
begin_error
error|#
directive|error
literal|"Qt build is broken: qmutex_linux.cpp is being built but futex support is not wanted"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|futexFlagSupport
specifier|static
name|QBasicAtomicInt
name|futexFlagSupport
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|checkFutexPrivateSupport
specifier|static
name|int
name|checkFutexPrivateSupport
parameter_list|()
block|{
name|int
name|value
init|=
literal|0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|FUTEX_PRIVATE_FLAG
argument_list|)
comment|// check if the kernel supports extra futex flags
comment|// FUTEX_PRIVATE_FLAG appeared in v2.6.22
name|Q_STATIC_ASSERT
argument_list|(
name|FUTEX_PRIVATE_FLAG
operator|!=
literal|0x80000000
argument_list|)
expr_stmt|;
comment|// try an operation that has no side-effects: wake up 42 threads
comment|// futex will return -1 (errno==ENOSYS) if the flag isn't supported
comment|// there should be no other error conditions
name|value
operator|=
name|syscall
argument_list|(
name|__NR_futex
argument_list|,
operator|&
name|futexFlagSupport
argument_list|,
name|FUTEX_WAKE
operator||
name|FUTEX_PRIVATE_FLAG
argument_list|,
literal|42
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|value
operator|!=
operator|-
literal|1
condition|)
name|value
operator|=
name|FUTEX_PRIVATE_FLAG
expr_stmt|;
else|else
name|value
operator|=
literal|0
expr_stmt|;
else|#
directive|else
name|value
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
name|futexFlagSupport
operator|.
name|store
argument_list|(
name|value
argument_list|)
expr_stmt|;
return|return
name|value
return|;
block|}
end_function
begin_function
DECL|function|futexFlags
specifier|static
specifier|inline
name|int
name|futexFlags
parameter_list|()
block|{
name|int
name|value
init|=
name|futexFlagSupport
operator|.
name|load
argument_list|()
decl_stmt|;
if|if
condition|(
name|Q_LIKELY
argument_list|(
name|value
operator|!=
operator|-
literal|1
argument_list|)
condition|)
return|return
name|value
return|;
return|return
name|checkFutexPrivateSupport
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|int
name|_q_futex
parameter_list|(
name|void
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
parameter_list|)
name|Q_DECL_NOTHROW
block|{
specifier|volatile
name|int
modifier|*
name|int_addr
init|=
cast|reinterpret_cast
argument_list|<
specifier|volatile
name|int
operator|*
argument_list|>
argument_list|(
name|addr
argument_list|)
decl_stmt|;
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_BIG_ENDIAN
operator|&&
name|QT_POINTER_SIZE
operator|==
literal|8
name|int_addr
operator|++
expr_stmt|;
comment|//We want a pointer to the 32 least significant bit of QMutex::d
endif|#
directive|endif
name|int
modifier|*
name|addr2
init|=
literal|0
decl_stmt|;
name|int
name|val2
init|=
literal|0
decl_stmt|;
comment|// we use __NR_futex because some libcs (like Android's bionic) don't
comment|// provide SYS_futex etc.
return|return
name|syscall
argument_list|(
name|__NR_futex
argument_list|,
name|int_addr
argument_list|,
name|op
operator||
name|futexFlags
argument_list|()
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
DECL|function|dummyFutexValue
specifier|static
specifier|inline
name|QMutexData
modifier|*
name|dummyFutexValue
parameter_list|()
block|{
return|return
cast|reinterpret_cast
argument_list|<
name|QMutexData
operator|*
argument_list|>
argument_list|(
name|quintptr
argument_list|(
literal|3
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
name|bool
name|QBasicMutex
operator|::
name|lockInternal
parameter_list|(
name|int
name|timeout
parameter_list|)
name|Q_DECL_NOTHROW
block|{
name|QElapsedTimer
name|elapsedTimer
decl_stmt|;
if|if
condition|(
name|timeout
operator|>=
literal|1
condition|)
name|elapsedTimer
operator|.
name|start
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|fastTryLock
argument_list|()
condition|)
block|{
name|QMutexData
modifier|*
name|d
init|=
name|d_ptr
operator|.
name|load
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|d
condition|)
comment|// if d is 0, the mutex is unlocked
continue|continue;
if|if
condition|(
name|quintptr
argument_list|(
name|d
argument_list|)
operator|<=
literal|0x3
condition|)
block|{
comment|//d == dummyLocked() || d == dummyFutexValue()
if|if
condition|(
name|timeout
operator|==
literal|0
condition|)
return|return
literal|false
return|;
while|while
condition|(
name|d_ptr
operator|.
name|fetchAndStoreAcquire
argument_list|(
name|dummyFutexValue
argument_list|()
argument_list|)
operator|!=
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
literal|1
condition|)
block|{
comment|// recalculate the timeout
name|qint64
name|xtimeout
init|=
name|qint64
argument_list|(
name|timeout
argument_list|)
operator|*
literal|1000
operator|*
literal|1000
decl_stmt|;
name|xtimeout
operator|-=
name|elapsedTimer
operator|.
name|nsecsElapsed
argument_list|()
expr_stmt|;
if|if
condition|(
name|xtimeout
operator|<=
literal|0
condition|)
block|{
comment|// timer expired after we returned
return|return
literal|false
return|;
block|}
name|ts
operator|.
name|tv_sec
operator|=
name|xtimeout
operator|/
name|Q_INT64_C
argument_list|(
literal|1000
argument_list|)
operator|/
literal|1000
operator|/
literal|1000
expr_stmt|;
name|ts
operator|.
name|tv_nsec
operator|=
name|xtimeout
operator|%
operator|(
name|Q_INT64_C
argument_list|(
literal|1000
argument_list|)
operator|*
literal|1000
operator|*
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
name|d_ptr
argument_list|,
name|FUTEX_WAIT
argument_list|,
name|quintptr
argument_list|(
name|dummyFutexValue
argument_list|()
argument_list|)
argument_list|,
name|pts
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
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|recursive
argument_list|)
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|QRecursiveMutexPrivate
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|lock
argument_list|(
name|timeout
argument_list|)
return|;
block|}
name|Q_ASSERT
argument_list|(
name|d_ptr
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
name|void
name|QBasicMutex
operator|::
name|unlockInternal
parameter_list|()
name|Q_DECL_NOTHROW
block|{
name|QMutexData
modifier|*
name|d
init|=
name|d_ptr
operator|.
name|load
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|d
argument_list|)
expr_stmt|;
comment|//we must be locked
name|Q_ASSERT
argument_list|(
name|d
operator|!=
name|dummyLocked
argument_list|()
argument_list|)
expr_stmt|;
comment|// testAndSetRelease(dummyLocked(), 0) failed
if|if
condition|(
name|d
operator|==
name|dummyFutexValue
argument_list|()
condition|)
block|{
name|d_ptr
operator|.
name|fetchAndStoreRelease
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|_q_futex
argument_list|(
operator|&
name|d_ptr
argument_list|,
name|FUTEX_WAKE
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|recursive
argument_list|)
expr_stmt|;
cast|static_cast
argument_list|<
name|QRecursiveMutexPrivate
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|unlock
argument_list|()
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
comment|// QT_NO_THREAD
end_comment
end_unit
