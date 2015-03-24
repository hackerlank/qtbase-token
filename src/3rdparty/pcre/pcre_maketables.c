begin_unit
begin_comment
comment|/************************************************* *      Perl-Compatible Regular Expressions       * *************************************************/
end_comment
begin_comment
comment|/* PCRE is a library of functions to support regular expressions whose syntax and semantics are as close as possible to those of the Perl 5 language.                         Written by Philip Hazel            Copyright (c) 1997-2012 University of Cambridge  ----------------------------------------------------------------------------- Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      * Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.      * Neither the name of the University of Cambridge nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ----------------------------------------------------------------------------- */
end_comment
begin_comment
comment|/* This module contains the external function pcre_maketables(), which builds character tables for PCRE in the current locale. The file is compiled on its own as part of the PCRE library. However, it is also included in the compilation of dftables.c, in which case the macro DFTABLES is defined. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DFTABLES
end_ifndef
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
begin_include
include|#
directive|include
file|"pcre_internal.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/************************************************* *           Create PCRE character tables         * *************************************************/
end_comment
begin_comment
comment|/* This function builds a set of character tables for use by PCRE and returns a pointer to them. They are build using the ctype functions, and consequently their contents will depend upon the current locale setting. When compiled as part of the library, the store is obtained via PUBL(malloc)(), but when compiled inside dftables, use malloc().  Arguments:   none Returns:     pointer to the contiguous block of data */
end_comment
begin_if
if|#
directive|if
name|defined
name|COMPILE_PCRE8
end_if
begin_decl_stmt
specifier|const
name|unsigned
name|char
modifier|*
DECL|function|pcre_maketables
name|pcre_maketables
argument_list|(
name|void
argument_list|)
elif|#
directive|elif
name|defined
name|COMPILE_PCRE16
decl|const
name|unsigned
name|char
modifier|*
name|pcre16_maketables
argument_list|(
name|void
argument_list|)
elif|#
directive|elif
name|defined
name|COMPILE_PCRE32
decl|const
name|unsigned
name|char
modifier|*
name|pcre32_maketables
argument_list|(
name|void
argument_list|)
endif|#
directive|endif
block|{
name|unsigned
name|char
modifier|*
name|yield
decl_stmt|,
modifier|*
name|p
decl_stmt|;
name|int
name|i
decl_stmt|;
ifndef|#
directive|ifndef
name|DFTABLES
name|yield
operator|=
operator|(
name|unsigned
name|char
operator|*
operator|)
operator|(
name|PUBL
argument_list|(
name|malloc
argument_list|)
operator|)
operator|(
name|tables_length
operator|)
expr_stmt|;
else|#
directive|else
name|yield
operator|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|tables_length
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|yield
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|p
operator|=
name|yield
expr_stmt|;
comment|/* First comes the lower casing table */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|256
condition|;
name|i
operator|++
control|)
operator|*
name|p
operator|++
operator|=
name|tolower
argument_list|(
name|i
argument_list|)
expr_stmt|;
comment|/* Next the case-flipping table */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|256
condition|;
name|i
operator|++
control|)
operator|*
name|p
operator|++
operator|=
name|islower
argument_list|(
name|i
argument_list|)
condition|?
name|toupper
argument_list|(
name|i
argument_list|)
else|:
name|tolower
argument_list|(
name|i
argument_list|)
expr_stmt|;
comment|/* Then the character class tables. Don't try to be clever and save effort on exclusive ones - in some locales things may be different.  Note that the table for "space" includes everything "isspace" gives, including VT in the default locale. This makes it work for the POSIX class [:space:]. From release 8.34 is is also correct for Perl space, because Perl added VT at release 5.18.  Note also that it is possible for a character to be alnum or alpha without being lower or upper, such as "male and female ordinals" (\xAA and \xBA) in the fr_FR locale (at least under Debian Linux's locales as of 12/2005). So we must test for alnum specially. */
name|memset
argument_list|(
name|p
argument_list|,
literal|0
argument_list|,
name|cbit_length
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|256
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|isdigit
argument_list|(
name|i
argument_list|)
condition|)
name|p
index|[
name|cbit_digit
operator|+
name|i
operator|/
literal|8
index|]
operator||=
literal|1
operator|<<
operator|(
name|i
operator|&
literal|7
operator|)
expr_stmt|;
if|if
condition|(
name|isupper
argument_list|(
name|i
argument_list|)
condition|)
name|p
index|[
name|cbit_upper
operator|+
name|i
operator|/
literal|8
index|]
operator||=
literal|1
operator|<<
operator|(
name|i
operator|&
literal|7
operator|)
expr_stmt|;
if|if
condition|(
name|islower
argument_list|(
name|i
argument_list|)
condition|)
name|p
index|[
name|cbit_lower
operator|+
name|i
operator|/
literal|8
index|]
operator||=
literal|1
operator|<<
operator|(
name|i
operator|&
literal|7
operator|)
expr_stmt|;
if|if
condition|(
name|isalnum
argument_list|(
name|i
argument_list|)
condition|)
name|p
index|[
name|cbit_word
operator|+
name|i
operator|/
literal|8
index|]
operator||=
literal|1
operator|<<
operator|(
name|i
operator|&
literal|7
operator|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
literal|'_'
condition|)
name|p
index|[
name|cbit_word
operator|+
name|i
operator|/
literal|8
index|]
operator||=
literal|1
operator|<<
operator|(
name|i
operator|&
literal|7
operator|)
expr_stmt|;
if|if
condition|(
name|isspace
argument_list|(
name|i
argument_list|)
condition|)
name|p
index|[
name|cbit_space
operator|+
name|i
operator|/
literal|8
index|]
operator||=
literal|1
operator|<<
operator|(
name|i
operator|&
literal|7
operator|)
expr_stmt|;
if|if
condition|(
name|isxdigit
argument_list|(
name|i
argument_list|)
condition|)
name|p
index|[
name|cbit_xdigit
operator|+
name|i
operator|/
literal|8
index|]
operator||=
literal|1
operator|<<
operator|(
name|i
operator|&
literal|7
operator|)
expr_stmt|;
if|if
condition|(
name|isgraph
argument_list|(
name|i
argument_list|)
condition|)
name|p
index|[
name|cbit_graph
operator|+
name|i
operator|/
literal|8
index|]
operator||=
literal|1
operator|<<
operator|(
name|i
operator|&
literal|7
operator|)
expr_stmt|;
if|if
condition|(
name|isprint
argument_list|(
name|i
argument_list|)
condition|)
name|p
index|[
name|cbit_print
operator|+
name|i
operator|/
literal|8
index|]
operator||=
literal|1
operator|<<
operator|(
name|i
operator|&
literal|7
operator|)
expr_stmt|;
if|if
condition|(
name|ispunct
argument_list|(
name|i
argument_list|)
condition|)
name|p
index|[
name|cbit_punct
operator|+
name|i
operator|/
literal|8
index|]
operator||=
literal|1
operator|<<
operator|(
name|i
operator|&
literal|7
operator|)
expr_stmt|;
if|if
condition|(
name|iscntrl
argument_list|(
name|i
argument_list|)
condition|)
name|p
index|[
name|cbit_cntrl
operator|+
name|i
operator|/
literal|8
index|]
operator||=
literal|1
operator|<<
operator|(
name|i
operator|&
literal|7
operator|)
expr_stmt|;
block|}
name|p
operator|+=
name|cbit_length
expr_stmt|;
comment|/* Finally, the character type table. In this, we used to exclude VT from the white space chars, because Perl didn't recognize it as such for \s and for comments within regexes. However, Perl changed at release 5.18, so PCRE changed at release 8.34. */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|256
condition|;
name|i
operator|++
control|)
block|{
name|int
name|x
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|isspace
argument_list|(
name|i
argument_list|)
condition|)
name|x
operator|+=
name|ctype_space
expr_stmt|;
if|if
condition|(
name|isalpha
argument_list|(
name|i
argument_list|)
condition|)
name|x
operator|+=
name|ctype_letter
expr_stmt|;
if|if
condition|(
name|isdigit
argument_list|(
name|i
argument_list|)
condition|)
name|x
operator|+=
name|ctype_digit
expr_stmt|;
if|if
condition|(
name|isxdigit
argument_list|(
name|i
argument_list|)
condition|)
name|x
operator|+=
name|ctype_xdigit
expr_stmt|;
if|if
condition|(
name|isalnum
argument_list|(
name|i
argument_list|)
operator|||
name|i
operator|==
literal|'_'
condition|)
name|x
operator|+=
name|ctype_word
expr_stmt|;
comment|/* Note: strchr includes the terminating zero in the characters it considers.   In this instance, that is ok because we want binary zero to be flagged as a   meta-character, which in this sense is any character that terminates a run   of data characters. */
if|if
condition|(
name|strchr
argument_list|(
literal|"\\*+?{^.$|()["
argument_list|,
name|i
argument_list|)
operator|!=
literal|0
condition|)
name|x
operator|+=
name|ctype_meta
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|x
expr_stmt|;
block|}
return|return
name|yield
return|;
block|}
end_decl_stmt
begin_comment
comment|/* End of pcre_maketables.c */
end_comment
end_unit
