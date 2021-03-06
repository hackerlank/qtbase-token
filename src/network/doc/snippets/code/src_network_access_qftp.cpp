begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|ftp
name|QFtp
modifier|*
name|ftp
init|=
operator|new
name|QFtp
argument_list|(
name|parent
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|ftp
operator|->
name|connectToHost
argument_list|(
literal|"ftp.qt-project.org"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|ftp
operator|->
name|login
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_expr_stmt
name|ftp
operator|->
name|connectToHost
argument_list|(
literal|"ftp.qt-project.org"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// id == 1
end_comment
begin_expr_stmt
name|ftp
operator|->
name|login
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// id == 2
end_comment
begin_expr_stmt
name|ftp
operator|->
name|cd
argument_list|(
literal|"qt"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// id == 3
end_comment
begin_expr_stmt
name|ftp
operator|->
name|get
argument_list|(
literal|"INSTALL"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// id == 4
end_comment
begin_expr_stmt
name|ftp
operator|->
name|close
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// id == 5
end_comment
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_macro
name|start
argument_list|(
literal|1
argument_list|)
end_macro
begin_macro
name|stateChanged
argument_list|(
argument|HostLookup
argument_list|)
end_macro
begin_macro
name|stateChanged
argument_list|(
argument|Connecting
argument_list|)
end_macro
begin_macro
name|stateChanged
argument_list|(
argument|Connected
argument_list|)
end_macro
begin_macro
name|finished
argument_list|(
literal|1
argument_list|,
literal|false
argument_list|)
end_macro
begin_macro
name|start
argument_list|(
literal|2
argument_list|)
end_macro
begin_macro
name|stateChanged
argument_list|(
argument|LoggedIn
argument_list|)
end_macro
begin_macro
name|finished
argument_list|(
literal|2
argument_list|,
literal|false
argument_list|)
end_macro
begin_macro
name|start
argument_list|(
literal|3
argument_list|)
end_macro
begin_macro
name|finished
argument_list|(
literal|3
argument_list|,
literal|false
argument_list|)
end_macro
begin_macro
name|start
argument_list|(
literal|4
argument_list|)
end_macro
begin_macro
name|dataTransferProgress
argument_list|(
literal|0
argument_list|,
literal|3798
argument_list|)
end_macro
begin_macro
name|dataTransferProgress
argument_list|(
literal|2896
argument_list|,
literal|3798
argument_list|)
end_macro
begin_macro
name|readyRead
argument_list|()
end_macro
begin_macro
name|dataTransferProgress
argument_list|(
literal|3798
argument_list|,
literal|3798
argument_list|)
end_macro
begin_macro
name|readyRead
argument_list|()
end_macro
begin_macro
name|finished
argument_list|(
literal|4
argument_list|,
literal|false
argument_list|)
end_macro
begin_macro
name|start
argument_list|(
literal|5
argument_list|)
end_macro
begin_macro
name|stateChanged
argument_list|(
argument|Closing
argument_list|)
end_macro
begin_macro
name|stateChanged
argument_list|(
argument|Unconnected
argument_list|)
end_macro
begin_macro
name|finished
argument_list|(
literal|5
argument_list|,
literal|false
argument_list|)
end_macro
begin_macro
name|done
argument_list|(
literal|false
argument_list|)
end_macro
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_macro
name|start
argument_list|(
literal|1
argument_list|)
end_macro
begin_macro
name|stateChanged
argument_list|(
argument|HostLookup
argument_list|)
end_macro
begin_macro
name|stateChanged
argument_list|(
argument|Connecting
argument_list|)
end_macro
begin_macro
name|stateChanged
argument_list|(
argument|Connected
argument_list|)
end_macro
begin_macro
name|finished
argument_list|(
literal|1
argument_list|,
literal|false
argument_list|)
end_macro
begin_macro
name|start
argument_list|(
literal|2
argument_list|)
end_macro
begin_macro
name|finished
argument_list|(
literal|2
argument_list|,
literal|true
argument_list|)
end_macro
begin_macro
name|done
argument_list|(
literal|true
argument_list|)
end_macro
begin_comment
comment|//! [3]
end_comment
end_unit
