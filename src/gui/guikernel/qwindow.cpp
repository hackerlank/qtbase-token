begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindow.h"
end_include
begin_include
include|#
directive|include
file|"qplatformwindow_qpa.h"
end_include
begin_include
include|#
directive|include
file|"qwindowformat_qpa.h"
end_include
begin_include
include|#
directive|include
file|"qplatformglcontext_qpa.h"
end_include
begin_include
include|#
directive|include
file|"qwindowcontext_qpa.h"
end_include
begin_include
include|#
directive|include
file|"qwindow_p.h"
end_include
begin_include
include|#
directive|include
file|"qguiapplication_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QWindow
name|QWindow
operator|::
name|QWindow
parameter_list|(
name|QWindow
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QWindowPrivate
argument_list|()
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QWindow
argument_list|)
expr_stmt|;
name|d
operator|->
name|parentWindow
operator|=
name|parent
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWindow
name|QWindow
operator|::
name|~
name|QWindow
parameter_list|()
block|{
name|destroy
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setVisible
name|void
name|QWindow
operator|::
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWindow
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|platformWindow
condition|)
block|{
name|create
argument_list|()
expr_stmt|;
block|}
name|d
operator|->
name|platformWindow
operator|->
name|setVisible
argument_list|(
name|visible
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|visible
name|bool
name|QWindow
operator|::
name|visible
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|visible
return|;
block|}
end_function
begin_function
DECL|function|create
name|void
name|QWindow
operator|::
name|create
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWindow
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|platformWindow
condition|)
block|{
name|d
operator|->
name|platformWindow
operator|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|createPlatformWindow
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|d
operator|->
name|windowFlags
operator|=
name|d
operator|->
name|platformWindow
operator|->
name|setWindowFlags
argument_list|(
name|d
operator|->
name|windowFlags
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|windowTitle
operator|.
name|isNull
argument_list|()
condition|)
name|d
operator|->
name|platformWindow
operator|->
name|setWindowTitle
argument_list|(
name|d
operator|->
name|windowTitle
argument_list|)
expr_stmt|;
name|QObjectList
name|childObjects
init|=
name|children
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
name|childObjects
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QObject
modifier|*
name|object
init|=
name|childObjects
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|object
operator|->
name|isWindowType
argument_list|()
condition|)
block|{
name|QWindow
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QWindow
operator|*
argument_list|>
argument_list|(
name|object
argument_list|)
decl_stmt|;
if|if
condition|(
name|window
operator|->
name|d_func
argument_list|()
operator|->
name|platformWindow
condition|)
name|window
operator|->
name|d_func
argument_list|()
operator|->
name|platformWindow
operator|->
name|setParent
argument_list|(
name|d
operator|->
name|platformWindow
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|winId
name|WId
name|QWindow
operator|::
name|winId
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindow
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|platformWindow
condition|)
cast|const_cast
argument_list|<
name|QWindow
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|create
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|platformWindow
operator|->
name|winId
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|parent
name|QWindow
modifier|*
name|QWindow
operator|::
name|parent
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|parentWindow
return|;
block|}
end_function
begin_comment
comment|/**   Sets the parent Window. This will lead to the windowing system managing the clip of the window, so it will be clipped to the parent window.   Setting parent to be 0(NULL) means map it as a top level window. If the parent window has grabbed its window system resources, then the current window will also grab its window system resources.   **/
end_comment
begin_function
DECL|function|setParent
name|void
name|QWindow
operator|::
name|setParent
parameter_list|(
name|QWindow
modifier|*
name|parent
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWindow
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|parentWindow
operator|==
name|parent
condition|)
return|return;
name|QObject
operator|::
name|setParent
argument_list|(
name|parent
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|platformWindow
condition|)
block|{
if|if
condition|(
name|parent
operator|&&
name|parent
operator|->
name|d_func
argument_list|()
operator|->
name|platformWindow
condition|)
block|{
name|d
operator|->
name|platformWindow
operator|->
name|setParent
argument_list|(
name|parent
operator|->
name|d_func
argument_list|()
operator|->
name|platformWindow
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|parent
condition|)
block|{
name|d
operator|->
name|platformWindow
operator|->
name|setParent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
name|d
operator|->
name|parentWindow
operator|=
name|parent
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setWindowFormat
name|void
name|QWindow
operator|::
name|setWindowFormat
parameter_list|(
specifier|const
name|QWindowFormat
modifier|&
name|format
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWindow
argument_list|)
expr_stmt|;
name|d
operator|->
name|requestedFormat
operator|=
name|format
expr_stmt|;
block|}
end_function
begin_function
DECL|function|requestedWindowFormat
name|QWindowFormat
name|QWindow
operator|::
name|requestedWindowFormat
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|requestedFormat
return|;
block|}
end_function
begin_function
DECL|function|actualWindowFormat
name|QWindowFormat
name|QWindow
operator|::
name|actualWindowFormat
parameter_list|()
specifier|const
block|{
return|return
name|glContext
argument_list|()
operator|->
name|handle
argument_list|()
operator|->
name|windowFormat
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setSurfaceType
name|void
name|QWindow
operator|::
name|setSurfaceType
parameter_list|(
name|SurfaceType
name|type
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWindow
argument_list|)
expr_stmt|;
name|d
operator|->
name|surfaceType
operator|=
name|type
expr_stmt|;
block|}
end_function
begin_function
DECL|function|surfaceType
name|QWindow
operator|::
name|SurfaceType
name|QWindow
operator|::
name|surfaceType
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|surfaceType
return|;
block|}
end_function
begin_function
DECL|function|setWindowFlags
name|void
name|QWindow
operator|::
name|setWindowFlags
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWindow
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|platformWindow
condition|)
name|d
operator|->
name|windowFlags
operator|=
name|d
operator|->
name|platformWindow
operator|->
name|setWindowFlags
argument_list|(
name|flags
argument_list|)
expr_stmt|;
else|else
name|d
operator|->
name|windowFlags
operator|=
name|flags
expr_stmt|;
block|}
end_function
begin_function
DECL|function|windowFlags
name|Qt
operator|::
name|WindowFlags
name|QWindow
operator|::
name|windowFlags
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|windowFlags
return|;
block|}
end_function
begin_function
DECL|function|setWindowTitle
name|void
name|QWindow
operator|::
name|setWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWindow
argument_list|)
expr_stmt|;
name|d
operator|->
name|windowTitle
operator|=
name|title
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|platformWindow
condition|)
block|{
name|d
operator|->
name|platformWindow
operator|->
name|setWindowTitle
argument_list|(
name|title
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|windowTitle
name|QString
name|QWindow
operator|::
name|windowTitle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|windowTitle
return|;
block|}
end_function
begin_function
DECL|function|raise
name|void
name|QWindow
operator|::
name|raise
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWindow
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|platformWindow
condition|)
block|{
name|d
operator|->
name|platformWindow
operator|->
name|raise
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|lower
name|void
name|QWindow
operator|::
name|lower
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWindow
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|platformWindow
condition|)
block|{
name|d
operator|->
name|platformWindow
operator|->
name|lower
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setOpacity
name|void
name|QWindow
operator|::
name|setOpacity
parameter_list|(
name|qreal
name|level
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWindow
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|platformWindow
condition|)
block|{
name|d
operator|->
name|platformWindow
operator|->
name|setOpacity
argument_list|(
name|level
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|requestActivateWindow
name|void
name|QWindow
operator|::
name|requestActivateWindow
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWindow
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|platformWindow
condition|)
block|{
name|d
operator|->
name|platformWindow
operator|->
name|requestActivateWindow
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|windowState
name|Qt
operator|::
name|WindowStates
name|QWindow
operator|::
name|windowState
parameter_list|()
specifier|const
block|{
name|qDebug
argument_list|()
operator|<<
literal|"unimplemented:"
operator|<<
name|__FILE__
operator|<<
name|__LINE__
expr_stmt|;
return|return
name|Qt
operator|::
name|WindowNoState
return|;
block|}
end_function
begin_function
DECL|function|setWindowState
name|void
name|QWindow
operator|::
name|setWindowState
parameter_list|(
name|Qt
operator|::
name|WindowStates
name|state
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|state
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"unimplemented:"
operator|<<
name|__FILE__
operator|<<
name|__LINE__
expr_stmt|;
block|}
end_function
begin_function
DECL|function|minimumSize
name|QSize
name|QWindow
operator|::
name|minimumSize
parameter_list|()
specifier|const
block|{
name|qDebug
argument_list|()
operator|<<
literal|"unimplemented:"
operator|<<
name|__FILE__
operator|<<
name|__LINE__
expr_stmt|;
return|return
name|QSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|maximumSize
name|QSize
name|QWindow
operator|::
name|maximumSize
parameter_list|()
specifier|const
block|{
name|qDebug
argument_list|()
operator|<<
literal|"unimplemented:"
operator|<<
name|__FILE__
operator|<<
name|__LINE__
expr_stmt|;
return|return
name|QSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setMinimumSize
name|void
name|QWindow
operator|::
name|setMinimumSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"unimplemented:"
operator|<<
name|__FILE__
operator|<<
name|__LINE__
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setMaximumSize
name|void
name|QWindow
operator|::
name|setMaximumSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"unimplemented:"
operator|<<
name|__FILE__
operator|<<
name|__LINE__
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|QWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWindow
argument_list|)
expr_stmt|;
name|d
operator|->
name|geometry
operator|=
name|rect
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|platformWindow
condition|)
block|{
name|d
operator|->
name|platformWindow
operator|->
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|geometry
name|QRect
name|QWindow
operator|::
name|geometry
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|geometry
return|;
block|}
end_function
begin_function
DECL|function|setWindowIcon
name|void
name|QWindow
operator|::
name|setWindowIcon
parameter_list|(
specifier|const
name|QImage
modifier|&
name|icon
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|icon
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"unimplemented:"
operator|<<
name|__FILE__
operator|<<
name|__LINE__
expr_stmt|;
block|}
end_function
begin_function
DECL|function|glContext
name|QWindowContext
modifier|*
name|QWindow
operator|::
name|glContext
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindow
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|platformWindow
operator|&&
operator|!
name|d
operator|->
name|glContext
condition|)
cast|const_cast
argument_list|<
name|QWindowPrivate
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|glContext
operator|=
operator|new
name|QWindowContext
argument_list|(
cast|const_cast
argument_list|<
name|QWindow
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|glContext
return|;
block|}
end_function
begin_function
DECL|function|setRequestFormat
name|void
name|QWindow
operator|::
name|setRequestFormat
parameter_list|(
specifier|const
name|QWindowFormat
modifier|&
name|format
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWindow
argument_list|)
expr_stmt|;
name|d
operator|->
name|requestedFormat
operator|=
name|format
expr_stmt|;
block|}
end_function
begin_function
DECL|function|format
name|QWindowFormat
name|QWindow
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|QWindowFormat
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|destroy
name|void
name|QWindow
operator|::
name|destroy
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWindow
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|glContext
condition|)
block|{
name|d
operator|->
name|glContext
operator|->
name|deleteQGLContext
argument_list|()
expr_stmt|;
block|}
operator|delete
name|d
operator|->
name|glContext
expr_stmt|;
name|d
operator|->
name|glContext
operator|=
literal|0
expr_stmt|;
operator|delete
name|d
operator|->
name|platformWindow
expr_stmt|;
name|d
operator|->
name|platformWindow
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handle
name|QPlatformWindow
modifier|*
name|QWindow
operator|::
name|handle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformWindow
return|;
block|}
end_function
begin_function
DECL|function|surface
name|QWindowSurface
modifier|*
name|QWindow
operator|::
name|surface
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|surface
return|;
block|}
end_function
begin_function
DECL|function|showMinimized
name|void
name|QWindow
operator|::
name|showMinimized
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"unimplemented:"
operator|<<
name|__FILE__
operator|<<
name|__LINE__
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showMaximized
name|void
name|QWindow
operator|::
name|showMaximized
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"unimplemented:"
operator|<<
name|__FILE__
operator|<<
name|__LINE__
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showFullScreen
name|void
name|QWindow
operator|::
name|showFullScreen
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"unimplemented:"
operator|<<
name|__FILE__
operator|<<
name|__LINE__
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showNormal
name|void
name|QWindow
operator|::
name|showNormal
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"unimplemented:"
operator|<<
name|__FILE__
operator|<<
name|__LINE__
expr_stmt|;
block|}
end_function
begin_function
DECL|function|close
name|bool
name|QWindow
operator|::
name|close
parameter_list|()
block|{
comment|//should we have close?
name|qDebug
argument_list|()
operator|<<
literal|"unimplemented:"
operator|<<
name|__FILE__
operator|<<
name|__LINE__
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|QWindow
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|showEvent
name|void
name|QWindow
operator|::
name|showEvent
parameter_list|(
name|QShowEvent
modifier|*
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"unimplemented:"
operator|<<
name|__FILE__
operator|<<
name|__LINE__
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hideEvent
name|void
name|QWindow
operator|::
name|hideEvent
parameter_list|(
name|QHideEvent
modifier|*
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"unimplemented:"
operator|<<
name|__FILE__
operator|<<
name|__LINE__
expr_stmt|;
block|}
end_function
begin_function
DECL|function|event
name|bool
name|QWindow
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
switch|switch
condition|(
name|event
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|MouseMove
case|:
name|mouseMoveEvent
argument_list|(
cast|static_cast
argument_list|<
name|QMouseEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|MouseButtonPress
case|:
name|mousePressEvent
argument_list|(
cast|static_cast
argument_list|<
name|QMouseEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|MouseButtonRelease
case|:
name|mouseReleaseEvent
argument_list|(
cast|static_cast
argument_list|<
name|QMouseEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|MouseButtonDblClick
case|:
name|mouseDoubleClickEvent
argument_list|(
cast|static_cast
argument_list|<
name|QMouseEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|Resize
case|:
name|resizeEvent
argument_list|(
cast|static_cast
argument_list|<
name|QResizeEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|KeyPress
case|:
name|keyPressEvent
argument_list|(
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|KeyRelease
case|:
name|keyReleaseEvent
argument_list|(
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
break|break;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
case|case
name|QEvent
operator|::
name|Wheel
case|:
name|wheelEvent
argument_list|(
cast|static_cast
argument_list|<
name|QWheelEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
name|QEvent
operator|::
name|Close
case|:
name|destroy
argument_list|()
expr_stmt|;
break|break;
default|default:
return|return
name|QObject
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|keyPressEvent
name|void
name|QWindow
operator|::
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|keyReleaseEvent
name|void
name|QWindow
operator|::
name|keyReleaseEvent
parameter_list|(
name|QKeyEvent
modifier|*
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|inputMethodEvent
name|void
name|QWindow
operator|::
name|inputMethodEvent
parameter_list|(
name|QInputMethodEvent
modifier|*
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|QWindow
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|mouseReleaseEvent
name|void
name|QWindow
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|mouseDoubleClickEvent
name|void
name|QWindow
operator|::
name|mouseDoubleClickEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|mouseMoveEvent
name|void
name|QWindow
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
block|{ }
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
end_ifndef
begin_function
DECL|function|wheelEvent
name|void
name|QWindow
operator|::
name|wheelEvent
parameter_list|(
name|QWheelEvent
modifier|*
parameter_list|)
block|{ }
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_WHEELEVENT
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
