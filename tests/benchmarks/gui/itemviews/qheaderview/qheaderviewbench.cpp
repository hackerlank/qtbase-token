begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 ThorbjÃ¸rn Lund Martsum - tmartsum[at]gmail.com ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QtWidgets>
end_include
begin_class
DECL|class|BenchQHeaderView
class|class
name|BenchQHeaderView
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|BenchQHeaderView
name|BenchQHeaderView
parameter_list|()
member_init_list|:
name|QObject
argument_list|()
block|{
name|m_tv
operator|=
literal|0
expr_stmt|;
name|m_hv
operator|=
literal|0
expr_stmt|;
name|m_model
operator|=
literal|0
expr_stmt|;
block|}
protected|protected:
DECL|member|m_tv
name|QTableView
modifier|*
name|m_tv
decl_stmt|;
DECL|member|m_hv
name|QHeaderView
modifier|*
name|m_hv
decl_stmt|;
DECL|member|m_model
name|QStandardItemModel
modifier|*
name|m_model
decl_stmt|;
DECL|member|m_normalmodel
name|QStandardItemModel
name|m_normalmodel
decl_stmt|;
DECL|member|t
name|QElapsedTimer
name|t
decl_stmt|;
DECL|member|m_worst_case
name|bool
name|m_worst_case
decl_stmt|;
name|void
name|setupTestData
parameter_list|()
function_decl|;
DECL|member|m_blockSomeSignals
name|bool
name|m_blockSomeSignals
decl_stmt|;
DECL|member|m_updatesEnabled
name|bool
name|m_updatesEnabled
decl_stmt|;
DECL|member|m_rowcount
name|int
name|m_rowcount
decl_stmt|;
DECL|member|m_colcount
name|int
name|m_colcount
decl_stmt|;
private|private
name|slots
private|:
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
DECL|function|visualIndexAtSpecial_data
name|void
name|visualIndexAtSpecial_data
parameter_list|()
block|{
name|setupTestData
argument_list|()
expr_stmt|;
block|}
DECL|function|visualIndexAt_data
name|void
name|visualIndexAt_data
parameter_list|()
block|{
name|setupTestData
argument_list|()
expr_stmt|;
block|}
DECL|function|hideShowBench_data
name|void
name|hideShowBench_data
parameter_list|()
block|{
name|setupTestData
argument_list|()
expr_stmt|;
block|}
DECL|function|swapSectionsBench_data
name|void
name|swapSectionsBench_data
parameter_list|()
block|{
name|setupTestData
argument_list|()
expr_stmt|;
block|}
DECL|function|moveSectionBench_data
name|void
name|moveSectionBench_data
parameter_list|()
block|{
name|setupTestData
argument_list|()
expr_stmt|;
block|}
DECL|function|defaultSizeBench_data
name|void
name|defaultSizeBench_data
parameter_list|()
block|{
name|setupTestData
argument_list|()
expr_stmt|;
block|}
DECL|function|removeBench_data
name|void
name|removeBench_data
parameter_list|()
block|{
name|setupTestData
argument_list|()
expr_stmt|;
block|}
DECL|function|insertBench_data
name|void
name|insertBench_data
parameter_list|()
block|{
name|setupTestData
argument_list|()
expr_stmt|;
block|}
DECL|function|truncBench_data
name|void
name|truncBench_data
parameter_list|()
block|{
name|setupTestData
argument_list|()
expr_stmt|;
block|}
name|void
name|visualIndexAtSpecial
parameter_list|()
function_decl|;
name|void
name|visualIndexAt
parameter_list|()
function_decl|;
name|void
name|hideShowBench
parameter_list|()
function_decl|;
name|void
name|swapSectionsBench
parameter_list|()
function_decl|;
name|void
name|moveSectionBench
parameter_list|()
function_decl|;
name|void
name|defaultSizeBench
parameter_list|()
function_decl|;
name|void
name|removeBench
parameter_list|()
function_decl|;
name|void
name|insertBench
parameter_list|()
function_decl|;
name|void
name|truncBench
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|setupTestData
name|void
name|BenchQHeaderView
operator|::
name|setupTestData
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"worst_case"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Less relevant best case"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"__* More important worst case *__"
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initTestCase
name|void
name|BenchQHeaderView
operator|::
name|initTestCase
parameter_list|()
block|{
name|m_tv
operator|=
operator|new
name|QTableView
argument_list|()
expr_stmt|;
name|m_hv
operator|=
name|m_tv
operator|->
name|verticalHeader
argument_list|()
expr_stmt|;
name|m_model
operator|=
operator|&
name|m_normalmodel
expr_stmt|;
name|m_tv
operator|->
name|setModel
argument_list|(
name|m_model
argument_list|)
expr_stmt|;
name|m_tv
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|BenchQHeaderView
operator|::
name|cleanupTestCase
parameter_list|()
block|{
operator|delete
name|m_tv
expr_stmt|;
name|m_tv
operator|=
literal|0
expr_stmt|;
name|m_hv
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|BenchQHeaderView
operator|::
name|init
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|worst_case
argument_list|)
expr_stmt|;
name|m_blockSomeSignals
operator|=
literal|true
expr_stmt|;
name|m_updatesEnabled
operator|=
literal|false
expr_stmt|;
name|m_rowcount
operator|=
literal|2500
expr_stmt|;
name|m_colcount
operator|=
literal|10
expr_stmt|;
name|m_worst_case
operator|=
name|worst_case
expr_stmt|;
name|m_model
operator|->
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|worst_case
condition|)
block|{
for|for
control|(
name|int
name|u
init|=
literal|0
init|;
name|u
operator|<=
name|m_rowcount
condition|;
operator|++
name|u
control|)
comment|// ensures fragment in Qt 4.x
name|m_model
operator|->
name|setRowCount
argument_list|(
name|u
argument_list|)
expr_stmt|;
name|m_model
operator|->
name|setColumnCount
argument_list|(
name|m_colcount
argument_list|)
expr_stmt|;
name|m_hv
operator|->
name|swapSections
argument_list|(
literal|0
argument_list|,
name|m_rowcount
operator|-
literal|1
argument_list|)
expr_stmt|;
name|m_hv
operator|->
name|hideSection
argument_list|(
name|m_rowcount
operator|/
literal|2
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_model
operator|->
name|setColumnCount
argument_list|(
name|m_colcount
argument_list|)
expr_stmt|;
name|m_model
operator|->
name|setRowCount
argument_list|(
name|m_rowcount
argument_list|)
expr_stmt|;
block|}
name|QString
name|s
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
name|m_model
operator|->
name|rowCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|m_model
operator|->
name|setData
argument_list|(
name|m_model
operator|->
name|index
argument_list|(
name|i
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QVariant
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|s
operator|.
name|setNum
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|s
operator|+=
literal|"."
expr_stmt|;
name|s
operator|+=
literal|'a'
operator|+
operator|(
name|i
operator|%
literal|25
operator|)
expr_stmt|;
name|m_model
operator|->
name|setData
argument_list|(
name|m_model
operator|->
name|index
argument_list|(
name|i
argument_list|,
literal|1
argument_list|)
argument_list|,
name|QVariant
argument_list|(
name|s
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|m_tv
operator|->
name|setUpdatesEnabled
argument_list|(
name|m_updatesEnabled
argument_list|)
expr_stmt|;
name|m_hv
operator|->
name|blockSignals
argument_list|(
name|m_blockSomeSignals
argument_list|)
expr_stmt|;
specifier|const
name|int
name|default_section_size
init|=
literal|25
decl_stmt|;
name|m_hv
operator|->
name|setDefaultSectionSize
argument_list|(
name|default_section_size
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|BenchQHeaderView
operator|::
name|cleanup
parameter_list|()
block|{
name|m_tv
operator|->
name|setUpdatesEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|m_hv
operator|->
name|blockSignals
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|visualIndexAtSpecial
name|void
name|BenchQHeaderView
operator|::
name|visualIndexAtSpecial
parameter_list|()
block|{
name|int
name|lookup_pos
init|=
name|m_hv
operator|->
name|length
argument_list|()
operator|-
literal|50
decl_stmt|;
name|int
name|testnum
init|=
literal|0
decl_stmt|;
name|QBENCHMARK
block|{
operator|++
name|testnum
expr_stmt|;
name|m_hv
operator|->
name|resizeSection
argument_list|(
literal|0
argument_list|,
name|testnum
operator|%
literal|47
argument_list|)
expr_stmt|;
name|m_hv
operator|->
name|visualIndexAt
argument_list|(
name|lookup_pos
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|visualIndexAt
name|void
name|BenchQHeaderView
operator|::
name|visualIndexAt
parameter_list|()
block|{
specifier|const
name|int
name|center_pos
init|=
name|m_hv
operator|->
name|length
argument_list|()
operator|/
literal|2
decl_stmt|;
specifier|const
name|int
name|maxpos
init|=
name|m_hv
operator|->
name|length
argument_list|()
operator|-
literal|1
decl_stmt|;
name|QBENCHMARK
block|{
name|m_hv
operator|->
name|visualIndexAt
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|m_hv
operator|->
name|visualIndexAt
argument_list|(
name|center_pos
argument_list|)
expr_stmt|;
name|m_hv
operator|->
name|visualIndexAt
argument_list|(
name|maxpos
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|hideShowBench
name|void
name|BenchQHeaderView
operator|::
name|hideShowBench
parameter_list|()
block|{
name|int
name|n
init|=
literal|0
decl_stmt|;
name|bool
name|hide_set
init|=
literal|true
decl_stmt|;
name|QBENCHMARK
block|{
name|m_hv
operator|->
name|setSectionHidden
argument_list|(
name|n
argument_list|,
name|hide_set
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|>=
name|m_hv
operator|->
name|count
argument_list|()
condition|)
block|{
name|n
operator|=
operator|-
literal|1
expr_stmt|;
name|hide_set
operator|=
operator|!
name|hide_set
expr_stmt|;
block|}
operator|++
name|n
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|swapSectionsBench
name|void
name|BenchQHeaderView
operator|::
name|swapSectionsBench
parameter_list|()
block|{
name|int
name|n
init|=
literal|0
decl_stmt|;
name|QBENCHMARK
block|{
name|m_hv
operator|->
name|swapSections
argument_list|(
name|n
argument_list|,
name|n
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
name|n
operator|>=
name|m_hv
operator|->
name|count
argument_list|()
condition|)
name|n
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|moveSectionBench
name|void
name|BenchQHeaderView
operator|::
name|moveSectionBench
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|m_hv
operator|->
name|moveSection
argument_list|(
literal|0
argument_list|,
name|m_hv
operator|->
name|count
argument_list|()
operator|-
literal|2
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|defaultSizeBench
name|void
name|BenchQHeaderView
operator|::
name|defaultSizeBench
parameter_list|()
block|{
name|int
name|n
init|=
literal|1
decl_stmt|;
name|QBENCHMARK
block|{
name|m_hv
operator|->
name|setDefaultSectionSize
argument_list|(
name|n
argument_list|)
expr_stmt|;
operator|++
name|n
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|removeBench
name|void
name|BenchQHeaderView
operator|::
name|removeBench
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|m_model
operator|->
name|removeRows
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_hv
operator|->
name|count
argument_list|()
operator|==
literal|0
condition|)
block|{
comment|// setup a new hard model
name|m_model
operator|->
name|setRowCount
argument_list|(
name|m_rowcount
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_worst_case
condition|)
block|{
name|m_hv
operator|->
name|swapSections
argument_list|(
literal|0
argument_list|,
name|m_rowcount
operator|-
literal|1
argument_list|)
expr_stmt|;
name|m_hv
operator|->
name|hideSection
argument_list|(
name|m_rowcount
operator|/
literal|2
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|insertBench
name|void
name|BenchQHeaderView
operator|::
name|insertBench
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|m_model
operator|->
name|insertRows
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_hv
operator|->
name|count
argument_list|()
operator|==
literal|10000000
condition|)
block|{
comment|// setup a new hard model
name|m_model
operator|->
name|setRowCount
argument_list|(
name|m_rowcount
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_worst_case
condition|)
block|{
name|m_hv
operator|->
name|swapSections
argument_list|(
literal|0
argument_list|,
name|m_rowcount
operator|-
literal|1
argument_list|)
expr_stmt|;
name|m_hv
operator|->
name|hideSection
argument_list|(
name|m_rowcount
operator|/
literal|2
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|truncBench
name|void
name|BenchQHeaderView
operator|::
name|truncBench
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|m_model
operator|->
name|setRowCount
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|m_model
operator|->
name|setRowCount
argument_list|(
name|m_rowcount
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_worst_case
condition|)
block|{
name|m_hv
operator|->
name|swapSections
argument_list|(
literal|0
argument_list|,
name|m_rowcount
operator|-
literal|1
argument_list|)
expr_stmt|;
name|m_hv
operator|->
name|hideSection
argument_list|(
name|m_rowcount
operator|/
literal|2
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|BenchQHeaderView
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"qheaderviewbench.moc"
end_include
end_unit
