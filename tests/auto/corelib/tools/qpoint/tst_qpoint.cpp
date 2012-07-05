begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qpoint.h>
end_include
begin_class
DECL|class|tst_QPoint
class|class
name|tst_QPoint
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|isNull
parameter_list|()
function_decl|;
name|void
name|manhattanLength_data
parameter_list|()
function_decl|;
name|void
name|manhattanLength
parameter_list|()
function_decl|;
name|void
name|getSet_data
parameter_list|()
function_decl|;
name|void
name|getSet
parameter_list|()
function_decl|;
name|void
name|rx
parameter_list|()
function_decl|;
name|void
name|ry
parameter_list|()
function_decl|;
name|void
name|operator_add_data
parameter_list|()
function_decl|;
name|void
name|operator_add
parameter_list|()
function_decl|;
name|void
name|operator_subtract_data
parameter_list|()
function_decl|;
name|void
name|operator_subtract
parameter_list|()
function_decl|;
name|void
name|operator_multiply_data
parameter_list|()
function_decl|;
name|void
name|operator_multiply
parameter_list|()
function_decl|;
name|void
name|operator_divide_data
parameter_list|()
function_decl|;
name|void
name|operator_divide
parameter_list|()
function_decl|;
name|void
name|operator_unary_minus_data
parameter_list|()
function_decl|;
name|void
name|operator_unary_minus
parameter_list|()
function_decl|;
name|void
name|operator_eq_data
parameter_list|()
function_decl|;
name|void
name|operator_eq
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|void
name|stream_data
parameter_list|()
function_decl|;
name|void
name|stream
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
class|;
end_class
begin_function
DECL|function|isNull
name|void
name|tst_QPoint
operator|::
name|isNull
parameter_list|()
block|{
name|QPoint
name|point
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|point
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
operator|++
name|point
operator|.
name|rx
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|point
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|point
operator|.
name|rx
argument_list|()
operator|-=
literal|2
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|point
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|manhattanLength_data
name|void
name|tst_QPoint
operator|::
name|manhattanLength_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPoint
argument_list|>
argument_list|(
literal|"point"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(0, 0)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(10, 0)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|10
argument_list|,
literal|0
argument_list|)
operator|<<
literal|10
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(0, 10)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|10
argument_list|)
operator|<<
literal|10
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(10, 20)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|)
operator|<<
literal|30
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(-10, -20)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|20
argument_list|)
operator|<<
literal|30
expr_stmt|;
block|}
end_function
begin_function
DECL|function|manhattanLength
name|void
name|tst_QPoint
operator|::
name|manhattanLength
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPoint
argument_list|,
name|point
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|point
operator|.
name|manhattanLength
argument_list|()
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getSet_data
name|void
name|tst_QPoint
operator|::
name|getSet_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"i"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0"
argument_list|)
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"INT_MIN"
argument_list|)
operator|<<
name|INT_MIN
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"INT_MAX"
argument_list|)
operator|<<
name|INT_MAX
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getSet
name|void
name|tst_QPoint
operator|::
name|getSet
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|QPoint
name|point
decl_stmt|;
name|point
operator|.
name|setX
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|point
operator|.
name|x
argument_list|()
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|point
operator|.
name|setY
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|point
operator|.
name|y
argument_list|()
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rx
name|void
name|tst_QPoint
operator|::
name|rx
parameter_list|()
block|{
specifier|const
name|QPoint
name|originalPoint
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QPoint
name|point
argument_list|(
name|originalPoint
argument_list|)
decl_stmt|;
operator|++
name|point
operator|.
name|rx
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|point
operator|.
name|x
argument_list|()
argument_list|,
name|originalPoint
operator|.
name|x
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|ry
name|void
name|tst_QPoint
operator|::
name|ry
parameter_list|()
block|{
specifier|const
name|QPoint
name|originalPoint
argument_list|(
literal|0
argument_list|,
operator|-
literal|1
argument_list|)
decl_stmt|;
name|QPoint
name|point
argument_list|(
name|originalPoint
argument_list|)
decl_stmt|;
operator|++
name|point
operator|.
name|ry
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|point
operator|.
name|y
argument_list|()
argument_list|,
name|originalPoint
operator|.
name|y
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator_add_data
name|void
name|tst_QPoint
operator|::
name|operator_add_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPoint
argument_list|>
argument_list|(
literal|"point1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPoint
argument_list|>
argument_list|(
literal|"point2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPoint
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(0, 0) + (0, 0)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(0, 9) + (1, 0)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|9
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|1
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(INT_MIN, 0) + (1, 0)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MIN
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MIN
operator|+
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(INT_MAX, 0) + (-1, 0)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MAX
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MAX
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator_add
name|void
name|tst_QPoint
operator|::
name|operator_add
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPoint
argument_list|,
name|point1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QPoint
argument_list|,
name|point2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QPoint
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|point1
operator|+
name|point2
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|point1
operator|+=
name|point2
expr_stmt|;
name|QCOMPARE
argument_list|(
name|point1
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator_subtract_data
name|void
name|tst_QPoint
operator|::
name|operator_subtract_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPoint
argument_list|>
argument_list|(
literal|"point1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPoint
argument_list|>
argument_list|(
literal|"point2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPoint
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(0, 0) - (0, 0)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(0, 9) - (1, 0)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|9
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(INT_MAX, 0) - (1, 0)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MAX
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MAX
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(INT_MIN, 0) - (-1, 0)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MIN
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MIN
operator|-
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator_subtract
name|void
name|tst_QPoint
operator|::
name|operator_subtract
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPoint
argument_list|,
name|point1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QPoint
argument_list|,
name|point2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QPoint
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|point1
operator|-
name|point2
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|point1
operator|-=
name|point2
expr_stmt|;
name|QCOMPARE
argument_list|(
name|point1
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_enum
DECL|enum|PrimitiveType
DECL|enumerator|Int
DECL|enumerator|Float
DECL|enumerator|Double
enum|enum
name|PrimitiveType
block|{
name|Int
block|,
name|Float
block|,
name|Double
block|}
enum|;
end_enum
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|PrimitiveType
argument_list|)
end_macro
begin_function
DECL|function|operator_multiply_data
name|void
name|tst_QPoint
operator|::
name|operator_multiply_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPoint
argument_list|>
argument_list|(
literal|"point"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|double
argument_list|>
argument_list|(
literal|"factorAsDouble"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|PrimitiveType
argument_list|>
argument_list|(
literal|"type"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPoint
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(0, 0) * 0.0"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
literal|0.0
operator|<<
name|Double
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(INT_MIN, 1) * 0.5"
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MIN
argument_list|,
literal|1
argument_list|)
operator|<<
literal|0.5
operator|<<
name|Double
operator|<<
name|QPoint
argument_list|(
name|qRound
argument_list|(
name|INT_MIN
operator|*
literal|0.5
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(INT_MAX, 2) * 0.5"
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MAX
argument_list|,
literal|2
argument_list|)
operator|<<
literal|0.5
operator|<<
name|Double
operator|<<
name|QPoint
argument_list|(
name|qRound
argument_list|(
name|INT_MAX
operator|*
literal|0.5
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(0, 0) * 0"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
literal|0.0
operator|<<
name|Int
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(INT_MIN + 1, 0) * -1"
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MIN
operator|+
literal|1
argument_list|,
literal|0
argument_list|)
operator|<<
operator|-
literal|1.0
operator|<<
name|Int
operator|<<
name|QPoint
argument_list|(
operator|(
name|INT_MIN
operator|+
literal|1
operator|)
operator|*
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(INT_MAX, 0) * -1"
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MAX
argument_list|,
literal|0
argument_list|)
operator|<<
operator|-
literal|1.0
operator|<<
name|Int
operator|<<
name|QPoint
argument_list|(
name|INT_MAX
operator|*
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(0, 0) * 0.0f"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
literal|0.0
operator|<<
name|Float
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(INT_MIN, 0) * -0.5f"
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MIN
argument_list|,
literal|0
argument_list|)
operator|<<
operator|-
literal|0.5
operator|<<
name|Float
operator|<<
name|QPoint
argument_list|(
name|qRound
argument_list|(
name|INT_MIN
operator|*
operator|-
literal|0.5f
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|multiplyTest
name|void
name|multiplyTest
parameter_list|(
name|QPoint
name|point
parameter_list|,
name|double
name|factor
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|expected
parameter_list|)
block|{
name|T
name|factorAsT
init|=
cast|static_cast
argument_list|<
name|T
argument_list|>
argument_list|(
name|factor
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|point
operator|*
name|factorAsT
argument_list|,
name|expected
argument_list|)
expr_stmt|;
comment|// Test with reversed argument version.
name|QCOMPARE
argument_list|(
name|factorAsT
operator|*
name|point
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|point
operator|*=
name|factorAsT
expr_stmt|;
name|QCOMPARE
argument_list|(
name|point
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator_multiply
name|void
name|tst_QPoint
operator|::
name|operator_multiply
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPoint
argument_list|,
name|point
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|double
argument_list|,
name|factorAsDouble
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|PrimitiveType
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QPoint
argument_list|,
name|expected
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|Int
condition|)
name|multiplyTest
argument_list|<
name|int
argument_list|>
argument_list|(
name|point
argument_list|,
name|factorAsDouble
argument_list|,
name|expected
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|type
operator|==
name|Float
condition|)
name|multiplyTest
argument_list|<
name|float
argument_list|>
argument_list|(
name|point
argument_list|,
name|factorAsDouble
argument_list|,
name|expected
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|type
operator|==
name|Double
condition|)
name|multiplyTest
argument_list|<
name|double
argument_list|>
argument_list|(
name|point
argument_list|,
name|factorAsDouble
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator_divide_data
name|void
name|tst_QPoint
operator|::
name|operator_divide_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPoint
argument_list|>
argument_list|(
literal|"point"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"divisor"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPoint
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(0, 0) / 1"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|qreal
argument_list|(
literal|1
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(0, 9) / 2"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|9
argument_list|)
operator|<<
name|qreal
argument_list|(
literal|2
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(INT_MAX, 0) / 2"
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MAX
argument_list|,
literal|0
argument_list|)
operator|<<
name|qreal
argument_list|(
literal|2
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|qRound
argument_list|(
name|INT_MAX
operator|/
name|qreal
argument_list|(
literal|2
argument_list|)
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(INT_MIN, 0) / -1.5"
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MIN
argument_list|,
literal|0
argument_list|)
operator|<<
name|qreal
argument_list|(
operator|-
literal|1.5
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|qRound
argument_list|(
name|INT_MIN
operator|/
name|qreal
argument_list|(
operator|-
literal|1.5
argument_list|)
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator_divide
name|void
name|tst_QPoint
operator|::
name|operator_divide
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPoint
argument_list|,
name|point
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|divisor
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QPoint
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|point
operator|/
name|divisor
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|point
operator|/=
name|divisor
expr_stmt|;
name|QCOMPARE
argument_list|(
name|point
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator_unary_minus_data
name|void
name|tst_QPoint
operator|::
name|operator_unary_minus_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPoint
argument_list|>
argument_list|(
literal|"point"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPoint
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"-(0, 0)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"-(-1, 0)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"-(0, -1)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
operator|-
literal|1
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"-(-INT_MAX, INT_MAX)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
operator|-
name|INT_MAX
argument_list|,
name|INT_MAX
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MAX
argument_list|,
operator|-
name|INT_MAX
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator_unary_minus
name|void
name|tst_QPoint
operator|::
name|operator_unary_minus
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPoint
argument_list|,
name|point
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QPoint
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|-
name|point
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator_eq_data
name|void
name|tst_QPoint
operator|::
name|operator_eq_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPoint
argument_list|>
argument_list|(
literal|"point1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPoint
argument_list|>
argument_list|(
literal|"point2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"expectEqual"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(0, 0) == (0, 0)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(-1, 0) == (-1, 0)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(-1, 0) != (0, 0)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(-1, 0) != (0, -1)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
operator|-
literal|1
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(1, 99999) != (-1, 99999)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|1
argument_list|,
literal|99999
argument_list|)
operator|<<
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
literal|99999
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(INT_MIN, INT_MIN) == (INT_MIN, INT_MIN)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MIN
argument_list|,
name|INT_MIN
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MIN
argument_list|,
name|INT_MIN
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(INT_MAX, INT_MAX) == (INT_MAX, INT_MAX)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MAX
argument_list|,
name|INT_MAX
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MAX
argument_list|,
name|INT_MAX
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator_eq
name|void
name|tst_QPoint
operator|::
name|operator_eq
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPoint
argument_list|,
name|point1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QPoint
argument_list|,
name|point2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|expectEqual
argument_list|)
expr_stmt|;
name|bool
name|equal
init|=
name|point1
operator|==
name|point2
decl_stmt|;
name|QCOMPARE
argument_list|(
name|equal
argument_list|,
name|expectEqual
argument_list|)
expr_stmt|;
name|bool
name|notEqual
init|=
name|point1
operator|!=
name|point2
decl_stmt|;
name|QCOMPARE
argument_list|(
name|notEqual
argument_list|,
operator|!
name|expectEqual
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_function
DECL|function|stream_data
name|void
name|tst_QPoint
operator|::
name|stream_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPoint
argument_list|>
argument_list|(
literal|"point"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(0, 0)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(-1, 1)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(1, -1)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"(INT_MIN, INT_MAX)"
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|INT_MIN
argument_list|,
name|INT_MAX
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stream
name|void
name|tst_QPoint
operator|::
name|stream
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPoint
argument_list|,
name|point
argument_list|)
expr_stmt|;
name|QBuffer
name|tmp
decl_stmt|;
name|QVERIFY
argument_list|(
name|tmp
operator|.
name|open
argument_list|(
name|QBuffer
operator|::
name|ReadWrite
argument_list|)
argument_list|)
expr_stmt|;
name|QDataStream
name|stream
argument_list|(
operator|&
name|tmp
argument_list|)
decl_stmt|;
comment|// Ensure that stream returned is the same stream we inserted into.
name|QDataStream
modifier|&
name|insertionStreamRef
argument_list|(
name|stream
operator|<<
name|point
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|&
name|insertionStreamRef
operator|==
operator|&
name|stream
argument_list|)
expr_stmt|;
name|tmp
operator|.
name|seek
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QPoint
name|pointFromStream
decl_stmt|;
name|QDataStream
modifier|&
name|extractionStreamRef
argument_list|(
name|stream
operator|>>
name|pointFromStream
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|&
name|extractionStreamRef
operator|==
operator|&
name|stream
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pointFromStream
argument_list|,
name|point
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QPoint
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qpoint.moc"
end_include
end_unit
