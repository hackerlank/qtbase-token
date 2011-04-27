begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSSYSTEM_RUNTIME_P_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSSYSTEM_RUNTIME_P_H
define|#
directive|define
name|QGRAPHICSSYSTEM_RUNTIME_P_H
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
file|"qgraphicssystem_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qpixmapdata_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QRuntimeGraphicsSystem
name|class
name|QRuntimeGraphicsSystem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QRuntimePixmapData
range|:
name|public
name|QPixmapData
block|{
name|public
operator|:
name|QRuntimePixmapData
argument_list|(
argument|const QRuntimeGraphicsSystem *gs
argument_list|,
argument|PixelType type
argument_list|)
block|;
operator|~
name|QRuntimePixmapData
argument_list|()
block|;
name|virtual
name|QPixmapData
operator|*
name|createCompatiblePixmapData
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|resize
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
block|;
name|virtual
name|void
name|fromImage
argument_list|(
argument|const QImage&image
argument_list|,
argument|Qt::ImageConversionFlags flags
argument_list|)
block|;
name|virtual
name|bool
name|fromFile
argument_list|(
argument|const QString&filename
argument_list|,
argument|const char *format
argument_list|,
argument|Qt::ImageConversionFlags flags
argument_list|)
block|;
name|virtual
name|bool
name|fromData
argument_list|(
argument|const uchar *buffer
argument_list|,
argument|uint len
argument_list|,
argument|const char *format
argument_list|,
argument|Qt::ImageConversionFlags flags
argument_list|)
block|;
name|virtual
name|void
name|copy
argument_list|(
specifier|const
name|QPixmapData
operator|*
name|data
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|virtual
name|bool
name|scroll
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|,
argument|const QRect&rect
argument_list|)
block|;
name|virtual
name|int
name|metric
argument_list|(
argument|QPaintDevice::PaintDeviceMetric metric
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|fill
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|virtual
name|QBitmap
name|mask
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setMask
argument_list|(
specifier|const
name|QBitmap
operator|&
name|mask
argument_list|)
block|;
name|virtual
name|bool
name|hasAlphaChannel
argument_list|()
specifier|const
block|;
name|virtual
name|QPixmap
name|transformed
argument_list|(
argument|const QTransform&matrix
argument_list|,
argument|Qt::TransformationMode mode
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|setAlphaChannel
argument_list|(
specifier|const
name|QPixmap
operator|&
name|alphaChannel
argument_list|)
block|;
name|virtual
name|QPixmap
name|alphaChannel
argument_list|()
specifier|const
block|;
name|virtual
name|QImage
name|toImage
argument_list|()
specifier|const
block|;
name|virtual
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
block|;
name|virtual
name|QImage
operator|*
name|buffer
argument_list|()
block|;
name|void
name|readBackInfo
argument_list|()
block|;
name|QPixmapData
operator|*
name|m_data
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|void
operator|*
name|toNativeType
argument_list|(
argument|NativeType type
argument_list|)
block|;
name|void
name|fromNativeType
argument_list|(
argument|void* pixmap
argument_list|,
argument|NativeType type
argument_list|)
block|;
endif|#
directive|endif
name|virtual
name|QPixmapData
operator|*
name|runtimeData
argument_list|()
specifier|const
block|;
name|private
operator|:
specifier|const
name|QRuntimeGraphicsSystem
operator|*
name|m_graphicsSystem
block|;  }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QRuntimeWindowSurface
range|:
name|public
name|QWindowSurface
block|{
name|public
operator|:
name|QRuntimeWindowSurface
argument_list|(
specifier|const
name|QRuntimeGraphicsSystem
operator|*
name|gs
argument_list|,
name|QWidget
operator|*
name|window
argument_list|)
block|;
operator|~
name|QRuntimeWindowSurface
argument_list|()
block|;
name|virtual
name|QPaintDevice
operator|*
name|paintDevice
argument_list|()
block|;
name|virtual
name|void
name|flush
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
specifier|const
name|QRegion
operator|&
name|region
argument_list|,
specifier|const
name|QPoint
operator|&
name|offset
argument_list|)
block|;
name|virtual
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|virtual
name|bool
name|scroll
argument_list|(
argument|const QRegion&area
argument_list|,
argument|int dx
argument_list|,
argument|int dy
argument_list|)
block|;
name|virtual
name|void
name|beginPaint
argument_list|(
specifier|const
name|QRegion
operator|&
argument_list|)
block|;
name|virtual
name|void
name|endPaint
argument_list|(
specifier|const
name|QRegion
operator|&
argument_list|)
block|;
name|virtual
name|QImage
operator|*
name|buffer
argument_list|(
specifier|const
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|virtual
name|QPixmap
name|grabWidget
argument_list|(
argument|const QWidget *widget
argument_list|,
argument|const QRect& rectangle = QRect()
argument_list|)
specifier|const
block|;
name|virtual
name|QPoint
name|offset
argument_list|(
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|virtual
name|WindowSurfaceFeatures
name|features
argument_list|()
specifier|const
block|;
name|QScopedPointer
operator|<
name|QWindowSurface
operator|>
name|m_windowSurface
block|;
name|QScopedPointer
operator|<
name|QWindowSurface
operator|>
name|m_pendingWindowSurface
block|;
name|private
operator|:
specifier|const
name|QRuntimeGraphicsSystem
operator|*
name|m_graphicsSystem
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QRuntimeGraphicsSystem
range|:
name|public
name|QGraphicsSystem
block|{
name|public
operator|:
expr|enum
name|WindowSurfaceDestroyPolicy
block|{
name|DestroyImmediately
block|,
name|DestroyAfterFirstFlush
block|}
block|;
name|public
operator|:
name|QRuntimeGraphicsSystem
argument_list|()
block|;
name|QPixmapData
operator|*
name|createPixmapData
argument_list|(
argument|QPixmapData::PixelType type
argument_list|)
specifier|const
block|;
name|QWindowSurface
operator|*
name|createWindowSurface
argument_list|(
argument|QWidget *widget
argument_list|)
specifier|const
block|;
name|void
name|removePixmapData
argument_list|(
argument|QRuntimePixmapData *pixmapData
argument_list|)
specifier|const
block|;
name|void
name|removeWindowSurface
argument_list|(
argument|QRuntimeWindowSurface *windowSurface
argument_list|)
specifier|const
block|;
name|void
name|setGraphicsSystem
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
name|QString
name|graphicsSystemName
argument_list|()
specifier|const
block|{
return|return
name|m_graphicsSystemName
return|;
block|}
name|void
name|setWindowSurfaceDestroyPolicy
argument_list|(
argument|WindowSurfaceDestroyPolicy policy
argument_list|)
block|{
name|m_windowSurfaceDestroyPolicy
operator|=
name|policy
block|;     }
name|int
name|windowSurfaceDestroyPolicy
argument_list|()
specifier|const
block|{
return|return
name|m_windowSurfaceDestroyPolicy
return|;
block|}
name|private
operator|:
name|int
name|m_windowSurfaceDestroyPolicy
block|;
name|QGraphicsSystem
operator|*
name|m_graphicsSystem
block|;
name|mutable
name|QList
operator|<
name|QRuntimePixmapData
operator|*
operator|>
name|m_pixmapDatas
block|;
name|mutable
name|QList
operator|<
name|QRuntimeWindowSurface
operator|*
operator|>
name|m_windowSurfaces
block|;
name|QString
name|m_graphicsSystemName
block|;
name|QString
name|m_pendingGraphicsSystemName
block|;
name|friend
name|class
name|QRuntimePixmapData
block|;
name|friend
name|class
name|QRuntimeWindowSurface
block|;
name|friend
name|class
name|QMeeGoGraphicsSystem
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
