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
file|<math.h>
end_include
begin_include
include|#
directive|include
file|"tabletcanvas.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|TabletCanvas
name|TabletCanvas
operator|::
name|TabletCanvas
parameter_list|()
block|{
name|resize
argument_list|(
literal|500
argument_list|,
literal|500
argument_list|)
expr_stmt|;
name|myBrush
operator|=
name|QBrush
argument_list|()
expr_stmt|;
name|myPen
operator|=
name|QPen
argument_list|()
expr_stmt|;
name|initPixmap
argument_list|()
expr_stmt|;
name|setAutoFillBackground
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|deviceDown
operator|=
literal|false
expr_stmt|;
name|myColor
operator|=
name|Qt
operator|::
name|red
expr_stmt|;
name|myTabletDevice
operator|=
name|QTabletEvent
operator|::
name|Stylus
expr_stmt|;
name|alphaChannelType
operator|=
name|NoAlpha
expr_stmt|;
name|colorSaturationType
operator|=
name|NoSaturation
expr_stmt|;
name|lineWidthType
operator|=
name|LineWidthPressure
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|initPixmap
name|void
name|TabletCanvas
operator|::
name|initPixmap
parameter_list|()
block|{
name|QPixmap
name|newPixmap
init|=
name|QPixmap
argument_list|(
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|newPixmap
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
name|newPixmap
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|pixmap
operator|.
name|isNull
argument_list|()
condition|)
name|painter
operator|.
name|drawPixmap
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
name|pixmap
operator|=
name|newPixmap
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|saveImage
name|bool
name|TabletCanvas
operator|::
name|saveImage
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
block|{
return|return
name|pixmap
operator|.
name|save
argument_list|(
name|file
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
DECL|function|loadImage
name|bool
name|TabletCanvas
operator|::
name|loadImage
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
block|{
name|bool
name|success
init|=
name|pixmap
operator|.
name|load
argument_list|(
name|file
argument_list|)
decl_stmt|;
if|if
condition|(
name|success
condition|)
block|{
name|update
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
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
DECL|function|tabletEvent
name|void
name|TabletCanvas
operator|::
name|tabletEvent
parameter_list|(
name|QTabletEvent
modifier|*
name|event
parameter_list|)
block|{
switch|switch
condition|(
name|event
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|TabletPress
case|:
if|if
condition|(
operator|!
name|deviceDown
condition|)
block|{
name|deviceDown
operator|=
literal|true
expr_stmt|;
name|polyLine
index|[
literal|0
index|]
operator|=
name|polyLine
index|[
literal|1
index|]
operator|=
name|polyLine
index|[
literal|2
index|]
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
name|QEvent
operator|::
name|TabletRelease
case|:
if|if
condition|(
name|deviceDown
condition|)
name|deviceDown
operator|=
literal|false
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|TabletMove
case|:
name|polyLine
index|[
literal|2
index|]
operator|=
name|polyLine
index|[
literal|1
index|]
expr_stmt|;
name|polyLine
index|[
literal|1
index|]
operator|=
name|polyLine
index|[
literal|0
index|]
expr_stmt|;
name|polyLine
index|[
literal|0
index|]
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
if|if
condition|(
name|deviceDown
condition|)
block|{
name|updateBrush
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|pixmap
argument_list|)
decl_stmt|;
name|paintPixmap
argument_list|(
name|painter
argument_list|,
name|event
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
break|break;
block|}
name|update
argument_list|()
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
DECL|function|paintEvent
name|void
name|TabletCanvas
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|painter
operator|.
name|drawPixmap
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|pixmap
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
DECL|function|paintPixmap
name|void
name|TabletCanvas
operator|::
name|paintPixmap
parameter_list|(
name|QPainter
modifier|&
name|painter
parameter_list|,
name|QTabletEvent
modifier|*
name|event
parameter_list|)
block|{
name|QPoint
name|brushAdjust
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|myTabletDevice
condition|)
block|{
case|case
name|QTabletEvent
operator|::
name|Airbrush
case|:
name|myBrush
operator|.
name|setColor
argument_list|(
name|myColor
argument_list|)
expr_stmt|;
name|myBrush
operator|.
name|setStyle
argument_list|(
name|brushPattern
argument_list|(
name|event
operator|->
name|pressure
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setBrush
argument_list|(
name|myBrush
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|3
condition|;
operator|++
name|i
control|)
block|{
name|painter
operator|.
name|drawEllipse
argument_list|(
name|QRect
argument_list|(
name|polyLine
index|[
name|i
index|]
operator|-
name|brushAdjust
argument_list|,
name|polyLine
index|[
name|i
index|]
operator|+
name|brushAdjust
argument_list|)
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|QTabletEvent
operator|::
name|Puck
case|:
case|case
name|QTabletEvent
operator|::
name|FourDMouse
case|:
case|case
name|QTabletEvent
operator|::
name|RotationStylus
case|:
block|{
specifier|const
name|QString
name|error
argument_list|(
name|tr
argument_list|(
literal|"This input device is not supported by the example."
argument_list|)
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_STATUSTIP
name|QStatusTipEvent
name|status
argument_list|(
name|error
argument_list|)
decl_stmt|;
name|QApplication
operator|::
name|sendEvent
argument_list|(
name|this
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
else|#
directive|else
name|qWarning
argument_list|()
operator|<<
name|error
expr_stmt|;
endif|#
directive|endif
block|}
break|break;
default|default:
block|{
specifier|const
name|QString
name|error
argument_list|(
name|tr
argument_list|(
literal|"Unknown tablet device - treating as stylus"
argument_list|)
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_STATUSTIP
name|QStatusTipEvent
name|status
argument_list|(
name|error
argument_list|)
decl_stmt|;
name|QApplication
operator|::
name|sendEvent
argument_list|(
name|this
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
else|#
directive|else
name|qWarning
argument_list|()
operator|<<
name|error
expr_stmt|;
endif|#
directive|endif
block|}
comment|// FALL-THROUGH
case|case
name|QTabletEvent
operator|::
name|Stylus
case|:
name|painter
operator|.
name|setBrush
argument_list|(
name|myBrush
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|myPen
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawLine
argument_list|(
name|polyLine
index|[
literal|1
index|]
argument_list|,
name|event
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|brushPattern
name|Qt
operator|::
name|BrushStyle
name|TabletCanvas
operator|::
name|brushPattern
parameter_list|(
name|qreal
name|value
parameter_list|)
block|{
name|int
name|pattern
init|=
name|int
argument_list|(
operator|(
name|value
operator|)
operator|*
literal|100.0
argument_list|)
operator|%
literal|7
decl_stmt|;
switch|switch
condition|(
name|pattern
condition|)
block|{
case|case
literal|0
case|:
return|return
name|Qt
operator|::
name|SolidPattern
return|;
case|case
literal|1
case|:
return|return
name|Qt
operator|::
name|Dense1Pattern
return|;
case|case
literal|2
case|:
return|return
name|Qt
operator|::
name|Dense2Pattern
return|;
case|case
literal|3
case|:
return|return
name|Qt
operator|::
name|Dense3Pattern
return|;
case|case
literal|4
case|:
return|return
name|Qt
operator|::
name|Dense4Pattern
return|;
case|case
literal|5
case|:
return|return
name|Qt
operator|::
name|Dense5Pattern
return|;
case|case
literal|6
case|:
return|return
name|Qt
operator|::
name|Dense6Pattern
return|;
default|default:
return|return
name|Qt
operator|::
name|Dense7Pattern
return|;
block|}
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|updateBrush
name|void
name|TabletCanvas
operator|::
name|updateBrush
parameter_list|(
name|QTabletEvent
modifier|*
name|event
parameter_list|)
block|{
name|int
name|hue
decl_stmt|,
name|saturation
decl_stmt|,
name|value
decl_stmt|,
name|alpha
decl_stmt|;
name|myColor
operator|.
name|getHsv
argument_list|(
operator|&
name|hue
argument_list|,
operator|&
name|saturation
argument_list|,
operator|&
name|value
argument_list|,
operator|&
name|alpha
argument_list|)
expr_stmt|;
name|int
name|vValue
init|=
name|int
argument_list|(
operator|(
operator|(
name|event
operator|->
name|yTilt
argument_list|()
operator|+
literal|60.0
operator|)
operator|/
literal|120.0
operator|)
operator|*
literal|255
argument_list|)
decl_stmt|;
name|int
name|hValue
init|=
name|int
argument_list|(
operator|(
operator|(
name|event
operator|->
name|xTilt
argument_list|()
operator|+
literal|60.0
operator|)
operator|/
literal|120.0
operator|)
operator|*
literal|255
argument_list|)
decl_stmt|;
comment|//! [7] //! [8]
switch|switch
condition|(
name|alphaChannelType
condition|)
block|{
case|case
name|AlphaPressure
case|:
name|myColor
operator|.
name|setAlpha
argument_list|(
name|int
argument_list|(
name|event
operator|->
name|pressure
argument_list|()
operator|*
literal|255.0
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|AlphaTilt
case|:
name|myColor
operator|.
name|setAlpha
argument_list|(
name|maximum
argument_list|(
name|abs
argument_list|(
name|vValue
operator|-
literal|127
argument_list|)
argument_list|,
name|abs
argument_list|(
name|hValue
operator|-
literal|127
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
break|break;
default|default:
name|myColor
operator|.
name|setAlpha
argument_list|(
literal|255
argument_list|)
expr_stmt|;
block|}
comment|//! [8] //! [9]
switch|switch
condition|(
name|colorSaturationType
condition|)
block|{
case|case
name|SaturationVTilt
case|:
name|myColor
operator|.
name|setHsv
argument_list|(
name|hue
argument_list|,
name|vValue
argument_list|,
name|value
argument_list|,
name|alpha
argument_list|)
expr_stmt|;
break|break;
case|case
name|SaturationHTilt
case|:
name|myColor
operator|.
name|setHsv
argument_list|(
name|hue
argument_list|,
name|hValue
argument_list|,
name|value
argument_list|,
name|alpha
argument_list|)
expr_stmt|;
break|break;
case|case
name|SaturationPressure
case|:
name|myColor
operator|.
name|setHsv
argument_list|(
name|hue
argument_list|,
name|int
argument_list|(
name|event
operator|->
name|pressure
argument_list|()
operator|*
literal|255.0
argument_list|)
argument_list|,
name|value
argument_list|,
name|alpha
argument_list|)
expr_stmt|;
break|break;
default|default:
empty_stmt|;
block|}
comment|//! [9] //! [10]
switch|switch
condition|(
name|lineWidthType
condition|)
block|{
case|case
name|LineWidthPressure
case|:
name|myPen
operator|.
name|setWidthF
argument_list|(
name|event
operator|->
name|pressure
argument_list|()
operator|*
literal|10
operator|+
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
name|LineWidthTilt
case|:
name|myPen
operator|.
name|setWidthF
argument_list|(
name|maximum
argument_list|(
name|abs
argument_list|(
name|vValue
operator|-
literal|127
argument_list|)
argument_list|,
name|abs
argument_list|(
name|hValue
operator|-
literal|127
argument_list|)
argument_list|)
operator|/
literal|12
argument_list|)
expr_stmt|;
break|break;
default|default:
name|myPen
operator|.
name|setWidthF
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|//! [10] //! [11]
if|if
condition|(
name|event
operator|->
name|pointerType
argument_list|()
operator|==
name|QTabletEvent
operator|::
name|Eraser
condition|)
block|{
name|myBrush
operator|.
name|setColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|myPen
operator|.
name|setColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|myPen
operator|.
name|setWidthF
argument_list|(
name|event
operator|->
name|pressure
argument_list|()
operator|*
literal|10
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|myBrush
operator|.
name|setColor
argument_list|(
name|myColor
argument_list|)
expr_stmt|;
name|myPen
operator|.
name|setColor
argument_list|(
name|myColor
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [11]
end_comment
begin_function
DECL|function|resizeEvent
name|void
name|TabletCanvas
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
block|{
name|initPixmap
argument_list|()
expr_stmt|;
name|polyLine
index|[
literal|0
index|]
operator|=
name|polyLine
index|[
literal|1
index|]
operator|=
name|polyLine
index|[
literal|2
index|]
operator|=
name|QPoint
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
