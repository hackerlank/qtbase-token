begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDATASTREAM_H
end_ifndef
begin_define
DECL|macro|QDATASTREAM_H
define|#
directive|define
name|QDATASTREAM_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qiodevice.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Status
end_ifdef
begin_error
error|#
directive|error
error|qdatastream.h must be included before any header file that defines Status
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QByteArray
name|class
name|QByteArray
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|QList
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QList
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QLinkedList
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QLinkedList
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QVector
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QVector
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QSet
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QSet
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|Key
DECL|variable|QHash
name|template
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
name|class
name|QHash
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|Key
DECL|variable|QMap
name|template
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
name|class
name|QMap
expr_stmt|;
end_expr_stmt
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DATASTREAM
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
end_if
begin_decl_stmt
DECL|variable|QDataStreamPrivate
name|class
name|QDataStreamPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QDataStream
block|{
name|public
label|:
enum|enum
name|Version
block|{
name|Qt_1_0
init|=
literal|1
block|,
name|Qt_2_0
init|=
literal|2
block|,
name|Qt_2_1
init|=
literal|3
block|,
name|Qt_3_0
init|=
literal|4
block|,
name|Qt_3_1
init|=
literal|5
block|,
name|Qt_3_3
init|=
literal|6
block|,
name|Qt_4_0
init|=
literal|7
block|,
name|Qt_4_1
init|=
name|Qt_4_0
block|,
name|Qt_4_2
init|=
literal|8
block|,
name|Qt_4_3
init|=
literal|9
block|,
name|Qt_4_4
init|=
literal|10
block|,
name|Qt_4_5
init|=
literal|11
block|,
name|Qt_4_6
init|=
literal|12
block|,
name|Qt_4_7
init|=
name|Qt_4_6
block|,
name|Qt_4_8
init|=
name|Qt_4_7
block|,
name|Qt_4_9
init|=
name|Qt_4_8
block|,
name|Qt_5_0
init|=
literal|13
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050100
error|#
directive|error
error|Add the datastream version for this Qt version
endif|#
directive|endif
block|}
enum|;
enum|enum
name|ByteOrder
block|{
name|BigEndian
init|=
name|QSysInfo
operator|::
name|BigEndian
block|,
name|LittleEndian
init|=
name|QSysInfo
operator|::
name|LittleEndian
block|}
enum|;
enum|enum
name|Status
block|{
name|Ok
block|,
name|ReadPastEnd
block|,
name|ReadCorruptData
block|,
name|WriteFailed
block|}
enum|;
enum|enum
name|FloatingPointPrecision
block|{
name|SinglePrecision
block|,
name|DoublePrecision
block|}
enum|;
name|QDataStream
argument_list|()
expr_stmt|;
name|explicit
name|QDataStream
parameter_list|(
name|QIODevice
modifier|*
parameter_list|)
function_decl|;
name|QDataStream
argument_list|(
argument|QByteArray *
argument_list|,
argument|QIODevice::OpenMode flags
argument_list|)
empty_stmt|;
name|QDataStream
argument_list|(
specifier|const
name|QByteArray
operator|&
argument_list|)
expr_stmt|;
operator|~
name|QDataStream
argument_list|()
expr_stmt|;
name|QIODevice
operator|*
name|device
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDevice
parameter_list|(
name|QIODevice
modifier|*
parameter_list|)
function_decl|;
name|void
name|unsetDevice
parameter_list|()
function_decl|;
name|bool
name|atEnd
argument_list|()
specifier|const
expr_stmt|;
name|Status
name|status
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setStatus
parameter_list|(
name|Status
name|status
parameter_list|)
function_decl|;
name|void
name|resetStatus
parameter_list|()
function_decl|;
name|FloatingPointPrecision
name|floatingPointPrecision
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setFloatingPointPrecision
parameter_list|(
name|FloatingPointPrecision
name|precision
parameter_list|)
function_decl|;
name|ByteOrder
name|byteOrder
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setByteOrder
parameter_list|(
name|ByteOrder
parameter_list|)
function_decl|;
name|int
name|version
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setVersion
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|qint8
operator|&
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|quint8
operator|&
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|qint16
operator|&
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|quint16
operator|&
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|qint32
operator|&
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|quint32
operator|&
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|qint64
operator|&
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|quint64
operator|&
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|bool
operator|&
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|float
operator|&
name|f
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|double
operator|&
name|f
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|char
operator|*
operator|&
name|str
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|qint8
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|quint8
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|qint16
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|quint16
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|qint32
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|quint32
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|qint64
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|quint64
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|bool
name|i
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|float
name|f
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|double
name|f
operator|)
expr_stmt|;
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|char
operator|*
name|str
operator|)
expr_stmt|;
name|QDataStream
modifier|&
name|readBytes
parameter_list|(
name|char
modifier|*
modifier|&
parameter_list|,
name|uint
modifier|&
name|len
parameter_list|)
function_decl|;
name|int
name|readRawData
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
name|QDataStream
modifier|&
name|writeBytes
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|uint
name|len
parameter_list|)
function_decl|;
name|int
name|writeRawData
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
name|int
name|skipRawData
parameter_list|(
name|int
name|len
parameter_list|)
function_decl|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QDataStream
argument_list|)
name|QScopedPointer
operator|<
name|QDataStreamPrivate
operator|>
name|d
expr_stmt|;
name|QIODevice
modifier|*
name|dev
decl_stmt|;
name|bool
name|owndev
decl_stmt|;
name|bool
name|noswap
decl_stmt|;
name|ByteOrder
name|byteorder
decl_stmt|;
name|int
name|ver
decl_stmt|;
name|Status
name|q_status
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*****************************************************************************   QDataStream inline functions  *****************************************************************************/
end_comment
begin_expr_stmt
DECL|function|device
specifier|inline
name|QIODevice
operator|*
name|QDataStream
operator|::
name|device
argument_list|()
specifier|const
block|{
return|return
name|dev
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|byteOrder
specifier|inline
name|QDataStream
operator|::
name|ByteOrder
name|QDataStream
operator|::
name|byteOrder
argument_list|()
specifier|const
block|{
return|return
name|byteorder
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|version
specifier|inline
name|int
name|QDataStream
operator|::
name|version
argument_list|()
specifier|const
block|{
return|return
name|ver
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setVersion
specifier|inline
name|void
name|QDataStream
operator|::
name|setVersion
argument_list|(
argument|int v
argument_list|)
block|{
name|ver
operator|=
name|v
block|; }
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|QDataStream
operator|::
name|operator
operator|>>
operator|(
name|quint8
operator|&
name|i
operator|)
block|{
return|return
operator|*
name|this
operator|>>
name|reinterpret_cast
operator|<
name|qint8
operator|&
operator|>
operator|(
name|i
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|QDataStream
operator|::
name|operator
operator|>>
operator|(
name|quint16
operator|&
name|i
operator|)
block|{
return|return
operator|*
name|this
operator|>>
name|reinterpret_cast
operator|<
name|qint16
operator|&
operator|>
operator|(
name|i
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|QDataStream
operator|::
name|operator
operator|>>
operator|(
name|quint32
operator|&
name|i
operator|)
block|{
return|return
operator|*
name|this
operator|>>
name|reinterpret_cast
operator|<
name|qint32
operator|&
operator|>
operator|(
name|i
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|QDataStream
operator|::
name|operator
operator|>>
operator|(
name|quint64
operator|&
name|i
operator|)
block|{
return|return
operator|*
name|this
operator|>>
name|reinterpret_cast
operator|<
name|qint64
operator|&
operator|>
operator|(
name|i
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|QDataStream
operator|::
name|operator
operator|<<
operator|(
name|quint8
name|i
operator|)
block|{
return|return
operator|*
name|this
operator|<<
name|qint8
argument_list|(
name|i
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|QDataStream
operator|::
name|operator
operator|<<
operator|(
name|quint16
name|i
operator|)
block|{
return|return
operator|*
name|this
operator|<<
name|qint16
argument_list|(
name|i
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|QDataStream
operator|::
name|operator
operator|<<
operator|(
name|quint32
name|i
operator|)
block|{
return|return
operator|*
name|this
operator|<<
name|qint32
argument_list|(
name|i
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|QDataStream
operator|::
name|operator
operator|<<
operator|(
name|quint64
name|i
operator|)
block|{
return|return
operator|*
name|this
operator|<<
name|qint64
argument_list|(
name|i
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|operator
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|s
operator|,
name|QList
operator|<
name|T
operator|>
operator|&
name|l
operator|)
block|{
name|l
operator|.
name|clear
argument_list|()
block|;
name|quint32
name|c
block|;
name|s
operator|>>
name|c
block|;
name|l
operator|.
name|reserve
argument_list|(
name|c
argument_list|)
block|;
for|for
control|(
name|quint32
name|i
init|=
literal|0
init|;
name|i
operator|<
name|c
condition|;
operator|++
name|i
control|)
block|{
name|T
name|t
decl_stmt|;
name|s
operator|>>
name|t
expr_stmt|;
name|l
operator|.
name|append
argument_list|(
name|t
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|.
name|atEnd
argument_list|()
condition|)
break|break;
block|}
end_expr_stmt
begin_return
return|return
name|s
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|operator
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|s
operator|,
specifier|const
name|QList
operator|<
name|T
operator|>
operator|&
name|l
operator|)
block|{
name|s
operator|<<
name|quint32
argument_list|(
name|l
operator|.
name|size
argument_list|()
argument_list|)
block|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|l
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|s
operator|<<
name|l
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|s
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|operator
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|s
operator|,
name|QLinkedList
operator|<
name|T
operator|>
operator|&
name|l
operator|)
block|{
name|l
operator|.
name|clear
argument_list|()
block|;
name|quint32
name|c
block|;
name|s
operator|>>
name|c
block|;
for|for
control|(
name|quint32
name|i
init|=
literal|0
init|;
name|i
operator|<
name|c
condition|;
operator|++
name|i
control|)
block|{
name|T
name|t
decl_stmt|;
name|s
operator|>>
name|t
expr_stmt|;
name|l
operator|.
name|append
argument_list|(
name|t
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|.
name|atEnd
argument_list|()
condition|)
break|break;
block|}
end_expr_stmt
begin_return
return|return
name|s
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|operator
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|s
operator|,
specifier|const
name|QLinkedList
operator|<
name|T
operator|>
operator|&
name|l
operator|)
block|{
name|s
operator|<<
name|quint32
argument_list|(
name|l
operator|.
name|size
argument_list|()
argument_list|)
block|;
name|typename
name|QLinkedList
operator|<
name|T
operator|>
operator|::
name|ConstIterator
name|it
operator|=
name|l
operator|.
name|constBegin
argument_list|()
block|;
for|for
control|(
init|;
name|it
operator|!=
name|l
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
name|s
operator|<<
operator|*
name|it
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|s
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|operator
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|s
operator|,
name|QVector
operator|<
name|T
operator|>
operator|&
name|v
operator|)
block|{
name|v
operator|.
name|clear
argument_list|()
block|;
name|quint32
name|c
block|;
name|s
operator|>>
name|c
block|;
name|v
operator|.
name|resize
argument_list|(
name|c
argument_list|)
block|;
for|for
control|(
name|quint32
name|i
init|=
literal|0
init|;
name|i
operator|<
name|c
condition|;
operator|++
name|i
control|)
block|{
name|T
name|t
decl_stmt|;
name|s
operator|>>
name|t
expr_stmt|;
name|v
index|[
name|i
index|]
operator|=
name|t
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|s
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|operator
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|s
operator|,
specifier|const
name|QVector
operator|<
name|T
operator|>
operator|&
name|v
operator|)
block|{
name|s
operator|<<
name|quint32
argument_list|(
name|v
operator|.
name|size
argument_list|()
argument_list|)
block|;
for|for
control|(
name|typename
name|QVector
operator|<
name|T
operator|>
operator|::
name|const_iterator
name|it
operator|=
name|v
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|v
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
name|s
operator|<<
operator|*
name|it
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|s
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|operator
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|in
operator|,
name|QSet
operator|<
name|T
operator|>
operator|&
name|set
operator|)
block|{
name|set
operator|.
name|clear
argument_list|()
block|;
name|quint32
name|c
block|;
name|in
operator|>>
name|c
block|;
for|for
control|(
name|quint32
name|i
init|=
literal|0
init|;
name|i
operator|<
name|c
condition|;
operator|++
name|i
control|)
block|{
name|T
name|t
decl_stmt|;
name|in
operator|>>
name|t
expr_stmt|;
name|set
operator|<<
name|t
expr_stmt|;
if|if
condition|(
name|in
operator|.
name|atEnd
argument_list|()
condition|)
break|break;
block|}
end_expr_stmt
begin_return
return|return
name|in
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|operator
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|out
operator|,
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|set
operator|)
block|{
name|out
operator|<<
name|quint32
argument_list|(
name|set
operator|.
name|size
argument_list|()
argument_list|)
block|;
name|typename
name|QSet
operator|<
name|T
operator|>
operator|::
name|const_iterator
name|i
operator|=
name|set
operator|.
name|constBegin
argument_list|()
block|;
while|while
condition|(
name|i
operator|!=
name|set
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|out
operator|<<
operator|*
name|i
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|out
return|;
end_return
begin_expr_stmt
unit|}  template
DECL|variable|Key
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
DECL|function|operator
name|Q_OUTOFLINE_TEMPLATE
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|in
operator|,
name|QHash
operator|<
name|Key
operator|,
name|T
operator|>
operator|&
name|hash
operator|)
block|{
name|QDataStream
operator|::
name|Status
name|oldStatus
operator|=
name|in
operator|.
name|status
argument_list|()
block|;
name|in
operator|.
name|resetStatus
argument_list|()
block|;
name|hash
operator|.
name|clear
argument_list|()
block|;
name|quint32
name|n
block|;
name|in
operator|>>
name|n
block|;
for|for
control|(
name|quint32
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|in
operator|.
name|status
argument_list|()
operator|!=
name|QDataStream
operator|::
name|Ok
condition|)
break|break;
name|Key
name|k
decl_stmt|;
name|T
name|t
decl_stmt|;
name|in
operator|>>
name|k
operator|>>
name|t
expr_stmt|;
name|hash
operator|.
name|insertMulti
argument_list|(
name|k
argument_list|,
name|t
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_if
if|if
condition|(
name|in
operator|.
name|status
argument_list|()
operator|!=
name|QDataStream
operator|::
name|Ok
condition|)
name|hash
operator|.
name|clear
argument_list|()
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|oldStatus
operator|!=
name|QDataStream
operator|::
name|Ok
condition|)
name|in
operator|.
name|setStatus
argument_list|(
name|oldStatus
argument_list|)
expr_stmt|;
end_if
begin_return
return|return
name|in
return|;
end_return
begin_expr_stmt
unit|}  template
DECL|variable|Key
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
DECL|function|operator
name|Q_OUTOFLINE_TEMPLATE
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|out
operator|,
specifier|const
name|QHash
operator|<
name|Key
operator|,
name|T
operator|>
operator|&
name|hash
operator|)
block|{
name|out
operator|<<
name|quint32
argument_list|(
name|hash
operator|.
name|size
argument_list|()
argument_list|)
block|;
name|typename
name|QHash
operator|<
name|Key
block|,
name|T
operator|>
operator|::
name|ConstIterator
name|it
operator|=
name|hash
operator|.
name|end
argument_list|()
block|;
name|typename
name|QHash
operator|<
name|Key
block|,
name|T
operator|>
operator|::
name|ConstIterator
name|begin
operator|=
name|hash
operator|.
name|begin
argument_list|()
block|;
while|while
condition|(
name|it
operator|!=
name|begin
condition|)
block|{
operator|--
name|it
expr_stmt|;
name|out
operator|<<
name|it
operator|.
name|key
argument_list|()
operator|<<
name|it
operator|.
name|value
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|out
return|;
end_return
begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|qdoc
end_ifdef
begin_expr_stmt
unit|template
DECL|variable|Key
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
DECL|function|operator
name|Q_OUTOFLINE_TEMPLATE
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|in
operator|,
name|QMap
operator|<
name|Key
operator|,
name|T
operator|>
operator|&
name|map
operator|)
else|#
directive|else
name|template
operator|<
name|class
name|aKey
operator|,
name|class
name|aT
operator|>
name|Q_OUTOFLINE_TEMPLATE
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|in
operator|,
name|QMap
operator|<
name|aKey
operator|,
name|aT
operator|>
operator|&
name|map
operator|)
endif|#
directive|endif
block|{
name|QDataStream
operator|::
name|Status
name|oldStatus
operator|=
name|in
operator|.
name|status
argument_list|()
block|;
name|in
operator|.
name|resetStatus
argument_list|()
block|;
name|map
operator|.
name|clear
argument_list|()
block|;
name|quint32
name|n
block|;
name|in
operator|>>
name|n
block|;
name|map
operator|.
name|detach
argument_list|()
block|;
name|map
operator|.
name|setInsertInOrder
argument_list|(
name|true
argument_list|)
block|;
for|for
control|(
name|quint32
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|in
operator|.
name|status
argument_list|()
operator|!=
name|QDataStream
operator|::
name|Ok
condition|)
break|break;
name|aKey
name|key
decl_stmt|;
name|aT
name|value
decl_stmt|;
name|in
operator|>>
name|key
operator|>>
name|value
expr_stmt|;
name|map
operator|.
name|insertMulti
argument_list|(
name|key
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
name|map
operator|.
name|setInsertInOrder
argument_list|(
name|false
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|in
operator|.
name|status
argument_list|()
operator|!=
name|QDataStream
operator|::
name|Ok
condition|)
name|map
operator|.
name|clear
argument_list|()
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|oldStatus
operator|!=
name|QDataStream
operator|::
name|Ok
condition|)
name|in
operator|.
name|setStatus
argument_list|(
name|oldStatus
argument_list|)
expr_stmt|;
end_if
begin_return
return|return
name|in
return|;
end_return
begin_expr_stmt
unit|}  template
DECL|variable|Key
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
DECL|function|operator
name|Q_OUTOFLINE_TEMPLATE
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|out
operator|,
specifier|const
name|QMap
operator|<
name|Key
operator|,
name|T
operator|>
operator|&
name|map
operator|)
block|{
name|out
operator|<<
name|quint32
argument_list|(
name|map
operator|.
name|size
argument_list|()
argument_list|)
block|;
name|typename
name|QMap
operator|<
name|Key
block|,
name|T
operator|>
operator|::
name|ConstIterator
name|it
operator|=
name|map
operator|.
name|end
argument_list|()
block|;
name|typename
name|QMap
operator|<
name|Key
block|,
name|T
operator|>
operator|::
name|ConstIterator
name|begin
operator|=
name|map
operator|.
name|begin
argument_list|()
block|;
while|while
condition|(
name|it
operator|!=
name|begin
condition|)
block|{
operator|--
name|it
expr_stmt|;
name|out
operator|<<
name|it
operator|.
name|key
argument_list|()
operator|<<
name|it
operator|.
name|value
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|out
return|;
end_return
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DATASTREAM
end_comment
begin_macro
unit|QT_END_NAMESPACE
name|QT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDATASTREAM_H
end_comment
end_unit
