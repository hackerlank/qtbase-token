begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"glextensions.h"
end_include
begin_define
DECL|macro|RESOLVE_GL_FUNC
define|#
directive|define
name|RESOLVE_GL_FUNC
parameter_list|(
name|f
parameter_list|)
value|ok&= bool((f = (_gl##f) context->getProcAddress(QLatin1String("gl" #f))));
end_define
begin_function
DECL|function|resolve
name|bool
name|GLExtensionFunctions
operator|::
name|resolve
parameter_list|(
specifier|const
name|QGLContext
modifier|*
name|context
parameter_list|)
block|{
name|bool
name|ok
init|=
literal|true
decl_stmt|;
name|RESOLVE_GL_FUNC
argument_list|(
argument|GenFramebuffersEXT
argument_list|)
name|RESOLVE_GL_FUNC
argument_list|(
argument|GenRenderbuffersEXT
argument_list|)
name|RESOLVE_GL_FUNC
argument_list|(
argument|BindRenderbufferEXT
argument_list|)
name|RESOLVE_GL_FUNC
argument_list|(
argument|RenderbufferStorageEXT
argument_list|)
name|RESOLVE_GL_FUNC
argument_list|(
argument|DeleteFramebuffersEXT
argument_list|)
name|RESOLVE_GL_FUNC
argument_list|(
argument|DeleteRenderbuffersEXT
argument_list|)
name|RESOLVE_GL_FUNC
argument_list|(
argument|BindFramebufferEXT
argument_list|)
name|RESOLVE_GL_FUNC
argument_list|(
argument|FramebufferTexture2DEXT
argument_list|)
name|RESOLVE_GL_FUNC
argument_list|(
argument|FramebufferRenderbufferEXT
argument_list|)
name|RESOLVE_GL_FUNC
argument_list|(
argument|CheckFramebufferStatusEXT
argument_list|)
name|RESOLVE_GL_FUNC
argument_list|(
argument|ActiveTexture
argument_list|)
name|RESOLVE_GL_FUNC
argument_list|(
argument|TexImage3D
argument_list|)
name|RESOLVE_GL_FUNC
argument_list|(
argument|GenBuffers
argument_list|)
name|RESOLVE_GL_FUNC
argument_list|(
argument|BindBuffer
argument_list|)
name|RESOLVE_GL_FUNC
argument_list|(
argument|BufferData
argument_list|)
name|RESOLVE_GL_FUNC
argument_list|(
argument|DeleteBuffers
argument_list|)
name|RESOLVE_GL_FUNC
argument_list|(
argument|MapBuffer
argument_list|)
name|RESOLVE_GL_FUNC
argument_list|(
argument|UnmapBuffer
argument_list|)
return|return
name|ok
return|;
block|}
end_function
begin_function
DECL|function|fboSupported
name|bool
name|GLExtensionFunctions
operator|::
name|fboSupported
parameter_list|()
block|{
return|return
name|GenFramebuffersEXT
operator|&&
name|GenRenderbuffersEXT
operator|&&
name|BindRenderbufferEXT
operator|&&
name|RenderbufferStorageEXT
operator|&&
name|DeleteFramebuffersEXT
operator|&&
name|DeleteRenderbuffersEXT
operator|&&
name|BindFramebufferEXT
operator|&&
name|FramebufferTexture2DEXT
operator|&&
name|FramebufferRenderbufferEXT
operator|&&
name|CheckFramebufferStatusEXT
return|;
block|}
end_function
begin_function
DECL|function|openGL15Supported
name|bool
name|GLExtensionFunctions
operator|::
name|openGL15Supported
parameter_list|()
block|{
return|return
name|ActiveTexture
operator|&&
name|TexImage3D
operator|&&
name|GenBuffers
operator|&&
name|BindBuffer
operator|&&
name|BufferData
operator|&&
name|DeleteBuffers
operator|&&
name|MapBuffer
operator|&&
name|UnmapBuffer
return|;
block|}
end_function
begin_undef
DECL|macro|RESOLVE_GL_FUNC
undef|#
directive|undef
name|RESOLVE_GL_FUNC
end_undef
end_unit
