begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformbackingstore.h"
end_include
begin_include
include|#
directive|include
file|<qwindow.h>
end_include
begin_include
include|#
directive|include
file|<qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<private/qwindow_p.h>
end_include
begin_include
include|#
directive|include
file|<qopengl.h>
end_include
begin_include
include|#
directive|include
file|<qopenglcontext.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QMatrix4x4>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLShaderProgram>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLFunctions>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|<QtGui/private/qopengltextureblitter_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qpa/qplatformgraphicsbuffer.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformgraphicsbufferhelper.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QPlatformBackingStorePrivate
class|class
name|QPlatformBackingStorePrivate
block|{
public|public:
DECL|function|QPlatformBackingStorePrivate
name|QPlatformBackingStorePrivate
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
member_init_list|:
name|window
argument_list|(
name|w
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
member_init_list|,
name|textureId
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|blitter
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
block|{     }
DECL|function|~QPlatformBackingStorePrivate
name|~
name|QPlatformBackingStorePrivate
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
if|if
condition|(
name|blitter
condition|)
name|blitter
operator|->
name|destroy
argument_list|()
expr_stmt|;
operator|delete
name|blitter
expr_stmt|;
endif|#
directive|endif
block|}
DECL|member|window
name|QWindow
modifier|*
name|window
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
DECL|member|textureId
specifier|mutable
name|GLuint
name|textureId
decl_stmt|;
DECL|member|textureSize
specifier|mutable
name|QSize
name|textureSize
decl_stmt|;
DECL|member|needsSwizzle
specifier|mutable
name|bool
name|needsSwizzle
decl_stmt|;
DECL|member|blitter
name|QOpenGLTextureBlitter
modifier|*
name|blitter
decl_stmt|;
endif|#
directive|endif
block|}
class|;
end_class
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_struct
DECL|struct|QBackingstoreTextureInfo
struct|struct
name|QBackingstoreTextureInfo
block|{
DECL|member|widget
name|QWidget
modifier|*
name|widget
decl_stmt|;
comment|// may be null
DECL|member|textureId
name|GLuint
name|textureId
decl_stmt|;
DECL|member|rect
name|QRect
name|rect
decl_stmt|;
DECL|member|flags
name|QPlatformTextureList
operator|::
name|Flags
name|flags
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QBackingstoreTextureInfo
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_class
DECL|class|QPlatformTextureListPrivate
class|class
name|QPlatformTextureListPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
public|public:
DECL|function|QPlatformTextureListPrivate
name|QPlatformTextureListPrivate
parameter_list|()
member_init_list|:
name|locked
argument_list|(
literal|false
argument_list|)
block|{     }
DECL|member|textures
name|QList
argument_list|<
name|QBackingstoreTextureInfo
argument_list|>
name|textures
decl_stmt|;
DECL|member|locked
name|bool
name|locked
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QPlatformTextureList
name|QPlatformTextureList
operator|::
name|QPlatformTextureList
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
name|QPlatformTextureListPrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QPlatformTextureList
name|QPlatformTextureList
operator|::
name|~
name|QPlatformTextureList
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|count
name|int
name|QPlatformTextureList
operator|::
name|count
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPlatformTextureList
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|textures
operator|.
name|count
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|textureId
name|GLuint
name|QPlatformTextureList
operator|::
name|textureId
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPlatformTextureList
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|textures
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|.
name|textureId
return|;
block|}
end_function
begin_function
DECL|function|widget
name|QWidget
modifier|*
name|QPlatformTextureList
operator|::
name|widget
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|Q_D
argument_list|(
specifier|const
name|QPlatformTextureList
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|textures
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|.
name|widget
return|;
block|}
end_function
begin_function
DECL|function|flags
name|QPlatformTextureList
operator|::
name|Flags
name|QPlatformTextureList
operator|::
name|flags
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPlatformTextureList
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|textures
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|.
name|flags
return|;
block|}
end_function
begin_function
DECL|function|geometry
name|QRect
name|QPlatformTextureList
operator|::
name|geometry
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPlatformTextureList
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|textures
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|.
name|rect
return|;
block|}
end_function
begin_function
DECL|function|lock
name|void
name|QPlatformTextureList
operator|::
name|lock
parameter_list|(
name|bool
name|on
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPlatformTextureList
argument_list|)
expr_stmt|;
if|if
condition|(
name|on
operator|!=
name|d
operator|->
name|locked
condition|)
block|{
name|d
operator|->
name|locked
operator|=
name|on
expr_stmt|;
emit|emit
name|locked
argument_list|(
name|on
argument_list|)
emit|;
block|}
block|}
end_function
begin_function
DECL|function|isLocked
name|bool
name|QPlatformTextureList
operator|::
name|isLocked
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPlatformTextureList
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|locked
return|;
block|}
end_function
begin_function
DECL|function|appendTexture
name|void
name|QPlatformTextureList
operator|::
name|appendTexture
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|GLuint
name|textureId
parameter_list|,
specifier|const
name|QRect
modifier|&
name|geometry
parameter_list|,
name|Flags
name|flags
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPlatformTextureList
argument_list|)
expr_stmt|;
name|QBackingstoreTextureInfo
name|bi
decl_stmt|;
name|bi
operator|.
name|widget
operator|=
name|widget
expr_stmt|;
name|bi
operator|.
name|textureId
operator|=
name|textureId
expr_stmt|;
name|bi
operator|.
name|rect
operator|=
name|geometry
expr_stmt|;
name|bi
operator|.
name|flags
operator|=
name|flags
expr_stmt|;
name|d
operator|->
name|textures
operator|.
name|append
argument_list|(
name|bi
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clear
name|void
name|QPlatformTextureList
operator|::
name|clear
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QPlatformTextureList
argument_list|)
expr_stmt|;
name|d
operator|->
name|textures
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_OPENGL
end_comment
begin_comment
comment|/*!     \class QPlatformBackingStore     \since 5.0     \internal     \preliminary     \ingroup qpa      \brief The QPlatformBackingStore class provides the drawing area for top-level     windows. */
end_comment
begin_comment
comment|/*!     \fn void QPlatformBackingStore::flush(QWindow *window, const QRegion&region,                                   const QPoint&offset)      Flushes the given \a region from the specified \a window onto the     screen.      Note that the \a offset parameter is currently unused. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_function
DECL|function|deviceRect
specifier|static
name|QRect
name|deviceRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|QRect
name|deviceRect
argument_list|(
name|rect
operator|.
name|topLeft
argument_list|()
operator|*
name|window
operator|->
name|devicePixelRatio
argument_list|()
argument_list|,
name|rect
operator|.
name|size
argument_list|()
operator|*
name|window
operator|->
name|devicePixelRatio
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|deviceRect
return|;
block|}
end_function
begin_function
DECL|function|deviceRegion
specifier|static
name|QRegion
name|deviceRegion
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|window
operator|->
name|devicePixelRatio
argument_list|()
operator|>
literal|1
operator|)
condition|)
return|return
name|region
return|;
name|QVector
argument_list|<
name|QRect
argument_list|>
name|rects
decl_stmt|;
foreach|foreach
control|(
name|QRect
name|rect
decl|,
name|region
operator|.
name|rects
argument_list|()
control|)
name|rects
operator|.
name|append
argument_list|(
name|deviceRect
argument_list|(
name|rect
argument_list|,
name|window
argument_list|)
argument_list|)
expr_stmt|;
name|QRegion
name|deviceRegion
decl_stmt|;
name|deviceRegion
operator|.
name|setRects
argument_list|(
name|rects
operator|.
name|constData
argument_list|()
argument_list|,
name|rects
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|deviceRegion
return|;
block|}
end_function
begin_comment
comment|/*!     Flushes the given \a region from the specified \a window onto the     screen, and composes it with the specified \a textures.      The default implementation retrieves the contents using toTexture()     and composes using OpenGL. May be reimplemented in subclasses if there     is a more efficient native way to do it.      Note that the \a offset parameter is currently unused.  */
end_comment
begin_function
DECL|function|composeAndFlush
name|void
name|QPlatformBackingStore
operator|::
name|composeAndFlush
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|,
name|QPlatformTextureList
modifier|*
name|textures
parameter_list|,
name|QOpenGLContext
modifier|*
name|context
parameter_list|,
name|bool
name|translucentBackground
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|offset
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|context
operator|->
name|makeCurrent
argument_list|(
name|window
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"composeAndFlush: makeCurrent() failed"
argument_list|)
expr_stmt|;
return|return;
block|}
name|QOpenGLFunctions
modifier|*
name|funcs
init|=
name|context
operator|->
name|functions
argument_list|()
decl_stmt|;
name|funcs
operator|->
name|glViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|window
operator|->
name|width
argument_list|()
operator|*
name|window
operator|->
name|devicePixelRatio
argument_list|()
argument_list|,
name|window
operator|->
name|height
argument_list|()
operator|*
name|window
operator|->
name|devicePixelRatio
argument_list|()
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glClearColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|translucentBackground
condition|?
literal|0
else|:
literal|1
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d_ptr
operator|->
name|blitter
condition|)
block|{
name|d_ptr
operator|->
name|blitter
operator|=
operator|new
name|QOpenGLTextureBlitter
expr_stmt|;
name|d_ptr
operator|->
name|blitter
operator|->
name|create
argument_list|()
expr_stmt|;
block|}
name|d_ptr
operator|->
name|blitter
operator|->
name|bind
argument_list|()
expr_stmt|;
name|QRect
name|windowRect
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|window
operator|->
name|size
argument_list|()
operator|*
name|window
operator|->
name|devicePixelRatio
argument_list|()
argument_list|)
decl_stmt|;
comment|// Textures for renderToTexture widgets.
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|textures
operator|->
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|!
name|textures
operator|->
name|flags
argument_list|(
name|i
argument_list|)
operator|.
name|testFlag
argument_list|(
name|QPlatformTextureList
operator|::
name|StacksOnTop
argument_list|)
condition|)
block|{
name|QRect
name|targetRect
init|=
name|deviceRect
argument_list|(
name|textures
operator|->
name|geometry
argument_list|(
name|i
argument_list|)
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|QMatrix4x4
name|target
init|=
name|QOpenGLTextureBlitter
operator|::
name|targetTransform
argument_list|(
name|targetRect
argument_list|,
name|windowRect
argument_list|)
decl_stmt|;
name|d_ptr
operator|->
name|blitter
operator|->
name|blit
argument_list|(
name|textures
operator|->
name|textureId
argument_list|(
name|i
argument_list|)
argument_list|,
name|target
argument_list|,
name|QOpenGLTextureBlitter
operator|::
name|OriginBottomLeft
argument_list|)
expr_stmt|;
block|}
block|}
name|funcs
operator|->
name|glEnable
argument_list|(
name|GL_BLEND
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glBlendFunc
argument_list|(
name|GL_SRC_ALPHA
argument_list|,
name|GL_ONE_MINUS_SRC_ALPHA
argument_list|)
expr_stmt|;
comment|// Do not write out alpha. We need blending, but only for RGB. The toplevel may have
comment|// alpha enabled in which case blending (writing out< 1.0 alpha values) would lead to
comment|// semi-transparency even when it is not wanted.
name|funcs
operator|->
name|glColorMask
argument_list|(
name|GL_TRUE
argument_list|,
name|GL_TRUE
argument_list|,
name|GL_TRUE
argument_list|,
name|GL_FALSE
argument_list|)
expr_stmt|;
name|GLuint
name|textureId
init|=
literal|0
decl_stmt|;
name|QOpenGLTextureBlitter
operator|::
name|Origin
name|origin
init|=
name|QOpenGLTextureBlitter
operator|::
name|OriginTopLeft
decl_stmt|;
if|if
condition|(
name|QPlatformGraphicsBuffer
modifier|*
name|graphicsBuffer
init|=
name|this
operator|->
name|graphicsBuffer
argument_list|()
condition|)
block|{
if|if
condition|(
name|graphicsBuffer
operator|->
name|size
argument_list|()
operator|!=
name|d_ptr
operator|->
name|textureSize
condition|)
block|{
if|if
condition|(
name|d_ptr
operator|->
name|textureId
condition|)
name|funcs
operator|->
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|d_ptr
operator|->
name|textureId
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glGenTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|d_ptr
operator|->
name|textureId
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|d_ptr
operator|->
name|textureId
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_OPENGL_ES_2
if|if
condition|(
operator|!
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|isOpenGLES
argument_list|()
condition|)
block|{
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_BASE_LEVEL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAX_LEVEL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|funcs
operator|->
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_S
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_T
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
if|if
condition|(
name|QPlatformGraphicsBufferHelper
operator|::
name|lockAndBindToTexture
argument_list|(
name|graphicsBuffer
argument_list|,
operator|&
name|d_ptr
operator|->
name|needsSwizzle
argument_list|)
condition|)
block|{
name|d_ptr
operator|->
name|textureSize
operator|=
name|graphicsBuffer
operator|->
name|size
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|d_ptr
operator|->
name|textureSize
operator|=
name|QSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|graphicsBuffer
operator|->
name|unlock
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|region
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|funcs
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|d_ptr
operator|->
name|textureId
argument_list|)
expr_stmt|;
name|QPlatformGraphicsBufferHelper
operator|::
name|lockAndBindToTexture
argument_list|(
name|graphicsBuffer
argument_list|,
operator|&
name|d_ptr
operator|->
name|needsSwizzle
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|graphicsBuffer
operator|->
name|origin
argument_list|()
operator|==
name|QPlatformGraphicsBuffer
operator|::
name|OriginBottomLeft
condition|)
name|origin
operator|=
name|QOpenGLTextureBlitter
operator|::
name|OriginBottomLeft
expr_stmt|;
name|textureId
operator|=
name|d_ptr
operator|->
name|textureId
expr_stmt|;
block|}
else|else
block|{
comment|// Backingstore texture with the normal widgets.
name|textureId
operator|=
name|toTexture
argument_list|(
name|deviceRegion
argument_list|(
name|region
argument_list|,
name|window
argument_list|)
argument_list|,
operator|&
name|d_ptr
operator|->
name|textureSize
argument_list|,
operator|&
name|d_ptr
operator|->
name|needsSwizzle
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|textureId
condition|)
block|{
name|QMatrix4x4
name|target
init|=
name|QOpenGLTextureBlitter
operator|::
name|targetTransform
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|d_ptr
operator|->
name|textureSize
argument_list|)
argument_list|,
name|windowRect
argument_list|)
decl_stmt|;
if|if
condition|(
name|d_ptr
operator|->
name|needsSwizzle
condition|)
name|d_ptr
operator|->
name|blitter
operator|->
name|setSwizzleRB
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|d_ptr
operator|->
name|blitter
operator|->
name|blit
argument_list|(
name|textureId
argument_list|,
name|target
argument_list|,
name|origin
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_ptr
operator|->
name|needsSwizzle
condition|)
name|d_ptr
operator|->
name|blitter
operator|->
name|setSwizzleRB
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
comment|// Textures for renderToTexture widgets that have WA_AlwaysStackOnTop set.
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|textures
operator|->
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|textures
operator|->
name|flags
argument_list|(
name|i
argument_list|)
operator|.
name|testFlag
argument_list|(
name|QPlatformTextureList
operator|::
name|StacksOnTop
argument_list|)
condition|)
block|{
name|QRect
name|targetRect
init|=
name|deviceRect
argument_list|(
name|textures
operator|->
name|geometry
argument_list|(
name|i
argument_list|)
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|QMatrix4x4
name|target
init|=
name|QOpenGLTextureBlitter
operator|::
name|targetTransform
argument_list|(
name|targetRect
argument_list|,
name|windowRect
argument_list|)
decl_stmt|;
name|d_ptr
operator|->
name|blitter
operator|->
name|blit
argument_list|(
name|textures
operator|->
name|textureId
argument_list|(
name|i
argument_list|)
argument_list|,
name|target
argument_list|,
name|QOpenGLTextureBlitter
operator|::
name|OriginBottomLeft
argument_list|)
expr_stmt|;
block|}
block|}
name|funcs
operator|->
name|glColorMask
argument_list|(
name|GL_TRUE
argument_list|,
name|GL_TRUE
argument_list|,
name|GL_TRUE
argument_list|,
name|GL_TRUE
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glDisable
argument_list|(
name|GL_BLEND
argument_list|)
expr_stmt|;
name|d_ptr
operator|->
name|blitter
operator|->
name|release
argument_list|()
expr_stmt|;
name|context
operator|->
name|swapBuffers
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Implemented in subclasses to return the content of the backingstore as a QImage.    If QPlatformIntegration::RasterGLSurface is supported, either this function or   toTexture() must be implemented.    \sa toTexture()  */
end_comment
begin_function
DECL|function|toImage
name|QImage
name|QPlatformBackingStore
operator|::
name|toImage
parameter_list|()
specifier|const
block|{
return|return
name|QImage
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   May be reimplemented in subclasses to return the content of the   backingstore as an OpenGL texture. \a dirtyRegion is the part of the   backingstore which may have changed since the last call to this function. The   caller of this function must ensure that there is a current context.   The size of the texture is returned in \a textureSize.    The ownership of the texture is not transferred. The caller must not store   the return value between calls, but instead call this function before each use.    The default implementation returns a cached texture if \a dirtyRegion is   empty and the window has not been resized, otherwise it retrieves the   content using toImage() and performs a texture upload.    If the red and blue components have to swapped, \a needsSwizzle will be set to \c true.   This allows creating textures from images in formats like QImage::Format_RGB32 without   any further image conversion. Instead, the swizzling will be done in the shaders when   performing composition. Other formats, that do not need such swizzling due to being   already byte ordered RGBA, for example QImage::Format_RGBA8888, must result in having \a   needsSwizzle set to false.  */
end_comment
begin_function
DECL|function|toTexture
name|GLuint
name|QPlatformBackingStore
operator|::
name|toTexture
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|dirtyRegion
parameter_list|,
name|QSize
modifier|*
name|textureSize
parameter_list|,
name|bool
modifier|*
name|needsSwizzle
parameter_list|)
specifier|const
block|{
name|QImage
name|image
init|=
name|toImage
argument_list|()
decl_stmt|;
name|QSize
name|imageSize
init|=
name|image
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|imageSize
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|0
return|;
name|bool
name|resized
init|=
name|d_ptr
operator|->
name|textureSize
operator|!=
name|imageSize
decl_stmt|;
if|if
condition|(
name|dirtyRegion
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|resized
condition|)
return|return
name|d_ptr
operator|->
name|textureId
return|;
comment|// Fast path for RGB32 and RGBA8888, convert everything else to RGBA8888.
if|if
condition|(
name|image
operator|.
name|format
argument_list|()
operator|==
name|QImage
operator|::
name|Format_RGB32
condition|)
block|{
if|if
condition|(
name|needsSwizzle
condition|)
operator|*
name|needsSwizzle
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|needsSwizzle
condition|)
operator|*
name|needsSwizzle
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|image
operator|.
name|format
argument_list|()
operator|!=
name|QImage
operator|::
name|Format_RGBA8888
condition|)
name|image
operator|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGBA8888
argument_list|)
expr_stmt|;
block|}
name|QOpenGLFunctions
modifier|*
name|funcs
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|functions
argument_list|()
decl_stmt|;
if|if
condition|(
name|resized
condition|)
block|{
if|if
condition|(
name|d_ptr
operator|->
name|textureId
condition|)
name|funcs
operator|->
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|d_ptr
operator|->
name|textureId
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glGenTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|d_ptr
operator|->
name|textureId
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|d_ptr
operator|->
name|textureId
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_OPENGL_ES_2
if|if
condition|(
operator|!
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|isOpenGLES
argument_list|()
condition|)
block|{
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_BASE_LEVEL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAX_LEVEL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|funcs
operator|->
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_S
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_T
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|imageSize
operator|.
name|width
argument_list|()
argument_list|,
name|imageSize
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
name|uchar
operator|*
argument_list|>
argument_list|(
name|image
operator|.
name|constBits
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|textureSize
condition|)
operator|*
name|textureSize
operator|=
name|imageSize
expr_stmt|;
block|}
else|else
block|{
name|funcs
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|d_ptr
operator|->
name|textureId
argument_list|)
expr_stmt|;
name|QRect
name|imageRect
init|=
name|image
operator|.
name|rect
argument_list|()
decl_stmt|;
name|QRect
name|rect
init|=
name|dirtyRegion
operator|.
name|boundingRect
argument_list|()
operator|&
name|imageRect
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_OPENGL_ES_2
if|if
condition|(
operator|!
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|isOpenGLES
argument_list|()
condition|)
block|{
name|funcs
operator|->
name|glPixelStorei
argument_list|(
name|GL_UNPACK_ROW_LENGTH
argument_list|,
name|image
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|rect
operator|.
name|x
argument_list|()
argument_list|,
name|rect
operator|.
name|y
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|image
operator|.
name|constScanLine
argument_list|(
name|rect
operator|.
name|y
argument_list|()
argument_list|)
operator|+
name|rect
operator|.
name|x
argument_list|()
operator|*
literal|4
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glPixelStorei
argument_list|(
name|GL_UNPACK_ROW_LENGTH
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
comment|// if the rect is wide enough it's cheaper to just
comment|// extend it instead of doing an image copy
if|if
condition|(
name|rect
operator|.
name|width
argument_list|()
operator|>=
name|imageRect
operator|.
name|width
argument_list|()
operator|/
literal|2
condition|)
block|{
name|rect
operator|.
name|setX
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|rect
operator|.
name|setWidth
argument_list|(
name|imageRect
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// if the sub-rect is full-width we can pass the image data directly to
comment|// OpenGL instead of copying, since there's no gap between scanlines
if|if
condition|(
name|rect
operator|.
name|width
argument_list|()
operator|==
name|imageRect
operator|.
name|width
argument_list|()
condition|)
block|{
name|funcs
operator|->
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|rect
operator|.
name|y
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|image
operator|.
name|constScanLine
argument_list|(
name|rect
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|funcs
operator|->
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|rect
operator|.
name|x
argument_list|()
argument_list|,
name|rect
operator|.
name|y
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|image
operator|.
name|copy
argument_list|(
name|rect
argument_list|)
operator|.
name|constBits
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
return|return
name|d_ptr
operator|->
name|textureId
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_OPENGL
end_comment
begin_comment
comment|/*!     \fn QPaintDevice* QPlatformBackingStore::paintDevice()      Implement this function to return the appropriate paint device. */
end_comment
begin_comment
comment|/*!     Constructs an empty surface for the given top-level \a window. */
end_comment
begin_constructor
DECL|function|QPlatformBackingStore
name|QPlatformBackingStore
operator|::
name|QPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QPlatformBackingStorePrivate
argument_list|(
name|window
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys this surface. */
end_comment
begin_destructor
DECL|function|~QPlatformBackingStore
name|QPlatformBackingStore
operator|::
name|~
name|QPlatformBackingStore
parameter_list|()
block|{
operator|delete
name|d_ptr
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Returns a pointer to the top-level window associated with this     surface. */
end_comment
begin_function
DECL|function|window
name|QWindow
modifier|*
name|QPlatformBackingStore
operator|::
name|window
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|window
return|;
block|}
end_function
begin_comment
comment|/*!     This function is called before painting onto the surface begins,     with the \a region in which the painting will occur.      \sa endPaint(), paintDevice() */
end_comment
begin_function
DECL|function|beginPaint
name|void
name|QPlatformBackingStore
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
parameter_list|)
block|{ }
end_function
begin_comment
comment|/*!     This function is called after painting onto the surface has ended.      \sa beginPaint(), paintDevice() */
end_comment
begin_function
DECL|function|endPaint
name|void
name|QPlatformBackingStore
operator|::
name|endPaint
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*!     Accessor for a backingstores graphics buffer abstraction */
end_comment
begin_function
DECL|function|graphicsBuffer
name|QPlatformGraphicsBuffer
modifier|*
name|QPlatformBackingStore
operator|::
name|graphicsBuffer
parameter_list|()
specifier|const
block|{
return|return
name|Q_NULLPTR
return|;
block|}
end_function
begin_comment
comment|/*!     Scrolls the given \a area \a dx pixels to the right and \a dy     downward; both \a dx and \a dy may be negative.      Returns \c true if the area was scrolled successfully; false otherwise. */
end_comment
begin_function
DECL|function|scroll
name|bool
name|QPlatformBackingStore
operator|::
name|scroll
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|area
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|area
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|dx
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|dy
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
