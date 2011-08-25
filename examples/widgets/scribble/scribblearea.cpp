begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QPrinter>
end_include
begin_include
include|#
directive|include
file|<QPrintDialog>
end_include
begin_include
include|#
directive|include
file|"scribblearea.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|ScribbleArea
name|ScribbleArea
operator|::
name|ScribbleArea
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
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_StaticContents
argument_list|)
expr_stmt|;
name|modified
operator|=
literal|false
expr_stmt|;
name|scribbling
operator|=
literal|false
expr_stmt|;
name|myPenWidth
operator|=
literal|1
expr_stmt|;
name|myPenColor
operator|=
name|Qt
operator|::
name|blue
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
DECL|function|openImage
name|bool
name|ScribbleArea
operator|::
name|openImage
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
comment|//! [1] //! [2]
block|{
name|QImage
name|loadedImage
decl_stmt|;
if|if
condition|(
operator|!
name|loadedImage
operator|.
name|load
argument_list|(
name|fileName
argument_list|)
condition|)
return|return
literal|false
return|;
name|QSize
name|newSize
init|=
name|loadedImage
operator|.
name|size
argument_list|()
operator|.
name|expandedTo
argument_list|(
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|resizeImage
argument_list|(
operator|&
name|loadedImage
argument_list|,
name|newSize
argument_list|)
expr_stmt|;
name|image
operator|=
name|loadedImage
expr_stmt|;
name|modified
operator|=
literal|false
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
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|saveImage
name|bool
name|ScribbleArea
operator|::
name|saveImage
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|char
modifier|*
name|fileFormat
parameter_list|)
comment|//! [3] //! [4]
block|{
name|QImage
name|visibleImage
init|=
name|image
decl_stmt|;
name|resizeImage
argument_list|(
operator|&
name|visibleImage
argument_list|,
name|size
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|visibleImage
operator|.
name|save
argument_list|(
name|fileName
argument_list|,
name|fileFormat
argument_list|)
condition|)
block|{
name|modified
operator|=
literal|false
expr_stmt|;
return|return
literal|true
return|;
block|}
else|else
block|{
return|return
literal|false
return|;
block|}
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|setPenColor
name|void
name|ScribbleArea
operator|::
name|setPenColor
parameter_list|(
specifier|const
name|QColor
modifier|&
name|newColor
parameter_list|)
comment|//! [5] //! [6]
block|{
name|myPenColor
operator|=
name|newColor
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|setPenWidth
name|void
name|ScribbleArea
operator|::
name|setPenWidth
parameter_list|(
name|int
name|newWidth
parameter_list|)
comment|//! [7] //! [8]
block|{
name|myPenWidth
operator|=
name|newWidth
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|clearImage
name|void
name|ScribbleArea
operator|::
name|clearImage
parameter_list|()
comment|//! [9] //! [10]
block|{
name|image
operator|.
name|fill
argument_list|(
name|qRgb
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
name|modified
operator|=
literal|true
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_function
DECL|function|mousePressEvent
name|void
name|ScribbleArea
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
comment|//! [11] //! [12]
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
condition|)
block|{
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
block|}
end_function
begin_function
DECL|function|mouseMoveEvent
name|void
name|ScribbleArea
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
name|ScribbleArea
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
begin_comment
comment|//! [12] //! [13]
end_comment
begin_function
DECL|function|paintEvent
name|void
name|ScribbleArea
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
comment|//! [13] //! [14]
block|{
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QRect
name|dirtyRect
init|=
name|event
operator|->
name|rect
argument_list|()
decl_stmt|;
name|painter
operator|.
name|drawImage
argument_list|(
name|dirtyRect
argument_list|,
name|image
argument_list|,
name|dirtyRect
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_function
DECL|function|resizeEvent
name|void
name|ScribbleArea
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|event
parameter_list|)
comment|//! [15] //! [16]
block|{
if|if
condition|(
name|width
argument_list|()
operator|>
name|image
operator|.
name|width
argument_list|()
operator|||
name|height
argument_list|()
operator|>
name|image
operator|.
name|height
argument_list|()
condition|)
block|{
name|int
name|newWidth
init|=
name|qMax
argument_list|(
name|width
argument_list|()
operator|+
literal|128
argument_list|,
name|image
operator|.
name|width
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|newHeight
init|=
name|qMax
argument_list|(
name|height
argument_list|()
operator|+
literal|128
argument_list|,
name|image
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|resizeImage
argument_list|(
operator|&
name|image
argument_list|,
name|QSize
argument_list|(
name|newWidth
argument_list|,
name|newHeight
argument_list|)
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
name|QWidget
operator|::
name|resizeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_function
DECL|function|drawLineTo
name|void
name|ScribbleArea
operator|::
name|drawLineTo
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|endPoint
parameter_list|)
comment|//! [17] //! [18]
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
name|myPenColor
argument_list|,
name|myPenWidth
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
name|modified
operator|=
literal|true
expr_stmt|;
name|int
name|rad
init|=
operator|(
name|myPenWidth
operator|/
literal|2
operator|)
operator|+
literal|2
decl_stmt|;
name|update
argument_list|(
name|QRect
argument_list|(
name|lastPoint
argument_list|,
name|endPoint
argument_list|)
operator|.
name|normalized
argument_list|()
operator|.
name|adjusted
argument_list|(
operator|-
name|rad
argument_list|,
operator|-
name|rad
argument_list|,
operator|+
name|rad
argument_list|,
operator|+
name|rad
argument_list|)
argument_list|)
expr_stmt|;
name|lastPoint
operator|=
name|endPoint
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
DECL|function|resizeImage
name|void
name|ScribbleArea
operator|::
name|resizeImage
parameter_list|(
name|QImage
modifier|*
name|image
parameter_list|,
specifier|const
name|QSize
modifier|&
name|newSize
parameter_list|)
comment|//! [19] //! [20]
block|{
if|if
condition|(
name|image
operator|->
name|size
argument_list|()
operator|==
name|newSize
condition|)
return|return;
name|QImage
name|newImage
argument_list|(
name|newSize
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
name|newImage
operator|.
name|fill
argument_list|(
name|qRgb
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|newImage
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
operator|*
name|image
argument_list|)
expr_stmt|;
operator|*
name|image
operator|=
name|newImage
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [20]
end_comment
begin_comment
comment|//! [21]
end_comment
begin_function
DECL|function|print
name|void
name|ScribbleArea
operator|::
name|print
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
name|QPrinter
name|printer
argument_list|(
name|QPrinter
operator|::
name|HighResolution
argument_list|)
decl_stmt|;
name|QPrintDialog
modifier|*
name|printDialog
init|=
operator|new
name|QPrintDialog
argument_list|(
operator|&
name|printer
argument_list|,
name|this
argument_list|)
decl_stmt|;
comment|//! [21] //! [22]
if|if
condition|(
name|printDialog
operator|->
name|exec
argument_list|()
operator|==
name|QDialog
operator|::
name|Accepted
condition|)
block|{
name|QPainter
name|painter
argument_list|(
operator|&
name|printer
argument_list|)
decl_stmt|;
name|QRect
name|rect
init|=
name|painter
operator|.
name|viewport
argument_list|()
decl_stmt|;
name|QSize
name|size
init|=
name|image
operator|.
name|size
argument_list|()
decl_stmt|;
name|size
operator|.
name|scale
argument_list|(
name|rect
operator|.
name|size
argument_list|()
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setViewport
argument_list|(
name|rect
operator|.
name|x
argument_list|()
argument_list|,
name|rect
operator|.
name|y
argument_list|()
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setWindow
argument_list|(
name|image
operator|.
name|rect
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|image
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|// QT_NO_PRINTER
block|}
end_function
begin_comment
comment|//! [22]
end_comment
end_unit
