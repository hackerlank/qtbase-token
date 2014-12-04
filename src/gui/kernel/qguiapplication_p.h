begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGUIAPPLICATION_P_H
end_ifndef
begin_define
DECL|macro|QGUIAPPLICATION_P_H
define|#
directive|define
name|QGUIAPPLICATION_P_H
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
file|<QtGui/qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QPointF>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qcoreapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qthread_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface_p.h>
end_include
begin_include
include|#
directive|include
file|"private/qshortcutmap_p.h"
end_include
begin_include
include|#
directive|include
file|<qicon.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPlatformIntegration
name|class
name|QPlatformIntegration
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformTheme
name|class
name|QPlatformTheme
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformDragQtResponse
name|class
name|QPlatformDragQtResponse
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QDrawHelperGammaTables
struct_decl|;
end_struct_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
end_ifndef
begin_decl_stmt
DECL|variable|QDrag
name|class
name|QDrag
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DRAGANDDROP
end_comment
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QGuiApplicationPrivate
range|:
name|public
name|QCoreApplicationPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGuiApplication
argument_list|)
name|public
operator|:
name|QGuiApplicationPrivate
argument_list|(
argument|int&argc
argument_list|,
argument|char **argv
argument_list|,
argument|int flags
argument_list|)
block|;
operator|~
name|QGuiApplicationPrivate
argument_list|()
block|;
name|void
name|createPlatformIntegration
argument_list|()
block|;
name|void
name|createEventDispatcher
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|eventDispatcherReady
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|notifyLayoutDirectionChange
argument_list|()
block|;
name|virtual
name|void
name|notifyActiveWindowChange
argument_list|(
name|QWindow
operator|*
name|previous
argument_list|)
block|;
name|virtual
name|bool
name|shouldQuit
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|shouldQuitInternal
argument_list|(
specifier|const
name|QWindowList
operator|&
name|processedWindows
argument_list|)
block|;
name|virtual
name|bool
name|tryCloseAllWindows
argument_list|()
block|;
specifier|static
name|Qt
operator|::
name|KeyboardModifiers
name|modifier_buttons
block|;
specifier|static
name|Qt
operator|::
name|MouseButtons
name|mouse_buttons
block|;
specifier|static
name|QPlatformIntegration
operator|*
name|platform_integration
block|;
specifier|static
name|QPlatformIntegration
operator|*
name|platformIntegration
argument_list|()
block|{
return|return
name|platform_integration
return|;
block|}
specifier|static
name|QPlatformTheme
operator|*
name|platform_theme
block|;
specifier|static
name|QPlatformTheme
operator|*
name|platformTheme
argument_list|()
block|{
return|return
name|platform_theme
return|;
block|}
specifier|static
name|QAbstractEventDispatcher
operator|*
name|qt_qpa_core_dispatcher
argument_list|()
block|{
if|if
condition|(
name|QCoreApplication
operator|::
name|instance
argument_list|()
condition|)
return|return
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|threadData
operator|->
name|eventDispatcher
operator|.
name|load
argument_list|()
return|;
else|else
return|return
literal|0
return|;
block|}
specifier|static
name|void
name|processMouseEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|MouseEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processKeyEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|KeyEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processWheelEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|WheelEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processTouchEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|TouchEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processCloseEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|CloseEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processGeometryChangeEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|GeometryChangeEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processEnterEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|EnterEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processLeaveEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|LeaveEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processActivatedEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|ActivatedWindowEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processWindowStateChangedEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|WindowStateChangedEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processWindowScreenChangedEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|WindowScreenChangedEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processWindowSystemEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|WindowSystemEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|updateFilteredScreenOrientation
argument_list|(
name|QScreen
operator|*
name|screen
argument_list|)
block|;
specifier|static
name|void
name|reportScreenOrientationChange
argument_list|(
name|QScreen
operator|*
name|screen
argument_list|)
block|;
specifier|static
name|void
name|reportScreenOrientationChange
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|ScreenOrientationEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|reportGeometryChange
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|ScreenGeometryEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|reportLogicalDotsPerInchChange
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|ScreenLogicalDotsPerInchEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|reportRefreshRateChange
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|ScreenRefreshRateEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processThemeChanged
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|ThemeChangeEvent
operator|*
name|tce
argument_list|)
block|;
specifier|static
name|void
name|processExposeEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|ExposeEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processFileOpenEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|FileOpenEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processTabletEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|TabletEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processTabletEnterProximityEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|TabletEnterProximityEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processTabletLeaveProximityEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|TabletLeaveProximityEvent
operator|*
name|e
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
specifier|static
name|void
name|processGestureEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|GestureEvent
operator|*
name|e
argument_list|)
block|;
endif|#
directive|endif
specifier|static
name|void
name|processPlatformPanelEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|PlatformPanelEvent
operator|*
name|e
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
specifier|static
name|void
name|processContextMenuEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|ContextMenuEvent
operator|*
name|e
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
specifier|static
name|QPlatformDragQtResponse
name|processDrag
argument_list|(
argument|QWindow *w
argument_list|,
argument|const QMimeData *dropData
argument_list|,
argument|const QPoint&p
argument_list|,
argument|Qt::DropActions supportedActions
argument_list|)
block|;
specifier|static
name|QPlatformDropQtResponse
name|processDrop
argument_list|(
argument|QWindow *w
argument_list|,
argument|const QMimeData *dropData
argument_list|,
argument|const QPoint&p
argument_list|,
argument|Qt::DropActions supportedActions
argument_list|)
block|;
endif|#
directive|endif
specifier|static
name|bool
name|processNativeEvent
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
specifier|const
name|QByteArray
operator|&
name|eventType
argument_list|,
name|void
operator|*
name|message
argument_list|,
name|long
operator|*
name|result
argument_list|)
block|;
specifier|static
name|void
name|sendQWindowEventToQPlatformWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
specifier|static
specifier|inline
name|Qt
operator|::
name|Alignment
name|visualAlignment
argument_list|(
argument|Qt::LayoutDirection direction
argument_list|,
argument|Qt::Alignment alignment
argument_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|alignment
operator|&
name|Qt
operator|::
name|AlignHorizontal_Mask
operator|)
condition|)
name|alignment
operator||=
name|Qt
operator|::
name|AlignLeft
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|alignment
operator|&
name|Qt
operator|::
name|AlignAbsolute
operator|)
operator|&&
operator|(
name|alignment
operator|&
operator|(
name|Qt
operator|::
name|AlignLeft
operator||
name|Qt
operator|::
name|AlignRight
operator|)
operator|)
condition|)
block|{
if|if
condition|(
name|direction
operator|==
name|Qt
operator|::
name|RightToLeft
condition|)
name|alignment
operator|^=
operator|(
name|Qt
operator|::
name|AlignLeft
operator||
name|Qt
operator|::
name|AlignRight
operator|)
expr_stmt|;
name|alignment
operator||=
name|Qt
operator|::
name|AlignAbsolute
expr_stmt|;
block|}
return|return
name|alignment
return|;
block|}
end_decl_stmt
begin_function_decl
specifier|static
name|void
name|emitLastWindowClosed
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|QPixmap
name|getPixmapCursor
argument_list|(
name|Qt
operator|::
name|CursorShape
name|cshape
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|_q_updateFocusObject
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|static
name|QGuiApplicationPrivate
modifier|*
name|instance
parameter_list|()
block|{
return|return
name|self
return|;
block|}
end_function
begin_decl_stmt
specifier|static
name|QIcon
modifier|*
name|app_icon
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|QString
modifier|*
name|platform_name
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|QString
modifier|*
name|displayName
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QWindowList
name|modalWindowList
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|void
name|showModalWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|hideModalWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|updateBlockedStatus
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|virtual
name|bool
name|isWindowBlocked
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|QWindow
operator|*
operator|*
name|blockingWindow
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|bool
name|synthesizeMouseFromTouchEventsEnabled
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
specifier|static
name|Qt
operator|::
name|MouseButtons
name|buttons
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|static
name|ulong
name|mousePressTime
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|static
name|Qt
operator|::
name|MouseButton
name|mousePressButton
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|static
name|int
name|mousePressX
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|int
name|mousePressY
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|int
name|mouse_double_click_distance
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|QPointF
name|lastCursorPosition
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|static
name|Qt
operator|::
name|MouseButtons
name|tabletState
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|static
name|QWindow
modifier|*
name|tabletPressTarget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|QWindow
modifier|*
name|currentMouseWindow
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|static
name|Qt
operator|::
name|ApplicationState
name|applicationState
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_decl_stmt
specifier|static
name|QClipboard
modifier|*
name|qt_clipboard
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
specifier|static
name|QPalette
modifier|*
name|app_pal
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|QWindowList
name|window_list
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|QWindow
modifier|*
name|focus_window
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
end_ifndef
begin_expr_stmt
name|QList
operator|<
name|QCursor
operator|>
name|cursor_list
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
specifier|static
name|QList
operator|<
name|QScreen
operator|*
operator|>
name|screen_list
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|static
name|QFont
modifier|*
name|app_font
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QStyleHints
modifier|*
name|styleHints
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|bool
name|obey_desktop_settings
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QInputMethod
modifier|*
name|inputMethod
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|firstWindowTitle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QIcon
name|forcedWindowIcon
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|static
name|QList
operator|<
name|QObject
operator|*
operator|>
name|generic_plugin_list
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
end_ifndef
begin_decl_stmt
name|QShortcutMap
name|shortcutMap
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SESSIONMANAGER
end_ifndef
begin_decl_stmt
name|QSessionManager
modifier|*
name|session_manager
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|is_session_restored
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|is_saving_session
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|commitData
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|saveState
parameter_list|()
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_struct
struct|struct
name|ActiveTouchPointsKey
block|{
name|ActiveTouchPointsKey
argument_list|(
argument|QTouchDevice *dev
argument_list|,
argument|int id
argument_list|)
block|:
name|device
argument_list|(
name|dev
argument_list|)
operator|,
name|touchPointId
argument_list|(
argument|id
argument_list|)
block|{ }
name|QTouchDevice
operator|*
name|device
expr_stmt|;
name|int
name|touchPointId
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
struct|struct
name|ActiveTouchPointsValue
block|{
name|QPointer
operator|<
name|QWindow
operator|>
name|window
expr_stmt|;
name|QPointer
operator|<
name|QObject
operator|>
name|target
expr_stmt|;
name|QTouchEvent
operator|::
name|TouchPoint
name|touchPoint
expr_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|QHash
operator|<
name|ActiveTouchPointsKey
operator|,
name|ActiveTouchPointsValue
operator|>
name|activeTouchPoints
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QEvent
operator|::
name|Type
name|lastTouchType
expr_stmt|;
end_expr_stmt
begin_struct
struct|struct
name|SynthesizedMouseData
block|{
name|SynthesizedMouseData
argument_list|(
specifier|const
name|QPointF
operator|&
name|p
argument_list|,
specifier|const
name|QPointF
operator|&
name|sp
argument_list|,
name|QWindow
operator|*
name|w
argument_list|)
operator|:
name|pos
argument_list|(
name|p
argument_list|)
operator|,
name|screenPos
argument_list|(
name|sp
argument_list|)
operator|,
name|window
argument_list|(
argument|w
argument_list|)
block|{ }
name|QPointF
name|pos
expr_stmt|;
name|QPointF
name|screenPos
decl_stmt|;
name|QPointer
operator|<
name|QWindow
operator|>
name|window
expr_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|QHash
operator|<
name|QWindow
operator|*
operator|,
name|SynthesizedMouseData
operator|>
name|synthesizedMousePoints
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|static
name|int
name|mouseEventCaps
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QVector2D
name|mouseEventVelocity
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|setMouseEventCapsAndVelocity
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|,
name|int
name|caps
parameter_list|,
specifier|const
name|QVector2D
modifier|&
name|velocity
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
specifier|static
name|Qt
operator|::
name|MouseEventSource
name|mouseEventSource
argument_list|(
specifier|const
name|QMouseEvent
operator|*
name|event
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|static
name|void
name|setMouseEventSource
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|,
name|Qt
operator|::
name|MouseEventSource
name|source
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|static
name|Qt
operator|::
name|MouseEventFlags
name|mouseEventFlags
argument_list|(
specifier|const
name|QMouseEvent
operator|*
name|event
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|static
name|void
name|setMouseEventFlags
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|,
name|Qt
operator|::
name|MouseEventFlags
name|flags
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|static
name|Qt
operator|::
name|MouseEventSource
name|wheelEventSource
argument_list|(
specifier|const
name|QWheelEvent
operator|*
name|event
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|const
name|QDrawHelperGammaTables
modifier|*
name|gammaTables
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// hook reimplemented in QApplication to apply the QStyle function on the QIcon
end_comment
begin_decl_stmt
name|virtual
name|QPixmap
name|applyQIconStyleHelper
argument_list|(
name|QIcon
operator|::
name|Mode
argument_list|,
specifier|const
name|QPixmap
operator|&
name|basePixmap
argument_list|)
decl|const
block|{
return|return
name|basePixmap
return|;
block|}
end_decl_stmt
begin_function_decl
name|virtual
name|void
name|notifyWindowIconChanged
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QRect
name|applyWindowGeometrySpecification
parameter_list|(
specifier|const
name|QRect
modifier|&
name|windowGeometry
parameter_list|,
specifier|const
name|QWindow
modifier|*
name|window
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|static
name|void
name|setApplicationState
argument_list|(
name|Qt
operator|::
name|ApplicationState
name|state
argument_list|,
name|bool
name|forcePropagate
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt
begin_label
name|protected
label|:
end_label
begin_function_decl
name|virtual
name|void
name|notifyThemeChanged
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|tryCloseRemainingWindows
parameter_list|(
name|QWindowList
name|processedWindows
parameter_list|)
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
end_ifndef
begin_function_decl
name|virtual
name|void
name|notifyDragStarted
parameter_list|(
specifier|const
name|QDrag
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DRAGANDDROP
end_comment
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|friend
name|class
name|QDragManager
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|init
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
specifier|static
name|QGuiApplicationPrivate
modifier|*
name|self
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|QTouchDevice
modifier|*
name|m_fakeTouchDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|int
name|m_fakeMouseSourcePointId
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QAtomicPointer
operator|<
name|QDrawHelperGammaTables
operator|>
name|m_gammaTables
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|ownGlobalShareContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|Q_GUI_EXPORT
name|uint
name|qHash
argument_list|(
specifier|const
name|QGuiApplicationPrivate
operator|::
name|ActiveTouchPointsKey
operator|&
name|k
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QGuiApplicationPrivate
operator|::
name|ActiveTouchPointsKey
operator|&
name|a
operator|,
specifier|const
name|QGuiApplicationPrivate
operator|::
name|ActiveTouchPointsKey
operator|&
name|b
operator|)
expr_stmt|;
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGUIAPPLICATION_P_H
end_comment
end_unit
