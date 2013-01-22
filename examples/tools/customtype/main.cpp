begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_include
include|#
directive|include
file|"message.h"
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QStringList
name|headers
decl_stmt|;
name|headers
operator|<<
literal|"Subject: Hello World"
operator|<<
literal|"From: address@example.com"
expr_stmt|;
name|QString
name|body
init|=
literal|"This is a test.\r\n"
decl_stmt|;
comment|//! [printing a custom type]
name|Message
name|message
argument_list|(
name|body
argument_list|,
name|headers
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Original:"
operator|<<
name|message
expr_stmt|;
comment|//! [printing a custom type]
comment|//! [storing a custom value]
name|QVariant
name|stored
decl_stmt|;
name|stored
operator|.
name|setValue
argument_list|(
name|message
argument_list|)
expr_stmt|;
comment|//! [storing a custom value]
name|qDebug
argument_list|()
operator|<<
literal|"Stored:"
operator|<<
name|stored
expr_stmt|;
comment|//! [retrieving a custom value]
name|Message
name|retrieved
init|=
name|stored
operator|.
name|value
argument_list|<
name|Message
argument_list|>
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Retrieved:"
operator|<<
name|retrieved
expr_stmt|;
name|retrieved
operator|=
name|qvariant_cast
argument_list|<
name|Message
argument_list|>
argument_list|(
name|stored
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Retrieved:"
operator|<<
name|retrieved
expr_stmt|;
comment|//! [retrieving a custom value]
return|return
literal|0
return|;
block|}
end_function
end_unit
