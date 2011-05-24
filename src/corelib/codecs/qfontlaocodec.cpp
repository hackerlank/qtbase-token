begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfontlaocodec_p.h"
end_include
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CODECS
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BIG_CODECS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|unicode_to_mulelao
specifier|static
name|unsigned
name|char
specifier|const
name|unicode_to_mulelao
index|[
literal|256
index|]
init|=
block|{
comment|// U+0E80
literal|0x00
block|,
literal|0xa1
block|,
literal|0xa2
block|,
literal|0x00
block|,
literal|0xa4
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xa7
block|,
literal|0xa8
block|,
literal|0x00
block|,
literal|0xaa
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xad
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|// U+0E90
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xb4
block|,
literal|0xb5
block|,
literal|0xb6
block|,
literal|0xb7
block|,
literal|0x00
block|,
literal|0xb9
block|,
literal|0xba
block|,
literal|0xbb
block|,
literal|0xbc
block|,
literal|0xbd
block|,
literal|0xbe
block|,
literal|0xbf
block|,
comment|// U+0EA0
literal|0x00
block|,
literal|0xc1
block|,
literal|0xc2
block|,
literal|0xc3
block|,
literal|0x00
block|,
literal|0xc5
block|,
literal|0x00
block|,
literal|0xc7
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xca
block|,
literal|0xcb
block|,
literal|0x00
block|,
literal|0xcd
block|,
literal|0xce
block|,
literal|0xcf
block|,
comment|// U+0EB0
literal|0xd0
block|,
literal|0xd1
block|,
literal|0xd2
block|,
literal|0xd3
block|,
literal|0xd4
block|,
literal|0xd5
block|,
literal|0xd6
block|,
literal|0xd7
block|,
literal|0xd8
block|,
literal|0xd9
block|,
literal|0x00
block|,
literal|0xdb
block|,
literal|0xdc
block|,
literal|0xdd
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|// U+0EC0
literal|0xe0
block|,
literal|0xe1
block|,
literal|0xe2
block|,
literal|0xe3
block|,
literal|0xe4
block|,
literal|0x00
block|,
literal|0xe6
block|,
literal|0x00
block|,
literal|0xe8
block|,
literal|0xe9
block|,
literal|0xea
block|,
literal|0xeb
block|,
literal|0xec
block|,
literal|0xed
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|// U+0ED0
literal|0xf0
block|,
literal|0xf1
block|,
literal|0xf2
block|,
literal|0xf3
block|,
literal|0xf4
block|,
literal|0xf5
block|,
literal|0xf6
block|,
literal|0xf7
block|,
literal|0xf8
block|,
literal|0xf9
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xfc
block|,
literal|0xfd
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|// U+0EE0
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|// U+0EF0
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|}
decl_stmt|;
end_decl_stmt
begin_destructor
DECL|function|~QFontLaoCodec
name|QFontLaoCodec
operator|::
name|~
name|QFontLaoCodec
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|name
name|QByteArray
name|QFontLaoCodec
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
literal|"mulelao-1"
return|;
block|}
end_function
begin_function
DECL|function|mibEnum
name|int
name|QFontLaoCodec
operator|::
name|mibEnum
parameter_list|()
specifier|const
block|{
return|return
operator|-
literal|4242
return|;
block|}
end_function
begin_function
DECL|function|convertToUnicode
name|QString
name|QFontLaoCodec
operator|::
name|convertToUnicode
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|ConverterState
modifier|*
parameter_list|)
specifier|const
block|{
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|convertFromUnicode
name|QByteArray
name|QFontLaoCodec
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
parameter_list|)
specifier|const
block|{
name|QByteArray
name|rstring
argument_list|(
name|len
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
name|uchar
modifier|*
name|rdata
init|=
operator|(
name|uchar
operator|*
operator|)
name|rstring
operator|.
name|data
argument_list|()
decl_stmt|;
specifier|const
name|QChar
modifier|*
name|sdata
init|=
name|uc
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
name|i
operator|<
name|len
condition|;
operator|++
name|i
operator|,
operator|++
name|sdata
operator|,
operator|++
name|rdata
control|)
block|{
if|if
condition|(
name|sdata
operator|->
name|unicode
argument_list|()
operator|<
literal|0x80
condition|)
block|{
operator|*
name|rdata
operator|=
operator|(
name|uchar
operator|)
name|sdata
operator|->
name|unicode
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|sdata
operator|->
name|unicode
argument_list|()
operator|>=
literal|0x0e80
operator|&&
name|sdata
operator|->
name|unicode
argument_list|()
operator|<=
literal|0x0eff
condition|)
block|{
name|uchar
name|lao
init|=
name|unicode_to_mulelao
index|[
name|sdata
operator|->
name|unicode
argument_list|()
operator|-
literal|0x0e80
index|]
decl_stmt|;
if|if
condition|(
name|lao
condition|)
operator|*
name|rdata
operator|=
name|lao
expr_stmt|;
else|else
operator|*
name|rdata
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
operator|*
name|rdata
operator|=
literal|0
expr_stmt|;
block|}
block|}
return|return
name|rstring
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
comment|// QT_NO_BIG_CODECS
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CODECS
end_comment
end_unit
