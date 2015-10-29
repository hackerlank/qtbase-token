begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014-2015 Canonical, Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL3$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPLv3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or later as published by the Free ** Software Foundation and appearing in the file LICENSE.GPL included in ** the packaging of this file. Please review the following information to ** ensure the GNU General Public License version 2.0 requirements will be ** met: http://www.gnu.org/licenses/gpl-2.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// Local
end_comment
begin_include
include|#
directive|include
file|"qmirclientclipboard.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientinput.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientwindow.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientscreen.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientlogging.h"
end_include
begin_comment
comment|// Qt
end_comment
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<QMutex>
end_include
begin_include
include|#
directive|include
file|<QMutexLocker>
end_include
begin_include
include|#
directive|include
file|<QSize>
end_include
begin_include
include|#
directive|include
file|<QtMath>
end_include
begin_comment
comment|// Platform API
end_comment
begin_include
include|#
directive|include
file|<ubuntu/application/instance.h>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_define
DECL|macro|IS_OPAQUE_FLAG
define|#
directive|define
name|IS_OPAQUE_FLAG
value|1
end_define
begin_namespace
namespace|namespace
block|{
DECL|function|qtWindowStateToMirSurfaceState
name|MirSurfaceState
name|qtWindowStateToMirSurfaceState
parameter_list|(
name|Qt
operator|::
name|WindowState
name|state
parameter_list|)
block|{
switch|switch
condition|(
name|state
condition|)
block|{
case|case
name|Qt
operator|::
name|WindowNoState
case|:
return|return
name|mir_surface_state_restored
return|;
case|case
name|Qt
operator|::
name|WindowFullScreen
case|:
return|return
name|mir_surface_state_fullscreen
return|;
case|case
name|Qt
operator|::
name|WindowMaximized
case|:
return|return
name|mir_surface_state_maximized
return|;
case|case
name|Qt
operator|::
name|WindowMinimized
case|:
return|return
name|mir_surface_state_minimized
return|;
default|default:
name|LOG
argument_list|(
literal|"Unexpected Qt::WindowState: %d"
argument_list|,
name|state
argument_list|)
expr_stmt|;
return|return
name|mir_surface_state_restored
return|;
block|}
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
DECL|function|qtWindowStateToStr
specifier|const
name|char
modifier|*
name|qtWindowStateToStr
parameter_list|(
name|Qt
operator|::
name|WindowState
name|state
parameter_list|)
block|{
switch|switch
condition|(
name|state
condition|)
block|{
case|case
name|Qt
operator|::
name|WindowNoState
case|:
return|return
literal|"NoState"
return|;
case|case
name|Qt
operator|::
name|WindowFullScreen
case|:
return|return
literal|"FullScreen"
return|;
case|case
name|Qt
operator|::
name|WindowMaximized
case|:
return|return
literal|"Maximized"
return|;
case|case
name|Qt
operator|::
name|WindowMinimized
case|:
return|return
literal|"Minimized"
return|;
default|default:
return|return
literal|"!?"
return|;
block|}
block|}
endif|#
directive|endif
block|}
end_namespace
begin_comment
comment|// anonymous namespace
end_comment
begin_class
DECL|class|QMirClientWindowPrivate
class|class
name|QMirClientWindowPrivate
block|{
public|public:
name|void
name|createEGLSurface
parameter_list|(
name|EGLNativeWindowType
name|nativeWindow
parameter_list|)
function_decl|;
name|void
name|destroyEGLSurface
parameter_list|()
function_decl|;
name|int
name|panelHeight
parameter_list|()
function_decl|;
DECL|member|screen
name|QMirClientScreen
modifier|*
name|screen
decl_stmt|;
DECL|member|eglSurface
name|EGLSurface
name|eglSurface
decl_stmt|;
DECL|member|id
name|WId
name|id
decl_stmt|;
DECL|member|input
name|QMirClientInput
modifier|*
name|input
decl_stmt|;
DECL|member|state
name|Qt
operator|::
name|WindowState
name|state
decl_stmt|;
DECL|member|connection
name|MirConnection
modifier|*
name|connection
decl_stmt|;
DECL|member|surface
name|MirSurface
modifier|*
name|surface
decl_stmt|;
DECL|member|bufferSize
name|QSize
name|bufferSize
decl_stmt|;
DECL|member|mutex
name|QMutex
name|mutex
decl_stmt|;
DECL|member|clipboard
name|QSharedPointer
argument_list|<
name|QMirClientClipboard
argument_list|>
name|clipboard
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|eventCallback
specifier|static
name|void
name|eventCallback
parameter_list|(
name|MirSurface
modifier|*
name|surface
parameter_list|,
specifier|const
name|MirEvent
modifier|*
name|event
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
block|{
operator|(
name|void
operator|)
name|surface
expr_stmt|;
name|DASSERT
argument_list|(
name|context
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|QMirClientWindow
modifier|*
name|platformWindow
init|=
cast|static_cast
argument_list|<
name|QMirClientWindow
operator|*
argument_list|>
argument_list|(
name|context
argument_list|)
decl_stmt|;
name|platformWindow
operator|->
name|priv
argument_list|()
operator|->
name|input
operator|->
name|postEvent
argument_list|(
name|platformWindow
argument_list|,
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|surfaceCreateCallback
specifier|static
name|void
name|surfaceCreateCallback
parameter_list|(
name|MirSurface
modifier|*
name|surface
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
block|{
name|DASSERT
argument_list|(
name|context
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|QMirClientWindow
modifier|*
name|platformWindow
init|=
cast|static_cast
argument_list|<
name|QMirClientWindow
operator|*
argument_list|>
argument_list|(
name|context
argument_list|)
decl_stmt|;
name|platformWindow
operator|->
name|priv
argument_list|()
operator|->
name|surface
operator|=
name|surface
expr_stmt|;
name|mir_surface_set_event_handler
argument_list|(
name|surface
argument_list|,
name|eventCallback
argument_list|,
name|context
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QMirClientWindow
name|QMirClientWindow
operator|::
name|QMirClientWindow
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
name|QSharedPointer
argument_list|<
name|QMirClientClipboard
argument_list|>
name|clipboard
parameter_list|,
name|QMirClientScreen
modifier|*
name|screen
parameter_list|,
name|QMirClientInput
modifier|*
name|input
parameter_list|,
name|MirConnection
modifier|*
name|connection
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
literal|nullptr
argument_list|)
member_init_list|,
name|QPlatformWindow
argument_list|(
name|w
argument_list|)
block|{
name|DASSERT
argument_list|(
name|screen
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|d
operator|=
operator|new
name|QMirClientWindowPrivate
expr_stmt|;
name|d
operator|->
name|screen
operator|=
name|screen
expr_stmt|;
name|d
operator|->
name|eglSurface
operator|=
name|EGL_NO_SURFACE
expr_stmt|;
name|d
operator|->
name|input
operator|=
name|input
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|window
argument_list|()
operator|->
name|windowState
argument_list|()
expr_stmt|;
name|d
operator|->
name|connection
operator|=
name|connection
expr_stmt|;
name|d
operator|->
name|clipboard
operator|=
name|clipboard
expr_stmt|;
specifier|static
name|int
name|id
init|=
literal|1
decl_stmt|;
name|d
operator|->
name|id
operator|=
name|id
operator|++
expr_stmt|;
comment|// Use client geometry if set explicitly, use available screen geometry otherwise.
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|window
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|isValid
argument_list|()
operator|&&
name|window
argument_list|()
operator|->
name|geometry
argument_list|()
operator|!=
name|screen
operator|->
name|geometry
argument_list|()
condition|?
name|window
argument_list|()
operator|->
name|geometry
argument_list|()
else|:
name|screen
operator|->
name|availableGeometry
argument_list|()
argument_list|)
expr_stmt|;
name|createWindow
argument_list|()
expr_stmt|;
name|DLOG
argument_list|(
literal|"QMirClientWindow::QMirClientWindow (this=%p, w=%p, screen=%p, input=%p)"
argument_list|,
name|this
argument_list|,
name|w
argument_list|,
name|screen
argument_list|,
name|input
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QMirClientWindow
name|QMirClientWindow
operator|::
name|~
name|QMirClientWindow
parameter_list|()
block|{
name|DLOG
argument_list|(
literal|"QMirClientWindow::~QMirClientWindow"
argument_list|)
expr_stmt|;
name|d
operator|->
name|destroyEGLSurface
argument_list|()
expr_stmt|;
name|mir_surface_release_sync
argument_list|(
name|d
operator|->
name|surface
argument_list|)
expr_stmt|;
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|createEGLSurface
name|void
name|QMirClientWindowPrivate
operator|::
name|createEGLSurface
parameter_list|(
name|EGLNativeWindowType
name|nativeWindow
parameter_list|)
block|{
name|DLOG
argument_list|(
literal|"QMirClientWindowPrivate::createEGLSurface (this=%p, nativeWindow=%p)"
argument_list|,
name|this
argument_list|,
cast|reinterpret_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
name|nativeWindow
argument_list|)
argument_list|)
expr_stmt|;
name|eglSurface
operator|=
name|eglCreateWindowSurface
argument_list|(
name|screen
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|screen
operator|->
name|eglConfig
argument_list|()
argument_list|,
name|nativeWindow
argument_list|,
literal|nullptr
argument_list|)
expr_stmt|;
name|DASSERT
argument_list|(
name|eglSurface
operator|!=
name|EGL_NO_SURFACE
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|destroyEGLSurface
name|void
name|QMirClientWindowPrivate
operator|::
name|destroyEGLSurface
parameter_list|()
block|{
name|DLOG
argument_list|(
literal|"QMirClientWindowPrivate::destroyEGLSurface (this=%p)"
argument_list|,
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|eglSurface
operator|!=
name|EGL_NO_SURFACE
condition|)
block|{
name|eglDestroySurface
argument_list|(
name|screen
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|eglSurface
argument_list|)
expr_stmt|;
name|eglSurface
operator|=
name|EGL_NO_SURFACE
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|// FIXME - in order to work around https://bugs.launchpad.net/mir/+bug/1346633
end_comment
begin_comment
comment|// we need to guess the panel height (3GU + 2DP)
end_comment
begin_function
DECL|function|panelHeight
name|int
name|QMirClientWindowPrivate
operator|::
name|panelHeight
parameter_list|()
block|{
if|if
condition|(
name|qEnvironmentVariableIsSet
argument_list|(
literal|"QT_MIRCLIENT_IGNORE_PANEL"
argument_list|)
condition|)
return|return
literal|0
return|;
specifier|const
name|int
name|defaultGridUnit
init|=
literal|8
decl_stmt|;
name|int
name|gridUnit
init|=
name|defaultGridUnit
decl_stmt|;
name|QByteArray
name|gridUnitString
init|=
name|qgetenv
argument_list|(
literal|"GRID_UNIT_PX"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|gridUnitString
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|bool
name|ok
decl_stmt|;
name|gridUnit
operator|=
name|gridUnitString
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
block|{
name|gridUnit
operator|=
name|defaultGridUnit
expr_stmt|;
block|}
block|}
name|qreal
name|densityPixelRatio
init|=
cast|static_cast
argument_list|<
name|qreal
argument_list|>
argument_list|(
name|gridUnit
argument_list|)
operator|/
name|defaultGridUnit
decl_stmt|;
return|return
name|gridUnit
operator|*
literal|3
operator|+
name|qFloor
argument_list|(
name|densityPixelRatio
argument_list|)
operator|*
literal|2
return|;
block|}
end_function
begin_namespace
namespace|namespace
block|{
specifier|static
name|MirPixelFormat
DECL|function|mir_choose_default_pixel_format
name|mir_choose_default_pixel_format
parameter_list|(
name|MirConnection
modifier|*
name|connection
parameter_list|)
block|{
name|MirPixelFormat
name|format
index|[
name|mir_pixel_formats
index|]
decl_stmt|;
name|unsigned
name|int
name|nformats
decl_stmt|;
name|mir_connection_get_available_surface_formats
argument_list|(
name|connection
argument_list|,
name|format
argument_list|,
name|mir_pixel_formats
argument_list|,
operator|&
name|nformats
argument_list|)
expr_stmt|;
return|return
name|format
index|[
literal|0
index|]
return|;
block|}
block|}
end_namespace
begin_function
DECL|function|createWindow
name|void
name|QMirClientWindow
operator|::
name|createWindow
parameter_list|()
block|{
name|DLOG
argument_list|(
literal|"QMirClientWindow::createWindow (this=%p)"
argument_list|,
name|this
argument_list|)
expr_stmt|;
comment|// FIXME: remove this remnant of an old platform-api enum - needs ubuntu-keyboard update
specifier|const
name|int
name|SCREEN_KEYBOARD_ROLE
init|=
literal|7
decl_stmt|;
comment|// Get surface role and flags.
name|QVariant
name|roleVariant
init|=
name|window
argument_list|()
operator|->
name|property
argument_list|(
literal|"role"
argument_list|)
decl_stmt|;
name|int
name|role
init|=
name|roleVariant
operator|.
name|isValid
argument_list|()
condition|?
name|roleVariant
operator|.
name|toUInt
argument_list|()
else|:
literal|1
decl_stmt|;
comment|// 1 is the default role for apps.
name|QVariant
name|opaqueVariant
init|=
name|window
argument_list|()
operator|->
name|property
argument_list|(
literal|"opaque"
argument_list|)
decl_stmt|;
name|uint
name|flags
init|=
name|opaqueVariant
operator|.
name|isValid
argument_list|()
condition|?
name|opaqueVariant
operator|.
name|toUInt
argument_list|()
condition|?
cast|static_cast
argument_list|<
name|uint
argument_list|>
argument_list|(
name|IS_OPAQUE_FLAG
argument_list|)
else|:
literal|0
else|:
literal|0
decl_stmt|;
comment|// FIXME(loicm) Opaque flag is forced for now for non-system sessions (applications) for
comment|//     performance reasons.
name|flags
operator||=
cast|static_cast
argument_list|<
name|uint
argument_list|>
argument_list|(
name|IS_OPAQUE_FLAG
argument_list|)
expr_stmt|;
specifier|const
name|QByteArray
name|title
init|=
operator|(
operator|!
name|window
argument_list|()
operator|->
name|title
argument_list|()
operator|.
name|isNull
argument_list|()
operator|)
condition|?
name|window
argument_list|()
operator|->
name|title
argument_list|()
operator|.
name|toUtf8
argument_list|()
else|:
literal|"Window 1"
decl_stmt|;
comment|// legacy title
specifier|const
name|int
name|panelHeight
init|=
name|d
operator|->
name|panelHeight
argument_list|()
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
name|LOG
argument_list|(
literal|"panelHeight: '%d'"
argument_list|,
name|panelHeight
argument_list|)
expr_stmt|;
name|LOG
argument_list|(
literal|"role: '%d'"
argument_list|,
name|role
argument_list|)
expr_stmt|;
name|LOG
argument_list|(
literal|"flags: '%s'"
argument_list|,
operator|(
name|flags
operator|&
cast|static_cast
argument_list|<
name|uint
argument_list|>
argument_list|(
literal|1
argument_list|)
operator|)
condition|?
literal|"Opaque"
else|:
literal|"NotOpaque"
argument_list|)
expr_stmt|;
name|LOG
argument_list|(
literal|"title: '%s'"
argument_list|,
name|title
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Get surface geometry.
name|QRect
name|geometry
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|state
operator|==
name|Qt
operator|::
name|WindowFullScreen
condition|)
block|{
name|printf
argument_list|(
literal|"QMirClientWindow - fullscreen geometry\n"
argument_list|)
expr_stmt|;
name|geometry
operator|=
name|screen
argument_list|()
operator|->
name|geometry
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|d
operator|->
name|state
operator|==
name|Qt
operator|::
name|WindowMaximized
condition|)
block|{
name|printf
argument_list|(
literal|"QMirClientWindow - maximized geometry\n"
argument_list|)
expr_stmt|;
name|geometry
operator|=
name|screen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
expr_stmt|;
comment|/*          * FIXME: Autopilot relies on being able to convert coordinates relative of the window          * into absolute screen coordinates. Mir does not allow this, see bug lp:1346633          * Until there's a correct way to perform this transformation agreed, this horrible hack          * guesses the transformation heuristically.          *          * Assumption: this method only used on phone devices!          */
name|geometry
operator|.
name|setY
argument_list|(
name|panelHeight
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"QMirClientWindow - regular geometry\n"
argument_list|)
expr_stmt|;
name|geometry
operator|=
name|this
operator|->
name|geometry
argument_list|()
expr_stmt|;
name|geometry
operator|.
name|setY
argument_list|(
name|panelHeight
argument_list|)
expr_stmt|;
block|}
name|DLOG
argument_list|(
literal|"[ubuntumirclient QPA] creating surface at (%d, %d) with size (%d, %d) with title '%s'\n"
argument_list|,
name|geometry
operator|.
name|x
argument_list|()
argument_list|,
name|geometry
operator|.
name|y
argument_list|()
argument_list|,
name|geometry
operator|.
name|width
argument_list|()
argument_list|,
name|geometry
operator|.
name|height
argument_list|()
argument_list|,
name|title
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|MirSurfaceSpec
modifier|*
name|spec
decl_stmt|;
if|if
condition|(
name|role
operator|==
name|SCREEN_KEYBOARD_ROLE
condition|)
block|{
name|spec
operator|=
name|mir_connection_create_spec_for_input_method
argument_list|(
name|d
operator|->
name|connection
argument_list|,
name|geometry
operator|.
name|width
argument_list|()
argument_list|,
name|geometry
operator|.
name|height
argument_list|()
argument_list|,
name|mir_choose_default_pixel_format
argument_list|(
name|d
operator|->
name|connection
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|spec
operator|=
name|mir_connection_create_spec_for_normal_surface
argument_list|(
name|d
operator|->
name|connection
argument_list|,
name|geometry
operator|.
name|width
argument_list|()
argument_list|,
name|geometry
operator|.
name|height
argument_list|()
argument_list|,
name|mir_choose_default_pixel_format
argument_list|(
name|d
operator|->
name|connection
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|mir_surface_spec_set_name
argument_list|(
name|spec
argument_list|,
name|title
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
comment|// Create platform window
name|mir_wait_for
argument_list|(
name|mir_surface_create
argument_list|(
name|spec
argument_list|,
name|surfaceCreateCallback
argument_list|,
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|mir_surface_spec_release
argument_list|(
name|spec
argument_list|)
expr_stmt|;
name|DASSERT
argument_list|(
name|d
operator|->
name|surface
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|d
operator|->
name|createEGLSurface
argument_list|(
operator|(
name|EGLNativeWindowType
operator|)
name|mir_buffer_stream_get_egl_native_window
argument_list|(
name|mir_surface_get_buffer_stream
argument_list|(
name|d
operator|->
name|surface
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|state
operator|==
name|Qt
operator|::
name|WindowFullScreen
condition|)
block|{
comment|// TODO: We could set this on creation once surface spec supports it (mps already up)
name|mir_wait_for
argument_list|(
name|mir_surface_set_state
argument_list|(
name|d
operator|->
name|surface
argument_list|,
name|mir_surface_state_fullscreen
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Window manager can give us a final size different from what we asked for
comment|// so let's check what we ended up getting
block|{
name|MirSurfaceParameters
name|parameters
decl_stmt|;
name|mir_surface_get_parameters
argument_list|(
name|d
operator|->
name|surface
argument_list|,
operator|&
name|parameters
argument_list|)
expr_stmt|;
name|geometry
operator|.
name|setWidth
argument_list|(
name|parameters
operator|.
name|width
argument_list|)
expr_stmt|;
name|geometry
operator|.
name|setHeight
argument_list|(
name|parameters
operator|.
name|height
argument_list|)
expr_stmt|;
block|}
name|DLOG
argument_list|(
literal|"[ubuntumirclient QPA] created surface has size (%d, %d)"
argument_list|,
name|geometry
operator|.
name|width
argument_list|()
argument_list|,
name|geometry
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
comment|// Assume that the buffer size matches the surface size at creation time
name|d
operator|->
name|bufferSize
operator|=
name|geometry
operator|.
name|size
argument_list|()
expr_stmt|;
comment|// Tell Qt about the geometry.
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|window
argument_list|()
argument_list|,
name|geometry
argument_list|)
expr_stmt|;
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|geometry
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|moveResize
name|void
name|QMirClientWindow
operator|::
name|moveResize
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
operator|(
name|void
operator|)
name|rect
expr_stmt|;
comment|// TODO: Not yet supported by mir.
block|}
end_function
begin_function
DECL|function|handleSurfaceResize
name|void
name|QMirClientWindow
operator|::
name|handleSurfaceResize
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|QMutexLocker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
expr_stmt|;
name|LOG
argument_list|(
literal|"QMirClientWindow::handleSurfaceResize(width=%d, height=%d)"
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
comment|// The current buffer size hasn't actually changed. so just render on it and swap
comment|// buffers in the hope that the next buffer will match the surface size advertised
comment|// in this event.
comment|// But since this event is processed by a thread different from the one that swaps
comment|// buffers, you can never know if this information is already outdated as there's
comment|// no synchronicity whatsoever between the processing of resize events and the
comment|// consumption of buffers.
if|if
condition|(
name|d
operator|->
name|bufferSize
operator|.
name|width
argument_list|()
operator|!=
name|width
operator|||
name|d
operator|->
name|bufferSize
operator|.
name|height
argument_list|()
operator|!=
name|height
condition|)
block|{
name|QWindowSystemInterface
operator|::
name|handleExposeEvent
argument_list|(
name|window
argument_list|()
argument_list|,
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|flushWindowSystemEvents
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|handleSurfaceFocusChange
name|void
name|QMirClientWindow
operator|::
name|handleSurfaceFocusChange
parameter_list|(
name|bool
name|focused
parameter_list|)
block|{
name|LOG
argument_list|(
literal|"QMirClientWindow::handleSurfaceFocusChange(focused=%s)"
argument_list|,
name|focused
condition|?
literal|"true"
else|:
literal|"false"
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|activatedWindow
init|=
name|focused
condition|?
name|window
argument_list|()
else|:
literal|nullptr
decl_stmt|;
comment|// System clipboard contents might have changed while this window was unfocused and wihtout
comment|// this process getting notified about it because it might have been suspended (due to
comment|// application lifecycle policies), thus unable to listen to any changes notified through
comment|// D-Bus.
comment|// Therefore let's ensure we are up to date with the system clipboard now that we are getting
comment|// focused again.
if|if
condition|(
name|focused
condition|)
block|{
name|d
operator|->
name|clipboard
operator|->
name|requestDBusClipboardContents
argument_list|()
expr_stmt|;
block|}
name|QWindowSystemInterface
operator|::
name|handleWindowActivated
argument_list|(
name|activatedWindow
argument_list|,
name|Qt
operator|::
name|ActiveWindowFocusReason
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setWindowState
name|void
name|QMirClientWindow
operator|::
name|setWindowState
parameter_list|(
name|Qt
operator|::
name|WindowState
name|state
parameter_list|)
block|{
name|QMutexLocker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
expr_stmt|;
name|DLOG
argument_list|(
literal|"QMirClientWindow::setWindowState (this=%p, %s)"
argument_list|,
name|this
argument_list|,
name|qtWindowStateToStr
argument_list|(
name|state
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|==
name|d
operator|->
name|state
condition|)
return|return;
comment|// TODO: Perhaps we should check if the states are applied?
name|mir_wait_for
argument_list|(
name|mir_surface_set_state
argument_list|(
name|d
operator|->
name|surface
argument_list|,
name|qtWindowStateToMirSurfaceState
argument_list|(
name|state
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|state
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|QMirClientWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|DLOG
argument_list|(
literal|"QMirClientWindow::setGeometry (this=%p)"
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|bool
name|doMoveResize
decl_stmt|;
block|{
name|QMutexLocker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
expr_stmt|;
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|doMoveResize
operator|=
name|d
operator|->
name|state
operator|!=
name|Qt
operator|::
name|WindowFullScreen
operator|&&
name|d
operator|->
name|state
operator|!=
name|Qt
operator|::
name|WindowMaximized
expr_stmt|;
block|}
if|if
condition|(
name|doMoveResize
condition|)
block|{
name|moveResize
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setVisible
name|void
name|QMirClientWindow
operator|::
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
name|QMutexLocker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
expr_stmt|;
name|DLOG
argument_list|(
literal|"QMirClientWindow::setVisible (this=%p, visible=%s)"
argument_list|,
name|this
argument_list|,
name|visible
condition|?
literal|"true"
else|:
literal|"false"
argument_list|)
expr_stmt|;
if|if
condition|(
name|visible
condition|)
block|{
name|mir_wait_for
argument_list|(
name|mir_surface_set_state
argument_list|(
name|d
operator|->
name|surface
argument_list|,
name|qtWindowStateToMirSurfaceState
argument_list|(
name|d
operator|->
name|state
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleExposeEvent
argument_list|(
name|window
argument_list|()
argument_list|,
name|QRect
argument_list|()
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|flushWindowSystemEvents
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|// TODO: Use the new mir_surface_state_hidden state instead of mir_surface_state_minimized.
comment|//       Will have to change qtmir and unity8 for that.
name|mir_wait_for
argument_list|(
name|mir_surface_set_state
argument_list|(
name|d
operator|->
name|surface
argument_list|,
name|mir_surface_state_minimized
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|eglSurface
name|void
modifier|*
name|QMirClientWindow
operator|::
name|eglSurface
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|eglSurface
return|;
block|}
end_function
begin_function
DECL|function|winId
name|WId
name|QMirClientWindow
operator|::
name|winId
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|id
return|;
block|}
end_function
begin_function
DECL|function|onBuffersSwapped_threadSafe
name|void
name|QMirClientWindow
operator|::
name|onBuffersSwapped_threadSafe
parameter_list|(
name|int
name|newBufferWidth
parameter_list|,
name|int
name|newBufferHeight
parameter_list|)
block|{
name|QMutexLocker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
expr_stmt|;
name|bool
name|sizeKnown
init|=
name|newBufferWidth
operator|>
literal|0
operator|&&
name|newBufferHeight
operator|>
literal|0
decl_stmt|;
if|if
condition|(
name|sizeKnown
operator|&&
operator|(
name|d
operator|->
name|bufferSize
operator|.
name|width
argument_list|()
operator|!=
name|newBufferWidth
operator|||
name|d
operator|->
name|bufferSize
operator|.
name|height
argument_list|()
operator|!=
name|newBufferHeight
operator|)
condition|)
block|{
name|DLOG
argument_list|(
literal|"QMirClientWindow::onBuffersSwapped_threadSafe - buffer size changed from (%d,%d) to (%d,%d)"
argument_list|,
name|d
operator|->
name|bufferSize
operator|.
name|width
argument_list|()
argument_list|,
name|d
operator|->
name|bufferSize
operator|.
name|height
argument_list|()
argument_list|,
name|newBufferWidth
argument_list|,
name|newBufferHeight
argument_list|)
expr_stmt|;
name|d
operator|->
name|bufferSize
operator|.
name|rwidth
argument_list|()
operator|=
name|newBufferWidth
expr_stmt|;
name|d
operator|->
name|bufferSize
operator|.
name|rheight
argument_list|()
operator|=
name|newBufferHeight
expr_stmt|;
name|QRect
name|newGeometry
decl_stmt|;
name|newGeometry
operator|=
name|geometry
argument_list|()
expr_stmt|;
name|newGeometry
operator|.
name|setWidth
argument_list|(
name|d
operator|->
name|bufferSize
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|newGeometry
operator|.
name|setHeight
argument_list|(
name|d
operator|->
name|bufferSize
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|newGeometry
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|window
argument_list|()
argument_list|,
name|newGeometry
argument_list|,
name|QRect
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
