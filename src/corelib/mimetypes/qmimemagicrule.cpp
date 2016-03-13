begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_define
DECL|macro|QT_NO_CAST_FROM_ASCII
define|#
directive|define
name|QT_NO_CAST_FROM_ASCII
end_define
begin_include
include|#
directive|include
file|"qmimemagicrule_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_MIMETYPE
end_ifndef
begin_include
include|#
directive|include
file|"qmimetypeparser_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<qendian.h>
end_include
begin_include
include|#
directive|include
file|<private/qsimd_p.h>
end_include
begin_comment
comment|// for qUnalignedLoad
end_comment
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// in the same order as Type!
DECL|variable|magicRuleTypes_string
specifier|static
specifier|const
name|char
name|magicRuleTypes_string
index|[]
init|=
literal|"invalid\0"
literal|"string\0"
literal|"host16\0"
literal|"host32\0"
literal|"big16\0"
literal|"big32\0"
literal|"little16\0"
literal|"little32\0"
literal|"byte\0"
literal|"\0"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|magicRuleTypes_indices
specifier|static
specifier|const
name|int
name|magicRuleTypes_indices
index|[]
init|=
block|{
literal|0
block|,
literal|8
block|,
literal|15
block|,
literal|22
block|,
literal|29
block|,
literal|35
block|,
literal|41
block|,
literal|50
block|,
literal|59
block|,
literal|65
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|type
name|QMimeMagicRule
operator|::
name|Type
name|QMimeMagicRule
operator|::
name|type
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|theTypeName
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
name|String
init|;
name|i
operator|<=
name|Byte
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|theTypeName
operator|==
name|magicRuleTypes_string
operator|+
name|magicRuleTypes_indices
index|[
name|i
index|]
condition|)
return|return
name|Type
argument_list|(
name|i
argument_list|)
return|;
block|}
return|return
name|Invalid
return|;
block|}
end_function
begin_function
DECL|function|typeName
name|QByteArray
name|QMimeMagicRule
operator|::
name|typeName
parameter_list|(
name|QMimeMagicRule
operator|::
name|Type
name|theType
parameter_list|)
block|{
return|return
name|magicRuleTypes_string
operator|+
name|magicRuleTypes_indices
index|[
name|theType
index|]
return|;
block|}
end_function
begin_function
DECL|function|operator ==
name|bool
name|QMimeMagicRule
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QMimeMagicRule
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
name|m_type
operator|==
name|other
operator|.
name|m_type
operator|&&
name|m_value
operator|==
name|other
operator|.
name|m_value
operator|&&
name|m_startPos
operator|==
name|other
operator|.
name|m_startPos
operator|&&
name|m_endPos
operator|==
name|other
operator|.
name|m_endPos
operator|&&
name|m_mask
operator|==
name|other
operator|.
name|m_mask
operator|&&
name|m_pattern
operator|==
name|other
operator|.
name|m_pattern
operator|&&
name|m_number
operator|==
name|other
operator|.
name|m_number
operator|&&
name|m_numberMask
operator|==
name|other
operator|.
name|m_numberMask
operator|&&
name|m_matchFunction
operator|==
name|other
operator|.
name|m_matchFunction
return|;
block|}
end_function
begin_comment
comment|// Used by both providers
end_comment
begin_function
DECL|function|matchSubstring
name|bool
name|QMimeMagicRule
operator|::
name|matchSubstring
parameter_list|(
specifier|const
name|char
modifier|*
name|dataPtr
parameter_list|,
name|int
name|dataSize
parameter_list|,
name|int
name|rangeStart
parameter_list|,
name|int
name|rangeLength
parameter_list|,
name|int
name|valueLength
parameter_list|,
specifier|const
name|char
modifier|*
name|valueData
parameter_list|,
specifier|const
name|char
modifier|*
name|mask
parameter_list|)
block|{
comment|// Size of searched data.
comment|// Example: value="ABC", rangeLength=3 -> we need 3+3-1=5 bytes (ABCxx,xABCx,xxABC would match)
specifier|const
name|int
name|dataNeeded
init|=
name|qMin
argument_list|(
name|rangeLength
operator|+
name|valueLength
operator|-
literal|1
argument_list|,
name|dataSize
operator|-
name|rangeStart
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|mask
condition|)
block|{
comment|// callgrind says QByteArray::indexOf is much slower, since our strings are typically too
comment|// short for be worth Boyer-Moore matching (1 to 71 bytes, 11 bytes on average).
name|bool
name|found
init|=
literal|false
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|rangeStart
init|;
name|i
operator|<
name|rangeStart
operator|+
name|rangeLength
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
operator|+
name|valueLength
operator|>
name|dataSize
condition|)
break|break;
if|if
condition|(
name|memcmp
argument_list|(
name|valueData
argument_list|,
name|dataPtr
operator|+
name|i
argument_list|,
name|valueLength
argument_list|)
operator|==
literal|0
condition|)
block|{
name|found
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
operator|!
name|found
condition|)
return|return
literal|false
return|;
block|}
else|else
block|{
name|bool
name|found
init|=
literal|false
decl_stmt|;
specifier|const
name|char
modifier|*
name|readDataBase
init|=
name|dataPtr
operator|+
name|rangeStart
decl_stmt|;
comment|// Example (continued from above):
comment|// deviceSize is 4, so dataNeeded was max'ed to 4.
comment|// maxStartPos = 4 - 3 + 1 = 2, and indeed
comment|// we need to check for a match a positions 0 and 1 (ABCx and xABC).
specifier|const
name|int
name|maxStartPos
init|=
name|dataNeeded
operator|-
name|valueLength
operator|+
literal|1
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
name|maxStartPos
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|char
modifier|*
name|d
init|=
name|readDataBase
operator|+
name|i
decl_stmt|;
name|bool
name|valid
init|=
literal|true
decl_stmt|;
for|for
control|(
name|int
name|idx
init|=
literal|0
init|;
name|idx
operator|<
name|valueLength
condition|;
operator|++
name|idx
control|)
block|{
if|if
condition|(
operator|(
operator|(
operator|*
name|d
operator|++
operator|)
operator|&
name|mask
index|[
name|idx
index|]
operator|)
operator|!=
operator|(
name|valueData
index|[
name|idx
index|]
operator|&
name|mask
index|[
name|idx
index|]
operator|)
condition|)
block|{
name|valid
operator|=
literal|false
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|valid
condition|)
name|found
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|found
condition|)
return|return
literal|false
return|;
block|}
comment|//qDebug()<< "Found"<< value<< "in"<< searchedData;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|matchString
name|bool
name|QMimeMagicRule
operator|::
name|matchString
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
specifier|const
block|{
specifier|const
name|int
name|rangeLength
init|=
name|m_endPos
operator|-
name|m_startPos
operator|+
literal|1
decl_stmt|;
return|return
name|QMimeMagicRule
operator|::
name|matchSubstring
argument_list|(
name|data
operator|.
name|constData
argument_list|()
argument_list|,
name|data
operator|.
name|size
argument_list|()
argument_list|,
name|m_startPos
argument_list|,
name|rangeLength
argument_list|,
name|m_pattern
operator|.
name|size
argument_list|()
argument_list|,
name|m_pattern
operator|.
name|constData
argument_list|()
argument_list|,
name|m_mask
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|matchNumber
name|bool
name|QMimeMagicRule
operator|::
name|matchNumber
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
specifier|const
block|{
specifier|const
name|T
name|value
argument_list|(
name|m_number
argument_list|)
decl_stmt|;
specifier|const
name|T
name|mask
argument_list|(
name|m_numberMask
argument_list|)
decl_stmt|;
comment|//qDebug()<< "matchNumber"<< "0x"<< QString::number(m_number, 16)<< "size"<< sizeof(T);
comment|//qDebug()<< "mask"<< QString::number(m_numberMask, 16);
specifier|const
name|char
modifier|*
name|p
init|=
name|data
operator|.
name|constData
argument_list|()
operator|+
name|m_startPos
decl_stmt|;
specifier|const
name|char
modifier|*
name|e
init|=
name|data
operator|.
name|constData
argument_list|()
operator|+
name|qMin
argument_list|(
name|data
operator|.
name|size
argument_list|()
operator|-
name|int
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
argument_list|,
name|m_endPos
operator|+
literal|1
argument_list|)
decl_stmt|;
for|for
control|(
init|;
name|p
operator|<=
name|e
condition|;
operator|++
name|p
control|)
block|{
if|if
condition|(
operator|(
name|qUnalignedLoad
argument_list|<
name|T
argument_list|>
argument_list|(
name|p
argument_list|)
operator|&
name|mask
operator|)
operator|==
operator|(
name|value
operator|&
name|mask
operator|)
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|makePattern
specifier|static
specifier|inline
name|QByteArray
name|makePattern
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
block|{
name|QByteArray
name|pattern
argument_list|(
name|value
operator|.
name|size
argument_list|()
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
name|char
modifier|*
name|data
init|=
name|pattern
operator|.
name|data
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|p
init|=
name|value
operator|.
name|constData
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|e
init|=
name|p
operator|+
name|value
operator|.
name|size
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|p
operator|<
name|e
condition|;
operator|++
name|p
control|)
block|{
if|if
condition|(
operator|*
name|p
operator|==
literal|'\\'
operator|&&
operator|++
name|p
operator|<
name|e
condition|)
block|{
if|if
condition|(
operator|*
name|p
operator|==
literal|'x'
condition|)
block|{
comment|// hex (\\xff)
name|char
name|c
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
literal|2
operator|&&
name|p
operator|+
literal|1
operator|<
name|e
condition|;
operator|++
name|i
control|)
block|{
operator|++
name|p
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|>=
literal|'0'
operator|&&
operator|*
name|p
operator|<=
literal|'9'
condition|)
name|c
operator|=
operator|(
name|c
operator|<<
literal|4
operator|)
operator|+
operator|*
name|p
operator|-
literal|'0'
expr_stmt|;
elseif|else
if|if
condition|(
operator|*
name|p
operator|>=
literal|'a'
operator|&&
operator|*
name|p
operator|<=
literal|'f'
condition|)
name|c
operator|=
operator|(
name|c
operator|<<
literal|4
operator|)
operator|+
operator|*
name|p
operator|-
literal|'a'
operator|+
literal|10
expr_stmt|;
elseif|else
if|if
condition|(
operator|*
name|p
operator|>=
literal|'A'
operator|&&
operator|*
name|p
operator|<=
literal|'F'
condition|)
name|c
operator|=
operator|(
name|c
operator|<<
literal|4
operator|)
operator|+
operator|*
name|p
operator|-
literal|'A'
operator|+
literal|10
expr_stmt|;
else|else
continue|continue;
block|}
operator|*
name|data
operator|++
operator|=
name|c
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|p
operator|>=
literal|'0'
operator|&&
operator|*
name|p
operator|<=
literal|'7'
condition|)
block|{
comment|// oct (\\7, or \\77, or \\377)
name|char
name|c
init|=
operator|*
name|p
operator|-
literal|'0'
decl_stmt|;
if|if
condition|(
name|p
operator|+
literal|1
operator|<
name|e
operator|&&
name|p
index|[
literal|1
index|]
operator|>=
literal|'0'
operator|&&
name|p
index|[
literal|1
index|]
operator|<=
literal|'7'
condition|)
block|{
name|c
operator|=
operator|(
name|c
operator|<<
literal|3
operator|)
operator|+
operator|*
operator|(
operator|++
name|p
operator|)
operator|-
literal|'0'
expr_stmt|;
if|if
condition|(
name|p
operator|+
literal|1
operator|<
name|e
operator|&&
name|p
index|[
literal|1
index|]
operator|>=
literal|'0'
operator|&&
name|p
index|[
literal|1
index|]
operator|<=
literal|'7'
operator|&&
name|p
index|[
operator|-
literal|1
index|]
operator|<=
literal|'3'
condition|)
name|c
operator|=
operator|(
name|c
operator|<<
literal|3
operator|)
operator|+
operator|*
operator|(
operator|++
name|p
operator|)
operator|-
literal|'0'
expr_stmt|;
block|}
operator|*
name|data
operator|++
operator|=
name|c
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|p
operator|==
literal|'n'
condition|)
block|{
operator|*
name|data
operator|++
operator|=
literal|'\n'
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|p
operator|==
literal|'r'
condition|)
block|{
operator|*
name|data
operator|++
operator|=
literal|'\r'
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|p
operator|==
literal|'t'
condition|)
block|{
operator|*
name|data
operator|++
operator|=
literal|'\t'
expr_stmt|;
block|}
else|else
block|{
comment|// escaped
operator|*
name|data
operator|++
operator|=
operator|*
name|p
expr_stmt|;
block|}
block|}
else|else
block|{
operator|*
name|data
operator|++
operator|=
operator|*
name|p
expr_stmt|;
block|}
block|}
name|pattern
operator|.
name|truncate
argument_list|(
name|data
operator|-
name|pattern
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|pattern
return|;
block|}
end_function
begin_comment
comment|// Evaluate a magic match rule like
end_comment
begin_comment
comment|//<match value="must be converted with BinHex" type="string" offset="11"/>
end_comment
begin_comment
comment|//<match value="0x9501" type="big16" offset="0:64"/>
end_comment
begin_constructor
DECL|function|QMimeMagicRule
name|QMimeMagicRule
operator|::
name|QMimeMagicRule
parameter_list|(
specifier|const
name|QString
modifier|&
name|type
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|,
specifier|const
name|QString
modifier|&
name|offsets
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|mask
parameter_list|,
name|QString
modifier|*
name|errorString
parameter_list|)
member_init_list|:
name|m_type
argument_list|(
name|QMimeMagicRule
operator|::
name|type
argument_list|(
name|type
operator|.
name|toLatin1
argument_list|()
argument_list|)
argument_list|)
member_init_list|,
name|m_value
argument_list|(
name|value
argument_list|)
member_init_list|,
name|m_mask
argument_list|(
name|mask
argument_list|)
member_init_list|,
name|m_matchFunction
argument_list|(
literal|nullptr
argument_list|)
block|{
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|m_type
operator|==
name|Invalid
argument_list|)
condition|)
operator|*
name|errorString
operator|=
name|QLatin1String
argument_list|(
literal|"Type "
argument_list|)
operator|+
name|type
operator|+
name|QLatin1String
argument_list|(
literal|" is not supported"
argument_list|)
expr_stmt|;
comment|// Parse for offset as "1" or "1:10"
specifier|const
name|int
name|colonIndex
init|=
name|offsets
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QStringRef
name|startPosStr
init|=
name|offsets
operator|.
name|midRef
argument_list|(
literal|0
argument_list|,
name|colonIndex
argument_list|)
decl_stmt|;
comment|// \ These decay to returning 'offsets'
specifier|const
name|QStringRef
name|endPosStr
init|=
name|offsets
operator|.
name|midRef
argument_list|(
name|colonIndex
operator|+
literal|1
argument_list|)
decl_stmt|;
comment|// / unchanged when colonIndex == -1
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|!
name|QMimeTypeParserBase
operator|::
name|parseNumber
argument_list|(
name|startPosStr
argument_list|,
operator|&
name|m_startPos
argument_list|,
name|errorString
argument_list|)
argument_list|)
operator|||
name|Q_UNLIKELY
argument_list|(
operator|!
name|QMimeTypeParserBase
operator|::
name|parseNumber
argument_list|(
name|endPosStr
argument_list|,
operator|&
name|m_endPos
argument_list|,
name|errorString
argument_list|)
argument_list|)
condition|)
block|{
name|m_type
operator|=
name|Invalid
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|m_value
operator|.
name|isEmpty
argument_list|()
argument_list|)
condition|)
block|{
name|m_type
operator|=
name|Invalid
expr_stmt|;
if|if
condition|(
name|errorString
condition|)
operator|*
name|errorString
operator|=
name|QStringLiteral
argument_list|(
literal|"Invalid empty magic rule value"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|m_type
operator|>=
name|Host16
operator|&&
name|m_type
operator|<=
name|Byte
condition|)
block|{
name|bool
name|ok
decl_stmt|;
name|m_number
operator|=
name|m_value
operator|.
name|toUInt
argument_list|(
operator|&
name|ok
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// autodetect base
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|!
name|ok
argument_list|)
condition|)
block|{
name|m_type
operator|=
name|Invalid
expr_stmt|;
if|if
condition|(
name|errorString
condition|)
operator|*
name|errorString
operator|=
name|QLatin1String
argument_list|(
literal|"Invalid magic rule value \""
argument_list|)
operator|+
name|QLatin1String
argument_list|(
name|m_value
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
expr_stmt|;
return|return;
block|}
name|m_numberMask
operator|=
operator|!
name|m_mask
operator|.
name|isEmpty
argument_list|()
condition|?
name|m_mask
operator|.
name|toUInt
argument_list|(
operator|&
name|ok
argument_list|,
literal|0
argument_list|)
else|:
literal|0
expr_stmt|;
comment|// autodetect base
block|}
switch|switch
condition|(
name|m_type
condition|)
block|{
case|case
name|String
case|:
name|m_pattern
operator|=
name|makePattern
argument_list|(
name|m_value
argument_list|)
expr_stmt|;
name|m_pattern
operator|.
name|squeeze
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|m_mask
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|m_mask
operator|.
name|size
argument_list|()
operator|<
literal|4
operator|||
operator|!
name|m_mask
operator|.
name|startsWith
argument_list|(
literal|"0x"
argument_list|)
argument_list|)
condition|)
block|{
name|m_type
operator|=
name|Invalid
expr_stmt|;
if|if
condition|(
name|errorString
condition|)
operator|*
name|errorString
operator|=
name|QLatin1String
argument_list|(
literal|"Invalid magic rule mask \""
argument_list|)
operator|+
name|QLatin1String
argument_list|(
name|m_mask
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
expr_stmt|;
return|return;
block|}
specifier|const
name|QByteArray
modifier|&
name|tempMask
init|=
name|QByteArray
operator|::
name|fromHex
argument_list|(
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|m_mask
operator|.
name|constData
argument_list|()
operator|+
literal|2
argument_list|,
name|m_mask
operator|.
name|size
argument_list|()
operator|-
literal|2
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|tempMask
operator|.
name|size
argument_list|()
operator|!=
name|m_pattern
operator|.
name|size
argument_list|()
argument_list|)
condition|)
block|{
name|m_type
operator|=
name|Invalid
expr_stmt|;
if|if
condition|(
name|errorString
condition|)
operator|*
name|errorString
operator|=
name|QLatin1String
argument_list|(
literal|"Invalid magic rule mask size \""
argument_list|)
operator|+
name|QLatin1String
argument_list|(
name|m_mask
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
expr_stmt|;
return|return;
block|}
name|m_mask
operator|=
name|tempMask
expr_stmt|;
block|}
else|else
block|{
name|m_mask
operator|.
name|fill
argument_list|(
name|char
argument_list|(
operator|-
literal|1
argument_list|)
argument_list|,
name|m_pattern
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|m_mask
operator|.
name|squeeze
argument_list|()
expr_stmt|;
name|m_matchFunction
operator|=
operator|&
name|QMimeMagicRule
operator|::
name|matchString
expr_stmt|;
break|break;
case|case
name|Byte
case|:
if|if
condition|(
name|m_number
operator|<=
name|quint8
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
block|{
if|if
condition|(
name|m_numberMask
operator|==
literal|0
condition|)
name|m_numberMask
operator|=
name|quint8
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|m_matchFunction
operator|=
operator|&
name|QMimeMagicRule
operator|::
name|matchNumber
argument_list|<
name|quint8
argument_list|>
expr_stmt|;
block|}
break|break;
case|case
name|Big16
case|:
case|case
name|Host16
case|:
case|case
name|Little16
case|:
if|if
condition|(
name|m_number
operator|<=
name|quint16
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
block|{
name|m_number
operator|=
name|m_type
operator|==
name|Little16
condition|?
name|qFromLittleEndian
argument_list|<
name|quint16
argument_list|>
argument_list|(
name|m_number
argument_list|)
else|:
name|qFromBigEndian
argument_list|<
name|quint16
argument_list|>
argument_list|(
name|m_number
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_numberMask
operator|==
literal|0
condition|)
name|m_numberMask
operator|=
name|quint16
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|m_matchFunction
operator|=
operator|&
name|QMimeMagicRule
operator|::
name|matchNumber
argument_list|<
name|quint16
argument_list|>
expr_stmt|;
block|}
break|break;
case|case
name|Big32
case|:
case|case
name|Host32
case|:
case|case
name|Little32
case|:
if|if
condition|(
name|m_number
operator|<=
name|quint32
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
block|{
name|m_number
operator|=
name|m_type
operator|==
name|Little32
condition|?
name|qFromLittleEndian
argument_list|<
name|quint32
argument_list|>
argument_list|(
name|m_number
argument_list|)
else|:
name|qFromBigEndian
argument_list|<
name|quint32
argument_list|>
argument_list|(
name|m_number
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_numberMask
operator|==
literal|0
condition|)
name|m_numberMask
operator|=
name|quint32
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|m_matchFunction
operator|=
operator|&
name|QMimeMagicRule
operator|::
name|matchNumber
argument_list|<
name|quint32
argument_list|>
expr_stmt|;
block|}
break|break;
default|default:
break|break;
block|}
block|}
end_constructor
begin_function
DECL|function|mask
name|QByteArray
name|QMimeMagicRule
operator|::
name|mask
parameter_list|()
specifier|const
block|{
name|QByteArray
name|result
init|=
name|m_mask
decl_stmt|;
if|if
condition|(
name|m_type
operator|==
name|String
condition|)
block|{
comment|// restore '0x'
name|result
operator|=
literal|"0x"
operator|+
name|result
operator|.
name|toHex
argument_list|()
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|matches
name|bool
name|QMimeMagicRule
operator|::
name|matches
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
specifier|const
block|{
specifier|const
name|bool
name|ok
init|=
name|m_matchFunction
operator|&&
call|(
name|this
operator|->*
name|m_matchFunction
call|)
argument_list|(
name|data
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
return|return
literal|false
return|;
comment|// No submatch? Then we are done.
if|if
condition|(
name|m_subMatches
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|true
return|;
comment|//qDebug()<< "Checking"<< m_subMatches.count()<< "sub-rules";
comment|// Check that one of the submatches matches too
for|for
control|(
name|QList
argument_list|<
name|QMimeMagicRule
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|m_subMatches
operator|.
name|begin
argument_list|()
init|,
name|end
init|=
name|m_subMatches
operator|.
name|end
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
operator|(
operator|*
name|it
operator|)
operator|.
name|matches
argument_list|(
name|data
argument_list|)
condition|)
block|{
comment|// One of the hierarchies matched -> mimetype recognized.
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
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
comment|// QT_NO_MIMETYPE
end_comment
end_unit
