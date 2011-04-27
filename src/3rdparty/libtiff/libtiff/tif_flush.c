begin_unit
begin_comment
comment|/* $Header: /cvs/maptools/cvsroot/libtiff/libtiff/tif_flush.c,v 1.3 2000/09/15 20:52:42 warmerda Exp $ */
end_comment
begin_comment
comment|/*  * Copyright (c) 1988-1997 Sam Leffler  * Copyright (c) 1991-1997 Silicon Graphics, Inc.  *  * Permission to use, copy, modify, distribute, and sell this software and   * its documentation for any purpose is hereby granted without fee, provided  * that (i) the above copyright notices and this permission notice appear in  * all copies of the software and related documentation, and (ii) the names of  * Sam Leffler and Silicon Graphics may not be used in any advertising or  * publicity relating to the software without the specific, prior written  * permission of Sam Leffler and Silicon Graphics.  *   * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,   * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY   * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.    *   * IN NO EVENT SHALL SAM LEFFLER OR SILICON GRAPHICS BE LIABLE FOR  * ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,  * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,  * WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF   * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE   * OF THIS SOFTWARE.  */
end_comment
begin_comment
comment|/*  * TIFF Library.  */
end_comment
begin_include
include|#
directive|include
file|"tiffiop.h"
end_include
begin_function
name|int
DECL|function|TIFFFlush
name|TIFFFlush
parameter_list|(
name|TIFF
modifier|*
name|tif
parameter_list|)
block|{
if|if
condition|(
name|tif
operator|->
name|tif_mode
operator|!=
name|O_RDONLY
condition|)
block|{
if|if
condition|(
operator|!
name|TIFFFlushData
argument_list|(
name|tif
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
operator|(
name|tif
operator|->
name|tif_flags
operator|&
name|TIFF_DIRTYDIRECT
operator|)
operator|&&
operator|!
name|TIFFWriteDirectory
argument_list|(
name|tif
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function
begin_comment
comment|/*  * Flush buffered data to the file.  *  * Frank Warmerdam'2000: I modified this to return 1 if TIFF_BEENWRITING  * is not set, so that TIFFFlush() will proceed to write out the directory.  * The documentation says returning 1 is an error indicator, but not having  * been writing isn't exactly a an error.  Hopefully this doesn't cause  * problems for other people.   */
end_comment
begin_function
name|int
DECL|function|TIFFFlushData
name|TIFFFlushData
parameter_list|(
name|TIFF
modifier|*
name|tif
parameter_list|)
block|{
if|if
condition|(
operator|(
name|tif
operator|->
name|tif_flags
operator|&
name|TIFF_BEENWRITING
operator|)
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|tif
operator|->
name|tif_flags
operator|&
name|TIFF_POSTENCODE
condition|)
block|{
name|tif
operator|->
name|tif_flags
operator|&=
operator|~
name|TIFF_POSTENCODE
expr_stmt|;
if|if
condition|(
operator|!
call|(
modifier|*
name|tif
operator|->
name|tif_postencode
call|)
argument_list|(
name|tif
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
operator|(
name|TIFFFlushData1
argument_list|(
name|tif
argument_list|)
operator|)
return|;
block|}
end_function
end_unit
