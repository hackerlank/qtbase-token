begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QSet>
end_include
begin_include
include|#
directive|include
file|<QTest>
end_include
begin_class
DECL|class|tst_QSet
class|class
name|tst_QSet
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|intersect_int_data
parameter_list|()
function_decl|;
name|void
name|intersect_int
parameter_list|()
function_decl|;
name|void
name|intersect_complexType_data
parameter_list|()
function_decl|;
name|void
name|intersect_complexType
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|intersect_int_data
name|void
name|tst_QSet
operator|::
name|intersect_int_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"lhsSize"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"rhsSize"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"intersectSize"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1000000.intersect(1000) = empty"
argument_list|)
operator|<<
literal|1000000
operator|<<
literal|1000
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1000.intersect(1000000) = empty"
argument_list|)
operator|<<
literal|1000
operator|<<
literal|1000000
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1000000.intersect(1000) = 500"
argument_list|)
operator|<<
literal|1000000
operator|<<
literal|1000
operator|<<
literal|500
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1000.intersect(1000000) = 500"
argument_list|)
operator|<<
literal|1000
operator|<<
literal|1000000
operator|<<
literal|500
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1000000.intersect(1000) = 1000"
argument_list|)
operator|<<
literal|1000000
operator|<<
literal|1000
operator|<<
literal|1000
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1000.intersect(1000000) = 1000"
argument_list|)
operator|<<
literal|1000
operator|<<
literal|1000000
operator|<<
literal|1000
expr_stmt|;
block|}
end_function
begin_function
DECL|function|intersect_int
name|void
name|tst_QSet
operator|::
name|intersect_int
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|lhsSize
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|rhsSize
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|intersectSize
argument_list|)
expr_stmt|;
comment|// E.g. when lhsSize = 1000, rhsSize = 1000000 and intersectSize = 500:
comment|// lhsSize = { 0, 1, ... 1000 }
comment|// rhsSize = { 500, 501, ... 1000500 }
name|QSet
argument_list|<
name|int
argument_list|>
name|lhs
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
name|lhsSize
condition|;
operator|++
name|i
control|)
name|lhs
operator|.
name|insert
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QSet
argument_list|<
name|int
argument_list|>
name|rhs
decl_stmt|;
specifier|const
name|int
name|start
init|=
name|lhsSize
operator|-
name|intersectSize
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|start
init|;
name|i
operator|<
name|start
operator|+
name|rhsSize
condition|;
operator|++
name|i
control|)
name|rhs
operator|.
name|insert
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|lhs
operator|.
name|intersect
argument_list|(
name|rhs
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|lhs
operator|.
name|size
argument_list|()
operator|==
name|intersectSize
argument_list|)
expr_stmt|;
block|}
end_function
begin_struct
DECL|struct|ComplexType
struct|struct
name|ComplexType
block|{
DECL|function|ComplexType
name|ComplexType
parameter_list|(
name|int
name|a
parameter_list|)
member_init_list|:
name|a
argument_list|(
name|a
argument_list|)
block|{}
DECL|member|a
name|int
name|a
decl_stmt|;
DECL|member|b
name|int
name|b
decl_stmt|;
DECL|member|c
name|int
name|c
decl_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|ComplexType
modifier|&
name|key
parameter_list|,
name|uint
name|seed
init|=
literal|0
parameter_list|)
block|{
return|return
name|uint
argument_list|(
name|key
operator|.
name|a
argument_list|)
operator|^
name|seed
return|;
block|}
end_function
begin_function
DECL|function|operator ==
specifier|inline
name|bool
name|operator
name|==
parameter_list|(
specifier|const
name|ComplexType
modifier|&
name|lhs
parameter_list|,
specifier|const
name|ComplexType
modifier|&
name|rhs
parameter_list|)
block|{
return|return
name|lhs
operator|.
name|a
operator|==
name|rhs
operator|.
name|a
return|;
block|}
end_function
begin_function
DECL|function|intersect_complexType_data
name|void
name|tst_QSet
operator|::
name|intersect_complexType_data
parameter_list|()
block|{
name|intersect_int_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|intersect_complexType
name|void
name|tst_QSet
operator|::
name|intersect_complexType
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|lhsSize
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|rhsSize
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|intersectSize
argument_list|)
expr_stmt|;
name|QSet
argument_list|<
name|ComplexType
argument_list|>
name|lhs
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
name|lhsSize
condition|;
operator|++
name|i
control|)
name|lhs
operator|.
name|insert
argument_list|(
name|ComplexType
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|QSet
argument_list|<
name|ComplexType
argument_list|>
name|rhs
decl_stmt|;
specifier|const
name|int
name|start
init|=
name|lhsSize
operator|-
name|intersectSize
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|start
init|;
name|i
operator|<
name|start
operator|+
name|rhsSize
condition|;
operator|++
name|i
control|)
name|rhs
operator|.
name|insert
argument_list|(
name|ComplexType
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|lhs
operator|.
name|intersect
argument_list|(
name|rhs
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSet
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit