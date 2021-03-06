begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2011 The ANGLE Project Authors. All rights reserved.
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
name|COMPILER_TRANSLATOR_FORLOOPUNROLL_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_FORLOOPUNROLL_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_FORLOOPUNROLL_H_
end_define
begin_include
include|#
directive|include
file|"compiler/translator/LoopInfo.h"
end_include
begin_comment
comment|// This class detects for-loops that needs to be unrolled.
end_comment
begin_comment
comment|// Currently we support two unroll conditions:
end_comment
begin_comment
comment|//   1) kForLoopWithIntegerIndex: unroll if the index type is integer.
end_comment
begin_comment
comment|//   2) kForLoopWithSamplerArrayIndex: unroll where a sampler array index
end_comment
begin_comment
comment|//      is also the loop integer index, and reject and fail a compile
end_comment
begin_comment
comment|//      where a sampler array index is also the loop float index.
end_comment
begin_decl_stmt
name|class
name|ForLoopUnrollMarker
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
expr|enum
name|UnrollCondition
block|{
name|kIntegerIndex
block|,
name|kSamplerArrayIndex
block|}
block|;
name|ForLoopUnrollMarker
argument_list|(
argument|UnrollCondition condition
argument_list|,
argument|bool hasRunLoopValidation
argument_list|)
operator|:
name|TIntermTraverser
argument_list|(
name|true
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|mUnrollCondition
argument_list|(
name|condition
argument_list|)
block|,
name|mSamplerArrayIndexIsFloatLoopIndex
argument_list|(
name|false
argument_list|)
block|,
name|mVisitSamplerArrayIndexNodeInsideLoop
argument_list|(
name|false
argument_list|)
block|,
name|mHasRunLoopValidation
argument_list|(
argument|hasRunLoopValidation
argument_list|)
block|{     }
name|bool
name|visitBinary
argument_list|(
argument|Visit
argument_list|,
argument|TIntermBinary *node
argument_list|)
name|override
block|;
name|bool
name|visitLoop
argument_list|(
argument|Visit
argument_list|,
argument|TIntermLoop *node
argument_list|)
name|override
block|;
name|void
name|visitSymbol
argument_list|(
argument|TIntermSymbol *node
argument_list|)
name|override
block|;
name|bool
name|samplerArrayIndexIsFloatLoopIndex
argument_list|()
specifier|const
block|{
return|return
name|mSamplerArrayIndexIsFloatLoopIndex
return|;
block|}
name|private
operator|:
name|UnrollCondition
name|mUnrollCondition
block|;
name|TLoopStack
name|mLoopStack
block|;
name|bool
name|mSamplerArrayIndexIsFloatLoopIndex
block|;
name|bool
name|mVisitSamplerArrayIndexNodeInsideLoop
block|;
name|bool
name|mHasRunLoopValidation
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_FORLOOPUNROLL_H_
end_comment
end_unit
