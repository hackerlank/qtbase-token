begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformglcontext_qpa.h"
end_include
begin_comment
comment|/*!     \class QPlatformGLContext     \since 4.8     \internal     \preliminary     \ingroup qpa      \brief The QPlatformGLContext class provides an abstraction for native GL contexts.      In QPA the way to support OpenGL or OpenVG or other technologies that requires a native GL     context is through the QPlatformGLContext wrapper.      There is no factory function for QPlatformGLContexts, but rather only one accessor function.     The only place to retrieve a QPlatformGLContext from is through a QPlatformWindow.      The context which is current for a specific thread can be collected by the currentContext()     function. This is how QPlatformGLContext also makes it possible to use the QtOpenGL module     withhout using QGLWidget. When using QGLContext::currentContext(), it will ask     QPlatformGLContext for the currentContext. Then a corresponding QGLContext will be returned,     which maps to the QPlatformGLContext. */
end_comment
begin_comment
comment|/*! \fn void QPlatformGLContext::swapBuffers()     Reimplement in subclass to native swap buffers calls      The implementation must support being called in a thread different than the gui-thread. */
end_comment
begin_comment
comment|/*! \fn void *QPlatformGLContext::getProcAddress(const QString&procName)     Reimplement in subclass to native getProcAddr calls.      Note: its convenient to use qPrintable(const QString&str) to get the const char * pointer */
end_comment
begin_comment
comment|/*! \fn QPlatformWindowFormat QPlatformGLContext::platformWindowFormat() const     QWidget has the function qplatformWindowFormat(). That function is for the application     programmer to request the format of the window and the context that he wants.      Reimplement this function in a subclass to indicate what format the glContext actually has. */
end_comment
begin_struct
DECL|struct|QPlatformGLContextPrivate
struct|struct
name|QPlatformGLContextPrivate
block|{
DECL|member|context
name|QGuiGLContext
modifier|*
name|context
decl_stmt|;
block|}
struct|;
end_struct
begin_constructor
DECL|function|QPlatformGLContext
name|QPlatformGLContext
operator|::
name|QPlatformGLContext
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QPlatformGLContextPrivate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QPlatformGLContext
argument_list|)
expr_stmt|;
name|d
operator|->
name|context
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QPlatformGLContext
name|QPlatformGLContext
operator|::
name|~
name|QPlatformGLContext
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|context
name|QGuiGLContext
modifier|*
name|QPlatformGLContext
operator|::
name|context
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPlatformGLContext
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
name|QPlatformGLContext
operator|::
name|setContext
parameter_list|(
name|QGuiGLContext
modifier|*
name|context
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPlatformGLContext
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
end_unit
