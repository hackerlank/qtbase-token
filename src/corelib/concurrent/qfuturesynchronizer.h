begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFUTRUESYNCHRONIZER_H
end_ifndef
begin_define
DECL|macro|QFUTRUESYNCHRONIZER_H
define|#
directive|define
name|QFUTRUESYNCHRONIZER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qfuture.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONCURRENT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
name|template
decl|<
name|typename
name|T
decl|>
name|class
name|QFutureSynchronizer
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QFutureSynchronizer
argument_list|)
name|public
label|:
name|QFutureSynchronizer
argument_list|()
operator|:
name|m_cancelOnWait
argument_list|(
argument|false
argument_list|)
block|{ }
name|explicit
name|QFutureSynchronizer
argument_list|(
specifier|const
name|QFuture
operator|<
name|T
operator|>
operator|&
name|future
argument_list|)
operator|:
name|m_cancelOnWait
argument_list|(
argument|false
argument_list|)
block|{
name|addFuture
argument_list|(
name|future
argument_list|)
block|; }
operator|~
name|QFutureSynchronizer
argument_list|()
block|{
name|waitForFinished
argument_list|()
block|; }
name|void
name|setFuture
argument_list|(
argument|const QFuture<T>&future
argument_list|)
block|{
name|waitForFinished
argument_list|()
block|;
name|m_futures
operator|.
name|clear
argument_list|()
block|;
name|addFuture
argument_list|(
name|future
argument_list|)
block|;     }
name|void
name|addFuture
argument_list|(
argument|const QFuture<T>&future
argument_list|)
block|{
name|m_futures
operator|.
name|append
argument_list|(
name|future
argument_list|)
block|;     }
name|void
name|waitForFinished
argument_list|()
block|{
if|if
condition|(
name|m_cancelOnWait
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
name|m_futures
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|m_futures
index|[
name|i
index|]
operator|.
name|cancel
argument_list|()
expr_stmt|;
block|}
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_futures
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|m_futures
index|[
name|i
index|]
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
block|}
name|void
name|clearFutures
argument_list|()
block|{
name|m_futures
operator|.
name|clear
argument_list|()
block|;     }
name|QList
operator|<
name|QFuture
operator|<
name|T
operator|>
expr|>
name|futures
argument_list|()
specifier|const
block|{
return|return
name|m_futures
return|;
block|}
name|void
name|setCancelOnWait
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
name|m_cancelOnWait
operator|=
name|enabled
expr_stmt|;
block|}
name|bool
name|cancelOnWait
argument_list|()
specifier|const
block|{
return|return
name|m_cancelOnWait
return|;
block|}
name|protected
label|:
name|QList
operator|<
name|QFuture
operator|<
name|T
operator|>
expr|>
name|m_futures
expr_stmt|;
name|bool
name|m_cancelOnWait
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
begin_comment
comment|// QFUTRUESYNCHRONIZER_H
end_comment
end_unit
