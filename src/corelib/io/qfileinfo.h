begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILEINFO_H
end_ifndef
begin_define
DECL|macro|QFILEINFO_H
define|#
directive|define
name|QFILEINFO_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qfile.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetatype.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDir
name|class
name|QDir
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDirIteratorPrivate
name|class
name|QDirIteratorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDateTime
name|class
name|QDateTime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFileInfoPrivate
name|class
name|QFileInfoPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QFileInfo
block|{
name|friend
name|class
name|QDirIteratorPrivate
decl_stmt|;
name|public
label|:
name|explicit
name|QFileInfo
parameter_list|(
name|QFileInfoPrivate
modifier|*
name|d
parameter_list|)
function_decl|;
name|QFileInfo
argument_list|()
expr_stmt|;
name|QFileInfo
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
expr_stmt|;
name|QFileInfo
argument_list|(
specifier|const
name|QFile
operator|&
name|file
argument_list|)
expr_stmt|;
name|QFileInfo
argument_list|(
specifier|const
name|QDir
operator|&
name|dir
argument_list|,
specifier|const
name|QString
operator|&
name|file
argument_list|)
expr_stmt|;
name|QFileInfo
argument_list|(
specifier|const
name|QFileInfo
operator|&
name|fileinfo
argument_list|)
expr_stmt|;
operator|~
name|QFileInfo
argument_list|()
expr_stmt|;
name|QFileInfo
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QFileInfo
operator|&
name|fileinfo
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QFileInfo
modifier|&
name|operator
init|=
operator|(
name|QFileInfo
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d_ptr
argument_list|,
name|other
operator|.
name|d_ptr
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
specifier|inline
name|void
name|swap
parameter_list|(
name|QFileInfo
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d_ptr
argument_list|,
name|other
operator|.
name|d_ptr
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QFileInfo
operator|&
name|fileinfo
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QFileInfo
operator|&
name|fileinfo
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
name|operator
operator|==
operator|(
name|fileinfo
operator|)
operator|)
return|;
block|}
name|void
name|setFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
function_decl|;
name|void
name|setFile
parameter_list|(
specifier|const
name|QFile
modifier|&
name|file
parameter_list|)
function_decl|;
name|void
name|setFile
parameter_list|(
specifier|const
name|QDir
modifier|&
name|dir
parameter_list|,
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
function_decl|;
name|bool
name|exists
argument_list|()
specifier|const
expr_stmt|;
name|void
name|refresh
parameter_list|()
function_decl|;
name|QString
name|filePath
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|absoluteFilePath
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|canonicalFilePath
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|fileName
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|baseName
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|completeBaseName
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|suffix
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|bundleName
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|completeSuffix
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|path
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|absolutePath
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|canonicalPath
argument_list|()
specifier|const
expr_stmt|;
name|QDir
name|dir
argument_list|()
specifier|const
expr_stmt|;
name|QDir
name|absoluteDir
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isReadable
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isWritable
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isExecutable
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isHidden
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isNativePath
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isRelative
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|isAbsolute
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isRelative
argument_list|()
return|;
block|}
name|bool
name|makeAbsolute
parameter_list|()
function_decl|;
name|bool
name|isFile
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isDir
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isSymLink
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isRoot
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isBundle
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|readLink
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|QString
name|symLinkTarget
argument_list|()
specifier|const
block|{
return|return
name|readLink
argument_list|()
return|;
block|}
name|QString
name|owner
argument_list|()
specifier|const
expr_stmt|;
name|uint
name|ownerId
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|group
argument_list|()
specifier|const
expr_stmt|;
name|uint
name|groupId
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|permission
argument_list|(
name|QFile
operator|::
name|Permissions
name|permissions
argument_list|)
decl|const
decl_stmt|;
name|QFile
operator|::
name|Permissions
name|permissions
argument_list|()
specifier|const
expr_stmt|;
name|qint64
name|size
argument_list|()
specifier|const
expr_stmt|;
name|QDateTime
name|created
argument_list|()
specifier|const
expr_stmt|;
name|QDateTime
name|lastModified
argument_list|()
specifier|const
expr_stmt|;
name|QDateTime
name|lastRead
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|caching
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCaching
parameter_list|(
name|bool
name|on
parameter_list|)
function_decl|;
name|protected
label|:
name|QSharedDataPointer
operator|<
name|QFileInfoPrivate
operator|>
name|d_ptr
expr_stmt|;
name|private
label|:
name|QFileInfoPrivate
modifier|*
name|d_func
parameter_list|()
function_decl|;
specifier|inline
specifier|const
name|QFileInfoPrivate
operator|*
name|d_func
argument_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|.
name|constData
argument_list|()
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QFileInfo
argument_list|)
end_macro
begin_typedef
DECL|typedef|QFileInfoList
typedef|typedef
name|QList
operator|<
name|QFileInfo
operator|>
name|QFileInfoList
expr_stmt|;
end_typedef
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QFileInfo
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFILEINFO_H
end_comment
end_unit
