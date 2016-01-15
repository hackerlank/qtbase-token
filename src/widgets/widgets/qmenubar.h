begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMENUBAR_H
end_ifndef
begin_define
DECL|macro|QMENUBAR_H
define|#
directive|define
name|QMENUBAR_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qmenu.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_MENUBAR
DECL|variable|QMenuBarPrivate
name|class
name|QMenuBarPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionMenuItem
name|class
name|QStyleOptionMenuItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindowsStyle
name|class
name|QWindowsStyle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformMenuBar
name|class
name|QPlatformMenuBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QMenuBar
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool defaultUp READ isDefaultUp WRITE setDefaultUp
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool nativeMenuBar READ isNativeMenuBar WRITE setNativeMenuBar
argument_list|)
name|public
operator|:
name|explicit
name|QMenuBar
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QMenuBar
argument_list|()
block|;
name|using
name|QWidget
operator|::
name|addAction
block|;
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
name|insertSeparator
argument_list|(
name|QAction
operator|*
name|before
argument_list|)
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
name|void
name|clear
argument_list|()
block|;
name|QAction
operator|*
name|activeAction
argument_list|()
specifier|const
block|;
name|void
name|setActiveAction
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|;
name|void
name|setDefaultUp
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|isDefaultUp
argument_list|()
specifier|const
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|QSize
name|minimumSizeHint
argument_list|()
specifier|const
block|;
name|int
name|heightForWidth
argument_list|(
argument|int
argument_list|)
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
name|void
name|setCornerWidget
argument_list|(
argument|QWidget *w
argument_list|,
argument|Qt::Corner corner = Qt::TopRightCorner
argument_list|)
block|;
name|QWidget
operator|*
name|cornerWidget
argument_list|(
argument|Qt::Corner corner = Qt::TopRightCorner
argument_list|)
specifier|const
block|;
ifdef|#
directive|ifdef
name|Q_OS_WINCE
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
specifier|static
name|void
name|wceCommands
argument_list|(
argument|uint command
argument_list|)
block|;
specifier|static
name|void
name|wceRefresh
argument_list|()
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_OSX
name|NSMenu
operator|*
name|toNSMenu
argument_list|()
block|;
endif|#
directive|endif
name|bool
name|isNativeMenuBar
argument_list|()
specifier|const
block|;
name|void
name|setNativeMenuBar
argument_list|(
argument|bool nativeMenuBar
argument_list|)
block|;
name|QPlatformMenuBar
operator|*
name|platformMenuBar
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
name|virtual
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|Q_SIGNALS
operator|:
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
name|void
name|leaveEvent
argument_list|(
name|QEvent
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
name|resizeEvent
argument_list|(
name|QResizeEvent
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
name|focusOutEvent
argument_list|(
name|QFocusEvent
operator|*
argument_list|)
block|;
name|void
name|focusInEvent
argument_list|(
name|QFocusEvent
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
name|eventFilter
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
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
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionMenuItem *option
argument_list|,
argument|const QAction *action
argument_list|)
specifier|const
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QMenuBar
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QMenuBar
argument_list|)
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
argument|void _q_internalShortcutActivated(int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateLayout()
argument_list|)
ifdef|#
directive|ifdef
name|Q_OS_WINCE
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateDefaultAction()
argument_list|)
endif|#
directive|endif
name|friend
name|class
name|QMenu
block|;
name|friend
name|class
name|QMenuPrivate
block|;
name|friend
name|class
name|QWindowsStyle
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MENUBAR
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMENUBAR_H
end_comment
end_unit
