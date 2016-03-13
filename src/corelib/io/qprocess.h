begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPROCESS_H
end_ifndef
begin_define
DECL|macro|QPROCESS_H
define|#
directive|define
name|QPROCESS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qiodevice.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<functional>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROCESS
end_ifndef
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
end_if
begin_typedef
DECL|typedef|Q_PID
typedef|typedef
name|qint64
name|Q_PID
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_typedef
typedef|typedef
name|struct
name|_PROCESS_INFORMATION
modifier|*
name|Q_PID
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|struct
name|_SECURITY_ATTRIBUTES
name|Q_SECURITY_ATTRIBUTES
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|struct
name|_STARTUPINFOW
name|Q_STARTUPINFO
typedef|;
end_typedef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
endif|#
directive|endif
DECL|variable|QProcessPrivate
name|class
name|QProcessPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QProcessEnvironmentPrivate
name|class
name|QProcessEnvironmentPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QProcessEnvironment
block|{
name|public
label|:
name|QProcessEnvironment
argument_list|()
expr_stmt|;
name|QProcessEnvironment
argument_list|(
specifier|const
name|QProcessEnvironment
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QProcessEnvironment
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QProcessEnvironment
modifier|&
name|operator
init|=
operator|(
name|QProcessEnvironment
operator|&&
name|other
operator|)
name|Q_DECL_NOTHROW
block|{
name|swap
argument_list|(
name|other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|QProcessEnvironment
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QProcessEnvironment
operator|&
name|other
operator|)
decl_stmt|;
name|void
name|swap
parameter_list|(
name|QProcessEnvironment
modifier|&
name|other
parameter_list|)
function|Q_DECL_NOTHROW
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QProcessEnvironment
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QProcessEnvironment
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|bool
name|contains
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|void
name|insert
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
function_decl|;
name|void
name|remove
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|QString
name|value
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QString
operator|&
name|defaultValue
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QStringList
name|toStringList
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|keys
argument_list|()
specifier|const
expr_stmt|;
name|void
name|insert
parameter_list|(
specifier|const
name|QProcessEnvironment
modifier|&
name|e
parameter_list|)
function_decl|;
specifier|static
name|QProcessEnvironment
name|systemEnvironment
parameter_list|()
function_decl|;
name|private
label|:
name|friend
name|class
name|QProcessPrivate
decl_stmt|;
name|friend
name|class
name|QProcessEnvironmentPrivate
decl_stmt|;
name|QSharedDataPointer
operator|<
name|QProcessEnvironmentPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QProcessEnvironment
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QProcess
range|:
name|public
name|QIODevice
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|ProcessError
block|{
name|FailedToStart
block|,
comment|//### file not found, resource error
name|Crashed
block|,
name|Timedout
block|,
name|ReadError
block|,
name|WriteError
block|,
name|UnknownError
block|}
block|;
name|Q_ENUM
argument_list|(
name|ProcessError
argument_list|)
expr|enum
name|ProcessState
block|{
name|NotRunning
block|,
name|Starting
block|,
name|Running
block|}
block|;
name|Q_ENUM
argument_list|(
name|ProcessState
argument_list|)
expr|enum
name|ProcessChannel
block|{
name|StandardOutput
block|,
name|StandardError
block|}
block|;
name|Q_ENUM
argument_list|(
name|ProcessChannel
argument_list|)
expr|enum
name|ProcessChannelMode
block|{
name|SeparateChannels
block|,
name|MergedChannels
block|,
name|ForwardedChannels
block|,
name|ForwardedOutputChannel
block|,
name|ForwardedErrorChannel
block|}
block|;
name|Q_ENUM
argument_list|(
name|ProcessChannelMode
argument_list|)
expr|enum
name|InputChannelMode
block|{
name|ManagedInputChannel
block|,
name|ForwardedInputChannel
block|}
block|;
name|Q_ENUM
argument_list|(
name|InputChannelMode
argument_list|)
expr|enum
name|ExitStatus
block|{
name|NormalExit
block|,
name|CrashExit
block|}
block|;
name|Q_ENUM
argument_list|(
argument|ExitStatus
argument_list|)
name|explicit
name|QProcess
argument_list|(
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|virtual
operator|~
name|QProcess
argument_list|()
block|;
name|void
name|start
argument_list|(
argument|const QString&program
argument_list|,
argument|const QStringList&arguments
argument_list|,
argument|OpenMode mode = ReadWrite
argument_list|)
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_PROCESS_COMBINED_ARGUMENT_START
argument_list|)
name|void
name|start
argument_list|(
argument|const QString&command
argument_list|,
argument|OpenMode mode = ReadWrite
argument_list|)
block|;
endif|#
directive|endif
name|void
name|start
argument_list|(
argument|OpenMode mode = ReadWrite
argument_list|)
block|;
name|bool
name|open
argument_list|(
argument|OpenMode mode = ReadWrite
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QString
name|program
argument_list|()
specifier|const
block|;
name|void
name|setProgram
argument_list|(
specifier|const
name|QString
operator|&
name|program
argument_list|)
block|;
name|QStringList
name|arguments
argument_list|()
specifier|const
block|;
name|void
name|setArguments
argument_list|(
specifier|const
name|QStringList
operator|&
name|arguments
argument_list|)
block|;
name|ProcessChannelMode
name|readChannelMode
argument_list|()
specifier|const
block|;
name|void
name|setReadChannelMode
argument_list|(
argument|ProcessChannelMode mode
argument_list|)
block|;
name|ProcessChannelMode
name|processChannelMode
argument_list|()
specifier|const
block|;
name|void
name|setProcessChannelMode
argument_list|(
argument|ProcessChannelMode mode
argument_list|)
block|;
name|InputChannelMode
name|inputChannelMode
argument_list|()
specifier|const
block|;
name|void
name|setInputChannelMode
argument_list|(
argument|InputChannelMode mode
argument_list|)
block|;
name|ProcessChannel
name|readChannel
argument_list|()
specifier|const
block|;
name|void
name|setReadChannel
argument_list|(
argument|ProcessChannel channel
argument_list|)
block|;
name|void
name|closeReadChannel
argument_list|(
argument|ProcessChannel channel
argument_list|)
block|;
name|void
name|closeWriteChannel
argument_list|()
block|;
name|void
name|setStandardInputFile
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|void
name|setStandardOutputFile
argument_list|(
argument|const QString&fileName
argument_list|,
argument|OpenMode mode = Truncate
argument_list|)
block|;
name|void
name|setStandardErrorFile
argument_list|(
argument|const QString&fileName
argument_list|,
argument|OpenMode mode = Truncate
argument_list|)
block|;
name|void
name|setStandardOutputProcess
argument_list|(
name|QProcess
operator|*
name|destination
argument_list|)
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|QString
name|nativeArguments
argument_list|()
specifier|const
block|;
name|void
name|setNativeArguments
argument_list|(
specifier|const
name|QString
operator|&
name|arguments
argument_list|)
block|;     struct
name|CreateProcessArguments
block|{
specifier|const
name|wchar_t
operator|*
name|applicationName
block|;
name|wchar_t
operator|*
name|arguments
block|;
name|Q_SECURITY_ATTRIBUTES
operator|*
name|processAttributes
block|;
name|Q_SECURITY_ATTRIBUTES
operator|*
name|threadAttributes
block|;
name|bool
name|inheritHandles
block|;
name|unsigned
name|long
name|flags
block|;
name|void
operator|*
name|environment
block|;
specifier|const
name|wchar_t
operator|*
name|currentDirectory
block|;
name|Q_STARTUPINFO
operator|*
name|startupInfo
block|;
name|Q_PID
name|processInformation
block|;     }
block|;
typedef|typedef
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|CreateProcessArguments
operator|*
argument_list|)
operator|>
name|CreateProcessArgumentModifier
expr_stmt|;
name|CreateProcessArgumentModifier
name|createProcessArgumentsModifier
argument_list|()
specifier|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setCreateProcessArgumentsModifier
parameter_list|(
name|CreateProcessArgumentModifier
name|modifier
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WIN
end_comment
begin_expr_stmt
name|QString
name|workingDirectory
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setWorkingDirectory
parameter_list|(
specifier|const
name|QString
modifier|&
name|dir
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setEnvironment
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|environment
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QStringList
name|environment
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setProcessEnvironment
parameter_list|(
specifier|const
name|QProcessEnvironment
modifier|&
name|environment
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QProcessEnvironment
name|processEnvironment
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QProcess
operator|::
name|ProcessError
name|error
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QProcess
operator|::
name|ProcessState
name|state
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_comment
comment|// #### Qt 5: Q_PID is a pointer on Windows and a value on Unix
end_comment
begin_expr_stmt
name|Q_PID
name|pid
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qint64
name|processId
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|bool
name|waitForStarted
parameter_list|(
name|int
name|msecs
init|=
literal|30000
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|bool
name|waitForReadyRead
argument_list|(
name|int
name|msecs
operator|=
literal|30000
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|waitForBytesWritten
argument_list|(
name|int
name|msecs
operator|=
literal|30000
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_function_decl
name|bool
name|waitForFinished
parameter_list|(
name|int
name|msecs
init|=
literal|30000
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QByteArray
name|readAllStandardOutput
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|QByteArray
name|readAllStandardError
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|exitCode
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QProcess
operator|::
name|ExitStatus
name|exitStatus
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_comment
comment|// QIODevice
end_comment
begin_expr_stmt
name|qint64
name|bytesAvailable
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
end_expr_stmt
begin_comment
comment|// ### Qt6: remove trivial override
end_comment
begin_expr_stmt
name|qint64
name|bytesToWrite
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isSequential
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|canReadLine
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
end_expr_stmt
begin_comment
comment|// ### Qt6: remove trivial override
end_comment
begin_expr_stmt
name|void
name|close
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|atEnd
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
end_expr_stmt
begin_comment
comment|// ### Qt6: remove trivial override
end_comment
begin_function_decl
specifier|static
name|int
name|execute
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
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|int
name|execute
parameter_list|(
specifier|const
name|QString
modifier|&
name|command
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
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
if|#
directive|if
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
init|=
name|QString
argument_list|()
endif|#
directive|endif
parameter_list|,
name|qint64
modifier|*
name|pid
init|=
name|Q_NULLPTR
parameter_list|)
function_decl|;
end_function_decl
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
end_if
begin_function_decl
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
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// ### Qt6: merge overloads
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
specifier|static
name|bool
name|startDetached
parameter_list|(
specifier|const
name|QString
modifier|&
name|command
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QStringList
name|systemEnvironment
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|nullDevice
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|public
name|Q_SLOTS
range|:
name|void
name|terminate
argument_list|()
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|kill
parameter_list|()
function_decl|;
end_function_decl
begin_label
name|Q_SIGNALS
label|:
end_label
begin_function_decl
name|void
name|started
parameter_list|(
name|QPrivateSignal
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|finished
parameter_list|(
name|int
name|exitCode
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// ### Qt 6: merge the two signals with a default value
end_comment
begin_decl_stmt
name|void
name|finished
argument_list|(
name|int
name|exitCode
argument_list|,
name|QProcess
operator|::
name|ExitStatus
name|exitStatus
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|6
argument_list|)
end_if
begin_decl_stmt
name|void
name|error
argument_list|(
name|QProcess
operator|::
name|ProcessError
name|error
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|void
name|errorOccurred
argument_list|(
name|QProcess
operator|::
name|ProcessError
name|error
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|stateChanged
argument_list|(
name|QProcess
operator|::
name|ProcessState
name|state
argument_list|,
name|QPrivateSignal
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|readyReadStandardOutput
parameter_list|(
name|QPrivateSignal
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|readyReadStandardError
parameter_list|(
name|QPrivateSignal
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|protected
label|:
end_label
begin_function_decl
name|void
name|setProcessState
parameter_list|(
name|ProcessState
name|state
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|setupChildProcess
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// QIODevice
end_comment
begin_decl_stmt
name|qint64
name|readData
argument_list|(
name|char
operator|*
name|data
argument_list|,
name|qint64
name|maxlen
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|qint64
name|writeData
argument_list|(
specifier|const
name|char
operator|*
name|data
argument_list|,
name|qint64
name|len
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QProcess
argument_list|)
end_macro
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QProcess
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|bool _q_canReadStandardOutput()
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|bool _q_canReadStandardError()
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|bool _q_canWrite()
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|bool _q_startupNotification()
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|bool _q_processDied()
argument_list|)
end_macro
begin_decl_stmt
name|friend
name|class
name|QProcessManager
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PROCESS
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPROCESS_H
end_comment
end_unit
