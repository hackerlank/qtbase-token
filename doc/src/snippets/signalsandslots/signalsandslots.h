begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SIGNALSANDSLOTS_H
end_ifndef
begin_define
DECL|macro|SIGNALSANDSLOTS_H
define|#
directive|define
name|SIGNALSANDSLOTS_H
end_define
begin_define
DECL|macro|Counter
define|#
directive|define
name|Counter
value|PlainCounter
end_define
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|Counter
block|{
name|public
label|:
name|Counter
argument_list|()
block|{
name|m_value
operator|=
literal|0
expr_stmt|;
block|}
name|int
name|value
argument_list|()
specifier|const
block|{
return|return
name|m_value
return|;
block|}
name|void
name|setValue
parameter_list|(
name|int
name|value
parameter_list|)
function_decl|;
name|private
label|:
name|int
name|m_value
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//! [0]
end_comment
begin_undef
DECL|macro|Counter
undef|#
directive|undef
name|Counter
end_undef
begin_define
DECL|macro|Counter
define|#
directive|define
name|Counter
value|ObjectCounter
end_define
begin_comment
comment|//! [1]
end_comment
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
name|class
name|Counter
range|:
name|public
name|QObject
comment|//! [2] //! [3]
block|{
name|Q_OBJECT
name|public
operator|:
name|Counter
argument_list|()
block|{
name|m_value
operator|=
literal|0
block|; }
name|int
name|value
argument_list|()
specifier|const
block|{
return|return
name|m_value
return|;
block|}
name|public
name|slots
operator|:
name|void
name|setValue
argument_list|(
argument|int value
argument_list|)
block|;
name|signals
operator|:
name|void
name|valueChanged
argument_list|(
argument|int newValue
argument_list|)
block|;
name|private
operator|:
name|int
name|m_value
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [3]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
