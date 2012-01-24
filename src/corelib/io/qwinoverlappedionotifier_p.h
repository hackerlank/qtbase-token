begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINOVERLAPPEDIONOTIFIER_P_H
end_ifndef
begin_define
DECL|macro|QWINOVERLAPPEDIONOTIFIER_P_H
define|#
directive|define
name|QWINOVERLAPPEDIONOTIFIER_P_H
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
file|<qobject.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
name|class
name|Q_CORE_EXPORT
name|QWinOverlappedIoNotifier
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QWinOverlappedIoNotifier
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QWinOverlappedIoNotifier
argument_list|()
block|;
name|void
name|setHandle
argument_list|(
argument|HANDLE h
argument_list|)
block|;
name|HANDLE
name|handle
argument_list|()
specifier|const
block|{
return|return
name|hHandle
return|;
block|}
name|void
name|setEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|waitForNotified
argument_list|(
argument|int msecs
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|notified
argument_list|(
argument|DWORD numberOfBytes
argument_list|,
argument|DWORD errorCode
argument_list|)
block|;
name|void
name|_q_notify
argument_list|()
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|_q_notified
argument_list|()
block|;
name|private
operator|:
name|void
name|notify
argument_list|(
argument|DWORD numberOfBytes
argument_list|,
argument|DWORD errorCode
argument_list|)
block|;
name|private
operator|:
name|HANDLE
name|hHandle
block|;
name|HANDLE
name|hEvent
block|;
name|DWORD
name|lastNumberOfBytes
block|;
name|DWORD
name|lastErrorCode
block|;
name|friend
name|class
name|QWinIoCompletionPort
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINOVERLAPPEDIONOTIFIER_P_H
end_comment
end_unit
