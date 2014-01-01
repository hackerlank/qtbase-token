begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOREAPPLICATION_P_H
end_ifndef
begin_define
DECL|macro|QCOREAPPLICATION_P_H
define|#
directive|define
name|QCOREAPPLICATION_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtCore/qcoreapplication.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qtranslator.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qsettings.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
end_ifndef
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|QTranslatorList
typedef|typedef
name|QList
operator|<
name|QTranslator
operator|*
operator|>
name|QTranslatorList
expr_stmt|;
end_typedef
begin_decl_stmt
DECL|variable|QAbstractEventDispatcher
name|class
name|QAbstractEventDispatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QCoreApplicationPrivate
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
range|:
name|public
name|QObjectPrivate
endif|#
directive|endif
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QCoreApplication
argument_list|)
name|public
operator|:
expr|enum
name|Type
block|{
name|Tty
block|,
name|Gui
block|}
block|;
name|QCoreApplicationPrivate
argument_list|(
argument|int&aargc
argument_list|,
argument|char **aargv
argument_list|,
argument|uint flags
argument_list|)
block|;
operator|~
name|QCoreApplicationPrivate
argument_list|()
block|;
name|QString
name|appName
argument_list|()
specifier|const
block|;
ifdef|#
directive|ifdef
name|Q_OS_MAC
specifier|static
name|QString
name|macMenuBarName
argument_list|()
block|;
endif|#
directive|endif
specifier|static
name|void
name|initLocale
argument_list|()
block|;
specifier|static
name|bool
name|checkInstance
argument_list|(
specifier|const
name|char
operator|*
name|method
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
name|bool
name|sendThroughApplicationEventFilters
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
name|bool
name|sendThroughObjectEventFilters
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
name|bool
name|notify_helper
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
name|virtual
name|void
name|createEventDispatcher
argument_list|()
block|;
name|virtual
name|void
name|eventDispatcherReady
argument_list|()
block|;
specifier|static
name|void
name|removePostedEvent
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
specifier|static
name|void
name|removePostedTimerEvent
argument_list|(
argument|QObject *object
argument_list|,
argument|int timerId
argument_list|)
block|;
endif|#
directive|endif
name|QAtomicInt
name|quitLockRef
block|;
name|void
name|ref
argument_list|()
block|;
name|void
name|deref
argument_list|()
block|;
name|virtual
name|bool
name|shouldQuit
argument_list|()
block|{
return|return
name|true
return|;
block|}
name|void
name|maybeQuit
argument_list|()
block|;
specifier|static
name|QThread
operator|*
name|theMainThread
block|;
specifier|static
name|QThread
operator|*
name|mainThread
argument_list|()
block|;
specifier|static
name|void
name|sendPostedEvents
argument_list|(
argument|QObject *receiver
argument_list|,
argument|int event_type
argument_list|,
argument|QThreadData *data
argument_list|)
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_MAC_FRAMEWORK_BUILD
argument_list|)
name|void
name|checkReceiverThread
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|)
block|;
endif|#
directive|endif
name|void
name|cleanupThreadData
argument_list|()
block|;
endif|#
directive|endif
comment|// QT_NO_QOBJECT
name|int
operator|&
name|argc
block|;
name|char
operator|*
operator|*
name|argv
block|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|int
name|origArgc
block|;
name|char
operator|*
operator|*
name|origArgv
block|;
comment|// store unmodified arguments for QCoreApplication::arguments()
endif|#
directive|endif
name|void
name|appendApplicationPathToLibraryPaths
argument_list|(
name|void
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_TRANSLATION
name|QTranslatorList
name|translators
block|;
specifier|static
name|bool
name|isTranslatorInstalled
argument_list|(
name|QTranslator
operator|*
name|translator
argument_list|)
block|;
endif|#
directive|endif
name|QCoreApplicationPrivate
operator|::
name|Type
name|application_type
block|;
name|QString
name|cachedApplicationDirPath
block|;
specifier|static
name|QString
operator|*
name|cachedApplicationFilePath
block|;
specifier|static
name|void
name|setApplicationFilePath
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
specifier|static
specifier|inline
name|void
name|clearApplicationFilePath
argument_list|()
block|{
name|delete
name|cachedApplicationFilePath
block|;
name|cachedApplicationFilePath
operator|=
literal|0
block|; }
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
name|bool
name|in_exec
block|;
name|bool
name|aboutToQuitEmitted
block|;
name|bool
name|threadData_clean
block|;
specifier|static
name|QAbstractEventDispatcher
operator|*
name|eventDispatcher
block|;
specifier|static
name|bool
name|is_app_running
block|;
specifier|static
name|bool
name|is_app_closing
block|;
endif|#
directive|endif
specifier|static
name|bool
name|setuidAllowed
block|;
specifier|static
name|uint
name|attribs
block|;
specifier|static
specifier|inline
name|bool
name|testAttribute
argument_list|(
argument|uint flag
argument_list|)
block|{
return|return
name|attribs
operator|&
operator|(
literal|1
operator|<<
name|flag
operator|)
return|;
block|}
specifier|static
name|int
name|app_compile_version
block|;
name|void
name|processCommandLineArguments
argument_list|()
block|;
name|QString
name|qmljs_debug_arguments
block|;
comment|// a string containing arguments for js/qml debugging.
specifier|inline
name|QString
name|qmljsDebugArgumentsString
argument_list|()
block|{
return|return
name|qmljs_debug_arguments
return|;
block|}
ifdef|#
directive|ifdef
name|QT_NO_QOBJECT
name|QCoreApplication
operator|*
name|q_ptr
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOREAPPLICATION_P_H
end_comment
end_unit
