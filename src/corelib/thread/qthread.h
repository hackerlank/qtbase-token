begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTHREAD_H
end_ifndef
begin_define
DECL|macro|QTHREAD_H
define|#
directive|define
name|QTHREAD_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
name|class
name|QThreadData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QThreadPrivate
name|class
name|QThreadPrivate
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QThread
range|:
name|public
name|QObject
block|{
name|public
operator|:
specifier|static
name|Qt
operator|::
name|HANDLE
name|currentThreadId
argument_list|()
block|;
specifier|static
name|QThread
operator|*
name|currentThread
argument_list|()
block|;
specifier|static
name|int
name|idealThreadCount
argument_list|()
block|;
specifier|static
name|void
name|yieldCurrentThread
argument_list|()
block|;
name|explicit
name|QThread
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QThread
argument_list|()
block|;      enum
name|Priority
block|{
name|IdlePriority
block|,
name|LowestPriority
block|,
name|LowPriority
block|,
name|NormalPriority
block|,
name|HighPriority
block|,
name|HighestPriority
block|,
name|TimeCriticalPriority
block|,
name|InheritPriority
block|}
block|;
name|void
name|setPriority
argument_list|(
argument|Priority priority
argument_list|)
block|;
name|Priority
name|priority
argument_list|()
specifier|const
block|;
name|bool
name|isFinished
argument_list|()
specifier|const
block|;
name|bool
name|isRunning
argument_list|()
specifier|const
block|;
name|void
name|setStackSize
argument_list|(
argument|uint stackSize
argument_list|)
block|;
name|uint
name|stackSize
argument_list|()
specifier|const
block|;
name|void
name|exit
argument_list|(
argument|int retcode =
literal|0
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|start
argument_list|(
name|Priority
operator|=
name|InheritPriority
argument_list|)
block|;
name|void
name|terminate
argument_list|()
block|;
name|void
name|quit
argument_list|()
block|;
name|public
operator|:
comment|// default argument causes thread to block indefinately
name|bool
name|wait
argument_list|(
argument|unsigned long time = ULONG_MAX
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|started
argument_list|()
block|;
name|void
name|finished
argument_list|()
block|;
name|void
name|terminated
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|void
name|run
argument_list|()
block|;
name|int
name|exec
argument_list|()
block|;
specifier|static
name|void
name|setTerminationEnabled
argument_list|(
argument|bool enabled = true
argument_list|)
block|;
specifier|static
name|void
name|sleep
argument_list|(
argument|unsigned long
argument_list|)
block|;
specifier|static
name|void
name|msleep
argument_list|(
argument|unsigned long
argument_list|)
block|;
specifier|static
name|void
name|usleep
argument_list|(
argument|unsigned long
argument_list|)
block|;
name|protected
operator|:
name|QThread
argument_list|(
name|QThreadPrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|private
operator|:
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QThread
argument_list|)
specifier|static
name|void
name|initialize
argument_list|()
block|;
specifier|static
name|void
name|cleanup
argument_list|()
block|;
name|friend
name|class
name|QCoreApplication
block|;
name|friend
name|class
name|QThreadData
block|; }
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_comment
comment|// QT_NO_THREAD
end_comment
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QThread
range|:
name|public
name|QObject
block|{
name|public
operator|:
specifier|static
name|Qt
operator|::
name|HANDLE
name|currentThreadId
argument_list|()
block|{
return|return
name|Qt
operator|::
name|HANDLE
argument_list|(
name|currentThread
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|QThread
operator|*
name|currentThread
argument_list|()
block|;
name|protected
operator|:
name|QThread
argument_list|(
name|QThreadPrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|private
operator|:
name|explicit
name|QThread
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|QThread
operator|*
name|instance
block|;
name|friend
name|class
name|QCoreApplication
block|;
name|friend
name|class
name|QThreadData
block|;
name|friend
name|class
name|QAdoptedThread
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QThread
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_THREAD
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTHREAD_H
end_comment
end_unit
