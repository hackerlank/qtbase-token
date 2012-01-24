begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"msvc_nmake.h"
end_include
begin_include
include|#
directive|include
file|"option.h"
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<time.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|NmakeMakefileGenerator
name|NmakeMakefileGenerator
operator|::
name|NmakeMakefileGenerator
parameter_list|()
member_init_list|:
name|Win32MakefileGenerator
argument_list|()
member_init_list|,
name|init_flag
argument_list|(
literal|false
argument_list|)
block|{  }
end_constructor
begin_function
name|bool
DECL|function|writeMakefile
name|NmakeMakefileGenerator
operator|::
name|writeMakefile
parameter_list|(
name|QTextStream
modifier|&
name|t
parameter_list|)
block|{
name|writeHeader
argument_list|(
name|t
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_FAILED_REQUIREMENTS"
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QStringList
modifier|&
name|qut
init|=
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_EXTRA_TARGETS"
argument_list|)
decl_stmt|;
for|for
control|(
name|QStringList
operator|::
name|ConstIterator
name|it
init|=
name|qut
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|qut
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
name|t
operator|<<
operator|*
name|it
operator|<<
literal|" "
expr_stmt|;
name|t
operator|<<
literal|"all first clean:"
operator|<<
literal|"\n\t"
operator|<<
literal|"@echo \"Some of the required modules ("
operator|<<
name|var
argument_list|(
literal|"QMAKE_FAILED_REQUIREMENTS"
argument_list|)
operator|<<
literal|") are not available.\""
operator|<<
literal|"\n\t"
operator|<<
literal|"@echo \"Skipped.\""
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
name|writeMakeQmake
argument_list|(
name|t
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
if|if
condition|(
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"app"
operator|||
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"lib"
operator|||
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"aux"
condition|)
block|{
if|#
directive|if
literal|0
block|if(Option::mkfile::do_stub_makefile)             return MakefileGenerator::writeStubMakefile(t);
endif|#
directive|endif
name|writeNmakeParts
argument_list|(
name|t
argument_list|)
expr_stmt|;
return|return
name|MakefileGenerator
operator|::
name|writeMakefile
argument_list|(
name|t
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"subdirs"
condition|)
block|{
name|writeSubDirs
argument_list|(
name|t
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|writeSubMakeCall
name|void
name|NmakeMakefileGenerator
operator|::
name|writeSubMakeCall
parameter_list|(
name|QTextStream
modifier|&
name|t
parameter_list|,
specifier|const
name|QString
modifier|&
name|callPrefix
parameter_list|,
specifier|const
name|QString
modifier|&
name|makeArguments
parameter_list|,
specifier|const
name|QString
modifier|&
name|callPostfix
parameter_list|)
block|{
comment|// Pass MAKEFLAGS as environment variable to sub-make calls.
comment|// Unlike other make tools nmake doesn't do this automatically.
name|t
operator|<<
literal|"\n\t@set MAKEFLAGS=$(MAKEFLAGS)"
expr_stmt|;
name|Win32MakefileGenerator
operator|::
name|writeSubMakeCall
argument_list|(
name|t
argument_list|,
name|callPrefix
argument_list|,
name|makeArguments
argument_list|,
name|callPostfix
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getPdbTarget
name|QString
name|NmakeMakefileGenerator
operator|::
name|getPdbTarget
parameter_list|()
block|{
return|return
name|QString
argument_list|(
name|project
operator|->
name|first
argument_list|(
literal|"TARGET"
argument_list|)
operator|+
name|project
operator|->
name|first
argument_list|(
literal|"TARGET_VERSION_EXT"
argument_list|)
operator|+
literal|".pdb"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|defaultInstall
name|QString
name|NmakeMakefileGenerator
operator|::
name|defaultInstall
parameter_list|(
specifier|const
name|QString
modifier|&
name|t
parameter_list|)
block|{
if|if
condition|(
operator|(
name|t
operator|!=
literal|"target"
operator|&&
name|t
operator|!=
literal|"dlltarget"
operator|)
operator|||
operator|(
name|t
operator|==
literal|"dlltarget"
operator|&&
operator|(
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|!=
literal|"lib"
operator|||
operator|!
name|project
operator|->
name|isActiveConfig
argument_list|(
literal|"shared"
argument_list|)
operator|)
operator|)
operator|||
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"subdirs"
condition|)
return|return
name|QString
argument_list|()
return|;
name|QString
name|ret
init|=
name|Win32MakefileGenerator
operator|::
name|defaultInstall
argument_list|(
name|t
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|root
init|=
literal|"$(INSTALL_ROOT)"
decl_stmt|;
name|QStringList
modifier|&
name|uninst
init|=
name|project
operator|->
name|values
argument_list|(
name|t
operator|+
literal|".uninstall"
argument_list|)
decl_stmt|;
name|QString
name|targetdir
init|=
name|Option
operator|::
name|fixPathToTargetOS
argument_list|(
name|project
operator|->
name|first
argument_list|(
name|t
operator|+
literal|".path"
argument_list|)
argument_list|,
literal|false
argument_list|)
decl_stmt|;
name|targetdir
operator|=
name|fileFixify
argument_list|(
name|targetdir
argument_list|,
name|FileFixifyAbsolute
argument_list|)
expr_stmt|;
if|if
condition|(
name|targetdir
operator|.
name|right
argument_list|(
literal|1
argument_list|)
operator|!=
name|Option
operator|::
name|dir_sep
condition|)
name|targetdir
operator|+=
name|Option
operator|::
name|dir_sep
expr_stmt|;
if|if
condition|(
name|t
operator|==
literal|"target"
operator|&&
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"lib"
condition|)
block|{
if|if
condition|(
name|project
operator|->
name|isActiveConfig
argument_list|(
literal|"shared"
argument_list|)
operator|&&
name|project
operator|->
name|isActiveConfig
argument_list|(
literal|"debug"
argument_list|)
condition|)
block|{
name|QString
name|pdb_target
init|=
name|getPdbTarget
argument_list|()
decl_stmt|;
name|pdb_target
operator|.
name|remove
argument_list|(
literal|'"'
argument_list|)
expr_stmt|;
name|QString
name|src_targ
init|=
operator|(
name|project
operator|->
name|isEmpty
argument_list|(
literal|"DESTDIR"
argument_list|)
condition|?
name|QString
argument_list|(
literal|"$(DESTDIR)"
argument_list|)
else|:
name|project
operator|->
name|first
argument_list|(
literal|"DESTDIR"
argument_list|)
operator|)
operator|+
name|pdb_target
decl_stmt|;
name|QString
name|dst_targ
init|=
name|filePrefixRoot
argument_list|(
name|root
argument_list|,
name|fileFixify
argument_list|(
name|targetdir
operator|+
name|pdb_target
argument_list|,
name|FileFixifyAbsolute
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ret
operator|.
name|isEmpty
argument_list|()
condition|)
name|ret
operator|+=
literal|"\n\t"
expr_stmt|;
name|ret
operator|+=
name|QString
argument_list|(
literal|"-$(INSTALL_FILE)"
argument_list|)
operator|+
literal|" \""
operator|+
name|src_targ
operator|+
literal|"\" \""
operator|+
name|dst_targ
operator|+
literal|"\""
expr_stmt|;
if|if
condition|(
operator|!
name|uninst
operator|.
name|isEmpty
argument_list|()
condition|)
name|uninst
operator|.
name|append
argument_list|(
literal|"\n\t"
argument_list|)
expr_stmt|;
name|uninst
operator|.
name|append
argument_list|(
literal|"-$(DEL_FILE) \""
operator|+
name|dst_targ
operator|+
literal|"\""
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|findDependencies
name|QStringList
modifier|&
name|NmakeMakefileGenerator
operator|::
name|findDependencies
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
block|{
name|QStringList
modifier|&
name|aList
init|=
name|MakefileGenerator
operator|::
name|findDependencies
argument_list|(
name|file
argument_list|)
decl_stmt|;
comment|// Note: The QMAKE_IMAGE_COLLECTION file have all images
comment|// as dependency, so don't add precompiled header then
if|if
condition|(
name|file
operator|==
name|project
operator|->
name|first
argument_list|(
literal|"QMAKE_IMAGE_COLLECTION"
argument_list|)
condition|)
return|return
name|aList
return|;
for|for
control|(
name|QStringList
operator|::
name|Iterator
name|it
init|=
name|Option
operator|::
name|cpp_ext
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|Option
operator|::
name|cpp_ext
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
name|file
operator|.
name|endsWith
argument_list|(
operator|*
name|it
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|precompObj
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|aList
operator|.
name|contains
argument_list|(
name|precompObj
argument_list|)
condition|)
name|aList
operator|+=
name|precompObj
expr_stmt|;
break|break;
block|}
block|}
return|return
name|aList
return|;
block|}
end_function
begin_function
DECL|function|writeNmakeParts
name|void
name|NmakeMakefileGenerator
operator|::
name|writeNmakeParts
parameter_list|(
name|QTextStream
modifier|&
name|t
parameter_list|)
block|{
name|writeStandardParts
argument_list|(
name|t
argument_list|)
expr_stmt|;
comment|// precompiled header
if|if
condition|(
name|usePCH
condition|)
block|{
name|QString
name|precompRule
init|=
name|QString
argument_list|(
literal|"-c -Yc -Fp%1 -Fo%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|precompPch
argument_list|)
operator|.
name|arg
argument_list|(
name|precompObj
argument_list|)
decl_stmt|;
name|t
operator|<<
name|precompObj
operator|<<
literal|": "
operator|<<
name|precompH
operator|<<
literal|" "
operator|<<
name|findDependencies
argument_list|(
name|precompH
argument_list|)
operator|.
name|join
argument_list|(
literal|" \\\n\t\t"
argument_list|)
operator|<<
literal|"\n\t"
operator|<<
literal|"$(CXX) "
operator|+
name|precompRule
operator|+
literal|" $(CXXFLAGS) $(INCPATH) -TP "
operator|<<
name|precompH
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|var
name|QString
name|NmakeMakefileGenerator
operator|::
name|var
parameter_list|(
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
block|{
if|if
condition|(
name|usePCH
condition|)
block|{
if|if
condition|(
operator|(
name|value
operator|==
literal|"QMAKE_RUN_CXX_IMP_BATCH"
operator|||
name|value
operator|==
literal|"QMAKE_RUN_CXX_IMP"
operator|||
name|value
operator|==
literal|"QMAKE_RUN_CXX"
operator|)
condition|)
block|{
name|QFileInfo
name|precompHInfo
argument_list|(
name|fileInfo
argument_list|(
name|precompH
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|precompRule
init|=
name|QString
argument_list|(
literal|"-c -FI%1 -Yu%2 -Fp%3"
argument_list|)
operator|.
name|arg
argument_list|(
name|precompHInfo
operator|.
name|fileName
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|precompHInfo
operator|.
name|fileName
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|precompPch
argument_list|)
decl_stmt|;
name|QString
name|p
init|=
name|MakefileGenerator
operator|::
name|var
argument_list|(
name|value
argument_list|)
decl_stmt|;
name|p
operator|.
name|replace
argument_list|(
literal|"-c"
argument_list|,
name|precompRule
argument_list|)
expr_stmt|;
comment|// Cannot use -Gm with -FI& -Yu, as this gives an
comment|// internal compiler error, on the newer compilers
comment|// ### work-around for a VS 2003 bug. Move to some prf file or remove completely.
name|p
operator|.
name|remove
argument_list|(
literal|"-Gm"
argument_list|)
expr_stmt|;
return|return
name|p
return|;
block|}
elseif|else
if|if
condition|(
name|value
operator|==
literal|"QMAKE_CXXFLAGS"
condition|)
block|{
comment|// Remove internal compiler error option
comment|// ### work-around for a VS 2003 bug. Move to some prf file or remove completely.
return|return
name|MakefileGenerator
operator|::
name|var
argument_list|(
name|value
argument_list|)
operator|.
name|remove
argument_list|(
literal|"-Gm"
argument_list|)
return|;
block|}
block|}
comment|// Normal val
return|return
name|MakefileGenerator
operator|::
name|var
argument_list|(
name|value
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|NmakeMakefileGenerator
operator|::
name|init
parameter_list|()
block|{
if|if
condition|(
name|init_flag
condition|)
return|return;
name|init_flag
operator|=
literal|true
expr_stmt|;
comment|/* this should probably not be here, but I'm using it to wrap the .t files */
if|if
condition|(
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"app"
condition|)
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_APP_FLAG"
argument_list|)
operator|.
name|append
argument_list|(
literal|"1"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"lib"
condition|)
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_LIB_FLAG"
argument_list|)
operator|.
name|append
argument_list|(
literal|"1"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"subdirs"
condition|)
block|{
name|MakefileGenerator
operator|::
name|init
argument_list|()
expr_stmt|;
if|if
condition|(
name|project
operator|->
name|values
argument_list|(
literal|"MAKEFILE"
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
name|project
operator|->
name|values
argument_list|(
literal|"MAKEFILE"
argument_list|)
operator|.
name|append
argument_list|(
literal|"Makefile"
argument_list|)
expr_stmt|;
if|if
condition|(
name|project
operator|->
name|isEmpty
argument_list|(
literal|"QMAKE_COPY_FILE"
argument_list|)
condition|)
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_COPY_FILE"
argument_list|)
operator|.
name|append
argument_list|(
literal|"$(COPY)"
argument_list|)
expr_stmt|;
if|if
condition|(
name|project
operator|->
name|isEmpty
argument_list|(
literal|"QMAKE_COPY_DIR"
argument_list|)
condition|)
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_COPY_DIR"
argument_list|)
operator|.
name|append
argument_list|(
literal|"xcopy /s /q /y /i"
argument_list|)
expr_stmt|;
if|if
condition|(
name|project
operator|->
name|isEmpty
argument_list|(
literal|"QMAKE_INSTALL_FILE"
argument_list|)
condition|)
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_INSTALL_FILE"
argument_list|)
operator|.
name|append
argument_list|(
literal|"$(COPY_FILE)"
argument_list|)
expr_stmt|;
if|if
condition|(
name|project
operator|->
name|isEmpty
argument_list|(
literal|"QMAKE_INSTALL_PROGRAM"
argument_list|)
condition|)
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_INSTALL_PROGRAM"
argument_list|)
operator|.
name|append
argument_list|(
literal|"$(COPY_FILE)"
argument_list|)
expr_stmt|;
if|if
condition|(
name|project
operator|->
name|isEmpty
argument_list|(
literal|"QMAKE_INSTALL_DIR"
argument_list|)
condition|)
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_INSTALL_DIR"
argument_list|)
operator|.
name|append
argument_list|(
literal|"$(COPY_DIR)"
argument_list|)
expr_stmt|;
return|return;
block|}
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_LIBS"
argument_list|)
operator|+=
name|escapeFilePaths
argument_list|(
name|project
operator|->
name|values
argument_list|(
literal|"LIBS"
argument_list|)
argument_list|)
expr_stmt|;
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_LIBS_PRIVATE"
argument_list|)
operator|+=
name|escapeFilePaths
argument_list|(
name|project
operator|->
name|values
argument_list|(
literal|"LIBS_PRIVATE"
argument_list|)
argument_list|)
expr_stmt|;
name|processVars
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|project
operator|->
name|values
argument_list|(
literal|"RES_FILE"
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_LIBS"
argument_list|)
operator|+=
name|escapeFilePaths
argument_list|(
name|project
operator|->
name|values
argument_list|(
literal|"RES_FILE"
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|project
operator|->
name|values
argument_list|(
literal|"DEF_FILE"
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QString
name|defFileName
init|=
name|fileFixify
argument_list|(
name|project
operator|->
name|values
argument_list|(
literal|"DEF_FILE"
argument_list|)
argument_list|)
operator|.
name|first
argument_list|()
decl_stmt|;
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_LFLAGS"
argument_list|)
operator|.
name|append
argument_list|(
name|QString
argument_list|(
literal|"/DEF:"
argument_list|)
operator|+
name|escapeFilePath
argument_list|(
name|defFileName
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|project
operator|->
name|values
argument_list|(
literal|"VERSION"
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QString
name|version
init|=
name|project
operator|->
name|values
argument_list|(
literal|"VERSION"
argument_list|)
index|[
literal|0
index|]
decl_stmt|;
name|int
name|firstDot
init|=
name|version
operator|.
name|indexOf
argument_list|(
literal|"."
argument_list|)
decl_stmt|;
name|QString
name|major
init|=
name|version
operator|.
name|left
argument_list|(
name|firstDot
argument_list|)
decl_stmt|;
name|QString
name|minor
init|=
name|version
operator|.
name|right
argument_list|(
name|version
operator|.
name|length
argument_list|()
operator|-
name|firstDot
operator|-
literal|1
argument_list|)
decl_stmt|;
name|minor
operator|.
name|replace
argument_list|(
literal|"."
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_LFLAGS"
argument_list|)
operator|.
name|append
argument_list|(
literal|"/VERSION:"
operator|+
name|major
operator|+
literal|"."
operator|+
name|minor
argument_list|)
expr_stmt|;
block|}
comment|// Base class init!
name|MakefileGenerator
operator|::
name|init
argument_list|()
expr_stmt|;
comment|// Setup PCH variables
name|precompH
operator|=
name|project
operator|->
name|first
argument_list|(
literal|"PRECOMPILED_HEADER"
argument_list|)
expr_stmt|;
name|usePCH
operator|=
operator|!
name|precompH
operator|.
name|isEmpty
argument_list|()
operator|&&
name|project
operator|->
name|isActiveConfig
argument_list|(
literal|"precompile_header"
argument_list|)
expr_stmt|;
if|if
condition|(
name|usePCH
condition|)
block|{
comment|// Created files
name|precompObj
operator|=
name|var
argument_list|(
literal|"PRECOMPILED_DIR"
argument_list|)
operator|+
name|project
operator|->
name|first
argument_list|(
literal|"TARGET"
argument_list|)
operator|+
literal|"_pch"
operator|+
name|Option
operator|::
name|obj_ext
expr_stmt|;
name|precompPch
operator|=
name|var
argument_list|(
literal|"PRECOMPILED_DIR"
argument_list|)
operator|+
name|project
operator|->
name|first
argument_list|(
literal|"TARGET"
argument_list|)
operator|+
literal|"_pch.pch"
expr_stmt|;
comment|// Add linking of precompObj (required for whole precompiled classes)
name|project
operator|->
name|values
argument_list|(
literal|"OBJECTS"
argument_list|)
operator|+=
name|precompObj
expr_stmt|;
comment|// Add pch file to cleanup
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_CLEAN"
argument_list|)
operator|+=
name|precompPch
expr_stmt|;
comment|// Return to variable pool
name|project
operator|->
name|values
argument_list|(
literal|"PRECOMPILED_OBJECT"
argument_list|)
operator|=
name|QStringList
argument_list|(
name|precompObj
argument_list|)
expr_stmt|;
name|project
operator|->
name|values
argument_list|(
literal|"PRECOMPILED_PCH"
argument_list|)
operator|=
name|QStringList
argument_list|(
name|precompPch
argument_list|)
expr_stmt|;
block|}
name|QString
name|version
init|=
name|project
operator|->
name|first
argument_list|(
literal|"TARGET_VERSION_EXT"
argument_list|)
decl_stmt|;
if|if
condition|(
name|project
operator|->
name|isActiveConfig
argument_list|(
literal|"shared"
argument_list|)
condition|)
block|{
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_CLEAN"
argument_list|)
operator|.
name|append
argument_list|(
name|project
operator|->
name|first
argument_list|(
literal|"DESTDIR"
argument_list|)
operator|+
name|project
operator|->
name|first
argument_list|(
literal|"TARGET"
argument_list|)
operator|+
name|version
operator|+
literal|".exp"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|project
operator|->
name|isActiveConfig
argument_list|(
literal|"debug"
argument_list|)
condition|)
block|{
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_DISTCLEAN"
argument_list|)
operator|.
name|append
argument_list|(
name|project
operator|->
name|first
argument_list|(
literal|"DESTDIR"
argument_list|)
operator|+
name|project
operator|->
name|first
argument_list|(
literal|"TARGET"
argument_list|)
operator|+
name|version
operator|+
literal|".pdb"
argument_list|)
expr_stmt|;
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_CLEAN"
argument_list|)
operator|.
name|append
argument_list|(
name|project
operator|->
name|first
argument_list|(
literal|"DESTDIR"
argument_list|)
operator|+
name|project
operator|->
name|first
argument_list|(
literal|"TARGET"
argument_list|)
operator|+
name|version
operator|+
literal|".ilk"
argument_list|)
expr_stmt|;
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_CLEAN"
argument_list|)
operator|.
name|append
argument_list|(
literal|"vc*.pdb"
argument_list|)
expr_stmt|;
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_CLEAN"
argument_list|)
operator|.
name|append
argument_list|(
literal|"vc*.idb"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|writeLibDirPart
name|void
name|NmakeMakefileGenerator
operator|::
name|writeLibDirPart
parameter_list|(
name|QTextStream
modifier|&
name|t
parameter_list|)
block|{
name|QStringList
name|libDirs
init|=
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_LIBDIR"
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|libDirs
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|libDirs
index|[
name|i
index|]
operator|.
name|remove
argument_list|(
literal|"\""
argument_list|)
expr_stmt|;
name|t
operator|<<
name|valGlue
argument_list|(
name|libDirs
argument_list|,
literal|"/LIBPATH:\""
argument_list|,
literal|"\" /LIBPATH:\""
argument_list|,
literal|"\""
argument_list|)
operator|<<
literal|" "
expr_stmt|;
block|}
end_function
begin_function
DECL|function|writeImplicitRulesPart
name|void
name|NmakeMakefileGenerator
operator|::
name|writeImplicitRulesPart
parameter_list|(
name|QTextStream
modifier|&
name|t
parameter_list|)
block|{
name|t
operator|<<
literal|".SUFFIXES:"
expr_stmt|;
for|for
control|(
name|QStringList
operator|::
name|Iterator
name|cit
init|=
name|Option
operator|::
name|c_ext
operator|.
name|begin
argument_list|()
init|;
name|cit
operator|!=
name|Option
operator|::
name|c_ext
operator|.
name|end
argument_list|()
condition|;
operator|++
name|cit
control|)
name|t
operator|<<
literal|" "
operator|<<
operator|(
operator|*
name|cit
operator|)
expr_stmt|;
for|for
control|(
name|QStringList
operator|::
name|Iterator
name|cppit
init|=
name|Option
operator|::
name|cpp_ext
operator|.
name|begin
argument_list|()
init|;
name|cppit
operator|!=
name|Option
operator|::
name|cpp_ext
operator|.
name|end
argument_list|()
condition|;
operator|++
name|cppit
control|)
name|t
operator|<<
literal|" "
operator|<<
operator|(
operator|*
name|cppit
operator|)
expr_stmt|;
name|t
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
if|if
condition|(
operator|!
name|project
operator|->
name|isActiveConfig
argument_list|(
literal|"no_batch"
argument_list|)
condition|)
block|{
comment|// Batchmode doesn't use the non implicit rules QMAKE_RUN_CXX& QMAKE_RUN_CC
name|project
operator|->
name|variables
argument_list|()
operator|.
name|remove
argument_list|(
literal|"QMAKE_RUN_CXX"
argument_list|)
expr_stmt|;
name|project
operator|->
name|variables
argument_list|()
operator|.
name|remove
argument_list|(
literal|"QMAKE_RUN_CC"
argument_list|)
expr_stmt|;
name|QHash
argument_list|<
name|QString
argument_list|,
name|void
modifier|*
argument_list|>
name|source_directories
decl_stmt|;
name|source_directories
operator|.
name|insert
argument_list|(
literal|"."
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|1
argument_list|)
expr_stmt|;
name|QString
name|directories
index|[]
init|=
block|{
name|QString
argument_list|(
literal|"UI_SOURCES_DIR"
argument_list|)
block|,
name|QString
argument_list|(
literal|"UI_DIR"
argument_list|)
block|,
name|QString
argument_list|()
block|}
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
operator|!
name|directories
index|[
name|y
index|]
operator|.
name|isNull
argument_list|()
condition|;
name|y
operator|++
control|)
block|{
name|QString
name|dirTemp
init|=
name|project
operator|->
name|first
argument_list|(
name|directories
index|[
name|y
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|dirTemp
operator|.
name|endsWith
argument_list|(
literal|"\\"
argument_list|)
condition|)
name|dirTemp
operator|.
name|truncate
argument_list|(
name|dirTemp
operator|.
name|length
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dirTemp
operator|.
name|isEmpty
argument_list|()
condition|)
name|source_directories
operator|.
name|insert
argument_list|(
name|dirTemp
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|1
argument_list|)
expr_stmt|;
block|}
name|QString
name|srcs
index|[]
init|=
block|{
name|QString
argument_list|(
literal|"SOURCES"
argument_list|)
block|,
name|QString
argument_list|(
literal|"GENERATED_SOURCES"
argument_list|)
block|,
name|QString
argument_list|()
block|}
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
operator|!
name|srcs
index|[
name|x
index|]
operator|.
name|isNull
argument_list|()
condition|;
name|x
operator|++
control|)
block|{
name|QStringList
modifier|&
name|l
init|=
name|project
operator|->
name|values
argument_list|(
name|srcs
index|[
name|x
index|]
argument_list|)
decl_stmt|;
for|for
control|(
name|QStringList
operator|::
name|Iterator
name|sit
init|=
name|l
operator|.
name|begin
argument_list|()
init|;
name|sit
operator|!=
name|l
operator|.
name|end
argument_list|()
condition|;
operator|++
name|sit
control|)
block|{
name|QString
name|sep
init|=
literal|"\\"
decl_stmt|;
if|if
condition|(
operator|(
operator|*
name|sit
operator|)
operator|.
name|indexOf
argument_list|(
name|sep
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|sep
operator|=
literal|"/"
expr_stmt|;
name|QString
name|dir
init|=
operator|(
operator|*
name|sit
operator|)
operator|.
name|section
argument_list|(
name|sep
argument_list|,
literal|0
argument_list|,
operator|-
literal|2
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|dir
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|source_directories
index|[
name|dir
index|]
condition|)
name|source_directories
operator|.
name|insert
argument_list|(
name|dir
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
for|for
control|(
name|QHash
argument_list|<
name|QString
argument_list|,
name|void
operator|*
argument_list|>
operator|::
name|Iterator
name|it
argument_list|(
name|source_directories
operator|.
name|begin
argument_list|()
argument_list|)
init|;
name|it
operator|!=
name|source_directories
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
name|it
operator|.
name|key
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
continue|continue;
name|QString
name|objDir
init|=
name|var
argument_list|(
literal|"OBJECTS_DIR"
argument_list|)
decl_stmt|;
if|if
condition|(
name|objDir
operator|==
literal|".\\"
condition|)
name|objDir
operator|=
literal|""
expr_stmt|;
for|for
control|(
name|QStringList
operator|::
name|Iterator
name|cppit
init|=
name|Option
operator|::
name|cpp_ext
operator|.
name|begin
argument_list|()
init|;
name|cppit
operator|!=
name|Option
operator|::
name|cpp_ext
operator|.
name|end
argument_list|()
condition|;
operator|++
name|cppit
control|)
name|t
operator|<<
literal|"{"
operator|<<
name|it
operator|.
name|key
argument_list|()
operator|<<
literal|"}"
operator|<<
operator|(
operator|*
name|cppit
operator|)
operator|<<
literal|"{"
operator|<<
name|objDir
operator|<<
literal|"}"
operator|<<
name|Option
operator|::
name|obj_ext
operator|<<
literal|"::\n\t"
operator|<<
name|var
argument_list|(
literal|"QMAKE_RUN_CXX_IMP_BATCH"
argument_list|)
operator|.
name|replace
argument_list|(
name|QRegExp
argument_list|(
literal|"\\$@"
argument_list|)
argument_list|,
name|var
argument_list|(
literal|"OBJECTS_DIR"
argument_list|)
argument_list|)
operator|<<
name|endl
operator|<<
literal|"\t$<"
operator|<<
name|endl
operator|<<
literal|"<<"
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
for|for
control|(
name|QStringList
operator|::
name|Iterator
name|cit
init|=
name|Option
operator|::
name|c_ext
operator|.
name|begin
argument_list|()
init|;
name|cit
operator|!=
name|Option
operator|::
name|c_ext
operator|.
name|end
argument_list|()
condition|;
operator|++
name|cit
control|)
name|t
operator|<<
literal|"{"
operator|<<
name|it
operator|.
name|key
argument_list|()
operator|<<
literal|"}"
operator|<<
operator|(
operator|*
name|cit
operator|)
operator|<<
literal|"{"
operator|<<
name|objDir
operator|<<
literal|"}"
operator|<<
name|Option
operator|::
name|obj_ext
operator|<<
literal|"::\n\t"
operator|<<
name|var
argument_list|(
literal|"QMAKE_RUN_CC_IMP_BATCH"
argument_list|)
operator|.
name|replace
argument_list|(
name|QRegExp
argument_list|(
literal|"\\$@"
argument_list|)
argument_list|,
name|var
argument_list|(
literal|"OBJECTS_DIR"
argument_list|)
argument_list|)
operator|<<
name|endl
operator|<<
literal|"\t$<"
operator|<<
name|endl
operator|<<
literal|"<<"
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
block|}
block|}
else|else
block|{
for|for
control|(
name|QStringList
operator|::
name|Iterator
name|cppit
init|=
name|Option
operator|::
name|cpp_ext
operator|.
name|begin
argument_list|()
init|;
name|cppit
operator|!=
name|Option
operator|::
name|cpp_ext
operator|.
name|end
argument_list|()
condition|;
operator|++
name|cppit
control|)
name|t
operator|<<
operator|(
operator|*
name|cppit
operator|)
operator|<<
name|Option
operator|::
name|obj_ext
operator|<<
literal|":\n\t"
operator|<<
name|var
argument_list|(
literal|"QMAKE_RUN_CXX_IMP"
argument_list|)
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
for|for
control|(
name|QStringList
operator|::
name|Iterator
name|cit
init|=
name|Option
operator|::
name|c_ext
operator|.
name|begin
argument_list|()
init|;
name|cit
operator|!=
name|Option
operator|::
name|c_ext
operator|.
name|end
argument_list|()
condition|;
operator|++
name|cit
control|)
name|t
operator|<<
operator|(
operator|*
name|cit
operator|)
operator|<<
name|Option
operator|::
name|obj_ext
operator|<<
literal|":\n\t"
operator|<<
name|var
argument_list|(
literal|"QMAKE_RUN_CC_IMP"
argument_list|)
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|writeBuildRulesPart
name|void
name|NmakeMakefileGenerator
operator|::
name|writeBuildRulesPart
parameter_list|(
name|QTextStream
modifier|&
name|t
parameter_list|)
block|{
if|if
condition|(
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"aux"
condition|)
block|{
name|t
operator|<<
literal|"first:"
operator|<<
name|endl
expr_stmt|;
return|return;
block|}
name|t
operator|<<
literal|"first: all"
operator|<<
name|endl
expr_stmt|;
name|t
operator|<<
literal|"all: "
operator|<<
name|fileFixify
argument_list|(
name|Option
operator|::
name|output
operator|.
name|fileName
argument_list|()
argument_list|)
operator|<<
literal|" "
operator|<<
name|varGlue
argument_list|(
literal|"ALL_DEPS"
argument_list|,
literal|" "
argument_list|,
literal|" "
argument_list|,
literal|" "
argument_list|)
operator|<<
literal|"$(DESTDIR_TARGET)"
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
name|t
operator|<<
literal|"$(DESTDIR_TARGET): "
operator|<<
name|var
argument_list|(
literal|"PRE_TARGETDEPS"
argument_list|)
operator|<<
literal|" $(OBJECTS) "
operator|<<
name|var
argument_list|(
literal|"POST_TARGETDEPS"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|project
operator|->
name|isEmpty
argument_list|(
literal|"QMAKE_PRE_LINK"
argument_list|)
condition|)
name|t
operator|<<
literal|"\n\t"
operator|<<
name|var
argument_list|(
literal|"QMAKE_PRE_LINK"
argument_list|)
expr_stmt|;
if|if
condition|(
name|project
operator|->
name|isActiveConfig
argument_list|(
literal|"staticlib"
argument_list|)
condition|)
block|{
name|t
operator|<<
literal|"\n\t"
operator|<<
literal|"$(LIBAPP) $(LIBFLAGS) /OUT:$(DESTDIR_TARGET) @<<"
operator|<<
literal|"\n\t  "
operator|<<
literal|"$(OBJECTS)"
expr_stmt|;
block|}
else|else
block|{
name|t
operator|<<
literal|"\n\t"
operator|<<
literal|"$(LINK) $(LFLAGS) /OUT:$(DESTDIR_TARGET) @<< "
operator|<<
literal|"\n\t  "
operator|<<
literal|"$(OBJECTS) $(LIBS)"
expr_stmt|;
block|}
name|t
operator|<<
name|endl
operator|<<
literal|"<<"
expr_stmt|;
name|QString
name|signature
init|=
operator|!
name|project
operator|->
name|isEmpty
argument_list|(
literal|"SIGNATURE_FILE"
argument_list|)
condition|?
name|var
argument_list|(
literal|"SIGNATURE_FILE"
argument_list|)
else|:
name|var
argument_list|(
literal|"DEFAULT_SIGNATURE"
argument_list|)
decl_stmt|;
name|bool
name|useSignature
init|=
operator|!
name|signature
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|project
operator|->
name|isActiveConfig
argument_list|(
literal|"staticlib"
argument_list|)
operator|&&
operator|!
name|project
operator|->
name|isEmpty
argument_list|(
literal|"CE_SDK"
argument_list|)
operator|&&
operator|!
name|project
operator|->
name|isEmpty
argument_list|(
literal|"CE_ARCH"
argument_list|)
decl_stmt|;
if|if
condition|(
name|useSignature
condition|)
block|{
name|t
operator|<<
literal|"\n\tsigntool sign /F "
operator|<<
name|signature
operator|<<
literal|" $(DESTDIR_TARGET)"
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|project
operator|->
name|isEmpty
argument_list|(
literal|"QMAKE_POST_LINK"
argument_list|)
condition|)
block|{
name|t
operator|<<
literal|"\n\t"
operator|<<
name|var
argument_list|(
literal|"QMAKE_POST_LINK"
argument_list|)
expr_stmt|;
block|}
name|t
operator|<<
name|endl
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
