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
file|"draglabel.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|DragLabel
name|DragLabel
operator|::
name|DragLabel
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QLabel
argument_list|(
name|parent
argument_list|)
block|{
name|QFontMetrics
name|metric
argument_list|(
name|font
argument_list|()
argument_list|)
decl_stmt|;
name|QSize
name|size
init|=
name|metric
operator|.
name|size
argument_list|(
name|Qt
operator|::
name|TextSingleLine
argument_list|,
name|text
argument_list|)
decl_stmt|;
name|QImage
name|image
argument_list|(
name|size
operator|.
name|width
argument_list|()
operator|+
literal|12
argument_list|,
name|size
operator|.
name|height
argument_list|()
operator|+
literal|12
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl_stmt|;
name|image
operator|.
name|fill
argument_list|(
name|qRgba
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QFont
name|font
decl_stmt|;
name|font
operator|.
name|setStyleStrategy
argument_list|(
name|QFont
operator|::
name|ForceOutline
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|QLinearGradient
name|gradient
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|image
operator|.
name|height
argument_list|()
operator|-
literal|1
argument_list|)
decl_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0.0
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0.2
argument_list|,
name|QColor
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0.8
argument_list|,
name|QColor
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|1.0
argument_list|,
name|QColor
argument_list|(
literal|127
argument_list|,
literal|127
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
name|QPainter
name|painter
decl_stmt|;
name|painter
operator|.
name|begin
argument_list|(
operator|&
name|image
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setBrush
argument_list|(
name|gradient
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawRoundedRect
argument_list|(
name|QRectF
argument_list|(
literal|0.5
argument_list|,
literal|0.5
argument_list|,
name|image
operator|.
name|width
argument_list|()
operator|-
literal|1
argument_list|,
name|image
operator|.
name|height
argument_list|()
operator|-
literal|1
argument_list|)
argument_list|,
literal|25
argument_list|,
literal|25
argument_list|,
name|Qt
operator|::
name|RelativeSize
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawText
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|6
argument_list|,
literal|6
argument_list|)
argument_list|,
name|size
argument_list|)
argument_list|,
name|Qt
operator|::
name|AlignCenter
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|setPixmap
argument_list|(
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|image
argument_list|)
argument_list|)
expr_stmt|;
name|m_labelText
operator|=
name|text
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|labelText
name|QString
name|DragLabel
operator|::
name|labelText
parameter_list|()
specifier|const
block|{
return|return
name|m_labelText
return|;
block|}
end_function
end_unit
