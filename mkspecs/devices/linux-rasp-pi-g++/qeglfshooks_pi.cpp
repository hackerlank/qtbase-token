begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfshooks.h"
end_include
begin_include
include|#
directive|include
file|"qeglfscursor.h"
end_include
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglconvenience_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglplatformcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<bcm_host.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|dispman_display
specifier|static
name|DISPMANX_DISPLAY_HANDLE_T
name|dispman_display
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|createDispmanxLayer
specifier|static
name|EGLNativeWindowType
name|createDispmanxLayer
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|int
name|z
parameter_list|,
name|DISPMANX_FLAGS_ALPHA_T
name|flags
parameter_list|)
block|{
name|VC_RECT_T
name|dst_rect
decl_stmt|;
name|dst_rect
operator|.
name|x
operator|=
name|pos
operator|.
name|x
argument_list|()
expr_stmt|;
name|dst_rect
operator|.
name|y
operator|=
name|pos
operator|.
name|y
argument_list|()
expr_stmt|;
name|dst_rect
operator|.
name|width
operator|=
name|size
operator|.
name|width
argument_list|()
expr_stmt|;
name|dst_rect
operator|.
name|height
operator|=
name|size
operator|.
name|height
argument_list|()
expr_stmt|;
name|VC_RECT_T
name|src_rect
decl_stmt|;
name|src_rect
operator|.
name|x
operator|=
literal|0
expr_stmt|;
name|src_rect
operator|.
name|y
operator|=
literal|0
expr_stmt|;
name|src_rect
operator|.
name|width
operator|=
name|size
operator|.
name|width
argument_list|()
operator|<<
literal|16
expr_stmt|;
name|src_rect
operator|.
name|height
operator|=
name|size
operator|.
name|height
argument_list|()
operator|<<
literal|16
expr_stmt|;
name|DISPMANX_UPDATE_HANDLE_T
name|dispman_update
init|=
name|vc_dispmanx_update_start
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|VC_DISPMANX_ALPHA_T
name|alpha
decl_stmt|;
name|alpha
operator|.
name|flags
operator|=
name|flags
expr_stmt|;
name|alpha
operator|.
name|opacity
operator|=
literal|0xFF
expr_stmt|;
name|alpha
operator|.
name|mask
operator|=
literal|0
expr_stmt|;
name|DISPMANX_ELEMENT_HANDLE_T
name|dispman_element
init|=
name|vc_dispmanx_element_add
argument_list|(
name|dispman_update
argument_list|,
name|dispman_display
argument_list|,
name|z
argument_list|,
operator|&
name|dst_rect
argument_list|,
literal|0
argument_list|,
operator|&
name|src_rect
argument_list|,
name|DISPMANX_PROTECTION_NONE
argument_list|,
operator|&
name|alpha
argument_list|,
operator|(
name|DISPMANX_CLAMP_T
operator|*
operator|)
name|NULL
argument_list|,
operator|(
name|DISPMANX_TRANSFORM_T
operator|)
literal|0
argument_list|)
decl_stmt|;
name|vc_dispmanx_update_submit_sync
argument_list|(
name|dispman_update
argument_list|)
expr_stmt|;
name|EGL_DISPMANX_WINDOW_T
modifier|*
name|eglWindow
init|=
operator|new
name|EGL_DISPMANX_WINDOW_T
decl_stmt|;
name|eglWindow
operator|->
name|element
operator|=
name|dispman_element
expr_stmt|;
name|eglWindow
operator|->
name|width
operator|=
name|size
operator|.
name|width
argument_list|()
expr_stmt|;
name|eglWindow
operator|->
name|height
operator|=
name|size
operator|.
name|height
argument_list|()
expr_stmt|;
return|return
name|eglWindow
return|;
block|}
end_function
begin_comment
comment|// these constants are not in any headers (yet)
end_comment
begin_define
DECL|macro|ELEMENT_CHANGE_LAYER
define|#
directive|define
name|ELEMENT_CHANGE_LAYER
value|(1<<0)
end_define
begin_define
DECL|macro|ELEMENT_CHANGE_OPACITY
define|#
directive|define
name|ELEMENT_CHANGE_OPACITY
value|(1<<1)
end_define
begin_define
DECL|macro|ELEMENT_CHANGE_DEST_RECT
define|#
directive|define
name|ELEMENT_CHANGE_DEST_RECT
value|(1<<2)
end_define
begin_define
DECL|macro|ELEMENT_CHANGE_SRC_RECT
define|#
directive|define
name|ELEMENT_CHANGE_SRC_RECT
value|(1<<3)
end_define
begin_define
DECL|macro|ELEMENT_CHANGE_MASK_RESOURCE
define|#
directive|define
name|ELEMENT_CHANGE_MASK_RESOURCE
value|(1<<4)
end_define
begin_define
DECL|macro|ELEMENT_CHANGE_TRANSFORM
define|#
directive|define
name|ELEMENT_CHANGE_TRANSFORM
value|(1<<5)
end_define
begin_function
DECL|function|moveDispmanxLayer
specifier|static
name|void
name|moveDispmanxLayer
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
name|EGL_DISPMANX_WINDOW_T
modifier|*
name|eglWindow
init|=
cast|static_cast
argument_list|<
name|EGL_DISPMANX_WINDOW_T
operator|*
argument_list|>
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|QSize
name|size
argument_list|(
name|eglWindow
operator|->
name|width
argument_list|,
name|eglWindow
operator|->
name|height
argument_list|)
decl_stmt|;
name|VC_RECT_T
name|dst_rect
decl_stmt|;
name|dst_rect
operator|.
name|x
operator|=
name|pos
operator|.
name|x
argument_list|()
expr_stmt|;
name|dst_rect
operator|.
name|y
operator|=
name|pos
operator|.
name|y
argument_list|()
expr_stmt|;
name|dst_rect
operator|.
name|width
operator|=
name|size
operator|.
name|width
argument_list|()
expr_stmt|;
name|dst_rect
operator|.
name|height
operator|=
name|size
operator|.
name|height
argument_list|()
expr_stmt|;
name|VC_RECT_T
name|src_rect
decl_stmt|;
name|src_rect
operator|.
name|x
operator|=
literal|0
expr_stmt|;
name|src_rect
operator|.
name|y
operator|=
literal|0
expr_stmt|;
name|src_rect
operator|.
name|width
operator|=
name|size
operator|.
name|width
argument_list|()
operator|<<
literal|16
expr_stmt|;
name|src_rect
operator|.
name|height
operator|=
name|size
operator|.
name|height
argument_list|()
operator|<<
literal|16
expr_stmt|;
name|DISPMANX_UPDATE_HANDLE_T
name|dispman_update
init|=
name|vc_dispmanx_update_start
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|vc_dispmanx_element_change_attributes
argument_list|(
name|dispman_update
argument_list|,
name|eglWindow
operator|->
name|element
argument_list|,
name|ELEMENT_CHANGE_DEST_RECT
comment|/*change_flags*/
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|dst_rect
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
operator|(
name|DISPMANX_TRANSFORM_T
operator|)
literal|0
argument_list|)
expr_stmt|;
name|vc_dispmanx_update_submit_sync
argument_list|(
name|dispman_update
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|destroyDispmanxLayer
specifier|static
name|void
name|destroyDispmanxLayer
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
block|{
name|EGL_DISPMANX_WINDOW_T
modifier|*
name|eglWindow
init|=
cast|static_cast
argument_list|<
name|EGL_DISPMANX_WINDOW_T
operator|*
argument_list|>
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|DISPMANX_UPDATE_HANDLE_T
name|dispman_update
init|=
name|vc_dispmanx_update_start
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|vc_dispmanx_element_remove
argument_list|(
name|dispman_update
argument_list|,
name|eglWindow
operator|->
name|element
argument_list|)
expr_stmt|;
name|vc_dispmanx_update_submit_sync
argument_list|(
name|dispman_update
argument_list|)
expr_stmt|;
operator|delete
name|eglWindow
expr_stmt|;
block|}
end_function
begin_class
DECL|class|QEglFSPiHooks
class|class
name|QEglFSPiHooks
super|:
specifier|public
name|QEglFSHooks
block|{
public|public:
specifier|virtual
name|void
name|platformInit
parameter_list|()
function_decl|;
specifier|virtual
name|void
name|platformDestroy
parameter_list|()
function_decl|;
specifier|virtual
name|EGLNativeDisplayType
name|platformDisplay
parameter_list|()
specifier|const
function_decl|;
specifier|virtual
name|QSize
name|screenSize
parameter_list|()
specifier|const
function_decl|;
specifier|virtual
name|EGLNativeWindowType
name|createNativeWindow
parameter_list|(
name|QPlatformWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
function_decl|;
specifier|virtual
name|void
name|destroyNativeWindow
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
function_decl|;
specifier|virtual
name|bool
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|platformInit
name|void
name|QEglFSPiHooks
operator|::
name|platformInit
parameter_list|()
block|{
name|bcm_host_init
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformDisplay
name|EGLNativeDisplayType
name|QEglFSPiHooks
operator|::
name|platformDisplay
parameter_list|()
specifier|const
block|{
name|dispman_display
operator|=
name|vc_dispmanx_display_open
argument_list|(
literal|0
comment|/* LCD */
argument_list|)
expr_stmt|;
return|return
name|EGL_DEFAULT_DISPLAY
return|;
block|}
end_function
begin_function
DECL|function|platformDestroy
name|void
name|QEglFSPiHooks
operator|::
name|platformDestroy
parameter_list|()
block|{
name|vc_dispmanx_display_close
argument_list|(
name|dispman_display
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|screenSize
name|QSize
name|QEglFSPiHooks
operator|::
name|screenSize
parameter_list|()
specifier|const
block|{
name|uint32_t
name|width
decl_stmt|,
name|height
decl_stmt|;
name|graphics_get_display_size
argument_list|(
literal|0
comment|/* LCD */
argument_list|,
operator|&
name|width
argument_list|,
operator|&
name|height
argument_list|)
expr_stmt|;
return|return
name|QSize
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createNativeWindow
name|EGLNativeWindowType
name|QEglFSPiHooks
operator|::
name|createNativeWindow
parameter_list|(
name|QPlatformWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|window
argument_list|)
return|return
name|createDispmanxLayer
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|size
argument_list|,
literal|1
argument_list|,
name|format
operator|.
name|hasAlpha
argument_list|()
condition|?
name|DISPMANX_FLAGS_ALPHA_FROM_SOURCE
else|:
name|DISPMANX_FLAGS_ALPHA_FIXED_ALL_PIXELS
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|destroyNativeWindow
name|void
name|QEglFSPiHooks
operator|::
name|destroyNativeWindow
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
block|{
name|destroyDispmanxLayer
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasCapability
name|bool
name|QEglFSPiHooks
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|cap
condition|)
block|{
case|case
name|QPlatformIntegration
operator|::
name|ThreadedPixmaps
case|:
case|case
name|QPlatformIntegration
operator|::
name|OpenGL
case|:
case|case
name|QPlatformIntegration
operator|::
name|ThreadedOpenGL
case|:
case|case
name|QPlatformIntegration
operator|::
name|BufferQueueingOpenGL
case|:
return|return
literal|true
return|;
default|default:
return|return
literal|false
return|;
block|}
block|}
end_function
begin_decl_stmt
DECL|variable|eglFSPiHooks
name|QEglFSPiHooks
name|eglFSPiHooks
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|platformHooks
name|QEglFSHooks
modifier|*
name|platformHooks
init|=
operator|&
name|eglFSPiHooks
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
