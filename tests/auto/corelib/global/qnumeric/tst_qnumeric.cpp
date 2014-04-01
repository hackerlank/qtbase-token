begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtGlobal>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_include
include|#
directive|include
file|<float.h>
end_include
begin_class
DECL|class|tst_QNumeric
class|class
name|tst_QNumeric
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|fuzzyCompare_data
parameter_list|()
function_decl|;
name|void
name|fuzzyCompare
parameter_list|()
function_decl|;
name|void
name|qNan
parameter_list|()
function_decl|;
name|void
name|floatDistance_data
parameter_list|()
function_decl|;
name|void
name|floatDistance
parameter_list|()
function_decl|;
name|void
name|floatDistance_double_data
parameter_list|()
function_decl|;
name|void
name|floatDistance_double
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|fuzzyCompare_data
name|void
name|tst_QNumeric
operator|::
name|fuzzyCompare_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|double
argument_list|>
argument_list|(
literal|"val1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|double
argument_list|>
argument_list|(
literal|"val2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"isEqual"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"zero"
argument_list|)
operator|<<
literal|0.0
operator|<<
literal|0.0
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"ten"
argument_list|)
operator|<<
literal|10.0
operator|<<
literal|10.0
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"large"
argument_list|)
operator|<<
literal|1000000000.0
operator|<<
literal|1000000000.0
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"small"
argument_list|)
operator|<<
literal|0.00000000001
operator|<<
literal|0.00000000001
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"eps"
argument_list|)
operator|<<
literal|10.000000000000001
operator|<<
literal|10.00000000000002
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"eps2"
argument_list|)
operator|<<
literal|10.000000000000001
operator|<<
literal|10.000000000000009
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mis1"
argument_list|)
operator|<<
literal|0.0
operator|<<
literal|1.0
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mis2"
argument_list|)
operator|<<
literal|0.0
operator|<<
literal|10000000.0
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mis3"
argument_list|)
operator|<<
literal|0.0
operator|<<
literal|0.000000001
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mis4"
argument_list|)
operator|<<
literal|100000000.0
operator|<<
literal|0.000000001
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mis5"
argument_list|)
operator|<<
literal|0.0000000001
operator|<<
literal|0.000000001
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fuzzyCompare
name|void
name|tst_QNumeric
operator|::
name|fuzzyCompare
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|double
argument_list|,
name|val1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|double
argument_list|,
name|val2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|isEqual
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|::
name|qFuzzyCompare
argument_list|(
name|val1
argument_list|,
name|val2
argument_list|)
argument_list|,
name|isEqual
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|::
name|qFuzzyCompare
argument_list|(
name|val2
argument_list|,
name|val1
argument_list|)
argument_list|,
name|isEqual
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|::
name|qFuzzyCompare
argument_list|(
operator|-
name|val1
argument_list|,
operator|-
name|val2
argument_list|)
argument_list|,
name|isEqual
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|::
name|qFuzzyCompare
argument_list|(
operator|-
name|val2
argument_list|,
operator|-
name|val1
argument_list|)
argument_list|,
name|isEqual
argument_list|)
expr_stmt|;
block|}
end_function
begin_if
if|#
directive|if
name|defined
name|__FAST_MATH__
operator|&&
operator|(
name|__GNUC__
operator|*
literal|100
operator|+
name|__GNUC_MINOR__
operator|>=
literal|404
operator|)
end_if
begin_comment
comment|// turn -ffast-math off
end_comment
begin_pragma
pragma|#
directive|pragma
name|GCC
name|optimize
literal|"no-fast-math"
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|qNan
name|void
name|tst_QNumeric
operator|::
name|qNan
parameter_list|()
block|{
if|#
directive|if
name|defined
name|__FAST_MATH__
operator|&&
operator|(
name|__GNUC__
operator|*
literal|100
operator|+
name|__GNUC_MINOR__
operator|<
literal|404
operator|)
name|QSKIP
argument_list|(
literal|"Non-conformant fast math mode is enabled, cannot run test"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|double
name|nan
init|=
name|qQNaN
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
literal|0
operator|>
name|nan
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
literal|0
operator|<
name|nan
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|qIsNaN
argument_list|(
name|nan
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|qIsNaN
argument_list|(
name|nan
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|qIsNaN
argument_list|(
operator|-
name|nan
argument_list|)
argument_list|)
expr_stmt|;
name|double
name|inf
init|=
name|qInf
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|inf
operator|>
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|-
name|inf
operator|<
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|qIsInf
argument_list|(
name|inf
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|qIsInf
argument_list|(
operator|-
name|inf
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|qIsInf
argument_list|(
literal|2
operator|*
name|inf
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|1
operator|/
name|inf
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_CC_INTEL
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"ICC optimizes zero * anything to zero"
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVERIFY
argument_list|(
name|qIsNaN
argument_list|(
literal|0
operator|*
name|nan
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_CC_INTEL
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"ICC optimizes zero * anything to zero"
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVERIFY
argument_list|(
name|qIsNaN
argument_list|(
literal|0
operator|*
name|inf
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|qFuzzyCompare
argument_list|(
literal|1
operator|/
name|inf
argument_list|,
literal|0.0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|floatDistance_data
name|void
name|tst_QNumeric
operator|::
name|floatDistance_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|float
argument_list|>
argument_list|(
literal|"val1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|float
argument_list|>
argument_list|(
literal|"val2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|quint32
argument_list|>
argument_list|(
literal|"expectedDistance"
argument_list|)
expr_stmt|;
comment|// exponent: 8 bits
comment|// mantissa: 23 bits
specifier|const
name|quint32
name|number_of_denormals
init|=
operator|(
literal|1
operator|<<
literal|23
operator|)
operator|-
literal|1
decl_stmt|;
comment|// Set to 0 if denormals are not included
name|quint32
name|_0_to_1
init|=
name|quint32
argument_list|(
operator|(
literal|1
operator|<<
literal|23
operator|)
operator|*
literal|126
operator|+
literal|1
operator|+
name|number_of_denormals
argument_list|)
decl_stmt|;
comment|// We need +1 to include the 0
name|quint32
name|_1_to_2
init|=
name|quint32
argument_list|(
literal|1
operator|<<
literal|23
argument_list|)
decl_stmt|;
comment|// We don't need +1 because FLT_MAX has all bits set in the mantissa. (Thus mantissa
comment|// have not wrapped back to 0, which would be the case for 1 in _0_to_1
name|quint32
name|_0_to_FLT_MAX
init|=
name|quint32
argument_list|(
operator|(
literal|1
operator|<<
literal|23
operator|)
operator|*
literal|254
argument_list|)
operator|+
name|number_of_denormals
decl_stmt|;
name|quint32
name|_0_to_FLT_MIN
init|=
literal|1
operator|+
name|number_of_denormals
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[0,FLT_MIN]"
argument_list|)
operator|<<
literal|0.F
operator|<<
name|FLT_MIN
operator|<<
name|_0_to_FLT_MIN
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[0,FLT_MAX]"
argument_list|)
operator|<<
literal|0.F
operator|<<
name|FLT_MAX
operator|<<
name|_0_to_FLT_MAX
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[1,1.5]"
argument_list|)
operator|<<
literal|1.0F
operator|<<
literal|1.5F
operator|<<
name|quint32
argument_list|(
literal|1
operator|<<
literal|22
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[0,1]"
argument_list|)
operator|<<
literal|0.F
operator|<<
literal|1.0F
operator|<<
name|_0_to_1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[0.5,1]"
argument_list|)
operator|<<
literal|0.5F
operator|<<
literal|1.0F
operator|<<
name|quint32
argument_list|(
literal|1
operator|<<
literal|23
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[1,2]"
argument_list|)
operator|<<
literal|1.F
operator|<<
literal|2.0F
operator|<<
name|_1_to_2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[-1,+1]"
argument_list|)
operator|<<
operator|-
literal|1.F
operator|<<
operator|+
literal|1.0F
operator|<<
literal|2
operator|*
name|_0_to_1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[-1,0]"
argument_list|)
operator|<<
operator|-
literal|1.F
operator|<<
literal|0.0F
operator|<<
name|_0_to_1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[-1,FLT_MAX]"
argument_list|)
operator|<<
operator|-
literal|1.F
operator|<<
name|FLT_MAX
operator|<<
name|_0_to_1
operator|+
name|_0_to_FLT_MAX
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[-2,-1"
argument_list|)
operator|<<
operator|-
literal|2.F
operator|<<
operator|-
literal|1.F
operator|<<
name|_1_to_2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[-1,-2"
argument_list|)
operator|<<
operator|-
literal|1.F
operator|<<
operator|-
literal|2.F
operator|<<
name|_1_to_2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[FLT_MIN,FLT_MAX]"
argument_list|)
operator|<<
name|FLT_MIN
operator|<<
name|FLT_MAX
operator|<<
name|_0_to_FLT_MAX
operator|-
name|_0_to_FLT_MIN
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[-FLT_MAX,FLT_MAX]"
argument_list|)
operator|<<
operator|-
name|FLT_MAX
operator|<<
name|FLT_MAX
operator|<<
operator|(
literal|2
operator|*
name|_0_to_FLT_MAX
operator|)
expr_stmt|;
name|float
name|denormal
init|=
name|FLT_MIN
decl_stmt|;
name|denormal
operator|/=
literal|2.0F
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"denormal"
argument_list|)
operator|<<
literal|0.F
operator|<<
name|denormal
operator|<<
name|_0_to_FLT_MIN
operator|/
literal|2
expr_stmt|;
block|}
end_function
begin_function
DECL|function|floatDistance
name|void
name|tst_QNumeric
operator|::
name|floatDistance
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|float
argument_list|,
name|val1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|float
argument_list|,
name|val2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|quint32
argument_list|,
name|expectedDistance
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_QNX
name|QEXPECT_FAIL
argument_list|(
literal|"denormal"
argument_list|,
literal|"See QTBUG-37094"
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QCOMPARE
argument_list|(
name|qFloatDistance
argument_list|(
name|val1
argument_list|,
name|val2
argument_list|)
argument_list|,
name|expectedDistance
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|floatDistance_double_data
name|void
name|tst_QNumeric
operator|::
name|floatDistance_double_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|double
argument_list|>
argument_list|(
literal|"val1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|double
argument_list|>
argument_list|(
literal|"val2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|quint64
argument_list|>
argument_list|(
literal|"expectedDistance"
argument_list|)
expr_stmt|;
comment|// exponent: 11 bits
comment|// mantissa: 52 bits
specifier|const
name|quint64
name|number_of_denormals
init|=
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
literal|52
operator|)
operator|-
literal|1
decl_stmt|;
comment|// Set to 0 if denormals are not included
name|quint64
name|_0_to_1
init|=
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
literal|52
operator|)
operator|*
operator|(
operator|(
literal|1
operator|<<
operator|(
literal|11
operator|-
literal|1
operator|)
operator|)
operator|-
literal|2
operator|)
operator|+
literal|1
operator|+
name|number_of_denormals
decl_stmt|;
comment|// We need +1 to include the 0
name|quint64
name|_1_to_2
init|=
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
literal|52
decl_stmt|;
comment|// We don't need +1 because DBL_MAX has all bits set in the mantissa. (Thus mantissa
comment|// have not wrapped back to 0, which would be the case for 1 in _0_to_1
name|quint64
name|_0_to_DBL_MAX
init|=
name|quint64
argument_list|(
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
literal|52
operator|)
operator|*
operator|(
operator|(
literal|1
operator|<<
literal|11
operator|)
operator|-
literal|2
operator|)
argument_list|)
operator|+
name|number_of_denormals
decl_stmt|;
name|quint64
name|_0_to_DBL_MIN
init|=
literal|1
operator|+
name|number_of_denormals
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[0,DBL_MIN]"
argument_list|)
operator|<<
literal|0.0
operator|<<
name|DBL_MIN
operator|<<
name|_0_to_DBL_MIN
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[0,DBL_MAX]"
argument_list|)
operator|<<
literal|0.0
operator|<<
name|DBL_MAX
operator|<<
name|_0_to_DBL_MAX
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[1,1.5]"
argument_list|)
operator|<<
literal|1.0
operator|<<
literal|1.5
operator|<<
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
literal|51
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[0,1]"
argument_list|)
operator|<<
literal|0.0
operator|<<
literal|1.0
operator|<<
name|_0_to_1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[0.5,1]"
argument_list|)
operator|<<
literal|0.5
operator|<<
literal|1.0
operator|<<
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
literal|52
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[1,2]"
argument_list|)
operator|<<
literal|1.0
operator|<<
literal|2.0
operator|<<
name|_1_to_2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[-1,+1]"
argument_list|)
operator|<<
operator|-
literal|1.0
operator|<<
operator|+
literal|1.0
operator|<<
literal|2
operator|*
name|_0_to_1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[-1,0]"
argument_list|)
operator|<<
operator|-
literal|1.0
operator|<<
literal|0.0
operator|<<
name|_0_to_1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[-1,DBL_MAX]"
argument_list|)
operator|<<
operator|-
literal|1.0
operator|<<
name|DBL_MAX
operator|<<
name|_0_to_1
operator|+
name|_0_to_DBL_MAX
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[-2,-1"
argument_list|)
operator|<<
operator|-
literal|2.0
operator|<<
operator|-
literal|1.0
operator|<<
name|_1_to_2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[-1,-2"
argument_list|)
operator|<<
operator|-
literal|1.0
operator|<<
operator|-
literal|2.0
operator|<<
name|_1_to_2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[DBL_MIN,DBL_MAX]"
argument_list|)
operator|<<
name|DBL_MIN
operator|<<
name|DBL_MAX
operator|<<
name|_0_to_DBL_MAX
operator|-
name|_0_to_DBL_MIN
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"[-DBL_MAX,DBL_MAX]"
argument_list|)
operator|<<
operator|-
name|DBL_MAX
operator|<<
name|DBL_MAX
operator|<<
operator|(
literal|2
operator|*
name|_0_to_DBL_MAX
operator|)
expr_stmt|;
name|double
name|denormal
init|=
name|DBL_MIN
decl_stmt|;
name|denormal
operator|/=
literal|2.0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"denormal"
argument_list|)
operator|<<
literal|0.0
operator|<<
name|denormal
operator|<<
name|_0_to_DBL_MIN
operator|/
literal|2
expr_stmt|;
block|}
end_function
begin_function
DECL|function|floatDistance_double
name|void
name|tst_QNumeric
operator|::
name|floatDistance_double
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|double
argument_list|,
name|val1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|double
argument_list|,
name|val2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|quint64
argument_list|,
name|expectedDistance
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_QNX
name|QEXPECT_FAIL
argument_list|(
literal|"denormal"
argument_list|,
literal|"See QTBUG-37094"
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QCOMPARE
argument_list|(
name|qFloatDistance
argument_list|(
name|val1
argument_list|,
name|val2
argument_list|)
argument_list|,
name|expectedDistance
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QNumeric
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qnumeric.moc"
end_include
end_unit
