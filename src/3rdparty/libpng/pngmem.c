begin_unit
begin_comment
comment|/* pngmem.c - stub functions for memory allocation  *  * Last changed in libpng 1.5.1 [February 3, 2011]  * Copyright (c) 1998-2011 Glenn Randers-Pehrson  * (Version 0.96 Copyright (c) 1996, 1997 Andreas Dilger)  * (Version 0.88 Copyright (c) 1995, 1996 Guy Eric Schalnat, Group 42, Inc.)  *  * This code is released under the libpng license.  * For conditions of distribution and use, see the disclaimer  * and license in png.h  *  * This file provides a location for all memory allocation.  Users who  * need special memory handling are expected to supply replacement  * functions for png_malloc() and png_free(), and to use  * png_create_read_struct_2() and png_create_write_struct_2() to  * identify the replacement functions.  */
end_comment
begin_include
include|#
directive|include
file|"pngpriv.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PNG_READ_SUPPORTED
argument_list|)
operator|||
name|defined
argument_list|(
name|PNG_WRITE_SUPPORTED
argument_list|)
end_if
begin_comment
comment|/* Borland DOS special memory handler */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__TURBOC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_Windows
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__FLAT__
argument_list|)
end_if
begin_comment
comment|/* If you change this, be sure to change the one in png.h also */
end_comment
begin_comment
comment|/* Allocate memory for a png_struct.  The malloc and memset can be replaced    by a single call to calloc() if this is thought to improve performance. */
end_comment
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
comment|/* PRIVATE */
argument_list|,
argument|png_create_struct
argument_list|,
argument|(int type)
argument_list|,
argument|PNG_ALLOCATED
argument_list|)
end_macro
begin_block
block|{
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
return|return
operator|(
name|png_create_struct_2
argument_list|(
name|type
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
operator|)
return|;
block|}
end_block
begin_comment
comment|/* Alternate version of png_create_struct, for use with user-defined malloc. */
end_comment
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
comment|/* PRIVATE */
argument_list|,
argument|png_create_struct_2
argument_list|,
argument|(int type, png_malloc_ptr malloc_fn, png_voidp mem_ptr)
argument_list|,
argument|PNG_ALLOCATED
argument_list|)
end_macro
begin_block
block|{
endif|#
directive|endif
comment|/* PNG_USER_MEM_SUPPORTED */
name|png_size_t
name|size
decl_stmt|;
name|png_voidp
name|struct_ptr
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|PNG_STRUCT_INFO
condition|)
name|size
operator|=
name|png_sizeof
argument_list|(
name|png_info
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|type
operator|==
name|PNG_STRUCT_PNG
condition|)
name|size
operator|=
name|png_sizeof
argument_list|(
name|png_struct
argument_list|)
expr_stmt|;
else|else
return|return
operator|(
name|png_get_copyright
argument_list|(
name|NULL
argument_list|)
operator|)
return|;
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
if|if
condition|(
name|malloc_fn
operator|!=
name|NULL
condition|)
block|{
name|png_struct
name|dummy_struct
decl_stmt|;
name|png_structp
name|png_ptr
init|=
operator|&
name|dummy_struct
decl_stmt|;
name|png_ptr
operator|->
name|mem_ptr
operator|=
name|mem_ptr
expr_stmt|;
name|struct_ptr
operator|=
operator|(
operator|*
operator|(
name|malloc_fn
operator|)
operator|)
operator|(
name|png_ptr
operator|,
operator|(
name|png_uint_32
operator|)
name|size
operator|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
comment|/* PNG_USER_MEM_SUPPORTED */
name|struct_ptr
operator|=
operator|(
name|png_voidp
operator|)
name|farmalloc
argument_list|(
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|struct_ptr
operator|!=
name|NULL
condition|)
name|png_memset
argument_list|(
name|struct_ptr
argument_list|,
literal|0
argument_list|,
name|size
argument_list|)
expr_stmt|;
return|return
operator|(
name|struct_ptr
operator|)
return|;
block|}
end_block
begin_comment
comment|/* Free memory allocated by a png_create_struct() call */
end_comment
begin_function
name|void
comment|/* PRIVATE */
DECL|function|png_destroy_struct
name|png_destroy_struct
parameter_list|(
name|png_voidp
name|struct_ptr
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
name|png_destroy_struct_2
argument_list|(
name|struct_ptr
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/* Free memory allocated by a png_create_struct() call */
end_comment
begin_function
name|void
comment|/* PRIVATE */
DECL|function|png_destroy_struct_2
name|png_destroy_struct_2
parameter_list|(
name|png_voidp
name|struct_ptr
parameter_list|,
name|png_free_ptr
name|free_fn
parameter_list|,
name|png_voidp
name|mem_ptr
parameter_list|)
block|{
endif|#
directive|endif
if|if
condition|(
name|struct_ptr
operator|!=
name|NULL
condition|)
block|{
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
if|if
condition|(
name|free_fn
operator|!=
name|NULL
condition|)
block|{
name|png_struct
name|dummy_struct
decl_stmt|;
name|png_structp
name|png_ptr
init|=
operator|&
name|dummy_struct
decl_stmt|;
name|png_ptr
operator|->
name|mem_ptr
operator|=
name|mem_ptr
expr_stmt|;
operator|(
operator|*
operator|(
name|free_fn
operator|)
operator|)
operator|(
name|png_ptr
operator|,
name|struct_ptr
operator|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
comment|/* PNG_USER_MEM_SUPPORTED */
name|farfree
argument_list|(
name|struct_ptr
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/* Allocate memory.  For reasonable files, size should never exceed  * 64K.  However, zlib may allocate more then 64K if you don't tell  * it not to.  See zconf.h and png.h for more information. zlib does  * need to allocate exactly 64K, so whatever you call here must  * have the ability to do that.  *  * Borland seems to have a problem in DOS mode for exactly 64K.  * It gives you a segment with an offset of 8 (perhaps to store its  * memory stuff).  zlib doesn't like this at all, so we have to  * detect and deal with it.  This code should not be needed in  * Windows or OS/2 modes, and only in 16 bit mode.  This code has  * been updated by Alexander Lehmann for version 0.89 to waste less  * memory.  *  * Note that we can't use png_size_t for the "size" declaration,  * since on some systems a png_size_t is a 16-bit quantity, and as a  * result, we would be truncating potentially larger memory requests  * (which should cause a fatal error) and introducing major problems.  */
end_comment
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
argument_list|,
argument|PNGAPI png_calloc
argument_list|,
argument|(png_structp png_ptr, png_alloc_size_t size)
argument_list|,
argument|PNG_ALLOCATED
argument_list|)
end_macro
begin_block
block|{
name|png_voidp
name|ret
decl_stmt|;
name|ret
operator|=
operator|(
name|png_malloc
argument_list|(
name|png_ptr
argument_list|,
name|size
argument_list|)
operator|)
expr_stmt|;
if|if
condition|(
name|ret
operator|!=
name|NULL
condition|)
name|png_memset
argument_list|(
name|ret
argument_list|,
literal|0
argument_list|,
operator|(
name|png_size_t
operator|)
name|size
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_block
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
argument_list|,
argument|PNGAPI png_malloc
argument_list|,
argument|(png_structp png_ptr, png_alloc_size_t size)
argument_list|,
argument|PNG_ALLOCATED
argument_list|)
end_macro
begin_block
block|{
name|png_voidp
name|ret
decl_stmt|;
if|if
condition|(
name|png_ptr
operator|==
name|NULL
operator|||
name|size
operator|==
literal|0
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
if|if
condition|(
name|png_ptr
operator|->
name|malloc_fn
operator|!=
name|NULL
condition|)
name|ret
operator|=
operator|(
call|(
name|png_voidp
call|)
argument_list|(
operator|*
operator|(
name|png_ptr
operator|->
name|malloc_fn
operator|)
argument_list|)
argument_list|(
name|png_ptr
argument_list|,
operator|(
name|png_size_t
operator|)
name|size
argument_list|)
operator|)
expr_stmt|;
else|else
name|ret
operator|=
operator|(
name|png_malloc_default
argument_list|(
name|png_ptr
argument_list|,
name|size
argument_list|)
operator|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
name|NULL
operator|&&
operator|(
name|png_ptr
operator|->
name|flags
operator|&
name|PNG_FLAG_MALLOC_NULL_MEM_OK
operator|)
operator|==
literal|0
condition|)
name|png_error
argument_list|(
name|png_ptr
argument_list|,
literal|"Out of memory"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_block
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
argument_list|,
argument|PNGAPI png_malloc_default
argument_list|,
argument|(png_structp png_ptr, png_alloc_size_t size)
argument_list|,
argument|PNG_ALLOCATED
argument_list|)
end_macro
begin_block
block|{
name|png_voidp
name|ret
decl_stmt|;
endif|#
directive|endif
comment|/* PNG_USER_MEM_SUPPORTED */
if|if
condition|(
name|png_ptr
operator|==
name|NULL
operator|||
name|size
operator|==
literal|0
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
ifdef|#
directive|ifdef
name|PNG_MAX_MALLOC_64K
if|if
condition|(
name|size
operator|>
operator|(
name|png_uint_32
operator|)
literal|65536L
condition|)
block|{
name|png_warning
argument_list|(
name|png_ptr
argument_list|,
literal|"Cannot Allocate> 64K"
argument_list|)
expr_stmt|;
name|ret
operator|=
name|NULL
expr_stmt|;
block|}
elseif|else
endif|#
directive|endif
if|if
condition|(
name|size
operator|!=
operator|(
name|size_t
operator|)
name|size
condition|)
name|ret
operator|=
name|NULL
expr_stmt|;
elseif|else
if|if
condition|(
name|size
operator|==
operator|(
name|png_uint_32
operator|)
literal|65536L
condition|)
block|{
if|if
condition|(
name|png_ptr
operator|->
name|offset_table
operator|==
name|NULL
condition|)
block|{
comment|/* Try to see if we need to do any of this fancy stuff */
name|ret
operator|=
name|farmalloc
argument_list|(
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
name|NULL
operator|||
operator|(
operator|(
name|png_size_t
operator|)
name|ret
operator|&
literal|0xffff
operator|)
condition|)
block|{
name|int
name|num_blocks
decl_stmt|;
name|png_uint_32
name|total_size
decl_stmt|;
name|png_bytep
name|table
decl_stmt|;
name|int
name|i
decl_stmt|;
name|png_byte
name|huge
modifier|*
name|hptr
decl_stmt|;
if|if
condition|(
name|ret
operator|!=
name|NULL
condition|)
block|{
name|farfree
argument_list|(
name|ret
argument_list|)
expr_stmt|;
name|ret
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|png_ptr
operator|->
name|zlib_window_bits
operator|>
literal|14
condition|)
name|num_blocks
operator|=
call|(
name|int
call|)
argument_list|(
literal|1
operator|<<
operator|(
name|png_ptr
operator|->
name|zlib_window_bits
operator|-
literal|14
operator|)
argument_list|)
expr_stmt|;
else|else
name|num_blocks
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|png_ptr
operator|->
name|zlib_mem_level
operator|>=
literal|7
condition|)
name|num_blocks
operator|+=
call|(
name|int
call|)
argument_list|(
literal|1
operator|<<
operator|(
name|png_ptr
operator|->
name|zlib_mem_level
operator|-
literal|7
operator|)
argument_list|)
expr_stmt|;
else|else
name|num_blocks
operator|++
expr_stmt|;
name|total_size
operator|=
operator|(
operator|(
name|png_uint_32
operator|)
literal|65536L
operator|)
operator|*
operator|(
name|png_uint_32
operator|)
name|num_blocks
operator|+
literal|16
expr_stmt|;
name|table
operator|=
name|farmalloc
argument_list|(
name|total_size
argument_list|)
expr_stmt|;
if|if
condition|(
name|table
operator|==
name|NULL
condition|)
block|{
ifndef|#
directive|ifndef
name|PNG_USER_MEM_SUPPORTED
if|if
condition|(
operator|(
name|png_ptr
operator|->
name|flags
operator|&
name|PNG_FLAG_MALLOC_NULL_MEM_OK
operator|)
operator|==
literal|0
condition|)
name|png_error
argument_list|(
name|png_ptr
argument_list|,
literal|"Out Of Memory"
argument_list|)
expr_stmt|;
comment|/* Note "O", "M" */
else|else
name|png_warning
argument_list|(
name|png_ptr
argument_list|,
literal|"Out Of Memory"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|NULL
operator|)
return|;
block|}
if|if
condition|(
operator|(
name|png_size_t
operator|)
name|table
operator|&
literal|0xfff0
condition|)
block|{
ifndef|#
directive|ifndef
name|PNG_USER_MEM_SUPPORTED
if|if
condition|(
operator|(
name|png_ptr
operator|->
name|flags
operator|&
name|PNG_FLAG_MALLOC_NULL_MEM_OK
operator|)
operator|==
literal|0
condition|)
name|png_error
argument_list|(
name|png_ptr
argument_list|,
literal|"Farmalloc didn't return normalized pointer"
argument_list|)
expr_stmt|;
else|else
name|png_warning
argument_list|(
name|png_ptr
argument_list|,
literal|"Farmalloc didn't return normalized pointer"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|png_ptr
operator|->
name|offset_table
operator|=
name|table
expr_stmt|;
name|png_ptr
operator|->
name|offset_table_ptr
operator|=
name|farmalloc
argument_list|(
name|num_blocks
operator|*
name|png_sizeof
argument_list|(
name|png_bytep
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|png_ptr
operator|->
name|offset_table_ptr
operator|==
name|NULL
condition|)
block|{
ifndef|#
directive|ifndef
name|PNG_USER_MEM_SUPPORTED
if|if
condition|(
operator|(
name|png_ptr
operator|->
name|flags
operator|&
name|PNG_FLAG_MALLOC_NULL_MEM_OK
operator|)
operator|==
literal|0
condition|)
name|png_error
argument_list|(
name|png_ptr
argument_list|,
literal|"Out Of memory"
argument_list|)
expr_stmt|;
comment|/* Note "O", "m" */
else|else
name|png_warning
argument_list|(
name|png_ptr
argument_list|,
literal|"Out Of memory"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|hptr
operator|=
operator|(
name|png_byte
name|huge
operator|*
operator|)
name|table
expr_stmt|;
if|if
condition|(
operator|(
name|png_size_t
operator|)
name|hptr
operator|&
literal|0xf
condition|)
block|{
name|hptr
operator|=
operator|(
name|png_byte
name|huge
operator|*
operator|)
operator|(
call|(
name|long
call|)
argument_list|(
name|hptr
argument_list|)
operator|&
literal|0xfffffff0L
operator|)
expr_stmt|;
name|hptr
operator|=
name|hptr
operator|+
literal|16L
expr_stmt|;
comment|/* "hptr += 16L" fails on Turbo C++ 3.0 */
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|num_blocks
condition|;
name|i
operator|++
control|)
block|{
name|png_ptr
operator|->
name|offset_table_ptr
index|[
name|i
index|]
operator|=
operator|(
name|png_bytep
operator|)
name|hptr
expr_stmt|;
name|hptr
operator|=
name|hptr
operator|+
operator|(
name|png_uint_32
operator|)
literal|65536L
expr_stmt|;
comment|/* "+=" fails on TC++3.0 */
block|}
name|png_ptr
operator|->
name|offset_table_number
operator|=
name|num_blocks
expr_stmt|;
name|png_ptr
operator|->
name|offset_table_count
operator|=
literal|0
expr_stmt|;
name|png_ptr
operator|->
name|offset_table_count_free
operator|=
literal|0
expr_stmt|;
block|}
block|}
if|if
condition|(
name|png_ptr
operator|->
name|offset_table_count
operator|>=
name|png_ptr
operator|->
name|offset_table_number
condition|)
block|{
ifndef|#
directive|ifndef
name|PNG_USER_MEM_SUPPORTED
if|if
condition|(
operator|(
name|png_ptr
operator|->
name|flags
operator|&
name|PNG_FLAG_MALLOC_NULL_MEM_OK
operator|)
operator|==
literal|0
condition|)
name|png_error
argument_list|(
name|png_ptr
argument_list|,
literal|"Out of Memory"
argument_list|)
expr_stmt|;
comment|/* Note "o" and "M" */
else|else
name|png_warning
argument_list|(
name|png_ptr
argument_list|,
literal|"Out of Memory"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|ret
operator|=
name|png_ptr
operator|->
name|offset_table_ptr
index|[
name|png_ptr
operator|->
name|offset_table_count
operator|++
index|]
expr_stmt|;
block|}
else|else
name|ret
operator|=
name|farmalloc
argument_list|(
name|size
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|PNG_USER_MEM_SUPPORTED
if|if
condition|(
name|ret
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
operator|(
name|png_ptr
operator|->
name|flags
operator|&
name|PNG_FLAG_MALLOC_NULL_MEM_OK
operator|)
operator|==
literal|0
condition|)
name|png_error
argument_list|(
name|png_ptr
argument_list|,
literal|"Out of memory"
argument_list|)
expr_stmt|;
comment|/* Note "o" and "m" */
else|else
name|png_warning
argument_list|(
name|png_ptr
argument_list|,
literal|"Out of memory"
argument_list|)
expr_stmt|;
comment|/* Note "o" and "m" */
block|}
endif|#
directive|endif
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_block
begin_comment
comment|/* Free a pointer allocated by png_malloc().  In the default  * configuration, png_ptr is not used, but is passed in case it  * is needed.  If ptr is NULL, return without taking any action.  */
end_comment
begin_function
name|void
name|PNGAPI
DECL|function|png_free
name|png_free
parameter_list|(
name|png_structp
name|png_ptr
parameter_list|,
name|png_voidp
name|ptr
parameter_list|)
block|{
if|if
condition|(
name|png_ptr
operator|==
name|NULL
operator|||
name|ptr
operator|==
name|NULL
condition|)
return|return;
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
if|if
condition|(
name|png_ptr
operator|->
name|free_fn
operator|!=
name|NULL
condition|)
block|{
operator|(
operator|*
operator|(
name|png_ptr
operator|->
name|free_fn
operator|)
operator|)
operator|(
name|png_ptr
operator|,
name|ptr
operator|)
expr_stmt|;
return|return;
block|}
else|else
name|png_free_default
argument_list|(
name|png_ptr
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|PNGAPI
DECL|function|png_free_default
name|png_free_default
parameter_list|(
name|png_structp
name|png_ptr
parameter_list|,
name|png_voidp
name|ptr
parameter_list|)
block|{
endif|#
directive|endif
comment|/* PNG_USER_MEM_SUPPORTED */
if|if
condition|(
name|png_ptr
operator|==
name|NULL
operator|||
name|ptr
operator|==
name|NULL
condition|)
return|return;
if|if
condition|(
name|png_ptr
operator|->
name|offset_table
operator|!=
name|NULL
condition|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|png_ptr
operator|->
name|offset_table_count
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|ptr
operator|==
name|png_ptr
operator|->
name|offset_table_ptr
index|[
name|i
index|]
condition|)
block|{
name|ptr
operator|=
name|NULL
expr_stmt|;
name|png_ptr
operator|->
name|offset_table_count_free
operator|++
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|png_ptr
operator|->
name|offset_table_count_free
operator|==
name|png_ptr
operator|->
name|offset_table_count
condition|)
block|{
name|farfree
argument_list|(
name|png_ptr
operator|->
name|offset_table
argument_list|)
expr_stmt|;
name|farfree
argument_list|(
name|png_ptr
operator|->
name|offset_table_ptr
argument_list|)
expr_stmt|;
name|png_ptr
operator|->
name|offset_table
operator|=
name|NULL
expr_stmt|;
name|png_ptr
operator|->
name|offset_table_ptr
operator|=
name|NULL
expr_stmt|;
block|}
block|}
if|if
condition|(
name|ptr
operator|!=
name|NULL
condition|)
name|farfree
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* Not the Borland DOS special memory handler */
end_comment
begin_comment
comment|/* Allocate memory for a png_struct or a png_info.  The malloc and    memset can be replaced by a single call to calloc() if this is thought    to improve performance noticably. */
end_comment
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
comment|/* PRIVATE */
argument_list|,
argument|png_create_struct
argument_list|,
argument|(int type)
argument_list|,
argument|PNG_ALLOCATED
argument_list|)
end_macro
begin_block
block|{
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
return|return
operator|(
name|png_create_struct_2
argument_list|(
name|type
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
operator|)
return|;
block|}
end_block
begin_comment
comment|/* Allocate memory for a png_struct or a png_info.  The malloc and    memset can be replaced by a single call to calloc() if this is thought    to improve performance noticably. */
end_comment
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
comment|/* PRIVATE */
argument_list|,
argument|png_create_struct_2
argument_list|,
argument|(int type, png_malloc_ptr malloc_fn, png_voidp mem_ptr)
argument_list|,
argument|PNG_ALLOCATED
argument_list|)
end_macro
begin_block
block|{
endif|#
directive|endif
comment|/* PNG_USER_MEM_SUPPORTED */
name|png_size_t
name|size
decl_stmt|;
name|png_voidp
name|struct_ptr
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|PNG_STRUCT_INFO
condition|)
name|size
operator|=
name|png_sizeof
argument_list|(
name|png_info
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|type
operator|==
name|PNG_STRUCT_PNG
condition|)
name|size
operator|=
name|png_sizeof
argument_list|(
name|png_struct
argument_list|)
expr_stmt|;
else|else
return|return
operator|(
name|NULL
operator|)
return|;
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
if|if
condition|(
name|malloc_fn
operator|!=
name|NULL
condition|)
block|{
name|png_struct
name|dummy_struct
decl_stmt|;
name|png_structp
name|png_ptr
init|=
operator|&
name|dummy_struct
decl_stmt|;
name|png_ptr
operator|->
name|mem_ptr
operator|=
name|mem_ptr
expr_stmt|;
name|struct_ptr
operator|=
operator|(
operator|*
operator|(
name|malloc_fn
operator|)
operator|)
operator|(
name|png_ptr
operator|,
name|size
operator|)
expr_stmt|;
if|if
condition|(
name|struct_ptr
operator|!=
name|NULL
condition|)
name|png_memset
argument_list|(
name|struct_ptr
argument_list|,
literal|0
argument_list|,
name|size
argument_list|)
expr_stmt|;
return|return
operator|(
name|struct_ptr
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* PNG_USER_MEM_SUPPORTED */
if|#
directive|if
name|defined
argument_list|(
name|__TURBOC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__FLAT__
argument_list|)
name|struct_ptr
operator|=
operator|(
name|png_voidp
operator|)
name|farmalloc
argument_list|(
name|size
argument_list|)
expr_stmt|;
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|defined
argument_list|(
name|MAXSEG_64K
argument_list|)
name|struct_ptr
operator|=
operator|(
name|png_voidp
operator|)
name|halloc
argument_list|(
name|size
argument_list|,
literal|1
argument_list|)
expr_stmt|;
else|#
directive|else
name|struct_ptr
operator|=
operator|(
name|png_voidp
operator|)
name|malloc
argument_list|(
name|size
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
if|if
condition|(
name|struct_ptr
operator|!=
name|NULL
condition|)
name|png_memset
argument_list|(
name|struct_ptr
argument_list|,
literal|0
argument_list|,
name|size
argument_list|)
expr_stmt|;
return|return
operator|(
name|struct_ptr
operator|)
return|;
block|}
end_block
begin_comment
comment|/* Free memory allocated by a png_create_struct() call */
end_comment
begin_function
name|void
comment|/* PRIVATE */
DECL|function|png_destroy_struct
name|png_destroy_struct
parameter_list|(
name|png_voidp
name|struct_ptr
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
name|png_destroy_struct_2
argument_list|(
name|struct_ptr
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/* Free memory allocated by a png_create_struct() call */
end_comment
begin_function
name|void
comment|/* PRIVATE */
DECL|function|png_destroy_struct_2
name|png_destroy_struct_2
parameter_list|(
name|png_voidp
name|struct_ptr
parameter_list|,
name|png_free_ptr
name|free_fn
parameter_list|,
name|png_voidp
name|mem_ptr
parameter_list|)
block|{
endif|#
directive|endif
comment|/* PNG_USER_MEM_SUPPORTED */
if|if
condition|(
name|struct_ptr
operator|!=
name|NULL
condition|)
block|{
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
if|if
condition|(
name|free_fn
operator|!=
name|NULL
condition|)
block|{
name|png_struct
name|dummy_struct
decl_stmt|;
name|png_structp
name|png_ptr
init|=
operator|&
name|dummy_struct
decl_stmt|;
name|png_ptr
operator|->
name|mem_ptr
operator|=
name|mem_ptr
expr_stmt|;
operator|(
operator|*
operator|(
name|free_fn
operator|)
operator|)
operator|(
name|png_ptr
operator|,
name|struct_ptr
operator|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
comment|/* PNG_USER_MEM_SUPPORTED */
if|#
directive|if
name|defined
argument_list|(
name|__TURBOC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__FLAT__
argument_list|)
name|farfree
argument_list|(
name|struct_ptr
argument_list|)
expr_stmt|;
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|defined
argument_list|(
name|MAXSEG_64K
argument_list|)
name|hfree
argument_list|(
name|struct_ptr
argument_list|)
expr_stmt|;
else|#
directive|else
name|free
argument_list|(
name|struct_ptr
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
block|}
block|}
end_function
begin_comment
comment|/* Allocate memory.  For reasonable files, size should never exceed  * 64K.  However, zlib may allocate more then 64K if you don't tell  * it not to.  See zconf.h and png.h for more information.  zlib does  * need to allocate exactly 64K, so whatever you call here must  * have the ability to do that.  */
end_comment
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
argument_list|,
argument|PNGAPI png_calloc
argument_list|,
argument|(png_structp png_ptr, png_alloc_size_t size)
argument_list|,
argument|PNG_ALLOCATED
argument_list|)
end_macro
begin_block
block|{
name|png_voidp
name|ret
decl_stmt|;
name|ret
operator|=
operator|(
name|png_malloc
argument_list|(
name|png_ptr
argument_list|,
name|size
argument_list|)
operator|)
expr_stmt|;
if|if
condition|(
name|ret
operator|!=
name|NULL
condition|)
name|png_memset
argument_list|(
name|ret
argument_list|,
literal|0
argument_list|,
operator|(
name|png_size_t
operator|)
name|size
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_block
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
argument_list|,
argument|PNGAPI png_malloc
argument_list|,
argument|(png_structp png_ptr, png_alloc_size_t size)
argument_list|,
argument|PNG_ALLOCATED
argument_list|)
end_macro
begin_block
block|{
name|png_voidp
name|ret
decl_stmt|;
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
if|if
condition|(
name|png_ptr
operator|==
name|NULL
operator|||
name|size
operator|==
literal|0
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
if|if
condition|(
name|png_ptr
operator|->
name|malloc_fn
operator|!=
name|NULL
condition|)
name|ret
operator|=
operator|(
call|(
name|png_voidp
call|)
argument_list|(
operator|*
operator|(
name|png_ptr
operator|->
name|malloc_fn
operator|)
argument_list|)
argument_list|(
name|png_ptr
argument_list|,
operator|(
name|png_size_t
operator|)
name|size
argument_list|)
operator|)
expr_stmt|;
else|else
name|ret
operator|=
operator|(
name|png_malloc_default
argument_list|(
name|png_ptr
argument_list|,
name|size
argument_list|)
operator|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
name|NULL
operator|&&
operator|(
name|png_ptr
operator|->
name|flags
operator|&
name|PNG_FLAG_MALLOC_NULL_MEM_OK
operator|)
operator|==
literal|0
condition|)
name|png_error
argument_list|(
name|png_ptr
argument_list|,
literal|"Out of Memory"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_block
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
argument_list|,
argument|PNGAPI png_malloc_default
argument_list|,
argument|(png_structp png_ptr, png_alloc_size_t size)
argument_list|,
argument|PNG_ALLOCATED
argument_list|)
end_macro
begin_block
block|{
name|png_voidp
name|ret
decl_stmt|;
endif|#
directive|endif
comment|/* PNG_USER_MEM_SUPPORTED */
if|if
condition|(
name|png_ptr
operator|==
name|NULL
operator|||
name|size
operator|==
literal|0
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
ifdef|#
directive|ifdef
name|PNG_MAX_MALLOC_64K
if|if
condition|(
name|size
operator|>
operator|(
name|png_uint_32
operator|)
literal|65536L
condition|)
block|{
ifndef|#
directive|ifndef
name|PNG_USER_MEM_SUPPORTED
if|if
condition|(
operator|(
name|png_ptr
operator|->
name|flags
operator|&
name|PNG_FLAG_MALLOC_NULL_MEM_OK
operator|)
operator|==
literal|0
condition|)
name|png_error
argument_list|(
name|png_ptr
argument_list|,
literal|"Cannot Allocate> 64K"
argument_list|)
expr_stmt|;
else|else
endif|#
directive|endif
return|return
name|NULL
return|;
block|}
endif|#
directive|endif
comment|/* Check for overflow */
if|#
directive|if
name|defined
argument_list|(
name|__TURBOC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__FLAT__
argument_list|)
if|if
condition|(
name|size
operator|!=
operator|(
name|unsigned
name|long
operator|)
name|size
condition|)
name|ret
operator|=
name|NULL
expr_stmt|;
else|else
name|ret
operator|=
name|farmalloc
argument_list|(
name|size
argument_list|)
expr_stmt|;
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|defined
argument_list|(
name|MAXSEG_64K
argument_list|)
if|if
condition|(
name|size
operator|!=
operator|(
name|unsigned
name|long
operator|)
name|size
condition|)
name|ret
operator|=
name|NULL
expr_stmt|;
else|else
name|ret
operator|=
name|halloc
argument_list|(
name|size
argument_list|,
literal|1
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|size
operator|!=
operator|(
name|size_t
operator|)
name|size
condition|)
name|ret
operator|=
name|NULL
expr_stmt|;
else|else
name|ret
operator|=
name|malloc
argument_list|(
operator|(
name|size_t
operator|)
name|size
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_USER_MEM_SUPPORTED
if|if
condition|(
name|ret
operator|==
name|NULL
operator|&&
operator|(
name|png_ptr
operator|->
name|flags
operator|&
name|PNG_FLAG_MALLOC_NULL_MEM_OK
operator|)
operator|==
literal|0
condition|)
name|png_error
argument_list|(
name|png_ptr
argument_list|,
literal|"Out of Memory"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_block
begin_comment
comment|/* Free a pointer allocated by png_malloc().  If ptr is NULL, return  * without taking any action.  */
end_comment
begin_function
name|void
name|PNGAPI
DECL|function|png_free
name|png_free
parameter_list|(
name|png_structp
name|png_ptr
parameter_list|,
name|png_voidp
name|ptr
parameter_list|)
block|{
if|if
condition|(
name|png_ptr
operator|==
name|NULL
operator|||
name|ptr
operator|==
name|NULL
condition|)
return|return;
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
if|if
condition|(
name|png_ptr
operator|->
name|free_fn
operator|!=
name|NULL
condition|)
block|{
operator|(
operator|*
operator|(
name|png_ptr
operator|->
name|free_fn
operator|)
operator|)
operator|(
name|png_ptr
operator|,
name|ptr
operator|)
expr_stmt|;
return|return;
block|}
else|else
name|png_free_default
argument_list|(
name|png_ptr
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|PNGAPI
DECL|function|png_free_default
name|png_free_default
parameter_list|(
name|png_structp
name|png_ptr
parameter_list|,
name|png_voidp
name|ptr
parameter_list|)
block|{
if|if
condition|(
name|png_ptr
operator|==
name|NULL
operator|||
name|ptr
operator|==
name|NULL
condition|)
return|return;
endif|#
directive|endif
comment|/* PNG_USER_MEM_SUPPORTED */
if|#
directive|if
name|defined
argument_list|(
name|__TURBOC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__FLAT__
argument_list|)
name|farfree
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|defined
argument_list|(
name|MAXSEG_64K
argument_list|)
name|hfree
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
else|#
directive|else
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Not Borland DOS special memory handler */
end_comment
begin_comment
comment|/* This function was added at libpng version 1.2.3.  The png_malloc_warn()  * function will set up png_malloc() to issue a png_warning and return NULL  * instead of issuing a png_error, if it fails to allocate the requested  * memory.  */
end_comment
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
argument_list|,
argument|PNGAPI png_malloc_warn
argument_list|,
argument|(png_structp png_ptr, png_alloc_size_t size)
argument_list|,
argument|PNG_ALLOCATED
argument_list|)
end_macro
begin_block
block|{
name|png_voidp
name|ptr
decl_stmt|;
name|png_uint_32
name|save_flags
decl_stmt|;
if|if
condition|(
name|png_ptr
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|save_flags
operator|=
name|png_ptr
operator|->
name|flags
expr_stmt|;
name|png_ptr
operator|->
name|flags
operator||=
name|PNG_FLAG_MALLOC_NULL_MEM_OK
expr_stmt|;
name|ptr
operator|=
operator|(
name|png_voidp
operator|)
name|png_malloc
argument_list|(
operator|(
name|png_structp
operator|)
name|png_ptr
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|png_ptr
operator|->
name|flags
operator|=
name|save_flags
expr_stmt|;
return|return
operator|(
name|ptr
operator|)
return|;
block|}
end_block
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
end_ifdef
begin_comment
comment|/* This function is called when the application wants to use another method  * of allocating and freeing memory.  */
end_comment
begin_function
name|void
name|PNGAPI
DECL|function|png_set_mem_fn
name|png_set_mem_fn
parameter_list|(
name|png_structp
name|png_ptr
parameter_list|,
name|png_voidp
name|mem_ptr
parameter_list|,
name|png_malloc_ptr
name|malloc_fn
parameter_list|,
name|png_free_ptr
name|free_fn
parameter_list|)
block|{
if|if
condition|(
name|png_ptr
operator|!=
name|NULL
condition|)
block|{
name|png_ptr
operator|->
name|mem_ptr
operator|=
name|mem_ptr
expr_stmt|;
name|png_ptr
operator|->
name|malloc_fn
operator|=
name|malloc_fn
expr_stmt|;
name|png_ptr
operator|->
name|free_fn
operator|=
name|free_fn
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/* This function returns a pointer to the mem_ptr associated with the user  * functions.  The application should free any memory associated with this  * pointer before png_write_destroy and png_read_destroy are called.  */
end_comment
begin_function
name|png_voidp
name|PNGAPI
DECL|function|png_get_mem_ptr
name|png_get_mem_ptr
parameter_list|(
name|png_const_structp
name|png_ptr
parameter_list|)
block|{
if|if
condition|(
name|png_ptr
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
return|return
operator|(
operator|(
name|png_voidp
operator|)
name|png_ptr
operator|->
name|mem_ptr
operator|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PNG_USER_MEM_SUPPORTED */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PNG_READ_SUPPORTED || PNG_WRITE_SUPPORTED */
end_comment
end_unit
