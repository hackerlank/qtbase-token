begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_function
DECL|function|loadInvalidUtf8Rows
name|void
name|loadInvalidUtf8Rows
parameter_list|()
block|{
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1char"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\x80"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2chars-1"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xC2\xC0"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2chars-2"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xC3\xDF"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2chars-3"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xC7\xF0"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"3chars-1"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xE0\xA0\xC0"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"3chars-2"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xE0\xC0\xA0"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"4chars-1"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xF0\x90\x80\xC0"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"4chars-2"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xF0\x90\xC0\x80"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"4chars-3"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xF0\xC0\x80\x80"
argument_list|)
expr_stmt|;
comment|// Surrogate pairs must now be present either
comment|// U+D800:        1101   10 0000   00 0000
comment|// encoding: xxxz:1101 xz10:0000 xz00:0000
name|QTest
operator|::
name|newRow
argument_list|(
literal|"hi-surrogate"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xED\xA0\x80"
argument_list|)
expr_stmt|;
comment|// U+DC00:        1101   11 0000   00 0000
comment|// encoding: xxxz:1101 xz11:0000 xz00:0000
name|QTest
operator|::
name|newRow
argument_list|(
literal|"lo-surrogate"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xED\xB0\x80"
argument_list|)
expr_stmt|;
comment|// not even in pair:
name|QTest
operator|::
name|newRow
argument_list|(
literal|"surrogate-pair"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xED\xA0\x80\xED\xB0\x80"
argument_list|)
expr_stmt|;
comment|// Characters outside the Unicode range:
comment|// 0x110000:   00 0100   01 0000   00 0000   00 0000
comment|// encoding: xxxx:z100 xz01:0000 xz00:0000 xz00:0000
name|QTest
operator|::
name|newRow
argument_list|(
literal|"non-unicode-1"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xF4\x90\x80\x80"
argument_list|)
expr_stmt|;
comment|// 0x200000:             00 1000   00 0000   00 0000   00 0000
comment|// encoding: xxxx:xz00 xz00:1000 xz00:0000 xz00:0000 xz00:0000
name|QTest
operator|::
name|newRow
argument_list|(
literal|"non-unicode-2"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xF8\x88\x80\x80\x80"
argument_list|)
expr_stmt|;
comment|// 0x04000000:              0100   00 0000   00 0000   00 0000   00 0000
comment|// encoding: xxxx:xxz0 xz00:0100 xz00:0000 xz00:0000 xz00:0001 xz00:0001
name|QTest
operator|::
name|newRow
argument_list|(
literal|"non-unicode-3"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xFC\x84\x80\x80\x80\x80"
argument_list|)
expr_stmt|;
comment|// 0x7fffffff:       1   11 1111   11 1111   11 1111   11 1111   11 1111
comment|// encoding: xxxx:xxz0 xz00:0100 xz00:0000 xz00:0000 xz00:0001 xz00:0001
name|QTest
operator|::
name|newRow
argument_list|(
literal|"non-unicode-4"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xFD\xBF\xBF\xBF\xBF\xBF"
argument_list|)
expr_stmt|;
comment|// As seen above, 0xFE and 0xFF never appear:
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fe"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xFE"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fe-bis"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xFE\xBF\xBF\xBF\xBF\xBF\xBF"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"ff"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xFF"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"ff-bis"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xFF\xBF\xBF\xBF\xBF\xBF\xBF\xBF"
argument_list|)
expr_stmt|;
comment|// some combinations in UTF-8 are invalid even though they have the proper bits set
comment|// these are known as overlong sequences
comment|// "A": U+0041:                                               01   00 0001
comment|// overlong 2:                                         xxz0:0001 xz00:0001
name|QTest
operator|::
name|newRow
argument_list|(
literal|"overlong-1-2"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xC1\x81"
argument_list|)
expr_stmt|;
comment|// overlong 3:                               xxxz:0000 xz00:0001 xz00:0001
name|QTest
operator|::
name|newRow
argument_list|(
literal|"overlong-1-3"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xE0\x81\x81"
argument_list|)
expr_stmt|;
comment|// overlong 4:                     xxxx:z000 xz00:0000 xz00:0001 xz00:0001
name|QTest
operator|::
name|newRow
argument_list|(
literal|"overlong-1-4"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xF0\x80\x81\x81"
argument_list|)
expr_stmt|;
comment|// overlong 5:           xxxx:xz00 xz00:0000 xz00:0000 xz00:0001 xz00:0001
name|QTest
operator|::
name|newRow
argument_list|(
literal|"overlong-1-5"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xF8\x80\x80\x81\x81"
argument_list|)
expr_stmt|;
comment|// overlong 6: xxxx:xxz0 xz00:0000 xz00:0000 xz00:0000 xz00:0001 xz00:0001
name|QTest
operator|::
name|newRow
argument_list|(
literal|"overlong-1-6"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xFC\x80\x80\x80\x81\x81"
argument_list|)
expr_stmt|;
comment|// NBSP: U+00A0:                                             10    00 0000
comment|// proper encoding:                                    xxz0:0010 xz00:0000
comment|// overlong 3:                               xxxz:0000 xz00:0010 xz00:0000
name|QTest
operator|::
name|newRow
argument_list|(
literal|"overlong-2-3"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xC0\x82\x80"
argument_list|)
expr_stmt|;
comment|// overlong 4:                     xxxx:z000 xz00:0000 xz00:0010 xz00:0000
name|QTest
operator|::
name|newRow
argument_list|(
literal|"overlong-2-4"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xF0\x80\x82\x80"
argument_list|)
expr_stmt|;
comment|// overlong 5:           xxxx:xz00 xz00:0000 xz00:0000 xz00:0010 xz00:0000
name|QTest
operator|::
name|newRow
argument_list|(
literal|"overlong-2-5"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xF8\x80\x80\x82\x80"
argument_list|)
expr_stmt|;
comment|// overlong 6: xxxx:xxz0 xz00:0000 xz00:0000 xz00:0000 xz00:0010 xz00:0000
name|QTest
operator|::
name|newRow
argument_list|(
literal|"overlong-2-6"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xFC\x80\x80\x80\x82\x80"
argument_list|)
expr_stmt|;
comment|// U+0800:                                               10 0000   00 0000
comment|// proper encoding:                          xxxz:0000 xz10:0000 xz00:0000
comment|// overlong 4:                     xxxx:z000 xz00:0000 xz10:0000 xz00:0000
name|QTest
operator|::
name|newRow
argument_list|(
literal|"overlong-3-4"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xF0\x80\xA0\x80"
argument_list|)
expr_stmt|;
comment|// overlong 5:           xxxx:xz00 xz00:0000 xz00:0000 xz10:0000 xz00:0000
name|QTest
operator|::
name|newRow
argument_list|(
literal|"overlong-3-5"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xF8\x80\x80\xA0\x80"
argument_list|)
expr_stmt|;
comment|// overlong 6: xxxx:xxz0 xz00:0000 xz00:0000 xz00:0000 xz10:0000 xz00:0000
name|QTest
operator|::
name|newRow
argument_list|(
literal|"overlong-3-6"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xFC\x80\x80\x80\xA0\x80"
argument_list|)
expr_stmt|;
comment|// U+010000:                                   00 0100   00 0000   00 0000
comment|// proper encoding:                xxxx:z000 xz00:0100 xz00:0000 xz00:0000
comment|// overlong 5:           xxxx:xz00 xz00:0000 xz00:0100 xz00:0000 xz00:0000
name|QTest
operator|::
name|newRow
argument_list|(
literal|"overlong-4-5"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xF8\x80\x84\x80\x80"
argument_list|)
expr_stmt|;
comment|// overlong 6: xxxx:xxz0 xz00:0000 xz00:0000 xz00:0100 xz00:0000 xz00:0000
name|QTest
operator|::
name|newRow
argument_list|(
literal|"overlong-4-6"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xFC\x80\x80\x84\x80\x80"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loadNonCharactersRows
name|void
name|loadNonCharactersRows
parameter_list|()
block|{
comment|// Unicode has a couple of "non-characters" that one can use internally,
comment|// but are not allowed to be used for text interchange.
comment|//
comment|// Those are the last two entries each Unicode Plane (U+FFFE, U+FFFF,
comment|// U+1FFFE, U+1FFFF, etc.) as well as the entries between U+FDD0 and
comment|// U+FDEF (inclusive)
comment|// U+FDD0 through U+FDEF
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|16
condition|;
operator|++
name|i
control|)
block|{
name|char
name|utf8
index|[]
init|=
block|{
name|char
argument_list|(
literal|0357
argument_list|)
block|,
name|char
argument_list|(
literal|0267
argument_list|)
block|,
name|char
argument_list|(
literal|0220
operator|+
name|i
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
name|QString
name|utf16
init|=
name|QChar
argument_list|(
literal|0xfdd0
operator|+
name|i
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|qPrintable
argument_list|(
name|QString
operator|::
name|number
argument_list|(
literal|0xfdd0
operator|+
name|i
argument_list|,
literal|16
argument_list|)
argument_list|)
argument_list|)
operator|<<
name|QByteArray
argument_list|(
name|utf8
argument_list|)
operator|<<
name|utf16
expr_stmt|;
block|}
comment|// the last two in Planes 1 through 16
for|for
control|(
name|uint
name|plane
init|=
literal|1
init|;
name|plane
operator|<=
literal|16
condition|;
operator|++
name|plane
control|)
block|{
for|for
control|(
name|uint
name|lower
init|=
literal|0xfffe
init|;
name|lower
operator|<
literal|0x10000
condition|;
operator|++
name|lower
control|)
block|{
name|uint
name|ucs4
init|=
operator|(
name|plane
operator|<<
literal|16
operator|)
operator||
name|lower
decl_stmt|;
name|char
name|utf8
index|[]
init|=
block|{
name|char
argument_list|(
literal|0xf0
operator||
name|uchar
argument_list|(
name|ucs4
operator|>>
literal|18
argument_list|)
argument_list|)
block|,
name|char
argument_list|(
literal|0x80
operator||
operator|(
name|uchar
argument_list|(
name|ucs4
operator|>>
literal|12
argument_list|)
operator|&
literal|0x3f
operator|)
argument_list|)
block|,
name|char
argument_list|(
literal|0x80
operator||
operator|(
name|uchar
argument_list|(
name|ucs4
operator|>>
literal|6
argument_list|)
operator|&
literal|0x3f
operator|)
argument_list|)
block|,
name|char
argument_list|(
literal|0x80
operator||
operator|(
name|uchar
argument_list|(
name|ucs4
argument_list|)
operator|&
literal|0x3f
operator|)
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
name|ushort
name|utf16
index|[]
init|=
block|{
name|QChar
operator|::
name|highSurrogate
argument_list|(
name|ucs4
argument_list|)
block|,
name|QChar
operator|::
name|lowSurrogate
argument_list|(
name|ucs4
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|qPrintable
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|ucs4
argument_list|,
literal|16
argument_list|)
argument_list|)
argument_list|)
operator|<<
name|QByteArray
argument_list|(
name|utf8
argument_list|)
operator|<<
name|QString
operator|::
name|fromUtf16
argument_list|(
name|utf16
argument_list|)
expr_stmt|;
block|}
block|}
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fffe"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xEF\xBF\xBE"
argument_list|)
operator|<<
name|QString
argument_list|(
name|QChar
argument_list|(
literal|0xfffe
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"ffff"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"\xEF\xBF\xBF"
argument_list|)
operator|<<
name|QString
argument_list|(
name|QChar
argument_list|(
literal|0xffff
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
