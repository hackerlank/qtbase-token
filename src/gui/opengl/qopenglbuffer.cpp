begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/qopengl.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qopenglcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|"qopenglbuffer.h"
end_include
begin_include
include|#
directive|include
file|<private/qopenglextensions_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QOpenGLBuffer     \brief The QOpenGLBuffer class provides functions for creating and managing OpenGL buffer objects.     \since 5.0     \ingroup painting-3D      Buffer objects are created in the OpenGL server so that the     client application can avoid uploading vertices, indices,     texture image data, etc every time they are needed.      QOpenGLBuffer objects can be copied around as a reference to the     underlying OpenGL buffer object:      \code     QOpenGLBuffer buffer1(QOpenGLBuffer::IndexBuffer);     buffer1.create();      QOpenGLBuffer buffer2 = buffer1;     \endcode      QOpenGLBuffer performs a shallow copy when objects are copied in this     manner, but does not implement copy-on-write semantics.  The original     object will be affected whenever the copy is modified. */
end_comment
begin_comment
comment|/*!     \enum QOpenGLBuffer::Type     This enum defines the type of OpenGL buffer object to create with QOpenGLBuffer.      \value VertexBuffer Vertex buffer object for use when specifying            vertex arrays.     \value IndexBuffer Index buffer object for use with \c{glDrawElements()}.     \value PixelPackBuffer Pixel pack buffer object for reading pixel            data from the OpenGL server (for example, with \c{glReadPixels()}).            Not supported under OpenGL/ES.     \value PixelUnpackBuffer Pixel unpack buffer object for writing pixel            data to the OpenGL server (for example, with \c{glTexImage2D()}).            Not supported under OpenGL/ES. */
end_comment
begin_comment
comment|/*!     \enum QOpenGLBuffer::UsagePattern     This enum defines the usage pattern of a QOpenGLBuffer object.      \value StreamDraw The data will be set once and used a few times            for drawing operations.  Under OpenGL/ES 1.1 this is identical            to StaticDraw.     \value StreamRead The data will be set once and used a few times            for reading data back from the OpenGL server.  Not supported            under OpenGL/ES.     \value StreamCopy The data will be set once and used a few times            for reading data back from the OpenGL server for use in further            drawing operations.  Not supported under OpenGL/ES.     \value StaticDraw The data will be set once and used many times            for drawing operations.     \value StaticRead The data will be set once and used many times            for reading data back from the OpenGL server.  Not supported            under OpenGL/ES.     \value StaticCopy The data will be set once and used many times            for reading data back from the OpenGL server for use in further            drawing operations.  Not supported under OpenGL/ES.     \value DynamicDraw The data will be modified repeatedly and used            many times for drawing operations.     \value DynamicRead The data will be modified repeatedly and used            many times for reading data back from the OpenGL server.            Not supported under OpenGL/ES.     \value DynamicCopy The data will be modified repeatedly and used            many times for reading data back from the OpenGL server for            use in further drawing operations.  Not supported under OpenGL/ES. */
end_comment
begin_comment
comment|/*!     \enum QOpenGLBuffer::Access     This enum defines the access mode for QOpenGLBuffer::map().      \value ReadOnly The buffer will be mapped for reading only.     \value WriteOnly The buffer will be mapped for writing only.     \value ReadWrite The buffer will be mapped for reading and writing. */
end_comment
begin_class
DECL|class|QOpenGLBufferPrivate
class|class
name|QOpenGLBufferPrivate
block|{
public|public:
DECL|function|QOpenGLBufferPrivate
name|QOpenGLBufferPrivate
parameter_list|(
name|QOpenGLBuffer
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
name|QOpenGLBuffer
operator|::
name|StaticDraw
argument_list|)
member_init_list|,
name|actualUsagePattern
argument_list|(
name|QOpenGLBuffer
operator|::
name|StaticDraw
argument_list|)
member_init_list|,
name|funcs
argument_list|(
literal|0
argument_list|)
block|{     }
DECL|member|ref
name|QAtomicInt
name|ref
decl_stmt|;
DECL|member|type
name|QOpenGLBuffer
operator|::
name|Type
name|type
decl_stmt|;
DECL|member|guard
name|QOpenGLSharedResourceGuard
modifier|*
name|guard
decl_stmt|;
DECL|member|usagePattern
name|QOpenGLBuffer
operator|::
name|UsagePattern
name|usagePattern
decl_stmt|;
DECL|member|actualUsagePattern
name|QOpenGLBuffer
operator|::
name|UsagePattern
name|actualUsagePattern
decl_stmt|;
DECL|member|funcs
name|QOpenGLExtensions
modifier|*
name|funcs
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     Constructs a new buffer object of type QOpenGLBuffer::VertexBuffer.      Note: this constructor just creates the QOpenGLBuffer instance.  The actual     buffer object in the OpenGL server is not created until create() is called.      \sa create() */
end_comment
begin_constructor
DECL|function|QOpenGLBuffer
name|QOpenGLBuffer
operator|::
name|QOpenGLBuffer
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QOpenGLBufferPrivate
argument_list|(
name|QOpenGLBuffer
operator|::
name|VertexBuffer
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a new buffer object of \a type.      Note: this constructor just creates the QOpenGLBuffer instance.  The actual     buffer object in the OpenGL server is not created until create() is called.      \sa create() */
end_comment
begin_constructor
DECL|function|QOpenGLBuffer
name|QOpenGLBuffer
operator|::
name|QOpenGLBuffer
parameter_list|(
name|QOpenGLBuffer
operator|::
name|Type
name|type
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QOpenGLBufferPrivate
argument_list|(
name|type
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a shallow copy of \a other.      Note: QOpenGLBuffer does not implement copy-on-write semantics,     so \a other will be affected whenever the copy is modified. */
end_comment
begin_constructor
DECL|function|QOpenGLBuffer
name|QOpenGLBuffer
operator|::
name|QOpenGLBuffer
parameter_list|(
specifier|const
name|QOpenGLBuffer
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
begin_comment
comment|/*!     Destroys this buffer object, including the storage being     used in the OpenGL server. */
end_comment
begin_destructor
DECL|function|~QOpenGLBuffer
name|QOpenGLBuffer
operator|::
name|~
name|QOpenGLBuffer
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
comment|/*!     Assigns a shallow copy of \a other to this object.      Note: QOpenGLBuffer does not implement copy-on-write semantics,     so \a other will be affected whenever the copy is modified. */
end_comment
begin_function
DECL|function|operator =
name|QOpenGLBuffer
modifier|&
name|QOpenGLBuffer
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QOpenGLBuffer
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
name|destroy
argument_list|()
expr_stmt|;
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
name|QOpenGLBuffer
operator|::
name|Type
name|QOpenGLBuffer
operator|::
name|type
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOpenGLBuffer
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
name|QOpenGLBuffer
operator|::
name|UsagePattern
name|QOpenGLBuffer
operator|::
name|usagePattern
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOpenGLBuffer
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
name|QOpenGLBuffer
operator|::
name|setUsagePattern
parameter_list|(
name|QOpenGLBuffer
operator|::
name|UsagePattern
name|value
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLBuffer
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
begin_namespace
namespace|namespace
block|{
DECL|function|freeBufferFunc
name|void
name|freeBufferFunc
parameter_list|(
name|QOpenGLFunctions
modifier|*
name|funcs
parameter_list|,
name|GLuint
name|id
parameter_list|)
block|{
name|funcs
operator|->
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
comment|/*!     Creates the buffer object in the OpenGL server.  Returns true if     the object was created; false otherwise.      This function must be called with a current QOpenGLContext.     The buffer will be bound to and can only be used in     that context (or any other context that is shared with it).      This function will return false if the OpenGL implementation     does not support buffers, or there is no current QOpenGLContext.      \sa isCreated(), allocate(), write(), destroy() */
end_comment
begin_function
DECL|function|create
name|bool
name|QOpenGLBuffer
operator|::
name|create
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLBuffer
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
name|QOpenGLContext
modifier|*
name|ctx
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ctx
condition|)
block|{
operator|delete
name|d
operator|->
name|funcs
expr_stmt|;
name|d
operator|->
name|funcs
operator|=
operator|new
name|QOpenGLExtensions
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|GLuint
name|bufferId
init|=
literal|0
decl_stmt|;
name|d
operator|->
name|funcs
operator|->
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
operator|new
name|QOpenGLSharedResourceGuard
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
begin_comment
comment|/*!     Returns true if this buffer has been created; false otherwise.      \sa create(), destroy() */
end_comment
begin_function
DECL|function|isCreated
name|bool
name|QOpenGLBuffer
operator|::
name|isCreated
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOpenGLBuffer
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
comment|/*!     Destroys this buffer object, including the storage being     used in the OpenGL server.  All references to the buffer will     become invalid. */
end_comment
begin_function
DECL|function|destroy
name|void
name|QOpenGLBuffer
operator|::
name|destroy
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLBuffer
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
name|QOpenGLBuffer
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
name|QOpenGLBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|funcs
operator|->
name|hasOpenGLFeature
argument_list|(
name|QOpenGLFunctions
operator|::
name|Buffers
argument_list|)
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
name|d
operator|->
name|funcs
operator|->
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
name|QOpenGLBuffer
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
literal|"QOpenGLBuffer::allocate(): buffer not created"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|Q_D
argument_list|(
name|QOpenGLBuffer
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
name|d
operator|->
name|funcs
operator|->
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
name|QOpenGLBuffer
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
literal|"QOpenGLBuffer::allocate(): buffer not created"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|Q_D
argument_list|(
name|QOpenGLBuffer
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
name|d
operator|->
name|funcs
operator|->
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
comment|/*!     \fn void QOpenGLBuffer::allocate(int count)     \overload      Allocates \a count bytes of space to the buffer.  Any previous     contents will be removed.      It is assumed that create() has been called on this buffer and that     it has been bound to the current context.      \sa create(), write() */
end_comment
begin_comment
comment|/*!     Binds the buffer associated with this object to the current     OpenGL context.  Returns false if binding was not possible, usually because     type() is not supported on this OpenGL implementation.      The buffer must be bound to the same QOpenGLContext current when create()     was called, or to another QOpenGLContext that is sharing with it.     Otherwise, false will be returned from this function.      \sa release(), create() */
end_comment
begin_function
DECL|function|bind
name|bool
name|QOpenGLBuffer
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
literal|"QOpenGLBuffer::bind(): buffer not created"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|Q_D
argument_list|(
specifier|const
name|QOpenGLBuffer
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
literal|"QOpenGLBuffer::bind: buffer is not valid in the current context"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
name|d
operator|->
name|funcs
operator|->
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
comment|/*!     Releases the buffer associated with this object from the     current OpenGL context.      This function must be called with the same QOpenGLContext current     as when bind() was called on the buffer.      \sa bind() */
end_comment
begin_function
DECL|function|release
name|void
name|QOpenGLBuffer
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
literal|"QOpenGLBuffer::release(): buffer not created"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|Q_D
argument_list|(
specifier|const
name|QOpenGLBuffer
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
name|d
operator|->
name|funcs
operator|->
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
begin_comment
comment|/*!     Releases the buffer associated with \a type in the current     QOpenGLContext.      This function is a direct call to \c{glBindBuffer(type, 0)}     for use when the caller does not know which QOpenGLBuffer has     been bound to the context but wants to make sure that it     is released.      \code     QOpenGLBuffer::release(QOpenGLBuffer::VertexBuffer);     \endcode */
end_comment
begin_function
DECL|function|release
name|void
name|QOpenGLBuffer
operator|::
name|release
parameter_list|(
name|QOpenGLBuffer
operator|::
name|Type
name|type
parameter_list|)
block|{
name|QOpenGLContext
modifier|*
name|ctx
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ctx
condition|)
name|ctx
operator|->
name|functions
argument_list|()
operator|->
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
begin_comment
comment|/*!     Returns the OpenGL identifier associated with this buffer; zero if     the buffer has not been created.      \sa isCreated() */
end_comment
begin_function
DECL|function|bufferId
name|GLuint
name|QOpenGLBuffer
operator|::
name|bufferId
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOpenGLBuffer
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
begin_comment
comment|/*!     Returns the size of the data in this buffer, for reading operations.     Returns -1 if fetching the buffer size is not supported, or the     buffer has not been created.      It is assumed that this buffer has been bound to the current context.      \sa isCreated(), bind() */
end_comment
begin_function
DECL|function|size
name|int
name|QOpenGLBuffer
operator|::
name|size
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOpenGLBuffer
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
name|d
operator|->
name|funcs
operator|->
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
name|QOpenGLBuffer
operator|::
name|map
parameter_list|(
name|QOpenGLBuffer
operator|::
name|Access
name|access
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLBuffer
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
literal|"QOpenGLBuffer::map(): buffer not created"
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
if|#
directive|if
literal|0
block|if (!glMapBufferARB)         return 0;     return glMapBufferARB(d->type, access);
endif|#
directive|endif
name|Q_UNUSED
argument_list|(
name|access
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|warned
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|warned
condition|)
block|{
name|qWarning
argument_list|(
literal|"QOpenGLBuffer::map(): pending implementation"
argument_list|)
expr_stmt|;
name|warned
operator|=
literal|true
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Unmaps the buffer after it was mapped into the application's     memory space with a previous call to map().  Returns true if     the unmap succeeded; false otherwise.      It is assumed that this buffer has been bound to the current context,     and that it was previously mapped with map().      This function is only supported under OpenGL/ES if the     \c{GL_OES_mapbuffer} extension is present.      \sa map() */
end_comment
begin_function
DECL|function|unmap
name|bool
name|QOpenGLBuffer
operator|::
name|unmap
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLBuffer
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
literal|"QOpenGLBuffer::unmap(): buffer not created"
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
if|#
directive|if
literal|0
block|if (!glUnmapBufferARB)         return false;     return glUnmapBufferARB(d->type) == GL_TRUE;
endif|#
directive|endif
specifier|static
name|bool
name|warned
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|warned
condition|)
block|{
name|qWarning
argument_list|(
literal|"QOpenGLBuffer::map(): pending implementation"
argument_list|)
expr_stmt|;
name|warned
operator|=
literal|true
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
