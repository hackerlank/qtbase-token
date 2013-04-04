begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftzopen.c                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType support for .Z compressed files.                            */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This optional component relies on NetBSD's zopen().  It should mainly  */
end_comment
begin_comment
comment|/*  be used to parse compressed PCF fonts, as found with many X11 server   */
end_comment
begin_comment
comment|/*  distributions.                                                         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2005, 2006, 2007, 2009 by David Turner.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file is part of the FreeType project, and may only be used,       */
end_comment
begin_comment
comment|/*  modified, and distributed under the terms of the FreeType project      */
end_comment
begin_comment
comment|/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
end_comment
begin_comment
comment|/*  this file you indicate that you have read the license and              */
end_comment
begin_comment
comment|/*  understand and accept it fully.                                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"ftzopen.h"
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_MEMORY_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_STREAM_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_function
specifier|static
name|int
DECL|function|ft_lzwstate_refill
name|ft_lzwstate_refill
parameter_list|(
name|FT_LzwState
name|state
parameter_list|)
block|{
name|FT_ULong
name|count
decl_stmt|;
if|if
condition|(
name|state
operator|->
name|in_eof
condition|)
return|return
operator|-
literal|1
return|;
name|count
operator|=
name|FT_Stream_TryRead
argument_list|(
name|state
operator|->
name|source
argument_list|,
name|state
operator|->
name|buf_tab
argument_list|,
name|state
operator|->
name|num_bits
argument_list|)
expr_stmt|;
comment|/* WHY? */
name|state
operator|->
name|buf_size
operator|=
operator|(
name|FT_UInt
operator|)
name|count
expr_stmt|;
name|state
operator|->
name|buf_total
operator|+=
name|count
expr_stmt|;
name|state
operator|->
name|in_eof
operator|=
name|FT_BOOL
argument_list|(
name|count
operator|<
name|state
operator|->
name|num_bits
argument_list|)
expr_stmt|;
name|state
operator|->
name|buf_offset
operator|=
literal|0
expr_stmt|;
name|state
operator|->
name|buf_size
operator|=
operator|(
name|state
operator|->
name|buf_size
operator|<<
literal|3
operator|)
operator|-
operator|(
name|state
operator|->
name|num_bits
operator|-
literal|1
operator|)
expr_stmt|;
if|if
condition|(
name|count
operator|==
literal|0
condition|)
comment|/* end of file */
return|return
operator|-
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Int32
DECL|function|ft_lzwstate_get_code
name|ft_lzwstate_get_code
parameter_list|(
name|FT_LzwState
name|state
parameter_list|)
block|{
name|FT_UInt
name|num_bits
init|=
name|state
operator|->
name|num_bits
decl_stmt|;
name|FT_Int
name|offset
init|=
name|state
operator|->
name|buf_offset
decl_stmt|;
name|FT_Byte
modifier|*
name|p
decl_stmt|;
name|FT_Int
name|result
decl_stmt|;
if|if
condition|(
name|state
operator|->
name|buf_clear
operator|||
name|offset
operator|>=
name|state
operator|->
name|buf_size
operator|||
name|state
operator|->
name|free_ent
operator|>=
name|state
operator|->
name|free_bits
condition|)
block|{
if|if
condition|(
name|state
operator|->
name|free_ent
operator|>=
name|state
operator|->
name|free_bits
condition|)
block|{
name|state
operator|->
name|num_bits
operator|=
operator|++
name|num_bits
expr_stmt|;
name|state
operator|->
name|free_bits
operator|=
name|state
operator|->
name|num_bits
operator|<
name|state
operator|->
name|max_bits
condition|?
call|(
name|FT_UInt
call|)
argument_list|(
operator|(
literal|1UL
operator|<<
name|num_bits
operator|)
operator|-
literal|256
argument_list|)
else|:
name|state
operator|->
name|max_free
operator|+
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|state
operator|->
name|buf_clear
condition|)
block|{
name|state
operator|->
name|num_bits
operator|=
name|num_bits
operator|=
name|LZW_INIT_BITS
expr_stmt|;
name|state
operator|->
name|free_bits
operator|=
call|(
name|FT_UInt
call|)
argument_list|(
operator|(
literal|1UL
operator|<<
name|num_bits
operator|)
operator|-
literal|256
argument_list|)
expr_stmt|;
name|state
operator|->
name|buf_clear
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|ft_lzwstate_refill
argument_list|(
name|state
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
name|offset
operator|=
literal|0
expr_stmt|;
block|}
name|state
operator|->
name|buf_offset
operator|=
name|offset
operator|+
name|num_bits
expr_stmt|;
name|p
operator|=
operator|&
name|state
operator|->
name|buf_tab
index|[
name|offset
operator|>>
literal|3
index|]
expr_stmt|;
name|offset
operator|&=
literal|7
expr_stmt|;
name|result
operator|=
operator|*
name|p
operator|++
operator|>>
name|offset
expr_stmt|;
name|offset
operator|=
literal|8
operator|-
name|offset
expr_stmt|;
name|num_bits
operator|-=
name|offset
expr_stmt|;
if|if
condition|(
name|num_bits
operator|>=
literal|8
condition|)
block|{
name|result
operator||=
operator|*
name|p
operator|++
operator|<<
name|offset
expr_stmt|;
name|offset
operator|+=
literal|8
expr_stmt|;
name|num_bits
operator|-=
literal|8
expr_stmt|;
block|}
if|if
condition|(
name|num_bits
operator|>
literal|0
condition|)
name|result
operator||=
operator|(
operator|*
name|p
operator|&
name|LZW_MASK
argument_list|(
name|num_bits
argument_list|)
operator|)
operator|<<
name|offset
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/* grow the character stack */
end_comment
begin_function
specifier|static
name|int
DECL|function|ft_lzwstate_stack_grow
name|ft_lzwstate_stack_grow
parameter_list|(
name|FT_LzwState
name|state
parameter_list|)
block|{
if|if
condition|(
name|state
operator|->
name|stack_top
operator|>=
name|state
operator|->
name|stack_size
condition|)
block|{
name|FT_Memory
name|memory
init|=
name|state
operator|->
name|memory
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
name|FT_Offset
name|old_size
init|=
name|state
operator|->
name|stack_size
decl_stmt|;
name|FT_Offset
name|new_size
init|=
name|old_size
decl_stmt|;
name|new_size
operator|=
name|new_size
operator|+
operator|(
name|new_size
operator|>>
literal|1
operator|)
operator|+
literal|4
expr_stmt|;
if|if
condition|(
name|state
operator|->
name|stack
operator|==
name|state
operator|->
name|stack_0
condition|)
block|{
name|state
operator|->
name|stack
operator|=
name|NULL
expr_stmt|;
name|old_size
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|FT_RENEW_ARRAY
argument_list|(
name|state
operator|->
name|stack
argument_list|,
name|old_size
argument_list|,
name|new_size
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
name|state
operator|->
name|stack_size
operator|=
name|new_size
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/* grow the prefix/suffix arrays */
end_comment
begin_function
specifier|static
name|int
DECL|function|ft_lzwstate_prefix_grow
name|ft_lzwstate_prefix_grow
parameter_list|(
name|FT_LzwState
name|state
parameter_list|)
block|{
name|FT_UInt
name|old_size
init|=
name|state
operator|->
name|prefix_size
decl_stmt|;
name|FT_UInt
name|new_size
init|=
name|old_size
decl_stmt|;
name|FT_Memory
name|memory
init|=
name|state
operator|->
name|memory
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
if|if
condition|(
name|new_size
operator|==
literal|0
condition|)
comment|/* first allocation -> 9 bits */
name|new_size
operator|=
literal|512
expr_stmt|;
else|else
name|new_size
operator|+=
name|new_size
operator|>>
literal|2
expr_stmt|;
comment|/* don't grow too fast */
comment|/*      *  Note that the `suffix' array is located in the same memory block      *  pointed to by `prefix'.      *      *  I know that sizeof(FT_Byte) == 1 by definition, but it is clearer      *  to write it literally.      *      */
if|if
condition|(
name|FT_REALLOC_MULT
argument_list|(
name|state
operator|->
name|prefix
argument_list|,
name|old_size
argument_list|,
name|new_size
argument_list|,
sizeof|sizeof
argument_list|(
name|FT_UShort
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|FT_Byte
argument_list|)
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
comment|/* now adjust `suffix' and move the data accordingly */
name|state
operator|->
name|suffix
operator|=
operator|(
name|FT_Byte
operator|*
operator|)
operator|(
name|state
operator|->
name|prefix
operator|+
name|new_size
operator|)
expr_stmt|;
name|FT_MEM_MOVE
argument_list|(
name|state
operator|->
name|suffix
argument_list|,
name|state
operator|->
name|prefix
operator|+
name|old_size
argument_list|,
name|old_size
operator|*
sizeof|sizeof
argument_list|(
name|FT_Byte
argument_list|)
argument_list|)
expr_stmt|;
name|state
operator|->
name|prefix_size
operator|=
name|new_size
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|ft_lzwstate_reset
name|ft_lzwstate_reset
argument_list|(
argument|FT_LzwState  state
argument_list|)
end_macro
begin_block
block|{
name|state
operator|->
name|in_eof
operator|=
literal|0
expr_stmt|;
name|state
operator|->
name|buf_offset
operator|=
literal|0
expr_stmt|;
name|state
operator|->
name|buf_size
operator|=
literal|0
expr_stmt|;
name|state
operator|->
name|buf_clear
operator|=
literal|0
expr_stmt|;
name|state
operator|->
name|buf_total
operator|=
literal|0
expr_stmt|;
name|state
operator|->
name|stack_top
operator|=
literal|0
expr_stmt|;
name|state
operator|->
name|num_bits
operator|=
name|LZW_INIT_BITS
expr_stmt|;
name|state
operator|->
name|phase
operator|=
name|FT_LZW_PHASE_START
expr_stmt|;
block|}
end_block
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|ft_lzwstate_init
name|ft_lzwstate_init
argument_list|(
argument|FT_LzwState  state
argument_list|,
argument|FT_Stream    source
argument_list|)
end_macro
begin_block
block|{
name|FT_ZERO
argument_list|(
name|state
argument_list|)
expr_stmt|;
name|state
operator|->
name|source
operator|=
name|source
expr_stmt|;
name|state
operator|->
name|memory
operator|=
name|source
operator|->
name|memory
expr_stmt|;
name|state
operator|->
name|prefix
operator|=
name|NULL
expr_stmt|;
name|state
operator|->
name|suffix
operator|=
name|NULL
expr_stmt|;
name|state
operator|->
name|prefix_size
operator|=
literal|0
expr_stmt|;
name|state
operator|->
name|stack
operator|=
name|state
operator|->
name|stack_0
expr_stmt|;
name|state
operator|->
name|stack_size
operator|=
sizeof|sizeof
argument_list|(
name|state
operator|->
name|stack_0
argument_list|)
expr_stmt|;
name|ft_lzwstate_reset
argument_list|(
name|state
argument_list|)
expr_stmt|;
block|}
end_block
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|ft_lzwstate_done
name|ft_lzwstate_done
argument_list|(
argument|FT_LzwState  state
argument_list|)
end_macro
begin_block
block|{
name|FT_Memory
name|memory
init|=
name|state
operator|->
name|memory
decl_stmt|;
name|ft_lzwstate_reset
argument_list|(
name|state
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|->
name|stack
operator|!=
name|state
operator|->
name|stack_0
condition|)
name|FT_FREE
argument_list|(
name|state
operator|->
name|stack
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|state
operator|->
name|prefix
argument_list|)
expr_stmt|;
name|state
operator|->
name|suffix
operator|=
name|NULL
expr_stmt|;
name|FT_ZERO
argument_list|(
name|state
argument_list|)
expr_stmt|;
block|}
end_block
begin_define
DECL|macro|FTLZW_STACK_PUSH
define|#
directive|define
name|FTLZW_STACK_PUSH
parameter_list|(
name|c
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                     \     if ( state->stack_top>= state->stack_size&&    \          ft_lzwstate_stack_grow( state )< 0   )     \       goto Eof;                                      \                                                      \     state->stack[state->stack_top++] = (FT_Byte)(c); \   FT_END_STMNT
end_define
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_ULong
argument_list|)
end_macro
begin_macro
name|ft_lzwstate_io
argument_list|(
argument|FT_LzwState  state
argument_list|,
argument|FT_Byte*     buffer
argument_list|,
argument|FT_ULong     out_size
argument_list|)
end_macro
begin_block
block|{
name|FT_ULong
name|result
init|=
literal|0
decl_stmt|;
name|FT_UInt
name|old_char
init|=
name|state
operator|->
name|old_char
decl_stmt|;
name|FT_UInt
name|old_code
init|=
name|state
operator|->
name|old_code
decl_stmt|;
name|FT_UInt
name|in_code
init|=
name|state
operator|->
name|in_code
decl_stmt|;
if|if
condition|(
name|out_size
operator|==
literal|0
condition|)
goto|goto
name|Exit
goto|;
switch|switch
condition|(
name|state
operator|->
name|phase
condition|)
block|{
case|case
name|FT_LZW_PHASE_START
case|:
block|{
name|FT_Byte
name|max_bits
decl_stmt|;
name|FT_Int32
name|c
decl_stmt|;
comment|/* skip magic bytes, and read max_bits + block_flag */
if|if
condition|(
name|FT_Stream_Seek
argument_list|(
name|state
operator|->
name|source
argument_list|,
literal|2
argument_list|)
operator|!=
literal|0
operator|||
name|FT_Stream_TryRead
argument_list|(
name|state
operator|->
name|source
argument_list|,
operator|&
name|max_bits
argument_list|,
literal|1
argument_list|)
operator|!=
literal|1
condition|)
goto|goto
name|Eof
goto|;
name|state
operator|->
name|max_bits
operator|=
name|max_bits
operator|&
name|LZW_BIT_MASK
expr_stmt|;
name|state
operator|->
name|block_mode
operator|=
name|max_bits
operator|&
name|LZW_BLOCK_MASK
expr_stmt|;
name|state
operator|->
name|max_free
operator|=
call|(
name|FT_UInt
call|)
argument_list|(
operator|(
literal|1UL
operator|<<
name|state
operator|->
name|max_bits
operator|)
operator|-
literal|256
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|->
name|max_bits
operator|>
name|LZW_MAX_BITS
condition|)
goto|goto
name|Eof
goto|;
name|state
operator|->
name|num_bits
operator|=
name|LZW_INIT_BITS
expr_stmt|;
name|state
operator|->
name|free_ent
operator|=
operator|(
name|state
operator|->
name|block_mode
condition|?
name|LZW_FIRST
else|:
name|LZW_CLEAR
operator|)
operator|-
literal|256
expr_stmt|;
name|in_code
operator|=
literal|0
expr_stmt|;
name|state
operator|->
name|free_bits
operator|=
name|state
operator|->
name|num_bits
operator|<
name|state
operator|->
name|max_bits
condition|?
call|(
name|FT_UInt
call|)
argument_list|(
operator|(
literal|1UL
operator|<<
name|state
operator|->
name|num_bits
operator|)
operator|-
literal|256
argument_list|)
else|:
name|state
operator|->
name|max_free
operator|+
literal|1
expr_stmt|;
name|c
operator|=
name|ft_lzwstate_get_code
argument_list|(
name|state
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|<
literal|0
condition|)
goto|goto
name|Eof
goto|;
name|old_code
operator|=
name|old_char
operator|=
operator|(
name|FT_UInt
operator|)
name|c
expr_stmt|;
if|if
condition|(
name|buffer
condition|)
name|buffer
index|[
name|result
index|]
operator|=
operator|(
name|FT_Byte
operator|)
name|old_char
expr_stmt|;
if|if
condition|(
operator|++
name|result
operator|>=
name|out_size
condition|)
goto|goto
name|Exit
goto|;
name|state
operator|->
name|phase
operator|=
name|FT_LZW_PHASE_CODE
expr_stmt|;
block|}
comment|/* fall-through */
case|case
name|FT_LZW_PHASE_CODE
case|:
block|{
name|FT_Int32
name|c
decl_stmt|;
name|FT_UInt
name|code
decl_stmt|;
name|NextCode
label|:
name|c
operator|=
name|ft_lzwstate_get_code
argument_list|(
name|state
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|<
literal|0
condition|)
goto|goto
name|Eof
goto|;
name|code
operator|=
operator|(
name|FT_UInt
operator|)
name|c
expr_stmt|;
if|if
condition|(
name|code
operator|==
name|LZW_CLEAR
operator|&&
name|state
operator|->
name|block_mode
condition|)
block|{
comment|/* why not LZW_FIRST-256 ? */
name|state
operator|->
name|free_ent
operator|=
operator|(
name|LZW_FIRST
operator|-
literal|1
operator|)
operator|-
literal|256
expr_stmt|;
name|state
operator|->
name|buf_clear
operator|=
literal|1
expr_stmt|;
name|c
operator|=
name|ft_lzwstate_get_code
argument_list|(
name|state
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|<
literal|0
condition|)
goto|goto
name|Eof
goto|;
name|code
operator|=
operator|(
name|FT_UInt
operator|)
name|c
expr_stmt|;
block|}
name|in_code
operator|=
name|code
expr_stmt|;
comment|/* save code for later */
if|if
condition|(
name|code
operator|>=
literal|256U
condition|)
block|{
comment|/* special case for KwKwKwK */
if|if
condition|(
name|code
operator|-
literal|256U
operator|>=
name|state
operator|->
name|free_ent
condition|)
block|{
name|FTLZW_STACK_PUSH
argument_list|(
name|old_char
argument_list|)
expr_stmt|;
name|code
operator|=
name|old_code
expr_stmt|;
block|}
while|while
condition|(
name|code
operator|>=
literal|256U
condition|)
block|{
if|if
condition|(
operator|!
name|state
operator|->
name|prefix
condition|)
goto|goto
name|Eof
goto|;
name|FTLZW_STACK_PUSH
argument_list|(
name|state
operator|->
name|suffix
index|[
name|code
operator|-
literal|256
index|]
argument_list|)
expr_stmt|;
name|code
operator|=
name|state
operator|->
name|prefix
index|[
name|code
operator|-
literal|256
index|]
expr_stmt|;
block|}
block|}
name|old_char
operator|=
name|code
expr_stmt|;
name|FTLZW_STACK_PUSH
argument_list|(
name|old_char
argument_list|)
expr_stmt|;
name|state
operator|->
name|phase
operator|=
name|FT_LZW_PHASE_STACK
expr_stmt|;
block|}
comment|/* fall-through */
case|case
name|FT_LZW_PHASE_STACK
case|:
block|{
while|while
condition|(
name|state
operator|->
name|stack_top
operator|>
literal|0
condition|)
block|{
operator|--
name|state
operator|->
name|stack_top
expr_stmt|;
if|if
condition|(
name|buffer
condition|)
name|buffer
index|[
name|result
index|]
operator|=
name|state
operator|->
name|stack
index|[
name|state
operator|->
name|stack_top
index|]
expr_stmt|;
if|if
condition|(
operator|++
name|result
operator|==
name|out_size
condition|)
goto|goto
name|Exit
goto|;
block|}
comment|/* now create new entry */
if|if
condition|(
name|state
operator|->
name|free_ent
operator|<
name|state
operator|->
name|max_free
condition|)
block|{
if|if
condition|(
name|state
operator|->
name|free_ent
operator|>=
name|state
operator|->
name|prefix_size
operator|&&
name|ft_lzwstate_prefix_grow
argument_list|(
name|state
argument_list|)
operator|<
literal|0
condition|)
goto|goto
name|Eof
goto|;
name|FT_ASSERT
argument_list|(
name|state
operator|->
name|free_ent
operator|<
name|state
operator|->
name|prefix_size
argument_list|)
expr_stmt|;
name|state
operator|->
name|prefix
index|[
name|state
operator|->
name|free_ent
index|]
operator|=
operator|(
name|FT_UShort
operator|)
name|old_code
expr_stmt|;
name|state
operator|->
name|suffix
index|[
name|state
operator|->
name|free_ent
index|]
operator|=
operator|(
name|FT_Byte
operator|)
name|old_char
expr_stmt|;
name|state
operator|->
name|free_ent
operator|+=
literal|1
expr_stmt|;
block|}
name|old_code
operator|=
name|in_code
expr_stmt|;
name|state
operator|->
name|phase
operator|=
name|FT_LZW_PHASE_CODE
expr_stmt|;
goto|goto
name|NextCode
goto|;
block|}
default|default:
comment|/* state == EOF */
empty_stmt|;
block|}
name|Exit
label|:
name|state
operator|->
name|old_code
operator|=
name|old_code
expr_stmt|;
name|state
operator|->
name|old_char
operator|=
name|old_char
expr_stmt|;
name|state
operator|->
name|in_code
operator|=
name|in_code
expr_stmt|;
return|return
name|result
return|;
name|Eof
label|:
name|state
operator|->
name|phase
operator|=
name|FT_LZW_PHASE_EOF
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
