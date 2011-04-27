begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QVARIANT_P_H
end_ifndef
begin_define
DECL|macro|QVARIANT_P_H
define|#
directive|define
name|QVARIANT_P_H
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
begin_comment
comment|// takes a type, returns the internal void* pointer cast
end_comment
begin_comment
comment|// to a pointer of the input type
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|Q_CC_SUN
comment|// Sun CC picks the wrong overload, so introduce awful hack
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|v_cast
specifier|inline
name|T
operator|*
name|v_cast
argument_list|(
argument|const QVariant::Private *nd
argument_list|,
argument|T * =
literal|0
argument_list|)
block|{
name|QVariant
operator|::
name|Private
operator|*
name|d
operator|=
name|const_cast
operator|<
name|QVariant
operator|::
name|Private
operator|*
operator|>
operator|(
name|nd
operator|)
block|;
return|return
operator|(
operator|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|QVariant
operator|::
name|Private
operator|::
name|Data
argument_list|)
operator|)
condition|?
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|d
operator|->
name|data
operator|.
name|shared
operator|->
name|ptr
operator|)
else|:
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|static_cast
operator|<
name|void
operator|*
operator|>
operator|(
operator|&
name|d
operator|->
name|data
operator|.
name|c
operator|)
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_comment
comment|// every other compiler in this world
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
specifier|const
name|T
operator|*
name|v_cast
argument_list|(
argument|const QVariant::Private *d
argument_list|,
argument|T * =
literal|0
argument_list|)
block|{
return|return
operator|(
operator|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|QVariant
operator|::
name|Private
operator|::
name|Data
argument_list|)
operator|)
operator|?
name|static_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|d
operator|->
name|data
operator|.
name|shared
operator|->
name|ptr
operator|)
operator|:
name|static_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|void
operator|*
operator|>
operator|(
operator|&
name|d
operator|->
name|data
operator|.
name|c
operator|)
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
operator|*
name|v_cast
argument_list|(
argument|QVariant::Private *d
argument_list|,
argument|T * =
literal|0
argument_list|)
block|{
return|return
operator|(
operator|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|QVariant
operator|::
name|Private
operator|::
name|Data
argument_list|)
operator|)
operator|?
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|d
operator|->
name|data
operator|.
name|shared
operator|->
name|ptr
operator|)
operator|:
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|static_cast
operator|<
name|void
operator|*
operator|>
operator|(
operator|&
name|d
operator|->
name|data
operator|.
name|c
operator|)
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//a simple template that avoids to allocate 2 memory chunks when creating a QVariant
end_comment
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QVariantPrivateSharedEx
operator|:
name|public
name|QVariant
operator|::
name|PrivateShared
block|{
name|public
operator|:
name|QVariantPrivateSharedEx
argument_list|()
operator|:
name|QVariant
operator|::
name|PrivateShared
argument_list|(
argument|&m_t
argument_list|)
block|{ }
name|QVariantPrivateSharedEx
argument_list|(
specifier|const
name|T
operator|&
name|t
argument_list|)
operator|:
name|QVariant
operator|::
name|PrivateShared
argument_list|(
operator|&
name|m_t
argument_list|)
block|,
name|m_t
argument_list|(
argument|t
argument_list|)
block|{ }
name|private
operator|:
name|T
name|m_t
block|; }
expr_stmt|;
end_expr_stmt
begin_comment
comment|// constructs a new variant if copy is 0, otherwise copy-constructs
end_comment
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|v_construct
specifier|inline
name|void
name|v_construct
argument_list|(
argument|QVariant::Private *x
argument_list|,
argument|const void *copy
argument_list|,
argument|T * =
literal|0
argument_list|)
block|{
if|if
condition|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|QVariant
operator|::
name|Private
operator|::
name|Data
argument_list|)
condition|)
block|{
name|x
operator|->
name|data
operator|.
name|shared
operator|=
name|copy
condition|?
name|new
name|QVariantPrivateSharedEx
operator|<
name|T
operator|>
operator|(
operator|*
name|static_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|copy
operator|)
operator|)
else|:
name|new
name|QVariantPrivateSharedEx
operator|<
name|T
operator|>
expr_stmt|;
name|x
operator|->
name|is_shared
operator|=
name|true
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
if|if
condition|(
name|copy
condition|)
name|new
argument_list|(
argument|&x->data.ptr
argument_list|)
name|T
argument_list|(
operator|*
name|static_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|copy
operator|)
argument_list|)
expr_stmt|;
else|else
name|new
argument_list|(
argument|&x->data.ptr
argument_list|)
name|T
expr_stmt|;
block|}
end_else
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|v_construct
specifier|inline
name|void
name|v_construct
argument_list|(
argument|QVariant::Private *x
argument_list|,
argument|const T&t
argument_list|)
block|{
if|if
condition|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|QVariant
operator|::
name|Private
operator|::
name|Data
argument_list|)
condition|)
block|{
name|x
operator|->
name|data
operator|.
name|shared
operator|=
name|new
name|QVariantPrivateSharedEx
operator|<
name|T
operator|>
operator|(
name|t
operator|)
expr_stmt|;
name|x
operator|->
name|is_shared
operator|=
name|true
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
name|new
argument_list|(
argument|&x->data.ptr
argument_list|)
name|T
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
end_else
begin_comment
unit|}
comment|// deletes the internal structures
end_comment
begin_expr_stmt
unit|template
operator|<
name|class
name|T
operator|>
DECL|function|v_clear
specifier|inline
name|void
name|v_clear
argument_list|(
argument|QVariant::Private *d
argument_list|,
argument|T* =
literal|0
argument_list|)
block|{
if|if
condition|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|QVariant
operator|::
name|Private
operator|::
name|Data
argument_list|)
condition|)
block|{
comment|//now we need to cast
comment|//because QVariant::PrivateShared doesn't have a virtual destructor
name|delete
name|static_cast
operator|<
name|QVariantPrivateSharedEx
operator|<
name|T
operator|>
operator|*
operator|>
operator|(
name|d
operator|->
name|data
operator|.
name|shared
operator|)
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
name|v_cast
operator|<
name|T
operator|>
operator|(
name|d
operator|)
operator|->
expr|~
name|T
argument_list|()
expr_stmt|;
block|}
end_else
begin_expr_stmt
unit|}  Q_CORE_EXPORT
specifier|const
name|QVariant
operator|::
name|Handler
operator|*
name|qcoreVariantHandler
argument_list|()
expr_stmt|;
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QVARIANT_P_H
end_comment
end_unit
