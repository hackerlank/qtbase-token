begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 David Faure<david.faure@kdab.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QIODevice>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QBuffer>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_class
DECL|class|tst_qtextstream
class|class
name|tst_qtextstream
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|writeSingleChar_data
parameter_list|()
function_decl|;
name|void
name|writeSingleChar
parameter_list|()
function_decl|;
private|private:
block|}
class|;
end_class
begin_enum
DECL|enum|Output
DECL|enumerator|StringOutput
DECL|enumerator|DeviceOutput
enum|enum
name|Output
block|{
name|StringOutput
block|,
name|DeviceOutput
block|}
enum|;
end_enum
begin_expr_stmt
DECL|variable|Output
name|Q_DECLARE_METATYPE
argument_list|(
name|Output
argument_list|)
expr_stmt|;
end_expr_stmt
begin_enum
DECL|enum|Input
DECL|enumerator|CharStarInput
DECL|enumerator|QStringInput
DECL|enumerator|CharInput
DECL|enumerator|QCharInput
enum|enum
name|Input
block|{
name|CharStarInput
block|,
name|QStringInput
block|,
name|CharInput
block|,
name|QCharInput
block|}
enum|;
end_enum
begin_expr_stmt
DECL|variable|Input
name|Q_DECLARE_METATYPE
argument_list|(
name|Input
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|writeSingleChar_data
name|void
name|tst_qtextstream
operator|::
name|writeSingleChar_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|Output
argument_list|>
argument_list|(
literal|"output"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|Input
argument_list|>
argument_list|(
literal|"input"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"string_charstar"
argument_list|)
operator|<<
name|StringOutput
operator|<<
name|CharStarInput
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"string_string"
argument_list|)
operator|<<
name|StringOutput
operator|<<
name|QStringInput
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"string_char"
argument_list|)
operator|<<
name|StringOutput
operator|<<
name|CharInput
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"string_qchar"
argument_list|)
operator|<<
name|StringOutput
operator|<<
name|QCharInput
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"device_charstar"
argument_list|)
operator|<<
name|DeviceOutput
operator|<<
name|CharStarInput
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"device_string"
argument_list|)
operator|<<
name|DeviceOutput
operator|<<
name|QStringInput
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"device_char"
argument_list|)
operator|<<
name|DeviceOutput
operator|<<
name|CharInput
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"device_qchar"
argument_list|)
operator|<<
name|DeviceOutput
operator|<<
name|QCharInput
expr_stmt|;
block|}
end_function
begin_function
DECL|function|writeSingleChar
name|void
name|tst_qtextstream
operator|::
name|writeSingleChar
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|Output
argument_list|,
name|output
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|Input
argument_list|,
name|input
argument_list|)
expr_stmt|;
name|QString
name|str
decl_stmt|;
name|QBuffer
name|buffer
decl_stmt|;
name|QTextStream
name|stream
decl_stmt|;
if|if
condition|(
name|output
operator|==
name|StringOutput
condition|)
block|{
name|stream
operator|.
name|setString
argument_list|(
operator|&
name|str
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QVERIFY
argument_list|(
name|buffer
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
argument_list|)
expr_stmt|;
name|stream
operator|.
name|setDevice
argument_list|(
operator|&
name|buffer
argument_list|)
expr_stmt|;
block|}
comment|// Test many different ways to write a single char into a QTextStream
name|QString
name|inputString
init|=
literal|"h"
decl_stmt|;
specifier|const
name|int
name|amount
init|=
literal|100000
decl_stmt|;
switch|switch
condition|(
name|input
condition|)
block|{
case|case
name|CharStarInput
case|:
name|QBENCHMARK
block|{
for|for
control|(
name|qint64
name|i
init|=
literal|0
init|;
name|i
operator|<
name|amount
condition|;
operator|++
name|i
control|)
name|stream
operator|<<
literal|"h"
expr_stmt|;
block|}
break|break;
case|case
name|QStringInput
case|:
name|QBENCHMARK
block|{
for|for
control|(
name|qint64
name|i
init|=
literal|0
init|;
name|i
operator|<
name|amount
condition|;
operator|++
name|i
control|)
name|stream
operator|<<
name|inputString
expr_stmt|;
block|}
break|break;
case|case
name|CharInput
case|:
name|QBENCHMARK
block|{
for|for
control|(
name|qint64
name|i
init|=
literal|0
init|;
name|i
operator|<
name|amount
condition|;
operator|++
name|i
control|)
name|stream
operator|<<
literal|'h'
expr_stmt|;
block|}
break|break;
case|case
name|QCharInput
case|:
name|QBENCHMARK
block|{
for|for
control|(
name|qint64
name|i
init|=
literal|0
init|;
name|i
operator|<
name|amount
condition|;
operator|++
name|i
control|)
name|stream
operator|<<
name|QChar
argument_list|(
literal|'h'
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
name|QString
name|result
decl_stmt|;
if|if
condition|(
name|output
operator|==
name|StringOutput
condition|)
name|result
operator|=
name|str
expr_stmt|;
else|else
name|result
operator|=
name|QString
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|left
argument_list|(
literal|10
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"hhhhhhhhhh"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qtextstream
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
