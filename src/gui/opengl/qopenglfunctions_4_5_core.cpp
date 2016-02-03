begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Klaralvdalens Datakonsult AB (KDAB) ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ** ** This file was generated by glgen version 0.1 ** Command line was: glgen ** ** glgen is Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB) ** ** This is an auto-generated file. ** Do not edit! All changes made to it will be lost. ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenglfunctions_4_5_core.h"
end_include
begin_include
include|#
directive|include
file|"qopenglcontext.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QOpenGLFunctions_4_5_Core     \inmodule QtGui     \since 5.5     \wrapper     \brief The QOpenGLFunctions_4_5_Core class provides all functions for OpenGL 4.5 core profile.      This class is a wrapper for functions from OpenGL 4.5 core profile.     See reference pages on \l {http://www.opengl.org/sdk/docs/}{opengl.org}     for function documentation.      \sa QAbstractOpenGLFunctions */
end_comment
begin_constructor
DECL|function|QOpenGLFunctions_4_5_Core
name|QOpenGLFunctions_4_5_Core
operator|::
name|QOpenGLFunctions_4_5_Core
parameter_list|()
member_init_list|:
name|QAbstractOpenGLFunctions
argument_list|()
member_init_list|,
name|d_1_0_Core
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_1_1_Core
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_1_2_Core
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_1_3_Core
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_1_4_Core
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_1_5_Core
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_2_0_Core
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_2_1_Core
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_3_0_Core
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_3_1_Core
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_3_2_Core
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_3_3_Core
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_4_0_Core
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_4_1_Core
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_4_2_Core
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_4_3_Core
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_4_4_Core
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_4_5_Core
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QOpenGLFunctions_4_5_Core
name|QOpenGLFunctions_4_5_Core
operator|::
name|~
name|QOpenGLFunctions_4_5_Core
parameter_list|()
block|{
if|if
condition|(
name|d_1_0_Core
condition|)
name|d_1_0_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_1_0_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_1_1_Core
condition|)
name|d_1_1_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_1_1_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_1_2_Core
condition|)
name|d_1_2_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_1_2_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_1_3_Core
condition|)
name|d_1_3_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_1_3_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_1_4_Core
condition|)
name|d_1_4_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_1_4_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_1_5_Core
condition|)
name|d_1_5_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_1_5_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_2_0_Core
condition|)
name|d_2_0_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_2_0_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_2_1_Core
condition|)
name|d_2_1_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_2_1_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_3_0_Core
condition|)
name|d_3_0_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_3_0_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_3_1_Core
condition|)
name|d_3_1_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_3_1_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_3_2_Core
condition|)
name|d_3_2_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_3_2_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_3_3_Core
condition|)
name|d_3_3_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_3_3_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_4_0_Core
condition|)
name|d_4_0_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_4_0_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_4_1_Core
condition|)
name|d_4_1_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_4_1_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_4_2_Core
condition|)
name|d_4_2_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_4_2_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_4_3_Core
condition|)
name|d_4_3_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_4_3_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_4_4_Core
condition|)
name|d_4_4_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_4_4_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_4_5_Core
condition|)
name|d_4_5_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d_4_5_Core
operator|->
name|refs
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|initializeOpenGLFunctions
name|bool
name|QOpenGLFunctions_4_5_Core
operator|::
name|initializeOpenGLFunctions
parameter_list|()
block|{
if|if
condition|(
name|isInitialized
argument_list|()
condition|)
return|return
literal|true
return|;
name|QOpenGLContext
modifier|*
name|context
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
comment|// If owned by a context object make sure it is current.
comment|// Also check that current context is capable of resolving all needed functions
if|if
condition|(
operator|(
operator|(
name|owningContext
argument_list|()
operator|&&
name|owningContext
argument_list|()
operator|==
name|context
operator|)
operator|||
operator|!
name|owningContext
argument_list|()
operator|)
operator|&&
name|QOpenGLFunctions_4_5_Core
operator|::
name|isContextCompatible
argument_list|(
name|context
argument_list|)
condition|)
block|{
comment|// Associate with private implementation, creating if necessary
comment|// Function pointers in the backends are resolved at creation time
name|QOpenGLVersionFunctionsBackend
modifier|*
name|d
init|=
literal|0
decl_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_1_0_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_1_0_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_1_0_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_1_1_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_1_1_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_1_1_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_1_2_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_1_2_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_1_2_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_1_3_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_1_3_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_1_3_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_1_4_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_1_4_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_1_4_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_1_5_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_1_5_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_1_5_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_2_0_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_2_0_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_2_0_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_2_1_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_2_1_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_2_1_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_3_0_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_3_0_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_3_0_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_3_1_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_3_1_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_3_1_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_3_2_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_3_2_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_3_2_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_3_3_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_3_3_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_3_3_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_4_0_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_4_0_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_4_0_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_4_1_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_4_1_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_4_1_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_4_2_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_4_2_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_4_2_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_4_3_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_4_3_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_4_3_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_4_4_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_4_4_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_4_4_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|d
operator|=
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_4_5_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
name|d_4_5_Core
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_4_5_CoreBackend
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|refs
operator|.
name|ref
argument_list|()
expr_stmt|;
name|QAbstractOpenGLFunctions
operator|::
name|initializeOpenGLFunctions
argument_list|()
expr_stmt|;
block|}
return|return
name|isInitialized
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isContextCompatible
name|bool
name|QOpenGLFunctions_4_5_Core
operator|::
name|isContextCompatible
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
name|QSurfaceFormat
name|f
init|=
name|context
operator|->
name|format
argument_list|()
decl_stmt|;
specifier|const
name|QPair
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|v
init|=
name|qMakePair
argument_list|(
name|f
operator|.
name|majorVersion
argument_list|()
argument_list|,
name|f
operator|.
name|minorVersion
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|v
operator|<
name|qMakePair
argument_list|(
literal|4
argument_list|,
literal|5
argument_list|)
condition|)
return|return
literal|false
return|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|versionProfile
name|QOpenGLVersionProfile
name|QOpenGLFunctions_4_5_Core
operator|::
name|versionProfile
parameter_list|()
block|{
name|QOpenGLVersionProfile
name|v
decl_stmt|;
name|v
operator|.
name|setVersion
argument_list|(
literal|4
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|v
operator|.
name|setProfile
argument_list|(
name|QSurfaceFormat
operator|::
name|CoreProfile
argument_list|)
expr_stmt|;
return|return
name|v
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
