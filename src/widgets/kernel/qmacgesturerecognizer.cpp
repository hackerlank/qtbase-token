begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qmacgesturerecognizer_p.h"
end_include
begin_include
include|#
directive|include
file|"qgesture.h"
end_include
begin_include
include|#
directive|include
file|"qgesture_p.h"
end_include
begin_include
include|#
directive|include
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"qwidget.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QMacSwipeGestureRecognizer
name|QMacSwipeGestureRecognizer
operator|::
name|QMacSwipeGestureRecognizer
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|create
name|QGesture
modifier|*
name|QMacSwipeGestureRecognizer
operator|::
name|create
parameter_list|(
name|QObject
modifier|*
comment|/*target*/
parameter_list|)
block|{
return|return
operator|new
name|QSwipeGesture
return|;
block|}
end_function
begin_function
name|QGestureRecognizer
operator|::
name|Result
DECL|function|recognize
name|QMacSwipeGestureRecognizer
operator|::
name|recognize
parameter_list|(
name|QGesture
modifier|*
name|gesture
parameter_list|,
name|QObject
modifier|*
name|obj
parameter_list|,
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
name|NativeGesture
operator|&&
name|obj
operator|->
name|isWidgetType
argument_list|()
condition|)
block|{
name|QNativeGestureEvent
modifier|*
name|ev
init|=
cast|static_cast
argument_list|<
name|QNativeGestureEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|ev
operator|->
name|gestureType
argument_list|()
condition|)
block|{
case|case
name|Qt
operator|::
name|SwipeNativeGesture
case|:
block|{
name|QSwipeGesture
modifier|*
name|g
init|=
cast|static_cast
argument_list|<
name|QSwipeGesture
operator|*
argument_list|>
argument_list|(
name|gesture
argument_list|)
decl_stmt|;
name|g
operator|->
name|setSwipeAngle
argument_list|(
name|ev
operator|->
name|value
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setHotSpot
argument_list|(
name|ev
operator|->
name|screenPos
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|QGestureRecognizer
operator|::
name|FinishGesture
operator||
name|QGestureRecognizer
operator|::
name|ConsumeEventHint
return|;
break|break;
block|}
default|default:
break|break;
block|}
block|}
return|return
name|QGestureRecognizer
operator|::
name|Ignore
return|;
block|}
end_function
begin_function
DECL|function|reset
name|void
name|QMacSwipeGestureRecognizer
operator|::
name|reset
parameter_list|(
name|QGesture
modifier|*
name|gesture
parameter_list|)
block|{
name|QSwipeGesture
modifier|*
name|g
init|=
cast|static_cast
argument_list|<
name|QSwipeGesture
operator|*
argument_list|>
argument_list|(
name|gesture
argument_list|)
decl_stmt|;
name|g
operator|->
name|setSwipeAngle
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QGestureRecognizer
operator|::
name|reset
argument_list|(
name|gesture
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|////////////////////////////////////////////////////////////////////////
end_comment
begin_constructor
DECL|function|QMacPinchGestureRecognizer
name|QMacPinchGestureRecognizer
operator|::
name|QMacPinchGestureRecognizer
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|create
name|QGesture
modifier|*
name|QMacPinchGestureRecognizer
operator|::
name|create
parameter_list|(
name|QObject
modifier|*
comment|/*target*/
parameter_list|)
block|{
return|return
operator|new
name|QPinchGesture
return|;
block|}
end_function
begin_function
name|QGestureRecognizer
operator|::
name|Result
DECL|function|recognize
name|QMacPinchGestureRecognizer
operator|::
name|recognize
parameter_list|(
name|QGesture
modifier|*
name|gesture
parameter_list|,
name|QObject
modifier|*
name|obj
parameter_list|,
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
name|NativeGesture
operator|&&
name|obj
operator|->
name|isWidgetType
argument_list|()
condition|)
block|{
name|QPinchGesture
modifier|*
name|g
init|=
cast|static_cast
argument_list|<
name|QPinchGesture
operator|*
argument_list|>
argument_list|(
name|gesture
argument_list|)
decl_stmt|;
name|QNativeGestureEvent
modifier|*
name|ev
init|=
cast|static_cast
argument_list|<
name|QNativeGestureEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|ev
operator|->
name|gestureType
argument_list|()
condition|)
block|{
case|case
name|Qt
operator|::
name|BeginNativeGesture
case|:
name|reset
argument_list|(
name|gesture
argument_list|)
expr_stmt|;
name|g
operator|->
name|setStartCenterPoint
argument_list|(
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|obj
argument_list|)
operator|->
name|mapFromGlobal
argument_list|(
name|ev
operator|->
name|screenPos
argument_list|()
operator|.
name|toPoint
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|g
operator|->
name|setCenterPoint
argument_list|(
name|g
operator|->
name|startCenterPoint
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setChangeFlags
argument_list|(
name|QPinchGesture
operator|::
name|CenterPointChanged
argument_list|)
expr_stmt|;
name|g
operator|->
name|setTotalChangeFlags
argument_list|(
name|g
operator|->
name|totalChangeFlags
argument_list|()
operator||
name|g
operator|->
name|changeFlags
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setHotSpot
argument_list|(
name|ev
operator|->
name|screenPos
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|QGestureRecognizer
operator|::
name|MayBeGesture
operator||
name|QGestureRecognizer
operator|::
name|ConsumeEventHint
return|;
case|case
name|Qt
operator|::
name|RotateNativeGesture
case|:
name|g
operator|->
name|setLastScaleFactor
argument_list|(
name|g
operator|->
name|scaleFactor
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setLastRotationAngle
argument_list|(
name|g
operator|->
name|rotationAngle
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setRotationAngle
argument_list|(
name|g
operator|->
name|rotationAngle
argument_list|()
operator|+
name|ev
operator|->
name|value
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setChangeFlags
argument_list|(
name|QPinchGesture
operator|::
name|RotationAngleChanged
argument_list|)
expr_stmt|;
name|g
operator|->
name|setTotalChangeFlags
argument_list|(
name|g
operator|->
name|totalChangeFlags
argument_list|()
operator||
name|g
operator|->
name|changeFlags
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setHotSpot
argument_list|(
name|ev
operator|->
name|screenPos
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|QGestureRecognizer
operator|::
name|TriggerGesture
operator||
name|QGestureRecognizer
operator|::
name|ConsumeEventHint
return|;
case|case
name|Qt
operator|::
name|ZoomNativeGesture
case|:
name|g
operator|->
name|setLastScaleFactor
argument_list|(
name|g
operator|->
name|scaleFactor
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setLastRotationAngle
argument_list|(
name|g
operator|->
name|rotationAngle
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setScaleFactor
argument_list|(
name|g
operator|->
name|scaleFactor
argument_list|()
operator|*
operator|(
literal|1
operator|+
name|ev
operator|->
name|value
argument_list|()
operator|)
argument_list|)
expr_stmt|;
name|g
operator|->
name|setChangeFlags
argument_list|(
name|QPinchGesture
operator|::
name|ScaleFactorChanged
argument_list|)
expr_stmt|;
name|g
operator|->
name|setTotalChangeFlags
argument_list|(
name|g
operator|->
name|totalChangeFlags
argument_list|()
operator||
name|g
operator|->
name|changeFlags
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setHotSpot
argument_list|(
name|ev
operator|->
name|screenPos
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|QGestureRecognizer
operator|::
name|TriggerGesture
operator||
name|QGestureRecognizer
operator|::
name|ConsumeEventHint
return|;
case|case
name|Qt
operator|::
name|SmartZoomNativeGesture
case|:
name|g
operator|->
name|setLastScaleFactor
argument_list|(
name|g
operator|->
name|scaleFactor
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setLastRotationAngle
argument_list|(
name|g
operator|->
name|rotationAngle
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setScaleFactor
argument_list|(
name|ev
operator|->
name|value
argument_list|()
condition|?
literal|1.7f
else|:
literal|1.0f
argument_list|)
expr_stmt|;
name|g
operator|->
name|setChangeFlags
argument_list|(
name|QPinchGesture
operator|::
name|ScaleFactorChanged
argument_list|)
expr_stmt|;
name|g
operator|->
name|setTotalChangeFlags
argument_list|(
name|g
operator|->
name|totalChangeFlags
argument_list|()
operator||
name|g
operator|->
name|changeFlags
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setHotSpot
argument_list|(
name|ev
operator|->
name|screenPos
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|QGestureRecognizer
operator|::
name|TriggerGesture
operator||
name|QGestureRecognizer
operator|::
name|ConsumeEventHint
return|;
case|case
name|Qt
operator|::
name|EndNativeGesture
case|:
return|return
name|QGestureRecognizer
operator|::
name|FinishGesture
operator||
name|QGestureRecognizer
operator|::
name|ConsumeEventHint
return|;
default|default:
break|break;
block|}
block|}
return|return
name|QGestureRecognizer
operator|::
name|Ignore
return|;
block|}
end_function
begin_function
DECL|function|reset
name|void
name|QMacPinchGestureRecognizer
operator|::
name|reset
parameter_list|(
name|QGesture
modifier|*
name|gesture
parameter_list|)
block|{
name|QPinchGesture
modifier|*
name|g
init|=
cast|static_cast
argument_list|<
name|QPinchGesture
operator|*
argument_list|>
argument_list|(
name|gesture
argument_list|)
decl_stmt|;
name|g
operator|->
name|setChangeFlags
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|g
operator|->
name|setTotalChangeFlags
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|g
operator|->
name|setScaleFactor
argument_list|(
literal|1.0f
argument_list|)
expr_stmt|;
name|g
operator|->
name|setTotalScaleFactor
argument_list|(
literal|1.0f
argument_list|)
expr_stmt|;
name|g
operator|->
name|setLastScaleFactor
argument_list|(
literal|1.0f
argument_list|)
expr_stmt|;
name|g
operator|->
name|setRotationAngle
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
name|g
operator|->
name|setTotalRotationAngle
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
name|g
operator|->
name|setLastRotationAngle
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
name|g
operator|->
name|setCenterPoint
argument_list|(
name|QPointF
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setStartCenterPoint
argument_list|(
name|QPointF
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setLastCenterPoint
argument_list|(
name|QPointF
argument_list|()
argument_list|)
expr_stmt|;
name|QGestureRecognizer
operator|::
name|reset
argument_list|(
name|gesture
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|////////////////////////////////////////////////////////////////////////
end_comment
begin_constructor
DECL|function|QMacPanGestureRecognizer
name|QMacPanGestureRecognizer
operator|::
name|QMacPanGestureRecognizer
parameter_list|()
member_init_list|:
name|_panCanceled
argument_list|(
literal|true
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|create
name|QGesture
modifier|*
name|QMacPanGestureRecognizer
operator|::
name|create
parameter_list|(
name|QObject
modifier|*
name|target
parameter_list|)
block|{
if|if
condition|(
operator|!
name|target
condition|)
return|return
operator|new
name|QPanGesture
return|;
if|if
condition|(
name|QWidget
modifier|*
name|w
init|=
name|qobject_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|target
argument_list|)
condition|)
block|{
name|w
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_AcceptTouchEvents
argument_list|)
expr_stmt|;
name|w
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_TouchPadAcceptSingleTouchEvents
argument_list|)
expr_stmt|;
return|return
operator|new
name|QPanGesture
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
name|QGestureRecognizer
operator|::
name|Result
DECL|function|recognize
name|QMacPanGestureRecognizer
operator|::
name|recognize
parameter_list|(
name|QGesture
modifier|*
name|gesture
parameter_list|,
name|QObject
modifier|*
name|target
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
specifier|const
name|int
name|panBeginDelay
init|=
literal|300
decl_stmt|;
specifier|const
name|int
name|panBeginRadius
init|=
literal|3
decl_stmt|;
name|QPanGesture
modifier|*
name|g
init|=
cast|static_cast
argument_list|<
name|QPanGesture
operator|*
argument_list|>
argument_list|(
name|gesture
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|event
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|TouchBegin
case|:
block|{
specifier|const
name|QTouchEvent
modifier|*
name|ev
init|=
cast|static_cast
argument_list|<
specifier|const
name|QTouchEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
if|if
condition|(
name|ev
operator|->
name|touchPoints
argument_list|()
operator|.
name|size
argument_list|()
operator|==
literal|1
condition|)
block|{
name|reset
argument_list|(
name|gesture
argument_list|)
expr_stmt|;
name|_startPos
operator|=
name|QCursor
operator|::
name|pos
argument_list|()
expr_stmt|;
name|_panTimer
operator|.
name|start
argument_list|(
name|panBeginDelay
argument_list|,
name|target
argument_list|)
expr_stmt|;
name|_panCanceled
operator|=
literal|false
expr_stmt|;
return|return
name|QGestureRecognizer
operator|::
name|MayBeGesture
return|;
block|}
break|break;
block|}
case|case
name|QEvent
operator|::
name|TouchEnd
case|:
block|{
if|if
condition|(
name|_panCanceled
condition|)
break|break;
specifier|const
name|QTouchEvent
modifier|*
name|ev
init|=
cast|static_cast
argument_list|<
specifier|const
name|QTouchEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
if|if
condition|(
name|ev
operator|->
name|touchPoints
argument_list|()
operator|.
name|size
argument_list|()
operator|==
literal|1
condition|)
return|return
name|QGestureRecognizer
operator|::
name|FinishGesture
return|;
break|break;
block|}
case|case
name|QEvent
operator|::
name|TouchUpdate
case|:
block|{
if|if
condition|(
name|_panCanceled
condition|)
break|break;
specifier|const
name|QTouchEvent
modifier|*
name|ev
init|=
cast|static_cast
argument_list|<
specifier|const
name|QTouchEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
if|if
condition|(
name|ev
operator|->
name|touchPoints
argument_list|()
operator|.
name|size
argument_list|()
operator|==
literal|1
condition|)
block|{
if|if
condition|(
name|_panTimer
operator|.
name|isActive
argument_list|()
condition|)
block|{
comment|// INVARIANT: Still in maybeGesture. Check if the user
comment|// moved his finger so much that it makes sense to cancel the pan:
specifier|const
name|QPointF
name|p
init|=
name|QCursor
operator|::
name|pos
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|p
operator|-
name|_startPos
operator|)
operator|.
name|manhattanLength
argument_list|()
operator|>
name|panBeginRadius
condition|)
block|{
name|_panCanceled
operator|=
literal|true
expr_stmt|;
name|_panTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
return|return
name|QGestureRecognizer
operator|::
name|CancelGesture
return|;
block|}
block|}
else|else
block|{
specifier|const
name|QPointF
name|p
init|=
name|QCursor
operator|::
name|pos
argument_list|()
decl_stmt|;
specifier|const
name|QPointF
name|posOffset
init|=
name|p
operator|-
name|_startPos
decl_stmt|;
name|g
operator|->
name|setLastOffset
argument_list|(
name|g
operator|->
name|offset
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setOffset
argument_list|(
name|QPointF
argument_list|(
name|posOffset
operator|.
name|x
argument_list|()
argument_list|,
name|posOffset
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|g
operator|->
name|setHotSpot
argument_list|(
name|_startPos
argument_list|)
expr_stmt|;
return|return
name|QGestureRecognizer
operator|::
name|TriggerGesture
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|_panTimer
operator|.
name|isActive
argument_list|()
condition|)
block|{
comment|// I only want to cancel the pan if the user is pressing
comment|// more than one finger, and the pan hasn't started yet:
name|_panCanceled
operator|=
literal|true
expr_stmt|;
name|_panTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
return|return
name|QGestureRecognizer
operator|::
name|CancelGesture
return|;
block|}
break|break;
block|}
case|case
name|QEvent
operator|::
name|Timer
case|:
block|{
name|QTimerEvent
modifier|*
name|ev
init|=
cast|static_cast
argument_list|<
name|QTimerEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
if|if
condition|(
name|ev
operator|->
name|timerId
argument_list|()
operator|==
name|_panTimer
operator|.
name|timerId
argument_list|()
condition|)
block|{
name|_panTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
if|if
condition|(
name|_panCanceled
condition|)
break|break;
comment|// Begin new pan session!
name|_startPos
operator|=
name|QCursor
operator|::
name|pos
argument_list|()
expr_stmt|;
name|g
operator|->
name|setHotSpot
argument_list|(
name|_startPos
argument_list|)
expr_stmt|;
return|return
name|QGestureRecognizer
operator|::
name|TriggerGesture
operator||
name|QGestureRecognizer
operator|::
name|ConsumeEventHint
return|;
block|}
break|break;
block|}
default|default:
break|break;
block|}
return|return
name|QGestureRecognizer
operator|::
name|Ignore
return|;
block|}
end_function
begin_function
DECL|function|reset
name|void
name|QMacPanGestureRecognizer
operator|::
name|reset
parameter_list|(
name|QGesture
modifier|*
name|gesture
parameter_list|)
block|{
name|QPanGesture
modifier|*
name|g
init|=
cast|static_cast
argument_list|<
name|QPanGesture
operator|*
argument_list|>
argument_list|(
name|gesture
argument_list|)
decl_stmt|;
name|_startPos
operator|=
name|QPointF
argument_list|()
expr_stmt|;
name|_panCanceled
operator|=
literal|true
expr_stmt|;
name|g
operator|->
name|setOffset
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|g
operator|->
name|setLastOffset
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|g
operator|->
name|setAcceleration
argument_list|(
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QGestureRecognizer
operator|::
name|reset
argument_list|(
name|gesture
argument_list|)
expr_stmt|;
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
comment|// QT_NO_GESTURES
end_comment
end_unit
