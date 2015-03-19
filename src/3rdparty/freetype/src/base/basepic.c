begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  basepic.c                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType position independent code services for base.            */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2009, 2012, 2013 by                                          */
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
file|"basepic.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_PIC
end_ifdef
begin_comment
comment|/* forward declaration of PIC init functions from ftglyph.c */
end_comment
begin_function_decl
name|void
name|FT_Init_Class_ft_outline_glyph_class
parameter_list|(
name|FT_Glyph_Class
modifier|*
name|clazz
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|FT_Init_Class_ft_bitmap_glyph_class
parameter_list|(
name|FT_Glyph_Class
modifier|*
name|clazz
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_MAC_FONTS
end_ifdef
begin_comment
comment|/* forward declaration of PIC init function from ftrfork.c */
end_comment
begin_comment
comment|/* (not modularized)                                       */
end_comment
begin_function_decl
name|void
name|FT_Init_Table_ft_raccess_guess_table
parameter_list|(
name|ft_raccess_guess_rec
modifier|*
name|record
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* forward declaration of PIC init functions from ftinit.c */
end_comment
begin_function_decl
name|FT_Error
name|ft_create_default_module_classes
parameter_list|(
name|FT_Library
name|library
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|ft_destroy_default_module_classes
parameter_list|(
name|FT_Library
name|library
parameter_list|)
function_decl|;
end_function_decl
begin_function
name|void
DECL|function|ft_base_pic_free
name|ft_base_pic_free
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
name|base
condition|)
block|{
comment|/* destroy default module classes            */
comment|/* (in case FT_Add_Default_Modules was used) */
name|ft_destroy_default_module_classes
argument_list|(
name|library
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|pic_container
operator|->
name|base
argument_list|)
expr_stmt|;
name|pic_container
operator|->
name|base
operator|=
name|NULL
expr_stmt|;
block|}
block|}
end_function
begin_function
name|FT_Error
DECL|function|ft_base_pic_init
name|ft_base_pic_init
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
name|BasePIC
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
name|base
operator|=
name|container
expr_stmt|;
comment|/* initialize default modules list and pointers */
name|error
operator|=
name|ft_create_default_module_classes
argument_list|(
name|library
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
comment|/* initialize pointer table -                       */
comment|/* this is how the module usually expects this data */
name|FT_Init_Class_ft_outline_glyph_class
argument_list|(
operator|&
name|container
operator|->
name|ft_outline_glyph_class
argument_list|)
expr_stmt|;
name|FT_Init_Class_ft_bitmap_glyph_class
argument_list|(
operator|&
name|container
operator|->
name|ft_bitmap_glyph_class
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_MAC_FONTS
name|FT_Init_Table_ft_raccess_guess_table
argument_list|(
operator|(
name|ft_raccess_guess_rec
operator|*
operator|)
operator|&
name|container
operator|->
name|ft_raccess_guess_table
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|Exit
label|:
if|if
condition|(
name|error
condition|)
name|ft_base_pic_free
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
