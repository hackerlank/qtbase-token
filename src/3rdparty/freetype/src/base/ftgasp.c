begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftgasp.c                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Access of TrueType's `gasp' table (body).                            */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2007 by                                                      */
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
include|FT_GASP_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_TRUETYPE_TYPES_H
end_include
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Int
argument_list|)
end_macro
begin_macro
name|FT_Get_Gasp
argument_list|(
argument|FT_Face  face
argument_list|,
argument|FT_UInt  ppem
argument_list|)
end_macro
begin_block
block|{
name|FT_Int
name|result
init|=
name|FT_GASP_NO_TABLE
decl_stmt|;
if|if
condition|(
name|face
operator|&&
name|FT_IS_SFNT
argument_list|(
name|face
argument_list|)
condition|)
block|{
name|TT_Face
name|ttface
init|=
operator|(
name|TT_Face
operator|)
name|face
decl_stmt|;
if|if
condition|(
name|ttface
operator|->
name|gasp
operator|.
name|numRanges
operator|>
literal|0
condition|)
block|{
name|TT_GaspRange
name|range
init|=
name|ttface
operator|->
name|gasp
operator|.
name|gaspRanges
decl_stmt|;
name|TT_GaspRange
name|range_end
init|=
name|range
operator|+
name|ttface
operator|->
name|gasp
operator|.
name|numRanges
decl_stmt|;
while|while
condition|(
name|ppem
operator|>
name|range
operator|->
name|maxPPEM
condition|)
block|{
name|range
operator|++
expr_stmt|;
if|if
condition|(
name|range
operator|>=
name|range_end
condition|)
goto|goto
name|Exit
goto|;
block|}
name|result
operator|=
name|range
operator|->
name|gaspFlag
expr_stmt|;
comment|/* ensure that we don't have spurious bits */
if|if
condition|(
name|ttface
operator|->
name|gasp
operator|.
name|version
operator|==
literal|0
condition|)
name|result
operator|&=
literal|3
expr_stmt|;
block|}
block|}
name|Exit
label|:
return|return
name|result
return|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
