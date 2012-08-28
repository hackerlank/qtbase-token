begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2011 The ANGLE Project Authors. All rights reserved.
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
file|"compiler/translator/OutputGLSL.h"
end_include
begin_constructor
DECL|function|TOutputGLSL
name|TOutputGLSL
operator|::
name|TOutputGLSL
parameter_list|(
name|TInfoSinkBase
modifier|&
name|objSink
parameter_list|,
name|ShArrayIndexClampingStrategy
name|clampingStrategy
parameter_list|,
name|ShHashFunction64
name|hashFunction
parameter_list|,
name|NameMap
modifier|&
name|nameMap
parameter_list|,
name|TSymbolTable
modifier|&
name|symbolTable
parameter_list|)
member_init_list|:
name|TOutputGLSLBase
argument_list|(
name|objSink
argument_list|,
name|clampingStrategy
argument_list|,
name|hashFunction
argument_list|,
name|nameMap
argument_list|,
name|symbolTable
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|writeVariablePrecision
name|bool
name|TOutputGLSL
operator|::
name|writeVariablePrecision
parameter_list|(
name|TPrecision
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|visitSymbol
name|void
name|TOutputGLSL
operator|::
name|visitSymbol
parameter_list|(
name|TIntermSymbol
modifier|*
name|node
parameter_list|)
block|{
name|TInfoSinkBase
modifier|&
name|out
init|=
name|objSink
argument_list|()
decl_stmt|;
if|if
condition|(
name|node
operator|->
name|getSymbol
argument_list|()
operator|==
literal|"gl_FragDepthEXT"
condition|)
block|{
name|out
operator|<<
literal|"gl_FragDepth"
expr_stmt|;
block|}
else|else
block|{
name|TOutputGLSLBase
operator|::
name|visitSymbol
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit