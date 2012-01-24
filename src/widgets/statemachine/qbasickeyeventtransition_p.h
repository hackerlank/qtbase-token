begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBASICKEYEVENTTRANSITION_P_H
end_ifndef
begin_define
DECL|macro|QBASICKEYEVENTTRANSITION_P_H
define|#
directive|define
name|QBASICKEYEVENTTRANSITION_P_H
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
file|<QtCore/qabstracttransition.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE
end_ifndef
begin_include
include|#
directive|include
file|<QtGui/qevent.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QBasicKeyEventTransitionPrivate
name|class
name|QBasicKeyEventTransitionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QBasicKeyEventTransition
range|:
name|public
name|QAbstractTransition
block|{
name|Q_OBJECT
name|public
operator|:
name|QBasicKeyEventTransition
argument_list|(
name|QState
operator|*
name|sourceState
operator|=
literal|0
argument_list|)
block|;
name|QBasicKeyEventTransition
argument_list|(
argument|QEvent::Type type
argument_list|,
argument|int key
argument_list|,
argument|QState *sourceState =
literal|0
argument_list|)
block|;
name|QBasicKeyEventTransition
argument_list|(
argument|QEvent::Type type
argument_list|,
argument|int key
argument_list|,
argument|Qt::KeyboardModifiers modifierMask
argument_list|,
argument|QState *sourceState =
literal|0
argument_list|)
block|;
operator|~
name|QBasicKeyEventTransition
argument_list|()
block|;
name|QEvent
operator|::
name|Type
name|eventType
argument_list|()
specifier|const
block|;
name|void
name|setEventType
argument_list|(
argument|QEvent::Type type
argument_list|)
block|;
name|int
name|key
argument_list|()
specifier|const
block|;
name|void
name|setKey
argument_list|(
argument|int key
argument_list|)
block|;
name|Qt
operator|::
name|KeyboardModifiers
name|modifierMask
argument_list|()
specifier|const
block|;
name|void
name|setModifierMask
argument_list|(
argument|Qt::KeyboardModifiers modifiers
argument_list|)
block|;
name|protected
operator|:
name|bool
name|eventTest
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|onTransition
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QBasicKeyEventTransition
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QBasicKeyEventTransition
argument_list|)
block|}
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
comment|//QT_NO_STATEMACHINE
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
