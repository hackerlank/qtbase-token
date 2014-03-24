begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Intel Corporation ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_include
include|#
directive|include
file|<QCryptographicHash>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QtTest>
end_include
begin_include
include|#
directive|include
file|<time.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINCE
end_ifdef
begin_comment
comment|// no C89 time() on Windows CE:
end_comment
begin_comment
comment|// http://blogs.msdn.com/b/cenet/archive/2006/04/29/time-h-on-windows-ce.aspx
end_comment
begin_function
DECL|function|time
name|uint
name|time
parameter_list|(
name|void
modifier|*
parameter_list|)
block|{
return|return
name|uint
argument_list|(
operator|-
literal|1
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_bench_QCryptographicHash
class|class
name|tst_bench_QCryptographicHash
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
DECL|member|blockOfData
name|QByteArray
name|blockOfData
decl_stmt|;
public|public:
name|tst_bench_QCryptographicHash
parameter_list|()
constructor_decl|;
private|private
name|Q_SLOTS
private|:
name|void
name|hash_data
parameter_list|()
function_decl|;
name|void
name|hash
parameter_list|()
function_decl|;
DECL|function|addData_data
name|void
name|addData_data
parameter_list|()
block|{
name|hash_data
argument_list|()
expr_stmt|;
block|}
name|void
name|addData
parameter_list|()
function_decl|;
DECL|function|addDataChunked_data
name|void
name|addDataChunked_data
parameter_list|()
block|{
name|hash_data
argument_list|()
expr_stmt|;
block|}
name|void
name|addDataChunked
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|MaxCryptoAlgorithm
specifier|const
name|int
name|MaxCryptoAlgorithm
init|=
name|QCryptographicHash
operator|::
name|Sha3_512
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|MaxBlockSize
specifier|const
name|int
name|MaxBlockSize
init|=
literal|65536
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|algoname
specifier|const
name|char
modifier|*
name|algoname
parameter_list|(
name|int
name|i
parameter_list|)
block|{
switch|switch
condition|(
name|QCryptographicHash
operator|::
name|Algorithm
argument_list|(
name|i
argument_list|)
condition|)
block|{
case|case
name|QCryptographicHash
operator|::
name|Md4
case|:
return|return
literal|"md4-"
return|;
case|case
name|QCryptographicHash
operator|::
name|Md5
case|:
return|return
literal|"md5-"
return|;
case|case
name|QCryptographicHash
operator|::
name|Sha1
case|:
return|return
literal|"sha1-"
return|;
case|case
name|QCryptographicHash
operator|::
name|Sha224
case|:
return|return
literal|"sha2_224-"
return|;
case|case
name|QCryptographicHash
operator|::
name|Sha256
case|:
return|return
literal|"sha2_256-"
return|;
case|case
name|QCryptographicHash
operator|::
name|Sha384
case|:
return|return
literal|"sha2_384-"
return|;
case|case
name|QCryptographicHash
operator|::
name|Sha512
case|:
return|return
literal|"sha2_512-"
return|;
case|case
name|QCryptographicHash
operator|::
name|Sha3_224
case|:
return|return
literal|"sha3_224-"
return|;
case|case
name|QCryptographicHash
operator|::
name|Sha3_256
case|:
return|return
literal|"sha3_256-"
return|;
case|case
name|QCryptographicHash
operator|::
name|Sha3_384
case|:
return|return
literal|"sha3_384-"
return|;
case|case
name|QCryptographicHash
operator|::
name|Sha3_512
case|:
return|return
literal|"sha3_512-"
return|;
block|}
name|Q_UNREACHABLE
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_constructor
DECL|function|tst_bench_QCryptographicHash
name|tst_bench_QCryptographicHash
operator|::
name|tst_bench_QCryptographicHash
parameter_list|()
member_init_list|:
name|blockOfData
argument_list|(
name|MaxBlockSize
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_UNIX
name|QFile
name|urandom
argument_list|(
literal|"/dev/urandom"
argument_list|)
decl_stmt|;
if|if
condition|(
name|urandom
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Unbuffered
argument_list|)
condition|)
block|{
name|QCOMPARE
argument_list|(
name|urandom
operator|.
name|read
argument_list|(
name|blockOfData
operator|.
name|data
argument_list|()
argument_list|,
name|blockOfData
operator|.
name|size
argument_list|()
argument_list|)
argument_list|,
name|qint64
argument_list|(
name|MaxBlockSize
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
name|qsrand
argument_list|(
name|time
argument_list|(
name|NULL
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|MaxBlockSize
condition|;
operator|++
name|i
control|)
name|blockOfData
index|[
name|i
index|]
operator|=
name|qrand
argument_list|()
expr_stmt|;
block|}
block|}
end_constructor
begin_function
DECL|function|hash_data
name|void
name|tst_bench_QCryptographicHash
operator|::
name|hash_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"algorithm"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"data"
argument_list|)
expr_stmt|;
specifier|static
specifier|const
name|int
name|datasizes
index|[]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|64
block|,
literal|65
block|,
literal|512
block|,
literal|4095
block|,
literal|4096
block|,
literal|4097
block|,
literal|65536
block|}
decl_stmt|;
for|for
control|(
name|uint
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|datasizes
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|datasizes
index|[
literal|0
index|]
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
name|Q_ASSERT
argument_list|(
name|datasizes
index|[
name|i
index|]
operator|<
name|MaxBlockSize
argument_list|)
expr_stmt|;
name|QByteArray
name|data
init|=
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|blockOfData
operator|.
name|constData
argument_list|()
argument_list|,
name|datasizes
index|[
name|i
index|]
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|algo
init|=
name|QCryptographicHash
operator|::
name|Md4
init|;
name|algo
operator|<=
name|MaxCryptoAlgorithm
condition|;
operator|++
name|algo
control|)
name|QTest
operator|::
name|newRow
argument_list|(
name|algoname
argument_list|(
name|algo
argument_list|)
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|datasizes
index|[
name|i
index|]
argument_list|)
argument_list|)
operator|<<
name|algo
operator|<<
name|data
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|hash
name|void
name|tst_bench_QCryptographicHash
operator|::
name|hash
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|algorithm
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|QCryptographicHash
operator|::
name|Algorithm
name|algo
init|=
name|QCryptographicHash
operator|::
name|Algorithm
argument_list|(
name|algorithm
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|QCryptographicHash
operator|::
name|hash
argument_list|(
name|data
argument_list|,
name|algo
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|addData
name|void
name|tst_bench_QCryptographicHash
operator|::
name|addData
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|algorithm
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|QCryptographicHash
operator|::
name|Algorithm
name|algo
init|=
name|QCryptographicHash
operator|::
name|Algorithm
argument_list|(
name|algorithm
argument_list|)
decl_stmt|;
name|QCryptographicHash
name|hash
argument_list|(
name|algo
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|hash
operator|.
name|reset
argument_list|()
expr_stmt|;
name|hash
operator|.
name|addData
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|hash
operator|.
name|result
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|addDataChunked
name|void
name|tst_bench_QCryptographicHash
operator|::
name|addDataChunked
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|algorithm
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|QCryptographicHash
operator|::
name|Algorithm
name|algo
init|=
name|QCryptographicHash
operator|::
name|Algorithm
argument_list|(
name|algorithm
argument_list|)
decl_stmt|;
name|QCryptographicHash
name|hash
argument_list|(
name|algo
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|hash
operator|.
name|reset
argument_list|()
expr_stmt|;
comment|// add the data in chunks of 64 bytes
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|data
operator|.
name|size
argument_list|()
operator|/
literal|64
condition|;
operator|++
name|i
control|)
name|hash
operator|.
name|addData
argument_list|(
name|data
operator|.
name|constData
argument_list|()
operator|+
literal|64
operator|*
name|i
argument_list|,
literal|64
argument_list|)
expr_stmt|;
name|hash
operator|.
name|addData
argument_list|(
name|data
operator|.
name|constData
argument_list|()
operator|+
name|data
operator|.
name|size
argument_list|()
operator|/
literal|64
operator|*
literal|64
argument_list|,
name|data
operator|.
name|size
argument_list|()
operator|%
literal|64
argument_list|)
expr_stmt|;
name|hash
operator|.
name|result
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_bench_QCryptographicHash
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
