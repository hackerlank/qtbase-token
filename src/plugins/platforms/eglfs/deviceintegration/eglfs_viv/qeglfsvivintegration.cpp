begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfsvivintegration.h"
end_include
begin_include
include|#
directive|include
file|<EGL/eglvivante.h>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|platformInit
name|void
name|QEglFSVivIntegration
operator|::
name|platformInit
parameter_list|()
block|{
name|QEGLDeviceIntegration
operator|::
name|platformInit
argument_list|()
expr_stmt|;
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
name|bool
name|multiBufferNotEnabledYet
init|=
name|qEnvironmentVariableIsEmpty
argument_list|(
literal|"FB_MULTI_BUFFER"
argument_list|)
decl_stmt|;
name|bool
name|multiBuffer
init|=
name|qEnvironmentVariableIsEmpty
argument_list|(
literal|"QT_EGLFS_IMX6_NO_FB_MULTI_BUFFER"
argument_list|)
decl_stmt|;
if|if
condition|(
name|multiBufferNotEnabledYet
operator|&&
name|multiBuffer
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QEglFSVivIntegration will set environment variable FB_MULTI_BUFFER=2 to enable double buffering and vsync.\n"
operator|<<
literal|"If this is not desired, you can override this via: export QT_EGLFS_IMX6_NO_FB_MULTI_BUFFER=1"
expr_stmt|;
name|qputenv
argument_list|(
literal|"FB_MULTI_BUFFER"
argument_list|,
literal|"2"
argument_list|)
expr_stmt|;
block|}
name|mNativeDisplay
operator|=
name|fbGetDisplayByIndex
argument_list|(
name|framebufferIndex
argument_list|()
argument_list|)
expr_stmt|;
name|fbGetDisplayGeometry
argument_list|(
name|mNativeDisplay
argument_list|,
operator|&
name|width
argument_list|,
operator|&
name|height
argument_list|)
expr_stmt|;
name|mScreenSize
operator|.
name|setHeight
argument_list|(
name|height
argument_list|)
expr_stmt|;
name|mScreenSize
operator|.
name|setWidth
argument_list|(
name|width
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|screenSize
name|QSize
name|QEglFSVivIntegration
operator|::
name|screenSize
parameter_list|()
specifier|const
block|{
return|return
name|mScreenSize
return|;
block|}
end_function
begin_function
DECL|function|platformDisplay
name|EGLNativeDisplayType
name|QEglFSVivIntegration
operator|::
name|platformDisplay
parameter_list|()
specifier|const
block|{
return|return
name|mNativeDisplay
return|;
block|}
end_function
begin_function
DECL|function|createNativeWindow
name|EGLNativeWindowType
name|QEglFSVivIntegration
operator|::
name|createNativeWindow
parameter_list|(
name|QPlatformWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|window
argument_list|)
name|Q_UNUSED
argument_list|(
argument|format
argument_list|)
name|EGLNativeWindowType
name|eglWindow
init|=
name|fbCreateWindow
argument_list|(
name|mNativeDisplay
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
argument_list|)
decl_stmt|;
return|return
name|eglWindow
return|;
block|}
end_function
begin_function
DECL|function|destroyNativeWindow
name|void
name|QEglFSVivIntegration
operator|::
name|destroyNativeWindow
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
block|{
name|fbDestroyWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
