begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  gxvprop.c                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueTypeGX/AAT prop table validation (body).                         */
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
value|trace_gxvprop
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
DECL|macro|GXV_PROP_HEADER_SIZE
define|#
directive|define
name|GXV_PROP_HEADER_SIZE
value|( 4 + 2 + 2 )
end_define
begin_define
DECL|macro|GXV_PROP_SIZE_MIN
define|#
directive|define
name|GXV_PROP_SIZE_MIN
value|GXV_PROP_HEADER_SIZE
end_define
begin_typedef
DECL|struct|GXV_prop_DataRec_
typedef|typedef
struct|struct
name|GXV_prop_DataRec_
block|{
DECL|member|version
name|FT_Fixed
name|version
decl_stmt|;
block|}
DECL|typedef|GXV_prop_DataRec
DECL|typedef|GXV_prop_Data
name|GXV_prop_DataRec
operator|,
typedef|*
name|GXV_prop_Data
typedef|;
end_typedef
begin_define
DECL|macro|GXV_PROP_DATA
define|#
directive|define
name|GXV_PROP_DATA
parameter_list|(
name|field
parameter_list|)
value|GXV_TABLE_DATA( prop, field )
end_define
begin_define
DECL|macro|GXV_PROP_FLOATER
define|#
directive|define
name|GXV_PROP_FLOATER
value|0x8000U
end_define
begin_define
DECL|macro|GXV_PROP_USE_COMPLEMENTARY_BRACKET
define|#
directive|define
name|GXV_PROP_USE_COMPLEMENTARY_BRACKET
value|0x1000U
end_define
begin_define
DECL|macro|GXV_PROP_COMPLEMENTARY_BRACKET_OFFSET
define|#
directive|define
name|GXV_PROP_COMPLEMENTARY_BRACKET_OFFSET
value|0x0F00U
end_define
begin_define
DECL|macro|GXV_PROP_ATTACHING_TO_RIGHT
define|#
directive|define
name|GXV_PROP_ATTACHING_TO_RIGHT
value|0x0080U
end_define
begin_define
DECL|macro|GXV_PROP_RESERVED
define|#
directive|define
name|GXV_PROP_RESERVED
value|0x0060U
end_define
begin_define
DECL|macro|GXV_PROP_DIRECTIONALITY_CLASS
define|#
directive|define
name|GXV_PROP_DIRECTIONALITY_CLASS
value|0x001FU
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
DECL|function|gxv_prop_zero_advance_validate
name|gxv_prop_zero_advance_validate
parameter_list|(
name|FT_UShort
name|gid
parameter_list|,
name|GXV_Validator
name|gxvalid
parameter_list|)
block|{
name|FT_Face
name|face
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
name|FT_GlyphSlot
name|glyph
decl_stmt|;
name|GXV_NAME_ENTER
argument_list|(
literal|"zero advance"
argument_list|)
expr_stmt|;
name|face
operator|=
name|gxvalid
operator|->
name|face
expr_stmt|;
name|error
operator|=
name|FT_Load_Glyph
argument_list|(
name|face
argument_list|,
name|gid
argument_list|,
name|FT_LOAD_IGNORE_TRANSFORM
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
name|FT_INVALID_GLYPH_ID
expr_stmt|;
name|glyph
operator|=
name|face
operator|->
name|glyph
expr_stmt|;
if|if
condition|(
name|glyph
operator|->
name|advance
operator|.
name|x
operator|!=
operator|(
name|FT_Pos
operator|)
literal|0
operator|||
name|glyph
operator|->
name|advance
operator|.
name|y
operator|!=
operator|(
name|FT_Pos
operator|)
literal|0
condition|)
block|{
name|GXV_TRACE
argument_list|(
operator|(
literal|"  found non-zero advance in zero-advance glyph\n"
operator|)
argument_list|)
expr_stmt|;
name|FT_INVALID_DATA
expr_stmt|;
block|}
name|GXV_EXIT
expr_stmt|;
block|}
end_function
begin_comment
comment|/* Pass 0 as GLYPH to check the default property */
end_comment
begin_function
specifier|static
name|void
DECL|function|gxv_prop_property_validate
name|gxv_prop_property_validate
parameter_list|(
name|FT_UShort
name|property
parameter_list|,
name|FT_UShort
name|glyph
parameter_list|,
name|GXV_Validator
name|gxvalid
parameter_list|)
block|{
if|if
condition|(
name|glyph
operator|!=
literal|0
operator|&&
operator|(
name|property
operator|&
name|GXV_PROP_FLOATER
operator|)
condition|)
name|gxv_prop_zero_advance_validate
argument_list|(
name|glyph
argument_list|,
name|gxvalid
argument_list|)
expr_stmt|;
if|if
condition|(
name|property
operator|&
name|GXV_PROP_USE_COMPLEMENTARY_BRACKET
condition|)
block|{
name|FT_UShort
name|offset
decl_stmt|;
name|char
name|complement
decl_stmt|;
name|offset
operator|=
call|(
name|FT_UShort
call|)
argument_list|(
name|property
operator|&
name|GXV_PROP_COMPLEMENTARY_BRACKET_OFFSET
argument_list|)
expr_stmt|;
if|if
condition|(
name|offset
operator|==
literal|0
condition|)
block|{
name|GXV_TRACE
argument_list|(
operator|(
literal|"  found zero offset to property\n"
operator|)
argument_list|)
expr_stmt|;
name|FT_INVALID_OFFSET
expr_stmt|;
block|}
name|complement
operator|=
call|(
name|char
call|)
argument_list|(
name|offset
operator|>>
literal|8
argument_list|)
expr_stmt|;
if|if
condition|(
name|complement
operator|&
literal|0x08
condition|)
block|{
comment|/* Top bit is set: negative */
comment|/* Calculate the absolute offset */
name|complement
operator|=
call|(
name|char
call|)
argument_list|(
operator|(
name|complement
operator|&
literal|0x07
operator|)
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|/* The gid for complement must be greater than 0 */
if|if
condition|(
name|glyph
operator|<=
name|complement
condition|)
block|{
name|GXV_TRACE
argument_list|(
operator|(
literal|"  found non-positive glyph complement\n"
operator|)
argument_list|)
expr_stmt|;
name|FT_INVALID_DATA
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* The gid for complement must be the face. */
name|gxv_glyphid_validate
argument_list|(
call|(
name|FT_UShort
call|)
argument_list|(
name|glyph
operator|+
name|complement
argument_list|)
argument_list|,
name|gxvalid
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|property
operator|&
name|GXV_PROP_COMPLEMENTARY_BRACKET_OFFSET
condition|)
name|GXV_TRACE
argument_list|(
operator|(
literal|"glyph %d cannot have complementary bracketing\n"
operator|,
name|glyph
operator|)
argument_list|)
expr_stmt|;
block|}
comment|/* this is introduced in version 2.0 */
if|if
condition|(
name|property
operator|&
name|GXV_PROP_ATTACHING_TO_RIGHT
condition|)
block|{
if|if
condition|(
name|GXV_PROP_DATA
argument_list|(
name|version
argument_list|)
operator|==
literal|0x00010000UL
condition|)
block|{
name|GXV_TRACE
argument_list|(
operator|(
literal|"  found older version (1.0) in new version table\n"
operator|)
argument_list|)
expr_stmt|;
name|FT_INVALID_DATA
expr_stmt|;
block|}
block|}
if|if
condition|(
name|property
operator|&
name|GXV_PROP_RESERVED
condition|)
block|{
name|GXV_TRACE
argument_list|(
operator|(
literal|"  found non-zero bits in reserved bits\n"
operator|)
argument_list|)
expr_stmt|;
name|FT_INVALID_DATA
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|property
operator|&
name|GXV_PROP_DIRECTIONALITY_CLASS
operator|)
operator|>
literal|11
condition|)
block|{
comment|/* TODO: Too restricted. Use the validation level. */
if|if
condition|(
name|GXV_PROP_DATA
argument_list|(
name|version
argument_list|)
operator|==
literal|0x00010000UL
operator|||
name|GXV_PROP_DATA
argument_list|(
name|version
argument_list|)
operator|==
literal|0x00020000UL
condition|)
block|{
name|GXV_TRACE
argument_list|(
operator|(
literal|"  found too old version in directionality class\n"
operator|)
argument_list|)
expr_stmt|;
name|FT_INVALID_DATA
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|gxv_prop_LookupValue_validate
name|gxv_prop_LookupValue_validate
parameter_list|(
name|FT_UShort
name|glyph
parameter_list|,
name|GXV_LookupValueCPtr
name|value_p
parameter_list|,
name|GXV_Validator
name|gxvalid
parameter_list|)
block|{
name|gxv_prop_property_validate
argument_list|(
name|value_p
operator|->
name|u
argument_list|,
name|glyph
argument_list|,
name|gxvalid
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     +===============+ --------+     | lookup header |         |     +===============+         |     | BinSrchHeader |         |     +===============+         |     | lastGlyph[0]  |         |     +---------------+         |     | firstGlyph[0] |         |    head of lookup table     +---------------+         |             +     | offset[0]     |    ->   |          offset            [byte]     +===============+         |             +     | lastGlyph[1]  |         | (glyphID - firstGlyph) * 2 [byte]     +---------------+         |     | firstGlyph[1] |         |     +---------------+         |     | offset[1]     |         |     +===============+         |                               |      ...                      |                               |     16bit value array         |     +===============+         |     |     value     |<-------+     ...   */
end_comment
begin_function
specifier|static
name|GXV_LookupValueDesc
DECL|function|gxv_prop_LookupFmt4_transit
name|gxv_prop_LookupFmt4_transit
parameter_list|(
name|FT_UShort
name|relative_gindex
parameter_list|,
name|GXV_LookupValueCPtr
name|base_value_p
parameter_list|,
name|FT_Bytes
name|lookuptbl_limit
parameter_list|,
name|GXV_Validator
name|gxvalid
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
comment|/* XXX: check range? */
name|offset
operator|=
call|(
name|FT_UShort
call|)
argument_list|(
name|base_value_p
operator|->
name|u
operator|+
name|relative_gindex
operator|*
sizeof|sizeof
argument_list|(
name|FT_UShort
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|=
name|gxvalid
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
comment|/*****                         prop TABLE                            *****/
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
DECL|function|gxv_prop_validate
name|gxv_prop_validate
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
name|GXV_ValidatorRec
name|gxvalidrec
decl_stmt|;
name|GXV_Validator
name|gxvalid
init|=
operator|&
name|gxvalidrec
decl_stmt|;
name|GXV_prop_DataRec
name|proprec
decl_stmt|;
name|GXV_prop_Data
name|prop
init|=
operator|&
name|proprec
decl_stmt|;
name|FT_Fixed
name|version
decl_stmt|;
name|FT_UShort
name|format
decl_stmt|;
name|FT_UShort
name|defaultProp
decl_stmt|;
name|gxvalid
operator|->
name|root
operator|=
name|ftvalid
expr_stmt|;
name|gxvalid
operator|->
name|table_data
operator|=
name|prop
expr_stmt|;
name|gxvalid
operator|->
name|face
operator|=
name|face
expr_stmt|;
name|FT_TRACE3
argument_list|(
operator|(
literal|"validating `prop' table\n"
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
name|defaultProp
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|GXV_TRACE
argument_list|(
operator|(
literal|"  version 0x%08x\n"
operator|,
name|version
operator|)
argument_list|)
expr_stmt|;
name|GXV_TRACE
argument_list|(
operator|(
literal|"  format  0x%04x\n"
operator|,
name|format
operator|)
argument_list|)
expr_stmt|;
name|GXV_TRACE
argument_list|(
operator|(
literal|"  defaultProp  0x%04x\n"
operator|,
name|defaultProp
operator|)
argument_list|)
expr_stmt|;
comment|/* only versions 1.0, 2.0, 3.0 are defined (1996) */
if|if
condition|(
name|version
operator|!=
literal|0x00010000UL
operator|&&
name|version
operator|!=
literal|0x00020000UL
operator|&&
name|version
operator|!=
literal|0x00030000UL
condition|)
block|{
name|GXV_TRACE
argument_list|(
operator|(
literal|"  found unknown version\n"
operator|)
argument_list|)
expr_stmt|;
name|FT_INVALID_FORMAT
expr_stmt|;
block|}
comment|/* only formats 0x0000, 0x0001 are defined (1996) */
if|if
condition|(
name|format
operator|>
literal|1
condition|)
block|{
name|GXV_TRACE
argument_list|(
operator|(
literal|"  found unknown format\n"
operator|)
argument_list|)
expr_stmt|;
name|FT_INVALID_FORMAT
expr_stmt|;
block|}
name|gxv_prop_property_validate
argument_list|(
name|defaultProp
argument_list|,
literal|0
argument_list|,
name|gxvalid
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|==
literal|0
condition|)
block|{
name|FT_TRACE3
argument_list|(
operator|(
literal|"(format 0, no per-glyph properties, "
literal|"remaining %d bytes are skipped)"
operator|,
name|limit
operator|-
name|p
operator|)
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
comment|/* format == 1 */
name|GXV_PROP_DATA
argument_list|(
name|version
argument_list|)
operator|=
name|version
expr_stmt|;
name|gxvalid
operator|->
name|lookupval_sign
operator|=
name|GXV_LOOKUPVALUE_UNSIGNED
expr_stmt|;
name|gxvalid
operator|->
name|lookupval_func
operator|=
name|gxv_prop_LookupValue_validate
expr_stmt|;
name|gxvalid
operator|->
name|lookupfmt4_trans
operator|=
name|gxv_prop_LookupFmt4_transit
expr_stmt|;
name|gxv_LookupTable_validate
argument_list|(
name|p
argument_list|,
name|limit
argument_list|,
name|gxvalid
argument_list|)
expr_stmt|;
name|Exit
label|:
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
comment|/* END */
end_comment
end_unit
