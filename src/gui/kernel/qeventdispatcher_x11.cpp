begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeventdispatcher_x11_p.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qx11info_x11.h"
end_include
begin_include
include|#
directive|include
file|"qt_x11_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qeventdispatcher_unix_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QEventDispatcherX11Private
class|class
name|QEventDispatcherX11Private
super|:
specifier|public
name|QEventDispatcherUNIXPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QEventDispatcherX11
parameter_list|)
specifier|public
private|:
DECL|function|QEventDispatcherX11Private
specifier|inline
name|QEventDispatcherX11Private
parameter_list|()
member_init_list|:
name|xfd
argument_list|(
operator|-
literal|1
argument_list|)
block|{ }
DECL|member|xfd
name|int
name|xfd
decl_stmt|;
DECL|member|queuedUserInputEvents
name|QList
argument_list|<
name|XEvent
argument_list|>
name|queuedUserInputEvents
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QEventDispatcherX11
name|QEventDispatcherX11
operator|::
name|QEventDispatcherX11
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QEventDispatcherUNIX
argument_list|(
operator|*
operator|new
name|QEventDispatcherX11Private
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QEventDispatcherX11
name|QEventDispatcherX11
operator|::
name|~
name|QEventDispatcherX11
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|processEvents
name|bool
name|QEventDispatcherX11
operator|::
name|processEvents
parameter_list|(
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QEventDispatcherX11
argument_list|)
expr_stmt|;
name|d
operator|->
name|interrupt
operator|=
literal|false
expr_stmt|;
name|QApplication
operator|::
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|ulong
name|marker
init|=
name|XNextRequest
argument_list|(
name|X11
operator|->
name|display
argument_list|)
decl_stmt|;
name|int
name|nevents
init|=
literal|0
decl_stmt|;
do|do
block|{
while|while
condition|(
operator|!
name|d
operator|->
name|interrupt
condition|)
block|{
name|XEvent
name|event
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|flags
operator|&
name|QEventLoop
operator|::
name|ExcludeUserInputEvents
operator|)
operator|&&
operator|!
name|d
operator|->
name|queuedUserInputEvents
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// process a pending user input event
name|event
operator|=
name|d
operator|->
name|queuedUserInputEvents
operator|.
name|takeFirst
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|XEventsQueued
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|QueuedAlready
argument_list|)
condition|)
block|{
comment|// process events from the X server
name|XNextEvent
argument_list|(
name|X11
operator|->
name|display
argument_list|,
operator|&
name|event
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|QEventLoop
operator|::
name|ExcludeUserInputEvents
condition|)
block|{
comment|// queue user input events
switch|switch
condition|(
name|event
operator|.
name|type
condition|)
block|{
case|case
name|ButtonPress
case|:
case|case
name|ButtonRelease
case|:
case|case
name|MotionNotify
case|:
case|case
name|XKeyPress
case|:
case|case
name|XKeyRelease
case|:
case|case
name|EnterNotify
case|:
case|case
name|LeaveNotify
case|:
name|d
operator|->
name|queuedUserInputEvents
operator|.
name|append
argument_list|(
name|event
argument_list|)
expr_stmt|;
continue|continue;
case|case
name|ClientMessage
case|:
comment|// only keep the wm_take_focus and
comment|// _qt_scrolldone protocols, queue all other
comment|// client messages
if|if
condition|(
name|event
operator|.
name|xclient
operator|.
name|format
operator|==
literal|32
condition|)
block|{
if|if
condition|(
name|event
operator|.
name|xclient
operator|.
name|message_type
operator|==
name|ATOM
argument_list|(
name|WM_PROTOCOLS
argument_list|)
operator|&&
operator|(
name|Atom
operator|)
name|event
operator|.
name|xclient
operator|.
name|data
operator|.
name|l
index|[
literal|0
index|]
operator|==
name|ATOM
argument_list|(
name|WM_TAKE_FOCUS
argument_list|)
condition|)
block|{
break|break;
block|}
elseif|else
if|if
condition|(
name|event
operator|.
name|xclient
operator|.
name|message_type
operator|==
name|ATOM
argument_list|(
name|_QT_SCROLL_DONE
argument_list|)
condition|)
block|{
break|break;
block|}
block|}
name|d
operator|->
name|queuedUserInputEvents
operator|.
name|append
argument_list|(
name|event
argument_list|)
expr_stmt|;
continue|continue;
default|default:
break|break;
block|}
block|}
block|}
else|else
block|{
comment|// no event to process
break|break;
block|}
comment|// send through event filter
if|if
condition|(
name|filterEvent
argument_list|(
operator|&
name|event
argument_list|)
condition|)
continue|continue;
name|nevents
operator|++
expr_stmt|;
if|if
condition|(
name|qApp
operator|->
name|x11ProcessEvent
argument_list|(
operator|&
name|event
argument_list|)
operator|==
literal|1
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|event
operator|.
name|xany
operator|.
name|serial
operator|>=
name|marker
condition|)
block|{
if|if
condition|(
name|XEventsQueued
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|QueuedAfterFlush
argument_list|)
condition|)
name|flags
operator|&=
operator|~
name|QEventLoop
operator|::
name|WaitForMoreEvents
expr_stmt|;
goto|goto
name|out
goto|;
block|}
block|}
block|}
do|while
condition|(
operator|!
name|d
operator|->
name|interrupt
operator|&&
name|XEventsQueued
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|QueuedAfterFlush
argument_list|)
condition|)
do|;
name|out
label|:
if|if
condition|(
operator|!
name|d
operator|->
name|interrupt
condition|)
block|{
specifier|const
name|uint
name|exclude_all
init|=
name|QEventLoop
operator|::
name|ExcludeSocketNotifiers
operator||
name|QEventLoop
operator|::
name|X11ExcludeTimers
operator||
name|QEventLoop
operator|::
name|WaitForMoreEvents
decl_stmt|;
if|if
condition|(
name|nevents
operator|>
literal|0
operator|&&
operator|(
operator|(
name|uint
operator|)
name|flags
operator|&
name|exclude_all
operator|)
operator|==
name|exclude_all
condition|)
block|{
name|QApplication
operator|::
name|sendPostedEvents
argument_list|()
expr_stmt|;
return|return
name|nevents
operator|>
literal|0
return|;
block|}
comment|// return true if we handled events, false otherwise
return|return
name|QEventDispatcherUNIX
operator|::
name|processEvents
argument_list|(
name|flags
argument_list|)
operator|||
operator|(
name|nevents
operator|>
literal|0
operator|)
return|;
block|}
return|return
name|nevents
operator|>
literal|0
return|;
block|}
end_function
begin_function
DECL|function|hasPendingEvents
name|bool
name|QEventDispatcherX11
operator|::
name|hasPendingEvents
parameter_list|()
block|{
specifier|extern
name|uint
name|qGlobalPostedEventsCount
argument_list|()
decl_stmt|;
comment|// from qapplication.cpp
return|return
operator|(
name|qGlobalPostedEventsCount
argument_list|()
operator|||
name|XPending
argument_list|(
name|X11
operator|->
name|display
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QEventDispatcherX11
operator|::
name|flush
parameter_list|()
block|{
name|XFlush
argument_list|(
name|X11
operator|->
name|display
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|startingUp
name|void
name|QEventDispatcherX11
operator|::
name|startingUp
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QEventDispatcherX11
argument_list|)
expr_stmt|;
name|d
operator|->
name|xfd
operator|=
name|XConnectionNumber
argument_list|(
name|X11
operator|->
name|display
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|closingDown
name|void
name|QEventDispatcherX11
operator|::
name|closingDown
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QEventDispatcherX11
argument_list|)
expr_stmt|;
name|d
operator|->
name|xfd
operator|=
operator|-
literal|1
expr_stmt|;
block|}
end_function
begin_function
DECL|function|select
name|int
name|QEventDispatcherX11
operator|::
name|select
parameter_list|(
name|int
name|nfds
parameter_list|,
name|fd_set
modifier|*
name|readfds
parameter_list|,
name|fd_set
modifier|*
name|writefds
parameter_list|,
name|fd_set
modifier|*
name|exceptfds
parameter_list|,
name|timeval
modifier|*
name|timeout
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QEventDispatcherX11
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|xfd
operator|>
literal|0
condition|)
block|{
name|nfds
operator|=
name|qMax
argument_list|(
name|nfds
operator|-
literal|1
argument_list|,
name|d
operator|->
name|xfd
argument_list|)
operator|+
literal|1
expr_stmt|;
name|FD_SET
argument_list|(
name|d
operator|->
name|xfd
argument_list|,
name|readfds
argument_list|)
expr_stmt|;
block|}
return|return
name|QEventDispatcherUNIX
operator|::
name|select
argument_list|(
name|nfds
argument_list|,
name|readfds
argument_list|,
name|writefds
argument_list|,
name|exceptfds
argument_list|,
name|timeout
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
