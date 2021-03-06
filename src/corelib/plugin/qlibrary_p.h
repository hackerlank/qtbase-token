begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLIBRARY_P_H
end_ifndef
begin_define
DECL|macro|QLIBRARY_P_H
define|#
directive|define
name|QLIBRARY_P_H
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
file|"QtCore/qlibrary.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpointer.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstringlist.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qplugin.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qsharedpointer.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qjsonobject.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qjsondocument.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qendian.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|"QtCore/qt_windows.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
comment|// Needed also in case of QT_NO_LIBRARY, for static plugin loading.
DECL|function|qJsonFromRawLibraryMetaData
specifier|inline
name|QJsonDocument
name|qJsonFromRawLibraryMetaData
parameter_list|(
specifier|const
name|char
modifier|*
name|raw
parameter_list|)
block|{
name|raw
operator|+=
name|strlen
argument_list|(
literal|"QTMETADATA  "
argument_list|)
expr_stmt|;
comment|// the size of the embedded JSON object can be found 8 bytes into the data (see qjson_p.h),
comment|// but doesn't include the size of the header (8 bytes)
name|QByteArray
name|json
argument_list|(
name|raw
argument_list|,
name|qFromLittleEndian
operator|<
name|uint
operator|>
operator|(
operator|*
operator|(
specifier|const
name|uint
operator|*
operator|)
operator|(
name|raw
operator|+
literal|8
operator|)
operator|)
operator|+
literal|8
argument_list|)
decl_stmt|;
return|return
name|QJsonDocument
operator|::
name|fromBinaryData
argument_list|(
name|json
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_function_decl
name|bool
name|qt_debug_component
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|QLibraryStore
name|class
name|QLibraryStore
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QLibraryPrivate
block|{
name|public
label|:
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|HINSTANCE
else|#
directive|else
name|void
modifier|*
endif|#
directive|endif
name|pHnd
decl_stmt|;
enum|enum
name|UnloadFlag
block|{
name|UnloadSys
block|,
name|NoUnloadSys
block|}
enum|;
name|QString
name|fileName
decl_stmt|,
name|qualifiedFileName
decl_stmt|;
name|QString
name|fullVersion
decl_stmt|;
name|bool
name|load
parameter_list|()
function_decl|;
name|bool
name|loadPlugin
parameter_list|()
function_decl|;
comment|// loads and resolves instance
name|bool
name|unload
parameter_list|(
name|UnloadFlag
name|flag
init|=
name|UnloadSys
parameter_list|)
function_decl|;
name|void
name|release
parameter_list|()
function_decl|;
name|QFunctionPointer
name|resolve
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|QLibrary
operator|::
name|LoadHints
name|loadHints
argument_list|()
specifier|const
block|{
return|return
name|QLibrary
operator|::
name|LoadHints
argument_list|(
name|loadHintsInt
operator|.
name|load
argument_list|()
argument_list|)
return|;
block|}
name|void
name|setLoadHints
argument_list|(
name|QLibrary
operator|::
name|LoadHints
name|lh
argument_list|)
decl_stmt|;
specifier|static
name|QLibraryPrivate
modifier|*
name|findOrCreate
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|QString
operator|&
name|version
operator|=
name|QString
argument_list|()
argument_list|,
name|QLibrary
operator|::
name|LoadHints
name|loadHints
operator|=
literal|0
argument_list|)
decl_stmt|;
specifier|static
name|QStringList
name|suffixes_sys
parameter_list|(
specifier|const
name|QString
modifier|&
name|fullVersion
parameter_list|)
function_decl|;
specifier|static
name|QStringList
name|prefixes_sys
parameter_list|()
function_decl|;
name|QPointer
operator|<
name|QObject
operator|>
name|inst
expr_stmt|;
name|QtPluginInstanceFunction
name|instance
decl_stmt|;
name|QJsonObject
name|metaData
decl_stmt|;
name|QString
name|errorString
decl_stmt|;
name|void
name|updatePluginState
parameter_list|()
function_decl|;
name|bool
name|isPlugin
parameter_list|()
function_decl|;
name|private
label|:
name|explicit
name|QLibraryPrivate
argument_list|(
specifier|const
name|QString
operator|&
name|canonicalFileName
argument_list|,
specifier|const
name|QString
operator|&
name|version
argument_list|,
name|QLibrary
operator|::
name|LoadHints
name|loadHints
argument_list|)
decl_stmt|;
operator|~
name|QLibraryPrivate
argument_list|()
expr_stmt|;
name|void
name|mergeLoadHints
argument_list|(
name|QLibrary
operator|::
name|LoadHints
name|loadHints
argument_list|)
decl_stmt|;
name|bool
name|load_sys
parameter_list|()
function_decl|;
name|bool
name|unload_sys
parameter_list|()
function_decl|;
name|QFunctionPointer
name|resolve_sys
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|QAtomicInt
name|loadHintsInt
decl_stmt|;
comment|/// counts how many QLibrary or QPluginLoader are attached to us, plus 1 if it's loaded
name|QAtomicInt
name|libraryRefCount
decl_stmt|;
comment|/// counts how many times load() or loadPlugin() were called
name|QAtomicInt
name|libraryUnloadCount
decl_stmt|;
enum|enum
block|{
name|IsAPlugin
block|,
name|IsNotAPlugin
block|,
name|MightBeAPlugin
block|}
name|pluginState
enum|;
name|friend
name|class
name|QLibraryStore
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LIBRARY
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLIBRARY_P_H
end_comment
end_unit
