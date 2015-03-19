begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftcid.c                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType API for accessing CID font information.                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2007, 2009, 2013 by Derek Clegg, Michael Toftdal.            */
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
include|FT_CID_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_CID_H
end_include
begin_comment
comment|/* documentation is in ftcid.h */
end_comment
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Get_CID_Registry_Ordering_Supplement
argument_list|(
argument|FT_Face       face
argument_list|,
argument|const char*  *registry
argument_list|,
argument|const char*  *ordering
argument_list|,
argument|FT_Int       *supplement
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
specifier|const
name|char
modifier|*
name|r
init|=
name|NULL
decl_stmt|;
specifier|const
name|char
modifier|*
name|o
init|=
name|NULL
decl_stmt|;
name|FT_Int
name|s
init|=
literal|0
decl_stmt|;
name|error
operator|=
name|FT_ERR
argument_list|(
name|Invalid_Argument
argument_list|)
expr_stmt|;
if|if
condition|(
name|face
condition|)
block|{
name|FT_Service_CID
name|service
decl_stmt|;
name|FT_FACE_FIND_SERVICE
argument_list|(
name|face
argument_list|,
name|service
argument_list|,
name|CID
argument_list|)
expr_stmt|;
if|if
condition|(
name|service
operator|&&
name|service
operator|->
name|get_ros
condition|)
name|error
operator|=
name|service
operator|->
name|get_ros
argument_list|(
name|face
argument_list|,
operator|&
name|r
argument_list|,
operator|&
name|o
argument_list|,
operator|&
name|s
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|registry
condition|)
operator|*
name|registry
operator|=
name|r
expr_stmt|;
if|if
condition|(
name|ordering
condition|)
operator|*
name|ordering
operator|=
name|o
expr_stmt|;
if|if
condition|(
name|supplement
condition|)
operator|*
name|supplement
operator|=
name|s
expr_stmt|;
return|return
name|error
return|;
block|}
end_block
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Get_CID_Is_Internally_CID_Keyed
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_Bool  *is_cid
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
init|=
name|FT_ERR
argument_list|(
name|Invalid_Argument
argument_list|)
decl_stmt|;
name|FT_Bool
name|ic
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|face
condition|)
block|{
name|FT_Service_CID
name|service
decl_stmt|;
name|FT_FACE_FIND_SERVICE
argument_list|(
name|face
argument_list|,
name|service
argument_list|,
name|CID
argument_list|)
expr_stmt|;
if|if
condition|(
name|service
operator|&&
name|service
operator|->
name|get_is_cid
condition|)
name|error
operator|=
name|service
operator|->
name|get_is_cid
argument_list|(
name|face
argument_list|,
operator|&
name|ic
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|is_cid
condition|)
operator|*
name|is_cid
operator|=
name|ic
expr_stmt|;
return|return
name|error
return|;
block|}
end_block
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Get_CID_From_Glyph_Index
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_UInt   glyph_index
argument_list|,
argument|FT_UInt  *cid
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
init|=
name|FT_ERR
argument_list|(
name|Invalid_Argument
argument_list|)
decl_stmt|;
name|FT_UInt
name|c
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|face
condition|)
block|{
name|FT_Service_CID
name|service
decl_stmt|;
name|FT_FACE_FIND_SERVICE
argument_list|(
name|face
argument_list|,
name|service
argument_list|,
name|CID
argument_list|)
expr_stmt|;
if|if
condition|(
name|service
operator|&&
name|service
operator|->
name|get_cid_from_glyph_index
condition|)
name|error
operator|=
name|service
operator|->
name|get_cid_from_glyph_index
argument_list|(
name|face
argument_list|,
name|glyph_index
argument_list|,
operator|&
name|c
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|cid
condition|)
operator|*
name|cid
operator|=
name|c
expr_stmt|;
return|return
name|error
return|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
