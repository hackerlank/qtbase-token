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
begin_include
include|#
directive|include
file|"compiler/translator/Cache.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/InitializeDll.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/InitializeGlobals.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/InitializeParseContext.h"
end_include
begin_include
include|#
directive|include
file|"common/platform.h"
end_include
begin_include
include|#
directive|include
file|<assert.h>
end_include
begin_function
DECL|function|InitProcess
name|bool
name|InitProcess
parameter_list|()
block|{
if|if
condition|(
operator|!
name|InitializePoolIndex
argument_list|()
condition|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"InitProcess(): Failed to initalize global pool"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
operator|!
name|InitializeParseContextIndex
argument_list|()
condition|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"InitProcess(): Failed to initalize parse context"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|TCache
operator|::
name|initialize
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|DetachProcess
name|void
name|DetachProcess
parameter_list|()
block|{
name|FreeParseContextIndex
argument_list|()
expr_stmt|;
name|FreePoolIndex
argument_list|()
expr_stmt|;
name|TCache
operator|::
name|destroy
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
