begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSWINDOW_H
end_ifndef
begin_define
DECL|macro|QWINDOWSWINDOW_H
define|#
directive|define
name|QWINDOWSWINDOW_H
end_define
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINCE
end_ifdef
begin_include
include|#
directive|include
file|"qplatformfunctions_wince.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qwindowsscaling.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscursor.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsopenglcontext.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindowsOleDropTarget
name|class
name|QWindowsOleDropTarget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QWindowsGeometryHint
struct|struct
name|QWindowsGeometryHint
block|{
DECL|function|QWindowsGeometryHint
name|QWindowsGeometryHint
argument_list|()
block|{}
name|explicit
name|QWindowsGeometryHint
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|QMargins
modifier|&
name|customMargins
parameter_list|)
function_decl|;
specifier|static
name|QMargins
name|frame
parameter_list|(
name|DWORD
name|style
parameter_list|,
name|DWORD
name|exStyle
parameter_list|)
function_decl|;
specifier|static
name|bool
name|handleCalculateSize
parameter_list|(
specifier|const
name|QMargins
modifier|&
name|customMargins
parameter_list|,
specifier|const
name|MSG
modifier|&
name|msg
parameter_list|,
name|LRESULT
modifier|*
name|result
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
comment|//MinMax maybe define struct if not available
name|void
name|applyToMinMaxInfo
argument_list|(
name|DWORD
name|style
argument_list|,
name|DWORD
name|exStyle
argument_list|,
name|MINMAXINFO
operator|*
name|mmi
argument_list|)
decl|const
decl_stmt|;
name|void
name|applyToMinMaxInfo
argument_list|(
name|HWND
name|hwnd
argument_list|,
name|MINMAXINFO
operator|*
name|mmi
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
name|bool
name|validSize
argument_list|(
specifier|const
name|QSize
operator|&
name|s
argument_list|)
decl|const
decl_stmt|;
specifier|static
specifier|inline
name|QPoint
name|mapToGlobal
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
specifier|const
name|QPoint
modifier|&
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|QPoint
name|mapToGlobal
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|QPoint
modifier|&
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|QPoint
name|mapFromGlobal
parameter_list|(
specifier|const
name|HWND
name|hwnd
parameter_list|,
specifier|const
name|QPoint
modifier|&
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|QPoint
name|mapFromGlobal
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|QPoint
modifier|&
parameter_list|)
function_decl|;
specifier|static
name|bool
name|positionIncludesFrame
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|w
parameter_list|)
function_decl|;
DECL|member|minimumSize
name|QSize
name|minimumSize
decl_stmt|;
DECL|member|maximumSize
name|QSize
name|maximumSize
decl_stmt|;
DECL|member|customMargins
name|QMargins
name|customMargins
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|QWindowCreationContext
struct|struct
name|QWindowCreationContext
block|{
name|QWindowCreationContext
argument_list|(
argument|const QWindow *w
argument_list|,
argument|const QRect&r
argument_list|,
argument|const QMargins&customMargins
argument_list|,
argument|DWORD style
argument_list|,
argument|DWORD exStyle
argument_list|)
empty_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
comment|//MinMax maybe define struct if not available
DECL|function|applyToMinMaxInfo
name|void
name|applyToMinMaxInfo
argument_list|(
name|MINMAXINFO
operator|*
name|mmi
argument_list|)
decl|const
block|{
name|geometryHint
operator|.
name|applyToMinMaxInfo
argument_list|(
name|style
argument_list|,
name|exStyle
argument_list|,
name|mmi
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
DECL|member|geometryHint
name|QWindowsGeometryHint
name|geometryHint
decl_stmt|;
DECL|member|style
name|DWORD
name|style
decl_stmt|;
DECL|member|exStyle
name|DWORD
name|exStyle
decl_stmt|;
DECL|member|requestedGeometry
name|QRect
name|requestedGeometry
decl_stmt|;
DECL|member|obtainedGeometry
name|QRect
name|obtainedGeometry
decl_stmt|;
DECL|member|margins
name|QMargins
name|margins
decl_stmt|;
DECL|member|customMargins
name|QMargins
name|customMargins
decl_stmt|;
comment|// User-defined, additional frame for WM_NCCALCSIZE
DECL|member|frameX
name|int
name|frameX
decl_stmt|;
comment|// Passed on to CreateWindowEx(), including frame.
DECL|member|frameY
name|int
name|frameY
decl_stmt|;
DECL|member|frameWidth
name|int
name|frameWidth
decl_stmt|;
DECL|member|frameHeight
name|int
name|frameHeight
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|QWindowsWindowData
struct|struct
name|QWindowsWindowData
block|{
DECL|function|QWindowsWindowData
name|QWindowsWindowData
argument_list|()
operator|:
name|hwnd
argument_list|(
literal|0
argument_list|)
operator|,
name|embedded
argument_list|(
argument|false
argument_list|)
block|{}
DECL|member|flags
name|Qt
operator|::
name|WindowFlags
name|flags
expr_stmt|;
DECL|member|geometry
name|QRect
name|geometry
decl_stmt|;
DECL|member|frame
name|QMargins
name|frame
decl_stmt|;
comment|// Do not use directly for windows, see FrameDirty.
DECL|member|customMargins
name|QMargins
name|customMargins
decl_stmt|;
comment|// User-defined, additional frame for NCCALCSIZE
DECL|member|hwnd
name|HWND
name|hwnd
decl_stmt|;
DECL|member|embedded
name|bool
name|embedded
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
DECL|member|staticOpenGLContext
name|QSharedPointer
operator|<
name|QWindowsStaticOpenGLContext
operator|>
name|staticOpenGLContext
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_OPENGL
specifier|static
name|QWindowsWindowData
name|create
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|QWindowsWindowData
modifier|&
name|parameters
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
function_decl|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QWindowsWindow
range|:
name|public
name|QPlatformWindow
block|{
name|public
operator|:
expr|enum
name|Flags
block|{
name|AutoMouseCapture
operator|=
literal|0x1
block|,
comment|//! Automatic mouse capture on button press.
name|WithinSetParent
operator|=
literal|0x2
block|,
name|FrameDirty
operator|=
literal|0x4
block|,
comment|//! Frame outdated by setStyle, recalculate in next query.
name|OpenGLSurface
operator|=
literal|0x10
block|,
name|OpenGL_ES2
operator|=
literal|0x20
block|,
name|OpenGLDoubleBuffered
operator|=
literal|0x40
block|,
name|OpenGlPixelFormatInitialized
operator|=
literal|0x80
block|,
name|BlockedByModal
operator|=
literal|0x100
block|,
name|SizeGripOperation
operator|=
literal|0x200
block|,
name|FrameStrutEventsEnabled
operator|=
literal|0x400
block|,
name|SynchronousGeometryChangeEvent
operator|=
literal|0x800
block|,
name|WithinSetStyle
operator|=
literal|0x1000
block|,
name|WithinDestroy
operator|=
literal|0x2000
block|,
name|TouchRegistered
operator|=
literal|0x4000
block|,
name|AlertState
operator|=
literal|0x8000
block|,
name|Exposed
operator|=
literal|0x10000
block|,
name|WithinCreate
operator|=
literal|0x20000
block|,
name|WithinMaximize
operator|=
literal|0x40000
block|,
name|MaximizeToFullScreen
operator|=
literal|0x80000
block|}
block|;
name|QWindowsWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
specifier|const
name|QWindowsWindowData
operator|&
name|data
argument_list|)
block|;
operator|~
name|QWindowsWindow
argument_list|()
block|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_format
return|;
block|}
name|void
name|setGeometryDp
argument_list|(
specifier|const
name|QRect
operator|&
name|rectIn
argument_list|)
block|;
name|void
name|setGeometry
argument_list|(
argument|const QRect&rect
argument_list|)
name|Q_DECL_OVERRIDE
block|{
name|setGeometryDp
argument_list|(
name|QWindowsScaling
operator|::
name|mapToNative
argument_list|(
name|rect
argument_list|)
argument_list|)
block|; }
name|QRect
name|geometryDp
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|.
name|geometry
return|;
block|}
name|QRect
name|geometry
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|QWindowsScaling
operator|::
name|mapFromNative
argument_list|(
name|geometryDp
argument_list|()
argument_list|)
return|;
block|}
name|QRect
name|normalGeometryDp
argument_list|()
specifier|const
block|;
name|QRect
name|normalGeometry
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|QWindowsScaling
operator|::
name|mapFromNative
argument_list|(
name|normalGeometryDp
argument_list|()
argument_list|)
return|;
block|}
name|qreal
name|devicePixelRatio
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|qreal
argument_list|(
name|QWindowsScaling
operator|::
name|factor
argument_list|()
argument_list|)
return|;
block|}
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isVisible
argument_list|()
specifier|const
block|;
name|bool
name|isExposed
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|testFlag
argument_list|(
name|Exposed
argument_list|)
return|;
block|}
name|bool
name|isActive
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isEmbedded
argument_list|(
argument|const QPlatformWindow *parentWindow
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPoint
name|mapToGlobalDp
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|;
name|QPoint
name|mapToGlobal
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|mapToGlobalDp
argument_list|(
name|pos
operator|*
name|QWindowsScaling
operator|::
name|factor
argument_list|()
argument_list|)
operator|/
name|QWindowsScaling
operator|::
name|factor
argument_list|()
return|;
block|}
name|QPoint
name|mapFromGlobalDp
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|;
name|QPoint
name|mapFromGlobal
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|mapFromGlobalDp
argument_list|(
name|pos
operator|*
name|QWindowsScaling
operator|::
name|factor
argument_list|()
argument_list|)
operator|/
name|QWindowsScaling
operator|::
name|factor
argument_list|()
return|;
block|}
name|void
name|setWindowFlags
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setWindowState
argument_list|(
argument|Qt::WindowState state
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|HWND
name|handle
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|.
name|hwnd
return|;
block|}
name|WId
name|winId
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|WId
argument_list|(
name|m_data
operator|.
name|hwnd
argument_list|)
return|;
block|}
name|void
name|setParent
argument_list|(
argument|const QPlatformWindow *window
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setWindowTitle
argument_list|(
argument|const QString&title
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|raise
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|lower
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|windowEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|propagateSizeHints
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QMargins
name|frameMarginsDp
argument_list|()
specifier|const
block|;
name|QMargins
name|frameMargins
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|frameMarginsDp
argument_list|()
operator|/
name|QWindowsScaling
operator|::
name|factor
argument_list|()
return|;
block|}
name|void
name|setOpacity
argument_list|(
argument|qreal level
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setMask
argument_list|(
argument|const QRegion&region
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|qreal
name|opacity
argument_list|()
specifier|const
block|{
return|return
name|m_opacity
return|;
block|}
name|void
name|requestActivateWindow
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|setKeyboardGrabEnabled
argument_list|(
argument|bool grab
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|setMouseGrabEnabled
argument_list|(
argument|bool grab
argument_list|)
name|Q_DECL_OVERRIDE
block|;
specifier|inline
name|bool
name|hasMouseCapture
argument_list|()
specifier|const
block|{
return|return
name|GetCapture
argument_list|()
operator|==
name|m_data
operator|.
name|hwnd
return|;
block|}
name|bool
name|startSystemResize
argument_list|(
argument|const QPoint&
argument_list|,
argument|Qt::Corner corner
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setFrameStrutEventsEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|frameStrutEventsEnabled
argument_list|()
specifier|const
block|{
return|return
name|testFlag
argument_list|(
name|FrameStrutEventsEnabled
argument_list|)
return|;
block|}
name|QMargins
name|customMargins
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|.
name|customMargins
return|;
block|}
name|void
name|setCustomMargins
argument_list|(
specifier|const
name|QMargins
operator|&
name|m
argument_list|)
block|;
specifier|inline
name|unsigned
name|style
argument_list|()
specifier|const
block|{
return|return
name|GetWindowLongPtr
argument_list|(
name|m_data
operator|.
name|hwnd
argument_list|,
name|GWL_STYLE
argument_list|)
return|;
block|}
name|void
name|setStyle
argument_list|(
argument|unsigned s
argument_list|)
specifier|const
block|;
specifier|inline
name|unsigned
name|exStyle
argument_list|()
specifier|const
block|{
return|return
name|GetWindowLongPtr
argument_list|(
name|m_data
operator|.
name|hwnd
argument_list|,
name|GWL_EXSTYLE
argument_list|)
return|;
block|}
name|void
name|setExStyle
argument_list|(
argument|unsigned s
argument_list|)
specifier|const
block|;
name|bool
name|handleWmPaint
argument_list|(
argument|HWND hwnd
argument_list|,
argument|UINT message
argument_list|,
argument|WPARAM wParam
argument_list|,
argument|LPARAM lParam
argument_list|)
block|;
name|void
name|handleMoved
argument_list|()
block|;
name|void
name|handleResized
argument_list|(
argument|int wParam
argument_list|)
block|;
name|void
name|handleHidden
argument_list|()
block|;
name|void
name|handleCompositionSettingsChanged
argument_list|()
block|;
specifier|static
specifier|inline
name|HWND
name|handleOf
argument_list|(
specifier|const
name|QWindow
operator|*
name|w
argument_list|)
block|;
specifier|static
specifier|inline
name|QWindowsWindow
operator|*
name|baseWindowOf
argument_list|(
specifier|const
name|QWindow
operator|*
name|w
argument_list|)
block|;
specifier|static
name|QWindow
operator|*
name|topLevelOf
argument_list|(
name|QWindow
operator|*
name|w
argument_list|)
block|;
specifier|static
specifier|inline
name|void
operator|*
name|userDataOf
argument_list|(
argument|HWND hwnd
argument_list|)
block|;
specifier|static
specifier|inline
name|void
name|setUserDataOf
argument_list|(
argument|HWND hwnd
argument_list|,
argument|void *ud
argument_list|)
block|;
specifier|static
name|bool
name|setWindowLayered
argument_list|(
argument|HWND hwnd
argument_list|,
argument|Qt::WindowFlags flags
argument_list|,
argument|bool hasAlpha
argument_list|,
argument|qreal opacity
argument_list|)
block|;
name|bool
name|isLayered
argument_list|()
specifier|const
block|;
name|HDC
name|getDC
argument_list|()
block|;
name|void
name|releaseDC
argument_list|()
block|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
comment|// maybe available on some SDKs revisit WM_GETMINMAXINFO
name|void
name|getSizeHints
argument_list|(
argument|MINMAXINFO *mmi
argument_list|)
specifier|const
block|;
name|bool
name|handleNonClientHitTest
argument_list|(
argument|const QPoint&globalPos
argument_list|,
argument|LRESULT *result
argument_list|)
specifier|const
block|;
endif|#
directive|endif
comment|// !Q_OS_WINCE
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QWindowsWindowCursor
name|cursor
argument_list|()
specifier|const
block|{
return|return
name|m_cursor
return|;
block|}
endif|#
directive|endif
name|void
name|setCursor
argument_list|(
specifier|const
name|QWindowsWindowCursor
operator|&
name|c
argument_list|)
block|;
name|void
name|applyCursor
argument_list|()
block|;
specifier|static
name|QByteArray
name|debugWindowFlags
argument_list|(
argument|Qt::WindowFlags wf
argument_list|)
block|;
specifier|inline
name|bool
name|testFlag
argument_list|(
argument|unsigned f
argument_list|)
specifier|const
block|{
return|return
operator|(
name|m_flags
operator|&
name|f
operator|)
operator|!=
literal|0
return|;
block|}
specifier|inline
name|void
name|setFlag
argument_list|(
argument|unsigned f
argument_list|)
specifier|const
block|{
name|m_flags
operator||=
name|f
block|; }
specifier|inline
name|void
name|clearFlag
argument_list|(
argument|unsigned f
argument_list|)
specifier|const
block|{
name|m_flags
operator|&=
operator|~
name|f
block|; }
name|void
name|setEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|isEnabled
argument_list|()
specifier|const
block|;
name|void
name|setWindowIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|)
block|;
name|void
operator|*
name|surface
argument_list|(
name|void
operator|*
name|nativeConfig
argument_list|)
block|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|void
name|setAlertState
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|isAlertState
argument_list|()
specifier|const
block|{
return|return
name|testFlag
argument_list|(
name|AlertState
argument_list|)
return|;
block|}
name|void
name|alertWindow
argument_list|(
argument|int durationMs =
literal|0
argument_list|)
block|;
name|void
name|stopAlertWindow
argument_list|()
block|;
endif|#
directive|endif
name|private
operator|:
specifier|inline
name|void
name|show_sys
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|hide_sys
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|setGeometry_sys
argument_list|(
argument|const QRect&rect
argument_list|)
specifier|const
block|;
specifier|inline
name|QRect
name|frameGeometry_sys
argument_list|()
specifier|const
block|;
specifier|inline
name|QRect
name|geometry_sys
argument_list|()
specifier|const
block|;
specifier|inline
name|QWindowsWindowData
name|setWindowFlags_sys
argument_list|(
argument|Qt::WindowFlags wt
argument_list|,
argument|unsigned flags =
literal|0
argument_list|)
specifier|const
block|;
specifier|inline
name|bool
name|isFullScreen_sys
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|setWindowState_sys
argument_list|(
argument|Qt::WindowState newState
argument_list|)
block|;
specifier|inline
name|void
name|setParent_sys
argument_list|(
specifier|const
name|QPlatformWindow
operator|*
name|parent
argument_list|)
block|;
specifier|inline
name|void
name|updateTransientParent
argument_list|()
specifier|const
block|;
name|void
name|destroyWindow
argument_list|()
block|;
specifier|inline
name|bool
name|isDropSiteEnabled
argument_list|()
specifier|const
block|{
return|return
name|m_dropTarget
operator|!=
literal|0
return|;
block|}
name|void
name|setDropSiteEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|updateDropSite
argument_list|()
block|;
name|void
name|handleGeometryChange
argument_list|()
block|;
name|void
name|handleWindowStateChange
argument_list|(
argument|Qt::WindowState state
argument_list|)
block|;
specifier|inline
name|void
name|destroyIcon
argument_list|()
block|;
name|void
name|fireExpose
argument_list|(
argument|const QRegion&region
argument_list|,
argument|bool force=false
argument_list|)
block|;
name|mutable
name|QWindowsWindowData
name|m_data
block|;
name|mutable
name|unsigned
name|m_flags
block|;
name|HDC
name|m_hdc
block|;
name|Qt
operator|::
name|WindowState
name|m_windowState
block|;
name|qreal
name|m_opacity
block|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QWindowsWindowCursor
name|m_cursor
block|;
endif|#
directive|endif
name|QWindowsOleDropTarget
operator|*
name|m_dropTarget
block|;
name|unsigned
name|m_savedStyle
block|;
name|QRect
name|m_savedFrameGeometry
block|;
specifier|const
name|QSurfaceFormat
name|m_format
block|;
ifdef|#
directive|ifdef
name|Q_OS_WINCE
name|bool
name|m_previouslyHidden
block|;
endif|#
directive|endif
name|HICON
name|m_iconSmall
block|;
name|HICON
name|m_iconBig
block|;
name|void
operator|*
name|m_surface
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Debug
end_comment
begin_expr_stmt
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|d
operator|,
specifier|const
name|RECT
operator|&
name|r
operator|)
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_comment
comment|// maybe available on some SDKs revisit WM_GETMINMAXINFO/WM_NCCALCSIZE
end_comment
begin_expr_stmt
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|d
operator|,
specifier|const
name|MINMAXINFO
operator|&
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|d
operator|,
specifier|const
name|NCCALCSIZE_PARAMS
operator|&
name|p
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ---------- QWindowsGeometryHint inline functions.
end_comment
begin_expr_stmt
DECL|function|mapToGlobal
name|QPoint
name|QWindowsGeometryHint
operator|::
name|mapToGlobal
argument_list|(
argument|HWND hwnd
argument_list|,
argument|const QPoint&qp
argument_list|)
block|{
name|POINT
name|p
operator|=
block|{
name|qp
operator|.
name|x
argument_list|()
block|,
name|qp
operator|.
name|y
argument_list|()
block|}
block|;
name|ClientToScreen
argument_list|(
name|hwnd
argument_list|,
operator|&
name|p
argument_list|)
block|;
return|return
name|QPoint
argument_list|(
name|p
operator|.
name|x
argument_list|,
name|p
operator|.
name|y
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|mapFromGlobal
name|QPoint
name|QWindowsGeometryHint
operator|::
name|mapFromGlobal
argument_list|(
argument|const HWND hwnd
argument_list|,
argument|const QPoint&qp
argument_list|)
block|{
name|POINT
name|p
operator|=
block|{
name|qp
operator|.
name|x
argument_list|()
block|,
name|qp
operator|.
name|y
argument_list|()
block|}
block|;
name|ScreenToClient
argument_list|(
name|hwnd
argument_list|,
operator|&
name|p
argument_list|)
block|;
return|return
name|QPoint
argument_list|(
name|p
operator|.
name|x
argument_list|,
name|p
operator|.
name|y
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|mapToGlobal
name|QPoint
name|QWindowsGeometryHint
operator|::
name|mapToGlobal
argument_list|(
argument|const QWindow *w
argument_list|,
argument|const QPoint&p
argument_list|)
block|{
return|return
name|QWindowsGeometryHint
operator|::
name|mapToGlobal
argument_list|(
name|QWindowsWindow
operator|::
name|handleOf
argument_list|(
name|w
argument_list|)
argument_list|,
name|p
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|mapFromGlobal
name|QPoint
name|QWindowsGeometryHint
operator|::
name|mapFromGlobal
argument_list|(
argument|const QWindow *w
argument_list|,
argument|const QPoint&p
argument_list|)
block|{
return|return
name|QWindowsGeometryHint
operator|::
name|mapFromGlobal
argument_list|(
name|QWindowsWindow
operator|::
name|handleOf
argument_list|(
name|w
argument_list|)
argument_list|,
name|p
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// ---------- QWindowsBaseWindow inline functions.
end_comment
begin_expr_stmt
DECL|function|baseWindowOf
name|QWindowsWindow
operator|*
name|QWindowsWindow
operator|::
name|baseWindowOf
argument_list|(
argument|const QWindow *w
argument_list|)
block|{
if|if
condition|(
name|w
condition|)
if|if
condition|(
name|QPlatformWindow
modifier|*
name|pw
init|=
name|w
operator|->
name|handle
argument_list|()
condition|)
return|return
name|static_cast
operator|<
name|QWindowsWindow
operator|*
operator|>
operator|(
name|pw
operator|)
return|;
end_expr_stmt
begin_return
return|return
literal|0
return|;
end_return
begin_expr_stmt
unit|}  HWND
DECL|function|handleOf
name|QWindowsWindow
operator|::
name|handleOf
argument_list|(
argument|const QWindow *w
argument_list|)
block|{
if|if
condition|(
specifier|const
name|QWindowsWindow
modifier|*
name|bw
init|=
name|QWindowsWindow
operator|::
name|baseWindowOf
argument_list|(
name|w
argument_list|)
condition|)
return|return
name|bw
operator|->
name|handle
argument_list|()
return|;
end_expr_stmt
begin_return
return|return
literal|0
return|;
end_return
begin_expr_stmt
unit|}  void
DECL|function|userDataOf
operator|*
name|QWindowsWindow
operator|::
name|userDataOf
argument_list|(
argument|HWND hwnd
argument_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
name|GetWindowLongPtr
argument_list|(
name|hwnd
argument_list|,
name|GWLP_USERDATA
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setUserDataOf
name|void
name|QWindowsWindow
operator|::
name|setUserDataOf
argument_list|(
argument|HWND hwnd
argument_list|,
argument|void *ud
argument_list|)
block|{
name|SetWindowLongPtr
argument_list|(
name|hwnd
argument_list|,
name|GWLP_USERDATA
argument_list|,
name|LONG_PTR
argument_list|(
name|ud
argument_list|)
argument_list|)
block|; }
DECL|function|destroyIcon
specifier|inline
name|void
name|QWindowsWindow
operator|::
name|destroyIcon
argument_list|()
block|{
if|if
condition|(
name|m_iconBig
condition|)
block|{
name|DestroyIcon
argument_list|(
name|m_iconBig
argument_list|)
expr_stmt|;
name|m_iconBig
operator|=
literal|0
expr_stmt|;
block|}
end_expr_stmt
begin_if
if|if
condition|(
name|m_iconSmall
condition|)
block|{
name|DestroyIcon
argument_list|(
name|m_iconSmall
argument_list|)
expr_stmt|;
name|m_iconSmall
operator|=
literal|0
expr_stmt|;
block|}
end_if
begin_expr_stmt
unit|}  inline
DECL|function|isLayered
name|bool
name|QWindowsWindow
operator|::
name|isLayered
argument_list|()
specifier|const
block|{
ifndef|#
directive|ifndef
name|Q_OS_WINCE
return|return
name|GetWindowLongPtr
argument_list|(
name|m_data
operator|.
name|hwnd
argument_list|,
name|GWL_EXSTYLE
argument_list|)
operator|&
name|WS_EX_LAYERED
return|;
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_return
return|return
name|false
return|;
end_return
begin_endif
endif|#
directive|endif
end_endif
begin_macro
unit|}  QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
argument|QMargins
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSWINDOW_H
end_comment
end_unit
