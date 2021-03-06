begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mouse.h"
end_include
begin_include
include|#
directive|include
file|<QGraphicsScene>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QStyleOption>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_decl_stmt
DECL|variable|Pi
specifier|static
specifier|const
name|double
name|Pi
init|=
literal|3.14159265358979323846264338327950288419717
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|TwoPi
specifier|static
name|double
name|TwoPi
init|=
literal|2.0
operator|*
name|Pi
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|normalizeAngle
specifier|static
name|qreal
name|normalizeAngle
parameter_list|(
name|qreal
name|angle
parameter_list|)
block|{
while|while
condition|(
name|angle
operator|<
literal|0
condition|)
name|angle
operator|+=
name|TwoPi
expr_stmt|;
while|while
condition|(
name|angle
operator|>
name|TwoPi
condition|)
name|angle
operator|-=
name|TwoPi
expr_stmt|;
return|return
name|angle
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|Mouse
name|Mouse
operator|::
name|Mouse
parameter_list|()
member_init_list|:
name|angle
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|speed
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mouseEyeDirection
argument_list|(
literal|0
argument_list|)
member_init_list|,
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
name|setRotation
argument_list|(
name|qrand
argument_list|()
operator|%
operator|(
literal|360
operator|*
literal|16
operator|)
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
name|Mouse
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
name|qreal
name|adjust
init|=
literal|0.5
decl_stmt|;
return|return
name|QRectF
argument_list|(
operator|-
literal|18
operator|-
name|adjust
argument_list|,
operator|-
literal|22
operator|-
name|adjust
argument_list|,
literal|36
operator|+
name|adjust
argument_list|,
literal|60
operator|+
name|adjust
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
DECL|function|shape
name|QPainterPath
name|Mouse
operator|::
name|shape
parameter_list|()
specifier|const
block|{
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|addRect
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|20
argument_list|,
literal|20
argument_list|,
literal|40
argument_list|)
expr_stmt|;
return|return
name|path
return|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|paint
name|void
name|Mouse
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
parameter_list|,
name|QWidget
modifier|*
parameter_list|)
block|{
comment|// Body
name|painter
operator|->
name|setBrush
argument_list|(
name|color
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|20
argument_list|,
literal|20
argument_list|,
literal|40
argument_list|)
expr_stmt|;
comment|// Eyes
name|painter
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|17
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
literal|2
argument_list|,
operator|-
literal|17
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
expr_stmt|;
comment|// Nose
name|painter
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
name|QRectF
argument_list|(
operator|-
literal|2
argument_list|,
operator|-
literal|22
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|)
argument_list|)
expr_stmt|;
comment|// Pupils
name|painter
operator|->
name|drawEllipse
argument_list|(
name|QRectF
argument_list|(
operator|-
literal|8.0
operator|+
name|mouseEyeDirection
argument_list|,
operator|-
literal|17
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
name|QRectF
argument_list|(
literal|4.0
operator|+
name|mouseEyeDirection
argument_list|,
operator|-
literal|17
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|)
argument_list|)
expr_stmt|;
comment|// Ears
name|painter
operator|->
name|setBrush
argument_list|(
name|scene
argument_list|()
operator|->
name|collidingItems
argument_list|(
name|this
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|?
name|Qt
operator|::
name|darkYellow
else|:
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
operator|-
literal|17
argument_list|,
operator|-
literal|12
argument_list|,
literal|16
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
literal|1
argument_list|,
operator|-
literal|12
argument_list|,
literal|16
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|// Tail
name|QPainterPath
name|path
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|20
argument_list|)
argument_list|)
decl_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|5
argument_list|,
literal|22
argument_list|,
operator|-
literal|5
argument_list|,
literal|22
argument_list|,
literal|0
argument_list|,
literal|25
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|5
argument_list|,
literal|27
argument_list|,
literal|5
argument_list|,
literal|32
argument_list|,
literal|0
argument_list|,
literal|30
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|5
argument_list|,
literal|32
argument_list|,
operator|-
literal|5
argument_list|,
literal|42
argument_list|,
literal|0
argument_list|,
literal|35
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|advance
name|void
name|Mouse
operator|::
name|advance
parameter_list|(
name|int
name|step
parameter_list|)
block|{
if|if
condition|(
operator|!
name|step
condition|)
return|return;
comment|//! [4]
comment|// Don't move too far away
comment|//! [5]
name|QLineF
name|lineToCenter
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|mapFromScene
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|lineToCenter
operator|.
name|length
argument_list|()
operator|>
literal|150
condition|)
block|{
name|qreal
name|angleToCenter
init|=
operator|::
name|acos
argument_list|(
name|lineToCenter
operator|.
name|dx
argument_list|()
operator|/
name|lineToCenter
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|lineToCenter
operator|.
name|dy
argument_list|()
operator|<
literal|0
condition|)
name|angleToCenter
operator|=
name|TwoPi
operator|-
name|angleToCenter
expr_stmt|;
name|angleToCenter
operator|=
name|normalizeAngle
argument_list|(
operator|(
name|Pi
operator|-
name|angleToCenter
operator|)
operator|+
name|Pi
operator|/
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|angleToCenter
argument_list|<
name|Pi
operator|&&
name|angleToCenter
argument_list|>
name|Pi
operator|/
literal|4
condition|)
block|{
comment|// Rotate left
name|angle
operator|+=
operator|(
name|angle
operator|<
operator|-
name|Pi
operator|/
literal|2
operator|)
condition|?
literal|0.25
else|:
operator|-
literal|0.25
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|angleToCenter
operator|>=
name|Pi
operator|&&
name|angleToCenter
operator|<
operator|(
name|Pi
operator|+
name|Pi
operator|/
literal|2
operator|+
name|Pi
operator|/
literal|4
operator|)
condition|)
block|{
comment|// Rotate right
name|angle
operator|+=
operator|(
name|angle
operator|<
name|Pi
operator|/
literal|2
operator|)
condition|?
literal|0.25
else|:
operator|-
literal|0.25
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
operator|::
name|sin
argument_list|(
name|angle
argument_list|)
operator|<
literal|0
condition|)
block|{
name|angle
operator|+=
literal|0.25
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|::
name|sin
argument_list|(
name|angle
argument_list|)
operator|>
literal|0
condition|)
block|{
name|angle
operator|-=
literal|0.25
expr_stmt|;
comment|//! [5] //! [6]
block|}
comment|//! [6]
comment|// Try not to crash with any other mice
comment|//! [7]
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
name|dangerMice
init|=
name|scene
argument_list|()
operator|->
name|items
argument_list|(
name|QPolygonF
argument_list|()
operator|<<
name|mapToScene
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|mapToScene
argument_list|(
operator|-
literal|30
argument_list|,
operator|-
literal|50
argument_list|)
operator|<<
name|mapToScene
argument_list|(
literal|30
argument_list|,
operator|-
literal|50
argument_list|)
argument_list|)
decl_stmt|;
foreach|foreach
control|(
name|QGraphicsItem
modifier|*
name|item
decl|,
name|dangerMice
control|)
block|{
if|if
condition|(
name|item
operator|==
name|this
condition|)
continue|continue;
name|QLineF
name|lineToMouse
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|mapFromItem
argument_list|(
name|item
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
decl_stmt|;
name|qreal
name|angleToMouse
init|=
operator|::
name|acos
argument_list|(
name|lineToMouse
operator|.
name|dx
argument_list|()
operator|/
name|lineToMouse
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|lineToMouse
operator|.
name|dy
argument_list|()
operator|<
literal|0
condition|)
name|angleToMouse
operator|=
name|TwoPi
operator|-
name|angleToMouse
expr_stmt|;
name|angleToMouse
operator|=
name|normalizeAngle
argument_list|(
operator|(
name|Pi
operator|-
name|angleToMouse
operator|)
operator|+
name|Pi
operator|/
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|angleToMouse
operator|>=
literal|0
operator|&&
name|angleToMouse
operator|<
name|Pi
operator|/
literal|2
condition|)
block|{
comment|// Rotate right
name|angle
operator|+=
literal|0.5
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|angleToMouse
operator|<=
name|TwoPi
operator|&&
name|angleToMouse
operator|>
operator|(
name|TwoPi
operator|-
name|Pi
operator|/
literal|2
operator|)
condition|)
block|{
comment|// Rotate left
name|angle
operator|-=
literal|0.5
expr_stmt|;
comment|//! [7] //! [8]
block|}
comment|//! [8] //! [9]
block|}
comment|//! [9]
comment|// Add some random movement
comment|//! [10]
if|if
condition|(
name|dangerMice
operator|.
name|size
argument_list|()
operator|>
literal|1
operator|&&
operator|(
name|qrand
argument_list|()
operator|%
literal|10
operator|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|qrand
argument_list|()
operator|%
literal|1
condition|)
name|angle
operator|+=
operator|(
name|qrand
argument_list|()
operator|%
literal|100
operator|)
operator|/
literal|500.0
expr_stmt|;
else|else
name|angle
operator|-=
operator|(
name|qrand
argument_list|()
operator|%
literal|100
operator|)
operator|/
literal|500.0
expr_stmt|;
block|}
comment|//! [10]
comment|//! [11]
name|speed
operator|+=
operator|(
operator|-
literal|50
operator|+
name|qrand
argument_list|()
operator|%
literal|100
operator|)
operator|/
literal|100.0
expr_stmt|;
name|qreal
name|dx
init|=
operator|::
name|sin
argument_list|(
name|angle
argument_list|)
operator|*
literal|10
decl_stmt|;
name|mouseEyeDirection
operator|=
operator|(
name|qAbs
argument_list|(
name|dx
operator|/
literal|5
argument_list|)
operator|<
literal|1
operator|)
condition|?
literal|0
else|:
name|dx
operator|/
literal|5
expr_stmt|;
name|setRotation
argument_list|(
name|rotation
argument_list|()
operator|+
name|dx
argument_list|)
expr_stmt|;
name|setPos
argument_list|(
name|mapToParent
argument_list|(
literal|0
argument_list|,
operator|-
operator|(
literal|3
operator|+
name|sin
argument_list|(
name|speed
argument_list|)
operator|*
literal|3
operator|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [11]
end_comment
end_unit
