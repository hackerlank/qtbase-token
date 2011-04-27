begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"mousepangesturerecognizer.h"
end_include
begin_class
DECL|class|ScrollArea
class|class
name|ScrollArea
super|:
specifier|public
name|QScrollArea
block|{
name|Q_OBJECT
public|public:
DECL|function|ScrollArea
name|ScrollArea
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QScrollArea
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|outside
argument_list|(
literal|false
argument_list|)
block|{
name|viewport
argument_list|()
operator|->
name|grabGesture
argument_list|(
name|Qt
operator|::
name|PanGesture
argument_list|,
name|Qt
operator|::
name|ReceivePartialGestures
argument_list|)
expr_stmt|;
block|}
protected|protected:
DECL|function|viewportEvent
name|bool
name|viewportEvent
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|Gesture
condition|)
block|{
name|gestureEvent
argument_list|(
cast|static_cast
argument_list|<
name|QGestureEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
elseif|else
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|GestureOverride
condition|)
block|{
name|QGestureEvent
modifier|*
name|ge
init|=
cast|static_cast
argument_list|<
name|QGestureEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
if|if
condition|(
name|QPanGesture
modifier|*
name|pan
init|=
cast|static_cast
argument_list|<
name|QPanGesture
operator|*
argument_list|>
argument_list|(
name|ge
operator|->
name|gesture
argument_list|(
name|Qt
operator|::
name|PanGesture
argument_list|)
argument_list|)
condition|)
if|if
condition|(
name|pan
operator|->
name|state
argument_list|()
operator|==
name|Qt
operator|::
name|GestureStarted
condition|)
block|{
name|outside
operator|=
literal|false
expr_stmt|;
block|}
block|}
return|return
name|QScrollArea
operator|::
name|viewportEvent
argument_list|(
name|event
argument_list|)
return|;
block|}
DECL|function|gestureEvent
name|void
name|gestureEvent
parameter_list|(
name|QGestureEvent
modifier|*
name|event
parameter_list|)
block|{
name|QPanGesture
modifier|*
name|pan
init|=
cast|static_cast
argument_list|<
name|QPanGesture
operator|*
argument_list|>
argument_list|(
name|event
operator|->
name|gesture
argument_list|(
name|Qt
operator|::
name|PanGesture
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|pan
condition|)
block|{
switch|switch
condition|(
name|pan
operator|->
name|state
argument_list|()
condition|)
block|{
case|case
name|Qt
operator|::
name|GestureStarted
case|:
name|qDebug
argument_list|()
operator|<<
name|this
operator|<<
literal|"Pan: started"
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|GestureFinished
case|:
name|qDebug
argument_list|()
operator|<<
name|this
operator|<<
literal|"Pan: finished"
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|GestureCanceled
case|:
name|qDebug
argument_list|()
operator|<<
name|this
operator|<<
literal|"Pan: canceled"
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|GestureUpdated
case|:
break|break;
default|default:
name|qDebug
argument_list|()
operator|<<
name|this
operator|<<
literal|"Pan:<unknown state>"
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|pan
operator|->
name|state
argument_list|()
operator|==
name|Qt
operator|::
name|GestureStarted
condition|)
name|outside
operator|=
literal|false
expr_stmt|;
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
name|event
operator|->
name|ignore
argument_list|(
name|pan
argument_list|)
expr_stmt|;
if|if
condition|(
name|outside
condition|)
return|return;
specifier|const
name|QPointF
name|delta
init|=
name|pan
operator|->
name|delta
argument_list|()
decl_stmt|;
specifier|const
name|QPointF
name|totalOffset
init|=
name|pan
operator|->
name|offset
argument_list|()
decl_stmt|;
name|QScrollBar
modifier|*
name|vbar
init|=
name|verticalScrollBar
argument_list|()
decl_stmt|;
name|QScrollBar
modifier|*
name|hbar
init|=
name|horizontalScrollBar
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|vbar
operator|->
name|value
argument_list|()
operator|==
name|vbar
operator|->
name|minimum
argument_list|()
operator|&&
name|totalOffset
operator|.
name|y
argument_list|()
operator|>
literal|10
operator|)
operator|||
operator|(
name|vbar
operator|->
name|value
argument_list|()
operator|==
name|vbar
operator|->
name|maximum
argument_list|()
operator|&&
name|totalOffset
operator|.
name|y
argument_list|()
operator|<
operator|-
literal|10
operator|)
condition|)
block|{
name|outside
operator|=
literal|true
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|(
name|hbar
operator|->
name|value
argument_list|()
operator|==
name|hbar
operator|->
name|minimum
argument_list|()
operator|&&
name|totalOffset
operator|.
name|x
argument_list|()
operator|>
literal|10
operator|)
operator|||
operator|(
name|hbar
operator|->
name|value
argument_list|()
operator|==
name|hbar
operator|->
name|maximum
argument_list|()
operator|&&
name|totalOffset
operator|.
name|x
argument_list|()
operator|<
operator|-
literal|10
operator|)
condition|)
block|{
name|outside
operator|=
literal|true
expr_stmt|;
return|return;
block|}
name|vbar
operator|->
name|setValue
argument_list|(
name|vbar
operator|->
name|value
argument_list|()
operator|-
name|delta
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|hbar
operator|->
name|setValue
argument_list|(
name|hbar
operator|->
name|value
argument_list|()
operator|-
name|delta
operator|.
name|x
argument_list|()
argument_list|)
expr_stmt|;
name|event
operator|->
name|accept
argument_list|(
name|pan
argument_list|)
expr_stmt|;
block|}
block|}
private|private:
DECL|member|outside
name|bool
name|outside
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|Slider
class|class
name|Slider
super|:
specifier|public
name|QSlider
block|{
public|public:
DECL|function|Slider
name|Slider
parameter_list|(
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|,
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QSlider
argument_list|(
name|orientation
argument_list|,
name|parent
argument_list|)
block|{
name|grabGesture
argument_list|(
name|Qt
operator|::
name|PanGesture
argument_list|)
expr_stmt|;
block|}
protected|protected:
DECL|function|event
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|Gesture
condition|)
block|{
name|gestureEvent
argument_list|(
cast|static_cast
argument_list|<
name|QGestureEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
name|QSlider
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
DECL|function|gestureEvent
name|void
name|gestureEvent
parameter_list|(
name|QGestureEvent
modifier|*
name|event
parameter_list|)
block|{
name|QPanGesture
modifier|*
name|pan
init|=
cast|static_cast
argument_list|<
name|QPanGesture
operator|*
argument_list|>
argument_list|(
name|event
operator|->
name|gesture
argument_list|(
name|Qt
operator|::
name|PanGesture
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|pan
condition|)
block|{
switch|switch
condition|(
name|pan
operator|->
name|state
argument_list|()
condition|)
block|{
case|case
name|Qt
operator|::
name|GestureStarted
case|:
name|qDebug
argument_list|()
operator|<<
name|this
operator|<<
literal|"Pan: started"
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|GestureFinished
case|:
name|qDebug
argument_list|()
operator|<<
name|this
operator|<<
literal|"Pan: finished"
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|GestureCanceled
case|:
name|qDebug
argument_list|()
operator|<<
name|this
operator|<<
literal|"Pan: canceled"
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|GestureUpdated
case|:
break|break;
default|default:
name|qDebug
argument_list|()
operator|<<
name|this
operator|<<
literal|"Pan:<unknown state>"
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|pan
operator|->
name|state
argument_list|()
operator|==
name|Qt
operator|::
name|GestureStarted
condition|)
name|outside
operator|=
literal|false
expr_stmt|;
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
name|event
operator|->
name|ignore
argument_list|(
name|pan
argument_list|)
expr_stmt|;
if|if
condition|(
name|outside
condition|)
return|return;
specifier|const
name|QPointF
name|delta
init|=
name|pan
operator|->
name|delta
argument_list|()
decl_stmt|;
specifier|const
name|QPointF
name|totalOffset
init|=
name|pan
operator|->
name|offset
argument_list|()
decl_stmt|;
if|if
condition|(
name|orientation
argument_list|()
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
block|{
if|if
condition|(
operator|(
name|value
argument_list|()
operator|==
name|minimum
argument_list|()
operator|&&
name|totalOffset
operator|.
name|x
argument_list|()
operator|<
operator|-
literal|10
operator|)
operator|||
operator|(
name|value
argument_list|()
operator|==
name|maximum
argument_list|()
operator|&&
name|totalOffset
operator|.
name|x
argument_list|()
operator|>
literal|10
operator|)
condition|)
block|{
name|outside
operator|=
literal|true
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|totalOffset
operator|.
name|y
argument_list|()
operator|<
literal|40
operator|&&
name|totalOffset
operator|.
name|y
argument_list|()
operator|>
operator|-
literal|40
condition|)
block|{
name|setValue
argument_list|(
name|value
argument_list|()
operator|+
name|delta
operator|.
name|x
argument_list|()
argument_list|)
expr_stmt|;
name|event
operator|->
name|accept
argument_list|(
name|pan
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|outside
operator|=
literal|true
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|orientation
argument_list|()
operator|==
name|Qt
operator|::
name|Vertical
condition|)
block|{
if|if
condition|(
operator|(
name|value
argument_list|()
operator|==
name|maximum
argument_list|()
operator|&&
name|totalOffset
operator|.
name|y
argument_list|()
operator|<
operator|-
literal|10
operator|)
operator|||
operator|(
name|value
argument_list|()
operator|==
name|minimum
argument_list|()
operator|&&
name|totalOffset
operator|.
name|y
argument_list|()
operator|>
literal|10
operator|)
condition|)
block|{
name|outside
operator|=
literal|true
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|totalOffset
operator|.
name|x
argument_list|()
operator|<
literal|40
operator|&&
name|totalOffset
operator|.
name|x
argument_list|()
operator|>
operator|-
literal|40
condition|)
block|{
name|setValue
argument_list|(
name|value
argument_list|()
operator|-
name|delta
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|event
operator|->
name|accept
argument_list|(
name|pan
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|outside
operator|=
literal|true
expr_stmt|;
block|}
block|}
block|}
block|}
private|private:
DECL|member|outside
name|bool
name|outside
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|MainWindow
class|class
name|MainWindow
super|:
specifier|public
name|QMainWindow
block|{
public|public:
DECL|function|MainWindow
name|MainWindow
parameter_list|()
block|{
name|rootScrollArea
operator|=
operator|new
name|ScrollArea
expr_stmt|;
name|rootScrollArea
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"rootScrollArea"
argument_list|)
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|rootScrollArea
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|root
init|=
operator|new
name|QWidget
decl_stmt|;
name|root
operator|->
name|setFixedSize
argument_list|(
literal|3000
argument_list|,
literal|3000
argument_list|)
expr_stmt|;
name|rootScrollArea
operator|->
name|setWidget
argument_list|(
name|root
argument_list|)
expr_stmt|;
name|Slider
modifier|*
name|verticalSlider
init|=
operator|new
name|Slider
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|,
name|root
argument_list|)
decl_stmt|;
name|verticalSlider
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"verticalSlider"
argument_list|)
argument_list|)
expr_stmt|;
name|verticalSlider
operator|->
name|move
argument_list|(
literal|650
argument_list|,
literal|1100
argument_list|)
expr_stmt|;
name|Slider
modifier|*
name|horizontalSlider
init|=
operator|new
name|Slider
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|,
name|root
argument_list|)
decl_stmt|;
name|horizontalSlider
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"horizontalSlider"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalSlider
operator|->
name|move
argument_list|(
literal|600
argument_list|,
literal|1000
argument_list|)
expr_stmt|;
name|childScrollArea
operator|=
operator|new
name|ScrollArea
argument_list|(
name|root
argument_list|)
expr_stmt|;
name|childScrollArea
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"childScrollArea"
argument_list|)
argument_list|)
expr_stmt|;
name|childScrollArea
operator|->
name|move
argument_list|(
literal|500
argument_list|,
literal|500
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|w
init|=
operator|new
name|QWidget
decl_stmt|;
name|w
operator|->
name|setMinimumWidth
argument_list|(
literal|700
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|l
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|w
argument_list|)
decl_stmt|;
name|l
operator|->
name|setMargin
argument_list|(
literal|20
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
literal|100
condition|;
operator|++
name|i
control|)
block|{
name|QWidget
modifier|*
name|w
init|=
operator|new
name|QWidget
decl_stmt|;
name|QHBoxLayout
modifier|*
name|ll
init|=
operator|new
name|QHBoxLayout
argument_list|(
name|w
argument_list|)
decl_stmt|;
name|ll
operator|->
name|addWidget
argument_list|(
operator|new
name|QLabel
argument_list|(
name|QString
argument_list|(
literal|"Label %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|ll
operator|->
name|addWidget
argument_list|(
operator|new
name|QPushButton
argument_list|(
name|QString
argument_list|(
literal|"Button %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
name|childScrollArea
operator|->
name|setWidget
argument_list|(
name|w
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
comment|// Windows can force Qt to create a native window handle for an
comment|// intermediate widget and that will block gesture to get touch events.
comment|// So this hack to make sure gestures get all touch events they need.
foreach|foreach
control|(
name|QObject
modifier|*
name|w
decl|,
name|children
argument_list|()
control|)
if|if
condition|(
name|w
operator|->
name|isWidgetType
argument_list|()
condition|)
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|w
argument_list|)
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_AcceptTouchEvents
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
private|private:
DECL|member|rootScrollArea
name|ScrollArea
modifier|*
name|rootScrollArea
decl_stmt|;
DECL|member|childScrollArea
name|ScrollArea
modifier|*
name|childScrollArea
decl_stmt|;
block|}
class|;
end_class
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
name|QGestureRecognizer
operator|::
name|registerRecognizer
argument_list|(
operator|new
name|MousePanGestureRecognizer
argument_list|)
expr_stmt|;
name|MainWindow
name|w
decl_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
