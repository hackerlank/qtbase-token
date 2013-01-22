begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenwfddevice.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdport.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdscreen.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<WF/wfdext.h>
end_include
begin_include
include|#
directive|include
file|<gbm.h>
end_include
begin_constructor
DECL|function|QOpenWFDDevice
name|QOpenWFDDevice
operator|::
name|QOpenWFDDevice
parameter_list|(
name|QOpenWFDIntegration
modifier|*
name|integration
parameter_list|,
name|WFDint
name|device_enumeration
parameter_list|)
member_init_list|:
name|mIntegration
argument_list|(
name|integration
argument_list|)
member_init_list|,
name|mDeviceEnum
argument_list|(
name|device_enumeration
argument_list|)
member_init_list|,
name|mCommitedDevice
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mWaitingForBindSourceEvent
argument_list|(
literal|false
argument_list|)
block|{
name|mDevice
operator|=
name|wfdCreateDevice
argument_list|(
name|WFD_DEFAULT_DEVICE_ID
argument_list|,
name|WFD_NONE
argument_list|)
expr_stmt|;
if|if
condition|(
name|mDevice
operator|==
name|WFD_INVALID_HANDLE
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"failed to create device"
expr_stmt|;
name|mEvent
operator|=
name|wfdCreateEvent
argument_list|(
name|mDevice
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|mEvent
operator|==
name|WFD_INVALID_HANDLE
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"failed to create event handle"
expr_stmt|;
comment|//initialize pipelines for device.
name|wfdEnumeratePipelines
argument_list|(
name|mDevice
argument_list|,
name|WFD_NONE
argument_list|,
literal|0
argument_list|,
name|WFD_NONE
argument_list|)
expr_stmt|;
name|initializeGbmAndEgl
argument_list|()
expr_stmt|;
name|WFDint
name|numberOfPorts
init|=
name|wfdEnumeratePorts
argument_list|(
name|mDevice
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|WFDint
name|port_enumerations
index|[
name|numberOfPorts
index|]
decl_stmt|;
name|WFDint
name|actualNumberOfPorts
init|=
name|wfdEnumeratePorts
argument_list|(
name|mDevice
argument_list|,
name|port_enumerations
argument_list|,
name|numberOfPorts
argument_list|,
name|WFD_NONE
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|actualNumberOfPorts
operator|==
name|numberOfPorts
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|actualNumberOfPorts
condition|;
name|i
operator|++
control|)
block|{
name|QOpenWFDPort
modifier|*
name|port
init|=
operator|new
name|QOpenWFDPort
argument_list|(
name|this
argument_list|,
name|port_enumerations
index|[
name|i
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|port
operator|->
name|attached
argument_list|()
condition|)
block|{
name|mPorts
operator|.
name|append
argument_list|(
name|port
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|delete
name|port
expr_stmt|;
block|}
block|}
name|int
name|fd
init|=
name|wfdDeviceEventGetFD
argument_list|(
name|mDevice
argument_list|,
name|mEvent
argument_list|)
decl_stmt|;
name|mEventSocketNotifier
operator|=
operator|new
name|QSocketNotifier
argument_list|(
name|fd
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|mEventSocketNotifier
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|readEvents
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|mCommitedDevice
operator|=
literal|true
expr_stmt|;
name|commit
argument_list|(
name|WFD_COMMIT_ENTIRE_DEVICE
argument_list|,
name|handle
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QOpenWFDDevice
name|QOpenWFDDevice
operator|::
name|~
name|QOpenWFDDevice
parameter_list|()
block|{
operator|delete
name|mEventSocketNotifier
expr_stmt|;
name|wfdDestroyEvent
argument_list|(
name|mDevice
argument_list|,
name|mEvent
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mPorts
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
comment|//probably don't need to remove them from the list
name|QList
argument_list|<
name|WFDint
argument_list|>
name|keys
init|=
name|mUsedPipelines
operator|.
name|keys
argument_list|(
name|mPorts
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|keyIndex
init|=
literal|0
init|;
name|keyIndex
operator|<
name|keys
operator|.
name|size
argument_list|()
condition|;
name|keyIndex
operator|++
control|)
block|{
name|mUsedPipelines
operator|.
name|remove
argument_list|(
name|keys
operator|.
name|at
argument_list|(
name|keyIndex
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|//but we have to delete them :)
operator|delete
name|mPorts
index|[
name|i
index|]
expr_stmt|;
block|}
name|eglDestroyContext
argument_list|(
name|mEglDisplay
argument_list|,
name|mEglContext
argument_list|)
expr_stmt|;
name|eglTerminate
argument_list|(
name|mEglDisplay
argument_list|)
expr_stmt|;
name|gbm_device_destroy
argument_list|(
name|mGbmDevice
argument_list|)
expr_stmt|;
name|wfdDestroyDevice
argument_list|(
name|mDevice
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|handle
name|WFDDevice
name|QOpenWFDDevice
operator|::
name|handle
parameter_list|()
specifier|const
block|{
return|return
name|mDevice
return|;
block|}
end_function
begin_function
DECL|function|integration
name|QOpenWFDIntegration
modifier|*
name|QOpenWFDDevice
operator|::
name|integration
parameter_list|()
specifier|const
block|{
return|return
name|mIntegration
return|;
block|}
end_function
begin_function
DECL|function|isPipelineUsed
name|bool
name|QOpenWFDDevice
operator|::
name|isPipelineUsed
parameter_list|(
name|WFDint
name|pipelineId
parameter_list|)
block|{
return|return
name|mUsedPipelines
operator|.
name|contains
argument_list|(
name|pipelineId
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|addToUsedPipelineSet
name|void
name|QOpenWFDDevice
operator|::
name|addToUsedPipelineSet
parameter_list|(
name|WFDint
name|pipelineId
parameter_list|,
name|QOpenWFDPort
modifier|*
name|port
parameter_list|)
block|{
name|mUsedPipelines
operator|.
name|insert
argument_list|(
name|pipelineId
argument_list|,
name|port
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeFromUsedPipelineSet
name|void
name|QOpenWFDDevice
operator|::
name|removeFromUsedPipelineSet
parameter_list|(
name|WFDint
name|pipelineId
parameter_list|)
block|{
name|mUsedPipelines
operator|.
name|remove
argument_list|(
name|pipelineId
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|gbmDevice
name|gbm_device
modifier|*
name|QOpenWFDDevice
operator|::
name|gbmDevice
parameter_list|()
specifier|const
block|{
return|return
name|mGbmDevice
return|;
block|}
end_function
begin_function
DECL|function|eglDisplay
name|EGLDisplay
name|QOpenWFDDevice
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
DECL|function|eglContext
name|EGLContext
name|QOpenWFDDevice
operator|::
name|eglContext
parameter_list|()
specifier|const
block|{
return|return
name|mEglContext
return|;
block|}
end_function
begin_function
DECL|function|commit
name|void
name|QOpenWFDDevice
operator|::
name|commit
parameter_list|(
name|WFDCommitType
name|type
parameter_list|,
name|WFDHandle
name|handle
parameter_list|)
block|{
if|if
condition|(
name|mCommitedDevice
condition|)
block|{
name|wfdDeviceCommit
argument_list|(
name|mDevice
argument_list|,
name|type
argument_list|,
name|handle
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|waitForPipelineBindSourceCompleteEvent
name|void
name|QOpenWFDDevice
operator|::
name|waitForPipelineBindSourceCompleteEvent
parameter_list|()
block|{
name|mWaitingForBindSourceEvent
operator|=
literal|true
expr_stmt|;
while|while
condition|(
name|mWaitingForBindSourceEvent
condition|)
block|{
name|readEvents
argument_list|(
name|WFD_FOREVER
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|readEvents
name|void
name|QOpenWFDDevice
operator|::
name|readEvents
parameter_list|(
name|WFDtime
name|wait
parameter_list|)
block|{
name|WFDEventType
name|type
init|=
name|wfdDeviceEventWait
argument_list|(
name|mDevice
argument_list|,
name|mEvent
argument_list|,
name|wait
argument_list|)
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|WFD_EVENT_NONE
operator|||
name|type
operator|==
name|WFD_EVENT_DESTROYED
condition|)
block|{
return|return;
block|}
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|WFD_EVENT_INVALID
case|:
case|case
name|WFD_EVENT_NONE
case|:
return|return;
case|case
name|WFD_EVENT_DESTROYED
case|:
name|qDebug
argument_list|()
operator|<<
literal|"Event or Device destoryed!"
expr_stmt|;
return|return;
case|case
name|WFD_EVENT_PORT_ATTACH_DETACH
case|:
name|handlePortAttachDetach
argument_list|()
expr_stmt|;
break|break;
case|case
name|WFD_EVENT_PORT_PROTECTION_FAILURE
case|:
name|qDebug
argument_list|()
operator|<<
literal|"Port protection event handling not implemented"
expr_stmt|;
break|break;
case|case
name|WFD_EVENT_PIPELINE_BIND_SOURCE_COMPLETE
case|:
name|handlePipelineBindSourceComplete
argument_list|()
expr_stmt|;
break|break;
case|case
name|WFD_EVENT_PIPELINE_BIND_MASK_COMPLETE
case|:
name|qDebug
argument_list|()
operator|<<
literal|"Pipeline bind mask event handling not implemented"
expr_stmt|;
break|break;
default|default:
name|qDebug
argument_list|()
operator|<<
literal|"Not recognised event type"
expr_stmt|;
break|break;
block|}
block|}
end_function
begin_function
DECL|function|initializeGbmAndEgl
name|void
name|QOpenWFDDevice
operator|::
name|initializeGbmAndEgl
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"initializing GBM and EGL"
expr_stmt|;
name|int
name|fd
init|=
name|wfdGetDeviceAttribi
argument_list|(
name|mDevice
argument_list|,
name|WFD_DEVICE_ID
argument_list|)
decl_stmt|;
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"failed to get WFD_DEVICE_ID"
expr_stmt|;
block|}
name|mGbmDevice
operator|=
name|gbm_create_device
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|setenv
argument_list|(
literal|"EGL_PLATFORM"
argument_list|,
literal|"drm"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mEglDisplay
operator|=
name|eglGetDisplay
argument_list|(
name|mGbmDevice
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
name|qDebug
argument_list|()
operator|<<
literal|"failed to initialize egl"
expr_stmt|;
block|}
name|QByteArray
name|eglExtensions
init|=
name|eglQueryString
argument_list|(
name|mEglDisplay
argument_list|,
name|EGL_EXTENSIONS
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|eglExtensions
operator|.
name|contains
argument_list|(
literal|"EGL_KHR_surfaceless_opengl"
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"This egl implementation does not have the required EGL extension EGL_KHR_surfaceless_opengl"
expr_stmt|;
block|}
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
expr_stmt|;
name|EGLint
name|contextAttribs
index|[]
init|=
block|{
name|EGL_CONTEXT_CLIENT_VERSION
block|,
literal|2
block|,
name|EGL_NONE
block|}
decl_stmt|;
name|mEglContext
operator|=
name|eglCreateContext
argument_list|(
name|mEglDisplay
argument_list|,
name|NULL
argument_list|,
name|EGL_NO_CONTEXT
argument_list|,
name|contextAttribs
argument_list|)
expr_stmt|;
if|if
condition|(
name|mEglContext
operator|==
name|EGL_NO_CONTEXT
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Failed to create EGL context"
expr_stmt|;
block|}
name|eglCreateImage
operator|=
operator|(
name|PFNEGLCREATEIMAGEKHRPROC
operator|)
name|eglGetProcAddress
argument_list|(
literal|"eglCreateImageKHR"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|eglCreateImage
condition|)
block|{
name|qWarning
argument_list|(
literal|"failed to load extension eglCreateImageKHR"
argument_list|)
expr_stmt|;
block|}
name|eglDestroyImage
operator|=
operator|(
name|PFNEGLDESTROYIMAGEKHRPROC
operator|)
name|eglGetProcAddress
argument_list|(
literal|"eglDestroyImageKHR"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|eglDestroyImage
condition|)
block|{
name|qWarning
argument_list|(
literal|"failed to load extension eglDestoryImageKHR"
argument_list|)
expr_stmt|;
block|}
name|glEglImageTargetRenderBufferStorage
operator|=
operator|(
name|PFNGLEGLIMAGETARGETRENDERBUFFERSTORAGEOESPROC
operator|)
name|eglGetProcAddress
argument_list|(
literal|"glEGLImageTargetRenderbufferStorageOES"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|glEglImageTargetRenderBufferStorage
condition|)
block|{
name|qWarning
argument_list|(
literal|"failed to load extension glEGLImageTargetRenderbufferStorageOES"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|handlePortAttachDetach
name|void
name|QOpenWFDDevice
operator|::
name|handlePortAttachDetach
parameter_list|()
block|{
name|WFDint
name|id
init|=
name|wfdGetEventAttribi
argument_list|(
name|mDevice
argument_list|,
name|mEvent
argument_list|,
name|WFD_EVENT_PORT_ATTACH_PORT_ID
argument_list|)
decl_stmt|;
if|if
condition|(
name|id
operator|==
name|WFD_INVALID_PORT_ID
condition|)
return|return;
name|WFDint
name|attachState
init|=
name|wfdGetEventAttribi
argument_list|(
name|mDevice
argument_list|,
name|mEvent
argument_list|,
name|WFD_EVENT_PORT_ATTACH_STATE
argument_list|)
decl_stmt|;
if|if
condition|(
name|attachState
operator|==
name|WFD_TRUE
condition|)
block|{
name|int
name|indexToAdd
init|=
operator|-
literal|1
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mPorts
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|mPorts
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|portId
argument_list|()
operator|==
name|id
condition|)
block|{
name|indexToAdd
operator|=
name|i
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"found index to attach"
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|indexToAdd
operator|>=
literal|0
condition|)
block|{
name|mPorts
index|[
name|indexToAdd
index|]
operator|->
name|attach
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|mPorts
operator|.
name|append
argument_list|(
operator|new
name|QOpenWFDPort
argument_list|(
name|this
argument_list|,
name|id
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|int
name|indexToDelete
init|=
operator|-
literal|1
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mPorts
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|mPorts
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|portId
argument_list|()
operator|==
name|id
condition|)
block|{
name|indexToDelete
operator|=
name|i
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|indexToDelete
operator|>=
literal|0
condition|)
block|{
name|QOpenWFDPort
modifier|*
name|portToDelete
init|=
name|mPorts
operator|.
name|at
argument_list|(
name|indexToDelete
argument_list|)
decl_stmt|;
name|mPorts
operator|.
name|removeAt
argument_list|(
name|indexToDelete
argument_list|)
expr_stmt|;
operator|delete
name|portToDelete
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|handlePipelineBindSourceComplete
name|void
name|QOpenWFDDevice
operator|::
name|handlePipelineBindSourceComplete
parameter_list|()
block|{
name|mWaitingForBindSourceEvent
operator|=
literal|false
expr_stmt|;
name|WFDint
name|overflow
init|=
name|wfdGetEventAttribi
argument_list|(
name|mDevice
argument_list|,
name|mEvent
argument_list|,
name|WFD_EVENT_PIPELINE_BIND_QUEUE_OVERFLOW
argument_list|)
decl_stmt|;
if|if
condition|(
name|overflow
operator|==
name|WFD_TRUE
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"PIPELINE_BIND_QUEUE_OVERFLOW event occurred"
expr_stmt|;
block|}
name|WFDint
name|pipelineId
init|=
name|wfdGetEventAttribi
argument_list|(
name|mDevice
argument_list|,
name|mEvent
argument_list|,
name|WFD_EVENT_PIPELINE_BIND_PIPELINE_ID
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mPorts
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|pipelineId
operator|!=
name|WFD_INVALID_PIPELINE_ID
operator|&&
name|mUsedPipelines
operator|.
name|contains
argument_list|(
name|pipelineId
argument_list|)
condition|)
block|{
name|QOpenWFDPort
modifier|*
name|port
init|=
name|mUsedPipelines
operator|.
name|value
argument_list|(
name|pipelineId
argument_list|)
decl_stmt|;
name|port
operator|->
name|screen
argument_list|()
operator|->
name|pipelineBindSourceComplete
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function
end_unit
