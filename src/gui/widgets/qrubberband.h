begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QRUBBERBAND_H
end_ifndef
begin_define
DECL|macro|QRUBBERBAND_H
define|#
directive|define
name|QRUBBERBAND_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_RUBBERBAND
name|class
name|QRubberBandPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionRubberBand
name|class
name|QStyleOptionRubberBand
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QRubberBand
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|Shape
block|{
name|Line
block|,
name|Rectangle
block|}
block|;
name|explicit
name|QRubberBand
argument_list|(
name|Shape
argument_list|,
name|QWidget
operator|*
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QRubberBand
argument_list|()
block|;
name|Shape
name|shape
argument_list|()
specifier|const
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
block|;
specifier|inline
name|void
name|setGeometry
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
specifier|inline
name|void
name|move
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
block|;
specifier|inline
name|void
name|move
argument_list|(
argument|const QPoint&p
argument_list|)
block|{
name|move
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|,
name|p
operator|.
name|y
argument_list|()
argument_list|)
block|; }
specifier|inline
name|void
name|resize
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|)
block|{
name|setGeometry
argument_list|(
name|geometry
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|geometry
argument_list|()
operator|.
name|y
argument_list|()
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
block|; }
specifier|inline
name|void
name|resize
argument_list|(
argument|const QSize&s
argument_list|)
block|{
name|resize
argument_list|(
name|s
operator|.
name|width
argument_list|()
argument_list|,
name|s
operator|.
name|height
argument_list|()
argument_list|)
block|; }
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
argument_list|)
block|;
name|void
name|changeEvent
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|showEvent
argument_list|(
name|QShowEvent
operator|*
argument_list|)
block|;
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
argument_list|)
block|;
name|void
name|moveEvent
argument_list|(
name|QMoveEvent
operator|*
argument_list|)
block|;
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionRubberBand *option
argument_list|)
specifier|const
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QRubberBand
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|setGeometry
specifier|inline
name|void
name|QRubberBand
operator|::
name|setGeometry
argument_list|(
argument|int ax
argument_list|,
argument|int ay
argument_list|,
argument|int aw
argument_list|,
argument|int ah
argument_list|)
block|{
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|,
name|aw
argument_list|,
name|ah
argument_list|)
argument_list|)
block|; }
DECL|function|move
specifier|inline
name|void
name|QRubberBand
operator|::
name|move
argument_list|(
argument|int ax
argument_list|,
argument|int ay
argument_list|)
block|{
name|setGeometry
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|,
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
block|; }
endif|#
directive|endif
comment|// QT_NO_RUBBERBAND
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QRUBBERBAND_H
end_comment
end_unit
