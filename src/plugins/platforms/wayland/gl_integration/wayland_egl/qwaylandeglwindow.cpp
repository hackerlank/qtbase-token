begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandeglwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandscreen.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandglcontext.h"
end_include
begin_constructor
DECL|function|QWaylandEglWindow
name|QWaylandEglWindow
operator|::
name|QWaylandEglWindow
parameter_list|(
name|QWidget
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QWaylandWindow
argument_list|(
name|window
argument_list|)
member_init_list|,
name|mGLContext
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mWaylandEglWindow
argument_list|(
literal|0
argument_list|)
block|{
name|mEglIntegration
operator|=
cast|static_cast
argument_list|<
name|QWaylandEglIntegration
operator|*
argument_list|>
argument_list|(
name|mDisplay
operator|->
name|eglIntegration
argument_list|()
argument_list|)
expr_stmt|;
comment|//super creates a new surface
name|newSurfaceCreated
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaylandEglWindow
name|QWaylandEglWindow
operator|::
name|~
name|QWaylandEglWindow
parameter_list|()
block|{
operator|delete
name|mGLContext
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|windowType
name|QWaylandWindow
operator|::
name|WindowType
name|QWaylandEglWindow
operator|::
name|windowType
parameter_list|()
specifier|const
block|{
return|return
name|QWaylandWindow
operator|::
name|Egl
return|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|QWaylandEglWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|QWaylandWindow
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
if|if
condition|(
name|mWaylandEglWindow
condition|)
block|{
name|wl_egl_window_resize
argument_list|(
name|mWaylandEglWindow
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setParent
name|void
name|QWaylandEglWindow
operator|::
name|setParent
parameter_list|(
specifier|const
name|QPlatformWindow
modifier|*
name|parent
parameter_list|)
block|{
specifier|const
name|QWaylandWindow
modifier|*
name|wParent
init|=
cast|static_cast
argument_list|<
specifier|const
name|QWaylandWindow
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|mParentWindow
operator|=
name|wParent
expr_stmt|;
block|}
end_function
begin_function
DECL|function|glContext
name|QPlatformGLContext
modifier|*
name|QWaylandEglWindow
operator|::
name|glContext
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|mGLContext
condition|)
block|{
name|QWaylandEglWindow
modifier|*
name|that
init|=
cast|const_cast
argument_list|<
name|QWaylandEglWindow
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|that
operator|->
name|mGLContext
operator|=
operator|new
name|QWaylandGLContext
argument_list|(
name|mEglIntegration
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|widget
argument_list|()
operator|->
name|platformWindowFormat
argument_list|()
argument_list|)
expr_stmt|;
name|EGLNativeWindowType
name|window
argument_list|(
cast|reinterpret_cast
argument_list|<
name|EGLNativeWindowType
argument_list|>
argument_list|(
name|mWaylandEglWindow
argument_list|)
argument_list|)
decl_stmt|;
name|EGLSurface
name|surface
init|=
name|eglCreateWindowSurface
argument_list|(
name|mEglIntegration
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|mGLContext
operator|->
name|eglConfig
argument_list|()
argument_list|,
name|window
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
name|that
operator|->
name|mGLContext
operator|->
name|setEglSurface
argument_list|(
name|surface
argument_list|)
expr_stmt|;
block|}
return|return
name|mGLContext
return|;
block|}
end_function
begin_function
DECL|function|newSurfaceCreated
name|void
name|QWaylandEglWindow
operator|::
name|newSurfaceCreated
parameter_list|()
block|{
if|if
condition|(
name|mWaylandEglWindow
condition|)
block|{
name|wl_egl_window_destroy
argument_list|(
name|mWaylandEglWindow
argument_list|)
expr_stmt|;
block|}
name|wl_visual
modifier|*
name|visual
init|=
name|QWaylandScreen
operator|::
name|waylandScreenFromWidget
argument_list|(
name|widget
argument_list|()
argument_list|)
operator|->
name|visual
argument_list|()
decl_stmt|;
name|QSize
name|size
init|=
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|size
operator|.
name|isValid
argument_list|()
condition|)
name|size
operator|=
name|QSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mWaylandEglWindow
operator|=
name|wl_egl_window_create
argument_list|(
name|mEglIntegration
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|mSurface
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
name|visual
argument_list|)
expr_stmt|;
if|if
condition|(
name|mGLContext
condition|)
block|{
name|EGLNativeWindowType
name|window
argument_list|(
cast|reinterpret_cast
argument_list|<
name|EGLNativeWindowType
argument_list|>
argument_list|(
name|mWaylandEglWindow
argument_list|)
argument_list|)
decl_stmt|;
name|EGLSurface
name|surface
init|=
name|eglCreateWindowSurface
argument_list|(
name|mEglIntegration
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|mGLContext
operator|->
name|eglConfig
argument_list|()
argument_list|,
name|window
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
name|mGLContext
operator|->
name|setEglSurface
argument_list|(
name|surface
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
