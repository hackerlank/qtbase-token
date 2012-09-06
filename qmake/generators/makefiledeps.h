begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MAKEFILEDEPS_H
end_ifndef
begin_define
DECL|macro|MAKEFILEDEPS_H
define|#
directive|define
name|MAKEFILEDEPS_H
end_define
begin_include
include|#
directive|include
file|<proitems.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qfileinfo.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct_decl
struct_decl|struct
name|SourceFile
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|SourceDependChildren
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|SourceFiles
name|class
name|SourceFiles
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QMakeLocalFileName
block|{
name|uint
name|is_null
range|:
literal|1
decl_stmt|;
name|mutable
name|QString
name|real_name
decl_stmt|,
name|local_name
decl_stmt|;
name|public
label|:
name|QMakeLocalFileName
argument_list|()
operator|:
name|is_null
argument_list|(
literal|1
argument_list|)
block|{ }
name|QMakeLocalFileName
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
expr_stmt|;
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|is_null
return|;
block|}
specifier|inline
specifier|const
name|QString
operator|&
name|real
argument_list|()
specifier|const
block|{
return|return
name|real_name
return|;
block|}
specifier|const
name|QString
operator|&
name|local
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QMakeLocalFileName
operator|&
name|other
operator|)
block|{
return|return
operator|(
name|this
operator|->
name|real_name
operator|==
name|other
operator|.
name|real_name
operator|)
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QMakeLocalFileName
operator|&
name|other
operator|)
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QMakeSourceFileInfo
block|{
name|private
label|:
comment|//quick project lookups
name|SourceFiles
modifier|*
name|files
decl_stmt|,
modifier|*
name|includes
decl_stmt|;
name|bool
name|files_changed
decl_stmt|;
name|QList
operator|<
name|QMakeLocalFileName
operator|>
name|depdirs
expr_stmt|;
comment|//sleezy buffer code
name|char
modifier|*
name|spare_buffer
decl_stmt|;
name|int
name|spare_buffer_size
decl_stmt|;
name|char
modifier|*
name|getBuffer
parameter_list|(
name|int
name|s
parameter_list|)
function_decl|;
comment|//actual guts
name|bool
name|findMocs
parameter_list|(
name|SourceFile
modifier|*
parameter_list|)
function_decl|;
name|bool
name|findDeps
parameter_list|(
name|SourceFile
modifier|*
parameter_list|)
function_decl|;
name|void
name|dependTreeWalker
parameter_list|(
name|SourceFile
modifier|*
parameter_list|,
name|SourceDependChildren
modifier|*
parameter_list|)
function_decl|;
comment|//cache
name|QString
name|cachefile
decl_stmt|;
name|protected
label|:
name|virtual
name|QMakeLocalFileName
name|fixPathForFile
parameter_list|(
specifier|const
name|QMakeLocalFileName
modifier|&
parameter_list|,
name|bool
name|forOpen
init|=
name|false
parameter_list|)
function_decl|;
name|virtual
name|QMakeLocalFileName
name|findFileForDep
parameter_list|(
specifier|const
name|QMakeLocalFileName
modifier|&
parameter_list|,
specifier|const
name|QMakeLocalFileName
modifier|&
parameter_list|)
function_decl|;
name|virtual
name|QFileInfo
name|findFileInfo
parameter_list|(
specifier|const
name|QMakeLocalFileName
modifier|&
parameter_list|)
function_decl|;
name|public
label|:
name|QMakeSourceFileInfo
argument_list|(
specifier|const
name|QString
operator|&
name|cachefile
operator|=
literal|""
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|QMakeSourceFileInfo
argument_list|()
expr_stmt|;
name|QList
operator|<
name|QMakeLocalFileName
operator|>
name|dependencyPaths
argument_list|()
specifier|const
block|{
return|return
name|depdirs
return|;
block|}
name|void
name|setDependencyPaths
argument_list|(
specifier|const
name|QList
operator|<
name|QMakeLocalFileName
operator|>
operator|&
argument_list|)
decl_stmt|;
enum|enum
name|DependencyMode
block|{
name|Recursive
block|,
name|NonRecursive
block|}
enum|;
specifier|inline
name|void
name|setDependencyMode
parameter_list|(
name|DependencyMode
name|mode
parameter_list|)
block|{
name|dep_mode
operator|=
name|mode
expr_stmt|;
block|}
specifier|inline
name|DependencyMode
name|dependencyMode
argument_list|()
specifier|const
block|{
return|return
name|dep_mode
return|;
block|}
enum|enum
name|SourceFileType
block|{
name|TYPE_UNKNOWN
block|,
name|TYPE_C
block|,
name|TYPE_UI
block|,
name|TYPE_QRC
block|}
enum|;
enum|enum
name|SourceFileSeek
block|{
name|SEEK_DEPS
init|=
literal|0x01
block|,
name|SEEK_MOCS
init|=
literal|0x02
block|}
enum|;
name|void
name|addSourceFiles
parameter_list|(
specifier|const
name|ProStringList
modifier|&
parameter_list|,
name|uchar
name|seek
parameter_list|,
name|SourceFileType
name|type
init|=
name|TYPE_C
parameter_list|)
function_decl|;
name|void
name|addSourceFile
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
name|uchar
name|seek
parameter_list|,
name|SourceFileType
name|type
init|=
name|TYPE_C
parameter_list|)
function_decl|;
name|bool
name|containsSourceFile
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
name|SourceFileType
name|type
init|=
name|TYPE_C
parameter_list|)
function_decl|;
name|int
name|included
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
function_decl|;
name|QStringList
name|dependencies
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
function_decl|;
name|bool
name|mocable
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
function_decl|;
name|virtual
name|QMap
operator|<
name|QString
operator|,
name|QStringList
operator|>
name|getCacheVerification
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|verifyCache
argument_list|(
specifier|const
name|QMap
operator|<
name|QString
argument_list|,
name|QStringList
operator|>
operator|&
argument_list|)
decl_stmt|;
name|void
name|setCacheFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|cachefile
parameter_list|)
function_decl|;
comment|//auto caching
name|void
name|loadCache
parameter_list|(
specifier|const
name|QString
modifier|&
name|cf
parameter_list|)
function_decl|;
name|void
name|saveCache
parameter_list|(
specifier|const
name|QString
modifier|&
name|cf
parameter_list|)
function_decl|;
name|private
label|:
name|DependencyMode
name|dep_mode
decl_stmt|;
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
comment|// MAKEFILEDEPS_H
end_comment
end_unit
