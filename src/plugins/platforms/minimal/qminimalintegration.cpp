begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qminimalintegration.h"
end_include
begin_include
include|#
directive|include
file|"qminimalbackingstore.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpixmap_raster_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformWindow>
end_include
begin_constructor
DECL|function|QMinimalIntegration
name|QMinimalIntegration
operator|::
name|QMinimalIntegration
parameter_list|()
block|{
name|QMinimalScreen
modifier|*
name|mPrimaryScreen
init|=
operator|new
name|QMinimalScreen
argument_list|()
decl_stmt|;
name|mPrimaryScreen
operator|->
name|mGeometry
operator|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|240
argument_list|,
literal|320
argument_list|)
expr_stmt|;
name|mPrimaryScreen
operator|->
name|mDepth
operator|=
literal|32
expr_stmt|;
name|mPrimaryScreen
operator|->
name|mFormat
operator|=
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
expr_stmt|;
name|mScreens
operator|.
name|append
argument_list|(
name|mPrimaryScreen
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|hasCapability
name|bool
name|QMinimalIntegration
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|cap
condition|)
block|{
case|case
name|ThreadedPixmaps
case|:
return|return
literal|true
return|;
default|default:
return|return
name|QPlatformIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|createPixmapData
name|QPixmapData
modifier|*
name|QMinimalIntegration
operator|::
name|createPixmapData
parameter_list|(
name|QPixmapData
operator|::
name|PixelType
name|type
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QRasterPixmapData
argument_list|(
name|type
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QMinimalIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
return|return
operator|new
name|QPlatformWindow
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QMinimalIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QMinimalBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
end_unit
