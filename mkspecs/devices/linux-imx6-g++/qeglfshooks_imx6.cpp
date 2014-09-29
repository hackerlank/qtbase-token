begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfshooks.h"
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
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QEglFSImx6Hooks
class|class
name|QEglFSImx6Hooks
super|:
specifier|public
name|QEglFSHooks
block|{
public|public:
name|QEglFSImx6Hooks
parameter_list|()
constructor_decl|;
specifier|virtual
name|QSize
name|screenSize
parameter_list|()
specifier|const
function_decl|;
specifier|virtual
name|EGLNativeWindowType
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
function_decl|;
specifier|virtual
name|void
name|destroyNativeWindow
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
function_decl|;
specifier|virtual
name|EGLNativeDisplayType
name|platformDisplay
parameter_list|()
specifier|const
function_decl|;
private|private:
DECL|member|mScreenSize
name|QSize
name|mScreenSize
decl_stmt|;
DECL|member|mNativeDisplay
name|EGLNativeDisplayType
name|mNativeDisplay
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QEglFSImx6Hooks
name|QEglFSImx6Hooks
operator|::
name|QEglFSImx6Hooks
parameter_list|()
block|{
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
literal|"QEglFSImx6Hooks will set environment variable FB_MULTI_BUFFER=2 to enable double buffering and vsync.\n"
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
end_constructor
begin_function
DECL|function|screenSize
name|QSize
name|QEglFSImx6Hooks
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
name|QEglFSImx6Hooks
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
name|QEglFSImx6Hooks
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
name|QEglFSImx6Hooks
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
begin_decl_stmt
DECL|variable|eglFSImx6Hooks
name|QEglFSImx6Hooks
name|eglFSImx6Hooks
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|platformHooks
name|QEglFSHooks
modifier|*
name|platformHooks
init|=
operator|&
name|eglFSImx6Hooks
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
