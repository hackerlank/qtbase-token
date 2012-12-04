begin_unit
begin_comment
comment|/*  * Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies)  * Copyright (C) 2007  Red Hat, Inc.  *  * This is part of HarfBuzz, an OpenType Layout engine library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  *  * Red Hat Author(s): Behdad Esfahbod  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|HARFBUZZ_GLOBAL_H
end_ifndef
begin_define
DECL|macro|HARFBUZZ_GLOBAL_H
define|#
directive|define
name|HARFBUZZ_GLOBAL_H
end_define
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|HB_BEGIN_HEADER
define|#
directive|define
name|HB_BEGIN_HEADER
value|extern "C" {
end_define
begin_define
DECL|macro|HB_END_HEADER
define|#
directive|define
name|HB_END_HEADER
value|}
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|HB_BEGIN_HEADER
define|#
directive|define
name|HB_BEGIN_HEADER
end_define
begin_comment
DECL|macro|HB_BEGIN_HEADER
comment|/* nothing */
end_comment
begin_define
DECL|macro|HB_END_HEADER
define|#
directive|define
name|HB_END_HEADER
end_define
begin_comment
DECL|macro|HB_END_HEADER
comment|/* nothing */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|HB_BEGIN_HEADER
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef
begin_define
DECL|macro|FALSE
define|#
directive|define
name|FALSE
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef
begin_define
DECL|macro|TRUE
define|#
directive|define
name|TRUE
value|(!FALSE)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|HB_MAKE_TAG
define|#
directive|define
name|HB_MAKE_TAG
parameter_list|(
name|_x1
parameter_list|,
name|_x2
parameter_list|,
name|_x3
parameter_list|,
name|_x4
parameter_list|)
define|\
value|( ( (HB_UInt)_x1<< 24 ) |     \             ( (HB_UInt)_x2<< 16 ) |     \             ( (HB_UInt)_x3<<  8 ) |     \               (HB_UInt)_x4         )
end_define
begin_typedef
DECL|typedef|hb_int8
typedef|typedef
name|char
name|hb_int8
typedef|;
end_typedef
begin_typedef
DECL|typedef|hb_uint8
typedef|typedef
name|unsigned
name|char
name|hb_uint8
typedef|;
end_typedef
begin_typedef
DECL|typedef|hb_int16
typedef|typedef
name|short
name|hb_int16
typedef|;
end_typedef
begin_typedef
DECL|typedef|hb_uint16
typedef|typedef
name|unsigned
name|short
name|hb_uint16
typedef|;
end_typedef
begin_typedef
DECL|typedef|hb_int32
typedef|typedef
name|int
name|hb_int32
typedef|;
end_typedef
begin_typedef
DECL|typedef|hb_uint32
typedef|typedef
name|unsigned
name|int
name|hb_uint32
typedef|;
end_typedef
begin_typedef
DECL|typedef|HB_Bool
typedef|typedef
name|hb_uint8
name|HB_Bool
typedef|;
end_typedef
begin_typedef
DECL|typedef|HB_Byte
typedef|typedef
name|hb_uint8
name|HB_Byte
typedef|;
end_typedef
begin_typedef
DECL|typedef|HB_UShort
typedef|typedef
name|hb_uint16
name|HB_UShort
typedef|;
end_typedef
begin_typedef
DECL|typedef|HB_UInt
typedef|typedef
name|hb_uint32
name|HB_UInt
typedef|;
end_typedef
begin_typedef
DECL|typedef|HB_Char
typedef|typedef
name|hb_int8
name|HB_Char
typedef|;
end_typedef
begin_typedef
DECL|typedef|HB_Short
typedef|typedef
name|hb_int16
name|HB_Short
typedef|;
end_typedef
begin_typedef
DECL|typedef|HB_Int
typedef|typedef
name|hb_int32
name|HB_Int
typedef|;
end_typedef
begin_typedef
DECL|typedef|HB_UChar16
typedef|typedef
name|hb_uint16
name|HB_UChar16
typedef|;
end_typedef
begin_typedef
DECL|typedef|HB_UChar32
typedef|typedef
name|hb_uint32
name|HB_UChar32
typedef|;
end_typedef
begin_typedef
DECL|typedef|HB_Glyph
typedef|typedef
name|hb_uint32
name|HB_Glyph
typedef|;
end_typedef
begin_typedef
DECL|typedef|HB_Fixed
typedef|typedef
name|hb_int32
name|HB_Fixed
typedef|;
end_typedef
begin_comment
DECL|typedef|HB_Fixed
comment|/* 26.6 */
end_comment
begin_define
DECL|macro|HB_FIXED_CONSTANT
define|#
directive|define
name|HB_FIXED_CONSTANT
parameter_list|(
name|v
parameter_list|)
value|((v) * 64)
end_define
begin_define
DECL|macro|HB_FIXED_ROUND
define|#
directive|define
name|HB_FIXED_ROUND
parameter_list|(
name|v
parameter_list|)
value|(((v)+32)& -64)
end_define
begin_typedef
DECL|typedef|HB_16Dot16
typedef|typedef
name|hb_int32
name|HB_16Dot16
typedef|;
end_typedef
begin_comment
DECL|typedef|HB_16Dot16
comment|/* 16.16 */
end_comment
begin_typedef
DECL|typedef|HB_Pointer
typedef|typedef
name|void
modifier|*
name|HB_Pointer
typedef|;
end_typedef
begin_typedef
DECL|typedef|HB_Tag
typedef|typedef
name|hb_uint32
name|HB_Tag
typedef|;
end_typedef
begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* no error */
DECL|enumerator|HB_Err_Ok
name|HB_Err_Ok
init|=
literal|0x0000
block|,
DECL|enumerator|HB_Err_Not_Covered
name|HB_Err_Not_Covered
init|=
literal|0xFFFF
block|,
comment|/* _hb_err() is called whenever returning the following errors,    * and in a couple places for HB_Err_Not_Covered too. */
comment|/* programmer error */
DECL|enumerator|HB_Err_Invalid_Argument
name|HB_Err_Invalid_Argument
init|=
literal|0x1A66
block|,
comment|/* font error */
DECL|enumerator|HB_Err_Invalid_SubTable_Format
name|HB_Err_Invalid_SubTable_Format
init|=
literal|0x157F
block|,
DECL|enumerator|HB_Err_Invalid_SubTable
name|HB_Err_Invalid_SubTable
init|=
literal|0x1570
block|,
DECL|enumerator|HB_Err_Read_Error
name|HB_Err_Read_Error
init|=
literal|0x6EAD
block|,
comment|/* system error */
DECL|enumerator|HB_Err_Out_Of_Memory
name|HB_Err_Out_Of_Memory
init|=
literal|0xDEAD
block|}
DECL|typedef|HB_Error
name|HB_Error
typedef|;
end_typedef
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|x
name|HB_Fixed
name|x
decl_stmt|;
DECL|member|y
name|HB_Fixed
name|y
decl_stmt|;
block|}
DECL|typedef|HB_FixedPoint
name|HB_FixedPoint
typedef|;
end_typedef
begin_typedef
DECL|typedef|HB_Font
typedef|typedef
name|struct
name|HB_Font_
modifier|*
name|HB_Font
typedef|;
end_typedef
begin_typedef
DECL|typedef|HB_Stream
typedef|typedef
name|struct
name|HB_StreamRec_
modifier|*
name|HB_Stream
typedef|;
end_typedef
begin_typedef
DECL|typedef|HB_Face
typedef|typedef
name|struct
name|HB_FaceRec_
modifier|*
name|HB_Face
typedef|;
end_typedef
begin_macro
name|HB_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
