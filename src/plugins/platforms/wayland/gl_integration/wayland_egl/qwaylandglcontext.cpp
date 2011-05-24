begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwaylanddisplay.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandwindow.h"
end_include
begin_include
include|#
directive|include
file|"../../../eglconvenience/qeglconvenience.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformWindowFormat>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMutex>
end_include
begin_constructor
DECL|function|QWaylandGLContext
name|QWaylandGLContext
operator|::
name|QWaylandGLContext
parameter_list|(
name|EGLDisplay
name|eglDisplay
parameter_list|,
specifier|const
name|QPlatformWindowFormat
modifier|&
name|format
parameter_list|)
member_init_list|:
name|QPlatformGLContext
argument_list|()
member_init_list|,
name|mEglDisplay
argument_list|(
name|eglDisplay
argument_list|)
member_init_list|,
name|mSurface
argument_list|(
name|EGL_NO_SURFACE
argument_list|)
member_init_list|,
name|mConfig
argument_list|(
name|q_configFromQPlatformWindowFormat
argument_list|(
name|mEglDisplay
argument_list|,
name|format
argument_list|,
literal|true
argument_list|)
argument_list|)
member_init_list|,
name|mFormat
argument_list|(
name|q_windowFormatFromConfig
argument_list|(
name|mEglDisplay
argument_list|,
name|mConfig
argument_list|)
argument_list|)
block|{
name|QPlatformGLContext
modifier|*
name|sharePlatformContext
init|=
literal|0
decl_stmt|;
name|sharePlatformContext
operator|=
name|format
operator|.
name|sharedGLContext
argument_list|()
expr_stmt|;
name|mFormat
operator|.
name|setSharedContext
argument_list|(
name|sharePlatformContext
argument_list|)
expr_stmt|;
name|EGLContext
name|shareEGLContext
init|=
name|EGL_NO_CONTEXT
decl_stmt|;
if|if
condition|(
name|sharePlatformContext
condition|)
name|shareEGLContext
operator|=
cast|static_cast
argument_list|<
specifier|const
name|QWaylandGLContext
operator|*
argument_list|>
argument_list|(
name|sharePlatformContext
argument_list|)
operator|->
name|mContext
expr_stmt|;
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
expr_stmt|;
name|QVector
argument_list|<
name|EGLint
argument_list|>
name|eglContextAttrs
decl_stmt|;
name|eglContextAttrs
operator|.
name|append
argument_list|(
name|EGL_CONTEXT_CLIENT_VERSION
argument_list|)
expr_stmt|;
name|eglContextAttrs
operator|.
name|append
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|eglContextAttrs
operator|.
name|append
argument_list|(
name|EGL_NONE
argument_list|)
expr_stmt|;
name|mContext
operator|=
name|eglCreateContext
argument_list|(
name|mEglDisplay
argument_list|,
name|mConfig
argument_list|,
name|shareEGLContext
argument_list|,
name|eglContextAttrs
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QWaylandGLContext
name|QWaylandGLContext
operator|::
name|QWaylandGLContext
parameter_list|()
member_init_list|:
name|QPlatformGLContext
argument_list|()
member_init_list|,
name|mEglDisplay
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mContext
argument_list|(
name|EGL_NO_CONTEXT
argument_list|)
member_init_list|,
name|mSurface
argument_list|(
name|EGL_NO_SURFACE
argument_list|)
member_init_list|,
name|mConfig
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QWaylandGLContext
name|QWaylandGLContext
operator|::
name|~
name|QWaylandGLContext
parameter_list|()
block|{
name|eglDestroyContext
argument_list|(
name|mEglDisplay
argument_list|,
name|mContext
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|makeCurrent
name|void
name|QWaylandGLContext
operator|::
name|makeCurrent
parameter_list|()
block|{
if|if
condition|(
name|mSurface
operator|==
name|EGL_NO_SURFACE
condition|)
block|{
name|qWarning
argument_list|(
literal|"makeCurrent with EGL_NO_SURFACE"
argument_list|)
expr_stmt|;
block|}
name|eglMakeCurrent
argument_list|(
name|mEglDisplay
argument_list|,
name|mSurface
argument_list|,
name|mSurface
argument_list|,
name|mContext
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|doneCurrent
name|void
name|QWaylandGLContext
operator|::
name|doneCurrent
parameter_list|()
block|{
name|QPlatformGLContext
operator|::
name|doneCurrent
argument_list|()
expr_stmt|;
name|eglMakeCurrent
argument_list|(
name|mEglDisplay
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
name|QWaylandGLContext
operator|::
name|swapBuffers
parameter_list|()
block|{
name|eglSwapBuffers
argument_list|(
name|mEglDisplay
argument_list|,
name|mSurface
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getProcAddress
name|void
modifier|*
name|QWaylandGLContext
operator|::
name|getProcAddress
parameter_list|(
specifier|const
name|QString
modifier|&
name|string
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
name|eglGetProcAddress
argument_list|(
name|string
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setEglSurface
name|void
name|QWaylandGLContext
operator|::
name|setEglSurface
parameter_list|(
name|EGLSurface
name|surface
parameter_list|)
block|{
name|doneCurrent
argument_list|()
expr_stmt|;
name|mSurface
operator|=
name|surface
expr_stmt|;
block|}
end_function
begin_function
DECL|function|eglConfig
name|EGLConfig
name|QWaylandGLContext
operator|::
name|eglConfig
parameter_list|()
specifier|const
block|{
return|return
name|mConfig
return|;
block|}
end_function
end_unit
