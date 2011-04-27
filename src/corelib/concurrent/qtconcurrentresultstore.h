begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTCONCURRENT_RESULTSTORE_H
end_ifndef
begin_define
DECL|macro|QTCONCURRENT_RESULTSTORE_H
define|#
directive|define
name|QTCONCURRENT_RESULTSTORE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QFUTURE
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
comment|/*     ResultStore stores indexed results. Results can be added and retrieved     either individually batched in a QVector. Retriveing results and checking     which indexes are in the store can be done either by iterating or by random     accees. In addition results kan be removed from the front of the store,     either individually or in batches. */
ifndef|#
directive|ifndef
name|qdoc
name|namespace
name|QtConcurrent
decl_stmt|{  class ResultItem
block|{
name|public
label|:
name|ResultItem
argument_list|(
argument|const void *_result
argument_list|,
argument|int _count
argument_list|)
block|:
name|m_count
argument_list|(
name|_count
argument_list|)
operator|,
name|result
argument_list|(
argument|_result
argument_list|)
block|{ }
comment|// contruct with vector of results
name|ResultItem
argument_list|(
specifier|const
name|void
operator|*
name|_result
argument_list|)
operator|:
name|m_count
argument_list|(
literal|0
argument_list|)
operator|,
name|result
argument_list|(
argument|_result
argument_list|)
block|{ }
comment|// construct with result
name|ResultItem
argument_list|()
operator|:
name|m_count
argument_list|(
literal|0
argument_list|)
operator|,
name|result
argument_list|(
literal|0
argument_list|)
block|{ }
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|result
operator|!=
literal|0
return|;
block|}
name|bool
name|isVector
argument_list|()
specifier|const
block|{
return|return
name|m_count
operator|!=
literal|0
return|;
block|}
name|int
name|count
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_count
operator|==
literal|0
operator|)
operator|?
literal|1
operator|:
name|m_count
return|;
block|}
name|int
name|m_count
decl_stmt|;
comment|// result is either a pointer to a result or to a vector of results,
specifier|const
name|void
modifier|*
name|result
decl_stmt|;
comment|// if count is 0 it's a result, otherwise it's a vector.
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|ResultIteratorBase
block|{
name|public
label|:
name|ResultIteratorBase
argument_list|()
expr_stmt|;
name|ResultIteratorBase
argument_list|(
argument|QMap<int
argument_list|,
argument|ResultItem>::const_iterator _mapIterator
argument_list|,
argument|int _vectorIndex =
literal|0
argument_list|)
empty_stmt|;
name|int
name|vectorIndex
argument_list|()
specifier|const
expr_stmt|;
name|int
name|resultIndex
argument_list|()
specifier|const
expr_stmt|;
name|ResultIteratorBase
name|operator
operator|++
operator|(
operator|)
expr_stmt|;
name|int
name|batchSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|batchedAdvance
parameter_list|()
function_decl|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ResultIteratorBase
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|ResultIteratorBase
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|bool
name|isVector
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|canIncrementVectorIndex
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|QMap
operator|<
name|int
operator|,
name|ResultItem
operator|>
operator|::
name|const_iterator
name|mapIterator
expr_stmt|;
name|int
name|m_vectorIndex
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ResultIterator
operator|:
name|public
name|ResultIteratorBase
block|{
name|public
operator|:
name|ResultIterator
argument_list|(
specifier|const
name|ResultIteratorBase
operator|&
name|base
argument_list|)
operator|:
name|ResultIteratorBase
argument_list|(
argument|base
argument_list|)
block|{ }
specifier|const
name|T
operator|&
name|value
argument_list|()
specifier|const
block|{
return|return
operator|*
name|pointer
argument_list|()
return|;
block|}
specifier|const
name|T
operator|*
name|pointer
argument_list|()
specifier|const
block|{
if|if
condition|(
name|mapIterator
operator|.
name|value
argument_list|()
operator|.
name|isVector
argument_list|()
condition|)
return|return
operator|&
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|QVector
operator|<
name|T
operator|>
operator|*
operator|>
operator|(
name|mapIterator
operator|.
name|value
argument_list|()
operator|.
name|result
operator|)
operator|->
name|at
argument_list|(
name|m_vectorIndex
argument_list|)
operator|)
return|;
else|else
return|return
name|reinterpret_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|mapIterator
operator|.
name|value
argument_list|()
operator|.
name|result
operator|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
unit|};
name|class
name|Q_CORE_EXPORT
name|ResultStoreBase
block|{
name|public
label|:
name|ResultStoreBase
argument_list|()
expr_stmt|;
name|void
name|setFilterMode
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|bool
name|filterMode
argument_list|()
specifier|const
expr_stmt|;
name|int
name|addResult
parameter_list|(
name|int
name|index
parameter_list|,
specifier|const
name|void
modifier|*
name|result
parameter_list|)
function_decl|;
name|int
name|addResults
parameter_list|(
name|int
name|index
parameter_list|,
specifier|const
name|void
modifier|*
name|results
parameter_list|,
name|int
name|vectorSize
parameter_list|,
name|int
name|logicalCount
parameter_list|)
function_decl|;
name|ResultIteratorBase
name|begin
argument_list|()
specifier|const
expr_stmt|;
name|ResultIteratorBase
name|end
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|hasNextResult
argument_list|()
specifier|const
expr_stmt|;
name|ResultIteratorBase
name|resultAt
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|bool
name|contains
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|int
name|count
argument_list|()
specifier|const
expr_stmt|;
name|virtual
operator|~
name|ResultStoreBase
argument_list|()
block|{ }
expr_stmt|;
name|protected
label|:
name|int
name|insertResultItem
parameter_list|(
name|int
name|index
parameter_list|,
name|ResultItem
modifier|&
name|resultItem
parameter_list|)
function_decl|;
name|void
name|insertResultItemIfValid
parameter_list|(
name|int
name|index
parameter_list|,
name|ResultItem
modifier|&
name|resultItem
parameter_list|)
function_decl|;
name|void
name|syncPendingResults
parameter_list|()
function_decl|;
name|void
name|syncResultCount
parameter_list|()
function_decl|;
name|int
name|updateInsertIndex
parameter_list|(
name|int
name|index
parameter_list|,
name|int
name|_count
parameter_list|)
function_decl|;
name|QMap
operator|<
name|int
operator|,
name|ResultItem
operator|>
name|m_results
expr_stmt|;
name|int
name|insertIndex
decl_stmt|;
comment|// The index where the next results(s) will be inserted.
name|int
name|resultCount
decl_stmt|;
comment|// The number of consecutive results stored, starting at index 0.
name|bool
name|m_filterMode
decl_stmt|;
name|QMap
operator|<
name|int
operator|,
name|ResultItem
operator|>
name|pendingResults
expr_stmt|;
name|int
name|filteredResults
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ResultStore
operator|:
name|public
name|ResultStoreBase
block|{
name|public
operator|:
name|ResultStore
argument_list|()
block|{ }
name|ResultStore
argument_list|(
specifier|const
name|ResultStoreBase
operator|&
name|base
argument_list|)
operator|:
name|ResultStoreBase
argument_list|(
argument|base
argument_list|)
block|{ }
name|int
name|addResult
argument_list|(
argument|int index
argument_list|,
argument|const T  *result
argument_list|)
block|{
if|if
condition|(
name|result
operator|==
literal|0
condition|)
return|return
name|ResultStoreBase
operator|::
name|addResult
argument_list|(
name|index
argument_list|,
name|result
argument_list|)
return|;
else|else
return|return
name|ResultStoreBase
operator|::
name|addResult
argument_list|(
argument|index
argument_list|,
argument|new T(*result)
argument_list|)
return|;
block|}
name|int
name|addResults
argument_list|(
argument|int index
argument_list|,
argument|const QVector<T> *results
argument_list|)
block|{
return|return
name|ResultStoreBase
operator|::
name|addResults
argument_list|(
argument|index
argument_list|,
argument|new QVector<T>(*results)
argument_list|,
argument|results->count()
argument_list|,
argument|results->count()
argument_list|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|int
name|addResults
argument_list|(
name|int
name|index
argument_list|,
specifier|const
name|QVector
operator|<
name|T
operator|>
operator|*
name|results
argument_list|,
name|int
name|totalCount
argument_list|)
block|{
return|return
name|ResultStoreBase
operator|::
name|addResults
argument_list|(
argument|index
argument_list|,
argument|new QVector<T>(*results)
argument_list|,
argument|results->count()
argument_list|,
argument|totalCount
argument_list|)
return|;
block|}
end_decl_stmt
begin_function
name|int
name|addCanceledResult
parameter_list|(
name|int
name|index
parameter_list|)
block|{
return|return
name|addResult
argument_list|(
name|index
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
begin_function
name|int
name|addCanceledResults
parameter_list|(
name|int
name|index
parameter_list|,
name|int
name|_count
parameter_list|)
block|{
name|QVector
operator|<
name|T
operator|>
name|empty
expr_stmt|;
return|return
name|addResults
argument_list|(
name|index
argument_list|,
operator|&
name|empty
argument_list|,
name|_count
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
name|ResultIterator
operator|<
name|T
operator|>
name|begin
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ResultIterator
operator|<
name|T
operator|>
expr|>
operator|(
name|ResultStoreBase
operator|::
name|begin
argument_list|()
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|ResultIterator
operator|<
name|T
operator|>
name|end
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ResultIterator
operator|<
name|T
operator|>
expr|>
operator|(
name|ResultStoreBase
operator|::
name|end
argument_list|()
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|ResultIterator
operator|<
name|T
operator|>
name|resultAt
argument_list|(
argument|int index
argument_list|)
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ResultIterator
operator|<
name|T
operator|>
expr|>
operator|(
name|ResultStoreBase
operator|::
name|resultAt
argument_list|(
name|index
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_function
name|void
name|clear
parameter_list|()
block|{
name|QMap
operator|<
name|int
operator|,
name|ResultItem
operator|>
operator|::
name|const_iterator
name|mapIterator
operator|=
name|m_results
operator|.
name|constBegin
argument_list|()
expr_stmt|;
while|while
condition|(
name|mapIterator
operator|!=
name|m_results
operator|.
name|constEnd
argument_list|()
condition|)
block|{
if|if
condition|(
name|mapIterator
operator|.
name|value
argument_list|()
operator|.
name|isVector
argument_list|()
condition|)
name|delete
name|reinterpret_cast
operator|<
specifier|const
name|QVector
operator|<
name|T
operator|>
operator|*
operator|>
operator|(
name|mapIterator
operator|.
name|value
argument_list|()
operator|.
name|result
operator|)
expr_stmt|;
else|else
name|delete
name|reinterpret_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|mapIterator
operator|.
name|value
argument_list|()
operator|.
name|result
operator|)
expr_stmt|;
operator|++
name|mapIterator
expr_stmt|;
block|}
name|resultCount
operator|=
literal|0
expr_stmt|;
name|m_results
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_expr_stmt
operator|~
name|ResultStore
argument_list|()
block|{
name|clear
argument_list|()
block|;     }
end_expr_stmt
begin_comment
unit|};  }
comment|// namespace QtConcurrent
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//qdoc
end_comment
begin_macro
unit|QT_END_NAMESPACE
name|QT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CONCURRENT
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
