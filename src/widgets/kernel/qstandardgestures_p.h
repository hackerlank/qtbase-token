begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTANDARDGESTURES_P_H
end_ifndef
begin_define
DECL|macro|QSTANDARDGESTURES_P_H
define|#
directive|define
name|QSTANDARDGESTURES_P_H
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
begin_include
include|#
directive|include
file|"qgesturerecognizer.h"
end_include
begin_include
include|#
directive|include
file|"private/qgesture_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QPanGestureRecognizer
range|:
name|public
name|QGestureRecognizer
block|{
name|public
operator|:
name|QPanGestureRecognizer
argument_list|()
block|;
name|QGesture
operator|*
name|create
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
name|QGestureRecognizer
operator|::
name|Result
name|recognize
argument_list|(
name|QGesture
operator|*
name|state
argument_list|,
name|QObject
operator|*
name|watched
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|reset
argument_list|(
name|QGesture
operator|*
name|state
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QPinchGestureRecognizer
range|:
name|public
name|QGestureRecognizer
block|{
name|public
operator|:
name|QPinchGestureRecognizer
argument_list|()
block|;
name|QGesture
operator|*
name|create
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
name|QGestureRecognizer
operator|::
name|Result
name|recognize
argument_list|(
name|QGesture
operator|*
name|state
argument_list|,
name|QObject
operator|*
name|watched
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|reset
argument_list|(
name|QGesture
operator|*
name|state
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QSwipeGestureRecognizer
range|:
name|public
name|QGestureRecognizer
block|{
name|public
operator|:
name|QSwipeGestureRecognizer
argument_list|()
block|;
name|QGesture
operator|*
name|create
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
name|QGestureRecognizer
operator|::
name|Result
name|recognize
argument_list|(
name|QGesture
operator|*
name|state
argument_list|,
name|QObject
operator|*
name|watched
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|reset
argument_list|(
name|QGesture
operator|*
name|state
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTapGestureRecognizer
range|:
name|public
name|QGestureRecognizer
block|{
name|public
operator|:
name|QTapGestureRecognizer
argument_list|()
block|;
name|QGesture
operator|*
name|create
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
name|QGestureRecognizer
operator|::
name|Result
name|recognize
argument_list|(
name|QGesture
operator|*
name|state
argument_list|,
name|QObject
operator|*
name|watched
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|reset
argument_list|(
name|QGesture
operator|*
name|state
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTapAndHoldGestureRecognizer
range|:
name|public
name|QGestureRecognizer
block|{
name|public
operator|:
name|QTapAndHoldGestureRecognizer
argument_list|()
block|;
name|QGesture
operator|*
name|create
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
name|QGestureRecognizer
operator|::
name|Result
name|recognize
argument_list|(
name|QGesture
operator|*
name|state
argument_list|,
name|QObject
operator|*
name|watched
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|reset
argument_list|(
name|QGesture
operator|*
name|state
argument_list|)
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
comment|// QT_NO_GESTURES
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTANDARDGESTURES_P_H
end_comment
end_unit
