begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"datagenerator.h"
end_include
begin_include
include|#
directive|include
file|"qengines.h"
end_include
begin_include
include|#
directive|include
file|"xmlgenerator.h"
end_include
begin_include
include|#
directive|include
file|<QDateTime>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QFileInfo>
end_include
begin_include
include|#
directive|include
file|<QSvgRenderer>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QProcess>
end_include
begin_include
include|#
directive|include
file|<QSettings>
end_include
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_include
include|#
directive|include
file|<iostream>
end_include
begin_define
DECL|macro|W3C_SVG_BASE
define|#
directive|define
name|W3C_SVG_BASE
value|"http://www.w3.org/Graphics/SVG/Test/20030813/png/"
end_define
begin_function
DECL|function|createW3CReference
specifier|static
name|QString
name|createW3CReference
parameter_list|(
specifier|const
name|QString
modifier|&
name|refUrl
parameter_list|,
specifier|const
name|QString
modifier|&
name|filename
parameter_list|)
block|{
name|QString
name|base
argument_list|(
name|refUrl
argument_list|)
decl_stmt|;
name|QString
name|pngFile
init|=
name|filename
decl_stmt|;
name|pngFile
operator|.
name|replace
argument_list|(
literal|".svg"
argument_list|,
literal|".png"
argument_list|)
expr_stmt|;
name|base
operator|+=
literal|"full-"
expr_stmt|;
name|base
operator|+=
name|pngFile
expr_stmt|;
return|return
name|base
return|;
block|}
end_function
begin_function
DECL|function|createOutFilename
specifier|static
name|QString
name|createOutFilename
parameter_list|(
specifier|const
name|QString
modifier|&
name|baseDir
parameter_list|,
specifier|const
name|QString
modifier|&
name|filename
parameter_list|,
name|QEngine
modifier|*
name|engine
parameter_list|)
block|{
name|QString
name|outFile
init|=
name|filename
decl_stmt|;
if|if
condition|(
name|outFile
operator|.
name|endsWith
argument_list|(
literal|".svgz"
argument_list|)
condition|)
name|outFile
operator|.
name|replace
argument_list|(
literal|".svgz"
argument_list|,
literal|".png"
argument_list|)
expr_stmt|;
else|else
name|outFile
operator|.
name|replace
argument_list|(
literal|".svg"
argument_list|,
literal|".png"
argument_list|)
expr_stmt|;
name|outFile
operator|.
name|replace
argument_list|(
literal|".qps"
argument_list|,
literal|".qps.png"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|baseDir
operator|.
name|isEmpty
argument_list|()
condition|)
name|outFile
operator|=
name|QString
argument_list|(
literal|"%1/%2/%3"
argument_list|)
operator|.
name|arg
argument_list|(
name|baseDir
argument_list|)
operator|.
name|arg
argument_list|(
name|engine
operator|->
name|name
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|outFile
argument_list|)
expr_stmt|;
else|else
name|outFile
operator|=
name|QString
argument_list|(
literal|"%1/%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|engine
operator|->
name|name
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|outFile
argument_list|)
expr_stmt|;
return|return
name|outFile
return|;
block|}
end_function
begin_function
DECL|function|usage
specifier|static
name|void
name|usage
parameter_list|(
specifier|const
name|char
modifier|*
name|progname
parameter_list|)
block|{
name|std
operator|::
name|cerr
operator|<<
literal|"Couldn't find 'framework.ini' "
operator|<<
literal|"file and no suite has been specified."
operator|<<
name|std
operator|::
name|endl
expr_stmt|;
name|std
operator|::
name|cerr
operator|<<
literal|"Usage: "
operator|<<
name|progname
operator|<<
literal|"\n"
operator|<<
literal|"\t-framework<framework.ini>\n"
operator|<<
literal|"\t-engine<engine name>|onscreen|printing\n"
operator|<<
literal|"\t-suite<suite name>\n"
operator|<<
literal|"\t-testcase<file.svg>\n"
operator|<<
literal|"\t-file</path/to/file.svg>\n"
operator|<<
literal|"\t-size<width,height>\n"
operator|<<
literal|"\t-fill<color>\n"
operator|<<
literal|"\t-output<dirname>\n"
operator|<<
name|std
operator|::
name|endl
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|DataGenerator
name|DataGenerator
operator|::
name|DataGenerator
parameter_list|()
member_init_list|:
name|iterations
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|size
argument_list|(
literal|480
argument_list|,
literal|360
argument_list|)
member_init_list|,
name|fillColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
block|{
name|settings
operator|.
name|load
argument_list|(
name|QString
argument_list|(
literal|"framework.ini"
argument_list|)
argument_list|)
expr_stmt|;
name|renderer
operator|=
operator|new
name|QSvgRenderer
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~DataGenerator
name|DataGenerator
operator|::
name|~
name|DataGenerator
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|run
name|void
name|DataGenerator
operator|::
name|run
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
if|if
condition|(
operator|!
name|processArguments
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
condition|)
return|return;
if|if
condition|(
operator|!
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|testGivenFile
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|settings
operator|.
name|isValid
argument_list|()
operator|&&
name|suiteName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|usage
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return;
block|}
name|prepareDirs
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|settings
operator|.
name|isValid
argument_list|()
condition|)
block|{
comment|//only suite specified
name|XMLGenerator
name|generator
argument_list|(
name|outputDirName
argument_list|)
decl_stmt|;
name|testSuite
argument_list|(
name|generator
argument_list|,
name|suiteName
argument_list|,
name|QString
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
name|XMLGenerator
name|generator
argument_list|(
name|outputDirName
argument_list|)
decl_stmt|;
name|QStringList
name|tests
init|=
name|settings
operator|.
name|suites
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"tests = "
operator|<<
name|tests
expr_stmt|;
foreach|foreach
control|(
name|QString
name|test
decl|,
name|tests
control|)
block|{
if|if
condition|(
operator|!
name|suiteName
operator|.
name|isEmpty
argument_list|()
operator|&&
name|test
operator|!=
name|suiteName
condition|)
continue|continue;
name|qDebug
argument_list|()
operator|<<
literal|"testing "
operator|<<
name|test
expr_stmt|;
name|settings
operator|.
name|settings
argument_list|()
operator|->
name|beginGroup
argument_list|(
name|test
argument_list|)
expr_stmt|;
name|QString
name|dirName
init|=
name|settings
operator|.
name|settings
argument_list|()
operator|->
name|value
argument_list|(
literal|"dir"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QString
name|refUrl
init|=
name|settings
operator|.
name|settings
argument_list|()
operator|->
name|value
argument_list|(
literal|"reference"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QDir
name|dir
argument_list|(
name|dirName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|dir
operator|.
name|isAbsolute
argument_list|()
operator|&&
operator|!
name|dir
operator|.
name|exists
argument_list|()
condition|)
name|dir
operator|=
name|QDir
argument_list|(
name|QString
argument_list|(
literal|"%1/%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|baseDataDir
argument_list|)
operator|.
name|arg
argument_list|(
name|dirName
argument_list|)
argument_list|)
expr_stmt|;
name|testSuite
argument_list|(
name|generator
argument_list|,
name|test
argument_list|,
name|dir
operator|.
name|absolutePath
argument_list|()
argument_list|,
name|refUrl
argument_list|)
expr_stmt|;
name|settings
operator|.
name|settings
argument_list|()
operator|->
name|endGroup
argument_list|()
expr_stmt|;
block|}
name|generator
operator|.
name|generateOutput
argument_list|(
name|outputDirName
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testEngines
name|void
name|DataGenerator
operator|::
name|testEngines
parameter_list|(
name|XMLGenerator
modifier|&
name|generator
parameter_list|,
specifier|const
name|QString
modifier|&
name|file
parameter_list|,
specifier|const
name|QString
modifier|&
name|refUrl
parameter_list|)
block|{
name|QFileInfo
name|fileInfo
argument_list|(
name|file
argument_list|)
decl_stmt|;
name|generator
operator|.
name|startTestcase
argument_list|(
name|file
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|refUrl
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QString
name|ref
init|=
name|createW3CReference
argument_list|(
name|refUrl
argument_list|,
name|fileInfo
operator|.
name|fileName
argument_list|()
argument_list|)
decl_stmt|;
name|generator
operator|.
name|addImage
argument_list|(
literal|"Reference"
argument_list|,
name|ref
argument_list|,
name|XMLData
argument_list|()
argument_list|,
name|Reference
argument_list|)
expr_stmt|;
block|}
comment|//bool isQpsScript = file.endsWith(".qps");
name|bool
name|isSvgFile
init|=
name|file
operator|.
name|endsWith
argument_list|(
literal|".svg"
argument_list|)
operator|||
name|file
operator|.
name|endsWith
argument_list|(
literal|".svgz"
argument_list|)
decl_stmt|;
if|if
condition|(
name|isSvgFile
condition|)
block|{
name|QDir
name|oldDir
init|=
name|QDir
operator|::
name|current
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|baseDataDir
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QDir
operator|::
name|setCurrent
argument_list|(
name|baseDataDir
argument_list|)
expr_stmt|;
block|}
name|renderer
operator|->
name|load
argument_list|(
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|baseDataDir
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QDir
operator|::
name|setCurrent
argument_list|(
name|oldDir
operator|.
name|absolutePath
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|renderer
operator|->
name|isValid
argument_list|()
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Error while processing "
operator|<<
name|file
expr_stmt|;
return|return;
block|}
block|}
name|QList
argument_list|<
name|QEngine
modifier|*
argument_list|>
name|engines
init|=
name|QtEngines
operator|::
name|self
argument_list|()
operator|->
name|engines
argument_list|()
decl_stmt|;
name|testGivenEngines
argument_list|(
name|engines
argument_list|,
name|fileInfo
argument_list|,
name|file
argument_list|,
name|generator
argument_list|,
name|Normal
argument_list|)
expr_stmt|;
name|engines
operator|=
name|QtEngines
operator|::
name|self
argument_list|()
operator|->
name|foreignEngines
argument_list|()
expr_stmt|;
name|testGivenEngines
argument_list|(
name|engines
argument_list|,
name|fileInfo
argument_list|,
name|file
argument_list|,
name|generator
argument_list|,
name|Foreign
argument_list|)
expr_stmt|;
name|generator
operator|.
name|endTestcase
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|prepareDirs
name|void
name|DataGenerator
operator|::
name|prepareDirs
parameter_list|()
block|{
name|QList
argument_list|<
name|QEngine
modifier|*
argument_list|>
name|engines
init|=
name|QtEngines
operator|::
name|self
argument_list|()
operator|->
name|engines
argument_list|()
decl_stmt|;
name|QDir
name|outDirs
decl_stmt|;
foreach|foreach
control|(
name|QEngine
modifier|*
name|engine
decl|,
name|engines
control|)
block|{
if|if
condition|(
operator|!
name|wantedEngine
argument_list|(
name|engine
operator|->
name|name
argument_list|()
argument_list|)
condition|)
continue|continue;
name|QString
name|dirName
init|=
name|engine
operator|->
name|name
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|outputDirName
operator|.
name|isEmpty
argument_list|()
condition|)
name|dirName
operator|=
name|QString
argument_list|(
literal|"%1/%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|outputDirName
argument_list|)
operator|.
name|arg
argument_list|(
name|dirName
argument_list|)
expr_stmt|;
name|outDirs
operator|.
name|mkpath
argument_list|(
name|dirName
argument_list|)
expr_stmt|;
block|}
name|engines
operator|=
name|QtEngines
operator|::
name|self
argument_list|()
operator|->
name|foreignEngines
argument_list|()
expr_stmt|;
foreach|foreach
control|(
name|QEngine
modifier|*
name|engine
decl|,
name|engines
control|)
block|{
if|if
condition|(
operator|!
name|wantedEngine
argument_list|(
name|engine
operator|->
name|name
argument_list|()
argument_list|)
condition|)
continue|continue;
name|QString
name|dirName
init|=
name|engine
operator|->
name|name
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|outputDirName
operator|.
name|isEmpty
argument_list|()
condition|)
name|dirName
operator|=
name|QString
argument_list|(
literal|"%1/%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|outputDirName
argument_list|)
operator|.
name|arg
argument_list|(
name|dirName
argument_list|)
expr_stmt|;
name|outDirs
operator|.
name|mkpath
argument_list|(
name|dirName
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|processArguments
name|bool
name|DataGenerator
operator|::
name|processArguments
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
name|QString
name|frameworkFile
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|argc
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|opt
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|opt
operator|==
literal|"-framework"
condition|)
block|{
name|frameworkFile
operator|=
name|QString
argument_list|(
name|argv
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
literal|"-engine"
condition|)
block|{
name|engineName
operator|=
name|QString
argument_list|(
name|argv
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
literal|"-suite"
condition|)
block|{
name|suiteName
operator|=
name|QString
argument_list|(
name|argv
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
literal|"-testcase"
condition|)
block|{
name|testcase
operator|=
name|QString
argument_list|(
name|argv
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
literal|"-file"
condition|)
block|{
name|fileName
operator|=
name|QString
argument_list|(
name|argv
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
literal|"-output"
condition|)
block|{
name|outputDirName
operator|=
name|QString
argument_list|(
name|argv
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
literal|"-iterations"
condition|)
block|{
name|iterations
operator|=
name|QString
argument_list|(
name|argv
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
literal|"-size"
condition|)
block|{
name|QStringList
name|args
init|=
name|QString
argument_list|(
name|argv
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
operator|.
name|split
argument_list|(
literal|","
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
decl_stmt|;
name|size
operator|=
name|QSize
argument_list|(
name|args
index|[
literal|0
index|]
operator|.
name|toInt
argument_list|()
argument_list|,
name|args
operator|.
name|size
argument_list|()
operator|>
literal|1
condition|?
name|args
index|[
literal|1
index|]
operator|.
name|toInt
argument_list|()
else|:
name|args
index|[
literal|0
index|]
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
literal|"-fill"
condition|)
block|{
name|fillColor
operator|=
name|QColor
argument_list|(
name|QString
argument_list|(
name|argv
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|.
name|startsWith
argument_list|(
literal|'-'
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Unknown option "
operator|<<
name|opt
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|frameworkFile
operator|.
name|isEmpty
argument_list|()
operator|&&
name|QFile
operator|::
name|exists
argument_list|(
name|frameworkFile
argument_list|)
condition|)
block|{
name|baseDataDir
operator|=
name|QFileInfo
argument_list|(
name|frameworkFile
argument_list|)
operator|.
name|absoluteDir
argument_list|()
operator|.
name|absolutePath
argument_list|()
expr_stmt|;
name|settings
operator|.
name|load
argument_list|(
name|frameworkFile
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|outputDirName
operator|.
name|isEmpty
argument_list|()
operator|&&
name|settings
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|outputDirName
operator|=
name|settings
operator|.
name|outputDir
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|outputDirName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QDir
name|dir
decl_stmt|;
name|dir
operator|.
name|mkpath
argument_list|(
name|outputDirName
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|engineName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QList
argument_list|<
name|QEngine
modifier|*
argument_list|>
name|engines
init|=
name|QtEngines
operator|::
name|self
argument_list|()
operator|->
name|engines
argument_list|()
decl_stmt|;
name|bool
name|found
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|engineName
operator|==
name|QLatin1String
argument_list|(
literal|"onscreen"
argument_list|)
operator|||
name|engineName
operator|==
name|QLatin1String
argument_list|(
literal|"printing"
argument_list|)
condition|)
name|found
operator|=
literal|true
expr_stmt|;
else|else
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|engines
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|found
operator||=
operator|(
name|engines
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|name
argument_list|()
operator|==
name|engineName
operator|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|found
condition|)
block|{
name|qDebug
argument_list|(
literal|"No such engine: '%s'\nAvailable engines are:"
argument_list|,
name|qPrintable
argument_list|(
name|engineName
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|engines
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|qDebug
argument_list|(
literal|"  %s"
argument_list|,
name|qPrintable
argument_list|(
name|engines
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|name
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
if|if
condition|(
operator|!
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|baseDataDir
operator|=
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|absoluteDir
argument_list|()
operator|.
name|absolutePath
argument_list|()
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|testGivenFile
name|void
name|DataGenerator
operator|::
name|testGivenFile
parameter_list|()
block|{
name|prepareDirs
argument_list|()
expr_stmt|;
name|XMLGenerator
name|generator
argument_list|(
name|baseDataDir
argument_list|)
decl_stmt|;
name|generator
operator|.
name|startSuite
argument_list|(
literal|"Single"
argument_list|)
expr_stmt|;
name|QFileInfo
name|fileInfo
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
name|bool
name|qpsScript
init|=
name|fileName
operator|.
name|endsWith
argument_list|(
literal|"qps"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|qpsScript
condition|)
block|{
name|QDir
name|oldDir
init|=
name|QDir
operator|::
name|current
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|baseDataDir
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QDir
operator|::
name|setCurrent
argument_list|(
name|baseDataDir
argument_list|)
expr_stmt|;
block|}
name|renderer
operator|->
name|load
argument_list|(
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|baseDataDir
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QDir
operator|::
name|setCurrent
argument_list|(
name|oldDir
operator|.
name|absolutePath
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|renderer
operator|->
name|isValid
argument_list|()
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Error while processing "
operator|<<
name|fileInfo
operator|.
name|absolutePath
argument_list|()
expr_stmt|;
return|return;
block|}
block|}
name|QList
argument_list|<
name|QEngine
modifier|*
argument_list|>
name|engines
init|=
name|QtEngines
operator|::
name|self
argument_list|()
operator|->
name|engines
argument_list|()
decl_stmt|;
name|testGivenEngines
argument_list|(
name|engines
argument_list|,
name|fileInfo
argument_list|,
name|fileInfo
operator|.
name|fileName
argument_list|()
argument_list|,
name|generator
argument_list|,
name|Normal
argument_list|)
expr_stmt|;
name|generator
operator|.
name|endSuite
argument_list|()
expr_stmt|;
name|std
operator|::
name|cout
operator|<<
name|qPrintable
argument_list|(
name|generator
operator|.
name|generateData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testSuite
name|void
name|DataGenerator
operator|::
name|testSuite
parameter_list|(
name|XMLGenerator
modifier|&
name|generator
parameter_list|,
specifier|const
name|QString
modifier|&
name|test
parameter_list|,
specifier|const
name|QString
modifier|&
name|dirName
parameter_list|,
specifier|const
name|QString
modifier|&
name|refUrl
parameter_list|)
block|{
name|generator
operator|.
name|startSuite
argument_list|(
name|test
argument_list|)
expr_stmt|;
name|QDir
name|dir
argument_list|(
name|dirName
argument_list|)
decl_stmt|;
name|dir
operator|.
name|setFilter
argument_list|(
name|QDir
operator|::
name|Files
operator||
name|QDir
operator|::
name|NoSymLinks
argument_list|)
expr_stmt|;
comment|//dir.setNameFilter()
foreach|foreach
control|(
name|QFileInfo
name|fileInfo
decl|,
name|dir
operator|.
name|entryInfoList
argument_list|()
control|)
block|{
if|if
condition|(
operator|!
name|testcase
operator|.
name|isEmpty
argument_list|()
operator|&&
name|fileInfo
operator|.
name|fileName
argument_list|()
operator|!=
name|testcase
condition|)
continue|continue;
name|QString
name|suffix
init|=
name|fileInfo
operator|.
name|suffix
argument_list|()
operator|.
name|toLower
argument_list|()
decl_stmt|;
if|if
condition|(
name|suffix
operator|!=
literal|"qps"
operator|&&
name|suffix
operator|!=
literal|"svg"
operator|&&
name|suffix
operator|!=
literal|"svgz"
condition|)
continue|continue;
name|qDebug
argument_list|()
operator|<<
literal|"Testing: "
operator|<<
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
expr_stmt|;
name|testEngines
argument_list|(
name|generator
argument_list|,
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|,
name|refUrl
argument_list|)
expr_stmt|;
block|}
name|generator
operator|.
name|endSuite
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loadFile
specifier|static
name|QString
name|loadFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|name
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qDebug
argument_list|(
literal|"Can't open file '%s'"
argument_list|,
name|qPrintable
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
block|}
name|QTextStream
name|str
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
return|return
name|str
operator|.
name|readAll
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|testGivenEngines
name|void
name|DataGenerator
operator|::
name|testGivenEngines
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QEngine
modifier|*
argument_list|>
name|engines
parameter_list|,
specifier|const
name|QFileInfo
modifier|&
name|fileInfo
parameter_list|,
specifier|const
name|QString
modifier|&
name|file
parameter_list|,
name|XMLGenerator
modifier|&
name|generator
parameter_list|,
name|GeneratorFlags
name|eflags
parameter_list|)
block|{
name|QString
name|fileName
init|=
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
decl_stmt|;
name|bool
name|qpsScript
init|=
name|fileName
operator|.
name|endsWith
argument_list|(
literal|".qps"
argument_list|)
decl_stmt|;
name|QStringList
name|qpsContents
decl_stmt|;
if|if
condition|(
name|qpsScript
condition|)
block|{
name|QString
name|script
init|=
name|loadFile
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
name|qpsContents
operator|=
name|script
operator|.
name|split
argument_list|(
literal|"\n"
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
expr_stmt|;
block|}
comment|//foreign one don't generate qpsScripts
if|if
condition|(
operator|(
name|eflags
operator|&
name|Foreign
operator|)
operator|&&
name|qpsScript
condition|)
return|return;
foreach|foreach
control|(
name|QEngine
modifier|*
name|engine
decl|,
name|engines
control|)
block|{
if|if
condition|(
operator|!
name|wantedEngine
argument_list|(
name|engine
operator|->
name|name
argument_list|()
argument_list|)
condition|)
continue|continue;
if|if
condition|(
name|settings
operator|.
name|isTestBlacklisted
argument_list|(
name|engine
operator|->
name|name
argument_list|()
argument_list|,
name|fileInfo
operator|.
name|fileName
argument_list|()
argument_list|)
condition|)
block|{
name|XMLData
name|data
decl_stmt|;
name|data
operator|.
name|details
operator|=
name|QString
argument_list|(
literal|"Test blacklisted"
argument_list|)
expr_stmt|;
name|data
operator|.
name|iterations
operator|=
literal|1
expr_stmt|;
name|generator
operator|.
name|addImage
argument_list|(
name|engine
operator|->
name|name
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|""
argument_list|)
argument_list|,
name|data
argument_list|,
name|eflags
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|QString
name|outFilename
init|=
name|createOutFilename
argument_list|(
name|outputDirName
argument_list|,
name|fileInfo
operator|.
name|fileName
argument_list|()
argument_list|,
name|engine
argument_list|)
decl_stmt|;
name|engine
operator|->
name|prepare
argument_list|(
name|qpsScript
condition|?
name|QSize
argument_list|(
literal|800
argument_list|,
literal|800
argument_list|)
else|:
name|size
argument_list|,
name|fillColor
argument_list|)
expr_stmt|;
name|int
name|elapsed
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|maxElapsed
init|=
literal|0
decl_stmt|;
name|int
name|minElapsed
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|(
name|eflags
operator|&
name|Foreign
operator|)
condition|)
block|{
name|engine
operator|->
name|render
argument_list|(
name|renderer
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|engine
operator|->
name|save
argument_list|(
name|outFilename
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|bool
name|saved
init|=
literal|false
decl_stmt|;
comment|//only measure Qt engines
name|QTime
name|time
decl_stmt|;
name|int
name|currentElapsed
init|=
literal|0
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
name|iterations
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|qpsScript
condition|)
block|{
name|QDir
name|oldDir
init|=
name|QDir
operator|::
name|current
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|baseDataDir
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QDir
operator|::
name|setCurrent
argument_list|(
name|baseDataDir
operator|+
literal|"/images"
argument_list|)
expr_stmt|;
block|}
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|engine
operator|->
name|render
argument_list|(
name|qpsContents
argument_list|,
name|fileName
argument_list|)
expr_stmt|;
name|currentElapsed
operator|=
name|time
operator|.
name|elapsed
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|baseDataDir
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QDir
operator|::
name|setCurrent
argument_list|(
name|oldDir
operator|.
name|absolutePath
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|engine
operator|->
name|render
argument_list|(
name|renderer
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|currentElapsed
operator|=
name|time
operator|.
name|elapsed
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|currentElapsed
operator|>
name|maxElapsed
condition|)
name|maxElapsed
operator|=
name|currentElapsed
expr_stmt|;
if|if
condition|(
operator|!
name|minElapsed
operator|||
name|currentElapsed
operator|<
name|minElapsed
condition|)
name|minElapsed
operator|=
name|currentElapsed
expr_stmt|;
name|elapsed
operator|+=
name|currentElapsed
expr_stmt|;
if|if
condition|(
operator|!
name|saved
condition|)
block|{
comment|//qDebug()<<"saving "<<i<<engine->name();
name|engine
operator|->
name|save
argument_list|(
name|outFilename
argument_list|)
expr_stmt|;
name|engine
operator|->
name|cleanup
argument_list|()
expr_stmt|;
name|engine
operator|->
name|prepare
argument_list|(
name|size
argument_list|,
name|fillColor
argument_list|)
expr_stmt|;
name|saved
operator|=
literal|true
expr_stmt|;
block|}
block|}
name|engine
operator|->
name|cleanup
argument_list|()
expr_stmt|;
block|}
name|GeneratorFlags
name|flags
init|=
name|Normal
decl_stmt|;
if|if
condition|(
name|QtEngines
operator|::
name|self
argument_list|()
operator|->
name|defaultEngine
argument_list|()
operator|==
name|engine
condition|)
name|flags
operator||=
name|Default
expr_stmt|;
name|flags
operator||=
name|eflags
expr_stmt|;
if|if
condition|(
operator|(
name|eflags
operator|&
name|Foreign
operator|)
condition|)
name|flags
operator|^=
name|Normal
expr_stmt|;
name|XMLData
name|data
decl_stmt|;
name|data
operator|.
name|date
operator|=
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
expr_stmt|;
name|data
operator|.
name|timeToRender
operator|=
name|elapsed
expr_stmt|;
name|data
operator|.
name|iterations
operator|=
name|iterations
expr_stmt|;
name|data
operator|.
name|maxElapsed
operator|=
name|maxElapsed
expr_stmt|;
name|data
operator|.
name|minElapsed
operator|=
name|minElapsed
expr_stmt|;
name|generator
operator|.
name|addImage
argument_list|(
name|engine
operator|->
name|name
argument_list|()
argument_list|,
name|outFilename
argument_list|,
name|data
argument_list|,
name|flags
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|wantedEngine
name|bool
name|DataGenerator
operator|::
name|wantedEngine
parameter_list|(
specifier|const
name|QString
modifier|&
name|engine
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|engineName
operator|.
name|isEmpty
argument_list|()
operator|&&
name|engine
operator|!=
name|engineName
condition|)
block|{
if|if
condition|(
name|engineName
operator|==
literal|"onscreen"
condition|)
block|{
if|if
condition|(
name|engine
operator|.
name|startsWith
argument_list|(
literal|"Native"
argument_list|)
operator|||
name|engine
operator|==
name|QLatin1String
argument_list|(
literal|"Raster"
argument_list|)
operator|||
name|engine
operator|==
name|QLatin1String
argument_list|(
literal|"OpenGL"
argument_list|)
condition|)
return|return
literal|true
return|;
block|}
elseif|else
if|if
condition|(
name|engineName
operator|==
name|QLatin1String
argument_list|(
literal|"printing"
argument_list|)
condition|)
block|{
if|if
condition|(
name|engine
operator|==
name|QLatin1String
argument_list|(
literal|"PS"
argument_list|)
operator|||
name|engine
operator|==
name|QLatin1String
argument_list|(
literal|"PDF"
argument_list|)
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
end_unit
