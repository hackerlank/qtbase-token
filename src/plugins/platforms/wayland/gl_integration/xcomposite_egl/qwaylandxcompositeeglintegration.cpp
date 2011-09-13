begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandxcompositeeglintegration.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandxcompositeeglwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|"wayland-xcomposite-client-protocol.h"
end_include
begin_function
DECL|function|createGLIntegration
name|QWaylandGLIntegration
modifier|*
name|QWaylandGLIntegration
operator|::
name|createGLIntegration
parameter_list|(
name|QWaylandDisplay
modifier|*
name|waylandDisplay
parameter_list|)
block|{
return|return
operator|new
name|QWaylandXCompositeEGLIntegration
argument_list|(
name|waylandDisplay
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|QWaylandXCompositeEGLIntegration
name|QWaylandXCompositeEGLIntegration
operator|::
name|QWaylandXCompositeEGLIntegration
parameter_list|(
name|QWaylandDisplay
modifier|*
name|waylandDispaly
parameter_list|)
member_init_list|:
name|QWaylandGLIntegration
argument_list|()
member_init_list|,
name|mWaylandDisplay
argument_list|(
name|waylandDispaly
argument_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Using XComposite-EGL"
expr_stmt|;
name|wl_display_add_global_listener
argument_list|(
name|mWaylandDisplay
operator|->
name|wl_display
argument_list|()
argument_list|,
name|QWaylandXCompositeEGLIntegration
operator|::
name|wlDisplayHandleGlobal
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaylandXCompositeEGLIntegration
name|QWaylandXCompositeEGLIntegration
operator|::
name|~
name|QWaylandXCompositeEGLIntegration
parameter_list|()
block|{
name|XCloseDisplay
argument_list|(
name|mDisplay
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|initialize
name|void
name|QWaylandXCompositeEGLIntegration
operator|::
name|initialize
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|createEglWindow
name|QWaylandWindow
modifier|*
name|QWaylandXCompositeEGLIntegration
operator|::
name|createEglWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
return|return
operator|new
name|QWaylandXCompositeEGLWindow
argument_list|(
name|window
argument_list|,
name|this
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QWaylandXCompositeEGLIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|glFormat
parameter_list|,
name|QPlatformOpenGLContext
modifier|*
name|share
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QWaylandXCompositeEGLContext
argument_list|(
name|glFormat
argument_list|,
name|share
argument_list|,
name|eglDisplay
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|xDisplay
name|Display
modifier|*
name|QWaylandXCompositeEGLIntegration
operator|::
name|xDisplay
parameter_list|()
specifier|const
block|{
return|return
name|mDisplay
return|;
block|}
end_function
begin_function
DECL|function|eglDisplay
name|EGLDisplay
name|QWaylandXCompositeEGLIntegration
operator|::
name|eglDisplay
parameter_list|()
specifier|const
block|{
return|return
name|mEglDisplay
return|;
block|}
end_function
begin_function
DECL|function|screen
name|int
name|QWaylandXCompositeEGLIntegration
operator|::
name|screen
parameter_list|()
specifier|const
block|{
return|return
name|mScreen
return|;
block|}
end_function
begin_function
DECL|function|rootWindow
name|Window
name|QWaylandXCompositeEGLIntegration
operator|::
name|rootWindow
parameter_list|()
specifier|const
block|{
return|return
name|mRootWindow
return|;
block|}
end_function
begin_function
DECL|function|waylandDisplay
name|QWaylandDisplay
modifier|*
name|QWaylandXCompositeEGLIntegration
operator|::
name|waylandDisplay
parameter_list|()
specifier|const
block|{
return|return
name|mWaylandDisplay
return|;
block|}
end_function
begin_function
DECL|function|waylandXComposite
name|wl_xcomposite
modifier|*
name|QWaylandXCompositeEGLIntegration
operator|::
name|waylandXComposite
parameter_list|()
specifier|const
block|{
return|return
name|mWaylandComposite
return|;
block|}
end_function
begin_decl_stmt
DECL|member|xcomposite_listener
specifier|const
name|struct
name|wl_xcomposite_listener
name|QWaylandXCompositeEGLIntegration
operator|::
name|xcomposite_listener
init|=
block|{
name|QWaylandXCompositeEGLIntegration
operator|::
name|rootInformation
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|wlDisplayHandleGlobal
name|void
name|QWaylandXCompositeEGLIntegration
operator|::
name|wlDisplayHandleGlobal
parameter_list|(
name|wl_display
modifier|*
name|display
parameter_list|,
name|uint32_t
name|id
parameter_list|,
specifier|const
name|char
modifier|*
name|interface
parameter_list|,
name|uint32_t
name|version
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|version
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|interface
argument_list|,
literal|"wl_xcomposite"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|QWaylandXCompositeEGLIntegration
modifier|*
name|integration
init|=
cast|static_cast
argument_list|<
name|QWaylandXCompositeEGLIntegration
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|integration
operator|->
name|mWaylandComposite
operator|=
name|wl_xcomposite_create
argument_list|(
name|display
argument_list|,
name|id
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|wl_xcomposite_add_listener
argument_list|(
name|integration
operator|->
name|mWaylandComposite
argument_list|,
operator|&
name|xcomposite_listener
argument_list|,
name|integration
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|rootInformation
name|void
name|QWaylandXCompositeEGLIntegration
operator|::
name|rootInformation
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|wl_xcomposite
modifier|*
name|xcomposite
parameter_list|,
specifier|const
name|char
modifier|*
name|display_name
parameter_list|,
name|uint32_t
name|root_window
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|xcomposite
argument_list|)
expr_stmt|;
name|QWaylandXCompositeEGLIntegration
modifier|*
name|integration
init|=
cast|static_cast
argument_list|<
name|QWaylandXCompositeEGLIntegration
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|integration
operator|->
name|mDisplay
operator|=
name|XOpenDisplay
argument_list|(
name|display_name
argument_list|)
expr_stmt|;
name|integration
operator|->
name|mRootWindow
operator|=
operator|(
name|Window
operator|)
name|root_window
expr_stmt|;
name|integration
operator|->
name|mScreen
operator|=
name|XDefaultScreen
argument_list|(
name|integration
operator|->
name|mDisplay
argument_list|)
expr_stmt|;
name|integration
operator|->
name|mEglDisplay
operator|=
name|eglGetDisplay
argument_list|(
name|integration
operator|->
name|mDisplay
argument_list|)
expr_stmt|;
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
expr_stmt|;
name|EGLint
name|minor
decl_stmt|,
name|major
decl_stmt|;
if|if
condition|(
operator|!
name|eglInitialize
argument_list|(
name|integration
operator|->
name|mEglDisplay
argument_list|,
operator|&
name|major
argument_list|,
operator|&
name|minor
argument_list|)
condition|)
block|{
name|qFatal
argument_list|(
literal|"Failed to initialize EGL"
argument_list|)
expr_stmt|;
block|}
name|eglSwapInterval
argument_list|(
name|integration
operator|->
name|eglDisplay
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"ROOT INFORMATION"
operator|<<
name|integration
operator|->
name|mDisplay
operator|<<
name|integration
operator|->
name|mRootWindow
operator|<<
name|integration
operator|->
name|mScreen
expr_stmt|;
block|}
end_function
end_unit
