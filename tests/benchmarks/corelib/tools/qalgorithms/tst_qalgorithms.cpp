begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2012 Robin Burchell<robin+qt@viroteck.net> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<iostream>
end_include
begin_include
include|#
directive|include
file|<iomanip>
end_include
begin_include
include|#
directive|include
file|<sstream>
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_include
include|#
directive|include
file|<qalgorithms.h>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_using
using|using
namespace|namespace
name|std
namespace|;
end_using
begin_class
DECL|class|tst_QAlgorithms
class|class
name|tst_QAlgorithms
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|stableSort_data
parameter_list|()
function_decl|;
name|void
name|stableSort
parameter_list|()
function_decl|;
name|void
name|sort_data
parameter_list|()
function_decl|;
name|void
name|sort
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
template|template
parameter_list|<
name|typename
name|DataType
parameter_list|>
DECL|function|generateData
name|QVector
argument_list|<
name|DataType
argument_list|>
name|generateData
parameter_list|(
name|QString
name|dataSetType
parameter_list|,
specifier|const
name|int
name|length
parameter_list|)
block|{
name|QVector
argument_list|<
name|DataType
argument_list|>
name|container
decl_stmt|;
if|if
condition|(
name|dataSetType
operator|==
literal|"Random"
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|length
condition|;
operator|++
name|i
control|)
name|container
operator|.
name|append
argument_list|(
name|rand
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|dataSetType
operator|==
literal|"Ascending"
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|length
condition|;
operator|++
name|i
control|)
name|container
operator|.
name|append
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|dataSetType
operator|==
literal|"Descending"
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|length
condition|;
operator|++
name|i
control|)
name|container
operator|.
name|append
argument_list|(
name|length
operator|-
name|i
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|dataSetType
operator|==
literal|"Equal"
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|length
condition|;
operator|++
name|i
control|)
name|container
operator|.
name|append
argument_list|(
literal|43
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|dataSetType
operator|==
literal|"Duplicates"
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|length
condition|;
operator|++
name|i
control|)
name|container
operator|.
name|append
argument_list|(
name|i
operator|%
literal|10
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|dataSetType
operator|==
literal|"Almost Sorted"
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|length
condition|;
operator|++
name|i
control|)
name|container
operator|.
name|append
argument_list|(
name|i
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
operator|<=
name|length
operator|/
literal|10
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|int
name|iswap
init|=
name|i
operator|*
literal|9
decl_stmt|;
name|DataType
name|tmp
init|=
name|container
operator|.
name|at
argument_list|(
name|iswap
argument_list|)
decl_stmt|;
name|container
index|[
name|iswap
index|]
operator|=
name|container
operator|.
name|at
argument_list|(
name|iswap
operator|+
literal|1
argument_list|)
expr_stmt|;
name|container
index|[
name|iswap
operator|+
literal|1
index|]
operator|=
name|tmp
expr_stmt|;
block|}
block|}
return|return
name|container
return|;
block|}
end_function
begin_function
DECL|function|stableSort_data
name|void
name|tst_QAlgorithms
operator|::
name|stableSort_data
parameter_list|()
block|{
specifier|const
name|int
name|dataSize
init|=
literal|5000
decl_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QVector
argument_list|<
name|int
argument_list|>
argument_list|>
argument_list|(
literal|"unsorted"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Equal"
argument_list|)
operator|<<
operator|(
name|generateData
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"Equal"
argument_list|,
name|dataSize
argument_list|)
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Ascending"
argument_list|)
operator|<<
operator|(
name|generateData
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"Ascending"
argument_list|,
name|dataSize
argument_list|)
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Descending"
argument_list|)
operator|<<
operator|(
name|generateData
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"Descending"
argument_list|,
name|dataSize
argument_list|)
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Duplicates"
argument_list|)
operator|<<
operator|(
name|generateData
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"Duplicates"
argument_list|,
name|dataSize
argument_list|)
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Almost Sorted"
argument_list|)
operator|<<
operator|(
name|generateData
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"Almost Sorted"
argument_list|,
name|dataSize
argument_list|)
operator|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stableSort
name|void
name|tst_QAlgorithms
operator|::
name|stableSort
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QVector
argument_list|<
name|int
argument_list|>
argument_list|,
name|unsorted
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|QVector
argument_list|<
name|int
argument_list|>
name|sorted
init|=
name|unsorted
decl_stmt|;
name|qStableSort
argument_list|(
name|sorted
operator|.
name|begin
argument_list|()
argument_list|,
name|sorted
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|sort_data
name|void
name|tst_QAlgorithms
operator|::
name|sort_data
parameter_list|()
block|{
name|stableSort_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sort
name|void
name|tst_QAlgorithms
operator|::
name|sort
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QVector
argument_list|<
name|int
argument_list|>
argument_list|,
name|unsorted
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|QVector
argument_list|<
name|int
argument_list|>
name|sorted
init|=
name|unsorted
decl_stmt|;
name|qSort
argument_list|(
name|sorted
operator|.
name|begin
argument_list|()
argument_list|,
name|sorted
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QAlgorithms
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qalgorithms.moc"
end_include
end_unit
