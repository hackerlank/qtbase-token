begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLBUFFER_H
end_ifndef
begin_define
DECL|macro|QOPENGLBUFFER_H
define|#
directive|define
name|QOPENGLBUFFER_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopengl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLBufferPrivate
name|class
name|QOpenGLBufferPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLBuffer
block|{
name|public
label|:
enum|enum
name|Type
block|{
name|VertexBuffer
init|=
literal|0x8892
block|,
comment|// GL_ARRAY_BUFFER
name|IndexBuffer
init|=
literal|0x8893
block|,
comment|// GL_ELEMENT_ARRAY_BUFFER
name|PixelPackBuffer
init|=
literal|0x88EB
block|,
comment|// GL_PIXEL_PACK_BUFFER
name|PixelUnpackBuffer
init|=
literal|0x88EC
comment|// GL_PIXEL_UNPACK_BUFFER
block|}
enum|;
name|QOpenGLBuffer
argument_list|()
expr_stmt|;
name|explicit
name|QOpenGLBuffer
argument_list|(
name|QOpenGLBuffer
operator|::
name|Type
name|type
argument_list|)
decl_stmt|;
name|QOpenGLBuffer
argument_list|(
specifier|const
name|QOpenGLBuffer
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QOpenGLBuffer
argument_list|()
expr_stmt|;
name|QOpenGLBuffer
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QOpenGLBuffer
operator|&
name|other
operator|)
decl_stmt|;
enum|enum
name|UsagePattern
block|{
name|StreamDraw
init|=
literal|0x88E0
block|,
comment|// GL_STREAM_DRAW
name|StreamRead
init|=
literal|0x88E1
block|,
comment|// GL_STREAM_READ
name|StreamCopy
init|=
literal|0x88E2
block|,
comment|// GL_STREAM_COPY
name|StaticDraw
init|=
literal|0x88E4
block|,
comment|// GL_STATIC_DRAW
name|StaticRead
init|=
literal|0x88E5
block|,
comment|// GL_STATIC_READ
name|StaticCopy
init|=
literal|0x88E6
block|,
comment|// GL_STATIC_COPY
name|DynamicDraw
init|=
literal|0x88E8
block|,
comment|// GL_DYNAMIC_DRAW
name|DynamicRead
init|=
literal|0x88E9
block|,
comment|// GL_DYNAMIC_READ
name|DynamicCopy
init|=
literal|0x88EA
comment|// GL_DYNAMIC_COPY
block|}
enum|;
enum|enum
name|Access
block|{
name|ReadOnly
init|=
literal|0x88B8
block|,
comment|// GL_READ_ONLY
name|WriteOnly
init|=
literal|0x88B9
block|,
comment|// GL_WRITE_ONLY
name|ReadWrite
init|=
literal|0x88BA
comment|// GL_READ_WRITE
block|}
enum|;
name|QOpenGLBuffer
operator|::
name|Type
name|type
argument_list|()
specifier|const
expr_stmt|;
name|QOpenGLBuffer
operator|::
name|UsagePattern
name|usagePattern
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setUsagePattern
argument_list|(
name|QOpenGLBuffer
operator|::
name|UsagePattern
name|value
argument_list|)
decl_stmt|;
name|bool
name|create
parameter_list|()
function_decl|;
name|bool
name|isCreated
argument_list|()
specifier|const
expr_stmt|;
name|void
name|destroy
parameter_list|()
function_decl|;
name|bool
name|bind
parameter_list|()
function_decl|;
name|void
name|release
parameter_list|()
function_decl|;
specifier|static
name|void
name|release
argument_list|(
name|QOpenGLBuffer
operator|::
name|Type
name|type
argument_list|)
decl_stmt|;
name|GLuint
name|bufferId
argument_list|()
specifier|const
expr_stmt|;
name|int
name|size
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|read
parameter_list|(
name|int
name|offset
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
name|void
name|write
parameter_list|(
name|int
name|offset
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
name|void
name|allocate
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
specifier|inline
name|void
name|allocate
parameter_list|(
name|int
name|count
parameter_list|)
block|{
name|allocate
argument_list|(
literal|0
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
name|void
modifier|*
name|map
argument_list|(
name|QOpenGLBuffer
operator|::
name|Access
name|access
argument_list|)
decl_stmt|;
name|bool
name|unmap
parameter_list|()
function_decl|;
name|private
label|:
name|QOpenGLBufferPrivate
modifier|*
name|d_ptr
decl_stmt|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QOpenGLBuffer
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
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
