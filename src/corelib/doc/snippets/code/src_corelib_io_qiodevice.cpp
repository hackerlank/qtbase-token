begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|gzip
name|QProcess
name|gzip
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|gzip
operator|.
name|start
argument_list|(
literal|"gzip"
argument_list|,
name|QStringList
argument_list|()
operator|<<
literal|"-c"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|gzip
operator|.
name|waitForStarted
argument_list|()
condition|)
return|return
literal|false
return|;
end_if
begin_expr_stmt
name|gzip
operator|.
name|write
argument_list|(
literal|"uncompressed data"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|compressed
name|QByteArray
name|compressed
decl_stmt|;
end_decl_stmt
begin_while
while|while
condition|(
name|gzip
operator|.
name|waitForReadyRead
argument_list|()
condition|)
name|compressed
operator|+=
name|gzip
operator|.
name|readAll
argument_list|()
expr_stmt|;
end_while
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|bytesAvailable
name|qint64
name|CustomDevice
operator|::
name|bytesAvailable
parameter_list|()
specifier|const
block|{
return|return
name|buffer
operator|.
name|size
argument_list|()
operator|+
name|QIODevice
operator|::
name|bytesAvailable
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
name|QFile
name|file
argument_list|(
literal|"box.txt"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|char
name|buf
index|[
literal|1024
index|]
decl_stmt|;
name|qint64
name|lineLength
init|=
name|file
operator|.
name|readLine
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|lineLength
operator|!=
operator|-
literal|1
condition|)
block|{
comment|// the line is available in buf
block|}
block|}
end_if
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|canReadLine
name|bool
name|CustomDevice
operator|::
name|canReadLine
parameter_list|()
specifier|const
block|{
return|return
name|buffer
operator|.
name|contains
argument_list|(
literal|'\n'
argument_list|)
operator|||
name|QIODevice
operator|::
name|canReadLine
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|isExeFile
name|bool
name|isExeFile
parameter_list|(
name|QFile
modifier|*
name|file
parameter_list|)
block|{
name|char
name|buf
index|[
literal|2
index|]
decl_stmt|;
if|if
condition|(
name|file
operator|->
name|peek
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
condition|)
return|return
operator|(
name|buf
index|[
literal|0
index|]
operator|==
literal|'M'
operator|&&
name|buf
index|[
literal|1
index|]
operator|==
literal|'Z'
operator|)
return|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|isExeFile
name|bool
name|isExeFile
parameter_list|(
name|QFile
modifier|*
name|file
parameter_list|)
block|{
return|return
name|file
operator|->
name|peek
argument_list|(
literal|2
argument_list|)
operator|==
literal|"MZ"
return|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
end_unit
