begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDIR_PRIVATE_H
end_ifndef
begin_define
DECL|macro|QDIR_PRIVATE_H
define|#
directive|define
name|QDIR_PRIVATE_H
end_define
begin_include
include|#
directive|include
file|"qfilesystementry_p.h"
end_include
begin_include
include|#
directive|include
file|"qfilesystemmetadata_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QDirPrivate
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
name|QDirPrivate
argument_list|(
argument|const QString&path
argument_list|,
argument|const QStringList&nameFilters_ = QStringList()
argument_list|,
argument|QDir::SortFlags sort_ = QDir::SortFlags(QDir::Name | QDir::IgnoreCase)
argument_list|,
argument|QDir::Filters filters_ = QDir::AllEntries
argument_list|)
block|;
name|QDirPrivate
argument_list|(
specifier|const
name|QDirPrivate
operator|&
name|copy
argument_list|)
block|;
name|bool
name|exists
argument_list|()
specifier|const
block|;
name|void
name|initFileEngine
argument_list|()
block|;
name|void
name|initFileLists
argument_list|(
argument|const QDir&dir
argument_list|)
specifier|const
block|;
specifier|static
name|void
name|sortFileList
argument_list|(
name|QDir
operator|::
name|SortFlags
argument_list|,
name|QFileInfoList
operator|&
argument_list|,
name|QStringList
operator|*
argument_list|,
name|QFileInfoList
operator|*
argument_list|)
block|;
specifier|static
specifier|inline
name|QChar
name|getFilterSepChar
argument_list|(
specifier|const
name|QString
operator|&
name|nameFilter
argument_list|)
block|;
specifier|static
specifier|inline
name|QStringList
name|splitFilters
argument_list|(
argument|const QString&nameFilter
argument_list|,
argument|QChar sep =
literal|0
argument_list|)
block|;
specifier|inline
name|void
name|setPath
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
specifier|inline
name|void
name|clearFileLists
argument_list|()
block|;
specifier|inline
name|void
name|resolveAbsoluteEntry
argument_list|()
specifier|const
block|;
name|QStringList
name|nameFilters
block|;
name|QDir
operator|::
name|SortFlags
name|sort
block|;
name|QDir
operator|::
name|Filters
name|filters
block|;
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|QChar
name|filterSepChar
block|;
name|bool
name|matchAllDirs
block|;
endif|#
directive|endif
name|QScopedPointer
operator|<
name|QAbstractFileEngine
operator|>
name|fileEngine
block|;
name|mutable
name|bool
name|fileListsInitialized
block|;
name|mutable
name|QStringList
name|files
block|;
name|mutable
name|QFileInfoList
name|fileInfos
block|;
name|QFileSystemEntry
name|dirEntry
block|;
name|mutable
name|QFileSystemEntry
name|absoluteDirEntry
block|;
name|mutable
name|QFileSystemMetaData
name|metaData
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
end_unit
