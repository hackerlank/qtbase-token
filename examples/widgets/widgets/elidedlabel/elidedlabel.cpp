begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"elidedlabel.h"
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QTextLayout>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|ElidedLabel
name|ElidedLabel
operator|::
name|ElidedLabel
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
name|QFrame
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|elided
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|content
argument_list|(
name|text
argument_list|)
block|{
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Preferred
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
DECL|function|setText
name|void
name|ElidedLabel
operator|::
name|setText
parameter_list|(
specifier|const
name|QString
modifier|&
name|newText
parameter_list|)
block|{
name|content
operator|=
name|newText
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
DECL|function|paintEvent
name|void
name|ElidedLabel
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
name|QFontMetrics
name|fontMetrics
init|=
name|painter
operator|.
name|fontMetrics
argument_list|()
decl_stmt|;
name|bool
name|didElide
init|=
literal|false
decl_stmt|;
name|int
name|lineSpacing
init|=
name|fontMetrics
operator|.
name|lineSpacing
argument_list|()
decl_stmt|;
name|int
name|y
init|=
literal|0
decl_stmt|;
name|QTextLayout
name|textLayout
argument_list|(
name|content
argument_list|,
name|painter
operator|.
name|font
argument_list|()
argument_list|)
decl_stmt|;
name|textLayout
operator|.
name|beginLayout
argument_list|()
expr_stmt|;
forever|forever
block|{
name|QTextLine
name|line
init|=
name|textLayout
operator|.
name|createLine
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|line
operator|.
name|isValid
argument_list|()
condition|)
break|break;
name|line
operator|.
name|setLineWidth
argument_list|(
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|nextLineY
init|=
name|y
operator|+
name|lineSpacing
decl_stmt|;
if|if
condition|(
name|height
argument_list|()
operator|>=
name|nextLineY
operator|+
name|lineSpacing
condition|)
block|{
name|line
operator|.
name|draw
argument_list|(
operator|&
name|painter
argument_list|,
name|QPoint
argument_list|(
literal|0
argument_list|,
name|y
argument_list|)
argument_list|)
expr_stmt|;
name|y
operator|=
name|nextLineY
expr_stmt|;
comment|//! [2]
comment|//! [3]
block|}
else|else
block|{
name|QString
name|lastLine
init|=
name|content
operator|.
name|mid
argument_list|(
name|line
operator|.
name|textStart
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|elidedLastLine
init|=
name|fontMetrics
operator|.
name|elidedText
argument_list|(
name|lastLine
argument_list|,
name|Qt
operator|::
name|ElideRight
argument_list|,
name|width
argument_list|()
argument_list|)
decl_stmt|;
name|painter
operator|.
name|drawText
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
name|y
operator|+
name|fontMetrics
operator|.
name|ascent
argument_list|()
argument_list|)
argument_list|,
name|elidedLastLine
argument_list|)
expr_stmt|;
name|line
operator|=
name|textLayout
operator|.
name|createLine
argument_list|()
expr_stmt|;
name|didElide
operator|=
name|line
operator|.
name|isValid
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
name|textLayout
operator|.
name|endLayout
argument_list|()
expr_stmt|;
comment|//! [3]
comment|//! [4]
if|if
condition|(
name|didElide
operator|!=
name|elided
condition|)
block|{
name|elided
operator|=
name|didElide
expr_stmt|;
emit|emit
name|elisionChanged
argument_list|(
name|didElide
argument_list|)
emit|;
block|}
block|}
end_function
begin_comment
comment|//! [4]
end_comment
end_unit
