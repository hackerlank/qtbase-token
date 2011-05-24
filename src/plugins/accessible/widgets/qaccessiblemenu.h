begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QACCESSIBLEMENU_H
end_ifndef
begin_define
DECL|macro|QACCESSIBLEMENU_H
define|#
directive|define
name|QACCESSIBLEMENU_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qaccessiblewidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
ifndef|#
directive|ifndef
name|QT_NO_MENU
DECL|variable|QMenu
name|class
name|QMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMenuBar
name|class
name|QMenuBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAction
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAccessibleMenu
range|:
name|public
name|QAccessibleWidgetEx
block|{
name|public
operator|:
name|explicit
name|QAccessibleMenu
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|int
name|childAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|QRect
name|rect
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|QString
name|text
argument_list|(
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|Role
name|role
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|State
name|state
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|int
name|navigate
argument_list|(
argument|RelationFlag relation
argument_list|,
argument|int entry
argument_list|,
argument|QAccessibleInterface **target
argument_list|)
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *child
argument_list|)
specifier|const
block|;
name|QString
name|actionText
argument_list|(
argument|int action
argument_list|,
argument|QAccessible::Text text
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|bool
name|doAction
argument_list|(
argument|int action
argument_list|,
argument|int child
argument_list|,
argument|const QVariantList&params
argument_list|)
block|;
name|protected
operator|:
name|QMenu
operator|*
name|menu
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_MENUBAR
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleMenuBar
range|:
name|public
name|QAccessibleWidgetEx
block|{
name|public
operator|:
name|explicit
name|QAccessibleMenuBar
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|int
name|childAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|QRect
name|rect
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|QString
name|text
argument_list|(
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|Role
name|role
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|State
name|state
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|int
name|navigate
argument_list|(
argument|RelationFlag relation
argument_list|,
argument|int entry
argument_list|,
argument|QAccessibleInterface **target
argument_list|)
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *child
argument_list|)
specifier|const
block|;
name|QString
name|actionText
argument_list|(
argument|int action
argument_list|,
argument|QAccessible::Text text
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|bool
name|doAction
argument_list|(
argument|int action
argument_list|,
argument|int child
argument_list|,
argument|const QVariantList&params
argument_list|)
block|;
name|protected
operator|:
name|QMenuBar
operator|*
name|menuBar
argument_list|()
specifier|const
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
begin_decl_stmt
name|class
name|QAccessibleMenuItem
range|:
name|public
name|QAccessibleInterface
block|{
name|public
operator|:
name|explicit
name|QAccessibleMenuItem
argument_list|(
name|QWidget
operator|*
name|owner
argument_list|,
name|QAction
operator|*
name|w
argument_list|)
block|;
name|virtual
operator|~
name|QAccessibleMenuItem
argument_list|()
block|;
name|virtual
name|QString
name|actionText
argument_list|(
argument|int action
argument_list|,
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|virtual
name|int
name|childAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|virtual
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|doAction
argument_list|(
argument|int action
argument_list|,
argument|int child
argument_list|,
argument|const QVariantList& params = QVariantList()
argument_list|)
block|;
name|virtual
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface * child
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|virtual
name|int
name|navigate
argument_list|(
argument|RelationFlag relation
argument_list|,
argument|int entry
argument_list|,
argument|QAccessibleInterface ** target
argument_list|)
specifier|const
block|;
name|virtual
name|QObject
operator|*
name|object
argument_list|()
specifier|const
block|;
name|virtual
name|QRect
name|rect
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|virtual
name|Relation
name|relationTo
argument_list|(
argument|int child
argument_list|,
argument|const QAccessibleInterface * other
argument_list|,
argument|int otherChild
argument_list|)
specifier|const
block|;
name|virtual
name|Role
name|role
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|setText
argument_list|(
argument|Text t
argument_list|,
argument|int child
argument_list|,
argument|const QString& text
argument_list|)
block|;
name|virtual
name|State
name|state
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|virtual
name|QString
name|text
argument_list|(
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|virtual
name|int
name|userActionCount
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|QWidget
operator|*
name|owner
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|QAction
operator|*
name|action
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QAction
operator|*
name|m_action
block|;
name|QWidget
operator|*
name|m_owner
block|;
comment|// can hold either QMenu or the QMenuBar that contains the action
block|}
decl_stmt|;
end_decl_stmt
begin_endif
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
comment|// QT_NO_ACCESSIBILITY
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QACCESSIBLEMENU_H
end_comment
end_unit
