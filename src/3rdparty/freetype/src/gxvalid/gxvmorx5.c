begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  gxvmorx5.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueTypeGX/AAT morx table validation                                 */
end_comment
begin_comment
comment|/*    body for type5 (Contextual Glyph Insertion) subtable.                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2005, 2007 by suzuki toshiya, Masatake YAMATO, Red Hat K.K., */
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
begin_comment
comment|/*    * `morx' subtable type5 (Contextual Glyph Insertion)    * has format of a StateTable with insertion-glyph-list    * without name.  However, the 32bit offset from the head    * of subtable to the i-g-l is given after `entryTable',    * without variable name specification (the existence of    * this offset to the table is different from mort type5).    */
end_comment
begin_typedef
DECL|struct|GXV_morx_subtable_type5_StateOptRec_
typedef|typedef
struct|struct
name|GXV_morx_subtable_type5_StateOptRec_
block|{
DECL|member|insertionGlyphList
name|FT_ULong
name|insertionGlyphList
decl_stmt|;
DECL|member|insertionGlyphList_length
name|FT_ULong
name|insertionGlyphList_length
decl_stmt|;
block|}
DECL|typedef|GXV_morx_subtable_type5_StateOptRec
name|GXV_morx_subtable_type5_StateOptRec
operator|,
typedef|*
DECL|typedef|GXV_morx_subtable_type5_StateOptRecData
name|GXV_morx_subtable_type5_StateOptRecData
typedef|;
end_typedef
begin_define
DECL|macro|GXV_MORX_SUBTABLE_TYPE5_HEADER_SIZE
define|#
directive|define
name|GXV_MORX_SUBTABLE_TYPE5_HEADER_SIZE
define|\
value|( GXV_STATETABLE_HEADER_SIZE + 4 )
end_define
begin_function
specifier|static
name|void
DECL|function|gxv_morx_subtable_type5_insertionGlyphList_load
name|gxv_morx_subtable_type5_insertionGlyphList_load
parameter_list|(
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
name|FT_Bytes
name|p
init|=
name|table
decl_stmt|;
name|GXV_morx_subtable_type5_StateOptRecData
name|optdata
init|=
operator|(
name|GXV_morx_subtable_type5_StateOptRecData
operator|)
name|gxvalid
operator|->
name|xstatetable
operator|.
name|optdata
decl_stmt|;
name|GXV_LIMIT_CHECK
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|optdata
operator|->
name|insertionGlyphList
operator|=
name|FT_NEXT_ULONG
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|gxv_morx_subtable_type5_subtable_setup
name|gxv_morx_subtable_type5_subtable_setup
parameter_list|(
name|FT_ULong
name|table_size
parameter_list|,
name|FT_ULong
name|classTable
parameter_list|,
name|FT_ULong
name|stateArray
parameter_list|,
name|FT_ULong
name|entryTable
parameter_list|,
name|FT_ULong
modifier|*
name|classTable_length_p
parameter_list|,
name|FT_ULong
modifier|*
name|stateArray_length_p
parameter_list|,
name|FT_ULong
modifier|*
name|entryTable_length_p
parameter_list|,
name|GXV_Validator
name|gxvalid
parameter_list|)
block|{
name|FT_ULong
name|o
index|[
literal|4
index|]
decl_stmt|;
name|FT_ULong
modifier|*
name|l
index|[
literal|4
index|]
decl_stmt|;
name|FT_ULong
name|buff
index|[
literal|5
index|]
decl_stmt|;
name|GXV_morx_subtable_type5_StateOptRecData
name|optdata
init|=
operator|(
name|GXV_morx_subtable_type5_StateOptRecData
operator|)
name|gxvalid
operator|->
name|xstatetable
operator|.
name|optdata
decl_stmt|;
name|o
index|[
literal|0
index|]
operator|=
name|classTable
expr_stmt|;
name|o
index|[
literal|1
index|]
operator|=
name|stateArray
expr_stmt|;
name|o
index|[
literal|2
index|]
operator|=
name|entryTable
expr_stmt|;
name|o
index|[
literal|3
index|]
operator|=
name|optdata
operator|->
name|insertionGlyphList
expr_stmt|;
name|l
index|[
literal|0
index|]
operator|=
name|classTable_length_p
expr_stmt|;
name|l
index|[
literal|1
index|]
operator|=
name|stateArray_length_p
expr_stmt|;
name|l
index|[
literal|2
index|]
operator|=
name|entryTable_length_p
expr_stmt|;
name|l
index|[
literal|3
index|]
operator|=
operator|&
operator|(
name|optdata
operator|->
name|insertionGlyphList_length
operator|)
expr_stmt|;
name|gxv_set_length_by_ulong_offset
argument_list|(
name|o
argument_list|,
name|l
argument_list|,
name|buff
argument_list|,
literal|4
argument_list|,
name|table_size
argument_list|,
name|gxvalid
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|gxv_morx_subtable_type5_InsertList_validate
name|gxv_morx_subtable_type5_InsertList_validate
parameter_list|(
name|FT_UShort
name|table_index
parameter_list|,
name|FT_UShort
name|count
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
name|FT_Bytes
name|p
init|=
name|table
operator|+
name|table_index
operator|*
literal|2
decl_stmt|;
ifndef|#
directive|ifndef
name|GXV_LOAD_TRACE_VARS
name|GXV_LIMIT_CHECK
argument_list|(
name|count
operator|*
literal|2
argument_list|)
expr_stmt|;
else|#
directive|else
while|while
condition|(
name|p
operator|<
name|table
operator|+
name|count
operator|*
literal|2
operator|+
name|table_index
operator|*
literal|2
condition|)
block|{
name|FT_UShort
name|insert_glyphID
decl_stmt|;
name|GXV_LIMIT_CHECK
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|insert_glyphID
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|GXV_TRACE
argument_list|(
operator|(
literal|" 0x%04x"
operator|,
name|insert_glyphID
operator|)
argument_list|)
expr_stmt|;
block|}
name|GXV_TRACE
argument_list|(
operator|(
literal|"\n"
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|gxv_morx_subtable_type5_entry_validate
name|gxv_morx_subtable_type5_entry_validate
parameter_list|(
name|FT_UShort
name|state
parameter_list|,
name|FT_UShort
name|flags
parameter_list|,
name|GXV_StateTable_GlyphOffsetCPtr
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
name|FT_Bool
name|setMark
decl_stmt|;
name|FT_Bool
name|dontAdvance
decl_stmt|;
name|FT_Bool
name|currentIsKashidaLike
decl_stmt|;
name|FT_Bool
name|markedIsKashidaLike
decl_stmt|;
name|FT_Bool
name|currentInsertBefore
decl_stmt|;
name|FT_Bool
name|markedInsertBefore
decl_stmt|;
endif|#
directive|endif
name|FT_Byte
name|currentInsertCount
decl_stmt|;
name|FT_Byte
name|markedInsertCount
decl_stmt|;
name|FT_Byte
name|currentInsertList
decl_stmt|;
name|FT_UShort
name|markedInsertList
decl_stmt|;
name|FT_UNUSED
argument_list|(
name|state
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|GXV_LOAD_UNUSED_VARS
name|setMark
operator|=
name|FT_BOOL
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
name|FT_BOOL
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
name|currentIsKashidaLike
operator|=
name|FT_BOOL
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
name|markedIsKashidaLike
operator|=
name|FT_BOOL
argument_list|(
operator|(
name|flags
operator|>>
literal|12
operator|)
operator|&
literal|1
argument_list|)
expr_stmt|;
name|currentInsertBefore
operator|=
name|FT_BOOL
argument_list|(
operator|(
name|flags
operator|>>
literal|11
operator|)
operator|&
literal|1
argument_list|)
expr_stmt|;
name|markedInsertBefore
operator|=
name|FT_BOOL
argument_list|(
operator|(
name|flags
operator|>>
literal|10
operator|)
operator|&
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|currentInsertCount
operator|=
call|(
name|FT_Byte
call|)
argument_list|(
operator|(
name|flags
operator|>>
literal|5
operator|)
operator|&
literal|0x1F
argument_list|)
expr_stmt|;
name|markedInsertCount
operator|=
call|(
name|FT_Byte
call|)
argument_list|(
name|flags
operator|&
literal|0x001F
argument_list|)
expr_stmt|;
name|currentInsertList
operator|=
call|(
name|FT_Byte
call|)
argument_list|(
name|glyphOffset_p
operator|->
name|ul
operator|>>
literal|16
argument_list|)
expr_stmt|;
name|markedInsertList
operator|=
call|(
name|FT_UShort
call|)
argument_list|(
name|glyphOffset_p
operator|->
name|ul
argument_list|)
expr_stmt|;
if|if
condition|(
name|currentInsertList
operator|&&
literal|0
operator|!=
name|currentInsertCount
condition|)
name|gxv_morx_subtable_type5_InsertList_validate
argument_list|(
name|currentInsertList
argument_list|,
name|currentInsertCount
argument_list|,
name|table
argument_list|,
name|limit
argument_list|,
name|gxvalid
argument_list|)
expr_stmt|;
if|if
condition|(
name|markedInsertList
operator|&&
literal|0
operator|!=
name|markedInsertCount
condition|)
name|gxv_morx_subtable_type5_InsertList_validate
argument_list|(
name|markedInsertList
argument_list|,
name|markedInsertCount
argument_list|,
name|table
argument_list|,
name|limit
argument_list|,
name|gxvalid
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|gxv_morx_subtable_type5_validate
name|gxv_morx_subtable_type5_validate
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
name|GXV_morx_subtable_type5_StateOptRec
name|et_rec
decl_stmt|;
name|GXV_morx_subtable_type5_StateOptRecData
name|et
init|=
operator|&
name|et_rec
decl_stmt|;
name|GXV_NAME_ENTER
argument_list|(
literal|"morx chain subtable type5 (Glyph Insertion)"
argument_list|)
expr_stmt|;
name|GXV_LIMIT_CHECK
argument_list|(
name|GXV_MORX_SUBTABLE_TYPE5_HEADER_SIZE
argument_list|)
expr_stmt|;
name|gxvalid
operator|->
name|xstatetable
operator|.
name|optdata
operator|=
name|et
expr_stmt|;
name|gxvalid
operator|->
name|xstatetable
operator|.
name|optdata_load_func
operator|=
name|gxv_morx_subtable_type5_insertionGlyphList_load
expr_stmt|;
name|gxvalid
operator|->
name|xstatetable
operator|.
name|subtable_setup_func
operator|=
name|gxv_morx_subtable_type5_subtable_setup
expr_stmt|;
name|gxvalid
operator|->
name|xstatetable
operator|.
name|entry_glyphoffset_fmt
operator|=
name|GXV_GLYPHOFFSET_ULONG
expr_stmt|;
name|gxvalid
operator|->
name|xstatetable
operator|.
name|entry_validate_func
operator|=
name|gxv_morx_subtable_type5_entry_validate
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
