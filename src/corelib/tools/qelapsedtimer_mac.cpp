begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<mach/mach_time.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|clockType
name|QElapsedTimer
operator|::
name|ClockType
name|QElapsedTimer
operator|::
name|clockType
parameter_list|()
block|{
return|return
name|MachAbsoluteTime
return|;
block|}
end_function
begin_function
DECL|function|isMonotonic
name|bool
name|QElapsedTimer
operator|::
name|isMonotonic
parameter_list|()
block|{
return|return
literal|true
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|info
specifier|static
name|mach_timebase_info_data_t
name|info
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|absoluteToNSecs
specifier|static
name|qint64
name|absoluteToNSecs
parameter_list|(
name|qint64
name|cpuTime
parameter_list|)
block|{
if|if
condition|(
name|info
operator|.
name|denom
operator|==
literal|0
condition|)
name|mach_timebase_info
argument_list|(
operator|&
name|info
argument_list|)
expr_stmt|;
name|qint64
name|nsecs
init|=
name|cpuTime
operator|*
name|info
operator|.
name|numer
operator|/
name|info
operator|.
name|denom
decl_stmt|;
return|return
name|nsecs
return|;
block|}
end_function
begin_function
DECL|function|absoluteToMSecs
specifier|static
name|qint64
name|absoluteToMSecs
parameter_list|(
name|qint64
name|cpuTime
parameter_list|)
block|{
return|return
name|absoluteToNSecs
argument_list|(
name|cpuTime
argument_list|)
operator|/
literal|1000000
return|;
block|}
end_function
begin_function
DECL|function|qt_gettime
name|timeval
name|qt_gettime
parameter_list|()
block|{
name|timeval
name|tv
decl_stmt|;
name|uint64_t
name|cpu_time
init|=
name|mach_absolute_time
argument_list|()
decl_stmt|;
name|uint64_t
name|nsecs
init|=
name|absoluteToNSecs
argument_list|(
name|cpu_time
argument_list|)
decl_stmt|;
name|tv
operator|.
name|tv_sec
operator|=
name|nsecs
operator|/
literal|1000000000ull
expr_stmt|;
name|tv
operator|.
name|tv_usec
operator|=
operator|(
name|nsecs
operator|/
literal|1000
operator|)
operator|-
operator|(
name|tv
operator|.
name|tv_sec
operator|*
literal|1000000
operator|)
expr_stmt|;
return|return
name|tv
return|;
block|}
end_function
begin_function
DECL|function|start
name|void
name|QElapsedTimer
operator|::
name|start
parameter_list|()
block|{
name|t1
operator|=
name|mach_absolute_time
argument_list|()
expr_stmt|;
name|t2
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|restart
name|qint64
name|QElapsedTimer
operator|::
name|restart
parameter_list|()
block|{
name|qint64
name|old
init|=
name|t1
decl_stmt|;
name|t1
operator|=
name|mach_absolute_time
argument_list|()
expr_stmt|;
name|t2
operator|=
literal|0
expr_stmt|;
return|return
name|absoluteToMSecs
argument_list|(
name|t1
operator|-
name|old
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|nsecsElapsed
name|qint64
name|QElapsedTimer
operator|::
name|nsecsElapsed
parameter_list|()
specifier|const
block|{
name|uint64_t
name|cpu_time
init|=
name|mach_absolute_time
argument_list|()
decl_stmt|;
return|return
name|absoluteToNSecs
argument_list|(
name|cpu_time
operator|-
name|t1
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|elapsed
name|qint64
name|QElapsedTimer
operator|::
name|elapsed
parameter_list|()
specifier|const
block|{
name|uint64_t
name|cpu_time
init|=
name|mach_absolute_time
argument_list|()
decl_stmt|;
return|return
name|absoluteToMSecs
argument_list|(
name|cpu_time
operator|-
name|t1
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|msecsSinceReference
name|qint64
name|QElapsedTimer
operator|::
name|msecsSinceReference
parameter_list|()
specifier|const
block|{
return|return
name|absoluteToMSecs
argument_list|(
name|t1
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|msecsTo
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
block|{
return|return
name|absoluteToMSecs
argument_list|(
name|other
operator|.
name|t1
operator|-
name|t1
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|secsTo
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
block|{
return|return
name|msecsTo
argument_list|(
name|other
argument_list|)
operator|/
literal|1000
return|;
block|}
end_function
begin_function
DECL|function|operator <
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
block|{
return|return
name|v1
operator|.
name|t1
operator|<
name|v2
operator|.
name|t1
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
