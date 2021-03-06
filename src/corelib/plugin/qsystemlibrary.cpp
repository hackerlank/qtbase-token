begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsystemlibrary_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qvarlengtharray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfileinfo.h>
end_include
begin_comment
comment|/*!      \internal     \class QSystemLibrary     \inmodule QtCore      The purpose of this class is to load only libraries that are located in     well-known and trusted locations on the filesystem. It does not suffer from     the security problem that QLibrary has, therefore it will never search in     the current directory.      The search order is the same as the order in DLL Safe search mode Windows,     except that we don't search:     * The current directory     * The 16-bit system directory. (normally \c{c:\windows\system})     * The Windows directory.  (normally \c{c:\windows})      This means that the effective search order is:     1. Application path.     2. System libraries path.     3. Trying all paths inside the PATH environment variable.      Note, when onlySystemDirectory is true it will skip 1) and 3).      DLL Safe search mode is documented in the "Dynamic-Link Library Search     Order" document on MSDN.      Since library loading code is sometimes shared between Windows and WinCE,     this class can also be used on WinCE. However, its implementation just     calls the LoadLibrary() function. This is ok since it is documented as not     loading from the current directory on WinCE. This behaviour is documented     in the documentation for LoadLibrary for Windows CE at MSDN.     (http://msdn.microsoft.com/en-us/library/ms886736.aspx) */
end_comment
begin_function
name|QT_BEGIN_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
DECL|function|load
name|HINSTANCE
name|QSystemLibrary
operator|::
name|load
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|libraryName
parameter_list|,
name|bool
name|onlySystemDirectory
comment|/* = true */
parameter_list|)
block|{
return|return
operator|::
name|LoadLibrary
argument_list|(
name|libraryName
argument_list|)
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WINRT
argument_list|)
end_elif
begin_function
name|HINSTANCE
name|QSystemLibrary
operator|::
name|load
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|libraryName
parameter_list|,
name|bool
name|onlySystemDirectory
comment|/* = true */
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|onlySystemDirectory
argument_list|)
expr_stmt|;
return|return
operator|::
name|LoadPackagedLibrary
argument_list|(
name|libraryName
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
end_if
begin_function_decl
specifier|extern
name|QString
name|qAppFileName
parameter_list|()
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|static
name|QString
name|qSystemDirectory
parameter_list|()
block|{
name|QVarLengthArray
argument_list|<
name|wchar_t
argument_list|,
name|MAX_PATH
argument_list|>
name|fullPath
decl_stmt|;
name|UINT
name|retLen
init|=
operator|::
name|GetSystemDirectory
argument_list|(
name|fullPath
operator|.
name|data
argument_list|()
argument_list|,
name|MAX_PATH
argument_list|)
decl_stmt|;
if|if
condition|(
name|retLen
operator|>
name|MAX_PATH
condition|)
block|{
name|fullPath
operator|.
name|resize
argument_list|(
name|retLen
argument_list|)
expr_stmt|;
name|retLen
operator|=
operator|::
name|GetSystemDirectory
argument_list|(
name|fullPath
operator|.
name|data
argument_list|()
argument_list|,
name|retLen
argument_list|)
expr_stmt|;
block|}
comment|// in some rare cases retLen might be 0
return|return
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|fullPath
operator|.
name|constData
argument_list|()
argument_list|,
name|int
argument_list|(
name|retLen
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
name|HINSTANCE
name|QSystemLibrary
operator|::
name|load
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|libraryName
parameter_list|,
name|bool
name|onlySystemDirectory
comment|/* = true */
parameter_list|)
block|{
name|QStringList
name|searchOrder
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
if|if
condition|(
operator|!
name|onlySystemDirectory
condition|)
name|searchOrder
operator|<<
name|QFileInfo
argument_list|(
name|qAppFileName
argument_list|()
argument_list|)
operator|.
name|path
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|searchOrder
operator|<<
name|qSystemDirectory
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|onlySystemDirectory
condition|)
block|{
specifier|const
name|QString
name|PATH
argument_list|(
name|QLatin1String
argument_list|(
name|qgetenv
argument_list|(
literal|"PATH"
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|searchOrder
operator|<<
name|PATH
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|';'
argument_list|)
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
expr_stmt|;
block|}
name|QString
name|fileName
init|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|libraryName
argument_list|)
decl_stmt|;
name|fileName
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|".dll"
argument_list|)
argument_list|)
expr_stmt|;
comment|// Start looking in the order specified
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|searchOrder
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|fullPathAttempt
init|=
name|searchOrder
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fullPathAttempt
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
argument_list|)
condition|)
block|{
name|fullPathAttempt
operator|.
name|append
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|fullPathAttempt
operator|.
name|append
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
name|HINSTANCE
name|inst
init|=
operator|::
name|LoadLibrary
argument_list|(
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|fullPathAttempt
operator|.
name|utf16
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|inst
operator|!=
literal|0
condition|)
return|return
name|inst
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//Q_OS_WINCE
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
