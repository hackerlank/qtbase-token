begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"coloritem.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|ColorItem
name|ColorItem
operator|::
name|ColorItem
parameter_list|()
member_init_list|:
name|color
argument_list|(
name|qrand
argument_list|()
operator|%
literal|256
argument_list|,
name|qrand
argument_list|()
operator|%
literal|256
argument_list|,
name|qrand
argument_list|()
operator|%
literal|256
argument_list|)
block|{
name|setToolTip
argument_list|(
name|QString
argument_list|(
literal|"QColor(%1, %2, %3)\n%4"
argument_list|)
operator|.
name|arg
argument_list|(
name|color
operator|.
name|red
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|color
operator|.
name|green
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|color
operator|.
name|blue
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
literal|"Click and drag this color onto the robot!"
argument_list|)
argument_list|)
expr_stmt|;
name|setCursor
argument_list|(
name|Qt
operator|::
name|OpenHandCursor
argument_list|)
expr_stmt|;
name|setAcceptedMouseButtons
argument_list|(
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|boundingRect
name|QRectF
name|ColorItem
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|(
operator|-
literal|15.5
argument_list|,
operator|-
literal|15.5
argument_list|,
literal|34
argument_list|,
literal|34
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|paint
name|void
name|ColorItem
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
name|option
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|option
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|darkGray
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
operator|-
literal|12
argument_list|,
operator|-
literal|12
argument_list|,
literal|30
argument_list|,
literal|30
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|QBrush
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
operator|-
literal|15
argument_list|,
operator|-
literal|15
argument_list|,
literal|30
argument_list|,
literal|30
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|mousePressEvent
name|void
name|ColorItem
operator|::
name|mousePressEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
parameter_list|)
block|{
name|setCursor
argument_list|(
name|Qt
operator|::
name|ClosedHandCursor
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|mouseMoveEvent
name|void
name|ColorItem
operator|::
name|mouseMoveEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|QLineF
argument_list|(
name|event
operator|->
name|screenPos
argument_list|()
argument_list|,
name|event
operator|->
name|buttonDownScreenPos
argument_list|(
name|Qt
operator|::
name|LeftButton
argument_list|)
argument_list|)
operator|.
name|length
argument_list|()
operator|<
name|QApplication
operator|::
name|startDragDistance
argument_list|()
condition|)
block|{
return|return;
block|}
name|QDrag
modifier|*
name|drag
init|=
operator|new
name|QDrag
argument_list|(
name|event
operator|->
name|widget
argument_list|()
argument_list|)
decl_stmt|;
name|QMimeData
modifier|*
name|mime
init|=
operator|new
name|QMimeData
decl_stmt|;
name|drag
operator|->
name|setMimeData
argument_list|(
name|mime
argument_list|)
expr_stmt|;
comment|//! [5]
comment|//! [6]
specifier|static
name|int
name|n
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|n
operator|++
operator|>
literal|2
operator|&&
operator|(
name|qrand
argument_list|()
operator|%
literal|3
operator|)
operator|==
literal|0
condition|)
block|{
name|QImage
name|image
argument_list|(
literal|":/images/head.png"
argument_list|)
decl_stmt|;
name|mime
operator|->
name|setImageData
argument_list|(
name|image
argument_list|)
expr_stmt|;
name|drag
operator|->
name|setPixmap
argument_list|(
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|image
argument_list|)
operator|.
name|scaled
argument_list|(
literal|30
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
name|drag
operator|->
name|setHotSpot
argument_list|(
name|QPoint
argument_list|(
literal|15
argument_list|,
literal|30
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [6]
comment|//! [7]
block|}
else|else
block|{
name|mime
operator|->
name|setColorData
argument_list|(
name|color
argument_list|)
expr_stmt|;
name|mime
operator|->
name|setText
argument_list|(
name|QString
argument_list|(
literal|"#%1%2%3"
argument_list|)
operator|.
name|arg
argument_list|(
name|color
operator|.
name|red
argument_list|()
argument_list|,
literal|2
argument_list|,
literal|16
argument_list|,
name|QLatin1Char
argument_list|(
literal|'0'
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|color
operator|.
name|green
argument_list|()
argument_list|,
literal|2
argument_list|,
literal|16
argument_list|,
name|QLatin1Char
argument_list|(
literal|'0'
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|color
operator|.
name|blue
argument_list|()
argument_list|,
literal|2
argument_list|,
literal|16
argument_list|,
name|QLatin1Char
argument_list|(
literal|'0'
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QPixmap
name|pixmap
argument_list|(
literal|34
argument_list|,
literal|34
argument_list|)
decl_stmt|;
name|pixmap
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|pixmap
argument_list|)
decl_stmt|;
name|painter
operator|.
name|translate
argument_list|(
literal|15
argument_list|,
literal|15
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|paint
argument_list|(
operator|&
name|painter
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
name|pixmap
operator|.
name|setMask
argument_list|(
name|pixmap
operator|.
name|createHeuristicMask
argument_list|()
argument_list|)
expr_stmt|;
name|drag
operator|->
name|setPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
name|drag
operator|->
name|setHotSpot
argument_list|(
name|QPoint
argument_list|(
literal|15
argument_list|,
literal|20
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|//! [7]
comment|//! [8]
name|drag
operator|->
name|exec
argument_list|()
expr_stmt|;
name|setCursor
argument_list|(
name|Qt
operator|::
name|OpenHandCursor
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|mouseReleaseEvent
name|void
name|ColorItem
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
parameter_list|)
block|{
name|setCursor
argument_list|(
name|Qt
operator|::
name|OpenHandCursor
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
end_unit
