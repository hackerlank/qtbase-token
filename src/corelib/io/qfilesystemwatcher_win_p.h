begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILESYSTEMWATCHER_WIN_P_H
end_ifndef
begin_define
DECL|macro|QFILESYSTEMWATCHER_WIN_P_H
define|#
directive|define
name|QFILESYSTEMWATCHER_WIN_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QLibrary class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
file|"qfilesystemwatcher_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMWATCHER
end_ifndef
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfile.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindowsFileSystemWatcherEngineThread
name|class
name|QWindowsFileSystemWatcherEngineThread
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Even though QWindowsFileSystemWatcherEngine is derived of QThread
end_comment
begin_comment
comment|// via QFileSystemWatcher, it does not start a thread.
end_comment
begin_comment
comment|// Instead QWindowsFileSystemWatcher creates QWindowsFileSystemWatcherEngineThreads
end_comment
begin_comment
comment|// to do the actually watching.
end_comment
begin_decl_stmt
name|class
name|QWindowsFileSystemWatcherEngine
range|:
name|public
name|QFileSystemWatcherEngine
block|{
name|Q_OBJECT
name|public
operator|:
name|QWindowsFileSystemWatcherEngine
argument_list|()
block|;
operator|~
name|QWindowsFileSystemWatcherEngine
argument_list|()
block|;
name|QStringList
name|addPaths
argument_list|(
specifier|const
name|QStringList
operator|&
name|paths
argument_list|,
name|QStringList
operator|*
name|files
argument_list|,
name|QStringList
operator|*
name|directories
argument_list|)
block|;
name|QStringList
name|removePaths
argument_list|(
specifier|const
name|QStringList
operator|&
name|paths
argument_list|,
name|QStringList
operator|*
name|files
argument_list|,
name|QStringList
operator|*
name|directories
argument_list|)
block|;
name|void
name|stop
argument_list|()
block|;
name|class
name|Handle
block|{
name|public
operator|:
name|HANDLE
name|handle
block|;
name|uint
name|flags
block|;
name|Handle
argument_list|()
operator|:
name|handle
argument_list|(
name|INVALID_HANDLE_VALUE
argument_list|)
block|,
name|flags
argument_list|(
literal|0u
argument_list|)
block|{ }
name|Handle
argument_list|(
specifier|const
name|Handle
operator|&
name|other
argument_list|)
operator|:
name|handle
argument_list|(
name|other
operator|.
name|handle
argument_list|)
block|,
name|flags
argument_list|(
argument|other.flags
argument_list|)
block|{ }
block|}
block|;
name|class
name|PathInfo
block|{
name|public
operator|:
name|QString
name|absolutePath
block|;
name|QString
name|path
block|;
name|bool
name|isDir
block|;
comment|// fileinfo bits
name|uint
name|ownerId
block|;
name|uint
name|groupId
block|;
name|QFile
operator|::
name|Permissions
name|permissions
block|;
name|QDateTime
name|lastModified
block|;
name|PathInfo
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QFileInfo
operator|&
name|fileInfo
operator|)
block|{
name|ownerId
operator|=
name|fileInfo
operator|.
name|ownerId
argument_list|()
block|;
name|groupId
operator|=
name|fileInfo
operator|.
name|groupId
argument_list|()
block|;
name|permissions
operator|=
name|fileInfo
operator|.
name|permissions
argument_list|()
block|;
name|lastModified
operator|=
name|fileInfo
operator|.
name|lastModified
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QFileInfo
operator|&
name|fileInfo
operator|)
specifier|const
block|{
return|return
operator|(
name|ownerId
operator|!=
name|fileInfo
operator|.
name|ownerId
argument_list|()
operator|||
name|groupId
operator|!=
name|fileInfo
operator|.
name|groupId
argument_list|()
operator|||
name|permissions
operator|!=
name|fileInfo
operator|.
name|permissions
argument_list|()
operator|||
name|lastModified
operator|!=
name|fileInfo
operator|.
name|lastModified
argument_list|()
operator|)
return|;
block|}
expr|}
block|;
name|private
operator|:
name|QList
operator|<
name|QWindowsFileSystemWatcherEngineThread
operator|*
operator|>
name|threads
block|;  }
block|;
name|class
name|QWindowsFileSystemWatcherEngineThread
operator|:
name|public
name|QThread
block|{
name|Q_OBJECT
name|public
operator|:
name|QWindowsFileSystemWatcherEngineThread
argument_list|()
block|;
operator|~
name|QWindowsFileSystemWatcherEngineThread
argument_list|()
block|;
name|void
name|run
argument_list|()
block|;
name|void
name|stop
argument_list|()
block|;
name|void
name|wakeup
argument_list|()
block|;
name|QMutex
name|mutex
block|;
name|QVector
operator|<
name|HANDLE
operator|>
name|handles
block|;
name|int
name|msg
block|;
name|QHash
operator|<
name|QString
block|,
name|QWindowsFileSystemWatcherEngine
operator|::
name|Handle
operator|>
name|handleForDir
block|;
name|QHash
operator|<
name|HANDLE
block|,
name|QHash
operator|<
name|QString
block|,
name|QWindowsFileSystemWatcherEngine
operator|::
name|PathInfo
operator|>
expr|>
name|pathInfoForHandle
block|;
name|Q_SIGNALS
operator|:
name|void
name|fileChanged
argument_list|(
argument|const QString&path
argument_list|,
argument|bool removed
argument_list|)
block|;
name|void
name|directoryChanged
argument_list|(
argument|const QString&path
argument_list|,
argument|bool removed
argument_list|)
block|; }
block|;
endif|#
directive|endif
comment|// QT_NO_FILESYSTEMWATCHER
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFILESYSTEMWATCHER_WIN_P_H
end_comment
end_unit
