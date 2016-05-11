begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<qfontdatabase.h>
end_include
begin_include
include|#
directive|include
file|<qfontinfo.h>
end_include
begin_include
include|#
directive|include
file|<qtimer.h>
end_include
begin_include
include|#
directive|include
file|<qmainwindow.h>
end_include
begin_include
include|#
directive|include
file|<qlistview.h>
end_include
begin_include
include|#
directive|include
file|"qfontdialog.h"
end_include
begin_include
include|#
directive|include
file|<private/qfontdialog_p.h>
end_include
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QtTestEventThread
argument_list|)
end_macro
begin_class
DECL|class|tst_QFontDialog
class|class
name|tst_QFontDialog
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QFontDialog
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QFontDialog
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|postKeyReturn
parameter_list|()
function_decl|;
name|void
name|testGetFont
parameter_list|()
function_decl|;
name|void
name|testSetFont
parameter_list|()
function_decl|;
name|void
name|testNonStandardFontSize
parameter_list|()
function_decl|;
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
name|defaultOkButton
parameter_list|()
function_decl|;
name|void
name|setFont
parameter_list|()
function_decl|;
name|void
name|task256466_wrongStyle
parameter_list|()
function_decl|;
name|void
name|setNonStandardFontSize
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_STYLE_STYLESHEET
name|void
name|qtbug_41513_stylesheetStyle
parameter_list|()
function_decl|;
endif|#
directive|endif
private|private:
name|void
name|runSlotWithFailsafeTimer
parameter_list|(
specifier|const
name|char
modifier|*
name|member
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QFontDialog
name|tst_QFontDialog
operator|::
name|tst_QFontDialog
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QFontDialog
name|tst_QFontDialog
operator|::
name|~
name|tst_QFontDialog
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QFontDialog
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QFontDialog
operator|::
name|cleanupTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|init
name|void
name|tst_QFontDialog
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QFontDialog
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|postKeyReturn
name|void
name|tst_QFontDialog
operator|::
name|postKeyReturn
parameter_list|()
block|{
name|QWidgetList
name|list
init|=
name|QApplication
operator|::
name|topLevelWidgets
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
name|list
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QFontDialog
modifier|*
name|dialog
init|=
name|qobject_cast
argument_list|<
name|QFontDialog
operator|*
argument_list|>
argument_list|(
name|list
index|[
name|i
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|dialog
condition|)
block|{
name|QTest
operator|::
name|keyClick
argument_list|(
name|list
index|[
name|i
index|]
argument_list|,
name|Qt
operator|::
name|Key_Return
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
block|}
end_function
begin_function
DECL|function|testGetFont
name|void
name|tst_QFontDialog
operator|::
name|testGetFont
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"Sending QTest::keyClick to OSX font dialog helper fails, see QTBUG-24321"
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|bool
name|ok
init|=
literal|false
decl_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|2000
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|postKeyReturn
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QFontDialog
operator|::
name|getFont
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|ok
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|runSlotWithFailsafeTimer
name|void
name|tst_QFontDialog
operator|::
name|runSlotWithFailsafeTimer
parameter_list|(
specifier|const
name|char
modifier|*
name|member
parameter_list|)
block|{
comment|// FailSafeTimer quits the nested event loop if the dialog closing doesn't do it.
name|QTimer
name|failSafeTimer
decl_stmt|;
name|failSafeTimer
operator|.
name|setInterval
argument_list|(
literal|4000
argument_list|)
expr_stmt|;
name|failSafeTimer
operator|.
name|setSingleShot
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|failSafeTimer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|failSafeTimer
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
name|this
argument_list|,
name|member
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|exec
argument_list|()
expr_stmt|;
comment|// FailSafeTimer stops once it goes out of scope.
block|}
end_function
begin_function
DECL|function|defaultOkButton
name|void
name|tst_QFontDialog
operator|::
name|defaultOkButton
parameter_list|()
block|{
name|runSlotWithFailsafeTimer
argument_list|(
name|SLOT
argument_list|(
name|testGetFont
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testSetFont
name|void
name|tst_QFontDialog
operator|::
name|testSetFont
parameter_list|()
block|{
name|bool
name|ok
init|=
literal|false
decl_stmt|;
if|#
directive|if
name|defined
name|Q_OS_HPUX
name|QString
name|fontName
init|=
literal|"Courier"
decl_stmt|;
name|int
name|fontSize
init|=
literal|25
decl_stmt|;
elif|#
directive|elif
name|defined
name|Q_OS_AIX
name|QString
name|fontName
init|=
literal|"Charter"
decl_stmt|;
name|int
name|fontSize
init|=
literal|13
decl_stmt|;
else|#
directive|else
name|QString
name|fontName
init|=
literal|"Arial"
decl_stmt|;
name|int
name|fontSize
init|=
literal|24
decl_stmt|;
endif|#
directive|endif
name|QFont
name|f1
argument_list|(
name|fontName
argument_list|,
name|fontSize
argument_list|)
decl_stmt|;
name|f1
operator|.
name|setPixelSize
argument_list|(
name|QFontInfo
argument_list|(
name|f1
argument_list|)
operator|.
name|pixelSize
argument_list|()
argument_list|)
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|2000
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|postKeyReturn
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QFont
name|f2
init|=
name|QFontDialog
operator|::
name|getFont
argument_list|(
operator|&
name|ok
argument_list|,
name|f1
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|QFontInfo
argument_list|(
name|f2
argument_list|)
operator|.
name|pointSize
argument_list|()
argument_list|,
name|QFontInfo
argument_list|(
name|f1
argument_list|)
operator|.
name|pointSize
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setFont
name|void
name|tst_QFontDialog
operator|::
name|setFont
parameter_list|()
block|{
comment|/* The font should be the same before as it is after if nothing changed               while the font dialog was open.               Task #27662     */
name|runSlotWithFailsafeTimer
argument_list|(
name|SLOT
argument_list|(
name|testSetFont
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|FriendlyFontDialog
class|class
name|FriendlyFontDialog
super|:
specifier|public
name|QFontDialog
block|{
friend|friend
class_decl|class
name|tst_QFontDialog
class_decl|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QFontDialog
argument_list|)
block|}
class|;
end_class
begin_function
DECL|function|task256466_wrongStyle
name|void
name|tst_QFontDialog
operator|::
name|task256466_wrongStyle
parameter_list|()
block|{
name|QFontDatabase
name|fdb
decl_stmt|;
name|FriendlyFontDialog
name|dialog
decl_stmt|;
name|dialog
operator|.
name|setOption
argument_list|(
name|QFontDialog
operator|::
name|DontUseNativeDialog
argument_list|)
expr_stmt|;
name|QListView
modifier|*
name|familyList
init|=
cast|reinterpret_cast
argument_list|<
name|QListView
operator|*
argument_list|>
argument_list|(
name|dialog
operator|.
name|d_func
argument_list|()
operator|->
name|familyList
argument_list|)
decl_stmt|;
name|QListView
modifier|*
name|styleList
init|=
cast|reinterpret_cast
argument_list|<
name|QListView
operator|*
argument_list|>
argument_list|(
name|dialog
operator|.
name|d_func
argument_list|()
operator|->
name|styleList
argument_list|)
decl_stmt|;
name|QListView
modifier|*
name|sizeList
init|=
cast|reinterpret_cast
argument_list|<
name|QListView
operator|*
argument_list|>
argument_list|(
name|dialog
operator|.
name|d_func
argument_list|()
operator|->
name|sizeList
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
name|familyList
operator|->
name|model
argument_list|()
operator|->
name|rowCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QModelIndex
name|currentFamily
init|=
name|familyList
operator|->
name|model
argument_list|()
operator|->
name|index
argument_list|(
name|i
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|familyList
operator|->
name|setCurrentIndex
argument_list|(
name|currentFamily
argument_list|)
expr_stmt|;
name|int
name|expectedSize
init|=
name|sizeList
operator|->
name|currentIndex
argument_list|()
operator|.
name|data
argument_list|()
operator|.
name|toInt
argument_list|()
decl_stmt|;
specifier|const
name|QFont
name|current
init|=
name|dialog
operator|.
name|currentFont
argument_list|()
decl_stmt|,
name|expected
init|=
name|fdb
operator|.
name|font
argument_list|(
name|currentFamily
operator|.
name|data
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|,
name|styleList
operator|->
name|currentIndex
argument_list|()
operator|.
name|data
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|,
name|expectedSize
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|current
operator|.
name|family
argument_list|()
argument_list|,
name|expected
operator|.
name|family
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|current
operator|.
name|style
argument_list|()
argument_list|,
name|expected
operator|.
name|style
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|expectedSize
operator|==
literal|0
operator|&&
operator|!
name|QFontDatabase
argument_list|()
operator|.
name|isScalable
argument_list|(
name|current
operator|.
name|family
argument_list|()
argument_list|,
name|current
operator|.
name|styleName
argument_list|()
argument_list|)
condition|)
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"QTBUG-53299: Smooth sizes for unscalable font contains unsupported size"
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|current
operator|.
name|pointSizeF
argument_list|()
argument_list|,
name|expected
operator|.
name|pointSizeF
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setNonStandardFontSize
name|void
name|tst_QFontDialog
operator|::
name|setNonStandardFontSize
parameter_list|()
block|{
name|runSlotWithFailsafeTimer
argument_list|(
name|SLOT
argument_list|(
name|testNonStandardFontSize
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_STYLESHEET
end_ifndef
begin_decl_stmt
DECL|variable|offendingStyleSheet
specifier|static
specifier|const
name|QString
name|offendingStyleSheet
init|=
name|QStringLiteral
argument_list|(
literal|"* { font-family: \"QtBidiTestFont\"; }"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qtbug_41513_stylesheetStyle
name|void
name|tst_QFontDialog
operator|::
name|qtbug_41513_stylesheetStyle
parameter_list|()
block|{
if|if
condition|(
name|QFontDatabase
operator|::
name|addApplicationFont
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"test.ttf"
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
name|QSKIP
argument_list|(
literal|"Test fonts not found."
argument_list|)
expr_stmt|;
if|if
condition|(
name|QFontDatabase
operator|::
name|addApplicationFont
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"testfont.ttf"
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
name|QSKIP
argument_list|(
literal|"Test fonts not found."
argument_list|)
expr_stmt|;
name|QFont
name|testFont
init|=
name|QFont
argument_list|(
name|QStringLiteral
argument_list|(
literal|"QtsSpecialTestFont"
argument_list|)
argument_list|)
decl_stmt|;
name|qApp
operator|->
name|setStyleSheet
argument_list|(
name|offendingStyleSheet
argument_list|)
expr_stmt|;
name|bool
name|accepted
init|=
literal|false
decl_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|2000
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|postKeyReturn
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QFont
name|resultFont
init|=
name|QFontDialog
operator|::
name|getFont
argument_list|(
operator|&
name|accepted
argument_list|,
name|testFont
argument_list|,
name|QApplication
operator|::
name|activeWindow
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|"QFontDialog - Stylesheet Test"
argument_list|)
argument_list|,
name|QFontDialog
operator|::
name|DontUseNativeDialog
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|accepted
argument_list|)
expr_stmt|;
comment|// The fontdialog sets the styleName, when the fontdatabase knows the style name.
name|resultFont
operator|.
name|setStyleName
argument_list|(
name|testFont
operator|.
name|styleName
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|resultFont
argument_list|,
name|testFont
argument_list|)
expr_stmt|;
comment|// reset stylesheet
name|qApp
operator|->
name|setStyleSheet
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STYLE_STYLESHEET
end_comment
begin_function
DECL|function|testNonStandardFontSize
name|void
name|tst_QFontDialog
operator|::
name|testNonStandardFontSize
parameter_list|()
block|{
name|QList
argument_list|<
name|int
argument_list|>
name|standardSizesList
init|=
name|QFontDatabase
operator|::
name|standardSizes
argument_list|()
decl_stmt|;
name|int
name|nonStandardFontSize
decl_stmt|;
if|if
condition|(
operator|!
name|standardSizesList
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|nonStandardFontSize
operator|=
name|standardSizesList
operator|.
name|at
argument_list|(
name|standardSizesList
operator|.
name|count
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// get the maximum standard size.
name|nonStandardFontSize
operator|+=
literal|1
expr_stmt|;
comment|// the increment of 1 to mock a non-standard font size.
block|}
else|else
block|{
name|QSKIP
argument_list|(
literal|"QFontDatabase::standardSizes() is empty."
argument_list|)
expr_stmt|;
block|}
name|QFont
name|testFont
decl_stmt|;
name|testFont
operator|.
name|setPointSize
argument_list|(
name|nonStandardFontSize
argument_list|)
expr_stmt|;
name|bool
name|accepted
init|=
literal|false
decl_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|2000
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|postKeyReturn
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QFont
name|resultFont
init|=
name|QFontDialog
operator|::
name|getFont
argument_list|(
operator|&
name|accepted
argument_list|,
name|testFont
argument_list|,
name|QApplication
operator|::
name|activeWindow
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|"QFontDialog - NonStandardFontSize Test"
argument_list|)
argument_list|,
name|QFontDialog
operator|::
name|DontUseNativeDialog
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|accepted
argument_list|)
expr_stmt|;
if|if
condition|(
name|accepted
condition|)
name|QCOMPARE
argument_list|(
name|testFont
operator|.
name|pointSize
argument_list|()
argument_list|,
name|resultFont
operator|.
name|pointSize
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|QWARN
argument_list|(
literal|"Fail using a non-standard font size."
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QFontDialog
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qfontdialog.moc"
end_include
end_unit
