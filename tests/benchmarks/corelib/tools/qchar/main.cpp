begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QChar>
end_include
begin_class
DECL|class|tst_QChar
class|class
name|tst_QChar
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|isUpper_data
parameter_list|()
function_decl|;
name|void
name|isUpper
parameter_list|()
function_decl|;
name|void
name|isLower_data
parameter_list|()
function_decl|;
name|void
name|isLower
parameter_list|()
function_decl|;
name|void
name|isLetter_data
parameter_list|()
function_decl|;
name|void
name|isLetter
parameter_list|()
function_decl|;
name|void
name|isDigit_data
parameter_list|()
function_decl|;
name|void
name|isDigit
parameter_list|()
function_decl|;
name|void
name|isLetterOrNumber_data
parameter_list|()
function_decl|;
name|void
name|isLetterOrNumber
parameter_list|()
function_decl|;
name|void
name|isSpace_data
parameter_list|()
function_decl|;
name|void
name|isSpace
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|isUpper_data
name|void
name|tst_QChar
operator|::
name|isUpper_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QChar
argument_list|>
argument_list|(
literal|"c"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"k"
argument_list|)
operator|<<
name|QChar
argument_list|(
literal|'k'
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"K"
argument_list|)
operator|<<
name|QChar
argument_list|(
literal|'K'
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5"
argument_list|)
operator|<<
name|QChar
argument_list|(
literal|'5'
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"\\0"
argument_list|)
operator|<<
name|QChar
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"space"
argument_list|)
operator|<<
name|QChar
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"\\u3C20"
argument_list|)
operator|<<
name|QChar
argument_list|(
literal|0x3C20
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isUpper
name|void
name|tst_QChar
operator|::
name|isUpper
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QChar
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|c
operator|.
name|isUpper
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|isLower_data
name|void
name|tst_QChar
operator|::
name|isLower_data
parameter_list|()
block|{
name|isUpper_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isLower
name|void
name|tst_QChar
operator|::
name|isLower
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QChar
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|c
operator|.
name|isLower
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|isLetter_data
name|void
name|tst_QChar
operator|::
name|isLetter_data
parameter_list|()
block|{
name|isUpper_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isLetter
name|void
name|tst_QChar
operator|::
name|isLetter
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QChar
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|c
operator|.
name|isLetter
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|isDigit_data
name|void
name|tst_QChar
operator|::
name|isDigit_data
parameter_list|()
block|{
name|isUpper_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isDigit
name|void
name|tst_QChar
operator|::
name|isDigit
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QChar
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|c
operator|.
name|isDigit
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|isLetterOrNumber_data
name|void
name|tst_QChar
operator|::
name|isLetterOrNumber_data
parameter_list|()
block|{
name|isUpper_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isLetterOrNumber
name|void
name|tst_QChar
operator|::
name|isLetterOrNumber
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QChar
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|c
operator|.
name|isLetterOrNumber
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|isSpace_data
name|void
name|tst_QChar
operator|::
name|isSpace_data
parameter_list|()
block|{
name|isUpper_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isSpace
name|void
name|tst_QChar
operator|::
name|isSpace
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QChar
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|c
operator|.
name|isSpace
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QChar
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
