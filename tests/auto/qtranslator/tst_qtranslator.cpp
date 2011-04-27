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
file|<QWidget>
end_include
begin_include
include|#
directive|include
file|<qtranslator.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_class
DECL|class|tst_QTranslator
class|class
name|tst_QTranslator
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
name|tst_QTranslator
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QTranslator
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
protected|protected:
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
function_decl|;
private|private
name|slots
private|:
name|void
name|load
parameter_list|()
function_decl|;
name|void
name|load2
parameter_list|()
function_decl|;
name|void
name|threadLoad
parameter_list|()
function_decl|;
name|void
name|testLanguageChange
parameter_list|()
function_decl|;
name|void
name|plural
parameter_list|()
function_decl|;
name|void
name|translate_qm_file_generated_with_msgfmt
parameter_list|()
function_decl|;
name|void
name|loadFromResource
parameter_list|()
function_decl|;
name|void
name|loadDirectory
parameter_list|()
function_decl|;
private|private:
DECL|member|languageChangeEventCounter
name|int
name|languageChangeEventCounter
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QTranslator
name|tst_QTranslator
operator|::
name|tst_QTranslator
parameter_list|()
member_init_list|:
name|languageChangeEventCounter
argument_list|(
literal|0
argument_list|)
block|{
name|show
argument_list|()
expr_stmt|;
name|hide
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~tst_QTranslator
name|tst_QTranslator
operator|::
name|~
name|tst_QTranslator
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|init
name|void
name|tst_QTranslator
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QTranslator
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|event
name|bool
name|tst_QTranslator
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|LanguageChange
condition|)
operator|++
name|languageChangeEventCounter
expr_stmt|;
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|load
name|void
name|tst_QTranslator
operator|::
name|load
parameter_list|()
block|{
name|QTranslator
name|tor
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|tor
operator|.
name|load
argument_list|(
literal|"hellotr_la"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|tor
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tor
operator|.
name|translate
argument_list|(
literal|"QPushButton"
argument_list|,
literal|"Hello world!"
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Hallo Welt!"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|load2
name|void
name|tst_QTranslator
operator|::
name|load2
parameter_list|()
block|{
name|QTranslator
name|tor
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QFile
name|file
argument_list|(
literal|"hellotr_la.qm"
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
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
name|tor
operator|.
name|load
argument_list|(
operator|(
specifier|const
name|uchar
operator|*
operator|)
name|data
operator|.
name|constData
argument_list|()
argument_list|,
name|data
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|tor
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tor
operator|.
name|translate
argument_list|(
literal|"QPushButton"
argument_list|,
literal|"Hello world!"
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Hallo Welt!"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|TranslatorThread
class|class
name|TranslatorThread
super|:
specifier|public
name|QThread
block|{
DECL|function|run
name|void
name|run
parameter_list|()
block|{
name|QTranslator
name|tor
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|tor
operator|.
name|load
argument_list|(
literal|"hellotr_la"
argument_list|)
expr_stmt|;
if|if
condition|(
name|tor
operator|.
name|isEmpty
argument_list|()
condition|)
name|qFatal
argument_list|(
literal|"Could not load translation"
argument_list|)
expr_stmt|;
if|if
condition|(
name|tor
operator|.
name|translate
argument_list|(
literal|"QPushButton"
argument_list|,
literal|"Hello world!"
argument_list|)
operator|!=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Hallo Welt!"
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"Test string was not translated correctlys"
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|threadLoad
name|void
name|tst_QTranslator
operator|::
name|threadLoad
parameter_list|()
block|{
name|TranslatorThread
name|thread
decl_stmt|;
name|thread
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|thread
operator|.
name|wait
argument_list|(
literal|10
operator|*
literal|1000
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testLanguageChange
name|void
name|tst_QTranslator
operator|::
name|testLanguageChange
parameter_list|()
block|{
name|languageChangeEventCounter
operator|=
literal|0
expr_stmt|;
name|QTranslator
modifier|*
name|tor
init|=
operator|new
name|QTranslator
decl_stmt|;
name|tor
operator|->
name|load
argument_list|(
literal|"hellotr_la.qm"
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|languageChangeEventCounter
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|tor
operator|->
name|load
argument_list|(
literal|"doesn't exist, same as clearing"
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|languageChangeEventCounter
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|tor
operator|->
name|load
argument_list|(
literal|"hellotr_la.qm"
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|languageChangeEventCounter
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|installTranslator
argument_list|(
name|tor
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|languageChangeEventCounter
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|tor
operator|->
name|load
argument_list|(
literal|"doesn't exist, same as clearing"
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|languageChangeEventCounter
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|tor
operator|->
name|load
argument_list|(
literal|"hellotr_la.qm"
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|languageChangeEventCounter
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|removeTranslator
argument_list|(
name|tor
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|languageChangeEventCounter
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|tor
operator|->
name|load
argument_list|(
literal|"doesn't exist, same as clearing"
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|languageChangeEventCounter
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|installTranslator
argument_list|(
name|tor
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|languageChangeEventCounter
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|tor
operator|->
name|load
argument_list|(
literal|"hellotr_la.qm"
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|languageChangeEventCounter
argument_list|,
literal|5
argument_list|)
expr_stmt|;
operator|delete
name|tor
expr_stmt|;
name|tor
operator|=
literal|0
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|languageChangeEventCounter
argument_list|,
literal|6
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|plural
name|void
name|tst_QTranslator
operator|::
name|plural
parameter_list|()
block|{
name|QTranslator
name|tor
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|tor
operator|.
name|load
argument_list|(
literal|"hellotr_la"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|tor
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|installTranslator
argument_list|(
operator|&
name|tor
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|Encoding
name|e
init|=
name|QCoreApplication
operator|::
name|UnicodeUTF8
decl_stmt|;
name|QCOMPARE
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QPushButton"
argument_list|,
literal|"Hello %n world(s)!"
argument_list|,
literal|0
argument_list|,
name|e
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Hallo 0 Welten!"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QPushButton"
argument_list|,
literal|"Hello %n world(s)!"
argument_list|,
literal|0
argument_list|,
name|e
argument_list|,
literal|1
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Hallo 1 Welt!"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QPushButton"
argument_list|,
literal|"Hello %n world(s)!"
argument_list|,
literal|0
argument_list|,
name|e
argument_list|,
literal|2
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Hallo 2 Welten!"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|translate_qm_file_generated_with_msgfmt
name|void
name|tst_QTranslator
operator|::
name|translate_qm_file_generated_with_msgfmt
parameter_list|()
block|{
name|QTranslator
name|translator
decl_stmt|;
name|translator
operator|.
name|load
argument_list|(
literal|"msgfmt_from_po"
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|installTranslator
argument_list|(
operator|&
name|translator
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|""
argument_list|,
literal|"Intro"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"Einleitung"
argument_list|)
argument_list|)
expr_stmt|;
comment|// The file is converted from a po file, thus it does not have any context info.
comment|// The following should then not be translated
name|QCOMPARE
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"contekst"
argument_list|,
literal|"Intro"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"Intro"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"contekst"
argument_list|,
literal|"Intro\0\0"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"Intro"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"contekst"
argument_list|,
literal|"Intro\0x"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"Intro"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|""
argument_list|,
literal|"Intro\0\0"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"Einleitung"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|""
argument_list|,
literal|"Intro\0x"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"Einleitung"
argument_list|)
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|removeTranslator
argument_list|(
operator|&
name|translator
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loadFromResource
name|void
name|tst_QTranslator
operator|::
name|loadFromResource
parameter_list|()
block|{
name|QTranslator
name|tor
decl_stmt|;
name|tor
operator|.
name|load
argument_list|(
literal|":/tst_qtranslator/hellotr_la.qm"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|tor
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tor
operator|.
name|translate
argument_list|(
literal|"QPushButton"
argument_list|,
literal|"Hello world!"
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Hallo Welt!"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loadDirectory
name|void
name|tst_QTranslator
operator|::
name|loadDirectory
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|QFileInfo
argument_list|(
literal|"../qtranslator"
argument_list|)
operator|.
name|isDir
argument_list|()
argument_list|)
expr_stmt|;
name|QTranslator
name|tor
decl_stmt|;
name|tor
operator|.
name|load
argument_list|(
literal|"qtranslator"
argument_list|,
literal|".."
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|tor
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
argument|tst_QTranslator
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtranslator.moc"
end_include
end_unit
