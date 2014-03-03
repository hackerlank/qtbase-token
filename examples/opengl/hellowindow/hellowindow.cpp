begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"hellowindow.h"
end_include
begin_include
include|#
directive|include
file|<QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QOpenGLFunctions>
end_include
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_constructor
DECL|function|Renderer
name|Renderer
operator|::
name|Renderer
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|Renderer
modifier|*
name|share
parameter_list|,
name|QScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|m_initialized
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_format
argument_list|(
name|format
argument_list|)
member_init_list|,
name|m_currentWindow
argument_list|(
literal|0
argument_list|)
block|{
name|m_context
operator|=
operator|new
name|QOpenGLContext
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|screen
condition|)
name|m_context
operator|->
name|setScreen
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|setFormat
argument_list|(
name|format
argument_list|)
expr_stmt|;
if|if
condition|(
name|share
condition|)
name|m_context
operator|->
name|setShareContext
argument_list|(
name|share
operator|->
name|m_context
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|create
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|HelloWindow
name|HelloWindow
operator|::
name|HelloWindow
parameter_list|(
specifier|const
name|QSharedPointer
argument_list|<
name|Renderer
argument_list|>
modifier|&
name|renderer
parameter_list|)
member_init_list|:
name|m_colorIndex
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_renderer
argument_list|(
name|renderer
argument_list|)
block|{
name|setSurfaceType
argument_list|(
name|QWindow
operator|::
name|OpenGLSurface
argument_list|)
expr_stmt|;
name|setFlags
argument_list|(
name|Qt
operator|::
name|Window
operator||
name|Qt
operator|::
name|WindowSystemMenuHint
operator||
name|Qt
operator|::
name|WindowTitleHint
operator||
name|Qt
operator|::
name|WindowMinMaxButtonsHint
operator||
name|Qt
operator|::
name|WindowCloseButtonHint
argument_list|)
expr_stmt|;
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|640
argument_list|,
literal|480
argument_list|)
argument_list|)
expr_stmt|;
name|setFormat
argument_list|(
name|renderer
operator|->
name|format
argument_list|()
argument_list|)
expr_stmt|;
name|create
argument_list|()
expr_stmt|;
name|updateColor
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|exposeEvent
name|void
name|HelloWindow
operator|::
name|exposeEvent
parameter_list|(
name|QExposeEvent
modifier|*
parameter_list|)
block|{
name|m_renderer
operator|->
name|setAnimating
argument_list|(
name|this
argument_list|,
name|isExposed
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|HelloWindow
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
block|{
name|updateColor
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|color
name|QColor
name|HelloWindow
operator|::
name|color
parameter_list|()
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|m_colorLock
argument_list|)
decl_stmt|;
return|return
name|m_color
return|;
block|}
end_function
begin_function
DECL|function|updateColor
name|void
name|HelloWindow
operator|::
name|updateColor
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|m_colorLock
argument_list|)
decl_stmt|;
name|QColor
name|colors
index|[]
init|=
block|{
name|QColor
argument_list|(
literal|100
argument_list|,
literal|255
argument_list|,
literal|0
argument_list|)
block|,
name|QColor
argument_list|(
literal|0
argument_list|,
literal|100
argument_list|,
literal|255
argument_list|)
block|}
decl_stmt|;
name|m_color
operator|=
name|colors
index|[
name|m_colorIndex
index|]
expr_stmt|;
name|m_colorIndex
operator|=
literal|1
operator|-
name|m_colorIndex
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setAnimating
name|void
name|Renderer
operator|::
name|setAnimating
parameter_list|(
name|HelloWindow
modifier|*
name|window
parameter_list|,
name|bool
name|animating
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|m_windowLock
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_windows
operator|.
name|contains
argument_list|(
name|window
argument_list|)
operator|==
name|animating
condition|)
return|return;
if|if
condition|(
name|animating
condition|)
block|{
name|m_windows
operator|<<
name|window
expr_stmt|;
if|if
condition|(
name|m_windows
operator|.
name|size
argument_list|()
operator|==
literal|1
condition|)
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|render
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_currentWindow
operator|=
literal|0
expr_stmt|;
name|m_windows
operator|.
name|removeOne
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|render
name|void
name|Renderer
operator|::
name|render
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|m_windowLock
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_windows
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|HelloWindow
modifier|*
name|surface
init|=
name|m_windows
operator|.
name|at
argument_list|(
name|m_currentWindow
argument_list|)
decl_stmt|;
name|QColor
name|color
init|=
name|surface
operator|->
name|color
argument_list|()
decl_stmt|;
name|m_currentWindow
operator|=
operator|(
name|m_currentWindow
operator|+
literal|1
operator|)
operator|%
name|m_windows
operator|.
name|size
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|m_context
operator|->
name|makeCurrent
argument_list|(
name|surface
argument_list|)
condition|)
return|return;
name|QSize
name|viewSize
init|=
name|surface
operator|->
name|size
argument_list|()
decl_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|m_initialized
condition|)
block|{
name|initialize
argument_list|()
expr_stmt|;
name|m_initialized
operator|=
literal|true
expr_stmt|;
block|}
name|QOpenGLFunctions
modifier|*
name|f
init|=
name|m_context
operator|->
name|functions
argument_list|()
decl_stmt|;
name|f
operator|->
name|glViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|viewSize
operator|.
name|width
argument_list|()
operator|*
name|surface
operator|->
name|devicePixelRatio
argument_list|()
argument_list|,
name|viewSize
operator|.
name|height
argument_list|()
operator|*
name|surface
operator|->
name|devicePixelRatio
argument_list|()
argument_list|)
expr_stmt|;
name|f
operator|->
name|glClearColor
argument_list|(
literal|0.1f
argument_list|,
literal|0.1f
argument_list|,
literal|0.2f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|f
operator|->
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
operator||
name|GL_DEPTH_BUFFER_BIT
argument_list|)
expr_stmt|;
name|f
operator|->
name|glFrontFace
argument_list|(
name|GL_CW
argument_list|)
expr_stmt|;
name|f
operator|->
name|glCullFace
argument_list|(
name|GL_FRONT
argument_list|)
expr_stmt|;
name|f
operator|->
name|glEnable
argument_list|(
name|GL_CULL_FACE
argument_list|)
expr_stmt|;
name|f
operator|->
name|glEnable
argument_list|(
name|GL_DEPTH_TEST
argument_list|)
expr_stmt|;
name|QMatrix4x4
name|modelview
decl_stmt|;
name|modelview
operator|.
name|rotate
argument_list|(
name|m_fAngle
argument_list|,
literal|0.0f
argument_list|,
literal|1.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|modelview
operator|.
name|rotate
argument_list|(
name|m_fAngle
argument_list|,
literal|1.0f
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|modelview
operator|.
name|rotate
argument_list|(
name|m_fAngle
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|modelview
operator|.
name|translate
argument_list|(
literal|0.0f
argument_list|,
operator|-
literal|0.2f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|bind
argument_list|()
expr_stmt|;
name|m_program
operator|->
name|setUniformValue
argument_list|(
name|matrixUniform
argument_list|,
name|modelview
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|setUniformValue
argument_list|(
name|colorUniform
argument_list|,
name|color
argument_list|)
expr_stmt|;
name|paintQtLogo
argument_list|()
expr_stmt|;
name|m_program
operator|->
name|release
argument_list|()
expr_stmt|;
name|f
operator|->
name|glDisable
argument_list|(
name|GL_DEPTH_TEST
argument_list|)
expr_stmt|;
name|f
operator|->
name|glDisable
argument_list|(
name|GL_CULL_FACE
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|swapBuffers
argument_list|(
name|surface
argument_list|)
expr_stmt|;
name|m_fAngle
operator|+=
literal|1.0f
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|render
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintQtLogo
name|void
name|Renderer
operator|::
name|paintQtLogo
parameter_list|()
block|{
name|m_program
operator|->
name|enableAttributeArray
argument_list|(
name|normalAttr
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|enableAttributeArray
argument_list|(
name|vertexAttr
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|setAttributeArray
argument_list|(
name|vertexAttr
argument_list|,
name|vertices
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|setAttributeArray
argument_list|(
name|normalAttr
argument_list|,
name|normals
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|glDrawArrays
argument_list|(
name|GL_TRIANGLES
argument_list|,
literal|0
argument_list|,
name|vertices
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|disableAttributeArray
argument_list|(
name|normalAttr
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|disableAttributeArray
argument_list|(
name|vertexAttr
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initialize
name|void
name|Renderer
operator|::
name|initialize
parameter_list|()
block|{
name|QOpenGLShader
modifier|*
name|vshader
init|=
operator|new
name|QOpenGLShader
argument_list|(
name|QOpenGLShader
operator|::
name|Vertex
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|vshader
operator|->
name|compileSourceCode
argument_list|(
literal|"attribute highp vec4 vertex;"
literal|"attribute mediump vec3 normal;"
literal|"uniform mediump mat4 matrix;"
literal|"uniform lowp vec4 sourceColor;"
literal|"varying mediump vec4 color;"
literal|"void main(void)"
literal|"{"
literal|"    vec3 toLight = normalize(vec3(0.0, 0.3, 1.0));"
literal|"    float angle = max(dot(normal, toLight), 0.0);"
literal|"    vec3 col = sourceColor.rgb;"
literal|"    color = vec4(col * 0.2 + col * 0.8 * angle, 1.0);"
literal|"    color = clamp(color, 0.0, 1.0);"
literal|"    gl_Position = matrix * vertex;"
literal|"}"
argument_list|)
expr_stmt|;
name|QOpenGLShader
modifier|*
name|fshader
init|=
operator|new
name|QOpenGLShader
argument_list|(
name|QOpenGLShader
operator|::
name|Fragment
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|fshader
operator|->
name|compileSourceCode
argument_list|(
literal|"varying mediump vec4 color;"
literal|"void main(void)"
literal|"{"
literal|"    gl_FragColor = color;"
literal|"}"
argument_list|)
expr_stmt|;
name|m_program
operator|=
operator|new
name|QOpenGLShaderProgram
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|addShader
argument_list|(
name|vshader
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|addShader
argument_list|(
name|fshader
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|link
argument_list|()
expr_stmt|;
name|vertexAttr
operator|=
name|m_program
operator|->
name|attributeLocation
argument_list|(
literal|"vertex"
argument_list|)
expr_stmt|;
name|normalAttr
operator|=
name|m_program
operator|->
name|attributeLocation
argument_list|(
literal|"normal"
argument_list|)
expr_stmt|;
name|matrixUniform
operator|=
name|m_program
operator|->
name|uniformLocation
argument_list|(
literal|"matrix"
argument_list|)
expr_stmt|;
name|colorUniform
operator|=
name|m_program
operator|->
name|uniformLocation
argument_list|(
literal|"sourceColor"
argument_list|)
expr_stmt|;
name|m_fAngle
operator|=
literal|0
expr_stmt|;
name|createGeometry
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createGeometry
name|void
name|Renderer
operator|::
name|createGeometry
parameter_list|()
block|{
name|vertices
operator|.
name|clear
argument_list|()
expr_stmt|;
name|normals
operator|.
name|clear
argument_list|()
expr_stmt|;
name|qreal
name|x1
init|=
operator|+
literal|0.06f
decl_stmt|;
name|qreal
name|y1
init|=
operator|-
literal|0.14f
decl_stmt|;
name|qreal
name|x2
init|=
operator|+
literal|0.14f
decl_stmt|;
name|qreal
name|y2
init|=
operator|-
literal|0.06f
decl_stmt|;
name|qreal
name|x3
init|=
operator|+
literal|0.08f
decl_stmt|;
name|qreal
name|y3
init|=
operator|+
literal|0.00f
decl_stmt|;
name|qreal
name|x4
init|=
operator|+
literal|0.30f
decl_stmt|;
name|qreal
name|y4
init|=
operator|+
literal|0.22f
decl_stmt|;
name|quad
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|,
name|x2
argument_list|,
name|y2
argument_list|,
name|y2
argument_list|,
name|x2
argument_list|,
name|y1
argument_list|,
name|x1
argument_list|)
expr_stmt|;
name|quad
argument_list|(
name|x3
argument_list|,
name|y3
argument_list|,
name|x4
argument_list|,
name|y4
argument_list|,
name|y4
argument_list|,
name|x4
argument_list|,
name|y3
argument_list|,
name|x3
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|,
name|x2
argument_list|,
name|y2
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|x2
argument_list|,
name|y2
argument_list|,
name|y2
argument_list|,
name|x2
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|y2
argument_list|,
name|x2
argument_list|,
name|y1
argument_list|,
name|x1
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|y1
argument_list|,
name|x1
argument_list|,
name|x1
argument_list|,
name|y1
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|x3
argument_list|,
name|y3
argument_list|,
name|x4
argument_list|,
name|y4
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|x4
argument_list|,
name|y4
argument_list|,
name|y4
argument_list|,
name|x4
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|y4
argument_list|,
name|x4
argument_list|,
name|y3
argument_list|,
name|x3
argument_list|)
expr_stmt|;
specifier|const
name|qreal
name|Pi
init|=
literal|3.14159f
decl_stmt|;
specifier|const
name|int
name|NumSectors
init|=
literal|100
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
name|NumSectors
condition|;
operator|++
name|i
control|)
block|{
name|qreal
name|angle1
init|=
operator|(
name|i
operator|*
literal|2
operator|*
name|Pi
operator|)
operator|/
name|NumSectors
decl_stmt|;
name|qreal
name|x5
init|=
literal|0.30
operator|*
name|qSin
argument_list|(
name|angle1
argument_list|)
decl_stmt|;
name|qreal
name|y5
init|=
literal|0.30
operator|*
name|qCos
argument_list|(
name|angle1
argument_list|)
decl_stmt|;
name|qreal
name|x6
init|=
literal|0.20
operator|*
name|qSin
argument_list|(
name|angle1
argument_list|)
decl_stmt|;
name|qreal
name|y6
init|=
literal|0.20
operator|*
name|qCos
argument_list|(
name|angle1
argument_list|)
decl_stmt|;
name|qreal
name|angle2
init|=
operator|(
operator|(
name|i
operator|+
literal|1
operator|)
operator|*
literal|2
operator|*
name|Pi
operator|)
operator|/
name|NumSectors
decl_stmt|;
name|qreal
name|x7
init|=
literal|0.20
operator|*
name|qSin
argument_list|(
name|angle2
argument_list|)
decl_stmt|;
name|qreal
name|y7
init|=
literal|0.20
operator|*
name|qCos
argument_list|(
name|angle2
argument_list|)
decl_stmt|;
name|qreal
name|x8
init|=
literal|0.30
operator|*
name|qSin
argument_list|(
name|angle2
argument_list|)
decl_stmt|;
name|qreal
name|y8
init|=
literal|0.30
operator|*
name|qCos
argument_list|(
name|angle2
argument_list|)
decl_stmt|;
name|quad
argument_list|(
name|x5
argument_list|,
name|y5
argument_list|,
name|x6
argument_list|,
name|y6
argument_list|,
name|x7
argument_list|,
name|y7
argument_list|,
name|x8
argument_list|,
name|y8
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|x6
argument_list|,
name|y6
argument_list|,
name|x7
argument_list|,
name|y7
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|x8
argument_list|,
name|y8
argument_list|,
name|x5
argument_list|,
name|y5
argument_list|)
expr_stmt|;
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
name|vertices
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
name|vertices
index|[
name|i
index|]
operator|*=
literal|2.0f
expr_stmt|;
block|}
end_function
begin_function
DECL|function|quad
name|void
name|Renderer
operator|::
name|quad
parameter_list|(
name|qreal
name|x1
parameter_list|,
name|qreal
name|y1
parameter_list|,
name|qreal
name|x2
parameter_list|,
name|qreal
name|y2
parameter_list|,
name|qreal
name|x3
parameter_list|,
name|qreal
name|y3
parameter_list|,
name|qreal
name|x4
parameter_list|,
name|qreal
name|y4
parameter_list|)
block|{
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|,
operator|-
literal|0.05f
argument_list|)
expr_stmt|;
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x2
argument_list|,
name|y2
argument_list|,
operator|-
literal|0.05f
argument_list|)
expr_stmt|;
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x4
argument_list|,
name|y4
argument_list|,
operator|-
literal|0.05f
argument_list|)
expr_stmt|;
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x3
argument_list|,
name|y3
argument_list|,
operator|-
literal|0.05f
argument_list|)
expr_stmt|;
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x4
argument_list|,
name|y4
argument_list|,
operator|-
literal|0.05f
argument_list|)
expr_stmt|;
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x2
argument_list|,
name|y2
argument_list|,
operator|-
literal|0.05f
argument_list|)
expr_stmt|;
name|QVector3D
name|n
init|=
name|QVector3D
operator|::
name|normal
argument_list|(
name|QVector3D
argument_list|(
name|x2
operator|-
name|x1
argument_list|,
name|y2
operator|-
name|y1
argument_list|,
literal|0.0f
argument_list|)
argument_list|,
name|QVector3D
argument_list|(
name|x4
operator|-
name|x1
argument_list|,
name|y4
operator|-
name|y1
argument_list|,
literal|0.0f
argument_list|)
argument_list|)
decl_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x4
argument_list|,
name|y4
argument_list|,
literal|0.05f
argument_list|)
expr_stmt|;
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x2
argument_list|,
name|y2
argument_list|,
literal|0.05f
argument_list|)
expr_stmt|;
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|,
literal|0.05f
argument_list|)
expr_stmt|;
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x2
argument_list|,
name|y2
argument_list|,
literal|0.05f
argument_list|)
expr_stmt|;
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x4
argument_list|,
name|y4
argument_list|,
literal|0.05f
argument_list|)
expr_stmt|;
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x3
argument_list|,
name|y3
argument_list|,
literal|0.05f
argument_list|)
expr_stmt|;
name|n
operator|=
name|QVector3D
operator|::
name|normal
argument_list|(
name|QVector3D
argument_list|(
name|x2
operator|-
name|x4
argument_list|,
name|y2
operator|-
name|y4
argument_list|,
literal|0.0f
argument_list|)
argument_list|,
name|QVector3D
argument_list|(
name|x1
operator|-
name|x4
argument_list|,
name|y1
operator|-
name|y4
argument_list|,
literal|0.0f
argument_list|)
argument_list|)
expr_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
block|}
end_function
begin_function
DECL|function|extrude
name|void
name|Renderer
operator|::
name|extrude
parameter_list|(
name|qreal
name|x1
parameter_list|,
name|qreal
name|y1
parameter_list|,
name|qreal
name|x2
parameter_list|,
name|qreal
name|y2
parameter_list|)
block|{
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|,
operator|+
literal|0.05f
argument_list|)
expr_stmt|;
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x2
argument_list|,
name|y2
argument_list|,
operator|+
literal|0.05f
argument_list|)
expr_stmt|;
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|,
operator|-
literal|0.05f
argument_list|)
expr_stmt|;
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x2
argument_list|,
name|y2
argument_list|,
operator|-
literal|0.05f
argument_list|)
expr_stmt|;
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|,
operator|-
literal|0.05f
argument_list|)
expr_stmt|;
name|vertices
operator|<<
name|QVector3D
argument_list|(
name|x2
argument_list|,
name|y2
argument_list|,
operator|+
literal|0.05f
argument_list|)
expr_stmt|;
name|QVector3D
name|n
init|=
name|QVector3D
operator|::
name|normal
argument_list|(
name|QVector3D
argument_list|(
name|x2
operator|-
name|x1
argument_list|,
name|y2
operator|-
name|y1
argument_list|,
literal|0.0f
argument_list|)
argument_list|,
name|QVector3D
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
operator|-
literal|0.1f
argument_list|)
argument_list|)
decl_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
name|normals
operator|<<
name|n
expr_stmt|;
block|}
end_function
end_unit
