begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMENU_P_H
end_ifndef
begin_define
DECL|macro|QMENU_P_H
define|#
directive|define
name|QMENU_P_H
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
file|"QtWidgets/qmenubar.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qstyleoption.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_MAC
end_ifdef
begin_include
include|#
directive|include
file|"QtWidgets/qmacdefines_mac.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"QtCore/qdatetime.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmap.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qhash.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qbasictimer.h"
end_include
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_S60
end_ifdef
begin_decl_stmt
DECL|variable|CEikMenuPane
name|class
name|CEikMenuPane
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|QT_SYMBIAN_FIRST_MENU_ITEM
define|#
directive|define
name|QT_SYMBIAN_FIRST_MENU_ITEM
value|32000
end_define
begin_define
DECL|macro|QT_SYMBIAN_LAST_MENU_ITEM
define|#
directive|define
name|QT_SYMBIAN_LAST_MENU_ITEM
value|41999
end_define
begin_comment
DECL|macro|QT_SYMBIAN_LAST_MENU_ITEM
comment|// 10000 items ought to be enough for anybody...
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_MENU
ifdef|#
directive|ifdef
name|Q_WS_S60
name|void
name|qt_symbian_next_menu_from_action
parameter_list|(
name|QWidget
modifier|*
name|actionContainer
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_symbian_show_toplevel
parameter_list|(
name|CEikMenuPane
modifier|*
name|menuPane
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_symbian_show_submenu
parameter_list|(
name|CEikMenuPane
modifier|*
name|menuPane
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_WS_S60
end_comment
begin_decl_stmt
DECL|variable|QTornOffMenu
name|class
name|QTornOffMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEventLoop
name|class
name|QEventLoop
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WINCE
end_ifdef
begin_struct
DECL|struct|QWceMenuAction
struct|struct
name|QWceMenuAction
block|{
DECL|member|command
name|uint
name|command
decl_stmt|;
DECL|member|action
name|QPointer
operator|<
name|QAction
operator|>
name|action
expr_stmt|;
DECL|member|menuHandle
name|HMENU
name|menuHandle
decl_stmt|;
DECL|function|QWceMenuAction
name|QWceMenuAction
argument_list|()
operator|:
name|menuHandle
argument_list|(
literal|0
argument_list|)
operator|,
name|command
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_S60
end_ifdef
begin_struct
DECL|struct|QSymbianMenuAction
struct|struct
name|QSymbianMenuAction
block|{
DECL|member|command
name|uint
name|command
decl_stmt|;
DECL|member|parent
name|int
name|parent
decl_stmt|;
DECL|member|menuPane
name|CEikMenuPane
modifier|*
name|menuPane
decl_stmt|;
DECL|member|action
name|QPointer
operator|<
name|QAction
operator|>
name|action
expr_stmt|;
DECL|function|QSymbianMenuAction
name|QSymbianMenuAction
argument_list|()
operator|:
name|command
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|QMenuPrivate
range|:
name|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QMenu
argument_list|)
name|public
operator|:
name|QMenuPrivate
argument_list|()
operator|:
name|itemsDirty
argument_list|(
literal|0
argument_list|)
block|,
name|maxIconWidth
argument_list|(
literal|0
argument_list|)
block|,
name|tabWidth
argument_list|(
literal|0
argument_list|)
block|,
name|ncols
argument_list|(
literal|0
argument_list|)
block|,
name|collapsibleSeparators
argument_list|(
name|true
argument_list|)
block|,
name|activationRecursionGuard
argument_list|(
name|false
argument_list|)
block|,
name|hasHadMouse
argument_list|(
literal|0
argument_list|)
block|,
name|aboutToHide
argument_list|(
literal|0
argument_list|)
block|,
name|motions
argument_list|(
literal|0
argument_list|)
block|,
name|currentAction
argument_list|(
literal|0
argument_list|)
block|,
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|selectAction
argument_list|(
literal|0
argument_list|)
block|,
name|cancelAction
argument_list|(
literal|0
argument_list|)
block|,
endif|#
directive|endif
name|scroll
argument_list|(
literal|0
argument_list|)
block|,
name|eventLoop
argument_list|(
literal|0
argument_list|)
block|,
name|tearoff
argument_list|(
literal|0
argument_list|)
block|,
name|tornoff
argument_list|(
literal|0
argument_list|)
block|,
name|tearoffHighlighted
argument_list|(
literal|0
argument_list|)
block|,
name|hasCheckableItems
argument_list|(
literal|0
argument_list|)
block|,
name|sloppyAction
argument_list|(
literal|0
argument_list|)
block|,
name|doChildEffects
argument_list|(
name|false
argument_list|)
block|,
name|platformMenu
argument_list|(
literal|0
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WINCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_MENUBAR
argument_list|)
block|,
name|wce_menu
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_WS_S60
block|,
name|symbian_menu
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
block|{ }
operator|~
name|QMenuPrivate
argument_list|()
block|{
name|delete
name|scroll
block|;
name|delete
name|platformMenu
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WINCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_MENUBAR
argument_list|)
name|delete
name|wce_menu
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_WS_S60
name|delete
name|symbian_menu
block|;
endif|#
directive|endif
block|}
name|void
name|init
argument_list|()
block|;
specifier|static
name|QMenuPrivate
operator|*
name|get
argument_list|(
argument|QMenu *m
argument_list|)
block|{
return|return
name|m
operator|->
name|d_func
argument_list|()
return|;
block|}
name|int
name|scrollerHeight
argument_list|()
specifier|const
block|;
comment|//item calculations
name|mutable
name|uint
name|itemsDirty
operator|:
literal|1
block|;
name|mutable
name|uint
name|maxIconWidth
block|,
name|tabWidth
block|;
name|QRect
name|actionRect
argument_list|(
argument|QAction *
argument_list|)
specifier|const
block|;
name|mutable
name|QVector
operator|<
name|QRect
operator|>
name|actionRects
block|;
name|mutable
name|QHash
operator|<
name|QAction
operator|*
block|,
name|QWidget
operator|*
operator|>
name|widgetItems
block|;
name|void
name|updateActionRects
argument_list|()
specifier|const
block|;
name|void
name|updateActionRects
argument_list|(
argument|const QRect&screen
argument_list|)
specifier|const
block|;
name|QRect
name|popupGeometry
argument_list|(
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|QRect
name|popupGeometry
argument_list|(
argument|int screen = -
literal|1
argument_list|)
specifier|const
block|;
name|mutable
name|uint
name|ncols
operator|:
literal|4
block|;
comment|//4 bits is probably plenty
name|uint
name|collapsibleSeparators
operator|:
literal|1
block|;
name|QSize
name|adjustMenuSizeForScreen
argument_list|(
specifier|const
name|QRect
operator|&
name|screen
argument_list|)
block|;
name|int
name|getLastVisibleAction
argument_list|()
specifier|const
block|;
name|bool
name|activationRecursionGuard
block|;
comment|//selection
specifier|static
name|QMenu
operator|*
name|mouseDown
block|;
name|QPoint
name|mousePopupPos
block|;
name|uint
name|hasHadMouse
operator|:
literal|1
block|;
name|uint
name|aboutToHide
operator|:
literal|1
block|;
name|int
name|motions
block|;
name|QAction
operator|*
name|currentAction
block|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|QAction
operator|*
name|selectAction
block|;
name|QAction
operator|*
name|cancelAction
block|;
endif|#
directive|endif
name|QBasicTimer
name|menuDelayTimer
block|;     enum
name|SelectionReason
block|{
name|SelectedFromKeyboard
block|,
name|SelectedFromElsewhere
block|}
block|;
name|QWidget
operator|*
name|topCausedWidget
argument_list|()
specifier|const
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
name|setFirstActionActive
argument_list|()
block|;
name|void
name|setCurrentAction
argument_list|(
argument|QAction *
argument_list|,
argument|int popup = -
literal|1
argument_list|,
argument|SelectionReason reason = SelectedFromElsewhere
argument_list|,
argument|bool activateFirst = false
argument_list|)
block|;
name|void
name|popupAction
argument_list|(
name|QAction
operator|*
argument_list|,
name|int
argument_list|,
name|bool
argument_list|)
block|;
name|void
name|setSyncAction
argument_list|()
block|;
comment|//scrolling support
block|struct
name|QMenuScroller
block|{         enum
name|ScrollLocation
block|{
name|ScrollStay
block|,
name|ScrollBottom
block|,
name|ScrollTop
block|,
name|ScrollCenter
block|}
block|;         enum
name|ScrollDirection
block|{
name|ScrollNone
operator|=
literal|0
block|,
name|ScrollUp
operator|=
literal|0x01
block|,
name|ScrollDown
operator|=
literal|0x02
block|}
block|;
name|uint
name|scrollFlags
operator|:
literal|2
block|,
name|scrollDirection
operator|:
literal|2
block|;
name|int
name|scrollOffset
block|;
name|QBasicTimer
name|scrollTimer
block|;
name|QMenuScroller
argument_list|()
operator|:
name|scrollFlags
argument_list|(
name|ScrollNone
argument_list|)
block|,
name|scrollDirection
argument_list|(
name|ScrollNone
argument_list|)
block|,
name|scrollOffset
argument_list|(
literal|0
argument_list|)
block|{ }
operator|~
name|QMenuScroller
argument_list|()
block|{ }
block|}
operator|*
name|scroll
block|;
name|void
name|scrollMenu
argument_list|(
argument|QMenuScroller::ScrollLocation location
argument_list|,
argument|bool active=false
argument_list|)
block|;
name|void
name|scrollMenu
argument_list|(
argument|QMenuScroller::ScrollDirection direction
argument_list|,
argument|bool page=false
argument_list|,
argument|bool active=false
argument_list|)
block|;
name|void
name|scrollMenu
argument_list|(
argument|QAction *action
argument_list|,
argument|QMenuScroller::ScrollLocation location
argument_list|,
argument|bool active=false
argument_list|)
block|;
comment|//synchronous operation (ie exec())
name|QEventLoop
operator|*
name|eventLoop
block|;
name|QPointer
operator|<
name|QAction
operator|>
name|syncAction
block|;
comment|//search buffer
name|QString
name|searchBuffer
block|;
name|QBasicTimer
name|searchBufferTimer
block|;
comment|//passing of mouse events up the parent hierarchy
name|QPointer
operator|<
name|QMenu
operator|>
name|activeMenu
block|;
name|bool
name|mouseEventTaken
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
comment|//used to walk up the popup list
block|struct
name|QMenuCaused
block|{
name|QPointer
operator|<
name|QWidget
operator|>
name|widget
block|;
name|QPointer
operator|<
name|QAction
operator|>
name|action
block|;     }
block|;
name|virtual
name|QList
operator|<
name|QPointer
operator|<
name|QWidget
operator|>
expr|>
name|calcCausedStack
argument_list|()
specifier|const
block|;
name|QMenuCaused
name|causedPopup
block|;
name|void
name|hideUpToMenuBar
argument_list|()
block|;
name|void
name|hideMenu
argument_list|(
argument|QMenu *menu
argument_list|,
argument|bool justRegister = false
argument_list|)
block|;
comment|//index mappings
specifier|inline
name|QAction
operator|*
name|actionAt
argument_list|(
argument|int i
argument_list|)
specifier|const
block|{
return|return
name|q_func
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
return|;
block|}
specifier|inline
name|int
name|indexOf
argument_list|(
argument|QAction *act
argument_list|)
specifier|const
block|{
return|return
name|q_func
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|indexOf
argument_list|(
name|act
argument_list|)
return|;
block|}
comment|//tear off support
name|uint
name|tearoff
operator|:
literal|1
block|,
name|tornoff
operator|:
literal|1
block|,
name|tearoffHighlighted
operator|:
literal|1
block|;
name|QPointer
operator|<
name|QTornOffMenu
operator|>
name|tornPopup
block|;
name|mutable
name|bool
name|hasCheckableItems
block|;
comment|//sloppy selection
specifier|static
name|int
name|sloppyDelayTimer
block|;
name|mutable
name|QAction
operator|*
name|sloppyAction
block|;
name|QRegion
name|sloppyRegion
block|;
comment|//default action
name|QPointer
operator|<
name|QAction
operator|>
name|defaultAction
block|;
name|QAction
operator|*
name|menuAction
block|;
name|QAction
operator|*
name|defaultMenuAction
block|;
name|void
name|setOverrideMenuAction
argument_list|(
name|QAction
operator|*
argument_list|)
block|;
name|void
name|_q_overrideMenuActionDestroyed
argument_list|()
block|;
comment|//firing of events
name|void
name|activateAction
argument_list|(
argument|QAction *
argument_list|,
argument|QAction::ActionEvent
argument_list|,
argument|bool self=true
argument_list|)
block|;
name|void
name|activateCausedStack
argument_list|(
specifier|const
name|QList
operator|<
name|QPointer
operator|<
name|QWidget
operator|>
expr|>
operator|&
argument_list|,
name|QAction
operator|*
argument_list|,
name|QAction
operator|::
name|ActionEvent
argument_list|,
name|bool
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
name|bool
name|hasMouseMoved
argument_list|(
specifier|const
name|QPoint
operator|&
name|globalPos
argument_list|)
block|;
name|void
name|updateLayoutDirection
argument_list|()
block|;
comment|//menu fading/scrolling effects
name|bool
name|doChildEffects
block|;
name|QPlatformMenu
operator|*
name|platformMenu
block|;
name|QPointer
operator|<
name|QAction
operator|>
name|actionAboutToTrigger
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WINCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_MENUBAR
argument_list|)
block|struct
name|QWceMenuPrivate
block|{
name|QList
operator|<
name|QWceMenuAction
operator|*
operator|>
name|actionItems
block|;
name|HMENU
name|menuHandle
block|;
name|QWceMenuPrivate
argument_list|()
block|;
operator|~
name|QWceMenuPrivate
argument_list|()
block|;
name|void
name|addAction
argument_list|(
name|QAction
operator|*
argument_list|,
name|QWceMenuAction
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
name|wce_menu
block|;
name|HMENU
name|wceMenu
argument_list|()
block|;
name|QAction
operator|*
name|wceCommands
argument_list|(
argument|uint command
argument_list|)
block|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_S60
argument_list|)
block|struct
name|QSymbianMenuPrivate
block|{
name|QList
operator|<
name|QSymbianMenuAction
operator|*
operator|>
name|actionItems
block|;
name|QSymbianMenuPrivate
argument_list|()
block|;
operator|~
name|QSymbianMenuPrivate
argument_list|()
block|;
name|void
name|addAction
argument_list|(
name|QAction
operator|*
argument_list|,
name|QSymbianMenuAction
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
argument_list|(
argument|bool reCreate = false
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
expr|}
operator|*
name|symbian_menu
block|;
endif|#
directive|endif
name|QPointer
operator|<
name|QWidget
operator|>
name|noReplayFor
block|; }
block|;
endif|#
directive|endif
comment|// QT_NO_MENU
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMENU_P_H
end_comment
end_unit
