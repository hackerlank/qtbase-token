begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSYSTEMTRAYICON_H
end_ifndef
begin_define
DECL|macro|QSYSTEMTRAYICON_H
define|#
directive|define
name|QSYSTEMTRAYICON_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
end_ifndef
begin_include
include|#
directive|include
file|<QtGui/qicon.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QSystemTrayIconPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMenu
name|class
name|QMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEvent
name|class
name|QEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWheelEvent
name|class
name|QWheelEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMouseEvent
name|class
name|QMouseEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPoint
name|class
name|QPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QSystemTrayIcon
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QString toolTip READ toolTip WRITE setToolTip
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QIcon icon READ icon WRITE setIcon
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool visible READ isVisible WRITE setVisible DESIGNABLE false
argument_list|)
name|public
operator|:
name|QSystemTrayIcon
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QSystemTrayIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QSystemTrayIcon
argument_list|()
block|;      enum
name|ActivationReason
block|{
name|Unknown
block|,
name|Context
block|,
name|DoubleClick
block|,
name|Trigger
block|,
name|MiddleClick
block|}
block|;
ifndef|#
directive|ifndef
name|QT_NO_MENU
name|void
name|setContextMenu
argument_list|(
name|QMenu
operator|*
name|menu
argument_list|)
block|;
name|QMenu
operator|*
name|contextMenu
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|QIcon
name|icon
argument_list|()
specifier|const
block|;
name|void
name|setIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|)
block|;
name|QString
name|toolTip
argument_list|()
specifier|const
block|;
name|void
name|setToolTip
argument_list|(
specifier|const
name|QString
operator|&
name|tip
argument_list|)
block|;
specifier|static
name|bool
name|isSystemTrayAvailable
argument_list|()
block|;
specifier|static
name|bool
name|supportsMessages
argument_list|()
block|;      enum
name|MessageIcon
block|{
name|NoIcon
block|,
name|Information
block|,
name|Warning
block|,
name|Critical
block|}
block|;
name|void
name|showMessage
argument_list|(
argument|const QString&title
argument_list|,
argument|const QString&msg
argument_list|,
argument|MessageIcon icon = Information
argument_list|,
argument|int msecs =
literal|10000
argument_list|)
block|;
name|QRect
name|geometry
argument_list|()
specifier|const
block|;
name|bool
name|isVisible
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
specifier|inline
name|void
name|show
argument_list|()
block|{
name|setVisible
argument_list|(
name|true
argument_list|)
block|; }
specifier|inline
name|void
name|hide
argument_list|()
block|{
name|setVisible
argument_list|(
name|false
argument_list|)
block|; }
name|Q_SIGNALS
operator|:
name|void
name|activated
argument_list|(
argument|QSystemTrayIcon::ActivationReason reason
argument_list|)
block|;
name|void
name|messageClicked
argument_list|()
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QSystemTrayIcon
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSystemTrayIcon
argument_list|)
name|friend
name|class
name|QSystemTrayIconSys
block|;
name|friend
name|class
name|QBalloonTip
block|;
name|friend
name|void
name|qtsystray_sendActivated
argument_list|(
name|QSystemTrayIcon
operator|*
argument_list|,
name|int
argument_list|)
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
comment|// QT_NO_SYSTEMTRAYICON
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSYSTEMTRAYICON_H
end_comment
end_unit
