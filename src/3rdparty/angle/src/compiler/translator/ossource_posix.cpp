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
begin_comment
comment|//
end_comment
begin_comment
comment|// This file contains the posix specific functions
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"compiler/translator/osinclude.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ANGLE_OS_POSIX
argument_list|)
end_if
begin_error
error|#
directive|error
error|Trying to build a posix specific file in a non-posix build.
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//
end_comment
begin_comment
comment|// Thread Local Storage Operations
end_comment
begin_comment
comment|//
end_comment
begin_function
DECL|function|OS_AllocTLSIndex
name|OS_TLSIndex
name|OS_AllocTLSIndex
parameter_list|()
block|{
name|pthread_key_t
name|pPoolIndex
decl_stmt|;
comment|//
comment|// Create global pool key.
comment|//
if|if
condition|(
operator|(
name|pthread_key_create
argument_list|(
operator|&
name|pPoolIndex
argument_list|,
name|NULL
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"OS_AllocTLSIndex(): Unable to allocate Thread Local Storage"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
else|else
block|{
return|return
name|pPoolIndex
return|;
block|}
block|}
end_function
begin_function
DECL|function|OS_GetTLSValue
name|void
modifier|*
name|OS_GetTLSValue
parameter_list|(
name|OS_TLSIndex
name|nIndex
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|nIndex
operator|!=
name|OS_INVALID_TLS_INDEX
argument_list|)
expr_stmt|;
return|return
name|pthread_getspecific
argument_list|(
name|nIndex
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|OS_SetTLSValue
name|bool
name|OS_SetTLSValue
parameter_list|(
name|OS_TLSIndex
name|nIndex
parameter_list|,
name|void
modifier|*
name|lpvValue
parameter_list|)
block|{
if|if
condition|(
name|nIndex
operator|==
name|OS_INVALID_TLS_INDEX
condition|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"OS_SetTLSValue(): Invalid TLS Index"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|pthread_setspecific
argument_list|(
name|nIndex
argument_list|,
name|lpvValue
argument_list|)
operator|==
literal|0
condition|)
return|return
literal|true
return|;
else|else
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|OS_FreeTLSIndex
name|bool
name|OS_FreeTLSIndex
parameter_list|(
name|OS_TLSIndex
name|nIndex
parameter_list|)
block|{
if|if
condition|(
name|nIndex
operator|==
name|OS_INVALID_TLS_INDEX
condition|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"OS_SetTLSValue(): Invalid TLS Index"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|//
comment|// Delete the global pool key.
comment|//
if|if
condition|(
name|pthread_key_delete
argument_list|(
name|nIndex
argument_list|)
operator|==
literal|0
condition|)
return|return
literal|true
return|;
else|else
return|return
literal|false
return|;
block|}
end_function
end_unit