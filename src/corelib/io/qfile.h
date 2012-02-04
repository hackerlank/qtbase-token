begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILE_H
end_ifndef
begin_define
DECL|macro|QFILE_H
define|#
directive|define
name|QFILE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qiodevice.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|open
end_ifdef
begin_error
error|#
directive|error
error|qfile.h must be included before any header file that defines open
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QTemporaryFile
name|class
name|QTemporaryFile
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFilePrivate
name|class
name|QFilePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QFile
range|:
name|public
name|QIODevice
block|{
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
name|Q_OBJECT
endif|#
directive|endif
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QFile
argument_list|)
name|public
operator|:
expr|enum
name|FileError
block|{
name|NoError
operator|=
literal|0
block|,
name|ReadError
operator|=
literal|1
block|,
name|WriteError
operator|=
literal|2
block|,
name|FatalError
operator|=
literal|3
block|,
name|ResourceError
operator|=
literal|4
block|,
name|OpenError
operator|=
literal|5
block|,
name|AbortError
operator|=
literal|6
block|,
name|TimeOutError
operator|=
literal|7
block|,
name|UnspecifiedError
operator|=
literal|8
block|,
name|RemoveError
operator|=
literal|9
block|,
name|RenameError
operator|=
literal|10
block|,
name|PositionError
operator|=
literal|11
block|,
name|ResizeError
operator|=
literal|12
block|,
name|PermissionsError
operator|=
literal|13
block|,
name|CopyError
operator|=
literal|14
block|}
block|;      enum
name|Permission
block|{
name|ReadOwner
operator|=
literal|0x4000
block|,
name|WriteOwner
operator|=
literal|0x2000
block|,
name|ExeOwner
operator|=
literal|0x1000
block|,
name|ReadUser
operator|=
literal|0x0400
block|,
name|WriteUser
operator|=
literal|0x0200
block|,
name|ExeUser
operator|=
literal|0x0100
block|,
name|ReadGroup
operator|=
literal|0x0040
block|,
name|WriteGroup
operator|=
literal|0x0020
block|,
name|ExeGroup
operator|=
literal|0x0010
block|,
name|ReadOther
operator|=
literal|0x0004
block|,
name|WriteOther
operator|=
literal|0x0002
block|,
name|ExeOther
operator|=
literal|0x0001
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
name|Permissions
argument_list|,
name|Permission
argument_list|)
expr|enum
name|FileHandleFlag
block|{
name|AutoCloseHandle
operator|=
literal|0x0001
block|,
name|DontCloseHandle
operator|=
literal|0
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|FileHandleFlags
argument_list|,
argument|FileHandleFlag
argument_list|)
name|QFile
argument_list|()
block|;
name|QFile
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
name|explicit
name|QFile
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|QFile
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
endif|#
directive|endif
operator|~
name|QFile
argument_list|()
block|;
name|FileError
name|error
argument_list|()
specifier|const
block|;
name|void
name|unsetError
argument_list|()
block|;
name|QString
name|fileName
argument_list|()
specifier|const
block|;
name|void
name|setFileName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
typedef|typedef
name|QByteArray
function_decl|(
modifier|*
name|EncoderFn
function_decl|)
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
end_decl_stmt
begin_typedef
typedef|typedef
name|QString
function_decl|(
modifier|*
name|DecoderFn
function_decl|)
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|localfileName
parameter_list|)
function_decl|;
end_typedef
begin_function_decl
specifier|static
name|QByteArray
name|encodeName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|decodeName
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|localFileName
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
specifier|static
name|QString
name|decodeName
parameter_list|(
specifier|const
name|char
modifier|*
name|localFileName
parameter_list|)
block|{
return|return
name|decodeName
argument_list|(
name|QByteArray
argument_list|(
name|localFileName
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function_decl
specifier|static
name|void
name|setEncodingFunction
parameter_list|(
name|EncoderFn
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|setDecodingFunction
parameter_list|(
name|DecoderFn
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|exists
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|static
name|bool
name|exists
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|readLink
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|static
name|QString
name|readLink
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
specifier|inline
name|QString
name|symLinkTarget
argument_list|()
specifier|const
block|{
return|return
name|readLink
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
specifier|static
name|QString
name|symLinkTarget
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
return|return
name|readLink
argument_list|(
name|fileName
argument_list|)
return|;
block|}
end_function
begin_function_decl
name|bool
name|remove
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|remove
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|rename
parameter_list|(
specifier|const
name|QString
modifier|&
name|newName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|rename
parameter_list|(
specifier|const
name|QString
modifier|&
name|oldName
parameter_list|,
specifier|const
name|QString
modifier|&
name|newName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|link
parameter_list|(
specifier|const
name|QString
modifier|&
name|newName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|link
parameter_list|(
specifier|const
name|QString
modifier|&
name|oldname
parameter_list|,
specifier|const
name|QString
modifier|&
name|newName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|copy
parameter_list|(
specifier|const
name|QString
modifier|&
name|newName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|copy
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QString
modifier|&
name|newName
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|isSequential
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|bool
name|open
parameter_list|(
name|OpenMode
name|flags
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|open
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
name|OpenMode
name|flags
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|open
parameter_list|(
name|int
name|fd
parameter_list|,
name|OpenMode
name|flags
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|open
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
name|OpenMode
name|ioFlags
parameter_list|,
name|FileHandleFlags
name|handleFlags
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|open
parameter_list|(
name|int
name|fd
parameter_list|,
name|OpenMode
name|ioFlags
parameter_list|,
name|FileHandleFlags
name|handleFlags
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|close
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|qint64
name|size
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qint64
name|pos
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|bool
name|seek
parameter_list|(
name|qint64
name|offset
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|atEnd
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|bool
name|flush
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|resize
parameter_list|(
name|qint64
name|sz
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|resize
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|,
name|qint64
name|sz
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|Permissions
name|permissions
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|static
name|Permissions
name|permissions
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|setPermissions
parameter_list|(
name|Permissions
name|permissionSpec
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|setPermissions
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|,
name|Permissions
name|permissionSpec
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|handle
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_enum
enum|enum
name|MemoryMapFlags
block|{
name|NoOptions
init|=
literal|0
block|}
enum|;
end_enum
begin_function_decl
name|uchar
modifier|*
name|map
parameter_list|(
name|qint64
name|offset
parameter_list|,
name|qint64
name|size
parameter_list|,
name|MemoryMapFlags
name|flags
init|=
name|NoOptions
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|unmap
parameter_list|(
name|uchar
modifier|*
name|address
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|protected
label|:
end_label
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_QOBJECT
end_ifdef
begin_expr_stmt
name|QFile
argument_list|(
name|QFilePrivate
operator|&
name|dd
argument_list|)
expr_stmt|;
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_expr_stmt
name|QFile
argument_list|(
name|QFilePrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|qint64
name|readData
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxlen
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|qint64
name|writeData
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|len
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|qint64
name|readLineData
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxlen
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|friend
name|class
name|QTemporaryFile
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QFile
argument_list|)
end_macro
begin_macro
unit|};
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QFile::Permissions
argument_list|)
end_macro
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFILE_H
end_comment
end_unit
