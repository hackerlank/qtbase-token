begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB) ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ** ** This file was generated by glgen version 0.1 ** Command line was: glgen ** ** glgen is Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB) ** ** This is an auto-generated file. ** Do not edit! All changes made to it will be lost. ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenglfunctions_1_3.h"
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
comment|/*!     \class QOpenGLFunctions_1_3     \inmodule QtGui     \since 5.1     \wrapper     \brief The QOpenGLFunctions_1_3 class provides all functions for this version and profile of OpenGL.      \sa QAbstractOpenGLFunctions */
end_comment
begin_constructor
DECL|function|QOpenGLFunctions_1_3
name|QOpenGLFunctions_1_3
operator|::
name|QOpenGLFunctions_1_3
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
name|d_1_0_Deprecated
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_1_1_Deprecated
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_1_2_Deprecated
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d_1_3_Deprecated
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QOpenGLFunctions_1_3
name|QOpenGLFunctions_1_3
operator|::
name|~
name|QOpenGLFunctions_1_3
parameter_list|()
block|{
if|if
condition|(
name|d_1_0_Core
operator|&&
operator|!
name|d_1_0_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
condition|)
block|{
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|removeFunctionsBackend
argument_list|(
name|d_1_0_Core
operator|->
name|context
argument_list|,
name|QOpenGLFunctions_1_0_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|d_1_0_Core
expr_stmt|;
block|}
if|if
condition|(
name|d_1_1_Core
operator|&&
operator|!
name|d_1_1_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
condition|)
block|{
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|removeFunctionsBackend
argument_list|(
name|d_1_1_Core
operator|->
name|context
argument_list|,
name|QOpenGLFunctions_1_1_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|d_1_1_Core
expr_stmt|;
block|}
if|if
condition|(
name|d_1_2_Core
operator|&&
operator|!
name|d_1_2_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
condition|)
block|{
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|removeFunctionsBackend
argument_list|(
name|d_1_2_Core
operator|->
name|context
argument_list|,
name|QOpenGLFunctions_1_2_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|d_1_2_Core
expr_stmt|;
block|}
if|if
condition|(
name|d_1_3_Core
operator|&&
operator|!
name|d_1_3_Core
operator|->
name|refs
operator|.
name|deref
argument_list|()
condition|)
block|{
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|removeFunctionsBackend
argument_list|(
name|d_1_3_Core
operator|->
name|context
argument_list|,
name|QOpenGLFunctions_1_3_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|d_1_3_Core
expr_stmt|;
block|}
if|if
condition|(
name|d_1_0_Deprecated
operator|&&
operator|!
name|d_1_0_Deprecated
operator|->
name|refs
operator|.
name|deref
argument_list|()
condition|)
block|{
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|removeFunctionsBackend
argument_list|(
name|d_1_0_Deprecated
operator|->
name|context
argument_list|,
name|QOpenGLFunctions_1_0_DeprecatedBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|d_1_0_Deprecated
expr_stmt|;
block|}
if|if
condition|(
name|d_1_1_Deprecated
operator|&&
operator|!
name|d_1_1_Deprecated
operator|->
name|refs
operator|.
name|deref
argument_list|()
condition|)
block|{
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|removeFunctionsBackend
argument_list|(
name|d_1_1_Deprecated
operator|->
name|context
argument_list|,
name|QOpenGLFunctions_1_1_DeprecatedBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|d_1_1_Deprecated
expr_stmt|;
block|}
if|if
condition|(
name|d_1_2_Deprecated
operator|&&
operator|!
name|d_1_2_Deprecated
operator|->
name|refs
operator|.
name|deref
argument_list|()
condition|)
block|{
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|removeFunctionsBackend
argument_list|(
name|d_1_2_Deprecated
operator|->
name|context
argument_list|,
name|QOpenGLFunctions_1_2_DeprecatedBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|d_1_2_Deprecated
expr_stmt|;
block|}
if|if
condition|(
name|d_1_3_Deprecated
operator|&&
operator|!
name|d_1_3_Deprecated
operator|->
name|refs
operator|.
name|deref
argument_list|()
condition|)
block|{
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|removeFunctionsBackend
argument_list|(
name|d_1_3_Deprecated
operator|->
name|context
argument_list|,
name|QOpenGLFunctions_1_3_DeprecatedBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|d_1_3_Deprecated
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|initializeOpenGLFunctions
name|bool
name|QOpenGLFunctions_1_3
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
name|QOpenGLFunctions_1_3
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
if|if
condition|(
operator|!
name|d
condition|)
block|{
name|d
operator|=
operator|new
name|QOpenGLFunctions_1_0_CoreBackend
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|insertFunctionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_1_0_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|,
name|d
argument_list|)
expr_stmt|;
block|}
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
if|if
condition|(
operator|!
name|d
condition|)
block|{
name|d
operator|=
operator|new
name|QOpenGLFunctions_1_1_CoreBackend
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|insertFunctionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_1_1_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|,
name|d
argument_list|)
expr_stmt|;
block|}
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
if|if
condition|(
operator|!
name|d
condition|)
block|{
name|d
operator|=
operator|new
name|QOpenGLFunctions_1_2_CoreBackend
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|insertFunctionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_1_2_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|,
name|d
argument_list|)
expr_stmt|;
block|}
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
if|if
condition|(
operator|!
name|d
condition|)
block|{
name|d
operator|=
operator|new
name|QOpenGLFunctions_1_3_CoreBackend
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|insertFunctionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_1_3_CoreBackend
operator|::
name|versionStatus
argument_list|()
argument_list|,
name|d
argument_list|)
expr_stmt|;
block|}
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
name|QOpenGLFunctions_1_0_DeprecatedBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
condition|)
block|{
name|d
operator|=
operator|new
name|QOpenGLFunctions_1_0_DeprecatedBackend
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|insertFunctionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_1_0_DeprecatedBackend
operator|::
name|versionStatus
argument_list|()
argument_list|,
name|d
argument_list|)
expr_stmt|;
block|}
name|d_1_0_Deprecated
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_1_0_DeprecatedBackend
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
name|QOpenGLFunctions_1_1_DeprecatedBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
condition|)
block|{
name|d
operator|=
operator|new
name|QOpenGLFunctions_1_1_DeprecatedBackend
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|insertFunctionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_1_1_DeprecatedBackend
operator|::
name|versionStatus
argument_list|()
argument_list|,
name|d
argument_list|)
expr_stmt|;
block|}
name|d_1_1_Deprecated
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_1_1_DeprecatedBackend
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
name|QOpenGLFunctions_1_2_DeprecatedBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
condition|)
block|{
name|d
operator|=
operator|new
name|QOpenGLFunctions_1_2_DeprecatedBackend
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|insertFunctionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_1_2_DeprecatedBackend
operator|::
name|versionStatus
argument_list|()
argument_list|,
name|d
argument_list|)
expr_stmt|;
block|}
name|d_1_2_Deprecated
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_1_2_DeprecatedBackend
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
name|QOpenGLFunctions_1_3_DeprecatedBackend
operator|::
name|versionStatus
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
condition|)
block|{
name|d
operator|=
operator|new
name|QOpenGLFunctions_1_3_DeprecatedBackend
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|insertFunctionsBackend
argument_list|(
name|context
argument_list|,
name|QOpenGLFunctions_1_3_DeprecatedBackend
operator|::
name|versionStatus
argument_list|()
argument_list|,
name|d
argument_list|)
expr_stmt|;
block|}
name|d_1_3_Deprecated
operator|=
cast|static_cast
argument_list|<
name|QOpenGLFunctions_1_3_DeprecatedBackend
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
name|QOpenGLFunctions_1_3
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
literal|1
argument_list|,
literal|3
argument_list|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|f
operator|.
name|profile
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|CoreProfile
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
name|QOpenGLFunctions_1_3
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
literal|1
argument_list|,
literal|3
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
