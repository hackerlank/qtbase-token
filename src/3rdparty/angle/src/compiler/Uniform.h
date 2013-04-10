begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2013 The ANGLE Project Authors. All rights reserved.
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
name|COMPILER_UNIFORM_H_
end_ifndef
begin_define
DECL|macro|COMPILER_UNIFORM_H_
define|#
directive|define
name|COMPILER_UNIFORM_H_
end_define
begin_include
include|#
directive|include
file|<string>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_define
DECL|macro|GL_APICALL
define|#
directive|define
name|GL_APICALL
end_define
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_decl_stmt
name|namespace
name|sh
block|{
struct|struct
name|Uniform
block|{
name|Uniform
argument_list|(
argument|GLenum type
argument_list|,
argument|GLenum precision
argument_list|,
argument|const char *name
argument_list|,
argument|int arraySize
argument_list|,
argument|int registerIndex
argument_list|)
empty_stmt|;
name|GLenum
name|type
decl_stmt|;
name|GLenum
name|precision
decl_stmt|;
name|std
operator|::
name|string
name|name
expr_stmt|;
name|unsigned
name|int
name|arraySize
decl_stmt|;
name|int
name|registerIndex
decl_stmt|;
block|}
struct|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Uniform
operator|>
name|ActiveUniforms
expr_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_UNIFORM_H_
end_comment
end_unit
