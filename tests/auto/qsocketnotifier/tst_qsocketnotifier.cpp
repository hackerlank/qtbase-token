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
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSocketNotifier>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QTcpServer>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QTcpSocket>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
end_ifdef
begin_include
include|#
directive|include
file|<private/qsymbiansocketengine_p.h>
end_include
begin_define
DECL|macro|NATIVESOCKETENGINE
define|#
directive|define
name|NATIVESOCKETENGINE
value|QSymbianSocketEngine
end_define
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<private/qnativesocketengine_p.h>
end_include
begin_define
DECL|macro|NATIVESOCKETENGINE
define|#
directive|define
name|NATIVESOCKETENGINE
value|QNativeSocketEngine
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_QSocketNotifier
class|class
name|tst_QSocketNotifier
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QSocketNotifier
parameter_list|()
constructor_decl|;
name|~
name|tst_QSocketNotifier
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|unexpectedDisconnection
parameter_list|()
function_decl|;
name|void
name|mixingWithTimers
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QSocketNotifier
name|tst_QSocketNotifier
operator|::
name|tst_QSocketNotifier
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QSocketNotifier
name|tst_QSocketNotifier
operator|::
name|~
name|tst_QSocketNotifier
parameter_list|()
block|{ }
end_destructor
begin_class
DECL|class|UnexpectedDisconnectTester
class|class
name|UnexpectedDisconnectTester
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|member|readEnd1
DECL|member|readEnd2
name|NATIVESOCKETENGINE
modifier|*
name|readEnd1
decl_stmt|,
modifier|*
name|readEnd2
decl_stmt|;
DECL|member|sequence
name|int
name|sequence
decl_stmt|;
DECL|function|UnexpectedDisconnectTester
name|UnexpectedDisconnectTester
parameter_list|(
name|NATIVESOCKETENGINE
modifier|*
name|s1
parameter_list|,
name|NATIVESOCKETENGINE
modifier|*
name|s2
parameter_list|)
member_init_list|:
name|readEnd1
argument_list|(
name|s1
argument_list|)
member_init_list|,
name|readEnd2
argument_list|(
name|s2
argument_list|)
member_init_list|,
name|sequence
argument_list|(
literal|0
argument_list|)
block|{
name|QSocketNotifier
modifier|*
name|notifier1
init|=
operator|new
name|QSocketNotifier
argument_list|(
name|readEnd1
operator|->
name|socketDescriptor
argument_list|()
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|notifier1
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|handleActivated
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QSocketNotifier
modifier|*
name|notifier2
init|=
operator|new
name|QSocketNotifier
argument_list|(
name|readEnd2
operator|->
name|socketDescriptor
argument_list|()
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|notifier2
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|handleActivated
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
public|public
name|slots
public|:
DECL|function|handleActivated
name|void
name|handleActivated
parameter_list|()
block|{
name|char
name|data1
index|[
literal|1
index|]
decl_stmt|,
name|data2
index|[
literal|1
index|]
decl_stmt|;
operator|++
name|sequence
expr_stmt|;
if|if
condition|(
name|sequence
operator|==
literal|1
condition|)
block|{
comment|// read from both ends
operator|(
name|void
operator|)
name|readEnd1
operator|->
name|read
argument_list|(
name|data1
argument_list|,
sizeof|sizeof
argument_list|(
name|data1
argument_list|)
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|readEnd2
operator|->
name|read
argument_list|(
name|data2
argument_list|,
sizeof|sizeof
argument_list|(
name|data2
argument_list|)
argument_list|)
expr_stmt|;
emit|emit
name|finished
argument_list|()
emit|;
block|}
elseif|else
if|if
condition|(
name|sequence
operator|==
literal|2
condition|)
block|{
comment|// we should never get here
name|QCOMPARE
argument_list|(
name|readEnd2
operator|->
name|read
argument_list|(
name|data2
argument_list|,
sizeof|sizeof
argument_list|(
name|data2
argument_list|)
argument_list|)
argument_list|,
name|qint64
argument_list|(
operator|-
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|readEnd2
operator|->
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
signals|signals:
name|void
name|finished
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|unexpectedDisconnection
name|void
name|tst_QSocketNotifier
operator|::
name|unexpectedDisconnection
parameter_list|()
block|{
comment|/*       Given two sockets and two QSocketNotifiers registered on each       their socket. If both sockets receive data, and the first slot       invoked by one of the socket notifiers empties both sockets, the       other notifier will also emit activated(). This results in       unexpected disconnection in QAbstractSocket.        The use case is that somebody calls one of the       waitFor... functions in a QSocketNotifier activated slot, and       the waitFor... functions do local selects that can empty both       stdin and stderr while waiting for fex bytes to be written.     */
name|QTcpServer
name|server
decl_stmt|;
name|QVERIFY
argument_list|(
name|server
operator|.
name|listen
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|NATIVESOCKETENGINE
name|readEnd1
decl_stmt|;
name|readEnd1
operator|.
name|initialize
argument_list|(
name|QAbstractSocket
operator|::
name|TcpSocket
argument_list|)
expr_stmt|;
name|bool
name|b
init|=
name|readEnd1
operator|.
name|connectToHost
argument_list|(
name|server
operator|.
name|serverAddress
argument_list|()
argument_list|,
name|server
operator|.
name|serverPort
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|readEnd1
operator|.
name|waitForWrite
argument_list|()
argument_list|)
expr_stmt|;
comment|//    while (!b&& readEnd1.state() != QAbstractSocket::ConnectedState)
comment|//        b = readEnd1.connectToHost(server.serverAddress(), server.serverPort());
name|QVERIFY
argument_list|(
name|readEnd1
operator|.
name|state
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|ConnectedState
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|server
operator|.
name|waitForNewConnection
argument_list|()
argument_list|)
expr_stmt|;
name|QTcpSocket
modifier|*
name|writeEnd1
init|=
name|server
operator|.
name|nextPendingConnection
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|writeEnd1
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|NATIVESOCKETENGINE
name|readEnd2
decl_stmt|;
name|readEnd2
operator|.
name|initialize
argument_list|(
name|QAbstractSocket
operator|::
name|TcpSocket
argument_list|)
expr_stmt|;
name|b
operator|=
name|readEnd2
operator|.
name|connectToHost
argument_list|(
name|server
operator|.
name|serverAddress
argument_list|()
argument_list|,
name|server
operator|.
name|serverPort
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|readEnd2
operator|.
name|waitForWrite
argument_list|()
argument_list|)
expr_stmt|;
comment|//    while (!b)
comment|//        b = readEnd2.connectToHost(server.serverAddress(), server.serverPort());
name|QVERIFY
argument_list|(
name|readEnd2
operator|.
name|state
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|ConnectedState
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|server
operator|.
name|waitForNewConnection
argument_list|()
argument_list|)
expr_stmt|;
name|QTcpSocket
modifier|*
name|writeEnd2
init|=
name|server
operator|.
name|nextPendingConnection
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|writeEnd2
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|writeEnd1
operator|->
name|write
argument_list|(
literal|"1"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|writeEnd2
operator|->
name|write
argument_list|(
literal|"2"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|writeEnd1
operator|->
name|waitForBytesWritten
argument_list|()
expr_stmt|;
name|writeEnd2
operator|->
name|waitForBytesWritten
argument_list|()
expr_stmt|;
name|writeEnd1
operator|->
name|flush
argument_list|()
expr_stmt|;
name|writeEnd2
operator|->
name|flush
argument_list|()
expr_stmt|;
name|UnexpectedDisconnectTester
name|tester
argument_list|(
operator|&
name|readEnd1
argument_list|,
operator|&
name|readEnd2
argument_list|)
decl_stmt|;
do|do
block|{
comment|// we have to wait until sequence value changes
comment|// as any event can make us jump out processing
name|QCoreApplication
operator|::
name|processEvents
argument_list|(
name|QEventLoop
operator|::
name|WaitForMoreEvents
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|tester
operator|.
name|sequence
operator|<=
literal|0
condition|)
do|;
name|QVERIFY
argument_list|(
name|readEnd1
operator|.
name|state
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|ConnectedState
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|readEnd2
operator|.
name|state
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|ConnectedState
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tester
operator|.
name|sequence
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|readEnd1
operator|.
name|close
argument_list|()
expr_stmt|;
name|readEnd2
operator|.
name|close
argument_list|()
expr_stmt|;
name|writeEnd1
operator|->
name|close
argument_list|()
expr_stmt|;
name|writeEnd2
operator|->
name|close
argument_list|()
expr_stmt|;
name|server
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_class
DECL|class|MixingWithTimersHelper
class|class
name|MixingWithTimersHelper
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|MixingWithTimersHelper
parameter_list|(
name|QTimer
modifier|*
name|timer
parameter_list|,
name|QTcpServer
modifier|*
name|server
parameter_list|)
constructor_decl|;
DECL|member|timerActivated
name|bool
name|timerActivated
decl_stmt|;
DECL|member|socketActivated
name|bool
name|socketActivated
decl_stmt|;
private|private
name|slots
private|:
name|void
name|timerFired
parameter_list|()
function_decl|;
name|void
name|socketFired
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|MixingWithTimersHelper
name|MixingWithTimersHelper
operator|::
name|MixingWithTimersHelper
parameter_list|(
name|QTimer
modifier|*
name|timer
parameter_list|,
name|QTcpServer
modifier|*
name|server
parameter_list|)
block|{
name|timerActivated
operator|=
literal|false
expr_stmt|;
name|socketActivated
operator|=
literal|false
expr_stmt|;
name|connect
argument_list|(
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|timerFired
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|server
argument_list|,
name|SIGNAL
argument_list|(
name|newConnection
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|socketFired
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|timerFired
name|void
name|MixingWithTimersHelper
operator|::
name|timerFired
parameter_list|()
block|{
name|timerActivated
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|socketFired
name|void
name|MixingWithTimersHelper
operator|::
name|socketFired
parameter_list|()
block|{
name|socketActivated
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mixingWithTimers
name|void
name|tst_QSocketNotifier
operator|::
name|mixingWithTimers
parameter_list|()
block|{
name|QTimer
name|timer
decl_stmt|;
name|timer
operator|.
name|setInterval
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTcpServer
name|server
decl_stmt|;
name|QVERIFY
argument_list|(
name|server
operator|.
name|listen
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|MixingWithTimersHelper
name|helper
argument_list|(
operator|&
name|timer
argument_list|,
operator|&
name|server
argument_list|)
decl_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|helper
operator|.
name|timerActivated
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|helper
operator|.
name|socketActivated
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|helper
operator|.
name|timerActivated
operator|=
literal|false
expr_stmt|;
name|helper
operator|.
name|socketActivated
operator|=
literal|false
expr_stmt|;
name|QTcpSocket
name|socket
decl_stmt|;
name|socket
operator|.
name|connectToHost
argument_list|(
name|server
operator|.
name|serverAddress
argument_list|()
argument_list|,
name|server
operator|.
name|serverPort
argument_list|()
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|helper
operator|.
name|timerActivated
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|helper
operator|.
name|socketActivated
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSocketNotifier
argument_list|)
end_macro
begin_include
include|#
directive|include
file|<tst_qsocketnotifier.moc>
end_include
end_unit
