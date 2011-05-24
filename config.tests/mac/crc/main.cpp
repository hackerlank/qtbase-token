begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the config.tests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<iostream>
end_include
begin_include
include|#
directive|include
file|<cstdlib>
end_include
begin_include
include|#
directive|include
file|<cstring>
end_include
begin_class
DECL|class|CCRC32
class|class
name|CCRC32
block|{
public|public:
DECL|function|CCRC32
name|CCRC32
parameter_list|()
block|{
name|initialize
argument_list|()
expr_stmt|;
block|}
DECL|function|FullCRC
name|unsigned
name|long
name|FullCRC
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|sData
parameter_list|,
name|unsigned
name|long
name|ulDataLength
parameter_list|)
block|{
name|unsigned
name|long
name|ulCRC
init|=
literal|0xffffffff
decl_stmt|;
name|PartialCRC
argument_list|(
operator|&
name|ulCRC
argument_list|,
name|sData
argument_list|,
name|ulDataLength
argument_list|)
expr_stmt|;
return|return
operator|(
name|ulCRC
operator|^
literal|0xffffffff
operator|)
return|;
block|}
DECL|function|PartialCRC
name|void
name|PartialCRC
parameter_list|(
name|unsigned
name|long
modifier|*
name|ulCRC
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|sData
parameter_list|,
name|unsigned
name|long
name|ulDataLength
parameter_list|)
block|{
while|while
condition|(
name|ulDataLength
operator|--
condition|)
block|{
operator|*
name|ulCRC
operator|=
operator|(
operator|*
name|ulCRC
operator|>>
literal|8
operator|)
operator|^
name|ulTable
index|[
operator|(
operator|*
name|ulCRC
operator|&
literal|0xFF
operator|)
operator|^
operator|*
name|sData
operator|++
index|]
expr_stmt|;
block|}
block|}
private|private:
DECL|function|initialize
name|void
name|initialize
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|long
name|ulPolynomial
init|=
literal|0x04C11DB7
decl_stmt|;
name|memset
argument_list|(
operator|&
name|ulTable
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|ulTable
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|iCodes
init|=
literal|0
init|;
name|iCodes
operator|<=
literal|0xFF
condition|;
name|iCodes
operator|++
control|)
block|{
name|ulTable
index|[
name|iCodes
index|]
operator|=
name|Reflect
argument_list|(
name|iCodes
argument_list|,
literal|8
argument_list|)
operator|<<
literal|24
expr_stmt|;
for|for
control|(
name|int
name|iPos
init|=
literal|0
init|;
name|iPos
operator|<
literal|8
condition|;
name|iPos
operator|++
control|)
block|{
name|ulTable
index|[
name|iCodes
index|]
operator|=
operator|(
operator|(
name|ulTable
index|[
name|iCodes
index|]
operator|<<
literal|1
operator|)
operator|&
literal|0xffffffff
operator|)
operator|^
operator|(
operator|(
name|ulTable
index|[
name|iCodes
index|]
operator|&
operator|(
literal|1
operator|<<
literal|31
operator|)
operator|)
condition|?
name|ulPolynomial
else|:
literal|0
operator|)
expr_stmt|;
block|}
name|ulTable
index|[
name|iCodes
index|]
operator|=
name|Reflect
argument_list|(
name|ulTable
index|[
name|iCodes
index|]
argument_list|,
literal|32
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|Reflect
name|unsigned
name|long
name|Reflect
parameter_list|(
name|unsigned
name|long
name|ulReflect
parameter_list|,
specifier|const
name|char
name|cChar
parameter_list|)
block|{
name|unsigned
name|long
name|ulValue
init|=
literal|0
decl_stmt|;
comment|// Swap bit 0 for bit 7, bit 1 For bit 6, etc....
for|for
control|(
name|int
name|iPos
init|=
literal|1
init|;
name|iPos
operator|<
operator|(
name|cChar
operator|+
literal|1
operator|)
condition|;
name|iPos
operator|++
control|)
block|{
if|if
condition|(
name|ulReflect
operator|&
literal|1
condition|)
block|{
name|ulValue
operator||=
operator|(
literal|1ul
operator|<<
operator|(
name|cChar
operator|-
name|iPos
operator|)
operator|)
expr_stmt|;
block|}
name|ulReflect
operator|>>=
literal|1
expr_stmt|;
block|}
return|return
name|ulValue
return|;
block|}
DECL|member|ulTable
name|unsigned
name|long
name|ulTable
index|[
literal|256
index|]
decl_stmt|;
comment|// CRC lookup table array.
block|}
class|;
end_class
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|CCRC32
name|crc
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
block|{
name|std
operator|::
name|cerr
operator|<<
literal|"usage: crc<string>\n"
expr_stmt|;
return|return
literal|0
return|;
block|}
else|else
block|{
name|name
operator|=
name|argv
index|[
literal|1
index|]
expr_stmt|;
block|}
name|std
operator|::
name|cout
operator|<<
name|crc
operator|.
name|FullCRC
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
name|name
argument_list|,
name|strlen
argument_list|(
name|name
argument_list|)
argument_list|)
operator|<<
name|std
operator|::
name|endl
expr_stmt|;
block|}
end_function
end_unit
