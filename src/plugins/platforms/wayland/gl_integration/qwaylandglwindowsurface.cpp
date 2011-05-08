begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandglwindowsurface.h"
end_include
begin_include
include|#
directive|include
file|"qwaylanddisplay.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandscreen.h"
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/QGLFramebufferObject>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/QGLContext>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/private/qglengineshadermanager_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|drawTexture
specifier|static
name|void
name|drawTexture
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|GLuint
name|tex_id
parameter_list|,
specifier|const
name|QSize
modifier|&
name|texSize
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|br
parameter_list|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
name|QGLContext
modifier|*
name|ctx
init|=
cast|const_cast
argument_list|<
name|QGLContext
operator|*
argument_list|>
argument_list|(
name|QGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
decl_stmt|;
endif|#
directive|endif
specifier|const
name|GLenum
name|target
init|=
name|GL_TEXTURE_2D
decl_stmt|;
name|QRectF
name|src
init|=
name|br
operator|.
name|isEmpty
argument_list|()
condition|?
name|QRectF
argument_list|(
name|QPointF
argument_list|()
argument_list|,
name|texSize
argument_list|)
else|:
name|QRectF
argument_list|(
name|QPointF
argument_list|(
name|br
operator|.
name|x
argument_list|()
argument_list|,
name|texSize
operator|.
name|height
argument_list|()
operator|-
name|br
operator|.
name|bottom
argument_list|()
argument_list|)
argument_list|,
name|br
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|target
operator|==
name|GL_TEXTURE_2D
condition|)
block|{
name|qreal
name|width
init|=
name|texSize
operator|.
name|width
argument_list|()
decl_stmt|;
name|qreal
name|height
init|=
name|texSize
operator|.
name|height
argument_list|()
decl_stmt|;
name|src
operator|.
name|setLeft
argument_list|(
name|src
operator|.
name|left
argument_list|()
operator|/
name|width
argument_list|)
expr_stmt|;
name|src
operator|.
name|setRight
argument_list|(
name|src
operator|.
name|right
argument_list|()
operator|/
name|width
argument_list|)
expr_stmt|;
name|src
operator|.
name|setTop
argument_list|(
name|src
operator|.
name|top
argument_list|()
operator|/
name|height
argument_list|)
expr_stmt|;
name|src
operator|.
name|setBottom
argument_list|(
name|src
operator|.
name|bottom
argument_list|()
operator|/
name|height
argument_list|)
expr_stmt|;
block|}
specifier|const
name|GLfloat
name|tx1
init|=
name|src
operator|.
name|left
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|tx2
init|=
name|src
operator|.
name|right
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|ty1
init|=
name|src
operator|.
name|top
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|ty2
init|=
name|src
operator|.
name|bottom
argument_list|()
decl_stmt|;
name|GLfloat
name|texCoordArray
index|[
literal|4
operator|*
literal|2
index|]
init|=
block|{
name|tx1
block|,
name|ty2
block|,
name|tx2
block|,
name|ty2
block|,
name|tx2
block|,
name|ty1
block|,
name|tx1
block|,
name|ty1
block|}
decl_stmt|;
name|GLfloat
name|vertexArray
index|[
literal|4
operator|*
literal|2
index|]
decl_stmt|;
name|vertexArray
index|[
literal|0
index|]
operator|=
name|rect
operator|.
name|left
argument_list|()
expr_stmt|;
name|vertexArray
index|[
literal|1
index|]
operator|=
name|rect
operator|.
name|top
argument_list|()
expr_stmt|;
name|vertexArray
index|[
literal|2
index|]
operator|=
name|rect
operator|.
name|right
argument_list|()
expr_stmt|;
name|vertexArray
index|[
literal|3
index|]
operator|=
name|rect
operator|.
name|top
argument_list|()
expr_stmt|;
name|vertexArray
index|[
literal|4
index|]
operator|=
name|rect
operator|.
name|right
argument_list|()
expr_stmt|;
name|vertexArray
index|[
literal|5
index|]
operator|=
name|rect
operator|.
name|bottom
argument_list|()
expr_stmt|;
name|vertexArray
index|[
literal|6
index|]
operator|=
name|rect
operator|.
name|left
argument_list|()
expr_stmt|;
name|vertexArray
index|[
literal|7
index|]
operator|=
name|rect
operator|.
name|bottom
argument_list|()
expr_stmt|;
name|glVertexAttribPointer
argument_list|(
name|QT_VERTEX_COORDS_ATTR
argument_list|,
literal|2
argument_list|,
name|GL_FLOAT
argument_list|,
name|GL_FALSE
argument_list|,
literal|0
argument_list|,
name|vertexArray
argument_list|)
expr_stmt|;
name|glVertexAttribPointer
argument_list|(
name|QT_TEXTURE_COORDS_ATTR
argument_list|,
literal|2
argument_list|,
name|GL_FLOAT
argument_list|,
name|GL_FALSE
argument_list|,
literal|0
argument_list|,
name|texCoordArray
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|target
argument_list|,
name|tex_id
argument_list|)
expr_stmt|;
name|glEnableVertexAttribArray
argument_list|(
name|QT_VERTEX_COORDS_ATTR
argument_list|)
expr_stmt|;
name|glEnableVertexAttribArray
argument_list|(
name|QT_TEXTURE_COORDS_ATTR
argument_list|)
expr_stmt|;
name|glDrawArrays
argument_list|(
name|GL_TRIANGLE_FAN
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|glDisableVertexAttribArray
argument_list|(
name|QT_VERTEX_COORDS_ATTR
argument_list|)
expr_stmt|;
name|glDisableVertexAttribArray
argument_list|(
name|QT_TEXTURE_COORDS_ATTR
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|target
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|blitTexture
specifier|static
name|void
name|blitTexture
parameter_list|(
name|QGLContext
modifier|*
name|ctx
parameter_list|,
name|GLuint
name|texture
parameter_list|,
specifier|const
name|QSize
modifier|&
name|viewport
parameter_list|,
specifier|const
name|QSize
modifier|&
name|texSize
parameter_list|,
specifier|const
name|QRect
modifier|&
name|targetRect
parameter_list|,
specifier|const
name|QRect
modifier|&
name|sourceRect
parameter_list|)
block|{
name|glDisable
argument_list|(
name|GL_DEPTH_TEST
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_SCISSOR_TEST
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_BLEND
argument_list|)
expr_stmt|;
name|glViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|viewport
operator|.
name|width
argument_list|()
argument_list|,
name|viewport
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QGLShaderProgram
modifier|*
name|blitProgram
init|=
name|QGLEngineSharedShaders
operator|::
name|shadersForContext
argument_list|(
name|ctx
argument_list|)
operator|->
name|blitProgram
argument_list|()
decl_stmt|;
name|blitProgram
operator|->
name|bind
argument_list|()
expr_stmt|;
name|blitProgram
operator|->
name|setUniformValue
argument_list|(
literal|"imageTexture"
argument_list|,
literal|0
comment|/*QT_IMAGE_TEXTURE_UNIT*/
argument_list|)
expr_stmt|;
comment|// The shader manager's blit program does not multiply the
comment|// vertices by the pmv matrix, so we need to do the effect
comment|// of the orthographic projection here ourselves.
name|QRectF
name|r
decl_stmt|;
name|qreal
name|w
init|=
name|viewport
operator|.
name|width
argument_list|()
decl_stmt|;
name|qreal
name|h
init|=
name|viewport
operator|.
name|height
argument_list|()
decl_stmt|;
name|r
operator|.
name|setLeft
argument_list|(
operator|(
name|targetRect
operator|.
name|left
argument_list|()
operator|/
name|w
operator|)
operator|*
literal|2.0f
operator|-
literal|1.0f
argument_list|)
expr_stmt|;
if|if
condition|(
name|targetRect
operator|.
name|right
argument_list|()
operator|==
operator|(
name|viewport
operator|.
name|width
argument_list|()
operator|-
literal|1
operator|)
condition|)
name|r
operator|.
name|setRight
argument_list|(
literal|1.0f
argument_list|)
expr_stmt|;
else|else
name|r
operator|.
name|setRight
argument_list|(
operator|(
name|targetRect
operator|.
name|right
argument_list|()
operator|/
name|w
operator|)
operator|*
literal|2.0f
operator|-
literal|1.0f
argument_list|)
expr_stmt|;
name|r
operator|.
name|setBottom
argument_list|(
operator|(
name|targetRect
operator|.
name|top
argument_list|()
operator|/
name|h
operator|)
operator|*
literal|2.0f
operator|-
literal|1.0f
argument_list|)
expr_stmt|;
if|if
condition|(
name|targetRect
operator|.
name|bottom
argument_list|()
operator|==
operator|(
name|viewport
operator|.
name|height
argument_list|()
operator|-
literal|1
operator|)
condition|)
name|r
operator|.
name|setTop
argument_list|(
literal|1.0f
argument_list|)
expr_stmt|;
else|else
name|r
operator|.
name|setTop
argument_list|(
operator|(
name|targetRect
operator|.
name|bottom
argument_list|()
operator|/
name|w
operator|)
operator|*
literal|2.0f
operator|-
literal|1.0f
argument_list|)
expr_stmt|;
name|drawTexture
argument_list|(
name|r
argument_list|,
name|texture
argument_list|,
name|texSize
argument_list|,
name|sourceRect
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QWaylandGLWindowSurface
name|QWaylandGLWindowSurface
operator|::
name|QWaylandGLWindowSurface
parameter_list|(
name|QWidget
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QWindowSurface
argument_list|(
name|window
argument_list|)
member_init_list|,
name|mDisplay
argument_list|(
name|QWaylandScreen
operator|::
name|waylandScreenFromWidget
argument_list|(
name|window
argument_list|)
operator|->
name|display
argument_list|()
argument_list|)
member_init_list|,
name|mPaintDevice
argument_list|(
literal|0
argument_list|)
block|{  }
end_constructor
begin_destructor
DECL|function|~QWaylandGLWindowSurface
name|QWaylandGLWindowSurface
operator|::
name|~
name|QWaylandGLWindowSurface
parameter_list|()
block|{
operator|delete
name|mPaintDevice
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QWaylandGLWindowSurface
operator|::
name|paintDevice
parameter_list|()
block|{
return|return
name|mPaintDevice
return|;
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QWaylandGLWindowSurface
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
parameter_list|)
block|{
name|window
argument_list|()
operator|->
name|platformWindow
argument_list|()
operator|->
name|glContext
argument_list|()
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
name|glClearColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0xff
argument_list|)
expr_stmt|;
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QWaylandGLWindowSurface
operator|::
name|flush
parameter_list|(
name|QWidget
modifier|*
name|widget
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
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|offset
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|region
argument_list|)
expr_stmt|;
name|QWaylandWindow
modifier|*
name|ww
init|=
operator|(
name|QWaylandWindow
operator|*
operator|)
name|widget
operator|->
name|platformWindow
argument_list|()
decl_stmt|;
if|if
condition|(
name|mPaintDevice
operator|->
name|isBound
argument_list|()
condition|)
name|mPaintDevice
operator|->
name|release
argument_list|()
expr_stmt|;
name|QRect
name|rect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|size
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|size
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|QGLContext
modifier|*
name|ctx
init|=
name|QGLContext
operator|::
name|fromPlatformGLContext
argument_list|(
name|ww
operator|->
name|glContext
argument_list|()
argument_list|)
decl_stmt|;
name|blitTexture
argument_list|(
name|ctx
argument_list|,
name|mPaintDevice
operator|->
name|texture
argument_list|()
argument_list|,
name|size
argument_list|()
argument_list|,
name|mPaintDevice
operator|->
name|size
argument_list|()
argument_list|,
name|rect
argument_list|,
name|rect
argument_list|)
expr_stmt|;
name|ww
operator|->
name|glContext
argument_list|()
operator|->
name|swapBuffers
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QWaylandGLWindowSurface
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
name|QWindowSurface
operator|::
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|window
argument_list|()
operator|->
name|platformWindow
argument_list|()
operator|->
name|glContext
argument_list|()
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
operator|delete
name|mPaintDevice
expr_stmt|;
name|mPaintDevice
operator|=
operator|new
name|QGLFramebufferObject
argument_list|(
name|size
argument_list|,
name|QGLFramebufferObject
operator|::
name|CombinedDepthStencil
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
