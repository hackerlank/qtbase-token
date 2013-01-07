begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QtDBus/QtDBus>
end_include
begin_include
include|#
directive|include
file|"./serverobject.h"
end_include
begin_decl_stmt
DECL|variable|serviceName
specifier|static
specifier|const
name|char
name|serviceName
index|[]
init|=
literal|"org.qtproject.autotests.performance"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|runTime
specifier|static
specifier|const
name|int
name|runTime
init|=
literal|500
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|tst_QDBusPerformance
class|class
name|tst_QDBusPerformance
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
DECL|member|proc
name|QProcess
name|proc
decl_stmt|;
DECL|member|target
name|QDBusInterface
modifier|*
name|target
decl_stmt|;
DECL|member|remote
name|QDBusInterface
modifier|*
name|remote
decl_stmt|;
DECL|member|local
name|QDBusInterface
modifier|*
name|local
decl_stmt|;
name|bool
name|executeTest
parameter_list|(
specifier|const
name|char
modifier|*
name|funcname
parameter_list|,
name|int
name|size
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|data
parameter_list|)
function_decl|;
public|public
name|slots
public|:
name|void
name|initTestCase_data
parameter_list|()
function_decl|;
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|callSpeed
parameter_list|()
function_decl|;
name|void
name|oneWay_data
parameter_list|()
function_decl|;
name|void
name|oneWay
parameter_list|()
function_decl|;
name|void
name|oneWayVariant_data
parameter_list|()
function_decl|;
name|void
name|oneWayVariant
parameter_list|()
function_decl|;
name|void
name|roundTrip_data
parameter_list|()
function_decl|;
name|void
name|roundTrip
parameter_list|()
function_decl|;
name|void
name|roundTripVariant_data
parameter_list|()
function_decl|;
name|void
name|roundTripVariant
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_QDBusPerformance
operator|::
name|initTestCase
parameter_list|()
block|{
name|QDBusConnection
name|con
init|=
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|con
operator|.
name|isConnected
argument_list|()
argument_list|)
expr_stmt|;
name|QDBusServiceWatcher
name|watcher
argument_list|(
name|serviceName
argument_list|,
name|con
argument_list|,
name|QDBusServiceWatcher
operator|::
name|WatchForRegistration
argument_list|)
decl_stmt|;
name|connect
argument_list|(
operator|&
name|watcher
argument_list|,
name|SIGNAL
argument_list|(
name|serviceRegistered
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
operator|&
name|QTestEventLoop
operator|::
name|instance
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|exitLoop
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|proc
operator|.
name|start
argument_list|(
literal|"server"
argument_list|)
expr_stmt|;
else|#
directive|else
name|proc
operator|.
name|start
argument_list|(
literal|"./server/server"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVERIFY
argument_list|(
name|proc
operator|.
name|waitForStarted
argument_list|()
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|con
operator|.
name|interface
argument_list|()
operator|->
name|isServiceRegistered
argument_list|(
name|serviceName
argument_list|)
argument_list|)
expr_stmt|;
name|remote
operator|=
operator|new
name|QDBusInterface
argument_list|(
name|serviceName
argument_list|,
literal|"/"
argument_list|,
literal|"org.qtproject.autotests.Performance"
argument_list|,
name|con
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|remote
operator|->
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
operator|new
name|ServerObject
argument_list|(
literal|"/"
argument_list|,
name|con
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|local
operator|=
operator|new
name|QDBusInterface
argument_list|(
name|con
operator|.
name|baseService
argument_list|()
argument_list|,
literal|"/"
argument_list|,
literal|"org.qtproject.autotests.Performance"
argument_list|,
name|con
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|local
operator|->
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initTestCase_data
name|void
name|tst_QDBusPerformance
operator|::
name|initTestCase_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"loopback"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"normal"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"loopback"
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|tst_QDBusPerformance
operator|::
name|init
parameter_list|()
block|{
name|QFETCH_GLOBAL
argument_list|(
name|bool
argument_list|,
name|loopback
argument_list|)
expr_stmt|;
if|if
condition|(
name|loopback
condition|)
name|target
operator|=
name|local
expr_stmt|;
else|else
name|target
operator|=
name|remote
expr_stmt|;
block|}
end_function
begin_function
DECL|function|callSpeed
name|void
name|tst_QDBusPerformance
operator|::
name|callSpeed
parameter_list|()
block|{
name|QElapsedTimer
name|timer
decl_stmt|;
name|int
name|callCount
init|=
literal|0
decl_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
while|while
condition|(
name|timer
operator|.
name|elapsed
argument_list|()
operator|<
name|runTime
condition|)
block|{
name|QDBusReply
argument_list|<
name|void
argument_list|>
name|reply
init|=
name|target
operator|->
name|call
argument_list|(
literal|"nothing"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|reply
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
operator|++
name|callCount
expr_stmt|;
block|}
name|qDebug
argument_list|()
operator|<<
name|callCount
operator|<<
literal|"calls in"
operator|<<
name|timer
operator|.
name|elapsed
argument_list|()
operator|<<
literal|"ms:"
operator|<<
operator|(
name|callCount
operator|*
literal|1000.0
operator|/
name|timer
operator|.
name|elapsed
argument_list|()
operator|)
operator|<<
literal|"calls/sec"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|executeTest
name|bool
name|tst_QDBusPerformance
operator|::
name|executeTest
parameter_list|(
specifier|const
name|char
modifier|*
name|funcname
parameter_list|,
name|int
name|size
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|data
parameter_list|)
block|{
name|QElapsedTimer
name|timer
decl_stmt|;
name|int
name|callCount
init|=
literal|0
decl_stmt|;
name|qint64
name|transferred
init|=
literal|0
decl_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
while|while
condition|(
name|timer
operator|.
name|elapsed
argument_list|()
operator|<
name|runTime
condition|)
block|{
name|QDBusMessage
name|reply
init|=
name|target
operator|->
name|call
argument_list|(
name|funcname
argument_list|,
name|data
argument_list|)
decl_stmt|;
if|if
condition|(
name|reply
operator|.
name|type
argument_list|()
operator|!=
name|QDBusMessage
operator|::
name|ReplyMessage
condition|)
return|return
literal|false
return|;
name|transferred
operator|+=
name|size
expr_stmt|;
operator|++
name|callCount
expr_stmt|;
block|}
name|qDebug
argument_list|()
operator|<<
name|transferred
operator|<<
literal|"bytes in"
operator|<<
name|timer
operator|.
name|elapsed
argument_list|()
operator|<<
literal|"ms"
operator|<<
literal|"(in"
operator|<<
name|callCount
operator|<<
literal|"calls):"
operator|<<
operator|(
name|transferred
operator|*
literal|1000.0
operator|/
name|timer
operator|.
name|elapsed
argument_list|()
operator|/
literal|1024
operator|/
literal|1024
operator|)
operator|<<
literal|"MB/s"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|oneWay_data
name|void
name|tst_QDBusPerformance
operator|::
name|oneWay_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QVariant
argument_list|>
argument_list|(
literal|"data"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
name|QByteArray
name|ba
argument_list|(
literal|256
argument_list|,
literal|'a'
argument_list|)
decl_stmt|;
while|while
condition|(
name|ba
operator|.
name|size
argument_list|()
operator|<
literal|8193
condition|)
block|{
name|QTest
operator|::
name|newRow
argument_list|(
name|QString
argument_list|(
literal|"%1-byteArray"
argument_list|)
operator|.
name|arg
argument_list|(
name|ba
operator|.
name|size
argument_list|()
argument_list|)
operator|.
name|toLatin1
argument_list|()
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|ba
argument_list|)
operator|<<
name|ba
operator|.
name|size
argument_list|()
expr_stmt|;
name|ba
operator|+=
name|ba
expr_stmt|;
block|}
name|QString
name|s
argument_list|(
literal|256
argument_list|,
name|QLatin1Char
argument_list|(
literal|'a'
argument_list|)
argument_list|)
decl_stmt|;
while|while
condition|(
name|s
operator|.
name|size
argument_list|()
operator|<
literal|8193
condition|)
block|{
name|QTest
operator|::
name|newRow
argument_list|(
name|QString
argument_list|(
literal|"%1-string"
argument_list|)
operator|.
name|arg
argument_list|(
name|s
operator|.
name|size
argument_list|()
argument_list|)
operator|.
name|toLatin1
argument_list|()
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|s
argument_list|)
operator|<<
name|s
operator|.
name|size
argument_list|()
expr_stmt|;
name|s
operator|+=
name|s
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|oneWay
name|void
name|tst_QDBusPerformance
operator|::
name|oneWay
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QVariant
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|executeTest
argument_list|(
literal|"size"
argument_list|,
name|size
argument_list|,
name|data
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|oneWayVariant_data
name|void
name|tst_QDBusPerformance
operator|::
name|oneWayVariant_data
parameter_list|()
block|{
name|oneWay_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|oneWayVariant
name|void
name|tst_QDBusPerformance
operator|::
name|oneWayVariant
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QVariant
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|executeTest
argument_list|(
literal|"size"
argument_list|,
name|size
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QDBusVariant
argument_list|(
name|data
argument_list|)
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|roundTrip_data
name|void
name|tst_QDBusPerformance
operator|::
name|roundTrip_data
parameter_list|()
block|{
name|oneWay_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|roundTrip
name|void
name|tst_QDBusPerformance
operator|::
name|roundTrip
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QVariant
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|executeTest
argument_list|(
literal|"echo"
argument_list|,
name|size
argument_list|,
name|data
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|roundTripVariant_data
name|void
name|tst_QDBusPerformance
operator|::
name|roundTripVariant_data
parameter_list|()
block|{
name|oneWay_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|roundTripVariant
name|void
name|tst_QDBusPerformance
operator|::
name|roundTripVariant
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QVariant
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|executeTest
argument_list|(
literal|"echo"
argument_list|,
name|size
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QDBusVariant
argument_list|(
name|data
argument_list|)
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QDBusPerformance
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qdbusperformance.moc"
end_include
end_unit
