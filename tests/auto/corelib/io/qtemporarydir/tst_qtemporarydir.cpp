begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qtemporarydir.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qset.h>
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
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_UNIX
end_ifdef
begin_comment
comment|// for geteuid()
end_comment
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_QTemporaryDir
class|class
name|tst_QTemporaryDir
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|construction
parameter_list|()
function_decl|;
name|void
name|fileTemplate
parameter_list|()
function_decl|;
name|void
name|fileTemplate_data
parameter_list|()
function_decl|;
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|fileName
parameter_list|()
function_decl|;
name|void
name|autoRemove
parameter_list|()
function_decl|;
name|void
name|nonWritableCurrentDir
parameter_list|()
function_decl|;
name|void
name|openOnRootDrives
parameter_list|()
function_decl|;
name|void
name|stressTest
parameter_list|()
function_decl|;
name|void
name|rename
parameter_list|()
function_decl|;
name|void
name|QTBUG_4796_data
parameter_list|()
function_decl|;
name|void
name|QTBUG_4796
parameter_list|()
function_decl|;
public|public:
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_QTemporaryDir
operator|::
name|initTestCase
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|QDir
argument_list|(
literal|"test-XXXXXX"
argument_list|)
operator|.
name|exists
argument_list|()
operator|||
name|QDir
argument_list|()
operator|.
name|mkdir
argument_list|(
literal|"test-XXXXXX"
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|setApplicationName
argument_list|(
literal|"tst_qtemporarydir"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QTemporaryDir
operator|::
name|cleanupTestCase
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|QDir
argument_list|()
operator|.
name|rmdir
argument_list|(
literal|"test-XXXXXX"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|construction
name|void
name|tst_QTemporaryDir
operator|::
name|construction
parameter_list|()
block|{
name|QTemporaryDir
name|dir
decl_stmt|;
name|QString
name|tmp
init|=
name|QDir
operator|::
name|tempPath
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|dir
operator|.
name|path
argument_list|()
operator|.
name|left
argument_list|(
name|tmp
operator|.
name|size
argument_list|()
argument_list|)
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|path
argument_list|()
operator|.
name|contains
argument_list|(
literal|"tst_qtemporarydir"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QFileInfo
argument_list|(
name|dir
operator|.
name|path
argument_list|()
argument_list|)
operator|.
name|isDir
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QTemporaryDir
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QTemporaryDir
name|obj1
decl_stmt|;
comment|// bool QTemporaryDir::autoRemove()
comment|// void QTemporaryDir::setAutoRemove(bool)
name|obj1
operator|.
name|setAutoRemove
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|false
argument_list|,
name|obj1
operator|.
name|autoRemove
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setAutoRemove
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|true
argument_list|,
name|obj1
operator|.
name|autoRemove
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fileTemplate_data
name|void
name|tst_QTemporaryDir
operator|::
name|fileTemplate_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"constructorTemplate"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"prefix"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"constructor default"
argument_list|)
operator|<<
literal|""
operator|<<
literal|"tst_qtemporarydir-"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"constructor with xxx sufix"
argument_list|)
operator|<<
literal|"qt_XXXXXXxxx"
operator|<<
literal|"qt_XXXXXXxxx"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"constructor with xXx sufix"
argument_list|)
operator|<<
literal|"qt_XXXXXXxXx"
operator|<<
literal|"qt_XXXXXXxXx"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"constructor with no suffix"
argument_list|)
operator|<<
literal|"qt_XXXXXX"
operator|<<
literal|"qt_"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"constructor with>6 X's, no suffix"
argument_list|)
operator|<<
literal|"qt_XXXXXXXXXX"
operator|<<
literal|"qt_"
expr_stmt|;
comment|// When more than 6 X are present at the end, linux and windows will only replace the last 6,
comment|// while Mac OS will actually replace all of them so we can only expect "qt_" (and check isValid).
name|QTest
operator|::
name|newRow
argument_list|(
literal|"constructor with XXXX suffix"
argument_list|)
operator|<<
literal|"qt_XXXXXX_XXXX"
operator|<<
literal|"qt_"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"constructor with XXXX prefix"
argument_list|)
operator|<<
literal|"qt_XXXX"
operator|<<
literal|"qt_"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"constructor with XXXXX prefix"
argument_list|)
operator|<<
literal|"qt_XXXXX"
operator|<<
literal|"qt_"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fileTemplate
name|void
name|tst_QTemporaryDir
operator|::
name|fileTemplate
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|constructorTemplate
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|prefix
argument_list|)
expr_stmt|;
name|QTemporaryDir
name|tempDir
argument_list|(
name|constructorTemplate
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|tempDir
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QString
name|dirName
init|=
name|QDir
argument_list|(
name|tempDir
operator|.
name|path
argument_list|()
argument_list|)
operator|.
name|dirName
argument_list|()
decl_stmt|;
if|if
condition|(
name|prefix
operator|.
name|length
argument_list|()
condition|)
name|QCOMPARE
argument_list|(
name|dirName
operator|.
name|left
argument_list|(
name|prefix
operator|.
name|length
argument_list|()
argument_list|)
argument_list|,
name|prefix
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     This tests whether the temporary dir really gets placed in QDir::tempPath */
end_comment
begin_function
DECL|function|fileName
name|void
name|tst_QTemporaryDir
operator|::
name|fileName
parameter_list|()
block|{
comment|// Get QDir::tempPath and make an absolute path.
name|QString
name|tempPath
init|=
name|QDir
operator|::
name|tempPath
argument_list|()
decl_stmt|;
name|QString
name|absoluteTempPath
init|=
name|QDir
argument_list|(
name|tempPath
argument_list|)
operator|.
name|absolutePath
argument_list|()
decl_stmt|;
name|QTemporaryDir
name|dir
decl_stmt|;
name|dir
operator|.
name|setAutoRemove
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QString
name|fileName
init|=
name|dir
operator|.
name|path
argument_list|()
decl_stmt|;
name|QVERIFY2
argument_list|(
name|fileName
operator|.
name|contains
argument_list|(
literal|"/tst_qtemporarydir-"
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|fileName
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QDir
argument_list|(
name|fileName
argument_list|)
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
comment|// Get path to the temp dir, without the file name.
name|QString
name|absoluteFilePath
init|=
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|absolutePath
argument_list|()
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|absoluteFilePath
operator|=
name|absoluteFilePath
operator|.
name|toLower
argument_list|()
expr_stmt|;
name|absoluteTempPath
operator|=
name|absoluteTempPath
operator|.
name|toLower
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|QCOMPARE
argument_list|(
name|absoluteFilePath
argument_list|,
name|absoluteTempPath
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|autoRemove
name|void
name|tst_QTemporaryDir
operator|::
name|autoRemove
parameter_list|()
block|{
comment|// Test auto remove
name|QString
name|dirName
decl_stmt|;
block|{
name|QTemporaryDir
name|dir
argument_list|(
literal|"tempXXXXXX"
argument_list|)
decl_stmt|;
name|dir
operator|.
name|setAutoRemove
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|dirName
operator|=
name|dir
operator|.
name|path
argument_list|()
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|Q_OS_WIN
comment|// Windows seems unreliable here: sometimes it says the directory still exists,
comment|// immediately after we deleted it.
name|QTRY_VERIFY
argument_list|(
operator|!
name|QDir
argument_list|(
name|dirName
argument_list|)
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|QVERIFY
argument_list|(
operator|!
name|QDir
argument_list|(
name|dirName
argument_list|)
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Test if disabling auto remove works.
block|{
name|QTemporaryDir
name|dir
argument_list|(
literal|"tempXXXXXX"
argument_list|)
decl_stmt|;
name|dir
operator|.
name|setAutoRemove
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|dirName
operator|=
name|dir
operator|.
name|path
argument_list|()
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|QDir
argument_list|(
name|dirName
argument_list|)
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QDir
argument_list|()
operator|.
name|rmdir
argument_list|(
name|dirName
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QDir
argument_list|(
name|dirName
argument_list|)
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
comment|// Do not explicitly call setAutoRemove (tests if it really is the default as documented)
block|{
name|QTemporaryDir
name|dir
argument_list|(
literal|"tempXXXXXX"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|dirName
operator|=
name|dir
operator|.
name|path
argument_list|()
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|QTRY_VERIFY
argument_list|(
operator|!
name|QDir
argument_list|(
name|dirName
argument_list|)
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|QVERIFY
argument_list|(
operator|!
name|QDir
argument_list|(
name|dirName
argument_list|)
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Test autoremove with files and subdirs in the temp dir
block|{
name|QTemporaryDir
name|tempDir
argument_list|(
literal|"tempXXXXXX"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|tempDir
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|dirName
operator|=
name|tempDir
operator|.
name|path
argument_list|()
expr_stmt|;
name|QDir
name|dir
argument_list|(
name|dirName
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|mkdir
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"dir1"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|mkdir
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"dir2"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|mkdir
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"dir2/nested"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QFile
name|file
argument_list|(
name|dirName
operator|+
literal|"/dir1/file"
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
name|WriteOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|file
operator|.
name|write
argument_list|(
literal|"Hello"
argument_list|)
argument_list|,
literal|5LL
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|QTRY_VERIFY
argument_list|(
operator|!
name|QDir
argument_list|(
name|dirName
argument_list|)
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|QVERIFY
argument_list|(
operator|!
name|QDir
argument_list|(
name|dirName
argument_list|)
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|nonWritableCurrentDir
name|void
name|tst_QTemporaryDir
operator|::
name|nonWritableCurrentDir
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_OS_UNIX
if|if
condition|(
operator|::
name|geteuid
argument_list|()
operator|==
literal|0
condition|)
name|QSKIP
argument_list|(
literal|"not valid running this test as root"
argument_list|)
expr_stmt|;
struct|struct
name|ChdirOnReturn
block|{
name|ChdirOnReturn
parameter_list|(
specifier|const
name|QString
modifier|&
name|d
parameter_list|)
member_init_list|:
name|dir
argument_list|(
name|d
argument_list|)
block|{}
name|~
name|ChdirOnReturn
parameter_list|()
block|{
name|QDir
operator|::
name|setCurrent
argument_list|(
name|dir
argument_list|)
expr_stmt|;
block|}
name|QString
name|dir
decl_stmt|;
block|}
struct|;
name|ChdirOnReturn
name|cor
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
argument_list|)
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_ANDROID_NO_SDK
argument_list|)
name|QDir
operator|::
name|setCurrent
argument_list|(
literal|"/data"
argument_list|)
expr_stmt|;
else|#
directive|else
name|QDir
operator|::
name|setCurrent
argument_list|(
literal|"/home"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QTemporaryDir("tempXXXXXX") is probably a bad idea in any app
comment|// where the current dir could anything...
name|QTemporaryDir
name|dir
argument_list|(
literal|"tempXXXXXX"
argument_list|)
decl_stmt|;
name|dir
operator|.
name|setAutoRemove
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|dir
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|path
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|openOnRootDrives
name|void
name|tst_QTemporaryDir
operator|::
name|openOnRootDrives
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINRT
argument_list|)
name|unsigned
name|int
name|lastErrorMode
init|=
name|SetErrorMode
argument_list|(
name|SEM_FAILCRITICALERRORS
argument_list|)
decl_stmt|;
endif|#
directive|endif
comment|// If it's possible to create a file in the root directory, it
comment|// must be possible to create a temp dir there too.
foreach|foreach
control|(
specifier|const
name|QFileInfo
modifier|&
name|driveInfo
decl|,
name|QDir
operator|::
name|drives
argument_list|()
control|)
block|{
name|QFile
name|testFile
argument_list|(
name|driveInfo
operator|.
name|filePath
argument_list|()
operator|+
literal|"XXXXXX"
argument_list|)
decl_stmt|;
if|if
condition|(
name|testFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadWrite
argument_list|)
condition|)
block|{
name|testFile
operator|.
name|remove
argument_list|()
expr_stmt|;
name|QTemporaryDir
name|dir
argument_list|(
name|driveInfo
operator|.
name|filePath
argument_list|()
operator|+
literal|"XXXXXX"
argument_list|)
decl_stmt|;
name|dir
operator|.
name|setAutoRemove
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINRT
argument_list|)
name|SetErrorMode
argument_list|(
name|lastErrorMode
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|stressTest
name|void
name|tst_QTemporaryDir
operator|::
name|stressTest
parameter_list|()
block|{
specifier|const
name|int
name|iterations
init|=
literal|1000
decl_stmt|;
name|QTemporaryDir
name|rootDir
decl_stmt|;
name|QVERIFY
argument_list|(
name|rootDir
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QSet
argument_list|<
name|QString
argument_list|>
name|names
decl_stmt|;
specifier|const
name|QString
name|pattern
init|=
name|rootDir
operator|.
name|path
argument_list|()
operator|+
name|QStringLiteral
argument_list|(
literal|"/XXXXXX"
argument_list|)
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
name|iterations
condition|;
operator|++
name|i
control|)
block|{
name|QTemporaryDir
name|dir
argument_list|(
name|pattern
argument_list|)
decl_stmt|;
name|dir
operator|.
name|setAutoRemove
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|dir
operator|.
name|isValid
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Failed to create #%1 under %2."
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
operator|.
name|arg
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|pattern
argument_list|)
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|names
operator|.
name|contains
argument_list|(
name|dir
operator|.
name|path
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|names
operator|.
name|insert
argument_list|(
name|dir
operator|.
name|path
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|rename
name|void
name|tst_QTemporaryDir
operator|::
name|rename
parameter_list|()
block|{
comment|// This test checks what happens if the temporary dir is renamed.
comment|// Then the autodelete feature can't possibly find it.
name|QDir
name|dir
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|dir
operator|.
name|exists
argument_list|(
literal|"temporary-dir.renamed"
argument_list|)
argument_list|)
expr_stmt|;
name|QString
name|tempname
decl_stmt|;
block|{
name|QTemporaryDir
name|tempDir
argument_list|(
name|dir
operator|.
name|filePath
argument_list|(
literal|"temporary-dir.XXXXXX"
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|tempDir
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|tempname
operator|=
name|tempDir
operator|.
name|path
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QDir
argument_list|()
operator|.
name|rename
argument_list|(
name|tempname
argument_list|,
literal|"temporary-dir.renamed"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QDir
argument_list|(
name|tempname
argument_list|)
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
name|dir
operator|.
name|setPath
argument_list|(
literal|"temporary-dir.renamed"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|dir
operator|.
name|path
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"temporary-dir.renamed"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Auto-delete couldn't find it
name|QVERIFY
argument_list|(
name|dir
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
comment|// Clean up by hand
name|QVERIFY
argument_list|(
name|dir
operator|.
name|removeRecursively
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|dir
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|QTBUG_4796_data
name|void
name|tst_QTemporaryDir
operator|::
name|QTBUG_4796_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"prefix"
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
name|bool
argument_list|>
argument_list|(
literal|"openResult"
argument_list|)
expr_stmt|;
name|QString
name|unicode
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"\xc3\xa5\xc3\xa6\xc3\xb8"
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"<empty>"
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"."
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"."
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|".."
argument_list|)
operator|<<
name|QString
argument_list|(
literal|".."
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"blaXXXXXX"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"bla"
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"does-not-exist/qt_temp.XXXXXX"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"does-not-exist/qt_temp"
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"XXXXXX<unicode>"
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
name|unicode
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"<unicode>XXXXXX"
argument_list|)
operator|<<
name|unicode
operator|<<
name|QString
argument_list|()
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|QTBUG_4796
name|void
name|tst_QTemporaryDir
operator|::
name|QTBUG_4796
parameter_list|()
comment|// unicode support
block|{
name|QVERIFY
argument_list|(
name|QDir
argument_list|(
literal|"test-XXXXXX"
argument_list|)
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
struct|struct
name|CleanOnReturn
block|{
name|~
name|CleanOnReturn
parameter_list|()
block|{
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|tempName
decl|,
name|tempNames
control|)
name|QVERIFY
argument_list|(
name|QDir
argument_list|(
name|tempName
argument_list|)
operator|.
name|removeRecursively
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|void
name|reset
parameter_list|()
block|{
name|tempNames
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|QStringList
name|tempNames
decl_stmt|;
block|}
struct|;
name|CleanOnReturn
name|cleaner
decl_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|prefix
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
name|bool
argument_list|,
name|openResult
argument_list|)
expr_stmt|;
block|{
name|QString
name|fileTemplate1
init|=
name|prefix
operator|+
name|QString
argument_list|(
literal|"XX"
argument_list|)
operator|+
name|suffix
decl_stmt|;
name|QString
name|fileTemplate2
init|=
name|prefix
operator|+
name|QString
argument_list|(
literal|"XXXX"
argument_list|)
operator|+
name|suffix
decl_stmt|;
name|QString
name|fileTemplate3
init|=
name|prefix
operator|+
name|QString
argument_list|(
literal|"XXXXXX"
argument_list|)
operator|+
name|suffix
decl_stmt|;
name|QString
name|fileTemplate4
init|=
name|prefix
operator|+
name|QString
argument_list|(
literal|"XXXXXXXX"
argument_list|)
operator|+
name|suffix
decl_stmt|;
name|QTemporaryDir
name|dir1
argument_list|(
name|fileTemplate1
argument_list|)
decl_stmt|;
name|QTemporaryDir
name|dir2
argument_list|(
name|fileTemplate2
argument_list|)
decl_stmt|;
name|QTemporaryDir
name|dir3
argument_list|(
name|fileTemplate3
argument_list|)
decl_stmt|;
name|QTemporaryDir
name|dir4
argument_list|(
name|fileTemplate4
argument_list|)
decl_stmt|;
name|QTemporaryDir
name|dir5
argument_list|(
literal|"test-XXXXXX/"
operator|+
name|fileTemplate1
argument_list|)
decl_stmt|;
name|QTemporaryDir
name|dir6
argument_list|(
literal|"test-XXXXXX/"
operator|+
name|fileTemplate3
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|dir1
operator|.
name|isValid
argument_list|()
argument_list|,
name|openResult
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|dir2
operator|.
name|isValid
argument_list|()
argument_list|,
name|openResult
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|dir3
operator|.
name|isValid
argument_list|()
argument_list|,
name|openResult
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|dir4
operator|.
name|isValid
argument_list|()
argument_list|,
name|openResult
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|dir5
operator|.
name|isValid
argument_list|()
argument_list|,
name|openResult
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|dir6
operator|.
name|isValid
argument_list|()
argument_list|,
name|openResult
argument_list|)
expr_stmt|;
comment|// make sure the dir exists under the *correct* name
if|if
condition|(
name|openResult
condition|)
block|{
name|cleaner
operator|.
name|tempNames
operator|<<
name|dir1
operator|.
name|path
argument_list|()
operator|<<
name|dir2
operator|.
name|path
argument_list|()
operator|<<
name|dir3
operator|.
name|path
argument_list|()
operator|<<
name|dir4
operator|.
name|path
argument_list|()
operator|<<
name|dir5
operator|.
name|path
argument_list|()
operator|<<
name|dir6
operator|.
name|path
argument_list|()
expr_stmt|;
name|QDir
name|currentDir
decl_stmt|;
name|QString
name|fileName1
init|=
name|currentDir
operator|.
name|relativeFilePath
argument_list|(
name|dir1
operator|.
name|path
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|fileName2
init|=
name|currentDir
operator|.
name|relativeFilePath
argument_list|(
name|dir2
operator|.
name|path
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|fileName3
init|=
name|currentDir
operator|.
name|relativeFilePath
argument_list|(
name|dir3
operator|.
name|path
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|fileName4
init|=
name|currentDir
operator|.
name|relativeFilePath
argument_list|(
name|dir4
operator|.
name|path
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|fileName5
init|=
name|currentDir
operator|.
name|relativeFilePath
argument_list|(
name|dir5
operator|.
name|path
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|fileName6
init|=
name|currentDir
operator|.
name|relativeFilePath
argument_list|(
name|dir6
operator|.
name|path
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|fileName1
operator|.
name|startsWith
argument_list|(
name|prefix
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fileName2
operator|.
name|startsWith
argument_list|(
name|prefix
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fileName5
operator|.
name|startsWith
argument_list|(
literal|"test-XXXXXX/"
operator|+
name|prefix
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fileName6
operator|.
name|startsWith
argument_list|(
literal|"test-XXXXXX/"
operator|+
name|prefix
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|prefix
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QVERIFY
argument_list|(
name|fileName3
operator|.
name|startsWith
argument_list|(
name|prefix
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fileName4
operator|.
name|startsWith
argument_list|(
name|prefix
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|QTest
operator|::
name|qWait
argument_list|(
literal|20
argument_list|)
expr_stmt|;
endif|#
directive|endif
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|tempName
decl|,
name|cleaner
operator|.
name|tempNames
control|)
name|QVERIFY2
argument_list|(
operator|!
name|QDir
argument_list|(
name|tempName
argument_list|)
operator|.
name|exists
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|tempName
argument_list|)
argument_list|)
expr_stmt|;
name|cleaner
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QTemporaryDir
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtemporarydir.moc"
end_include
end_unit
