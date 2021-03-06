begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QTest>
end_include
begin_decl_stmt
DECL|variable|N
specifier|static
specifier|const
name|int
name|N
init|=
literal|1000
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|MyBase
struct|struct
name|MyBase
block|{
DECL|function|MyBase
name|MyBase
parameter_list|(
name|int
name|i_
parameter_list|)
member_init_list|:
name|isCopy
argument_list|(
literal|false
argument_list|)
block|{
operator|++
name|liveCount
expr_stmt|;
name|i
operator|=
name|i_
expr_stmt|;
block|}
DECL|function|MyBase
name|MyBase
parameter_list|(
specifier|const
name|MyBase
modifier|&
name|other
parameter_list|)
member_init_list|:
name|isCopy
argument_list|(
literal|true
argument_list|)
block|{
if|if
condition|(
name|isCopy
condition|)
operator|++
name|copyCount
expr_stmt|;
operator|++
name|liveCount
expr_stmt|;
name|i
operator|=
name|other
operator|.
name|i
expr_stmt|;
block|}
DECL|function|operator =
name|MyBase
modifier|&
name|operator
name|=
parameter_list|(
specifier|const
name|MyBase
modifier|&
name|other
parameter_list|)
block|{
if|if
condition|(
operator|!
name|isCopy
condition|)
block|{
name|isCopy
operator|=
literal|true
expr_stmt|;
operator|++
name|copyCount
expr_stmt|;
block|}
else|else
block|{
operator|++
name|errorCount
expr_stmt|;
block|}
name|i
operator|=
name|other
operator|.
name|i
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
DECL|function|~MyBase
name|~
name|MyBase
parameter_list|()
block|{
if|if
condition|(
name|isCopy
condition|)
block|{
if|if
condition|(
operator|!
name|copyCount
condition|)
operator|++
name|errorCount
expr_stmt|;
else|else
operator|--
name|copyCount
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|liveCount
condition|)
operator|++
name|errorCount
expr_stmt|;
else|else
operator|--
name|liveCount
expr_stmt|;
block|}
DECL|function|operator ==
name|bool
name|operator
name|==
parameter_list|(
specifier|const
name|MyBase
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
name|i
operator|==
name|other
operator|.
name|i
return|;
block|}
protected|protected:
DECL|member|i
name|ushort
name|i
decl_stmt|;
DECL|member|isCopy
name|bool
name|isCopy
decl_stmt|;
public|public:
DECL|member|errorCount
specifier|static
name|int
name|errorCount
decl_stmt|;
DECL|member|liveCount
specifier|static
name|int
name|liveCount
decl_stmt|;
DECL|member|copyCount
specifier|static
name|int
name|copyCount
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|member|errorCount
name|int
name|MyBase
operator|::
name|errorCount
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|liveCount
name|int
name|MyBase
operator|::
name|liveCount
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|copyCount
name|int
name|MyBase
operator|::
name|copyCount
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|MyPrimitive
struct|struct
name|MyPrimitive
super|:
specifier|public
name|MyBase
block|{
DECL|function|MyPrimitive
name|MyPrimitive
parameter_list|(
name|int
name|i
init|=
operator|-
literal|1
parameter_list|)
member_init_list|:
name|MyBase
argument_list|(
name|i
argument_list|)
block|{
operator|++
name|errorCount
expr_stmt|;
block|}
DECL|function|MyPrimitive
name|MyPrimitive
parameter_list|(
specifier|const
name|MyPrimitive
modifier|&
name|other
parameter_list|)
member_init_list|:
name|MyBase
argument_list|(
name|other
argument_list|)
block|{
operator|++
name|errorCount
expr_stmt|;
block|}
DECL|function|~MyPrimitive
name|~
name|MyPrimitive
parameter_list|()
block|{
operator|++
name|errorCount
expr_stmt|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|MyMovable
struct|struct
name|MyMovable
super|:
specifier|public
name|MyBase
block|{
DECL|function|MyMovable
name|MyMovable
parameter_list|(
name|int
name|i
init|=
operator|-
literal|1
parameter_list|)
member_init_list|:
name|MyBase
argument_list|(
name|i
argument_list|)
block|{}
block|}
struct|;
end_struct
begin_struct
DECL|struct|MyComplex
struct|struct
name|MyComplex
super|:
specifier|public
name|MyBase
block|{
DECL|function|MyComplex
name|MyComplex
parameter_list|(
name|int
name|i
init|=
operator|-
literal|1
parameter_list|)
member_init_list|:
name|MyBase
argument_list|(
name|i
argument_list|)
block|{}
block|}
struct|;
end_struct
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_TYPEINFO
parameter_list|(
name|MyPrimitive
parameter_list|,
name|Q_PRIMITIVE_TYPE
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|MyMovable
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|MyComplex
argument_list|,
name|Q_COMPLEX_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_class
DECL|class|tst_QList
class|class
name|tst_QList
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|Q_SLOTS
private|:
name|void
name|removeAll_primitive_data
parameter_list|()
function_decl|;
name|void
name|removeAll_primitive
parameter_list|()
function_decl|;
name|void
name|removeAll_movable_data
parameter_list|()
function_decl|;
name|void
name|removeAll_movable
parameter_list|()
function_decl|;
name|void
name|removeAll_complex_data
parameter_list|()
function_decl|;
name|void
name|removeAll_complex
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
template|template
parameter_list|<
name|class
name|T
parameter_list|>
DECL|function|removeAll_test
name|void
name|removeAll_test
parameter_list|(
specifier|const
name|QList
argument_list|<
name|int
argument_list|>
modifier|&
name|i10
parameter_list|,
name|ushort
name|valueToRemove
parameter_list|,
name|int
name|itemsToRemove
parameter_list|)
block|{
name|bool
name|isComplex
init|=
name|QTypeInfo
argument_list|<
name|T
argument_list|>
operator|::
name|isComplex
decl_stmt|;
name|MyBase
operator|::
name|errorCount
operator|=
literal|0
expr_stmt|;
name|MyBase
operator|::
name|liveCount
operator|=
literal|0
expr_stmt|;
name|MyBase
operator|::
name|copyCount
operator|=
literal|0
expr_stmt|;
block|{
name|QList
argument_list|<
name|T
argument_list|>
name|list
decl_stmt|;
name|QCOMPARE
argument_list|(
name|MyBase
operator|::
name|liveCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|MyBase
operator|::
name|copyCount
argument_list|,
literal|0
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
literal|10
operator|*
name|N
condition|;
operator|++
name|i
control|)
block|{
name|T
name|t
argument_list|(
name|i10
operator|.
name|at
argument_list|(
name|i
operator|%
literal|10
argument_list|)
argument_list|)
decl_stmt|;
name|list
operator|.
name|append
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|MyBase
operator|::
name|liveCount
argument_list|,
name|isComplex
condition|?
name|list
operator|.
name|size
argument_list|()
else|:
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|MyBase
operator|::
name|copyCount
argument_list|,
name|isComplex
condition|?
name|list
operator|.
name|size
argument_list|()
else|:
literal|0
argument_list|)
expr_stmt|;
name|T
name|t
argument_list|(
name|valueToRemove
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|MyBase
operator|::
name|liveCount
argument_list|,
name|isComplex
condition|?
name|list
operator|.
name|size
argument_list|()
operator|+
literal|1
else|:
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|MyBase
operator|::
name|copyCount
argument_list|,
name|isComplex
condition|?
name|list
operator|.
name|size
argument_list|()
else|:
literal|0
argument_list|)
expr_stmt|;
name|int
name|removedCount
decl_stmt|;
name|QList
argument_list|<
name|T
argument_list|>
name|l
decl_stmt|;
name|QBENCHMARK
block|{
name|l
operator|=
name|list
expr_stmt|;
name|removedCount
operator|=
name|l
operator|.
name|removeAll
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|removedCount
argument_list|,
name|itemsToRemove
operator|*
name|N
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|l
operator|.
name|size
argument_list|()
operator|+
name|removedCount
argument_list|,
name|list
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|l
operator|.
name|contains
argument_list|(
name|valueToRemove
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|MyBase
operator|::
name|liveCount
argument_list|,
name|isComplex
condition|?
name|l
operator|.
name|isDetached
argument_list|()
condition|?
name|list
operator|.
name|size
argument_list|()
operator|+
name|l
operator|.
name|size
argument_list|()
operator|+
literal|1
else|:
name|list
operator|.
name|size
argument_list|()
operator|+
literal|1
else|:
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|MyBase
operator|::
name|copyCount
argument_list|,
name|isComplex
condition|?
name|l
operator|.
name|isDetached
argument_list|()
condition|?
name|list
operator|.
name|size
argument_list|()
operator|+
name|l
operator|.
name|size
argument_list|()
else|:
name|list
operator|.
name|size
argument_list|()
else|:
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|isComplex
condition|)
name|QCOMPARE
argument_list|(
name|MyBase
operator|::
name|errorCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeAll_primitive_data
name|void
name|tst_QList
operator|::
name|removeAll_primitive_data
parameter_list|()
block|{
name|qRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|int
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QList
argument_list|<
name|int
argument_list|>
argument_list|>
argument_list|(
literal|"i10"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"valueToRemove"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"itemsToRemove"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0%"
argument_list|)
operator|<<
operator|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|()
operator|<<
literal|0
operator|<<
literal|0
operator|<<
literal|0
operator|<<
literal|0
operator|<<
literal|0
operator|<<
literal|0
operator|<<
literal|0
operator|<<
literal|0
operator|<<
literal|0
operator|<<
literal|0
operator|)
operator|<<
literal|5
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10%"
argument_list|)
operator|<<
operator|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|()
operator|<<
literal|0
operator|<<
literal|0
operator|<<
literal|0
operator|<<
literal|0
operator|<<
literal|5
operator|<<
literal|0
operator|<<
literal|0
operator|<<
literal|0
operator|<<
literal|0
operator|<<
literal|0
operator|)
operator|<<
literal|5
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"90%"
argument_list|)
operator|<<
operator|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|()
operator|<<
literal|5
operator|<<
literal|5
operator|<<
literal|5
operator|<<
literal|5
operator|<<
literal|0
operator|<<
literal|5
operator|<<
literal|5
operator|<<
literal|5
operator|<<
literal|5
operator|<<
literal|5
operator|)
operator|<<
literal|5
operator|<<
literal|9
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"100%"
argument_list|)
operator|<<
operator|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|()
operator|<<
literal|5
operator|<<
literal|5
operator|<<
literal|5
operator|<<
literal|5
operator|<<
literal|5
operator|<<
literal|5
operator|<<
literal|5
operator|<<
literal|5
operator|<<
literal|5
operator|<<
literal|5
operator|)
operator|<<
literal|5
operator|<<
literal|10
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeAll_primitive
name|void
name|tst_QList
operator|::
name|removeAll_primitive
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|,
name|i10
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|valueToRemove
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|itemsToRemove
argument_list|)
expr_stmt|;
name|removeAll_test
argument_list|<
name|MyPrimitive
argument_list|>
argument_list|(
name|i10
argument_list|,
name|valueToRemove
argument_list|,
name|itemsToRemove
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeAll_movable_data
name|void
name|tst_QList
operator|::
name|removeAll_movable_data
parameter_list|()
block|{
name|removeAll_primitive_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeAll_movable
name|void
name|tst_QList
operator|::
name|removeAll_movable
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|,
name|i10
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|valueToRemove
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|itemsToRemove
argument_list|)
expr_stmt|;
name|removeAll_test
argument_list|<
name|MyMovable
argument_list|>
argument_list|(
name|i10
argument_list|,
name|valueToRemove
argument_list|,
name|itemsToRemove
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeAll_complex_data
name|void
name|tst_QList
operator|::
name|removeAll_complex_data
parameter_list|()
block|{
name|removeAll_primitive_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeAll_complex
name|void
name|tst_QList
operator|::
name|removeAll_complex
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|,
name|i10
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|valueToRemove
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|itemsToRemove
argument_list|)
expr_stmt|;
name|removeAll_test
argument_list|<
name|MyComplex
argument_list|>
argument_list|(
name|i10
argument_list|,
name|valueToRemove
argument_list|,
name|itemsToRemove
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QList
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
