begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFUTUREWATCHER_P_H
end_ifndef
begin_define
DECL|macro|QFUTUREWATCHER_P_H
define|#
directive|define
name|QFUTUREWATCHER_P_H
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
file|"qfutureinterface_p.h"
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QFUTURE
end_ifndef
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFutureWatcherBase
name|class
name|QFutureWatcherBase
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObjectPrivate
name|class
name|QFutureWatcherBasePrivate
range|:
name|public
name|QObjectPrivate
decl_stmt|,
name|public
name|QFutureCallOutInterface
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QFutureWatcherBase
argument_list|)
name|public
label|:
name|QFutureWatcherBasePrivate
argument_list|()
expr_stmt|;
name|void
name|postCallOutEvent
parameter_list|(
specifier|const
name|QFutureCallOutEvent
modifier|&
name|callOutEvent
parameter_list|)
function_decl|;
name|void
name|callOutInterfaceDisconnected
parameter_list|()
function_decl|;
name|void
name|sendCallOutEvent
parameter_list|(
name|QFutureCallOutEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|QList
operator|<
name|QFutureCallOutEvent
operator|*
operator|>
name|pendingCallOutEvents
expr_stmt|;
name|QAtomicInt
name|pendingResultsReady
decl_stmt|;
name|int
name|maximumPendingResultsReady
decl_stmt|;
name|QAtomicInt
name|resultAtConnected
decl_stmt|;
name|bool
name|finished
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QFUTURE
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
