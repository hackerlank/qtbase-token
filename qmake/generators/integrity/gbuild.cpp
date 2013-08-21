begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"gbuild.h"
end_include
begin_include
include|#
directive|include
file|"option.h"
end_include
begin_include
include|#
directive|include
file|"meta.h"
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<time.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_UNIX
end_ifdef
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|dllbase
name|unsigned
name|int
name|dllbase
init|=
literal|0x01000000
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|DLLOFFSET
define|#
directive|define
name|DLLOFFSET
value|0x600000
end_define
begin_constructor
DECL|function|GBuildMakefileGenerator
name|GBuildMakefileGenerator
operator|::
name|GBuildMakefileGenerator
parameter_list|()
member_init_list|:
name|MakefileGenerator
argument_list|()
block|{
name|nativebins
operator|<<
literal|"moc"
operator|<<
literal|"rcc"
operator|<<
literal|"uic"
operator|<<
literal|"bootstrap"
expr_stmt|;
block|}
end_constructor
begin_function
name|bool
DECL|function|write
name|GBuildMakefileGenerator
operator|::
name|write
parameter_list|()
block|{
name|QStringList
name|tmp
decl_stmt|;
name|QString
name|filename
argument_list|(
name|Option
operator|::
name|output
operator|.
name|fileName
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|pathtoremove
argument_list|(
name|qmake_getpwd
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|relpath
argument_list|(
name|pathtoremove
argument_list|)
decl_stmt|;
name|QString
name|strtarget
argument_list|(
name|project
operator|->
name|first
argument_list|(
literal|"TARGET"
argument_list|)
operator|.
name|toQString
argument_list|()
argument_list|)
decl_stmt|;
name|bool
name|isnativebin
init|=
name|nativebins
operator|.
name|contains
argument_list|(
name|strtarget
argument_list|)
decl_stmt|;
name|relpath
operator|.
name|replace
argument_list|(
name|Option
operator|::
name|output_dir
argument_list|,
literal|""
argument_list|)
expr_stmt|;
comment|/* correct output for non-prl, non-recursive case */
name|QString
name|outname
argument_list|(
name|qmake_getpwd
argument_list|()
argument_list|)
decl_stmt|;
name|outname
operator|+=
name|QDir
operator|::
name|separator
argument_list|()
expr_stmt|;
name|outname
operator|+=
name|fileInfo
argument_list|(
name|Option
operator|::
name|output
operator|.
name|fileName
argument_list|()
argument_list|)
operator|.
name|baseName
argument_list|()
expr_stmt|;
name|outname
operator|+=
name|projectSuffix
argument_list|()
expr_stmt|;
name|Option
operator|::
name|output
operator|.
name|close
argument_list|()
expr_stmt|;
name|Option
operator|::
name|output
operator|.
name|setFileName
argument_list|(
name|outname
argument_list|)
expr_stmt|;
name|MakefileGenerator
operator|::
name|openOutput
argument_list|(
name|Option
operator|::
name|output
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|strtarget
operator|!=
name|fileInfo
argument_list|(
name|project
operator|->
name|projectFile
argument_list|()
argument_list|)
operator|.
name|baseName
argument_list|()
condition|)
block|{
name|QString
name|gpjname
argument_list|(
name|strtarget
argument_list|)
decl_stmt|;
name|QString
name|outputName
argument_list|(
name|qmake_getpwd
argument_list|()
argument_list|)
decl_stmt|;
name|outputName
operator|+=
name|QDir
operator|::
name|separator
argument_list|()
expr_stmt|;
name|outputName
operator|+=
name|fileInfo
argument_list|(
name|project
operator|->
name|projectFile
argument_list|()
argument_list|)
operator|.
name|baseName
argument_list|()
expr_stmt|;
name|outputName
operator|+=
name|projectSuffix
argument_list|()
expr_stmt|;
name|QFile
name|f
argument_list|(
name|outputName
argument_list|)
decl_stmt|;
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Text
operator||
name|QIODevice
operator|::
name|Truncate
argument_list|)
expr_stmt|;
name|QTextStream
name|t
argument_list|(
operator|&
name|f
argument_list|)
decl_stmt|;
name|t
operator|<<
literal|"#!gbuild\n"
expr_stmt|;
name|t
operator|<<
literal|"[Project]\n"
expr_stmt|;
name|t
operator|<<
name|gpjname
operator|<<
name|projectSuffix
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
if|if
condition|(
operator|(
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"lib"
operator|)
operator|&&
name|project
operator|->
name|isActiveConfig
argument_list|(
literal|"shared"
argument_list|)
condition|)
name|t
operator|<<
name|gpjname
operator|<<
literal|"_shared"
operator|<<
name|projectSuffix
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
name|t
operator|.
name|flush
argument_list|()
expr_stmt|;
name|gpjname
operator|+=
name|projectSuffix
argument_list|()
expr_stmt|;
name|Option
operator|::
name|output
operator|.
name|close
argument_list|()
expr_stmt|;
name|Option
operator|::
name|output
operator|.
name|setFileName
argument_list|(
name|gpjname
argument_list|)
expr_stmt|;
name|MakefileGenerator
operator|::
name|openOutput
argument_list|(
name|Option
operator|::
name|output
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"app"
operator|)
operator|&&
operator|(
operator|!
name|isnativebin
operator|)
condition|)
block|{
name|QTextStream
name|t
argument_list|(
operator|&
name|Option
operator|::
name|output
argument_list|)
decl_stmt|;
name|QString
name|intname
argument_list|(
name|strtarget
argument_list|)
decl_stmt|;
name|intname
operator|+=
literal|".int"
expr_stmt|;
comment|/* this is for bulding an INTEGRITY application.          * generate the .int integrate file and the .gpj INTEGRITY Application          * project file, then go on with regular files */
name|t
operator|<<
literal|"#!gbuild\n"
expr_stmt|;
name|t
operator|<<
literal|"[INTEGRITY Application]\n"
expr_stmt|;
name|t
operator|<<
literal|"\t:binDirRelative=.\n"
expr_stmt|;
name|t
operator|<<
literal|"\t-o "
operator|<<
name|strtarget
operator|<<
literal|"\n"
expr_stmt|;
name|t
operator|<<
name|intname
operator|<<
literal|"\n"
expr_stmt|;
name|t
operator|<<
name|strtarget
operator|<<
literal|"_app"
operator|<<
name|projectSuffix
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
name|t
operator|.
name|flush
argument_list|()
expr_stmt|;
comment|/* generate integrate file */
name|QFile
name|f
argument_list|(
name|intname
argument_list|)
decl_stmt|;
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Text
operator||
name|QIODevice
operator|::
name|Truncate
argument_list|)
expr_stmt|;
name|QTextStream
name|ti
argument_list|(
operator|&
name|f
argument_list|)
decl_stmt|;
name|ti
operator|<<
literal|"# This is a file automatically generated by qmake\n"
expr_stmt|;
name|ti
operator|<<
literal|"# Modifications will be lost next time you run qmake\n"
expr_stmt|;
name|ti
operator|<<
literal|"Kernel\n"
expr_stmt|;
name|ti
operator|<<
literal|"\tFilename\tDynamicDownload\n"
expr_stmt|;
name|ti
operator|<<
literal|"EndKernel\n\n"
expr_stmt|;
name|ti
operator|<<
literal|"AddressSpace\n"
expr_stmt|;
name|ti
operator|<<
literal|"\tName\t"
operator|<<
name|strtarget
operator|<<
literal|"\n"
expr_stmt|;
name|ti
operator|<<
literal|"\tFilename\t"
operator|<<
name|strtarget
operator|<<
literal|"_app\n"
expr_stmt|;
name|ti
operator|<<
literal|"\tMemoryPoolSize\t0x100000\n"
expr_stmt|;
name|ti
operator|<<
literal|"\tLanguage\tC++\n"
expr_stmt|;
comment|/* FIXME : heap size is huge to be big enough for every example          * it should probably be tailored for each example, btu there is no          * good way to guess that */
name|ti
operator|<<
literal|"\tHeapSize\t0x00D00000\n"
expr_stmt|;
name|ti
operator|<<
literal|"\tTask\tInitial\n"
expr_stmt|;
name|ti
operator|<<
literal|"\t\tStackSize\t0x30000\n"
expr_stmt|;
name|ti
operator|<<
literal|"\tEndTask\n"
expr_stmt|;
name|ti
operator|<<
literal|"EndAddressSpace\n"
expr_stmt|;
name|ti
operator|.
name|flush
argument_list|()
expr_stmt|;
comment|/* change current project file to<projectname>_app.gpj and continue          * generation */
name|filename
operator|.
name|insert
argument_list|(
name|filename
operator|.
name|lastIndexOf
argument_list|(
literal|"."
argument_list|)
argument_list|,
literal|"_app"
argument_list|)
expr_stmt|;
name|Option
operator|::
name|output
operator|.
name|close
argument_list|()
expr_stmt|;
name|Option
operator|::
name|output
operator|.
name|setFileName
argument_list|(
name|filename
argument_list|)
expr_stmt|;
name|MakefileGenerator
operator|::
name|openOutput
argument_list|(
name|Option
operator|::
name|output
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"lib"
operator|)
operator|&&
name|project
operator|->
name|isActiveConfig
argument_list|(
literal|"shared"
argument_list|)
condition|)
block|{
name|QString
name|gpjname
argument_list|(
name|strtarget
argument_list|)
decl_stmt|;
name|gpjname
operator|+=
literal|"_shared"
expr_stmt|;
name|gpjname
operator|+=
name|projectSuffix
argument_list|()
expr_stmt|;
name|QFile
name|f
argument_list|(
name|gpjname
argument_list|)
decl_stmt|;
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Text
operator||
name|QIODevice
operator|::
name|Truncate
argument_list|)
expr_stmt|;
name|QTextStream
name|t
argument_list|(
operator|&
name|f
argument_list|)
decl_stmt|;
name|t
operator|<<
literal|"#!gbuild\n"
literal|"[Program]\n"
literal|"\t-A libINTEGRITY.so\n"
literal|"\t-A libc.so\n"
literal|"\t-A libscxx.so\n"
literal|"\t-A libQtCore.so\n"
literal|"\t-e __ghsbegin_text\n"
literal|"\t-startfile=-\n"
literal|"\t:syslibraries=-\n"
literal|"\t-Onolink\n"
expr_stmt|;
name|t
operator|<<
literal|"\t-o lib"
operator|<<
name|strtarget
operator|<<
literal|".so\n"
expr_stmt|;
name|t
operator|<<
literal|"\t-l"
operator|<<
name|strtarget
operator|<<
literal|"\n"
expr_stmt|;
name|t
operator|<<
literal|"\t-extractall=-l"
operator|<<
name|strtarget
operator|<<
literal|"\n"
expr_stmt|;
name|t
operator|<<
literal|"\t:outputDir=work/"
operator|<<
name|filename
operator|.
name|section
argument_list|(
name|QDir
operator|::
name|separator
argument_list|()
argument_list|,
literal|0
argument_list|,
operator|-
literal|1
argument_list|)
operator|.
name|remove
argument_list|(
literal|".gpj"
argument_list|)
operator|<<
literal|"\n"
expr_stmt|;
name|t
operator|<<
name|strtarget
operator|<<
literal|"_shared.ld\n"
expr_stmt|;
name|t
operator|<<
literal|"$(__OS_DIR)/intlib/sharedobjbssinit.c\n"
expr_stmt|;
name|t
operator|.
name|flush
argument_list|()
expr_stmt|;
name|QFile
name|fl
argument_list|(
name|strtarget
operator|+
literal|"_shared.ld"
argument_list|)
decl_stmt|;
name|fl
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Text
operator||
name|QIODevice
operator|::
name|Truncate
argument_list|)
expr_stmt|;
name|QTextStream
name|tl
argument_list|(
operator|&
name|fl
argument_list|)
decl_stmt|;
name|tl
operator|<<
literal|"CONSTANTS {\n"
literal|"    __INTEGRITY_MinPageAlign          = 16K\n"
literal|"    __INTEGRITY_MaxPageAlign          = 16K\n"
literal|"    __INTEGRITY_LibCBaseAddress       = \n"
expr_stmt|;
name|tl
operator|<<
name|dllbase
operator|<<
literal|"\n"
expr_stmt|;
name|tl
operator|<<
literal|"}\n"
literal|"-sec\n"
literal|"{\n"
literal|"  .picbase __INTEGRITY_LibCBaseAddress :\n"
literal|"        .text :\n"
literal|"  .syscall :\n"
literal|"        .intercall :\n"
literal|"        .interfunc :\n"
literal|"  .secinfo :\n"
literal|"  .rodata align(16) :\n"
literal|"  .fixaddr :\n"
literal|"  .fixtype :\n"
literal|"        .rombeg :\n"
literal|"        .textchecksum :\n"
literal|"        // The above sections may be large. Leave a bigger gap for large pages.\n"
literal|"  .pidbase align(__INTEGRITY_MaxPageAlign) :\n"
literal|"        .sdabase :\n"
literal|"        .data :\n"
literal|"        .toc :\n"
literal|"        .opd :\n"
literal|"        .datachecksum :\n"
literal|"  .bss align(__INTEGRITY_MinPageAlign) :\n"
literal|"        .heap :\n"
literal|"}\n"
expr_stmt|;
name|tl
operator|.
name|flush
argument_list|()
expr_stmt|;
name|dllbase
operator|+=
name|DLLOFFSET
expr_stmt|;
block|}
name|QTextStream
name|t
argument_list|(
operator|&
name|Option
operator|::
name|output
argument_list|)
decl_stmt|;
name|QString
name|primaryTarget
argument_list|(
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_CXX"
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toQString
argument_list|()
argument_list|)
decl_stmt|;
name|pathtoremove
operator|+=
name|QDir
operator|::
name|separator
argument_list|()
expr_stmt|;
name|filename
operator|.
name|remove
argument_list|(
name|qmake_getpwd
argument_list|()
argument_list|)
expr_stmt|;
comment|//HEADER
name|t
operator|<<
literal|"#!gbuild\n"
expr_stmt|;
comment|/* find the architecture out of the compiler name */
if|if
condition|(
name|filename
operator|.
name|endsWith
argument_list|(
literal|"projects.gpj"
argument_list|)
condition|)
block|{
name|primaryTarget
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|t
operator|<<
literal|"macro QT_BUILD_DIR=%expand_path(.)\n"
expr_stmt|;
name|t
operator|<<
literal|"macro __OS_DIR="
operator|<<
name|project
operator|->
name|values
argument_list|(
literal|"INTEGRITY_DIR"
argument_list|)
operator|.
name|first
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
name|t
operator|<<
literal|"primaryTarget="
operator|<<
name|primaryTarget
operator|<<
literal|"_integrity.tgt\n"
expr_stmt|;
name|t
operator|<<
literal|"customization=util/integrity/qt.bod\n"
expr_stmt|;
block|}
comment|/* project type */
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
block|{
name|t
operator|<<
literal|"[Program]\n"
expr_stmt|;
if|if
condition|(
name|isnativebin
condition|)
block|{
name|t
operator|<<
literal|"\t:binDir=bin\n"
expr_stmt|;
name|t
operator|<<
literal|"\t-o "
operator|<<
name|strtarget
operator|<<
literal|"\n"
expr_stmt|;
block|}
else|else
block|{
name|t
operator|<<
literal|"\t:binDirRelative=.\n"
expr_stmt|;
name|t
operator|<<
literal|"\t-o "
operator|<<
name|strtarget
operator|<<
literal|"_app\n"
expr_stmt|;
block|}
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
literal|"lib"
condition|)
block|{
name|t
operator|<<
literal|"[Library]\n"
expr_stmt|;
name|t
operator|<<
literal|"\t:binDir=lib\n"
expr_stmt|;
name|t
operator|<<
literal|"\t-o lib"
operator|<<
name|strtarget
operator|<<
literal|".a\n"
expr_stmt|;
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
name|t
operator|<<
literal|"[Project]\n"
expr_stmt|;
else|else
name|t
operator|<<
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|<<
literal|"\n"
expr_stmt|;
comment|/* compilations options */
name|t
operator|<<
literal|"\t:sourceDir=.\n"
expr_stmt|;
name|t
operator|<<
literal|"\t:outputDir=work"
operator|<<
name|relpath
operator|<<
literal|"\n"
expr_stmt|;
if|if
condition|(
name|filename
operator|.
name|endsWith
argument_list|(
literal|"projects.gpj"
argument_list|)
condition|)
block|{
name|t
operator|<<
literal|"\t:sourceDir=work\n"
expr_stmt|;
name|t
operator|<<
literal|"\t-Iwork\n"
expr_stmt|;
name|t
operator|<<
literal|"\t-Llib\n"
expr_stmt|;
name|t
operator|<<
literal|"\t"
expr_stmt|;
specifier|const
name|ProStringList
modifier|&
name|l
init|=
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_CXXFLAGS"
argument_list|)
decl_stmt|;
for|for
control|(
name|ProStringList
operator|::
name|ConstIterator
name|it
init|=
name|l
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|l
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
operator|(
operator|*
name|it
operator|)
operator|.
name|startsWith
argument_list|(
literal|"-"
argument_list|)
condition|)
name|t
operator|<<
literal|"\n\t"
operator|<<
operator|(
operator|*
name|it
operator|)
expr_stmt|;
else|else
name|t
operator|<<
literal|" "
operator|<<
operator|(
operator|*
name|it
operator|)
expr_stmt|;
block|}
name|t
operator|<<
literal|"\n"
expr_stmt|;
block|}
name|t
operator|<<
literal|"\n"
expr_stmt|;
name|t
operator|<<
name|varGlue
argument_list|(
literal|"DEFINES"
argument_list|,
literal|"\t-D"
argument_list|,
literal|"\n\t-D"
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|t
operator|<<
literal|"\t-I.\n\t-I"
operator|<<
name|specdir
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
name|t
operator|<<
name|varGlue
argument_list|(
literal|"INCLUDEPATH"
argument_list|,
literal|"\t-I"
argument_list|,
literal|"\n\t-I"
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|t
operator|<<
literal|"\t--cxx_include_directory .\n\t--cxx_include_directory "
operator|<<
name|specdir
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
name|t
operator|<<
name|varGlue
argument_list|(
literal|"INCLUDEPATH"
argument_list|,
literal|"\t--cxx_include_directory "
argument_list|,
literal|"\n\t--cxx_include_directory "
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
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
block|{
comment|/* include linker flags if it's an application */
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|src
index|[]
init|=
block|{
literal|"QMAKE_LFLAGS"
block|,
literal|"QMAKE_LIBS"
block|,
literal|"LIBS"
block|,
literal|0
block|}
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|src
index|[
name|i
index|]
condition|;
name|i
operator|++
control|)
block|{
comment|/* skip target libraries for native tools */
if|if
condition|(
name|isnativebin
operator|&&
operator|(
name|i
operator|==
literal|0
operator|)
condition|)
continue|continue;
name|t
operator|<<
literal|"\t"
expr_stmt|;
specifier|const
name|ProStringList
modifier|&
name|l
init|=
name|project
operator|->
name|values
argument_list|(
name|src
index|[
name|i
index|]
argument_list|)
decl_stmt|;
for|for
control|(
name|ProStringList
operator|::
name|ConstIterator
name|it
init|=
name|l
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|l
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
operator|(
operator|*
name|it
operator|)
operator|.
name|startsWith
argument_list|(
literal|"-"
argument_list|)
condition|)
name|t
operator|<<
literal|"\n\t"
operator|<<
operator|(
operator|*
name|it
operator|)
expr_stmt|;
else|else
name|t
operator|<<
literal|" "
operator|<<
operator|(
operator|*
name|it
operator|)
expr_stmt|;
block|}
name|t
operator|<<
literal|"\n"
expr_stmt|;
block|}
block|}
comment|/* first subdirectories/subprojects */
block|{
specifier|const
name|ProStringList
modifier|&
name|l
init|=
name|project
operator|->
name|values
argument_list|(
literal|"SUBDIRS"
argument_list|)
decl_stmt|;
for|for
control|(
name|ProStringList
operator|::
name|ConstIterator
name|it
init|=
name|l
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|l
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|QString
name|gpjname
argument_list|(
operator|(
operator|*
name|it
operator|)
operator|.
name|toQString
argument_list|()
argument_list|)
decl_stmt|;
comment|/* avoid native tools */
if|if
condition|(
name|nativebins
operator|.
name|contains
argument_list|(
name|gpjname
operator|.
name|section
argument_list|(
literal|"_"
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|)
condition|)
continue|continue;
specifier|const
name|ProKey
name|skey
argument_list|(
operator|*
name|it
operator|+
literal|".subdir"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|project
operator|->
name|first
argument_list|(
name|skey
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
name|gpjname
operator|=
name|project
operator|->
name|first
argument_list|(
name|skey
argument_list|)
operator|.
name|toQString
argument_list|()
expr_stmt|;
else|else
name|gpjname
operator|.
name|replace
argument_list|(
literal|"_"
argument_list|,
name|QDir
operator|::
name|separator
argument_list|()
argument_list|)
expr_stmt|;
name|gpjname
operator|+=
name|QDir
operator|::
name|separator
argument_list|()
operator|+
name|gpjname
operator|.
name|section
argument_list|(
name|QDir
operator|::
name|separator
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|gpjname
operator|+=
name|projectSuffix
argument_list|()
expr_stmt|;
comment|/* make relative */
if|if
condition|(
operator|!
name|project
operator|->
name|values
argument_list|(
literal|"QT_SOURCE_TREE"
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|gpjname
operator|.
name|replace
argument_list|(
name|project
operator|->
name|values
argument_list|(
literal|"QT_SOURCE_TREE"
argument_list|)
operator|.
name|first
argument_list|()
operator|+
name|QDir
operator|::
name|separator
argument_list|()
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
name|t
operator|<<
name|gpjname
operator|<<
literal|"\n"
expr_stmt|;
block|}
block|}
block|{
specifier|const
name|ProStringList
modifier|&
name|l
init|=
name|project
operator|->
name|values
argument_list|(
literal|"RESOURCES"
argument_list|)
decl_stmt|;
for|for
control|(
name|ProStringList
operator|::
name|ConstIterator
name|it
init|=
name|l
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|l
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|QString
name|tmpstr
argument_list|(
operator|(
operator|*
name|it
operator|)
operator|.
name|toQString
argument_list|()
argument_list|)
decl_stmt|;
name|tmpstr
operator|.
name|remove
argument_list|(
name|pathtoremove
argument_list|)
expr_stmt|;
name|t
operator|<<
name|tmpstr
operator|<<
literal|"\t[Qt Resource]\n"
expr_stmt|;
name|tmpstr
operator|=
name|tmpstr
operator|.
name|section
argument_list|(
literal|"."
argument_list|,
operator|-
literal|2
argument_list|,
operator|-
literal|1
argument_list|)
operator|.
name|section
argument_list|(
name|QDir
operator|::
name|separator
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|tmpstr
operator|.
name|remove
argument_list|(
literal|".qrc"
argument_list|)
expr_stmt|;
name|t
operator|<<
literal|"\t-name "
operator|<<
name|tmpstr
operator|<<
literal|"\n"
expr_stmt|;
name|tmpstr
operator|.
name|insert
argument_list|(
name|tmpstr
operator|.
name|lastIndexOf
argument_list|(
name|QDir
operator|::
name|separator
argument_list|()
argument_list|)
operator|+
literal|1
argument_list|,
literal|"qrc_"
argument_list|)
expr_stmt|;
name|tmpstr
operator|.
name|append
argument_list|(
literal|".cpp"
argument_list|)
expr_stmt|;
name|t
operator|<<
literal|"\t-o work/"
operator|<<
name|tmpstr
operator|<<
literal|"\n"
expr_stmt|;
block|}
block|}
block|{
specifier|const
name|ProStringList
modifier|&
name|l
init|=
name|project
operator|->
name|values
argument_list|(
literal|"FORMS"
argument_list|)
decl_stmt|;
for|for
control|(
name|ProStringList
operator|::
name|ConstIterator
name|it
init|=
name|l
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|l
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|QString
name|tmpstr
argument_list|(
operator|(
operator|*
name|it
operator|)
operator|.
name|toQString
argument_list|()
argument_list|)
decl_stmt|;
name|tmpstr
operator|.
name|remove
argument_list|(
name|pathtoremove
argument_list|)
expr_stmt|;
name|t
operator|<<
name|tmpstr
operator|<<
literal|"\t[Qt Dialog]\n"
expr_stmt|;
name|tmpstr
operator|=
name|tmpstr
operator|.
name|section
argument_list|(
literal|"."
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|.
name|section
argument_list|(
name|QDir
operator|::
name|separator
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|tmpstr
operator|.
name|insert
argument_list|(
name|tmpstr
operator|.
name|lastIndexOf
argument_list|(
name|QDir
operator|::
name|separator
argument_list|()
argument_list|)
operator|+
literal|1
argument_list|,
literal|"ui_"
argument_list|)
expr_stmt|;
name|tmpstr
operator|.
name|remove
argument_list|(
literal|".ui"
argument_list|)
expr_stmt|;
name|tmpstr
operator|.
name|append
argument_list|(
literal|".h"
argument_list|)
expr_stmt|;
name|t
operator|<<
literal|"\t-o work/"
operator|<<
name|tmpstr
operator|<<
literal|"\n"
expr_stmt|;
block|}
block|}
comment|/* source files for this project */
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|src
index|[]
init|=
block|{
literal|"HEADERS"
block|,
literal|"SOURCES"
block|,
literal|0
block|}
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|src
index|[
name|i
index|]
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|ProStringList
modifier|&
name|l
init|=
name|project
operator|->
name|values
argument_list|(
name|src
index|[
name|i
index|]
argument_list|)
decl_stmt|;
for|for
control|(
name|ProStringList
operator|::
name|ConstIterator
name|it
init|=
name|l
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|l
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
operator|(
operator|*
name|it
operator|)
operator|.
name|isEmpty
argument_list|()
condition|)
continue|continue;
comment|/* native tools aren't preprocessed */
if|if
condition|(
operator|!
name|isnativebin
condition|)
name|t
operator|<<
name|writeOne
argument_list|(
operator|(
operator|*
name|it
operator|)
operator|.
name|toQString
argument_list|()
argument_list|,
name|pathtoremove
argument_list|)
expr_stmt|;
else|else
name|t
operator|<<
operator|(
operator|*
name|it
operator|)
operator|.
name|toQString
argument_list|()
operator|.
name|remove
argument_list|(
name|pathtoremove
argument_list|)
operator|<<
literal|"\n"
expr_stmt|;
block|}
block|}
name|t
operator|<<
literal|"\n"
expr_stmt|;
block|{
specifier|const
name|ProStringList
modifier|&
name|l
init|=
name|project
operator|->
name|values
argument_list|(
literal|"GENERATED_SOURCES"
argument_list|)
decl_stmt|;
for|for
control|(
name|ProStringList
operator|::
name|ConstIterator
name|it
init|=
name|l
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|l
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|t
operator|<<
literal|"work/"
operator|<<
operator|(
operator|*
name|it
operator|)
operator|.
name|toQString
argument_list|()
operator|.
name|section
argument_list|(
name|QDir
operator|::
name|separator
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
operator|<<
literal|"\n"
expr_stmt|;
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|writeOne
name|QString
name|GBuildMakefileGenerator
operator|::
name|writeOne
parameter_list|(
name|QString
name|filename
parameter_list|,
name|QString
name|pathtoremove
parameter_list|)
block|{
name|QString
name|s
argument_list|(
literal|""
argument_list|)
decl_stmt|;
name|s
operator|+=
name|filename
operator|.
name|remove
argument_list|(
name|pathtoremove
argument_list|)
expr_stmt|;
if|if
condition|(
name|filename
operator|.
name|endsWith
argument_list|(
name|Option
operator|::
name|h_ext
operator|.
name|first
argument_list|()
argument_list|)
condition|)
block|{
name|QString
name|corename
argument_list|(
name|filename
operator|.
name|section
argument_list|(
name|QDir
operator|::
name|separator
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|)
decl_stmt|;
name|corename
operator|.
name|remove
argument_list|(
name|Option
operator|::
name|h_ext
operator|.
name|first
argument_list|()
argument_list|)
expr_stmt|;
name|corename
operator|.
name|append
argument_list|(
name|Option
operator|::
name|cpp_ext
operator|.
name|first
argument_list|()
argument_list|)
expr_stmt|;
name|corename
operator|.
name|prepend
argument_list|(
name|Option
operator|::
name|h_moc_mod
argument_list|)
expr_stmt|;
name|s
operator|+=
literal|"\t[MOC/Qt Header]\n"
expr_stmt|;
name|s
operator|+=
literal|"\t-o "
expr_stmt|;
name|s
operator|+=
literal|"work/"
expr_stmt|;
name|s
operator|+=
name|corename
expr_stmt|;
name|s
operator|+=
literal|"\n"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|filename
operator|.
name|section
argument_list|(
name|QDir
operator|::
name|separator
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
operator|.
name|startsWith
argument_list|(
literal|"qrc_"
argument_list|)
condition|)
block|{
name|QString
name|tmpstr
argument_list|(
name|filename
operator|.
name|section
argument_list|(
literal|"/"
argument_list|,
operator|-
literal|1
argument_list|)
operator|.
name|section
argument_list|(
literal|"."
argument_list|,
literal|0
argument_list|,
operator|-
literal|1
argument_list|)
operator|.
name|remove
argument_list|(
literal|"qrc_"
argument_list|)
operator|.
name|remove
argument_list|(
literal|".cpp"
argument_list|)
argument_list|)
decl_stmt|;
name|s
operator|+=
literal|"\n\t:depends="
expr_stmt|;
name|s
operator|+=
name|tmpstr
expr_stmt|;
name|s
operator|+=
literal|".qrc"
expr_stmt|;
name|s
operator|+=
literal|"\n"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|filename
operator|.
name|endsWith
argument_list|(
name|Option
operator|::
name|cpp_ext
operator|.
name|first
argument_list|()
argument_list|)
condition|)
block|{
name|QString
name|tmpstr
argument_list|(
name|filename
operator|.
name|section
argument_list|(
literal|"/"
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|filepath
argument_list|(
name|pathtoremove
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|project
operator|->
name|values
argument_list|(
literal|"QT_SOURCE_TREE"
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|filepath
operator|.
name|remove
argument_list|(
name|project
operator|->
name|first
argument_list|(
literal|"QT_SOURCE_TREE"
argument_list|)
operator|.
name|toQString
argument_list|()
argument_list|)
expr_stmt|;
name|filepath
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|s
operator|+=
literal|"\n\t:preexecShellSafe='${QT_BUILD_DIR}/bin/moc "
expr_stmt|;
name|s
operator|+=
literal|"-nn "
expr_stmt|;
name|s
operator|+=
name|varGlue
argument_list|(
literal|"DEFINES"
argument_list|,
literal|"-D"
argument_list|,
literal|" -D"
argument_list|,
literal|" "
argument_list|)
expr_stmt|;
name|s
operator|+=
name|varGlue
argument_list|(
literal|"INCLUDEPATH"
argument_list|,
literal|"-I"
argument_list|,
literal|" -I"
argument_list|,
literal|" "
argument_list|)
expr_stmt|;
name|s
operator|+=
name|filepath
expr_stmt|;
name|s
operator|+=
name|filename
expr_stmt|;
name|s
operator|+=
literal|" -o "
expr_stmt|;
name|tmpstr
operator|.
name|replace
argument_list|(
name|Option
operator|::
name|cpp_ext
operator|.
name|first
argument_list|()
argument_list|,
name|Option
operator|::
name|cpp_moc_ext
argument_list|)
expr_stmt|;
name|s
operator|+=
literal|"work/"
expr_stmt|;
name|s
operator|+=
name|tmpstr
expr_stmt|;
name|s
operator|+=
literal|"\n"
expr_stmt|;
block|}
else|else
name|s
operator|+=
literal|"\n"
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_function
name|bool
DECL|function|openOutput
name|GBuildMakefileGenerator
operator|::
name|openOutput
parameter_list|(
name|QFile
modifier|&
name|file
parameter_list|,
specifier|const
name|QString
modifier|&
name|build
parameter_list|)
specifier|const
block|{
name|debug_msg
argument_list|(
literal|1
argument_list|,
literal|"file is %s"
argument_list|,
name|file
operator|.
name|fileName
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|QFileInfo
name|fi
argument_list|(
name|file
argument_list|)
decl_stmt|;
if|if
condition|(
name|fi
operator|.
name|filePath
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|file
operator|.
name|setFileName
argument_list|(
name|qmake_getpwd
argument_list|()
operator|+
name|QDir
operator|::
name|separator
argument_list|()
operator|+
name|file
operator|.
name|fileName
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|fileName
argument_list|()
operator|.
name|endsWith
argument_list|(
name|projectSuffix
argument_list|()
argument_list|)
condition|)
block|{
name|QString
name|outputName
argument_list|(
name|file
operator|.
name|fileName
argument_list|()
argument_list|)
decl_stmt|;
name|outputName
operator|+=
name|QDir
operator|::
name|separator
argument_list|()
expr_stmt|;
name|outputName
operator|+=
name|fileInfo
argument_list|(
name|project
operator|->
name|projectFile
argument_list|()
argument_list|)
operator|.
name|baseName
argument_list|()
expr_stmt|;
name|outputName
operator|+=
name|projectSuffix
argument_list|()
expr_stmt|;
name|file
operator|.
name|setFileName
argument_list|(
name|outputName
argument_list|)
expr_stmt|;
block|}
name|debug_msg
argument_list|(
literal|1
argument_list|,
literal|"file is %s"
argument_list|,
name|file
operator|.
name|fileName
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|bool
name|ret
init|=
name|MakefileGenerator
operator|::
name|openOutput
argument_list|(
name|file
argument_list|,
name|QString
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
