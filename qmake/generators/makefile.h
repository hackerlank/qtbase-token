begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MAKEFILE_H
end_ifndef
begin_define
DECL|macro|MAKEFILE_H
define|#
directive|define
name|MAKEFILE_H
end_define
begin_include
include|#
directive|include
file|"option.h"
end_include
begin_include
include|#
directive|include
file|"project.h"
end_include
begin_include
include|#
directive|include
file|"makefiledeps.h"
end_include
begin_include
include|#
directive|include
file|<qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<qfileinfo.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN32
end_ifdef
begin_define
DECL|macro|QT_POPEN
define|#
directive|define
name|QT_POPEN
value|_popen
end_define
begin_define
DECL|macro|QT_PCLOSE
define|#
directive|define
name|QT_PCLOSE
value|_pclose
end_define
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
name|QT_POPEN
value|popen
end_define
begin_define
define|#
directive|define
name|QT_PCLOSE
value|pclose
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_struct
DECL|struct|ReplaceExtraCompilerCacheKey
struct|struct
name|ReplaceExtraCompilerCacheKey
block|{
DECL|member|hash
name|mutable
name|uint
name|hash
decl_stmt|;
DECL|member|var
DECL|member|in
DECL|member|out
DECL|member|pwd
name|QString
name|var
decl_stmt|,
name|in
decl_stmt|,
name|out
decl_stmt|,
name|pwd
decl_stmt|;
name|ReplaceExtraCompilerCacheKey
argument_list|(
specifier|const
name|QString
operator|&
name|v
argument_list|,
specifier|const
name|QStringList
operator|&
name|i
argument_list|,
specifier|const
name|QStringList
operator|&
name|o
argument_list|)
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ReplaceExtraCompilerCacheKey
operator|&
name|f
operator|)
specifier|const
expr_stmt|;
DECL|function|hashCode
specifier|inline
name|uint
name|hashCode
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|hash
condition|)
name|hash
operator|=
name|qHash
argument_list|(
name|var
argument_list|)
operator||
name|qHash
argument_list|(
name|in
argument_list|)
operator||
name|qHash
argument_list|(
name|out
argument_list|)
comment|/*| qHash(pwd)*/
expr_stmt|;
return|return
name|hash
return|;
block|}
end_struct
begin_function
unit|};
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|ReplaceExtraCompilerCacheKey
modifier|&
name|f
parameter_list|)
block|{
return|return
name|f
operator|.
name|hashCode
argument_list|()
return|;
block|}
end_function
begin_struct_decl
struct_decl|struct
name|ReplaceExtraCompilerCacheKey
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|MakefileGenerator
range|:
name|protected
name|QMakeSourceFileInfo
block|{
name|QString
name|spec
block|;
name|bool
name|init_opath_already
block|,
name|init_already
block|,
name|no_io
block|;
name|QHash
operator|<
name|QString
block|,
name|bool
operator|>
name|init_compiler_already
block|;
name|QString
name|chkdir
block|,
name|chkfile
block|,
name|chkglue
block|;
name|QString
name|build_args
argument_list|(
specifier|const
name|QString
operator|&
name|outdir
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|void
name|checkMultipleDefinition
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QString
operator|&
argument_list|)
block|;
comment|//internal caches
name|mutable
name|QHash
operator|<
name|QString
block|,
name|QMakeLocalFileName
operator|>
name|depHeuristicsCache
block|;
name|mutable
name|QHash
operator|<
name|QString
block|,
name|QStringList
operator|>
name|dependsCache
block|;
name|mutable
name|QHash
operator|<
name|ReplaceExtraCompilerCacheKey
block|,
name|QString
operator|>
name|extraCompilerVariablesCache
block|;
name|protected
operator|:
expr|enum
name|TARG_MODE
block|{
name|TARG_UNIX_MODE
block|,
name|TARG_MACX_MODE
block|,
name|TARG_WIN_MODE
block|}
name|target_mode
block|;
name|QStringList
name|createObjectList
argument_list|(
specifier|const
name|QStringList
operator|&
name|sources
argument_list|)
block|;
comment|//makefile style generator functions
name|void
name|writeObj
argument_list|(
name|QTextStream
operator|&
argument_list|,
specifier|const
name|QString
operator|&
name|src
argument_list|)
block|;
name|void
name|writeInstalls
argument_list|(
argument|QTextStream&t
argument_list|,
argument|const QString&installs
argument_list|,
argument|bool noBuild=false
argument_list|)
block|;
name|void
name|writeHeader
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|void
name|writeSubDirs
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|void
name|writeMakeQmake
argument_list|(
argument|QTextStream&t
argument_list|,
argument|bool noDummyQmakeAll = false
argument_list|)
block|;
name|void
name|writeExtraVariables
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|void
name|writeExtraTargets
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|void
name|writeExtraCompilerTargets
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|void
name|writeExtraCompilerVariables
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|virtual
name|bool
name|writeStubMakefile
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|virtual
name|bool
name|writeMakefile
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|QString
name|pkgConfigPrefix
argument_list|()
specifier|const
block|;
name|QString
name|pkgConfigFileName
argument_list|(
argument|bool fixify=true
argument_list|)
block|;
name|QString
name|pkgConfigFixPath
argument_list|(
argument|QString
argument_list|)
specifier|const
block|;
name|void
name|writePkgConfigFile
argument_list|()
block|;
comment|// for pkg-config
comment|//generating subtarget makefiles
block|struct
name|SubTarget
block|{
name|QString
name|name
block|;
name|QString
name|in_directory
block|,
name|out_directory
block|;
name|QString
name|profile
block|,
name|target
block|,
name|makefile
block|;
name|QStringList
name|depends
block|;     }
block|;     enum
name|SubTargetFlags
block|{
name|SubTargetInstalls
operator|=
literal|0x01
block|,
name|SubTargetOrdered
operator|=
literal|0x02
block|,
name|SubTargetSkipDefaultVariables
operator|=
literal|0x04
block|,
name|SubTargetSkipDefaultTargets
operator|=
literal|0x08
block|,
name|SubTargetsNoFlags
operator|=
literal|0x00
block|}
block|;
name|QList
operator|<
name|MakefileGenerator
operator|::
name|SubTarget
operator|*
operator|>
name|findSubDirsSubTargets
argument_list|()
specifier|const
block|;
name|void
name|writeSubTargetCall
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|,
specifier|const
name|QString
operator|&
name|in_directory
argument_list|,
specifier|const
name|QString
operator|&
name|in
argument_list|,
specifier|const
name|QString
operator|&
name|out_directory
argument_list|,
specifier|const
name|QString
operator|&
name|out
argument_list|,
specifier|const
name|QString
operator|&
name|out_directory_cdin
argument_list|,
specifier|const
name|QString
operator|&
name|makefilein
argument_list|,
specifier|const
name|QString
operator|&
name|out_directory_cdout
argument_list|)
block|;
name|virtual
name|void
name|writeSubMakeCall
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|,
specifier|const
name|QString
operator|&
name|outDirectory_cdin
argument_list|,
specifier|const
name|QString
operator|&
name|makeFileIn
argument_list|,
specifier|const
name|QString
operator|&
name|outDirectory_cdout
argument_list|)
block|;
name|void
name|writeSubTargets
argument_list|(
argument|QTextStream&t
argument_list|,
argument|QList<SubTarget*> subtargets
argument_list|,
argument|int flags
argument_list|)
block|;
comment|//extra compiler interface
name|bool
name|verifyExtraCompiler
argument_list|(
specifier|const
name|QString
operator|&
name|c
argument_list|,
specifier|const
name|QString
operator|&
name|f
argument_list|)
block|;
name|virtual
name|QString
name|replaceExtraCompilerVariables
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QStringList
operator|&
argument_list|,
specifier|const
name|QStringList
operator|&
argument_list|)
block|;
specifier|inline
name|QString
name|replaceExtraCompilerVariables
argument_list|(
argument|const QString&val
argument_list|,
argument|const QString&in
argument_list|,
argument|const QString&out
argument_list|)
block|{
return|return
name|replaceExtraCompilerVariables
argument_list|(
name|val
argument_list|,
name|QStringList
argument_list|(
name|in
argument_list|)
argument_list|,
name|QStringList
argument_list|(
name|out
argument_list|)
argument_list|)
return|;
block|}
comment|//interface to the source file info
name|QMakeLocalFileName
name|fixPathForFile
argument_list|(
specifier|const
name|QMakeLocalFileName
operator|&
argument_list|,
name|bool
argument_list|)
block|;
name|QMakeLocalFileName
name|findFileForDep
argument_list|(
specifier|const
name|QMakeLocalFileName
operator|&
argument_list|,
specifier|const
name|QMakeLocalFileName
operator|&
argument_list|)
block|;
name|QFileInfo
name|findFileInfo
argument_list|(
specifier|const
name|QMakeLocalFileName
operator|&
argument_list|)
block|;
name|QMakeProject
operator|*
name|project
block|;
comment|//escape
name|virtual
name|QString
name|unescapeFilePath
argument_list|(
argument|const QString&path
argument_list|)
specifier|const
block|;
name|virtual
name|QStringList
name|unescapeFilePaths
argument_list|(
argument|const QStringList&path
argument_list|)
specifier|const
block|;
name|virtual
name|QString
name|escapeFilePath
argument_list|(
argument|const QString&path
argument_list|)
specifier|const
block|{
return|return
name|path
return|;
block|}
name|virtual
name|QString
name|escapeDependencyPath
argument_list|(
argument|const QString&path
argument_list|)
specifier|const
block|{
return|return
name|escapeFilePath
argument_list|(
name|path
argument_list|)
return|;
block|}
name|QStringList
name|escapeFilePaths
argument_list|(
argument|const QStringList&paths
argument_list|)
specifier|const
block|;
name|QStringList
name|escapeDependencyPaths
argument_list|(
argument|const QStringList&paths
argument_list|)
specifier|const
block|;
comment|//initialization
name|void
name|verifyCompilers
argument_list|()
block|;
name|virtual
name|void
name|init
argument_list|()
block|;
name|void
name|initOutPaths
argument_list|()
block|;     struct
name|Compiler
block|{
name|QString
name|variable_in
block|;         enum
name|CompilerFlag
block|{
name|CompilerNoFlags
operator|=
literal|0x00
block|,
name|CompilerBuiltin
operator|=
literal|0x01
block|,
name|CompilerNoCheckDeps
operator|=
literal|0x02
block|,
name|CompilerRemoveNoExist
operator|=
literal|0x04
block|,
name|CompilerAddInputsAsMakefileDeps
operator|=
literal|0x08
block|}
block|;
name|uint
name|flags
block|,
name|type
block|;     }
block|;
name|void
name|initCompiler
argument_list|(
specifier|const
name|Compiler
operator|&
name|comp
argument_list|)
block|;     enum
name|VPATHFlag
block|{
name|VPATH_NoFlag
operator|=
literal|0x00
block|,
name|VPATH_WarnMissingFiles
operator|=
literal|0x01
block|,
name|VPATH_RemoveMissingFiles
operator|=
literal|0x02
block|,
name|VPATH_NoFixify
operator|=
literal|0x04
block|}
block|;
name|QStringList
name|findFilesInVPATH
argument_list|(
argument|QStringList l
argument_list|,
argument|uchar flags
argument_list|,
argument|const QString&var=
literal|""
argument_list|)
block|;
specifier|inline
name|int
name|findExecutable
argument_list|(
argument|const QStringList&cmdline
argument_list|)
block|{
name|int
name|ret
block|;
name|canExecute
argument_list|(
name|cmdline
argument_list|,
operator|&
name|ret
argument_list|)
block|;
return|return
name|ret
return|;
block|}
name|bool
name|canExecute
argument_list|(
argument|const QStringList&cmdline
argument_list|,
argument|int *argv0
argument_list|)
specifier|const
block|;
specifier|inline
name|bool
name|canExecute
argument_list|(
argument|const QString&cmdline
argument_list|)
specifier|const
block|{
return|return
name|canExecute
argument_list|(
name|cmdline
operator|.
name|split
argument_list|(
literal|' '
argument_list|)
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|bool
name|mkdir
argument_list|(
argument|const QString&dir
argument_list|)
specifier|const
block|;
name|QString
name|mkdir_p_asstring
argument_list|(
argument|const QString&dir
argument_list|,
argument|bool escape=true
argument_list|)
specifier|const
block|;
name|QString
name|specdir
argument_list|()
block|;
comment|//subclasses can use these to query information about how the generator was "run"
name|QString
name|buildArgs
argument_list|(
specifier|const
name|QString
operator|&
name|outdir
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|QString
name|fixifySpecdir
argument_list|(
specifier|const
name|QString
operator|&
name|spec
argument_list|,
specifier|const
name|QString
operator|&
name|outdir
argument_list|)
block|;
name|virtual
name|QStringList
operator|&
name|findDependencies
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|virtual
name|bool
name|doDepends
argument_list|()
specifier|const
block|{
return|return
name|Option
operator|::
name|mkfile
operator|::
name|do_deps
return|;
block|}
name|void
name|filterIncludedFiles
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|virtual
name|void
name|processSources
argument_list|()
block|{
name|filterIncludedFiles
argument_list|(
literal|"SOURCES"
argument_list|)
block|;
name|filterIncludedFiles
argument_list|(
literal|"GENERATED_SOURCES"
argument_list|)
block|;     }
comment|//for installs
name|virtual
name|QString
name|defaultInstall
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
comment|//for prl
name|QString
name|prlFileName
argument_list|(
argument|bool fixify=true
argument_list|)
block|;
name|void
name|writePrlFile
argument_list|()
block|;
name|bool
name|processPrlFile
argument_list|(
name|QString
operator|&
argument_list|)
block|;
name|virtual
name|void
name|processPrlVariable
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QStringList
operator|&
argument_list|)
block|;
name|virtual
name|void
name|processPrlFiles
argument_list|()
block|;
name|virtual
name|void
name|writePrlFile
argument_list|(
name|QTextStream
operator|&
argument_list|)
block|;
comment|//make sure libraries are found
name|virtual
name|bool
name|findLibraries
argument_list|()
block|;
comment|//for retrieving values and lists of values
name|virtual
name|QString
name|var
argument_list|(
specifier|const
name|QString
operator|&
name|var
argument_list|)
block|;
name|QString
name|varGlue
argument_list|(
specifier|const
name|QString
operator|&
name|var
argument_list|,
specifier|const
name|QString
operator|&
name|before
argument_list|,
specifier|const
name|QString
operator|&
name|glue
argument_list|,
specifier|const
name|QString
operator|&
name|after
argument_list|)
block|;
name|QString
name|varList
argument_list|(
specifier|const
name|QString
operator|&
name|var
argument_list|)
block|;
name|QString
name|val
argument_list|(
specifier|const
name|QStringList
operator|&
name|varList
argument_list|)
block|;
name|QString
name|valGlue
argument_list|(
specifier|const
name|QStringList
operator|&
name|varList
argument_list|,
specifier|const
name|QString
operator|&
name|before
argument_list|,
specifier|const
name|QString
operator|&
name|glue
argument_list|,
specifier|const
name|QString
operator|&
name|after
argument_list|)
block|;
name|QString
name|valList
argument_list|(
specifier|const
name|QStringList
operator|&
name|varList
argument_list|)
block|;
name|QString
name|filePrefixRoot
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QString
operator|&
argument_list|)
block|;
comment|//file fixification to unify all file names into a single pattern
block|enum
name|FileFixifyType
block|{
name|FileFixifyAbsolute
block|,
name|FileFixifyRelative
block|,
name|FileFixifyDefault
block|}
block|;
name|QString
name|fileFixify
argument_list|(
argument|const QString& file
argument_list|,
argument|const QString&out_dir=QString()
argument_list|,
argument|const QString&in_dir=QString()
argument_list|,
argument|FileFixifyType fix=FileFixifyDefault
argument_list|,
argument|bool canon=true
argument_list|)
specifier|const
block|;
specifier|inline
name|QString
name|fileFixify
argument_list|(
argument|const QString& file
argument_list|,
argument|FileFixifyType fix
argument_list|,
argument|bool canon=true
argument_list|)
specifier|const
block|{
return|return
name|fileFixify
argument_list|(
name|file
argument_list|,
name|QString
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|,
name|fix
argument_list|,
name|canon
argument_list|)
return|;
block|}
name|QStringList
name|fileFixify
argument_list|(
argument|const QStringList& files
argument_list|,
argument|const QString&out_dir=QString()
argument_list|,
argument|const QString&in_dir=QString()
argument_list|,
argument|FileFixifyType fix=FileFixifyDefault
argument_list|,
argument|bool canon=true
argument_list|)
specifier|const
block|;
specifier|inline
name|QStringList
name|fileFixify
argument_list|(
argument|const QStringList& files
argument_list|,
argument|FileFixifyType fix
argument_list|,
argument|bool canon=true
argument_list|)
specifier|const
block|{
return|return
name|fileFixify
argument_list|(
name|files
argument_list|,
name|QString
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|,
name|fix
argument_list|,
name|canon
argument_list|)
return|;
block|}
name|public
operator|:
name|MakefileGenerator
argument_list|()
block|;
name|virtual
operator|~
name|MakefileGenerator
argument_list|()
block|;
name|QMakeProject
operator|*
name|projectFile
argument_list|()
specifier|const
block|;
name|void
name|setProjectFile
argument_list|(
name|QMakeProject
operator|*
name|p
argument_list|)
block|;
name|void
name|setNoIO
argument_list|(
argument|bool o
argument_list|)
block|;
name|bool
name|noIO
argument_list|()
specifier|const
block|;
specifier|inline
name|bool
name|exists
argument_list|(
argument|QString file
argument_list|)
specifier|const
block|{
return|return
name|fileInfo
argument_list|(
name|file
argument_list|)
operator|.
name|exists
argument_list|()
return|;
block|}
name|QFileInfo
name|fileInfo
argument_list|(
argument|QString file
argument_list|)
specifier|const
block|;
specifier|static
name|MakefileGenerator
operator|*
name|create
argument_list|(
name|QMakeProject
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|write
argument_list|()
block|;
name|virtual
name|bool
name|writeProjectMakefile
argument_list|()
block|;
name|virtual
name|bool
name|supportsMetaBuild
argument_list|()
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|supportsMergedBuilds
argument_list|()
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|mergeBuildProject
argument_list|(
argument|MakefileGenerator *
comment|/*other*/
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|openOutput
argument_list|(
argument|QFile&
argument_list|,
argument|const QString&build
argument_list|)
specifier|const
block|;
name|bool
name|isWindowsShell
argument_list|()
specifier|const
block|{
return|return
name|Option
operator|::
name|dir_sep
operator|==
name|QLatin1String
argument_list|(
literal|"\\"
argument_list|)
return|;
block|}
expr|}
block|;
DECL|function|setNoIO
specifier|inline
name|void
name|MakefileGenerator
operator|::
name|setNoIO
argument_list|(
argument|bool o
argument_list|)
block|{
name|no_io
operator|=
name|o
block|; }
DECL|function|noIO
specifier|inline
name|bool
name|MakefileGenerator
operator|::
name|noIO
argument_list|()
specifier|const
block|{
return|return
name|no_io
return|;
block|}
DECL|function|defaultInstall
specifier|inline
name|QString
name|MakefileGenerator
operator|::
name|defaultInstall
argument_list|(
argument|const QString&
argument_list|)
block|{
return|return
name|QString
argument_list|(
literal|""
argument_list|)
return|;
block|}
DECL|function|findLibraries
specifier|inline
name|bool
name|MakefileGenerator
operator|::
name|findLibraries
argument_list|()
block|{
return|return
name|true
return|;
block|}
DECL|function|~MakefileGenerator
specifier|inline
name|MakefileGenerator
operator|::
operator|~
name|MakefileGenerator
argument_list|()
block|{ }
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// MAKEFILE_H
end_comment
end_unit
