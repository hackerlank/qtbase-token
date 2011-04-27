begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|p
name|QPoint
name|p
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|p
operator|.
name|setX
argument_list|(
name|p
operator|.
name|x
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|p
operator|+=
name|QPoint
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|p
operator|.
name|rx
argument_list|()
operator|++
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
name|QPoint
name|p
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|p
operator|.
name|rx
argument_list|()
operator|--
expr_stmt|;
end_expr_stmt
begin_comment
comment|// p becomes (0, 2)
end_comment
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
name|QPoint
name|p
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|p
operator|.
name|ry
argument_list|()
operator|++
expr_stmt|;
end_expr_stmt
begin_comment
comment|// p becomes (1, 3)
end_comment
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
name|QPoint
name|p
argument_list|(
literal|3
argument_list|,
literal|7
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPoint
name|q
argument_list|(
operator|-
literal|1
argument_list|,
literal|4
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|p
operator|+=
name|q
expr_stmt|;
end_expr_stmt
begin_comment
comment|// p becomes (2, 11)
end_comment
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
name|QPoint
name|p
argument_list|(
literal|3
argument_list|,
literal|7
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPoint
name|q
argument_list|(
operator|-
literal|1
argument_list|,
literal|4
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|p
operator|-=
name|q
expr_stmt|;
end_expr_stmt
begin_comment
comment|// p becomes (4, 3)
end_comment
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
name|QPoint
name|p
argument_list|(
operator|-
literal|1
argument_list|,
literal|4
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|p
operator|*=
literal|2.5
expr_stmt|;
end_expr_stmt
begin_comment
comment|// p becomes (-3, 10)
end_comment
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_decl_stmt
name|QPoint
name|p
argument_list|(
operator|-
literal|3
argument_list|,
literal|10
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|p
operator|/=
literal|2.5
expr_stmt|;
end_expr_stmt
begin_comment
comment|// p becomes (-1, 4)
end_comment
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_decl_stmt
DECL|variable|oldPosition
name|QPoint
name|oldPosition
decl_stmt|;
end_decl_stmt
begin_macro
DECL|function|mouseMoveEvent
name|MyWidget
end_macro
begin_expr_stmt
DECL|function|mouseMoveEvent
operator|::
name|mouseMoveEvent
operator|(
name|QMouseEvent
operator|*
name|event
operator|)
block|{
name|QPoint
name|point
operator|=
name|event
operator|->
name|pos
argument_list|()
operator|-
name|oldPosition
block|;
if|if
condition|(
name|point
operator|.
name|manhattanLength
argument_list|()
operator|>
literal|3
condition|)
comment|// the mouse has moved more than 3 pixels since the oldPosition
block|}
comment|//! [7]
comment|//! [8]
DECL|variable|trueLength
name|double
name|trueLength
operator|=
name|sqrt
argument_list|(
name|pow
argument_list|(
name|x
argument_list|()
argument_list|,
literal|2
argument_list|)
operator|+
name|pow
argument_list|(
name|y
argument_list|()
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_decl_stmt
DECL|variable|p
name|QPointF
name|p
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|p
operator|.
name|setX
argument_list|(
name|p
operator|.
name|x
argument_list|()
operator|+
literal|1.0
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|p
operator|+=
name|QPointF
argument_list|(
literal|1.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|p
operator|.
name|rx
argument_list|()
operator|++
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_decl_stmt
name|QPointF
name|p
argument_list|(
literal|1.1
argument_list|,
literal|2.5
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|p
operator|.
name|rx
argument_list|()
operator|--
expr_stmt|;
end_expr_stmt
begin_comment
comment|// p becomes (0.1, 2.5)
end_comment
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_decl_stmt
name|QPointF
name|p
argument_list|(
literal|1.1
argument_list|,
literal|2.5
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|p
operator|.
name|ry
argument_list|()
operator|++
expr_stmt|;
end_expr_stmt
begin_comment
comment|// p becomes (1.1, 3.5)
end_comment
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_decl_stmt
name|QPointF
name|p
argument_list|(
literal|3.1
argument_list|,
literal|7.1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPointF
name|q
argument_list|(
operator|-
literal|1.0
argument_list|,
literal|4.1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|p
operator|+=
name|q
expr_stmt|;
end_expr_stmt
begin_comment
comment|// p becomes (2.1, 11.2)
end_comment
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_decl_stmt
name|QPointF
name|p
argument_list|(
literal|3.1
argument_list|,
literal|7.1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPointF
name|q
argument_list|(
operator|-
literal|1.0
argument_list|,
literal|4.1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|p
operator|-=
name|q
expr_stmt|;
end_expr_stmt
begin_comment
comment|// p becomes (4.1, 3.0)
end_comment
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_decl_stmt
name|QPointF
name|p
argument_list|(
operator|-
literal|1.1
argument_list|,
literal|4.1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|p
operator|*=
literal|2.5
expr_stmt|;
end_expr_stmt
begin_comment
comment|// p becomes (-2.75, 10.25)
end_comment
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_decl_stmt
name|QPointF
name|p
argument_list|(
operator|-
literal|2.75
argument_list|,
literal|10.25
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|p
operator|/=
literal|2.5
expr_stmt|;
end_expr_stmt
begin_comment
comment|// p becomes (-1.1, 4.1)
end_comment
begin_comment
comment|//! [15]
end_comment
end_unit
