begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_FetchBogus
class|class
name|tst_FetchBogus
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|fetchBogus_data
parameter_list|()
function_decl|;
name|void
name|fetchBogus
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|fetchBogus_data
name|void
name|tst_FetchBogus
operator|::
name|fetchBogus_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"string"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"foo"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"blah"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fetchBogus
name|void
name|tst_FetchBogus
operator|::
name|fetchBogus
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|bubu
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_FetchBogus
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_fetchbogus.moc"
end_include
end_unit
