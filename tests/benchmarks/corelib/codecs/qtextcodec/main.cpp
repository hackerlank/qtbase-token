begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QTextCodec>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
end_ifdef
begin_comment
comment|// In Symbian OS test data is located in applications private dir
end_comment
begin_comment
comment|// Application private dir is default serach path for files, so SRCDIR can be set to empty
end_comment
begin_define
DECL|macro|SRCDIR
define|#
directive|define
name|SRCDIR
value|""
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QList<QByteArray>
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QTextCodec *
argument_list|)
end_macro
begin_class
DECL|class|tst_QTextCodec
class|class
name|tst_QTextCodec
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|codecForName
parameter_list|()
specifier|const
function_decl|;
name|void
name|codecForName_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|codecForMib
parameter_list|()
specifier|const
function_decl|;
name|void
name|fromUnicode_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|fromUnicode
parameter_list|()
specifier|const
function_decl|;
name|void
name|toUnicode_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|toUnicode
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|codecForName
name|void
name|tst_QTextCodec
operator|::
name|codecForName
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|QList
argument_list|<
name|QByteArray
argument_list|>
argument_list|,
name|codecs
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
foreach|foreach
control|(
specifier|const
name|QByteArray
modifier|&
name|c
decl|,
name|codecs
control|)
block|{
name|QVERIFY
argument_list|(
name|QTextCodec
operator|::
name|codecForName
argument_list|(
name|c
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTextCodec
operator|::
name|codecForName
argument_list|(
name|c
operator|+
literal|"-"
argument_list|)
argument_list|)
expr_stmt|;
block|}
foreach|foreach
control|(
specifier|const
name|QByteArray
modifier|&
name|c
decl|,
name|codecs
control|)
block|{
name|QVERIFY
argument_list|(
name|QTextCodec
operator|::
name|codecForName
argument_list|(
name|c
operator|+
literal|"+"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTextCodec
operator|::
name|codecForName
argument_list|(
name|c
operator|+
literal|"*"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|codecForName_data
name|void
name|tst_QTextCodec
operator|::
name|codecForName_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QList
argument_list|<
name|QByteArray
argument_list|>
argument_list|>
argument_list|(
literal|"codecs"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"all"
argument_list|)
operator|<<
name|QTextCodec
operator|::
name|availableCodecs
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"many utf-8"
argument_list|)
operator|<<
operator|(
name|QList
argument_list|<
name|QByteArray
argument_list|>
argument_list|()
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|<<
literal|"utf-8"
operator|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|codecForMib
name|void
name|tst_QTextCodec
operator|::
name|codecForMib
parameter_list|()
specifier|const
block|{
name|QBENCHMARK
block|{
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
literal|106
argument_list|)
expr_stmt|;
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
literal|111
argument_list|)
expr_stmt|;
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
literal|106
argument_list|)
expr_stmt|;
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
literal|2254
argument_list|)
expr_stmt|;
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
literal|2255
argument_list|)
expr_stmt|;
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
literal|2256
argument_list|)
expr_stmt|;
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
literal|2257
argument_list|)
expr_stmt|;
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
literal|2258
argument_list|)
expr_stmt|;
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
literal|111
argument_list|)
expr_stmt|;
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
literal|2250
argument_list|)
expr_stmt|;
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
literal|2251
argument_list|)
expr_stmt|;
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
literal|2252
argument_list|)
expr_stmt|;
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
literal|106
argument_list|)
expr_stmt|;
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
literal|106
argument_list|)
expr_stmt|;
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
literal|106
argument_list|)
expr_stmt|;
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
literal|106
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fromUnicode_data
name|void
name|tst_QTextCodec
operator|::
name|fromUnicode_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QTextCodec
operator|*
argument_list|>
argument_list|(
literal|"codec"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"utf-8"
argument_list|)
operator|<<
name|QTextCodec
operator|::
name|codecForName
argument_list|(
literal|"utf-8"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"latin 1"
argument_list|)
operator|<<
name|QTextCodec
operator|::
name|codecForName
argument_list|(
literal|"latin 1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"utf-16"
argument_list|)
operator|<<
name|QTextCodec
operator|::
name|codecForName
argument_list|(
literal|"utf16"
argument_list|)
expr_stmt|;
empty_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"utf-32"
argument_list|)
operator|<<
name|QTextCodec
operator|::
name|codecForName
argument_list|(
literal|"utf32"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"latin15"
argument_list|)
operator|<<
name|QTextCodec
operator|::
name|codecForName
argument_list|(
literal|"iso-8859-15"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"eucKr"
argument_list|)
operator|<<
name|QTextCodec
operator|::
name|codecForName
argument_list|(
literal|"eucKr"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fromUnicode
name|void
name|tst_QTextCodec
operator|::
name|fromUnicode
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|QTextCodec
operator|*
argument_list|,
name|codec
argument_list|)
expr_stmt|;
name|QFile
name|file
argument_list|(
name|SRCDIR
literal|"utf-8.txt"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qFatal
argument_list|(
literal|"Cannot open input file"
argument_list|)
expr_stmt|;
return|return;
block|}
name|QByteArray
name|data
init|=
name|file
operator|.
name|readAll
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|d
init|=
name|data
operator|.
name|constData
argument_list|()
decl_stmt|;
name|int
name|size
init|=
name|data
operator|.
name|size
argument_list|()
decl_stmt|;
name|QString
name|s
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|d
argument_list|,
name|size
argument_list|)
decl_stmt|;
name|s
operator|=
name|s
operator|+
name|s
operator|+
name|s
expr_stmt|;
name|s
operator|=
name|s
operator|+
name|s
operator|+
name|s
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
name|codec
operator|->
name|fromUnicode
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|toUnicode_data
name|void
name|tst_QTextCodec
operator|::
name|toUnicode_data
parameter_list|()
specifier|const
block|{
name|fromUnicode_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toUnicode
name|void
name|tst_QTextCodec
operator|::
name|toUnicode
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|QTextCodec
operator|*
argument_list|,
name|codec
argument_list|)
expr_stmt|;
name|QFile
name|file
argument_list|(
name|SRCDIR
literal|"utf-8.txt"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QByteArray
name|data
init|=
name|file
operator|.
name|readAll
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|d
init|=
name|data
operator|.
name|constData
argument_list|()
decl_stmt|;
name|int
name|size
init|=
name|data
operator|.
name|size
argument_list|()
decl_stmt|;
name|QString
name|s
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|d
argument_list|,
name|size
argument_list|)
decl_stmt|;
name|s
operator|=
name|s
operator|+
name|s
operator|+
name|s
expr_stmt|;
name|s
operator|=
name|s
operator|+
name|s
operator|+
name|s
expr_stmt|;
name|QByteArray
name|orig
init|=
name|codec
operator|->
name|fromUnicode
argument_list|(
name|s
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
name|codec
operator|->
name|toUnicode
argument_list|(
name|orig
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QTextCodec
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
