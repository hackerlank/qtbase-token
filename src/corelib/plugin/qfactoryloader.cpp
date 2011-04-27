begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qsettings.h>
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
DECL|member|keyList
name|QStringList
name|keyList
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
name|libraryList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|release
argument_list|()
expr_stmt|;
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
name|QSettings
name|settings
argument_list|(
name|QSettings
operator|::
name|UserScope
argument_list|,
name|QLatin1String
argument_list|(
literal|"Trolltech"
argument_list|)
argument_list|)
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
argument_list|(
operator|&
name|settings
argument_list|)
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
name|QString
name|regkey
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Qt Factory Cache %1.%2/%3:/%4"
argument_list|)
operator|.
name|arg
argument_list|(
operator|(
name|QT_VERSION
operator|&
literal|0xff0000
operator|)
operator|>>
literal|16
argument_list|)
operator|.
name|arg
argument_list|(
operator|(
name|QT_VERSION
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|d
operator|->
name|iid
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
name|QStringList
name|reg
decl_stmt|,
name|keys
decl_stmt|;
name|reg
operator|=
name|settings
operator|.
name|value
argument_list|(
name|regkey
argument_list|)
operator|.
name|toStringList
argument_list|()
expr_stmt|;
if|if
condition|(
name|reg
operator|.
name|count
argument_list|()
operator|&&
name|library
operator|->
name|lastModified
operator|==
name|reg
index|[
literal|0
index|]
condition|)
block|{
name|keys
operator|=
name|reg
expr_stmt|;
name|keys
operator|.
name|removeFirst
argument_list|()
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|library
operator|->
name|loadPlugin
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
literal|"           could not load"
expr_stmt|;
block|}
name|library
operator|->
name|release
argument_list|()
expr_stmt|;
continue|continue;
block|}
name|QObject
modifier|*
name|instance
init|=
name|library
operator|->
name|instance
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|instance
condition|)
block|{
name|library
operator|->
name|release
argument_list|()
expr_stmt|;
comment|// ignore plugins that have a valid signature but cannot be loaded.
continue|continue;
block|}
name|QFactoryInterface
modifier|*
name|factory
init|=
name|qobject_cast
argument_list|<
name|QFactoryInterface
operator|*
argument_list|>
argument_list|(
name|instance
argument_list|)
decl_stmt|;
if|if
condition|(
name|instance
operator|&&
name|factory
operator|&&
name|instance
operator|->
name|qt_metacast
argument_list|(
name|d
operator|->
name|iid
argument_list|)
condition|)
name|keys
operator|=
name|factory
operator|->
name|keys
argument_list|()
expr_stmt|;
if|if
condition|(
name|keys
operator|.
name|isEmpty
argument_list|()
condition|)
name|library
operator|->
name|unload
argument_list|()
expr_stmt|;
name|reg
operator|.
name|clear
argument_list|()
expr_stmt|;
name|reg
operator|<<
name|library
operator|->
name|lastModified
expr_stmt|;
name|reg
operator|+=
name|keys
expr_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
name|regkey
argument_list|,
name|reg
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|qt_debug_component
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"keys"
operator|<<
name|keys
expr_stmt|;
block|}
if|if
condition|(
name|keys
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|library
operator|->
name|release
argument_list|()
expr_stmt|;
continue|continue;
block|}
name|d
operator|->
name|libraryList
operator|+=
name|library
expr_stmt|;
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
name|QString
name|key
init|=
name|keys
operator|.
name|at
argument_list|(
name|k
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|cs
condition|)
name|key
operator|=
name|key
operator|.
name|toLower
argument_list|()
expr_stmt|;
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
if|if
condition|(
operator|!
name|previous
operator|||
operator|(
name|previous
operator|->
name|qt_version
operator|>
name|QT_VERSION
operator|&&
name|library
operator|->
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
name|d
operator|->
name|keyList
operator|+=
name|keys
operator|.
name|at
argument_list|(
name|k
argument_list|)
expr_stmt|;
block|}
block|}
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
DECL|function|keys
name|QStringList
name|QFactoryLoader
operator|::
name|keys
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
name|QStringList
name|keys
init|=
name|d
operator|->
name|keyList
decl_stmt|;
name|QObjectList
name|instances
init|=
name|QPluginLoader
operator|::
name|staticInstances
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
name|instances
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|QFactoryInterface
modifier|*
name|factory
init|=
name|qobject_cast
argument_list|<
name|QFactoryInterface
operator|*
argument_list|>
argument_list|(
name|instances
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
if|if
condition|(
name|instances
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|qt_metacast
argument_list|(
name|d
operator|->
name|iid
argument_list|)
condition|)
name|keys
operator|+=
name|factory
operator|->
name|keys
argument_list|()
expr_stmt|;
return|return
name|keys
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
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|QObjectList
name|instances
init|=
name|QPluginLoader
operator|::
name|staticInstances
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
name|instances
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|QFactoryInterface
modifier|*
name|factory
init|=
name|qobject_cast
argument_list|<
name|QFactoryInterface
operator|*
argument_list|>
argument_list|(
name|instances
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
if|if
condition|(
name|instances
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|qt_metacast
argument_list|(
name|d
operator|->
name|iid
argument_list|)
operator|&&
name|factory
operator|->
name|keys
argument_list|()
operator|.
name|contains
argument_list|(
name|key
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
return|return
name|instances
operator|.
name|at
argument_list|(
name|i
argument_list|)
return|;
name|QString
name|lowered
init|=
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
decl_stmt|;
if|if
condition|(
name|QLibraryPrivate
modifier|*
name|library
init|=
name|d
operator|->
name|keyMap
operator|.
name|value
argument_list|(
name|lowered
argument_list|)
condition|)
block|{
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
name|QObject
modifier|*
name|obj
init|=
name|library
operator|->
name|instance
argument_list|()
condition|)
block|{
if|if
condition|(
name|obj
operator|&&
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
block|}
return|return
literal|0
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_X11
end_ifdef
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
