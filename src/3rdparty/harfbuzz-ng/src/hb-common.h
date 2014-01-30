begin_unit
begin_comment
comment|/*  * Copyright Â© 2007,2008,2009  Red Hat, Inc.  * Copyright Â© 2011,2012  Google, Inc.  *  *  This is part of HarfBuzz, a text shaping library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  *  * Red Hat Author(s): Behdad Esfahbod  * Google Author(s): Behdad Esfahbod  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|HB_H_IN
end_ifndef
begin_error
error|#
directive|error
literal|"Include<hb.h> instead."
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|HB_COMMON_H
end_ifndef
begin_define
DECL|macro|HB_COMMON_H
define|#
directive|define
name|HB_COMMON_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|HB_BEGIN_DECLS
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|HB_BEGIN_DECLS
define|#
directive|define
name|HB_BEGIN_DECLS
value|extern "C" {
end_define
begin_define
DECL|macro|HB_END_DECLS
define|#
directive|define
name|HB_END_DECLS
value|}
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !__cplusplus */
end_comment
begin_define
DECL|macro|HB_BEGIN_DECLS
define|#
directive|define
name|HB_BEGIN_DECLS
end_define
begin_define
DECL|macro|HB_END_DECLS
define|#
directive|define
name|HB_END_DECLS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !__cplusplus */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HB_DONT_DEFINE_STDINT
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_SVR4
argument_list|)
operator|||
name|defined
argument_list|(
name|SVR4
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|_sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|__sun
argument_list|)
operator|||
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__digital__
argument_list|)
operator|||
name|defined
argument_list|(
name|__HP_cc
argument_list|)
end_if
begin_include
include|#
directive|include
file|<inttypes.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_AIX
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<sys/inttypes.h>
end_include
begin_comment
comment|/* VS 2010 (_MSC_VER 1600) has stdint.h */
end_comment
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|<
literal|1600
end_elif
begin_typedef
DECL|typedef|int8_t
typedef|typedef
name|__int8
name|int8_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|uint8_t
typedef|typedef
name|unsigned
name|__int8
name|uint8_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|int16_t
typedef|typedef
name|__int16
name|int16_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|uint16_t
typedef|typedef
name|unsigned
name|__int16
name|uint16_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|int32_t
typedef|typedef
name|__int32
name|int32_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|uint32_t
typedef|typedef
name|unsigned
name|__int32
name|uint32_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|int64_t
typedef|typedef
name|__int64
name|int64_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|uint64_t
typedef|typedef
name|unsigned
name|__int64
name|uint64_t
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<stdint.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|HB_BEGIN_DECLS
end_macro
begin_typedef
DECL|typedef|hb_bool_t
typedef|typedef
name|int
name|hb_bool_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|hb_codepoint_t
typedef|typedef
name|uint32_t
name|hb_codepoint_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|hb_position_t
typedef|typedef
name|int32_t
name|hb_position_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|hb_mask_t
typedef|typedef
name|uint32_t
name|hb_mask_t
typedef|;
end_typedef
begin_typedef
DECL|union|_hb_var_int_t
typedef|typedef
union|union
name|_hb_var_int_t
block|{
DECL|member|u32
name|uint32_t
name|u32
decl_stmt|;
DECL|member|i32
name|int32_t
name|i32
decl_stmt|;
DECL|member|u16
name|uint16_t
name|u16
index|[
literal|2
index|]
decl_stmt|;
DECL|member|i16
name|int16_t
name|i16
index|[
literal|2
index|]
decl_stmt|;
DECL|member|u8
name|uint8_t
name|u8
index|[
literal|4
index|]
decl_stmt|;
DECL|member|i8
name|int8_t
name|i8
index|[
literal|4
index|]
decl_stmt|;
block|}
DECL|typedef|hb_var_int_t
name|hb_var_int_t
typedef|;
end_typedef
begin_comment
comment|/* hb_tag_t */
end_comment
begin_typedef
DECL|typedef|hb_tag_t
typedef|typedef
name|uint32_t
name|hb_tag_t
typedef|;
end_typedef
begin_define
DECL|macro|HB_TAG
define|#
directive|define
name|HB_TAG
parameter_list|(
name|c1
parameter_list|,
name|c2
parameter_list|,
name|c3
parameter_list|,
name|c4
parameter_list|)
value|((hb_tag_t)((((uint8_t)(c1))<<24)|(((uint8_t)(c2))<<16)|(((uint8_t)(c3))<<8)|((uint8_t)(c4))))
end_define
begin_define
DECL|macro|HB_UNTAG
define|#
directive|define
name|HB_UNTAG
parameter_list|(
name|tag
parameter_list|)
value|((uint8_t)((tag)>>24)), ((uint8_t)((tag)>>16)), ((uint8_t)((tag)>>8)), ((uint8_t)(tag))
end_define
begin_define
DECL|macro|HB_TAG_NONE
define|#
directive|define
name|HB_TAG_NONE
value|HB_TAG(0,0,0,0)
end_define
begin_define
DECL|macro|HB_TAG_MAX
define|#
directive|define
name|HB_TAG_MAX
value|HB_TAG(0xff,0xff,0xff,0xff)
end_define
begin_comment
comment|/* len=-1 means str is NUL-terminated. */
end_comment
begin_function_decl
name|hb_tag_t
name|hb_tag_from_string
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* buf should have 4 bytes. */
end_comment
begin_function_decl
name|void
name|hb_tag_to_string
parameter_list|(
name|hb_tag_t
name|tag
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* hb_direction_t */
end_comment
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|HB_DIRECTION_INVALID
name|HB_DIRECTION_INVALID
init|=
literal|0
block|,
DECL|enumerator|HB_DIRECTION_LTR
name|HB_DIRECTION_LTR
init|=
literal|4
block|,
DECL|enumerator|HB_DIRECTION_RTL
name|HB_DIRECTION_RTL
block|,
DECL|enumerator|HB_DIRECTION_TTB
name|HB_DIRECTION_TTB
block|,
DECL|enumerator|HB_DIRECTION_BTT
name|HB_DIRECTION_BTT
block|}
DECL|typedef|hb_direction_t
name|hb_direction_t
typedef|;
end_typedef
begin_comment
comment|/* len=-1 means str is NUL-terminated */
end_comment
begin_function_decl
name|hb_direction_t
name|hb_direction_from_string
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|char
modifier|*
name|hb_direction_to_string
parameter_list|(
name|hb_direction_t
name|direction
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|HB_DIRECTION_IS_HORIZONTAL
define|#
directive|define
name|HB_DIRECTION_IS_HORIZONTAL
parameter_list|(
name|dir
parameter_list|)
value|((((unsigned int) (dir))& ~1U) == 4)
end_define
begin_define
DECL|macro|HB_DIRECTION_IS_VERTICAL
define|#
directive|define
name|HB_DIRECTION_IS_VERTICAL
parameter_list|(
name|dir
parameter_list|)
value|((((unsigned int) (dir))& ~1U) == 6)
end_define
begin_define
DECL|macro|HB_DIRECTION_IS_FORWARD
define|#
directive|define
name|HB_DIRECTION_IS_FORWARD
parameter_list|(
name|dir
parameter_list|)
value|((((unsigned int) (dir))& ~2U) == 4)
end_define
begin_define
DECL|macro|HB_DIRECTION_IS_BACKWARD
define|#
directive|define
name|HB_DIRECTION_IS_BACKWARD
parameter_list|(
name|dir
parameter_list|)
value|((((unsigned int) (dir))& ~2U) == 5)
end_define
begin_define
DECL|macro|HB_DIRECTION_IS_VALID
define|#
directive|define
name|HB_DIRECTION_IS_VALID
parameter_list|(
name|dir
parameter_list|)
value|((((unsigned int) (dir))& ~3U) == 4)
end_define
begin_define
DECL|macro|HB_DIRECTION_REVERSE
define|#
directive|define
name|HB_DIRECTION_REVERSE
parameter_list|(
name|dir
parameter_list|)
value|((hb_direction_t) (((unsigned int) (dir)) ^ 1))
end_define
begin_comment
DECL|macro|HB_DIRECTION_REVERSE
comment|/* Direction must be valid */
end_comment
begin_comment
comment|/* hb_language_t */
end_comment
begin_typedef
DECL|typedef|hb_language_t
typedef|typedef
specifier|const
name|struct
name|hb_language_impl_t
modifier|*
name|hb_language_t
typedef|;
end_typedef
begin_comment
comment|/* len=-1 means str is NUL-terminated */
end_comment
begin_function_decl
name|hb_language_t
name|hb_language_from_string
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|char
modifier|*
name|hb_language_to_string
parameter_list|(
name|hb_language_t
name|language
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|HB_LANGUAGE_INVALID
define|#
directive|define
name|HB_LANGUAGE_INVALID
value|((hb_language_t) NULL)
end_define
begin_function_decl
name|hb_language_t
name|hb_language_get_default
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* hb_script_t */
end_comment
begin_comment
comment|/* http://unicode.org/iso15924/ */
end_comment
begin_comment
comment|/* http://goo.gl/x9ilM */
end_comment
begin_comment
comment|/* Unicode Character Database property: Script (sc) */
end_comment
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|HB_SCRIPT_COMMON
comment|/*1.1*/
name|HB_SCRIPT_COMMON
init|=
name|HB_TAG
argument_list|(
literal|'Z'
argument_list|,
literal|'y'
argument_list|,
literal|'y'
argument_list|,
literal|'y'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_INHERITED
comment|/*1.1*/
name|HB_SCRIPT_INHERITED
init|=
name|HB_TAG
argument_list|(
literal|'Z'
argument_list|,
literal|'i'
argument_list|,
literal|'n'
argument_list|,
literal|'h'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_UNKNOWN
comment|/*5.0*/
name|HB_SCRIPT_UNKNOWN
init|=
name|HB_TAG
argument_list|(
literal|'Z'
argument_list|,
literal|'z'
argument_list|,
literal|'z'
argument_list|,
literal|'z'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_ARABIC
comment|/*1.1*/
name|HB_SCRIPT_ARABIC
init|=
name|HB_TAG
argument_list|(
literal|'A'
argument_list|,
literal|'r'
argument_list|,
literal|'a'
argument_list|,
literal|'b'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_ARMENIAN
comment|/*1.1*/
name|HB_SCRIPT_ARMENIAN
init|=
name|HB_TAG
argument_list|(
literal|'A'
argument_list|,
literal|'r'
argument_list|,
literal|'m'
argument_list|,
literal|'n'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_BENGALI
comment|/*1.1*/
name|HB_SCRIPT_BENGALI
init|=
name|HB_TAG
argument_list|(
literal|'B'
argument_list|,
literal|'e'
argument_list|,
literal|'n'
argument_list|,
literal|'g'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_CYRILLIC
comment|/*1.1*/
name|HB_SCRIPT_CYRILLIC
init|=
name|HB_TAG
argument_list|(
literal|'C'
argument_list|,
literal|'y'
argument_list|,
literal|'r'
argument_list|,
literal|'l'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_DEVANAGARI
comment|/*1.1*/
name|HB_SCRIPT_DEVANAGARI
init|=
name|HB_TAG
argument_list|(
literal|'D'
argument_list|,
literal|'e'
argument_list|,
literal|'v'
argument_list|,
literal|'a'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_GEORGIAN
comment|/*1.1*/
name|HB_SCRIPT_GEORGIAN
init|=
name|HB_TAG
argument_list|(
literal|'G'
argument_list|,
literal|'e'
argument_list|,
literal|'o'
argument_list|,
literal|'r'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_GREEK
comment|/*1.1*/
name|HB_SCRIPT_GREEK
init|=
name|HB_TAG
argument_list|(
literal|'G'
argument_list|,
literal|'r'
argument_list|,
literal|'e'
argument_list|,
literal|'k'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_GUJARATI
comment|/*1.1*/
name|HB_SCRIPT_GUJARATI
init|=
name|HB_TAG
argument_list|(
literal|'G'
argument_list|,
literal|'u'
argument_list|,
literal|'j'
argument_list|,
literal|'r'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_GURMUKHI
comment|/*1.1*/
name|HB_SCRIPT_GURMUKHI
init|=
name|HB_TAG
argument_list|(
literal|'G'
argument_list|,
literal|'u'
argument_list|,
literal|'r'
argument_list|,
literal|'u'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_HANGUL
comment|/*1.1*/
name|HB_SCRIPT_HANGUL
init|=
name|HB_TAG
argument_list|(
literal|'H'
argument_list|,
literal|'a'
argument_list|,
literal|'n'
argument_list|,
literal|'g'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_HAN
comment|/*1.1*/
name|HB_SCRIPT_HAN
init|=
name|HB_TAG
argument_list|(
literal|'H'
argument_list|,
literal|'a'
argument_list|,
literal|'n'
argument_list|,
literal|'i'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_HEBREW
comment|/*1.1*/
name|HB_SCRIPT_HEBREW
init|=
name|HB_TAG
argument_list|(
literal|'H'
argument_list|,
literal|'e'
argument_list|,
literal|'b'
argument_list|,
literal|'r'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_HIRAGANA
comment|/*1.1*/
name|HB_SCRIPT_HIRAGANA
init|=
name|HB_TAG
argument_list|(
literal|'H'
argument_list|,
literal|'i'
argument_list|,
literal|'r'
argument_list|,
literal|'a'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_KANNADA
comment|/*1.1*/
name|HB_SCRIPT_KANNADA
init|=
name|HB_TAG
argument_list|(
literal|'K'
argument_list|,
literal|'n'
argument_list|,
literal|'d'
argument_list|,
literal|'a'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_KATAKANA
comment|/*1.1*/
name|HB_SCRIPT_KATAKANA
init|=
name|HB_TAG
argument_list|(
literal|'K'
argument_list|,
literal|'a'
argument_list|,
literal|'n'
argument_list|,
literal|'a'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_LAO
comment|/*1.1*/
name|HB_SCRIPT_LAO
init|=
name|HB_TAG
argument_list|(
literal|'L'
argument_list|,
literal|'a'
argument_list|,
literal|'o'
argument_list|,
literal|'o'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_LATIN
comment|/*1.1*/
name|HB_SCRIPT_LATIN
init|=
name|HB_TAG
argument_list|(
literal|'L'
argument_list|,
literal|'a'
argument_list|,
literal|'t'
argument_list|,
literal|'n'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_MALAYALAM
comment|/*1.1*/
name|HB_SCRIPT_MALAYALAM
init|=
name|HB_TAG
argument_list|(
literal|'M'
argument_list|,
literal|'l'
argument_list|,
literal|'y'
argument_list|,
literal|'m'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_ORIYA
comment|/*1.1*/
name|HB_SCRIPT_ORIYA
init|=
name|HB_TAG
argument_list|(
literal|'O'
argument_list|,
literal|'r'
argument_list|,
literal|'y'
argument_list|,
literal|'a'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_TAMIL
comment|/*1.1*/
name|HB_SCRIPT_TAMIL
init|=
name|HB_TAG
argument_list|(
literal|'T'
argument_list|,
literal|'a'
argument_list|,
literal|'m'
argument_list|,
literal|'l'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_TELUGU
comment|/*1.1*/
name|HB_SCRIPT_TELUGU
init|=
name|HB_TAG
argument_list|(
literal|'T'
argument_list|,
literal|'e'
argument_list|,
literal|'l'
argument_list|,
literal|'u'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_THAI
comment|/*1.1*/
name|HB_SCRIPT_THAI
init|=
name|HB_TAG
argument_list|(
literal|'T'
argument_list|,
literal|'h'
argument_list|,
literal|'a'
argument_list|,
literal|'i'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_TIBETAN
comment|/*2.0*/
name|HB_SCRIPT_TIBETAN
init|=
name|HB_TAG
argument_list|(
literal|'T'
argument_list|,
literal|'i'
argument_list|,
literal|'b'
argument_list|,
literal|'t'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_BOPOMOFO
comment|/*3.0*/
name|HB_SCRIPT_BOPOMOFO
init|=
name|HB_TAG
argument_list|(
literal|'B'
argument_list|,
literal|'o'
argument_list|,
literal|'p'
argument_list|,
literal|'o'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_BRAILLE
comment|/*3.0*/
name|HB_SCRIPT_BRAILLE
init|=
name|HB_TAG
argument_list|(
literal|'B'
argument_list|,
literal|'r'
argument_list|,
literal|'a'
argument_list|,
literal|'i'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_CANADIAN_SYLLABICS
comment|/*3.0*/
name|HB_SCRIPT_CANADIAN_SYLLABICS
init|=
name|HB_TAG
argument_list|(
literal|'C'
argument_list|,
literal|'a'
argument_list|,
literal|'n'
argument_list|,
literal|'s'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_CHEROKEE
comment|/*3.0*/
name|HB_SCRIPT_CHEROKEE
init|=
name|HB_TAG
argument_list|(
literal|'C'
argument_list|,
literal|'h'
argument_list|,
literal|'e'
argument_list|,
literal|'r'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_ETHIOPIC
comment|/*3.0*/
name|HB_SCRIPT_ETHIOPIC
init|=
name|HB_TAG
argument_list|(
literal|'E'
argument_list|,
literal|'t'
argument_list|,
literal|'h'
argument_list|,
literal|'i'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_KHMER
comment|/*3.0*/
name|HB_SCRIPT_KHMER
init|=
name|HB_TAG
argument_list|(
literal|'K'
argument_list|,
literal|'h'
argument_list|,
literal|'m'
argument_list|,
literal|'r'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_MONGOLIAN
comment|/*3.0*/
name|HB_SCRIPT_MONGOLIAN
init|=
name|HB_TAG
argument_list|(
literal|'M'
argument_list|,
literal|'o'
argument_list|,
literal|'n'
argument_list|,
literal|'g'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_MYANMAR
comment|/*3.0*/
name|HB_SCRIPT_MYANMAR
init|=
name|HB_TAG
argument_list|(
literal|'M'
argument_list|,
literal|'y'
argument_list|,
literal|'m'
argument_list|,
literal|'r'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_OGHAM
comment|/*3.0*/
name|HB_SCRIPT_OGHAM
init|=
name|HB_TAG
argument_list|(
literal|'O'
argument_list|,
literal|'g'
argument_list|,
literal|'a'
argument_list|,
literal|'m'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_RUNIC
comment|/*3.0*/
name|HB_SCRIPT_RUNIC
init|=
name|HB_TAG
argument_list|(
literal|'R'
argument_list|,
literal|'u'
argument_list|,
literal|'n'
argument_list|,
literal|'r'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_SINHALA
comment|/*3.0*/
name|HB_SCRIPT_SINHALA
init|=
name|HB_TAG
argument_list|(
literal|'S'
argument_list|,
literal|'i'
argument_list|,
literal|'n'
argument_list|,
literal|'h'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_SYRIAC
comment|/*3.0*/
name|HB_SCRIPT_SYRIAC
init|=
name|HB_TAG
argument_list|(
literal|'S'
argument_list|,
literal|'y'
argument_list|,
literal|'r'
argument_list|,
literal|'c'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_THAANA
comment|/*3.0*/
name|HB_SCRIPT_THAANA
init|=
name|HB_TAG
argument_list|(
literal|'T'
argument_list|,
literal|'h'
argument_list|,
literal|'a'
argument_list|,
literal|'a'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_YI
comment|/*3.0*/
name|HB_SCRIPT_YI
init|=
name|HB_TAG
argument_list|(
literal|'Y'
argument_list|,
literal|'i'
argument_list|,
literal|'i'
argument_list|,
literal|'i'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_DESERET
comment|/*3.1*/
name|HB_SCRIPT_DESERET
init|=
name|HB_TAG
argument_list|(
literal|'D'
argument_list|,
literal|'s'
argument_list|,
literal|'r'
argument_list|,
literal|'t'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_GOTHIC
comment|/*3.1*/
name|HB_SCRIPT_GOTHIC
init|=
name|HB_TAG
argument_list|(
literal|'G'
argument_list|,
literal|'o'
argument_list|,
literal|'t'
argument_list|,
literal|'h'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_OLD_ITALIC
comment|/*3.1*/
name|HB_SCRIPT_OLD_ITALIC
init|=
name|HB_TAG
argument_list|(
literal|'I'
argument_list|,
literal|'t'
argument_list|,
literal|'a'
argument_list|,
literal|'l'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_BUHID
comment|/*3.2*/
name|HB_SCRIPT_BUHID
init|=
name|HB_TAG
argument_list|(
literal|'B'
argument_list|,
literal|'u'
argument_list|,
literal|'h'
argument_list|,
literal|'d'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_HANUNOO
comment|/*3.2*/
name|HB_SCRIPT_HANUNOO
init|=
name|HB_TAG
argument_list|(
literal|'H'
argument_list|,
literal|'a'
argument_list|,
literal|'n'
argument_list|,
literal|'o'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_TAGALOG
comment|/*3.2*/
name|HB_SCRIPT_TAGALOG
init|=
name|HB_TAG
argument_list|(
literal|'T'
argument_list|,
literal|'g'
argument_list|,
literal|'l'
argument_list|,
literal|'g'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_TAGBANWA
comment|/*3.2*/
name|HB_SCRIPT_TAGBANWA
init|=
name|HB_TAG
argument_list|(
literal|'T'
argument_list|,
literal|'a'
argument_list|,
literal|'g'
argument_list|,
literal|'b'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_CYPRIOT
comment|/*4.0*/
name|HB_SCRIPT_CYPRIOT
init|=
name|HB_TAG
argument_list|(
literal|'C'
argument_list|,
literal|'p'
argument_list|,
literal|'r'
argument_list|,
literal|'t'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_LIMBU
comment|/*4.0*/
name|HB_SCRIPT_LIMBU
init|=
name|HB_TAG
argument_list|(
literal|'L'
argument_list|,
literal|'i'
argument_list|,
literal|'m'
argument_list|,
literal|'b'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_LINEAR_B
comment|/*4.0*/
name|HB_SCRIPT_LINEAR_B
init|=
name|HB_TAG
argument_list|(
literal|'L'
argument_list|,
literal|'i'
argument_list|,
literal|'n'
argument_list|,
literal|'b'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_OSMANYA
comment|/*4.0*/
name|HB_SCRIPT_OSMANYA
init|=
name|HB_TAG
argument_list|(
literal|'O'
argument_list|,
literal|'s'
argument_list|,
literal|'m'
argument_list|,
literal|'a'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_SHAVIAN
comment|/*4.0*/
name|HB_SCRIPT_SHAVIAN
init|=
name|HB_TAG
argument_list|(
literal|'S'
argument_list|,
literal|'h'
argument_list|,
literal|'a'
argument_list|,
literal|'w'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_TAI_LE
comment|/*4.0*/
name|HB_SCRIPT_TAI_LE
init|=
name|HB_TAG
argument_list|(
literal|'T'
argument_list|,
literal|'a'
argument_list|,
literal|'l'
argument_list|,
literal|'e'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_UGARITIC
comment|/*4.0*/
name|HB_SCRIPT_UGARITIC
init|=
name|HB_TAG
argument_list|(
literal|'U'
argument_list|,
literal|'g'
argument_list|,
literal|'a'
argument_list|,
literal|'r'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_BUGINESE
comment|/*4.1*/
name|HB_SCRIPT_BUGINESE
init|=
name|HB_TAG
argument_list|(
literal|'B'
argument_list|,
literal|'u'
argument_list|,
literal|'g'
argument_list|,
literal|'i'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_COPTIC
comment|/*4.1*/
name|HB_SCRIPT_COPTIC
init|=
name|HB_TAG
argument_list|(
literal|'C'
argument_list|,
literal|'o'
argument_list|,
literal|'p'
argument_list|,
literal|'t'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_GLAGOLITIC
comment|/*4.1*/
name|HB_SCRIPT_GLAGOLITIC
init|=
name|HB_TAG
argument_list|(
literal|'G'
argument_list|,
literal|'l'
argument_list|,
literal|'a'
argument_list|,
literal|'g'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_KHAROSHTHI
comment|/*4.1*/
name|HB_SCRIPT_KHAROSHTHI
init|=
name|HB_TAG
argument_list|(
literal|'K'
argument_list|,
literal|'h'
argument_list|,
literal|'a'
argument_list|,
literal|'r'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_NEW_TAI_LUE
comment|/*4.1*/
name|HB_SCRIPT_NEW_TAI_LUE
init|=
name|HB_TAG
argument_list|(
literal|'T'
argument_list|,
literal|'a'
argument_list|,
literal|'l'
argument_list|,
literal|'u'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_OLD_PERSIAN
comment|/*4.1*/
name|HB_SCRIPT_OLD_PERSIAN
init|=
name|HB_TAG
argument_list|(
literal|'X'
argument_list|,
literal|'p'
argument_list|,
literal|'e'
argument_list|,
literal|'o'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_SYLOTI_NAGRI
comment|/*4.1*/
name|HB_SCRIPT_SYLOTI_NAGRI
init|=
name|HB_TAG
argument_list|(
literal|'S'
argument_list|,
literal|'y'
argument_list|,
literal|'l'
argument_list|,
literal|'o'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_TIFINAGH
comment|/*4.1*/
name|HB_SCRIPT_TIFINAGH
init|=
name|HB_TAG
argument_list|(
literal|'T'
argument_list|,
literal|'f'
argument_list|,
literal|'n'
argument_list|,
literal|'g'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_BALINESE
comment|/*5.0*/
name|HB_SCRIPT_BALINESE
init|=
name|HB_TAG
argument_list|(
literal|'B'
argument_list|,
literal|'a'
argument_list|,
literal|'l'
argument_list|,
literal|'i'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_CUNEIFORM
comment|/*5.0*/
name|HB_SCRIPT_CUNEIFORM
init|=
name|HB_TAG
argument_list|(
literal|'X'
argument_list|,
literal|'s'
argument_list|,
literal|'u'
argument_list|,
literal|'x'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_NKO
comment|/*5.0*/
name|HB_SCRIPT_NKO
init|=
name|HB_TAG
argument_list|(
literal|'N'
argument_list|,
literal|'k'
argument_list|,
literal|'o'
argument_list|,
literal|'o'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_PHAGS_PA
comment|/*5.0*/
name|HB_SCRIPT_PHAGS_PA
init|=
name|HB_TAG
argument_list|(
literal|'P'
argument_list|,
literal|'h'
argument_list|,
literal|'a'
argument_list|,
literal|'g'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_PHOENICIAN
comment|/*5.0*/
name|HB_SCRIPT_PHOENICIAN
init|=
name|HB_TAG
argument_list|(
literal|'P'
argument_list|,
literal|'h'
argument_list|,
literal|'n'
argument_list|,
literal|'x'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_CARIAN
comment|/*5.1*/
name|HB_SCRIPT_CARIAN
init|=
name|HB_TAG
argument_list|(
literal|'C'
argument_list|,
literal|'a'
argument_list|,
literal|'r'
argument_list|,
literal|'i'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_CHAM
comment|/*5.1*/
name|HB_SCRIPT_CHAM
init|=
name|HB_TAG
argument_list|(
literal|'C'
argument_list|,
literal|'h'
argument_list|,
literal|'a'
argument_list|,
literal|'m'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_KAYAH_LI
comment|/*5.1*/
name|HB_SCRIPT_KAYAH_LI
init|=
name|HB_TAG
argument_list|(
literal|'K'
argument_list|,
literal|'a'
argument_list|,
literal|'l'
argument_list|,
literal|'i'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_LEPCHA
comment|/*5.1*/
name|HB_SCRIPT_LEPCHA
init|=
name|HB_TAG
argument_list|(
literal|'L'
argument_list|,
literal|'e'
argument_list|,
literal|'p'
argument_list|,
literal|'c'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_LYCIAN
comment|/*5.1*/
name|HB_SCRIPT_LYCIAN
init|=
name|HB_TAG
argument_list|(
literal|'L'
argument_list|,
literal|'y'
argument_list|,
literal|'c'
argument_list|,
literal|'i'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_LYDIAN
comment|/*5.1*/
name|HB_SCRIPT_LYDIAN
init|=
name|HB_TAG
argument_list|(
literal|'L'
argument_list|,
literal|'y'
argument_list|,
literal|'d'
argument_list|,
literal|'i'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_OL_CHIKI
comment|/*5.1*/
name|HB_SCRIPT_OL_CHIKI
init|=
name|HB_TAG
argument_list|(
literal|'O'
argument_list|,
literal|'l'
argument_list|,
literal|'c'
argument_list|,
literal|'k'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_REJANG
comment|/*5.1*/
name|HB_SCRIPT_REJANG
init|=
name|HB_TAG
argument_list|(
literal|'R'
argument_list|,
literal|'j'
argument_list|,
literal|'n'
argument_list|,
literal|'g'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_SAURASHTRA
comment|/*5.1*/
name|HB_SCRIPT_SAURASHTRA
init|=
name|HB_TAG
argument_list|(
literal|'S'
argument_list|,
literal|'a'
argument_list|,
literal|'u'
argument_list|,
literal|'r'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_SUNDANESE
comment|/*5.1*/
name|HB_SCRIPT_SUNDANESE
init|=
name|HB_TAG
argument_list|(
literal|'S'
argument_list|,
literal|'u'
argument_list|,
literal|'n'
argument_list|,
literal|'d'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_VAI
comment|/*5.1*/
name|HB_SCRIPT_VAI
init|=
name|HB_TAG
argument_list|(
literal|'V'
argument_list|,
literal|'a'
argument_list|,
literal|'i'
argument_list|,
literal|'i'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_AVESTAN
comment|/*5.2*/
name|HB_SCRIPT_AVESTAN
init|=
name|HB_TAG
argument_list|(
literal|'A'
argument_list|,
literal|'v'
argument_list|,
literal|'s'
argument_list|,
literal|'t'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_BAMUM
comment|/*5.2*/
name|HB_SCRIPT_BAMUM
init|=
name|HB_TAG
argument_list|(
literal|'B'
argument_list|,
literal|'a'
argument_list|,
literal|'m'
argument_list|,
literal|'u'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_EGYPTIAN_HIEROGLYPHS
comment|/*5.2*/
name|HB_SCRIPT_EGYPTIAN_HIEROGLYPHS
init|=
name|HB_TAG
argument_list|(
literal|'E'
argument_list|,
literal|'g'
argument_list|,
literal|'y'
argument_list|,
literal|'p'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_IMPERIAL_ARAMAIC
comment|/*5.2*/
name|HB_SCRIPT_IMPERIAL_ARAMAIC
init|=
name|HB_TAG
argument_list|(
literal|'A'
argument_list|,
literal|'r'
argument_list|,
literal|'m'
argument_list|,
literal|'i'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_INSCRIPTIONAL_PAHLAVI
comment|/*5.2*/
name|HB_SCRIPT_INSCRIPTIONAL_PAHLAVI
init|=
name|HB_TAG
argument_list|(
literal|'P'
argument_list|,
literal|'h'
argument_list|,
literal|'l'
argument_list|,
literal|'i'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_INSCRIPTIONAL_PARTHIAN
comment|/*5.2*/
name|HB_SCRIPT_INSCRIPTIONAL_PARTHIAN
init|=
name|HB_TAG
argument_list|(
literal|'P'
argument_list|,
literal|'r'
argument_list|,
literal|'t'
argument_list|,
literal|'i'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_JAVANESE
comment|/*5.2*/
name|HB_SCRIPT_JAVANESE
init|=
name|HB_TAG
argument_list|(
literal|'J'
argument_list|,
literal|'a'
argument_list|,
literal|'v'
argument_list|,
literal|'a'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_KAITHI
comment|/*5.2*/
name|HB_SCRIPT_KAITHI
init|=
name|HB_TAG
argument_list|(
literal|'K'
argument_list|,
literal|'t'
argument_list|,
literal|'h'
argument_list|,
literal|'i'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_LISU
comment|/*5.2*/
name|HB_SCRIPT_LISU
init|=
name|HB_TAG
argument_list|(
literal|'L'
argument_list|,
literal|'i'
argument_list|,
literal|'s'
argument_list|,
literal|'u'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_MEETEI_MAYEK
comment|/*5.2*/
name|HB_SCRIPT_MEETEI_MAYEK
init|=
name|HB_TAG
argument_list|(
literal|'M'
argument_list|,
literal|'t'
argument_list|,
literal|'e'
argument_list|,
literal|'i'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_OLD_SOUTH_ARABIAN
comment|/*5.2*/
name|HB_SCRIPT_OLD_SOUTH_ARABIAN
init|=
name|HB_TAG
argument_list|(
literal|'S'
argument_list|,
literal|'a'
argument_list|,
literal|'r'
argument_list|,
literal|'b'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_OLD_TURKIC
comment|/*5.2*/
name|HB_SCRIPT_OLD_TURKIC
init|=
name|HB_TAG
argument_list|(
literal|'O'
argument_list|,
literal|'r'
argument_list|,
literal|'k'
argument_list|,
literal|'h'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_SAMARITAN
comment|/*5.2*/
name|HB_SCRIPT_SAMARITAN
init|=
name|HB_TAG
argument_list|(
literal|'S'
argument_list|,
literal|'a'
argument_list|,
literal|'m'
argument_list|,
literal|'r'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_TAI_THAM
comment|/*5.2*/
name|HB_SCRIPT_TAI_THAM
init|=
name|HB_TAG
argument_list|(
literal|'L'
argument_list|,
literal|'a'
argument_list|,
literal|'n'
argument_list|,
literal|'a'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_TAI_VIET
comment|/*5.2*/
name|HB_SCRIPT_TAI_VIET
init|=
name|HB_TAG
argument_list|(
literal|'T'
argument_list|,
literal|'a'
argument_list|,
literal|'v'
argument_list|,
literal|'t'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_BATAK
comment|/*6.0*/
name|HB_SCRIPT_BATAK
init|=
name|HB_TAG
argument_list|(
literal|'B'
argument_list|,
literal|'a'
argument_list|,
literal|'t'
argument_list|,
literal|'k'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_BRAHMI
comment|/*6.0*/
name|HB_SCRIPT_BRAHMI
init|=
name|HB_TAG
argument_list|(
literal|'B'
argument_list|,
literal|'r'
argument_list|,
literal|'a'
argument_list|,
literal|'h'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_MANDAIC
comment|/*6.0*/
name|HB_SCRIPT_MANDAIC
init|=
name|HB_TAG
argument_list|(
literal|'M'
argument_list|,
literal|'a'
argument_list|,
literal|'n'
argument_list|,
literal|'d'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_CHAKMA
comment|/*6.1*/
name|HB_SCRIPT_CHAKMA
init|=
name|HB_TAG
argument_list|(
literal|'C'
argument_list|,
literal|'a'
argument_list|,
literal|'k'
argument_list|,
literal|'m'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_MEROITIC_CURSIVE
comment|/*6.1*/
name|HB_SCRIPT_MEROITIC_CURSIVE
init|=
name|HB_TAG
argument_list|(
literal|'M'
argument_list|,
literal|'e'
argument_list|,
literal|'r'
argument_list|,
literal|'c'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_MEROITIC_HIEROGLYPHS
comment|/*6.1*/
name|HB_SCRIPT_MEROITIC_HIEROGLYPHS
init|=
name|HB_TAG
argument_list|(
literal|'M'
argument_list|,
literal|'e'
argument_list|,
literal|'r'
argument_list|,
literal|'o'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_MIAO
comment|/*6.1*/
name|HB_SCRIPT_MIAO
init|=
name|HB_TAG
argument_list|(
literal|'P'
argument_list|,
literal|'l'
argument_list|,
literal|'r'
argument_list|,
literal|'d'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_SHARADA
comment|/*6.1*/
name|HB_SCRIPT_SHARADA
init|=
name|HB_TAG
argument_list|(
literal|'S'
argument_list|,
literal|'h'
argument_list|,
literal|'r'
argument_list|,
literal|'d'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_SORA_SOMPENG
comment|/*6.1*/
name|HB_SCRIPT_SORA_SOMPENG
init|=
name|HB_TAG
argument_list|(
literal|'S'
argument_list|,
literal|'o'
argument_list|,
literal|'r'
argument_list|,
literal|'a'
argument_list|)
block|,
DECL|enumerator|HB_SCRIPT_TAKRI
comment|/*6.1*/
name|HB_SCRIPT_TAKRI
init|=
name|HB_TAG
argument_list|(
literal|'T'
argument_list|,
literal|'a'
argument_list|,
literal|'k'
argument_list|,
literal|'r'
argument_list|)
block|,
comment|/* No script set. */
DECL|enumerator|HB_SCRIPT_INVALID
comment|/*---*/
name|HB_SCRIPT_INVALID
init|=
name|HB_TAG_NONE
block|,
comment|/* Dummy value to ensure any hb_tag_t value can be passed/stored as hb_script_t    * without risking undefined behavior. */
DECL|enumerator|_HB_SCRIPT_MAX_VALUE
comment|/*---*/
name|_HB_SCRIPT_MAX_VALUE
init|=
name|HB_TAG_MAX
block|}
DECL|typedef|hb_script_t
name|hb_script_t
typedef|;
end_typedef
begin_comment
comment|/* These are moved out of hb_script_t because glib-mkenums chokes otherwise. */
end_comment
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_BASSA_VAH			= HB_TAG ('B','a','s','s'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_CAUCASIAN_ALBANIAN		= HB_TAG ('A','g','h','b'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_DUPLOYAN			= HB_TAG ('D','u','p','l'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_ELBASAN			= HB_TAG ('E','l','b','a'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_GRANTHA			= HB_TAG ('G','r','a','n'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_KHOJKI			= HB_TAG ('K','h','o','j'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_KHUDAWADI			= HB_TAG ('S','i','n','d'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_LINEAR_A			= HB_TAG ('L','i','n','a'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_MAHAJANI			= HB_TAG ('M','a','h','j'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_MANICHAEAN			= HB_TAG ('M','a','n','i'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_MENDE_KIKAKUI		= HB_TAG ('M','e','n','d'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_MODI			= ???
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_MRO				= HB_TAG ('M','r','o','o'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_NABATAEAN			= HB_TAG ('N','b','a','t'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_OLD_NORTH_ARABIAN		= HB_TAG ('N','a','r','b'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_OLD_PERMIC			= HB_TAG ('P','e','r','m'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_PAHAWH_HMONG		= HB_TAG ('H','m','n','g'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_PALMYRENE			= HB_TAG ('P','a','l','m'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_PAU_CIN_HAU			= ???
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_PSALTER_PAHLAVI		= HB_TAG ('P','h','l','p'),
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_SIDDHAM			= ???
comment|/*7.0*/
end_comment
begin_comment
unit|HB_SCRIPT_TIRHUTA			= HB_TAG ('T','i','r','h'),
comment|/*7.0*/
end_comment
begin_endif
unit|HB_SCRIPT_WARANG_CITI			= HB_TAG ('W','a','r','a'),
endif|#
directive|endif
end_endif
begin_comment
comment|/* Script functions */
end_comment
begin_function_decl
name|hb_script_t
name|hb_script_from_iso15924_tag
parameter_list|(
name|hb_tag_t
name|tag
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* suger for tag_from_string() then script_from_iso15924_tag */
end_comment
begin_comment
comment|/* len=-1 means s is NUL-terminated */
end_comment
begin_function_decl
name|hb_script_t
name|hb_script_from_string
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_tag_t
name|hb_script_to_iso15924_tag
parameter_list|(
name|hb_script_t
name|script
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_direction_t
name|hb_script_get_horizontal_direction
parameter_list|(
name|hb_script_t
name|script
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* User data */
end_comment
begin_typedef
DECL|struct|hb_user_data_key_t
typedef|typedef
struct|struct
name|hb_user_data_key_t
block|{
comment|/*< private>*/
DECL|member|unused
name|char
name|unused
decl_stmt|;
block|}
DECL|typedef|hb_user_data_key_t
name|hb_user_data_key_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|hb_destroy_func_t
typedef|typedef
name|void
function_decl|(
modifier|*
name|hb_destroy_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_typedef
begin_macro
name|HB_END_DECLS
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* HB_COMMON_H */
end_comment
end_unit
