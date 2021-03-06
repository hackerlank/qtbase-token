begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  gxvmorx0.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueTypeGX/AAT morx table validation                                 */
end_comment
begin_comment
comment|/*    body for type0 (Indic Script Rearrangement) subtable.                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2005-2015 by                                                 */
end_comment
begin_comment
comment|/*  suzuki toshiya, Masatake YAMATO, Red Hat K.K.,                         */
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
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/* gxvalid is derived from both gxlayout module and otvalid module.        */
end_comment
begin_comment
comment|/* Development of gxlayout is supported by the Information-technology      */
end_comment
begin_comment
comment|/* Promotion Agency(IPA), Japan.                                           */
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
file|"gxvmorx.h"
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
value|trace_gxvmorx
end_define
begin_function
specifier|static
name|void
DECL|function|gxv_morx_subtable_type0_entry_validate
name|gxv_morx_subtable_type0_entry_validate
parameter_list|(
name|FT_UShort
name|state
parameter_list|,
name|FT_UShort
name|flags
parameter_list|,
name|GXV_XStateTable_GlyphOffsetCPtr
name|glyphOffset_p
parameter_list|,
name|FT_Bytes
name|table
parameter_list|,
name|FT_Bytes
name|limit
parameter_list|,
name|GXV_Validator
name|gxvalid
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|GXV_LOAD_UNUSED_VARS
name|FT_UShort
name|markFirst
decl_stmt|;
name|FT_UShort
name|dontAdvance
decl_stmt|;
name|FT_UShort
name|markLast
decl_stmt|;
endif|#
directive|endif
name|FT_UShort
name|reserved
decl_stmt|;
ifdef|#
directive|ifdef
name|GXV_LOAD_UNUSED_VARS
name|FT_UShort
name|verb
decl_stmt|;
endif|#
directive|endif
name|FT_UNUSED
argument_list|(
name|state
argument_list|)
expr_stmt|;
name|FT_UNUSED
argument_list|(
name|glyphOffset_p
argument_list|)
expr_stmt|;
name|FT_UNUSED
argument_list|(
name|table
argument_list|)
expr_stmt|;
name|FT_UNUSED
argument_list|(
name|limit
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|GXV_LOAD_UNUSED_VARS
name|markFirst
operator|=
call|(
name|FT_UShort
call|)
argument_list|(
operator|(
name|flags
operator|>>
literal|15
operator|)
operator|&
literal|1
argument_list|)
expr_stmt|;
name|dontAdvance
operator|=
call|(
name|FT_UShort
call|)
argument_list|(
operator|(
name|flags
operator|>>
literal|14
operator|)
operator|&
literal|1
argument_list|)
expr_stmt|;
name|markLast
operator|=
call|(
name|FT_UShort
call|)
argument_list|(
operator|(
name|flags
operator|>>
literal|13
operator|)
operator|&
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|reserved
operator|=
call|(
name|FT_UShort
call|)
argument_list|(
name|flags
operator|&
literal|0x1FF0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|GXV_LOAD_UNUSED_VARS
name|verb
operator|=
call|(
name|FT_UShort
call|)
argument_list|(
name|flags
operator|&
literal|0x000F
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
literal|0
operator|<
name|reserved
condition|)
block|{
name|GXV_TRACE
argument_list|(
operator|(
literal|" non-zero bits found in reserved range\n"
operator|)
argument_list|)
expr_stmt|;
name|FT_INVALID_DATA
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|gxv_morx_subtable_type0_validate
name|gxv_morx_subtable_type0_validate
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|GXV_Validator  gxvalid
argument_list|)
end_macro
begin_block
block|{
name|FT_Bytes
name|p
init|=
name|table
decl_stmt|;
name|GXV_NAME_ENTER
argument_list|(
literal|"morx chain subtable type0 (Indic-Script Rearrangement)"
argument_list|)
expr_stmt|;
name|GXV_LIMIT_CHECK
argument_list|(
name|GXV_STATETABLE_HEADER_SIZE
argument_list|)
expr_stmt|;
name|gxvalid
operator|->
name|xstatetable
operator|.
name|optdata
operator|=
name|NULL
expr_stmt|;
name|gxvalid
operator|->
name|xstatetable
operator|.
name|optdata_load_func
operator|=
name|NULL
expr_stmt|;
name|gxvalid
operator|->
name|xstatetable
operator|.
name|subtable_setup_func
operator|=
name|NULL
expr_stmt|;
name|gxvalid
operator|->
name|xstatetable
operator|.
name|entry_glyphoffset_fmt
operator|=
name|GXV_GLYPHOFFSET_NONE
expr_stmt|;
name|gxvalid
operator|->
name|xstatetable
operator|.
name|entry_validate_func
operator|=
name|gxv_morx_subtable_type0_entry_validate
expr_stmt|;
name|gxv_XStateTable_validate
argument_list|(
name|p
argument_list|,
name|limit
argument_list|,
name|gxvalid
argument_list|)
expr_stmt|;
name|GXV_EXIT
expr_stmt|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
