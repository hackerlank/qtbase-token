begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_SYMBIAN
end_ifndef
begin_include
include|#
directive|include
file|<malloc.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<exception>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
end_if
begin_include
include|#
directive|include
file|"3rdparty/memcheck.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|mallocFailActive
specifier|static
name|bool
name|mallocFailActive
init|=
name|false
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|mallocFailIndex
specifier|static
name|int
name|mallocFailIndex
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|mallocCount
specifier|static
name|int
name|mallocCount
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|my_terminate_handler
specifier|static
name|void
name|my_terminate_handler
parameter_list|()
block|{
comment|// set a breakpoint here to get a backtrace for your uncaught exceptions
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Uncaught Exception Detected. Set a breakpoint in my_terminate_handler()\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|__GLIBC__
end_ifdef
begin_comment
comment|/* Use glibc's memory allocation hooks */
end_comment
begin_comment
comment|/* our hooks */
end_comment
begin_function_decl
specifier|static
name|void
modifier|*
name|my_malloc_hook
parameter_list|(
name|size_t
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
modifier|*
name|my_realloc_hook
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
modifier|*
name|my_memalign_hook
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|my_free_hook
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* original hooks. */
end_comment
begin_function_decl
DECL|variable|old_malloc_hook
specifier|static
name|void
modifier|*
function_decl|(
modifier|*
name|old_malloc_hook
function_decl|)
parameter_list|(
name|size_t
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
DECL|variable|old_realloc_hook
specifier|static
name|void
modifier|*
function_decl|(
modifier|*
name|old_realloc_hook
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
DECL|variable|old_memalign_hook
specifier|static
name|void
modifier|*
function_decl|(
modifier|*
name|old_memalign_hook
function_decl|)
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
DECL|variable|old_free_hook
specifier|static
name|void
function_decl|(
modifier|*
name|old_free_hook
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* initializer function */
end_comment
begin_function_decl
specifier|static
name|void
name|my_init_hook
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|/* Override initialising hook from the C library. */
end_comment
begin_function_decl
DECL|variable|__malloc_initialize_hook
name|void
function_decl|(
modifier|*
name|__malloc_initialize_hook
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|my_init_hook
function_decl|;
end_function_decl
begin_function
DECL|function|disableHooks
specifier|static
name|void
name|disableHooks
parameter_list|()
block|{
name|__malloc_hook
operator|=
name|old_malloc_hook
expr_stmt|;
name|__realloc_hook
operator|=
name|old_realloc_hook
expr_stmt|;
name|__memalign_hook
operator|=
name|old_memalign_hook
expr_stmt|;
name|__free_hook
operator|=
name|old_free_hook
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enableHooks
specifier|static
name|void
name|enableHooks
parameter_list|()
block|{
name|__malloc_hook
operator|=
name|my_malloc_hook
expr_stmt|;
name|__realloc_hook
operator|=
name|my_realloc_hook
expr_stmt|;
name|__memalign_hook
operator|=
name|my_memalign_hook
expr_stmt|;
name|__free_hook
operator|=
name|my_free_hook
expr_stmt|;
block|}
end_function
begin_function
DECL|function|my_init_hook
name|void
name|my_init_hook
parameter_list|()
block|{
name|old_malloc_hook
operator|=
name|__malloc_hook
expr_stmt|;
name|old_realloc_hook
operator|=
name|__realloc_hook
expr_stmt|;
name|old_memalign_hook
operator|=
name|__memalign_hook
expr_stmt|;
name|old_free_hook
operator|=
name|__free_hook
expr_stmt|;
name|enableHooks
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|my_malloc_hook
name|void
modifier|*
name|my_malloc_hook
parameter_list|(
name|size_t
name|size
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
block|{
operator|++
name|mallocCount
expr_stmt|;
if|if
condition|(
name|mallocFailActive
operator|&&
operator|--
name|mallocFailIndex
operator|<
literal|0
condition|)
return|return
literal|0
return|;
comment|// simulate OOM
name|__malloc_hook
operator|=
name|old_malloc_hook
expr_stmt|;
name|void
modifier|*
name|result
init|=
operator|::
name|malloc
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|__malloc_hook
operator|=
name|my_malloc_hook
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|my_memalign_hook
name|void
modifier|*
name|my_memalign_hook
parameter_list|(
name|size_t
name|alignment
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
block|{
operator|++
name|mallocCount
expr_stmt|;
if|if
condition|(
name|mallocFailActive
operator|&&
operator|--
name|mallocFailIndex
operator|<
literal|0
condition|)
return|return
literal|0
return|;
comment|// simulate OOM
name|__memalign_hook
operator|=
name|old_memalign_hook
expr_stmt|;
name|void
modifier|*
name|result
init|=
operator|::
name|memalign
argument_list|(
name|alignment
argument_list|,
name|size
argument_list|)
decl_stmt|;
name|__memalign_hook
operator|=
name|my_memalign_hook
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|my_realloc_hook
name|void
modifier|*
name|my_realloc_hook
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
block|{
operator|++
name|mallocCount
expr_stmt|;
if|if
condition|(
name|mallocFailActive
operator|&&
operator|--
name|mallocFailIndex
operator|<
literal|0
condition|)
return|return
literal|0
return|;
comment|// simulate OOM
name|__realloc_hook
operator|=
name|old_realloc_hook
expr_stmt|;
name|__malloc_hook
operator|=
name|old_malloc_hook
expr_stmt|;
name|void
modifier|*
name|result
init|=
operator|::
name|realloc
argument_list|(
name|ptr
argument_list|,
name|size
argument_list|)
decl_stmt|;
name|__malloc_hook
operator|=
name|my_malloc_hook
expr_stmt|;
name|__realloc_hook
operator|=
name|my_realloc_hook
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|my_free_hook
name|void
name|my_free_hook
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
block|{
name|__free_hook
operator|=
name|old_free_hook
expr_stmt|;
operator|::
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
name|__free_hook
operator|=
name|my_free_hook
expr_stmt|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"crtdbg.h"
end_include
begin_function
DECL|function|qCrtAllocHook
specifier|static
name|int
name|qCrtAllocHook
parameter_list|(
name|int
name|allocType
parameter_list|,
name|void
modifier|*
comment|/*userData*/
parameter_list|,
name|size_t
comment|/*size*/
parameter_list|,
name|int
name|blockType
parameter_list|,
name|long
comment|/*requestNumber*/
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
comment|/*filename*/
parameter_list|,
name|int
comment|/*lineNumber*/
parameter_list|)
block|{
if|if
condition|(
name|blockType
operator|==
name|_CRT_BLOCK
condition|)
return|return
name|TRUE
return|;
comment|// ignore allocations from the C library
switch|switch
condition|(
name|allocType
condition|)
block|{
case|case
name|_HOOK_ALLOC
case|:
case|case
name|_HOOK_REALLOC
case|:
operator|++
name|mallocCount
expr_stmt|;
if|if
condition|(
name|mallocFailActive
operator|&&
operator|--
name|mallocFailIndex
operator|<
literal|0
condition|)
return|return
name|FALSE
return|;
comment|// simulate OOM
block|}
return|return
name|TRUE
return|;
block|}
end_function
begin_struct
DECL|struct|QCrtDebugRegistrator
specifier|static
struct|struct
name|QCrtDebugRegistrator
block|{
DECL|function|QCrtDebugRegistrator
name|QCrtDebugRegistrator
argument_list|()
block|{
name|_CrtSetAllocHook
argument_list|(
name|qCrtAllocHook
argument_list|)
expr_stmt|;
block|}
block|}
DECL|variable|crtDebugRegistrator
name|crtDebugRegistrator
struct|;
end_struct
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
end_elif
begin_decl_stmt
DECL|struct|RAllocator
name|struct
name|QAllocFailAllocator
range|:
name|public
name|RAllocator
block|{
DECL|function|QAllocFailAllocator
name|QAllocFailAllocator
argument_list|()
operator|:
name|allocator
argument_list|(
argument|User::Allocator()
argument_list|)
block|{
name|User
operator|::
name|SwitchAllocator
argument_list|(
name|this
argument_list|)
block|;     }
DECL|function|~QAllocFailAllocator
operator|~
name|QAllocFailAllocator
argument_list|()
block|{
name|User
operator|::
name|SwitchAllocator
argument_list|(
operator|&
name|allocator
argument_list|)
block|;     }
DECL|member|allocator
name|RAllocator
operator|&
name|allocator
block|;
comment|// from MAllocator
DECL|function|Alloc
name|TAny
operator|*
name|Alloc
argument_list|(
argument|TInt aSize
argument_list|)
block|{
operator|++
name|mallocCount
block|;
if|if
condition|(
name|mallocFailActive
operator|&&
operator|--
name|mallocFailIndex
operator|<
literal|0
condition|)
return|return
literal|0
return|;
comment|// simulate OOM
return|return
name|allocator
operator|.
name|Alloc
argument_list|(
name|aSize
argument_list|)
return|;
block|}
end_decl_stmt
begin_function
DECL|function|Free
name|void
name|Free
parameter_list|(
name|TAny
modifier|*
name|aPtr
parameter_list|)
block|{
name|allocator
operator|.
name|Free
argument_list|(
name|aPtr
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|ReAlloc
name|TAny
modifier|*
name|ReAlloc
parameter_list|(
name|TAny
modifier|*
name|aPtr
parameter_list|,
name|TInt
name|aSize
parameter_list|,
name|TInt
name|aMode
parameter_list|)
block|{
operator|++
name|mallocCount
expr_stmt|;
if|if
condition|(
name|mallocFailActive
operator|&&
operator|--
name|mallocFailIndex
operator|<
literal|0
condition|)
return|return
literal|0
return|;
comment|// simulate OOM
return|return
name|allocator
operator|.
name|ReAlloc
argument_list|(
name|aPtr
argument_list|,
name|aSize
argument_list|,
name|aMode
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
DECL|function|AllocLen
name|TInt
name|AllocLen
argument_list|(
specifier|const
name|TAny
operator|*
name|aCell
argument_list|)
decl|const
block|{
return|return
name|allocator
operator|.
name|AllocLen
argument_list|(
name|aCell
argument_list|)
return|;
block|}
end_decl_stmt
begin_function
DECL|function|Compress
name|TInt
name|Compress
parameter_list|()
block|{
return|return
name|allocator
operator|.
name|Compress
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|Reset
name|void
name|Reset
parameter_list|()
block|{
name|allocator
operator|.
name|Reset
argument_list|()
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|function|AllocSize
name|TInt
name|AllocSize
argument_list|(
name|TInt
operator|&
name|aTotalAllocSize
argument_list|)
decl|const
block|{
return|return
name|allocator
operator|.
name|AllocSize
argument_list|(
name|aTotalAllocSize
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
DECL|function|Available
name|TInt
name|Available
argument_list|(
name|TInt
operator|&
name|aBiggestBlock
argument_list|)
decl|const
block|{
return|return
name|allocator
operator|.
name|Available
argument_list|(
name|aBiggestBlock
argument_list|)
return|;
block|}
end_decl_stmt
begin_function
DECL|function|DebugFunction
name|TInt
name|DebugFunction
parameter_list|(
name|TInt
name|aFunc
parameter_list|,
name|TAny
modifier|*
name|a1
parameter_list|,
name|TAny
modifier|*
name|a2
parameter_list|)
block|{
return|return
name|allocator
operator|.
name|DebugFunction
argument_list|(
name|aFunc
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|Extension_
name|TInt
name|Extension_
parameter_list|(
name|TUint
name|aExtensionId
parameter_list|,
name|TAny
modifier|*
modifier|&
name|a0
parameter_list|,
name|TAny
modifier|*
name|a1
parameter_list|)
block|{
return|return
operator|(
operator|(
name|MAllocator
operator|&
operator|)
name|allocator
operator|)
operator|.
name|Extension_
argument_list|(
name|aExtensionId
argument_list|,
name|a0
argument_list|,
name|a1
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
unit|};
DECL|variable|symbianTestAllocator
name|QAllocFailAllocator
name|symbianTestAllocator
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_struct
DECL|struct|AllocFailer
struct|struct
name|AllocFailer
block|{
DECL|function|AllocFailer
specifier|inline
name|AllocFailer
argument_list|(
argument|int index
argument_list|)
block|{
name|reactivateAt
argument_list|(
name|index
argument_list|)
block|; }
DECL|function|~AllocFailer
specifier|inline
operator|~
name|AllocFailer
argument_list|()
block|{
name|deactivate
argument_list|()
block|; }
DECL|function|reactivateAt
specifier|inline
name|void
name|reactivateAt
argument_list|(
argument|int index
argument_list|)
block|{
ifdef|#
directive|ifdef
name|RUNNING_ON_VALGRIND
if|if
condition|(
name|RUNNING_ON_VALGRIND
condition|)
name|VALGRIND_ENABLE_OOM_AT_ALLOC_INDEX
argument_list|(
name|VALGRIND_GET_ALLOC_INDEX
operator|+
name|index
operator|+
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|mallocFailIndex
operator|=
name|index
expr_stmt|;
name|mallocFailActive
operator|=
name|true
expr_stmt|;
block|}
DECL|function|deactivate
specifier|inline
namespace|void
name|deactivate
namespace|(
struct|)
block|{
name|mallocFailActive
operator|=
name|false
expr_stmt|;
ifdef|#
directive|ifdef
name|RUNNING_ON_VALGRIND
name|VALGRIND_ENABLE_OOM_AT_ALLOC_INDEX
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
DECL|function|currentAllocIndex
specifier|inline
namespace|int
name|currentAllocIndex
namespace|(
struct|)
specifier|const
block|{
ifdef|#
directive|ifdef
name|RUNNING_ON_VALGRIND
if|if
condition|(
name|RUNNING_ON_VALGRIND
condition|)
return|return
name|VALGRIND_GET_ALLOC_INDEX
return|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
begin_return
return|return
name|mallocCount
return|;
end_return
begin_function
unit|}      static
DECL|function|initialize
name|bool
name|initialize
parameter_list|()
block|{
name|std
operator|::
name|set_terminate
argument_list|(
name|my_terminate_handler
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|RUNNING_ON_VALGRIND
if|if
condition|(
name|RUNNING_ON_VALGRIND
condition|)
block|{
if|if
condition|(
name|VALGRIND_GET_ALLOC_INDEX
operator|==
operator|-
literal|1u
condition|)
block|{
name|qWarning
argument_list|(
literal|"You must use a valgrind with oom simulation support"
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
comment|// running in valgrind - don't use glibc hooks
name|disableHooks
argument_list|()
expr_stmt|;
comment|// never stop simulating OOM
name|VALGRIND_DISABLE_OOM_AT_ALLOC_INDEX
argument_list|(
operator|-
literal|1u
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|true
return|;
block|}
end_function
begin_ifndef
unit|};
ifndef|#
directive|ifndef
name|Q_OS_SYMBIAN
end_ifndef
begin_decl_stmt
DECL|function|new_helper
specifier|static
name|void
modifier|*
name|new_helper
argument_list|(
name|std
operator|::
name|size_t
name|size
argument_list|)
block|{
name|void
modifier|*
name|ptr
init|=
name|malloc
argument_list|(
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ptr
condition|)
name|throw
name|std
operator|::
name|bad_alloc
argument_list|()
expr_stmt|;
return|return
name|ptr
return|;
block|}
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_CC_MSVC
end_ifdef
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
end_pragma
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4290
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// overload operator new
end_comment
begin_function
DECL|function|throw
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|size_t
name|size
parameter_list|)
function|throw
parameter_list|(
function|std::bad_alloc
end_function
begin_block
DECL|function|throw
unit|)
block|{
return|return
name|new_helper
argument_list|(
name|size
argument_list|)
return|;
block|}
end_block
begin_function
DECL|function|throw
name|void
modifier|*
name|operator
name|new
function|[]
parameter_list|(
name|size_t
name|size
parameter_list|)
function|throw
parameter_list|(
function|std::bad_alloc
end_function
begin_block
DECL|function|throw
unit|)
block|{
return|return
name|new_helper
argument_list|(
name|size
argument_list|)
return|;
block|}
end_block
begin_decl_stmt
DECL|function|throw
name|void
modifier|*
name|operator
name|new
argument_list|(
name|size_t
name|size
argument_list|,
specifier|const
name|std
operator|::
name|nothrow_t
operator|&
argument_list|)
name|throw
argument_list|()
block|{
return|return
name|malloc
argument_list|(
name|size
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
DECL|function|throw
name|void
modifier|*
name|operator
name|new
index|[]
argument_list|(
name|std
operator|::
name|size_t
name|size
argument_list|,
specifier|const
name|std
operator|::
name|nothrow_t
operator|&
argument_list|)
name|throw
argument_list|()
block|{
return|return
name|malloc
argument_list|(
name|size
argument_list|)
return|;
block|}
end_decl_stmt
begin_comment
comment|// overload operator delete
end_comment
begin_function
DECL|function|throw
name|void
name|operator
name|delete
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function|throw
parameter_list|()
block|{
if|if
condition|(
name|ptr
condition|)
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|throw
name|void
name|operator
name|delete
function|[]
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function|throw
parameter_list|()
block|{
if|if
condition|(
name|ptr
condition|)
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|function|throw
name|void
name|operator
name|delete
argument_list|(
name|void
operator|*
name|ptr
argument_list|,
specifier|const
name|std
operator|::
name|nothrow_t
operator|&
argument_list|)
name|throw
argument_list|()
block|{
if|if
condition|(
name|ptr
condition|)
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
DECL|function|throw
name|void
name|operator
name|delete
index|[]
argument_list|(
name|void
operator|*
name|ptr
argument_list|,
specifier|const
name|std
operator|::
name|nothrow_t
operator|&
argument_list|)
name|throw
argument_list|()
block|{
if|if
condition|(
name|ptr
condition|)
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_CC_MSVC
end_ifdef
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ignore placement new and placement delete - those don't allocate.
end_comment
end_unit
