begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfilesystementry_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdir.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfile.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qfsfileengine_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<QtCore/qstringbuilder.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|Q_OS_WIN
DECL|function|isUncRoot
specifier|static
name|bool
name|isUncRoot
parameter_list|(
specifier|const
name|QString
modifier|&
name|server
parameter_list|)
block|{
name|QString
name|localPath
init|=
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|server
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|localPath
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"\\\\"
argument_list|)
argument_list|)
condition|)
return|return
literal|false
return|;
name|int
name|idx
init|=
name|localPath
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
argument_list|,
literal|2
argument_list|)
decl_stmt|;
if|if
condition|(
name|idx
operator|==
operator|-
literal|1
operator|||
name|idx
operator|+
literal|1
operator|==
name|localPath
operator|.
name|length
argument_list|()
condition|)
return|return
literal|true
return|;
name|localPath
operator|=
name|localPath
operator|.
name|right
argument_list|(
name|localPath
operator|.
name|length
argument_list|()
operator|-
name|idx
operator|-
literal|1
argument_list|)
operator|.
name|trimmed
argument_list|()
expr_stmt|;
return|return
name|localPath
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|fixIfRelativeUncPath
specifier|static
specifier|inline
name|QString
name|fixIfRelativeUncPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
name|QString
name|currentPath
init|=
name|QDir
operator|::
name|currentPath
argument_list|()
decl_stmt|;
if|if
condition|(
name|currentPath
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"//"
argument_list|)
argument_list|)
condition|)
return|return
name|currentPath
operator|%
name|QChar
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
operator|%
name|path
return|;
return|return
name|path
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|QFileSystemEntry
name|QFileSystemEntry
operator|::
name|QFileSystemEntry
parameter_list|()
member_init_list|:
name|m_lastSeparator
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_firstDotInFileName
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_lastDotInFileName
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!    \internal    Use this constructor when the path is supplied by user code, as it may contain a mix    of '/' and the native separator.  */
end_comment
begin_constructor
DECL|function|QFileSystemEntry
name|QFileSystemEntry
operator|::
name|QFileSystemEntry
parameter_list|(
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|)
member_init_list|:
name|m_filePath
argument_list|(
name|QDir
operator|::
name|fromNativeSeparators
argument_list|(
name|filePath
argument_list|)
argument_list|)
member_init_list|,
name|m_lastSeparator
argument_list|(
operator|-
literal|2
argument_list|)
member_init_list|,
name|m_firstDotInFileName
argument_list|(
operator|-
literal|2
argument_list|)
member_init_list|,
name|m_lastDotInFileName
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!    \internal    Use this constructor when the path is guaranteed to be in internal format, i.e. all    directory separators are '/' and not the native separator.  */
end_comment
begin_constructor
DECL|function|QFileSystemEntry
name|QFileSystemEntry
operator|::
name|QFileSystemEntry
parameter_list|(
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|,
name|FromInternalPath
comment|/* dummy */
parameter_list|)
member_init_list|:
name|m_filePath
argument_list|(
name|filePath
argument_list|)
member_init_list|,
name|m_lastSeparator
argument_list|(
operator|-
literal|2
argument_list|)
member_init_list|,
name|m_firstDotInFileName
argument_list|(
operator|-
literal|2
argument_list|)
member_init_list|,
name|m_lastDotInFileName
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!    \internal    Use this constructor when the path comes from a native API  */
end_comment
begin_constructor
DECL|function|QFileSystemEntry
name|QFileSystemEntry
operator|::
name|QFileSystemEntry
parameter_list|(
specifier|const
name|NativePath
modifier|&
name|nativeFilePath
parameter_list|,
name|FromNativePath
comment|/* dummy */
parameter_list|)
member_init_list|:
name|m_nativeFilePath
argument_list|(
name|nativeFilePath
argument_list|)
member_init_list|,
name|m_lastSeparator
argument_list|(
operator|-
literal|2
argument_list|)
member_init_list|,
name|m_firstDotInFileName
argument_list|(
operator|-
literal|2
argument_list|)
member_init_list|,
name|m_lastDotInFileName
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QFileSystemEntry
name|QFileSystemEntry
operator|::
name|QFileSystemEntry
parameter_list|(
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|,
specifier|const
name|NativePath
modifier|&
name|nativeFilePath
parameter_list|)
member_init_list|:
name|m_filePath
argument_list|(
name|QDir
operator|::
name|fromNativeSeparators
argument_list|(
name|filePath
argument_list|)
argument_list|)
member_init_list|,
name|m_nativeFilePath
argument_list|(
name|nativeFilePath
argument_list|)
member_init_list|,
name|m_lastSeparator
argument_list|(
operator|-
literal|2
argument_list|)
member_init_list|,
name|m_firstDotInFileName
argument_list|(
operator|-
literal|2
argument_list|)
member_init_list|,
name|m_lastDotInFileName
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|filePath
name|QString
name|QFileSystemEntry
operator|::
name|filePath
parameter_list|()
specifier|const
block|{
name|resolveFilePath
argument_list|()
expr_stmt|;
return|return
name|m_filePath
return|;
block|}
end_function
begin_function
DECL|function|nativeFilePath
name|QFileSystemEntry
operator|::
name|NativePath
name|QFileSystemEntry
operator|::
name|nativeFilePath
parameter_list|()
specifier|const
block|{
name|resolveNativeFilePath
argument_list|()
expr_stmt|;
return|return
name|m_nativeFilePath
return|;
block|}
end_function
begin_function
DECL|function|resolveFilePath
name|void
name|QFileSystemEntry
operator|::
name|resolveFilePath
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_filePath
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|m_nativeFilePath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QFILESYSTEMENTRY_NATIVE_PATH_IS_UTF16
argument_list|)
name|m_filePath
operator|=
name|QDir
operator|::
name|fromNativeSeparators
argument_list|(
name|m_nativeFilePath
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
if|if
condition|(
name|m_filePath
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"//?/UNC/"
argument_list|)
argument_list|)
condition|)
name|m_filePath
operator|=
name|m_filePath
operator|.
name|remove
argument_list|(
literal|2
argument_list|,
literal|6
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_filePath
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"//?/"
argument_list|)
argument_list|)
condition|)
name|m_filePath
operator|=
name|m_filePath
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
literal|4
argument_list|)
expr_stmt|;
endif|#
directive|endif
else|#
directive|else
name|m_filePath
operator|=
name|QDir
operator|::
name|fromNativeSeparators
argument_list|(
name|QFile
operator|::
name|decodeName
argument_list|(
name|m_nativeFilePath
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
begin_function
DECL|function|resolveNativeFilePath
name|void
name|QFileSystemEntry
operator|::
name|resolveNativeFilePath
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_filePath
operator|.
name|isEmpty
argument_list|()
operator|&&
name|m_nativeFilePath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|QString
name|filePath
init|=
name|m_filePath
decl_stmt|;
if|if
condition|(
name|isRelative
argument_list|()
condition|)
name|filePath
operator|=
name|fixIfRelativeUncPath
argument_list|(
name|m_filePath
argument_list|)
expr_stmt|;
name|m_nativeFilePath
operator|=
name|QFSFileEnginePrivate
operator|::
name|longFileName
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|filePath
argument_list|)
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|QFILESYSTEMENTRY_NATIVE_PATH_IS_UTF16
argument_list|)
name|m_nativeFilePath
operator|=
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|m_filePath
argument_list|)
expr_stmt|;
else|#
directive|else
name|m_nativeFilePath
operator|=
name|QFile
operator|::
name|encodeName
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|m_filePath
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
begin_function
DECL|function|fileName
name|QString
name|QFileSystemEntry
operator|::
name|fileName
parameter_list|()
specifier|const
block|{
name|findLastSeparator
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
if|if
condition|(
name|m_lastSeparator
operator|==
operator|-
literal|1
operator|&&
name|m_filePath
operator|.
name|length
argument_list|()
operator|>=
literal|2
operator|&&
name|m_filePath
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
condition|)
return|return
name|m_filePath
operator|.
name|mid
argument_list|(
literal|2
argument_list|)
return|;
endif|#
directive|endif
return|return
name|m_filePath
operator|.
name|mid
argument_list|(
name|m_lastSeparator
operator|+
literal|1
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|path
name|QString
name|QFileSystemEntry
operator|::
name|path
parameter_list|()
specifier|const
block|{
name|findLastSeparator
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_lastSeparator
operator|==
operator|-
literal|1
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
if|if
condition|(
name|m_filePath
operator|.
name|length
argument_list|()
operator|>=
literal|2
operator|&&
name|m_filePath
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
condition|)
return|return
name|m_filePath
operator|.
name|left
argument_list|(
literal|2
argument_list|)
return|;
endif|#
directive|endif
return|return
name|QString
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
argument_list|)
return|;
block|}
if|if
condition|(
name|m_lastSeparator
operator|==
literal|0
condition|)
return|return
name|QString
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
return|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
if|if
condition|(
name|m_lastSeparator
operator|==
literal|2
operator|&&
name|m_filePath
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
condition|)
return|return
name|m_filePath
operator|.
name|left
argument_list|(
name|m_lastSeparator
operator|+
literal|1
argument_list|)
return|;
endif|#
directive|endif
return|return
name|m_filePath
operator|.
name|left
argument_list|(
name|m_lastSeparator
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|baseName
name|QString
name|QFileSystemEntry
operator|::
name|baseName
parameter_list|()
specifier|const
block|{
name|findFileNameSeparators
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
if|if
condition|(
name|m_lastSeparator
operator|==
operator|-
literal|1
operator|&&
name|m_filePath
operator|.
name|length
argument_list|()
operator|>=
literal|2
operator|&&
name|m_filePath
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
condition|)
return|return
name|m_filePath
operator|.
name|mid
argument_list|(
literal|2
argument_list|)
return|;
endif|#
directive|endif
name|int
name|length
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|m_firstDotInFileName
operator|>=
literal|0
condition|)
block|{
name|length
operator|=
name|m_firstDotInFileName
expr_stmt|;
if|if
condition|(
name|m_lastSeparator
operator|!=
operator|-
literal|1
condition|)
comment|// avoid off by one
name|length
operator|--
expr_stmt|;
block|}
return|return
name|m_filePath
operator|.
name|mid
argument_list|(
name|m_lastSeparator
operator|+
literal|1
argument_list|,
name|length
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|completeBaseName
name|QString
name|QFileSystemEntry
operator|::
name|completeBaseName
parameter_list|()
specifier|const
block|{
name|findFileNameSeparators
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
if|if
condition|(
name|m_lastSeparator
operator|==
operator|-
literal|1
operator|&&
name|m_filePath
operator|.
name|length
argument_list|()
operator|>=
literal|2
operator|&&
name|m_filePath
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
condition|)
return|return
name|m_filePath
operator|.
name|mid
argument_list|(
literal|2
argument_list|)
return|;
endif|#
directive|endif
name|int
name|length
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|m_firstDotInFileName
operator|>=
literal|0
condition|)
block|{
name|length
operator|=
name|m_firstDotInFileName
operator|+
name|m_lastDotInFileName
expr_stmt|;
if|if
condition|(
name|m_lastSeparator
operator|!=
operator|-
literal|1
condition|)
comment|// avoid off by one
name|length
operator|--
expr_stmt|;
block|}
return|return
name|m_filePath
operator|.
name|mid
argument_list|(
name|m_lastSeparator
operator|+
literal|1
argument_list|,
name|length
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|suffix
name|QString
name|QFileSystemEntry
operator|::
name|suffix
parameter_list|()
specifier|const
block|{
name|findFileNameSeparators
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_lastDotInFileName
operator|==
operator|-
literal|1
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|m_filePath
operator|.
name|mid
argument_list|(
name|qMax
argument_list|(
operator|(
name|qint16
operator|)
literal|0
argument_list|,
name|m_lastSeparator
argument_list|)
operator|+
name|m_firstDotInFileName
operator|+
name|m_lastDotInFileName
operator|+
literal|1
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|completeSuffix
name|QString
name|QFileSystemEntry
operator|::
name|completeSuffix
parameter_list|()
specifier|const
block|{
name|findFileNameSeparators
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_firstDotInFileName
operator|==
operator|-
literal|1
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|m_filePath
operator|.
name|mid
argument_list|(
name|qMax
argument_list|(
operator|(
name|qint16
operator|)
literal|0
argument_list|,
name|m_lastSeparator
argument_list|)
operator|+
name|m_firstDotInFileName
operator|+
literal|1
argument_list|)
return|;
block|}
end_function
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
end_if
begin_function
DECL|function|isRelative
name|bool
name|QFileSystemEntry
operator|::
name|isRelative
parameter_list|()
specifier|const
block|{
name|resolveFilePath
argument_list|()
expr_stmt|;
return|return
operator|(
name|m_filePath
operator|.
name|isEmpty
argument_list|()
operator|||
operator|(
operator|!
name|m_filePath
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|(
name|m_filePath
index|[
literal|0
index|]
operator|.
name|unicode
argument_list|()
operator|!=
literal|'/'
operator|)
operator|&&
operator|(
operator|!
operator|(
name|m_filePath
operator|.
name|length
argument_list|()
operator|>=
literal|2
operator|&&
name|m_filePath
index|[
literal|1
index|]
operator|.
name|unicode
argument_list|()
operator|==
literal|':'
operator|)
operator|)
operator|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|isAbsolute
name|bool
name|QFileSystemEntry
operator|::
name|isAbsolute
parameter_list|()
specifier|const
block|{
name|resolveFilePath
argument_list|()
expr_stmt|;
return|return
operator|(
operator|!
name|m_filePath
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|(
operator|(
name|m_filePath
operator|.
name|length
argument_list|()
operator|>=
literal|3
operator|&&
operator|(
name|m_filePath
index|[
literal|0
index|]
operator|.
name|isLetter
argument_list|()
operator|&&
name|m_filePath
index|[
literal|1
index|]
operator|.
name|unicode
argument_list|()
operator|==
literal|':'
operator|&&
name|m_filePath
index|[
literal|2
index|]
operator|.
name|unicode
argument_list|()
operator|==
literal|'/'
operator|)
operator|)
ifdef|#
directive|ifdef
name|Q_OS_WIN
operator|||
operator|(
name|m_filePath
operator|.
name|length
argument_list|()
operator|>=
literal|2
operator|&&
operator|(
name|m_filePath
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|&&
name|m_filePath
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|)
operator|)
endif|#
directive|endif
operator|)
operator|)
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_function
DECL|function|isRelative
name|bool
name|QFileSystemEntry
operator|::
name|isRelative
parameter_list|()
specifier|const
block|{
return|return
operator|!
name|isAbsolute
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isAbsolute
name|bool
name|QFileSystemEntry
operator|::
name|isAbsolute
parameter_list|()
specifier|const
block|{
name|resolveFilePath
argument_list|()
expr_stmt|;
return|return
operator|(
operator|!
name|m_filePath
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|(
name|m_filePath
index|[
literal|0
index|]
operator|.
name|unicode
argument_list|()
operator|==
literal|'/'
operator|)
operator|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
end_if
begin_function
DECL|function|isDriveRoot
name|bool
name|QFileSystemEntry
operator|::
name|isDriveRoot
parameter_list|()
specifier|const
block|{
name|resolveFilePath
argument_list|()
expr_stmt|;
return|return
operator|(
name|m_filePath
operator|.
name|length
argument_list|()
operator|==
literal|3
operator|&&
name|m_filePath
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|isLetter
argument_list|()
operator|&&
name|m_filePath
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
name|m_filePath
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|isRoot
name|bool
name|QFileSystemEntry
operator|::
name|isRoot
parameter_list|()
specifier|const
block|{
name|resolveFilePath
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_filePath
operator|==
name|QLatin1String
argument_list|(
literal|"/"
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|||
name|isDriveRoot
argument_list|()
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|isUncRoot
argument_list|(
name|m_filePath
argument_list|)
endif|#
directive|endif
endif|#
directive|endif
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|isEmpty
name|bool
name|QFileSystemEntry
operator|::
name|isEmpty
parameter_list|()
specifier|const
block|{
name|resolveNativeFilePath
argument_list|()
expr_stmt|;
return|return
name|m_nativeFilePath
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// private methods
end_comment
begin_function
DECL|function|findLastSeparator
name|void
name|QFileSystemEntry
operator|::
name|findLastSeparator
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_lastSeparator
operator|==
operator|-
literal|2
condition|)
block|{
name|resolveFilePath
argument_list|()
expr_stmt|;
name|m_lastSeparator
operator|=
operator|-
literal|1
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|m_filePath
operator|.
name|size
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
if|if
condition|(
name|m_filePath
index|[
name|i
index|]
operator|.
name|unicode
argument_list|()
operator|==
literal|'/'
condition|)
block|{
name|m_lastSeparator
operator|=
name|i
expr_stmt|;
break|break;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|findFileNameSeparators
name|void
name|QFileSystemEntry
operator|::
name|findFileNameSeparators
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_firstDotInFileName
operator|==
operator|-
literal|2
condition|)
block|{
name|resolveFilePath
argument_list|()
expr_stmt|;
name|int
name|firstDotInFileName
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|lastDotInFileName
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|lastSeparator
init|=
name|m_lastSeparator
decl_stmt|;
name|int
name|stop
decl_stmt|;
if|if
condition|(
name|lastSeparator
operator|<
literal|0
condition|)
block|{
name|lastSeparator
operator|=
operator|-
literal|1
expr_stmt|;
name|stop
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|stop
operator|=
name|lastSeparator
expr_stmt|;
block|}
name|int
name|i
init|=
name|m_filePath
operator|.
name|size
argument_list|()
operator|-
literal|1
decl_stmt|;
for|for
control|(
init|;
name|i
operator|>=
name|stop
condition|;
operator|--
name|i
control|)
block|{
if|if
condition|(
name|m_filePath
index|[
name|i
index|]
operator|.
name|unicode
argument_list|()
operator|==
literal|'.'
condition|)
block|{
name|firstDotInFileName
operator|=
name|lastDotInFileName
operator|=
name|i
expr_stmt|;
break|break;
block|}
elseif|else
if|if
condition|(
name|m_filePath
index|[
name|i
index|]
operator|.
name|unicode
argument_list|()
operator|==
literal|'/'
condition|)
block|{
name|lastSeparator
operator|=
name|i
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|lastSeparator
operator|!=
name|i
condition|)
block|{
for|for
control|(
operator|--
name|i
init|;
name|i
operator|>=
name|stop
condition|;
operator|--
name|i
control|)
block|{
if|if
condition|(
name|m_filePath
index|[
name|i
index|]
operator|.
name|unicode
argument_list|()
operator|==
literal|'.'
condition|)
name|firstDotInFileName
operator|=
name|i
expr_stmt|;
elseif|else
if|if
condition|(
name|m_filePath
index|[
name|i
index|]
operator|.
name|unicode
argument_list|()
operator|==
literal|'/'
condition|)
block|{
name|lastSeparator
operator|=
name|i
expr_stmt|;
break|break;
block|}
block|}
block|}
name|m_lastSeparator
operator|=
name|lastSeparator
expr_stmt|;
name|m_firstDotInFileName
operator|=
name|firstDotInFileName
operator|==
operator|-
literal|1
condition|?
operator|-
literal|1
else|:
name|firstDotInFileName
operator|-
name|qMax
argument_list|(
literal|0
argument_list|,
name|lastSeparator
argument_list|)
expr_stmt|;
if|if
condition|(
name|lastDotInFileName
operator|==
operator|-
literal|1
condition|)
name|m_lastDotInFileName
operator|=
operator|-
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|firstDotInFileName
operator|==
name|lastDotInFileName
condition|)
name|m_lastDotInFileName
operator|=
literal|0
expr_stmt|;
else|else
name|m_lastDotInFileName
operator|=
name|lastDotInFileName
operator|-
name|firstDotInFileName
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
