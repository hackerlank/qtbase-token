begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qsystemlock.h>
end_include
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
end_ifdef
begin_comment
comment|// In Symbian OS test data is located in applications private dir
end_comment
begin_comment
comment|// And underlying Open C have application private dir in default search path
end_comment
begin_define
DECL|macro|SRCDIR
define|#
directive|define
name|SRCDIR
value|""
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|EXISTING_SHARE
define|#
directive|define
name|EXISTING_SHARE
value|"existing"
end_define
begin_class
DECL|class|tst_QSystemLock
class|class
name|tst_QSystemLock
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QSystemLock
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QSystemLock
parameter_list|()
destructor_decl|;
public|public
name|Q_SLOTS
public|:
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
name|basicLock
parameter_list|()
function_decl|;
name|void
name|complexLock
parameter_list|()
function_decl|;
name|void
name|lockModes
parameter_list|()
function_decl|;
name|void
name|sucessive
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
private|private:
DECL|member|existingLock
name|QSystemLock
modifier|*
name|existingLock
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QSystemLock
name|tst_QSystemLock
operator|::
name|tst_QSystemLock
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QSystemLock
name|tst_QSystemLock
operator|::
name|~
name|tst_QSystemLock
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|init
name|void
name|tst_QSystemLock
operator|::
name|init
parameter_list|()
block|{
name|existingLock
operator|=
operator|new
name|QSystemLock
argument_list|(
name|EXISTING_SHARE
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QSystemLock
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
name|tst_QSystemLock
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
name|tst_QSystemLock
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
name|QSystemLock
name|sl
argument_list|(
name|constructorKey
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|sl
operator|.
name|key
argument_list|()
argument_list|,
name|constructorKey
argument_list|)
expr_stmt|;
name|sl
operator|.
name|setKey
argument_list|(
name|setKey
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sl
operator|.
name|key
argument_list|()
argument_list|,
name|setKey
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|basicLock
name|void
name|tst_QSystemLock
operator|::
name|basicLock
parameter_list|()
block|{
name|QSystemLock
name|lock
argument_list|(
literal|"foo"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|lock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|unlock
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|complexLock
name|void
name|tst_QSystemLock
operator|::
name|complexLock
parameter_list|()
block|{
name|QSystemLock
name|lock
argument_list|(
literal|"foo"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|lock
argument_list|(
name|QSystemLock
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|unlock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|lock
argument_list|(
name|QSystemLock
operator|::
name|ReadWrite
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|unlock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|lock
argument_list|(
name|QSystemLock
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|lock
argument_list|(
name|QSystemLock
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|unlock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|unlock
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lockModes
name|void
name|tst_QSystemLock
operator|::
name|lockModes
parameter_list|()
block|{
name|QSystemLock
name|reader1
argument_list|(
literal|"library"
argument_list|)
decl_stmt|;
name|QSystemLock
name|reader2
argument_list|(
literal|"library"
argument_list|)
decl_stmt|;
name|QSystemLock
name|librarian
argument_list|(
literal|"library"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|reader1
operator|.
name|lock
argument_list|(
name|QSystemLock
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|reader2
operator|.
name|lock
argument_list|(
name|QSystemLock
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|reader1
operator|.
name|unlock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|reader2
operator|.
name|unlock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|librarian
operator|.
name|lock
argument_list|(
name|QSystemLock
operator|::
name|ReadWrite
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|librarian
operator|.
name|unlock
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sucessive
name|void
name|tst_QSystemLock
operator|::
name|sucessive
parameter_list|()
block|{
name|QSystemLock
name|lock
argument_list|(
literal|"library"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|lock
argument_list|(
name|QSystemLock
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|lock
argument_list|(
name|QSystemLock
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|lock
argument_list|(
name|QSystemLock
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|lock
argument_list|(
name|QSystemLock
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|lock
argument_list|(
name|QSystemLock
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|unlock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|unlock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|unlock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|unlock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lock
operator|.
name|unlock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|lock
operator|.
name|unlock
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|processes_data
name|void
name|tst_QSystemLock
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
literal|"readOnly"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"readWrite"
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
literal|"1/0 process"
argument_list|)
operator|<<
literal|1
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0/1 process"
argument_list|)
operator|<<
literal|0
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0/4 process"
argument_list|)
operator|<<
literal|0
operator|<<
literal|4
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1/1 process"
argument_list|)
operator|<<
literal|1
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10/1 process"
argument_list|)
operator|<<
literal|10
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1/10 process"
argument_list|)
operator|<<
literal|1
operator|<<
literal|10
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10/10 processes"
argument_list|)
operator|<<
literal|10
operator|<<
literal|10
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Create external processes  */
end_comment
begin_function
DECL|function|processes
name|void
name|tst_QSystemLock
operator|::
name|processes
parameter_list|()
block|{
name|QSKIP
argument_list|(
literal|"This test takes about 15 minutes and needs to be trimmed down before we can re-enable it"
argument_list|,
name|SkipAll
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|readOnly
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|readWrite
argument_list|)
expr_stmt|;
name|QStringList
name|scripts
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
name|readOnly
condition|;
operator|++
name|i
control|)
name|scripts
operator|.
name|append
argument_list|(
name|QFileInfo
argument_list|(
name|SRCDIR
literal|"/../lackey/scripts/systemlock_read.js"
argument_list|)
operator|.
name|absoluteFilePath
argument_list|()
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
name|readWrite
condition|;
operator|++
name|i
control|)
name|scripts
operator|.
name|append
argument_list|(
name|QFileInfo
argument_list|(
name|SRCDIR
literal|"/../lackey/scripts/systemlock_readwrite.js"
argument_list|)
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QProcess
modifier|*
argument_list|>
name|consumers
decl_stmt|;
name|unsigned
name|int
name|failedProcesses
init|=
literal|0
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
name|QStringList
name|arguments
init|=
name|QStringList
argument_list|()
operator|<<
name|scripts
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
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
name|p
operator|->
name|start
argument_list|(
literal|"../lackey/lackey"
argument_list|,
name|arguments
argument_list|)
expr_stmt|;
comment|// test, if the process could be started.
if|if
condition|(
name|p
operator|->
name|waitForStarted
argument_list|(
literal|2000
argument_list|)
condition|)
name|consumers
operator|.
name|append
argument_list|(
name|p
argument_list|)
expr_stmt|;
else|else
operator|++
name|failedProcesses
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
argument_list|(
literal|3000
argument_list|)
expr_stmt|;
name|consumers
operator|.
name|first
argument_list|()
operator|->
name|kill
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
name|QCOMPARE
argument_list|(
name|failedProcesses
argument_list|,
call|(
name|unsigned
name|int
call|)
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSystemLock
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsystemlock.moc"
end_include
end_unit
