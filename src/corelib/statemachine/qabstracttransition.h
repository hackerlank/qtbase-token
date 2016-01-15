begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTTRANSITION_H
end_ifndef
begin_define
DECL|macro|QABSTRACTTRANSITION_H
define|#
directive|define
name|QABSTRACTTRANSITION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE
DECL|variable|QEvent
name|class
name|QEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractState
name|class
name|QAbstractState
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QState
name|class
name|QState
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStateMachine
name|class
name|QStateMachine
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
end_ifndef
begin_decl_stmt
DECL|variable|QAbstractAnimation
name|class
name|QAbstractAnimation
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QAbstractTransitionPrivate
name|class
name|QAbstractTransitionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QAbstractTransition
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QState* sourceState READ sourceState
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QAbstractState* targetState READ targetState WRITE setTargetState NOTIFY targetStateChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QList<QAbstractState*> targetStates READ targetStates WRITE setTargetStates NOTIFY targetStatesChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|TransitionType transitionType READ transitionType WRITE setTransitionType REVISION
literal|1
argument_list|)
name|public
operator|:
expr|enum
name|TransitionType
block|{
name|ExternalTransition
block|,
name|InternalTransition
block|}
block|;
name|Q_ENUM
argument_list|(
argument|TransitionType
argument_list|)
name|QAbstractTransition
argument_list|(
name|QState
operator|*
name|sourceState
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|virtual
operator|~
name|QAbstractTransition
argument_list|()
block|;
name|QState
operator|*
name|sourceState
argument_list|()
specifier|const
block|;
name|QAbstractState
operator|*
name|targetState
argument_list|()
specifier|const
block|;
name|void
name|setTargetState
argument_list|(
name|QAbstractState
operator|*
name|target
argument_list|)
block|;
name|QList
operator|<
name|QAbstractState
operator|*
operator|>
name|targetStates
argument_list|()
specifier|const
block|;
name|void
name|setTargetStates
argument_list|(
specifier|const
name|QList
operator|<
name|QAbstractState
operator|*
operator|>
operator|&
name|targets
argument_list|)
block|;
name|TransitionType
name|transitionType
argument_list|()
specifier|const
block|;
name|void
name|setTransitionType
argument_list|(
argument|TransitionType type
argument_list|)
block|;
name|QStateMachine
operator|*
name|machine
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
name|void
name|addAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|animation
argument_list|)
block|;
name|void
name|removeAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|animation
argument_list|)
block|;
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
name|animations
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|Q_SIGNALS
operator|:
name|void
name|triggered
argument_list|(
name|QPrivateSignal
argument_list|)
block|;
name|void
name|targetStateChanged
argument_list|(
name|QPrivateSignal
argument_list|)
block|;
name|void
name|targetStatesChanged
argument_list|(
name|QPrivateSignal
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|bool
name|eventTest
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|onTransition
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
operator|=
literal|0
block|;
name|bool
name|event
argument_list|(
argument|QEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|QAbstractTransition
argument_list|(
name|QAbstractTransitionPrivate
operator|&
name|dd
argument_list|,
name|QState
operator|*
name|parent
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QAbstractTransition
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QAbstractTransition
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_STATEMACHINE
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
