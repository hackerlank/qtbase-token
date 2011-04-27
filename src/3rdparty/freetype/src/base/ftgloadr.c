begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftgloadr.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType glyph loader (body).                                    */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002, 2003, 2004, 2005, 2006 by                              */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg                       */
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
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_GLYPH_LOADER_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_MEMORY_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_undef
DECL|macro|FT_COMPONENT
undef|#
directive|undef
name|FT_COMPONENT
end_undef
begin_define
DECL|macro|FT_COMPONENT
define|#
directive|define
name|FT_COMPONENT
value|trace_gloader
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****                    G L Y P H   L O A D E R                    *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The glyph loader is a simple object which is used to load a set of    */
end_comment
begin_comment
comment|/* glyphs easily.  It is critical for the correct loading of composites. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Ideally, one can see it as a stack of abstract `glyph' objects.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   loader.base     Is really the bottom of the stack.  It describes a  */
end_comment
begin_comment
comment|/*                   single glyph image made of the juxtaposition of     */
end_comment
begin_comment
comment|/*                   several glyphs (those `in the stack').              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   loader.current  Describes the top of the stack, on which a new      */
end_comment
begin_comment
comment|/*                   glyph can be loaded.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   Rewind          Clears the stack.                                   */
end_comment
begin_comment
comment|/*   Prepare         Set up `loader.current' for addition of a new glyph */
end_comment
begin_comment
comment|/*                   image.                                              */
end_comment
begin_comment
comment|/*   Add             Add the `current' glyph image to the `base' one,    */
end_comment
begin_comment
comment|/*                   and prepare for another one.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The glyph loader is now a base object.  Each driver used to           */
end_comment
begin_comment
comment|/* re-implement it in one way or the other, which wasted code and        */
end_comment
begin_comment
comment|/* energy.                                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* create a new glyph loader */
end_comment
begin_macro
DECL|function|FT_BASE_DEF
name|FT_BASE_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_GlyphLoader_New
argument_list|(
argument|FT_Memory        memory
argument_list|,
argument|FT_GlyphLoader  *aloader
argument_list|)
end_macro
begin_block
block|{
name|FT_GlyphLoader
name|loader
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
if|if
condition|(
operator|!
name|FT_NEW
argument_list|(
name|loader
argument_list|)
condition|)
block|{
name|loader
operator|->
name|memory
operator|=
name|memory
expr_stmt|;
operator|*
name|aloader
operator|=
name|loader
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_block
begin_comment
comment|/* rewind the glyph loader - reset counters to 0 */
end_comment
begin_macro
name|FT_BASE_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FT_GlyphLoader_Rewind
name|FT_GlyphLoader_Rewind
argument_list|(
argument|FT_GlyphLoader  loader
argument_list|)
end_macro
begin_block
block|{
name|FT_GlyphLoad
name|base
init|=
operator|&
name|loader
operator|->
name|base
decl_stmt|;
name|FT_GlyphLoad
name|current
init|=
operator|&
name|loader
operator|->
name|current
decl_stmt|;
name|base
operator|->
name|outline
operator|.
name|n_points
operator|=
literal|0
expr_stmt|;
name|base
operator|->
name|outline
operator|.
name|n_contours
operator|=
literal|0
expr_stmt|;
name|base
operator|->
name|num_subglyphs
operator|=
literal|0
expr_stmt|;
operator|*
name|current
operator|=
operator|*
name|base
expr_stmt|;
block|}
end_block
begin_comment
comment|/* reset the glyph loader, frees all allocated tables */
end_comment
begin_comment
comment|/* and starts from zero                               */
end_comment
begin_macro
name|FT_BASE_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FT_GlyphLoader_Reset
name|FT_GlyphLoader_Reset
argument_list|(
argument|FT_GlyphLoader  loader
argument_list|)
end_macro
begin_block
block|{
name|FT_Memory
name|memory
init|=
name|loader
operator|->
name|memory
decl_stmt|;
name|FT_FREE
argument_list|(
name|loader
operator|->
name|base
operator|.
name|outline
operator|.
name|points
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|loader
operator|->
name|base
operator|.
name|outline
operator|.
name|tags
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|loader
operator|->
name|base
operator|.
name|outline
operator|.
name|contours
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|loader
operator|->
name|base
operator|.
name|extra_points
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|loader
operator|->
name|base
operator|.
name|subglyphs
argument_list|)
expr_stmt|;
name|loader
operator|->
name|base
operator|.
name|extra_points2
operator|=
name|NULL
expr_stmt|;
name|loader
operator|->
name|max_points
operator|=
literal|0
expr_stmt|;
name|loader
operator|->
name|max_contours
operator|=
literal|0
expr_stmt|;
name|loader
operator|->
name|max_subglyphs
operator|=
literal|0
expr_stmt|;
name|FT_GlyphLoader_Rewind
argument_list|(
name|loader
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/* delete a glyph loader */
end_comment
begin_macro
name|FT_BASE_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FT_GlyphLoader_Done
name|FT_GlyphLoader_Done
argument_list|(
argument|FT_GlyphLoader  loader
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|loader
condition|)
block|{
name|FT_Memory
name|memory
init|=
name|loader
operator|->
name|memory
decl_stmt|;
name|FT_GlyphLoader_Reset
argument_list|(
name|loader
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|loader
argument_list|)
expr_stmt|;
block|}
block|}
end_block
begin_comment
comment|/* re-adjust the `current' outline fields */
end_comment
begin_function
specifier|static
name|void
DECL|function|FT_GlyphLoader_Adjust_Points
name|FT_GlyphLoader_Adjust_Points
parameter_list|(
name|FT_GlyphLoader
name|loader
parameter_list|)
block|{
name|FT_Outline
modifier|*
name|base
init|=
operator|&
name|loader
operator|->
name|base
operator|.
name|outline
decl_stmt|;
name|FT_Outline
modifier|*
name|current
init|=
operator|&
name|loader
operator|->
name|current
operator|.
name|outline
decl_stmt|;
name|current
operator|->
name|points
operator|=
name|base
operator|->
name|points
operator|+
name|base
operator|->
name|n_points
expr_stmt|;
name|current
operator|->
name|tags
operator|=
name|base
operator|->
name|tags
operator|+
name|base
operator|->
name|n_points
expr_stmt|;
name|current
operator|->
name|contours
operator|=
name|base
operator|->
name|contours
operator|+
name|base
operator|->
name|n_contours
expr_stmt|;
comment|/* handle extra points table - if any */
if|if
condition|(
name|loader
operator|->
name|use_extra
condition|)
block|{
name|loader
operator|->
name|current
operator|.
name|extra_points
operator|=
name|loader
operator|->
name|base
operator|.
name|extra_points
operator|+
name|base
operator|->
name|n_points
expr_stmt|;
name|loader
operator|->
name|current
operator|.
name|extra_points2
operator|=
name|loader
operator|->
name|base
operator|.
name|extra_points2
operator|+
name|base
operator|->
name|n_points
expr_stmt|;
block|}
block|}
end_function
begin_macro
DECL|function|FT_BASE_DEF
name|FT_BASE_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_GlyphLoader_CreateExtra
argument_list|(
argument|FT_GlyphLoader  loader
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|FT_Memory
name|memory
init|=
name|loader
operator|->
name|memory
decl_stmt|;
if|if
condition|(
operator|!
name|FT_NEW_ARRAY
argument_list|(
name|loader
operator|->
name|base
operator|.
name|extra_points
argument_list|,
literal|2
operator|*
name|loader
operator|->
name|max_points
argument_list|)
condition|)
block|{
name|loader
operator|->
name|use_extra
operator|=
literal|1
expr_stmt|;
name|loader
operator|->
name|base
operator|.
name|extra_points2
operator|=
name|loader
operator|->
name|base
operator|.
name|extra_points
operator|+
name|loader
operator|->
name|max_points
expr_stmt|;
name|FT_GlyphLoader_Adjust_Points
argument_list|(
name|loader
argument_list|)
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_block
begin_comment
comment|/* re-adjust the `current' subglyphs field */
end_comment
begin_function
specifier|static
name|void
DECL|function|FT_GlyphLoader_Adjust_Subglyphs
name|FT_GlyphLoader_Adjust_Subglyphs
parameter_list|(
name|FT_GlyphLoader
name|loader
parameter_list|)
block|{
name|FT_GlyphLoad
name|base
init|=
operator|&
name|loader
operator|->
name|base
decl_stmt|;
name|FT_GlyphLoad
name|current
init|=
operator|&
name|loader
operator|->
name|current
decl_stmt|;
name|current
operator|->
name|subglyphs
operator|=
name|base
operator|->
name|subglyphs
operator|+
name|base
operator|->
name|num_subglyphs
expr_stmt|;
block|}
end_function
begin_comment
comment|/* Ensure that we can add `n_points' and `n_contours' to our glyph.      */
end_comment
begin_comment
comment|/* This function reallocates its outline tables if necessary.  Note that */
end_comment
begin_comment
comment|/* it DOESN'T change the number of points within the loader!             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
DECL|function|FT_BASE_DEF
name|FT_BASE_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_GlyphLoader_CheckPoints
argument_list|(
argument|FT_GlyphLoader  loader
argument_list|,
argument|FT_UInt         n_points
argument_list|,
argument|FT_UInt         n_contours
argument_list|)
end_macro
begin_block
block|{
name|FT_Memory
name|memory
init|=
name|loader
operator|->
name|memory
decl_stmt|;
name|FT_Error
name|error
init|=
name|FT_Err_Ok
decl_stmt|;
name|FT_Outline
modifier|*
name|base
init|=
operator|&
name|loader
operator|->
name|base
operator|.
name|outline
decl_stmt|;
name|FT_Outline
modifier|*
name|current
init|=
operator|&
name|loader
operator|->
name|current
operator|.
name|outline
decl_stmt|;
name|FT_Bool
name|adjust
init|=
literal|0
decl_stmt|;
name|FT_UInt
name|new_max
decl_stmt|,
name|old_max
decl_stmt|;
comment|/* check points& tags */
name|new_max
operator|=
name|base
operator|->
name|n_points
operator|+
name|current
operator|->
name|n_points
operator|+
name|n_points
expr_stmt|;
name|old_max
operator|=
name|loader
operator|->
name|max_points
expr_stmt|;
if|if
condition|(
name|new_max
operator|>
name|old_max
condition|)
block|{
name|new_max
operator|=
name|FT_PAD_CEIL
argument_list|(
name|new_max
argument_list|,
literal|8
argument_list|)
expr_stmt|;
if|if
condition|(
name|FT_RENEW_ARRAY
argument_list|(
name|base
operator|->
name|points
argument_list|,
name|old_max
argument_list|,
name|new_max
argument_list|)
operator|||
name|FT_RENEW_ARRAY
argument_list|(
name|base
operator|->
name|tags
argument_list|,
name|old_max
argument_list|,
name|new_max
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
if|if
condition|(
name|loader
operator|->
name|use_extra
condition|)
block|{
if|if
condition|(
name|FT_RENEW_ARRAY
argument_list|(
name|loader
operator|->
name|base
operator|.
name|extra_points
argument_list|,
name|old_max
operator|*
literal|2
argument_list|,
name|new_max
operator|*
literal|2
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
name|FT_ARRAY_MOVE
argument_list|(
name|loader
operator|->
name|base
operator|.
name|extra_points
operator|+
name|new_max
argument_list|,
name|loader
operator|->
name|base
operator|.
name|extra_points
operator|+
name|old_max
argument_list|,
name|old_max
argument_list|)
expr_stmt|;
name|loader
operator|->
name|base
operator|.
name|extra_points2
operator|=
name|loader
operator|->
name|base
operator|.
name|extra_points
operator|+
name|new_max
expr_stmt|;
block|}
name|adjust
operator|=
literal|1
expr_stmt|;
name|loader
operator|->
name|max_points
operator|=
name|new_max
expr_stmt|;
block|}
comment|/* check contours */
name|old_max
operator|=
name|loader
operator|->
name|max_contours
expr_stmt|;
name|new_max
operator|=
name|base
operator|->
name|n_contours
operator|+
name|current
operator|->
name|n_contours
operator|+
name|n_contours
expr_stmt|;
if|if
condition|(
name|new_max
operator|>
name|old_max
condition|)
block|{
name|new_max
operator|=
name|FT_PAD_CEIL
argument_list|(
name|new_max
argument_list|,
literal|4
argument_list|)
expr_stmt|;
if|if
condition|(
name|FT_RENEW_ARRAY
argument_list|(
name|base
operator|->
name|contours
argument_list|,
name|old_max
argument_list|,
name|new_max
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
name|adjust
operator|=
literal|1
expr_stmt|;
name|loader
operator|->
name|max_contours
operator|=
name|new_max
expr_stmt|;
block|}
if|if
condition|(
name|adjust
condition|)
name|FT_GlyphLoader_Adjust_Points
argument_list|(
name|loader
argument_list|)
expr_stmt|;
name|Exit
label|:
return|return
name|error
return|;
block|}
end_block
begin_comment
comment|/* Ensure that we can add `n_subglyphs' to our glyph. this function */
end_comment
begin_comment
comment|/* reallocates its subglyphs table if necessary.  Note that it DOES */
end_comment
begin_comment
comment|/* NOT change the number of subglyphs within the loader!            */
end_comment
begin_comment
comment|/*                                                                  */
end_comment
begin_macro
DECL|function|FT_BASE_DEF
name|FT_BASE_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_GlyphLoader_CheckSubGlyphs
argument_list|(
argument|FT_GlyphLoader  loader
argument_list|,
argument|FT_UInt         n_subs
argument_list|)
end_macro
begin_block
block|{
name|FT_Memory
name|memory
init|=
name|loader
operator|->
name|memory
decl_stmt|;
name|FT_Error
name|error
init|=
name|FT_Err_Ok
decl_stmt|;
name|FT_UInt
name|new_max
decl_stmt|,
name|old_max
decl_stmt|;
name|FT_GlyphLoad
name|base
init|=
operator|&
name|loader
operator|->
name|base
decl_stmt|;
name|FT_GlyphLoad
name|current
init|=
operator|&
name|loader
operator|->
name|current
decl_stmt|;
name|new_max
operator|=
name|base
operator|->
name|num_subglyphs
operator|+
name|current
operator|->
name|num_subglyphs
operator|+
name|n_subs
expr_stmt|;
name|old_max
operator|=
name|loader
operator|->
name|max_subglyphs
expr_stmt|;
if|if
condition|(
name|new_max
operator|>
name|old_max
condition|)
block|{
name|new_max
operator|=
name|FT_PAD_CEIL
argument_list|(
name|new_max
argument_list|,
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|FT_RENEW_ARRAY
argument_list|(
name|base
operator|->
name|subglyphs
argument_list|,
name|old_max
argument_list|,
name|new_max
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
name|loader
operator|->
name|max_subglyphs
operator|=
name|new_max
expr_stmt|;
name|FT_GlyphLoader_Adjust_Subglyphs
argument_list|(
name|loader
argument_list|)
expr_stmt|;
block|}
name|Exit
label|:
return|return
name|error
return|;
block|}
end_block
begin_comment
comment|/* prepare loader for the addition of a new glyph on top of the base one */
end_comment
begin_macro
name|FT_BASE_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FT_GlyphLoader_Prepare
name|FT_GlyphLoader_Prepare
argument_list|(
argument|FT_GlyphLoader  loader
argument_list|)
end_macro
begin_block
block|{
name|FT_GlyphLoad
name|current
init|=
operator|&
name|loader
operator|->
name|current
decl_stmt|;
name|current
operator|->
name|outline
operator|.
name|n_points
operator|=
literal|0
expr_stmt|;
name|current
operator|->
name|outline
operator|.
name|n_contours
operator|=
literal|0
expr_stmt|;
name|current
operator|->
name|num_subglyphs
operator|=
literal|0
expr_stmt|;
name|FT_GlyphLoader_Adjust_Points
argument_list|(
name|loader
argument_list|)
expr_stmt|;
name|FT_GlyphLoader_Adjust_Subglyphs
argument_list|(
name|loader
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/* add current glyph to the base image - and prepare for another */
end_comment
begin_macro
name|FT_BASE_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FT_GlyphLoader_Add
name|FT_GlyphLoader_Add
argument_list|(
argument|FT_GlyphLoader  loader
argument_list|)
end_macro
begin_block
block|{
name|FT_GlyphLoad
name|base
decl_stmt|;
name|FT_GlyphLoad
name|current
decl_stmt|;
name|FT_UInt
name|n_curr_contours
decl_stmt|;
name|FT_UInt
name|n_base_points
decl_stmt|;
name|FT_UInt
name|n
decl_stmt|;
if|if
condition|(
operator|!
name|loader
condition|)
return|return;
name|base
operator|=
operator|&
name|loader
operator|->
name|base
expr_stmt|;
name|current
operator|=
operator|&
name|loader
operator|->
name|current
expr_stmt|;
name|n_curr_contours
operator|=
name|current
operator|->
name|outline
operator|.
name|n_contours
expr_stmt|;
name|n_base_points
operator|=
name|base
operator|->
name|outline
operator|.
name|n_points
expr_stmt|;
name|base
operator|->
name|outline
operator|.
name|n_points
operator|=
call|(
name|short
call|)
argument_list|(
name|base
operator|->
name|outline
operator|.
name|n_points
operator|+
name|current
operator|->
name|outline
operator|.
name|n_points
argument_list|)
expr_stmt|;
name|base
operator|->
name|outline
operator|.
name|n_contours
operator|=
call|(
name|short
call|)
argument_list|(
name|base
operator|->
name|outline
operator|.
name|n_contours
operator|+
name|current
operator|->
name|outline
operator|.
name|n_contours
argument_list|)
expr_stmt|;
name|base
operator|->
name|num_subglyphs
operator|+=
name|current
operator|->
name|num_subglyphs
expr_stmt|;
comment|/* adjust contours count in newest outline */
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|n_curr_contours
condition|;
name|n
operator|++
control|)
name|current
operator|->
name|outline
operator|.
name|contours
index|[
name|n
index|]
operator|=
call|(
name|short
call|)
argument_list|(
name|current
operator|->
name|outline
operator|.
name|contours
index|[
name|n
index|]
operator|+
name|n_base_points
argument_list|)
expr_stmt|;
comment|/* prepare for another new glyph image */
name|FT_GlyphLoader_Prepare
argument_list|(
name|loader
argument_list|)
expr_stmt|;
block|}
end_block
begin_macro
DECL|function|FT_BASE_DEF
name|FT_BASE_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_GlyphLoader_CopyPoints
argument_list|(
argument|FT_GlyphLoader  target
argument_list|,
argument|FT_GlyphLoader  source
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|FT_UInt
name|num_points
init|=
name|source
operator|->
name|base
operator|.
name|outline
operator|.
name|n_points
decl_stmt|;
name|FT_UInt
name|num_contours
init|=
name|source
operator|->
name|base
operator|.
name|outline
operator|.
name|n_contours
decl_stmt|;
name|error
operator|=
name|FT_GlyphLoader_CheckPoints
argument_list|(
name|target
argument_list|,
name|num_points
argument_list|,
name|num_contours
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
block|{
name|FT_Outline
modifier|*
name|out
init|=
operator|&
name|target
operator|->
name|base
operator|.
name|outline
decl_stmt|;
name|FT_Outline
modifier|*
name|in
init|=
operator|&
name|source
operator|->
name|base
operator|.
name|outline
decl_stmt|;
name|FT_ARRAY_COPY
argument_list|(
name|out
operator|->
name|points
argument_list|,
name|in
operator|->
name|points
argument_list|,
name|num_points
argument_list|)
expr_stmt|;
name|FT_ARRAY_COPY
argument_list|(
name|out
operator|->
name|tags
argument_list|,
name|in
operator|->
name|tags
argument_list|,
name|num_points
argument_list|)
expr_stmt|;
name|FT_ARRAY_COPY
argument_list|(
name|out
operator|->
name|contours
argument_list|,
name|in
operator|->
name|contours
argument_list|,
name|num_contours
argument_list|)
expr_stmt|;
comment|/* do we need to copy the extra points? */
if|if
condition|(
name|target
operator|->
name|use_extra
operator|&&
name|source
operator|->
name|use_extra
condition|)
block|{
name|FT_ARRAY_COPY
argument_list|(
name|target
operator|->
name|base
operator|.
name|extra_points
argument_list|,
name|source
operator|->
name|base
operator|.
name|extra_points
argument_list|,
name|num_points
argument_list|)
expr_stmt|;
name|FT_ARRAY_COPY
argument_list|(
name|target
operator|->
name|base
operator|.
name|extra_points2
argument_list|,
name|source
operator|->
name|base
operator|.
name|extra_points2
argument_list|,
name|num_points
argument_list|)
expr_stmt|;
block|}
name|out
operator|->
name|n_points
operator|=
operator|(
name|short
operator|)
name|num_points
expr_stmt|;
name|out
operator|->
name|n_contours
operator|=
operator|(
name|short
operator|)
name|num_contours
expr_stmt|;
name|FT_GlyphLoader_Adjust_Points
argument_list|(
name|target
argument_list|)
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
