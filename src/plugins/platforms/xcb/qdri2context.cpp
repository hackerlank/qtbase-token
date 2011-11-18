begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdri2context.h"
end_include
begin_include
include|#
directive|include
file|"qxcbwindow.h"
end_include
begin_include
include|#
directive|include
file|"qxcbconnection.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_include
include|#
directive|include
file|<xcb/dri2.h>
end_include
begin_include
include|#
directive|include
file|<xcb/xfixes.h>
end_include
begin_define
DECL|macro|MESA_EGL_NO_X11_HEADERS
define|#
directive|define
name|MESA_EGL_NO_X11_HEADERS
end_define
begin_define
DECL|macro|EGL_EGLEXT_PROTOTYPES
define|#
directive|define
name|EGL_EGLEXT_PROTOTYPES
end_define
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_include
include|#
directive|include
file|<EGL/eglext.h>
end_include
begin_define
DECL|macro|GL_GLEXT_PROTOTYPES
define|#
directive|define
name|GL_GLEXT_PROTOTYPES
end_define
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_include
include|#
directive|include
file|<GLES2/gl2ext.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QDri2ContextPrivate
class|class
name|QDri2ContextPrivate
block|{
public|public:
DECL|function|QDri2ContextPrivate
name|QDri2ContextPrivate
parameter_list|(
name|QXcbWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|qXcbWindow
argument_list|(
name|window
argument_list|)
member_init_list|,
name|windowFormat
argument_list|(
name|window
operator|->
name|widget
argument_list|()
operator|->
name|platformWindowFormat
argument_list|()
argument_list|)
member_init_list|,
name|image
argument_list|(
literal|0
argument_list|)
block|{     }
DECL|function|xcbWindow
name|xcb_window_t
name|xcbWindow
parameter_list|()
block|{
return|return
name|qXcbWindow
operator|->
name|window
argument_list|()
return|;
block|}
DECL|function|xcbConnection
name|xcb_connection_t
modifier|*
name|xcbConnection
parameter_list|()
block|{
return|return
name|qXcbWindow
operator|->
name|xcb_connection
argument_list|()
return|;
block|}
DECL|member|qXcbWindow
name|QXcbWindow
modifier|*
name|qXcbWindow
decl_stmt|;
DECL|member|windowFormat
name|QPlatformWindowFormat
name|windowFormat
decl_stmt|;
DECL|member|eglContext
name|EGLContext
name|eglContext
decl_stmt|;
DECL|member|image
name|EGLImageKHR
name|image
decl_stmt|;
DECL|member|fbo
name|GLuint
name|fbo
decl_stmt|;
DECL|member|rbo
name|GLuint
name|rbo
decl_stmt|;
DECL|member|depth
name|GLuint
name|depth
decl_stmt|;
DECL|member|size
name|QSize
name|size
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QDri2Context
name|QDri2Context
operator|::
name|QDri2Context
parameter_list|(
name|QXcbWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QDri2ContextPrivate
argument_list|(
name|window
argument_list|)
argument_list|)
block|{
name|Q_D
argument_list|(
name|QDri2Context
argument_list|)
expr_stmt|;
specifier|static
specifier|const
name|EGLint
name|contextAttribs
index|[]
init|=
block|{
name|EGL_CONTEXT_CLIENT_VERSION
block|,
literal|2
block|,
name|EGL_NONE
block|}
decl_stmt|;
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
expr_stmt|;
name|EGLContext
name|shareContext
init|=
name|EGL_NO_CONTEXT
decl_stmt|;
if|if
condition|(
name|window
operator|->
name|widget
argument_list|()
operator|->
name|platformWindowFormat
argument_list|()
operator|.
name|sharedGLContext
argument_list|()
condition|)
block|{
name|QDri2Context
modifier|*
name|context
init|=
cast|static_cast
argument_list|<
name|QDri2Context
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|widget
argument_list|()
operator|->
name|platformWindowFormat
argument_list|()
operator|.
name|sharedGLContext
argument_list|()
argument_list|)
decl_stmt|;
name|shareContext
operator|=
name|context
operator|->
name|d_func
argument_list|()
operator|->
name|eglContext
expr_stmt|;
block|}
name|d
operator|->
name|eglContext
operator|=
name|eglCreateContext
argument_list|(
name|EGL_DISPLAY_FROM_XCB
argument_list|(
name|d
operator|->
name|qXcbWindow
argument_list|)
argument_list|,
name|NULL
argument_list|,
name|shareContext
argument_list|,
name|contextAttribs
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|eglContext
operator|==
name|EGL_NO_CONTEXT
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"No eglContext!"
operator|<<
name|eglGetError
argument_list|()
expr_stmt|;
block|}
name|EGLBoolean
name|makeCurrentSuccess
init|=
name|eglMakeCurrent
argument_list|(
name|EGL_DISPLAY_FROM_XCB
argument_list|(
name|d
operator|->
name|qXcbWindow
argument_list|)
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|d
operator|->
name|eglContext
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|makeCurrentSuccess
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"eglMakeCurrent failed!"
operator|<<
name|eglGetError
argument_list|()
expr_stmt|;
block|}
name|xcb_dri2_create_drawable
argument_list|(
name|d
operator|->
name|xcbConnection
argument_list|()
argument_list|,
name|d
operator|->
name|xcbWindow
argument_list|()
argument_list|)
expr_stmt|;
name|glGenFramebuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|d
operator|->
name|fbo
argument_list|)
expr_stmt|;
name|glBindFramebuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|d
operator|->
name|fbo
argument_list|)
expr_stmt|;
name|glActiveTexture
argument_list|(
name|GL_TEXTURE0
argument_list|)
expr_stmt|;
name|glGenRenderbuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|d
operator|->
name|rbo
argument_list|)
expr_stmt|;
name|glBindRenderbuffer
argument_list|(
name|GL_RENDERBUFFER
argument_list|,
name|d
operator|->
name|rbo
argument_list|)
expr_stmt|;
name|glGenRenderbuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|d
operator|->
name|depth
argument_list|)
expr_stmt|;
name|glBindRenderbuffer
argument_list|(
name|GL_RENDERBUFFER
argument_list|,
name|d
operator|->
name|depth
argument_list|)
expr_stmt|;
name|resize
argument_list|(
name|d
operator|->
name|qXcbWindow
operator|->
name|widget
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|glFramebufferRenderbuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|GL_COLOR_ATTACHMENT0
argument_list|,
name|GL_RENDERBUFFER
argument_list|,
name|d
operator|->
name|rbo
argument_list|)
expr_stmt|;
name|glFramebufferRenderbuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|GL_DEPTH_ATTACHMENT
argument_list|,
name|GL_RENDERER
argument_list|,
name|d
operator|->
name|depth
argument_list|)
expr_stmt|;
name|glFramebufferRenderbuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|GL_STENCIL_ATTACHMENT
argument_list|,
name|GL_RENDERER
argument_list|,
name|d
operator|->
name|depth
argument_list|)
expr_stmt|;
comment|//restore the old current context
specifier|const
name|QPlatformOpenGLContext
modifier|*
name|currentContext
init|=
name|QPlatformOpenGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|currentContext
condition|)
cast|const_cast
argument_list|<
name|QPlatformOpenGLContext
operator|*
argument_list|>
argument_list|(
name|currentContext
argument_list|)
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QDri2Context
name|QDri2Context
operator|::
name|~
name|QDri2Context
parameter_list|()
block|{
comment|//cleanup
block|}
end_destructor
begin_function
DECL|function|makeCurrent
name|void
name|QDri2Context
operator|::
name|makeCurrent
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QDri2Context
argument_list|)
expr_stmt|;
name|eglMakeCurrent
argument_list|(
name|EGL_DISPLAY_FROM_XCB
argument_list|(
name|d
operator|->
name|qXcbWindow
argument_list|)
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|d
operator|->
name|eglContext
argument_list|)
expr_stmt|;
name|glBindFramebuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|d
operator|->
name|fbo
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|doneCurrent
name|void
name|QDri2Context
operator|::
name|doneCurrent
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QDri2Context
argument_list|)
expr_stmt|;
name|eglMakeCurrent
argument_list|(
name|EGL_DISPLAY_FROM_XCB
argument_list|(
name|d
operator|->
name|qXcbWindow
argument_list|)
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_CONTEXT
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QDri2Context
operator|::
name|swapBuffers
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QDri2Context
argument_list|)
expr_stmt|;
name|xcb_rectangle_t
name|rectangle
decl_stmt|;
name|rectangle
operator|.
name|x
operator|=
literal|0
expr_stmt|;
name|rectangle
operator|.
name|y
operator|=
literal|0
expr_stmt|;
name|rectangle
operator|.
name|width
operator|=
name|d
operator|->
name|qXcbWindow
operator|->
name|widget
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
expr_stmt|;
name|rectangle
operator|.
name|height
operator|=
name|d
operator|->
name|qXcbWindow
operator|->
name|widget
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
expr_stmt|;
name|xcb_xfixes_region_t
name|xfixesRegion
init|=
name|xcb_generate_id
argument_list|(
name|d
operator|->
name|xcbConnection
argument_list|()
argument_list|)
decl_stmt|;
name|xcb_xfixes_create_region
argument_list|(
name|d
operator|->
name|xcbConnection
argument_list|()
argument_list|,
name|xfixesRegion
argument_list|,
literal|1
argument_list|,
operator|&
name|rectangle
argument_list|)
expr_stmt|;
name|xcb_dri2_copy_region_cookie_t
name|cookie
init|=
name|xcb_dri2_copy_region_unchecked
argument_list|(
name|d
operator|->
name|xcbConnection
argument_list|()
argument_list|,
name|d
operator|->
name|qXcbWindow
operator|->
name|window
argument_list|()
argument_list|,
name|xfixesRegion
argument_list|,
name|XCB_DRI2_ATTACHMENT_BUFFER_FRONT_LEFT
argument_list|,
name|XCB_DRI2_ATTACHMENT_BUFFER_BACK_LEFT
argument_list|)
decl_stmt|;
name|xcb_dri2_copy_region_reply_t
modifier|*
name|reply
init|=
name|xcb_dri2_copy_region_reply
argument_list|(
name|d
operator|->
name|xcbConnection
argument_list|()
argument_list|,
name|cookie
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
comment|//cleanup
operator|delete
name|reply
expr_stmt|;
name|xcb_xfixes_destroy_region
argument_list|(
name|d
operator|->
name|xcbConnection
argument_list|()
argument_list|,
name|xfixesRegion
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getProcAddress
name|void
modifier|*
name|QDri2Context
operator|::
name|getProcAddress
parameter_list|(
specifier|const
name|QString
modifier|&
name|procName
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
name|eglGetProcAddress
argument_list|(
name|qPrintable
argument_list|(
name|procName
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QDri2Context
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDri2Context
argument_list|)
expr_stmt|;
name|d
operator|->
name|size
operator|=
name|size
expr_stmt|;
name|glBindFramebuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|d
operator|->
name|fbo
argument_list|)
expr_stmt|;
name|xcb_dri2_dri2_buffer_t
modifier|*
name|backBfr
init|=
name|backBuffer
argument_list|()
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|image
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"destroing image"
expr_stmt|;
name|eglDestroyImageKHR
argument_list|(
name|EGL_DISPLAY_FROM_XCB
argument_list|(
name|d
operator|->
name|qXcbWindow
argument_list|)
argument_list|,
name|d
operator|->
name|image
argument_list|)
expr_stmt|;
block|}
name|EGLint
name|imgAttribs
index|[]
init|=
block|{
name|EGL_WIDTH
block|,
name|d
operator|->
name|size
operator|.
name|width
argument_list|()
block|,
name|EGL_HEIGHT
block|,
name|d
operator|->
name|size
operator|.
name|height
argument_list|()
block|,
name|EGL_DRM_BUFFER_STRIDE_MESA
block|,
name|backBfr
operator|->
name|pitch
operator|/
literal|4
block|,
name|EGL_DRM_BUFFER_FORMAT_MESA
block|,
name|EGL_DRM_BUFFER_FORMAT_ARGB32_MESA
block|,
name|EGL_NONE
block|}
decl_stmt|;
name|d
operator|->
name|image
operator|=
name|eglCreateImageKHR
argument_list|(
name|EGL_DISPLAY_FROM_XCB
argument_list|(
name|d
operator|->
name|qXcbWindow
argument_list|)
argument_list|,
name|EGL_NO_CONTEXT
argument_list|,
name|EGL_DRM_BUFFER_MESA
argument_list|,
operator|(
name|EGLClientBuffer
operator|)
name|backBfr
operator|->
name|name
argument_list|,
name|imgAttribs
argument_list|)
expr_stmt|;
name|glBindRenderbuffer
argument_list|(
name|GL_RENDERBUFFER
argument_list|,
name|d
operator|->
name|rbo
argument_list|)
expr_stmt|;
name|glEGLImageTargetRenderbufferStorageOES
argument_list|(
name|GL_RENDERBUFFER
argument_list|,
name|d
operator|->
name|image
argument_list|)
expr_stmt|;
name|glBindRenderbuffer
argument_list|(
name|GL_RENDERBUFFER
argument_list|,
name|d
operator|->
name|depth
argument_list|)
expr_stmt|;
name|glRenderbufferStorage
argument_list|(
name|GL_RENDERBUFFER
argument_list|,
name|GL_DEPTH24_STENCIL8_OES
argument_list|,
name|d
operator|->
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|d
operator|->
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformWindowFormat
name|QPlatformWindowFormat
name|QDri2Context
operator|::
name|platformWindowFormat
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QDri2Context
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|windowFormat
return|;
block|}
end_function
begin_function
DECL|function|backBuffer
name|xcb_dri2_dri2_buffer_t
modifier|*
name|QDri2Context
operator|::
name|backBuffer
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QDri2Context
argument_list|)
expr_stmt|;
name|unsigned
name|int
name|backBufferAttachment
init|=
name|XCB_DRI2_ATTACHMENT_BUFFER_BACK_LEFT
decl_stmt|;
name|xcb_dri2_get_buffers_cookie_t
name|cookie
init|=
name|xcb_dri2_get_buffers_unchecked
argument_list|(
name|d
operator|->
name|xcbConnection
argument_list|()
argument_list|,
name|d
operator|->
name|xcbWindow
argument_list|()
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
operator|&
name|backBufferAttachment
argument_list|)
decl_stmt|;
name|xcb_dri2_get_buffers_reply_t
modifier|*
name|reply
init|=
name|xcb_dri2_get_buffers_reply
argument_list|(
name|d
operator|->
name|xcbConnection
argument_list|()
argument_list|,
name|cookie
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|reply
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"failed to get buffers reply"
expr_stmt|;
return|return
literal|0
return|;
block|}
name|xcb_dri2_dri2_buffer_t
modifier|*
name|buffers
init|=
name|xcb_dri2_get_buffers_buffers
argument_list|(
name|reply
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|buffers
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"failed to get buffers"
expr_stmt|;
return|return
literal|0
return|;
block|}
name|Q_ASSERT
argument_list|(
name|reply
operator|->
name|count
operator|==
literal|1
argument_list|)
expr_stmt|;
operator|delete
name|reply
expr_stmt|;
return|return
name|buffers
return|;
block|}
end_function
begin_function
DECL|function|eglContext
name|void
modifier|*
name|QDri2Context
operator|::
name|eglContext
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QDri2Context
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|eglContext
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
