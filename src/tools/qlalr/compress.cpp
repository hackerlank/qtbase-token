begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"compress.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_include
include|#
directive|include
file|<iterator>
end_include
begin_include
include|#
directive|include
file|<iostream>
end_include
begin_define
DECL|macro|QLALR_NO_CHECK_SORTED_TABLE
define|#
directive|define
name|QLALR_NO_CHECK_SORTED_TABLE
end_define
begin_struct
DECL|struct|_Fit
struct|struct
name|_Fit
super|:
specifier|public
name|std
operator|::
name|binary_function
argument_list|<
name|int
argument_list|,
name|int
argument_list|,
name|bool
argument_list|>
block|{
DECL|function|operator ()
specifier|inline
name|bool
name|operator
name|()
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
specifier|const
block|{
return|return
name|a
operator|==
literal|0
operator|||
name|b
operator|==
literal|0
operator|||
name|a
operator|==
name|b
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|_PerfectMatch
struct|struct
name|_PerfectMatch
super|:
specifier|public
name|std
operator|::
name|binary_function
argument_list|<
name|int
argument_list|,
name|int
argument_list|,
name|bool
argument_list|>
block|{
DECL|function|operator ()
specifier|inline
name|bool
name|operator
name|()
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
specifier|const
block|{
return|return
name|a
operator|==
name|b
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|_GenerateCheck
struct|struct
name|_GenerateCheck
block|{
DECL|member|iterator
name|QVector
argument_list|<
name|int
argument_list|>
operator|::
name|const_iterator
name|iterator
decl_stmt|;
DECL|member|initial
name|int
name|initial
decl_stmt|;
DECL|function|_GenerateCheck
name|_GenerateCheck
parameter_list|(
name|QVector
argument_list|<
name|int
argument_list|>
operator|::
name|const_iterator
name|it
parameter_list|,
name|int
name|i
parameter_list|)
member_init_list|:
name|iterator
argument_list|(
name|it
argument_list|)
member_init_list|,
name|initial
argument_list|(
name|i
argument_list|)
block|{}
DECL|function|operator ()
specifier|inline
name|int
name|operator
name|()
parameter_list|()
block|{
name|int
name|check
init|=
name|initial
operator|++
decl_stmt|;
return|return
operator|*
name|iterator
operator|++
condition|?
name|check
else|:
operator|-
literal|1
return|;
block|}
block|}
struct|;
end_struct
begin_class
DECL|class|UncompressedRow
class|class
name|UncompressedRow
block|{
public|public:
DECL|typedef|const_iterator
typedef|typedef
specifier|const
name|int
modifier|*
name|const_iterator
typedef|;
DECL|typedef|iterator
typedef|typedef
specifier|const
name|int
modifier|*
name|iterator
typedef|;
public|public:
DECL|function|UncompressedRow
specifier|inline
name|UncompressedRow
parameter_list|()
member_init_list|:
name|_M_index
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|_M_begin
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|_M_end
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|_M_beginNonZeros
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|_M_endNonZeros
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|UncompressedRow
specifier|inline
name|UncompressedRow
parameter_list|(
name|int
name|index
parameter_list|,
name|const_iterator
name|begin
parameter_list|,
name|const_iterator
name|end
parameter_list|)
block|{
name|assign
argument_list|(
name|index
argument_list|,
name|begin
argument_list|,
name|end
argument_list|)
expr_stmt|;
block|}
DECL|function|index
specifier|inline
name|int
name|index
parameter_list|()
specifier|const
block|{
return|return
name|_M_index
return|;
block|}
DECL|function|begin
specifier|inline
name|const_iterator
name|begin
parameter_list|()
specifier|const
block|{
return|return
name|_M_begin
return|;
block|}
DECL|function|end
specifier|inline
name|const_iterator
name|end
parameter_list|()
specifier|const
block|{
return|return
name|_M_end
return|;
block|}
DECL|function|assign
specifier|inline
name|void
name|assign
parameter_list|(
name|int
name|index
parameter_list|,
name|const_iterator
name|begin
parameter_list|,
name|const_iterator
name|end
parameter_list|)
block|{
name|_M_index
operator|=
name|index
expr_stmt|;
name|_M_begin
operator|=
name|begin
expr_stmt|;
name|_M_end
operator|=
name|end
expr_stmt|;
name|_M_beginNonZeros
operator|=
name|_M_begin
expr_stmt|;
name|_M_endNonZeros
operator|=
name|_M_end
expr_stmt|;
for|for
control|(
name|_M_beginNonZeros
operator|=
name|_M_begin
init|;
name|_M_beginNonZeros
operator|!=
name|_M_end
operator|&&
operator|!
name|_M_beginNonZeros
index|[
literal|0
index|]
condition|;
operator|++
name|_M_beginNonZeros
control|)
comment|/*continue*/
empty_stmt|;
if|#
directive|if
literal|0
block|for (_M_endNonZeros = _M_end; _M_endNonZeros != _M_beginNonZeros&& ! _M_endNonZeros [-1]; --_M_endNonZeros)
comment|/*continue*/
block|;
endif|#
directive|endif
block|}
DECL|function|at
specifier|inline
name|int
name|at
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
return|return
name|_M_begin
index|[
name|index
index|]
return|;
block|}
DECL|function|isEmpty
specifier|inline
name|bool
name|isEmpty
parameter_list|()
specifier|const
block|{
return|return
name|_M_begin
operator|==
name|_M_end
return|;
block|}
DECL|function|size
specifier|inline
name|int
name|size
parameter_list|()
specifier|const
block|{
return|return
name|_M_end
operator|-
name|_M_begin
return|;
block|}
DECL|function|nonZeroElements
specifier|inline
name|int
name|nonZeroElements
parameter_list|()
specifier|const
block|{
return|return
name|_M_endNonZeros
operator|-
name|_M_beginNonZeros
return|;
block|}
DECL|function|count
specifier|inline
name|int
name|count
parameter_list|(
name|int
name|value
parameter_list|)
specifier|const
block|{
return|return
name|std
operator|::
name|count
argument_list|(
name|begin
argument_list|()
argument_list|,
name|end
argument_list|()
argument_list|,
name|value
argument_list|)
return|;
block|}
DECL|function|beginNonZeros
specifier|inline
name|const_iterator
name|beginNonZeros
parameter_list|()
specifier|const
block|{
return|return
name|_M_beginNonZeros
return|;
block|}
DECL|function|endNonZeros
specifier|inline
name|const_iterator
name|endNonZeros
parameter_list|()
specifier|const
block|{
return|return
name|_M_endNonZeros
return|;
block|}
private|private:
DECL|member|_M_index
name|int
name|_M_index
decl_stmt|;
DECL|member|_M_begin
name|const_iterator
name|_M_begin
decl_stmt|;
DECL|member|_M_end
name|const_iterator
name|_M_end
decl_stmt|;
DECL|member|_M_beginNonZeros
name|const_iterator
name|_M_beginNonZeros
decl_stmt|;
DECL|member|_M_endNonZeros
name|const_iterator
name|_M_endNonZeros
decl_stmt|;
block|}
class|;
end_class
begin_struct
DECL|struct|_SortUncompressedRow
struct|struct
name|_SortUncompressedRow
super|:
specifier|public
name|std
operator|::
name|binary_function
argument_list|<
name|UncompressedRow
argument_list|,
name|UncompressedRow
argument_list|,
name|bool
argument_list|>
block|{
DECL|function|operator ()
specifier|inline
name|bool
name|operator
name|()
parameter_list|(
specifier|const
name|UncompressedRow
modifier|&
name|a
parameter_list|,
specifier|const
name|UncompressedRow
modifier|&
name|b
parameter_list|)
specifier|const
block|{
return|return
name|a
operator|.
name|count
argument_list|(
literal|0
argument_list|)
operator|>
name|b
operator|.
name|count
argument_list|(
literal|0
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_constructor
DECL|function|Compress
name|Compress
operator|::
name|Compress
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|operator ()
name|void
name|Compress
operator|::
name|operator
name|()
parameter_list|(
name|int
modifier|*
name|table
parameter_list|,
name|int
name|row_count
parameter_list|,
name|int
name|column_count
parameter_list|)
block|{
name|index
operator|.
name|clear
argument_list|()
expr_stmt|;
name|info
operator|.
name|clear
argument_list|()
expr_stmt|;
name|check
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QVector
argument_list|<
name|UncompressedRow
argument_list|>
name|sortedTable
argument_list|(
name|row_count
argument_list|)
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
name|row_count
condition|;
operator|++
name|i
control|)
block|{
name|int
modifier|*
name|begin
init|=
operator|&
name|table
index|[
name|i
operator|*
name|column_count
index|]
decl_stmt|;
name|int
modifier|*
name|end
init|=
name|begin
operator|+
name|column_count
decl_stmt|;
name|sortedTable
index|[
name|i
index|]
operator|.
name|assign
argument_list|(
name|i
argument_list|,
name|begin
argument_list|,
name|end
argument_list|)
expr_stmt|;
block|}
name|std
operator|::
name|sort
argument_list|(
name|sortedTable
operator|.
name|begin
argument_list|()
argument_list|,
name|sortedTable
operator|.
name|end
argument_list|()
argument_list|,
name|_SortUncompressedRow
argument_list|()
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QLALR_NO_CHECK_SORTED_TABLE
name|int
name|previous_zeros
init|=
name|INT_MAX
decl_stmt|;
for|for
control|(
specifier|const
name|UncompressedRow
modifier|&
name|row
range|:
name|qAsConst
argument_list|(
name|sortedTable
argument_list|)
control|)
block|{
name|int
name|zeros
init|=
name|row
operator|.
name|count
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|zeros
operator|<=
name|previous_zeros
argument_list|)
expr_stmt|;
name|zeros
operator|=
name|previous_zeros
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"OK!"
expr_stmt|;
block|}
endif|#
directive|endif
name|index
operator|.
name|fill
argument_list|(
operator|-
literal|999999
argument_list|,
name|row_count
argument_list|)
expr_stmt|;
for|for
control|(
specifier|const
name|UncompressedRow
modifier|&
name|row
range|:
name|qAsConst
argument_list|(
name|sortedTable
argument_list|)
control|)
block|{
name|int
name|first_token
init|=
name|std
operator|::
name|distance
argument_list|(
name|row
operator|.
name|begin
argument_list|()
argument_list|,
name|row
operator|.
name|beginNonZeros
argument_list|()
argument_list|)
decl_stmt|;
name|QVector
argument_list|<
name|int
argument_list|>
operator|::
name|iterator
name|pos
init|=
name|info
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|pos
operator|!=
name|info
operator|.
name|end
argument_list|()
condition|)
block|{
if|if
condition|(
name|pos
operator|==
name|info
operator|.
name|begin
argument_list|()
condition|)
block|{
comment|// try to find a perfect match
name|QVector
argument_list|<
name|int
argument_list|>
operator|::
name|iterator
name|pm
init|=
name|std
operator|::
name|search
argument_list|(
name|pos
argument_list|,
name|info
operator|.
name|end
argument_list|()
argument_list|,
name|row
operator|.
name|beginNonZeros
argument_list|()
argument_list|,
name|row
operator|.
name|endNonZeros
argument_list|()
argument_list|,
name|_PerfectMatch
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|pm
operator|!=
name|info
operator|.
name|end
argument_list|()
condition|)
block|{
name|pos
operator|=
name|pm
expr_stmt|;
break|break;
block|}
block|}
name|pos
operator|=
name|std
operator|::
name|search
argument_list|(
name|pos
argument_list|,
name|info
operator|.
name|end
argument_list|()
argument_list|,
name|row
operator|.
name|beginNonZeros
argument_list|()
argument_list|,
name|row
operator|.
name|endNonZeros
argument_list|()
argument_list|,
name|_Fit
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|pos
operator|==
name|info
operator|.
name|end
argument_list|()
condition|)
break|break;
name|int
name|idx
init|=
name|std
operator|::
name|distance
argument_list|(
name|info
operator|.
name|begin
argument_list|()
argument_list|,
name|pos
argument_list|)
operator|-
name|first_token
decl_stmt|;
name|bool
name|conflict
init|=
literal|false
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
operator|!
name|conflict
operator|&&
name|j
operator|<
name|row
operator|.
name|size
argument_list|()
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
name|row
operator|.
name|at
argument_list|(
name|j
argument_list|)
operator|==
literal|0
condition|)
name|conflict
operator||=
name|idx
operator|+
name|j
operator|>=
literal|0
operator|&&
name|check
index|[
name|idx
operator|+
name|j
index|]
operator|==
name|j
expr_stmt|;
else|else
name|conflict
operator||=
name|check
index|[
name|idx
operator|+
name|j
index|]
operator|==
name|j
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|conflict
condition|)
break|break;
operator|++
name|pos
expr_stmt|;
block|}
if|if
condition|(
name|pos
operator|==
name|info
operator|.
name|end
argument_list|()
condition|)
block|{
name|int
name|size
init|=
name|info
operator|.
name|size
argument_list|()
decl_stmt|;
name|info
operator|.
name|resize
argument_list|(
name|info
operator|.
name|size
argument_list|()
operator|+
name|row
operator|.
name|nonZeroElements
argument_list|()
argument_list|)
expr_stmt|;
name|check
operator|.
name|resize
argument_list|(
name|info
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|std
operator|::
name|fill
argument_list|(
name|check
operator|.
name|begin
argument_list|()
operator|+
name|size
argument_list|,
name|check
operator|.
name|end
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|pos
operator|=
name|info
operator|.
name|begin
argument_list|()
operator|+
name|size
expr_stmt|;
block|}
name|int
name|offset
init|=
name|std
operator|::
name|distance
argument_list|(
name|info
operator|.
name|begin
argument_list|()
argument_list|,
name|pos
argument_list|)
decl_stmt|;
name|index
index|[
name|row
operator|.
name|index
argument_list|()
index|]
operator|=
name|offset
operator|-
name|first_token
expr_stmt|;
for|for
control|(
specifier|const
name|int
modifier|*
name|it
init|=
name|row
operator|.
name|beginNonZeros
argument_list|()
init|;
name|it
operator|!=
name|row
operator|.
name|endNonZeros
argument_list|()
condition|;
operator|++
name|it
operator|,
operator|++
name|pos
control|)
block|{
if|if
condition|(
operator|*
name|it
condition|)
operator|*
name|pos
operator|=
operator|*
name|it
expr_stmt|;
block|}
name|int
name|i
init|=
name|row
operator|.
name|index
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|row
operator|.
name|size
argument_list|()
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
name|row
operator|.
name|at
argument_list|(
name|j
argument_list|)
operator|==
literal|0
condition|)
continue|continue;
name|check
index|[
name|index
index|[
name|i
index|]
operator|+
name|j
index|]
operator|=
name|j
expr_stmt|;
block|}
block|}
if|#
directive|if
literal|0
block|for (const UncompressedRow&row : qAsConst(sortedTable))     {       int i = row.index ();       Q_ASSERT (i< sortedTable.size ());        for (int j = 0; j< row.size (); ++j)         {           if (row.at (j) == 0)             {               Q_ASSERT (index [i] + j< 0 || check [index [i] + j] != j);               continue;             }            Q_ASSERT ( info [index [i] + j] == row.at (j));           Q_ASSERT (check [index [i] + j] == j);         }     }
endif|#
directive|endif
block|}
end_function
end_unit
