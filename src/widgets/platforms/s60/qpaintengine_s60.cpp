begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<private/qpaintengine_s60_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qpixmap_s60_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qt_s60_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qvolatileimage_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QS60PaintEnginePrivate
class|class
name|QS60PaintEnginePrivate
super|:
specifier|public
name|QRasterPaintEnginePrivate
block|{
public|public:
DECL|function|QS60PaintEnginePrivate
name|QS60PaintEnginePrivate
parameter_list|()
block|{}
block|}
class|;
end_class
begin_constructor
DECL|function|QS60PaintEngine
name|QS60PaintEngine
operator|::
name|QS60PaintEngine
parameter_list|(
name|QPaintDevice
modifier|*
name|device
parameter_list|,
name|QS60PixmapData
modifier|*
name|data
parameter_list|)
member_init_list|:
name|QRasterPaintEngine
argument_list|(
operator|*
operator|(
operator|new
name|QS60PaintEnginePrivate
operator|)
argument_list|,
name|device
argument_list|)
member_init_list|,
name|pixmapData
argument_list|(
name|data
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|begin
name|bool
name|QS60PaintEngine
operator|::
name|begin
parameter_list|(
name|QPaintDevice
modifier|*
name|device
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QS60PaintEngine
argument_list|)
expr_stmt|;
if|if
condition|(
name|pixmapData
operator|->
name|classId
argument_list|()
operator|==
name|QPixmapData
operator|::
name|RasterClass
condition|)
block|{
name|pixmapData
operator|->
name|beginDataAccess
argument_list|()
expr_stmt|;
name|bool
name|ret
init|=
name|QRasterPaintEngine
operator|::
name|begin
argument_list|(
name|device
argument_list|)
decl_stmt|;
comment|// Make sure QPaintEngine::paintDevice() returns the proper device.
comment|// QRasterPaintEngine changes pdev to QImage in case of RasterClass QPixmapData
comment|// which is incorrect in Symbian.
name|d
operator|->
name|pdev
operator|=
name|device
expr_stmt|;
return|return
name|ret
return|;
block|}
return|return
name|QRasterPaintEngine
operator|::
name|begin
argument_list|(
name|device
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|end
name|bool
name|QS60PaintEngine
operator|::
name|end
parameter_list|()
block|{
if|if
condition|(
name|pixmapData
operator|->
name|classId
argument_list|()
operator|==
name|QPixmapData
operator|::
name|RasterClass
condition|)
block|{
name|bool
name|ret
init|=
name|QRasterPaintEngine
operator|::
name|end
argument_list|()
decl_stmt|;
name|pixmapData
operator|->
name|endDataAccess
argument_list|()
expr_stmt|;
return|return
name|ret
return|;
block|}
return|return
name|QRasterPaintEngine
operator|::
name|end
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|drawPixmap
name|void
name|QS60PaintEngine
operator|::
name|drawPixmap
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pm
parameter_list|)
block|{
if|if
condition|(
name|pm
operator|.
name|pixmapData
argument_list|()
operator|->
name|classId
argument_list|()
operator|==
name|QPixmapData
operator|::
name|RasterClass
condition|)
block|{
name|QS60PixmapData
modifier|*
name|srcData
init|=
cast|static_cast
argument_list|<
name|QS60PixmapData
operator|*
argument_list|>
argument_list|(
name|pm
operator|.
name|pixmapData
argument_list|()
argument_list|)
decl_stmt|;
name|srcData
operator|->
name|beginDataAccess
argument_list|()
expr_stmt|;
name|QRasterPaintEngine
operator|::
name|drawPixmap
argument_list|(
name|p
argument_list|,
name|pm
argument_list|)
expr_stmt|;
name|srcData
operator|->
name|endDataAccess
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|void
modifier|*
name|nativeData
init|=
name|pm
operator|.
name|pixmapData
argument_list|()
operator|->
name|toNativeType
argument_list|(
name|QPixmapData
operator|::
name|VolatileImage
argument_list|)
decl_stmt|;
if|if
condition|(
name|nativeData
condition|)
block|{
name|QVolatileImage
modifier|*
name|img
init|=
cast|static_cast
argument_list|<
name|QVolatileImage
operator|*
argument_list|>
argument_list|(
name|nativeData
argument_list|)
decl_stmt|;
name|img
operator|->
name|beginDataAccess
argument_list|()
expr_stmt|;
name|QRasterPaintEngine
operator|::
name|drawImage
argument_list|(
name|p
argument_list|,
name|img
operator|->
name|imageRef
argument_list|()
argument_list|)
expr_stmt|;
name|img
operator|->
name|endDataAccess
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QRasterPaintEngine
operator|::
name|drawPixmap
argument_list|(
name|p
argument_list|,
name|pm
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|drawPixmap
name|void
name|QS60PaintEngine
operator|::
name|drawPixmap
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|r
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pm
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|sr
parameter_list|)
block|{
if|if
condition|(
name|pm
operator|.
name|pixmapData
argument_list|()
operator|->
name|classId
argument_list|()
operator|==
name|QPixmapData
operator|::
name|RasterClass
condition|)
block|{
name|QS60PixmapData
modifier|*
name|srcData
init|=
cast|static_cast
argument_list|<
name|QS60PixmapData
operator|*
argument_list|>
argument_list|(
name|pm
operator|.
name|pixmapData
argument_list|()
argument_list|)
decl_stmt|;
name|srcData
operator|->
name|beginDataAccess
argument_list|()
expr_stmt|;
name|QRasterPaintEngine
operator|::
name|drawPixmap
argument_list|(
name|r
argument_list|,
name|pm
argument_list|,
name|sr
argument_list|)
expr_stmt|;
name|srcData
operator|->
name|endDataAccess
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|void
modifier|*
name|nativeData
init|=
name|pm
operator|.
name|pixmapData
argument_list|()
operator|->
name|toNativeType
argument_list|(
name|QPixmapData
operator|::
name|VolatileImage
argument_list|)
decl_stmt|;
if|if
condition|(
name|nativeData
condition|)
block|{
name|QVolatileImage
modifier|*
name|img
init|=
cast|static_cast
argument_list|<
name|QVolatileImage
operator|*
argument_list|>
argument_list|(
name|nativeData
argument_list|)
decl_stmt|;
name|img
operator|->
name|beginDataAccess
argument_list|()
expr_stmt|;
name|QRasterPaintEngine
operator|::
name|drawImage
argument_list|(
name|r
argument_list|,
name|img
operator|->
name|imageRef
argument_list|()
argument_list|,
name|sr
argument_list|)
expr_stmt|;
name|img
operator|->
name|endDataAccess
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QRasterPaintEngine
operator|::
name|drawPixmap
argument_list|(
name|r
argument_list|,
name|pm
argument_list|,
name|sr
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|drawTiledPixmap
name|void
name|QS60PaintEngine
operator|::
name|drawTiledPixmap
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|r
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pm
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|sr
parameter_list|)
block|{
if|if
condition|(
name|pm
operator|.
name|pixmapData
argument_list|()
operator|->
name|classId
argument_list|()
operator|==
name|QPixmapData
operator|::
name|RasterClass
condition|)
block|{
name|QS60PixmapData
modifier|*
name|srcData
init|=
cast|static_cast
argument_list|<
name|QS60PixmapData
operator|*
argument_list|>
argument_list|(
name|pm
operator|.
name|pixmapData
argument_list|()
argument_list|)
decl_stmt|;
name|srcData
operator|->
name|beginDataAccess
argument_list|()
expr_stmt|;
name|QRasterPaintEngine
operator|::
name|drawTiledPixmap
argument_list|(
name|r
argument_list|,
name|pm
argument_list|,
name|sr
argument_list|)
expr_stmt|;
name|srcData
operator|->
name|endDataAccess
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QRasterPaintEngine
operator|::
name|drawTiledPixmap
argument_list|(
name|r
argument_list|,
name|pm
argument_list|,
name|sr
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|prepare
name|void
name|QS60PaintEngine
operator|::
name|prepare
parameter_list|(
name|QImage
modifier|*
name|image
parameter_list|)
block|{
name|QRasterBuffer
modifier|*
name|buffer
init|=
name|d_func
argument_list|()
operator|->
name|rasterBuffer
operator|.
name|data
argument_list|()
decl_stmt|;
if|if
condition|(
name|buffer
condition|)
name|buffer
operator|->
name|prepare
argument_list|(
name|image
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
