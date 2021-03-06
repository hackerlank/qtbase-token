begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qgraphicsgridlayoutengine_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
end_ifndef
begin_include
include|#
directive|include
file|"qgraphicslayoutitem_p.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicslayout_p.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicswidget.h"
end_include
begin_include
include|#
directive|include
file|<private/qgraphicswidget_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|isHidden
name|bool
name|QGraphicsGridLayoutEngineItem
operator|::
name|isHidden
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|QGraphicsItem
modifier|*
name|item
init|=
name|q_layoutItem
operator|->
name|graphicsItem
argument_list|()
condition|)
return|return
name|QGraphicsItemPrivate
operator|::
name|get
argument_list|(
name|item
argument_list|)
operator|->
name|explicitlyHidden
return|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!   \internal    If this returns true, the layout will arrange just as if the item was never added to the layout.   (Note that this shouldn't lead to a "double spacing" where the item was hidden)   ### Qt6: Move to QGraphicsLayoutItem and make virtual */
end_comment
begin_function
DECL|function|isIgnored
name|bool
name|QGraphicsGridLayoutEngineItem
operator|::
name|isIgnored
parameter_list|()
specifier|const
block|{
return|return
name|isHidden
argument_list|()
operator|&&
operator|!
name|q_layoutItem
operator|->
name|sizePolicy
argument_list|()
operator|.
name|retainSizeWhenHidden
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*   returns \c true if the size policy returns \c true for either hasHeightForWidth()   or hasWidthForHeight()  */
end_comment
begin_function
DECL|function|hasDynamicConstraint
name|bool
name|QGraphicsGridLayoutEngineItem
operator|::
name|hasDynamicConstraint
parameter_list|()
specifier|const
block|{
return|return
name|QGraphicsLayoutItemPrivate
operator|::
name|get
argument_list|(
name|q_layoutItem
argument_list|)
operator|->
name|hasHeightForWidth
argument_list|()
operator|||
name|QGraphicsLayoutItemPrivate
operator|::
name|get
argument_list|(
name|q_layoutItem
argument_list|)
operator|->
name|hasWidthForHeight
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|dynamicConstraintOrientation
name|Qt
operator|::
name|Orientation
name|QGraphicsGridLayoutEngineItem
operator|::
name|dynamicConstraintOrientation
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|QGraphicsLayoutItemPrivate
operator|::
name|get
argument_list|(
name|q_layoutItem
argument_list|)
operator|->
name|hasHeightForWidth
argument_list|()
condition|)
return|return
name|Qt
operator|::
name|Vertical
return|;
else|else
comment|//if (QGraphicsLayoutItemPrivate::get(q_layoutItem)->hasWidthForHeight())
return|return
name|Qt
operator|::
name|Horizontal
return|;
block|}
end_function
begin_function
DECL|function|setAlignment
name|void
name|QGraphicsGridLayoutEngine
operator|::
name|setAlignment
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|graphicsLayoutItem
parameter_list|,
name|Qt
operator|::
name|Alignment
name|alignment
parameter_list|)
block|{
if|if
condition|(
name|QGraphicsGridLayoutEngineItem
modifier|*
name|gridEngineItem
init|=
name|findLayoutItem
argument_list|(
name|graphicsLayoutItem
argument_list|)
condition|)
block|{
name|gridEngineItem
operator|->
name|setAlignment
argument_list|(
name|alignment
argument_list|)
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|alignment
name|Qt
operator|::
name|Alignment
name|QGraphicsGridLayoutEngine
operator|::
name|alignment
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|graphicsLayoutItem
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|QGraphicsGridLayoutEngineItem
modifier|*
name|gridEngineItem
init|=
name|findLayoutItem
argument_list|(
name|graphicsLayoutItem
argument_list|)
condition|)
return|return
name|gridEngineItem
operator|->
name|alignment
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|setStretchFactor
name|void
name|QGraphicsGridLayoutEngine
operator|::
name|setStretchFactor
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|layoutItem
parameter_list|,
name|int
name|stretch
parameter_list|,
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|stretch
operator|>=
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|QGraphicsGridLayoutEngineItem
modifier|*
name|item
init|=
name|findLayoutItem
argument_list|(
name|layoutItem
argument_list|)
condition|)
name|item
operator|->
name|setStretchFactor
argument_list|(
name|stretch
argument_list|,
name|orientation
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stretchFactor
name|int
name|QGraphicsGridLayoutEngine
operator|::
name|stretchFactor
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|layoutItem
parameter_list|,
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|QGraphicsGridLayoutEngineItem
modifier|*
name|item
init|=
name|findLayoutItem
argument_list|(
name|layoutItem
argument_list|)
condition|)
return|return
name|item
operator|->
name|stretchFactor
argument_list|(
name|orientation
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_GRAPHICSVIEW
end_comment
end_unit
