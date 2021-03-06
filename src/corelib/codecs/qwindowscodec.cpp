begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowscodec_p.h"
end_include
begin_include
include|#
directive|include
file|<qvarlengtharray.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QWindowsLocalCodec
name|QWindowsLocalCodec
operator|::
name|QWindowsLocalCodec
parameter_list|()
block|{ }
end_function
begin_destructor
DECL|function|~QWindowsLocalCodec
name|QWindowsLocalCodec
operator|::
name|~
name|QWindowsLocalCodec
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|convertToUnicode
name|QString
name|QWindowsLocalCodec
operator|::
name|convertToUnicode
parameter_list|(
specifier|const
name|char
modifier|*
name|chars
parameter_list|,
name|int
name|length
parameter_list|,
name|ConverterState
modifier|*
name|state
parameter_list|)
specifier|const
block|{
specifier|const
name|char
modifier|*
name|mb
init|=
name|chars
decl_stmt|;
name|int
name|mblen
init|=
name|length
decl_stmt|;
if|if
condition|(
operator|!
name|mb
operator|||
operator|!
name|mblen
condition|)
return|return
name|QString
argument_list|()
return|;
name|QVarLengthArray
argument_list|<
name|wchar_t
argument_list|,
literal|4096
argument_list|>
name|wc
argument_list|(
literal|4096
argument_list|)
decl_stmt|;
name|int
name|len
decl_stmt|;
name|QString
name|sp
decl_stmt|;
name|bool
name|prepend
init|=
literal|false
decl_stmt|;
name|char
name|state_data
init|=
literal|0
decl_stmt|;
name|int
name|remainingChars
init|=
literal|0
decl_stmt|;
comment|//save the current state information
if|if
condition|(
name|state
condition|)
block|{
name|state_data
operator|=
operator|(
name|char
operator|)
name|state
operator|->
name|state_data
index|[
literal|0
index|]
expr_stmt|;
name|remainingChars
operator|=
name|state
operator|->
name|remainingChars
expr_stmt|;
block|}
comment|//convert the pending charcter (if available)
if|if
condition|(
name|state
operator|&&
name|remainingChars
condition|)
block|{
name|char
name|prev
index|[
literal|3
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|prev
index|[
literal|0
index|]
operator|=
name|state_data
expr_stmt|;
name|prev
index|[
literal|1
index|]
operator|=
name|mb
index|[
literal|0
index|]
expr_stmt|;
name|remainingChars
operator|=
literal|0
expr_stmt|;
name|len
operator|=
name|MultiByteToWideChar
argument_list|(
name|CP_ACP
argument_list|,
name|MB_PRECOMPOSED
argument_list|,
name|prev
argument_list|,
literal|2
argument_list|,
name|wc
operator|.
name|data
argument_list|()
argument_list|,
name|wc
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|len
condition|)
block|{
name|prepend
operator|=
literal|true
expr_stmt|;
name|sp
operator|.
name|append
argument_list|(
name|QChar
argument_list|(
name|wc
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|mb
operator|++
expr_stmt|;
name|mblen
operator|--
expr_stmt|;
name|wc
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
block|}
block|}
while|while
condition|(
operator|!
operator|(
name|len
operator|=
name|MultiByteToWideChar
argument_list|(
name|CP_ACP
argument_list|,
name|MB_PRECOMPOSED
operator||
name|MB_ERR_INVALID_CHARS
argument_list|,
name|mb
argument_list|,
name|mblen
argument_list|,
name|wc
operator|.
name|data
argument_list|()
argument_list|,
name|wc
operator|.
name|length
argument_list|()
argument_list|)
operator|)
condition|)
block|{
name|int
name|r
init|=
name|GetLastError
argument_list|()
decl_stmt|;
if|if
condition|(
name|r
operator|==
name|ERROR_INSUFFICIENT_BUFFER
condition|)
block|{
specifier|const
name|int
name|wclen
init|=
name|MultiByteToWideChar
argument_list|(
name|CP_ACP
argument_list|,
name|MB_PRECOMPOSED
argument_list|,
name|mb
argument_list|,
name|mblen
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|wc
operator|.
name|resize
argument_list|(
name|wclen
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|r
operator|==
name|ERROR_NO_UNICODE_TRANSLATION
condition|)
block|{
comment|//find the last non NULL character
while|while
condition|(
name|mblen
operator|>
literal|1
operator|&&
operator|!
operator|(
name|mb
index|[
name|mblen
operator|-
literal|1
index|]
operator|)
condition|)
name|mblen
operator|--
expr_stmt|;
comment|//check whether,  we hit an invalid character in the middle
if|if
condition|(
operator|(
name|mblen
operator|<=
literal|1
operator|)
operator|||
operator|(
name|remainingChars
operator|&&
name|state_data
operator|)
condition|)
return|return
name|convertToUnicodeCharByChar
argument_list|(
name|chars
argument_list|,
name|length
argument_list|,
name|state
argument_list|)
return|;
comment|//Remove the last character and try again...
name|state_data
operator|=
name|mb
index|[
name|mblen
operator|-
literal|1
index|]
expr_stmt|;
name|remainingChars
operator|=
literal|1
expr_stmt|;
name|mblen
operator|--
expr_stmt|;
block|}
else|else
block|{
comment|// Fail.
name|qWarning
argument_list|(
literal|"MultiByteToWideChar: Cannot convert multibyte text"
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|len
operator|<=
literal|0
condition|)
return|return
name|QString
argument_list|()
return|;
if|if
condition|(
name|wc
index|[
name|len
operator|-
literal|1
index|]
operator|==
literal|0
condition|)
comment|// len - 1: we don't want terminator
operator|--
name|len
expr_stmt|;
comment|//save the new state information
if|if
condition|(
name|state
condition|)
block|{
name|state
operator|->
name|state_data
index|[
literal|0
index|]
operator|=
operator|(
name|char
operator|)
name|state_data
expr_stmt|;
name|state
operator|->
name|remainingChars
operator|=
name|remainingChars
expr_stmt|;
block|}
name|QString
name|s
argument_list|(
operator|(
name|QChar
operator|*
operator|)
name|wc
operator|.
name|data
argument_list|()
argument_list|,
name|len
argument_list|)
decl_stmt|;
if|if
condition|(
name|prepend
condition|)
block|{
return|return
name|sp
operator|+
name|s
return|;
block|}
return|return
name|s
return|;
block|}
end_function
begin_function
DECL|function|convertToUnicodeCharByChar
name|QString
name|QWindowsLocalCodec
operator|::
name|convertToUnicodeCharByChar
parameter_list|(
specifier|const
name|char
modifier|*
name|chars
parameter_list|,
name|int
name|length
parameter_list|,
name|ConverterState
modifier|*
name|state
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|chars
operator|||
operator|!
name|length
condition|)
return|return
name|QString
argument_list|()
return|;
name|int
name|copyLocation
init|=
literal|0
decl_stmt|;
name|int
name|extra
init|=
literal|2
decl_stmt|;
if|if
condition|(
name|state
operator|&&
name|state
operator|->
name|remainingChars
condition|)
block|{
name|copyLocation
operator|=
name|state
operator|->
name|remainingChars
expr_stmt|;
name|extra
operator|+=
name|copyLocation
expr_stmt|;
block|}
name|int
name|newLength
init|=
name|length
operator|+
name|extra
decl_stmt|;
name|char
modifier|*
name|mbcs
init|=
operator|new
name|char
index|[
name|newLength
index|]
decl_stmt|;
comment|//ensure that we have a NULL terminated string
name|mbcs
index|[
name|newLength
operator|-
literal|1
index|]
operator|=
literal|0
expr_stmt|;
name|mbcs
index|[
name|newLength
operator|-
literal|2
index|]
operator|=
literal|0
expr_stmt|;
name|memcpy
argument_list|(
operator|&
operator|(
name|mbcs
index|[
name|copyLocation
index|]
operator|)
argument_list|,
name|chars
argument_list|,
name|length
argument_list|)
expr_stmt|;
if|if
condition|(
name|copyLocation
condition|)
block|{
comment|//copy the last character from the state
name|mbcs
index|[
literal|0
index|]
operator|=
operator|(
name|char
operator|)
name|state
operator|->
name|state_data
index|[
literal|0
index|]
expr_stmt|;
name|state
operator|->
name|remainingChars
operator|=
literal|0
expr_stmt|;
block|}
specifier|const
name|char
modifier|*
name|mb
init|=
name|mbcs
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINRT
argument_list|)
specifier|const
name|char
modifier|*
name|next
init|=
literal|0
decl_stmt|;
name|QString
name|s
decl_stmt|;
while|while
condition|(
operator|(
name|next
operator|=
name|CharNextExA
argument_list|(
name|CP_ACP
argument_list|,
name|mb
argument_list|,
literal|0
argument_list|)
operator|)
operator|!=
name|mb
condition|)
block|{
name|wchar_t
name|wc
index|[
literal|2
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|int
name|charlength
init|=
name|next
operator|-
name|mb
decl_stmt|;
name|int
name|len
init|=
name|MultiByteToWideChar
argument_list|(
name|CP_ACP
argument_list|,
name|MB_PRECOMPOSED
operator||
name|MB_ERR_INVALID_CHARS
argument_list|,
name|mb
argument_list|,
name|charlength
argument_list|,
name|wc
argument_list|,
literal|2
argument_list|)
decl_stmt|;
if|if
condition|(
name|len
operator|>
literal|0
condition|)
block|{
name|s
operator|.
name|append
argument_list|(
name|QChar
argument_list|(
name|wc
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|int
name|r
init|=
name|GetLastError
argument_list|()
decl_stmt|;
comment|//check if the character being dropped is the last character
if|if
condition|(
name|r
operator|==
name|ERROR_NO_UNICODE_TRANSLATION
operator|&&
name|mb
operator|==
operator|(
name|mbcs
operator|+
name|newLength
operator|-
literal|3
operator|)
operator|&&
name|state
condition|)
block|{
name|state
operator|->
name|remainingChars
operator|=
literal|1
expr_stmt|;
name|state
operator|->
name|state_data
index|[
literal|0
index|]
operator|=
operator|(
name|char
operator|)
operator|*
name|mb
expr_stmt|;
block|}
block|}
name|mb
operator|=
name|next
expr_stmt|;
block|}
else|#
directive|else
name|QString
name|s
decl_stmt|;
name|size_t
name|size
init|=
name|mbstowcs
argument_list|(
name|NULL
argument_list|,
name|mb
argument_list|,
name|length
argument_list|)
decl_stmt|;
if|if
condition|(
name|size
operator|<
literal|0
condition|)
block|{
name|Q_ASSERT
argument_list|(
literal|"Error in CE TextCodec"
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
block|}
name|wchar_t
modifier|*
name|ws
init|=
operator|new
name|wchar_t
index|[
name|size
operator|+
literal|2
index|]
decl_stmt|;
name|ws
index|[
name|size
operator|+
literal|1
index|]
operator|=
literal|0
expr_stmt|;
name|ws
index|[
name|size
index|]
operator|=
literal|0
expr_stmt|;
name|size
operator|=
name|mbstowcs
argument_list|(
name|ws
argument_list|,
name|mb
argument_list|,
name|length
argument_list|)
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
name|i
operator|++
control|)
name|s
operator|.
name|append
argument_list|(
name|QChar
argument_list|(
name|ws
index|[
name|i
index|]
argument_list|)
argument_list|)
expr_stmt|;
operator|delete
index|[]
name|ws
expr_stmt|;
endif|#
directive|endif
operator|delete
index|[]
name|mbcs
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_function
DECL|function|convertFromUnicode
name|QByteArray
name|QWindowsLocalCodec
operator|::
name|convertFromUnicode
parameter_list|(
specifier|const
name|QChar
modifier|*
name|ch
parameter_list|,
name|int
name|uclen
parameter_list|,
name|ConverterState
modifier|*
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|ch
condition|)
return|return
name|QByteArray
argument_list|()
return|;
if|if
condition|(
name|uclen
operator|==
literal|0
condition|)
return|return
name|QByteArray
argument_list|(
literal|""
argument_list|)
return|;
name|BOOL
name|used_def
decl_stmt|;
name|QByteArray
name|mb
argument_list|(
literal|4096
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|int
name|len
decl_stmt|;
while|while
condition|(
operator|!
operator|(
name|len
operator|=
name|WideCharToMultiByte
argument_list|(
name|CP_ACP
argument_list|,
literal|0
argument_list|,
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|ch
argument_list|,
name|uclen
argument_list|,
name|mb
operator|.
name|data
argument_list|()
argument_list|,
name|mb
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
operator|&
name|used_def
argument_list|)
operator|)
condition|)
block|{
name|int
name|r
init|=
name|GetLastError
argument_list|()
decl_stmt|;
if|if
condition|(
name|r
operator|==
name|ERROR_INSUFFICIENT_BUFFER
condition|)
block|{
name|mb
operator|.
name|resize
argument_list|(
literal|1
operator|+
name|WideCharToMultiByte
argument_list|(
name|CP_ACP
argument_list|,
literal|0
argument_list|,
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|ch
argument_list|,
name|uclen
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|used_def
argument_list|)
argument_list|)
expr_stmt|;
comment|// and try again...
block|}
else|else
block|{
comment|// Fail.  Probably can't happen in fact (dwFlags is 0).
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
comment|// Can't use qWarning(), as it'll recurse to handle %ls
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"WideCharToMultiByte: Cannot convert multibyte text (error %d): %ls\n"
argument_list|,
name|r
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|QString
argument_list|(
name|ch
argument_list|,
name|uclen
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
break|break;
block|}
block|}
name|mb
operator|.
name|resize
argument_list|(
name|len
argument_list|)
expr_stmt|;
return|return
name|mb
return|;
block|}
end_function
begin_function
DECL|function|name
name|QByteArray
name|QWindowsLocalCodec
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
name|QWindowsLocalCodec
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
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
