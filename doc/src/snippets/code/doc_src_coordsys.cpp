begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
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
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|darkGreen
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|drawRect
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|6
argument_list|,
literal|4
argument_list|)
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
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|darkGreen
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|drawLine
argument_list|(
literal|2
argument_list|,
literal|7
argument_list|,
literal|6
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
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
name|painter
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|darkGreen
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|drawRect
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|6
argument_list|,
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
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
name|painter
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|darkGreen
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|drawLine
argument_list|(
literal|2
argument_list|,
literal|7
argument_list|,
literal|6
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
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
name|painter
operator|.
name|setWindow
argument_list|(
name|QRect
argument_list|(
operator|-
literal|50
argument_list|,
operator|-
literal|50
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
DECL|variable|side
name|int
name|side
init|=
name|qMin
argument_list|(
argument|width()
argument_list|,
argument|height()
argument_list|)
name|int
name|x
operator|=
operator|(
name|width
argument_list|()
operator|-
name|side
operator|/
literal|2
operator|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|y
name|int
name|y
init|=
operator|(
name|height
argument_list|()
operator|-
name|side
operator|/
literal|2
operator|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|painter
operator|.
name|setViewport
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|side
argument_list|,
name|side
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [5]
end_comment
end_unit
