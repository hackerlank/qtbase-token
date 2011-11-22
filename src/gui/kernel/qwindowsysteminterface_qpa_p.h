begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSYSTEMINTERFACE_QPA_P_H
end_ifndef
begin_define
DECL|macro|QWINDOWSYSTEMINTERFACE_QPA_P_H
define|#
directive|define
name|QWINDOWSYSTEMINTERFACE_QPA_P_H
end_define
begin_include
include|#
directive|include
file|"qwindowsysteminterface_qpa.h"
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|class
name|QWindowSystemInterfacePrivate
block|{
name|public
label|:
enum|enum
name|EventType
block|{
name|Close
block|,
name|GeometryChange
block|,
name|Enter
block|,
name|Leave
block|,
name|ActivatedWindow
block|,
name|WindowStateChanged
block|,
name|Mouse
block|,
name|Wheel
block|,
name|Key
block|,
name|Touch
block|,
name|ScreenOrientation
block|,
name|ScreenGeometry
block|,
name|ScreenAvailableGeometry
block|,
name|ScreenLogicalDotsPerInch
block|,
name|Map
block|,
name|Unmap
block|,
name|Expose
block|}
enum|;
name|class
name|WindowSystemEvent
block|{
name|public
label|:
name|explicit
name|WindowSystemEvent
argument_list|(
argument|EventType t
argument_list|)
block|:
name|type
argument_list|(
argument|t
argument_list|)
block|{ }
name|EventType
name|type
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
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|Close
argument_list|)
block|,
name|window
argument_list|(
argument|w
argument_list|)
block|{ }
name|QWeakPointer
operator|<
name|QWindow
operator|>
name|window
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
argument|newGeometry
argument_list|)
block|{ }
name|QWeakPointer
operator|<
name|QWindow
operator|>
name|tlw
block|;
name|QRect
name|newGeometry
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
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|Enter
argument_list|)
block|,
name|enter
argument_list|(
argument|enter
argument_list|)
block|{ }
name|QWeakPointer
operator|<
name|QWindow
operator|>
name|enter
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
name|QWeakPointer
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
name|QWindow
operator|*
name|activatedWindow
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|ActivatedWindow
argument_list|)
block|,
name|activated
argument_list|(
argument|activatedWindow
argument_list|)
block|{ }
name|QWeakPointer
operator|<
name|QWindow
operator|>
name|activated
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
name|QWeakPointer
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
name|nullWindow
argument_list|(
name|w
operator|==
literal|0
argument_list|)
block|,
name|timestamp
argument_list|(
argument|time
argument_list|)
block|{ }
name|QWeakPointer
operator|<
name|QWindow
operator|>
name|window
block|;
name|bool
name|nullWindow
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
argument|b
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
argument|int d
argument_list|,
argument|Qt::Orientation o
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
name|Wheel
argument_list|,
name|mods
argument_list|)
block|,
name|delta
argument_list|(
name|d
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
name|orient
argument_list|(
argument|o
argument_list|)
block|{ }
name|int
name|delta
block|;
name|QPointF
name|localPos
block|;
name|QPointF
name|globalPos
block|;
name|Qt
operator|::
name|Orientation
name|orient
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
argument|QTouchEvent::DeviceType d
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
name|devType
argument_list|(
name|d
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
name|QTouchEvent
operator|::
name|DeviceType
name|devType
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
block|;      }
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
name|QScreen
operator|*
name|s
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|ScreenOrientation
argument_list|)
block|,
name|screen
argument_list|(
argument|s
argument_list|)
block|{ }
name|QWeakPointer
operator|<
name|QScreen
operator|>
name|screen
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
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|ScreenGeometry
argument_list|)
block|,
name|screen
argument_list|(
argument|s
argument_list|)
block|{ }
name|QWeakPointer
operator|<
name|QScreen
operator|>
name|screen
block|;     }
decl_stmt|;
name|class
name|ScreenAvailableGeometryEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|ScreenAvailableGeometryEvent
argument_list|(
name|QScreen
operator|*
name|s
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|ScreenAvailableGeometry
argument_list|)
block|,
name|screen
argument_list|(
argument|s
argument_list|)
block|{ }
name|QWeakPointer
operator|<
name|QScreen
operator|>
name|screen
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
name|QScreen
operator|*
name|s
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|ScreenLogicalDotsPerInch
argument_list|)
block|,
name|screen
argument_list|(
argument|s
argument_list|)
block|{ }
name|QWeakPointer
operator|<
name|QScreen
operator|>
name|screen
block|;     }
decl_stmt|;
name|class
name|MapEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|MapEvent
argument_list|(
name|QWindow
operator|*
name|mapped
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|Map
argument_list|)
block|,
name|mapped
argument_list|(
argument|mapped
argument_list|)
block|{ }
name|QWeakPointer
operator|<
name|QWindow
operator|>
name|mapped
block|;     }
decl_stmt|;
name|class
name|UnmapEvent
range|:
name|public
name|WindowSystemEvent
block|{
name|public
operator|:
name|UnmapEvent
argument_list|(
name|QWindow
operator|*
name|unmapped
argument_list|)
operator|:
name|WindowSystemEvent
argument_list|(
name|Unmap
argument_list|)
block|,
name|unmapped
argument_list|(
argument|unmapped
argument_list|)
block|{ }
name|QWeakPointer
operator|<
name|QWindow
operator|>
name|unmapped
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
operator|:
name|WindowSystemEvent
argument_list|(
name|Expose
argument_list|)
block|,
name|exposed
argument_list|(
name|exposed
argument_list|)
block|,
name|region
argument_list|(
argument|region
argument_list|)
block|{ }
name|QWeakPointer
operator|<
name|QWindow
operator|>
name|exposed
block|;
name|QRegion
name|region
block|;     }
decl_stmt|;
specifier|static
name|QList
operator|<
name|WindowSystemEvent
operator|*
operator|>
name|windowSystemEventQueue
expr_stmt|;
specifier|static
name|QMutex
name|queueMutex
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
name|void
name|queueWindowSystemEvent
parameter_list|(
name|WindowSystemEvent
modifier|*
name|ev
parameter_list|)
function_decl|;
specifier|static
name|QTime
name|eventTime
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_HEADER
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSYSTEMINTERFACE_QPA_P_H
end_comment
end_unit
