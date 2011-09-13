begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (info@qt.nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QtGui/QPlatformScreen>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QWindowsScreenData
struct|struct
name|QWindowsScreenData
block|{
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
name|QPair
operator|<
name|int
operator|,
name|int
operator|>
name|dpi
expr_stmt|;
DECL|member|physicalSizeMM
name|QSize
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
DECL|member|primary
name|bool
name|primary
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
name|explicit
name|QWindowsScreen
argument_list|(
specifier|const
name|QWindowsScreenData
operator|&
name|data
argument_list|)
block|;
specifier|static
name|QWindowsScreen
operator|*
name|screenOf
argument_list|(
specifier|const
name|QWindow
operator|*
name|w
operator|=
literal|0
argument_list|)
block|;
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
name|virtual
name|QSize
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
name|virtual
name|QWindow
operator|*
name|topLevelAt
argument_list|(
argument|const QPoint&point
argument_list|)
specifier|const
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
specifier|static
name|QWindow
operator|*
name|findTopLevelAt
argument_list|(
argument|const QPoint&point
argument_list|,
argument|unsigned flags
argument_list|)
block|;
specifier|static
name|QWindow
operator|*
name|windowAt
argument_list|(
argument|const QPoint&point
argument_list|,
argument|unsigned flags = CWP_SKIPINVISIBLE
argument_list|)
block|;
specifier|static
name|QWindow
operator|*
name|windowUnderMouse
argument_list|(
argument|unsigned flags = CWP_SKIPINVISIBLE
argument_list|)
block|;
specifier|static
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|screens
argument_list|()
block|;
name|virtual
name|QPixmap
name|grabWindow
argument_list|(
argument|WId window
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|)
specifier|const
block|;
specifier|const
name|QWindowsCursor
operator|&
name|cursor
argument_list|()
specifier|const
block|{
return|return
name|m_cursor
return|;
block|}
name|QWindowsCursor
operator|&
name|cursor
argument_list|()
block|{
return|return
name|m_cursor
return|;
block|}
name|private
operator|:
specifier|const
name|QWindowsScreenData
name|m_data
block|;
name|QWindowsCursor
name|m_cursor
block|; }
decl_stmt|;
end_decl_stmt
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
