begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"flickable.h"
end_include
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_class
DECL|class|FlickableTicker
class|class
name|FlickableTicker
super|:
name|QObject
block|{
public|public:
DECL|function|FlickableTicker
name|FlickableTicker
parameter_list|(
name|Flickable
modifier|*
name|scroller
parameter_list|)
block|{
name|m_scroller
operator|=
name|scroller
expr_stmt|;
block|}
DECL|function|start
name|void
name|start
parameter_list|(
name|int
name|interval
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_timer
operator|.
name|isActive
argument_list|()
condition|)
name|m_timer
operator|.
name|start
argument_list|(
name|interval
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
DECL|function|stop
name|void
name|stop
parameter_list|()
block|{
name|m_timer
operator|.
name|stop
argument_list|()
expr_stmt|;
block|}
protected|protected:
DECL|function|timerEvent
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|m_scroller
operator|->
name|tick
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|member|m_scroller
name|Flickable
modifier|*
name|m_scroller
decl_stmt|;
DECL|member|m_timer
name|QBasicTimer
name|m_timer
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|FlickablePrivate
class|class
name|FlickablePrivate
block|{
public|public:
typedef|typedef
enum|enum
block|{
DECL|enumerator|Steady
name|Steady
block|,
DECL|enumerator|Pressed
name|Pressed
block|,
DECL|enumerator|ManualScroll
name|ManualScroll
block|,
DECL|enumerator|AutoScroll
name|AutoScroll
block|,
DECL|enumerator|Stop
name|Stop
block|}
DECL|typedef|State
name|State
typedef|;
DECL|member|state
name|State
name|state
decl_stmt|;
DECL|member|threshold
name|int
name|threshold
decl_stmt|;
DECL|member|pressPos
name|QPoint
name|pressPos
decl_stmt|;
DECL|member|offset
name|QPoint
name|offset
decl_stmt|;
DECL|member|delta
name|QPoint
name|delta
decl_stmt|;
DECL|member|speed
name|QPoint
name|speed
decl_stmt|;
DECL|member|ticker
name|FlickableTicker
modifier|*
name|ticker
decl_stmt|;
DECL|member|timeStamp
name|QTime
name|timeStamp
decl_stmt|;
DECL|member|target
name|QWidget
modifier|*
name|target
decl_stmt|;
DECL|member|ignoreList
name|QList
argument_list|<
name|QEvent
modifier|*
argument_list|>
name|ignoreList
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|Flickable
name|Flickable
operator|::
name|Flickable
parameter_list|()
block|{
name|d
operator|=
operator|new
name|FlickablePrivate
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|FlickablePrivate
operator|::
name|Steady
expr_stmt|;
name|d
operator|->
name|threshold
operator|=
literal|10
expr_stmt|;
name|d
operator|->
name|ticker
operator|=
operator|new
name|FlickableTicker
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|d
operator|->
name|timeStamp
operator|=
name|QTime
operator|::
name|currentTime
argument_list|()
expr_stmt|;
name|d
operator|->
name|target
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~Flickable
name|Flickable
operator|::
name|~
name|Flickable
parameter_list|()
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setThreshold
name|void
name|Flickable
operator|::
name|setThreshold
parameter_list|(
name|int
name|th
parameter_list|)
block|{
if|if
condition|(
name|th
operator|>=
literal|0
condition|)
name|d
operator|->
name|threshold
operator|=
name|th
expr_stmt|;
block|}
end_function
begin_function
DECL|function|threshold
name|int
name|Flickable
operator|::
name|threshold
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|threshold
return|;
block|}
end_function
begin_function
DECL|function|setAcceptMouseClick
name|void
name|Flickable
operator|::
name|setAcceptMouseClick
parameter_list|(
name|QWidget
modifier|*
name|target
parameter_list|)
block|{
name|d
operator|->
name|target
operator|=
name|target
expr_stmt|;
block|}
end_function
begin_function
DECL|function|deaccelerate
specifier|static
name|QPoint
name|deaccelerate
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|speed
parameter_list|,
name|int
name|a
init|=
literal|1
parameter_list|,
name|int
name|max
init|=
literal|64
parameter_list|)
block|{
name|int
name|x
init|=
name|qBound
argument_list|(
operator|-
name|max
argument_list|,
name|speed
operator|.
name|x
argument_list|()
argument_list|,
name|max
argument_list|)
decl_stmt|;
name|int
name|y
init|=
name|qBound
argument_list|(
operator|-
name|max
argument_list|,
name|speed
operator|.
name|y
argument_list|()
argument_list|,
name|max
argument_list|)
decl_stmt|;
name|x
operator|=
operator|(
name|x
operator|==
literal|0
operator|)
condition|?
name|x
else|:
operator|(
name|x
operator|>
literal|0
operator|)
condition|?
name|qMax
argument_list|(
literal|0
argument_list|,
name|x
operator|-
name|a
argument_list|)
else|:
name|qMin
argument_list|(
literal|0
argument_list|,
name|x
operator|+
name|a
argument_list|)
expr_stmt|;
name|y
operator|=
operator|(
name|y
operator|==
literal|0
operator|)
condition|?
name|y
else|:
operator|(
name|y
operator|>
literal|0
operator|)
condition|?
name|qMax
argument_list|(
literal|0
argument_list|,
name|y
operator|-
name|a
argument_list|)
else|:
name|qMin
argument_list|(
literal|0
argument_list|,
name|y
operator|+
name|a
argument_list|)
expr_stmt|;
return|return
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|handleMousePress
name|void
name|Flickable
operator|::
name|handleMousePress
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|button
argument_list|()
operator|!=
name|Qt
operator|::
name|LeftButton
condition|)
return|return;
if|if
condition|(
name|d
operator|->
name|ignoreList
operator|.
name|removeAll
argument_list|(
name|event
argument_list|)
condition|)
return|return;
switch|switch
condition|(
name|d
operator|->
name|state
condition|)
block|{
case|case
name|FlickablePrivate
operator|::
name|Steady
case|:
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|FlickablePrivate
operator|::
name|Pressed
expr_stmt|;
name|d
operator|->
name|pressPos
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
break|break;
case|case
name|FlickablePrivate
operator|::
name|AutoScroll
case|:
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|FlickablePrivate
operator|::
name|Stop
expr_stmt|;
name|d
operator|->
name|speed
operator|=
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|pressPos
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
name|d
operator|->
name|offset
operator|=
name|scrollOffset
argument_list|()
expr_stmt|;
name|d
operator|->
name|ticker
operator|->
name|stop
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
end_function
begin_function
DECL|function|handleMouseRelease
name|void
name|Flickable
operator|::
name|handleMouseRelease
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|button
argument_list|()
operator|!=
name|Qt
operator|::
name|LeftButton
condition|)
return|return;
if|if
condition|(
name|d
operator|->
name|ignoreList
operator|.
name|removeAll
argument_list|(
name|event
argument_list|)
condition|)
return|return;
name|QPoint
name|delta
decl_stmt|;
switch|switch
condition|(
name|d
operator|->
name|state
condition|)
block|{
case|case
name|FlickablePrivate
operator|::
name|Pressed
case|:
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|FlickablePrivate
operator|::
name|Steady
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|target
condition|)
block|{
name|QMouseEvent
modifier|*
name|event1
init|=
operator|new
name|QMouseEvent
argument_list|(
name|QEvent
operator|::
name|MouseButtonPress
argument_list|,
name|d
operator|->
name|pressPos
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|)
decl_stmt|;
name|QMouseEvent
modifier|*
name|event2
init|=
operator|new
name|QMouseEvent
argument_list|(
operator|*
name|event
argument_list|)
decl_stmt|;
name|d
operator|->
name|ignoreList
operator|<<
name|event1
expr_stmt|;
name|d
operator|->
name|ignoreList
operator|<<
name|event2
expr_stmt|;
name|QApplication
operator|::
name|postEvent
argument_list|(
name|d
operator|->
name|target
argument_list|,
name|event1
argument_list|)
expr_stmt|;
name|QApplication
operator|::
name|postEvent
argument_list|(
name|d
operator|->
name|target
argument_list|,
name|event2
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|FlickablePrivate
operator|::
name|ManualScroll
case|:
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
name|delta
operator|=
name|event
operator|->
name|pos
argument_list|()
operator|-
name|d
operator|->
name|pressPos
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|timeStamp
operator|.
name|elapsed
argument_list|()
operator|>
literal|100
condition|)
block|{
name|d
operator|->
name|timeStamp
operator|=
name|QTime
operator|::
name|currentTime
argument_list|()
expr_stmt|;
name|d
operator|->
name|speed
operator|=
name|delta
operator|-
name|d
operator|->
name|delta
expr_stmt|;
name|d
operator|->
name|delta
operator|=
name|delta
expr_stmt|;
block|}
name|d
operator|->
name|offset
operator|=
name|scrollOffset
argument_list|()
expr_stmt|;
name|d
operator|->
name|pressPos
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|speed
operator|==
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|d
operator|->
name|state
operator|=
name|FlickablePrivate
operator|::
name|Steady
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|speed
operator|/=
literal|4
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|FlickablePrivate
operator|::
name|AutoScroll
expr_stmt|;
name|d
operator|->
name|ticker
operator|->
name|start
argument_list|(
literal|20
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|FlickablePrivate
operator|::
name|Stop
case|:
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|FlickablePrivate
operator|::
name|Steady
expr_stmt|;
name|d
operator|->
name|offset
operator|=
name|scrollOffset
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
end_function
begin_function
DECL|function|handleMouseMove
name|void
name|Flickable
operator|::
name|handleMouseMove
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|event
operator|->
name|buttons
argument_list|()
operator|&
name|Qt
operator|::
name|LeftButton
operator|)
condition|)
return|return;
if|if
condition|(
name|d
operator|->
name|ignoreList
operator|.
name|removeAll
argument_list|(
name|event
argument_list|)
condition|)
return|return;
name|QPoint
name|delta
decl_stmt|;
switch|switch
condition|(
name|d
operator|->
name|state
condition|)
block|{
case|case
name|FlickablePrivate
operator|::
name|Pressed
case|:
case|case
name|FlickablePrivate
operator|::
name|Stop
case|:
name|delta
operator|=
name|event
operator|->
name|pos
argument_list|()
operator|-
name|d
operator|->
name|pressPos
expr_stmt|;
if|if
condition|(
name|delta
operator|.
name|x
argument_list|()
operator|>
name|d
operator|->
name|threshold
operator|||
name|delta
operator|.
name|x
argument_list|()
operator|<
operator|-
name|d
operator|->
name|threshold
operator|||
name|delta
operator|.
name|y
argument_list|()
operator|>
name|d
operator|->
name|threshold
operator|||
name|delta
operator|.
name|y
argument_list|()
operator|<
operator|-
name|d
operator|->
name|threshold
condition|)
block|{
name|d
operator|->
name|timeStamp
operator|=
name|QTime
operator|::
name|currentTime
argument_list|()
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|FlickablePrivate
operator|::
name|ManualScroll
expr_stmt|;
name|d
operator|->
name|delta
operator|=
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|pressPos
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
name|FlickablePrivate
operator|::
name|ManualScroll
case|:
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
name|delta
operator|=
name|event
operator|->
name|pos
argument_list|()
operator|-
name|d
operator|->
name|pressPos
expr_stmt|;
name|setScrollOffset
argument_list|(
name|d
operator|->
name|offset
operator|-
name|delta
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|timeStamp
operator|.
name|elapsed
argument_list|()
operator|>
literal|100
condition|)
block|{
name|d
operator|->
name|timeStamp
operator|=
name|QTime
operator|::
name|currentTime
argument_list|()
expr_stmt|;
name|d
operator|->
name|speed
operator|=
name|delta
operator|-
name|d
operator|->
name|delta
expr_stmt|;
name|d
operator|->
name|delta
operator|=
name|delta
expr_stmt|;
block|}
break|break;
default|default:
break|break;
block|}
block|}
end_function
begin_function
DECL|function|tick
name|void
name|Flickable
operator|::
name|tick
parameter_list|()
block|{
if|if
condition|(
name|d
operator|->
name|state
operator|==
name|FlickablePrivate
operator|::
name|AutoScroll
condition|)
block|{
name|d
operator|->
name|speed
operator|=
name|deaccelerate
argument_list|(
name|d
operator|->
name|speed
argument_list|)
expr_stmt|;
name|setScrollOffset
argument_list|(
name|d
operator|->
name|offset
operator|-
name|d
operator|->
name|speed
argument_list|)
expr_stmt|;
name|d
operator|->
name|offset
operator|=
name|scrollOffset
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|speed
operator|==
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|d
operator|->
name|state
operator|=
name|FlickablePrivate
operator|::
name|Steady
expr_stmt|;
name|d
operator|->
name|ticker
operator|->
name|stop
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|d
operator|->
name|ticker
operator|->
name|stop
argument_list|()
expr_stmt|;
block|}
block|}
end_function
end_unit
