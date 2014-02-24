begin_unit
begin_comment
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_include
include|#
directive|include
file|"common/event_tracer.h"
end_include
begin_namespace
DECL|namespace|gl
namespace|namespace
name|gl
block|{
DECL|member|g_getCategoryEnabledFlag
name|GetCategoryEnabledFlagFunc
name|g_getCategoryEnabledFlag
decl_stmt|;
DECL|member|g_addTraceEvent
name|AddTraceEventFunc
name|g_addTraceEvent
decl_stmt|;
block|}
end_namespace
begin_comment
comment|// namespace gl
end_comment
begin_extern
extern|extern
literal|"C"
block|{
DECL|function|SetTraceFunctionPointers
name|void
name|TRACE_ENTRY
name|SetTraceFunctionPointers
parameter_list|(
name|GetCategoryEnabledFlagFunc
name|getCategoryEnabledFlag
parameter_list|,
name|AddTraceEventFunc
name|addTraceEvent
parameter_list|)
block|{
name|gl
operator|::
name|g_getCategoryEnabledFlag
operator|=
name|getCategoryEnabledFlag
expr_stmt|;
name|gl
operator|::
name|g_addTraceEvent
operator|=
name|addTraceEvent
expr_stmt|;
block|}
block|}
end_extern
begin_comment
comment|// extern "C"
end_comment
begin_namespace
DECL|namespace|gl
namespace|namespace
name|gl
block|{
DECL|function|TraceGetTraceCategoryEnabledFlag
specifier|const
name|unsigned
name|char
modifier|*
name|TraceGetTraceCategoryEnabledFlag
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
if|if
condition|(
name|g_getCategoryEnabledFlag
condition|)
block|{
return|return
name|g_getCategoryEnabledFlag
argument_list|(
name|name
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|char
name|disabled
init|=
literal|0
decl_stmt|;
return|return
operator|&
name|disabled
return|;
block|}
DECL|function|TraceAddTraceEvent
name|void
name|TraceAddTraceEvent
parameter_list|(
name|char
name|phase
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|categoryGroupEnabled
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|unsigned
name|long
name|long
name|id
parameter_list|,
name|int
name|numArgs
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argNames
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|argTypes
parameter_list|,
specifier|const
name|unsigned
name|long
name|long
modifier|*
name|argValues
parameter_list|,
name|unsigned
name|char
name|flags
parameter_list|)
block|{
if|if
condition|(
name|g_addTraceEvent
condition|)
block|{
name|g_addTraceEvent
argument_list|(
name|phase
argument_list|,
name|categoryGroupEnabled
argument_list|,
name|name
argument_list|,
name|id
argument_list|,
name|numArgs
argument_list|,
name|argNames
argument_list|,
name|argTypes
argument_list|,
name|argValues
argument_list|,
name|flags
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_namespace
begin_comment
comment|// namespace gl
end_comment
end_unit
