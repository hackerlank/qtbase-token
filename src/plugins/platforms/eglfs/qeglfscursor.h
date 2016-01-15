begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLFSCURSOR_H
end_ifndef
begin_define
DECL|macro|QEGLFSCURSOR_H
define|#
directive|define
name|QEGLFSCURSOR_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"qeglfsglobal.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformcursor.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLFunctions>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qinputdevicemanager_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLShaderProgram
name|class
name|QOpenGLShaderProgram
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEglFSCursor
name|class
name|QEglFSCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEglFSScreen
name|class
name|QEglFSScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEglFSCursorDeviceListener
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QEglFSCursorDeviceListener
argument_list|(
name|QEglFSCursor
operator|*
name|cursor
argument_list|)
operator|:
name|m_cursor
argument_list|(
argument|cursor
argument_list|)
block|{ }
name|bool
name|hasMouse
argument_list|()
specifier|const
block|;
name|public
name|slots
operator|:
name|void
name|onDeviceListChanged
argument_list|(
argument|QInputDeviceManager::DeviceType type
argument_list|)
block|;
name|private
operator|:
name|QEglFSCursor
operator|*
name|m_cursor
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformCursor
name|class
name|Q_EGLFS_EXPORT
name|QEglFSCursor
range|:
name|public
name|QPlatformCursor
decl_stmt|,
name|protected
name|QOpenGLFunctions
block|{
name|Q_OBJECT
name|public
range|:
name|QEglFSCursor
argument_list|(
name|QPlatformScreen
operator|*
name|screen
argument_list|)
decl_stmt|;
operator|~
name|QEglFSCursor
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|void
name|changeCursor
argument_list|(
name|QCursor
operator|*
name|cursor
argument_list|,
name|QWindow
operator|*
name|widget
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
endif|#
directive|endif
name|void
name|pointerEvent
argument_list|(
specifier|const
name|QMouseEvent
operator|&
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QPoint
name|pos
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|setPos
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QRect
name|cursorRect
argument_list|()
specifier|const
expr_stmt|;
name|void
name|paintOnScreen
parameter_list|()
function_decl|;
name|void
name|resetResources
parameter_list|()
function_decl|;
name|void
name|updateMouseStatus
parameter_list|()
function_decl|;
name|private
label|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|bool
name|setCurrentCursor
parameter_list|(
name|QCursor
modifier|*
name|cursor
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
name|draw
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
function_decl|;
name|void
name|update
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
function_decl|;
name|void
name|createShaderPrograms
parameter_list|()
function_decl|;
name|void
name|createCursorTexture
parameter_list|(
name|uint
modifier|*
name|texture
parameter_list|,
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
function_decl|;
name|void
name|initCursorAtlas
parameter_list|()
function_decl|;
comment|// current cursor information
struct|struct
name|Cursor
block|{
name|Cursor
argument_list|()
operator|:
name|texture
argument_list|(
literal|0
argument_list|)
operator|,
name|shape
argument_list|(
name|Qt
operator|::
name|BlankCursor
argument_list|)
operator|,
name|customCursorTexture
argument_list|(
literal|0
argument_list|)
operator|,
name|customCursorPending
argument_list|(
argument|false
argument_list|)
block|{ }
name|uint
name|texture
expr_stmt|;
comment|// a texture from 'image' or the atlas
name|Qt
operator|::
name|CursorShape
name|shape
expr_stmt|;
name|QRectF
name|textureRect
decl_stmt|;
comment|// normalized rect inside texture
name|QSize
name|size
decl_stmt|;
comment|// size of the cursor
name|QPoint
name|hotSpot
decl_stmt|;
name|QImage
name|customCursorImage
decl_stmt|;
name|QPoint
name|pos
decl_stmt|;
comment|// current cursor position
name|uint
name|customCursorTexture
decl_stmt|;
name|bool
name|customCursorPending
decl_stmt|;
block|}
name|m_cursor
struct|;
comment|// cursor atlas information
struct|struct
name|CursorAtlas
block|{
name|CursorAtlas
argument_list|()
operator|:
name|cursorsPerRow
argument_list|(
literal|0
argument_list|)
operator|,
name|texture
argument_list|(
literal|0
argument_list|)
operator|,
name|cursorWidth
argument_list|(
literal|0
argument_list|)
operator|,
name|cursorHeight
argument_list|(
literal|0
argument_list|)
block|{ }
name|int
name|cursorsPerRow
expr_stmt|;
name|uint
name|texture
decl_stmt|;
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|// width and height of the atlas
name|int
name|cursorWidth
decl_stmt|,
name|cursorHeight
decl_stmt|;
comment|// width and height of cursors inside the atlas
name|QList
operator|<
name|QPoint
operator|>
name|hotSpots
expr_stmt|;
name|QImage
name|image
decl_stmt|;
comment|// valid until it's uploaded
block|}
name|m_cursorAtlas
struct|;
name|bool
name|m_visible
decl_stmt|;
name|QEglFSScreen
modifier|*
name|m_screen
decl_stmt|;
name|QOpenGLShaderProgram
modifier|*
name|m_program
decl_stmt|;
name|int
name|m_textureEntry
decl_stmt|;
name|QEglFSCursorDeviceListener
modifier|*
name|m_deviceListener
decl_stmt|;
name|bool
name|m_updateRequested
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
comment|// QEGLFSCURSOR_H
end_comment
end_unit
