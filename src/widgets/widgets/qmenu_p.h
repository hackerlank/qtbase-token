begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_include
include|#
directive|include
file|<qpa/qplatformmenu.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_MENU
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
name|Q_OS_WINCE
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
name|toolTipsVisible
argument_list|(
name|false
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
name|Q_OS_WINCE
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
block|{ }
operator|~
name|QMenuPrivate
argument_list|()
block|{
name|delete
name|scroll
block|;
if|if
condition|(
operator|!
name|platformMenu
operator|.
name|isNull
argument_list|()
operator|&&
operator|!
name|platformMenu
operator|->
name|parent
argument_list|()
condition|)
name|delete
name|platformMenu
operator|.
name|data
parameter_list|()
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
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
block|}
name|void
name|init
argument_list|()
decl_stmt|;
end_decl_stmt
begin_function
specifier|static
name|QMenuPrivate
modifier|*
name|get
parameter_list|(
name|QMenu
modifier|*
name|m
parameter_list|)
block|{
return|return
name|m
operator|->
name|d_func
argument_list|()
return|;
block|}
end_function
begin_expr_stmt
name|int
name|scrollerHeight
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_comment
comment|//item calculations
end_comment
begin_decl_stmt
name|mutable
name|uint
name|itemsDirty
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|uint
name|maxIconWidth
decl_stmt|,
name|tabWidth
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|actionRect
argument_list|(
name|QAction
operator|*
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|mutable
name|QVector
operator|<
name|QRect
operator|>
name|actionRects
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|mutable
name|QHash
operator|<
name|QAction
operator|*
operator|,
name|QWidget
operator|*
operator|>
name|widgetItems
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|void
name|updateActionRects
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|void
name|updateActionRects
argument_list|(
specifier|const
name|QRect
operator|&
name|screen
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|popupGeometry
argument_list|(
specifier|const
name|QWidget
operator|*
name|widget
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|popupGeometry
argument_list|(
name|int
name|screen
operator|=
operator|-
literal|1
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|uint
name|ncols
range|:
literal|4
decl_stmt|;
end_decl_stmt
begin_comment
comment|//4 bits is probably plenty
end_comment
begin_decl_stmt
name|uint
name|collapsibleSeparators
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|toolTipsVisible
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QSize
name|adjustMenuSizeForScreen
parameter_list|(
specifier|const
name|QRect
modifier|&
name|screen
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|getLastVisibleAction
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|activationRecursionGuard
decl_stmt|;
end_decl_stmt
begin_comment
comment|//selection
end_comment
begin_decl_stmt
specifier|static
name|QMenu
modifier|*
name|mouseDown
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPoint
name|mousePopupPos
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|hasHadMouse
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|aboutToHide
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|motions
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAction
modifier|*
name|currentAction
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
end_ifdef
begin_decl_stmt
name|QAction
modifier|*
name|selectAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAction
modifier|*
name|cancelAction
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QBasicTimer
name|menuDelayTimer
decl_stmt|;
end_decl_stmt
begin_enum
enum|enum
name|SelectionReason
block|{
name|SelectedFromKeyboard
block|,
name|SelectedFromElsewhere
block|}
enum|;
end_enum
begin_expr_stmt
name|QWidget
operator|*
name|topCausedWidget
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QAction
modifier|*
name|actionAt
argument_list|(
name|QPoint
name|p
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setFirstActionActive
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setCurrentAction
parameter_list|(
name|QAction
modifier|*
parameter_list|,
name|int
name|popup
init|=
operator|-
literal|1
parameter_list|,
name|SelectionReason
name|reason
init|=
name|SelectedFromElsewhere
parameter_list|,
name|bool
name|activateFirst
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|popupAction
parameter_list|(
name|QAction
modifier|*
parameter_list|,
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setSyncAction
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//scrolling support
end_comment
begin_struct
struct|struct
name|QMenuScroller
block|{
enum|enum
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
enum|;
enum|enum
name|ScrollDirection
block|{
name|ScrollNone
init|=
literal|0
block|,
name|ScrollUp
init|=
literal|0x01
block|,
name|ScrollDown
init|=
literal|0x02
block|}
enum|;
name|uint
name|scrollFlags
range|:
literal|2
decl_stmt|,
name|scrollDirection
range|:
literal|2
decl_stmt|;
name|int
name|scrollOffset
decl_stmt|;
name|QBasicTimer
name|scrollTimer
decl_stmt|;
name|QMenuScroller
argument_list|()
operator|:
name|scrollFlags
argument_list|(
name|ScrollNone
argument_list|)
operator|,
name|scrollDirection
argument_list|(
name|ScrollNone
argument_list|)
operator|,
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
modifier|*
name|scroll
struct|;
end_struct
begin_decl_stmt
name|void
name|scrollMenu
argument_list|(
name|QMenuScroller
operator|::
name|ScrollLocation
name|location
argument_list|,
name|bool
name|active
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|scrollMenu
argument_list|(
name|QMenuScroller
operator|::
name|ScrollDirection
name|direction
argument_list|,
name|bool
name|page
operator|=
name|false
argument_list|,
name|bool
name|active
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|scrollMenu
argument_list|(
name|QAction
operator|*
name|action
argument_list|,
name|QMenuScroller
operator|::
name|ScrollLocation
name|location
argument_list|,
name|bool
name|active
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//synchronous operation (ie exec())
end_comment
begin_decl_stmt
name|QEventLoop
modifier|*
name|eventLoop
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QPointer
operator|<
name|QAction
operator|>
name|syncAction
expr_stmt|;
end_expr_stmt
begin_comment
comment|//search buffer
end_comment
begin_decl_stmt
name|QString
name|searchBuffer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBasicTimer
name|searchBufferTimer
decl_stmt|;
end_decl_stmt
begin_comment
comment|//passing of mouse events up the parent hierarchy
end_comment
begin_expr_stmt
name|QPointer
operator|<
name|QMenu
operator|>
name|activeMenu
expr_stmt|;
end_expr_stmt
begin_function_decl
name|bool
name|mouseEventTaken
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//used to walk up the popup list
end_comment
begin_struct
struct|struct
name|QMenuCaused
block|{
name|QPointer
operator|<
name|QWidget
operator|>
name|widget
expr_stmt|;
name|QPointer
operator|<
name|QAction
operator|>
name|action
expr_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
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
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QMenuCaused
name|causedPopup
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|hideUpToMenuBar
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hideMenu
parameter_list|(
name|QMenu
modifier|*
name|menu
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//index mappings
end_comment
begin_decl_stmt
specifier|inline
name|QAction
modifier|*
name|actionAt
argument_list|(
name|int
name|i
argument_list|)
decl|const
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
end_decl_stmt
begin_decl_stmt
specifier|inline
name|int
name|indexOf
argument_list|(
name|QAction
operator|*
name|act
argument_list|)
decl|const
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
end_decl_stmt
begin_comment
comment|//tear off support
end_comment
begin_decl_stmt
name|uint
name|tearoff
range|:
literal|1
decl_stmt|,
name|tornoff
range|:
literal|1
decl_stmt|,
name|tearoffHighlighted
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QPointer
operator|<
name|QTornOffMenu
operator|>
name|tornPopup
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|mutable
name|bool
name|hasCheckableItems
decl_stmt|;
end_decl_stmt
begin_comment
comment|//sloppy selection
end_comment
begin_decl_stmt
specifier|static
name|int
name|sloppyDelayTimer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|QAction
modifier|*
name|sloppyAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRegion
name|sloppyRegion
decl_stmt|;
end_decl_stmt
begin_comment
comment|//default action
end_comment
begin_expr_stmt
name|QPointer
operator|<
name|QAction
operator|>
name|defaultAction
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QAction
modifier|*
name|menuAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAction
modifier|*
name|defaultMenuAction
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setOverrideMenuAction
parameter_list|(
name|QAction
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_overrideMenuActionDestroyed
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//firing of events
end_comment
begin_decl_stmt
name|void
name|activateAction
argument_list|(
name|QAction
operator|*
argument_list|,
name|QAction
operator|::
name|ActionEvent
argument_list|,
name|bool
name|self
operator|=
name|true
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
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
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|_q_actionTriggered
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_actionHovered
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|hasMouseMoved
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|globalPos
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|updateLayoutDirection
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//menu fading/scrolling effects
end_comment
begin_decl_stmt
name|bool
name|doChildEffects
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QPointer
operator|<
name|QPlatformMenu
operator|>
name|platformMenu
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QPointer
operator|<
name|QAction
operator|>
name|actionAboutToTrigger
expr_stmt|;
end_expr_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_MENUBAR
argument_list|)
end_if
begin_struct
struct|struct
name|QWceMenuPrivate
block|{
name|QList
operator|<
name|QWceMenuAction
operator|*
operator|>
name|actionItems
expr_stmt|;
name|HMENU
name|menuHandle
decl_stmt|;
name|QWceMenuPrivate
argument_list|()
expr_stmt|;
operator|~
name|QWceMenuPrivate
argument_list|()
expr_stmt|;
name|void
name|addAction
parameter_list|(
name|QAction
modifier|*
parameter_list|,
name|QWceMenuAction
modifier|*
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|addAction
parameter_list|(
name|QWceMenuAction
modifier|*
parameter_list|,
name|QWceMenuAction
modifier|*
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|syncAction
parameter_list|(
name|QWceMenuAction
modifier|*
parameter_list|)
function_decl|;
specifier|inline
name|void
name|syncAction
parameter_list|(
name|QAction
modifier|*
name|a
parameter_list|)
block|{
name|syncAction
argument_list|(
name|findAction
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|removeAction
parameter_list|(
name|QWceMenuAction
modifier|*
parameter_list|)
function_decl|;
name|void
name|rebuild
parameter_list|()
function_decl|;
specifier|inline
name|void
name|removeAction
parameter_list|(
name|QAction
modifier|*
name|a
parameter_list|)
block|{
name|removeAction
argument_list|(
name|findAction
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|QWceMenuAction
modifier|*
name|findAction
parameter_list|(
name|QAction
modifier|*
name|a
parameter_list|)
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
block|}
modifier|*
name|wce_menu
struct|;
end_struct
begin_function_decl
name|HMENU
name|wceMenu
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|QAction
modifier|*
name|wceCommands
parameter_list|(
name|uint
name|command
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QPointer
operator|<
name|QWidget
operator|>
name|noReplayFor
expr_stmt|;
end_expr_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MENU
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMENU_P_H
end_comment
end_unit
