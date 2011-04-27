begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtconcurrentiteratekernel.h"
end_include
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
file|<mach/mach_time.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
end_elif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_HURD
argument_list|)
end_if
begin_include
include|#
directive|include
file|<sys/time.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<time.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"private/qfunctions_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONCURRENT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|enum
type|{
DECL|enumerator|TargetRatio
name|TargetRatio
init|=
literal|100
decl_stmt|,
DECL|enumerator|MedianSize
name|MedianSize
init|=
literal|7
end_decl_stmt
begin_if
unit|};
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_function
DECL|function|getticks
specifier|static
name|qint64
name|getticks
parameter_list|()
block|{
return|return
name|mach_absolute_time
argument_list|()
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
end_elif
begin_function
DECL|function|getticks
specifier|static
name|qint64
name|getticks
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_TIMERS
argument_list|)
operator|&&
operator|(
name|_POSIX_TIMERS
operator|>
literal|0
operator|)
name|clockid_t
name|clockId
decl_stmt|;
ifndef|#
directive|ifndef
name|_POSIX_THREAD_CPUTIME
name|clockId
operator|=
name|CLOCK_REALTIME
expr_stmt|;
elif|#
directive|elif
operator|(
name|_POSIX_THREAD_CPUTIME
operator|-
literal|0
operator|<=
literal|0
operator|)
comment|// if we don't have CLOCK_THREAD_CPUTIME_ID, we have to just use elapsed realtime instead
name|clockId
operator|=
name|CLOCK_REALTIME
expr_stmt|;
if|#
directive|if
operator|(
name|_POSIX_THREAD_CPUTIME
operator|-
literal|0
operator|==
literal|0
operator|)
comment|// detect availablility of CLOCK_THREAD_CPUTIME_ID
specifier|static
name|long
name|useThreadCpuTime
init|=
operator|-
literal|2
decl_stmt|;
if|if
condition|(
name|useThreadCpuTime
operator|==
operator|-
literal|2
condition|)
block|{
comment|// sysconf() will return either -1 or _POSIX_VERSION (don't care about thread races here)
name|useThreadCpuTime
operator|=
name|sysconf
argument_list|(
name|_SC_THREAD_CPUTIME
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|useThreadCpuTime
operator|!=
operator|-
literal|1
condition|)
name|clockId
operator|=
name|CLOCK_THREAD_CPUTIME_ID
expr_stmt|;
endif|#
directive|endif
else|#
directive|else
name|clockId
operator|=
name|CLOCK_THREAD_CPUTIME_ID
expr_stmt|;
endif|#
directive|endif
name|struct
name|timespec
name|ts
decl_stmt|;
if|if
condition|(
name|clock_gettime
argument_list|(
name|clockId
argument_list|,
operator|&
name|ts
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
literal|0
return|;
return|return
operator|(
name|ts
operator|.
name|tv_sec
operator|*
literal|1000000000
operator|)
operator|+
name|ts
operator|.
name|tv_nsec
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
return|return
name|clock
argument_list|()
return|;
else|#
directive|else
comment|// no clock_gettime(), fall back to wall time
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
return|return
operator|(
name|tv
operator|.
name|tv_sec
operator|*
literal|1000000
operator|)
operator|+
name|tv
operator|.
name|tv_usec
return|;
endif|#
directive|endif
endif|#
directive|endif
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_elif
begin_function
DECL|function|getticks
specifier|static
name|qint64
name|getticks
parameter_list|()
block|{
name|LARGE_INTEGER
name|x
decl_stmt|;
if|if
condition|(
operator|!
name|QueryPerformanceCounter
argument_list|(
operator|&
name|x
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
name|x
operator|.
name|QuadPart
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|elapsed
specifier|static
name|double
name|elapsed
parameter_list|(
name|qint64
name|after
parameter_list|,
name|qint64
name|before
parameter_list|)
block|{
return|return
name|double
argument_list|(
name|after
operator|-
name|before
argument_list|)
return|;
block|}
end_function
begin_namespace
DECL|namespace|QtConcurrent
namespace|namespace
name|QtConcurrent
block|{
comment|/*! \internal  */
DECL|function|BlockSizeManager
name|BlockSizeManager
operator|::
name|BlockSizeManager
parameter_list|(
name|int
name|iterationCount
parameter_list|)
member_init_list|:
name|maxBlockSize
argument_list|(
name|iterationCount
operator|/
operator|(
name|QThreadPool
operator|::
name|globalInstance
argument_list|()
operator|->
name|maxThreadCount
argument_list|()
operator|*
literal|2
operator|)
argument_list|)
member_init_list|,
name|beforeUser
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|afterUser
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|controlPartElapsed
argument_list|(
name|MedianSize
argument_list|)
member_init_list|,
name|userPartElapsed
argument_list|(
name|MedianSize
argument_list|)
member_init_list|,
name|m_blockSize
argument_list|(
literal|1
argument_list|)
block|{ }
comment|// Records the time before user code.
DECL|function|timeBeforeUser
name|void
name|BlockSizeManager
operator|::
name|timeBeforeUser
parameter_list|()
block|{
if|if
condition|(
name|blockSizeMaxed
argument_list|()
condition|)
return|return;
name|beforeUser
operator|=
name|getticks
argument_list|()
expr_stmt|;
name|controlPartElapsed
operator|.
name|addValue
argument_list|(
name|elapsed
argument_list|(
name|beforeUser
argument_list|,
name|afterUser
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Records the time after user code and adjust the block size if we are spending
comment|// to much time in the for control code compared with the user code.
DECL|function|timeAfterUser
name|void
name|BlockSizeManager
operator|::
name|timeAfterUser
parameter_list|()
block|{
if|if
condition|(
name|blockSizeMaxed
argument_list|()
condition|)
return|return;
name|afterUser
operator|=
name|getticks
argument_list|()
expr_stmt|;
name|userPartElapsed
operator|.
name|addValue
argument_list|(
name|elapsed
argument_list|(
name|afterUser
argument_list|,
name|beforeUser
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|controlPartElapsed
operator|.
name|isMedianValid
argument_list|()
operator|==
literal|false
condition|)
return|return;
if|if
condition|(
name|controlPartElapsed
operator|.
name|median
argument_list|()
operator|*
name|TargetRatio
operator|<
name|userPartElapsed
operator|.
name|median
argument_list|()
condition|)
return|return;
name|m_blockSize
operator|=
name|qMin
argument_list|(
name|m_blockSize
operator|*
literal|2
argument_list|,
name|maxBlockSize
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QTCONCURRENT_FOR_DEBUG
name|qDebug
argument_list|()
operator|<<
name|QThread
operator|::
name|currentThread
argument_list|()
operator|<<
literal|"adjusting block size"
operator|<<
name|controlPartElapsed
operator|.
name|median
argument_list|()
operator|<<
name|userPartElapsed
operator|.
name|median
argument_list|()
operator|<<
name|m_blockSize
expr_stmt|;
endif|#
directive|endif
comment|// Reset the medians after adjusting the block size so we get
comment|// new measurements with the new block size.
name|controlPartElapsed
operator|.
name|reset
argument_list|()
expr_stmt|;
name|userPartElapsed
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
DECL|function|blockSize
name|int
name|BlockSizeManager
operator|::
name|blockSize
parameter_list|()
block|{
return|return
name|m_blockSize
return|;
block|}
block|}
end_namespace
begin_comment
comment|// namespace QtConcurrent
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CONCURRENT
end_comment
end_unit
