begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_comment
comment|//! [0]
end_comment
begin_class
DECL|class|LightWidget
class|class
name|LightWidget
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_PROPERTY
parameter_list|(
name|bool
name|on
name|READ
name|isOn
name|WRITE
name|setOn
parameter_list|)
specifier|public
private|:
DECL|function|LightWidget
name|LightWidget
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|,
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_color
argument_list|(
name|color
argument_list|)
member_init_list|,
name|m_on
argument_list|(
literal|false
argument_list|)
block|{}
DECL|function|isOn
name|bool
name|isOn
parameter_list|()
specifier|const
block|{
return|return
name|m_on
return|;
block|}
DECL|function|setOn
name|void
name|setOn
parameter_list|(
name|bool
name|on
parameter_list|)
block|{
if|if
condition|(
name|on
operator|==
name|m_on
condition|)
return|return;
name|m_on
operator|=
name|on
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
public|public
name|slots
public|:
DECL|function|turnOff
name|void
name|turnOff
parameter_list|()
block|{
name|setOn
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
DECL|function|turnOn
name|void
name|turnOn
parameter_list|()
block|{
name|setOn
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
protected|protected:
DECL|function|paintEvent
specifier|virtual
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_on
condition|)
return|return;
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setBrush
argument_list|(
name|m_color
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawEllipse
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
private|private:
DECL|member|m_color
name|QColor
name|m_color
decl_stmt|;
DECL|member|m_on
name|bool
name|m_on
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_class
DECL|class|TrafficLightWidget
class|class
name|TrafficLightWidget
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|function|TrafficLightWidget
name|TrafficLightWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|QVBoxLayout
modifier|*
name|vbox
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_MAEMO_5
name|vbox
operator|->
name|setContentsMargins
argument_list|(
literal|320
argument_list|,
literal|0
argument_list|,
literal|320
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|m_red
operator|=
operator|new
name|LightWidget
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|m_red
argument_list|)
expr_stmt|;
name|m_yellow
operator|=
operator|new
name|LightWidget
argument_list|(
name|Qt
operator|::
name|yellow
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|m_yellow
argument_list|)
expr_stmt|;
name|m_green
operator|=
operator|new
name|LightWidget
argument_list|(
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|m_green
argument_list|)
expr_stmt|;
name|QPalette
name|pal
init|=
name|palette
argument_list|()
decl_stmt|;
name|pal
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Background
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|setPalette
argument_list|(
name|pal
argument_list|)
expr_stmt|;
name|setAutoFillBackground
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
DECL|function|redLight
name|LightWidget
modifier|*
name|redLight
parameter_list|()
specifier|const
block|{
return|return
name|m_red
return|;
block|}
DECL|function|yellowLight
name|LightWidget
modifier|*
name|yellowLight
parameter_list|()
specifier|const
block|{
return|return
name|m_yellow
return|;
block|}
DECL|function|greenLight
name|LightWidget
modifier|*
name|greenLight
parameter_list|()
specifier|const
block|{
return|return
name|m_green
return|;
block|}
private|private:
DECL|member|m_red
name|LightWidget
modifier|*
name|m_red
decl_stmt|;
DECL|member|m_yellow
name|LightWidget
modifier|*
name|m_yellow
decl_stmt|;
DECL|member|m_green
name|LightWidget
modifier|*
name|m_green
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|createLightState
name|QState
modifier|*
name|createLightState
parameter_list|(
name|LightWidget
modifier|*
name|light
parameter_list|,
name|int
name|duration
parameter_list|,
name|QState
modifier|*
name|parent
init|=
literal|0
parameter_list|)
block|{
name|QState
modifier|*
name|lightState
init|=
operator|new
name|QState
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|QTimer
modifier|*
name|timer
init|=
operator|new
name|QTimer
argument_list|(
name|lightState
argument_list|)
decl_stmt|;
name|timer
operator|->
name|setInterval
argument_list|(
name|duration
argument_list|)
expr_stmt|;
name|timer
operator|->
name|setSingleShot
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|timing
init|=
operator|new
name|QState
argument_list|(
name|lightState
argument_list|)
decl_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|timing
argument_list|,
name|SIGNAL
argument_list|(
name|entered
argument_list|()
argument_list|)
argument_list|,
name|light
argument_list|,
name|SLOT
argument_list|(
name|turnOn
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|timing
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
name|timing
argument_list|,
name|SIGNAL
argument_list|(
name|exited
argument_list|()
argument_list|)
argument_list|,
name|light
argument_list|,
name|SLOT
argument_list|(
name|turnOff
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QFinalState
modifier|*
name|done
init|=
operator|new
name|QFinalState
argument_list|(
name|lightState
argument_list|)
decl_stmt|;
name|timing
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
name|done
argument_list|)
expr_stmt|;
name|lightState
operator|->
name|setInitialState
argument_list|(
name|timing
argument_list|)
expr_stmt|;
return|return
name|lightState
return|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_class
DECL|class|TrafficLight
class|class
name|TrafficLight
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|function|TrafficLight
name|TrafficLight
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|QVBoxLayout
modifier|*
name|vbox
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|TrafficLightWidget
modifier|*
name|widget
init|=
operator|new
name|TrafficLightWidget
argument_list|()
decl_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|setMargin
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QStateMachine
modifier|*
name|machine
init|=
operator|new
name|QStateMachine
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QState
modifier|*
name|redGoingYellow
init|=
name|createLightState
argument_list|(
name|widget
operator|->
name|redLight
argument_list|()
argument_list|,
literal|3000
argument_list|)
decl_stmt|;
name|redGoingYellow
operator|->
name|setObjectName
argument_list|(
literal|"redGoingYellow"
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|yellowGoingGreen
init|=
name|createLightState
argument_list|(
name|widget
operator|->
name|yellowLight
argument_list|()
argument_list|,
literal|1000
argument_list|)
decl_stmt|;
name|yellowGoingGreen
operator|->
name|setObjectName
argument_list|(
literal|"yellowGoingGreen"
argument_list|)
expr_stmt|;
name|redGoingYellow
operator|->
name|addTransition
argument_list|(
name|redGoingYellow
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|yellowGoingGreen
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|greenGoingYellow
init|=
name|createLightState
argument_list|(
name|widget
operator|->
name|greenLight
argument_list|()
argument_list|,
literal|3000
argument_list|)
decl_stmt|;
name|greenGoingYellow
operator|->
name|setObjectName
argument_list|(
literal|"greenGoingYellow"
argument_list|)
expr_stmt|;
name|yellowGoingGreen
operator|->
name|addTransition
argument_list|(
name|yellowGoingGreen
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|greenGoingYellow
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|yellowGoingRed
init|=
name|createLightState
argument_list|(
name|widget
operator|->
name|yellowLight
argument_list|()
argument_list|,
literal|1000
argument_list|)
decl_stmt|;
name|yellowGoingRed
operator|->
name|setObjectName
argument_list|(
literal|"yellowGoingRed"
argument_list|)
expr_stmt|;
name|greenGoingYellow
operator|->
name|addTransition
argument_list|(
name|greenGoingYellow
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|yellowGoingRed
argument_list|)
expr_stmt|;
name|yellowGoingRed
operator|->
name|addTransition
argument_list|(
name|yellowGoingRed
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|redGoingYellow
argument_list|)
expr_stmt|;
name|machine
operator|->
name|addState
argument_list|(
name|redGoingYellow
argument_list|)
expr_stmt|;
name|machine
operator|->
name|addState
argument_list|(
name|yellowGoingGreen
argument_list|)
expr_stmt|;
name|machine
operator|->
name|addState
argument_list|(
name|greenGoingYellow
argument_list|)
expr_stmt|;
name|machine
operator|->
name|addState
argument_list|(
name|yellowGoingRed
argument_list|)
expr_stmt|;
name|machine
operator|->
name|setInitialState
argument_list|(
name|redGoingYellow
argument_list|)
expr_stmt|;
name|machine
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|TrafficLight
name|widget
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|widget
operator|.
name|showMaximized
argument_list|()
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_MAEMO_5
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_SIMULATOR
argument_list|)
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
else|#
directive|else
name|widget
operator|.
name|resize
argument_list|(
literal|110
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
