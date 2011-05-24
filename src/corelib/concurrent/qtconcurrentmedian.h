begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTCONCURRENT_MEDIAN_H
end_ifndef
begin_define
DECL|macro|QTCONCURRENT_MEDIAN_H
define|#
directive|define
name|QTCONCURRENT_MEDIAN_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONCURRENT
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qalgorithms.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
ifndef|#
directive|ifndef
name|qdoc
name|namespace
name|QtConcurrent
decl_stmt|{  template<typename T> class Median
block|{
name|public
label|:
name|Median
argument_list|(
argument|int _bufferSize
argument_list|)
block|:
name|currentMedian
argument_list|()
operator|,
name|bufferSize
argument_list|(
name|_bufferSize
argument_list|)
operator|,
name|currentIndex
argument_list|(
literal|0
argument_list|)
operator|,
name|valid
argument_list|(
name|false
argument_list|)
operator|,
name|dirty
argument_list|(
argument|true
argument_list|)
block|{
name|values
operator|.
name|resize
argument_list|(
name|bufferSize
argument_list|)
block|;     }
name|void
name|reset
argument_list|()
block|{
name|values
operator|.
name|fill
argument_list|(
literal|0
argument_list|)
block|;
name|currentIndex
operator|=
literal|0
block|;
name|valid
operator|=
name|false
block|;
name|dirty
operator|=
name|true
block|;     }
name|void
name|addValue
argument_list|(
argument|T value
argument_list|)
block|{
name|currentIndex
operator|=
operator|(
operator|(
name|currentIndex
operator|+
literal|1
operator|)
operator|%
name|bufferSize
operator|)
block|;
if|if
condition|(
name|valid
operator|==
name|false
operator|&&
name|currentIndex
operator|%
name|bufferSize
operator|==
literal|0
condition|)
name|valid
operator|=
name|true
expr_stmt|;
comment|// Only update the cached median value when we have to, that
comment|// is when the new value is on then other side of the median
comment|// compared to the current value at the index.
specifier|const
name|T
name|currentIndexValue
operator|=
name|values
index|[
name|currentIndex
index|]
expr_stmt|;
if|if
condition|(
operator|(
name|currentIndexValue
operator|>
name|currentMedian
operator|&&
name|currentMedian
operator|>
name|value
operator|)
operator|||
operator|(
name|currentMedian
operator|>
name|currentIndexValue
operator|&&
name|value
operator|>
name|currentMedian
operator|)
condition|)
block|{
name|dirty
operator|=
name|true
expr_stmt|;
block|}
name|values
index|[
name|currentIndex
index|]
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|bool
name|isMedianValid
argument_list|()
specifier|const
block|{
return|return
name|valid
return|;
block|}
end_expr_stmt
begin_function
name|T
name|median
parameter_list|()
block|{
if|if
condition|(
name|dirty
condition|)
block|{
name|dirty
operator|=
name|false
expr_stmt|;
name|QVector
operator|<
name|T
operator|>
name|sorted
operator|=
name|values
expr_stmt|;
name|qSort
argument_list|(
name|sorted
argument_list|)
expr_stmt|;
name|currentMedian
operator|=
name|sorted
operator|.
name|at
argument_list|(
name|bufferSize
operator|/
literal|2
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
name|currentMedian
return|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|QVector
operator|<
name|T
operator|>
name|values
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|T
name|currentMedian
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|bufferSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|currentIndex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|valid
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|dirty
decl_stmt|;
end_decl_stmt
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
