begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSBACKINGSTORE_H
end_ifndef
begin_define
DECL|macro|QWINDOWSBACKINGSTORE_H
define|#
directive|define
name|QWINDOWSBACKINGSTORE_H
end_define
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformbackingstore.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QScopedPointer>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindowsWindow
name|class
name|QWindowsWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindowsNativeImage
name|class
name|QWindowsNativeImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsBackingStore
range|:
name|public
name|QPlatformBackingStore
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QWindowsBackingStore
argument_list|)
name|public
operator|:
name|QWindowsBackingStore
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
operator|~
name|QWindowsBackingStore
argument_list|()
block|;
name|virtual
name|QPaintDevice
operator|*
name|paintDevice
argument_list|()
block|;
name|virtual
name|void
name|flush
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
specifier|const
name|QRegion
operator|&
name|region
argument_list|,
specifier|const
name|QPoint
operator|&
name|offset
argument_list|)
block|;
name|virtual
name|void
name|resize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QRegion
operator|&
name|r
argument_list|)
block|;
name|virtual
name|void
name|beginPaint
argument_list|(
specifier|const
name|QRegion
operator|&
argument_list|)
block|;
name|HDC
name|getDC
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QWindowsWindow
operator|*
name|rasterWindow
argument_list|()
specifier|const
block|;
name|QScopedPointer
operator|<
name|QWindowsNativeImage
operator|>
name|m_image
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
comment|// QWINDOWSBACKINGSTORE_H
end_comment
end_unit
