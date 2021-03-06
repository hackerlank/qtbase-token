begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QElapsedTimer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QThread>
end_include
begin_include
include|#
directive|include
file|<private/qfreelist_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_QFreeList
class|class
name|tst_QFreeList
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|basicTest
parameter_list|()
function_decl|;
name|void
name|customized
parameter_list|()
function_decl|;
name|void
name|threadedTest
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|basicTest
name|void
name|tst_QFreeList
operator|::
name|basicTest
parameter_list|()
block|{
block|{
name|QFreeList
argument_list|<
name|void
argument_list|>
name|voidFreeList
decl_stmt|;
name|int
name|zero
init|=
name|voidFreeList
operator|.
name|next
argument_list|()
decl_stmt|;
name|int
name|one
init|=
name|voidFreeList
operator|.
name|next
argument_list|()
decl_stmt|;
name|int
name|two
init|=
name|voidFreeList
operator|.
name|next
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|zero
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|one
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|two
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|voidFreeList
index|[
name|zero
index|]
expr_stmt|;
name|voidFreeList
index|[
name|one
index|]
expr_stmt|;
name|voidFreeList
index|[
name|two
index|]
expr_stmt|;
name|voidFreeList
operator|.
name|at
argument_list|(
name|zero
argument_list|)
expr_stmt|;
name|voidFreeList
operator|.
name|at
argument_list|(
name|one
argument_list|)
expr_stmt|;
name|voidFreeList
operator|.
name|at
argument_list|(
name|two
argument_list|)
expr_stmt|;
name|voidFreeList
operator|.
name|release
argument_list|(
name|one
argument_list|)
expr_stmt|;
name|int
name|next
init|=
name|voidFreeList
operator|.
name|next
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|next
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|voidFreeList
index|[
name|next
index|]
expr_stmt|;
name|voidFreeList
operator|.
name|at
argument_list|(
name|next
argument_list|)
expr_stmt|;
block|}
block|{
name|QFreeList
argument_list|<
name|int
argument_list|>
name|intFreeList
decl_stmt|;
name|int
name|zero
init|=
name|intFreeList
operator|.
name|next
argument_list|()
decl_stmt|;
name|int
name|one
init|=
name|intFreeList
operator|.
name|next
argument_list|()
decl_stmt|;
name|int
name|two
init|=
name|intFreeList
operator|.
name|next
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|zero
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|one
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|two
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|intFreeList
index|[
name|zero
index|]
operator|=
name|zero
expr_stmt|;
name|intFreeList
index|[
name|one
index|]
operator|=
name|one
expr_stmt|;
name|intFreeList
index|[
name|two
index|]
operator|=
name|two
expr_stmt|;
name|QCOMPARE
argument_list|(
name|intFreeList
operator|.
name|at
argument_list|(
name|zero
argument_list|)
argument_list|,
name|zero
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|intFreeList
operator|.
name|at
argument_list|(
name|one
argument_list|)
argument_list|,
name|one
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|intFreeList
operator|.
name|at
argument_list|(
name|two
argument_list|)
argument_list|,
name|two
argument_list|)
expr_stmt|;
name|intFreeList
operator|.
name|release
argument_list|(
name|one
argument_list|)
expr_stmt|;
name|int
name|next
init|=
name|intFreeList
operator|.
name|next
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|next
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|intFreeList
operator|.
name|at
argument_list|(
name|next
argument_list|)
argument_list|,
name|one
argument_list|)
expr_stmt|;
name|intFreeList
index|[
name|next
index|]
operator|=
operator|-
name|one
expr_stmt|;
name|QCOMPARE
argument_list|(
name|intFreeList
operator|.
name|at
argument_list|(
name|next
argument_list|)
argument_list|,
operator|-
name|one
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_struct
DECL|struct|CustomFreeListConstants
struct|struct
name|CustomFreeListConstants
super|:
specifier|public
name|QFreeListDefaultConstants
block|{
enum|enum
block|{
DECL|enumerator|InitialNextValue
name|InitialNextValue
init|=
literal|50
block|,
DECL|enumerator|BlockCount
name|BlockCount
init|=
literal|10
block|}
enum|;
DECL|member|Sizes
specifier|static
specifier|const
name|int
name|Sizes
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|member|Sizes
specifier|const
name|int
name|CustomFreeListConstants
operator|::
name|Sizes
index|[
literal|10
index|]
init|=
block|{
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
block|,
literal|16777216
operator|-
literal|1
operator|-
literal|2
operator|-
literal|3
operator|-
literal|4
operator|-
literal|5
operator|-
literal|6
operator|-
literal|7
operator|-
literal|8
operator|-
literal|9
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|customized
name|void
name|tst_QFreeList
operator|::
name|customized
parameter_list|()
block|{
name|QFreeList
argument_list|<
name|void
argument_list|,
name|CustomFreeListConstants
argument_list|>
name|customFreeList
decl_stmt|;
name|int
name|next
init|=
name|customFreeList
operator|.
name|next
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|next
argument_list|,
name|int
argument_list|(
name|CustomFreeListConstants
operator|::
name|InitialNextValue
argument_list|)
argument_list|)
expr_stmt|;
name|customFreeList
index|[
name|next
index|]
expr_stmt|;
name|customFreeList
operator|.
name|at
argument_list|(
name|next
argument_list|)
expr_stmt|;
name|customFreeList
operator|.
name|release
argument_list|(
name|next
argument_list|)
expr_stmt|;
block|}
end_function
begin_enum
DECL|enumerator|TimeLimit
enum|enum
block|{
name|TimeLimit
init|=
literal|3000
block|}
enum|;
end_enum
begin_class
DECL|class|FreeListThread
class|class
name|FreeListThread
super|:
specifier|public
name|QThread
block|{
DECL|member|freelist
specifier|static
name|QFreeList
argument_list|<
name|void
argument_list|>
name|freelist
decl_stmt|;
public|public:
DECL|function|FreeListThread
specifier|inline
name|FreeListThread
parameter_list|()
member_init_list|:
name|QThread
argument_list|()
block|{ }
DECL|function|run
specifier|inline
name|void
name|run
parameter_list|()
block|{
name|QElapsedTimer
name|t
decl_stmt|;
name|t
operator|.
name|start
argument_list|()
expr_stmt|;
name|QList
argument_list|<
name|int
argument_list|>
name|needToRelease
decl_stmt|;
do|do
block|{
name|int
name|i
init|=
name|freelist
operator|.
name|next
argument_list|()
decl_stmt|;
name|int
name|j
init|=
name|freelist
operator|.
name|next
argument_list|()
decl_stmt|;
name|int
name|k
init|=
name|freelist
operator|.
name|next
argument_list|()
decl_stmt|;
name|int
name|l
init|=
name|freelist
operator|.
name|next
argument_list|()
decl_stmt|;
name|freelist
operator|.
name|release
argument_list|(
name|k
argument_list|)
expr_stmt|;
name|int
name|n
init|=
name|freelist
operator|.
name|next
argument_list|()
decl_stmt|;
name|int
name|m
init|=
name|freelist
operator|.
name|next
argument_list|()
decl_stmt|;
name|freelist
operator|.
name|release
argument_list|(
name|l
argument_list|)
expr_stmt|;
name|freelist
operator|.
name|release
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|freelist
operator|.
name|release
argument_list|(
name|n
argument_list|)
expr_stmt|;
name|freelist
operator|.
name|release
argument_list|(
name|j
argument_list|)
expr_stmt|;
comment|// freelist.release(i);
name|needToRelease
operator|<<
name|i
expr_stmt|;
block|}
do|while
condition|(
name|t
operator|.
name|elapsed
argument_list|()
operator|<
name|TimeLimit
condition|)
do|;
foreach|foreach
control|(
name|int
name|x
decl|,
name|needToRelease
control|)
name|freelist
operator|.
name|release
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_decl_stmt
DECL|member|freelist
name|QFreeList
argument_list|<
name|void
argument_list|>
name|FreeListThread
operator|::
name|freelist
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|threadedTest
name|void
name|tst_QFreeList
operator|::
name|threadedTest
parameter_list|()
block|{
specifier|const
name|int
name|ThreadCount
init|=
name|QThread
operator|::
name|idealThreadCount
argument_list|()
decl_stmt|;
name|FreeListThread
modifier|*
name|threads
init|=
operator|new
name|FreeListThread
index|[
name|ThreadCount
index|]
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
name|ThreadCount
condition|;
operator|++
name|i
control|)
name|threads
index|[
name|i
index|]
operator|.
name|start
argument_list|()
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
name|ThreadCount
condition|;
operator|++
name|i
control|)
name|threads
index|[
name|i
index|]
operator|.
name|wait
argument_list|()
expr_stmt|;
operator|delete
index|[]
name|threads
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QFreeList
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qfreelist.moc"
end_include
end_unit
