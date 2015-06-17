begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPROCESS_P_H
end_ifndef
begin_define
DECL|macro|QPROCESS_P_H
define|#
directive|define
name|QPROCESS_P_H
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
file|"QtCore/qprocess.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstringlist.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qhash.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qshareddata.h"
end_include
begin_include
include|#
directive|include
file|"private/qringbuffer_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qiodevice_p.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_UNIX
end_ifdef
begin_include
include|#
directive|include
file|<QtCore/private/qorderedmutexlocker_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|"QtCore/qt_windows.h"
end_include
begin_typedef
DECL|typedef|Q_PIPE
typedef|typedef
name|HANDLE
name|Q_PIPE
typedef|;
end_typedef
begin_define
DECL|macro|INVALID_Q_PIPE
define|#
directive|define
name|INVALID_Q_PIPE
value|INVALID_HANDLE_VALUE
end_define
begin_else
else|#
directive|else
end_else
begin_typedef
DECL|typedef|Q_PIPE
typedef|typedef
name|int
name|Q_PIPE
typedef|;
end_typedef
begin_define
DECL|macro|INVALID_Q_PIPE
define|#
directive|define
name|INVALID_Q_PIPE
value|-1
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_QNX
end_ifdef
begin_define
DECL|macro|QPROCESS_USE_SPAWN
define|#
directive|define
name|QPROCESS_USE_SPAWN
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROCESS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSocketNotifier
name|class
name|QSocketNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindowsPipeReader
name|class
name|QWindowsPipeReader
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindowsPipeWriter
name|class
name|QWindowsPipeWriter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWinEventNotifier
name|class
name|QWinEventNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTimer
name|class
name|QTimer
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_decl_stmt
name|class
name|QProcEnvKey
range|:
name|public
name|QString
block|{
name|public
operator|:
name|QProcEnvKey
argument_list|()
block|{}
name|explicit
name|QProcEnvKey
argument_list|(
specifier|const
name|QString
operator|&
name|other
argument_list|)
operator|:
name|QString
argument_list|(
argument|other
argument_list|)
block|{}
name|QProcEnvKey
argument_list|(
specifier|const
name|QProcEnvKey
operator|&
name|other
argument_list|)
operator|:
name|QString
argument_list|(
argument|other
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QProcEnvKey
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|compare
argument_list|(
name|other
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
return|;
block|}
expr|}
block|;
DECL|function|qHash
specifier|inline
name|uint
name|qHash
argument_list|(
argument|const QProcEnvKey&key
argument_list|)
block|{
return|return
name|qHash
argument_list|(
name|key
operator|.
name|toCaseFolded
argument_list|()
argument_list|)
return|;
block|}
DECL|typedef|QProcEnvValue
typedef|typedef
name|QString
name|QProcEnvValue
typedef|;
else|#
directive|else
name|class
name|QProcEnvKey
block|{
name|public
operator|:
name|QProcEnvKey
argument_list|()
operator|:
name|hash
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|QProcEnvKey
argument_list|(
specifier|const
name|QByteArray
operator|&
name|other
argument_list|)
operator|:
name|key
argument_list|(
name|other
argument_list|)
block|,
name|hash
argument_list|(
argument|qHash(key)
argument_list|)
block|{}
name|QProcEnvKey
argument_list|(
argument|const QProcEnvKey&other
argument_list|)
block|{
operator|*
name|this
operator|=
name|other
block|; }
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QProcEnvKey
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|key
operator|==
name|other
operator|.
name|key
return|;
block|}
name|QByteArray
name|key
block|;
name|uint
name|hash
block|; }
decl_stmt|;
end_decl_stmt
begin_function
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|QProcEnvKey
modifier|&
name|key
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|key
operator|.
name|hash
return|;
block|}
end_function
begin_decl_stmt
name|class
name|QProcEnvValue
block|{
name|public
label|:
name|QProcEnvValue
argument_list|()
block|{}
name|QProcEnvValue
argument_list|(
argument|const QProcEnvValue&other
argument_list|)
block|{
operator|*
name|this
operator|=
name|other
expr_stmt|;
block|}
name|explicit
name|QProcEnvValue
argument_list|(
specifier|const
name|QString
operator|&
name|value
argument_list|)
operator|:
name|stringValue
argument_list|(
argument|value
argument_list|)
block|{}
name|explicit
name|QProcEnvValue
argument_list|(
specifier|const
name|QByteArray
operator|&
name|value
argument_list|)
operator|:
name|byteValue
argument_list|(
argument|value
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QProcEnvValue
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|byteValue
operator|.
name|isEmpty
argument_list|()
operator|&&
name|other
operator|.
name|byteValue
operator|.
name|isEmpty
argument_list|()
operator|?
name|stringValue
operator|==
name|other
operator|.
name|stringValue
operator|:
name|bytes
argument_list|()
operator|==
name|other
operator|.
name|bytes
argument_list|()
return|;
block|}
name|QByteArray
name|bytes
argument_list|()
specifier|const
block|{
if|if
condition|(
name|byteValue
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|stringValue
operator|.
name|isEmpty
argument_list|()
condition|)
name|byteValue
operator|=
name|stringValue
operator|.
name|toLocal8Bit
argument_list|()
expr_stmt|;
return|return
name|byteValue
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|QString
name|string
argument_list|()
specifier|const
block|{
if|if
condition|(
name|stringValue
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|byteValue
operator|.
name|isEmpty
argument_list|()
condition|)
name|stringValue
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|byteValue
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|stringValue
return|;
end_return
begin_decl_stmt
unit|}      mutable
name|QByteArray
name|byteValue
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|QString
name|stringValue
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QProcEnvValue
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QProcEnvKey
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QProcessEnvironmentPrivate
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
typedef|typedef
name|QProcEnvKey
name|Key
typedef|;
end_decl_stmt
begin_typedef
typedef|typedef
name|QProcEnvValue
name|Value
typedef|;
end_typedef
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_decl_stmt
specifier|inline
name|Key
name|prepareName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
block|{
return|return
name|Key
argument_list|(
name|name
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|QString
name|nameToString
argument_list|(
specifier|const
name|Key
operator|&
name|name
argument_list|)
decl|const
block|{
return|return
name|name
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|Value
name|prepareValue
argument_list|(
specifier|const
name|QString
operator|&
name|value
argument_list|)
decl|const
block|{
return|return
name|value
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|QString
name|valueToString
argument_list|(
specifier|const
name|Value
operator|&
name|value
argument_list|)
decl|const
block|{
return|return
name|value
return|;
block|}
end_decl_stmt
begin_struct
struct|struct
name|MutexLocker
block|{
name|MutexLocker
argument_list|(
argument|const QProcessEnvironmentPrivate *
argument_list|)
block|{}
block|}
struct|;
end_struct
begin_struct
struct|struct
name|OrderedMutexLocker
block|{
name|OrderedMutexLocker
argument_list|(
argument|const QProcessEnvironmentPrivate *
argument_list|,
argument|const QProcessEnvironmentPrivate *
argument_list|)
block|{}
block|}
struct|;
end_struct
begin_else
else|#
directive|else
end_else
begin_decl_stmt
specifier|inline
name|Key
name|prepareName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
block|{
name|Key
modifier|&
name|ent
init|=
name|nameMap
index|[
name|name
index|]
decl_stmt|;
if|if
condition|(
name|ent
operator|.
name|key
operator|.
name|isEmpty
argument_list|()
condition|)
name|ent
operator|=
name|Key
argument_list|(
name|name
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|ent
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|QString
name|nameToString
argument_list|(
specifier|const
name|Key
operator|&
name|name
argument_list|)
decl|const
block|{
specifier|const
name|QString
name|sname
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|name
operator|.
name|key
argument_list|)
decl_stmt|;
name|nameMap
index|[
name|sname
index|]
operator|=
name|name
expr_stmt|;
return|return
name|sname
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|Value
name|prepareValue
argument_list|(
specifier|const
name|QString
operator|&
name|value
argument_list|)
decl|const
block|{
return|return
name|Value
argument_list|(
name|value
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|QString
name|valueToString
argument_list|(
specifier|const
name|Value
operator|&
name|value
argument_list|)
decl|const
block|{
return|return
name|value
operator|.
name|string
argument_list|()
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|struct
name|MutexLocker
range|:
name|public
name|QMutexLocker
block|{
name|MutexLocker
argument_list|(
specifier|const
name|QProcessEnvironmentPrivate
operator|*
name|d
argument_list|)
operator|:
name|QMutexLocker
argument_list|(
argument|&d->mutex
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|struct
name|OrderedMutexLocker
range|:
name|public
name|QOrderedMutexLocker
block|{
name|OrderedMutexLocker
argument_list|(
specifier|const
name|QProcessEnvironmentPrivate
operator|*
name|d1
argument_list|,
specifier|const
name|QProcessEnvironmentPrivate
operator|*
name|d2
argument_list|)
operator|:
name|QOrderedMutexLocker
argument_list|(
argument|&d1->mutex
argument_list|,
argument|&d2->mutex
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QProcessEnvironmentPrivate
argument_list|()
operator|:
name|QSharedData
argument_list|()
block|{}
name|QProcessEnvironmentPrivate
argument_list|(
specifier|const
name|QProcessEnvironmentPrivate
operator|&
name|other
argument_list|)
operator|:
name|QSharedData
argument_list|()
block|{
comment|// This being locked ensures that the functions that only assign
comment|// d pointers don't need explicit locking.
comment|// We don't need to lock our own mutex, as this object is new and
comment|// consequently not shared. For the same reason, non-const methods
comment|// do not need a lock, as they detach objects (however, we need to
comment|// ensure that they really detach before using prepareName()).
name|MutexLocker
name|locker
argument_list|(
operator|&
name|other
argument_list|)
block|;
name|hash
operator|=
name|other
operator|.
name|hash
block|;
name|nameMap
operator|=
name|other
operator|.
name|nameMap
block|;
comment|// We need to detach our members, so that our mutex can protect them.
comment|// As we are being detached, they likely would be detached a moment later anyway.
name|hash
operator|.
name|detach
argument_list|()
block|;
name|nameMap
operator|.
name|detach
argument_list|()
block|;     }
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
typedef|typedef
name|QHash
operator|<
name|Key
operator|,
name|Value
operator|>
name|Hash
expr_stmt|;
end_typedef
begin_decl_stmt
name|Hash
name|hash
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_UNIX
end_ifdef
begin_typedef
typedef|typedef
name|QHash
operator|<
name|QString
operator|,
name|Key
operator|>
name|NameHash
expr_stmt|;
end_typedef
begin_decl_stmt
name|mutable
name|NameHash
name|nameMap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|QMutex
name|mutex
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
specifier|static
name|QProcessEnvironment
name|fromList
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|list
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QStringList
name|toList
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QStringList
name|keys
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|insert
parameter_list|(
specifier|const
name|QProcessEnvironmentPrivate
modifier|&
name|other
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
unit|};
DECL|function|detach
name|template
operator|<
operator|>
name|Q_INLINE_TEMPLATE
name|void
name|QSharedDataPointer
operator|<
name|QProcessEnvironmentPrivate
operator|>
operator|::
name|detach
argument_list|()
block|{
if|if
condition|(
name|d
operator|&&
name|d
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|==
literal|1
condition|)
return|return;
name|QProcessEnvironmentPrivate
operator|*
name|x
operator|=
operator|(
name|d
condition|?
name|new
name|QProcessEnvironmentPrivate
argument_list|(
operator|*
name|d
argument_list|)
else|:
name|new
name|QProcessEnvironmentPrivate
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|x
operator|->
name|ref
operator|.
name|ref
argument_list|()
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|d
operator|&&
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|delete
name|d
decl_stmt|;
end_if
begin_expr_stmt
name|d
operator|=
name|x
expr_stmt|;
end_expr_stmt
begin_label
unit|}  class
name|QProcessPrivate
label|:
end_label
begin_decl_stmt
name|public
name|QIODevicePrivate
block|{
name|public
label|:
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QProcess
argument_list|)
struct|struct
name|Channel
block|{
enum|enum
name|ProcessChannelType
block|{
name|Normal
init|=
literal|0
block|,
name|PipeSource
init|=
literal|1
block|,
name|PipeSink
init|=
literal|2
block|,
name|Redirect
init|=
literal|3
comment|// if you add "= 4" here, increase the number of bits below
block|}
enum|;
name|Channel
argument_list|()
operator|:
name|process
argument_list|(
literal|0
argument_list|)
operator|,
name|notifier
argument_list|(
literal|0
argument_list|)
operator|,
name|type
argument_list|(
name|Normal
argument_list|)
operator|,
name|closed
argument_list|(
name|false
argument_list|)
operator|,
name|append
argument_list|(
argument|false
argument_list|)
block|{
name|pipe
index|[
literal|0
index|]
operator|=
name|INVALID_Q_PIPE
block|;
name|pipe
index|[
literal|1
index|]
operator|=
name|INVALID_Q_PIPE
block|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|reader
operator|=
literal|0
block|;
endif|#
directive|endif
block|}
name|void
name|clear
argument_list|()
expr_stmt|;
name|Channel
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QString
operator|&
name|fileName
operator|)
block|{
name|clear
argument_list|()
block|;
name|file
operator|=
name|fileName
block|;
name|type
operator|=
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|?
name|Normal
else|:
name|Redirect
block|;
return|return
operator|*
name|this
return|;
block|}
name|void
name|pipeTo
parameter_list|(
name|QProcessPrivate
modifier|*
name|other
parameter_list|)
block|{
name|clear
argument_list|()
expr_stmt|;
name|process
operator|=
name|other
expr_stmt|;
name|type
operator|=
name|PipeSource
expr_stmt|;
block|}
name|void
name|pipeFrom
parameter_list|(
name|QProcessPrivate
modifier|*
name|other
parameter_list|)
block|{
name|clear
argument_list|()
expr_stmt|;
name|process
operator|=
name|other
expr_stmt|;
name|type
operator|=
name|PipeSink
expr_stmt|;
block|}
name|QString
name|file
decl_stmt|;
name|QProcessPrivate
modifier|*
name|process
decl_stmt|;
name|QSocketNotifier
modifier|*
name|notifier
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
union|union
block|{
name|QWindowsPipeReader
modifier|*
name|reader
decl_stmt|;
name|QWindowsPipeWriter
modifier|*
name|writer
decl_stmt|;
block|}
union|;
endif|#
directive|endif
name|QRingBuffer
name|buffer
decl_stmt|;
name|Q_PIPE
name|pipe
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|type
range|:
literal|2
decl_stmt|;
name|bool
name|closed
range|:
literal|1
decl_stmt|;
name|bool
name|append
range|:
literal|1
decl_stmt|;
block|}
struct|;
name|QProcessPrivate
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QProcessPrivate
argument_list|()
expr_stmt|;
comment|// private slots
name|bool
name|_q_canReadStandardOutput
parameter_list|()
function_decl|;
name|bool
name|_q_canReadStandardError
parameter_list|()
function_decl|;
name|bool
name|_q_canWrite
parameter_list|()
function_decl|;
name|bool
name|_q_startupNotification
parameter_list|()
function_decl|;
name|bool
name|_q_processDied
parameter_list|()
function_decl|;
name|QProcess
operator|::
name|ProcessChannel
name|processChannel
expr_stmt|;
name|QProcess
operator|::
name|ProcessChannelMode
name|processChannelMode
expr_stmt|;
name|QProcess
operator|::
name|InputChannelMode
name|inputChannelMode
expr_stmt|;
name|QProcess
operator|::
name|ProcessError
name|processError
expr_stmt|;
name|QProcess
operator|::
name|ProcessState
name|processState
expr_stmt|;
name|QString
name|workingDirectory
decl_stmt|;
name|Q_PID
name|pid
decl_stmt|;
name|int
name|sequenceNumber
decl_stmt|;
name|bool
name|dying
decl_stmt|;
name|bool
name|emittedReadyRead
decl_stmt|;
name|bool
name|emittedBytesWritten
decl_stmt|;
name|Channel
name|stdinChannel
decl_stmt|;
name|Channel
name|stdoutChannel
decl_stmt|;
name|Channel
name|stderrChannel
decl_stmt|;
name|bool
name|openChannel
parameter_list|(
name|Channel
modifier|&
name|channel
parameter_list|)
function_decl|;
name|void
name|closeChannel
parameter_list|(
name|Channel
modifier|*
name|channel
parameter_list|)
function_decl|;
name|void
name|closeWriteChannel
parameter_list|()
function_decl|;
name|bool
name|tryReadFromChannel
parameter_list|(
name|Channel
modifier|*
name|channel
parameter_list|)
function_decl|;
comment|// obviously, only stdout and stderr
name|QString
name|program
decl_stmt|;
name|QStringList
name|arguments
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|QString
name|nativeArguments
decl_stmt|;
endif|#
directive|endif
name|QProcessEnvironment
name|environment
decl_stmt|;
name|Q_PIPE
name|childStartedPipe
index|[
literal|2
index|]
decl_stmt|;
name|void
name|destroyPipe
parameter_list|(
name|Q_PIPE
name|pipe
index|[
literal|2
index|]
parameter_list|)
function_decl|;
name|QSocketNotifier
modifier|*
name|startupSocketNotifier
decl_stmt|;
name|QSocketNotifier
modifier|*
name|deathNotifier
decl_stmt|;
name|int
name|forkfd
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|QTimer
modifier|*
name|stdinWriteTrigger
decl_stmt|;
name|QWinEventNotifier
modifier|*
name|processFinishedNotifier
decl_stmt|;
endif|#
directive|endif
name|void
name|start
argument_list|(
name|QIODevice
operator|::
name|OpenMode
name|mode
argument_list|)
decl_stmt|;
name|void
name|startProcess
parameter_list|()
function_decl|;
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
name|QPROCESS_USE_SPAWN
argument_list|)
name|void
name|execChild
parameter_list|(
specifier|const
name|char
modifier|*
name|workingDirectory
parameter_list|,
name|char
modifier|*
modifier|*
name|path
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|char
modifier|*
modifier|*
name|envp
parameter_list|)
function_decl|;
elif|#
directive|elif
name|defined
argument_list|(
name|QPROCESS_USE_SPAWN
argument_list|)
name|pid_t
name|spawnChild
parameter_list|(
name|pid_t
modifier|*
name|ppid
parameter_list|,
specifier|const
name|char
modifier|*
name|workingDirectory
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|char
modifier|*
modifier|*
name|envp
parameter_list|)
function_decl|;
endif|#
directive|endif
name|bool
name|processStarted
parameter_list|()
function_decl|;
name|void
name|terminateProcess
parameter_list|()
function_decl|;
name|void
name|killProcess
parameter_list|()
function_decl|;
name|void
name|findExitCode
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|Q_OS_UNIX
name|bool
name|waitForDeadChild
parameter_list|()
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|bool
name|drainOutputPipes
parameter_list|()
function_decl|;
name|void
name|flushPipeWriter
parameter_list|()
function_decl|;
name|qint64
name|pipeWriterBytesToWrite
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
specifier|static
name|bool
name|startDetached
parameter_list|(
specifier|const
name|QString
modifier|&
name|program
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|arguments
parameter_list|,
specifier|const
name|QString
modifier|&
name|workingDirectory
init|=
name|QString
argument_list|()
parameter_list|,
name|qint64
modifier|*
name|pid
init|=
literal|0
parameter_list|)
function_decl|;
name|int
name|exitCode
decl_stmt|;
name|QProcess
operator|::
name|ExitStatus
name|exitStatus
expr_stmt|;
name|bool
name|crashed
decl_stmt|;
name|bool
name|waitForStarted
parameter_list|(
name|int
name|msecs
init|=
literal|30000
parameter_list|)
function_decl|;
name|bool
name|waitForReadyRead
parameter_list|(
name|int
name|msecs
init|=
literal|30000
parameter_list|)
function_decl|;
name|bool
name|waitForBytesWritten
parameter_list|(
name|int
name|msecs
init|=
literal|30000
parameter_list|)
function_decl|;
name|bool
name|waitForFinished
parameter_list|(
name|int
name|msecs
init|=
literal|30000
parameter_list|)
function_decl|;
name|bool
name|waitForWrite
parameter_list|(
name|int
name|msecs
init|=
literal|30000
parameter_list|)
function_decl|;
name|qint64
name|bytesAvailableInChannel
argument_list|(
specifier|const
name|Channel
operator|*
name|channel
argument_list|)
decl|const
decl_stmt|;
name|qint64
name|readFromChannel
parameter_list|(
specifier|const
name|Channel
modifier|*
name|channel
parameter_list|,
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxlen
parameter_list|)
function_decl|;
name|qint64
name|writeToStdin
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxlen
parameter_list|)
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
name|void
name|setError
argument_list|(
name|QProcess
operator|::
name|ProcessError
name|error
argument_list|,
specifier|const
name|QString
operator|&
name|description
operator|=
name|QString
argument_list|()
argument_list|)
decl_stmt|;
name|void
name|setErrorAndEmit
argument_list|(
name|QProcess
operator|::
name|ProcessError
name|error
argument_list|,
specifier|const
name|QString
operator|&
name|description
operator|=
name|QString
argument_list|()
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_BLACKBERRY
name|QList
operator|<
name|QSocketNotifier
operator|*
operator|>
name|defaultNotifiers
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
comment|// Q_OS_BLACKBERRY
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PROCESS
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPROCESS_P_H
end_comment
end_unit
