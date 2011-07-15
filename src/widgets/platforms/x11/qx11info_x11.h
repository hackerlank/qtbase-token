begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QX11INFO_X11_H
end_ifndef
begin_define
DECL|macro|QX11INFO_X11_H
define|#
directive|define
name|QX11INFO_X11_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_typedef
DECL|typedef|Display
typedef|typedef
name|struct
name|_XDisplay
name|Display
typedef|;
end_typedef
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
function|struct QX11InfoData;
end_function
begin_decl_stmt
DECL|variable|QX11Info
name|class
name|QX11Info
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPaintDevice
name|class
name|QPaintDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QApplicationPrivate
name|class
name|QApplicationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QX11InfoPrivate
name|class
name|QX11InfoPrivate
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QX11WindowAttributes
struct_decl|;
end_struct_decl
begin_function_decl
name|void
name|qt_x11_getX11InfoForWindow
parameter_list|(
name|QX11Info
modifier|*
name|xinfo
parameter_list|,
specifier|const
name|QX11WindowAttributes
modifier|&
name|a
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QX11Info
block|{
name|public
label|:
name|QX11Info
argument_list|()
expr_stmt|;
operator|~
name|QX11Info
argument_list|()
expr_stmt|;
name|QX11Info
argument_list|(
specifier|const
name|QX11Info
operator|&
name|other
argument_list|)
expr_stmt|;
name|QX11Info
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QX11Info
operator|&
name|other
operator|)
decl_stmt|;
specifier|static
name|Display
modifier|*
name|display
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|appClass
parameter_list|()
function_decl|;
name|int
name|screen
argument_list|()
specifier|const
expr_stmt|;
name|int
name|depth
argument_list|()
specifier|const
expr_stmt|;
name|int
name|cells
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|HANDLE
name|colormap
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|defaultColormap
argument_list|()
specifier|const
expr_stmt|;
name|void
operator|*
name|visual
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|defaultVisual
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|int
name|appScreen
parameter_list|()
function_decl|;
specifier|static
name|int
name|appDepth
parameter_list|(
name|int
name|screen
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
specifier|static
name|int
name|appCells
parameter_list|(
name|int
name|screen
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
specifier|static
name|Qt
operator|::
name|HANDLE
name|appColormap
argument_list|(
argument|int screen = -
literal|1
argument_list|)
expr_stmt|;
specifier|static
name|void
modifier|*
name|appVisual
parameter_list|(
name|int
name|screen
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
specifier|static
name|Qt
operator|::
name|HANDLE
name|appRootWindow
argument_list|(
argument|int screen = -
literal|1
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|appDefaultColormap
parameter_list|(
name|int
name|screen
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
specifier|static
name|bool
name|appDefaultVisual
parameter_list|(
name|int
name|screen
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
specifier|static
name|int
name|appDpiX
parameter_list|(
name|int
name|screen
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
specifier|static
name|int
name|appDpiY
parameter_list|(
name|int
name|screen
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
specifier|static
name|void
name|setAppDpiX
parameter_list|(
name|int
name|screen
parameter_list|,
name|int
name|dpi
parameter_list|)
function_decl|;
specifier|static
name|void
name|setAppDpiY
parameter_list|(
name|int
name|screen
parameter_list|,
name|int
name|dpi
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|long
name|appTime
parameter_list|()
function_decl|;
specifier|static
name|unsigned
name|long
name|appUserTime
parameter_list|()
function_decl|;
specifier|static
name|void
name|setAppTime
parameter_list|(
name|unsigned
name|long
name|time
parameter_list|)
function_decl|;
specifier|static
name|void
name|setAppUserTime
parameter_list|(
name|unsigned
name|long
name|time
parameter_list|)
function_decl|;
specifier|static
name|bool
name|isCompositingManagerRunning
parameter_list|()
function_decl|;
name|protected
label|:
name|void
name|copyX11Data
parameter_list|(
specifier|const
name|QPaintDevice
modifier|*
parameter_list|)
function_decl|;
name|void
name|cloneX11Data
parameter_list|(
specifier|const
name|QPaintDevice
modifier|*
parameter_list|)
function_decl|;
name|void
name|setX11Data
parameter_list|(
specifier|const
name|QX11InfoData
modifier|*
parameter_list|)
function_decl|;
name|QX11InfoData
modifier|*
name|getX11Data
argument_list|(
name|bool
name|def
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|QX11InfoData
modifier|*
name|x11data
decl_stmt|;
name|friend
name|class
name|QX11PaintEngine
decl_stmt|;
name|friend
name|class
name|QPixmap
decl_stmt|;
name|friend
name|class
name|QX11PlatformPixmap
decl_stmt|;
name|friend
name|class
name|QWidget
decl_stmt|;
name|friend
name|class
name|QWidgetPrivate
decl_stmt|;
name|friend
name|class
name|QGLWidget
decl_stmt|;
name|friend
name|void
name|qt_init
argument_list|(
name|QApplicationPrivate
operator|*
name|priv
argument_list|,
name|int
argument_list|,
name|Display
operator|*
name|display
argument_list|,
name|Qt
operator|::
name|HANDLE
name|visual
argument_list|,
name|Qt
operator|::
name|HANDLE
name|colormap
argument_list|)
decl_stmt|;
name|friend
name|void
name|qt_cleanup
parameter_list|()
function_decl|;
name|friend
name|void
name|qt_x11_getX11InfoForWindow
parameter_list|(
name|QX11Info
modifier|*
name|xinfo
parameter_list|,
specifier|const
name|QX11WindowAttributes
modifier|&
name|a
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QX11INFO_X11_H
end_comment
end_unit
