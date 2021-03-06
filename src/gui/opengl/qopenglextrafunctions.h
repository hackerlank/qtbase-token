begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLEXTRAFUNCTIONS_H
end_ifndef
begin_define
DECL|macro|QOPENGLEXTRAFUNCTIONS_H
define|#
directive|define
name|QOPENGLEXTRAFUNCTIONS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|<QtGui/qopenglfunctions.h>
end_include
begin_comment
comment|// MemoryBarrier is a macro on some architectures on Windows
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_pragma
pragma|#
directive|pragma
name|push_macro
name|(
literal|"MemoryBarrier"
name|)
end_pragma
begin_undef
DECL|macro|MemoryBarrier
undef|#
directive|undef
name|MemoryBarrier
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLExtraFunctionsPrivate
name|class
name|QOpenGLExtraFunctionsPrivate
decl_stmt|;
end_decl_stmt
begin_undef
DECL|macro|glReadBuffer
undef|#
directive|undef
name|glReadBuffer
end_undef
begin_undef
DECL|macro|glDrawRangeElements
undef|#
directive|undef
name|glDrawRangeElements
end_undef
begin_undef
DECL|macro|glTexImage3D
undef|#
directive|undef
name|glTexImage3D
end_undef
begin_undef
DECL|macro|glTexSubImage3D
undef|#
directive|undef
name|glTexSubImage3D
end_undef
begin_undef
DECL|macro|glCopyTexSubImage3D
undef|#
directive|undef
name|glCopyTexSubImage3D
end_undef
begin_undef
DECL|macro|glCompressedTexImage3D
undef|#
directive|undef
name|glCompressedTexImage3D
end_undef
begin_undef
DECL|macro|glCompressedTexSubImage3D
undef|#
directive|undef
name|glCompressedTexSubImage3D
end_undef
begin_undef
DECL|macro|glGenQueries
undef|#
directive|undef
name|glGenQueries
end_undef
begin_undef
DECL|macro|glDeleteQueries
undef|#
directive|undef
name|glDeleteQueries
end_undef
begin_undef
DECL|macro|glIsQuery
undef|#
directive|undef
name|glIsQuery
end_undef
begin_undef
DECL|macro|glBeginQuery
undef|#
directive|undef
name|glBeginQuery
end_undef
begin_undef
DECL|macro|glEndQuery
undef|#
directive|undef
name|glEndQuery
end_undef
begin_undef
DECL|macro|glGetQueryiv
undef|#
directive|undef
name|glGetQueryiv
end_undef
begin_undef
DECL|macro|glGetQueryObjectuiv
undef|#
directive|undef
name|glGetQueryObjectuiv
end_undef
begin_undef
DECL|macro|glUnmapBuffer
undef|#
directive|undef
name|glUnmapBuffer
end_undef
begin_undef
DECL|macro|glGetBufferPointerv
undef|#
directive|undef
name|glGetBufferPointerv
end_undef
begin_undef
DECL|macro|glDrawBuffers
undef|#
directive|undef
name|glDrawBuffers
end_undef
begin_undef
DECL|macro|glUniformMatrix2x3fv
undef|#
directive|undef
name|glUniformMatrix2x3fv
end_undef
begin_undef
DECL|macro|glUniformMatrix3x2fv
undef|#
directive|undef
name|glUniformMatrix3x2fv
end_undef
begin_undef
DECL|macro|glUniformMatrix2x4fv
undef|#
directive|undef
name|glUniformMatrix2x4fv
end_undef
begin_undef
DECL|macro|glUniformMatrix4x2fv
undef|#
directive|undef
name|glUniformMatrix4x2fv
end_undef
begin_undef
DECL|macro|glUniformMatrix3x4fv
undef|#
directive|undef
name|glUniformMatrix3x4fv
end_undef
begin_undef
DECL|macro|glUniformMatrix4x3fv
undef|#
directive|undef
name|glUniformMatrix4x3fv
end_undef
begin_undef
DECL|macro|glBlitFramebuffer
undef|#
directive|undef
name|glBlitFramebuffer
end_undef
begin_undef
DECL|macro|glRenderbufferStorageMultisample
undef|#
directive|undef
name|glRenderbufferStorageMultisample
end_undef
begin_undef
DECL|macro|glFramebufferTextureLayer
undef|#
directive|undef
name|glFramebufferTextureLayer
end_undef
begin_undef
DECL|macro|glMapBufferRange
undef|#
directive|undef
name|glMapBufferRange
end_undef
begin_undef
DECL|macro|glFlushMappedBufferRange
undef|#
directive|undef
name|glFlushMappedBufferRange
end_undef
begin_undef
DECL|macro|glBindVertexArray
undef|#
directive|undef
name|glBindVertexArray
end_undef
begin_undef
DECL|macro|glDeleteVertexArrays
undef|#
directive|undef
name|glDeleteVertexArrays
end_undef
begin_undef
DECL|macro|glGenVertexArrays
undef|#
directive|undef
name|glGenVertexArrays
end_undef
begin_undef
DECL|macro|glIsVertexArray
undef|#
directive|undef
name|glIsVertexArray
end_undef
begin_undef
DECL|macro|glGetIntegeri_v
undef|#
directive|undef
name|glGetIntegeri_v
end_undef
begin_undef
DECL|macro|glBeginTransformFeedback
undef|#
directive|undef
name|glBeginTransformFeedback
end_undef
begin_undef
DECL|macro|glEndTransformFeedback
undef|#
directive|undef
name|glEndTransformFeedback
end_undef
begin_undef
DECL|macro|glBindBufferRange
undef|#
directive|undef
name|glBindBufferRange
end_undef
begin_undef
DECL|macro|glBindBufferBase
undef|#
directive|undef
name|glBindBufferBase
end_undef
begin_undef
DECL|macro|glTransformFeedbackVaryings
undef|#
directive|undef
name|glTransformFeedbackVaryings
end_undef
begin_undef
DECL|macro|glGetTransformFeedbackVarying
undef|#
directive|undef
name|glGetTransformFeedbackVarying
end_undef
begin_undef
DECL|macro|glVertexAttribIPointer
undef|#
directive|undef
name|glVertexAttribIPointer
end_undef
begin_undef
DECL|macro|glGetVertexAttribIiv
undef|#
directive|undef
name|glGetVertexAttribIiv
end_undef
begin_undef
DECL|macro|glGetVertexAttribIuiv
undef|#
directive|undef
name|glGetVertexAttribIuiv
end_undef
begin_undef
DECL|macro|glVertexAttribI4i
undef|#
directive|undef
name|glVertexAttribI4i
end_undef
begin_undef
DECL|macro|glVertexAttribI4ui
undef|#
directive|undef
name|glVertexAttribI4ui
end_undef
begin_undef
DECL|macro|glVertexAttribI4iv
undef|#
directive|undef
name|glVertexAttribI4iv
end_undef
begin_undef
DECL|macro|glVertexAttribI4uiv
undef|#
directive|undef
name|glVertexAttribI4uiv
end_undef
begin_undef
DECL|macro|glGetUniformuiv
undef|#
directive|undef
name|glGetUniformuiv
end_undef
begin_undef
DECL|macro|glGetFragDataLocation
undef|#
directive|undef
name|glGetFragDataLocation
end_undef
begin_undef
DECL|macro|glUniform1ui
undef|#
directive|undef
name|glUniform1ui
end_undef
begin_undef
DECL|macro|glUniform2ui
undef|#
directive|undef
name|glUniform2ui
end_undef
begin_undef
DECL|macro|glUniform3ui
undef|#
directive|undef
name|glUniform3ui
end_undef
begin_undef
DECL|macro|glUniform4ui
undef|#
directive|undef
name|glUniform4ui
end_undef
begin_undef
DECL|macro|glUniform1uiv
undef|#
directive|undef
name|glUniform1uiv
end_undef
begin_undef
DECL|macro|glUniform2uiv
undef|#
directive|undef
name|glUniform2uiv
end_undef
begin_undef
DECL|macro|glUniform3uiv
undef|#
directive|undef
name|glUniform3uiv
end_undef
begin_undef
DECL|macro|glUniform4uiv
undef|#
directive|undef
name|glUniform4uiv
end_undef
begin_undef
DECL|macro|glClearBufferiv
undef|#
directive|undef
name|glClearBufferiv
end_undef
begin_undef
DECL|macro|glClearBufferuiv
undef|#
directive|undef
name|glClearBufferuiv
end_undef
begin_undef
DECL|macro|glClearBufferfv
undef|#
directive|undef
name|glClearBufferfv
end_undef
begin_undef
DECL|macro|glClearBufferfi
undef|#
directive|undef
name|glClearBufferfi
end_undef
begin_undef
DECL|macro|glGetStringi
undef|#
directive|undef
name|glGetStringi
end_undef
begin_undef
DECL|macro|glCopyBufferSubData
undef|#
directive|undef
name|glCopyBufferSubData
end_undef
begin_undef
DECL|macro|glGetUniformIndices
undef|#
directive|undef
name|glGetUniformIndices
end_undef
begin_undef
DECL|macro|glGetActiveUniformsiv
undef|#
directive|undef
name|glGetActiveUniformsiv
end_undef
begin_undef
DECL|macro|glGetUniformBlockIndex
undef|#
directive|undef
name|glGetUniformBlockIndex
end_undef
begin_undef
DECL|macro|glGetActiveUniformBlockiv
undef|#
directive|undef
name|glGetActiveUniformBlockiv
end_undef
begin_undef
DECL|macro|glGetActiveUniformBlockName
undef|#
directive|undef
name|glGetActiveUniformBlockName
end_undef
begin_undef
DECL|macro|glUniformBlockBinding
undef|#
directive|undef
name|glUniformBlockBinding
end_undef
begin_undef
DECL|macro|glDrawArraysInstanced
undef|#
directive|undef
name|glDrawArraysInstanced
end_undef
begin_undef
DECL|macro|glDrawElementsInstanced
undef|#
directive|undef
name|glDrawElementsInstanced
end_undef
begin_undef
DECL|macro|glFenceSync
undef|#
directive|undef
name|glFenceSync
end_undef
begin_undef
DECL|macro|glIsSync
undef|#
directive|undef
name|glIsSync
end_undef
begin_undef
DECL|macro|glDeleteSync
undef|#
directive|undef
name|glDeleteSync
end_undef
begin_undef
DECL|macro|glClientWaitSync
undef|#
directive|undef
name|glClientWaitSync
end_undef
begin_undef
DECL|macro|glWaitSync
undef|#
directive|undef
name|glWaitSync
end_undef
begin_undef
DECL|macro|glGetInteger64v
undef|#
directive|undef
name|glGetInteger64v
end_undef
begin_undef
DECL|macro|glGetSynciv
undef|#
directive|undef
name|glGetSynciv
end_undef
begin_undef
DECL|macro|glGetInteger64i_v
undef|#
directive|undef
name|glGetInteger64i_v
end_undef
begin_undef
DECL|macro|glGetBufferParameteri64v
undef|#
directive|undef
name|glGetBufferParameteri64v
end_undef
begin_undef
DECL|macro|glGenSamplers
undef|#
directive|undef
name|glGenSamplers
end_undef
begin_undef
DECL|macro|glDeleteSamplers
undef|#
directive|undef
name|glDeleteSamplers
end_undef
begin_undef
DECL|macro|glIsSampler
undef|#
directive|undef
name|glIsSampler
end_undef
begin_undef
DECL|macro|glBindSampler
undef|#
directive|undef
name|glBindSampler
end_undef
begin_undef
DECL|macro|glSamplerParameteri
undef|#
directive|undef
name|glSamplerParameteri
end_undef
begin_undef
DECL|macro|glSamplerParameteriv
undef|#
directive|undef
name|glSamplerParameteriv
end_undef
begin_undef
DECL|macro|glSamplerParameterf
undef|#
directive|undef
name|glSamplerParameterf
end_undef
begin_undef
DECL|macro|glSamplerParameterfv
undef|#
directive|undef
name|glSamplerParameterfv
end_undef
begin_undef
DECL|macro|glGetSamplerParameteriv
undef|#
directive|undef
name|glGetSamplerParameteriv
end_undef
begin_undef
DECL|macro|glGetSamplerParameterfv
undef|#
directive|undef
name|glGetSamplerParameterfv
end_undef
begin_undef
DECL|macro|glVertexAttribDivisor
undef|#
directive|undef
name|glVertexAttribDivisor
end_undef
begin_undef
DECL|macro|glBindTransformFeedback
undef|#
directive|undef
name|glBindTransformFeedback
end_undef
begin_undef
DECL|macro|glDeleteTransformFeedbacks
undef|#
directive|undef
name|glDeleteTransformFeedbacks
end_undef
begin_undef
DECL|macro|glGenTransformFeedbacks
undef|#
directive|undef
name|glGenTransformFeedbacks
end_undef
begin_undef
DECL|macro|glIsTransformFeedback
undef|#
directive|undef
name|glIsTransformFeedback
end_undef
begin_undef
DECL|macro|glPauseTransformFeedback
undef|#
directive|undef
name|glPauseTransformFeedback
end_undef
begin_undef
DECL|macro|glResumeTransformFeedback
undef|#
directive|undef
name|glResumeTransformFeedback
end_undef
begin_undef
DECL|macro|glGetProgramBinary
undef|#
directive|undef
name|glGetProgramBinary
end_undef
begin_undef
DECL|macro|glProgramBinary
undef|#
directive|undef
name|glProgramBinary
end_undef
begin_undef
DECL|macro|glProgramParameteri
undef|#
directive|undef
name|glProgramParameteri
end_undef
begin_undef
DECL|macro|glInvalidateFramebuffer
undef|#
directive|undef
name|glInvalidateFramebuffer
end_undef
begin_undef
DECL|macro|glInvalidateSubFramebuffer
undef|#
directive|undef
name|glInvalidateSubFramebuffer
end_undef
begin_undef
DECL|macro|glTexStorage2D
undef|#
directive|undef
name|glTexStorage2D
end_undef
begin_undef
DECL|macro|glTexStorage3D
undef|#
directive|undef
name|glTexStorage3D
end_undef
begin_undef
DECL|macro|glGetInternalformativ
undef|#
directive|undef
name|glGetInternalformativ
end_undef
begin_undef
DECL|macro|glDispatchCompute
undef|#
directive|undef
name|glDispatchCompute
end_undef
begin_undef
DECL|macro|glDispatchComputeIndirect
undef|#
directive|undef
name|glDispatchComputeIndirect
end_undef
begin_undef
DECL|macro|glDrawArraysIndirect
undef|#
directive|undef
name|glDrawArraysIndirect
end_undef
begin_undef
DECL|macro|glDrawElementsIndirect
undef|#
directive|undef
name|glDrawElementsIndirect
end_undef
begin_undef
DECL|macro|glFramebufferParameteri
undef|#
directive|undef
name|glFramebufferParameteri
end_undef
begin_undef
DECL|macro|glGetFramebufferParameteriv
undef|#
directive|undef
name|glGetFramebufferParameteriv
end_undef
begin_undef
DECL|macro|glGetProgramInterfaceiv
undef|#
directive|undef
name|glGetProgramInterfaceiv
end_undef
begin_undef
DECL|macro|glGetProgramResourceIndex
undef|#
directive|undef
name|glGetProgramResourceIndex
end_undef
begin_undef
DECL|macro|glGetProgramResourceName
undef|#
directive|undef
name|glGetProgramResourceName
end_undef
begin_undef
DECL|macro|glGetProgramResourceiv
undef|#
directive|undef
name|glGetProgramResourceiv
end_undef
begin_undef
DECL|macro|glGetProgramResourceLocation
undef|#
directive|undef
name|glGetProgramResourceLocation
end_undef
begin_undef
DECL|macro|glUseProgramStages
undef|#
directive|undef
name|glUseProgramStages
end_undef
begin_undef
DECL|macro|glActiveShaderProgram
undef|#
directive|undef
name|glActiveShaderProgram
end_undef
begin_undef
DECL|macro|glCreateShaderProgramv
undef|#
directive|undef
name|glCreateShaderProgramv
end_undef
begin_undef
DECL|macro|glBindProgramPipeline
undef|#
directive|undef
name|glBindProgramPipeline
end_undef
begin_undef
DECL|macro|glDeleteProgramPipelines
undef|#
directive|undef
name|glDeleteProgramPipelines
end_undef
begin_undef
DECL|macro|glGenProgramPipelines
undef|#
directive|undef
name|glGenProgramPipelines
end_undef
begin_undef
DECL|macro|glIsProgramPipeline
undef|#
directive|undef
name|glIsProgramPipeline
end_undef
begin_undef
DECL|macro|glGetProgramPipelineiv
undef|#
directive|undef
name|glGetProgramPipelineiv
end_undef
begin_undef
DECL|macro|glProgramUniform1i
undef|#
directive|undef
name|glProgramUniform1i
end_undef
begin_undef
DECL|macro|glProgramUniform2i
undef|#
directive|undef
name|glProgramUniform2i
end_undef
begin_undef
DECL|macro|glProgramUniform3i
undef|#
directive|undef
name|glProgramUniform3i
end_undef
begin_undef
DECL|macro|glProgramUniform4i
undef|#
directive|undef
name|glProgramUniform4i
end_undef
begin_undef
DECL|macro|glProgramUniform1ui
undef|#
directive|undef
name|glProgramUniform1ui
end_undef
begin_undef
DECL|macro|glProgramUniform2ui
undef|#
directive|undef
name|glProgramUniform2ui
end_undef
begin_undef
DECL|macro|glProgramUniform3ui
undef|#
directive|undef
name|glProgramUniform3ui
end_undef
begin_undef
DECL|macro|glProgramUniform4ui
undef|#
directive|undef
name|glProgramUniform4ui
end_undef
begin_undef
DECL|macro|glProgramUniform1f
undef|#
directive|undef
name|glProgramUniform1f
end_undef
begin_undef
DECL|macro|glProgramUniform2f
undef|#
directive|undef
name|glProgramUniform2f
end_undef
begin_undef
DECL|macro|glProgramUniform3f
undef|#
directive|undef
name|glProgramUniform3f
end_undef
begin_undef
DECL|macro|glProgramUniform4f
undef|#
directive|undef
name|glProgramUniform4f
end_undef
begin_undef
DECL|macro|glProgramUniform1iv
undef|#
directive|undef
name|glProgramUniform1iv
end_undef
begin_undef
DECL|macro|glProgramUniform2iv
undef|#
directive|undef
name|glProgramUniform2iv
end_undef
begin_undef
DECL|macro|glProgramUniform3iv
undef|#
directive|undef
name|glProgramUniform3iv
end_undef
begin_undef
DECL|macro|glProgramUniform4iv
undef|#
directive|undef
name|glProgramUniform4iv
end_undef
begin_undef
DECL|macro|glProgramUniform1uiv
undef|#
directive|undef
name|glProgramUniform1uiv
end_undef
begin_undef
DECL|macro|glProgramUniform2uiv
undef|#
directive|undef
name|glProgramUniform2uiv
end_undef
begin_undef
DECL|macro|glProgramUniform3uiv
undef|#
directive|undef
name|glProgramUniform3uiv
end_undef
begin_undef
DECL|macro|glProgramUniform4uiv
undef|#
directive|undef
name|glProgramUniform4uiv
end_undef
begin_undef
DECL|macro|glProgramUniform1fv
undef|#
directive|undef
name|glProgramUniform1fv
end_undef
begin_undef
DECL|macro|glProgramUniform2fv
undef|#
directive|undef
name|glProgramUniform2fv
end_undef
begin_undef
DECL|macro|glProgramUniform3fv
undef|#
directive|undef
name|glProgramUniform3fv
end_undef
begin_undef
DECL|macro|glProgramUniform4fv
undef|#
directive|undef
name|glProgramUniform4fv
end_undef
begin_undef
DECL|macro|glProgramUniformMatrix2fv
undef|#
directive|undef
name|glProgramUniformMatrix2fv
end_undef
begin_undef
DECL|macro|glProgramUniformMatrix3fv
undef|#
directive|undef
name|glProgramUniformMatrix3fv
end_undef
begin_undef
DECL|macro|glProgramUniformMatrix4fv
undef|#
directive|undef
name|glProgramUniformMatrix4fv
end_undef
begin_undef
DECL|macro|glProgramUniformMatrix2x3fv
undef|#
directive|undef
name|glProgramUniformMatrix2x3fv
end_undef
begin_undef
DECL|macro|glProgramUniformMatrix3x2fv
undef|#
directive|undef
name|glProgramUniformMatrix3x2fv
end_undef
begin_undef
DECL|macro|glProgramUniformMatrix2x4fv
undef|#
directive|undef
name|glProgramUniformMatrix2x4fv
end_undef
begin_undef
DECL|macro|glProgramUniformMatrix4x2fv
undef|#
directive|undef
name|glProgramUniformMatrix4x2fv
end_undef
begin_undef
DECL|macro|glProgramUniformMatrix3x4fv
undef|#
directive|undef
name|glProgramUniformMatrix3x4fv
end_undef
begin_undef
DECL|macro|glProgramUniformMatrix4x3fv
undef|#
directive|undef
name|glProgramUniformMatrix4x3fv
end_undef
begin_undef
DECL|macro|glValidateProgramPipeline
undef|#
directive|undef
name|glValidateProgramPipeline
end_undef
begin_undef
DECL|macro|glGetProgramPipelineInfoLog
undef|#
directive|undef
name|glGetProgramPipelineInfoLog
end_undef
begin_undef
DECL|macro|glBindImageTexture
undef|#
directive|undef
name|glBindImageTexture
end_undef
begin_undef
DECL|macro|glGetBooleani_v
undef|#
directive|undef
name|glGetBooleani_v
end_undef
begin_undef
DECL|macro|glMemoryBarrier
undef|#
directive|undef
name|glMemoryBarrier
end_undef
begin_undef
DECL|macro|glMemoryBarrierByRegion
undef|#
directive|undef
name|glMemoryBarrierByRegion
end_undef
begin_undef
DECL|macro|glTexStorage2DMultisample
undef|#
directive|undef
name|glTexStorage2DMultisample
end_undef
begin_undef
DECL|macro|glGetMultisamplefv
undef|#
directive|undef
name|glGetMultisamplefv
end_undef
begin_undef
DECL|macro|glSampleMaski
undef|#
directive|undef
name|glSampleMaski
end_undef
begin_undef
DECL|macro|glGetTexLevelParameteriv
undef|#
directive|undef
name|glGetTexLevelParameteriv
end_undef
begin_undef
DECL|macro|glGetTexLevelParameterfv
undef|#
directive|undef
name|glGetTexLevelParameterfv
end_undef
begin_undef
DECL|macro|glBindVertexBuffer
undef|#
directive|undef
name|glBindVertexBuffer
end_undef
begin_undef
DECL|macro|glVertexAttribFormat
undef|#
directive|undef
name|glVertexAttribFormat
end_undef
begin_undef
DECL|macro|glVertexAttribIFormat
undef|#
directive|undef
name|glVertexAttribIFormat
end_undef
begin_undef
DECL|macro|glVertexAttribBinding
undef|#
directive|undef
name|glVertexAttribBinding
end_undef
begin_undef
DECL|macro|glVertexBindingDivisor
undef|#
directive|undef
name|glVertexBindingDivisor
end_undef
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLExtraFunctions
range|:
name|public
name|QOpenGLFunctions
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QOpenGLExtraFunctions
argument_list|)
name|public
operator|:
name|QOpenGLExtraFunctions
argument_list|()
block|;
name|QOpenGLExtraFunctions
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
operator|~
name|QOpenGLExtraFunctions
argument_list|()
block|{}
comment|// GLES3
name|void
name|glReadBuffer
argument_list|(
argument|GLenum mode
argument_list|)
block|;
name|void
name|glDrawRangeElements
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLuint start
argument_list|,
argument|GLuint end
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLenum type
argument_list|,
argument|const void *indices
argument_list|)
block|;
name|void
name|glTexImage3D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLint border
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|void
name|glTexSubImage3D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint zoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|void
name|glCopyTexSubImage3D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint zoffset
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|void
name|glCompressedTexImage3D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLint border
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const void *data
argument_list|)
block|;
name|void
name|glCompressedTexSubImage3D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint zoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLenum format
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const void *data
argument_list|)
block|;
name|void
name|glGenQueries
argument_list|(
argument|GLsizei n
argument_list|,
argument|GLuint *ids
argument_list|)
block|;
name|void
name|glDeleteQueries
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint *ids
argument_list|)
block|;
name|GLboolean
name|glIsQuery
argument_list|(
argument|GLuint id
argument_list|)
block|;
name|void
name|glBeginQuery
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint id
argument_list|)
block|;
name|void
name|glEndQuery
argument_list|(
argument|GLenum target
argument_list|)
block|;
name|void
name|glGetQueryiv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint *params
argument_list|)
block|;
name|void
name|glGetQueryObjectuiv
argument_list|(
argument|GLuint id
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLuint *params
argument_list|)
block|;
name|GLboolean
name|glUnmapBuffer
argument_list|(
argument|GLenum target
argument_list|)
block|;
name|void
name|glGetBufferPointerv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|void **params
argument_list|)
block|;
name|void
name|glDrawBuffers
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLenum *bufs
argument_list|)
block|;
name|void
name|glUniformMatrix2x3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glUniformMatrix3x2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glUniformMatrix2x4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glUniformMatrix4x2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glUniformMatrix3x4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glUniformMatrix4x3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glBlitFramebuffer
argument_list|(
argument|GLint srcX0
argument_list|,
argument|GLint srcY0
argument_list|,
argument|GLint srcX1
argument_list|,
argument|GLint srcY1
argument_list|,
argument|GLint dstX0
argument_list|,
argument|GLint dstY0
argument_list|,
argument|GLint dstX1
argument_list|,
argument|GLint dstY1
argument_list|,
argument|GLbitfield mask
argument_list|,
argument|GLenum filter
argument_list|)
block|;
name|void
name|glRenderbufferStorageMultisample
argument_list|(
argument|GLenum target
argument_list|,
argument|GLsizei samples
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|void
name|glFramebufferTextureLayer
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum attachment
argument_list|,
argument|GLuint texture
argument_list|,
argument|GLint level
argument_list|,
argument|GLint layer
argument_list|)
block|;
name|void
operator|*
name|glMapBufferRange
argument_list|(
argument|GLenum target
argument_list|,
argument|GLintptr offset
argument_list|,
argument|GLsizeiptr length
argument_list|,
argument|GLbitfield access
argument_list|)
block|;
name|void
name|glFlushMappedBufferRange
argument_list|(
argument|GLenum target
argument_list|,
argument|GLintptr offset
argument_list|,
argument|GLsizeiptr length
argument_list|)
block|;
name|void
name|glBindVertexArray
argument_list|(
argument|GLuint array
argument_list|)
block|;
name|void
name|glDeleteVertexArrays
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint *arrays
argument_list|)
block|;
name|void
name|glGenVertexArrays
argument_list|(
argument|GLsizei n
argument_list|,
argument|GLuint *arrays
argument_list|)
block|;
name|GLboolean
name|glIsVertexArray
argument_list|(
argument|GLuint array
argument_list|)
block|;
name|void
name|glGetIntegeri_v
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint index
argument_list|,
argument|GLint *data
argument_list|)
block|;
name|void
name|glBeginTransformFeedback
argument_list|(
argument|GLenum primitiveMode
argument_list|)
block|;
name|void
name|glEndTransformFeedback
argument_list|(
name|void
argument_list|)
block|;
name|void
name|glBindBufferRange
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint index
argument_list|,
argument|GLuint buffer
argument_list|,
argument|GLintptr offset
argument_list|,
argument|GLsizeiptr size
argument_list|)
block|;
name|void
name|glBindBufferBase
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint index
argument_list|,
argument|GLuint buffer
argument_list|)
block|;
name|void
name|glTransformFeedbackVaryings
argument_list|(
argument|GLuint program
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLchar *const*varyings
argument_list|,
argument|GLenum bufferMode
argument_list|)
block|;
name|void
name|glGetTransformFeedbackVarying
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint index
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei *length
argument_list|,
argument|GLsizei *size
argument_list|,
argument|GLenum *type
argument_list|,
argument|GLchar *name
argument_list|)
block|;
name|void
name|glVertexAttribIPointer
argument_list|(
argument|GLuint index
argument_list|,
argument|GLint size
argument_list|,
argument|GLenum type
argument_list|,
argument|GLsizei stride
argument_list|,
argument|const void *pointer
argument_list|)
block|;
name|void
name|glGetVertexAttribIiv
argument_list|(
argument|GLuint index
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint *params
argument_list|)
block|;
name|void
name|glGetVertexAttribIuiv
argument_list|(
argument|GLuint index
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLuint *params
argument_list|)
block|;
name|void
name|glVertexAttribI4i
argument_list|(
argument|GLuint index
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLint z
argument_list|,
argument|GLint w
argument_list|)
block|;
name|void
name|glVertexAttribI4ui
argument_list|(
argument|GLuint index
argument_list|,
argument|GLuint x
argument_list|,
argument|GLuint y
argument_list|,
argument|GLuint z
argument_list|,
argument|GLuint w
argument_list|)
block|;
name|void
name|glVertexAttribI4iv
argument_list|(
argument|GLuint index
argument_list|,
argument|const GLint *v
argument_list|)
block|;
name|void
name|glVertexAttribI4uiv
argument_list|(
argument|GLuint index
argument_list|,
argument|const GLuint *v
argument_list|)
block|;
name|void
name|glGetUniformuiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLuint *params
argument_list|)
block|;
name|GLint
name|glGetFragDataLocation
argument_list|(
argument|GLuint program
argument_list|,
argument|const GLchar *name
argument_list|)
block|;
name|void
name|glUniform1ui
argument_list|(
argument|GLint location
argument_list|,
argument|GLuint v0
argument_list|)
block|;
name|void
name|glUniform2ui
argument_list|(
argument|GLint location
argument_list|,
argument|GLuint v0
argument_list|,
argument|GLuint v1
argument_list|)
block|;
name|void
name|glUniform3ui
argument_list|(
argument|GLint location
argument_list|,
argument|GLuint v0
argument_list|,
argument|GLuint v1
argument_list|,
argument|GLuint v2
argument_list|)
block|;
name|void
name|glUniform4ui
argument_list|(
argument|GLint location
argument_list|,
argument|GLuint v0
argument_list|,
argument|GLuint v1
argument_list|,
argument|GLuint v2
argument_list|,
argument|GLuint v3
argument_list|)
block|;
name|void
name|glUniform1uiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint *value
argument_list|)
block|;
name|void
name|glUniform2uiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint *value
argument_list|)
block|;
name|void
name|glUniform3uiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint *value
argument_list|)
block|;
name|void
name|glUniform4uiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint *value
argument_list|)
block|;
name|void
name|glClearBufferiv
argument_list|(
argument|GLenum buffer
argument_list|,
argument|GLint drawbuffer
argument_list|,
argument|const GLint *value
argument_list|)
block|;
name|void
name|glClearBufferuiv
argument_list|(
argument|GLenum buffer
argument_list|,
argument|GLint drawbuffer
argument_list|,
argument|const GLuint *value
argument_list|)
block|;
name|void
name|glClearBufferfv
argument_list|(
argument|GLenum buffer
argument_list|,
argument|GLint drawbuffer
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glClearBufferfi
argument_list|(
argument|GLenum buffer
argument_list|,
argument|GLint drawbuffer
argument_list|,
argument|GLfloat depth
argument_list|,
argument|GLint stencil
argument_list|)
block|;
specifier|const
name|GLubyte
operator|*
name|glGetStringi
argument_list|(
argument|GLenum name
argument_list|,
argument|GLuint index
argument_list|)
block|;
name|void
name|glCopyBufferSubData
argument_list|(
argument|GLenum readTarget
argument_list|,
argument|GLenum writeTarget
argument_list|,
argument|GLintptr readOffset
argument_list|,
argument|GLintptr writeOffset
argument_list|,
argument|GLsizeiptr size
argument_list|)
block|;
name|void
name|glGetUniformIndices
argument_list|(
argument|GLuint program
argument_list|,
argument|GLsizei uniformCount
argument_list|,
argument|const GLchar *const*uniformNames
argument_list|,
argument|GLuint *uniformIndices
argument_list|)
block|;
name|void
name|glGetActiveUniformsiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLsizei uniformCount
argument_list|,
argument|const GLuint *uniformIndices
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint *params
argument_list|)
block|;
name|GLuint
name|glGetUniformBlockIndex
argument_list|(
argument|GLuint program
argument_list|,
argument|const GLchar *uniformBlockName
argument_list|)
block|;
name|void
name|glGetActiveUniformBlockiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint uniformBlockIndex
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint *params
argument_list|)
block|;
name|void
name|glGetActiveUniformBlockName
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint uniformBlockIndex
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei *length
argument_list|,
argument|GLchar *uniformBlockName
argument_list|)
block|;
name|void
name|glUniformBlockBinding
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint uniformBlockIndex
argument_list|,
argument|GLuint uniformBlockBinding
argument_list|)
block|;
name|void
name|glDrawArraysInstanced
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLint first
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instancecount
argument_list|)
block|;
name|void
name|glDrawElementsInstanced
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLenum type
argument_list|,
argument|const void *indices
argument_list|,
argument|GLsizei instancecount
argument_list|)
block|;
name|GLsync
name|glFenceSync
argument_list|(
argument|GLenum condition
argument_list|,
argument|GLbitfield flags
argument_list|)
block|;
name|GLboolean
name|glIsSync
argument_list|(
argument|GLsync sync
argument_list|)
block|;
name|void
name|glDeleteSync
argument_list|(
argument|GLsync sync
argument_list|)
block|;
name|GLenum
name|glClientWaitSync
argument_list|(
argument|GLsync sync
argument_list|,
argument|GLbitfield flags
argument_list|,
argument|GLuint64 timeout
argument_list|)
block|;
name|void
name|glWaitSync
argument_list|(
argument|GLsync sync
argument_list|,
argument|GLbitfield flags
argument_list|,
argument|GLuint64 timeout
argument_list|)
block|;
name|void
name|glGetInteger64v
argument_list|(
argument|GLenum pname
argument_list|,
argument|GLint64 *data
argument_list|)
block|;
name|void
name|glGetSynciv
argument_list|(
argument|GLsync sync
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei *length
argument_list|,
argument|GLint *values
argument_list|)
block|;
name|void
name|glGetInteger64i_v
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint index
argument_list|,
argument|GLint64 *data
argument_list|)
block|;
name|void
name|glGetBufferParameteri64v
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint64 *params
argument_list|)
block|;
name|void
name|glGenSamplers
argument_list|(
argument|GLsizei count
argument_list|,
argument|GLuint *samplers
argument_list|)
block|;
name|void
name|glDeleteSamplers
argument_list|(
argument|GLsizei count
argument_list|,
argument|const GLuint *samplers
argument_list|)
block|;
name|GLboolean
name|glIsSampler
argument_list|(
argument|GLuint sampler
argument_list|)
block|;
name|void
name|glBindSampler
argument_list|(
argument|GLuint unit
argument_list|,
argument|GLuint sampler
argument_list|)
block|;
name|void
name|glSamplerParameteri
argument_list|(
argument|GLuint sampler
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint param
argument_list|)
block|;
name|void
name|glSamplerParameteriv
argument_list|(
argument|GLuint sampler
argument_list|,
argument|GLenum pname
argument_list|,
argument|const GLint *param
argument_list|)
block|;
name|void
name|glSamplerParameterf
argument_list|(
argument|GLuint sampler
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLfloat param
argument_list|)
block|;
name|void
name|glSamplerParameterfv
argument_list|(
argument|GLuint sampler
argument_list|,
argument|GLenum pname
argument_list|,
argument|const GLfloat *param
argument_list|)
block|;
name|void
name|glGetSamplerParameteriv
argument_list|(
argument|GLuint sampler
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint *params
argument_list|)
block|;
name|void
name|glGetSamplerParameterfv
argument_list|(
argument|GLuint sampler
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLfloat *params
argument_list|)
block|;
name|void
name|glVertexAttribDivisor
argument_list|(
argument|GLuint index
argument_list|,
argument|GLuint divisor
argument_list|)
block|;
name|void
name|glBindTransformFeedback
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint id
argument_list|)
block|;
name|void
name|glDeleteTransformFeedbacks
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint *ids
argument_list|)
block|;
name|void
name|glGenTransformFeedbacks
argument_list|(
argument|GLsizei n
argument_list|,
argument|GLuint *ids
argument_list|)
block|;
name|GLboolean
name|glIsTransformFeedback
argument_list|(
argument|GLuint id
argument_list|)
block|;
name|void
name|glPauseTransformFeedback
argument_list|(
name|void
argument_list|)
block|;
name|void
name|glResumeTransformFeedback
argument_list|(
name|void
argument_list|)
block|;
name|void
name|glGetProgramBinary
argument_list|(
argument|GLuint program
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei *length
argument_list|,
argument|GLenum *binaryFormat
argument_list|,
argument|void *binary
argument_list|)
block|;
name|void
name|glProgramBinary
argument_list|(
argument|GLuint program
argument_list|,
argument|GLenum binaryFormat
argument_list|,
argument|const void *binary
argument_list|,
argument|GLsizei length
argument_list|)
block|;
name|void
name|glProgramParameteri
argument_list|(
argument|GLuint program
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint value
argument_list|)
block|;
name|void
name|glInvalidateFramebuffer
argument_list|(
argument|GLenum target
argument_list|,
argument|GLsizei numAttachments
argument_list|,
argument|const GLenum *attachments
argument_list|)
block|;
name|void
name|glInvalidateSubFramebuffer
argument_list|(
argument|GLenum target
argument_list|,
argument|GLsizei numAttachments
argument_list|,
argument|const GLenum *attachments
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|void
name|glTexStorage2D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLsizei levels
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|void
name|glTexStorage3D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLsizei levels
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|)
block|;
name|void
name|glGetInternalformativ
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLint *params
argument_list|)
block|;
comment|// GLES 3.1
name|void
name|glDispatchCompute
argument_list|(
argument|GLuint num_groups_x
argument_list|,
argument|GLuint num_groups_y
argument_list|,
argument|GLuint num_groups_z
argument_list|)
block|;
name|void
name|glDispatchComputeIndirect
argument_list|(
argument|GLintptr indirect
argument_list|)
block|;
name|void
name|glDrawArraysIndirect
argument_list|(
argument|GLenum mode
argument_list|,
argument|const void *indirect
argument_list|)
block|;
name|void
name|glDrawElementsIndirect
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLenum type
argument_list|,
argument|const void *indirect
argument_list|)
block|;
name|void
name|glFramebufferParameteri
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint param
argument_list|)
block|;
name|void
name|glGetFramebufferParameteriv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint *params
argument_list|)
block|;
name|void
name|glGetProgramInterfaceiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLenum programInterface
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint *params
argument_list|)
block|;
name|GLuint
name|glGetProgramResourceIndex
argument_list|(
argument|GLuint program
argument_list|,
argument|GLenum programInterface
argument_list|,
argument|const GLchar *name
argument_list|)
block|;
name|void
name|glGetProgramResourceName
argument_list|(
argument|GLuint program
argument_list|,
argument|GLenum programInterface
argument_list|,
argument|GLuint index
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei *length
argument_list|,
argument|GLchar *name
argument_list|)
block|;
name|void
name|glGetProgramResourceiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLenum programInterface
argument_list|,
argument|GLuint index
argument_list|,
argument|GLsizei propCount
argument_list|,
argument|const GLenum *props
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei *length
argument_list|,
argument|GLint *params
argument_list|)
block|;
name|GLint
name|glGetProgramResourceLocation
argument_list|(
argument|GLuint program
argument_list|,
argument|GLenum programInterface
argument_list|,
argument|const GLchar *name
argument_list|)
block|;
name|void
name|glUseProgramStages
argument_list|(
argument|GLuint pipeline
argument_list|,
argument|GLbitfield stages
argument_list|,
argument|GLuint program
argument_list|)
block|;
name|void
name|glActiveShaderProgram
argument_list|(
argument|GLuint pipeline
argument_list|,
argument|GLuint program
argument_list|)
block|;
name|GLuint
name|glCreateShaderProgramv
argument_list|(
argument|GLenum type
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLchar *const*strings
argument_list|)
block|;
name|void
name|glBindProgramPipeline
argument_list|(
argument|GLuint pipeline
argument_list|)
block|;
name|void
name|glDeleteProgramPipelines
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint *pipelines
argument_list|)
block|;
name|void
name|glGenProgramPipelines
argument_list|(
argument|GLsizei n
argument_list|,
argument|GLuint *pipelines
argument_list|)
block|;
name|GLboolean
name|glIsProgramPipeline
argument_list|(
argument|GLuint pipeline
argument_list|)
block|;
name|void
name|glGetProgramPipelineiv
argument_list|(
argument|GLuint pipeline
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint *params
argument_list|)
block|;
name|void
name|glProgramUniform1i
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLint v0
argument_list|)
block|;
name|void
name|glProgramUniform2i
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLint v0
argument_list|,
argument|GLint v1
argument_list|)
block|;
name|void
name|glProgramUniform3i
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLint v0
argument_list|,
argument|GLint v1
argument_list|,
argument|GLint v2
argument_list|)
block|;
name|void
name|glProgramUniform4i
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLint v0
argument_list|,
argument|GLint v1
argument_list|,
argument|GLint v2
argument_list|,
argument|GLint v3
argument_list|)
block|;
name|void
name|glProgramUniform1ui
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLuint v0
argument_list|)
block|;
name|void
name|glProgramUniform2ui
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLuint v0
argument_list|,
argument|GLuint v1
argument_list|)
block|;
name|void
name|glProgramUniform3ui
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLuint v0
argument_list|,
argument|GLuint v1
argument_list|,
argument|GLuint v2
argument_list|)
block|;
name|void
name|glProgramUniform4ui
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLuint v0
argument_list|,
argument|GLuint v1
argument_list|,
argument|GLuint v2
argument_list|,
argument|GLuint v3
argument_list|)
block|;
name|void
name|glProgramUniform1f
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLfloat v0
argument_list|)
block|;
name|void
name|glProgramUniform2f
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLfloat v0
argument_list|,
argument|GLfloat v1
argument_list|)
block|;
name|void
name|glProgramUniform3f
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLfloat v0
argument_list|,
argument|GLfloat v1
argument_list|,
argument|GLfloat v2
argument_list|)
block|;
name|void
name|glProgramUniform4f
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLfloat v0
argument_list|,
argument|GLfloat v1
argument_list|,
argument|GLfloat v2
argument_list|,
argument|GLfloat v3
argument_list|)
block|;
name|void
name|glProgramUniform1iv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *value
argument_list|)
block|;
name|void
name|glProgramUniform2iv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *value
argument_list|)
block|;
name|void
name|glProgramUniform3iv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *value
argument_list|)
block|;
name|void
name|glProgramUniform4iv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *value
argument_list|)
block|;
name|void
name|glProgramUniform1uiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint *value
argument_list|)
block|;
name|void
name|glProgramUniform2uiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint *value
argument_list|)
block|;
name|void
name|glProgramUniform3uiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint *value
argument_list|)
block|;
name|void
name|glProgramUniform4uiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint *value
argument_list|)
block|;
name|void
name|glProgramUniform1fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glProgramUniform2fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glProgramUniform3fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glProgramUniform4fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glProgramUniformMatrix2fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glProgramUniformMatrix3fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glProgramUniformMatrix4fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glProgramUniformMatrix2x3fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glProgramUniformMatrix3x2fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glProgramUniformMatrix2x4fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glProgramUniformMatrix4x2fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glProgramUniformMatrix3x4fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glProgramUniformMatrix4x3fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|glValidateProgramPipeline
argument_list|(
argument|GLuint pipeline
argument_list|)
block|;
name|void
name|glGetProgramPipelineInfoLog
argument_list|(
argument|GLuint pipeline
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei *length
argument_list|,
argument|GLchar *infoLog
argument_list|)
block|;
name|void
name|glBindImageTexture
argument_list|(
argument|GLuint unit
argument_list|,
argument|GLuint texture
argument_list|,
argument|GLint level
argument_list|,
argument|GLboolean layered
argument_list|,
argument|GLint layer
argument_list|,
argument|GLenum access
argument_list|,
argument|GLenum format
argument_list|)
block|;
name|void
name|glGetBooleani_v
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint index
argument_list|,
argument|GLboolean *data
argument_list|)
block|;
name|void
name|glMemoryBarrier
argument_list|(
argument|GLbitfield barriers
argument_list|)
block|;
name|void
name|glMemoryBarrierByRegion
argument_list|(
argument|GLbitfield barriers
argument_list|)
block|;
name|void
name|glTexStorage2DMultisample
argument_list|(
argument|GLenum target
argument_list|,
argument|GLsizei samples
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLboolean fixedsamplelocations
argument_list|)
block|;
name|void
name|glGetMultisamplefv
argument_list|(
argument|GLenum pname
argument_list|,
argument|GLuint index
argument_list|,
argument|GLfloat *val
argument_list|)
block|;
name|void
name|glSampleMaski
argument_list|(
argument|GLuint maskNumber
argument_list|,
argument|GLbitfield mask
argument_list|)
block|;
name|void
name|glGetTexLevelParameteriv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint *params
argument_list|)
block|;
name|void
name|glGetTexLevelParameterfv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLfloat *params
argument_list|)
block|;
name|void
name|glBindVertexBuffer
argument_list|(
argument|GLuint bindingindex
argument_list|,
argument|GLuint buffer
argument_list|,
argument|GLintptr offset
argument_list|,
argument|GLsizei stride
argument_list|)
block|;
name|void
name|glVertexAttribFormat
argument_list|(
argument|GLuint attribindex
argument_list|,
argument|GLint size
argument_list|,
argument|GLenum type
argument_list|,
argument|GLboolean normalized
argument_list|,
argument|GLuint relativeoffset
argument_list|)
block|;
name|void
name|glVertexAttribIFormat
argument_list|(
argument|GLuint attribindex
argument_list|,
argument|GLint size
argument_list|,
argument|GLenum type
argument_list|,
argument|GLuint relativeoffset
argument_list|)
block|;
name|void
name|glVertexAttribBinding
argument_list|(
argument|GLuint attribindex
argument_list|,
argument|GLuint bindingindex
argument_list|)
block|;
name|void
name|glVertexBindingDivisor
argument_list|(
argument|GLuint bindingindex
argument_list|,
argument|GLuint divisor
argument_list|)
block|;
name|private
operator|:
specifier|static
name|bool
name|isInitialized
argument_list|(
argument|const QOpenGLExtraFunctionsPrivate *d
argument_list|)
block|{
return|return
name|d
operator|!=
name|Q_NULLPTR
return|;
block|}
expr|}
block|;
DECL|macro|QT_OPENGL_DECLARE_FUNCTIONS
define|#
directive|define
name|QT_OPENGL_DECLARE_FUNCTIONS
parameter_list|(
name|ret
parameter_list|,
name|name
parameter_list|,
name|args
parameter_list|)
define|\
value|ret (QOPENGLF_APIENTRYP name)args;
DECL|macro|QT_OPENGL_COUNT_FUNCTIONS
define|#
directive|define
name|QT_OPENGL_COUNT_FUNCTIONS
parameter_list|(
name|ret
parameter_list|,
name|name
parameter_list|,
name|args
parameter_list|)
value|+1
DECL|macro|QT_OPENGL_DECLARE
define|#
directive|define
name|QT_OPENGL_DECLARE
parameter_list|(
name|FUNCTIONS
parameter_list|)
define|\
value|public: \     struct Functions { \         FUNCTIONS(QT_OPENGL_DECLARE_FUNCTIONS) \     }; \     union { \         QFunctionPointer functions[FUNCTIONS(QT_OPENGL_COUNT_FUNCTIONS)]; \         Functions f; \     }; \ private: \     void init(QOpenGLContext *context);
name|class
name|QOpenGLExtraFunctionsPrivate
operator|:
name|public
name|QOpenGLFunctionsPrivate
block|{
name|public
operator|:
name|QOpenGLExtraFunctionsPrivate
argument_list|(
name|QOpenGLContext
operator|*
name|ctx
argument_list|)
block|;
comment|// GLES3
DECL|macro|QT_OPENGL_EXTRA_FUNCTIONS
define|#
directive|define
name|QT_OPENGL_EXTRA_FUNCTIONS
parameter_list|(
name|F
parameter_list|)
define|\
value|F(void, ReadBuffer, (GLenum mode)) \     F(void, DrawRangeElements, (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices)) \     F(void, TexImage3D, (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels)) \     F(void, TexSubImage3D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels)) \     F(void, CopyTexSubImage3D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)) \     F(void, CompressedTexImage3D, (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data)) \     F(void, CompressedTexSubImage3D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data)) \     F(void, GenQueries, (GLsizei n, GLuint *ids)) \     F(void, DeleteQueries, (GLsizei n, const GLuint *ids)) \     F(GLboolean, IsQuery, (GLuint id)) \     F(void, BeginQuery, (GLenum target, GLuint id)) \     F(void, EndQuery, (GLenum target)) \     F(void, GetQueryiv, (GLenum target, GLenum pname, GLint *params)) \     F(void, GetQueryObjectuiv, (GLuint id, GLenum pname, GLuint *params)) \     F(GLboolean, UnmapBuffer, (GLenum target)) \     F(void, GetBufferPointerv, (GLenum target, GLenum pname, void **params)) \     F(void, DrawBuffers, (GLsizei n, const GLenum *bufs)) \     F(void, UniformMatrix2x3fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \     F(void, UniformMatrix3x2fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \     F(void, UniformMatrix2x4fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \     F(void, UniformMatrix4x2fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \     F(void, UniformMatrix3x4fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \     F(void, UniformMatrix4x3fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \     F(void, BlitFramebuffer, (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)) \     F(void, RenderbufferStorageMultisample, (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)) \     F(void, FramebufferTextureLayer, (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)) \     F(void *,MapBufferRange, (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)) \     F(void, FlushMappedBufferRange, (GLenum target, GLintptr offset, GLsizeiptr length)) \     F(void, BindVertexArray, (GLuint array)) \     F(void, DeleteVertexArrays, (GLsizei n, const GLuint *arrays)) \     F(void, GenVertexArrays, (GLsizei n, GLuint *arrays)) \     F(GLboolean, IsVertexArray, (GLuint array)) \     F(void, GetIntegeri_v, (GLenum target, GLuint index, GLint *data)) \     F(void, BeginTransformFeedback, (GLenum primitiveMode)) \     F(void, EndTransformFeedback, (void)) \     F(void, BindBufferRange, (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)) \     F(void, BindBufferBase, (GLenum target, GLuint index, GLuint buffer)) \     F(void, TransformFeedbackVaryings, (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode)) \     F(void, GetTransformFeedbackVarying, (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name)) \     F(void, VertexAttribIPointer, (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer)) \     F(void, GetVertexAttribIiv, (GLuint index, GLenum pname, GLint *params)) \     F(void, GetVertexAttribIuiv, (GLuint index, GLenum pname, GLuint *params)) \     F(void, VertexAttribI4i, (GLuint index, GLint x, GLint y, GLint z, GLint w)) \     F(void, VertexAttribI4ui, (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)) \     F(void, VertexAttribI4iv, (GLuint index, const GLint *v)) \     F(void, VertexAttribI4uiv, (GLuint index, const GLuint *v)) \     F(void, GetUniformuiv, (GLuint program, GLint location, GLuint *params)) \     F(GLint, GetFragDataLocation, (GLuint program, const GLchar *name)) \     F(void, Uniform1ui, (GLint location, GLuint v0)) \     F(void, Uniform2ui, (GLint location, GLuint v0, GLuint v1)) \     F(void, Uniform3ui, (GLint location, GLuint v0, GLuint v1, GLuint v2)) \     F(void, Uniform4ui, (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)) \     F(void, Uniform1uiv, (GLint location, GLsizei count, const GLuint *value)) \     F(void, Uniform2uiv, (GLint location, GLsizei count, const GLuint *value)) \     F(void, Uniform3uiv, (GLint location, GLsizei count, const GLuint *value)) \     F(void, Uniform4uiv, (GLint location, GLsizei count, const GLuint *value)) \     F(void, ClearBufferiv, (GLenum buffer, GLint drawbuffer, const GLint *value)) \     F(void, ClearBufferuiv, (GLenum buffer, GLint drawbuffer, const GLuint *value)) \     F(void, ClearBufferfv, (GLenum buffer, GLint drawbuffer, const GLfloat *value)) \     F(void, ClearBufferfi, (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)) \     F(const GLubyte *, GetStringi, (GLenum name, GLuint index)) \     F(void, CopyBufferSubData, (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)) \     F(void, GetUniformIndices, (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices)) \     F(void, GetActiveUniformsiv, (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params)) \     F(GLuint, GetUniformBlockIndex, (GLuint program, const GLchar *uniformBlockName)) \     F(void, GetActiveUniformBlockiv, (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params)) \     F(void, GetActiveUniformBlockName, (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName)) \     F(void, UniformBlockBinding, (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)) \     F(void, DrawArraysInstanced, (GLenum mode, GLint first, GLsizei count, GLsizei instancecount)) \     F(void, DrawElementsInstanced, (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount)) \     F(GLsync, FenceSync, (GLenum condition, GLbitfield flags)) \     F(GLboolean, IsSync, (GLsync sync)) \     F(void, DeleteSync, (GLsync sync)) \     F(GLenum, ClientWaitSync, (GLsync sync, GLbitfield flags, GLuint64 timeout)) \     F(void, WaitSync, (GLsync sync, GLbitfield flags, GLuint64 timeout)) \     F(void, GetInteger64v, (GLenum pname, GLint64 *data)) \     F(void, GetSynciv, (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values)) \     F(void, GetInteger64i_v, (GLenum target, GLuint index, GLint64 *data)) \     F(void, GetBufferParameteri64v, (GLenum target, GLenum pname, GLint64 *params)) \     F(void, GenSamplers, (GLsizei count, GLuint *samplers)) \     F(void, DeleteSamplers, (GLsizei count, const GLuint *samplers)) \     F(GLboolean, IsSampler, (GLuint sampler)) \     F(void, BindSampler, (GLuint unit, GLuint sampler)) \     F(void, SamplerParameteri, (GLuint sampler, GLenum pname, GLint param)) \     F(void, SamplerParameteriv, (GLuint sampler, GLenum pname, const GLint *param)) \     F(void, SamplerParameterf, (GLuint sampler, GLenum pname, GLfloat param)) \     F(void, SamplerParameterfv, (GLuint sampler, GLenum pname, const GLfloat *param)) \     F(void, GetSamplerParameteriv, (GLuint sampler, GLenum pname, GLint *params)) \     F(void, GetSamplerParameterfv, (GLuint sampler, GLenum pname, GLfloat *params)) \     F(void, VertexAttribDivisor, (GLuint index, GLuint divisor)) \     F(void, BindTransformFeedback, (GLenum target, GLuint id)) \     F(void, DeleteTransformFeedbacks, (GLsizei n, const GLuint *ids)) \     F(void, GenTransformFeedbacks, (GLsizei n, GLuint *ids)) \     F(GLboolean, IsTransformFeedback, (GLuint id)) \     F(void, PauseTransformFeedback, (void)) \     F(void, ResumeTransformFeedback, (void)) \     F(void, GetProgramBinary, (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary)) \     F(void, ProgramBinary, (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length)) \     F(void, ProgramParameteri, (GLuint program, GLenum pname, GLint value)) \     F(void, InvalidateFramebuffer, (GLenum target, GLsizei numAttachments, const GLenum *attachments)) \     F(void, InvalidateSubFramebuffer, (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height)) \     F(void, TexStorage2D, (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)) \     F(void, TexStorage3D, (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)) \     F(void, GetInternalformativ, (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params)) \     F(void, DispatchCompute, (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z)) \     F(void, DispatchComputeIndirect, (GLintptr indirect)) \     F(void, DrawArraysIndirect, (GLenum mode, const void *indirect)) \     F(void, DrawElementsIndirect, (GLenum mode, GLenum type, const void *indirect)) \     F(void, FramebufferParameteri, (GLenum target, GLenum pname, GLint param)) \     F(void, GetFramebufferParameteriv, (GLenum target, GLenum pname, GLint *params)) \     F(void, GetProgramInterfaceiv, (GLuint program, GLenum programInterface, GLenum pname, GLint *params)) \     F(GLuint, GetProgramResourceIndex, (GLuint program, GLenum programInterface, const GLchar *name)) \     F(void, GetProgramResourceName, (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name)) \     F(void, GetProgramResourceiv, (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params)) \     F(GLint, GetProgramResourceLocation, (GLuint program, GLenum programInterface, const GLchar *name)) \     F(void, UseProgramStages, (GLuint pipeline, GLbitfield stages, GLuint program)) \     F(void, ActiveShaderProgram, (GLuint pipeline, GLuint program)) \     F(GLuint, CreateShaderProgramv, (GLenum type, GLsizei count, const GLchar *const*strings)) \     F(void, BindProgramPipeline, (GLuint pipeline)) \     F(void, DeleteProgramPipelines, (GLsizei n, const GLuint *pipelines)) \     F(void, GenProgramPipelines, (GLsizei n, GLuint *pipelines)) \     F(GLboolean, IsProgramPipeline, (GLuint pipeline)) \     F(void, GetProgramPipelineiv, (GLuint pipeline, GLenum pname, GLint *params)) \     F(void, ProgramUniform1i, (GLuint program, GLint location, GLint v0)) \     F(void, ProgramUniform2i, (GLuint program, GLint location, GLint v0, GLint v1)) \     F(void, ProgramUniform3i, (GLuint program, GLint location, GLint v0, GLint v1, GLint v2)) \     F(void, ProgramUniform4i, (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)) \     F(void, ProgramUniform1ui, (GLuint program, GLint location, GLuint v0)) \     F(void, ProgramUniform2ui, (GLuint program, GLint location, GLuint v0, GLuint v1)) \     F(void, ProgramUniform3ui, (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2)) \     F(void, ProgramUniform4ui, (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)) \     F(void, ProgramUniform1f, (GLuint program, GLint location, GLfloat v0)) \     F(void, ProgramUniform2f, (GLuint program, GLint location, GLfloat v0, GLfloat v1)) \     F(void, ProgramUniform3f, (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)) \     F(void, ProgramUniform4f, (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)) \     F(void, ProgramUniform1iv, (GLuint program, GLint location, GLsizei count, const GLint *value)) \     F(void, ProgramUniform2iv, (GLuint program, GLint location, GLsizei count, const GLint *value)) \     F(void, ProgramUniform3iv, (GLuint program, GLint location, GLsizei count, const GLint *value)) \     F(void, ProgramUniform4iv, (GLuint program, GLint location, GLsizei count, const GLint *value)) \     F(void, ProgramUniform1uiv, (GLuint program, GLint location, GLsizei count, const GLuint *value)) \     F(void, ProgramUniform2uiv, (GLuint program, GLint location, GLsizei count, const GLuint *value)) \     F(void, ProgramUniform3uiv, (GLuint program, GLint location, GLsizei count, const GLuint *value)) \     F(void, ProgramUniform4uiv, (GLuint program, GLint location, GLsizei count, const GLuint *value)) \     F(void, ProgramUniform1fv, (GLuint program, GLint location, GLsizei count, const GLfloat *value)) \     F(void, ProgramUniform2fv, (GLuint program, GLint location, GLsizei count, const GLfloat *value)) \     F(void, ProgramUniform3fv, (GLuint program, GLint location, GLsizei count, const GLfloat *value)) \     F(void, ProgramUniform4fv, (GLuint program, GLint location, GLsizei count, const GLfloat *value)) \     F(void, ProgramUniformMatrix2fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \     F(void, ProgramUniformMatrix3fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \     F(void, ProgramUniformMatrix4fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \     F(void, ProgramUniformMatrix2x3fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \     F(void, ProgramUniformMatrix3x2fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \     F(void, ProgramUniformMatrix2x4fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \     F(void, ProgramUniformMatrix4x2fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \     F(void, ProgramUniformMatrix3x4fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \     F(void, ProgramUniformMatrix4x3fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \     F(void, ValidateProgramPipeline, (GLuint pipeline)) \     F(void, GetProgramPipelineInfoLog, (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog)) \     F(void, BindImageTexture, (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format)) \     F(void, GetBooleani_v, (GLenum target, GLuint index, GLboolean *data)) \     F(void, MemoryBarrier, (GLbitfield barriers)) \     F(void, MemoryBarrierByRegion, (GLbitfield barriers)) \     F(void, TexStorage2DMultisample, (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)) \     F(void, GetMultisamplefv, (GLenum pname, GLuint index, GLfloat *val)) \     F(void, SampleMaski, (GLuint maskNumber, GLbitfield mask)) \     F(void, GetTexLevelParameteriv, (GLenum target, GLint level, GLenum pname, GLint *params)) \     F(void, GetTexLevelParameterfv, (GLenum target, GLint level, GLenum pname, GLfloat *params)) \     F(void, BindVertexBuffer, (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)) \     F(void, VertexAttribFormat, (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)) \     F(void, VertexAttribIFormat, (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)) \     F(void, VertexAttribBinding, (GLuint attribindex, GLuint bindingindex)) \     F(void, VertexBindingDivisor, (GLuint bindingindex, GLuint divisor)) \      QT_OPENGL_DECLARE(QT_OPENGL_EXTRA_FUNCTIONS)
block|}
block|;
comment|// GLES 3.0 and 3.1
DECL|function|glBeginQuery
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glBeginQuery
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint id
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|BeginQuery
argument_list|(
name|target
argument_list|,
name|id
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glBeginTransformFeedback
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glBeginTransformFeedback
argument_list|(
argument|GLenum primitiveMode
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|BeginTransformFeedback
argument_list|(
name|primitiveMode
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glBindBufferBase
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glBindBufferBase
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint index
argument_list|,
argument|GLuint buffer
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|BindBufferBase
argument_list|(
name|target
argument_list|,
name|index
argument_list|,
name|buffer
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glBindBufferRange
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glBindBufferRange
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint index
argument_list|,
argument|GLuint buffer
argument_list|,
argument|GLintptr offset
argument_list|,
argument|GLsizeiptr size
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|BindBufferRange
argument_list|(
name|target
argument_list|,
name|index
argument_list|,
name|buffer
argument_list|,
name|offset
argument_list|,
name|size
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glBindSampler
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glBindSampler
argument_list|(
argument|GLuint unit
argument_list|,
argument|GLuint sampler
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|BindSampler
argument_list|(
name|unit
argument_list|,
name|sampler
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glBindTransformFeedback
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glBindTransformFeedback
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint id
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|BindTransformFeedback
argument_list|(
name|target
argument_list|,
name|id
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glBindVertexArray
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glBindVertexArray
argument_list|(
argument|GLuint array
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|BindVertexArray
argument_list|(
name|array
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glBlitFramebuffer
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glBlitFramebuffer
argument_list|(
argument|GLint srcX0
argument_list|,
argument|GLint srcY0
argument_list|,
argument|GLint srcX1
argument_list|,
argument|GLint srcY1
argument_list|,
argument|GLint dstX0
argument_list|,
argument|GLint dstY0
argument_list|,
argument|GLint dstX1
argument_list|,
argument|GLint dstY1
argument_list|,
argument|GLbitfield mask
argument_list|,
argument|GLenum filter
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|BlitFramebuffer
argument_list|(
name|srcX0
argument_list|,
name|srcY0
argument_list|,
name|srcX1
argument_list|,
name|srcY1
argument_list|,
name|dstX0
argument_list|,
name|dstY0
argument_list|,
name|dstX1
argument_list|,
name|dstY1
argument_list|,
name|mask
argument_list|,
name|filter
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glClearBufferfi
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glClearBufferfi
argument_list|(
argument|GLenum buffer
argument_list|,
argument|GLint drawbuffer
argument_list|,
argument|GLfloat depth
argument_list|,
argument|GLint stencil
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ClearBufferfi
argument_list|(
name|buffer
argument_list|,
name|drawbuffer
argument_list|,
name|depth
argument_list|,
name|stencil
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glClearBufferfv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glClearBufferfv
argument_list|(
argument|GLenum buffer
argument_list|,
argument|GLint drawbuffer
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ClearBufferfv
argument_list|(
name|buffer
argument_list|,
name|drawbuffer
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glClearBufferiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glClearBufferiv
argument_list|(
argument|GLenum buffer
argument_list|,
argument|GLint drawbuffer
argument_list|,
argument|const GLint * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ClearBufferiv
argument_list|(
name|buffer
argument_list|,
name|drawbuffer
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glClearBufferuiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glClearBufferuiv
argument_list|(
argument|GLenum buffer
argument_list|,
argument|GLint drawbuffer
argument_list|,
argument|const GLuint * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ClearBufferuiv
argument_list|(
name|buffer
argument_list|,
name|drawbuffer
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glClientWaitSync
specifier|inline
name|GLenum
name|QOpenGLExtraFunctions
operator|::
name|glClientWaitSync
argument_list|(
argument|GLsync sync
argument_list|,
argument|GLbitfield flags
argument_list|,
argument|GLuint64 timeout
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|GLenum
name|result
operator|=
name|d
operator|->
name|f
operator|.
name|ClientWaitSync
argument_list|(
name|sync
argument_list|,
name|flags
argument_list|,
name|timeout
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glCompressedTexImage3D
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glCompressedTexImage3D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLint border
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const void * data
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|CompressedTexImage3D
argument_list|(
name|target
argument_list|,
name|level
argument_list|,
name|internalformat
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|depth
argument_list|,
name|border
argument_list|,
name|imageSize
argument_list|,
name|data
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glCompressedTexSubImage3D
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glCompressedTexSubImage3D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint zoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLenum format
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const void * data
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|CompressedTexSubImage3D
argument_list|(
name|target
argument_list|,
name|level
argument_list|,
name|xoffset
argument_list|,
name|yoffset
argument_list|,
name|zoffset
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|depth
argument_list|,
name|format
argument_list|,
name|imageSize
argument_list|,
name|data
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glCopyBufferSubData
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glCopyBufferSubData
argument_list|(
argument|GLenum readTarget
argument_list|,
argument|GLenum writeTarget
argument_list|,
argument|GLintptr readOffset
argument_list|,
argument|GLintptr writeOffset
argument_list|,
argument|GLsizeiptr size
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|CopyBufferSubData
argument_list|(
name|readTarget
argument_list|,
name|writeTarget
argument_list|,
name|readOffset
argument_list|,
name|writeOffset
argument_list|,
name|size
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glCopyTexSubImage3D
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glCopyTexSubImage3D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint zoffset
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|CopyTexSubImage3D
argument_list|(
name|target
argument_list|,
name|level
argument_list|,
name|xoffset
argument_list|,
name|yoffset
argument_list|,
name|zoffset
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glDeleteQueries
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glDeleteQueries
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint * ids
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|DeleteQueries
argument_list|(
name|n
argument_list|,
name|ids
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glDeleteSamplers
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glDeleteSamplers
argument_list|(
argument|GLsizei count
argument_list|,
argument|const GLuint * samplers
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|DeleteSamplers
argument_list|(
name|count
argument_list|,
name|samplers
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glDeleteSync
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glDeleteSync
argument_list|(
argument|GLsync sync
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|DeleteSync
argument_list|(
name|sync
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glDeleteTransformFeedbacks
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glDeleteTransformFeedbacks
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint * ids
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|DeleteTransformFeedbacks
argument_list|(
name|n
argument_list|,
name|ids
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glDeleteVertexArrays
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glDeleteVertexArrays
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint * arrays
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|DeleteVertexArrays
argument_list|(
name|n
argument_list|,
name|arrays
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glDrawArraysInstanced
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glDrawArraysInstanced
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLint first
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instancecount
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|DrawArraysInstanced
argument_list|(
name|mode
argument_list|,
name|first
argument_list|,
name|count
argument_list|,
name|instancecount
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glDrawBuffers
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glDrawBuffers
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLenum * bufs
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|DrawBuffers
argument_list|(
name|n
argument_list|,
name|bufs
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glDrawElementsInstanced
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glDrawElementsInstanced
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLenum type
argument_list|,
argument|const void * indices
argument_list|,
argument|GLsizei instancecount
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|DrawElementsInstanced
argument_list|(
name|mode
argument_list|,
name|count
argument_list|,
name|type
argument_list|,
name|indices
argument_list|,
name|instancecount
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glDrawRangeElements
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glDrawRangeElements
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLuint start
argument_list|,
argument|GLuint end
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLenum type
argument_list|,
argument|const void * indices
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|DrawRangeElements
argument_list|(
name|mode
argument_list|,
name|start
argument_list|,
name|end
argument_list|,
name|count
argument_list|,
name|type
argument_list|,
name|indices
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glEndQuery
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glEndQuery
argument_list|(
argument|GLenum target
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|EndQuery
argument_list|(
name|target
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glEndTransformFeedback
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glEndTransformFeedback
argument_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|EndTransformFeedback
argument_list|()
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glFenceSync
specifier|inline
name|GLsync
name|QOpenGLExtraFunctions
operator|::
name|glFenceSync
argument_list|(
argument|GLenum condition
argument_list|,
argument|GLbitfield flags
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|GLsync
name|result
operator|=
name|d
operator|->
name|f
operator|.
name|FenceSync
argument_list|(
name|condition
argument_list|,
name|flags
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glFlushMappedBufferRange
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glFlushMappedBufferRange
argument_list|(
argument|GLenum target
argument_list|,
argument|GLintptr offset
argument_list|,
argument|GLsizeiptr length
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|FlushMappedBufferRange
argument_list|(
name|target
argument_list|,
name|offset
argument_list|,
name|length
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glFramebufferTextureLayer
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glFramebufferTextureLayer
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum attachment
argument_list|,
argument|GLuint texture
argument_list|,
argument|GLint level
argument_list|,
argument|GLint layer
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|FramebufferTextureLayer
argument_list|(
name|target
argument_list|,
name|attachment
argument_list|,
name|texture
argument_list|,
name|level
argument_list|,
name|layer
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGenQueries
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGenQueries
argument_list|(
argument|GLsizei n
argument_list|,
argument|GLuint* ids
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GenQueries
argument_list|(
name|n
argument_list|,
name|ids
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGenSamplers
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGenSamplers
argument_list|(
argument|GLsizei count
argument_list|,
argument|GLuint* samplers
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GenSamplers
argument_list|(
name|count
argument_list|,
name|samplers
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGenTransformFeedbacks
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGenTransformFeedbacks
argument_list|(
argument|GLsizei n
argument_list|,
argument|GLuint* ids
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GenTransformFeedbacks
argument_list|(
name|n
argument_list|,
name|ids
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGenVertexArrays
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGenVertexArrays
argument_list|(
argument|GLsizei n
argument_list|,
argument|GLuint* arrays
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GenVertexArrays
argument_list|(
name|n
argument_list|,
name|arrays
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetActiveUniformBlockName
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetActiveUniformBlockName
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint uniformBlockIndex
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei* length
argument_list|,
argument|GLchar* uniformBlockName
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetActiveUniformBlockName
argument_list|(
name|program
argument_list|,
name|uniformBlockIndex
argument_list|,
name|bufSize
argument_list|,
name|length
argument_list|,
name|uniformBlockName
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetActiveUniformBlockiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetActiveUniformBlockiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint uniformBlockIndex
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetActiveUniformBlockiv
argument_list|(
name|program
argument_list|,
name|uniformBlockIndex
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetActiveUniformsiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetActiveUniformsiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLsizei uniformCount
argument_list|,
argument|const GLuint * uniformIndices
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetActiveUniformsiv
argument_list|(
name|program
argument_list|,
name|uniformCount
argument_list|,
name|uniformIndices
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetBufferParameteri64v
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetBufferParameteri64v
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint64* params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetBufferParameteri64v
argument_list|(
name|target
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetBufferPointerv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetBufferPointerv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|void ** params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetBufferPointerv
argument_list|(
name|target
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetFragDataLocation
specifier|inline
name|GLint
name|QOpenGLExtraFunctions
operator|::
name|glGetFragDataLocation
argument_list|(
argument|GLuint program
argument_list|,
argument|const GLchar * name
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|GLint
name|result
operator|=
name|d
operator|->
name|f
operator|.
name|GetFragDataLocation
argument_list|(
name|program
argument_list|,
name|name
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glGetInteger64i_v
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetInteger64i_v
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint index
argument_list|,
argument|GLint64* data
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetInteger64i_v
argument_list|(
name|target
argument_list|,
name|index
argument_list|,
name|data
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetInteger64v
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetInteger64v
argument_list|(
argument|GLenum pname
argument_list|,
argument|GLint64* data
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetInteger64v
argument_list|(
name|pname
argument_list|,
name|data
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetIntegeri_v
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetIntegeri_v
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint index
argument_list|,
argument|GLint* data
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetIntegeri_v
argument_list|(
name|target
argument_list|,
name|index
argument_list|,
name|data
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetInternalformativ
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetInternalformativ
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLint* params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetInternalformativ
argument_list|(
name|target
argument_list|,
name|internalformat
argument_list|,
name|pname
argument_list|,
name|bufSize
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetProgramBinary
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetProgramBinary
argument_list|(
argument|GLuint program
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei* length
argument_list|,
argument|GLenum* binaryFormat
argument_list|,
argument|void * binary
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetProgramBinary
argument_list|(
name|program
argument_list|,
name|bufSize
argument_list|,
name|length
argument_list|,
name|binaryFormat
argument_list|,
name|binary
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetQueryObjectuiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetQueryObjectuiv
argument_list|(
argument|GLuint id
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLuint* params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetQueryObjectuiv
argument_list|(
name|id
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetQueryiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetQueryiv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetQueryiv
argument_list|(
name|target
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetSamplerParameterfv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetSamplerParameterfv
argument_list|(
argument|GLuint sampler
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLfloat* params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetSamplerParameterfv
argument_list|(
name|sampler
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetSamplerParameteriv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetSamplerParameteriv
argument_list|(
argument|GLuint sampler
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetSamplerParameteriv
argument_list|(
name|sampler
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetStringi
specifier|inline
specifier|const
name|GLubyte
operator|*
name|QOpenGLExtraFunctions
operator|::
name|glGetStringi
argument_list|(
argument|GLenum name
argument_list|,
argument|GLuint index
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
specifier|const
name|GLubyte
operator|*
name|result
operator|=
name|d
operator|->
name|f
operator|.
name|GetStringi
argument_list|(
name|name
argument_list|,
name|index
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glGetSynciv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetSynciv
argument_list|(
argument|GLsync sync
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei* length
argument_list|,
argument|GLint* values
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetSynciv
argument_list|(
name|sync
argument_list|,
name|pname
argument_list|,
name|bufSize
argument_list|,
name|length
argument_list|,
name|values
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetTransformFeedbackVarying
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetTransformFeedbackVarying
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint index
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei* length
argument_list|,
argument|GLsizei* size
argument_list|,
argument|GLenum* type
argument_list|,
argument|GLchar* name
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetTransformFeedbackVarying
argument_list|(
name|program
argument_list|,
name|index
argument_list|,
name|bufSize
argument_list|,
name|length
argument_list|,
name|size
argument_list|,
name|type
argument_list|,
name|name
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetUniformBlockIndex
specifier|inline
name|GLuint
name|QOpenGLExtraFunctions
operator|::
name|glGetUniformBlockIndex
argument_list|(
argument|GLuint program
argument_list|,
argument|const GLchar * uniformBlockName
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|GLuint
name|result
operator|=
name|d
operator|->
name|f
operator|.
name|GetUniformBlockIndex
argument_list|(
name|program
argument_list|,
name|uniformBlockName
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glGetUniformIndices
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetUniformIndices
argument_list|(
argument|GLuint program
argument_list|,
argument|GLsizei uniformCount
argument_list|,
argument|const GLchar *const* uniformNames
argument_list|,
argument|GLuint* uniformIndices
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetUniformIndices
argument_list|(
name|program
argument_list|,
name|uniformCount
argument_list|,
name|uniformNames
argument_list|,
name|uniformIndices
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetUniformuiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetUniformuiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLuint* params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetUniformuiv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetVertexAttribIiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetVertexAttribIiv
argument_list|(
argument|GLuint index
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetVertexAttribIiv
argument_list|(
name|index
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetVertexAttribIuiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetVertexAttribIuiv
argument_list|(
argument|GLuint index
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLuint* params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetVertexAttribIuiv
argument_list|(
name|index
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glInvalidateFramebuffer
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glInvalidateFramebuffer
argument_list|(
argument|GLenum target
argument_list|,
argument|GLsizei numAttachments
argument_list|,
argument|const GLenum * attachments
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|InvalidateFramebuffer
argument_list|(
name|target
argument_list|,
name|numAttachments
argument_list|,
name|attachments
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glInvalidateSubFramebuffer
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glInvalidateSubFramebuffer
argument_list|(
argument|GLenum target
argument_list|,
argument|GLsizei numAttachments
argument_list|,
argument|const GLenum * attachments
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|InvalidateSubFramebuffer
argument_list|(
name|target
argument_list|,
name|numAttachments
argument_list|,
name|attachments
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glIsQuery
specifier|inline
name|GLboolean
name|QOpenGLExtraFunctions
operator|::
name|glIsQuery
argument_list|(
argument|GLuint id
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|GLboolean
name|result
operator|=
name|d
operator|->
name|f
operator|.
name|IsQuery
argument_list|(
name|id
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glIsSampler
specifier|inline
name|GLboolean
name|QOpenGLExtraFunctions
operator|::
name|glIsSampler
argument_list|(
argument|GLuint sampler
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|GLboolean
name|result
operator|=
name|d
operator|->
name|f
operator|.
name|IsSampler
argument_list|(
name|sampler
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glIsSync
specifier|inline
name|GLboolean
name|QOpenGLExtraFunctions
operator|::
name|glIsSync
argument_list|(
argument|GLsync sync
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|GLboolean
name|result
operator|=
name|d
operator|->
name|f
operator|.
name|IsSync
argument_list|(
name|sync
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glIsTransformFeedback
specifier|inline
name|GLboolean
name|QOpenGLExtraFunctions
operator|::
name|glIsTransformFeedback
argument_list|(
argument|GLuint id
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|GLboolean
name|result
operator|=
name|d
operator|->
name|f
operator|.
name|IsTransformFeedback
argument_list|(
name|id
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glIsVertexArray
specifier|inline
name|GLboolean
name|QOpenGLExtraFunctions
operator|::
name|glIsVertexArray
argument_list|(
argument|GLuint array
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|GLboolean
name|result
operator|=
name|d
operator|->
name|f
operator|.
name|IsVertexArray
argument_list|(
name|array
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glMapBufferRange
specifier|inline
name|void
operator|*
name|QOpenGLExtraFunctions
operator|::
name|glMapBufferRange
argument_list|(
argument|GLenum target
argument_list|,
argument|GLintptr offset
argument_list|,
argument|GLsizeiptr length
argument_list|,
argument|GLbitfield access
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|void
operator|*
name|result
operator|=
name|d
operator|->
name|f
operator|.
name|MapBufferRange
argument_list|(
name|target
argument_list|,
name|offset
argument_list|,
name|length
argument_list|,
name|access
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glPauseTransformFeedback
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glPauseTransformFeedback
argument_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|PauseTransformFeedback
argument_list|()
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramBinary
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramBinary
argument_list|(
argument|GLuint program
argument_list|,
argument|GLenum binaryFormat
argument_list|,
argument|const void * binary
argument_list|,
argument|GLsizei length
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramBinary
argument_list|(
name|program
argument_list|,
name|binaryFormat
argument_list|,
name|binary
argument_list|,
name|length
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramParameteri
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramParameteri
argument_list|(
argument|GLuint program
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramParameteri
argument_list|(
name|program
argument_list|,
name|pname
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glReadBuffer
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glReadBuffer
argument_list|(
argument|GLenum src
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ReadBuffer
argument_list|(
name|src
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glRenderbufferStorageMultisample
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glRenderbufferStorageMultisample
argument_list|(
argument|GLenum target
argument_list|,
argument|GLsizei samples
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|RenderbufferStorageMultisample
argument_list|(
name|target
argument_list|,
name|samples
argument_list|,
name|internalformat
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glResumeTransformFeedback
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glResumeTransformFeedback
argument_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ResumeTransformFeedback
argument_list|()
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glSamplerParameterf
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glSamplerParameterf
argument_list|(
argument|GLuint sampler
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLfloat param
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|SamplerParameterf
argument_list|(
name|sampler
argument_list|,
name|pname
argument_list|,
name|param
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glSamplerParameterfv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glSamplerParameterfv
argument_list|(
argument|GLuint sampler
argument_list|,
argument|GLenum pname
argument_list|,
argument|const GLfloat * param
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|SamplerParameterfv
argument_list|(
name|sampler
argument_list|,
name|pname
argument_list|,
name|param
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glSamplerParameteri
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glSamplerParameteri
argument_list|(
argument|GLuint sampler
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint param
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|SamplerParameteri
argument_list|(
name|sampler
argument_list|,
name|pname
argument_list|,
name|param
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glSamplerParameteriv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glSamplerParameteriv
argument_list|(
argument|GLuint sampler
argument_list|,
argument|GLenum pname
argument_list|,
argument|const GLint * param
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|SamplerParameteriv
argument_list|(
name|sampler
argument_list|,
name|pname
argument_list|,
name|param
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glTexImage3D
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glTexImage3D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLint border
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const void * pixels
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|TexImage3D
argument_list|(
name|target
argument_list|,
name|level
argument_list|,
name|internalformat
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|depth
argument_list|,
name|border
argument_list|,
name|format
argument_list|,
name|type
argument_list|,
name|pixels
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glTexStorage2D
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glTexStorage2D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLsizei levels
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|TexStorage2D
argument_list|(
name|target
argument_list|,
name|levels
argument_list|,
name|internalformat
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glTexStorage3D
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glTexStorage3D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLsizei levels
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|TexStorage3D
argument_list|(
name|target
argument_list|,
name|levels
argument_list|,
name|internalformat
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|depth
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glTexSubImage3D
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glTexSubImage3D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint zoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const void * pixels
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|TexSubImage3D
argument_list|(
name|target
argument_list|,
name|level
argument_list|,
name|xoffset
argument_list|,
name|yoffset
argument_list|,
name|zoffset
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|depth
argument_list|,
name|format
argument_list|,
name|type
argument_list|,
name|pixels
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glTransformFeedbackVaryings
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glTransformFeedbackVaryings
argument_list|(
argument|GLuint program
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLchar *const* varyings
argument_list|,
argument|GLenum bufferMode
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|TransformFeedbackVaryings
argument_list|(
name|program
argument_list|,
name|count
argument_list|,
name|varyings
argument_list|,
name|bufferMode
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glUniform1ui
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glUniform1ui
argument_list|(
argument|GLint location
argument_list|,
argument|GLuint v0
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|Uniform1ui
argument_list|(
name|location
argument_list|,
name|v0
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glUniform1uiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glUniform1uiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|Uniform1uiv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glUniform2ui
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glUniform2ui
argument_list|(
argument|GLint location
argument_list|,
argument|GLuint v0
argument_list|,
argument|GLuint v1
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|Uniform2ui
argument_list|(
name|location
argument_list|,
name|v0
argument_list|,
name|v1
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glUniform2uiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glUniform2uiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|Uniform2uiv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glUniform3ui
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glUniform3ui
argument_list|(
argument|GLint location
argument_list|,
argument|GLuint v0
argument_list|,
argument|GLuint v1
argument_list|,
argument|GLuint v2
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|Uniform3ui
argument_list|(
name|location
argument_list|,
name|v0
argument_list|,
name|v1
argument_list|,
name|v2
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glUniform3uiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glUniform3uiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|Uniform3uiv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glUniform4ui
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glUniform4ui
argument_list|(
argument|GLint location
argument_list|,
argument|GLuint v0
argument_list|,
argument|GLuint v1
argument_list|,
argument|GLuint v2
argument_list|,
argument|GLuint v3
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|Uniform4ui
argument_list|(
name|location
argument_list|,
name|v0
argument_list|,
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glUniform4uiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glUniform4uiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|Uniform4uiv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glUniformBlockBinding
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glUniformBlockBinding
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint uniformBlockIndex
argument_list|,
argument|GLuint uniformBlockBinding
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|UniformBlockBinding
argument_list|(
name|program
argument_list|,
name|uniformBlockIndex
argument_list|,
name|uniformBlockBinding
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glUniformMatrix2x3fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glUniformMatrix2x3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|UniformMatrix2x3fv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glUniformMatrix2x4fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glUniformMatrix2x4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|UniformMatrix2x4fv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glUniformMatrix3x2fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glUniformMatrix3x2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|UniformMatrix3x2fv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glUniformMatrix3x4fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glUniformMatrix3x4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|UniformMatrix3x4fv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glUniformMatrix4x2fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glUniformMatrix4x2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|UniformMatrix4x2fv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glUniformMatrix4x3fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glUniformMatrix4x3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|UniformMatrix4x3fv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glUnmapBuffer
specifier|inline
name|GLboolean
name|QOpenGLExtraFunctions
operator|::
name|glUnmapBuffer
argument_list|(
argument|GLenum target
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|GLboolean
name|result
operator|=
name|d
operator|->
name|f
operator|.
name|UnmapBuffer
argument_list|(
name|target
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glVertexAttribDivisor
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glVertexAttribDivisor
argument_list|(
argument|GLuint index
argument_list|,
argument|GLuint divisor
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|VertexAttribDivisor
argument_list|(
name|index
argument_list|,
name|divisor
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glVertexAttribI4i
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glVertexAttribI4i
argument_list|(
argument|GLuint index
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLint z
argument_list|,
argument|GLint w
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|VertexAttribI4i
argument_list|(
name|index
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|z
argument_list|,
name|w
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glVertexAttribI4iv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glVertexAttribI4iv
argument_list|(
argument|GLuint index
argument_list|,
argument|const GLint * v
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|VertexAttribI4iv
argument_list|(
name|index
argument_list|,
name|v
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glVertexAttribI4ui
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glVertexAttribI4ui
argument_list|(
argument|GLuint index
argument_list|,
argument|GLuint x
argument_list|,
argument|GLuint y
argument_list|,
argument|GLuint z
argument_list|,
argument|GLuint w
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|VertexAttribI4ui
argument_list|(
name|index
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|z
argument_list|,
name|w
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glVertexAttribI4uiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glVertexAttribI4uiv
argument_list|(
argument|GLuint index
argument_list|,
argument|const GLuint * v
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|VertexAttribI4uiv
argument_list|(
name|index
argument_list|,
name|v
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glVertexAttribIPointer
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glVertexAttribIPointer
argument_list|(
argument|GLuint index
argument_list|,
argument|GLint size
argument_list|,
argument|GLenum type
argument_list|,
argument|GLsizei stride
argument_list|,
argument|const void * pointer
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|VertexAttribIPointer
argument_list|(
name|index
argument_list|,
name|size
argument_list|,
name|type
argument_list|,
name|stride
argument_list|,
name|pointer
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glWaitSync
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glWaitSync
argument_list|(
argument|GLsync sync
argument_list|,
argument|GLbitfield flags
argument_list|,
argument|GLuint64 timeout
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|WaitSync
argument_list|(
name|sync
argument_list|,
name|flags
argument_list|,
name|timeout
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glActiveShaderProgram
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glActiveShaderProgram
argument_list|(
argument|GLuint pipeline
argument_list|,
argument|GLuint program
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ActiveShaderProgram
argument_list|(
name|pipeline
argument_list|,
name|program
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glBindImageTexture
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glBindImageTexture
argument_list|(
argument|GLuint unit
argument_list|,
argument|GLuint texture
argument_list|,
argument|GLint level
argument_list|,
argument|GLboolean layered
argument_list|,
argument|GLint layer
argument_list|,
argument|GLenum access
argument_list|,
argument|GLenum format
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|BindImageTexture
argument_list|(
name|unit
argument_list|,
name|texture
argument_list|,
name|level
argument_list|,
name|layered
argument_list|,
name|layer
argument_list|,
name|access
argument_list|,
name|format
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glBindProgramPipeline
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glBindProgramPipeline
argument_list|(
argument|GLuint pipeline
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|BindProgramPipeline
argument_list|(
name|pipeline
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glBindVertexBuffer
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glBindVertexBuffer
argument_list|(
argument|GLuint bindingindex
argument_list|,
argument|GLuint buffer
argument_list|,
argument|GLintptr offset
argument_list|,
argument|GLsizei stride
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|BindVertexBuffer
argument_list|(
name|bindingindex
argument_list|,
name|buffer
argument_list|,
name|offset
argument_list|,
name|stride
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glCreateShaderProgramv
specifier|inline
name|GLuint
name|QOpenGLExtraFunctions
operator|::
name|glCreateShaderProgramv
argument_list|(
argument|GLenum type
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLchar *const* strings
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|GLuint
name|result
operator|=
name|d
operator|->
name|f
operator|.
name|CreateShaderProgramv
argument_list|(
name|type
argument_list|,
name|count
argument_list|,
name|strings
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glDeleteProgramPipelines
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glDeleteProgramPipelines
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint * pipelines
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|DeleteProgramPipelines
argument_list|(
name|n
argument_list|,
name|pipelines
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glDispatchCompute
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glDispatchCompute
argument_list|(
argument|GLuint num_groups_x
argument_list|,
argument|GLuint num_groups_y
argument_list|,
argument|GLuint num_groups_z
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|DispatchCompute
argument_list|(
name|num_groups_x
argument_list|,
name|num_groups_y
argument_list|,
name|num_groups_z
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glDispatchComputeIndirect
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glDispatchComputeIndirect
argument_list|(
argument|GLintptr indirect
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|DispatchComputeIndirect
argument_list|(
name|indirect
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glDrawArraysIndirect
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glDrawArraysIndirect
argument_list|(
argument|GLenum mode
argument_list|,
argument|const void * indirect
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|DrawArraysIndirect
argument_list|(
name|mode
argument_list|,
name|indirect
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glDrawElementsIndirect
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glDrawElementsIndirect
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLenum type
argument_list|,
argument|const void * indirect
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|DrawElementsIndirect
argument_list|(
name|mode
argument_list|,
name|type
argument_list|,
name|indirect
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glFramebufferParameteri
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glFramebufferParameteri
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint param
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|FramebufferParameteri
argument_list|(
name|target
argument_list|,
name|pname
argument_list|,
name|param
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGenProgramPipelines
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGenProgramPipelines
argument_list|(
argument|GLsizei n
argument_list|,
argument|GLuint* pipelines
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GenProgramPipelines
argument_list|(
name|n
argument_list|,
name|pipelines
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetBooleani_v
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetBooleani_v
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint index
argument_list|,
argument|GLboolean* data
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetBooleani_v
argument_list|(
name|target
argument_list|,
name|index
argument_list|,
name|data
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetFramebufferParameteriv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetFramebufferParameteriv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetFramebufferParameteriv
argument_list|(
name|target
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetMultisamplefv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetMultisamplefv
argument_list|(
argument|GLenum pname
argument_list|,
argument|GLuint index
argument_list|,
argument|GLfloat* val
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetMultisamplefv
argument_list|(
name|pname
argument_list|,
name|index
argument_list|,
name|val
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetProgramInterfaceiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetProgramInterfaceiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLenum programInterface
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetProgramInterfaceiv
argument_list|(
name|program
argument_list|,
name|programInterface
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetProgramPipelineInfoLog
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetProgramPipelineInfoLog
argument_list|(
argument|GLuint pipeline
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei* length
argument_list|,
argument|GLchar* infoLog
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetProgramPipelineInfoLog
argument_list|(
name|pipeline
argument_list|,
name|bufSize
argument_list|,
name|length
argument_list|,
name|infoLog
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetProgramPipelineiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetProgramPipelineiv
argument_list|(
argument|GLuint pipeline
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetProgramPipelineiv
argument_list|(
name|pipeline
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetProgramResourceIndex
specifier|inline
name|GLuint
name|QOpenGLExtraFunctions
operator|::
name|glGetProgramResourceIndex
argument_list|(
argument|GLuint program
argument_list|,
argument|GLenum programInterface
argument_list|,
argument|const GLchar * name
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|GLuint
name|result
operator|=
name|d
operator|->
name|f
operator|.
name|GetProgramResourceIndex
argument_list|(
name|program
argument_list|,
name|programInterface
argument_list|,
name|name
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glGetProgramResourceLocation
specifier|inline
name|GLint
name|QOpenGLExtraFunctions
operator|::
name|glGetProgramResourceLocation
argument_list|(
argument|GLuint program
argument_list|,
argument|GLenum programInterface
argument_list|,
argument|const GLchar * name
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|GLint
name|result
operator|=
name|d
operator|->
name|f
operator|.
name|GetProgramResourceLocation
argument_list|(
name|program
argument_list|,
name|programInterface
argument_list|,
name|name
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glGetProgramResourceName
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetProgramResourceName
argument_list|(
argument|GLuint program
argument_list|,
argument|GLenum programInterface
argument_list|,
argument|GLuint index
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei* length
argument_list|,
argument|GLchar* name
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetProgramResourceName
argument_list|(
name|program
argument_list|,
name|programInterface
argument_list|,
name|index
argument_list|,
name|bufSize
argument_list|,
name|length
argument_list|,
name|name
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetProgramResourceiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetProgramResourceiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLenum programInterface
argument_list|,
argument|GLuint index
argument_list|,
argument|GLsizei propCount
argument_list|,
argument|const GLenum * props
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei* length
argument_list|,
argument|GLint* params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetProgramResourceiv
argument_list|(
name|program
argument_list|,
name|programInterface
argument_list|,
name|index
argument_list|,
name|propCount
argument_list|,
name|props
argument_list|,
name|bufSize
argument_list|,
name|length
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetTexLevelParameterfv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetTexLevelParameterfv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLfloat* params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetTexLevelParameterfv
argument_list|(
name|target
argument_list|,
name|level
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetTexLevelParameteriv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glGetTexLevelParameteriv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|GetTexLevelParameteriv
argument_list|(
name|target
argument_list|,
name|level
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glIsProgramPipeline
specifier|inline
name|GLboolean
name|QOpenGLExtraFunctions
operator|::
name|glIsProgramPipeline
argument_list|(
argument|GLuint pipeline
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|GLboolean
name|result
operator|=
name|d
operator|->
name|f
operator|.
name|IsProgramPipeline
argument_list|(
name|pipeline
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glMemoryBarrier
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glMemoryBarrier
argument_list|(
argument|GLbitfield barriers
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|MemoryBarrier
argument_list|(
name|barriers
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glMemoryBarrierByRegion
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glMemoryBarrierByRegion
argument_list|(
argument|GLbitfield barriers
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|MemoryBarrierByRegion
argument_list|(
name|barriers
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform1f
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform1f
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLfloat v0
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform1f
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|v0
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform1fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform1fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform1fv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform1i
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform1i
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLint v0
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform1i
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|v0
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform1iv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform1iv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform1iv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform1ui
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform1ui
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLuint v0
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform1ui
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|v0
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform1uiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform1uiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform1uiv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform2f
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform2f
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLfloat v0
argument_list|,
argument|GLfloat v1
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform2f
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|v0
argument_list|,
name|v1
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform2fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform2fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform2fv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform2i
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform2i
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLint v0
argument_list|,
argument|GLint v1
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform2i
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|v0
argument_list|,
name|v1
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform2iv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform2iv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform2iv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform2ui
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform2ui
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLuint v0
argument_list|,
argument|GLuint v1
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform2ui
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|v0
argument_list|,
name|v1
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform2uiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform2uiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform2uiv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform3f
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform3f
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLfloat v0
argument_list|,
argument|GLfloat v1
argument_list|,
argument|GLfloat v2
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform3f
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|v0
argument_list|,
name|v1
argument_list|,
name|v2
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform3fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform3fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform3fv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform3i
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform3i
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLint v0
argument_list|,
argument|GLint v1
argument_list|,
argument|GLint v2
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform3i
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|v0
argument_list|,
name|v1
argument_list|,
name|v2
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform3iv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform3iv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform3iv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform3ui
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform3ui
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLuint v0
argument_list|,
argument|GLuint v1
argument_list|,
argument|GLuint v2
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform3ui
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|v0
argument_list|,
name|v1
argument_list|,
name|v2
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform3uiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform3uiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform3uiv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform4f
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform4f
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLfloat v0
argument_list|,
argument|GLfloat v1
argument_list|,
argument|GLfloat v2
argument_list|,
argument|GLfloat v3
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform4f
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|v0
argument_list|,
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform4fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform4fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform4fv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform4i
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform4i
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLint v0
argument_list|,
argument|GLint v1
argument_list|,
argument|GLint v2
argument_list|,
argument|GLint v3
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform4i
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|v0
argument_list|,
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform4iv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform4iv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform4iv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform4ui
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform4ui
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLuint v0
argument_list|,
argument|GLuint v1
argument_list|,
argument|GLuint v2
argument_list|,
argument|GLuint v3
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform4ui
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|v0
argument_list|,
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniform4uiv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniform4uiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniform4uiv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniformMatrix2fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniformMatrix2fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniformMatrix2fv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniformMatrix2x3fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniformMatrix2x3fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniformMatrix2x3fv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniformMatrix2x4fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniformMatrix2x4fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniformMatrix2x4fv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniformMatrix3fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniformMatrix3fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniformMatrix3fv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniformMatrix3x2fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniformMatrix3x2fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniformMatrix3x2fv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniformMatrix3x4fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniformMatrix3x4fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniformMatrix3x4fv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniformMatrix4fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniformMatrix4fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniformMatrix4fv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniformMatrix4x2fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniformMatrix4x2fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniformMatrix4x2fv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glProgramUniformMatrix4x3fv
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glProgramUniformMatrix4x3fv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat * value
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ProgramUniformMatrix4x3fv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glSampleMaski
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glSampleMaski
argument_list|(
argument|GLuint maskNumber
argument_list|,
argument|GLbitfield mask
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|SampleMaski
argument_list|(
name|maskNumber
argument_list|,
name|mask
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glTexStorage2DMultisample
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glTexStorage2DMultisample
argument_list|(
argument|GLenum target
argument_list|,
argument|GLsizei samples
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLboolean fixedsamplelocations
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|TexStorage2DMultisample
argument_list|(
name|target
argument_list|,
name|samples
argument_list|,
name|internalformat
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|fixedsamplelocations
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glUseProgramStages
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glUseProgramStages
argument_list|(
argument|GLuint pipeline
argument_list|,
argument|GLbitfield stages
argument_list|,
argument|GLuint program
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|UseProgramStages
argument_list|(
name|pipeline
argument_list|,
name|stages
argument_list|,
name|program
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glValidateProgramPipeline
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glValidateProgramPipeline
argument_list|(
argument|GLuint pipeline
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|ValidateProgramPipeline
argument_list|(
name|pipeline
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glVertexAttribBinding
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glVertexAttribBinding
argument_list|(
argument|GLuint attribindex
argument_list|,
argument|GLuint bindingindex
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|VertexAttribBinding
argument_list|(
name|attribindex
argument_list|,
name|bindingindex
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glVertexAttribFormat
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glVertexAttribFormat
argument_list|(
argument|GLuint attribindex
argument_list|,
argument|GLint size
argument_list|,
argument|GLenum type
argument_list|,
argument|GLboolean normalized
argument_list|,
argument|GLuint relativeoffset
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|VertexAttribFormat
argument_list|(
name|attribindex
argument_list|,
name|size
argument_list|,
name|type
argument_list|,
name|normalized
argument_list|,
name|relativeoffset
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glVertexAttribIFormat
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glVertexAttribIFormat
argument_list|(
argument|GLuint attribindex
argument_list|,
argument|GLint size
argument_list|,
argument|GLenum type
argument_list|,
argument|GLuint relativeoffset
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|VertexAttribIFormat
argument_list|(
name|attribindex
argument_list|,
name|size
argument_list|,
name|type
argument_list|,
name|relativeoffset
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glVertexBindingDivisor
specifier|inline
name|void
name|QOpenGLExtraFunctions
operator|::
name|glVertexBindingDivisor
argument_list|(
argument|GLuint bindingindex
argument_list|,
argument|GLuint divisor
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtraFunctions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtraFunctions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|f
operator|.
name|VertexBindingDivisor
argument_list|(
name|bindingindex
argument_list|,
name|divisor
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
name|QT_END_NAMESPACE
end_decl_stmt
begin_undef
DECL|macro|QT_OPENGL_DECLARE_FUNCTIONS
undef|#
directive|undef
name|QT_OPENGL_DECLARE_FUNCTIONS
end_undef
begin_undef
DECL|macro|QT_OPENGL_COUNT_FUNCTIONS
undef|#
directive|undef
name|QT_OPENGL_COUNT_FUNCTIONS
end_undef
begin_undef
DECL|macro|QT_OPENGL_DECLARE
undef|#
directive|undef
name|QT_OPENGL_DECLARE
end_undef
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_pragma
pragma|#
directive|pragma
name|pop_macro
name|(
literal|"MemoryBarrier"
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_OPENGL
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
