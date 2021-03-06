begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2015 The ANGLE Project Authors. All rights reserved.
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
comment|// Analysis of the AST needed for HLSL generation
end_comment
begin_include
include|#
directive|include
file|"compiler/translator/ASTMetadataHLSL.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/CallDAG.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/SymbolTable.h"
end_include
begin_namespace
namespace|namespace
block|{
comment|// Class used to traverse the AST of a function definition, checking if the
comment|// function uses a gradient, and writing the set of control flow using gradients.
comment|// It assumes that the analysis has already been made for the function's
comment|// callees.
DECL|class|PullGradient
class|class
name|PullGradient
super|:
specifier|public
name|TIntermTraverser
block|{
public|public:
DECL|function|PullGradient
name|PullGradient
parameter_list|(
name|MetadataList
modifier|*
name|metadataList
parameter_list|,
name|size_t
name|index
parameter_list|,
specifier|const
name|CallDAG
modifier|&
name|dag
parameter_list|)
member_init_list|:
name|TIntermTraverser
argument_list|(
literal|true
argument_list|,
literal|false
argument_list|,
literal|true
argument_list|)
member_init_list|,
name|mMetadataList
argument_list|(
name|metadataList
argument_list|)
member_init_list|,
name|mMetadata
argument_list|(
operator|&
operator|(
operator|*
name|metadataList
operator|)
index|[
name|index
index|]
argument_list|)
member_init_list|,
name|mIndex
argument_list|(
name|index
argument_list|)
member_init_list|,
name|mDag
argument_list|(
name|dag
argument_list|)
block|{
name|ASSERT
argument_list|(
name|index
operator|<
name|metadataList
operator|->
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
DECL|function|traverse
name|void
name|traverse
parameter_list|(
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
block|{
name|node
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|mParents
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Called when a gradient operation or a call to a function using a gradient is found.
DECL|function|onGradient
name|void
name|onGradient
parameter_list|()
block|{
name|mMetadata
operator|->
name|mUsesGradient
operator|=
literal|true
expr_stmt|;
comment|// Mark the latest control flow as using a gradient.
if|if
condition|(
operator|!
name|mParents
operator|.
name|empty
argument_list|()
condition|)
block|{
name|mMetadata
operator|->
name|mControlFlowsContainingGradient
operator|.
name|insert
argument_list|(
name|mParents
operator|.
name|back
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|visitControlFlow
name|void
name|visitControlFlow
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermNode
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
name|mParents
operator|.
name|push_back
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|visit
operator|==
name|PostVisit
condition|)
block|{
name|ASSERT
argument_list|(
name|mParents
operator|.
name|back
argument_list|()
operator|==
name|node
argument_list|)
expr_stmt|;
name|mParents
operator|.
name|pop_back
argument_list|()
expr_stmt|;
comment|// A control flow's using a gradient means its parents are too.
if|if
condition|(
name|mMetadata
operator|->
name|mControlFlowsContainingGradient
operator|.
name|count
argument_list|(
name|node
argument_list|)
operator|>
literal|0
operator|&&
operator|!
name|mParents
operator|.
name|empty
argument_list|()
condition|)
block|{
name|mMetadata
operator|->
name|mControlFlowsContainingGradient
operator|.
name|insert
argument_list|(
name|mParents
operator|.
name|back
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
name|bool
name|visitLoop
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermLoop
modifier|*
name|loop
parameter_list|)
specifier|override
block|{
name|visitControlFlow
argument_list|(
name|visit
argument_list|,
name|loop
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
name|bool
name|visitSelection
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermSelection
modifier|*
name|selection
parameter_list|)
specifier|override
block|{
name|visitControlFlow
argument_list|(
name|visit
argument_list|,
name|selection
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
name|bool
name|visitUnary
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermUnary
modifier|*
name|node
parameter_list|)
specifier|override
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
name|EOpDFdx
case|:
case|case
name|EOpDFdy
case|:
name|onGradient
argument_list|()
expr_stmt|;
default|default:
break|break;
block|}
block|}
return|return
literal|true
return|;
block|}
name|bool
name|visitAggregate
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
specifier|override
block|{
if|if
condition|(
name|visit
operator|==
name|PreVisit
condition|)
block|{
if|if
condition|(
name|node
operator|->
name|getOp
argument_list|()
operator|==
name|EOpFunctionCall
condition|)
block|{
if|if
condition|(
name|node
operator|->
name|isUserDefined
argument_list|()
condition|)
block|{
name|size_t
name|calleeIndex
init|=
name|mDag
operator|.
name|findIndex
argument_list|(
name|node
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|calleeIndex
operator|!=
name|CallDAG
operator|::
name|InvalidIndex
operator|&&
name|calleeIndex
operator|<
name|mIndex
argument_list|)
expr_stmt|;
name|UNUSED_ASSERTION_VARIABLE
argument_list|(
name|mIndex
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|mMetadataList
operator|)
index|[
name|calleeIndex
index|]
operator|.
name|mUsesGradient
condition|)
block|{
name|onGradient
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|TString
name|name
init|=
name|TFunction
operator|::
name|unmangleName
argument_list|(
name|node
operator|->
name|getName
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|name
operator|==
literal|"texture2D"
operator|||
name|name
operator|==
literal|"texture2DProj"
operator|||
name|name
operator|==
literal|"textureCube"
condition|)
block|{
name|onGradient
argument_list|()
expr_stmt|;
block|}
block|}
block|}
block|}
return|return
literal|true
return|;
block|}
private|private:
DECL|member|mMetadataList
name|MetadataList
modifier|*
name|mMetadataList
decl_stmt|;
DECL|member|mMetadata
name|ASTMetadataHLSL
modifier|*
name|mMetadata
decl_stmt|;
DECL|member|mIndex
name|size_t
name|mIndex
decl_stmt|;
DECL|member|mDag
specifier|const
name|CallDAG
modifier|&
name|mDag
decl_stmt|;
comment|// Contains a stack of the control flow nodes that are parents of the node being
comment|// currently visited. It is used to mark control flows using a gradient.
DECL|member|mParents
name|std
operator|::
name|vector
argument_list|<
name|TIntermNode
modifier|*
argument_list|>
name|mParents
decl_stmt|;
block|}
class|;
comment|// Traverses the AST of a function definition to compute the the discontinuous loops
comment|// and the if statements containing gradient loops. It assumes that the gradient loops
comment|// (loops that contain a gradient) have already been computed and that it has already
comment|// traversed the current function's callees.
DECL|class|PullComputeDiscontinuousAndGradientLoops
class|class
name|PullComputeDiscontinuousAndGradientLoops
super|:
specifier|public
name|TIntermTraverser
block|{
public|public:
DECL|function|PullComputeDiscontinuousAndGradientLoops
name|PullComputeDiscontinuousAndGradientLoops
parameter_list|(
name|MetadataList
modifier|*
name|metadataList
parameter_list|,
name|size_t
name|index
parameter_list|,
specifier|const
name|CallDAG
modifier|&
name|dag
parameter_list|)
member_init_list|:
name|TIntermTraverser
argument_list|(
literal|true
argument_list|,
literal|false
argument_list|,
literal|true
argument_list|)
member_init_list|,
name|mMetadataList
argument_list|(
name|metadataList
argument_list|)
member_init_list|,
name|mMetadata
argument_list|(
operator|&
operator|(
operator|*
name|metadataList
operator|)
index|[
name|index
index|]
argument_list|)
member_init_list|,
name|mIndex
argument_list|(
name|index
argument_list|)
member_init_list|,
name|mDag
argument_list|(
name|dag
argument_list|)
block|{     }
DECL|function|traverse
name|void
name|traverse
parameter_list|(
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
block|{
name|node
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|mLoopsAndSwitches
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|mIfs
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Called when traversing a gradient loop or a call to a function with a
comment|// gradient loop in its call graph.
DECL|function|onGradientLoop
name|void
name|onGradientLoop
parameter_list|()
block|{
name|mMetadata
operator|->
name|mHasGradientLoopInCallGraph
operator|=
literal|true
expr_stmt|;
comment|// Mark the latest if as using a discontinuous loop.
if|if
condition|(
operator|!
name|mIfs
operator|.
name|empty
argument_list|()
condition|)
block|{
name|mMetadata
operator|->
name|mIfsContainingGradientLoop
operator|.
name|insert
argument_list|(
name|mIfs
operator|.
name|back
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
name|bool
name|visitLoop
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermLoop
modifier|*
name|loop
parameter_list|)
specifier|override
block|{
if|if
condition|(
name|visit
operator|==
name|PreVisit
condition|)
block|{
name|mLoopsAndSwitches
operator|.
name|push_back
argument_list|(
name|loop
argument_list|)
expr_stmt|;
if|if
condition|(
name|mMetadata
operator|->
name|hasGradientInCallGraph
argument_list|(
name|loop
argument_list|)
condition|)
block|{
name|onGradientLoop
argument_list|()
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|visit
operator|==
name|PostVisit
condition|)
block|{
name|ASSERT
argument_list|(
name|mLoopsAndSwitches
operator|.
name|back
argument_list|()
operator|==
name|loop
argument_list|)
expr_stmt|;
name|mLoopsAndSwitches
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
name|bool
name|visitSelection
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermSelection
modifier|*
name|node
parameter_list|)
specifier|override
block|{
if|if
condition|(
name|visit
operator|==
name|PreVisit
condition|)
block|{
name|mIfs
operator|.
name|push_back
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|visit
operator|==
name|PostVisit
condition|)
block|{
name|ASSERT
argument_list|(
name|mIfs
operator|.
name|back
argument_list|()
operator|==
name|node
argument_list|)
expr_stmt|;
name|mIfs
operator|.
name|pop_back
argument_list|()
expr_stmt|;
comment|// An if using a discontinuous loop means its parents ifs are also discontinuous.
if|if
condition|(
name|mMetadata
operator|->
name|mIfsContainingGradientLoop
operator|.
name|count
argument_list|(
name|node
argument_list|)
operator|>
literal|0
operator|&&
operator|!
name|mIfs
operator|.
name|empty
argument_list|()
condition|)
block|{
name|mMetadata
operator|->
name|mIfsContainingGradientLoop
operator|.
name|insert
argument_list|(
name|mIfs
operator|.
name|back
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
return|return
literal|true
return|;
block|}
name|bool
name|visitBranch
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermBranch
modifier|*
name|node
parameter_list|)
specifier|override
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
name|getFlowOp
argument_list|()
condition|)
block|{
case|case
name|EOpBreak
case|:
block|{
name|ASSERT
argument_list|(
operator|!
name|mLoopsAndSwitches
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
name|TIntermLoop
modifier|*
name|loop
init|=
name|mLoopsAndSwitches
operator|.
name|back
argument_list|()
operator|->
name|getAsLoopNode
argument_list|()
decl_stmt|;
if|if
condition|(
name|loop
operator|!=
literal|nullptr
condition|)
block|{
name|mMetadata
operator|->
name|mDiscontinuousLoops
operator|.
name|insert
argument_list|(
name|loop
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
name|EOpContinue
case|:
block|{
name|ASSERT
argument_list|(
operator|!
name|mLoopsAndSwitches
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
name|TIntermLoop
modifier|*
name|loop
init|=
literal|nullptr
decl_stmt|;
name|size_t
name|i
init|=
name|mLoopsAndSwitches
operator|.
name|size
argument_list|()
decl_stmt|;
while|while
condition|(
name|loop
operator|==
literal|nullptr
operator|&&
name|i
operator|>
literal|0
condition|)
block|{
operator|--
name|i
expr_stmt|;
name|loop
operator|=
name|mLoopsAndSwitches
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|getAsLoopNode
argument_list|()
expr_stmt|;
block|}
name|ASSERT
argument_list|(
name|loop
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
name|mMetadata
operator|->
name|mDiscontinuousLoops
operator|.
name|insert
argument_list|(
name|loop
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|EOpKill
case|:
case|case
name|EOpReturn
case|:
comment|// A return or discard jumps out of all the enclosing loops
if|if
condition|(
operator|!
name|mLoopsAndSwitches
operator|.
name|empty
argument_list|()
condition|)
block|{
for|for
control|(
name|TIntermNode
modifier|*
name|intermNode
range|:
name|mLoopsAndSwitches
control|)
block|{
name|TIntermLoop
modifier|*
name|loop
init|=
name|intermNode
operator|->
name|getAsLoopNode
argument_list|()
decl_stmt|;
if|if
condition|(
name|loop
condition|)
block|{
name|mMetadata
operator|->
name|mDiscontinuousLoops
operator|.
name|insert
argument_list|(
name|loop
argument_list|)
expr_stmt|;
block|}
block|}
block|}
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
block|}
return|return
literal|true
return|;
block|}
name|bool
name|visitAggregate
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
specifier|override
block|{
if|if
condition|(
name|visit
operator|==
name|PreVisit
operator|&&
name|node
operator|->
name|getOp
argument_list|()
operator|==
name|EOpFunctionCall
condition|)
block|{
if|if
condition|(
name|node
operator|->
name|isUserDefined
argument_list|()
condition|)
block|{
name|size_t
name|calleeIndex
init|=
name|mDag
operator|.
name|findIndex
argument_list|(
name|node
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|calleeIndex
operator|!=
name|CallDAG
operator|::
name|InvalidIndex
operator|&&
name|calleeIndex
operator|<
name|mIndex
argument_list|)
expr_stmt|;
name|UNUSED_ASSERTION_VARIABLE
argument_list|(
name|mIndex
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|mMetadataList
operator|)
index|[
name|calleeIndex
index|]
operator|.
name|mHasGradientLoopInCallGraph
condition|)
block|{
name|onGradientLoop
argument_list|()
expr_stmt|;
block|}
block|}
block|}
return|return
literal|true
return|;
block|}
name|bool
name|visitSwitch
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermSwitch
modifier|*
name|node
parameter_list|)
specifier|override
block|{
if|if
condition|(
name|visit
operator|==
name|PreVisit
condition|)
block|{
name|mLoopsAndSwitches
operator|.
name|push_back
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|visit
operator|==
name|PostVisit
condition|)
block|{
name|ASSERT
argument_list|(
name|mLoopsAndSwitches
operator|.
name|back
argument_list|()
operator|==
name|node
argument_list|)
expr_stmt|;
name|mLoopsAndSwitches
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
private|private:
DECL|member|mMetadataList
name|MetadataList
modifier|*
name|mMetadataList
decl_stmt|;
DECL|member|mMetadata
name|ASTMetadataHLSL
modifier|*
name|mMetadata
decl_stmt|;
DECL|member|mIndex
name|size_t
name|mIndex
decl_stmt|;
DECL|member|mDag
specifier|const
name|CallDAG
modifier|&
name|mDag
decl_stmt|;
DECL|member|mLoopsAndSwitches
name|std
operator|::
name|vector
argument_list|<
name|TIntermNode
modifier|*
argument_list|>
name|mLoopsAndSwitches
decl_stmt|;
DECL|member|mIfs
name|std
operator|::
name|vector
argument_list|<
name|TIntermSelection
modifier|*
argument_list|>
name|mIfs
decl_stmt|;
block|}
class|;
comment|// Tags all the functions called in a discontinuous loop
DECL|class|PushDiscontinuousLoops
class|class
name|PushDiscontinuousLoops
super|:
specifier|public
name|TIntermTraverser
block|{
public|public:
DECL|function|PushDiscontinuousLoops
name|PushDiscontinuousLoops
parameter_list|(
name|MetadataList
modifier|*
name|metadataList
parameter_list|,
name|size_t
name|index
parameter_list|,
specifier|const
name|CallDAG
modifier|&
name|dag
parameter_list|)
member_init_list|:
name|TIntermTraverser
argument_list|(
literal|true
argument_list|,
literal|true
argument_list|,
literal|true
argument_list|)
member_init_list|,
name|mMetadataList
argument_list|(
name|metadataList
argument_list|)
member_init_list|,
name|mMetadata
argument_list|(
operator|&
operator|(
operator|*
name|metadataList
operator|)
index|[
name|index
index|]
argument_list|)
member_init_list|,
name|mIndex
argument_list|(
name|index
argument_list|)
member_init_list|,
name|mDag
argument_list|(
name|dag
argument_list|)
member_init_list|,
name|mNestedDiscont
argument_list|(
name|mMetadata
operator|->
name|mCalledInDiscontinuousLoop
condition|?
literal|1
else|:
literal|0
argument_list|)
block|{     }
DECL|function|traverse
name|void
name|traverse
parameter_list|(
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
block|{
name|node
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|mNestedDiscont
operator|==
operator|(
name|mMetadata
operator|->
name|mCalledInDiscontinuousLoop
condition|?
literal|1
else|:
literal|0
operator|)
argument_list|)
expr_stmt|;
block|}
name|bool
name|visitLoop
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermLoop
modifier|*
name|loop
parameter_list|)
specifier|override
block|{
name|bool
name|isDiscontinuous
init|=
name|mMetadata
operator|->
name|mDiscontinuousLoops
operator|.
name|count
argument_list|(
name|loop
argument_list|)
operator|>
literal|0
decl_stmt|;
if|if
condition|(
name|visit
operator|==
name|PreVisit
operator|&&
name|isDiscontinuous
condition|)
block|{
name|mNestedDiscont
operator|++
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|visit
operator|==
name|PostVisit
operator|&&
name|isDiscontinuous
condition|)
block|{
name|mNestedDiscont
operator|--
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
name|bool
name|visitAggregate
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
specifier|override
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
name|EOpFunctionCall
case|:
if|if
condition|(
name|visit
operator|==
name|PreVisit
operator|&&
name|node
operator|->
name|isUserDefined
argument_list|()
operator|&&
name|mNestedDiscont
operator|>
literal|0
condition|)
block|{
name|size_t
name|calleeIndex
init|=
name|mDag
operator|.
name|findIndex
argument_list|(
name|node
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|calleeIndex
operator|!=
name|CallDAG
operator|::
name|InvalidIndex
operator|&&
name|calleeIndex
operator|<
name|mIndex
argument_list|)
expr_stmt|;
name|UNUSED_ASSERTION_VARIABLE
argument_list|(
name|mIndex
argument_list|)
expr_stmt|;
operator|(
operator|*
name|mMetadataList
operator|)
index|[
name|calleeIndex
index|]
operator|.
name|mCalledInDiscontinuousLoop
operator|=
literal|true
expr_stmt|;
block|}
break|break;
default|default:
break|break;
block|}
return|return
literal|true
return|;
block|}
private|private:
DECL|member|mMetadataList
name|MetadataList
modifier|*
name|mMetadataList
decl_stmt|;
DECL|member|mMetadata
name|ASTMetadataHLSL
modifier|*
name|mMetadata
decl_stmt|;
DECL|member|mIndex
name|size_t
name|mIndex
decl_stmt|;
DECL|member|mDag
specifier|const
name|CallDAG
modifier|&
name|mDag
decl_stmt|;
DECL|member|mNestedDiscont
name|int
name|mNestedDiscont
decl_stmt|;
block|}
class|;
block|}
end_namespace
begin_function
DECL|function|hasGradientInCallGraph
name|bool
name|ASTMetadataHLSL
operator|::
name|hasGradientInCallGraph
parameter_list|(
name|TIntermLoop
modifier|*
name|node
parameter_list|)
block|{
return|return
name|mControlFlowsContainingGradient
operator|.
name|count
argument_list|(
name|node
argument_list|)
operator|>
literal|0
return|;
block|}
end_function
begin_function
DECL|function|hasGradientLoop
name|bool
name|ASTMetadataHLSL
operator|::
name|hasGradientLoop
parameter_list|(
name|TIntermSelection
modifier|*
name|node
parameter_list|)
block|{
return|return
name|mIfsContainingGradientLoop
operator|.
name|count
argument_list|(
name|node
argument_list|)
operator|>
literal|0
return|;
block|}
end_function
begin_function
DECL|function|CreateASTMetadataHLSL
name|MetadataList
name|CreateASTMetadataHLSL
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|,
specifier|const
name|CallDAG
modifier|&
name|callDag
parameter_list|)
block|{
name|MetadataList
name|metadataList
argument_list|(
name|callDag
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
comment|// Compute all the information related to when gradient operations are used.
comment|// We want to know for each function and control flow operation if they have
comment|// a gradient operation in their call graph (shortened to "using a gradient"
comment|// in the rest of the file).
comment|//
comment|// This computation is logically split in three steps:
comment|//  1 - For each function compute if it uses a gradient in its body, ignoring
comment|// calls to other user-defined functions.
comment|//  2 - For each function determine if it uses a gradient in its call graph,
comment|// using the result of step 1 and the CallDAG to know its callees.
comment|//  3 - For each control flow statement of each function, check if it uses a
comment|// gradient in the function's body, or if it calls a user-defined function that
comment|// uses a gradient.
comment|//
comment|// We take advantage of the call graph being a DAG and instead compute 1, 2 and 3
comment|// for leaves first, then going down the tree. This is correct because 1 doesn't
comment|// depend on other functions, and 2 and 3 depend only on callees.
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|callDag
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|PullGradient
name|pull
argument_list|(
operator|&
name|metadataList
argument_list|,
name|i
argument_list|,
name|callDag
argument_list|)
decl_stmt|;
name|pull
operator|.
name|traverse
argument_list|(
name|callDag
operator|.
name|getRecordFromIndex
argument_list|(
name|i
argument_list|)
operator|.
name|node
argument_list|)
expr_stmt|;
block|}
comment|// Compute which loops are discontinuous and which function are called in
comment|// these loops. The same way computing gradient usage is a "pull" process,
comment|// computing "bing used in a discont. loop" is a push process. However we also
comment|// need to know what ifs have a discontinuous loop inside so we do the same type
comment|// of callgraph analysis as for the gradient.
comment|// First compute which loops are discontinuous (no specific order) and pull
comment|// the ifs and functions using a gradient loop.
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|callDag
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|PullComputeDiscontinuousAndGradientLoops
name|pull
argument_list|(
operator|&
name|metadataList
argument_list|,
name|i
argument_list|,
name|callDag
argument_list|)
decl_stmt|;
name|pull
operator|.
name|traverse
argument_list|(
name|callDag
operator|.
name|getRecordFromIndex
argument_list|(
name|i
argument_list|)
operator|.
name|node
argument_list|)
expr_stmt|;
block|}
comment|// Then push the information to callees, either from the a local discontinuous
comment|// loop or from the caller being called in a discontinuous loop already
for|for
control|(
name|size_t
name|i
init|=
name|callDag
operator|.
name|size
argument_list|()
init|;
name|i
operator|--
operator|>
literal|0
condition|;
control|)
block|{
name|PushDiscontinuousLoops
name|push
argument_list|(
operator|&
name|metadataList
argument_list|,
name|i
argument_list|,
name|callDag
argument_list|)
decl_stmt|;
name|push
operator|.
name|traverse
argument_list|(
name|callDag
operator|.
name|getRecordFromIndex
argument_list|(
name|i
argument_list|)
operator|.
name|node
argument_list|)
expr_stmt|;
block|}
comment|// We create "Lod0" version of functions with the gradient operations replaced
comment|// by non-gradient operations so that the D3D compiler is happier with discont
comment|// loops.
for|for
control|(
name|auto
operator|&
name|metadata
operator|:
name|metadataList
control|)
block|{
name|metadata
operator|.
name|mNeedsLod0
operator|=
name|metadata
operator|.
name|mCalledInDiscontinuousLoop
operator|&&
name|metadata
operator|.
name|mUsesGradient
expr_stmt|;
block|}
return|return
name|metadataList
return|;
block|}
end_function
end_unit
