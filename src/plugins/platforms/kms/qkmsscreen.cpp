begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//#include<QDebug>
end_comment
begin_include
include|#
directive|include
file|"qkmscursor.h"
end_include
begin_include
include|#
directive|include
file|"qkmsscreen.h"
end_include
begin_include
include|#
directive|include
file|"qkmsdevice.h"
end_include
begin_include
include|#
directive|include
file|"qkmscontext.h"
end_include
begin_include
include|#
directive|include
file|"qkmsbuffermanager.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|//Fallback mode (taken from Wayland DRM demo compositor)
DECL|variable|builtin_1024x768
specifier|static
name|drmModeModeInfo
name|builtin_1024x768
init|=
block|{
literal|63500
block|,
comment|//clock
literal|1024
block|,
literal|1072
block|,
literal|1176
block|,
literal|1328
block|,
literal|0
block|,
literal|768
block|,
literal|771
block|,
literal|775
block|,
literal|798
block|,
literal|0
block|,
literal|59920
block|,
name|DRM_MODE_FLAG_NHSYNC
operator||
name|DRM_MODE_FLAG_PVSYNC
block|,
literal|0
block|,
literal|"1024x768"
block|}
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QKmsScreen
name|QKmsScreen
operator|::
name|QKmsScreen
parameter_list|(
name|QKmsDevice
modifier|*
name|device
parameter_list|,
name|int
name|connectorId
parameter_list|)
member_init_list|:
name|m_device
argument_list|(
name|device
argument_list|)
member_init_list|,
name|m_flipReady
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|m_connectorId
argument_list|(
name|connectorId
argument_list|)
member_init_list|,
name|m_depth
argument_list|(
literal|32
argument_list|)
member_init_list|,
name|m_format
argument_list|(
name|QImage
operator|::
name|Format_Invalid
argument_list|)
member_init_list|,
name|m_bufferManager
argument_list|(
name|this
argument_list|)
member_init_list|,
name|m_refreshTime
argument_list|(
literal|16000
argument_list|)
block|{
name|m_cursor
operator|=
operator|new
name|QKmsCursor
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|initializeScreenMode
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QKmsScreen
name|QKmsScreen
operator|::
name|~
name|QKmsScreen
parameter_list|()
block|{
operator|delete
name|m_cursor
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|geometry
name|QRect
name|QKmsScreen
operator|::
name|geometry
parameter_list|()
specifier|const
block|{
return|return
name|m_geometry
return|;
block|}
end_function
begin_function
DECL|function|depth
name|int
name|QKmsScreen
operator|::
name|depth
parameter_list|()
specifier|const
block|{
return|return
name|m_depth
return|;
block|}
end_function
begin_function
DECL|function|format
name|QImage
operator|::
name|Format
name|QKmsScreen
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|m_format
return|;
block|}
end_function
begin_function
DECL|function|physicalSize
name|QSizeF
name|QKmsScreen
operator|::
name|physicalSize
parameter_list|()
specifier|const
block|{
return|return
name|m_physicalSize
return|;
block|}
end_function
begin_function
DECL|function|framebufferObject
name|GLuint
name|QKmsScreen
operator|::
name|framebufferObject
parameter_list|()
specifier|const
block|{
return|return
name|m_bufferManager
operator|.
name|framebufferObject
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|initializeScreenMode
name|void
name|QKmsScreen
operator|::
name|initializeScreenMode
parameter_list|()
block|{
comment|//Determine optimal mode for screen
name|drmModeRes
modifier|*
name|resources
init|=
name|drmModeGetResources
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|resources
condition|)
name|qFatal
argument_list|(
literal|"drmModeGetResources failed"
argument_list|)
expr_stmt|;
name|drmModeConnector
modifier|*
name|connector
init|=
name|drmModeGetConnector
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
name|m_connectorId
argument_list|)
decl_stmt|;
name|drmModeModeInfo
modifier|*
name|mode
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|connector
operator|->
name|count_modes
operator|>
literal|0
condition|)
name|mode
operator|=
operator|&
name|connector
operator|->
name|modes
index|[
literal|0
index|]
expr_stmt|;
else|else
name|mode
operator|=
operator|&
name|builtin_1024x768
expr_stmt|;
name|drmModeEncoder
modifier|*
name|encoder
init|=
name|drmModeGetEncoder
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
name|connector
operator|->
name|encoders
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|encoder
operator|==
literal|0
condition|)
name|qFatal
argument_list|(
literal|"No encoder for connector."
argument_list|)
expr_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|resources
operator|->
name|count_crtcs
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|encoder
operator|->
name|possible_crtcs
operator|&
operator|(
literal|1
operator|<<
name|i
operator|)
condition|)
break|break;
block|}
if|if
condition|(
name|i
operator|==
name|resources
operator|->
name|count_crtcs
condition|)
name|qFatal
argument_list|(
literal|"No usable crtc for encoder."
argument_list|)
expr_stmt|;
name|m_crtcId
operator|=
name|resources
operator|->
name|crtcs
index|[
name|i
index|]
expr_stmt|;
name|m_mode
operator|=
operator|*
name|mode
expr_stmt|;
name|m_geometry
operator|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_mode
operator|.
name|hdisplay
argument_list|,
name|m_mode
operator|.
name|vdisplay
argument_list|)
expr_stmt|;
name|m_depth
operator|=
literal|32
expr_stmt|;
name|m_format
operator|=
name|QImage
operator|::
name|Format_RGB32
expr_stmt|;
name|m_physicalSize
operator|=
name|QSizeF
argument_list|(
name|connector
operator|->
name|mmWidth
argument_list|,
name|connector
operator|->
name|mmHeight
argument_list|)
expr_stmt|;
comment|//Setup three buffers for current mode
name|m_bufferManager
operator|.
name|setupBuffersForMode
argument_list|(
name|m_mode
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|//Set the Mode of the screen.
name|int
name|ret
init|=
name|drmModeSetCrtc
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
name|m_crtcId
argument_list|,
name|m_bufferManager
operator|.
name|displayFramebufferId
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|m_connectorId
argument_list|,
literal|1
argument_list|,
operator|&
name|m_mode
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
condition|)
name|qFatal
argument_list|(
literal|"failed to set mode"
argument_list|)
expr_stmt|;
comment|//Cleanup
name|drmModeFreeEncoder
argument_list|(
name|encoder
argument_list|)
expr_stmt|;
name|drmModeFreeConnector
argument_list|(
name|connector
argument_list|)
expr_stmt|;
name|drmModeFreeResources
argument_list|(
name|resources
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bindFramebuffer
name|void
name|QKmsScreen
operator|::
name|bindFramebuffer
parameter_list|()
block|{
if|if
condition|(
name|m_bufferManager
operator|.
name|framebufferObject
argument_list|()
condition|)
block|{
name|glBindFramebuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|m_bufferManager
operator|.
name|framebufferObject
argument_list|()
argument_list|)
expr_stmt|;
name|glFramebufferRenderbuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|GL_COLOR_ATTACHMENT0
argument_list|,
name|GL_RENDERBUFFER
argument_list|,
name|m_bufferManager
operator|.
name|renderTargetBuffer
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QKmsScreen
operator|::
name|swapBuffers
parameter_list|()
block|{
name|waitForPageFlipComplete
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_flipReady
condition|)
name|performPageFlip
argument_list|()
expr_stmt|;
comment|//TODO: Do something with return value here
name|m_bufferManager
operator|.
name|nextBuffer
argument_list|()
expr_stmt|;
comment|//qDebug()<< "swapBuffers now rendering to "<< m_bufferManager.renderTargetBuffer();
name|bindFramebuffer
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|performPageFlip
name|void
name|QKmsScreen
operator|::
name|performPageFlip
parameter_list|()
block|{
name|quint32
name|displayFramebufferId
init|=
name|m_bufferManager
operator|.
name|displayFramebufferId
argument_list|()
decl_stmt|;
comment|//qDebug()<< "Flipping to framebuffer: "<< displayFramebufferId;
name|int
name|pageFlipStatus
init|=
name|drmModePageFlip
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
name|m_crtcId
argument_list|,
name|displayFramebufferId
argument_list|,
name|DRM_MODE_PAGE_FLIP_EVENT
argument_list|,
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|pageFlipStatus
condition|)
name|qWarning
argument_list|(
literal|"Pageflip status: %d"
argument_list|,
name|pageFlipStatus
argument_list|)
expr_stmt|;
name|m_flipReady
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setFlipReady
name|void
name|QKmsScreen
operator|::
name|setFlipReady
parameter_list|(
name|unsigned
name|int
name|time
parameter_list|)
block|{
name|m_flipReady
operator|=
literal|true
expr_stmt|;
name|m_refreshTime
operator|=
name|time
expr_stmt|;
name|performPageFlip
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|device
name|QKmsDevice
modifier|*
name|QKmsScreen
operator|::
name|device
parameter_list|()
specifier|const
block|{
return|return
name|m_device
return|;
block|}
end_function
begin_function
DECL|function|waitForPageFlipComplete
name|void
name|QKmsScreen
operator|::
name|waitForPageFlipComplete
parameter_list|()
block|{
comment|//Check manually if there is something to be read on the device
comment|//as there are senarios where the signal is not received (starvation)
name|fd_set
name|fdSet
decl_stmt|;
name|timeval
name|timeValue
decl_stmt|;
name|int
name|returnValue
decl_stmt|;
name|FD_ZERO
argument_list|(
operator|&
name|fdSet
argument_list|)
expr_stmt|;
name|FD_SET
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
operator|&
name|fdSet
argument_list|)
expr_stmt|;
name|timeValue
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
name|timeValue
operator|.
name|tv_usec
operator|=
name|m_refreshTime
expr_stmt|;
name|returnValue
operator|=
name|select
argument_list|(
literal|1
argument_list|,
operator|&
name|fdSet
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|timeValue
argument_list|)
expr_stmt|;
if|if
condition|(
name|returnValue
condition|)
block|{
name|m_device
operator|->
name|handlePageFlipCompleted
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
