begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"lifecycle.h"
end_include
begin_include
include|#
directive|include
file|"stickman.h"
end_include
begin_include
include|#
directive|include
file|"node.h"
end_include
begin_include
include|#
directive|include
file|"animation.h"
end_include
begin_include
include|#
directive|include
file|"graphicsview.h"
end_include
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_class
DECL|class|KeyPressTransition
class|class
name|KeyPressTransition
super|:
specifier|public
name|QSignalTransition
block|{
public|public:
DECL|function|KeyPressTransition
name|KeyPressTransition
parameter_list|(
name|GraphicsView
modifier|*
name|receiver
parameter_list|,
name|Qt
operator|::
name|Key
name|key
parameter_list|)
member_init_list|:
name|QSignalTransition
argument_list|(
name|receiver
argument_list|,
name|SIGNAL
argument_list|(
name|keyPressed
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|m_key
argument_list|(
name|key
argument_list|)
block|{     }
DECL|function|KeyPressTransition
name|KeyPressTransition
parameter_list|(
name|GraphicsView
modifier|*
name|receiver
parameter_list|,
name|Qt
operator|::
name|Key
name|key
parameter_list|,
name|QAbstractState
modifier|*
name|target
parameter_list|)
member_init_list|:
name|QSignalTransition
argument_list|(
name|receiver
argument_list|,
name|SIGNAL
argument_list|(
name|keyPressed
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|m_key
argument_list|(
name|key
argument_list|)
block|{
name|setTargetState
argument_list|(
name|target
argument_list|)
expr_stmt|;
block|}
specifier|virtual
name|bool
name|eventTest
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
if|if
condition|(
name|QSignalTransition
operator|::
name|eventTest
argument_list|(
name|e
argument_list|)
condition|)
block|{
name|QVariant
name|key
init|=
cast|static_cast
argument_list|<
name|QStateMachine
operator|::
name|SignalEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
operator|->
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
return|return
operator|(
name|key
operator|.
name|toInt
argument_list|()
operator|==
name|int
argument_list|(
name|m_key
argument_list|)
operator|)
return|;
block|}
return|return
literal|false
return|;
block|}
private|private:
DECL|member|m_key
name|Qt
operator|::
name|Key
name|m_key
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//! [4]
end_comment
begin_class
DECL|class|LightningStrikesTransition
class|class
name|LightningStrikesTransition
super|:
specifier|public
name|QEventTransition
block|{
public|public:
DECL|function|LightningStrikesTransition
name|LightningStrikesTransition
parameter_list|(
name|QAbstractState
modifier|*
name|target
parameter_list|)
member_init_list|:
name|QEventTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|Timer
argument_list|)
block|{
name|setTargetState
argument_list|(
name|target
argument_list|)
expr_stmt|;
name|qsrand
argument_list|(
operator|(
name|uint
operator|)
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
operator|.
name|toTime_t
argument_list|()
argument_list|)
expr_stmt|;
name|startTimer
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
block|}
specifier|virtual
name|bool
name|eventTest
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
return|return
name|QEventTransition
operator|::
name|eventTest
argument_list|(
name|e
argument_list|)
operator|&&
operator|(
operator|(
name|qrand
argument_list|()
operator|%
literal|50
operator|)
operator|==
literal|0
operator|)
return|;
block|}
block|}
class|;
end_class
begin_comment
comment|//! [4]
end_comment
begin_constructor
DECL|function|LifeCycle
name|LifeCycle
operator|::
name|LifeCycle
parameter_list|(
name|StickMan
modifier|*
name|stickMan
parameter_list|,
name|GraphicsView
modifier|*
name|keyReceiver
parameter_list|)
member_init_list|:
name|m_stickMan
argument_list|(
name|stickMan
argument_list|)
member_init_list|,
name|m_keyReceiver
argument_list|(
name|keyReceiver
argument_list|)
block|{
comment|// Create animation group to be used for all transitions
name|m_animationGroup
operator|=
operator|new
name|QParallelAnimationGroup
argument_list|()
expr_stmt|;
specifier|const
name|int
name|stickManNodeCount
init|=
name|m_stickMan
operator|->
name|nodeCount
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
name|stickManNodeCount
condition|;
operator|++
name|i
control|)
block|{
name|QPropertyAnimation
modifier|*
name|pa
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|m_stickMan
operator|->
name|node
argument_list|(
name|i
argument_list|)
argument_list|,
literal|"pos"
argument_list|)
decl_stmt|;
name|m_animationGroup
operator|->
name|addAnimation
argument_list|(
name|pa
argument_list|)
expr_stmt|;
block|}
comment|// Set up initial state graph
comment|//! [3]
name|m_machine
operator|=
operator|new
name|QStateMachine
argument_list|()
expr_stmt|;
name|m_machine
operator|->
name|addDefaultAnimation
argument_list|(
name|m_animationGroup
argument_list|)
expr_stmt|;
comment|//! [3]
name|m_alive
operator|=
operator|new
name|QState
argument_list|(
name|m_machine
argument_list|)
expr_stmt|;
name|m_alive
operator|->
name|setObjectName
argument_list|(
literal|"alive"
argument_list|)
expr_stmt|;
comment|// Make it blink when lightning strikes before entering dead animation
name|QState
modifier|*
name|lightningBlink
init|=
operator|new
name|QState
argument_list|(
name|m_machine
argument_list|)
decl_stmt|;
name|lightningBlink
operator|->
name|assignProperty
argument_list|(
name|m_stickMan
operator|->
name|scene
argument_list|()
argument_list|,
literal|"backgroundBrush"
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
name|lightningBlink
operator|->
name|assignProperty
argument_list|(
name|m_stickMan
argument_list|,
literal|"penColor"
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
argument_list|)
expr_stmt|;
name|lightningBlink
operator|->
name|assignProperty
argument_list|(
name|m_stickMan
argument_list|,
literal|"fillColor"
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
name|lightningBlink
operator|->
name|assignProperty
argument_list|(
name|m_stickMan
argument_list|,
literal|"isDead"
argument_list|,
literal|true
argument_list|)
expr_stmt|;
comment|//! [5]
name|QTimer
modifier|*
name|timer
init|=
operator|new
name|QTimer
argument_list|(
name|lightningBlink
argument_list|)
decl_stmt|;
name|timer
operator|->
name|setSingleShot
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|timer
operator|->
name|setInterval
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|lightningBlink
argument_list|,
name|SIGNAL
argument_list|(
name|entered
argument_list|()
argument_list|)
argument_list|,
name|timer
argument_list|,
name|SLOT
argument_list|(
name|start
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|lightningBlink
argument_list|,
name|SIGNAL
argument_list|(
name|exited
argument_list|()
argument_list|)
argument_list|,
name|timer
argument_list|,
name|SLOT
argument_list|(
name|stop
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [5]
name|m_dead
operator|=
operator|new
name|QState
argument_list|(
name|m_machine
argument_list|)
expr_stmt|;
name|m_dead
operator|->
name|assignProperty
argument_list|(
name|m_stickMan
operator|->
name|scene
argument_list|()
argument_list|,
literal|"backgroundBrush"
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
argument_list|)
expr_stmt|;
name|m_dead
operator|->
name|assignProperty
argument_list|(
name|m_stickMan
argument_list|,
literal|"penColor"
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
name|m_dead
operator|->
name|assignProperty
argument_list|(
name|m_stickMan
argument_list|,
literal|"fillColor"
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
argument_list|)
expr_stmt|;
name|m_dead
operator|->
name|setObjectName
argument_list|(
literal|"dead"
argument_list|)
expr_stmt|;
comment|// Idle state (sets no properties)
name|m_idle
operator|=
operator|new
name|QState
argument_list|(
name|m_alive
argument_list|)
expr_stmt|;
name|m_idle
operator|->
name|setObjectName
argument_list|(
literal|"idle"
argument_list|)
expr_stmt|;
name|m_alive
operator|->
name|setInitialState
argument_list|(
name|m_idle
argument_list|)
expr_stmt|;
comment|// Lightning strikes at random
name|m_alive
operator|->
name|addTransition
argument_list|(
operator|new
name|LightningStrikesTransition
argument_list|(
name|lightningBlink
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [0]
name|lightningBlink
operator|->
name|addTransition
argument_list|(
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|m_dead
argument_list|)
expr_stmt|;
comment|//! [0]
name|m_machine
operator|->
name|setInitialState
argument_list|(
name|m_alive
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setDeathAnimation
name|void
name|LifeCycle
operator|::
name|setDeathAnimation
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QState
modifier|*
name|deathAnimation
init|=
name|makeState
argument_list|(
name|m_dead
argument_list|,
name|fileName
argument_list|)
decl_stmt|;
name|m_dead
operator|->
name|setInitialState
argument_list|(
name|deathAnimation
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|start
name|void
name|LifeCycle
operator|::
name|start
parameter_list|()
block|{
name|m_machine
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addActivity
name|void
name|LifeCycle
operator|::
name|addActivity
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|Qt
operator|::
name|Key
name|key
parameter_list|,
name|QObject
modifier|*
name|sender
parameter_list|,
specifier|const
name|char
modifier|*
name|signal
parameter_list|)
block|{
name|QState
modifier|*
name|state
init|=
name|makeState
argument_list|(
name|m_alive
argument_list|,
name|fileName
argument_list|)
decl_stmt|;
name|m_alive
operator|->
name|addTransition
argument_list|(
operator|new
name|KeyPressTransition
argument_list|(
name|m_keyReceiver
argument_list|,
name|key
argument_list|,
name|state
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|sender
operator|!=
name|NULL
operator|)
operator|||
operator|(
name|signal
operator|!=
name|NULL
operator|)
condition|)
block|{
name|m_alive
operator|->
name|addTransition
argument_list|(
name|sender
argument_list|,
name|signal
argument_list|,
name|state
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|makeState
name|QState
modifier|*
name|LifeCycle
operator|::
name|makeState
parameter_list|(
name|QState
modifier|*
name|parentState
parameter_list|,
specifier|const
name|QString
modifier|&
name|animationFileName
parameter_list|)
block|{
name|QState
modifier|*
name|topLevel
init|=
operator|new
name|QState
argument_list|(
name|parentState
argument_list|)
decl_stmt|;
name|Animation
name|animation
decl_stmt|;
block|{
name|QFile
name|file
argument_list|(
name|animationFileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
name|animation
operator|.
name|load
argument_list|(
operator|&
name|file
argument_list|)
expr_stmt|;
block|}
specifier|const
name|int
name|frameCount
init|=
name|animation
operator|.
name|totalFrames
argument_list|()
decl_stmt|;
name|QState
modifier|*
name|previousState
init|=
literal|0
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
name|frameCount
condition|;
operator|++
name|i
control|)
block|{
name|animation
operator|.
name|setCurrentFrame
argument_list|(
name|i
argument_list|)
expr_stmt|;
comment|//! [1]
name|QState
modifier|*
name|frameState
init|=
operator|new
name|QState
argument_list|(
name|topLevel
argument_list|)
decl_stmt|;
specifier|const
name|int
name|nodeCount
init|=
name|animation
operator|.
name|nodeCount
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|nodeCount
condition|;
operator|++
name|j
control|)
name|frameState
operator|->
name|assignProperty
argument_list|(
name|m_stickMan
operator|->
name|node
argument_list|(
name|j
argument_list|)
argument_list|,
literal|"pos"
argument_list|,
name|animation
operator|.
name|nodePos
argument_list|(
name|j
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [1]
name|frameState
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"frame %0"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|previousState
operator|==
literal|0
condition|)
name|topLevel
operator|->
name|setInitialState
argument_list|(
name|frameState
argument_list|)
expr_stmt|;
else|else
comment|//! [2]
name|previousState
operator|->
name|addTransition
argument_list|(
name|previousState
argument_list|,
name|SIGNAL
argument_list|(
name|propertiesAssigned
argument_list|()
argument_list|)
argument_list|,
name|frameState
argument_list|)
expr_stmt|;
comment|//! [2]
name|previousState
operator|=
name|frameState
expr_stmt|;
block|}
comment|// Loop
name|previousState
operator|->
name|addTransition
argument_list|(
name|previousState
argument_list|,
name|SIGNAL
argument_list|(
name|propertiesAssigned
argument_list|()
argument_list|)
argument_list|,
name|topLevel
operator|->
name|initialState
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|topLevel
return|;
block|}
end_function
begin_destructor
DECL|function|~LifeCycle
name|LifeCycle
operator|::
name|~
name|LifeCycle
parameter_list|()
block|{
operator|delete
name|m_machine
expr_stmt|;
operator|delete
name|m_animationGroup
expr_stmt|;
block|}
end_destructor
end_unit
