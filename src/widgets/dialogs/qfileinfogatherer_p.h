begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILEINFOGATHERER_H
end_ifndef
begin_define
DECL|macro|QFILEINFOGATHERER_H
define|#
directive|define
name|QFILEINFOGATHERER_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|<qthread.h>
end_include
begin_include
include|#
directive|include
file|<qmutex.h>
end_include
begin_include
include|#
directive|include
file|<qwaitcondition.h>
end_include
begin_include
include|#
directive|include
file|<qfilesystemwatcher.h>
end_include
begin_include
include|#
directive|include
file|<qfileiconprovider.h>
end_include
begin_include
include|#
directive|include
file|<qpair.h>
end_include
begin_include
include|#
directive|include
file|<qstack.h>
end_include
begin_include
include|#
directive|include
file|<qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qelapsedtimer.h>
end_include
begin_include
include|#
directive|include
file|<private/qfilesystemengine_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QExtendedInformation
block|{
name|public
label|:
enum|enum
name|Type
block|{
name|Dir
block|,
name|File
block|,
name|System
block|}
enum|;
name|QExtendedInformation
argument_list|()
block|{}
name|QExtendedInformation
argument_list|(
specifier|const
name|QFileInfo
operator|&
name|info
argument_list|)
operator|:
name|mFileInfo
argument_list|(
argument|info
argument_list|)
block|{}
specifier|inline
name|bool
name|isDir
argument_list|()
block|{
return|return
name|type
argument_list|()
operator|==
name|Dir
return|;
block|}
specifier|inline
name|bool
name|isFile
parameter_list|()
block|{
return|return
name|type
argument_list|()
operator|==
name|File
return|;
block|}
specifier|inline
name|bool
name|isSystem
parameter_list|()
block|{
return|return
name|type
argument_list|()
operator|==
name|System
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QExtendedInformation
operator|&
name|fileInfo
operator|)
specifier|const
block|{
return|return
name|mFileInfo
operator|==
name|fileInfo
operator|.
name|mFileInfo
operator|&&
name|displayType
operator|==
name|fileInfo
operator|.
name|displayType
operator|&&
name|permissions
argument_list|()
operator|==
name|fileInfo
operator|.
name|permissions
argument_list|()
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_FSFILEENGINE
name|bool
name|isCaseSensitive
argument_list|()
specifier|const
block|{
return|return
name|QFileSystemEngine
operator|::
name|isCaseSensitive
argument_list|()
return|;
block|}
endif|#
directive|endif
name|QFile
operator|::
name|Permissions
name|permissions
argument_list|()
specifier|const
block|{
return|return
name|mFileInfo
operator|.
name|permissions
argument_list|()
return|;
block|}
name|Type
name|type
argument_list|()
specifier|const
block|{
if|if
condition|(
name|mFileInfo
operator|.
name|isDir
argument_list|()
condition|)
block|{
return|return
name|QExtendedInformation
operator|::
name|Dir
return|;
block|}
if|if
condition|(
name|mFileInfo
operator|.
name|isFile
argument_list|()
condition|)
block|{
return|return
name|QExtendedInformation
operator|::
name|File
return|;
block|}
if|if
condition|(
operator|!
name|mFileInfo
operator|.
name|exists
argument_list|()
operator|&&
name|mFileInfo
operator|.
name|isSymLink
argument_list|()
condition|)
block|{
return|return
name|QExtendedInformation
operator|::
name|System
return|;
block|}
return|return
name|QExtendedInformation
operator|::
name|System
return|;
block|}
name|bool
name|isSymLink
argument_list|()
specifier|const
block|{
return|return
name|mFileInfo
operator|.
name|isSymLink
argument_list|()
return|;
block|}
name|bool
name|isHidden
argument_list|()
specifier|const
block|{
return|return
name|mFileInfo
operator|.
name|isHidden
argument_list|()
return|;
block|}
name|QFileInfo
name|fileInfo
argument_list|()
specifier|const
block|{
return|return
name|mFileInfo
return|;
block|}
name|QDateTime
name|lastModified
argument_list|()
specifier|const
block|{
return|return
name|mFileInfo
operator|.
name|lastModified
argument_list|()
return|;
block|}
name|qint64
name|size
argument_list|()
specifier|const
block|{
name|qint64
name|size
operator|=
operator|-
literal|1
block|;
if|if
condition|(
name|type
argument_list|()
operator|==
name|QExtendedInformation
operator|::
name|Dir
condition|)
name|size
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|type
argument_list|()
operator|==
name|QExtendedInformation
operator|::
name|File
condition|)
name|size
operator|=
name|mFileInfo
operator|.
name|size
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|mFileInfo
operator|.
name|exists
argument_list|()
operator|&&
operator|!
name|mFileInfo
operator|.
name|isSymLink
argument_list|()
condition|)
name|size
operator|=
operator|-
literal|1
expr_stmt|;
return|return
name|size
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|QString
name|displayType
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QIcon
name|icon
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QFileInfo
name|mFileInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
DECL|variable|QFileIconProvider
name|class
name|QFileIconProvider
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMMODEL
end_ifndef
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QFileInfoGatherer
range|:
name|public
name|QThread
block|{
name|Q_OBJECT
name|Q_SIGNALS
operator|:
name|void
name|updates
argument_list|(
specifier|const
name|QString
operator|&
name|directory
argument_list|,
specifier|const
name|QList
operator|<
name|QPair
operator|<
name|QString
argument_list|,
name|QFileInfo
operator|>
expr|>
operator|&
name|updates
argument_list|)
block|;
name|void
name|newListOfFiles
argument_list|(
argument|const QString&directory
argument_list|,
argument|const QStringList&listOfFiles
argument_list|)
specifier|const
block|;
name|void
name|nameResolved
argument_list|(
argument|const QString&fileName
argument_list|,
argument|const QString&resolvedName
argument_list|)
specifier|const
block|;
name|void
name|directoryLoaded
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|public
operator|:
name|QFileInfoGatherer
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QFileInfoGatherer
argument_list|()
block|;
name|void
name|clear
argument_list|()
block|;
name|void
name|removePath
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|QExtendedInformation
name|getInfo
argument_list|(
argument|const QFileInfo&info
argument_list|)
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|list
argument_list|(
specifier|const
name|QString
operator|&
name|directoryPath
argument_list|)
block|;
name|void
name|fetchExtendedInformation
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QStringList
operator|&
name|files
argument_list|)
block|;
name|void
name|updateFile
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|void
name|setResolveSymlinks
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|resolveSymlinks
argument_list|()
specifier|const
block|;
name|void
name|setIconProvider
argument_list|(
name|QFileIconProvider
operator|*
name|provider
argument_list|)
block|;
name|QFileIconProvider
operator|*
name|iconProvider
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|void
name|run
argument_list|()
block|;
name|void
name|getFileInfos
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QStringList
operator|&
name|files
argument_list|)
block|;
name|private
operator|:
name|void
name|fetch
argument_list|(
specifier|const
name|QFileInfo
operator|&
name|info
argument_list|,
name|QElapsedTimer
operator|&
name|base
argument_list|,
name|bool
operator|&
name|firstTime
argument_list|,
name|QList
operator|<
name|QPair
operator|<
name|QString
argument_list|,
name|QFileInfo
operator|>
expr|>
operator|&
name|updatedFiles
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|QString
name|translateDriveName
argument_list|(
argument|const QFileInfo&drive
argument_list|)
specifier|const
block|;
name|mutable
name|QMutex
name|mutex
block|;
name|QWaitCondition
name|condition
block|;
name|QAtomicInt
name|abort
block|;
name|QStack
operator|<
name|QString
operator|>
name|path
block|;
name|QStack
operator|<
name|QStringList
operator|>
name|files
block|;
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMWATCHER
name|QFileSystemWatcher
operator|*
name|watcher
block|;
endif|#
directive|endif
name|bool
name|m_resolveSymlinks
block|;
name|QFileIconProvider
operator|*
name|m_iconProvider
block|;
name|QFileIconProvider
name|defaultProvider
block|;
ifndef|#
directive|ifndef
name|Q_OS_WIN
name|uint
name|userId
block|;
name|uint
name|groupId
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
comment|// QT_NO_FILESYSTEMMODEL
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFILEINFOGATHERER_H
end_comment
end_unit
