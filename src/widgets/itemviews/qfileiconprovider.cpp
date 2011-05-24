begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfileiconprovider.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILEICONPROVIDER
end_ifndef
begin_include
include|#
directive|include
file|<qstyle.h>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qpixmapcache.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
end_if
begin_define
DECL|macro|_WIN32_IE
define|#
directive|define
name|_WIN32_IE
value|0x0500
end_define
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<commctrl.h>
end_include
begin_include
include|#
directive|include
file|<objbase.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<private/qt_cocoa_helpers_mac_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<private/qfunctions_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiplatformplugin_p.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_NO_STYLE_GTK
argument_list|)
end_if
begin_include
include|#
directive|include
file|<private/qgtkstyle_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qt_x11_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SHGFI_ADDOVERLAYS
end_ifndef
begin_define
DECL|macro|SHGFI_ADDOVERLAYS
define|#
directive|define
name|SHGFI_ADDOVERLAYS
value|0x000000020
end_define
begin_define
DECL|macro|SHGFI_OVERLAYINDEX
define|#
directive|define
name|SHGFI_OVERLAYINDEX
value|0x000000040
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!   \class QFileIconProvider    \brief The QFileIconProvider class provides file icons for the QDirModel and the QFileSystemModel classes. */
end_comment
begin_comment
comment|/*!   \enum QFileIconProvider::IconType   \value Computer   \value Desktop   \value Trashcan   \value Network   \value Drive   \value Folder   \value File */
end_comment
begin_class
DECL|class|QFileIconProviderPrivate
class|class
name|QFileIconProviderPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QFileIconProvider
parameter_list|)
specifier|public
private|:
name|QFileIconProviderPrivate
parameter_list|()
constructor_decl|;
name|QIcon
name|getIcon
parameter_list|(
name|QStyle
operator|::
name|StandardPixmap
name|name
parameter_list|)
specifier|const
function_decl|;
ifdef|#
directive|ifdef
name|Q_WS_WIN
name|QIcon
name|getWinIcon
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fi
parameter_list|)
specifier|const
function_decl|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
name|QIcon
name|getMacIcon
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fi
parameter_list|)
specifier|const
function_decl|;
endif|#
directive|endif
DECL|member|q_ptr
name|QFileIconProvider
modifier|*
name|q_ptr
decl_stmt|;
DECL|member|homePath
specifier|const
name|QString
name|homePath
decl_stmt|;
private|private:
DECL|member|file
specifier|mutable
name|QIcon
name|file
decl_stmt|;
DECL|member|fileLink
specifier|mutable
name|QIcon
name|fileLink
decl_stmt|;
DECL|member|directory
specifier|mutable
name|QIcon
name|directory
decl_stmt|;
DECL|member|directoryLink
specifier|mutable
name|QIcon
name|directoryLink
decl_stmt|;
DECL|member|harddisk
specifier|mutable
name|QIcon
name|harddisk
decl_stmt|;
DECL|member|floppy
specifier|mutable
name|QIcon
name|floppy
decl_stmt|;
DECL|member|cdrom
specifier|mutable
name|QIcon
name|cdrom
decl_stmt|;
DECL|member|ram
specifier|mutable
name|QIcon
name|ram
decl_stmt|;
DECL|member|network
specifier|mutable
name|QIcon
name|network
decl_stmt|;
DECL|member|computer
specifier|mutable
name|QIcon
name|computer
decl_stmt|;
DECL|member|desktop
specifier|mutable
name|QIcon
name|desktop
decl_stmt|;
DECL|member|trashcan
specifier|mutable
name|QIcon
name|trashcan
decl_stmt|;
DECL|member|generic
specifier|mutable
name|QIcon
name|generic
decl_stmt|;
DECL|member|home
specifier|mutable
name|QIcon
name|home
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QFileIconProviderPrivate
name|QFileIconProviderPrivate
operator|::
name|QFileIconProviderPrivate
parameter_list|()
member_init_list|:
name|homePath
argument_list|(
name|QDir
operator|::
name|home
argument_list|()
operator|.
name|absolutePath
argument_list|()
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|getIcon
name|QIcon
name|QFileIconProviderPrivate
operator|::
name|getIcon
parameter_list|(
name|QStyle
operator|::
name|StandardPixmap
name|name
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|name
condition|)
block|{
case|case
name|QStyle
operator|::
name|SP_FileIcon
case|:
if|if
condition|(
name|file
operator|.
name|isNull
argument_list|()
condition|)
name|file
operator|=
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
name|file
return|;
case|case
name|QStyle
operator|::
name|SP_FileLinkIcon
case|:
if|if
condition|(
name|fileLink
operator|.
name|isNull
argument_list|()
condition|)
name|fileLink
operator|=
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
name|fileLink
return|;
case|case
name|QStyle
operator|::
name|SP_DirIcon
case|:
if|if
condition|(
name|directory
operator|.
name|isNull
argument_list|()
condition|)
name|directory
operator|=
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
name|directory
return|;
case|case
name|QStyle
operator|::
name|SP_DirLinkIcon
case|:
if|if
condition|(
name|directoryLink
operator|.
name|isNull
argument_list|()
condition|)
name|directoryLink
operator|=
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
name|directoryLink
return|;
case|case
name|QStyle
operator|::
name|SP_DriveHDIcon
case|:
if|if
condition|(
name|harddisk
operator|.
name|isNull
argument_list|()
condition|)
name|harddisk
operator|=
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
name|harddisk
return|;
case|case
name|QStyle
operator|::
name|SP_DriveFDIcon
case|:
if|if
condition|(
name|floppy
operator|.
name|isNull
argument_list|()
condition|)
name|floppy
operator|=
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
name|floppy
return|;
case|case
name|QStyle
operator|::
name|SP_DriveCDIcon
case|:
if|if
condition|(
name|cdrom
operator|.
name|isNull
argument_list|()
condition|)
name|cdrom
operator|=
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
name|cdrom
return|;
case|case
name|QStyle
operator|::
name|SP_DriveNetIcon
case|:
if|if
condition|(
name|network
operator|.
name|isNull
argument_list|()
condition|)
name|network
operator|=
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
name|network
return|;
case|case
name|QStyle
operator|::
name|SP_ComputerIcon
case|:
if|if
condition|(
name|computer
operator|.
name|isNull
argument_list|()
condition|)
name|computer
operator|=
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
name|computer
return|;
case|case
name|QStyle
operator|::
name|SP_DesktopIcon
case|:
if|if
condition|(
name|desktop
operator|.
name|isNull
argument_list|()
condition|)
name|desktop
operator|=
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
name|desktop
return|;
case|case
name|QStyle
operator|::
name|SP_TrashIcon
case|:
if|if
condition|(
name|trashcan
operator|.
name|isNull
argument_list|()
condition|)
name|trashcan
operator|=
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
name|trashcan
return|;
case|case
name|QStyle
operator|::
name|SP_DirHomeIcon
case|:
if|if
condition|(
name|home
operator|.
name|isNull
argument_list|()
condition|)
name|home
operator|=
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
name|home
return|;
default|default:
return|return
name|QIcon
argument_list|()
return|;
block|}
return|return
name|QIcon
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   Constructs a file icon provider. */
end_comment
begin_constructor
DECL|function|QFileIconProvider
name|QFileIconProvider
operator|::
name|QFileIconProvider
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QFileIconProviderPrivate
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Destroys the file icon provider.  */
end_comment
begin_destructor
DECL|function|~QFileIconProvider
name|QFileIconProvider
operator|::
name|~
name|QFileIconProvider
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!   Returns an icon set for the given \a type. */
end_comment
begin_function
DECL|function|icon
name|QIcon
name|QFileIconProvider
operator|::
name|icon
parameter_list|(
name|IconType
name|type
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFileIconProvider
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|Computer
case|:
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_ComputerIcon
argument_list|)
return|;
case|case
name|Desktop
case|:
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_DesktopIcon
argument_list|)
return|;
case|case
name|Trashcan
case|:
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_TrashIcon
argument_list|)
return|;
case|case
name|Network
case|:
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_DriveNetIcon
argument_list|)
return|;
case|case
name|Drive
case|:
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_DriveHDIcon
argument_list|)
return|;
case|case
name|Folder
case|:
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_DirIcon
argument_list|)
return|;
case|case
name|File
case|:
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_FileIcon
argument_list|)
return|;
default|default:
break|break;
block|}
empty_stmt|;
return|return
name|QIcon
argument_list|()
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WIN
end_ifdef
begin_function
DECL|function|getWinIcon
name|QIcon
name|QFileIconProviderPrivate
operator|::
name|getWinIcon
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fileInfo
parameter_list|)
specifier|const
block|{
name|QIcon
name|retIcon
decl_stmt|;
specifier|const
name|QString
name|fileExtension
init|=
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
operator|+
name|fileInfo
operator|.
name|suffix
argument_list|()
operator|.
name|toUpper
argument_list|()
decl_stmt|;
name|QString
name|key
decl_stmt|;
if|if
condition|(
name|fileInfo
operator|.
name|isFile
argument_list|()
operator|&&
operator|!
name|fileInfo
operator|.
name|isExecutable
argument_list|()
operator|&&
operator|!
name|fileInfo
operator|.
name|isSymLink
argument_list|()
operator|&&
name|fileExtension
operator|!=
name|QLatin1String
argument_list|(
literal|".ICO"
argument_list|)
condition|)
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"qt_"
argument_list|)
operator|+
name|fileExtension
expr_stmt|;
name|QPixmap
name|pixmap
decl_stmt|;
if|if
condition|(
operator|!
name|key
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QPixmapCache
operator|::
name|find
argument_list|(
name|key
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|pixmap
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|retIcon
operator|.
name|addPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
if|if
condition|(
name|QPixmapCache
operator|::
name|find
argument_list|(
name|key
operator|+
name|QLatin1Char
argument_list|(
literal|'l'
argument_list|)
argument_list|,
name|pixmap
argument_list|)
condition|)
name|retIcon
operator|.
name|addPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
return|return
name|retIcon
return|;
block|}
comment|/* We don't use the variable, but by storing it statically, we      * ensure CoInitialize is only called once. */
specifier|static
name|HRESULT
name|comInit
init|=
name|CoInitialize
argument_list|(
name|NULL
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|comInit
argument_list|)
expr_stmt|;
name|SHFILEINFO
name|info
decl_stmt|;
name|unsigned
name|long
name|val
init|=
literal|0
decl_stmt|;
comment|//Get the small icon
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|val
operator|=
name|SHGetFileInfo
argument_list|(
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fileInfo
operator|.
name|filePath
argument_list|()
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|,
literal|0
argument_list|,
operator|&
name|info
argument_list|,
sizeof|sizeof
argument_list|(
name|SHFILEINFO
argument_list|)
argument_list|,
name|SHGFI_ICON
operator||
name|SHGFI_SMALLICON
operator||
name|SHGFI_SYSICONINDEX
operator||
name|SHGFI_ADDOVERLAYS
operator||
name|SHGFI_OVERLAYINDEX
argument_list|)
expr_stmt|;
else|#
directive|else
name|val
operator|=
name|SHGetFileInfo
argument_list|(
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fileInfo
operator|.
name|filePath
argument_list|()
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|,
literal|0
argument_list|,
operator|&
name|info
argument_list|,
sizeof|sizeof
argument_list|(
name|SHFILEINFO
argument_list|)
argument_list|,
name|SHGFI_SMALLICON
operator||
name|SHGFI_SYSICONINDEX
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Even if GetFileInfo returns a valid result, hIcon can be empty in some cases
if|if
condition|(
name|val
operator|&&
name|info
operator|.
name|hIcon
condition|)
block|{
if|if
condition|(
name|fileInfo
operator|.
name|isDir
argument_list|()
operator|&&
operator|!
name|fileInfo
operator|.
name|isRoot
argument_list|()
condition|)
block|{
comment|//using the unique icon index provided by windows save us from duplicate keys
name|key
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"qt_dir_%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|info
operator|.
name|iIcon
argument_list|)
expr_stmt|;
name|QPixmapCache
operator|::
name|find
argument_list|(
name|key
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|pixmap
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|retIcon
operator|.
name|addPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
if|if
condition|(
name|QPixmapCache
operator|::
name|find
argument_list|(
name|key
operator|+
name|QLatin1Char
argument_list|(
literal|'l'
argument_list|)
argument_list|,
name|pixmap
argument_list|)
condition|)
name|retIcon
operator|.
name|addPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
name|DestroyIcon
argument_list|(
name|info
operator|.
name|hIcon
argument_list|)
expr_stmt|;
return|return
name|retIcon
return|;
block|}
block|}
if|if
condition|(
name|pixmap
operator|.
name|isNull
argument_list|()
condition|)
block|{
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|pixmap
operator|=
name|QPixmap
operator|::
name|fromWinHICON
argument_list|(
name|info
operator|.
name|hIcon
argument_list|)
expr_stmt|;
else|#
directive|else
name|pixmap
operator|=
name|QPixmap
operator|::
name|fromWinHICON
argument_list|(
name|ImageList_GetIcon
argument_list|(
operator|(
name|HIMAGELIST
operator|)
name|val
argument_list|,
name|info
operator|.
name|iIcon
argument_list|,
name|ILD_NORMAL
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|pixmap
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|retIcon
operator|.
name|addPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|key
operator|.
name|isEmpty
argument_list|()
condition|)
name|QPixmapCache
operator|::
name|insert
argument_list|(
name|key
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QFileIconProviderPrivate::getWinIcon() no small icon found"
argument_list|)
expr_stmt|;
block|}
block|}
name|DestroyIcon
argument_list|(
name|info
operator|.
name|hIcon
argument_list|)
expr_stmt|;
block|}
comment|//Get the big icon
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|val
operator|=
name|SHGetFileInfo
argument_list|(
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fileInfo
operator|.
name|filePath
argument_list|()
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|,
literal|0
argument_list|,
operator|&
name|info
argument_list|,
sizeof|sizeof
argument_list|(
name|SHFILEINFO
argument_list|)
argument_list|,
name|SHGFI_ICON
operator||
name|SHGFI_LARGEICON
operator||
name|SHGFI_SYSICONINDEX
operator||
name|SHGFI_ADDOVERLAYS
operator||
name|SHGFI_OVERLAYINDEX
argument_list|)
expr_stmt|;
else|#
directive|else
name|val
operator|=
name|SHGetFileInfo
argument_list|(
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fileInfo
operator|.
name|filePath
argument_list|()
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|,
literal|0
argument_list|,
operator|&
name|info
argument_list|,
sizeof|sizeof
argument_list|(
name|SHFILEINFO
argument_list|)
argument_list|,
name|SHGFI_LARGEICON
operator||
name|SHGFI_SYSICONINDEX
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|val
operator|&&
name|info
operator|.
name|hIcon
condition|)
block|{
if|if
condition|(
name|fileInfo
operator|.
name|isDir
argument_list|()
operator|&&
operator|!
name|fileInfo
operator|.
name|isRoot
argument_list|()
condition|)
block|{
comment|//using the unique icon index provided by windows save us from duplicate keys
name|key
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"qt_dir_%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|info
operator|.
name|iIcon
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|pixmap
operator|=
name|QPixmap
operator|::
name|fromWinHICON
argument_list|(
name|info
operator|.
name|hIcon
argument_list|)
expr_stmt|;
else|#
directive|else
name|pixmap
operator|=
name|QPixmap
operator|::
name|fromWinHICON
argument_list|(
name|ImageList_GetIcon
argument_list|(
operator|(
name|HIMAGELIST
operator|)
name|val
argument_list|,
name|info
operator|.
name|iIcon
argument_list|,
name|ILD_NORMAL
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|pixmap
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|retIcon
operator|.
name|addPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|key
operator|.
name|isEmpty
argument_list|()
condition|)
name|QPixmapCache
operator|::
name|insert
argument_list|(
name|key
operator|+
name|QLatin1Char
argument_list|(
literal|'l'
argument_list|)
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QFileIconProviderPrivate::getWinIcon() no large icon found"
argument_list|)
expr_stmt|;
block|}
name|DestroyIcon
argument_list|(
name|info
operator|.
name|hIcon
argument_list|)
expr_stmt|;
block|}
return|return
name|retIcon
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
end_elif
begin_function
DECL|function|getMacIcon
name|QIcon
name|QFileIconProviderPrivate
operator|::
name|getMacIcon
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fi
parameter_list|)
specifier|const
block|{
name|QIcon
name|retIcon
decl_stmt|;
name|QString
name|fileExtension
init|=
name|fi
operator|.
name|suffix
argument_list|()
operator|.
name|toUpper
argument_list|()
decl_stmt|;
name|fileExtension
operator|.
name|prepend
argument_list|(
name|QLatin1String
argument_list|(
literal|"."
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|keyBase
init|=
name|QLatin1String
argument_list|(
literal|"qt_"
argument_list|)
operator|+
name|fileExtension
decl_stmt|;
name|QPixmap
name|pixmap
decl_stmt|;
if|if
condition|(
name|fi
operator|.
name|isFile
argument_list|()
operator|&&
operator|!
name|fi
operator|.
name|isExecutable
argument_list|()
operator|&&
operator|!
name|fi
operator|.
name|isSymLink
argument_list|()
condition|)
block|{
name|QPixmapCache
operator|::
name|find
argument_list|(
name|keyBase
operator|+
name|QLatin1String
argument_list|(
literal|"16"
argument_list|)
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|pixmap
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|retIcon
operator|.
name|addPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
if|if
condition|(
name|QPixmapCache
operator|::
name|find
argument_list|(
name|keyBase
operator|+
name|QLatin1String
argument_list|(
literal|"32"
argument_list|)
argument_list|,
name|pixmap
argument_list|)
condition|)
block|{
name|retIcon
operator|.
name|addPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
if|if
condition|(
name|QPixmapCache
operator|::
name|find
argument_list|(
name|keyBase
operator|+
name|QLatin1String
argument_list|(
literal|"64"
argument_list|)
argument_list|,
name|pixmap
argument_list|)
condition|)
block|{
name|retIcon
operator|.
name|addPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
if|if
condition|(
name|QPixmapCache
operator|::
name|find
argument_list|(
name|keyBase
operator|+
name|QLatin1String
argument_list|(
literal|"128"
argument_list|)
argument_list|,
name|pixmap
argument_list|)
condition|)
block|{
name|retIcon
operator|.
name|addPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
return|return
name|retIcon
return|;
block|}
block|}
block|}
block|}
name|FSRef
name|macRef
decl_stmt|;
name|OSStatus
name|status
init|=
name|FSPathMakeRef
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|UInt8
operator|*
argument_list|>
argument_list|(
name|fi
operator|.
name|canonicalFilePath
argument_list|()
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|,
operator|&
name|macRef
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|status
operator|!=
name|noErr
condition|)
return|return
name|retIcon
return|;
name|FSCatalogInfo
name|info
decl_stmt|;
name|HFSUniStr255
name|macName
decl_stmt|;
name|status
operator|=
name|FSGetCatalogInfo
argument_list|(
operator|&
name|macRef
argument_list|,
name|kIconServicesCatalogInfoMask
argument_list|,
operator|&
name|info
argument_list|,
operator|&
name|macName
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
name|noErr
condition|)
return|return
name|retIcon
return|;
name|IconRef
name|iconRef
decl_stmt|;
name|SInt16
name|iconLabel
decl_stmt|;
name|status
operator|=
name|GetIconRefFromFileInfo
argument_list|(
operator|&
name|macRef
argument_list|,
name|macName
operator|.
name|length
argument_list|,
name|macName
operator|.
name|unicode
argument_list|,
name|kIconServicesCatalogInfoMask
argument_list|,
operator|&
name|info
argument_list|,
name|kIconServicesNormalUsageFlag
argument_list|,
operator|&
name|iconRef
argument_list|,
operator|&
name|iconLabel
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
name|noErr
condition|)
return|return
name|retIcon
return|;
name|qt_mac_constructQIconFromIconRef
argument_list|(
name|iconRef
argument_list|,
literal|0
argument_list|,
operator|&
name|retIcon
argument_list|)
expr_stmt|;
name|ReleaseIconRef
argument_list|(
name|iconRef
argument_list|)
expr_stmt|;
name|pixmap
operator|=
name|retIcon
operator|.
name|pixmap
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|QPixmapCache
operator|::
name|insert
argument_list|(
name|keyBase
operator|+
name|QLatin1String
argument_list|(
literal|"16"
argument_list|)
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
name|pixmap
operator|=
name|retIcon
operator|.
name|pixmap
argument_list|(
literal|32
argument_list|)
expr_stmt|;
name|QPixmapCache
operator|::
name|insert
argument_list|(
name|keyBase
operator|+
name|QLatin1String
argument_list|(
literal|"32"
argument_list|)
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
name|pixmap
operator|=
name|retIcon
operator|.
name|pixmap
argument_list|(
literal|64
argument_list|)
expr_stmt|;
name|QPixmapCache
operator|::
name|insert
argument_list|(
name|keyBase
operator|+
name|QLatin1String
argument_list|(
literal|"64"
argument_list|)
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
name|pixmap
operator|=
name|retIcon
operator|.
name|pixmap
argument_list|(
literal|128
argument_list|)
expr_stmt|;
name|QPixmapCache
operator|::
name|insert
argument_list|(
name|keyBase
operator|+
name|QLatin1String
argument_list|(
literal|"128"
argument_list|)
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
return|return
name|retIcon
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!   Returns an icon for the file described by \a info. */
end_comment
begin_function
DECL|function|icon
name|QIcon
name|QFileIconProvider
operator|::
name|icon
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|info
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFileIconProvider
argument_list|)
expr_stmt|;
name|QIcon
name|platformIcon
init|=
name|qt_guiPlatformPlugin
argument_list|()
operator|->
name|fileSystemIcon
argument_list|(
name|info
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|platformIcon
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|platformIcon
return|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_STYLE_GTK
argument_list|)
if|if
condition|(
name|X11
operator|->
name|desktopEnvironment
operator|==
name|DE_GNOME
condition|)
block|{
name|QIcon
name|gtkIcon
init|=
name|QGtkStylePrivate
operator|::
name|getFilesystemIcon
argument_list|(
name|info
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|gtkIcon
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|gtkIcon
return|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_WS_MAC
name|QIcon
name|retIcon
init|=
name|d
operator|->
name|getMacIcon
argument_list|(
name|info
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|retIcon
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|retIcon
return|;
elif|#
directive|elif
name|defined
name|Q_WS_WIN
name|QIcon
name|icon
init|=
name|d
operator|->
name|getWinIcon
argument_list|(
name|info
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|icon
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|icon
return|;
endif|#
directive|endif
if|if
condition|(
name|info
operator|.
name|isRoot
argument_list|()
condition|)
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_WS_WINCE
argument_list|)
block|{
name|UINT
name|type
init|=
name|GetDriveType
argument_list|(
operator|(
name|wchar_t
operator|*
operator|)
name|info
operator|.
name|absoluteFilePath
argument_list|()
operator|.
name|utf16
argument_list|()
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|DRIVE_REMOVABLE
case|:
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_DriveFDIcon
argument_list|)
return|;
case|case
name|DRIVE_FIXED
case|:
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_DriveHDIcon
argument_list|)
return|;
case|case
name|DRIVE_REMOTE
case|:
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_DriveNetIcon
argument_list|)
return|;
case|case
name|DRIVE_CDROM
case|:
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_DriveCDIcon
argument_list|)
return|;
case|case
name|DRIVE_RAMDISK
case|:
case|case
name|DRIVE_UNKNOWN
case|:
case|case
name|DRIVE_NO_ROOT_DIR
case|:
default|default:
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_DriveHDIcon
argument_list|)
return|;
block|}
block|}
else|#
directive|else
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_DriveHDIcon
argument_list|)
return|;
endif|#
directive|endif
if|if
condition|(
name|info
operator|.
name|isFile
argument_list|()
condition|)
block|{
if|if
condition|(
name|info
operator|.
name|isSymLink
argument_list|()
condition|)
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_FileLinkIcon
argument_list|)
return|;
else|else
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_FileIcon
argument_list|)
return|;
block|}
if|if
condition|(
name|info
operator|.
name|isDir
argument_list|()
condition|)
block|{
if|if
condition|(
name|info
operator|.
name|isSymLink
argument_list|()
condition|)
block|{
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_DirLinkIcon
argument_list|)
return|;
block|}
else|else
block|{
if|if
condition|(
name|info
operator|.
name|absoluteFilePath
argument_list|()
operator|==
name|d
operator|->
name|homePath
condition|)
block|{
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_DirHomeIcon
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|d
operator|->
name|getIcon
argument_list|(
name|QStyle
operator|::
name|SP_DirIcon
argument_list|)
return|;
block|}
block|}
block|}
return|return
name|QIcon
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the type of the file described by \a info. */
end_comment
begin_function
DECL|function|type
name|QString
name|QFileIconProvider
operator|::
name|type
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|info
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|info
operator|.
name|isRoot
argument_list|()
condition|)
return|return
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QFileDialog"
argument_list|,
literal|"Drive"
argument_list|)
return|;
if|if
condition|(
name|info
operator|.
name|isFile
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|info
operator|.
name|suffix
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|info
operator|.
name|suffix
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
operator|+
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QFileDialog"
argument_list|,
literal|"File"
argument_list|)
return|;
return|return
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QFileDialog"
argument_list|,
literal|"File"
argument_list|)
return|;
block|}
if|if
condition|(
name|info
operator|.
name|isDir
argument_list|()
condition|)
ifdef|#
directive|ifdef
name|Q_WS_WIN
return|return
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QFileDialog"
argument_list|,
literal|"File Folder"
argument_list|,
literal|"Match Windows Explorer"
argument_list|)
return|;
else|#
directive|else
return|return
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QFileDialog"
argument_list|,
literal|"Folder"
argument_list|,
literal|"All other platforms"
argument_list|)
return|;
endif|#
directive|endif
comment|// Windows   - "File Folder"
comment|// OS X      - "Folder"
comment|// Konqueror - "Folder"
comment|// Nautilus  - "folder"
if|if
condition|(
name|info
operator|.
name|isSymLink
argument_list|()
condition|)
ifdef|#
directive|ifdef
name|Q_OS_MAC
return|return
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QFileDialog"
argument_list|,
literal|"Alias"
argument_list|,
literal|"Mac OS X Finder"
argument_list|)
return|;
else|#
directive|else
return|return
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QFileDialog"
argument_list|,
literal|"Shortcut"
argument_list|,
literal|"All other platforms"
argument_list|)
return|;
endif|#
directive|endif
comment|// OS X      - "Alias"
comment|// Windows   - "Shortcut"
comment|// Konqueror - "Folder" or "TXT File" i.e. what it is pointing to
comment|// Nautilus  - "link to folder" or "link to object file", same as Konqueror
return|return
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QFileDialog"
argument_list|,
literal|"Unknown"
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
