begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qpropertyanimation.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qstyle.h>
end_include
begin_include
include|#
directive|include
file|<private/qmainwindowlayout_p.h>
end_include
begin_include
include|#
directive|include
file|"qwidgetanimator_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QWidgetAnimator
name|QWidgetAnimator
operator|::
name|QWidgetAnimator
parameter_list|(
name|QMainWindowLayout
modifier|*
name|layout
parameter_list|)
member_init_list|:
name|m_mainWindowLayout
argument_list|(
name|layout
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|abort
name|void
name|QWidgetAnimator
operator|::
name|abort
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
specifier|const
specifier|auto
name|it
init|=
name|m_animation_map
operator|.
name|constFind
argument_list|(
name|w
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|==
name|m_animation_map
operator|.
name|cend
argument_list|()
condition|)
return|return;
name|QPropertyAnimation
modifier|*
name|anim
init|=
operator|*
name|it
decl_stmt|;
name|m_animation_map
operator|.
name|erase
argument_list|(
name|it
argument_list|)
expr_stmt|;
if|if
condition|(
name|anim
condition|)
block|{
name|anim
operator|->
name|stop
argument_list|()
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_MAINWINDOW
name|m_mainWindowLayout
operator|->
name|animationFinished
argument_list|(
name|w
argument_list|)
expr_stmt|;
endif|#
directive|endif
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|w
argument_list|)
expr_stmt|;
comment|//there is no animation to abort
endif|#
directive|endif
comment|//QT_NO_ANIMATION
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
end_ifndef
begin_function
DECL|function|animationFinished
name|void
name|QWidgetAnimator
operator|::
name|animationFinished
parameter_list|()
block|{
name|QPropertyAnimation
modifier|*
name|anim
init|=
name|qobject_cast
argument_list|<
name|QPropertyAnimation
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
name|abort
argument_list|(
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|anim
operator|->
name|targetObject
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_ANIMATION
end_comment
begin_function
DECL|function|animate
name|void
name|QWidgetAnimator
operator|::
name|animate
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
specifier|const
name|QRect
modifier|&
name|_final_geometry
parameter_list|,
name|bool
name|animate
parameter_list|)
block|{
name|QRect
name|r
init|=
name|widget
operator|->
name|geometry
argument_list|()
decl_stmt|;
if|if
condition|(
name|r
operator|.
name|right
argument_list|()
operator|<
literal|0
operator|||
name|r
operator|.
name|bottom
argument_list|()
operator|<
literal|0
condition|)
name|r
operator|=
name|QRect
argument_list|()
expr_stmt|;
name|animate
operator|=
name|animate
operator|&&
operator|!
name|r
operator|.
name|isNull
argument_list|()
operator|&&
operator|!
name|_final_geometry
operator|.
name|isNull
argument_list|()
expr_stmt|;
comment|// might make the wigdet go away by sending it to negative space
specifier|const
name|QRect
name|final_geometry
init|=
name|_final_geometry
operator|.
name|isValid
argument_list|()
operator|||
name|widget
operator|->
name|isWindow
argument_list|()
condition|?
name|_final_geometry
else|:
name|QRect
argument_list|(
name|QPoint
argument_list|(
operator|-
literal|500
operator|-
name|widget
operator|->
name|width
argument_list|()
argument_list|,
operator|-
literal|500
operator|-
name|widget
operator|->
name|height
argument_list|()
argument_list|)
argument_list|,
name|widget
operator|->
name|size
argument_list|()
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
comment|//If the QStyle has animations, animate
if|if
condition|(
name|widget
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_Widget_Animate
argument_list|,
literal|0
argument_list|,
name|widget
argument_list|)
condition|)
block|{
name|AnimationMap
operator|::
name|const_iterator
name|it
init|=
name|m_animation_map
operator|.
name|constFind
argument_list|(
name|widget
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|!=
name|m_animation_map
operator|.
name|constEnd
argument_list|()
operator|&&
operator|(
operator|*
name|it
operator|)
operator|->
name|endValue
argument_list|()
operator|.
name|toRect
argument_list|()
operator|==
name|final_geometry
condition|)
return|return;
name|QPropertyAnimation
modifier|*
name|anim
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|widget
argument_list|,
literal|"geometry"
argument_list|,
name|widget
argument_list|)
decl_stmt|;
name|anim
operator|->
name|setDuration
argument_list|(
name|animate
condition|?
literal|200
else|:
literal|0
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|InOutQuad
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setEndValue
argument_list|(
name|final_geometry
argument_list|)
expr_stmt|;
name|m_animation_map
index|[
name|widget
index|]
operator|=
name|anim
expr_stmt|;
name|connect
argument_list|(
name|anim
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|animationFinished
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|anim
operator|->
name|start
argument_list|(
name|QPropertyAnimation
operator|::
name|DeleteWhenStopped
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
comment|//QT_NO_ANIMATION
block|{
comment|//we do it in one shot
name|widget
operator|->
name|setGeometry
argument_list|(
name|final_geometry
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_MAINWINDOW
name|m_mainWindowLayout
operator|->
name|animationFinished
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|//QT_NO_MAINWINDOW
block|}
block|}
end_function
begin_function
DECL|function|animating
name|bool
name|QWidgetAnimator
operator|::
name|animating
parameter_list|()
specifier|const
block|{
return|return
operator|!
name|m_animation_map
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qwidgetanimator_p.cpp"
end_include
end_unit
