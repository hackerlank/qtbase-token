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
name|WA_AcceptTouchEvents
argument_list|)
expr_stmt|;
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
name|myPenColors
operator|<<
name|QColor
argument_list|(
literal|"green"
argument_list|)
operator|<<
name|QColor
argument_list|(
literal|"purple"
argument_list|)
operator|<<
name|QColor
argument_list|(
literal|"red"
argument_list|)
operator|<<
name|QColor
argument_list|(
literal|"blue"
argument_list|)
operator|<<
name|QColor
argument_list|(
literal|"yellow"
argument_list|)
operator|<<
name|QColor
argument_list|(
literal|"pink"
argument_list|)
operator|<<
name|QColor
argument_list|(
literal|"orange"
argument_list|)
operator|<<
name|QColor
argument_list|(
literal|"brown"
argument_list|)
operator|<<
name|QColor
argument_list|(
literal|"grey"
argument_list|)
operator|<<
name|QColor
argument_list|(
literal|"black"
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
specifier|const
name|QRect
name|rect
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
name|rect
operator|.
name|topLeft
argument_list|()
argument_list|,
name|image
argument_list|,
name|rect
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
begin_function
DECL|function|event
name|bool
name|ScribbleArea
operator|::
name|event
parameter_list|(
name|QEvent
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
name|TouchBegin
case|:
case|case
name|QEvent
operator|::
name|TouchUpdate
case|:
case|case
name|QEvent
operator|::
name|TouchEnd
case|:
block|{
name|QList
argument_list|<
name|QTouchEvent
operator|::
name|TouchPoint
argument_list|>
name|touchPoints
init|=
cast|static_cast
argument_list|<
name|QTouchEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
operator|->
name|touchPoints
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QTouchEvent
operator|::
name|TouchPoint
modifier|&
name|touchPoint
decl|,
name|touchPoints
control|)
block|{
switch|switch
condition|(
name|touchPoint
operator|.
name|state
argument_list|()
condition|)
block|{
case|case
name|Qt
operator|::
name|TouchPointStationary
case|:
comment|// don't do anything if this touch point hasn't moved
continue|continue;
default|default:
block|{
name|QRectF
name|rect
init|=
name|touchPoint
operator|.
name|rect
argument_list|()
decl_stmt|;
if|if
condition|(
name|rect
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qreal
name|diameter
init|=
name|qreal
argument_list|(
literal|50
argument_list|)
operator|*
name|touchPoint
operator|.
name|pressure
argument_list|()
decl_stmt|;
name|rect
operator|.
name|setSize
argument_list|(
name|QSizeF
argument_list|(
name|diameter
argument_list|,
name|diameter
argument_list|)
argument_list|)
expr_stmt|;
block|}
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
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setBrush
argument_list|(
name|myPenColors
operator|.
name|at
argument_list|(
name|touchPoint
operator|.
name|id
argument_list|()
operator|%
name|myPenColors
operator|.
name|count
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawEllipse
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
name|modified
operator|=
literal|true
expr_stmt|;
name|int
name|rad
init|=
literal|2
decl_stmt|;
name|update
argument_list|(
name|rect
operator|.
name|toRect
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
block|}
break|break;
block|}
block|}
break|break;
block|}
default|default:
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
end_unit
