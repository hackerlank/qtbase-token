begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdirectfb_egl.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbwindow.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbscreen.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbeglhooks.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformopenglcontext.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglplatformcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglconvenience_p.h>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|DIRECTFB_PLATFORM_HOOKS
specifier|extern
name|QDirectFBEGLHooks
name|platform_hook
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|hooks
specifier|static
name|QDirectFBEGLHooks
modifier|*
name|hooks
init|=
operator|&
name|platform_hook
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_decl_stmt
specifier|static
name|QDirectFBEGLHooks
modifier|*
name|hooks
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/**  * This provides OpenGL ES 2.0 integration with DirectFB. It assumes that  * one can adapt a DirectFBSurface as a EGLSurface. It might need some vendor  * init code in the QDirectFbScreenEGL class to initialize EGL and one might  * need to provide a custom QDirectFbWindowEGL::format() to return the  * QSurfaceFormat used by the device.  */
end_comment
begin_class
DECL|class|QDirectFbScreenEGL
class|class
name|QDirectFbScreenEGL
super|:
specifier|public
name|QDirectFbScreen
block|{
public|public:
name|QDirectFbScreenEGL
parameter_list|(
name|int
name|display
parameter_list|)
constructor_decl|;
name|~
name|QDirectFbScreenEGL
parameter_list|()
destructor_decl|;
comment|// EGL helper
name|EGLDisplay
name|eglDisplay
parameter_list|()
function_decl|;
private|private:
name|void
name|initializeEGL
parameter_list|()
function_decl|;
name|void
name|platformInit
parameter_list|()
function_decl|;
name|void
name|platformDestroy
parameter_list|()
function_decl|;
private|private:
DECL|member|m_eglDisplay
name|EGLDisplay
name|m_eglDisplay
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|QDirectFbWindowEGL
class|class
name|QDirectFbWindowEGL
super|:
specifier|public
name|QDirectFbWindow
block|{
public|public:
name|QDirectFbWindowEGL
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|,
name|QDirectFbInput
modifier|*
name|inputhandler
parameter_list|)
constructor_decl|;
name|~
name|QDirectFbWindowEGL
parameter_list|()
destructor_decl|;
comment|// EGL. Subclass it instead to have different GL integrations?
name|EGLSurface
name|eglSurface
parameter_list|()
function_decl|;
name|QSurfaceFormat
name|format
parameter_list|()
specifier|const
function_decl|;
private|private:
DECL|member|m_eglSurface
name|EGLSurface
name|m_eglSurface
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|QDirectFbEGLContext
class|class
name|QDirectFbEGLContext
super|:
specifier|public
name|QEGLPlatformContext
block|{
public|public:
name|QDirectFbEGLContext
parameter_list|(
name|QDirectFbScreenEGL
modifier|*
name|screen
parameter_list|,
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
constructor_decl|;
protected|protected:
name|EGLSurface
name|eglSurfaceForPlatformSurface
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
function_decl|;
private|private:
DECL|member|m_screen
name|QDirectFbScreen
modifier|*
name|m_screen
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QDirectFbScreenEGL
name|QDirectFbScreenEGL
operator|::
name|QDirectFbScreenEGL
parameter_list|(
name|int
name|display
parameter_list|)
member_init_list|:
name|QDirectFbScreen
argument_list|(
name|display
argument_list|)
member_init_list|,
name|m_eglDisplay
argument_list|(
name|EGL_NO_DISPLAY
argument_list|)
block|{}
end_constructor
begin_destructor
DECL|function|~QDirectFbScreenEGL
name|QDirectFbScreenEGL
operator|::
name|~
name|QDirectFbScreenEGL
parameter_list|()
block|{
name|platformDestroy
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|eglDisplay
name|EGLDisplay
name|QDirectFbScreenEGL
operator|::
name|eglDisplay
parameter_list|()
block|{
if|if
condition|(
name|m_eglDisplay
operator|==
name|EGL_NO_DISPLAY
condition|)
name|initializeEGL
argument_list|()
expr_stmt|;
return|return
name|m_eglDisplay
return|;
block|}
end_function
begin_function
DECL|function|initializeEGL
name|void
name|QDirectFbScreenEGL
operator|::
name|initializeEGL
parameter_list|()
block|{
name|m_eglDisplay
operator|=
name|eglGetDisplay
argument_list|(
name|EGL_DEFAULT_DISPLAY
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_eglDisplay
operator|==
name|EGL_NO_DISPLAY
condition|)
return|return;
name|platformInit
argument_list|()
expr_stmt|;
name|EGLint
name|major
decl_stmt|,
name|minor
decl_stmt|;
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
expr_stmt|;
name|eglInitialize
argument_list|(
name|m_eglDisplay
argument_list|,
operator|&
name|major
argument_list|,
operator|&
name|minor
argument_list|)
expr_stmt|;
return|return;
block|}
end_function
begin_function
DECL|function|platformInit
name|void
name|QDirectFbScreenEGL
operator|::
name|platformInit
parameter_list|()
block|{
if|if
condition|(
name|hooks
condition|)
name|hooks
operator|->
name|platformInit
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformDestroy
name|void
name|QDirectFbScreenEGL
operator|::
name|platformDestroy
parameter_list|()
block|{
if|if
condition|(
name|hooks
condition|)
name|hooks
operator|->
name|platformDestroy
argument_list|()
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QDirectFbWindowEGL
name|QDirectFbWindowEGL
operator|::
name|QDirectFbWindowEGL
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|,
name|QDirectFbInput
modifier|*
name|input
parameter_list|)
member_init_list|:
name|QDirectFbWindow
argument_list|(
name|tlw
argument_list|,
name|input
argument_list|)
member_init_list|,
name|m_eglSurface
argument_list|(
name|EGL_NO_SURFACE
argument_list|)
block|{}
end_constructor
begin_destructor
DECL|function|~QDirectFbWindowEGL
name|QDirectFbWindowEGL
operator|::
name|~
name|QDirectFbWindowEGL
parameter_list|()
block|{
if|if
condition|(
name|m_eglSurface
operator|!=
name|EGL_NO_SURFACE
condition|)
block|{
name|QDirectFbScreenEGL
modifier|*
name|dfbScreen
decl_stmt|;
name|dfbScreen
operator|=
cast|static_cast
argument_list|<
name|QDirectFbScreenEGL
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|()
argument_list|)
expr_stmt|;
name|eglDestroySurface
argument_list|(
name|dfbScreen
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|m_eglSurface
argument_list|)
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|eglSurface
name|EGLSurface
name|QDirectFbWindowEGL
operator|::
name|eglSurface
parameter_list|()
block|{
if|if
condition|(
name|m_eglSurface
operator|==
name|EGL_NO_SURFACE
condition|)
block|{
name|QDirectFbScreenEGL
modifier|*
name|dfbScreen
init|=
cast|static_cast
argument_list|<
name|QDirectFbScreenEGL
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|()
argument_list|)
decl_stmt|;
name|EGLConfig
name|config
init|=
name|q_configFromGLFormat
argument_list|(
name|dfbScreen
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|format
argument_list|()
argument_list|,
literal|true
argument_list|)
decl_stmt|;
name|m_eglSurface
operator|=
name|eglCreateWindowSurface
argument_list|(
name|dfbScreen
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|config
argument_list|,
name|dfbSurface
argument_list|()
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_eglSurface
operator|==
name|EGL_NO_SURFACE
condition|)
name|eglGetError
argument_list|()
expr_stmt|;
block|}
return|return
name|m_eglSurface
return|;
block|}
end_function
begin_function
DECL|function|format
name|QSurfaceFormat
name|QDirectFbWindowEGL
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|window
argument_list|()
operator|->
name|requestedFormat
argument_list|()
return|;
block|}
end_function
begin_constructor
DECL|function|QDirectFbEGLContext
name|QDirectFbEGLContext
operator|::
name|QDirectFbEGLContext
parameter_list|(
name|QDirectFbScreenEGL
modifier|*
name|screen
parameter_list|,
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
member_init_list|:
name|QEGLPlatformContext
argument_list|(
name|context
operator|->
name|format
argument_list|()
argument_list|,
name|context
operator|->
name|shareHandle
argument_list|()
argument_list|,
name|screen
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|EGL_OPENGL_ES_API
argument_list|)
member_init_list|,
name|m_screen
argument_list|(
name|screen
argument_list|)
block|{}
end_constructor
begin_function
DECL|function|eglSurfaceForPlatformSurface
name|EGLSurface
name|QDirectFbEGLContext
operator|::
name|eglSurfaceForPlatformSurface
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|QDirectFbWindowEGL
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QDirectFbWindowEGL
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
decl_stmt|;
return|return
name|window
operator|->
name|eglSurface
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QDirectFbIntegrationEGL
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QDirectFbWindowEGL
argument_list|(
name|window
argument_list|,
name|m_input
operator|.
name|data
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QDirectFbIntegrationEGL
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
name|QDirectFbScreenEGL
modifier|*
name|screen
decl_stmt|;
name|screen
operator|=
cast|static_cast
argument_list|<
name|QDirectFbScreenEGL
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|new
name|QDirectFbEGLContext
argument_list|(
name|screen
argument_list|,
name|context
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|initializeScreen
name|void
name|QDirectFbIntegrationEGL
operator|::
name|initializeScreen
parameter_list|()
block|{
name|m_primaryScreen
operator|.
name|reset
argument_list|(
operator|new
name|QDirectFbScreenEGL
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|screenAdded
argument_list|(
name|m_primaryScreen
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasCapability
name|bool
name|QDirectFbIntegrationEGL
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
comment|// We assume that devices will have more and not less capabilities
if|if
condition|(
name|hooks
operator|&&
name|hooks
operator|->
name|hasCapability
argument_list|(
name|cap
argument_list|)
condition|)
return|return
literal|true
return|;
return|return
name|QDirectFbIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
