begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVENT_P_H
end_ifndef
begin_define
DECL|macro|QEVENT_P_H
define|#
directive|define
name|QEVENT_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qurl.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qevent.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|//
comment|//  W A R N I N G
comment|//  -------------
comment|//
comment|// This file is not part of the Qt API.  It exists purely as an
comment|// implementation detail.  This header file may change from version to
comment|// version without notice, or even be removed.
comment|//
comment|// We mean it.
comment|//
name|class
name|QTouchEventTouchPointPrivate
block|{
name|public
label|:
specifier|inline
name|QTouchEventTouchPointPrivate
argument_list|(
argument|int id
argument_list|)
operator|:
name|ref
argument_list|(
literal|1
argument_list|)
operator|,
name|id
argument_list|(
name|id
argument_list|)
operator|,
name|state
argument_list|(
name|Qt
operator|::
name|TouchPointReleased
argument_list|)
operator|,
name|pressure
argument_list|(
argument|qreal(-
literal|1.
argument|)
argument_list|)
block|{ }
specifier|inline
name|QTouchEventTouchPointPrivate
operator|*
name|detach
argument_list|()
block|{
name|QTouchEventTouchPointPrivate
operator|*
name|d
operator|=
name|new
name|QTouchEventTouchPointPrivate
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|d
operator|->
name|ref
operator|.
name|store
argument_list|(
literal|1
argument_list|)
block|;
if|if
condition|(
operator|!
name|this
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|delete
name|this
decl_stmt|;
return|return
name|d
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|QAtomicInt
name|ref
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|id
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|TouchPointStates
name|state
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QRectF
name|rect
decl_stmt|,
name|sceneRect
decl_stmt|,
name|screenRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPointF
name|normalizedPos
decl_stmt|,
name|startPos
decl_stmt|,
name|startScenePos
decl_stmt|,
name|startScreenPos
decl_stmt|,
name|startNormalizedPos
decl_stmt|,
name|lastPos
decl_stmt|,
name|lastScenePos
decl_stmt|,
name|lastScreenPos
decl_stmt|,
name|lastNormalizedPos
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|qreal
name|pressure
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QVector2D
name|velocity
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QTouchEvent
operator|::
name|TouchPoint
operator|::
name|InfoFlags
name|flags
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QVector
operator|<
name|QPointF
operator|>
name|rawScreenPositions
expr_stmt|;
end_expr_stmt
begin_ifndef
unit|};
ifndef|#
directive|ifndef
name|QT_NO_TABLETEVENT
end_ifndef
begin_decl_stmt
name|class
name|QTabletEventPrivate
block|{
name|public
label|:
specifier|inline
name|QTabletEventPrivate
argument_list|(
argument|Qt::MouseButton button
argument_list|,
argument|Qt::MouseButtons buttons
argument_list|)
operator|:
name|b
argument_list|(
name|button
argument_list|)
operator|,
name|buttonState
argument_list|(
argument|buttons
argument_list|)
block|{ }
name|Qt
operator|::
name|MouseButton
name|b
expr_stmt|;
name|Qt
operator|::
name|MouseButtons
name|buttonState
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TABLETEVENT
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QEVENT_P_H
end_comment
end_unit
