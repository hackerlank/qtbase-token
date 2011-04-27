begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|leading
name|int
name|leading
init|=
name|fontMetrics
operator|.
name|leading
argument_list|()
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|height
name|qreal
name|height
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|textLayout
operator|.
name|beginLayout
argument_list|()
expr_stmt|;
end_expr_stmt
begin_while
while|while
condition|(
literal|1
condition|)
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
name|lineWidth
argument_list|)
expr_stmt|;
name|height
operator|+=
name|leading
expr_stmt|;
name|line
operator|.
name|setPosition
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
name|height
argument_list|)
argument_list|)
expr_stmt|;
name|height
operator|+=
name|line
operator|.
name|height
argument_list|()
expr_stmt|;
block|}
end_while
begin_expr_stmt
name|textLayout
operator|.
name|endLayout
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function_decl
name|QPainter
name|painter
parameter_list|(
name|this
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|textLayout
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
literal|0
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
end_unit
