begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ttmtx.c                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Load the metrics tables common to TTF and OTF fonts (body).          */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2006, 2007, 2008 by                                          */
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
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_STREAM_H
end_include
begin_include
include|#
directive|include
include|FT_TRUETYPE_TAGS_H
end_include
begin_include
include|#
directive|include
file|"ttmtx.h"
end_include
begin_include
include|#
directive|include
file|"sferrors.h"
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
value|trace_ttmtx
end_define
begin_comment
comment|/*    *  Unfortunately, we can't enable our memory optimizations if    *  FT_CONFIG_OPTION_OLD_INTERNALS is defined.  This is because at least    *  one rogue client (libXfont in the X.Org XServer) is directly accessing    *  the metrics.    */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    tt_face_load_hmtx                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Load the `hmtx' or `vmtx' table into a face object.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face     :: A handle to the target face object.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    stream   :: The input stream.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    vertical :: A boolean flag.  If set, load `vmtx'.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0 means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_OLD_INTERNALS
end_ifndef
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_face_load_hmtx
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_Stream  stream
argument_list|,
argument|FT_Bool    vertical
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|FT_ULong
name|tag
decl_stmt|,
name|table_size
decl_stmt|;
name|FT_ULong
modifier|*
name|ptable_offset
decl_stmt|;
name|FT_ULong
modifier|*
name|ptable_size
decl_stmt|;
if|if
condition|(
name|vertical
condition|)
block|{
name|tag
operator|=
name|TTAG_vmtx
expr_stmt|;
name|ptable_offset
operator|=
operator|&
name|face
operator|->
name|vert_metrics_offset
expr_stmt|;
name|ptable_size
operator|=
operator|&
name|face
operator|->
name|vert_metrics_size
expr_stmt|;
block|}
else|else
block|{
name|tag
operator|=
name|TTAG_hmtx
expr_stmt|;
name|ptable_offset
operator|=
operator|&
name|face
operator|->
name|horz_metrics_offset
expr_stmt|;
name|ptable_size
operator|=
operator|&
name|face
operator|->
name|horz_metrics_size
expr_stmt|;
block|}
name|error
operator|=
name|face
operator|->
name|goto_table
argument_list|(
name|face
argument_list|,
name|tag
argument_list|,
name|stream
argument_list|,
operator|&
name|table_size
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Fail
goto|;
operator|*
name|ptable_size
operator|=
name|table_size
expr_stmt|;
operator|*
name|ptable_offset
operator|=
name|FT_STREAM_POS
argument_list|()
expr_stmt|;
name|Fail
label|:
return|return
name|error
return|;
block|}
end_block
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !FT_CONFIG_OPTION_OLD_INTERNALS */
end_comment
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_face_load_hmtx
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_Stream  stream
argument_list|,
argument|FT_Bool    vertical
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|FT_Memory
name|memory
init|=
name|stream
operator|->
name|memory
decl_stmt|;
name|FT_ULong
name|table_len
decl_stmt|;
name|FT_Long
name|num_shorts
decl_stmt|,
name|num_longs
decl_stmt|,
name|num_shorts_checked
decl_stmt|;
name|TT_LongMetrics
modifier|*
name|longs
decl_stmt|;
name|TT_ShortMetrics
modifier|*
modifier|*
name|shorts
decl_stmt|;
name|FT_Byte
modifier|*
name|p
decl_stmt|;
if|if
condition|(
name|vertical
condition|)
block|{
name|void
modifier|*
name|lm
init|=
operator|&
name|face
operator|->
name|vertical
operator|.
name|long_metrics
decl_stmt|;
name|void
modifier|*
modifier|*
name|sm
init|=
operator|&
name|face
operator|->
name|vertical
operator|.
name|short_metrics
decl_stmt|;
name|error
operator|=
name|face
operator|->
name|goto_table
argument_list|(
name|face
argument_list|,
name|TTAG_vmtx
argument_list|,
name|stream
argument_list|,
operator|&
name|table_len
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Fail
goto|;
name|num_longs
operator|=
name|face
operator|->
name|vertical
operator|.
name|number_Of_VMetrics
expr_stmt|;
if|if
condition|(
operator|(
name|FT_ULong
operator|)
name|num_longs
operator|>
name|table_len
operator|/
literal|4
condition|)
name|num_longs
operator|=
call|(
name|FT_Long
call|)
argument_list|(
name|table_len
operator|/
literal|4
argument_list|)
expr_stmt|;
name|face
operator|->
name|vertical
operator|.
name|number_Of_VMetrics
operator|=
literal|0
expr_stmt|;
name|longs
operator|=
operator|(
name|TT_LongMetrics
operator|*
operator|)
name|lm
expr_stmt|;
name|shorts
operator|=
operator|(
name|TT_ShortMetrics
operator|*
operator|*
operator|)
name|sm
expr_stmt|;
block|}
else|else
block|{
name|void
modifier|*
name|lm
init|=
operator|&
name|face
operator|->
name|horizontal
operator|.
name|long_metrics
decl_stmt|;
name|void
modifier|*
modifier|*
name|sm
init|=
operator|&
name|face
operator|->
name|horizontal
operator|.
name|short_metrics
decl_stmt|;
name|error
operator|=
name|face
operator|->
name|goto_table
argument_list|(
name|face
argument_list|,
name|TTAG_hmtx
argument_list|,
name|stream
argument_list|,
operator|&
name|table_len
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Fail
goto|;
name|num_longs
operator|=
name|face
operator|->
name|horizontal
operator|.
name|number_Of_HMetrics
expr_stmt|;
if|if
condition|(
operator|(
name|FT_ULong
operator|)
name|num_longs
operator|>
name|table_len
operator|/
literal|4
condition|)
name|num_longs
operator|=
call|(
name|FT_Long
call|)
argument_list|(
name|table_len
operator|/
literal|4
argument_list|)
expr_stmt|;
name|face
operator|->
name|horizontal
operator|.
name|number_Of_HMetrics
operator|=
literal|0
expr_stmt|;
name|longs
operator|=
operator|(
name|TT_LongMetrics
operator|*
operator|)
name|lm
expr_stmt|;
name|shorts
operator|=
operator|(
name|TT_ShortMetrics
operator|*
operator|*
operator|)
name|sm
expr_stmt|;
block|}
comment|/* never trust derived values */
name|num_shorts
operator|=
name|face
operator|->
name|max_profile
operator|.
name|numGlyphs
operator|-
name|num_longs
expr_stmt|;
name|num_shorts_checked
operator|=
operator|(
name|table_len
operator|-
name|num_longs
operator|*
literal|4L
operator|)
operator|/
literal|2
expr_stmt|;
if|if
condition|(
name|num_shorts
operator|<
literal|0
condition|)
block|{
name|FT_ERROR
argument_list|(
operator|(
literal|"%cmtx has more metrics than glyphs.\n"
operator|)
argument_list|)
expr_stmt|;
comment|/* Adobe simply ignores this problem.  So we shall do the same. */
if|#
directive|if
literal|0
block|error = vertical ? SFNT_Err_Invalid_Vert_Metrics                        : SFNT_Err_Invalid_Horiz_Metrics;       goto Exit;
else|#
directive|else
name|num_shorts
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
block|}
if|if
condition|(
name|FT_QNEW_ARRAY
argument_list|(
operator|*
name|longs
argument_list|,
name|num_longs
argument_list|)
operator|||
name|FT_QNEW_ARRAY
argument_list|(
operator|*
name|shorts
argument_list|,
name|num_shorts
argument_list|)
condition|)
goto|goto
name|Fail
goto|;
if|if
condition|(
name|FT_FRAME_ENTER
argument_list|(
name|table_len
argument_list|)
condition|)
goto|goto
name|Fail
goto|;
name|p
operator|=
name|stream
operator|->
name|cursor
expr_stmt|;
block|{
name|TT_LongMetrics
name|cur
init|=
operator|*
name|longs
decl_stmt|;
name|TT_LongMetrics
name|limit
init|=
name|cur
operator|+
name|num_longs
decl_stmt|;
for|for
control|(
init|;
name|cur
operator|<
name|limit
condition|;
name|cur
operator|++
control|)
block|{
name|cur
operator|->
name|advance
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|cur
operator|->
name|bearing
operator|=
name|FT_NEXT_SHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* do we have an inconsistent number of metric values? */
block|{
name|TT_ShortMetrics
modifier|*
name|cur
init|=
operator|*
name|shorts
decl_stmt|;
name|TT_ShortMetrics
modifier|*
name|limit
init|=
name|cur
operator|+
name|FT_MIN
argument_list|(
name|num_shorts
argument_list|,
name|num_shorts_checked
argument_list|)
decl_stmt|;
for|for
control|(
init|;
name|cur
operator|<
name|limit
condition|;
name|cur
operator|++
control|)
operator|*
name|cur
operator|=
name|FT_NEXT_SHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* We fill up the missing left side bearings with the     */
comment|/* last valid value.  Since this will occur for buggy CJK */
comment|/* fonts usually only, nothing serious will happen.       */
if|if
condition|(
name|num_shorts
operator|>
name|num_shorts_checked
operator|&&
name|num_shorts_checked
operator|>
literal|0
condition|)
block|{
name|FT_Short
name|val
init|=
operator|(
operator|*
name|shorts
operator|)
index|[
name|num_shorts_checked
operator|-
literal|1
index|]
decl_stmt|;
name|limit
operator|=
operator|*
name|shorts
operator|+
name|num_shorts
expr_stmt|;
for|for
control|(
init|;
name|cur
operator|<
name|limit
condition|;
name|cur
operator|++
control|)
operator|*
name|cur
operator|=
name|val
expr_stmt|;
block|}
block|}
name|FT_FRAME_EXIT
argument_list|()
expr_stmt|;
if|if
condition|(
name|vertical
condition|)
name|face
operator|->
name|vertical
operator|.
name|number_Of_VMetrics
operator|=
operator|(
name|FT_UShort
operator|)
name|num_longs
expr_stmt|;
else|else
name|face
operator|->
name|horizontal
operator|.
name|number_Of_HMetrics
operator|=
operator|(
name|FT_UShort
operator|)
name|num_longs
expr_stmt|;
name|Fail
label|:
return|return
name|error
return|;
block|}
end_block
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FT_CONFIG_OPTION_OLD_INTERNALS */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    tt_face_load_hhea                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Load the `hhea' or 'vhea' table into a face object.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face     :: A handle to the target face object.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    stream   :: The input stream.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    vertical :: A boolean flag.  If set, load `vhea'.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0 means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_face_load_hhea
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_Stream  stream
argument_list|,
argument|FT_Bool    vertical
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|TT_HoriHeader
modifier|*
name|header
decl_stmt|;
specifier|const
name|FT_Frame_Field
name|metrics_header_fields
index|[]
init|=
block|{
DECL|macro|FT_STRUCTURE
undef|#
directive|undef
name|FT_STRUCTURE
DECL|macro|FT_STRUCTURE
define|#
directive|define
name|FT_STRUCTURE
value|TT_HoriHeader
name|FT_FRAME_START
argument_list|(
literal|36
argument_list|)
block|,
name|FT_FRAME_ULONG
argument_list|(
name|Version
argument_list|)
block|,
name|FT_FRAME_SHORT
argument_list|(
name|Ascender
argument_list|)
block|,
name|FT_FRAME_SHORT
argument_list|(
name|Descender
argument_list|)
block|,
name|FT_FRAME_SHORT
argument_list|(
name|Line_Gap
argument_list|)
block|,
name|FT_FRAME_USHORT
argument_list|(
name|advance_Width_Max
argument_list|)
block|,
name|FT_FRAME_SHORT
argument_list|(
name|min_Left_Side_Bearing
argument_list|)
block|,
name|FT_FRAME_SHORT
argument_list|(
name|min_Right_Side_Bearing
argument_list|)
block|,
name|FT_FRAME_SHORT
argument_list|(
name|xMax_Extent
argument_list|)
block|,
name|FT_FRAME_SHORT
argument_list|(
name|caret_Slope_Rise
argument_list|)
block|,
name|FT_FRAME_SHORT
argument_list|(
name|caret_Slope_Run
argument_list|)
block|,
name|FT_FRAME_SHORT
argument_list|(
name|caret_Offset
argument_list|)
block|,
name|FT_FRAME_SHORT
argument_list|(
name|Reserved
index|[
literal|0
index|]
argument_list|)
block|,
name|FT_FRAME_SHORT
argument_list|(
name|Reserved
index|[
literal|1
index|]
argument_list|)
block|,
name|FT_FRAME_SHORT
argument_list|(
name|Reserved
index|[
literal|2
index|]
argument_list|)
block|,
name|FT_FRAME_SHORT
argument_list|(
name|Reserved
index|[
literal|3
index|]
argument_list|)
block|,
name|FT_FRAME_SHORT
argument_list|(
name|metric_Data_Format
argument_list|)
block|,
name|FT_FRAME_USHORT
argument_list|(
name|number_Of_HMetrics
argument_list|)
block|,
name|FT_FRAME_END
block|}
decl_stmt|;
if|if
condition|(
name|vertical
condition|)
block|{
name|void
modifier|*
name|v
init|=
operator|&
name|face
operator|->
name|vertical
decl_stmt|;
name|error
operator|=
name|face
operator|->
name|goto_table
argument_list|(
name|face
argument_list|,
name|TTAG_vhea
argument_list|,
name|stream
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Fail
goto|;
name|header
operator|=
operator|(
name|TT_HoriHeader
operator|*
operator|)
name|v
expr_stmt|;
block|}
else|else
block|{
name|error
operator|=
name|face
operator|->
name|goto_table
argument_list|(
name|face
argument_list|,
name|TTAG_hhea
argument_list|,
name|stream
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Fail
goto|;
name|header
operator|=
operator|&
name|face
operator|->
name|horizontal
expr_stmt|;
block|}
if|if
condition|(
name|FT_STREAM_READ_FIELDS
argument_list|(
name|metrics_header_fields
argument_list|,
name|header
argument_list|)
condition|)
goto|goto
name|Fail
goto|;
name|FT_TRACE3
argument_list|(
operator|(
literal|"Ascender:          %5d\n"
operator|,
name|header
operator|->
name|Ascender
operator|)
argument_list|)
expr_stmt|;
name|FT_TRACE3
argument_list|(
operator|(
literal|"Descender:         %5d\n"
operator|,
name|header
operator|->
name|Descender
operator|)
argument_list|)
expr_stmt|;
name|FT_TRACE3
argument_list|(
operator|(
literal|"number_Of_Metrics: %5u\n"
operator|,
name|header
operator|->
name|number_Of_HMetrics
operator|)
argument_list|)
expr_stmt|;
name|header
operator|->
name|long_metrics
operator|=
name|NULL
expr_stmt|;
name|header
operator|->
name|short_metrics
operator|=
name|NULL
expr_stmt|;
name|Fail
label|:
return|return
name|error
return|;
block|}
end_block
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    tt_face_get_metrics                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Returns the horizontal or vertical metrics in font units for a     */
end_comment
begin_comment
comment|/*    given glyph.  The metrics are the left side bearing (resp. top     */
end_comment
begin_comment
comment|/*    side bearing) and advance width (resp. advance height).            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    header  :: A pointer to either the horizontal or vertical metrics  */
end_comment
begin_comment
comment|/*               structure.                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    idx     :: The glyph index.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    bearing :: The bearing, either left side or top side.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    advance :: The advance width resp. advance height.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_OLD_INTERNALS
end_ifndef
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_face_get_metrics
argument_list|(
argument|TT_Face     face
argument_list|,
argument|FT_Bool     vertical
argument_list|,
argument|FT_UInt     gindex
argument_list|,
argument|FT_Short   *abearing
argument_list|,
argument|FT_UShort  *aadvance
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|FT_Stream
name|stream
init|=
name|face
operator|->
name|root
operator|.
name|stream
decl_stmt|;
name|TT_HoriHeader
modifier|*
name|header
decl_stmt|;
name|FT_ULong
name|table_pos
decl_stmt|,
name|table_size
decl_stmt|,
name|table_end
decl_stmt|;
name|FT_UShort
name|k
decl_stmt|;
if|if
condition|(
name|vertical
condition|)
block|{
name|void
modifier|*
name|v
init|=
operator|&
name|face
operator|->
name|vertical
decl_stmt|;
name|header
operator|=
operator|(
name|TT_HoriHeader
operator|*
operator|)
name|v
expr_stmt|;
name|table_pos
operator|=
name|face
operator|->
name|vert_metrics_offset
expr_stmt|;
name|table_size
operator|=
name|face
operator|->
name|vert_metrics_size
expr_stmt|;
block|}
else|else
block|{
name|header
operator|=
operator|&
name|face
operator|->
name|horizontal
expr_stmt|;
name|table_pos
operator|=
name|face
operator|->
name|horz_metrics_offset
expr_stmt|;
name|table_size
operator|=
name|face
operator|->
name|horz_metrics_size
expr_stmt|;
block|}
name|table_end
operator|=
name|table_pos
operator|+
name|table_size
expr_stmt|;
name|k
operator|=
name|header
operator|->
name|number_Of_HMetrics
expr_stmt|;
if|if
condition|(
name|k
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|gindex
operator|<
operator|(
name|FT_UInt
operator|)
name|k
condition|)
block|{
name|table_pos
operator|+=
literal|4
operator|*
name|gindex
expr_stmt|;
if|if
condition|(
name|table_pos
operator|+
literal|4
operator|>
name|table_end
condition|)
goto|goto
name|NoData
goto|;
if|if
condition|(
name|FT_STREAM_SEEK
argument_list|(
name|table_pos
argument_list|)
operator|||
name|FT_READ_USHORT
argument_list|(
operator|*
name|aadvance
argument_list|)
operator|||
name|FT_READ_SHORT
argument_list|(
operator|*
name|abearing
argument_list|)
condition|)
goto|goto
name|NoData
goto|;
block|}
else|else
block|{
name|table_pos
operator|+=
literal|4
operator|*
operator|(
name|k
operator|-
literal|1
operator|)
expr_stmt|;
if|if
condition|(
name|table_pos
operator|+
literal|4
operator|>
name|table_end
condition|)
goto|goto
name|NoData
goto|;
if|if
condition|(
name|FT_STREAM_SEEK
argument_list|(
name|table_pos
argument_list|)
operator|||
name|FT_READ_USHORT
argument_list|(
operator|*
name|aadvance
argument_list|)
condition|)
goto|goto
name|NoData
goto|;
name|table_pos
operator|+=
literal|4
operator|+
literal|2
operator|*
operator|(
name|gindex
operator|-
name|k
operator|)
expr_stmt|;
if|if
condition|(
name|table_pos
operator|+
literal|2
operator|>
name|table_end
condition|)
operator|*
name|abearing
operator|=
literal|0
expr_stmt|;
else|else
block|{
if|if
condition|(
operator|!
name|FT_STREAM_SEEK
argument_list|(
name|table_pos
argument_list|)
condition|)
operator|(
name|void
operator|)
name|FT_READ_SHORT
argument_list|(
operator|*
name|abearing
argument_list|)
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
name|NoData
label|:
operator|*
name|abearing
operator|=
literal|0
expr_stmt|;
operator|*
name|aadvance
operator|=
literal|0
expr_stmt|;
block|}
return|return
name|SFNT_Err_Ok
return|;
block|}
end_block
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !FT_CONFIG_OPTION_OLD_INTERNALS */
end_comment
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_face_get_metrics
argument_list|(
argument|TT_Face     face
argument_list|,
argument|FT_Bool     vertical
argument_list|,
argument|FT_UInt     gindex
argument_list|,
argument|FT_Short*   abearing
argument_list|,
argument|FT_UShort*  aadvance
argument_list|)
end_macro
begin_block
block|{
name|void
modifier|*
name|v
init|=
operator|&
name|face
operator|->
name|vertical
decl_stmt|;
name|void
modifier|*
name|h
init|=
operator|&
name|face
operator|->
name|horizontal
decl_stmt|;
name|TT_HoriHeader
modifier|*
name|header
init|=
name|vertical
condition|?
operator|(
name|TT_HoriHeader
operator|*
operator|)
name|v
else|:
operator|(
name|TT_HoriHeader
operator|*
operator|)
name|h
decl_stmt|;
name|TT_LongMetrics
name|longs_m
decl_stmt|;
name|FT_UShort
name|k
init|=
name|header
operator|->
name|number_Of_HMetrics
decl_stmt|;
if|if
condition|(
name|k
operator|==
literal|0
operator|||
operator|!
name|header
operator|->
name|long_metrics
operator|||
name|gindex
operator|>=
operator|(
name|FT_UInt
operator|)
name|face
operator|->
name|max_profile
operator|.
name|numGlyphs
condition|)
block|{
operator|*
name|abearing
operator|=
operator|*
name|aadvance
operator|=
literal|0
expr_stmt|;
return|return
name|SFNT_Err_Ok
return|;
block|}
if|if
condition|(
name|gindex
operator|<
operator|(
name|FT_UInt
operator|)
name|k
condition|)
block|{
name|longs_m
operator|=
operator|(
name|TT_LongMetrics
operator|)
name|header
operator|->
name|long_metrics
operator|+
name|gindex
expr_stmt|;
operator|*
name|abearing
operator|=
name|longs_m
operator|->
name|bearing
expr_stmt|;
operator|*
name|aadvance
operator|=
name|longs_m
operator|->
name|advance
expr_stmt|;
block|}
else|else
block|{
operator|*
name|abearing
operator|=
operator|(
operator|(
name|TT_ShortMetrics
operator|*
operator|)
name|header
operator|->
name|short_metrics
operator|)
index|[
name|gindex
operator|-
name|k
index|]
expr_stmt|;
operator|*
name|aadvance
operator|=
operator|(
operator|(
name|TT_LongMetrics
operator|)
name|header
operator|->
name|long_metrics
operator|)
index|[
name|k
operator|-
literal|1
index|]
operator|.
name|advance
expr_stmt|;
block|}
return|return
name|SFNT_Err_Ok
return|;
block|}
end_block
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FT_CONFIG_OPTION_OLD_INTERNALS */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
