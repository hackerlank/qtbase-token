begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSYSTEMINTERFACE_P_H
end_ifndef
begin_define
DECL|macro|QWINDOWSYSTEMINTERFACE_P_H
define|#
directive|define
name|QWINDOWSYSTEMINTERFACE_P_H
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
file|"qwindowsysteminterface.h"
end_include
begin_include
include|#
directive|include
file|<QElapsedTimer>
end_include
begin_include
include|#
directive|include
file|<QPointer>
end_include
begin_include
include|#
directive|include
file|<QMutex>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QWaitCondition>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_GUI_EXPORT
name|QWindowSystemInterfacePrivate
block|{
name|public
label|:
enum|enum
name|EventType
block|{
name|UserInputEvent
init|=
literal|0x100
block|,
name|Close
init|=
name|UserInputEvent
operator||
literal|0x01
block|,
name|GeometryChange
init|=
literal|0x02
block|,
name|Enter
init|=
name|UserInputEvent
operator||
literal|0x03
block|,
name|Leave
init|=
name|UserInputEvent
operator||
literal|0x04
block|,
name|ActivatedWindow
init|=
literal|0x05
block|,
name|WindowStateChanged
init|=
literal|0x06
block|,
name|Mouse
init|=
name|UserInputEvent
operator||
literal|0x07
block|,
name|FrameStrutMouse
init|=
name|UserInputEvent
operator||
literal|0x08
block|,
name|Wheel
init|=
name|UserInputEvent
operator||
literal|0x09
block|,
name|Key
init|=
name|UserInputEvent
operator||
literal|0x0a
block|,
name|Touch
init|=
name|UserInputEvent
operator||
literal|0x0b
block|,
name|ScreenOrientation
init|=
literal|0x0c
block|,
name|ScreenGeometry
init|=
literal|0x0d
block|,
name|ScreenAvailableGeometry
init|=
literal|0x0e
block|,
name|ScreenLogicalDotsPerInch
init|=
literal|0x0f
block|,
name|ScreenRefreshRate
init|=
literal|0x10
block|,
name|ThemeChange
init|=
literal|0x11
block|,
name|Expose
init|=
literal|0x12
block|,
name|FileOpen
init|=
name|UserInputEvent
operator||
literal|0x13
block|,
name|Tablet
init|=
name|UserInputEvent
operator||
literal|0x14
block|,
name|TabletEnterProximity
init|=
name|UserInputEvent
operator||
literal|0x15
block|,
name|TabletLeaveProximity
init|=
name|UserInputEvent
operator||
literal|0x16
block|,
name|PlatformPanel
init|=
name|UserInputEvent
operator||
literal|0x17
block|,
name|ContextMenu
init|=
name|UserInputEvent
operator||
literal|0x18
block|,
name|EnterWhatsThisMode
init|=
name|UserInputEvent
operator||
literal|0x19
block|,
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
name|Gesture
init|=
name|UserInputEvent
operator||
literal|0x1a
block|,
endif|#
directive|endif
name|ApplicationStateChanged
init|=
literal|0x19
block|,
name|FlushEvents
init|=
literal|0x20
block|,
name|WindowScreenChanged
init|=
literal|0x21
block|}
enum|;
name|class
name|WindowSystemEvent
block|{
name|public
label|:
enum|enum
block|{
name|Synthetic
init|=
literal|0x1
block|,
name|NullWindow
init|=
literal|0x2
block|}
enum|;
name|explicit
name|WindowSystemEvent
argument_list|(
argument|EventType t
argument_list|)
block|:
name|type
argument_list|(
name|t
argument_list|)
operator|,
name|flags
argument_list|(
literal|0
argument_list|)
block|{ }
name|virtual
operator|~
name|WindowSystemEvent
argument_list|()
block|{ }
name|bool
name|synthetic
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|Synthetic
return|;
block|}
name|bool
name|nullWindow
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|NullWindow
return|;
block|}
name|EventType
name|type
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
empty_stmt|;
name|class
name|CloseEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|explicit
name|CloseEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|bool
operator|*
name|a
operator|=
literal|0
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|Close
argument_list|)
block|,
name|window
argument_list|(
name|w
argument_list|)
block|,
name|accepted
argument_list|(
argument|a
argument_list|)
block|{ }
name|QPointer
operator|<
name|QWindow
operator|>
name|window
block|;
name|bool
operator|*
name|accepted
block|;     }
decl_stmt|;
name|class
name|GeometryChangeEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|GeometryChangeEvent
argument_list|(
name|QWindow
operator|*
name|tlw
argument_list|,
specifier|const
name|QRect
operator|&
name|newGeometry
argument_list|,
specifier|const
name|QRect
operator|&
name|oldGeometry
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|GeometryChange
argument_list|)
block|,
name|tlw
argument_list|(
name|tlw
argument_list|)
block|,
name|newGeometry
argument_list|(
name|newGeometry
argument_list|)
block|,
name|oldGeometry
argument_list|(
argument|oldGeometry
argument_list|)
block|{ }
name|QPointer
operator|<
name|QWindow
operator|>
name|tlw
block|;
name|QRect
name|newGeometry
block|;
name|QRect
name|oldGeometry
block|;     }
decl_stmt|;
name|class
name|EnterEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|explicit
name|EnterEvent
argument_list|(
name|QWindow
operator|*
name|enter
argument_list|,
specifier|const
name|QPointF
operator|&
name|local
argument_list|,
specifier|const
name|QPointF
operator|&
name|global
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|Enter
argument_list|)
block|,
name|enter
argument_list|(
name|enter
argument_list|)
block|,
name|localPos
argument_list|(
name|local
argument_list|)
block|,
name|globalPos
argument_list|(
argument|global
argument_list|)
block|{ }
name|QPointer
operator|<
name|QWindow
operator|>
name|enter
block|;
specifier|const
name|QPointF
name|localPos
block|;
specifier|const
name|QPointF
name|globalPos
block|;     }
decl_stmt|;
name|class
name|LeaveEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|explicit
name|LeaveEvent
argument_list|(
name|QWindow
operator|*
name|leave
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|Leave
argument_list|)
block|,
name|leave
argument_list|(
argument|leave
argument_list|)
block|{ }
name|QPointer
operator|<
name|QWindow
operator|>
name|leave
block|;     }
decl_stmt|;
name|class
name|ActivatedWindowEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|explicit
name|ActivatedWindowEvent
argument_list|(
argument|QWindow *activatedWindow
argument_list|,
argument|Qt::FocusReason r
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|ActivatedWindow
argument_list|)
block|,
name|activated
argument_list|(
name|activatedWindow
argument_list|)
block|,
name|reason
argument_list|(
argument|r
argument_list|)
block|{ }
name|QPointer
operator|<
name|QWindow
operator|>
name|activated
block|;
name|Qt
operator|::
name|FocusReason
name|reason
block|;     }
decl_stmt|;
name|class
name|WindowStateChangedEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|WindowStateChangedEvent
argument_list|(
argument|QWindow *_window
argument_list|,
argument|Qt::WindowState _newState
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|WindowStateChanged
argument_list|)
block|,
name|window
argument_list|(
name|_window
argument_list|)
block|,
name|newState
argument_list|(
argument|_newState
argument_list|)
block|{ }
name|QPointer
operator|<
name|QWindow
operator|>
name|window
block|;
name|Qt
operator|::
name|WindowState
name|newState
block|;     }
decl_stmt|;
name|class
name|WindowScreenChangedEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|WindowScreenChangedEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|QScreen
operator|*
name|s
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|WindowScreenChanged
argument_list|)
block|,
name|window
argument_list|(
name|w
argument_list|)
block|,
name|screen
argument_list|(
argument|s
argument_list|)
block|{ }
name|QPointer
operator|<
name|QWindow
operator|>
name|window
block|;
name|QPointer
operator|<
name|QScreen
operator|>
name|screen
block|;     }
decl_stmt|;
name|class
name|ApplicationStateChangedEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|ApplicationStateChangedEvent
argument_list|(
argument|Qt::ApplicationState newState
argument_list|,
argument|bool forcePropagate = false
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|ApplicationStateChanged
argument_list|)
block|,
name|newState
argument_list|(
name|newState
argument_list|)
block|,
name|forcePropagate
argument_list|(
argument|forcePropagate
argument_list|)
block|{ }
name|Qt
operator|::
name|ApplicationState
name|newState
block|;
name|bool
name|forcePropagate
block|;     }
decl_stmt|;
name|class
name|FlushEventsEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|FlushEventsEvent
argument_list|(
argument|QEventLoop::ProcessEventsFlags f = QEventLoop::AllEvents
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|FlushEvents
argument_list|)
block|,
name|flags
argument_list|(
argument|f
argument_list|)
block|{ }
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
block|;     }
decl_stmt|;
name|class
name|UserEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|UserEvent
argument_list|(
argument|QWindow * w
argument_list|,
argument|ulong time
argument_list|,
argument|EventType t
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|t
argument_list|)
block|,
name|window
argument_list|(
name|w
argument_list|)
block|,
name|timestamp
argument_list|(
argument|time
argument_list|)
block|{
if|if
condition|(
operator|!
name|w
condition|)
name|flags
operator||=
name|NullWindow
expr_stmt|;
block|}
name|QPointer
operator|<
name|QWindow
operator|>
name|window
block|;
name|unsigned
name|long
name|timestamp
block|;     }
decl_stmt|;
name|class
name|InputEvent
range|:
name|public
name|UserEvent
block|{
name|public
operator|:
name|InputEvent
argument_list|(
argument|QWindow * w
argument_list|,
argument|ulong time
argument_list|,
argument|EventType t
argument_list|,
argument|Qt::KeyboardModifiers mods
argument_list|)
operator|:
name|UserEvent
argument_list|(
name|w
argument_list|,
name|time
argument_list|,
name|t
argument_list|)
block|,
name|modifiers
argument_list|(
argument|mods
argument_list|)
block|{}
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
block|;     }
decl_stmt|;
name|class
name|MouseEvent
range|:
name|public
name|InputEvent
block|{
name|public
operator|:
name|MouseEvent
argument_list|(
argument|QWindow * w
argument_list|,
argument|ulong time
argument_list|,
argument|const QPointF& local
argument_list|,
argument|const QPointF& global
argument_list|,
argument|Qt::MouseButtons b
argument_list|,
argument|Qt::KeyboardModifiers mods
argument_list|,
argument|Qt::MouseEventSource src = Qt::MouseEventNotSynthesized
argument_list|)
operator|:
name|InputEvent
argument_list|(
name|w
argument_list|,
name|time
argument_list|,
name|Mouse
argument_list|,
name|mods
argument_list|)
block|,
name|localPos
argument_list|(
name|local
argument_list|)
block|,
name|globalPos
argument_list|(
name|global
argument_list|)
block|,
name|buttons
argument_list|(
name|b
argument_list|)
block|,
name|source
argument_list|(
argument|src
argument_list|)
block|{ }
name|MouseEvent
argument_list|(
argument|QWindow * w
argument_list|,
argument|ulong time
argument_list|,
argument|EventType t
argument_list|,
argument|const QPointF& local
argument_list|,
argument|const QPointF& global
argument_list|,
argument|Qt::MouseButtons b
argument_list|,
argument|Qt::KeyboardModifiers mods
argument_list|,
argument|Qt::MouseEventSource src = Qt::MouseEventNotSynthesized
argument_list|)
operator|:
name|InputEvent
argument_list|(
name|w
argument_list|,
name|time
argument_list|,
name|t
argument_list|,
name|mods
argument_list|)
block|,
name|localPos
argument_list|(
name|local
argument_list|)
block|,
name|globalPos
argument_list|(
name|global
argument_list|)
block|,
name|buttons
argument_list|(
name|b
argument_list|)
block|,
name|source
argument_list|(
argument|src
argument_list|)
block|{ }
name|QPointF
name|localPos
block|;
name|QPointF
name|globalPos
block|;
name|Qt
operator|::
name|MouseButtons
name|buttons
block|;
name|Qt
operator|::
name|MouseEventSource
name|source
block|;     }
decl_stmt|;
name|class
name|WheelEvent
range|:
name|public
name|InputEvent
block|{
name|public
operator|:
name|WheelEvent
argument_list|(
argument|QWindow *w
argument_list|,
argument|ulong time
argument_list|,
argument|const QPointF& local
argument_list|,
argument|const QPointF& global
argument_list|,
argument|QPoint pixelD
argument_list|,
argument|QPoint angleD
argument_list|,
argument|int qt4D
argument_list|,
argument|Qt::Orientation qt4O
argument_list|,
argument|Qt::KeyboardModifiers mods
argument_list|,
argument|Qt::ScrollPhase phase = Qt::ScrollUpdate
argument_list|,
argument|Qt::MouseEventSource src = Qt::MouseEventNotSynthesized
argument_list|)
operator|:
name|InputEvent
argument_list|(
name|w
argument_list|,
name|time
argument_list|,
name|Wheel
argument_list|,
name|mods
argument_list|)
block|,
name|pixelDelta
argument_list|(
name|pixelD
argument_list|)
block|,
name|angleDelta
argument_list|(
name|angleD
argument_list|)
block|,
name|qt4Delta
argument_list|(
name|qt4D
argument_list|)
block|,
name|qt4Orientation
argument_list|(
name|qt4O
argument_list|)
block|,
name|localPos
argument_list|(
name|local
argument_list|)
block|,
name|globalPos
argument_list|(
name|global
argument_list|)
block|,
name|phase
argument_list|(
name|phase
argument_list|)
block|,
name|source
argument_list|(
argument|src
argument_list|)
block|{ }
name|QPoint
name|pixelDelta
block|;
name|QPoint
name|angleDelta
block|;
name|int
name|qt4Delta
block|;
name|Qt
operator|::
name|Orientation
name|qt4Orientation
block|;
name|QPointF
name|localPos
block|;
name|QPointF
name|globalPos
block|;
name|Qt
operator|::
name|ScrollPhase
name|phase
block|;
name|Qt
operator|::
name|MouseEventSource
name|source
block|;     }
decl_stmt|;
name|class
name|KeyEvent
range|:
name|public
name|InputEvent
block|{
name|public
operator|:
name|KeyEvent
argument_list|(
argument|QWindow *w
argument_list|,
argument|ulong time
argument_list|,
argument|QEvent::Type t
argument_list|,
argument|int k
argument_list|,
argument|Qt::KeyboardModifiers mods
argument_list|,
argument|const QString& text = QString()
argument_list|,
argument|bool autorep = false
argument_list|,
argument|ushort count =
literal|1
argument_list|)
operator|:
name|InputEvent
argument_list|(
name|w
argument_list|,
name|time
argument_list|,
name|Key
argument_list|,
name|mods
argument_list|)
block|,
name|key
argument_list|(
name|k
argument_list|)
block|,
name|unicode
argument_list|(
name|text
argument_list|)
block|,
name|repeat
argument_list|(
name|autorep
argument_list|)
block|,
name|repeatCount
argument_list|(
name|count
argument_list|)
block|,
name|keyType
argument_list|(
name|t
argument_list|)
block|,
name|nativeScanCode
argument_list|(
literal|0
argument_list|)
block|,
name|nativeVirtualKey
argument_list|(
literal|0
argument_list|)
block|,
name|nativeModifiers
argument_list|(
literal|0
argument_list|)
block|{ }
name|KeyEvent
argument_list|(
argument|QWindow *w
argument_list|,
argument|ulong time
argument_list|,
argument|QEvent::Type t
argument_list|,
argument|int k
argument_list|,
argument|Qt::KeyboardModifiers mods
argument_list|,
argument|quint32 nativeSC
argument_list|,
argument|quint32 nativeVK
argument_list|,
argument|quint32 nativeMods
argument_list|,
argument|const QString& text = QString()
argument_list|,
argument|bool autorep = false
argument_list|,
argument|ushort count =
literal|1
argument_list|)
operator|:
name|InputEvent
argument_list|(
name|w
argument_list|,
name|time
argument_list|,
name|Key
argument_list|,
name|mods
argument_list|)
block|,
name|key
argument_list|(
name|k
argument_list|)
block|,
name|unicode
argument_list|(
name|text
argument_list|)
block|,
name|repeat
argument_list|(
name|autorep
argument_list|)
block|,
name|repeatCount
argument_list|(
name|count
argument_list|)
block|,
name|keyType
argument_list|(
name|t
argument_list|)
block|,
name|nativeScanCode
argument_list|(
name|nativeSC
argument_list|)
block|,
name|nativeVirtualKey
argument_list|(
name|nativeVK
argument_list|)
block|,
name|nativeModifiers
argument_list|(
argument|nativeMods
argument_list|)
block|{ }
name|int
name|key
block|;
name|QString
name|unicode
block|;
name|bool
name|repeat
block|;
name|ushort
name|repeatCount
block|;
name|QEvent
operator|::
name|Type
name|keyType
block|;
name|quint32
name|nativeScanCode
block|;
name|quint32
name|nativeVirtualKey
block|;
name|quint32
name|nativeModifiers
block|;     }
decl_stmt|;
name|class
name|TouchEvent
range|:
name|public
name|InputEvent
block|{
name|public
operator|:
name|TouchEvent
argument_list|(
argument|QWindow *w
argument_list|,
argument|ulong time
argument_list|,
argument|QEvent::Type t
argument_list|,
argument|QTouchDevice *dev
argument_list|,
argument|const QList<QTouchEvent::TouchPoint>&p
argument_list|,
argument|Qt::KeyboardModifiers mods
argument_list|)
operator|:
name|InputEvent
argument_list|(
name|w
argument_list|,
name|time
argument_list|,
name|Touch
argument_list|,
name|mods
argument_list|)
block|,
name|device
argument_list|(
name|dev
argument_list|)
block|,
name|points
argument_list|(
name|p
argument_list|)
block|,
name|touchType
argument_list|(
argument|t
argument_list|)
block|{ }
name|QTouchDevice
operator|*
name|device
block|;
name|QList
operator|<
name|QTouchEvent
operator|::
name|TouchPoint
operator|>
name|points
block|;
name|QEvent
operator|::
name|Type
name|touchType
block|;     }
decl_stmt|;
name|class
name|ScreenOrientationEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|ScreenOrientationEvent
argument_list|(
argument|QScreen *s
argument_list|,
argument|Qt::ScreenOrientation o
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|ScreenOrientation
argument_list|)
block|,
name|screen
argument_list|(
name|s
argument_list|)
block|,
name|orientation
argument_list|(
argument|o
argument_list|)
block|{ }
name|QPointer
operator|<
name|QScreen
operator|>
name|screen
block|;
name|Qt
operator|::
name|ScreenOrientation
name|orientation
block|;     }
decl_stmt|;
name|class
name|ScreenGeometryEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|ScreenGeometryEvent
argument_list|(
name|QScreen
operator|*
name|s
argument_list|,
specifier|const
name|QRect
operator|&
name|g
argument_list|,
specifier|const
name|QRect
operator|&
name|ag
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|ScreenGeometry
argument_list|)
block|,
name|screen
argument_list|(
name|s
argument_list|)
block|,
name|geometry
argument_list|(
name|g
argument_list|)
block|,
name|availableGeometry
argument_list|(
argument|ag
argument_list|)
block|{ }
name|QPointer
operator|<
name|QScreen
operator|>
name|screen
block|;
name|QRect
name|geometry
block|;
name|QRect
name|availableGeometry
block|;     }
decl_stmt|;
name|class
name|ScreenLogicalDotsPerInchEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|ScreenLogicalDotsPerInchEvent
argument_list|(
argument|QScreen *s
argument_list|,
argument|qreal dx
argument_list|,
argument|qreal dy
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|ScreenLogicalDotsPerInch
argument_list|)
block|,
name|screen
argument_list|(
name|s
argument_list|)
block|,
name|dpiX
argument_list|(
name|dx
argument_list|)
block|,
name|dpiY
argument_list|(
argument|dy
argument_list|)
block|{ }
name|QPointer
operator|<
name|QScreen
operator|>
name|screen
block|;
name|qreal
name|dpiX
block|;
name|qreal
name|dpiY
block|;     }
decl_stmt|;
name|class
name|ScreenRefreshRateEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|ScreenRefreshRateEvent
argument_list|(
argument|QScreen *s
argument_list|,
argument|qreal r
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|ScreenRefreshRate
argument_list|)
block|,
name|screen
argument_list|(
name|s
argument_list|)
block|,
name|rate
argument_list|(
argument|r
argument_list|)
block|{ }
name|QPointer
operator|<
name|QScreen
operator|>
name|screen
block|;
name|qreal
name|rate
block|;     }
decl_stmt|;
name|class
name|ThemeChangeEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|explicit
name|ThemeChangeEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|ThemeChange
argument_list|)
block|,
name|window
argument_list|(
argument|w
argument_list|)
block|{ }
name|QPointer
operator|<
name|QWindow
operator|>
name|window
block|;     }
decl_stmt|;
name|class
name|ExposeEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|ExposeEvent
argument_list|(
name|QWindow
operator|*
name|exposed
argument_list|,
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
block|;
name|QPointer
operator|<
name|QWindow
operator|>
name|exposed
block|;
name|bool
name|isExposed
block|;
name|QRegion
name|region
block|;     }
decl_stmt|;
name|class
name|FileOpenEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|FileOpenEvent
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|FileOpen
argument_list|)
block|,
name|url
argument_list|(
argument|QUrl::fromLocalFile(fileName)
argument_list|)
block|{ }
name|FileOpenEvent
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|FileOpen
argument_list|)
block|,
name|url
argument_list|(
argument|url
argument_list|)
block|{ }
name|QUrl
name|url
block|;     }
decl_stmt|;
name|class
name|TabletEvent
range|:
name|public
name|InputEvent
block|{
name|public
operator|:
specifier|static
name|void
name|handleTabletEvent
argument_list|(
argument|QWindow *w
argument_list|,
argument|const QPointF&local
argument_list|,
argument|const QPointF&global
argument_list|,
argument|int device
argument_list|,
argument|int pointerType
argument_list|,
argument|Qt::MouseButtons buttons
argument_list|,
argument|qreal pressure
argument_list|,
argument|int xTilt
argument_list|,
argument|int yTilt
argument_list|,
argument|qreal tangentialPressure
argument_list|,
argument|qreal rotation
argument_list|,
argument|int z
argument_list|,
argument|qint64 uid
argument_list|,
argument|Qt::KeyboardModifiers modifiers = Qt::NoModifier
argument_list|)
block|;
name|TabletEvent
argument_list|(
argument|QWindow *w
argument_list|,
argument|ulong time
argument_list|,
argument|const QPointF&local
argument_list|,
argument|const QPointF&global
argument_list|,
argument|int device
argument_list|,
argument|int pointerType
argument_list|,
argument|Qt::MouseButtons b
argument_list|,
argument|qreal pressure
argument_list|,
argument|int xTilt
argument_list|,
argument|int yTilt
argument_list|,
argument|qreal tpressure
argument_list|,
argument|qreal rotation
argument_list|,
argument|int z
argument_list|,
argument|qint64 uid
argument_list|,
argument|Qt::KeyboardModifiers mods
argument_list|)
operator|:
name|InputEvent
argument_list|(
name|w
argument_list|,
name|time
argument_list|,
name|Tablet
argument_list|,
name|mods
argument_list|)
block|,
name|buttons
argument_list|(
name|b
argument_list|)
block|,
name|local
argument_list|(
name|local
argument_list|)
block|,
name|global
argument_list|(
name|global
argument_list|)
block|,
name|device
argument_list|(
name|device
argument_list|)
block|,
name|pointerType
argument_list|(
name|pointerType
argument_list|)
block|,
name|pressure
argument_list|(
name|pressure
argument_list|)
block|,
name|xTilt
argument_list|(
name|xTilt
argument_list|)
block|,
name|yTilt
argument_list|(
name|yTilt
argument_list|)
block|,
name|tangentialPressure
argument_list|(
name|tpressure
argument_list|)
block|,
name|rotation
argument_list|(
name|rotation
argument_list|)
block|,
name|z
argument_list|(
name|z
argument_list|)
block|,
name|uid
argument_list|(
argument|uid
argument_list|)
block|{ }
name|Qt
operator|::
name|MouseButtons
name|buttons
block|;
name|QPointF
name|local
block|;
name|QPointF
name|global
block|;
name|int
name|device
block|;
name|int
name|pointerType
block|;
name|qreal
name|pressure
block|;
name|int
name|xTilt
block|;
name|int
name|yTilt
block|;
name|qreal
name|tangentialPressure
block|;
name|qreal
name|rotation
block|;
name|int
name|z
block|;
name|qint64
name|uid
block|;     }
decl_stmt|;
name|class
name|TabletEnterProximityEvent
range|:
name|public
name|InputEvent
block|{
name|public
operator|:
name|TabletEnterProximityEvent
argument_list|(
argument|ulong time
argument_list|,
argument|int device
argument_list|,
argument|int pointerType
argument_list|,
argument|qint64 uid
argument_list|)
operator|:
name|InputEvent
argument_list|(
literal|0
argument_list|,
name|time
argument_list|,
name|TabletEnterProximity
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|)
block|,
name|device
argument_list|(
name|device
argument_list|)
block|,
name|pointerType
argument_list|(
name|pointerType
argument_list|)
block|,
name|uid
argument_list|(
argument|uid
argument_list|)
block|{ }
name|int
name|device
block|;
name|int
name|pointerType
block|;
name|qint64
name|uid
block|;     }
decl_stmt|;
name|class
name|TabletLeaveProximityEvent
range|:
name|public
name|InputEvent
block|{
name|public
operator|:
name|TabletLeaveProximityEvent
argument_list|(
argument|ulong time
argument_list|,
argument|int device
argument_list|,
argument|int pointerType
argument_list|,
argument|qint64 uid
argument_list|)
operator|:
name|InputEvent
argument_list|(
literal|0
argument_list|,
name|time
argument_list|,
name|TabletLeaveProximity
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|)
block|,
name|device
argument_list|(
name|device
argument_list|)
block|,
name|pointerType
argument_list|(
name|pointerType
argument_list|)
block|,
name|uid
argument_list|(
argument|uid
argument_list|)
block|{ }
name|int
name|device
block|;
name|int
name|pointerType
block|;
name|qint64
name|uid
block|;     }
decl_stmt|;
name|class
name|PlatformPanelEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|explicit
name|PlatformPanelEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|PlatformPanel
argument_list|)
block|,
name|window
argument_list|(
argument|w
argument_list|)
block|{ }
name|QPointer
operator|<
name|QWindow
operator|>
name|window
block|;     }
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|class
name|ContextMenuEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|explicit
name|ContextMenuEvent
argument_list|(
argument|QWindow *w
argument_list|,
argument|bool mouseTriggered
argument_list|,
argument|const QPoint&pos
argument_list|,
argument|const QPoint&globalPos
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|ContextMenu
argument_list|)
block|,
name|window
argument_list|(
name|w
argument_list|)
block|,
name|mouseTriggered
argument_list|(
name|mouseTriggered
argument_list|)
block|,
name|pos
argument_list|(
name|pos
argument_list|)
block|,
name|globalPos
argument_list|(
name|globalPos
argument_list|)
block|,
name|modifiers
argument_list|(
argument|modifiers
argument_list|)
block|{ }
name|QPointer
operator|<
name|QWindow
operator|>
name|window
block|;
name|bool
name|mouseTriggered
block|;
name|QPoint
name|pos
block|;
comment|// Only valid if triggered by mouse
name|QPoint
name|globalPos
block|;
comment|// Only valid if triggered by mouse
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
block|;     }
decl_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
name|class
name|GestureEvent
range|:
name|public
name|InputEvent
block|{
name|public
operator|:
name|GestureEvent
argument_list|(
argument|QWindow *window
argument_list|,
argument|ulong time
argument_list|,
argument|Qt::NativeGestureType type
argument_list|,
argument|QPointF pos
argument_list|,
argument|QPointF globalPos
argument_list|)
operator|:
name|InputEvent
argument_list|(
name|window
argument_list|,
name|time
argument_list|,
name|Gesture
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|)
block|,
name|type
argument_list|(
name|type
argument_list|)
block|,
name|pos
argument_list|(
name|pos
argument_list|)
block|,
name|globalPos
argument_list|(
name|globalPos
argument_list|)
block|,
name|realValue
argument_list|(
literal|0
argument_list|)
block|,
name|sequenceId
argument_list|(
literal|0
argument_list|)
block|,
name|intValue
argument_list|(
literal|0
argument_list|)
block|{ }
name|Qt
operator|::
name|NativeGestureType
name|type
block|;
name|QPointF
name|pos
block|;
name|QPointF
name|globalPos
block|;
comment|// Mac
name|qreal
name|realValue
block|;
comment|// Windows
name|ulong
name|sequenceId
block|;
name|quint64
name|intValue
block|;     }
decl_stmt|;
endif|#
directive|endif
name|class
name|WindowSystemEventList
block|{
name|QList
operator|<
name|WindowSystemEvent
operator|*
operator|>
name|impl
expr_stmt|;
name|mutable
name|QMutex
name|mutex
decl_stmt|;
name|public
label|:
name|WindowSystemEventList
argument_list|()
operator|:
name|impl
argument_list|()
operator|,
name|mutex
argument_list|()
block|{}
operator|~
name|WindowSystemEventList
argument_list|()
block|{
name|clear
argument_list|()
block|; }
name|void
name|clear
argument_list|()
block|{
specifier|const
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
block|;
name|qDeleteAll
argument_list|(
name|impl
argument_list|)
block|;
name|impl
operator|.
name|clear
argument_list|()
block|; }
name|void
name|prepend
argument_list|(
argument|WindowSystemEvent *e
argument_list|)
block|{
specifier|const
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
block|;
name|impl
operator|.
name|prepend
argument_list|(
name|e
argument_list|)
block|; }
name|WindowSystemEvent
operator|*
name|takeFirstOrReturnNull
argument_list|()
block|{
specifier|const
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
block|;
return|return
name|impl
operator|.
name|empty
argument_list|()
condition|?
literal|0
else|:
name|impl
operator|.
name|takeFirst
argument_list|()
return|;
block|}
name|WindowSystemEvent
modifier|*
name|takeFirstNonUserInputOrReturnNull
parameter_list|()
block|{
specifier|const
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|impl
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
operator|!
operator|(
name|impl
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|type
operator|&
name|QWindowSystemInterfacePrivate
operator|::
name|UserInputEvent
operator|)
condition|)
return|return
name|impl
operator|.
name|takeAt
argument_list|(
name|i
argument_list|)
return|;
return|return
literal|0
return|;
block|}
name|void
name|append
parameter_list|(
name|WindowSystemEvent
modifier|*
name|e
parameter_list|)
block|{
specifier|const
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|impl
operator|.
name|append
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
name|int
name|count
argument_list|()
specifier|const
block|{
specifier|const
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
block|;
return|return
name|impl
operator|.
name|count
argument_list|()
return|;
block|}
name|WindowSystemEvent
modifier|*
name|peekAtFirstOfType
argument_list|(
name|EventType
name|t
argument_list|)
decl|const
block|{
specifier|const
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|impl
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|impl
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|type
operator|==
name|t
condition|)
return|return
name|impl
operator|.
name|at
argument_list|(
name|i
argument_list|)
return|;
block|}
return|return
literal|0
return|;
block|}
name|void
name|remove
parameter_list|(
specifier|const
name|WindowSystemEvent
modifier|*
name|e
parameter_list|)
block|{
specifier|const
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|impl
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|impl
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|e
condition|)
block|{
name|delete
name|impl
operator|.
name|takeAt
argument_list|(
name|i
argument_list|)
decl_stmt|;
break|break;
block|}
block|}
block|}
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|WindowSystemEventList
argument_list|)
block|}
empty_stmt|;
specifier|static
name|WindowSystemEventList
name|windowSystemEventQueue
decl_stmt|;
specifier|static
name|int
name|windowSystemEventsQueued
parameter_list|()
function_decl|;
specifier|static
name|WindowSystemEvent
modifier|*
name|getWindowSystemEvent
parameter_list|()
function_decl|;
specifier|static
name|WindowSystemEvent
modifier|*
name|getNonUserInputWindowSystemEvent
parameter_list|()
function_decl|;
specifier|static
name|WindowSystemEvent
modifier|*
name|peekWindowSystemEvent
parameter_list|(
name|EventType
name|t
parameter_list|)
function_decl|;
specifier|static
name|void
name|removeWindowSystemEvent
parameter_list|(
name|WindowSystemEvent
modifier|*
name|event
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleWindowSystemEvent
parameter_list|(
name|WindowSystemEvent
modifier|*
name|ev
parameter_list|)
function_decl|;
specifier|static
name|QElapsedTimer
name|eventTime
decl_stmt|;
specifier|static
name|bool
name|synchronousWindowsSystemEvents
decl_stmt|;
specifier|static
name|QWaitCondition
name|eventsFlushed
decl_stmt|;
specifier|static
name|QMutex
name|flushEventMutex
decl_stmt|;
specifier|static
name|QList
operator|<
name|QTouchEvent
operator|::
name|TouchPoint
operator|>
name|convertTouchPoints
argument_list|(
specifier|const
name|QList
operator|<
name|QWindowSystemInterface
operator|::
name|TouchPoint
operator|>
operator|&
name|points
argument_list|,
name|QEvent
operator|::
name|Type
operator|*
name|type
argument_list|)
expr_stmt|;
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
comment|// QWINDOWSYSTEMINTERFACE_P_H
end_comment
end_unit
