begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVENTDISPATCHER_WIN_P_H
end_ifndef
begin_define
DECL|macro|QEVENTDISPATCHER_WIN_P_H
define|#
directive|define
name|QEVENTDISPATCHER_WIN_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtCore/qabstracteventdispatcher.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qt_windows.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWinEventNotifier
name|class
name|QWinEventNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEventDispatcherWin32Private
name|class
name|QEventDispatcherWin32Private
decl_stmt|;
end_decl_stmt
begin_comment
comment|// forward declaration
end_comment
begin_function_decl
name|LRESULT
name|QT_WIN_CALLBACK
name|qt_internal_proc
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|UINT
name|message
parameter_list|,
name|WPARAM
name|wp
parameter_list|,
name|LPARAM
name|lp
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QEventDispatcherWin32
range|:
name|public
name|QAbstractEventDispatcher
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QEventDispatcherWin32
argument_list|)
name|void
name|createInternalHwnd
argument_list|()
block|;
name|friend
name|class
name|QGuiEventDispatcherWin32
block|;
name|public
operator|:
name|explicit
name|QEventDispatcherWin32
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QEventDispatcherWin32
argument_list|()
block|;
name|bool
name|QT_ENSURE_STACK_ALIGNED_FOR_SSE
name|processEvents
argument_list|(
argument|QEventLoop::ProcessEventsFlags flags
argument_list|)
block|;
name|bool
name|hasPendingEvents
argument_list|()
block|;
name|void
name|registerSocketNotifier
argument_list|(
name|QSocketNotifier
operator|*
name|notifier
argument_list|)
block|;
name|void
name|unregisterSocketNotifier
argument_list|(
name|QSocketNotifier
operator|*
name|notifier
argument_list|)
block|;
name|void
name|registerTimer
argument_list|(
argument|int timerId
argument_list|,
argument|int interval
argument_list|,
argument|QObject *object
argument_list|)
block|;
name|bool
name|unregisterTimer
argument_list|(
argument|int timerId
argument_list|)
block|;
name|bool
name|unregisterTimers
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|QList
operator|<
name|TimerInfo
operator|>
name|registeredTimers
argument_list|(
argument|QObject *object
argument_list|)
specifier|const
block|;
name|bool
name|registerEventNotifier
argument_list|(
name|QWinEventNotifier
operator|*
name|notifier
argument_list|)
block|;
name|void
name|unregisterEventNotifier
argument_list|(
name|QWinEventNotifier
operator|*
name|notifier
argument_list|)
block|;
name|void
name|activateEventNotifiers
argument_list|()
block|;
name|void
name|wakeUp
argument_list|()
block|;
name|void
name|interrupt
argument_list|()
block|;
name|void
name|flush
argument_list|()
block|;
name|void
name|startingUp
argument_list|()
block|;
name|void
name|closingDown
argument_list|()
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|private
operator|:
name|friend
name|LRESULT
name|QT_WIN_CALLBACK
name|qt_internal_proc
argument_list|(
argument|HWND hwnd
argument_list|,
argument|UINT message
argument_list|,
argument|WPARAM wp
argument_list|,
argument|LPARAM lp
argument_list|)
block|;
name|friend
name|LRESULT
name|QT_WIN_CALLBACK
name|qt_GetMessageHook
argument_list|(
name|int
argument_list|,
name|WPARAM
argument_list|,
name|LPARAM
argument_list|)
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
comment|// QEVENTDISPATCHER_WIN_P_H
end_comment
end_unit
