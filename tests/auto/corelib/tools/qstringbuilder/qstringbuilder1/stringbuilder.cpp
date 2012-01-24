begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_define
DECL|macro|LITERAL
define|#
directive|define
name|LITERAL
value|"some literal"
end_define
begin_define
DECL|macro|LITERAL_LEN
define|#
directive|define
name|LITERAL_LEN
value|(sizeof(LITERAL)-1)
end_define
begin_define
DECL|macro|LITERAL_EXTRA
define|#
directive|define
name|LITERAL_EXTRA
value|"some literal" "EXTRA"
end_define
begin_comment
comment|// "some literal", but replacing all vocals by their umlauted UTF-8 string :)
end_comment
begin_define
DECL|macro|UTF8_LITERAL
define|#
directive|define
name|UTF8_LITERAL
value|"s\xc3\xb6m\xc3\xab l\xc3\xaft\xc3\xabr\xc3\xa4l"
end_define
begin_define
DECL|macro|UTF8_LITERAL_LEN
define|#
directive|define
name|UTF8_LITERAL_LEN
value|(sizeof(UTF8_LITERAL)-1)
end_define
begin_define
DECL|macro|UTF8_LITERAL_EXTRA
define|#
directive|define
name|UTF8_LITERAL_EXTRA
value|"s\xc3\xb6m\xc3\xab l\xc3\xaft\xc3\xabr\xc3\xa4l" "EXTRA"
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_UNICODE_STRINGS
end_ifdef
begin_comment
comment|// "some literal", but replacing all vocals by their umlauted UTF-8 string :)
end_comment
begin_define
DECL|macro|UNICODE_LITERAL
define|#
directive|define
name|UNICODE_LITERAL
value|u"s\u00f6m\u00eb l\u00eft\u00ebr\u00e4l"
end_define
begin_define
DECL|macro|UNICODE_LITERAL_LEN
define|#
directive|define
name|UNICODE_LITERAL_LEN
value|((sizeof(UNICODE_LITERAL) - 1) / 2)
end_define
begin_define
DECL|macro|UNICODE_LITERAL_EXTRA
define|#
directive|define
name|UNICODE_LITERAL_EXTRA
value|u"s\u00f6m\u00eb l\u00eft\u00ebr\u00e4l" "EXTRA"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//fix for gcc4.0: if the operator+ does not exist without QT_USE_FAST_OPERATOR_PLUS
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_USE_FAST_CONCATENATION
end_ifndef
begin_define
DECL|macro|Q
define|#
directive|define
name|Q
value|%
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q
define|#
directive|define
name|Q
value|P
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|runScenario
name|void
name|runScenario
parameter_list|()
block|{
comment|// set codec for C strings to 0, enforcing Latin1
name|QTextCodec
operator|::
name|setCodecForCStrings
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QTextCodec
operator|::
name|codecForCStrings
argument_list|()
argument_list|)
expr_stmt|;
name|QLatin1Literal
name|l1literal
argument_list|(
name|LITERAL
argument_list|)
decl_stmt|;
name|QLatin1String
name|l1string
argument_list|(
name|LITERAL
argument_list|)
decl_stmt|;
name|QString
name|string
argument_list|(
name|l1string
argument_list|)
decl_stmt|;
name|QStringRef
name|stringref
argument_list|(
operator|&
name|string
argument_list|,
literal|2
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QLatin1Char
name|achar
argument_list|(
literal|'c'
argument_list|)
decl_stmt|;
name|QString
name|r2
argument_list|(
name|QLatin1String
argument_list|(
argument|LITERAL LITERAL
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|r3
init|=
name|QString
operator|::
name|fromUtf8
operator|(
name|UTF8_LITERAL
name|UTF8_LITERAL
operator|)
decl_stmt|;
name|QString
name|r
decl_stmt|;
name|r
operator|=
name|l1literal
name|Q
name|l1literal
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|r
operator|=
name|string
name|P
name|string
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|r
operator|=
name|stringref
name|Q
name|stringref
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|QString
argument_list|(
name|stringref
operator|.
name|toString
argument_list|()
operator|+
name|stringref
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|r
operator|=
name|string
name|Q
name|l1literal
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|r
operator|=
name|string
name|P
name|l1string
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|r
operator|=
name|string
name|Q
name|QStringLiteral
argument_list|(
name|LITERAL
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|r
operator|=
name|QStringLiteral
argument_list|(
argument|LITERAL
argument_list|)
name|Q
name|string
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|r
operator|=
name|l1string
name|Q
name|QStringLiteral
argument_list|(
name|LITERAL
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|r
operator|=
name|string
operator|+
name|achar
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|QString
argument_list|(
argument|string P achar
argument_list|)
argument_list|)
expr_stmt|;
name|r
operator|=
name|achar
operator|+
name|string
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|QString
argument_list|(
argument|achar P string
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_UNICODE_STRINGS
name|r
operator|=
name|QStringLiteral
argument_list|(
name|UNICODE_LITERAL
argument_list|)
expr_stmt|;
name|r
operator|=
name|r
name|Q
name|QStringLiteral
argument_list|(
name|UNICODE_LITERAL
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r3
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_CAST_FROM_ASCII
name|r
operator|=
name|string
name|P
name|LITERAL
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|r
operator|=
name|LITERAL
name|P
name|string
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|QByteArray
name|ba
init|=
name|QByteArray
argument_list|(
name|LITERAL
argument_list|)
decl_stmt|;
name|r
operator|=
name|ba
name|P
name|string
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|r
operator|=
name|string
name|P
name|ba
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|r
operator|=
name|string
name|P
name|QByteArrayLiteral
argument_list|(
name|LITERAL
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|r
operator|=
name|QByteArrayLiteral
argument_list|(
argument|LITERAL
argument_list|)
name|P
name|string
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
specifier|static
specifier|const
name|char
name|badata
index|[]
init|=
name|LITERAL_EXTRA
decl_stmt|;
name|ba
operator|=
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|badata
argument_list|,
name|LITERAL_LEN
argument_list|)
expr_stmt|;
name|r
operator|=
name|ba
name|P
name|string
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|r
operator|=
name|string
name|P
name|ba
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
comment|// now test with codec for C strings set
name|QTextCodec
operator|::
name|setCodecForCStrings
argument_list|(
name|QTextCodec
operator|::
name|codecForName
argument_list|(
literal|"UTF-8"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTextCodec
operator|::
name|codecForCStrings
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QTextCodec
operator|::
name|codecForCStrings
argument_list|()
operator|->
name|name
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
literal|"UTF-8"
argument_list|)
argument_list|)
expr_stmt|;
name|string
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|UTF8_LITERAL
argument_list|)
expr_stmt|;
name|ba
operator|=
name|UTF8_LITERAL
expr_stmt|;
name|r
operator|=
name|string
name|P
name|UTF8_LITERAL
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
operator|.
name|size
argument_list|()
argument_list|,
name|r3
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r3
argument_list|)
expr_stmt|;
name|r
operator|=
name|UTF8_LITERAL
name|P
name|string
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r3
argument_list|)
expr_stmt|;
name|r
operator|=
name|ba
name|P
name|string
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r3
argument_list|)
expr_stmt|;
name|r
operator|=
name|string
name|P
name|ba
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r3
argument_list|)
expr_stmt|;
name|ba
operator|=
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|UTF8_LITERAL_EXTRA
argument_list|,
name|UTF8_LITERAL_LEN
argument_list|)
expr_stmt|;
name|r
operator|=
name|ba
name|P
name|string
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r3
argument_list|)
expr_stmt|;
name|r
operator|=
name|string
name|P
name|ba
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r3
argument_list|)
expr_stmt|;
name|ba
operator|=
name|QByteArray
argument_list|()
expr_stmt|;
comment|// empty
name|r
operator|=
name|ba
name|P
name|string
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|string
argument_list|)
expr_stmt|;
name|r
operator|=
name|string
name|P
name|ba
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|string
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|zero
init|=
literal|0
decl_stmt|;
name|r
operator|=
name|string
name|P
name|zero
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|string
argument_list|)
expr_stmt|;
name|r
operator|=
name|zero
name|P
name|string
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|string
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|string
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|LITERAL
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QByteArray
argument_list|(
name|qPrintable
argument_list|(
argument|string P string
argument_list|)
argument_list|)
argument_list|,
name|QByteArray
argument_list|(
name|string
operator|.
name|toLatin1
argument_list|()
operator|+
name|string
operator|.
name|toLatin1
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//QByteArray
block|{
name|QByteArray
name|ba
init|=
name|LITERAL
decl_stmt|;
name|QByteArray
name|superba
init|=
name|ba
name|P
name|ba
name|P
name|LITERAL
decl_stmt|;
name|QCOMPARE
argument_list|(
name|superba
argument_list|,
name|QByteArray
argument_list|(
argument|LITERAL LITERAL LITERAL
argument_list|)
argument_list|)
expr_stmt|;
name|ba
operator|=
name|QByteArrayLiteral
argument_list|(
name|LITERAL
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ba
argument_list|,
name|QByteArray
argument_list|(
name|LITERAL
argument_list|)
argument_list|)
expr_stmt|;
name|superba
operator|=
name|ba
name|P
name|QByteArrayLiteral
argument_list|(
argument|LITERAL
argument_list|)
name|P
name|LITERAL
expr_stmt|;
name|QCOMPARE
argument_list|(
name|superba
argument_list|,
name|QByteArray
argument_list|(
argument|LITERAL LITERAL LITERAL
argument_list|)
argument_list|)
expr_stmt|;
name|QByteArray
name|testWith0
init|=
name|ba
name|P
literal|"test\0with\0zero"
name|P
name|ba
decl_stmt|;
name|QCOMPARE
argument_list|(
name|testWith0
argument_list|,
name|QByteArray
argument_list|(
name|LITERAL
literal|"test"
name|LITERAL
argument_list|)
argument_list|)
expr_stmt|;
name|QByteArray
name|ba2
init|=
name|ba
name|P
literal|'\0'
operator|+
name|LITERAL
decl_stmt|;
name|QCOMPARE
argument_list|(
name|ba2
argument_list|,
name|QByteArray
argument_list|(
name|LITERAL
literal|"\0"
name|LITERAL
argument_list|,
name|ba
operator|.
name|size
argument_list|()
operator|*
literal|2
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|mmh
init|=
literal|"test\0foo"
decl_stmt|;
name|QCOMPARE
argument_list|(
name|QByteArray
argument_list|(
argument|ba P mmh P ba
argument_list|)
argument_list|,
name|testWith0
argument_list|)
expr_stmt|;
name|QByteArray
name|raw
init|=
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|UTF8_LITERAL_EXTRA
argument_list|,
name|UTF8_LITERAL_LEN
argument_list|)
decl_stmt|;
name|QByteArray
name|r
init|=
literal|"hello"
name|P
name|raw
decl_stmt|;
name|QByteArray
name|r2
init|=
literal|"hello"
name|UTF8_LITERAL
decl_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|r2
operator|=
name|QByteArray
argument_list|(
literal|"hello\0"
argument_list|)
name|P
name|UTF8_LITERAL
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|zero
init|=
literal|0
decl_stmt|;
name|r
operator|=
name|ba
name|P
name|zero
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|ba
argument_list|)
expr_stmt|;
name|r
operator|=
name|zero
name|P
name|ba
expr_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|ba
argument_list|)
expr_stmt|;
block|}
comment|//operator QString  +=
block|{
name|QString
name|str
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|UTF8_LITERAL
argument_list|)
decl_stmt|;
name|str
operator|+=
name|QLatin1String
argument_list|(
argument|LITERAL
argument_list|)
name|P
name|str
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
operator|::
name|fromUtf8
operator|(
name|UTF8_LITERAL
name|LITERAL
name|UTF8_LITERAL
operator|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CAST_FROM_ASCII
name|str
operator|=
operator|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|UTF8_LITERAL
argument_list|)
operator|+=
name|QLatin1String
argument_list|(
argument|LITERAL
argument_list|)
name|P
name|UTF8_LITERAL
operator|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
operator|::
name|fromUtf8
operator|(
name|UTF8_LITERAL
name|LITERAL
name|UTF8_LITERAL
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|//operator QByteArray  +=
block|{
name|QByteArray
name|ba
init|=
name|UTF8_LITERAL
decl_stmt|;
name|ba
operator|+=
name|QByteArray
argument_list|(
argument|LITERAL
argument_list|)
name|P
name|UTF8_LITERAL
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ba
argument_list|,
name|QByteArray
argument_list|(
argument|UTF8_LITERAL LITERAL UTF8_LITERAL
argument_list|)
argument_list|)
expr_stmt|;
name|ba
operator|+=
name|LITERAL
name|P
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|UTF8_LITERAL_EXTRA
argument_list|,
name|UTF8_LITERAL_LEN
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ba
argument_list|,
name|QByteArray
argument_list|(
argument|UTF8_LITERAL LITERAL UTF8_LITERAL LITERAL UTF8_LITERAL
argument_list|)
argument_list|)
expr_stmt|;
name|QByteArray
name|withZero
init|=
name|QByteArray
argument_list|(
name|LITERAL
literal|"\0"
name|LITERAL
argument_list|,
name|LITERAL_LEN
operator|*
literal|2
operator|+
literal|1
argument_list|)
decl_stmt|;
name|QByteArray
name|ba2
init|=
name|withZero
decl_stmt|;
name|ba2
operator|+=
name|ba2
name|P
name|withZero
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ba2
argument_list|,
name|QByteArray
argument_list|(
name|withZero
operator|+
name|withZero
operator|+
name|withZero
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CAST_TO_ASCII
name|ba
operator|=
name|UTF8_LITERAL
expr_stmt|;
name|ba2
operator|=
operator|(
name|ba
operator|+=
name|QLatin1String
argument_list|(
name|LITERAL
argument_list|)
operator|+
name|QString
operator|::
name|fromUtf8
argument_list|(
name|UTF8_LITERAL
argument_list|)
operator|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ba2
argument_list|,
name|ba
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ba
argument_list|,
name|QByteArray
argument_list|(
argument|UTF8_LITERAL LITERAL UTF8_LITERAL
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
end_unit
