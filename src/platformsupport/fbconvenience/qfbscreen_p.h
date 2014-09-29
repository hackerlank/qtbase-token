begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFBSCREEN_P_H
end_ifndef
begin_define
DECL|macro|QFBSCREEN_P_H
define|#
directive|define
name|QFBSCREEN_P_H
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
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTimer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSize>
end_include
begin_include
include|#
directive|include
file|"qfbcursor_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFbWindow
name|class
name|QFbWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFbCursor
name|class
name|QFbCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPainter
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFbBackingStore
name|class
name|QFbBackingStore
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QFbScreen
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QPlatformScreen
block|{
name|Q_OBJECT
name|public
range|:
name|QFbScreen
argument_list|()
decl_stmt|;
operator|~
name|QFbScreen
argument_list|()
expr_stmt|;
name|QRect
name|geometry
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|mGeometry
return|;
block|}
name|int
name|depth
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|mDepth
return|;
block|}
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|mFormat
return|;
block|}
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|mPhysicalSize
return|;
block|}
name|QPlatformCursor
operator|*
name|cursor
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|mCursor
return|;
block|}
name|QWindow
operator|*
name|topWindow
argument_list|()
specifier|const
expr_stmt|;
name|QWindow
modifier|*
name|topLevelAt
argument_list|(
specifier|const
name|QPoint
operator|&
name|p
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
comment|// compositor api
name|virtual
name|void
name|addWindow
parameter_list|(
name|QFbWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|virtual
name|void
name|removeWindow
parameter_list|(
name|QFbWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|virtual
name|void
name|raise
parameter_list|(
name|QFbWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|virtual
name|void
name|lower
parameter_list|(
name|QFbWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|virtual
name|void
name|topWindowChanged
parameter_list|(
name|QWindow
modifier|*
parameter_list|)
block|{}
name|void
name|addBackingStore
parameter_list|(
name|QFbBackingStore
modifier|*
name|bs
parameter_list|)
block|{
name|mBackingStores
operator|<<
name|bs
expr_stmt|;
block|}
name|void
name|scheduleUpdate
parameter_list|()
function_decl|;
name|public
name|slots
range|:
name|virtual
name|void
name|setDirty
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
decl_stmt|;
name|void
name|setPhysicalSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
function_decl|;
name|void
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
name|protected
name|slots
range|:
name|virtual
name|QRegion
name|doRedraw
argument_list|()
decl_stmt|;
name|protected
label|:
name|void
name|initializeCompositor
parameter_list|()
function_decl|;
name|QList
operator|<
name|QFbWindow
operator|*
operator|>
name|mWindowStack
expr_stmt|;
name|QRegion
name|mRepaintRegion
decl_stmt|;
name|QTimer
name|mRedrawTimer
decl_stmt|;
name|QFbCursor
modifier|*
name|mCursor
decl_stmt|;
name|QRect
name|mGeometry
decl_stmt|;
name|int
name|mDepth
decl_stmt|;
name|QImage
operator|::
name|Format
name|mFormat
expr_stmt|;
name|QSizeF
name|mPhysicalSize
decl_stmt|;
name|QImage
modifier|*
name|mScreenImage
decl_stmt|;
name|private
label|:
name|void
name|invalidateRectCache
parameter_list|()
block|{
name|mIsUpToDate
operator|=
name|false
expr_stmt|;
block|}
name|void
name|generateRects
parameter_list|()
function_decl|;
name|QPainter
modifier|*
name|mCompositePainter
decl_stmt|;
name|QVector
operator|<
name|QPair
operator|<
name|QRect
operator|,
name|int
operator|>
expr|>
name|mCachedRects
expr_stmt|;
name|QList
operator|<
name|QFbBackingStore
operator|*
operator|>
name|mBackingStores
expr_stmt|;
name|friend
name|class
name|QFbWindow
decl_stmt|;
name|bool
name|mIsUpToDate
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
comment|// QFBSCREEN_P_H
end_comment
end_unit
