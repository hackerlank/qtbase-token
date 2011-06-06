begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandreadbackcglintegration.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandreadbackcglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandreadbackcglwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_function
DECL|function|createGLIntegration
name|QWaylandGLIntegration
modifier|*
name|QWaylandGLIntegration
operator|::
name|createGLIntegration
parameter_list|(
name|QWaylandDisplay
modifier|*
name|waylandDisplay
parameter_list|)
block|{
return|return
operator|new
name|QWaylandReadbackCGLIntegration
argument_list|(
name|waylandDisplay
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|QWaylandReadbackCGLIntegration
name|QWaylandReadbackCGLIntegration
operator|::
name|QWaylandReadbackCGLIntegration
parameter_list|(
name|QWaylandDisplay
modifier|*
name|waylandDispaly
parameter_list|)
member_init_list|:
name|QWaylandGLIntegration
argument_list|()
member_init_list|,
name|mWaylandDisplay
argument_list|(
name|waylandDispaly
argument_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Using Readback-CGL"
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaylandReadbackCGLIntegration
name|QWaylandReadbackCGLIntegration
operator|::
name|~
name|QWaylandReadbackCGLIntegration
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|initialize
name|void
name|QWaylandReadbackCGLIntegration
operator|::
name|initialize
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|createEglWindow
name|QWaylandWindow
modifier|*
name|QWaylandReadbackCGLIntegration
operator|::
name|createEglWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
return|return
operator|new
name|QWaylandReadbackCGLWindow
argument_list|(
name|window
argument_list|,
name|this
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformGLContext
name|QPlatformGLContext
modifier|*
name|QWaylandReadbackCGLIntegration
operator|::
name|createPlatformGLContext
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|glFormat
parameter_list|,
name|QPlatformGLContext
modifier|*
name|share
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QWaylandReadbackCGLContext
argument_list|(
name|share
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|waylandDisplay
name|QWaylandDisplay
modifier|*
name|QWaylandReadbackCGLIntegration
operator|::
name|waylandDisplay
parameter_list|()
specifier|const
block|{
return|return
name|mWaylandDisplay
return|;
block|}
end_function
end_unit
