begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|path
name|QPainterPath
name|path
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|path
operator|.
name|addRect
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|,
literal|60
argument_list|,
literal|60
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|path
operator|.
name|moveTo
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|path
operator|.
name|cubicTo
argument_list|(
literal|99
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
literal|99
argument_list|,
literal|99
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|path
operator|.
name|cubicTo
argument_list|(
literal|0
argument_list|,
literal|99
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QPainter
name|painter
parameter_list|(
name|this
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|painter
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|member|SolidLine
name|painter
operator|.
name|setPen
argument_list|(
name|QPen
argument_list|(
name|QColor
argument_list|(
literal|79
argument_list|,
literal|106
argument_list|,
literal|25
argument_list|)
argument_list|,
literal|1
argument_list|,
name|Qt
operator|::
name|SolidLine
argument_list|,
DECL|member|FlatCap
DECL|member|MiterJoin
name|Qt
operator|::
name|FlatCap
argument_list|,
name|Qt
operator|::
name|MiterJoin
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|setBrush
argument_list|(
name|QColor
argument_list|(
literal|122
argument_list|,
literal|163
argument_list|,
literal|39
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|drawPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|myGradient
name|QLinearGradient
name|myGradient
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|myPen
name|QPen
name|myPen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|myPath
name|QPainterPath
name|myPath
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|myPath
operator|.
name|cubicTo
argument_list|(
name|c1
argument_list|,
name|c2
argument_list|,
name|endPoint
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QPainter
name|painter
parameter_list|(
name|this
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|painter
operator|.
name|setBrush
argument_list|(
name|myGradient
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|setPen
argument_list|(
name|myPen
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|drawPath
argument_list|(
name|myPath
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|myGradient
name|QLinearGradient
name|myGradient
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|myPen
name|QPen
name|myPen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|center
DECL|variable|startPoint
name|QPointF
name|center
decl_stmt|,
name|startPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|myPath
name|QPainterPath
name|myPath
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|myPath
operator|.
name|moveTo
argument_list|(
name|center
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|myPath
operator|.
name|arcTo
argument_list|(
name|boundingRect
argument_list|,
name|startAngle
argument_list|,
name|sweepLength
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QPainter
name|painter
parameter_list|(
name|this
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|painter
operator|.
name|setBrush
argument_list|(
name|myGradient
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|setPen
argument_list|(
name|myPen
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|drawPath
argument_list|(
name|myPath
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
DECL|variable|myGradient
name|QLinearGradient
name|myGradient
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|myPen
name|QPen
name|myPen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|myRectangle
name|QRectF
name|myRectangle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|myPath
name|QPainterPath
name|myPath
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|myPath
operator|.
name|addRect
argument_list|(
name|myRectangle
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QPainter
name|painter
parameter_list|(
name|this
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|painter
operator|.
name|setBrush
argument_list|(
name|myGradient
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|setPen
argument_list|(
name|myPen
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|drawPath
argument_list|(
name|myPath
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
DECL|variable|myGradient
name|QLinearGradient
name|myGradient
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|myPen
name|QPen
name|myPen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|myPolygon
name|QPolygonF
name|myPolygon
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|myPath
name|QPainterPath
name|myPath
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|myPath
operator|.
name|addPolygon
argument_list|(
name|myPolygon
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QPainter
name|painter
parameter_list|(
name|this
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|painter
operator|.
name|setBrush
argument_list|(
name|myGradient
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|setPen
argument_list|(
name|myPen
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|drawPath
argument_list|(
name|myPath
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
DECL|variable|myGradient
name|QLinearGradient
name|myGradient
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|myPen
name|QPen
name|myPen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|boundingRectangle
name|QRectF
name|boundingRectangle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|myPath
name|QPainterPath
name|myPath
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|myPath
operator|.
name|addEllipse
argument_list|(
name|boundingRectangle
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QPainter
name|painter
parameter_list|(
name|this
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|painter
operator|.
name|setBrush
argument_list|(
name|myGradient
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|setPen
argument_list|(
name|myPen
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|drawPath
argument_list|(
name|myPath
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_decl_stmt
DECL|variable|myGradient
name|QLinearGradient
name|myGradient
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|myPen
name|QPen
name|myPen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|myFont
name|QFont
name|myFont
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QPointF
name|baseline
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|myPath
name|QPainterPath
name|myPath
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|myPath
operator|.
name|addText
argument_list|(
name|baseline
argument_list|,
name|myFont
argument_list|,
name|tr
argument_list|(
literal|"Qt"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QPainter
name|painter
parameter_list|(
name|this
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|painter
operator|.
name|setBrush
argument_list|(
name|myGradient
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|setPen
argument_list|(
name|myPen
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|drawPath
argument_list|(
name|myPath
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [6]
end_comment
end_unit
