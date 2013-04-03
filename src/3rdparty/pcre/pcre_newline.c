begin_unit
begin_comment
comment|/************************************************* *      Perl-Compatible Regular Expressions       * *************************************************/
end_comment
begin_comment
comment|/* PCRE is a library of functions to support regular expressions whose syntax and semantics are as close as possible to those of the Perl 5 language.                         Written by Philip Hazel            Copyright (c) 1997-2012 University of Cambridge  ----------------------------------------------------------------------------- Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      * Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.      * Neither the name of the University of Cambridge nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ----------------------------------------------------------------------------- */
end_comment
begin_comment
comment|/* This module contains internal functions for testing newlines when more than one kind of newline is to be recognized. When a newline is found, its length is returned. In principle, we could implement several newline "types", each referring to a different set of newline characters. At present, PCRE supports only NLTYPE_FIXED, which gets handled without these functions, NLTYPE_ANYCRLF, and NLTYPE_ANY. The full list of Unicode newline characters is taken from http://unicode.org/unicode/reports/tr18/. */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|PCRE_HAVE_CONFIG_H
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
begin_include
include|#
directive|include
file|"pcre_internal.h"
end_include
begin_comment
comment|/************************************************* *      Check for newline at given position       * *************************************************/
end_comment
begin_comment
comment|/* It is guaranteed that the initial value of ptr is less than the end of the string that is being processed.  Arguments:   ptr          pointer to possible newline   type         the newline type   endptr       pointer to the end of the string   lenptr       where to return the length   utf          TRUE if in utf mode  Returns:       TRUE or FALSE */
end_comment
begin_function
name|BOOL
DECL|function|is_newline
name|PRIV
function|(
name|is_newline
function|)
parameter_list|(
name|PCRE_PUCHAR
name|ptr
parameter_list|,
name|int
name|type
parameter_list|,
name|PCRE_PUCHAR
name|endptr
parameter_list|,
name|int
modifier|*
name|lenptr
parameter_list|,
name|BOOL
name|utf
parameter_list|)
block|{
name|pcre_uint32
name|c
decl_stmt|;
operator|(
name|void
operator|)
name|utf
expr_stmt|;
ifdef|#
directive|ifdef
name|SUPPORT_UTF
if|if
condition|(
name|utf
condition|)
block|{
name|GETCHAR
argument_list|(
name|c
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
comment|/* SUPPORT_UTF */
name|c
operator|=
operator|*
name|ptr
expr_stmt|;
comment|/* Note that this function is called only for ANY or ANYCRLF. */
if|if
condition|(
name|type
operator|==
name|NLTYPE_ANYCRLF
condition|)
switch|switch
condition|(
name|c
condition|)
block|{
case|case
name|CHAR_LF
case|:
operator|*
name|lenptr
operator|=
literal|1
expr_stmt|;
return|return
name|TRUE
return|;
case|case
name|CHAR_CR
case|:
operator|*
name|lenptr
operator|=
operator|(
name|ptr
operator|<
name|endptr
operator|-
literal|1
operator|&&
name|ptr
index|[
literal|1
index|]
operator|==
name|CHAR_LF
operator|)
condition|?
literal|2
else|:
literal|1
expr_stmt|;
return|return
name|TRUE
return|;
default|default:
return|return
name|FALSE
return|;
block|}
comment|/* NLTYPE_ANY */
else|else
switch|switch
condition|(
name|c
condition|)
block|{
ifdef|#
directive|ifdef
name|EBCDIC
case|case
name|CHAR_NEL
case|:
endif|#
directive|endif
case|case
name|CHAR_LF
case|:
case|case
name|CHAR_VT
case|:
case|case
name|CHAR_FF
case|:
operator|*
name|lenptr
operator|=
literal|1
expr_stmt|;
return|return
name|TRUE
return|;
case|case
name|CHAR_CR
case|:
operator|*
name|lenptr
operator|=
operator|(
name|ptr
operator|<
name|endptr
operator|-
literal|1
operator|&&
name|ptr
index|[
literal|1
index|]
operator|==
name|CHAR_LF
operator|)
condition|?
literal|2
else|:
literal|1
expr_stmt|;
return|return
name|TRUE
return|;
ifndef|#
directive|ifndef
name|EBCDIC
ifdef|#
directive|ifdef
name|COMPILE_PCRE8
case|case
name|CHAR_NEL
case|:
operator|*
name|lenptr
operator|=
name|utf
condition|?
literal|2
else|:
literal|1
expr_stmt|;
return|return
name|TRUE
return|;
case|case
literal|0x2028
case|:
comment|/* LS */
case|case
literal|0x2029
case|:
operator|*
name|lenptr
operator|=
literal|3
expr_stmt|;
return|return
name|TRUE
return|;
comment|/* PS */
else|#
directive|else
comment|/* COMPILE_PCRE16 || COMPILE_PCRE32 */
case|case
name|CHAR_NEL
case|:
case|case
literal|0x2028
case|:
comment|/* LS */
case|case
literal|0x2029
case|:
operator|*
name|lenptr
operator|=
literal|1
expr_stmt|;
return|return
name|TRUE
return|;
comment|/* PS */
endif|#
directive|endif
comment|/* COMPILE_PCRE8 */
endif|#
directive|endif
comment|/* Not EBCDIC */
default|default:
return|return
name|FALSE
return|;
block|}
block|}
end_function
begin_comment
comment|/************************************************* *     Check for newline at previous position     * *************************************************/
end_comment
begin_comment
comment|/* It is guaranteed that the initial value of ptr is greater than the start of the string that is being processed.  Arguments:   ptr          pointer to possible newline   type         the newline type   startptr     pointer to the start of the string   lenptr       where to return the length   utf          TRUE if in utf mode  Returns:       TRUE or FALSE */
end_comment
begin_function
name|BOOL
DECL|function|was_newline
name|PRIV
function|(
name|was_newline
function|)
parameter_list|(
name|PCRE_PUCHAR
name|ptr
parameter_list|,
name|int
name|type
parameter_list|,
name|PCRE_PUCHAR
name|startptr
parameter_list|,
name|int
modifier|*
name|lenptr
parameter_list|,
name|BOOL
name|utf
parameter_list|)
block|{
name|pcre_uint32
name|c
decl_stmt|;
operator|(
name|void
operator|)
name|utf
expr_stmt|;
name|ptr
operator|--
expr_stmt|;
ifdef|#
directive|ifdef
name|SUPPORT_UTF
if|if
condition|(
name|utf
condition|)
block|{
name|BACKCHAR
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
name|GETCHAR
argument_list|(
name|c
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
comment|/* SUPPORT_UTF */
name|c
operator|=
operator|*
name|ptr
expr_stmt|;
comment|/* Note that this function is called only for ANY or ANYCRLF. */
if|if
condition|(
name|type
operator|==
name|NLTYPE_ANYCRLF
condition|)
switch|switch
condition|(
name|c
condition|)
block|{
case|case
name|CHAR_LF
case|:
operator|*
name|lenptr
operator|=
operator|(
name|ptr
operator|>
name|startptr
operator|&&
name|ptr
index|[
operator|-
literal|1
index|]
operator|==
name|CHAR_CR
operator|)
condition|?
literal|2
else|:
literal|1
expr_stmt|;
return|return
name|TRUE
return|;
case|case
name|CHAR_CR
case|:
operator|*
name|lenptr
operator|=
literal|1
expr_stmt|;
return|return
name|TRUE
return|;
default|default:
return|return
name|FALSE
return|;
block|}
comment|/* NLTYPE_ANY */
else|else
switch|switch
condition|(
name|c
condition|)
block|{
case|case
name|CHAR_LF
case|:
operator|*
name|lenptr
operator|=
operator|(
name|ptr
operator|>
name|startptr
operator|&&
name|ptr
index|[
operator|-
literal|1
index|]
operator|==
name|CHAR_CR
operator|)
condition|?
literal|2
else|:
literal|1
expr_stmt|;
return|return
name|TRUE
return|;
ifdef|#
directive|ifdef
name|EBCDIC
case|case
name|CHAR_NEL
case|:
endif|#
directive|endif
case|case
name|CHAR_VT
case|:
case|case
name|CHAR_FF
case|:
case|case
name|CHAR_CR
case|:
operator|*
name|lenptr
operator|=
literal|1
expr_stmt|;
return|return
name|TRUE
return|;
ifndef|#
directive|ifndef
name|EBCDIC
ifdef|#
directive|ifdef
name|COMPILE_PCRE8
case|case
name|CHAR_NEL
case|:
operator|*
name|lenptr
operator|=
name|utf
condition|?
literal|2
else|:
literal|1
expr_stmt|;
return|return
name|TRUE
return|;
case|case
literal|0x2028
case|:
comment|/* LS */
case|case
literal|0x2029
case|:
operator|*
name|lenptr
operator|=
literal|3
expr_stmt|;
return|return
name|TRUE
return|;
comment|/* PS */
else|#
directive|else
comment|/* COMPILE_PCRE16 || COMPILE_PCRE32 */
case|case
name|CHAR_NEL
case|:
case|case
literal|0x2028
case|:
comment|/* LS */
case|case
literal|0x2029
case|:
operator|*
name|lenptr
operator|=
literal|1
expr_stmt|;
return|return
name|TRUE
return|;
comment|/* PS */
endif|#
directive|endif
comment|/* COMPILE_PCRE8 */
endif|#
directive|endif
comment|/* NotEBCDIC */
default|default:
return|return
name|FALSE
return|;
block|}
block|}
end_function
begin_comment
comment|/* End of pcre_newline.c */
end_comment
end_unit
