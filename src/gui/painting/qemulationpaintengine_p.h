begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEMULATIONPAINTENGINE_P_H
end_ifndef
begin_define
DECL|macro|QEMULATIONPAINTENGINE_P_H
define|#
directive|define
name|QEMULATIONPAINTENGINE_P_H
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
file|<private/qpaintengineex_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QEmulationPaintEngine
range|:
name|public
name|QPaintEngineEx
block|{
name|public
operator|:
name|QEmulationPaintEngine
argument_list|(
name|QPaintEngineEx
operator|*
name|engine
argument_list|)
block|;
name|virtual
name|bool
name|begin
argument_list|(
name|QPaintDevice
operator|*
name|pdev
argument_list|)
block|;
name|virtual
name|bool
name|end
argument_list|()
block|;
name|virtual
name|Type
name|type
argument_list|()
specifier|const
block|;
name|virtual
name|QPainterState
operator|*
name|createState
argument_list|(
argument|QPainterState *orig
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|fill
argument_list|(
specifier|const
name|QVectorPath
operator|&
name|path
argument_list|,
specifier|const
name|QBrush
operator|&
name|brush
argument_list|)
block|;
name|virtual
name|void
name|stroke
argument_list|(
specifier|const
name|QVectorPath
operator|&
name|path
argument_list|,
specifier|const
name|QPen
operator|&
name|pen
argument_list|)
block|;
name|virtual
name|void
name|clip
argument_list|(
argument|const QVectorPath&path
argument_list|,
argument|Qt::ClipOperation op
argument_list|)
block|;
name|virtual
name|void
name|drawPixmap
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pm
argument_list|,
specifier|const
name|QRectF
operator|&
name|sr
argument_list|)
block|;
name|virtual
name|void
name|drawTextItem
argument_list|(
specifier|const
name|QPointF
operator|&
name|p
argument_list|,
specifier|const
name|QTextItem
operator|&
name|textItem
argument_list|)
block|;
name|virtual
name|void
name|drawStaticTextItem
argument_list|(
name|QStaticTextItem
operator|*
name|item
argument_list|)
block|;
name|virtual
name|void
name|drawTiledPixmap
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|,
specifier|const
name|QPointF
operator|&
name|s
argument_list|)
block|;
name|virtual
name|void
name|drawImage
argument_list|(
argument|const QRectF&r
argument_list|,
argument|const QImage&pm
argument_list|,
argument|const QRectF&sr
argument_list|,
argument|Qt::ImageConversionFlags flags
argument_list|)
block|;
name|virtual
name|void
name|clipEnabledChanged
argument_list|()
block|;
name|virtual
name|void
name|penChanged
argument_list|()
block|;
name|virtual
name|void
name|brushChanged
argument_list|()
block|;
name|virtual
name|void
name|brushOriginChanged
argument_list|()
block|;
name|virtual
name|void
name|opacityChanged
argument_list|()
block|;
name|virtual
name|void
name|compositionModeChanged
argument_list|()
block|;
name|virtual
name|void
name|renderHintsChanged
argument_list|()
block|;
name|virtual
name|void
name|transformChanged
argument_list|()
block|;
name|virtual
name|void
name|setState
argument_list|(
name|QPainterState
operator|*
name|s
argument_list|)
block|;
name|virtual
name|void
name|beginNativePainting
argument_list|()
block|;
name|virtual
name|void
name|endNativePainting
argument_list|()
block|;
name|virtual
name|uint
name|flags
argument_list|()
specifier|const
block|{
return|return
name|QPaintEngineEx
operator|::
name|IsEmulationEngine
operator||
name|QPaintEngineEx
operator|::
name|DoNotEmulate
return|;
block|}
specifier|inline
name|QPainterState
operator|*
name|state
argument_list|()
block|{
return|return
operator|(
name|QPainterState
operator|*
operator|)
name|QPaintEngine
operator|::
name|state
return|;
block|}
specifier|inline
specifier|const
name|QPainterState
operator|*
name|state
argument_list|()
specifier|const
block|{
return|return
operator|(
specifier|const
name|QPainterState
operator|*
operator|)
name|QPaintEngine
operator|::
name|state
return|;
block|}
name|QPaintEngineEx
operator|*
name|real_engine
block|;
name|private
operator|:
name|void
name|fillBGRect
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
