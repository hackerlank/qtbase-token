begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  gxvfeat.c                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueTypeGX/AAT feat table validation (body).                         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004, 2005, 2008 by                                          */
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
file|"gxvalid.h"
end_include
begin_include
include|#
directive|include
file|"gxvcommn.h"
end_include
begin_include
include|#
directive|include
file|"gxvfeat.h"
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
value|trace_gxvfeat
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
begin_typedef
DECL|struct|GXV_feat_DataRec_
typedef|typedef
struct|struct
name|GXV_feat_DataRec_
block|{
DECL|member|reserved_size
name|FT_UInt
name|reserved_size
decl_stmt|;
DECL|member|feature
name|FT_UShort
name|feature
decl_stmt|;
DECL|member|setting
name|FT_UShort
name|setting
decl_stmt|;
block|}
DECL|typedef|GXV_feat_DataRec
DECL|typedef|GXV_feat_Data
name|GXV_feat_DataRec
operator|,
typedef|*
name|GXV_feat_Data
typedef|;
end_typedef
begin_define
DECL|macro|GXV_FEAT_DATA
define|#
directive|define
name|GXV_FEAT_DATA
parameter_list|(
name|field
parameter_list|)
value|GXV_TABLE_DATA( feat, field )
end_define
begin_typedef
DECL|enum|GXV_FeatureFlagsMask_
typedef|typedef
enum|enum
name|GXV_FeatureFlagsMask_
block|{
DECL|enumerator|GXV_FEAT_MASK_EXCLUSIVE_SETTINGS
name|GXV_FEAT_MASK_EXCLUSIVE_SETTINGS
init|=
literal|0x8000U
block|,
DECL|enumerator|GXV_FEAT_MASK_DYNAMIC_DEFAULT
name|GXV_FEAT_MASK_DYNAMIC_DEFAULT
init|=
literal|0x4000
block|,
DECL|enumerator|GXV_FEAT_MASK_UNUSED
name|GXV_FEAT_MASK_UNUSED
init|=
literal|0x3F00
block|,
DECL|enumerator|GXV_FEAT_MASK_DEFAULT_SETTING
name|GXV_FEAT_MASK_DEFAULT_SETTING
init|=
literal|0x00FF
block|}
DECL|typedef|GXV_FeatureFlagsMask
name|GXV_FeatureFlagsMask
typedef|;
end_typedef
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
DECL|function|gxv_feat_registry_validate
name|gxv_feat_registry_validate
parameter_list|(
name|FT_UShort
name|feature
parameter_list|,
name|FT_UShort
name|nSettings
parameter_list|,
name|FT_Bool
name|exclusive
parameter_list|,
name|GXV_Validator
name|valid
parameter_list|)
block|{
name|GXV_NAME_ENTER
argument_list|(
literal|"feature in registry"
argument_list|)
expr_stmt|;
name|GXV_TRACE
argument_list|(
operator|(
literal|" (feature = %u)\n"
operator|,
name|feature
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|feature
operator|>=
name|gxv_feat_registry_length
condition|)
block|{
name|GXV_TRACE
argument_list|(
operator|(
literal|"feature number %d is out of range %d\n"
operator|,
name|feature
operator|,
name|gxv_feat_registry_length
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|valid
operator|->
name|root
operator|->
name|level
operator|==
name|FT_VALIDATE_PARANOID
condition|)
name|FT_INVALID_DATA
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|gxv_feat_registry
index|[
name|feature
index|]
operator|.
name|existence
operator|==
literal|0
condition|)
block|{
name|GXV_TRACE
argument_list|(
operator|(
literal|"feature number %d is in defined range but doesn't exist\n"
operator|,
name|feature
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|valid
operator|->
name|root
operator|->
name|level
operator|==
name|FT_VALIDATE_PARANOID
condition|)
name|FT_INVALID_DATA
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|gxv_feat_registry
index|[
name|feature
index|]
operator|.
name|apple_reserved
condition|)
block|{
comment|/* Don't use here. Apple is reserved. */
name|GXV_TRACE
argument_list|(
operator|(
literal|"feature number %d is reserved by Apple\n"
operator|,
name|feature
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|valid
operator|->
name|root
operator|->
name|level
operator|>=
name|FT_VALIDATE_TIGHT
condition|)
name|FT_INVALID_DATA
expr_stmt|;
block|}
if|if
condition|(
name|nSettings
operator|!=
name|gxv_feat_registry
index|[
name|feature
index|]
operator|.
name|nSettings
condition|)
block|{
name|GXV_TRACE
argument_list|(
operator|(
literal|"feature %d: nSettings %d != defined nSettings %d\n"
operator|,
name|feature
operator|,
name|nSettings
operator|,
name|gxv_feat_registry
index|[
name|feature
index|]
operator|.
name|nSettings
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|valid
operator|->
name|root
operator|->
name|level
operator|>=
name|FT_VALIDATE_TIGHT
condition|)
name|FT_INVALID_DATA
expr_stmt|;
block|}
if|if
condition|(
name|exclusive
operator|!=
name|gxv_feat_registry
index|[
name|feature
index|]
operator|.
name|exclusive
condition|)
block|{
name|GXV_TRACE
argument_list|(
operator|(
literal|"exclusive flag %d differs from predefined value\n"
operator|,
name|exclusive
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|valid
operator|->
name|root
operator|->
name|level
operator|>=
name|FT_VALIDATE_TIGHT
condition|)
name|FT_INVALID_DATA
expr_stmt|;
block|}
name|Exit
label|:
name|GXV_EXIT
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|gxv_feat_name_index_validate
name|gxv_feat_name_index_validate
parameter_list|(
name|FT_Bytes
name|table
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
name|table
decl_stmt|;
name|FT_Short
name|nameIndex
decl_stmt|;
name|GXV_NAME_ENTER
argument_list|(
literal|"nameIndex"
argument_list|)
expr_stmt|;
name|GXV_LIMIT_CHECK
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|nameIndex
operator|=
name|FT_NEXT_SHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|GXV_TRACE
argument_list|(
operator|(
literal|" (nameIndex = %d)\n"
operator|,
name|nameIndex
operator|)
argument_list|)
expr_stmt|;
name|gxv_sfntName_validate
argument_list|(
operator|(
name|FT_UShort
operator|)
name|nameIndex
argument_list|,
literal|255
argument_list|,
literal|32768U
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
DECL|function|gxv_feat_setting_validate
name|gxv_feat_setting_validate
parameter_list|(
name|FT_Bytes
name|table
parameter_list|,
name|FT_Bytes
name|limit
parameter_list|,
name|FT_Bool
name|exclusive
parameter_list|,
name|GXV_Validator
name|valid
parameter_list|)
block|{
name|FT_Bytes
name|p
init|=
name|table
decl_stmt|;
name|FT_UShort
name|setting
decl_stmt|;
name|GXV_NAME_ENTER
argument_list|(
literal|"setting"
argument_list|)
expr_stmt|;
name|GXV_LIMIT_CHECK
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|setting
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* If we have exclusive setting, the setting should be odd. */
if|if
condition|(
name|exclusive
operator|&&
operator|(
name|setting
operator|%
literal|2
operator|)
operator|==
literal|0
condition|)
name|FT_INVALID_DATA
expr_stmt|;
name|gxv_feat_name_index_validate
argument_list|(
name|p
argument_list|,
name|limit
argument_list|,
name|valid
argument_list|)
expr_stmt|;
name|GXV_FEAT_DATA
argument_list|(
name|setting
argument_list|)
operator|=
name|setting
expr_stmt|;
name|GXV_EXIT
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|gxv_feat_name_validate
name|gxv_feat_name_validate
parameter_list|(
name|FT_Bytes
name|table
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
name|table
decl_stmt|;
name|FT_UInt
name|reserved_size
init|=
name|GXV_FEAT_DATA
argument_list|(
name|reserved_size
argument_list|)
decl_stmt|;
name|FT_UShort
name|feature
decl_stmt|;
name|FT_UShort
name|nSettings
decl_stmt|;
name|FT_UInt
name|settingTable
decl_stmt|;
name|FT_UShort
name|featureFlags
decl_stmt|;
name|FT_Bool
name|exclusive
decl_stmt|;
name|FT_Int
name|last_setting
decl_stmt|;
name|FT_UInt
name|i
decl_stmt|;
name|GXV_NAME_ENTER
argument_list|(
literal|"name"
argument_list|)
expr_stmt|;
comment|/* feature + nSettings + settingTable + featureFlags */
name|GXV_LIMIT_CHECK
argument_list|(
literal|2
operator|+
literal|2
operator|+
literal|4
operator|+
literal|2
argument_list|)
expr_stmt|;
name|feature
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|GXV_FEAT_DATA
argument_list|(
name|feature
argument_list|)
operator|=
name|feature
expr_stmt|;
name|nSettings
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|settingTable
operator|=
name|FT_NEXT_ULONG
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|featureFlags
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|settingTable
operator|<
name|reserved_size
condition|)
name|FT_INVALID_OFFSET
expr_stmt|;
if|if
condition|(
name|valid
operator|->
name|root
operator|->
name|level
operator|==
name|FT_VALIDATE_PARANOID
operator|&&
operator|(
name|featureFlags
operator|&
name|GXV_FEAT_MASK_UNUSED
operator|)
operator|==
literal|0
condition|)
name|FT_INVALID_DATA
expr_stmt|;
name|exclusive
operator|=
name|FT_BOOL
argument_list|(
name|featureFlags
operator|&
name|GXV_FEAT_MASK_EXCLUSIVE_SETTINGS
argument_list|)
expr_stmt|;
if|if
condition|(
name|exclusive
condition|)
block|{
name|FT_Byte
name|dynamic_default
decl_stmt|;
if|if
condition|(
name|featureFlags
operator|&
name|GXV_FEAT_MASK_DYNAMIC_DEFAULT
condition|)
name|dynamic_default
operator|=
call|(
name|FT_Byte
call|)
argument_list|(
name|featureFlags
operator|&
name|GXV_FEAT_MASK_DEFAULT_SETTING
argument_list|)
expr_stmt|;
else|else
name|dynamic_default
operator|=
literal|0
expr_stmt|;
comment|/* If exclusive, check whether default setting is in the range. */
if|if
condition|(
operator|!
operator|(
name|dynamic_default
operator|<
name|nSettings
operator|)
condition|)
name|FT_INVALID_FORMAT
expr_stmt|;
block|}
name|gxv_feat_registry_validate
argument_list|(
name|feature
argument_list|,
name|nSettings
argument_list|,
name|exclusive
argument_list|,
name|valid
argument_list|)
expr_stmt|;
name|gxv_feat_name_index_validate
argument_list|(
name|p
argument_list|,
name|limit
argument_list|,
name|valid
argument_list|)
expr_stmt|;
name|p
operator|=
name|valid
operator|->
name|root
operator|->
name|base
operator|+
name|settingTable
expr_stmt|;
for|for
control|(
name|last_setting
operator|=
operator|-
literal|1
operator|,
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nSettings
condition|;
name|i
operator|++
control|)
block|{
name|gxv_feat_setting_validate
argument_list|(
name|p
argument_list|,
name|limit
argument_list|,
name|exclusive
argument_list|,
name|valid
argument_list|)
expr_stmt|;
if|if
condition|(
name|valid
operator|->
name|root
operator|->
name|level
operator|==
name|FT_VALIDATE_PARANOID
operator|&&
operator|(
name|FT_Int
operator|)
name|GXV_FEAT_DATA
argument_list|(
name|setting
argument_list|)
operator|<=
name|last_setting
condition|)
name|FT_INVALID_FORMAT
expr_stmt|;
name|last_setting
operator|=
operator|(
name|FT_Int
operator|)
name|GXV_FEAT_DATA
argument_list|(
name|setting
argument_list|)
expr_stmt|;
comment|/* setting + nameIndex */
name|p
operator|+=
operator|(
literal|2
operator|+
literal|2
operator|)
expr_stmt|;
block|}
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
comment|/*****                         feat TABLE                            *****/
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
DECL|function|gxv_feat_validate
name|gxv_feat_validate
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
name|GXV_feat_DataRec
name|featrec
decl_stmt|;
name|GXV_feat_Data
name|feat
init|=
operator|&
name|featrec
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
name|FT_UInt
name|featureNameCount
decl_stmt|;
name|FT_UInt
name|i
decl_stmt|;
name|FT_Int
name|last_feature
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
name|feat
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
literal|"validating `feat' table\n"
operator|)
argument_list|)
expr_stmt|;
name|GXV_INIT
expr_stmt|;
name|feat
operator|->
name|reserved_size
operator|=
literal|0
expr_stmt|;
comment|/* version + featureNameCount + none_0 + none_1  */
name|GXV_LIMIT_CHECK
argument_list|(
literal|4
operator|+
literal|2
operator|+
literal|2
operator|+
literal|4
argument_list|)
expr_stmt|;
name|feat
operator|->
name|reserved_size
operator|+=
literal|4
operator|+
literal|2
operator|+
literal|2
operator|+
literal|4
expr_stmt|;
if|if
condition|(
name|FT_NEXT_ULONG
argument_list|(
name|p
argument_list|)
operator|!=
literal|0x00010000UL
condition|)
comment|/* Version */
name|FT_INVALID_FORMAT
expr_stmt|;
name|featureNameCount
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|GXV_TRACE
argument_list|(
operator|(
literal|" (featureNameCount = %d)\n"
operator|,
name|featureNameCount
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|valid
operator|->
name|root
operator|->
name|level
operator|!=
name|FT_VALIDATE_PARANOID
condition|)
name|p
operator|+=
literal|6
expr_stmt|;
comment|/* skip (none) and (none) */
else|else
block|{
if|if
condition|(
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
operator|!=
literal|0
condition|)
name|FT_INVALID_DATA
expr_stmt|;
if|if
condition|(
name|FT_NEXT_ULONG
argument_list|(
name|p
argument_list|)
operator|!=
literal|0
condition|)
name|FT_INVALID_DATA
expr_stmt|;
block|}
name|feat
operator|->
name|reserved_size
operator|+=
name|featureNameCount
operator|*
operator|(
literal|2
operator|+
literal|2
operator|+
literal|4
operator|+
literal|2
operator|+
literal|2
operator|)
expr_stmt|;
for|for
control|(
name|last_feature
operator|=
operator|-
literal|1
operator|,
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|featureNameCount
condition|;
name|i
operator|++
control|)
block|{
name|gxv_feat_name_validate
argument_list|(
name|p
argument_list|,
name|limit
argument_list|,
name|valid
argument_list|)
expr_stmt|;
if|if
condition|(
name|valid
operator|->
name|root
operator|->
name|level
operator|==
name|FT_VALIDATE_PARANOID
operator|&&
operator|(
name|FT_Int
operator|)
name|GXV_FEAT_DATA
argument_list|(
name|feature
argument_list|)
operator|<=
name|last_feature
condition|)
name|FT_INVALID_FORMAT
expr_stmt|;
name|last_feature
operator|=
name|GXV_FEAT_DATA
argument_list|(
name|feature
argument_list|)
expr_stmt|;
name|p
operator|+=
literal|2
operator|+
literal|2
operator|+
literal|4
operator|+
literal|2
operator|+
literal|2
expr_stmt|;
block|}
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
