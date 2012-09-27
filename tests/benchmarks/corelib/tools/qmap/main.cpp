begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QTest>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_class
DECL|class|tst_QMap
class|class
name|tst_QMap
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|insertion_int_int
parameter_list|()
function_decl|;
name|void
name|insertion_int_string
parameter_list|()
function_decl|;
name|void
name|insertion_string_int
parameter_list|()
function_decl|;
name|void
name|lookup_int_int
parameter_list|()
function_decl|;
name|void
name|lookup_int_string
parameter_list|()
function_decl|;
name|void
name|lookup_string_int
parameter_list|()
function_decl|;
name|void
name|iteration
parameter_list|()
function_decl|;
name|void
name|toStdMap
parameter_list|()
function_decl|;
name|void
name|iterator_begin
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|insertion_int_int
name|void
name|tst_QMap
operator|::
name|insertion_int_int
parameter_list|()
block|{
name|QMap
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|map
decl_stmt|;
name|QBENCHMARK
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
literal|100000
condition|;
operator|++
name|i
control|)
name|map
operator|.
name|insert
argument_list|(
name|i
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|insertion_int_string
name|void
name|tst_QMap
operator|::
name|insertion_int_string
parameter_list|()
block|{
name|QMap
argument_list|<
name|int
argument_list|,
name|QString
argument_list|>
name|map
decl_stmt|;
name|QString
name|str
argument_list|(
literal|"Hello World"
argument_list|)
decl_stmt|;
name|QBENCHMARK
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
literal|100000
condition|;
operator|++
name|i
control|)
name|map
operator|.
name|insert
argument_list|(
name|i
argument_list|,
name|str
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|insertion_string_int
name|void
name|tst_QMap
operator|::
name|insertion_string_int
parameter_list|()
block|{
name|QMap
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|map
decl_stmt|;
name|QString
name|str
argument_list|(
literal|"Hello World"
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
literal|100000
condition|;
operator|++
name|i
control|)
block|{
name|str
index|[
literal|0
index|]
operator|=
name|QChar
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|map
operator|.
name|insert
argument_list|(
name|str
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|lookup_int_int
name|void
name|tst_QMap
operator|::
name|lookup_int_int
parameter_list|()
block|{
name|QMap
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|map
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
literal|100000
condition|;
operator|++
name|i
control|)
name|map
operator|.
name|insert
argument_list|(
name|i
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|int
name|sum
init|=
literal|0
decl_stmt|;
name|QBENCHMARK
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
literal|100000
condition|;
operator|++
name|i
control|)
name|sum
operator|+=
name|map
operator|.
name|value
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|lookup_int_string
name|void
name|tst_QMap
operator|::
name|lookup_int_string
parameter_list|()
block|{
name|QMap
argument_list|<
name|int
argument_list|,
name|QString
argument_list|>
name|map
decl_stmt|;
name|QString
name|str
argument_list|(
literal|"Hello World"
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
literal|100000
condition|;
operator|++
name|i
control|)
name|map
operator|.
name|insert
argument_list|(
name|i
argument_list|,
name|str
argument_list|)
expr_stmt|;
name|QBENCHMARK
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
literal|100000
condition|;
operator|++
name|i
control|)
name|str
operator|+=
name|map
operator|.
name|value
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|lookup_string_int
name|void
name|tst_QMap
operator|::
name|lookup_string_int
parameter_list|()
block|{
name|QMap
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|map
decl_stmt|;
name|QString
name|str
argument_list|(
literal|"Hello World"
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
literal|100000
condition|;
operator|++
name|i
control|)
block|{
name|str
index|[
literal|0
index|]
operator|=
name|QChar
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|map
operator|.
name|insert
argument_list|(
name|str
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
name|int
name|sum
init|=
literal|0
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
literal|100000
condition|;
operator|++
name|i
control|)
block|{
name|str
index|[
literal|0
index|]
operator|=
name|QChar
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|sum
operator|+=
name|map
operator|.
name|value
argument_list|(
name|str
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|// iteration speed doesn't depend on the type of the map.
end_comment
begin_function
DECL|function|iteration
name|void
name|tst_QMap
operator|::
name|iteration
parameter_list|()
block|{
name|QMap
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|map
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
literal|100000
condition|;
operator|++
name|i
control|)
name|map
operator|.
name|insert
argument_list|(
name|i
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|int
name|j
init|=
literal|0
decl_stmt|;
name|QBENCHMARK
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
literal|100
condition|;
operator|++
name|i
control|)
block|{
name|QMap
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|map
operator|.
name|constBegin
argument_list|()
decl_stmt|;
name|QMap
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
operator|::
name|const_iterator
name|end
init|=
name|map
operator|.
name|constEnd
argument_list|()
decl_stmt|;
while|while
condition|(
name|it
operator|!=
name|end
condition|)
block|{
name|j
operator|+=
operator|*
name|it
expr_stmt|;
operator|++
name|it
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|toStdMap
name|void
name|tst_QMap
operator|::
name|toStdMap
parameter_list|()
block|{
name|QMap
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|map
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
literal|100000
condition|;
operator|++
name|i
control|)
name|map
operator|.
name|insert
argument_list|(
name|i
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|std
operator|::
name|map
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|n
init|=
name|map
operator|.
name|toStdMap
argument_list|()
decl_stmt|;
name|n
operator|.
name|begin
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|iterator_begin
name|void
name|tst_QMap
operator|::
name|iterator_begin
parameter_list|()
block|{
name|QMap
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|map
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
literal|100000
condition|;
operator|++
name|i
control|)
name|map
operator|.
name|insert
argument_list|(
name|i
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|QBENCHMARK
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
literal|100000
condition|;
operator|++
name|i
control|)
block|{
name|QMap
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|map
operator|.
name|constBegin
argument_list|()
decl_stmt|;
name|QMap
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
operator|::
name|const_iterator
name|end
init|=
name|map
operator|.
name|constEnd
argument_list|()
decl_stmt|;
if|if
condition|(
name|it
operator|==
name|end
condition|)
comment|// same as if (false)
operator|++
name|it
expr_stmt|;
block|}
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QMap
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
