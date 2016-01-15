begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qrasterbackingstore_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qpainter.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QRasterBackingStore
name|QRasterBackingStore
operator|::
name|QRasterBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformBackingStore
argument_list|(
name|window
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QRasterBackingStore
name|QRasterBackingStore
operator|::
name|~
name|QRasterBackingStore
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|resize
name|void
name|QRasterBackingStore
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|staticContents
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|staticContents
argument_list|)
expr_stmt|;
name|int
name|windowDevicePixelRatio
init|=
name|window
argument_list|()
operator|->
name|devicePixelRatio
argument_list|()
decl_stmt|;
name|QSize
name|effectiveBufferSize
init|=
name|size
operator|*
name|windowDevicePixelRatio
decl_stmt|;
if|if
condition|(
name|m_image
operator|.
name|size
argument_list|()
operator|==
name|effectiveBufferSize
condition|)
return|return;
name|QImage
operator|::
name|Format
name|format
init|=
name|window
argument_list|()
operator|->
name|format
argument_list|()
operator|.
name|hasAlpha
argument_list|()
condition|?
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
else|:
name|QImage
operator|::
name|Format_RGB32
decl_stmt|;
name|m_image
operator|=
name|QImage
argument_list|(
name|effectiveBufferSize
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|m_image
operator|.
name|setDevicePixelRatio
argument_list|(
name|windowDevicePixelRatio
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|==
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
condition|)
name|m_image
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QRasterBackingStore
operator|::
name|paintDevice
parameter_list|()
block|{
return|return
operator|&
name|m_image
return|;
block|}
end_function
begin_function
DECL|function|toImage
name|QImage
name|QRasterBackingStore
operator|::
name|toImage
parameter_list|()
specifier|const
block|{
return|return
name|m_image
return|;
block|}
end_function
begin_function
DECL|function|scroll
name|bool
name|QRasterBackingStore
operator|::
name|scroll
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
block|{
if|if
condition|(
name|window
argument_list|()
operator|->
name|surfaceType
argument_list|()
operator|!=
name|QSurface
operator|::
name|RasterSurface
condition|)
return|return
literal|false
return|;
specifier|extern
name|void
name|qt_scrollRectInImage
argument_list|(
name|QImage
operator|&
argument_list|,
specifier|const
name|QRect
operator|&
argument_list|,
specifier|const
name|QPoint
operator|&
argument_list|)
decl_stmt|;
specifier|const
name|qreal
name|devicePixelRatio
init|=
name|m_image
operator|.
name|devicePixelRatio
argument_list|()
decl_stmt|;
specifier|const
name|QPoint
name|delta
argument_list|(
name|dx
operator|*
name|devicePixelRatio
argument_list|,
name|dy
operator|*
name|devicePixelRatio
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QRect
modifier|&
name|rect
decl|,
name|region
operator|.
name|rects
argument_list|()
control|)
name|qt_scrollRectInImage
argument_list|(
name|m_image
argument_list|,
name|QRect
argument_list|(
name|rect
operator|.
name|topLeft
argument_list|()
operator|*
name|devicePixelRatio
argument_list|,
name|rect
operator|.
name|size
argument_list|()
operator|*
name|devicePixelRatio
argument_list|)
argument_list|,
name|delta
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QRasterBackingStore
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_image
operator|.
name|hasAlphaChannel
argument_list|()
condition|)
return|return;
name|QPainter
name|painter
argument_list|(
operator|&
name|m_image
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
specifier|const
name|QColor
name|blank
init|=
name|Qt
operator|::
name|transparent
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QRect
modifier|&
name|rect
decl|,
name|region
operator|.
name|rects
argument_list|()
control|)
name|painter
operator|.
name|fillRect
argument_list|(
name|rect
argument_list|,
name|blank
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
