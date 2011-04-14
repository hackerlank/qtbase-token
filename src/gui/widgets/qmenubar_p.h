begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMENUBAR_P_H
end_ifndef
begin_define
DECL|macro|QMENUBAR_P_H
define|#
directive|define
name|QMENUBAR_P_H
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
begin_ifndef
ifndef|#
directive|ifndef
name|QMAC_Q3MENUBAR_CPP_FILE
end_ifndef
begin_include
include|#
directive|include
file|"QtGui/qstyleoption.h"
end_include
begin_include
include|#
directive|include
file|<private/qmenu_p.h>
end_include
begin_comment
comment|// Mac needs what in this file!
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WINCE
end_ifdef
begin_include
include|#
directive|include
file|"qguifunctions_wince.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_MENUBAR
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_S60
end_ifdef
begin_decl_stmt
DECL|variable|CCoeControl
name|class
name|CCoeControl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|CEikMenuBar
name|class
name|CEikMenuBar
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_MENUBAR
DECL|variable|QMenuBarExtension
name|class
name|QMenuBarExtension
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QMenuBarPrivate
range|:
name|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QMenuBar
argument_list|)
name|public
operator|:
name|QMenuBarPrivate
argument_list|()
operator|:
name|itemsDirty
argument_list|(
literal|0
argument_list|)
block|,
name|currentAction
argument_list|(
literal|0
argument_list|)
block|,
name|mouseDown
argument_list|(
literal|0
argument_list|)
block|,
name|closePopupMode
argument_list|(
literal|0
argument_list|)
block|,
name|defaultPopDown
argument_list|(
literal|1
argument_list|)
block|,
name|popupState
argument_list|(
literal|0
argument_list|)
block|,
name|keyboardState
argument_list|(
literal|0
argument_list|)
block|,
name|altPressed
argument_list|(
literal|0
argument_list|)
block|,
name|nativeMenuBar
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|doChildEffects
argument_list|(
name|false
argument_list|)
ifdef|#
directive|ifdef
name|QT3_SUPPORT
block|,
name|doAutoResize
argument_list|(
name|false
argument_list|)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_WS_MAC
block|,
name|mac_menubar
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_WS_WINCE
block|,
name|wce_menubar
argument_list|(
literal|0
argument_list|)
block|,
name|wceClassicMenu
argument_list|(
name|false
argument_list|)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_WS_S60
block|,
name|symbian_menubar
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
block|{ }
operator|~
name|QMenuBarPrivate
argument_list|()
block|{
ifdef|#
directive|ifdef
name|Q_WS_MAC
name|delete
name|mac_menubar
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_WS_WINCE
name|delete
name|wce_menubar
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_WS_S60
name|delete
name|symbian_menubar
block|;
endif|#
directive|endif
block|}
name|void
name|init
argument_list|()
block|;
name|QAction
operator|*
name|getNextAction
argument_list|(
argument|const int start
argument_list|,
argument|const int increment
argument_list|)
specifier|const
block|;
comment|//item calculations
name|uint
name|itemsDirty
operator|:
literal|1
block|;
name|QVector
operator|<
name|int
operator|>
name|shortcutIndexMap
block|;
name|mutable
name|QVector
operator|<
name|QRect
operator|>
name|actionRects
block|;
name|void
name|calcActionRects
argument_list|(
argument|int max_width
argument_list|,
argument|int start
argument_list|)
specifier|const
block|;
name|QRect
name|actionRect
argument_list|(
argument|QAction *
argument_list|)
specifier|const
block|;
name|void
name|updateGeometries
argument_list|()
block|;
comment|//selection
name|QPointer
operator|<
name|QAction
operator|>
name|currentAction
block|;
name|uint
name|mouseDown
operator|:
literal|1
block|,
name|closePopupMode
operator|:
literal|1
block|,
name|defaultPopDown
block|;
name|QAction
operator|*
name|actionAt
argument_list|(
argument|QPoint p
argument_list|)
specifier|const
block|;
name|void
name|setCurrentAction
argument_list|(
name|QAction
operator|*
argument_list|,
name|bool
operator|=
name|false
argument_list|,
name|bool
operator|=
name|false
argument_list|)
block|;
name|void
name|popupAction
argument_list|(
name|QAction
operator|*
argument_list|,
name|bool
argument_list|)
block|;
comment|//active popup state
name|uint
name|popupState
operator|:
literal|1
block|;
name|QPointer
operator|<
name|QMenu
operator|>
name|activeMenu
block|;
comment|//keyboard mode for keyboard navigation
name|void
name|focusFirstAction
argument_list|()
block|;
name|void
name|setKeyboardMode
argument_list|(
name|bool
argument_list|)
block|;
name|uint
name|keyboardState
operator|:
literal|1
block|,
name|altPressed
operator|:
literal|1
block|;
name|QPointer
operator|<
name|QWidget
operator|>
name|keyboardFocusWidget
block|;
name|int
name|nativeMenuBar
operator|:
literal|3
block|;
comment|// Only has values -1, 0, and 1
comment|//firing of events
name|void
name|activateAction
argument_list|(
name|QAction
operator|*
argument_list|,
name|QAction
operator|::
name|ActionEvent
argument_list|)
block|;
name|void
name|_q_actionTriggered
argument_list|()
block|;
name|void
name|_q_actionHovered
argument_list|()
block|;
name|void
name|_q_internalShortcutActivated
argument_list|(
name|int
argument_list|)
block|;
name|void
name|_q_updateLayout
argument_list|()
block|;
ifdef|#
directive|ifdef
name|Q_WS_WINCE
name|void
name|_q_updateDefaultAction
argument_list|()
block|;
endif|#
directive|endif
comment|//extra widgets in the menubar
name|QPointer
operator|<
name|QWidget
operator|>
name|leftWidget
block|,
name|rightWidget
block|;
name|QMenuBarExtension
operator|*
name|extension
block|;
name|bool
name|isVisible
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|;
comment|//menu fading/scrolling effects
name|bool
name|doChildEffects
block|;
name|QRect
name|menuRect
argument_list|(
argument|bool
argument_list|)
specifier|const
block|;
comment|// reparenting
name|void
name|handleReparent
argument_list|()
block|;
name|QWidget
operator|*
name|oldParent
block|;
name|QWidget
operator|*
name|oldWindow
block|;
name|QList
operator|<
name|QAction
operator|*
operator|>
name|hiddenActions
block|;
comment|//default action
name|QPointer
operator|<
name|QAction
operator|>
name|defaultAction
block|;
name|QBasicTimer
name|autoReleaseTimer
block|;
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|bool
name|doAutoResize
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_WS_MAC
comment|//mac menubar binding
block|struct
name|QMacMenuBarPrivate
block|{
name|QList
operator|<
name|QMacMenuAction
operator|*
operator|>
name|actionItems
block|;
name|OSMenuRef
name|menu
block|,
name|apple_menu
block|;
name|QMacMenuBarPrivate
argument_list|()
block|;
operator|~
name|QMacMenuBarPrivate
argument_list|()
block|;
name|void
name|addAction
argument_list|(
name|QAction
operator|*
argument_list|,
name|QAction
operator|*
operator|=
literal|0
argument_list|)
block|;
name|void
name|addAction
argument_list|(
name|QMacMenuAction
operator|*
argument_list|,
name|QMacMenuAction
operator|*
operator|=
literal|0
argument_list|)
block|;
name|void
name|syncAction
argument_list|(
name|QMacMenuAction
operator|*
argument_list|)
block|;
specifier|inline
name|void
name|syncAction
argument_list|(
argument|QAction *a
argument_list|)
block|{
name|syncAction
argument_list|(
name|findAction
argument_list|(
name|a
argument_list|)
argument_list|)
block|; }
name|void
name|removeAction
argument_list|(
name|QMacMenuAction
operator|*
argument_list|)
block|;
specifier|inline
name|void
name|removeAction
argument_list|(
argument|QAction *a
argument_list|)
block|{
name|removeAction
argument_list|(
name|findAction
argument_list|(
name|a
argument_list|)
argument_list|)
block|; }
specifier|inline
name|QMacMenuAction
operator|*
name|findAction
argument_list|(
argument|QAction *a
argument_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|actionItems
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QMacMenuAction
modifier|*
name|act
init|=
name|actionItems
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|a
operator|==
name|act
operator|->
name|action
condition|)
return|return
name|act
return|;
block|}
return|return
literal|0
return|;
block|}
expr|}
operator|*
name|mac_menubar
block|;
specifier|static
name|bool
name|macUpdateMenuBarImmediatly
argument_list|()
block|;
name|bool
name|macWidgetHasNativeMenubar
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|macCreateMenuBar
argument_list|(
name|QWidget
operator|*
argument_list|)
block|;
name|void
name|macDestroyMenuBar
argument_list|()
block|;
name|OSMenuRef
name|macMenu
argument_list|()
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_WS_WINCE
name|void
name|wceCreateMenuBar
argument_list|(
name|QWidget
operator|*
argument_list|)
block|;
name|void
name|wceDestroyMenuBar
argument_list|()
block|;     struct
name|QWceMenuBarPrivate
block|{
name|QList
operator|<
name|QWceMenuAction
operator|*
operator|>
name|actionItems
block|;
name|QList
operator|<
name|QWceMenuAction
operator|*
operator|>
name|actionItemsLeftButton
block|;
name|QList
operator|<
name|QList
operator|<
name|QWceMenuAction
operator|*
operator|>>
name|actionItemsClassic
block|;
name|HMENU
name|menuHandle
block|;
name|HMENU
name|leftButtonMenuHandle
block|;
name|HWND
name|menubarHandle
block|;
name|HWND
name|parentWindowHandle
block|;
name|bool
name|leftButtonIsMenu
block|;
name|QPointer
operator|<
name|QAction
operator|>
name|leftButtonAction
block|;
name|QMenuBarPrivate
operator|*
name|d
block|;
name|int
name|leftButtonCommand
block|;
name|QWceMenuBarPrivate
argument_list|(
name|QMenuBarPrivate
operator|*
name|menubar
argument_list|)
block|;
operator|~
name|QWceMenuBarPrivate
argument_list|()
block|;
name|void
name|addAction
argument_list|(
name|QAction
operator|*
argument_list|,
name|QAction
operator|*
operator|=
literal|0
argument_list|)
block|;
name|void
name|addAction
argument_list|(
name|QWceMenuAction
operator|*
argument_list|,
name|QWceMenuAction
operator|*
operator|=
literal|0
argument_list|)
block|;
name|void
name|syncAction
argument_list|(
name|QWceMenuAction
operator|*
argument_list|)
block|;
specifier|inline
name|void
name|syncAction
argument_list|(
argument|QAction *a
argument_list|)
block|{
name|syncAction
argument_list|(
name|findAction
argument_list|(
name|a
argument_list|)
argument_list|)
block|; }
name|void
name|removeAction
argument_list|(
name|QWceMenuAction
operator|*
argument_list|)
block|;
name|void
name|rebuild
argument_list|()
block|;
specifier|inline
name|void
name|removeAction
argument_list|(
argument|QAction *a
argument_list|)
block|{
name|removeAction
argument_list|(
name|findAction
argument_list|(
name|a
argument_list|)
argument_list|)
block|; }
specifier|inline
name|QWceMenuAction
operator|*
name|findAction
argument_list|(
argument|QAction *a
argument_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|actionItems
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QWceMenuAction
modifier|*
name|act
init|=
name|actionItems
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|a
operator|==
name|act
operator|->
name|action
condition|)
return|return
name|act
return|;
block|}
return|return
literal|0
return|;
block|}
expr|}
operator|*
name|wce_menubar
block|;
name|bool
name|wceClassicMenu
block|;
name|void
name|wceCommands
argument_list|(
argument|uint command
argument_list|)
block|;
name|void
name|wceRefresh
argument_list|()
block|;
name|bool
name|wceEmitSignals
argument_list|(
argument|QList<QWceMenuAction*> actions
argument_list|,
argument|uint command
argument_list|)
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_WS_S60
name|void
name|symbianCreateMenuBar
argument_list|(
name|QWidget
operator|*
argument_list|)
block|;
name|void
name|symbianDestroyMenuBar
argument_list|()
block|;
name|void
name|reparentMenuBar
argument_list|(
name|QWidget
operator|*
name|oldParent
argument_list|,
name|QWidget
operator|*
name|newParent
argument_list|)
block|;     struct
name|QSymbianMenuBarPrivate
block|{
name|QList
operator|<
name|QSymbianMenuAction
operator|*
operator|>
name|actionItems
block|;
name|QMenuBarPrivate
operator|*
name|d
block|;
name|QSymbianMenuBarPrivate
argument_list|(
name|QMenuBarPrivate
operator|*
name|menubar
argument_list|)
block|;
operator|~
name|QSymbianMenuBarPrivate
argument_list|()
block|;
name|void
name|addAction
argument_list|(
name|QAction
operator|*
argument_list|,
name|QAction
operator|*
operator|=
literal|0
argument_list|)
block|;
name|void
name|addAction
argument_list|(
name|QSymbianMenuAction
operator|*
argument_list|,
name|QSymbianMenuAction
operator|*
operator|=
literal|0
argument_list|)
block|;
name|void
name|syncAction
argument_list|(
name|QSymbianMenuAction
operator|*
argument_list|)
block|;
specifier|inline
name|void
name|syncAction
argument_list|(
argument|QAction *a
argument_list|)
block|{
name|syncAction
argument_list|(
name|findAction
argument_list|(
name|a
argument_list|)
argument_list|)
block|; }
name|void
name|removeAction
argument_list|(
name|QSymbianMenuAction
operator|*
argument_list|)
block|;
name|void
name|rebuild
argument_list|()
block|;
specifier|inline
name|void
name|removeAction
argument_list|(
argument|QAction *a
argument_list|)
block|{
name|removeAction
argument_list|(
name|findAction
argument_list|(
name|a
argument_list|)
argument_list|)
block|; }
specifier|inline
name|QSymbianMenuAction
operator|*
name|findAction
argument_list|(
argument|QAction *a
argument_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|actionItems
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QSymbianMenuAction
modifier|*
name|act
init|=
name|actionItems
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|a
operator|==
name|act
operator|->
name|action
condition|)
return|return
name|act
return|;
block|}
return|return
literal|0
return|;
block|}
name|void
name|insertNativeMenuItems
argument_list|(
specifier|const
name|QList
operator|<
name|QAction
operator|*
operator|>
operator|&
name|actions
argument_list|)
block|;      }
operator|*
name|symbian_menubar
block|;
specifier|static
name|int
name|symbianCommands
argument_list|(
argument|int command
argument_list|)
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_SOFTKEYS_ENABLED
name|QAction
operator|*
name|menuBarAction
block|;
endif|#
directive|endif
block|}
block|;
endif|#
directive|endif
endif|#
directive|endif
comment|// QT_NO_MENUBAR
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMENUBAR_P_H
end_comment
end_unit
