begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"main.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|qHash
name|uint
name|qHash
parameter_list|(
specifier|const
name|Qt4String
modifier|&
name|str
parameter_list|)
block|{
name|int
name|n
init|=
name|str
operator|.
name|length
argument_list|()
decl_stmt|;
specifier|const
name|QChar
modifier|*
name|p
init|=
name|str
operator|.
name|unicode
argument_list|()
decl_stmt|;
name|uint
name|h
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|n
operator|--
condition|)
block|{
name|h
operator|=
operator|(
name|h
operator|<<
literal|4
operator|)
operator|+
operator|(
operator|*
name|p
operator|++
operator|)
operator|.
name|unicode
argument_list|()
expr_stmt|;
name|h
operator|^=
operator|(
name|h
operator|&
literal|0xf0000000
operator|)
operator|>>
literal|23
expr_stmt|;
name|h
operator|&=
literal|0x0fffffff
expr_stmt|;
block|}
return|return
name|h
return|;
block|}
end_function
begin_function
DECL|function|qHash
name|uint
name|qHash
parameter_list|(
specifier|const
name|Qt50String
modifier|&
name|key
parameter_list|,
name|uint
name|seed
parameter_list|)
block|{
specifier|const
name|QChar
modifier|*
name|p
init|=
name|key
operator|.
name|unicode
argument_list|()
decl_stmt|;
name|int
name|len
init|=
name|key
operator|.
name|size
argument_list|()
decl_stmt|;
name|uint
name|h
init|=
name|seed
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
operator|++
name|i
control|)
name|h
operator|=
literal|31
operator|*
name|h
operator|+
name|p
index|[
name|i
index|]
operator|.
name|unicode
argument_list|()
expr_stmt|;
return|return
name|h
return|;
block|}
end_function
begin_comment
comment|// The Java's hashing algorithm for strings is a variation of D. J. Bernstein
end_comment
begin_comment
comment|// hashing algorithm appeared here http://cr.yp.to/cdb/cdb.txt
end_comment
begin_comment
comment|// and informally known as DJB33XX - DJB's 33 Times Xor.
end_comment
begin_comment
comment|// Java uses DJB31XA, that is, 31 Times Add.
end_comment
begin_comment
comment|// The original algorithm was a loop around  "(h<< 5) + h ^ c",
end_comment
begin_comment
comment|// which is indeed "h * 33 ^ c"; it was then changed to
end_comment
begin_comment
comment|// "(h<< 5) - h ^ c", so "h * 31 ^ c", and the XOR changed to a sum:
end_comment
begin_comment
comment|// "(h<< 5) - h + c", which can save some assembly instructions.
end_comment
begin_comment
comment|// Still, we can avoid writing the multiplication as "(h<< 5) - h"
end_comment
begin_comment
comment|// -- the compiler will turn it into a shift and an addition anyway
end_comment
begin_comment
comment|// (for instance, gcc 4.4 does that even at -O0).
end_comment
begin_function
DECL|function|qHash
name|uint
name|qHash
parameter_list|(
specifier|const
name|JavaString
modifier|&
name|str
parameter_list|)
block|{
specifier|const
name|unsigned
name|short
modifier|*
name|p
init|=
operator|(
name|unsigned
name|short
operator|*
operator|)
name|str
operator|.
name|constData
argument_list|()
decl_stmt|;
specifier|const
name|int
name|len
init|=
name|str
operator|.
name|size
argument_list|()
decl_stmt|;
name|uint
name|h
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
name|len
condition|;
operator|++
name|i
control|)
name|h
operator|=
literal|31
operator|*
name|h
operator|+
name|p
index|[
name|i
index|]
expr_stmt|;
return|return
name|h
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
