begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGL_H
end_ifndef
begin_define
DECL|macro|QOPENGL_H
define|#
directive|define
name|QOPENGL_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_include
include|#
directive|include
file|<OpenGLES/ES2/gl.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*    Some GLES2 implementations (like the one on Harmattan) are missing the    typedef for GLchar. Work around it here by adding it. The Kkronos headers    specify GLChar as a typedef to char, so if an implementation already    provides it, then this doesn't do any harm. */
end_comment
begin_typedef
DECL|typedef|GLchar
typedef|typedef
name|char
name|GLchar
typedef|;
end_typedef
begin_include
include|#
directive|include
file|<QtGui/qopengles2ext.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|GL_DOUBLE
end_ifndef
begin_define
DECL|macro|GL_DOUBLE
define|#
directive|define
name|GL_DOUBLE
value|GL_FLOAT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GLdouble
end_ifndef
begin_typedef
DECL|typedef|GLdouble
typedef|typedef
name|GLfloat
name|GLdouble
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_comment
comment|// Mac OSX is a "controlled platform" for OpenGL ABI so we use
end_comment
begin_comment
comment|// the system provided headers there. Controlled means that the
end_comment
begin_comment
comment|// headers always match the actual driver implementation so there
end_comment
begin_comment
comment|// is no possibility of drivers exposing additional functionality
end_comment
begin_comment
comment|// from the system headers. Also it means that the vendor can
end_comment
begin_comment
comment|// (and does) make different choices about some OpenGL types. For
end_comment
begin_comment
comment|// e.g. Apple uses void* for GLhandleARB whereas other platforms
end_comment
begin_comment
comment|// use unsigned int.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// For the "uncontrolled" Windows and Linux platforms we use the
end_comment
begin_comment
comment|// official Khronos glext.h header. On these platforms this gives
end_comment
begin_comment
comment|// access to additional functionality the drivers may expose but
end_comment
begin_comment
comment|// which the system headers do not.
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_include
include|#
directive|include
file|<OpenGL/gl.h>
end_include
begin_if
if|#
directive|if
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|>=
name|MAC_OS_X_VERSION_10_7
end_if
begin_define
DECL|macro|GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
define|#
directive|define
name|GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
end_define
begin_include
include|#
directive|include
file|<OpenGL/gl3.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<OpenGL/glext.h>
end_include
begin_else
else|#
directive|else
end_else
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|GL_GLEXT_LEGACY
define|#
directive|define
name|GL_GLEXT_LEGACY
end_define
begin_comment
DECL|macro|GL_GLEXT_LEGACY
comment|// Prevents GL/gl.h form #including system glext.h
end_comment
begin_include
include|#
directive|include
file|<GL/gl.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopenglext.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_MAC
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Desktops, apart from Mac OS X prior to 10.7 can support OpenGL 3
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|&&
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|>=
name|MAC_OS_X_VERSION_10_7
operator|)
end_if
begin_define
DECL|macro|QT_OPENGL_3
define|#
directive|define
name|QT_OPENGL_3
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|// Types that aren't defined in all system's gl.h files.
end_comment
begin_typedef
DECL|typedef|qopengl_GLintptr
typedef|typedef
name|ptrdiff_t
name|qopengl_GLintptr
typedef|;
end_typedef
begin_typedef
DECL|typedef|qopengl_GLsizeiptr
typedef|typedef
name|ptrdiff_t
name|qopengl_GLsizeiptr
typedef|;
end_typedef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|APIENTRY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QOPENGLF_APIENTRY
argument_list|)
end_if
begin_define
DECL|macro|QOPENGLF_APIENTRY
define|#
directive|define
name|QOPENGLF_APIENTRY
value|APIENTRY
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLF_APIENTRYP
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|QOPENGLF_APIENTRY
end_ifdef
begin_define
DECL|macro|QOPENGLF_APIENTRYP
define|#
directive|define
name|QOPENGLF_APIENTRYP
value|QOPENGLF_APIENTRY *
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QOPENGLF_APIENTRY
define|#
directive|define
name|QOPENGLF_APIENTRY
end_define
begin_define
DECL|macro|QOPENGLF_APIENTRYP
define|#
directive|define
name|QOPENGLF_APIENTRYP
value|*
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
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
comment|// QOPENGL_H
end_comment
end_unit
