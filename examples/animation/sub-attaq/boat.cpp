begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//Own
end_comment
begin_include
include|#
directive|include
file|"boat.h"
end_include
begin_include
include|#
directive|include
file|"boat_p.h"
end_include
begin_include
include|#
directive|include
file|"bomb.h"
end_include
begin_include
include|#
directive|include
file|"pixmapitem.h"
end_include
begin_include
include|#
directive|include
file|"graphicsscene.h"
end_include
begin_include
include|#
directive|include
file|"animationmanager.h"
end_include
begin_include
include|#
directive|include
file|"qanimationstate.h"
end_include
begin_comment
comment|//Qt
end_comment
begin_include
include|#
directive|include
file|<QtCore/QPropertyAnimation>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStateMachine>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHistoryState>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFinalState>
end_include
begin_include
include|#
directive|include
file|<QtCore/QState>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSequentialAnimationGroup>
end_include
begin_function
DECL|function|setupDestroyAnimation
specifier|static
name|QAbstractAnimation
modifier|*
name|setupDestroyAnimation
parameter_list|(
name|Boat
modifier|*
name|boat
parameter_list|)
block|{
name|QSequentialAnimationGroup
modifier|*
name|group
init|=
operator|new
name|QSequentialAnimationGroup
argument_list|(
name|boat
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<=
literal|4
condition|;
name|i
operator|++
control|)
block|{
name|PixmapItem
modifier|*
name|step
init|=
operator|new
name|PixmapItem
argument_list|(
name|QString
argument_list|(
literal|"explosion/boat/step%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|,
name|GraphicsScene
operator|::
name|Big
argument_list|,
name|boat
argument_list|)
decl_stmt|;
name|step
operator|->
name|setZValue
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|step
operator|->
name|setOpacity
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|//fade-in
name|QPropertyAnimation
modifier|*
name|anim
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|step
argument_list|,
literal|"opacity"
argument_list|)
decl_stmt|;
name|anim
operator|->
name|setEndValue
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setDuration
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|group
operator|->
name|insertAnimation
argument_list|(
name|i
operator|-
literal|1
argument_list|,
name|anim
argument_list|)
expr_stmt|;
comment|//and then fade-out
name|QPropertyAnimation
modifier|*
name|anim2
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|step
argument_list|,
literal|"opacity"
argument_list|)
decl_stmt|;
name|anim2
operator|->
name|setEndValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|anim2
operator|->
name|setDuration
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|group
operator|->
name|addAnimation
argument_list|(
name|anim2
argument_list|)
expr_stmt|;
block|}
name|AnimationManager
operator|::
name|self
argument_list|()
operator|->
name|registerAnimation
argument_list|(
name|group
argument_list|)
expr_stmt|;
return|return
name|group
return|;
block|}
end_function
begin_constructor
DECL|function|Boat
name|Boat
operator|::
name|Boat
parameter_list|()
member_init_list|:
name|PixmapItem
argument_list|(
name|QString
argument_list|(
literal|"boat"
argument_list|)
argument_list|,
name|GraphicsScene
operator|::
name|Big
argument_list|)
member_init_list|,
name|speed
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|bombsAlreadyLaunched
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|direction
argument_list|(
name|Boat
operator|::
name|None
argument_list|)
member_init_list|,
name|movementAnimation
argument_list|(
literal|0
argument_list|)
block|{
name|setZValue
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|setFlags
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIsFocusable
argument_list|)
expr_stmt|;
comment|//The movement animation used to animate the boat
name|movementAnimation
operator|=
operator|new
name|QPropertyAnimation
argument_list|(
name|this
argument_list|,
literal|"pos"
argument_list|)
expr_stmt|;
comment|//The destroy animation used to explode the boat
name|destroyAnimation
operator|=
name|setupDestroyAnimation
argument_list|(
name|this
argument_list|)
expr_stmt|;
comment|//We setup the state machine of the boat
name|machine
operator|=
operator|new
name|QStateMachine
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|moving
init|=
operator|new
name|QState
argument_list|(
name|machine
argument_list|)
decl_stmt|;
name|StopState
modifier|*
name|stopState
init|=
operator|new
name|StopState
argument_list|(
name|this
argument_list|,
name|moving
argument_list|)
decl_stmt|;
name|machine
operator|->
name|setInitialState
argument_list|(
name|moving
argument_list|)
expr_stmt|;
name|moving
operator|->
name|setInitialState
argument_list|(
name|stopState
argument_list|)
expr_stmt|;
name|MoveStateRight
modifier|*
name|moveStateRight
init|=
operator|new
name|MoveStateRight
argument_list|(
name|this
argument_list|,
name|moving
argument_list|)
decl_stmt|;
name|MoveStateLeft
modifier|*
name|moveStateLeft
init|=
operator|new
name|MoveStateLeft
argument_list|(
name|this
argument_list|,
name|moving
argument_list|)
decl_stmt|;
name|LaunchStateRight
modifier|*
name|launchStateRight
init|=
operator|new
name|LaunchStateRight
argument_list|(
name|this
argument_list|,
name|machine
argument_list|)
decl_stmt|;
name|LaunchStateLeft
modifier|*
name|launchStateLeft
init|=
operator|new
name|LaunchStateLeft
argument_list|(
name|this
argument_list|,
name|machine
argument_list|)
decl_stmt|;
comment|//then setup the transitions for the rightMove state
name|KeyStopTransition
modifier|*
name|leftStopRight
init|=
operator|new
name|KeyStopTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Left
argument_list|)
decl_stmt|;
name|leftStopRight
operator|->
name|setTargetState
argument_list|(
name|stopState
argument_list|)
expr_stmt|;
name|KeyMoveTransition
modifier|*
name|leftMoveRight
init|=
operator|new
name|KeyMoveTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Left
argument_list|)
decl_stmt|;
name|leftMoveRight
operator|->
name|setTargetState
argument_list|(
name|moveStateRight
argument_list|)
expr_stmt|;
name|KeyMoveTransition
modifier|*
name|rightMoveRight
init|=
operator|new
name|KeyMoveTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Right
argument_list|)
decl_stmt|;
name|rightMoveRight
operator|->
name|setTargetState
argument_list|(
name|moveStateRight
argument_list|)
expr_stmt|;
name|KeyMoveTransition
modifier|*
name|rightMoveStop
init|=
operator|new
name|KeyMoveTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Right
argument_list|)
decl_stmt|;
name|rightMoveStop
operator|->
name|setTargetState
argument_list|(
name|moveStateRight
argument_list|)
expr_stmt|;
comment|//then setup the transitions for the leftMove state
name|KeyStopTransition
modifier|*
name|rightStopLeft
init|=
operator|new
name|KeyStopTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Right
argument_list|)
decl_stmt|;
name|rightStopLeft
operator|->
name|setTargetState
argument_list|(
name|stopState
argument_list|)
expr_stmt|;
name|KeyMoveTransition
modifier|*
name|rightMoveLeft
init|=
operator|new
name|KeyMoveTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Right
argument_list|)
decl_stmt|;
name|rightMoveLeft
operator|->
name|setTargetState
argument_list|(
name|moveStateLeft
argument_list|)
expr_stmt|;
name|KeyMoveTransition
modifier|*
name|leftMoveLeft
init|=
operator|new
name|KeyMoveTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Left
argument_list|)
decl_stmt|;
name|leftMoveLeft
operator|->
name|setTargetState
argument_list|(
name|moveStateLeft
argument_list|)
expr_stmt|;
name|KeyMoveTransition
modifier|*
name|leftMoveStop
init|=
operator|new
name|KeyMoveTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Left
argument_list|)
decl_stmt|;
name|leftMoveStop
operator|->
name|setTargetState
argument_list|(
name|moveStateLeft
argument_list|)
expr_stmt|;
comment|//We set up the right move state
name|moveStateRight
operator|->
name|addTransition
argument_list|(
name|leftStopRight
argument_list|)
expr_stmt|;
name|moveStateRight
operator|->
name|addTransition
argument_list|(
name|leftMoveRight
argument_list|)
expr_stmt|;
name|moveStateRight
operator|->
name|addTransition
argument_list|(
name|rightMoveRight
argument_list|)
expr_stmt|;
name|stopState
operator|->
name|addTransition
argument_list|(
name|rightMoveStop
argument_list|)
expr_stmt|;
comment|//We set up the left move state
name|moveStateLeft
operator|->
name|addTransition
argument_list|(
name|rightStopLeft
argument_list|)
expr_stmt|;
name|moveStateLeft
operator|->
name|addTransition
argument_list|(
name|leftMoveLeft
argument_list|)
expr_stmt|;
name|moveStateLeft
operator|->
name|addTransition
argument_list|(
name|rightMoveLeft
argument_list|)
expr_stmt|;
name|stopState
operator|->
name|addTransition
argument_list|(
name|leftMoveStop
argument_list|)
expr_stmt|;
comment|//The animation is finished, it means we reached the border of the screen, the boat is stopped so we move to the stop state
name|moveStateLeft
operator|->
name|addTransition
argument_list|(
name|movementAnimation
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|stopState
argument_list|)
expr_stmt|;
name|moveStateRight
operator|->
name|addTransition
argument_list|(
name|movementAnimation
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|stopState
argument_list|)
expr_stmt|;
comment|//We set up the keys for dropping bombs
name|KeyLaunchTransition
modifier|*
name|upFireLeft
init|=
operator|new
name|KeyLaunchTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Up
argument_list|)
decl_stmt|;
name|upFireLeft
operator|->
name|setTargetState
argument_list|(
name|launchStateRight
argument_list|)
expr_stmt|;
name|KeyLaunchTransition
modifier|*
name|upFireRight
init|=
operator|new
name|KeyLaunchTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Up
argument_list|)
decl_stmt|;
name|upFireRight
operator|->
name|setTargetState
argument_list|(
name|launchStateRight
argument_list|)
expr_stmt|;
name|KeyLaunchTransition
modifier|*
name|upFireStop
init|=
operator|new
name|KeyLaunchTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Up
argument_list|)
decl_stmt|;
name|upFireStop
operator|->
name|setTargetState
argument_list|(
name|launchStateRight
argument_list|)
expr_stmt|;
name|KeyLaunchTransition
modifier|*
name|downFireLeft
init|=
operator|new
name|KeyLaunchTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Down
argument_list|)
decl_stmt|;
name|downFireLeft
operator|->
name|setTargetState
argument_list|(
name|launchStateLeft
argument_list|)
expr_stmt|;
name|KeyLaunchTransition
modifier|*
name|downFireRight
init|=
operator|new
name|KeyLaunchTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Down
argument_list|)
decl_stmt|;
name|downFireRight
operator|->
name|setTargetState
argument_list|(
name|launchStateLeft
argument_list|)
expr_stmt|;
name|KeyLaunchTransition
modifier|*
name|downFireMove
init|=
operator|new
name|KeyLaunchTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Down
argument_list|)
decl_stmt|;
name|downFireMove
operator|->
name|setTargetState
argument_list|(
name|launchStateLeft
argument_list|)
expr_stmt|;
comment|//We set up transitions for fire up
name|moveStateRight
operator|->
name|addTransition
argument_list|(
name|upFireRight
argument_list|)
expr_stmt|;
name|moveStateLeft
operator|->
name|addTransition
argument_list|(
name|upFireLeft
argument_list|)
expr_stmt|;
name|stopState
operator|->
name|addTransition
argument_list|(
name|upFireStop
argument_list|)
expr_stmt|;
comment|//We set up transitions for fire down
name|moveStateRight
operator|->
name|addTransition
argument_list|(
name|downFireRight
argument_list|)
expr_stmt|;
name|moveStateLeft
operator|->
name|addTransition
argument_list|(
name|downFireLeft
argument_list|)
expr_stmt|;
name|stopState
operator|->
name|addTransition
argument_list|(
name|downFireMove
argument_list|)
expr_stmt|;
comment|//Finally the launch state should come back to its original state
name|QHistoryState
modifier|*
name|historyState
init|=
operator|new
name|QHistoryState
argument_list|(
name|moving
argument_list|)
decl_stmt|;
name|launchStateLeft
operator|->
name|addTransition
argument_list|(
name|historyState
argument_list|)
expr_stmt|;
name|launchStateRight
operator|->
name|addTransition
argument_list|(
name|historyState
argument_list|)
expr_stmt|;
name|QFinalState
modifier|*
name|final
init|=
operator|new
name|QFinalState
argument_list|(
name|machine
argument_list|)
decl_stmt|;
comment|//This state play the destroyed animation
name|QAnimationState
modifier|*
name|destroyedState
init|=
operator|new
name|QAnimationState
argument_list|(
name|machine
argument_list|)
decl_stmt|;
name|destroyedState
operator|->
name|setAnimation
argument_list|(
name|destroyAnimation
argument_list|)
expr_stmt|;
comment|//Play a nice animation when the boat is destroyed
name|moving
operator|->
name|addTransition
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|boatDestroyed
argument_list|()
argument_list|)
argument_list|,
name|destroyedState
argument_list|)
expr_stmt|;
comment|//Transition to final state when the destroyed animation is finished
name|destroyedState
operator|->
name|addTransition
argument_list|(
name|destroyedState
argument_list|,
name|SIGNAL
argument_list|(
name|animationFinished
argument_list|()
argument_list|)
argument_list|,
name|final
argument_list|)
expr_stmt|;
comment|//The machine has finished to be executed, then the boat is dead
name|connect
argument_list|(
name|machine
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|boatExecutionFinished
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|run
name|void
name|Boat
operator|::
name|run
parameter_list|()
block|{
comment|//We register animations
name|AnimationManager
operator|::
name|self
argument_list|()
operator|->
name|registerAnimation
argument_list|(
name|movementAnimation
argument_list|)
expr_stmt|;
name|AnimationManager
operator|::
name|self
argument_list|()
operator|->
name|registerAnimation
argument_list|(
name|destroyAnimation
argument_list|)
expr_stmt|;
name|machine
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stop
name|void
name|Boat
operator|::
name|stop
parameter_list|()
block|{
name|movementAnimation
operator|->
name|stop
argument_list|()
expr_stmt|;
name|machine
operator|->
name|stop
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateBoatMovement
name|void
name|Boat
operator|::
name|updateBoatMovement
parameter_list|()
block|{
if|if
condition|(
name|speed
operator|==
literal|0
operator|||
name|direction
operator|==
name|Boat
operator|::
name|None
condition|)
block|{
name|movementAnimation
operator|->
name|stop
argument_list|()
expr_stmt|;
return|return;
block|}
name|movementAnimation
operator|->
name|stop
argument_list|()
expr_stmt|;
if|if
condition|(
name|direction
operator|==
name|Boat
operator|::
name|Left
condition|)
block|{
name|movementAnimation
operator|->
name|setEndValue
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
name|y
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|movementAnimation
operator|->
name|setDuration
argument_list|(
name|x
argument_list|()
operator|/
name|speed
operator|*
literal|15
argument_list|)
expr_stmt|;
block|}
else|else
comment|/*if (direction == Boat::Right)*/
block|{
name|movementAnimation
operator|->
name|setEndValue
argument_list|(
name|QPointF
argument_list|(
name|scene
argument_list|()
operator|->
name|width
argument_list|()
operator|-
name|size
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|y
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|movementAnimation
operator|->
name|setDuration
argument_list|(
operator|(
name|scene
argument_list|()
operator|->
name|width
argument_list|()
operator|-
name|size
argument_list|()
operator|.
name|width
argument_list|()
operator|-
name|x
argument_list|()
operator|)
operator|/
name|speed
operator|*
literal|15
argument_list|)
expr_stmt|;
block|}
name|movementAnimation
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|destroy
name|void
name|Boat
operator|::
name|destroy
parameter_list|()
block|{
name|movementAnimation
operator|->
name|stop
argument_list|()
expr_stmt|;
emit|emit
name|boatDestroyed
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|bombsLaunched
name|int
name|Boat
operator|::
name|bombsLaunched
parameter_list|()
specifier|const
block|{
return|return
name|bombsAlreadyLaunched
return|;
block|}
end_function
begin_function
DECL|function|setBombsLaunched
name|void
name|Boat
operator|::
name|setBombsLaunched
parameter_list|(
name|int
name|number
parameter_list|)
block|{
if|if
condition|(
name|number
operator|>
name|MAX_BOMB
condition|)
block|{
name|qWarning
argument_list|(
literal|"Boat::setBombsLaunched : It impossible to launch that number of bombs"
argument_list|)
expr_stmt|;
return|return;
block|}
name|bombsAlreadyLaunched
operator|=
name|number
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentSpeed
name|int
name|Boat
operator|::
name|currentSpeed
parameter_list|()
specifier|const
block|{
return|return
name|speed
return|;
block|}
end_function
begin_function
DECL|function|setCurrentSpeed
name|void
name|Boat
operator|::
name|setCurrentSpeed
parameter_list|(
name|int
name|speed
parameter_list|)
block|{
if|if
condition|(
name|speed
operator|>
literal|3
operator|||
name|speed
operator|<
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"Boat::setCurrentSpeed: The boat can't run on that speed"
argument_list|)
expr_stmt|;
return|return;
block|}
name|this
operator|->
name|speed
operator|=
name|speed
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentDirection
name|enum
name|Boat
operator|::
name|Movement
name|Boat
operator|::
name|currentDirection
parameter_list|()
specifier|const
block|{
return|return
name|direction
return|;
block|}
end_function
begin_function
DECL|function|setCurrentDirection
name|void
name|Boat
operator|::
name|setCurrentDirection
parameter_list|(
name|Movement
name|direction
parameter_list|)
block|{
name|this
operator|->
name|direction
operator|=
name|direction
expr_stmt|;
block|}
end_function
begin_function
DECL|function|type
name|int
name|Boat
operator|::
name|type
parameter_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
end_function
end_unit
