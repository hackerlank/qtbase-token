begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtOpenGL/qgl.h>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/private/qgl_p.h>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/private/qglextensions_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|"qglbuffer.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QGLBuffer     \inmodule QtOpenGL     \brief The QGLBuffer class provides functions for creating and managing GL buffer objects.     \since 4.7     \obsolete     \ingroup painting-3D      Buffer objects are created in the GL server so that the     client application can avoid uploading vertices, indices,     texture image data, etc every time they are needed.      QGLBuffer objects can be copied around as a reference to the     underlying GL buffer object:      \code     QGLBuffer buffer1(QGLBuffer::IndexBuffer);     buffer1.create();      QGLBuffer buffer2 = buffer1;     \endcode      QGLBuffer performs a shallow copy when objects are copied in this     manner, but does not implement copy-on-write semantics.  The original     object will be affected whenever the copy is modified.      \note This class has been deprecated in favor of QOpenGLBuffer. */
end_comment
begin_comment
comment|/*!     \enum QGLBuffer::Type     This enum defines the type of GL buffer object to create with QGLBuffer.      \value VertexBuffer Vertex buffer object for use when specifying            vertex arrays.     \value IndexBuffer Index buffer object for use with \c{glDrawElements()}.     \value PixelPackBuffer Pixel pack buffer object for reading pixel            data from the GL server (for example, with \c{glReadPixels()}).            Not supported under OpenGL/ES.     \value PixelUnpackBuffer Pixel unpack buffer object for writing pixel            data to the GL server (for example, with \c{glTexImage2D()}).            Not supported under OpenGL/ES. */
end_comment
begin_comment
comment|/*!     \enum QGLBuffer::UsagePattern     This enum defines the usage pattern of a QGLBuffer object.      \value StreamDraw The data will be set once and used a few times            for drawing operations.  Under OpenGL/ES 1.1 this is identical            to StaticDraw.     \value StreamRead The data will be set once and used a few times            for reading data back from the GL server.  Not supported            under OpenGL/ES.     \value StreamCopy The data will be set once and used a few times            for reading data back from the GL server for use in further            drawing operations.  Not supported under OpenGL/ES.     \value StaticDraw The data will be set once and used many times            for drawing operations.     \value StaticRead The data will be set once and used many times            for reading data back from the GL server.  Not supported            under OpenGL/ES.     \value StaticCopy The data will be set once and used many times            for reading data back from the GL server for use in further            drawing operations.  Not supported under OpenGL/ES.     \value DynamicDraw The data will be modified repeatedly and used            many times for drawing operations.     \value DynamicRead The data will be modified repeatedly and used            many times for reading data back from the GL server.            Not supported under OpenGL/ES.     \value DynamicCopy The data will be modified repeatedly and used            many times for reading data back from the GL server for            use in further drawing operations.  Not supported under OpenGL/ES. */
end_comment
begin_comment
comment|/*!     \enum QGLBuffer::Access     This enum defines the access mode for QGLBuffer::map().      \value ReadOnly The buffer will be mapped for reading only.     \value WriteOnly The buffer will be mapped for writing only.     \value ReadWrite The buffer will be mapped for reading and writing. */
end_comment
begin_class
DECL|class|QGLBufferPrivate
class|class
name|QGLBufferPrivate
block|{
public|public:
DECL|function|QGLBufferPrivate
name|QGLBufferPrivate
parameter_list|(
name|QGLBuffer
operator|::
name|Type
name|t
parameter_list|)
member_init_list|:
name|ref
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|type
argument_list|(
name|t
argument_list|)
member_init_list|,
name|guard
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|usagePattern
argument_list|(
name|QGLBuffer
operator|::
name|StaticDraw
argument_list|)
member_init_list|,
name|actualUsagePattern
argument_list|(
name|QGLBuffer
operator|::
name|StaticDraw
argument_list|)
block|{     }
DECL|member|ref
name|QAtomicInt
name|ref
decl_stmt|;
DECL|member|type
name|QGLBuffer
operator|::
name|Type
name|type
decl_stmt|;
DECL|member|guard
name|QGLSharedResourceGuardBase
modifier|*
name|guard
decl_stmt|;
DECL|member|usagePattern
name|QGLBuffer
operator|::
name|UsagePattern
name|usagePattern
decl_stmt|;
DECL|member|actualUsagePattern
name|QGLBuffer
operator|::
name|UsagePattern
name|actualUsagePattern
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     Constructs a new buffer object of type QGLBuffer::VertexBuffer.      Note: this constructor just creates the QGLBuffer instance.  The actual     buffer object in the GL server is not created until create() is called.      \sa create() */
end_comment
begin_constructor
DECL|function|QGLBuffer
name|QGLBuffer
operator|::
name|QGLBuffer
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QGLBufferPrivate
argument_list|(
name|QGLBuffer
operator|::
name|VertexBuffer
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a new buffer object of \a type.      Note: this constructor just creates the QGLBuffer instance.  The actual     buffer object in the GL server is not created until create() is called.      \sa create() */
end_comment
begin_constructor
DECL|function|QGLBuffer
name|QGLBuffer
operator|::
name|QGLBuffer
parameter_list|(
name|QGLBuffer
operator|::
name|Type
name|type
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QGLBufferPrivate
argument_list|(
name|type
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a shallow copy of \a other.      Note: QGLBuffer does not implement copy-on-write semantics,     so \a other will be affected whenever the copy is modified. */
end_comment
begin_constructor
DECL|function|QGLBuffer
name|QGLBuffer
operator|::
name|QGLBuffer
parameter_list|(
specifier|const
name|QGLBuffer
modifier|&
name|other
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
name|other
operator|.
name|d_ptr
argument_list|)
block|{
name|d_ptr
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_define
DECL|macro|ctx
define|#
directive|define
name|ctx
value|QGLContext::currentContext();
end_define
begin_comment
comment|/*!     Destroys this buffer object, including the storage being     used in the GL server. */
end_comment
begin_destructor
DECL|function|~QGLBuffer
name|QGLBuffer
operator|::
name|~
name|QGLBuffer
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d_ptr
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
block|{
name|destroy
argument_list|()
expr_stmt|;
operator|delete
name|d_ptr
expr_stmt|;
block|}
block|}
end_destructor
begin_comment
comment|/*!     Assigns a shallow copy of \a other to this object.      Note: QGLBuffer does not implement copy-on-write semantics,     so \a other will be affected whenever the copy is modified. */
end_comment
begin_function
DECL|function|operator =
name|QGLBuffer
modifier|&
name|QGLBuffer
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QGLBuffer
modifier|&
name|other
parameter_list|)
block|{
if|if
condition|(
name|d_ptr
operator|!=
name|other
operator|.
name|d_ptr
condition|)
block|{
name|other
operator|.
name|d_ptr
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
if|if
condition|(
operator|!
name|d_ptr
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
block|{
name|destroy
argument_list|()
expr_stmt|;
operator|delete
name|d_ptr
expr_stmt|;
block|}
name|d_ptr
operator|=
name|other
operator|.
name|d_ptr
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the type of buffer represented by this object. */
end_comment
begin_function
DECL|function|type
name|QGLBuffer
operator|::
name|Type
name|QGLBuffer
operator|::
name|type
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGLBuffer
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|type
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the usage pattern for this buffer object.     The default value is StaticDraw.      \sa setUsagePattern() */
end_comment
begin_function
DECL|function|usagePattern
name|QGLBuffer
operator|::
name|UsagePattern
name|QGLBuffer
operator|::
name|usagePattern
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGLBuffer
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|usagePattern
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the usage pattern for this buffer object to \a value.     This function must be called before allocate() or write().      \sa usagePattern(), allocate(), write() */
end_comment
begin_function
DECL|function|setUsagePattern
name|void
name|QGLBuffer
operator|::
name|setUsagePattern
parameter_list|(
name|QGLBuffer
operator|::
name|UsagePattern
name|value
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLBuffer
argument_list|)
expr_stmt|;
name|d
operator|->
name|usagePattern
operator|=
name|d
operator|->
name|actualUsagePattern
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_undef
DECL|macro|ctx
undef|#
directive|undef
name|ctx
end_undef
begin_namespace
namespace|namespace
block|{
DECL|function|freeBufferFunc
name|void
name|freeBufferFunc
parameter_list|(
name|QGLContext
modifier|*
name|ctx
parameter_list|,
name|GLuint
name|id
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|glDeleteBuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|id
argument_list|)
expr_stmt|;
block|}
block|}
end_namespace
begin_comment
comment|/*!     Creates the buffer object in the GL server.  Returns true if     the object was created; false otherwise.      This function must be called with a current QGLContext.     The buffer will be bound to and can only be used in     that context (or any other context that is shared with it).      This function will return false if the GL implementation     does not support buffers, or there is no current QGLContext.      \sa isCreated(), allocate(), write(), destroy() */
end_comment
begin_function
DECL|function|create
name|bool
name|QGLBuffer
operator|::
name|create
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGLBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|guard
operator|&&
name|d
operator|->
name|guard
operator|->
name|id
argument_list|()
condition|)
return|return
literal|true
return|;
name|QGLContext
modifier|*
name|ctx
init|=
cast|const_cast
argument_list|<
name|QGLContext
operator|*
argument_list|>
argument_list|(
name|QGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|ctx
condition|)
block|{
if|if
condition|(
operator|!
name|qt_resolve_buffer_extensions
argument_list|(
name|ctx
argument_list|)
condition|)
return|return
literal|false
return|;
name|GLuint
name|bufferId
init|=
literal|0
decl_stmt|;
name|glGenBuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|bufferId
argument_list|)
expr_stmt|;
if|if
condition|(
name|bufferId
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|guard
condition|)
name|d
operator|->
name|guard
operator|->
name|free
argument_list|()
expr_stmt|;
name|d
operator|->
name|guard
operator|=
name|createSharedResourceGuard
argument_list|(
name|ctx
argument_list|,
name|bufferId
argument_list|,
name|freeBufferFunc
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
begin_define
DECL|macro|ctx
define|#
directive|define
name|ctx
value|QGLContext::currentContext()
end_define
begin_comment
comment|/*!     Returns true if this buffer has been created; false otherwise.      \sa create(), destroy() */
end_comment
begin_function
DECL|function|isCreated
name|bool
name|QGLBuffer
operator|::
name|isCreated
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGLBuffer
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|guard
operator|&&
name|d
operator|->
name|guard
operator|->
name|id
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Destroys this buffer object, including the storage being     used in the GL server.  All references to the buffer will     become invalid. */
end_comment
begin_function
DECL|function|destroy
name|void
name|QGLBuffer
operator|::
name|destroy
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGLBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|guard
condition|)
block|{
name|d
operator|->
name|guard
operator|->
name|free
argument_list|()
expr_stmt|;
name|d
operator|->
name|guard
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Reads the \a count bytes in this buffer starting at \a offset     into \a data.  Returns true on success; false if reading from     the buffer is not supported.  Buffer reading is not supported     under OpenGL/ES.      It is assumed that this buffer has been bound to the current context.      \sa write(), bind() */
end_comment
begin_function
DECL|function|read
name|bool
name|QGLBuffer
operator|::
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
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES
argument_list|)
name|Q_D
argument_list|(
name|QGLBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|glGetBufferSubData
operator|||
operator|!
name|d
operator|->
name|guard
operator|->
name|id
argument_list|()
condition|)
return|return
literal|false
return|;
while|while
condition|(
name|glGetError
argument_list|()
operator|!=
name|GL_NO_ERROR
condition|)
empty_stmt|;
comment|// Clear error state.
name|glGetBufferSubData
argument_list|(
name|d
operator|->
name|type
argument_list|,
name|offset
argument_list|,
name|count
argument_list|,
name|data
argument_list|)
expr_stmt|;
return|return
name|glGetError
argument_list|()
operator|==
name|GL_NO_ERROR
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|offset
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|count
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*!     Replaces the \a count bytes of this buffer starting at \a offset     with the contents of \a data.  Any other bytes in the buffer     will be left unmodified.      It is assumed that create() has been called on this buffer and that     it has been bound to the current context.      \sa create(), read(), allocate() */
end_comment
begin_function
DECL|function|write
name|void
name|QGLBuffer
operator|::
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
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
if|if
condition|(
operator|!
name|isCreated
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"QGLBuffer::allocate(): buffer not created"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|Q_D
argument_list|(
name|QGLBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|guard
operator|&&
name|d
operator|->
name|guard
operator|->
name|id
argument_list|()
condition|)
name|glBufferSubData
argument_list|(
name|d
operator|->
name|type
argument_list|,
name|offset
argument_list|,
name|count
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Allocates \a count bytes of space to the buffer, initialized to     the contents of \a data.  Any previous contents will be removed.      It is assumed that create() has been called on this buffer and that     it has been bound to the current context.      \sa create(), read(), write() */
end_comment
begin_function
DECL|function|allocate
name|void
name|QGLBuffer
operator|::
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
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
if|if
condition|(
operator|!
name|isCreated
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"QGLBuffer::allocate(): buffer not created"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|Q_D
argument_list|(
name|QGLBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|guard
operator|&&
name|d
operator|->
name|guard
operator|->
name|id
argument_list|()
condition|)
name|glBufferData
argument_list|(
name|d
operator|->
name|type
argument_list|,
name|count
argument_list|,
name|data
argument_list|,
name|d
operator|->
name|actualUsagePattern
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn void QGLBuffer::allocate(int count)     \overload      Allocates \a count bytes of space to the buffer.  Any previous     contents will be removed.      It is assumed that create() has been called on this buffer and that     it has been bound to the current context.      \sa create(), write() */
end_comment
begin_comment
comment|/*!     Binds the buffer associated with this object to the current     GL context.  Returns false if binding was not possible, usually because     type() is not supported on this GL implementation.      The buffer must be bound to the same QGLContext current when create()     was called, or to another QGLContext that is sharing with it.     Otherwise, false will be returned from this function.      \sa release(), create() */
end_comment
begin_function
DECL|function|bind
name|bool
name|QGLBuffer
operator|::
name|bind
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
if|if
condition|(
operator|!
name|isCreated
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"QGLBuffer::bind(): buffer not created"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|Q_D
argument_list|(
specifier|const
name|QGLBuffer
argument_list|)
expr_stmt|;
name|GLuint
name|bufferId
init|=
name|d
operator|->
name|guard
condition|?
name|d
operator|->
name|guard
operator|->
name|id
argument_list|()
else|:
literal|0
decl_stmt|;
if|if
condition|(
name|bufferId
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|guard
operator|->
name|group
argument_list|()
operator|!=
name|QOpenGLContextGroup
operator|::
name|currentContextGroup
argument_list|()
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
name|qWarning
argument_list|(
literal|"QGLBuffer::bind: buffer is not valid in the current context"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
name|glBindBuffer
argument_list|(
name|d
operator|->
name|type
argument_list|,
name|bufferId
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
else|else
block|{
return|return
literal|false
return|;
block|}
block|}
end_function
begin_comment
comment|/*!     Releases the buffer associated with this object from the     current GL context.      This function must be called with the same QGLContext current     as when bind() was called on the buffer.      \sa bind() */
end_comment
begin_function
DECL|function|release
name|void
name|QGLBuffer
operator|::
name|release
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
if|if
condition|(
operator|!
name|isCreated
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"QGLBuffer::release(): buffer not created"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|Q_D
argument_list|(
specifier|const
name|QGLBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|guard
operator|&&
name|d
operator|->
name|guard
operator|->
name|id
argument_list|()
condition|)
name|glBindBuffer
argument_list|(
name|d
operator|->
name|type
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_undef
DECL|macro|ctx
undef|#
directive|undef
name|ctx
end_undef
begin_comment
comment|/*!     Releases the buffer associated with \a type in the current     QGLContext.      This function is a direct call to \c{glBindBuffer(type, 0)}     for use when the caller does not know which QGLBuffer has     been bound to the context but wants to make sure that it     is released.      \code     QGLBuffer::release(QGLBuffer::VertexBuffer);     \endcode */
end_comment
begin_function
DECL|function|release
name|void
name|QGLBuffer
operator|::
name|release
parameter_list|(
name|QGLBuffer
operator|::
name|Type
name|type
parameter_list|)
block|{
specifier|const
name|QGLContext
modifier|*
name|ctx
init|=
name|QGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ctx
operator|&&
name|qt_resolve_buffer_extensions
argument_list|(
cast|const_cast
argument_list|<
name|QGLContext
operator|*
argument_list|>
argument_list|(
name|ctx
argument_list|)
argument_list|)
condition|)
name|glBindBuffer
argument_list|(
name|GLenum
argument_list|(
name|type
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_define
DECL|macro|ctx
define|#
directive|define
name|ctx
value|QGLContext::currentContext()
end_define
begin_comment
comment|/*!     Returns the GL identifier associated with this buffer; zero if     the buffer has not been created.      \sa isCreated() */
end_comment
begin_function
DECL|function|bufferId
name|GLuint
name|QGLBuffer
operator|::
name|bufferId
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGLBuffer
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|guard
condition|?
name|d
operator|->
name|guard
operator|->
name|id
argument_list|()
else|:
literal|0
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|GL_BUFFER_SIZE
end_ifndef
begin_define
DECL|macro|GL_BUFFER_SIZE
define|#
directive|define
name|GL_BUFFER_SIZE
value|0x8764
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     Returns the size of the data in this buffer, for reading operations.     Returns -1 if fetching the buffer size is not supported, or the     buffer has not been created.      It is assumed that this buffer has been bound to the current context.      \sa isCreated(), bind() */
end_comment
begin_function
DECL|function|size
name|int
name|QGLBuffer
operator|::
name|size
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGLBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|guard
operator|||
operator|!
name|d
operator|->
name|guard
operator|->
name|id
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
name|GLint
name|value
init|=
operator|-
literal|1
decl_stmt|;
name|glGetBufferParameteriv
argument_list|(
name|d
operator|->
name|type
argument_list|,
name|GL_BUFFER_SIZE
argument_list|,
operator|&
name|value
argument_list|)
expr_stmt|;
return|return
name|value
return|;
block|}
end_function
begin_comment
comment|/*!     Maps the contents of this buffer into the application's memory     space and returns a pointer to it.  Returns null if memory     mapping is not possible.  The \a access parameter indicates the     type of access to be performed.      It is assumed that create() has been called on this buffer and that     it has been bound to the current context.      This function is only supported under OpenGL/ES if the     \c{GL_OES_mapbuffer} extension is present.      \sa unmap(), create(), bind() */
end_comment
begin_function
DECL|function|map
name|void
modifier|*
name|QGLBuffer
operator|::
name|map
parameter_list|(
name|QGLBuffer
operator|::
name|Access
name|access
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLBuffer
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
if|if
condition|(
operator|!
name|isCreated
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"QGLBuffer::map(): buffer not created"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|d
operator|->
name|guard
operator|||
operator|!
name|d
operator|->
name|guard
operator|->
name|id
argument_list|()
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|glMapBufferARB
condition|)
return|return
literal|0
return|;
return|return
name|glMapBufferARB
argument_list|(
name|d
operator|->
name|type
argument_list|,
name|access
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Unmaps the buffer after it was mapped into the application's     memory space with a previous call to map().  Returns true if     the unmap succeeded; false otherwise.      It is assumed that this buffer has been bound to the current context,     and that it was previously mapped with map().      This function is only supported under OpenGL/ES if the     \c{GL_OES_mapbuffer} extension is present.      \sa map() */
end_comment
begin_function
DECL|function|unmap
name|bool
name|QGLBuffer
operator|::
name|unmap
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGLBuffer
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
if|if
condition|(
operator|!
name|isCreated
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"QGLBuffer::unmap(): buffer not created"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|d
operator|->
name|guard
operator|||
operator|!
name|d
operator|->
name|guard
operator|->
name|id
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
name|glUnmapBufferARB
condition|)
return|return
literal|false
return|;
return|return
name|glUnmapBufferARB
argument_list|(
name|d
operator|->
name|type
argument_list|)
operator|==
name|GL_TRUE
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
