begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|"qwindowscursor.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_OPENGL_ES_2
end_ifdef
begin_include
include|#
directive|include
file|<QtCore/QSharedPointer>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
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
begin_ifdef
ifdef|#
directive|ifdef
name|QT_OPENGL_ES_2
end_ifdef
begin_decl_stmt
DECL|variable|QWindowsEGLStaticContext
name|class
name|QWindowsEGLStaticContext
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
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
begin_decl_stmt
name|class
name|QWindowsWindow
range|:
name|public
name|QPlatformWindow
block|{
name|public
operator|:
ifdef|#
directive|ifdef
name|QT_OPENGL_ES_2
typedef|typedef
name|QSharedPointer
operator|<
name|QWindowsEGLStaticContext
operator|>
name|QWindowsEGLStaticContextPtr
expr_stmt|;
endif|#
directive|endif
block|enum
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
block|}
decl_stmt|;
end_decl_stmt
begin_struct
struct|struct
name|WindowData
block|{
name|WindowData
argument_list|()
operator|:
name|hwnd
argument_list|(
literal|0
argument_list|)
block|{}
name|Qt
operator|::
name|WindowFlags
name|flags
expr_stmt|;
name|QRect
name|geometry
decl_stmt|;
name|QMargins
name|frame
decl_stmt|;
comment|// Do not use directly for windows, see FrameDirty.
name|QMargins
name|customMargins
decl_stmt|;
comment|// User-defined, additional frame for NCCALCSIZE
name|HWND
name|hwnd
decl_stmt|;
name|bool
name|embedded
decl_stmt|;
specifier|static
name|WindowData
name|create
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|WindowData
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
begin_expr_stmt
name|QWindowsWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
specifier|const
name|WindowData
operator|&
name|data
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|~
name|QWindowsWindow
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
block|{
return|return
name|m_format
return|;
block|}
end_expr_stmt
begin_function_decl
name|virtual
name|void
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|virtual
name|QRect
name|geometry
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|.
name|geometry
return|;
block|}
end_expr_stmt
begin_function_decl
name|virtual
name|void
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|isVisible
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|bool
name|isExposed
argument_list|()
specifier|const
block|{
return|return
name|testFlag
argument_list|(
name|Exposed
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|bool
name|isActive
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|virtual
name|bool
name|isEmbedded
argument_list|(
specifier|const
name|QPlatformWindow
operator|*
name|parentWindow
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|QPoint
name|mapToGlobal
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|QPoint
name|mapFromGlobal
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|void
name|setWindowFlags
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|void
name|setWindowState
argument_list|(
name|Qt
operator|::
name|WindowState
name|state
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
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
end_expr_stmt
begin_expr_stmt
name|virtual
name|WId
name|winId
argument_list|()
specifier|const
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
end_expr_stmt
begin_function_decl
name|virtual
name|void
name|setParent
parameter_list|(
specifier|const
name|QPlatformWindow
modifier|*
name|window
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|setWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|raise
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|lower
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|windowEvent
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|propagateSizeHints
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|virtual
name|QMargins
name|frameMargins
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|virtual
name|void
name|setOpacity
parameter_list|(
name|qreal
name|level
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|setMask
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|qreal
name|opacity
argument_list|()
specifier|const
block|{
return|return
name|m_opacity
return|;
block|}
end_expr_stmt
begin_function_decl
name|virtual
name|void
name|requestActivateWindow
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|bool
name|setKeyboardGrabEnabled
parameter_list|(
name|bool
name|grab
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|bool
name|setMouseGrabEnabled
parameter_list|(
name|bool
name|grab
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
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
end_expr_stmt
begin_decl_stmt
name|virtual
name|bool
name|startSystemResize
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
name|Qt
operator|::
name|Corner
name|corner
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setFrameStrutEventsEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
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
end_expr_stmt
begin_expr_stmt
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
end_expr_stmt
begin_function_decl
name|void
name|setCustomMargins
parameter_list|(
specifier|const
name|QMargins
modifier|&
name|m
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|QT_OPENGL_ES_2
end_ifdef
begin_expr_stmt
name|EGLSurface
name|eglSurfaceHandle
argument_list|()
specifier|const
block|{
return|return
name|m_eglSurface
return|;
block|}
end_expr_stmt
begin_function_decl
name|EGLSurface
name|ensureEglSurfaceHandle
parameter_list|(
specifier|const
name|QWindowsEGLStaticContextPtr
modifier|&
name|staticContext
parameter_list|,
name|EGLConfig
name|config
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
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
end_expr_stmt
begin_decl_stmt
name|void
name|setStyle
argument_list|(
name|unsigned
name|s
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
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
end_expr_stmt
begin_decl_stmt
name|void
name|setExStyle
argument_list|(
name|unsigned
name|s
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|bool
name|handleWmPaint
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|UINT
name|message
parameter_list|,
name|WPARAM
name|wParam
parameter_list|,
name|LPARAM
name|lParam
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|handleMoved
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|handleResized
parameter_list|(
name|int
name|wParam
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|handleHidden
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
specifier|inline
name|HWND
name|handleOf
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|w
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
specifier|inline
name|QWindowsWindow
modifier|*
name|baseWindowOf
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|w
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QWindow
modifier|*
name|topLevelOf
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
specifier|inline
name|void
modifier|*
name|userDataOf
parameter_list|(
name|HWND
name|hwnd
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
specifier|inline
name|void
name|setUserDataOf
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|void
modifier|*
name|ud
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|static
name|bool
name|setWindowLayered
argument_list|(
name|HWND
name|hwnd
argument_list|,
name|Qt
operator|::
name|WindowFlags
name|flags
argument_list|,
name|bool
name|hasAlpha
argument_list|,
name|qreal
name|opacity
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|bool
name|isLayered
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|HDC
name|getDC
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|releaseDC
parameter_list|()
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_comment
comment|// maybe available on some SDKs revisit WM_GETMINMAXINFO
end_comment
begin_decl_stmt
name|void
name|getSizeHints
argument_list|(
name|MINMAXINFO
operator|*
name|mmi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|handleNonClientHitTest
argument_list|(
specifier|const
name|QPoint
operator|&
name|globalPos
argument_list|,
name|LRESULT
operator|*
name|result
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !Q_OS_WINCE
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
end_ifndef
begin_expr_stmt
name|QWindowsWindowCursor
name|cursor
argument_list|()
specifier|const
block|{
return|return
name|m_cursor
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|void
name|setCursor
parameter_list|(
specifier|const
name|QWindowsWindowCursor
modifier|&
name|c
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|applyCursor
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|QWindowsWindow
modifier|*
name|childAt
argument_list|(
specifier|const
name|QPoint
operator|&
name|clientPoint
argument_list|,
name|unsigned
name|cwexflags
operator|=
name|CWP_SKIPINVISIBLE
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QWindowsWindow
modifier|*
name|childAtScreenPoint
argument_list|(
specifier|const
name|QPoint
operator|&
name|screenPoint
argument_list|,
name|unsigned
name|cwexflags
operator|=
name|CWP_SKIPINVISIBLE
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|QByteArray
name|debugWindowFlags
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|wf
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|inline
name|bool
name|testFlag
argument_list|(
name|unsigned
name|f
argument_list|)
decl|const
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
end_decl_stmt
begin_decl_stmt
specifier|inline
name|void
name|setFlag
argument_list|(
name|unsigned
name|f
argument_list|)
decl|const
block|{
name|m_flags
operator||=
name|f
expr_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|void
name|clearFlag
argument_list|(
name|unsigned
name|f
argument_list|)
decl|const
block|{
name|m_flags
operator|&=
operator|~
name|f
expr_stmt|;
block|}
end_decl_stmt
begin_function_decl
name|void
name|setEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|isEnabled
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setWindowIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_function_decl
name|void
name|setAlertState
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
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
end_expr_stmt
begin_function_decl
name|void
name|alertWindow
parameter_list|(
name|int
name|durationMs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|stopAlertWindow
parameter_list|()
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_label
name|private
label|:
end_label
begin_expr_stmt
specifier|inline
name|void
name|show_sys
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|void
name|hide_sys
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|inline
name|void
name|setGeometry_sys
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|inline
name|QRect
name|frameGeometry_sys
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QRect
name|geometry_sys
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|inline
name|WindowData
name|setWindowFlags_sys
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|wt
argument_list|,
name|unsigned
name|flags
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isFullScreen_sys
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|inline
name|void
name|setWindowState_sys
argument_list|(
name|Qt
operator|::
name|WindowState
name|newState
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|inline
name|void
name|setParent_sys
argument_list|(
specifier|const
name|QPlatformWindow
operator|*
name|parent
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|inline
name|void
name|updateTransientParent
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|destroyWindow
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|registerDropSite
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|unregisterDropSite
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|handleGeometryChange
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|handleWindowStateChange
argument_list|(
name|Qt
operator|::
name|WindowState
name|state
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|inline
name|void
name|destroyIcon
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|fireExpose
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
name|bool
name|force
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|mutable
name|WindowData
name|m_data
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|unsigned
name|m_flags
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|HDC
name|m_hdc
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|WindowState
name|m_windowState
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|qreal
name|m_opacity
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
end_ifndef
begin_decl_stmt
name|QWindowsWindowCursor
name|m_cursor
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QWindowsOleDropTarget
modifier|*
name|m_dropTarget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|unsigned
name|m_savedStyle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|m_savedFrameGeometry
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QSurfaceFormat
name|m_format
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT_OPENGL_ES_2
end_ifdef
begin_decl_stmt
name|EGLSurface
name|m_eglSurface
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QSharedPointer
operator|<
name|QWindowsEGLStaticContext
operator|>
name|m_staticEglContext
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINCE
end_ifdef
begin_decl_stmt
name|bool
name|m_previouslyHidden
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|HICON
name|m_iconSmall
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|HICON
name|m_iconBig
decl_stmt|;
end_decl_stmt
begin_comment
unit|};
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
