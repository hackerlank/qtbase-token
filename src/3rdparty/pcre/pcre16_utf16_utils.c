begin_unit
begin_comment
comment|/************************************************* *      Perl-Compatible Regular Expressions       * *************************************************/
end_comment
begin_comment
comment|/* PCRE is a library of functions to support regular expressions whose syntax and semantics are as close as possible to those of the Perl 5 language.                         Written by Philip Hazel            Copyright (c) 1997-2012 University of Cambridge  ----------------------------------------------------------------------------- Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      * Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.      * Neither the name of the University of Cambridge nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ----------------------------------------------------------------------------- */
end_comment
begin_comment
comment|/* This module contains a function for converting any UTF-16 character strings to host byte order. */
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
comment|/************************************************* *  Convert any UTF-16 string to host byte order  * *************************************************/
end_comment
begin_comment
comment|/* This function takes an UTF-16 string and converts it to host byte order. The length can be explicitly set, or automatically detected for zero terminated strings. BOMs can be kept or discarded during the conversion. Conversion can be done in place (output == input).  Arguments:   output     the output buffer, its size must be greater              or equal than the input string   input      any UTF-16 string   length     the number of 16-bit units in the input string              can be less than zero for zero terminated strings   host_byte_order              A non-zero value means the input is in host byte              order, which can be dynamically changed by BOMs later.              Initially it contains the starting byte order and returns              with the last byte order so it can be used for stream              processing. It can be NULL, which set the host byte              order mode by default.   keep_boms  for a non-zero value, the BOM (0xfeff) characters              are copied as well  Returns:     the number of 16-bit units placed into the output buffer,              including the zero-terminator */
end_comment
begin_function
name|int
DECL|function|pcre16_utf16_to_host_byte_order
name|pcre16_utf16_to_host_byte_order
parameter_list|(
name|PCRE_UCHAR16
modifier|*
name|output
parameter_list|,
name|PCRE_SPTR16
name|input
parameter_list|,
name|int
name|length
parameter_list|,
name|int
modifier|*
name|host_byte_order
parameter_list|,
name|int
name|keep_boms
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|SUPPORT_UTF
comment|/* This function converts any UTF-16 string to host byte order and optionally removes any Byte Order Marks (BOMS). Returns with the remainig length. */
name|int
name|host_bo
init|=
name|host_byte_order
operator|!=
name|NULL
condition|?
operator|*
name|host_byte_order
else|:
literal|1
decl_stmt|;
name|pcre_uchar
modifier|*
name|optr
init|=
operator|(
name|pcre_uchar
operator|*
operator|)
name|output
decl_stmt|;
specifier|const
name|pcre_uchar
modifier|*
name|iptr
init|=
operator|(
specifier|const
name|pcre_uchar
operator|*
operator|)
name|input
decl_stmt|;
specifier|const
name|pcre_uchar
modifier|*
name|end
decl_stmt|;
comment|/* The c variable must be unsigned. */
specifier|register
name|pcre_uchar
name|c
decl_stmt|;
if|if
condition|(
name|length
operator|<
literal|0
condition|)
name|length
operator|=
name|STRLEN_UC
argument_list|(
name|iptr
argument_list|)
operator|+
literal|1
expr_stmt|;
name|end
operator|=
name|iptr
operator|+
name|length
expr_stmt|;
while|while
condition|(
name|iptr
operator|<
name|end
condition|)
block|{
name|c
operator|=
operator|*
name|iptr
operator|++
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|0xfeff
operator|||
name|c
operator|==
literal|0xfffe
condition|)
block|{
comment|/* Detecting the byte order of the machine is unnecessary, it is     enough to know that the UTF-16 string has the same byte order or not. */
name|host_bo
operator|=
name|c
operator|==
literal|0xfeff
expr_stmt|;
if|if
condition|(
name|keep_boms
operator|!=
literal|0
condition|)
operator|*
name|optr
operator|++
operator|=
literal|0xfeff
expr_stmt|;
else|else
name|length
operator|--
expr_stmt|;
block|}
else|else
operator|*
name|optr
operator|++
operator|=
name|host_bo
condition|?
name|c
else|:
operator|(
operator|(
name|c
operator|>>
literal|8
operator|)
operator||
operator|(
name|c
operator|<<
literal|8
operator|)
operator|)
expr_stmt|;
comment|/* Flip bytes if needed. */
block|}
if|if
condition|(
name|host_byte_order
operator|!=
name|NULL
condition|)
operator|*
name|host_byte_order
operator|=
name|host_bo
expr_stmt|;
else|#
directive|else
comment|/* Not SUPPORT_UTF */
call|(
name|void
call|)
argument_list|(
name|output
argument_list|)
expr_stmt|;
comment|/* Keep picky compilers happy */
call|(
name|void
call|)
argument_list|(
name|input
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|keep_boms
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|host_byte_order
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SUPPORT_UTF */
return|return
name|length
return|;
block|}
end_function
begin_comment
comment|/* End of pcre16_utf16_utils.c */
end_comment
end_unit
