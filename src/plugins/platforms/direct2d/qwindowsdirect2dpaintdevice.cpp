begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsdirect2dpaintdevice.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dpaintengine.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dhelpers.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2ddevicecontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowswindow.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QWindowsDirect2DPaintDevicePrivate
class|class
name|QWindowsDirect2DPaintDevicePrivate
block|{
public|public:
DECL|function|QWindowsDirect2DPaintDevicePrivate
name|QWindowsDirect2DPaintDevicePrivate
parameter_list|(
name|QWindowsDirect2DBitmap
modifier|*
name|bitmap
parameter_list|,
name|QInternal
operator|::
name|PaintDeviceFlags
name|f
parameter_list|,
name|QWindowsDirect2DPaintEngine
operator|::
name|Flags
name|paintFlags
parameter_list|)
member_init_list|:
name|engine
argument_list|(
operator|new
name|QWindowsDirect2DPaintEngine
argument_list|(
name|bitmap
argument_list|,
name|paintFlags
argument_list|)
argument_list|)
member_init_list|,
name|bitmap
argument_list|(
name|bitmap
argument_list|)
member_init_list|,
name|flags
argument_list|(
name|f
argument_list|)
block|{}
DECL|member|engine
name|QScopedPointer
argument_list|<
name|QWindowsDirect2DPaintEngine
argument_list|>
name|engine
decl_stmt|;
DECL|member|bitmap
name|QWindowsDirect2DBitmap
modifier|*
name|bitmap
decl_stmt|;
DECL|member|flags
name|QInternal
operator|::
name|PaintDeviceFlags
name|flags
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QWindowsDirect2DPaintDevice
name|QWindowsDirect2DPaintDevice
operator|::
name|QWindowsDirect2DPaintDevice
parameter_list|(
name|QWindowsDirect2DBitmap
modifier|*
name|bitmap
parameter_list|,
name|QInternal
operator|::
name|PaintDeviceFlags
name|flags
parameter_list|,
name|QWindowsDirect2DPaintEngine
operator|::
name|Flags
name|paintFlags
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QWindowsDirect2DPaintDevicePrivate
argument_list|(
name|bitmap
argument_list|,
name|flags
argument_list|,
name|paintFlags
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|paintEngine
name|QPaintEngine
modifier|*
name|QWindowsDirect2DPaintDevice
operator|::
name|paintEngine
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindowsDirect2DPaintDevice
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|engine
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|devType
name|int
name|QWindowsDirect2DPaintDevice
operator|::
name|devType
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindowsDirect2DPaintDevice
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|flags
return|;
block|}
end_function
begin_function
DECL|function|metric
name|int
name|QWindowsDirect2DPaintDevice
operator|::
name|metric
parameter_list|(
name|QPaintDevice
operator|::
name|PaintDeviceMetric
name|metric
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindowsDirect2DPaintDevice
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|metric
condition|)
block|{
case|case
name|QPaintDevice
operator|::
name|PdmWidth
case|:
return|return
name|d
operator|->
name|bitmap
operator|->
name|bitmap
argument_list|()
operator|->
name|GetPixelSize
argument_list|()
operator|.
name|width
return|;
break|break;
case|case
name|QPaintDevice
operator|::
name|PdmHeight
case|:
return|return
name|d
operator|->
name|bitmap
operator|->
name|bitmap
argument_list|()
operator|->
name|GetPixelSize
argument_list|()
operator|.
name|height
return|;
break|break;
case|case
name|QPaintDevice
operator|::
name|PdmNumColors
case|:
return|return
name|INT_MAX
return|;
break|break;
case|case
name|QPaintDevice
operator|::
name|PdmDepth
case|:
return|return
literal|32
return|;
break|break;
case|case
name|QPaintDevice
operator|::
name|PdmDpiX
case|:
case|case
name|QPaintDevice
operator|::
name|PdmPhysicalDpiX
case|:
block|{
name|FLOAT
name|x
decl_stmt|,
name|y
decl_stmt|;
name|QWindowsDirect2DContext
operator|::
name|instance
argument_list|()
operator|->
name|d2dFactory
argument_list|()
operator|->
name|GetDesktopDpi
argument_list|(
operator|&
name|x
argument_list|,
operator|&
name|y
argument_list|)
expr_stmt|;
return|return
name|x
return|;
block|}
break|break;
case|case
name|QPaintDevice
operator|::
name|PdmDpiY
case|:
case|case
name|QPaintDevice
operator|::
name|PdmPhysicalDpiY
case|:
block|{
name|FLOAT
name|x
decl_stmt|,
name|y
decl_stmt|;
name|QWindowsDirect2DContext
operator|::
name|instance
argument_list|()
operator|->
name|d2dFactory
argument_list|()
operator|->
name|GetDesktopDpi
argument_list|(
operator|&
name|x
argument_list|,
operator|&
name|y
argument_list|)
expr_stmt|;
return|return
name|y
return|;
block|}
break|break;
case|case
name|QPaintDevice
operator|::
name|PdmDevicePixelRatio
case|:
return|return
literal|1
return|;
break|break;
case|case
name|QPaintDevice
operator|::
name|PdmDevicePixelRatioScaled
case|:
return|return
literal|1
operator|*
name|devicePixelRatioFScale
argument_list|()
return|;
break|break;
case|case
name|QPaintDevice
operator|::
name|PdmWidthMM
case|:
case|case
name|QPaintDevice
operator|::
name|PdmHeightMM
case|:
return|return
operator|-
literal|1
return|;
break|break;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
