begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"layoutitem.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|LayoutItem
name|LayoutItem
operator|::
name|LayoutItem
parameter_list|(
name|QGraphicsItem
modifier|*
name|parent
comment|/* = 0*/
parameter_list|)
member_init_list|:
name|QGraphicsLayoutItem
argument_list|()
member_init_list|,
name|QGraphicsItem
argument_list|(
name|parent
argument_list|)
block|{
name|m_pix
operator|=
operator|new
name|QPixmap
argument_list|(
name|QLatin1String
argument_list|(
literal|":/images/block.png"
argument_list|)
argument_list|)
expr_stmt|;
name|setGraphicsItem
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_destructor
DECL|function|~LayoutItem
name|LayoutItem
operator|::
name|~
name|LayoutItem
parameter_list|()
block|{
operator|delete
name|m_pix
expr_stmt|;
block|}
end_destructor
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|paint
name|void
name|LayoutItem
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
comment|/*= 0*/
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|option
argument_list|)
expr_stmt|;
name|QRectF
name|frame
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|qreal
name|w
init|=
name|m_pix
operator|->
name|width
argument_list|()
decl_stmt|;
name|qreal
name|h
init|=
name|m_pix
operator|->
name|height
argument_list|()
decl_stmt|;
name|QGradientStops
name|stops
decl_stmt|;
comment|//! [1]
comment|//! [2]
comment|// paint a background rect (with gradient)
name|QLinearGradient
name|gradient
argument_list|(
name|frame
operator|.
name|topLeft
argument_list|()
argument_list|,
name|frame
operator|.
name|topLeft
argument_list|()
operator|+
name|QPointF
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
argument_list|)
decl_stmt|;
name|stops
operator|<<
name|QGradientStop
argument_list|(
literal|0.0
argument_list|,
name|QColor
argument_list|(
literal|60
argument_list|,
literal|60
argument_list|,
literal|60
argument_list|)
argument_list|)
expr_stmt|;
name|stops
operator|<<
name|QGradientStop
argument_list|(
name|frame
operator|.
name|height
argument_list|()
operator|/
literal|2
operator|/
name|frame
operator|.
name|height
argument_list|()
argument_list|,
name|QColor
argument_list|(
literal|102
argument_list|,
literal|176
argument_list|,
literal|54
argument_list|)
argument_list|)
expr_stmt|;
comment|//stops<< QGradientStop(((frame.height() + h)/2 )/frame.height(), QColor(157, 195,  55));
name|stops
operator|<<
name|QGradientStop
argument_list|(
literal|1.0
argument_list|,
name|QColor
argument_list|(
literal|215
argument_list|,
literal|215
argument_list|,
literal|215
argument_list|)
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setStops
argument_list|(
name|stops
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|QBrush
argument_list|(
name|gradient
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRoundedRect
argument_list|(
name|frame
argument_list|,
literal|10.0
argument_list|,
literal|10.0
argument_list|)
expr_stmt|;
comment|// paint a rect around the pixmap (with gradient)
name|QPointF
name|pixpos
init|=
name|frame
operator|.
name|center
argument_list|()
operator|-
operator|(
name|QPointF
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
operator|/
literal|2
operator|)
decl_stmt|;
name|QRectF
name|innerFrame
argument_list|(
name|pixpos
argument_list|,
name|QSizeF
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
decl_stmt|;
name|innerFrame
operator|.
name|adjust
argument_list|(
operator|-
literal|4
argument_list|,
operator|-
literal|4
argument_list|,
operator|+
literal|4
argument_list|,
operator|+
literal|4
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setStart
argument_list|(
name|innerFrame
operator|.
name|topLeft
argument_list|()
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setFinalStop
argument_list|(
name|innerFrame
operator|.
name|bottomRight
argument_list|()
argument_list|)
expr_stmt|;
name|stops
operator|.
name|clear
argument_list|()
expr_stmt|;
name|stops
operator|<<
name|QGradientStop
argument_list|(
literal|0.0
argument_list|,
name|QColor
argument_list|(
literal|215
argument_list|,
literal|255
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
name|stops
operator|<<
name|QGradientStop
argument_list|(
literal|0.5
argument_list|,
name|QColor
argument_list|(
literal|102
argument_list|,
literal|176
argument_list|,
literal|54
argument_list|)
argument_list|)
expr_stmt|;
name|stops
operator|<<
name|QGradientStop
argument_list|(
literal|1.0
argument_list|,
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setStops
argument_list|(
name|stops
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|QBrush
argument_list|(
name|gradient
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRoundedRect
argument_list|(
name|innerFrame
argument_list|,
literal|10.0
argument_list|,
literal|10.0
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPixmap
argument_list|(
name|pixpos
argument_list|,
operator|*
name|m_pix
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
DECL|function|boundingRect
name|QRectF
name|LayoutItem
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|setGeometry
name|void
name|LayoutItem
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|geom
parameter_list|)
block|{
name|prepareGeometryChange
argument_list|()
expr_stmt|;
name|QGraphicsLayoutItem
operator|::
name|setGeometry
argument_list|(
name|geom
argument_list|)
expr_stmt|;
name|setPos
argument_list|(
name|geom
operator|.
name|topLeft
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|sizeHint
name|QSizeF
name|LayoutItem
operator|::
name|sizeHint
parameter_list|(
name|Qt
operator|::
name|SizeHint
name|which
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|constraint
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|which
condition|)
block|{
case|case
name|Qt
operator|::
name|MinimumSize
case|:
case|case
name|Qt
operator|::
name|PreferredSize
case|:
comment|// Do not allow a size smaller than the pixmap with two frames around it.
return|return
name|m_pix
operator|->
name|size
argument_list|()
operator|+
name|QSize
argument_list|(
literal|12
argument_list|,
literal|12
argument_list|)
return|;
case|case
name|Qt
operator|::
name|MaximumSize
case|:
return|return
name|QSizeF
argument_list|(
literal|1000
argument_list|,
literal|1000
argument_list|)
return|;
default|default:
break|break;
block|}
return|return
name|constraint
return|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
end_unit
