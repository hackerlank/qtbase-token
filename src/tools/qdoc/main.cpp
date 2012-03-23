begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   main.cpp */
end_comment
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|"codemarker.h"
end_include
begin_include
include|#
directive|include
file|"codeparser.h"
end_include
begin_include
include|#
directive|include
file|"config.h"
end_include
begin_include
include|#
directive|include
file|"cppcodemarker.h"
end_include
begin_include
include|#
directive|include
file|"cppcodeparser.h"
end_include
begin_include
include|#
directive|include
file|"ditaxmlgenerator.h"
end_include
begin_include
include|#
directive|include
file|"doc.h"
end_include
begin_include
include|#
directive|include
file|"htmlgenerator.h"
end_include
begin_include
include|#
directive|include
file|"plaincodemarker.h"
end_include
begin_include
include|#
directive|include
file|"puredocparser.h"
end_include
begin_include
include|#
directive|include
file|"tokenizer.h"
end_include
begin_include
include|#
directive|include
file|"tree.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DECLARATIVE
end_ifdef
begin_include
include|#
directive|include
file|"jscodemarker.h"
end_include
begin_include
include|#
directive|include
file|"qmlcodemarker.h"
end_include
begin_include
include|#
directive|include
file|"qmlcodeparser.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|"qtranslator.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
end_ifndef
begin_include
include|#
directive|include
file|"qcoreapplication.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
comment|/*   The default indent for code is 4.   The default value for false is 0.   The default supported file extensions are cpp, h, qdoc and qml.   The default language is c++.   The default output format is html.   The default tab size is 8.   And those are all the default values for configuration variables.  */
specifier|static
specifier|const
expr|struct
block|{
DECL|member|key
specifier|const
name|char
operator|*
name|key
block|;
DECL|member|value
specifier|const
name|char
operator|*
name|value
block|; }
DECL|variable|defaults
name|defaults
index|[]
operator|=
block|{
block|{
name|CONFIG_CODEINDENT
block|,
literal|"4"
block|}
block|,
block|{
name|CONFIG_FALSEHOODS
block|,
literal|"0"
block|}
block|,
block|{
name|CONFIG_FILEEXTENSIONS
block|,
literal|"*.cpp *.h *.qdoc *.qml"
block|}
block|,
block|{
name|CONFIG_LANGUAGE
block|,
literal|"Cpp"
block|}
block|,
block|{
name|CONFIG_OUTPUTFORMATS
block|,
literal|"HTML"
block|}
block|,
block|{
name|CONFIG_TABSIZE
block|,
literal|"8"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|highlighting
specifier|static
name|bool
name|highlighting
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|showInternal
specifier|static
name|bool
name|showInternal
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|obsoleteLinks
specifier|static
name|bool
name|obsoleteLinks
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|defines
specifier|static
name|QStringList
name|defines
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|trees
specifier|static
name|QHash
argument_list|<
name|QString
argument_list|,
name|Tree
modifier|*
argument_list|>
name|trees
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!   Print the help message to \c stdout.  */
end_comment
begin_function
DECL|function|printHelp
specifier|static
name|void
name|printHelp
parameter_list|()
block|{
name|Location
operator|::
name|information
argument_list|(
name|tr
argument_list|(
literal|"Usage: qdoc [options] file1.qdocconf ...\n"
literal|"Options:\n"
literal|"    -D<name>       "
literal|"Define<name> as a macro while parsing sources\n"
literal|"    -help          "
literal|"Display this information and exit\n"
literal|"    -highlighting  "
literal|"Turn on syntax highlighting (makes qdoc run slower)\n"
literal|"    -no-examples   "
literal|"Do not generate documentation for examples"
literal|"    -obsoletelinks "
literal|"Report links from obsolete items to non-obsolete items\n"
literal|"    -outputdir     "
literal|"Specify output directory, overrides setting in qdocconf file\n"
literal|"    -outputformat  "
literal|"Specify output format, overrides setting in qdocconf file"
literal|"    -showinternal  "
literal|"Include content marked internal\n"
literal|"    -version       "
literal|"Display version of qdoc and exit\n"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Prints the qdoc version number to stdout.  */
end_comment
begin_function
DECL|function|printVersion
specifier|static
name|void
name|printVersion
parameter_list|()
block|{
name|QString
name|s
init|=
name|tr
argument_list|(
literal|"qdoc version %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QT_VERSION_STR
argument_list|)
decl_stmt|;
name|Location
operator|::
name|information
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Processes the qdoc config file \a fileName. This is the   controller for all of qdoc.  */
end_comment
begin_function
DECL|function|processQdocconfFile
specifier|static
name|void
name|processQdocconfFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_TRANSLATION
name|QList
argument_list|<
name|QTranslator
modifier|*
argument_list|>
name|translators
decl_stmt|;
endif|#
directive|endif
comment|/*       The Config instance represents the configuration data for qdoc.       All the other classes are initialized with the config. Here we       initialize the configuration with some default values.      */
name|Config
name|config
argument_list|(
name|tr
argument_list|(
literal|"qdoc"
argument_list|)
argument_list|)
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|defaults
index|[
name|i
index|]
operator|.
name|key
condition|)
block|{
name|config
operator|.
name|setStringList
argument_list|(
name|defaults
index|[
name|i
index|]
operator|.
name|key
argument_list|,
name|QStringList
argument_list|()
operator|<<
name|defaults
index|[
name|i
index|]
operator|.
name|value
argument_list|)
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
name|config
operator|.
name|setStringList
argument_list|(
name|CONFIG_SYNTAXHIGHLIGHTING
argument_list|,
name|QStringList
argument_list|(
name|highlighting
condition|?
literal|"true"
else|:
literal|"false"
argument_list|)
argument_list|)
expr_stmt|;
name|config
operator|.
name|setStringList
argument_list|(
name|CONFIG_SHOWINTERNAL
argument_list|,
name|QStringList
argument_list|(
name|showInternal
condition|?
literal|"true"
else|:
literal|"false"
argument_list|)
argument_list|)
expr_stmt|;
name|config
operator|.
name|setStringList
argument_list|(
name|CONFIG_OBSOLETELINKS
argument_list|,
name|QStringList
argument_list|(
name|obsoleteLinks
condition|?
literal|"true"
else|:
literal|"false"
argument_list|)
argument_list|)
expr_stmt|;
comment|/*       With the default configuration values in place, load       the qdoc configuration file. Note that the configuration       file may include other configuration files.        The Location class keeps track of the current location       in the file being processed, mainly for error reporting       purposes.      */
name|Location
operator|::
name|initialize
argument_list|(
name|config
argument_list|)
expr_stmt|;
name|config
operator|.
name|load
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
comment|/*       Add the defines to the configuration variables.      */
name|QStringList
name|defs
init|=
name|defines
operator|+
name|config
operator|.
name|getStringList
argument_list|(
name|CONFIG_DEFINES
argument_list|)
decl_stmt|;
name|config
operator|.
name|setStringList
argument_list|(
name|CONFIG_DEFINES
argument_list|,
name|defs
argument_list|)
expr_stmt|;
name|Location
operator|::
name|terminate
argument_list|()
expr_stmt|;
name|QString
name|prevCurrentDir
init|=
name|QDir
operator|::
name|currentPath
argument_list|()
decl_stmt|;
name|QString
name|dir
init|=
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|path
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|dir
operator|.
name|isEmpty
argument_list|()
condition|)
name|QDir
operator|::
name|setCurrent
argument_list|(
name|dir
argument_list|)
expr_stmt|;
comment|/*       Initialize all the classes and data structures with the       qdoc configuration.      */
name|Location
operator|::
name|initialize
argument_list|(
name|config
argument_list|)
expr_stmt|;
name|Tokenizer
operator|::
name|initialize
argument_list|(
name|config
argument_list|)
expr_stmt|;
name|Doc
operator|::
name|initialize
argument_list|(
name|config
argument_list|)
expr_stmt|;
name|CodeMarker
operator|::
name|initialize
argument_list|(
name|config
argument_list|)
expr_stmt|;
name|CodeParser
operator|::
name|initialize
argument_list|(
name|config
argument_list|)
expr_stmt|;
name|Generator
operator|::
name|initialize
argument_list|(
name|config
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TRANSLATION
comment|/*       Load the language translators, if the configuration specifies any.      */
name|QStringList
name|fileNames
init|=
name|config
operator|.
name|getStringList
argument_list|(
name|CONFIG_TRANSLATORS
argument_list|)
decl_stmt|;
name|QStringList
operator|::
name|Iterator
name|fn
init|=
name|fileNames
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|fn
operator|!=
name|fileNames
operator|.
name|end
argument_list|()
condition|)
block|{
name|QTranslator
modifier|*
name|translator
init|=
operator|new
name|QTranslator
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|translator
operator|->
name|load
argument_list|(
operator|*
name|fn
argument_list|)
condition|)
name|config
operator|.
name|lastLocation
argument_list|()
operator|.
name|error
argument_list|(
name|tr
argument_list|(
literal|"Cannot load translator '%1'"
argument_list|)
operator|.
name|arg
argument_list|(
operator|*
name|fn
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|installTranslator
argument_list|(
name|translator
argument_list|)
expr_stmt|;
name|translators
operator|.
name|append
argument_list|(
name|translator
argument_list|)
expr_stmt|;
operator|++
name|fn
expr_stmt|;
block|}
endif|#
directive|endif
comment|//QSet<QString> outputLanguages = config.getStringSet(CONFIG_OUTPUTLANGUAGES);
comment|/*       Get the source language (Cpp) from the configuration       and the location in the configuration file where the       source language was set.      */
name|QString
name|lang
init|=
name|config
operator|.
name|getString
argument_list|(
name|CONFIG_LANGUAGE
argument_list|)
decl_stmt|;
name|Location
name|langLocation
init|=
name|config
operator|.
name|lastLocation
argument_list|()
decl_stmt|;
comment|/*       Initialize the tree where all the parsed sources will be stored.       The tree gets built as the source files are parsed, and then the       documentation output is generated by traversing the tree.      */
name|Tree
modifier|*
name|tree
init|=
operator|new
name|Tree
decl_stmt|;
name|tree
operator|->
name|setVersion
argument_list|(
name|config
operator|.
name|getString
argument_list|(
name|CONFIG_VERSION
argument_list|)
argument_list|)
expr_stmt|;
comment|/*       By default, the only output format is HTML.      */
name|QSet
argument_list|<
name|QString
argument_list|>
name|outputFormats
init|=
name|config
operator|.
name|getOutputFormats
argument_list|()
decl_stmt|;
name|Location
name|outputFormatsLocation
init|=
name|config
operator|.
name|lastLocation
argument_list|()
decl_stmt|;
comment|/*       Read some XML indexes containing definitions from other documentation sets.      */
name|QStringList
name|indexFiles
init|=
name|config
operator|.
name|getStringList
argument_list|(
name|CONFIG_INDEXES
argument_list|)
decl_stmt|;
name|tree
operator|->
name|readIndexes
argument_list|(
name|indexFiles
argument_list|)
expr_stmt|;
name|QSet
argument_list|<
name|QString
argument_list|>
name|excludedDirs
decl_stmt|;
name|QSet
argument_list|<
name|QString
argument_list|>
name|excludedFiles
decl_stmt|;
name|QSet
argument_list|<
name|QString
argument_list|>
name|headers
decl_stmt|;
name|QSet
argument_list|<
name|QString
argument_list|>
name|sources
decl_stmt|;
name|QStringList
name|headerList
decl_stmt|;
name|QStringList
name|sourceList
decl_stmt|;
name|QStringList
name|excludedDirsList
decl_stmt|;
name|QStringList
name|excludedFilesList
decl_stmt|;
name|excludedDirsList
operator|=
name|config
operator|.
name|getCleanPathList
argument_list|(
name|CONFIG_EXCLUDEDIRS
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|excludeDir
decl|,
name|excludedDirsList
control|)
block|{
name|QString
name|p
init|=
name|QDir
operator|::
name|fromNativeSeparators
argument_list|(
name|excludeDir
argument_list|)
decl_stmt|;
name|excludedDirs
operator|.
name|insert
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
name|excludedFilesList
operator|=
name|config
operator|.
name|getCleanPathList
argument_list|(
name|CONFIG_EXCLUDEFILES
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|excludeFile
decl|,
name|excludedFilesList
control|)
block|{
name|QString
name|p
init|=
name|QDir
operator|::
name|fromNativeSeparators
argument_list|(
name|excludeFile
argument_list|)
decl_stmt|;
name|excludedFiles
operator|.
name|insert
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
name|headerList
operator|=
name|config
operator|.
name|getAllFiles
argument_list|(
name|CONFIG_HEADERS
argument_list|,
name|CONFIG_HEADERDIRS
argument_list|,
name|excludedDirs
argument_list|,
name|excludedFiles
argument_list|)
expr_stmt|;
name|headers
operator|=
name|QSet
argument_list|<
name|QString
argument_list|>
operator|::
name|fromList
argument_list|(
name|headerList
argument_list|)
expr_stmt|;
name|sourceList
operator|=
name|config
operator|.
name|getAllFiles
argument_list|(
name|CONFIG_SOURCES
argument_list|,
name|CONFIG_SOURCEDIRS
argument_list|,
name|excludedDirs
argument_list|,
name|excludedFiles
argument_list|)
expr_stmt|;
name|sources
operator|=
name|QSet
argument_list|<
name|QString
argument_list|>
operator|::
name|fromList
argument_list|(
name|sourceList
argument_list|)
expr_stmt|;
comment|/*       Parse each header file in the set using the appropriate parser and add it       to the big tree.      */
name|QSet
argument_list|<
name|CodeParser
modifier|*
argument_list|>
name|usedParsers
decl_stmt|;
name|QSet
argument_list|<
name|QString
argument_list|>
operator|::
name|ConstIterator
name|h
init|=
name|headers
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|h
operator|!=
name|headers
operator|.
name|end
argument_list|()
condition|)
block|{
name|CodeParser
modifier|*
name|codeParser
init|=
name|CodeParser
operator|::
name|parserForHeaderFile
argument_list|(
operator|*
name|h
argument_list|)
decl_stmt|;
if|if
condition|(
name|codeParser
condition|)
block|{
name|codeParser
operator|->
name|parseHeaderFile
argument_list|(
name|config
operator|.
name|location
argument_list|()
argument_list|,
operator|*
name|h
argument_list|,
name|tree
argument_list|)
expr_stmt|;
name|usedParsers
operator|.
name|insert
argument_list|(
name|codeParser
argument_list|)
expr_stmt|;
block|}
operator|++
name|h
expr_stmt|;
block|}
foreach|foreach
control|(
name|CodeParser
modifier|*
name|codeParser
decl|,
name|usedParsers
control|)
name|codeParser
operator|->
name|doneParsingHeaderFiles
argument_list|(
name|tree
argument_list|)
expr_stmt|;
name|usedParsers
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|/*       Parse each source text file in the set using the appropriate parser and       add it to the big tree.      */
name|QSet
argument_list|<
name|QString
argument_list|>
operator|::
name|ConstIterator
name|s
init|=
name|sources
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|s
operator|!=
name|sources
operator|.
name|end
argument_list|()
condition|)
block|{
name|CodeParser
modifier|*
name|codeParser
init|=
name|CodeParser
operator|::
name|parserForSourceFile
argument_list|(
operator|*
name|s
argument_list|)
decl_stmt|;
if|if
condition|(
name|codeParser
condition|)
block|{
name|codeParser
operator|->
name|parseSourceFile
argument_list|(
name|config
operator|.
name|location
argument_list|()
argument_list|,
operator|*
name|s
argument_list|,
name|tree
argument_list|)
expr_stmt|;
name|usedParsers
operator|.
name|insert
argument_list|(
name|codeParser
argument_list|)
expr_stmt|;
block|}
operator|++
name|s
expr_stmt|;
block|}
foreach|foreach
control|(
name|CodeParser
modifier|*
name|codeParser
decl|,
name|usedParsers
control|)
name|codeParser
operator|->
name|doneParsingSourceFiles
argument_list|(
name|tree
argument_list|)
expr_stmt|;
comment|/*       Now the big tree has been built from all the header and       source files. Resolve all the class names, function names,       targets, URLs, links, and other stuff that needs resolving.      */
name|tree
operator|->
name|resolveGroups
argument_list|()
expr_stmt|;
name|tree
operator|->
name|resolveQmlModules
argument_list|()
expr_stmt|;
name|tree
operator|->
name|resolveTargets
argument_list|(
name|tree
operator|->
name|root
argument_list|()
argument_list|)
expr_stmt|;
name|tree
operator|->
name|resolveCppToQmlLinks
argument_list|()
expr_stmt|;
name|tree
operator|->
name|resolveQmlInheritance
argument_list|()
expr_stmt|;
comment|/*       The tree is built and all the stuff that needed resolving       has been resolved. Now traverse the tree and generate the       documentation output. More than one output format can be       requested. The tree is traversed for each one.      */
name|QSet
argument_list|<
name|QString
argument_list|>
operator|::
name|ConstIterator
name|of
init|=
name|outputFormats
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|of
operator|!=
name|outputFormats
operator|.
name|end
argument_list|()
condition|)
block|{
name|Generator
modifier|*
name|generator
init|=
name|Generator
operator|::
name|generatorForFormat
argument_list|(
operator|*
name|of
argument_list|)
decl_stmt|;
if|if
condition|(
name|generator
operator|==
literal|0
condition|)
name|outputFormatsLocation
operator|.
name|fatal
argument_list|(
name|tr
argument_list|(
literal|"Unknown output format '%1'"
argument_list|)
operator|.
name|arg
argument_list|(
operator|*
name|of
argument_list|)
argument_list|)
expr_stmt|;
name|generator
operator|->
name|generateTree
argument_list|(
name|tree
argument_list|)
expr_stmt|;
operator|++
name|of
expr_stmt|;
block|}
comment|/*       Generate the XML tag file, if it was requested.      */
name|QString
name|tagFile
init|=
name|config
operator|.
name|getString
argument_list|(
name|CONFIG_TAGFILE
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|tagFile
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|tree
operator|->
name|generateTagFile
argument_list|(
name|tagFile
argument_list|)
expr_stmt|;
block|}
name|tree
operator|->
name|setVersion
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|Generator
operator|::
name|terminate
argument_list|()
expr_stmt|;
name|CodeParser
operator|::
name|terminate
argument_list|()
expr_stmt|;
name|CodeMarker
operator|::
name|terminate
argument_list|()
expr_stmt|;
name|Doc
operator|::
name|terminate
argument_list|()
expr_stmt|;
name|Tokenizer
operator|::
name|terminate
argument_list|()
expr_stmt|;
name|Location
operator|::
name|terminate
argument_list|()
expr_stmt|;
name|QDir
operator|::
name|setCurrent
argument_list|(
name|prevCurrentDir
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TRANSLATION
name|qDeleteAll
argument_list|(
name|translators
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DEBUG_SHUTDOWN_CRASH
name|qDebug
argument_list|()
operator|<<
literal|"main(): Delete tree"
expr_stmt|;
endif|#
directive|endif
operator|delete
name|tree
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG_SHUTDOWN_CRASH
name|qDebug
argument_list|()
operator|<<
literal|"main(): Tree deleted"
expr_stmt|;
endif|#
directive|endif
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
modifier|*
name|argv
parameter_list|)
block|{
name|QT_USE_NAMESPACE
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
endif|#
directive|endif
comment|/*       Create code parsers for the languages to be parsed,       and create a tree for C++.      */
name|CppCodeParser
name|cppParser
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_DECLARATIVE
name|QmlCodeParser
name|qmlParser
decl_stmt|;
endif|#
directive|endif
name|PureDocParser
name|docParser
decl_stmt|;
comment|/*       Create code markers for plain text, C++,       javascript, and QML.      */
name|PlainCodeMarker
name|plainMarker
decl_stmt|;
name|CppCodeMarker
name|cppMarker
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_DECLARATIVE
name|JsCodeMarker
name|jsMarker
decl_stmt|;
name|QmlCodeMarker
name|qmlMarker
decl_stmt|;
endif|#
directive|endif
name|HtmlGenerator
name|htmlGenerator
decl_stmt|;
name|DitaXmlGenerator
name|ditaxmlGenerator
decl_stmt|;
name|QStringList
name|qdocFiles
decl_stmt|;
name|QString
name|opt
decl_stmt|;
name|int
name|i
init|=
literal|1
decl_stmt|;
while|while
condition|(
name|i
operator|<
name|argc
condition|)
block|{
name|opt
operator|=
name|argv
index|[
name|i
operator|++
index|]
expr_stmt|;
if|if
condition|(
name|opt
operator|==
literal|"-help"
condition|)
block|{
name|printHelp
argument_list|()
expr_stmt|;
return|return
name|EXIT_SUCCESS
return|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
literal|"-version"
condition|)
block|{
name|printVersion
argument_list|()
expr_stmt|;
return|return
name|EXIT_SUCCESS
return|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
literal|"--"
condition|)
block|{
while|while
condition|(
name|i
operator|<
name|argc
condition|)
name|qdocFiles
operator|.
name|append
argument_list|(
name|argv
index|[
name|i
operator|++
index|]
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
literal|"-D"
argument_list|)
condition|)
block|{
name|QString
name|define
init|=
name|opt
operator|.
name|mid
argument_list|(
literal|2
argument_list|)
decl_stmt|;
name|defines
operator|+=
name|define
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
literal|"-highlighting"
condition|)
block|{
name|highlighting
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
literal|"-showinternal"
condition|)
block|{
name|showInternal
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
literal|"-no-examples"
condition|)
block|{
name|Config
operator|::
name|generateExamples
operator|=
literal|false
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
literal|"-obsoletelinks"
condition|)
block|{
name|obsoleteLinks
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
literal|"-outputdir"
condition|)
block|{
name|Config
operator|::
name|overrideOutputDir
operator|=
name|argv
index|[
name|i
index|]
expr_stmt|;
name|i
operator|++
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
literal|"-outputformat"
condition|)
block|{
name|Config
operator|::
name|overrideOutputFormats
operator|.
name|insert
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|i
operator|++
expr_stmt|;
block|}
else|else
block|{
name|qdocFiles
operator|.
name|append
argument_list|(
name|opt
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|qdocFiles
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|printHelp
argument_list|()
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
comment|/*       Main loop.      */
foreach|foreach
control|(
name|QString
name|qf
decl|,
name|qdocFiles
control|)
block|{
comment|//qDebug()<< "PROCESSING:"<< qf;
name|processQdocconfFile
argument_list|(
name|qf
argument_list|)
expr_stmt|;
block|}
name|qDeleteAll
argument_list|(
name|trees
argument_list|)
expr_stmt|;
return|return
name|EXIT_SUCCESS
return|;
block|}
end_function
end_unit
