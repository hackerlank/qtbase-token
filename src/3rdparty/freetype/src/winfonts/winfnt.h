begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  winfnt.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType font driver for Windows FNT/FON files                       */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2015 by                                                 */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*  Copyright 2007 Dmitry Timoshkov for Codeweavers                        */
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
begin_ifndef
ifndef|#
directive|ifndef
name|__WINFNT_H__
end_ifndef
begin_define
DECL|macro|__WINFNT_H__
define|#
directive|define
name|__WINFNT_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_WINFONTS_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DRIVER_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_PIC
end_ifdef
begin_error
error|#
directive|error
literal|"this module does not support PIC yet"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|struct|WinMZ_HeaderRec_
typedef|typedef
struct|struct
name|WinMZ_HeaderRec_
block|{
DECL|member|magic
name|FT_UShort
name|magic
decl_stmt|;
comment|/* skipped content */
DECL|member|lfanew
name|FT_UShort
name|lfanew
decl_stmt|;
block|}
DECL|typedef|WinMZ_HeaderRec
name|WinMZ_HeaderRec
typedef|;
end_typedef
begin_typedef
DECL|struct|WinNE_HeaderRec_
typedef|typedef
struct|struct
name|WinNE_HeaderRec_
block|{
DECL|member|magic
name|FT_UShort
name|magic
decl_stmt|;
comment|/* skipped content */
DECL|member|resource_tab_offset
name|FT_UShort
name|resource_tab_offset
decl_stmt|;
DECL|member|rname_tab_offset
name|FT_UShort
name|rname_tab_offset
decl_stmt|;
block|}
DECL|typedef|WinNE_HeaderRec
name|WinNE_HeaderRec
typedef|;
end_typedef
begin_typedef
DECL|struct|WinPE32_HeaderRec_
typedef|typedef
struct|struct
name|WinPE32_HeaderRec_
block|{
DECL|member|magic
name|FT_ULong
name|magic
decl_stmt|;
DECL|member|machine
name|FT_UShort
name|machine
decl_stmt|;
DECL|member|number_of_sections
name|FT_UShort
name|number_of_sections
decl_stmt|;
comment|/* skipped content */
DECL|member|size_of_optional_header
name|FT_UShort
name|size_of_optional_header
decl_stmt|;
comment|/* skipped content */
DECL|member|magic32
name|FT_UShort
name|magic32
decl_stmt|;
comment|/* skipped content */
DECL|member|rsrc_virtual_address
name|FT_ULong
name|rsrc_virtual_address
decl_stmt|;
DECL|member|rsrc_size
name|FT_ULong
name|rsrc_size
decl_stmt|;
comment|/* skipped content */
block|}
DECL|typedef|WinPE32_HeaderRec
name|WinPE32_HeaderRec
typedef|;
end_typedef
begin_typedef
DECL|struct|WinPE32_SectionRec_
typedef|typedef
struct|struct
name|WinPE32_SectionRec_
block|{
DECL|member|name
name|FT_Byte
name|name
index|[
literal|8
index|]
decl_stmt|;
comment|/* skipped content */
DECL|member|virtual_address
name|FT_ULong
name|virtual_address
decl_stmt|;
DECL|member|size_of_raw_data
name|FT_ULong
name|size_of_raw_data
decl_stmt|;
DECL|member|pointer_to_raw_data
name|FT_ULong
name|pointer_to_raw_data
decl_stmt|;
comment|/* skipped content */
block|}
DECL|typedef|WinPE32_SectionRec
name|WinPE32_SectionRec
typedef|;
end_typedef
begin_typedef
DECL|struct|WinPE_RsrcDirRec_
typedef|typedef
struct|struct
name|WinPE_RsrcDirRec_
block|{
DECL|member|characteristics
name|FT_ULong
name|characteristics
decl_stmt|;
DECL|member|time_date_stamp
name|FT_ULong
name|time_date_stamp
decl_stmt|;
DECL|member|major_version
name|FT_UShort
name|major_version
decl_stmt|;
DECL|member|minor_version
name|FT_UShort
name|minor_version
decl_stmt|;
DECL|member|number_of_named_entries
name|FT_UShort
name|number_of_named_entries
decl_stmt|;
DECL|member|number_of_id_entries
name|FT_UShort
name|number_of_id_entries
decl_stmt|;
block|}
DECL|typedef|WinPE_RsrcDirRec
name|WinPE_RsrcDirRec
typedef|;
end_typedef
begin_typedef
DECL|struct|WinPE_RsrcDirEntryRec_
typedef|typedef
struct|struct
name|WinPE_RsrcDirEntryRec_
block|{
DECL|member|name
name|FT_ULong
name|name
decl_stmt|;
DECL|member|offset
name|FT_ULong
name|offset
decl_stmt|;
block|}
DECL|typedef|WinPE_RsrcDirEntryRec
name|WinPE_RsrcDirEntryRec
typedef|;
end_typedef
begin_typedef
DECL|struct|WinPE_RsrcDataEntryRec_
typedef|typedef
struct|struct
name|WinPE_RsrcDataEntryRec_
block|{
DECL|member|offset_to_data
name|FT_ULong
name|offset_to_data
decl_stmt|;
DECL|member|size
name|FT_ULong
name|size
decl_stmt|;
DECL|member|code_page
name|FT_ULong
name|code_page
decl_stmt|;
DECL|member|reserved
name|FT_ULong
name|reserved
decl_stmt|;
block|}
DECL|typedef|WinPE_RsrcDataEntryRec
name|WinPE_RsrcDataEntryRec
typedef|;
end_typedef
begin_typedef
DECL|struct|WinNameInfoRec_
typedef|typedef
struct|struct
name|WinNameInfoRec_
block|{
DECL|member|offset
name|FT_UShort
name|offset
decl_stmt|;
DECL|member|length
name|FT_UShort
name|length
decl_stmt|;
DECL|member|flags
name|FT_UShort
name|flags
decl_stmt|;
DECL|member|id
name|FT_UShort
name|id
decl_stmt|;
DECL|member|handle
name|FT_UShort
name|handle
decl_stmt|;
DECL|member|usage
name|FT_UShort
name|usage
decl_stmt|;
block|}
DECL|typedef|WinNameInfoRec
name|WinNameInfoRec
typedef|;
end_typedef
begin_typedef
DECL|struct|WinResourceInfoRec_
typedef|typedef
struct|struct
name|WinResourceInfoRec_
block|{
DECL|member|type_id
name|FT_UShort
name|type_id
decl_stmt|;
DECL|member|count
name|FT_UShort
name|count
decl_stmt|;
block|}
DECL|typedef|WinResourceInfoRec
name|WinResourceInfoRec
typedef|;
end_typedef
begin_define
DECL|macro|WINFNT_MZ_MAGIC
define|#
directive|define
name|WINFNT_MZ_MAGIC
value|0x5A4D
end_define
begin_define
DECL|macro|WINFNT_NE_MAGIC
define|#
directive|define
name|WINFNT_NE_MAGIC
value|0x454E
end_define
begin_define
DECL|macro|WINFNT_PE_MAGIC
define|#
directive|define
name|WINFNT_PE_MAGIC
value|0x4550
end_define
begin_typedef
DECL|struct|FNT_FontRec_
typedef|typedef
struct|struct
name|FNT_FontRec_
block|{
DECL|member|offset
name|FT_ULong
name|offset
decl_stmt|;
DECL|member|header
name|FT_WinFNT_HeaderRec
name|header
decl_stmt|;
DECL|member|fnt_frame
name|FT_Byte
modifier|*
name|fnt_frame
decl_stmt|;
DECL|member|fnt_size
name|FT_ULong
name|fnt_size
decl_stmt|;
DECL|member|family_name
name|FT_String
modifier|*
name|family_name
decl_stmt|;
block|}
DECL|typedef|FNT_FontRec
DECL|typedef|FNT_Font
name|FNT_FontRec
operator|,
typedef|*
name|FNT_Font
typedef|;
end_typedef
begin_typedef
DECL|struct|FNT_FaceRec_
typedef|typedef
struct|struct
name|FNT_FaceRec_
block|{
DECL|member|root
name|FT_FaceRec
name|root
decl_stmt|;
DECL|member|font
name|FNT_Font
name|font
decl_stmt|;
DECL|member|charmap_handle
name|FT_CharMap
name|charmap_handle
decl_stmt|;
DECL|member|charmap
name|FT_CharMapRec
name|charmap
decl_stmt|;
comment|/* a single charmap per face */
block|}
DECL|typedef|FNT_FaceRec
DECL|typedef|FNT_Face
name|FNT_FaceRec
operator|,
typedef|*
name|FNT_Face
typedef|;
end_typedef
begin_macro
name|FT_EXPORT_VAR
argument_list|(
argument|const FT_Driver_ClassRec
argument_list|)
end_macro
begin_expr_stmt
name|winfnt_driver_class
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __WINFNT_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
