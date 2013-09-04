begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CHARACTER_H
end_ifndef
begin_define
DECL|macro|CHARACTER_H
define|#
directive|define
name|CHARACTER_H
end_define
begin_include
include|#
directive|include
file|<QJsonObject>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|Character
block|{
name|public
label|:
enum|enum
name|ClassType
block|{
name|Warrior
block|,
name|Mage
block|,
name|Archer
block|}
enum|;
name|Character
argument_list|()
expr_stmt|;
name|Character
argument_list|(
argument|const QString&name
argument_list|,
argument|int level
argument_list|,
argument|ClassType classType
argument_list|)
empty_stmt|;
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|int
name|level
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLevel
parameter_list|(
name|int
name|level
parameter_list|)
function_decl|;
name|ClassType
name|classType
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setClassType
parameter_list|(
name|ClassType
name|classType
parameter_list|)
function_decl|;
name|void
name|read
parameter_list|(
specifier|const
name|QJsonObject
modifier|&
name|json
parameter_list|)
function_decl|;
name|void
name|write
argument_list|(
name|QJsonObject
operator|&
name|json
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|QString
name|mName
decl_stmt|;
name|int
name|mLevel
decl_stmt|;
name|ClassType
name|mClassType
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// CHARACTER_H
end_comment
end_unit