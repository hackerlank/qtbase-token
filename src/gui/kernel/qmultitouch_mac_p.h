begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
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
begin_ifndef
ifndef|#
directive|ifndef
name|QMULTITOUCH_MAC_P_H
end_ifndef
begin_define
DECL|macro|QMULTITOUCH_MAC_P_H
define|#
directive|define
name|QMULTITOUCH_MAC_P_H
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|QT_MAC_USE_COCOA
end_ifdef
begin_empty
empty|#import<Cocoa/Cocoa.h>
end_empty
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_if
if|#
directive|if
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|>=
name|MAC_OS_X_VERSION_10_6
end_if
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|QT_MAC_USE_COCOA
name|class
name|QCocoaTouch
block|{
name|public
label|:
specifier|static
name|QList
operator|<
name|QTouchEvent
operator|::
name|TouchPoint
operator|>
name|getCurrentTouchPointList
argument_list|(
argument|NSEvent *event
argument_list|,
argument|bool acceptSingleTouch
argument_list|)
expr_stmt|;
specifier|static
name|void
name|setMouseInDraggingState
parameter_list|(
name|bool
name|inDraggingState
parameter_list|)
function_decl|;
name|private
label|:
specifier|static
name|QHash
operator|<
name|qint64
operator|,
name|QCocoaTouch
operator|*
operator|>
name|_currentTouches
expr_stmt|;
specifier|static
name|QPointF
name|_screenReferencePos
decl_stmt|;
specifier|static
name|QPointF
name|_trackpadReferencePos
decl_stmt|;
specifier|static
name|int
name|_idAssignmentCount
decl_stmt|;
specifier|static
name|int
name|_touchCount
decl_stmt|;
specifier|static
name|bool
name|_updateInternalStateOnly
decl_stmt|;
name|QTouchEvent
operator|::
name|TouchPoint
name|_touchPoint
expr_stmt|;
name|qint64
name|_identity
decl_stmt|;
name|QCocoaTouch
argument_list|(
name|NSTouch
operator|*
name|nstouch
argument_list|)
expr_stmt|;
operator|~
name|QCocoaTouch
argument_list|()
expr_stmt|;
name|void
name|updateTouchData
parameter_list|(
name|NSTouch
modifier|*
name|nstouch
parameter_list|,
name|NSTouchPhase
name|phase
parameter_list|)
function_decl|;
specifier|static
name|QCocoaTouch
modifier|*
name|findQCocoaTouch
parameter_list|(
name|NSTouch
modifier|*
name|nstouch
parameter_list|)
function_decl|;
specifier|static
name|Qt
operator|::
name|TouchPointState
name|toTouchPointState
argument_list|(
argument|NSTouchPhase nsState
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_MAC_USE_COCOA
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// MAC_OS_X_VERSION_MAX_ALLOWED>= MAC_OS_X_VERSION_10_6
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMULTITOUCH_MAC_P_H
end_comment
end_unit
