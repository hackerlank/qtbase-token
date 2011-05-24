begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVector>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtDBus>
end_include
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QVariant
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QList<int>
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QVector<int>
argument_list|)
end_macro
begin_class
DECL|class|tst_QDBusLocalCalls
class|class
name|tst_QDBusLocalCalls
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Interface"
argument_list|,
literal|"local.tst_QDBusLocalCalls"
argument_list|)
DECL|member|conn
name|QDBusConnection
name|conn
decl_stmt|;
public|public:
name|tst_QDBusLocalCalls
parameter_list|()
constructor_decl|;
public|public
name|Q_SLOTS
public|:
DECL|function|echo
name|Q_SCRIPTABLE
name|int
name|echo
parameter_list|(
name|int
name|value
parameter_list|)
block|{
return|return
name|value
return|;
block|}
DECL|function|echo
name|Q_SCRIPTABLE
name|QString
name|echo
parameter_list|(
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
block|{
return|return
name|value
return|;
block|}
DECL|function|echo
name|Q_SCRIPTABLE
name|QDBusVariant
name|echo
parameter_list|(
specifier|const
name|QDBusVariant
modifier|&
name|value
parameter_list|)
block|{
return|return
name|value
return|;
block|}
DECL|function|echo
name|Q_SCRIPTABLE
name|QVector
argument_list|<
name|int
argument_list|>
name|echo
parameter_list|(
specifier|const
name|QVector
argument_list|<
name|int
argument_list|>
modifier|&
name|value
parameter_list|)
block|{
return|return
name|value
return|;
block|}
DECL|function|echo2
name|Q_SCRIPTABLE
name|QString
name|echo2
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|list
parameter_list|,
name|QString
modifier|&
name|out
parameter_list|)
block|{
name|out
operator|=
name|list
index|[
literal|1
index|]
expr_stmt|;
return|return
name|list
index|[
literal|0
index|]
return|;
block|}
DECL|function|delayed
name|Q_SCRIPTABLE
name|void
name|delayed
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|msg
parameter_list|)
block|{
name|msg
operator|.
name|setDelayedReply
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
protected|protected
name|Q_SLOTS
protected|:
name|void
name|replyReceived
parameter_list|(
name|QDBusPendingCallWatcher
modifier|*
name|watcher
parameter_list|)
function_decl|;
private|private
name|Q_SLOTS
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|makeInvalidCalls
parameter_list|()
function_decl|;
name|void
name|makeCalls_data
parameter_list|()
function_decl|;
name|void
name|makeCalls
parameter_list|()
function_decl|;
name|void
name|makeCallsVariant_data
parameter_list|()
function_decl|;
name|void
name|makeCallsVariant
parameter_list|()
function_decl|;
name|void
name|makeCallsTwoRets
parameter_list|()
function_decl|;
name|void
name|makeCallsComplex
parameter_list|()
function_decl|;
name|void
name|makeDelayedCalls
parameter_list|()
function_decl|;
name|void
name|asyncReplySignal
parameter_list|()
function_decl|;
private|private:
DECL|member|asyncReplyArgs
name|QVariantList
name|asyncReplyArgs
decl_stmt|;
name|QDBusMessage
name|doCall
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|call
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QDBusLocalCalls
name|tst_QDBusLocalCalls
operator|::
name|tst_QDBusLocalCalls
parameter_list|()
member_init_list|:
name|conn
argument_list|(
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|doCall
name|QDBusMessage
name|tst_QDBusLocalCalls
operator|::
name|doCall
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|call
parameter_list|)
block|{
name|QFETCH_GLOBAL
argument_list|(
name|bool
argument_list|,
name|useAsync
argument_list|)
expr_stmt|;
if|if
condition|(
name|useAsync
condition|)
block|{
name|QDBusPendingCall
name|ac
init|=
name|conn
operator|.
name|asyncCall
argument_list|(
name|call
argument_list|)
decl_stmt|;
name|ac
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
return|return
name|ac
operator|.
name|reply
argument_list|()
return|;
block|}
else|else
block|{
return|return
name|conn
operator|.
name|call
argument_list|(
name|call
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|replyReceived
name|void
name|tst_QDBusLocalCalls
operator|::
name|replyReceived
parameter_list|(
name|QDBusPendingCallWatcher
modifier|*
name|watcher
parameter_list|)
block|{
name|asyncReplyArgs
operator|=
name|watcher
operator|->
name|reply
argument_list|()
operator|.
name|arguments
argument_list|()
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|exitLoop
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initTestCase
name|void
name|tst_QDBusLocalCalls
operator|::
name|initTestCase
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|conn
operator|.
name|isConnected
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|conn
operator|.
name|registerObject
argument_list|(
literal|"/"
argument_list|,
name|this
argument_list|,
name|QDBusConnection
operator|::
name|ExportScriptableSlots
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"useAsync"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"sync"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"async"
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|makeCalls_data
name|void
name|tst_QDBusLocalCalls
operator|::
name|makeCalls_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QVariant
argument_list|>
argument_list|(
literal|"value"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"int"
argument_list|)
operator|<<
name|QVariant
argument_list|(
literal|42
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"string"
argument_list|)
operator|<<
name|QVariant
argument_list|(
literal|"Hello, world"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|makeCallsVariant_data
name|void
name|tst_QDBusLocalCalls
operator|::
name|makeCallsVariant_data
parameter_list|()
block|{
name|makeCalls_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|makeInvalidCalls
name|void
name|tst_QDBusLocalCalls
operator|::
name|makeInvalidCalls
parameter_list|()
block|{
block|{
name|QDBusMessage
name|callMsg
init|=
name|QDBusMessage
operator|::
name|createMethodCall
argument_list|(
name|conn
operator|.
name|baseService
argument_list|()
argument_list|,
literal|"/"
argument_list|,
name|QString
argument_list|()
argument_list|,
literal|"echo"
argument_list|)
decl_stmt|;
name|QDBusMessage
name|replyMsg
init|=
name|doCall
argument_list|(
name|callMsg
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|replyMsg
operator|.
name|type
argument_list|()
argument_list|)
argument_list|,
name|int
argument_list|(
name|QDBusMessage
operator|::
name|ErrorMessage
argument_list|)
argument_list|)
expr_stmt|;
name|QDBusError
name|error
argument_list|(
name|replyMsg
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|error
operator|.
name|type
argument_list|()
argument_list|)
argument_list|,
name|int
argument_list|(
name|QDBusError
operator|::
name|UnknownMethod
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QDBusMessage
name|callMsg
init|=
name|QDBusMessage
operator|::
name|createMethodCall
argument_list|(
name|conn
operator|.
name|baseService
argument_list|()
argument_list|,
literal|"/no_object"
argument_list|,
name|QString
argument_list|()
argument_list|,
literal|"echo"
argument_list|)
decl_stmt|;
name|QDBusMessage
name|replyMsg
init|=
name|doCall
argument_list|(
name|callMsg
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|replyMsg
operator|.
name|type
argument_list|()
argument_list|)
argument_list|,
name|int
argument_list|(
name|QDBusMessage
operator|::
name|ErrorMessage
argument_list|)
argument_list|)
expr_stmt|;
name|QDBusError
name|error
argument_list|(
name|replyMsg
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|error
operator|.
name|type
argument_list|()
argument_list|)
argument_list|,
name|int
argument_list|(
name|QDBusError
operator|::
name|UnknownObject
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|makeCalls
name|void
name|tst_QDBusLocalCalls
operator|::
name|makeCalls
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QVariant
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|QDBusMessage
name|callMsg
init|=
name|QDBusMessage
operator|::
name|createMethodCall
argument_list|(
name|conn
operator|.
name|baseService
argument_list|()
argument_list|,
literal|"/"
argument_list|,
name|QString
argument_list|()
argument_list|,
literal|"echo"
argument_list|)
decl_stmt|;
name|callMsg
operator|<<
name|value
expr_stmt|;
name|QDBusMessage
name|replyMsg
init|=
name|doCall
argument_list|(
name|callMsg
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|replyMsg
operator|.
name|type
argument_list|()
argument_list|)
argument_list|,
name|int
argument_list|(
name|QDBusMessage
operator|::
name|ReplyMessage
argument_list|)
argument_list|)
expr_stmt|;
name|QVariantList
name|replyArgs
init|=
name|replyMsg
operator|.
name|arguments
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|replyArgs
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|replyArgs
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|makeCallsVariant
name|void
name|tst_QDBusLocalCalls
operator|::
name|makeCallsVariant
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QVariant
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|QDBusMessage
name|callMsg
init|=
name|QDBusMessage
operator|::
name|createMethodCall
argument_list|(
name|conn
operator|.
name|baseService
argument_list|()
argument_list|,
literal|"/"
argument_list|,
name|QString
argument_list|()
argument_list|,
literal|"echo"
argument_list|)
decl_stmt|;
name|callMsg
operator|<<
name|qVariantFromValue
argument_list|(
name|QDBusVariant
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
name|QDBusMessage
name|replyMsg
init|=
name|doCall
argument_list|(
name|callMsg
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|replyMsg
operator|.
name|type
argument_list|()
argument_list|)
argument_list|,
name|int
argument_list|(
name|QDBusMessage
operator|::
name|ReplyMessage
argument_list|)
argument_list|)
expr_stmt|;
name|QVariantList
name|replyArgs
init|=
name|replyMsg
operator|.
name|arguments
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|replyArgs
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
specifier|const
name|QVariant
modifier|&
name|reply
init|=
name|replyArgs
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|reply
operator|.
name|userType
argument_list|()
argument_list|,
name|qMetaTypeId
argument_list|<
name|QDBusVariant
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qvariant_cast
argument_list|<
name|QDBusVariant
argument_list|>
argument_list|(
name|reply
argument_list|)
operator|.
name|variant
argument_list|()
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|makeCallsTwoRets
name|void
name|tst_QDBusLocalCalls
operator|::
name|makeCallsTwoRets
parameter_list|()
block|{
name|QDBusMessage
name|callMsg
init|=
name|QDBusMessage
operator|::
name|createMethodCall
argument_list|(
name|conn
operator|.
name|baseService
argument_list|()
argument_list|,
literal|"/"
argument_list|,
name|QString
argument_list|()
argument_list|,
literal|"echo2"
argument_list|)
decl_stmt|;
name|callMsg
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|)
expr_stmt|;
name|QDBusMessage
name|replyMsg
init|=
name|doCall
argument_list|(
name|callMsg
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|replyMsg
operator|.
name|type
argument_list|()
argument_list|)
argument_list|,
name|int
argument_list|(
name|QDBusMessage
operator|::
name|ReplyMessage
argument_list|)
argument_list|)
expr_stmt|;
name|QVariantList
name|replyArgs
init|=
name|replyMsg
operator|.
name|arguments
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|replyArgs
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|replyArgs
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"One"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|replyArgs
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Two"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|makeCallsComplex
name|void
name|tst_QDBusLocalCalls
operator|::
name|makeCallsComplex
parameter_list|()
block|{
name|qDBusRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|int
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QVector
argument_list|<
name|int
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|QList
argument_list|<
name|int
argument_list|>
name|value
decl_stmt|;
name|value
operator|<<
literal|1
operator|<<
operator|-
literal|42
operator|<<
literal|47
expr_stmt|;
name|QDBusMessage
name|callMsg
init|=
name|QDBusMessage
operator|::
name|createMethodCall
argument_list|(
name|conn
operator|.
name|baseService
argument_list|()
argument_list|,
literal|"/"
argument_list|,
name|QString
argument_list|()
argument_list|,
literal|"echo"
argument_list|)
decl_stmt|;
name|callMsg
operator|<<
name|qVariantFromValue
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|QDBusMessage
name|replyMsg
init|=
name|doCall
argument_list|(
name|callMsg
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|replyMsg
operator|.
name|type
argument_list|()
argument_list|)
argument_list|,
name|int
argument_list|(
name|QDBusMessage
operator|::
name|ReplyMessage
argument_list|)
argument_list|)
expr_stmt|;
name|QVariantList
name|replyArgs
init|=
name|replyMsg
operator|.
name|arguments
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|replyArgs
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
specifier|const
name|QVariant
modifier|&
name|reply
init|=
name|replyArgs
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|reply
operator|.
name|userType
argument_list|()
argument_list|,
name|qMetaTypeId
argument_list|<
name|QDBusArgument
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qdbus_cast
argument_list|<
name|QList
argument_list|<
name|int
argument_list|>
argument_list|>
argument_list|(
name|reply
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|makeDelayedCalls
name|void
name|tst_QDBusLocalCalls
operator|::
name|makeDelayedCalls
parameter_list|()
block|{
name|QDBusMessage
name|callMsg
init|=
name|QDBusMessage
operator|::
name|createMethodCall
argument_list|(
name|conn
operator|.
name|baseService
argument_list|()
argument_list|,
literal|"/"
argument_list|,
name|QString
argument_list|()
argument_list|,
literal|"delayed"
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"QDBusConnection: cannot call local method 'delayed' at object / (with signature '') on blocking mode"
argument_list|)
expr_stmt|;
name|QDBusMessage
name|replyMsg
init|=
name|doCall
argument_list|(
name|callMsg
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|replyMsg
operator|.
name|type
argument_list|()
argument_list|)
argument_list|,
name|int
argument_list|(
name|QDBusMessage
operator|::
name|ErrorMessage
argument_list|)
argument_list|)
expr_stmt|;
name|QDBusError
name|error
argument_list|(
name|replyMsg
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|error
operator|.
name|type
argument_list|()
argument_list|)
argument_list|,
name|int
argument_list|(
name|QDBusError
operator|::
name|InternalError
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|asyncReplySignal
name|void
name|tst_QDBusLocalCalls
operator|::
name|asyncReplySignal
parameter_list|()
block|{
name|QFETCH_GLOBAL
argument_list|(
name|bool
argument_list|,
name|useAsync
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|useAsync
condition|)
return|return;
comment|// this test only works in async mode
name|QDBusMessage
name|callMsg
init|=
name|QDBusMessage
operator|::
name|createMethodCall
argument_list|(
name|conn
operator|.
name|baseService
argument_list|()
argument_list|,
literal|"/"
argument_list|,
name|QString
argument_list|()
argument_list|,
literal|"echo"
argument_list|)
decl_stmt|;
name|callMsg
operator|<<
literal|"Hello World"
expr_stmt|;
name|QDBusPendingCall
name|ac
init|=
name|conn
operator|.
name|asyncCall
argument_list|(
name|callMsg
argument_list|)
decl_stmt|;
if|if
condition|(
name|ac
operator|.
name|isFinished
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"Test ignored: the local-loop async call is already finished"
argument_list|,
name|SkipAll
argument_list|)
expr_stmt|;
name|QDBusPendingCallWatcher
name|watch
argument_list|(
name|ac
argument_list|)
decl_stmt|;
name|connect
argument_list|(
operator|&
name|watch
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|(
name|QDBusPendingCallWatcher
operator|*
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|replyReceived
argument_list|(
name|QDBusPendingCallWatcher
operator|*
argument_list|)
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
literal|2
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
name|QVERIFY
argument_list|(
name|ac
operator|.
name|isFinished
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|ac
operator|.
name|isError
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|asyncReplyArgs
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|asyncReplyArgs
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Hello World"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QDBusLocalCalls
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qdbuslocalcalls.moc"
end_include
end_unit
