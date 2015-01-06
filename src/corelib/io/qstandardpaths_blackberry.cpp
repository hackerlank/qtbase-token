begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2012 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qstandardpaths.h"
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STANDARDPATHS
end_ifndef
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|testModeInsert
specifier|static
name|QString
name|testModeInsert
parameter_list|()
block|{
if|if
condition|(
name|QStandardPaths
operator|::
name|isTestModeEnabled
argument_list|()
condition|)
return|return
name|QStringLiteral
argument_list|(
literal|"/.qttest"
argument_list|)
return|;
else|else
return|return
name|QStringLiteral
argument_list|(
literal|""
argument_list|)
return|;
block|}
end_function
begin_function
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
name|QDir
name|sharedDir
init|=
name|QDir
operator|::
name|home
argument_list|()
decl_stmt|;
name|sharedDir
operator|.
name|cd
argument_list|(
name|QLatin1String
argument_list|(
literal|"../shared"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|sharedRoot
init|=
name|sharedDir
operator|.
name|absolutePath
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|AppDataLocation
case|:
case|case
name|AppLocalDataLocation
case|:
return|return
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|testModeInsert
argument_list|()
return|;
case|case
name|DesktopLocation
case|:
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
name|RuntimeLocation
case|:
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
case|case
name|GenericCacheLocation
case|:
return|return
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|testModeInsert
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/Cache"
argument_list|)
return|;
case|case
name|ConfigLocation
case|:
case|case
name|GenericConfigLocation
case|:
case|case
name|AppConfigLocation
case|:
return|return
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|testModeInsert
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/Settings"
argument_list|)
return|;
case|case
name|GenericDataLocation
case|:
return|return
name|sharedRoot
operator|+
name|testModeInsert
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/misc"
argument_list|)
return|;
case|case
name|DocumentsLocation
case|:
return|return
name|sharedRoot
operator|+
name|QLatin1String
argument_list|(
literal|"/documents"
argument_list|)
return|;
case|case
name|PicturesLocation
case|:
return|return
name|sharedRoot
operator|+
name|QLatin1String
argument_list|(
literal|"/photos"
argument_list|)
return|;
case|case
name|FontsLocation
case|:
comment|// this is not a writable location
return|return
name|QString
argument_list|()
return|;
case|case
name|MusicLocation
case|:
return|return
name|sharedRoot
operator|+
name|QLatin1String
argument_list|(
literal|"/music"
argument_list|)
return|;
case|case
name|MoviesLocation
case|:
return|return
name|sharedRoot
operator|+
name|QLatin1String
argument_list|(
literal|"/videos"
argument_list|)
return|;
case|case
name|DownloadLocation
case|:
return|return
name|sharedRoot
operator|+
name|QLatin1String
argument_list|(
literal|"/downloads"
argument_list|)
return|;
case|case
name|ApplicationsLocation
case|:
return|return
name|QString
argument_list|()
return|;
default|default:
break|break;
block|}
return|return
name|QString
argument_list|()
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
name|FontsLocation
condition|)
return|return
name|QStringList
argument_list|(
name|QLatin1String
argument_list|(
literal|"/base/usr/fonts"
argument_list|)
argument_list|)
return|;
if|if
condition|(
name|type
operator|==
name|AppDataLocation
operator|||
name|type
operator|==
name|AppLocalDataLocation
condition|)
name|dirs
operator|.
name|append
argument_list|(
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|testModeInsert
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"native/assets"
argument_list|)
argument_list|)
expr_stmt|;
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
