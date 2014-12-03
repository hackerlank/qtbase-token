begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLIBRARYINFO_H
end_ifndef
begin_define
DECL|macro|QLIBRARYINFO_H
define|#
directive|define
name|QLIBRARYINFO_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatetime.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QLibraryInfo
block|{
name|public
label|:
specifier|static
name|QString
name|licensee
parameter_list|()
function_decl|;
specifier|static
name|QString
name|licensedProducts
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_DATESTRING
specifier|static
name|QDate
name|buildDate
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|//QT_NO_DATESTRING
specifier|static
specifier|const
name|char
operator|*
name|build
argument_list|()
name|Q_DECL_NOTHROW
expr_stmt|;
specifier|static
name|bool
name|isDebugBuild
parameter_list|()
function_decl|;
enum|enum
name|LibraryLocation
block|{
name|PrefixPath
init|=
literal|0
block|,
name|DocumentationPath
block|,
name|HeadersPath
block|,
name|LibrariesPath
block|,
name|LibraryExecutablesPath
block|,
name|BinariesPath
block|,
name|PluginsPath
block|,
name|ImportsPath
block|,
name|Qml2ImportsPath
block|,
name|ArchDataPath
block|,
name|DataPath
block|,
name|TranslationsPath
block|,
name|ExamplesPath
block|,
name|TestsPath
block|,
comment|// Insert new values above this line
comment|// Please read the comments in qlibraryinfo.cpp before adding
ifdef|#
directive|ifdef
name|QT_BUILD_QMAKE
comment|// These are not subject to binary compatibility constraints
name|SysrootPath
block|,
name|HostBinariesPath
block|,
name|HostLibrariesPath
block|,
name|HostDataPath
block|,
name|TargetSpecPath
block|,
name|HostSpecPath
block|,
name|HostPrefixPath
block|,
name|LastHostPath
init|=
name|HostPrefixPath
block|,
endif|#
directive|endif
name|SettingsPath
init|=
literal|100
block|}
enum|;
specifier|static
name|QString
name|location
parameter_list|(
name|LibraryLocation
parameter_list|)
function_decl|;
comment|// ### Qt 6: consider renaming it to path()
ifdef|#
directive|ifdef
name|QT_BUILD_QMAKE
enum|enum
name|PathGroup
block|{
name|FinalPaths
block|,
name|EffectivePaths
block|,
name|EffectiveSourcePaths
block|,
name|DevicePaths
block|}
enum|;
specifier|static
name|QString
name|rawLocation
parameter_list|(
name|LibraryLocation
parameter_list|,
name|PathGroup
parameter_list|)
function_decl|;
endif|#
directive|endif
specifier|static
name|QStringList
name|platformPluginArguments
parameter_list|(
specifier|const
name|QString
modifier|&
name|platformName
parameter_list|)
function_decl|;
name|private
label|:
name|QLibraryInfo
argument_list|()
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLIBRARYINFO_H
end_comment
end_unit
