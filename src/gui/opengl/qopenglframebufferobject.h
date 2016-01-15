begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLFRAMEBUFFEROBJECT_H
end_ifndef
begin_define
DECL|macro|QOPENGLFRAMEBUFFEROBJECT_H
define|#
directive|define
name|QOPENGLFRAMEBUFFEROBJECT_H
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
file|<QtGui/qopengl.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpaintdevice.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLFramebufferObjectPrivate
name|class
name|QOpenGLFramebufferObjectPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLFramebufferObjectFormat
name|class
name|QOpenGLFramebufferObjectFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLFramebufferObject
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QOpenGLFramebufferObject
argument_list|)
name|public
label|:
enum|enum
name|Attachment
block|{
name|NoAttachment
block|,
name|CombinedDepthStencil
block|,
name|Depth
block|}
enum|;
name|explicit
name|QOpenGLFramebufferObject
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|GLenum
name|target
init|=
name|GL_TEXTURE_2D
parameter_list|)
function_decl|;
name|QOpenGLFramebufferObject
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|)
empty_stmt|;
name|QOpenGLFramebufferObject
argument_list|(
argument|const QSize&size
argument_list|,
argument|Attachment attachment
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|,
argument|GLenum internalFormat =
literal|0
argument_list|)
empty_stmt|;
name|QOpenGLFramebufferObject
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|Attachment attachment
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|,
argument|GLenum internalFormat =
literal|0
argument_list|)
empty_stmt|;
name|QOpenGLFramebufferObject
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QOpenGLFramebufferObjectFormat
operator|&
name|format
argument_list|)
expr_stmt|;
name|QOpenGLFramebufferObject
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|const QOpenGLFramebufferObjectFormat&format
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|QOpenGLFramebufferObject
argument_list|()
expr_stmt|;
name|void
name|addColorAttachment
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|GLenum
name|internalFormat
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|addColorAttachment
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|GLenum
name|internalFormat
init|=
literal|0
parameter_list|)
function_decl|;
name|QOpenGLFramebufferObjectFormat
name|format
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isBound
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|bind
parameter_list|()
function_decl|;
name|bool
name|release
parameter_list|()
function_decl|;
name|int
name|width
argument_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|.
name|width
argument_list|()
return|;
block|}
name|int
name|height
argument_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|.
name|height
argument_list|()
return|;
block|}
name|GLuint
name|texture
argument_list|()
specifier|const
expr_stmt|;
name|QVector
operator|<
name|GLuint
operator|>
name|textures
argument_list|()
specifier|const
expr_stmt|;
name|GLuint
name|takeTexture
parameter_list|()
function_decl|;
name|GLuint
name|takeTexture
parameter_list|(
name|int
name|colorAttachmentIndex
parameter_list|)
function_decl|;
name|QSize
name|size
argument_list|()
specifier|const
expr_stmt|;
name|QVector
operator|<
name|QSize
operator|>
name|sizes
argument_list|()
specifier|const
expr_stmt|;
name|QImage
name|toImage
argument_list|()
specifier|const
expr_stmt|;
name|QImage
name|toImage
argument_list|(
name|bool
name|flipped
argument_list|)
decl|const
decl_stmt|;
name|QImage
name|toImage
argument_list|(
name|bool
name|flipped
argument_list|,
name|int
name|colorAttachmentIndex
argument_list|)
decl|const
decl_stmt|;
name|Attachment
name|attachment
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAttachment
parameter_list|(
name|Attachment
name|attachment
parameter_list|)
function_decl|;
name|GLuint
name|handle
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|bool
name|bindDefault
parameter_list|()
function_decl|;
specifier|static
name|bool
name|hasOpenGLFramebufferObjects
parameter_list|()
function_decl|;
specifier|static
name|bool
name|hasOpenGLFramebufferBlit
parameter_list|()
function_decl|;
specifier|static
name|void
name|blitFramebuffer
parameter_list|(
name|QOpenGLFramebufferObject
modifier|*
name|target
parameter_list|,
specifier|const
name|QRect
modifier|&
name|targetRect
parameter_list|,
name|QOpenGLFramebufferObject
modifier|*
name|source
parameter_list|,
specifier|const
name|QRect
modifier|&
name|sourceRect
parameter_list|,
name|GLbitfield
name|buffers
parameter_list|,
name|GLenum
name|filter
parameter_list|,
name|int
name|readColorAttachmentIndex
parameter_list|,
name|int
name|drawColorAttachmentIndex
parameter_list|)
function_decl|;
specifier|static
name|void
name|blitFramebuffer
parameter_list|(
name|QOpenGLFramebufferObject
modifier|*
name|target
parameter_list|,
specifier|const
name|QRect
modifier|&
name|targetRect
parameter_list|,
name|QOpenGLFramebufferObject
modifier|*
name|source
parameter_list|,
specifier|const
name|QRect
modifier|&
name|sourceRect
parameter_list|,
name|GLbitfield
name|buffers
init|=
name|GL_COLOR_BUFFER_BIT
parameter_list|,
name|GLenum
name|filter
init|=
name|GL_NEAREST
parameter_list|)
function_decl|;
specifier|static
name|void
name|blitFramebuffer
parameter_list|(
name|QOpenGLFramebufferObject
modifier|*
name|target
parameter_list|,
name|QOpenGLFramebufferObject
modifier|*
name|source
parameter_list|,
name|GLbitfield
name|buffers
init|=
name|GL_COLOR_BUFFER_BIT
parameter_list|,
name|GLenum
name|filter
init|=
name|GL_NEAREST
parameter_list|)
function_decl|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QOpenGLFramebufferObject
argument_list|)
name|QScopedPointer
operator|<
name|QOpenGLFramebufferObjectPrivate
operator|>
name|d_ptr
expr_stmt|;
name|friend
name|class
name|QOpenGLPaintDevice
decl_stmt|;
name|friend
name|class
name|QOpenGLFBOGLPaintDevice
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QOpenGLFramebufferObjectFormatPrivate
name|class
name|QOpenGLFramebufferObjectFormatPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLFramebufferObjectFormat
block|{
name|public
label|:
name|QOpenGLFramebufferObjectFormat
argument_list|()
expr_stmt|;
name|QOpenGLFramebufferObjectFormat
argument_list|(
specifier|const
name|QOpenGLFramebufferObjectFormat
operator|&
name|other
argument_list|)
expr_stmt|;
name|QOpenGLFramebufferObjectFormat
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QOpenGLFramebufferObjectFormat
operator|&
name|other
operator|)
decl_stmt|;
operator|~
name|QOpenGLFramebufferObjectFormat
argument_list|()
expr_stmt|;
name|void
name|setSamples
parameter_list|(
name|int
name|samples
parameter_list|)
function_decl|;
name|int
name|samples
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMipmap
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|bool
name|mipmap
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAttachment
argument_list|(
name|QOpenGLFramebufferObject
operator|::
name|Attachment
name|attachment
argument_list|)
decl_stmt|;
name|QOpenGLFramebufferObject
operator|::
name|Attachment
name|attachment
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setTextureTarget
parameter_list|(
name|GLenum
name|target
parameter_list|)
function_decl|;
name|GLenum
name|textureTarget
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setInternalTextureFormat
parameter_list|(
name|GLenum
name|internalTextureFormat
parameter_list|)
function_decl|;
name|GLenum
name|internalTextureFormat
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QOpenGLFramebufferObjectFormat
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QOpenGLFramebufferObjectFormat
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|private
label|:
name|QOpenGLFramebufferObjectFormatPrivate
modifier|*
name|d
decl_stmt|;
name|void
name|detach
parameter_list|()
function_decl|;
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
comment|// QT_NO_OPENGL
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOPENGLFRAMEBUFFEROBJECT_H
end_comment
end_unit
