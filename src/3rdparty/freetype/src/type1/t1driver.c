begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  t1driver.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Type 1 driver interface (body).                                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2004, 2006, 2007, 2009 by             */
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
file|"t1driver.h"
end_include
begin_include
include|#
directive|include
file|"t1gload.h"
end_include
begin_include
include|#
directive|include
file|"t1load.h"
end_include
begin_include
include|#
directive|include
file|"t1errors.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|T1_CONFIG_OPTION_NO_AFM
end_ifndef
begin_include
include|#
directive|include
file|"t1afm.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_STREAM_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_MULTIPLE_MASTERS_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_GLYPH_DICT_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_XFREE86_NAME_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_POSTSCRIPT_NAME_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_POSTSCRIPT_CMAPS_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_POSTSCRIPT_INFO_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_KERNING_H
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
value|trace_t1driver
end_define
begin_comment
comment|/*   *  GLYPH DICT SERVICE   *   */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|t1_get_glyph_name
name|t1_get_glyph_name
parameter_list|(
name|T1_Face
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
name|T1_Err_Ok
return|;
block|}
end_function
begin_function
specifier|static
name|FT_UInt
DECL|function|t1_get_name_index
name|t1_get_name_index
parameter_list|(
name|T1_Face
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
name|i
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|t1_service_glyph_dict
specifier|static
specifier|const
name|FT_Service_GlyphDictRec
name|t1_service_glyph_dict
init|=
block|{
operator|(
name|FT_GlyphDict_GetNameFunc
operator|)
name|t1_get_glyph_name
block|,
operator|(
name|FT_GlyphDict_NameIndexFunc
operator|)
name|t1_get_name_index
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*    *  POSTSCRIPT NAME SERVICE    *    */
end_comment
begin_function
specifier|static
specifier|const
name|char
modifier|*
DECL|function|t1_get_ps_name
name|t1_get_ps_name
parameter_list|(
name|T1_Face
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
DECL|variable|t1_service_ps_name
specifier|static
specifier|const
name|FT_Service_PsFontNameRec
name|t1_service_ps_name
init|=
block|{
operator|(
name|FT_PsName_GetFunc
operator|)
name|t1_get_ps_name
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*    *  MULTIPLE MASTERS SERVICE    *    */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|T1_CONFIG_OPTION_NO_MM_SUPPORT
end_ifndef
begin_decl_stmt
DECL|variable|t1_service_multi_masters
specifier|static
specifier|const
name|FT_Service_MultiMastersRec
name|t1_service_multi_masters
init|=
block|{
operator|(
name|FT_Get_MM_Func
operator|)
name|T1_Get_Multi_Master
block|,
operator|(
name|FT_Set_MM_Design_Func
operator|)
name|T1_Set_MM_Design
block|,
operator|(
name|FT_Set_MM_Blend_Func
operator|)
name|T1_Set_MM_Blend
block|,
operator|(
name|FT_Get_MM_Var_Func
operator|)
name|T1_Get_MM_Var
block|,
operator|(
name|FT_Set_Var_Design_Func
operator|)
name|T1_Set_Var_Design
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*    *  POSTSCRIPT INFO SERVICE    *    */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|t1_ps_get_font_info
name|t1_ps_get_font_info
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
name|T1_Face
operator|)
name|face
operator|)
operator|->
name|type1
operator|.
name|font_info
expr_stmt|;
return|return
name|T1_Err_Ok
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|t1_ps_get_font_extra
name|t1_ps_get_font_extra
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
name|T1_Face
operator|)
name|face
operator|)
operator|->
name|type1
operator|.
name|font_extra
expr_stmt|;
return|return
name|T1_Err_Ok
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Int
DECL|function|t1_ps_has_glyph_names
name|t1_ps_has_glyph_names
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
DECL|function|t1_ps_get_font_private
name|t1_ps_get_font_private
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
name|T1_Face
operator|)
name|face
operator|)
operator|->
name|type1
operator|.
name|private_dict
expr_stmt|;
return|return
name|T1_Err_Ok
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|t1_service_ps_info
specifier|static
specifier|const
name|FT_Service_PsInfoRec
name|t1_service_ps_info
init|=
block|{
operator|(
name|PS_GetFontInfoFunc
operator|)
name|t1_ps_get_font_info
block|,
operator|(
name|PS_GetFontExtraFunc
operator|)
name|t1_ps_get_font_extra
block|,
operator|(
name|PS_HasGlyphNamesFunc
operator|)
name|t1_ps_has_glyph_names
block|,
operator|(
name|PS_GetFontPrivateFunc
operator|)
name|t1_ps_get_font_private
block|,   }
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|T1_CONFIG_OPTION_NO_AFM
end_ifndef
begin_decl_stmt
DECL|variable|t1_service_kerning
specifier|static
specifier|const
name|FT_Service_KerningRec
name|t1_service_kerning
init|=
block|{
name|T1_Get_Track_Kerning
block|,   }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*    *  SERVICE LIST    *    */
end_comment
begin_decl_stmt
DECL|variable|t1_services
specifier|static
specifier|const
name|FT_ServiceDescRec
name|t1_services
index|[]
init|=
block|{
block|{
name|FT_SERVICE_ID_POSTSCRIPT_FONT_NAME
block|,
operator|&
name|t1_service_ps_name
block|}
block|,
block|{
name|FT_SERVICE_ID_GLYPH_DICT
block|,
operator|&
name|t1_service_glyph_dict
block|}
block|,
block|{
name|FT_SERVICE_ID_XF86_NAME
block|,
name|FT_XF86_FORMAT_TYPE_1
block|}
block|,
block|{
name|FT_SERVICE_ID_POSTSCRIPT_INFO
block|,
operator|&
name|t1_service_ps_info
block|}
block|,
ifndef|#
directive|ifndef
name|T1_CONFIG_OPTION_NO_AFM
block|{
name|FT_SERVICE_ID_KERNING
block|,
operator|&
name|t1_service_kerning
block|}
block|,
endif|#
directive|endif
ifndef|#
directive|ifndef
name|T1_CONFIG_OPTION_NO_MM_SUPPORT
block|{
name|FT_SERVICE_ID_MULTI_MASTERS
block|,
operator|&
name|t1_service_multi_masters
block|}
block|,
endif|#
directive|endif
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
DECL|function|Get_Interface
name|Get_Interface
parameter_list|(
name|FT_Driver
name|driver
parameter_list|,
specifier|const
name|FT_String
modifier|*
name|t1_interface
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
name|t1_services
argument_list|,
name|t1_interface
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|T1_CONFIG_OPTION_NO_AFM
end_ifndef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    Get_Kerning                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A driver method used to return the kerning vector between two      */
end_comment
begin_comment
comment|/*    glyphs of the same face.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face        :: A handle to the source face object.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    left_glyph  :: The index of the left glyph in the kern pair.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    right_glyph :: The index of the right glyph in the kern pair.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    kerning     :: The kerning vector.  This is in font units for      */
end_comment
begin_comment
comment|/*                   scalable formats, and in pixels for fixed-sizes     */
end_comment
begin_comment
comment|/*                   formats.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0 means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Only horizontal layouts (left-to-right& right-to-left) are        */
end_comment
begin_comment
comment|/*    supported by this function.  Other layouts, or more sophisticated  */
end_comment
begin_comment
comment|/*    kernings are out of scope of this method (the basic driver         */
end_comment
begin_comment
comment|/*    interface is meant to be simple).                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    They can be implemented by format-specific interfaces.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|Get_Kerning
name|Get_Kerning
parameter_list|(
name|T1_Face
name|face
parameter_list|,
name|FT_UInt
name|left_glyph
parameter_list|,
name|FT_UInt
name|right_glyph
parameter_list|,
name|FT_Vector
modifier|*
name|kerning
parameter_list|)
block|{
name|kerning
operator|->
name|x
operator|=
literal|0
expr_stmt|;
name|kerning
operator|->
name|y
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|face
operator|->
name|afm_data
condition|)
name|T1_Get_Kerning
argument_list|(
operator|(
name|AFM_FontInfo
operator|)
name|face
operator|->
name|afm_data
argument_list|,
name|left_glyph
argument_list|,
name|right_glyph
argument_list|,
name|kerning
argument_list|)
expr_stmt|;
return|return
name|T1_Err_Ok
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* T1_CONFIG_OPTION_NO_AFM */
end_comment
begin_decl_stmt
name|FT_CALLBACK_TABLE_DEF
DECL|variable|t1_driver_class
specifier|const
name|FT_Driver_ClassRec
name|t1_driver_class
init|=
block|{
block|{
name|FT_MODULE_FONT_DRIVER
operator||
name|FT_MODULE_DRIVER_SCALABLE
operator||
name|FT_MODULE_DRIVER_HAS_HINTER
block|,
sizeof|sizeof
argument_list|(
name|FT_DriverRec
argument_list|)
block|,
literal|"type1"
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
name|T1_Driver_Init
block|,
operator|(
name|FT_Module_Destructor
operator|)
name|T1_Driver_Done
block|,
operator|(
name|FT_Module_Requester
operator|)
name|Get_Interface
block|,     }
block|,
sizeof|sizeof
argument_list|(
name|T1_FaceRec
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|T1_SizeRec
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|T1_GlyphSlotRec
argument_list|)
block|,
operator|(
name|FT_Face_InitFunc
operator|)
name|T1_Face_Init
block|,
operator|(
name|FT_Face_DoneFunc
operator|)
name|T1_Face_Done
block|,
operator|(
name|FT_Size_InitFunc
operator|)
name|T1_Size_Init
block|,
operator|(
name|FT_Size_DoneFunc
operator|)
name|T1_Size_Done
block|,
operator|(
name|FT_Slot_InitFunc
operator|)
name|T1_GlyphSlot_Init
block|,
operator|(
name|FT_Slot_DoneFunc
operator|)
name|T1_GlyphSlot_Done
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
name|T1_Load_Glyph
block|,
ifdef|#
directive|ifdef
name|T1_CONFIG_OPTION_NO_AFM
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
else|#
directive|else
operator|(
name|FT_Face_GetKerningFunc
operator|)
name|Get_Kerning
block|,
operator|(
name|FT_Face_AttachFunc
operator|)
name|T1_Read_Metrics
block|,
endif|#
directive|endif
operator|(
name|FT_Face_GetAdvancesFunc
operator|)
name|T1_Get_Advances
block|,
operator|(
name|FT_Size_RequestFunc
operator|)
name|T1_Size_Request
block|,
operator|(
name|FT_Size_SelectFunc
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* END */
end_comment
end_unit
