begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2013 The ANGLE Project Authors. All rights reserved.
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
file|"compiler/translator/InitializeVariables.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/compilerdebug.h"
end_include
begin_namespace
namespace|namespace
block|{
DECL|function|constructFloatConstUnionNode
name|TIntermConstantUnion
modifier|*
name|constructFloatConstUnionNode
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|)
block|{
name|TType
name|myType
init|=
name|type
decl_stmt|;
name|unsigned
name|char
name|size
init|=
name|myType
operator|.
name|getNominalSize
argument_list|()
decl_stmt|;
if|if
condition|(
name|myType
operator|.
name|isMatrix
argument_list|()
condition|)
name|size
operator|*=
name|size
expr_stmt|;
name|ConstantUnion
modifier|*
name|u
init|=
operator|new
name|ConstantUnion
index|[
name|size
index|]
decl_stmt|;
for|for
control|(
name|int
name|ii
init|=
literal|0
init|;
name|ii
operator|<
name|size
condition|;
operator|++
name|ii
control|)
name|u
index|[
name|ii
index|]
operator|.
name|setFConst
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
name|myType
operator|.
name|clearArrayness
argument_list|()
expr_stmt|;
name|myType
operator|.
name|setQualifier
argument_list|(
name|EvqConst
argument_list|)
expr_stmt|;
name|TIntermConstantUnion
modifier|*
name|node
init|=
operator|new
name|TIntermConstantUnion
argument_list|(
name|u
argument_list|,
name|myType
argument_list|)
decl_stmt|;
return|return
name|node
return|;
block|}
DECL|function|constructIndexNode
name|TIntermConstantUnion
modifier|*
name|constructIndexNode
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|ConstantUnion
modifier|*
name|u
init|=
operator|new
name|ConstantUnion
index|[
literal|1
index|]
decl_stmt|;
name|u
index|[
literal|0
index|]
operator|.
name|setIConst
argument_list|(
name|index
argument_list|)
expr_stmt|;
name|TType
name|type
argument_list|(
name|EbtInt
argument_list|,
name|EbpUndefined
argument_list|,
name|EvqConst
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|TIntermConstantUnion
modifier|*
name|node
init|=
operator|new
name|TIntermConstantUnion
argument_list|(
name|u
argument_list|,
name|type
argument_list|)
decl_stmt|;
return|return
name|node
return|;
block|}
block|}
end_namespace
begin_comment
comment|// namespace anonymous
end_comment
begin_function
DECL|function|visitAggregate
name|bool
name|InitializeVariables
operator|::
name|visitAggregate
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
block|{
name|bool
name|visitChildren
init|=
operator|!
name|mCodeInserted
decl_stmt|;
switch|switch
condition|(
name|node
operator|->
name|getOp
argument_list|()
condition|)
block|{
case|case
name|EOpSequence
case|:
break|break;
case|case
name|EOpFunction
case|:
block|{
comment|// Function definition.
name|ASSERT
argument_list|(
name|visit
operator|==
name|PreVisit
argument_list|)
expr_stmt|;
if|if
condition|(
name|node
operator|->
name|getName
argument_list|()
operator|==
literal|"main("
condition|)
block|{
name|TIntermSequence
modifier|&
name|sequence
init|=
name|node
operator|->
name|getSequence
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
operator|(
name|sequence
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|)
operator|||
operator|(
name|sequence
operator|.
name|size
argument_list|()
operator|==
literal|2
operator|)
argument_list|)
expr_stmt|;
name|TIntermAggregate
modifier|*
name|body
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|sequence
operator|.
name|size
argument_list|()
operator|==
literal|1
condition|)
block|{
name|body
operator|=
operator|new
name|TIntermAggregate
argument_list|(
name|EOpSequence
argument_list|)
expr_stmt|;
name|sequence
operator|.
name|push_back
argument_list|(
name|body
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|body
operator|=
name|sequence
index|[
literal|1
index|]
operator|->
name|getAsAggregate
argument_list|()
expr_stmt|;
block|}
name|ASSERT
argument_list|(
name|body
argument_list|)
expr_stmt|;
name|insertInitCode
argument_list|(
name|body
operator|->
name|getSequence
argument_list|()
argument_list|)
expr_stmt|;
name|mCodeInserted
operator|=
literal|true
expr_stmt|;
block|}
break|break;
block|}
default|default:
name|visitChildren
operator|=
literal|false
expr_stmt|;
break|break;
block|}
return|return
name|visitChildren
return|;
block|}
end_function
begin_function
DECL|function|insertInitCode
name|void
name|InitializeVariables
operator|::
name|insertInitCode
parameter_list|(
name|TIntermSequence
modifier|&
name|sequence
parameter_list|)
block|{
for|for
control|(
name|size_t
name|ii
init|=
literal|0
init|;
name|ii
operator|<
name|mVariables
operator|.
name|size
argument_list|()
condition|;
operator|++
name|ii
control|)
block|{
specifier|const
name|InitVariableInfo
modifier|&
name|varInfo
init|=
name|mVariables
index|[
name|ii
index|]
decl_stmt|;
if|if
condition|(
name|varInfo
operator|.
name|type
operator|.
name|isArray
argument_list|()
condition|)
block|{
for|for
control|(
name|int
name|index
init|=
name|varInfo
operator|.
name|type
operator|.
name|getArraySize
argument_list|()
operator|-
literal|1
init|;
name|index
operator|>=
literal|0
condition|;
operator|--
name|index
control|)
block|{
name|TIntermBinary
modifier|*
name|assign
init|=
operator|new
name|TIntermBinary
argument_list|(
name|EOpAssign
argument_list|)
decl_stmt|;
name|sequence
operator|.
name|insert
argument_list|(
name|sequence
operator|.
name|begin
argument_list|()
argument_list|,
name|assign
argument_list|)
expr_stmt|;
name|TIntermBinary
modifier|*
name|indexDirect
init|=
operator|new
name|TIntermBinary
argument_list|(
name|EOpIndexDirect
argument_list|)
decl_stmt|;
name|TIntermSymbol
modifier|*
name|symbol
init|=
operator|new
name|TIntermSymbol
argument_list|(
literal|0
argument_list|,
name|varInfo
operator|.
name|name
argument_list|,
name|varInfo
operator|.
name|type
argument_list|)
decl_stmt|;
name|indexDirect
operator|->
name|setLeft
argument_list|(
name|symbol
argument_list|)
expr_stmt|;
name|TIntermConstantUnion
modifier|*
name|indexNode
init|=
name|constructIndexNode
argument_list|(
name|index
argument_list|)
decl_stmt|;
name|indexDirect
operator|->
name|setRight
argument_list|(
name|indexNode
argument_list|)
expr_stmt|;
name|assign
operator|->
name|setLeft
argument_list|(
name|indexDirect
argument_list|)
expr_stmt|;
name|TIntermConstantUnion
modifier|*
name|zeroConst
init|=
name|constructFloatConstUnionNode
argument_list|(
name|varInfo
operator|.
name|type
argument_list|)
decl_stmt|;
name|assign
operator|->
name|setRight
argument_list|(
name|zeroConst
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|TIntermBinary
modifier|*
name|assign
init|=
operator|new
name|TIntermBinary
argument_list|(
name|EOpAssign
argument_list|)
decl_stmt|;
name|sequence
operator|.
name|insert
argument_list|(
name|sequence
operator|.
name|begin
argument_list|()
argument_list|,
name|assign
argument_list|)
expr_stmt|;
name|TIntermSymbol
modifier|*
name|symbol
init|=
operator|new
name|TIntermSymbol
argument_list|(
literal|0
argument_list|,
name|varInfo
operator|.
name|name
argument_list|,
name|varInfo
operator|.
name|type
argument_list|)
decl_stmt|;
name|assign
operator|->
name|setLeft
argument_list|(
name|symbol
argument_list|)
expr_stmt|;
name|TIntermConstantUnion
modifier|*
name|zeroConst
init|=
name|constructFloatConstUnionNode
argument_list|(
name|varInfo
operator|.
name|type
argument_list|)
decl_stmt|;
name|assign
operator|->
name|setRight
argument_list|(
name|zeroConst
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
end_unit