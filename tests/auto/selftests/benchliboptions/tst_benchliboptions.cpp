begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_comment
comment|/* Custom event dispatcher to ensure we don't receive any spontaneous events */
end_comment
begin_class
DECL|class|TestEventDispatcher
class|class
name|TestEventDispatcher
super|:
specifier|public
name|QAbstractEventDispatcher
block|{
name|Q_OBJECT
public|public:
DECL|function|TestEventDispatcher
name|TestEventDispatcher
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QAbstractEventDispatcher
argument_list|(
name|parent
argument_list|)
block|{}
DECL|function|flush
name|void
name|flush
parameter_list|()
block|{}
DECL|function|hasPendingEvents
name|bool
name|hasPendingEvents
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
DECL|function|interrupt
name|void
name|interrupt
parameter_list|()
block|{}
DECL|function|processEvents
name|bool
name|processEvents
parameter_list|(
name|QEventLoop
operator|::
name|ProcessEventsFlags
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|registerSocketNotifier
name|void
name|registerSocketNotifier
parameter_list|(
name|QSocketNotifier
modifier|*
parameter_list|)
block|{}
DECL|function|registerTimer
name|int
name|registerTimer
parameter_list|(
name|int
parameter_list|,
name|QObject
modifier|*
parameter_list|)
block|{
return|return
operator|-
literal|1
return|;
block|}
DECL|function|registerTimer
name|void
name|registerTimer
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|QObject
modifier|*
parameter_list|)
block|{}
DECL|function|registeredTimers
name|QList
argument_list|<
name|TimerInfo
argument_list|>
name|registeredTimers
parameter_list|(
name|QObject
modifier|*
parameter_list|)
specifier|const
block|{
return|return
name|QList
argument_list|<
name|TimerInfo
argument_list|>
argument_list|()
return|;
block|}
DECL|function|unregisterSocketNotifier
name|void
name|unregisterSocketNotifier
parameter_list|(
name|QSocketNotifier
modifier|*
parameter_list|)
block|{}
DECL|function|unregisterTimer
name|bool
name|unregisterTimer
parameter_list|(
name|int
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|unregisterTimers
name|bool
name|unregisterTimers
parameter_list|(
name|QObject
modifier|*
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|wakeUp
name|void
name|wakeUp
parameter_list|()
block|{}
block|}
class|;
end_class
begin_class
DECL|class|tst_BenchlibOptions
class|class
name|tst_BenchlibOptions
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|threeEvents
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|tst_BenchlibFifteenIterations
class|class
name|tst_BenchlibFifteenIterations
super|:
specifier|public
name|tst_BenchlibOptions
block|{
name|Q_OBJECT
block|}
class|;
end_class
begin_class
DECL|class|tst_BenchlibOneHundredMinimum
class|class
name|tst_BenchlibOneHundredMinimum
super|:
specifier|public
name|tst_BenchlibOptions
block|{
name|Q_OBJECT
block|}
class|;
end_class
begin_function
DECL|function|threeEvents
name|void
name|tst_BenchlibOptions
operator|::
name|threeEvents
parameter_list|()
block|{
name|QAbstractEventDispatcher
modifier|*
name|ed
init|=
name|QAbstractEventDispatcher
operator|::
name|instance
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|ed
operator|->
name|filterEvent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|ed
operator|->
name|filterEvent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|ed
operator|->
name|filterEvent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
name|ret
init|=
literal|0
decl_stmt|;
name|TestEventDispatcher
name|dispatcher
decl_stmt|;
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
comment|/* Run with no special arguments. */
block|{
name|tst_BenchlibOptions
name|test
decl_stmt|;
name|ret
operator|+=
name|QTest
operator|::
name|qExec
argument_list|(
operator|&
name|test
argument_list|,
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
block|}
comment|/* Run with an exact number of iterations. */
block|{
name|QVector
argument_list|<
name|char
specifier|const
operator|*
argument_list|>
name|args
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
name|argc
condition|;
operator|++
name|i
control|)
name|args
operator|<<
name|argv
index|[
name|i
index|]
expr_stmt|;
name|args
operator|<<
literal|"-iterations"
expr_stmt|;
name|args
operator|<<
literal|"15"
expr_stmt|;
name|tst_BenchlibFifteenIterations
name|test
decl_stmt|;
name|ret
operator|+=
name|QTest
operator|::
name|qExec
argument_list|(
operator|&
name|test
argument_list|,
name|args
operator|.
name|count
argument_list|()
argument_list|,
cast|const_cast
argument_list|<
name|char
operator|*
operator|*
argument_list|>
argument_list|(
name|args
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/*         Run until getting a value of at least 100.     */
block|{
name|QVector
argument_list|<
name|char
specifier|const
operator|*
argument_list|>
name|args
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
name|argc
condition|;
operator|++
name|i
control|)
name|args
operator|<<
name|argv
index|[
name|i
index|]
expr_stmt|;
name|args
operator|<<
literal|"-minimumvalue"
expr_stmt|;
name|args
operator|<<
literal|"100"
expr_stmt|;
name|tst_BenchlibOneHundredMinimum
name|test
decl_stmt|;
name|ret
operator|+=
name|QTest
operator|::
name|qExec
argument_list|(
operator|&
name|test
argument_list|,
name|args
operator|.
name|count
argument_list|()
argument_list|,
cast|const_cast
argument_list|<
name|char
operator|*
operator|*
argument_list|>
argument_list|(
name|args
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"tst_benchliboptions.moc"
end_include
end_unit
