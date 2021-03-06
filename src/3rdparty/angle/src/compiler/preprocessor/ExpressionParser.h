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
name|COMPILER_PREPROCESSOR_EXPRESSIONPARSER_H_
end_ifndef
begin_define
DECL|macro|COMPILER_PREPROCESSOR_EXPRESSIONPARSER_H_
define|#
directive|define
name|COMPILER_PREPROCESSOR_EXPRESSIONPARSER_H_
end_define
begin_include
include|#
directive|include
file|"DiagnosticsBase.h"
end_include
begin_include
include|#
directive|include
file|"pp_utils.h"
end_include
begin_decl_stmt
name|namespace
name|pp
block|{
name|class
name|Lexer
decl_stmt|;
struct_decl|struct
name|Token
struct_decl|;
name|class
name|ExpressionParser
block|{
name|public
label|:
struct|struct
name|ErrorSettings
block|{
name|Diagnostics
operator|::
name|ID
name|unexpectedIdentifier
expr_stmt|;
name|bool
name|integerLiteralsMustFit32BitSignedRange
decl_stmt|;
block|}
struct|;
name|ExpressionParser
argument_list|(
name|Lexer
operator|*
name|lexer
argument_list|,
name|Diagnostics
operator|*
name|diagnostics
argument_list|)
expr_stmt|;
name|bool
name|parse
parameter_list|(
name|Token
modifier|*
name|token
parameter_list|,
name|int
modifier|*
name|result
parameter_list|,
name|bool
name|parsePresetToken
parameter_list|,
specifier|const
name|ErrorSettings
modifier|&
name|errorSettings
parameter_list|,
name|bool
modifier|*
name|valid
parameter_list|)
function_decl|;
name|private
label|:
name|PP_DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ExpressionParser
argument_list|)
expr_stmt|;
name|Lexer
modifier|*
name|mLexer
decl_stmt|;
name|Diagnostics
modifier|*
name|mDiagnostics
decl_stmt|;
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
comment|// COMPILER_PREPROCESSOR_EXPRESSIONPARSER_H_
end_comment
end_unit
