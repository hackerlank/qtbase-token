begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"preprocessor.h"
end_include
begin_include
include|#
directive|include
file|"moc.h"
end_include
begin_include
include|#
directive|include
file|"outputrevision.h"
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<ctype.h>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qcommandlineoption.h>
end_include
begin_include
include|#
directive|include
file|<qcommandlineparser.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*     This function looks at two file names and returns the name of the     infile with a path relative to outfile.      Examples:          /tmp/abc, /tmp/bcd -> abc         xyz/a/bc, xyz/b/ac -> ../a/bc         /tmp/abc, xyz/klm -> /tmp/abc  */
DECL|function|combinePath
specifier|static
name|QByteArray
name|combinePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|infile
parameter_list|,
specifier|const
name|QString
modifier|&
name|outfile
parameter_list|)
block|{
name|QFileInfo
name|inFileInfo
argument_list|(
name|QDir
operator|::
name|current
argument_list|()
argument_list|,
name|infile
argument_list|)
decl_stmt|;
name|QFileInfo
name|outFileInfo
argument_list|(
name|QDir
operator|::
name|current
argument_list|()
argument_list|,
name|outfile
argument_list|)
decl_stmt|;
specifier|const
name|QByteArray
name|relativePath
init|=
name|QFile
operator|::
name|encodeName
argument_list|(
name|outFileInfo
operator|.
name|dir
argument_list|()
operator|.
name|relativeFilePath
argument_list|(
name|inFileInfo
operator|.
name|filePath
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
comment|// It's a system limitation.
comment|// It depends on the Win API function which is used by the program to open files.
comment|// cl apparently uses the functions that have the MAX_PATH limitation.
if|if
condition|(
name|outFileInfo
operator|.
name|dir
argument_list|()
operator|.
name|absolutePath
argument_list|()
operator|.
name|length
argument_list|()
operator|+
name|relativePath
operator|.
name|length
argument_list|()
operator|+
literal|1
operator|>=
literal|260
condition|)
return|return
name|QFile
operator|::
name|encodeName
argument_list|(
name|inFileInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
return|;
endif|#
directive|endif
return|return
name|relativePath
return|;
block|}
end_function
begin_function
DECL|function|error
name|void
name|error
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
init|=
literal|"Invalid argument"
parameter_list|)
block|{
if|if
condition|(
name|msg
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"moc: %s\n"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasNext
specifier|static
specifier|inline
name|bool
name|hasNext
parameter_list|(
specifier|const
name|Symbols
modifier|&
name|symbols
parameter_list|,
name|int
name|i
parameter_list|)
block|{
return|return
operator|(
name|i
operator|<
name|symbols
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
end_function
begin_function
DECL|function|next
specifier|static
specifier|inline
specifier|const
name|Symbol
modifier|&
name|next
parameter_list|(
specifier|const
name|Symbols
modifier|&
name|symbols
parameter_list|,
name|int
modifier|&
name|i
parameter_list|)
block|{
return|return
name|symbols
operator|.
name|at
argument_list|(
name|i
operator|++
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|composePreprocessorOutput
name|QByteArray
name|composePreprocessorOutput
parameter_list|(
specifier|const
name|Symbols
modifier|&
name|symbols
parameter_list|)
block|{
name|QByteArray
name|output
decl_stmt|;
name|int
name|lineNum
init|=
literal|1
decl_stmt|;
name|Token
name|last
init|=
name|PP_NOTOKEN
decl_stmt|;
name|Token
name|secondlast
init|=
name|last
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|hasNext
argument_list|(
name|symbols
argument_list|,
name|i
argument_list|)
condition|)
block|{
name|Symbol
name|sym
init|=
name|next
argument_list|(
name|symbols
argument_list|,
name|i
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|sym
operator|.
name|token
condition|)
block|{
case|case
name|PP_NEWLINE
case|:
case|case
name|PP_WHITESPACE
case|:
if|if
condition|(
name|last
operator|!=
name|PP_WHITESPACE
condition|)
block|{
name|secondlast
operator|=
name|last
expr_stmt|;
name|last
operator|=
name|PP_WHITESPACE
expr_stmt|;
name|output
operator|+=
literal|' '
expr_stmt|;
block|}
continue|continue;
case|case
name|PP_STRING_LITERAL
case|:
if|if
condition|(
name|last
operator|==
name|PP_STRING_LITERAL
condition|)
name|output
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|secondlast
operator|==
name|PP_STRING_LITERAL
operator|&&
name|last
operator|==
name|PP_WHITESPACE
condition|)
name|output
operator|.
name|chop
argument_list|(
literal|2
argument_list|)
expr_stmt|;
else|else
break|break;
name|output
operator|+=
name|sym
operator|.
name|lexem
argument_list|()
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|secondlast
operator|=
name|last
expr_stmt|;
name|last
operator|=
name|PP_STRING_LITERAL
expr_stmt|;
continue|continue;
case|case
name|MOC_INCLUDE_BEGIN
case|:
name|lineNum
operator|=
literal|0
expr_stmt|;
continue|continue;
case|case
name|MOC_INCLUDE_END
case|:
name|lineNum
operator|=
name|sym
operator|.
name|lineNum
expr_stmt|;
continue|continue;
default|default:
break|break;
block|}
name|secondlast
operator|=
name|last
expr_stmt|;
name|last
operator|=
name|sym
operator|.
name|token
expr_stmt|;
specifier|const
name|int
name|padding
init|=
name|sym
operator|.
name|lineNum
operator|-
name|lineNum
decl_stmt|;
if|if
condition|(
name|padding
operator|>
literal|0
condition|)
block|{
name|output
operator|.
name|resize
argument_list|(
name|output
operator|.
name|size
argument_list|()
operator|+
name|padding
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|output
operator|.
name|data
argument_list|()
operator|+
name|output
operator|.
name|size
argument_list|()
operator|-
name|padding
argument_list|,
literal|'\n'
argument_list|,
name|padding
argument_list|)
expr_stmt|;
name|lineNum
operator|=
name|sym
operator|.
name|lineNum
expr_stmt|;
block|}
name|output
operator|+=
name|sym
operator|.
name|lexem
argument_list|()
expr_stmt|;
block|}
return|return
name|output
return|;
block|}
end_function
begin_function
DECL|function|argumentsFromCommandLineAndFile
specifier|static
name|QStringList
name|argumentsFromCommandLineAndFile
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|arguments
parameter_list|)
block|{
name|QStringList
name|allArguments
decl_stmt|;
name|allArguments
operator|.
name|reserve
argument_list|(
name|arguments
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|argument
decl|,
name|arguments
control|)
block|{
comment|// "@file" doesn't start with a '-' so we can't use QCommandLineParser for it
if|if
condition|(
name|argument
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'@'
argument_list|)
argument_list|)
condition|)
block|{
name|QString
name|optionsFile
init|=
name|argument
decl_stmt|;
name|optionsFile
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|optionsFile
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|error
argument_list|(
literal|"The @ option requires an input file"
argument_list|)
expr_stmt|;
return|return
name|QStringList
argument_list|()
return|;
block|}
name|QFile
name|f
argument_list|(
name|optionsFile
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
condition|)
block|{
name|error
argument_list|(
literal|"Cannot open options file specified with @"
argument_list|)
expr_stmt|;
return|return
name|QStringList
argument_list|()
return|;
block|}
while|while
condition|(
operator|!
name|f
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QString
name|line
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|f
operator|.
name|readLine
argument_list|()
operator|.
name|trimmed
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|line
operator|.
name|isEmpty
argument_list|()
condition|)
name|allArguments
operator|<<
name|line
expr_stmt|;
block|}
block|}
else|else
block|{
name|allArguments
operator|<<
name|argument
expr_stmt|;
block|}
block|}
return|return
name|allArguments
return|;
block|}
end_function
begin_function
DECL|function|runMoc
name|int
name|runMoc
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QCoreApplication
operator|::
name|setApplicationVersion
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|QT_VERSION_STR
argument_list|)
argument_list|)
expr_stmt|;
name|bool
name|autoInclude
init|=
literal|true
decl_stmt|;
name|bool
name|defaultInclude
init|=
literal|true
decl_stmt|;
name|Preprocessor
name|pp
decl_stmt|;
name|Moc
name|moc
decl_stmt|;
name|pp
operator|.
name|macros
index|[
literal|"Q_MOC_RUN"
index|]
expr_stmt|;
name|pp
operator|.
name|macros
index|[
literal|"__cplusplus"
index|]
expr_stmt|;
comment|// Don't stumble over GCC extensions
name|Macro
name|dummyVariadicFunctionMacro
decl_stmt|;
name|dummyVariadicFunctionMacro
operator|.
name|isFunction
operator|=
literal|true
expr_stmt|;
name|dummyVariadicFunctionMacro
operator|.
name|isVariadic
operator|=
literal|true
expr_stmt|;
name|dummyVariadicFunctionMacro
operator|.
name|arguments
operator|+=
name|Symbol
argument_list|(
literal|0
argument_list|,
name|PP_IDENTIFIER
argument_list|,
literal|"__VA_ARGS__"
argument_list|)
expr_stmt|;
name|pp
operator|.
name|macros
index|[
literal|"__attribute__"
index|]
operator|=
name|dummyVariadicFunctionMacro
expr_stmt|;
name|pp
operator|.
name|macros
index|[
literal|"__declspec"
index|]
operator|=
name|dummyVariadicFunctionMacro
expr_stmt|;
name|QString
name|filename
decl_stmt|;
name|QString
name|output
decl_stmt|;
name|QFile
name|in
decl_stmt|;
name|FILE
modifier|*
name|out
init|=
literal|0
decl_stmt|;
comment|// Note that moc isn't translated.
comment|// If you use this code as an example for a translated app, make sure to translate the strings.
name|QCommandLineParser
name|parser
decl_stmt|;
name|parser
operator|.
name|setApplicationDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Qt Meta Object Compiler version %1 (Qt %2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|mocOutputRevision
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|QT_VERSION_STR
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addHelpOption
argument_list|()
expr_stmt|;
name|parser
operator|.
name|addVersionOption
argument_list|()
expr_stmt|;
name|QCommandLineOption
name|outputOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"o"
argument_list|)
argument_list|)
decl_stmt|;
name|outputOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Write output to file rather than stdout."
argument_list|)
argument_list|)
expr_stmt|;
name|outputOption
operator|.
name|setValueName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"file"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|outputOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|includePathOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"I"
argument_list|)
argument_list|)
decl_stmt|;
name|includePathOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Add dir to the include path for header files."
argument_list|)
argument_list|)
expr_stmt|;
name|includePathOption
operator|.
name|setValueName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"dir"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|includePathOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|macFrameworkOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"F"
argument_list|)
argument_list|)
decl_stmt|;
name|macFrameworkOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Add Mac framework to the include path for header files."
argument_list|)
argument_list|)
expr_stmt|;
name|macFrameworkOption
operator|.
name|setValueName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"framework"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|macFrameworkOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|preprocessOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"E"
argument_list|)
argument_list|)
decl_stmt|;
name|preprocessOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Preprocess only; do not generate meta object code."
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|preprocessOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|defineOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"D"
argument_list|)
argument_list|)
decl_stmt|;
name|defineOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Define macro, with optional definition."
argument_list|)
argument_list|)
expr_stmt|;
name|defineOption
operator|.
name|setValueName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"macro[=def]"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|defineOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|undefineOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"U"
argument_list|)
argument_list|)
decl_stmt|;
name|undefineOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Undefine macro."
argument_list|)
argument_list|)
expr_stmt|;
name|undefineOption
operator|.
name|setValueName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"macro"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|undefineOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|metadataOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"M"
argument_list|)
argument_list|)
decl_stmt|;
name|metadataOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Add key/value pair to plugin meta data"
argument_list|)
argument_list|)
expr_stmt|;
name|metadataOption
operator|.
name|setValueName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"key=value"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|metadataOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|noIncludeOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"i"
argument_list|)
argument_list|)
decl_stmt|;
name|noIncludeOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Do not generate an #include statement."
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|noIncludeOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|pathPrefixOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"p"
argument_list|)
argument_list|)
decl_stmt|;
name|pathPrefixOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Path prefix for included file."
argument_list|)
argument_list|)
expr_stmt|;
name|pathPrefixOption
operator|.
name|setValueName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"path"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|pathPrefixOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|forceIncludeOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"f"
argument_list|)
argument_list|)
decl_stmt|;
name|forceIncludeOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Force #include [optional<file>] (overwrite default)."
argument_list|)
argument_list|)
expr_stmt|;
name|forceIncludeOption
operator|.
name|setValueName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"file"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|forceIncludeOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|prependIncludeOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"b"
argument_list|)
argument_list|)
decl_stmt|;
name|prependIncludeOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Prepend #include<file> (preserve default include)."
argument_list|)
argument_list|)
expr_stmt|;
name|prependIncludeOption
operator|.
name|setValueName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"file"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|prependIncludeOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|noNotesWarningsCompatOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"n"
argument_list|)
argument_list|)
decl_stmt|;
name|noNotesWarningsCompatOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Do not display notes (-nn) or warnings (-nw). Compatibility option."
argument_list|)
argument_list|)
expr_stmt|;
name|noNotesWarningsCompatOption
operator|.
name|setValueName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"which"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|noNotesWarningsCompatOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|noNotesOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"no-notes"
argument_list|)
argument_list|)
decl_stmt|;
name|noNotesOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Do not display notes."
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|noNotesOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|noWarningsOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"no-warnings"
argument_list|)
argument_list|)
decl_stmt|;
name|noWarningsOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Do not display warnings (implies --no-notes)."
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|noWarningsOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|ignoreConflictsOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"ignore-option-clashes"
argument_list|)
argument_list|)
decl_stmt|;
name|ignoreConflictsOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Ignore all options that conflict with compilers, like -pthread conflicting with moc's -p option."
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|ignoreConflictsOption
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addPositionalArgument
argument_list|(
name|QStringLiteral
argument_list|(
literal|"[header-file]"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Header file to read from, otherwise stdin."
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addPositionalArgument
argument_list|(
name|QStringLiteral
argument_list|(
literal|"[@option-file]"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Read additional options from option-file."
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QStringList
name|arguments
init|=
name|argumentsFromCommandLineAndFile
argument_list|(
name|app
operator|.
name|arguments
argument_list|()
argument_list|)
decl_stmt|;
name|parser
operator|.
name|process
argument_list|(
name|arguments
argument_list|)
expr_stmt|;
specifier|const
name|QStringList
name|files
init|=
name|parser
operator|.
name|positionalArguments
argument_list|()
decl_stmt|;
if|if
condition|(
name|files
operator|.
name|count
argument_list|()
operator|>
literal|1
condition|)
block|{
name|error
argument_list|(
name|qPrintable
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Too many input files specified: '"
argument_list|)
operator|+
name|files
operator|.
name|join
argument_list|(
name|QStringLiteral
argument_list|(
literal|"' '"
argument_list|)
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|'\''
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|showHelp
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|files
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|filename
operator|=
name|files
operator|.
name|first
argument_list|()
expr_stmt|;
block|}
specifier|const
name|bool
name|ignoreConflictingOptions
init|=
name|parser
operator|.
name|isSet
argument_list|(
name|ignoreConflictsOption
argument_list|)
decl_stmt|;
name|output
operator|=
name|parser
operator|.
name|value
argument_list|(
name|outputOption
argument_list|)
expr_stmt|;
name|pp
operator|.
name|preprocessOnly
operator|=
name|parser
operator|.
name|isSet
argument_list|(
name|preprocessOption
argument_list|)
expr_stmt|;
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|noIncludeOption
argument_list|)
condition|)
block|{
name|moc
operator|.
name|noInclude
operator|=
literal|true
expr_stmt|;
name|autoInclude
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|ignoreConflictingOptions
condition|)
block|{
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|forceIncludeOption
argument_list|)
condition|)
block|{
name|moc
operator|.
name|noInclude
operator|=
literal|false
expr_stmt|;
name|autoInclude
operator|=
literal|false
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|include
decl|,
name|parser
operator|.
name|values
argument_list|(
name|forceIncludeOption
argument_list|)
control|)
block|{
name|moc
operator|.
name|includeFiles
operator|.
name|append
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|include
argument_list|)
argument_list|)
expr_stmt|;
name|defaultInclude
operator|=
literal|false
expr_stmt|;
block|}
block|}
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|include
decl|,
name|parser
operator|.
name|values
argument_list|(
name|prependIncludeOption
argument_list|)
control|)
name|moc
operator|.
name|includeFiles
operator|.
name|prepend
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|include
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|pathPrefixOption
argument_list|)
condition|)
name|moc
operator|.
name|includePath
operator|=
name|QFile
operator|::
name|encodeName
argument_list|(
name|parser
operator|.
name|value
argument_list|(
name|pathPrefixOption
argument_list|)
argument_list|)
expr_stmt|;
block|}
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|path
decl|,
name|parser
operator|.
name|values
argument_list|(
name|includePathOption
argument_list|)
control|)
name|pp
operator|.
name|includes
operator|+=
name|Preprocessor
operator|::
name|IncludePath
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|path
argument_list|)
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|path
decl|,
name|parser
operator|.
name|values
argument_list|(
name|macFrameworkOption
argument_list|)
control|)
block|{
comment|// minimalistic framework support for the mac
name|Preprocessor
operator|::
name|IncludePath
name|p
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|path
argument_list|)
argument_list|)
decl_stmt|;
name|p
operator|.
name|isFrameworkPath
operator|=
literal|true
expr_stmt|;
name|pp
operator|.
name|includes
operator|+=
name|p
expr_stmt|;
block|}
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|arg
decl|,
name|parser
operator|.
name|values
argument_list|(
name|defineOption
argument_list|)
control|)
block|{
name|QByteArray
name|name
init|=
name|arg
operator|.
name|toLocal8Bit
argument_list|()
decl_stmt|;
name|QByteArray
name|value
argument_list|(
literal|"1"
argument_list|)
decl_stmt|;
name|int
name|eq
init|=
name|name
operator|.
name|indexOf
argument_list|(
literal|'='
argument_list|)
decl_stmt|;
if|if
condition|(
name|eq
operator|>=
literal|0
condition|)
block|{
name|value
operator|=
name|name
operator|.
name|mid
argument_list|(
name|eq
operator|+
literal|1
argument_list|)
expr_stmt|;
name|name
operator|=
name|name
operator|.
name|left
argument_list|(
name|eq
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|error
argument_list|(
literal|"Missing macro name"
argument_list|)
expr_stmt|;
name|parser
operator|.
name|showHelp
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|Macro
name|macro
decl_stmt|;
name|macro
operator|.
name|symbols
operator|=
name|Preprocessor
operator|::
name|tokenize
argument_list|(
name|value
argument_list|,
literal|1
argument_list|,
name|Preprocessor
operator|::
name|TokenizeDefine
argument_list|)
expr_stmt|;
name|macro
operator|.
name|symbols
operator|.
name|removeLast
argument_list|()
expr_stmt|;
comment|// remove the EOF symbol
name|pp
operator|.
name|macros
operator|.
name|insert
argument_list|(
name|name
argument_list|,
name|macro
argument_list|)
expr_stmt|;
block|}
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|arg
decl|,
name|parser
operator|.
name|values
argument_list|(
name|undefineOption
argument_list|)
control|)
block|{
name|QByteArray
name|macro
init|=
name|arg
operator|.
name|toLocal8Bit
argument_list|()
decl_stmt|;
if|if
condition|(
name|macro
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|error
argument_list|(
literal|"Missing macro name"
argument_list|)
expr_stmt|;
name|parser
operator|.
name|showHelp
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|pp
operator|.
name|macros
operator|.
name|remove
argument_list|(
name|macro
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QStringList
name|noNotesCompatValues
init|=
name|parser
operator|.
name|values
argument_list|(
name|noNotesWarningsCompatOption
argument_list|)
decl_stmt|;
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|noNotesOption
argument_list|)
operator|||
name|noNotesCompatValues
operator|.
name|contains
argument_list|(
name|QStringLiteral
argument_list|(
literal|"n"
argument_list|)
argument_list|)
condition|)
name|moc
operator|.
name|displayNotes
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|noWarningsOption
argument_list|)
operator|||
name|noNotesCompatValues
operator|.
name|contains
argument_list|(
name|QStringLiteral
argument_list|(
literal|"w"
argument_list|)
argument_list|)
condition|)
name|moc
operator|.
name|displayWarnings
operator|=
name|moc
operator|.
name|displayNotes
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|autoInclude
condition|)
block|{
name|int
name|spos
init|=
name|filename
operator|.
name|lastIndexOf
argument_list|(
name|QDir
operator|::
name|separator
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|ppos
init|=
name|filename
operator|.
name|lastIndexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
argument_list|)
decl_stmt|;
comment|// spos>= -1&& ppos> spos => ppos>= 0
name|moc
operator|.
name|noInclude
operator|=
operator|(
name|ppos
operator|>
name|spos
operator|&&
name|filename
index|[
name|ppos
operator|+
literal|1
index|]
operator|.
name|toLower
argument_list|()
operator|!=
name|QLatin1Char
argument_list|(
literal|'h'
argument_list|)
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|defaultInclude
condition|)
block|{
if|if
condition|(
name|moc
operator|.
name|includePath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|filename
operator|.
name|size
argument_list|()
condition|)
block|{
if|if
condition|(
name|output
operator|.
name|size
argument_list|()
condition|)
name|moc
operator|.
name|includeFiles
operator|.
name|append
argument_list|(
name|combinePath
argument_list|(
name|filename
argument_list|,
name|output
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|moc
operator|.
name|includeFiles
operator|.
name|append
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|filename
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|moc
operator|.
name|includeFiles
operator|.
name|append
argument_list|(
name|combinePath
argument_list|(
name|filename
argument_list|,
name|filename
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|filename
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|filename
operator|=
name|QStringLiteral
argument_list|(
literal|"standard input"
argument_list|)
expr_stmt|;
name|in
operator|.
name|open
argument_list|(
name|stdin
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|in
operator|.
name|setFileName
argument_list|(
name|filename
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|in
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"moc: %s: No such file\n"
argument_list|,
name|qPrintable
argument_list|(
name|filename
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|moc
operator|.
name|filename
operator|=
name|filename
operator|.
name|toLocal8Bit
argument_list|()
expr_stmt|;
block|}
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|md
decl|,
name|parser
operator|.
name|values
argument_list|(
name|metadataOption
argument_list|)
control|)
block|{
name|int
name|split
init|=
name|md
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'='
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|key
init|=
name|md
operator|.
name|left
argument_list|(
name|split
argument_list|)
decl_stmt|;
name|QString
name|value
init|=
name|md
operator|.
name|mid
argument_list|(
name|split
operator|+
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|split
operator|==
operator|-
literal|1
operator|||
name|key
operator|.
name|isEmpty
argument_list|()
operator|||
name|value
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|error
argument_list|(
literal|"missing key or value for option '-M'"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|key
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
argument_list|)
operator|!=
operator|-
literal|1
condition|)
block|{
comment|// Don't allow keys with '.' for now, since we might need this
comment|// format later for more advanced meta data API
name|error
argument_list|(
literal|"A key cannot contain the letter '.' for option '-M'"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QJsonArray
name|array
init|=
name|moc
operator|.
name|metaArgs
operator|.
name|value
argument_list|(
name|key
argument_list|)
decl_stmt|;
name|array
operator|.
name|append
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|moc
operator|.
name|metaArgs
operator|.
name|insert
argument_list|(
name|key
argument_list|,
name|array
argument_list|)
expr_stmt|;
block|}
block|}
name|moc
operator|.
name|currentFilenames
operator|.
name|push
argument_list|(
name|filename
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
expr_stmt|;
name|moc
operator|.
name|includes
operator|=
name|pp
operator|.
name|includes
expr_stmt|;
comment|// 1. preprocess
name|moc
operator|.
name|symbols
operator|=
name|pp
operator|.
name|preprocessed
argument_list|(
name|moc
operator|.
name|filename
argument_list|,
operator|&
name|in
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|pp
operator|.
name|preprocessOnly
condition|)
block|{
comment|// 2. parse
name|moc
operator|.
name|parse
argument_list|()
expr_stmt|;
block|}
comment|// 3. and output meta object code
if|if
condition|(
name|output
operator|.
name|size
argument_list|()
condition|)
block|{
comment|// output file specified
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|1400
if|if
condition|(
name|fopen_s
argument_list|(
operator|&
name|out
argument_list|,
name|QFile
operator|::
name|encodeName
argument_list|(
name|output
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|,
literal|"w"
argument_list|)
condition|)
else|#
directive|else
name|out
operator|=
name|fopen
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|output
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
comment|// create output file
if|if
condition|(
operator|!
name|out
condition|)
endif|#
directive|endif
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"moc: Cannot create %s\n"
argument_list|,
name|QFile
operator|::
name|encodeName
argument_list|(
name|output
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
block|}
else|else
block|{
comment|// use stdout
name|out
operator|=
name|stdout
expr_stmt|;
block|}
if|if
condition|(
name|pp
operator|.
name|preprocessOnly
condition|)
block|{
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"%s\n"
argument_list|,
name|composePreprocessorOutput
argument_list|(
name|moc
operator|.
name|symbols
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|moc
operator|.
name|classList
operator|.
name|isEmpty
argument_list|()
condition|)
name|moc
operator|.
name|note
argument_list|(
literal|"No relevant classes found. No output generated."
argument_list|)
expr_stmt|;
else|else
name|moc
operator|.
name|generate
argument_list|(
name|out
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|output
operator|.
name|size
argument_list|()
condition|)
name|fclose
argument_list|(
name|out
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
name|QT_END_NAMESPACE
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|_argc
parameter_list|,
name|char
modifier|*
modifier|*
name|_argv
parameter_list|)
block|{
return|return
name|QT_PREPEND_NAMESPACE
argument_list|(
name|runMoc
argument_list|)
argument_list|(
name|_argc
argument_list|,
name|_argv
argument_list|)
return|;
block|}
end_function
end_unit
