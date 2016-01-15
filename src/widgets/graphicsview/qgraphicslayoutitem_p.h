begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSLAYOUTITEM_P_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSLAYOUTITEM_P_H
define|#
directive|define
name|QGRAPHICSLAYOUTITEM_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
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
file|<QtCore/QSizeF>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSizePolicy>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGraphicsLayoutItem
name|class
name|QGraphicsLayoutItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QGraphicsLayoutItemPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGraphicsLayoutItem
argument_list|)
name|public
label|:
name|virtual
operator|~
name|QGraphicsLayoutItemPrivate
argument_list|()
expr_stmt|;
name|QGraphicsLayoutItemPrivate
argument_list|(
argument|QGraphicsLayoutItem *parent
argument_list|,
argument|bool isLayout
argument_list|)
empty_stmt|;
specifier|static
name|QGraphicsLayoutItemPrivate
modifier|*
name|get
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|q
parameter_list|)
block|{
return|return
name|q
operator|->
name|d_func
argument_list|()
return|;
block|}
specifier|static
specifier|const
name|QGraphicsLayoutItemPrivate
modifier|*
name|get
parameter_list|(
specifier|const
name|QGraphicsLayoutItem
modifier|*
name|q
parameter_list|)
block|{
return|return
name|q
operator|->
name|d_func
argument_list|()
return|;
block|}
name|void
name|init
parameter_list|()
function_decl|;
name|QSizeF
modifier|*
name|effectiveSizeHints
argument_list|(
specifier|const
name|QSizeF
operator|&
name|constraint
argument_list|)
decl|const
decl_stmt|;
name|QGraphicsItem
operator|*
name|parentItem
argument_list|()
specifier|const
expr_stmt|;
name|void
name|ensureUserSizeHints
parameter_list|()
function_decl|;
name|void
name|setSize
argument_list|(
name|Qt
operator|::
name|SizeHint
name|which
argument_list|,
specifier|const
name|QSizeF
operator|&
name|size
argument_list|)
decl_stmt|;
enum|enum
name|SizeComponent
block|{
name|Width
block|,
name|Height
block|}
enum|;
name|void
name|setSizeComponent
argument_list|(
name|Qt
operator|::
name|SizeHint
name|which
argument_list|,
name|SizeComponent
name|component
argument_list|,
name|qreal
name|value
argument_list|)
decl_stmt|;
name|bool
name|hasHeightForWidth
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|hasWidthForHeight
argument_list|()
specifier|const
expr_stmt|;
name|QSizePolicy
name|sizePolicy
decl_stmt|;
name|QGraphicsLayoutItem
modifier|*
name|parent
decl_stmt|;
name|QSizeF
modifier|*
name|userSizeHints
decl_stmt|;
name|mutable
name|QSizeF
name|cachedSizeHints
index|[
name|Qt
operator|::
name|NSizeHints
index|]
decl_stmt|;
name|mutable
name|QSizeF
name|cachedConstraint
decl_stmt|;
name|mutable
name|QSizeF
name|cachedSizeHintsWithConstraints
index|[
name|Qt
operator|::
name|NSizeHints
index|]
decl_stmt|;
name|mutable
name|quint32
name|sizeHintCacheDirty
range|:
literal|1
decl_stmt|;
name|mutable
name|quint32
name|sizeHintWithConstraintCacheDirty
range|:
literal|1
decl_stmt|;
name|quint32
name|isLayout
range|:
literal|1
decl_stmt|;
name|quint32
name|ownedByLayout
range|:
literal|1
decl_stmt|;
name|QGraphicsLayoutItem
modifier|*
name|q_ptr
decl_stmt|;
name|QRectF
name|geom
decl_stmt|;
name|QGraphicsItem
modifier|*
name|graphicsItem
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QGRAPHICSLAYOUTITEM_P_H
end_comment
end_unit
