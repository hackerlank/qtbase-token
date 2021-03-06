begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"tetrixboard.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|TetrixBoard
name|TetrixBoard
operator|::
name|TetrixBoard
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QFrame
argument_list|(
name|parent
argument_list|)
block|{
name|setFrameStyle
argument_list|(
name|QFrame
operator|::
name|Panel
operator||
name|QFrame
operator|::
name|Sunken
argument_list|)
expr_stmt|;
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|StrongFocus
argument_list|)
expr_stmt|;
name|isStarted
operator|=
literal|false
expr_stmt|;
name|isPaused
operator|=
literal|false
expr_stmt|;
name|clearBoard
argument_list|()
expr_stmt|;
name|nextPiece
operator|.
name|setRandomShape
argument_list|()
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
DECL|function|setNextPieceLabel
name|void
name|TetrixBoard
operator|::
name|setNextPieceLabel
parameter_list|(
name|QLabel
modifier|*
name|label
parameter_list|)
block|{
name|nextPieceLabel
operator|=
name|label
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|TetrixBoard
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
name|BoardWidth
operator|*
literal|15
operator|+
name|frameWidth
argument_list|()
operator|*
literal|2
argument_list|,
name|BoardHeight
operator|*
literal|15
operator|+
name|frameWidth
argument_list|()
operator|*
literal|2
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|minimumSizeHint
name|QSize
name|TetrixBoard
operator|::
name|minimumSizeHint
parameter_list|()
specifier|const
comment|//! [2] //! [3]
block|{
return|return
name|QSize
argument_list|(
name|BoardWidth
operator|*
literal|5
operator|+
name|frameWidth
argument_list|()
operator|*
literal|2
argument_list|,
name|BoardHeight
operator|*
literal|5
operator|+
name|frameWidth
argument_list|()
operator|*
literal|2
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
DECL|function|start
name|void
name|TetrixBoard
operator|::
name|start
parameter_list|()
block|{
if|if
condition|(
name|isPaused
condition|)
return|return;
name|isStarted
operator|=
literal|true
expr_stmt|;
name|isWaitingAfterLine
operator|=
literal|false
expr_stmt|;
name|numLinesRemoved
operator|=
literal|0
expr_stmt|;
name|numPiecesDropped
operator|=
literal|0
expr_stmt|;
name|score
operator|=
literal|0
expr_stmt|;
name|level
operator|=
literal|1
expr_stmt|;
name|clearBoard
argument_list|()
expr_stmt|;
emit|emit
name|linesRemovedChanged
argument_list|(
name|numLinesRemoved
argument_list|)
emit|;
emit|emit
name|scoreChanged
argument_list|(
name|score
argument_list|)
emit|;
emit|emit
name|levelChanged
argument_list|(
name|level
argument_list|)
emit|;
name|newPiece
argument_list|()
expr_stmt|;
name|timer
operator|.
name|start
argument_list|(
name|timeoutTime
argument_list|()
argument_list|,
name|this
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
DECL|function|pause
name|void
name|TetrixBoard
operator|::
name|pause
parameter_list|()
block|{
if|if
condition|(
operator|!
name|isStarted
condition|)
return|return;
name|isPaused
operator|=
operator|!
name|isPaused
expr_stmt|;
if|if
condition|(
name|isPaused
condition|)
block|{
name|timer
operator|.
name|stop
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|timer
operator|.
name|start
argument_list|(
name|timeoutTime
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
name|update
argument_list|()
expr_stmt|;
comment|//! [5] //! [6]
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|paintEvent
name|void
name|TetrixBoard
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|QFrame
operator|::
name|paintEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QRect
name|rect
init|=
name|contentsRect
argument_list|()
decl_stmt|;
comment|//! [7]
if|if
condition|(
name|isPaused
condition|)
block|{
name|painter
operator|.
name|drawText
argument_list|(
name|rect
argument_list|,
name|Qt
operator|::
name|AlignCenter
argument_list|,
name|tr
argument_list|(
literal|"Pause"
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
comment|//! [8]
name|int
name|boardTop
init|=
name|rect
operator|.
name|bottom
argument_list|()
operator|-
name|BoardHeight
operator|*
name|squareHeight
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|BoardHeight
condition|;
operator|++
name|i
control|)
block|{
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|BoardWidth
condition|;
operator|++
name|j
control|)
block|{
name|TetrixShape
name|shape
init|=
name|shapeAt
argument_list|(
name|j
argument_list|,
name|BoardHeight
operator|-
name|i
operator|-
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|shape
operator|!=
name|NoShape
condition|)
name|drawSquare
argument_list|(
name|painter
argument_list|,
name|rect
operator|.
name|left
argument_list|()
operator|+
name|j
operator|*
name|squareWidth
argument_list|()
argument_list|,
name|boardTop
operator|+
name|i
operator|*
name|squareHeight
argument_list|()
argument_list|,
name|shape
argument_list|)
expr_stmt|;
block|}
comment|//! [8] //! [9]
block|}
comment|//! [9]
comment|//! [10]
if|if
condition|(
name|curPiece
operator|.
name|shape
argument_list|()
operator|!=
name|NoShape
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
operator|++
name|i
control|)
block|{
name|int
name|x
init|=
name|curX
operator|+
name|curPiece
operator|.
name|x
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|int
name|y
init|=
name|curY
operator|-
name|curPiece
operator|.
name|y
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|drawSquare
argument_list|(
name|painter
argument_list|,
name|rect
operator|.
name|left
argument_list|()
operator|+
name|x
operator|*
name|squareWidth
argument_list|()
argument_list|,
name|boardTop
operator|+
operator|(
name|BoardHeight
operator|-
name|y
operator|-
literal|1
operator|)
operator|*
name|squareHeight
argument_list|()
argument_list|,
name|curPiece
operator|.
name|shape
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|//! [10] //! [11]
block|}
comment|//! [11] //! [12]
block|}
end_function
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_function
DECL|function|keyPressEvent
name|void
name|TetrixBoard
operator|::
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
operator|!
name|isStarted
operator|||
name|isPaused
operator|||
name|curPiece
operator|.
name|shape
argument_list|()
operator|==
name|NoShape
condition|)
block|{
name|QFrame
operator|::
name|keyPressEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
return|return;
block|}
comment|//! [13]
comment|//! [14]
switch|switch
condition|(
name|event
operator|->
name|key
argument_list|()
condition|)
block|{
case|case
name|Qt
operator|::
name|Key_Left
case|:
name|tryMove
argument_list|(
name|curPiece
argument_list|,
name|curX
operator|-
literal|1
argument_list|,
name|curY
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Right
case|:
name|tryMove
argument_list|(
name|curPiece
argument_list|,
name|curX
operator|+
literal|1
argument_list|,
name|curY
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Down
case|:
name|tryMove
argument_list|(
name|curPiece
operator|.
name|rotatedRight
argument_list|()
argument_list|,
name|curX
argument_list|,
name|curY
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Up
case|:
name|tryMove
argument_list|(
name|curPiece
operator|.
name|rotatedLeft
argument_list|()
argument_list|,
name|curX
argument_list|,
name|curY
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Space
case|:
name|dropDown
argument_list|()
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_D
case|:
name|oneLineDown
argument_list|()
expr_stmt|;
break|break;
default|default:
name|QFrame
operator|::
name|keyPressEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
comment|//! [14]
block|}
end_function
begin_comment
comment|//! [15]
end_comment
begin_function
DECL|function|timerEvent
name|void
name|TetrixBoard
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|timerId
argument_list|()
operator|==
name|timer
operator|.
name|timerId
argument_list|()
condition|)
block|{
if|if
condition|(
name|isWaitingAfterLine
condition|)
block|{
name|isWaitingAfterLine
operator|=
literal|false
expr_stmt|;
name|newPiece
argument_list|()
expr_stmt|;
name|timer
operator|.
name|start
argument_list|(
name|timeoutTime
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|oneLineDown
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|QFrame
operator|::
name|timerEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
comment|//! [15] //! [16]
block|}
comment|//! [16] //! [17]
block|}
end_function
begin_comment
comment|//! [17]
end_comment
begin_comment
comment|//! [18]
end_comment
begin_function
DECL|function|clearBoard
name|void
name|TetrixBoard
operator|::
name|clearBoard
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|BoardHeight
operator|*
name|BoardWidth
condition|;
operator|++
name|i
control|)
name|board
index|[
name|i
index|]
operator|=
name|NoShape
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [18]
end_comment
begin_comment
comment|//! [19]
end_comment
begin_function
DECL|function|dropDown
name|void
name|TetrixBoard
operator|::
name|dropDown
parameter_list|()
block|{
name|int
name|dropHeight
init|=
literal|0
decl_stmt|;
name|int
name|newY
init|=
name|curY
decl_stmt|;
while|while
condition|(
name|newY
operator|>
literal|0
condition|)
block|{
if|if
condition|(
operator|!
name|tryMove
argument_list|(
name|curPiece
argument_list|,
name|curX
argument_list|,
name|newY
operator|-
literal|1
argument_list|)
condition|)
break|break;
operator|--
name|newY
expr_stmt|;
operator|++
name|dropHeight
expr_stmt|;
block|}
name|pieceDropped
argument_list|(
name|dropHeight
argument_list|)
expr_stmt|;
comment|//! [19] //! [20]
block|}
end_function
begin_comment
comment|//! [20]
end_comment
begin_comment
comment|//! [21]
end_comment
begin_function
DECL|function|oneLineDown
name|void
name|TetrixBoard
operator|::
name|oneLineDown
parameter_list|()
block|{
if|if
condition|(
operator|!
name|tryMove
argument_list|(
name|curPiece
argument_list|,
name|curX
argument_list|,
name|curY
operator|-
literal|1
argument_list|)
condition|)
name|pieceDropped
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [21]
end_comment
begin_comment
comment|//! [22]
end_comment
begin_function
DECL|function|pieceDropped
name|void
name|TetrixBoard
operator|::
name|pieceDropped
parameter_list|(
name|int
name|dropHeight
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
operator|++
name|i
control|)
block|{
name|int
name|x
init|=
name|curX
operator|+
name|curPiece
operator|.
name|x
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|int
name|y
init|=
name|curY
operator|-
name|curPiece
operator|.
name|y
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|shapeAt
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
operator|=
name|curPiece
operator|.
name|shape
argument_list|()
expr_stmt|;
block|}
operator|++
name|numPiecesDropped
expr_stmt|;
if|if
condition|(
name|numPiecesDropped
operator|%
literal|25
operator|==
literal|0
condition|)
block|{
operator|++
name|level
expr_stmt|;
name|timer
operator|.
name|start
argument_list|(
name|timeoutTime
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
emit|emit
name|levelChanged
argument_list|(
name|level
argument_list|)
emit|;
block|}
name|score
operator|+=
name|dropHeight
operator|+
literal|7
expr_stmt|;
emit|emit
name|scoreChanged
argument_list|(
name|score
argument_list|)
emit|;
name|removeFullLines
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|isWaitingAfterLine
condition|)
name|newPiece
argument_list|()
expr_stmt|;
comment|//! [22] //! [23]
block|}
end_function
begin_comment
comment|//! [23]
end_comment
begin_comment
comment|//! [24]
end_comment
begin_function
DECL|function|removeFullLines
name|void
name|TetrixBoard
operator|::
name|removeFullLines
parameter_list|()
block|{
name|int
name|numFullLines
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|BoardHeight
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
name|bool
name|lineIsFull
init|=
literal|true
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|BoardWidth
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
name|shapeAt
argument_list|(
name|j
argument_list|,
name|i
argument_list|)
operator|==
name|NoShape
condition|)
block|{
name|lineIsFull
operator|=
literal|false
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|lineIsFull
condition|)
block|{
comment|//! [24] //! [25]
operator|++
name|numFullLines
expr_stmt|;
for|for
control|(
name|int
name|k
init|=
name|i
init|;
name|k
operator|<
name|BoardHeight
operator|-
literal|1
condition|;
operator|++
name|k
control|)
block|{
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|BoardWidth
condition|;
operator|++
name|j
control|)
name|shapeAt
argument_list|(
name|j
argument_list|,
name|k
argument_list|)
operator|=
name|shapeAt
argument_list|(
name|j
argument_list|,
name|k
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
comment|//! [25] //! [26]
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|BoardWidth
condition|;
operator|++
name|j
control|)
name|shapeAt
argument_list|(
name|j
argument_list|,
name|BoardHeight
operator|-
literal|1
argument_list|)
operator|=
name|NoShape
expr_stmt|;
block|}
comment|//! [26] //! [27]
block|}
comment|//! [27]
comment|//! [28]
if|if
condition|(
name|numFullLines
operator|>
literal|0
condition|)
block|{
name|numLinesRemoved
operator|+=
name|numFullLines
expr_stmt|;
name|score
operator|+=
literal|10
operator|*
name|numFullLines
expr_stmt|;
emit|emit
name|linesRemovedChanged
argument_list|(
name|numLinesRemoved
argument_list|)
emit|;
emit|emit
name|scoreChanged
argument_list|(
name|score
argument_list|)
emit|;
name|timer
operator|.
name|start
argument_list|(
literal|500
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|isWaitingAfterLine
operator|=
literal|true
expr_stmt|;
name|curPiece
operator|.
name|setShape
argument_list|(
name|NoShape
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
comment|//! [28] //! [29]
block|}
end_function
begin_comment
comment|//! [29]
end_comment
begin_comment
comment|//! [30]
end_comment
begin_function
DECL|function|newPiece
name|void
name|TetrixBoard
operator|::
name|newPiece
parameter_list|()
block|{
name|curPiece
operator|=
name|nextPiece
expr_stmt|;
name|nextPiece
operator|.
name|setRandomShape
argument_list|()
expr_stmt|;
name|showNextPiece
argument_list|()
expr_stmt|;
name|curX
operator|=
name|BoardWidth
operator|/
literal|2
operator|+
literal|1
expr_stmt|;
name|curY
operator|=
name|BoardHeight
operator|-
literal|1
operator|+
name|curPiece
operator|.
name|minY
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|tryMove
argument_list|(
name|curPiece
argument_list|,
name|curX
argument_list|,
name|curY
argument_list|)
condition|)
block|{
name|curPiece
operator|.
name|setShape
argument_list|(
name|NoShape
argument_list|)
expr_stmt|;
name|timer
operator|.
name|stop
argument_list|()
expr_stmt|;
name|isStarted
operator|=
literal|false
expr_stmt|;
block|}
comment|//! [30] //! [31]
block|}
end_function
begin_comment
comment|//! [31]
end_comment
begin_comment
comment|//! [32]
end_comment
begin_function
DECL|function|showNextPiece
name|void
name|TetrixBoard
operator|::
name|showNextPiece
parameter_list|()
block|{
if|if
condition|(
operator|!
name|nextPieceLabel
condition|)
return|return;
name|int
name|dx
init|=
name|nextPiece
operator|.
name|maxX
argument_list|()
operator|-
name|nextPiece
operator|.
name|minX
argument_list|()
operator|+
literal|1
decl_stmt|;
name|int
name|dy
init|=
name|nextPiece
operator|.
name|maxY
argument_list|()
operator|-
name|nextPiece
operator|.
name|minY
argument_list|()
operator|+
literal|1
decl_stmt|;
name|QPixmap
name|pixmap
argument_list|(
name|dx
operator|*
name|squareWidth
argument_list|()
argument_list|,
name|dy
operator|*
name|squareHeight
argument_list|()
argument_list|)
decl_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|pixmap
argument_list|)
decl_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
name|pixmap
operator|.
name|rect
argument_list|()
argument_list|,
name|nextPieceLabel
operator|->
name|palette
argument_list|()
operator|.
name|background
argument_list|()
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
literal|4
condition|;
operator|++
name|i
control|)
block|{
name|int
name|x
init|=
name|nextPiece
operator|.
name|x
argument_list|(
name|i
argument_list|)
operator|-
name|nextPiece
operator|.
name|minX
argument_list|()
decl_stmt|;
name|int
name|y
init|=
name|nextPiece
operator|.
name|y
argument_list|(
name|i
argument_list|)
operator|-
name|nextPiece
operator|.
name|minY
argument_list|()
decl_stmt|;
name|drawSquare
argument_list|(
name|painter
argument_list|,
name|x
operator|*
name|squareWidth
argument_list|()
argument_list|,
name|y
operator|*
name|squareHeight
argument_list|()
argument_list|,
name|nextPiece
operator|.
name|shape
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|nextPieceLabel
operator|->
name|setPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
comment|//! [32] //! [33]
block|}
end_function
begin_comment
comment|//! [33]
end_comment
begin_comment
comment|//! [34]
end_comment
begin_function
DECL|function|tryMove
name|bool
name|TetrixBoard
operator|::
name|tryMove
parameter_list|(
specifier|const
name|TetrixPiece
modifier|&
name|newPiece
parameter_list|,
name|int
name|newX
parameter_list|,
name|int
name|newY
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
operator|++
name|i
control|)
block|{
name|int
name|x
init|=
name|newX
operator|+
name|newPiece
operator|.
name|x
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|int
name|y
init|=
name|newY
operator|-
name|newPiece
operator|.
name|y
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
operator|||
name|x
operator|>=
name|BoardWidth
operator|||
name|y
operator|<
literal|0
operator|||
name|y
operator|>=
name|BoardHeight
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|shapeAt
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
operator|!=
name|NoShape
condition|)
return|return
literal|false
return|;
block|}
comment|//! [34]
comment|//! [35]
name|curPiece
operator|=
name|newPiece
expr_stmt|;
name|curX
operator|=
name|newX
expr_stmt|;
name|curY
operator|=
name|newY
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [35]
end_comment
begin_comment
comment|//! [36]
end_comment
begin_function
DECL|function|drawSquare
name|void
name|TetrixBoard
operator|::
name|drawSquare
parameter_list|(
name|QPainter
modifier|&
name|painter
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|TetrixShape
name|shape
parameter_list|)
block|{
specifier|static
specifier|const
name|QRgb
name|colorTable
index|[
literal|8
index|]
init|=
block|{
literal|0x000000
block|,
literal|0xCC6666
block|,
literal|0x66CC66
block|,
literal|0x6666CC
block|,
literal|0xCCCC66
block|,
literal|0xCC66CC
block|,
literal|0x66CCCC
block|,
literal|0xDAAA00
block|}
decl_stmt|;
name|QColor
name|color
init|=
name|colorTable
index|[
name|int
argument_list|(
name|shape
argument_list|)
index|]
decl_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
name|x
operator|+
literal|1
argument_list|,
name|y
operator|+
literal|1
argument_list|,
name|squareWidth
argument_list|()
operator|-
literal|2
argument_list|,
name|squareHeight
argument_list|()
operator|-
literal|2
argument_list|,
name|color
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|color
operator|.
name|light
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawLine
argument_list|(
name|x
argument_list|,
name|y
operator|+
name|squareHeight
argument_list|()
operator|-
literal|1
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawLine
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|x
operator|+
name|squareWidth
argument_list|()
operator|-
literal|1
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|color
operator|.
name|dark
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawLine
argument_list|(
name|x
operator|+
literal|1
argument_list|,
name|y
operator|+
name|squareHeight
argument_list|()
operator|-
literal|1
argument_list|,
name|x
operator|+
name|squareWidth
argument_list|()
operator|-
literal|1
argument_list|,
name|y
operator|+
name|squareHeight
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawLine
argument_list|(
name|x
operator|+
name|squareWidth
argument_list|()
operator|-
literal|1
argument_list|,
name|y
operator|+
name|squareHeight
argument_list|()
operator|-
literal|1
argument_list|,
name|x
operator|+
name|squareWidth
argument_list|()
operator|-
literal|1
argument_list|,
name|y
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [36]
end_comment
end_unit
