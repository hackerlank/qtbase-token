begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWIDGETWINDOW_P_H
end_ifndef
begin_define
DECL|macro|QWIDGETWINDOW_P_H
define|#
directive|define
name|QWIDGETWINDOW_P_H
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
file|<QtGui/qwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qevent_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCloseEvent
name|class
name|QCloseEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMoveEvent
name|class
name|QMoveEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWidgetWindow
range|:
name|public
name|QWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|QWidgetWindow
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
operator|~
name|QWidgetWindow
argument_list|()
block|;
name|QWidget
operator|*
name|widget
argument_list|()
specifier|const
block|{
return|return
name|m_widget
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|QAccessibleInterface
operator|*
name|accessibleRoot
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|QObject
operator|*
name|focusObject
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
argument|QEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|handleCloseEvent
argument_list|(
name|QCloseEvent
operator|*
argument_list|)
block|;
name|void
name|handleEnterLeaveEvent
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|handleFocusInEvent
argument_list|(
name|QFocusEvent
operator|*
argument_list|)
block|;
name|void
name|handleKeyEvent
argument_list|(
name|QKeyEvent
operator|*
argument_list|)
block|;
name|void
name|handleMouseEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|void
name|handleNonClientAreaMouseEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|void
name|handleTouchEvent
argument_list|(
name|QTouchEvent
operator|*
argument_list|)
block|;
name|void
name|handleMoveEvent
argument_list|(
name|QMoveEvent
operator|*
argument_list|)
block|;
name|void
name|handleResizeEvent
argument_list|(
name|QResizeEvent
operator|*
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|void
name|handleWheelEvent
argument_list|(
name|QWheelEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|void
name|handleDragEnterMoveEvent
argument_list|(
name|QDragMoveEvent
operator|*
argument_list|)
block|;
name|void
name|handleDragLeaveEvent
argument_list|(
name|QDragLeaveEvent
operator|*
argument_list|)
block|;
name|void
name|handleDropEvent
argument_list|(
name|QDropEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|void
name|handleExposeEvent
argument_list|(
name|QExposeEvent
operator|*
argument_list|)
block|;
name|void
name|handleWindowStateChangedEvent
argument_list|(
name|QWindowStateChangeEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|nativeEvent
argument_list|(
argument|const QByteArray&eventType
argument_list|,
argument|void *message
argument_list|,
argument|long *result
argument_list|)
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|QT_NO_TABLETEVENT
name|void
name|handleTabletEvent
argument_list|(
name|QTabletEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
name|void
name|handleGestureEvent
argument_list|(
name|QNativeGestureEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|void
name|handleContextMenuEvent
argument_list|(
name|QContextMenuEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|private
name|slots
operator|:
name|void
name|updateObjectName
argument_list|()
block|;
name|void
name|handleScreenChange
argument_list|()
block|;
name|private
operator|:
name|void
name|repaintWindow
argument_list|()
block|;
name|bool
name|updateSize
argument_list|()
block|;
name|bool
name|updatePos
argument_list|()
block|;
name|void
name|updateMargins
argument_list|()
block|;
name|void
name|updateNormalGeometry
argument_list|()
block|;      enum
name|FocusWidgets
block|{
name|FirstFocusWidget
block|,
name|LastFocusWidget
block|}
block|;
name|QWidget
operator|*
name|getFocusWidget
argument_list|(
argument|FocusWidgets fw
argument_list|)
block|;
name|QWidget
operator|*
name|m_widget
block|;
name|QPointer
operator|<
name|QWidget
operator|>
name|m_implicit_mouse_grabber
block|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|QPointer
operator|<
name|QWidget
operator|>
name|m_dragTarget
block|;
endif|#
directive|endif
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
comment|// QWIDGETWINDOW_P_H
end_comment
end_unit
