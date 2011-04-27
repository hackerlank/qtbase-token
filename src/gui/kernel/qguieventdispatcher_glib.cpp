begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qguieventdispatcher_glib_p.h"
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
file|<glib.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|GX11EventSource
struct|struct
name|GX11EventSource
block|{
DECL|member|source
name|GSource
name|source
decl_stmt|;
DECL|member|pollfd
name|GPollFD
name|pollfd
decl_stmt|;
DECL|member|flags
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
decl_stmt|;
DECL|member|q
name|QGuiEventDispatcherGlib
modifier|*
name|q
decl_stmt|;
DECL|member|d
name|QGuiEventDispatcherGlibPrivate
modifier|*
name|d
decl_stmt|;
block|}
struct|;
end_struct
begin_class
DECL|class|QGuiEventDispatcherGlibPrivate
class|class
name|QGuiEventDispatcherGlibPrivate
super|:
specifier|public
name|QEventDispatcherGlibPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QGuiEventDispatcherGlib
parameter_list|)
specifier|public
private|:
name|QGuiEventDispatcherGlibPrivate
parameter_list|()
constructor_decl|;
DECL|member|x11EventSource
name|GX11EventSource
modifier|*
name|x11EventSource
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
begin_function
DECL|function|x11EventSourcePrepare
specifier|static
name|gboolean
name|x11EventSourcePrepare
parameter_list|(
name|GSource
modifier|*
name|s
parameter_list|,
name|gint
modifier|*
name|timeout
parameter_list|)
block|{
if|if
condition|(
name|timeout
condition|)
operator|*
name|timeout
operator|=
operator|-
literal|1
expr_stmt|;
name|GX11EventSource
modifier|*
name|source
init|=
cast|reinterpret_cast
argument_list|<
name|GX11EventSource
operator|*
argument_list|>
argument_list|(
name|s
argument_list|)
decl_stmt|;
return|return
operator|(
name|XEventsQueued
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|QueuedAfterFlush
argument_list|)
operator|||
operator|(
operator|!
operator|(
name|source
operator|->
name|flags
operator|&
name|QEventLoop
operator|::
name|ExcludeUserInputEvents
operator|)
operator|&&
operator|!
name|source
operator|->
name|d
operator|->
name|queuedUserInputEvents
operator|.
name|isEmpty
argument_list|()
operator|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|x11EventSourceCheck
specifier|static
name|gboolean
name|x11EventSourceCheck
parameter_list|(
name|GSource
modifier|*
name|s
parameter_list|)
block|{
name|GX11EventSource
modifier|*
name|source
init|=
cast|reinterpret_cast
argument_list|<
name|GX11EventSource
operator|*
argument_list|>
argument_list|(
name|s
argument_list|)
decl_stmt|;
return|return
operator|(
name|XEventsQueued
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|QueuedAfterFlush
argument_list|)
operator|||
operator|(
operator|!
operator|(
name|source
operator|->
name|flags
operator|&
name|QEventLoop
operator|::
name|ExcludeUserInputEvents
operator|)
operator|&&
operator|!
name|source
operator|->
name|d
operator|->
name|queuedUserInputEvents
operator|.
name|isEmpty
argument_list|()
operator|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|x11EventSourceDispatch
specifier|static
name|gboolean
name|x11EventSourceDispatch
parameter_list|(
name|GSource
modifier|*
name|s
parameter_list|,
name|GSourceFunc
name|callback
parameter_list|,
name|gpointer
name|user_data
parameter_list|)
block|{
name|GX11EventSource
modifier|*
name|source
init|=
cast|reinterpret_cast
argument_list|<
name|GX11EventSource
operator|*
argument_list|>
argument_list|(
name|s
argument_list|)
decl_stmt|;
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
do|do
block|{
name|XEvent
name|event
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|source
operator|->
name|flags
operator|&
name|QEventLoop
operator|::
name|ExcludeUserInputEvents
operator|)
operator|&&
operator|!
name|source
operator|->
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
name|source
operator|->
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
name|source
operator|->
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
name|source
operator|->
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
name|source
operator|->
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
name|source
operator|->
name|q
operator|->
name|filterEvent
argument_list|(
operator|&
name|event
argument_list|)
condition|)
continue|continue;
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
goto|goto
name|out
goto|;
block|}
do|while
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
do|;
name|out
label|:
name|source
operator|->
name|d
operator|->
name|runTimersOnceWithNormalPriority
argument_list|()
expr_stmt|;
if|if
condition|(
name|callback
condition|)
name|callback
argument_list|(
name|user_data
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|x11EventSourceFuncs
specifier|static
name|GSourceFuncs
name|x11EventSourceFuncs
init|=
block|{
name|x11EventSourcePrepare
block|,
name|x11EventSourceCheck
block|,
name|x11EventSourceDispatch
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QGuiEventDispatcherGlibPrivate
name|QGuiEventDispatcherGlibPrivate
operator|::
name|QGuiEventDispatcherGlibPrivate
parameter_list|()
block|{
name|x11EventSource
operator|=
cast|reinterpret_cast
argument_list|<
name|GX11EventSource
operator|*
argument_list|>
argument_list|(
name|g_source_new
argument_list|(
operator|&
name|x11EventSourceFuncs
argument_list|,
sizeof|sizeof
argument_list|(
name|GX11EventSource
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|g_source_set_can_recurse
argument_list|(
operator|&
name|x11EventSource
operator|->
name|source
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|memset
argument_list|(
operator|&
name|x11EventSource
operator|->
name|pollfd
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|GPollFD
argument_list|)
argument_list|)
expr_stmt|;
name|x11EventSource
operator|->
name|flags
operator|=
name|QEventLoop
operator|::
name|AllEvents
expr_stmt|;
name|x11EventSource
operator|->
name|q
operator|=
literal|0
expr_stmt|;
name|x11EventSource
operator|->
name|d
operator|=
literal|0
expr_stmt|;
name|g_source_attach
argument_list|(
operator|&
name|x11EventSource
operator|->
name|source
argument_list|,
name|mainContext
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QGuiEventDispatcherGlib
name|QGuiEventDispatcherGlib
operator|::
name|QGuiEventDispatcherGlib
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QEventDispatcherGlib
argument_list|(
operator|*
operator|new
name|QGuiEventDispatcherGlibPrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QGuiEventDispatcherGlib
name|QGuiEventDispatcherGlib
operator|::
name|~
name|QGuiEventDispatcherGlib
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGuiEventDispatcherGlib
argument_list|)
expr_stmt|;
name|g_source_remove_poll
argument_list|(
operator|&
name|d
operator|->
name|x11EventSource
operator|->
name|source
argument_list|,
operator|&
name|d
operator|->
name|x11EventSource
operator|->
name|pollfd
argument_list|)
expr_stmt|;
name|g_source_destroy
argument_list|(
operator|&
name|d
operator|->
name|x11EventSource
operator|->
name|source
argument_list|)
expr_stmt|;
name|d
operator|->
name|x11EventSource
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|processEvents
name|bool
name|QGuiEventDispatcherGlib
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
name|QGuiEventDispatcherGlib
argument_list|)
expr_stmt|;
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|saved_flags
init|=
name|d
operator|->
name|x11EventSource
operator|->
name|flags
decl_stmt|;
name|d
operator|->
name|x11EventSource
operator|->
name|flags
operator|=
name|flags
expr_stmt|;
name|bool
name|returnValue
init|=
name|QEventDispatcherGlib
operator|::
name|processEvents
argument_list|(
name|flags
argument_list|)
decl_stmt|;
name|d
operator|->
name|x11EventSource
operator|->
name|flags
operator|=
name|saved_flags
expr_stmt|;
return|return
name|returnValue
return|;
block|}
end_function
begin_function
DECL|function|startingUp
name|void
name|QGuiEventDispatcherGlib
operator|::
name|startingUp
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGuiEventDispatcherGlib
argument_list|)
expr_stmt|;
name|d
operator|->
name|x11EventSource
operator|->
name|pollfd
operator|.
name|fd
operator|=
name|XConnectionNumber
argument_list|(
name|X11
operator|->
name|display
argument_list|)
expr_stmt|;
name|d
operator|->
name|x11EventSource
operator|->
name|pollfd
operator|.
name|events
operator|=
name|G_IO_IN
operator||
name|G_IO_HUP
operator||
name|G_IO_ERR
expr_stmt|;
name|d
operator|->
name|x11EventSource
operator|->
name|q
operator|=
name|this
expr_stmt|;
name|d
operator|->
name|x11EventSource
operator|->
name|d
operator|=
name|d
expr_stmt|;
name|g_source_add_poll
argument_list|(
operator|&
name|d
operator|->
name|x11EventSource
operator|->
name|source
argument_list|,
operator|&
name|d
operator|->
name|x11EventSource
operator|->
name|pollfd
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QGuiEventDispatcherGlib
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
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
