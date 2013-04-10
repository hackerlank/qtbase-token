begin_unit
begin_include
include|#
directive|include
file|"precompiled.h"
end_include
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
begin_comment
comment|// Fence11.cpp: Defines the rx::Fence11 class which implements rx::FenceImpl.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Fence11.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/main.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Renderer11.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|Fence11
name|Fence11
operator|::
name|Fence11
parameter_list|(
name|rx
operator|::
name|Renderer11
modifier|*
name|renderer
parameter_list|)
block|{
name|mRenderer
operator|=
name|renderer
expr_stmt|;
name|mQuery
operator|=
name|NULL
expr_stmt|;
block|}
DECL|function|~Fence11
name|Fence11
operator|::
name|~
name|Fence11
parameter_list|()
block|{
if|if
condition|(
name|mQuery
condition|)
block|{
name|mQuery
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mQuery
operator|=
name|NULL
expr_stmt|;
block|}
block|}
DECL|function|isFence
name|GLboolean
name|Fence11
operator|::
name|isFence
parameter_list|()
block|{
comment|// GL_NV_fence spec:
comment|// A name returned by GenFencesNV, but not yet set via SetFenceNV, is not the name of an existing fence.
return|return
name|mQuery
operator|!=
name|NULL
return|;
block|}
DECL|function|setFence
name|void
name|Fence11
operator|::
name|setFence
parameter_list|(
name|GLenum
name|condition
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mQuery
condition|)
block|{
name|D3D11_QUERY_DESC
name|queryDesc
decl_stmt|;
name|queryDesc
operator|.
name|Query
operator|=
name|D3D11_QUERY_EVENT
expr_stmt|;
name|queryDesc
operator|.
name|MiscFlags
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|mRenderer
operator|->
name|getDevice
argument_list|()
operator|->
name|CreateQuery
argument_list|(
operator|&
name|queryDesc
argument_list|,
operator|&
name|mQuery
argument_list|)
argument_list|)
condition|)
block|{
return|return
name|gl
operator|::
name|error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|)
return|;
block|}
block|}
name|mRenderer
operator|->
name|getDeviceContext
argument_list|()
operator|->
name|End
argument_list|(
name|mQuery
argument_list|)
expr_stmt|;
name|setCondition
argument_list|(
name|condition
argument_list|)
expr_stmt|;
name|setStatus
argument_list|(
name|GL_FALSE
argument_list|)
expr_stmt|;
block|}
DECL|function|testFence
name|GLboolean
name|Fence11
operator|::
name|testFence
parameter_list|()
block|{
if|if
condition|(
name|mQuery
operator|==
name|NULL
condition|)
block|{
return|return
name|gl
operator|::
name|error
argument_list|(
name|GL_INVALID_OPERATION
argument_list|,
name|GL_TRUE
argument_list|)
return|;
block|}
name|HRESULT
name|result
init|=
name|mRenderer
operator|->
name|getDeviceContext
argument_list|()
operator|->
name|GetData
argument_list|(
name|mQuery
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|mRenderer
operator|->
name|isDeviceLost
argument_list|()
condition|)
block|{
return|return
name|gl
operator|::
name|error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
name|GL_TRUE
argument_list|)
return|;
block|}
name|ASSERT
argument_list|(
name|result
operator|==
name|S_OK
operator|||
name|result
operator|==
name|S_FALSE
argument_list|)
expr_stmt|;
name|setStatus
argument_list|(
name|result
operator|==
name|S_OK
argument_list|)
expr_stmt|;
return|return
name|getStatus
argument_list|()
return|;
block|}
DECL|function|finishFence
name|void
name|Fence11
operator|::
name|finishFence
parameter_list|()
block|{
if|if
condition|(
name|mQuery
operator|==
name|NULL
condition|)
block|{
return|return
name|gl
operator|::
name|error
argument_list|(
name|GL_INVALID_OPERATION
argument_list|)
return|;
block|}
while|while
condition|(
operator|!
name|testFence
argument_list|()
condition|)
block|{
name|Sleep
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|getFenceiv
name|void
name|Fence11
operator|::
name|getFenceiv
parameter_list|(
name|GLenum
name|pname
parameter_list|,
name|GLint
modifier|*
name|params
parameter_list|)
block|{
if|if
condition|(
name|mQuery
operator|==
name|NULL
condition|)
block|{
return|return
name|gl
operator|::
name|error
argument_list|(
name|GL_INVALID_OPERATION
argument_list|)
return|;
block|}
switch|switch
condition|(
name|pname
condition|)
block|{
case|case
name|GL_FENCE_STATUS_NV
case|:
block|{
comment|// GL_NV_fence spec:
comment|// Once the status of a fence has been finished (via FinishFenceNV) or tested and the returned status is TRUE (via either TestFenceNV
comment|// or GetFenceivNV querying the FENCE_STATUS_NV), the status remains TRUE until the next SetFenceNV of the fence.
if|if
condition|(
name|getStatus
argument_list|()
condition|)
block|{
name|params
index|[
literal|0
index|]
operator|=
name|GL_TRUE
expr_stmt|;
return|return;
block|}
name|HRESULT
name|result
init|=
name|mRenderer
operator|->
name|getDeviceContext
argument_list|()
operator|->
name|GetData
argument_list|(
name|mQuery
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|D3D11_ASYNC_GETDATA_DONOTFLUSH
argument_list|)
decl_stmt|;
if|if
condition|(
name|mRenderer
operator|->
name|isDeviceLost
argument_list|()
condition|)
block|{
name|params
index|[
literal|0
index|]
operator|=
name|GL_TRUE
expr_stmt|;
return|return
name|gl
operator|::
name|error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|)
return|;
block|}
name|ASSERT
argument_list|(
name|result
operator|==
name|S_OK
operator|||
name|result
operator|==
name|S_FALSE
argument_list|)
expr_stmt|;
name|setStatus
argument_list|(
name|result
operator|==
name|S_OK
argument_list|)
expr_stmt|;
name|params
index|[
literal|0
index|]
operator|=
name|getStatus
argument_list|()
expr_stmt|;
break|break;
block|}
case|case
name|GL_FENCE_CONDITION_NV
case|:
name|params
index|[
literal|0
index|]
operator|=
name|getCondition
argument_list|()
expr_stmt|;
break|break;
default|default:
return|return
name|gl
operator|::
name|error
argument_list|(
name|GL_INVALID_ENUM
argument_list|)
return|;
break|break;
block|}
block|}
block|}
end_namespace
end_unit
