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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_VALIDATELIMITATIONS_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_VALIDATELIMITATIONS_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_VALIDATELIMITATIONS_H_
end_define
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/LoopInfo.h"
end_include
begin_decl_stmt
DECL|variable|TInfoSinkBase
name|class
name|TInfoSinkBase
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Traverses intermediate tree to ensure that the shader does not exceed the
end_comment
begin_comment
comment|// minimum functionality mandated in GLSL 1.0 spec, Appendix A.
end_comment
begin_decl_stmt
name|class
name|ValidateLimitations
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|ValidateLimitations
argument_list|(
argument|sh::GLenum shaderType
argument_list|,
argument|TInfoSinkBase&sink
argument_list|)
block|;
name|int
name|numErrors
argument_list|()
specifier|const
block|{
return|return
name|mNumErrors
return|;
block|}
name|virtual
name|bool
name|visitBinary
argument_list|(
name|Visit
argument_list|,
name|TIntermBinary
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visitUnary
argument_list|(
name|Visit
argument_list|,
name|TIntermUnary
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visitAggregate
argument_list|(
name|Visit
argument_list|,
name|TIntermAggregate
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visitLoop
argument_list|(
name|Visit
argument_list|,
name|TIntermLoop
operator|*
argument_list|)
block|;
name|private
operator|:
name|void
name|error
argument_list|(
argument|TSourceLoc loc
argument_list|,
argument|const char *reason
argument_list|,
argument|const char *token
argument_list|)
block|;
name|bool
name|withinLoopBody
argument_list|()
specifier|const
block|;
name|bool
name|isLoopIndex
argument_list|(
name|TIntermSymbol
operator|*
name|symbol
argument_list|)
block|;
name|bool
name|validateLoopType
argument_list|(
name|TIntermLoop
operator|*
name|node
argument_list|)
block|;
name|bool
name|validateForLoopHeader
argument_list|(
name|TIntermLoop
operator|*
name|node
argument_list|)
block|;
comment|// If valid, return the index symbol id; Otherwise, return -1.
name|int
name|validateForLoopInit
argument_list|(
name|TIntermLoop
operator|*
name|node
argument_list|)
block|;
name|bool
name|validateForLoopCond
argument_list|(
argument|TIntermLoop *node
argument_list|,
argument|int indexSymbolId
argument_list|)
block|;
name|bool
name|validateForLoopExpr
argument_list|(
argument|TIntermLoop *node
argument_list|,
argument|int indexSymbolId
argument_list|)
block|;
comment|// Returns true if none of the loop indices is used as the argument to
comment|// the given function out or inout parameter.
name|bool
name|validateFunctionCall
argument_list|(
name|TIntermAggregate
operator|*
name|node
argument_list|)
block|;
name|bool
name|validateOperation
argument_list|(
name|TIntermOperator
operator|*
name|node
argument_list|,
name|TIntermNode
operator|*
name|operand
argument_list|)
block|;
comment|// Returns true if indexing does not exceed the minimum functionality
comment|// mandated in GLSL 1.0 spec, Appendix A, Section 5.
name|bool
name|isConstExpr
argument_list|(
name|TIntermNode
operator|*
name|node
argument_list|)
block|;
name|bool
name|isConstIndexExpr
argument_list|(
name|TIntermNode
operator|*
name|node
argument_list|)
block|;
name|bool
name|validateIndexing
argument_list|(
name|TIntermBinary
operator|*
name|node
argument_list|)
block|;
name|sh
operator|::
name|GLenum
name|mShaderType
block|;
name|TInfoSinkBase
operator|&
name|mSink
block|;
name|int
name|mNumErrors
block|;
name|TLoopStack
name|mLoopStack
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_VALIDATELIMITATIONS_H_
end_comment
end_unit
