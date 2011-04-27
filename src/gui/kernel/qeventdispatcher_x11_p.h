begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVENTDISPATCHER_X11_P_H
end_ifndef
begin_define
DECL|macro|QEVENTDISPATCHER_X11_P_H
define|#
directive|define
name|QEVENTDISPATCHER_X11_P_H
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
file|"private/qeventdispatcher_unix_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QEventDispatcherX11Private
name|class
name|QEventDispatcherX11Private
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEventDispatcherX11
range|:
name|public
name|QEventDispatcherUNIX
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QEventDispatcherX11
argument_list|)
name|public
operator|:
name|explicit
name|QEventDispatcherX11
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QEventDispatcherX11
argument_list|()
block|;
name|bool
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
name|protected
operator|:
name|int
name|select
argument_list|(
argument|int nfds
argument_list|,
argument|fd_set *readfds
argument_list|,
argument|fd_set *writefds
argument_list|,
argument|fd_set *exceptfds
argument_list|,
argument|timeval *timeout
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
comment|// QEVENTDISPATCHER_X11_P_H
end_comment
end_unit
