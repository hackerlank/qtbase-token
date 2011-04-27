begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QDirIterator>
end_include
begin_include
include|#
directive|include
file|<QString>
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
begin_include
include|#
directive|include
file|<atlbase.h>
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
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|"qfilesystemiterator.h"
end_include
begin_class
DECL|class|tst_qdiriterator
class|class
name|tst_qdiriterator
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|posix
parameter_list|()
function_decl|;
DECL|function|posix_data
name|void
name|posix_data
parameter_list|()
block|{
name|data
argument_list|()
expr_stmt|;
block|}
name|void
name|diriterator
parameter_list|()
function_decl|;
DECL|function|diriterator_data
name|void
name|diriterator_data
parameter_list|()
block|{
name|data
argument_list|()
expr_stmt|;
block|}
name|void
name|fsiterator
parameter_list|()
function_decl|;
DECL|function|fsiterator_data
name|void
name|fsiterator_data
parameter_list|()
block|{
name|data
argument_list|()
expr_stmt|;
block|}
name|void
name|data
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|data
name|void
name|tst_qdiriterator
operator|::
name|data
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|QByteArray
name|qtdir
init|=
name|qPrintable
argument_list|(
name|QCoreApplication
operator|::
name|applicationDirPath
argument_list|()
argument_list|)
decl_stmt|;
name|qtdir
operator|+=
literal|"/depot"
expr_stmt|;
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
specifier|const
name|char
modifier|*
name|qtdir
init|=
literal|"C:\\depot\\qt\\main"
decl_stmt|;
else|#
directive|else
specifier|const
name|char
modifier|*
name|qtdir
init|=
operator|::
name|getenv
argument_list|(
literal|"QTDIR"
argument_list|)
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|qtdir
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"QTDIR not set\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"dirpath"
argument_list|)
expr_stmt|;
name|QByteArray
name|ba
init|=
name|QByteArray
argument_list|(
name|qtdir
argument_list|)
operator|+
literal|"/src/corelib"
decl_stmt|;
name|QByteArray
name|ba1
init|=
name|ba
operator|+
literal|"/io"
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|ba
argument_list|)
operator|<<
name|ba
expr_stmt|;
comment|//QTest::newRow(ba1)<< ba1;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_function
DECL|function|posix_helper
specifier|static
name|int
name|posix_helper
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|dirpath
parameter_list|)
block|{
name|int
name|count
init|=
literal|0
decl_stmt|;
name|HANDLE
name|hSearch
decl_stmt|;
name|WIN32_FIND_DATA
name|fd
decl_stmt|;
specifier|const
name|size_t
name|origDirPathLength
init|=
name|wcslen
argument_list|(
name|dirpath
argument_list|)
decl_stmt|;
name|wchar_t
name|appendedPath
index|[
name|MAX_PATH
index|]
decl_stmt|;
name|wcscpy
argument_list|(
name|appendedPath
argument_list|,
name|dirpath
argument_list|)
expr_stmt|;
name|wcscat
argument_list|(
name|appendedPath
argument_list|,
literal|L"\\*"
argument_list|)
expr_stmt|;
name|hSearch
operator|=
name|FindFirstFile
argument_list|(
name|appendedPath
argument_list|,
operator|&
name|fd
argument_list|)
expr_stmt|;
name|appendedPath
index|[
name|origDirPathLength
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|hSearch
operator|==
name|INVALID_HANDLE_VALUE
condition|)
block|{
name|qWarning
argument_list|(
literal|"FindFirstFile failed"
argument_list|)
expr_stmt|;
return|return
name|count
return|;
block|}
do|do
block|{
if|if
condition|(
operator|!
operator|(
name|fd
operator|.
name|cFileName
index|[
literal|0
index|]
operator|==
literal|L'
expr|.'
operator|&&
name|fd
operator|.
name|cFileName
index|[
literal|1
index|]
operator|==
literal|0
operator|)
operator|&&
operator|!
operator|(
name|fd
operator|.
name|cFileName
index|[
literal|0
index|]
operator|==
literal|L'
expr|.'
operator|&&
name|fd
operator|.
name|cFileName
index|[
literal|1
index|]
operator|==
literal|L'
expr|.'
operator|&&
name|fd
operator|.
name|cFileName
index|[
literal|2
index|]
operator|==
literal|0
operator|)
condition|)
block|{
if|if
condition|(
name|fd
operator|.
name|dwFileAttributes
operator|&
name|FILE_ATTRIBUTE_DIRECTORY
condition|)
block|{
name|wcscat
argument_list|(
name|appendedPath
argument_list|,
literal|L"\\"
argument_list|)
expr_stmt|;
name|wcscat
argument_list|(
name|appendedPath
argument_list|,
name|fd
operator|.
name|cFileName
argument_list|)
expr_stmt|;
name|count
operator|+=
name|posix_helper
argument_list|(
name|appendedPath
argument_list|)
expr_stmt|;
name|appendedPath
index|[
name|origDirPathLength
index|]
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
operator|++
name|count
expr_stmt|;
block|}
block|}
block|}
do|while
condition|(
name|FindNextFile
argument_list|(
name|hSearch
argument_list|,
operator|&
name|fd
argument_list|)
condition|)
do|;
name|FindClose
argument_list|(
name|hSearch
argument_list|)
expr_stmt|;
return|return
name|count
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_function
DECL|function|posix_helper
specifier|static
name|int
name|posix_helper
parameter_list|(
specifier|const
name|char
modifier|*
name|dirpath
parameter_list|)
block|{
comment|//qDebug()<< "DIR"<< dirpath;
name|DIR
modifier|*
name|dir
init|=
operator|::
name|opendir
argument_list|(
name|dirpath
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|dir
condition|)
return|return
literal|0
return|;
name|dirent
modifier|*
name|entry
init|=
literal|0
decl_stmt|;
name|int
name|count
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|(
name|entry
operator|=
operator|::
name|readdir
argument_list|(
name|dir
argument_list|)
operator|)
condition|)
block|{
if|if
condition|(
name|qstrcmp
argument_list|(
name|entry
operator|->
name|d_name
argument_list|,
literal|"."
argument_list|)
operator|==
literal|0
condition|)
continue|continue;
if|if
condition|(
name|qstrcmp
argument_list|(
name|entry
operator|->
name|d_name
argument_list|,
literal|".."
argument_list|)
operator|==
literal|0
condition|)
continue|continue;
operator|++
name|count
expr_stmt|;
name|QByteArray
name|ba
init|=
name|dirpath
decl_stmt|;
name|ba
operator|+=
literal|'/'
expr_stmt|;
name|ba
operator|+=
name|entry
operator|->
name|d_name
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
name|count
operator|+=
name|posix_helper
argument_list|(
name|ba
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
operator|::
name|closedir
argument_list|(
name|dir
argument_list|)
expr_stmt|;
return|return
name|count
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|posix
name|void
name|tst_qdiriterator
operator|::
name|posix
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|dirpath
argument_list|)
expr_stmt|;
name|int
name|count
init|=
literal|0
decl_stmt|;
name|QString
name|path
argument_list|(
name|dirpath
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|count
operator|=
name|posix_helper
argument_list|(
name|path
operator|.
name|utf16
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|count
operator|=
name|posix_helper
argument_list|(
name|dirpath
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|qDebug
argument_list|()
operator|<<
name|count
expr_stmt|;
block|}
end_function
begin_function
DECL|function|diriterator
name|void
name|tst_qdiriterator
operator|::
name|diriterator
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|dirpath
argument_list|)
expr_stmt|;
name|int
name|count
init|=
literal|0
decl_stmt|;
name|QBENCHMARK
block|{
name|int
name|c
init|=
literal|0
decl_stmt|;
name|QDirIterator
name|dir
argument_list|(
name|dirpath
argument_list|,
comment|//QDir::AllEntries | QDir::Hidden | QDir::NoDotAndDotDot,
comment|//QDir::AllEntries | QDir::Hidden,
name|QDir
operator|::
name|Files
argument_list|,
name|QDirIterator
operator|::
name|Subdirectories
argument_list|)
decl_stmt|;
while|while
condition|(
name|dir
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|dir
operator|.
name|next
argument_list|()
expr_stmt|;
comment|//printf("%s\n", qPrintable(dir.fileName()));
literal|0
operator|&&
name|printf
argument_list|(
literal|"%d %s\n"
argument_list|,
name|dir
operator|.
name|fileInfo
argument_list|()
operator|.
name|isDir
argument_list|()
argument_list|,
comment|//qPrintable(dir.fileInfo().absoluteFilePath()),
comment|//qPrintable(dir.path()),
name|qPrintable
argument_list|(
name|dir
operator|.
name|filePath
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
operator|++
name|c
expr_stmt|;
block|}
name|count
operator|=
name|c
expr_stmt|;
block|}
name|qDebug
argument_list|()
operator|<<
name|count
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fsiterator
name|void
name|tst_qdiriterator
operator|::
name|fsiterator
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|dirpath
argument_list|)
expr_stmt|;
name|int
name|count
init|=
literal|0
decl_stmt|;
name|int
name|dump
init|=
literal|0
decl_stmt|;
name|QBENCHMARK
block|{
name|int
name|c
init|=
literal|0
decl_stmt|;
name|dump
modifier|&&
name|printf
argument_list|(
literal|"\n\n\n\n"
argument_list|)
decl_stmt|;
name|QFileSystemIterator
name|dir
argument_list|(
name|dirpath
argument_list|,
comment|//QDir::AllEntries | QDir::Hidden | QDir::NoDotAndDotDot,
comment|//QDir::AllEntries | QDir::Hidden,
comment|//QDir::Files | QDir::NoDotAndDotDot,
name|QDir
operator|::
name|Files
argument_list|,
name|QFileSystemIterator
operator|::
name|Subdirectories
argument_list|)
decl_stmt|;
for|for
control|(
init|;
operator|!
name|dir
operator|.
name|atEnd
argument_list|()
condition|;
name|dir
operator|.
name|next
argument_list|()
control|)
block|{
name|dump
modifier|&&
name|printf
argument_list|(
literal|"%d %s\n"
argument_list|,
name|dir
operator|.
name|fileInfo
argument_list|()
operator|.
name|isDir
argument_list|()
argument_list|,
comment|//qPrintable(dir.fileInfo().absoluteFilePath()),
comment|//qPrintable(dir.path()),
name|qPrintable
argument_list|(
name|dir
operator|.
name|filePath
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
operator|++
name|c
expr_stmt|;
block|}
name|count
operator|=
name|c
expr_stmt|;
block|}
name|qDebug
argument_list|()
operator|<<
name|count
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qdiriterator
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
