begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2010 The ANGLE Project Authors. All rights reserved.
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
name|COMPILER_TRANSLATOR_INITIALIZEPARSECONTEXT_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_INITIALIZEPARSECONTEXT_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_INITIALIZEPARSECONTEXT_H_
end_define
begin_function_decl
name|bool
name|InitializeParseContextIndex
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|FreeParseContextIndex
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|TParseContext
name|class
name|TParseContext
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|extern
name|void
name|SetGlobalParseContext
parameter_list|(
name|TParseContext
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|TParseContext
modifier|*
name|GetGlobalParseContext
parameter_list|()
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_INITIALIZEPARSECONTEXT_H_
end_comment
end_unit
