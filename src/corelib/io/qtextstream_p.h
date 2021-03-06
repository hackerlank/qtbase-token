begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTSTREAM_P_H
end_ifndef
begin_define
DECL|macro|QTEXTSTREAM_P_H
define|#
directive|define
name|QTEXTSTREAM_P_H
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
file|"qtextstream.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
end_ifndef
begin_include
include|#
directive|include
file|"qtextcodec.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
name|class
name|QDeviceClosedNotifier
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
specifier|inline
name|QDeviceClosedNotifier
argument_list|()
block|{ }
specifier|inline
name|void
name|setupDevice
argument_list|(
argument|QTextStream *stream
argument_list|,
argument|QIODevice *device
argument_list|)
block|{
name|disconnect
argument_list|()
block|;
if|if
condition|(
name|device
condition|)
name|connect
argument_list|(
name|device
argument_list|,
name|SIGNAL
argument_list|(
name|aboutToClose
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|flushStream
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|this
operator|->
name|stream
operator|=
name|stream
block|;     }
name|public
name|Q_SLOTS
operator|:
specifier|inline
name|void
name|flushStream
argument_list|()
block|{
name|stream
operator|->
name|flush
argument_list|()
block|; }
name|private
operator|:
name|QTextStream
operator|*
name|stream
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|QTextStreamPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTextStream
argument_list|)
name|public
label|:
comment|// streaming parameters
name|class
name|Params
block|{
name|public
label|:
name|void
name|reset
parameter_list|()
function_decl|;
name|int
name|realNumberPrecision
decl_stmt|;
name|int
name|integerBase
decl_stmt|;
name|int
name|fieldWidth
decl_stmt|;
name|QChar
name|padChar
decl_stmt|;
name|QTextStream
operator|::
name|FieldAlignment
name|fieldAlignment
expr_stmt|;
name|QTextStream
operator|::
name|RealNumberNotation
name|realNumberNotation
expr_stmt|;
name|QTextStream
operator|::
name|NumberFlags
name|numberFlags
expr_stmt|;
block|}
empty_stmt|;
name|QTextStreamPrivate
argument_list|(
name|QTextStream
operator|*
name|q_ptr
argument_list|)
expr_stmt|;
operator|~
name|QTextStreamPrivate
argument_list|()
expr_stmt|;
name|void
name|reset
parameter_list|()
function_decl|;
comment|// device
name|QIODevice
modifier|*
name|device
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
name|QDeviceClosedNotifier
name|deviceClosedNotifier
decl_stmt|;
endif|#
directive|endif
comment|// string
name|QString
modifier|*
name|string
decl_stmt|;
name|int
name|stringOffset
decl_stmt|;
name|QIODevice
operator|::
name|OpenMode
name|stringOpenMode
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
comment|// codec
name|QTextCodec
modifier|*
name|codec
decl_stmt|;
name|QTextCodec
operator|::
name|ConverterState
name|readConverterState
expr_stmt|;
name|QTextCodec
operator|::
name|ConverterState
name|writeConverterState
expr_stmt|;
name|QTextCodec
operator|::
name|ConverterState
operator|*
name|readConverterSavedState
expr_stmt|;
endif|#
directive|endif
name|QString
name|writeBuffer
decl_stmt|;
name|QString
name|readBuffer
decl_stmt|;
name|int
name|readBufferOffset
decl_stmt|;
name|int
name|readConverterSavedStateOffset
decl_stmt|;
comment|//the offset between readBufferStartDevicePos and that start of the buffer
name|qint64
name|readBufferStartDevicePos
decl_stmt|;
name|Params
name|params
decl_stmt|;
comment|// status
name|QTextStream
operator|::
name|Status
name|status
expr_stmt|;
name|QLocale
name|locale
decl_stmt|;
name|QTextStream
modifier|*
name|q_ptr
decl_stmt|;
name|int
name|lastTokenSize
decl_stmt|;
name|bool
name|deleteDevice
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
name|bool
name|autoDetectUnicode
decl_stmt|;
endif|#
directive|endif
comment|// i/o
enum|enum
name|TokenDelimiter
block|{
name|Space
block|,
name|NotSpace
block|,
name|EndOfLine
block|}
enum|;
name|QString
name|read
parameter_list|(
name|int
name|maxlen
parameter_list|)
function_decl|;
name|bool
name|scan
parameter_list|(
specifier|const
name|QChar
modifier|*
modifier|*
name|ptr
parameter_list|,
name|int
modifier|*
name|tokenLength
parameter_list|,
name|int
name|maxlen
parameter_list|,
name|TokenDelimiter
name|delimiter
parameter_list|)
function_decl|;
specifier|inline
specifier|const
name|QChar
operator|*
name|readPtr
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|void
name|consumeLastToken
parameter_list|()
function_decl|;
specifier|inline
name|void
name|consume
parameter_list|(
name|int
name|nchars
parameter_list|)
function_decl|;
name|void
name|saveConverterState
parameter_list|(
name|qint64
name|newPos
parameter_list|)
function_decl|;
name|void
name|restoreToSavedConverterState
parameter_list|()
function_decl|;
comment|// Return value type for getNumber()
enum|enum
name|NumberParsingStatus
block|{
name|npsOk
block|,
name|npsMissingDigit
block|,
name|npsInvalidPrefix
block|}
enum|;
specifier|inline
name|bool
name|getChar
parameter_list|(
name|QChar
modifier|*
name|ch
parameter_list|)
function_decl|;
specifier|inline
name|void
name|ungetChar
parameter_list|(
name|QChar
name|ch
parameter_list|)
function_decl|;
name|NumberParsingStatus
name|getNumber
parameter_list|(
name|qulonglong
modifier|*
name|l
parameter_list|)
function_decl|;
name|bool
name|getReal
parameter_list|(
name|double
modifier|*
name|f
parameter_list|)
function_decl|;
specifier|inline
name|void
name|write
parameter_list|(
specifier|const
name|QString
modifier|&
name|data
parameter_list|)
block|{
name|write
argument_list|(
name|data
operator|.
name|begin
argument_list|()
argument_list|,
name|data
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|write
parameter_list|(
name|QChar
name|ch
parameter_list|)
function_decl|;
name|void
name|write
parameter_list|(
specifier|const
name|QChar
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
name|void
name|write
parameter_list|(
name|QLatin1String
name|data
parameter_list|)
function_decl|;
name|void
name|writePadding
parameter_list|(
name|int
name|len
parameter_list|)
function_decl|;
specifier|inline
name|void
name|putString
parameter_list|(
specifier|const
name|QString
modifier|&
name|ch
parameter_list|,
name|bool
name|number
init|=
name|false
parameter_list|)
block|{
name|putString
argument_list|(
name|ch
operator|.
name|constData
argument_list|()
argument_list|,
name|ch
operator|.
name|length
argument_list|()
argument_list|,
name|number
argument_list|)
expr_stmt|;
block|}
name|void
name|putString
parameter_list|(
specifier|const
name|QChar
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|,
name|bool
name|number
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|putString
parameter_list|(
name|QLatin1String
name|data
parameter_list|,
name|bool
name|number
init|=
name|false
parameter_list|)
function_decl|;
specifier|inline
name|void
name|putChar
parameter_list|(
name|QChar
name|ch
parameter_list|)
function_decl|;
name|void
name|putNumber
parameter_list|(
name|qulonglong
name|number
parameter_list|,
name|bool
name|negative
parameter_list|)
function_decl|;
struct|struct
name|PaddingResult
block|{
name|int
name|left
decl_stmt|,
name|right
decl_stmt|;
block|}
struct|;
name|PaddingResult
name|padding
argument_list|(
name|int
name|len
argument_list|)
decl|const
decl_stmt|;
comment|// buffers
name|bool
name|fillReadBuffer
parameter_list|(
name|qint64
name|maxBytes
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
name|void
name|resetReadBuffer
parameter_list|()
function_decl|;
name|void
name|flushWriteBuffer
parameter_list|()
function_decl|;
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
comment|// QTEXTSTREAM_P_H
end_comment
end_unit
