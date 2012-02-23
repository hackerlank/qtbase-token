begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"testcompiler.h"
end_include
begin_include
include|#
directive|include
file|<QProcess>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_function
DECL|function|targetName
specifier|static
name|QString
name|targetName
parameter_list|(
name|BuildType
name|buildMode
parameter_list|,
specifier|const
name|QString
modifier|&
name|target
parameter_list|,
specifier|const
name|QString
modifier|&
name|version
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|version
argument_list|)
expr_stmt|;
name|QString
name|targetName
init|=
name|target
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
switch|switch
condition|(
name|buildMode
condition|)
block|{
case|case
name|Exe
case|:
comment|// app
name|targetName
operator|.
name|append
argument_list|(
literal|".exe"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Dll
case|:
comment|// dll
if|if
condition|(
operator|!
name|version
operator|.
name|isEmpty
argument_list|()
condition|)
name|targetName
operator|.
name|append
argument_list|(
name|version
operator|.
name|section
argument_list|(
literal|"."
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|targetName
operator|.
name|append
argument_list|(
literal|".dll"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Lib
case|:
comment|// lib
ifdef|#
directive|ifdef
name|Q_CC_GNU
name|targetName
operator|.
name|prepend
argument_list|(
literal|"lib"
argument_list|)
expr_stmt|;
name|targetName
operator|.
name|append
argument_list|(
literal|".a"
argument_list|)
expr_stmt|;
else|#
directive|else
name|targetName
operator|.
name|append
argument_list|(
literal|".lib"
argument_list|)
expr_stmt|;
endif|#
directive|endif
break|break;
case|case
name|Plain
case|:
comment|// no conversion
break|break;
block|}
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
switch|switch
condition|(
name|buildMode
condition|)
block|{
case|case
name|Exe
case|:
comment|// app
name|targetName
operator|+=
literal|".app/Contents/MacOS/"
operator|+
name|target
operator|.
name|section
argument_list|(
literal|'/'
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
name|Dll
case|:
comment|// dll
name|targetName
operator|.
name|prepend
argument_list|(
literal|"lib"
argument_list|)
expr_stmt|;
name|targetName
operator|.
name|append
argument_list|(
literal|"."
operator|+
name|version
operator|+
literal|".dylib"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Lib
case|:
comment|// lib
name|targetName
operator|.
name|prepend
argument_list|(
literal|"lib"
argument_list|)
expr_stmt|;
name|targetName
operator|.
name|append
argument_list|(
literal|".a"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Plain
case|:
comment|// no conversion
break|break;
block|}
else|#
directive|else
switch|switch
condition|(
name|buildMode
condition|)
block|{
case|case
name|Exe
case|:
comment|// app
break|break;
case|case
name|Dll
case|:
comment|// dll
name|targetName
operator|.
name|prepend
argument_list|(
literal|"lib"
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_HPUX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ia64
argument_list|)
name|targetName
operator|.
name|append
argument_list|(
literal|".sl"
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_AIX
argument_list|)
name|targetName
operator|.
name|append
argument_list|(
literal|".a"
argument_list|)
expr_stmt|;
else|#
directive|else
name|targetName
operator|.
name|append
argument_list|(
literal|".so"
argument_list|)
expr_stmt|;
endif|#
directive|endif
break|break;
case|case
name|Lib
case|:
comment|// lib
name|targetName
operator|.
name|prepend
argument_list|(
literal|"lib"
argument_list|)
expr_stmt|;
name|targetName
operator|.
name|append
argument_list|(
literal|".a"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Plain
case|:
comment|// no conversion
break|break;
block|}
endif|#
directive|endif
return|return
name|targetName
return|;
block|}
end_function
begin_constructor
DECL|function|TestCompiler
name|TestCompiler
operator|::
name|TestCompiler
parameter_list|()
block|{
name|setBaseCommands
argument_list|(
literal|""
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~TestCompiler
name|TestCompiler
operator|::
name|~
name|TestCompiler
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|errorOut
name|bool
name|TestCompiler
operator|::
name|errorOut
parameter_list|()
block|{
name|qDebug
argument_list|(
name|qPrintable
argument_list|(
name|testOutput_
operator|.
name|join
argument_list|(
literal|"\n"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|runCommand
name|bool
name|TestCompiler
operator|::
name|runCommand
parameter_list|(
name|QString
name|cmdline
parameter_list|,
name|bool
name|expectFail
parameter_list|)
block|{
name|testOutput_
operator|.
name|append
argument_list|(
literal|"Running command: "
operator|+
name|cmdline
argument_list|)
expr_stmt|;
name|QProcess
name|child
decl_stmt|;
if|if
condition|(
operator|!
name|environment_
operator|.
name|empty
argument_list|()
condition|)
name|child
operator|.
name|setEnvironment
argument_list|(
name|QProcess
operator|::
name|systemEnvironment
argument_list|()
operator|+
name|environment_
argument_list|)
expr_stmt|;
name|child
operator|.
name|start
argument_list|(
name|cmdline
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|child
operator|.
name|waitForStarted
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
block|{
name|testOutput_
operator|.
name|append
argument_list|(
literal|"Unable to start child process."
argument_list|)
expr_stmt|;
return|return
name|errorOut
argument_list|()
return|;
block|}
name|child
operator|.
name|setReadChannel
argument_list|(
name|QProcess
operator|::
name|StandardError
argument_list|)
expr_stmt|;
name|child
operator|.
name|waitForFinished
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|bool
name|ok
init|=
name|child
operator|.
name|exitStatus
argument_list|()
operator|==
name|QProcess
operator|::
name|NormalExit
operator|&&
operator|(
name|expectFail
operator|^
operator|(
name|child
operator|.
name|exitCode
argument_list|()
operator|==
literal|0
operator|)
operator|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QByteArray
modifier|&
name|output
decl|,
name|child
operator|.
name|readAllStandardError
argument_list|()
operator|.
name|split
argument_list|(
literal|'\n'
argument_list|)
control|)
block|{
name|testOutput_
operator|.
name|append
argument_list|(
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|output
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|output
operator|.
name|startsWith
argument_list|(
literal|"Project MESSAGE: FAILED"
argument_list|)
condition|)
name|ok
operator|=
literal|false
expr_stmt|;
block|}
return|return
name|ok
condition|?
literal|true
else|:
name|errorOut
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setBaseCommands
name|void
name|TestCompiler
operator|::
name|setBaseCommands
parameter_list|(
name|QString
name|makeCmd
parameter_list|,
name|QString
name|qmakeCmd
parameter_list|)
block|{
name|makeCmd_
operator|=
name|makeCmd
expr_stmt|;
name|qmakeCmd_
operator|=
name|qmakeCmd
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resetArguments
name|void
name|TestCompiler
operator|::
name|resetArguments
parameter_list|()
block|{
name|makeArgs_
operator|.
name|clear
argument_list|()
expr_stmt|;
name|qmakeArgs_
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setArguments
name|void
name|TestCompiler
operator|::
name|setArguments
parameter_list|(
name|QString
name|makeArgs
parameter_list|,
name|QString
name|qmakeArgs
parameter_list|)
block|{
name|makeArgs_
operator|=
name|makeArgs
expr_stmt|;
name|qmakeArgs_
operator|=
name|qmakeArgs
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resetEnvironment
name|void
name|TestCompiler
operator|::
name|resetEnvironment
parameter_list|()
block|{
name|environment_
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addToEnvironment
name|void
name|TestCompiler
operator|::
name|addToEnvironment
parameter_list|(
name|QString
name|varAssignment
parameter_list|)
block|{
name|environment_
operator|.
name|push_back
argument_list|(
name|varAssignment
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|makeClean
name|bool
name|TestCompiler
operator|::
name|makeClean
parameter_list|(
specifier|const
name|QString
modifier|&
name|workPath
parameter_list|)
block|{
name|QDir
name|D
decl_stmt|;
if|if
condition|(
operator|!
name|D
operator|.
name|exists
argument_list|(
name|workPath
argument_list|)
condition|)
block|{
name|testOutput_
operator|.
name|append
argument_list|(
literal|"Directory '"
operator|+
name|workPath
operator|+
literal|"' doesn't exist"
argument_list|)
expr_stmt|;
return|return
name|errorOut
argument_list|()
return|;
block|}
name|D
operator|.
name|setCurrent
argument_list|(
name|workPath
argument_list|)
expr_stmt|;
name|QFileInfo
name|Fi
argument_list|(
name|workPath
operator|+
literal|"/Makefile"
argument_list|)
decl_stmt|;
if|if
condition|(
name|Fi
operator|.
name|exists
argument_list|()
condition|)
comment|// Run make clean
return|return
name|runCommand
argument_list|(
name|makeCmd_
operator|+
literal|" clean"
argument_list|)
return|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|makeDistClean
name|bool
name|TestCompiler
operator|::
name|makeDistClean
parameter_list|(
specifier|const
name|QString
modifier|&
name|workPath
parameter_list|)
block|{
name|QDir
name|D
decl_stmt|;
if|if
condition|(
operator|!
name|D
operator|.
name|exists
argument_list|(
name|workPath
argument_list|)
condition|)
block|{
name|testOutput_
operator|.
name|append
argument_list|(
literal|"Directory '"
operator|+
name|workPath
operator|+
literal|"' doesn't exist"
argument_list|)
expr_stmt|;
return|return
name|errorOut
argument_list|()
return|;
block|}
name|D
operator|.
name|setCurrent
argument_list|(
name|workPath
argument_list|)
expr_stmt|;
name|QFileInfo
name|Fi
argument_list|(
name|workPath
operator|+
literal|"/Makefile"
argument_list|)
decl_stmt|;
if|if
condition|(
name|Fi
operator|.
name|exists
argument_list|()
condition|)
comment|// Run make distclean
return|return
name|runCommand
argument_list|(
name|makeCmd_
operator|+
literal|" distclean"
argument_list|)
return|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|qmake
name|bool
name|TestCompiler
operator|::
name|qmake
parameter_list|(
specifier|const
name|QString
modifier|&
name|workDir
parameter_list|,
specifier|const
name|QString
modifier|&
name|proName
parameter_list|,
specifier|const
name|QString
modifier|&
name|buildDir
parameter_list|)
block|{
name|QDir
name|D
decl_stmt|;
name|D
operator|.
name|setCurrent
argument_list|(
name|workDir
argument_list|)
expr_stmt|;
if|if
condition|(
name|D
operator|.
name|exists
argument_list|(
literal|"Makefile"
argument_list|)
condition|)
name|D
operator|.
name|remove
argument_list|(
literal|"Makefile"
argument_list|)
expr_stmt|;
name|QString
name|projectFile
init|=
name|proName
decl_stmt|;
name|QString
name|makeFile
init|=
name|buildDir
decl_stmt|;
if|if
condition|(
operator|!
name|projectFile
operator|.
name|endsWith
argument_list|(
literal|".pro"
argument_list|)
condition|)
name|projectFile
operator|+=
literal|".pro"
expr_stmt|;
if|if
condition|(
operator|!
name|makeFile
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|makeFile
operator|.
name|endsWith
argument_list|(
literal|'/'
argument_list|)
condition|)
name|makeFile
operator|+=
literal|'/'
expr_stmt|;
name|makeFile
operator|+=
literal|"Makefile"
expr_stmt|;
comment|// Now start qmake and generate the makefile
return|return
name|runCommand
argument_list|(
name|qmakeCmd_
operator|+
literal|" "
operator|+
name|qmakeArgs_
operator|+
literal|" "
operator|+
name|projectFile
operator|+
literal|" -o "
operator|+
name|makeFile
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|make
name|bool
name|TestCompiler
operator|::
name|make
parameter_list|(
specifier|const
name|QString
modifier|&
name|workPath
parameter_list|,
specifier|const
name|QString
modifier|&
name|target
parameter_list|,
name|bool
name|expectFail
parameter_list|)
block|{
name|QDir
name|D
decl_stmt|;
name|D
operator|.
name|setCurrent
argument_list|(
name|workPath
argument_list|)
expr_stmt|;
name|QString
name|cmdline
init|=
name|makeCmd_
operator|+
literal|" "
operator|+
name|makeArgs_
decl_stmt|;
if|if
condition|(
name|cmdline
operator|.
name|contains
argument_list|(
literal|"nmake"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
name|cmdline
operator|.
name|append
argument_list|(
literal|" /NOLOGO"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|target
operator|.
name|isEmpty
argument_list|()
condition|)
name|cmdline
operator|+=
literal|" "
operator|+
name|target
expr_stmt|;
return|return
name|runCommand
argument_list|(
name|cmdline
argument_list|,
name|expectFail
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|exists
name|bool
name|TestCompiler
operator|::
name|exists
parameter_list|(
specifier|const
name|QString
modifier|&
name|destDir
parameter_list|,
specifier|const
name|QString
modifier|&
name|exeName
parameter_list|,
name|BuildType
name|buildType
parameter_list|,
specifier|const
name|QString
modifier|&
name|version
parameter_list|)
block|{
name|QFileInfo
name|f
argument_list|(
name|destDir
operator|+
literal|"/"
operator|+
name|targetName
argument_list|(
name|buildType
argument_list|,
name|exeName
argument_list|,
name|version
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|f
operator|.
name|exists
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|removeMakefile
name|bool
name|TestCompiler
operator|::
name|removeMakefile
parameter_list|(
specifier|const
name|QString
modifier|&
name|workPath
parameter_list|)
block|{
name|QDir
name|D
decl_stmt|;
name|D
operator|.
name|setCurrent
argument_list|(
name|workPath
argument_list|)
expr_stmt|;
if|if
condition|(
name|D
operator|.
name|exists
argument_list|(
literal|"Makefile"
argument_list|)
condition|)
return|return
name|D
operator|.
name|remove
argument_list|(
literal|"Makefile"
argument_list|)
return|;
else|else
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|commandOutput
name|QString
name|TestCompiler
operator|::
name|commandOutput
parameter_list|()
specifier|const
block|{
ifndef|#
directive|ifndef
name|Q_OS_WIN
return|return
name|testOutput_
operator|.
name|join
argument_list|(
literal|"\n"
argument_list|)
return|;
else|#
directive|else
return|return
name|testOutput_
operator|.
name|join
argument_list|(
literal|"\r\n"
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|clearCommandOutput
name|void
name|TestCompiler
operator|::
name|clearCommandOutput
parameter_list|()
block|{
name|testOutput_
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
