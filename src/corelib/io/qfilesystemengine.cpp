begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfilesystemengine_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdir.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringbuilder.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qabstractfileengine_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_BUILD_CORE_LIB
end_ifdef
begin_include
include|#
directive|include
file|<QtCore/private/qresource_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \internal      Returns the canonicalized form of \a path (i.e., with all symlinks     resolved, and all redundant path elements removed. */
DECL|function|slowCanonicalized
name|QString
name|QFileSystemEngine
operator|::
name|slowCanonicalized
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
if|if
condition|(
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|path
return|;
name|QFileInfo
name|fi
decl_stmt|;
specifier|const
name|QChar
name|slash
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|tmpPath
init|=
name|path
decl_stmt|;
name|int
name|separatorPos
init|=
literal|0
decl_stmt|;
name|QSet
argument_list|<
name|QString
argument_list|>
name|nonSymlinks
decl_stmt|;
name|QSet
argument_list|<
name|QString
argument_list|>
name|known
decl_stmt|;
name|known
operator|.
name|insert
argument_list|(
name|path
argument_list|)
expr_stmt|;
do|do
block|{
ifdef|#
directive|ifdef
name|Q_OS_WIN
if|if
condition|(
name|separatorPos
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|tmpPath
operator|.
name|size
argument_list|()
operator|>=
literal|2
operator|&&
name|tmpPath
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|==
name|slash
operator|&&
name|tmpPath
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|==
name|slash
condition|)
block|{
comment|// UNC, skip past the first two elements
name|separatorPos
operator|=
name|tmpPath
operator|.
name|indexOf
argument_list|(
name|slash
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|tmpPath
operator|.
name|size
argument_list|()
operator|>=
literal|3
operator|&&
name|tmpPath
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
operator|&&
name|tmpPath
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|==
name|slash
condition|)
block|{
comment|// volume root, skip since it can not be a symlink
name|separatorPos
operator|=
literal|2
expr_stmt|;
block|}
block|}
if|if
condition|(
name|separatorPos
operator|!=
operator|-
literal|1
condition|)
endif|#
directive|endif
name|separatorPos
operator|=
name|tmpPath
operator|.
name|indexOf
argument_list|(
name|slash
argument_list|,
name|separatorPos
operator|+
literal|1
argument_list|)
expr_stmt|;
name|QString
name|prefix
init|=
name|separatorPos
operator|==
operator|-
literal|1
condition|?
name|tmpPath
else|:
name|tmpPath
operator|.
name|left
argument_list|(
name|separatorPos
argument_list|)
decl_stmt|;
if|if
condition|(
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
comment|// Symbian doesn't support directory symlinks, so do not check for link unless we
comment|// are handling the last path element. This not only slightly improves performance,
comment|// but also saves us from lot of unnecessary platform security check failures
comment|// when dealing with files under *:/private directories.
name|separatorPos
operator|==
operator|-
literal|1
operator|&&
endif|#
directive|endif
operator|!
name|nonSymlinks
operator|.
name|contains
argument_list|(
name|prefix
argument_list|)
condition|)
block|{
name|fi
operator|.
name|setFile
argument_list|(
name|prefix
argument_list|)
expr_stmt|;
if|if
condition|(
name|fi
operator|.
name|isSymLink
argument_list|()
condition|)
block|{
name|QString
name|target
init|=
name|fi
operator|.
name|symLinkTarget
argument_list|()
decl_stmt|;
if|if
condition|(
name|QFileInfo
argument_list|(
name|target
argument_list|)
operator|.
name|isRelative
argument_list|()
condition|)
name|target
operator|=
name|fi
operator|.
name|absolutePath
argument_list|()
operator|+
name|slash
operator|+
name|target
expr_stmt|;
if|if
condition|(
name|separatorPos
operator|!=
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|fi
operator|.
name|isDir
argument_list|()
operator|&&
operator|!
name|target
operator|.
name|endsWith
argument_list|(
name|slash
argument_list|)
condition|)
name|target
operator|.
name|append
argument_list|(
name|slash
argument_list|)
expr_stmt|;
name|target
operator|.
name|append
argument_list|(
name|tmpPath
operator|.
name|mid
argument_list|(
name|separatorPos
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|tmpPath
operator|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|target
argument_list|)
expr_stmt|;
name|separatorPos
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|known
operator|.
name|contains
argument_list|(
name|tmpPath
argument_list|)
condition|)
return|return
name|QString
argument_list|()
return|;
name|known
operator|.
name|insert
argument_list|(
name|tmpPath
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|nonSymlinks
operator|.
name|insert
argument_list|(
name|prefix
argument_list|)
expr_stmt|;
block|}
block|}
block|}
do|while
condition|(
name|separatorPos
operator|!=
operator|-
literal|1
condition|)
do|;
return|return
name|QDir
operator|::
name|cleanPath
argument_list|(
name|tmpPath
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|_q_checkEntry
specifier|static
specifier|inline
name|bool
name|_q_checkEntry
parameter_list|(
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|,
name|QFileSystemMetaData
modifier|&
name|data
parameter_list|,
name|bool
name|resolvingEntry
parameter_list|)
block|{
if|if
condition|(
name|resolvingEntry
condition|)
block|{
if|if
condition|(
operator|!
name|QFileSystemEngine
operator|::
name|fillMetaData
argument_list|(
name|entry
argument_list|,
name|data
argument_list|,
name|QFileSystemMetaData
operator|::
name|ExistsAttribute
argument_list|)
operator|||
operator|!
name|data
operator|.
name|exists
argument_list|()
condition|)
block|{
name|data
operator|.
name|clear
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|_q_checkEntry
specifier|static
specifier|inline
name|bool
name|_q_checkEntry
parameter_list|(
name|QAbstractFileEngine
modifier|*
modifier|&
name|engine
parameter_list|,
name|bool
name|resolvingEntry
parameter_list|)
block|{
if|if
condition|(
name|resolvingEntry
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|engine
operator|->
name|fileFlags
argument_list|(
name|QAbstractFileEngine
operator|::
name|FlagsMask
argument_list|)
operator|&
name|QAbstractFileEngine
operator|::
name|ExistsFlag
operator|)
condition|)
block|{
operator|delete
name|engine
expr_stmt|;
name|engine
operator|=
literal|0
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|_q_resolveEntryAndCreateLegacyEngine_recursive
specifier|static
name|bool
name|_q_resolveEntryAndCreateLegacyEngine_recursive
parameter_list|(
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|,
name|QFileSystemMetaData
modifier|&
name|data
parameter_list|,
name|QAbstractFileEngine
modifier|*
modifier|&
name|engine
parameter_list|,
name|bool
name|resolvingEntry
init|=
literal|false
parameter_list|)
block|{
name|QString
specifier|const
modifier|&
name|filePath
init|=
name|entry
operator|.
name|filePath
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|engine
operator|=
name|qt_custom_file_engine_handler_create
argument_list|(
name|filePath
argument_list|)
operator|)
condition|)
return|return
name|_q_checkEntry
argument_list|(
name|engine
argument_list|,
name|resolvingEntry
argument_list|)
return|;
if|#
directive|if
name|defined
argument_list|(
name|QT_BUILD_CORE_LIB
argument_list|)
for|for
control|(
name|int
name|prefixSeparator
init|=
literal|0
init|;
name|prefixSeparator
operator|<
name|filePath
operator|.
name|size
argument_list|()
condition|;
operator|++
name|prefixSeparator
control|)
block|{
name|QChar
specifier|const
name|ch
init|=
name|filePath
index|[
name|prefixSeparator
index|]
decl_stmt|;
if|if
condition|(
name|ch
operator|==
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
condition|)
break|break;
if|if
condition|(
name|ch
operator|==
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
condition|)
block|{
if|if
condition|(
name|prefixSeparator
operator|==
literal|0
condition|)
block|{
name|engine
operator|=
operator|new
name|QResourceFileEngine
argument_list|(
name|filePath
argument_list|)
expr_stmt|;
return|return
name|_q_checkEntry
argument_list|(
name|engine
argument_list|,
name|resolvingEntry
argument_list|)
return|;
block|}
if|if
condition|(
name|prefixSeparator
operator|==
literal|1
condition|)
break|break;
specifier|const
name|QStringList
modifier|&
name|paths
init|=
name|QDir
operator|::
name|searchPaths
argument_list|(
name|filePath
operator|.
name|left
argument_list|(
name|prefixSeparator
argument_list|)
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|paths
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|entry
operator|=
name|QFileSystemEntry
argument_list|(
name|QDir
operator|::
name|cleanPath
argument_list|(
name|paths
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|%
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|%
name|filePath
operator|.
name|mid
argument_list|(
name|prefixSeparator
operator|+
literal|1
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|// Recurse!
if|if
condition|(
name|_q_resolveEntryAndCreateLegacyEngine_recursive
argument_list|(
name|entry
argument_list|,
name|data
argument_list|,
name|engine
argument_list|,
literal|true
argument_list|)
condition|)
return|return
literal|true
return|;
block|}
comment|// entry may have been clobbered at this point.
return|return
literal|false
return|;
block|}
comment|//  There's no need to fully validate the prefix here. Consulting the
comment|//  unicode tables could be expensive and validation is already
comment|//  performed in QDir::setSearchPaths.
comment|//
comment|//  if (!ch.isLetterOrNumber())
comment|//      break;
block|}
endif|#
directive|endif
comment|// defined(QT_BUILD_CORE_LIB)
return|return
name|_q_checkEntry
argument_list|(
name|entry
argument_list|,
name|data
argument_list|,
name|resolvingEntry
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \internal      Resolves the \a entry (see QDir::searchPaths) and returns an engine for     it, but never a QFSFileEngine.      Returns a file engine that can be used to access the entry. Returns 0 if     QFileSystemEngine API should be used to query and interact with the file     system object. */
end_comment
begin_function
DECL|function|resolveEntryAndCreateLegacyEngine
name|QAbstractFileEngine
modifier|*
name|QFileSystemEngine
operator|::
name|resolveEntryAndCreateLegacyEngine
parameter_list|(
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|,
name|QFileSystemMetaData
modifier|&
name|data
parameter_list|)
block|{
name|QFileSystemEntry
name|copy
init|=
name|entry
decl_stmt|;
name|QAbstractFileEngine
modifier|*
name|engine
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|_q_resolveEntryAndCreateLegacyEngine_recursive
argument_list|(
name|copy
argument_list|,
name|data
argument_list|,
name|engine
argument_list|)
condition|)
comment|// Reset entry to resolved copy.
name|entry
operator|=
name|copy
expr_stmt|;
else|else
name|data
operator|.
name|clear
argument_list|()
expr_stmt|;
return|return
name|engine
return|;
block|}
end_function
begin_comment
comment|//these unix functions are in this file, because they are shared by symbian port
end_comment
begin_comment
comment|//for open C file handles.
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_UNIX
end_ifdef
begin_comment
comment|//static
end_comment
begin_function
DECL|function|fillMetaData
name|bool
name|QFileSystemEngine
operator|::
name|fillMetaData
parameter_list|(
name|int
name|fd
parameter_list|,
name|QFileSystemMetaData
modifier|&
name|data
parameter_list|)
block|{
name|data
operator|.
name|entryFlags
operator|&=
operator|~
name|QFileSystemMetaData
operator|::
name|PosixStatFlags
expr_stmt|;
name|data
operator|.
name|knownFlagsMask
operator||=
name|QFileSystemMetaData
operator|::
name|PosixStatFlags
expr_stmt|;
name|QT_STATBUF
name|statBuffer
decl_stmt|;
if|if
condition|(
name|QT_FSTAT
argument_list|(
name|fd
argument_list|,
operator|&
name|statBuffer
argument_list|)
operator|==
literal|0
condition|)
block|{
name|data
operator|.
name|fillFromStatBuf
argument_list|(
name|statBuffer
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|fillFromStatBuf
name|void
name|QFileSystemMetaData
operator|::
name|fillFromStatBuf
parameter_list|(
specifier|const
name|QT_STATBUF
modifier|&
name|statBuffer
parameter_list|)
block|{
comment|// Permissions
if|if
condition|(
name|statBuffer
operator|.
name|st_mode
operator|&
name|S_IRUSR
condition|)
name|entryFlags
operator||=
name|QFileSystemMetaData
operator|::
name|OwnerReadPermission
expr_stmt|;
if|if
condition|(
name|statBuffer
operator|.
name|st_mode
operator|&
name|S_IWUSR
condition|)
name|entryFlags
operator||=
name|QFileSystemMetaData
operator|::
name|OwnerWritePermission
expr_stmt|;
if|if
condition|(
name|statBuffer
operator|.
name|st_mode
operator|&
name|S_IXUSR
condition|)
name|entryFlags
operator||=
name|QFileSystemMetaData
operator|::
name|OwnerExecutePermission
expr_stmt|;
if|if
condition|(
name|statBuffer
operator|.
name|st_mode
operator|&
name|S_IRGRP
condition|)
name|entryFlags
operator||=
name|QFileSystemMetaData
operator|::
name|GroupReadPermission
expr_stmt|;
if|if
condition|(
name|statBuffer
operator|.
name|st_mode
operator|&
name|S_IWGRP
condition|)
name|entryFlags
operator||=
name|QFileSystemMetaData
operator|::
name|GroupWritePermission
expr_stmt|;
if|if
condition|(
name|statBuffer
operator|.
name|st_mode
operator|&
name|S_IXGRP
condition|)
name|entryFlags
operator||=
name|QFileSystemMetaData
operator|::
name|GroupExecutePermission
expr_stmt|;
if|if
condition|(
name|statBuffer
operator|.
name|st_mode
operator|&
name|S_IROTH
condition|)
name|entryFlags
operator||=
name|QFileSystemMetaData
operator|::
name|OtherReadPermission
expr_stmt|;
if|if
condition|(
name|statBuffer
operator|.
name|st_mode
operator|&
name|S_IWOTH
condition|)
name|entryFlags
operator||=
name|QFileSystemMetaData
operator|::
name|OtherWritePermission
expr_stmt|;
if|if
condition|(
name|statBuffer
operator|.
name|st_mode
operator|&
name|S_IXOTH
condition|)
name|entryFlags
operator||=
name|QFileSystemMetaData
operator|::
name|OtherExecutePermission
expr_stmt|;
comment|// Type
if|if
condition|(
operator|(
name|statBuffer
operator|.
name|st_mode
operator|&
name|S_IFMT
operator|)
operator|==
name|S_IFREG
condition|)
name|entryFlags
operator||=
name|QFileSystemMetaData
operator|::
name|FileType
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|statBuffer
operator|.
name|st_mode
operator|&
name|S_IFMT
operator|)
operator|==
name|S_IFDIR
condition|)
name|entryFlags
operator||=
name|QFileSystemMetaData
operator|::
name|DirectoryType
expr_stmt|;
else|else
name|entryFlags
operator||=
name|QFileSystemMetaData
operator|::
name|SequentialType
expr_stmt|;
comment|// Attributes
name|entryFlags
operator||=
name|QFileSystemMetaData
operator|::
name|ExistsAttribute
expr_stmt|;
name|size_
operator|=
name|statBuffer
operator|.
name|st_size
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_CORESERVICES
argument_list|)
expr|\
operator|&&
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|>=
name|MAC_OS_X_VERSION_10_5
if|if
condition|(
name|statBuffer
operator|.
name|st_flags
operator|&
name|UF_HIDDEN
condition|)
block|{
name|entryFlags
operator||=
name|QFileSystemMetaData
operator|::
name|HiddenAttribute
expr_stmt|;
name|knownFlagsMask
operator||=
name|QFileSystemMetaData
operator|::
name|HiddenAttribute
expr_stmt|;
block|}
endif|#
directive|endif
comment|// Times
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|modificationTime_
operator|=
name|qt_symbian_time_t_To_TTime
argument_list|(
name|statBuffer
operator|.
name|st_mtime
argument_list|)
expr_stmt|;
else|#
directive|else
name|creationTime_
operator|=
name|statBuffer
operator|.
name|st_ctime
condition|?
name|statBuffer
operator|.
name|st_ctime
else|:
name|statBuffer
operator|.
name|st_mtime
expr_stmt|;
name|modificationTime_
operator|=
name|statBuffer
operator|.
name|st_mtime
expr_stmt|;
name|accessTime_
operator|=
name|statBuffer
operator|.
name|st_atime
expr_stmt|;
name|userId_
operator|=
name|statBuffer
operator|.
name|st_uid
expr_stmt|;
name|groupId_
operator|=
name|statBuffer
operator|.
name|st_gid
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|fillFromDirEnt
name|void
name|QFileSystemMetaData
operator|::
name|fillFromDirEnt
parameter_list|(
specifier|const
name|QT_DIRENT
modifier|&
name|entry
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|_DIRENT_HAVE_D_TYPE
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_BSD4
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
comment|// BSD4 includes Mac OS X
comment|// ### This will clear all entry flags and knownFlagsMask
switch|switch
condition|(
name|entry
operator|.
name|d_type
condition|)
block|{
case|case
name|DT_DIR
case|:
name|knownFlagsMask
operator|=
name|QFileSystemMetaData
operator|::
name|LinkType
operator||
name|QFileSystemMetaData
operator|::
name|FileType
operator||
name|QFileSystemMetaData
operator|::
name|DirectoryType
operator||
name|QFileSystemMetaData
operator|::
name|SequentialType
operator||
name|QFileSystemMetaData
operator|::
name|ExistsAttribute
expr_stmt|;
name|entryFlags
operator|=
name|QFileSystemMetaData
operator|::
name|DirectoryType
operator||
name|QFileSystemMetaData
operator|::
name|ExistsAttribute
expr_stmt|;
break|break;
case|case
name|DT_BLK
case|:
case|case
name|DT_CHR
case|:
case|case
name|DT_FIFO
case|:
case|case
name|DT_SOCK
case|:
comment|// ### System attribute
name|knownFlagsMask
operator|=
name|QFileSystemMetaData
operator|::
name|LinkType
operator||
name|QFileSystemMetaData
operator|::
name|FileType
operator||
name|QFileSystemMetaData
operator|::
name|DirectoryType
operator||
name|QFileSystemMetaData
operator|::
name|BundleType
operator||
name|QFileSystemMetaData
operator|::
name|AliasType
operator||
name|QFileSystemMetaData
operator|::
name|SequentialType
operator||
name|QFileSystemMetaData
operator|::
name|ExistsAttribute
expr_stmt|;
name|entryFlags
operator|=
name|QFileSystemMetaData
operator|::
name|SequentialType
operator||
name|QFileSystemMetaData
operator|::
name|ExistsAttribute
expr_stmt|;
break|break;
case|case
name|DT_LNK
case|:
name|knownFlagsMask
operator|=
name|QFileSystemMetaData
operator|::
name|LinkType
expr_stmt|;
name|entryFlags
operator|=
name|QFileSystemMetaData
operator|::
name|LinkType
expr_stmt|;
break|break;
case|case
name|DT_REG
case|:
name|knownFlagsMask
operator|=
name|QFileSystemMetaData
operator|::
name|LinkType
operator||
name|QFileSystemMetaData
operator|::
name|FileType
operator||
name|QFileSystemMetaData
operator|::
name|DirectoryType
operator||
name|QFileSystemMetaData
operator|::
name|BundleType
operator||
name|QFileSystemMetaData
operator|::
name|SequentialType
operator||
name|QFileSystemMetaData
operator|::
name|ExistsAttribute
expr_stmt|;
name|entryFlags
operator|=
name|QFileSystemMetaData
operator|::
name|FileType
operator||
name|QFileSystemMetaData
operator|::
name|ExistsAttribute
expr_stmt|;
break|break;
case|case
name|DT_UNKNOWN
case|:
default|default:
name|clear
argument_list|()
expr_stmt|;
block|}
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|entry
argument_list|)
endif|#
directive|endif
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//static
end_comment
begin_function
DECL|function|resolveUserName
name|QString
name|QFileSystemEngine
operator|::
name|resolveUserName
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|,
name|QFileSystemMetaData
modifier|&
name|metaData
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|Q_UNUSED
argument_list|(
name|entry
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|metaData
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|Q_UNUSED
argument_list|(
name|metaData
argument_list|)
expr_stmt|;
return|return
name|QFileSystemEngine
operator|::
name|owner
argument_list|(
name|entry
argument_list|,
name|QAbstractFileEngine
operator|::
name|OwnerUser
argument_list|)
return|;
else|#
directive|else
comment|//(Q_OS_UNIX)
if|if
condition|(
operator|!
name|metaData
operator|.
name|hasFlags
argument_list|(
name|QFileSystemMetaData
operator|::
name|UserId
argument_list|)
condition|)
name|QFileSystemEngine
operator|::
name|fillMetaData
argument_list|(
name|entry
argument_list|,
name|metaData
argument_list|,
name|QFileSystemMetaData
operator|::
name|UserId
argument_list|)
expr_stmt|;
return|return
name|resolveUserName
argument_list|(
name|metaData
operator|.
name|userId
argument_list|()
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|//static
end_comment
begin_function
DECL|function|resolveGroupName
name|QString
name|QFileSystemEngine
operator|::
name|resolveGroupName
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|,
name|QFileSystemMetaData
modifier|&
name|metaData
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|Q_UNUSED
argument_list|(
name|entry
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|metaData
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|Q_UNUSED
argument_list|(
name|metaData
argument_list|)
expr_stmt|;
return|return
name|QFileSystemEngine
operator|::
name|owner
argument_list|(
name|entry
argument_list|,
name|QAbstractFileEngine
operator|::
name|OwnerGroup
argument_list|)
return|;
else|#
directive|else
comment|//(Q_OS_UNIX)
if|if
condition|(
operator|!
name|metaData
operator|.
name|hasFlags
argument_list|(
name|QFileSystemMetaData
operator|::
name|GroupId
argument_list|)
condition|)
name|QFileSystemEngine
operator|::
name|fillMetaData
argument_list|(
name|entry
argument_list|,
name|metaData
argument_list|,
name|QFileSystemMetaData
operator|::
name|GroupId
argument_list|)
expr_stmt|;
return|return
name|resolveGroupName
argument_list|(
name|metaData
operator|.
name|groupId
argument_list|()
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
