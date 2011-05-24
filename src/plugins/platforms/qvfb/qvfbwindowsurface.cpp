begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qvfbwindowsurface.h"
end_include
begin_include
include|#
directive|include
file|"qvfbintegration.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpainter.h>
end_include
begin_include
include|#
directive|include
file|<private/qapplication_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QVFbWindowSurface
name|QVFbWindowSurface
operator|::
name|QVFbWindowSurface
parameter_list|(
comment|//QVFbIntegration *graphicsSystem,
name|QVFbScreen
modifier|*
name|screen
parameter_list|,
name|QWidget
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QWindowSurface
argument_list|(
name|window
argument_list|)
member_init_list|,
name|mScreen
argument_list|(
name|screen
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QVFbWindowSurface
name|QVFbWindowSurface
operator|::
name|~
name|QVFbWindowSurface
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QVFbWindowSurface
operator|::
name|paintDevice
parameter_list|()
block|{
return|return
name|mScreen
operator|->
name|screenImage
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QVFbWindowSurface
operator|::
name|flush
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|offset
argument_list|)
expr_stmt|;
comment|//    QRect rect = geometry();
comment|//    QPoint topLeft = rect.topLeft();
name|mScreen
operator|->
name|setDirty
argument_list|(
name|region
operator|.
name|boundingRect
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QVFbWindowSurface
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
parameter_list|)
block|{
comment|// any size you like as long as it's full-screen...
name|QRect
name|rect
argument_list|(
name|mScreen
operator|->
name|availableGeometry
argument_list|()
argument_list|)
decl_stmt|;
name|QWindowSurface
operator|::
name|resize
argument_list|(
name|rect
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QVFbWindow
name|QVFbWindow
operator|::
name|QVFbWindow
parameter_list|(
name|QVFbScreen
modifier|*
name|screen
parameter_list|,
name|QWidget
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformWindow
argument_list|(
name|window
argument_list|)
member_init_list|,
name|mScreen
argument_list|(
name|screen
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|setGeometry
name|void
name|QVFbWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
parameter_list|)
block|{
comment|// any size you like as long as it's full-screen...
name|QRect
name|rect
argument_list|(
name|mScreen
operator|->
name|availableGeometry
argument_list|()
argument_list|)
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|this
operator|->
name|widget
argument_list|()
argument_list|,
name|rect
argument_list|)
expr_stmt|;
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
