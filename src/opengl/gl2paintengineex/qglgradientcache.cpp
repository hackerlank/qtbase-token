begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qglgradientcache_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qdrawhelper_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qgl_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QGL2GradientCacheWrapper
class|class
name|QGL2GradientCacheWrapper
block|{
public|public:
DECL|function|cacheForContext
name|QGL2GradientCache
modifier|*
name|cacheForContext
parameter_list|(
specifier|const
name|QGLContext
modifier|*
name|context
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_mutex
argument_list|)
decl_stmt|;
return|return
name|m_resource
operator|.
name|value
argument_list|<
name|QGL2GradientCache
argument_list|>
argument_list|(
name|context
operator|->
name|contextHandle
argument_list|()
argument_list|)
return|;
block|}
private|private:
DECL|member|m_resource
name|QGLMultiGroupSharedResource
name|m_resource
decl_stmt|;
DECL|member|m_mutex
name|QMutex
name|m_mutex
decl_stmt|;
block|}
class|;
end_class
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QGL2GradientCacheWrapper
argument_list|,
argument|qt_gradient_caches
argument_list|)
end_macro
begin_constructor
DECL|function|QGL2GradientCache
name|QGL2GradientCache
operator|::
name|QGL2GradientCache
parameter_list|(
name|QGuiGLContext
modifier|*
name|ctx
parameter_list|)
member_init_list|:
name|QGLSharedResource
argument_list|(
name|ctx
operator|->
name|shareGroup
argument_list|()
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QGL2GradientCache
name|QGL2GradientCache
operator|::
name|~
name|QGL2GradientCache
parameter_list|()
block|{
name|cache
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|cacheForContext
name|QGL2GradientCache
modifier|*
name|QGL2GradientCache
operator|::
name|cacheForContext
parameter_list|(
specifier|const
name|QGLContext
modifier|*
name|context
parameter_list|)
block|{
return|return
name|qt_gradient_caches
argument_list|()
operator|->
name|cacheForContext
argument_list|(
name|context
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|invalidateResource
name|void
name|QGL2GradientCache
operator|::
name|invalidateResource
parameter_list|()
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_mutex
argument_list|)
decl_stmt|;
name|cache
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|freeResource
name|void
name|QGL2GradientCache
operator|::
name|freeResource
parameter_list|(
name|QGuiGLContext
modifier|*
parameter_list|)
block|{
name|cleanCache
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanCache
name|void
name|QGL2GradientCache
operator|::
name|cleanCache
parameter_list|()
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_mutex
argument_list|)
decl_stmt|;
name|QGLGradientColorTableHash
operator|::
name|const_iterator
name|it
init|=
name|cache
operator|.
name|constBegin
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|it
operator|!=
name|cache
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
specifier|const
name|CacheInfo
modifier|&
name|cache_info
init|=
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|cache_info
operator|.
name|texId
argument_list|)
expr_stmt|;
block|}
name|cache
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getBuffer
name|GLuint
name|QGL2GradientCache
operator|::
name|getBuffer
parameter_list|(
specifier|const
name|QGradient
modifier|&
name|gradient
parameter_list|,
name|qreal
name|opacity
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_mutex
argument_list|)
decl_stmt|;
name|quint64
name|hash_val
init|=
literal|0
decl_stmt|;
name|QGradientStops
name|stops
init|=
name|gradient
operator|.
name|stops
argument_list|()
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
name|stops
operator|.
name|size
argument_list|()
operator|&&
name|i
operator|<=
literal|2
condition|;
name|i
operator|++
control|)
name|hash_val
operator|+=
name|stops
index|[
name|i
index|]
operator|.
name|second
operator|.
name|rgba
argument_list|()
expr_stmt|;
name|QGLGradientColorTableHash
operator|::
name|const_iterator
name|it
init|=
name|cache
operator|.
name|constFind
argument_list|(
name|hash_val
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|==
name|cache
operator|.
name|constEnd
argument_list|()
condition|)
return|return
name|addCacheElement
argument_list|(
name|hash_val
argument_list|,
name|gradient
argument_list|,
name|opacity
argument_list|)
return|;
else|else
block|{
do|do
block|{
specifier|const
name|CacheInfo
modifier|&
name|cache_info
init|=
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
if|if
condition|(
name|cache_info
operator|.
name|stops
operator|==
name|stops
operator|&&
name|cache_info
operator|.
name|opacity
operator|==
name|opacity
operator|&&
name|cache_info
operator|.
name|interpolationMode
operator|==
name|gradient
operator|.
name|interpolationMode
argument_list|()
condition|)
block|{
return|return
name|cache_info
operator|.
name|texId
return|;
block|}
operator|++
name|it
expr_stmt|;
block|}
do|while
condition|(
name|it
operator|!=
name|cache
operator|.
name|constEnd
argument_list|()
operator|&&
name|it
operator|.
name|key
argument_list|()
operator|==
name|hash_val
condition|)
do|;
comment|// an exact match for these stops and opacity was not found, create new cache
return|return
name|addCacheElement
argument_list|(
name|hash_val
argument_list|,
name|gradient
argument_list|,
name|opacity
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|addCacheElement
name|GLuint
name|QGL2GradientCache
operator|::
name|addCacheElement
parameter_list|(
name|quint64
name|hash_val
parameter_list|,
specifier|const
name|QGradient
modifier|&
name|gradient
parameter_list|,
name|qreal
name|opacity
parameter_list|)
block|{
if|if
condition|(
name|cache
operator|.
name|size
argument_list|()
operator|==
name|maxCacheSize
argument_list|()
condition|)
block|{
name|int
name|elem_to_remove
init|=
name|qrand
argument_list|()
operator|%
name|maxCacheSize
argument_list|()
decl_stmt|;
name|quint64
name|key
init|=
name|cache
operator|.
name|keys
argument_list|()
index|[
name|elem_to_remove
index|]
decl_stmt|;
comment|// need to call glDeleteTextures on each removed cache entry:
name|QGLGradientColorTableHash
operator|::
name|const_iterator
name|it
init|=
name|cache
operator|.
name|constFind
argument_list|(
name|key
argument_list|)
decl_stmt|;
do|do
block|{
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|it
operator|.
name|value
argument_list|()
operator|.
name|texId
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|++
name|it
operator|!=
name|cache
operator|.
name|constEnd
argument_list|()
operator|&&
name|it
operator|.
name|key
argument_list|()
operator|==
name|key
condition|)
do|;
name|cache
operator|.
name|remove
argument_list|(
name|key
argument_list|)
expr_stmt|;
comment|// may remove more than 1, but OK
block|}
name|CacheInfo
name|cache_entry
argument_list|(
name|gradient
operator|.
name|stops
argument_list|()
argument_list|,
name|opacity
argument_list|,
name|gradient
operator|.
name|interpolationMode
argument_list|()
argument_list|)
decl_stmt|;
name|uint
name|buffer
index|[
literal|1024
index|]
decl_stmt|;
name|generateGradientColorTable
argument_list|(
name|gradient
argument_list|,
name|buffer
argument_list|,
name|paletteSize
argument_list|()
argument_list|,
name|opacity
argument_list|)
expr_stmt|;
name|glGenTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|cache_entry
operator|.
name|texId
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|cache_entry
operator|.
name|texId
argument_list|)
expr_stmt|;
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|paletteSize
argument_list|()
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
return|return
name|cache
operator|.
name|insert
argument_list|(
name|hash_val
argument_list|,
name|cache_entry
argument_list|)
operator|.
name|value
argument_list|()
operator|.
name|texId
return|;
block|}
end_function
begin_comment
comment|// GL's expects pixels in RGBA (when using GL_RGBA), bin-endian (ABGR on x86).
end_comment
begin_comment
comment|// Qt always stores in ARGB reguardless of the byte-order the mancine uses.
end_comment
begin_function
DECL|function|qtToGlColor
specifier|static
specifier|inline
name|uint
name|qtToGlColor
parameter_list|(
name|uint
name|c
parameter_list|)
block|{
name|uint
name|o
decl_stmt|;
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_LITTLE_ENDIAN
name|o
operator|=
operator|(
name|c
operator|&
literal|0xff00ff00
operator|)
comment|// alpha& green already in the right place
operator||
operator|(
operator|(
name|c
operator|>>
literal|16
operator|)
operator|&
literal|0x000000ff
operator|)
comment|// red
operator||
operator|(
operator|(
name|c
operator|<<
literal|16
operator|)
operator|&
literal|0x00ff0000
operator|)
expr_stmt|;
comment|// blue
else|#
directive|else
comment|//Q_BIG_ENDIAN
name|o
operator|=
operator|(
name|c
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|c
operator|>>
literal|24
operator|)
operator|&
literal|0x000000ff
operator|)
expr_stmt|;
endif|#
directive|endif
comment|// Q_BYTE_ORDER
return|return
name|o
return|;
block|}
end_function
begin_comment
comment|//TODO: Let GL generate the texture using an FBO
end_comment
begin_function
DECL|function|generateGradientColorTable
name|void
name|QGL2GradientCache
operator|::
name|generateGradientColorTable
parameter_list|(
specifier|const
name|QGradient
modifier|&
name|gradient
parameter_list|,
name|uint
modifier|*
name|colorTable
parameter_list|,
name|int
name|size
parameter_list|,
name|qreal
name|opacity
parameter_list|)
specifier|const
block|{
name|int
name|pos
init|=
literal|0
decl_stmt|;
name|QGradientStops
name|s
init|=
name|gradient
operator|.
name|stops
argument_list|()
decl_stmt|;
name|QVector
argument_list|<
name|uint
argument_list|>
name|colors
argument_list|(
name|s
operator|.
name|size
argument_list|()
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
name|s
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|colors
index|[
name|i
index|]
operator|=
name|s
index|[
name|i
index|]
operator|.
name|second
operator|.
name|rgba
argument_list|()
expr_stmt|;
comment|// Qt LIES! It returns ARGB (on little-endian AND on big-endian)
name|bool
name|colorInterpolation
init|=
operator|(
name|gradient
operator|.
name|interpolationMode
argument_list|()
operator|==
name|QGradient
operator|::
name|ColorInterpolation
operator|)
decl_stmt|;
name|uint
name|alpha
init|=
name|qRound
argument_list|(
name|opacity
operator|*
literal|256
argument_list|)
decl_stmt|;
name|uint
name|current_color
init|=
name|ARGB_COMBINE_ALPHA
argument_list|(
name|colors
index|[
literal|0
index|]
argument_list|,
name|alpha
argument_list|)
decl_stmt|;
name|qreal
name|incr
init|=
literal|1.0
operator|/
name|qreal
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|qreal
name|fpos
init|=
literal|1.5
operator|*
name|incr
decl_stmt|;
name|colorTable
index|[
name|pos
operator|++
index|]
operator|=
name|qtToGlColor
argument_list|(
name|PREMUL
argument_list|(
name|current_color
argument_list|)
argument_list|)
expr_stmt|;
while|while
condition|(
name|fpos
operator|<=
name|s
operator|.
name|first
argument_list|()
operator|.
name|first
condition|)
block|{
name|colorTable
index|[
name|pos
index|]
operator|=
name|colorTable
index|[
name|pos
operator|-
literal|1
index|]
expr_stmt|;
name|pos
operator|++
expr_stmt|;
name|fpos
operator|+=
name|incr
expr_stmt|;
block|}
if|if
condition|(
name|colorInterpolation
condition|)
name|current_color
operator|=
name|PREMUL
argument_list|(
name|current_color
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|s
operator|.
name|size
argument_list|()
operator|-
literal|1
condition|;
operator|++
name|i
control|)
block|{
name|qreal
name|delta
init|=
literal|1
operator|/
operator|(
name|s
index|[
name|i
operator|+
literal|1
index|]
operator|.
name|first
operator|-
name|s
index|[
name|i
index|]
operator|.
name|first
operator|)
decl_stmt|;
name|uint
name|next_color
init|=
name|ARGB_COMBINE_ALPHA
argument_list|(
name|colors
index|[
name|i
operator|+
literal|1
index|]
argument_list|,
name|alpha
argument_list|)
decl_stmt|;
if|if
condition|(
name|colorInterpolation
condition|)
name|next_color
operator|=
name|PREMUL
argument_list|(
name|next_color
argument_list|)
expr_stmt|;
while|while
condition|(
name|fpos
operator|<
name|s
index|[
name|i
operator|+
literal|1
index|]
operator|.
name|first
operator|&&
name|pos
operator|<
name|size
condition|)
block|{
name|int
name|dist
init|=
name|int
argument_list|(
literal|256
operator|*
operator|(
operator|(
name|fpos
operator|-
name|s
index|[
name|i
index|]
operator|.
name|first
operator|)
operator|*
name|delta
operator|)
argument_list|)
decl_stmt|;
name|int
name|idist
init|=
literal|256
operator|-
name|dist
decl_stmt|;
if|if
condition|(
name|colorInterpolation
condition|)
name|colorTable
index|[
name|pos
index|]
operator|=
name|qtToGlColor
argument_list|(
name|INTERPOLATE_PIXEL_256
argument_list|(
name|current_color
argument_list|,
name|idist
argument_list|,
name|next_color
argument_list|,
name|dist
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|colorTable
index|[
name|pos
index|]
operator|=
name|qtToGlColor
argument_list|(
name|PREMUL
argument_list|(
name|INTERPOLATE_PIXEL_256
argument_list|(
name|current_color
argument_list|,
name|idist
argument_list|,
name|next_color
argument_list|,
name|dist
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
operator|++
name|pos
expr_stmt|;
name|fpos
operator|+=
name|incr
expr_stmt|;
block|}
name|current_color
operator|=
name|next_color
expr_stmt|;
block|}
name|Q_ASSERT
argument_list|(
name|s
operator|.
name|size
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
name|uint
name|last_color
init|=
name|qtToGlColor
argument_list|(
name|PREMUL
argument_list|(
name|ARGB_COMBINE_ALPHA
argument_list|(
name|colors
index|[
name|s
operator|.
name|size
argument_list|()
operator|-
literal|1
index|]
argument_list|,
name|alpha
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
for|for
control|(
init|;
name|pos
operator|<
name|size
condition|;
operator|++
name|pos
control|)
name|colorTable
index|[
name|pos
index|]
operator|=
name|last_color
expr_stmt|;
comment|// Make sure the last color stop is represented at the end of the table
name|colorTable
index|[
name|size
operator|-
literal|1
index|]
operator|=
name|last_color
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
