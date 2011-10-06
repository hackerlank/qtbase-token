begin_unit
begin_comment
comment|/* this ALWAYS GENERATED file contains the definitions for the interfaces */
end_comment
begin_comment
comment|/* File created by MIDL compiler version 7.00.0555 */
end_comment
begin_comment
comment|/* at Thu Mar 08 14:53:56 2012  */
end_comment
begin_comment
comment|/* Compiler settings for IA2CommonTypes.idl:     Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555      protocol : dce , ms_ext, c_ext, robust     error checks: allocation ref bounds_check enum stub_data      VC __declspec() decoration level:           __declspec(uuid()), __declspec(selectany), __declspec(novtable)          DECLSPEC_UUID(), MIDL_INTERFACE() */
end_comment
begin_comment
comment|/* @@MIDL_FILE_HEADING(  ) */
end_comment
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4049
name|)
end_pragma
begin_comment
comment|/* more than 64k source lines */
end_comment
begin_comment
comment|/* verify that the<rpcndr.h> version is high enough to compile this file*/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__REQUIRED_RPCNDR_H_VERSION__
end_ifndef
begin_define
DECL|macro|__REQUIRED_RPCNDR_H_VERSION__
define|#
directive|define
name|__REQUIRED_RPCNDR_H_VERSION__
value|475
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"rpc.h"
end_include
begin_include
include|#
directive|include
file|"rpcndr.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|__RPCNDR_H_VERSION__
end_ifndef
begin_error
error|#
directive|error
error|this stub requires an updated version of<rpcndr.h>
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// __RPCNDR_H_VERSION__
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__IA2CommonTypes_h__
end_ifndef
begin_define
DECL|macro|__IA2CommonTypes_h__
define|#
directive|define
name|__IA2CommonTypes_h__
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|(
name|_MSC_VER
operator|>=
literal|1020
operator|)
end_if
begin_pragma
pragma|#
directive|pragma
name|once
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Forward Declarations */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* interface __MIDL_itf_IA2CommonTypes_0000_0000 */
comment|/* [local] */
DECL|enum|IA2ScrollType
enum|enum
name|IA2ScrollType
DECL|enumerator|IA2_SCROLL_TYPE_TOP_LEFT
block|{
name|IA2_SCROLL_TYPE_TOP_LEFT
init|=
literal|0
block|,
DECL|enumerator|IA2_SCROLL_TYPE_BOTTOM_RIGHT
name|IA2_SCROLL_TYPE_BOTTOM_RIGHT
init|=
operator|(
name|IA2_SCROLL_TYPE_TOP_LEFT
operator|+
literal|1
operator|)
block|,
DECL|enumerator|IA2_SCROLL_TYPE_TOP_EDGE
name|IA2_SCROLL_TYPE_TOP_EDGE
init|=
operator|(
name|IA2_SCROLL_TYPE_BOTTOM_RIGHT
operator|+
literal|1
operator|)
block|,
DECL|enumerator|IA2_SCROLL_TYPE_BOTTOM_EDGE
name|IA2_SCROLL_TYPE_BOTTOM_EDGE
init|=
operator|(
name|IA2_SCROLL_TYPE_TOP_EDGE
operator|+
literal|1
operator|)
block|,
DECL|enumerator|IA2_SCROLL_TYPE_LEFT_EDGE
name|IA2_SCROLL_TYPE_LEFT_EDGE
init|=
operator|(
name|IA2_SCROLL_TYPE_BOTTOM_EDGE
operator|+
literal|1
operator|)
block|,
DECL|enumerator|IA2_SCROLL_TYPE_RIGHT_EDGE
name|IA2_SCROLL_TYPE_RIGHT_EDGE
init|=
operator|(
name|IA2_SCROLL_TYPE_LEFT_EDGE
operator|+
literal|1
operator|)
block|,
DECL|enumerator|IA2_SCROLL_TYPE_ANYWHERE
name|IA2_SCROLL_TYPE_ANYWHERE
init|=
operator|(
name|IA2_SCROLL_TYPE_RIGHT_EDGE
operator|+
literal|1
operator|)
block|}
enum|;
DECL|enum|IA2CoordinateType
enum|enum
name|IA2CoordinateType
DECL|enumerator|IA2_COORDTYPE_SCREEN_RELATIVE
block|{
name|IA2_COORDTYPE_SCREEN_RELATIVE
init|=
literal|0
block|,
DECL|enumerator|IA2_COORDTYPE_PARENT_RELATIVE
name|IA2_COORDTYPE_PARENT_RELATIVE
init|=
operator|(
name|IA2_COORDTYPE_SCREEN_RELATIVE
operator|+
literal|1
operator|)
block|}
enum|;
DECL|enum|IA2TextSpecialOffsets
enum|enum
name|IA2TextSpecialOffsets
DECL|enumerator|IA2_TEXT_OFFSET_LENGTH
block|{
name|IA2_TEXT_OFFSET_LENGTH
init|=
operator|-
literal|1
block|,
DECL|enumerator|IA2_TEXT_OFFSET_CARET
name|IA2_TEXT_OFFSET_CARET
init|=
operator|-
literal|2
block|}
enum|;
DECL|enum|IA2TableModelChangeType
enum|enum
name|IA2TableModelChangeType
DECL|enumerator|IA2_TABLE_MODEL_CHANGE_INSERT
block|{
name|IA2_TABLE_MODEL_CHANGE_INSERT
init|=
literal|0
block|,
DECL|enumerator|IA2_TABLE_MODEL_CHANGE_DELETE
name|IA2_TABLE_MODEL_CHANGE_DELETE
init|=
operator|(
name|IA2_TABLE_MODEL_CHANGE_INSERT
operator|+
literal|1
operator|)
block|,
DECL|enumerator|IA2_TABLE_MODEL_CHANGE_UPDATE
name|IA2_TABLE_MODEL_CHANGE_UPDATE
init|=
operator|(
name|IA2_TABLE_MODEL_CHANGE_DELETE
operator|+
literal|1
operator|)
block|}
enum|;
DECL|struct|IA2TableModelChange
typedef|typedef
struct|struct
name|IA2TableModelChange
block|{
DECL|member|type
name|enum
name|IA2TableModelChangeType
name|type
decl_stmt|;
DECL|member|firstRow
name|long
name|firstRow
decl_stmt|;
DECL|member|lastRow
name|long
name|lastRow
decl_stmt|;
DECL|member|firstColumn
name|long
name|firstColumn
decl_stmt|;
DECL|member|lastColumn
name|long
name|lastColumn
decl_stmt|;
block|}
DECL|typedef|IA2TableModelChange
name|IA2TableModelChange
typedef|;
specifier|extern
name|RPC_IF_HANDLE
name|__MIDL_itf_IA2CommonTypes_0000_0000_v0_0_c_ifspec
decl_stmt|;
specifier|extern
name|RPC_IF_HANDLE
name|__MIDL_itf_IA2CommonTypes_0000_0000_v0_0_s_ifspec
decl_stmt|;
comment|/* Additional Prototypes for ALL interfaces */
comment|/* end of Additional Prototypes */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
end_unit
