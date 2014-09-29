begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"nativeeventlist.h"
end_include
begin_constructor
DECL|function|NativeEventList
name|NativeEventList
operator|::
name|NativeEventList
parameter_list|(
name|int
name|defaultWaitMs
parameter_list|)
member_init_list|:
name|playbackMultiplier
argument_list|(
literal|1.0
argument_list|)
member_init_list|,
name|currIndex
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|wait
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|defaultWaitMs
argument_list|(
name|defaultWaitMs
argument_list|)
block|{
name|debug
operator|=
name|qgetenv
argument_list|(
literal|"NATIVEDEBUG"
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|QString
name|multiplier
init|=
name|qgetenv
argument_list|(
literal|"NATIVEDEBUGSPEED"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|multiplier
operator|.
name|isEmpty
argument_list|()
condition|)
name|setTimeMultiplier
argument_list|(
name|multiplier
operator|.
name|toFloat
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~NativeEventList
name|NativeEventList
operator|::
name|~
name|NativeEventList
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|eventList
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
operator|delete
name|eventList
operator|.
name|takeAt
argument_list|(
name|i
argument_list|)
operator|.
name|second
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|sendNextEvent
name|void
name|NativeEventList
operator|::
name|sendNextEvent
parameter_list|()
block|{
name|QNativeEvent
modifier|*
name|e
init|=
name|eventList
operator|.
name|at
argument_list|(
name|currIndex
argument_list|)
operator|.
name|second
decl_stmt|;
if|if
condition|(
name|e
condition|)
block|{
if|if
condition|(
name|debug
operator|>
literal|0
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"Sending:"
operator|<<
operator|*
name|e
expr_stmt|;
name|QNativeInput
operator|::
name|sendNativeEvent
argument_list|(
operator|*
name|e
argument_list|)
expr_stmt|;
block|}
name|waitNextEvent
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|waitNextEvent
name|void
name|NativeEventList
operator|::
name|waitNextEvent
parameter_list|()
block|{
if|if
condition|(
operator|++
name|currIndex
operator|>=
name|eventList
operator|.
name|size
argument_list|()
condition|)
block|{
emit|emit
name|done
argument_list|()
emit|;
name|stop
argument_list|()
expr_stmt|;
return|return;
block|}
name|int
name|interval
init|=
name|eventList
operator|.
name|at
argument_list|(
name|currIndex
argument_list|)
operator|.
name|first
decl_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
name|interval
operator|*
name|playbackMultiplier
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|sendNextEvent
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|append
name|void
name|NativeEventList
operator|::
name|append
parameter_list|(
name|QNativeEvent
modifier|*
name|event
parameter_list|)
block|{
name|eventList
operator|.
name|append
argument_list|(
name|QPair
argument_list|<
name|int
argument_list|,
name|QNativeEvent
operator|*
argument_list|>
argument_list|(
name|defaultWaitMs
argument_list|,
name|event
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|append
name|void
name|NativeEventList
operator|::
name|append
parameter_list|(
name|int
name|waitMs
parameter_list|,
name|QNativeEvent
modifier|*
name|event
parameter_list|)
block|{
name|eventList
operator|.
name|append
argument_list|(
name|QPair
argument_list|<
name|int
argument_list|,
name|QNativeEvent
operator|*
argument_list|>
argument_list|(
name|waitMs
argument_list|,
name|event
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|play
name|void
name|NativeEventList
operator|::
name|play
parameter_list|(
name|Playback
name|playback
parameter_list|)
block|{
name|waitNextEvent
argument_list|()
expr_stmt|;
name|wait
operator|=
operator|(
name|playback
operator|==
name|WaitUntilFinished
operator|)
expr_stmt|;
while|while
condition|(
name|wait
condition|)
name|QCoreApplication
operator|::
name|processEvents
argument_list|(
name|QEventLoop
operator|::
name|WaitForMoreEvents
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stop
name|void
name|NativeEventList
operator|::
name|stop
parameter_list|()
block|{
name|wait
operator|=
literal|false
expr_stmt|;
name|QAbstractEventDispatcher
operator|::
name|instance
argument_list|()
operator|->
name|interrupt
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setTimeMultiplier
name|void
name|NativeEventList
operator|::
name|setTimeMultiplier
parameter_list|(
name|float
name|multiplier
parameter_list|)
block|{
name|playbackMultiplier
operator|=
name|multiplier
expr_stmt|;
block|}
end_function
end_unit
