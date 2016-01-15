begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|"qhistorystate.h"
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
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!   \class QAbstractTransition   \inmodule QtCore    \brief The QAbstractTransition class is the base class of transitions between QAbstractState objects.    \since 4.6   \ingroup statemachine    The QAbstractTransition class is the abstract base class of transitions   between states (QAbstractState objects) of a   QStateMachine. QAbstractTransition is part of \l{The State Machine   Framework}.    The sourceState() function returns the source of the transition. The   targetStates() function returns the targets of the transition. The machine()   function returns the state machine that the transition is part of.    The triggered() signal is emitted when the transition has been triggered.    Transitions can cause animations to be played. Use the addAnimation()   function to add an animation to the transition.    \section1 Subclassing    The eventTest() function is called by the state machine to determine whether   an event should trigger the transition. In your reimplementation you   typically check the event type and cast the event object to the proper type,   and check that one or more properties of the event meet your criteria.    The onTransition() function is called when the transition is triggered;   reimplement this function to perform custom processing for the transition. */
end_comment
begin_comment
comment|/*!     \property QAbstractTransition::sourceState      \brief the source state (parent) of this transition */
end_comment
begin_comment
comment|/*!     \property QAbstractTransition::targetState      \brief the target state of this transition      If a transition has no target state, the transition may still be     triggered, but this will not cause the state machine's configuration to     change (i.e. the current state will not be exited and re-entered). */
end_comment
begin_comment
comment|/*!     \property QAbstractTransition::targetStates      \brief the target states of this transition      If multiple states are specified, all must be descendants of the same     parallel group state. */
end_comment
begin_comment
comment|/*!     \property QAbstractTransition::transitionType      \brief indicates whether this transition is an internal transition, or an external transition.      Internal and external transitions behave the same, except for the case of a transition whose     source state is a compound state and whose target(s) is a descendant of the source. In such a     case, an internal transition will not exit and re-enter its source state, while an external one     will.      By default, the type is an external transition. */
end_comment
begin_comment
comment|/*!   \enum QAbstractTransition::TransitionType    This enum specifies the kind of transition. By default, the type is an external transition.    \value ExternalTransition Any state that is the source state of a transition (which is not a                             target-less transition) is left, and re-entered when necessary.   \value InternalTransition If the target state of a transition is a sub-state of a compound state,                             and that compound state is the source state, an internal transition will                             not leave the source state.    \sa QAbstractTransition::transitionType */
end_comment
begin_constructor
DECL|function|QAbstractTransitionPrivate
name|QAbstractTransitionPrivate
operator|::
name|QAbstractTransitionPrivate
parameter_list|()
member_init_list|:
name|transitionType
argument_list|(
name|QAbstractTransition
operator|::
name|ExternalTransition
argument_list|)
block|{ }
end_constructor
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
if|if
condition|(
name|QState
modifier|*
name|source
init|=
name|sourceState
argument_list|()
condition|)
return|return
name|source
operator|->
name|machine
argument_list|()
return|;
name|Q_Q
argument_list|(
specifier|const
name|QAbstractTransition
argument_list|)
expr_stmt|;
if|if
condition|(
name|QHistoryState
modifier|*
name|parent
init|=
name|qobject_cast
argument_list|<
name|QHistoryState
operator|*
argument_list|>
argument_list|(
name|q
operator|->
name|parent
argument_list|()
argument_list|)
condition|)
return|return
name|parent
operator|->
name|machine
argument_list|()
return|;
return|return
literal|0
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
argument_list|(
name|QAbstractTransition
operator|::
name|QPrivateSignal
argument_list|()
argument_list|)
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
operator|(
name|d
operator|->
name|targetStates
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
name|target
operator|==
name|d
operator|->
name|targetStates
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|data
argument_list|()
operator|)
operator|||
operator|(
name|d
operator|->
name|targetStates
operator|.
name|isEmpty
argument_list|()
operator|&&
name|target
operator|==
literal|0
operator|)
condition|)
block|{
return|return;
block|}
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
emit|emit
name|targetStateChanged
argument_list|(
name|QPrivateSignal
argument_list|()
argument_list|)
emit|;
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
comment|// Verify if any of the new target states is a null-pointer:
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
if|if
condition|(
name|targets
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|Q_NULLPTR
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
comment|// First clean out any target states that got destroyed, but for which we still have a QPointer
comment|// around.
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
control|)
block|{
if|if
condition|(
name|d
operator|->
name|targetStates
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|d
operator|->
name|targetStates
operator|.
name|remove
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|++
name|i
expr_stmt|;
block|}
block|}
comment|// Easy check: if both lists are empty, we're done.
if|if
condition|(
name|targets
operator|.
name|isEmpty
argument_list|()
operator|&&
name|d
operator|->
name|targetStates
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|bool
name|sameList
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|targets
operator|.
name|size
argument_list|()
operator|!=
name|d
operator|->
name|targetStates
operator|.
name|size
argument_list|()
condition|)
block|{
comment|// If the sizes of the lists are different, we don't need to be smart: they're different. So
comment|// we can just set the new list as the targetStates.
name|sameList
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
name|QVector
argument_list|<
name|QPointer
argument_list|<
name|QAbstractState
argument_list|>
argument_list|>
name|copy
argument_list|(
name|d
operator|->
name|targetStates
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
name|targets
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|sameList
operator|&=
name|copy
operator|.
name|removeOne
argument_list|(
name|targets
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|sameList
condition|)
break|break;
comment|// ok, we now know the lists are not the same, so stop the loop.
block|}
name|sameList
operator|&=
name|copy
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|sameList
condition|)
return|return;
name|d
operator|->
name|targetStates
operator|.
name|resize
argument_list|(
name|targets
operator|.
name|size
argument_list|()
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
name|d
operator|->
name|targetStates
index|[
name|i
index|]
operator|=
name|targets
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
emit|emit
name|targetStatesChanged
argument_list|(
name|QPrivateSignal
argument_list|()
argument_list|)
emit|;
block|}
end_function
begin_comment
comment|/*!   Returns the type of the transition. */
end_comment
begin_function
DECL|function|transitionType
name|QAbstractTransition
operator|::
name|TransitionType
name|QAbstractTransition
operator|::
name|transitionType
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
name|transitionType
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the type of the transition to \a type. */
end_comment
begin_function
DECL|function|setTransitionType
name|void
name|QAbstractTransition
operator|::
name|setTransitionType
parameter_list|(
name|TransitionType
name|type
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractTransition
argument_list|)
expr_stmt|;
name|d
operator|->
name|transitionType
operator|=
name|type
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
comment|/*!   \fn QAbstractTransition::targetStateChanged()   \since 5.4    This signal is emitted when the targetState property is changed.    \sa QAbstractTransition::targetState */
end_comment
begin_comment
comment|/*!   \fn QAbstractTransition::targetStatesChanged()   \since 5.4    This signal is emitted when the targetStates property is changed.    \sa QAbstractTransition::targetStates */
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
