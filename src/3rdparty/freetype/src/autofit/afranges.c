begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afranges.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter Unicode script ranges (body).                            */
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
begin_include
include|#
directive|include
file|"afranges.h"
end_include
begin_decl_stmt
DECL|variable|af_cyrl_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_cyrl_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0400UL
argument_list|,
literal|0x04FFUL
argument_list|)
block|,
comment|/* Cyrillic            */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0500UL
argument_list|,
literal|0x052FUL
argument_list|)
block|,
comment|/* Cyrillic Supplement */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x2DE0UL
argument_list|,
literal|0x2DFFUL
argument_list|)
block|,
comment|/* Cyrillic Extended-A */
name|AF_UNIRANGE_REC
argument_list|(
literal|0xA640UL
argument_list|,
literal|0xA69FUL
argument_list|)
block|,
comment|/* Cyrillic Extended-B */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* there are some characters in the Devanagari Unicode block that are    */
end_comment
begin_comment
comment|/* generic to Indic scripts; we omit them so that their presence doesn't */
end_comment
begin_comment
comment|/* trigger Devanagari                                                    */
end_comment
begin_decl_stmt
DECL|variable|af_deva_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_deva_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0900UL
argument_list|,
literal|0x093BUL
argument_list|)
block|,
comment|/* Devanagari       */
comment|/* omitting U+093C nukta */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x093DUL
argument_list|,
literal|0x0950UL
argument_list|)
block|,
comment|/* omitting U+0951 udatta, U+0952 anudatta */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0953UL
argument_list|,
literal|0x0963UL
argument_list|)
block|,
comment|/* omitting U+0964 danda, U+0965 double danda */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0966UL
argument_list|,
literal|0x097FUL
argument_list|)
block|,
name|AF_UNIRANGE_REC
argument_list|(
literal|0x20B9UL
argument_list|,
literal|0x20B9UL
argument_list|)
block|,
comment|/* (new) Rupee sign */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|af_grek_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_grek_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0370UL
argument_list|,
literal|0x03FFUL
argument_list|)
block|,
comment|/* Greek and Coptic */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x1F00UL
argument_list|,
literal|0x1FFFUL
argument_list|)
block|,
comment|/* Greek Extended   */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|af_hebr_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_hebr_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0590UL
argument_list|,
literal|0x05FFUL
argument_list|)
block|,
comment|/* Hebrew                          */
name|AF_UNIRANGE_REC
argument_list|(
literal|0xFB1DUL
argument_list|,
literal|0xFB4FUL
argument_list|)
block|,
comment|/* Alphab. Present. Forms (Hebrew) */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|af_latn_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_latn_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0020UL
argument_list|,
literal|0x007FUL
argument_list|)
block|,
comment|/* Basic Latin (no control chars)         */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x00A0UL
argument_list|,
literal|0x00FFUL
argument_list|)
block|,
comment|/* Latin-1 Supplement (no control chars)  */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0100UL
argument_list|,
literal|0x017FUL
argument_list|)
block|,
comment|/* Latin Extended-A                       */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0180UL
argument_list|,
literal|0x024FUL
argument_list|)
block|,
comment|/* Latin Extended-B                       */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0250UL
argument_list|,
literal|0x02AFUL
argument_list|)
block|,
comment|/* IPA Extensions                         */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x02B0UL
argument_list|,
literal|0x02FFUL
argument_list|)
block|,
comment|/* Spacing Modifier Letters               */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0300UL
argument_list|,
literal|0x036FUL
argument_list|)
block|,
comment|/* Combining Diacritical Marks            */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x1D00UL
argument_list|,
literal|0x1D7FUL
argument_list|)
block|,
comment|/* Phonetic Extensions                    */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x1D80UL
argument_list|,
literal|0x1DBFUL
argument_list|)
block|,
comment|/* Phonetic Extensions Supplement         */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x1DC0UL
argument_list|,
literal|0x1DFFUL
argument_list|)
block|,
comment|/* Combining Diacritical Marks Supplement */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x1E00UL
argument_list|,
literal|0x1EFFUL
argument_list|)
block|,
comment|/* Latin Extended Additional              */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x2000UL
argument_list|,
literal|0x206FUL
argument_list|)
block|,
comment|/* General Punctuation                    */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x2070UL
argument_list|,
literal|0x209FUL
argument_list|)
block|,
comment|/* Superscripts and Subscripts            */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x20A0UL
argument_list|,
literal|0x20B8UL
argument_list|)
block|,
comment|/* Currency Symbols ...                   */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x20BAUL
argument_list|,
literal|0x20CFUL
argument_list|)
block|,
comment|/* ... except new Rupee sign              */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x2150UL
argument_list|,
literal|0x218FUL
argument_list|)
block|,
comment|/* Number Forms                           */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x2460UL
argument_list|,
literal|0x24FFUL
argument_list|)
block|,
comment|/* Enclosed Alphanumerics                 */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x2C60UL
argument_list|,
literal|0x2C7FUL
argument_list|)
block|,
comment|/* Latin Extended-C                       */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x2E00UL
argument_list|,
literal|0x2E7FUL
argument_list|)
block|,
comment|/* Supplemental Punctuation               */
name|AF_UNIRANGE_REC
argument_list|(
literal|0xA720UL
argument_list|,
literal|0xA7FFUL
argument_list|)
block|,
comment|/* Latin Extended-D                       */
name|AF_UNIRANGE_REC
argument_list|(
literal|0xFB00UL
argument_list|,
literal|0xFB06UL
argument_list|)
block|,
comment|/* Alphab. Present. Forms (Latin Ligs)    */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x1D400UL
argument_list|,
literal|0x1D7FFUL
argument_list|)
block|,
comment|/* Mathematical Alphanumeric Symbols      */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x1F100UL
argument_list|,
literal|0x1F1FFUL
argument_list|)
block|,
comment|/* Enclosed Alphanumeric Supplement       */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|af_none_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_none_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|af_telu_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_telu_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0C00UL
argument_list|,
literal|0x0C7FUL
argument_list|)
block|,
comment|/* Telugu */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|AF_CONFIG_OPTION_INDIC
end_ifdef
begin_decl_stmt
DECL|variable|af_beng_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_beng_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0980UL
argument_list|,
literal|0x09FFUL
argument_list|)
block|,
comment|/* Bengali */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|af_gujr_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_gujr_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0A80UL
argument_list|,
literal|0x0AFFUL
argument_list|)
block|,
comment|/* Gujarati */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|af_guru_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_guru_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0A00UL
argument_list|,
literal|0x0A7FUL
argument_list|)
block|,
comment|/* Gurmukhi */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|af_knda_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_knda_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0C80UL
argument_list|,
literal|0x0CFFUL
argument_list|)
block|,
comment|/* Kannada */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|af_limb_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_limb_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x1900UL
argument_list|,
literal|0x194FUL
argument_list|)
block|,
comment|/* Limbu */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|af_mlym_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_mlym_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0D00UL
argument_list|,
literal|0x0D7FUL
argument_list|)
block|,
comment|/* Malayalam */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|af_orya_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_orya_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0B00UL
argument_list|,
literal|0x0B7FUL
argument_list|)
block|,
comment|/* Oriya */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|af_sinh_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_sinh_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0D80UL
argument_list|,
literal|0x0DFFUL
argument_list|)
block|,
comment|/* Sinhala */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|af_sund_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_sund_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x1B80UL
argument_list|,
literal|0x1BBFUL
argument_list|)
block|,
comment|/* Sundanese */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|af_sylo_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_sylo_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0xA800UL
argument_list|,
literal|0xA82FUL
argument_list|)
block|,
comment|/* Syloti Nagri */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|af_taml_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_taml_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0B80UL
argument_list|,
literal|0x0BFFUL
argument_list|)
block|,
comment|/* Tamil */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|af_tibt_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_tibt_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0F00UL
argument_list|,
literal|0x0FFFUL
argument_list|)
block|,
comment|/* Tibetan */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !AF_CONFIG_OPTION_INDIC */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|AF_CONFIG_OPTION_CJK
end_ifdef
begin_comment
comment|/* this corresponds to Unicode 6.0 */
end_comment
begin_decl_stmt
DECL|variable|af_hani_uniranges
specifier|const
name|AF_Script_UniRangeRec
name|af_hani_uniranges
index|[]
init|=
block|{
name|AF_UNIRANGE_REC
argument_list|(
literal|0x1100UL
argument_list|,
literal|0x11FFUL
argument_list|)
block|,
comment|/* Hangul Jamo                             */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x2E80UL
argument_list|,
literal|0x2EFFUL
argument_list|)
block|,
comment|/* CJK Radicals Supplement                 */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x2F00UL
argument_list|,
literal|0x2FDFUL
argument_list|)
block|,
comment|/* Kangxi Radicals                         */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x2FF0UL
argument_list|,
literal|0x2FFFUL
argument_list|)
block|,
comment|/* Ideographic Description Characters      */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x3000UL
argument_list|,
literal|0x303FUL
argument_list|)
block|,
comment|/* CJK Symbols and Punctuation             */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x3040UL
argument_list|,
literal|0x309FUL
argument_list|)
block|,
comment|/* Hiragana                                */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x30A0UL
argument_list|,
literal|0x30FFUL
argument_list|)
block|,
comment|/* Katakana                                */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x3100UL
argument_list|,
literal|0x312FUL
argument_list|)
block|,
comment|/* Bopomofo                                */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x3130UL
argument_list|,
literal|0x318FUL
argument_list|)
block|,
comment|/* Hangul Compatibility Jamo               */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x3190UL
argument_list|,
literal|0x319FUL
argument_list|)
block|,
comment|/* Kanbun                                  */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x31A0UL
argument_list|,
literal|0x31BFUL
argument_list|)
block|,
comment|/* Bopomofo Extended                       */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x31C0UL
argument_list|,
literal|0x31EFUL
argument_list|)
block|,
comment|/* CJK Strokes                             */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x31F0UL
argument_list|,
literal|0x31FFUL
argument_list|)
block|,
comment|/* Katakana Phonetic Extensions            */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x3200UL
argument_list|,
literal|0x32FFUL
argument_list|)
block|,
comment|/* Enclosed CJK Letters and Months         */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x3300UL
argument_list|,
literal|0x33FFUL
argument_list|)
block|,
comment|/* CJK Compatibility                       */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x3400UL
argument_list|,
literal|0x4DBFUL
argument_list|)
block|,
comment|/* CJK Unified Ideographs Extension A      */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x4DC0UL
argument_list|,
literal|0x4DFFUL
argument_list|)
block|,
comment|/* Yijing Hexagram Symbols                 */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x4E00UL
argument_list|,
literal|0x9FFFUL
argument_list|)
block|,
comment|/* CJK Unified Ideographs                  */
name|AF_UNIRANGE_REC
argument_list|(
literal|0xA960UL
argument_list|,
literal|0xA97FUL
argument_list|)
block|,
comment|/* Hangul Jamo Extended-A                  */
name|AF_UNIRANGE_REC
argument_list|(
literal|0xAC00UL
argument_list|,
literal|0xD7AFUL
argument_list|)
block|,
comment|/* Hangul Syllables                        */
name|AF_UNIRANGE_REC
argument_list|(
literal|0xD7B0UL
argument_list|,
literal|0xD7FFUL
argument_list|)
block|,
comment|/* Hangul Jamo Extended-B                  */
name|AF_UNIRANGE_REC
argument_list|(
literal|0xF900UL
argument_list|,
literal|0xFAFFUL
argument_list|)
block|,
comment|/* CJK Compatibility Ideographs            */
name|AF_UNIRANGE_REC
argument_list|(
literal|0xFE10UL
argument_list|,
literal|0xFE1FUL
argument_list|)
block|,
comment|/* Vertical forms                          */
name|AF_UNIRANGE_REC
argument_list|(
literal|0xFE30UL
argument_list|,
literal|0xFE4FUL
argument_list|)
block|,
comment|/* CJK Compatibility Forms                 */
name|AF_UNIRANGE_REC
argument_list|(
literal|0xFF00UL
argument_list|,
literal|0xFFEFUL
argument_list|)
block|,
comment|/* Halfwidth and Fullwidth Forms           */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x1B000UL
argument_list|,
literal|0x1B0FFUL
argument_list|)
block|,
comment|/* Kana Supplement                         */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x1D300UL
argument_list|,
literal|0x1D35FUL
argument_list|)
block|,
comment|/* Tai Xuan Hing Symbols                   */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x1F200UL
argument_list|,
literal|0x1F2FFUL
argument_list|)
block|,
comment|/* Enclosed Ideographic Supplement         */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x20000UL
argument_list|,
literal|0x2A6DFUL
argument_list|)
block|,
comment|/* CJK Unified Ideographs Extension B      */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x2A700UL
argument_list|,
literal|0x2B73FUL
argument_list|)
block|,
comment|/* CJK Unified Ideographs Extension C      */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x2B740UL
argument_list|,
literal|0x2B81FUL
argument_list|)
block|,
comment|/* CJK Unified Ideographs Extension D      */
name|AF_UNIRANGE_REC
argument_list|(
literal|0x2F800UL
argument_list|,
literal|0x2FA1FUL
argument_list|)
block|,
comment|/* CJK Compatibility Ideographs Supplement */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !AF_CONFIG_OPTION_CJK */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
