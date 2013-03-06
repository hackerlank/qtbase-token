begin_unit
begin_define
DECL|macro|HAVE_MEMMOVE
define|#
directive|define
name|HAVE_MEMMOVE
value|1
end_define
begin_define
DECL|macro|HAVE_STDLIB_H
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define
begin_define
DECL|macro|HAVE_STRING_H
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define
begin_define
DECL|macro|LINK_SIZE
define|#
directive|define
name|LINK_SIZE
value|2
end_define
begin_define
DECL|macro|MATCH_LIMIT
define|#
directive|define
name|MATCH_LIMIT
value|10000000
end_define
begin_define
DECL|macro|MATCH_LIMIT_RECURSION
define|#
directive|define
name|MATCH_LIMIT_RECURSION
value|MATCH_LIMIT
end_define
begin_define
DECL|macro|MAX_NAME_COUNT
define|#
directive|define
name|MAX_NAME_COUNT
value|10000
end_define
begin_define
DECL|macro|MAX_NAME_SIZE
define|#
directive|define
name|MAX_NAME_SIZE
value|32
end_define
begin_define
DECL|macro|NEWLINE
define|#
directive|define
name|NEWLINE
value|10
end_define
begin_define
DECL|macro|POSIX_MALLOC_THRESHOLD
define|#
directive|define
name|POSIX_MALLOC_THRESHOLD
value|10
end_define
begin_define
DECL|macro|SUPPORT_UCP
define|#
directive|define
name|SUPPORT_UCP
end_define
begin_define
DECL|macro|SUPPORT_UTF16
define|#
directive|define
name|SUPPORT_UTF16
end_define
begin_comment
comment|/*     man 3 pcrejit for a list of supported platforms;     as PCRE 8.30, stable JIT support is available for:     - ARM v5, v7, and Thumb2 (__GNUC__ compilers only)     - x86/x86-64     - MIPS 32bit (__GNUC__ compilers only) */
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PCRE_DISABLE_JIT
argument_list|)
operator|&&
operator|(
expr|\
comment|/* ARM */
expr|\
operator|(
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|||
name|defined
argument_list|(
name|__TARGET_ARCH_ARM
argument_list|)
operator|)
operator|)
expr|\
comment|/* x86 32/64 */
expr|\
operator|||
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_IX86
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__x86_64
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_X64
argument_list|)
expr|\
comment|/* MIPS32 */
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|__GNUC__
argument_list|)
expr|\
operator|&&
operator|(
name|defined
argument_list|(
name|__mips
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|)
expr|\
operator|&&
operator|!
operator|(
name|defined
argument_list|(
name|_MIPS_ARCH_MIPS64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips64
argument_list|)
operator|)
operator|)
operator|)
end_if
begin_define
DECL|macro|SUPPORT_JIT
define|#
directive|define
name|SUPPORT_JIT
end_define
begin_endif
endif|#
directive|endif
end_endif
end_unit
