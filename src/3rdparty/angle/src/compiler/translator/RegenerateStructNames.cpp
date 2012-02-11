begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2014 The ANGLE Project Authors. All rights reserved.
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
file|"compiler/translator/RegenerateStructNames.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/compilerdebug.h"
end_include
begin_function
DECL|function|visitSymbol
name|void
name|RegenerateStructNames
operator|::
name|visitSymbol
parameter_list|(
name|TIntermSymbol
modifier|*
name|symbol
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|symbol
argument_list|)
expr_stmt|;
name|TType
modifier|*
name|type
init|=
name|symbol
operator|->
name|getTypePointer
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|type
argument_list|)
expr_stmt|;
name|TStructure
modifier|*
name|userType
init|=
name|type
operator|->
name|getStruct
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|userType
condition|)
return|return;
if|if
condition|(
name|mSymbolTable
operator|.
name|findBuiltIn
argument_list|(
name|userType
operator|->
name|name
argument_list|()
argument_list|,
name|mShaderVersion
argument_list|)
condition|)
block|{
comment|// Built-in struct, do not touch it.
return|return;
block|}
name|int
name|uniqueId
init|=
name|userType
operator|->
name|uniqueId
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|mScopeDepth
operator|>
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|mScopeDepth
operator|==
literal|1
condition|)
block|{
comment|// If a struct is defined at global scope, we don't map its name.
comment|// This is because at global level, the struct might be used to
comment|// declare a uniform, so the same name needs to stay the same for
comment|// vertex/fragment shaders. However, our mapping uses internal ID,
comment|// which will be different for the same struct in vertex/fragment
comment|// shaders.
comment|// This is OK because names for any structs defined in other scopes
comment|// will begin with "_webgl", which is reserved. So there will be
comment|// no conflicts among unmapped struct names from global scope and
comment|// mapped struct names from other scopes.
comment|// However, we need to keep track of these global structs, so if a
comment|// variable is used in a local scope, we don't try to modify the
comment|// struct name through that variable.
name|mDeclaredGlobalStructs
operator|.
name|insert
argument_list|(
name|uniqueId
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|mDeclaredGlobalStructs
operator|.
name|count
argument_list|(
name|uniqueId
argument_list|)
operator|>
literal|0
condition|)
return|return;
comment|// Map {name} to _webgl_struct_{uniqueId}_{name}.
specifier|const
name|char
name|kPrefix
index|[]
init|=
literal|"_webgl_struct_"
decl_stmt|;
if|if
condition|(
name|userType
operator|->
name|name
argument_list|()
operator|.
name|find
argument_list|(
name|kPrefix
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|// The name has already been regenerated.
return|return;
block|}
name|std
operator|::
name|string
name|id
init|=
name|Str
argument_list|(
name|uniqueId
argument_list|)
decl_stmt|;
name|TString
name|tmp
init|=
name|kPrefix
operator|+
name|TString
argument_list|(
name|id
operator|.
name|c_str
argument_list|()
argument_list|)
decl_stmt|;
name|tmp
operator|+=
literal|"_"
operator|+
name|userType
operator|->
name|name
argument_list|()
expr_stmt|;
name|userType
operator|->
name|setName
argument_list|(
name|tmp
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|visitAggregate
name|bool
name|RegenerateStructNames
operator|::
name|visitAggregate
parameter_list|(
name|Visit
parameter_list|,
name|TIntermAggregate
modifier|*
name|aggregate
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|aggregate
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|aggregate
operator|->
name|getOp
argument_list|()
condition|)
block|{
case|case
name|EOpSequence
case|:
operator|++
name|mScopeDepth
expr_stmt|;
block|{
name|TIntermSequence
modifier|&
name|sequence
init|=
operator|*
operator|(
name|aggregate
operator|->
name|getSequence
argument_list|()
operator|)
decl_stmt|;
for|for
control|(
name|size_t
name|ii
init|=
literal|0
init|;
name|ii
operator|<
name|sequence
operator|.
name|size
argument_list|()
condition|;
operator|++
name|ii
control|)
block|{
name|TIntermNode
modifier|*
name|node
init|=
name|sequence
index|[
name|ii
index|]
decl_stmt|;
name|ASSERT
argument_list|(
name|node
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|node
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
block|}
operator|--
name|mScopeDepth
expr_stmt|;
return|return
literal|false
return|;
default|default:
return|return
literal|true
return|;
block|}
block|}
end_function
end_unit