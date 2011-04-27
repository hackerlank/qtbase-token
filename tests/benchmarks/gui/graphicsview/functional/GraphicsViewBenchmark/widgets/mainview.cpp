begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QGraphicsLinearLayout>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|<QGLWidget>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|"button.h"
end_include
begin_include
include|#
directive|include
file|"label.h"
end_include
begin_include
include|#
directive|include
file|"menu.h"
end_include
begin_include
include|#
directive|include
file|"topbar.h"
end_include
begin_include
include|#
directive|include
file|"backgrounditem.h"
end_include
begin_include
include|#
directive|include
file|"theme.h"
end_include
begin_include
include|#
directive|include
file|"mainview.h"
end_include
begin_include
include|#
directive|include
file|"gvbwidget.h"
end_include
begin_constructor
DECL|function|MainView
name|MainView
operator|::
name|MainView
parameter_list|(
specifier|const
name|bool
name|enableOpenGL
parameter_list|,
specifier|const
name|bool
name|outputFps
parameter_list|,
specifier|const
name|bool
name|imageRendering
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsView
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_scene
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_mainLayout
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_mainWidget
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_testWidget
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_imageBasedRendering
argument_list|(
name|imageRendering
argument_list|)
member_init_list|,
name|m_pixmapToRender
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_OutputFps
argument_list|(
name|outputFps
argument_list|)
member_init_list|,
name|m_fpsUpdated
argument_list|()
member_init_list|,
name|m_Fpss
argument_list|()
member_init_list|,
name|m_angle
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_enableOpenGL
argument_list|(
name|enableOpenGL
argument_list|)
block|{
name|construct
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~MainView
name|MainView
operator|::
name|~
name|MainView
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_scene
operator|->
name|parent
argument_list|()
condition|)
operator|delete
name|m_scene
expr_stmt|;
operator|delete
name|m_pixmapToRender
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setTestWidget
name|void
name|MainView
operator|::
name|setTestWidget
parameter_list|(
name|QGraphicsWidget
modifier|*
name|testWidget
parameter_list|)
block|{
if|if
condition|(
operator|!
name|testWidget
condition|)
return|return;
if|if
condition|(
name|m_testWidget
condition|)
block|{
name|m_mainLayout
operator|->
name|removeItem
argument_list|(
name|m_testWidget
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_testWidget
operator|->
name|parent
argument_list|()
operator|&&
operator|!
name|m_testWidget
operator|->
name|parentLayoutItem
argument_list|()
condition|)
operator|delete
name|m_testWidget
expr_stmt|;
block|}
name|m_testWidget
operator|=
name|testWidget
expr_stmt|;
name|m_mainLayout
operator|->
name|addItem
argument_list|(
name|m_testWidget
argument_list|)
expr_stmt|;
name|resizeContent
argument_list|(
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|takeTestWidget
name|QGraphicsWidget
modifier|*
name|MainView
operator|::
name|takeTestWidget
parameter_list|()
block|{
if|if
condition|(
name|m_testWidget
condition|)
block|{
name|m_mainLayout
operator|->
name|removeItem
argument_list|(
name|m_testWidget
argument_list|)
expr_stmt|;
name|QGraphicsWidget
modifier|*
name|tmp
init|=
name|m_testWidget
decl_stmt|;
name|m_testWidget
operator|=
literal|0
expr_stmt|;
return|return
name|tmp
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|testWidget
name|QGraphicsWidget
modifier|*
name|MainView
operator|::
name|testWidget
parameter_list|()
block|{
return|return
name|m_testWidget
return|;
block|}
end_function
begin_function
DECL|function|setImageBasedRendering
name|void
name|MainView
operator|::
name|setImageBasedRendering
parameter_list|(
specifier|const
name|bool
name|imageBasedRendering
parameter_list|)
block|{
name|m_imageBasedRendering
operator|=
name|imageBasedRendering
expr_stmt|;
operator|delete
name|m_pixmapToRender
expr_stmt|;
name|m_pixmapToRender
operator|=
literal|0
expr_stmt|;
name|viewport
argument_list|()
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|imageBasedRendering
name|bool
name|MainView
operator|::
name|imageBasedRendering
parameter_list|()
specifier|const
block|{
return|return
name|m_imageBasedRendering
return|;
block|}
end_function
begin_function
DECL|function|fps
name|qreal
name|MainView
operator|::
name|fps
parameter_list|()
block|{
if|if
condition|(
name|m_Fpss
operator|.
name|count
argument_list|()
operator|<=
literal|0
condition|)
name|updateFps
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_Fpss
operator|.
name|count
argument_list|()
operator|<=
literal|0
condition|)
return|return
literal|0.0
return|;
name|qreal
name|sum
init|=
literal|0
decl_stmt|;
name|int
name|count
init|=
name|m_Fpss
operator|.
name|count
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
operator|++
name|i
control|)
name|sum
operator|+=
name|m_Fpss
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|m_Fpss
operator|.
name|clear
argument_list|()
expr_stmt|;
name|fpsReset
argument_list|()
expr_stmt|;
return|return
name|sum
operator|/
name|qreal
argument_list|(
name|count
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|fpsReset
name|void
name|MainView
operator|::
name|fpsReset
parameter_list|()
block|{
name|m_frameCount
operator|=
literal|0
expr_stmt|;
name|m_fpsFirstTs
operator|.
name|start
argument_list|()
expr_stmt|;
name|m_fpsLatestTs
operator|=
name|m_fpsFirstTs
expr_stmt|;
name|m_fpsUpdated
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rotateContent
name|void
name|MainView
operator|::
name|rotateContent
parameter_list|(
name|int
name|angle
parameter_list|)
block|{
name|bool
name|portrait
init|=
operator|(
operator|(
name|m_angle
operator|+
name|angle
operator|)
operator|%
literal|90
operator|==
literal|0
operator|)
operator|&&
operator|(
operator|(
name|m_angle
operator|+
name|angle
operator|)
operator|%
literal|180
operator|!=
literal|0
operator|)
decl_stmt|;
name|bool
name|landscape
init|=
operator|(
operator|(
name|m_angle
operator|+
name|angle
operator|)
operator|%
literal|180
operator|==
literal|0
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|portrait
operator|&&
operator|!
name|landscape
condition|)
return|return;
name|m_angle
operator|=
operator|(
name|m_angle
operator|+
name|angle
operator|)
operator|%
literal|360
expr_stmt|;
name|rotate
argument_list|(
name|angle
argument_list|)
expr_stmt|;
name|resizeContent
argument_list|(
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rotationAngle
name|int
name|MainView
operator|::
name|rotationAngle
parameter_list|()
specifier|const
block|{
return|return
name|m_angle
return|;
block|}
end_function
begin_function
DECL|function|resizeContent
name|void
name|MainView
operator|::
name|resizeContent
parameter_list|(
specifier|const
name|QSize
modifier|&
name|s
parameter_list|)
block|{
name|QSizeF
name|l_size
argument_list|(
name|s
argument_list|)
decl_stmt|;
name|QSizeF
name|p_size
argument_list|(
name|l_size
operator|.
name|height
argument_list|()
argument_list|,
name|l_size
operator|.
name|width
argument_list|()
argument_list|)
decl_stmt|;
name|bool
name|portrait
init|=
operator|(
name|m_angle
operator|%
literal|90
operator|==
literal|0
operator|)
operator|&&
operator|(
name|m_angle
operator|%
literal|180
operator|!=
literal|0
operator|)
decl_stmt|;
if|if
condition|(
name|portrait
condition|)
block|{
name|m_mainWidget
operator|->
name|resize
argument_list|(
name|p_size
argument_list|)
expr_stmt|;
name|m_backGround
operator|->
name|resize
argument_list|(
name|p_size
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_mainWidget
operator|->
name|resize
argument_list|(
name|l_size
argument_list|)
expr_stmt|;
name|m_backGround
operator|->
name|resize
argument_list|(
name|l_size
argument_list|)
expr_stmt|;
block|}
name|m_menu
operator|->
name|setPos
argument_list|(
name|m_topBar
operator|->
name|getStatusBarLocation
argument_list|()
argument_list|)
expr_stmt|;
name|setSceneRect
argument_list|(
name|QRectF
argument_list|(
name|m_mainWidget
operator|->
name|pos
argument_list|()
argument_list|,
name|m_mainWidget
operator|->
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|MainView
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|QGraphicsView
operator|::
name|resizeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|resizeContent
argument_list|(
name|event
operator|->
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|MainView
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|m_imageBasedRendering
condition|)
block|{
if|if
condition|(
operator|!
name|m_pixmapToRender
condition|)
name|m_pixmapToRender
operator|=
operator|new
name|QPixmap
argument_list|(
name|size
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_pixmapToRender
operator|->
name|size
argument_list|()
operator|!=
name|size
argument_list|()
condition|)
block|{
operator|delete
name|m_pixmapToRender
expr_stmt|;
name|m_pixmapToRender
operator|=
operator|new
name|QPixmap
argument_list|(
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QPainter
name|p
argument_list|(
name|m_pixmapToRender
argument_list|)
decl_stmt|;
name|render
argument_list|(
operator|&
name|p
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QGraphicsView
operator|::
name|paintEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|m_OutputFps
condition|)
emit|emit
name|repainted
argument_list|()
emit|;
name|m_frameCount
operator|++
expr_stmt|;
name|m_fpsLatestTs
operator|.
name|start
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_fpsUpdated
operator|.
name|elapsed
argument_list|()
operator|>
literal|2000
condition|)
block|{
name|updateFps
argument_list|()
expr_stmt|;
name|m_fpsUpdated
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|keyPressEvent
name|void
name|MainView
operator|::
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_F
condition|)
block|{
if|if
condition|(
name|isFullScreen
argument_list|()
condition|)
name|showNormal
argument_list|()
expr_stmt|;
else|else
name|showFullScreen
argument_list|()
expr_stmt|;
block|}
comment|//S60 3.x specific
if|if
condition|(
name|m_menu
operator|->
name|menuVisible
argument_list|()
condition|)
block|{
name|m_menu
operator|->
name|keyPressEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
literal|16777235
condition|)
block|{
comment|//Up Arrow
name|GvbWidget
modifier|*
name|widget
init|=
name|qobject_cast
argument_list|<
name|GvbWidget
operator|*
argument_list|>
argument_list|(
name|m_testWidget
argument_list|)
decl_stmt|;
if|if
condition|(
name|widget
condition|)
name|widget
operator|->
name|keyPressEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
literal|16777237
condition|)
block|{
comment|//Down Arrow
name|GvbWidget
modifier|*
name|widget
init|=
name|qobject_cast
argument_list|<
name|GvbWidget
operator|*
argument_list|>
argument_list|(
name|m_testWidget
argument_list|)
decl_stmt|;
if|if
condition|(
name|widget
condition|)
name|widget
operator|->
name|keyPressEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
literal|17825792
condition|)
block|{
comment|//LSK
if|if
condition|(
operator|!
name|m_menu
operator|->
name|menuVisible
argument_list|()
condition|)
name|m_menu
operator|->
name|menuShowHide
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
literal|17825793
condition|)
block|{
comment|//RSK
name|QApplication
operator|::
name|quit
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|construct
name|void
name|MainView
operator|::
name|construct
parameter_list|()
block|{
name|m_scene
operator|=
operator|new
name|QGraphicsScene
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
if|if
condition|(
name|m_enableOpenGL
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"OpenGL enabled"
expr_stmt|;
name|m_scene
operator|->
name|setSortCacheEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|setViewport
argument_list|(
operator|new
name|QGLWidget
argument_list|)
expr_stmt|;
comment|// Qt doc says: This is the preferred update mode for
comment|// viewports that do not support partial updates, such as QGLWidget...
name|setViewportUpdateMode
argument_list|(
name|QGraphicsView
operator|::
name|FullViewportUpdate
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
name|setViewportUpdateMode
argument_list|(
name|QGraphicsView
operator|::
name|BoundingRectViewportUpdate
argument_list|)
expr_stmt|;
name|setScene
argument_list|(
name|m_scene
argument_list|)
expr_stmt|;
name|m_scene
operator|->
name|setItemIndexMethod
argument_list|(
name|QGraphicsScene
operator|::
name|NoIndex
argument_list|)
expr_stmt|;
comment|//setCacheMode(QGraphicsView::CacheBackground);
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
operator||
name|Qt
operator|::
name|AlignTop
argument_list|)
expr_stmt|;
comment|// Turn off automatic background
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_OpaquePaintEvent
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_NoBackground
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_NoSystemBackground
argument_list|)
expr_stmt|;
name|setAutoFillBackground
argument_list|(
literal|false
argument_list|)
expr_stmt|;
comment|//Background
name|m_backGround
operator|=
operator|new
name|BackgroundItem
argument_list|(
literal|"background.svg"
argument_list|)
expr_stmt|;
name|m_scene
operator|->
name|addItem
argument_list|(
name|m_backGround
argument_list|)
expr_stmt|;
name|m_backGround
operator|->
name|setZValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|//Menu
name|m_menu
operator|=
operator|new
name|Menu
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_scene
operator|->
name|addItem
argument_list|(
name|m_menu
argument_list|)
expr_stmt|;
comment|//Add menu to the scene directly
name|m_menu
operator|->
name|setZValue
argument_list|(
literal|10
argument_list|)
expr_stmt|;
comment|//Bring to front
name|m_mainLayout
operator|=
operator|new
name|QGraphicsLinearLayout
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|m_mainLayout
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_mainLayout
operator|->
name|setSpacing
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|m_mainWidget
operator|=
operator|new
name|QGraphicsWidget
expr_stmt|;
name|m_mainWidget
operator|->
name|setLayout
argument_list|(
name|m_mainLayout
argument_list|)
expr_stmt|;
name|m_mainWidget
operator|->
name|setZValue
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|m_scene
operator|->
name|addItem
argument_list|(
name|m_mainWidget
argument_list|)
expr_stmt|;
comment|//Topbar
name|m_topBar
operator|=
operator|new
name|TopBar
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_mainLayout
operator|->
name|addItem
argument_list|(
name|m_topBar
argument_list|)
expr_stmt|;
name|m_topBar
operator|->
name|setZValue
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_topBar
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|m_menu
argument_list|,
name|SLOT
argument_list|(
name|menuShowHide
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|setHorizontalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAlwaysOff
argument_list|)
expr_stmt|;
name|setVerticalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAlwaysOff
argument_list|)
expr_stmt|;
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setViewportMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|NoFrame
argument_list|)
expr_stmt|;
name|fpsReset
argument_list|()
expr_stmt|;
name|m_fpsUpdated
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateFps
name|void
name|MainView
operator|::
name|updateFps
parameter_list|()
block|{
name|int
name|msecs
init|=
name|m_fpsFirstTs
operator|.
name|msecsTo
argument_list|(
name|m_fpsLatestTs
argument_list|)
decl_stmt|;
name|qreal
name|fps
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|msecs
operator|>
literal|0
condition|)
block|{
name|fps
operator|=
name|m_frameCount
operator|*
literal|1000.0
operator|/
name|msecs
expr_stmt|;
if|if
condition|(
name|m_OutputFps
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"FPS: "
operator|<<
name|fps
expr_stmt|;
name|m_Fpss
operator|.
name|append
argument_list|(
name|fps
argument_list|)
expr_stmt|;
block|}
name|m_fpsFirstTs
operator|=
name|m_fpsLatestTs
expr_stmt|;
name|m_frameCount
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|menu
name|Menu
modifier|*
name|MainView
operator|::
name|menu
parameter_list|()
block|{
return|return
name|m_menu
return|;
block|}
end_function
end_unit
