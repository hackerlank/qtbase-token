begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtDBus/QDBusServiceWatcher>
end_include
begin_include
include|#
directive|include
file|<QtDBus>
end_include
begin_include
include|#
directive|include
file|<QtTest>
end_include
begin_class
DECL|class|tst_QDBusServiceWatcher
class|class
name|tst_QDBusServiceWatcher
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
DECL|member|serviceName
name|QString
name|serviceName
decl_stmt|;
DECL|member|testCounter
name|int
name|testCounter
decl_stmt|;
public|public:
name|tst_QDBusServiceWatcher
parameter_list|()
constructor_decl|;
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|watchForCreation
parameter_list|()
function_decl|;
name|void
name|watchForDisappearance
parameter_list|()
function_decl|;
name|void
name|watchForOwnerChange
parameter_list|()
function_decl|;
name|void
name|modeChange
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QDBusServiceWatcher
name|tst_QDBusServiceWatcher
operator|::
name|tst_QDBusServiceWatcher
parameter_list|()
member_init_list|:
name|testCounter
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QDBusServiceWatcher
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
block|}
end_function
begin_function
DECL|function|init
name|void
name|tst_QDBusServiceWatcher
operator|::
name|init
parameter_list|()
block|{
comment|// change the service name from test to test
name|serviceName
operator|=
literal|"com.example.TestService"
operator|+
name|QString
operator|::
name|number
argument_list|(
name|testCounter
operator|++
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|watchForCreation
name|void
name|tst_QDBusServiceWatcher
operator|::
name|watchForCreation
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
name|QSignalSpy
name|spyR
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
argument_list|)
decl_stmt|;
name|QSignalSpy
name|spyU
argument_list|(
operator|&
name|watcher
argument_list|,
name|SIGNAL
argument_list|(
name|serviceUnregistered
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|spyO
argument_list|(
operator|&
name|watcher
argument_list|,
name|SIGNAL
argument_list|(
name|serviceOwnerChanged
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
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
name|SLOT
argument_list|(
name|exitLoop
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// register a name
name|QVERIFY
argument_list|(
name|con
operator|.
name|registerService
argument_list|(
name|serviceName
argument_list|)
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|timeout
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyR
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyR
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|serviceName
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyU
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|serviceName
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|con
operator|.
name|baseService
argument_list|()
argument_list|)
expr_stmt|;
name|spyR
operator|.
name|clear
argument_list|()
expr_stmt|;
name|spyU
operator|.
name|clear
argument_list|()
expr_stmt|;
name|spyO
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// unregister it:
name|con
operator|.
name|unregisterService
argument_list|(
name|serviceName
argument_list|)
expr_stmt|;
comment|// and register again
name|QVERIFY
argument_list|(
name|con
operator|.
name|registerService
argument_list|(
name|serviceName
argument_list|)
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|timeout
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyR
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyR
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|serviceName
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyU
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|serviceName
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|con
operator|.
name|baseService
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|watchForDisappearance
name|void
name|tst_QDBusServiceWatcher
operator|::
name|watchForDisappearance
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
name|WatchForUnregistration
argument_list|)
decl_stmt|;
name|watcher
operator|.
name|setObjectName
argument_list|(
literal|"watcher for disappearance"
argument_list|)
expr_stmt|;
name|QSignalSpy
name|spyR
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
argument_list|)
decl_stmt|;
name|QSignalSpy
name|spyU
argument_list|(
operator|&
name|watcher
argument_list|,
name|SIGNAL
argument_list|(
name|serviceUnregistered
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|spyO
argument_list|(
operator|&
name|watcher
argument_list|,
name|SIGNAL
argument_list|(
name|serviceOwnerChanged
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|connect
argument_list|(
operator|&
name|watcher
argument_list|,
name|SIGNAL
argument_list|(
name|serviceUnregistered
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|exitLoop
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// register a name
name|QVERIFY
argument_list|(
name|con
operator|.
name|registerService
argument_list|(
name|serviceName
argument_list|)
argument_list|)
expr_stmt|;
comment|// unregister it:
name|con
operator|.
name|unregisterService
argument_list|(
name|serviceName
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|timeout
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyR
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyU
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyU
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|serviceName
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|serviceName
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|con
operator|.
name|baseService
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|watchForOwnerChange
name|void
name|tst_QDBusServiceWatcher
operator|::
name|watchForOwnerChange
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
name|WatchForOwnerChange
argument_list|)
decl_stmt|;
name|QSignalSpy
name|spyR
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
argument_list|)
decl_stmt|;
name|QSignalSpy
name|spyU
argument_list|(
operator|&
name|watcher
argument_list|,
name|SIGNAL
argument_list|(
name|serviceUnregistered
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|spyO
argument_list|(
operator|&
name|watcher
argument_list|,
name|SIGNAL
argument_list|(
name|serviceOwnerChanged
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
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
name|SLOT
argument_list|(
name|exitLoop
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// register a name
name|QVERIFY
argument_list|(
name|con
operator|.
name|registerService
argument_list|(
name|serviceName
argument_list|)
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|timeout
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyR
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyR
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|serviceName
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyU
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|serviceName
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|con
operator|.
name|baseService
argument_list|()
argument_list|)
expr_stmt|;
name|spyR
operator|.
name|clear
argument_list|()
expr_stmt|;
name|spyU
operator|.
name|clear
argument_list|()
expr_stmt|;
name|spyO
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// unregister it:
name|con
operator|.
name|unregisterService
argument_list|(
name|serviceName
argument_list|)
expr_stmt|;
comment|// and register again
name|QVERIFY
argument_list|(
name|con
operator|.
name|registerService
argument_list|(
name|serviceName
argument_list|)
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|timeout
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyR
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyR
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|serviceName
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyU
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyU
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|serviceName
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|serviceName
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|con
operator|.
name|baseService
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|serviceName
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|con
operator|.
name|baseService
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|modeChange
name|void
name|tst_QDBusServiceWatcher
operator|::
name|modeChange
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
name|QSignalSpy
name|spyR
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
argument_list|)
decl_stmt|;
name|QSignalSpy
name|spyU
argument_list|(
operator|&
name|watcher
argument_list|,
name|SIGNAL
argument_list|(
name|serviceUnregistered
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|spyO
argument_list|(
operator|&
name|watcher
argument_list|,
name|SIGNAL
argument_list|(
name|serviceOwnerChanged
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
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
name|SLOT
argument_list|(
name|exitLoop
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// register a name
name|QVERIFY
argument_list|(
name|con
operator|.
name|registerService
argument_list|(
name|serviceName
argument_list|)
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|timeout
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyR
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyR
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|serviceName
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyU
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|serviceName
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|con
operator|.
name|baseService
argument_list|()
argument_list|)
expr_stmt|;
name|spyR
operator|.
name|clear
argument_list|()
expr_stmt|;
name|spyU
operator|.
name|clear
argument_list|()
expr_stmt|;
name|spyO
operator|.
name|clear
argument_list|()
expr_stmt|;
name|watcher
operator|.
name|setWatchMode
argument_list|(
name|QDBusServiceWatcher
operator|::
name|WatchForUnregistration
argument_list|)
expr_stmt|;
comment|// unregister it:
name|con
operator|.
name|unregisterService
argument_list|(
name|serviceName
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|connect
argument_list|(
operator|&
name|watcher
argument_list|,
name|SIGNAL
argument_list|(
name|serviceUnregistered
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|exitLoop
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|timeout
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyR
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyU
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyU
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|serviceName
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|serviceName
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|con
operator|.
name|baseService
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|spyO
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QDBusServiceWatcher
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qdbusservicewatcher.moc"
end_include
end_unit
