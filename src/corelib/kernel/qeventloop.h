begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVENTLOOP_H
end_ifndef
begin_define
DECL|macro|QEVENTLOOP_H
define|#
directive|define
name|QEVENTLOOP_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QEventLoopPrivate
name|class
name|QEventLoopPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QEventLoop
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QEventLoop
argument_list|)
name|public
operator|:
name|explicit
name|QEventLoop
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QEventLoop
argument_list|()
block|;      enum
name|ProcessEventsFlag
block|{
name|AllEvents
operator|=
literal|0x00
block|,
name|ExcludeUserInputEvents
operator|=
literal|0x01
block|,
name|ExcludeSocketNotifiers
operator|=
literal|0x02
block|,
name|WaitForMoreEvents
operator|=
literal|0x04
block|,
name|X11ExcludeTimers
operator|=
literal|0x08
block|,
name|EventLoopExec
operator|=
literal|0x20
block|,
name|DialogExec
operator|=
literal|0x40
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|ProcessEventsFlags
argument_list|,
argument|ProcessEventsFlag
argument_list|)
name|bool
name|processEvents
argument_list|(
argument|ProcessEventsFlags flags = AllEvents
argument_list|)
block|;
name|void
name|processEvents
argument_list|(
argument|ProcessEventsFlags flags
argument_list|,
argument|int maximumTime
argument_list|)
block|;
name|int
name|exec
argument_list|(
argument|ProcessEventsFlags flags = AllEvents
argument_list|)
block|;
name|void
name|exit
argument_list|(
argument|int returnCode =
literal|0
argument_list|)
block|;
name|bool
name|isRunning
argument_list|()
specifier|const
block|;
name|void
name|wakeUp
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|quit
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QEventLoop::ProcessEventsFlags
argument_list|)
end_macro
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QEVENTLOOP_H
end_comment
end_unit
