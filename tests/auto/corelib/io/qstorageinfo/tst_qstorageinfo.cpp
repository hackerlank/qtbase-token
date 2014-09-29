begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Ivan Komissarov<ABBAPOH@gmail.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QStorageInfo>
end_include
begin_class
DECL|class|tst_QStorageInfo
class|class
name|tst_QStorageInfo
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|defaultValues
parameter_list|()
function_decl|;
name|void
name|operatorEqual
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|Q_OS_WINRT
name|void
name|operatorNotEqual
parameter_list|()
function_decl|;
name|void
name|root
parameter_list|()
function_decl|;
name|void
name|currentStorage
parameter_list|()
function_decl|;
name|void
name|storageList
parameter_list|()
function_decl|;
name|void
name|tempFile
parameter_list|()
function_decl|;
name|void
name|caching
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
class|;
end_class
begin_function
DECL|function|defaultValues
name|void
name|tst_QStorageInfo
operator|::
name|defaultValues
parameter_list|()
block|{
name|QStorageInfo
name|storage
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|storage
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|storage
operator|.
name|isReady
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|rootPath
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|storage
operator|.
name|isRoot
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|device
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|fileSystemType
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|bytesTotal
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|bytesFree
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|bytesAvailable
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operatorEqual
name|void
name|tst_QStorageInfo
operator|::
name|operatorEqual
parameter_list|()
block|{
block|{
name|QStorageInfo
name|storage1
init|=
name|QStorageInfo
operator|::
name|root
argument_list|()
decl_stmt|;
name|QStorageInfo
name|storage2
argument_list|(
name|QDir
operator|::
name|rootPath
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|storage1
operator|==
name|storage2
argument_list|)
expr_stmt|;
block|}
block|{
name|QStorageInfo
name|storage1
argument_list|(
name|QCoreApplication
operator|::
name|applicationDirPath
argument_list|()
argument_list|)
decl_stmt|;
name|QStorageInfo
name|storage2
argument_list|(
name|QCoreApplication
operator|::
name|applicationFilePath
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|storage1
operator|==
name|storage2
argument_list|)
expr_stmt|;
block|}
block|{
name|QStorageInfo
name|storage1
decl_stmt|;
name|QStorageInfo
name|storage2
decl_stmt|;
name|QVERIFY
argument_list|(
name|storage1
operator|==
name|storage2
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINRT
end_ifndef
begin_function
DECL|function|operatorNotEqual
name|void
name|tst_QStorageInfo
operator|::
name|operatorNotEqual
parameter_list|()
block|{
name|QStorageInfo
name|storage1
init|=
name|QStorageInfo
operator|::
name|root
argument_list|()
decl_stmt|;
name|QStorageInfo
name|storage2
decl_stmt|;
name|QVERIFY
argument_list|(
name|storage1
operator|!=
name|storage2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|root
name|void
name|tst_QStorageInfo
operator|::
name|root
parameter_list|()
block|{
name|QStorageInfo
name|storage
init|=
name|QStorageInfo
operator|::
name|root
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|isReady
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|storage
operator|.
name|rootPath
argument_list|()
argument_list|,
name|QDir
operator|::
name|rootPath
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|isRoot
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|storage
operator|.
name|device
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|storage
operator|.
name|fileSystemType
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|bytesTotal
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|bytesFree
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|bytesAvailable
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentStorage
name|void
name|tst_QStorageInfo
operator|::
name|currentStorage
parameter_list|()
block|{
name|QString
name|appPath
init|=
name|QCoreApplication
operator|::
name|applicationFilePath
argument_list|()
decl_stmt|;
name|QStorageInfo
name|storage
argument_list|(
name|appPath
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|isReady
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|appPath
operator|.
name|startsWith
argument_list|(
name|storage
operator|.
name|rootPath
argument_list|()
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|storage
operator|.
name|device
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|storage
operator|.
name|fileSystemType
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|bytesTotal
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|bytesFree
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|bytesAvailable
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|storageList
name|void
name|tst_QStorageInfo
operator|::
name|storageList
parameter_list|()
block|{
name|QStorageInfo
name|root
init|=
name|QStorageInfo
operator|::
name|root
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QStorageInfo
argument_list|>
name|volumes
init|=
name|QStorageInfo
operator|::
name|mountedVolumes
argument_list|()
decl_stmt|;
comment|// at least, root storage should be present
name|QVERIFY
argument_list|(
name|volumes
operator|.
name|contains
argument_list|(
name|root
argument_list|)
argument_list|)
expr_stmt|;
name|volumes
operator|.
name|removeOne
argument_list|(
name|root
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|volumes
operator|.
name|contains
argument_list|(
name|root
argument_list|)
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QStorageInfo
modifier|&
name|storage
decl|,
name|volumes
control|)
block|{
if|if
condition|(
operator|!
name|storage
operator|.
name|isReady
argument_list|()
condition|)
continue|continue;
name|QVERIFY
argument_list|(
name|storage
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|storage
operator|.
name|isRoot
argument_list|()
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_WIN
name|QVERIFY
argument_list|(
operator|!
name|storage
operator|.
name|device
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|storage
operator|.
name|fileSystemType
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
begin_function
DECL|function|tempFile
name|void
name|tst_QStorageInfo
operator|::
name|tempFile
parameter_list|()
block|{
name|QTemporaryFile
name|file
decl_stmt|;
name|QVERIFY
argument_list|(
name|file
operator|.
name|open
argument_list|()
argument_list|)
expr_stmt|;
name|QStorageInfo
name|storage1
argument_list|(
name|file
operator|.
name|fileName
argument_list|()
argument_list|)
decl_stmt|;
name|qint64
name|free
init|=
name|storage1
operator|.
name|bytesFree
argument_list|()
decl_stmt|;
name|file
operator|.
name|write
argument_list|(
name|QByteArray
argument_list|(
literal|1024
operator|*
literal|1024
argument_list|,
literal|'1'
argument_list|)
argument_list|)
expr_stmt|;
name|file
operator|.
name|flush
argument_list|()
expr_stmt|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
name|QStorageInfo
name|storage2
argument_list|(
name|file
operator|.
name|fileName
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|free
operator|!=
name|storage2
operator|.
name|bytesFree
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|caching
name|void
name|tst_QStorageInfo
operator|::
name|caching
parameter_list|()
block|{
name|QTemporaryFile
name|file
decl_stmt|;
name|QVERIFY
argument_list|(
name|file
operator|.
name|open
argument_list|()
argument_list|)
expr_stmt|;
name|QStorageInfo
name|storage1
argument_list|(
name|file
operator|.
name|fileName
argument_list|()
argument_list|)
decl_stmt|;
name|qint64
name|free
init|=
name|storage1
operator|.
name|bytesFree
argument_list|()
decl_stmt|;
name|QStorageInfo
name|storage2
argument_list|(
name|storage1
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|free
operator|==
name|storage2
operator|.
name|bytesFree
argument_list|()
argument_list|)
expr_stmt|;
name|file
operator|.
name|write
argument_list|(
name|QByteArray
argument_list|(
literal|1024
operator|*
literal|1024
argument_list|,
literal|'\0'
argument_list|)
argument_list|)
expr_stmt|;
name|file
operator|.
name|flush
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|free
operator|==
name|storage1
operator|.
name|bytesFree
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|free
operator|==
name|storage2
operator|.
name|bytesFree
argument_list|()
argument_list|)
expr_stmt|;
name|storage2
operator|.
name|refresh
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|storage1
operator|==
name|storage2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|free
operator|!=
name|storage2
operator|.
name|bytesFree
argument_list|()
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
argument|tst_QStorageInfo
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qstorageinfo.moc"
end_include
end_unit
