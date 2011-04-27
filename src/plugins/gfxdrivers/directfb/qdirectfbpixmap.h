begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDIRECTFBPIXMAP_H
end_ifndef
begin_define
DECL|macro|QDIRECTFBPIXMAP_H
define|#
directive|define
name|QDIRECTFBPIXMAP_H
end_define
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_DIRECTFB
end_ifndef
begin_include
include|#
directive|include
file|<QtGui/private/qpixmapdata_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpaintengine_raster_p.h>
end_include
begin_include
include|#
directive|include
file|"qdirectfbpaintdevice.h"
end_include
begin_include
include|#
directive|include
file|<directfb.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QDirectFBPaintEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPixmapData
name|class
name|QDirectFBPixmapData
range|:
name|public
name|QPixmapData
decl_stmt|,
name|public
name|QDirectFBPaintDevice
block|{
name|public
label|:
name|QDirectFBPixmapData
argument_list|(
argument|QDirectFBScreen *screen
argument_list|,
argument|PixelType pixelType
argument_list|)
empty_stmt|;
operator|~
name|QDirectFBPixmapData
argument_list|()
expr_stmt|;
comment|// Re-implemented from QPixmapData:
name|virtual
name|void
name|resize
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
function_decl|;
name|virtual
name|void
name|fromImage
argument_list|(
specifier|const
name|QImage
operator|&
name|image
argument_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_DIRECTFB_IMAGEPROVIDER
name|virtual
name|bool
name|fromFile
argument_list|(
specifier|const
name|QString
operator|&
name|filename
argument_list|,
specifier|const
name|char
operator|*
name|format
argument_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
argument_list|)
decl_stmt|;
name|virtual
name|bool
name|fromData
argument_list|(
specifier|const
name|uchar
operator|*
name|buffer
argument_list|,
name|uint
name|len
argument_list|,
specifier|const
name|char
operator|*
name|format
argument_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|virtual
name|void
name|copy
parameter_list|(
specifier|const
name|QPixmapData
modifier|*
name|data
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
name|virtual
name|void
name|fill
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
function_decl|;
name|virtual
name|QPixmap
name|transformed
argument_list|(
specifier|const
name|QTransform
operator|&
name|matrix
argument_list|,
name|Qt
operator|::
name|TransformationMode
name|mode
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QImage
name|toImage
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QImage
modifier|*
name|buffer
parameter_list|()
function_decl|;
name|virtual
name|bool
name|scroll
parameter_list|(
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
comment|// Pure virtual in QPixmapData, so re-implement here and delegate to QDirectFBPaintDevice
name|virtual
name|int
name|metric
argument_list|(
name|QPaintDevice
operator|::
name|PaintDeviceMetric
name|m
argument_list|)
decl|const
block|{
return|return
name|QDirectFBPaintDevice
operator|::
name|metric
argument_list|(
name|m
argument_list|)
return|;
block|}
specifier|inline
name|QImage
operator|::
name|Format
name|pixelFormat
argument_list|()
specifier|const
block|{
return|return
name|imageFormat
return|;
block|}
specifier|inline
name|bool
name|hasAlphaChannel
argument_list|()
specifier|const
block|{
return|return
name|alpha
return|;
block|}
specifier|static
name|bool
name|hasAlphaChannel
argument_list|(
specifier|const
name|QImage
operator|&
name|img
argument_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
operator|=
name|Qt
operator|::
name|AutoColor
argument_list|)
decl_stmt|;
name|private
label|:
ifdef|#
directive|ifdef
name|QT_DIRECTFB_IMAGEPROVIDER
name|bool
name|fromDataBufferDescription
parameter_list|(
specifier|const
name|DFBDataBufferDescription
modifier|&
name|dataBuffer
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
name|invalidate
parameter_list|()
function_decl|;
name|bool
name|alpha
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QWS_DIRECTFB
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDIRECTFBPIXMAP_H
end_comment
end_unit
