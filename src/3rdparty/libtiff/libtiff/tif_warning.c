begin_unit
begin_comment
comment|/* $Header: /cvs/maptools/cvsroot/libtiff/libtiff/tif_warning.c,v 1.2 2005/12/23 01:18:59 joris Exp $ */
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
begin_decl_stmt
DECL|variable|_TIFFwarningHandlerExt
name|TIFFErrorHandlerExt
name|_TIFFwarningHandlerExt
init|=
name|NULL
decl_stmt|;
end_decl_stmt
begin_function
name|TIFFErrorHandler
DECL|function|TIFFSetWarningHandler
name|TIFFSetWarningHandler
parameter_list|(
name|TIFFErrorHandler
name|handler
parameter_list|)
block|{
name|TIFFErrorHandler
name|prev
init|=
name|_TIFFwarningHandler
decl_stmt|;
name|_TIFFwarningHandler
operator|=
name|handler
expr_stmt|;
return|return
operator|(
name|prev
operator|)
return|;
block|}
end_function
begin_function
name|TIFFErrorHandlerExt
DECL|function|TIFFSetWarningHandlerExt
name|TIFFSetWarningHandlerExt
parameter_list|(
name|TIFFErrorHandlerExt
name|handler
parameter_list|)
block|{
name|TIFFErrorHandlerExt
name|prev
init|=
name|_TIFFwarningHandlerExt
decl_stmt|;
name|_TIFFwarningHandlerExt
operator|=
name|handler
expr_stmt|;
return|return
operator|(
name|prev
operator|)
return|;
block|}
end_function
begin_function
name|void
DECL|function|TIFFWarning
name|TIFFWarning
parameter_list|(
specifier|const
name|char
modifier|*
name|module
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
if|if
condition|(
name|_TIFFwarningHandler
condition|)
call|(
modifier|*
name|_TIFFwarningHandler
call|)
argument_list|(
name|module
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
if|if
condition|(
name|_TIFFwarningHandlerExt
condition|)
call|(
modifier|*
name|_TIFFwarningHandlerExt
call|)
argument_list|(
literal|0
argument_list|,
name|module
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
DECL|function|TIFFWarningExt
name|TIFFWarningExt
parameter_list|(
name|thandle_t
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|module
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
if|if
condition|(
name|_TIFFwarningHandler
condition|)
call|(
modifier|*
name|_TIFFwarningHandler
call|)
argument_list|(
name|module
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
if|if
condition|(
name|_TIFFwarningHandlerExt
condition|)
call|(
modifier|*
name|_TIFFwarningHandlerExt
call|)
argument_list|(
name|fd
argument_list|,
name|module
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
