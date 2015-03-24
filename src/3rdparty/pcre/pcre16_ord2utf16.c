begin_unit
begin_comment
comment|/************************************************* *      Perl-Compatible Regular Expressions       * *************************************************/
end_comment
begin_comment
comment|/* PCRE is a library of functions to support regular expressions whose syntax and semantics are as close as possible to those of the Perl 5 language.                         Written by Philip Hazel            Copyright (c) 1997-2012 University of Cambridge  ----------------------------------------------------------------------------- Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      * Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.      * Neither the name of the University of Cambridge nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ----------------------------------------------------------------------------- */
end_comment
begin_comment
comment|/* This file contains a private PCRE function that converts an ordinal character value into a UTF16 string. */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef
begin_include
include|#
directive|include
file|"config.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Generate code with 16 bit character support. */
end_comment
begin_define
DECL|macro|COMPILE_PCRE16
define|#
directive|define
name|COMPILE_PCRE16
end_define
begin_include
include|#
directive|include
file|"pcre_internal.h"
end_include
begin_comment
comment|/************************************************* *       Convert character value to UTF-16         * *************************************************/
end_comment
begin_comment
comment|/* This function takes an integer value in the range 0 - 0x10ffff and encodes it as a UTF-16 character in 1 to 2 pcre_uchars.  Arguments:   cvalue     the character value   buffer     pointer to buffer for result - at least 2 pcre_uchars long  Returns:     number of characters placed in the buffer */
end_comment
begin_function
name|unsigned
name|int
DECL|function|ord2utf
name|PRIV
function|(
name|ord2utf
function|)
parameter_list|(
name|pcre_uint32
name|cvalue
parameter_list|,
name|pcre_uchar
modifier|*
name|buffer
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|SUPPORT_UTF
if|if
condition|(
name|cvalue
operator|<=
literal|0xffff
condition|)
block|{
operator|*
name|buffer
operator|=
operator|(
name|pcre_uchar
operator|)
name|cvalue
expr_stmt|;
return|return
literal|1
return|;
block|}
name|cvalue
operator|-=
literal|0x10000
expr_stmt|;
operator|*
name|buffer
operator|++
operator|=
literal|0xd800
operator||
operator|(
name|cvalue
operator|>>
literal|10
operator|)
expr_stmt|;
operator|*
name|buffer
operator|=
literal|0xdc00
operator||
operator|(
name|cvalue
operator|&
literal|0x3ff
operator|)
expr_stmt|;
return|return
literal|2
return|;
else|#
directive|else
comment|/* SUPPORT_UTF */
call|(
name|void
call|)
argument_list|(
name|cvalue
argument_list|)
expr_stmt|;
comment|/* Keep compiler happy; this function won't ever be */
call|(
name|void
call|)
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
comment|/* called when SUPPORT_UTF is not defined. */
return|return
literal|0
return|;
endif|#
directive|endif
comment|/* SUPPORT_UTF */
block|}
end_function
begin_comment
comment|/* End of pcre16_ord2utf16.c */
end_comment
end_unit
