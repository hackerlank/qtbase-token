begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFSFILEENGINE_P_H
end_ifndef
begin_define
DECL|macro|QFSFILEENGINE_P_H
define|#
directive|define
name|QFSFILEENGINE_P_H
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
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qfsfileengine.h"
end_include
begin_include
include|#
directive|include
file|"private/qabstractfileengine_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qfilesystementry_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qfilesystemmetadata_p.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
end_ifdef
begin_include
include|#
directive|include
file|<f32file.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FSFILEENGINE
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE_STD
argument_list|)
operator|&&
name|_WIN32_WCE
operator|<
literal|0x600
DECL|macro|Q_USE_DEPRECATED_MAP_API
define|#
directive|define
name|Q_USE_DEPRECATED_MAP_API
value|1
endif|#
directive|endif
name|class
name|Q_AUTOTEST_EXPORT
name|QFSFileEnginePrivate
range|:
name|public
name|QAbstractFileEnginePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QFSFileEngine
argument_list|)
name|public
operator|:
ifdef|#
directive|ifdef
name|Q_OS_WIN
specifier|static
name|QString
name|longFileName
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
endif|#
directive|endif
name|QFileSystemEntry
name|fileEntry
block|;
name|QIODevice
operator|::
name|OpenMode
name|openMode
block|;
name|bool
name|nativeOpen
argument_list|(
argument|QIODevice::OpenMode openMode
argument_list|)
block|;
name|bool
name|openFh
argument_list|(
argument|QIODevice::OpenMode flags
argument_list|,
argument|FILE *fh
argument_list|)
block|;
name|bool
name|openFd
argument_list|(
argument|QIODevice::OpenMode flags
argument_list|,
argument|int fd
argument_list|)
block|;
name|bool
name|nativeClose
argument_list|()
block|;
name|bool
name|closeFdFh
argument_list|()
block|;
name|bool
name|nativeFlush
argument_list|()
block|;
name|bool
name|flushFh
argument_list|()
block|;
name|qint64
name|nativeSize
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|Q_OS_WIN
name|qint64
name|sizeFdFh
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|qint64
name|nativePos
argument_list|()
specifier|const
block|;
name|qint64
name|posFdFh
argument_list|()
specifier|const
block|;
name|bool
name|nativeSeek
argument_list|(
name|qint64
argument_list|)
block|;
name|bool
name|seekFdFh
argument_list|(
name|qint64
argument_list|)
block|;
name|qint64
name|nativeRead
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|readFdFh
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|nativeReadLine
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|readLineFdFh
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|nativeWrite
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|)
block|;
name|qint64
name|writeFdFh
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|)
block|;
name|int
name|nativeHandle
argument_list|()
specifier|const
block|;
name|bool
name|nativeIsSequential
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|Q_OS_WIN
name|bool
name|isSequentialFdFh
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|uchar
operator|*
name|map
argument_list|(
argument|qint64 offset
argument_list|,
argument|qint64 size
argument_list|,
argument|QFile::MemoryMapFlags flags
argument_list|)
block|;
name|bool
name|unmap
argument_list|(
name|uchar
operator|*
name|ptr
argument_list|)
block|;
name|mutable
name|QFileSystemMetaData
name|metaData
block|;
name|FILE
operator|*
name|fh
block|;
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
ifdef|#
directive|ifdef
name|SYMBIAN_ENABLE_64_BIT_FILE_SERVER_API
name|RFile64
name|symbianFile
block|;
name|TInt64
name|symbianFilePos
block|;
else|#
directive|else
name|RFile
name|symbianFile
block|;
comment|/**      * The cursor position in the underlying file.  This differs      * from devicePos because the latter is updated on calls to      * writeData, even if no data was physically transferred to      * the file, but instead stored in the write buffer.      *       * iFilePos is updated on calls to RFile::Read and      * RFile::Write.  It is also updated on calls to seek() but      * RFile::Seek is not called when that happens because      * Symbian supports positioned reads and writes, saving a file      * server call, and because Symbian does not support seeking      * past the end of a file.        */
name|TInt
name|symbianFilePos
block|;
endif|#
directive|endif
name|mutable
name|int
name|fileHandleForMaps
block|;
name|int
name|getMapHandle
argument_list|()
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|HANDLE
name|fileHandle
block|;
name|HANDLE
name|mapHandle
block|;
name|QHash
operator|<
name|uchar
operator|*
block|,
name|DWORD
comment|/* offset % AllocationGranularity */
operator|>
name|maps
block|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|mutable
name|int
name|cachedFd
block|;
endif|#
directive|endif
name|mutable
name|DWORD
name|fileAttrib
block|;
else|#
directive|else
name|QHash
operator|<
name|uchar
operator|*
block|,
name|QPair
operator|<
name|int
comment|/*offset % PageSize*/
block|,
name|size_t
comment|/*length + offset % PageSize*/
operator|>
expr|>
name|maps
block|;
endif|#
directive|endif
name|int
name|fd
block|;      enum
name|LastIOCommand
block|{
name|IOFlushCommand
block|,
name|IOReadCommand
block|,
name|IOWriteCommand
block|}
block|;
name|LastIOCommand
name|lastIOCommand
block|;
name|bool
name|lastFlushFailed
block|;
name|bool
name|closeFileHandle
block|;
name|mutable
name|uint
name|is_sequential
operator|:
literal|2
block|;
name|mutable
name|uint
name|could_stat
operator|:
literal|1
block|;
name|mutable
name|uint
name|tried_stat
operator|:
literal|1
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|mutable
name|uint
name|need_lstat
operator|:
literal|1
block|;
name|mutable
name|uint
name|is_link
operator|:
literal|1
block|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|bool
name|doStat
argument_list|(
argument|QFileSystemMetaData::MetaDataFlags flags
argument_list|)
specifier|const
block|;
else|#
directive|else
name|bool
name|doStat
argument_list|(
argument|QFileSystemMetaData::MetaDataFlags flags = QFileSystemMetaData::PosixStatFlags
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|bool
name|isSymlink
argument_list|()
specifier|const
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
name|int
name|sysOpen
argument_list|(
argument|const QString&
argument_list|,
argument|int flags
argument_list|)
block|;
endif|#
directive|endif
name|protected
operator|:
name|QFSFileEnginePrivate
argument_list|()
block|;
name|void
name|init
argument_list|()
block|;
name|QAbstractFileEngine
operator|::
name|FileFlags
name|getPermissions
argument_list|(
argument|QAbstractFileEngine::FileFlags type
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FSFILEENGINE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFSFILEENGINE_P_H
end_comment
end_unit
