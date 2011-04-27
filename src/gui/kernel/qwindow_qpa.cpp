begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindow_qpa.h"
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
file|"qapplication_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QWindowPrivate
class|class
name|QWindowPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
public|public:
DECL|function|QWindowPrivate
name|QWindowPrivate
parameter_list|()
member_init_list|:
name|QObjectPrivate
argument_list|()
member_init_list|,
name|windowFlags
argument_list|(
name|Qt
operator|::
name|Window
argument_list|)
member_init_list|,
name|surfaceType
argument_list|(
name|QWindow
operator|::
name|RasterSurface
argument_list|)
member_init_list|,
name|platformWindow
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|glContext
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|widget
argument_list|(
literal|0
argument_list|)
block|{      }
DECL|function|~QWindowPrivate
name|~
name|QWindowPrivate
parameter_list|()
block|{      }
DECL|member|windowFlags
name|Qt
operator|::
name|WindowFlags
name|windowFlags
decl_stmt|;
DECL|member|surfaceType
name|QWindow
operator|::
name|SurfaceType
name|surfaceType
decl_stmt|;
DECL|member|platformWindow
name|QPlatformWindow
modifier|*
name|platformWindow
decl_stmt|;
DECL|member|requestedFormat
name|QWindowFormat
name|requestedFormat
decl_stmt|;
DECL|member|windowTitle
name|QString
name|windowTitle
decl_stmt|;
DECL|member|geometry
name|QRect
name|geometry
decl_stmt|;
DECL|member|glContext
name|QWindowContext
modifier|*
name|glContext
decl_stmt|;
DECL|member|widget
name|QWidget
modifier|*
name|widget
decl_stmt|;
block|}
class|;
end_class
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
block|{ }
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
DECL|function|widget
name|QWidget
modifier|*
name|QWindow
operator|::
name|widget
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
name|widget
return|;
block|}
end_function
begin_function
DECL|function|setWidget
name|void
name|QWindow
operator|::
name|setWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWindow
argument_list|)
expr_stmt|;
name|d
operator|->
name|widget
operator|=
name|widget
expr_stmt|;
block|}
end_function
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
name|QApplicationPrivate
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
block|}
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|platformWindow
argument_list|)
expr_stmt|;
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
DECL|function|setParent
name|void
name|QWindow
operator|::
name|setParent
parameter_list|(
specifier|const
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
comment|//How should we support lazy init when setting parent
if|if
condition|(
operator|!
name|parent
operator|->
name|d_func
argument_list|()
operator|->
name|platformWindow
condition|)
block|{
cast|const_cast
argument_list|<
name|QWindow
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|)
operator|->
name|create
argument_list|()
expr_stmt|;
block|}
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
comment|//JA, this will be solved later....
comment|//    if (QGLContext *context = extra->topextra->window->glContext()) {
comment|//                context->deleteQGLContext();
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
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
comment|//    }
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
return|return
literal|false
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
block|{  }
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
