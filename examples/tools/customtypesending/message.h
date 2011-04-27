begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MESSAGE_H
end_ifndef
begin_define
DECL|macro|MESSAGE_H
define|#
directive|define
name|MESSAGE_H
end_define
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QMetaType>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_comment
comment|//! [custom type definition]
end_comment
begin_decl_stmt
name|class
name|Message
block|{
name|public
label|:
name|Message
argument_list|()
expr_stmt|;
name|Message
argument_list|(
specifier|const
name|Message
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|Message
argument_list|()
expr_stmt|;
name|Message
argument_list|(
specifier|const
name|QString
operator|&
name|body
argument_list|,
specifier|const
name|QStringList
operator|&
name|headers
argument_list|)
expr_stmt|;
name|QString
name|body
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|headers
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QString
name|m_body
decl_stmt|;
name|QStringList
name|m_headers
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//! [custom type definition]
end_comment
begin_comment
comment|//! [custom type meta-type declaration]
end_comment
begin_expr_stmt
DECL|variable|Message
name|Q_DECLARE_METATYPE
argument_list|(
name|Message
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [custom type meta-type declaration]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
