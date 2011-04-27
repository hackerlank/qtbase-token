begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWAYLANDREADBACKEGLWINDOW_H
end_ifndef
begin_define
DECL|macro|QWAYLANDREADBACKEGLWINDOW_H
define|#
directive|define
name|QWAYLANDREADBACKEGLWINDOW_H
end_define
begin_include
include|#
directive|include
file|"qwaylandshmwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandreadbackeglintegration.h"
end_include
begin_decl_stmt
DECL|variable|QWaylandReadbackEglContext
name|class
name|QWaylandReadbackEglContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWaylandReadbackEglWindow
range|:
name|public
name|QWaylandShmWindow
block|{
name|public
operator|:
name|QWaylandReadbackEglWindow
argument_list|(
name|QWidget
operator|*
name|window
argument_list|,
name|QWaylandReadbackEglIntegration
operator|*
name|eglIntegration
argument_list|)
block|;
name|WindowType
name|windowType
argument_list|()
specifier|const
block|;
name|QPlatformGLContext
operator|*
name|glContext
argument_list|()
specifier|const
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|private
operator|:
name|QWaylandReadbackEglIntegration
operator|*
name|mEglIntegration
block|;
name|QWaylandReadbackEglContext
operator|*
name|mContext
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWAYLANDREADBACKEGLWINDOW_H
end_comment
end_unit
