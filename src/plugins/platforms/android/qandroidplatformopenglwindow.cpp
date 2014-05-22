begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 BogDan Vatra<bogdan@kde.org> ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qandroidplatformopenglwindow.h"
end_include
begin_include
include|#
directive|include
file|"androidjnimain.h"
end_include
begin_include
include|#
directive|include
file|<QSurfaceFormat>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglconvenience_p.h>
end_include
begin_include
include|#
directive|include
file|<android/native_window.h>
end_include
begin_include
include|#
directive|include
file|<android/native_window_jni.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QAndroidPlatformOpenGLWindow
name|QAndroidPlatformOpenGLWindow
operator|::
name|QAndroidPlatformOpenGLWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|EGLDisplay
name|display
parameter_list|)
member_init_list|:
name|QAndroidPlatformWindow
argument_list|(
name|window
argument_list|)
member_init_list|,
name|m_eglDisplay
argument_list|(
name|display
argument_list|)
block|{
name|lockSurface
argument_list|()
expr_stmt|;
name|m_nativeSurfaceId
operator|=
name|QtAndroid
operator|::
name|createSurface
argument_list|(
name|this
argument_list|,
name|geometry
argument_list|()
argument_list|,
name|bool
argument_list|(
name|window
operator|->
name|flags
argument_list|()
operator|&
name|Qt
operator|::
name|WindowStaysOnTopHint
argument_list|)
argument_list|,
literal|32
argument_list|)
expr_stmt|;
name|m_surfaceWaitCondition
operator|.
name|wait
argument_list|(
operator|&
name|m_surfaceMutex
argument_list|)
expr_stmt|;
name|unlockSurface
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QAndroidPlatformOpenGLWindow
name|QAndroidPlatformOpenGLWindow
operator|::
name|~
name|QAndroidPlatformOpenGLWindow
parameter_list|()
block|{
name|m_surfaceWaitCondition
operator|.
name|wakeOne
argument_list|()
expr_stmt|;
name|lockSurface
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_nativeSurfaceId
operator|!=
operator|-
literal|1
condition|)
name|QtAndroid
operator|::
name|destroySurface
argument_list|(
name|m_nativeSurfaceId
argument_list|)
expr_stmt|;
name|clearEgl
argument_list|()
expr_stmt|;
name|unlockSurface
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setGeometry
name|void
name|QAndroidPlatformOpenGLWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
if|if
condition|(
name|rect
operator|==
name|geometry
argument_list|()
condition|)
return|return;
name|QRect
name|oldGeometry
init|=
name|geometry
argument_list|()
decl_stmt|;
name|QAndroidPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|QtAndroid
operator|::
name|setSurfaceGeometry
argument_list|(
name|m_nativeSurfaceId
argument_list|,
name|rect
argument_list|)
expr_stmt|;
name|QRect
name|availableGeometry
init|=
name|screen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
decl_stmt|;
if|if
condition|(
name|oldGeometry
operator|.
name|width
argument_list|()
operator|==
literal|0
operator|&&
name|oldGeometry
operator|.
name|height
argument_list|()
operator|==
literal|0
operator|&&
name|rect
operator|.
name|width
argument_list|()
operator|>
literal|0
operator|&&
name|rect
operator|.
name|height
argument_list|()
operator|>
literal|0
operator|&&
name|availableGeometry
operator|.
name|width
argument_list|()
operator|>
literal|0
operator|&&
name|availableGeometry
operator|.
name|height
argument_list|()
operator|>
literal|0
condition|)
block|{
name|QWindowSystemInterface
operator|::
name|handleExposeEvent
argument_list|(
name|window
argument_list|()
argument_list|,
name|QRegion
argument_list|(
name|rect
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|eglSurface
name|EGLSurface
name|QAndroidPlatformOpenGLWindow
operator|::
name|eglSurface
parameter_list|(
name|EGLConfig
name|config
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_surfaceMutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_eglSurface
operator|==
name|EGL_NO_SURFACE
condition|)
block|{
name|m_surfaceMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|checkNativeSurface
argument_list|(
name|config
argument_list|)
expr_stmt|;
name|m_surfaceMutex
operator|.
name|lock
argument_list|()
expr_stmt|;
block|}
return|return
name|m_eglSurface
return|;
block|}
end_function
begin_function
DECL|function|checkNativeSurface
name|void
name|QAndroidPlatformOpenGLWindow
operator|::
name|checkNativeSurface
parameter_list|(
name|EGLConfig
name|config
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_surfaceMutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_nativeSurfaceId
operator|==
operator|-
literal|1
operator|||
operator|!
name|m_androidSurfaceObject
operator|.
name|isValid
argument_list|()
condition|)
return|return;
name|createEgl
argument_list|(
name|config
argument_list|)
expr_stmt|;
comment|// we've create another surface, the window should be repainted
name|QRect
name|availableGeometry
init|=
name|screen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
decl_stmt|;
if|if
condition|(
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
operator|>
literal|0
operator|&&
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
operator|>
literal|0
operator|&&
name|availableGeometry
operator|.
name|width
argument_list|()
operator|>
literal|0
operator|&&
name|availableGeometry
operator|.
name|height
argument_list|()
operator|>
literal|0
condition|)
name|QWindowSystemInterface
operator|::
name|handleExposeEvent
argument_list|(
name|window
argument_list|()
argument_list|,
name|QRegion
argument_list|(
name|geometry
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createEgl
name|void
name|QAndroidPlatformOpenGLWindow
operator|::
name|createEgl
parameter_list|(
name|EGLConfig
name|config
parameter_list|)
block|{
name|clearEgl
argument_list|()
expr_stmt|;
name|QJNIEnvironmentPrivate
name|env
decl_stmt|;
name|m_nativeWindow
operator|=
name|ANativeWindow_fromSurface
argument_list|(
name|env
argument_list|,
name|m_androidSurfaceObject
operator|.
name|object
argument_list|()
argument_list|)
expr_stmt|;
name|m_androidSurfaceObject
operator|=
name|QJNIObjectPrivate
argument_list|()
expr_stmt|;
name|m_eglSurface
operator|=
name|eglCreateWindowSurface
argument_list|(
name|m_eglDisplay
argument_list|,
name|config
argument_list|,
name|m_nativeWindow
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
block|{
name|EGLint
name|error
init|=
name|eglGetError
argument_list|()
decl_stmt|;
name|eglTerminate
argument_list|(
name|m_eglDisplay
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"EGL Error : Could not create the egl surface: error = 0x%x\n"
argument_list|,
name|error
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|clearEgl
name|void
name|QAndroidPlatformOpenGLWindow
operator|::
name|clearEgl
parameter_list|()
block|{
name|eglMakeCurrent
argument_list|(
name|m_eglDisplay
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_CONTEXT
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_eglSurface
operator|!=
name|EGL_NO_SURFACE
condition|)
block|{
name|eglDestroySurface
argument_list|(
name|m_eglDisplay
argument_list|,
name|m_eglSurface
argument_list|)
expr_stmt|;
name|m_eglSurface
operator|=
name|EGL_NO_SURFACE
expr_stmt|;
block|}
if|if
condition|(
name|m_nativeWindow
condition|)
block|{
name|ANativeWindow_release
argument_list|(
name|m_nativeWindow
argument_list|)
expr_stmt|;
name|m_nativeWindow
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|surfaceChanged
name|void
name|QAndroidPlatformOpenGLWindow
operator|::
name|surfaceChanged
parameter_list|(
name|JNIEnv
modifier|*
name|jniEnv
parameter_list|,
name|jobject
name|surface
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|jniEnv
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|h
argument_list|)
expr_stmt|;
name|lockSurface
argument_list|()
expr_stmt|;
name|m_androidSurfaceObject
operator|=
name|surface
expr_stmt|;
name|m_surfaceWaitCondition
operator|.
name|wakeOne
argument_list|()
expr_stmt|;
name|unlockSurface
argument_list|()
expr_stmt|;
comment|// repaint the window
name|QRect
name|availableGeometry
init|=
name|screen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
decl_stmt|;
if|if
condition|(
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
operator|>
literal|0
operator|&&
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
operator|>
literal|0
operator|&&
name|availableGeometry
operator|.
name|width
argument_list|()
operator|>
literal|0
operator|&&
name|availableGeometry
operator|.
name|height
argument_list|()
operator|>
literal|0
condition|)
name|QWindowSystemInterface
operator|::
name|handleExposeEvent
argument_list|(
name|window
argument_list|()
argument_list|,
name|QRegion
argument_list|(
name|geometry
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
