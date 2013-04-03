begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftsynth.c                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType synthesizing code for emboldening and slanting (body).      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2000-2001, 2002, 2003, 2004, 2005, 2006, 2010 by             */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
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
include|FT_SYNTHESIS_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_OUTLINE_H
end_include
begin_include
include|#
directive|include
include|FT_BITMAP_H
end_include
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The macro FT_COMPONENT is used in trace mode.  It is an implicit      */
end_comment
begin_comment
comment|/* parameter of the FT_TRACE() and FT_ERROR() macros, used to print/log  */
end_comment
begin_comment
comment|/* messages during execution.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
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
value|trace_synth
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****   EXPERIMENTAL OBLIQUING SUPPORT                                ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* documentation is in ftsynth.h */
end_comment
begin_macro
name|FT_EXPORT_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FT_GlyphSlot_Oblique
name|FT_GlyphSlot_Oblique
argument_list|(
argument|FT_GlyphSlot  slot
argument_list|)
end_macro
begin_block
block|{
name|FT_Matrix
name|transform
decl_stmt|;
name|FT_Outline
modifier|*
name|outline
init|=
operator|&
name|slot
operator|->
name|outline
decl_stmt|;
comment|/* only oblique outline glyphs */
if|if
condition|(
name|slot
operator|->
name|format
operator|!=
name|FT_GLYPH_FORMAT_OUTLINE
condition|)
return|return;
comment|/* we don't touch the advance width */
comment|/* For italic, simply apply a shear transform, with an angle */
comment|/* of about 12 degrees.                                      */
name|transform
operator|.
name|xx
operator|=
literal|0x10000L
expr_stmt|;
name|transform
operator|.
name|yx
operator|=
literal|0x00000L
expr_stmt|;
name|transform
operator|.
name|xy
operator|=
literal|0x06000L
expr_stmt|;
name|transform
operator|.
name|yy
operator|=
literal|0x10000L
expr_stmt|;
name|FT_Outline_Transform
argument_list|(
name|outline
argument_list|,
operator|&
name|transform
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****   EXPERIMENTAL EMBOLDENING/OUTLINING SUPPORT                    ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* documentation is in ftsynth.h */
end_comment
begin_macro
name|FT_EXPORT_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FT_GlyphSlot_Embolden
name|FT_GlyphSlot_Embolden
argument_list|(
argument|FT_GlyphSlot  slot
argument_list|)
end_macro
begin_block
block|{
name|FT_Library
name|library
init|=
name|slot
operator|->
name|library
decl_stmt|;
name|FT_Face
name|face
init|=
name|slot
operator|->
name|face
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
name|FT_Pos
name|xstr
decl_stmt|,
name|ystr
decl_stmt|;
if|if
condition|(
name|slot
operator|->
name|format
operator|!=
name|FT_GLYPH_FORMAT_OUTLINE
operator|&&
name|slot
operator|->
name|format
operator|!=
name|FT_GLYPH_FORMAT_BITMAP
condition|)
return|return;
comment|/* some reasonable strength */
name|xstr
operator|=
name|FT_MulFix
argument_list|(
name|face
operator|->
name|units_per_EM
argument_list|,
name|face
operator|->
name|size
operator|->
name|metrics
operator|.
name|y_scale
argument_list|)
operator|/
literal|24
expr_stmt|;
name|ystr
operator|=
name|xstr
expr_stmt|;
if|if
condition|(
name|slot
operator|->
name|format
operator|==
name|FT_GLYPH_FORMAT_OUTLINE
condition|)
block|{
comment|/* ignore error */
operator|(
name|void
operator|)
name|FT_Outline_Embolden
argument_list|(
operator|&
name|slot
operator|->
name|outline
argument_list|,
name|xstr
argument_list|)
expr_stmt|;
comment|/* this is more than enough for most glyphs; if you need accurate */
comment|/* values, you have to call FT_Outline_Get_CBox                   */
name|xstr
operator|=
name|xstr
operator|*
literal|2
expr_stmt|;
name|ystr
operator|=
name|xstr
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|slot
operator|->
name|format
operator|==
name|FT_GLYPH_FORMAT_BITMAP
condition|)
block|{
comment|/* round to full pixels */
name|xstr
operator|&=
operator|~
literal|63
expr_stmt|;
if|if
condition|(
name|xstr
operator|==
literal|0
condition|)
name|xstr
operator|=
literal|1
operator|<<
literal|6
expr_stmt|;
name|ystr
operator|&=
operator|~
literal|63
expr_stmt|;
comment|/*        * XXX: overflow check for 16-bit system, for compatibility        *      with FT_GlyphSlot_Embolden() since freetype-2.1.10.        *      unfortunately, this function return no informations        *      about the cause of error.        */
if|if
condition|(
operator|(
name|ystr
operator|>>
literal|6
operator|)
operator|>
name|FT_INT_MAX
operator|||
operator|(
name|ystr
operator|>>
literal|6
operator|)
operator|<
name|FT_INT_MIN
condition|)
block|{
name|FT_TRACE1
argument_list|(
operator|(
literal|"FT_GlyphSlot_Embolden:"
operator|)
argument_list|)
expr_stmt|;
name|FT_TRACE1
argument_list|(
operator|(
literal|"too strong embolding parameter ystr=%d\n"
operator|,
name|ystr
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|error
operator|=
name|FT_GlyphSlot_Own_Bitmap
argument_list|(
name|slot
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
return|return;
name|error
operator|=
name|FT_Bitmap_Embolden
argument_list|(
name|library
argument_list|,
operator|&
name|slot
operator|->
name|bitmap
argument_list|,
name|xstr
argument_list|,
name|ystr
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
return|return;
block|}
if|if
condition|(
name|slot
operator|->
name|advance
operator|.
name|x
condition|)
name|slot
operator|->
name|advance
operator|.
name|x
operator|+=
name|xstr
expr_stmt|;
if|if
condition|(
name|slot
operator|->
name|advance
operator|.
name|y
condition|)
name|slot
operator|->
name|advance
operator|.
name|y
operator|+=
name|ystr
expr_stmt|;
name|slot
operator|->
name|metrics
operator|.
name|width
operator|+=
name|xstr
expr_stmt|;
name|slot
operator|->
name|metrics
operator|.
name|height
operator|+=
name|ystr
expr_stmt|;
name|slot
operator|->
name|metrics
operator|.
name|horiBearingY
operator|+=
name|ystr
expr_stmt|;
name|slot
operator|->
name|metrics
operator|.
name|horiAdvance
operator|+=
name|xstr
expr_stmt|;
name|slot
operator|->
name|metrics
operator|.
name|vertBearingX
operator|-=
name|xstr
operator|/
literal|2
expr_stmt|;
name|slot
operator|->
name|metrics
operator|.
name|vertBearingY
operator|+=
name|ystr
expr_stmt|;
name|slot
operator|->
name|metrics
operator|.
name|vertAdvance
operator|+=
name|ystr
expr_stmt|;
comment|/* XXX: 16-bit overflow case must be excluded before here */
if|if
condition|(
name|slot
operator|->
name|format
operator|==
name|FT_GLYPH_FORMAT_BITMAP
condition|)
name|slot
operator|->
name|bitmap_top
operator|+=
call|(
name|FT_Int
call|)
argument_list|(
name|ystr
operator|>>
literal|6
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
