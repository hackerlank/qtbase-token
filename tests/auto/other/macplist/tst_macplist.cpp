begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDir>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFile>
end_include
begin_include
include|#
directive|include
file|<QtCore/QProcess>
end_include
begin_class
DECL|class|tst_MacPlist
class|class
name|tst_MacPlist
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_MacPlist
name|tst_MacPlist
parameter_list|()
block|{}
private|private
name|slots
private|:
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|void
name|test_plist_data
parameter_list|()
function_decl|;
name|void
name|test_plist
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
class|;
end_class
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_MAC
end_ifdef
begin_function
DECL|function|test_plist_data
name|void
name|tst_MacPlist
operator|::
name|test_plist_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"test_plist"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"control"
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
literal|"<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
literal|"<plist version=\"1.0\">\n"
literal|"<dict>\n"
literal|"<key>CFBundleIconFile</key>\n"
literal|"<string></string>\n"
literal|"<key>CFBundlePackageType</key>\n"
literal|"<string>APPL</string>\n"
literal|"<key>CFBundleGetInfoString</key>\n"
literal|"<string>Created by Qt/QMake</string>\n"
literal|"<key>CFBundleExecutable</key>\n"
literal|"<string>app</string>\n"
literal|"<key>CFBundleIdentifier</key>\n"
literal|"<string>com.yourcompany.app</string>\n"
literal|"</dict>\n"
literal|"</plist>\n"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"LSUIElement-as-string"
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
literal|"<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
literal|"<plist version=\"1.0\">\n"
literal|"<dict>\n"
literal|"<key>CFBundleIconFile</key>\n"
literal|"<string></string>\n"
literal|"<key>CFBundlePackageType</key>\n"
literal|"<string>APPL</string>\n"
literal|"<key>CFBundleGetInfoString</key>\n"
literal|"<string>Created by Qt/QMake</string>\n"
literal|"<key>CFBundleExecutable</key>\n"
literal|"<string>app</string>\n"
literal|"<key>CFBundleIdentifier</key>\n"
literal|"<string>com.yourcompany.app</string>\n"
literal|"<key>LSUIElement</key>\n"
literal|"<string>false</string>\n"
literal|"</dict>\n"
literal|"</plist>\n"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"LSUIElement-as-bool"
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
literal|"<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
literal|"<plist version=\"1.0\">\n"
literal|"<dict>\n"
literal|"<key>CFBundleIconFile</key>\n"
literal|"<string></string>\n"
literal|"<key>CFBundlePackageType</key>\n"
literal|"<string>APPL</string>\n"
literal|"<key>CFBundleGetInfoString</key>\n"
literal|"<string>Created by Qt/QMake</string>\n"
literal|"<key>CFBundleExecutable</key>\n"
literal|"<string>app</string>\n"
literal|"<key>CFBundleIdentifier</key>\n"
literal|"<string>com.yourcompany.app</string>\n"
literal|"<key>LSUIElement</key>\n"
literal|"<false/>\n"
literal|"</dict>\n"
literal|"</plist>\n"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"LSUIElement-as-int"
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
literal|"<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
literal|"<plist version=\"1.0\">\n"
literal|"<dict>\n"
literal|"<key>CFBundleIconFile</key>\n"
literal|"<string></string>\n"
literal|"<key>CFBundlePackageType</key>\n"
literal|"<string>APPL</string>\n"
literal|"<key>CFBundleGetInfoString</key>\n"
literal|"<string>Created by Qt/QMake</string>\n"
literal|"<key>CFBundleExecutable</key>\n"
literal|"<string>app</string>\n"
literal|"<key>CFBundleIdentifier</key>\n"
literal|"<string>com.yourcompany.app</string>\n"
literal|"<key>LSUIElement</key>\n"
literal|"<real>0</real>\n"
literal|"</dict>\n"
literal|"</plist>\n"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"LSUIElement-as-garbage"
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
literal|"<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
literal|"<plist version=\"1.0\">\n"
literal|"<dict>\n"
literal|"<key>CFBundleIconFile</key>\n"
literal|"<string></string>\n"
literal|"<key>CFBundlePackageType</key>\n"
literal|"<string>APPL</string>\n"
literal|"<key>CFBundleGetInfoString</key>\n"
literal|"<string>Created by Qt/QMake</string>\n"
literal|"<key>CFBundleExecutable</key>\n"
literal|"<string>app</string>\n"
literal|"<key>CFBundleIdentifier</key>\n"
literal|"<string>com.yourcompany.app</string>\n"
literal|"<key>LSUIElement</key>\n"
literal|"<badkey>0</badkey>\n"
literal|"</dict>\n"
literal|"</plist>\n"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|test_plist
name|void
name|tst_MacPlist
operator|::
name|test_plist
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|test_plist
argument_list|)
expr_stmt|;
name|QString
name|infoPlist
init|=
name|QLatin1String
argument_list|(
literal|"Info.plist"
argument_list|)
decl_stmt|;
name|QDir
name|dir
argument_list|(
name|QCoreApplication
operator|::
name|applicationDirPath
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|cdUp
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|cdUp
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|cdUp
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|cd
argument_list|(
name|QLatin1String
argument_list|(
literal|"app"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|cd
argument_list|(
name|QLatin1String
argument_list|(
literal|"app.app"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|cd
argument_list|(
name|QLatin1String
argument_list|(
literal|"Contents"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|exists
argument_list|(
name|infoPlist
argument_list|)
argument_list|)
expr_stmt|;
block|{
name|QFile
name|file
argument_list|(
name|dir
operator|.
name|filePath
argument_list|(
name|infoPlist
argument_list|)
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
name|QByteArray
name|ba
init|=
name|test_plist
operator|.
name|toUtf8
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|file
operator|.
name|write
argument_list|(
name|ba
argument_list|)
argument_list|,
name|qint64
argument_list|(
name|ba
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|dir
operator|.
name|cd
argument_list|(
name|QLatin1String
argument_list|(
literal|"MacOS"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|exists
argument_list|(
name|QLatin1String
argument_list|(
literal|"app"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QProcess
name|process
decl_stmt|;
name|process
operator|.
name|start
argument_list|(
name|dir
operator|.
name|filePath
argument_list|(
literal|"app"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|process
operator|.
name|waitForFinished
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|process
operator|.
name|exitStatus
argument_list|()
argument_list|,
name|QProcess
operator|::
name|NormalExit
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
argument|tst_MacPlist
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_macplist.moc"
end_include
end_unit
