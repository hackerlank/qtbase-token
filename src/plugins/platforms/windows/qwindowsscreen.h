begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSSCREEN_H
end_ifndef
begin_define
DECL|macro|QWINDOWSSCREEN_H
define|#
directive|define
name|QWINDOWSSCREEN_H
end_define
begin_include
include|#
directive|include
file|"qwindowscursor.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINCE
end_ifdef
begin_include
include|#
directive|include
file|"qplatformfunctions_wince.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QPair>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedPointer>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QWindowsScreenData
struct|struct
name|QWindowsScreenData
block|{
DECL|enum|Flags
enum|enum
name|Flags
block|{
DECL|enumerator|PrimaryScreen
name|PrimaryScreen
init|=
literal|0x1
block|,
DECL|enumerator|VirtualDesktop
name|VirtualDesktop
init|=
literal|0x2
block|}
enum|;
name|QWindowsScreenData
argument_list|()
expr_stmt|;
DECL|member|geometry
name|QRect
name|geometry
decl_stmt|;
DECL|member|availableGeometry
name|QRect
name|availableGeometry
decl_stmt|;
DECL|member|dpi
name|QDpi
name|dpi
decl_stmt|;
DECL|member|physicalSizeMM
name|QSizeF
name|physicalSizeMM
decl_stmt|;
DECL|member|depth
name|int
name|depth
decl_stmt|;
DECL|member|format
name|QImage
operator|::
name|Format
name|format
expr_stmt|;
DECL|member|flags
name|unsigned
name|flags
decl_stmt|;
DECL|member|name
name|QString
name|name
decl_stmt|;
DECL|member|orientation
name|Qt
operator|::
name|ScreenOrientation
name|orientation
expr_stmt|;
DECL|member|refreshRateHz
name|qreal
name|refreshRateHz
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QWindowsScreen
range|:
name|public
name|QPlatformScreen
block|{
name|public
operator|:
typedef|typedef
name|QSharedPointer
operator|<
name|QWindowsCursor
operator|>
name|WindowsCursorPtr
expr_stmt|;
name|explicit
name|QWindowsScreen
argument_list|(
specifier|const
name|QWindowsScreenData
operator|&
name|data
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|QWindowsScreen
modifier|*
name|screenOf
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|w
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|virtual
name|QRect
name|geometry
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|.
name|geometry
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|QRect
name|availableGeometry
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|.
name|availableGeometry
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|int
name|depth
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|.
name|depth
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|.
name|format
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|.
name|physicalSizeMM
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|QDpi
name|logicalDpi
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|.
name|dpi
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|qreal
name|refreshRate
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|.
name|refreshRateHz
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|QString
name|name
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|.
name|name
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|Qt
operator|::
name|ScreenOrientation
name|primaryOrientation
argument_list|()
block|{
return|return
name|m_data
operator|.
name|orientation
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|virtualSiblings
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|virtual
name|QWindow
modifier|*
name|topLevelAt
argument_list|(
specifier|const
name|QPoint
operator|&
name|point
argument_list|)
decl|const
block|{
return|return
name|QWindowsScreen
operator|::
name|findTopLevelAt
argument_list|(
name|point
argument_list|,
name|CWP_SKIPINVISIBLE
argument_list|)
return|;
block|}
end_decl_stmt
begin_function_decl
specifier|static
name|QWindow
modifier|*
name|findTopLevelAt
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|point
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QWindow
modifier|*
name|windowAt
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|point
parameter_list|,
name|unsigned
name|flags
init|=
name|CWP_SKIPINVISIBLE
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QWindow
modifier|*
name|windowUnderMouse
parameter_list|(
name|unsigned
name|flags
init|=
name|CWP_SKIPINVISIBLE
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|virtual
name|QPixmap
name|grabWindow
argument_list|(
name|WId
name|window
argument_list|,
name|int
name|x
argument_list|,
name|int
name|y
argument_list|,
name|int
name|width
argument_list|,
name|int
name|height
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|inline
name|void
name|handleChanges
parameter_list|(
specifier|const
name|QWindowsScreenData
modifier|&
name|newData
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QPlatformCursor
operator|*
name|cursor
argument_list|()
specifier|const
block|{
return|return
name|m_cursor
operator|.
name|data
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|const
name|WindowsCursorPtr
operator|&
name|windowsCursor
argument_list|()
specifier|const
block|{
return|return
name|m_cursor
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|const
name|QWindowsScreenData
operator|&
name|data
argument_list|()
specifier|const
block|{
return|return
name|m_data
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QWindowsScreenData
name|m_data
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|WindowsCursorPtr
name|m_cursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|QWindowsScreenManager
block|{
name|public
label|:
typedef|typedef
name|QList
operator|<
name|QWindowsScreen
operator|*
operator|>
name|WindowsScreenList
expr_stmt|;
name|QWindowsScreenManager
argument_list|()
expr_stmt|;
specifier|inline
name|void
name|clearScreens
parameter_list|()
block|{
comment|// Delete screens in reverse order to avoid crash in case of multiple screens
while|while
condition|(
operator|!
name|m_screens
operator|.
name|isEmpty
argument_list|()
condition|)
name|delete
name|m_screens
operator|.
name|takeLast
parameter_list|()
function_decl|;
block|}
name|bool
name|handleScreenChanges
parameter_list|()
function_decl|;
name|bool
name|handleDisplayChange
parameter_list|(
name|WPARAM
name|wParam
parameter_list|,
name|LPARAM
name|lParam
parameter_list|)
function_decl|;
specifier|const
name|WindowsScreenList
operator|&
name|screens
argument_list|()
specifier|const
block|{
return|return
name|m_screens
return|;
block|}
name|private
label|:
name|WindowsScreenList
name|m_screens
decl_stmt|;
name|int
name|m_lastDepth
decl_stmt|;
name|WORD
name|m_lastHorizontalResolution
decl_stmt|;
name|WORD
name|m_lastVerticalResolution
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSSCREEN_H
end_comment
end_unit
