begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// This file contains benchmarks for comparing QVector against std::vector
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_class
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
comment|// T is the item type
class|class
DECL|class|UseCases
name|UseCases
block|{
public|public:
DECL|function|~UseCases
specifier|virtual
name|~
name|UseCases
parameter_list|()
block|{}
comment|// Use case: Insert \a size items into the vector.
specifier|virtual
name|void
name|insert
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|=
literal|0
function_decl|;
comment|// Use case: Lookup \a size items from the vector.
specifier|virtual
name|void
name|lookup
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|=
literal|0
function_decl|;
block|}
class|;
end_class
begin_function
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|f
name|T
modifier|*
name|f
parameter_list|(
name|T
modifier|*
name|ts
parameter_list|)
comment|// dummy function to prevent code from being optimized away by the compiler
block|{
return|return
name|ts
return|;
block|}
end_function
begin_comment
comment|// This subclass implements the use cases using QVector as efficiently as possible.
end_comment
begin_class
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
class|class
DECL|class|UseCases_QVector
name|UseCases_QVector
super|:
specifier|public
name|UseCases
argument_list|<
name|T
argument_list|>
block|{
DECL|function|insert
name|void
name|insert
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|QVector
argument_list|<
name|T
argument_list|>
name|v
decl_stmt|;
name|T
name|t
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
name|size
condition|;
operator|++
name|i
control|)
name|v
operator|.
name|append
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|lookup
name|void
name|lookup
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|QVector
argument_list|<
name|T
argument_list|>
name|v
decl_stmt|;
name|T
name|t
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
name|size
condition|;
operator|++
name|i
control|)
name|v
operator|.
name|append
argument_list|(
name|t
argument_list|)
expr_stmt|;
name|T
modifier|*
name|ts
init|=
operator|new
name|T
index|[
name|size
index|]
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
name|size
condition|;
operator|++
name|i
control|)
name|ts
index|[
name|i
index|]
operator|=
name|v
operator|.
name|value
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
name|f
argument_list|<
name|T
argument_list|>
argument_list|(
name|ts
argument_list|)
expr_stmt|;
operator|delete
index|[]
name|ts
expr_stmt|;
block|}
block|}
class|;
end_class
begin_comment
comment|// This subclass implements the use cases using std::vector as efficiently as possible.
end_comment
begin_class
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
class|class
DECL|class|UseCases_stdvector
name|UseCases_stdvector
super|:
specifier|public
name|UseCases
argument_list|<
name|T
argument_list|>
block|{
DECL|function|insert
name|void
name|insert
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|std
operator|::
name|vector
argument_list|<
name|T
argument_list|>
name|v
decl_stmt|;
name|T
name|t
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
name|size
condition|;
operator|++
name|i
control|)
name|v
operator|.
name|push_back
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|lookup
name|void
name|lookup
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|std
operator|::
name|vector
argument_list|<
name|T
argument_list|>
name|v
decl_stmt|;
name|T
name|t
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
name|size
condition|;
operator|++
name|i
control|)
name|v
operator|.
name|push_back
argument_list|(
name|t
argument_list|)
expr_stmt|;
name|T
modifier|*
name|ts
init|=
operator|new
name|T
index|[
name|size
index|]
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
name|size
condition|;
operator|++
name|i
control|)
name|ts
index|[
name|i
index|]
operator|=
name|v
index|[
name|i
index|]
expr_stmt|;
block|}
name|f
argument_list|<
name|T
argument_list|>
argument_list|(
name|ts
argument_list|)
expr_stmt|;
operator|delete
index|[]
name|ts
expr_stmt|;
block|}
block|}
class|;
end_class
begin_struct
DECL|struct|Large
struct|struct
name|Large
block|{
comment|// A "large" item type
DECL|member|x
name|int
name|x
index|[
literal|1000
index|]
decl_stmt|;
block|}
struct|;
end_struct
begin_comment
comment|// Embedded devices typically have limited memory
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WINCE
argument_list|)
end_if
begin_define
DECL|macro|LARGE_MAX_SIZE
define|#
directive|define
name|LARGE_MAX_SIZE
value|2000
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|LARGE_MAX_SIZE
define|#
directive|define
name|LARGE_MAX_SIZE
value|20000
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_vector_vs_std
class|class
name|tst_vector_vs_std
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_vector_vs_std
name|tst_vector_vs_std
parameter_list|()
block|{
name|useCases_QVector_int
operator|=
operator|new
name|UseCases_QVector
argument_list|<
name|int
argument_list|>
expr_stmt|;
name|useCases_stdvector_int
operator|=
operator|new
name|UseCases_stdvector
argument_list|<
name|int
argument_list|>
expr_stmt|;
name|useCases_QVector_Large
operator|=
operator|new
name|UseCases_QVector
argument_list|<
name|Large
argument_list|>
expr_stmt|;
name|useCases_stdvector_Large
operator|=
operator|new
name|UseCases_stdvector
argument_list|<
name|Large
argument_list|>
expr_stmt|;
block|}
private|private:
DECL|member|useCases_QVector_int
name|UseCases
argument_list|<
name|int
argument_list|>
modifier|*
name|useCases_QVector_int
decl_stmt|;
DECL|member|useCases_stdvector_int
name|UseCases
argument_list|<
name|int
argument_list|>
modifier|*
name|useCases_stdvector_int
decl_stmt|;
DECL|member|useCases_QVector_Large
name|UseCases
argument_list|<
name|Large
argument_list|>
modifier|*
name|useCases_QVector_Large
decl_stmt|;
DECL|member|useCases_stdvector_Large
name|UseCases
argument_list|<
name|Large
argument_list|>
modifier|*
name|useCases_stdvector_Large
decl_stmt|;
private|private
name|slots
private|:
name|void
name|insert_int_data
parameter_list|()
function_decl|;
name|void
name|insert_int
parameter_list|()
function_decl|;
name|void
name|insert_Large_data
parameter_list|()
function_decl|;
name|void
name|insert_Large
parameter_list|()
function_decl|;
name|void
name|lookup_int_data
parameter_list|()
function_decl|;
name|void
name|lookup_int
parameter_list|()
function_decl|;
name|void
name|lookup_Large_data
parameter_list|()
function_decl|;
name|void
name|lookup_Large
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|insert_int_data
name|void
name|tst_vector_vs_std
operator|::
name|insert_int_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"useStd"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|size
init|=
literal|10
init|;
name|size
operator|<
literal|20000
condition|;
name|size
operator|+=
literal|100
control|)
block|{
specifier|const
name|QByteArray
name|sizeString
init|=
name|QByteArray
operator|::
name|number
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
operator|(
literal|"std::vector-int--"
operator|+
name|sizeString
operator|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
literal|true
operator|<<
name|size
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
operator|(
literal|"QVector-int--"
operator|+
name|sizeString
operator|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
literal|false
operator|<<
name|size
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|insert_int
name|void
name|tst_vector_vs_std
operator|::
name|insert_int
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|useStd
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|useStd
condition|)
name|useCases_stdvector_int
operator|->
name|insert
argument_list|(
name|size
argument_list|)
expr_stmt|;
else|else
name|useCases_QVector_int
operator|->
name|insert
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insert_Large_data
name|void
name|tst_vector_vs_std
operator|::
name|insert_Large_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"useStd"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|size
init|=
literal|10
init|;
name|size
operator|<
name|LARGE_MAX_SIZE
condition|;
name|size
operator|+=
literal|100
control|)
block|{
specifier|const
name|QByteArray
name|sizeString
init|=
name|QByteArray
operator|::
name|number
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
operator|(
literal|"std::vector-Large--"
operator|+
name|sizeString
operator|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
literal|true
operator|<<
name|size
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
operator|(
literal|"QVector-Large--"
operator|+
name|sizeString
operator|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
literal|false
operator|<<
name|size
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|insert_Large
name|void
name|tst_vector_vs_std
operator|::
name|insert_Large
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|useStd
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|useStd
condition|)
name|useCases_stdvector_Large
operator|->
name|insert
argument_list|(
name|size
argument_list|)
expr_stmt|;
else|else
name|useCases_QVector_Large
operator|->
name|insert
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lookup_int_data
name|void
name|tst_vector_vs_std
operator|::
name|lookup_int_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"useStd"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|size
init|=
literal|10
init|;
name|size
operator|<
literal|20000
condition|;
name|size
operator|+=
literal|100
control|)
block|{
specifier|const
name|QByteArray
name|sizeString
init|=
name|QByteArray
operator|::
name|number
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
operator|(
literal|"std::vector-int--"
operator|+
name|sizeString
operator|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
literal|true
operator|<<
name|size
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
operator|(
literal|"QVector-int--"
operator|+
name|sizeString
operator|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
literal|false
operator|<<
name|size
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|lookup_int
name|void
name|tst_vector_vs_std
operator|::
name|lookup_int
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|useStd
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|useStd
condition|)
name|useCases_stdvector_int
operator|->
name|lookup
argument_list|(
name|size
argument_list|)
expr_stmt|;
else|else
name|useCases_QVector_int
operator|->
name|lookup
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lookup_Large_data
name|void
name|tst_vector_vs_std
operator|::
name|lookup_Large_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"useStd"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|size
init|=
literal|10
init|;
name|size
operator|<
name|LARGE_MAX_SIZE
condition|;
name|size
operator|+=
literal|100
control|)
block|{
specifier|const
name|QByteArray
name|sizeString
init|=
name|QByteArray
operator|::
name|number
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
operator|(
literal|"std::vector-Large--"
operator|+
name|sizeString
operator|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
literal|true
operator|<<
name|size
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
operator|(
literal|"QVector-Large--"
operator|+
name|sizeString
operator|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
literal|false
operator|<<
name|size
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|lookup_Large
name|void
name|tst_vector_vs_std
operator|::
name|lookup_Large
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|useStd
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|useStd
condition|)
name|useCases_stdvector_Large
operator|->
name|lookup
argument_list|(
name|size
argument_list|)
expr_stmt|;
else|else
name|useCases_QVector_Large
operator|->
name|lookup
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_vector_vs_std
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
