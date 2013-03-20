begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the Android port of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_package
DECL|package|org.qtproject.qt5.android
package|package
name|org
operator|.
name|qtproject
operator|.
name|qt5
operator|.
name|android
package|;
end_package
begin_import
import|import
name|android
operator|.
name|content
operator|.
name|Context
import|;
end_import
begin_import
import|import
name|android
operator|.
name|util
operator|.
name|AttributeSet
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|View
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|ViewGroup
import|;
end_import
begin_class
DECL|class|QtLayout
specifier|public
class|class
name|QtLayout
extends|extends
name|ViewGroup
block|{
DECL|method|QtLayout
specifier|public
name|QtLayout
parameter_list|(
name|Context
name|context
parameter_list|)
block|{
name|super
argument_list|(
name|context
argument_list|)
expr_stmt|;
block|}
DECL|method|QtLayout
specifier|public
name|QtLayout
parameter_list|(
name|Context
name|context
parameter_list|,
name|AttributeSet
name|attrs
parameter_list|)
block|{
name|super
argument_list|(
name|context
argument_list|,
name|attrs
argument_list|)
expr_stmt|;
block|}
DECL|method|QtLayout
specifier|public
name|QtLayout
parameter_list|(
name|Context
name|context
parameter_list|,
name|AttributeSet
name|attrs
parameter_list|,
name|int
name|defStyle
parameter_list|)
block|{
name|super
argument_list|(
name|context
argument_list|,
name|attrs
argument_list|,
name|defStyle
argument_list|)
expr_stmt|;
block|}
annotation|@
name|Override
DECL|method|onMeasure
specifier|protected
name|void
name|onMeasure
parameter_list|(
name|int
name|widthMeasureSpec
parameter_list|,
name|int
name|heightMeasureSpec
parameter_list|)
block|{
name|int
name|count
init|=
name|getChildCount
argument_list|()
decl_stmt|;
name|int
name|maxHeight
init|=
literal|0
decl_stmt|;
name|int
name|maxWidth
init|=
literal|0
decl_stmt|;
comment|// Find out how big everyone wants to be
name|measureChildren
argument_list|(
name|widthMeasureSpec
argument_list|,
name|heightMeasureSpec
argument_list|)
expr_stmt|;
comment|// Find rightmost and bottom-most child
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
name|i
operator|++
control|)
block|{
name|View
name|child
init|=
name|getChildAt
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|child
operator|.
name|getVisibility
argument_list|()
operator|!=
name|GONE
condition|)
block|{
name|int
name|childRight
decl_stmt|;
name|int
name|childBottom
decl_stmt|;
name|QtLayout
operator|.
name|LayoutParams
name|lp
init|=
operator|(
name|QtLayout
operator|.
name|LayoutParams
operator|)
name|child
operator|.
name|getLayoutParams
argument_list|()
decl_stmt|;
name|childRight
operator|=
name|lp
operator|.
name|x
operator|+
name|child
operator|.
name|getMeasuredWidth
argument_list|()
expr_stmt|;
name|childBottom
operator|=
name|lp
operator|.
name|y
operator|+
name|child
operator|.
name|getMeasuredHeight
argument_list|()
expr_stmt|;
name|maxWidth
operator|=
name|Math
operator|.
name|max
argument_list|(
name|maxWidth
argument_list|,
name|childRight
argument_list|)
expr_stmt|;
name|maxHeight
operator|=
name|Math
operator|.
name|max
argument_list|(
name|maxHeight
argument_list|,
name|childBottom
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Check against minimum height and width
name|maxHeight
operator|=
name|Math
operator|.
name|max
argument_list|(
name|maxHeight
argument_list|,
name|getSuggestedMinimumHeight
argument_list|()
argument_list|)
expr_stmt|;
name|maxWidth
operator|=
name|Math
operator|.
name|max
argument_list|(
name|maxWidth
argument_list|,
name|getSuggestedMinimumWidth
argument_list|()
argument_list|)
expr_stmt|;
name|setMeasuredDimension
argument_list|(
name|resolveSize
argument_list|(
name|maxWidth
argument_list|,
name|widthMeasureSpec
argument_list|)
argument_list|,
name|resolveSize
argument_list|(
name|maxHeight
argument_list|,
name|heightMeasureSpec
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/**     * Returns a set of layout parameters with a width of     * {@link android.view.ViewGroup.LayoutParams#WRAP_CONTENT},     * a height of {@link android.view.ViewGroup.LayoutParams#WRAP_CONTENT}     * and with the coordinates (0, 0).     */
annotation|@
name|Override
DECL|method|generateDefaultLayoutParams
specifier|protected
name|ViewGroup
operator|.
name|LayoutParams
name|generateDefaultLayoutParams
parameter_list|()
block|{
return|return
operator|new
name|LayoutParams
argument_list|(
name|android
operator|.
name|view
operator|.
name|ViewGroup
operator|.
name|LayoutParams
operator|.
name|WRAP_CONTENT
argument_list|,
name|android
operator|.
name|view
operator|.
name|ViewGroup
operator|.
name|LayoutParams
operator|.
name|WRAP_CONTENT
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
annotation|@
name|Override
DECL|method|onLayout
specifier|protected
name|void
name|onLayout
parameter_list|(
name|boolean
name|changed
parameter_list|,
name|int
name|l
parameter_list|,
name|int
name|t
parameter_list|,
name|int
name|r
parameter_list|,
name|int
name|b
parameter_list|)
block|{
name|int
name|count
init|=
name|getChildCount
argument_list|()
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
name|count
condition|;
name|i
operator|++
control|)
block|{
name|View
name|child
init|=
name|getChildAt
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|child
operator|.
name|getVisibility
argument_list|()
operator|!=
name|GONE
condition|)
block|{
name|QtLayout
operator|.
name|LayoutParams
name|lp
init|=
operator|(
name|QtLayout
operator|.
name|LayoutParams
operator|)
name|child
operator|.
name|getLayoutParams
argument_list|()
decl_stmt|;
name|int
name|childLeft
init|=
name|lp
operator|.
name|x
decl_stmt|;
name|int
name|childTop
init|=
name|lp
operator|.
name|y
decl_stmt|;
name|child
operator|.
name|layout
argument_list|(
name|childLeft
argument_list|,
name|childTop
argument_list|,
name|childLeft
operator|+
name|child
operator|.
name|getMeasuredWidth
argument_list|()
argument_list|,
name|childTop
operator|+
name|child
operator|.
name|getMeasuredHeight
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|// Override to allow type-checking of LayoutParams.
annotation|@
name|Override
DECL|method|checkLayoutParams
specifier|protected
name|boolean
name|checkLayoutParams
parameter_list|(
name|ViewGroup
operator|.
name|LayoutParams
name|p
parameter_list|)
block|{
return|return
name|p
operator|instanceof
name|QtLayout
operator|.
name|LayoutParams
return|;
block|}
annotation|@
name|Override
DECL|method|generateLayoutParams
specifier|protected
name|ViewGroup
operator|.
name|LayoutParams
name|generateLayoutParams
parameter_list|(
name|ViewGroup
operator|.
name|LayoutParams
name|p
parameter_list|)
block|{
return|return
operator|new
name|LayoutParams
argument_list|(
name|p
argument_list|)
return|;
block|}
comment|/**     * Per-child layout information associated with AbsoluteLayout.     * See     * {@link android.R.styleable#AbsoluteLayout_Layout Absolute Layout Attributes}     * for a list of all child view attributes that this class supports.     */
DECL|class|LayoutParams
specifier|public
specifier|static
class|class
name|LayoutParams
extends|extends
name|ViewGroup
operator|.
name|LayoutParams
block|{
comment|/**         * The horizontal, or X, location of the child within the view group.         */
DECL|field|x
specifier|public
name|int
name|x
decl_stmt|;
comment|/**         * The vertical, or Y, location of the child within the view group.         */
DECL|field|y
specifier|public
name|int
name|y
decl_stmt|;
comment|/**         * Creates a new set of layout parameters with the specified width,         * height and location.         *         * @param width the width, either {@link #FILL_PARENT},                 {@link #WRAP_CONTENT} or a fixed size in pixels         * @param height the height, either {@link #FILL_PARENT},                 {@link #WRAP_CONTENT} or a fixed size in pixels         * @param x the X location of the child         * @param y the Y location of the child         */
DECL|method|LayoutParams
specifier|public
name|LayoutParams
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|super
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
name|this
operator|.
name|x
operator|=
name|x
expr_stmt|;
name|this
operator|.
name|y
operator|=
name|y
expr_stmt|;
block|}
comment|/**         * {@inheritDoc}         */
DECL|method|LayoutParams
specifier|public
name|LayoutParams
parameter_list|(
name|ViewGroup
operator|.
name|LayoutParams
name|source
parameter_list|)
block|{
name|super
argument_list|(
name|source
argument_list|)
expr_stmt|;
block|}
block|}
DECL|method|bringChildFront
specifier|public
name|void
name|bringChildFront
parameter_list|(
name|int
name|child
parameter_list|)
block|{
name|bringChildToFront
argument_list|(
name|getChildAt
argument_list|(
name|child
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_class
end_unit
