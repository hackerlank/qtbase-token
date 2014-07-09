begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSystemSemaphore>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVector>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTemporaryDir>
end_include
begin_define
DECL|macro|EXISTING_SHARE
define|#
directive|define
name|EXISTING_SHARE
value|"existing"
end_define
begin_define
DECL|macro|HELPERWAITTIME
define|#
directive|define
name|HELPERWAITTIME
value|10000
end_define
begin_class
DECL|class|tst_QSystemSemaphore
class|class
name|tst_QSystemSemaphore
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QSystemSemaphore
parameter_list|()
constructor_decl|;
public|public
name|Q_SLOTS
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|key_data
parameter_list|()
function_decl|;
name|void
name|key
parameter_list|()
function_decl|;
name|void
name|basicacquire
parameter_list|()
function_decl|;
name|void
name|complexacquire
parameter_list|()
function_decl|;
name|void
name|release
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_PROCESS
name|void
name|basicProcesses
parameter_list|()
function_decl|;
name|void
name|processes_data
parameter_list|()
function_decl|;
name|void
name|processes
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|Q_OS_WIN
name|void
name|undo
parameter_list|()
function_decl|;
endif|#
directive|endif
name|void
name|initialValue
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|// QT_NO_PROCESS
private|private:
specifier|static
name|QString
name|helperBinary
parameter_list|()
function_decl|;
DECL|member|existingLock
name|QSystemSemaphore
modifier|*
name|existingLock
decl_stmt|;
DECL|member|m_helperBinary
specifier|const
name|QString
name|m_helperBinary
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QSystemSemaphore
name|tst_QSystemSemaphore
operator|::
name|tst_QSystemSemaphore
parameter_list|()
member_init_list|:
name|m_helperBinary
argument_list|(
name|helperBinary
argument_list|()
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QSystemSemaphore
operator|::
name|initTestCase
parameter_list|()
block|{
name|QVERIFY2
argument_list|(
operator|!
name|m_helperBinary
operator|.
name|isEmpty
argument_list|()
argument_list|,
literal|"Could not find helper binary"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|tst_QSystemSemaphore
operator|::
name|init
parameter_list|()
block|{
name|existingLock
operator|=
operator|new
name|QSystemSemaphore
argument_list|(
name|EXISTING_SHARE
argument_list|,
literal|1
argument_list|,
name|QSystemSemaphore
operator|::
name|Create
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QSystemSemaphore
operator|::
name|cleanup
parameter_list|()
block|{
operator|delete
name|existingLock
expr_stmt|;
block|}
end_function
begin_function
DECL|function|key_data
name|void
name|tst_QSystemSemaphore
operator|::
name|key_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"constructorKey"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"setKey"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null, null"
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null, one"
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|(
literal|"one"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"one, two"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"one"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"two"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Basic key testing  */
end_comment
begin_function
DECL|function|key
name|void
name|tst_QSystemSemaphore
operator|::
name|key
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|constructorKey
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|setKey
argument_list|)
expr_stmt|;
name|QSystemSemaphore
name|sem
argument_list|(
name|constructorKey
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|key
argument_list|()
argument_list|,
name|constructorKey
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|errorString
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|sem
operator|.
name|setKey
argument_list|(
name|setKey
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|key
argument_list|()
argument_list|,
name|setKey
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|errorString
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|basicacquire
name|void
name|tst_QSystemSemaphore
operator|::
name|basicacquire
parameter_list|()
block|{
name|QSystemSemaphore
name|sem
argument_list|(
literal|"QSystemSemaphore_basicacquire"
argument_list|,
literal|1
argument_list|,
name|QSystemSemaphore
operator|::
name|Create
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|sem
operator|.
name|acquire
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sem
operator|.
name|release
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|errorString
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|complexacquire
name|void
name|tst_QSystemSemaphore
operator|::
name|complexacquire
parameter_list|()
block|{
name|QSystemSemaphore
name|sem
argument_list|(
literal|"QSystemSemaphore_complexacquire"
argument_list|,
literal|2
argument_list|,
name|QSystemSemaphore
operator|::
name|Create
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|sem
operator|.
name|acquire
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sem
operator|.
name|release
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sem
operator|.
name|acquire
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sem
operator|.
name|release
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sem
operator|.
name|acquire
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sem
operator|.
name|acquire
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sem
operator|.
name|release
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sem
operator|.
name|release
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|errorString
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|release
name|void
name|tst_QSystemSemaphore
operator|::
name|release
parameter_list|()
block|{
name|QSystemSemaphore
name|sem
argument_list|(
literal|"QSystemSemaphore_release"
argument_list|,
literal|0
argument_list|,
name|QSystemSemaphore
operator|::
name|Create
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|sem
operator|.
name|release
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sem
operator|.
name|release
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sem
operator|.
name|acquire
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sem
operator|.
name|acquire
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sem
operator|.
name|release
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sem
operator|.
name|release
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|error
argument_list|()
argument_list|,
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sem
operator|.
name|errorString
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROCESS
end_ifndef
begin_function
DECL|function|basicProcesses
name|void
name|tst_QSystemSemaphore
operator|::
name|basicProcesses
parameter_list|()
block|{
name|QSystemSemaphore
name|sem
argument_list|(
literal|"store"
argument_list|,
literal|0
argument_list|,
name|QSystemSemaphore
operator|::
name|Create
argument_list|)
decl_stmt|;
name|QProcess
name|acquire
decl_stmt|;
name|acquire
operator|.
name|setProcessChannelMode
argument_list|(
name|QProcess
operator|::
name|ForwardedChannels
argument_list|)
expr_stmt|;
name|QProcess
name|release
decl_stmt|;
name|release
operator|.
name|setProcessChannelMode
argument_list|(
name|QProcess
operator|::
name|ForwardedChannels
argument_list|)
expr_stmt|;
name|acquire
operator|.
name|start
argument_list|(
name|m_helperBinary
argument_list|,
name|QStringList
argument_list|(
literal|"acquire"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|acquire
operator|.
name|waitForStarted
argument_list|()
argument_list|,
literal|"Could not start helper binary"
argument_list|)
expr_stmt|;
name|acquire
operator|.
name|waitForFinished
argument_list|(
name|HELPERWAITTIME
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|acquire
operator|.
name|state
argument_list|()
operator|==
name|QProcess
operator|::
name|Running
argument_list|)
expr_stmt|;
name|acquire
operator|.
name|kill
argument_list|()
expr_stmt|;
name|release
operator|.
name|start
argument_list|(
name|m_helperBinary
argument_list|,
name|QStringList
argument_list|(
literal|"release"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|release
operator|.
name|waitForStarted
argument_list|()
argument_list|,
literal|"Could not start helper binary"
argument_list|)
expr_stmt|;
name|acquire
operator|.
name|waitForFinished
argument_list|(
name|HELPERWAITTIME
argument_list|)
expr_stmt|;
name|release
operator|.
name|waitForFinished
argument_list|(
name|HELPERWAITTIME
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|acquire
operator|.
name|state
argument_list|()
operator|==
name|QProcess
operator|::
name|NotRunning
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|processes_data
name|void
name|tst_QSystemSemaphore
operator|::
name|processes_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"processes"
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
literal|5
condition|;
operator|++
name|i
control|)
block|{
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1 process"
argument_list|)
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"3 process"
argument_list|)
operator|<<
literal|3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10 process"
argument_list|)
operator|<<
literal|10
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|processes
name|void
name|tst_QSystemSemaphore
operator|::
name|processes
parameter_list|()
block|{
name|QSystemSemaphore
name|sem
argument_list|(
literal|"store"
argument_list|,
literal|1
argument_list|,
name|QSystemSemaphore
operator|::
name|Create
argument_list|)
decl_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|processes
argument_list|)
expr_stmt|;
name|QVector
argument_list|<
name|QString
argument_list|>
name|scripts
argument_list|(
name|processes
argument_list|,
literal|"acquirerelease"
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QProcess
modifier|*
argument_list|>
name|consumers
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
name|scripts
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QProcess
modifier|*
name|p
init|=
operator|new
name|QProcess
decl_stmt|;
name|p
operator|->
name|setProcessChannelMode
argument_list|(
name|QProcess
operator|::
name|ForwardedChannels
argument_list|)
expr_stmt|;
name|consumers
operator|.
name|append
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|p
operator|->
name|start
argument_list|(
name|m_helperBinary
argument_list|,
name|QStringList
argument_list|(
name|scripts
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
operator|!
name|consumers
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|consumers
operator|.
name|first
argument_list|()
operator|->
name|waitForFinished
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|consumers
operator|.
name|first
argument_list|()
operator|->
name|exitStatus
argument_list|()
argument_list|,
name|QProcess
operator|::
name|NormalExit
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|consumers
operator|.
name|first
argument_list|()
operator|->
name|exitCode
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
operator|delete
name|consumers
operator|.
name|takeFirst
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|// This test only checks a unix behavior.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WIN
end_ifndef
begin_function
DECL|function|undo
name|void
name|tst_QSystemSemaphore
operator|::
name|undo
parameter_list|()
block|{
name|QSystemSemaphore
name|sem
argument_list|(
literal|"store"
argument_list|,
literal|1
argument_list|,
name|QSystemSemaphore
operator|::
name|Create
argument_list|)
decl_stmt|;
name|QStringList
name|acquireArguments
init|=
name|QStringList
argument_list|(
literal|"acquire"
argument_list|)
decl_stmt|;
name|QProcess
name|acquire
decl_stmt|;
name|acquire
operator|.
name|setProcessChannelMode
argument_list|(
name|QProcess
operator|::
name|ForwardedChannels
argument_list|)
expr_stmt|;
name|acquire
operator|.
name|start
argument_list|(
name|m_helperBinary
argument_list|,
name|acquireArguments
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|acquire
operator|.
name|waitForStarted
argument_list|()
argument_list|,
literal|"Could not start helper binary"
argument_list|)
expr_stmt|;
name|acquire
operator|.
name|waitForFinished
argument_list|(
name|HELPERWAITTIME
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|acquire
operator|.
name|state
argument_list|()
operator|==
name|QProcess
operator|::
name|NotRunning
argument_list|)
expr_stmt|;
comment|// At process exit the kernel should auto undo
name|acquire
operator|.
name|start
argument_list|(
name|m_helperBinary
argument_list|,
name|acquireArguments
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|acquire
operator|.
name|waitForStarted
argument_list|()
argument_list|,
literal|"Could not start helper binary"
argument_list|)
expr_stmt|;
name|acquire
operator|.
name|waitForFinished
argument_list|(
name|HELPERWAITTIME
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|acquire
operator|.
name|state
argument_list|()
operator|==
name|QProcess
operator|::
name|NotRunning
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|initialValue
name|void
name|tst_QSystemSemaphore
operator|::
name|initialValue
parameter_list|()
block|{
name|QSystemSemaphore
name|sem
argument_list|(
literal|"store"
argument_list|,
literal|1
argument_list|,
name|QSystemSemaphore
operator|::
name|Create
argument_list|)
decl_stmt|;
name|QStringList
name|acquireArguments
init|=
name|QStringList
argument_list|(
literal|"acquire"
argument_list|)
decl_stmt|;
name|QStringList
name|releaseArguments
init|=
name|QStringList
argument_list|(
literal|"release"
argument_list|)
decl_stmt|;
name|QProcess
name|acquire
decl_stmt|;
name|acquire
operator|.
name|setProcessChannelMode
argument_list|(
name|QProcess
operator|::
name|ForwardedChannels
argument_list|)
expr_stmt|;
name|QProcess
name|release
decl_stmt|;
name|release
operator|.
name|setProcessChannelMode
argument_list|(
name|QProcess
operator|::
name|ForwardedChannels
argument_list|)
expr_stmt|;
name|acquire
operator|.
name|start
argument_list|(
name|m_helperBinary
argument_list|,
name|acquireArguments
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|acquire
operator|.
name|waitForStarted
argument_list|()
argument_list|,
literal|"Could not start helper binary"
argument_list|)
expr_stmt|;
name|acquire
operator|.
name|waitForFinished
argument_list|(
name|HELPERWAITTIME
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|acquire
operator|.
name|state
argument_list|()
operator|==
name|QProcess
operator|::
name|NotRunning
argument_list|)
expr_stmt|;
name|acquire
operator|.
name|start
argument_list|(
name|m_helperBinary
argument_list|,
name|acquireArguments
operator|<<
name|QLatin1String
argument_list|(
literal|"2"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|acquire
operator|.
name|waitForStarted
argument_list|()
argument_list|,
literal|"Could not start helper binary"
argument_list|)
expr_stmt|;
name|acquire
operator|.
name|waitForFinished
argument_list|(
name|HELPERWAITTIME
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|acquire
operator|.
name|state
argument_list|()
operator|==
name|QProcess
operator|::
name|Running
argument_list|)
expr_stmt|;
name|acquire
operator|.
name|kill
argument_list|()
expr_stmt|;
name|release
operator|.
name|start
argument_list|(
name|m_helperBinary
argument_list|,
name|releaseArguments
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|release
operator|.
name|waitForStarted
argument_list|()
argument_list|,
literal|"Could not start helper binary"
argument_list|)
expr_stmt|;
name|acquire
operator|.
name|waitForFinished
argument_list|(
name|HELPERWAITTIME
argument_list|)
expr_stmt|;
name|release
operator|.
name|waitForFinished
argument_list|(
name|HELPERWAITTIME
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|acquire
operator|.
name|state
argument_list|()
operator|==
name|QProcess
operator|::
name|NotRunning
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|helperBinary
name|QString
name|tst_QSystemSemaphore
operator|::
name|helperBinary
parameter_list|()
block|{
name|QString
name|binary
init|=
name|QStringLiteral
argument_list|(
literal|"helperbinary"
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|binary
operator|+=
name|QStringLiteral
argument_list|(
literal|".exe"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|QFINDTESTDATA
argument_list|(
name|binary
argument_list|)
return|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSystemSemaphore
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsystemsemaphore.moc"
end_include
end_unit
