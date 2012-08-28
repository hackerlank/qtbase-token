begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
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
file|"compiler/translator/depgraph/DependencyGraph.h"
end_include
begin_comment
comment|// These methods do a breadth-first traversal through the graph and mark visited nodes.
end_comment
begin_function
DECL|function|traverse
name|void
name|TGraphNode
operator|::
name|traverse
parameter_list|(
name|TDependencyGraphTraverser
modifier|*
name|graphTraverser
parameter_list|)
block|{
name|graphTraverser
operator|->
name|markVisited
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|traverse
name|void
name|TGraphParentNode
operator|::
name|traverse
parameter_list|(
name|TDependencyGraphTraverser
modifier|*
name|graphTraverser
parameter_list|)
block|{
name|TGraphNode
operator|::
name|traverse
argument_list|(
name|graphTraverser
argument_list|)
expr_stmt|;
name|graphTraverser
operator|->
name|incrementDepth
argument_list|()
expr_stmt|;
comment|// Visit the parent node's children.
for|for
control|(
name|TGraphNodeSet
operator|::
name|const_iterator
name|iter
init|=
name|mDependentNodes
operator|.
name|begin
argument_list|()
init|;
name|iter
operator|!=
name|mDependentNodes
operator|.
name|end
argument_list|()
condition|;
operator|++
name|iter
control|)
block|{
name|TGraphNode
modifier|*
name|node
init|=
operator|*
name|iter
decl_stmt|;
if|if
condition|(
operator|!
name|graphTraverser
operator|->
name|isVisited
argument_list|(
name|node
argument_list|)
condition|)
name|node
operator|->
name|traverse
argument_list|(
name|graphTraverser
argument_list|)
expr_stmt|;
block|}
name|graphTraverser
operator|->
name|decrementDepth
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|traverse
name|void
name|TGraphArgument
operator|::
name|traverse
parameter_list|(
name|TDependencyGraphTraverser
modifier|*
name|graphTraverser
parameter_list|)
block|{
name|graphTraverser
operator|->
name|visitArgument
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|TGraphParentNode
operator|::
name|traverse
argument_list|(
name|graphTraverser
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|traverse
name|void
name|TGraphFunctionCall
operator|::
name|traverse
parameter_list|(
name|TDependencyGraphTraverser
modifier|*
name|graphTraverser
parameter_list|)
block|{
name|graphTraverser
operator|->
name|visitFunctionCall
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|TGraphParentNode
operator|::
name|traverse
argument_list|(
name|graphTraverser
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|traverse
name|void
name|TGraphSymbol
operator|::
name|traverse
parameter_list|(
name|TDependencyGraphTraverser
modifier|*
name|graphTraverser
parameter_list|)
block|{
name|graphTraverser
operator|->
name|visitSymbol
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|TGraphParentNode
operator|::
name|traverse
argument_list|(
name|graphTraverser
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|traverse
name|void
name|TGraphSelection
operator|::
name|traverse
parameter_list|(
name|TDependencyGraphTraverser
modifier|*
name|graphTraverser
parameter_list|)
block|{
name|graphTraverser
operator|->
name|visitSelection
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|TGraphNode
operator|::
name|traverse
argument_list|(
name|graphTraverser
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|traverse
name|void
name|TGraphLoop
operator|::
name|traverse
parameter_list|(
name|TDependencyGraphTraverser
modifier|*
name|graphTraverser
parameter_list|)
block|{
name|graphTraverser
operator|->
name|visitLoop
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|TGraphNode
operator|::
name|traverse
argument_list|(
name|graphTraverser
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|traverse
name|void
name|TGraphLogicalOp
operator|::
name|traverse
parameter_list|(
name|TDependencyGraphTraverser
modifier|*
name|graphTraverser
parameter_list|)
block|{
name|graphTraverser
operator|->
name|visitLogicalOp
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|TGraphNode
operator|::
name|traverse
argument_list|(
name|graphTraverser
argument_list|)
expr_stmt|;
block|}
end_function
end_unit