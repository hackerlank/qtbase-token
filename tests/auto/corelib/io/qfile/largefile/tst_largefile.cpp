begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QTest>
end_include
begin_include
include|#
directive|include
file|<QtAlgorithms>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QFileInfo>
end_include
begin_include
include|#
directive|include
file|<qplatformdefs.h>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<cstdlib>
end_include
begin_include
include|#
directive|include
file|<cstdio>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_include
include|#
directive|include
file|<io.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|FSCTL_SET_SPARSE
end_ifndef
begin_comment
comment|// MinGW doesn't define this.
end_comment
begin_define
DECL|macro|FSCTL_SET_SPARSE
define|#
directive|define
name|FSCTL_SET_SPARSE
value|(0x900C4)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WIN
end_comment
begin_class
DECL|class|tst_LargeFile
class|class
name|tst_LargeFile
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_LargeFile
name|tst_LargeFile
parameter_list|()
member_init_list|:
name|blockSize
argument_list|(
literal|1
operator|<<
literal|12
argument_list|)
member_init_list|,
name|maxSizeBits
argument_list|()
member_init_list|,
name|fd_
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|stream_
argument_list|(
literal|0
argument_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QT_LARGEFILE_SUPPORT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
name|maxSizeBits
operator|=
literal|36
expr_stmt|;
comment|// 64 GiB
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
comment|// HFS+ does not support sparse files, so we limit file size for the test
comment|// on Mac OS.
name|maxSizeBits
operator|=
literal|32
expr_stmt|;
comment|// 4 GiB
else|#
directive|else
name|maxSizeBits
operator|=
literal|24
expr_stmt|;
comment|// 16 MiB
endif|#
directive|endif
block|}
private|private:
name|void
name|sparseFileData
parameter_list|()
function_decl|;
name|QByteArray
specifier|const
modifier|&
name|getDataBlock
parameter_list|(
name|int
name|index
parameter_list|,
name|qint64
name|position
parameter_list|)
function_decl|;
private|private
name|slots
private|:
comment|// The LargeFile test case was designed to be run in order as a single unit
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
comment|// Create and fill large file
name|void
name|createSparseFile
parameter_list|()
function_decl|;
name|void
name|fillFileSparsely
parameter_list|()
function_decl|;
name|void
name|closeSparseFile
parameter_list|()
function_decl|;
comment|// Verify file was created
name|void
name|fileCreated
parameter_list|()
function_decl|;
comment|// Positioning in large files
name|void
name|filePositioning
parameter_list|()
function_decl|;
name|void
name|fdPositioning
parameter_list|()
function_decl|;
name|void
name|streamPositioning
parameter_list|()
function_decl|;
comment|// Read data from file
name|void
name|openFileForReading
parameter_list|()
function_decl|;
name|void
name|readFile
parameter_list|()
function_decl|;
comment|// Map/unmap large file
name|void
name|mapFile
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|void
name|mapOffsetOverflow
parameter_list|()
function_decl|;
endif|#
directive|endif
DECL|function|closeFile
name|void
name|closeFile
parameter_list|()
block|{
name|largeFile
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
comment|// Test data
DECL|function|fillFileSparsely_data
name|void
name|fillFileSparsely_data
parameter_list|()
block|{
name|sparseFileData
argument_list|()
expr_stmt|;
block|}
DECL|function|filePositioning_data
name|void
name|filePositioning_data
parameter_list|()
block|{
name|sparseFileData
argument_list|()
expr_stmt|;
block|}
DECL|function|fdPositioning_data
name|void
name|fdPositioning_data
parameter_list|()
block|{
name|sparseFileData
argument_list|()
expr_stmt|;
block|}
DECL|function|streamPositioning_data
name|void
name|streamPositioning_data
parameter_list|()
block|{
name|sparseFileData
argument_list|()
expr_stmt|;
block|}
DECL|function|readFile_data
name|void
name|readFile_data
parameter_list|()
block|{
name|sparseFileData
argument_list|()
expr_stmt|;
block|}
DECL|function|mapFile_data
name|void
name|mapFile_data
parameter_list|()
block|{
name|sparseFileData
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|member|blockSize
specifier|const
name|int
name|blockSize
decl_stmt|;
DECL|member|maxSizeBits
name|int
name|maxSizeBits
decl_stmt|;
DECL|member|largeFile
name|QFile
name|largeFile
decl_stmt|;
DECL|member|generatedBlocks
name|QVector
argument_list|<
name|QByteArray
argument_list|>
name|generatedBlocks
decl_stmt|;
DECL|member|fd_
name|int
name|fd_
decl_stmt|;
DECL|member|stream_
name|FILE
modifier|*
name|stream_
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*     Convenience function to hide reinterpret_cast when copying a POD directly     into a QByteArray.  */
end_comment
begin_function
template|template
parameter_list|<
name|class
name|T
parameter_list|>
DECL|function|appendRaw
specifier|static
specifier|inline
name|void
name|appendRaw
parameter_list|(
name|QByteArray
modifier|&
name|array
parameter_list|,
name|T
name|data
parameter_list|)
block|{
name|array
operator|.
name|append
argument_list|(
cast|reinterpret_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
operator|&
name|data
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     Pad array with filler up to size. On return, array.size() returns size.  */
end_comment
begin_function
DECL|function|topUpWith
specifier|static
specifier|inline
name|void
name|topUpWith
parameter_list|(
name|QByteArray
modifier|&
name|array
parameter_list|,
name|QByteArray
name|filler
parameter_list|,
name|int
name|size
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
operator|(
name|size
operator|-
name|array
operator|.
name|size
argument_list|()
operator|)
operator|/
name|filler
operator|.
name|size
argument_list|()
init|;
name|i
operator|>
literal|0
condition|;
operator|--
name|i
control|)
name|array
operator|.
name|append
argument_list|(
name|filler
argument_list|)
expr_stmt|;
if|if
condition|(
name|array
operator|.
name|size
argument_list|()
operator|<
name|size
condition|)
block|{
name|array
operator|.
name|append
argument_list|(
name|filler
operator|.
name|left
argument_list|(
name|size
operator|-
name|array
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*    Generate a unique data block containing identifiable data. Unaligned,    overlapping and partial blocks should not compare equal.  */
end_comment
begin_function
DECL|function|generateDataBlock
specifier|static
specifier|inline
name|QByteArray
name|generateDataBlock
parameter_list|(
name|int
name|blockSize
parameter_list|,
name|QString
name|text
parameter_list|,
name|qint64
name|userBits
init|=
operator|-
literal|1
parameter_list|)
block|{
name|QByteArray
name|block
decl_stmt|;
name|block
operator|.
name|reserve
argument_list|(
name|blockSize
argument_list|)
expr_stmt|;
comment|// Use of counter and randomBits means content of block will be dependent
comment|// on the generation order. For (file-)systems that do not support sparse
comment|// files, these can be removed so the test file can be reused and doesn't
comment|// have to be generated for every run.
specifier|static
name|qint64
name|counter
init|=
literal|0
decl_stmt|;
name|qint64
name|randomBits
init|=
operator|(
operator|(
name|qint64
operator|)
name|qrand
argument_list|()
operator|<<
literal|32
operator|)
operator||
operator|(
operator|(
name|qint64
operator|)
name|qrand
argument_list|()
operator|&
literal|0x00000000ffffffff
operator|)
decl_stmt|;
name|appendRaw
argument_list|(
name|block
argument_list|,
name|randomBits
argument_list|)
expr_stmt|;
name|appendRaw
argument_list|(
name|block
argument_list|,
name|userBits
argument_list|)
expr_stmt|;
name|appendRaw
argument_list|(
name|block
argument_list|,
name|counter
argument_list|)
expr_stmt|;
name|appendRaw
argument_list|(
name|block
argument_list|,
operator|(
name|qint32
operator|)
literal|0xdeadbeef
argument_list|)
expr_stmt|;
name|appendRaw
argument_list|(
name|block
argument_list|,
name|blockSize
argument_list|)
expr_stmt|;
name|QByteArray
name|userContent
init|=
name|text
operator|.
name|toUtf8
argument_list|()
decl_stmt|;
name|appendRaw
argument_list|(
name|block
argument_list|,
name|userContent
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|block
operator|.
name|append
argument_list|(
name|userContent
argument_list|)
expr_stmt|;
name|appendRaw
argument_list|(
name|block
argument_list|,
operator|(
name|qint64
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// size, so far
name|appendRaw
argument_list|(
name|block
argument_list|,
name|block
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|QByteArray
name|filler
argument_list|(
literal|"0123456789"
argument_list|)
decl_stmt|;
name|block
operator|.
name|append
argument_list|(
name|filler
operator|.
name|right
argument_list|(
literal|10
operator|-
name|block
operator|.
name|size
argument_list|()
operator|%
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|topUpWith
argument_list|(
name|block
argument_list|,
name|filler
argument_list|,
name|blockSize
operator|-
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|qint64
argument_list|)
argument_list|)
expr_stmt|;
name|appendRaw
argument_list|(
name|block
argument_list|,
name|counter
argument_list|)
expr_stmt|;
name|appendRaw
argument_list|(
name|block
argument_list|,
name|userBits
argument_list|)
expr_stmt|;
name|appendRaw
argument_list|(
name|block
argument_list|,
name|randomBits
argument_list|)
expr_stmt|;
operator|++
name|counter
expr_stmt|;
return|return
name|block
return|;
block|}
end_function
begin_comment
comment|/*    Generates data blocks the first time they are requested. Keeps copies for reuse.  */
end_comment
begin_function
DECL|function|getDataBlock
name|QByteArray
specifier|const
modifier|&
name|tst_LargeFile
operator|::
name|getDataBlock
parameter_list|(
name|int
name|index
parameter_list|,
name|qint64
name|position
parameter_list|)
block|{
if|if
condition|(
name|index
operator|>=
name|generatedBlocks
operator|.
name|size
argument_list|()
condition|)
name|generatedBlocks
operator|.
name|resize
argument_list|(
name|index
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|generatedBlocks
index|[
name|index
index|]
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QString
name|text
init|=
name|QString
argument_list|(
literal|"Current %1-byte block (index = %2) "
literal|"starts %3 bytes into the file '%4'."
argument_list|)
operator|.
name|arg
argument_list|(
name|blockSize
argument_list|)
operator|.
name|arg
argument_list|(
name|index
argument_list|)
operator|.
name|arg
argument_list|(
name|position
argument_list|)
operator|.
name|arg
argument_list|(
literal|"qt_largefile.tmp"
argument_list|)
decl_stmt|;
name|generatedBlocks
index|[
name|index
index|]
operator|=
name|generateDataBlock
argument_list|(
name|blockSize
argument_list|,
name|text
argument_list|,
operator|(
name|qint64
operator|)
literal|1
operator|<<
name|index
argument_list|)
expr_stmt|;
block|}
return|return
name|generatedBlocks
index|[
name|index
index|]
return|;
block|}
end_function
begin_function
DECL|function|initTestCase
name|void
name|tst_LargeFile
operator|::
name|initTestCase
parameter_list|()
block|{
name|QFile
name|file
argument_list|(
literal|"qt_largefile.tmp"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|file
operator|.
name|exists
argument_list|()
operator|||
name|file
operator|.
name|remove
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_LargeFile
operator|::
name|cleanupTestCase
parameter_list|()
block|{
if|if
condition|(
name|largeFile
operator|.
name|isOpen
argument_list|()
condition|)
name|largeFile
operator|.
name|close
argument_list|()
expr_stmt|;
name|QFile
name|file
argument_list|(
literal|"qt_largefile.tmp"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|file
operator|.
name|exists
argument_list|()
operator|||
name|file
operator|.
name|remove
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|tst_LargeFile
operator|::
name|init
parameter_list|()
block|{
name|fd_
operator|=
operator|-
literal|1
expr_stmt|;
name|stream_
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_LargeFile
operator|::
name|cleanup
parameter_list|()
block|{
if|if
condition|(
operator|-
literal|1
operator|!=
name|fd_
condition|)
name|QT_CLOSE
argument_list|(
name|fd_
argument_list|)
expr_stmt|;
if|if
condition|(
name|stream_
condition|)
operator|::
name|fclose
argument_list|(
name|stream_
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sparseFileData
name|void
name|tst_LargeFile
operator|::
name|sparseFileData
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"index"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qint64
argument_list|>
argument_list|(
literal|"position"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"block"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|QString
argument_list|(
literal|"block[%1] @%2)"
argument_list|)
operator|.
name|arg
argument_list|(
literal|0
argument_list|)
operator|.
name|arg
argument_list|(
literal|0
argument_list|)
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
literal|0
operator|<<
operator|(
name|qint64
operator|)
literal|0
operator|<<
name|getDataBlock
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// While on Linux sparse files scale well, on Windows, testing at every
comment|// power of 2 leads to very large files. i += 4 gives us a good coverage
comment|// without taxing too much on resources.
for|for
control|(
name|int
name|index
init|=
literal|12
init|;
name|index
operator|<=
name|maxSizeBits
condition|;
name|index
operator|+=
literal|4
control|)
block|{
name|qint64
name|position
init|=
operator|(
name|qint64
operator|)
literal|1
operator|<<
name|index
decl_stmt|;
name|QByteArray
name|block
init|=
name|getDataBlock
argument_list|(
name|index
argument_list|,
name|position
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|QString
argument_list|(
literal|"block[%1] @%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|index
argument_list|)
operator|.
name|arg
argument_list|(
name|position
argument_list|)
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
name|index
operator|<<
name|position
operator|<<
name|block
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|createSparseFile
name|void
name|tst_LargeFile
operator|::
name|createSparseFile
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
comment|// On Windows platforms, we must explicitly set the file to be sparse,
comment|// so disk space is not allocated for the full file when writing to it.
name|HANDLE
name|handle
init|=
operator|::
name|CreateFileA
argument_list|(
literal|"qt_largefile.tmp"
argument_list|,
name|GENERIC_WRITE
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|CREATE_ALWAYS
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|INVALID_HANDLE_VALUE
operator|!=
name|handle
argument_list|)
expr_stmt|;
name|DWORD
name|bytes
decl_stmt|;
if|if
condition|(
operator|!
operator|::
name|DeviceIoControl
argument_list|(
name|handle
argument_list|,
name|FSCTL_SET_SPARSE
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
operator|&
name|bytes
argument_list|,
name|NULL
argument_list|)
condition|)
block|{
name|QWARN
argument_list|(
literal|"Unable to set test file as sparse. "
literal|"Limiting test file to 16MiB."
argument_list|)
expr_stmt|;
name|maxSizeBits
operator|=
literal|24
expr_stmt|;
block|}
name|int
name|fd
init|=
operator|::
name|_open_osfhandle
argument_list|(
operator|(
name|intptr_t
operator|)
name|handle
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|-
literal|1
operator|!=
name|fd
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|largeFile
operator|.
name|open
argument_list|(
name|fd
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Unbuffered
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
comment|// !Q_OS_WIN32
name|largeFile
operator|.
name|setFileName
argument_list|(
literal|"qt_largefile.tmp"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|largeFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Unbuffered
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|closeSparseFile
name|void
name|tst_LargeFile
operator|::
name|closeSparseFile
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
name|int
name|fd
init|=
name|largeFile
operator|.
name|handle
argument_list|()
decl_stmt|;
endif|#
directive|endif
name|largeFile
operator|.
name|close
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
if|if
condition|(
operator|-
literal|1
operator|!=
name|fd
condition|)
operator|::
name|_close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|fillFileSparsely
name|void
name|tst_LargeFile
operator|::
name|fillFileSparsely
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|qint64
argument_list|,
name|position
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|block
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|block
operator|.
name|size
argument_list|()
argument_list|,
name|blockSize
argument_list|)
expr_stmt|;
specifier|static
name|int
name|lastKnownGoodIndex
init|=
literal|0
decl_stmt|;
struct|struct
name|ScopeGuard
block|{
name|ScopeGuard
parameter_list|(
name|tst_LargeFile
modifier|*
name|test
parameter_list|)
member_init_list|:
name|this_
argument_list|(
name|test
argument_list|)
member_init_list|,
name|failed
argument_list|(
literal|true
argument_list|)
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|index
argument_list|)
expr_stmt|;
name|index_
operator|=
name|index
expr_stmt|;
block|}
name|~
name|ScopeGuard
parameter_list|()
block|{
if|if
condition|(
name|failed
condition|)
block|{
name|this_
operator|->
name|maxSizeBits
operator|=
name|lastKnownGoodIndex
expr_stmt|;
name|QWARN
argument_list|(
name|qPrintable
argument_list|(
name|QString
argument_list|(
literal|"QFile::error %1: '%2'. Maximum size bits reset to %3."
argument_list|)
operator|.
name|arg
argument_list|(
name|this_
operator|->
name|largeFile
operator|.
name|error
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|this_
operator|->
name|largeFile
operator|.
name|errorString
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|this_
operator|->
name|maxSizeBits
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
name|lastKnownGoodIndex
operator|=
name|qMax
argument_list|<
name|int
argument_list|>
argument_list|(
name|index_
argument_list|,
name|lastKnownGoodIndex
argument_list|)
expr_stmt|;
block|}
private|private:
name|tst_LargeFile
modifier|*
specifier|const
name|this_
decl_stmt|;
name|int
name|index_
decl_stmt|;
public|public:
name|bool
name|failed
decl_stmt|;
block|}
struct|;
name|ScopeGuard
name|resetMaxSizeBitsOnFailure
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|largeFile
operator|.
name|seek
argument_list|(
name|position
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|largeFile
operator|.
name|pos
argument_list|()
argument_list|,
name|position
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|largeFile
operator|.
name|write
argument_list|(
name|block
argument_list|)
argument_list|,
operator|(
name|qint64
operator|)
name|blockSize
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|largeFile
operator|.
name|pos
argument_list|()
argument_list|,
name|position
operator|+
name|blockSize
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|largeFile
operator|.
name|flush
argument_list|()
argument_list|)
expr_stmt|;
name|resetMaxSizeBitsOnFailure
operator|.
name|failed
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fileCreated
name|void
name|tst_LargeFile
operator|::
name|fileCreated
parameter_list|()
block|{
name|QFileInfo
name|info
argument_list|(
literal|"qt_largefile.tmp"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|info
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|info
operator|.
name|isFile
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|info
operator|.
name|size
argument_list|()
operator|>=
operator|(
operator|(
name|qint64
operator|)
literal|1
operator|<<
name|maxSizeBits
operator|)
operator|+
name|blockSize
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|filePositioning
name|void
name|tst_LargeFile
operator|::
name|filePositioning
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|qint64
argument_list|,
name|position
argument_list|)
expr_stmt|;
name|QFile
name|file
argument_list|(
literal|"qt_largefile.tmp"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|file
operator|.
name|seek
argument_list|(
name|position
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|file
operator|.
name|pos
argument_list|()
argument_list|,
name|position
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fdPositioning
name|void
name|tst_LargeFile
operator|::
name|fdPositioning
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|qint64
argument_list|,
name|position
argument_list|)
expr_stmt|;
name|fd_
operator|=
name|QT_OPEN
argument_list|(
literal|"qt_largefile.tmp"
argument_list|,
name|QT_OPEN_RDONLY
operator||
name|QT_OPEN_LARGEFILE
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|-
literal|1
operator|!=
name|fd_
argument_list|)
expr_stmt|;
name|QFile
name|file
decl_stmt|;
name|QVERIFY
argument_list|(
name|file
operator|.
name|open
argument_list|(
name|fd_
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|file
operator|.
name|pos
argument_list|()
argument_list|,
operator|(
name|qint64
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|file
operator|.
name|seek
argument_list|(
name|position
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|file
operator|.
name|pos
argument_list|()
argument_list|,
name|position
argument_list|)
expr_stmt|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QT_LSEEK
argument_list|(
name|fd_
argument_list|,
name|QT_OFF_T
argument_list|(
literal|0
argument_list|)
argument_list|,
name|SEEK_SET
argument_list|)
argument_list|,
name|QT_OFF_T
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QT_LSEEK
argument_list|(
name|fd_
argument_list|,
name|QT_OFF_T
argument_list|(
name|position
argument_list|)
argument_list|,
name|SEEK_SET
argument_list|)
argument_list|,
name|QT_OFF_T
argument_list|(
name|position
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|file
operator|.
name|open
argument_list|(
name|fd_
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QT_LSEEK
argument_list|(
name|fd_
argument_list|,
name|QT_OFF_T
argument_list|(
literal|0
argument_list|)
argument_list|,
name|SEEK_CUR
argument_list|)
argument_list|,
name|QT_OFF_T
argument_list|(
name|position
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|file
operator|.
name|pos
argument_list|()
argument_list|,
name|position
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|file
operator|.
name|seek
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|file
operator|.
name|pos
argument_list|()
argument_list|,
operator|(
name|qint64
operator|)
literal|0
argument_list|)
expr_stmt|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QT_CLOSE
argument_list|(
name|fd_
argument_list|)
argument_list|)
expr_stmt|;
name|fd_
operator|=
operator|-
literal|1
expr_stmt|;
block|}
end_function
begin_function
DECL|function|streamPositioning
name|void
name|tst_LargeFile
operator|::
name|streamPositioning
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|qint64
argument_list|,
name|position
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QT_LARGEFILE_SUPPORT
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
name|_MSC_VER
operator|<
literal|1400
if|if
condition|(
name|position
operator|>=
operator|(
name|qint64
operator|)
literal|1
operator|<<
literal|31
condition|)
name|QSKIP
argument_list|(
literal|"MSVC 2003 doesn't have 64 bit versions of fseek/ftell."
argument_list|,
name|SkipSingle
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|stream_
operator|=
name|QT_FOPEN
argument_list|(
literal|"qt_largefile.tmp"
argument_list|,
literal|"rb"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
literal|0
operator|!=
name|stream_
argument_list|)
expr_stmt|;
name|QFile
name|file
decl_stmt|;
name|QVERIFY
argument_list|(
name|file
operator|.
name|open
argument_list|(
name|stream_
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|file
operator|.
name|pos
argument_list|()
argument_list|,
operator|(
name|qint64
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|file
operator|.
name|seek
argument_list|(
name|position
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|file
operator|.
name|pos
argument_list|()
argument_list|,
name|position
argument_list|)
expr_stmt|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QT_FSEEK
argument_list|(
name|stream_
argument_list|,
name|QT_OFF_T
argument_list|(
literal|0
argument_list|)
argument_list|,
name|SEEK_SET
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QT_FTELL
argument_list|(
name|stream_
argument_list|)
argument_list|,
name|QT_OFF_T
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QT_FSEEK
argument_list|(
name|stream_
argument_list|,
name|QT_OFF_T
argument_list|(
name|position
argument_list|)
argument_list|,
name|SEEK_SET
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QT_FTELL
argument_list|(
name|stream_
argument_list|)
argument_list|,
name|QT_OFF_T
argument_list|(
name|position
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|file
operator|.
name|open
argument_list|(
name|stream_
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QT_FTELL
argument_list|(
name|stream_
argument_list|)
argument_list|,
name|QT_OFF_T
argument_list|(
name|position
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|file
operator|.
name|pos
argument_list|()
argument_list|,
name|position
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|file
operator|.
name|seek
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|file
operator|.
name|pos
argument_list|()
argument_list|,
operator|(
name|qint64
operator|)
literal|0
argument_list|)
expr_stmt|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|::
name|fclose
argument_list|(
name|stream_
argument_list|)
argument_list|)
expr_stmt|;
name|stream_
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|openFileForReading
name|void
name|tst_LargeFile
operator|::
name|openFileForReading
parameter_list|()
block|{
name|largeFile
operator|.
name|setFileName
argument_list|(
literal|"qt_largefile.tmp"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|largeFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readFile
name|void
name|tst_LargeFile
operator|::
name|readFile
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|qint64
argument_list|,
name|position
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|block
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|block
operator|.
name|size
argument_list|()
argument_list|,
name|blockSize
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|largeFile
operator|.
name|size
argument_list|()
operator|>=
name|position
operator|+
name|blockSize
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|largeFile
operator|.
name|seek
argument_list|(
name|position
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|largeFile
operator|.
name|pos
argument_list|()
argument_list|,
name|position
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|largeFile
operator|.
name|read
argument_list|(
name|blockSize
argument_list|)
argument_list|,
name|block
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|largeFile
operator|.
name|pos
argument_list|()
argument_list|,
name|position
operator|+
name|blockSize
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mapFile
name|void
name|tst_LargeFile
operator|::
name|mapFile
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|qint64
argument_list|,
name|position
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|block
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|block
operator|.
name|size
argument_list|()
argument_list|,
name|blockSize
argument_list|)
expr_stmt|;
comment|// Keep full block mapped to facilitate OS and/or internal reuse by Qt.
name|uchar
modifier|*
name|baseAddress
init|=
name|largeFile
operator|.
name|map
argument_list|(
name|position
argument_list|,
name|blockSize
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|baseAddress
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|qEqual
argument_list|(
name|block
operator|.
name|begin
argument_list|()
argument_list|,
name|block
operator|.
name|end
argument_list|()
argument_list|,
cast|reinterpret_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|baseAddress
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|offset
init|=
literal|1
init|;
name|offset
operator|<
name|blockSize
condition|;
operator|++
name|offset
control|)
block|{
name|uchar
modifier|*
name|address
init|=
name|largeFile
operator|.
name|map
argument_list|(
name|position
operator|+
name|offset
argument_list|,
name|blockSize
operator|-
name|offset
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|address
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|qEqual
argument_list|(
name|block
operator|.
name|begin
argument_list|()
operator|+
name|offset
argument_list|,
name|block
operator|.
name|end
argument_list|()
argument_list|,
cast|reinterpret_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|address
argument_list|)
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Expected:"
operator|<<
name|block
operator|.
name|toHex
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Actual  :"
operator|<<
name|QByteArray
argument_list|(
cast|reinterpret_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|address
argument_list|)
argument_list|,
name|blockSize
argument_list|)
operator|.
name|toHex
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|largeFile
operator|.
name|unmap
argument_list|(
name|address
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|largeFile
operator|.
name|unmap
argument_list|(
name|baseAddress
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// mmap'ping beyond EOF may succeed; generate bus error on access.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_MAC
end_ifndef
begin_function
DECL|function|mapOffsetOverflow
name|void
name|tst_LargeFile
operator|::
name|mapOffsetOverflow
parameter_list|()
block|{
comment|// Out-of-range mappings should fail, and not silently clip the offset
for|for
control|(
name|int
name|i
init|=
literal|50
init|;
name|i
operator|<
literal|63
condition|;
operator|++
name|i
control|)
block|{
name|uchar
modifier|*
name|address
init|=
literal|0
decl_stmt|;
name|address
operator|=
name|largeFile
operator|.
name|map
argument_list|(
operator|(
operator|(
name|qint64
operator|)
literal|1
operator|<<
name|i
operator|)
argument_list|,
name|blockSize
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|address
argument_list|)
expr_stmt|;
name|address
operator|=
name|largeFile
operator|.
name|map
argument_list|(
operator|(
operator|(
name|qint64
operator|)
literal|1
operator|<<
name|i
operator|)
operator|+
name|blockSize
argument_list|,
name|blockSize
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|address
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_LargeFile
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_largefile.moc"
end_include
end_unit
