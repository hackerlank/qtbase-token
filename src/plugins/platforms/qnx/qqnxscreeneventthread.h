begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXSCREENEVENTTHREAD_H
end_ifndef
begin_define
DECL|macro|QQNXSCREENEVENTTHREAD_H
define|#
directive|define
name|QQNXSCREENEVENTTHREAD_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QThread>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMutex>
end_include
begin_include
include|#
directive|include
file|<screen/screen.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QQnxScreenEventHandler
name|class
name|QQnxScreenEventHandler
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|screen_event_t
DECL|typedef|QQnxScreenEventArray
typedef|typedef
name|QVarLengthArray
operator|<
name|screen_event_t
operator|,
literal|64
operator|>
name|QQnxScreenEventArray
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QQnxScreenEventThread
range|:
name|public
name|QThread
block|{
name|Q_OBJECT
name|public
operator|:
name|QQnxScreenEventThread
argument_list|(
argument|screen_context_t context
argument_list|,
argument|QQnxScreenEventHandler *screenEventHandler
argument_list|)
block|;
operator|~
name|QQnxScreenEventThread
argument_list|()
block|;
specifier|static
name|void
name|injectKeyboardEvent
argument_list|(
argument|int flags
argument_list|,
argument|int sym
argument_list|,
argument|int mod
argument_list|,
argument|int scan
argument_list|,
argument|int cap
argument_list|)
block|;
name|QQnxScreenEventArray
operator|*
name|lock
argument_list|()
block|;
name|void
name|unlock
argument_list|()
block|;
name|protected
operator|:
name|void
name|run
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|eventPending
argument_list|()
block|;
name|private
operator|:
name|void
name|shutdown
argument_list|()
block|;
name|screen_context_t
name|m_screenContext
block|;
name|QMutex
name|m_mutex
block|;
name|QQnxScreenEventArray
name|m_events
block|;
name|QQnxScreenEventHandler
operator|*
name|m_screenEventHandler
block|;
name|bool
name|m_quit
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QQNXSCREENEVENTTHREAD_H
end_comment
end_unit
