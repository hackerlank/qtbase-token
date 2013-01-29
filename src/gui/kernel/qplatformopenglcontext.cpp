begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformopenglcontext.h"
end_include
begin_include
include|#
directive|include
file|<QOpenGLFunctions>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QPlatformOpenGLContext     \since 4.8     \internal     \preliminary     \ingroup qpa      \brief The QPlatformOpenGLContext class provides an abstraction for native GL contexts.      In QPA the way to support OpenGL or OpenVG or other technologies that requires a native GL     context is through the QPlatformOpenGLContext wrapper.      There is no factory function for QPlatformOpenGLContexts, but rather only one accessor function.     The only place to retrieve a QPlatformOpenGLContext from is through a QPlatformWindow.      The context which is current for a specific thread can be collected by the currentContext()     function. This is how QPlatformOpenGLContext also makes it possible to use the Qt GUI module     withhout using QOpenGLWidget. When using QOpenGLContext::currentContext(), it will ask     QPlatformOpenGLContext for the currentContext. Then a corresponding QOpenGLContext will be returned,     which maps to the QPlatformOpenGLContext. */
end_comment
begin_comment
comment|/*! \fn void QPlatformOpenGLContext::swapBuffers(QPlatformSurface *surface)     Reimplement in subclass to native swap buffers calls      The implementation must support being called in a thread different than the gui-thread. */
end_comment
begin_comment
comment|/*! \fn QFunctionPointer QPlatformOpenGLContext::getProcAddress(const QByteArray&procName)     Reimplement in subclass to native getProcAddr calls.      Note: its convenient to use qPrintable(const QString&str) to get the const char * pointer */
end_comment
begin_class
DECL|class|QPlatformOpenGLContextPrivate
class|class
name|QPlatformOpenGLContextPrivate
block|{
public|public:
DECL|function|QPlatformOpenGLContextPrivate
name|QPlatformOpenGLContextPrivate
parameter_list|()
member_init_list|:
name|context
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|context
name|QOpenGLContext
modifier|*
name|context
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QPlatformOpenGLContext
name|QPlatformOpenGLContext
operator|::
name|QPlatformOpenGLContext
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QPlatformOpenGLContextPrivate
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QPlatformOpenGLContext
name|QPlatformOpenGLContext
operator|::
name|~
name|QPlatformOpenGLContext
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Reimplement in subclass if your platform uses framebuffer objects for surfaces.      The default implementation returns 0. */
end_comment
begin_function
DECL|function|defaultFramebufferObject
name|GLuint
name|QPlatformOpenGLContext
operator|::
name|defaultFramebufferObject
parameter_list|(
name|QPlatformSurface
modifier|*
parameter_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|context
name|QOpenGLContext
modifier|*
name|QPlatformOpenGLContext
operator|::
name|context
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPlatformOpenGLContext
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|context
return|;
block|}
end_function
begin_function
DECL|function|setContext
name|void
name|QPlatformOpenGLContext
operator|::
name|setContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPlatformOpenGLContext
argument_list|)
expr_stmt|;
name|d
operator|->
name|context
operator|=
name|context
expr_stmt|;
block|}
end_function
begin_function
DECL|function|parseOpenGLVersion
name|bool
name|QPlatformOpenGLContext
operator|::
name|parseOpenGLVersion
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|versionString
parameter_list|,
name|int
modifier|&
name|major
parameter_list|,
name|int
modifier|&
name|minor
parameter_list|)
block|{
name|bool
name|majorOk
init|=
literal|false
decl_stmt|;
name|bool
name|minorOk
init|=
literal|false
decl_stmt|;
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|parts
init|=
name|versionString
operator|.
name|split
argument_list|(
literal|' '
argument_list|)
decl_stmt|;
if|if
condition|(
name|versionString
operator|.
name|startsWith
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"OpenGL ES"
argument_list|)
argument_list|)
condition|)
block|{
if|if
condition|(
name|parts
operator|.
name|size
argument_list|()
operator|>=
literal|3
condition|)
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|versionParts
init|=
name|parts
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|split
argument_list|(
literal|'.'
argument_list|)
decl_stmt|;
if|if
condition|(
name|versionParts
operator|.
name|size
argument_list|()
operator|>=
literal|2
condition|)
block|{
name|major
operator|=
name|versionParts
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|(
operator|&
name|majorOk
argument_list|)
expr_stmt|;
name|minor
operator|=
name|versionParts
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|(
operator|&
name|minorOk
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"Unrecognized OpenGL ES version"
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// If< 3 parts to the name, it is an unrecognised OpenGL ES
name|qWarning
argument_list|(
literal|"Unrecognised OpenGL ES version"
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// Not OpenGL ES, but regular OpenGL, the version numbers are first in the string
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|versionParts
init|=
name|parts
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|split
argument_list|(
literal|'.'
argument_list|)
decl_stmt|;
if|if
condition|(
name|versionParts
operator|.
name|size
argument_list|()
operator|>=
literal|2
condition|)
block|{
name|major
operator|=
name|versionParts
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|(
operator|&
name|majorOk
argument_list|)
expr_stmt|;
name|minor
operator|=
name|versionParts
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|(
operator|&
name|minorOk
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"Unrecognized OpenGL version"
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|majorOk
operator|||
operator|!
name|minorOk
condition|)
name|qWarning
argument_list|(
literal|"Unrecognized OpenGL version"
argument_list|)
expr_stmt|;
return|return
operator|(
name|majorOk
operator|&&
name|minorOk
operator|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
