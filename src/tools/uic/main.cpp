begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"uic.h"
end_include
begin_include
include|#
directive|include
file|"option.h"
end_include
begin_include
include|#
directive|include
file|"driver.h"
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<qtextcodec.h>
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
specifier|extern
name|Q_CORE_EXPORT
name|QBasicAtomicInt
name|qt_qhash_seed
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|runUic
name|int
name|runUic
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
name|qt_qhash_seed
operator|.
name|testAndSetRelaxed
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// set the hash seed to 0 if it wasn't set yet
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
name|Driver
name|driver
decl_stmt|;
comment|// Note that uic isn't translated.
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
literal|"Qt User Interface Compiler version %1"
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
name|dependenciesOption
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|QStringLiteral
argument_list|(
literal|"d"
argument_list|)
operator|<<
name|QStringLiteral
argument_list|(
literal|"dependencies"
argument_list|)
argument_list|)
decl_stmt|;
name|dependenciesOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Display the dependencies."
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|dependenciesOption
argument_list|)
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
literal|"Place the output into<file>"
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
name|noProtOption
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|QStringLiteral
argument_list|(
literal|"p"
argument_list|)
operator|<<
name|QStringLiteral
argument_list|(
literal|"no-protection"
argument_list|)
argument_list|)
decl_stmt|;
name|noProtOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Disable header protection."
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|noProtOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|noImplicitIncludesOption
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|QStringLiteral
argument_list|(
literal|"n"
argument_list|)
operator|<<
name|QStringLiteral
argument_list|(
literal|"no-implicit-includes"
argument_list|)
argument_list|)
decl_stmt|;
name|noImplicitIncludesOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Disable generation of #include-directives."
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|noImplicitIncludesOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|postfixOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"postfix"
argument_list|)
argument_list|)
decl_stmt|;
name|postfixOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Postfix to add to all generated classnames."
argument_list|)
argument_list|)
expr_stmt|;
name|postfixOption
operator|.
name|setValueName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"postfix"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|postfixOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|translateOption
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|QStringLiteral
argument_list|(
literal|"tr"
argument_list|)
operator|<<
name|QStringLiteral
argument_list|(
literal|"translate"
argument_list|)
argument_list|)
decl_stmt|;
name|translateOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Use<function> for i18n."
argument_list|)
argument_list|)
expr_stmt|;
name|translateOption
operator|.
name|setValueName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"function"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|translateOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|includeOption
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|QStringLiteral
argument_list|(
literal|"include"
argument_list|)
argument_list|)
decl_stmt|;
name|includeOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Add #include<include-file> to<file>."
argument_list|)
argument_list|)
expr_stmt|;
name|includeOption
operator|.
name|setValueName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"include-file"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|includeOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|generatorOption
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|QStringLiteral
argument_list|(
literal|"g"
argument_list|)
operator|<<
name|QStringLiteral
argument_list|(
literal|"generator"
argument_list|)
argument_list|)
decl_stmt|;
name|generatorOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Select generator."
argument_list|)
argument_list|)
expr_stmt|;
name|generatorOption
operator|.
name|setValueName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"java|cpp"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|generatorOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|idBasedOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"idbased"
argument_list|)
argument_list|)
decl_stmt|;
name|idBasedOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Use id based function for i18n"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|idBasedOption
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addPositionalArgument
argument_list|(
name|QStringLiteral
argument_list|(
literal|"[uifile]"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Input file (*.ui), otherwise stdin."
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|process
argument_list|(
name|app
argument_list|)
expr_stmt|;
name|driver
operator|.
name|option
argument_list|()
operator|.
name|dependencies
operator|=
name|parser
operator|.
name|isSet
argument_list|(
name|dependenciesOption
argument_list|)
expr_stmt|;
name|driver
operator|.
name|option
argument_list|()
operator|.
name|outputFile
operator|=
name|parser
operator|.
name|value
argument_list|(
name|outputOption
argument_list|)
expr_stmt|;
name|driver
operator|.
name|option
argument_list|()
operator|.
name|headerProtection
operator|=
operator|!
name|parser
operator|.
name|isSet
argument_list|(
name|noProtOption
argument_list|)
expr_stmt|;
name|driver
operator|.
name|option
argument_list|()
operator|.
name|implicitIncludes
operator|=
operator|!
name|parser
operator|.
name|isSet
argument_list|(
name|noImplicitIncludesOption
argument_list|)
expr_stmt|;
name|driver
operator|.
name|option
argument_list|()
operator|.
name|idBased
operator|=
name|parser
operator|.
name|isSet
argument_list|(
name|idBasedOption
argument_list|)
expr_stmt|;
name|driver
operator|.
name|option
argument_list|()
operator|.
name|postfix
operator|=
name|parser
operator|.
name|value
argument_list|(
name|postfixOption
argument_list|)
expr_stmt|;
name|driver
operator|.
name|option
argument_list|()
operator|.
name|translateFunction
operator|=
name|parser
operator|.
name|value
argument_list|(
name|translateOption
argument_list|)
expr_stmt|;
name|driver
operator|.
name|option
argument_list|()
operator|.
name|includeFile
operator|=
name|parser
operator|.
name|value
argument_list|(
name|includeOption
argument_list|)
expr_stmt|;
name|driver
operator|.
name|option
argument_list|()
operator|.
name|generator
operator|=
operator|(
name|parser
operator|.
name|value
argument_list|(
name|generatorOption
argument_list|)
operator|.
name|toLower
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"java"
argument_list|)
operator|)
condition|?
name|Option
operator|::
name|JavaGenerator
else|:
name|Option
operator|::
name|CppGenerator
expr_stmt|;
name|QString
name|inputFile
decl_stmt|;
if|if
condition|(
operator|!
name|parser
operator|.
name|positionalArguments
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|inputFile
operator|=
name|parser
operator|.
name|positionalArguments
argument_list|()
operator|.
name|first
argument_list|()
expr_stmt|;
else|else
comment|// reading from stdin
name|driver
operator|.
name|option
argument_list|()
operator|.
name|headerProtection
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|driver
operator|.
name|option
argument_list|()
operator|.
name|dependencies
condition|)
block|{
return|return
operator|!
name|driver
operator|.
name|printDependencies
argument_list|(
name|inputFile
argument_list|)
return|;
block|}
name|QTextStream
modifier|*
name|out
init|=
literal|0
decl_stmt|;
name|QFile
name|f
decl_stmt|;
if|if
condition|(
name|driver
operator|.
name|option
argument_list|()
operator|.
name|outputFile
operator|.
name|size
argument_list|()
condition|)
block|{
name|f
operator|.
name|setFileName
argument_list|(
name|driver
operator|.
name|option
argument_list|()
operator|.
name|outputFile
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Could not create output file\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|out
operator|=
operator|new
name|QTextStream
argument_list|(
operator|&
name|f
argument_list|)
expr_stmt|;
name|out
operator|->
name|setCodec
argument_list|(
name|QTextCodec
operator|::
name|codecForName
argument_list|(
literal|"UTF-8"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|bool
name|rtn
init|=
name|driver
operator|.
name|uic
argument_list|(
name|inputFile
argument_list|,
name|out
argument_list|)
decl_stmt|;
operator|delete
name|out
expr_stmt|;
if|if
condition|(
operator|!
name|rtn
condition|)
block|{
if|if
condition|(
name|driver
operator|.
name|option
argument_list|()
operator|.
name|outputFile
operator|.
name|size
argument_list|()
condition|)
block|{
name|f
operator|.
name|close
argument_list|()
expr_stmt|;
name|f
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"File '%s' is not valid\n"
argument_list|,
name|inputFile
operator|.
name|isEmpty
argument_list|()
condition|?
literal|"<stdin>"
else|:
name|inputFile
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
operator|!
name|rtn
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
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
return|return
name|QT_PREPEND_NAMESPACE
argument_list|(
name|runUic
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
