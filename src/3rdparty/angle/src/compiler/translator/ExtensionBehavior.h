begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2010 The ANGLE Project Authors. All rights reserved.
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
name|_EXTENSION_BEHAVIOR_INCLUDED_
end_ifndef
begin_define
DECL|macro|_EXTENSION_BEHAVIOR_INCLUDED_
define|#
directive|define
name|_EXTENSION_BEHAVIOR_INCLUDED_
end_define
begin_include
include|#
directive|include
file|<map>
end_include
begin_include
include|#
directive|include
file|<string>
end_include
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|EBhRequire
name|EBhRequire
block|,
DECL|enumerator|EBhEnable
name|EBhEnable
block|,
DECL|enumerator|EBhWarn
name|EBhWarn
block|,
DECL|enumerator|EBhDisable
name|EBhDisable
block|,
DECL|enumerator|EBhUndefined
name|EBhUndefined
block|}
DECL|typedef|TBehavior
name|TBehavior
typedef|;
end_typedef
begin_function
DECL|function|getBehaviorString
specifier|inline
specifier|const
name|char
modifier|*
name|getBehaviorString
parameter_list|(
name|TBehavior
name|b
parameter_list|)
block|{
switch|switch
condition|(
name|b
condition|)
block|{
case|case
name|EBhRequire
case|:
return|return
literal|"require"
return|;
case|case
name|EBhEnable
case|:
return|return
literal|"enable"
return|;
case|case
name|EBhWarn
case|:
return|return
literal|"warn"
return|;
case|case
name|EBhDisable
case|:
return|return
literal|"disable"
return|;
default|default:
return|return
name|NULL
return|;
block|}
block|}
end_function
begin_comment
comment|// Mapping between extension name and behavior.
end_comment
begin_typedef
DECL|typedef|string
DECL|typedef|TExtensionBehavior
typedef|typedef
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|TBehavior
operator|>
name|TExtensionBehavior
expr_stmt|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// _EXTENSION_TABLE_INCLUDED_
end_comment
end_unit