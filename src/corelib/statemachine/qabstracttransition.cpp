begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qabstracttransition.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE
end_ifndef
begin_include
include|#
directive|include
file|"qabstracttransition_p.h"
end_include
begin_include
include|#
directive|include
file|"qabstractstate.h"
end_include
begin_include
include|#
directive|include
file|"qstate.h"
end_include
begin_include
include|#
directive|include
file|"qstatemachine.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!   \class QAbstractTransition    \brief The QAbstractTransition class is the base class of transitions between QAbstractState objects.    \since 4.6   \ingroup statemachine    The QAbstractTransition class is the abstract base class of transitions   between states (QAbstractState objects) of a   QStateMachine. QAbstractTransition is part of \l{The State Machine   Framework}.    The sourceState() function returns the source of the transition. The   targetStates() function returns the targets of the transition. The machine()   function returns the state machine that the transition is part of.    The triggered() signal is emitted when the transition has been triggered.    Transitions can cause animations to be played. Use the addAnimation()   function to add an animation to the transition.    \section1 Subclassing    The eventTest() function is called by the state machine to determine whether   an event should trigger the transition. In your reimplementation you   typically check the event type and cast the event object to the proper type,   and check that one or more properties of the event meet your criteria.    The onTransition() function is called when the transition is triggered;   reimplement this function to perform custom processing for the transition. */
comment|/*!     \property QAbstractTransition::sourceState      \brief the source state (parent) of this transition */
comment|/*!     \property QAbstractTransition::targetState      \brief the target state of this transition      If a transition has no target state, the transition may still be     triggered, but this will not cause the state machine's configuration to     change (i.e. the current state will not be exited and re-entered). */
comment|/*!     \property QAbstractTransition::targetStates      \brief the target states of this transition      If multiple states are specified, all must be descendants of the same     parallel group state. */
DECL|function|QAbstractTransitionPrivate
name|QAbstractTransitionPrivate
operator|::
name|QAbstractTransitionPrivate
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|get
name|QAbstractTransitionPrivate
modifier|*
name|QAbstractTransitionPrivate
operator|::
name|get
parameter_list|(
name|QAbstractTransition
modifier|*
name|q
parameter_list|)
block|{
return|return
name|q
operator|->
name|d_func
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|machine
name|QStateMachine
modifier|*
name|QAbstractTransitionPrivate
operator|::
name|machine
parameter_list|()
specifier|const
block|{
name|QState
modifier|*
name|source
init|=
name|sourceState
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|source
condition|)
return|return
literal|0
return|;
return|return
name|source
operator|->
name|machine
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|callEventTest
name|bool
name|QAbstractTransitionPrivate
operator|::
name|callEventTest
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QAbstractTransition
argument_list|)
expr_stmt|;
return|return
name|q
operator|->
name|eventTest
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|callOnTransition
name|void
name|QAbstractTransitionPrivate
operator|::
name|callOnTransition
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QAbstractTransition
argument_list|)
expr_stmt|;
name|q
operator|->
name|onTransition
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sourceState
name|QState
modifier|*
name|QAbstractTransitionPrivate
operator|::
name|sourceState
parameter_list|()
specifier|const
block|{
return|return
name|qobject_cast
argument_list|<
name|QState
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|emitTriggered
name|void
name|QAbstractTransitionPrivate
operator|::
name|emitTriggered
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QAbstractTransition
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|triggered
argument_list|()
emit|;
block|}
end_function
begin_comment
comment|/*!   Constructs a new QAbstractTransition object with the given \a sourceState. */
end_comment
begin_constructor
DECL|function|QAbstractTransition
name|QAbstractTransition
operator|::
name|QAbstractTransition
parameter_list|(
name|QState
modifier|*
name|sourceState
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QAbstractTransitionPrivate
argument_list|,
name|sourceState
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   \internal */
end_comment
begin_constructor
DECL|function|QAbstractTransition
name|QAbstractTransition
operator|::
name|QAbstractTransition
parameter_list|(
name|QAbstractTransitionPrivate
modifier|&
name|dd
parameter_list|,
name|QState
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Destroys this transition. */
end_comment
begin_destructor
DECL|function|~QAbstractTransition
name|QAbstractTransition
operator|::
name|~
name|QAbstractTransition
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!   Returns the source state of this transition, or 0 if this transition has no   source state. */
end_comment
begin_function
DECL|function|sourceState
name|QState
modifier|*
name|QAbstractTransition
operator|::
name|sourceState
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractTransition
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|sourceState
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the target state of this transition, or 0 if the transition has no   target. */
end_comment
begin_function
DECL|function|targetState
name|QAbstractState
modifier|*
name|QAbstractTransition
operator|::
name|targetState
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractTransition
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|targetStates
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|d
operator|->
name|targetStates
operator|.
name|first
argument_list|()
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the \a target state of this transition. */
end_comment
begin_function
DECL|function|setTargetState
name|void
name|QAbstractTransition
operator|::
name|setTargetState
parameter_list|(
name|QAbstractState
modifier|*
name|target
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractTransition
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|target
condition|)
name|d
operator|->
name|targetStates
operator|.
name|clear
argument_list|()
expr_stmt|;
else|else
name|setTargetStates
argument_list|(
name|QList
argument_list|<
name|QAbstractState
operator|*
argument_list|>
argument_list|()
operator|<<
name|target
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the target states of this transition, or an empty list if this   transition has no target states. */
end_comment
begin_function
DECL|function|targetStates
name|QList
argument_list|<
name|QAbstractState
modifier|*
argument_list|>
name|QAbstractTransition
operator|::
name|targetStates
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractTransition
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QAbstractState
modifier|*
argument_list|>
name|result
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
name|d
operator|->
name|targetStates
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QAbstractState
modifier|*
name|target
init|=
name|d
operator|->
name|targetStates
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|data
argument_list|()
decl_stmt|;
if|if
condition|(
name|target
condition|)
name|result
operator|.
name|append
argument_list|(
name|target
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the target states of this transition to be the given \a targets. */
end_comment
begin_function
DECL|function|setTargetStates
name|void
name|QAbstractTransition
operator|::
name|setTargetStates
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QAbstractState
modifier|*
argument_list|>
modifier|&
name|targets
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractTransition
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
name|targets
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QAbstractState
modifier|*
name|target
init|=
name|targets
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|target
condition|)
block|{
name|qWarning
argument_list|(
literal|"QAbstractTransition::setTargetStates: target state(s) cannot be null"
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
name|d
operator|->
name|targetStates
operator|.
name|clear
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
name|targets
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|d
operator|->
name|targetStates
operator|.
name|append
argument_list|(
name|targets
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the state machine that this transition is part of, or 0 if the   transition is not part of a state machine. */
end_comment
begin_function
DECL|function|machine
name|QStateMachine
modifier|*
name|QAbstractTransition
operator|::
name|machine
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractTransition
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|machine
argument_list|()
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
end_ifndef
begin_comment
comment|/*!   Adds the given \a animation to this transition.   The transition does not take ownership of the animation.    \sa removeAnimation(), animations() */
end_comment
begin_function
DECL|function|addAnimation
name|void
name|QAbstractTransition
operator|::
name|addAnimation
parameter_list|(
name|QAbstractAnimation
modifier|*
name|animation
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractTransition
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|animation
condition|)
block|{
name|qWarning
argument_list|(
literal|"QAbstractTransition::addAnimation: cannot add null animation"
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|animations
operator|.
name|append
argument_list|(
name|animation
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Removes the given \a animation from this transition.    \sa addAnimation() */
end_comment
begin_function
DECL|function|removeAnimation
name|void
name|QAbstractTransition
operator|::
name|removeAnimation
parameter_list|(
name|QAbstractAnimation
modifier|*
name|animation
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractTransition
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|animation
condition|)
block|{
name|qWarning
argument_list|(
literal|"QAbstractTransition::removeAnimation: cannot remove null animation"
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|animations
operator|.
name|removeOne
argument_list|(
name|animation
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the list of animations associated with this transition, or an empty   list if it has no animations.    \sa addAnimation() */
end_comment
begin_function
DECL|function|animations
name|QList
argument_list|<
name|QAbstractAnimation
modifier|*
argument_list|>
name|QAbstractTransition
operator|::
name|animations
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractTransition
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|animations
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!   \fn QAbstractTransition::eventTest(QEvent *event)    This function is called to determine whether the given \a event should cause   this transition to trigger. Reimplement this function and return true if the   event should trigger the transition, otherwise return false. */
end_comment
begin_comment
comment|/*!   \fn QAbstractTransition::onTransition(QEvent *event)    This function is called when the transition is triggered. The given \a event   is what caused the transition to trigger. Reimplement this function to   perform custom processing when the transition is triggered. */
end_comment
begin_comment
comment|/*!   \fn QAbstractTransition::triggered()    This signal is emitted when the transition has been triggered (after   onTransition() has been called). */
end_comment
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QAbstractTransition
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|QObject
operator|::
name|event
argument_list|(
name|e
argument_list|)
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
comment|//QT_NO_STATEMACHINE
end_comment
end_unit
