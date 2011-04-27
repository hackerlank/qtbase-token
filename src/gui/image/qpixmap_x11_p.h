begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPIXMAPDATA_X11_P_H
end_ifndef
begin_define
DECL|macro|QPIXMAPDATA_X11_P_H
define|#
directive|define
name|QPIXMAPDATA_X11_P_H
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
file|<QtGui/private/qpixmapdata_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpixmapdatafactory_p.h>
end_include
begin_include
include|#
directive|include
file|"QtGui/qx11info_x11.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QX11PaintEngine
name|class
name|QX11PaintEngine
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QXImageWrapper
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QX11PixmapData
range|:
name|public
name|QPixmapData
block|{
name|public
operator|:
name|QX11PixmapData
argument_list|(
argument|PixelType type
argument_list|)
block|;
comment|//     QX11PixmapData(PixelType type, int width, int height);
comment|//     QX11PixmapData(PixelType type, const QImage&image,
comment|//                    Qt::ImageConversionFlags flags);
operator|~
name|QX11PixmapData
argument_list|()
block|;
name|QPixmapData
operator|*
name|createCompatiblePixmapData
argument_list|()
specifier|const
block|;
name|void
name|resize
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
block|;
name|void
name|fromImage
argument_list|(
argument|const QImage&image
argument_list|,
argument|Qt::ImageConversionFlags flags
argument_list|)
block|;
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
name|void
name|fill
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|QBitmap
name|mask
argument_list|()
specifier|const
block|;
name|void
name|setMask
argument_list|(
specifier|const
name|QBitmap
operator|&
name|mask
argument_list|)
block|;
name|bool
name|hasAlphaChannel
argument_list|()
specifier|const
block|;
name|void
name|setAlphaChannel
argument_list|(
specifier|const
name|QPixmap
operator|&
name|alphaChannel
argument_list|)
block|;
name|QPixmap
name|alphaChannel
argument_list|()
specifier|const
block|;
name|QPixmap
name|transformed
argument_list|(
argument|const QTransform&transform
argument_list|,
argument|Qt::TransformationMode mode
argument_list|)
specifier|const
block|;
name|QImage
name|toImage
argument_list|()
specifier|const
block|;
name|QImage
name|toImage
argument_list|(
argument|const QRect&rect
argument_list|)
specifier|const
block|;
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
specifier|const
block|{
return|return
name|hd
return|;
block|}
name|Qt
operator|::
name|HANDLE
name|x11ConvertToDefaultDepth
argument_list|()
block|;
specifier|static
name|Qt
operator|::
name|HANDLE
name|createBitmapFromImage
argument_list|(
specifier|const
name|QImage
operator|&
name|image
argument_list|)
block|;
name|void
operator|*
name|gl_surface
block|;
ifndef|#
directive|ifndef
name|QT_NO_XRENDER
name|void
name|convertToARGB32
argument_list|(
argument|bool preserveContents = true
argument_list|)
block|;
endif|#
directive|endif
name|protected
operator|:
name|int
name|metric
argument_list|(
argument|QPaintDevice::PaintDeviceMetric metric
argument_list|)
specifier|const
block|;
name|private
operator|:
name|friend
name|class
name|QPixmap
block|;
name|friend
name|class
name|QBitmap
block|;
name|friend
name|class
name|QX11PaintEngine
block|;
name|friend
name|class
name|QX11WindowSurface
block|;
name|friend
name|class
name|QRasterWindowSurface
block|;
name|friend
name|class
name|QGLContextPrivate
block|;
comment|// Needs to access xinfo, gl_surface& flags
name|friend
name|class
name|QEglContext
block|;
comment|// Needs gl_surface
name|friend
name|class
name|QGLContext
block|;
comment|// Needs gl_surface
name|friend
name|class
name|QX11GLPixmapData
block|;
comment|// Needs gl_surface
name|friend
name|class
name|QMeeGoLivePixmapData
block|;
comment|// Needs gl_surface and flags
name|friend
name|bool
name|qt_createEGLSurfaceForPixmap
argument_list|(
name|QPixmapData
operator|*
argument_list|,
name|bool
argument_list|)
block|;
comment|// Needs gl_surface
name|void
name|release
argument_list|()
block|;
name|QImage
name|toImage
argument_list|(
argument|const QXImageWrapper&xi
argument_list|,
argument|const QRect&rect
argument_list|)
specifier|const
block|;
name|QBitmap
name|mask_to_bitmap
argument_list|(
argument|int screen
argument_list|)
specifier|const
block|;
specifier|static
name|Qt
operator|::
name|HANDLE
name|bitmap_to_mask
argument_list|(
argument|const QBitmap&
argument_list|,
argument|int screen
argument_list|)
block|;
name|void
name|bitmapFromImage
argument_list|(
specifier|const
name|QImage
operator|&
name|image
argument_list|)
block|;
name|bool
name|canTakeQImageFromXImage
argument_list|(
argument|const QXImageWrapper&xi
argument_list|)
specifier|const
block|;
name|QImage
name|takeQImageFromXImage
argument_list|(
argument|const QXImageWrapper&xi
argument_list|)
specifier|const
block|;
name|Qt
operator|::
name|HANDLE
name|hd
block|;      enum
name|Flag
block|{
name|NoFlags
operator|=
literal|0x0
block|,
name|Uninitialized
operator|=
literal|0x1
block|,
name|Readonly
operator|=
literal|0x2
block|,
name|InvertedWhenBoundToTexture
operator|=
literal|0x4
block|,
name|GlSurfaceCreatedWithAlpha
operator|=
literal|0x8
block|}
block|;
name|uint
name|flags
block|;
name|QX11Info
name|xinfo
block|;
name|Qt
operator|::
name|HANDLE
name|x11_mask
block|;
name|Qt
operator|::
name|HANDLE
name|picture
block|;
name|Qt
operator|::
name|HANDLE
name|mask_picture
block|;
name|Qt
operator|::
name|HANDLE
name|hd2
block|;
comment|// sorted in the default display depth
name|QPixmap
operator|::
name|ShareMode
name|share_mode
block|;
name|QX11PaintEngine
operator|*
name|pengine
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
begin_comment
comment|// QPIXMAPDATA_X11_P_H
end_comment
end_unit
