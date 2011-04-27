begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qfilesystementry_p.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
end_if
begin_define
DECL|macro|WIN_STUFF
define|#
directive|define
name|WIN_STUFF
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_class
DECL|class|tst_QFileSystemEntry
class|class
name|tst_QFileSystemEntry
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|getSetCheck_data
parameter_list|()
function_decl|;
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|suffix_data
parameter_list|()
function_decl|;
name|void
name|suffix
parameter_list|()
function_decl|;
name|void
name|completeSuffix_data
parameter_list|()
function_decl|;
name|void
name|completeSuffix
parameter_list|()
function_decl|;
name|void
name|baseName_data
parameter_list|()
function_decl|;
name|void
name|baseName
parameter_list|()
function_decl|;
name|void
name|completeBaseName_data
parameter_list|()
function_decl|;
name|void
name|completeBaseName
parameter_list|()
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|WIN_STUFF
argument_list|)
name|void
name|absoluteOrRelative_data
parameter_list|()
function_decl|;
name|void
name|absoluteOrRelative
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
class|;
end_class
begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN_STUFF
argument_list|)
end_if
begin_function
DECL|function|getSetCheck_data
name|void
name|tst_QFileSystemEntry
operator|::
name|getSetCheck_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"nativeFilePath"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"internalnativeFilePath"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"filepath"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"filename"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"baseName"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"completeBasename"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"suffix"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"completeSuffix"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"absolute"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"relative"
argument_list|)
expr_stmt|;
name|QString
name|absPrefix
init|=
name|QLatin1String
argument_list|(
literal|"\\\\?\\"
argument_list|)
decl_stmt|;
name|QString
name|relPrefix
init|=
name|absPrefix
operator|+
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
argument_list|)
operator|+
name|QLatin1String
argument_list|(
literal|"\\"
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"simple"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"A:\\home\\qt\\in\\a\\dir.tar.gz"
argument_list|)
operator|<<
name|absPrefix
operator|+
name|QString
argument_list|(
literal|"A:\\home\\qt\\in\\a\\dir.tar.gz"
argument_list|)
operator|<<
literal|"A:/home/qt/in/a/dir.tar.gz"
operator|<<
literal|"dir.tar.gz"
operator|<<
literal|"dir"
operator|<<
literal|"dir.tar"
operator|<<
literal|"gz"
operator|<<
literal|"tar.gz"
operator|<<
literal|true
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"relative"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"in\\a\\dir.tar.gz"
argument_list|)
operator|<<
name|relPrefix
operator|+
name|QString
argument_list|(
literal|"in\\a\\dir.tar.gz"
argument_list|)
operator|<<
literal|"in/a/dir.tar.gz"
operator|<<
literal|"dir.tar.gz"
operator|<<
literal|"dir"
operator|<<
literal|"dir.tar"
operator|<<
literal|"gz"
operator|<<
literal|"tar.gz"
operator|<<
literal|false
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"noSuffix"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"myDir\\myfile"
argument_list|)
operator|<<
name|relPrefix
operator|+
name|QString
argument_list|(
literal|"myDir\\myfile"
argument_list|)
operator|<<
literal|"myDir/myfile"
operator|<<
literal|"myfile"
operator|<<
literal|"myfile"
operator|<<
literal|"myfile"
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|false
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"noLongSuffix"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"myDir\\myfile.txt"
argument_list|)
operator|<<
name|relPrefix
operator|+
name|QString
argument_list|(
literal|"myDir\\myfile.txt"
argument_list|)
operator|<<
literal|"myDir/myfile.txt"
operator|<<
literal|"myfile.txt"
operator|<<
literal|"myfile"
operator|<<
literal|"myfile"
operator|<<
literal|"txt"
operator|<<
literal|"txt"
operator|<<
literal|false
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"endingSlash"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"myDir\\myfile.bla\\"
argument_list|)
operator|<<
name|relPrefix
operator|+
name|QString
argument_list|(
literal|"myDir\\myfile.bla\\"
argument_list|)
operator|<<
literal|"myDir/myfile.bla/"
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|false
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"absolutePath"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"A:dir\\without\\leading\\backslash.bat"
argument_list|)
operator|<<
name|absPrefix
operator|+
name|QString
argument_list|(
literal|"A:\\dir\\without\\leading\\backslash.bat"
argument_list|)
operator|<<
literal|"A:dir/without/leading/backslash.bat"
operator|<<
literal|"backslash.bat"
operator|<<
literal|"backslash"
operator|<<
literal|"backslash"
operator|<<
literal|"bat"
operator|<<
literal|"bat"
operator|<<
literal|false
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getSetCheck
name|void
name|tst_QFileSystemEntry
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|nativeFilePath
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|internalnativeFilePath
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|filepath
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|baseName
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|completeBasename
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|suffix
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|completeSuffix
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|absolute
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|relative
argument_list|)
expr_stmt|;
name|QFileSystemEntry
name|entry1
argument_list|(
name|filepath
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|filePath
argument_list|()
argument_list|,
name|filepath
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|nativeFilePath
argument_list|()
operator|.
name|toLower
argument_list|()
argument_list|,
name|internalnativeFilePath
operator|.
name|toLower
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|fileName
argument_list|()
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|suffix
argument_list|()
argument_list|,
name|suffix
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|completeSuffix
argument_list|()
argument_list|,
name|completeSuffix
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|isAbsolute
argument_list|()
argument_list|,
name|absolute
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|isRelative
argument_list|()
argument_list|,
name|relative
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|baseName
argument_list|()
argument_list|,
name|baseName
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|completeBaseName
argument_list|()
argument_list|,
name|completeBasename
argument_list|)
expr_stmt|;
name|QFileSystemEntry
name|entry2
argument_list|(
name|nativeFilePath
argument_list|,
name|QFileSystemEntry
operator|::
name|FromNativePath
argument_list|()
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|suffix
argument_list|()
argument_list|,
name|suffix
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|completeSuffix
argument_list|()
argument_list|,
name|completeSuffix
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|isAbsolute
argument_list|()
argument_list|,
name|absolute
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|isRelative
argument_list|()
argument_list|,
name|relative
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|filePath
argument_list|()
argument_list|,
name|filepath
argument_list|)
expr_stmt|;
comment|// Since this entry was created using the native path,
comment|// the object shouldnot change nativeFilePath.
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|nativeFilePath
argument_list|()
argument_list|,
name|nativeFilePath
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|fileName
argument_list|()
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|baseName
argument_list|()
argument_list|,
name|baseName
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|completeBaseName
argument_list|()
argument_list|,
name|completeBasename
argument_list|)
expr_stmt|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_function
DECL|function|getSetCheck_data
name|void
name|tst_QFileSystemEntry
operator|::
name|getSetCheck_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"nativeFilePath"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"filepath"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"filename"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"basename"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"completeBasename"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"suffix"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"completeSuffix"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"absolute"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"simple"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"/home/qt/in/a/dir.tar.gz"
argument_list|)
operator|<<
literal|"/home/qt/in/a/dir.tar.gz"
operator|<<
literal|"dir.tar.gz"
operator|<<
literal|"dir"
operator|<<
literal|"dir.tar"
operator|<<
literal|"gz"
operator|<<
literal|"tar.gz"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"relative"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"in/a/dir.tar.gz"
argument_list|)
operator|<<
literal|"in/a/dir.tar.gz"
operator|<<
literal|"dir.tar.gz"
operator|<<
literal|"dir"
operator|<<
literal|"dir.tar"
operator|<<
literal|"gz"
operator|<<
literal|"tar.gz"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"noSuffix"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"myDir/myfile"
argument_list|)
operator|<<
literal|"myDir/myfile"
operator|<<
literal|"myfile"
operator|<<
literal|"myfile"
operator|<<
literal|"myfile"
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"noLongSuffix"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"myDir/myfile.txt"
argument_list|)
operator|<<
literal|"myDir/myfile.txt"
operator|<<
literal|"myfile.txt"
operator|<<
literal|"myfile"
operator|<<
literal|"myfile"
operator|<<
literal|"txt"
operator|<<
literal|"txt"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"endingSlash"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"myDir/myfile.bla/"
argument_list|)
operator|<<
literal|"myDir/myfile.bla/"
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"relativePath"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"A:dir/without/leading/backslash.bat"
argument_list|)
operator|<<
literal|"A:dir/without/leading/backslash.bat"
operator|<<
literal|"backslash.bat"
operator|<<
literal|"backslash"
operator|<<
literal|"backslash"
operator|<<
literal|"bat"
operator|<<
literal|"bat"
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getSetCheck
name|void
name|tst_QFileSystemEntry
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|nativeFilePath
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|filepath
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|basename
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|completeBasename
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|suffix
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|completeSuffix
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|absolute
argument_list|)
expr_stmt|;
name|QFileSystemEntry
name|entry1
argument_list|(
name|filepath
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|filePath
argument_list|()
argument_list|,
name|filepath
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|nativeFilePath
argument_list|()
argument_list|,
name|nativeFilePath
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|fileName
argument_list|()
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|suffix
argument_list|()
argument_list|,
name|suffix
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|completeSuffix
argument_list|()
argument_list|,
name|completeSuffix
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|isAbsolute
argument_list|()
argument_list|,
name|absolute
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|isRelative
argument_list|()
argument_list|,
operator|!
name|absolute
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|baseName
argument_list|()
argument_list|,
name|basename
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry1
operator|.
name|completeBaseName
argument_list|()
argument_list|,
name|completeBasename
argument_list|)
expr_stmt|;
name|QFileSystemEntry
name|entry2
argument_list|(
name|nativeFilePath
argument_list|,
name|QFileSystemEntry
operator|::
name|FromNativePath
argument_list|()
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|suffix
argument_list|()
argument_list|,
name|suffix
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|completeSuffix
argument_list|()
argument_list|,
name|completeSuffix
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|isAbsolute
argument_list|()
argument_list|,
name|absolute
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|isRelative
argument_list|()
argument_list|,
operator|!
name|absolute
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|filePath
argument_list|()
argument_list|,
name|filepath
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|nativeFilePath
argument_list|()
argument_list|,
name|nativeFilePath
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|fileName
argument_list|()
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|baseName
argument_list|()
argument_list|,
name|basename
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry2
operator|.
name|completeBaseName
argument_list|()
argument_list|,
name|completeBasename
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|suffix_data
name|void
name|tst_QFileSystemEntry
operator|::
name|suffix_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"file"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"noextension0"
argument_list|)
operator|<<
literal|"file"
operator|<<
literal|""
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"noextension1"
argument_list|)
operator|<<
literal|"/path/to/file"
operator|<<
literal|""
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
literal|"file.tar"
operator|<<
literal|"tar"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
literal|"file.tar.gz"
operator|<<
literal|"gz"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data2"
argument_list|)
operator|<<
literal|"/path/file/file.tar.gz"
operator|<<
literal|"gz"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
literal|"/path/file.tar"
operator|<<
literal|"tar"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"hidden1"
argument_list|)
operator|<<
literal|".ext1"
operator|<<
literal|"ext1"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"hidden1"
argument_list|)
operator|<<
literal|".ext"
operator|<<
literal|"ext"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"hidden1"
argument_list|)
operator|<<
literal|".ex"
operator|<<
literal|"ex"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"hidden1"
argument_list|)
operator|<<
literal|".e"
operator|<<
literal|"e"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"hidden2"
argument_list|)
operator|<<
literal|".ext1.ext2"
operator|<<
literal|"ext2"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"hidden2"
argument_list|)
operator|<<
literal|".ext.ext2"
operator|<<
literal|"ext2"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"hidden2"
argument_list|)
operator|<<
literal|".ex.ext2"
operator|<<
literal|"ext2"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"hidden2"
argument_list|)
operator|<<
literal|".e.ext2"
operator|<<
literal|"ext2"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"hidden2"
argument_list|)
operator|<<
literal|"..ext2"
operator|<<
literal|"ext2"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dots"
argument_list|)
operator|<<
literal|"/path/file.with.dots/file..ext2"
operator|<<
literal|"ext2"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dots2"
argument_list|)
operator|<<
literal|"/path/file.with.dots/.file..ext2"
operator|<<
literal|"ext2"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|suffix
name|void
name|tst_QFileSystemEntry
operator|::
name|suffix
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QFileSystemEntry
name|fe
argument_list|(
name|file
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fe
operator|.
name|suffix
argument_list|()
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QFileSystemEntry
name|fi2
argument_list|(
name|file
argument_list|)
decl_stmt|;
comment|// first resolve the last slash
operator|(
name|void
operator|)
name|fi2
operator|.
name|path
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fi2
operator|.
name|suffix
argument_list|()
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|completeSuffix_data
name|void
name|tst_QFileSystemEntry
operator|::
name|completeSuffix_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"file"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"noextension0"
argument_list|)
operator|<<
literal|"file"
operator|<<
literal|""
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"noextension1"
argument_list|)
operator|<<
literal|"/path/to/file"
operator|<<
literal|""
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
literal|"file.tar"
operator|<<
literal|"tar"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
literal|"file.tar.gz"
operator|<<
literal|"tar.gz"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data2"
argument_list|)
operator|<<
literal|"/path/file/file.tar.gz"
operator|<<
literal|"tar.gz"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
literal|"/path/file.tar"
operator|<<
literal|"tar"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dots"
argument_list|)
operator|<<
literal|"/path/file.with.dots/file..ext2"
operator|<<
literal|".ext2"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dots2"
argument_list|)
operator|<<
literal|"/path/file.with.dots/.file..ext2"
operator|<<
literal|"file..ext2"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|completeSuffix
name|void
name|tst_QFileSystemEntry
operator|::
name|completeSuffix
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QFileSystemEntry
name|fi
argument_list|(
name|file
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fi
operator|.
name|completeSuffix
argument_list|()
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QFileSystemEntry
name|fi2
argument_list|(
name|file
argument_list|)
decl_stmt|;
comment|// first resolve the last slash
operator|(
name|void
operator|)
name|fi2
operator|.
name|path
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fi2
operator|.
name|completeSuffix
argument_list|()
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|baseName_data
name|void
name|tst_QFileSystemEntry
operator|::
name|baseName_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"file"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
literal|"file.tar"
operator|<<
literal|"file"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
literal|"file.tar.gz"
operator|<<
literal|"file"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data2"
argument_list|)
operator|<<
literal|"/path/file/file.tar.gz"
operator|<<
literal|"file"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
literal|"/path/file.tar"
operator|<<
literal|"file"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data4"
argument_list|)
operator|<<
literal|"/path/file"
operator|<<
literal|"file"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dots"
argument_list|)
operator|<<
literal|"/path/file.with.dots/file..ext2"
operator|<<
literal|"file"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dots2"
argument_list|)
operator|<<
literal|"/path/file.with.dots/.file..ext2"
operator|<<
literal|""
expr_stmt|;
block|}
end_function
begin_function
DECL|function|baseName
name|void
name|tst_QFileSystemEntry
operator|::
name|baseName
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QFileSystemEntry
name|fi
argument_list|(
name|file
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fi
operator|.
name|baseName
argument_list|()
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QFileSystemEntry
name|fi2
argument_list|(
name|file
argument_list|)
decl_stmt|;
comment|// first resolve the last slash
operator|(
name|void
operator|)
name|fi2
operator|.
name|path
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fi2
operator|.
name|baseName
argument_list|()
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|completeBaseName_data
name|void
name|tst_QFileSystemEntry
operator|::
name|completeBaseName_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"file"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
literal|"file.tar"
operator|<<
literal|"file"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
literal|"file.tar.gz"
operator|<<
literal|"file.tar"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data2"
argument_list|)
operator|<<
literal|"/path/file/file.tar.gz"
operator|<<
literal|"file.tar"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
literal|"/path/file.tar"
operator|<<
literal|"file"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data4"
argument_list|)
operator|<<
literal|"/path/file"
operator|<<
literal|"file"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dots"
argument_list|)
operator|<<
literal|"/path/file.with.dots/file..ext2"
operator|<<
literal|"file."
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dots2"
argument_list|)
operator|<<
literal|"/path/file.with.dots/.file..ext2"
operator|<<
literal|".file."
expr_stmt|;
block|}
end_function
begin_function
DECL|function|completeBaseName
name|void
name|tst_QFileSystemEntry
operator|::
name|completeBaseName
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QFileSystemEntry
name|fi
argument_list|(
name|file
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fi
operator|.
name|completeBaseName
argument_list|()
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QFileSystemEntry
name|fi2
argument_list|(
name|file
argument_list|)
decl_stmt|;
comment|// first resolve the last slash
operator|(
name|void
operator|)
name|fi2
operator|.
name|path
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fi2
operator|.
name|completeBaseName
argument_list|()
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN_STUFF
argument_list|)
end_if
begin_function
DECL|function|absoluteOrRelative_data
name|void
name|tst_QFileSystemEntry
operator|::
name|absoluteOrRelative_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"path"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"isAbsolute"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"isRelative"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
literal|"file.tar"
operator|<<
literal|false
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
literal|"/path/file/file.tar.gz"
operator|<<
literal|false
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
literal|"C:path/file/file.tar.gz"
operator|<<
literal|false
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
literal|"C:/path/file"
operator|<<
literal|true
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
literal|"//machine/share"
operator|<<
literal|true
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|absoluteOrRelative
name|void
name|tst_QFileSystemEntry
operator|::
name|absoluteOrRelative
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|path
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|isAbsolute
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|isRelative
argument_list|)
expr_stmt|;
name|QFileSystemEntry
name|fi
argument_list|(
name|path
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fi
operator|.
name|isAbsolute
argument_list|()
argument_list|,
name|isAbsolute
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fi
operator|.
name|isRelative
argument_list|()
argument_list|,
name|isRelative
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QFileSystemEntry
argument_list|)
end_macro
begin_include
include|#
directive|include
file|<tst_qfilesystementry.moc>
end_include
end_unit
