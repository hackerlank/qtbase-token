begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"private/qwscommand_qws_p.h"
end_include
begin_include
include|#
directive|include
file|"qwsdisplay_qws.h"
end_include
begin_include
include|#
directive|include
file|"qwsevent_qws.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsystem_qws.h"
end_include
begin_include
include|#
directive|include
file|"qeventdispatcher_qws_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qeventdispatcher_unix_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
name|QT_USE_NAMESPACE
DECL|class|QEventDispatcherQWSPrivate
name|class
name|QEventDispatcherQWSPrivate
operator|:
specifier|public
name|QEventDispatcherUNIXPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QEventDispatcherQWS
argument_list|)
specifier|public
operator|:
DECL|function|QEventDispatcherQWSPrivate
specifier|inline
name|QEventDispatcherQWSPrivate
argument_list|()
block|{ }
DECL|member|queuedUserInputEvents
name|QList
argument_list|<
name|QWSEvent
operator|*
argument_list|>
name|queuedUserInputEvents
block|; }
expr_stmt|;
end_expr_stmt
begin_constructor
DECL|function|QEventDispatcherQWS
name|QEventDispatcherQWS
operator|::
name|QEventDispatcherQWS
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
name|QEventDispatcherQWSPrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QEventDispatcherQWS
name|QEventDispatcherQWS
operator|::
name|~
name|QEventDispatcherQWS
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|// from qapplication_qws.cpp
end_comment
begin_decl_stmt
specifier|extern
name|QWSDisplay
modifier|*
name|qt_fbdpy
decl_stmt|;
end_decl_stmt
begin_comment
comment|// QWS `display'
end_comment
begin_comment
comment|//#define ZERO_FOR_THE_MOMENT
end_comment
begin_function
DECL|function|processEvents
name|bool
name|QEventDispatcherQWS
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
name|QEventDispatcherQWS
argument_list|)
expr_stmt|;
comment|// process events from the QWS server
name|int
name|nevents
init|=
literal|0
decl_stmt|;
comment|// handle gui and posted events
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
while|while
condition|(
operator|!
name|d
operator|->
name|interrupt
condition|)
block|{
comment|// also flushes output buffer ###can be optimized
name|QWSEvent
modifier|*
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
name|qt_fbdpy
operator|->
name|eventPending
argument_list|()
condition|)
block|{
name|event
operator|=
name|qt_fbdpy
operator|->
name|getEvent
argument_list|()
expr_stmt|;
comment|// get next event
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
if|if
condition|(
name|event
operator|->
name|type
operator|==
name|QWSEvent
operator|::
name|Mouse
operator|||
name|event
operator|->
name|type
operator|==
name|QWSEvent
operator|::
name|Key
condition|)
block|{
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
block|}
block|}
block|}
else|else
block|{
break|break;
block|}
if|if
condition|(
name|filterEvent
argument_list|(
name|event
argument_list|)
condition|)
block|{
operator|delete
name|event
expr_stmt|;
continue|continue;
block|}
name|nevents
operator|++
expr_stmt|;
name|bool
name|ret
init|=
name|qApp
operator|->
name|qwsProcessEvent
argument_list|(
name|event
argument_list|)
operator|==
literal|1
decl_stmt|;
operator|delete
name|event
expr_stmt|;
if|if
condition|(
name|ret
condition|)
block|{
return|return
literal|true
return|;
block|}
block|}
if|if
condition|(
operator|!
name|d
operator|->
name|interrupt
condition|)
block|{
specifier|extern
name|QList
argument_list|<
name|QWSCommand
modifier|*
argument_list|>
modifier|*
name|qt_get_server_queue
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|qt_get_server_queue
argument_list|()
operator|->
name|isEmpty
argument_list|()
condition|)
block|{
name|QWSServer
operator|::
name|processEventQueue
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|QEventDispatcherUNIX
operator|::
name|processEvents
argument_list|(
name|flags
argument_list|)
condition|)
return|return
literal|true
return|;
block|}
return|return
operator|(
name|nevents
operator|>
literal|0
operator|)
return|;
block|}
end_function
begin_function
DECL|function|hasPendingEvents
name|bool
name|QEventDispatcherQWS
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
name|qGlobalPostedEventsCount
argument_list|()
operator|||
name|qt_fbdpy
operator|->
name|eventPending
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|startingUp
name|void
name|QEventDispatcherQWS
operator|::
name|startingUp
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|closingDown
name|void
name|QEventDispatcherQWS
operator|::
name|closingDown
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|flush
name|void
name|QEventDispatcherQWS
operator|::
name|flush
parameter_list|()
block|{
if|if
condition|(
name|qApp
condition|)
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|qt_fbdpy
operator|->
name|eventPending
argument_list|()
expr_stmt|;
comment|// flush
block|}
end_function
begin_function
DECL|function|select
name|int
name|QEventDispatcherQWS
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
