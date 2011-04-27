begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  gxvbsln.c                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueTypeGX/AAT bsln table validation (body).                         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004, 2005 by suzuki toshiya, Masatake YAMATO, Red Hat K.K., */
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
file|"gxvalid.h"
end_include
begin_include
include|#
directive|include
file|"gxvcommn.h"
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
value|trace_gxvbsln
end_define
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
comment|/*****                      Data and Types                           *****/
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
begin_define
DECL|macro|GXV_BSLN_VALUE_COUNT
define|#
directive|define
name|GXV_BSLN_VALUE_COUNT
value|32
end_define
begin_define
DECL|macro|GXV_BSLN_VALUE_EMPTY
define|#
directive|define
name|GXV_BSLN_VALUE_EMPTY
value|0xFFFFU
end_define
begin_typedef
DECL|struct|GXV_bsln_DataRec_
typedef|typedef
struct|struct
name|GXV_bsln_DataRec_
block|{
DECL|member|ctlPoints_p
name|FT_Bytes
name|ctlPoints_p
decl_stmt|;
DECL|member|defaultBaseline
name|FT_UShort
name|defaultBaseline
decl_stmt|;
block|}
DECL|typedef|GXV_bsln_DataRec
DECL|typedef|GXV_bsln_Data
name|GXV_bsln_DataRec
operator|,
typedef|*
name|GXV_bsln_Data
typedef|;
end_typedef
begin_define
DECL|macro|GXV_BSLN_DATA
define|#
directive|define
name|GXV_BSLN_DATA
parameter_list|(
name|field
parameter_list|)
value|GXV_TABLE_DATA( bsln, field )
end_define
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
comment|/*****                      UTILITY FUNCTIONS                        *****/
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
begin_function
specifier|static
name|void
DECL|function|gxv_bsln_LookupValue_validate
name|gxv_bsln_LookupValue_validate
parameter_list|(
name|FT_UShort
name|glyph
parameter_list|,
name|GXV_LookupValueDesc
name|value
parameter_list|,
name|GXV_Validator
name|valid
parameter_list|)
block|{
name|FT_UShort
name|v
init|=
name|value
operator|.
name|u
decl_stmt|;
name|FT_UShort
modifier|*
name|ctlPoints
decl_stmt|;
name|FT_UNUSED
argument_list|(
name|glyph
argument_list|)
expr_stmt|;
name|GXV_NAME_ENTER
argument_list|(
literal|"lookup value"
argument_list|)
expr_stmt|;
if|if
condition|(
name|v
operator|>=
name|GXV_BSLN_VALUE_COUNT
condition|)
name|FT_INVALID_DATA
expr_stmt|;
name|ctlPoints
operator|=
operator|(
name|FT_UShort
operator|*
operator|)
name|GXV_BSLN_DATA
argument_list|(
name|ctlPoints_p
argument_list|)
expr_stmt|;
if|if
condition|(
name|ctlPoints
operator|&&
name|ctlPoints
index|[
name|v
index|]
operator|==
name|GXV_BSLN_VALUE_EMPTY
condition|)
name|FT_INVALID_DATA
expr_stmt|;
name|GXV_EXIT
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     +===============+ --------+     | lookup header |         |     +===============+         |     | BinSrchHeader |         |     +===============+         |     | lastGlyph[0]  |         |     +---------------+         |     | firstGlyph[0] |         |    head of lookup table     +---------------+         |             +     | offset[0]     |    ->   |          offset            [byte]     +===============+         |             +     | lastGlyph[1]  |         | (glyphID - firstGlyph) * 2 [byte]     +---------------+         |     | firstGlyph[1] |         |     +---------------+         |     | offset[1]     |         |     +===============+         |                               |     ...                       |                               |     16bit value array         |     +===============+         |     |     value     |<-------+     ...   */
end_comment
begin_function
specifier|static
name|GXV_LookupValueDesc
DECL|function|gxv_bsln_LookupFmt4_transit
name|gxv_bsln_LookupFmt4_transit
parameter_list|(
name|FT_UShort
name|relative_gindex
parameter_list|,
name|GXV_LookupValueDesc
name|base_value
parameter_list|,
name|FT_Bytes
name|lookuptbl_limit
parameter_list|,
name|GXV_Validator
name|valid
parameter_list|)
block|{
name|FT_Bytes
name|p
decl_stmt|;
name|FT_Bytes
name|limit
decl_stmt|;
name|FT_UShort
name|offset
decl_stmt|;
name|GXV_LookupValueDesc
name|value
decl_stmt|;
comment|/* XXX: check range ? */
name|offset
operator|=
call|(
name|FT_UShort
call|)
argument_list|(
name|base_value
operator|.
name|u
operator|+
operator|(
name|relative_gindex
operator|*
sizeof|sizeof
argument_list|(
name|FT_UShort
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|p
operator|=
name|valid
operator|->
name|lookuptbl_head
operator|+
name|offset
expr_stmt|;
name|limit
operator|=
name|lookuptbl_limit
expr_stmt|;
name|GXV_LIMIT_CHECK
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|value
operator|.
name|u
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
name|value
return|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|gxv_bsln_parts_fmt0_validate
name|gxv_bsln_parts_fmt0_validate
parameter_list|(
name|FT_Bytes
name|tables
parameter_list|,
name|FT_Bytes
name|limit
parameter_list|,
name|GXV_Validator
name|valid
parameter_list|)
block|{
name|FT_Bytes
name|p
init|=
name|tables
decl_stmt|;
name|GXV_NAME_ENTER
argument_list|(
literal|"parts format 0"
argument_list|)
expr_stmt|;
comment|/* deltas */
name|GXV_LIMIT_CHECK
argument_list|(
literal|2
operator|*
name|GXV_BSLN_VALUE_COUNT
argument_list|)
expr_stmt|;
name|valid
operator|->
name|table_data
operator|=
name|NULL
expr_stmt|;
comment|/* No ctlPoints here. */
name|GXV_EXIT
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|gxv_bsln_parts_fmt1_validate
name|gxv_bsln_parts_fmt1_validate
parameter_list|(
name|FT_Bytes
name|tables
parameter_list|,
name|FT_Bytes
name|limit
parameter_list|,
name|GXV_Validator
name|valid
parameter_list|)
block|{
name|FT_Bytes
name|p
init|=
name|tables
decl_stmt|;
name|GXV_NAME_ENTER
argument_list|(
literal|"parts format 1"
argument_list|)
expr_stmt|;
comment|/* deltas */
name|gxv_bsln_parts_fmt0_validate
argument_list|(
name|p
argument_list|,
name|limit
argument_list|,
name|valid
argument_list|)
expr_stmt|;
comment|/* mappingData */
name|valid
operator|->
name|lookupval_sign
operator|=
name|GXV_LOOKUPVALUE_UNSIGNED
expr_stmt|;
name|valid
operator|->
name|lookupval_func
operator|=
name|gxv_bsln_LookupValue_validate
expr_stmt|;
name|valid
operator|->
name|lookupfmt4_trans
operator|=
name|gxv_bsln_LookupFmt4_transit
expr_stmt|;
name|gxv_LookupTable_validate
argument_list|(
name|p
operator|+
literal|2
operator|*
name|GXV_BSLN_VALUE_COUNT
argument_list|,
name|limit
argument_list|,
name|valid
argument_list|)
expr_stmt|;
name|GXV_EXIT
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|gxv_bsln_parts_fmt2_validate
name|gxv_bsln_parts_fmt2_validate
parameter_list|(
name|FT_Bytes
name|tables
parameter_list|,
name|FT_Bytes
name|limit
parameter_list|,
name|GXV_Validator
name|valid
parameter_list|)
block|{
name|FT_Bytes
name|p
init|=
name|tables
decl_stmt|;
name|FT_UShort
name|stdGlyph
decl_stmt|;
name|FT_UShort
name|ctlPoint
decl_stmt|;
name|FT_Int
name|i
decl_stmt|;
name|FT_UShort
name|defaultBaseline
init|=
name|GXV_BSLN_DATA
argument_list|(
name|defaultBaseline
argument_list|)
decl_stmt|;
name|GXV_NAME_ENTER
argument_list|(
literal|"parts format 2"
argument_list|)
expr_stmt|;
name|GXV_LIMIT_CHECK
argument_list|(
literal|2
operator|+
operator|(
literal|2
operator|*
name|GXV_BSLN_VALUE_COUNT
operator|)
argument_list|)
expr_stmt|;
comment|/* stdGlyph */
name|stdGlyph
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|GXV_TRACE
argument_list|(
operator|(
literal|" (stdGlyph = %u)\n"
operator|,
name|stdGlyph
operator|)
argument_list|)
expr_stmt|;
name|gxv_glyphid_validate
argument_list|(
name|stdGlyph
argument_list|,
name|valid
argument_list|)
expr_stmt|;
comment|/* Record the position of ctlPoints */
name|GXV_BSLN_DATA
argument_list|(
name|ctlPoints_p
argument_list|)
operator|=
name|p
expr_stmt|;
comment|/* ctlPoints */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|GXV_BSLN_VALUE_COUNT
condition|;
name|i
operator|++
control|)
block|{
name|ctlPoint
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|ctlPoint
operator|==
name|GXV_BSLN_VALUE_EMPTY
condition|)
block|{
if|if
condition|(
name|i
operator|==
name|defaultBaseline
condition|)
name|FT_INVALID_DATA
expr_stmt|;
block|}
else|else
name|gxv_ctlPoint_validate
argument_list|(
name|stdGlyph
argument_list|,
operator|(
name|FT_Short
operator|)
name|ctlPoint
argument_list|,
name|valid
argument_list|)
expr_stmt|;
block|}
name|GXV_EXIT
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|gxv_bsln_parts_fmt3_validate
name|gxv_bsln_parts_fmt3_validate
parameter_list|(
name|FT_Bytes
name|tables
parameter_list|,
name|FT_Bytes
name|limit
parameter_list|,
name|GXV_Validator
name|valid
parameter_list|)
block|{
name|FT_Bytes
name|p
init|=
name|tables
decl_stmt|;
name|GXV_NAME_ENTER
argument_list|(
literal|"parts format 3"
argument_list|)
expr_stmt|;
comment|/* stdGlyph + ctlPoints */
name|gxv_bsln_parts_fmt2_validate
argument_list|(
name|p
argument_list|,
name|limit
argument_list|,
name|valid
argument_list|)
expr_stmt|;
comment|/* mappingData */
name|valid
operator|->
name|lookupval_sign
operator|=
name|GXV_LOOKUPVALUE_UNSIGNED
expr_stmt|;
name|valid
operator|->
name|lookupval_func
operator|=
name|gxv_bsln_LookupValue_validate
expr_stmt|;
name|valid
operator|->
name|lookupfmt4_trans
operator|=
name|gxv_bsln_LookupFmt4_transit
expr_stmt|;
name|gxv_LookupTable_validate
argument_list|(
name|p
operator|+
operator|(
literal|2
operator|+
literal|2
operator|*
name|GXV_BSLN_VALUE_COUNT
operator|)
argument_list|,
name|limit
argument_list|,
name|valid
argument_list|)
expr_stmt|;
name|GXV_EXIT
expr_stmt|;
block|}
end_function
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
comment|/*****                         bsln TABLE                            *****/
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
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|gxv_bsln_validate
name|gxv_bsln_validate
argument_list|(
argument|FT_Bytes      table
argument_list|,
argument|FT_Face       face
argument_list|,
argument|FT_Validator  ftvalid
argument_list|)
end_macro
begin_block
block|{
name|GXV_ValidatorRec
name|validrec
decl_stmt|;
name|GXV_Validator
name|valid
init|=
operator|&
name|validrec
decl_stmt|;
name|GXV_bsln_DataRec
name|bslnrec
decl_stmt|;
name|GXV_bsln_Data
name|bsln
init|=
operator|&
name|bslnrec
decl_stmt|;
name|FT_Bytes
name|p
init|=
name|table
decl_stmt|;
name|FT_Bytes
name|limit
init|=
literal|0
decl_stmt|;
name|FT_ULong
name|version
decl_stmt|;
name|FT_UShort
name|format
decl_stmt|;
name|FT_UShort
name|defaultBaseline
decl_stmt|;
name|GXV_Validate_Func
name|fmt_funcs_table
index|[]
init|=
block|{
name|gxv_bsln_parts_fmt0_validate
block|,
name|gxv_bsln_parts_fmt1_validate
block|,
name|gxv_bsln_parts_fmt2_validate
block|,
name|gxv_bsln_parts_fmt3_validate
block|,     }
decl_stmt|;
name|valid
operator|->
name|root
operator|=
name|ftvalid
expr_stmt|;
name|valid
operator|->
name|table_data
operator|=
name|bsln
expr_stmt|;
name|valid
operator|->
name|face
operator|=
name|face
expr_stmt|;
name|FT_TRACE3
argument_list|(
operator|(
literal|"validating `bsln' table\n"
operator|)
argument_list|)
expr_stmt|;
name|GXV_INIT
expr_stmt|;
name|GXV_LIMIT_CHECK
argument_list|(
literal|4
operator|+
literal|2
operator|+
literal|2
argument_list|)
expr_stmt|;
name|version
operator|=
name|FT_NEXT_ULONG
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|format
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|defaultBaseline
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* only version 1.0 is defined (1996) */
if|if
condition|(
name|version
operator|!=
literal|0x00010000UL
condition|)
name|FT_INVALID_FORMAT
expr_stmt|;
comment|/* only format 1, 2, 3 are defined (1996) */
name|GXV_TRACE
argument_list|(
operator|(
literal|" (format = %d)\n"
operator|,
name|format
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|>
literal|3
condition|)
name|FT_INVALID_FORMAT
expr_stmt|;
if|if
condition|(
name|defaultBaseline
operator|>
literal|31
condition|)
name|FT_INVALID_FORMAT
expr_stmt|;
name|bsln
operator|->
name|defaultBaseline
operator|=
name|defaultBaseline
expr_stmt|;
name|fmt_funcs_table
index|[
name|format
index|]
operator|(
name|p
operator|,
name|limit
operator|,
name|valid
operator|)
expr_stmt|;
name|FT_TRACE4
argument_list|(
operator|(
literal|"\n"
operator|)
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/* arch-tag: ebe81143-fdaa-4c68-a4d1-b57227daa3bc    (do not change this comment) */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
