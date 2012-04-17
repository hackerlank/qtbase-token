begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSLAYOUTITEM_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSLAYOUTITEM_H
define|#
directive|define
name|QGRAPHICSLAYOUTITEM_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qsizepolicy.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qevent.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_GRAPHICSVIEW
argument_list|)
DECL|variable|QGraphicsLayoutItemPrivate
name|class
name|QGraphicsLayoutItemPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsItem
name|class
name|QGraphicsItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsLayoutItem
block|{
name|public
label|:
name|QGraphicsLayoutItem
argument_list|(
argument|QGraphicsLayoutItem *parent =
literal|0
argument_list|,
argument|bool isLayout = false
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|QGraphicsLayoutItem
argument_list|()
expr_stmt|;
name|void
name|setSizePolicy
parameter_list|(
specifier|const
name|QSizePolicy
modifier|&
name|policy
parameter_list|)
function_decl|;
name|void
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Policy
name|hPolicy
argument_list|,
name|QSizePolicy
operator|::
name|Policy
name|vPolicy
argument_list|,
name|QSizePolicy
operator|::
name|ControlType
name|controlType
operator|=
name|QSizePolicy
operator|::
name|DefaultType
argument_list|)
decl_stmt|;
name|QSizePolicy
name|sizePolicy
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMinimumSize
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|size
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setMinimumSize
parameter_list|(
name|qreal
name|w
parameter_list|,
name|qreal
name|h
parameter_list|)
function_decl|;
name|QSizeF
name|minimumSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMinimumWidth
parameter_list|(
name|qreal
name|width
parameter_list|)
function_decl|;
specifier|inline
name|qreal
name|minimumWidth
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMinimumHeight
parameter_list|(
name|qreal
name|height
parameter_list|)
function_decl|;
specifier|inline
name|qreal
name|minimumHeight
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPreferredSize
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|size
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setPreferredSize
parameter_list|(
name|qreal
name|w
parameter_list|,
name|qreal
name|h
parameter_list|)
function_decl|;
name|QSizeF
name|preferredSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPreferredWidth
parameter_list|(
name|qreal
name|width
parameter_list|)
function_decl|;
specifier|inline
name|qreal
name|preferredWidth
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPreferredHeight
parameter_list|(
name|qreal
name|height
parameter_list|)
function_decl|;
specifier|inline
name|qreal
name|preferredHeight
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMaximumSize
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|size
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setMaximumSize
parameter_list|(
name|qreal
name|w
parameter_list|,
name|qreal
name|h
parameter_list|)
function_decl|;
name|QSizeF
name|maximumSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMaximumWidth
parameter_list|(
name|qreal
name|width
parameter_list|)
function_decl|;
specifier|inline
name|qreal
name|maximumWidth
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMaximumHeight
parameter_list|(
name|qreal
name|height
parameter_list|)
function_decl|;
specifier|inline
name|qreal
name|maximumHeight
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|void
name|setGeometry
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
function_decl|;
name|QRectF
name|geometry
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|void
name|getContentsMargins
argument_list|(
name|qreal
operator|*
name|left
argument_list|,
name|qreal
operator|*
name|top
argument_list|,
name|qreal
operator|*
name|right
argument_list|,
name|qreal
operator|*
name|bottom
argument_list|)
decl|const
decl_stmt|;
name|QRectF
name|contentsRect
argument_list|()
specifier|const
expr_stmt|;
name|QSizeF
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|SizeHint
name|which
argument_list|,
specifier|const
name|QSizeF
operator|&
name|constraint
operator|=
name|QSizeF
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|updateGeometry
parameter_list|()
function_decl|;
name|QGraphicsLayoutItem
operator|*
name|parentLayoutItem
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setParentLayoutItem
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|parent
parameter_list|)
function_decl|;
name|bool
name|isLayout
argument_list|()
specifier|const
expr_stmt|;
name|QGraphicsItem
operator|*
name|graphicsItem
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|ownedByLayout
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|void
name|setGraphicsItem
parameter_list|(
name|QGraphicsItem
modifier|*
name|item
parameter_list|)
function_decl|;
name|void
name|setOwnedByLayout
parameter_list|(
name|bool
name|ownedByLayout
parameter_list|)
function_decl|;
name|QGraphicsLayoutItem
argument_list|(
name|QGraphicsLayoutItemPrivate
operator|&
name|dd
argument_list|)
expr_stmt|;
name|virtual
name|QSizeF
name|sizeHint
argument_list|(
name|Qt
operator|::
name|SizeHint
name|which
argument_list|,
specifier|const
name|QSizeF
operator|&
name|constraint
operator|=
name|QSizeF
argument_list|()
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|QScopedPointer
operator|<
name|QGraphicsLayoutItemPrivate
operator|>
name|d_ptr
expr_stmt|;
name|private
label|:
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
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsLayoutItem
argument_list|)
name|friend
name|class
name|QGraphicsLayout
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_INTERFACE
argument_list|(
argument|QGraphicsLayoutItem
argument_list|,
literal|"org.qt-project.Qt.QGraphicsLayoutItem"
argument_list|)
end_macro
begin_expr_stmt
DECL|function|setMinimumSize
specifier|inline
name|void
name|QGraphicsLayoutItem
operator|::
name|setMinimumSize
argument_list|(
argument|qreal aw
argument_list|,
argument|qreal ah
argument_list|)
block|{
name|setMinimumSize
argument_list|(
name|QSizeF
argument_list|(
name|aw
argument_list|,
name|ah
argument_list|)
argument_list|)
block|; }
DECL|function|setPreferredSize
specifier|inline
name|void
name|QGraphicsLayoutItem
operator|::
name|setPreferredSize
argument_list|(
argument|qreal aw
argument_list|,
argument|qreal ah
argument_list|)
block|{
name|setPreferredSize
argument_list|(
name|QSizeF
argument_list|(
name|aw
argument_list|,
name|ah
argument_list|)
argument_list|)
block|; }
DECL|function|setMaximumSize
specifier|inline
name|void
name|QGraphicsLayoutItem
operator|::
name|setMaximumSize
argument_list|(
argument|qreal aw
argument_list|,
argument|qreal ah
argument_list|)
block|{
name|setMaximumSize
argument_list|(
name|QSizeF
argument_list|(
name|aw
argument_list|,
name|ah
argument_list|)
argument_list|)
block|; }
DECL|function|minimumWidth
specifier|inline
name|qreal
name|QGraphicsLayoutItem
operator|::
name|minimumWidth
argument_list|()
specifier|const
block|{
return|return
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|MinimumSize
argument_list|)
operator|.
name|width
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|minimumHeight
specifier|inline
name|qreal
name|QGraphicsLayoutItem
operator|::
name|minimumHeight
argument_list|()
specifier|const
block|{
return|return
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|MinimumSize
argument_list|)
operator|.
name|height
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|preferredWidth
specifier|inline
name|qreal
name|QGraphicsLayoutItem
operator|::
name|preferredWidth
argument_list|()
specifier|const
block|{
return|return
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|PreferredSize
argument_list|)
operator|.
name|width
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|preferredHeight
specifier|inline
name|qreal
name|QGraphicsLayoutItem
operator|::
name|preferredHeight
argument_list|()
specifier|const
block|{
return|return
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|PreferredSize
argument_list|)
operator|.
name|height
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|maximumWidth
specifier|inline
name|qreal
name|QGraphicsLayoutItem
operator|::
name|maximumWidth
argument_list|()
specifier|const
block|{
return|return
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|MaximumSize
argument_list|)
operator|.
name|width
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|maximumHeight
specifier|inline
name|qreal
name|QGraphicsLayoutItem
operator|::
name|maximumHeight
argument_list|()
specifier|const
block|{
return|return
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|MaximumSize
argument_list|)
operator|.
name|height
argument_list|()
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
