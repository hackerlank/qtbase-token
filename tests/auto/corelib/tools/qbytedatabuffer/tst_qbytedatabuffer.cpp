begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Hewlett-Packard Development Company, L.P. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QTest>
end_include
begin_include
include|#
directive|include
file|<private/qbytedata_p.h>
end_include
begin_comment
comment|// for QIODEVICE_BUFFERSIZE macro (== 16384):
end_comment
begin_include
include|#
directive|include
file|<private/qiodevice_p.h>
end_include
begin_class
DECL|class|tst_QByteDataBuffer
class|class
name|tst_QByteDataBuffer
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|Q_SLOTS
private|:
name|void
name|canReadLine
parameter_list|()
function_decl|;
name|void
name|positionHandling
parameter_list|()
function_decl|;
name|void
name|appendBuffer
parameter_list|()
function_decl|;
name|void
name|readCompleteBuffer_data
parameter_list|()
function_decl|;
name|void
name|readCompleteBuffer
parameter_list|()
function_decl|;
name|void
name|readPartialBuffer_data
parameter_list|()
function_decl|;
name|void
name|readPartialBuffer
parameter_list|()
function_decl|;
private|private:
name|void
name|readBuffer
parameter_list|(
name|int
name|size
parameter_list|,
name|int
name|readSize
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|canReadLine
name|void
name|tst_QByteDataBuffer
operator|::
name|canReadLine
parameter_list|()
block|{
name|QByteDataBuffer
name|buf
decl_stmt|;
name|buf
operator|.
name|append
argument_list|(
name|QByteArray
argument_list|(
literal|"a"
argument_list|)
argument_list|)
expr_stmt|;
name|buf
operator|.
name|append
argument_list|(
name|QByteArray
argument_list|(
literal|"\nb"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|buf
operator|.
name|canReadLine
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|buf
operator|.
name|getChar
argument_list|()
operator|==
literal|'a'
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|buf
operator|.
name|canReadLine
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|buf
operator|.
name|getChar
argument_list|()
operator|==
literal|'\n'
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|buf
operator|.
name|canReadLine
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|positionHandling
name|void
name|tst_QByteDataBuffer
operator|::
name|positionHandling
parameter_list|()
block|{
name|QByteDataBuffer
name|buf
decl_stmt|;
name|buf
operator|.
name|append
argument_list|(
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
argument_list|)
expr_stmt|;
name|buf
operator|.
name|append
argument_list|(
name|QByteArray
argument_list|(
literal|"def"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buf
operator|.
name|byteAmount
argument_list|()
argument_list|,
operator|(
name|qlonglong
operator|)
literal|6
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buf
operator|.
name|sizeNextBlock
argument_list|()
argument_list|,
operator|(
name|qlonglong
operator|)
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buf
operator|.
name|getChar
argument_list|()
argument_list|,
literal|'a'
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buf
operator|.
name|byteAmount
argument_list|()
argument_list|,
operator|(
name|qlonglong
operator|)
literal|5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buf
operator|.
name|sizeNextBlock
argument_list|()
argument_list|,
operator|(
name|qlonglong
operator|)
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|strcmp
argument_list|(
name|buf
index|[
literal|0
index|]
operator|.
name|constData
argument_list|()
argument_list|,
literal|"bc"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buf
operator|.
name|getChar
argument_list|()
argument_list|,
literal|'b'
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buf
operator|.
name|byteAmount
argument_list|()
argument_list|,
operator|(
name|qlonglong
operator|)
literal|4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buf
operator|.
name|sizeNextBlock
argument_list|()
argument_list|,
operator|(
name|qlonglong
operator|)
literal|1
argument_list|)
expr_stmt|;
name|QByteArray
name|tmp
argument_list|(
literal|"ab"
argument_list|)
decl_stmt|;
name|buf
operator|.
name|prepend
argument_list|(
name|tmp
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buf
operator|.
name|byteAmount
argument_list|()
argument_list|,
operator|(
name|qlonglong
operator|)
literal|6
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|strcmp
argument_list|(
name|buf
operator|.
name|readAll
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
literal|"abcdef"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buf
operator|.
name|byteAmount
argument_list|()
argument_list|,
operator|(
name|qlonglong
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QByteDataBuffer
name|buf2
decl_stmt|;
name|buf2
operator|.
name|append
argument_list|(
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
argument_list|)
expr_stmt|;
name|buf2
operator|.
name|getChar
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buf2
operator|.
name|read
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
literal|"bc"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|appendBuffer
name|void
name|tst_QByteDataBuffer
operator|::
name|appendBuffer
parameter_list|()
block|{
name|QByteDataBuffer
name|buf
decl_stmt|;
name|buf
operator|.
name|append
argument_list|(
name|QByteArray
argument_list|(
literal|"\1\2\3"
argument_list|)
argument_list|)
expr_stmt|;
name|buf
operator|.
name|getChar
argument_list|()
expr_stmt|;
name|QByteDataBuffer
name|tmp
decl_stmt|;
name|tmp
operator|.
name|append
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tmp
operator|.
name|readAll
argument_list|()
argument_list|,
name|buf
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|makeByteArray
specifier|static
name|QByteArray
name|makeByteArray
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|QByteArray
name|array
decl_stmt|;
name|array
operator|.
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|char
modifier|*
name|data
init|=
name|array
operator|.
name|data
argument_list|()
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
name|size
condition|;
operator|++
name|i
control|)
name|data
index|[
name|i
index|]
operator|=
name|i
operator|%
literal|256
expr_stmt|;
return|return
name|array
return|;
block|}
end_function
begin_function
DECL|function|readBuffer
name|void
name|tst_QByteDataBuffer
operator|::
name|readBuffer
parameter_list|(
name|int
name|size
parameter_list|,
name|int
name|readSize
parameter_list|)
block|{
name|QByteArray
name|data
init|=
name|makeByteArray
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|QByteDataBuffer
name|buf
decl_stmt|;
name|buf
operator|.
name|append
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|QByteArray
name|tmp
decl_stmt|;
name|tmp
operator|.
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|QBENCHMARK_ONCE
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
operator|(
name|size
operator|-
literal|1
operator|)
operator|/
name|readSize
operator|+
literal|1
condition|;
operator|++
name|i
control|)
name|buf
operator|.
name|read
argument_list|(
name|tmp
operator|.
name|data
argument_list|()
operator|+
name|i
operator|*
name|readSize
argument_list|,
name|readSize
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|data
operator|.
name|size
argument_list|()
argument_list|,
name|tmp
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readCompleteBuffer_data
name|void
name|tst_QByteDataBuffer
operator|::
name|readCompleteBuffer_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10B"
argument_list|)
operator|<<
operator|(
name|int
operator|)
literal|10
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1MB"
argument_list|)
operator|<<
operator|(
name|int
operator|)
literal|1e6
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5MB"
argument_list|)
operator|<<
operator|(
name|int
operator|)
literal|5e6
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10MB"
argument_list|)
operator|<<
operator|(
name|int
operator|)
literal|10e6
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readCompleteBuffer
name|void
name|tst_QByteDataBuffer
operator|::
name|readCompleteBuffer
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|readBuffer
argument_list|(
name|size
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readPartialBuffer_data
name|void
name|tst_QByteDataBuffer
operator|::
name|readPartialBuffer_data
parameter_list|()
block|{
name|readCompleteBuffer_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readPartialBuffer
name|void
name|tst_QByteDataBuffer
operator|::
name|readPartialBuffer
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size
argument_list|)
expr_stmt|;
comment|// QIODevice::readAll() reads in QIODEVICE_BUFFERSIZE size
comment|// increments.
name|readBuffer
argument_list|(
name|size
argument_list|,
name|QIODEVICE_BUFFERSIZE
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QByteDataBuffer
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qbytedatabuffer.moc"
end_include
end_unit
