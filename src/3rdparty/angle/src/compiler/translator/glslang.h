begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2010 The ANGLE Project Authors. All rights reserved.
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
begin_struct_decl
struct_decl|struct
name|TParseContext
struct_decl|;
end_struct_decl
begin_function_decl
specifier|extern
name|int
name|glslang_initialize
parameter_list|(
name|TParseContext
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|int
name|glslang_finalize
parameter_list|(
name|TParseContext
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|int
name|glslang_scan
parameter_list|(
name|size_t
name|count
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
name|string
index|[]
parameter_list|,
specifier|const
name|int
name|length
index|[]
parameter_list|,
name|TParseContext
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|int
name|glslang_parse
parameter_list|(
name|TParseContext
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl
end_unit