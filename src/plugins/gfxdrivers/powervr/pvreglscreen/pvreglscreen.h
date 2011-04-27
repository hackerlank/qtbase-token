begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PVREGLSCREEN_H
end_ifndef
begin_define
DECL|macro|PVREGLSCREEN_H
define|#
directive|define
name|PVREGLSCREEN_H
end_define
begin_include
include|#
directive|include
file|<QScreen>
end_include
begin_include
include|#
directive|include
file|<QGLScreen>
end_include
begin_include
include|#
directive|include
file|"pvrqwsdrawable.h"
end_include
begin_decl_stmt
DECL|variable|PvrEglScreen
name|class
name|PvrEglScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|PvrEglScreenSurfaceFunctions
range|:
name|public
name|QGLScreenSurfaceFunctions
block|{
name|public
operator|:
name|PvrEglScreenSurfaceFunctions
argument_list|(
argument|PvrEglScreen *s
argument_list|,
argument|int screenNum
argument_list|)
operator|:
name|screen
argument_list|(
name|s
argument_list|)
block|,
name|displayId
argument_list|(
argument|screenNum
argument_list|)
block|{}
name|bool
name|createNativeWindow
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
name|EGLNativeWindowType
operator|*
name|native
argument_list|)
block|;
name|private
operator|:
name|PvrEglScreen
operator|*
name|screen
block|;
name|int
name|displayId
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|PvrEglScreen
range|:
name|public
name|QGLScreen
block|{
name|public
operator|:
name|PvrEglScreen
argument_list|(
argument|int displayId
argument_list|)
block|;
operator|~
name|PvrEglScreen
argument_list|()
block|;
name|bool
name|initDevice
argument_list|()
block|;
name|bool
name|connect
argument_list|(
specifier|const
name|QString
operator|&
name|displaySpec
argument_list|)
block|;
name|void
name|disconnect
argument_list|()
block|;
name|void
name|shutdownDevice
argument_list|()
block|;
name|void
name|setMode
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|)
block|{}
name|void
name|blit
argument_list|(
specifier|const
name|QImage
operator|&
name|img
argument_list|,
specifier|const
name|QPoint
operator|&
name|topLeft
argument_list|,
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
block|;
name|void
name|solidFill
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|,
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
block|;
name|bool
name|chooseContext
argument_list|(
name|QGLContext
operator|*
name|context
argument_list|,
specifier|const
name|QGLContext
operator|*
name|shareContext
argument_list|)
block|;
name|bool
name|hasOpenGL
argument_list|()
block|;
name|QWSWindowSurface
operator|*
name|createSurface
argument_list|(
argument|QWidget *widget
argument_list|)
specifier|const
block|;
name|QWSWindowSurface
operator|*
name|createSurface
argument_list|(
argument|const QString&key
argument_list|)
specifier|const
block|;
name|int
name|transformation
argument_list|()
specifier|const
block|;
name|private
operator|:
name|void
name|sync
argument_list|()
block|;
name|void
name|openTty
argument_list|()
block|;
name|void
name|closeTty
argument_list|()
block|;
name|int
name|fd
block|;
name|int
name|ttyfd
block|,
name|oldKdMode
block|;
name|QString
name|ttyDevice
block|;
name|bool
name|doGraphicsMode
block|;
name|mutable
specifier|const
name|QScreen
operator|*
name|parent
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
