begin_unit
begin_include
include|#
directive|include
file|<QWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopengl.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopenglshaderprogram.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopenglframebufferobject.h>
end_include
begin_include
include|#
directive|include
file|<QColor>
end_include
begin_include
include|#
directive|include
file|<QTime>
end_include
begin_decl_stmt
DECL|variable|QOpenGLContext
name|class
name|QOpenGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|PaintedWindow
range|:
name|public
name|QWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|PaintedWindow
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|paint
argument_list|()
block|;
name|private
operator|:
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
argument_list|)
block|;
name|void
name|exposeEvent
argument_list|(
name|QExposeEvent
operator|*
argument_list|)
block|;
name|QOpenGLContext
operator|*
name|m_context
block|; }
decl_stmt|;
end_decl_stmt
end_unit
