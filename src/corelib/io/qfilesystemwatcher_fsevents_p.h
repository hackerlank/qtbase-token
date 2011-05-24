begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FILEWATCHER_FSEVENTS_P_H
end_ifndef
begin_define
DECL|macro|FILEWATCHER_FSEVENTS_P_H
define|#
directive|define
name|FILEWATCHER_FSEVENTS_P_H
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
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qwaitcondition.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qthread.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlinkedlist.h>
end_include
begin_include
include|#
directive|include
file|<private/qcore_mac_p.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_typedef
DECL|typedef|FSEventStreamRef
typedef|typedef
name|struct
name|__FSEventStream
modifier|*
name|FSEventStreamRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|ConstFSEventStreamRef
typedef|typedef
specifier|const
name|struct
name|__FSEventStream
modifier|*
name|ConstFSEventStreamRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|CFArrayRef
typedef|typedef
specifier|const
name|struct
name|__CFArray
modifier|*
name|CFArrayRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|FSEventStreamEventFlags
typedef|typedef
name|UInt32
name|FSEventStreamEventFlags
typedef|;
end_typedef
begin_typedef
DECL|typedef|FSEventStreamEventId
typedef|typedef
name|uint64_t
name|FSEventStreamEventId
typedef|;
end_typedef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_if
if|#
directive|if
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|>=
name|MAC_OS_X_VERSION_10_5
end_if
begin_comment
comment|// Yes, I use a stat64 element here. QFileInfo requires too much knowledge about implementation
end_comment
begin_comment
comment|// details to be used as a long-standing record. Since I'm going to have to store this information, I can
end_comment
begin_comment
comment|// do the stat myself too.
end_comment
begin_struct
DECL|struct|PathInfo
struct|struct
name|PathInfo
block|{
DECL|function|PathInfo
name|PathInfo
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QByteArray
operator|&
name|absPath
argument_list|)
operator|:
name|originalPath
argument_list|(
name|path
argument_list|)
operator|,
name|absolutePath
argument_list|(
argument|absPath
argument_list|)
block|{}
DECL|member|originalPath
name|QString
name|originalPath
expr_stmt|;
comment|// The path we need to emit
DECL|member|absolutePath
name|QByteArray
name|absolutePath
decl_stmt|;
comment|// The path we need to stat.
DECL|member|savedInfo
struct_decl|struct ::stat64 savedInfo;
comment|// All the info for the path so we can compare it.
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|PathInfoList
typedef|typedef
name|QLinkedList
operator|<
name|PathInfo
operator|>
name|PathInfoList
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QString
DECL|typedef|PathHash
typedef|typedef
name|QHash
operator|<
name|QString
operator|,
name|PathInfoList
operator|>
name|PathHash
expr_stmt|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|QFSEventsFileSystemWatcherEngine
range|:
name|public
name|QFileSystemWatcherEngine
block|{
name|Q_OBJECT
name|public
operator|:
operator|~
name|QFSEventsFileSystemWatcherEngine
argument_list|()
block|;
specifier|static
name|QFSEventsFileSystemWatcherEngine
operator|*
name|create
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
name|private
operator|:
name|QFSEventsFileSystemWatcherEngine
argument_list|()
block|;
name|void
name|warmUpFSEvents
argument_list|()
block|;
name|void
name|updateFiles
argument_list|()
block|;
specifier|static
name|void
name|fseventsCallback
argument_list|(
argument|ConstFSEventStreamRef streamRef
argument_list|,
argument|void *clientCallBackInfo
argument_list|,
argument|size_t numEvents
argument_list|,
argument|void *eventPaths
argument_list|,
argument|const FSEventStreamEventFlags eventFlags[]
argument_list|,
argument|const FSEventStreamEventId eventIds[]
argument_list|)
block|;
name|void
name|run
argument_list|()
block|;
name|FSEventStreamRef
name|fsStream
block|;
name|CFArrayRef
name|pathsToWatch
block|;
name|CFRunLoopRef
name|threadsRunLoop
block|;
name|QMutex
name|mutex
block|;
name|QWaitCondition
name|waitCondition
block|;
name|QWaitCondition
name|waitForStop
block|;
if|#
directive|if
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|>=
name|MAC_OS_X_VERSION_10_5
name|PathHash
name|filePathInfoHash
block|;
name|PathHash
name|dirPathInfoHash
block|;
name|void
name|updateHash
argument_list|(
name|PathHash
operator|&
name|pathHash
argument_list|)
block|;
name|void
name|updateList
argument_list|(
argument|PathInfoList&list
argument_list|,
argument|bool directory
argument_list|,
argument|bool emitSignals
argument_list|)
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_FILESYSTEMWATCHER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
