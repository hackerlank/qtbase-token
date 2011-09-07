begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMENU_H
end_ifndef
begin_define
DECL|macro|QMENU_H
define|#
directive|define
name|QMENU_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qicon.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qaction.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qplatformmenu_qpa.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WINCE
end_ifdef
begin_include
include|#
directive|include
file|<windef.h>
end_include
begin_comment
comment|// for HMENU
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_MENU
name|class
name|QMenuPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionMenuItem
name|class
name|QStyleOptionMenuItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QMenu
range|:
name|public
name|QWidget
block|{
name|private
operator|:
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QMenu
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool tearOffEnabled READ isTearOffEnabled WRITE setTearOffEnabled
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString title READ title WRITE setTitle
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QIcon icon READ icon WRITE setIcon
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool separatorsCollapsible READ separatorsCollapsible WRITE setSeparatorsCollapsible
argument_list|)
name|public
operator|:
name|explicit
name|QMenu
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QMenu
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QMenu
argument_list|()
block|;
ifdef|#
directive|ifdef
name|Q_NO_USING_KEYWORD
specifier|inline
name|void
name|addAction
argument_list|(
argument|QAction *action
argument_list|)
block|{
name|QWidget
operator|::
name|addAction
argument_list|(
name|action
argument_list|)
block|; }
else|#
directive|else
name|using
name|QWidget
operator|::
name|addAction
block|;
endif|#
directive|endif
name|QAction
operator|*
name|addAction
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|QAction
operator|*
name|addAction
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|QAction
operator|*
name|addAction
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
specifier|const
name|QObject
operator|*
name|receiver
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|,
specifier|const
name|QKeySequence
operator|&
name|shortcut
operator|=
literal|0
argument_list|)
block|;
name|QAction
operator|*
name|addAction
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|,
specifier|const
name|QObject
operator|*
name|receiver
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|,
specifier|const
name|QKeySequence
operator|&
name|shortcut
operator|=
literal|0
argument_list|)
block|;
name|QAction
operator|*
name|addMenu
argument_list|(
name|QMenu
operator|*
name|menu
argument_list|)
block|;
name|QMenu
operator|*
name|addMenu
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
name|QMenu
operator|*
name|addMenu
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|,
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
name|QAction
operator|*
name|addSeparator
argument_list|()
block|;
name|QAction
operator|*
name|insertMenu
argument_list|(
name|QAction
operator|*
name|before
argument_list|,
name|QMenu
operator|*
name|menu
argument_list|)
block|;
name|QAction
operator|*
name|insertSeparator
argument_list|(
name|QAction
operator|*
name|before
argument_list|)
block|;
name|bool
name|isEmpty
argument_list|()
specifier|const
block|;
name|void
name|clear
argument_list|()
block|;
name|void
name|setTearOffEnabled
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|isTearOffEnabled
argument_list|()
specifier|const
block|;
name|bool
name|isTearOffMenuVisible
argument_list|()
specifier|const
block|;
name|void
name|hideTearOffMenu
argument_list|()
block|;
name|void
name|setDefaultAction
argument_list|(
name|QAction
operator|*
argument_list|)
block|;
name|QAction
operator|*
name|defaultAction
argument_list|()
specifier|const
block|;
name|void
name|setActiveAction
argument_list|(
name|QAction
operator|*
name|act
argument_list|)
block|;
name|QAction
operator|*
name|activeAction
argument_list|()
specifier|const
block|;
name|void
name|popup
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
name|QAction
operator|*
name|at
operator|=
literal|0
argument_list|)
block|;
name|QAction
operator|*
name|exec
argument_list|()
block|;
name|QAction
operator|*
name|exec
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
name|QAction
operator|*
name|at
operator|=
literal|0
argument_list|)
block|;
comment|// ### Qt 5: merge
specifier|static
name|QAction
operator|*
name|exec
argument_list|(
name|QList
operator|<
name|QAction
operator|*
operator|>
name|actions
argument_list|,
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
name|QAction
operator|*
name|at
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|QAction
operator|*
name|exec
argument_list|(
name|QList
operator|<
name|QAction
operator|*
operator|>
name|actions
argument_list|,
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
name|QAction
operator|*
name|at
argument_list|,
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|QRect
name|actionGeometry
argument_list|(
argument|QAction *
argument_list|)
specifier|const
block|;
name|QAction
operator|*
name|actionAt
argument_list|(
argument|const QPoint&
argument_list|)
specifier|const
block|;
name|QAction
operator|*
name|menuAction
argument_list|()
specifier|const
block|;
name|QString
name|title
argument_list|()
specifier|const
block|;
name|void
name|setTitle
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
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
name|void
name|setNoReplayFor
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QPlatformMenu
operator|*
name|platformMenu
argument_list|()
block|;
ifdef|#
directive|ifdef
name|Q_WS_WINCE
name|HMENU
name|wceMenu
argument_list|()
block|;
endif|#
directive|endif
name|bool
name|separatorsCollapsible
argument_list|()
specifier|const
block|;
name|void
name|setSeparatorsCollapsible
argument_list|(
argument|bool collapse
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|aboutToShow
argument_list|()
block|;
name|void
name|aboutToHide
argument_list|()
block|;
name|void
name|triggered
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|;
name|void
name|hovered
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|;
name|protected
operator|:
name|int
name|columnCount
argument_list|()
specifier|const
block|;
name|void
name|changeEvent
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|void
name|wheelEvent
argument_list|(
name|QWheelEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|void
name|enterEvent
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|leaveEvent
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|hideEvent
argument_list|(
name|QHideEvent
operator|*
argument_list|)
block|;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
argument_list|)
block|;
name|void
name|actionEvent
argument_list|(
name|QActionEvent
operator|*
argument_list|)
block|;
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|bool
name|focusNextPrevChild
argument_list|(
argument|bool next
argument_list|)
block|;
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionMenuItem *option
argument_list|,
argument|const QAction *action
argument_list|)
specifier|const
block|;
ifdef|#
directive|ifdef
name|Q_WS_WINCE
name|QAction
operator|*
name|wceCommands
argument_list|(
argument|uint command
argument_list|)
block|;
endif|#
directive|endif
name|private
name|Q_SLOTS
operator|:
name|void
name|internalSetSloppyAction
argument_list|()
block|;
name|void
name|internalDelayedPopup
argument_list|()
block|;
name|private
operator|:
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_actionTriggered()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_actionHovered()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_overrideMenuActionDestroyed()
argument_list|)
name|protected
operator|:
name|QMenu
argument_list|(
name|QMenuPrivate
operator|&
name|dd
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QMenu
argument_list|)
name|friend
name|class
name|QMenuBar
block|;
name|friend
name|class
name|QMenuBarPrivate
block|;
name|friend
name|class
name|QTornOffMenu
block|;
name|friend
name|class
name|Q3PopupMenu
block|;
name|friend
name|class
name|QComboBox
block|;
name|friend
name|class
name|QAction
block|;
name|friend
name|class
name|QToolButtonPrivate
block|;
name|friend
name|void
name|qt_mac_emit_menuSignals
argument_list|(
argument|QMenu *menu
argument_list|,
argument|bool show
argument_list|)
block|;
name|friend
name|void
name|qt_mac_menu_emit_hovered
argument_list|(
name|QMenu
operator|*
name|menu
argument_list|,
name|QAction
operator|*
name|action
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MENU
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMENU_H
end_comment
end_unit
