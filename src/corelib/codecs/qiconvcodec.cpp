begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qiconvcodec_p.h"
end_include
begin_include
include|#
directive|include
file|"qtextcodec_p.h"
end_include
begin_include
include|#
directive|include
file|<qlibrary.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qthreadstorage.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<locale.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<dlfcn.h>
end_include
begin_comment
comment|// unistd.h is needed for the _XOPEN_UNIX macro
end_comment
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_XOPEN_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_QNX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_OSF
argument_list|)
end_if
begin_include
include|#
directive|include
file|<langinfo.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_HPUX
argument_list|)
end_if
begin_define
DECL|macro|NO_BOM
define|#
directive|define
name|NO_BOM
end_define
begin_define
DECL|macro|UTF16
define|#
directive|define
name|UTF16
value|"ucs2"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_AIX
argument_list|)
end_elif
begin_define
DECL|macro|NO_BOM
define|#
directive|define
name|NO_BOM
end_define
begin_define
DECL|macro|UTF16
define|#
directive|define
name|UTF16
value|"UCS-2"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_FREEBSD
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_elif
begin_define
DECL|macro|NO_BOM
define|#
directive|define
name|NO_BOM
end_define
begin_if
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_BIG_ENDIAN
end_if
begin_define
DECL|macro|UTF16
define|#
directive|define
name|UTF16
value|"UTF-16BE"
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|UTF16
define|#
directive|define
name|UTF16
value|"UTF-16LE"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|UTF16
define|#
directive|define
name|UTF16
value|"UTF-16"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_ifndef
ifndef|#
directive|ifndef
name|GNU_LIBICONV
end_ifndef
begin_define
DECL|macro|GNU_LIBICONV
define|#
directive|define
name|GNU_LIBICONV
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|Ptr_iconv_open
typedef|typedef
name|iconv_t
function_decl|(
modifier|*
name|Ptr_iconv_open
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|Ptr_iconv
typedef|typedef
name|size_t
function_decl|(
modifier|*
name|Ptr_iconv
function_decl|)
parameter_list|(
name|iconv_t
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|Ptr_iconv_close
typedef|typedef
name|int
function_decl|(
modifier|*
name|Ptr_iconv_close
function_decl|)
parameter_list|(
name|iconv_t
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
DECL|variable|ptr_iconv_open
specifier|static
name|Ptr_iconv_open
name|ptr_iconv_open
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ptr_iconv
specifier|static
name|Ptr_iconv
name|ptr_iconv
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ptr_iconv_close
specifier|static
name|Ptr_iconv_close
name|ptr_iconv_close
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
specifier|extern
name|bool
name|qt_locale_initialized
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QIconvCodec
name|QIconvCodec
operator|::
name|QIconvCodec
parameter_list|()
member_init_list|:
name|utf16Codec
argument_list|(
literal|0
argument_list|)
block|{
name|utf16Codec
operator|=
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
literal|1015
argument_list|)
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
name|utf16Codec
operator|!=
literal|0
argument_list|,
literal|"QIconvCodec::convertToUnicode"
argument_list|,
literal|"internal error, UTF-16 codec not found"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|utf16Codec
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"QIconvCodec::convertToUnicode: internal error, UTF-16 codec not found\n"
argument_list|)
expr_stmt|;
name|utf16Codec
operator|=
cast|reinterpret_cast
argument_list|<
name|QTextCodec
operator|*
argument_list|>
argument_list|(
operator|~
literal|0
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
if|if
condition|(
name|ptr_iconv_open
operator|==
literal|0
condition|)
block|{
name|QLibrary
name|libiconv
argument_list|(
name|QLatin1String
argument_list|(
literal|"/usr/lib/libiconv"
argument_list|)
argument_list|)
decl_stmt|;
name|libiconv
operator|.
name|setLoadHints
argument_list|(
name|QLibrary
operator|::
name|ExportExternalSymbolsHint
argument_list|)
expr_stmt|;
name|ptr_iconv_open
operator|=
cast|reinterpret_cast
argument_list|<
name|Ptr_iconv_open
argument_list|>
argument_list|(
name|libiconv
operator|.
name|resolve
argument_list|(
literal|"libiconv_open"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ptr_iconv_open
condition|)
name|ptr_iconv_open
operator|=
cast|reinterpret_cast
argument_list|<
name|Ptr_iconv_open
argument_list|>
argument_list|(
name|libiconv
operator|.
name|resolve
argument_list|(
literal|"iconv_open"
argument_list|)
argument_list|)
expr_stmt|;
name|ptr_iconv
operator|=
cast|reinterpret_cast
argument_list|<
name|Ptr_iconv
argument_list|>
argument_list|(
name|libiconv
operator|.
name|resolve
argument_list|(
literal|"libiconv"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ptr_iconv
condition|)
name|ptr_iconv
operator|=
cast|reinterpret_cast
argument_list|<
name|Ptr_iconv
argument_list|>
argument_list|(
name|libiconv
operator|.
name|resolve
argument_list|(
literal|"iconv"
argument_list|)
argument_list|)
expr_stmt|;
name|ptr_iconv_close
operator|=
cast|reinterpret_cast
argument_list|<
name|Ptr_iconv_close
argument_list|>
argument_list|(
name|libiconv
operator|.
name|resolve
argument_list|(
literal|"libiconv_close"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ptr_iconv_close
condition|)
name|ptr_iconv_close
operator|=
cast|reinterpret_cast
argument_list|<
name|Ptr_iconv_close
argument_list|>
argument_list|(
name|libiconv
operator|.
name|resolve
argument_list|(
literal|"iconv_close"
argument_list|)
argument_list|)
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
name|ptr_iconv_open
operator|&&
name|ptr_iconv
operator|&&
name|ptr_iconv_close
argument_list|,
literal|"QIconvCodec::QIconvCodec()"
argument_list|,
literal|"internal error, could not resolve the iconv functions"
argument_list|)
expr_stmt|;
DECL|macro|iconv_open
undef|#
directive|undef
name|iconv_open
DECL|macro|iconv_open
define|#
directive|define
name|iconv_open
value|ptr_iconv_open
DECL|macro|iconv
undef|#
directive|undef
name|iconv
DECL|macro|iconv
define|#
directive|define
name|iconv
value|ptr_iconv
DECL|macro|iconv_close
undef|#
directive|undef
name|iconv_close
DECL|macro|iconv_close
define|#
directive|define
name|iconv_close
value|ptr_iconv_close
block|}
endif|#
directive|endif
block|}
end_constructor
begin_destructor
DECL|function|~QIconvCodec
name|QIconvCodec
operator|::
name|~
name|QIconvCodec
parameter_list|()
block|{ }
end_destructor
begin_constructor
DECL|function|IconvState
name|QIconvCodec
operator|::
name|IconvState
operator|::
name|IconvState
parameter_list|(
name|iconv_t
name|x
parameter_list|)
member_init_list|:
name|buffer
argument_list|(
name|array
argument_list|)
member_init_list|,
name|bufferLen
argument_list|(
sizeof|sizeof
name|array
argument_list|)
member_init_list|,
name|cd
argument_list|(
name|x
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~IconvState
name|QIconvCodec
operator|::
name|IconvState
operator|::
name|~
name|IconvState
parameter_list|()
block|{
if|if
condition|(
name|cd
operator|!=
cast|reinterpret_cast
argument_list|<
name|iconv_t
argument_list|>
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
name|iconv_close
argument_list|(
name|cd
argument_list|)
expr_stmt|;
if|if
condition|(
name|buffer
operator|!=
name|array
condition|)
operator|delete
index|[]
name|buffer
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|saveChars
name|void
name|QIconvCodec
operator|::
name|IconvState
operator|::
name|saveChars
parameter_list|(
specifier|const
name|char
modifier|*
name|c
parameter_list|,
name|int
name|count
parameter_list|)
block|{
if|if
condition|(
name|count
operator|>
name|bufferLen
condition|)
block|{
if|if
condition|(
name|buffer
operator|!=
name|array
condition|)
operator|delete
index|[]
name|buffer
expr_stmt|;
name|buffer
operator|=
operator|new
name|char
index|[
name|bufferLen
operator|=
name|count
index|]
expr_stmt|;
block|}
name|memcpy
argument_list|(
name|buffer
argument_list|,
name|c
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qIconvCodecStateFree
specifier|static
name|void
name|qIconvCodecStateFree
parameter_list|(
name|QTextCodec
operator|::
name|ConverterState
modifier|*
name|state
parameter_list|)
block|{
operator|delete
cast|reinterpret_cast
argument_list|<
name|QIconvCodec
operator|::
name|IconvState
operator|*
argument_list|>
argument_list|(
name|state
operator|->
name|d
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QThreadStorage<QIconvCodec::IconvState *>
argument_list|,
argument|toUnicodeState
argument_list|)
end_macro
begin_function
DECL|function|convertToUnicode
name|QString
name|QIconvCodec
operator|::
name|convertToUnicode
parameter_list|(
specifier|const
name|char
modifier|*
name|chars
parameter_list|,
name|int
name|len
parameter_list|,
name|ConverterState
modifier|*
name|convState
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|utf16Codec
operator|==
cast|reinterpret_cast
argument_list|<
name|QTextCodec
operator|*
argument_list|>
argument_list|(
operator|~
literal|0
argument_list|)
condition|)
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
name|chars
argument_list|,
name|len
argument_list|)
return|;
name|int
name|invalidCount
init|=
literal|0
decl_stmt|;
name|int
name|remainingCount
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|remainingBuffer
init|=
literal|0
decl_stmt|;
name|IconvState
modifier|*
name|temporaryState
init|=
literal|0
decl_stmt|;
name|IconvState
modifier|*
modifier|*
name|pstate
decl_stmt|;
if|if
condition|(
name|convState
condition|)
block|{
comment|// stateful conversion
name|pstate
operator|=
cast|reinterpret_cast
argument_list|<
name|IconvState
operator|*
operator|*
argument_list|>
argument_list|(
operator|&
name|convState
operator|->
name|d
argument_list|)
expr_stmt|;
if|if
condition|(
name|convState
operator|->
name|d
condition|)
block|{
comment|// restore state
name|remainingCount
operator|=
name|convState
operator|->
name|remainingChars
expr_stmt|;
name|remainingBuffer
operator|=
operator|(
operator|*
name|pstate
operator|)
operator|->
name|buffer
expr_stmt|;
block|}
else|else
block|{
comment|// first time
name|convState
operator|->
name|flags
operator||=
name|FreeFunction
expr_stmt|;
name|QTextCodecUnalignedPointer
operator|::
name|encode
argument_list|(
name|convState
operator|->
name|state_data
argument_list|,
name|qIconvCodecStateFree
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|QThreadStorage
argument_list|<
name|QIconvCodec
operator|::
name|IconvState
operator|*
argument_list|>
modifier|*
name|ts
init|=
name|toUnicodeState
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|qt_locale_initialized
operator|||
operator|!
name|ts
condition|)
block|{
comment|// we're running after the Q_GLOBAL_STATIC has been deleted
comment|// or before the QCoreApplication initialization
comment|// bad programmer, no cookie for you
name|pstate
operator|=
operator|&
name|temporaryState
expr_stmt|;
block|}
else|else
block|{
comment|// stateless conversion -- use thread-local data
name|pstate
operator|=
operator|&
name|toUnicodeState
argument_list|()
operator|->
name|localData
argument_list|()
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
operator|*
name|pstate
condition|)
block|{
comment|// first time, create the state
name|iconv_t
name|cd
init|=
name|QIconvCodec
operator|::
name|createIconv_t
argument_list|(
name|UTF16
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|cd
operator|==
cast|reinterpret_cast
argument_list|<
name|iconv_t
argument_list|>
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
block|{
specifier|static
name|int
name|reported
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|reported
operator|++
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"QIconvCodec::convertToUnicode: using Latin-1 for conversion, iconv_open failed\n"
argument_list|)
expr_stmt|;
block|}
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
name|chars
argument_list|,
name|len
argument_list|)
return|;
block|}
operator|*
name|pstate
operator|=
operator|new
name|IconvState
argument_list|(
name|cd
argument_list|)
expr_stmt|;
block|}
name|IconvState
modifier|*
name|state
init|=
operator|*
name|pstate
decl_stmt|;
name|size_t
name|inBytesLeft
init|=
name|len
decl_stmt|;
comment|// best case assumption, each byte is converted into one UTF-16 character, plus 2 bytes for the BOM
ifdef|#
directive|ifdef
name|GNU_LIBICONV
comment|// GNU doesn't disagree with POSIX :/
specifier|const
name|char
modifier|*
name|inBytes
init|=
name|chars
decl_stmt|;
else|#
directive|else
name|char
modifier|*
name|inBytes
init|=
cast|const_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|chars
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|QByteArray
name|in
decl_stmt|;
if|if
condition|(
name|remainingCount
condition|)
block|{
comment|// we have to prepend the remaining bytes from the previous conversion
name|inBytesLeft
operator|+=
name|remainingCount
expr_stmt|;
name|in
operator|.
name|resize
argument_list|(
name|inBytesLeft
argument_list|)
expr_stmt|;
name|inBytes
operator|=
name|in
operator|.
name|data
argument_list|()
expr_stmt|;
name|memcpy
argument_list|(
name|in
operator|.
name|data
argument_list|()
argument_list|,
name|remainingBuffer
argument_list|,
name|remainingCount
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|in
operator|.
name|data
argument_list|()
operator|+
name|remainingCount
argument_list|,
name|chars
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|remainingCount
operator|=
literal|0
expr_stmt|;
block|}
name|size_t
name|outBytesLeft
init|=
name|len
operator|*
literal|2
operator|+
literal|2
decl_stmt|;
name|QByteArray
name|ba
argument_list|(
name|outBytesLeft
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
name|char
modifier|*
name|outBytes
init|=
name|ba
operator|.
name|data
argument_list|()
decl_stmt|;
do|do
block|{
name|size_t
name|ret
init|=
name|iconv
argument_list|(
name|state
operator|->
name|cd
argument_list|,
operator|&
name|inBytes
argument_list|,
operator|&
name|inBytesLeft
argument_list|,
operator|&
name|outBytes
argument_list|,
operator|&
name|outBytesLeft
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|==
operator|(
name|size_t
operator|)
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|errno
operator|==
name|E2BIG
condition|)
block|{
name|int
name|offset
init|=
name|ba
operator|.
name|size
argument_list|()
operator|-
name|outBytesLeft
decl_stmt|;
name|ba
operator|.
name|resize
argument_list|(
name|ba
operator|.
name|size
argument_list|()
operator|*
literal|2
argument_list|)
expr_stmt|;
name|outBytes
operator|=
name|ba
operator|.
name|data
argument_list|()
operator|+
name|offset
expr_stmt|;
name|outBytesLeft
operator|=
name|ba
operator|.
name|size
argument_list|()
operator|-
name|offset
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|errno
operator|==
name|EILSEQ
condition|)
block|{
comment|// conversion stopped because of an invalid character in the sequence
operator|++
name|invalidCount
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|errno
operator|==
name|EINVAL
operator|&&
name|convState
condition|)
block|{
comment|// conversion stopped because the remaining inBytesLeft make up
comment|// an incomplete multi-byte sequence; save them for later
name|state
operator|->
name|saveChars
argument_list|(
name|inBytes
argument_list|,
name|inBytesLeft
argument_list|)
expr_stmt|;
name|remainingCount
operator|=
name|inBytesLeft
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|errno
operator|==
name|EILSEQ
operator|||
name|errno
operator|==
name|EINVAL
condition|)
block|{
comment|// skip the next character
operator|++
name|inBytes
expr_stmt|;
operator|--
name|inBytesLeft
expr_stmt|;
continue|continue;
block|}
comment|// some other error
comment|// note, cannot use qWarning() since we are implementing the codecForLocale :)
name|perror
argument_list|(
literal|"QIconvCodec::convertToUnicode: using Latin-1 for conversion, iconv failed"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|convState
condition|)
block|{
comment|// reset state
name|iconv
argument_list|(
name|state
operator|->
name|cd
argument_list|,
literal|0
argument_list|,
operator|&
name|inBytesLeft
argument_list|,
literal|0
argument_list|,
operator|&
name|outBytesLeft
argument_list|)
expr_stmt|;
block|}
operator|delete
name|temporaryState
expr_stmt|;
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
name|chars
argument_list|,
name|len
argument_list|)
return|;
block|}
block|}
do|while
condition|(
name|inBytesLeft
operator|!=
literal|0
condition|)
do|;
name|QString
name|s
init|=
name|utf16Codec
operator|->
name|toUnicode
argument_list|(
name|ba
operator|.
name|constData
argument_list|()
argument_list|,
name|ba
operator|.
name|size
argument_list|()
operator|-
name|outBytesLeft
argument_list|)
decl_stmt|;
if|if
condition|(
name|convState
condition|)
block|{
name|convState
operator|->
name|invalidChars
operator|=
name|invalidCount
expr_stmt|;
name|convState
operator|->
name|remainingChars
operator|=
name|remainingCount
expr_stmt|;
block|}
else|else
block|{
comment|// reset state
name|iconv
argument_list|(
name|state
operator|->
name|cd
argument_list|,
literal|0
argument_list|,
operator|&
name|inBytesLeft
argument_list|,
literal|0
argument_list|,
operator|&
name|outBytesLeft
argument_list|)
expr_stmt|;
block|}
operator|delete
name|temporaryState
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QThreadStorage<QIconvCodec::IconvState *>
argument_list|,
argument|fromUnicodeState
argument_list|)
end_macro
begin_function
DECL|function|setByteOrder
specifier|static
name|bool
name|setByteOrder
parameter_list|(
name|iconv_t
name|cd
parameter_list|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_BOM
argument_list|)
comment|// give iconv() a BOM
name|char
name|buf
index|[
literal|4
index|]
decl_stmt|;
name|ushort
name|bom
index|[]
init|=
block|{
name|QChar
operator|::
name|ByteOrderMark
block|}
decl_stmt|;
name|char
modifier|*
name|outBytes
init|=
name|buf
decl_stmt|;
name|char
modifier|*
name|inBytes
init|=
cast|reinterpret_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|bom
argument_list|)
decl_stmt|;
name|size_t
name|outBytesLeft
init|=
sizeof|sizeof
name|buf
decl_stmt|;
name|size_t
name|inBytesLeft
init|=
sizeof|sizeof
name|bom
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|GNU_LIBICONV
argument_list|)
specifier|const
name|char
modifier|*
modifier|*
name|inBytesPtr
init|=
cast|const_cast
argument_list|<
specifier|const
name|char
operator|*
operator|*
argument_list|>
argument_list|(
operator|&
name|inBytes
argument_list|)
decl_stmt|;
else|#
directive|else
name|char
modifier|*
modifier|*
name|inBytesPtr
init|=
operator|&
name|inBytes
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|iconv
argument_list|(
name|cd
argument_list|,
name|inBytesPtr
argument_list|,
operator|&
name|inBytesLeft
argument_list|,
operator|&
name|outBytes
argument_list|,
operator|&
name|outBytesLeft
argument_list|)
operator|==
operator|(
name|size_t
operator|)
operator|-
literal|1
condition|)
block|{
return|return
literal|false
return|;
block|}
endif|#
directive|endif
comment|// NO_BOM
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|convertFromUnicode
name|QByteArray
name|QIconvCodec
operator|::
name|convertFromUnicode
parameter_list|(
specifier|const
name|QChar
modifier|*
name|uc
parameter_list|,
name|int
name|len
parameter_list|,
name|ConverterState
modifier|*
name|convState
parameter_list|)
specifier|const
block|{
name|char
modifier|*
name|inBytes
decl_stmt|;
name|char
modifier|*
name|outBytes
decl_stmt|;
name|size_t
name|inBytesLeft
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|GNU_LIBICONV
argument_list|)
specifier|const
name|char
modifier|*
modifier|*
name|inBytesPtr
init|=
cast|const_cast
argument_list|<
specifier|const
name|char
operator|*
operator|*
argument_list|>
argument_list|(
operator|&
name|inBytes
argument_list|)
decl_stmt|;
else|#
directive|else
name|char
modifier|*
modifier|*
name|inBytesPtr
init|=
operator|&
name|inBytes
decl_stmt|;
endif|#
directive|endif
name|IconvState
modifier|*
name|temporaryState
init|=
literal|0
decl_stmt|;
name|QThreadStorage
argument_list|<
name|QIconvCodec
operator|::
name|IconvState
operator|*
argument_list|>
modifier|*
name|ts
init|=
name|fromUnicodeState
argument_list|()
decl_stmt|;
name|IconvState
modifier|*
modifier|&
name|state
init|=
operator|(
name|qt_locale_initialized
operator|&&
name|ts
operator|)
condition|?
name|ts
operator|->
name|localData
argument_list|()
else|:
name|temporaryState
decl_stmt|;
if|if
condition|(
operator|!
name|state
condition|)
block|{
name|iconv_t
name|cd
init|=
name|QIconvCodec
operator|::
name|createIconv_t
argument_list|(
literal|0
argument_list|,
name|UTF16
argument_list|)
decl_stmt|;
if|if
condition|(
name|cd
operator|!=
cast|reinterpret_cast
argument_list|<
name|iconv_t
argument_list|>
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|setByteOrder
argument_list|(
name|cd
argument_list|)
condition|)
block|{
name|perror
argument_list|(
literal|"QIconvCodec::convertFromUnicode: using Latin-1 for conversion, iconv failed for BOM"
argument_list|)
expr_stmt|;
name|iconv_close
argument_list|(
name|cd
argument_list|)
expr_stmt|;
name|cd
operator|=
cast|reinterpret_cast
argument_list|<
name|iconv_t
argument_list|>
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|(
name|uc
argument_list|,
name|len
argument_list|)
operator|.
name|toLatin1
argument_list|()
return|;
block|}
block|}
name|state
operator|=
operator|new
name|IconvState
argument_list|(
name|cd
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|state
operator|->
name|cd
operator|==
cast|reinterpret_cast
argument_list|<
name|iconv_t
argument_list|>
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
block|{
specifier|static
name|int
name|reported
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|reported
operator|++
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"QIconvCodec::convertFromUnicode: using Latin-1 for conversion, iconv_open failed\n"
argument_list|)
expr_stmt|;
block|}
operator|delete
name|temporaryState
expr_stmt|;
return|return
name|QString
argument_list|(
name|uc
argument_list|,
name|len
argument_list|)
operator|.
name|toLatin1
argument_list|()
return|;
block|}
name|size_t
name|outBytesLeft
init|=
name|len
decl_stmt|;
name|QByteArray
name|ba
argument_list|(
name|outBytesLeft
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
name|outBytes
operator|=
name|ba
operator|.
name|data
argument_list|()
expr_stmt|;
comment|// now feed iconv() the real data
name|inBytes
operator|=
cast|const_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|uc
argument_list|)
argument_list|)
expr_stmt|;
name|inBytesLeft
operator|=
name|len
operator|*
sizeof|sizeof
argument_list|(
name|QChar
argument_list|)
expr_stmt|;
name|QByteArray
name|in
decl_stmt|;
if|if
condition|(
name|convState
operator|&&
name|convState
operator|->
name|remainingChars
condition|)
block|{
comment|// we have one surrogate char to be prepended
name|in
operator|.
name|resize
argument_list|(
sizeof|sizeof
argument_list|(
name|QChar
argument_list|)
operator|+
name|len
argument_list|)
expr_stmt|;
name|inBytes
operator|=
name|in
operator|.
name|data
argument_list|()
expr_stmt|;
name|QChar
name|remaining
init|=
name|convState
operator|->
name|state_data
index|[
literal|0
index|]
decl_stmt|;
name|memcpy
argument_list|(
name|in
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|remaining
argument_list|,
sizeof|sizeof
argument_list|(
name|QChar
argument_list|)
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|in
operator|.
name|data
argument_list|()
operator|+
sizeof|sizeof
argument_list|(
name|QChar
argument_list|)
argument_list|,
name|uc
argument_list|,
name|inBytesLeft
argument_list|)
expr_stmt|;
name|inBytesLeft
operator|+=
sizeof|sizeof
argument_list|(
name|QChar
argument_list|)
expr_stmt|;
name|convState
operator|->
name|remainingChars
operator|=
literal|0
expr_stmt|;
block|}
name|int
name|invalidCount
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|inBytesLeft
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|iconv
argument_list|(
name|state
operator|->
name|cd
argument_list|,
name|inBytesPtr
argument_list|,
operator|&
name|inBytesLeft
argument_list|,
operator|&
name|outBytes
argument_list|,
operator|&
name|outBytesLeft
argument_list|)
operator|==
operator|(
name|size_t
operator|)
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|errno
operator|==
name|EINVAL
operator|&&
name|convState
condition|)
block|{
comment|// buffer ends in a surrogate
name|Q_ASSERT
argument_list|(
name|inBytesLeft
operator|==
literal|2
argument_list|)
expr_stmt|;
name|convState
operator|->
name|remainingChars
operator|=
literal|1
expr_stmt|;
name|convState
operator|->
name|state_data
index|[
literal|0
index|]
operator|=
name|uc
index|[
name|len
operator|-
literal|1
index|]
operator|.
name|unicode
argument_list|()
expr_stmt|;
break|break;
block|}
switch|switch
condition|(
name|errno
condition|)
block|{
case|case
name|EILSEQ
case|:
operator|++
name|invalidCount
expr_stmt|;
comment|// fall through
case|case
name|EINVAL
case|:
block|{
name|inBytes
operator|+=
sizeof|sizeof
argument_list|(
name|QChar
argument_list|)
expr_stmt|;
name|inBytesLeft
operator|-=
sizeof|sizeof
argument_list|(
name|QChar
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|E2BIG
case|:
block|{
name|int
name|offset
init|=
name|ba
operator|.
name|size
argument_list|()
operator|-
name|outBytesLeft
decl_stmt|;
name|ba
operator|.
name|resize
argument_list|(
name|ba
operator|.
name|size
argument_list|()
operator|*
literal|2
argument_list|)
expr_stmt|;
name|outBytes
operator|=
name|ba
operator|.
name|data
argument_list|()
operator|+
name|offset
expr_stmt|;
name|outBytesLeft
operator|=
name|ba
operator|.
name|size
argument_list|()
operator|-
name|offset
expr_stmt|;
break|break;
block|}
default|default:
block|{
comment|// note, cannot use qWarning() since we are implementing the codecForLocale :)
name|perror
argument_list|(
literal|"QIconvCodec::convertFromUnicode: using Latin-1 for conversion, iconv failed"
argument_list|)
expr_stmt|;
comment|// reset to initial state
name|iconv
argument_list|(
name|state
operator|->
name|cd
argument_list|,
literal|0
argument_list|,
operator|&
name|inBytesLeft
argument_list|,
literal|0
argument_list|,
operator|&
name|outBytesLeft
argument_list|)
expr_stmt|;
operator|delete
name|temporaryState
expr_stmt|;
return|return
name|QString
argument_list|(
name|uc
argument_list|,
name|len
argument_list|)
operator|.
name|toLatin1
argument_list|()
return|;
block|}
block|}
block|}
block|}
comment|// reset to initial state
name|iconv
argument_list|(
name|state
operator|->
name|cd
argument_list|,
literal|0
argument_list|,
operator|&
name|inBytesLeft
argument_list|,
literal|0
argument_list|,
operator|&
name|outBytesLeft
argument_list|)
expr_stmt|;
name|setByteOrder
argument_list|(
name|state
operator|->
name|cd
argument_list|)
expr_stmt|;
name|ba
operator|.
name|resize
argument_list|(
name|ba
operator|.
name|size
argument_list|()
operator|-
name|outBytesLeft
argument_list|)
expr_stmt|;
if|if
condition|(
name|convState
condition|)
name|convState
operator|->
name|invalidChars
operator|=
name|invalidCount
expr_stmt|;
operator|delete
name|temporaryState
expr_stmt|;
return|return
name|ba
return|;
block|}
end_function
begin_function
DECL|function|name
name|QByteArray
name|QIconvCodec
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
literal|"System"
return|;
block|}
end_function
begin_function
DECL|function|mibEnum
name|int
name|QIconvCodec
operator|::
name|mibEnum
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|createIconv_t
name|iconv_t
name|QIconvCodec
operator|::
name|createIconv_t
parameter_list|(
specifier|const
name|char
modifier|*
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|(
name|to
operator|==
literal|0
operator|&&
name|from
operator|!=
literal|0
operator|)
operator|||
operator|(
name|to
operator|!=
literal|0
operator|&&
name|from
operator|==
literal|0
operator|)
argument_list|)
expr_stmt|;
name|iconv_t
name|cd
init|=
operator|(
name|iconv_t
operator|)
operator|-
literal|1
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
operator|||
name|defined
argument_list|(
name|GNU_LIBICONV
argument_list|)
comment|// both GLIBC and libgnuiconv will use the locale's encoding if from or to is an empty string
specifier|static
specifier|const
name|char
name|empty_codeset
index|[]
init|=
literal|""
decl_stmt|;
specifier|const
name|char
modifier|*
name|codeset
init|=
name|empty_codeset
decl_stmt|;
name|cd
operator|=
name|iconv_open
argument_list|(
name|to
condition|?
name|to
else|:
name|codeset
argument_list|,
name|from
condition|?
name|from
else|:
name|codeset
argument_list|)
expr_stmt|;
else|#
directive|else
name|char
modifier|*
name|codeset
init|=
literal|0
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|_XOPEN_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_QNX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_OSF
argument_list|)
if|if
condition|(
name|cd
operator|==
operator|(
name|iconv_t
operator|)
operator|-
literal|1
condition|)
block|{
name|codeset
operator|=
name|nl_langinfo
argument_list|(
name|CODESET
argument_list|)
expr_stmt|;
if|if
condition|(
name|codeset
condition|)
name|cd
operator|=
name|iconv_open
argument_list|(
name|to
condition|?
name|to
else|:
name|codeset
argument_list|,
name|from
condition|?
name|from
else|:
name|codeset
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|cd
operator|==
operator|(
name|iconv_t
operator|)
operator|-
literal|1
condition|)
block|{
comment|// Very poorly defined and followed standards causes lots of
comment|// code to try to get all the cases... This logic is
comment|// duplicated in QTextCodec, so if you change it here, change
comment|// it there too.
comment|// Try to determine locale codeset from locale name assigned to
comment|// LC_CTYPE category.
comment|// First part is getting that locale name.  First try setlocale() which
comment|// definitely knows it, but since we cannot fully trust it, get ready
comment|// to fall back to environment variables.
name|char
modifier|*
name|ctype
init|=
name|qstrdup
argument_list|(
name|setlocale
argument_list|(
name|LC_CTYPE
argument_list|,
literal|0
argument_list|)
argument_list|)
decl_stmt|;
comment|// Get the first nonempty value from $LC_ALL, $LC_CTYPE, and $LANG
comment|// environment variables.
name|char
modifier|*
name|lang
init|=
name|qstrdup
argument_list|(
name|qgetenv
argument_list|(
literal|"LC_ALL"
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|lang
operator|||
name|lang
index|[
literal|0
index|]
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|lang
argument_list|,
literal|"C"
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|lang
condition|)
operator|delete
index|[]
name|lang
expr_stmt|;
name|lang
operator|=
name|qstrdup
argument_list|(
name|qgetenv
argument_list|(
literal|"LC_CTYPE"
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|lang
operator|||
name|lang
index|[
literal|0
index|]
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|lang
argument_list|,
literal|"C"
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|lang
condition|)
operator|delete
index|[]
name|lang
expr_stmt|;
name|lang
operator|=
name|qstrdup
argument_list|(
name|qgetenv
argument_list|(
literal|"LANG"
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Now try these in order:
comment|// 1. CODESET from ctype if it contains a .CODESET part (e.g. en_US.ISO8859-15)
comment|// 2. CODESET from lang if it contains a .CODESET part
comment|// 3. ctype (maybe the locale is named "ISO-8859-1" or something)
comment|// 4. locale (ditto)
comment|// 5. check for "@euro"
comment|// 1. CODESET from ctype if it contains a .CODESET part (e.g. en_US.ISO8859-15)
name|codeset
operator|=
name|ctype
condition|?
name|strchr
argument_list|(
name|ctype
argument_list|,
literal|'.'
argument_list|)
else|:
literal|0
expr_stmt|;
if|if
condition|(
name|codeset
operator|&&
operator|*
name|codeset
operator|==
literal|'.'
condition|)
block|{
operator|++
name|codeset
expr_stmt|;
name|cd
operator|=
name|iconv_open
argument_list|(
name|to
condition|?
name|to
else|:
name|codeset
argument_list|,
name|from
condition|?
name|from
else|:
name|codeset
argument_list|)
expr_stmt|;
block|}
comment|// 2. CODESET from lang if it contains a .CODESET part
name|codeset
operator|=
name|lang
condition|?
name|strchr
argument_list|(
name|lang
argument_list|,
literal|'.'
argument_list|)
else|:
literal|0
expr_stmt|;
if|if
condition|(
name|cd
operator|==
operator|(
name|iconv_t
operator|)
operator|-
literal|1
operator|&&
name|codeset
operator|&&
operator|*
name|codeset
operator|==
literal|'.'
condition|)
block|{
operator|++
name|codeset
expr_stmt|;
name|cd
operator|=
name|iconv_open
argument_list|(
name|to
condition|?
name|to
else|:
name|codeset
argument_list|,
name|from
condition|?
name|from
else|:
name|codeset
argument_list|)
expr_stmt|;
block|}
comment|// 3. ctype (maybe the locale is named "ISO-8859-1" or something)
if|if
condition|(
name|cd
operator|==
operator|(
name|iconv_t
operator|)
operator|-
literal|1
operator|&&
name|ctype
operator|&&
operator|*
name|ctype
operator|!=
literal|0
operator|&&
name|strcmp
argument_list|(
name|ctype
argument_list|,
literal|"C"
argument_list|)
operator|!=
literal|0
condition|)
name|cd
operator|=
name|iconv_open
argument_list|(
name|to
condition|?
name|to
else|:
name|ctype
argument_list|,
name|from
condition|?
name|from
else|:
name|ctype
argument_list|)
expr_stmt|;
comment|// 4. locale (ditto)
if|if
condition|(
name|cd
operator|==
operator|(
name|iconv_t
operator|)
operator|-
literal|1
operator|&&
name|lang
operator|&&
operator|*
name|lang
operator|!=
literal|0
condition|)
name|cd
operator|=
name|iconv_open
argument_list|(
name|to
condition|?
name|to
else|:
name|lang
argument_list|,
name|from
condition|?
name|from
else|:
name|lang
argument_list|)
expr_stmt|;
comment|// 5. "@euro"
if|if
condition|(
operator|(
name|cd
operator|==
operator|(
name|iconv_t
operator|)
operator|-
literal|1
operator|&&
name|ctype
operator|&&
name|strstr
argument_list|(
name|ctype
argument_list|,
literal|"@euro"
argument_list|)
operator|)
operator|||
operator|(
name|lang
operator|&&
name|strstr
argument_list|(
name|lang
argument_list|,
literal|"@euro"
argument_list|)
operator|)
condition|)
name|cd
operator|=
name|iconv_open
argument_list|(
name|to
condition|?
name|to
else|:
literal|"ISO8859-15"
argument_list|,
name|from
condition|?
name|from
else|:
literal|"ISO8859-15"
argument_list|)
expr_stmt|;
operator|delete
index|[]
name|ctype
expr_stmt|;
operator|delete
index|[]
name|lang
expr_stmt|;
block|}
return|return
name|cd
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
