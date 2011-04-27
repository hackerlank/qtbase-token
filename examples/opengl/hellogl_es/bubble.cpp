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
file|"bubble.h"
end_include
begin_constructor
DECL|function|Bubble
name|Bubble
operator|::
name|Bubble
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|position
parameter_list|,
name|qreal
name|radius
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|velocity
parameter_list|)
member_init_list|:
name|position
argument_list|(
name|position
argument_list|)
member_init_list|,
name|vel
argument_list|(
name|velocity
argument_list|)
member_init_list|,
name|radius
argument_list|(
name|radius
argument_list|)
block|{
name|innerColor
operator|=
name|randomColor
argument_list|()
expr_stmt|;
name|outerColor
operator|=
name|randomColor
argument_list|()
expr_stmt|;
name|cache
operator|=
literal|0
expr_stmt|;
name|updateBrush
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|updateCache
name|void
name|Bubble
operator|::
name|updateCache
parameter_list|()
block|{
if|if
condition|(
name|cache
condition|)
operator|delete
name|cache
expr_stmt|;
name|cache
operator|=
operator|new
name|QImage
argument_list|(
name|qRound
argument_list|(
name|radius
operator|*
literal|2
operator|+
literal|2
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|radius
operator|*
literal|2
operator|+
literal|2
argument_list|)
argument_list|,
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
expr_stmt|;
name|cache
operator|->
name|fill
argument_list|(
literal|0x00000000
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
name|cache
argument_list|)
decl_stmt|;
name|p
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|HighQualityAntialiasing
argument_list|)
expr_stmt|;
name|QPen
name|pen
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
decl_stmt|;
name|pen
operator|.
name|setWidth
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|pen
argument_list|)
expr_stmt|;
name|p
operator|.
name|setBrush
argument_list|(
name|brush
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawEllipse
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|int
argument_list|(
literal|2
operator|*
name|radius
argument_list|)
argument_list|,
name|int
argument_list|(
literal|2
operator|*
name|radius
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_destructor
DECL|function|~Bubble
name|Bubble
operator|::
name|~
name|Bubble
parameter_list|()
block|{
if|if
condition|(
name|cache
condition|)
operator|delete
name|cache
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|updateBrush
name|void
name|Bubble
operator|::
name|updateBrush
parameter_list|()
block|{
name|QRadialGradient
name|gradient
argument_list|(
name|QPointF
argument_list|(
name|radius
argument_list|,
name|radius
argument_list|)
argument_list|,
name|radius
argument_list|,
name|QPointF
argument_list|(
name|radius
operator|*
literal|0.5
argument_list|,
name|radius
operator|*
literal|0.5
argument_list|)
argument_list|)
decl_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|QColor
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0.25
argument_list|,
name|innerColor
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|outerColor
argument_list|)
expr_stmt|;
name|brush
operator|=
name|QBrush
argument_list|(
name|gradient
argument_list|)
expr_stmt|;
name|updateCache
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|drawBubble
name|void
name|Bubble
operator|::
name|drawBubble
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|)
block|{
name|painter
operator|->
name|save
argument_list|()
expr_stmt|;
name|painter
operator|->
name|translate
argument_list|(
name|position
operator|.
name|x
argument_list|()
operator|-
name|radius
argument_list|,
name|position
operator|.
name|y
argument_list|()
operator|-
name|radius
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setOpacity
argument_list|(
literal|0.8
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
operator|*
name|cache
argument_list|)
expr_stmt|;
name|painter
operator|->
name|restore
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|randomColor
name|QColor
name|Bubble
operator|::
name|randomColor
parameter_list|()
block|{
name|int
name|red
init|=
name|int
argument_list|(
literal|185
operator|+
literal|70.0
operator|*
name|qrand
argument_list|()
operator|/
operator|(
name|RAND_MAX
operator|+
literal|1.0
operator|)
argument_list|)
decl_stmt|;
name|int
name|green
init|=
name|int
argument_list|(
literal|185
operator|+
literal|70.0
operator|*
name|qrand
argument_list|()
operator|/
operator|(
name|RAND_MAX
operator|+
literal|1.0
operator|)
argument_list|)
decl_stmt|;
name|int
name|blue
init|=
name|int
argument_list|(
literal|205
operator|+
literal|50.0
operator|*
name|qrand
argument_list|()
operator|/
operator|(
name|RAND_MAX
operator|+
literal|1.0
operator|)
argument_list|)
decl_stmt|;
name|int
name|alpha
init|=
name|int
argument_list|(
literal|91
operator|+
literal|100.0
operator|*
name|qrand
argument_list|()
operator|/
operator|(
name|RAND_MAX
operator|+
literal|1.0
operator|)
argument_list|)
decl_stmt|;
return|return
name|QColor
argument_list|(
name|red
argument_list|,
name|green
argument_list|,
name|blue
argument_list|,
name|alpha
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|move
name|void
name|Bubble
operator|::
name|move
parameter_list|(
specifier|const
name|QRect
modifier|&
name|bbox
parameter_list|)
block|{
name|position
operator|+=
name|vel
expr_stmt|;
name|qreal
name|leftOverflow
init|=
name|position
operator|.
name|x
argument_list|()
operator|-
name|radius
operator|-
name|bbox
operator|.
name|left
argument_list|()
decl_stmt|;
name|qreal
name|rightOverflow
init|=
name|position
operator|.
name|x
argument_list|()
operator|+
name|radius
operator|-
name|bbox
operator|.
name|right
argument_list|()
decl_stmt|;
name|qreal
name|topOverflow
init|=
name|position
operator|.
name|y
argument_list|()
operator|-
name|radius
operator|-
name|bbox
operator|.
name|top
argument_list|()
decl_stmt|;
name|qreal
name|bottomOverflow
init|=
name|position
operator|.
name|y
argument_list|()
operator|+
name|radius
operator|-
name|bbox
operator|.
name|bottom
argument_list|()
decl_stmt|;
if|if
condition|(
name|leftOverflow
operator|<
literal|0.0
condition|)
block|{
name|position
operator|.
name|setX
argument_list|(
name|position
operator|.
name|x
argument_list|()
operator|-
literal|2
operator|*
name|leftOverflow
argument_list|)
expr_stmt|;
name|vel
operator|.
name|setX
argument_list|(
operator|-
name|vel
operator|.
name|x
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|rightOverflow
operator|>
literal|0.0
condition|)
block|{
name|position
operator|.
name|setX
argument_list|(
name|position
operator|.
name|x
argument_list|()
operator|-
literal|2
operator|*
name|rightOverflow
argument_list|)
expr_stmt|;
name|vel
operator|.
name|setX
argument_list|(
operator|-
name|vel
operator|.
name|x
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|topOverflow
operator|<
literal|0.0
condition|)
block|{
name|position
operator|.
name|setY
argument_list|(
name|position
operator|.
name|y
argument_list|()
operator|-
literal|2
operator|*
name|topOverflow
argument_list|)
expr_stmt|;
name|vel
operator|.
name|setY
argument_list|(
operator|-
name|vel
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|bottomOverflow
operator|>
literal|0.0
condition|)
block|{
name|position
operator|.
name|setY
argument_list|(
name|position
operator|.
name|y
argument_list|()
operator|-
literal|2
operator|*
name|bottomOverflow
argument_list|)
expr_stmt|;
name|vel
operator|.
name|setY
argument_list|(
operator|-
name|vel
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|rect
name|QRectF
name|Bubble
operator|::
name|rect
parameter_list|()
block|{
return|return
name|QRectF
argument_list|(
name|position
operator|.
name|x
argument_list|()
operator|-
name|radius
argument_list|,
name|position
operator|.
name|y
argument_list|()
operator|-
name|radius
argument_list|,
literal|2
operator|*
name|radius
argument_list|,
literal|2
operator|*
name|radius
argument_list|)
return|;
block|}
end_function
end_unit
