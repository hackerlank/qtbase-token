begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  otvgsub.c                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    OpenType GSUB table validation (body).                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004, 2005, 2007 by                                          */
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
file|"otvalid.h"
end_include
begin_include
include|#
directive|include
file|"otvcommn.h"
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
value|trace_otvgsub
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
comment|/*****                  GSUB LOOKUP TYPE 1                           *****/
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
begin_comment
comment|/* uses otvalid->glyph_count */
end_comment
begin_function
specifier|static
name|void
DECL|function|otv_SingleSubst_validate
name|otv_SingleSubst_validate
parameter_list|(
name|FT_Bytes
name|table
parameter_list|,
name|OTV_Validator
name|otvalid
parameter_list|)
block|{
name|FT_Bytes
name|p
init|=
name|table
decl_stmt|;
name|FT_UInt
name|SubstFormat
decl_stmt|;
name|OTV_NAME_ENTER
argument_list|(
literal|"SingleSubst"
argument_list|)
expr_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|SubstFormat
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|OTV_TRACE
argument_list|(
operator|(
literal|" (format %d)\n"
operator|,
name|SubstFormat
operator|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|SubstFormat
condition|)
block|{
case|case
literal|1
case|:
comment|/* SingleSubstFormat1 */
block|{
name|FT_Bytes
name|Coverage
decl_stmt|;
name|FT_Int
name|DeltaGlyphID
decl_stmt|;
name|FT_Long
name|idx
decl_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|Coverage
operator|=
name|table
operator|+
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|DeltaGlyphID
operator|=
name|FT_NEXT_SHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|otv_Coverage_validate
argument_list|(
name|Coverage
argument_list|,
name|otvalid
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|idx
operator|=
name|otv_Coverage_get_first
argument_list|(
name|Coverage
argument_list|)
operator|+
name|DeltaGlyphID
expr_stmt|;
if|if
condition|(
name|idx
operator|<
literal|0
condition|)
name|FT_INVALID_DATA
expr_stmt|;
name|idx
operator|=
name|otv_Coverage_get_last
argument_list|(
name|Coverage
argument_list|)
operator|+
name|DeltaGlyphID
expr_stmt|;
if|if
condition|(
operator|(
name|FT_UInt
operator|)
name|idx
operator|>=
name|otvalid
operator|->
name|glyph_count
condition|)
name|FT_INVALID_DATA
expr_stmt|;
block|}
break|break;
case|case
literal|2
case|:
comment|/* SingleSubstFormat2 */
block|{
name|FT_UInt
name|Coverage
decl_stmt|,
name|GlyphCount
decl_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|Coverage
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|GlyphCount
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|OTV_TRACE
argument_list|(
operator|(
literal|" (GlyphCount = %d)\n"
operator|,
name|GlyphCount
operator|)
argument_list|)
expr_stmt|;
name|otv_Coverage_validate
argument_list|(
name|table
operator|+
name|Coverage
argument_list|,
name|otvalid
argument_list|,
name|GlyphCount
argument_list|)
expr_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
name|GlyphCount
operator|*
literal|2
argument_list|)
expr_stmt|;
comment|/* Substitute */
for|for
control|(
init|;
name|GlyphCount
operator|>
literal|0
condition|;
name|GlyphCount
operator|--
control|)
if|if
condition|(
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
operator|>=
name|otvalid
operator|->
name|glyph_count
condition|)
name|FT_INVALID_GLYPH_ID
expr_stmt|;
block|}
break|break;
default|default:
name|FT_INVALID_FORMAT
expr_stmt|;
block|}
name|OTV_EXIT
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
comment|/*****                  GSUB LOOKUP TYPE 2                           *****/
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
begin_comment
comment|/* sets otvalid->extra1 (glyph count) */
end_comment
begin_function
specifier|static
name|void
DECL|function|otv_MultipleSubst_validate
name|otv_MultipleSubst_validate
parameter_list|(
name|FT_Bytes
name|table
parameter_list|,
name|OTV_Validator
name|otvalid
parameter_list|)
block|{
name|FT_Bytes
name|p
init|=
name|table
decl_stmt|;
name|FT_UInt
name|SubstFormat
decl_stmt|;
name|OTV_NAME_ENTER
argument_list|(
literal|"MultipleSubst"
argument_list|)
expr_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|SubstFormat
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|OTV_TRACE
argument_list|(
operator|(
literal|" (format %d)\n"
operator|,
name|SubstFormat
operator|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|SubstFormat
condition|)
block|{
case|case
literal|1
case|:
name|otvalid
operator|->
name|extra1
operator|=
name|otvalid
operator|->
name|glyph_count
expr_stmt|;
name|OTV_NEST2
argument_list|(
name|MultipleSubstFormat1
argument_list|,
name|Sequence
argument_list|)
expr_stmt|;
name|OTV_RUN
argument_list|(
name|table
argument_list|,
name|otvalid
argument_list|)
expr_stmt|;
break|break;
default|default:
name|FT_INVALID_FORMAT
expr_stmt|;
block|}
name|OTV_EXIT
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
comment|/*****                    GSUB LOOKUP TYPE 3                         *****/
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
begin_comment
comment|/* sets otvalid->extra1 (glyph count) */
end_comment
begin_function
specifier|static
name|void
DECL|function|otv_AlternateSubst_validate
name|otv_AlternateSubst_validate
parameter_list|(
name|FT_Bytes
name|table
parameter_list|,
name|OTV_Validator
name|otvalid
parameter_list|)
block|{
name|FT_Bytes
name|p
init|=
name|table
decl_stmt|;
name|FT_UInt
name|SubstFormat
decl_stmt|;
name|OTV_NAME_ENTER
argument_list|(
literal|"AlternateSubst"
argument_list|)
expr_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|SubstFormat
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|OTV_TRACE
argument_list|(
operator|(
literal|" (format %d)\n"
operator|,
name|SubstFormat
operator|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|SubstFormat
condition|)
block|{
case|case
literal|1
case|:
name|otvalid
operator|->
name|extra1
operator|=
name|otvalid
operator|->
name|glyph_count
expr_stmt|;
name|OTV_NEST2
argument_list|(
name|AlternateSubstFormat1
argument_list|,
name|AlternateSet
argument_list|)
expr_stmt|;
name|OTV_RUN
argument_list|(
name|table
argument_list|,
name|otvalid
argument_list|)
expr_stmt|;
break|break;
default|default:
name|FT_INVALID_FORMAT
expr_stmt|;
block|}
name|OTV_EXIT
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
comment|/*****                    GSUB LOOKUP TYPE 4                         *****/
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
DECL|macro|LigatureFunc
define|#
directive|define
name|LigatureFunc
value|otv_Ligature_validate
end_define
begin_comment
comment|/* uses otvalid->glyph_count */
end_comment
begin_function
specifier|static
name|void
DECL|function|otv_Ligature_validate
name|otv_Ligature_validate
parameter_list|(
name|FT_Bytes
name|table
parameter_list|,
name|OTV_Validator
name|otvalid
parameter_list|)
block|{
name|FT_Bytes
name|p
init|=
name|table
decl_stmt|;
name|FT_UInt
name|LigatureGlyph
decl_stmt|,
name|CompCount
decl_stmt|;
name|OTV_ENTER
expr_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|LigatureGlyph
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|LigatureGlyph
operator|>=
name|otvalid
operator|->
name|glyph_count
condition|)
name|FT_INVALID_DATA
expr_stmt|;
name|CompCount
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|OTV_TRACE
argument_list|(
operator|(
literal|" (CompCount = %d)\n"
operator|,
name|CompCount
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|CompCount
operator|==
literal|0
condition|)
name|FT_INVALID_DATA
expr_stmt|;
name|CompCount
operator|--
expr_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
name|CompCount
operator|*
literal|2
argument_list|)
expr_stmt|;
comment|/* Component */
comment|/* no need to check the Component glyph indices */
name|OTV_EXIT
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|otv_LigatureSubst_validate
name|otv_LigatureSubst_validate
parameter_list|(
name|FT_Bytes
name|table
parameter_list|,
name|OTV_Validator
name|otvalid
parameter_list|)
block|{
name|FT_Bytes
name|p
init|=
name|table
decl_stmt|;
name|FT_UInt
name|SubstFormat
decl_stmt|;
name|OTV_NAME_ENTER
argument_list|(
literal|"LigatureSubst"
argument_list|)
expr_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|SubstFormat
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|OTV_TRACE
argument_list|(
operator|(
literal|" (format %d)\n"
operator|,
name|SubstFormat
operator|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|SubstFormat
condition|)
block|{
case|case
literal|1
case|:
name|OTV_NEST3
argument_list|(
name|LigatureSubstFormat1
argument_list|,
name|LigatureSet
argument_list|,
name|Ligature
argument_list|)
expr_stmt|;
name|OTV_RUN
argument_list|(
name|table
argument_list|,
name|otvalid
argument_list|)
expr_stmt|;
break|break;
default|default:
name|FT_INVALID_FORMAT
expr_stmt|;
block|}
name|OTV_EXIT
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
comment|/*****                  GSUB LOOKUP TYPE 5                           *****/
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
begin_comment
comment|/* sets otvalid->extra1 (lookup count) */
end_comment
begin_function
specifier|static
name|void
DECL|function|otv_ContextSubst_validate
name|otv_ContextSubst_validate
parameter_list|(
name|FT_Bytes
name|table
parameter_list|,
name|OTV_Validator
name|otvalid
parameter_list|)
block|{
name|FT_Bytes
name|p
init|=
name|table
decl_stmt|;
name|FT_UInt
name|SubstFormat
decl_stmt|;
name|OTV_NAME_ENTER
argument_list|(
literal|"ContextSubst"
argument_list|)
expr_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|SubstFormat
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|OTV_TRACE
argument_list|(
operator|(
literal|" (format %d)\n"
operator|,
name|SubstFormat
operator|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|SubstFormat
condition|)
block|{
case|case
literal|1
case|:
comment|/* no need to check glyph indices/classes used as input for these */
comment|/* context rules since even invalid glyph indices/classes return  */
comment|/* meaningful results                                             */
name|otvalid
operator|->
name|extra1
operator|=
name|otvalid
operator|->
name|lookup_count
expr_stmt|;
name|OTV_NEST3
argument_list|(
name|ContextSubstFormat1
argument_list|,
name|SubRuleSet
argument_list|,
name|SubRule
argument_list|)
expr_stmt|;
name|OTV_RUN
argument_list|(
name|table
argument_list|,
name|otvalid
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
comment|/* no need to check glyph indices/classes used as input for these */
comment|/* context rules since even invalid glyph indices/classes return  */
comment|/* meaningful results                                             */
name|OTV_NEST3
argument_list|(
name|ContextSubstFormat2
argument_list|,
name|SubClassSet
argument_list|,
name|SubClassRule
argument_list|)
expr_stmt|;
name|OTV_RUN
argument_list|(
name|table
argument_list|,
name|otvalid
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|OTV_NEST1
argument_list|(
name|ContextSubstFormat3
argument_list|)
expr_stmt|;
name|OTV_RUN
argument_list|(
name|table
argument_list|,
name|otvalid
argument_list|)
expr_stmt|;
break|break;
default|default:
name|FT_INVALID_FORMAT
expr_stmt|;
block|}
name|OTV_EXIT
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
comment|/*****                    GSUB LOOKUP TYPE 6                         *****/
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
begin_comment
comment|/* sets otvalid->extra1 (lookup count)            */
end_comment
begin_function
specifier|static
name|void
DECL|function|otv_ChainContextSubst_validate
name|otv_ChainContextSubst_validate
parameter_list|(
name|FT_Bytes
name|table
parameter_list|,
name|OTV_Validator
name|otvalid
parameter_list|)
block|{
name|FT_Bytes
name|p
init|=
name|table
decl_stmt|;
name|FT_UInt
name|SubstFormat
decl_stmt|;
name|OTV_NAME_ENTER
argument_list|(
literal|"ChainContextSubst"
argument_list|)
expr_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|SubstFormat
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|OTV_TRACE
argument_list|(
operator|(
literal|" (format %d)\n"
operator|,
name|SubstFormat
operator|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|SubstFormat
condition|)
block|{
case|case
literal|1
case|:
comment|/* no need to check glyph indices/classes used as input for these */
comment|/* context rules since even invalid glyph indices/classes return  */
comment|/* meaningful results                                             */
name|otvalid
operator|->
name|extra1
operator|=
name|otvalid
operator|->
name|lookup_count
expr_stmt|;
name|OTV_NEST3
argument_list|(
name|ChainContextSubstFormat1
argument_list|,
name|ChainSubRuleSet
argument_list|,
name|ChainSubRule
argument_list|)
expr_stmt|;
name|OTV_RUN
argument_list|(
name|table
argument_list|,
name|otvalid
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
comment|/* no need to check glyph indices/classes used as input for these */
comment|/* context rules since even invalid glyph indices/classes return  */
comment|/* meaningful results                                             */
name|OTV_NEST3
argument_list|(
name|ChainContextSubstFormat2
argument_list|,
name|ChainSubClassSet
argument_list|,
name|ChainSubClassRule
argument_list|)
expr_stmt|;
name|OTV_RUN
argument_list|(
name|table
argument_list|,
name|otvalid
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|OTV_NEST1
argument_list|(
name|ChainContextSubstFormat3
argument_list|)
expr_stmt|;
name|OTV_RUN
argument_list|(
name|table
argument_list|,
name|otvalid
argument_list|)
expr_stmt|;
break|break;
default|default:
name|FT_INVALID_FORMAT
expr_stmt|;
block|}
name|OTV_EXIT
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
comment|/*****                    GSUB LOOKUP TYPE 7                         *****/
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
begin_comment
comment|/* uses otvalid->type_funcs */
end_comment
begin_function
specifier|static
name|void
DECL|function|otv_ExtensionSubst_validate
name|otv_ExtensionSubst_validate
parameter_list|(
name|FT_Bytes
name|table
parameter_list|,
name|OTV_Validator
name|otvalid
parameter_list|)
block|{
name|FT_Bytes
name|p
init|=
name|table
decl_stmt|;
name|FT_UInt
name|SubstFormat
decl_stmt|;
name|OTV_NAME_ENTER
argument_list|(
literal|"ExtensionSubst"
argument_list|)
expr_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|SubstFormat
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|OTV_TRACE
argument_list|(
operator|(
literal|" (format %d)\n"
operator|,
name|SubstFormat
operator|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|SubstFormat
condition|)
block|{
case|case
literal|1
case|:
comment|/* ExtensionSubstFormat1 */
block|{
name|FT_UInt
name|ExtensionLookupType
decl_stmt|;
name|FT_ULong
name|ExtensionOffset
decl_stmt|;
name|OTV_Validate_Func
name|validate
decl_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|ExtensionLookupType
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|ExtensionOffset
operator|=
name|FT_NEXT_ULONG
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|ExtensionLookupType
operator|==
literal|0
operator|||
name|ExtensionLookupType
operator|==
literal|7
operator|||
name|ExtensionLookupType
operator|>
literal|8
condition|)
name|FT_INVALID_DATA
expr_stmt|;
name|validate
operator|=
name|otvalid
operator|->
name|type_funcs
index|[
name|ExtensionLookupType
operator|-
literal|1
index|]
expr_stmt|;
name|validate
argument_list|(
name|table
operator|+
name|ExtensionOffset
argument_list|,
name|otvalid
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
name|FT_INVALID_FORMAT
expr_stmt|;
block|}
name|OTV_EXIT
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
comment|/*****                    GSUB LOOKUP TYPE 8                         *****/
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
begin_comment
comment|/* uses otvalid->glyph_count */
end_comment
begin_function
specifier|static
name|void
DECL|function|otv_ReverseChainSingleSubst_validate
name|otv_ReverseChainSingleSubst_validate
parameter_list|(
name|FT_Bytes
name|table
parameter_list|,
name|OTV_Validator
name|otvalid
parameter_list|)
block|{
name|FT_Bytes
name|p
init|=
name|table
decl_stmt|,
name|Coverage
decl_stmt|;
name|FT_UInt
name|SubstFormat
decl_stmt|;
name|FT_UInt
name|BacktrackGlyphCount
decl_stmt|,
name|LookaheadGlyphCount
decl_stmt|,
name|GlyphCount
decl_stmt|;
name|OTV_NAME_ENTER
argument_list|(
literal|"ReverseChainSingleSubst"
argument_list|)
expr_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|SubstFormat
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|OTV_TRACE
argument_list|(
operator|(
literal|" (format %d)\n"
operator|,
name|SubstFormat
operator|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|SubstFormat
condition|)
block|{
case|case
literal|1
case|:
comment|/* ReverseChainSingleSubstFormat1 */
name|OTV_LIMIT_CHECK
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|Coverage
operator|=
name|table
operator|+
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|BacktrackGlyphCount
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|OTV_TRACE
argument_list|(
operator|(
literal|" (BacktrackGlyphCount = %d)\n"
operator|,
name|BacktrackGlyphCount
operator|)
argument_list|)
expr_stmt|;
name|otv_Coverage_validate
argument_list|(
name|Coverage
argument_list|,
name|otvalid
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
name|BacktrackGlyphCount
operator|*
literal|2
operator|+
literal|2
argument_list|)
expr_stmt|;
for|for
control|(
init|;
name|BacktrackGlyphCount
operator|>
literal|0
condition|;
name|BacktrackGlyphCount
operator|--
control|)
name|otv_Coverage_validate
argument_list|(
name|table
operator|+
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
argument_list|,
name|otvalid
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|LookaheadGlyphCount
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|OTV_TRACE
argument_list|(
operator|(
literal|" (LookaheadGlyphCount = %d)\n"
operator|,
name|LookaheadGlyphCount
operator|)
argument_list|)
expr_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
name|LookaheadGlyphCount
operator|*
literal|2
operator|+
literal|2
argument_list|)
expr_stmt|;
for|for
control|(
init|;
name|LookaheadGlyphCount
operator|>
literal|0
condition|;
name|LookaheadGlyphCount
operator|--
control|)
name|otv_Coverage_validate
argument_list|(
name|table
operator|+
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
argument_list|,
name|otvalid
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|GlyphCount
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|OTV_TRACE
argument_list|(
operator|(
literal|" (GlyphCount = %d)\n"
operator|,
name|GlyphCount
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|GlyphCount
operator|!=
name|otv_Coverage_get_count
argument_list|(
name|Coverage
argument_list|)
condition|)
name|FT_INVALID_DATA
expr_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
name|GlyphCount
operator|*
literal|2
argument_list|)
expr_stmt|;
comment|/* Substitute */
for|for
control|(
init|;
name|GlyphCount
operator|>
literal|0
condition|;
name|GlyphCount
operator|--
control|)
if|if
condition|(
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
operator|>=
name|otvalid
operator|->
name|glyph_count
condition|)
name|FT_INVALID_DATA
expr_stmt|;
break|break;
default|default:
name|FT_INVALID_FORMAT
expr_stmt|;
block|}
name|OTV_EXIT
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|otv_gsub_validate_funcs
specifier|static
specifier|const
name|OTV_Validate_Func
name|otv_gsub_validate_funcs
index|[
literal|8
index|]
init|=
block|{
name|otv_SingleSubst_validate
block|,
name|otv_MultipleSubst_validate
block|,
name|otv_AlternateSubst_validate
block|,
name|otv_LigatureSubst_validate
block|,
name|otv_ContextSubst_validate
block|,
name|otv_ChainContextSubst_validate
block|,
name|otv_ExtensionSubst_validate
block|,
name|otv_ReverseChainSingleSubst_validate
block|}
decl_stmt|;
end_decl_stmt
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
comment|/*****                          GSUB TABLE                           *****/
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
begin_comment
comment|/* sets otvalid->type_count  */
end_comment
begin_comment
comment|/* sets otvalid->type_funcs  */
end_comment
begin_comment
comment|/* sets otvalid->glyph_count */
end_comment
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|otv_GSUB_validate
name|otv_GSUB_validate
argument_list|(
argument|FT_Bytes      table
argument_list|,
argument|FT_UInt       glyph_count
argument_list|,
argument|FT_Validator  ftvalid
argument_list|)
end_macro
begin_block
block|{
name|OTV_ValidatorRec
name|otvalidrec
decl_stmt|;
name|OTV_Validator
name|otvalid
init|=
operator|&
name|otvalidrec
decl_stmt|;
name|FT_Bytes
name|p
init|=
name|table
decl_stmt|;
name|FT_UInt
name|ScriptList
decl_stmt|,
name|FeatureList
decl_stmt|,
name|LookupList
decl_stmt|;
name|otvalid
operator|->
name|root
operator|=
name|ftvalid
expr_stmt|;
name|FT_TRACE3
argument_list|(
operator|(
literal|"validating GSUB table\n"
operator|)
argument_list|)
expr_stmt|;
name|OTV_INIT
expr_stmt|;
name|OTV_LIMIT_CHECK
argument_list|(
literal|10
argument_list|)
expr_stmt|;
if|if
condition|(
name|FT_NEXT_ULONG
argument_list|(
name|p
argument_list|)
operator|!=
literal|0x10000UL
condition|)
comment|/* Version */
name|FT_INVALID_FORMAT
expr_stmt|;
name|ScriptList
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|FeatureList
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|LookupList
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|otvalid
operator|->
name|type_count
operator|=
literal|8
expr_stmt|;
name|otvalid
operator|->
name|type_funcs
operator|=
operator|(
name|OTV_Validate_Func
operator|*
operator|)
name|otv_gsub_validate_funcs
expr_stmt|;
name|otvalid
operator|->
name|glyph_count
operator|=
name|glyph_count
expr_stmt|;
name|otv_LookupList_validate
argument_list|(
name|table
operator|+
name|LookupList
argument_list|,
name|otvalid
argument_list|)
expr_stmt|;
name|otv_FeatureList_validate
argument_list|(
name|table
operator|+
name|FeatureList
argument_list|,
name|table
operator|+
name|LookupList
argument_list|,
name|otvalid
argument_list|)
expr_stmt|;
name|otv_ScriptList_validate
argument_list|(
name|table
operator|+
name|ScriptList
argument_list|,
name|table
operator|+
name|FeatureList
argument_list|,
name|otvalid
argument_list|)
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
comment|/* END */
end_comment
end_unit
