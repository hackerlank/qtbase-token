begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  t42drivr.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    High-level Type 42 driver interface (body).                          */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002, 2003, 2004, 2006, 2007, 2009 by Roberto Alameda.       */
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
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* This driver implements Type42 fonts as described in the               */
end_comment
begin_comment
comment|/* Technical Note #5012 from Adobe, with these limitations:              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* 1) CID Fonts are not currently supported.                             */
end_comment
begin_comment
comment|/* 2) Incremental fonts making use of the GlyphDirectory keyword         */
end_comment
begin_comment
comment|/*    will be loaded, but the rendering will be using the TrueType       */
end_comment
begin_comment
comment|/*    tables.                                                            */
end_comment
begin_comment
comment|/* 3) As for Type1 fonts, CDevProc is not supported.                     */
end_comment
begin_comment
comment|/* 4) The Metrics dictionary is not supported.                           */
end_comment
begin_comment
comment|/* 5) AFM metrics are not supported.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* In other words, this driver supports Type42 fonts derived from        */
end_comment
begin_comment
comment|/* TrueType fonts in a non-CID manner, as done by usual conversion       */
end_comment
begin_comment
comment|/* programs.                                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"t42drivr.h"
end_include
begin_include
include|#
directive|include
file|"t42objs.h"
end_include
begin_include
include|#
directive|include
file|"t42error.h"
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_XFREE86_NAME_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_GLYPH_DICT_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_POSTSCRIPT_NAME_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_POSTSCRIPT_INFO_H
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
value|trace_t42
end_define
begin_comment
comment|/*    *    *  GLYPH DICT SERVICE    *    */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|t42_get_glyph_name
name|t42_get_glyph_name
parameter_list|(
name|T42_Face
name|face
parameter_list|,
name|FT_UInt
name|glyph_index
parameter_list|,
name|FT_Pointer
name|buffer
parameter_list|,
name|FT_UInt
name|buffer_max
parameter_list|)
block|{
name|FT_STRCPYN
argument_list|(
name|buffer
argument_list|,
name|face
operator|->
name|type1
operator|.
name|glyph_names
index|[
name|glyph_index
index|]
argument_list|,
name|buffer_max
argument_list|)
expr_stmt|;
return|return
name|T42_Err_Ok
return|;
block|}
end_function
begin_function
specifier|static
name|FT_UInt
DECL|function|t42_get_name_index
name|t42_get_name_index
parameter_list|(
name|T42_Face
name|face
parameter_list|,
name|FT_String
modifier|*
name|glyph_name
parameter_list|)
block|{
name|FT_Int
name|i
decl_stmt|;
name|FT_String
modifier|*
name|gname
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|face
operator|->
name|type1
operator|.
name|num_glyphs
condition|;
name|i
operator|++
control|)
block|{
name|gname
operator|=
name|face
operator|->
name|type1
operator|.
name|glyph_names
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|glyph_name
index|[
literal|0
index|]
operator|==
name|gname
index|[
literal|0
index|]
operator|&&
operator|!
name|ft_strcmp
argument_list|(
name|glyph_name
argument_list|,
name|gname
argument_list|)
condition|)
return|return
operator|(
name|FT_UInt
operator|)
name|ft_atol
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|face
operator|->
name|type1
operator|.
name|charstrings
index|[
name|i
index|]
argument_list|)
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|t42_service_glyph_dict
specifier|static
specifier|const
name|FT_Service_GlyphDictRec
name|t42_service_glyph_dict
init|=
block|{
operator|(
name|FT_GlyphDict_GetNameFunc
operator|)
name|t42_get_glyph_name
block|,
operator|(
name|FT_GlyphDict_NameIndexFunc
operator|)
name|t42_get_name_index
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*    *    *  POSTSCRIPT NAME SERVICE    *    */
end_comment
begin_function
specifier|static
specifier|const
name|char
modifier|*
DECL|function|t42_get_ps_font_name
name|t42_get_ps_font_name
parameter_list|(
name|T42_Face
name|face
parameter_list|)
block|{
return|return
operator|(
specifier|const
name|char
operator|*
operator|)
name|face
operator|->
name|type1
operator|.
name|font_name
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|t42_service_ps_font_name
specifier|static
specifier|const
name|FT_Service_PsFontNameRec
name|t42_service_ps_font_name
init|=
block|{
operator|(
name|FT_PsName_GetFunc
operator|)
name|t42_get_ps_font_name
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*    *    *  POSTSCRIPT INFO SERVICE    *    */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|t42_ps_get_font_info
name|t42_ps_get_font_info
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|PS_FontInfoRec
modifier|*
name|afont_info
parameter_list|)
block|{
operator|*
name|afont_info
operator|=
operator|(
operator|(
name|T42_Face
operator|)
name|face
operator|)
operator|->
name|type1
operator|.
name|font_info
expr_stmt|;
return|return
name|T42_Err_Ok
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|t42_ps_get_font_extra
name|t42_ps_get_font_extra
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|PS_FontExtraRec
modifier|*
name|afont_extra
parameter_list|)
block|{
operator|*
name|afont_extra
operator|=
operator|(
operator|(
name|T42_Face
operator|)
name|face
operator|)
operator|->
name|type1
operator|.
name|font_extra
expr_stmt|;
return|return
name|T42_Err_Ok
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Int
DECL|function|t42_ps_has_glyph_names
name|t42_ps_has_glyph_names
parameter_list|(
name|FT_Face
name|face
parameter_list|)
block|{
name|FT_UNUSED
argument_list|(
name|face
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|t42_ps_get_font_private
name|t42_ps_get_font_private
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|PS_PrivateRec
modifier|*
name|afont_private
parameter_list|)
block|{
operator|*
name|afont_private
operator|=
operator|(
operator|(
name|T42_Face
operator|)
name|face
operator|)
operator|->
name|type1
operator|.
name|private_dict
expr_stmt|;
return|return
name|T42_Err_Ok
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|t42_service_ps_info
specifier|static
specifier|const
name|FT_Service_PsInfoRec
name|t42_service_ps_info
init|=
block|{
operator|(
name|PS_GetFontInfoFunc
operator|)
name|t42_ps_get_font_info
block|,
operator|(
name|PS_GetFontExtraFunc
operator|)
name|t42_ps_get_font_extra
block|,
operator|(
name|PS_HasGlyphNamesFunc
operator|)
name|t42_ps_has_glyph_names
block|,
operator|(
name|PS_GetFontPrivateFunc
operator|)
name|t42_ps_get_font_private
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*    *    *  SERVICE LIST    *    */
end_comment
begin_decl_stmt
DECL|variable|t42_services
specifier|static
specifier|const
name|FT_ServiceDescRec
name|t42_services
index|[]
init|=
block|{
block|{
name|FT_SERVICE_ID_GLYPH_DICT
block|,
operator|&
name|t42_service_glyph_dict
block|}
block|,
block|{
name|FT_SERVICE_ID_POSTSCRIPT_FONT_NAME
block|,
operator|&
name|t42_service_ps_font_name
block|}
block|,
block|{
name|FT_SERVICE_ID_POSTSCRIPT_INFO
block|,
operator|&
name|t42_service_ps_info
block|}
block|,
block|{
name|FT_SERVICE_ID_XF86_NAME
block|,
name|FT_XF86_FORMAT_TYPE_42
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_function
specifier|static
name|FT_Module_Interface
DECL|function|T42_Get_Interface
name|T42_Get_Interface
parameter_list|(
name|FT_Driver
name|driver
parameter_list|,
specifier|const
name|FT_String
modifier|*
name|t42_interface
parameter_list|)
block|{
name|FT_UNUSED
argument_list|(
name|driver
argument_list|)
expr_stmt|;
return|return
name|ft_service_list_lookup
argument_list|(
name|t42_services
argument_list|,
name|t42_interface
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|t42_driver_class
specifier|const
name|FT_Driver_ClassRec
name|t42_driver_class
init|=
block|{
block|{
name|FT_MODULE_FONT_DRIVER
operator||
name|FT_MODULE_DRIVER_SCALABLE
operator||
ifdef|#
directive|ifdef
name|TT_USE_BYTECODE_INTERPRETER
name|FT_MODULE_DRIVER_HAS_HINTER
block|,
else|#
directive|else
literal|0
block|,
endif|#
directive|endif
sizeof|sizeof
argument_list|(
name|T42_DriverRec
argument_list|)
block|,
literal|"type42"
block|,
literal|0x10000L
block|,
literal|0x20000L
block|,
literal|0
block|,
comment|/* format interface */
operator|(
name|FT_Module_Constructor
operator|)
name|T42_Driver_Init
block|,
operator|(
name|FT_Module_Destructor
operator|)
name|T42_Driver_Done
block|,
operator|(
name|FT_Module_Requester
operator|)
name|T42_Get_Interface
block|,     }
block|,
sizeof|sizeof
argument_list|(
name|T42_FaceRec
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|T42_SizeRec
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|T42_GlyphSlotRec
argument_list|)
block|,
operator|(
name|FT_Face_InitFunc
operator|)
name|T42_Face_Init
block|,
operator|(
name|FT_Face_DoneFunc
operator|)
name|T42_Face_Done
block|,
operator|(
name|FT_Size_InitFunc
operator|)
name|T42_Size_Init
block|,
operator|(
name|FT_Size_DoneFunc
operator|)
name|T42_Size_Done
block|,
operator|(
name|FT_Slot_InitFunc
operator|)
name|T42_GlyphSlot_Init
block|,
operator|(
name|FT_Slot_DoneFunc
operator|)
name|T42_GlyphSlot_Done
block|,
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_OLD_INTERNALS
name|ft_stub_set_char_sizes
block|,
name|ft_stub_set_pixel_sizes
block|,
endif|#
directive|endif
operator|(
name|FT_Slot_LoadFunc
operator|)
name|T42_GlyphSlot_Load
block|,
operator|(
name|FT_Face_GetKerningFunc
operator|)
literal|0
block|,
operator|(
name|FT_Face_AttachFunc
operator|)
literal|0
block|,
operator|(
name|FT_Face_GetAdvancesFunc
operator|)
literal|0
block|,
operator|(
name|FT_Size_RequestFunc
operator|)
name|T42_Size_Request
block|,
operator|(
name|FT_Size_SelectFunc
operator|)
name|T42_Size_Select
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* END */
end_comment
end_unit
