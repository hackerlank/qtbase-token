begin_unit
begin_comment
comment|/*  * Copyright (C) 1998-2004  David Turner and Werner Lemberg  * Copyright (C) 2015 The Qt Company Ltd  * Copyright (C) 2007  Red Hat, Inc.  *  * This is part of HarfBuzz, an OpenType Layout engine library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  *  * Red Hat Author(s): Behdad Esfahbod  */
end_comment
begin_include
include|#
directive|include
file|"harfbuzz-impl.h"
end_include
begin_function
name|HB_INTERNAL
name|HB_Pointer
DECL|function|_hb_alloc
name|_hb_alloc
parameter_list|(
name|size_t
name|size
parameter_list|,
name|HB_Error
modifier|*
name|perror
parameter_list|)
block|{
name|HB_Error
name|error
init|=
operator|(
name|HB_Error
operator|)
literal|0
decl_stmt|;
name|HB_Pointer
name|block
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|size
operator|>
literal|0
condition|)
block|{
name|block
operator|=
name|calloc
argument_list|(
literal|1
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|block
condition|)
name|error
operator|=
name|ERR
argument_list|(
name|HB_Err_Out_Of_Memory
argument_list|)
expr_stmt|;
block|}
operator|*
name|perror
operator|=
name|error
expr_stmt|;
return|return
name|block
return|;
block|}
end_function
begin_function
name|HB_INTERNAL
name|HB_Pointer
DECL|function|_hb_realloc
name|_hb_realloc
parameter_list|(
name|HB_Pointer
name|block
parameter_list|,
name|size_t
name|new_size
parameter_list|,
name|HB_Error
modifier|*
name|perror
parameter_list|)
block|{
name|HB_Pointer
name|block2
init|=
name|NULL
decl_stmt|;
name|HB_Error
name|error
init|=
operator|(
name|HB_Error
operator|)
literal|0
decl_stmt|;
name|block2
operator|=
name|realloc
argument_list|(
name|block
argument_list|,
name|new_size
argument_list|)
expr_stmt|;
if|if
condition|(
name|block2
operator|==
name|NULL
operator|&&
name|new_size
operator|!=
literal|0
condition|)
name|error
operator|=
name|ERR
argument_list|(
name|HB_Err_Out_Of_Memory
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
name|block
operator|=
name|block2
expr_stmt|;
operator|*
name|perror
operator|=
name|error
expr_stmt|;
return|return
name|block
return|;
block|}
end_function
begin_function
name|HB_INTERNAL
name|void
DECL|function|_hb_free
name|_hb_free
parameter_list|(
name|HB_Pointer
name|block
parameter_list|)
block|{
if|if
condition|(
name|block
condition|)
name|free
argument_list|(
name|block
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/* helper func to set a breakpoint on */
end_comment
begin_function
name|HB_INTERNAL
name|HB_Error
DECL|function|_hb_err
name|_hb_err
parameter_list|(
name|HB_Error
name|code
parameter_list|)
block|{
return|return
name|code
return|;
block|}
end_function
end_unit
