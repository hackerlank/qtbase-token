begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlatincodec_p.h"
end_include
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
end_ifndef
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
DECL|function|~QLatin1Codec
name|QLatin1Codec
operator|::
name|~
name|QLatin1Codec
operator|(
operator|)
block|{ }
DECL|function|convertToUnicode
name|QString
name|QLatin1Codec
operator|::
name|convertToUnicode
operator|(
specifier|const
name|char
operator|*
name|chars
operator|,
name|int
name|len
operator|,
name|ConverterState
operator|*
operator|)
specifier|const
block|{
if|if
condition|(
name|chars
operator|==
literal|0
condition|)
return|return
name|QString
argument_list|()
return|;
end_expr_stmt
begin_return
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
end_return
begin_macro
unit|}   QByteArray
DECL|function|convertFromUnicode
name|QLatin1Codec
end_macro
begin_expr_stmt
DECL|function|convertFromUnicode
operator|::
name|convertFromUnicode
operator|(
specifier|const
name|QChar
operator|*
name|ch
operator|,
name|int
name|len
operator|,
name|ConverterState
operator|*
name|state
operator|)
specifier|const
block|{
specifier|const
name|char
name|replacement
operator|=
operator|(
name|state
operator|&&
name|state
operator|->
name|flags
operator|&
name|ConvertInvalidToNull
operator|)
operator|?
literal|0
operator|:
literal|'?'
block|;
name|QByteArray
name|r
argument_list|(
name|len
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
block|;
name|char
operator|*
name|d
operator|=
name|r
operator|.
name|data
argument_list|()
block|;
name|int
name|invalid
operator|=
literal|0
block|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|ch
index|[
name|i
index|]
operator|>
literal|0xff
condition|)
block|{
name|d
index|[
name|i
index|]
operator|=
name|replacement
expr_stmt|;
operator|++
name|invalid
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
name|d
index|[
name|i
index|]
operator|=
operator|(
name|char
operator|)
name|ch
index|[
name|i
index|]
operator|.
name|cell
argument_list|()
expr_stmt|;
block|}
end_else
begin_expr_stmt
unit|}     if
operator|(
name|state
operator|)
block|{
name|state
operator|->
name|invalidChars
operator|+=
name|invalid
block|;     }
end_expr_stmt
begin_return
return|return
name|r
return|;
end_return
begin_macro
unit|}  QByteArray
DECL|function|name
name|QLatin1Codec
end_macro
begin_expr_stmt
DECL|function|name
operator|::
name|name
operator|(
operator|)
specifier|const
block|{
return|return
literal|"ISO-8859-1"
return|;
block|}
end_expr_stmt
begin_function
DECL|function|aliases
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|QLatin1Codec
operator|::
name|aliases
parameter_list|()
specifier|const
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|list
decl_stmt|;
name|list
operator|<<
literal|"latin1"
operator|<<
literal|"CP819"
operator|<<
literal|"IBM819"
operator|<<
literal|"iso-ir-100"
operator|<<
literal|"csISOLatin1"
expr_stmt|;
return|return
name|list
return|;
block|}
end_function
begin_function
DECL|function|mibEnum
name|int
name|QLatin1Codec
operator|::
name|mibEnum
parameter_list|()
specifier|const
block|{
return|return
literal|4
return|;
block|}
end_function
begin_destructor
DECL|function|~QLatin15Codec
name|QLatin15Codec
operator|::
name|~
name|QLatin15Codec
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|convertToUnicode
name|QString
name|QLatin15Codec
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
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|chars
operator|==
literal|0
condition|)
return|return
name|QString
argument_list|()
return|;
name|QString
name|str
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|chars
argument_list|,
name|len
argument_list|)
decl_stmt|;
name|QChar
modifier|*
name|uc
init|=
name|str
operator|.
name|data
argument_list|()
decl_stmt|;
while|while
condition|(
name|len
operator|--
condition|)
block|{
switch|switch
condition|(
name|uc
operator|->
name|unicode
argument_list|()
condition|)
block|{
case|case
literal|0xa4
case|:
operator|*
name|uc
operator|=
literal|0x20ac
expr_stmt|;
break|break;
case|case
literal|0xa6
case|:
operator|*
name|uc
operator|=
literal|0x0160
expr_stmt|;
break|break;
case|case
literal|0xa8
case|:
operator|*
name|uc
operator|=
literal|0x0161
expr_stmt|;
break|break;
case|case
literal|0xb4
case|:
operator|*
name|uc
operator|=
literal|0x017d
expr_stmt|;
break|break;
case|case
literal|0xb8
case|:
operator|*
name|uc
operator|=
literal|0x017e
expr_stmt|;
break|break;
case|case
literal|0xbc
case|:
operator|*
name|uc
operator|=
literal|0x0152
expr_stmt|;
break|break;
case|case
literal|0xbd
case|:
operator|*
name|uc
operator|=
literal|0x0153
expr_stmt|;
break|break;
case|case
literal|0xbe
case|:
operator|*
name|uc
operator|=
literal|0x0178
expr_stmt|;
break|break;
default|default:
break|break;
block|}
name|uc
operator|++
expr_stmt|;
block|}
return|return
name|str
return|;
block|}
end_function
begin_function
DECL|function|convertFromUnicode
name|QByteArray
name|QLatin15Codec
operator|::
name|convertFromUnicode
parameter_list|(
specifier|const
name|QChar
modifier|*
name|in
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
name|replacement
init|=
operator|(
name|state
operator|&&
name|state
operator|->
name|flags
operator|&
name|ConvertInvalidToNull
operator|)
condition|?
literal|0
else|:
literal|'?'
decl_stmt|;
name|QByteArray
name|r
argument_list|(
name|length
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
name|char
modifier|*
name|d
init|=
name|r
operator|.
name|data
argument_list|()
decl_stmt|;
name|int
name|invalid
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|length
condition|;
operator|++
name|i
control|)
block|{
name|uchar
name|c
decl_stmt|;
name|ushort
name|uc
init|=
name|in
index|[
name|i
index|]
operator|.
name|unicode
argument_list|()
decl_stmt|;
if|if
condition|(
name|uc
operator|<
literal|0x0100
condition|)
block|{
if|if
condition|(
name|uc
operator|>
literal|0xa3
condition|)
block|{
switch|switch
condition|(
name|uc
condition|)
block|{
case|case
literal|0xa4
case|:
case|case
literal|0xa6
case|:
case|case
literal|0xa8
case|:
case|case
literal|0xb4
case|:
case|case
literal|0xb8
case|:
case|case
literal|0xbc
case|:
case|case
literal|0xbd
case|:
case|case
literal|0xbe
case|:
name|c
operator|=
name|replacement
expr_stmt|;
operator|++
name|invalid
expr_stmt|;
break|break;
default|default:
name|c
operator|=
operator|(
name|unsigned
name|char
operator|)
name|uc
expr_stmt|;
break|break;
block|}
block|}
else|else
block|{
name|c
operator|=
operator|(
name|unsigned
name|char
operator|)
name|uc
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|uc
operator|==
literal|0x20ac
condition|)
name|c
operator|=
literal|0xa4
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|uc
operator|&
literal|0xff00
operator|)
operator|==
literal|0x0100
condition|)
block|{
switch|switch
condition|(
name|uc
condition|)
block|{
case|case
literal|0x0160
case|:
name|c
operator|=
literal|0xa6
expr_stmt|;
break|break;
case|case
literal|0x0161
case|:
name|c
operator|=
literal|0xa8
expr_stmt|;
break|break;
case|case
literal|0x017d
case|:
name|c
operator|=
literal|0xb4
expr_stmt|;
break|break;
case|case
literal|0x017e
case|:
name|c
operator|=
literal|0xb8
expr_stmt|;
break|break;
case|case
literal|0x0152
case|:
name|c
operator|=
literal|0xbc
expr_stmt|;
break|break;
case|case
literal|0x0153
case|:
name|c
operator|=
literal|0xbd
expr_stmt|;
break|break;
case|case
literal|0x0178
case|:
name|c
operator|=
literal|0xbe
expr_stmt|;
break|break;
default|default:
name|c
operator|=
name|replacement
expr_stmt|;
operator|++
name|invalid
expr_stmt|;
block|}
block|}
else|else
block|{
name|c
operator|=
name|replacement
expr_stmt|;
operator|++
name|invalid
expr_stmt|;
block|}
block|}
name|d
index|[
name|i
index|]
operator|=
operator|(
name|char
operator|)
name|c
expr_stmt|;
block|}
if|if
condition|(
name|state
condition|)
block|{
name|state
operator|->
name|remainingChars
operator|=
literal|0
expr_stmt|;
name|state
operator|->
name|invalidChars
operator|+=
name|invalid
expr_stmt|;
block|}
return|return
name|r
return|;
block|}
end_function
begin_function
DECL|function|name
name|QByteArray
name|QLatin15Codec
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
literal|"ISO-8859-15"
return|;
block|}
end_function
begin_function
DECL|function|aliases
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|QLatin15Codec
operator|::
name|aliases
parameter_list|()
specifier|const
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|list
decl_stmt|;
name|list
operator|<<
literal|"latin9"
expr_stmt|;
return|return
name|list
return|;
block|}
end_function
begin_function
DECL|function|mibEnum
name|int
name|QLatin15Codec
operator|::
name|mibEnum
parameter_list|()
specifier|const
block|{
return|return
literal|111
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TEXTCODEC
end_comment
end_unit
