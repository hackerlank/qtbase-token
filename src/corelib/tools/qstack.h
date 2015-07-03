begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTACK_H
end_ifndef
begin_define
DECL|macro|QSTACK_H
define|#
directive|define
name|QSTACK_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QStack
operator|:
name|public
name|QVector
operator|<
name|T
operator|>
block|{
name|public
operator|:
comment|// compiler-generated special member functions are fine!
specifier|inline
name|void
name|swap
argument_list|(
argument|QStack<T>&other
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|QVector
operator|<
name|T
operator|>
operator|::
name|swap
argument_list|(
name|other
argument_list|)
block|; }
comment|// prevent QVector<->QStack swaps
specifier|inline
name|void
name|push
argument_list|(
argument|const T&t
argument_list|)
block|{
name|QVector
operator|<
name|T
operator|>
operator|::
name|append
argument_list|(
name|t
argument_list|)
block|; }
name|T
name|pop
argument_list|()
block|;
name|T
operator|&
name|top
argument_list|()
block|;
specifier|const
name|T
operator|&
name|top
argument_list|()
specifier|const
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|pop
specifier|inline
name|T
name|QStack
operator|<
name|T
operator|>
operator|::
name|pop
argument_list|()
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|this
operator|->
name|isEmpty
argument_list|()
argument_list|)
block|;
name|T
name|t
operator|=
name|this
operator|->
name|data
argument_list|()
index|[
name|this
operator|->
name|size
argument_list|()
operator|-
literal|1
index|]
block|;
name|this
operator|->
name|resize
argument_list|(
name|this
operator|->
name|size
argument_list|()
operator|-
literal|1
argument_list|)
block|;
return|return
name|t
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|top
specifier|inline
name|T
operator|&
name|QStack
operator|<
name|T
operator|>
operator|::
name|top
argument_list|()
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|this
operator|->
name|isEmpty
argument_list|()
argument_list|)
block|;
name|this
operator|->
name|detach
argument_list|()
block|;
return|return
name|this
operator|->
name|data
argument_list|()
index|[
name|this
operator|->
name|size
argument_list|()
operator|-
literal|1
index|]
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|top
specifier|inline
specifier|const
name|T
operator|&
name|QStack
operator|<
name|T
operator|>
operator|::
name|top
argument_list|()
specifier|const
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|this
operator|->
name|isEmpty
argument_list|()
argument_list|)
block|;
return|return
name|this
operator|->
name|data
argument_list|()
index|[
name|this
operator|->
name|size
argument_list|()
operator|-
literal|1
index|]
return|;
block|}
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTACK_H
end_comment
end_unit
