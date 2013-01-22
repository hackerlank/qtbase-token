begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|setStyle
name|void
name|QPen
operator|::
name|setStyle
parameter_list|(
name|Qt
operator|::
name|PenStyle
name|style
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
comment|// detach from common data
name|d
operator|->
name|style
operator|=
name|style
expr_stmt|;
comment|// set the style member
block|}
end_function
begin_function
DECL|function|detach
name|void
name|QPen
operator|::
name|detach
parameter_list|()
block|{
if|if
condition|(
name|d
operator|->
name|ref
operator|!=
literal|1
condition|)
block|{
operator|...
comment|// perform a deep copy
block|}
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|p1
DECL|variable|p2
name|QPixmap
name|p1
decl_stmt|,
name|p2
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|p1
operator|.
name|load
argument_list|(
literal|"image.bmp"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|p2
operator|=
name|p1
expr_stmt|;
end_expr_stmt
begin_comment
comment|// p1 and p2 share data
end_comment
begin_decl_stmt
DECL|variable|paint
name|QPainter
name|paint
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|paint
operator|.
name|begin
argument_list|(
operator|&
name|p2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// cuts p2 loose from p1
end_comment
begin_expr_stmt
name|paint
operator|.
name|drawText
argument_list|(
literal|0
argument_list|,
literal|50
argument_list|,
literal|"Hi"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|paint
operator|.
name|end
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
end_unit
