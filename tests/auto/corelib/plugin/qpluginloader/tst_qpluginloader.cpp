begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qpluginloader.h>
end_include
begin_include
include|#
directive|include
file|"theplugin/plugininterface.h"
end_include
begin_comment
comment|// Helper macros to let us know if some suffixes are valid
end_comment
begin_define
DECL|macro|bundle_VALID
define|#
directive|define
name|bundle_VALID
value|false
end_define
begin_define
DECL|macro|dylib_VALID
define|#
directive|define
name|dylib_VALID
value|false
end_define
begin_define
DECL|macro|sl_VALID
define|#
directive|define
name|sl_VALID
value|false
end_define
begin_define
DECL|macro|a_VALID
define|#
directive|define
name|a_VALID
value|false
end_define
begin_define
DECL|macro|so_VALID
define|#
directive|define
name|so_VALID
value|false
end_define
begin_define
DECL|macro|dll_VALID
define|#
directive|define
name|dll_VALID
value|false
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_DARWIN
argument_list|)
end_if
begin_undef
DECL|macro|bundle_VALID
undef|#
directive|undef
name|bundle_VALID
end_undef
begin_undef
DECL|macro|dylib_VALID
undef|#
directive|undef
name|dylib_VALID
end_undef
begin_undef
DECL|macro|so_VALID
undef|#
directive|undef
name|so_VALID
end_undef
begin_define
DECL|macro|bundle_VALID
define|#
directive|define
name|bundle_VALID
value|true
end_define
begin_define
DECL|macro|dylib_VALID
define|#
directive|define
name|dylib_VALID
value|true
end_define
begin_define
DECL|macro|so_VALID
define|#
directive|define
name|so_VALID
value|true
end_define
begin_define
DECL|macro|SUFFIX
define|#
directive|define
name|SUFFIX
value|".dylib"
end_define
begin_define
DECL|macro|PREFIX
define|#
directive|define
name|PREFIX
value|"lib"
end_define
begin_elif
elif|#
directive|elif
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
end_elif
begin_undef
DECL|macro|sl_VALID
undef|#
directive|undef
name|sl_VALID
end_undef
begin_define
DECL|macro|sl_VALID
define|#
directive|define
name|sl_VALID
value|true
end_define
begin_define
DECL|macro|SUFFIX
define|#
directive|define
name|SUFFIX
value|".sl"
end_define
begin_define
DECL|macro|PREFIX
define|#
directive|define
name|PREFIX
value|"lib"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_AIX
argument_list|)
end_elif
begin_undef
DECL|macro|a_VALID
undef|#
directive|undef
name|a_VALID
end_undef
begin_undef
DECL|macro|so_VALID
undef|#
directive|undef
name|so_VALID
end_undef
begin_define
DECL|macro|a_VALID
define|#
directive|define
name|a_VALID
value|true
end_define
begin_define
DECL|macro|so_VALID
define|#
directive|define
name|so_VALID
value|true
end_define
begin_define
DECL|macro|SUFFIX
define|#
directive|define
name|SUFFIX
value|".so"
end_define
begin_define
DECL|macro|PREFIX
define|#
directive|define
name|PREFIX
value|"lib"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_elif
begin_undef
DECL|macro|dll_VALID
undef|#
directive|undef
name|dll_VALID
end_undef
begin_define
DECL|macro|dll_VALID
define|#
directive|define
name|dll_VALID
value|true
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_DEBUG
end_ifdef
begin_define
DECL|macro|SUFFIX
define|#
directive|define
name|SUFFIX
value|".dll"
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|SUFFIX
define|#
directive|define
name|SUFFIX
value|"d.dll"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|PREFIX
define|#
directive|define
name|PREFIX
value|""
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|// all other Unix
end_comment
begin_undef
DECL|macro|so_VALID
undef|#
directive|undef
name|so_VALID
end_undef
begin_define
DECL|macro|so_VALID
define|#
directive|define
name|so_VALID
value|true
end_define
begin_define
DECL|macro|SUFFIX
define|#
directive|define
name|SUFFIX
value|".so"
end_define
begin_define
DECL|macro|PREFIX
define|#
directive|define
name|PREFIX
value|"lib"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|sys_qualifiedLibraryName
specifier|static
name|QString
name|sys_qualifiedLibraryName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
return|return
name|QFINDTESTDATA
argument_list|(
name|QString
argument_list|(
literal|"bin/%1%2%3"
argument_list|)
operator|.
name|arg
argument_list|(
name|PREFIX
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
operator|.
name|arg
argument_list|(
name|SUFFIX
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QPluginLoader
argument_list|)
end_macro
begin_class
DECL|class|tst_QPluginLoader
class|class
name|tst_QPluginLoader
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|errorString
parameter_list|()
function_decl|;
name|void
name|loadHints
parameter_list|()
function_decl|;
name|void
name|deleteinstanceOnUnload
parameter_list|()
function_decl|;
name|void
name|loadDebugObj
parameter_list|()
function_decl|;
name|void
name|loadCorruptElf
parameter_list|()
function_decl|;
name|void
name|loadGarbage
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|errorString
name|void
name|tst_QPluginLoader
operator|::
name|errorString
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
comment|// On WinCE we need an QCoreApplication object for current dir
name|int
name|argc
init|=
literal|0
decl_stmt|;
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
literal|0
argument_list|)
decl_stmt|;
endif|#
directive|endif
specifier|const
name|QString
name|unknown
argument_list|(
name|QLatin1String
argument_list|(
literal|"Unknown error"
argument_list|)
argument_list|)
decl_stmt|;
block|{
name|QPluginLoader
name|loader
decl_stmt|;
comment|// default constructed
name|bool
name|loaded
init|=
name|loader
operator|.
name|load
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|loader
operator|.
name|errorString
argument_list|()
argument_list|,
name|unknown
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|loaded
argument_list|)
expr_stmt|;
name|QObject
modifier|*
name|obj
init|=
name|loader
operator|.
name|instance
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|loader
operator|.
name|errorString
argument_list|()
argument_list|,
name|unknown
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj
argument_list|,
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|bool
name|unloaded
init|=
name|loader
operator|.
name|unload
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|loader
operator|.
name|errorString
argument_list|()
argument_list|,
name|unknown
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|unloaded
argument_list|)
expr_stmt|;
block|}
block|{
name|QPluginLoader
name|loader
argument_list|(
name|sys_qualifiedLibraryName
argument_list|(
literal|"tst_qpluginloaderlib"
argument_list|)
argument_list|)
decl_stmt|;
comment|//not a plugin
name|bool
name|loaded
init|=
name|loader
operator|.
name|load
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|loader
operator|.
name|errorString
argument_list|()
operator|!=
name|unknown
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|loaded
argument_list|)
expr_stmt|;
name|QObject
modifier|*
name|obj
init|=
name|loader
operator|.
name|instance
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|loader
operator|.
name|errorString
argument_list|()
operator|!=
name|unknown
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj
argument_list|,
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|bool
name|unloaded
init|=
name|loader
operator|.
name|unload
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|loader
operator|.
name|errorString
argument_list|()
operator|!=
name|unknown
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|unloaded
argument_list|)
expr_stmt|;
block|}
block|{
name|QPluginLoader
name|loader
argument_list|(
name|sys_qualifiedLibraryName
argument_list|(
literal|"nosuchfile"
argument_list|)
argument_list|)
decl_stmt|;
comment|//not a file
name|bool
name|loaded
init|=
name|loader
operator|.
name|load
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|loader
operator|.
name|errorString
argument_list|()
operator|!=
name|unknown
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|loaded
argument_list|)
expr_stmt|;
name|QObject
modifier|*
name|obj
init|=
name|loader
operator|.
name|instance
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|loader
operator|.
name|errorString
argument_list|()
operator|!=
name|unknown
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj
argument_list|,
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|bool
name|unloaded
init|=
name|loader
operator|.
name|unload
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|loader
operator|.
name|errorString
argument_list|()
operator|!=
name|unknown
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|unloaded
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
operator|!
name|defined
name|Q_OS_WIN
operator|&&
operator|!
name|defined
name|Q_OS_MAC
operator|&&
operator|!
name|defined
name|Q_OS_HPUX
block|{
name|QPluginLoader
name|loader
argument_list|(
name|sys_qualifiedLibraryName
argument_list|(
literal|"almostplugin"
argument_list|)
argument_list|)
decl_stmt|;
comment|//a plugin with unresolved symbols
name|loader
operator|.
name|setLoadHints
argument_list|(
name|QLibrary
operator|::
name|ResolveAllSymbolsHint
argument_list|)
expr_stmt|;
name|bool
name|loaded
init|=
name|loader
operator|.
name|load
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|loader
operator|.
name|errorString
argument_list|()
operator|!=
name|unknown
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|loaded
argument_list|)
expr_stmt|;
name|QObject
modifier|*
name|obj
init|=
name|loader
operator|.
name|instance
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|loader
operator|.
name|errorString
argument_list|()
operator|!=
name|unknown
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj
argument_list|,
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|bool
name|unloaded
init|=
name|loader
operator|.
name|unload
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|loader
operator|.
name|errorString
argument_list|()
operator|!=
name|unknown
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|unloaded
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|{
name|QPluginLoader
name|loader
argument_list|(
name|sys_qualifiedLibraryName
argument_list|(
literal|"theplugin"
argument_list|)
argument_list|)
decl_stmt|;
comment|//a plugin
name|QCOMPARE
argument_list|(
name|loader
operator|.
name|load
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|loader
operator|.
name|errorString
argument_list|()
argument_list|,
name|unknown
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|loader
operator|.
name|instance
argument_list|()
operator|!=
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|loader
operator|.
name|errorString
argument_list|()
argument_list|,
name|unknown
argument_list|)
expr_stmt|;
comment|// Make sure that plugin really works
name|PluginInterface
modifier|*
name|theplugin
init|=
name|qobject_cast
argument_list|<
name|PluginInterface
operator|*
argument_list|>
argument_list|(
name|loader
operator|.
name|instance
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|pluginName
init|=
name|theplugin
operator|->
name|pluginName
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|pluginName
argument_list|,
name|QLatin1String
argument_list|(
literal|"Plugin ok"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|loader
operator|.
name|unload
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|loader
operator|.
name|errorString
argument_list|()
argument_list|,
name|unknown
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|loadHints
name|void
name|tst_QPluginLoader
operator|::
name|loadHints
parameter_list|()
block|{
name|QPluginLoader
name|loader
decl_stmt|;
name|QCOMPARE
argument_list|(
name|loader
operator|.
name|loadHints
argument_list|()
argument_list|,
operator|(
name|QLibrary
operator|::
name|LoadHints
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|//Do not crash
name|loader
operator|.
name|setLoadHints
argument_list|(
name|QLibrary
operator|::
name|ResolveAllSymbolsHint
argument_list|)
expr_stmt|;
name|loader
operator|.
name|setFileName
argument_list|(
name|sys_qualifiedLibraryName
argument_list|(
literal|"theplugin"
argument_list|)
argument_list|)
expr_stmt|;
comment|//a plugin
name|QCOMPARE
argument_list|(
name|loader
operator|.
name|loadHints
argument_list|()
argument_list|,
name|QLibrary
operator|::
name|ResolveAllSymbolsHint
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|deleteinstanceOnUnload
name|void
name|tst_QPluginLoader
operator|::
name|deleteinstanceOnUnload
parameter_list|()
block|{
for|for
control|(
name|int
name|pass
init|=
literal|0
init|;
name|pass
operator|<
literal|2
condition|;
operator|++
name|pass
control|)
block|{
name|QPluginLoader
name|loader1
decl_stmt|;
name|loader1
operator|.
name|setFileName
argument_list|(
name|sys_qualifiedLibraryName
argument_list|(
literal|"theplugin"
argument_list|)
argument_list|)
expr_stmt|;
comment|//a plugin
if|if
condition|(
name|pass
operator|==
literal|0
condition|)
name|loader1
operator|.
name|load
argument_list|()
expr_stmt|;
comment|// not recommended, instance() should do the job.
name|PluginInterface
modifier|*
name|instance1
init|=
name|qobject_cast
argument_list|<
name|PluginInterface
operator|*
argument_list|>
argument_list|(
name|loader1
operator|.
name|instance
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|instance1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|instance1
operator|->
name|pluginName
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|"Plugin ok"
argument_list|)
argument_list|)
expr_stmt|;
name|QPluginLoader
name|loader2
decl_stmt|;
name|loader2
operator|.
name|setFileName
argument_list|(
name|sys_qualifiedLibraryName
argument_list|(
literal|"theplugin"
argument_list|)
argument_list|)
expr_stmt|;
comment|//a plugin
if|if
condition|(
name|pass
operator|==
literal|0
condition|)
name|loader2
operator|.
name|load
argument_list|()
expr_stmt|;
comment|// not recommended, instance() should do the job.
name|PluginInterface
modifier|*
name|instance2
init|=
name|qobject_cast
argument_list|<
name|PluginInterface
operator|*
argument_list|>
argument_list|(
name|loader2
operator|.
name|instance
argument_list|()
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|instance2
operator|->
name|pluginName
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|"Plugin ok"
argument_list|)
argument_list|)
expr_stmt|;
name|QSignalSpy
name|spy1
argument_list|(
name|loader1
operator|.
name|instance
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|spy2
argument_list|(
name|loader2
operator|.
name|instance
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|spy1
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|spy2
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|pass
operator|==
literal|0
condition|)
block|{
name|QCOMPARE
argument_list|(
name|loader2
operator|.
name|unload
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
comment|// refcount not reached 0, not really unloaded
name|QCOMPARE
argument_list|(
name|spy1
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy2
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|instance1
operator|->
name|pluginName
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|"Plugin ok"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|instance2
operator|->
name|pluginName
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|"Plugin ok"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|loader1
operator|.
name|unload
argument_list|()
argument_list|)
expr_stmt|;
comment|// refcount reached 0, did really unload
name|QCOMPARE
argument_list|(
name|spy1
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy2
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|loadDebugObj
name|void
name|tst_QPluginLoader
operator|::
name|loadDebugObj
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|__ELF__
argument_list|)
name|QVERIFY
argument_list|(
name|QFile
operator|::
name|exists
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"elftest/debugobj.so"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QPluginLoader
name|lib1
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"elftest/debugobj.so"
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|lib1
operator|.
name|load
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|loadCorruptElf
name|void
name|tst_QPluginLoader
operator|::
name|loadCorruptElf
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|__ELF__
argument_list|)
if|if
condition|(
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|==
literal|8
condition|)
block|{
name|QVERIFY
argument_list|(
name|QFile
operator|::
name|exists
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"elftest/corrupt1.elf64.so"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QPluginLoader
name|lib1
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"elftest/corrupt1.elf64.so"
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|lib1
operator|.
name|load
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|lib1
operator|.
name|errorString
argument_list|()
operator|.
name|contains
argument_list|(
literal|"not an ELF object"
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|lib1
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QPluginLoader
name|lib2
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"elftest/corrupt2.elf64.so"
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|lib2
operator|.
name|load
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|lib2
operator|.
name|errorString
argument_list|()
operator|.
name|contains
argument_list|(
literal|"invalid"
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|lib2
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QPluginLoader
name|lib3
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"elftest/corrupt3.elf64.so"
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|lib3
operator|.
name|load
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|lib3
operator|.
name|errorString
argument_list|()
operator|.
name|contains
argument_list|(
literal|"invalid"
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|lib3
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|==
literal|4
condition|)
block|{
name|QPluginLoader
name|libW
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"elftest/corrupt3.elf64.so"
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|libW
operator|.
name|load
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|libW
operator|.
name|errorString
argument_list|()
operator|.
name|contains
argument_list|(
literal|"architecture"
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|libW
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QFAIL
argument_list|(
literal|"Please port QElfParser to this platform or blacklist this test."
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|loadGarbage
name|void
name|tst_QPluginLoader
operator|::
name|loadGarbage
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|5
condition|;
name|i
operator|++
control|)
block|{
name|QPluginLoader
name|lib
argument_list|(
name|QFINDTESTDATA
argument_list|(
name|QString
argument_list|(
literal|"elftest/garbage%1.so"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|lib
operator|.
name|load
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lib
operator|.
name|errorString
argument_list|()
operator|!=
name|QString
argument_list|(
literal|"Unknown error"
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QPluginLoader
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qpluginloader.moc"
end_include
end_unit
