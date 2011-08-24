begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTLITEWINDOW_H
end_ifndef
begin_define
DECL|macro|QTESTLITEWINDOW_H
define|#
directive|define
name|QTESTLITEWINDOW_H
end_define
begin_include
include|#
directive|include
file|"qxlibintegration.h"
end_include
begin_include
include|#
directive|include
file|<QPlatformWindow>
end_include
begin_include
include|#
directive|include
file|<QEvent>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_struct
DECL|struct|QXlibMWMHints
struct|struct
name|QXlibMWMHints
block|{
DECL|member|flags
DECL|member|functions
DECL|member|decorations
name|ulong
name|flags
decl_stmt|,
name|functions
decl_stmt|,
name|decorations
decl_stmt|;
DECL|member|input_mode
name|long
name|input_mode
decl_stmt|;
DECL|member|status
name|ulong
name|status
decl_stmt|;
block|}
struct|;
end_struct
begin_enum
enum|enum
block|{
DECL|enumerator|MWM_HINTS_FUNCTIONS
name|MWM_HINTS_FUNCTIONS
init|=
operator|(
literal|1L
operator|<<
literal|0
operator|)
block|,
DECL|enumerator|MWM_FUNC_ALL
name|MWM_FUNC_ALL
init|=
operator|(
literal|1L
operator|<<
literal|0
operator|)
block|,
DECL|enumerator|MWM_FUNC_RESIZE
name|MWM_FUNC_RESIZE
init|=
operator|(
literal|1L
operator|<<
literal|1
operator|)
block|,
DECL|enumerator|MWM_FUNC_MOVE
name|MWM_FUNC_MOVE
init|=
operator|(
literal|1L
operator|<<
literal|2
operator|)
block|,
DECL|enumerator|MWM_FUNC_MINIMIZE
name|MWM_FUNC_MINIMIZE
init|=
operator|(
literal|1L
operator|<<
literal|3
operator|)
block|,
DECL|enumerator|MWM_FUNC_MAXIMIZE
name|MWM_FUNC_MAXIMIZE
init|=
operator|(
literal|1L
operator|<<
literal|4
operator|)
block|,
DECL|enumerator|MWM_FUNC_CLOSE
name|MWM_FUNC_CLOSE
init|=
operator|(
literal|1L
operator|<<
literal|5
operator|)
block|,
DECL|enumerator|MWM_HINTS_DECORATIONS
name|MWM_HINTS_DECORATIONS
init|=
operator|(
literal|1L
operator|<<
literal|1
operator|)
block|,
DECL|enumerator|MWM_DECOR_ALL
name|MWM_DECOR_ALL
init|=
operator|(
literal|1L
operator|<<
literal|0
operator|)
block|,
DECL|enumerator|MWM_DECOR_BORDER
name|MWM_DECOR_BORDER
init|=
operator|(
literal|1L
operator|<<
literal|1
operator|)
block|,
DECL|enumerator|MWM_DECOR_RESIZEH
name|MWM_DECOR_RESIZEH
init|=
operator|(
literal|1L
operator|<<
literal|2
operator|)
block|,
DECL|enumerator|MWM_DECOR_TITLE
name|MWM_DECOR_TITLE
init|=
operator|(
literal|1L
operator|<<
literal|3
operator|)
block|,
DECL|enumerator|MWM_DECOR_MENU
name|MWM_DECOR_MENU
init|=
operator|(
literal|1L
operator|<<
literal|4
operator|)
block|,
DECL|enumerator|MWM_DECOR_MINIMIZE
name|MWM_DECOR_MINIMIZE
init|=
operator|(
literal|1L
operator|<<
literal|5
operator|)
block|,
DECL|enumerator|MWM_DECOR_MAXIMIZE
name|MWM_DECOR_MAXIMIZE
init|=
operator|(
literal|1L
operator|<<
literal|6
operator|)
block|,
DECL|enumerator|MWM_HINTS_INPUT_MODE
name|MWM_HINTS_INPUT_MODE
init|=
operator|(
literal|1L
operator|<<
literal|2
operator|)
block|,
DECL|enumerator|MWM_INPUT_MODELESS
name|MWM_INPUT_MODELESS
init|=
literal|0L
block|,
DECL|enumerator|MWM_INPUT_PRIMARY_APPLICATION_MODAL
name|MWM_INPUT_PRIMARY_APPLICATION_MODAL
init|=
literal|1L
block|,
DECL|enumerator|MWM_INPUT_FULL_APPLICATION_MODAL
name|MWM_INPUT_FULL_APPLICATION_MODAL
init|=
literal|3L
block|}
enum|;
end_enum
begin_decl_stmt
name|class
name|QXlibWindow
range|:
name|public
name|QPlatformWindow
block|{
name|public
operator|:
name|QXlibWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
operator|~
name|QXlibWindow
argument_list|()
block|;
name|void
name|mousePressEvent
argument_list|(
name|XButtonEvent
operator|*
argument_list|)
block|;
name|void
name|handleMouseEvent
argument_list|(
name|QEvent
operator|::
name|Type
argument_list|,
name|XButtonEvent
operator|*
name|ev
argument_list|)
block|;
name|void
name|handleCloseEvent
argument_list|()
block|;
name|void
name|handleEnterEvent
argument_list|()
block|;
name|void
name|handleLeaveEvent
argument_list|()
block|;
name|void
name|handleFocusInEvent
argument_list|()
block|;
name|void
name|handleFocusOutEvent
argument_list|()
block|;
name|void
name|resizeEvent
argument_list|(
name|XConfigureEvent
operator|*
name|configure_event
argument_list|)
block|;
name|void
name|requestActivateWindow
argument_list|()
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
name|Qt
operator|::
name|WindowFlags
name|setWindowFlags
argument_list|(
argument|Qt::WindowFlags type
argument_list|)
block|;
name|Qt
operator|::
name|WindowFlags
name|windowFlags
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|WindowState
name|setWindowState
argument_list|(
argument|Qt::WindowState state
argument_list|)
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|WId
name|winId
argument_list|()
specifier|const
block|;
name|void
name|setParent
argument_list|(
specifier|const
name|QPlatformWindow
operator|*
name|window
argument_list|)
block|;
name|void
name|raise
argument_list|()
block|;
name|void
name|lower
argument_list|()
block|;
name|void
name|setWindowTitle
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
name|void
name|setCursor
argument_list|(
specifier|const
name|Cursor
operator|&
name|cursor
argument_list|)
block|;
name|Window
name|xWindow
argument_list|()
specifier|const
block|;
name|GC
name|graphicsContext
argument_list|()
specifier|const
block|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
block|;
name|Visual
operator|*
name|visual
argument_list|()
specifier|const
block|{
return|return
name|mVisual
return|;
block|}
name|int
name|depth
argument_list|()
specifier|const
block|{
return|return
name|mDepth
return|;
block|}
specifier|static
name|QXlibWindow
operator|*
name|platformWindowForXWindow
argument_list|(
argument|Window window
argument_list|)
block|;
name|protected
operator|:
name|QVector
operator|<
name|Atom
operator|>
name|getNetWmState
argument_list|()
specifier|const
block|;
name|void
name|setMWMHints
argument_list|(
specifier|const
name|QXlibMWMHints
operator|&
name|mwmhints
argument_list|)
block|;
name|QXlibMWMHints
name|getMWMHints
argument_list|()
specifier|const
block|;
name|void
name|doSizeHints
argument_list|()
block|;
name|private
operator|:
name|Window
name|x_window
block|;
name|GC
name|gc
block|;
name|uint
name|mDepth
block|;
name|QImage
operator|::
name|Format
name|mFormat
block|;
name|Visual
operator|*
name|mVisual
block|;
name|GC
name|createGC
argument_list|()
block|;
name|QPlatformGLContext
operator|*
name|mGLContext
block|;
name|QXlibScreen
operator|*
name|mScreen
block|;
name|Qt
operator|::
name|WindowFlags
name|mWindowFlags
block|;
specifier|static
name|QHash
operator|<
name|Window
block|,
name|QXlibWindow
operator|*
operator|>
name|windowMap
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
