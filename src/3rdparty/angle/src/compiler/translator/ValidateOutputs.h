begin_unit
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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_VALIDATEOUTPUTS_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_VALIDATEOUTPUTS_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_VALIDATEOUTPUTS_H_
end_define
begin_include
include|#
directive|include
file|"compiler/translator/ExtensionBehavior.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_include
include|#
directive|include
file|<set>
end_include
begin_decl_stmt
DECL|variable|TInfoSinkBase
name|class
name|TInfoSinkBase
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|ValidateOutputs
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|ValidateOutputs
argument_list|(
argument|const TExtensionBehavior&extBehavior
argument_list|,
argument|int maxDrawBuffers
argument_list|)
block|;
name|int
name|validateAndCountErrors
argument_list|(
argument|TInfoSinkBase&sink
argument_list|)
specifier|const
block|;
name|void
name|visitSymbol
argument_list|(
argument|TIntermSymbol *
argument_list|)
name|override
block|;
name|private
operator|:
name|int
name|mMaxDrawBuffers
block|;
name|bool
name|mAllowUnspecifiedOutputLocationResolution
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|TIntermSymbol
operator|*
operator|>
name|OutputVector
expr_stmt|;
name|OutputVector
name|mOutputs
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|OutputVector
name|mUnspecifiedLocationOutputs
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|std
operator|::
name|set
operator|<
name|TString
operator|>
name|mVisitedSymbols
expr_stmt|;
end_expr_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_VALIDATEOUTPUTS_H_
end_comment
end_unit
