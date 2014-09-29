begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QMutexLocker>
end_include
begin_include
include|#
directive|include
file|<QSemaphore>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_class
DECL|class|tst_QMutexLockerThread
class|class
name|tst_QMutexLockerThread
super|:
specifier|public
name|QThread
block|{
public|public:
DECL|member|mutex
name|QMutex
name|mutex
decl_stmt|;
DECL|member|semaphore
DECL|member|testSemaphore
name|QSemaphore
name|semaphore
decl_stmt|,
name|testSemaphore
decl_stmt|;
DECL|function|waitForTest
name|void
name|waitForTest
parameter_list|()
block|{
name|semaphore
operator|.
name|release
argument_list|()
expr_stmt|;
name|testSemaphore
operator|.
name|acquire
argument_list|()
expr_stmt|;
block|}
DECL|function|tst_QMutexLockerThread
name|tst_QMutexLockerThread
parameter_list|()
member_init_list|:
name|mutex
argument_list|(
name|QMutex
operator|::
name|Recursive
argument_list|)
block|{     }
block|}
class|;
end_class
begin_class
DECL|class|tst_QMutexLocker
class|class
name|tst_QMutexLocker
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|member|thread
name|tst_QMutexLockerThread
modifier|*
name|thread
decl_stmt|;
DECL|function|waitForThread
name|void
name|waitForThread
parameter_list|()
block|{
name|thread
operator|->
name|semaphore
operator|.
name|acquire
argument_list|()
expr_stmt|;
block|}
DECL|function|releaseThread
name|void
name|releaseThread
parameter_list|()
block|{
name|thread
operator|->
name|testSemaphore
operator|.
name|release
argument_list|()
expr_stmt|;
block|}
private|private
name|slots
private|:
name|void
name|scopeTest
parameter_list|()
function_decl|;
name|void
name|unlockAndRelockTest
parameter_list|()
function_decl|;
name|void
name|lockerStateTest
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|scopeTest
name|void
name|tst_QMutexLocker
operator|::
name|scopeTest
parameter_list|()
block|{
class|class
name|ScopeTestThread
super|:
specifier|public
name|tst_QMutexLockerThread
block|{
public|public:
name|void
name|run
parameter_list|()
block|{
name|waitForTest
argument_list|()
expr_stmt|;
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|waitForTest
argument_list|()
expr_stmt|;
block|}
name|waitForTest
argument_list|()
expr_stmt|;
block|}
block|}
class|;
name|thread
operator|=
operator|new
name|ScopeTestThread
expr_stmt|;
name|thread
operator|->
name|start
argument_list|()
expr_stmt|;
name|waitForThread
argument_list|()
expr_stmt|;
comment|// mutex should be unlocked before entering the scope that creates the QMutexLocker
name|QVERIFY
argument_list|(
name|thread
operator|->
name|mutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|thread
operator|->
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|releaseThread
argument_list|()
expr_stmt|;
name|waitForThread
argument_list|()
expr_stmt|;
comment|// mutex should be locked by the QMutexLocker
name|QVERIFY
argument_list|(
operator|!
name|thread
operator|->
name|mutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|releaseThread
argument_list|()
expr_stmt|;
name|waitForThread
argument_list|()
expr_stmt|;
comment|// mutex should be unlocked when the QMutexLocker goes out of scope
name|QVERIFY
argument_list|(
name|thread
operator|->
name|mutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|thread
operator|->
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|releaseThread
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|thread
operator|->
name|wait
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|thread
expr_stmt|;
name|thread
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unlockAndRelockTest
name|void
name|tst_QMutexLocker
operator|::
name|unlockAndRelockTest
parameter_list|()
block|{
class|class
name|UnlockAndRelockThread
super|:
specifier|public
name|tst_QMutexLockerThread
block|{
public|public:
name|void
name|run
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|waitForTest
argument_list|()
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|waitForTest
argument_list|()
expr_stmt|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
name|waitForTest
argument_list|()
expr_stmt|;
block|}
block|}
class|;
name|thread
operator|=
operator|new
name|UnlockAndRelockThread
expr_stmt|;
name|thread
operator|->
name|start
argument_list|()
expr_stmt|;
name|waitForThread
argument_list|()
expr_stmt|;
comment|// mutex should be locked by the QMutexLocker
name|QVERIFY
argument_list|(
operator|!
name|thread
operator|->
name|mutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|releaseThread
argument_list|()
expr_stmt|;
name|waitForThread
argument_list|()
expr_stmt|;
comment|// mutex has been explicitly unlocked via QMutexLocker
name|QVERIFY
argument_list|(
name|thread
operator|->
name|mutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|thread
operator|->
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|releaseThread
argument_list|()
expr_stmt|;
name|waitForThread
argument_list|()
expr_stmt|;
comment|// mutex has been explicitly relocked via QMutexLocker
name|QVERIFY
argument_list|(
operator|!
name|thread
operator|->
name|mutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|releaseThread
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|thread
operator|->
name|wait
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|thread
expr_stmt|;
name|thread
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lockerStateTest
name|void
name|tst_QMutexLocker
operator|::
name|lockerStateTest
parameter_list|()
block|{
class|class
name|LockerStateThread
super|:
specifier|public
name|tst_QMutexLockerThread
block|{
public|public:
name|void
name|run
parameter_list|()
block|{
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|waitForTest
argument_list|()
expr_stmt|;
block|}
name|waitForTest
argument_list|()
expr_stmt|;
block|}
block|}
class|;
name|thread
operator|=
operator|new
name|LockerStateThread
expr_stmt|;
name|thread
operator|->
name|start
argument_list|()
expr_stmt|;
name|waitForThread
argument_list|()
expr_stmt|;
comment|// even though we relock() after creating the QMutexLocker, it shouldn't lock the mutex more than once
name|QVERIFY
argument_list|(
name|thread
operator|->
name|mutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|thread
operator|->
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|releaseThread
argument_list|()
expr_stmt|;
name|waitForThread
argument_list|()
expr_stmt|;
comment|// if we call QMutexLocker::unlock(), its destructor should do nothing
name|QVERIFY
argument_list|(
name|thread
operator|->
name|mutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|thread
operator|->
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|releaseThread
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|thread
operator|->
name|wait
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|thread
expr_stmt|;
name|thread
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QMutexLocker
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qmutexlocker.moc"
end_include
end_unit
