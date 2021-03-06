begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ttpic.c                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType position independent code services for truetype module. */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2009-2015 by                                                 */
end_comment
begin_comment
comment|/*  Oran Agra and Mickey Gabel.                                            */
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
include|FT_FREETYPE_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
file|"ttpic.h"
end_include
begin_include
include|#
directive|include
file|"tterrors.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_PIC
end_ifdef
begin_comment
comment|/* forward declaration of PIC init functions from ttdriver.c */
end_comment
begin_function_decl
name|FT_Error
name|FT_Create_Class_tt_services
parameter_list|(
name|FT_Library
name|library
parameter_list|,
name|FT_ServiceDescRec
modifier|*
modifier|*
name|output_class
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|FT_Destroy_Class_tt_services
parameter_list|(
name|FT_Library
name|library
parameter_list|,
name|FT_ServiceDescRec
modifier|*
name|clazz
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|FT_Init_Class_tt_service_gx_multi_masters
parameter_list|(
name|FT_Service_MultiMastersRec
modifier|*
name|sv_mm
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|FT_Init_Class_tt_service_truetype_glyf
parameter_list|(
name|FT_Service_TTGlyfRec
modifier|*
name|sv_ttglyf
parameter_list|)
function_decl|;
end_function_decl
begin_function
name|void
DECL|function|tt_driver_class_pic_free
name|tt_driver_class_pic_free
parameter_list|(
name|FT_Library
name|library
parameter_list|)
block|{
name|FT_PIC_Container
modifier|*
name|pic_container
init|=
operator|&
name|library
operator|->
name|pic_container
decl_stmt|;
name|FT_Memory
name|memory
init|=
name|library
operator|->
name|memory
decl_stmt|;
if|if
condition|(
name|pic_container
operator|->
name|truetype
condition|)
block|{
name|TTModulePIC
modifier|*
name|container
init|=
operator|(
name|TTModulePIC
operator|*
operator|)
name|pic_container
operator|->
name|truetype
decl_stmt|;
if|if
condition|(
name|container
operator|->
name|tt_services
condition|)
name|FT_Destroy_Class_tt_services
argument_list|(
name|library
argument_list|,
name|container
operator|->
name|tt_services
argument_list|)
expr_stmt|;
name|container
operator|->
name|tt_services
operator|=
name|NULL
expr_stmt|;
name|FT_FREE
argument_list|(
name|container
argument_list|)
expr_stmt|;
name|pic_container
operator|->
name|truetype
operator|=
name|NULL
expr_stmt|;
block|}
block|}
end_function
begin_function
name|FT_Error
DECL|function|tt_driver_class_pic_init
name|tt_driver_class_pic_init
parameter_list|(
name|FT_Library
name|library
parameter_list|)
block|{
name|FT_PIC_Container
modifier|*
name|pic_container
init|=
operator|&
name|library
operator|->
name|pic_container
decl_stmt|;
name|FT_Error
name|error
init|=
name|FT_Err_Ok
decl_stmt|;
name|TTModulePIC
modifier|*
name|container
init|=
name|NULL
decl_stmt|;
name|FT_Memory
name|memory
init|=
name|library
operator|->
name|memory
decl_stmt|;
comment|/* allocate pointer, clear and set global container pointer */
if|if
condition|(
name|FT_ALLOC
argument_list|(
name|container
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|container
argument_list|)
argument_list|)
condition|)
return|return
name|error
return|;
name|FT_MEM_SET
argument_list|(
name|container
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|container
argument_list|)
argument_list|)
expr_stmt|;
name|pic_container
operator|->
name|truetype
operator|=
name|container
expr_stmt|;
comment|/* initialize pointer table - this is how the module usually */
comment|/* expects this data                                         */
name|error
operator|=
name|FT_Create_Class_tt_services
argument_list|(
name|library
argument_list|,
operator|&
name|container
operator|->
name|tt_services
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_GX_VAR_SUPPORT
name|FT_Init_Class_tt_service_gx_multi_masters
argument_list|(
operator|&
name|container
operator|->
name|tt_service_gx_multi_masters
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|FT_Init_Class_tt_service_truetype_glyf
argument_list|(
operator|&
name|container
operator|->
name|tt_service_truetype_glyf
argument_list|)
expr_stmt|;
name|Exit
label|:
if|if
condition|(
name|error
condition|)
name|tt_driver_class_pic_free
argument_list|(
name|library
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
