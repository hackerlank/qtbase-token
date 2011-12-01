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
file|<QtCore/qarraydata.h>
end_include
begin_class
DECL|class|tst_QArrayData
class|class
name|tst_QArrayData
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|referenceCounting
parameter_list|()
function_decl|;
name|void
name|sharedNullEmpty
parameter_list|()
function_decl|;
name|void
name|staticData
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|referenceCounting
name|void
name|tst_QArrayData
operator|::
name|referenceCounting
parameter_list|()
block|{
block|{
comment|// Reference counting initialized to 1 (owned)
name|QArrayData
name|array
init|=
block|{
name|Q_REFCOUNT_INITIALIZER
argument_list|(
literal|1
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|array
operator|.
name|ref
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|array
operator|.
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|array
operator|.
name|ref
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|array
operator|.
name|ref
operator|.
name|deref
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|array
operator|.
name|ref
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|array
operator|.
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|array
operator|.
name|ref
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|array
operator|.
name|ref
operator|.
name|deref
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|array
operator|.
name|ref
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|array
operator|.
name|ref
operator|.
name|deref
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|array
operator|.
name|ref
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// Now would be a good time to free/release allocated data
block|}
block|{
comment|// Reference counting initialized to -1 (static read-only data)
name|QArrayData
name|array
init|=
block|{
name|Q_REFCOUNT_INITIALIZER
argument_list|(
operator|-
literal|1
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|array
operator|.
name|ref
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|array
operator|.
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|array
operator|.
name|ref
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|array
operator|.
name|ref
operator|.
name|deref
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|array
operator|.
name|ref
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|sharedNullEmpty
name|void
name|tst_QArrayData
operator|::
name|sharedNullEmpty
parameter_list|()
block|{
name|QArrayData
modifier|*
name|null
init|=
cast|const_cast
argument_list|<
name|QArrayData
operator|*
argument_list|>
argument_list|(
operator|&
name|QArrayData
operator|::
name|shared_null
argument_list|)
decl_stmt|;
name|QArrayData
modifier|*
name|empty
init|=
cast|const_cast
argument_list|<
name|QArrayData
operator|*
argument_list|>
argument_list|(
operator|&
name|QArrayData
operator|::
name|shared_empty
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|null
operator|->
name|ref
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|empty
operator|->
name|ref
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|null
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
name|empty
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|null
operator|->
name|ref
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|empty
operator|->
name|ref
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|null
operator|->
name|ref
operator|.
name|deref
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|empty
operator|->
name|ref
operator|.
name|deref
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|null
operator|->
name|ref
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|empty
operator|->
name|ref
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|null
operator|!=
name|empty
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|null
operator|->
name|size
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|null
operator|->
name|alloc
argument_list|,
literal|0u
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|null
operator|->
name|capacityReserved
argument_list|,
literal|0u
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|empty
operator|->
name|size
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|empty
operator|->
name|alloc
argument_list|,
literal|0u
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|empty
operator|->
name|capacityReserved
argument_list|,
literal|0u
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|staticData
name|void
name|tst_QArrayData
operator|::
name|staticData
parameter_list|()
block|{
name|QStaticArrayData
argument_list|<
name|char
argument_list|,
literal|10
argument_list|>
name|charArray
init|=
block|{
name|Q_STATIC_ARRAY_DATA_HEADER_INITIALIZER
argument_list|(
name|char
argument_list|,
literal|10
argument_list|)
block|,
block|{
literal|'a'
block|,
literal|'b'
block|,
literal|'c'
block|,
literal|'d'
block|,
literal|'e'
block|,
literal|'f'
block|,
literal|'g'
block|,
literal|'h'
block|,
literal|'i'
block|,
literal|'j'
block|}
block|}
decl_stmt|;
name|QStaticArrayData
argument_list|<
name|int
argument_list|,
literal|10
argument_list|>
name|intArray
init|=
block|{
name|Q_STATIC_ARRAY_DATA_HEADER_INITIALIZER
argument_list|(
name|int
argument_list|,
literal|10
argument_list|)
block|,
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|}
block|}
decl_stmt|;
name|QStaticArrayData
argument_list|<
name|double
argument_list|,
literal|10
argument_list|>
name|doubleArray
init|=
block|{
name|Q_STATIC_ARRAY_DATA_HEADER_INITIALIZER
argument_list|(
name|double
argument_list|,
literal|10
argument_list|)
block|,
block|{
literal|0.f
block|,
literal|1.f
block|,
literal|2.f
block|,
literal|3.f
block|,
literal|4.f
block|,
literal|5.f
block|,
literal|6.f
block|,
literal|7.f
block|,
literal|8.f
block|,
literal|9.f
block|}
block|}
decl_stmt|;
name|QCOMPARE
argument_list|(
name|charArray
operator|.
name|header
operator|.
name|size
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|intArray
operator|.
name|header
operator|.
name|size
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|doubleArray
operator|.
name|header
operator|.
name|size
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|charArray
operator|.
name|header
operator|.
name|data
argument_list|()
argument_list|,
cast|reinterpret_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
operator|&
name|charArray
operator|.
name|data
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|intArray
operator|.
name|header
operator|.
name|data
argument_list|()
argument_list|,
cast|reinterpret_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
operator|&
name|intArray
operator|.
name|data
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|doubleArray
operator|.
name|header
operator|.
name|data
argument_list|()
argument_list|,
cast|reinterpret_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
operator|&
name|doubleArray
operator|.
name|data
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QArrayData
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qarraydata.moc"
end_include
end_unit
