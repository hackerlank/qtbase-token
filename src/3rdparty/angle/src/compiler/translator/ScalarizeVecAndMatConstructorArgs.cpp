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
file|"common/debug.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/ScalarizeVecAndMatConstructorArgs.h"
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_namespace
namespace|namespace
block|{
DECL|function|ContainsMatrixNode
name|bool
name|ContainsMatrixNode
parameter_list|(
specifier|const
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
name|sequence
operator|.
name|size
argument_list|()
condition|;
operator|++
name|ii
control|)
block|{
name|TIntermTyped
modifier|*
name|node
init|=
name|sequence
index|[
name|ii
index|]
operator|->
name|getAsTyped
argument_list|()
decl_stmt|;
if|if
condition|(
name|node
operator|&&
name|node
operator|->
name|isMatrix
argument_list|()
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|ContainsVectorNode
name|bool
name|ContainsVectorNode
parameter_list|(
specifier|const
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
name|sequence
operator|.
name|size
argument_list|()
condition|;
operator|++
name|ii
control|)
block|{
name|TIntermTyped
modifier|*
name|node
init|=
name|sequence
index|[
name|ii
index|]
operator|->
name|getAsTyped
argument_list|()
decl_stmt|;
if|if
condition|(
name|node
operator|&&
name|node
operator|->
name|isVector
argument_list|()
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|ConstructIndexNode
name|TIntermConstantUnion
modifier|*
name|ConstructIndexNode
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|TConstantUnion
modifier|*
name|u
init|=
operator|new
name|TConstantUnion
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
DECL|function|ConstructVectorIndexBinaryNode
name|TIntermBinary
modifier|*
name|ConstructVectorIndexBinaryNode
parameter_list|(
name|TIntermSymbol
modifier|*
name|symbolNode
parameter_list|,
name|int
name|index
parameter_list|)
block|{
name|TIntermBinary
modifier|*
name|binary
init|=
operator|new
name|TIntermBinary
argument_list|(
name|EOpIndexDirect
argument_list|)
decl_stmt|;
name|binary
operator|->
name|setLeft
argument_list|(
name|symbolNode
argument_list|)
expr_stmt|;
name|TIntermConstantUnion
modifier|*
name|indexNode
init|=
name|ConstructIndexNode
argument_list|(
name|index
argument_list|)
decl_stmt|;
name|binary
operator|->
name|setRight
argument_list|(
name|indexNode
argument_list|)
expr_stmt|;
return|return
name|binary
return|;
block|}
DECL|function|ConstructMatrixIndexBinaryNode
name|TIntermBinary
modifier|*
name|ConstructMatrixIndexBinaryNode
parameter_list|(
name|TIntermSymbol
modifier|*
name|symbolNode
parameter_list|,
name|int
name|colIndex
parameter_list|,
name|int
name|rowIndex
parameter_list|)
block|{
name|TIntermBinary
modifier|*
name|colVectorNode
init|=
name|ConstructVectorIndexBinaryNode
argument_list|(
name|symbolNode
argument_list|,
name|colIndex
argument_list|)
decl_stmt|;
name|TIntermBinary
modifier|*
name|binary
init|=
operator|new
name|TIntermBinary
argument_list|(
name|EOpIndexDirect
argument_list|)
decl_stmt|;
name|binary
operator|->
name|setLeft
argument_list|(
name|colVectorNode
argument_list|)
expr_stmt|;
name|TIntermConstantUnion
modifier|*
name|rowIndexNode
init|=
name|ConstructIndexNode
argument_list|(
name|rowIndex
argument_list|)
decl_stmt|;
name|binary
operator|->
name|setRight
argument_list|(
name|rowIndexNode
argument_list|)
expr_stmt|;
return|return
name|binary
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
name|ScalarizeVecAndMatConstructorArgs
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
if|if
condition|(
name|visit
operator|==
name|PreVisit
condition|)
block|{
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
name|mSequenceStack
operator|.
name|push_back
argument_list|(
name|TIntermSequence
argument_list|()
argument_list|)
expr_stmt|;
block|{
for|for
control|(
name|TIntermSequence
operator|::
name|const_iterator
name|iter
init|=
name|node
operator|->
name|getSequence
argument_list|()
operator|->
name|begin
argument_list|()
init|;
name|iter
operator|!=
name|node
operator|->
name|getSequence
argument_list|()
operator|->
name|end
argument_list|()
condition|;
operator|++
name|iter
control|)
block|{
name|TIntermNode
modifier|*
name|child
init|=
operator|*
name|iter
decl_stmt|;
name|ASSERT
argument_list|(
name|child
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|child
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|mSequenceStack
operator|.
name|back
argument_list|()
operator|.
name|push_back
argument_list|(
name|child
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|mSequenceStack
operator|.
name|back
argument_list|()
operator|.
name|size
argument_list|()
operator|>
name|node
operator|->
name|getSequence
argument_list|()
operator|->
name|size
argument_list|()
condition|)
block|{
name|node
operator|->
name|getSequence
argument_list|()
operator|->
name|clear
argument_list|()
expr_stmt|;
operator|*
operator|(
name|node
operator|->
name|getSequence
argument_list|()
operator|)
operator|=
name|mSequenceStack
operator|.
name|back
argument_list|()
expr_stmt|;
block|}
name|mSequenceStack
operator|.
name|pop_back
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
case|case
name|EOpConstructVec2
case|:
case|case
name|EOpConstructVec3
case|:
case|case
name|EOpConstructVec4
case|:
case|case
name|EOpConstructBVec2
case|:
case|case
name|EOpConstructBVec3
case|:
case|case
name|EOpConstructBVec4
case|:
case|case
name|EOpConstructIVec2
case|:
case|case
name|EOpConstructIVec3
case|:
case|case
name|EOpConstructIVec4
case|:
if|if
condition|(
name|ContainsMatrixNode
argument_list|(
operator|*
operator|(
name|node
operator|->
name|getSequence
argument_list|()
operator|)
argument_list|)
condition|)
name|scalarizeArgs
argument_list|(
name|node
argument_list|,
literal|false
argument_list|,
literal|true
argument_list|)
expr_stmt|;
break|break;
case|case
name|EOpConstructMat2
case|:
case|case
name|EOpConstructMat2x3
case|:
case|case
name|EOpConstructMat2x4
case|:
case|case
name|EOpConstructMat3x2
case|:
case|case
name|EOpConstructMat3
case|:
case|case
name|EOpConstructMat3x4
case|:
case|case
name|EOpConstructMat4x2
case|:
case|case
name|EOpConstructMat4x3
case|:
case|case
name|EOpConstructMat4
case|:
if|if
condition|(
name|ContainsVectorNode
argument_list|(
operator|*
operator|(
name|node
operator|->
name|getSequence
argument_list|()
operator|)
argument_list|)
condition|)
name|scalarizeArgs
argument_list|(
name|node
argument_list|,
literal|true
argument_list|,
literal|false
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|scalarizeArgs
name|void
name|ScalarizeVecAndMatConstructorArgs
operator|::
name|scalarizeArgs
parameter_list|(
name|TIntermAggregate
modifier|*
name|aggregate
parameter_list|,
name|bool
name|scalarizeVector
parameter_list|,
name|bool
name|scalarizeMatrix
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|aggregate
argument_list|)
expr_stmt|;
name|int
name|size
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|aggregate
operator|->
name|getOp
argument_list|()
condition|)
block|{
case|case
name|EOpConstructVec2
case|:
case|case
name|EOpConstructBVec2
case|:
case|case
name|EOpConstructIVec2
case|:
name|size
operator|=
literal|2
expr_stmt|;
break|break;
case|case
name|EOpConstructVec3
case|:
case|case
name|EOpConstructBVec3
case|:
case|case
name|EOpConstructIVec3
case|:
name|size
operator|=
literal|3
expr_stmt|;
break|break;
case|case
name|EOpConstructVec4
case|:
case|case
name|EOpConstructBVec4
case|:
case|case
name|EOpConstructIVec4
case|:
case|case
name|EOpConstructMat2
case|:
name|size
operator|=
literal|4
expr_stmt|;
break|break;
case|case
name|EOpConstructMat2x3
case|:
case|case
name|EOpConstructMat3x2
case|:
name|size
operator|=
literal|6
expr_stmt|;
break|break;
case|case
name|EOpConstructMat2x4
case|:
case|case
name|EOpConstructMat4x2
case|:
name|size
operator|=
literal|8
expr_stmt|;
break|break;
case|case
name|EOpConstructMat3
case|:
name|size
operator|=
literal|9
expr_stmt|;
break|break;
case|case
name|EOpConstructMat3x4
case|:
case|case
name|EOpConstructMat4x3
case|:
name|size
operator|=
literal|12
expr_stmt|;
break|break;
case|case
name|EOpConstructMat4
case|:
name|size
operator|=
literal|16
expr_stmt|;
break|break;
default|default:
break|break;
block|}
name|TIntermSequence
modifier|*
name|sequence
init|=
name|aggregate
operator|->
name|getSequence
argument_list|()
decl_stmt|;
name|TIntermSequence
name|original
argument_list|(
operator|*
name|sequence
argument_list|)
decl_stmt|;
name|sequence
operator|->
name|clear
argument_list|()
expr_stmt|;
for|for
control|(
name|size_t
name|ii
init|=
literal|0
init|;
name|ii
operator|<
name|original
operator|.
name|size
argument_list|()
condition|;
operator|++
name|ii
control|)
block|{
name|ASSERT
argument_list|(
name|size
operator|>
literal|0
argument_list|)
expr_stmt|;
name|TIntermTyped
modifier|*
name|node
init|=
name|original
index|[
name|ii
index|]
operator|->
name|getAsTyped
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|node
argument_list|)
expr_stmt|;
name|TString
name|varName
init|=
name|createTempVariable
argument_list|(
name|node
argument_list|)
decl_stmt|;
if|if
condition|(
name|node
operator|->
name|isScalar
argument_list|()
condition|)
block|{
name|TIntermSymbol
modifier|*
name|symbolNode
init|=
operator|new
name|TIntermSymbol
argument_list|(
operator|-
literal|1
argument_list|,
name|varName
argument_list|,
name|node
operator|->
name|getType
argument_list|()
argument_list|)
decl_stmt|;
name|sequence
operator|->
name|push_back
argument_list|(
name|symbolNode
argument_list|)
expr_stmt|;
name|size
operator|--
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|node
operator|->
name|isVector
argument_list|()
condition|)
block|{
if|if
condition|(
name|scalarizeVector
condition|)
block|{
name|int
name|repeat
init|=
name|std
operator|::
name|min
argument_list|(
name|size
argument_list|,
name|node
operator|->
name|getNominalSize
argument_list|()
argument_list|)
decl_stmt|;
name|size
operator|-=
name|repeat
expr_stmt|;
for|for
control|(
name|int
name|index
init|=
literal|0
init|;
name|index
operator|<
name|repeat
condition|;
operator|++
name|index
control|)
block|{
name|TIntermSymbol
modifier|*
name|symbolNode
init|=
operator|new
name|TIntermSymbol
argument_list|(
operator|-
literal|1
argument_list|,
name|varName
argument_list|,
name|node
operator|->
name|getType
argument_list|()
argument_list|)
decl_stmt|;
name|TIntermBinary
modifier|*
name|newNode
init|=
name|ConstructVectorIndexBinaryNode
argument_list|(
name|symbolNode
argument_list|,
name|index
argument_list|)
decl_stmt|;
name|sequence
operator|->
name|push_back
argument_list|(
name|newNode
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|TIntermSymbol
modifier|*
name|symbolNode
init|=
operator|new
name|TIntermSymbol
argument_list|(
operator|-
literal|1
argument_list|,
name|varName
argument_list|,
name|node
operator|->
name|getType
argument_list|()
argument_list|)
decl_stmt|;
name|sequence
operator|->
name|push_back
argument_list|(
name|symbolNode
argument_list|)
expr_stmt|;
name|size
operator|-=
name|node
operator|->
name|getNominalSize
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|ASSERT
argument_list|(
name|node
operator|->
name|isMatrix
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|scalarizeMatrix
condition|)
block|{
name|int
name|colIndex
init|=
literal|0
decl_stmt|,
name|rowIndex
init|=
literal|0
decl_stmt|;
name|int
name|repeat
init|=
name|std
operator|::
name|min
argument_list|(
name|size
argument_list|,
name|node
operator|->
name|getCols
argument_list|()
operator|*
name|node
operator|->
name|getRows
argument_list|()
argument_list|)
decl_stmt|;
name|size
operator|-=
name|repeat
expr_stmt|;
while|while
condition|(
name|repeat
operator|>
literal|0
condition|)
block|{
name|TIntermSymbol
modifier|*
name|symbolNode
init|=
operator|new
name|TIntermSymbol
argument_list|(
operator|-
literal|1
argument_list|,
name|varName
argument_list|,
name|node
operator|->
name|getType
argument_list|()
argument_list|)
decl_stmt|;
name|TIntermBinary
modifier|*
name|newNode
init|=
name|ConstructMatrixIndexBinaryNode
argument_list|(
name|symbolNode
argument_list|,
name|colIndex
argument_list|,
name|rowIndex
argument_list|)
decl_stmt|;
name|sequence
operator|->
name|push_back
argument_list|(
name|newNode
argument_list|)
expr_stmt|;
name|rowIndex
operator|++
expr_stmt|;
if|if
condition|(
name|rowIndex
operator|>=
name|node
operator|->
name|getRows
argument_list|()
condition|)
block|{
name|rowIndex
operator|=
literal|0
expr_stmt|;
name|colIndex
operator|++
expr_stmt|;
block|}
name|repeat
operator|--
expr_stmt|;
block|}
block|}
else|else
block|{
name|TIntermSymbol
modifier|*
name|symbolNode
init|=
operator|new
name|TIntermSymbol
argument_list|(
operator|-
literal|1
argument_list|,
name|varName
argument_list|,
name|node
operator|->
name|getType
argument_list|()
argument_list|)
decl_stmt|;
name|sequence
operator|->
name|push_back
argument_list|(
name|symbolNode
argument_list|)
expr_stmt|;
name|size
operator|-=
name|node
operator|->
name|getCols
argument_list|()
operator|*
name|node
operator|->
name|getRows
argument_list|()
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|createTempVariable
name|TString
name|ScalarizeVecAndMatConstructorArgs
operator|::
name|createTempVariable
parameter_list|(
name|TIntermTyped
modifier|*
name|original
parameter_list|)
block|{
name|TString
name|tempVarName
init|=
literal|"_webgl_tmp_"
decl_stmt|;
if|if
condition|(
name|original
operator|->
name|isScalar
argument_list|()
condition|)
block|{
name|tempVarName
operator|+=
literal|"scalar_"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|original
operator|->
name|isVector
argument_list|()
condition|)
block|{
name|tempVarName
operator|+=
literal|"vec_"
expr_stmt|;
block|}
else|else
block|{
name|ASSERT
argument_list|(
name|original
operator|->
name|isMatrix
argument_list|()
argument_list|)
expr_stmt|;
name|tempVarName
operator|+=
literal|"mat_"
expr_stmt|;
block|}
name|tempVarName
operator|+=
name|Str
argument_list|(
name|mTempVarCount
argument_list|)
operator|.
name|c_str
argument_list|()
expr_stmt|;
name|mTempVarCount
operator|++
expr_stmt|;
name|ASSERT
argument_list|(
name|original
argument_list|)
expr_stmt|;
name|TType
name|type
init|=
name|original
operator|->
name|getType
argument_list|()
decl_stmt|;
name|type
operator|.
name|setQualifier
argument_list|(
name|EvqTemporary
argument_list|)
expr_stmt|;
if|if
condition|(
name|mShaderType
operator|==
name|GL_FRAGMENT_SHADER
operator|&&
name|type
operator|.
name|getBasicType
argument_list|()
operator|==
name|EbtFloat
operator|&&
name|type
operator|.
name|getPrecision
argument_list|()
operator|==
name|EbpUndefined
condition|)
block|{
comment|// We use the highest available precision for the temporary variable
comment|// to avoid computing the actual precision using the rules defined
comment|// in GLSL ES 1.0 Section 4.5.2.
name|type
operator|.
name|setPrecision
argument_list|(
name|mFragmentPrecisionHigh
condition|?
name|EbpHigh
else|:
name|EbpMedium
argument_list|)
expr_stmt|;
block|}
name|TIntermBinary
modifier|*
name|init
init|=
operator|new
name|TIntermBinary
argument_list|(
name|EOpInitialize
argument_list|)
decl_stmt|;
name|TIntermSymbol
modifier|*
name|symbolNode
init|=
operator|new
name|TIntermSymbol
argument_list|(
operator|-
literal|1
argument_list|,
name|tempVarName
argument_list|,
name|type
argument_list|)
decl_stmt|;
name|init
operator|->
name|setLeft
argument_list|(
name|symbolNode
argument_list|)
expr_stmt|;
name|init
operator|->
name|setRight
argument_list|(
name|original
argument_list|)
expr_stmt|;
name|init
operator|->
name|setType
argument_list|(
name|type
argument_list|)
expr_stmt|;
name|TIntermAggregate
modifier|*
name|decl
init|=
operator|new
name|TIntermAggregate
argument_list|(
name|EOpDeclaration
argument_list|)
decl_stmt|;
name|decl
operator|->
name|getSequence
argument_list|()
operator|->
name|push_back
argument_list|(
name|init
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|mSequenceStack
operator|.
name|size
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
name|TIntermSequence
modifier|&
name|sequence
init|=
name|mSequenceStack
operator|.
name|back
argument_list|()
decl_stmt|;
name|sequence
operator|.
name|push_back
argument_list|(
name|decl
argument_list|)
expr_stmt|;
return|return
name|tempVarName
return|;
block|}
end_function
end_unit
