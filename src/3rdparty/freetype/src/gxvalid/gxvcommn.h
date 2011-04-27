begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  gxvcommn.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueTypeGX/AAT common tables validation (specification).             */
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
begin_comment
comment|/*    * keywords in variable naming    * ---------------------------    *  table: Of type FT_Bytes, pointing to the start of this table/subtable.    *  limit: Of type FT_Bytes, pointing to the end of this table/subtable,    *         including padding for alignment.    *  offset: Of type FT_UInt, the number of octets from the start to target.    *  length: Of type FT_UInt, the number of octets from the start to the    *          end in this table/subtable, including padding for alignment.    *    *  _MIN, _MAX: Should be added to the tail of macros, as INT_MIN, etc.    */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__GXVCOMMN_H__
end_ifndef
begin_define
DECL|macro|__GXVCOMMN_H__
define|#
directive|define
name|__GXVCOMMN_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
file|"gxvalid.h"
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
include|FT_SFNT_NAMES_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
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
comment|/*****                         VALIDATION                            *****/
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
DECL|typedef|GXV_Validator
typedef|typedef
name|struct
name|GXV_ValidatorRec_
modifier|*
name|GXV_Validator
typedef|;
end_typedef
begin_define
DECL|macro|DUMMY_LIMIT
define|#
directive|define
name|DUMMY_LIMIT
value|0
end_define
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|GXV_Validate_Func
modifier|*
name|GXV_Validate_Func
function_decl|)
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
function_decl|;
end_typedef
begin_comment
comment|/* ====================== LookupTable Validator ======================== */
end_comment
begin_typedef
DECL|union|GXV_LookupValueDesc_
typedef|typedef
union|union
name|GXV_LookupValueDesc_
block|{
DECL|member|u
name|FT_UShort
name|u
decl_stmt|;
DECL|member|s
name|FT_Short
name|s
decl_stmt|;
block|}
DECL|typedef|GXV_LookupValueDesc
name|GXV_LookupValueDesc
typedef|;
end_typedef
begin_typedef
DECL|enum|GXV_LookupValue_SignSpec_
typedef|typedef
enum|enum
name|GXV_LookupValue_SignSpec_
block|{
DECL|enumerator|GXV_LOOKUPVALUE_UNSIGNED
name|GXV_LOOKUPVALUE_UNSIGNED
init|=
literal|0
block|,
DECL|enumerator|GXV_LOOKUPVALUE_SIGNED
name|GXV_LOOKUPVALUE_SIGNED
block|}
DECL|typedef|GXV_LookupValue_SignSpec
name|GXV_LookupValue_SignSpec
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|GXV_Lookup_Value_Validate_Func
modifier|*
name|GXV_Lookup_Value_Validate_Func
function_decl|)
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
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|GXV_LookupValueDesc
function_decl|(
DECL|typedef|GXV_Lookup_Fmt4_Transit_Func
modifier|*
name|GXV_Lookup_Fmt4_Transit_Func
function_decl|)
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
function_decl|;
end_typedef
begin_comment
comment|/* ====================== StateTable Validator ========================= */
end_comment
begin_typedef
DECL|enum|GXV_GlyphOffset_Format_
typedef|typedef
enum|enum
name|GXV_GlyphOffset_Format_
block|{
DECL|enumerator|GXV_GLYPHOFFSET_NONE
name|GXV_GLYPHOFFSET_NONE
init|=
operator|-
literal|1
block|,
DECL|enumerator|GXV_GLYPHOFFSET_UCHAR
name|GXV_GLYPHOFFSET_UCHAR
init|=
literal|2
block|,
DECL|enumerator|GXV_GLYPHOFFSET_CHAR
name|GXV_GLYPHOFFSET_CHAR
block|,
DECL|enumerator|GXV_GLYPHOFFSET_USHORT
name|GXV_GLYPHOFFSET_USHORT
init|=
literal|4
block|,
DECL|enumerator|GXV_GLYPHOFFSET_SHORT
name|GXV_GLYPHOFFSET_SHORT
block|,
DECL|enumerator|GXV_GLYPHOFFSET_ULONG
name|GXV_GLYPHOFFSET_ULONG
init|=
literal|8
block|,
DECL|enumerator|GXV_GLYPHOFFSET_LONG
name|GXV_GLYPHOFFSET_LONG
block|}
DECL|typedef|GXV_GlyphOffset_Format
name|GXV_GlyphOffset_Format
typedef|;
end_typedef
begin_define
DECL|macro|GXV_GLYPHOFFSET_FMT
define|#
directive|define
name|GXV_GLYPHOFFSET_FMT
parameter_list|(
name|table
parameter_list|)
define|\
value|( valid->table.entry_glyphoffset_fmt )
end_define
begin_define
DECL|macro|GXV_GLYPHOFFSET_SIZE
define|#
directive|define
name|GXV_GLYPHOFFSET_SIZE
parameter_list|(
name|table
parameter_list|)
define|\
value|( valid->table.entry_glyphoffset_fmt / 2 )
end_define
begin_comment
comment|/* ----------------------- 16bit StateTable ---------------------------- */
end_comment
begin_typedef
DECL|union|GXV_StateTable_GlyphOffsetDesc_
typedef|typedef
union|union
name|GXV_StateTable_GlyphOffsetDesc_
block|{
DECL|member|uc
name|FT_Byte
name|uc
decl_stmt|;
DECL|member|u
name|FT_UShort
name|u
decl_stmt|;
comment|/* same as GXV_LookupValueDesc */
DECL|member|ul
name|FT_ULong
name|ul
decl_stmt|;
DECL|member|c
name|FT_Char
name|c
decl_stmt|;
DECL|member|s
name|FT_Short
name|s
decl_stmt|;
comment|/* same as GXV_LookupValueDesc */
DECL|member|l
name|FT_Long
name|l
decl_stmt|;
block|}
DECL|typedef|GXV_StateTable_GlyphOffsetDesc
name|GXV_StateTable_GlyphOffsetDesc
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|GXV_StateTable_Subtable_Setup_Func
modifier|*
name|GXV_StateTable_Subtable_Setup_Func
function_decl|)
parameter_list|(
name|FT_UShort
name|table_size
parameter_list|,
name|FT_UShort
name|classTable
parameter_list|,
name|FT_UShort
name|stateArray
parameter_list|,
name|FT_UShort
name|entryTable
parameter_list|,
name|FT_UShort
modifier|*
name|classTable_length_p
parameter_list|,
name|FT_UShort
modifier|*
name|stateArray_length_p
parameter_list|,
name|FT_UShort
modifier|*
name|entryTable_length_p
parameter_list|,
name|GXV_Validator
name|valid
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|GXV_StateTable_Entry_Validate_Func
modifier|*
name|GXV_StateTable_Entry_Validate_Func
function_decl|)
parameter_list|(
name|FT_Byte
name|state
parameter_list|,
name|FT_UShort
name|flags
parameter_list|,
name|GXV_StateTable_GlyphOffsetDesc
name|glyphOffset
parameter_list|,
name|FT_Bytes
name|statetable_table
parameter_list|,
name|FT_Bytes
name|statetable_limit
parameter_list|,
name|GXV_Validator
name|valid
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|GXV_StateTable_OptData_Load_Func
modifier|*
name|GXV_StateTable_OptData_Load_Func
function_decl|)
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
function_decl|;
end_typedef
begin_typedef
DECL|struct|GXV_StateTable_ValidatorRec_
typedef|typedef
struct|struct
name|GXV_StateTable_ValidatorRec_
block|{
DECL|member|entry_glyphoffset_fmt
name|GXV_GlyphOffset_Format
name|entry_glyphoffset_fmt
decl_stmt|;
DECL|member|optdata
name|void
modifier|*
name|optdata
decl_stmt|;
DECL|member|subtable_setup_func
name|GXV_StateTable_Subtable_Setup_Func
name|subtable_setup_func
decl_stmt|;
DECL|member|entry_validate_func
name|GXV_StateTable_Entry_Validate_Func
name|entry_validate_func
decl_stmt|;
DECL|member|optdata_load_func
name|GXV_StateTable_OptData_Load_Func
name|optdata_load_func
decl_stmt|;
block|}
DECL|typedef|GXV_StateTable_ValidatorRec
DECL|typedef|GXV_StateTable_ValidatorRecData
name|GXV_StateTable_ValidatorRec
operator|,
typedef|*
name|GXV_StateTable_ValidatorRecData
typedef|;
end_typedef
begin_comment
comment|/* ---------------------- 32bit XStateTable ---------------------------- */
end_comment
begin_typedef
DECL|typedef|GXV_XStateTable_GlyphOffsetDesc
typedef|typedef
name|GXV_StateTable_GlyphOffsetDesc
name|GXV_XStateTable_GlyphOffsetDesc
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|GXV_XStateTable_Subtable_Setup_Func
modifier|*
name|GXV_XStateTable_Subtable_Setup_Func
function_decl|)
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
name|valid
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|GXV_XStateTable_Entry_Validate_Func
modifier|*
name|GXV_XStateTable_Entry_Validate_Func
function_decl|)
parameter_list|(
name|FT_UShort
name|state
parameter_list|,
name|FT_UShort
name|flags
parameter_list|,
name|GXV_StateTable_GlyphOffsetDesc
name|glyphOffset
parameter_list|,
name|FT_Bytes
name|xstatetable_table
parameter_list|,
name|FT_Bytes
name|xstatetable_limit
parameter_list|,
name|GXV_Validator
name|valid
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|GXV_XStateTable_OptData_Load_Func
typedef|typedef
name|GXV_StateTable_OptData_Load_Func
name|GXV_XStateTable_OptData_Load_Func
typedef|;
end_typedef
begin_typedef
DECL|struct|GXV_XStateTable_ValidatorRec_
typedef|typedef
struct|struct
name|GXV_XStateTable_ValidatorRec_
block|{
DECL|member|entry_glyphoffset_fmt
name|int
name|entry_glyphoffset_fmt
decl_stmt|;
DECL|member|optdata
name|void
modifier|*
name|optdata
decl_stmt|;
DECL|member|subtable_setup_func
name|GXV_XStateTable_Subtable_Setup_Func
name|subtable_setup_func
decl_stmt|;
DECL|member|entry_validate_func
name|GXV_XStateTable_Entry_Validate_Func
name|entry_validate_func
decl_stmt|;
DECL|member|optdata_load_func
name|GXV_XStateTable_OptData_Load_Func
name|optdata_load_func
decl_stmt|;
DECL|member|nClasses
name|FT_ULong
name|nClasses
decl_stmt|;
DECL|member|maxClassID
name|FT_UShort
name|maxClassID
decl_stmt|;
block|}
DECL|typedef|GXV_XStateTable_ValidatorRec
DECL|typedef|GXV_XStateTable_ValidatorRecData
name|GXV_XStateTable_ValidatorRec
operator|,
typedef|*
name|GXV_XStateTable_ValidatorRecData
typedef|;
end_typedef
begin_comment
comment|/* ===================================================================== */
end_comment
begin_typedef
DECL|struct|GXV_ValidatorRec_
typedef|typedef
struct|struct
name|GXV_ValidatorRec_
block|{
DECL|member|root
name|FT_Validator
name|root
decl_stmt|;
DECL|member|face
name|FT_Face
name|face
decl_stmt|;
DECL|member|table_data
name|void
modifier|*
name|table_data
decl_stmt|;
DECL|member|subtable_length
name|FT_ULong
name|subtable_length
decl_stmt|;
DECL|member|lookupval_sign
name|GXV_LookupValue_SignSpec
name|lookupval_sign
decl_stmt|;
DECL|member|lookupval_func
name|GXV_Lookup_Value_Validate_Func
name|lookupval_func
decl_stmt|;
DECL|member|lookupfmt4_trans
name|GXV_Lookup_Fmt4_Transit_Func
name|lookupfmt4_trans
decl_stmt|;
DECL|member|lookuptbl_head
name|FT_Bytes
name|lookuptbl_head
decl_stmt|;
DECL|member|statetable
name|GXV_StateTable_ValidatorRec
name|statetable
decl_stmt|;
DECL|member|xstatetable
name|GXV_XStateTable_ValidatorRec
name|xstatetable
decl_stmt|;
ifdef|#
directive|ifdef
name|FT_DEBUG_LEVEL_TRACE
DECL|member|debug_indent
name|FT_UInt
name|debug_indent
decl_stmt|;
DECL|member|debug_function_name
specifier|const
name|FT_String
modifier|*
name|debug_function_name
index|[
literal|3
index|]
decl_stmt|;
endif|#
directive|endif
block|}
DECL|typedef|GXV_ValidatorRec
name|GXV_ValidatorRec
typedef|;
end_typedef
begin_define
DECL|macro|GXV_TABLE_DATA
define|#
directive|define
name|GXV_TABLE_DATA
parameter_list|(
name|tag
parameter_list|,
name|field
parameter_list|)
define|\
value|( ( (GXV_ ## tag ## _Data)valid->table_data )->field )
end_define
begin_undef
DECL|macro|FT_INVALID_
undef|#
directive|undef
name|FT_INVALID_
end_undef
begin_define
DECL|macro|FT_INVALID_
define|#
directive|define
name|FT_INVALID_
parameter_list|(
name|_prefix
parameter_list|,
name|_error
parameter_list|)
define|\
value|ft_validator_error( valid->root, _prefix ## _error )
end_define
begin_define
DECL|macro|GXV_LIMIT_CHECK
define|#
directive|define
name|GXV_LIMIT_CHECK
parameter_list|(
name|_count
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                              \             if ( p + _count> ( limit? limit : valid->root->limit ) ) \               FT_INVALID_TOO_SHORT;                                   \           FT_END_STMNT
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|FT_DEBUG_LEVEL_TRACE
end_ifdef
begin_define
DECL|macro|GXV_INIT
define|#
directive|define
name|GXV_INIT
value|valid->debug_indent = 0
end_define
begin_define
DECL|macro|GXV_NAME_ENTER
define|#
directive|define
name|GXV_NAME_ENTER
parameter_list|(
name|name
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                   \             valid->debug_indent += 2;                      \             FT_TRACE4(( "%*.s", valid->debug_indent, 0 )); \             FT_TRACE4(( "%s table\n", name ));             \           FT_END_STMNT
end_define
begin_define
DECL|macro|GXV_EXIT
define|#
directive|define
name|GXV_EXIT
value|valid->debug_indent -= 2
end_define
begin_define
DECL|macro|GXV_TRACE
define|#
directive|define
name|GXV_TRACE
parameter_list|(
name|s
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                   \             FT_TRACE4(( "%*.s", valid->debug_indent, 0 )); \             FT_TRACE4( s );                                \           FT_END_STMNT
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !FT_DEBUG_LEVEL_TRACE */
end_comment
begin_define
DECL|macro|GXV_INIT
define|#
directive|define
name|GXV_INIT
value|do { } while ( 0 )
end_define
begin_define
DECL|macro|GXV_NAME_ENTER
define|#
directive|define
name|GXV_NAME_ENTER
parameter_list|(
name|name
parameter_list|)
value|do { } while ( 0 )
end_define
begin_define
DECL|macro|GXV_EXIT
define|#
directive|define
name|GXV_EXIT
value|do { } while ( 0 )
end_define
begin_define
DECL|macro|GXV_TRACE
define|#
directive|define
name|GXV_TRACE
parameter_list|(
name|s
parameter_list|)
value|do { } while ( 0 )
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FT_DEBUG_LEVEL_TRACE */
end_comment
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
comment|/*****                    32bit alignment checking                   *****/
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
DECL|macro|GXV_32BIT_ALIGNMENT_VALIDATE
define|#
directive|define
name|GXV_32BIT_ALIGNMENT_VALIDATE
parameter_list|(
name|a
parameter_list|)
define|\
value|FT_BEGIN_STMNT                  \             {                             \               if ( 0 != ( (a) % 4 ) )     \                 FT_INVALID_OFFSET ;       \             }                             \           FT_END_STMNT
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
comment|/*****                    Dumping Binary Data                        *****/
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
DECL|macro|GXV_TRACE_HEXDUMP
define|#
directive|define
name|GXV_TRACE_HEXDUMP
parameter_list|(
name|p
parameter_list|,
name|len
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                \             {                                           \               FT_Bytes  b;                              \                                                         \                                                         \               for ( b = p; b< (FT_Bytes)p + len; b++ ) \                 FT_TRACE1(("\\x%02x", *b)) ;            \             }                                           \           FT_END_STMNT
end_define
begin_define
DECL|macro|GXV_TRACE_HEXDUMP_C
define|#
directive|define
name|GXV_TRACE_HEXDUMP_C
parameter_list|(
name|p
parameter_list|,
name|len
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                \             {                                           \               FT_Bytes  b;                              \                                                         \                                                         \               for ( b = p; b< (FT_Bytes)p + len; b++ ) \                 if ( 0x40< *b&& *b< 0x7e )           \                   FT_TRACE1(("%c", *b)) ;               \                 else                                    \                   FT_TRACE1(("\\x%02x", *b)) ;          \             }                                           \           FT_END_STMNT
end_define
begin_define
DECL|macro|GXV_TRACE_HEXDUMP_SFNTNAME
define|#
directive|define
name|GXV_TRACE_HEXDUMP_SFNTNAME
parameter_list|(
name|n
parameter_list|)
define|\
value|GXV_TRACE_HEXDUMP( n.string, n.string_len )
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
comment|/*****                         LOOKUP TABLE                          *****/
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
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_BinSrchHeader_validate
argument_list|(
argument|FT_Bytes       p
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|FT_UShort*     unitSize_p
argument_list|,
argument|FT_UShort*     nUnits_p
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_LookupTable_validate
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
comment|/*****                          Glyph ID                             *****/
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
name|FT_LOCAL
argument_list|(
argument|FT_Int
argument_list|)
end_macro
begin_macro
name|gxv_glyphid_validate
argument_list|(
argument|FT_UShort      gid
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
comment|/*****                        CONTROL POINT                          *****/
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
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|gxv_ctlPoint_validate
name|gxv_ctlPoint_validate
argument_list|(
argument|FT_UShort      gid
argument_list|,
argument|FT_Short       ctl_point
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
comment|/*****                          SFNT NAME                            *****/
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
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_sfntName_validate
argument_list|(
argument|FT_UShort      name_index
argument_list|,
argument|FT_UShort      min_index
argument_list|,
argument|FT_UShort      max_index
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
comment|/*****                          STATE TABLE                          *****/
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
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_StateTable_subtable_setup
argument_list|(
argument|FT_UShort      table_size
argument_list|,
argument|FT_UShort      classTable
argument_list|,
argument|FT_UShort      stateArray
argument_list|,
argument|FT_UShort      entryTable
argument_list|,
argument|FT_UShort*     classTable_length_p
argument_list|,
argument|FT_UShort*     stateArray_length_p
argument_list|,
argument|FT_UShort*     entryTable_length_p
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_XStateTable_subtable_setup
argument_list|(
argument|FT_ULong       table_size
argument_list|,
argument|FT_ULong       classTable
argument_list|,
argument|FT_ULong       stateArray
argument_list|,
argument|FT_ULong       entryTable
argument_list|,
argument|FT_ULong*      classTable_length_p
argument_list|,
argument|FT_ULong*      stateArray_length_p
argument_list|,
argument|FT_ULong*      entryTable_length_p
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_StateTable_validate
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_XStateTable_validate
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
comment|/*****                 UTILITY MACROS AND FUNCTIONS                  *****/
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
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_array_getlimits_byte
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|FT_Byte*       min
argument_list|,
argument|FT_Byte*       max
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_array_getlimits_ushort
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|FT_UShort*     min
argument_list|,
argument|FT_UShort*     max
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_set_length_by_ushort_offset
argument_list|(
argument|FT_UShort*     offset
argument_list|,
argument|FT_UShort**    length
argument_list|,
argument|FT_UShort*     buff
argument_list|,
argument|FT_UInt        nmemb
argument_list|,
argument|FT_UShort      limit
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_set_length_by_ulong_offset
argument_list|(
argument|FT_ULong*      offset
argument_list|,
argument|FT_ULong**     length
argument_list|,
argument|FT_ULong*      buff
argument_list|,
argument|FT_UInt        nmemb
argument_list|,
argument|FT_ULong       limit
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_define
DECL|macro|GXV_SUBTABLE_OFFSET_CHECK
define|#
directive|define
name|GXV_SUBTABLE_OFFSET_CHECK
parameter_list|(
name|_offset
parameter_list|)
define|\
value|FT_BEGIN_STMNT                              \             if ( (_offset)> valid->subtable_length ) \               FT_INVALID_OFFSET;                      \           FT_END_STMNT
end_define
begin_define
DECL|macro|GXV_SUBTABLE_LIMIT_CHECK
define|#
directive|define
name|GXV_SUBTABLE_LIMIT_CHECK
parameter_list|(
name|_count
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                    \             if ( ( p + (_count) - valid->subtable_start )> \                    valid->subtable_length )                 \               FT_INVALID_TOO_SHORT;                         \           FT_END_STMNT
end_define
begin_define
DECL|macro|GXV_USHORT_TO_SHORT
define|#
directive|define
name|GXV_USHORT_TO_SHORT
parameter_list|(
name|_us
parameter_list|)
define|\
value|( ( 0x8000U< ( _us ) ) ? ( ( _us ) - 0x8000U ) : ( _us ) )
end_define
begin_define
DECL|macro|GXV_STATETABLE_HEADER_SIZE
define|#
directive|define
name|GXV_STATETABLE_HEADER_SIZE
value|( 2 + 2 + 2 + 2 )
end_define
begin_define
DECL|macro|GXV_STATEHEADER_SIZE
define|#
directive|define
name|GXV_STATEHEADER_SIZE
value|GXV_STATETABLE_HEADER_SIZE
end_define
begin_define
DECL|macro|GXV_XSTATETABLE_HEADER_SIZE
define|#
directive|define
name|GXV_XSTATETABLE_HEADER_SIZE
value|( 4 + 4 + 4 + 4 )
end_define
begin_define
DECL|macro|GXV_XSTATEHEADER_SIZE
define|#
directive|define
name|GXV_XSTATEHEADER_SIZE
value|GXV_XSTATETABLE_HEADER_SIZE
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
comment|/*****                        Table overlapping                      *****/
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
DECL|struct|GXV_odtect_DataRec_
typedef|typedef
struct|struct
name|GXV_odtect_DataRec_
block|{
DECL|member|start
name|FT_Bytes
name|start
decl_stmt|;
DECL|member|length
name|FT_ULong
name|length
decl_stmt|;
DECL|member|name
name|FT_String
modifier|*
name|name
decl_stmt|;
block|}
DECL|typedef|GXV_odtect_DataRec
DECL|typedef|GXV_odtect_Data
name|GXV_odtect_DataRec
operator|,
typedef|*
name|GXV_odtect_Data
typedef|;
end_typedef
begin_typedef
DECL|struct|GXV_odtect_RangeRec_
typedef|typedef
struct|struct
name|GXV_odtect_RangeRec_
block|{
DECL|member|nRanges
name|FT_UInt
name|nRanges
decl_stmt|;
DECL|member|range
name|GXV_odtect_Data
name|range
decl_stmt|;
block|}
DECL|typedef|GXV_odtect_RangeRec
DECL|typedef|GXV_odtect_Range
name|GXV_odtect_RangeRec
operator|,
typedef|*
name|GXV_odtect_Range
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_odtect_add_range
argument_list|(
argument|FT_Bytes          start
argument_list|,
argument|FT_ULong          length
argument_list|,
argument|const FT_String*  name
argument_list|,
argument|GXV_odtect_Range  odtect
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_odtect_validate
argument_list|(
argument|GXV_odtect_Range  odtect
argument_list|,
argument|GXV_Validator     valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_define
DECL|macro|GXV_ODTECT
define|#
directive|define
name|GXV_ODTECT
parameter_list|(
name|n
parameter_list|,
name|odtect
parameter_list|)
define|\
value|GXV_odtect_DataRec   odtect ## _range[n];          \           GXV_odtect_RangeRec  odtect ## _rec = { 0, NULL }; \           GXV_odtect_Range     odtect = NULL
end_define
begin_define
DECL|macro|GXV_ODTECT_INIT
define|#
directive|define
name|GXV_ODTECT_INIT
parameter_list|(
name|odtect
parameter_list|)
define|\
value|FT_BEGIN_STMNT                               \             odtect ## _rec.nRanges = 0;                \             odtect ## _rec.range   = odtect ## _range; \             odtect                 =& odtect ## _rec; \           FT_END_STMNT
end_define
begin_comment
comment|/* */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __GXVCOMMN_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
