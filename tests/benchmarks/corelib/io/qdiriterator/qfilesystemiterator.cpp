begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     \since 4.5     \class QFileSystemIterator     \brief The QFileSystemIterator class provides an iterator for directory entrylists.      You can use QFileSystemIterator to navigate entries of a directory one at a time.     It is similar to QDir::entryList() and QDir::entryInfoList(), but because     it lists entries one at a time instead of all at once, it scales better     and is more suitable for large directories. It also supports listing     directory contents recursively, and following symbolic links. Unlike     QDir::entryList(), QFileSystemIterator does not support sorting.      The QFileSystemIterator constructor takes a QDir or a directory as     argument. After construction, the iterator is located before the first     directory entry. Here's how to iterate over all the entries sequentially:      \snippet doc/src/snippets/code/src.corelib.io.qdiriterator.cpp 0      The next() function returns the path to the next directory entry and     advances the iterator. You can also call filePath() to get the current     file path without advancing the iterator.  The fileName() function returns     only the name of the file, similar to how QDir::entryList() works. You can     also call fileInfo() to get a QFileInfo for the current entry.      Unlike Qt's container iterators, QFileSystemIterator is uni-directional (i.e.,     you cannot iterate directories in reverse order) and does not allow random     access.      QFileSystemIterator works with all supported file engines, and is implemented     using QAbstractFileEngineIterator.      \sa QDir, QDir::entryList(), QAbstractFileEngineIterator */
end_comment
begin_comment
comment|/*! \enum QFileSystemIterator::IteratorFlag      This enum describes flags that you can combine to configure the behavior     of QFileSystemIterator.      \value NoIteratorFlags The default value, representing no flags. The     iterator will return entries for the assigned path.      \value Subdirectories List entries inside all subdirectories as well.      \value FollowSymlinks When combined with Subdirectories, this flag     enables iterating through all subdirectories of the assigned path,     following all symbolic links. Symbolic link loops (e.g., "link" => "." or     "link" => "..") are automatically detected and ignored. */
end_comment
begin_include
include|#
directive|include
file|"qfilesystemiterator.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstack.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<dirent.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QFileSystemIteratorPrivate
class|class
name|QFileSystemIteratorPrivate
block|{
public|public:
name|QFileSystemIteratorPrivate
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|nameFilters
parameter_list|,
name|QDir
operator|::
name|Filters
name|filters
parameter_list|,
name|QFileSystemIterator
operator|::
name|IteratorFlags
name|flags
parameter_list|)
constructor_decl|;
name|~
name|QFileSystemIteratorPrivate
parameter_list|()
destructor_decl|;
name|void
name|pushSubDirectory
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|path
parameter_list|)
function_decl|;
name|void
name|advance
parameter_list|()
function_decl|;
name|bool
name|isAcceptable
parameter_list|()
specifier|const
function_decl|;
name|bool
name|shouldFollowDirectory
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
parameter_list|)
function_decl|;
comment|//bool matchesFilters(const QAbstractFileEngineIterator *it) const;
DECL|function|atEnd
specifier|inline
name|bool
name|atEnd
parameter_list|()
specifier|const
block|{
return|return
name|m_dirPaths
operator|.
name|isEmpty
argument_list|()
return|;
block|}
ifdef|#
directive|ifdef
name|Q_OS_WIN
DECL|member|m_dirStructs
name|QStack
argument_list|<
name|HANDLE
argument_list|>
name|m_dirStructs
decl_stmt|;
DECL|member|m_entry
name|WIN32_FIND_DATA
modifier|*
name|m_entry
decl_stmt|;
DECL|member|m_fileSearchResult
name|WIN32_FIND_DATA
name|m_fileSearchResult
decl_stmt|;
DECL|member|m_bFirstSearchResult
name|bool
name|m_bFirstSearchResult
decl_stmt|;
else|#
directive|else
DECL|member|m_dirStructs
name|QStack
argument_list|<
name|DIR
modifier|*
argument_list|>
name|m_dirStructs
decl_stmt|;
DECL|member|m_entry
name|dirent
modifier|*
name|m_entry
decl_stmt|;
endif|#
directive|endif
DECL|member|visitedLinks
name|QSet
argument_list|<
name|QString
argument_list|>
name|visitedLinks
decl_stmt|;
DECL|member|m_dirPaths
name|QStack
argument_list|<
name|QByteArray
argument_list|>
name|m_dirPaths
decl_stmt|;
DECL|member|fileInfo
name|QFileInfo
name|fileInfo
decl_stmt|;
DECL|member|currentFilePath
name|QString
name|currentFilePath
decl_stmt|;
DECL|member|iteratorFlags
name|QFileSystemIterator
operator|::
name|IteratorFlags
name|iteratorFlags
decl_stmt|;
DECL|member|filters
name|QDir
operator|::
name|Filters
name|filters
decl_stmt|;
DECL|member|nameFilters
name|QStringList
name|nameFilters
decl_stmt|;
DECL|enumerator|DontShowDir
DECL|enumerator|ShowDotDotDir
DECL|enumerator|ShowDotDir
DECL|enumerator|ShowDir
enum|enum
block|{
name|DontShowDir
block|,
name|ShowDotDotDir
block|,
name|ShowDotDir
block|,
name|ShowDir
block|}
DECL|member|m_currentDirShown
DECL|member|m_nextDirShown
name|m_currentDirShown
enum|,
name|m_nextDirShown
expr_stmt|;
DECL|member|q
name|QFileSystemIterator
modifier|*
name|q
decl_stmt|;
private|private:
name|bool
name|advanceHelper
parameter_list|()
function_decl|;
comment|// returns true if we know we have something suitable
block|}
class|;
end_class
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QFileSystemIteratorPrivate
name|QFileSystemIteratorPrivate
operator|::
name|QFileSystemIteratorPrivate
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|nameFilters
parameter_list|,
name|QDir
operator|::
name|Filters
name|filters
parameter_list|,
name|QFileSystemIterator
operator|::
name|IteratorFlags
name|flags
parameter_list|)
member_init_list|:
name|iteratorFlags
argument_list|(
name|flags
argument_list|)
block|{
if|if
condition|(
name|filters
operator|==
name|QDir
operator|::
name|NoFilter
condition|)
name|filters
operator|=
name|QDir
operator|::
name|AllEntries
expr_stmt|;
name|this
operator|->
name|filters
operator|=
name|filters
expr_stmt|;
name|this
operator|->
name|nameFilters
operator|=
name|nameFilters
expr_stmt|;
name|fileInfo
operator|.
name|setFile
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|QString
name|dir
init|=
name|fileInfo
operator|.
name|isSymLink
argument_list|()
condition|?
name|fileInfo
operator|.
name|canonicalFilePath
argument_list|()
else|:
name|path
decl_stmt|;
name|pushSubDirectory
argument_list|(
name|dir
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
expr_stmt|;
comment|// skip to acceptable entry
while|while
condition|(
literal|true
condition|)
block|{
if|if
condition|(
name|atEnd
argument_list|()
condition|)
return|return;
if|if
condition|(
name|isAcceptable
argument_list|()
condition|)
return|return;
if|if
condition|(
name|advanceHelper
argument_list|()
condition|)
return|return;
block|}
block|}
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_destructor
DECL|function|~QFileSystemIteratorPrivate
name|QFileSystemIteratorPrivate
operator|::
name|~
name|QFileSystemIteratorPrivate
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_OS_WIN
while|while
condition|(
operator|!
name|m_dirStructs
operator|.
name|isEmpty
argument_list|()
condition|)
operator|::
name|FindClose
argument_list|(
name|m_dirStructs
operator|.
name|pop
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
while|while
condition|(
operator|!
name|m_dirStructs
operator|.
name|isEmpty
argument_list|()
condition|)
operator|::
name|closedir
argument_list|(
name|m_dirStructs
operator|.
name|pop
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_destructor
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_function
DECL|function|isDotOrDotDot
specifier|static
name|bool
name|isDotOrDotDot
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|name
parameter_list|)
block|{
if|if
condition|(
name|name
index|[
literal|0
index|]
operator|==
literal|L'
expr|.'
operator|&&
name|name
index|[
literal|1
index|]
operator|==
literal|0
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|name
index|[
literal|0
index|]
operator|==
literal|L'
expr|.'
operator|&&
name|name
index|[
literal|1
index|]
operator|==
literal|L'
expr|.'
operator|&&
name|name
index|[
literal|2
index|]
operator|==
literal|0
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_function
DECL|function|isDotOrDotDot
specifier|static
name|bool
name|isDotOrDotDot
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
if|if
condition|(
name|name
index|[
literal|0
index|]
operator|==
literal|'.'
operator|&&
name|name
index|[
literal|1
index|]
operator|==
literal|0
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|name
index|[
literal|0
index|]
operator|==
literal|'.'
operator|&&
name|name
index|[
literal|1
index|]
operator|==
literal|'.'
operator|&&
name|name
index|[
literal|2
index|]
operator|==
literal|0
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|pushSubDirectory
name|void
name|QFileSystemIteratorPrivate
operator|::
name|pushSubDirectory
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|path
parameter_list|)
block|{
comment|/*     if (iteratorFlags& QFileSystemIterator::FollowSymlinks) {         if (fileInfo.filePath() != path)             fileInfo.setFile(path);         if (fileInfo.isSymLink()) {             visitedLinks<< fileInfo.canonicalFilePath();         } else {             visitedLinks<< fileInfo.absoluteFilePath();         }     } */
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|wchar_t
name|szSearchPath
index|[
name|MAX_PATH
index|]
decl_stmt|;
name|QString
operator|::
name|fromLatin1
argument_list|(
name|path
argument_list|)
operator|.
name|toWCharArray
argument_list|(
name|szSearchPath
argument_list|)
expr_stmt|;
name|wcscat
argument_list|(
name|szSearchPath
argument_list|,
literal|L"\\*"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_WINRT
name|HANDLE
name|dir
init|=
name|FindFirstFile
argument_list|(
name|szSearchPath
argument_list|,
operator|&
name|m_fileSearchResult
argument_list|)
decl_stmt|;
else|#
directive|else
name|HANDLE
name|dir
init|=
name|FindFirstFileEx
argument_list|(
name|szSearchPath
argument_list|,
name|FindExInfoStandard
argument_list|,
operator|&
name|m_fileSearchResult
argument_list|,
name|FindExSearchLimitToDirectories
argument_list|,
name|NULL
argument_list|,
name|FIND_FIRST_EX_LARGE_FETCH
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|m_bFirstSearchResult
operator|=
literal|true
expr_stmt|;
else|#
directive|else
name|DIR
modifier|*
name|dir
init|=
operator|::
name|opendir
argument_list|(
name|path
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
comment|//m_entry = ::readdir(dir);
comment|//while (m_entry&& isDotOrDotDot(m_entry->d_name))
comment|//    m_entry = ::readdir(m_dirStructs.top());
endif|#
directive|endif
name|m_dirStructs
operator|.
name|append
argument_list|(
name|dir
argument_list|)
expr_stmt|;
name|m_dirPaths
operator|.
name|append
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|m_entry
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|filters
operator|&
name|QDir
operator|::
name|Dirs
condition|)
name|m_nextDirShown
operator|=
name|ShowDir
expr_stmt|;
else|else
name|m_nextDirShown
operator|=
name|DontShowDir
expr_stmt|;
name|m_currentDirShown
operator|=
name|DontShowDir
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|isAcceptable
name|bool
name|QFileSystemIteratorPrivate
operator|::
name|isAcceptable
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_entry
condition|)
return|return
literal|false
return|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|advance
name|void
name|QFileSystemIteratorPrivate
operator|::
name|advance
parameter_list|()
block|{
while|while
condition|(
literal|true
condition|)
block|{
if|if
condition|(
name|advanceHelper
argument_list|()
condition|)
return|return;
if|if
condition|(
name|atEnd
argument_list|()
condition|)
return|return;
if|if
condition|(
name|isAcceptable
argument_list|()
condition|)
return|return;
block|}
block|}
end_function
begin_function
DECL|function|advanceHelper
name|bool
name|QFileSystemIteratorPrivate
operator|::
name|advanceHelper
parameter_list|()
block|{
if|if
condition|(
name|m_dirStructs
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|true
return|;
comment|//printf("ADV %d %d\n", int(m_currentDirShown), int(m_nextDirShown));
if|if
condition|(
operator|(
name|filters
operator|&
name|QDir
operator|::
name|Dirs
operator|)
condition|)
block|{
name|m_currentDirShown
operator|=
name|m_nextDirShown
expr_stmt|;
if|if
condition|(
name|m_nextDirShown
operator|==
name|ShowDir
condition|)
block|{
comment|//printf("RESTING ON DIR %s %x\n", m_dirPaths.top().constData(), int(filters));
name|m_nextDirShown
operator|=
operator|(
name|filters
operator|&
name|QDir
operator|::
name|NoDotAndDotDot
operator|)
condition|?
name|DontShowDir
else|:
name|ShowDotDir
expr_stmt|;
comment|// skip start directory itself
if|if
condition|(
name|m_dirStructs
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
name|m_currentDirShown
operator|==
name|ShowDir
condition|)
return|return
name|advanceHelper
argument_list|()
return|;
return|return
literal|true
return|;
block|}
if|if
condition|(
name|m_nextDirShown
operator|==
name|ShowDotDir
condition|)
block|{
comment|//printf("RESTING ON DOT %s %x\n", m_dirPaths.top().constData(), int(filters));
name|m_nextDirShown
operator|=
name|ShowDotDotDir
expr_stmt|;
return|return
literal|true
return|;
block|}
if|if
condition|(
name|m_nextDirShown
operator|==
name|ShowDotDotDir
condition|)
block|{
comment|//printf("RESTING ON DOTDOT %s %x\n", m_dirPaths.top().constData(), int(filters));
name|m_nextDirShown
operator|=
name|DontShowDir
expr_stmt|;
return|return
literal|true
return|;
block|}
name|m_currentDirShown
operator|=
name|DontShowDir
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|m_entry
operator|=
operator|&
name|m_fileSearchResult
expr_stmt|;
if|if
condition|(
name|m_bFirstSearchResult
condition|)
block|{
name|m_bFirstSearchResult
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|FindNextFile
argument_list|(
name|m_dirStructs
operator|.
name|top
argument_list|()
argument_list|,
name|m_entry
argument_list|)
condition|)
name|m_entry
operator|=
literal|0
expr_stmt|;
block|}
while|while
condition|(
name|m_entry
operator|&&
name|isDotOrDotDot
argument_list|(
name|m_entry
operator|->
name|cFileName
argument_list|)
condition|)
if|if
condition|(
operator|!
name|FindNextFile
argument_list|(
name|m_dirStructs
operator|.
name|top
argument_list|()
argument_list|,
name|m_entry
argument_list|)
condition|)
name|m_entry
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|m_entry
condition|)
block|{
name|m_dirPaths
operator|.
name|pop
argument_list|()
expr_stmt|;
name|FindClose
argument_list|(
name|m_dirStructs
operator|.
name|pop
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|m_entry
operator|->
name|dwFileAttributes
operator|&
name|FILE_ATTRIBUTE_DIRECTORY
condition|)
block|{
name|QByteArray
name|ba
init|=
name|m_dirPaths
operator|.
name|top
argument_list|()
decl_stmt|;
name|ba
operator|+=
literal|'\\'
expr_stmt|;
name|ba
operator|+=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|m_entry
operator|->
name|cFileName
argument_list|)
expr_stmt|;
name|pushSubDirectory
argument_list|(
name|ba
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|m_entry
operator|=
operator|::
name|readdir
argument_list|(
name|m_dirStructs
operator|.
name|top
argument_list|()
argument_list|)
expr_stmt|;
while|while
condition|(
name|m_entry
operator|&&
name|isDotOrDotDot
argument_list|(
name|m_entry
operator|->
name|d_name
argument_list|)
condition|)
name|m_entry
operator|=
operator|::
name|readdir
argument_list|(
name|m_dirStructs
operator|.
name|top
argument_list|()
argument_list|)
expr_stmt|;
comment|//return false; // further iteration possibly needed
comment|//printf("READ %p %s\n", m_entry, m_entry ? m_entry->d_name : "");
if|if
condition|(
operator|!
name|m_entry
condition|)
block|{
name|m_dirPaths
operator|.
name|pop
argument_list|()
expr_stmt|;
name|DIR
modifier|*
name|dir
init|=
name|m_dirStructs
operator|.
name|pop
argument_list|()
decl_stmt|;
operator|::
name|closedir
argument_list|(
name|dir
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
comment|// further iteration possibly needed
block|}
specifier|const
name|char
modifier|*
name|name
init|=
name|m_entry
operator|->
name|d_name
decl_stmt|;
name|QByteArray
name|ba
init|=
name|m_dirPaths
operator|.
name|top
argument_list|()
decl_stmt|;
name|ba
operator|+=
literal|'/'
expr_stmt|;
name|ba
operator|+=
name|name
expr_stmt|;
name|struct
name|stat
name|st
decl_stmt|;
name|lstat
argument_list|(
name|ba
operator|.
name|constData
argument_list|()
argument_list|,
operator|&
name|st
argument_list|)
expr_stmt|;
if|if
condition|(
name|S_ISDIR
argument_list|(
name|st
operator|.
name|st_mode
argument_list|)
condition|)
block|{
name|pushSubDirectory
argument_list|(
name|ba
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
comment|// further iteration possibly needed
block|}
endif|#
directive|endif
return|return
literal|false
return|;
comment|// further iteration possiblye needed
block|}
end_function
begin_comment
comment|/*!     \internal  */
end_comment
begin_function
DECL|function|shouldFollowDirectory
name|bool
name|QFileSystemIteratorPrivate
operator|::
name|shouldFollowDirectory
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fileInfo
parameter_list|)
block|{
comment|// If we're doing flat iteration, we're done.
if|if
condition|(
operator|!
operator|(
name|iteratorFlags
operator|&
name|QFileSystemIterator
operator|::
name|Subdirectories
operator|)
condition|)
return|return
literal|false
return|;
comment|// Never follow non-directory entries
if|if
condition|(
operator|!
name|fileInfo
operator|.
name|isDir
argument_list|()
condition|)
return|return
literal|false
return|;
comment|// Never follow . and ..
if|if
condition|(
name|fileInfo
operator|.
name|fileName
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"."
argument_list|)
operator|||
name|fileInfo
operator|.
name|fileName
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|".."
argument_list|)
condition|)
return|return
literal|false
return|;
comment|// Check symlinks
if|if
condition|(
name|fileInfo
operator|.
name|isSymLink
argument_list|()
operator|&&
operator|!
operator|(
name|iteratorFlags
operator|&
name|QFileSystemIterator
operator|::
name|FollowSymlinks
operator|)
condition|)
block|{
comment|// Follow symlinks only if FollowSymlinks was passed
return|return
literal|false
return|;
block|}
comment|// Stop link loops
if|if
condition|(
name|visitedLinks
operator|.
name|contains
argument_list|(
name|fileInfo
operator|.
name|canonicalFilePath
argument_list|()
argument_list|)
condition|)
return|return
literal|false
return|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     \internal      This convenience function implements the iterator's filtering logics and     applies then to the current directory entry.      It returns true if the current entry matches the filters (i.e., the     current entry will be returned as part of the directory iteration);     otherwise, false is returned. */
end_comment
begin_if
if|#
directive|if
literal|0
end_if
begin_ifndef
unit|bool QFileSystemIteratorPrivate::matchesFilters(const QAbstractFileEngineIterator *it) const {     const bool filterPermissions = ((filters& QDir::PermissionMask)&& (filters& QDir::PermissionMask) != QDir::PermissionMask);     const bool skipDirs     = !(filters& (QDir::Dirs | QDir::AllDirs));     const bool skipFiles    = !(filters& QDir::Files);     const bool skipSymlinks = (filters& QDir::NoSymLinks);     const bool doReadable   = !filterPermissions || (filters& QDir::Readable);     const bool doWritable   = !filterPermissions || (filters& QDir::Writable);     const bool doExecutable = !filterPermissions || (filters& QDir::Executable);     const bool includeHidden = (filters& QDir::Hidden);     const bool includeSystem = (filters& QDir::System);
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
end_ifndef
begin_comment
comment|// Prepare name filters
end_comment
begin_endif
unit|QList<QRegExp> regexps;     bool hasNameFilters = !nameFilters.isEmpty()&& !(nameFilters.contains(QLatin1String("*")));     if (hasNameFilters) {         for (int i = 0; i< nameFilters.size(); ++i) {             regexps<< QRegExp(nameFilters.at(i),                                (filters& QDir::CaseSensitive) ? Qt::CaseSensitive : Qt::CaseInsensitive,                                QRegExp::Wildcard);         }     }
endif|#
directive|endif
end_endif
begin_comment
unit|QString fileName = it->currentFileName();     if (fileName.isEmpty()) {
comment|// invalid entry
end_comment
begin_ifndef
unit|return false;     }      QFileInfo fi = it->currentFileInfo();     QString filePath = it->currentFilePath();
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
end_ifndef
begin_comment
comment|// Pass all entries through name filters, except dirs if the AllDirs
end_comment
begin_comment
comment|// filter is passed.
end_comment
begin_endif
unit|if (hasNameFilters&& !((filters& QDir::AllDirs)&& fi.isDir())) {         bool matched = false;         for (int i = 0; i< regexps.size(); ++i) {             if (regexps.at(i).exactMatch(fileName)) {                 matched = true;                 break;             }         }         if (!matched)             return false;     }
endif|#
directive|endif
end_endif
begin_comment
unit|bool dotOrDotDot = (fileName == QLatin1String(".") || fileName == QLatin1String(".."));     if ((filters& QDir::NoDotAndDotDot)&& dotOrDotDot)         return false;      bool isHidden = !dotOrDotDot&& fi.isHidden();     if (!includeHidden&& isHidden)         return false;      bool isSystem = (!fi.isFile()&& !fi.isDir()&& !fi.isSymLink())                     || (!fi.exists()&& fi.isSymLink());     if (!includeSystem&& isSystem)         return false;      bool alwaysShow = (filters& QDir::TypeMask) == 0&& ((isHidden&& includeHidden)             || (includeSystem&& isSystem));
comment|// Skip files and directories
end_comment
begin_endif
unit|if ((filters& QDir::AllDirs) == 0&& skipDirs&& fi.isDir()) {         if (!alwaysShow)             return false;     }      if ((skipFiles&& (fi.isFile() || !fi.exists()))         || (skipSymlinks&& fi.isSymLink())) {         if (!alwaysShow)             return false;     }      if (filterPermissions&& ((doReadable&& !fi.isReadable())             || (doWritable&& !fi.isWritable())             || (doExecutable&& !fi.isExecutable()))) {         return false;     }      if (!includeSystem&& !dotOrDotDot&& ((fi.exists()&& !fi.isFile()&& !fi.isDir()&& !fi.isSymLink())                                            || (!fi.exists()&& fi.isSymLink()))) {         return false;     }      return true; }
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     Constructs a QFileSystemIterator that can iterate over \a dir's entrylist, using     \a dir's name filters and regular filters. You can pass options via \a     flags to decide how the directory should be iterated.      By default, \a flags is NoIteratorFlags, which provides the same behavior     as in QDir::entryList().      The sorting in \a dir is ignored.      \sa atEnd(), next(), IteratorFlags */
end_comment
begin_constructor
DECL|function|QFileSystemIterator
name|QFileSystemIterator
operator|::
name|QFileSystemIterator
parameter_list|(
specifier|const
name|QDir
modifier|&
name|dir
parameter_list|,
name|IteratorFlags
name|flags
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QFileSystemIteratorPrivate
argument_list|(
name|dir
operator|.
name|path
argument_list|()
argument_list|,
name|dir
operator|.
name|nameFilters
argument_list|()
argument_list|,
name|dir
operator|.
name|filter
argument_list|()
argument_list|,
name|flags
argument_list|)
argument_list|)
block|{
name|d
operator|->
name|q
operator|=
name|this
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QFileSystemIterator that can iterate over \a path, with no name     filtering and \a filters for entry filtering. You can pass options via \a     flags to decide how the directory should be iterated.      By default, \a filters is QDir::NoFilter, and \a flags is NoIteratorFlags,     which provides the same behavior as in QDir::entryList().      \sa atEnd(), next(), IteratorFlags */
end_comment
begin_constructor
DECL|function|QFileSystemIterator
name|QFileSystemIterator
operator|::
name|QFileSystemIterator
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
name|QDir
operator|::
name|Filters
name|filters
parameter_list|,
name|IteratorFlags
name|flags
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QFileSystemIteratorPrivate
argument_list|(
name|path
argument_list|,
name|QStringList
argument_list|(
name|QLatin1String
argument_list|(
literal|"*"
argument_list|)
argument_list|)
argument_list|,
name|filters
argument_list|,
name|flags
argument_list|)
argument_list|)
block|{
name|d
operator|->
name|q
operator|=
name|this
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QFileSystemIterator that can iterate over \a path. You can pass     options via \a flags to decide how the directory should be iterated.      By default, \a flags is NoIteratorFlags, which provides the same behavior     as in QDir::entryList().      \sa atEnd(), next(), IteratorFlags */
end_comment
begin_constructor
DECL|function|QFileSystemIterator
name|QFileSystemIterator
operator|::
name|QFileSystemIterator
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
name|IteratorFlags
name|flags
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QFileSystemIteratorPrivate
argument_list|(
name|path
argument_list|,
name|QStringList
argument_list|(
name|QLatin1String
argument_list|(
literal|"*"
argument_list|)
argument_list|)
argument_list|,
name|QDir
operator|::
name|NoFilter
argument_list|,
name|flags
argument_list|)
argument_list|)
block|{
name|d
operator|->
name|q
operator|=
name|this
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QFileSystemIterator that can iterate over \a path, using \a     nameFilters and \a filters. You can pass options via \a flags to decide     how the directory should be iterated.      By default, \a flags is NoIteratorFlags, which provides the same behavior     as QDir::entryList().      \sa atEnd(), next(), IteratorFlags */
end_comment
begin_constructor
DECL|function|QFileSystemIterator
name|QFileSystemIterator
operator|::
name|QFileSystemIterator
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|nameFilters
parameter_list|,
name|QDir
operator|::
name|Filters
name|filters
parameter_list|,
name|IteratorFlags
name|flags
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QFileSystemIteratorPrivate
argument_list|(
name|path
argument_list|,
name|nameFilters
argument_list|,
name|filters
argument_list|,
name|flags
argument_list|)
argument_list|)
block|{
name|d
operator|->
name|q
operator|=
name|this
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the QFileSystemIterator. */
end_comment
begin_destructor
DECL|function|~QFileSystemIterator
name|QFileSystemIterator
operator|::
name|~
name|QFileSystemIterator
parameter_list|()
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Advances the iterator to the next entry, and returns the file path of this     new entry. If atEnd() returns true, this function does nothing, and     returns a null QString.      You can call fileName() or filePath() to get the current entry file name     or path, or fileInfo() to get a QFileInfo for the current entry.      \sa hasNext(), fileName(), filePath(), fileInfo() */
end_comment
begin_function
DECL|function|next
name|void
name|QFileSystemIterator
operator|::
name|next
parameter_list|()
block|{
name|d
operator|->
name|advance
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns true if there is at least one more entry in the directory;     otherwise, false is returned.      \sa next(), fileName(), filePath(), fileInfo() */
end_comment
begin_function
DECL|function|atEnd
name|bool
name|QFileSystemIterator
operator|::
name|atEnd
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|atEnd
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the file name for the current directory entry, without the path     prepended. If the current entry is invalid (i.e., isValid() returns     false), a null QString is returned.      This function is provided for the convenience when iterating single     directories. For recursive iteration, you should call filePath() or     fileInfo() instead.      \sa filePath(), fileInfo() */
end_comment
begin_function
DECL|function|fileName
name|QString
name|QFileSystemIterator
operator|::
name|fileName
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|atEnd
argument_list|()
operator|||
operator|!
name|d
operator|->
name|m_entry
condition|)
return|return
name|QString
argument_list|()
return|;
if|if
condition|(
name|d
operator|->
name|m_currentDirShown
operator|==
name|QFileSystemIteratorPrivate
operator|::
name|ShowDir
condition|)
return|return
name|QString
argument_list|()
return|;
if|if
condition|(
name|d
operator|->
name|m_currentDirShown
operator|==
name|QFileSystemIteratorPrivate
operator|::
name|ShowDotDir
condition|)
return|return
name|QLatin1String
argument_list|(
literal|"@"
argument_list|)
return|;
if|if
condition|(
name|d
operator|->
name|m_currentDirShown
operator|==
name|QFileSystemIteratorPrivate
operator|::
name|ShowDotDotDir
condition|)
return|return
name|QLatin1String
argument_list|(
literal|"@@"
argument_list|)
return|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
return|return
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|d
operator|->
name|m_entry
operator|->
name|cFileName
argument_list|)
return|;
else|#
directive|else
return|return
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|d
operator|->
name|m_entry
operator|->
name|d_name
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*!     Returns the full file path for the current directory entry. If the current     entry is invalid (i.e., isValid() returns false), a null QString is     returned.      \sa fileInfo(), fileName() */
end_comment
begin_function
DECL|function|filePath
name|QString
name|QFileSystemIterator
operator|::
name|filePath
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|atEnd
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
name|QByteArray
name|ba
init|=
name|d
operator|->
name|m_dirPaths
operator|.
name|top
argument_list|()
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|m_currentDirShown
operator|==
name|QFileSystemIteratorPrivate
operator|::
name|ShowDotDir
condition|)
name|ba
operator|+=
literal|"/."
expr_stmt|;
elseif|else
if|if
condition|(
name|d
operator|->
name|m_currentDirShown
operator|==
name|QFileSystemIteratorPrivate
operator|::
name|ShowDotDotDir
condition|)
name|ba
operator|+=
literal|"/.."
expr_stmt|;
elseif|else
if|if
condition|(
name|d
operator|->
name|m_entry
condition|)
block|{
name|ba
operator|+=
literal|'/'
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|ba
operator|+=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|d
operator|->
name|m_entry
operator|->
name|cFileName
argument_list|)
expr_stmt|;
else|#
directive|else
name|ba
operator|+=
name|d
operator|->
name|m_entry
operator|->
name|d_name
expr_stmt|;
endif|#
directive|endif
block|}
return|return
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|ba
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a QFileInfo for the current directory entry. If the current entry     is invalid (i.e., isValid() returns false), a null QFileInfo is returned.      \sa filePath(), fileName() */
end_comment
begin_function
DECL|function|fileInfo
name|QFileInfo
name|QFileSystemIterator
operator|::
name|fileInfo
parameter_list|()
specifier|const
block|{
return|return
name|QFileInfo
argument_list|(
name|filePath
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the base directory of the iterator. */
end_comment
begin_function
DECL|function|path
name|QString
name|QFileSystemIterator
operator|::
name|path
parameter_list|()
specifier|const
block|{
return|return
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|d
operator|->
name|m_dirPaths
operator|.
name|top
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
