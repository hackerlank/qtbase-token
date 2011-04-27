begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qplugin.h"
end_include
begin_include
include|#
directive|include
file|"qpluginloader.h"
end_include
begin_include
include|#
directive|include
file|<qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|"qlibrary_p.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|"qdir.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
end_if
begin_include
include|#
directive|include
file|<f32file.h>
end_include
begin_include
include|#
directive|include
file|"private/qcore_symbian_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QPluginLoader     \reentrant     \brief The QPluginLoader class loads a plugin at run-time.       \ingroup plugins      QPluginLoader provides access to a \l{How to Create Qt     Plugins}{Qt plugin}. A Qt plugin is stored in a shared library (a     DLL) and offers these benefits over shared libraries accessed     using QLibrary:      \list     \o QPluginLoader checks that a plugin is linked against the same        version of Qt as the application.     \o QPluginLoader provides direct access to a root component object        (instance()), instead of forcing you to resolve a C function manually.     \endlist      An instance of a QPluginLoader object operates on a single shared     library file, which we call a plugin. It provides access to the     functionality in the plugin in a platform-independent way. To     specify which plugin to load, either pass a file name in     the constructor or set it with setFileName().      The most important functions are load() to dynamically load the     plugin file, isLoaded() to check whether loading was successful,     and instance() to access the root component in the plugin. The     instance() function implicitly tries to load the plugin if it has     not been loaded yet. Multiple instances of QPluginLoader can be     used to access the same physical plugin.      Once loaded, plugins remain in memory until all instances of     QPluginLoader has been unloaded, or until the application     terminates. You can attempt to unload a plugin using unload(),     but if other instances of QPluginLoader are using the same     library, the call will fail, and unloading will only happen when     every instance has called unload(). Right before the unloading     happen, the root component will also be deleted.      In order to speed up loading and validation of plugins, some of     the information that is collected during loading is cached in     persistent memory (through QSettings). For instance, the result     of a load operation (e.g. succeeded or failed) is stored in the     cache, so that subsequent load operations don't try to load an     invalid plugin. However, if the "last modified" timestamp of     a plugin has changed, the plugin's cache entry is invalidated     and the plugin is reloaded regardless of the values in the cache     entry. The cache entry is then updated with the new result of the     load operation.      This also means that the timestamp must be updated each time the     plugin or any dependent resources (such as a shared library) is     updated, since the dependent resources might influence the result     of loading a plugin.      See \l{How to Create Qt Plugins} for more information about     how to make your application extensible through plugins.      Note that the QPluginLoader cannot be used if your application is     statically linked against Qt. In this case, you will also have to     link to plugins statically. You can use QLibrary if you need to     load dynamic libraries in a statically linked application.      \note In Symbian the plugin stub files must be used whenever a     path to plugin is needed. For the purposes of loading plugins,     the stubs can be considered to have the same name as the actual     plugin binary. In practice they have ".qtplugin" extension     instead of ".dll", but this difference is handled transparently     by QPluginLoader and QLibrary to avoid need for Symbian specific     plugin handling in most Qt applications. Plugin stubs are needed     because Symbian Platform Security denies all access to the directory     where the actual plugin binaries are located.      \sa QLibrary, {Plug& Paint Example} */
end_comment
begin_comment
comment|/*!     Constructs a plugin loader with the given \a parent. */
end_comment
begin_constructor
DECL|function|QPluginLoader
name|QPluginLoader
operator|::
name|QPluginLoader
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|d
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|did_load
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a plugin loader with the given \a parent that will     load the plugin specified by \a fileName.      To be loadable, the file's suffix must be a valid suffix for a     loadable library in accordance with the platform, e.g. \c .so on     Unix, - \c .dylib on Mac OS X, and \c .dll on Windows. The suffix     can be verified with QLibrary::isLibrary().      Note: In Symbian the \a fileName must point to plugin stub file.      \sa setFileName() */
end_comment
begin_constructor
DECL|function|QPluginLoader
name|QPluginLoader
operator|::
name|QPluginLoader
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|d
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|did_load
argument_list|(
literal|false
argument_list|)
block|{
name|setFileName
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the QPluginLoader object.      Unless unload() was called explicitly, the plugin stays in memory     until the application terminates.      \sa isLoaded(), unload() */
end_comment
begin_destructor
DECL|function|~QPluginLoader
name|QPluginLoader
operator|::
name|~
name|QPluginLoader
parameter_list|()
block|{
if|if
condition|(
name|d
condition|)
name|d
operator|->
name|release
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Returns the root component object of the plugin. The plugin is     loaded if necessary. The function returns 0 if the plugin could     not be loaded or if the root component object could not be     instantiated.      If the root component object was destroyed, calling this function     creates a new instance.      The root component, returned by this function, is not deleted when     the QPluginLoader is destroyed. If you want to ensure that the root     component is deleted, you should call unload() as soon you don't     need to access the core component anymore.  When the library is     finally unloaded, the root component will automatically be deleted.      The component object is a QObject. Use qobject_cast() to access     interfaces you are interested in.      \sa load() */
end_comment
begin_function
DECL|function|instance
name|QObject
modifier|*
name|QPluginLoader
operator|::
name|instance
parameter_list|()
block|{
if|if
condition|(
operator|!
name|isLoaded
argument_list|()
operator|&&
operator|!
name|load
argument_list|()
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|d
operator|->
name|inst
operator|&&
name|d
operator|->
name|instance
condition|)
name|d
operator|->
name|inst
operator|=
name|d
operator|->
name|instance
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|inst
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Loads the plugin and returns true if the plugin was loaded     successfully; otherwise returns false. Since instance() always     calls this function before resolving any symbols it is not     necessary to call it explicitly. In some situations you might want     the plugin loaded in advance, in which case you would use this     function.      \sa unload() */
end_comment
begin_function
DECL|function|load
name|bool
name|QPluginLoader
operator|::
name|load
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|||
name|d
operator|->
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|did_load
condition|)
return|return
name|d
operator|->
name|pHnd
operator|&&
name|d
operator|->
name|instance
return|;
if|if
condition|(
operator|!
name|d
operator|->
name|isPlugin
argument_list|()
condition|)
return|return
literal|false
return|;
name|did_load
operator|=
literal|true
expr_stmt|;
return|return
name|d
operator|->
name|loadPlugin
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Unloads the plugin and returns true if the plugin could be     unloaded; otherwise returns false.      This happens automatically on application termination, so you     shouldn't normally need to call this function.      If other instances of QPluginLoader are using the same plugin, the     call will fail, and unloading will only happen when every instance     has called unload().      Don't try to delete the root component. Instead rely on     that unload() will automatically delete it when needed.      \sa instance(), load() */
end_comment
begin_function
DECL|function|unload
name|bool
name|QPluginLoader
operator|::
name|unload
parameter_list|()
block|{
if|if
condition|(
name|did_load
condition|)
block|{
name|did_load
operator|=
literal|false
expr_stmt|;
return|return
name|d
operator|->
name|unload
argument_list|()
return|;
block|}
if|if
condition|(
name|d
condition|)
comment|// Ouch
name|d
operator|->
name|errorString
operator|=
name|tr
argument_list|(
literal|"The plugin was not loaded."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the plugin is loaded; otherwise returns false.      \sa load()  */
end_comment
begin_function
DECL|function|isLoaded
name|bool
name|QPluginLoader
operator|::
name|isLoaded
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|&&
name|d
operator|->
name|pHnd
operator|&&
name|d
operator|->
name|instance
return|;
block|}
end_function
begin_comment
comment|/*!     \property QPluginLoader::fileName     \brief the file name of the plugin      To be loadable, the file's suffix must be a valid suffix for a     loadable library in accordance with the platform, e.g. \c .so on     Unix, \c .dylib on Mac OS X, and \c .dll on Windows. The suffix     can be verified with QLibrary::isLibrary().      If the file name does not exist, it will not be set. This property     will then contain an empty string.      By default, this property contains an empty string.      Note: In Symbian the \a fileName must point to plugin stub file.      \sa load() */
end_comment
begin_function
DECL|function|setFileName
name|void
name|QPluginLoader
operator|::
name|setFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QT_SHARED
argument_list|)
name|QLibrary
operator|::
name|LoadHints
name|lh
decl_stmt|;
if|if
condition|(
name|d
condition|)
block|{
name|lh
operator|=
name|d
operator|->
name|loadHints
expr_stmt|;
name|d
operator|->
name|release
argument_list|()
expr_stmt|;
name|d
operator|=
literal|0
expr_stmt|;
name|did_load
operator|=
literal|false
expr_stmt|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
comment|// In Symbian we actually look for plugin stub, so modify the filename
comment|// to make canonicalFilePath find the file, if .dll is specified.
name|QFileInfo
name|fi
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|fi
operator|.
name|suffix
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"dll"
argument_list|)
condition|)
block|{
name|QString
name|stubName
init|=
name|fileName
decl_stmt|;
name|stubName
operator|.
name|chop
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|stubName
operator|+=
name|QLatin1String
argument_list|(
literal|"qtplugin"
argument_list|)
expr_stmt|;
name|fi
operator|=
name|QFileInfo
argument_list|(
name|stubName
argument_list|)
expr_stmt|;
block|}
name|QString
name|fn
init|=
name|fi
operator|.
name|canonicalFilePath
argument_list|()
decl_stmt|;
comment|// If not found directly, check also all the available drives
if|if
condition|(
operator|!
name|fn
operator|.
name|length
argument_list|()
condition|)
block|{
name|QString
name|stubPath
argument_list|(
name|fi
operator|.
name|fileName
argument_list|()
operator|.
name|length
argument_list|()
condition|?
name|fi
operator|.
name|absoluteFilePath
argument_list|()
else|:
name|QString
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|stubPath
operator|.
name|length
argument_list|()
operator|>
literal|1
condition|)
block|{
if|if
condition|(
name|stubPath
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toAscii
argument_list|()
operator|==
literal|':'
condition|)
name|stubPath
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QFileInfoList
name|driveList
argument_list|(
name|QDir
operator|::
name|drives
argument_list|()
argument_list|)
decl_stmt|;
name|RFs
name|rfs
init|=
name|qt_s60GetRFs
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QFileInfo
modifier|&
name|drive
decl|,
name|driveList
control|)
block|{
name|QString
name|testFilePath
argument_list|(
name|drive
operator|.
name|absolutePath
argument_list|()
operator|+
name|stubPath
argument_list|)
decl_stmt|;
name|testFilePath
operator|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|testFilePath
argument_list|)
expr_stmt|;
comment|// Use native Symbian code to check for file existence, because checking
comment|// for file from under non-existent protected dir like E:/private/<uid> using
comment|// QFile::exists causes platform security violations on most apps.
name|QString
name|nativePath
init|=
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|testFilePath
argument_list|)
decl_stmt|;
name|TPtrC
name|ptr
argument_list|(
name|qt_QString2TPtrC
argument_list|(
name|nativePath
argument_list|)
argument_list|)
decl_stmt|;
name|TUint
name|attributes
decl_stmt|;
name|TInt
name|err
init|=
name|rfs
operator|.
name|Att
argument_list|(
name|ptr
argument_list|,
name|attributes
argument_list|)
decl_stmt|;
if|if
condition|(
name|err
operator|==
name|KErrNone
condition|)
block|{
name|fn
operator|=
name|testFilePath
expr_stmt|;
break|break;
block|}
block|}
block|}
block|}
else|#
directive|else
name|QString
name|fn
init|=
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|canonicalFilePath
argument_list|()
decl_stmt|;
endif|#
directive|endif
name|d
operator|=
name|QLibraryPrivate
operator|::
name|findOrCreate
argument_list|(
name|fn
argument_list|)
expr_stmt|;
name|d
operator|->
name|loadHints
operator|=
name|lh
expr_stmt|;
if|if
condition|(
name|fn
operator|.
name|isEmpty
argument_list|()
condition|)
name|d
operator|->
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"The shared library was not found."
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|qt_debug_component
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"Cannot load %s into a statically linked Qt library."
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
name|QFile
operator|::
name|encodeName
argument_list|(
name|fileName
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|Q_UNUSED
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|fileName
name|QString
name|QPluginLoader
operator|::
name|fileName
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|d
condition|)
return|return
name|d
operator|->
name|fileName
return|;
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.2      Returns a text string with the description of the last error that occurred. */
end_comment
begin_function
DECL|function|errorString
name|QString
name|QPluginLoader
operator|::
name|errorString
parameter_list|()
specifier|const
block|{
return|return
operator|(
operator|!
name|d
operator|||
name|d
operator|->
name|errorString
operator|.
name|isEmpty
argument_list|()
operator|)
condition|?
name|tr
argument_list|(
literal|"Unknown error"
argument_list|)
else|:
name|d
operator|->
name|errorString
return|;
block|}
end_function
begin_typedef
DECL|typedef|StaticInstanceFunctionList
typedef|typedef
name|QList
argument_list|<
name|QtPluginInstanceFunction
argument_list|>
name|StaticInstanceFunctionList
typedef|;
end_typedef
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|StaticInstanceFunctionList
argument_list|,
argument|staticInstanceFunctionList
argument_list|)
end_macro
begin_comment
comment|/*! \since 4.4      \property QPluginLoader::loadHints     \brief Give the load() function some hints on how it should behave.      You can give hints on how the symbols in the plugin are     resolved. By default, none of the hints are set.      See the documentation of QLibrary::loadHints for a complete     description of how this property works.      \sa QLibrary::loadHints */
end_comment
begin_function
DECL|function|setLoadHints
name|void
name|QPluginLoader
operator|::
name|setLoadHints
parameter_list|(
name|QLibrary
operator|::
name|LoadHints
name|loadHints
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
block|{
name|d
operator|=
name|QLibraryPrivate
operator|::
name|findOrCreate
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
comment|// ugly, but we need a d-ptr
name|d
operator|->
name|errorString
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|d
operator|->
name|loadHints
operator|=
name|loadHints
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loadHints
name|QLibrary
operator|::
name|LoadHints
name|QPluginLoader
operator|::
name|loadHints
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
block|{
name|QPluginLoader
modifier|*
name|that
init|=
cast|const_cast
argument_list|<
name|QPluginLoader
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|that
operator|->
name|d
operator|=
name|QLibraryPrivate
operator|::
name|findOrCreate
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
comment|// ugly, but we need a d-ptr
name|that
operator|->
name|d
operator|->
name|errorString
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
return|return
name|d
operator|->
name|loadHints
return|;
block|}
end_function
begin_comment
comment|/*!     \relates QPluginLoader     \since 4.4      Registers the given \a function with the plugin loader. */
end_comment
begin_function
DECL|function|qRegisterStaticPluginInstanceFunction
name|void
name|Q_CORE_EXPORT
name|qRegisterStaticPluginInstanceFunction
parameter_list|(
name|QtPluginInstanceFunction
name|function
parameter_list|)
block|{
name|staticInstanceFunctionList
argument_list|()
operator|->
name|append
argument_list|(
name|function
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns a list of static plugin instances (root components) held     by the plugin loader. */
end_comment
begin_function
DECL|function|staticInstances
name|QObjectList
name|QPluginLoader
operator|::
name|staticInstances
parameter_list|()
block|{
name|QObjectList
name|instances
decl_stmt|;
name|StaticInstanceFunctionList
modifier|*
name|functions
init|=
name|staticInstanceFunctionList
argument_list|()
decl_stmt|;
if|if
condition|(
name|functions
condition|)
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
name|functions
operator|->
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|instances
operator|.
name|append
argument_list|(
argument|(*functions)[i]()
argument_list|)
expr_stmt|;
block|}
return|return
name|instances
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LIBRARY
end_comment
end_unit
