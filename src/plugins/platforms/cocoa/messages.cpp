begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"messages.h"
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_comment
comment|// Translatable messages should go into this .cpp file for them to be picked up by lupdate.
end_comment
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|msgAboutQt
name|QString
name|msgAboutQt
parameter_list|()
block|{
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QCocoaMenuItem"
argument_list|,
literal|"About Qt"
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|application_menu_strings
specifier|static
specifier|const
name|char
modifier|*
name|application_menu_strings
index|[]
init|=
block|{
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"MAC_APPLICATION_MENU"
argument_list|,
literal|"Services"
argument_list|)
block|,
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"MAC_APPLICATION_MENU"
argument_list|,
literal|"Hide %1"
argument_list|)
block|,
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"MAC_APPLICATION_MENU"
argument_list|,
literal|"Hide Others"
argument_list|)
block|,
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"MAC_APPLICATION_MENU"
argument_list|,
literal|"Show All"
argument_list|)
block|,
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"MAC_APPLICATION_MENU"
argument_list|,
literal|"Preferences..."
argument_list|)
block|,
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"MAC_APPLICATION_MENU"
argument_list|,
literal|"Quit %1"
argument_list|)
block|,
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"MAC_APPLICATION_MENU"
argument_list|,
literal|"About %1"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qt_mac_applicationmenu_string
name|QString
name|qt_mac_applicationmenu_string
parameter_list|(
name|int
name|type
parameter_list|)
block|{
name|QString
name|menuString
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|application_menu_strings
index|[
name|type
index|]
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|translated
init|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QMenuBar"
argument_list|,
name|application_menu_strings
index|[
name|type
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|translated
operator|!=
name|menuString
condition|)
block|{
return|return
name|translated
return|;
block|}
else|else
block|{
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"MAC_APPLICATION_MENU"
argument_list|,
name|application_menu_strings
index|[
name|type
index|]
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|detectMenuRole
name|QPlatformMenuItem
operator|::
name|MenuRole
name|detectMenuRole
parameter_list|(
specifier|const
name|QString
modifier|&
name|caption
parameter_list|)
block|{
name|QString
name|captionNoAmpersand
argument_list|(
name|caption
argument_list|)
decl_stmt|;
name|captionNoAmpersand
operator|.
name|remove
argument_list|(
name|QChar
argument_list|(
literal|'&'
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|aboutString
init|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QCocoaMenuItem"
argument_list|,
literal|"About"
argument_list|)
decl_stmt|;
if|if
condition|(
name|captionNoAmpersand
operator|.
name|startsWith
argument_list|(
name|aboutString
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|||
name|caption
operator|.
name|endsWith
argument_list|(
name|aboutString
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
return|return
name|QPlatformMenuItem
operator|::
name|AboutRole
return|;
if|if
condition|(
name|captionNoAmpersand
operator|.
name|startsWith
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QCocoaMenuItem"
argument_list|,
literal|"Config"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|||
name|captionNoAmpersand
operator|.
name|startsWith
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QCocoaMenuItem"
argument_list|,
literal|"Preference"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|||
name|captionNoAmpersand
operator|.
name|startsWith
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QCocoaMenuItem"
argument_list|,
literal|"Options"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|||
name|captionNoAmpersand
operator|.
name|startsWith
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QCocoaMenuItem"
argument_list|,
literal|"Setting"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|||
name|captionNoAmpersand
operator|.
name|startsWith
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QCocoaMenuItem"
argument_list|,
literal|"Setup"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
block|{
return|return
name|QPlatformMenuItem
operator|::
name|PreferencesRole
return|;
block|}
if|if
condition|(
name|captionNoAmpersand
operator|.
name|startsWith
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QCocoaMenuItem"
argument_list|,
literal|"Quit"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|||
name|captionNoAmpersand
operator|.
name|startsWith
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QCocoaMenuItem"
argument_list|,
literal|"Exit"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
block|{
return|return
name|QPlatformMenuItem
operator|::
name|QuitRole
return|;
block|}
if|if
condition|(
operator|!
name|captionNoAmpersand
operator|.
name|compare
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QCocoaMenuItem"
argument_list|,
literal|"Cut"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
return|return
name|QPlatformMenuItem
operator|::
name|CutRole
return|;
if|if
condition|(
operator|!
name|captionNoAmpersand
operator|.
name|compare
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QCocoaMenuItem"
argument_list|,
literal|"Copy"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
return|return
name|QPlatformMenuItem
operator|::
name|CopyRole
return|;
if|if
condition|(
operator|!
name|captionNoAmpersand
operator|.
name|compare
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QCocoaMenuItem"
argument_list|,
literal|"Paste"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
return|return
name|QPlatformMenuItem
operator|::
name|PasteRole
return|;
if|if
condition|(
operator|!
name|captionNoAmpersand
operator|.
name|compare
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QCocoaMenuItem"
argument_list|,
literal|"Select All"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
return|return
name|QPlatformMenuItem
operator|::
name|SelectAllRole
return|;
return|return
name|QPlatformMenuItem
operator|::
name|NoRole
return|;
block|}
end_function
begin_function
DECL|function|msgDialogButtonDiscard
name|QString
name|msgDialogButtonDiscard
parameter_list|()
block|{
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QCocoaTheme"
argument_list|,
literal|"Don't Save"
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
