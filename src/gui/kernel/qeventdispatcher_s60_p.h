begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVENTDISPATCHER_S60_P_H
end_ifndef
begin_define
DECL|macro|QEVENTDISPATCHER_S60_P_H
define|#
directive|define
name|QEVENTDISPATCHER_S60_P_H
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
file|<private/qeventdispatcher_symbian_p.h>
end_include
begin_include
include|#
directive|include
file|"qt_s60_p.h"
end_include
begin_include
include|#
directive|include
file|<eikenv.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QEventDispatcherS60
name|class
name|QEventDispatcherS60
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QtEikonEnv
range|:
name|public
name|CEikonEnv
block|{
name|public
operator|:
name|QtEikonEnv
argument_list|()
block|;
operator|~
name|QtEikonEnv
argument_list|()
block|;
comment|// from CActive.
name|void
name|RunL
argument_list|()
block|;
name|void
name|DoCancel
argument_list|()
block|;
name|void
name|complete
argument_list|()
block|;
name|private
operator|:
comment|// Workaround for a BC break from S60 3.2 -> 5.0, where the CEikonEnv override was removed.
comment|// To avoid linking to that when we build against 3.2, define an empty body here.
comment|// Reserved_*() have been verified to be empty in the S60 code.
name|void
name|Reserved_1
argument_list|()
block|{}
name|void
name|Reserved_2
argument_list|()
block|{}
name|private
operator|:
name|int
name|m_lastIterationCount
block|;
name|TInt
name|m_savedStatusCode
block|;
name|bool
name|m_hasAlreadyRun
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QEventDispatcherS60
range|:
name|public
name|QEventDispatcherSymbian
block|{
name|Q_OBJECT
name|public
operator|:
name|QEventDispatcherS60
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QEventDispatcherS60
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
name|bool
name|excludeUserInputEvents
argument_list|()
block|{
return|return
name|m_noInputEvents
return|;
block|}
name|void
name|saveInputEvent
argument_list|(
name|QSymbianControl
operator|*
name|control
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|,
name|QInputEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|reactivateDeferredActiveObjects
argument_list|()
block|;
name|private
operator|:
name|bool
name|sendDeferredInputEvents
argument_list|()
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|removeInputEventsForWidget
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|private
operator|:
name|bool
name|m_noInputEvents
block|;      struct
name|DeferredInputEvent
block|{
name|QSymbianControl
operator|*
name|control
block|;
name|QWidget
operator|*
name|widget
block|;
name|QInputEvent
operator|*
name|event
block|;     }
block|;
name|QList
operator|<
name|DeferredInputEvent
operator|>
name|m_deferredInputEvents
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
comment|// QEVENTDISPATCHER_S60_P_H
end_comment
end_unit
