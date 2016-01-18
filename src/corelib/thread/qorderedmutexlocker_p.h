begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QORDEREDMUTEXLOCKER_P_H
end_ifndef
begin_define
DECL|macro|QORDEREDMUTEXLOCKER_P_H
define|#
directive|define
name|QORDEREDMUTEXLOCKER_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<functional>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*   Locks 2 mutexes in a defined order, avoiding a recursive lock if   we're trying to lock the same mutex twice. */
name|class
name|QOrderedMutexLocker
block|{
name|public
label|:
name|QOrderedMutexLocker
argument_list|(
name|QMutex
operator|*
name|m1
argument_list|,
name|QMutex
operator|*
name|m2
argument_list|)
operator|:
name|mtx1
argument_list|(
operator|(
name|m1
operator|==
name|m2
operator|)
condition|?
name|m1
else|:
operator|(
name|std
operator|::
name|less
operator|<
name|QMutex
operator|*
operator|>
operator|(
operator|)
operator|(
name|m1
operator|,
name|m2
operator|)
condition|?
name|m1
else|:
name|m2
operator|)
argument_list|)
operator|,
name|mtx2
argument_list|(
operator|(
name|m1
operator|==
name|m2
operator|)
condition|?
literal|0
else|:
operator|(
name|std
operator|::
name|less
operator|<
name|QMutex
operator|*
operator|>
operator|(
operator|)
operator|(
name|m1
operator|,
name|m2
operator|)
condition|?
name|m2
else|:
name|m1
operator|)
argument_list|)
operator|,
name|locked
argument_list|(
argument|false
argument_list|)
block|{
name|relock
argument_list|()
block|;     }
operator|~
name|QOrderedMutexLocker
argument_list|()
block|{
name|unlock
argument_list|()
block|;     }
name|void
name|relock
argument_list|()
block|{
if|if
condition|(
operator|!
name|locked
condition|)
block|{
if|if
condition|(
name|mtx1
condition|)
name|mtx1
operator|->
name|lock
argument_list|()
expr_stmt|;
if|if
condition|(
name|mtx2
condition|)
name|mtx2
operator|->
name|lock
argument_list|()
expr_stmt|;
name|locked
operator|=
name|true
expr_stmt|;
block|}
block|}
name|void
name|unlock
argument_list|()
block|{
if|if
condition|(
name|locked
condition|)
block|{
if|if
condition|(
name|mtx1
condition|)
name|mtx1
operator|->
name|unlock
argument_list|()
expr_stmt|;
if|if
condition|(
name|mtx2
condition|)
name|mtx2
operator|->
name|unlock
argument_list|()
expr_stmt|;
name|locked
operator|=
name|false
expr_stmt|;
block|}
block|}
specifier|static
name|bool
name|relock
argument_list|(
argument|QMutex *mtx1
argument_list|,
argument|QMutex *mtx2
argument_list|)
block|{
comment|// mtx1 is already locked, mtx2 not... do we need to unlock and relock?
if|if
condition|(
name|mtx1
operator|==
name|mtx2
condition|)
return|return
name|false
return|;
if|if
condition|(
name|mtx1
operator|<
name|mtx2
condition|)
block|{
name|mtx2
operator|->
name|lock
argument_list|()
expr_stmt|;
return|return
name|true
return|;
block|}
if|if
condition|(
operator|!
name|mtx2
operator|->
name|tryLock
argument_list|()
condition|)
block|{
name|mtx1
operator|->
name|unlock
argument_list|()
expr_stmt|;
name|mtx2
operator|->
name|lock
argument_list|()
expr_stmt|;
name|mtx1
operator|->
name|lock
argument_list|()
expr_stmt|;
block|}
return|return
name|true
return|;
block|}
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QMutex
modifier|*
name|mtx1
decl_stmt|,
modifier|*
name|mtx2
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|locked
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
