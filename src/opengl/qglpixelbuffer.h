begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLPIXELBUFFER_H
end_ifndef
begin_define
DECL|macro|QGLPIXELBUFFER_H
define|#
directive|define
name|QGLPIXELBUFFER_H
end_define
begin_include
include|#
directive|include
file|<QtOpenGL/qgl.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpaintdevice.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|OpenGL
argument_list|)
name|class
name|QGLPixelBufferPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_OPENGL_EXPORT
name|QGLPixelBuffer
range|:
name|public
name|QPaintDevice
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGLPixelBuffer
argument_list|)
name|public
operator|:
name|QGLPixelBuffer
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QGLFormat
operator|&
name|format
operator|=
name|QGLFormat
operator|::
name|defaultFormat
argument_list|()
argument_list|,
name|QGLWidget
operator|*
name|shareWidget
operator|=
literal|0
argument_list|)
block|;
name|QGLPixelBuffer
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|const QGLFormat&format = QGLFormat::defaultFormat()
argument_list|,
argument|QGLWidget *shareWidget =
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QGLPixelBuffer
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|bool
name|makeCurrent
argument_list|()
block|;
name|bool
name|doneCurrent
argument_list|()
block|;
name|GLuint
name|generateDynamicTexture
argument_list|()
specifier|const
block|;
name|bool
name|bindToDynamicTexture
argument_list|(
argument|GLuint texture
argument_list|)
block|;
name|void
name|releaseFromDynamicTexture
argument_list|()
block|;
name|void
name|updateDynamicTexture
argument_list|(
argument|GLuint texture_id
argument_list|)
specifier|const
block|;
name|GLuint
name|bindTexture
argument_list|(
argument|const QImage&image
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|)
block|;
name|GLuint
name|bindTexture
argument_list|(
argument|const QPixmap&pixmap
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|)
block|;
name|GLuint
name|bindTexture
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|void
name|deleteTexture
argument_list|(
argument|GLuint texture_id
argument_list|)
block|;
name|void
name|drawTexture
argument_list|(
argument|const QRectF&target
argument_list|,
argument|GLuint textureId
argument_list|,
argument|GLenum textureTarget = GL_TEXTURE_2D
argument_list|)
block|;
name|void
name|drawTexture
argument_list|(
argument|const QPointF&point
argument_list|,
argument|GLuint textureId
argument_list|,
argument|GLenum textureTarget = GL_TEXTURE_2D
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_MAC_COMPAT_GL_FUNCTIONS
name|bool
name|bindToDynamicTexture
argument_list|(
argument|QMacCompatGLuint texture
argument_list|)
block|;
name|void
name|updateDynamicTexture
argument_list|(
argument|QMacCompatGLuint texture_id
argument_list|)
specifier|const
block|;
name|GLuint
name|bindTexture
argument_list|(
argument|const QImage&image
argument_list|,
argument|QMacCompatGLenum target = GL_TEXTURE_2D
argument_list|)
block|;
name|GLuint
name|bindTexture
argument_list|(
argument|const QPixmap&pixmap
argument_list|,
argument|QMacCompatGLenum target = GL_TEXTURE_2D
argument_list|)
block|;
name|void
name|drawTexture
argument_list|(
argument|const QRectF&target
argument_list|,
argument|QMacCompatGLuint textureId
argument_list|,
argument|QMacCompatGLenum textureTarget = GL_TEXTURE_2D
argument_list|)
block|;
name|void
name|drawTexture
argument_list|(
argument|const QPointF&point
argument_list|,
argument|QMacCompatGLuint textureId
argument_list|,
argument|QMacCompatGLenum textureTarget = GL_TEXTURE_2D
argument_list|)
block|;
name|void
name|deleteTexture
argument_list|(
argument|QMacCompatGLuint texture_id
argument_list|)
block|;
endif|#
directive|endif
name|QSize
name|size
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
specifier|const
block|;
name|QImage
name|toImage
argument_list|()
specifier|const
block|;
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
block|;
name|QGLFormat
name|format
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|hasOpenGLPbuffers
argument_list|()
block|;
name|protected
operator|:
name|int
name|metric
argument_list|(
argument|PaintDeviceMetric metric
argument_list|)
specifier|const
block|;
name|int
name|devType
argument_list|()
specifier|const
block|{
return|return
name|QInternal
operator|::
name|Pbuffer
return|;
block|}
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGLPixelBuffer
argument_list|)
name|QScopedPointer
operator|<
name|QGLPixelBufferPrivate
operator|>
name|d_ptr
block|;
name|friend
name|class
name|QGLDrawable
block|;
name|friend
name|class
name|QGLWindowSurface
block|;
name|friend
name|class
name|QGLPaintDevice
block|;
name|friend
name|class
name|QGLPBufferGLPaintDevice
block|;
name|friend
name|class
name|QGLContextPrivate
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGLPIXELBUFFER_H
end_comment
end_unit
