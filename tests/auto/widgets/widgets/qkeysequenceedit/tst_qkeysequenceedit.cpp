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
file|<QKeySequenceEdit>
end_include
begin_include
include|#
directive|include
file|<QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Qt::Key
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Qt::KeyboardModifiers
argument_list|)
end_macro
begin_class
DECL|class|tst_QKeySequenceEdit
class|class
name|tst_QKeySequenceEdit
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|testSetters
parameter_list|()
function_decl|;
name|void
name|testKeys_data
parameter_list|()
function_decl|;
name|void
name|testKeys
parameter_list|()
function_decl|;
name|void
name|testLineEditContents
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|testSetters
name|void
name|tst_QKeySequenceEdit
operator|::
name|testSetters
parameter_list|()
block|{
name|QKeySequenceEdit
name|edit
decl_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|edit
argument_list|,
name|SIGNAL
argument_list|(
name|keySequenceChanged
argument_list|(
name|QKeySequence
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|edit
operator|.
name|keySequence
argument_list|()
argument_list|,
name|QKeySequence
argument_list|()
argument_list|)
expr_stmt|;
name|edit
operator|.
name|setKeySequence
argument_list|(
name|QKeySequence
operator|::
name|New
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit
operator|.
name|keySequence
argument_list|()
argument_list|,
name|QKeySequence
argument_list|(
name|QKeySequence
operator|::
name|New
argument_list|)
argument_list|)
expr_stmt|;
name|edit
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit
operator|.
name|keySequence
argument_list|()
argument_list|,
name|QKeySequence
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testKeys_data
name|void
name|tst_QKeySequenceEdit
operator|::
name|testKeys_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|Qt
operator|::
name|Key
argument_list|>
argument_list|(
literal|"key"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|Qt
operator|::
name|KeyboardModifiers
argument_list|>
argument_list|(
literal|"modifiers"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QKeySequence
argument_list|>
argument_list|(
literal|"keySequence"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1"
argument_list|)
operator|<<
name|Qt
operator|::
name|Key_N
operator|<<
name|Qt
operator|::
name|KeyboardModifiers
argument_list|(
name|Qt
operator|::
name|ControlModifier
argument_list|)
operator|<<
name|QKeySequence
argument_list|(
literal|"Ctrl+N"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2"
argument_list|)
operator|<<
name|Qt
operator|::
name|Key_N
operator|<<
name|Qt
operator|::
name|KeyboardModifiers
argument_list|(
name|Qt
operator|::
name|AltModifier
argument_list|)
operator|<<
name|QKeySequence
argument_list|(
literal|"Alt+N"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"3"
argument_list|)
operator|<<
name|Qt
operator|::
name|Key_N
operator|<<
name|Qt
operator|::
name|KeyboardModifiers
argument_list|(
name|Qt
operator|::
name|ShiftModifier
argument_list|)
operator|<<
name|QKeySequence
argument_list|(
literal|"Shift+N"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"4"
argument_list|)
operator|<<
name|Qt
operator|::
name|Key_N
operator|<<
name|Qt
operator|::
name|KeyboardModifiers
argument_list|(
name|Qt
operator|::
name|ControlModifier
operator||
name|Qt
operator|::
name|ShiftModifier
argument_list|)
operator|<<
name|QKeySequence
argument_list|(
literal|"Ctrl+Shift+N"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testKeys
name|void
name|tst_QKeySequenceEdit
operator|::
name|testKeys
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|Qt
operator|::
name|Key
argument_list|,
name|key
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|Qt
operator|::
name|KeyboardModifiers
argument_list|,
name|modifiers
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QKeySequence
argument_list|,
name|keySequence
argument_list|)
expr_stmt|;
name|QKeySequenceEdit
name|edit
decl_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|edit
argument_list|,
name|SIGNAL
argument_list|(
name|editingFinished
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|keyPress
argument_list|(
operator|&
name|edit
argument_list|,
name|key
argument_list|,
name|modifiers
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyRelease
argument_list|(
operator|&
name|edit
argument_list|,
name|key
argument_list|,
name|modifiers
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit
operator|.
name|keySequence
argument_list|()
argument_list|,
name|keySequence
argument_list|)
expr_stmt|;
name|QTRY_COMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testLineEditContents
name|void
name|tst_QKeySequenceEdit
operator|::
name|testLineEditContents
parameter_list|()
block|{
name|QKeySequenceEdit
name|edit
decl_stmt|;
name|QLineEdit
modifier|*
name|le
init|=
name|edit
operator|.
name|findChild
argument_list|<
name|QLineEdit
operator|*
argument_list|>
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|le
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|le
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|edit
operator|.
name|setKeySequence
argument_list|(
name|QKeySequence
operator|::
name|New
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit
operator|.
name|keySequence
argument_list|()
argument_list|,
name|QKeySequence
argument_list|(
name|QKeySequence
operator|::
name|New
argument_list|)
argument_list|)
expr_stmt|;
name|edit
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|le
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|edit
operator|.
name|setKeySequence
argument_list|(
name|QKeySequence
operator|::
name|New
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|le
operator|->
name|text
argument_list|()
operator|!=
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|edit
operator|.
name|setKeySequence
argument_list|(
name|QKeySequence
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|le
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QKeySequenceEdit
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qkeysequenceedit.moc"
end_include
end_unit
