begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DOCUMENT_H
end_ifndef
begin_define
DECL|macro|DOCUMENT_H
define|#
directive|define
name|DOCUMENT_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_macro
DECL|function|QT_FORWARD_DECLARE_CLASS
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QUndoStack
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QTextStream
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Shape
block|{
name|public
label|:
enum|enum
name|Type
block|{
name|Rectangle
block|,
name|Circle
block|,
name|Triangle
block|}
enum|;
name|explicit
name|Shape
parameter_list|(
name|Type
name|type
init|=
name|Rectangle
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
init|=
name|Qt
operator|::
name|red
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
init|=
name|QRect
argument_list|()
parameter_list|)
function_decl|;
name|Type
name|type
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|QRect
name|rect
argument_list|()
specifier|const
expr_stmt|;
name|QRect
name|resizeHandle
argument_list|()
specifier|const
expr_stmt|;
name|QColor
name|color
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QString
name|typeToString
parameter_list|(
name|Type
name|type
parameter_list|)
function_decl|;
specifier|static
name|Type
name|stringToType
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|,
name|bool
modifier|*
name|ok
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|QSize
name|minSize
decl_stmt|;
name|private
label|:
name|Type
name|m_type
decl_stmt|;
name|QRect
name|m_rect
decl_stmt|;
name|QColor
name|m_color
decl_stmt|;
name|QString
name|m_name
decl_stmt|;
name|friend
name|class
name|Document
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Document
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|Document
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QString
name|addShape
argument_list|(
specifier|const
name|Shape
operator|&
name|shape
argument_list|)
block|;
name|void
name|deleteShape
argument_list|(
specifier|const
name|QString
operator|&
name|shapeName
argument_list|)
block|;
name|Shape
name|shape
argument_list|(
argument|const QString&shapeName
argument_list|)
specifier|const
block|;
name|QString
name|currentShapeName
argument_list|()
specifier|const
block|;
name|void
name|setShapeRect
argument_list|(
specifier|const
name|QString
operator|&
name|shapeName
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|setShapeColor
argument_list|(
specifier|const
name|QString
operator|&
name|shapeName
argument_list|,
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|bool
name|load
argument_list|(
name|QTextStream
operator|&
name|stream
argument_list|)
block|;
name|void
name|save
argument_list|(
name|QTextStream
operator|&
name|stream
argument_list|)
block|;
name|QString
name|fileName
argument_list|()
specifier|const
block|;
name|void
name|setFileName
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|QUndoStack
operator|*
name|undoStack
argument_list|()
specifier|const
block|;
name|signals
operator|:
name|void
name|currentShapeChanged
argument_list|(
specifier|const
name|QString
operator|&
name|shapeName
argument_list|)
block|;
name|protected
operator|:
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mousePressEvent
argument_list|(
argument|QMouseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseReleaseEvent
argument_list|(
argument|QMouseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseMoveEvent
argument_list|(
argument|QMouseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|void
name|setCurrentShape
argument_list|(
argument|int index
argument_list|)
block|;
name|int
name|indexOf
argument_list|(
argument|const QString&shapeName
argument_list|)
specifier|const
block|;
name|int
name|indexAt
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|;
name|QString
name|uniqueName
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|Shape
operator|>
name|m_shapeList
block|;
name|int
name|m_currentIndex
block|;
name|int
name|m_mousePressIndex
block|;
name|QPoint
name|m_mousePressOffset
block|;
name|bool
name|m_resizeHandlePressed
block|;
name|QString
name|m_fileName
block|;
name|QUndoStack
operator|*
name|m_undoStack
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// DOCUMENT_H
end_comment
end_unit
