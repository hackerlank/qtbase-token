begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QtCore>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
end_ifdef
begin_include
include|#
directive|include
file|<e32std.h>
end_include
begin_typedef
DECL|typedef|NativeMutexType
typedef|typedef
name|RMutex
name|NativeMutexType
typedef|;
end_typedef
begin_function
DECL|function|NativeMutexInitialize
name|void
name|NativeMutexInitialize
parameter_list|(
name|NativeMutexType
modifier|*
name|mutex
parameter_list|)
block|{
name|mutex
operator|->
name|CreateLocal
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|NativeMutexDestroy
name|void
name|NativeMutexDestroy
parameter_list|(
name|NativeMutexType
modifier|*
name|mutex
parameter_list|)
block|{
name|mutex
operator|->
name|Close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|NativeMutexLock
name|void
name|NativeMutexLock
parameter_list|(
name|NativeMutexType
modifier|*
name|mutex
parameter_list|)
block|{
name|mutex
operator|->
name|Wait
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|NativeMutexUnlock
name|void
name|NativeMutexUnlock
parameter_list|(
name|NativeMutexType
modifier|*
name|mutex
parameter_list|)
block|{
name|mutex
operator|->
name|Signal
argument_list|()
expr_stmt|;
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
begin_include
include|#
directive|include
file|<pthread.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_typedef
DECL|typedef|NativeMutexType
typedef|typedef
name|pthread_mutex_t
name|NativeMutexType
typedef|;
end_typedef
begin_function
DECL|function|NativeMutexInitialize
name|void
name|NativeMutexInitialize
parameter_list|(
name|NativeMutexType
modifier|*
name|mutex
parameter_list|)
block|{
name|pthread_mutex_init
argument_list|(
name|mutex
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|NativeMutexDestroy
name|void
name|NativeMutexDestroy
parameter_list|(
name|NativeMutexType
modifier|*
name|mutex
parameter_list|)
block|{
name|pthread_mutex_destroy
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|NativeMutexLock
name|void
name|NativeMutexLock
parameter_list|(
name|NativeMutexType
modifier|*
name|mutex
parameter_list|)
block|{
name|pthread_mutex_lock
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|NativeMutexUnlock
name|void
name|NativeMutexUnlock
parameter_list|(
name|NativeMutexType
modifier|*
name|mutex
parameter_list|)
block|{
name|pthread_mutex_unlock
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
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
begin_define
DECL|macro|_WIN32_WINNT
define|#
directive|define
name|_WIN32_WINNT
value|0x0400
end_define
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_typedef
DECL|typedef|NativeMutexType
typedef|typedef
name|CRITICAL_SECTION
name|NativeMutexType
typedef|;
end_typedef
begin_function
DECL|function|NativeMutexInitialize
name|void
name|NativeMutexInitialize
parameter_list|(
name|NativeMutexType
modifier|*
name|mutex
parameter_list|)
block|{
name|InitializeCriticalSection
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|NativeMutexDestroy
name|void
name|NativeMutexDestroy
parameter_list|(
name|NativeMutexType
modifier|*
name|mutex
parameter_list|)
block|{
name|DeleteCriticalSection
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|NativeMutexLock
name|void
name|NativeMutexLock
parameter_list|(
name|NativeMutexType
modifier|*
name|mutex
parameter_list|)
block|{
name|EnterCriticalSection
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|NativeMutexUnlock
name|void
name|NativeMutexUnlock
parameter_list|(
name|NativeMutexType
modifier|*
name|mutex
parameter_list|)
block|{
name|LeaveCriticalSection
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_QMutex
class|class
name|tst_QMutex
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
DECL|member|threadCount
name|int
name|threadCount
decl_stmt|;
public|public:
comment|// barriers for the contended tests
DECL|member|semaphore1
DECL|member|semaphore2
DECL|member|semaphore3
DECL|member|semaphore4
specifier|static
name|QSemaphore
name|semaphore1
decl_stmt|,
name|semaphore2
decl_stmt|,
name|semaphore3
decl_stmt|,
name|semaphore4
decl_stmt|;
DECL|function|tst_QMutex
name|tst_QMutex
parameter_list|()
block|{
comment|// at least 2 threads, even on single cpu/core machines
name|threadCount
operator|=
name|qMax
argument_list|(
literal|2
argument_list|,
name|QThread
operator|::
name|idealThreadCount
argument_list|()
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"thread count: %d"
argument_list|,
name|threadCount
argument_list|)
expr_stmt|;
block|}
private|private
name|slots
private|:
name|void
name|noThread_data
parameter_list|()
function_decl|;
name|void
name|noThread
parameter_list|()
function_decl|;
name|void
name|constructionNative
parameter_list|()
function_decl|;
name|void
name|uncontendedNative
parameter_list|()
function_decl|;
name|void
name|constructionQMutex
parameter_list|()
function_decl|;
name|void
name|uncontendedQMutex
parameter_list|()
function_decl|;
name|void
name|uncontendedQMutexLocker
parameter_list|()
function_decl|;
name|void
name|contendedNative_data
parameter_list|()
function_decl|;
DECL|function|contendedQMutex_data
name|void
name|contendedQMutex_data
parameter_list|()
block|{
name|contendedNative_data
argument_list|()
expr_stmt|;
block|}
DECL|function|contendedQMutexLocker_data
name|void
name|contendedQMutexLocker_data
parameter_list|()
block|{
name|contendedNative_data
argument_list|()
expr_stmt|;
block|}
name|void
name|contendedNative
parameter_list|()
function_decl|;
name|void
name|contendedQMutex
parameter_list|()
function_decl|;
name|void
name|contendedQMutexLocker
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_decl_stmt
DECL|member|semaphore1
name|QSemaphore
name|tst_QMutex
operator|::
name|semaphore1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|semaphore2
name|QSemaphore
name|tst_QMutex
operator|::
name|semaphore2
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|semaphore3
name|QSemaphore
name|tst_QMutex
operator|::
name|semaphore3
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|semaphore4
name|QSemaphore
name|tst_QMutex
operator|::
name|semaphore4
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|noThread_data
name|void
name|tst_QMutex
operator|::
name|noThread_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"t"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"noLock"
argument_list|)
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QMutex"
argument_list|)
operator|<<
literal|3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QMutexLocker"
argument_list|)
operator|<<
literal|4
expr_stmt|;
block|}
end_function
begin_function
DECL|function|noThread
name|void
name|tst_QMutex
operator|::
name|noThread
parameter_list|()
block|{
specifier|volatile
name|int
name|count
init|=
literal|0
decl_stmt|;
specifier|const
name|int
name|N
init|=
literal|5000000
decl_stmt|;
name|QMutex
name|mtx
decl_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|t
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|t
condition|)
block|{
case|case
literal|1
case|:
name|QBENCHMARK
block|{
name|count
operator|=
literal|0
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
name|N
condition|;
name|i
operator|++
control|)
block|{
name|count
operator|++
expr_stmt|;
block|}
block|}
break|break;
case|case
literal|3
case|:
name|QBENCHMARK
block|{
name|count
operator|=
literal|0
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
name|N
condition|;
name|i
operator|++
control|)
block|{
name|mtx
operator|.
name|lock
argument_list|()
expr_stmt|;
name|count
operator|++
expr_stmt|;
name|mtx
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
block|}
break|break;
case|case
literal|4
case|:
name|QBENCHMARK
block|{
name|count
operator|=
literal|0
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
name|N
condition|;
name|i
operator|++
control|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mtx
argument_list|)
decl_stmt|;
name|count
operator|++
expr_stmt|;
block|}
block|}
break|break;
block|}
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|count
argument_list|)
argument_list|,
name|N
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|constructionNative
name|void
name|tst_QMutex
operator|::
name|constructionNative
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|NativeMutexType
name|mutex
decl_stmt|;
name|NativeMutexInitialize
argument_list|(
operator|&
name|mutex
argument_list|)
expr_stmt|;
name|NativeMutexDestroy
argument_list|(
operator|&
name|mutex
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|uncontendedNative
name|void
name|tst_QMutex
operator|::
name|uncontendedNative
parameter_list|()
block|{
name|NativeMutexType
name|mutex
decl_stmt|;
name|NativeMutexInitialize
argument_list|(
operator|&
name|mutex
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|NativeMutexLock
argument_list|(
operator|&
name|mutex
argument_list|)
expr_stmt|;
name|NativeMutexUnlock
argument_list|(
operator|&
name|mutex
argument_list|)
expr_stmt|;
block|}
name|NativeMutexDestroy
argument_list|(
operator|&
name|mutex
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|constructionQMutex
name|void
name|tst_QMutex
operator|::
name|constructionQMutex
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QMutex
name|mutex
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|uncontendedQMutex
name|void
name|tst_QMutex
operator|::
name|uncontendedQMutex
parameter_list|()
block|{
name|QMutex
name|mutex
decl_stmt|;
name|QBENCHMARK
block|{
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|uncontendedQMutexLocker
name|void
name|tst_QMutex
operator|::
name|uncontendedQMutexLocker
parameter_list|()
block|{
name|QMutex
name|mutex
decl_stmt|;
name|QBENCHMARK
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|contendedNative_data
name|void
name|tst_QMutex
operator|::
name|contendedNative_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"iterations"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"msleepDuration"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"use2mutexes"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"baseline"
argument_list|)
operator|<<
literal|0
operator|<<
operator|-
literal|1
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"no msleep, 1 mutex"
argument_list|)
operator|<<
literal|1000
operator|<<
operator|-
literal|1
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"no msleep, 2 mutexes"
argument_list|)
operator|<<
literal|1000
operator|<<
operator|-
literal|1
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"msleep(0), 1 mutex"
argument_list|)
operator|<<
literal|1000
operator|<<
literal|0
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"msleep(0), 2 mutexes"
argument_list|)
operator|<<
literal|1000
operator|<<
literal|0
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"msleep(1), 1 mutex"
argument_list|)
operator|<<
literal|10
operator|<<
literal|1
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"msleep(1), 2 mutexes"
argument_list|)
operator|<<
literal|10
operator|<<
literal|1
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"msleep(2), 1 mutex"
argument_list|)
operator|<<
literal|10
operator|<<
literal|2
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"msleep(2), 2 mutexes"
argument_list|)
operator|<<
literal|10
operator|<<
literal|2
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"msleep(10), 1 mutex"
argument_list|)
operator|<<
literal|10
operator|<<
literal|10
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"msleep(10), 2 mutexes"
argument_list|)
operator|<<
literal|10
operator|<<
literal|10
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_class
DECL|class|NativeMutexThread
class|class
name|NativeMutexThread
super|:
specifier|public
name|QThread
block|{
DECL|member|mutex1
DECL|member|mutex2
name|NativeMutexType
modifier|*
name|mutex1
decl_stmt|,
modifier|*
name|mutex2
decl_stmt|;
DECL|member|iterations
DECL|member|msleepDuration
name|int
name|iterations
decl_stmt|,
name|msleepDuration
decl_stmt|;
DECL|member|use2mutexes
name|bool
name|use2mutexes
decl_stmt|;
public|public:
DECL|member|done
name|bool
name|done
decl_stmt|;
DECL|function|NativeMutexThread
name|NativeMutexThread
parameter_list|(
name|NativeMutexType
modifier|*
name|mutex1
parameter_list|,
name|NativeMutexType
modifier|*
name|mutex2
parameter_list|,
name|int
name|iterations
parameter_list|,
name|int
name|msleepDuration
parameter_list|,
name|bool
name|use2mutexes
parameter_list|)
member_init_list|:
name|mutex1
argument_list|(
name|mutex1
argument_list|)
member_init_list|,
name|mutex2
argument_list|(
name|mutex2
argument_list|)
member_init_list|,
name|iterations
argument_list|(
name|iterations
argument_list|)
member_init_list|,
name|msleepDuration
argument_list|(
name|msleepDuration
argument_list|)
member_init_list|,
name|use2mutexes
argument_list|(
name|use2mutexes
argument_list|)
member_init_list|,
name|done
argument_list|(
literal|false
argument_list|)
block|{ }
DECL|function|run
name|void
name|run
parameter_list|()
block|{
forever|forever
block|{
name|tst_QMutex
operator|::
name|semaphore1
operator|.
name|release
argument_list|()
expr_stmt|;
name|tst_QMutex
operator|::
name|semaphore2
operator|.
name|acquire
argument_list|()
expr_stmt|;
if|if
condition|(
name|done
condition|)
break|break;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|iterations
condition|;
operator|++
name|i
control|)
block|{
name|NativeMutexLock
argument_list|(
name|mutex1
argument_list|)
expr_stmt|;
if|if
condition|(
name|use2mutexes
condition|)
name|NativeMutexLock
argument_list|(
name|mutex2
argument_list|)
expr_stmt|;
if|if
condition|(
name|msleepDuration
operator|>=
literal|0
condition|)
name|msleep
argument_list|(
name|msleepDuration
argument_list|)
expr_stmt|;
if|if
condition|(
name|use2mutexes
condition|)
name|NativeMutexUnlock
argument_list|(
name|mutex2
argument_list|)
expr_stmt|;
name|NativeMutexUnlock
argument_list|(
name|mutex1
argument_list|)
expr_stmt|;
name|QThread
operator|::
name|yieldCurrentThread
argument_list|()
expr_stmt|;
block|}
name|tst_QMutex
operator|::
name|semaphore3
operator|.
name|release
argument_list|()
expr_stmt|;
name|tst_QMutex
operator|::
name|semaphore4
operator|.
name|acquire
argument_list|()
expr_stmt|;
block|}
block|}
block|}
class|;
end_class
begin_function
DECL|function|contendedNative
name|void
name|tst_QMutex
operator|::
name|contendedNative
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|iterations
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|msleepDuration
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|use2mutexes
argument_list|)
expr_stmt|;
name|NativeMutexType
name|mutex1
decl_stmt|,
name|mutex2
decl_stmt|;
name|NativeMutexInitialize
argument_list|(
operator|&
name|mutex1
argument_list|)
expr_stmt|;
name|NativeMutexInitialize
argument_list|(
operator|&
name|mutex2
argument_list|)
expr_stmt|;
name|QVector
argument_list|<
name|NativeMutexThread
modifier|*
argument_list|>
name|threads
argument_list|(
name|threadCount
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|threads
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|threads
index|[
name|i
index|]
operator|=
operator|new
name|NativeMutexThread
argument_list|(
operator|&
name|mutex1
argument_list|,
operator|&
name|mutex2
argument_list|,
name|iterations
argument_list|,
name|msleepDuration
argument_list|,
name|use2mutexes
argument_list|)
expr_stmt|;
name|threads
index|[
name|i
index|]
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
name|QBENCHMARK
block|{
name|semaphore1
operator|.
name|acquire
argument_list|(
name|threadCount
argument_list|)
expr_stmt|;
name|semaphore2
operator|.
name|release
argument_list|(
name|threadCount
argument_list|)
expr_stmt|;
name|semaphore3
operator|.
name|acquire
argument_list|(
name|threadCount
argument_list|)
expr_stmt|;
name|semaphore4
operator|.
name|release
argument_list|(
name|threadCount
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|threads
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|threads
index|[
name|i
index|]
operator|->
name|done
operator|=
literal|true
expr_stmt|;
name|semaphore1
operator|.
name|acquire
argument_list|(
name|threadCount
argument_list|)
expr_stmt|;
name|semaphore2
operator|.
name|release
argument_list|(
name|threadCount
argument_list|)
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
name|threads
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|threads
index|[
name|i
index|]
operator|->
name|wait
argument_list|()
expr_stmt|;
name|qDeleteAll
argument_list|(
name|threads
argument_list|)
expr_stmt|;
name|NativeMutexDestroy
argument_list|(
operator|&
name|mutex1
argument_list|)
expr_stmt|;
name|NativeMutexDestroy
argument_list|(
operator|&
name|mutex2
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|QMutexThread
class|class
name|QMutexThread
super|:
specifier|public
name|QThread
block|{
DECL|member|mutex1
DECL|member|mutex2
name|QMutex
modifier|*
name|mutex1
decl_stmt|,
modifier|*
name|mutex2
decl_stmt|;
DECL|member|iterations
DECL|member|msleepDuration
name|int
name|iterations
decl_stmt|,
name|msleepDuration
decl_stmt|;
DECL|member|use2mutexes
name|bool
name|use2mutexes
decl_stmt|;
public|public:
DECL|member|done
name|bool
name|done
decl_stmt|;
DECL|function|QMutexThread
name|QMutexThread
parameter_list|(
name|QMutex
modifier|*
name|mutex1
parameter_list|,
name|QMutex
modifier|*
name|mutex2
parameter_list|,
name|int
name|iterations
parameter_list|,
name|int
name|msleepDuration
parameter_list|,
name|bool
name|use2mutexes
parameter_list|)
member_init_list|:
name|mutex1
argument_list|(
name|mutex1
argument_list|)
member_init_list|,
name|mutex2
argument_list|(
name|mutex2
argument_list|)
member_init_list|,
name|iterations
argument_list|(
name|iterations
argument_list|)
member_init_list|,
name|msleepDuration
argument_list|(
name|msleepDuration
argument_list|)
member_init_list|,
name|use2mutexes
argument_list|(
name|use2mutexes
argument_list|)
member_init_list|,
name|done
argument_list|(
literal|false
argument_list|)
block|{ }
DECL|function|run
name|void
name|run
parameter_list|()
block|{
forever|forever
block|{
name|tst_QMutex
operator|::
name|semaphore1
operator|.
name|release
argument_list|()
expr_stmt|;
name|tst_QMutex
operator|::
name|semaphore2
operator|.
name|acquire
argument_list|()
expr_stmt|;
if|if
condition|(
name|done
condition|)
break|break;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|iterations
condition|;
operator|++
name|i
control|)
block|{
name|mutex1
operator|->
name|lock
argument_list|()
expr_stmt|;
if|if
condition|(
name|use2mutexes
condition|)
name|mutex2
operator|->
name|lock
argument_list|()
expr_stmt|;
if|if
condition|(
name|msleepDuration
operator|>=
literal|0
condition|)
name|msleep
argument_list|(
name|msleepDuration
argument_list|)
expr_stmt|;
if|if
condition|(
name|use2mutexes
condition|)
name|mutex2
operator|->
name|unlock
argument_list|()
expr_stmt|;
name|mutex1
operator|->
name|unlock
argument_list|()
expr_stmt|;
name|QThread
operator|::
name|yieldCurrentThread
argument_list|()
expr_stmt|;
block|}
name|tst_QMutex
operator|::
name|semaphore3
operator|.
name|release
argument_list|()
expr_stmt|;
name|tst_QMutex
operator|::
name|semaphore4
operator|.
name|acquire
argument_list|()
expr_stmt|;
block|}
block|}
block|}
class|;
end_class
begin_function
DECL|function|contendedQMutex
name|void
name|tst_QMutex
operator|::
name|contendedQMutex
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|iterations
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|msleepDuration
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|use2mutexes
argument_list|)
expr_stmt|;
name|QMutex
name|mutex1
decl_stmt|,
name|mutex2
decl_stmt|;
name|QVector
argument_list|<
name|QMutexThread
modifier|*
argument_list|>
name|threads
argument_list|(
name|threadCount
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|threads
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|threads
index|[
name|i
index|]
operator|=
operator|new
name|QMutexThread
argument_list|(
operator|&
name|mutex1
argument_list|,
operator|&
name|mutex2
argument_list|,
name|iterations
argument_list|,
name|msleepDuration
argument_list|,
name|use2mutexes
argument_list|)
expr_stmt|;
name|threads
index|[
name|i
index|]
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
name|QBENCHMARK
block|{
name|semaphore1
operator|.
name|acquire
argument_list|(
name|threadCount
argument_list|)
expr_stmt|;
name|semaphore2
operator|.
name|release
argument_list|(
name|threadCount
argument_list|)
expr_stmt|;
name|semaphore3
operator|.
name|acquire
argument_list|(
name|threadCount
argument_list|)
expr_stmt|;
name|semaphore4
operator|.
name|release
argument_list|(
name|threadCount
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|threads
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|threads
index|[
name|i
index|]
operator|->
name|done
operator|=
literal|true
expr_stmt|;
name|semaphore1
operator|.
name|acquire
argument_list|(
name|threadCount
argument_list|)
expr_stmt|;
name|semaphore2
operator|.
name|release
argument_list|(
name|threadCount
argument_list|)
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
name|threads
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|threads
index|[
name|i
index|]
operator|->
name|wait
argument_list|()
expr_stmt|;
name|qDeleteAll
argument_list|(
name|threads
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|QMutexLockerThread
class|class
name|QMutexLockerThread
super|:
specifier|public
name|QThread
block|{
DECL|member|mutex1
DECL|member|mutex2
name|QMutex
modifier|*
name|mutex1
decl_stmt|,
modifier|*
name|mutex2
decl_stmt|;
DECL|member|iterations
DECL|member|msleepDuration
name|int
name|iterations
decl_stmt|,
name|msleepDuration
decl_stmt|;
DECL|member|use2mutexes
name|bool
name|use2mutexes
decl_stmt|;
public|public:
DECL|member|done
name|bool
name|done
decl_stmt|;
DECL|function|QMutexLockerThread
name|QMutexLockerThread
parameter_list|(
name|QMutex
modifier|*
name|mutex1
parameter_list|,
name|QMutex
modifier|*
name|mutex2
parameter_list|,
name|int
name|iterations
parameter_list|,
name|int
name|msleepDuration
parameter_list|,
name|bool
name|use2mutexes
parameter_list|)
member_init_list|:
name|mutex1
argument_list|(
name|mutex1
argument_list|)
member_init_list|,
name|mutex2
argument_list|(
name|mutex2
argument_list|)
member_init_list|,
name|iterations
argument_list|(
name|iterations
argument_list|)
member_init_list|,
name|msleepDuration
argument_list|(
name|msleepDuration
argument_list|)
member_init_list|,
name|use2mutexes
argument_list|(
name|use2mutexes
argument_list|)
member_init_list|,
name|done
argument_list|(
literal|false
argument_list|)
block|{ }
DECL|function|run
name|void
name|run
parameter_list|()
block|{
forever|forever
block|{
name|tst_QMutex
operator|::
name|semaphore1
operator|.
name|release
argument_list|()
expr_stmt|;
name|tst_QMutex
operator|::
name|semaphore2
operator|.
name|acquire
argument_list|()
expr_stmt|;
if|if
condition|(
name|done
condition|)
break|break;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|iterations
condition|;
operator|++
name|i
control|)
block|{
block|{
name|QMutexLocker
name|locker1
argument_list|(
name|mutex1
argument_list|)
decl_stmt|;
name|QMutexLocker
name|locker2
argument_list|(
name|use2mutexes
condition|?
name|mutex2
else|:
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|msleepDuration
operator|>=
literal|0
condition|)
name|msleep
argument_list|(
name|msleepDuration
argument_list|)
expr_stmt|;
block|}
name|QThread
operator|::
name|yieldCurrentThread
argument_list|()
expr_stmt|;
block|}
name|tst_QMutex
operator|::
name|semaphore3
operator|.
name|release
argument_list|()
expr_stmt|;
name|tst_QMutex
operator|::
name|semaphore4
operator|.
name|acquire
argument_list|()
expr_stmt|;
block|}
block|}
block|}
class|;
end_class
begin_function
DECL|function|contendedQMutexLocker
name|void
name|tst_QMutex
operator|::
name|contendedQMutexLocker
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|iterations
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|msleepDuration
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|use2mutexes
argument_list|)
expr_stmt|;
name|QMutex
name|mutex1
decl_stmt|,
name|mutex2
decl_stmt|;
name|QVector
argument_list|<
name|QMutexLockerThread
modifier|*
argument_list|>
name|threads
argument_list|(
name|threadCount
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|threads
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|threads
index|[
name|i
index|]
operator|=
operator|new
name|QMutexLockerThread
argument_list|(
operator|&
name|mutex1
argument_list|,
operator|&
name|mutex2
argument_list|,
name|iterations
argument_list|,
name|msleepDuration
argument_list|,
name|use2mutexes
argument_list|)
expr_stmt|;
name|threads
index|[
name|i
index|]
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
name|QBENCHMARK
block|{
name|semaphore1
operator|.
name|acquire
argument_list|(
name|threadCount
argument_list|)
expr_stmt|;
name|semaphore2
operator|.
name|release
argument_list|(
name|threadCount
argument_list|)
expr_stmt|;
name|semaphore3
operator|.
name|acquire
argument_list|(
name|threadCount
argument_list|)
expr_stmt|;
name|semaphore4
operator|.
name|release
argument_list|(
name|threadCount
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|threads
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|threads
index|[
name|i
index|]
operator|->
name|done
operator|=
literal|true
expr_stmt|;
name|semaphore1
operator|.
name|acquire
argument_list|(
name|threadCount
argument_list|)
expr_stmt|;
name|semaphore2
operator|.
name|release
argument_list|(
name|threadCount
argument_list|)
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
name|threads
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|threads
index|[
name|i
index|]
operator|->
name|wait
argument_list|()
expr_stmt|;
name|qDeleteAll
argument_list|(
name|threads
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QMutex
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qmutex.moc"
end_include
end_unit
