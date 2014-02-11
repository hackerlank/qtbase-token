begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopengltexturecache_p.h"
end_include
begin_include
include|#
directive|include
file|<qopenglfunctions.h>
end_include
begin_include
include|#
directive|include
file|<private/qopenglcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qimagepixmapcleanuphooks_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformpixmap.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QOpenGLTextureCacheWrapper
class|class
name|QOpenGLTextureCacheWrapper
block|{
public|public:
DECL|function|QOpenGLTextureCacheWrapper
name|QOpenGLTextureCacheWrapper
parameter_list|()
block|{
name|QImagePixmapCleanupHooks
operator|::
name|instance
argument_list|()
operator|->
name|addPlatformPixmapModificationHook
argument_list|(
name|cleanupTexturesForPixmapData
argument_list|)
expr_stmt|;
name|QImagePixmapCleanupHooks
operator|::
name|instance
argument_list|()
operator|->
name|addPlatformPixmapDestructionHook
argument_list|(
name|cleanupTexturesForPixmapData
argument_list|)
expr_stmt|;
name|QImagePixmapCleanupHooks
operator|::
name|instance
argument_list|()
operator|->
name|addImageHook
argument_list|(
name|cleanupTexturesForCacheKey
argument_list|)
expr_stmt|;
block|}
DECL|function|~QOpenGLTextureCacheWrapper
name|~
name|QOpenGLTextureCacheWrapper
parameter_list|()
block|{
name|QImagePixmapCleanupHooks
operator|::
name|instance
argument_list|()
operator|->
name|removePlatformPixmapModificationHook
argument_list|(
name|cleanupTexturesForPixmapData
argument_list|)
expr_stmt|;
name|QImagePixmapCleanupHooks
operator|::
name|instance
argument_list|()
operator|->
name|removePlatformPixmapDestructionHook
argument_list|(
name|cleanupTexturesForPixmapData
argument_list|)
expr_stmt|;
name|QImagePixmapCleanupHooks
operator|::
name|instance
argument_list|()
operator|->
name|removeImageHook
argument_list|(
name|cleanupTexturesForCacheKey
argument_list|)
expr_stmt|;
block|}
DECL|function|cacheForContext
name|QOpenGLTextureCache
modifier|*
name|cacheForContext
parameter_list|(
name|QOpenGLContext
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
name|QOpenGLTextureCache
argument_list|>
argument_list|(
name|context
argument_list|)
return|;
block|}
specifier|static
name|void
name|cleanupTexturesForCacheKey
parameter_list|(
name|qint64
name|key
parameter_list|)
function_decl|;
specifier|static
name|void
name|cleanupTexturesForPixmapData
parameter_list|(
name|QPlatformPixmap
modifier|*
name|pmd
parameter_list|)
function_decl|;
private|private:
DECL|member|m_resource
name|QOpenGLMultiGroupSharedResource
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
argument|QOpenGLTextureCacheWrapper
argument_list|,
argument|qt_texture_caches
argument_list|)
end_macro
begin_function
DECL|function|cacheForContext
name|QOpenGLTextureCache
modifier|*
name|QOpenGLTextureCache
operator|::
name|cacheForContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
return|return
name|qt_texture_caches
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
DECL|function|cleanupTexturesForCacheKey
name|void
name|QOpenGLTextureCacheWrapper
operator|::
name|cleanupTexturesForCacheKey
parameter_list|(
name|qint64
name|key
parameter_list|)
block|{
name|QList
argument_list|<
name|QOpenGLSharedResource
modifier|*
argument_list|>
name|resources
init|=
name|qt_texture_caches
argument_list|()
operator|->
name|m_resource
operator|.
name|resources
argument_list|()
decl_stmt|;
for|for
control|(
name|QList
argument_list|<
name|QOpenGLSharedResource
operator|*
argument_list|>
operator|::
name|iterator
name|it
init|=
name|resources
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|resources
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
cast|static_cast
argument_list|<
name|QOpenGLTextureCache
operator|*
argument_list|>
argument_list|(
operator|*
name|it
argument_list|)
operator|->
name|invalidate
argument_list|(
name|key
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTexturesForPixmapData
name|void
name|QOpenGLTextureCacheWrapper
operator|::
name|cleanupTexturesForPixmapData
parameter_list|(
name|QPlatformPixmap
modifier|*
name|pmd
parameter_list|)
block|{
name|cleanupTexturesForCacheKey
argument_list|(
name|pmd
operator|->
name|cacheKey
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QOpenGLTextureCache
name|QOpenGLTextureCache
operator|::
name|QOpenGLTextureCache
parameter_list|(
name|QOpenGLContext
modifier|*
name|ctx
parameter_list|)
member_init_list|:
name|QOpenGLSharedResource
argument_list|(
name|ctx
operator|->
name|shareGroup
argument_list|()
argument_list|)
member_init_list|,
name|m_cache
argument_list|(
literal|64
operator|*
literal|1024
argument_list|)
comment|// 64 MB cache
block|{ }
end_constructor
begin_destructor
DECL|function|~QOpenGLTextureCache
name|QOpenGLTextureCache
operator|::
name|~
name|QOpenGLTextureCache
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|bindTexture
name|GLuint
name|QOpenGLTextureCache
operator|::
name|bindTexture
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
block|{
if|if
condition|(
name|pixmap
operator|.
name|isNull
argument_list|()
condition|)
return|return
literal|0
return|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|m_mutex
argument_list|)
decl_stmt|;
name|qint64
name|key
init|=
name|pixmap
operator|.
name|cacheKey
argument_list|()
decl_stmt|;
comment|// A QPainter is active on the image - take the safe route and replace the texture.
if|if
condition|(
operator|!
name|pixmap
operator|.
name|paintingActive
argument_list|()
condition|)
block|{
name|QOpenGLCachedTexture
modifier|*
name|entry
init|=
name|m_cache
operator|.
name|object
argument_list|(
name|key
argument_list|)
decl_stmt|;
if|if
condition|(
name|entry
condition|)
block|{
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|entry
operator|->
name|id
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|entry
operator|->
name|id
argument_list|()
return|;
block|}
block|}
name|GLuint
name|id
init|=
name|bindTexture
argument_list|(
name|context
argument_list|,
name|key
argument_list|,
name|pixmap
operator|.
name|toImage
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|id
operator|>
literal|0
condition|)
name|QImagePixmapCleanupHooks
operator|::
name|enableCleanupHooks
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
return|return
name|id
return|;
block|}
end_function
begin_comment
comment|// returns the highest number closest to v, which is a power of 2
end_comment
begin_comment
comment|// NB! assumes 32 bit ints
end_comment
begin_function
DECL|function|qt_next_power_of_two
specifier|static
name|int
name|qt_next_power_of_two
parameter_list|(
name|int
name|v
parameter_list|)
block|{
name|v
operator|--
expr_stmt|;
name|v
operator||=
name|v
operator|>>
literal|1
expr_stmt|;
name|v
operator||=
name|v
operator|>>
literal|2
expr_stmt|;
name|v
operator||=
name|v
operator|>>
literal|4
expr_stmt|;
name|v
operator||=
name|v
operator|>>
literal|8
expr_stmt|;
name|v
operator||=
name|v
operator|>>
literal|16
expr_stmt|;
operator|++
name|v
expr_stmt|;
return|return
name|v
return|;
block|}
end_function
begin_function
DECL|function|bindTexture
name|GLuint
name|QOpenGLTextureCache
operator|::
name|bindTexture
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|,
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
if|if
condition|(
name|image
operator|.
name|isNull
argument_list|()
condition|)
return|return
literal|0
return|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|m_mutex
argument_list|)
decl_stmt|;
name|qint64
name|key
init|=
name|image
operator|.
name|cacheKey
argument_list|()
decl_stmt|;
comment|// A QPainter is active on the image - take the safe route and replace the texture.
if|if
condition|(
operator|!
name|image
operator|.
name|paintingActive
argument_list|()
condition|)
block|{
name|QOpenGLCachedTexture
modifier|*
name|entry
init|=
name|m_cache
operator|.
name|object
argument_list|(
name|key
argument_list|)
decl_stmt|;
if|if
condition|(
name|entry
condition|)
block|{
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|entry
operator|->
name|id
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|entry
operator|->
name|id
argument_list|()
return|;
block|}
block|}
name|QImage
name|img
init|=
name|image
decl_stmt|;
if|if
condition|(
operator|!
name|context
operator|->
name|functions
argument_list|()
operator|->
name|hasOpenGLFeature
argument_list|(
name|QOpenGLFunctions
operator|::
name|NPOTTextures
argument_list|)
condition|)
block|{
comment|// Scale the pixmap if needed. GL textures needs to have the
comment|// dimensions 2^n+2(border) x 2^m+2(border), unless we're using GL
comment|// 2.0 or use the GL_TEXTURE_RECTANGLE texture target
name|int
name|tx_w
init|=
name|qt_next_power_of_two
argument_list|(
name|image
operator|.
name|width
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|tx_h
init|=
name|qt_next_power_of_two
argument_list|(
name|image
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|tx_w
operator|!=
name|image
operator|.
name|width
argument_list|()
operator|||
name|tx_h
operator|!=
name|image
operator|.
name|height
argument_list|()
condition|)
block|{
name|img
operator|=
name|img
operator|.
name|scaled
argument_list|(
name|tx_w
argument_list|,
name|tx_h
argument_list|)
expr_stmt|;
block|}
block|}
name|GLuint
name|id
init|=
name|bindTexture
argument_list|(
name|context
argument_list|,
name|key
argument_list|,
name|img
argument_list|)
decl_stmt|;
if|if
condition|(
name|id
operator|>
literal|0
condition|)
name|QImagePixmapCleanupHooks
operator|::
name|enableCleanupHooks
argument_list|(
name|image
argument_list|)
expr_stmt|;
return|return
name|id
return|;
block|}
end_function
begin_function
DECL|function|bindTexture
name|GLuint
name|QOpenGLTextureCache
operator|::
name|bindTexture
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|,
name|qint64
name|key
parameter_list|,
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
name|GLuint
name|id
decl_stmt|;
name|glGenTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|id
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|id
argument_list|)
expr_stmt|;
name|QImage
name|tx
init|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGBA8888_Premultiplied
argument_list|)
decl_stmt|;
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|tx
operator|.
name|width
argument_list|()
argument_list|,
name|tx
operator|.
name|height
argument_list|()
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
cast|const_cast
argument_list|<
specifier|const
name|QImage
operator|&
argument_list|>
argument_list|(
name|tx
argument_list|)
operator|.
name|bits
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|cost
init|=
name|tx
operator|.
name|width
argument_list|()
operator|*
name|tx
operator|.
name|height
argument_list|()
operator|*
literal|4
operator|/
literal|1024
decl_stmt|;
name|m_cache
operator|.
name|insert
argument_list|(
name|key
argument_list|,
operator|new
name|QOpenGLCachedTexture
argument_list|(
name|id
argument_list|,
name|context
argument_list|)
argument_list|,
name|cost
argument_list|)
expr_stmt|;
return|return
name|id
return|;
block|}
end_function
begin_function
DECL|function|invalidate
name|void
name|QOpenGLTextureCache
operator|::
name|invalidate
parameter_list|(
name|qint64
name|key
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|m_mutex
argument_list|)
decl_stmt|;
name|m_cache
operator|.
name|remove
argument_list|(
name|key
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|invalidateResource
name|void
name|QOpenGLTextureCache
operator|::
name|invalidateResource
parameter_list|()
block|{
name|m_cache
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|freeResource
name|void
name|QOpenGLTextureCache
operator|::
name|freeResource
parameter_list|(
name|QOpenGLContext
modifier|*
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
comment|// the texture cache lives until the context group disappears
block|}
end_function
begin_function
DECL|function|freeTexture
specifier|static
name|void
name|freeTexture
parameter_list|(
name|QOpenGLFunctions
modifier|*
parameter_list|,
name|GLuint
name|id
parameter_list|)
block|{
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|id
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QOpenGLCachedTexture
name|QOpenGLCachedTexture
operator|::
name|QOpenGLCachedTexture
parameter_list|(
name|GLuint
name|id
parameter_list|,
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
name|m_resource
operator|=
operator|new
name|QOpenGLSharedResourceGuard
argument_list|(
name|context
argument_list|,
name|id
argument_list|,
name|freeTexture
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
