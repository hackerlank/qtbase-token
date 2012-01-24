begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"scribblewidget.h"
end_include
begin_constructor
DECL|function|ScribbleWidget
name|ScribbleWidget
operator|::
name|ScribbleWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|scribbling
operator|=
literal|false
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|resizeEvent
name|void
name|ScribbleWidget
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|e
parameter_list|)
block|{
name|image
operator|=
name|QImage
argument_list|(
name|e
operator|->
name|size
argument_list|()
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
expr_stmt|;
name|image
operator|.
name|fill
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
operator|.
name|rgb
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|ScribbleWidget
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|button
argument_list|()
operator|!=
name|Qt
operator|::
name|LeftButton
condition|)
return|return;
name|lastPoint
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
name|scribbling
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseMoveEvent
name|void
name|ScribbleWidget
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
operator|(
name|event
operator|->
name|buttons
argument_list|()
operator|&
name|Qt
operator|::
name|LeftButton
operator|)
operator|&&
name|scribbling
condition|)
name|drawLineTo
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseReleaseEvent
name|void
name|ScribbleWidget
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
operator|&&
name|scribbling
condition|)
block|{
name|drawLineTo
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|scribbling
operator|=
literal|false
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|ScribbleWidget
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
name|drawImage
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|image
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|drawLineTo
name|void
name|ScribbleWidget
operator|::
name|drawLineTo
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|endPoint
parameter_list|)
block|{
name|QPainter
name|painter
argument_list|(
operator|&
name|image
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|blue
argument_list|,
literal|1
argument_list|,
name|Qt
operator|::
name|SolidLine
argument_list|,
name|Qt
operator|::
name|RoundCap
argument_list|,
name|Qt
operator|::
name|RoundJoin
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawLine
argument_list|(
name|lastPoint
argument_list|,
name|endPoint
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
name|lastPoint
operator|=
name|endPoint
expr_stmt|;
block|}
end_function
end_unit
