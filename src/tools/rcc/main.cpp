begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<rcc.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
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
file|<qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<qatomic.h>
end_include
begin_include
include|#
directive|include
file|<qglobal.h>
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
DECL|function|dumpRecursive
name|void
name|dumpRecursive
parameter_list|(
specifier|const
name|QDir
modifier|&
name|dir
parameter_list|,
name|QTextStream
modifier|&
name|out
parameter_list|)
block|{
name|QFileInfoList
name|entries
init|=
name|dir
operator|.
name|entryInfoList
argument_list|(
name|QDir
operator|::
name|Files
operator||
name|QDir
operator|::
name|Dirs
operator||
name|QDir
operator|::
name|NoDotAndDotDot
operator||
name|QDir
operator|::
name|NoSymLinks
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QFileInfo
modifier|&
name|entry
decl|,
name|entries
control|)
block|{
if|if
condition|(
name|entry
operator|.
name|isDir
argument_list|()
condition|)
block|{
name|dumpRecursive
argument_list|(
name|entry
operator|.
name|filePath
argument_list|()
argument_list|,
name|out
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|out
operator|<<
name|QLatin1String
argument_list|(
literal|"<file>"
argument_list|)
operator|<<
name|entry
operator|.
name|filePath
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"</file>\n"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|createProject
name|int
name|createProject
parameter_list|(
specifier|const
name|QString
modifier|&
name|outFileName
parameter_list|)
block|{
name|QDir
name|currentDir
init|=
name|QDir
operator|::
name|current
argument_list|()
decl_stmt|;
name|QString
name|currentDirName
init|=
name|currentDir
operator|.
name|dirName
argument_list|()
decl_stmt|;
if|if
condition|(
name|currentDirName
operator|.
name|isEmpty
argument_list|()
condition|)
name|currentDirName
operator|=
name|QLatin1String
argument_list|(
literal|"root"
argument_list|)
expr_stmt|;
name|QFile
name|file
decl_stmt|;
name|bool
name|isOk
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|outFileName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|isOk
operator|=
name|file
operator|.
name|open
argument_list|(
name|stdout
argument_list|,
name|QFile
operator|::
name|WriteOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|file
operator|.
name|setFileName
argument_list|(
name|outFileName
argument_list|)
expr_stmt|;
name|isOk
operator|=
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|WriteOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|isOk
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Unable to open %s: %s\n"
argument_list|,
name|outFileName
operator|.
name|isEmpty
argument_list|()
condition|?
name|qPrintable
argument_list|(
name|outFileName
argument_list|)
else|:
literal|"standard output"
argument_list|,
name|qPrintable
argument_list|(
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|QTextStream
name|out
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|out
operator|<<
name|QLatin1String
argument_list|(
literal|"<!DOCTYPE RCC><RCC version=\"1.0\">\n"
literal|"<qresource>\n"
argument_list|)
expr_stmt|;
comment|// use "." as dir to get relative file pathes
name|dumpRecursive
argument_list|(
name|QDir
argument_list|(
name|QLatin1String
argument_list|(
literal|"."
argument_list|)
argument_list|)
argument_list|,
name|out
argument_list|)
expr_stmt|;
name|out
operator|<<
name|QLatin1String
argument_list|(
literal|"</qresource>\n"
literal|"</RCC>\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|runRcc
name|int
name|runRcc
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
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
comment|// Note that rcc isn't translated.
comment|// If you use this code as an example for a translated app, make sure to translate the strings.
name|QCommandLineParser
name|parser
decl_stmt|;
name|parser
operator|.
name|setSingleDashWordOptionMode
argument_list|(
name|QCommandLineParser
operator|::
name|ParseAsLongOptions
argument_list|)
expr_stmt|;
name|parser
operator|.
name|setApplicationDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Qt Resource Compiler version %1"
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
name|QStringList
argument_list|()
operator|<<
name|QStringLiteral
argument_list|(
literal|"o"
argument_list|)
operator|<<
name|QStringLiteral
argument_list|(
literal|"output"
argument_list|)
argument_list|)
decl_stmt|;
name|outputOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Write output to<file> rather than stdout."
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
name|tempOption
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|QStringLiteral
argument_list|(
literal|"t"
argument_list|)
operator|<<
name|QStringLiteral
argument_list|(
literal|"temp"
argument_list|)
argument_list|)
decl_stmt|;
name|tempOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Use temporary<file> for big resources."
argument_list|)
argument_list|)
expr_stmt|;
name|tempOption
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
name|tempOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|nameOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"name"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Create an external initialization function with<name>."
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"name"
argument_list|)
argument_list|)
decl_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|nameOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|rootOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"root"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Prefix resource access path with root path."
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"path"
argument_list|)
argument_list|)
decl_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|rootOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|compressOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"compress"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Compress input files by<level>."
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"level"
argument_list|)
argument_list|)
decl_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|compressOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|nocompressOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"no-compress"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Disable all compression."
argument_list|)
argument_list|)
decl_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|nocompressOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|thresholdOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"threshold"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Threshold to consider compressing files."
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"level"
argument_list|)
argument_list|)
decl_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|thresholdOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|binaryOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"binary"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Output a binary file for use as a dynamic resource."
argument_list|)
argument_list|)
decl_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|binaryOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|passOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"pass"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Pass number for big resources"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"number"
argument_list|)
argument_list|)
decl_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|passOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|namespaceOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"namespace"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Turn off namespace macros."
argument_list|)
argument_list|)
decl_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|namespaceOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|verboseOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"verbose"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Enable verbose mode."
argument_list|)
argument_list|)
decl_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|verboseOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|listOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"list"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Only list .qrc file entries, do not generate code."
argument_list|)
argument_list|)
decl_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|listOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|projectOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"project"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Output a resource file containing all files from the current directory."
argument_list|)
argument_list|)
decl_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|projectOption
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addPositionalArgument
argument_list|(
name|QStringLiteral
argument_list|(
literal|"inputs"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Input files (*.qrc)."
argument_list|)
argument_list|)
expr_stmt|;
comment|//parse options
name|parser
operator|.
name|process
argument_list|(
name|app
argument_list|)
expr_stmt|;
name|QString
name|errorMsg
decl_stmt|;
name|RCCResourceLibrary
name|library
decl_stmt|;
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|nameOption
argument_list|)
condition|)
name|library
operator|.
name|setInitName
argument_list|(
name|parser
operator|.
name|value
argument_list|(
name|nameOption
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|rootOption
argument_list|)
condition|)
block|{
name|library
operator|.
name|setResourceRoot
argument_list|(
name|QDir
operator|::
name|cleanPath
argument_list|(
name|parser
operator|.
name|value
argument_list|(
name|rootOption
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|library
operator|.
name|resourceRoot
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|||
name|library
operator|.
name|resourceRoot
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|!=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
condition|)
name|errorMsg
operator|=
name|QLatin1String
argument_list|(
literal|"Root must start with a /"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|compressOption
argument_list|)
condition|)
name|library
operator|.
name|setCompressLevel
argument_list|(
name|parser
operator|.
name|value
argument_list|(
name|compressOption
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|nocompressOption
argument_list|)
condition|)
name|library
operator|.
name|setCompressLevel
argument_list|(
operator|-
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|thresholdOption
argument_list|)
condition|)
name|library
operator|.
name|setCompressThreshold
argument_list|(
name|parser
operator|.
name|value
argument_list|(
name|thresholdOption
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|binaryOption
argument_list|)
condition|)
name|library
operator|.
name|setFormat
argument_list|(
name|RCCResourceLibrary
operator|::
name|Binary
argument_list|)
expr_stmt|;
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|passOption
argument_list|)
condition|)
block|{
if|if
condition|(
name|parser
operator|.
name|value
argument_list|(
name|passOption
argument_list|)
operator|==
name|QStringLiteral
argument_list|(
literal|"1"
argument_list|)
condition|)
name|library
operator|.
name|setFormat
argument_list|(
name|RCCResourceLibrary
operator|::
name|Pass1
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|parser
operator|.
name|value
argument_list|(
name|passOption
argument_list|)
operator|==
name|QStringLiteral
argument_list|(
literal|"2"
argument_list|)
condition|)
name|library
operator|.
name|setFormat
argument_list|(
name|RCCResourceLibrary
operator|::
name|Pass2
argument_list|)
expr_stmt|;
else|else
name|errorMsg
operator|=
name|QLatin1String
argument_list|(
literal|"Pass number must be 1 or 2"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|namespaceOption
argument_list|)
condition|)
name|library
operator|.
name|setUseNameSpace
argument_list|(
operator|!
name|library
operator|.
name|useNameSpace
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|verboseOption
argument_list|)
condition|)
name|library
operator|.
name|setVerbose
argument_list|(
literal|true
argument_list|)
expr_stmt|;
specifier|const
name|bool
name|list
init|=
name|parser
operator|.
name|isSet
argument_list|(
name|listOption
argument_list|)
decl_stmt|;
specifier|const
name|bool
name|projectRequested
init|=
name|parser
operator|.
name|isSet
argument_list|(
name|projectOption
argument_list|)
decl_stmt|;
specifier|const
name|QStringList
name|filenamesIn
init|=
name|parser
operator|.
name|positionalArguments
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|file
decl|,
name|filenamesIn
control|)
block|{
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|file
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: File does not exist '%s'"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|,
name|qPrintable
argument_list|(
name|file
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
block|}
name|QString
name|outFilename
init|=
name|parser
operator|.
name|value
argument_list|(
name|outputOption
argument_list|)
decl_stmt|;
name|QString
name|tempFilename
init|=
name|parser
operator|.
name|value
argument_list|(
name|tempOption
argument_list|)
decl_stmt|;
if|if
condition|(
name|projectRequested
condition|)
block|{
return|return
name|createProject
argument_list|(
name|outFilename
argument_list|)
return|;
block|}
if|if
condition|(
name|filenamesIn
operator|.
name|isEmpty
argument_list|()
condition|)
name|errorMsg
operator|=
name|QStringLiteral
argument_list|(
literal|"No input files specified."
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|errorMsg
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|,
name|qPrintable
argument_list|(
name|errorMsg
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
return|return
literal|1
return|;
block|}
name|QFile
name|errorDevice
decl_stmt|;
name|errorDevice
operator|.
name|open
argument_list|(
name|stderr
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
expr_stmt|;
if|if
condition|(
name|library
operator|.
name|verbose
argument_list|()
condition|)
name|errorDevice
operator|.
name|write
argument_list|(
literal|"Qt resource compiler\n"
argument_list|)
expr_stmt|;
name|library
operator|.
name|setInputFiles
argument_list|(
name|filenamesIn
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|library
operator|.
name|readFiles
argument_list|(
name|list
argument_list|,
name|errorDevice
argument_list|)
condition|)
return|return
literal|1
return|;
name|QFile
name|out
decl_stmt|;
comment|// open output
name|QIODevice
operator|::
name|OpenMode
name|mode
init|=
name|QIODevice
operator|::
name|NotOpen
decl_stmt|;
switch|switch
condition|(
name|library
operator|.
name|format
argument_list|()
condition|)
block|{
case|case
name|RCCResourceLibrary
operator|::
name|C_Code
case|:
case|case
name|RCCResourceLibrary
operator|::
name|Pass1
case|:
name|mode
operator|=
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Text
expr_stmt|;
break|break;
case|case
name|RCCResourceLibrary
operator|::
name|Pass2
case|:
case|case
name|RCCResourceLibrary
operator|::
name|Binary
case|:
name|mode
operator|=
name|QIODevice
operator|::
name|WriteOnly
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|outFilename
operator|.
name|isEmpty
argument_list|()
operator|||
name|outFilename
operator|==
name|QLatin1String
argument_list|(
literal|"-"
argument_list|)
condition|)
block|{
comment|// using this overload close() only flushes.
name|out
operator|.
name|open
argument_list|(
name|stdout
argument_list|,
name|mode
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|out
operator|.
name|setFileName
argument_list|(
name|outFilename
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|out
operator|.
name|open
argument_list|(
name|mode
argument_list|)
condition|)
block|{
specifier|const
name|QString
name|msg
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"Unable to open %1 for writing: %2\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|outFilename
argument_list|)
operator|.
name|arg
argument_list|(
name|out
operator|.
name|errorString
argument_list|()
argument_list|)
decl_stmt|;
name|errorDevice
operator|.
name|write
argument_list|(
name|msg
operator|.
name|toUtf8
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
block|}
comment|// do the task
if|if
condition|(
name|list
condition|)
block|{
specifier|const
name|QStringList
name|data
init|=
name|library
operator|.
name|dataFiles
argument_list|()
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
name|data
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|out
operator|.
name|write
argument_list|(
name|qPrintable
argument_list|(
name|QDir
operator|::
name|cleanPath
argument_list|(
name|data
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|out
operator|.
name|write
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
name|QFile
name|temp
decl_stmt|;
if|if
condition|(
operator|!
name|tempFilename
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|temp
operator|.
name|setFileName
argument_list|(
name|tempFilename
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|temp
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
specifier|const
name|QString
name|msg
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"Unable to open temporary file %1 for reading: %2\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|outFilename
argument_list|)
operator|.
name|arg
argument_list|(
name|out
operator|.
name|errorString
argument_list|()
argument_list|)
decl_stmt|;
name|errorDevice
operator|.
name|write
argument_list|(
name|msg
operator|.
name|toUtf8
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
block|}
name|bool
name|success
init|=
name|library
operator|.
name|output
argument_list|(
name|out
argument_list|,
name|temp
argument_list|,
name|errorDevice
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|success
condition|)
block|{
comment|// erase the output file if we failed
name|out
operator|.
name|remove
argument_list|()
expr_stmt|;
return|return
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_decl_stmt
name|Q_CORE_EXPORT
specifier|extern
name|QBasicAtomicInt
name|qt_qhash_seed
decl_stmt|;
end_decl_stmt
begin_comment
comment|// from qhash.cpp
end_comment
begin_function
name|QT_END_NAMESPACE
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
comment|// rcc uses a QHash to store files in the resource system.
comment|// we must force a certain hash order when testing or tst_rcc will fail, see QTBUG-25078
if|if
condition|(
operator|!
name|qEnvironmentVariableIsEmpty
argument_list|(
literal|"QT_RCC_TEST"
argument_list|)
operator|&&
operator|!
name|qt_qhash_seed
operator|.
name|testAndSetRelaxed
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"Cannot force QHash seed for testing as requested"
argument_list|)
expr_stmt|;
return|return
name|QT_PREPEND_NAMESPACE
argument_list|(
name|runRcc
argument_list|)
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
return|;
block|}
end_function
end_unit
