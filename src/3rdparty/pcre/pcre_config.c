begin_unit
begin_comment
comment|/************************************************* *      Perl-Compatible Regular Expressions       * *************************************************/
end_comment
begin_comment
comment|/* PCRE is a library of functions to support regular expressions whose syntax and semantics are as close as possible to those of the Perl 5 language.                         Written by Philip Hazel            Copyright (c) 1997-2012 University of Cambridge  ----------------------------------------------------------------------------- Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      * Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.      * Neither the name of the University of Cambridge nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ----------------------------------------------------------------------------- */
end_comment
begin_comment
comment|/* This module contains the external function pcre_config(). */
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
begin_comment
comment|/* Keep the original link size. */
end_comment
begin_decl_stmt
DECL|variable|real_link_size
specifier|static
name|int
name|real_link_size
init|=
name|LINK_SIZE
decl_stmt|;
end_decl_stmt
begin_include
include|#
directive|include
file|"pcre_internal.h"
end_include
begin_comment
comment|/************************************************* * Return info about what features are configured * *************************************************/
end_comment
begin_comment
comment|/* This function has an extensible interface so that additional items can be added compatibly.  Arguments:   what             what information is required   where            where to put the information  Returns:           0 if data returned, negative on error */
end_comment
begin_if
if|#
directive|if
name|defined
name|COMPILE_PCRE8
end_if
begin_decl_stmt
name|PCRE_EXP_DEFN
name|int
name|PCRE_CALL_CONVENTION
DECL|function|pcre_config
name|pcre_config
argument_list|(
name|int
name|what
argument_list|,
name|void
operator|*
name|where
argument_list|)
elif|#
directive|elif
name|defined
name|COMPILE_PCRE16
name|PCRE_EXP_DEFN
name|int
name|PCRE_CALL_CONVENTION
name|pcre16_config
argument_list|(
name|int
name|what
argument_list|,
name|void
operator|*
name|where
argument_list|)
elif|#
directive|elif
name|defined
name|COMPILE_PCRE32
name|PCRE_EXP_DEFN
name|int
name|PCRE_CALL_CONVENTION
name|pcre32_config
argument_list|(
name|int
name|what
argument_list|,
name|void
operator|*
name|where
argument_list|)
endif|#
directive|endif
block|{
switch|switch
condition|(
name|what
condition|)
block|{
case|case
name|PCRE_CONFIG_UTF8
case|:
if|#
directive|if
name|defined
name|COMPILE_PCRE16
operator|||
name|defined
name|COMPILE_PCRE32
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
literal|0
expr_stmt|;
return|return
name|PCRE_ERROR_BADOPTION
return|;
else|#
directive|else
if|#
directive|if
name|defined
name|SUPPORT_UTF
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
literal|1
expr_stmt|;
else|#
directive|else
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
break|break;
endif|#
directive|endif
case|case
name|PCRE_CONFIG_UTF16
case|:
if|#
directive|if
name|defined
name|COMPILE_PCRE8
operator|||
name|defined
name|COMPILE_PCRE32
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
literal|0
expr_stmt|;
return|return
name|PCRE_ERROR_BADOPTION
return|;
else|#
directive|else
if|#
directive|if
name|defined
name|SUPPORT_UTF
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
literal|1
expr_stmt|;
else|#
directive|else
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
break|break;
endif|#
directive|endif
case|case
name|PCRE_CONFIG_UTF32
case|:
if|#
directive|if
name|defined
name|COMPILE_PCRE8
operator|||
name|defined
name|COMPILE_PCRE16
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
literal|0
expr_stmt|;
return|return
name|PCRE_ERROR_BADOPTION
return|;
else|#
directive|else
if|#
directive|if
name|defined
name|SUPPORT_UTF
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
literal|1
expr_stmt|;
else|#
directive|else
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
break|break;
endif|#
directive|endif
case|case
name|PCRE_CONFIG_UNICODE_PROPERTIES
case|:
ifdef|#
directive|ifdef
name|SUPPORT_UCP
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
literal|1
expr_stmt|;
else|#
directive|else
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
break|break;
case|case
name|PCRE_CONFIG_JIT
case|:
ifdef|#
directive|ifdef
name|SUPPORT_JIT
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
literal|1
expr_stmt|;
else|#
directive|else
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
break|break;
case|case
name|PCRE_CONFIG_JITTARGET
case|:
ifdef|#
directive|ifdef
name|SUPPORT_JIT
operator|*
operator|(
operator|(
specifier|const
name|char
operator|*
operator|*
operator|)
name|where
operator|)
operator|=
name|PRIV
argument_list|(
name|jit_get_target
argument_list|)
argument_list|()
expr_stmt|;
else|#
directive|else
operator|*
operator|(
operator|(
specifier|const
name|char
operator|*
operator|*
operator|)
name|where
operator|)
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
break|break;
case|case
name|PCRE_CONFIG_NEWLINE
case|:
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
name|NEWLINE
expr_stmt|;
break|break;
case|case
name|PCRE_CONFIG_BSR
case|:
ifdef|#
directive|ifdef
name|BSR_ANYCRLF
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
literal|1
expr_stmt|;
else|#
directive|else
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
break|break;
case|case
name|PCRE_CONFIG_LINK_SIZE
case|:
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
name|real_link_size
expr_stmt|;
break|break;
case|case
name|PCRE_CONFIG_POSIX_MALLOC_THRESHOLD
case|:
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
name|POSIX_MALLOC_THRESHOLD
expr_stmt|;
break|break;
case|case
name|PCRE_CONFIG_MATCH_LIMIT
case|:
operator|*
operator|(
operator|(
name|unsigned
name|long
name|int
operator|*
operator|)
name|where
operator|)
operator|=
name|MATCH_LIMIT
expr_stmt|;
break|break;
case|case
name|PCRE_CONFIG_MATCH_LIMIT_RECURSION
case|:
operator|*
operator|(
operator|(
name|unsigned
name|long
name|int
operator|*
operator|)
name|where
operator|)
operator|=
name|MATCH_LIMIT_RECURSION
expr_stmt|;
break|break;
case|case
name|PCRE_CONFIG_STACKRECURSE
case|:
ifdef|#
directive|ifdef
name|NO_RECURSE
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
literal|0
expr_stmt|;
else|#
directive|else
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|where
operator|)
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
break|break;
default|default:
return|return
name|PCRE_ERROR_BADOPTION
return|;
block|}
return|return
literal|0
return|;
block|}
end_decl_stmt
begin_comment
comment|/* End of pcre_config.c */
end_comment
end_unit
