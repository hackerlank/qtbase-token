begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfactoryloader_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_include
include|#
directive|include
file|"qfactoryinterface.h"
end_include
begin_include
include|#
directive|include
file|"qmap.h"
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|"qmutex.h"
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
file|"private/qobject_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qcoreapplication_p.h"
end_include
begin_include
include|#
directive|include
file|"qjsondocument.h"
end_include
begin_include
include|#
directive|include
file|"qjsonvalue.h"
end_include
begin_include
include|#
directive|include
file|"qjsonobject.h"
end_include
begin_include
include|#
directive|include
file|"qjsonarray.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_GLOBAL_STATIC
argument_list|(
name|QList
argument_list|<
name|QFactoryLoader
operator|*
argument_list|>
argument_list|,
name|qt_factory_loaders
argument_list|)
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QMutex
argument_list|,
name|qt_factoryloader_mutex
argument_list|,
operator|(
name|QMutex
operator|::
name|Recursive
operator|)
argument_list|)
DECL|class|QFactoryLoaderPrivate
name|class
name|QFactoryLoaderPrivate
range|:
specifier|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QFactoryLoader
argument_list|)
specifier|public
operator|:
DECL|function|QFactoryLoaderPrivate
name|QFactoryLoaderPrivate
argument_list|()
block|{}
name|~
name|QFactoryLoaderPrivate
argument_list|()
block|;
DECL|member|mutex
name|mutable
name|QMutex
name|mutex
block|;
DECL|member|iid
name|QByteArray
name|iid
block|;
DECL|member|libraryList
name|QList
argument_list|<
name|QLibraryPrivate
operator|*
argument_list|>
name|libraryList
block|;
DECL|member|keyMap
name|QMap
argument_list|<
name|QString
argument_list|,
name|QLibraryPrivate
operator|*
argument_list|>
name|keyMap
block|;
DECL|member|suffix
name|QString
name|suffix
block|;
DECL|member|cs
name|Qt
operator|::
name|CaseSensitivity
name|cs
block|;
DECL|member|loadedPaths
name|QStringList
name|loadedPaths
block|;
name|void
name|unloadPath
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_destructor
DECL|function|~QFactoryLoaderPrivate
name|QFactoryLoaderPrivate
operator|::
name|~
name|QFactoryLoaderPrivate
parameter_list|()
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
name|libraryList
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QLibraryPrivate
modifier|*
name|library
init|=
name|libraryList
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|library
operator|->
name|unload
argument_list|()
expr_stmt|;
name|library
operator|->
name|release
argument_list|()
expr_stmt|;
block|}
block|}
end_destructor
begin_constructor
DECL|function|QFactoryLoader
name|QFactoryLoader
operator|::
name|QFactoryLoader
parameter_list|(
specifier|const
name|char
modifier|*
name|iid
parameter_list|,
specifier|const
name|QString
modifier|&
name|suffix
parameter_list|,
name|Qt
operator|::
name|CaseSensitivity
name|cs
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QFactoryLoaderPrivate
argument_list|)
block|{
name|moveToThread
argument_list|(
name|QCoreApplicationPrivate
operator|::
name|mainThread
argument_list|()
argument_list|)
expr_stmt|;
name|Q_D
argument_list|(
name|QFactoryLoader
argument_list|)
expr_stmt|;
name|d
operator|->
name|iid
operator|=
name|iid
expr_stmt|;
name|d
operator|->
name|cs
operator|=
name|cs
expr_stmt|;
name|d
operator|->
name|suffix
operator|=
name|suffix
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
name|qt_factoryloader_mutex
argument_list|()
argument_list|)
decl_stmt|;
name|update
argument_list|()
expr_stmt|;
name|qt_factory_loaders
argument_list|()
operator|->
name|append
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|update
name|void
name|QFactoryLoader
operator|::
name|update
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QT_SHARED
name|Q_D
argument_list|(
name|QFactoryLoader
argument_list|)
expr_stmt|;
name|QStringList
name|paths
init|=
name|QCoreApplication
operator|::
name|libraryPaths
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
name|paths
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QString
modifier|&
name|pluginDir
init|=
name|paths
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
comment|// Already loaded, skip it...
if|if
condition|(
name|d
operator|->
name|loadedPaths
operator|.
name|contains
argument_list|(
name|pluginDir
argument_list|)
condition|)
continue|continue;
name|d
operator|->
name|loadedPaths
operator|<<
name|pluginDir
expr_stmt|;
name|QString
name|path
init|=
name|pluginDir
operator|+
name|d
operator|->
name|suffix
decl_stmt|;
if|if
condition|(
name|qt_debug_component
argument_list|()
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"QFactoryLoader::QFactoryLoader() checking directory path"
operator|<<
name|path
operator|<<
literal|"..."
expr_stmt|;
if|if
condition|(
operator|!
name|QDir
argument_list|(
name|path
argument_list|)
operator|.
name|exists
argument_list|(
name|QLatin1String
argument_list|(
literal|"."
argument_list|)
argument_list|)
condition|)
continue|continue;
name|QStringList
name|plugins
init|=
name|QDir
argument_list|(
name|path
argument_list|)
operator|.
name|entryList
argument_list|(
name|QDir
operator|::
name|Files
argument_list|)
decl_stmt|;
name|QLibraryPrivate
modifier|*
name|library
init|=
literal|0
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_MAC
comment|// Loading both the debug and release version of the cocoa plugins causes the objective-c runtime
comment|// to print "duplicate class definitions" warnings. Detect if QFactoryLoader is about to load both,
comment|// skip one of them (below).
comment|//
comment|// ### FIXME find a proper solution
comment|//
specifier|const
name|bool
name|isLoadingDebugAndReleaseCocoa
init|=
name|plugins
operator|.
name|contains
argument_list|(
literal|"libqcocoa_debug.dylib"
argument_list|)
operator|&&
name|plugins
operator|.
name|contains
argument_list|(
literal|"libqcocoa.dylib"
argument_list|)
decl_stmt|;
endif|#
directive|endif
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|plugins
operator|.
name|count
argument_list|()
condition|;
operator|++
name|j
control|)
block|{
name|QString
name|fileName
init|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|path
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|plugins
operator|.
name|at
argument_list|(
name|j
argument_list|)
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_MAC
if|if
condition|(
name|isLoadingDebugAndReleaseCocoa
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_DEBUG
if|if
condition|(
name|fileName
operator|.
name|contains
argument_list|(
name|QStringLiteral
argument_list|(
literal|"libqcocoa.dylib"
argument_list|)
argument_list|)
condition|)
continue|continue;
comment|// Skip release plugin in debug mode
else|#
directive|else
if|if
condition|(
name|fileName
operator|.
name|contains
argument_list|(
name|QStringLiteral
argument_list|(
literal|"libqcocoa_debug.dylib"
argument_list|)
argument_list|)
condition|)
continue|continue;
comment|// Skip debug plugin in release mode
endif|#
directive|endif
block|}
endif|#
directive|endif
if|if
condition|(
name|qt_debug_component
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"QFactoryLoader::QFactoryLoader() looking at"
operator|<<
name|fileName
expr_stmt|;
block|}
name|library
operator|=
name|QLibraryPrivate
operator|::
name|findOrCreate
argument_list|(
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|canonicalFilePath
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|library
operator|->
name|isPlugin
argument_list|()
condition|)
block|{
if|if
condition|(
name|qt_debug_component
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
name|library
operator|->
name|errorString
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"         not a plugin"
expr_stmt|;
block|}
name|library
operator|->
name|release
argument_list|()
expr_stmt|;
continue|continue;
block|}
name|QStringList
name|keys
decl_stmt|;
name|bool
name|metaDataOk
init|=
literal|false
decl_stmt|;
name|QString
name|iid
init|=
name|library
operator|->
name|metaData
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"IID"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
name|iid
operator|==
name|QLatin1String
argument_list|(
name|d
operator|->
name|iid
operator|.
name|constData
argument_list|()
argument_list|,
name|d
operator|->
name|iid
operator|.
name|size
argument_list|()
argument_list|)
condition|)
block|{
name|QJsonObject
name|object
init|=
name|library
operator|->
name|metaData
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"MetaData"
argument_list|)
argument_list|)
operator|.
name|toObject
argument_list|()
decl_stmt|;
name|metaDataOk
operator|=
literal|true
expr_stmt|;
name|QJsonArray
name|k
init|=
name|object
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"Keys"
argument_list|)
argument_list|)
operator|.
name|toArray
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
name|k
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|keys
operator|+=
name|d
operator|->
name|cs
condition|?
name|k
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toString
argument_list|()
else|:
name|k
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|toLower
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|qt_debug_component
argument_list|()
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"Got keys from plugin meta data"
operator|<<
name|keys
expr_stmt|;
if|if
condition|(
operator|!
name|metaDataOk
condition|)
block|{
name|library
operator|->
name|release
argument_list|()
expr_stmt|;
continue|continue;
block|}
name|int
name|keyUsageCount
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|k
init|=
literal|0
init|;
name|k
operator|<
name|keys
operator|.
name|count
argument_list|()
condition|;
operator|++
name|k
control|)
block|{
comment|// first come first serve, unless the first
comment|// library was built with a future Qt version,
comment|// whereas the new one has a Qt version that fits
comment|// better
specifier|const
name|QString
modifier|&
name|key
init|=
name|keys
operator|.
name|at
argument_list|(
name|k
argument_list|)
decl_stmt|;
name|QLibraryPrivate
modifier|*
name|previous
init|=
name|d
operator|->
name|keyMap
operator|.
name|value
argument_list|(
name|key
argument_list|)
decl_stmt|;
name|int
name|prev_qt_version
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|previous
condition|)
block|{
name|prev_qt_version
operator|=
operator|(
name|int
operator|)
name|previous
operator|->
name|metaData
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"version"
argument_list|)
argument_list|)
operator|.
name|toDouble
argument_list|()
expr_stmt|;
block|}
name|int
name|qt_version
init|=
operator|(
name|int
operator|)
name|library
operator|->
name|metaData
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"version"
argument_list|)
argument_list|)
operator|.
name|toDouble
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|previous
operator|||
operator|(
name|prev_qt_version
operator|>
name|QT_VERSION
operator|&&
name|qt_version
operator|<=
name|QT_VERSION
operator|)
condition|)
block|{
name|d
operator|->
name|keyMap
index|[
name|key
index|]
operator|=
name|library
expr_stmt|;
operator|++
name|keyUsageCount
expr_stmt|;
block|}
block|}
if|if
condition|(
name|keyUsageCount
operator|||
name|keys
operator|.
name|isEmpty
argument_list|()
condition|)
name|d
operator|->
name|libraryList
operator|+=
name|library
expr_stmt|;
else|else
name|library
operator|->
name|release
argument_list|()
expr_stmt|;
block|}
block|}
else|#
directive|else
name|Q_D
argument_list|(
name|QFactoryLoader
argument_list|)
expr_stmt|;
if|if
condition|(
name|qt_debug_component
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"QFactoryLoader::QFactoryLoader() ignoring"
operator|<<
name|d
operator|->
name|iid
operator|<<
literal|"since plugins are disabled in static builds"
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_destructor
DECL|function|~QFactoryLoader
name|QFactoryLoader
operator|::
name|~
name|QFactoryLoader
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
name|qt_factoryloader_mutex
argument_list|()
argument_list|)
decl_stmt|;
name|qt_factory_loaders
argument_list|()
operator|->
name|removeAll
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|metaData
name|QList
argument_list|<
name|QJsonObject
argument_list|>
name|QFactoryLoader
operator|::
name|metaData
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFactoryLoader
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QJsonObject
argument_list|>
name|metaData
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
name|d
operator|->
name|libraryList
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|metaData
operator|.
name|append
argument_list|(
name|d
operator|->
name|libraryList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|metaData
argument_list|)
expr_stmt|;
name|QVector
argument_list|<
name|QStaticPlugin
argument_list|>
name|staticPlugins
init|=
name|QLibraryPrivate
operator|::
name|staticPlugins
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
name|staticPlugins
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|char
modifier|*
name|rawMetaData
init|=
name|staticPlugins
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|metaData
argument_list|()
decl_stmt|;
name|QJsonObject
name|object
init|=
name|QLibraryPrivate
operator|::
name|fromRawMetaData
argument_list|(
name|rawMetaData
argument_list|)
operator|.
name|object
argument_list|()
decl_stmt|;
if|if
condition|(
name|object
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"IID"
argument_list|)
argument_list|)
operator|!=
name|QLatin1String
argument_list|(
name|d
operator|->
name|iid
operator|.
name|constData
argument_list|()
argument_list|,
name|d
operator|->
name|iid
operator|.
name|size
argument_list|()
argument_list|)
condition|)
continue|continue;
name|metaData
operator|.
name|append
argument_list|(
name|object
argument_list|)
expr_stmt|;
block|}
return|return
name|metaData
return|;
block|}
end_function
begin_function
DECL|function|instance
name|QObject
modifier|*
name|QFactoryLoader
operator|::
name|instance
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFactoryLoader
argument_list|)
expr_stmt|;
if|if
condition|(
name|index
operator|<
literal|0
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|index
operator|<
name|d
operator|->
name|libraryList
operator|.
name|size
argument_list|()
condition|)
block|{
name|QLibraryPrivate
modifier|*
name|library
init|=
name|d
operator|->
name|libraryList
operator|.
name|at
argument_list|(
name|index
argument_list|)
decl_stmt|;
if|if
condition|(
name|library
operator|->
name|instance
operator|||
name|library
operator|->
name|loadPlugin
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|library
operator|->
name|inst
condition|)
name|library
operator|->
name|inst
operator|=
name|library
operator|->
name|instance
argument_list|()
expr_stmt|;
name|QObject
modifier|*
name|obj
init|=
name|library
operator|->
name|inst
operator|.
name|data
argument_list|()
decl_stmt|;
if|if
condition|(
name|obj
condition|)
block|{
if|if
condition|(
operator|!
name|obj
operator|->
name|parent
argument_list|()
condition|)
name|obj
operator|->
name|moveToThread
argument_list|(
name|QCoreApplicationPrivate
operator|::
name|mainThread
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|obj
return|;
block|}
block|}
return|return
literal|0
return|;
block|}
name|index
operator|-=
name|d
operator|->
name|libraryList
operator|.
name|size
argument_list|()
expr_stmt|;
name|QVector
argument_list|<
name|QStaticPlugin
argument_list|>
name|staticPlugins
init|=
name|QLibraryPrivate
operator|::
name|staticPlugins
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
name|staticPlugins
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|char
modifier|*
name|rawMetaData
init|=
name|staticPlugins
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|metaData
argument_list|()
decl_stmt|;
name|QJsonObject
name|object
init|=
name|QLibraryPrivate
operator|::
name|fromRawMetaData
argument_list|(
name|rawMetaData
argument_list|)
operator|.
name|object
argument_list|()
decl_stmt|;
if|if
condition|(
name|object
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"IID"
argument_list|)
argument_list|)
operator|!=
name|QLatin1String
argument_list|(
name|d
operator|->
name|iid
operator|.
name|constData
argument_list|()
argument_list|,
name|d
operator|->
name|iid
operator|.
name|size
argument_list|()
argument_list|)
condition|)
continue|continue;
if|if
condition|(
name|index
operator|==
literal|0
condition|)
return|return
name|staticPlugins
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|instance
argument_list|()
return|;
operator|--
name|index
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_function
DECL|function|library
name|QLibraryPrivate
modifier|*
name|QFactoryLoader
operator|::
name|library
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFactoryLoader
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|keyMap
operator|.
name|value
argument_list|(
name|d
operator|->
name|cs
condition|?
name|key
else|:
name|key
operator|.
name|toLower
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|refreshAll
name|void
name|QFactoryLoader
operator|::
name|refreshAll
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
name|qt_factoryloader_mutex
argument_list|()
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QFactoryLoader
modifier|*
argument_list|>
modifier|*
name|loaders
init|=
name|qt_factory_loaders
argument_list|()
decl_stmt|;
for|for
control|(
name|QList
argument_list|<
name|QFactoryLoader
operator|*
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|loaders
operator|->
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|loaders
operator|->
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
operator|(
operator|*
name|it
operator|)
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|keyMap
name|QMultiMap
argument_list|<
name|int
argument_list|,
name|QString
argument_list|>
name|QFactoryLoader
operator|::
name|keyMap
parameter_list|()
specifier|const
block|{
name|QMultiMap
argument_list|<
name|int
argument_list|,
name|QString
argument_list|>
name|result
decl_stmt|;
specifier|const
name|QString
name|metaDataKey
init|=
name|QStringLiteral
argument_list|(
literal|"MetaData"
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|keysKey
init|=
name|QStringLiteral
argument_list|(
literal|"Keys"
argument_list|)
decl_stmt|;
specifier|const
name|QList
argument_list|<
name|QJsonObject
argument_list|>
name|metaDataList
init|=
name|metaData
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
name|metaDataList
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QJsonObject
name|metaData
init|=
name|metaDataList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|value
argument_list|(
name|metaDataKey
argument_list|)
operator|.
name|toObject
argument_list|()
decl_stmt|;
specifier|const
name|QJsonArray
name|keys
init|=
name|metaData
operator|.
name|value
argument_list|(
name|keysKey
argument_list|)
operator|.
name|toArray
argument_list|()
decl_stmt|;
specifier|const
name|int
name|keyCount
init|=
name|keys
operator|.
name|size
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|k
init|=
literal|0
init|;
name|k
operator|<
name|keyCount
condition|;
operator|++
name|k
control|)
name|result
operator|.
name|insert
argument_list|(
name|i
argument_list|,
name|keys
operator|.
name|at
argument_list|(
name|k
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|indexOf
name|int
name|QFactoryLoader
operator|::
name|indexOf
parameter_list|(
specifier|const
name|QString
modifier|&
name|needle
parameter_list|)
specifier|const
block|{
specifier|const
name|QString
name|metaDataKey
init|=
name|QStringLiteral
argument_list|(
literal|"MetaData"
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|keysKey
init|=
name|QStringLiteral
argument_list|(
literal|"Keys"
argument_list|)
decl_stmt|;
specifier|const
name|QList
argument_list|<
name|QJsonObject
argument_list|>
name|metaDataList
init|=
name|metaData
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
name|metaDataList
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QJsonObject
name|metaData
init|=
name|metaDataList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|value
argument_list|(
name|metaDataKey
argument_list|)
operator|.
name|toObject
argument_list|()
decl_stmt|;
specifier|const
name|QJsonArray
name|keys
init|=
name|metaData
operator|.
name|value
argument_list|(
name|keysKey
argument_list|)
operator|.
name|toArray
argument_list|()
decl_stmt|;
specifier|const
name|int
name|keyCount
init|=
name|keys
operator|.
name|size
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|k
init|=
literal|0
init|;
name|k
operator|<
name|keyCount
condition|;
operator|++
name|k
control|)
block|{
if|if
condition|(
operator|!
name|keys
operator|.
name|at
argument_list|(
name|k
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|compare
argument_list|(
name|needle
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
return|return
name|i
return|;
block|}
block|}
return|return
operator|-
literal|1
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
