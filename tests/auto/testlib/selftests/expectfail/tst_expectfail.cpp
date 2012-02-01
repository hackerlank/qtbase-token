begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QTest::TestFailMode
argument_list|)
end_macro
begin_class
DECL|class|tst_ExpectFail
class|class
name|tst_ExpectFail
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|xfailAndContinue
parameter_list|()
specifier|const
function_decl|;
name|void
name|xfailAndAbort
parameter_list|()
specifier|const
function_decl|;
name|void
name|xfailTwice
parameter_list|()
specifier|const
function_decl|;
name|void
name|xfailWithQString
parameter_list|()
specifier|const
function_decl|;
name|void
name|xfailDataDriven_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|xfailDataDriven
parameter_list|()
specifier|const
function_decl|;
name|void
name|xfailOnWrongRow_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|xfailOnWrongRow
parameter_list|()
specifier|const
function_decl|;
name|void
name|xfailOnAnyRow_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|xfailOnAnyRow
parameter_list|()
specifier|const
function_decl|;
name|void
name|xpass
parameter_list|()
specifier|const
function_decl|;
name|void
name|xpassDataDriven_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|xpassDataDriven
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|xfailAndContinue
name|void
name|tst_ExpectFail
operator|::
name|xfailAndContinue
parameter_list|()
specifier|const
block|{
name|qDebug
argument_list|(
literal|"begin"
argument_list|)
expr_stmt|;
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"This should xfail"
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"after"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|xfailAndAbort
name|void
name|tst_ExpectFail
operator|::
name|xfailAndAbort
parameter_list|()
specifier|const
block|{
name|qDebug
argument_list|(
literal|"begin"
argument_list|)
expr_stmt|;
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"This should xfail"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
literal|false
argument_list|)
expr_stmt|;
comment|// If we get here the test did not correctly abort on the previous QVERIFY.
name|QVERIFY2
argument_list|(
literal|false
argument_list|,
literal|"This should not be reached"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|xfailTwice
name|void
name|tst_ExpectFail
operator|::
name|xfailTwice
parameter_list|()
specifier|const
block|{
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"Calling QEXPECT_FAIL once is fine"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"Calling QEXPECT_FAIL when already expecting a failure is "
literal|"an error and should abort this test function"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
comment|// If we get here the test did not correctly abort on the double call to QEXPECT_FAIL.
name|QVERIFY2
argument_list|(
literal|false
argument_list|,
literal|"This should not be reached"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|xfailWithQString
name|void
name|tst_ExpectFail
operator|::
name|xfailWithQString
parameter_list|()
specifier|const
block|{
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
name|QString
argument_list|(
literal|"A string"
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|int
name|bugNo
init|=
literal|5
decl_stmt|;
name|QString
name|msg
argument_list|(
literal|"The message"
argument_list|)
decl_stmt|;
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
name|QString
argument_list|(
literal|"Bug %1 (%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|bugNo
argument_list|)
operator|.
name|arg
argument_list|(
name|msg
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|xfailDataDriven_data
name|void
name|tst_ExpectFail
operator|::
name|xfailDataDriven_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"shouldPass"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QTest
operator|::
name|TestFailMode
argument_list|>
argument_list|(
literal|"failMode"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Pass 1"
argument_list|)
operator|<<
literal|true
operator|<<
name|QTest
operator|::
name|Abort
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Pass 2"
argument_list|)
operator|<<
literal|true
operator|<<
name|QTest
operator|::
name|Continue
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Abort"
argument_list|)
operator|<<
literal|false
operator|<<
name|QTest
operator|::
name|Abort
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Continue"
argument_list|)
operator|<<
literal|false
operator|<<
name|QTest
operator|::
name|Continue
expr_stmt|;
block|}
end_function
begin_function
DECL|function|xfailDataDriven
name|void
name|tst_ExpectFail
operator|::
name|xfailDataDriven
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|shouldPass
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QTest
operator|::
name|TestFailMode
argument_list|,
name|failMode
argument_list|)
expr_stmt|;
comment|// You can't pass a variable as the last parameter of QEXPECT_FAIL,
comment|// because the macro adds "QTest::" in front of the last parameter.
comment|// That is why the following code appears to be a little strange.
if|if
condition|(
operator|!
name|shouldPass
condition|)
block|{
if|if
condition|(
name|failMode
operator|==
name|QTest
operator|::
name|Abort
condition|)
name|QEXPECT_FAIL
argument_list|(
name|QTest
operator|::
name|currentDataTag
argument_list|()
argument_list|,
literal|"This test should xfail"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
else|else
name|QEXPECT_FAIL
argument_list|(
name|QTest
operator|::
name|currentDataTag
argument_list|()
argument_list|,
literal|"This test should xfail"
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|shouldPass
argument_list|)
expr_stmt|;
comment|// If we get here, we either expected to pass or we expected to
comment|// fail and the failure mode was Continue.
if|if
condition|(
operator|!
name|shouldPass
condition|)
name|QCOMPARE
argument_list|(
name|failMode
argument_list|,
name|QTest
operator|::
name|Continue
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|xfailOnWrongRow_data
name|void
name|tst_ExpectFail
operator|::
name|xfailOnWrongRow_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"dummy"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"right row"
argument_list|)
operator|<<
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|xfailOnWrongRow
name|void
name|tst_ExpectFail
operator|::
name|xfailOnWrongRow
parameter_list|()
specifier|const
block|{
comment|// QEXPECT_FAIL for a row that is not the current row should be ignored.
name|QEXPECT_FAIL
argument_list|(
literal|"wrong row"
argument_list|,
literal|"This xfail should be ignored"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|xfailOnAnyRow_data
name|void
name|tst_ExpectFail
operator|::
name|xfailOnAnyRow_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"dummy"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"first row"
argument_list|)
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"second row"
argument_list|)
operator|<<
literal|1
expr_stmt|;
block|}
end_function
begin_function
DECL|function|xfailOnAnyRow
name|void
name|tst_ExpectFail
operator|::
name|xfailOnAnyRow
parameter_list|()
specifier|const
block|{
comment|// In a data-driven test, passing an empty first parameter to QEXPECT_FAIL
comment|// should mean that the failure is expected for all data rows.
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"This test should xfail"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|xpass
name|void
name|tst_ExpectFail
operator|::
name|xpass
parameter_list|()
specifier|const
block|{
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"This test should xpass"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|// If we get here the test did not correctly abort on the previous
comment|// unexpected pass.
name|QVERIFY2
argument_list|(
literal|false
argument_list|,
literal|"This should not be reached"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|xpassDataDriven_data
name|void
name|tst_ExpectFail
operator|::
name|xpassDataDriven_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"shouldXPass"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"XPass"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Pass"
argument_list|)
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|xpassDataDriven
name|void
name|tst_ExpectFail
operator|::
name|xpassDataDriven
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|shouldXPass
argument_list|)
expr_stmt|;
if|if
condition|(
name|shouldXPass
condition|)
name|QEXPECT_FAIL
argument_list|(
name|QTest
operator|::
name|currentDataTag
argument_list|()
argument_list|,
literal|"This test should xpass"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|// We should only get here if the test wasn't supposed to xpass.
name|QVERIFY2
argument_list|(
operator|!
name|shouldXPass
argument_list|,
literal|"Test failed to terminate on XPASS"
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_ExpectFail
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_expectfail.moc"
end_include
end_unit
