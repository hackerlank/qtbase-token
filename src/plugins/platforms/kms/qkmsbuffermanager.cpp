begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qkmsbuffermanager.h"
end_include
begin_include
include|#
directive|include
file|"qkmsscreen.h"
end_include
begin_include
include|#
directive|include
file|"qkmscontext.h"
end_include
begin_include
include|#
directive|include
file|"qkmsdevice.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QKmsBufferManager
name|QKmsBufferManager
operator|::
name|QKmsBufferManager
parameter_list|(
name|QKmsScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|m_screen
argument_list|(
name|screen
argument_list|)
member_init_list|,
name|m_frameBufferObject
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_renderTarget
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_displayCanidate
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_currentDisplay
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QKmsBufferManager
name|QKmsBufferManager
operator|::
name|~
name|QKmsBufferManager
parameter_list|()
block|{
name|clearBuffers
argument_list|()
expr_stmt|;
name|glDeleteFramebuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|m_frameBufferObject
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setupBuffersForMode
name|void
name|QKmsBufferManager
operator|::
name|setupBuffersForMode
parameter_list|(
specifier|const
name|drmModeModeInfo
modifier|&
name|mode
parameter_list|,
name|int
name|numBuffers
parameter_list|)
block|{
name|eglMakeCurrent
argument_list|(
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|eglContext
argument_list|()
argument_list|)
expr_stmt|;
name|m_screen
operator|->
name|bindFramebuffer
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_frameBufferObject
condition|)
block|{
name|clearBuffers
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|//Setup Framebuffer Object
name|glGenFramebuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|m_frameBufferObject
argument_list|)
expr_stmt|;
name|glBindFramebuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|m_frameBufferObject
argument_list|)
expr_stmt|;
block|}
comment|//Setup shared Depth/Stencil buffer
name|glGenRenderbuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|m_depthAndStencilBufferObject
argument_list|)
expr_stmt|;
name|glBindRenderbuffer
argument_list|(
name|GL_RENDERBUFFER
argument_list|,
name|m_depthAndStencilBufferObject
argument_list|)
expr_stmt|;
name|glRenderbufferStorage
argument_list|(
name|GL_RENDERBUFFER
argument_list|,
name|GL_DEPTH24_STENCIL8_OES
argument_list|,
name|mode
operator|.
name|hdisplay
argument_list|,
name|mode
operator|.
name|vdisplay
argument_list|)
expr_stmt|;
comment|//Setup "numBuffer" many rendering targets
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|numBuffers
condition|;
name|i
operator|++
control|)
block|{
name|QKmsFramebuffer
modifier|*
name|buffer
init|=
operator|new
name|QKmsFramebuffer
argument_list|()
decl_stmt|;
name|glGenRenderbuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|buffer
operator|->
name|renderBuffer
argument_list|)
expr_stmt|;
name|glBindRenderbuffer
argument_list|(
name|GL_RENDERBUFFER
argument_list|,
name|buffer
operator|->
name|renderBuffer
argument_list|)
expr_stmt|;
name|buffer
operator|->
name|graphicsBufferObject
operator|=
name|gbm_bo_create
argument_list|(
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|gbmDevice
argument_list|()
argument_list|,
name|mode
operator|.
name|hdisplay
argument_list|,
name|mode
operator|.
name|vdisplay
argument_list|,
name|GBM_BO_FORMAT_XRGB8888
argument_list|,
name|GBM_BO_USE_SCANOUT
operator||
name|GBM_BO_USE_RENDERING
argument_list|)
expr_stmt|;
name|buffer
operator|->
name|eglImage
operator|=
name|eglCreateImageKHR
argument_list|(
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|eglDisplay
argument_list|()
argument_list|,
literal|0
argument_list|,
name|EGL_NATIVE_PIXMAP_KHR
argument_list|,
name|buffer
operator|->
name|graphicsBufferObject
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|glEGLImageTargetRenderbufferStorageOES
argument_list|(
name|GL_RENDERBUFFER
argument_list|,
name|buffer
operator|->
name|eglImage
argument_list|)
expr_stmt|;
name|quint32
name|stride
init|=
name|gbm_bo_get_pitch
argument_list|(
name|buffer
operator|->
name|graphicsBufferObject
argument_list|)
decl_stmt|;
name|quint32
name|handle
init|=
name|gbm_bo_get_handle
argument_list|(
name|buffer
operator|->
name|graphicsBufferObject
argument_list|)
operator|.
name|u32
decl_stmt|;
name|int
name|status
init|=
name|drmModeAddFB
argument_list|(
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|mode
operator|.
name|hdisplay
argument_list|,
name|mode
operator|.
name|vdisplay
argument_list|,
literal|32
argument_list|,
literal|32
argument_list|,
name|stride
argument_list|,
name|handle
argument_list|,
operator|&
name|buffer
operator|->
name|framebufferId
argument_list|)
decl_stmt|;
comment|//Todo: IF this returns true, then this is one less buffer that we use
comment|//Not so fatal, but not handled at the moment.
if|if
condition|(
name|status
condition|)
name|qFatal
argument_list|(
literal|"failed to add framebuffer"
argument_list|)
expr_stmt|;
name|m_framebuffers
operator|.
name|append
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
block|}
comment|//Attach the Depth and Stencil buffer
name|glFramebufferRenderbuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|GL_DEPTH_ATTACHMENT
argument_list|,
name|GL_RENDERBUFFER
argument_list|,
name|m_depthAndStencilBufferObject
argument_list|)
expr_stmt|;
name|glFramebufferRenderbuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|GL_STENCIL_ATTACHMENT
argument_list|,
name|GL_RENDERBUFFER
argument_list|,
name|m_depthAndStencilBufferObject
argument_list|)
expr_stmt|;
comment|//Attach  renderbuffer as Color Attachment.
name|glFramebufferRenderbuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|GL_COLOR_ATTACHMENT0
argument_list|,
name|GL_RENDERBUFFER
argument_list|,
name|this
operator|->
name|renderTargetBuffer
argument_list|()
argument_list|)
expr_stmt|;
name|eglMakeCurrent
argument_list|(
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|eglDisplay
argument_list|()
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
DECL|function|clearBuffers
name|void
name|QKmsBufferManager
operator|::
name|clearBuffers
parameter_list|()
block|{
comment|//Make sure that the FBO is binded
name|glBindFramebuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|m_frameBufferObject
argument_list|)
expr_stmt|;
comment|//Detach the Color/Depth/Stencil Attachments.
name|glFramebufferRenderbuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|GL_COLOR_ATTACHMENT0
argument_list|,
name|GL_RENDERBUFFER
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|glFramebufferRenderbuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|GL_DEPTH_ATTACHMENT
argument_list|,
name|GL_RENDERBUFFER
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|glFramebufferRenderbuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|GL_STENCIL_ATTACHMENT
argument_list|,
name|GL_RENDERBUFFER
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|glBindRenderbuffer
argument_list|(
name|GL_RENDERBUFFER
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|//Delete the shared Depth/Stencil buffer
name|glDeleteRenderbuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|m_depthAndStencilBufferObject
argument_list|)
expr_stmt|;
comment|//Delete each renderbuffer object
comment|//Delete each EGLImage
comment|//Remove each drm Framebuffer
foreach|foreach
control|(
name|QKmsFramebuffer
modifier|*
name|buffer
decl|,
name|m_framebuffers
control|)
block|{
name|glDeleteRenderbuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|buffer
operator|->
name|renderBuffer
argument_list|)
expr_stmt|;
name|eglDestroyImageKHR
argument_list|(
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|buffer
operator|->
name|eglImage
argument_list|)
expr_stmt|;
name|drmModeRmFB
argument_list|(
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|buffer
operator|->
name|framebufferId
argument_list|)
expr_stmt|;
operator|delete
name|buffer
expr_stmt|;
block|}
name|m_framebuffers
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|renderTargetBuffer
name|GLuint
name|QKmsBufferManager
operator|::
name|renderTargetBuffer
parameter_list|()
block|{
comment|//TODO: Handle more senarios than assuming at least 2 buffers
if|if
condition|(
operator|!
name|m_renderTarget
condition|)
block|{
name|m_renderTarget
operator|=
name|m_framebuffers
operator|.
name|at
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
name|m_renderTarget
operator|->
name|renderBuffer
return|;
block|}
end_function
begin_function
DECL|function|displayFramebufferId
name|quint32
name|QKmsBufferManager
operator|::
name|displayFramebufferId
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_currentDisplay
condition|)
block|{
name|m_currentDisplay
operator|=
name|m_framebuffers
operator|.
name|at
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|m_currentDisplay
operator|->
name|available
operator|=
literal|false
expr_stmt|;
return|return
name|m_currentDisplay
operator|->
name|framebufferId
return|;
block|}
if|if
condition|(
operator|!
name|m_displayCanidate
condition|)
return|return
name|m_currentDisplay
operator|->
name|framebufferId
return|;
name|m_currentDisplay
operator|->
name|available
operator|=
literal|true
expr_stmt|;
name|m_displayCanidate
operator|->
name|available
operator|=
literal|false
expr_stmt|;
name|m_currentDisplay
operator|=
name|m_displayCanidate
expr_stmt|;
return|return
name|m_currentDisplay
operator|->
name|framebufferId
return|;
block|}
end_function
begin_function
DECL|function|nextBuffer
name|bool
name|QKmsBufferManager
operator|::
name|nextBuffer
parameter_list|()
block|{
name|m_displayCanidate
operator|=
name|m_renderTarget
expr_stmt|;
foreach|foreach
control|(
name|QKmsFramebuffer
modifier|*
name|buffer
decl|,
name|m_framebuffers
control|)
block|{
if|if
condition|(
name|buffer
operator|->
name|available
operator|&&
name|buffer
operator|!=
name|m_displayCanidate
condition|)
block|{
name|m_renderTarget
operator|=
name|buffer
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
end_unit
