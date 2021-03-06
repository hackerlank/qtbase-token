begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// tls.cpp: Simple cross-platform interface for thread local storage.
end_comment
begin_include
include|#
directive|include
file|"common/tls.h"
end_include
begin_include
include|#
directive|include
file|<assert.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|ANGLE_ENABLE_WINDOWS_STORE
end_ifdef
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|<set>
end_include
begin_include
include|#
directive|include
file|<map>
end_include
begin_include
include|#
directive|include
file|<mutex>
end_include
begin_include
include|#
directive|include
file|<wrl/client.h>
end_include
begin_include
include|#
directive|include
file|<wrl/async.h>
end_include
begin_include
include|#
directive|include
file|<Windows.System.Threading.h>
end_include
begin_using
using|using
namespace|namespace
name|std
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|Windows
operator|::
name|Foundation
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|System
operator|::
name|Threading
namespace|;
end_using
begin_comment
comment|// Thread local storage for Windows Store support
end_comment
begin_typedef
DECL|typedef|ThreadLocalData
typedef|typedef
name|vector
argument_list|<
name|void
modifier|*
argument_list|>
name|ThreadLocalData
typedef|;
end_typedef
begin_expr_stmt
DECL|variable|currentThreadData
specifier|static
name|__declspec
argument_list|(
argument|thread
argument_list|)
name|ThreadLocalData
operator|*
name|currentThreadData
operator|=
literal|nullptr
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|allThreadData
specifier|static
name|set
argument_list|<
name|ThreadLocalData
modifier|*
argument_list|>
name|allThreadData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|nextTlsIndex
specifier|static
name|DWORD
name|nextTlsIndex
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|freeTlsIndices
specifier|static
name|vector
argument_list|<
name|DWORD
argument_list|>
name|freeTlsIndices
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|CreateTLSIndex
name|TLSIndex
name|CreateTLSIndex
parameter_list|()
block|{
name|TLSIndex
name|index
decl_stmt|;
ifdef|#
directive|ifdef
name|ANGLE_PLATFORM_WINDOWS
ifdef|#
directive|ifdef
name|ANGLE_ENABLE_WINDOWS_STORE
if|if
condition|(
operator|!
name|freeTlsIndices
operator|.
name|empty
argument_list|()
condition|)
block|{
name|DWORD
name|result
init|=
name|freeTlsIndices
operator|.
name|back
argument_list|()
decl_stmt|;
name|freeTlsIndices
operator|.
name|pop_back
argument_list|()
expr_stmt|;
name|index
operator|=
name|result
expr_stmt|;
block|}
else|else
block|{
name|index
operator|=
name|nextTlsIndex
operator|++
expr_stmt|;
block|}
else|#
directive|else
name|index
operator|=
name|TlsAlloc
argument_list|()
expr_stmt|;
endif|#
directive|endif
elif|#
directive|elif
name|defined
argument_list|(
name|ANGLE_PLATFORM_POSIX
argument_list|)
comment|// Create global pool key
if|if
condition|(
operator|(
name|pthread_key_create
argument_list|(
operator|&
name|index
argument_list|,
name|NULL
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|index
operator|=
name|TLS_INVALID_INDEX
expr_stmt|;
block|}
endif|#
directive|endif
name|assert
argument_list|(
name|index
operator|!=
name|TLS_INVALID_INDEX
operator|&&
literal|"CreateTLSIndex(): Unable to allocate Thread Local Storage"
argument_list|)
expr_stmt|;
return|return
name|index
return|;
block|}
end_function
begin_function
DECL|function|DestroyTLSIndex
name|bool
name|DestroyTLSIndex
parameter_list|(
name|TLSIndex
name|index
parameter_list|)
block|{
name|assert
argument_list|(
name|index
operator|!=
name|TLS_INVALID_INDEX
operator|&&
literal|"DestroyTLSIndex(): Invalid TLS Index"
argument_list|)
expr_stmt|;
if|if
condition|(
name|index
operator|==
name|TLS_INVALID_INDEX
condition|)
block|{
return|return
literal|false
return|;
block|}
ifdef|#
directive|ifdef
name|ANGLE_PLATFORM_WINDOWS
ifdef|#
directive|ifdef
name|ANGLE_ENABLE_WINDOWS_STORE
name|assert
argument_list|(
name|index
operator|<
name|nextTlsIndex
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|find
argument_list|(
name|freeTlsIndices
operator|.
name|begin
argument_list|()
argument_list|,
name|freeTlsIndices
operator|.
name|end
argument_list|()
argument_list|,
name|index
argument_list|)
operator|==
name|freeTlsIndices
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|freeTlsIndices
operator|.
name|push_back
argument_list|(
name|index
argument_list|)
expr_stmt|;
for|for
control|(
name|auto
name|threadData
range|:
name|allThreadData
control|)
block|{
if|if
condition|(
name|threadData
operator|->
name|size
argument_list|()
operator|>
name|index
condition|)
block|{
name|threadData
operator|->
name|at
argument_list|(
name|index
argument_list|)
operator|=
literal|nullptr
expr_stmt|;
block|}
block|}
return|return
literal|true
return|;
else|#
directive|else
return|return
operator|(
name|TlsFree
argument_list|(
name|index
argument_list|)
operator|==
name|TRUE
operator|)
return|;
endif|#
directive|endif
elif|#
directive|elif
name|defined
argument_list|(
name|ANGLE_PLATFORM_POSIX
argument_list|)
return|return
operator|(
name|pthread_key_delete
argument_list|(
name|index
argument_list|)
operator|==
literal|0
operator|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|SetTLSValue
name|bool
name|SetTLSValue
parameter_list|(
name|TLSIndex
name|index
parameter_list|,
name|void
modifier|*
name|value
parameter_list|)
block|{
name|assert
argument_list|(
name|index
operator|!=
name|TLS_INVALID_INDEX
operator|&&
literal|"SetTLSValue(): Invalid TLS Index"
argument_list|)
expr_stmt|;
if|if
condition|(
name|index
operator|==
name|TLS_INVALID_INDEX
condition|)
block|{
return|return
literal|false
return|;
block|}
ifdef|#
directive|ifdef
name|ANGLE_PLATFORM_WINDOWS
ifdef|#
directive|ifdef
name|ANGLE_ENABLE_WINDOWS_STORE
name|ThreadLocalData
modifier|*
name|threadData
init|=
name|currentThreadData
decl_stmt|;
if|if
condition|(
operator|!
name|threadData
condition|)
block|{
name|threadData
operator|=
operator|new
name|ThreadLocalData
argument_list|(
name|index
operator|+
literal|1
argument_list|,
literal|nullptr
argument_list|)
expr_stmt|;
name|allThreadData
operator|.
name|insert
argument_list|(
name|threadData
argument_list|)
expr_stmt|;
name|currentThreadData
operator|=
name|threadData
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|threadData
operator|->
name|size
argument_list|()
operator|<=
name|index
condition|)
block|{
name|threadData
operator|->
name|resize
argument_list|(
name|index
operator|+
literal|1
argument_list|,
literal|nullptr
argument_list|)
expr_stmt|;
block|}
name|threadData
operator|->
name|at
argument_list|(
name|index
argument_list|)
operator|=
name|value
expr_stmt|;
return|return
literal|true
return|;
else|#
directive|else
return|return
operator|(
name|TlsSetValue
argument_list|(
name|index
argument_list|,
name|value
argument_list|)
operator|==
name|TRUE
operator|)
return|;
endif|#
directive|endif
elif|#
directive|elif
name|defined
argument_list|(
name|ANGLE_PLATFORM_POSIX
argument_list|)
return|return
operator|(
name|pthread_setspecific
argument_list|(
name|index
argument_list|,
name|value
argument_list|)
operator|==
literal|0
operator|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|GetTLSValue
name|void
modifier|*
name|GetTLSValue
parameter_list|(
name|TLSIndex
name|index
parameter_list|)
block|{
name|assert
argument_list|(
name|index
operator|!=
name|TLS_INVALID_INDEX
operator|&&
literal|"GetTLSValue(): Invalid TLS Index"
argument_list|)
expr_stmt|;
if|if
condition|(
name|index
operator|==
name|TLS_INVALID_INDEX
condition|)
block|{
return|return
name|NULL
return|;
block|}
ifdef|#
directive|ifdef
name|ANGLE_PLATFORM_WINDOWS
ifdef|#
directive|ifdef
name|ANGLE_ENABLE_WINDOWS_STORE
name|ThreadLocalData
modifier|*
name|threadData
init|=
name|currentThreadData
decl_stmt|;
if|if
condition|(
name|threadData
operator|&&
name|threadData
operator|->
name|size
argument_list|()
operator|>
name|index
condition|)
block|{
return|return
name|threadData
operator|->
name|at
argument_list|(
name|index
argument_list|)
return|;
block|}
else|else
block|{
return|return
literal|nullptr
return|;
block|}
else|#
directive|else
return|return
name|TlsGetValue
argument_list|(
name|index
argument_list|)
return|;
endif|#
directive|endif
elif|#
directive|elif
name|defined
argument_list|(
name|ANGLE_PLATFORM_POSIX
argument_list|)
return|return
name|pthread_getspecific
argument_list|(
name|index
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
end_unit
