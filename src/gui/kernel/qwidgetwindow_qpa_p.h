begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWIDGETWINDOW_QPA_P_H
end_ifndef
begin_define
DECL|macro|QWIDGETWINDOW_QPA_P_H
define|#
directive|define
name|QWIDGETWINDOW_QPA_P_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qobject_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QWidgetWindow
range|:
name|public
name|QWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|QWidgetWindow
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QWidget
operator|*
name|widget
argument_list|()
specifier|const
block|{
return|return
name|m_widget
return|;
block|}
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|handleCloseEvent
argument_list|(
name|QCloseEvent
operator|*
argument_list|)
block|;
name|void
name|handleEnterLeaveEvent
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|handleKeyEvent
argument_list|(
name|QKeyEvent
operator|*
argument_list|)
block|;
name|void
name|handleMouseEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|void
name|handleMoveEvent
argument_list|(
name|QMoveEvent
operator|*
argument_list|)
block|;
name|void
name|handleResizeEvent
argument_list|(
name|QResizeEvent
operator|*
argument_list|)
block|;
name|void
name|handleWheelEvent
argument_list|(
name|QWheelEvent
operator|*
argument_list|)
block|;
name|private
operator|:
name|QWidget
operator|*
name|m_widget
block|;
name|QWeakPointer
operator|<
name|QWidget
operator|>
name|m_implicit_mouse_grabber
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWIDGETWINDOW_QPA_P_H
end_comment
end_unit
