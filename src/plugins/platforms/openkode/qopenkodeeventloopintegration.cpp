begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenkodeeventloopintegration.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<KD/kd.h>
end_include
begin_include
include|#
directive|include
file|<KD/ATX_keyboard.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QT_EVENT_WAKEUP_EVENTLOOP
specifier|static
specifier|const
name|int
name|QT_EVENT_WAKEUP_EVENTLOOP
init|=
name|KD_EVENT_USER
operator|+
literal|1
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|kdprocessevent
name|void
name|kdprocessevent
parameter_list|(
specifier|const
name|KDEvent
modifier|*
name|event
parameter_list|)
block|{
switch|switch
condition|(
name|event
operator|->
name|type
condition|)
block|{
case|case
name|KD_EVENT_INPUT
case|:
name|qDebug
argument_list|()
operator|<<
literal|"KD_EVENT_INPUT"
expr_stmt|;
break|break;
case|case
name|KD_EVENT_INPUT_POINTER
case|:
name|qDebug
argument_list|()
operator|<<
literal|"KD_EVENT_INPUT_POINTER"
expr_stmt|;
break|break;
case|case
name|KD_EVENT_WINDOW_CLOSE
case|:
name|qDebug
argument_list|()
operator|<<
literal|"KD_EVENT_WINDOW_CLOSE"
expr_stmt|;
break|break;
case|case
name|KD_EVENT_WINDOWPROPERTY_CHANGE
case|:
name|qDebug
argument_list|()
operator|<<
literal|"KD_EVENT_WINDOWPROPERTY_CHANGE"
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
name|event
operator|->
name|data
operator|.
name|windowproperty
operator|.
name|pname
expr_stmt|;
break|break;
case|case
name|KD_EVENT_WINDOW_FOCUS
case|:
name|qDebug
argument_list|()
operator|<<
literal|"KD_EVENT_WINDOW_FOCUS"
expr_stmt|;
break|break;
case|case
name|KD_EVENT_WINDOW_REDRAW
case|:
name|qDebug
argument_list|()
operator|<<
literal|"KD_EVENT_WINDOW_REDRAW"
expr_stmt|;
break|break;
case|case
name|KD_EVENT_USER
case|:
name|qDebug
argument_list|()
operator|<<
literal|"KD_EVENT_USER"
expr_stmt|;
break|break;
case|case
name|KD_EVENT_INPUT_KEY_ATX
case|:
name|qDebug
argument_list|()
operator|<<
literal|"KD_EVENT_INPUT_KEY_ATX"
expr_stmt|;
break|break;
case|case
name|QT_EVENT_WAKEUP_EVENTLOOP
case|:
name|QPlatformEventLoopIntegration
operator|::
name|processEvents
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
name|kdDefaultEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QOpenKODEEventLoopIntegration
name|QOpenKODEEventLoopIntegration
operator|::
name|QOpenKODEEventLoopIntegration
parameter_list|()
member_init_list|:
name|m_quit
argument_list|(
literal|false
argument_list|)
block|{
name|m_kdThread
operator|=
name|kdThreadSelf
argument_list|()
expr_stmt|;
name|kdInstallCallback
argument_list|(
operator|&
name|kdprocessevent
argument_list|,
name|QT_EVENT_WAKEUP_EVENTLOOP
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|startEventLoop
name|void
name|QOpenKODEEventLoopIntegration
operator|::
name|startEventLoop
parameter_list|()
block|{
while|while
condition|(
operator|!
name|m_quit
condition|)
block|{
name|qint64
name|msec
init|=
name|nextTimerEvent
argument_list|()
decl_stmt|;
specifier|const
name|KDEvent
modifier|*
name|event
init|=
name|kdWaitEvent
argument_list|(
name|msec
argument_list|)
decl_stmt|;
if|if
condition|(
name|event
condition|)
block|{
name|kdDefaultEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|event
operator|=
name|kdWaitEvent
argument_list|(
literal|0
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|kdDefaultEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
block|}
name|QPlatformEventLoopIntegration
operator|::
name|processEvents
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|quitEventLoop
name|void
name|QOpenKODEEventLoopIntegration
operator|::
name|quitEventLoop
parameter_list|()
block|{
name|m_quit
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qtNeedsToProcessEvents
name|void
name|QOpenKODEEventLoopIntegration
operator|::
name|qtNeedsToProcessEvents
parameter_list|()
block|{
name|KDEvent
modifier|*
name|event
init|=
name|kdCreateEvent
argument_list|()
decl_stmt|;
name|event
operator|->
name|type
operator|=
name|QT_EVENT_WAKEUP_EVENTLOOP
expr_stmt|;
name|event
operator|->
name|userptr
operator|=
name|this
expr_stmt|;
name|kdPostThreadEvent
argument_list|(
name|event
argument_list|,
name|m_kdThread
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
