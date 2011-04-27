begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"cppwriteicondata.h"
end_include
begin_include
include|#
directive|include
file|"driver.h"
end_include
begin_include
include|#
directive|include
file|"ui4.h"
end_include
begin_include
include|#
directive|include
file|"uic.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextStream>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_namespace
DECL|namespace|CPP
namespace|namespace
name|CPP
block|{
DECL|function|transformImageData
specifier|static
name|QByteArray
name|transformImageData
parameter_list|(
name|QString
name|data
parameter_list|)
block|{
name|int
name|baSize
init|=
name|data
operator|.
name|length
argument_list|()
operator|/
literal|2
decl_stmt|;
name|uchar
modifier|*
name|ba
init|=
operator|new
name|uchar
index|[
name|baSize
index|]
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
name|baSize
condition|;
operator|++
name|i
control|)
block|{
name|char
name|h
init|=
name|data
index|[
literal|2
operator|*
operator|(
name|i
operator|)
index|]
operator|.
name|toLatin1
argument_list|()
decl_stmt|;
name|char
name|l
init|=
name|data
index|[
literal|2
operator|*
operator|(
name|i
operator|)
operator|+
literal|1
index|]
operator|.
name|toLatin1
argument_list|()
decl_stmt|;
name|uchar
name|r
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|h
operator|<=
literal|'9'
condition|)
name|r
operator|+=
name|h
operator|-
literal|'0'
expr_stmt|;
else|else
name|r
operator|+=
name|h
operator|-
literal|'a'
operator|+
literal|10
expr_stmt|;
name|r
operator|=
name|r
operator|<<
literal|4
expr_stmt|;
if|if
condition|(
name|l
operator|<=
literal|'9'
condition|)
name|r
operator|+=
name|l
operator|-
literal|'0'
expr_stmt|;
else|else
name|r
operator|+=
name|l
operator|-
literal|'a'
operator|+
literal|10
expr_stmt|;
name|ba
index|[
name|i
index|]
operator|=
name|r
expr_stmt|;
block|}
name|QByteArray
name|ret
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|ba
argument_list|)
argument_list|,
name|baSize
argument_list|)
decl_stmt|;
operator|delete
index|[]
name|ba
expr_stmt|;
return|return
name|ret
return|;
block|}
DECL|function|unzipXPM
specifier|static
name|QByteArray
name|unzipXPM
parameter_list|(
name|QString
name|data
parameter_list|,
name|ulong
modifier|&
name|length
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_COMPRESS
specifier|const
name|int
name|lengthOffset
init|=
literal|4
decl_stmt|;
name|QByteArray
name|ba
argument_list|(
name|lengthOffset
argument_list|,
literal|' '
argument_list|)
decl_stmt|;
comment|// qUncompress() expects the first 4 bytes to be the expected length of the
comment|// uncompressed data
name|ba
index|[
literal|0
index|]
operator|=
operator|(
name|length
operator|&
literal|0xff000000
operator|)
operator|>>
literal|24
expr_stmt|;
name|ba
index|[
literal|1
index|]
operator|=
operator|(
name|length
operator|&
literal|0x00ff0000
operator|)
operator|>>
literal|16
expr_stmt|;
name|ba
index|[
literal|2
index|]
operator|=
operator|(
name|length
operator|&
literal|0x0000ff00
operator|)
operator|>>
literal|8
expr_stmt|;
name|ba
index|[
literal|3
index|]
operator|=
operator|(
name|length
operator|&
literal|0x000000ff
operator|)
expr_stmt|;
name|ba
operator|.
name|append
argument_list|(
name|transformImageData
argument_list|(
name|data
argument_list|)
argument_list|)
expr_stmt|;
name|QByteArray
name|baunzip
init|=
name|qUncompress
argument_list|(
name|ba
argument_list|)
decl_stmt|;
return|return
name|baunzip
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|length
argument_list|)
expr_stmt|;
return|return
name|QByteArray
argument_list|()
return|;
endif|#
directive|endif
block|}
DECL|function|WriteIconData
name|WriteIconData
operator|::
name|WriteIconData
parameter_list|(
name|Uic
modifier|*
name|uic
parameter_list|)
member_init_list|:
name|driver
argument_list|(
name|uic
operator|->
name|driver
argument_list|()
argument_list|)
member_init_list|,
name|output
argument_list|(
name|uic
operator|->
name|output
argument_list|()
argument_list|)
member_init_list|,
name|option
argument_list|(
name|uic
operator|->
name|option
argument_list|()
argument_list|)
block|{ }
DECL|function|acceptUI
name|void
name|WriteIconData
operator|::
name|acceptUI
parameter_list|(
name|DomUI
modifier|*
name|node
parameter_list|)
block|{
name|TreeWalker
operator|::
name|acceptUI
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
DECL|function|acceptImages
name|void
name|WriteIconData
operator|::
name|acceptImages
parameter_list|(
name|DomImages
modifier|*
name|images
parameter_list|)
block|{
name|TreeWalker
operator|::
name|acceptImages
argument_list|(
name|images
argument_list|)
expr_stmt|;
block|}
DECL|function|acceptImage
name|void
name|WriteIconData
operator|::
name|acceptImage
parameter_list|(
name|DomImage
modifier|*
name|image
parameter_list|)
block|{
comment|// Limit line length when writing code.
name|writeImage
argument_list|(
name|output
argument_list|,
name|option
operator|.
name|indent
argument_list|,
literal|true
argument_list|,
name|image
argument_list|)
expr_stmt|;
block|}
DECL|function|writeImage
name|void
name|WriteIconData
operator|::
name|writeImage
parameter_list|(
name|QTextStream
modifier|&
name|output
parameter_list|,
specifier|const
name|QString
modifier|&
name|indent
parameter_list|,
name|bool
name|limitXPM_LineLength
parameter_list|,
specifier|const
name|DomImage
modifier|*
name|image
parameter_list|)
block|{
name|QString
name|img
init|=
name|image
operator|->
name|attributeName
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"_data"
argument_list|)
decl_stmt|;
name|QString
name|data
init|=
name|image
operator|->
name|elementData
argument_list|()
operator|->
name|text
argument_list|()
decl_stmt|;
name|QString
name|fmt
init|=
name|image
operator|->
name|elementData
argument_list|()
operator|->
name|attributeFormat
argument_list|()
decl_stmt|;
name|int
name|size
init|=
name|image
operator|->
name|elementData
argument_list|()
operator|->
name|attributeLength
argument_list|()
decl_stmt|;
if|if
condition|(
name|fmt
operator|==
name|QLatin1String
argument_list|(
literal|"XPM.GZ"
argument_list|)
condition|)
block|{
name|ulong
name|length
init|=
name|size
decl_stmt|;
name|QByteArray
name|baunzip
init|=
name|unzipXPM
argument_list|(
name|data
argument_list|,
name|length
argument_list|)
decl_stmt|;
name|length
operator|=
name|baunzip
operator|.
name|size
argument_list|()
expr_stmt|;
comment|// shouldn't we test the initial 'length' against the
comment|// resulting 'length' to catch corrupt UIC files?
name|int
name|a
init|=
literal|0
decl_stmt|;
name|int
name|column
init|=
literal|0
decl_stmt|;
name|bool
name|inQuote
init|=
literal|false
decl_stmt|;
name|output
operator|<<
name|indent
operator|<<
literal|"/* XPM */\n"
operator|<<
name|indent
operator|<<
literal|"static const char* const "
operator|<<
name|img
operator|<<
literal|"[] = { \n"
expr_stmt|;
while|while
condition|(
name|baunzip
index|[
name|a
index|]
operator|!=
literal|'\"'
condition|)
name|a
operator|++
expr_stmt|;
for|for
control|(
init|;
name|a
operator|<
operator|(
name|int
operator|)
name|length
condition|;
name|a
operator|++
control|)
block|{
name|output
operator|<<
name|baunzip
index|[
name|a
index|]
expr_stmt|;
if|if
condition|(
name|baunzip
index|[
name|a
index|]
operator|==
literal|'\n'
condition|)
block|{
name|column
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|baunzip
index|[
name|a
index|]
operator|==
literal|'"'
condition|)
block|{
name|inQuote
operator|=
operator|!
name|inQuote
expr_stmt|;
block|}
name|column
operator|++
expr_stmt|;
if|if
condition|(
name|limitXPM_LineLength
operator|&&
name|column
operator|>=
literal|512
operator|&&
name|inQuote
condition|)
block|{
name|output
operator|<<
literal|"\"\n\""
expr_stmt|;
comment|// be nice with MSVC& Co.
name|column
operator|=
literal|1
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|baunzip
operator|.
name|trimmed
argument_list|()
operator|.
name|endsWith
argument_list|(
literal|"};"
argument_list|)
condition|)
name|output
operator|<<
literal|"};"
expr_stmt|;
name|output
operator|<<
literal|"\n\n"
expr_stmt|;
block|}
else|else
block|{
name|output
operator|<<
name|indent
operator|<<
literal|"static const unsigned char "
operator|<<
name|img
operator|<<
literal|"[] = { \n"
expr_stmt|;
name|output
operator|<<
name|indent
expr_stmt|;
name|int
name|a
decl_stmt|;
for|for
control|(
name|a
operator|=
literal|0
init|;
name|a
operator|<
call|(
name|int
call|)
argument_list|(
name|data
operator|.
name|length
argument_list|()
operator|/
literal|2
argument_list|)
operator|-
literal|1
condition|;
name|a
operator|++
control|)
block|{
name|output
operator|<<
literal|"0x"
operator|<<
name|QString
argument_list|(
name|data
index|[
literal|2
operator|*
name|a
index|]
argument_list|)
operator|<<
name|QString
argument_list|(
name|data
index|[
literal|2
operator|*
name|a
operator|+
literal|1
index|]
argument_list|)
operator|<<
literal|','
expr_stmt|;
if|if
condition|(
name|a
operator|%
literal|12
operator|==
literal|11
condition|)
name|output
operator|<<
literal|'\n'
operator|<<
name|indent
expr_stmt|;
else|else
name|output
operator|<<
literal|' '
expr_stmt|;
block|}
name|output
operator|<<
literal|"0x"
operator|<<
name|QString
argument_list|(
name|data
index|[
literal|2
operator|*
name|a
index|]
argument_list|)
operator|<<
name|QString
argument_list|(
name|data
index|[
literal|2
operator|*
name|a
operator|+
literal|1
index|]
argument_list|)
operator|<<
literal|'\n'
expr_stmt|;
name|output
operator|<<
literal|"};\n\n"
expr_stmt|;
block|}
block|}
DECL|function|writeImage
name|void
name|WriteIconData
operator|::
name|writeImage
parameter_list|(
name|QIODevice
modifier|&
name|output
parameter_list|,
name|DomImage
modifier|*
name|image
parameter_list|)
block|{
name|QByteArray
name|array
init|=
name|transformImageData
argument_list|(
name|image
operator|->
name|elementData
argument_list|()
operator|->
name|text
argument_list|()
argument_list|)
decl_stmt|;
name|output
operator|.
name|write
argument_list|(
name|array
argument_list|,
name|array
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_namespace
begin_comment
comment|// namespace CPP
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
