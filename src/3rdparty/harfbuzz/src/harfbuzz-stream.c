begin_unit
begin_comment
comment|/*  * Copyright (C) 2005  David Turner  * Copyright (C) 2015 The Qt Company Ltd  * Copyright (C) 2007  Red Hat, Inc.  *  * This is part of HarfBuzz, an OpenType Layout engine library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  *  * Red Hat Author(s): Behdad Esfahbod  */
end_comment
begin_include
include|#
directive|include
file|"harfbuzz-impl.h"
end_include
begin_include
include|#
directive|include
file|"harfbuzz-stream-private.h"
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_if
if|#
directive|if
literal|0
end_if
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_define
define|#
directive|define
name|LOG
parameter_list|(
name|x
parameter_list|)
value|_hb_log x
end_define
begin_else
unit|static void _hb_log( const char*   format, ... ) {   va_list  ap;     va_start( ap, format );   vfprintf( stderr, format, ap );   va_end( ap ); }
else|#
directive|else
end_else
begin_define
DECL|macro|LOG
define|#
directive|define
name|LOG
parameter_list|(
name|x
parameter_list|)
value|do {} while (0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|HB_INTERNAL
name|void
DECL|function|_hb_close_stream
name|_hb_close_stream
parameter_list|(
name|HB_Stream
name|stream
parameter_list|)
block|{
if|if
condition|(
operator|!
name|stream
condition|)
return|return;
name|free
argument_list|(
name|stream
operator|->
name|base
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|stream
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|HB_INTERNAL
name|HB_Int
DECL|function|_hb_stream_pos
name|_hb_stream_pos
parameter_list|(
name|HB_Stream
name|stream
parameter_list|)
block|{
name|LOG
argument_list|(
operator|(
literal|"_hb_stream_pos() -> %ld\n"
operator|,
name|stream
operator|->
name|pos
operator|)
argument_list|)
expr_stmt|;
return|return
name|stream
operator|->
name|pos
return|;
block|}
end_function
begin_function
name|HB_INTERNAL
name|HB_Error
DECL|function|_hb_stream_seek
name|_hb_stream_seek
parameter_list|(
name|HB_Stream
name|stream
parameter_list|,
name|HB_UInt
name|pos
parameter_list|)
block|{
name|HB_Error
name|error
init|=
operator|(
name|HB_Error
operator|)
literal|0
decl_stmt|;
name|stream
operator|->
name|pos
operator|=
name|pos
expr_stmt|;
if|if
condition|(
name|pos
operator|>
name|stream
operator|->
name|size
condition|)
name|error
operator|=
name|ERR
argument_list|(
name|HB_Err_Read_Error
argument_list|)
expr_stmt|;
name|LOG
argument_list|(
operator|(
literal|"_hb_stream_seek(%ld) -> 0x%04X\n"
operator|,
name|pos
operator|,
name|error
operator|)
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_function
begin_function
name|HB_INTERNAL
name|HB_Error
DECL|function|_hb_stream_frame_enter
name|_hb_stream_frame_enter
parameter_list|(
name|HB_Stream
name|stream
parameter_list|,
name|HB_UInt
name|count
parameter_list|)
block|{
name|HB_Error
name|error
init|=
name|HB_Err_Ok
decl_stmt|;
comment|/* check new position, watch for overflow */
if|if
condition|(
name|HB_UNLIKELY
argument_list|(
name|stream
operator|->
name|pos
operator|+
name|count
operator|>
name|stream
operator|->
name|size
operator|||
name|stream
operator|->
name|pos
operator|+
name|count
operator|<
name|stream
operator|->
name|pos
argument_list|)
condition|)
block|{
name|error
operator|=
name|ERR
argument_list|(
name|HB_Err_Read_Error
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
comment|/* set cursor */
name|stream
operator|->
name|cursor
operator|=
name|stream
operator|->
name|base
operator|+
name|stream
operator|->
name|pos
expr_stmt|;
name|stream
operator|->
name|pos
operator|+=
name|count
expr_stmt|;
name|Exit
label|:
name|LOG
argument_list|(
operator|(
literal|"_hb_stream_frame_enter(%ld) -> 0x%04X\n"
operator|,
name|count
operator|,
name|error
operator|)
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_function
begin_function
name|HB_INTERNAL
name|void
DECL|function|_hb_stream_frame_exit
name|_hb_stream_frame_exit
parameter_list|(
name|HB_Stream
name|stream
parameter_list|)
block|{
name|stream
operator|->
name|cursor
operator|=
name|NULL
expr_stmt|;
name|LOG
argument_list|(
operator|(
literal|"_hb_stream_frame_exit()\n"
operator|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
