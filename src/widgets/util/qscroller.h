begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSCROLLER_H
end_ifndef
begin_define
DECL|macro|QSCROLLER_H
define|#
directive|define
name|QSCROLLER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QPointF>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QScrollerProperties>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScrollerPrivate
name|class
name|QScrollerPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScrollerProperties
name|class
name|QScrollerProperties
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
end_ifndef
begin_decl_stmt
DECL|variable|QFlickGestureRecognizer
name|class
name|QFlickGestureRecognizer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMouseFlickGestureRecognizer
name|class
name|QMouseFlickGestureRecognizer
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QScroller
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|State state READ state NOTIFY stateChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QScrollerProperties scrollerProperties READ scrollerProperties WRITE setScrollerProperties NOTIFY scrollerPropertiesChanged
argument_list|)
name|public
operator|:
expr|enum
name|State
block|{
name|Inactive
block|,
name|Pressed
block|,
name|Dragging
block|,
name|Scrolling
block|}
block|;
name|Q_ENUM
argument_list|(
name|State
argument_list|)
expr|enum
name|ScrollerGestureType
block|{
name|TouchGesture
block|,
name|LeftMouseButtonGesture
block|,
name|RightMouseButtonGesture
block|,
name|MiddleMouseButtonGesture
block|}
block|;      enum
name|Input
block|{
name|InputPress
operator|=
literal|1
block|,
name|InputMove
block|,
name|InputRelease
block|}
block|;
specifier|static
name|bool
name|hasScroller
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
specifier|static
name|QScroller
operator|*
name|scroller
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
specifier|static
specifier|const
name|QScroller
operator|*
name|scroller
argument_list|(
specifier|const
name|QObject
operator|*
name|target
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
specifier|static
name|Qt
operator|::
name|GestureType
name|grabGesture
argument_list|(
argument|QObject *target
argument_list|,
argument|ScrollerGestureType gestureType = TouchGesture
argument_list|)
block|;
specifier|static
name|Qt
operator|::
name|GestureType
name|grabbedGesture
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
specifier|static
name|void
name|ungrabGesture
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
endif|#
directive|endif
specifier|static
name|QList
operator|<
name|QScroller
operator|*
operator|>
name|activeScrollers
argument_list|()
block|;
name|QObject
operator|*
name|target
argument_list|()
specifier|const
block|;
name|State
name|state
argument_list|()
specifier|const
block|;
name|bool
name|handleInput
argument_list|(
argument|Input input
argument_list|,
argument|const QPointF&position
argument_list|,
argument|qint64 timestamp =
literal|0
argument_list|)
block|;
name|void
name|stop
argument_list|()
block|;
name|QPointF
name|velocity
argument_list|()
specifier|const
block|;
name|QPointF
name|finalPosition
argument_list|()
specifier|const
block|;
name|QPointF
name|pixelPerMeter
argument_list|()
specifier|const
block|;
name|QScrollerProperties
name|scrollerProperties
argument_list|()
specifier|const
block|;
name|void
name|setSnapPositionsX
argument_list|(
specifier|const
name|QList
operator|<
name|qreal
operator|>
operator|&
name|positions
argument_list|)
block|;
name|void
name|setSnapPositionsX
argument_list|(
argument|qreal first
argument_list|,
argument|qreal interval
argument_list|)
block|;
name|void
name|setSnapPositionsY
argument_list|(
specifier|const
name|QList
operator|<
name|qreal
operator|>
operator|&
name|positions
argument_list|)
block|;
name|void
name|setSnapPositionsY
argument_list|(
argument|qreal first
argument_list|,
argument|qreal interval
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setScrollerProperties
argument_list|(
specifier|const
name|QScrollerProperties
operator|&
name|prop
argument_list|)
block|;
name|void
name|scrollTo
argument_list|(
specifier|const
name|QPointF
operator|&
name|pos
argument_list|)
block|;
name|void
name|scrollTo
argument_list|(
argument|const QPointF&pos
argument_list|,
argument|int scrollTime
argument_list|)
block|;
name|void
name|ensureVisible
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|qreal xmargin
argument_list|,
argument|qreal ymargin
argument_list|)
block|;
name|void
name|ensureVisible
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|qreal xmargin
argument_list|,
argument|qreal ymargin
argument_list|,
argument|int scrollTime
argument_list|)
block|;
name|void
name|resendPrepareEvent
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|stateChanged
argument_list|(
argument|QScroller::State newstate
argument_list|)
block|;
name|void
name|scrollerPropertiesChanged
argument_list|(
specifier|const
name|QScrollerProperties
operator|&
argument_list|)
block|;
name|private
operator|:
name|QScrollerPrivate
operator|*
name|d_ptr
block|;
name|QScroller
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
name|virtual
operator|~
name|QScroller
argument_list|()
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QScroller
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QScroller
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
name|friend
name|class
name|QFlickGestureRecognizer
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
comment|// QSCROLLER_H
end_comment
end_unit
