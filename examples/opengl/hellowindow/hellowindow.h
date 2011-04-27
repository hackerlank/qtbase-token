begin_unit
begin_include
include|#
directive|include
file|<QWindow>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/qgl.h>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/qglshaderprogram.h>
end_include
begin_include
include|#
directive|include
file|<QTime>
end_include
begin_decl_stmt
name|class
name|HelloWindow
range|:
name|public
name|QWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|HelloWindow
argument_list|()
block|;
name|protected
operator|:
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|render
argument_list|()
block|;
name|private
operator|:
name|void
name|initialize
argument_list|()
block|;
name|void
name|updateColor
argument_list|()
block|;
name|qreal
name|m_fAngle
block|;
name|bool
name|m_showBubbles
block|;
name|void
name|paintQtLogo
argument_list|()
block|;
name|void
name|createGeometry
argument_list|()
block|;
name|void
name|createBubbles
argument_list|(
argument|int number
argument_list|)
block|;
name|void
name|quad
argument_list|(
argument|qreal x1
argument_list|,
argument|qreal y1
argument_list|,
argument|qreal x2
argument_list|,
argument|qreal y2
argument_list|,
argument|qreal x3
argument_list|,
argument|qreal y3
argument_list|,
argument|qreal x4
argument_list|,
argument|qreal y4
argument_list|)
block|;
name|void
name|extrude
argument_list|(
argument|qreal x1
argument_list|,
argument|qreal y1
argument_list|,
argument|qreal x2
argument_list|,
argument|qreal y2
argument_list|)
block|;
name|QVector
operator|<
name|QVector3D
operator|>
name|vertices
block|;
name|QVector
operator|<
name|QVector3D
operator|>
name|normals
block|;
name|QGLShaderProgram
name|program
block|;
name|int
name|vertexAttr
block|;
name|int
name|normalAttr
block|;
name|int
name|matrixUniform
block|;
name|int
name|colorUniform
block|;
name|uint
name|colorIndex
block|; }
decl_stmt|;
end_decl_stmt
end_unit
