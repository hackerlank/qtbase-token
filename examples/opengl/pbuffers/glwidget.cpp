begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"glwidget.h"
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_include
include|#
directive|include
file|"cube.h"
end_include
begin_include
include|#
directive|include
file|<QGLPixelBuffer>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|GL_MULTISAMPLE
end_ifndef
begin_define
DECL|macro|GL_MULTISAMPLE
define|#
directive|define
name|GL_MULTISAMPLE
value|0x809D
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|colorArray
specifier|static
name|GLfloat
name|colorArray
index|[]
index|[
literal|4
index|]
init|=
block|{
block|{
literal|0.243f
block|,
literal|0.423f
block|,
literal|0.125f
block|,
literal|1.0f
block|}
block|,
block|{
literal|0.176f
block|,
literal|0.31f
block|,
literal|0.09f
block|,
literal|1.0f
block|}
block|,
block|{
literal|0.4f
block|,
literal|0.69f
block|,
literal|0.212f
block|,
literal|1.0f
block|}
block|,
block|{
literal|0.317f
block|,
literal|0.553f
block|,
literal|0.161f
block|,
literal|1.0f
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|GLWidget
name|GLWidget
operator|::
name|GLWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGLWidget
argument_list|(
name|QGLFormat
argument_list|(
name|QGL
operator|::
name|SampleBuffers
argument_list|)
argument_list|,
name|parent
argument_list|)
member_init_list|,
name|geom
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|cube
argument_list|(
literal|0
argument_list|)
block|{
comment|// create the pbuffer
name|QGLFormat
name|pbufferFormat
init|=
name|format
argument_list|()
decl_stmt|;
name|pbufferFormat
operator|.
name|setSampleBuffers
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|pbuffer
operator|=
operator|new
name|QGLPixelBuffer
argument_list|(
name|QSize
argument_list|(
literal|512
argument_list|,
literal|512
argument_list|)
argument_list|,
name|pbufferFormat
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"OpenGL pbuffers"
argument_list|)
argument_list|)
expr_stmt|;
name|initializeGeometry
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~GLWidget
name|GLWidget
operator|::
name|~
name|GLWidget
parameter_list|()
block|{
name|pbuffer
operator|->
name|releaseFromDynamicTexture
argument_list|()
expr_stmt|;
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|dynamicTexture
argument_list|)
expr_stmt|;
operator|delete
name|pbuffer
expr_stmt|;
name|qDeleteAll
argument_list|(
name|cubes
argument_list|)
expr_stmt|;
name|qDeleteAll
argument_list|(
name|tiles
argument_list|)
expr_stmt|;
operator|delete
name|cube
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|initializeGL
name|void
name|GLWidget
operator|::
name|initializeGL
parameter_list|()
block|{
name|initCommon
argument_list|()
expr_stmt|;
name|glShadeModel
argument_list|(
name|GL_SMOOTH
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_LIGHTING
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_LIGHT0
argument_list|)
expr_stmt|;
specifier|static
name|GLfloat
name|lightPosition
index|[
literal|4
index|]
init|=
block|{
literal|0.5
block|,
literal|5.0
block|,
literal|7.0
block|,
literal|1.0
block|}
decl_stmt|;
name|glLightfv
argument_list|(
name|GL_LIGHT0
argument_list|,
name|GL_POSITION
argument_list|,
name|lightPosition
argument_list|)
expr_stmt|;
name|initPbuffer
argument_list|()
expr_stmt|;
name|cube
operator|->
name|startAnimation
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|cube
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|update
argument_list|()
argument_list|)
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
literal|3
condition|;
operator|++
name|i
control|)
block|{
name|cubes
index|[
name|i
index|]
operator|->
name|startAnimation
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|cubes
index|[
name|i
index|]
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|update
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|paintGL
name|void
name|GLWidget
operator|::
name|paintGL
parameter_list|()
block|{
name|pbuffer
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
name|drawPbuffer
argument_list|()
expr_stmt|;
comment|// On direct render platforms, drawing onto the pbuffer context above
comment|// automatically updates the dynamic texture.  For cases where rendering
comment|// directly to a texture is not supported, explicitly copy.
if|if
condition|(
operator|!
name|hasDynamicTextureUpdate
condition|)
name|pbuffer
operator|->
name|updateDynamicTexture
argument_list|(
name|dynamicTexture
argument_list|)
expr_stmt|;
name|makeCurrent
argument_list|()
expr_stmt|;
comment|// Use the pbuffer as a texture to render the scene
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|dynamicTexture
argument_list|)
expr_stmt|;
comment|// set up to render the scene
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
operator||
name|GL_DEPTH_BUFFER_BIT
argument_list|)
expr_stmt|;
name|glLoadIdentity
argument_list|()
expr_stmt|;
name|glTranslatef
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
operator|-
literal|10.0f
argument_list|)
expr_stmt|;
comment|// draw the background
name|glPushMatrix
argument_list|()
expr_stmt|;
name|glScalef
argument_list|(
name|aspect
argument_list|,
literal|1.0f
argument_list|,
literal|1.0f
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
name|tiles
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|tiles
index|[
name|i
index|]
operator|->
name|draw
argument_list|()
expr_stmt|;
name|glPopMatrix
argument_list|()
expr_stmt|;
comment|// draw the bouncing cubes
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|cubes
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|cubes
index|[
name|i
index|]
operator|->
name|draw
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initializeGeometry
name|void
name|GLWidget
operator|::
name|initializeGeometry
parameter_list|()
block|{
name|geom
operator|=
operator|new
name|Geometry
argument_list|()
expr_stmt|;
name|CubeBuilder
name|cBuilder
argument_list|(
name|geom
argument_list|,
literal|0.5
argument_list|)
decl_stmt|;
name|cBuilder
operator|.
name|setColor
argument_list|(
name|QColor
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|,
literal|212
argument_list|)
argument_list|)
expr_stmt|;
comment|// build the 3 bouncing, spinning cubes
for|for
control|(
name|int
name|i
init|=
literal|3
init|;
name|i
operator|>
literal|0
condition|;
operator|--
name|i
control|)
name|cubes
operator|.
name|append
argument_list|(
name|cBuilder
operator|.
name|newCube
argument_list|(
name|QVector3D
argument_list|(
call|(
name|float
call|)
argument_list|(
name|i
operator|-
literal|1
argument_list|)
argument_list|,
operator|-
literal|1.5f
argument_list|,
literal|5
operator|-
name|i
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|// build the spinning cube which goes in the dynamic texture
name|cube
operator|=
name|cBuilder
operator|.
name|newCube
argument_list|()
expr_stmt|;
name|cube
operator|->
name|removeBounce
argument_list|()
expr_stmt|;
comment|// build the background tiles
name|TileBuilder
name|tBuilder
argument_list|(
name|geom
argument_list|)
decl_stmt|;
name|tBuilder
operator|.
name|setColor
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|c
init|=
operator|-
literal|2
init|;
name|c
operator|<=
operator|+
literal|2
condition|;
operator|++
name|c
control|)
for|for
control|(
name|int
name|r
init|=
operator|-
literal|2
init|;
name|r
operator|<=
operator|+
literal|2
condition|;
operator|++
name|r
control|)
name|tiles
operator|.
name|append
argument_list|(
name|tBuilder
operator|.
name|newTile
argument_list|(
name|QVector3D
argument_list|(
name|c
argument_list|,
name|r
argument_list|,
literal|0
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|// graded backdrop for the pbuffer scene
name|TileBuilder
name|bBuilder
argument_list|(
name|geom
argument_list|,
literal|0.0f
argument_list|,
literal|2.0f
argument_list|)
decl_stmt|;
name|bBuilder
operator|.
name|setColor
argument_list|(
name|QColor
argument_list|(
literal|102
argument_list|,
literal|176
argument_list|,
literal|54
argument_list|,
literal|210
argument_list|)
argument_list|)
expr_stmt|;
name|backdrop
operator|=
name|bBuilder
operator|.
name|newTile
argument_list|(
name|QVector3D
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
operator|-
literal|1.5f
argument_list|)
argument_list|)
expr_stmt|;
name|backdrop
operator|->
name|setColors
argument_list|(
name|colorArray
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initCommon
name|void
name|GLWidget
operator|::
name|initCommon
parameter_list|()
block|{
name|qglClearColor
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|darkGray
argument_list|)
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_DEPTH_TEST
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_CULL_FACE
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_MULTISAMPLE
argument_list|)
expr_stmt|;
name|glBlendFunc
argument_list|(
name|GL_SRC_ALPHA
argument_list|,
name|GL_ONE_MINUS_SRC_ALPHA
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_BLEND
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_TEXTURE_2D
argument_list|)
expr_stmt|;
name|geom
operator|->
name|loadArrays
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|perspectiveProjection
name|void
name|GLWidget
operator|::
name|perspectiveProjection
parameter_list|()
block|{
name|glMatrixMode
argument_list|(
name|GL_PROJECTION
argument_list|)
expr_stmt|;
name|glLoadIdentity
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_OPENGL_ES
name|glFrustumf
argument_list|(
operator|-
name|aspect
argument_list|,
operator|+
name|aspect
argument_list|,
operator|-
literal|1.0
argument_list|,
operator|+
literal|1.0
argument_list|,
literal|4.0
argument_list|,
literal|15.0
argument_list|)
expr_stmt|;
else|#
directive|else
name|glFrustum
argument_list|(
operator|-
name|aspect
argument_list|,
operator|+
name|aspect
argument_list|,
operator|-
literal|1.0
argument_list|,
operator|+
literal|1.0
argument_list|,
literal|4.0
argument_list|,
literal|15.0
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|glMatrixMode
argument_list|(
name|GL_MODELVIEW
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|orthographicProjection
name|void
name|GLWidget
operator|::
name|orthographicProjection
parameter_list|()
block|{
name|glMatrixMode
argument_list|(
name|GL_PROJECTION
argument_list|)
expr_stmt|;
name|glLoadIdentity
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_OPENGL_ES
name|glOrthof
argument_list|(
operator|-
literal|1.0
argument_list|,
operator|+
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|,
operator|+
literal|1.0
argument_list|,
operator|-
literal|90.0
argument_list|,
operator|+
literal|90.0
argument_list|)
expr_stmt|;
else|#
directive|else
name|glOrtho
argument_list|(
operator|-
literal|1.0
argument_list|,
operator|+
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|,
operator|+
literal|1.0
argument_list|,
operator|-
literal|90.0
argument_list|,
operator|+
literal|90.0
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|glMatrixMode
argument_list|(
name|GL_MODELVIEW
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeGL
name|void
name|GLWidget
operator|::
name|resizeGL
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|glViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
operator|*
name|devicePixelRatio
argument_list|()
argument_list|,
name|height
operator|*
name|devicePixelRatio
argument_list|()
argument_list|)
expr_stmt|;
name|aspect
operator|=
operator|(
name|qreal
operator|)
name|width
operator|/
call|(
name|qreal
call|)
argument_list|(
name|height
condition|?
name|height
else|:
literal|1
argument_list|)
expr_stmt|;
name|perspectiveProjection
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|drawPbuffer
name|void
name|GLWidget
operator|::
name|drawPbuffer
parameter_list|()
block|{
name|orthographicProjection
argument_list|()
expr_stmt|;
name|glClearColor
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
operator||
name|GL_DEPTH_BUFFER_BIT
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_TEXTURE_2D
argument_list|)
expr_stmt|;
name|backdrop
operator|->
name|draw
argument_list|()
expr_stmt|;
name|glEnable
argument_list|(
name|GL_TEXTURE_2D
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|cubeTexture
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_CULL_FACE
argument_list|)
expr_stmt|;
name|cube
operator|->
name|draw
argument_list|()
expr_stmt|;
name|glEnable
argument_list|(
name|GL_CULL_FACE
argument_list|)
expr_stmt|;
name|glFlush
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initPbuffer
name|void
name|GLWidget
operator|::
name|initPbuffer
parameter_list|()
block|{
name|pbuffer
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
name|cubeTexture
operator|=
name|bindTexture
argument_list|(
name|QImage
argument_list|(
literal|":res/cubelogo.png"
argument_list|)
argument_list|)
expr_stmt|;
name|initCommon
argument_list|()
expr_stmt|;
comment|// generate a texture that has the same size/format as the pbuffer
name|dynamicTexture
operator|=
name|pbuffer
operator|->
name|generateDynamicTexture
argument_list|()
expr_stmt|;
comment|// bind the dynamic texture to the pbuffer - this is a no-op under X11
name|hasDynamicTextureUpdate
operator|=
name|pbuffer
operator|->
name|bindToDynamicTexture
argument_list|(
name|dynamicTexture
argument_list|)
expr_stmt|;
name|makeCurrent
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setAnimationPaused
name|void
name|GLWidget
operator|::
name|setAnimationPaused
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|cube
operator|->
name|setAnimationPaused
argument_list|(
name|enable
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
literal|3
condition|;
operator|++
name|i
control|)
name|cubes
index|[
name|i
index|]
operator|->
name|setAnimationPaused
argument_list|(
name|enable
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
