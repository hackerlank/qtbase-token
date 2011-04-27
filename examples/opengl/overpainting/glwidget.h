begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|GLWIDGET_H
end_ifndef
begin_define
DECL|macro|GLWIDGET_H
define|#
directive|define
name|GLWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QBrush>
end_include
begin_include
include|#
directive|include
file|<QFont>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QPen>
end_include
begin_include
include|#
directive|include
file|<QGLWidget>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_decl_stmt
DECL|variable|Bubble
name|class
name|Bubble
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QtLogo
name|class
name|QtLogo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPaintEvent
name|class
name|QPaintEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|GLWidget
range|:
name|public
name|QGLWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|GLWidget
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|GLWidget
argument_list|()
block|;
comment|//! [0]
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|int
name|xRotation
argument_list|()
specifier|const
block|{
return|return
name|xRot
return|;
block|}
name|int
name|yRotation
argument_list|()
specifier|const
block|{
return|return
name|yRot
return|;
block|}
name|int
name|zRotation
argument_list|()
specifier|const
block|{
return|return
name|zRot
return|;
block|}
name|public
name|slots
operator|:
name|void
name|setXRotation
argument_list|(
argument|int angle
argument_list|)
block|;
name|void
name|setYRotation
argument_list|(
argument|int angle
argument_list|)
block|;
name|void
name|setZRotation
argument_list|(
argument|int angle
argument_list|)
block|;
comment|//! [1]
name|protected
operator|:
name|void
name|initializeGL
argument_list|()
block|;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|resizeGL
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|showEvent
argument_list|(
name|QShowEvent
operator|*
name|event
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|animate
argument_list|()
block|;
name|private
operator|:
name|void
name|createBubbles
argument_list|(
argument|int number
argument_list|)
block|;
name|void
name|drawInstructions
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|)
block|;
comment|//! [1]
name|void
name|setupViewport
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
block|;
name|QColor
name|qtGreen
block|;
name|QColor
name|qtPurple
block|;
name|GLuint
name|object
block|;
name|int
name|xRot
block|;
name|int
name|yRot
block|;
name|int
name|zRot
block|;
name|QPoint
name|lastPos
block|;
comment|//! [4]
name|QtLogo
operator|*
name|logo
block|;
name|QList
operator|<
name|Bubble
operator|*
operator|>
name|bubbles
block|;
name|QTimer
name|animationTimer
block|;
comment|//! [4]
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
