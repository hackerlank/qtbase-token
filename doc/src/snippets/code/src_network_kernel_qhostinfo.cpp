begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|// To find the IP address of qt.nokia.com
end_comment
begin_expr_stmt
name|QHostInfo
operator|::
name|lookupHost
argument_list|(
literal|"qt.nokia.com"
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|printResults
argument_list|(
name|QHostInfo
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// To find the host name for 4.2.2.1
end_comment
begin_expr_stmt
name|QHostInfo
operator|::
name|lookupHost
argument_list|(
literal|"4.2.2.1"
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|printResults
argument_list|(
name|QHostInfo
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|info
name|QHostInfo
name|info
init|=
name|QHostInfo
operator|::
name|fromName
argument_list|(
literal|"qt.nokia.com"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_expr_stmt
name|QHostInfo
operator|::
name|lookupHost
argument_list|(
literal|"www.kde.org"
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|lookedUp
argument_list|(
name|QHostInfo
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|lookedUp
name|void
name|MyWidget
operator|::
name|lookedUp
parameter_list|(
specifier|const
name|QHostInfo
modifier|&
name|host
parameter_list|)
block|{
if|if
condition|(
name|host
operator|.
name|error
argument_list|()
operator|!=
name|QHostInfo
operator|::
name|NoError
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Lookup failed:"
operator|<<
name|host
operator|.
name|errorString
argument_list|()
expr_stmt|;
return|return;
block|}
foreach|foreach
control|(
specifier|const
name|QHostAddress
modifier|&
name|address
decl|,
name|host
operator|.
name|addresses
argument_list|()
control|)
name|qDebug
argument_list|()
operator|<<
literal|"Found address:"
operator|<<
name|address
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_expr_stmt
name|QHostInfo
operator|::
name|lookupHost
argument_list|(
literal|"4.2.2.1"
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|lookedUp
argument_list|(
name|QHostInfo
argument_list|)
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
DECL|variable|info
name|QHostInfo
name|info
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|...
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|info
operator|.
name|addresses
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QHostAddress
name|address
init|=
name|info
operator|.
name|addresses
argument_list|()
operator|.
name|first
argument_list|()
decl_stmt|;
comment|// use the first IP address
block|}
end_if
begin_comment
comment|//! [5]
end_comment
end_unit
