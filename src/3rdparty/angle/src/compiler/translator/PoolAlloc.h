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
name|COMPILER_TRANSLATOR_POOLALLOC_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_POOLALLOC_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_POOLALLOC_H_
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|_DEBUG
end_ifdef
begin_define
DECL|macro|GUARD_BLOCKS
define|#
directive|define
name|GUARD_BLOCKS
end_define
begin_comment
DECL|macro|GUARD_BLOCKS
comment|// define to enable guard block sanity checking
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//
end_comment
begin_comment
comment|// This header defines an allocator that can be used to efficiently
end_comment
begin_comment
comment|// allocate a large number of small requests for heap memory, with the
end_comment
begin_comment
comment|// intention that they are not individually deallocated, but rather
end_comment
begin_comment
comment|// collectively deallocated at one time.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This simultaneously
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// * Makes each individual allocation much more efficient; the
end_comment
begin_comment
comment|//     typical allocation is trivial.
end_comment
begin_comment
comment|// * Completely avoids the cost of doing individual deallocation.
end_comment
begin_comment
comment|// * Saves the trouble of tracking down and plugging a large class of leaks.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Individual classes can use this allocator by supplying their own
end_comment
begin_comment
comment|// new and delete methods.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// STL containers can use this allocator by using the pool_allocator
end_comment
begin_comment
comment|// class as the allocator (second) template argument.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<stddef.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_comment
comment|// If we are using guard blocks, we must track each indivual
end_comment
begin_comment
comment|// allocation.  If we aren't using guard blocks, these
end_comment
begin_comment
comment|// never get instantiated, so won't have any impact.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|TAllocation
block|{
name|public
label|:
name|TAllocation
argument_list|(
argument|size_t size
argument_list|,
argument|unsigned char* mem
argument_list|,
argument|TAllocation* prev =
literal|0
argument_list|)
block|:
name|size
argument_list|(
name|size
argument_list|)
operator|,
name|mem
argument_list|(
name|mem
argument_list|)
operator|,
name|prevAlloc
argument_list|(
argument|prev
argument_list|)
block|{
comment|// Allocations are bracketed:
comment|//    [allocationHeader][initialGuardBlock][userData][finalGuardBlock]
comment|// This would be cleaner with if (guardBlockSize)..., but that
comment|// makes the compiler print warnings about 0 length memsets,
comment|// even with the if() protecting them.
ifdef|#
directive|ifdef
name|GUARD_BLOCKS
name|memset
argument_list|(
name|preGuard
argument_list|()
argument_list|,
name|guardBlockBeginVal
argument_list|,
name|guardBlockSize
argument_list|)
block|;
name|memset
argument_list|(
name|data
argument_list|()
argument_list|,
name|userDataFill
argument_list|,
name|size
argument_list|)
block|;
name|memset
argument_list|(
name|postGuard
argument_list|()
argument_list|,
name|guardBlockEndVal
argument_list|,
name|guardBlockSize
argument_list|)
block|;
endif|#
directive|endif
block|}
name|void
name|check
argument_list|()
specifier|const
block|{
name|checkGuardBlock
argument_list|(
name|preGuard
argument_list|()
argument_list|,
name|guardBlockBeginVal
argument_list|,
literal|"before"
argument_list|)
block|;
name|checkGuardBlock
argument_list|(
name|postGuard
argument_list|()
argument_list|,
name|guardBlockEndVal
argument_list|,
literal|"after"
argument_list|)
block|;     }
name|void
name|checkAllocList
argument_list|()
specifier|const
expr_stmt|;
comment|// Return total size needed to accomodate user buffer of 'size',
comment|// plus our tracking data.
specifier|inline
specifier|static
name|size_t
name|allocationSize
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
return|return
name|size
operator|+
literal|2
operator|*
name|guardBlockSize
operator|+
name|headerSize
argument_list|()
return|;
block|}
comment|// Offset from surrounding buffer to get to user data buffer.
specifier|inline
specifier|static
name|unsigned
name|char
modifier|*
name|offsetAllocation
parameter_list|(
name|unsigned
name|char
modifier|*
name|m
parameter_list|)
block|{
return|return
name|m
operator|+
name|guardBlockSize
operator|+
name|headerSize
argument_list|()
return|;
block|}
name|private
label|:
name|void
name|checkGuardBlock
argument_list|(
name|unsigned
name|char
operator|*
name|blockMem
argument_list|,
name|unsigned
name|char
name|val
argument_list|,
specifier|const
name|char
operator|*
name|locText
argument_list|)
decl|const
decl_stmt|;
comment|// Find offsets to pre and post guard blocks, and user data buffer
name|unsigned
name|char
operator|*
name|preGuard
argument_list|()
specifier|const
block|{
return|return
name|mem
operator|+
name|headerSize
argument_list|()
return|;
block|}
name|unsigned
name|char
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|preGuard
argument_list|()
operator|+
name|guardBlockSize
return|;
block|}
name|unsigned
name|char
operator|*
name|postGuard
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|+
name|size
return|;
block|}
name|size_t
name|size
decl_stmt|;
comment|// size of the user data area
name|unsigned
name|char
modifier|*
name|mem
decl_stmt|;
comment|// beginning of our allocation (pts to header)
name|TAllocation
modifier|*
name|prevAlloc
decl_stmt|;
comment|// prior allocation in the chain
comment|// Support MSVC++ 6.0
specifier|const
specifier|static
name|unsigned
name|char
name|guardBlockBeginVal
decl_stmt|;
specifier|const
specifier|static
name|unsigned
name|char
name|guardBlockEndVal
decl_stmt|;
specifier|const
specifier|static
name|unsigned
name|char
name|userDataFill
decl_stmt|;
specifier|const
specifier|static
name|size_t
name|guardBlockSize
decl_stmt|;
ifdef|#
directive|ifdef
name|GUARD_BLOCKS
specifier|inline
specifier|static
name|size_t
name|headerSize
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|TAllocation
argument_list|)
return|;
block|}
else|#
directive|else
specifier|inline
specifier|static
name|size_t
name|headerSize
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// There are several stacks.  One is to track the pushing and popping
end_comment
begin_comment
comment|// of the user, and not yet implemented.  The others are simply a
end_comment
begin_comment
comment|// repositories of free pages or used pages.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Page stacks are linked together with a simple header at the beginning
end_comment
begin_comment
comment|// of each allocation obtained from the underlying OS.  Multi-page allocations
end_comment
begin_comment
comment|// are returned to the OS.  Individual page allocations are kept for future
end_comment
begin_comment
comment|// re-use.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// The "page size" used is not, nor must it match, the underlying OS
end_comment
begin_comment
comment|// page size.  But, having it be about that size or equal to a set of
end_comment
begin_comment
comment|// pages is likely most optimal.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|TPoolAllocator
block|{
name|public
label|:
name|TPoolAllocator
argument_list|(
argument|int growthIncrement =
literal|8
argument|*
literal|1024
argument_list|,
argument|int allocationAlignment =
literal|16
argument_list|)
empty_stmt|;
comment|//
comment|// Don't call the destructor just to free up the memory, call pop()
comment|//
operator|~
name|TPoolAllocator
argument_list|()
expr_stmt|;
comment|//
comment|// Call push() to establish a new place to pop memory too.  Does not
comment|// have to be called to get things started.
comment|//
name|void
name|push
parameter_list|()
function_decl|;
comment|//
comment|// Call pop() to free all memory allocated since the last call to push(),
comment|// or if no last call to push, frees all memory since first allocation.
comment|//
name|void
name|pop
parameter_list|()
function_decl|;
comment|//
comment|// Call popAll() to free all memory allocated.
comment|//
name|void
name|popAll
parameter_list|()
function_decl|;
comment|//
comment|// Call allocate() to actually acquire memory.  Returns 0 if no memory
comment|// available, otherwise a properly aligned pointer to 'numBytes' of memory.
comment|//
name|void
modifier|*
name|allocate
parameter_list|(
name|size_t
name|numBytes
parameter_list|)
function_decl|;
comment|//
comment|// There is no deallocate.  The point of this class is that
comment|// deallocation can be skipped by the user of it, as the model
comment|// of use is to simultaneously deallocate everything at once
comment|// by calling pop(), and to not have to solve memory leak problems.
comment|//
name|protected
label|:
name|friend
struct_decl|struct
name|tHeader
struct_decl|;
struct|struct
name|tHeader
block|{
name|tHeader
argument_list|(
argument|tHeader* nextPage
argument_list|,
argument|size_t pageCount
argument_list|)
block|:
name|nextPage
argument_list|(
name|nextPage
argument_list|)
operator|,
name|pageCount
argument_list|(
name|pageCount
argument_list|)
ifdef|#
directive|ifdef
name|GUARD_BLOCKS
operator|,
name|lastAllocation
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
block|{ }
operator|~
name|tHeader
argument_list|()
block|{
ifdef|#
directive|ifdef
name|GUARD_BLOCKS
if|if
condition|(
name|lastAllocation
condition|)
name|lastAllocation
operator|->
name|checkAllocList
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
name|tHeader
modifier|*
name|nextPage
decl_stmt|;
name|size_t
name|pageCount
decl_stmt|;
ifdef|#
directive|ifdef
name|GUARD_BLOCKS
name|TAllocation
modifier|*
name|lastAllocation
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
struct|struct
name|tAllocState
block|{
name|size_t
name|offset
decl_stmt|;
name|tHeader
modifier|*
name|page
decl_stmt|;
block|}
struct|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|tAllocState
operator|>
name|tAllocStack
expr_stmt|;
comment|// Track allocations if and only if we're using guard blocks
name|void
modifier|*
name|initializeAllocation
parameter_list|(
name|tHeader
modifier|*
name|block
parameter_list|,
name|unsigned
name|char
modifier|*
name|memory
parameter_list|,
name|size_t
name|numBytes
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|GUARD_BLOCKS
name|new
argument_list|(
argument|memory
argument_list|)
name|TAllocation
argument_list|(
name|numBytes
argument_list|,
name|memory
argument_list|,
name|block
operator|->
name|lastAllocation
argument_list|)
expr_stmt|;
name|block
operator|->
name|lastAllocation
operator|=
name|reinterpret_cast
operator|<
name|TAllocation
operator|*
operator|>
operator|(
name|memory
operator|)
expr_stmt|;
endif|#
directive|endif
comment|// This is optimized entirely away if GUARD_BLOCKS is not defined.
return|return
name|TAllocation
operator|::
name|offsetAllocation
argument_list|(
name|memory
argument_list|)
return|;
block|}
name|size_t
name|pageSize
decl_stmt|;
comment|// granularity of allocation from the OS
name|size_t
name|alignment
decl_stmt|;
comment|// all returned allocations will be aligned at
comment|// this granularity, which will be a power of 2
name|size_t
name|alignmentMask
decl_stmt|;
name|size_t
name|headerSkip
decl_stmt|;
comment|// amount of memory to skip to make room for the
comment|//      header (basically, size of header, rounded
comment|//      up to make it aligned
name|size_t
name|currentPageOffset
decl_stmt|;
comment|// next offset in top of inUseList to allocate from
name|tHeader
modifier|*
name|freeList
decl_stmt|;
comment|// list of popped memory
name|tHeader
modifier|*
name|inUseList
decl_stmt|;
comment|// list of all memory currently being used
name|tAllocStack
name|stack
decl_stmt|;
comment|// stack of where to allocate from, to partition pool
name|int
name|numCalls
decl_stmt|;
comment|// just an interesting statistic
name|size_t
name|totalBytes
decl_stmt|;
comment|// just an interesting statistic
name|private
label|:
name|TPoolAllocator
modifier|&
name|operator
init|=
operator|(
specifier|const
name|TPoolAllocator
operator|&
operator|)
decl_stmt|;
comment|// dont allow assignment operator
name|TPoolAllocator
argument_list|(
specifier|const
name|TPoolAllocator
operator|&
argument_list|)
expr_stmt|;
comment|// dont allow default copy constructor
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// There could potentially be many pools with pops happening at
end_comment
begin_comment
comment|// different times.  But a simple use is to have a global pop
end_comment
begin_comment
comment|// with everyone using the same global allocator.
end_comment
begin_comment
comment|//
end_comment
begin_function_decl
specifier|extern
name|TPoolAllocator
modifier|*
name|GetGlobalPoolAllocator
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|void
name|SetGlobalPoolAllocator
parameter_list|(
name|TPoolAllocator
modifier|*
name|poolAllocator
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//
end_comment
begin_comment
comment|// This STL compatible allocator is intended to be used as the allocator
end_comment
begin_comment
comment|// parameter to templatized STL containers, like vector and map.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// It will use the pools for allocation, and not
end_comment
begin_comment
comment|// do any deallocation, but will still do destruction.
end_comment
begin_comment
comment|//
end_comment
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|pool_allocator
block|{
name|public
operator|:
typedef|typedef
name|size_t
name|size_type
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|T
modifier|*
name|pointer
typedef|;
end_typedef
begin_typedef
typedef|typedef
specifier|const
name|T
modifier|*
name|const_pointer
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|T
modifier|&
name|reference
typedef|;
end_typedef
begin_typedef
typedef|typedef
specifier|const
name|T
modifier|&
name|const_reference
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|T
name|value_type
typedef|;
end_typedef
begin_expr_stmt
name|template
operator|<
name|class
name|Other
operator|>
expr|struct
name|rebind
block|{
typedef|typedef
name|pool_allocator
operator|<
name|Other
operator|>
name|other
expr_stmt|;
block|}
end_expr_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|pointer
name|address
argument_list|(
name|reference
name|x
argument_list|)
decl|const
block|{
return|return
operator|&
name|x
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|const_pointer
name|address
argument_list|(
name|const_reference
name|x
argument_list|)
decl|const
block|{
return|return
operator|&
name|x
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|pool_allocator
argument_list|()
operator|:
name|allocator
argument_list|(
argument|GetGlobalPoolAllocator()
argument_list|)
block|{ }
name|pool_allocator
argument_list|(
name|TPoolAllocator
operator|&
name|a
argument_list|)
operator|:
name|allocator
argument_list|(
argument|&a
argument_list|)
block|{ }
name|pool_allocator
argument_list|(
specifier|const
name|pool_allocator
operator|<
name|T
operator|>
operator|&
name|p
argument_list|)
operator|:
name|allocator
argument_list|(
argument|p.allocator
argument_list|)
block|{ }
name|template
operator|<
name|class
name|Other
operator|>
name|pool_allocator
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|pool_allocator
operator|<
name|Other
operator|>
operator|&
name|p
operator|)
block|{
name|allocator
operator|=
name|p
operator|.
name|allocator
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|Other
operator|>
name|pool_allocator
argument_list|(
specifier|const
name|pool_allocator
operator|<
name|Other
operator|>
operator|&
name|p
argument_list|)
operator|:
name|allocator
argument_list|(
argument|&p.getAllocator()
argument_list|)
block|{ }
if|#
directive|if
name|defined
argument_list|(
name|__SUNPRO_CC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_RWSTD_ALLOCATOR
argument_list|)
comment|// libCStd on some platforms have a different allocate/deallocate interface.
comment|// Caller pre-bakes sizeof(T) into 'n' which is the number of bytes to be
comment|// allocated, not the number of elements.
name|void
operator|*
name|allocate
argument_list|(
argument|size_type n
argument_list|)
block|{
return|return
name|getAllocator
argument_list|()
operator|.
name|allocate
argument_list|(
name|n
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
name|void
modifier|*
name|allocate
parameter_list|(
name|size_type
name|n
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
block|{
return|return
name|getAllocator
argument_list|()
operator|.
name|allocate
argument_list|(
name|n
argument_list|)
return|;
block|}
end_function
begin_function
name|void
name|deallocate
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_type
parameter_list|)
block|{}
end_function
begin_else
else|#
directive|else
end_else
begin_function
name|pointer
name|allocate
parameter_list|(
name|size_type
name|n
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|pointer
operator|>
operator|(
name|getAllocator
argument_list|()
operator|.
name|allocate
argument_list|(
name|n
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
name|pointer
name|allocate
parameter_list|(
name|size_type
name|n
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|pointer
operator|>
operator|(
name|getAllocator
argument_list|()
operator|.
name|allocate
argument_list|(
name|n
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
name|void
name|deallocate
parameter_list|(
name|pointer
parameter_list|,
name|size_type
parameter_list|)
block|{}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// _RWSTD_ALLOCATOR
end_comment
begin_function
name|void
name|construct
parameter_list|(
name|pointer
name|p
parameter_list|,
specifier|const
name|T
modifier|&
name|val
parameter_list|)
block|{
name|new
argument_list|(
argument|(void *)p
argument_list|)
name|T
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|destroy
parameter_list|(
name|pointer
name|p
parameter_list|)
block|{
name|p
operator|->
name|T
operator|::
operator|~
name|T
argument_list|()
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|pool_allocator
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
operator|&
name|getAllocator
argument_list|()
operator|==
operator|&
name|rhs
operator|.
name|getAllocator
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|pool_allocator
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
operator|&
name|getAllocator
argument_list|()
operator|!=
operator|&
name|rhs
operator|.
name|getAllocator
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|size_type
name|max_size
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|size_type
operator|>
operator|(
operator|-
literal|1
operator|)
operator|/
sizeof|sizeof
argument_list|(
name|T
argument_list|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|size_type
name|max_size
argument_list|(
name|int
name|size
argument_list|)
decl|const
block|{
return|return
name|static_cast
operator|<
name|size_type
operator|>
operator|(
operator|-
literal|1
operator|)
operator|/
name|size
return|;
block|}
end_decl_stmt
begin_function
name|void
name|setAllocator
parameter_list|(
name|TPoolAllocator
modifier|*
name|a
parameter_list|)
block|{
name|allocator
operator|=
name|a
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|TPoolAllocator
operator|&
name|getAllocator
argument_list|()
specifier|const
block|{
return|return
operator|*
name|allocator
return|;
block|}
end_expr_stmt
begin_label
name|protected
label|:
end_label
begin_decl_stmt
name|TPoolAllocator
modifier|*
name|allocator
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_POOLALLOC_H_
end_comment
end_unit
