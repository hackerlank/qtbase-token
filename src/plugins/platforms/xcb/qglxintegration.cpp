begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QtGui/QOffscreenSurface>
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
name|GLX_CONTEXT_ES2_PROFILE_BIT_EXT
end_ifndef
begin_define
DECL|macro|GLX_CONTEXT_ES2_PROFILE_BIT_EXT
define|#
directive|define
name|GLX_CONTEXT_ES2_PROFILE_BIT_EXT
value|0x00000004
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
begin_ifndef
ifndef|#
directive|ifndef
name|GL_CONTEXT_FLAG_DEBUG_BIT
end_ifndef
begin_define
DECL|macro|GL_CONTEXT_FLAG_DEBUG_BIT
define|#
directive|define
name|GL_CONTEXT_FLAG_DEBUG_BIT
value|0x00000002
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|createDummyWindow
specifier|static
name|Window
name|createDummyWindow
parameter_list|(
name|QXcbScreen
modifier|*
name|screen
parameter_list|,
name|XVisualInfo
modifier|*
name|visualInfo
parameter_list|)
block|{
name|Colormap
name|cmap
init|=
name|XCreateColormap
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
name|screen
operator|->
name|root
argument_list|()
argument_list|,
name|visualInfo
operator|->
name|visual
argument_list|,
name|AllocNone
argument_list|)
decl_stmt|;
name|XSetWindowAttributes
name|a
decl_stmt|;
name|a
operator|.
name|background_pixel
operator|=
name|WhitePixel
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
argument_list|)
expr_stmt|;
name|a
operator|.
name|border_pixel
operator|=
name|BlackPixel
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
argument_list|)
expr_stmt|;
name|a
operator|.
name|colormap
operator|=
name|cmap
expr_stmt|;
name|Window
name|window
init|=
name|XCreateWindow
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
name|screen
operator|->
name|root
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|,
literal|0
argument_list|,
name|visualInfo
operator|->
name|depth
argument_list|,
name|InputOutput
argument_list|,
name|visualInfo
operator|->
name|visual
argument_list|,
name|CWBackPixel
operator||
name|CWBorderPixel
operator||
name|CWColormap
argument_list|,
operator|&
name|a
argument_list|)
decl_stmt|;
name|XFreeColormap
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
name|cmap
argument_list|)
expr_stmt|;
return|return
name|window
return|;
block|}
end_function
begin_function
DECL|function|createDummyWindow
specifier|static
name|Window
name|createDummyWindow
parameter_list|(
name|QXcbScreen
modifier|*
name|screen
parameter_list|,
name|GLXFBConfig
name|config
parameter_list|)
block|{
name|XVisualInfo
modifier|*
name|visualInfo
init|=
name|glXGetVisualFromFBConfig
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
name|config
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
name|Window
name|window
init|=
name|createDummyWindow
argument_list|(
name|screen
argument_list|,
name|visualInfo
argument_list|)
decl_stmt|;
name|XFree
argument_list|(
name|visualInfo
argument_list|)
expr_stmt|;
return|return
name|window
return|;
block|}
end_function
begin_function
DECL|function|getGlString
specifier|static
specifier|inline
name|QByteArray
name|getGlString
parameter_list|(
name|GLenum
name|param
parameter_list|)
block|{
if|if
condition|(
specifier|const
name|GLubyte
modifier|*
name|s
init|=
name|glGetString
argument_list|(
name|param
argument_list|)
condition|)
return|return
name|QByteArray
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|s
argument_list|)
argument_list|)
return|;
return|return
name|QByteArray
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|updateFormatFromContext
specifier|static
name|void
name|updateFormatFromContext
parameter_list|(
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
comment|// Update the version, profile, and context bit of the format
name|int
name|major
init|=
literal|0
decl_stmt|,
name|minor
init|=
literal|0
decl_stmt|;
name|QByteArray
name|versionString
argument_list|(
name|getGlString
argument_list|(
name|GL_VERSION
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|QPlatformOpenGLContext
operator|::
name|parseOpenGLVersion
argument_list|(
name|versionString
argument_list|,
name|major
argument_list|,
name|minor
argument_list|)
condition|)
block|{
name|format
operator|.
name|setMajorVersion
argument_list|(
name|major
argument_list|)
expr_stmt|;
name|format
operator|.
name|setMinorVersion
argument_list|(
name|minor
argument_list|)
expr_stmt|;
block|}
name|format
operator|.
name|setProfile
argument_list|(
name|QSurfaceFormat
operator|::
name|NoProfile
argument_list|)
expr_stmt|;
name|format
operator|.
name|setOption
argument_list|(
name|QSurfaceFormat
operator|::
name|FormatOptions
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|renderableType
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|OpenGL
condition|)
block|{
if|if
condition|(
name|format
operator|.
name|version
argument_list|()
operator|<
name|qMakePair
argument_list|(
literal|3
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|format
operator|.
name|setOption
argument_list|(
name|QSurfaceFormat
operator|::
name|DeprecatedFunctions
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Version 3.0 onwards - check if it includes deprecated functionality or is
comment|// a debug context
name|GLint
name|value
init|=
literal|0
decl_stmt|;
name|glGetIntegerv
argument_list|(
name|GL_CONTEXT_FLAGS
argument_list|,
operator|&
name|value
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|value
operator|&
name|GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
operator|)
condition|)
name|format
operator|.
name|setOption
argument_list|(
name|QSurfaceFormat
operator|::
name|DeprecatedFunctions
argument_list|)
expr_stmt|;
if|if
condition|(
name|value
operator|&
name|GL_CONTEXT_FLAG_DEBUG_BIT
condition|)
name|format
operator|.
name|setOption
argument_list|(
name|QSurfaceFormat
operator|::
name|DebugContext
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|version
argument_list|()
operator|<
name|qMakePair
argument_list|(
literal|3
argument_list|,
literal|2
argument_list|)
condition|)
return|return;
comment|// Version 3.2 and newer have a profile
name|value
operator|=
literal|0
expr_stmt|;
name|glGetIntegerv
argument_list|(
name|GL_CONTEXT_PROFILE_MASK
argument_list|,
operator|&
name|value
argument_list|)
expr_stmt|;
if|if
condition|(
name|value
operator|&
name|GL_CONTEXT_CORE_PROFILE_BIT
condition|)
name|format
operator|.
name|setProfile
argument_list|(
name|QSurfaceFormat
operator|::
name|CoreProfile
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|value
operator|&
name|GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
condition|)
name|format
operator|.
name|setProfile
argument_list|(
name|QSurfaceFormat
operator|::
name|CompatibilityProfile
argument_list|)
expr_stmt|;
block|}
block|}
end_function
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
name|m_shareContext
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_format
argument_list|(
name|format
argument_list|)
member_init_list|,
name|m_isPBufferCurrent
argument_list|(
literal|false
argument_list|)
block|{
if|if
condition|(
name|m_format
operator|.
name|renderableType
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|DefaultRenderableType
condition|)
name|m_format
operator|.
name|setRenderableType
argument_list|(
name|QSurfaceFormat
operator|::
name|OpenGL
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_format
operator|.
name|renderableType
argument_list|()
operator|!=
name|QSurfaceFormat
operator|::
name|OpenGL
operator|&&
name|m_format
operator|.
name|renderableType
argument_list|()
operator|!=
name|QSurfaceFormat
operator|::
name|OpenGLES
condition|)
return|return;
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
name|m_format
argument_list|)
decl_stmt|;
name|XVisualInfo
modifier|*
name|visualInfo
init|=
literal|0
decl_stmt|;
name|Window
name|window
init|=
literal|0
decl_stmt|;
comment|// Temporary window used to query OpenGL context
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
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|glxExt
init|=
name|QByteArray
argument_list|(
name|glXQueryExtensionsString
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
name|m_screen
operator|->
name|screenNumber
argument_list|()
argument_list|)
argument_list|)
operator|.
name|split
argument_list|(
literal|' '
argument_list|)
decl_stmt|;
name|bool
name|supportsProfiles
init|=
name|glxExt
operator|.
name|contains
argument_list|(
literal|"GLX_ARB_create_context_profile"
argument_list|)
decl_stmt|;
comment|// Use glXCreateContextAttribsARB if available
comment|// Also, GL ES context creation requires GLX_EXT_create_context_es2_profile
if|if
condition|(
name|glxExt
operator|.
name|contains
argument_list|(
literal|"GLX_ARB_create_context"
argument_list|)
operator|&&
name|glXCreateContextAttribsARB
operator|!=
literal|0
operator|&&
operator|(
name|m_format
operator|.
name|renderableType
argument_list|()
operator|!=
name|QSurfaceFormat
operator|::
name|OpenGLES
operator|||
operator|(
name|supportsProfiles
operator|&&
name|glxExt
operator|.
name|contains
argument_list|(
literal|"GLX_EXT_create_context_es2_profile"
argument_list|)
operator|)
operator|)
condition|)
block|{
comment|// Try to create an OpenGL context for each known OpenGL version in descending
comment|// order from the requested version.
specifier|const
name|int
name|requestedVersion
init|=
name|format
operator|.
name|majorVersion
argument_list|()
operator|*
literal|10
operator|+
name|qMin
argument_list|(
name|format
operator|.
name|minorVersion
argument_list|()
argument_list|,
literal|9
argument_list|)
decl_stmt|;
name|QVector
argument_list|<
name|int
argument_list|>
name|glVersions
decl_stmt|;
if|if
condition|(
name|m_format
operator|.
name|renderableType
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|OpenGL
condition|)
block|{
if|if
condition|(
name|requestedVersion
operator|>
literal|43
condition|)
name|glVersions
operator|<<
name|requestedVersion
expr_stmt|;
comment|// Don't bother with versions below 2.0
name|glVersions
operator|<<
literal|43
operator|<<
literal|42
operator|<<
literal|41
operator|<<
literal|40
operator|<<
literal|33
operator|<<
literal|32
operator|<<
literal|31
operator|<<
literal|30
operator|<<
literal|21
operator|<<
literal|20
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|m_format
operator|.
name|renderableType
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|OpenGLES
condition|)
block|{
if|if
condition|(
name|requestedVersion
operator|>
literal|30
condition|)
name|glVersions
operator|<<
name|requestedVersion
expr_stmt|;
comment|// Don't bother with versions below ES 2.0
name|glVersions
operator|<<
literal|30
operator|<<
literal|20
expr_stmt|;
comment|// ES does not support any format option
name|m_format
operator|.
name|setOption
argument_list|(
name|QSurfaceFormat
operator|::
name|FormatOptions
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|Q_ASSERT
argument_list|(
name|glVersions
operator|.
name|count
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
operator|!
name|m_context
operator|&&
name|i
operator|<
name|glVersions
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|int
name|version
init|=
name|glVersions
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|version
operator|>
name|requestedVersion
condition|)
continue|continue;
specifier|const
name|int
name|majorVersion
init|=
name|version
operator|/
literal|10
decl_stmt|;
specifier|const
name|int
name|minorVersion
init|=
name|version
operator|%
literal|10
decl_stmt|;
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
name|majorVersion
operator|<<
name|GLX_CONTEXT_MINOR_VERSION_ARB
operator|<<
name|minorVersion
expr_stmt|;
if|if
condition|(
name|m_format
operator|.
name|renderableType
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|OpenGL
condition|)
block|{
comment|// If asking for OpenGL 3.2 or newer we should also specify a profile
if|if
condition|(
name|version
operator|>=
literal|32
operator|&&
name|supportsProfiles
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
name|contextAttributes
operator|<<
name|GLX_CONTEXT_PROFILE_MASK_ARB
operator|<<
name|GLX_CONTEXT_CORE_PROFILE_BIT_ARB
expr_stmt|;
else|else
name|contextAttributes
operator|<<
name|GLX_CONTEXT_PROFILE_MASK_ARB
operator|<<
name|GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB
expr_stmt|;
block|}
name|int
name|flags
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|m_format
operator|.
name|testOption
argument_list|(
name|QSurfaceFormat
operator|::
name|DebugContext
argument_list|)
condition|)
name|flags
operator||=
name|GLX_CONTEXT_DEBUG_BIT_ARB
expr_stmt|;
comment|// A forward-compatible context may be requested for 3.0 and later
if|if
condition|(
name|version
operator|>=
literal|30
operator|&&
operator|!
name|m_format
operator|.
name|testOption
argument_list|(
name|QSurfaceFormat
operator|::
name|DeprecatedFunctions
argument_list|)
condition|)
name|flags
operator||=
name|GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB
expr_stmt|;
if|if
condition|(
name|flags
operator|!=
literal|0
condition|)
name|contextAttributes
operator|<<
name|GLX_CONTEXT_FLAGS_ARB
operator|<<
name|flags
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|m_format
operator|.
name|renderableType
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|OpenGLES
condition|)
block|{
name|contextAttributes
operator|<<
name|GLX_CONTEXT_PROFILE_MASK_ARB
operator|<<
name|GLX_CONTEXT_ES2_PROFILE_BIT_EXT
expr_stmt|;
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
block|}
comment|// Could not create a context using glXCreateContextAttribsARB, falling back to glXCreateNewContext.
if|if
condition|(
operator|!
name|m_context
condition|)
block|{
comment|// requesting an OpenGL ES context requires glXCreateContextAttribsARB, so bail out
if|if
condition|(
name|m_format
operator|.
name|renderableType
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|OpenGLES
condition|)
return|return;
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
comment|// Get the basic surface format details
if|if
condition|(
name|m_context
condition|)
name|qglx_surfaceFormatFromGLXFBConfig
argument_list|(
operator|&
name|m_format
argument_list|,
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
comment|// Create a temporary window so that we can make the new context current
name|window
operator|=
name|createDummyWindow
argument_list|(
name|screen
argument_list|,
name|config
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// requesting an OpenGL ES context requires glXCreateContextAttribsARB, so bail out
if|if
condition|(
name|m_format
operator|.
name|renderableType
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|OpenGLES
condition|)
return|return;
comment|// Note that m_format gets updated with the used surface format
name|visualInfo
operator|=
name|qglx_findVisualInfo
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
operator|&
name|m_format
argument_list|)
expr_stmt|;
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
comment|// Create a temporary window so that we can make the new context current
name|window
operator|=
name|createDummyWindow
argument_list|(
name|screen
argument_list|,
name|visualInfo
argument_list|)
expr_stmt|;
name|XFree
argument_list|(
name|visualInfo
argument_list|)
expr_stmt|;
block|}
comment|// Query the OpenGL version and profile
if|if
condition|(
name|m_context
operator|&&
name|window
condition|)
block|{
name|glXMakeCurrent
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
name|window
argument_list|,
name|m_context
argument_list|)
expr_stmt|;
name|updateFormatFromContext
argument_list|(
name|m_format
argument_list|)
expr_stmt|;
comment|// Make our context non-current
name|glXMakeCurrent
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
comment|// Destroy our temporary window
name|XDestroyWindow
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
name|window
argument_list|)
expr_stmt|;
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
name|QSurface
operator|::
name|SurfaceClass
name|surfaceClass
init|=
name|surface
operator|->
name|surface
argument_list|()
operator|->
name|surfaceClass
argument_list|()
decl_stmt|;
if|if
condition|(
name|surfaceClass
operator|==
name|QSurface
operator|::
name|Window
condition|)
block|{
name|m_isPBufferCurrent
operator|=
literal|false
expr_stmt|;
name|QXcbWindow
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QXcbWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
decl_stmt|;
return|return
name|glXMakeCurrent
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
name|window
operator|->
name|xcb_window
argument_list|()
argument_list|,
name|m_context
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|surfaceClass
operator|==
name|QSurface
operator|::
name|Offscreen
condition|)
block|{
name|m_isPBufferCurrent
operator|=
literal|true
expr_stmt|;
name|QGLXPbuffer
modifier|*
name|pbuffer
init|=
cast|static_cast
argument_list|<
name|QGLXPbuffer
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
decl_stmt|;
return|return
name|glXMakeContextCurrent
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
name|pbuffer
operator|->
name|pbuffer
argument_list|()
argument_list|,
name|pbuffer
operator|->
name|pbuffer
argument_list|()
argument_list|,
name|m_context
argument_list|)
return|;
block|}
return|return
literal|false
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
if|if
condition|(
name|m_isPBufferCurrent
condition|)
name|glXMakeContextCurrent
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
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
name|m_isPBufferCurrent
operator|=
literal|false
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
literal|0
decl_stmt|;
if|if
condition|(
name|surface
operator|->
name|surface
argument_list|()
operator|->
name|surfaceClass
argument_list|()
operator|==
name|QSurface
operator|::
name|Offscreen
condition|)
name|glxDrawable
operator|=
cast|static_cast
argument_list|<
name|QGLXPbuffer
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
operator|->
name|pbuffer
argument_list|()
expr_stmt|;
else|else
name|glxDrawable
operator|=
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
expr_stmt|;
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
begin_constructor
DECL|function|QGLXPbuffer
name|QGLXPbuffer
operator|::
name|QGLXPbuffer
parameter_list|(
name|QOffscreenSurface
modifier|*
name|offscreenSurface
parameter_list|)
member_init_list|:
name|QPlatformOffscreenSurface
argument_list|(
name|offscreenSurface
argument_list|)
member_init_list|,
name|m_format
argument_list|(
name|offscreenSurface
operator|->
name|requestedFormat
argument_list|()
argument_list|)
member_init_list|,
name|m_screen
argument_list|(
cast|static_cast
argument_list|<
name|QXcbScreen
operator|*
argument_list|>
argument_list|(
name|offscreenSurface
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
argument_list|)
member_init_list|,
name|m_pbuffer
argument_list|(
literal|0
argument_list|)
block|{
name|GLXFBConfig
name|config
init|=
name|qglx_findConfig
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
name|m_screen
operator|->
name|screenNumber
argument_list|()
argument_list|,
name|m_format
argument_list|)
decl_stmt|;
if|if
condition|(
name|config
condition|)
block|{
specifier|const
name|int
name|attributes
index|[]
init|=
block|{
name|GLX_PBUFFER_WIDTH
block|,
name|offscreenSurface
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
block|,
name|GLX_PBUFFER_HEIGHT
block|,
name|offscreenSurface
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
block|,
name|GLX_LARGEST_PBUFFER
block|,
name|False
block|,
name|GLX_PRESERVED_CONTENTS
block|,
name|False
block|,
name|GLX_NONE
block|}
decl_stmt|;
name|m_pbuffer
operator|=
name|glXCreatePbuffer
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
name|config
argument_list|,
name|attributes
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_pbuffer
condition|)
name|qglx_surfaceFormatFromGLXFBConfig
argument_list|(
operator|&
name|m_format
argument_list|,
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
name|config
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QGLXPbuffer
name|QGLXPbuffer
operator|::
name|~
name|QGLXPbuffer
parameter_list|()
block|{
if|if
condition|(
name|m_pbuffer
condition|)
name|glXDestroyPbuffer
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
name|m_pbuffer
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
