begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOW_P_H
end_ifndef
begin_define
DECL|macro|QWINDOW_P_H
define|#
directive|define
name|QWINDOW_P_H
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
file|<QtGui/qwindow.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QIcon>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|macro|QWINDOWSIZE_MAX
define|#
directive|define
name|QWINDOWSIZE_MAX
value|((1<<24)-1)
name|class
name|Q_GUI_EXPORT
name|QWindowPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QWindow
argument_list|)
name|public
operator|:
expr|enum
name|PositionPolicy
block|{
name|WindowFrameInclusive
block|,
name|WindowFrameExclusive
block|}
block|;
name|QWindowPrivate
argument_list|()
operator|:
name|QObjectPrivate
argument_list|()
block|,
name|surfaceType
argument_list|(
name|QWindow
operator|::
name|RasterSurface
argument_list|)
block|,
name|windowFlags
argument_list|(
name|Qt
operator|::
name|Window
argument_list|)
block|,
name|parentWindow
argument_list|(
literal|0
argument_list|)
block|,
name|platformWindow
argument_list|(
literal|0
argument_list|)
block|,
name|visible
argument_list|(
name|false
argument_list|)
block|,
name|exposed
argument_list|(
name|false
argument_list|)
block|,
name|windowState
argument_list|(
name|Qt
operator|::
name|WindowNoState
argument_list|)
block|,
name|visibility
argument_list|(
name|QWindow
operator|::
name|Hidden
argument_list|)
block|,
name|resizeEventPending
argument_list|(
name|true
argument_list|)
block|,
name|receivedExpose
argument_list|(
name|false
argument_list|)
block|,
name|positionPolicy
argument_list|(
name|WindowFrameExclusive
argument_list|)
block|,
name|positionAutomatic
argument_list|(
name|true
argument_list|)
block|,
name|contentOrientation
argument_list|(
name|Qt
operator|::
name|PrimaryOrientation
argument_list|)
block|,
name|opacity
argument_list|(
name|qreal
argument_list|(
literal|1.0
argument_list|)
argument_list|)
block|,
name|minimumSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|maximumSize
argument_list|(
name|QWINDOWSIZE_MAX
argument_list|,
name|QWINDOWSIZE_MAX
argument_list|)
block|,
name|modality
argument_list|(
name|Qt
operator|::
name|NonModal
argument_list|)
block|,
name|blockedByModalWindow
argument_list|(
name|false
argument_list|)
block|,
name|transientParent
argument_list|(
literal|0
argument_list|)
block|,
name|topLevelScreen
argument_list|(
literal|0
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
block|,
name|cursor
argument_list|(
name|Qt
operator|::
name|ArrowCursor
argument_list|)
block|,
name|hasCursor
argument_list|(
argument|false
argument_list|)
endif|#
directive|endif
block|{
name|isWindow
operator|=
name|true
block|;     }
operator|~
name|QWindowPrivate
argument_list|()
block|{     }
name|void
name|init
argument_list|()
block|;
name|void
name|maybeQuitOnLastWindowClosed
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|void
name|setCursor
argument_list|(
specifier|const
name|QCursor
operator|*
name|c
operator|=
literal|0
argument_list|)
block|;
name|void
name|applyCursor
argument_list|()
block|;
endif|#
directive|endif
name|QPoint
name|globalPosition
argument_list|()
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QWindow
argument_list|)
block|;
name|QPoint
name|offset
operator|=
name|q
operator|->
name|position
argument_list|()
block|;
for|for
control|(
specifier|const
name|QWindow
modifier|*
name|p
init|=
name|q
operator|->
name|parent
argument_list|()
init|;
name|p
condition|;
name|p
operator|=
name|p
operator|->
name|parent
argument_list|()
control|)
name|offset
operator|+=
name|p
operator|->
name|position
argument_list|()
expr_stmt|;
return|return
name|offset
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|QWindow
operator|*
name|topLevelWindow
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function
name|virtual
name|QWindow
modifier|*
name|eventReceiver
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QWindow
argument_list|)
expr_stmt|;
return|return
name|q
return|;
block|}
end_function
begin_function_decl
name|void
name|updateVisibility
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_clearAlert
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|bool
name|windowRecreationRequired
argument_list|(
name|QScreen
operator|*
name|newScreen
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setTopLevelScreen
parameter_list|(
name|QScreen
modifier|*
name|newScreen
parameter_list|,
name|bool
name|recreate
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|connectToScreen
parameter_list|(
name|QScreen
modifier|*
name|topLevelScreen
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|disconnectFromScreen
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|emitScreenChangedRecursion
parameter_list|(
name|QScreen
modifier|*
name|newScreen
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|clearFocusObject
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|QWindow
operator|::
name|SurfaceType
name|surfaceType
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Qt
operator|::
name|WindowFlags
name|windowFlags
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QWindow
modifier|*
name|parentWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPlatformWindow
modifier|*
name|platformWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|visible
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|exposed
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSurfaceFormat
name|requestedFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|windowTitle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|windowFilePath
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QIcon
name|windowIcon
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|geometry
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|WindowState
name|windowState
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QWindow
operator|::
name|Visibility
name|visibility
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|resizeEventPending
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|receivedExpose
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|PositionPolicy
name|positionPolicy
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|positionAutomatic
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|ScreenOrientation
name|contentOrientation
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|qreal
name|opacity
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRegion
name|mask
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSize
name|minimumSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSize
name|maximumSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSize
name|baseSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSize
name|sizeIncrement
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|WindowModality
name|modality
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|blockedByModalWindow
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QPointer
operator|<
name|QWindow
operator|>
name|transientParent
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QScreen
modifier|*
name|topLevelScreen
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
end_ifndef
begin_decl_stmt
name|QCursor
name|cursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|hasCursor
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOW_P_H
end_comment
end_unit
