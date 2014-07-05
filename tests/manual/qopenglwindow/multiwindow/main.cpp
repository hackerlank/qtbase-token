begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QOpenGLWindow>
end_include
begin_include
include|#
directive|include
file|<QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QOpenGLFunctions>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QElapsedTimer>
end_include
begin_comment
comment|// This application opens three windows and continuously schedules updates for
end_comment
begin_comment
comment|// them.  Each of them is a separate QOpenGLWindow so there will be a separate
end_comment
begin_comment
comment|// context and swapBuffers call for each.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// By default the swap interval is 1 so the effect of three blocking swapBuffers
end_comment
begin_comment
comment|// on the main thread can be examined. (the result is likely to be different
end_comment
begin_comment
comment|// between platforms, for example OS X is buffer queuing meaning that it can
end_comment
begin_comment
comment|// block outside swap, resulting in perfect vsync for all three windows, while
end_comment
begin_comment
comment|// other systems that block on swap will kill the frame rate due to blocking the
end_comment
begin_comment
comment|// thread three times)
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Pass --novsync to set a swap interval of 0. This should give an unthrottled
end_comment
begin_comment
comment|// refresh on all platforms for all three windows.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Passing --vsyncone sets swap interval to 1 for the first window and 0 to the
end_comment
begin_comment
comment|// others.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Pass --extrawindows N to open N windows in addition to the default 3.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// For reference, below is a table of some test results.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//                                    swap interval 1 for all             swap interval 1 for only one and 0 for others
end_comment
begin_comment
comment|// --------------------------------------------------------------------------------------------------------------------
end_comment
begin_comment
comment|// OS X (Intel HD)                    60 FPS for all                      60 FPS for all
end_comment
begin_comment
comment|// Windows Intel opengl32             20 FPS for all (each swap blocks)   60 FPS for all
end_comment
begin_comment
comment|// Windows ANGLE D3D9/D3D11           60 FPS for all                      60 FPS for all
end_comment
begin_comment
comment|// Windows ANGLE D3D11 WARP           20 FPS for all                      60 FPS for all
end_comment
begin_comment
comment|// Windows Mesa llvmpipe              does not really vsync anyway
end_comment
begin_class
DECL|class|Window
class|class
name|Window
super|:
specifier|public
name|QOpenGLWindow
block|{
public|public:
DECL|function|Window
name|Window
parameter_list|(
name|int
name|n
parameter_list|)
member_init_list|:
name|idx
argument_list|(
name|n
argument_list|)
block|{
name|r
operator|=
name|g
operator|=
name|b
operator|=
name|fps
operator|=
literal|0
expr_stmt|;
name|y
operator|=
literal|0
expr_stmt|;
name|resize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|t2
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
DECL|function|paintGL
name|void
name|paintGL
parameter_list|()
block|{
name|QOpenGLFunctions
modifier|*
name|f
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|functions
argument_list|()
decl_stmt|;
name|f
operator|->
name|glClearColor
argument_list|(
name|r
argument_list|,
name|g
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|f
operator|->
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|idx
operator|%
literal|3
condition|)
block|{
case|case
literal|0
case|:
name|r
operator|+=
literal|0.005f
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|g
operator|+=
literal|0.005f
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|b
operator|+=
literal|0.005f
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|r
operator|>
literal|1
condition|)
name|r
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|g
operator|>
literal|1
condition|)
name|g
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|b
operator|>
literal|1
condition|)
name|b
operator|=
literal|0
expr_stmt|;
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawText
argument_list|(
name|QPoint
argument_list|(
literal|20
argument_list|,
name|y
argument_list|)
argument_list|,
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|"Window %1 (%2 FPS)"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|idx
argument_list|)
operator|.
name|arg
argument_list|(
name|fps
argument_list|)
argument_list|)
expr_stmt|;
name|y
operator|+=
literal|1
expr_stmt|;
if|if
condition|(
name|y
operator|>
name|height
argument_list|()
operator|-
literal|20
condition|)
name|y
operator|=
literal|20
expr_stmt|;
if|if
condition|(
name|t2
operator|.
name|elapsed
argument_list|()
operator|>
literal|1000
condition|)
block|{
name|fps
operator|=
literal|1000.0
operator|/
name|t
operator|.
name|elapsed
argument_list|()
expr_stmt|;
name|t2
operator|.
name|restart
argument_list|()
expr_stmt|;
block|}
name|t
operator|.
name|restart
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|member|idx
name|int
name|idx
decl_stmt|;
DECL|member|r
DECL|member|g
DECL|member|b
DECL|member|fps
name|GLfloat
name|r
decl_stmt|,
name|g
decl_stmt|,
name|b
decl_stmt|,
name|fps
decl_stmt|;
DECL|member|y
name|int
name|y
decl_stmt|;
DECL|member|t
DECL|member|t2
name|QElapsedTimer
name|t
decl_stmt|,
name|t2
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QGuiApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QSurfaceFormat
name|fmt
decl_stmt|;
if|if
condition|(
name|QGuiApplication
operator|::
name|arguments
argument_list|()
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"--novsync"
argument_list|)
argument_list|)
condition|)
block|{
name|qDebug
argument_list|(
literal|"swap interval 0 (no throttling)"
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setSwapInterval
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qDebug
argument_list|(
literal|"swap interval 1 (sync to vblank)"
argument_list|)
expr_stmt|;
block|}
name|QSurfaceFormat
operator|::
name|setDefaultFormat
argument_list|(
name|fmt
argument_list|)
expr_stmt|;
name|Window
name|w1
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|QGuiApplication
operator|::
name|arguments
argument_list|()
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"--vsyncone"
argument_list|)
argument_list|)
condition|)
block|{
name|qDebug
argument_list|(
literal|"swap interval 1 for first window only"
argument_list|)
expr_stmt|;
name|QSurfaceFormat
name|w1fmt
init|=
name|fmt
decl_stmt|;
name|w1fmt
operator|.
name|setSwapInterval
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|w1
operator|.
name|setFormat
argument_list|(
name|w1fmt
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setSwapInterval
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QSurfaceFormat
operator|::
name|setDefaultFormat
argument_list|(
name|fmt
argument_list|)
expr_stmt|;
block|}
name|Window
name|w2
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|Window
name|w3
argument_list|(
literal|2
argument_list|)
decl_stmt|;
name|w1
operator|.
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|10
argument_list|,
literal|100
argument_list|)
argument_list|,
name|w1
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|w2
operator|.
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|300
argument_list|,
literal|100
argument_list|)
argument_list|,
name|w2
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|w3
operator|.
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|600
argument_list|,
literal|100
argument_list|)
argument_list|,
name|w3
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|w1
operator|.
name|show
argument_list|()
expr_stmt|;
name|w2
operator|.
name|show
argument_list|()
expr_stmt|;
name|w3
operator|.
name|show
argument_list|()
expr_stmt|;
name|QList
argument_list|<
name|QWindow
modifier|*
argument_list|>
name|extraWindows
decl_stmt|;
name|int
name|countIdx
decl_stmt|;
if|if
condition|(
operator|(
name|countIdx
operator|=
name|QGuiApplication
operator|::
name|arguments
argument_list|()
operator|.
name|indexOf
argument_list|(
name|QLatin1String
argument_list|(
literal|"--extrawindows"
argument_list|)
argument_list|)
operator|)
operator|>=
literal|0
condition|)
block|{
name|int
name|extraWindowCount
init|=
name|QGuiApplication
operator|::
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
name|countIdx
operator|+
literal|1
argument_list|)
operator|.
name|toInt
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
name|extraWindowCount
condition|;
operator|++
name|i
control|)
block|{
name|Window
modifier|*
name|w
init|=
operator|new
name|Window
argument_list|(
literal|3
operator|+
name|i
argument_list|)
decl_stmt|;
name|extraWindows
operator|<<
name|w
expr_stmt|;
name|w
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
block|}
name|int
name|r
init|=
name|app
operator|.
name|exec
argument_list|()
decl_stmt|;
name|qDeleteAll
argument_list|(
name|extraWindows
argument_list|)
expr_stmt|;
return|return
name|r
return|;
block|}
end_function
end_unit