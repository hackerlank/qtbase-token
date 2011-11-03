begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qstandardpaths.h"
end_include
begin_include
include|#
directive|include
file|<qprocess.h>
end_include
begin_include
include|#
directive|include
file|<qurl.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<private/qfilesystemengine_p.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STANDARDPATHS
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|writableLocation
name|QString
name|QStandardPaths
operator|::
name|writableLocation
parameter_list|(
name|StandardLocation
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|HomeLocation
case|:
return|return
name|QDir
operator|::
name|homePath
argument_list|()
return|;
case|case
name|TempLocation
case|:
return|return
name|QDir
operator|::
name|tempPath
argument_list|()
return|;
case|case
name|CacheLocation
case|:
block|{
comment|// http://standards.freedesktop.org/basedir-spec/basedir-spec-0.6.html
name|QString
name|xdgCacheHome
init|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|qgetenv
argument_list|(
literal|"XDG_CACHE_HOME"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|xdgCacheHome
operator|.
name|isEmpty
argument_list|()
condition|)
name|xdgCacheHome
operator|=
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/.cache"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QCoreApplication
operator|::
name|organizationName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|xdgCacheHome
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|QCoreApplication
operator|::
name|organizationName
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|xdgCacheHome
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
expr_stmt|;
return|return
name|xdgCacheHome
return|;
block|}
case|case
name|DataLocation
case|:
case|case
name|GenericDataLocation
case|:
block|{
name|QString
name|xdgDataHome
init|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|qgetenv
argument_list|(
literal|"XDG_DATA_HOME"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|xdgDataHome
operator|.
name|isEmpty
argument_list|()
condition|)
name|xdgDataHome
operator|=
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/.local/share"
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|QStandardPaths
operator|::
name|DataLocation
condition|)
block|{
if|if
condition|(
operator|!
name|QCoreApplication
operator|::
name|organizationName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|xdgDataHome
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|QCoreApplication
operator|::
name|organizationName
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|xdgDataHome
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
expr_stmt|;
block|}
return|return
name|xdgDataHome
return|;
block|}
case|case
name|ConfigLocation
case|:
block|{
comment|// http://standards.freedesktop.org/basedir-spec/latest/
name|QString
name|xdgConfigHome
init|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|qgetenv
argument_list|(
literal|"XDG_CONFIG_HOME"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|xdgConfigHome
operator|.
name|isEmpty
argument_list|()
condition|)
name|xdgConfigHome
operator|=
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/.config"
argument_list|)
expr_stmt|;
return|return
name|xdgConfigHome
return|;
block|}
case|case
name|RuntimeLocation
case|:
block|{
specifier|const
name|uid_t
name|myUid
init|=
name|geteuid
argument_list|()
decl_stmt|;
comment|// http://standards.freedesktop.org/basedir-spec/latest/
name|QString
name|xdgRuntimeDir
init|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|qgetenv
argument_list|(
literal|"XDG_RUNTIME_DIR"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|xdgRuntimeDir
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|userName
init|=
name|QFileSystemEngine
operator|::
name|resolveUserName
argument_list|(
name|myUid
argument_list|)
decl_stmt|;
name|xdgRuntimeDir
operator|=
name|QDir
operator|::
name|tempPath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/runtime-"
argument_list|)
operator|+
name|userName
expr_stmt|;
name|QDir
name|dir
argument_list|(
name|xdgRuntimeDir
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|dir
operator|.
name|exists
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|QDir
argument_list|()
operator|.
name|mkdir
argument_list|(
name|xdgRuntimeDir
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QStandardPaths: error creating runtime directory %s: %s"
argument_list|,
name|qPrintable
argument_list|(
name|xdgRuntimeDir
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|errno
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
block|}
block|}
block|}
comment|// "The directory MUST be owned by the user"
name|QFileInfo
name|fileInfo
argument_list|(
name|xdgRuntimeDir
argument_list|)
decl_stmt|;
if|if
condition|(
name|fileInfo
operator|.
name|ownerId
argument_list|()
operator|!=
name|myUid
condition|)
block|{
name|qWarning
argument_list|(
literal|"QStandardPaths: wrong ownership on runtime directory %s, %d instead of %d"
argument_list|,
name|qPrintable
argument_list|(
name|xdgRuntimeDir
argument_list|)
argument_list|,
name|fileInfo
operator|.
name|ownerId
argument_list|()
argument_list|,
name|myUid
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
block|}
comment|// "and he MUST be the only one having read and write access to it. Its Unix access mode MUST be 0700."
name|QFile
name|file
argument_list|(
name|xdgRuntimeDir
argument_list|)
decl_stmt|;
specifier|const
name|QFile
operator|::
name|Permissions
name|wantedPerms
init|=
name|QFile
operator|::
name|ReadUser
operator||
name|QFile
operator|::
name|WriteUser
operator||
name|QFile
operator|::
name|ExeUser
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|permissions
argument_list|()
operator|!=
name|wantedPerms
operator|&&
operator|!
name|file
operator|.
name|setPermissions
argument_list|(
name|wantedPerms
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QStandardPaths: wrong permissions on runtime directory %s"
argument_list|,
name|qPrintable
argument_list|(
name|xdgRuntimeDir
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
block|}
return|return
name|xdgRuntimeDir
return|;
block|}
default|default:
break|break;
block|}
comment|// http://www.freedesktop.org/wiki/Software/xdg-user-dirs
name|QString
name|xdgConfigHome
init|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|qgetenv
argument_list|(
literal|"XDG_CONFIG_HOME"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|xdgConfigHome
operator|.
name|isEmpty
argument_list|()
condition|)
name|xdgConfigHome
operator|=
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/.config"
argument_list|)
expr_stmt|;
name|QFile
name|file
argument_list|(
name|xdgConfigHome
operator|+
name|QLatin1String
argument_list|(
literal|"/user-dirs.dirs"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|exists
argument_list|()
operator|&&
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|QHash
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|lines
decl_stmt|;
name|QTextStream
name|stream
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
comment|// Only look for lines like: XDG_DESKTOP_DIR="$HOME/Desktop"
name|QRegExp
name|exp
argument_list|(
name|QLatin1String
argument_list|(
literal|"^XDG_(.*)_DIR=(.*)$"
argument_list|)
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|stream
operator|.
name|atEnd
argument_list|()
condition|)
block|{
specifier|const
name|QString
modifier|&
name|line
init|=
name|stream
operator|.
name|readLine
argument_list|()
decl_stmt|;
if|if
condition|(
name|exp
operator|.
name|indexIn
argument_list|(
name|line
argument_list|)
operator|!=
operator|-
literal|1
condition|)
block|{
specifier|const
name|QStringList
name|lst
init|=
name|exp
operator|.
name|capturedTexts
argument_list|()
decl_stmt|;
specifier|const
name|QString
name|key
init|=
name|lst
operator|.
name|at
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|QString
name|value
init|=
name|lst
operator|.
name|at
argument_list|(
literal|2
argument_list|)
decl_stmt|;
if|if
condition|(
name|value
operator|.
name|length
argument_list|()
operator|>
literal|2
operator|&&
name|value
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\"'
argument_list|)
argument_list|)
operator|&&
name|value
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\"'
argument_list|)
argument_list|)
condition|)
name|value
operator|=
name|value
operator|.
name|mid
argument_list|(
literal|1
argument_list|,
name|value
operator|.
name|length
argument_list|()
operator|-
literal|2
argument_list|)
expr_stmt|;
comment|// Store the key and value: "DESKTOP", "$HOME/Desktop"
name|lines
index|[
name|key
index|]
operator|=
name|value
expr_stmt|;
block|}
block|}
name|QString
name|key
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|DesktopLocation
case|:
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"DESKTOP"
argument_list|)
expr_stmt|;
break|break;
case|case
name|DocumentsLocation
case|:
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"DOCUMENTS"
argument_list|)
expr_stmt|;
break|break;
case|case
name|PicturesLocation
case|:
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"PICTURES"
argument_list|)
expr_stmt|;
break|break;
case|case
name|MusicLocation
case|:
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"MUSIC"
argument_list|)
expr_stmt|;
break|break;
case|case
name|MoviesLocation
case|:
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"VIDEOS"
argument_list|)
expr_stmt|;
break|break;
case|case
name|DownloadLocation
case|:
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"DOWNLOAD"
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
if|if
condition|(
operator|!
name|key
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QString
name|value
init|=
name|lines
operator|.
name|value
argument_list|(
name|key
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|value
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// value can start with $HOME
if|if
condition|(
name|value
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"$HOME"
argument_list|)
argument_list|)
condition|)
name|value
operator|=
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|value
operator|.
name|mid
argument_list|(
literal|5
argument_list|)
expr_stmt|;
return|return
name|value
return|;
block|}
block|}
block|}
name|QString
name|path
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|DesktopLocation
case|:
name|path
operator|=
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/Desktop"
argument_list|)
expr_stmt|;
break|break;
case|case
name|DocumentsLocation
case|:
name|path
operator|=
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/Documents"
argument_list|)
expr_stmt|;
break|break;
case|case
name|PicturesLocation
case|:
name|path
operator|=
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/Pictures"
argument_list|)
expr_stmt|;
break|break;
case|case
name|FontsLocation
case|:
name|path
operator|=
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/.fonts"
argument_list|)
expr_stmt|;
break|break;
case|case
name|MusicLocation
case|:
name|path
operator|=
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/Music"
argument_list|)
expr_stmt|;
break|break;
case|case
name|MoviesLocation
case|:
name|path
operator|=
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/Videos"
argument_list|)
expr_stmt|;
break|break;
case|case
name|DownloadLocation
case|:
name|path
operator|=
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/Downloads"
argument_list|)
expr_stmt|;
break|break;
case|case
name|ApplicationsLocation
case|:
name|path
operator|=
name|writableLocation
argument_list|(
name|GenericDataLocation
argument_list|)
operator|+
name|QLatin1String
argument_list|(
literal|"/applications"
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|path
return|;
block|}
end_function
begin_function
DECL|function|standardLocations
name|QStringList
name|QStandardPaths
operator|::
name|standardLocations
parameter_list|(
name|StandardLocation
name|type
parameter_list|)
block|{
name|QStringList
name|dirs
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|ConfigLocation
condition|)
block|{
comment|// http://standards.freedesktop.org/basedir-spec/latest/
name|QString
name|xdgConfigDirs
init|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|qgetenv
argument_list|(
literal|"XDG_CONFIG_DIRS"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|xdgConfigDirs
operator|.
name|isEmpty
argument_list|()
condition|)
name|dirs
operator|.
name|append
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"/etc/xdg"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|dirs
operator|=
name|xdgConfigDirs
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|GenericDataLocation
condition|)
block|{
comment|// http://standards.freedesktop.org/basedir-spec/latest/
name|QString
name|xdgConfigDirs
init|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|qgetenv
argument_list|(
literal|"XDG_DATA_DIRS"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|xdgConfigDirs
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|dirs
operator|.
name|append
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"/usr/local/share"
argument_list|)
argument_list|)
expr_stmt|;
name|dirs
operator|.
name|append
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"/usr/share"
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
name|dirs
operator|=
name|xdgConfigDirs
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QString
name|localDir
init|=
name|writableLocation
argument_list|(
name|type
argument_list|)
decl_stmt|;
name|dirs
operator|.
name|prepend
argument_list|(
name|localDir
argument_list|)
expr_stmt|;
return|return
name|dirs
return|;
block|}
end_function
begin_function
DECL|function|displayName
name|QString
name|QStandardPaths
operator|::
name|displayName
parameter_list|(
name|StandardLocation
name|type
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|type
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
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
begin_comment
comment|// QT_NO_STANDARDPATHS
end_comment
end_unit
