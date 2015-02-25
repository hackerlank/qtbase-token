begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     \class QParallelAnimationGroup     \inmodule QtCore     \brief The QParallelAnimationGroup class provides a parallel group of animations.     \since 4.6     \ingroup animation      QParallelAnimationGroup--a \l{QAnimationGroup}{container for     animations}--starts all its animations when it is     \l{QAbstractAnimation::start()}{started} itself, i.e., runs all     animations in parallel. The animation group finishes when the     longest lasting animation has finished.      You can treat QParallelAnimationGroup as any other QAbstractAnimation,     e.g., pause, resume, or add it to other animation groups.      \code         QParallelAnimationGroup *group = new QParallelAnimationGroup;         group->addAnimation(anim1);         group->addAnimation(anim2);          group->start();     \endcode      In this example, \c anim1 and \c anim2 are two     \l{QPropertyAnimation}s that have already been set up.      \sa QAnimationGroup, QPropertyAnimation, {The Animation Framework} */
end_comment
begin_include
include|#
directive|include
file|"qparallelanimationgroup.h"
end_include
begin_include
include|#
directive|include
file|"qparallelanimationgroup_p.h"
end_include
begin_comment
comment|//#define QANIMATION_DEBUG
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|AnimationListConstIt
typedef|typedef
name|QList
argument_list|<
name|QAbstractAnimation
modifier|*
argument_list|>
operator|::
name|ConstIterator
name|AnimationListConstIt
typedef|;
end_typedef
begin_typedef
DECL|typedef|AnimationTimeHashIt
typedef|typedef
name|QHash
argument_list|<
name|QAbstractAnimation
modifier|*
argument_list|,
name|int
argument_list|>
operator|::
name|Iterator
name|AnimationTimeHashIt
typedef|;
end_typedef
begin_typedef
DECL|typedef|AnimationTimeHashConstIt
typedef|typedef
name|QHash
argument_list|<
name|QAbstractAnimation
modifier|*
argument_list|,
name|int
argument_list|>
operator|::
name|ConstIterator
name|AnimationTimeHashConstIt
typedef|;
end_typedef
begin_comment
comment|/*!     Constructs a QParallelAnimationGroup.     \a parent is passed to QObject's constructor. */
end_comment
begin_constructor
DECL|function|QParallelAnimationGroup
name|QParallelAnimationGroup
operator|::
name|QParallelAnimationGroup
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAnimationGroup
argument_list|(
operator|*
operator|new
name|QParallelAnimationGroupPrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QParallelAnimationGroup
name|QParallelAnimationGroup
operator|::
name|QParallelAnimationGroup
parameter_list|(
name|QParallelAnimationGroupPrivate
modifier|&
name|dd
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAnimationGroup
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the animation group. It will also destroy all its animations. */
end_comment
begin_destructor
DECL|function|~QParallelAnimationGroup
name|QParallelAnimationGroup
operator|::
name|~
name|QParallelAnimationGroup
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|duration
name|int
name|QParallelAnimationGroup
operator|::
name|duration
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QParallelAnimationGroup
argument_list|)
expr_stmt|;
name|int
name|ret
init|=
literal|0
decl_stmt|;
for|for
control|(
name|AnimationListConstIt
name|it
init|=
name|d
operator|->
name|animations
operator|.
name|constBegin
argument_list|()
init|,
name|cend
init|=
name|d
operator|->
name|animations
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
block|{
specifier|const
name|int
name|currentDuration
init|=
operator|(
operator|*
name|it
operator|)
operator|->
name|totalDuration
argument_list|()
decl_stmt|;
if|if
condition|(
name|currentDuration
operator|==
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
comment|// Undetermined length
name|ret
operator|=
name|qMax
argument_list|(
name|ret
argument_list|,
name|currentDuration
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|updateCurrentTime
name|void
name|QParallelAnimationGroup
operator|::
name|updateCurrentTime
parameter_list|(
name|int
name|currentTime
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QParallelAnimationGroup
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|animations
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
if|if
condition|(
name|d
operator|->
name|currentLoop
operator|>
name|d
operator|->
name|lastLoop
condition|)
block|{
comment|// simulate completion of the loop
name|int
name|dura
init|=
name|duration
argument_list|()
decl_stmt|;
if|if
condition|(
name|dura
operator|>
literal|0
condition|)
block|{
for|for
control|(
name|AnimationListConstIt
name|it
init|=
name|d
operator|->
name|animations
operator|.
name|constBegin
argument_list|()
init|,
name|cend
init|=
name|d
operator|->
name|animations
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
block|{
name|QAbstractAnimation
modifier|*
name|animation
init|=
operator|(
operator|*
name|it
operator|)
decl_stmt|;
if|if
condition|(
name|animation
operator|->
name|state
argument_list|()
operator|!=
name|QAbstractAnimation
operator|::
name|Stopped
condition|)
name|animation
operator|->
name|setCurrentTime
argument_list|(
name|dura
argument_list|)
expr_stmt|;
comment|// will stop
block|}
block|}
block|}
elseif|else
if|if
condition|(
name|d
operator|->
name|currentLoop
operator|<
name|d
operator|->
name|lastLoop
condition|)
block|{
comment|// simulate completion of the loop seeking backwards
for|for
control|(
name|AnimationListConstIt
name|it
init|=
name|d
operator|->
name|animations
operator|.
name|constBegin
argument_list|()
init|,
name|cend
init|=
name|d
operator|->
name|animations
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
block|{
name|QAbstractAnimation
modifier|*
name|animation
init|=
operator|*
name|it
decl_stmt|;
comment|//we need to make sure the animation is in the right state
comment|//and then rewind it
name|d
operator|->
name|applyGroupState
argument_list|(
name|animation
argument_list|)
expr_stmt|;
name|animation
operator|->
name|setCurrentTime
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|animation
operator|->
name|stop
argument_list|()
expr_stmt|;
block|}
block|}
ifdef|#
directive|ifdef
name|QANIMATION_DEBUG
name|qDebug
argument_list|(
literal|"QParallellAnimationGroup %5d: setCurrentTime(%d), loop:%d, last:%d, timeFwd:%d, lastcurrent:%d, %d"
argument_list|,
name|__LINE__
argument_list|,
name|d
operator|->
name|currentTime
argument_list|,
name|d
operator|->
name|currentLoop
argument_list|,
name|d
operator|->
name|lastLoop
argument_list|,
name|timeFwd
argument_list|,
name|d
operator|->
name|lastCurrentTime
argument_list|,
name|state
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// finally move into the actual time of the current loop
for|for
control|(
name|AnimationListConstIt
name|it
init|=
name|d
operator|->
name|animations
operator|.
name|constBegin
argument_list|()
init|,
name|cend
init|=
name|d
operator|->
name|animations
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
block|{
name|QAbstractAnimation
modifier|*
name|animation
init|=
operator|*
name|it
decl_stmt|;
specifier|const
name|int
name|dura
init|=
name|animation
operator|->
name|totalDuration
argument_list|()
decl_stmt|;
comment|//if the loopcount is bigger we should always start all animations
if|if
condition|(
name|d
operator|->
name|currentLoop
operator|>
name|d
operator|->
name|lastLoop
comment|//if we're at the end of the animation, we need to start it if it wasn't already started in this loop
comment|//this happens in Backward direction where not all animations are started at the same time
operator|||
name|d
operator|->
name|shouldAnimationStart
argument_list|(
name|animation
argument_list|,
name|d
operator|->
name|lastCurrentTime
operator|>
name|dura
comment|/*startIfAtEnd*/
argument_list|)
condition|)
block|{
name|d
operator|->
name|applyGroupState
argument_list|(
name|animation
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|animation
operator|->
name|state
argument_list|()
operator|==
name|state
argument_list|()
condition|)
block|{
name|animation
operator|->
name|setCurrentTime
argument_list|(
name|currentTime
argument_list|)
expr_stmt|;
if|if
condition|(
name|dura
operator|>
literal|0
operator|&&
name|currentTime
operator|>
name|dura
condition|)
name|animation
operator|->
name|stop
argument_list|()
expr_stmt|;
block|}
block|}
name|d
operator|->
name|lastLoop
operator|=
name|d
operator|->
name|currentLoop
expr_stmt|;
name|d
operator|->
name|lastCurrentTime
operator|=
name|currentTime
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|updateState
name|void
name|QParallelAnimationGroup
operator|::
name|updateState
parameter_list|(
name|QAbstractAnimation
operator|::
name|State
name|newState
parameter_list|,
name|QAbstractAnimation
operator|::
name|State
name|oldState
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QParallelAnimationGroup
argument_list|)
expr_stmt|;
name|QAnimationGroup
operator|::
name|updateState
argument_list|(
name|newState
argument_list|,
name|oldState
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|newState
condition|)
block|{
case|case
name|Stopped
case|:
for|for
control|(
name|AnimationListConstIt
name|it
init|=
name|d
operator|->
name|animations
operator|.
name|constBegin
argument_list|()
init|,
name|cend
init|=
name|d
operator|->
name|animations
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
operator|(
operator|*
name|it
operator|)
operator|->
name|stop
argument_list|()
expr_stmt|;
name|d
operator|->
name|disconnectUncontrolledAnimations
argument_list|()
expr_stmt|;
break|break;
case|case
name|Paused
case|:
for|for
control|(
name|AnimationListConstIt
name|it
init|=
name|d
operator|->
name|animations
operator|.
name|constBegin
argument_list|()
init|,
name|cend
init|=
name|d
operator|->
name|animations
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
operator|(
operator|*
name|it
operator|)
operator|->
name|state
argument_list|()
operator|==
name|Running
condition|)
operator|(
operator|*
name|it
operator|)
operator|->
name|pause
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
name|Running
case|:
name|d
operator|->
name|connectUncontrolledAnimations
argument_list|()
expr_stmt|;
for|for
control|(
name|AnimationListConstIt
name|it
init|=
name|d
operator|->
name|animations
operator|.
name|constBegin
argument_list|()
init|,
name|cend
init|=
name|d
operator|->
name|animations
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
block|{
name|QAbstractAnimation
modifier|*
name|animation
init|=
operator|*
name|it
decl_stmt|;
if|if
condition|(
name|oldState
operator|==
name|Stopped
condition|)
name|animation
operator|->
name|stop
argument_list|()
expr_stmt|;
name|animation
operator|->
name|setDirection
argument_list|(
name|d
operator|->
name|direction
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|shouldAnimationStart
argument_list|(
name|animation
argument_list|,
name|oldState
operator|==
name|Stopped
argument_list|)
condition|)
name|animation
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
break|break;
block|}
block|}
end_function
begin_function
DECL|function|_q_uncontrolledAnimationFinished
name|void
name|QParallelAnimationGroupPrivate
operator|::
name|_q_uncontrolledAnimationFinished
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QParallelAnimationGroup
argument_list|)
expr_stmt|;
name|QAbstractAnimation
modifier|*
name|animation
init|=
name|qobject_cast
argument_list|<
name|QAbstractAnimation
operator|*
argument_list|>
argument_list|(
name|q
operator|->
name|sender
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|animation
argument_list|)
expr_stmt|;
name|int
name|uncontrolledRunningCount
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|animation
operator|->
name|duration
argument_list|()
operator|==
operator|-
literal|1
operator|||
name|animation
operator|->
name|loopCount
argument_list|()
operator|<
literal|0
condition|)
block|{
for|for
control|(
name|AnimationTimeHashIt
name|it
init|=
name|uncontrolledFinishTime
operator|.
name|begin
argument_list|()
init|,
name|cend
init|=
name|uncontrolledFinishTime
operator|.
name|end
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
name|it
operator|.
name|key
argument_list|()
operator|==
name|animation
condition|)
block|{
operator|*
name|it
operator|=
name|animation
operator|->
name|currentTime
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|it
operator|.
name|value
argument_list|()
operator|==
operator|-
literal|1
condition|)
operator|++
name|uncontrolledRunningCount
expr_stmt|;
block|}
block|}
if|if
condition|(
name|uncontrolledRunningCount
operator|>
literal|0
condition|)
return|return;
name|int
name|maxDuration
init|=
literal|0
decl_stmt|;
for|for
control|(
name|AnimationListConstIt
name|it
init|=
name|animations
operator|.
name|constBegin
argument_list|()
init|,
name|cend
init|=
name|animations
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
name|maxDuration
operator|=
name|qMax
argument_list|(
name|maxDuration
argument_list|,
operator|(
operator|*
name|it
operator|)
operator|->
name|totalDuration
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|currentTime
operator|>=
name|maxDuration
condition|)
name|q
operator|->
name|stop
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|disconnectUncontrolledAnimations
name|void
name|QParallelAnimationGroupPrivate
operator|::
name|disconnectUncontrolledAnimations
parameter_list|()
block|{
for|for
control|(
name|AnimationTimeHashConstIt
name|it
init|=
name|uncontrolledFinishTime
operator|.
name|constBegin
argument_list|()
init|,
name|cend
init|=
name|uncontrolledFinishTime
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
name|disconnectUncontrolledAnimation
argument_list|(
name|it
operator|.
name|key
argument_list|()
argument_list|)
expr_stmt|;
name|uncontrolledFinishTime
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|connectUncontrolledAnimations
name|void
name|QParallelAnimationGroupPrivate
operator|::
name|connectUncontrolledAnimations
parameter_list|()
block|{
for|for
control|(
name|AnimationListConstIt
name|it
init|=
name|animations
operator|.
name|constBegin
argument_list|()
init|,
name|cend
init|=
name|animations
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
block|{
name|QAbstractAnimation
modifier|*
name|animation
init|=
operator|*
name|it
decl_stmt|;
if|if
condition|(
name|animation
operator|->
name|duration
argument_list|()
operator|==
operator|-
literal|1
operator|||
name|animation
operator|->
name|loopCount
argument_list|()
operator|<
literal|0
condition|)
block|{
name|uncontrolledFinishTime
index|[
name|animation
index|]
operator|=
operator|-
literal|1
expr_stmt|;
name|connectUncontrolledAnimation
argument_list|(
name|animation
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|shouldAnimationStart
name|bool
name|QParallelAnimationGroupPrivate
operator|::
name|shouldAnimationStart
parameter_list|(
name|QAbstractAnimation
modifier|*
name|animation
parameter_list|,
name|bool
name|startIfAtEnd
parameter_list|)
specifier|const
block|{
specifier|const
name|int
name|dura
init|=
name|animation
operator|->
name|totalDuration
argument_list|()
decl_stmt|;
if|if
condition|(
name|dura
operator|==
operator|-
literal|1
condition|)
return|return
operator|!
name|isUncontrolledAnimationFinished
argument_list|(
name|animation
argument_list|)
return|;
if|if
condition|(
name|startIfAtEnd
condition|)
return|return
name|currentTime
operator|<=
name|dura
return|;
if|if
condition|(
name|direction
operator|==
name|QAbstractAnimation
operator|::
name|Forward
condition|)
return|return
name|currentTime
operator|<
name|dura
return|;
else|else
comment|//direction == QAbstractAnimation::Backward
return|return
name|currentTime
operator|&&
name|currentTime
operator|<=
name|dura
return|;
block|}
end_function
begin_function
DECL|function|applyGroupState
name|void
name|QParallelAnimationGroupPrivate
operator|::
name|applyGroupState
parameter_list|(
name|QAbstractAnimation
modifier|*
name|animation
parameter_list|)
block|{
switch|switch
condition|(
name|state
condition|)
block|{
case|case
name|QAbstractAnimation
operator|::
name|Running
case|:
name|animation
operator|->
name|start
argument_list|()
expr_stmt|;
break|break;
case|case
name|QAbstractAnimation
operator|::
name|Paused
case|:
name|animation
operator|->
name|pause
argument_list|()
expr_stmt|;
break|break;
case|case
name|QAbstractAnimation
operator|::
name|Stopped
case|:
default|default:
break|break;
block|}
block|}
end_function
begin_function
DECL|function|isUncontrolledAnimationFinished
name|bool
name|QParallelAnimationGroupPrivate
operator|::
name|isUncontrolledAnimationFinished
parameter_list|(
name|QAbstractAnimation
modifier|*
name|anim
parameter_list|)
specifier|const
block|{
return|return
name|uncontrolledFinishTime
operator|.
name|value
argument_list|(
name|anim
argument_list|,
operator|-
literal|1
argument_list|)
operator|>=
literal|0
return|;
block|}
end_function
begin_function
DECL|function|animationRemoved
name|void
name|QParallelAnimationGroupPrivate
operator|::
name|animationRemoved
parameter_list|(
name|int
name|index
parameter_list|,
name|QAbstractAnimation
modifier|*
name|anim
parameter_list|)
block|{
name|QAnimationGroupPrivate
operator|::
name|animationRemoved
argument_list|(
name|index
argument_list|,
name|anim
argument_list|)
expr_stmt|;
name|disconnectUncontrolledAnimation
argument_list|(
name|anim
argument_list|)
expr_stmt|;
name|uncontrolledFinishTime
operator|.
name|remove
argument_list|(
name|anim
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|updateDirection
name|void
name|QParallelAnimationGroup
operator|::
name|updateDirection
parameter_list|(
name|QAbstractAnimation
operator|::
name|Direction
name|direction
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QParallelAnimationGroup
argument_list|)
expr_stmt|;
comment|//we need to update the direction of the current animation
if|if
condition|(
name|state
argument_list|()
operator|!=
name|Stopped
condition|)
block|{
for|for
control|(
name|AnimationListConstIt
name|it
init|=
name|d
operator|->
name|animations
operator|.
name|constBegin
argument_list|()
init|,
name|cend
init|=
name|d
operator|->
name|animations
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
operator|(
operator|*
name|it
operator|)
operator|->
name|setDirection
argument_list|(
name|direction
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|direction
operator|==
name|Forward
condition|)
block|{
name|d
operator|->
name|lastLoop
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|lastCurrentTime
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
comment|// Looping backwards with loopCount == -1 does not really work well...
name|d
operator|->
name|lastLoop
operator|=
operator|(
name|d
operator|->
name|loopCount
operator|==
operator|-
literal|1
condition|?
literal|0
else|:
name|d
operator|->
name|loopCount
operator|-
literal|1
operator|)
expr_stmt|;
name|d
operator|->
name|lastCurrentTime
operator|=
name|duration
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QParallelAnimationGroup
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
return|return
name|QAnimationGroup
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qparallelanimationgroup.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_ANIMATION
end_comment
end_unit
