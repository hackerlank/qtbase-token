begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_define
DECL|macro|QT_DEBUG_SHADER_CACHE
define|#
directive|define
name|QT_DEBUG_SHADER_CACHE
end_define
begin_define
DECL|macro|QT_MEEGO_EXPERIMENTAL_SHADERCACHE
define|#
directive|define
name|QT_MEEGO_EXPERIMENTAL_SHADERCACHE
end_define
begin_define
DECL|macro|QT_OPENGL_ES_2
define|#
directive|define
name|QT_OPENGL_ES_2
end_define
begin_define
DECL|macro|QT_BOOTSTRAPPED
define|#
directive|define
name|QT_BOOTSTRAPPED
end_define
begin_typedef
DECL|typedef|GLsizei
typedef|typedef
name|int
name|GLsizei
typedef|;
end_typedef
begin_typedef
DECL|typedef|GLenum
typedef|typedef
name|unsigned
name|int
name|GLenum
typedef|;
end_typedef
begin_include
include|#
directive|include
file|"../../gl2paintengineex/qglshadercache_meego_p.h"
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
name|ShaderCacheSharedMemory
name|shm
decl_stmt|;
if|if
condition|(
operator|!
name|shm
operator|.
name|isAttached
argument_list|()
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Unable to attach to shared memory\n"
argument_list|)
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
name|ShaderCacheLocker
name|locker
argument_list|(
operator|&
name|shm
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|locker
operator|.
name|isLocked
argument_list|()
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Unable to lock shared memory\n"
argument_list|)
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
name|void
modifier|*
name|data
init|=
name|shm
operator|.
name|data
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|CachedShaders
modifier|*
name|cache
init|=
cast|reinterpret_cast
argument_list|<
name|CachedShaders
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|cache
operator|->
name|shaderCount
condition|;
operator|++
name|i
control|)
block|{
name|printf
argument_list|(
literal|"Shader %d: %d bytes\n"
argument_list|,
name|i
argument_list|,
name|cache
operator|->
name|headers
index|[
name|i
index|]
operator|.
name|size
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\nSummary:\n\n"
literal|"    Amount of cached shaders: %d\n"
literal|"                  Bytes used: %d\n"
literal|"             Bytes available: %d\n"
argument_list|,
name|cache
operator|->
name|shaderCount
argument_list|,
name|cache
operator|->
name|dataSize
argument_list|,
name|cache
operator|->
name|availableSize
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|EXIT_SUCCESS
return|;
block|}
end_function
end_unit
