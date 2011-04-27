begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"bencodeparser.h"
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QMetaType>
end_include
begin_constructor
DECL|function|BencodeParser
name|BencodeParser
operator|::
name|BencodeParser
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|parse
name|bool
name|BencodeParser
operator|::
name|parse
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|content
parameter_list|)
block|{
if|if
condition|(
name|content
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|errString
operator|=
name|QString
argument_list|(
literal|"No content"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|this
operator|->
name|content
operator|=
name|content
expr_stmt|;
name|index
operator|=
literal|0
expr_stmt|;
name|infoStart
operator|=
literal|0
expr_stmt|;
name|infoLength
operator|=
literal|0
expr_stmt|;
return|return
name|getDictionary
argument_list|(
operator|&
name|dictionaryValue
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|errorString
name|QString
name|BencodeParser
operator|::
name|errorString
parameter_list|()
specifier|const
block|{
return|return
name|errString
return|;
block|}
end_function
begin_function
DECL|function|dictionary
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QVariant
argument_list|>
name|BencodeParser
operator|::
name|dictionary
parameter_list|()
specifier|const
block|{
return|return
name|dictionaryValue
return|;
block|}
end_function
begin_function
DECL|function|infoSection
name|QByteArray
name|BencodeParser
operator|::
name|infoSection
parameter_list|()
specifier|const
block|{
return|return
name|content
operator|.
name|mid
argument_list|(
name|infoStart
argument_list|,
name|infoLength
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|getByteString
name|bool
name|BencodeParser
operator|::
name|getByteString
parameter_list|(
name|QByteArray
modifier|*
name|byteString
parameter_list|)
block|{
specifier|const
name|int
name|contentSize
init|=
name|content
operator|.
name|size
argument_list|()
decl_stmt|;
name|int
name|size
init|=
operator|-
literal|1
decl_stmt|;
do|do
block|{
name|char
name|c
init|=
name|content
operator|.
name|at
argument_list|(
name|index
argument_list|)
decl_stmt|;
if|if
condition|(
name|c
argument_list|<
literal|'0'
operator|||
name|c
argument_list|>
literal|'9'
condition|)
block|{
if|if
condition|(
name|size
operator|==
operator|-
literal|1
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|c
operator|!=
literal|':'
condition|)
block|{
name|errString
operator|=
name|QString
argument_list|(
literal|"Unexpected character at pos %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|index
argument_list|)
operator|.
name|arg
argument_list|(
name|c
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
operator|++
name|index
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|size
operator|==
operator|-
literal|1
condition|)
name|size
operator|=
literal|0
expr_stmt|;
name|size
operator|*=
literal|10
expr_stmt|;
name|size
operator|+=
name|c
operator|-
literal|'0'
expr_stmt|;
block|}
do|while
condition|(
operator|++
name|index
operator|<
name|contentSize
condition|)
do|;
if|if
condition|(
name|byteString
condition|)
operator|*
name|byteString
operator|=
name|content
operator|.
name|mid
argument_list|(
name|index
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|index
operator|+=
name|size
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|getInteger
name|bool
name|BencodeParser
operator|::
name|getInteger
parameter_list|(
name|qint64
modifier|*
name|integer
parameter_list|)
block|{
specifier|const
name|int
name|contentSize
init|=
name|content
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|content
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|!=
literal|'i'
condition|)
return|return
literal|false
return|;
operator|++
name|index
expr_stmt|;
name|qint64
name|num
init|=
operator|-
literal|1
decl_stmt|;
name|bool
name|negative
init|=
literal|false
decl_stmt|;
do|do
block|{
name|char
name|c
init|=
name|content
operator|.
name|at
argument_list|(
name|index
argument_list|)
decl_stmt|;
if|if
condition|(
name|c
argument_list|<
literal|'0'
operator|||
name|c
argument_list|>
literal|'9'
condition|)
block|{
if|if
condition|(
name|num
operator|==
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|c
operator|!=
literal|'-'
operator|||
name|negative
condition|)
return|return
literal|false
return|;
name|negative
operator|=
literal|true
expr_stmt|;
continue|continue;
block|}
else|else
block|{
if|if
condition|(
name|c
operator|!=
literal|'e'
condition|)
block|{
name|errString
operator|=
name|QString
argument_list|(
literal|"Unexpected character at pos %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|index
argument_list|)
operator|.
name|arg
argument_list|(
name|c
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
operator|++
name|index
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|num
operator|==
operator|-
literal|1
condition|)
name|num
operator|=
literal|0
expr_stmt|;
name|num
operator|*=
literal|10
expr_stmt|;
name|num
operator|+=
name|c
operator|-
literal|'0'
expr_stmt|;
block|}
do|while
condition|(
operator|++
name|index
operator|<
name|contentSize
condition|)
do|;
if|if
condition|(
name|integer
condition|)
operator|*
name|integer
operator|=
name|negative
condition|?
operator|-
name|num
else|:
name|num
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|getList
name|bool
name|BencodeParser
operator|::
name|getList
parameter_list|(
name|QList
argument_list|<
name|QVariant
argument_list|>
modifier|*
name|list
parameter_list|)
block|{
specifier|const
name|int
name|contentSize
init|=
name|content
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|content
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|!=
literal|'l'
condition|)
return|return
literal|false
return|;
name|QList
argument_list|<
name|QVariant
argument_list|>
name|tmp
decl_stmt|;
operator|++
name|index
expr_stmt|;
do|do
block|{
if|if
condition|(
name|content
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|==
literal|'e'
condition|)
block|{
operator|++
name|index
expr_stmt|;
break|break;
block|}
name|qint64
name|number
decl_stmt|;
name|QByteArray
name|byteString
decl_stmt|;
name|QList
argument_list|<
name|QVariant
argument_list|>
name|tmpList
decl_stmt|;
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QVariant
argument_list|>
name|dictionary
decl_stmt|;
if|if
condition|(
name|getInteger
argument_list|(
operator|&
name|number
argument_list|)
condition|)
name|tmp
operator|<<
name|number
expr_stmt|;
elseif|else
if|if
condition|(
name|getByteString
argument_list|(
operator|&
name|byteString
argument_list|)
condition|)
name|tmp
operator|<<
name|byteString
expr_stmt|;
elseif|else
if|if
condition|(
name|getList
argument_list|(
operator|&
name|tmpList
argument_list|)
condition|)
name|tmp
operator|<<
name|tmpList
expr_stmt|;
elseif|else
if|if
condition|(
name|getDictionary
argument_list|(
operator|&
name|dictionary
argument_list|)
condition|)
name|tmp
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|<
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QVariant
argument_list|>
argument_list|>
argument_list|(
name|dictionary
argument_list|)
expr_stmt|;
else|else
block|{
name|errString
operator|=
name|QString
argument_list|(
literal|"error at index %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|index
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
do|while
condition|(
name|index
operator|<
name|contentSize
condition|)
do|;
if|if
condition|(
name|list
condition|)
operator|*
name|list
operator|=
name|tmp
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|getDictionary
name|bool
name|BencodeParser
operator|::
name|getDictionary
parameter_list|(
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QVariant
argument_list|>
modifier|*
name|dictionary
parameter_list|)
block|{
specifier|const
name|int
name|contentSize
init|=
name|content
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|content
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|!=
literal|'d'
condition|)
return|return
literal|false
return|;
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QVariant
argument_list|>
name|tmp
decl_stmt|;
operator|++
name|index
expr_stmt|;
do|do
block|{
if|if
condition|(
name|content
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|==
literal|'e'
condition|)
block|{
operator|++
name|index
expr_stmt|;
break|break;
block|}
name|QByteArray
name|key
decl_stmt|;
if|if
condition|(
operator|!
name|getByteString
argument_list|(
operator|&
name|key
argument_list|)
condition|)
break|break;
if|if
condition|(
name|key
operator|==
literal|"info"
condition|)
name|infoStart
operator|=
name|index
expr_stmt|;
name|qint64
name|number
decl_stmt|;
name|QByteArray
name|byteString
decl_stmt|;
name|QList
argument_list|<
name|QVariant
argument_list|>
name|tmpList
decl_stmt|;
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QVariant
argument_list|>
name|dictionary
decl_stmt|;
if|if
condition|(
name|getInteger
argument_list|(
operator|&
name|number
argument_list|)
condition|)
name|tmp
operator|.
name|insert
argument_list|(
name|key
argument_list|,
name|number
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|getByteString
argument_list|(
operator|&
name|byteString
argument_list|)
condition|)
name|tmp
operator|.
name|insert
argument_list|(
name|key
argument_list|,
name|byteString
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|getList
argument_list|(
operator|&
name|tmpList
argument_list|)
condition|)
name|tmp
operator|.
name|insert
argument_list|(
name|key
argument_list|,
name|tmpList
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|getDictionary
argument_list|(
operator|&
name|dictionary
argument_list|)
condition|)
name|tmp
operator|.
name|insert
argument_list|(
name|key
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|<
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QVariant
argument_list|>
argument_list|>
argument_list|(
name|dictionary
argument_list|)
argument_list|)
expr_stmt|;
else|else
block|{
name|errString
operator|=
name|QString
argument_list|(
literal|"error at index %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|index
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|key
operator|==
literal|"info"
condition|)
name|infoLength
operator|=
name|index
operator|-
name|infoStart
expr_stmt|;
block|}
do|while
condition|(
name|index
operator|<
name|contentSize
condition|)
do|;
if|if
condition|(
name|dictionary
condition|)
operator|*
name|dictionary
operator|=
name|tmp
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
end_unit
