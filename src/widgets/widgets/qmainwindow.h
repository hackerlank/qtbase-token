begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDYNAMICMAINWINDOW_H
end_ifndef
begin_define
DECL|macro|QDYNAMICMAINWINDOW_H
define|#
directive|define
name|QDYNAMICMAINWINDOW_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qtabwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_MAINWINDOW
DECL|variable|QDockWidget
name|class
name|QDockWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMainWindowPrivate
name|class
name|QMainWindowPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMenuBar
name|class
name|QMenuBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStatusBar
name|class
name|QStatusBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QToolBar
name|class
name|QToolBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMenu
name|class
name|QMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QMainWindow
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|DockOption
argument_list|)
name|Q_FLAGS
argument_list|(
argument|DockOptions
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QSize iconSize READ iconSize WRITE setIconSize
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::ToolButtonStyle toolButtonStyle READ toolButtonStyle WRITE setToolButtonStyle
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_DOCKWIDGET
name|Q_PROPERTY
argument_list|(
argument|bool animated READ isAnimated WRITE setAnimated
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
name|Q_PROPERTY
argument_list|(
argument|bool documentMode READ documentMode WRITE setDocumentMode
argument_list|)
endif|#
directive|endif
comment|// QT_NO_TABBAR
ifndef|#
directive|ifndef
name|QT_NO_TABWIDGET
name|Q_PROPERTY
argument_list|(
argument|QTabWidget::TabShape tabShape READ tabShape WRITE setTabShape
argument_list|)
endif|#
directive|endif
comment|// QT_NO_TABWIDGET
name|Q_PROPERTY
argument_list|(
argument|bool dockNestingEnabled READ isDockNestingEnabled WRITE setDockNestingEnabled
argument_list|)
endif|#
directive|endif
comment|// QT_NO_DOCKWIDGET
name|Q_PROPERTY
argument_list|(
argument|DockOptions dockOptions READ dockOptions WRITE setDockOptions
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_TOOLBAR
name|Q_PROPERTY
argument_list|(
argument|bool unifiedTitleAndToolBarOnMac READ unifiedTitleAndToolBarOnMac WRITE setUnifiedTitleAndToolBarOnMac
argument_list|)
endif|#
directive|endif
name|public
operator|:
expr|enum
name|DockOption
block|{
name|AnimatedDocks
operator|=
literal|0x01
block|,
name|AllowNestedDocks
operator|=
literal|0x02
block|,
name|AllowTabbedDocks
operator|=
literal|0x04
block|,
name|ForceTabbedDocks
operator|=
literal|0x08
block|,
comment|// implies AllowTabbedDocks, !AllowNestedDocks
name|VerticalTabs
operator|=
literal|0x10
comment|// implies AllowTabbedDocks
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|DockOptions
argument_list|,
argument|DockOption
argument_list|)
name|explicit
name|QMainWindow
argument_list|(
argument|QWidget *parent =
literal|0
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|)
block|;
operator|~
name|QMainWindow
argument_list|()
block|;
name|QSize
name|iconSize
argument_list|()
specifier|const
block|;
name|void
name|setIconSize
argument_list|(
specifier|const
name|QSize
operator|&
name|iconSize
argument_list|)
block|;
name|Qt
operator|::
name|ToolButtonStyle
name|toolButtonStyle
argument_list|()
specifier|const
block|;
name|void
name|setToolButtonStyle
argument_list|(
argument|Qt::ToolButtonStyle toolButtonStyle
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_DOCKWIDGET
name|bool
name|isAnimated
argument_list|()
specifier|const
block|;
name|bool
name|isDockNestingEnabled
argument_list|()
specifier|const
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
name|bool
name|documentMode
argument_list|()
specifier|const
block|;
name|void
name|setDocumentMode
argument_list|(
argument|bool enabled
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_TABWIDGET
name|QTabWidget
operator|::
name|TabShape
name|tabShape
argument_list|()
specifier|const
block|;
name|void
name|setTabShape
argument_list|(
argument|QTabWidget::TabShape tabShape
argument_list|)
block|;
name|QTabWidget
operator|::
name|TabPosition
name|tabPosition
argument_list|(
argument|Qt::DockWidgetArea area
argument_list|)
specifier|const
block|;
name|void
name|setTabPosition
argument_list|(
argument|Qt::DockWidgetAreas areas
argument_list|,
argument|QTabWidget::TabPosition tabPosition
argument_list|)
block|;
endif|#
directive|endif
comment|// QT_NO_TABWIDGET
name|void
name|setDockOptions
argument_list|(
argument|DockOptions options
argument_list|)
block|;
name|DockOptions
name|dockOptions
argument_list|()
specifier|const
block|;
name|bool
name|isSeparator
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_MENUBAR
name|QMenuBar
operator|*
name|menuBar
argument_list|()
specifier|const
block|;
name|void
name|setMenuBar
argument_list|(
name|QMenuBar
operator|*
name|menubar
argument_list|)
block|;
name|QWidget
operator|*
name|menuWidget
argument_list|()
specifier|const
block|;
name|void
name|setMenuWidget
argument_list|(
name|QWidget
operator|*
name|menubar
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STATUSBAR
name|QStatusBar
operator|*
name|statusBar
argument_list|()
specifier|const
block|;
name|void
name|setStatusBar
argument_list|(
name|QStatusBar
operator|*
name|statusbar
argument_list|)
block|;
endif|#
directive|endif
name|QWidget
operator|*
name|centralWidget
argument_list|()
specifier|const
block|;
name|void
name|setCentralWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QWidget
operator|*
name|takeCentralWidget
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_DOCKWIDGET
name|void
name|setCorner
argument_list|(
argument|Qt::Corner corner
argument_list|,
argument|Qt::DockWidgetArea area
argument_list|)
block|;
name|Qt
operator|::
name|DockWidgetArea
name|corner
argument_list|(
argument|Qt::Corner corner
argument_list|)
specifier|const
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_TOOLBAR
name|void
name|addToolBarBreak
argument_list|(
argument|Qt::ToolBarArea area = Qt::TopToolBarArea
argument_list|)
block|;
name|void
name|insertToolBarBreak
argument_list|(
name|QToolBar
operator|*
name|before
argument_list|)
block|;
name|void
name|addToolBar
argument_list|(
argument|Qt::ToolBarArea area
argument_list|,
argument|QToolBar *toolbar
argument_list|)
block|;
name|void
name|addToolBar
argument_list|(
name|QToolBar
operator|*
name|toolbar
argument_list|)
block|;
name|QToolBar
operator|*
name|addToolBar
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
name|void
name|insertToolBar
argument_list|(
name|QToolBar
operator|*
name|before
argument_list|,
name|QToolBar
operator|*
name|toolbar
argument_list|)
block|;
name|void
name|removeToolBar
argument_list|(
name|QToolBar
operator|*
name|toolbar
argument_list|)
block|;
name|void
name|removeToolBarBreak
argument_list|(
name|QToolBar
operator|*
name|before
argument_list|)
block|;
name|void
name|setUnifiedTitleAndToolBarOnMac
argument_list|(
argument|bool set
argument_list|)
block|;
name|bool
name|unifiedTitleAndToolBarOnMac
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|ToolBarArea
name|toolBarArea
argument_list|(
argument|QToolBar *toolbar
argument_list|)
specifier|const
block|;
name|bool
name|toolBarBreak
argument_list|(
argument|QToolBar *toolbar
argument_list|)
specifier|const
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DOCKWIDGET
name|void
name|addDockWidget
argument_list|(
argument|Qt::DockWidgetArea area
argument_list|,
argument|QDockWidget *dockwidget
argument_list|)
block|;
name|void
name|addDockWidget
argument_list|(
argument|Qt::DockWidgetArea area
argument_list|,
argument|QDockWidget *dockwidget
argument_list|,
argument|Qt::Orientation orientation
argument_list|)
block|;
name|void
name|splitDockWidget
argument_list|(
argument|QDockWidget *after
argument_list|,
argument|QDockWidget *dockwidget
argument_list|,
argument|Qt::Orientation orientation
argument_list|)
block|;
name|void
name|tabifyDockWidget
argument_list|(
name|QDockWidget
operator|*
name|first
argument_list|,
name|QDockWidget
operator|*
name|second
argument_list|)
block|;
name|QList
operator|<
name|QDockWidget
operator|*
operator|>
name|tabifiedDockWidgets
argument_list|(
argument|QDockWidget *dockwidget
argument_list|)
specifier|const
block|;
name|void
name|removeDockWidget
argument_list|(
name|QDockWidget
operator|*
name|dockwidget
argument_list|)
block|;
name|bool
name|restoreDockWidget
argument_list|(
name|QDockWidget
operator|*
name|dockwidget
argument_list|)
block|;
name|Qt
operator|::
name|DockWidgetArea
name|dockWidgetArea
argument_list|(
argument|QDockWidget *dockwidget
argument_list|)
specifier|const
block|;
endif|#
directive|endif
comment|// QT_NO_DOCKWIDGET
name|QByteArray
name|saveState
argument_list|(
argument|int version =
literal|0
argument_list|)
specifier|const
block|;
name|bool
name|restoreState
argument_list|(
argument|const QByteArray&state
argument_list|,
argument|int version =
literal|0
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_MENU
name|virtual
name|QMenu
operator|*
name|createPopupMenu
argument_list|()
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DOCKWIDGET
name|public
name|Q_SLOTS
operator|:
name|void
name|setAnimated
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|setDockNestingEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
endif|#
directive|endif
name|Q_SIGNALS
operator|:
name|void
name|iconSizeChanged
argument_list|(
specifier|const
name|QSize
operator|&
name|iconSize
argument_list|)
block|;
name|void
name|toolButtonStyleChanged
argument_list|(
argument|Qt::ToolButtonStyle toolButtonStyle
argument_list|)
block|;
name|protected
operator|:
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|void
name|contextMenuEvent
argument_list|(
name|QContextMenuEvent
operator|*
name|event
argument_list|)
block|;
endif|#
directive|endif
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
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QMainWindow
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QMainWindow
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QMainWindow::DockOptions
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MAINWINDOW
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDYNAMICMAINWINDOW_H
end_comment
end_unit
