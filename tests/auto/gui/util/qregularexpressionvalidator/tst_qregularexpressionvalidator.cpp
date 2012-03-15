begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Giuseppe D'Angelo<giuseppe.dangelo@kdab.com> ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/QRegularExpressionValidator>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_QRegularExpressionValidator
class|class
name|tst_QRegularExpressionValidator
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|validate_data
parameter_list|()
function_decl|;
name|void
name|validate
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QValidator::State
argument_list|)
end_macro
begin_function
DECL|function|validate_data
name|void
name|tst_QRegularExpressionValidator
operator|::
name|validate_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QRegularExpression
argument_list|>
argument_list|(
literal|"re"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"value"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QValidator
operator|::
name|State
argument_list|>
argument_list|(
literal|"state"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|(
literal|"[1-9]\\d{0,3}"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"0"
argument_list|)
operator|<<
name|QValidator
operator|::
name|Invalid
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|(
literal|"[1-9]\\d{0,3}"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"12345"
argument_list|)
operator|<<
name|QValidator
operator|::
name|Invalid
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data2"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|(
literal|"[1-9]\\d{0,3}"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"1"
argument_list|)
operator|<<
name|QValidator
operator|::
name|Acceptable
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|(
literal|"\\S+"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"myfile.txt"
argument_list|)
operator|<<
name|QValidator
operator|::
name|Acceptable
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data4"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|(
literal|"\\S+"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"my file.txt"
argument_list|)
operator|<<
name|QValidator
operator|::
name|Invalid
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data5"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|(
literal|"[A-C]\\d{5}[W-Z]"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"a12345Z"
argument_list|)
operator|<<
name|QValidator
operator|::
name|Invalid
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data6"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|(
literal|"[A-C]\\d{5}[W-Z]"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"A12345Z"
argument_list|)
operator|<<
name|QValidator
operator|::
name|Acceptable
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data7"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|(
literal|"[A-C]\\d{5}[W-Z]"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"B12"
argument_list|)
operator|<<
name|QValidator
operator|::
name|Intermediate
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data8"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|(
literal|"read\\S?me(\\.(txt|asc|1st))?"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"readme"
argument_list|)
operator|<<
name|QValidator
operator|::
name|Acceptable
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data9"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|(
literal|"read\\S?me(\\.(txt|asc|1st))?"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"read me.txt"
argument_list|)
operator|<<
name|QValidator
operator|::
name|Invalid
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data10"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|(
literal|"read\\S?me(\\.(txt|asc|1st))?"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"readm"
argument_list|)
operator|<<
name|QValidator
operator|::
name|Intermediate
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data11"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|(
literal|"read\\S?me(\\.(txt|asc|1st))?"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"read me.txt"
argument_list|)
operator|<<
name|QValidator
operator|::
name|Invalid
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data12"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|(
literal|"read\\S?me(\\.(txt|asc|1st))?"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"readm"
argument_list|)
operator|<<
name|QValidator
operator|::
name|Intermediate
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data13"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|(
literal|"\\w\\d\\d"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"A57"
argument_list|)
operator|<<
name|QValidator
operator|::
name|Acceptable
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data14"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|(
literal|"\\w\\d\\d"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"E5"
argument_list|)
operator|<<
name|QValidator
operator|::
name|Intermediate
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data15"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|(
literal|"\\w\\d\\d"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"+9"
argument_list|)
operator|<<
name|QValidator
operator|::
name|Invalid
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty01"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|()
operator|<<
name|QString
argument_list|()
operator|<<
name|QValidator
operator|::
name|Acceptable
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty02"
argument_list|)
operator|<<
name|QRegularExpression
argument_list|()
operator|<<
name|QString
argument_list|(
literal|"test"
argument_list|)
operator|<<
name|QValidator
operator|::
name|Acceptable
expr_stmt|;
block|}
end_function
begin_function
DECL|function|validate
name|void
name|tst_QRegularExpressionValidator
operator|::
name|validate
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QRegularExpression
argument_list|,
name|re
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|QRegularExpressionValidator
name|rv
decl_stmt|;
comment|// setting the same regexp won't emit signals
specifier|const
name|int
name|signalCount
init|=
operator|(
name|rv
operator|.
name|regularExpression
argument_list|()
operator|==
name|re
operator|)
condition|?
literal|0
else|:
literal|1
decl_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|rv
argument_list|,
name|SIGNAL
argument_list|(
name|regularExpressionChanged
argument_list|(
name|QRegularExpression
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|changedSpy
argument_list|(
operator|&
name|rv
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|rv
operator|.
name|setRegularExpression
argument_list|(
name|re
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rv
operator|.
name|regularExpression
argument_list|()
argument_list|,
name|re
argument_list|)
expr_stmt|;
name|int
name|pos
init|=
operator|-
literal|1
decl_stmt|;
name|QValidator
operator|::
name|State
name|result
init|=
name|rv
operator|.
name|validate
argument_list|(
name|value
argument_list|,
name|pos
argument_list|)
decl_stmt|;
name|QTEST
argument_list|(
name|result
argument_list|,
literal|"state"
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|==
name|QValidator
operator|::
name|Invalid
condition|)
name|QCOMPARE
argument_list|(
name|pos
argument_list|,
name|value
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|QCOMPARE
argument_list|(
name|pos
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// ensure pos is not modified if validate returned Acceptable or Intermediate
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
name|signalCount
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|changedSpy
operator|.
name|count
argument_list|()
argument_list|,
name|signalCount
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_GUILESS_MAIN
argument_list|(
argument|tst_QRegularExpressionValidator
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qregularexpressionvalidator.moc"
end_include
end_unit
