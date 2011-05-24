begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qhistorystate.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE
end_ifndef
begin_include
include|#
directive|include
file|"qhistorystate_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!   \class QHistoryState    \brief The QHistoryState class provides a means of returning to a previously active substate.    \since 4.6   \ingroup statemachine    A history state is a pseudo-state that represents the child state that the   parent state was in the last time the parent state was exited. A transition   with a history state as its target is in fact a transition to one of the   other child states of the parent state. QHistoryState is part of \l{The   State Machine Framework}.    Use the setDefaultState() function to set the state that should be entered   if the parent state has never been entered.  Example:    \code   QStateMachine machine;    QState *s1 = new QState();   QState *s11 = new QState(s1);   QState *s12 = new QState(s1);    QHistoryState *s1h = new QHistoryState(s1);   s1h->setDefaultState(s11);    machine.addState(s1);    QState *s2 = new QState();   machine.addState(s2);    QPushButton *button = new QPushButton();   // Clicking the button will cause the state machine to enter the child state   // that s1 was in the last time s1 was exited, or the history state's default   // state if s1 has never been entered.   s1->addTransition(button, SIGNAL(clicked()), s1h);   \endcode    By default a history state is shallow, meaning that it won't remember nested   states. This can be configured through the historyType property. */
end_comment
begin_comment
comment|/*!   \property QHistoryState::defaultState    \brief the default state of this history state */
end_comment
begin_comment
comment|/*!   \property QHistoryState::historyType    \brief the type of history that this history state records    The default value of this property is QHistoryState::ShallowHistory. */
end_comment
begin_comment
comment|/*!   \enum QHistoryState::HistoryType    This enum specifies the type of history that a QHistoryState records.    \value ShallowHistory Only the immediate child states of the parent state   are recorded. In this case a transition with the history state as its   target will end up in the immediate child state that the parent was in the   last time it was exited. This is the default.    \value DeepHistory Nested states are recorded. In this case a transition   with the history state as its target will end up in the most deeply nested   descendant state the parent was in the last time it was exited. */
end_comment
begin_constructor
DECL|function|QHistoryStatePrivate
name|QHistoryStatePrivate
operator|::
name|QHistoryStatePrivate
parameter_list|()
member_init_list|:
name|QAbstractStatePrivate
argument_list|(
name|HistoryState
argument_list|)
member_init_list|,
name|defaultState
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|historyType
argument_list|(
name|QHistoryState
operator|::
name|ShallowHistory
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|get
name|QHistoryStatePrivate
modifier|*
name|QHistoryStatePrivate
operator|::
name|get
parameter_list|(
name|QHistoryState
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
begin_comment
comment|/*!   Constructs a new shallow history state with the given \a parent state. */
end_comment
begin_constructor
DECL|function|QHistoryState
name|QHistoryState
operator|::
name|QHistoryState
parameter_list|(
name|QState
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractState
argument_list|(
operator|*
operator|new
name|QHistoryStatePrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Constructs a new history state of the given \a type, with the given \a   parent state. */
end_comment
begin_constructor
DECL|function|QHistoryState
name|QHistoryState
operator|::
name|QHistoryState
parameter_list|(
name|HistoryType
name|type
parameter_list|,
name|QState
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractState
argument_list|(
operator|*
operator|new
name|QHistoryStatePrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QHistoryState
argument_list|)
expr_stmt|;
name|d
operator|->
name|historyType
operator|=
name|type
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Destroys this history state. */
end_comment
begin_destructor
DECL|function|~QHistoryState
name|QHistoryState
operator|::
name|~
name|QHistoryState
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!   Returns this history state's default state.  The default state indicates the   state to transition to if the parent state has never been entered before. */
end_comment
begin_function
DECL|function|defaultState
name|QAbstractState
modifier|*
name|QHistoryState
operator|::
name|defaultState
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QHistoryState
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|defaultState
return|;
block|}
end_function
begin_comment
comment|/*!   Sets this history state's default state to be the given \a state.   \a state must be a sibling of this history state.    Note that this function does not set \a state as the initial state   of its parent. */
end_comment
begin_function
DECL|function|setDefaultState
name|void
name|QHistoryState
operator|::
name|setDefaultState
parameter_list|(
name|QAbstractState
modifier|*
name|state
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QHistoryState
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|&&
name|state
operator|->
name|parentState
argument_list|()
operator|!=
name|parentState
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QHistoryState::setDefaultState: state %p does not belong "
literal|"to this history state's group (%p)"
argument_list|,
name|state
argument_list|,
name|parentState
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|defaultState
operator|=
name|state
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the type of history that this history state records. */
end_comment
begin_function
DECL|function|historyType
name|QHistoryState
operator|::
name|HistoryType
name|QHistoryState
operator|::
name|historyType
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QHistoryState
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|historyType
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the \a type of history that this history state records. */
end_comment
begin_function
DECL|function|setHistoryType
name|void
name|QHistoryState
operator|::
name|setHistoryType
parameter_list|(
name|HistoryType
name|type
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QHistoryState
argument_list|)
expr_stmt|;
name|d
operator|->
name|historyType
operator|=
name|type
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|onEntry
name|void
name|QHistoryState
operator|::
name|onEntry
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|onExit
name|void
name|QHistoryState
operator|::
name|onExit
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QHistoryState
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|QAbstractState
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
