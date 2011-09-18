begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdirectfbcursor.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbconvenience.h"
end_include
begin_constructor
DECL|function|QDirectFBCursor
name|QDirectFBCursor
operator|::
name|QDirectFBCursor
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|QPlatformCursor
argument_list|(
name|screen
argument_list|)
block|{
name|QDirectFbConvenience
operator|::
name|dfbInterface
argument_list|()
operator|->
name|GetDisplayLayer
argument_list|(
name|QDirectFbConvenience
operator|::
name|dfbInterface
argument_list|()
argument_list|,
name|DLID_PRIMARY
argument_list|,
name|m_layer
operator|.
name|outPtr
argument_list|()
argument_list|)
expr_stmt|;
name|m_image
operator|.
name|reset
argument_list|(
operator|new
name|QPlatformCursorImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|changeCursor
name|void
name|QDirectFBCursor
operator|::
name|changeCursor
parameter_list|(
name|QCursor
modifier|*
name|cursor
parameter_list|,
name|QWindow
modifier|*
parameter_list|)
block|{
name|int
name|xSpot
decl_stmt|;
name|int
name|ySpot
decl_stmt|;
name|QPixmap
name|map
decl_stmt|;
if|if
condition|(
name|cursor
operator|->
name|shape
argument_list|()
operator|!=
name|Qt
operator|::
name|BitmapCursor
condition|)
block|{
name|m_image
operator|->
name|set
argument_list|(
name|cursor
operator|->
name|shape
argument_list|()
argument_list|)
expr_stmt|;
name|xSpot
operator|=
name|m_image
operator|->
name|hotspot
argument_list|()
operator|.
name|x
argument_list|()
expr_stmt|;
name|ySpot
operator|=
name|m_image
operator|->
name|hotspot
argument_list|()
operator|.
name|y
argument_list|()
expr_stmt|;
name|QImage
modifier|*
name|i
init|=
name|m_image
operator|->
name|image
argument_list|()
decl_stmt|;
name|map
operator|=
name|QPixmap
operator|::
name|fromImage
argument_list|(
operator|*
name|i
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QPoint
name|point
init|=
name|cursor
operator|->
name|hotSpot
argument_list|()
decl_stmt|;
name|xSpot
operator|=
name|point
operator|.
name|x
argument_list|()
expr_stmt|;
name|ySpot
operator|=
name|point
operator|.
name|y
argument_list|()
expr_stmt|;
name|map
operator|=
name|cursor
operator|->
name|pixmap
argument_list|()
expr_stmt|;
block|}
name|IDirectFBSurface
modifier|*
name|surface
argument_list|(
name|QDirectFbConvenience
operator|::
name|dfbSurfaceForPlatformPixmap
argument_list|(
name|map
operator|.
name|handle
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_layer
operator|->
name|SetCooperativeLevel
argument_list|(
name|m_layer
operator|.
name|data
argument_list|()
argument_list|,
name|DLSCL_ADMINISTRATIVE
argument_list|)
operator|!=
name|DFB_OK
condition|)
block|{
return|return;
block|}
name|m_layer
operator|->
name|SetCursorShape
argument_list|(
name|m_layer
operator|.
name|data
argument_list|()
argument_list|,
name|surface
argument_list|,
name|xSpot
argument_list|,
name|ySpot
argument_list|)
expr_stmt|;
name|m_layer
operator|->
name|SetCooperativeLevel
argument_list|(
name|m_layer
operator|.
name|data
argument_list|()
argument_list|,
name|DLSCL_SHARED
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
