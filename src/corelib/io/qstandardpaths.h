begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTANDARDPATHS_H
end_ifndef
begin_define
DECL|macro|QSTANDARDPATHS_H
define|#
directive|define
name|QSTANDARDPATHS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_STANDARDPATHS
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QStandardPaths
block|{
name|public
label|:
comment|// Do not re-order, must match QDesktopServices
enum|enum
name|StandardLocation
block|{
name|DesktopLocation
block|,
name|DocumentsLocation
block|,
name|FontsLocation
block|,
name|ApplicationsLocation
block|,
name|MusicLocation
block|,
name|MoviesLocation
block|,
name|PicturesLocation
block|,
name|TempLocation
block|,
name|HomeLocation
block|,
name|DataLocation
block|,
name|CacheLocation
block|,
name|GenericDataLocation
block|,
name|RuntimeLocation
block|,
name|ConfigLocation
block|,
name|DownloadLocation
block|,
name|GenericCacheLocation
block|}
enum|;
specifier|static
name|QString
name|writableLocation
parameter_list|(
name|StandardLocation
name|type
parameter_list|)
function_decl|;
specifier|static
name|QStringList
name|standardLocations
parameter_list|(
name|StandardLocation
name|type
parameter_list|)
function_decl|;
enum|enum
name|LocateOption
block|{
name|LocateFile
init|=
literal|0x0
block|,
name|LocateDirectory
init|=
literal|0x1
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|LocateOptions
argument_list|,
argument|LocateOption
argument_list|)
specifier|static
name|QString
name|locate
parameter_list|(
name|StandardLocation
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|LocateOptions
name|options
init|=
name|LocateFile
parameter_list|)
function_decl|;
specifier|static
name|QStringList
name|locateAll
parameter_list|(
name|StandardLocation
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|LocateOptions
name|options
init|=
name|LocateFile
parameter_list|)
function_decl|;
specifier|static
name|QString
name|displayName
parameter_list|(
name|StandardLocation
name|type
parameter_list|)
function_decl|;
specifier|static
name|QString
name|findExecutable
parameter_list|(
specifier|const
name|QString
modifier|&
name|executableName
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|paths
init|=
name|QStringList
argument_list|()
parameter_list|)
function_decl|;
specifier|static
name|void
name|enableTestMode
parameter_list|(
name|bool
name|testMode
parameter_list|)
function_decl|;
name|private
label|:
comment|// prevent construction
name|QStandardPaths
argument_list|()
expr_stmt|;
operator|~
name|QStandardPaths
argument_list|()
expr_stmt|;
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
comment|// QT_NO_STANDARDPATHS
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTANDARDPATHS_H
end_comment
end_unit
