begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdirectfbscreen.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbcursor.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QDirectFbScreen
name|QDirectFbScreen
operator|::
name|QDirectFbScreen
parameter_list|(
name|int
name|display
parameter_list|)
member_init_list|:
name|QPlatformScreen
argument_list|()
member_init_list|,
name|m_layer
argument_list|(
name|QDirectFbConvenience
operator|::
name|dfbDisplayLayer
argument_list|(
name|display
argument_list|)
argument_list|)
block|{
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
name|DFBDisplayLayerConfig
name|config
decl_stmt|;
name|m_layer
operator|->
name|GetConfiguration
argument_list|(
name|m_layer
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|config
argument_list|)
expr_stmt|;
name|m_format
operator|=
name|QDirectFbConvenience
operator|::
name|imageFormatFromSurfaceFormat
argument_list|(
name|config
operator|.
name|pixelformat
argument_list|,
name|config
operator|.
name|surface_caps
argument_list|)
expr_stmt|;
name|m_geometry
operator|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|config
operator|.
name|width
argument_list|,
name|config
operator|.
name|height
argument_list|)
expr_stmt|;
specifier|const
name|int
name|dpi
init|=
literal|72
decl_stmt|;
specifier|const
name|qreal
name|inch
init|=
literal|25.4
decl_stmt|;
name|m_depth
operator|=
name|QDirectFbConvenience
operator|::
name|colorDepthForSurface
argument_list|(
name|config
operator|.
name|pixelformat
argument_list|)
expr_stmt|;
name|m_physicalSize
operator|=
name|QSizeF
argument_list|(
name|config
operator|.
name|width
argument_list|,
name|config
operator|.
name|height
argument_list|)
operator|*
name|inch
operator|/
name|dpi
expr_stmt|;
name|m_cursor
operator|.
name|reset
argument_list|(
operator|new
name|QDirectFBCursor
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|dfbLayer
name|IDirectFBDisplayLayer
modifier|*
name|QDirectFbScreen
operator|::
name|dfbLayer
parameter_list|()
specifier|const
block|{
return|return
name|m_layer
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
