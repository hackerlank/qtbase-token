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
file|<qfileiconprovider.h>
end_include
begin_include
include|#
directive|include
file|<qfileinfo.h>
end_include
begin_class
DECL|class|tst_QFileIconProvider
class|class
name|tst_QFileIconProvider
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
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
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|qfileiconprovider_data
parameter_list|()
function_decl|;
name|void
name|qfileiconprovider
parameter_list|()
function_decl|;
name|void
name|iconType_data
parameter_list|()
function_decl|;
name|void
name|iconType
parameter_list|()
function_decl|;
name|void
name|iconInfo_data
parameter_list|()
function_decl|;
name|void
name|iconInfo
parameter_list|()
function_decl|;
name|void
name|type_data
parameter_list|()
function_decl|;
name|void
name|type
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|// Subclass that exposes the protected functions.
end_comment
begin_class
DECL|class|SubQFileIconProvider
class|class
name|SubQFileIconProvider
super|:
specifier|public
name|QFileIconProvider
block|{
public|public:
block|}
class|;
end_class
begin_comment
comment|// This will be called before the first test function is executed.
end_comment
begin_comment
comment|// It is only called once.
end_comment
begin_function
DECL|function|initTestCase
name|void
name|tst_QFileIconProvider
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_comment
comment|// This will be called after the last test function is executed.
end_comment
begin_comment
comment|// It is only called once.
end_comment
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QFileIconProvider
operator|::
name|cleanupTestCase
parameter_list|()
block|{ }
end_function
begin_comment
comment|// This will be called before each test function is executed.
end_comment
begin_function
DECL|function|init
name|void
name|tst_QFileIconProvider
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_comment
comment|// This will be called after every test function.
end_comment
begin_function
DECL|function|cleanup
name|void
name|tst_QFileIconProvider
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|qfileiconprovider_data
name|void
name|tst_QFileIconProvider
operator|::
name|qfileiconprovider_data
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|qfileiconprovider
name|void
name|tst_QFileIconProvider
operator|::
name|qfileiconprovider
parameter_list|()
block|{
comment|// don't crash
name|SubQFileIconProvider
name|provider
decl_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QFileIconProvider::IconType
argument_list|)
end_macro
begin_function
DECL|function|iconType_data
name|void
name|tst_QFileIconProvider
operator|::
name|iconType_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QFileIconProvider
operator|::
name|IconType
argument_list|>
argument_list|(
literal|"type"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"computer"
argument_list|)
operator|<<
name|QFileIconProvider
operator|::
name|Computer
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"desktop"
argument_list|)
operator|<<
name|QFileIconProvider
operator|::
name|Desktop
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"trashcan"
argument_list|)
operator|<<
name|QFileIconProvider
operator|::
name|Trashcan
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"network"
argument_list|)
operator|<<
name|QFileIconProvider
operator|::
name|Network
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"drive"
argument_list|)
operator|<<
name|QFileIconProvider
operator|::
name|Drive
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"folder"
argument_list|)
operator|<<
name|QFileIconProvider
operator|::
name|Folder
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"file"
argument_list|)
operator|<<
name|QFileIconProvider
operator|::
name|File
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QIcon icon(QFileIconProvider::IconType const& type) const
end_comment
begin_function
DECL|function|iconType
name|void
name|tst_QFileIconProvider
operator|::
name|iconType
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QFileIconProvider
operator|::
name|IconType
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|SubQFileIconProvider
name|provider
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|provider
operator|.
name|icon
argument_list|(
name|type
argument_list|)
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QFileInfo
argument_list|)
end_macro
begin_function
DECL|function|iconInfo_data
name|void
name|tst_QFileIconProvider
operator|::
name|iconInfo_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QFileInfo
argument_list|>
argument_list|(
literal|"info"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"setPath"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QFileInfo
argument_list|()
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"drive"
argument_list|)
operator|<<
name|QFileInfo
argument_list|(
name|QDir
operator|::
name|rootPath
argument_list|()
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"home"
argument_list|)
operator|<<
name|QFileInfo
argument_list|(
name|QDir
operator|::
name|homePath
argument_list|()
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"current"
argument_list|)
operator|<<
name|QFileInfo
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QIcon icon(QFileInfo const& info) const
end_comment
begin_function
DECL|function|iconInfo
name|void
name|tst_QFileIconProvider
operator|::
name|iconInfo
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QFileInfo
argument_list|,
name|info
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|setPath
argument_list|)
expr_stmt|;
if|if
condition|(
name|setPath
condition|)
name|QVERIFY
argument_list|(
name|info
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
name|SubQFileIconProvider
name|provider
decl_stmt|;
comment|// we should always get an icon
name|QVERIFY
argument_list|(
operator|!
name|provider
operator|.
name|icon
argument_list|(
name|info
argument_list|)
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|type_data
name|void
name|tst_QFileIconProvider
operator|::
name|type_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QFileInfo
argument_list|>
argument_list|(
literal|"info"
argument_list|)
expr_stmt|;
comment|// Return value is _very_ system dependent, hard to test
comment|// QTest::addColumn<QString>("type");
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QFileInfo
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"drive"
argument_list|)
operator|<<
name|QFileInfo
argument_list|(
name|QDir
operator|::
name|rootPath
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"home"
argument_list|)
operator|<<
name|QFileInfo
argument_list|(
name|QDir
operator|::
name|homePath
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"current"
argument_list|)
operator|<<
name|QFileInfo
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"exe"
argument_list|)
operator|<<
name|QFileInfo
argument_list|(
name|QCoreApplication
operator|::
name|applicationFilePath
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QString type(QFileInfo const& info) const
end_comment
begin_function
DECL|function|type
name|void
name|tst_QFileIconProvider
operator|::
name|type
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QFileInfo
argument_list|,
name|info
argument_list|)
expr_stmt|;
name|SubQFileIconProvider
name|provider
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|provider
operator|.
name|type
argument_list|(
name|info
argument_list|)
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QFileIconProvider
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qfileiconprovider.moc"
end_include
end_unit
