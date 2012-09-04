begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QLibrary>
end_include
begin_include
include|#
directive|include
file|"qxcbwindow.h"
end_include
begin_include
include|#
directive|include
file|"qxcbscreen.h"
end_include
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_include
include|#
directive|include
file|<X11/Xutil.h>
end_include
begin_include
include|#
directive|include
file|<GL/glx.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|"qglxintegration.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qglxconvenience_p.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_BSD4
argument_list|)
end_if
begin_include
include|#
directive|include
file|<dlfcn.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|glXCreateContextAttribsARBProc
typedef|typedef
name|GLXContext
function_decl|(
modifier|*
name|glXCreateContextAttribsARBProc
function_decl|)
parameter_list|(
name|Display
modifier|*
parameter_list|,
name|GLXFBConfig
parameter_list|,
name|GLXContext
parameter_list|,
name|Bool
parameter_list|,
specifier|const
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_ifndef
ifndef|#
directive|ifndef
name|GLX_CONTEXT_CORE_PROFILE_BIT_ARB
end_ifndef
begin_define
DECL|macro|GLX_CONTEXT_CORE_PROFILE_BIT_ARB
define|#
directive|define
name|GLX_CONTEXT_CORE_PROFILE_BIT_ARB
value|0x00000001
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB
end_ifndef
begin_define
DECL|macro|GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB
define|#
directive|define
name|GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB
value|0x00000002
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GLX_CONTEXT_PROFILE_MASK_ARB
end_ifndef
begin_define
DECL|macro|GLX_CONTEXT_PROFILE_MASK_ARB
define|#
directive|define
name|GLX_CONTEXT_PROFILE_MASK_ARB
value|0x9126
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|QGLXContext
name|QGLXContext
operator|::
name|QGLXContext
parameter_list|(
name|QXcbScreen
modifier|*
name|screen
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|QPlatformOpenGLContext
modifier|*
name|share
parameter_list|)
member_init_list|:
name|QPlatformOpenGLContext
argument_list|()
member_init_list|,
name|m_screen
argument_list|(
name|screen
argument_list|)
member_init_list|,
name|m_context
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_format
argument_list|(
name|format
argument_list|)
block|{
name|m_shareContext
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|share
condition|)
name|m_shareContext
operator|=
cast|static_cast
argument_list|<
specifier|const
name|QGLXContext
operator|*
argument_list|>
argument_list|(
name|share
argument_list|)
operator|->
name|glxContext
argument_list|()
expr_stmt|;
name|GLXFBConfig
name|config
init|=
name|qglx_findConfig
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
name|screen
operator|->
name|screenNumber
argument_list|()
argument_list|,
name|format
argument_list|)
decl_stmt|;
if|if
condition|(
name|config
condition|)
block|{
comment|// Resolve entry point for glXCreateContextAttribsARB
name|glXCreateContextAttribsARBProc
name|glXCreateContextAttribsARB
init|=
literal|0
decl_stmt|;
name|glXCreateContextAttribsARB
operator|=
operator|(
name|glXCreateContextAttribsARBProc
operator|)
name|glXGetProcAddress
argument_list|(
operator|(
specifier|const
name|GLubyte
operator|*
operator|)
literal|"glXCreateContextAttribsARB"
argument_list|)
expr_stmt|;
if|if
condition|(
name|glXCreateContextAttribsARB
operator|!=
literal|0
condition|)
block|{
name|QVector
argument_list|<
name|int
argument_list|>
name|contextAttributes
decl_stmt|;
name|contextAttributes
operator|<<
name|GLX_CONTEXT_MAJOR_VERSION_ARB
operator|<<
name|m_format
operator|.
name|majorVersion
argument_list|()
operator|<<
name|GLX_CONTEXT_MINOR_VERSION_ARB
operator|<<
name|m_format
operator|.
name|minorVersion
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_format
operator|.
name|majorVersion
argument_list|()
operator|>
literal|3
operator|||
operator|(
name|m_format
operator|.
name|majorVersion
argument_list|()
operator|==
literal|3
operator|&&
name|m_format
operator|.
name|minorVersion
argument_list|()
operator|>
literal|1
operator|)
condition|)
block|{
if|if
condition|(
name|m_format
operator|.
name|profile
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|CoreProfile
condition|)
block|{
name|contextAttributes
operator|<<
name|GLX_CONTEXT_FLAGS_ARB
operator|<<
name|GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB
operator|<<
name|GLX_CONTEXT_PROFILE_MASK_ARB
operator|<<
name|GLX_CONTEXT_CORE_PROFILE_BIT_ARB
expr_stmt|;
block|}
else|else
block|{
name|contextAttributes
operator|<<
name|GLX_CONTEXT_PROFILE_MASK_ARB
operator|<<
name|GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB
expr_stmt|;
block|}
block|}
name|contextAttributes
operator|<<
name|None
expr_stmt|;
name|m_context
operator|=
name|glXCreateContextAttribsARB
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
name|config
argument_list|,
name|m_shareContext
argument_list|,
literal|true
argument_list|,
name|contextAttributes
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_context
operator|&&
name|m_shareContext
condition|)
block|{
comment|// re-try without a shared glx context
name|m_context
operator|=
name|glXCreateContextAttribsARB
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
name|config
argument_list|,
literal|0
argument_list|,
literal|true
argument_list|,
name|contextAttributes
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_context
condition|)
name|m_shareContext
operator|=
literal|0
expr_stmt|;
block|}
block|}
comment|// Could not create a context using glXCreateContextAttribsARB, falling back to glXCreateNewContext.
if|if
condition|(
operator|!
name|m_context
condition|)
block|{
name|m_context
operator|=
name|glXCreateNewContext
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
name|config
argument_list|,
name|GLX_RGBA_TYPE
argument_list|,
name|m_shareContext
argument_list|,
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_context
operator|&&
name|m_shareContext
condition|)
block|{
comment|// re-try without a shared glx context
name|m_context
operator|=
name|glXCreateNewContext
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
name|config
argument_list|,
name|GLX_RGBA_TYPE
argument_list|,
literal|0
argument_list|,
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_context
condition|)
name|m_shareContext
operator|=
literal|0
expr_stmt|;
block|}
block|}
if|if
condition|(
name|m_context
condition|)
block|{
name|m_format
operator|=
name|qglx_surfaceFormatFromGLXFBConfig
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
name|config
argument_list|,
name|m_context
argument_list|)
expr_stmt|;
name|m_format
operator|.
name|setMajorVersion
argument_list|(
name|format
operator|.
name|majorVersion
argument_list|()
argument_list|)
expr_stmt|;
name|m_format
operator|.
name|setMinorVersion
argument_list|(
name|format
operator|.
name|minorVersion
argument_list|()
argument_list|)
expr_stmt|;
name|m_format
operator|.
name|setProfile
argument_list|(
name|format
operator|.
name|profile
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|XVisualInfo
modifier|*
name|visualInfo
init|=
name|qglx_findVisualInfo
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
name|screen
operator|->
name|screenNumber
argument_list|()
argument_list|,
operator|&
name|m_format
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|visualInfo
condition|)
name|qFatal
argument_list|(
literal|"Could not initialize GLX"
argument_list|)
expr_stmt|;
name|m_context
operator|=
name|glXCreateContext
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
name|visualInfo
argument_list|,
name|m_shareContext
argument_list|,
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_context
operator|&&
name|m_shareContext
condition|)
block|{
comment|// re-try without a shared glx context
name|m_shareContext
operator|=
literal|0
expr_stmt|;
name|m_context
operator|=
name|glXCreateContext
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
name|visualInfo
argument_list|,
literal|0
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
name|XFree
argument_list|(
name|visualInfo
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QGLXContext
name|QGLXContext
operator|::
name|~
name|QGLXContext
parameter_list|()
block|{
name|glXDestroyContext
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
name|m_context
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|makeCurrent
name|bool
name|QGLXContext
operator|::
name|makeCurrent
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|surface
operator|->
name|surface
argument_list|()
operator|->
name|surfaceType
argument_list|()
operator|==
name|QSurface
operator|::
name|OpenGLSurface
argument_list|)
expr_stmt|;
name|GLXDrawable
name|glxDrawable
init|=
cast|static_cast
argument_list|<
name|QXcbWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
operator|->
name|xcb_window
argument_list|()
decl_stmt|;
return|return
name|glXMakeCurrent
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
name|glxDrawable
argument_list|,
name|m_context
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|doneCurrent
name|void
name|QGLXContext
operator|::
name|doneCurrent
parameter_list|()
block|{
name|glXMakeCurrent
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QGLXContext
operator|::
name|swapBuffers
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|GLXDrawable
name|glxDrawable
init|=
cast|static_cast
argument_list|<
name|QXcbWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
operator|->
name|xcb_window
argument_list|()
decl_stmt|;
name|glXSwapBuffers
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
name|glxDrawable
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
DECL|function|getProcAddress
name|void
argument_list|(
argument|*QGLXContext::getProcAddress(const QByteArray&procName)
argument_list|)
end_macro
begin_expr_stmt
DECL|function|getProcAddress
operator|(
operator|)
block|{
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|qt_glXGetProcAddressARB
function_decl|)
parameter_list|(
specifier|const
name|GLubyte
modifier|*
parameter_list|)
function_decl|;
specifier|static
name|qt_glXGetProcAddressARB
name|glXGetProcAddressARB
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|static
name|bool
name|resolved
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|resolved
operator|&&
operator|!
name|glXGetProcAddressARB
condition|)
return|return
literal|0
return|;
end_if
begin_if
if|if
condition|(
operator|!
name|glXGetProcAddressARB
condition|)
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|glxExt
init|=
name|QByteArray
argument_list|(
name|glXGetClientString
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
name|GLX_EXTENSIONS
argument_list|)
argument_list|)
operator|.
name|split
argument_list|(
literal|' '
argument_list|)
decl_stmt|;
if|if
condition|(
name|glxExt
operator|.
name|contains
argument_list|(
literal|"GLX_ARB_get_proc_address"
argument_list|)
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_BSD4
argument_list|)
name|void
modifier|*
name|handle
init|=
name|dlopen
argument_list|(
name|NULL
argument_list|,
name|RTLD_LAZY
argument_list|)
decl_stmt|;
if|if
condition|(
name|handle
condition|)
block|{
name|glXGetProcAddressARB
operator|=
operator|(
name|qt_glXGetProcAddressARB
operator|)
name|dlsym
argument_list|(
name|handle
argument_list|,
literal|"glXGetProcAddressARB"
argument_list|)
expr_stmt|;
name|dlclose
argument_list|(
name|handle
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|glXGetProcAddressARB
condition|)
endif|#
directive|endif
block|{
specifier|extern
specifier|const
name|QString
name|qt_gl_library_name
parameter_list|()
function_decl|;
comment|//                QLibrary lib(qt_gl_library_name());
name|QLibrary
name|lib
argument_list|(
name|QLatin1String
argument_list|(
literal|"GL"
argument_list|)
argument_list|)
decl_stmt|;
name|glXGetProcAddressARB
operator|=
operator|(
name|qt_glXGetProcAddressARB
operator|)
name|lib
operator|.
name|resolve
argument_list|(
literal|"glXGetProcAddressARB"
argument_list|)
expr_stmt|;
block|}
block|}
name|resolved
operator|=
literal|true
expr_stmt|;
block|}
end_if
begin_if
if|if
condition|(
operator|!
name|glXGetProcAddressARB
condition|)
return|return
literal|0
return|;
end_if
begin_return
return|return
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|glXGetProcAddressARB
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|GLubyte
operator|*
argument_list|>
argument_list|(
name|procName
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|)
return|;
end_return
begin_macro
unit|}  QSurfaceFormat
DECL|function|format
name|QGLXContext
end_macro
begin_expr_stmt
DECL|function|format
operator|::
name|format
operator|(
operator|)
specifier|const
block|{
return|return
name|m_format
return|;
block|}
end_expr_stmt
begin_function
DECL|function|isSharing
name|bool
name|QGLXContext
operator|::
name|isSharing
parameter_list|()
specifier|const
block|{
return|return
name|m_shareContext
operator|!=
literal|0
return|;
block|}
end_function
begin_function
DECL|function|isValid
name|bool
name|QGLXContext
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|m_context
operator|!=
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
