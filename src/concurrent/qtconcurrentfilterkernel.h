begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTCONCURRENT_FILTERKERNEL_H
end_ifndef
begin_define
DECL|macro|QTCONCURRENT_FILTERKERNEL_H
define|#
directive|define
name|QTCONCURRENT_FILTERKERNEL_H
end_define
begin_include
include|#
directive|include
file|<QtConcurrent/qtconcurrent_global.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONCURRENT
end_ifndef
begin_include
include|#
directive|include
file|<QtConcurrent/qtconcurrentiteratekernel.h>
end_include
begin_include
include|#
directive|include
file|<QtConcurrent/qtconcurrentmapkernel.h>
end_include
begin_include
include|#
directive|include
file|<QtConcurrent/qtconcurrentreducekernel.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|Q_QDOC
name|namespace
name|QtConcurrent
block|{
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|qValueType
block|{
typedef|typedef
name|typename
name|T
operator|::
name|value_type
name|value_type
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|qValueType
operator|<
specifier|const
name|T
operator|*
operator|>
block|{
typedef|typedef
name|T
name|value_type
typedef|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|qValueType
operator|<
name|T
operator|*
operator|>
block|{
typedef|typedef
name|T
name|value_type
typedef|;
block|}
empty_stmt|;
comment|// Implementation of filter
name|template
operator|<
name|typename
name|Sequence
operator|,
name|typename
name|KeepFunctor
operator|,
name|typename
name|ReduceFunctor
operator|>
name|class
name|FilterKernel
operator|:
name|public
name|IterateKernel
operator|<
name|typename
name|Sequence
operator|::
name|const_iterator
operator|,
name|void
operator|>
block|{
typedef|typedef
name|ReduceKernel
operator|<
name|ReduceFunctor
operator|,
name|Sequence
operator|,
name|typename
name|Sequence
operator|::
name|value_type
operator|>
name|Reducer
expr_stmt|;
typedef|typedef
name|IterateKernel
operator|<
name|typename
name|Sequence
operator|::
name|const_iterator
operator|,
name|void
operator|>
name|IterateKernelType
expr_stmt|;
typedef|typedef
name|typename
name|ReduceFunctor
operator|::
name|result_type
name|T
expr_stmt|;
name|Sequence
name|reducedResult
decl_stmt|;
name|Sequence
modifier|&
name|sequence
decl_stmt|;
name|KeepFunctor
name|keep
decl_stmt|;
name|ReduceFunctor
name|reduce
decl_stmt|;
name|Reducer
name|reducer
decl_stmt|;
name|public
label|:
name|FilterKernel
argument_list|(
argument|Sequence&_sequence
argument_list|,
argument|KeepFunctor _keep
argument_list|,
argument|ReduceFunctor _reduce
argument_list|)
block|:
name|IterateKernelType
argument_list|(
name|const_cast
operator|<
specifier|const
name|Sequence
operator|&
operator|>
operator|(
name|_sequence
operator|)
operator|.
name|begin
argument_list|()
argument_list|,
name|const_cast
operator|<
specifier|const
name|Sequence
operator|&
operator|>
operator|(
name|_sequence
operator|)
operator|.
name|end
argument_list|()
argument_list|)
operator|,
name|reducedResult
argument_list|()
operator|,
name|sequence
argument_list|(
name|_sequence
argument_list|)
operator|,
name|keep
argument_list|(
name|_keep
argument_list|)
operator|,
name|reduce
argument_list|(
name|_reduce
argument_list|)
operator|,
name|reducer
argument_list|(
argument|OrderedReduce
argument_list|)
block|{ }
name|bool
name|runIteration
argument_list|(
argument|typename Sequence::const_iterator it
argument_list|,
argument|int index
argument_list|,
argument|T *
argument_list|)
block|{
name|IntermediateResults
operator|<
name|typename
name|Sequence
operator|::
name|value_type
operator|>
name|results
block|;
name|results
operator|.
name|begin
operator|=
name|index
block|;
name|results
operator|.
name|end
operator|=
name|index
operator|+
literal|1
block|;
if|if
condition|(
name|keep
argument_list|(
operator|*
name|it
argument_list|)
condition|)
name|results
operator|.
name|vector
operator|.
name|append
argument_list|(
operator|*
name|it
argument_list|)
expr_stmt|;
name|reducer
operator|.
name|runReduce
argument_list|(
name|reduce
argument_list|,
name|reducedResult
argument_list|,
name|results
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|bool
name|runIterations
argument_list|(
name|typename
name|Sequence
operator|::
name|const_iterator
name|sequenceBeginIterator
argument_list|,
name|int
name|begin
argument_list|,
name|int
name|end
argument_list|,
name|T
operator|*
argument_list|)
block|{
name|IntermediateResults
operator|<
name|typename
name|Sequence
operator|::
name|value_type
operator|>
name|results
expr_stmt|;
name|results
operator|.
name|begin
operator|=
name|begin
expr_stmt|;
name|results
operator|.
name|end
operator|=
name|end
expr_stmt|;
name|results
operator|.
name|vector
operator|.
name|reserve
argument_list|(
name|end
operator|-
name|begin
argument_list|)
expr_stmt|;
name|typename
name|Sequence
operator|::
name|const_iterator
name|it
operator|=
name|sequenceBeginIterator
expr_stmt|;
name|advance
argument_list|(
name|it
argument_list|,
name|begin
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|begin
init|;
name|i
operator|<
name|end
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|keep
argument_list|(
operator|*
name|it
argument_list|)
condition|)
name|results
operator|.
name|vector
operator|.
name|append
argument_list|(
operator|*
name|it
argument_list|)
expr_stmt|;
name|advance
argument_list|(
name|it
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|reducer
operator|.
name|runReduce
argument_list|(
name|reduce
argument_list|,
name|reducedResult
argument_list|,
name|results
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
end_decl_stmt
begin_function
name|void
name|finish
parameter_list|()
block|{
name|reducer
operator|.
name|finish
argument_list|(
name|reduce
argument_list|,
name|reducedResult
argument_list|)
expr_stmt|;
name|sequence
operator|=
name|reducedResult
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|bool
name|shouldThrottleThread
parameter_list|()
block|{
return|return
name|IterateKernelType
operator|::
name|shouldThrottleThread
argument_list|()
operator|||
name|reducer
operator|.
name|shouldThrottle
argument_list|()
return|;
block|}
end_function
begin_function
specifier|inline
name|bool
name|shouldStartThread
parameter_list|()
block|{
return|return
name|IterateKernelType
operator|::
name|shouldStartThread
argument_list|()
operator|&&
name|reducer
operator|.
name|shouldStartThread
argument_list|()
return|;
block|}
end_function
begin_typedef
typedef|typedef
name|void
name|ReturnType
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|void
name|ResultType
typedef|;
end_typedef
begin_comment
unit|};
comment|// Implementation of filter-reduce
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|ReducedResultType
operator|,
name|typename
name|Iterator
operator|,
name|typename
name|KeepFunctor
operator|,
name|typename
name|ReduceFunctor
operator|,
name|typename
name|Reducer
operator|=
name|ReduceKernel
operator|<
name|ReduceFunctor
operator|,
name|ReducedResultType
operator|,
name|typename
name|qValueType
operator|<
name|Iterator
operator|>
operator|::
name|value_type
operator|>
expr|>
name|class
name|FilteredReducedKernel
operator|:
name|public
name|IterateKernel
operator|<
name|Iterator
operator|,
name|ReducedResultType
operator|>
block|{
name|ReducedResultType
name|reducedResult
block|;
name|KeepFunctor
name|keep
block|;
name|ReduceFunctor
name|reduce
block|;
name|Reducer
name|reducer
block|;
typedef|typedef
name|IterateKernel
operator|<
name|Iterator
operator|,
name|ReducedResultType
operator|>
name|IterateKernelType
expr_stmt|;
name|public
operator|:
name|FilteredReducedKernel
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|KeepFunctor _keep
argument_list|,
argument|ReduceFunctor _reduce
argument_list|,
argument|ReduceOptions reduceOption
argument_list|)
operator|:
name|IterateKernelType
argument_list|(
name|begin
argument_list|,
name|end
argument_list|)
operator|,
name|reducedResult
argument_list|()
operator|,
name|keep
argument_list|(
name|_keep
argument_list|)
operator|,
name|reduce
argument_list|(
name|_reduce
argument_list|)
operator|,
name|reducer
argument_list|(
argument|reduceOption
argument_list|)
block|{ }
if|#
directive|if
literal|0
expr|FilteredReducedKernel(ReducedResultType initialValue,                           KeepFunctor keep,                           ReduceFunctor reduce,                           ReduceOption reduceOption)         : reducedResult(initialValue), keep(keep), reduce(reduce), reducer(reduceOption)     { }
endif|#
directive|endif
name|bool
name|runIteration
argument_list|(
argument|Iterator it
argument_list|,
argument|int index
argument_list|,
argument|ReducedResultType *
argument_list|)
block|{
name|IntermediateResults
operator|<
name|typename
name|qValueType
operator|<
name|Iterator
operator|>
operator|::
name|value_type
operator|>
name|results
block|;
name|results
operator|.
name|begin
operator|=
name|index
block|;
name|results
operator|.
name|end
operator|=
name|index
operator|+
literal|1
block|;
if|if
condition|(
name|keep
argument_list|(
operator|*
name|it
argument_list|)
condition|)
name|results
operator|.
name|vector
operator|.
name|append
argument_list|(
operator|*
name|it
argument_list|)
expr_stmt|;
name|reducer
operator|.
name|runReduce
argument_list|(
name|reduce
argument_list|,
name|reducedResult
argument_list|,
name|results
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|false
return|;
end_return
begin_macro
unit|}      bool
name|runIterations
argument_list|(
argument|Iterator sequenceBeginIterator
argument_list|,
argument|int begin
argument_list|,
argument|int end
argument_list|,
argument|ReducedResultType *
argument_list|)
end_macro
begin_block
block|{
name|IntermediateResults
operator|<
name|typename
name|qValueType
operator|<
name|Iterator
operator|>
operator|::
name|value_type
operator|>
name|results
expr_stmt|;
name|results
operator|.
name|begin
operator|=
name|begin
expr_stmt|;
name|results
operator|.
name|end
operator|=
name|end
expr_stmt|;
name|results
operator|.
name|vector
operator|.
name|reserve
argument_list|(
name|end
operator|-
name|begin
argument_list|)
expr_stmt|;
name|Iterator
name|it
init|=
name|sequenceBeginIterator
decl_stmt|;
name|advance
argument_list|(
name|it
argument_list|,
name|begin
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|begin
init|;
name|i
operator|<
name|end
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|keep
argument_list|(
operator|*
name|it
argument_list|)
condition|)
name|results
operator|.
name|vector
operator|.
name|append
argument_list|(
operator|*
name|it
argument_list|)
expr_stmt|;
name|advance
argument_list|(
name|it
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|reducer
operator|.
name|runReduce
argument_list|(
name|reduce
argument_list|,
name|reducedResult
argument_list|,
name|results
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
end_block
begin_function
name|void
name|finish
parameter_list|()
block|{
name|reducer
operator|.
name|finish
argument_list|(
name|reduce
argument_list|,
name|reducedResult
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|bool
name|shouldThrottleThread
parameter_list|()
block|{
return|return
name|IterateKernelType
operator|::
name|shouldThrottleThread
argument_list|()
operator|||
name|reducer
operator|.
name|shouldThrottle
argument_list|()
return|;
block|}
end_function
begin_function
specifier|inline
name|bool
name|shouldStartThread
parameter_list|()
block|{
return|return
name|IterateKernelType
operator|::
name|shouldStartThread
argument_list|()
operator|&&
name|reducer
operator|.
name|shouldStartThread
argument_list|()
return|;
block|}
end_function
begin_typedef
typedef|typedef
name|ReducedResultType
name|ReturnType
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|ReducedResultType
name|ResultType
typedef|;
end_typedef
begin_function
name|ReducedResultType
modifier|*
name|result
parameter_list|()
block|{
return|return
operator|&
name|reducedResult
return|;
block|}
end_function
begin_comment
unit|};
comment|// Implementation of filter that reports individual results via QFutureInterface
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|Iterator
operator|,
name|typename
name|KeepFunctor
operator|>
name|class
name|FilteredEachKernel
operator|:
name|public
name|IterateKernel
operator|<
name|Iterator
operator|,
name|typename
name|qValueType
operator|<
name|Iterator
operator|>
operator|::
name|value_type
operator|>
block|{
typedef|typedef
name|typename
name|qValueType
operator|<
name|Iterator
operator|>
operator|::
name|value_type
name|T
expr_stmt|;
end_expr_stmt
begin_typedef
typedef|typedef
name|IterateKernel
operator|<
name|Iterator
operator|,
name|T
operator|>
name|IterateKernelType
expr_stmt|;
end_typedef
begin_decl_stmt
name|KeepFunctor
name|keep
decl_stmt|;
end_decl_stmt
begin_label
name|public
label|:
end_label
begin_typedef
typedef|typedef
name|T
name|ReturnType
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|T
name|ResultType
typedef|;
end_typedef
begin_macro
name|FilteredEachKernel
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|KeepFunctor _keep
argument_list|)
end_macro
begin_expr_stmt
unit|:
name|IterateKernelType
argument_list|(
name|begin
argument_list|,
name|end
argument_list|)
operator|,
name|keep
argument_list|(
argument|_keep
argument_list|)
block|{ }
name|void
name|start
argument_list|()
block|{
if|if
condition|(
name|this
operator|->
name|futureInterface
condition|)
name|this
operator|->
name|futureInterface
operator|->
name|setFilterMode
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|IterateKernelType
operator|::
name|start
argument_list|()
expr_stmt|;
end_expr_stmt
begin_macro
unit|}      bool
name|runIteration
argument_list|(
argument|Iterator it
argument_list|,
argument|int index
argument_list|,
argument|T *
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|keep
argument_list|(
operator|*
name|it
argument_list|)
condition|)
name|this
operator|->
name|reportResult
argument_list|(
operator|&
operator|(
operator|*
name|it
operator|)
argument_list|,
name|index
argument_list|)
expr_stmt|;
else|else
name|this
operator|->
name|reportResult
argument_list|(
literal|0
argument_list|,
name|index
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
end_block
begin_function
name|bool
name|runIterations
parameter_list|(
name|Iterator
name|sequenceBeginIterator
parameter_list|,
name|int
name|begin
parameter_list|,
name|int
name|end
parameter_list|,
name|T
modifier|*
parameter_list|)
block|{
specifier|const
name|int
name|count
init|=
name|end
operator|-
name|begin
decl_stmt|;
name|IntermediateResults
operator|<
name|typename
name|qValueType
operator|<
name|Iterator
operator|>
operator|::
name|value_type
operator|>
name|results
expr_stmt|;
name|results
operator|.
name|begin
operator|=
name|begin
expr_stmt|;
name|results
operator|.
name|end
operator|=
name|end
expr_stmt|;
name|results
operator|.
name|vector
operator|.
name|reserve
argument_list|(
name|count
argument_list|)
expr_stmt|;
name|Iterator
name|it
init|=
name|sequenceBeginIterator
decl_stmt|;
name|advance
argument_list|(
name|it
argument_list|,
name|begin
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|begin
init|;
name|i
operator|<
name|end
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|keep
argument_list|(
operator|*
name|it
argument_list|)
condition|)
name|results
operator|.
name|vector
operator|.
name|append
argument_list|(
operator|*
name|it
argument_list|)
expr_stmt|;
name|advance
argument_list|(
name|it
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|this
operator|->
name|reportResults
argument_list|(
name|results
operator|.
name|vector
argument_list|,
name|begin
argument_list|,
name|count
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|Iterator
operator|,
name|typename
name|KeepFunctor
operator|>
specifier|inline
name|ThreadEngineStarter
operator|<
name|typename
name|qValueType
operator|<
name|Iterator
operator|>
operator|::
name|value_type
operator|>
name|startFiltered
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|KeepFunctor functor
argument_list|)
block|{
return|return
name|startThreadEngine
argument_list|(
argument|new FilteredEachKernel<Iterator
argument_list|,
argument|KeepFunctor>(begin, end, functor)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|Sequence
operator|,
name|typename
name|KeepFunctor
operator|>
specifier|inline
name|ThreadEngineStarter
operator|<
name|typename
name|Sequence
operator|::
name|value_type
operator|>
name|startFiltered
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|KeepFunctor functor
argument_list|)
block|{
typedef|typedef
name|SequenceHolder1
operator|<
name|Sequence
operator|,
name|FilteredEachKernel
operator|<
name|typename
name|Sequence
operator|::
name|const_iterator
operator|,
name|KeepFunctor
operator|>
operator|,
name|KeepFunctor
operator|>
name|SequenceHolderType
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|startThreadEngine
argument_list|(
argument|new SequenceHolderType(sequence, functor)
argument_list|)
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|ResultType
operator|,
name|typename
name|Sequence
operator|,
name|typename
name|MapFunctor
operator|,
name|typename
name|ReduceFunctor
operator|>
specifier|inline
name|ThreadEngineStarter
operator|<
name|ResultType
operator|>
name|startFilteredReduced
argument_list|(
argument|const Sequence& sequence
argument_list|,
argument|MapFunctor mapFunctor
argument_list|,
argument|ReduceFunctor reduceFunctor
argument_list|,
argument|ReduceOptions options
argument_list|)
block|{
typedef|typedef
name|typename
name|Sequence
operator|::
name|const_iterator
name|Iterator
expr_stmt|;
end_expr_stmt
begin_typedef
typedef|typedef
name|ReduceKernel
operator|<
name|ReduceFunctor
operator|,
name|ResultType
operator|,
name|typename
name|qValueType
operator|<
name|Iterator
operator|>
operator|::
name|value_type
operator|>
name|Reducer
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|FilteredReducedKernel
operator|<
name|ResultType
operator|,
name|Iterator
operator|,
name|MapFunctor
operator|,
name|ReduceFunctor
operator|,
name|Reducer
operator|>
name|FilteredReduceType
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|SequenceHolder2
operator|<
name|Sequence
operator|,
name|FilteredReduceType
operator|,
name|MapFunctor
operator|,
name|ReduceFunctor
operator|>
name|SequenceHolderType
expr_stmt|;
end_typedef
begin_return
return|return
name|startThreadEngine
argument_list|(
argument|new SequenceHolderType(sequence, mapFunctor, reduceFunctor, options)
argument_list|)
return|;
end_return
begin_expr_stmt
unit|}   template
operator|<
name|typename
name|ResultType
operator|,
name|typename
name|Iterator
operator|,
name|typename
name|MapFunctor
operator|,
name|typename
name|ReduceFunctor
operator|>
specifier|inline
name|ThreadEngineStarter
operator|<
name|ResultType
operator|>
name|startFilteredReduced
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|MapFunctor mapFunctor
argument_list|,
argument|ReduceFunctor reduceFunctor
argument_list|,
argument|ReduceOptions options
argument_list|)
block|{
typedef|typedef
name|ReduceKernel
operator|<
name|ReduceFunctor
operator|,
name|ResultType
operator|,
name|typename
name|qValueType
operator|<
name|Iterator
operator|>
operator|::
name|value_type
operator|>
name|Reducer
expr_stmt|;
end_expr_stmt
begin_typedef
typedef|typedef
name|FilteredReducedKernel
operator|<
name|ResultType
operator|,
name|Iterator
operator|,
name|MapFunctor
operator|,
name|ReduceFunctor
operator|,
name|Reducer
operator|>
name|FilteredReduceType
expr_stmt|;
end_typedef
begin_return
return|return
name|startThreadEngine
argument_list|(
argument|new FilteredReduceType(begin, end, mapFunctor, reduceFunctor, options)
argument_list|)
return|;
end_return
begin_comment
unit|}   }
comment|// namespace QtConcurrent
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_QDOC
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
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
