begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfileiconprovider.h"
end_include
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
begin_include
include|#
directive|include
file|<private/qfunctions_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformservices.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformtheme.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
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
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_STYLE_GTK
argument_list|)
end_if
begin_include
include|#
directive|include
file|<private/qgtkstyle_p_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!   \class QFileIconProvider    \inmodule QtWidgets    \brief The QFileIconProvider class provides file icons for the QDirModel and the QFileSystemModel classes. */
end_comment
begin_comment
comment|/*!   \enum QFileIconProvider::IconType   \value Computer   \value Desktop   \value Trashcan   \value Network   \value Drive   \value Folder   \value File */
end_comment
begin_comment
comment|/*!     \enum QFileIconProvider::Option     \since 5.2      \value DontUseCustomDirectoryIcons Always use the default directory icon.     Some platforms allow the user to set a different icon. Custom icon lookup     cause a big performance impact over network or removable drives. */
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
name|QIcon
name|getIcon
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fi
parameter_list|)
specifier|const
function_decl|;
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
DECL|member|options
name|QFileIconProvider
operator|::
name|Options
name|options
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
comment|/*!     \since 5.2     Sets \a options that affect the icon provider.     \sa options() */
end_comment
begin_function
DECL|function|setOptions
name|void
name|QFileIconProvider
operator|::
name|setOptions
parameter_list|(
name|QFileIconProvider
operator|::
name|Options
name|options
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFileIconProvider
argument_list|)
expr_stmt|;
name|d
operator|->
name|options
operator|=
name|options
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 5.2     Returns all the options that affect the icon provider.     By default, all options are disabled.     \sa setOptions() */
end_comment
begin_function
DECL|function|options
name|QFileIconProvider
operator|::
name|Options
name|QFileIconProvider
operator|::
name|options
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFileIconProvider
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|options
return|;
block|}
end_function
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
begin_function
DECL|function|isCacheable
specifier|static
name|bool
name|isCacheable
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fi
parameter_list|)
block|{
if|if
condition|(
operator|!
name|fi
operator|.
name|isFile
argument_list|()
condition|)
return|return
literal|false
return|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
comment|// On windows it's faster to just look at the file extensions. QTBUG-13182
specifier|const
name|QString
name|fileExtension
init|=
name|fi
operator|.
name|suffix
argument_list|()
decl_stmt|;
comment|// Will return false for .exe, .lnk and .ico extensions
return|return
name|fileExtension
operator|.
name|compare
argument_list|(
name|QLatin1String
argument_list|(
literal|"exe"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|&&
name|fileExtension
operator|.
name|compare
argument_list|(
name|QLatin1String
argument_list|(
literal|"lnk"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|&&
name|fileExtension
operator|.
name|compare
argument_list|(
name|QLatin1String
argument_list|(
literal|"ico"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
return|;
else|#
directive|else
return|return
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
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|getIcon
name|QIcon
name|QFileIconProviderPrivate
operator|::
name|getIcon
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
specifier|const
name|QPlatformTheme
modifier|*
name|theme
init|=
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|theme
condition|)
return|return
name|retIcon
return|;
name|QList
argument_list|<
name|int
argument_list|>
name|sizes
init|=
name|theme
operator|->
name|themeHint
argument_list|(
name|QPlatformTheme
operator|::
name|IconPixmapSizes
argument_list|)
operator|.
name|value
argument_list|<
name|QList
argument_list|<
name|int
argument_list|>
argument_list|>
argument_list|()
decl_stmt|;
if|if
condition|(
name|sizes
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|retIcon
return|;
specifier|const
name|QString
name|keyBase
init|=
name|QLatin1String
argument_list|(
literal|"qt_."
argument_list|)
operator|+
name|fi
operator|.
name|suffix
argument_list|()
operator|.
name|toUpper
argument_list|()
decl_stmt|;
name|bool
name|cacheable
init|=
name|isCacheable
argument_list|(
name|fi
argument_list|)
decl_stmt|;
if|if
condition|(
name|cacheable
condition|)
block|{
name|QPixmap
name|pixmap
decl_stmt|;
name|QPixmapCache
operator|::
name|find
argument_list|(
name|keyBase
operator|+
name|QString
operator|::
name|number
argument_list|(
name|sizes
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
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
name|bool
name|iconIsComplete
init|=
literal|true
decl_stmt|;
name|retIcon
operator|.
name|addPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|sizes
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|QPixmapCache
operator|::
name|find
argument_list|(
name|keyBase
operator|+
name|QString
operator|::
name|number
argument_list|(
name|sizes
operator|.
name|at
argument_list|(
name|i
argument_list|)
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
block|}
else|else
block|{
name|iconIsComplete
operator|=
literal|false
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|iconIsComplete
condition|)
return|return
name|retIcon
return|;
block|}
block|}
name|QPlatformTheme
operator|::
name|IconOptions
name|iconOptions
decl_stmt|;
if|if
condition|(
name|options
operator|&
name|QFileIconProvider
operator|::
name|DontUseCustomDirectoryIcons
condition|)
name|iconOptions
operator||=
name|QPlatformTheme
operator|::
name|DontUseCustomDirectoryIcons
expr_stmt|;
name|Q_FOREACH
argument_list|(
argument|int size
argument_list|,
argument|sizes
argument_list|)
block|{
name|QPixmap
name|pixmap
init|=
name|theme
operator|->
name|fileIconPixmap
argument_list|(
name|fi
argument_list|,
name|QSizeF
argument_list|(
name|size
argument_list|,
name|size
argument_list|)
argument_list|,
name|iconOptions
argument_list|)
decl_stmt|;
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
name|cacheable
condition|)
name|QPixmapCache
operator|::
name|insert
argument_list|(
name|keyBase
operator|+
name|QString
operator|::
name|number
argument_list|(
name|size
argument_list|)
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|retIcon
return|;
block|}
end_function
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
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_STYLE_GTK
argument_list|)
specifier|const
name|QByteArray
name|desktopEnvironment
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|services
argument_list|()
operator|->
name|desktopEnvironment
argument_list|()
decl_stmt|;
if|if
condition|(
name|desktopEnvironment
operator|!=
name|QByteArrayLiteral
argument_list|(
literal|"KDE"
argument_list|)
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
name|QIcon
name|retIcon
init|=
name|d
operator|->
name|getIcon
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
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
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
name|Q_OS_WIN
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
end_unit
