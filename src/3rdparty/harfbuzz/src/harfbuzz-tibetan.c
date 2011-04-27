begin_unit
begin_comment
comment|/*  * Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies)  *  * This is part of HarfBuzz, an OpenType Layout engine library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  */
end_comment
begin_include
include|#
directive|include
file|"harfbuzz-shaper.h"
end_include
begin_include
include|#
directive|include
file|"harfbuzz-shaper-private.h"
end_include
begin_include
include|#
directive|include
file|<assert.h>
end_include
begin_comment
comment|/*  tibetan syllables are of the form:     head position consonant     first sub-joined consonant     ....intermediate sub-joined consonants (if any)     last sub-joined consonant     sub-joined vowel (a-chung U+0F71)     standard or compound vowel sign (or 'virama' for devanagari transliteration) */
end_comment
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|TibetanOther
name|TibetanOther
block|,
DECL|enumerator|TibetanHeadConsonant
name|TibetanHeadConsonant
block|,
DECL|enumerator|TibetanSubjoinedConsonant
name|TibetanSubjoinedConsonant
block|,
DECL|enumerator|TibetanSubjoinedVowel
name|TibetanSubjoinedVowel
block|,
DECL|enumerator|TibetanVowel
name|TibetanVowel
block|}
DECL|typedef|TibetanForm
name|TibetanForm
typedef|;
end_typedef
begin_comment
comment|/* this table starts at U+0f40 */
end_comment
begin_decl_stmt
DECL|variable|tibetanForm
specifier|static
specifier|const
name|unsigned
name|char
name|tibetanForm
index|[
literal|0x80
index|]
init|=
block|{
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanHeadConsonant
block|,
name|TibetanOther
block|,
name|TibetanOther
block|,
name|TibetanOther
block|,
name|TibetanOther
block|,
name|TibetanOther
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanVowel
block|,
name|TibetanOther
block|,
name|TibetanOther
block|,
name|TibetanOther
block|,
name|TibetanOther
block|,
name|TibetanOther
block|,
name|TibetanOther
block|,
name|TibetanOther
block|,
name|TibetanOther
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanSubjoinedConsonant
block|,
name|TibetanOther
block|,
name|TibetanOther
block|,
name|TibetanOther
block|}
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|tibetan_form
define|#
directive|define
name|tibetan_form
parameter_list|(
name|c
parameter_list|)
define|\
value|(TibetanForm)tibetanForm[c - 0x0f40]
end_define
begin_decl_stmt
DECL|variable|tibetan_features
specifier|static
specifier|const
name|HB_OpenTypeFeature
name|tibetan_features
index|[]
init|=
block|{
block|{
name|HB_MAKE_TAG
argument_list|(
literal|'c'
argument_list|,
literal|'c'
argument_list|,
literal|'m'
argument_list|,
literal|'p'
argument_list|)
block|,
name|CcmpProperty
block|}
block|,
block|{
name|HB_MAKE_TAG
argument_list|(
literal|'a'
argument_list|,
literal|'b'
argument_list|,
literal|'v'
argument_list|,
literal|'s'
argument_list|)
block|,
name|AboveSubstProperty
block|}
block|,
block|{
name|HB_MAKE_TAG
argument_list|(
literal|'b'
argument_list|,
literal|'l'
argument_list|,
literal|'w'
argument_list|,
literal|'s'
argument_list|)
block|,
name|BelowSubstProperty
block|}
block|,
block|{
name|HB_MAKE_TAG
argument_list|(
literal|'c'
argument_list|,
literal|'a'
argument_list|,
literal|'l'
argument_list|,
literal|'t'
argument_list|)
block|,
name|CaltProperty
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|tibetan_shape_syllable
specifier|static
name|HB_Bool
name|tibetan_shape_syllable
parameter_list|(
name|HB_Bool
name|openType
parameter_list|,
name|HB_ShaperItem
modifier|*
name|item
parameter_list|,
name|HB_Bool
name|invalid
parameter_list|)
block|{
name|hb_uint32
name|i
decl_stmt|;
specifier|const
name|HB_UChar16
modifier|*
name|str
init|=
name|item
operator|->
name|string
operator|+
name|item
operator|->
name|item
operator|.
name|pos
decl_stmt|;
name|int
name|len
init|=
name|item
operator|->
name|item
operator|.
name|length
decl_stmt|;
ifndef|#
directive|ifndef
name|NO_OPENTYPE
specifier|const
name|int
name|availableGlyphs
init|=
name|item
operator|->
name|num_glyphs
decl_stmt|;
endif|#
directive|endif
name|HB_Bool
name|haveGlyphs
decl_stmt|;
name|HB_STACKARRAY
argument_list|(
name|HB_UChar16
argument_list|,
name|reordered
argument_list|,
name|len
operator|+
literal|4
argument_list|)
expr_stmt|;
if|if
condition|(
name|item
operator|->
name|num_glyphs
operator|<
name|item
operator|->
name|item
operator|.
name|length
operator|+
literal|4
condition|)
block|{
name|item
operator|->
name|num_glyphs
operator|=
name|item
operator|->
name|item
operator|.
name|length
operator|+
literal|4
expr_stmt|;
return|return
name|FALSE
return|;
block|}
if|if
condition|(
name|invalid
condition|)
block|{
operator|*
name|reordered
operator|=
literal|0x25cc
expr_stmt|;
name|memcpy
argument_list|(
name|reordered
operator|+
literal|1
argument_list|,
name|str
argument_list|,
name|len
operator|*
sizeof|sizeof
argument_list|(
name|HB_UChar16
argument_list|)
argument_list|)
expr_stmt|;
name|len
operator|++
expr_stmt|;
name|str
operator|=
name|reordered
expr_stmt|;
block|}
name|haveGlyphs
operator|=
name|item
operator|->
name|font
operator|->
name|klass
operator|->
name|convertStringToGlyphIndices
argument_list|(
name|item
operator|->
name|font
argument_list|,
name|str
argument_list|,
name|len
argument_list|,
name|item
operator|->
name|glyphs
argument_list|,
operator|&
name|item
operator|->
name|num_glyphs
argument_list|,
name|item
operator|->
name|item
operator|.
name|bidiLevel
operator|%
literal|2
argument_list|)
expr_stmt|;
name|HB_FREE_STACKARRAY
argument_list|(
name|reordered
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|haveGlyphs
condition|)
return|return
name|FALSE
return|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|item
operator|->
name|item
operator|.
name|length
condition|;
name|i
operator|++
control|)
block|{
name|item
operator|->
name|attributes
index|[
name|i
index|]
operator|.
name|mark
operator|=
name|FALSE
expr_stmt|;
name|item
operator|->
name|attributes
index|[
name|i
index|]
operator|.
name|clusterStart
operator|=
name|FALSE
expr_stmt|;
name|item
operator|->
name|attributes
index|[
name|i
index|]
operator|.
name|justification
operator|=
literal|0
expr_stmt|;
name|item
operator|->
name|attributes
index|[
name|i
index|]
operator|.
name|zeroWidth
operator|=
name|FALSE
expr_stmt|;
comment|/*        IDEBUG("    %d: %4x", i, str[i]); */
block|}
comment|/* now we have the syllable in the right order, and can start running it through open type. */
ifndef|#
directive|ifndef
name|NO_OPENTYPE
if|if
condition|(
name|openType
condition|)
block|{
name|HB_OpenTypeShape
argument_list|(
name|item
argument_list|,
comment|/*properties*/
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|HB_OpenTypePosition
argument_list|(
name|item
argument_list|,
name|availableGlyphs
argument_list|,
comment|/*doLogClusters*/
name|FALSE
argument_list|)
condition|)
return|return
name|FALSE
return|;
block|}
else|else
block|{
name|HB_HeuristicPosition
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|item
operator|->
name|attributes
index|[
literal|0
index|]
operator|.
name|clusterStart
operator|=
name|TRUE
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_function
begin_function
DECL|function|tibetan_nextSyllableBoundary
specifier|static
name|int
name|tibetan_nextSyllableBoundary
parameter_list|(
specifier|const
name|HB_UChar16
modifier|*
name|s
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|,
name|HB_Bool
modifier|*
name|invalid
parameter_list|)
block|{
specifier|const
name|HB_UChar16
modifier|*
name|uc
init|=
name|s
operator|+
name|start
decl_stmt|;
name|int
name|pos
init|=
literal|0
decl_stmt|;
name|TibetanForm
name|state
init|=
name|tibetan_form
argument_list|(
operator|*
name|uc
argument_list|)
decl_stmt|;
comment|/*     qDebug("state[%d]=%d (uc=%4x)", pos, state, uc[pos]);*/
name|pos
operator|++
expr_stmt|;
if|if
condition|(
name|state
operator|!=
name|TibetanHeadConsonant
condition|)
block|{
if|if
condition|(
name|state
operator|!=
name|TibetanOther
condition|)
operator|*
name|invalid
operator|=
name|TRUE
expr_stmt|;
goto|goto
name|finish
goto|;
block|}
while|while
condition|(
name|pos
operator|<
name|end
operator|-
name|start
condition|)
block|{
name|TibetanForm
name|newState
init|=
name|tibetan_form
argument_list|(
name|uc
index|[
name|pos
index|]
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|newState
condition|)
block|{
case|case
name|TibetanSubjoinedConsonant
case|:
case|case
name|TibetanSubjoinedVowel
case|:
if|if
condition|(
name|state
operator|!=
name|TibetanHeadConsonant
operator|&&
name|state
operator|!=
name|TibetanSubjoinedConsonant
condition|)
goto|goto
name|finish
goto|;
name|state
operator|=
name|newState
expr_stmt|;
break|break;
case|case
name|TibetanVowel
case|:
if|if
condition|(
name|state
operator|!=
name|TibetanHeadConsonant
operator|&&
name|state
operator|!=
name|TibetanSubjoinedConsonant
operator|&&
name|state
operator|!=
name|TibetanSubjoinedVowel
condition|)
goto|goto
name|finish
goto|;
break|break;
case|case
name|TibetanOther
case|:
case|case
name|TibetanHeadConsonant
case|:
goto|goto
name|finish
goto|;
block|}
name|pos
operator|++
expr_stmt|;
block|}
name|finish
label|:
operator|*
name|invalid
operator|=
name|FALSE
expr_stmt|;
return|return
name|start
operator|+
name|pos
return|;
block|}
end_function
begin_function
DECL|function|HB_TibetanShape
name|HB_Bool
name|HB_TibetanShape
parameter_list|(
name|HB_ShaperItem
modifier|*
name|item
parameter_list|)
block|{
name|HB_Bool
name|openType
init|=
name|FALSE
decl_stmt|;
name|unsigned
name|short
modifier|*
name|logClusters
init|=
name|item
operator|->
name|log_clusters
decl_stmt|;
name|HB_ShaperItem
name|syllable
init|=
operator|*
name|item
decl_stmt|;
name|int
name|first_glyph
init|=
literal|0
decl_stmt|;
name|int
name|sstart
init|=
name|item
operator|->
name|item
operator|.
name|pos
decl_stmt|;
name|int
name|end
init|=
name|sstart
operator|+
name|item
operator|->
name|item
operator|.
name|length
decl_stmt|;
name|assert
argument_list|(
name|item
operator|->
name|item
operator|.
name|script
operator|==
name|HB_Script_Tibetan
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_OPENTYPE
name|openType
operator|=
name|HB_SelectScript
argument_list|(
name|item
argument_list|,
name|tibetan_features
argument_list|)
expr_stmt|;
endif|#
directive|endif
while|while
condition|(
name|sstart
operator|<
name|end
condition|)
block|{
name|HB_Bool
name|invalid
decl_stmt|;
name|int
name|i
decl_stmt|;
name|int
name|send
init|=
name|tibetan_nextSyllableBoundary
argument_list|(
name|item
operator|->
name|string
argument_list|,
name|sstart
argument_list|,
name|end
argument_list|,
operator|&
name|invalid
argument_list|)
decl_stmt|;
comment|/*        IDEBUG("syllable from %d, length %d, invalid=%s", sstart, send-sstart,                  invalid ? "TRUE" : "FALSE"); */
name|syllable
operator|.
name|item
operator|.
name|pos
operator|=
name|sstart
expr_stmt|;
name|syllable
operator|.
name|item
operator|.
name|length
operator|=
name|send
operator|-
name|sstart
expr_stmt|;
name|syllable
operator|.
name|glyphs
operator|=
name|item
operator|->
name|glyphs
operator|+
name|first_glyph
expr_stmt|;
name|syllable
operator|.
name|attributes
operator|=
name|item
operator|->
name|attributes
operator|+
name|first_glyph
expr_stmt|;
name|syllable
operator|.
name|offsets
operator|=
name|item
operator|->
name|offsets
operator|+
name|first_glyph
expr_stmt|;
name|syllable
operator|.
name|advances
operator|=
name|item
operator|->
name|advances
operator|+
name|first_glyph
expr_stmt|;
name|syllable
operator|.
name|num_glyphs
operator|=
name|item
operator|->
name|num_glyphs
operator|-
name|first_glyph
expr_stmt|;
if|if
condition|(
operator|!
name|tibetan_shape_syllable
argument_list|(
name|openType
argument_list|,
operator|&
name|syllable
argument_list|,
name|invalid
argument_list|)
condition|)
block|{
name|item
operator|->
name|num_glyphs
operator|+=
name|syllable
operator|.
name|num_glyphs
expr_stmt|;
return|return
name|FALSE
return|;
block|}
comment|/* fix logcluster array */
for|for
control|(
name|i
operator|=
name|sstart
init|;
name|i
operator|<
name|send
condition|;
operator|++
name|i
control|)
name|logClusters
index|[
name|i
operator|-
name|item
operator|->
name|item
operator|.
name|pos
index|]
operator|=
name|first_glyph
expr_stmt|;
name|sstart
operator|=
name|send
expr_stmt|;
name|first_glyph
operator|+=
name|syllable
operator|.
name|num_glyphs
expr_stmt|;
block|}
name|item
operator|->
name|num_glyphs
operator|=
name|first_glyph
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_function
begin_function
DECL|function|HB_TibetanAttributes
name|void
name|HB_TibetanAttributes
parameter_list|(
name|HB_Script
name|script
parameter_list|,
specifier|const
name|HB_UChar16
modifier|*
name|text
parameter_list|,
name|hb_uint32
name|from
parameter_list|,
name|hb_uint32
name|len
parameter_list|,
name|HB_CharAttributes
modifier|*
name|attributes
parameter_list|)
block|{
name|int
name|end
init|=
name|from
operator|+
name|len
decl_stmt|;
specifier|const
name|HB_UChar16
modifier|*
name|uc
init|=
name|text
operator|+
name|from
decl_stmt|;
name|hb_uint32
name|i
init|=
literal|0
decl_stmt|;
name|HB_UNUSED
argument_list|(
name|script
argument_list|)
expr_stmt|;
name|attributes
operator|+=
name|from
expr_stmt|;
while|while
condition|(
name|i
operator|<
name|len
condition|)
block|{
name|HB_Bool
name|invalid
decl_stmt|;
name|hb_uint32
name|boundary
init|=
name|tibetan_nextSyllableBoundary
argument_list|(
name|text
argument_list|,
name|from
operator|+
name|i
argument_list|,
name|end
argument_list|,
operator|&
name|invalid
argument_list|)
operator|-
name|from
decl_stmt|;
name|attributes
index|[
name|i
index|]
operator|.
name|charStop
operator|=
name|TRUE
expr_stmt|;
if|if
condition|(
name|boundary
operator|>
name|len
operator|-
literal|1
condition|)
name|boundary
operator|=
name|len
expr_stmt|;
name|i
operator|++
expr_stmt|;
while|while
condition|(
name|i
operator|<
name|boundary
condition|)
block|{
name|attributes
index|[
name|i
index|]
operator|.
name|charStop
operator|=
name|FALSE
expr_stmt|;
operator|++
name|uc
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
name|assert
argument_list|(
name|i
operator|==
name|boundary
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
