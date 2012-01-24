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
file|<windows.h>
end_include
begin_comment
comment|// Result of QueryPerformanceFrequency, 0 indicates that the high resolution timer is unavailable
end_comment
begin_decl_stmt
DECL|variable|counterFrequency
specifier|static
name|quint64
name|counterFrequency
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|PtrGetTickCount64
typedef|typedef
name|ULONGLONG
function_decl|(
name|WINAPI
modifier|*
name|PtrGetTickCount64
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
DECL|variable|ptrGetTickCount64
specifier|static
name|PtrGetTickCount64
name|ptrGetTickCount64
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|resolveLibs
specifier|static
name|void
name|resolveLibs
parameter_list|()
block|{
specifier|static
name|bool
name|done
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|done
condition|)
return|return;
comment|// try to get GetTickCount64 from the system
name|HMODULE
name|kernel32
init|=
name|GetModuleHandleW
argument_list|(
literal|L"kernel32"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|kernel32
condition|)
return|return;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
comment|// does this function exist on WinCE, or will ever exist?
name|ptrGetTickCount64
operator|=
operator|(
name|PtrGetTickCount64
operator|)
name|GetProcAddress
argument_list|(
name|kernel32
argument_list|,
literal|L"GetTickCount64"
argument_list|)
expr_stmt|;
else|#
directive|else
name|ptrGetTickCount64
operator|=
operator|(
name|PtrGetTickCount64
operator|)
name|GetProcAddress
argument_list|(
name|kernel32
argument_list|,
literal|"GetTickCount64"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Retrieve the number of high-resolution performance counter ticks per second
name|LARGE_INTEGER
name|frequency
decl_stmt|;
if|if
condition|(
operator|!
name|QueryPerformanceFrequency
argument_list|(
operator|&
name|frequency
argument_list|)
condition|)
block|{
name|counterFrequency
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|counterFrequency
operator|=
name|frequency
operator|.
name|QuadPart
expr_stmt|;
block|}
name|done
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|ticksToNanoseconds
specifier|static
specifier|inline
name|qint64
name|ticksToNanoseconds
parameter_list|(
name|qint64
name|ticks
parameter_list|)
block|{
if|if
condition|(
name|counterFrequency
operator|>
literal|0
condition|)
block|{
comment|// QueryPerformanceCounter uses an arbitrary frequency
return|return
name|ticks
operator|*
literal|1000000000
operator|/
name|counterFrequency
return|;
block|}
else|else
block|{
comment|// GetTickCount(64) return milliseconds
return|return
name|ticks
operator|*
literal|1000000
return|;
block|}
block|}
end_function
begin_function
DECL|function|getTickCount
specifier|static
name|quint64
name|getTickCount
parameter_list|()
block|{
name|resolveLibs
argument_list|()
expr_stmt|;
comment|// This avoids a division by zero and disables the high performance counter if it's not available
if|if
condition|(
name|counterFrequency
operator|>
literal|0
condition|)
block|{
name|LARGE_INTEGER
name|counter
decl_stmt|;
if|if
condition|(
name|QueryPerformanceCounter
argument_list|(
operator|&
name|counter
argument_list|)
condition|)
block|{
return|return
name|counter
operator|.
name|QuadPart
return|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QueryPerformanceCounter failed, although QueryPerformanceFrequency succeeded."
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
if|if
condition|(
name|ptrGetTickCount64
condition|)
return|return
name|ptrGetTickCount64
argument_list|()
return|;
specifier|static
name|quint32
name|highdword
init|=
literal|0
decl_stmt|;
specifier|static
name|quint32
name|lastval
init|=
literal|0
decl_stmt|;
name|quint32
name|val
init|=
name|GetTickCount
argument_list|()
decl_stmt|;
if|if
condition|(
name|val
operator|<
name|lastval
condition|)
operator|++
name|highdword
expr_stmt|;
name|lastval
operator|=
name|val
expr_stmt|;
return|return
name|val
operator||
operator|(
name|quint64
argument_list|(
name|highdword
argument_list|)
operator|<<
literal|32
operator|)
return|;
block|}
end_function
begin_function
DECL|function|clockType
name|QElapsedTimer
operator|::
name|ClockType
name|QElapsedTimer
operator|::
name|clockType
parameter_list|()
block|{
name|resolveLibs
argument_list|()
expr_stmt|;
if|if
condition|(
name|counterFrequency
operator|>
literal|0
condition|)
return|return
name|PerformanceCounter
return|;
else|else
return|return
name|TickCounter
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
name|getTickCount
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
name|oldt1
init|=
name|t1
decl_stmt|;
name|t1
operator|=
name|getTickCount
argument_list|()
expr_stmt|;
name|t2
operator|=
literal|0
expr_stmt|;
return|return
name|ticksToNanoseconds
argument_list|(
name|t1
operator|-
name|oldt1
argument_list|)
operator|/
literal|1000000
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
name|qint64
name|elapsed
init|=
name|getTickCount
argument_list|()
operator|-
name|t1
decl_stmt|;
return|return
name|ticksToNanoseconds
argument_list|(
name|elapsed
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
name|qint64
name|elapsed
init|=
name|getTickCount
argument_list|()
operator|-
name|t1
decl_stmt|;
return|return
name|ticksToNanoseconds
argument_list|(
name|elapsed
argument_list|)
operator|/
literal|1000000
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
name|ticksToNanoseconds
argument_list|(
name|t1
argument_list|)
operator|/
literal|1000000
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
name|qint64
name|difference
init|=
name|other
operator|.
name|t1
operator|-
name|t1
decl_stmt|;
return|return
name|ticksToNanoseconds
argument_list|(
name|difference
argument_list|)
operator|/
literal|1000000
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
operator|(
name|v1
operator|.
name|t1
operator|-
name|v2
operator|.
name|t1
operator|)
operator|<
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
