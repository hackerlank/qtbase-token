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
begin_class
DECL|class|tst_Subtest
class|class
name|tst_Subtest
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public
name|slots
public|:
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|test1
parameter_list|()
function_decl|;
name|void
name|test2_data
parameter_list|()
function_decl|;
name|void
name|test2
parameter_list|()
function_decl|;
name|void
name|test3_data
parameter_list|()
function_decl|;
name|void
name|test3
parameter_list|()
function_decl|;
name|void
name|floatComparisons
parameter_list|()
specifier|const
function_decl|;
name|void
name|floatComparisons_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|compareFloatTests
parameter_list|()
specifier|const
function_decl|;
name|void
name|compareFloatTests_data
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_Subtest
operator|::
name|initTestCase
parameter_list|()
block|{
name|printf
argument_list|(
literal|"initTestCase %s %s\n"
argument_list|,
name|QTest
operator|::
name|currentTestFunction
argument_list|()
condition|?
name|QTest
operator|::
name|currentTestFunction
argument_list|()
else|:
literal|"(null)"
argument_list|,
name|QTest
operator|::
name|currentDataTag
argument_list|()
condition|?
name|QTest
operator|::
name|currentDataTag
argument_list|()
else|:
literal|"(null)"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_Subtest
operator|::
name|cleanupTestCase
parameter_list|()
block|{
name|printf
argument_list|(
literal|"cleanupTestCase %s %s\n"
argument_list|,
name|QTest
operator|::
name|currentTestFunction
argument_list|()
condition|?
name|QTest
operator|::
name|currentTestFunction
argument_list|()
else|:
literal|"(null)"
argument_list|,
name|QTest
operator|::
name|currentDataTag
argument_list|()
condition|?
name|QTest
operator|::
name|currentDataTag
argument_list|()
else|:
literal|"(null)"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|tst_Subtest
operator|::
name|init
parameter_list|()
block|{
name|printf
argument_list|(
literal|"init %s %s\n"
argument_list|,
name|QTest
operator|::
name|currentTestFunction
argument_list|()
condition|?
name|QTest
operator|::
name|currentTestFunction
argument_list|()
else|:
literal|"(null)"
argument_list|,
name|QTest
operator|::
name|currentDataTag
argument_list|()
condition|?
name|QTest
operator|::
name|currentDataTag
argument_list|()
else|:
literal|"(null)"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_Subtest
operator|::
name|cleanup
parameter_list|()
block|{
name|printf
argument_list|(
literal|"cleanup %s %s\n"
argument_list|,
name|QTest
operator|::
name|currentTestFunction
argument_list|()
condition|?
name|QTest
operator|::
name|currentTestFunction
argument_list|()
else|:
literal|"(null)"
argument_list|,
name|QTest
operator|::
name|currentDataTag
argument_list|()
condition|?
name|QTest
operator|::
name|currentDataTag
argument_list|()
else|:
literal|"(null)"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|test1
name|void
name|tst_Subtest
operator|::
name|test1
parameter_list|()
block|{
name|printf
argument_list|(
literal|"test1 %s %s\n"
argument_list|,
name|QTest
operator|::
name|currentTestFunction
argument_list|()
condition|?
name|QTest
operator|::
name|currentTestFunction
argument_list|()
else|:
literal|"(null)"
argument_list|,
name|QTest
operator|::
name|currentDataTag
argument_list|()
condition|?
name|QTest
operator|::
name|currentDataTag
argument_list|()
else|:
literal|"(null)"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|test2_data
name|void
name|tst_Subtest
operator|::
name|test2_data
parameter_list|()
block|{
name|printf
argument_list|(
literal|"test2_data %s %s\n"
argument_list|,
name|QTest
operator|::
name|currentTestFunction
argument_list|()
condition|?
name|QTest
operator|::
name|currentTestFunction
argument_list|()
else|:
literal|"(null)"
argument_list|,
name|QTest
operator|::
name|currentDataTag
argument_list|()
condition|?
name|QTest
operator|::
name|currentDataTag
argument_list|()
else|:
literal|"(null)"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"str"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"hello0"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"hello1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data2"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"hello2"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"test2_data end\n"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|test2
name|void
name|tst_Subtest
operator|::
name|test2
parameter_list|()
block|{
name|printf
argument_list|(
literal|"test2 %s %s\n"
argument_list|,
name|QTest
operator|::
name|currentTestFunction
argument_list|()
condition|?
name|QTest
operator|::
name|currentTestFunction
argument_list|()
else|:
literal|"(null)"
argument_list|,
name|QTest
operator|::
name|currentDataTag
argument_list|()
condition|?
name|QTest
operator|::
name|currentDataTag
argument_list|()
else|:
literal|"(null)"
argument_list|)
expr_stmt|;
specifier|static
name|int
name|count
init|=
literal|0
decl_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|str
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"hello%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|count
operator|++
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"test2 end\n"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|test3_data
name|void
name|tst_Subtest
operator|::
name|test3_data
parameter_list|()
block|{
name|printf
argument_list|(
literal|"test3_data %s %s\n"
argument_list|,
name|QTest
operator|::
name|currentTestFunction
argument_list|()
condition|?
name|QTest
operator|::
name|currentTestFunction
argument_list|()
else|:
literal|"(null)"
argument_list|,
name|QTest
operator|::
name|currentDataTag
argument_list|()
condition|?
name|QTest
operator|::
name|currentDataTag
argument_list|()
else|:
literal|"(null)"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"str"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"hello0"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"hello1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data2"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"hello2"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"test3_data end\n"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|test3
name|void
name|tst_Subtest
operator|::
name|test3
parameter_list|()
block|{
name|printf
argument_list|(
literal|"test2 %s %s\n"
argument_list|,
name|QTest
operator|::
name|currentTestFunction
argument_list|()
condition|?
name|QTest
operator|::
name|currentTestFunction
argument_list|()
else|:
literal|"(null)"
argument_list|,
name|QTest
operator|::
name|currentDataTag
argument_list|()
condition|?
name|QTest
operator|::
name|currentDataTag
argument_list|()
else|:
literal|"(null)"
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|str
argument_list|)
expr_stmt|;
comment|// second and third time we call this it shoud FAIL
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"hello0"
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"test2 end\n"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|floatComparisons
name|void
name|tst_Subtest
operator|::
name|floatComparisons
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|float
argument_list|,
name|operandLeft
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|float
argument_list|,
name|operandRight
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|operandLeft
argument_list|,
name|operandRight
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|floatComparisons_data
name|void
name|tst_Subtest
operator|::
name|floatComparisons_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|float
argument_list|>
argument_list|(
literal|"operandLeft"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|float
argument_list|>
argument_list|(
literal|"operandRight"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"should SUCCEED"
argument_list|)
operator|<<
name|float
argument_list|(
literal|0
argument_list|)
operator|<<
name|float
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"should FAIL"
argument_list|)
operator|<<
name|float
argument_list|(
literal|1.00000
argument_list|)
operator|<<
name|float
argument_list|(
literal|3.00000
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"should FAIL"
argument_list|)
operator|<<
name|float
argument_list|(
literal|1.00000e-7f
argument_list|)
operator|<<
name|float
argument_list|(
literal|3.00000e-7f
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"should FAIL"
argument_list|)
operator|<<
name|float
argument_list|(
literal|100001
argument_list|)
operator|<<
name|float
argument_list|(
literal|100002
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|compareFloatTests
name|void
name|tst_Subtest
operator|::
name|compareFloatTests
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|float
argument_list|,
name|t1
argument_list|)
expr_stmt|;
comment|// Create two more values
comment|// t2 differs from t1 by 1 ppm (part per million)
comment|// t3 differs from t1 by 200%
comment|// we should consider that t1 == t2 and t1 != t3
specifier|const
name|float
name|t2
init|=
name|t1
operator|+
operator|(
name|t1
operator|/
literal|1e6
operator|)
decl_stmt|;
specifier|const
name|float
name|t3
init|=
literal|3
operator|*
name|t1
decl_stmt|;
name|QCOMPARE
argument_list|(
name|t1
argument_list|,
name|t2
argument_list|)
expr_stmt|;
comment|/* Should FAIL. */
name|QCOMPARE
argument_list|(
name|t1
argument_list|,
name|t3
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|compareFloatTests_data
name|void
name|tst_Subtest
operator|::
name|compareFloatTests_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|float
argument_list|>
argument_list|(
literal|"t1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1e0"
argument_list|)
operator|<<
literal|1e0f
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1e-7"
argument_list|)
operator|<<
literal|1e-7f
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1e+7"
argument_list|)
operator|<<
literal|1e+7f
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_Subtest
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_subtest.moc"
end_include
end_unit
