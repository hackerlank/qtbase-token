begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QXCBINTEGRATION_H
define|#
directive|define
name|QXCBINTEGRATION_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QPlatformIntegration>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformScreen>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QXcbConnection
name|class
name|QXcbConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QXcbIntegration
range|:
name|public
name|QPlatformIntegration
block|{
name|public
operator|:
name|QXcbIntegration
argument_list|()
block|;
operator|~
name|QXcbIntegration
argument_list|()
block|;
name|bool
name|hasCapability
argument_list|(
argument|Capability cap
argument_list|)
specifier|const
block|;
name|QPixmapData
operator|*
name|createPixmapData
argument_list|(
argument|QPixmapData::PixelType type
argument_list|)
specifier|const
block|;
name|QPlatformWindow
operator|*
name|createPlatformWindow
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
block|;
name|QWindowSurface
operator|*
name|createWindowSurface
argument_list|(
argument|QWindow *window
argument_list|,
argument|WId winId
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|screens
argument_list|()
specifier|const
block|;
name|void
name|moveToScreen
argument_list|(
argument|QWidget *window
argument_list|,
argument|int screen
argument_list|)
block|;
name|bool
name|isVirtualDesktop
argument_list|()
block|;
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
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
block|;
name|QPlatformNativeInterface
operator|*
name|nativeInterface
argument_list|()
specifier|const
block|;
name|private
operator|:
name|bool
name|hasOpenGL
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|m_screens
block|;
name|QXcbConnection
operator|*
name|m_connection
block|;
name|QPlatformFontDatabase
operator|*
name|m_fontDatabase
block|;
name|QPlatformNativeInterface
operator|*
name|m_nativeInterface
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
end_unit
