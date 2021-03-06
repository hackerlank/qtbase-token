begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLFramebufferObject>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QMatrix4x4>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformbackingstore.h>
end_include
begin_include
include|#
directive|include
file|"qopenglcompositor_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QOpenGLCompositor     \brief A generic OpenGL-based compositor     \since 5.4     \internal     \ingroup qpa      This class provides a lightweight compositor that maintains the     basic stacking order of windows and composites them by drawing     textured quads via OpenGL.      It it meant to be used by platform plugins that run without a     windowing system.      It is up to the platform plugin to manage the lifetime of the     compositor (instance(), destroy()), set the correct destination     context and window as early as possible (setTarget()),     register the composited windows as they are shown, activated,     raised and lowered (addWindow(), moveToTop(), etc.), and to     schedule repaints (update()).      \note To get support for QWidget-based windows, just use     QOpenGLCompositorBackingStore. It will automatically create     textures from the raster-rendered content and trigger the     necessary repaints.  */
DECL|variable|compositor
specifier|static
name|QOpenGLCompositor
modifier|*
name|compositor
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QOpenGLCompositor
name|QOpenGLCompositor
operator|::
name|QOpenGLCompositor
parameter_list|()
member_init_list|:
name|m_context
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_targetWindow
argument_list|(
literal|0
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|compositor
argument_list|)
expr_stmt|;
name|m_updateTimer
operator|.
name|setSingleShot
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|m_updateTimer
operator|.
name|setInterval
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|m_updateTimer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|handleRenderAllRequest
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QOpenGLCompositor
name|QOpenGLCompositor
operator|::
name|~
name|QOpenGLCompositor
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|compositor
operator|==
name|this
argument_list|)
expr_stmt|;
name|m_blitter
operator|.
name|destroy
argument_list|()
expr_stmt|;
name|compositor
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setTarget
name|void
name|QOpenGLCompositor
operator|::
name|setTarget
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|,
name|QWindow
modifier|*
name|targetWindow
parameter_list|)
block|{
name|m_context
operator|=
name|context
expr_stmt|;
name|m_targetWindow
operator|=
name|targetWindow
expr_stmt|;
block|}
end_function
begin_function
DECL|function|update
name|void
name|QOpenGLCompositor
operator|::
name|update
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_updateTimer
operator|.
name|isActive
argument_list|()
condition|)
name|m_updateTimer
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|grab
name|QImage
name|QOpenGLCompositor
operator|::
name|grab
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|m_context
operator|&&
name|m_targetWindow
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|makeCurrent
argument_list|(
name|m_targetWindow
argument_list|)
expr_stmt|;
name|QScopedPointer
argument_list|<
name|QOpenGLFramebufferObject
argument_list|>
name|fbo
argument_list|(
operator|new
name|QOpenGLFramebufferObject
argument_list|(
name|m_targetWindow
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|renderAll
argument_list|(
name|fbo
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|fbo
operator|->
name|toImage
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|handleRenderAllRequest
name|void
name|QOpenGLCompositor
operator|::
name|handleRenderAllRequest
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|m_context
operator|&&
name|m_targetWindow
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|makeCurrent
argument_list|(
name|m_targetWindow
argument_list|)
expr_stmt|;
name|renderAll
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|renderAll
name|void
name|QOpenGLCompositor
operator|::
name|renderAll
parameter_list|(
name|QOpenGLFramebufferObject
modifier|*
name|fbo
parameter_list|)
block|{
if|if
condition|(
name|fbo
condition|)
name|fbo
operator|->
name|bind
argument_list|()
expr_stmt|;
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
operator||
name|GL_DEPTH_BUFFER_BIT
operator||
name|GL_STENCIL_BUFFER_BIT
argument_list|)
expr_stmt|;
specifier|const
name|QRect
name|targetWindowRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|m_targetWindow
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|glViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|targetWindowRect
operator|.
name|width
argument_list|()
argument_list|,
name|targetWindowRect
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_blitter
operator|.
name|isCreated
argument_list|()
condition|)
name|m_blitter
operator|.
name|create
argument_list|()
expr_stmt|;
name|m_blitter
operator|.
name|bind
argument_list|()
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
name|m_windows
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|m_windows
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|beginCompositing
argument_list|()
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
name|m_windows
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|render
argument_list|(
name|m_windows
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|m_blitter
operator|.
name|release
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|fbo
condition|)
name|m_context
operator|->
name|swapBuffers
argument_list|(
name|m_targetWindow
argument_list|)
expr_stmt|;
else|else
name|fbo
operator|->
name|release
argument_list|()
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
name|m_windows
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|m_windows
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|endCompositing
argument_list|()
expr_stmt|;
block|}
end_function
begin_struct
DECL|struct|BlendStateBinder
struct|struct
name|BlendStateBinder
block|{
DECL|function|BlendStateBinder
name|BlendStateBinder
parameter_list|()
member_init_list|:
name|m_blend
argument_list|(
literal|false
argument_list|)
block|{
name|glDisable
argument_list|(
name|GL_BLEND
argument_list|)
expr_stmt|;
block|}
DECL|function|set
name|void
name|set
parameter_list|(
name|bool
name|blend
parameter_list|)
block|{
if|if
condition|(
name|blend
operator|!=
name|m_blend
condition|)
block|{
if|if
condition|(
name|blend
condition|)
block|{
name|glEnable
argument_list|(
name|GL_BLEND
argument_list|)
expr_stmt|;
name|glBlendFunc
argument_list|(
name|GL_SRC_ALPHA
argument_list|,
name|GL_ONE_MINUS_SRC_ALPHA
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|glDisable
argument_list|(
name|GL_BLEND
argument_list|)
expr_stmt|;
block|}
name|m_blend
operator|=
name|blend
expr_stmt|;
block|}
block|}
DECL|function|~BlendStateBinder
name|~
name|BlendStateBinder
parameter_list|()
block|{
if|if
condition|(
name|m_blend
condition|)
name|glDisable
argument_list|(
name|GL_BLEND
argument_list|)
expr_stmt|;
block|}
DECL|member|m_blend
name|bool
name|m_blend
decl_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|toBottomLeftRect
specifier|static
specifier|inline
name|QRect
name|toBottomLeftRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|topLeftRect
parameter_list|,
name|int
name|windowHeight
parameter_list|)
block|{
return|return
name|QRect
argument_list|(
name|topLeftRect
operator|.
name|x
argument_list|()
argument_list|,
name|windowHeight
operator|-
name|topLeftRect
operator|.
name|bottomRight
argument_list|()
operator|.
name|y
argument_list|()
operator|-
literal|1
argument_list|,
name|topLeftRect
operator|.
name|width
argument_list|()
argument_list|,
name|topLeftRect
operator|.
name|height
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|clippedBlit
specifier|static
name|void
name|clippedBlit
parameter_list|(
specifier|const
name|QPlatformTextureList
modifier|*
name|textures
parameter_list|,
name|int
name|idx
parameter_list|,
specifier|const
name|QRect
modifier|&
name|targetWindowRect
parameter_list|,
name|QOpenGLTextureBlitter
modifier|*
name|blitter
parameter_list|)
block|{
specifier|const
name|QRect
name|clipRect
init|=
name|textures
operator|->
name|clipRect
argument_list|(
name|idx
argument_list|)
decl_stmt|;
if|if
condition|(
name|clipRect
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
specifier|const
name|QRect
name|rectInWindow
init|=
name|textures
operator|->
name|geometry
argument_list|(
name|idx
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|clippedRectInWindow
init|=
name|rectInWindow
operator|&
name|clipRect
operator|.
name|translated
argument_list|(
name|rectInWindow
operator|.
name|topLeft
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|srcRect
init|=
name|toBottomLeftRect
argument_list|(
name|clipRect
argument_list|,
name|rectInWindow
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QMatrix4x4
name|target
init|=
name|QOpenGLTextureBlitter
operator|::
name|targetTransform
argument_list|(
name|clippedRectInWindow
argument_list|,
name|targetWindowRect
argument_list|)
decl_stmt|;
specifier|const
name|QMatrix3x3
name|source
init|=
name|QOpenGLTextureBlitter
operator|::
name|sourceTransform
argument_list|(
name|srcRect
argument_list|,
name|rectInWindow
operator|.
name|size
argument_list|()
argument_list|,
name|QOpenGLTextureBlitter
operator|::
name|OriginBottomLeft
argument_list|)
decl_stmt|;
name|blitter
operator|->
name|blit
argument_list|(
name|textures
operator|->
name|textureId
argument_list|(
name|idx
argument_list|)
argument_list|,
name|target
argument_list|,
name|source
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|render
name|void
name|QOpenGLCompositor
operator|::
name|render
parameter_list|(
name|QOpenGLCompositorWindow
modifier|*
name|window
parameter_list|)
block|{
specifier|const
name|QPlatformTextureList
modifier|*
name|textures
init|=
name|window
operator|->
name|textures
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|textures
condition|)
return|return;
specifier|const
name|QRect
name|targetWindowRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|m_targetWindow
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|float
name|currentOpacity
init|=
literal|1.0f
decl_stmt|;
name|BlendStateBinder
name|blend
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
name|textures
operator|->
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|uint
name|textureId
init|=
name|textures
operator|->
name|textureId
argument_list|(
name|i
argument_list|)
decl_stmt|;
specifier|const
name|float
name|opacity
init|=
name|window
operator|->
name|sourceWindow
argument_list|()
operator|->
name|opacity
argument_list|()
decl_stmt|;
if|if
condition|(
name|opacity
operator|!=
name|currentOpacity
condition|)
block|{
name|currentOpacity
operator|=
name|opacity
expr_stmt|;
name|m_blitter
operator|.
name|setOpacity
argument_list|(
name|currentOpacity
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|textures
operator|->
name|count
argument_list|()
operator|>
literal|1
operator|&&
name|i
operator|==
name|textures
operator|->
name|count
argument_list|()
operator|-
literal|1
condition|)
block|{
comment|// Backingstore for a widget with QOpenGLWidget subwidgets
name|blend
operator|.
name|set
argument_list|(
literal|true
argument_list|)
expr_stmt|;
specifier|const
name|QMatrix4x4
name|target
init|=
name|QOpenGLTextureBlitter
operator|::
name|targetTransform
argument_list|(
name|textures
operator|->
name|geometry
argument_list|(
name|i
argument_list|)
argument_list|,
name|targetWindowRect
argument_list|)
decl_stmt|;
name|m_blitter
operator|.
name|blit
argument_list|(
name|textureId
argument_list|,
name|target
argument_list|,
name|QOpenGLTextureBlitter
operator|::
name|OriginTopLeft
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|textures
operator|->
name|count
argument_list|()
operator|==
literal|1
condition|)
block|{
comment|// A regular QWidget window
specifier|const
name|bool
name|translucent
init|=
name|window
operator|->
name|sourceWindow
argument_list|()
operator|->
name|requestedFormat
argument_list|()
operator|.
name|alphaBufferSize
argument_list|()
operator|>
literal|0
decl_stmt|;
name|blend
operator|.
name|set
argument_list|(
name|translucent
argument_list|)
expr_stmt|;
specifier|const
name|QMatrix4x4
name|target
init|=
name|QOpenGLTextureBlitter
operator|::
name|targetTransform
argument_list|(
name|textures
operator|->
name|geometry
argument_list|(
name|i
argument_list|)
argument_list|,
name|targetWindowRect
argument_list|)
decl_stmt|;
name|m_blitter
operator|.
name|blit
argument_list|(
name|textureId
argument_list|,
name|target
argument_list|,
name|QOpenGLTextureBlitter
operator|::
name|OriginTopLeft
argument_list|)
expr_stmt|;
block|}
elseif|else
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
comment|// Texture from an FBO belonging to a QOpenGLWidget
name|blend
operator|.
name|set
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|clippedBlit
argument_list|(
name|textures
argument_list|,
name|i
argument_list|,
name|targetWindowRect
argument_list|,
operator|&
name|m_blitter
argument_list|)
expr_stmt|;
block|}
block|}
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
name|blend
operator|.
name|set
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|clippedBlit
argument_list|(
name|textures
argument_list|,
name|i
argument_list|,
name|targetWindowRect
argument_list|,
operator|&
name|m_blitter
argument_list|)
expr_stmt|;
block|}
block|}
name|m_blitter
operator|.
name|setOpacity
argument_list|(
literal|1.0f
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|instance
name|QOpenGLCompositor
modifier|*
name|QOpenGLCompositor
operator|::
name|instance
parameter_list|()
block|{
if|if
condition|(
operator|!
name|compositor
condition|)
name|compositor
operator|=
operator|new
name|QOpenGLCompositor
expr_stmt|;
return|return
name|compositor
return|;
block|}
end_function
begin_function
DECL|function|destroy
name|void
name|QOpenGLCompositor
operator|::
name|destroy
parameter_list|()
block|{
operator|delete
name|compositor
expr_stmt|;
name|compositor
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addWindow
name|void
name|QOpenGLCompositor
operator|::
name|addWindow
parameter_list|(
name|QOpenGLCompositorWindow
modifier|*
name|window
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_windows
operator|.
name|contains
argument_list|(
name|window
argument_list|)
condition|)
block|{
name|m_windows
operator|.
name|append
argument_list|(
name|window
argument_list|)
expr_stmt|;
emit|emit
name|topWindowChanged
argument_list|(
name|window
argument_list|)
emit|;
block|}
block|}
end_function
begin_function
DECL|function|removeWindow
name|void
name|QOpenGLCompositor
operator|::
name|removeWindow
parameter_list|(
name|QOpenGLCompositorWindow
modifier|*
name|window
parameter_list|)
block|{
name|m_windows
operator|.
name|removeOne
argument_list|(
name|window
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_windows
operator|.
name|isEmpty
argument_list|()
condition|)
emit|emit
name|topWindowChanged
argument_list|(
name|m_windows
operator|.
name|last
argument_list|()
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|moveToTop
name|void
name|QOpenGLCompositor
operator|::
name|moveToTop
parameter_list|(
name|QOpenGLCompositorWindow
modifier|*
name|window
parameter_list|)
block|{
name|m_windows
operator|.
name|removeOne
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|m_windows
operator|.
name|append
argument_list|(
name|window
argument_list|)
expr_stmt|;
emit|emit
name|topWindowChanged
argument_list|(
name|window
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|changeWindowIndex
name|void
name|QOpenGLCompositor
operator|::
name|changeWindowIndex
parameter_list|(
name|QOpenGLCompositorWindow
modifier|*
name|window
parameter_list|,
name|int
name|newIdx
parameter_list|)
block|{
name|int
name|idx
init|=
name|m_windows
operator|.
name|indexOf
argument_list|(
name|window
argument_list|)
decl_stmt|;
if|if
condition|(
name|idx
operator|!=
operator|-
literal|1
operator|&&
name|idx
operator|!=
name|newIdx
condition|)
block|{
name|m_windows
operator|.
name|move
argument_list|(
name|idx
argument_list|,
name|newIdx
argument_list|)
expr_stmt|;
if|if
condition|(
name|newIdx
operator|==
name|m_windows
operator|.
name|size
argument_list|()
operator|-
literal|1
condition|)
emit|emit
name|topWindowChanged
argument_list|(
name|m_windows
operator|.
name|last
argument_list|()
argument_list|)
emit|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
