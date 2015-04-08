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
begin_ifndef
ifndef|#
directive|ifndef
name|COMMON_EVENT_TRACER_H_
end_ifndef
begin_define
DECL|macro|COMMON_EVENT_TRACER_H_
define|#
directive|define
name|COMMON_EVENT_TRACER_H_
end_define
begin_include
include|#
directive|include
file|"common/platform.h"
end_include
begin_extern
extern|extern
literal|"C"
block|{
DECL|typedef|GetCategoryEnabledFlagFunc
typedef|typedef
specifier|const
name|unsigned
name|char
modifier|*
function_decl|(
modifier|*
name|GetCategoryEnabledFlagFunc
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
DECL|typedef|AddTraceEventFunc
typedef|typedef
name|void
function_decl|(
modifier|*
name|AddTraceEventFunc
function_decl|)
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
function_decl|;
block|}
end_extern
begin_decl_stmt
name|namespace
name|gl
block|{
specifier|extern
name|GetCategoryEnabledFlagFunc
name|g_getCategoryEnabledFlag
decl_stmt|;
specifier|extern
name|AddTraceEventFunc
name|g_addTraceEvent
decl_stmt|;
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
function_decl|;
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
function_decl|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMMON_EVENT_TRACER_H_
end_comment
end_unit
