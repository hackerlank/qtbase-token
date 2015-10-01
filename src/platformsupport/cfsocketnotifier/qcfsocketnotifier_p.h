begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCFSOCKETNOTIFIER_P_H
end_ifndef
begin_define
DECL|macro|QCFSOCKETNOTIFIER_P_H
define|#
directive|define
name|QCFSOCKETNOTIFIER_P_H
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
file|<QtCore/qabstracteventdispatcher.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_include
include|#
directive|include
file|<CoreFoundation/CoreFoundation.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|MacSocketInfo
struct|struct
name|MacSocketInfo
block|{
DECL|function|MacSocketInfo
name|MacSocketInfo
argument_list|()
operator|:
name|socket
argument_list|(
literal|0
argument_list|)
operator|,
name|runloop
argument_list|(
literal|0
argument_list|)
operator|,
name|readNotifier
argument_list|(
literal|0
argument_list|)
operator|,
name|writeNotifier
argument_list|(
literal|0
argument_list|)
operator|,
name|readEnabled
argument_list|(
name|false
argument_list|)
operator|,
name|writeEnabled
argument_list|(
argument|false
argument_list|)
block|{}
DECL|member|socket
name|CFSocketRef
name|socket
expr_stmt|;
DECL|member|runloop
name|CFRunLoopSourceRef
name|runloop
decl_stmt|;
DECL|member|readNotifier
name|QObject
modifier|*
name|readNotifier
decl_stmt|;
DECL|member|writeNotifier
name|QObject
modifier|*
name|writeNotifier
decl_stmt|;
DECL|member|readEnabled
name|bool
name|readEnabled
decl_stmt|;
DECL|member|writeEnabled
name|bool
name|writeEnabled
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|MacSocketHash
typedef|typedef
name|QHash
operator|<
name|int
operator|,
name|MacSocketInfo
operator|*
operator|>
name|MacSocketHash
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|MaybeCancelWaitForMoreEventsFn
typedef|typedef
name|void
function_decl|(
modifier|*
name|MaybeCancelWaitForMoreEventsFn
function_decl|)
parameter_list|(
name|QAbstractEventDispatcher
modifier|*
name|hostEventDispacher
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|// The CoreFoundationSocketNotifier class implements socket notifiers support using
end_comment
begin_comment
comment|// CFSocket for event dispatchers running on top of the Core Foundation run loop system.
end_comment
begin_comment
comment|// (currently Mac and iOS)
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// The principal functions are registerSocketNotifier() and unregisterSocketNotifier().
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// setHostEventDispatcher() should be called at startup.
end_comment
begin_comment
comment|// removeSocketNotifiers() should be called at shutdown.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|QCFSocketNotifier
block|{
name|public
label|:
name|QCFSocketNotifier
argument_list|()
expr_stmt|;
operator|~
name|QCFSocketNotifier
argument_list|()
expr_stmt|;
name|void
name|setHostEventDispatcher
parameter_list|(
name|QAbstractEventDispatcher
modifier|*
name|hostEventDispacher
parameter_list|)
function_decl|;
name|void
name|setMaybeCancelWaitForMoreEventsCallback
parameter_list|(
name|MaybeCancelWaitForMoreEventsFn
name|callBack
parameter_list|)
function_decl|;
name|void
name|registerSocketNotifier
parameter_list|(
name|QSocketNotifier
modifier|*
name|notifier
parameter_list|)
function_decl|;
name|void
name|unregisterSocketNotifier
parameter_list|(
name|QSocketNotifier
modifier|*
name|notifier
parameter_list|)
function_decl|;
name|void
name|enableSocketNotifiers
parameter_list|()
function_decl|;
name|void
name|removeSocketNotifiers
parameter_list|()
function_decl|;
name|MacSocketHash
name|macSockets
decl_stmt|;
name|QAbstractEventDispatcher
modifier|*
name|eventDispatcher
decl_stmt|;
name|MaybeCancelWaitForMoreEventsFn
name|maybeCancelWaitForMoreEvents
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
end_unit
