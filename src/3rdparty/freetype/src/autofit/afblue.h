begin_unit
begin_comment
comment|/* This file has been generated by the Perl script `afblue.pl', */
end_comment
begin_comment
comment|/* using data from file `afblue.dat'.                           */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afblue.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter data for blue strings (specification).                   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2013, 2014 by                                                */
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
begin_ifndef
ifndef|#
directive|ifndef
name|__AFBLUE_H__
end_ifndef
begin_define
DECL|macro|__AFBLUE_H__
define|#
directive|define
name|__AFBLUE_H__
end_define
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/* an auxiliary macro to decode a UTF-8 character -- since we only use */
end_comment
begin_comment
comment|/* hard-coded, self-converted data, no error checking is performed     */
end_comment
begin_define
DECL|macro|GET_UTF8_CHAR
define|#
directive|define
name|GET_UTF8_CHAR
parameter_list|(
name|ch
parameter_list|,
name|p
parameter_list|)
define|\
value|ch = (unsigned char)*p++;               \           if ( ch>= 0x80 )                       \           {                                       \             FT_UInt  len;                         \                                                   \                                                   \             if ( ch< 0xE0 )                      \             {                                     \               len = 1;                            \               ch&= 0x1F;                         \             }                                     \             else if ( ch< 0xF0 )                 \             {                                     \               len = 2;                            \               ch&= 0x0F;                         \             }                                     \             else                                  \             {                                     \               len = 3;                            \               ch&= 0x07;                         \             }                                     \                                                   \             for ( ; len> 0; len-- )              \               ch = ( ch<< 6 ) | ( *p++& 0x3F ); \           }
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
comment|/*****                    B L U E   S T R I N G S                    *****/
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
comment|/* At the bottommost level, we define strings for finding blue zones. */
end_comment
begin_define
DECL|macro|AF_BLUE_STRING_MAX_LEN
define|#
directive|define
name|AF_BLUE_STRING_MAX_LEN
value|51
end_define
begin_comment
comment|/* The AF_Blue_String enumeration values are offsets into the */
end_comment
begin_comment
comment|/* `af_blue_strings' array.                                   */
end_comment
begin_typedef
DECL|enum|AF_Blue_String_
typedef|typedef
enum|enum
name|AF_Blue_String_
block|{
DECL|enumerator|AF_BLUE_STRING_CYRILLIC_CAPITAL_TOP
name|AF_BLUE_STRING_CYRILLIC_CAPITAL_TOP
init|=
literal|0
block|,
DECL|enumerator|AF_BLUE_STRING_CYRILLIC_CAPITAL_BOTTOM
name|AF_BLUE_STRING_CYRILLIC_CAPITAL_BOTTOM
init|=
literal|17
block|,
DECL|enumerator|AF_BLUE_STRING_CYRILLIC_SMALL
name|AF_BLUE_STRING_CYRILLIC_SMALL
init|=
literal|34
block|,
DECL|enumerator|AF_BLUE_STRING_CYRILLIC_SMALL_DESCENDER
name|AF_BLUE_STRING_CYRILLIC_SMALL_DESCENDER
init|=
literal|51
block|,
DECL|enumerator|AF_BLUE_STRING_DEVANAGARI_BASE
name|AF_BLUE_STRING_DEVANAGARI_BASE
init|=
literal|58
block|,
DECL|enumerator|AF_BLUE_STRING_DEVANAGARI_TOP
name|AF_BLUE_STRING_DEVANAGARI_TOP
init|=
literal|83
block|,
DECL|enumerator|AF_BLUE_STRING_DEVANAGARI_HEAD
name|AF_BLUE_STRING_DEVANAGARI_HEAD
init|=
literal|108
block|,
DECL|enumerator|AF_BLUE_STRING_DEVANAGARI_BOTTOM
name|AF_BLUE_STRING_DEVANAGARI_BOTTOM
init|=
literal|133
block|,
DECL|enumerator|AF_BLUE_STRING_GREEK_CAPITAL_TOP
name|AF_BLUE_STRING_GREEK_CAPITAL_TOP
init|=
literal|140
block|,
DECL|enumerator|AF_BLUE_STRING_GREEK_CAPITAL_BOTTOM
name|AF_BLUE_STRING_GREEK_CAPITAL_BOTTOM
init|=
literal|155
block|,
DECL|enumerator|AF_BLUE_STRING_GREEK_SMALL_BETA_TOP
name|AF_BLUE_STRING_GREEK_SMALL_BETA_TOP
init|=
literal|168
block|,
DECL|enumerator|AF_BLUE_STRING_GREEK_SMALL
name|AF_BLUE_STRING_GREEK_SMALL
init|=
literal|181
block|,
DECL|enumerator|AF_BLUE_STRING_GREEK_SMALL_DESCENDER
name|AF_BLUE_STRING_GREEK_SMALL_DESCENDER
init|=
literal|198
block|,
DECL|enumerator|AF_BLUE_STRING_HEBREW_TOP
name|AF_BLUE_STRING_HEBREW_TOP
init|=
literal|215
block|,
DECL|enumerator|AF_BLUE_STRING_HEBREW_BOTTOM
name|AF_BLUE_STRING_HEBREW_BOTTOM
init|=
literal|232
block|,
DECL|enumerator|AF_BLUE_STRING_HEBREW_DESCENDER
name|AF_BLUE_STRING_HEBREW_DESCENDER
init|=
literal|245
block|,
DECL|enumerator|AF_BLUE_STRING_LATIN_CAPITAL_TOP
name|AF_BLUE_STRING_LATIN_CAPITAL_TOP
init|=
literal|256
block|,
DECL|enumerator|AF_BLUE_STRING_LATIN_CAPITAL_BOTTOM
name|AF_BLUE_STRING_LATIN_CAPITAL_BOTTOM
init|=
literal|265
block|,
DECL|enumerator|AF_BLUE_STRING_LATIN_SMALL_F_TOP
name|AF_BLUE_STRING_LATIN_SMALL_F_TOP
init|=
literal|274
block|,
DECL|enumerator|AF_BLUE_STRING_LATIN_SMALL
name|AF_BLUE_STRING_LATIN_SMALL
init|=
literal|282
block|,
DECL|enumerator|AF_BLUE_STRING_LATIN_SMALL_DESCENDER
name|AF_BLUE_STRING_LATIN_SMALL_DESCENDER
init|=
literal|290
block|,
DECL|enumerator|AF_BLUE_STRING_TELUGU_TOP
name|AF_BLUE_STRING_TELUGU_TOP
init|=
literal|296
block|,
DECL|enumerator|AF_BLUE_STRING_TELUGU_BOTTOM
name|AF_BLUE_STRING_TELUGU_BOTTOM
init|=
literal|318
block|,
DECL|enumerator|af_blue_1_1
name|af_blue_1_1
init|=
literal|339
block|,
ifdef|#
directive|ifdef
name|AF_CONFIG_OPTION_CJK
DECL|enumerator|AF_BLUE_STRING_CJK_TOP
name|AF_BLUE_STRING_CJK_TOP
init|=
name|af_blue_1_1
operator|+
literal|1
block|,
DECL|enumerator|AF_BLUE_STRING_CJK_BOTTOM
name|AF_BLUE_STRING_CJK_BOTTOM
init|=
name|af_blue_1_1
operator|+
literal|153
block|,
DECL|enumerator|af_blue_1_1_1
name|af_blue_1_1_1
init|=
name|af_blue_1_1
operator|+
literal|304
block|,
ifdef|#
directive|ifdef
name|AF_CONFIG_OPTION_CJK_BLUE_HANI_VERT
DECL|enumerator|AF_BLUE_STRING_CJK_LEFT
name|AF_BLUE_STRING_CJK_LEFT
init|=
name|af_blue_1_1_1
operator|+
literal|1
block|,
DECL|enumerator|AF_BLUE_STRING_CJK_RIGHT
name|AF_BLUE_STRING_CJK_RIGHT
init|=
name|af_blue_1_1_1
operator|+
literal|153
block|,
DECL|enumerator|af_blue_1_1_2
name|af_blue_1_1_2
init|=
name|af_blue_1_1_1
operator|+
literal|304
block|,
else|#
directive|else
name|af_blue_1_1_2
init|=
name|af_blue_1_1_1
operator|+
literal|0
block|,
endif|#
directive|endif
comment|/* AF_CONFIG_OPTION_CJK_BLUE_HANI_VERT */
DECL|enumerator|af_blue_1_2
name|af_blue_1_2
init|=
name|af_blue_1_1_2
operator|+
literal|0
block|,
else|#
directive|else
name|af_blue_1_2
init|=
name|af_blue_1_1
operator|+
literal|0
block|,
endif|#
directive|endif
comment|/* AF_CONFIG_OPTION_CJK                */
DECL|enumerator|AF_BLUE_STRING_MAX
name|AF_BLUE_STRING_MAX
comment|/* do not remove */
block|}
DECL|typedef|AF_Blue_String
name|AF_Blue_String
typedef|;
end_typedef
begin_macro
name|FT_LOCAL_ARRAY
argument_list|(
argument|char
argument_list|)
end_macro
begin_expr_stmt
name|af_blue_strings
index|[]
expr_stmt|;
end_expr_stmt
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
comment|/*****                 B L U E   S T R I N G S E T S                 *****/
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
comment|/* The next level is to group blue strings into style-specific sets. */
end_comment
begin_comment
comment|/* Properties are specific to a writing system.  We assume that a given  */
end_comment
begin_comment
comment|/* blue string can't be used in more than a single writing system, which */
end_comment
begin_comment
comment|/* is a safe bet.                                                        */
end_comment
begin_define
DECL|macro|AF_BLUE_PROPERTY_LATIN_TOP
define|#
directive|define
name|AF_BLUE_PROPERTY_LATIN_TOP
value|( 1<< 0 )
end_define
begin_comment
DECL|macro|AF_BLUE_PROPERTY_LATIN_TOP
comment|/* must have value 1 */
end_comment
begin_define
DECL|macro|AF_BLUE_PROPERTY_LATIN_NEUTRAL
define|#
directive|define
name|AF_BLUE_PROPERTY_LATIN_NEUTRAL
value|( 1<< 1 )
end_define
begin_define
DECL|macro|AF_BLUE_PROPERTY_LATIN_X_HEIGHT
define|#
directive|define
name|AF_BLUE_PROPERTY_LATIN_X_HEIGHT
value|( 1<< 2 )
end_define
begin_define
DECL|macro|AF_BLUE_PROPERTY_LATIN_LONG
define|#
directive|define
name|AF_BLUE_PROPERTY_LATIN_LONG
value|( 1<< 3 )
end_define
begin_define
DECL|macro|AF_BLUE_PROPERTY_CJK_TOP
define|#
directive|define
name|AF_BLUE_PROPERTY_CJK_TOP
value|( 1<< 0 )
end_define
begin_comment
DECL|macro|AF_BLUE_PROPERTY_CJK_TOP
comment|/* must have value 1 */
end_comment
begin_define
DECL|macro|AF_BLUE_PROPERTY_CJK_HORIZ
define|#
directive|define
name|AF_BLUE_PROPERTY_CJK_HORIZ
value|( 1<< 1 )
end_define
begin_comment
DECL|macro|AF_BLUE_PROPERTY_CJK_HORIZ
comment|/* must have value 2 */
end_comment
begin_define
DECL|macro|AF_BLUE_PROPERTY_CJK_RIGHT
define|#
directive|define
name|AF_BLUE_PROPERTY_CJK_RIGHT
value|AF_BLUE_PROPERTY_CJK_TOP
end_define
begin_define
DECL|macro|AF_BLUE_STRINGSET_MAX_LEN
define|#
directive|define
name|AF_BLUE_STRINGSET_MAX_LEN
value|7
end_define
begin_comment
comment|/* The AF_Blue_Stringset enumeration values are offsets into the */
end_comment
begin_comment
comment|/* `af_blue_stringsets' array.                                   */
end_comment
begin_typedef
DECL|enum|AF_Blue_Stringset_
typedef|typedef
enum|enum
name|AF_Blue_Stringset_
block|{
DECL|enumerator|AF_BLUE_STRINGSET_CYRL
name|AF_BLUE_STRINGSET_CYRL
init|=
literal|0
block|,
DECL|enumerator|AF_BLUE_STRINGSET_DEVA
name|AF_BLUE_STRINGSET_DEVA
init|=
literal|6
block|,
DECL|enumerator|AF_BLUE_STRINGSET_GREK
name|AF_BLUE_STRINGSET_GREK
init|=
literal|12
block|,
DECL|enumerator|AF_BLUE_STRINGSET_HEBR
name|AF_BLUE_STRINGSET_HEBR
init|=
literal|19
block|,
DECL|enumerator|AF_BLUE_STRINGSET_LATN
name|AF_BLUE_STRINGSET_LATN
init|=
literal|23
block|,
DECL|enumerator|AF_BLUE_STRINGSET_TELU
name|AF_BLUE_STRINGSET_TELU
init|=
literal|30
block|,
DECL|enumerator|af_blue_2_1
name|af_blue_2_1
init|=
literal|33
block|,
ifdef|#
directive|ifdef
name|AF_CONFIG_OPTION_CJK
DECL|enumerator|AF_BLUE_STRINGSET_HANI
name|AF_BLUE_STRINGSET_HANI
init|=
name|af_blue_2_1
operator|+
literal|0
block|,
DECL|enumerator|af_blue_2_1_1
name|af_blue_2_1_1
init|=
name|af_blue_2_1
operator|+
literal|2
block|,
ifdef|#
directive|ifdef
name|AF_CONFIG_OPTION_CJK_BLUE_HANI_VERT
DECL|enumerator|af_blue_2_1_2
name|af_blue_2_1_2
init|=
name|af_blue_2_1_1
operator|+
literal|2
block|,
else|#
directive|else
name|af_blue_2_1_2
init|=
name|af_blue_2_1_1
operator|+
literal|0
block|,
endif|#
directive|endif
comment|/* AF_CONFIG_OPTION_CJK_BLUE_HANI_VERT */
DECL|enumerator|af_blue_2_2
name|af_blue_2_2
init|=
name|af_blue_2_1_2
operator|+
literal|1
block|,
else|#
directive|else
name|af_blue_2_2
init|=
name|af_blue_2_1
operator|+
literal|0
block|,
endif|#
directive|endif
comment|/* AF_CONFIG_OPTION_CJK                */
DECL|enumerator|AF_BLUE_STRINGSET_MAX
name|AF_BLUE_STRINGSET_MAX
comment|/* do not remove */
block|}
DECL|typedef|AF_Blue_Stringset
name|AF_Blue_Stringset
typedef|;
end_typedef
begin_typedef
DECL|struct|AF_Blue_StringRec_
typedef|typedef
struct|struct
name|AF_Blue_StringRec_
block|{
DECL|member|string
name|AF_Blue_String
name|string
decl_stmt|;
DECL|member|properties
name|FT_UShort
name|properties
decl_stmt|;
block|}
DECL|typedef|AF_Blue_StringRec
name|AF_Blue_StringRec
typedef|;
end_typedef
begin_macro
name|FT_LOCAL_ARRAY
argument_list|(
argument|AF_Blue_StringRec
argument_list|)
end_macro
begin_expr_stmt
name|af_blue_stringsets
index|[]
expr_stmt|;
end_expr_stmt
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
comment|/* __AFBLUE_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
