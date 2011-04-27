begin_unit
begin_comment
comment|/* $Header: /cvs/maptools/cvsroot/libtiff/libtiff/tif_acorn.c,v 1.2 2005/12/21 12:23:13 joris Exp $ */
end_comment
begin_comment
comment|/*  * Copyright (c) 1988-1997 Sam Leffler  * Copyright (c) 1991-1997 Silicon Graphics, Inc.  *  * Permission to use, copy, modify, distribute, and sell this software and  * its documentation for any purpose is hereby granted without fee, provided  * that (i) the above copyright notices and this permission notice appear in  * all copies of the software and related documentation, and (ii) the names of  * Sam Leffler and Silicon Graphics may not be used in any advertising or  * publicity relating to the software without the specific, prior written  * permission of Sam Leffler and Silicon Graphics.  *  * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,  * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY  * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  *  * IN NO EVENT SHALL SAM LEFFLER OR SILICON GRAPHICS BE LIABLE FOR  * ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,  * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,  * WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF  * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE  * OF THIS SOFTWARE.  */
end_comment
begin_comment
comment|/*  * TIFF Library RISC OS specific Routines.  * Developed out of the Unix version.  * Peter Greenham, May 1995  */
end_comment
begin_include
include|#
directive|include
file|"tiffiop.h"
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_comment
comment|/* Low-level file handling ~~~~~~~~~~~~~~~~~~~~~~~ The functions in osfcn.h are unavailable when compiling under C, as it's a C++ header. Therefore they have been implemented here.  Now, why have I done it this way?  The definitive API library for RISC OS is Jonathan Coxhead's OSLib, which uses heavily optimised ARM assembler or even plain inline SWI calls for maximum performance and minimum runtime size. However, I don't want to make LIBTIFF need that to survive. Therefore I have also emulated the functions using macros to _swi() and _swix() defined in the swis.h header, and borrowing types from kernel.h, which is less efficient but doesn't need any third-party libraries.  */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|INCLUDE_OSLIB
end_ifdef
begin_include
include|#
directive|include
file|"osfile.h"
end_include
begin_include
include|#
directive|include
file|"osgbpb.h"
end_include
begin_include
include|#
directive|include
file|"osargs.h"
end_include
begin_include
include|#
directive|include
file|"osfind.h"
end_include
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* OSLIB EMULATION STARTS */
end_comment
begin_include
include|#
directive|include
file|"kernel.h"
end_include
begin_include
include|#
directive|include
file|"swis.h"
end_include
begin_comment
comment|/* From oslib:types.h */
end_comment
begin_typedef
DECL|typedef|bits
typedef|typedef
name|unsigned
name|int
name|bits
typedef|;
end_typedef
begin_typedef
DECL|typedef|byte
typedef|typedef
name|unsigned
name|char
name|byte
typedef|;
end_typedef
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
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
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
name|NULL
end_ifndef
begin_define
DECL|macro|NULL
define|#
directive|define
name|NULL
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SKIP
end_ifndef
begin_define
DECL|macro|SKIP
define|#
directive|define
name|SKIP
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* From oslib:os.h */
end_comment
begin_typedef
DECL|typedef|os_error
typedef|typedef
name|_kernel_oserror
name|os_error
typedef|;
end_typedef
begin_typedef
DECL|typedef|os_f
typedef|typedef
name|byte
name|os_f
typedef|;
end_typedef
begin_comment
comment|/* From oslib:osfile.h */
end_comment
begin_undef
DECL|macro|OS_File
undef|#
directive|undef
name|OS_File
end_undef
begin_define
DECL|macro|OS_File
define|#
directive|define
name|OS_File
value|0x8
end_define
begin_comment
comment|/* From oslib:osgbpb.h */
end_comment
begin_undef
DECL|macro|OS_GBPB
undef|#
directive|undef
name|OS_GBPB
end_undef
begin_define
DECL|macro|OS_GBPB
define|#
directive|define
name|OS_GBPB
value|0xC
end_define
begin_undef
DECL|macro|OSGBPB_Write
undef|#
directive|undef
name|OSGBPB_Write
end_undef
begin_define
DECL|macro|OSGBPB_Write
define|#
directive|define
name|OSGBPB_Write
value|0x2
end_define
begin_undef
DECL|macro|OSGBPB_Read
undef|#
directive|undef
name|OSGBPB_Read
end_undef
begin_define
DECL|macro|OSGBPB_Read
define|#
directive|define
name|OSGBPB_Read
value|0x4
end_define
begin_function_decl
specifier|extern
name|os_error
modifier|*
name|xosgbpb_write
parameter_list|(
name|os_f
name|file
parameter_list|,
name|byte
modifier|*
name|data
parameter_list|,
name|int
name|size
parameter_list|,
name|int
modifier|*
name|unwritten
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|int
name|osgbpb_write
parameter_list|(
name|os_f
name|file
parameter_list|,
name|byte
modifier|*
name|data
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|xosgbpb_write
define|#
directive|define
name|xosgbpb_write
parameter_list|(
name|file
parameter_list|,
name|data
parameter_list|,
name|size
parameter_list|,
name|unwritten
parameter_list|)
define|\
value|(os_error*) _swix(OS_GBPB, _IN(0)|_IN(1)|_IN(2)|_IN(3)|_IN(4)|_OUT(3), \ 		OSGBPB_WriteAt, \ 		file, \ 		data, \ 		size, \ 		unwritten)
end_define
begin_define
DECL|macro|osgbpb_write
define|#
directive|define
name|osgbpb_write
parameter_list|(
name|file
parameter_list|,
name|data
parameter_list|,
name|size
parameter_list|)
define|\
value|_swi(OS_GBPB, _IN(0)|_IN(1)|_IN(2)|_IN(3)|_RETURN(3), \ 		OSGBPB_Write, \ 		file, \ 		data, \ 		size)
end_define
begin_function_decl
specifier|extern
name|os_error
modifier|*
name|xosgbpb_read
parameter_list|(
name|os_f
name|file
parameter_list|,
name|byte
modifier|*
name|buffer
parameter_list|,
name|int
name|size
parameter_list|,
name|int
modifier|*
name|unread
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|int
name|osgbpb_read
parameter_list|(
name|os_f
name|file
parameter_list|,
name|byte
modifier|*
name|buffer
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|xosgbpb_read
define|#
directive|define
name|xosgbpb_read
parameter_list|(
name|file
parameter_list|,
name|buffer
parameter_list|,
name|size
parameter_list|,
name|unread
parameter_list|)
define|\
value|(os_error*) _swix(OS_GBPB, _IN(0)|_IN(1)|_IN(2)|_IN(3)|_OUT(3), \ 		OSGBPB_Read, \ 		file, \ 		buffer, \ 		size, \ 		unread)
end_define
begin_define
DECL|macro|osgbpb_read
define|#
directive|define
name|osgbpb_read
parameter_list|(
name|file
parameter_list|,
name|buffer
parameter_list|,
name|size
parameter_list|)
define|\
value|_swi(OS_GBPB, _IN(0)|_IN(1)|_IN(2)|_IN(3)|_RETURN(3), \ 		OSGBPB_Read, \ 		file, \ 		buffer, \ 		size)
end_define
begin_comment
comment|/* From oslib:osfind.h */
end_comment
begin_undef
DECL|macro|OS_Find
undef|#
directive|undef
name|OS_Find
end_undef
begin_define
DECL|macro|OS_Find
define|#
directive|define
name|OS_Find
value|0xD
end_define
begin_undef
DECL|macro|OSFind_Openin
undef|#
directive|undef
name|OSFind_Openin
end_undef
begin_define
DECL|macro|OSFind_Openin
define|#
directive|define
name|OSFind_Openin
value|0x40
end_define
begin_undef
DECL|macro|OSFind_Openout
undef|#
directive|undef
name|OSFind_Openout
end_undef
begin_define
DECL|macro|OSFind_Openout
define|#
directive|define
name|OSFind_Openout
value|0x80
end_define
begin_undef
DECL|macro|OSFind_Openup
undef|#
directive|undef
name|OSFind_Openup
end_undef
begin_define
DECL|macro|OSFind_Openup
define|#
directive|define
name|OSFind_Openup
value|0xC0
end_define
begin_undef
DECL|macro|OSFind_Close
undef|#
directive|undef
name|OSFind_Close
end_undef
begin_define
DECL|macro|OSFind_Close
define|#
directive|define
name|OSFind_Close
value|0x0
end_define
begin_define
DECL|macro|xosfind_open
define|#
directive|define
name|xosfind_open
parameter_list|(
name|reason
parameter_list|,
name|file_name
parameter_list|,
name|path
parameter_list|,
name|file
parameter_list|)
define|\
value|(os_error*) _swix(OS_Find, _IN(0)|_IN(1)|_IN(2)|_OUT(0), \ 		reason, file_name, path, file)
end_define
begin_define
DECL|macro|osfind_open
define|#
directive|define
name|osfind_open
parameter_list|(
name|reason
parameter_list|,
name|file_name
parameter_list|,
name|path
parameter_list|)
define|\
value|(os_f) _swi(OS_Find, _IN(0)|_IN(1)|_IN(2)|_RETURN(0), \ 		reason, file_name, path)
end_define
begin_function_decl
specifier|extern
name|os_error
modifier|*
name|xosfind_openin
parameter_list|(
name|bits
name|flags
parameter_list|,
name|char
modifier|*
name|file_name
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|os_f
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|os_f
name|osfind_openin
parameter_list|(
name|bits
name|flags
parameter_list|,
name|char
modifier|*
name|file_name
parameter_list|,
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|xosfind_openin
define|#
directive|define
name|xosfind_openin
parameter_list|(
name|flags
parameter_list|,
name|file_name
parameter_list|,
name|path
parameter_list|,
name|file
parameter_list|)
define|\
value|xosfind_open(flags | OSFind_Openin, file_name, path, file)
end_define
begin_define
DECL|macro|osfind_openin
define|#
directive|define
name|osfind_openin
parameter_list|(
name|flags
parameter_list|,
name|file_name
parameter_list|,
name|path
parameter_list|)
define|\
value|osfind_open(flags | OSFind_Openin, file_name, path)
end_define
begin_function_decl
specifier|extern
name|os_error
modifier|*
name|xosfind_openout
parameter_list|(
name|bits
name|flags
parameter_list|,
name|char
modifier|*
name|file_name
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|os_f
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|os_f
name|osfind_openout
parameter_list|(
name|bits
name|flags
parameter_list|,
name|char
modifier|*
name|file_name
parameter_list|,
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|xosfind_openout
define|#
directive|define
name|xosfind_openout
parameter_list|(
name|flags
parameter_list|,
name|file_name
parameter_list|,
name|path
parameter_list|,
name|file
parameter_list|)
define|\
value|xosfind_open(flags | OSFind_Openout, file_name, path, file)
end_define
begin_define
DECL|macro|osfind_openout
define|#
directive|define
name|osfind_openout
parameter_list|(
name|flags
parameter_list|,
name|file_name
parameter_list|,
name|path
parameter_list|)
define|\
value|osfind_open(flags | OSFind_Openout, file_name, path)
end_define
begin_function_decl
specifier|extern
name|os_error
modifier|*
name|xosfind_openup
parameter_list|(
name|bits
name|flags
parameter_list|,
name|char
modifier|*
name|file_name
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|os_f
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|os_f
name|osfind_openup
parameter_list|(
name|bits
name|flags
parameter_list|,
name|char
modifier|*
name|file_name
parameter_list|,
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|xosfind_openup
define|#
directive|define
name|xosfind_openup
parameter_list|(
name|flags
parameter_list|,
name|file_name
parameter_list|,
name|path
parameter_list|,
name|file
parameter_list|)
define|\
value|xosfind_open(flags | OSFind_Openup, file_name, path, file)
end_define
begin_define
DECL|macro|osfind_openup
define|#
directive|define
name|osfind_openup
parameter_list|(
name|flags
parameter_list|,
name|file_name
parameter_list|,
name|path
parameter_list|)
define|\
value|osfind_open(flags | OSFind_Openup, file_name, path)
end_define
begin_function_decl
specifier|extern
name|os_error
modifier|*
name|xosfind_close
parameter_list|(
name|os_f
name|file
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|void
name|osfind_close
parameter_list|(
name|os_f
name|file
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|xosfind_close
define|#
directive|define
name|xosfind_close
parameter_list|(
name|file
parameter_list|)
define|\
value|(os_error*) _swix(OS_Find, _IN(0)|_IN(1), \ 		OSFind_Close, \ 		file)
end_define
begin_define
DECL|macro|osfind_close
define|#
directive|define
name|osfind_close
parameter_list|(
name|file
parameter_list|)
define|\
value|(void) _swi(OS_Find, _IN(0)|_IN(1), \ 		OSFind_Close, \ 		file)
end_define
begin_comment
comment|/* From oslib:osargs.h */
end_comment
begin_undef
DECL|macro|OS_Args
undef|#
directive|undef
name|OS_Args
end_undef
begin_define
DECL|macro|OS_Args
define|#
directive|define
name|OS_Args
value|0x9
end_define
begin_undef
DECL|macro|OSArgs_ReadPtr
undef|#
directive|undef
name|OSArgs_ReadPtr
end_undef
begin_define
DECL|macro|OSArgs_ReadPtr
define|#
directive|define
name|OSArgs_ReadPtr
value|0x0
end_define
begin_undef
DECL|macro|OSArgs_SetPtr
undef|#
directive|undef
name|OSArgs_SetPtr
end_undef
begin_define
DECL|macro|OSArgs_SetPtr
define|#
directive|define
name|OSArgs_SetPtr
value|0x1
end_define
begin_undef
DECL|macro|OSArgs_ReadExt
undef|#
directive|undef
name|OSArgs_ReadExt
end_undef
begin_define
DECL|macro|OSArgs_ReadExt
define|#
directive|define
name|OSArgs_ReadExt
value|0x2
end_define
begin_function_decl
specifier|extern
name|os_error
modifier|*
name|xosargs_read_ptr
parameter_list|(
name|os_f
name|file
parameter_list|,
name|int
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|int
name|osargs_read_ptr
parameter_list|(
name|os_f
name|file
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|xosargs_read_ptr
define|#
directive|define
name|xosargs_read_ptr
parameter_list|(
name|file
parameter_list|,
name|ptr
parameter_list|)
define|\
value|(os_error*) _swix(OS_Args, _IN(0)|_IN(1)|_OUT(2), \ 		OSArgs_ReadPtr, \ 		file, \ 		ptr)
end_define
begin_define
DECL|macro|osargs_read_ptr
define|#
directive|define
name|osargs_read_ptr
parameter_list|(
name|file
parameter_list|)
define|\
value|_swi(OS_Args, _IN(0)|_IN(1)|_RETURN(2), \ 		OSArgs_ReadPtr, \ 		file)
end_define
begin_function_decl
specifier|extern
name|os_error
modifier|*
name|xosargs_set_ptr
parameter_list|(
name|os_f
name|file
parameter_list|,
name|int
name|ptr
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|void
name|osargs_set_ptr
parameter_list|(
name|os_f
name|file
parameter_list|,
name|int
name|ptr
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|xosargs_set_ptr
define|#
directive|define
name|xosargs_set_ptr
parameter_list|(
name|file
parameter_list|,
name|ptr
parameter_list|)
define|\
value|(os_error*) _swix(OS_Args, _IN(0)|_IN(1)|_IN(2), \ 		OSArgs_SetPtr, \ 		file, \ 		ptr)
end_define
begin_define
DECL|macro|osargs_set_ptr
define|#
directive|define
name|osargs_set_ptr
parameter_list|(
name|file
parameter_list|,
name|ptr
parameter_list|)
define|\
value|(void) _swi(OS_Args, _IN(0)|_IN(1)|_IN(2), \ 		OSArgs_SetPtr, \ 		file, \ 		ptr)
end_define
begin_function_decl
specifier|extern
name|os_error
modifier|*
name|xosargs_read_ext
parameter_list|(
name|os_f
name|file
parameter_list|,
name|int
modifier|*
name|ext
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|int
name|osargs_read_ext
parameter_list|(
name|os_f
name|file
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|xosargs_read_ext
define|#
directive|define
name|xosargs_read_ext
parameter_list|(
name|file
parameter_list|,
name|ext
parameter_list|)
define|\
value|(os_error*) _swix(OS_Args, _IN(0)|_IN(1)|_OUT(2), \ 		OSArgs_ReadExt, \ 		file, \ 		ext)
end_define
begin_define
DECL|macro|osargs_read_ext
define|#
directive|define
name|osargs_read_ext
parameter_list|(
name|file
parameter_list|)
define|\
value|_swi(OS_Args, _IN(0)|_IN(1)|_RETURN(2), \ 		OSArgs_ReadExt, \ 		file)
end_define
begin_comment
comment|/* OSLIB EMULATION ENDS */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|__osfcn_h
end_ifndef
begin_comment
comment|/* Will be set or not during tiffcomp.h */
end_comment
begin_comment
comment|/* You get this to compile under C++? Please say how! */
end_comment
begin_function
DECL|function|open
specifier|extern
name|int
name|open
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|mode
parameter_list|)
block|{
comment|/* From what I can tell, should return<0 for failure */
name|os_error
modifier|*
name|e
init|=
operator|(
name|os_error
operator|*
operator|)
literal|1
decl_stmt|;
comment|/* Cheeky way to use a pointer eh? :-) */
name|os_f
name|file
init|=
operator|(
name|os_f
operator|)
operator|-
literal|1
decl_stmt|;
name|flags
operator|=
name|flags
expr_stmt|;
switch|switch
condition|(
name|mode
condition|)
block|{
case|case
name|O_RDONLY
case|:
block|{
name|e
operator|=
name|xosfind_openin
argument_list|(
name|SKIP
argument_list|,
name|name
argument_list|,
name|SKIP
argument_list|,
operator|&
name|file
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|O_WRONLY
case|:
case|case
name|O_RDWR
operator||
name|O_CREAT
case|:
case|case
name|O_RDWR
operator||
name|O_CREAT
operator||
name|O_TRUNC
case|:
block|{
name|e
operator|=
name|xosfind_openout
argument_list|(
name|SKIP
argument_list|,
name|name
argument_list|,
name|SKIP
argument_list|,
operator|&
name|file
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|O_RDWR
case|:
block|{
name|e
operator|=
name|xosfind_openup
argument_list|(
name|SKIP
argument_list|,
name|name
argument_list|,
name|SKIP
argument_list|,
operator|&
name|file
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|e
condition|)
block|{
name|file
operator|=
operator|(
name|os_f
operator|)
operator|-
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|file
operator|)
return|;
block|}
end_function
begin_function
DECL|function|close
specifier|extern
name|int
name|close
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
return|return
operator|(
operator|(
name|int
operator|)
name|xosfind_close
argument_list|(
operator|(
name|os_f
operator|)
name|fd
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|write
specifier|extern
name|int
name|write
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|nbytes
parameter_list|)
block|{
comment|/* Returns number of bytes written */
return|return
operator|(
name|nbytes
operator|-
name|osgbpb_write
argument_list|(
operator|(
name|os_f
operator|)
name|fd
argument_list|,
operator|(
specifier|const
name|byte
operator|*
operator|)
name|buf
argument_list|,
name|nbytes
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|read
specifier|extern
name|int
name|read
parameter_list|(
name|int
name|fd
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|nbytes
parameter_list|)
block|{
comment|/* Returns number of bytes read */
return|return
operator|(
name|nbytes
operator|-
name|osgbpb_read
argument_list|(
operator|(
name|os_f
operator|)
name|fd
argument_list|,
operator|(
name|byte
operator|*
operator|)
name|buf
argument_list|,
name|nbytes
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|lseek
specifier|extern
name|off_t
name|lseek
parameter_list|(
name|int
name|fd
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|int
name|whence
parameter_list|)
block|{
name|int
name|absolute
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|whence
condition|)
block|{
case|case
name|SEEK_SET
case|:
block|{
name|absolute
operator|=
operator|(
name|int
operator|)
name|offset
expr_stmt|;
break|break;
block|}
case|case
name|SEEK_CUR
case|:
block|{
name|absolute
operator|=
name|osargs_read_ptr
argument_list|(
operator|(
name|os_f
operator|)
name|fd
argument_list|)
operator|+
operator|(
name|int
operator|)
name|offset
expr_stmt|;
break|break;
block|}
case|case
name|SEEK_END
case|:
block|{
name|absolute
operator|=
name|osargs_read_ext
argument_list|(
operator|(
name|os_f
operator|)
name|fd
argument_list|)
operator|+
operator|(
name|int
operator|)
name|offset
expr_stmt|;
break|break;
block|}
block|}
name|osargs_set_ptr
argument_list|(
operator|(
name|os_f
operator|)
name|fd
argument_list|,
name|absolute
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|off_t
operator|)
name|osargs_read_ptr
argument_list|(
operator|(
name|os_f
operator|)
name|fd
argument_list|)
operator|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|static
name|tsize_t
DECL|function|_tiffReadProc
name|_tiffReadProc
parameter_list|(
name|thandle_t
name|fd
parameter_list|,
name|tdata_t
name|buf
parameter_list|,
name|tsize_t
name|size
parameter_list|)
block|{
return|return
operator|(
operator|(
name|tsize_t
operator|)
name|read
argument_list|(
operator|(
name|int
operator|)
name|fd
argument_list|,
name|buf
argument_list|,
operator|(
name|size_t
operator|)
name|size
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
specifier|static
name|tsize_t
DECL|function|_tiffWriteProc
name|_tiffWriteProc
parameter_list|(
name|thandle_t
name|fd
parameter_list|,
name|tdata_t
name|buf
parameter_list|,
name|tsize_t
name|size
parameter_list|)
block|{
return|return
operator|(
operator|(
name|tsize_t
operator|)
name|write
argument_list|(
operator|(
name|int
operator|)
name|fd
argument_list|,
name|buf
argument_list|,
operator|(
name|size_t
operator|)
name|size
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
specifier|static
name|toff_t
DECL|function|_tiffSeekProc
name|_tiffSeekProc
parameter_list|(
name|thandle_t
name|fd
parameter_list|,
name|toff_t
name|off
parameter_list|,
name|int
name|whence
parameter_list|)
block|{
return|return
operator|(
operator|(
name|toff_t
operator|)
name|lseek
argument_list|(
operator|(
name|int
operator|)
name|fd
argument_list|,
operator|(
name|off_t
operator|)
name|off
argument_list|,
name|whence
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
specifier|static
name|int
DECL|function|_tiffCloseProc
name|_tiffCloseProc
parameter_list|(
name|thandle_t
name|fd
parameter_list|)
block|{
return|return
operator|(
name|close
argument_list|(
operator|(
name|int
operator|)
name|fd
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
specifier|static
name|toff_t
DECL|function|_tiffSizeProc
name|_tiffSizeProc
parameter_list|(
name|thandle_t
name|fd
parameter_list|)
block|{
return|return
operator|(
name|lseek
argument_list|(
operator|(
name|int
operator|)
name|fd
argument_list|,
name|SEEK_END
argument_list|,
name|SEEK_SET
argument_list|)
operator|)
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MMAP
end_ifdef
begin_error
error|#
directive|error
literal|"I didn't know Acorn had that!"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !HAVE_MMAP */
end_comment
begin_function
specifier|static
name|int
DECL|function|_tiffMapProc
name|_tiffMapProc
parameter_list|(
name|thandle_t
name|fd
parameter_list|,
name|tdata_t
modifier|*
name|pbase
parameter_list|,
name|toff_t
modifier|*
name|psize
parameter_list|)
block|{
operator|(
name|void
operator|)
name|fd
expr_stmt|;
operator|(
name|void
operator|)
name|pbase
expr_stmt|;
operator|(
name|void
operator|)
name|psize
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|_tiffUnmapProc
name|_tiffUnmapProc
parameter_list|(
name|thandle_t
name|fd
parameter_list|,
name|tdata_t
name|base
parameter_list|,
name|toff_t
name|size
parameter_list|)
block|{
operator|(
name|void
operator|)
name|fd
expr_stmt|;
operator|(
name|void
operator|)
name|base
expr_stmt|;
operator|(
name|void
operator|)
name|size
expr_stmt|;
block|}
end_function
begin_comment
comment|/*  * Open a TIFF file descriptor for read/writing.  */
end_comment
begin_function
name|TIFF
modifier|*
DECL|function|TIFFFdOpen
name|TIFFFdOpen
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|)
block|{
name|TIFF
modifier|*
name|tif
decl_stmt|;
name|tif
operator|=
name|TIFFClientOpen
argument_list|(
name|name
argument_list|,
name|mode
argument_list|,
operator|(
name|thandle_t
operator|)
name|fd
argument_list|,
name|_tiffReadProc
argument_list|,
name|_tiffWriteProc
argument_list|,
name|_tiffSeekProc
argument_list|,
name|_tiffCloseProc
argument_list|,
name|_tiffSizeProc
argument_list|,
name|_tiffMapProc
argument_list|,
name|_tiffUnmapProc
argument_list|)
expr_stmt|;
if|if
condition|(
name|tif
condition|)
block|{
name|tif
operator|->
name|tif_fd
operator|=
name|fd
expr_stmt|;
block|}
return|return
operator|(
name|tif
operator|)
return|;
block|}
end_function
begin_comment
comment|/*  * Open a TIFF file for read/writing.  */
end_comment
begin_function
name|TIFF
modifier|*
DECL|function|TIFFOpen
name|TIFFOpen
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|)
block|{
specifier|static
specifier|const
name|char
name|module
index|[]
init|=
literal|"TIFFOpen"
decl_stmt|;
name|int
name|m
decl_stmt|,
name|fd
decl_stmt|;
name|m
operator|=
name|_TIFFgetMode
argument_list|(
name|mode
argument_list|,
name|module
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|==
operator|-
literal|1
condition|)
block|{
return|return
operator|(
operator|(
name|TIFF
operator|*
operator|)
literal|0
operator|)
return|;
block|}
name|fd
operator|=
name|open
argument_list|(
name|name
argument_list|,
literal|0
argument_list|,
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
block|{
name|TIFFErrorExt
argument_list|(
literal|0
argument_list|,
name|module
argument_list|,
literal|"%s: Cannot open"
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|TIFF
operator|*
operator|)
literal|0
operator|)
return|;
block|}
return|return
operator|(
name|TIFFFdOpen
argument_list|(
name|fd
argument_list|,
name|name
argument_list|,
name|mode
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
name|void
modifier|*
DECL|function|_TIFFmalloc
name|_TIFFmalloc
parameter_list|(
name|tsize_t
name|s
parameter_list|)
block|{
return|return
operator|(
name|malloc
argument_list|(
operator|(
name|size_t
operator|)
name|s
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
name|void
DECL|function|_TIFFfree
name|_TIFFfree
parameter_list|(
name|tdata_t
name|p
parameter_list|)
block|{
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
modifier|*
DECL|function|_TIFFrealloc
name|_TIFFrealloc
parameter_list|(
name|tdata_t
name|p
parameter_list|,
name|tsize_t
name|s
parameter_list|)
block|{
return|return
operator|(
name|realloc
argument_list|(
name|p
argument_list|,
operator|(
name|size_t
operator|)
name|s
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
name|void
DECL|function|_TIFFmemset
name|_TIFFmemset
parameter_list|(
name|tdata_t
name|p
parameter_list|,
name|int
name|v
parameter_list|,
name|tsize_t
name|c
parameter_list|)
block|{
name|memset
argument_list|(
name|p
argument_list|,
name|v
argument_list|,
operator|(
name|size_t
operator|)
name|c
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
DECL|function|_TIFFmemcpy
name|_TIFFmemcpy
parameter_list|(
name|tdata_t
name|d
parameter_list|,
specifier|const
name|tdata_t
name|s
parameter_list|,
name|tsize_t
name|c
parameter_list|)
block|{
name|memcpy
argument_list|(
name|d
argument_list|,
name|s
argument_list|,
operator|(
name|size_t
operator|)
name|c
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|int
DECL|function|_TIFFmemcmp
name|_TIFFmemcmp
parameter_list|(
specifier|const
name|tdata_t
name|p1
parameter_list|,
specifier|const
name|tdata_t
name|p2
parameter_list|,
name|tsize_t
name|c
parameter_list|)
block|{
return|return
operator|(
name|memcmp
argument_list|(
name|p1
argument_list|,
name|p2
argument_list|,
operator|(
name|size_t
operator|)
name|c
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|acornWarningHandler
name|acornWarningHandler
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
name|va_list
name|ap
parameter_list|)
block|{
if|if
condition|(
name|module
operator|!=
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|module
argument_list|)
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Warning, "
argument_list|)
expr_stmt|;
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|".\n"
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|_TIFFwarningHandler
name|TIFFErrorHandler
name|_TIFFwarningHandler
init|=
name|acornWarningHandler
decl_stmt|;
end_decl_stmt
begin_function
specifier|static
name|void
DECL|function|acornErrorHandler
name|acornErrorHandler
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
name|va_list
name|ap
parameter_list|)
block|{
if|if
condition|(
name|module
operator|!=
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|module
argument_list|)
expr_stmt|;
block|}
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|".\n"
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|_TIFFerrorHandler
name|TIFFErrorHandler
name|_TIFFerrorHandler
init|=
name|acornErrorHandler
decl_stmt|;
end_decl_stmt
end_unit
