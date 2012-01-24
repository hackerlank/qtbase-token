begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPIXMAPFILTER_H
end_ifndef
begin_define
DECL|macro|QPIXMAPFILTER_H
define|#
directive|define
name|QPIXMAPFILTER_H
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
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qgraphicseffect.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSEFFECT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QPainter
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformPixmap
name|class
name|QPlatformPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPixmapFilterPrivate
name|class
name|QPixmapFilterPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QPixmapFilter
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPixmapFilter
argument_list|)
name|public
operator|:
name|virtual
operator|~
name|QPixmapFilter
argument_list|()
operator|=
literal|0
block|;      enum
name|FilterType
block|{
name|ConvolutionFilter
block|,
name|ColorizeFilter
block|,
name|DropShadowFilter
block|,
name|BlurFilter
block|,
name|UserFilter
operator|=
literal|1024
block|}
block|;
name|FilterType
name|type
argument_list|()
specifier|const
block|;
name|virtual
name|QRectF
name|boundingRectFor
argument_list|(
argument|const QRectF&rect
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|draw
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QPointF&p
argument_list|,
argument|const QPixmap&src
argument_list|,
argument|const QRectF&srcRect = QRectF()
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|protected
operator|:
name|QPixmapFilter
argument_list|(
argument|QPixmapFilterPrivate&d
argument_list|,
argument|FilterType type
argument_list|,
argument|QObject *parent
argument_list|)
block|;
name|QPixmapFilter
argument_list|(
argument|FilterType type
argument_list|,
argument|QObject *parent
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPixmapConvolutionFilterPrivate
name|class
name|QPixmapConvolutionFilterPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QPixmapConvolutionFilter
range|:
name|public
name|QPixmapFilter
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPixmapConvolutionFilter
argument_list|)
name|public
operator|:
name|QPixmapConvolutionFilter
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QPixmapConvolutionFilter
argument_list|()
block|;
name|void
name|setConvolutionKernel
argument_list|(
argument|const qreal *matrix
argument_list|,
argument|int rows
argument_list|,
argument|int columns
argument_list|)
block|;
name|QRectF
name|boundingRectFor
argument_list|(
argument|const QRectF&rect
argument_list|)
specifier|const
block|;
name|void
name|draw
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QPointF&dest
argument_list|,
argument|const QPixmap&src
argument_list|,
argument|const QRectF&srcRect = QRectF()
argument_list|)
specifier|const
block|;
name|private
operator|:
name|friend
name|class
name|QGLPixmapConvolutionFilter
block|;
name|friend
name|class
name|QVGPixmapConvolutionFilter
block|;
specifier|const
name|qreal
operator|*
name|convolutionKernel
argument_list|()
specifier|const
block|;
name|int
name|rows
argument_list|()
specifier|const
block|;
name|int
name|columns
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPixmapBlurFilterPrivate
name|class
name|QPixmapBlurFilterPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QPixmapBlurFilter
range|:
name|public
name|QPixmapFilter
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPixmapBlurFilter
argument_list|)
name|public
operator|:
name|QPixmapBlurFilter
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QPixmapBlurFilter
argument_list|()
block|;
name|void
name|setRadius
argument_list|(
argument|qreal radius
argument_list|)
block|;
name|void
name|setBlurHints
argument_list|(
argument|QGraphicsBlurEffect::BlurHints hints
argument_list|)
block|;
name|qreal
name|radius
argument_list|()
specifier|const
block|;
name|QGraphicsBlurEffect
operator|::
name|BlurHints
name|blurHints
argument_list|()
specifier|const
block|;
name|QRectF
name|boundingRectFor
argument_list|(
argument|const QRectF&rect
argument_list|)
specifier|const
block|;
name|void
name|draw
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QPointF&dest
argument_list|,
argument|const QPixmap&src
argument_list|,
argument|const QRectF&srcRect = QRectF()
argument_list|)
specifier|const
block|;
name|private
operator|:
name|friend
name|class
name|QGLPixmapBlurFilter
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPixmapColorizeFilterPrivate
name|class
name|QPixmapColorizeFilterPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QPixmapColorizeFilter
range|:
name|public
name|QPixmapFilter
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPixmapColorizeFilter
argument_list|)
name|public
operator|:
name|QPixmapColorizeFilter
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|setColor
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|QColor
name|color
argument_list|()
specifier|const
block|;
name|void
name|setStrength
argument_list|(
argument|qreal strength
argument_list|)
block|;
name|qreal
name|strength
argument_list|()
specifier|const
block|;
name|void
name|draw
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QPointF&dest
argument_list|,
argument|const QPixmap&src
argument_list|,
argument|const QRectF&srcRect = QRectF()
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPixmapDropShadowFilterPrivate
name|class
name|QPixmapDropShadowFilterPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QPixmapDropShadowFilter
range|:
name|public
name|QPixmapFilter
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPixmapDropShadowFilter
argument_list|)
name|public
operator|:
name|QPixmapDropShadowFilter
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QPixmapDropShadowFilter
argument_list|()
block|;
name|QRectF
name|boundingRectFor
argument_list|(
argument|const QRectF&rect
argument_list|)
specifier|const
block|;
name|void
name|draw
argument_list|(
argument|QPainter *p
argument_list|,
argument|const QPointF&pos
argument_list|,
argument|const QPixmap&px
argument_list|,
argument|const QRectF&src = QRectF()
argument_list|)
specifier|const
block|;
name|qreal
name|blurRadius
argument_list|()
specifier|const
block|;
name|void
name|setBlurRadius
argument_list|(
argument|qreal radius
argument_list|)
block|;
name|QColor
name|color
argument_list|()
specifier|const
block|;
name|void
name|setColor
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|QPointF
name|offset
argument_list|()
specifier|const
block|;
name|void
name|setOffset
argument_list|(
specifier|const
name|QPointF
operator|&
name|offset
argument_list|)
block|;
specifier|inline
name|void
name|setOffset
argument_list|(
argument|qreal dx
argument_list|,
argument|qreal dy
argument_list|)
block|{
name|setOffset
argument_list|(
name|QPointF
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|)
argument_list|)
block|; }
block|}
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
comment|//QT_NO_GRAPHICSEFFECT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPIXMAPFILTER_H
end_comment
end_unit
