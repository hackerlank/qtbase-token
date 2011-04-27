begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSITEMANIMATION_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSITEMANIMATION_H
define|#
directive|define
name|QGRAPHICSITEMANIMATION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_GRAPHICSVIEW
argument_list|)
operator|||
operator|(
name|QT_EDITION
operator|&
name|QT_MODULE_GRAPHICSVIEW
operator|)
operator|!=
name|QT_MODULE_GRAPHICSVIEW
end_if
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QGraphicsItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMatrix
name|class
name|QMatrix
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPointF
name|class
name|QPointF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTimeLine
name|class
name|QTimeLine
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
expr|struct
name|QPair
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QGraphicsItemAnimationPrivate
name|class
name|QGraphicsItemAnimationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QGraphicsItemAnimation
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QGraphicsItemAnimation
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QGraphicsItemAnimation
argument_list|()
block|;
name|QGraphicsItem
operator|*
name|item
argument_list|()
specifier|const
block|;
name|void
name|setItem
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|QTimeLine
operator|*
name|timeLine
argument_list|()
specifier|const
block|;
name|void
name|setTimeLine
argument_list|(
name|QTimeLine
operator|*
name|timeLine
argument_list|)
block|;
name|QPointF
name|posAt
argument_list|(
argument|qreal step
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QPair
operator|<
name|qreal
block|,
name|QPointF
operator|>
expr|>
name|posList
argument_list|()
specifier|const
block|;
name|void
name|setPosAt
argument_list|(
argument|qreal step
argument_list|,
argument|const QPointF&pos
argument_list|)
block|;
name|QMatrix
name|matrixAt
argument_list|(
argument|qreal step
argument_list|)
specifier|const
block|;
name|qreal
name|rotationAt
argument_list|(
argument|qreal step
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QPair
operator|<
name|qreal
block|,
name|qreal
operator|>
expr|>
name|rotationList
argument_list|()
specifier|const
block|;
name|void
name|setRotationAt
argument_list|(
argument|qreal step
argument_list|,
argument|qreal angle
argument_list|)
block|;
name|qreal
name|xTranslationAt
argument_list|(
argument|qreal step
argument_list|)
specifier|const
block|;
name|qreal
name|yTranslationAt
argument_list|(
argument|qreal step
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QPair
operator|<
name|qreal
block|,
name|QPointF
operator|>
expr|>
name|translationList
argument_list|()
specifier|const
block|;
name|void
name|setTranslationAt
argument_list|(
argument|qreal step
argument_list|,
argument|qreal dx
argument_list|,
argument|qreal dy
argument_list|)
block|;
name|qreal
name|verticalScaleAt
argument_list|(
argument|qreal step
argument_list|)
specifier|const
block|;
name|qreal
name|horizontalScaleAt
argument_list|(
argument|qreal step
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QPair
operator|<
name|qreal
block|,
name|QPointF
operator|>
expr|>
name|scaleList
argument_list|()
specifier|const
block|;
name|void
name|setScaleAt
argument_list|(
argument|qreal step
argument_list|,
argument|qreal sx
argument_list|,
argument|qreal sy
argument_list|)
block|;
name|qreal
name|verticalShearAt
argument_list|(
argument|qreal step
argument_list|)
specifier|const
block|;
name|qreal
name|horizontalShearAt
argument_list|(
argument|qreal step
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QPair
operator|<
name|qreal
block|,
name|QPointF
operator|>
expr|>
name|shearList
argument_list|()
specifier|const
block|;
name|void
name|setShearAt
argument_list|(
argument|qreal step
argument_list|,
argument|qreal sh
argument_list|,
argument|qreal sv
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setStep
argument_list|(
argument|qreal x
argument_list|)
block|;
name|void
name|reset
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|void
name|beforeAnimationStep
argument_list|(
argument|qreal step
argument_list|)
block|;
name|virtual
name|void
name|afterAnimationStep
argument_list|(
argument|qreal step
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsItemAnimation
argument_list|)
name|QGraphicsItemAnimationPrivate
operator|*
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_GRAPHICSVIEW
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
