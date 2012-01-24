begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QREFCOUNT_H
end_ifndef
begin_define
DECL|macro|QREFCOUNT_H
define|#
directive|define
name|QREFCOUNT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|namespace
name|QtPrivate
block|{
name|class
name|RefCount
block|{
name|public
label|:
specifier|inline
name|void
name|ref
parameter_list|()
block|{
if|if
condition|(
name|atomic
operator|.
name|load
argument_list|()
operator|>
literal|0
condition|)
name|atomic
operator|.
name|ref
argument_list|()
expr_stmt|;
block|}
specifier|inline
name|bool
name|deref
parameter_list|()
block|{
if|if
condition|(
name|atomic
operator|.
name|load
argument_list|()
operator|<=
literal|0
condition|)
return|return
name|true
return|;
return|return
name|atomic
operator|.
name|deref
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|int
name|value
operator|)
specifier|const
block|{
return|return
name|atomic
operator|.
name|load
argument_list|()
operator|==
name|value
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|int
name|value
operator|)
specifier|const
block|{
return|return
name|atomic
operator|.
name|load
argument_list|()
operator|!=
name|value
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
operator|!
name|atomic
operator|.
name|load
argument_list|()
return|;
block|}
specifier|inline
name|operator
name|int
argument_list|()
specifier|const
block|{
return|return
name|atomic
operator|.
name|load
argument_list|()
return|;
block|}
specifier|inline
name|RefCount
modifier|&
name|operator
init|=
operator|(
name|int
name|value
operator|)
block|{
name|atomic
operator|.
name|store
argument_list|(
name|value
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|RefCount
modifier|&
name|operator
init|=
operator|(
specifier|const
name|RefCount
operator|&
name|other
operator|)
block|{
name|atomic
operator|.
name|store
argument_list|(
name|other
operator|.
name|atomic
operator|.
name|load
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|QBasicAtomicInt
name|atomic
decl_stmt|;
block|}
empty_stmt|;
DECL|macro|Q_REFCOUNT_INITIALIZER
define|#
directive|define
name|Q_REFCOUNT_INITIALIZER
parameter_list|(
name|a
parameter_list|)
value|{ Q_BASIC_ATOMIC_INITIALIZER(a) }
block|}
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
