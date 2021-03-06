begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 BogDan Vatra<bogdan@kde.org> ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QANDROIDPLATFORMOPENGLWINDOW_H
end_ifndef
begin_define
DECL|macro|QANDROIDPLATFORMOPENGLWINDOW_H
define|#
directive|define
name|QANDROIDPLATFORMOPENGLWINDOW_H
end_define
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_include
include|#
directive|include
file|<QWaitCondition>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qjni_p.h>
end_include
begin_include
include|#
directive|include
file|"androidsurfaceclient.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformwindow.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAndroidPlatformWindow
name|class
name|QAndroidPlatformOpenGLWindow
range|:
name|public
name|QAndroidPlatformWindow
decl_stmt|,
name|public
name|AndroidSurfaceClient
block|{
name|public
label|:
name|explicit
name|QAndroidPlatformOpenGLWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|EGLDisplay
name|display
parameter_list|)
function_decl|;
operator|~
name|QAndroidPlatformOpenGLWindow
argument_list|()
expr_stmt|;
name|void
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
name|EGLSurface
name|eglSurface
parameter_list|(
name|EGLConfig
name|config
parameter_list|)
function_decl|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|checkNativeSurface
parameter_list|(
name|EGLConfig
name|config
parameter_list|)
function_decl|;
name|void
name|applicationStateChanged
argument_list|(
name|Qt
operator|::
name|ApplicationState
argument_list|)
decl_stmt|;
name|void
name|repaint
argument_list|(
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|protected
label|:
name|virtual
name|void
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
function_decl|;
name|void
name|createEgl
parameter_list|(
name|EGLConfig
name|config
parameter_list|)
function_decl|;
name|void
name|clearEgl
parameter_list|()
function_decl|;
name|private
label|:
name|EGLDisplay
name|m_eglDisplay
init|=
name|EGL_NO_DISPLAY
decl_stmt|;
name|EGLSurface
name|m_eglSurface
init|=
name|EGL_NO_SURFACE
decl_stmt|;
name|EGLNativeWindowType
name|m_nativeWindow
init|=
name|nullptr
decl_stmt|;
name|int
name|m_nativeSurfaceId
init|=
operator|-
literal|1
decl_stmt|;
name|QJNIObjectPrivate
name|m_androidSurfaceObject
decl_stmt|;
name|QWaitCondition
name|m_surfaceWaitCondition
decl_stmt|;
name|QSurfaceFormat
name|m_format
decl_stmt|;
name|QRect
name|m_oldGeometry
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QANDROIDPLATFORMOPENGLWINDOW_H
end_comment
end_unit
