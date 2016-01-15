begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlayout.h"
end_include
begin_include
include|#
directive|include
file|"private/qlayoutengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qvector.h"
end_include
begin_include
include|#
directive|include
file|"qwidget.h"
end_include
begin_include
include|#
directive|include
file|<qvarlengtharray.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|//#define QLAYOUT_EXTRA_DEBUG
end_comment
begin_typedef
DECL|typedef|Fixed64
typedef|typedef
name|qint64
name|Fixed64
typedef|;
end_typedef
begin_function
DECL|function|toFixed
specifier|static
specifier|inline
name|Fixed64
name|toFixed
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
operator|(
name|Fixed64
operator|)
name|i
operator|*
literal|256
return|;
block|}
end_function
begin_function
DECL|function|fRound
specifier|static
specifier|inline
name|int
name|fRound
parameter_list|(
name|Fixed64
name|i
parameter_list|)
block|{
return|return
operator|(
name|i
operator|%
literal|256
operator|<
literal|128
operator|)
condition|?
name|i
operator|/
literal|256
else|:
literal|1
operator|+
name|i
operator|/
literal|256
return|;
block|}
end_function
begin_comment
comment|/*   This is the main workhorse of the QGridLayout. It portions out   available space to the chain's children.    The calculation is done in fixed point: "fixed" variables are   scaled by a factor of 256.    If the layout runs "backwards" (i.e. RightToLeft or Up) the layout   is computed mirror-reversed, and it's the caller's responsibility   do reverse the values before use.    chain contains input and output parameters describing the geometry.   count is the count of items in the chain; pos and space give the   interval (relative to parentWidget topLeft). */
end_comment
begin_function
DECL|function|qGeomCalc
name|void
name|qGeomCalc
parameter_list|(
name|QVector
argument_list|<
name|QLayoutStruct
argument_list|>
modifier|&
name|chain
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|count
parameter_list|,
name|int
name|pos
parameter_list|,
name|int
name|space
parameter_list|,
name|int
name|spacer
parameter_list|)
block|{
name|int
name|cHint
init|=
literal|0
decl_stmt|;
name|int
name|cMin
init|=
literal|0
decl_stmt|;
name|int
name|cMax
init|=
literal|0
decl_stmt|;
name|int
name|sumStretch
init|=
literal|0
decl_stmt|;
name|int
name|sumSpacing
init|=
literal|0
decl_stmt|;
name|int
name|expandingCount
init|=
literal|0
decl_stmt|;
name|bool
name|allEmptyNonstretch
init|=
literal|true
decl_stmt|;
name|int
name|pendingSpacing
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|spacerCount
init|=
literal|0
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
name|start
init|;
name|i
operator|<
name|start
operator|+
name|count
condition|;
name|i
operator|++
control|)
block|{
name|QLayoutStruct
modifier|*
name|data
init|=
operator|&
name|chain
index|[
name|i
index|]
decl_stmt|;
name|data
operator|->
name|done
operator|=
literal|false
expr_stmt|;
name|cHint
operator|+=
name|data
operator|->
name|smartSizeHint
argument_list|()
expr_stmt|;
name|cMin
operator|+=
name|data
operator|->
name|minimumSize
expr_stmt|;
name|cMax
operator|+=
name|data
operator|->
name|maximumSize
expr_stmt|;
name|sumStretch
operator|+=
name|data
operator|->
name|stretch
expr_stmt|;
if|if
condition|(
operator|!
name|data
operator|->
name|empty
condition|)
block|{
comment|/*                 Using pendingSpacing, we ensure that the spacing for the last                 (non-empty) item is ignored.             */
if|if
condition|(
name|pendingSpacing
operator|>=
literal|0
condition|)
block|{
name|sumSpacing
operator|+=
name|pendingSpacing
expr_stmt|;
operator|++
name|spacerCount
expr_stmt|;
block|}
name|pendingSpacing
operator|=
name|data
operator|->
name|effectiveSpacer
argument_list|(
name|spacer
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|data
operator|->
name|expansive
condition|)
name|expandingCount
operator|++
expr_stmt|;
name|allEmptyNonstretch
operator|=
name|allEmptyNonstretch
operator|&&
name|data
operator|->
name|empty
operator|&&
operator|!
name|data
operator|->
name|expansive
operator|&&
name|data
operator|->
name|stretch
operator|<=
literal|0
expr_stmt|;
block|}
name|int
name|extraspace
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|space
operator|<
name|cMin
operator|+
name|sumSpacing
condition|)
block|{
comment|/*           Less space than minimumSize; take from the biggest first         */
name|int
name|minSize
init|=
name|cMin
operator|+
name|sumSpacing
decl_stmt|;
comment|// shrink the spacers proportionally
if|if
condition|(
name|spacer
operator|>=
literal|0
condition|)
block|{
name|spacer
operator|=
name|minSize
operator|>
literal|0
condition|?
name|spacer
operator|*
name|space
operator|/
name|minSize
else|:
literal|0
expr_stmt|;
name|sumSpacing
operator|=
name|spacer
operator|*
name|spacerCount
expr_stmt|;
block|}
name|QVarLengthArray
argument_list|<
name|int
argument_list|,
literal|32
argument_list|>
name|minimumSizes
decl_stmt|;
name|minimumSizes
operator|.
name|reserve
argument_list|(
name|count
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|start
init|;
name|i
operator|<
name|start
operator|+
name|count
condition|;
name|i
operator|++
control|)
name|minimumSizes
operator|<<
name|chain
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|minimumSize
expr_stmt|;
name|std
operator|::
name|sort
argument_list|(
name|minimumSizes
operator|.
name|begin
argument_list|()
argument_list|,
name|minimumSizes
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|space_left
init|=
name|space
operator|-
name|sumSpacing
decl_stmt|;
name|int
name|sum
init|=
literal|0
decl_stmt|;
name|int
name|idx
init|=
literal|0
decl_stmt|;
name|int
name|space_used
init|=
literal|0
decl_stmt|;
name|int
name|current
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|idx
operator|<
name|count
operator|&&
name|space_used
operator|<
name|space_left
condition|)
block|{
name|current
operator|=
name|minimumSizes
operator|.
name|at
argument_list|(
name|idx
argument_list|)
expr_stmt|;
name|space_used
operator|=
name|sum
operator|+
name|current
operator|*
operator|(
name|count
operator|-
name|idx
operator|)
expr_stmt|;
name|sum
operator|+=
name|current
expr_stmt|;
operator|++
name|idx
expr_stmt|;
block|}
operator|--
name|idx
expr_stmt|;
name|int
name|deficit
init|=
name|space_used
operator|-
name|space_left
decl_stmt|;
name|int
name|items
init|=
name|count
operator|-
name|idx
decl_stmt|;
comment|/*          * If we truncate all items to "current", we would get "deficit" too many pixels. Therefore, we have to remove          * deficit/items from each item bigger than maxval. The actual value to remove is deficitPerItem + remainder/items          * "rest" is the accumulated error from using integer arithmetic.         */
name|int
name|deficitPerItem
init|=
name|deficit
operator|/
name|items
decl_stmt|;
name|int
name|remainder
init|=
name|deficit
operator|%
name|items
decl_stmt|;
name|int
name|maxval
init|=
name|current
operator|-
name|deficitPerItem
decl_stmt|;
name|int
name|rest
init|=
literal|0
decl_stmt|;
for|for
control|(
name|i
operator|=
name|start
init|;
name|i
operator|<
name|start
operator|+
name|count
condition|;
name|i
operator|++
control|)
block|{
name|int
name|maxv
init|=
name|maxval
decl_stmt|;
name|rest
operator|+=
name|remainder
expr_stmt|;
if|if
condition|(
name|rest
operator|>=
name|items
condition|)
block|{
name|maxv
operator|--
expr_stmt|;
name|rest
operator|-=
name|items
expr_stmt|;
block|}
name|QLayoutStruct
modifier|*
name|data
init|=
operator|&
name|chain
index|[
name|i
index|]
decl_stmt|;
name|data
operator|->
name|size
operator|=
name|qMin
argument_list|(
name|data
operator|->
name|minimumSize
argument_list|,
name|maxv
argument_list|)
expr_stmt|;
name|data
operator|->
name|done
operator|=
literal|true
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|space
operator|<
name|cHint
operator|+
name|sumSpacing
condition|)
block|{
comment|/*           Less space than smartSizeHint(), but more than minimumSize.           Currently take space equally from each, as in Qt 2.x.           Commented-out lines will give more space to stretchier           items.         */
name|int
name|n
init|=
name|count
decl_stmt|;
name|int
name|space_left
init|=
name|space
operator|-
name|sumSpacing
decl_stmt|;
name|int
name|overdraft
init|=
name|cHint
operator|-
name|space_left
decl_stmt|;
comment|// first give to the fixed ones:
for|for
control|(
name|i
operator|=
name|start
init|;
name|i
operator|<
name|start
operator|+
name|count
condition|;
name|i
operator|++
control|)
block|{
name|QLayoutStruct
modifier|*
name|data
init|=
operator|&
name|chain
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|data
operator|->
name|done
operator|&&
name|data
operator|->
name|minimumSize
operator|>=
name|data
operator|->
name|smartSizeHint
argument_list|()
condition|)
block|{
name|data
operator|->
name|size
operator|=
name|data
operator|->
name|smartSizeHint
argument_list|()
expr_stmt|;
name|data
operator|->
name|done
operator|=
literal|true
expr_stmt|;
name|space_left
operator|-=
name|data
operator|->
name|smartSizeHint
argument_list|()
expr_stmt|;
comment|// sumStretch -= data->stretch;
name|n
operator|--
expr_stmt|;
block|}
block|}
name|bool
name|finished
init|=
name|n
operator|==
literal|0
decl_stmt|;
while|while
condition|(
operator|!
name|finished
condition|)
block|{
name|finished
operator|=
literal|true
expr_stmt|;
name|Fixed64
name|fp_over
init|=
name|toFixed
argument_list|(
name|overdraft
argument_list|)
decl_stmt|;
name|Fixed64
name|fp_w
init|=
literal|0
decl_stmt|;
for|for
control|(
name|i
operator|=
name|start
init|;
name|i
operator|<
name|start
operator|+
name|count
condition|;
name|i
operator|++
control|)
block|{
name|QLayoutStruct
modifier|*
name|data
init|=
operator|&
name|chain
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|data
operator|->
name|done
condition|)
continue|continue;
comment|// if (sumStretch<= 0)
name|fp_w
operator|+=
name|fp_over
operator|/
name|n
expr_stmt|;
comment|// else
comment|//    fp_w += (fp_over * data->stretch) / sumStretch;
name|int
name|w
init|=
name|fRound
argument_list|(
name|fp_w
argument_list|)
decl_stmt|;
name|data
operator|->
name|size
operator|=
name|data
operator|->
name|smartSizeHint
argument_list|()
operator|-
name|w
expr_stmt|;
name|fp_w
operator|-=
name|toFixed
argument_list|(
name|w
argument_list|)
expr_stmt|;
comment|// give the difference to the next
if|if
condition|(
name|data
operator|->
name|size
operator|<
name|data
operator|->
name|minimumSize
condition|)
block|{
name|data
operator|->
name|done
operator|=
literal|true
expr_stmt|;
name|data
operator|->
name|size
operator|=
name|data
operator|->
name|minimumSize
expr_stmt|;
name|finished
operator|=
literal|false
expr_stmt|;
name|overdraft
operator|-=
name|data
operator|->
name|smartSizeHint
argument_list|()
operator|-
name|data
operator|->
name|minimumSize
expr_stmt|;
comment|// sumStretch -= data->stretch;
name|n
operator|--
expr_stmt|;
break|break;
block|}
block|}
block|}
block|}
else|else
block|{
comment|// extra space
name|int
name|n
init|=
name|count
decl_stmt|;
name|int
name|space_left
init|=
name|space
operator|-
name|sumSpacing
decl_stmt|;
comment|// first give to the fixed ones, and handle non-expansiveness
for|for
control|(
name|i
operator|=
name|start
init|;
name|i
operator|<
name|start
operator|+
name|count
condition|;
name|i
operator|++
control|)
block|{
name|QLayoutStruct
modifier|*
name|data
init|=
operator|&
name|chain
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|data
operator|->
name|done
operator|&&
operator|(
name|data
operator|->
name|maximumSize
operator|<=
name|data
operator|->
name|smartSizeHint
argument_list|()
operator|||
operator|(
operator|!
name|allEmptyNonstretch
operator|&&
name|data
operator|->
name|empty
operator|&&
operator|!
name|data
operator|->
name|expansive
operator|&&
name|data
operator|->
name|stretch
operator|==
literal|0
operator|)
operator|)
condition|)
block|{
name|data
operator|->
name|size
operator|=
name|data
operator|->
name|smartSizeHint
argument_list|()
expr_stmt|;
name|data
operator|->
name|done
operator|=
literal|true
expr_stmt|;
name|space_left
operator|-=
name|data
operator|->
name|size
expr_stmt|;
name|sumStretch
operator|-=
name|data
operator|->
name|stretch
expr_stmt|;
if|if
condition|(
name|data
operator|->
name|expansive
condition|)
name|expandingCount
operator|--
expr_stmt|;
name|n
operator|--
expr_stmt|;
block|}
block|}
name|extraspace
operator|=
name|space_left
expr_stmt|;
comment|/*           Do a trial distribution and calculate how much it is off.           If there are more deficit pixels than surplus pixels, give           the minimum size items what they need, and repeat.           Otherwise give to the maximum size items, and repeat.            Paul Olav Tvete has a wonderful mathematical proof of the           correctness of this principle, but unfortunately this           comment is too small to contain it.         */
name|int
name|surplus
decl_stmt|,
name|deficit
decl_stmt|;
do|do
block|{
name|surplus
operator|=
name|deficit
operator|=
literal|0
expr_stmt|;
name|Fixed64
name|fp_space
init|=
name|toFixed
argument_list|(
name|space_left
argument_list|)
decl_stmt|;
name|Fixed64
name|fp_w
init|=
literal|0
decl_stmt|;
for|for
control|(
name|i
operator|=
name|start
init|;
name|i
operator|<
name|start
operator|+
name|count
condition|;
name|i
operator|++
control|)
block|{
name|QLayoutStruct
modifier|*
name|data
init|=
operator|&
name|chain
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|data
operator|->
name|done
condition|)
continue|continue;
name|extraspace
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|sumStretch
operator|>
literal|0
condition|)
block|{
name|fp_w
operator|+=
operator|(
name|fp_space
operator|*
name|data
operator|->
name|stretch
operator|)
operator|/
name|sumStretch
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|expandingCount
operator|>
literal|0
condition|)
block|{
name|fp_w
operator|+=
operator|(
name|fp_space
operator|*
operator|(
name|data
operator|->
name|expansive
condition|?
literal|1
else|:
literal|0
operator|)
operator|)
operator|/
name|expandingCount
expr_stmt|;
block|}
else|else
block|{
name|fp_w
operator|+=
name|fp_space
operator|*
literal|1
operator|/
name|n
expr_stmt|;
block|}
name|int
name|w
init|=
name|fRound
argument_list|(
name|fp_w
argument_list|)
decl_stmt|;
name|data
operator|->
name|size
operator|=
name|w
expr_stmt|;
name|fp_w
operator|-=
name|toFixed
argument_list|(
name|w
argument_list|)
expr_stmt|;
comment|// give the difference to the next
if|if
condition|(
name|w
operator|<
name|data
operator|->
name|smartSizeHint
argument_list|()
condition|)
block|{
name|deficit
operator|+=
name|data
operator|->
name|smartSizeHint
argument_list|()
operator|-
name|w
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|w
operator|>
name|data
operator|->
name|maximumSize
condition|)
block|{
name|surplus
operator|+=
name|w
operator|-
name|data
operator|->
name|maximumSize
expr_stmt|;
block|}
block|}
if|if
condition|(
name|deficit
operator|>
literal|0
operator|&&
name|surplus
operator|<=
name|deficit
condition|)
block|{
comment|// give to the ones that have too little
for|for
control|(
name|i
operator|=
name|start
init|;
name|i
operator|<
name|start
operator|+
name|count
condition|;
name|i
operator|++
control|)
block|{
name|QLayoutStruct
modifier|*
name|data
init|=
operator|&
name|chain
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|data
operator|->
name|done
operator|&&
name|data
operator|->
name|size
operator|<
name|data
operator|->
name|smartSizeHint
argument_list|()
condition|)
block|{
name|data
operator|->
name|size
operator|=
name|data
operator|->
name|smartSizeHint
argument_list|()
expr_stmt|;
name|data
operator|->
name|done
operator|=
literal|true
expr_stmt|;
name|space_left
operator|-=
name|data
operator|->
name|smartSizeHint
argument_list|()
expr_stmt|;
name|sumStretch
operator|-=
name|data
operator|->
name|stretch
expr_stmt|;
if|if
condition|(
name|data
operator|->
name|expansive
condition|)
name|expandingCount
operator|--
expr_stmt|;
name|n
operator|--
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
name|surplus
operator|>
literal|0
operator|&&
name|surplus
operator|>=
name|deficit
condition|)
block|{
comment|// take from the ones that have too much
for|for
control|(
name|i
operator|=
name|start
init|;
name|i
operator|<
name|start
operator|+
name|count
condition|;
name|i
operator|++
control|)
block|{
name|QLayoutStruct
modifier|*
name|data
init|=
operator|&
name|chain
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|data
operator|->
name|done
operator|&&
name|data
operator|->
name|size
operator|>
name|data
operator|->
name|maximumSize
condition|)
block|{
name|data
operator|->
name|size
operator|=
name|data
operator|->
name|maximumSize
expr_stmt|;
name|data
operator|->
name|done
operator|=
literal|true
expr_stmt|;
name|space_left
operator|-=
name|data
operator|->
name|maximumSize
expr_stmt|;
name|sumStretch
operator|-=
name|data
operator|->
name|stretch
expr_stmt|;
if|if
condition|(
name|data
operator|->
name|expansive
condition|)
name|expandingCount
operator|--
expr_stmt|;
name|n
operator|--
expr_stmt|;
block|}
block|}
block|}
block|}
do|while
condition|(
name|n
operator|>
literal|0
operator|&&
name|surplus
operator|!=
name|deficit
condition|)
do|;
if|if
condition|(
name|n
operator|==
literal|0
condition|)
name|extraspace
operator|=
name|space_left
expr_stmt|;
block|}
comment|/*       As a last resort, we distribute the unwanted space equally       among the spacers (counting the start and end of the chain). We       could, but don't, attempt a sub-pixel allocation of the extra       space.     */
name|int
name|extra
init|=
name|extraspace
operator|/
operator|(
name|spacerCount
operator|+
literal|2
operator|)
decl_stmt|;
name|int
name|p
init|=
name|pos
operator|+
name|extra
decl_stmt|;
for|for
control|(
name|i
operator|=
name|start
init|;
name|i
operator|<
name|start
operator|+
name|count
condition|;
name|i
operator|++
control|)
block|{
name|QLayoutStruct
modifier|*
name|data
init|=
operator|&
name|chain
index|[
name|i
index|]
decl_stmt|;
name|data
operator|->
name|pos
operator|=
name|p
expr_stmt|;
name|p
operator|+=
name|data
operator|->
name|size
expr_stmt|;
if|if
condition|(
operator|!
name|data
operator|->
name|empty
condition|)
name|p
operator|+=
name|data
operator|->
name|effectiveSpacer
argument_list|(
name|spacer
argument_list|)
operator|+
name|extra
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|QLAYOUT_EXTRA_DEBUG
name|qDebug
argument_list|()
operator|<<
literal|"qGeomCalc"
operator|<<
literal|"start"
operator|<<
name|start
operator|<<
literal|"count"
operator|<<
name|count
operator|<<
literal|"pos"
operator|<<
name|pos
operator|<<
literal|"space"
operator|<<
name|space
operator|<<
literal|"spacer"
operator|<<
name|spacer
expr_stmt|;
for|for
control|(
name|i
operator|=
name|start
init|;
name|i
operator|<
name|start
operator|+
name|count
condition|;
operator|++
name|i
control|)
block|{
name|qDebug
argument_list|()
operator|<<
name|i
operator|<<
literal|':'
operator|<<
name|chain
index|[
name|i
index|]
operator|.
name|minimumSize
operator|<<
name|chain
index|[
name|i
index|]
operator|.
name|smartSizeHint
argument_list|()
operator|<<
name|chain
index|[
name|i
index|]
operator|.
name|maximumSize
operator|<<
literal|"stretch"
operator|<<
name|chain
index|[
name|i
index|]
operator|.
name|stretch
operator|<<
literal|"empty"
operator|<<
name|chain
index|[
name|i
index|]
operator|.
name|empty
operator|<<
literal|"expansive"
operator|<<
name|chain
index|[
name|i
index|]
operator|.
name|expansive
operator|<<
literal|"spacing"
operator|<<
name|chain
index|[
name|i
index|]
operator|.
name|spacing
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"result pos"
operator|<<
name|chain
index|[
name|i
index|]
operator|.
name|pos
operator|<<
literal|"size"
operator|<<
name|chain
index|[
name|i
index|]
operator|.
name|size
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|qSmartMinSize
name|Q_WIDGETS_EXPORT
name|QSize
name|qSmartMinSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|sizeHint
parameter_list|,
specifier|const
name|QSize
modifier|&
name|minSizeHint
parameter_list|,
specifier|const
name|QSize
modifier|&
name|minSize
parameter_list|,
specifier|const
name|QSize
modifier|&
name|maxSize
parameter_list|,
specifier|const
name|QSizePolicy
modifier|&
name|sizePolicy
parameter_list|)
block|{
name|QSize
name|s
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|sizePolicy
operator|.
name|horizontalPolicy
argument_list|()
operator|!=
name|QSizePolicy
operator|::
name|Ignored
condition|)
block|{
if|if
condition|(
name|sizePolicy
operator|.
name|horizontalPolicy
argument_list|()
operator|&
name|QSizePolicy
operator|::
name|ShrinkFlag
condition|)
name|s
operator|.
name|setWidth
argument_list|(
name|minSizeHint
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|s
operator|.
name|setWidth
argument_list|(
name|qMax
argument_list|(
name|sizeHint
operator|.
name|width
argument_list|()
argument_list|,
name|minSizeHint
operator|.
name|width
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|sizePolicy
operator|.
name|verticalPolicy
argument_list|()
operator|!=
name|QSizePolicy
operator|::
name|Ignored
condition|)
block|{
if|if
condition|(
name|sizePolicy
operator|.
name|verticalPolicy
argument_list|()
operator|&
name|QSizePolicy
operator|::
name|ShrinkFlag
condition|)
block|{
name|s
operator|.
name|setHeight
argument_list|(
name|minSizeHint
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|s
operator|.
name|setHeight
argument_list|(
name|qMax
argument_list|(
name|sizeHint
operator|.
name|height
argument_list|()
argument_list|,
name|minSizeHint
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|s
operator|=
name|s
operator|.
name|boundedTo
argument_list|(
name|maxSize
argument_list|)
expr_stmt|;
if|if
condition|(
name|minSize
operator|.
name|width
argument_list|()
operator|>
literal|0
condition|)
name|s
operator|.
name|setWidth
argument_list|(
name|minSize
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|minSize
operator|.
name|height
argument_list|()
operator|>
literal|0
condition|)
name|s
operator|.
name|setHeight
argument_list|(
name|minSize
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|s
operator|.
name|expandedTo
argument_list|(
name|QSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qSmartMinSize
name|Q_WIDGETS_EXPORT
name|QSize
name|qSmartMinSize
parameter_list|(
specifier|const
name|QWidgetItem
modifier|*
name|i
parameter_list|)
block|{
name|QWidget
modifier|*
name|w
init|=
cast|const_cast
argument_list|<
name|QWidgetItem
operator|*
argument_list|>
argument_list|(
name|i
argument_list|)
operator|->
name|widget
argument_list|()
decl_stmt|;
return|return
name|qSmartMinSize
argument_list|(
name|w
operator|->
name|sizeHint
argument_list|()
argument_list|,
name|w
operator|->
name|minimumSizeHint
argument_list|()
argument_list|,
name|w
operator|->
name|minimumSize
argument_list|()
argument_list|,
name|w
operator|->
name|maximumSize
argument_list|()
argument_list|,
name|w
operator|->
name|sizePolicy
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qSmartMinSize
name|Q_WIDGETS_EXPORT
name|QSize
name|qSmartMinSize
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|w
parameter_list|)
block|{
return|return
name|qSmartMinSize
argument_list|(
name|w
operator|->
name|sizeHint
argument_list|()
argument_list|,
name|w
operator|->
name|minimumSizeHint
argument_list|()
argument_list|,
name|w
operator|->
name|minimumSize
argument_list|()
argument_list|,
name|w
operator|->
name|maximumSize
argument_list|()
argument_list|,
name|w
operator|->
name|sizePolicy
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qSmartMaxSize
name|Q_WIDGETS_EXPORT
name|QSize
name|qSmartMaxSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|sizeHint
parameter_list|,
specifier|const
name|QSize
modifier|&
name|minSize
parameter_list|,
specifier|const
name|QSize
modifier|&
name|maxSize
parameter_list|,
specifier|const
name|QSizePolicy
modifier|&
name|sizePolicy
parameter_list|,
name|Qt
operator|::
name|Alignment
name|align
parameter_list|)
block|{
if|if
condition|(
name|align
operator|&
name|Qt
operator|::
name|AlignHorizontal_Mask
operator|&&
name|align
operator|&
name|Qt
operator|::
name|AlignVertical_Mask
condition|)
return|return
name|QSize
argument_list|(
name|QLAYOUTSIZE_MAX
argument_list|,
name|QLAYOUTSIZE_MAX
argument_list|)
return|;
name|QSize
name|s
init|=
name|maxSize
decl_stmt|;
name|QSize
name|hint
init|=
name|sizeHint
operator|.
name|expandedTo
argument_list|(
name|minSize
argument_list|)
decl_stmt|;
if|if
condition|(
name|s
operator|.
name|width
argument_list|()
operator|==
name|QWIDGETSIZE_MAX
operator|&&
operator|!
operator|(
name|align
operator|&
name|Qt
operator|::
name|AlignHorizontal_Mask
operator|)
condition|)
if|if
condition|(
operator|!
operator|(
name|sizePolicy
operator|.
name|horizontalPolicy
argument_list|()
operator|&
name|QSizePolicy
operator|::
name|GrowFlag
operator|)
condition|)
name|s
operator|.
name|setWidth
argument_list|(
name|hint
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|.
name|height
argument_list|()
operator|==
name|QWIDGETSIZE_MAX
operator|&&
operator|!
operator|(
name|align
operator|&
name|Qt
operator|::
name|AlignVertical_Mask
operator|)
condition|)
if|if
condition|(
operator|!
operator|(
name|sizePolicy
operator|.
name|verticalPolicy
argument_list|()
operator|&
name|QSizePolicy
operator|::
name|GrowFlag
operator|)
condition|)
name|s
operator|.
name|setHeight
argument_list|(
name|hint
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|align
operator|&
name|Qt
operator|::
name|AlignHorizontal_Mask
condition|)
name|s
operator|.
name|setWidth
argument_list|(
name|QLAYOUTSIZE_MAX
argument_list|)
expr_stmt|;
if|if
condition|(
name|align
operator|&
name|Qt
operator|::
name|AlignVertical_Mask
condition|)
name|s
operator|.
name|setHeight
argument_list|(
name|QLAYOUTSIZE_MAX
argument_list|)
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_function
DECL|function|qSmartMaxSize
name|Q_WIDGETS_EXPORT
name|QSize
name|qSmartMaxSize
parameter_list|(
specifier|const
name|QWidgetItem
modifier|*
name|i
parameter_list|,
name|Qt
operator|::
name|Alignment
name|align
parameter_list|)
block|{
name|QWidget
modifier|*
name|w
init|=
cast|const_cast
argument_list|<
name|QWidgetItem
operator|*
argument_list|>
argument_list|(
name|i
argument_list|)
operator|->
name|widget
argument_list|()
decl_stmt|;
return|return
name|qSmartMaxSize
argument_list|(
name|w
operator|->
name|sizeHint
argument_list|()
operator|.
name|expandedTo
argument_list|(
name|w
operator|->
name|minimumSizeHint
argument_list|()
argument_list|)
argument_list|,
name|w
operator|->
name|minimumSize
argument_list|()
argument_list|,
name|w
operator|->
name|maximumSize
argument_list|()
argument_list|,
name|w
operator|->
name|sizePolicy
argument_list|()
argument_list|,
name|align
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qSmartMaxSize
name|Q_WIDGETS_EXPORT
name|QSize
name|qSmartMaxSize
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|w
parameter_list|,
name|Qt
operator|::
name|Alignment
name|align
parameter_list|)
block|{
return|return
name|qSmartMaxSize
argument_list|(
name|w
operator|->
name|sizeHint
argument_list|()
operator|.
name|expandedTo
argument_list|(
name|w
operator|->
name|minimumSizeHint
argument_list|()
argument_list|)
argument_list|,
name|w
operator|->
name|minimumSize
argument_list|()
argument_list|,
name|w
operator|->
name|maximumSize
argument_list|()
argument_list|,
name|w
operator|->
name|sizePolicy
argument_list|()
argument_list|,
name|align
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qSmartSpacing
name|Q_WIDGETS_EXPORT
name|int
name|qSmartSpacing
parameter_list|(
specifier|const
name|QLayout
modifier|*
name|layout
parameter_list|,
name|QStyle
operator|::
name|PixelMetric
name|pm
parameter_list|)
block|{
name|QObject
modifier|*
name|parent
init|=
name|layout
operator|->
name|parent
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|parent
condition|)
block|{
return|return
operator|-
literal|1
return|;
block|}
elseif|else
if|if
condition|(
name|parent
operator|->
name|isWidgetType
argument_list|()
condition|)
block|{
name|QWidget
modifier|*
name|pw
init|=
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|)
decl_stmt|;
return|return
name|pw
operator|->
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|pm
argument_list|,
literal|0
argument_list|,
name|pw
argument_list|)
return|;
block|}
else|else
block|{
return|return
cast|static_cast
argument_list|<
name|QLayout
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|)
operator|->
name|spacing
argument_list|()
return|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
