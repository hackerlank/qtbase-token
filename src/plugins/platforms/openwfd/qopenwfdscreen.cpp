begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenwfdscreen.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdport.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdoutputbuffer.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_constructor
DECL|function|QOpenWFDScreen
name|QOpenWFDScreen
operator|::
name|QOpenWFDScreen
parameter_list|(
name|QOpenWFDPort
modifier|*
name|port
parameter_list|)
member_init_list|:
name|mPort
argument_list|(
name|port
argument_list|)
member_init_list|,
name|mFbo
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mOutputBuffers
argument_list|(
name|BUFFER_NUM
argument_list|)
member_init_list|,
name|mCurrentRenderBufferIndex
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mStagedBackBufferIndex
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|mCommitedBackBufferIndex
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|mBackBufferIndex
argument_list|(
operator|-
literal|1
argument_list|)
block|{
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Information of screen %p:\n"
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  width..........: %d\n"
argument_list|,
name|port
operator|->
name|pixelSize
argument_list|()
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  height.........: %d\n"
argument_list|,
name|port
operator|->
name|pixelSize
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  physical width.: %f\n"
argument_list|,
name|port
operator|->
name|physicalSize
argument_list|()
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  physical height: %f\n"
argument_list|,
name|port
operator|->
name|physicalSize
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|EGLDisplay
name|display
init|=
name|mPort
operator|->
name|device
argument_list|()
operator|->
name|eglDisplay
argument_list|()
decl_stmt|;
name|EGLContext
name|context
init|=
name|mPort
operator|->
name|device
argument_list|()
operator|->
name|eglContext
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|eglMakeCurrent
argument_list|(
name|display
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|context
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"screen: eglMakeCurrent FAILED"
expr_stmt|;
block|}
name|glGenFramebuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|mFbo
argument_list|)
expr_stmt|;
name|glBindFramebuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|mFbo
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
name|mOutputBuffers
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|mOutputBuffers
index|[
name|i
index|]
operator|=
operator|new
name|QOpenWFDOutputBuffer
argument_list|(
name|mPort
operator|->
name|pixelSize
argument_list|()
argument_list|,
name|mPort
argument_list|)
expr_stmt|;
block|}
name|mStagedBackBufferIndex
operator|=
name|mOutputBuffers
operator|.
name|size
argument_list|()
operator|-
literal|1
expr_stmt|;
name|mOutputBuffers
index|[
name|mStagedBackBufferIndex
index|]
operator|->
name|setAvailable
argument_list|(
literal|false
argument_list|)
expr_stmt|;
empty_stmt|;
name|commitStagedOutputBuffer
argument_list|()
expr_stmt|;
name|mOutputBuffers
operator|.
name|at
argument_list|(
name|mCurrentRenderBufferIndex
argument_list|)
operator|->
name|bindToCurrentFbo
argument_list|()
expr_stmt|;
if|if
condition|(
name|mPort
operator|->
name|device
argument_list|()
operator|->
name|isDeviceInitializedAndCommited
argument_list|()
condition|)
block|{
name|mPort
operator|->
name|device
argument_list|()
operator|->
name|commit
argument_list|(
name|WFD_COMMIT_ENTIRE_PORT
argument_list|,
name|mPort
operator|->
name|handle
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QOpenWFDScreen
name|QOpenWFDScreen
operator|::
name|~
name|QOpenWFDScreen
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mOutputBuffers
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
operator|delete
name|mOutputBuffers
index|[
name|i
index|]
expr_stmt|;
block|}
name|glDeleteFramebuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|mFbo
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|geometry
name|QRect
name|QOpenWFDScreen
operator|::
name|geometry
parameter_list|()
specifier|const
block|{
return|return
name|QRect
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|mPort
operator|->
name|pixelSize
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|depth
name|int
name|QOpenWFDScreen
operator|::
name|depth
parameter_list|()
specifier|const
block|{
return|return
literal|32
return|;
block|}
end_function
begin_function
DECL|function|format
name|QImage
operator|::
name|Format
name|QOpenWFDScreen
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|QImage
operator|::
name|Format_RGB32
return|;
block|}
end_function
begin_function
DECL|function|physicalSize
name|QSizeF
name|QOpenWFDScreen
operator|::
name|physicalSize
parameter_list|()
specifier|const
block|{
return|return
name|mPort
operator|->
name|physicalSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|port
name|QOpenWFDPort
modifier|*
name|QOpenWFDScreen
operator|::
name|port
parameter_list|()
specifier|const
block|{
return|return
name|mPort
return|;
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QOpenWFDScreen
operator|::
name|swapBuffers
parameter_list|()
block|{
name|glFlush
argument_list|()
expr_stmt|;
name|setStagedBackBuffer
argument_list|(
name|mCurrentRenderBufferIndex
argument_list|)
expr_stmt|;
name|mCurrentRenderBufferIndex
operator|=
name|nextAvailableRenderBuffer
argument_list|()
expr_stmt|;
name|bindFramebuffer
argument_list|()
expr_stmt|;
name|mOutputBuffers
operator|.
name|at
argument_list|(
name|mCurrentRenderBufferIndex
argument_list|)
operator|->
name|bindToCurrentFbo
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bindFramebuffer
name|void
name|QOpenWFDScreen
operator|::
name|bindFramebuffer
parameter_list|()
block|{
name|glBindFramebuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|mFbo
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setStagedBackBuffer
name|void
name|QOpenWFDScreen
operator|::
name|setStagedBackBuffer
parameter_list|(
name|int
name|bufferIndex
parameter_list|)
block|{
if|if
condition|(
name|mStagedBackBufferIndex
operator|>=
literal|0
condition|)
block|{
name|mOutputBuffers
index|[
name|mStagedBackBufferIndex
index|]
operator|->
name|setAvailable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
name|mOutputBuffers
index|[
name|bufferIndex
index|]
operator|->
name|setAvailable
argument_list|(
literal|false
argument_list|)
expr_stmt|;
empty_stmt|;
name|mStagedBackBufferIndex
operator|=
name|bufferIndex
expr_stmt|;
if|if
condition|(
name|mCommitedBackBufferIndex
operator|<
literal|0
condition|)
block|{
name|commitStagedOutputBuffer
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|commitStagedOutputBuffer
name|void
name|QOpenWFDScreen
operator|::
name|commitStagedOutputBuffer
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|mStagedBackBufferIndex
operator|>=
literal|0
argument_list|)
expr_stmt|;
name|wfdBindSourceToPipeline
argument_list|(
name|mPort
operator|->
name|device
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|,
name|mPort
operator|->
name|pipeline
argument_list|()
argument_list|,
name|mOutputBuffers
operator|.
name|at
argument_list|(
name|mStagedBackBufferIndex
argument_list|)
operator|->
name|wfdSource
argument_list|()
argument_list|,
name|WFD_TRANSITION_AT_VSYNC
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mPort
operator|->
name|device
argument_list|()
operator|->
name|commit
argument_list|(
name|WFD_COMMIT_PIPELINE
argument_list|,
name|mPort
operator|->
name|pipeline
argument_list|()
argument_list|)
expr_stmt|;
name|mCommitedBackBufferIndex
operator|=
name|mStagedBackBufferIndex
expr_stmt|;
name|mStagedBackBufferIndex
operator|=
operator|-
literal|1
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nextAvailableRenderBuffer
name|int
name|QOpenWFDScreen
operator|::
name|nextAvailableRenderBuffer
parameter_list|()
specifier|const
block|{
while|while
condition|(
literal|true
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mOutputBuffers
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
name|mOutputBuffers
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|isAvailable
argument_list|()
condition|)
block|{
return|return
name|i
return|;
block|}
block|}
name|mPort
operator|->
name|device
argument_list|()
operator|->
name|waitForPipelineBindSourceCompleteEvent
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|pipelineBindSourceComplete
name|void
name|QOpenWFDScreen
operator|::
name|pipelineBindSourceComplete
parameter_list|()
block|{
if|if
condition|(
name|mBackBufferIndex
operator|>=
literal|0
condition|)
block|{
name|mOutputBuffers
index|[
name|mBackBufferIndex
index|]
operator|->
name|setAvailable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
name|mBackBufferIndex
operator|=
name|mCommitedBackBufferIndex
expr_stmt|;
name|mCommitedBackBufferIndex
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|mStagedBackBufferIndex
operator|>=
literal|0
condition|)
block|{
name|commitStagedOutputBuffer
argument_list|()
expr_stmt|;
block|}
block|}
end_function
end_unit
