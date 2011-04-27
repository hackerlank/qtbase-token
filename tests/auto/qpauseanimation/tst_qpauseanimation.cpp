begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpauseanimation.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpropertyanimation.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsequentialanimationgroup.h>
end_include
begin_include
include|#
directive|include
file|<private/qabstractanimation_p.h>
end_include
begin_comment
comment|//TESTED_CLASS=QPauseAnimation
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_class
DECL|class|TestablePauseAnimation
class|class
name|TestablePauseAnimation
super|:
specifier|public
name|QPauseAnimation
block|{
name|Q_OBJECT
public|public:
DECL|function|TestablePauseAnimation
name|TestablePauseAnimation
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QPauseAnimation
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_updateCurrentTimeCount
argument_list|(
literal|0
argument_list|)
block|{     }
DECL|member|m_updateCurrentTimeCount
name|int
name|m_updateCurrentTimeCount
decl_stmt|;
protected|protected:
DECL|function|updateCurrentTime
name|void
name|updateCurrentTime
parameter_list|(
name|int
name|currentTime
parameter_list|)
block|{
comment|//qDebug()<< this<< "update current time: "<< currentTime;
name|QPauseAnimation
operator|::
name|updateCurrentTime
argument_list|(
name|currentTime
argument_list|)
expr_stmt|;
operator|++
name|m_updateCurrentTimeCount
expr_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|EnableConsistentTiming
class|class
name|EnableConsistentTiming
block|{
public|public:
DECL|function|EnableConsistentTiming
name|EnableConsistentTiming
parameter_list|()
block|{
name|QUnifiedTimer
modifier|*
name|timer
init|=
name|QUnifiedTimer
operator|::
name|instance
argument_list|()
decl_stmt|;
name|timer
operator|->
name|setConsistentTiming
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
DECL|function|~EnableConsistentTiming
name|~
name|EnableConsistentTiming
parameter_list|()
block|{
name|QUnifiedTimer
modifier|*
name|timer
init|=
name|QUnifiedTimer
operator|::
name|instance
argument_list|()
decl_stmt|;
name|timer
operator|->
name|setConsistentTiming
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|tst_QPauseAnimation
class|class
name|tst_QPauseAnimation
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QPauseAnimation
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QPauseAnimation
parameter_list|()
destructor_decl|;
public|public
name|Q_SLOTS
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|changeDirectionWhileRunning
parameter_list|()
function_decl|;
name|void
name|noTimerUpdates_data
parameter_list|()
function_decl|;
name|void
name|noTimerUpdates
parameter_list|()
function_decl|;
name|void
name|multiplePauseAnimations
parameter_list|()
function_decl|;
name|void
name|pauseAndPropertyAnimations
parameter_list|()
function_decl|;
name|void
name|pauseResume
parameter_list|()
function_decl|;
name|void
name|sequentialPauseGroup
parameter_list|()
function_decl|;
name|void
name|sequentialGroupWithPause
parameter_list|()
function_decl|;
name|void
name|multipleSequentialGroups
parameter_list|()
function_decl|;
name|void
name|zeroDuration
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QPauseAnimation
name|tst_QPauseAnimation
operator|::
name|tst_QPauseAnimation
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QPauseAnimation
name|tst_QPauseAnimation
operator|::
name|~
name|tst_QPauseAnimation
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QPauseAnimation
operator|::
name|initTestCase
parameter_list|()
block|{
name|qRegisterMetaType
argument_list|<
name|QAbstractAnimation
operator|::
name|State
argument_list|>
argument_list|(
literal|"QAbstractAnimation::State"
argument_list|)
expr_stmt|;
name|qRegisterMetaType
argument_list|<
name|QAbstractAnimation
operator|::
name|DeletionPolicy
argument_list|>
argument_list|(
literal|"QAbstractAnimation::DeletionPolicy"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|changeDirectionWhileRunning
name|void
name|tst_QPauseAnimation
operator|::
name|changeDirectionWhileRunning
parameter_list|()
block|{
name|EnableConsistentTiming
name|enabled
decl_stmt|;
name|TestablePauseAnimation
name|animation
decl_stmt|;
name|animation
operator|.
name|setDuration
argument_list|(
literal|400
argument_list|)
expr_stmt|;
name|animation
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|animation
operator|.
name|setDirection
argument_list|(
name|QAbstractAnimation
operator|::
name|Backward
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
name|animation
operator|.
name|totalDuration
argument_list|()
operator|+
literal|50
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|noTimerUpdates_data
name|void
name|tst_QPauseAnimation
operator|::
name|noTimerUpdates_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"duration"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"loopCount"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0"
argument_list|)
operator|<<
literal|200
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1"
argument_list|)
operator|<<
literal|160
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2"
argument_list|)
operator|<<
literal|160
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"3"
argument_list|)
operator|<<
literal|200
operator|<<
literal|3
expr_stmt|;
block|}
end_function
begin_function
DECL|function|noTimerUpdates
name|void
name|tst_QPauseAnimation
operator|::
name|noTimerUpdates
parameter_list|()
block|{
name|EnableConsistentTiming
name|enabled
decl_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|duration
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|loopCount
argument_list|)
expr_stmt|;
name|TestablePauseAnimation
name|animation
decl_stmt|;
name|animation
operator|.
name|setDuration
argument_list|(
name|duration
argument_list|)
expr_stmt|;
name|animation
operator|.
name|setLoopCount
argument_list|(
name|loopCount
argument_list|)
expr_stmt|;
name|animation
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
name|animation
operator|.
name|totalDuration
argument_list|()
operator|+
literal|100
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
if|if
condition|(
name|animation
operator|.
name|state
argument_list|()
operator|!=
name|QAbstractAnimation
operator|::
name|Stopped
condition|)
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"On windows, consistent timing is not working properly due to bad timer resolution"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVERIFY
argument_list|(
name|animation
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|1
operator|+
name|loopCount
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|multiplePauseAnimations
name|void
name|tst_QPauseAnimation
operator|::
name|multiplePauseAnimations
parameter_list|()
block|{
name|EnableConsistentTiming
name|enabled
decl_stmt|;
name|TestablePauseAnimation
name|animation
decl_stmt|;
name|animation
operator|.
name|setDuration
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|TestablePauseAnimation
name|animation2
decl_stmt|;
name|animation2
operator|.
name|setDuration
argument_list|(
literal|800
argument_list|)
expr_stmt|;
name|animation
operator|.
name|start
argument_list|()
expr_stmt|;
name|animation2
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
name|animation
operator|.
name|totalDuration
argument_list|()
operator|+
literal|100
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
if|if
condition|(
name|animation
operator|.
name|state
argument_list|()
operator|!=
name|QAbstractAnimation
operator|::
name|Stopped
condition|)
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"On windows, consistent timing is not working properly due to bad timer resolution"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVERIFY
argument_list|(
name|animation
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation2
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation2
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|550
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
if|if
condition|(
name|animation2
operator|.
name|state
argument_list|()
operator|!=
name|QAbstractAnimation
operator|::
name|Stopped
condition|)
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"On windows, consistent timing is not working properly due to bad timer resolution"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVERIFY
argument_list|(
name|animation2
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation2
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pauseAndPropertyAnimations
name|void
name|tst_QPauseAnimation
operator|::
name|pauseAndPropertyAnimations
parameter_list|()
block|{
name|EnableConsistentTiming
name|enabled
decl_stmt|;
name|TestablePauseAnimation
name|pause
decl_stmt|;
name|pause
operator|.
name|setDuration
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|QObject
name|o
decl_stmt|;
name|o
operator|.
name|setProperty
argument_list|(
literal|"ole"
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|QPropertyAnimation
name|animation
argument_list|(
operator|&
name|o
argument_list|,
literal|"ole"
argument_list|)
decl_stmt|;
name|animation
operator|.
name|setEndValue
argument_list|(
literal|43
argument_list|)
expr_stmt|;
name|pause
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|animation
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|pause
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pause
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
name|animation
operator|.
name|totalDuration
argument_list|()
operator|+
literal|100
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
if|if
condition|(
name|animation
operator|.
name|state
argument_list|()
operator|!=
name|QAbstractAnimation
operator|::
name|Stopped
condition|)
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"On windows, consistent timing is not working properly due to bad timer resolution"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVERIFY
argument_list|(
name|animation
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|pause
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|pause
operator|.
name|m_updateCurrentTimeCount
operator|>
literal|3
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pauseResume
name|void
name|tst_QPauseAnimation
operator|::
name|pauseResume
parameter_list|()
block|{
name|TestablePauseAnimation
name|animation
decl_stmt|;
name|animation
operator|.
name|setDuration
argument_list|(
literal|400
argument_list|)
expr_stmt|;
name|animation
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|animation
operator|.
name|pause
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Paused
argument_list|)
expr_stmt|;
name|animation
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|300
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sequentialPauseGroup
name|void
name|tst_QPauseAnimation
operator|::
name|sequentialPauseGroup
parameter_list|()
block|{
name|QSequentialAnimationGroup
name|group
decl_stmt|;
name|TestablePauseAnimation
name|animation1
argument_list|(
operator|&
name|group
argument_list|)
decl_stmt|;
name|animation1
operator|.
name|setDuration
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|TestablePauseAnimation
name|animation2
argument_list|(
operator|&
name|group
argument_list|)
decl_stmt|;
name|animation2
operator|.
name|setDuration
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|TestablePauseAnimation
name|animation3
argument_list|(
operator|&
name|group
argument_list|)
decl_stmt|;
name|animation3
operator|.
name|setDuration
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|group
operator|.
name|start
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation1
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation2
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation3
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|group
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation1
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation2
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation3
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|group
operator|.
name|setCurrentTime
argument_list|(
literal|250
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation1
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation2
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation3
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|group
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation1
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|QAbstractAnimation
operator|*
operator|)
operator|&
name|animation2
argument_list|,
name|group
operator|.
name|currentAnimation
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation2
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation3
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|group
operator|.
name|setCurrentTime
argument_list|(
literal|500
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation1
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation2
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation3
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|group
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation1
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation2
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|QAbstractAnimation
operator|*
operator|)
operator|&
name|animation3
argument_list|,
name|group
operator|.
name|currentAnimation
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation3
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|group
operator|.
name|setCurrentTime
argument_list|(
literal|750
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|group
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation1
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation2
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation3
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation1
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation2
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation3
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sequentialGroupWithPause
name|void
name|tst_QPauseAnimation
operator|::
name|sequentialGroupWithPause
parameter_list|()
block|{
name|QSequentialAnimationGroup
name|group
decl_stmt|;
name|QObject
name|o
decl_stmt|;
name|o
operator|.
name|setProperty
argument_list|(
literal|"ole"
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|QPropertyAnimation
name|animation
argument_list|(
operator|&
name|o
argument_list|,
literal|"ole"
argument_list|,
operator|&
name|group
argument_list|)
decl_stmt|;
name|animation
operator|.
name|setEndValue
argument_list|(
literal|43
argument_list|)
expr_stmt|;
name|TestablePauseAnimation
name|pause
argument_list|(
operator|&
name|group
argument_list|)
decl_stmt|;
name|pause
operator|.
name|setDuration
argument_list|(
literal|250
argument_list|)
expr_stmt|;
name|group
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|group
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|pause
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|group
operator|.
name|setCurrentTime
argument_list|(
literal|300
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|group
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|QAbstractAnimation
operator|*
operator|)
operator|&
name|pause
argument_list|,
name|group
operator|.
name|currentAnimation
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|pause
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|group
operator|.
name|setCurrentTime
argument_list|(
literal|600
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|group
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|pause
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pause
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|multipleSequentialGroups
name|void
name|tst_QPauseAnimation
operator|::
name|multipleSequentialGroups
parameter_list|()
block|{
name|EnableConsistentTiming
name|enabled
decl_stmt|;
name|QParallelAnimationGroup
name|group
decl_stmt|;
name|group
operator|.
name|setLoopCount
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|QSequentialAnimationGroup
name|subgroup1
argument_list|(
operator|&
name|group
argument_list|)
decl_stmt|;
name|QObject
name|o
decl_stmt|;
name|o
operator|.
name|setProperty
argument_list|(
literal|"ole"
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|QPropertyAnimation
name|animation
argument_list|(
operator|&
name|o
argument_list|,
literal|"ole"
argument_list|,
operator|&
name|subgroup1
argument_list|)
decl_stmt|;
name|animation
operator|.
name|setEndValue
argument_list|(
literal|43
argument_list|)
expr_stmt|;
name|animation
operator|.
name|setDuration
argument_list|(
literal|300
argument_list|)
expr_stmt|;
name|TestablePauseAnimation
name|pause
argument_list|(
operator|&
name|subgroup1
argument_list|)
decl_stmt|;
name|pause
operator|.
name|setDuration
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|QSequentialAnimationGroup
name|subgroup2
argument_list|(
operator|&
name|group
argument_list|)
decl_stmt|;
name|o
operator|.
name|setProperty
argument_list|(
literal|"ole2"
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|QPropertyAnimation
name|animation2
argument_list|(
operator|&
name|o
argument_list|,
literal|"ole2"
argument_list|,
operator|&
name|subgroup2
argument_list|)
decl_stmt|;
name|animation2
operator|.
name|setEndValue
argument_list|(
literal|43
argument_list|)
expr_stmt|;
name|animation2
operator|.
name|setDuration
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|TestablePauseAnimation
name|pause2
argument_list|(
operator|&
name|subgroup2
argument_list|)
decl_stmt|;
name|pause2
operator|.
name|setDuration
argument_list|(
literal|250
argument_list|)
expr_stmt|;
name|QSequentialAnimationGroup
name|subgroup3
argument_list|(
operator|&
name|group
argument_list|)
decl_stmt|;
name|TestablePauseAnimation
name|pause3
argument_list|(
operator|&
name|subgroup3
argument_list|)
decl_stmt|;
name|pause3
operator|.
name|setDuration
argument_list|(
literal|400
argument_list|)
expr_stmt|;
name|o
operator|.
name|setProperty
argument_list|(
literal|"ole3"
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|QPropertyAnimation
name|animation3
argument_list|(
operator|&
name|o
argument_list|,
literal|"ole3"
argument_list|,
operator|&
name|subgroup3
argument_list|)
decl_stmt|;
name|animation3
operator|.
name|setEndValue
argument_list|(
literal|43
argument_list|)
expr_stmt|;
name|animation3
operator|.
name|setDuration
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|QSequentialAnimationGroup
name|subgroup4
argument_list|(
operator|&
name|group
argument_list|)
decl_stmt|;
name|TestablePauseAnimation
name|pause4
argument_list|(
operator|&
name|subgroup4
argument_list|)
decl_stmt|;
name|pause4
operator|.
name|setDuration
argument_list|(
literal|310
argument_list|)
expr_stmt|;
name|TestablePauseAnimation
name|pause5
argument_list|(
operator|&
name|subgroup4
argument_list|)
decl_stmt|;
name|pause5
operator|.
name|setDuration
argument_list|(
literal|60
argument_list|)
expr_stmt|;
name|group
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|group
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|subgroup1
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|subgroup2
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|subgroup3
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|subgroup4
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
comment|// This is a pretty long animation so it tends to get rather out of sync
comment|// when using the consistent timer, so run for an extra half second for good
comment|// measure...
name|QTest
operator|::
name|qWait
argument_list|(
name|group
operator|.
name|totalDuration
argument_list|()
operator|+
literal|500
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
if|if
condition|(
name|group
operator|.
name|state
argument_list|()
operator|!=
name|QAbstractAnimation
operator|::
name|Stopped
condition|)
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"On windows, consistent timing is not working properly due to bad timer resolution"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVERIFY
argument_list|(
name|group
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|subgroup1
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|subgroup2
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|subgroup3
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|subgroup4
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pause5
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|zeroDuration
name|void
name|tst_QPauseAnimation
operator|::
name|zeroDuration
parameter_list|()
block|{
name|TestablePauseAnimation
name|animation
decl_stmt|;
name|animation
operator|.
name|setDuration
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|animation
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
name|animation
operator|.
name|totalDuration
argument_list|()
operator|+
literal|100
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|animation
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|m_updateCurrentTimeCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QPauseAnimation
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qpauseanimation.moc"
end_include
end_unit
