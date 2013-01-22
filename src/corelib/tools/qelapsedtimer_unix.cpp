begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// ask for the latest POSIX, just in case
end_comment
begin_define
DECL|macro|_POSIX_C_SOURCE
define|#
directive|define
name|_POSIX_C_SOURCE
value|200809L
end_define
begin_include
include|#
directive|include
file|"qelapsedtimer.h"
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
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<qatomic.h>
end_include
begin_include
include|#
directive|include
file|"private/qcore_unix_p.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_CLOCK_MONOTONIC
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
end_if
begin_comment
comment|// turn off the monotonic clock
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_MONOTONIC_CLOCK
end_ifdef
begin_undef
DECL|macro|_POSIX_MONOTONIC_CLOCK
undef|#
directive|undef
name|_POSIX_MONOTONIC_CLOCK
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|_POSIX_MONOTONIC_CLOCK
define|#
directive|define
name|_POSIX_MONOTONIC_CLOCK
value|-1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*  * Design:  *  * POSIX offers a facility to select the system's monotonic clock when getting  * the current timestamp. Whereas the functions are mandatory in POSIX.1-2008,  * the presence of a monotonic clock is a POSIX Option (see the document  *  http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap02.html#tag_02_01_06 )  *  * The macro _POSIX_MONOTONIC_CLOCK can therefore assume the following values:  *  -1          monotonic clock is never supported on this system  *   0          monotonic clock might be supported, runtime check is needed  *>1          (such as 200809L) monotonic clock is always supported  *  * The unixCheckClockType() function will return the clock to use: either  * CLOCK_MONOTONIC or CLOCK_REALTIME. In the case the POSIX option has a value  * of zero, then this function stores a static that contains the clock to be  * used.  *  * There's one extra case, which is when CLOCK_REALTIME isn't defined. When  * that's the case, we'll emulate the clock_gettime function with gettimeofday.  *  * Conforming to:  *  POSIX.1b-1993 section "Clocks and Timers"  *  included in UNIX98 (Single Unix Specification v2)  *  included in POSIX.1-2001  *  see http://pubs.opengroup.org/onlinepubs/9699919799/functions/clock_getres.html  */
ifndef|#
directive|ifndef
name|CLOCK_REALTIME
DECL|macro|CLOCK_REALTIME
define|#
directive|define
name|CLOCK_REALTIME
value|0
DECL|function|qt_clock_gettime
specifier|static
specifier|inline
name|void
name|qt_clock_gettime
parameter_list|(
name|int
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
block|{
comment|// support clock_gettime with gettimeofday
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
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_MONOTONIC_CLOCK
end_ifdef
begin_undef
DECL|macro|_POSIX_MONOTONIC_CLOCK
undef|#
directive|undef
name|_POSIX_MONOTONIC_CLOCK
end_undef
begin_define
DECL|macro|_POSIX_MONOTONIC_CLOCK
define|#
directive|define
name|_POSIX_MONOTONIC_CLOCK
value|-1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_function
specifier|static
specifier|inline
name|void
name|qt_clock_gettime
parameter_list|(
name|clockid_t
name|clock
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
block|{
name|clock_gettime
argument_list|(
name|clock
argument_list|,
name|ts
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|unixCheckClockType
specifier|static
name|int
name|unixCheckClockType
parameter_list|()
block|{
if|#
directive|if
operator|(
name|_POSIX_MONOTONIC_CLOCK
operator|-
literal|0
operator|==
literal|0
operator|)
operator|&&
name|defined
argument_list|(
name|_SC_MONOTONIC_CLOCK
argument_list|)
comment|// we need a value we can store in a clockid_t that isn't a valid clock
comment|// check if the valid ones are both non-negative or both non-positive
if|#
directive|if
name|CLOCK_MONOTONIC
operator|>=
literal|0
operator|&&
name|CLOCK_REALTIME
operator|>=
literal|0
DECL|macro|IS_VALID_CLOCK
define|#
directive|define
name|IS_VALID_CLOCK
parameter_list|(
name|clock
parameter_list|)
value|(clock>= 0)
DECL|macro|INVALID_CLOCK
define|#
directive|define
name|INVALID_CLOCK
value|-1
elif|#
directive|elif
name|CLOCK_MONOTONIC
operator|<=
literal|0
operator|&&
name|CLOCK_REALTIME
operator|<=
literal|0
define|#
directive|define
name|IS_VALID_CLOCK
parameter_list|(
name|clock
parameter_list|)
value|(clock<= 0)
define|#
directive|define
name|INVALID_CLOCK
value|1
else|#
directive|else
error|#
directive|error
literal|"Sorry, your system has weird values for CLOCK_MONOTONIC and CLOCK_REALTIME"
endif|#
directive|endif
specifier|static
name|QBasicAtomicInt
name|clockToUse
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
name|INVALID_CLOCK
argument_list|)
decl_stmt|;
name|int
name|clock
init|=
name|clockToUse
operator|.
name|loadAcquire
argument_list|()
decl_stmt|;
if|if
condition|(
name|Q_LIKELY
argument_list|(
name|IS_VALID_CLOCK
argument_list|(
name|clock
argument_list|)
argument_list|)
condition|)
return|return
name|clock
return|;
comment|// detect if the system supports monotonic timers
name|clock
operator|=
name|sysconf
argument_list|(
name|_SC_MONOTONIC_CLOCK
argument_list|)
operator|>
literal|0
condition|?
name|CLOCK_MONOTONIC
else|:
name|CLOCK_REALTIME
expr_stmt|;
name|clockToUse
operator|.
name|storeRelease
argument_list|(
name|clock
argument_list|)
expr_stmt|;
return|return
name|clock
return|;
DECL|macro|INVALID_CLOCK
undef|#
directive|undef
name|INVALID_CLOCK
DECL|macro|IS_VALID_CLOCK
undef|#
directive|undef
name|IS_VALID_CLOCK
elif|#
directive|elif
operator|(
name|_POSIX_MONOTONIC_CLOCK
operator|-
literal|0
operator|)
operator|>
literal|0
return|return
name|CLOCK_MONOTONIC
return|;
else|#
directive|else
return|return
name|CLOCK_REALTIME
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|fractionAdjustment
specifier|static
specifier|inline
name|qint64
name|fractionAdjustment
parameter_list|()
block|{
return|return
literal|1000
operator|*
literal|1000ull
return|;
block|}
end_function
begin_function
name|bool
name|QElapsedTimer
operator|::
name|isMonotonic
parameter_list|()
name|Q_DECL_NOTHROW
block|{
return|return
name|clockType
argument_list|()
operator|==
name|MonotonicClock
return|;
block|}
end_function
begin_function
name|QElapsedTimer
operator|::
name|ClockType
name|QElapsedTimer
operator|::
name|clockType
parameter_list|()
name|Q_DECL_NOTHROW
block|{
return|return
name|unixCheckClockType
argument_list|()
operator|==
name|CLOCK_REALTIME
condition|?
name|SystemTime
else|:
name|MonotonicClock
return|;
block|}
end_function
begin_function
DECL|function|do_gettime
specifier|static
specifier|inline
name|void
name|do_gettime
parameter_list|(
name|qint64
modifier|*
name|sec
parameter_list|,
name|qint64
modifier|*
name|frac
parameter_list|)
block|{
name|timespec
name|ts
decl_stmt|;
name|qt_clock_gettime
argument_list|(
name|unixCheckClockType
argument_list|()
argument_list|,
operator|&
name|ts
argument_list|)
expr_stmt|;
operator|*
name|sec
operator|=
name|ts
operator|.
name|tv_sec
expr_stmt|;
operator|*
name|frac
operator|=
name|ts
operator|.
name|tv_nsec
expr_stmt|;
block|}
end_function
begin_comment
comment|// used in qcore_unix.cpp and qeventdispatcher_unix.cpp
end_comment
begin_function
name|timeval
name|qt_gettime
parameter_list|()
name|Q_DECL_NOTHROW
block|{
name|qint64
name|sec
decl_stmt|,
name|frac
decl_stmt|;
name|do_gettime
argument_list|(
operator|&
name|sec
argument_list|,
operator|&
name|frac
argument_list|)
expr_stmt|;
name|timeval
name|tv
decl_stmt|;
name|tv
operator|.
name|tv_sec
operator|=
name|sec
expr_stmt|;
name|tv
operator|.
name|tv_usec
operator|=
name|frac
operator|/
literal|1000
expr_stmt|;
return|return
name|tv
return|;
block|}
end_function
begin_function
DECL|function|qt_nanosleep
name|void
name|qt_nanosleep
parameter_list|(
name|timespec
name|amount
parameter_list|)
block|{
comment|// We'd like to use clock_nanosleep.
comment|//
comment|// But clock_nanosleep is from POSIX.1-2001 and both are *not*
comment|// affected by clock changes when using relative sleeps, even for
comment|// CLOCK_REALTIME.
comment|//
comment|// nanosleep is POSIX.1-1993
name|int
name|r
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|r
argument_list|,
name|nanosleep
argument_list|(
operator|&
name|amount
argument_list|,
operator|&
name|amount
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|elapsedAndRestart
specifier|static
name|qint64
name|elapsedAndRestart
parameter_list|(
name|qint64
name|sec
parameter_list|,
name|qint64
name|frac
parameter_list|,
name|qint64
modifier|*
name|nowsec
parameter_list|,
name|qint64
modifier|*
name|nowfrac
parameter_list|)
block|{
name|do_gettime
argument_list|(
name|nowsec
argument_list|,
name|nowfrac
argument_list|)
expr_stmt|;
name|sec
operator|=
operator|*
name|nowsec
operator|-
name|sec
expr_stmt|;
name|frac
operator|=
operator|*
name|nowfrac
operator|-
name|frac
expr_stmt|;
return|return
name|sec
operator|*
name|Q_INT64_C
argument_list|(
literal|1000
argument_list|)
operator|+
name|frac
operator|/
name|fractionAdjustment
argument_list|()
return|;
block|}
end_function
begin_function
name|void
name|QElapsedTimer
operator|::
name|start
parameter_list|()
name|Q_DECL_NOTHROW
block|{
name|do_gettime
argument_list|(
operator|&
name|t1
argument_list|,
operator|&
name|t2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|qint64
name|QElapsedTimer
operator|::
name|restart
parameter_list|()
name|Q_DECL_NOTHROW
block|{
return|return
name|elapsedAndRestart
argument_list|(
name|t1
argument_list|,
name|t2
argument_list|,
operator|&
name|t1
argument_list|,
operator|&
name|t2
argument_list|)
return|;
block|}
end_function
begin_function
name|qint64
name|QElapsedTimer
operator|::
name|nsecsElapsed
parameter_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
name|qint64
name|sec
decl_stmt|,
name|frac
decl_stmt|;
name|do_gettime
argument_list|(
operator|&
name|sec
argument_list|,
operator|&
name|frac
argument_list|)
expr_stmt|;
name|sec
operator|=
name|sec
operator|-
name|t1
expr_stmt|;
name|frac
operator|=
name|frac
operator|-
name|t2
expr_stmt|;
return|return
name|sec
operator|*
name|Q_INT64_C
argument_list|(
literal|1000000000
argument_list|)
operator|+
name|frac
return|;
block|}
end_function
begin_function
name|qint64
name|QElapsedTimer
operator|::
name|elapsed
parameter_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
name|qint64
name|sec
decl_stmt|,
name|frac
decl_stmt|;
return|return
name|elapsedAndRestart
argument_list|(
name|t1
argument_list|,
name|t2
argument_list|,
operator|&
name|sec
argument_list|,
operator|&
name|frac
argument_list|)
return|;
block|}
end_function
begin_function
name|qint64
name|QElapsedTimer
operator|::
name|msecsSinceReference
parameter_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|t1
operator|*
name|Q_INT64_C
argument_list|(
literal|1000
argument_list|)
operator|+
name|t2
operator|/
name|fractionAdjustment
argument_list|()
return|;
block|}
end_function
begin_function
name|qint64
name|QElapsedTimer
operator|::
name|msecsTo
parameter_list|(
specifier|const
name|QElapsedTimer
modifier|&
name|other
parameter_list|)
specifier|const
name|Q_DECL_NOTHROW
block|{
name|qint64
name|secs
init|=
name|other
operator|.
name|t1
operator|-
name|t1
decl_stmt|;
name|qint64
name|fraction
init|=
name|other
operator|.
name|t2
operator|-
name|t2
decl_stmt|;
return|return
name|secs
operator|*
name|Q_INT64_C
argument_list|(
literal|1000
argument_list|)
operator|+
name|fraction
operator|/
name|fractionAdjustment
argument_list|()
return|;
block|}
end_function
begin_function
name|qint64
name|QElapsedTimer
operator|::
name|secsTo
parameter_list|(
specifier|const
name|QElapsedTimer
modifier|&
name|other
parameter_list|)
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|other
operator|.
name|t1
operator|-
name|t1
return|;
block|}
end_function
begin_function
name|bool
name|operator
name|<
parameter_list|(
specifier|const
name|QElapsedTimer
modifier|&
name|v1
parameter_list|,
specifier|const
name|QElapsedTimer
modifier|&
name|v2
parameter_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|v1
operator|.
name|t1
operator|<
name|v2
operator|.
name|t1
operator|||
operator|(
name|v1
operator|.
name|t1
operator|==
name|v2
operator|.
name|t1
operator|&&
name|v1
operator|.
name|t2
operator|<
name|v2
operator|.
name|t2
operator|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
