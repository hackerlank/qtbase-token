begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_QString
class|class
name|tst_QString
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QString
parameter_list|()
constructor_decl|;
private|private
name|slots
private|:
name|void
name|toUpper_data
parameter_list|()
function_decl|;
name|void
name|toUpper
parameter_list|()
function_decl|;
name|void
name|toLower_data
parameter_list|()
function_decl|;
name|void
name|toLower
parameter_list|()
function_decl|;
name|void
name|toCaseFolded_data
parameter_list|()
function_decl|;
name|void
name|toCaseFolded
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QString
name|tst_QString
operator|::
name|tst_QString
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|toUpper_data
name|void
name|tst_QString
operator|::
name|toUpper_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"s"
argument_list|)
expr_stmt|;
name|QString
name|lowerLatin1
argument_list|(
literal|300
argument_list|,
name|QChar
argument_list|(
literal|'a'
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|upperLatin1
argument_list|(
literal|300
argument_list|,
name|QChar
argument_list|(
literal|'A'
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|lowerDeseret
decl_stmt|;
block|{
name|QString
name|pattern
decl_stmt|;
name|pattern
operator|+=
name|QChar
argument_list|(
name|QChar
operator|::
name|highSurrogate
argument_list|(
literal|0x10428
argument_list|)
argument_list|)
expr_stmt|;
name|pattern
operator|+=
name|QChar
argument_list|(
name|QChar
operator|::
name|lowSurrogate
argument_list|(
literal|0x10428
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|300
operator|/
name|pattern
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|lowerDeseret
operator|+=
name|pattern
expr_stmt|;
block|}
name|QString
name|upperDeseret
decl_stmt|;
block|{
name|QString
name|pattern
decl_stmt|;
name|pattern
operator|+=
name|QChar
argument_list|(
name|QChar
operator|::
name|highSurrogate
argument_list|(
literal|0x10400
argument_list|)
argument_list|)
expr_stmt|;
name|pattern
operator|+=
name|QChar
argument_list|(
name|QChar
operator|::
name|lowSurrogate
argument_list|(
literal|0x10400
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|300
operator|/
name|pattern
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|upperDeseret
operator|+=
name|pattern
expr_stmt|;
block|}
name|QString
name|lowerLigature
argument_list|(
literal|600
argument_list|,
name|QChar
argument_list|(
literal|0xFB03
argument_list|)
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"600<a>"
argument_list|)
operator|<<
operator|(
name|lowerLatin1
operator|+
name|lowerLatin1
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"600<A>"
argument_list|)
operator|<<
operator|(
name|upperLatin1
operator|+
name|upperLatin1
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"300<a>+300<A>"
argument_list|)
operator|<<
operator|(
name|lowerLatin1
operator|+
name|upperLatin1
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"300<A>+300<a>"
argument_list|)
operator|<<
operator|(
name|upperLatin1
operator|+
name|lowerLatin1
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"300<10428>"
argument_list|)
operator|<<
operator|(
name|lowerDeseret
operator|+
name|lowerDeseret
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"300<10400>"
argument_list|)
operator|<<
operator|(
name|upperDeseret
operator|+
name|upperDeseret
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"150<10428>+150<10400>"
argument_list|)
operator|<<
operator|(
name|lowerDeseret
operator|+
name|upperDeseret
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"150<10400>+150<10428>"
argument_list|)
operator|<<
operator|(
name|upperDeseret
operator|+
name|lowerDeseret
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"300a+150<10400>"
argument_list|)
operator|<<
operator|(
name|lowerLatin1
operator|+
name|upperDeseret
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"300a+150<10428>"
argument_list|)
operator|<<
operator|(
name|lowerLatin1
operator|+
name|lowerDeseret
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"300A+150<10400>"
argument_list|)
operator|<<
operator|(
name|upperLatin1
operator|+
name|upperDeseret
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"300A+150<10428>"
argument_list|)
operator|<<
operator|(
name|upperLatin1
operator|+
name|lowerDeseret
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"600<FB03> (ligature)"
argument_list|)
operator|<<
name|lowerLigature
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toUpper
name|void
name|tst_QString
operator|::
name|toUpper
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|s
operator|.
name|toUpper
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|toLower_data
name|void
name|tst_QString
operator|::
name|toLower_data
parameter_list|()
block|{
name|toUpper_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toLower
name|void
name|tst_QString
operator|::
name|toLower
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|s
operator|.
name|toLower
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|toCaseFolded_data
name|void
name|tst_QString
operator|::
name|toCaseFolded_data
parameter_list|()
block|{
name|toUpper_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toCaseFolded
name|void
name|tst_QString
operator|::
name|toCaseFolded
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|s
operator|.
name|toCaseFolded
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QString
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
