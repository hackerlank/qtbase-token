begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qandroidplatformmenubar.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformmenu.h"
end_include
begin_include
include|#
directive|include
file|"androidjnimenu.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QAndroidPlatformMenuBar
name|QAndroidPlatformMenuBar
operator|::
name|QAndroidPlatformMenuBar
parameter_list|()
block|{
name|m_parentWindow
operator|=
literal|0
expr_stmt|;
name|QtAndroidMenu
operator|::
name|addMenuBar
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_destructor
DECL|function|~QAndroidPlatformMenuBar
name|QAndroidPlatformMenuBar
operator|::
name|~
name|QAndroidPlatformMenuBar
parameter_list|()
block|{
name|QtAndroidMenu
operator|::
name|removeMenuBar
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|insertMenu
name|void
name|QAndroidPlatformMenuBar
operator|::
name|insertMenu
parameter_list|(
name|QPlatformMenu
modifier|*
name|menu
parameter_list|,
name|QPlatformMenu
modifier|*
name|before
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_menusListMutex
argument_list|)
decl_stmt|;
name|m_menus
operator|.
name|insert
argument_list|(
name|std
operator|::
name|find
argument_list|(
name|m_menus
operator|.
name|begin
argument_list|()
argument_list|,
name|m_menus
operator|.
name|end
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|QAndroidPlatformMenu
operator|*
argument_list|>
argument_list|(
name|before
argument_list|)
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|QAndroidPlatformMenu
operator|*
argument_list|>
argument_list|(
name|menu
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeMenu
name|void
name|QAndroidPlatformMenuBar
operator|::
name|removeMenu
parameter_list|(
name|QPlatformMenu
modifier|*
name|menu
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_menusListMutex
argument_list|)
decl_stmt|;
name|m_menus
operator|.
name|erase
argument_list|(
name|std
operator|::
name|find
argument_list|(
name|m_menus
operator|.
name|begin
argument_list|()
argument_list|,
name|m_menus
operator|.
name|end
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|QAndroidPlatformMenu
operator|*
argument_list|>
argument_list|(
name|menu
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|syncMenu
name|void
name|QAndroidPlatformMenuBar
operator|::
name|syncMenu
parameter_list|(
name|QPlatformMenu
modifier|*
name|menu
parameter_list|)
block|{
name|QtAndroidMenu
operator|::
name|syncMenu
argument_list|(
cast|static_cast
argument_list|<
name|QAndroidPlatformMenu
operator|*
argument_list|>
argument_list|(
name|menu
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleReparent
name|void
name|QAndroidPlatformMenuBar
operator|::
name|handleReparent
parameter_list|(
name|QWindow
modifier|*
name|newParentWindow
parameter_list|)
block|{
if|if
condition|(
name|m_parentWindow
operator|==
name|newParentWindow
condition|)
return|return;
name|m_parentWindow
operator|=
name|newParentWindow
expr_stmt|;
name|QtAndroidMenu
operator|::
name|setMenuBar
argument_list|(
name|this
argument_list|,
name|newParentWindow
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|menuForTag
name|QPlatformMenu
modifier|*
name|QAndroidPlatformMenuBar
operator|::
name|menuForTag
parameter_list|(
name|quintptr
name|tag
parameter_list|)
specifier|const
block|{
for|for
control|(
name|QPlatformMenu
modifier|*
name|menu
range|:
name|m_menus
control|)
block|{
if|if
condition|(
name|menu
operator|->
name|tag
argument_list|()
operator|==
name|tag
condition|)
return|return
name|menu
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|parentWindow
name|QWindow
modifier|*
name|QAndroidPlatformMenuBar
operator|::
name|parentWindow
parameter_list|()
specifier|const
block|{
return|return
name|m_parentWindow
return|;
block|}
end_function
begin_function
DECL|function|menus
name|QAndroidPlatformMenuBar
operator|::
name|PlatformMenusType
name|QAndroidPlatformMenuBar
operator|::
name|menus
parameter_list|()
specifier|const
block|{
return|return
name|m_menus
return|;
block|}
end_function
begin_function
DECL|function|menusListMutex
name|QMutex
modifier|*
name|QAndroidPlatformMenuBar
operator|::
name|menusListMutex
parameter_list|()
block|{
return|return
operator|&
name|m_menusListMutex
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
