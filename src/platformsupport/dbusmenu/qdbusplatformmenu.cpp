begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbusplatformmenu_p.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QWindow>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_LOGGING_CATEGORY
argument_list|(
name|qLcMenu
argument_list|,
literal|"qt.qpa.menu"
argument_list|)
decl|static
DECL|variable|nextDBusID
name|int
name|nextDBusID
init|=
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|menusByID
name|QHash
argument_list|<
name|int
argument_list|,
name|QDBusPlatformMenu
modifier|*
argument_list|>
name|menusByID
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|menuItemsByID
name|QHash
argument_list|<
name|int
argument_list|,
name|QDBusPlatformMenuItem
modifier|*
argument_list|>
name|menuItemsByID
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|m_topLevelMenus
name|QList
argument_list|<
name|QDBusPlatformMenu
modifier|*
argument_list|>
name|QDBusPlatformMenu
operator|::
name|m_topLevelMenus
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QDBusPlatformMenuItem
name|QDBusPlatformMenuItem
operator|::
name|QDBusPlatformMenuItem
parameter_list|(
name|quintptr
name|tag
parameter_list|)
member_init_list|:
name|m_tag
argument_list|(
name|tag
condition|?
name|tag
else|:
cast|reinterpret_cast
argument_list|<
name|quintptr
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
comment|// QMenu will overwrite this later
member_init_list|,
name|m_subMenu
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|m_role
argument_list|(
name|NoRole
argument_list|)
member_init_list|,
name|m_isEnabled
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_isVisible
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|m_isSeparator
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_isCheckable
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_isChecked
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_dbusID
argument_list|(
name|nextDBusID
operator|++
argument_list|)
block|{
name|menuItemsByID
operator|.
name|insert
argument_list|(
name|m_dbusID
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QDBusPlatformMenuItem
name|QDBusPlatformMenuItem
operator|::
name|~
name|QDBusPlatformMenuItem
parameter_list|()
block|{
name|menuItemsByID
operator|.
name|remove
argument_list|(
name|m_dbusID
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setTag
name|void
name|QDBusPlatformMenuItem
operator|::
name|setTag
parameter_list|(
name|quintptr
name|tag
parameter_list|)
block|{
name|m_tag
operator|=
name|tag
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setText
name|void
name|QDBusPlatformMenuItem
operator|::
name|setText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|qCDebug
argument_list|(
name|qLcMenu
argument_list|)
operator|<<
name|m_dbusID
operator|<<
name|text
expr_stmt|;
name|m_text
operator|=
name|text
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setIcon
name|void
name|QDBusPlatformMenuItem
operator|::
name|setIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
block|{
name|m_icon
operator|=
name|icon
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Set a submenu under this menu item. */
end_comment
begin_function
DECL|function|setMenu
name|void
name|QDBusPlatformMenuItem
operator|::
name|setMenu
parameter_list|(
name|QPlatformMenu
modifier|*
name|menu
parameter_list|)
block|{
name|m_subMenu
operator|=
cast|static_cast
argument_list|<
name|QDBusPlatformMenu
operator|*
argument_list|>
argument_list|(
name|menu
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setEnabled
name|void
name|QDBusPlatformMenuItem
operator|::
name|setEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
name|m_isEnabled
operator|=
name|enabled
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setVisible
name|void
name|QDBusPlatformMenuItem
operator|::
name|setVisible
parameter_list|(
name|bool
name|isVisible
parameter_list|)
block|{
name|m_isVisible
operator|=
name|isVisible
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setIsSeparator
name|void
name|QDBusPlatformMenuItem
operator|::
name|setIsSeparator
parameter_list|(
name|bool
name|isSeparator
parameter_list|)
block|{
name|m_isSeparator
operator|=
name|isSeparator
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setRole
name|void
name|QDBusPlatformMenuItem
operator|::
name|setRole
parameter_list|(
name|QPlatformMenuItem
operator|::
name|MenuRole
name|role
parameter_list|)
block|{
name|m_role
operator|=
name|role
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCheckable
name|void
name|QDBusPlatformMenuItem
operator|::
name|setCheckable
parameter_list|(
name|bool
name|checkable
parameter_list|)
block|{
name|m_isCheckable
operator|=
name|checkable
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setChecked
name|void
name|QDBusPlatformMenuItem
operator|::
name|setChecked
parameter_list|(
name|bool
name|isChecked
parameter_list|)
block|{
name|m_isChecked
operator|=
name|isChecked
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setShortcut
name|void
name|QDBusPlatformMenuItem
operator|::
name|setShortcut
parameter_list|(
specifier|const
name|QKeySequence
modifier|&
name|shortcut
parameter_list|)
block|{
name|m_shortcut
operator|=
name|shortcut
expr_stmt|;
block|}
end_function
begin_function
DECL|function|trigger
name|void
name|QDBusPlatformMenuItem
operator|::
name|trigger
parameter_list|()
block|{
emit|emit
name|activated
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|byId
name|QDBusPlatformMenuItem
modifier|*
name|QDBusPlatformMenuItem
operator|::
name|byId
parameter_list|(
name|int
name|id
parameter_list|)
block|{
return|return
name|menuItemsByID
index|[
name|id
index|]
return|;
block|}
end_function
begin_function
DECL|function|byIds
name|QList
argument_list|<
specifier|const
name|QDBusPlatformMenuItem
modifier|*
argument_list|>
name|QDBusPlatformMenuItem
operator|::
name|byIds
parameter_list|(
specifier|const
name|QList
argument_list|<
name|int
argument_list|>
modifier|&
name|ids
parameter_list|)
block|{
name|QList
argument_list|<
specifier|const
name|QDBusPlatformMenuItem
modifier|*
argument_list|>
name|ret
decl_stmt|;
name|Q_FOREACH
argument_list|(
argument|int id
argument_list|,
argument|ids
argument_list|)
block|{
if|if
condition|(
name|menuItemsByID
operator|.
name|contains
argument_list|(
name|id
argument_list|)
condition|)
name|ret
operator|<<
name|menuItemsByID
index|[
name|id
index|]
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_constructor
DECL|function|QDBusPlatformMenu
name|QDBusPlatformMenu
operator|::
name|QDBusPlatformMenu
parameter_list|(
name|quintptr
name|tag
parameter_list|)
member_init_list|:
name|m_tag
argument_list|(
name|tag
condition|?
name|tag
else|:
cast|reinterpret_cast
argument_list|<
name|quintptr
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
member_init_list|,
name|m_isEnabled
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_isVisible
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|m_isSeparator
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_dbusID
argument_list|(
name|nextDBusID
operator|++
argument_list|)
member_init_list|,
name|m_revision
argument_list|(
literal|0
argument_list|)
block|{
name|menusByID
operator|.
name|insert
argument_list|(
name|m_dbusID
argument_list|,
name|this
argument_list|)
expr_stmt|;
comment|// Assume it's top-level until we find out otherwise
name|m_topLevelMenus
operator|<<
name|this
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QDBusPlatformMenu
name|QDBusPlatformMenu
operator|::
name|~
name|QDBusPlatformMenu
parameter_list|()
block|{
name|menusByID
operator|.
name|remove
argument_list|(
name|m_dbusID
argument_list|)
expr_stmt|;
name|m_topLevelMenus
operator|.
name|removeOne
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|insertMenuItem
name|void
name|QDBusPlatformMenu
operator|::
name|insertMenuItem
parameter_list|(
name|QPlatformMenuItem
modifier|*
name|menuItem
parameter_list|,
name|QPlatformMenuItem
modifier|*
name|before
parameter_list|)
block|{
name|QDBusPlatformMenuItem
modifier|*
name|item
init|=
cast|static_cast
argument_list|<
name|QDBusPlatformMenuItem
operator|*
argument_list|>
argument_list|(
name|menuItem
argument_list|)
decl_stmt|;
name|QDBusPlatformMenuItem
modifier|*
name|beforeItem
init|=
cast|static_cast
argument_list|<
name|QDBusPlatformMenuItem
operator|*
argument_list|>
argument_list|(
name|before
argument_list|)
decl_stmt|;
name|int
name|idx
init|=
name|m_items
operator|.
name|indexOf
argument_list|(
name|beforeItem
argument_list|)
decl_stmt|;
name|qCDebug
argument_list|(
name|qLcMenu
argument_list|)
operator|<<
name|item
operator|->
name|dbusID
argument_list|()
operator|<<
name|item
operator|->
name|text
argument_list|()
expr_stmt|;
if|if
condition|(
name|idx
operator|<
literal|0
condition|)
name|m_items
operator|.
name|append
argument_list|(
name|item
argument_list|)
expr_stmt|;
else|else
name|m_items
operator|.
name|insert
argument_list|(
name|idx
argument_list|,
name|item
argument_list|)
expr_stmt|;
name|m_itemsByTag
operator|.
name|insert
argument_list|(
name|item
operator|->
name|tag
argument_list|()
argument_list|,
name|item
argument_list|)
expr_stmt|;
comment|// If a menu is found as a submenu under an item, we know that it's not a top-level menu.
if|if
condition|(
name|item
operator|->
name|menu
argument_list|()
condition|)
name|m_topLevelMenus
operator|.
name|removeOne
argument_list|(
cast|const_cast
argument_list|<
name|QDBusPlatformMenu
operator|*
argument_list|>
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|QDBusPlatformMenu
operator|*
argument_list|>
argument_list|(
name|item
operator|->
name|menu
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeMenuItem
name|void
name|QDBusPlatformMenu
operator|::
name|removeMenuItem
parameter_list|(
name|QPlatformMenuItem
modifier|*
name|menuItem
parameter_list|)
block|{
name|m_items
operator|.
name|removeAll
argument_list|(
cast|static_cast
argument_list|<
name|QDBusPlatformMenuItem
operator|*
argument_list|>
argument_list|(
name|menuItem
argument_list|)
argument_list|)
expr_stmt|;
name|m_itemsByTag
operator|.
name|remove
argument_list|(
name|menuItem
operator|->
name|tag
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|syncMenuItem
name|void
name|QDBusPlatformMenu
operator|::
name|syncMenuItem
parameter_list|(
name|QPlatformMenuItem
modifier|*
name|menuItem
parameter_list|)
block|{
comment|// TODO keep around copies of the QDBusMenuLayoutItems so they can be updated?
comment|// or eliminate them by putting dbus streaming operators in this class instead?
comment|// or somehow tell the dbusmenu client that something has changed, so it will ask for properties again
name|emitUpdated
argument_list|()
expr_stmt|;
name|QDBusMenuItemList
name|updated
decl_stmt|;
name|QDBusMenuItemKeysList
name|removed
decl_stmt|;
name|updated
operator|<<
name|QDBusMenuItem
argument_list|(
cast|static_cast
argument_list|<
name|QDBusPlatformMenuItem
operator|*
argument_list|>
argument_list|(
name|menuItem
argument_list|)
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|qLcMenu
argument_list|)
operator|<<
name|updated
expr_stmt|;
emit|emit
name|propertiesUpdated
argument_list|(
name|updated
argument_list|,
name|removed
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|byId
name|QDBusPlatformMenu
modifier|*
name|QDBusPlatformMenu
operator|::
name|byId
parameter_list|(
name|int
name|id
parameter_list|)
block|{
return|return
name|menusByID
index|[
name|id
index|]
return|;
block|}
end_function
begin_function
DECL|function|emitUpdated
name|void
name|QDBusPlatformMenu
operator|::
name|emitUpdated
parameter_list|()
block|{
emit|emit
name|updated
argument_list|(
operator|++
name|m_revision
argument_list|,
name|m_dbusID
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|setTag
name|void
name|QDBusPlatformMenu
operator|::
name|setTag
parameter_list|(
name|quintptr
name|tag
parameter_list|)
block|{
name|m_tag
operator|=
name|tag
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setText
name|void
name|QDBusPlatformMenu
operator|::
name|setText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|m_text
operator|=
name|text
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setIcon
name|void
name|QDBusPlatformMenu
operator|::
name|setIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
block|{
name|m_icon
operator|=
name|icon
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setEnabled
name|void
name|QDBusPlatformMenu
operator|::
name|setEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
name|m_isEnabled
operator|=
name|enabled
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setVisible
name|void
name|QDBusPlatformMenu
operator|::
name|setVisible
parameter_list|(
name|bool
name|isVisible
parameter_list|)
block|{
name|m_isVisible
operator|=
name|isVisible
expr_stmt|;
block|}
end_function
begin_function
DECL|function|menuItemAt
name|QPlatformMenuItem
modifier|*
name|QDBusPlatformMenu
operator|::
name|menuItemAt
parameter_list|(
name|int
name|position
parameter_list|)
specifier|const
block|{
return|return
name|m_items
operator|.
name|at
argument_list|(
name|position
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|menuItemForTag
name|QPlatformMenuItem
modifier|*
name|QDBusPlatformMenu
operator|::
name|menuItemForTag
parameter_list|(
name|quintptr
name|tag
parameter_list|)
specifier|const
block|{
return|return
name|m_itemsByTag
index|[
name|tag
index|]
return|;
block|}
end_function
begin_function
DECL|function|items
specifier|const
name|QList
argument_list|<
name|QDBusPlatformMenuItem
modifier|*
argument_list|>
name|QDBusPlatformMenu
operator|::
name|items
parameter_list|()
specifier|const
block|{
return|return
name|m_items
return|;
block|}
end_function
begin_function
DECL|function|createMenuItem
name|QPlatformMenuItem
modifier|*
name|QDBusPlatformMenu
operator|::
name|createMenuItem
parameter_list|()
specifier|const
block|{
name|QDBusPlatformMenuItem
modifier|*
name|ret
init|=
operator|new
name|QDBusPlatformMenuItem
argument_list|()
decl_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|createSubMenu
name|QPlatformMenu
modifier|*
name|QDBusPlatformMenu
operator|::
name|createSubMenu
parameter_list|()
specifier|const
block|{
return|return
operator|new
name|QDBusPlatformMenu
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
