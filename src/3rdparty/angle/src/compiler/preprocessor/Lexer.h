begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_PREPROCESSOR_LEXER_H_
end_ifndef
begin_define
DECL|macro|COMPILER_PREPROCESSOR_LEXER_H_
define|#
directive|define
name|COMPILER_PREPROCESSOR_LEXER_H_
end_define
begin_decl_stmt
name|namespace
name|pp
block|{
struct_decl|struct
name|Token
struct_decl|;
name|class
name|Lexer
block|{
name|public
label|:
name|virtual
operator|~
name|Lexer
argument_list|()
expr_stmt|;
name|virtual
name|void
name|lex
parameter_list|(
name|Token
modifier|*
name|token
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace pp
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_PREPROCESSOR_LEXER_H_
end_comment
end_unit
