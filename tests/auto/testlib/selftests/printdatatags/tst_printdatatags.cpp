begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_PrintDataTags
class|class
name|tst_PrintDataTags
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|a_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|a
parameter_list|()
specifier|const
function_decl|;
name|void
name|b
parameter_list|()
specifier|const
function_decl|;
name|void
name|c_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|c
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|a_data
name|void
name|tst_PrintDataTags
operator|::
name|a_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"x"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"y"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data tag a1 "
argument_list|)
operator|<<
literal|1
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data tag a2"
argument_list|)
operator|<<
literal|1
operator|<<
literal|2
expr_stmt|;
block|}
end_function
begin_function
DECL|function|a
name|void
name|tst_PrintDataTags
operator|::
name|a
parameter_list|()
specifier|const
block|{ }
end_function
begin_function
DECL|function|b
name|void
name|tst_PrintDataTags
operator|::
name|b
parameter_list|()
specifier|const
block|{ }
end_function
begin_function
DECL|function|c_data
name|void
name|tst_PrintDataTags
operator|::
name|c_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"x"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data tag c1"
argument_list|)
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data tag c2"
argument_list|)
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data tag c3"
argument_list|)
operator|<<
literal|1
expr_stmt|;
block|}
end_function
begin_function
DECL|function|c
name|void
name|tst_PrintDataTags
operator|::
name|c
parameter_list|()
specifier|const
block|{ }
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_PrintDataTags
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_printdatatags.moc"
end_include
end_unit
