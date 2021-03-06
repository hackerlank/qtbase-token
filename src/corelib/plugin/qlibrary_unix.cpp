begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|"qlibrary_p.h"
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<private/qfilesystementry_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_MAC
end_ifdef
begin_include
include|#
directive|include
file|<private/qcore_mac_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_AOUT_UNDERSCORE
argument_list|)
end_if
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VXWORKS_RTP
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|Q_OS_NACL
argument_list|)
end_if
begin_define
DECL|macro|QT_NO_DYNAMIC_LIBRARY
define|#
directive|define
name|QT_NO_DYNAMIC_LIBRARY
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_HPUX_LD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_DYNAMIC_LIBRARY
argument_list|)
name|QT_BEGIN_INCLUDE_NAMESPACE
include|#
directive|include
file|<dlfcn.h>
name|QT_END_INCLUDE_NAMESPACE
endif|#
directive|endif
DECL|function|qdlerror
specifier|static
name|QString
name|qdlerror
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_DYNAMIC_LIBRARY
argument_list|)
specifier|const
name|char
modifier|*
name|err
init|=
literal|"This platform does not support dynamic libraries."
decl_stmt|;
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|QT_HPUX_LD
argument_list|)
specifier|const
name|char
modifier|*
name|err
init|=
name|dlerror
argument_list|()
decl_stmt|;
else|#
directive|else
specifier|const
name|char
modifier|*
name|err
init|=
name|strerror
argument_list|(
name|errno
argument_list|)
decl_stmt|;
endif|#
directive|endif
return|return
name|err
condition|?
name|QLatin1Char
argument_list|(
literal|'('
argument_list|)
operator|+
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|err
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|')'
argument_list|)
else|:
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|suffixes_sys
name|QStringList
name|QLibraryPrivate
operator|::
name|suffixes_sys
parameter_list|(
specifier|const
name|QString
modifier|&
name|fullVersion
parameter_list|)
block|{
name|QStringList
name|suffixes
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_HPUX
argument_list|)
comment|// according to
comment|// http://docs.hp.com/en/B2355-90968/linkerdifferencesiapa.htm
comment|// In PA-RISC (PA-32 and PA-64) shared libraries are suffixed
comment|// with .sl. In IPF (32-bit and 64-bit), the shared libraries
comment|// are suffixed with .so. For compatibility, the IPF linker
comment|// also supports the .sl suffix.
comment|// But since we don't know if we are built on HPUX or HPUXi,
comment|// we support both .sl (and .<version>) and .so suffixes but
comment|// .so is preferred.
if|#
directive|if
name|defined
argument_list|(
name|__ia64
argument_list|)
if|if
condition|(
operator|!
name|fullVersion
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|suffixes
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|".so.%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|fullVersion
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|suffixes
operator|<<
name|QLatin1String
argument_list|(
literal|".so"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
operator|!
name|fullVersion
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|suffixes
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|".sl.%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|fullVersion
argument_list|)
expr_stmt|;
name|suffixes
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|".%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|fullVersion
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|suffixes
operator|<<
name|QLatin1String
argument_list|(
literal|".sl"
argument_list|)
expr_stmt|;
block|}
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_AIX
argument_list|)
name|suffixes
operator|<<
literal|".a"
expr_stmt|;
else|#
directive|else
if|if
condition|(
operator|!
name|fullVersion
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|suffixes
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|".so.%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|fullVersion
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|suffixes
operator|<<
name|QLatin1String
argument_list|(
literal|".so"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_MAC
if|if
condition|(
operator|!
name|fullVersion
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|suffixes
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|".%1.bundle"
argument_list|)
operator|.
name|arg
argument_list|(
name|fullVersion
argument_list|)
expr_stmt|;
name|suffixes
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|".%1.dylib"
argument_list|)
operator|.
name|arg
argument_list|(
name|fullVersion
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|suffixes
operator|<<
name|QLatin1String
argument_list|(
literal|".bundle"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|".dylib"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|suffixes
return|;
block|}
end_function
begin_function
DECL|function|prefixes_sys
name|QStringList
name|QLibraryPrivate
operator|::
name|prefixes_sys
parameter_list|()
block|{
return|return
name|QStringList
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"lib"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|load_sys
name|bool
name|QLibraryPrivate
operator|::
name|load_sys
parameter_list|()
block|{
name|QString
name|attempt
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DYNAMIC_LIBRARY
argument_list|)
name|QFileSystemEntry
name|fsEntry
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
name|QString
name|path
init|=
name|fsEntry
operator|.
name|path
argument_list|()
decl_stmt|;
name|QString
name|name
init|=
name|fsEntry
operator|.
name|fileName
argument_list|()
decl_stmt|;
if|if
condition|(
name|path
operator|==
name|QLatin1String
argument_list|(
literal|"."
argument_list|)
operator|&&
operator|!
name|fileName
operator|.
name|startsWith
argument_list|(
name|path
argument_list|)
condition|)
name|path
operator|.
name|clear
argument_list|()
expr_stmt|;
else|else
name|path
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
expr_stmt|;
name|QStringList
name|suffixes
decl_stmt|;
name|QStringList
name|prefixes
decl_stmt|;
if|if
condition|(
name|pluginState
operator|!=
name|IsAPlugin
condition|)
block|{
name|prefixes
operator|=
name|prefixes_sys
argument_list|()
expr_stmt|;
name|suffixes
operator|=
name|suffixes_sys
argument_list|(
name|fullVersion
argument_list|)
expr_stmt|;
block|}
name|int
name|dlFlags
init|=
literal|0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QT_HPUX_LD
argument_list|)
name|dlFlags
operator|=
name|DYNAMIC_PATH
operator||
name|BIND_NONFATAL
expr_stmt|;
if|if
condition|(
name|loadHints
operator|&
name|QLibrary
operator|::
name|ResolveAllSymbolsHint
condition|)
block|{
name|dlFlags
operator||=
name|BIND_IMMEDIATE
expr_stmt|;
block|}
else|else
block|{
name|dlFlags
operator||=
name|BIND_DEFERRED
expr_stmt|;
block|}
else|#
directive|else
name|int
name|loadHints
init|=
name|this
operator|->
name|loadHints
argument_list|()
decl_stmt|;
if|if
condition|(
name|loadHints
operator|&
name|QLibrary
operator|::
name|ResolveAllSymbolsHint
condition|)
block|{
name|dlFlags
operator||=
name|RTLD_NOW
expr_stmt|;
block|}
else|else
block|{
name|dlFlags
operator||=
name|RTLD_LAZY
expr_stmt|;
block|}
if|if
condition|(
name|loadHints
operator|&
name|QLibrary
operator|::
name|ExportExternalSymbolsHint
condition|)
block|{
name|dlFlags
operator||=
name|RTLD_GLOBAL
expr_stmt|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_CYGWIN
argument_list|)
else|else
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
if|if
condition|(
name|QSysInfo
operator|::
name|MacintoshVersion
operator|>=
name|QSysInfo
operator|::
name|MV_10_4
condition|)
endif|#
directive|endif
name|dlFlags
operator||=
name|RTLD_LOCAL
expr_stmt|;
block|}
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|RTLD_DEEPBIND
argument_list|)
if|if
condition|(
name|loadHints
operator|&
name|QLibrary
operator|::
name|DeepBindHint
condition|)
name|dlFlags
operator||=
name|RTLD_DEEPBIND
expr_stmt|;
endif|#
directive|endif
comment|// Provide access to RTLD_NODELETE flag on Unix
comment|// From GNU documentation on RTLD_NODELETE:
comment|// Do not unload the library during dlclose(). Consequently, the
comment|// library's specific static variables are not reinitialized if the
comment|// library is reloaded with dlopen() at a later time.
ifdef|#
directive|ifdef
name|RTLD_NODELETE
if|if
condition|(
name|loadHints
operator|&
name|QLibrary
operator|::
name|PreventUnloadHint
condition|)
block|{
name|dlFlags
operator||=
name|RTLD_NODELETE
expr_stmt|;
block|}
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_AIX
argument_list|)
comment|// Not sure if any other platform actually support this thing.
if|if
condition|(
name|loadHints
operator|&
name|QLibrary
operator|::
name|LoadArchiveMemberHint
condition|)
block|{
name|dlFlags
operator||=
name|RTLD_MEMBER
expr_stmt|;
block|}
endif|#
directive|endif
endif|#
directive|endif
comment|// QT_HPUX_LD
comment|// If the filename is an absolute path then we want to try that first as it is most likely
comment|// what the callee wants. If we have been given a non-absolute path then lets try the
comment|// native library name first to avoid unnecessary calls to dlopen().
if|if
condition|(
name|fsEntry
operator|.
name|isAbsolute
argument_list|()
condition|)
block|{
name|suffixes
operator|.
name|prepend
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|prefixes
operator|.
name|prepend
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|suffixes
operator|.
name|append
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|prefixes
operator|.
name|append
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|bool
name|retry
init|=
literal|true
decl_stmt|;
for|for
control|(
name|int
name|prefix
init|=
literal|0
init|;
name|retry
operator|&&
operator|!
name|pHnd
operator|&&
name|prefix
operator|<
name|prefixes
operator|.
name|size
argument_list|()
condition|;
name|prefix
operator|++
control|)
block|{
for|for
control|(
name|int
name|suffix
init|=
literal|0
init|;
name|retry
operator|&&
operator|!
name|pHnd
operator|&&
name|suffix
operator|<
name|suffixes
operator|.
name|size
argument_list|()
condition|;
name|suffix
operator|++
control|)
block|{
if|if
condition|(
operator|!
name|prefixes
operator|.
name|at
argument_list|(
name|prefix
argument_list|)
operator|.
name|isEmpty
argument_list|()
operator|&&
name|name
operator|.
name|startsWith
argument_list|(
name|prefixes
operator|.
name|at
argument_list|(
name|prefix
argument_list|)
argument_list|)
condition|)
continue|continue;
if|if
condition|(
operator|!
name|suffixes
operator|.
name|at
argument_list|(
name|suffix
argument_list|)
operator|.
name|isEmpty
argument_list|()
operator|&&
name|name
operator|.
name|endsWith
argument_list|(
name|suffixes
operator|.
name|at
argument_list|(
name|suffix
argument_list|)
argument_list|)
condition|)
continue|continue;
if|if
condition|(
name|loadHints
operator|&
name|QLibrary
operator|::
name|LoadArchiveMemberHint
condition|)
block|{
name|attempt
operator|=
name|name
expr_stmt|;
name|int
name|lparen
init|=
name|attempt
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'('
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|lparen
operator|==
operator|-
literal|1
condition|)
name|lparen
operator|=
name|attempt
operator|.
name|count
argument_list|()
expr_stmt|;
name|attempt
operator|=
name|path
operator|+
name|prefixes
operator|.
name|at
argument_list|(
name|prefix
argument_list|)
operator|+
name|attempt
operator|.
name|insert
argument_list|(
name|lparen
argument_list|,
name|suffixes
operator|.
name|at
argument_list|(
name|suffix
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|attempt
operator|=
name|path
operator|+
name|prefixes
operator|.
name|at
argument_list|(
name|prefix
argument_list|)
operator|+
name|name
operator|+
name|suffixes
operator|.
name|at
argument_list|(
name|suffix
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|QT_HPUX_LD
argument_list|)
name|pHnd
operator|=
operator|(
name|void
operator|*
operator|)
name|shl_load
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|attempt
argument_list|)
argument_list|,
name|dlFlags
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
name|pHnd
operator|=
name|dlopen
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|attempt
argument_list|)
argument_list|,
name|dlFlags
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|pHnd
operator|&&
name|fileName
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
operator|&&
name|QFile
operator|::
name|exists
argument_list|(
name|attempt
argument_list|)
condition|)
block|{
comment|// We only want to continue if dlopen failed due to that the shared library did not exist.
comment|// However, we are only able to apply this check for absolute filenames (since they are
comment|// not influenced by the content of LD_LIBRARY_PATH, /etc/ld.so.cache, DT_RPATH etc...)
comment|// This is all because dlerror is flawed and cannot tell us the reason why it failed.
name|retry
operator|=
literal|false
expr_stmt|;
block|}
block|}
block|}
ifdef|#
directive|ifdef
name|Q_OS_MAC
if|if
condition|(
operator|!
name|pHnd
condition|)
block|{
name|QByteArray
name|utf8Bundle
init|=
name|fileName
operator|.
name|toUtf8
argument_list|()
decl_stmt|;
name|QCFType
argument_list|<
name|CFURLRef
argument_list|>
name|bundleUrl
init|=
name|CFURLCreateFromFileSystemRepresentation
argument_list|(
name|NULL
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|UInt8
operator|*
argument_list|>
argument_list|(
name|utf8Bundle
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
name|utf8Bundle
operator|.
name|length
argument_list|()
argument_list|,
literal|true
argument_list|)
decl_stmt|;
name|QCFType
argument_list|<
name|CFBundleRef
argument_list|>
name|bundle
init|=
name|CFBundleCreate
argument_list|(
name|NULL
argument_list|,
name|bundleUrl
argument_list|)
decl_stmt|;
if|if
condition|(
name|bundle
condition|)
block|{
name|QCFType
argument_list|<
name|CFURLRef
argument_list|>
name|url
init|=
name|CFBundleCopyExecutableURL
argument_list|(
name|bundle
argument_list|)
decl_stmt|;
name|char
name|executableFile
index|[
name|FILENAME_MAX
index|]
decl_stmt|;
name|CFURLGetFileSystemRepresentation
argument_list|(
name|url
argument_list|,
literal|true
argument_list|,
cast|reinterpret_cast
argument_list|<
name|UInt8
operator|*
argument_list|>
argument_list|(
name|executableFile
argument_list|)
argument_list|,
name|FILENAME_MAX
argument_list|)
expr_stmt|;
name|attempt
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|executableFile
argument_list|)
expr_stmt|;
name|pHnd
operator|=
name|dlopen
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|attempt
argument_list|)
argument_list|,
name|dlFlags
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
endif|#
directive|endif
comment|// QT_NO_DYNAMIC_LIBRARY
if|if
condition|(
operator|!
name|pHnd
condition|)
block|{
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"Cannot load library %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
operator|.
name|arg
argument_list|(
name|qdlerror
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|pHnd
condition|)
block|{
name|qualifiedFileName
operator|=
name|attempt
expr_stmt|;
name|errorString
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
return|return
operator|(
name|pHnd
operator|!=
literal|0
operator|)
return|;
block|}
end_function
begin_function
DECL|function|unload_sys
name|bool
name|QLibraryPrivate
operator|::
name|unload_sys
parameter_list|()
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DYNAMIC_LIBRARY
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|QT_HPUX_LD
argument_list|)
if|if
condition|(
name|shl_unload
argument_list|(
operator|(
name|shl_t
operator|)
name|pHnd
argument_list|)
condition|)
block|{
else|#
directive|else
if|if
condition|(
name|dlclose
argument_list|(
name|pHnd
argument_list|)
condition|)
block|{
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_QNX
argument_list|)
comment|// Workaround until fixed in QNX; fixes crash in
name|char
modifier|*
name|error
init|=
name|dlerror
argument_list|()
decl_stmt|;
comment|// QtDeclarative auto test "qqmlenginecleanup" for instance
if|if
condition|(
operator|!
name|qstrcmp
argument_list|(
name|error
argument_list|,
literal|"Shared objects still referenced"
argument_list|)
condition|)
comment|// On QNX that's only "informative"
return|return
literal|true
return|;
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"Cannot unload library %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|error
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"Cannot unload library %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
operator|.
name|arg
argument_list|(
name|qdlerror
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
endif|#
directive|endif
name|errorString
operator|.
name|clear
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_DYNAMIC_LIBRARY
argument_list|)
DECL|function|qt_linux_find_symbol_sys
name|Q_CORE_EXPORT
name|QFunctionPointer
name|qt_linux_find_symbol_sys
parameter_list|(
specifier|const
name|char
modifier|*
name|symbol
parameter_list|)
block|{
return|return
name|QFunctionPointer
argument_list|(
name|dlsym
argument_list|(
name|RTLD_DEFAULT
argument_list|,
name|symbol
argument_list|)
argument_list|)
return|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_MAC
DECL|function|qt_mac_resolve_sys
name|Q_CORE_EXPORT
name|QFunctionPointer
name|qt_mac_resolve_sys
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
name|symbol
parameter_list|)
block|{
return|return
name|QFunctionPointer
argument_list|(
name|dlsym
argument_list|(
name|handle
argument_list|,
name|symbol
argument_list|)
argument_list|)
return|;
block|}
endif|#
directive|endif
DECL|function|resolve_sys
name|QFunctionPointer
name|QLibraryPrivate
operator|::
name|resolve_sys
parameter_list|(
specifier|const
name|char
modifier|*
name|symbol
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QT_AOUT_UNDERSCORE
argument_list|)
comment|// older a.out systems add an underscore in front of symbols
name|char
modifier|*
name|undrscr_symbol
init|=
operator|new
name|char
index|[
name|strlen
argument_list|(
name|symbol
argument_list|)
operator|+
literal|2
index|]
decl_stmt|;
name|undrscr_symbol
index|[
literal|0
index|]
operator|=
literal|'_'
expr_stmt|;
name|strcpy
argument_list|(
name|undrscr_symbol
operator|+
literal|1
argument_list|,
name|symbol
argument_list|)
expr_stmt|;
name|QFunctionPointer
name|address
init|=
name|QFunctionPointer
argument_list|(
name|dlsym
argument_list|(
name|pHnd
argument_list|,
name|undrscr_symbol
argument_list|)
argument_list|)
decl_stmt|;
operator|delete
index|[]
name|undrscr_symbol
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|QT_HPUX_LD
argument_list|)
name|QFunctionPointer
name|address
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|shl_findsym
argument_list|(
operator|(
name|shl_t
operator|*
operator|)
operator|&
name|pHnd
argument_list|,
name|symbol
argument_list|,
name|TYPE_UNDEFINED
argument_list|,
operator|&
name|address
argument_list|)
operator|<
literal|0
condition|)
name|address
operator|=
literal|0
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|QT_NO_DYNAMIC_LIBRARY
argument_list|)
name|QFunctionPointer
name|address
init|=
literal|0
decl_stmt|;
else|#
directive|else
name|QFunctionPointer
name|address
init|=
name|QFunctionPointer
argument_list|(
name|dlsym
argument_list|(
name|pHnd
argument_list|,
name|symbol
argument_list|)
argument_list|)
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|address
condition|)
block|{
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"Cannot resolve symbol \"%1\" in %2: %3"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|symbol
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
operator|.
name|arg
argument_list|(
name|qdlerror
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|errorString
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
return|return
name|address
return|;
block|}
name|QT_END_NAMESPACE
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LIBRARY
end_comment
end_unit
