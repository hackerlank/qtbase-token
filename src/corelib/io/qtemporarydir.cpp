begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtemporarydir.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEMPORARYFILE
end_ifndef
begin_include
include|#
directive|include
file|"qdiriterator.h"
end_include
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_BUILD_CORE_LIB
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qcoreapplication.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_comment
comment|// mkdtemp
end_comment
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
file|<private/qfsfileengine_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|//************* QTemporaryDirPrivate
end_comment
begin_class
DECL|class|QTemporaryDirPrivate
class|class
name|QTemporaryDirPrivate
block|{
public|public:
name|QTemporaryDirPrivate
parameter_list|()
constructor_decl|;
name|~
name|QTemporaryDirPrivate
parameter_list|()
destructor_decl|;
name|void
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|templateName
parameter_list|)
function_decl|;
DECL|member|path
name|QString
name|path
decl_stmt|;
DECL|member|autoRemove
name|bool
name|autoRemove
decl_stmt|;
DECL|member|success
name|bool
name|success
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QTemporaryDirPrivate
name|QTemporaryDirPrivate
operator|::
name|QTemporaryDirPrivate
parameter_list|()
member_init_list|:
name|autoRemove
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|success
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QTemporaryDirPrivate
name|QTemporaryDirPrivate
operator|::
name|~
name|QTemporaryDirPrivate
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|defaultTemplateName
specifier|static
name|QString
name|defaultTemplateName
parameter_list|()
block|{
name|QString
name|baseName
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QT_BUILD_CORE_LIB
argument_list|)
name|baseName
operator|=
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
expr_stmt|;
if|if
condition|(
name|baseName
operator|.
name|isEmpty
argument_list|()
condition|)
endif|#
directive|endif
name|baseName
operator|=
name|QLatin1String
argument_list|(
literal|"qt_temp"
argument_list|)
expr_stmt|;
return|return
name|QDir
operator|::
name|tempPath
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|baseName
operator|+
name|QLatin1String
argument_list|(
literal|"-XXXXXX"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|create
name|void
name|QTemporaryDirPrivate
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|templateName
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|QString
name|buffer
init|=
name|templateName
decl_stmt|;
comment|// Windows' mktemp believes 26 temp files per process ought to be enough for everyone (!)
comment|// Let's add a few random chars then, before the XXXXXX template.
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
operator|++
name|i
control|)
name|buffer
operator|+=
name|QChar
argument_list|(
operator|(
name|qrand
argument_list|()
operator|&
literal|0xffff
operator|)
operator|%
operator|(
literal|26
operator|)
operator|+
literal|'A'
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|buffer
operator|.
name|endsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"XXXXXX"
argument_list|)
argument_list|)
condition|)
name|buffer
operator|+=
name|QLatin1String
argument_list|(
literal|"XXXXXX"
argument_list|)
expr_stmt|;
name|QFileSystemEntry
name|baseEntry
argument_list|(
name|buffer
argument_list|)
decl_stmt|;
name|QFileSystemEntry
operator|::
name|NativePath
name|basePath
init|=
name|baseEntry
operator|.
name|nativeFilePath
argument_list|()
decl_stmt|;
name|wchar_t
modifier|*
name|array
init|=
operator|(
name|wchar_t
operator|*
operator|)
name|basePath
operator|.
name|utf16
argument_list|()
decl_stmt|;
if|if
condition|(
name|_wmktemp
argument_list|(
name|array
argument_list|)
operator|&&
operator|::
name|CreateDirectory
argument_list|(
name|array
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|success
operator|=
literal|true
expr_stmt|;
name|QFileSystemEntry
name|entry
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|array
argument_list|)
argument_list|,
name|QFileSystemEntry
operator|::
name|FromNativePath
argument_list|()
argument_list|)
decl_stmt|;
name|path
operator|=
name|entry
operator|.
name|filePath
argument_list|()
expr_stmt|;
block|}
else|#
directive|else
name|QByteArray
name|buffer
init|=
name|QFile
operator|::
name|encodeName
argument_list|(
name|templateName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|buffer
operator|.
name|endsWith
argument_list|(
literal|"XXXXXX"
argument_list|)
condition|)
name|buffer
operator|+=
literal|"XXXXXX"
expr_stmt|;
if|if
condition|(
name|mkdtemp
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|)
condition|)
block|{
comment|// modifies buffer
name|success
operator|=
literal|true
expr_stmt|;
name|path
operator|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|buffer
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_comment
comment|//************* QTemporaryDir
end_comment
begin_comment
comment|/*!     \class QTemporaryDir     \reentrant     \brief The QTemporaryDir class creates a unique directory for temporary use.      \ingroup io       QTemporaryDir is used to create unique temporary dirs safely.     The dir itself is created by the constructor. The name of the     temporary directory is guaranteed to be unique (i.e., you are     guaranteed to not overwrite an existing dir), and the directory will     subsequently be removed upon destruction of the QTemporaryDir     object. The directory name is either auto-generated, or created based     on a template, which is passed to QTemporaryDir's constructor.      Example:      \snippet doc/src/snippets/code/src_corelib_io_qtemporarydir.cpp 0      It is very important to test that the temporary directory could be     created, using isValid(). Do not use exists(), since a default-constructed     QDir represents the current directory, which exists.      The path to the temporary dir can be found by calling path().      A temporary directory will have some static part of the name and some     part that is calculated to be unique. The default path will be     determined from QCoreApplication::applicationName() (otherwise \c qt_temp) and will     be placed into the temporary path as returned by QDir::tempPath().     If you specify your own path, a relative path will not be placed in the     temporary directory by default, but be relative to the current working directory.     In all cases, a random string will be appended to the path in order to make it unique.      \sa QDir::tempPath(), QDir, QTemporaryFile */
end_comment
begin_comment
comment|/*!     Constructs a QTemporaryDir using as template the application name     returned by QCoreApplication::applicationName() (otherwise \c qt_temp).     The directory is stored in the system's temporary directory, QDir::tempPath().      \sa QDir::tempPath() */
end_comment
begin_constructor
DECL|function|QTemporaryDir
name|QTemporaryDir
operator|::
name|QTemporaryDir
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QTemporaryDirPrivate
argument_list|)
block|{
name|d_ptr
operator|->
name|create
argument_list|(
name|defaultTemplateName
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QTemporaryFile with a template name of \a templateName.      If \a templateName is a relative path, the path will be relative to the     current working directory. You can use QDir::tempPath() to construct \a     templateName if you want use the system's temporary directory.      If the \a templateName ends with XXXXXX it will be used as the dynamic portion     of the directory name, otherwise it will be appended.     Unlike QTemporaryFile, XXXXXX in the middle of the template string is not supported.      \sa QDir::tempPath() */
end_comment
begin_constructor
DECL|function|QTemporaryDir
name|QTemporaryDir
operator|::
name|QTemporaryDir
parameter_list|(
specifier|const
name|QString
modifier|&
name|templateName
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QTemporaryDirPrivate
argument_list|)
block|{
if|if
condition|(
name|templateName
operator|.
name|isEmpty
argument_list|()
condition|)
name|d_ptr
operator|->
name|create
argument_list|(
name|defaultTemplateName
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|d_ptr
operator|->
name|create
argument_list|(
name|templateName
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the temporary directory object.     If auto remove mode was set, it will automatically delete the directory     including all its contents.      \sa autoRemove() */
end_comment
begin_destructor
DECL|function|~QTemporaryDir
name|QTemporaryDir
operator|::
name|~
name|QTemporaryDir
parameter_list|()
block|{
if|if
condition|(
name|d_ptr
operator|->
name|autoRemove
condition|)
name|remove
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!    Returns true if the QTemporaryDir was created successfully. */
end_comment
begin_function
DECL|function|isValid
name|bool
name|QTemporaryDir
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|success
return|;
block|}
end_function
begin_comment
comment|/*!    Returns the path to the temporary directory.    Empty if the QTemporaryDir could not be created. */
end_comment
begin_function
DECL|function|path
name|QString
name|QTemporaryDir
operator|::
name|path
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|path
return|;
block|}
end_function
begin_comment
comment|/*!    Returns true if the QTemporaryDir is in auto remove    mode. Auto-remove mode will automatically delete the directory from    disk upon destruction. This makes it very easy to create your    QTemporaryDir object on the stack, fill it with files, do something with    the files, and finally on function return it will automatically clean up    after itself.     Auto-remove is on by default.     \sa setAutoRemove(), remove() */
end_comment
begin_function
DECL|function|autoRemove
name|bool
name|QTemporaryDir
operator|::
name|autoRemove
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|autoRemove
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the QTemporaryDir into auto-remove mode if \a b is true.      Auto-remove is on by default.      \sa autoRemove(), remove() */
end_comment
begin_function
DECL|function|setAutoRemove
name|void
name|QTemporaryDir
operator|::
name|setAutoRemove
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|d_ptr
operator|->
name|autoRemove
operator|=
name|b
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Removes the temporary directory, including all its contents. */
end_comment
begin_function
DECL|function|remove
name|bool
name|QTemporaryDir
operator|::
name|remove
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d_ptr
operator|->
name|success
condition|)
return|return
literal|false
return|;
name|Q_ASSERT
argument_list|(
operator|!
name|path
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|path
argument_list|()
operator|!=
name|QLatin1String
argument_list|(
literal|"."
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|QDir
argument_list|(
name|path
argument_list|()
argument_list|)
operator|.
name|removeRecursively
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
comment|// QT_NO_TEMPORARYFILE
end_comment
end_unit
