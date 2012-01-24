begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfontjpcodec_p.h"
end_include
begin_include
include|#
directive|include
file|"qjpunicode_p.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|Q_OS_UNIX
comment|// JIS X 0201
DECL|function|QFontJis0201Codec
name|QFontJis0201Codec
operator|::
name|QFontJis0201Codec
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|_name
name|QByteArray
name|QFontJis0201Codec
operator|::
name|_name
parameter_list|()
block|{
return|return
literal|"jisx0201*-0"
return|;
block|}
end_function
begin_function
DECL|function|_mibEnum
name|int
name|QFontJis0201Codec
operator|::
name|_mibEnum
parameter_list|()
block|{
return|return
literal|15
return|;
block|}
end_function
begin_function
DECL|function|convertFromUnicode
name|QByteArray
name|QFontJis0201Codec
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
decl_stmt|;
name|rstring
operator|.
name|resize
argument_list|(
name|len
argument_list|)
expr_stmt|;
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
literal|0xff61
operator|&&
name|sdata
operator|->
name|unicode
argument_list|()
operator|<=
literal|0xff9f
condition|)
block|{
operator|*
name|rdata
operator|=
call|(
name|uchar
call|)
argument_list|(
name|sdata
operator|->
name|unicode
argument_list|()
operator|-
literal|0xff61
operator|+
literal|0xa1
argument_list|)
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
begin_function
DECL|function|convertToUnicode
name|QString
name|QFontJis0201Codec
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
begin_comment
comment|// JIS X 0208
end_comment
begin_constructor
DECL|function|QFontJis0208Codec
name|QFontJis0208Codec
operator|::
name|QFontJis0208Codec
parameter_list|()
block|{
name|convJP
operator|=
name|QJpUnicodeConv
operator|::
name|newConverter
argument_list|(
name|QJpUnicodeConv
operator|::
name|Default
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QFontJis0208Codec
name|QFontJis0208Codec
operator|::
name|~
name|QFontJis0208Codec
parameter_list|()
block|{
operator|delete
name|convJP
expr_stmt|;
name|convJP
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|_name
name|QByteArray
name|QFontJis0208Codec
operator|::
name|_name
parameter_list|()
block|{
return|return
literal|"jisx0208*-0"
return|;
block|}
end_function
begin_function
DECL|function|_mibEnum
name|int
name|QFontJis0208Codec
operator|::
name|_mibEnum
parameter_list|()
block|{
return|return
literal|63
return|;
block|}
end_function
begin_function
DECL|function|convertToUnicode
name|QString
name|QFontJis0208Codec
operator|::
name|convertToUnicode
parameter_list|(
specifier|const
name|char
modifier|*
comment|/*chars*/
parameter_list|,
name|int
comment|/*len*/
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
name|QFontJis0208Codec
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
name|result
decl_stmt|;
name|result
operator|.
name|resize
argument_list|(
name|len
operator|*
literal|2
argument_list|)
expr_stmt|;
name|uchar
modifier|*
name|rdata
init|=
operator|(
name|uchar
operator|*
operator|)
name|result
operator|.
name|data
argument_list|()
decl_stmt|;
specifier|const
name|QChar
modifier|*
name|ucp
init|=
name|uc
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
name|len
condition|;
name|i
operator|++
control|)
block|{
name|QChar
name|ch
argument_list|(
operator|*
name|ucp
operator|++
argument_list|)
decl_stmt|;
name|ch
operator|=
name|convJP
operator|->
name|unicodeToJisx0208
argument_list|(
name|ch
operator|.
name|unicode
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ch
operator|.
name|isNull
argument_list|()
condition|)
block|{
operator|*
name|rdata
operator|++
operator|=
name|ch
operator|.
name|row
argument_list|()
expr_stmt|;
operator|*
name|rdata
operator|++
operator|=
name|ch
operator|.
name|cell
argument_list|()
expr_stmt|;
block|}
else|else
block|{
operator|*
name|rdata
operator|++
operator|=
literal|0
expr_stmt|;
operator|*
name|rdata
operator|++
operator|=
literal|0
expr_stmt|;
block|}
block|}
return|return
name|result
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
