begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandxcompositeglxcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandxcompositeglxwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandxcompositebuffer.h"
end_include
begin_include
include|#
directive|include
file|"wayland-xcomposite-client-protocol.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<X11/extensions/Xcomposite.h>
end_include
begin_constructor
DECL|function|QWaylandXCompositeGLXContext
name|QWaylandXCompositeGLXContext
operator|::
name|QWaylandXCompositeGLXContext
parameter_list|(
name|QWaylandXCompositeGLXIntegration
modifier|*
name|glxIntegration
parameter_list|,
name|QWaylandXCompositeGLXWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformGLContext
argument_list|()
member_init_list|,
name|mGlxIntegration
argument_list|(
name|glxIntegration
argument_list|)
member_init_list|,
name|mWindow
argument_list|(
name|window
argument_list|)
member_init_list|,
name|mBuffer
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mXWindow
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mConfig
argument_list|(
name|qglx_findConfig
argument_list|(
name|glxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|glxIntegration
operator|->
name|screen
argument_list|()
argument_list|,
name|window
operator|->
name|widget
argument_list|()
operator|->
name|platformWindowFormat
argument_list|()
argument_list|)
argument_list|)
member_init_list|,
name|mWaitingForSyncCallback
argument_list|(
literal|false
argument_list|)
block|{
name|XVisualInfo
modifier|*
name|visualInfo
init|=
name|glXGetVisualFromFBConfig
argument_list|(
name|glxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|mConfig
argument_list|)
decl_stmt|;
name|mContext
operator|=
name|glXCreateContext
argument_list|(
name|glxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|visualInfo
argument_list|,
literal|0
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|geometryChanged
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|makeCurrent
name|void
name|QWaylandXCompositeGLXContext
operator|::
name|makeCurrent
parameter_list|()
block|{
name|QPlatformGLContext
operator|::
name|makeCurrent
argument_list|()
expr_stmt|;
name|glXMakeCurrent
argument_list|(
name|mGlxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|mXWindow
argument_list|,
name|mContext
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|doneCurrent
name|void
name|QWaylandXCompositeGLXContext
operator|::
name|doneCurrent
parameter_list|()
block|{
name|glXMakeCurrent
argument_list|(
name|mGlxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QPlatformGLContext
operator|::
name|doneCurrent
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QWaylandXCompositeGLXContext
operator|::
name|swapBuffers
parameter_list|()
block|{
name|QSize
name|size
init|=
name|mWindow
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
decl_stmt|;
name|glXSwapBuffers
argument_list|(
name|mGlxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|mXWindow
argument_list|)
expr_stmt|;
name|mWindow
operator|->
name|damage
argument_list|(
name|QRegion
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|size
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|mWindow
operator|->
name|waitForFrameSync
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getProcAddress
name|void
modifier|*
name|QWaylandXCompositeGLXContext
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
name|glXGetProcAddress
argument_list|(
cast|reinterpret_cast
argument_list|<
name|GLubyte
operator|*
argument_list|>
argument_list|(
name|procName
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|platformWindowFormat
name|QPlatformWindowFormat
name|QWaylandXCompositeGLXContext
operator|::
name|platformWindowFormat
parameter_list|()
specifier|const
block|{
return|return
name|qglx_platformWindowFromGLXFBConfig
argument_list|(
name|mGlxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|mConfig
argument_list|,
name|mContext
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|sync_function
name|void
name|QWaylandXCompositeGLXContext
operator|::
name|sync_function
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
block|{
name|QWaylandXCompositeGLXContext
modifier|*
name|that
init|=
cast|static_cast
argument_list|<
name|QWaylandXCompositeGLXContext
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|that
operator|->
name|mWaitingForSyncCallback
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|waitForSync
name|void
name|QWaylandXCompositeGLXContext
operator|::
name|waitForSync
parameter_list|()
block|{
name|wl_display_sync_callback
argument_list|(
name|mGlxIntegration
operator|->
name|waylandDisplay
argument_list|()
operator|->
name|wl_display
argument_list|()
argument_list|,
name|QWaylandXCompositeGLXContext
operator|::
name|sync_function
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|mWaitingForSyncCallback
operator|=
literal|true
expr_stmt|;
name|wl_display_sync
argument_list|(
name|mGlxIntegration
operator|->
name|waylandDisplay
argument_list|()
operator|->
name|wl_display
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mGlxIntegration
operator|->
name|waylandDisplay
argument_list|()
operator|->
name|flushRequests
argument_list|()
expr_stmt|;
while|while
condition|(
name|mWaitingForSyncCallback
condition|)
block|{
name|mGlxIntegration
operator|->
name|waylandDisplay
argument_list|()
operator|->
name|readEvents
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|geometryChanged
name|void
name|QWaylandXCompositeGLXContext
operator|::
name|geometryChanged
parameter_list|()
block|{
name|QSize
name|size
argument_list|(
name|mWindow
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|size
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|//QGLWidget wants a context for a window without geometry
name|size
operator|=
name|QSize
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
operator|delete
name|mBuffer
expr_stmt|;
comment|//XFreePixmap deletes the glxPixmap as well
if|if
condition|(
name|mXWindow
condition|)
block|{
name|XDestroyWindow
argument_list|(
name|mGlxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|mXWindow
argument_list|)
expr_stmt|;
block|}
name|XVisualInfo
modifier|*
name|visualInfo
init|=
name|glXGetVisualFromFBConfig
argument_list|(
name|mGlxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|mConfig
argument_list|)
decl_stmt|;
name|Colormap
name|cmap
init|=
name|XCreateColormap
argument_list|(
name|mGlxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|mGlxIntegration
operator|->
name|rootWindow
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
name|colormap
operator|=
name|cmap
expr_stmt|;
name|mXWindow
operator|=
name|XCreateWindow
argument_list|(
name|mGlxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|mGlxIntegration
operator|->
name|rootWindow
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
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
name|CWColormap
argument_list|,
operator|&
name|a
argument_list|)
expr_stmt|;
name|XCompositeRedirectWindow
argument_list|(
name|mGlxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|mXWindow
argument_list|,
name|CompositeRedirectManual
argument_list|)
expr_stmt|;
name|XMapWindow
argument_list|(
name|mGlxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|mXWindow
argument_list|)
expr_stmt|;
name|XSync
argument_list|(
name|mGlxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|False
argument_list|)
expr_stmt|;
name|mBuffer
operator|=
operator|new
name|QWaylandXCompositeBuffer
argument_list|(
name|mGlxIntegration
operator|->
name|waylandXComposite
argument_list|()
argument_list|,
operator|(
name|uint32_t
operator|)
name|mXWindow
argument_list|,
name|size
argument_list|,
name|mGlxIntegration
operator|->
name|waylandDisplay
argument_list|()
operator|->
name|argbVisual
argument_list|()
argument_list|)
expr_stmt|;
name|mWindow
operator|->
name|attach
argument_list|(
name|mBuffer
argument_list|)
expr_stmt|;
name|waitForSync
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
