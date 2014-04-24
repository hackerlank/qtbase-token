begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenglvertexarrayobject.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopenglcontext.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopenglfunctions.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qoffscreensurface.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopenglfunctions_3_0.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopenglfunctions_3_2_core.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class_decl
class_decl|class
name|QOpenGLFunctions_3_0
class_decl|;
end_class_decl
begin_class_decl
class_decl|class
name|QOpenGLFunctions_3_2_Core
class_decl|;
end_class_decl
begin_class
DECL|class|QVertexArrayObjectHelper
class|class
name|QVertexArrayObjectHelper
block|{
public|public:
DECL|function|QVertexArrayObjectHelper
name|QVertexArrayObjectHelper
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|context
argument_list|)
expr_stmt|;
if|if
condition|(
name|context
operator|->
name|isOpenGLES
argument_list|()
condition|)
block|{
name|GenVertexArrays
operator|=
expr|reinterpret_cast
operator|<
name|void
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLsizei
argument_list|,
name|GLuint
operator|*
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"glGenVertexArraysOES"
argument_list|)
argument_list|)
operator|)
expr_stmt|;
name|DeleteVertexArrays
operator|=
expr|reinterpret_cast
operator|<
name|void
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLsizei
argument_list|,
specifier|const
name|GLuint
operator|*
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"glDeleteVertexArraysOES"
argument_list|)
argument_list|)
operator|)
expr_stmt|;
name|BindVertexArray
operator|=
cast|reinterpret_cast
argument_list|<
name|void
operator|(
name|QOPENGLF_APIENTRYP
operator|)
operator|(
name|GLuint
operator|)
argument_list|>
argument_list|(
name|context
operator|->
name|getProcAddress
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"glBindVertexArrayOES"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|context
operator|->
name|hasExtension
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"GL_APPLE_vertex_array_object"
argument_list|)
argument_list|)
condition|)
block|{
name|GenVertexArrays
operator|=
expr|reinterpret_cast
operator|<
name|void
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLsizei
argument_list|,
name|GLuint
operator|*
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"glGenVertexArraysAPPLE"
argument_list|)
argument_list|)
operator|)
expr_stmt|;
name|DeleteVertexArrays
operator|=
expr|reinterpret_cast
operator|<
name|void
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLsizei
argument_list|,
specifier|const
name|GLuint
operator|*
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"glDeleteVertexArraysAPPLE"
argument_list|)
argument_list|)
operator|)
expr_stmt|;
name|BindVertexArray
operator|=
cast|reinterpret_cast
argument_list|<
name|void
operator|(
name|QOPENGLF_APIENTRYP
operator|)
operator|(
name|GLuint
operator|)
argument_list|>
argument_list|(
name|context
operator|->
name|getProcAddress
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"glBindVertexArrayAPPLE"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|GenVertexArrays
operator|=
expr|reinterpret_cast
operator|<
name|void
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLsizei
argument_list|,
name|GLuint
operator|*
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"glGenVertexArrays"
argument_list|)
argument_list|)
operator|)
expr_stmt|;
name|DeleteVertexArrays
operator|=
expr|reinterpret_cast
operator|<
name|void
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLsizei
argument_list|,
specifier|const
name|GLuint
operator|*
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"glDeleteVertexArrays"
argument_list|)
argument_list|)
operator|)
expr_stmt|;
name|BindVertexArray
operator|=
cast|reinterpret_cast
argument_list|<
name|void
operator|(
name|QOPENGLF_APIENTRYP
operator|)
operator|(
name|GLuint
operator|)
argument_list|>
argument_list|(
name|context
operator|->
name|getProcAddress
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"glBindVertexArray"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
DECL|function|glGenVertexArrays
specifier|inline
name|void
name|glGenVertexArrays
parameter_list|(
name|GLsizei
name|n
parameter_list|,
name|GLuint
modifier|*
name|arrays
parameter_list|)
block|{
name|GenVertexArrays
argument_list|(
name|n
argument_list|,
name|arrays
argument_list|)
expr_stmt|;
block|}
DECL|function|glDeleteVertexArrays
specifier|inline
name|void
name|glDeleteVertexArrays
parameter_list|(
name|GLsizei
name|n
parameter_list|,
specifier|const
name|GLuint
modifier|*
name|arrays
parameter_list|)
block|{
name|DeleteVertexArrays
argument_list|(
name|n
argument_list|,
name|arrays
argument_list|)
expr_stmt|;
block|}
DECL|function|glBindVertexArray
specifier|inline
name|void
name|glBindVertexArray
parameter_list|(
name|GLuint
name|array
parameter_list|)
block|{
name|BindVertexArray
argument_list|(
name|array
argument_list|)
expr_stmt|;
block|}
private|private:
comment|// Function signatures are equivalent between desktop core, ARB, APPLE and ES 2 extensions
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|GenVertexArrays
function_decl|)
parameter_list|(
name|GLsizei
name|n
parameter_list|,
name|GLuint
modifier|*
name|arrays
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|DeleteVertexArrays
function_decl|)
parameter_list|(
name|GLsizei
name|n
parameter_list|,
specifier|const
name|GLuint
modifier|*
name|arrays
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|BindVertexArray
function_decl|)
parameter_list|(
name|GLuint
name|array
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|QOpenGLVertexArrayObjectPrivate
class|class
name|QOpenGLVertexArrayObjectPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
public|public:
DECL|function|QOpenGLVertexArrayObjectPrivate
name|QOpenGLVertexArrayObjectPrivate
parameter_list|()
member_init_list|:
name|vao
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|vaoFuncsType
argument_list|(
name|NotSupported
argument_list|)
member_init_list|,
name|context
argument_list|(
literal|0
argument_list|)
block|{     }
DECL|function|~QOpenGLVertexArrayObjectPrivate
name|~
name|QOpenGLVertexArrayObjectPrivate
parameter_list|()
block|{
if|if
condition|(
name|vaoFuncsType
operator|==
name|ARB
operator|||
name|vaoFuncsType
operator|==
name|APPLE
operator|||
name|vaoFuncsType
operator|==
name|OES
condition|)
operator|delete
name|vaoFuncs
operator|.
name|helper
expr_stmt|;
block|}
name|bool
name|create
parameter_list|()
function_decl|;
name|void
name|destroy
parameter_list|()
function_decl|;
name|void
name|bind
parameter_list|()
function_decl|;
name|void
name|release
parameter_list|()
function_decl|;
name|void
name|_q_contextAboutToBeDestroyed
parameter_list|()
function_decl|;
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QOpenGLVertexArrayObject
parameter_list|)
DECL|member|vao
name|GLuint
name|vao
decl_stmt|;
constructor_decl|union
block|{
DECL|member|core_3_0
name|QOpenGLFunctions_3_0
modifier|*
name|core_3_0
decl_stmt|;
DECL|member|core_3_2
name|QOpenGLFunctions_3_2_Core
modifier|*
name|core_3_2
decl_stmt|;
DECL|member|helper
name|QVertexArrayObjectHelper
modifier|*
name|helper
decl_stmt|;
block|}
DECL|member|vaoFuncs
name|vaoFuncs
empty_stmt|;
enum|enum
block|{
DECL|enumerator|NotSupported
name|NotSupported
block|,
DECL|enumerator|Core_3_0
name|Core_3_0
block|,
DECL|enumerator|Core_3_2
name|Core_3_2
block|,
DECL|enumerator|ARB
name|ARB
block|,
DECL|enumerator|APPLE
name|APPLE
block|,
DECL|enumerator|OES
name|OES
block|}
DECL|member|vaoFuncsType
name|vaoFuncsType
enum|;
DECL|member|context
name|QOpenGLContext
modifier|*
name|context
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|create
name|bool
name|QOpenGLVertexArrayObjectPrivate
operator|::
name|create
parameter_list|()
block|{
if|if
condition|(
name|vao
condition|)
block|{
name|qWarning
argument_list|(
literal|"QOpenGLVertexArrayObject::create() VAO is already created"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|Q_Q
argument_list|(
name|QOpenGLVertexArrayObject
argument_list|)
expr_stmt|;
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
operator|!
name|ctx
condition|)
block|{
name|qWarning
argument_list|(
literal|"QOpenGLVertexArrayObject::create() requires a valid current OpenGL context"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|context
operator|=
name|ctx
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|context
argument_list|,
name|SIGNAL
argument_list|(
name|aboutToBeDestroyed
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_contextAboutToBeDestroyed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ctx
operator|->
name|isOpenGLES
argument_list|()
condition|)
block|{
if|if
condition|(
name|ctx
operator|->
name|hasExtension
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"GL_OES_vertex_array_object"
argument_list|)
argument_list|)
condition|)
block|{
name|vaoFuncs
operator|.
name|helper
operator|=
operator|new
name|QVertexArrayObjectHelper
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|vaoFuncsType
operator|=
name|OES
expr_stmt|;
name|vaoFuncs
operator|.
name|helper
operator|->
name|glGenVertexArrays
argument_list|(
literal|1
argument_list|,
operator|&
name|vao
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|vaoFuncs
operator|.
name|core_3_0
operator|=
literal|0
expr_stmt|;
name|vaoFuncsType
operator|=
name|NotSupported
expr_stmt|;
name|QSurfaceFormat
name|format
init|=
name|ctx
operator|->
name|format
argument_list|()
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_OPENGL_ES_2
if|if
condition|(
name|format
operator|.
name|version
argument_list|()
operator|>=
name|qMakePair
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
argument_list|(
literal|3
argument_list|,
literal|2
argument_list|)
condition|)
block|{
name|vaoFuncs
operator|.
name|core_3_2
operator|=
name|ctx
operator|->
name|versionFunctions
argument_list|<
name|QOpenGLFunctions_3_2_Core
argument_list|>
argument_list|()
expr_stmt|;
name|vaoFuncsType
operator|=
name|Core_3_2
expr_stmt|;
name|vaoFuncs
operator|.
name|core_3_2
operator|->
name|initializeOpenGLFunctions
argument_list|()
expr_stmt|;
name|vaoFuncs
operator|.
name|core_3_2
operator|->
name|glGenVertexArrays
argument_list|(
literal|1
argument_list|,
operator|&
name|vao
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|format
operator|.
name|majorVersion
argument_list|()
operator|>=
literal|3
condition|)
block|{
name|vaoFuncs
operator|.
name|core_3_0
operator|=
name|ctx
operator|->
name|versionFunctions
argument_list|<
name|QOpenGLFunctions_3_0
argument_list|>
argument_list|()
expr_stmt|;
name|vaoFuncsType
operator|=
name|Core_3_0
expr_stmt|;
name|vaoFuncs
operator|.
name|core_3_0
operator|->
name|initializeOpenGLFunctions
argument_list|()
expr_stmt|;
name|vaoFuncs
operator|.
name|core_3_0
operator|->
name|glGenVertexArrays
argument_list|(
literal|1
argument_list|,
operator|&
name|vao
argument_list|)
expr_stmt|;
block|}
elseif|else
endif|#
directive|endif
if|if
condition|(
name|ctx
operator|->
name|hasExtension
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"GL_ARB_vertex_array_object"
argument_list|)
argument_list|)
condition|)
block|{
name|vaoFuncs
operator|.
name|helper
operator|=
operator|new
name|QVertexArrayObjectHelper
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|vaoFuncsType
operator|=
name|ARB
expr_stmt|;
name|vaoFuncs
operator|.
name|helper
operator|->
name|glGenVertexArrays
argument_list|(
literal|1
argument_list|,
operator|&
name|vao
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ctx
operator|->
name|hasExtension
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"GL_APPLE_vertex_array_object"
argument_list|)
argument_list|)
condition|)
block|{
name|vaoFuncs
operator|.
name|helper
operator|=
operator|new
name|QVertexArrayObjectHelper
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|vaoFuncsType
operator|=
name|APPLE
expr_stmt|;
name|vaoFuncs
operator|.
name|helper
operator|->
name|glGenVertexArrays
argument_list|(
literal|1
argument_list|,
operator|&
name|vao
argument_list|)
expr_stmt|;
block|}
block|}
return|return
operator|(
name|vao
operator|!=
literal|0
operator|)
return|;
block|}
end_function
begin_function
DECL|function|destroy
name|void
name|QOpenGLVertexArrayObjectPrivate
operator|::
name|destroy
parameter_list|()
block|{
if|if
condition|(
operator|!
name|vao
condition|)
return|return;
name|Q_Q
argument_list|(
name|QOpenGLVertexArrayObject
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|vaoFuncsType
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_OPENGL_ES_2
case|case
name|Core_3_2
case|:
name|vaoFuncs
operator|.
name|core_3_2
operator|->
name|glDeleteVertexArrays
argument_list|(
literal|1
argument_list|,
operator|&
name|vao
argument_list|)
expr_stmt|;
break|break;
case|case
name|Core_3_0
case|:
name|vaoFuncs
operator|.
name|core_3_0
operator|->
name|glDeleteVertexArrays
argument_list|(
literal|1
argument_list|,
operator|&
name|vao
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
name|ARB
case|:
case|case
name|APPLE
case|:
case|case
name|OES
case|:
name|vaoFuncs
operator|.
name|helper
operator|->
name|glDeleteVertexArrays
argument_list|(
literal|1
argument_list|,
operator|&
name|vao
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
name|Q_ASSERT
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|disconnect
argument_list|(
name|context
argument_list|,
name|SIGNAL
argument_list|(
name|aboutToBeDestroyed
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_contextAboutToBeDestroyed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|context
operator|=
literal|0
expr_stmt|;
name|vao
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|_q_contextAboutToBeDestroyed
name|void
name|QOpenGLVertexArrayObjectPrivate
operator|::
name|_q_contextAboutToBeDestroyed
parameter_list|()
block|{
name|destroy
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bind
name|void
name|QOpenGLVertexArrayObjectPrivate
operator|::
name|bind
parameter_list|()
block|{
switch|switch
condition|(
name|vaoFuncsType
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_OPENGL_ES_2
case|case
name|Core_3_2
case|:
name|vaoFuncs
operator|.
name|core_3_2
operator|->
name|glBindVertexArray
argument_list|(
name|vao
argument_list|)
expr_stmt|;
break|break;
case|case
name|Core_3_0
case|:
name|vaoFuncs
operator|.
name|core_3_0
operator|->
name|glBindVertexArray
argument_list|(
name|vao
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
name|ARB
case|:
case|case
name|APPLE
case|:
case|case
name|OES
case|:
name|vaoFuncs
operator|.
name|helper
operator|->
name|glBindVertexArray
argument_list|(
name|vao
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
end_function
begin_function
DECL|function|release
name|void
name|QOpenGLVertexArrayObjectPrivate
operator|::
name|release
parameter_list|()
block|{
switch|switch
condition|(
name|vaoFuncsType
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_OPENGL_ES_2
case|case
name|Core_3_2
case|:
name|vaoFuncs
operator|.
name|core_3_2
operator|->
name|glBindVertexArray
argument_list|(
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|Core_3_0
case|:
name|vaoFuncs
operator|.
name|core_3_0
operator|->
name|glBindVertexArray
argument_list|(
literal|0
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
name|ARB
case|:
case|case
name|APPLE
case|:
case|case
name|OES
case|:
name|vaoFuncs
operator|.
name|helper
operator|->
name|glBindVertexArray
argument_list|(
literal|0
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
end_function
begin_comment
comment|/*!     \class QOpenGLVertexArrayObject     \brief The QOpenGLVertexArrayObject class wraps an OpenGL Vertex Array Object.     \inmodule QtGui     \since 5.1     \ingroup painting-3D      A Vertex Array Object (VAO) is an OpenGL container object that encapsulates     the state needed to specify per-vertex attribute data to the OpenGL pipeline.     To put it another way, a VAO remembers the states of buffer objects (see     QOpenGLBuffer) and their associated state (e.g. vertex attribute divisors).     This allows a very easy and efficient method of switching between OpenGL buffer     states for rendering different "objects" in a scene. The QOpenGLVertexArrayObject     class is a thin wrapper around an OpenGL VAO.      For the desktop, VAOs are supported as a core feature in OpenGL 3.0 or newer and by the     GL_ARB_vertex_array_object for older versions. On OpenGL ES 2, VAOs are provided by     the optional GL_OES_vertex_array_object extension. You can check the version of     OpenGL with QOpenGLContext::surfaceFormat() and check for the presence of extensions     with QOpenGLContext::hasExtension().      As with the other Qt OpenGL classes, QOpenGLVertexArrayObject has a create()     function to create the underlying OpenGL object. This is to allow the developer to     ensure that there is a valid current OpenGL context at the time.      Once you have successfully created a VAO the typical usage pattern is:      \list         \li In scene initialization function, for each visual object:         \list             \li Bind the VAO             \li Set vertex data state for this visual object (vertices, normals, texture coordinates etc.)             \li Unbind (release()) the VAO         \endlist         \li In render function, for each visual object:         \list             \li Bind the VAO (and shader program if needed)             \li Call a glDraw*() function             \li Unbind (release()) the VAO         \endlist     \endlist      The act of binding the VAO in the render function has the effect of restoring     all of the vertex data state setup in the initialization phase. In this way we can     set a great deal of state when setting up a VAO and efficiently switch between     state sets of objects to be rendered. Using VAOs also allows the OpenGL driver     to amortise the validation checks of the vertex data.      \note Vertex Array Objects, like all other OpenGL container objects, are specific     to the context for which they were created and cannot be shared amongst a     context group.      \sa QOpenGLVertexArrayObject::Binder, QOpenGLBuffer */
end_comment
begin_comment
comment|/*!     Creates a QOpenGLVertexArrayObject with the given \a parent. You must call create()     with a valid OpenGL context before using. */
end_comment
begin_constructor
DECL|function|QOpenGLVertexArrayObject
name|QOpenGLVertexArrayObject
operator|::
name|QOpenGLVertexArrayObject
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QOpenGLVertexArrayObjectPrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QOpenGLVertexArrayObject
name|QOpenGLVertexArrayObject
operator|::
name|QOpenGLVertexArrayObject
parameter_list|(
name|QOpenGLVertexArrayObjectPrivate
modifier|&
name|dd
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|dd
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the QOpenGLVertexArrayObject and the underlying OpenGL resource. */
end_comment
begin_destructor
DECL|function|~QOpenGLVertexArrayObject
name|QOpenGLVertexArrayObject
operator|::
name|~
name|QOpenGLVertexArrayObject
parameter_list|()
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
name|Q_D
argument_list|(
name|QOpenGLVertexArrayObject
argument_list|)
expr_stmt|;
name|QOpenGLContext
modifier|*
name|oldContext
init|=
literal|0
decl_stmt|;
name|QScopedPointer
argument_list|<
name|QOffscreenSurface
argument_list|>
name|offscreenSurface
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|context
operator|&&
name|ctx
operator|&&
name|d
operator|->
name|context
operator|!=
name|ctx
condition|)
block|{
name|oldContext
operator|=
name|ctx
expr_stmt|;
comment|// Cannot just make the current surface current again with another context.
comment|// The format may be incompatible and some platforms (iOS) may impose
comment|// restrictions on using a window with different contexts. Create an
comment|// offscreen surface (a pbuffer or a hidden window) instead to be safe.
name|offscreenSurface
operator|.
name|reset
argument_list|(
operator|new
name|QOffscreenSurface
argument_list|)
expr_stmt|;
name|offscreenSurface
operator|->
name|setFormat
argument_list|(
name|d
operator|->
name|context
operator|->
name|format
argument_list|()
argument_list|)
expr_stmt|;
name|offscreenSurface
operator|->
name|create
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|context
operator|->
name|makeCurrent
argument_list|(
name|offscreenSurface
operator|.
name|data
argument_list|()
argument_list|)
condition|)
block|{
name|ctx
operator|=
name|d
operator|->
name|context
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QOpenGLVertexArrayObject::~QOpenGLVertexArrayObject() failed to make VAO's context current"
argument_list|)
expr_stmt|;
name|ctx
operator|=
literal|0
expr_stmt|;
block|}
block|}
if|if
condition|(
name|ctx
condition|)
name|destroy
argument_list|()
expr_stmt|;
if|if
condition|(
name|oldContext
condition|)
block|{
if|if
condition|(
operator|!
name|oldContext
operator|->
name|makeCurrent
argument_list|(
name|oldContext
operator|->
name|surface
argument_list|()
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"QOpenGLVertexArrayObject::~QOpenGLVertexArrayObject() failed to restore current context"
argument_list|)
expr_stmt|;
block|}
block|}
end_destructor
begin_comment
comment|/*!     Creates the underlying OpenGL vertex array object. There must be a valid OpenGL context     that supports vertex array objects current for this function to succeed.      Returns \c true if the OpenGL vertex array object was successfully created. */
end_comment
begin_function
DECL|function|create
name|bool
name|QOpenGLVertexArrayObject
operator|::
name|create
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLVertexArrayObject
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|create
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Destroys the underlying OpenGL vertex array object. There must be a valid OpenGL context     that supports vertex array objects current for this function to succeed. */
end_comment
begin_function
DECL|function|destroy
name|void
name|QOpenGLVertexArrayObject
operator|::
name|destroy
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLVertexArrayObject
argument_list|)
expr_stmt|;
name|d
operator|->
name|destroy
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true is the underlying OpenGL vertex array object has been created. If this     returns \c true and the associated OpenGL context is current, then you are able to bind()     this object. */
end_comment
begin_function
DECL|function|isCreated
name|bool
name|QOpenGLVertexArrayObject
operator|::
name|isCreated
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOpenGLVertexArrayObject
argument_list|)
expr_stmt|;
return|return
operator|(
name|d
operator|->
name|vao
operator|!=
literal|0
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the id of the underlying OpenGL vertex array object. */
end_comment
begin_function
DECL|function|objectId
name|GLuint
name|QOpenGLVertexArrayObject
operator|::
name|objectId
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOpenGLVertexArrayObject
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|vao
return|;
block|}
end_function
begin_comment
comment|/*!     Binds this vertex array object to the OpenGL binding point. From this point on     and until release() is called or another vertex array object is bound, any     modifications made to vertex data state are stored inside this vertex array object.      If another vertex array object is then bound you can later restore the set of     state associated with this object by calling bind() on this object once again.     This allows efficient changes between vertex data states in rendering functions. */
end_comment
begin_function
DECL|function|bind
name|void
name|QOpenGLVertexArrayObject
operator|::
name|bind
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLVertexArrayObject
argument_list|)
expr_stmt|;
name|d
operator|->
name|bind
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Unbinds this vertex array object by binding the default vertex array object (id = 0). */
end_comment
begin_function
DECL|function|release
name|void
name|QOpenGLVertexArrayObject
operator|::
name|release
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLVertexArrayObject
argument_list|)
expr_stmt|;
name|d
operator|->
name|release
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QOpenGLVertexArrayObject::Binder     \brief The QOpenGLVertexArrayObject::Binder class is a convenience class to help     with the binding and releasing of OpenGL Vertex Array Objects.     \inmodule QtGui     \reentrant     \since 5.1     \ingroup painting-3D      QOpenGLVertexArrayObject::Binder is a simple convenience class that can be used     to assist with the binding and releasing of QOpenGLVertexArrayObject instances.     This class is to QOpenGLVertexArrayObject as QMutexLocker is to QMutex.      This class implements the RAII principle which helps to ensure behavior in     complex code or in the presence of exceptions.      The constructor of this class accepts a QOpenGLVertexArrayObject (VAO) as an     argument and attempts to bind the VAO, calling QOpenGLVertexArrayObject::create()     if necessary. The destructor of this class calls QOpenGLVertexArrayObject::release()     which unbinds the VAO.      If needed the VAO can be temporarily unbound with the release() function and bound     once more with rebind().      \sa QOpenGLVertexArrayObject */
end_comment
begin_comment
comment|/*!     \fn QOpenGLVertexArrayObject::Binder::Binder(QOpenGLVertexArrayObject *v)      Creates a QOpenGLVertexArrayObject::Binder object and binds \a v by calling     QOpenGLVertexArrayObject::bind(). If necessary it first calls     QOpenGLVertexArrayObject::create(). */
end_comment
begin_comment
comment|/*!     \fn QOpenGLVertexArrayObject::Binder::~Binder()      Destroys the QOpenGLVertexArrayObject::Binder and releases the associated vertex array object. */
end_comment
begin_comment
comment|/*!     \fn QOpenGLVertexArrayObject::Binder::release()      Can be used to temporarily release the associated vertex array object.      \sa rebind() */
end_comment
begin_comment
comment|/*!     \fn QOpenGLVertexArrayObject::Binder::rebind()      Can be used to rebind the associated vertex array object.      \sa release() */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qopenglvertexarrayobject.cpp"
end_include
end_unit
