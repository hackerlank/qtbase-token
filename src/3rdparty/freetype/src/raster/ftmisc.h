begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftmisc.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Miscellaneous macros for stand-alone rasterizer (specification       */
end_comment
begin_comment
comment|/*    only).                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2005, 2009, 2010 by                                          */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file is part of the FreeType project, and may only be used        */
end_comment
begin_comment
comment|/*  modified and distributed under the terms of the FreeType project       */
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
begin_comment
comment|/***************************************************/
end_comment
begin_comment
comment|/*                                                 */
end_comment
begin_comment
comment|/* This file is *not* portable!  You have to adapt */
end_comment
begin_comment
comment|/* its definitions to your platform.               */
end_comment
begin_comment
comment|/*                                                 */
end_comment
begin_comment
comment|/***************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__FTMISC_H__
end_ifndef
begin_define
DECL|macro|__FTMISC_H__
define|#
directive|define
name|__FTMISC_H__
end_define
begin_comment
comment|/* memset */
end_comment
begin_include
include|#
directive|include
include|FT_CONFIG_STANDARD_LIBRARY_H
end_include
begin_define
DECL|macro|FT_BEGIN_HEADER
define|#
directive|define
name|FT_BEGIN_HEADER
end_define
begin_define
DECL|macro|FT_END_HEADER
define|#
directive|define
name|FT_END_HEADER
end_define
begin_define
DECL|macro|FT_LOCAL_DEF
define|#
directive|define
name|FT_LOCAL_DEF
parameter_list|(
name|x
parameter_list|)
value|static x
end_define
begin_comment
comment|/* from include/freetype2/fttypes.h */
end_comment
begin_typedef
DECL|typedef|FT_Byte
typedef|typedef
name|unsigned
name|char
name|FT_Byte
typedef|;
end_typedef
begin_typedef
DECL|typedef|FT_Int
typedef|typedef
name|signed
name|int
name|FT_Int
typedef|;
end_typedef
begin_typedef
DECL|typedef|FT_UInt
typedef|typedef
name|unsigned
name|int
name|FT_UInt
typedef|;
end_typedef
begin_typedef
DECL|typedef|FT_Long
typedef|typedef
name|signed
name|long
name|FT_Long
typedef|;
end_typedef
begin_typedef
DECL|typedef|FT_ULong
typedef|typedef
name|unsigned
name|long
name|FT_ULong
typedef|;
end_typedef
begin_typedef
DECL|typedef|FT_F26Dot6
typedef|typedef
name|signed
name|long
name|FT_F26Dot6
typedef|;
end_typedef
begin_typedef
DECL|typedef|FT_Error
typedef|typedef
name|int
name|FT_Error
typedef|;
end_typedef
begin_define
DECL|macro|FT_MAKE_TAG
define|#
directive|define
name|FT_MAKE_TAG
parameter_list|(
name|_x1
parameter_list|,
name|_x2
parameter_list|,
name|_x3
parameter_list|,
name|_x4
parameter_list|)
define|\
value|( ( (FT_ULong)_x1<< 24 ) |     \             ( (FT_ULong)_x2<< 16 ) |     \             ( (FT_ULong)_x3<<  8 ) |     \               (FT_ULong)_x4         )
end_define
begin_comment
comment|/* from include/freetype2/ftsystem.h */
end_comment
begin_typedef
DECL|typedef|FT_Memory
typedef|typedef
name|struct
name|FT_MemoryRec_
modifier|*
name|FT_Memory
typedef|;
end_typedef
begin_typedef
DECL|typedef|FT_Alloc_Func
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|FT_Alloc_Func
function_decl|)
parameter_list|(
name|FT_Memory
name|memory
parameter_list|,
name|long
name|size
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|FT_Free_Func
typedef|typedef
name|void
function_decl|(
modifier|*
name|FT_Free_Func
function_decl|)
parameter_list|(
name|FT_Memory
name|memory
parameter_list|,
name|void
modifier|*
name|block
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|FT_Realloc_Func
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|FT_Realloc_Func
function_decl|)
parameter_list|(
name|FT_Memory
name|memory
parameter_list|,
name|long
name|cur_size
parameter_list|,
name|long
name|new_size
parameter_list|,
name|void
modifier|*
name|block
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|struct|FT_MemoryRec_
typedef|typedef
struct|struct
name|FT_MemoryRec_
block|{
DECL|member|user
name|void
modifier|*
name|user
decl_stmt|;
DECL|member|alloc
name|FT_Alloc_Func
name|alloc
decl_stmt|;
DECL|member|free
name|FT_Free_Func
name|free
decl_stmt|;
DECL|member|realloc
name|FT_Realloc_Func
name|realloc
decl_stmt|;
block|}
DECL|typedef|FT_MemoryRec
name|FT_MemoryRec
typedef|;
end_typedef
begin_comment
comment|/* from src/ftcalc.c */
end_comment
begin_if
if|#
directive|if
operator|(
name|defined
name|_WIN32
operator|||
name|defined
name|_WIN64
operator|)
end_if
begin_typedef
DECL|typedef|FT_Int64
typedef|typedef
name|__int64
name|FT_Int64
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"inttypes.h"
end_include
begin_typedef
DECL|typedef|FT_Int64
typedef|typedef
name|int64_t
name|FT_Int64
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|static
name|FT_Long
DECL|function|FT_MulDiv
name|FT_MulDiv
parameter_list|(
name|FT_Long
name|a
parameter_list|,
name|FT_Long
name|b
parameter_list|,
name|FT_Long
name|c
parameter_list|)
block|{
name|FT_Int
name|s
decl_stmt|;
name|FT_Long
name|d
decl_stmt|;
name|s
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|a
operator|<
literal|0
condition|)
block|{
name|a
operator|=
operator|-
name|a
expr_stmt|;
name|s
operator|=
operator|-
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|b
operator|<
literal|0
condition|)
block|{
name|b
operator|=
operator|-
name|b
expr_stmt|;
name|s
operator|=
operator|-
name|s
expr_stmt|;
block|}
if|if
condition|(
name|c
operator|<
literal|0
condition|)
block|{
name|c
operator|=
operator|-
name|c
expr_stmt|;
name|s
operator|=
operator|-
name|s
expr_stmt|;
block|}
name|d
operator|=
call|(
name|FT_Long
call|)
argument_list|(
name|c
operator|>
literal|0
condition|?
operator|(
operator|(
name|FT_Int64
operator|)
name|a
operator|*
name|b
operator|+
operator|(
name|c
operator|>>
literal|1
operator|)
operator|)
operator|/
name|c
else|:
literal|0x7FFFFFFFL
argument_list|)
expr_stmt|;
return|return
operator|(
name|s
operator|>
literal|0
operator|)
condition|?
name|d
else|:
operator|-
name|d
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Long
DECL|function|FT_MulDiv_No_Round
name|FT_MulDiv_No_Round
parameter_list|(
name|FT_Long
name|a
parameter_list|,
name|FT_Long
name|b
parameter_list|,
name|FT_Long
name|c
parameter_list|)
block|{
name|FT_Int
name|s
decl_stmt|;
name|FT_Long
name|d
decl_stmt|;
name|s
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|a
operator|<
literal|0
condition|)
block|{
name|a
operator|=
operator|-
name|a
expr_stmt|;
name|s
operator|=
operator|-
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|b
operator|<
literal|0
condition|)
block|{
name|b
operator|=
operator|-
name|b
expr_stmt|;
name|s
operator|=
operator|-
name|s
expr_stmt|;
block|}
if|if
condition|(
name|c
operator|<
literal|0
condition|)
block|{
name|c
operator|=
operator|-
name|c
expr_stmt|;
name|s
operator|=
operator|-
name|s
expr_stmt|;
block|}
name|d
operator|=
call|(
name|FT_Long
call|)
argument_list|(
name|c
operator|>
literal|0
condition|?
operator|(
name|FT_Int64
operator|)
name|a
operator|*
name|b
operator|/
name|c
else|:
literal|0x7FFFFFFFL
argument_list|)
expr_stmt|;
return|return
operator|(
name|s
operator|>
literal|0
operator|)
condition|?
name|d
else|:
operator|-
name|d
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTMISC_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
