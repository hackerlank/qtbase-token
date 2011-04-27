begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"roundrectitem.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QtGui>
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|RoundRectItem
name|RoundRectItem
operator|::
name|RoundRectItem
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|bounds
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|,
name|QGraphicsItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|fillRect
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|bounds
argument_list|(
name|bounds
argument_list|)
block|{
name|gradient
operator|.
name|setStart
argument_list|(
name|bounds
operator|.
name|topLeft
argument_list|()
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setFinalStop
argument_list|(
name|bounds
operator|.
name|bottomRight
argument_list|()
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|color
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|color
operator|.
name|dark
argument_list|(
literal|200
argument_list|)
argument_list|)
expr_stmt|;
name|setCacheMode
argument_list|(
name|ItemCoordinateCache
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
DECL|function|pixmap
name|QPixmap
name|RoundRectItem
operator|::
name|pixmap
parameter_list|()
specifier|const
block|{
return|return
name|pix
return|;
block|}
end_function
begin_function
DECL|function|setPixmap
name|void
name|RoundRectItem
operator|::
name|setPixmap
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
block|{
name|pix
operator|=
name|pixmap
expr_stmt|;
name|update
argument_list|()
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
DECL|function|boundingRect
name|QRectF
name|RoundRectItem
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|bounds
operator|.
name|adjusted
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
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
name|RoundRectItem
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
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|option
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|64
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRoundRect
argument_list|(
name|bounds
operator|.
name|translated
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [3]
comment|//! [4]
if|if
condition|(
name|fillRect
condition|)
name|painter
operator|->
name|setBrush
argument_list|(
name|QApplication
operator|::
name|palette
argument_list|()
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Window
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|painter
operator|->
name|setBrush
argument_list|(
name|gradient
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRoundRect
argument_list|(
name|bounds
argument_list|)
expr_stmt|;
comment|//! [4]
comment|//! [5]
if|if
condition|(
operator|!
name|pix
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|painter
operator|->
name|scale
argument_list|(
literal|1.95
argument_list|,
literal|1.95
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPixmap
argument_list|(
operator|-
name|pix
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
operator|-
name|pix
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
name|pix
argument_list|)
expr_stmt|;
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
DECL|function|fill
name|bool
name|RoundRectItem
operator|::
name|fill
parameter_list|()
specifier|const
block|{
return|return
name|fillRect
return|;
block|}
end_function
begin_function
DECL|function|setFill
name|void
name|RoundRectItem
operator|::
name|setFill
parameter_list|(
name|bool
name|fill
parameter_list|)
block|{
name|fillRect
operator|=
name|fill
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
end_unit
