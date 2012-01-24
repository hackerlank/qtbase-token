begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGESTUREMANAGER_P_H
end_ifndef
begin_define
DECL|macro|QGESTUREMANAGER_P_H
define|#
directive|define
name|QGESTUREMANAGER_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
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
file|"qobject.h"
end_include
begin_include
include|#
directive|include
file|"qbasictimer.h"
end_include
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|"qgesturerecognizer.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QBasicTimer
name|class
name|QBasicTimer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsObject
name|class
name|QGraphicsObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGestureManager
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QGestureManager
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
block|;
operator|~
name|QGestureManager
argument_list|()
block|;
name|Qt
operator|::
name|GestureType
name|registerGestureRecognizer
argument_list|(
name|QGestureRecognizer
operator|*
name|recognizer
argument_list|)
block|;
name|void
name|unregisterGestureRecognizer
argument_list|(
argument|Qt::GestureType type
argument_list|)
block|;
name|bool
name|filterEvent
argument_list|(
name|QWidget
operator|*
name|receiver
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|filterEvent
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
name|bool
name|filterEvent
argument_list|(
name|QGraphicsObject
operator|*
name|receiver
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
endif|#
directive|endif
comment|//QT_NO_GRAPHICSVIEW
specifier|static
name|QGestureManager
operator|*
name|instance
argument_list|()
block|;
comment|// declared in qapplication.cpp
name|void
name|cleanupCachedGestures
argument_list|(
argument|QObject *target
argument_list|,
argument|Qt::GestureType type
argument_list|)
block|;
name|void
name|recycle
argument_list|(
name|QGesture
operator|*
name|gesture
argument_list|)
block|;
name|protected
operator|:
name|bool
name|filterEventThroughContexts
argument_list|(
specifier|const
name|QMultiMap
operator|<
name|QObject
operator|*
argument_list|,
name|Qt
operator|::
name|GestureType
operator|>
operator|&
name|contexts
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
name|QMultiMap
operator|<
name|Qt
operator|::
name|GestureType
block|,
name|QGestureRecognizer
operator|*
operator|>
name|m_recognizers
block|;
name|QSet
operator|<
name|QGesture
operator|*
operator|>
name|m_activeGestures
block|;
name|QSet
operator|<
name|QGesture
operator|*
operator|>
name|m_maybeGestures
block|;      enum
name|State
block|{
name|Gesture
block|,
name|NotGesture
block|,
name|MaybeGesture
comment|// this means timers are up and waiting for some
comment|// more events, and input events are handled by
comment|// gesture recognizer explicitly
block|}
name|state
block|;      struct
name|ObjectGesture
block|{
name|QObject
operator|*
name|object
block|;
name|Qt
operator|::
name|GestureType
name|gesture
block|;
name|ObjectGesture
argument_list|(
name|QObject
operator|*
name|o
argument_list|,
specifier|const
name|Qt
operator|::
name|GestureType
operator|&
name|g
argument_list|)
operator|:
name|object
argument_list|(
name|o
argument_list|)
block|,
name|gesture
argument_list|(
argument|g
argument_list|)
block|{ }
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|ObjectGesture
operator|&
name|rhs
operator|)
specifier|const
block|{
if|if
condition|(
name|object
operator|<
name|rhs
operator|.
name|object
condition|)
return|return
name|true
return|;
if|if
condition|(
name|object
operator|==
name|rhs
operator|.
name|object
condition|)
return|return
name|gesture
operator|<
name|rhs
operator|.
name|gesture
return|;
return|return
name|false
return|;
block|}
end_decl_stmt
begin_expr_stmt
unit|};
name|QMap
operator|<
name|ObjectGesture
operator|,
name|QList
operator|<
name|QGesture
operator|*
operator|>
expr|>
name|m_objectGestures
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QHash
operator|<
name|QGesture
operator|*
operator|,
name|QGestureRecognizer
operator|*
operator|>
name|m_gestureToRecognizer
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QHash
operator|<
name|QGesture
operator|*
operator|,
name|QObject
operator|*
operator|>
name|m_gestureOwners
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QHash
operator|<
name|QGesture
operator|*
operator|,
name|QWidget
operator|*
operator|>
name|m_gestureTargets
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|int
name|m_lastCustomGestureId
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QHash
operator|<
name|QGestureRecognizer
operator|*
operator|,
name|QSet
operator|<
name|QGesture
operator|*
operator|>
expr|>
name|m_obsoleteGestures
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QHash
operator|<
name|QGesture
operator|*
operator|,
name|QGestureRecognizer
operator|*
operator|>
name|m_deletedRecognizers
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QSet
operator|<
name|QGesture
operator|*
operator|>
name|m_gesturesToDelete
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|cleanupGesturesForRemovedRecognizer
parameter_list|(
name|QGesture
modifier|*
name|gesture
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QGesture
modifier|*
name|getState
argument_list|(
name|QObject
operator|*
name|widget
argument_list|,
name|QGestureRecognizer
operator|*
name|recognizer
argument_list|,
name|Qt
operator|::
name|GestureType
name|gesture
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|deliverEvents
argument_list|(
specifier|const
name|QSet
operator|<
name|QGesture
operator|*
operator|>
operator|&
name|gestures
argument_list|,
name|QSet
operator|<
name|QGesture
operator|*
operator|>
operator|*
name|undeliveredGestures
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|getGestureTargets
argument_list|(
specifier|const
name|QSet
operator|<
name|QGesture
operator|*
operator|>
operator|&
name|gestures
argument_list|,
name|QMap
operator|<
name|QWidget
operator|*
argument_list|,
name|QList
operator|<
name|QGesture
operator|*
operator|>
expr|>
operator|*
name|conflicts
argument_list|,
name|QMap
operator|<
name|QWidget
operator|*
argument_list|,
name|QList
operator|<
name|QGesture
operator|*
operator|>
expr|>
operator|*
name|normal
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|cancelGesturesForChildren
parameter_list|(
name|QGesture
modifier|*
name|originatingGesture
parameter_list|)
function_decl|;
end_function_decl
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_GESTURES
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGESTUREMANAGER_P_H
end_comment
end_unit
