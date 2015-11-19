begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSCURSOR_H
end_ifndef
begin_define
DECL|macro|QWINDOWSCURSOR_H
define|#
directive|define
name|QWINDOWSCURSOR_H
end_define
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformcursor.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QWindowsPixmapCursorCacheKey
struct|struct
name|QWindowsPixmapCursorCacheKey
block|{
name|explicit
name|QWindowsPixmapCursorCacheKey
parameter_list|(
specifier|const
name|QCursor
modifier|&
name|c
parameter_list|)
function_decl|;
DECL|member|bitmapCacheKey
name|qint64
name|bitmapCacheKey
decl_stmt|;
DECL|member|maskCacheKey
name|qint64
name|maskCacheKey
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QWindowsPixmapCursorCacheKey
operator|&
name|k1
operator|,
specifier|const
name|QWindowsPixmapCursorCacheKey
operator|&
name|k2
operator|)
block|{
return|return
name|k1
operator|.
name|bitmapCacheKey
operator|==
name|k2
operator|.
name|bitmapCacheKey
operator|&&
name|k1
operator|.
name|maskCacheKey
operator|==
name|k2
operator|.
name|maskCacheKey
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|QWindowsPixmapCursorCacheKey
modifier|&
name|k
parameter_list|,
name|uint
name|seed
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
operator|(
name|uint
argument_list|(
name|k
operator|.
name|bitmapCacheKey
argument_list|)
operator|+
name|uint
argument_list|(
name|k
operator|.
name|maskCacheKey
argument_list|)
operator|)
operator|^
name|seed
return|;
block|}
end_function
begin_decl_stmt
name|class
name|CursorHandle
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|CursorHandle
argument_list|)
name|public
label|:
name|explicit
name|CursorHandle
argument_list|(
argument|HCURSOR hcursor = Q_NULLPTR
argument_list|)
block|:
name|m_hcursor
argument_list|(
argument|hcursor
argument_list|)
block|{}
operator|~
name|CursorHandle
argument_list|()
block|{
if|if
condition|(
name|m_hcursor
condition|)
name|DestroyCursor
argument_list|(
name|m_hcursor
argument_list|)
expr_stmt|;
block|}
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
operator|!
name|m_hcursor
return|;
block|}
name|HCURSOR
name|handle
argument_list|()
specifier|const
block|{
return|return
name|m_hcursor
return|;
block|}
name|private
label|:
specifier|const
name|HCURSOR
name|m_hcursor
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_typedef
DECL|typedef|CursorHandlePtr
typedef|typedef
name|QSharedPointer
operator|<
name|CursorHandle
operator|>
name|CursorHandlePtr
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QWindowsCursor
range|:
name|public
name|QPlatformCursor
block|{
name|public
operator|:
expr|enum
name|CursorState
block|{
name|CursorShowing
block|,
name|CursorHidden
block|,
name|CursorSuppressed
comment|// Cursor suppressed by touch interaction (Windows 8).
block|}
block|;      struct
name|PixmapCursor
block|{
name|explicit
name|PixmapCursor
argument_list|(
specifier|const
name|QPixmap
operator|&
name|pix
operator|=
name|QPixmap
argument_list|()
argument_list|,
specifier|const
name|QPoint
operator|&
name|h
operator|=
name|QPoint
argument_list|()
argument_list|)
operator|:
name|pixmap
argument_list|(
name|pix
argument_list|)
block|,
name|hotSpot
argument_list|(
argument|h
argument_list|)
block|{}
name|QPixmap
name|pixmap
block|;
name|QPoint
name|hotSpot
block|;     }
block|;
name|explicit
name|QWindowsCursor
argument_list|(
specifier|const
name|QPlatformScreen
operator|*
name|screen
argument_list|)
block|;
name|void
name|changeCursor
argument_list|(
argument|QCursor * widgetCursor
argument_list|,
argument|QWindow * widget
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QPoint
name|pos
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setPos
argument_list|(
argument|const QPoint&pos
argument_list|)
name|Q_DECL_OVERRIDE
block|;
specifier|static
name|HCURSOR
name|createPixmapCursor
argument_list|(
argument|QPixmap pixmap
argument_list|,
argument|const QPoint&hotSpot
argument_list|,
argument|qreal scaleFactor =
literal|1
argument_list|)
block|;
specifier|static
name|HCURSOR
name|createPixmapCursor
argument_list|(
argument|const PixmapCursor&pc
argument_list|,
argument|qreal scaleFactor =
literal|1
argument_list|)
block|{
return|return
name|createPixmapCursor
argument_list|(
name|pc
operator|.
name|pixmap
argument_list|,
name|pc
operator|.
name|hotSpot
argument_list|,
name|scaleFactor
argument_list|)
return|;
block|}
specifier|static
name|PixmapCursor
name|customCursor
argument_list|(
argument|Qt::CursorShape cursorShape
argument_list|,
argument|const QPlatformScreen *screen = Q_NULLPTR
argument_list|)
block|;
specifier|static
name|HCURSOR
name|createCursorFromShape
argument_list|(
argument|Qt::CursorShape cursorShape
argument_list|,
argument|const QPlatformScreen *screen = Q_NULLPTR
argument_list|)
block|;
specifier|static
name|QPoint
name|mousePosition
argument_list|()
block|;
specifier|static
name|CursorState
name|cursorState
argument_list|()
block|;
name|CursorHandlePtr
name|standardWindowCursor
argument_list|(
argument|Qt::CursorShape s = Qt::ArrowCursor
argument_list|)
block|;
name|CursorHandlePtr
name|pixmapWindowCursor
argument_list|(
specifier|const
name|QCursor
operator|&
name|c
argument_list|)
block|;
name|QPixmap
name|dragDefaultCursor
argument_list|(
argument|Qt::DropAction action
argument_list|)
specifier|const
block|;
name|private
operator|:
typedef|typedef
name|QHash
operator|<
name|Qt
operator|::
name|CursorShape
operator|,
name|CursorHandlePtr
operator|>
name|StandardCursorCache
expr_stmt|;
end_decl_stmt
begin_typedef
typedef|typedef
name|QHash
operator|<
name|QWindowsPixmapCursorCacheKey
operator|,
name|CursorHandlePtr
operator|>
name|PixmapCursorCache
expr_stmt|;
end_typedef
begin_decl_stmt
specifier|const
name|QPlatformScreen
modifier|*
specifier|const
name|m_screen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|StandardCursorCache
name|m_standardCursorCache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|PixmapCursorCache
name|m_pixmapCursorCache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|QPixmap
name|m_copyDragCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|QPixmap
name|m_moveDragCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|QPixmap
name|m_linkDragCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|QPixmap
name|m_ignoreDragCursor
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSCURSOR_H
end_comment
end_unit
