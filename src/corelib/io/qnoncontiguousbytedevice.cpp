begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnoncontiguousbytedevice_p.h"
end_include
begin_include
include|#
directive|include
file|<qbuffer.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QNonContiguousByteDevice     \inmodule QtCore     \brief A QNonContiguousByteDevice is a representation of a     file, array or buffer that allows access with a read pointer.     \since 4.6      The goal of this class is to have a data representation that     allows us to avoid doing a memcpy as we have to do with QIODevice.      \sa QNonContiguousByteDeviceFactory      \internal */
end_comment
begin_comment
comment|/*!     \fn virtual const char* QNonContiguousByteDevice::readPointer(qint64 maximumLength, qint64&len)      Return a byte pointer for at most \a maximumLength bytes of that device.     if \a maximumLength is -1, the caller does not care about the length and     the device may return what it desires to.     The actual number of bytes the pointer is valid for is returned in     the \a len variable.     \a len will be -1 if EOF or an error occurs.     If it was really EOF can then afterwards be checked with atEnd()     Returns 0 if it is not possible to read at that position.      \sa atEnd()      \internal */
end_comment
begin_comment
comment|/*!     \fn virtual bool QNonContiguousByteDevice::advanceReadPointer(qint64 amount)       will advance the internal read pointer by \a amount bytes.      The old readPointer is invalid after this call.      \sa readPointer()      \internal */
end_comment
begin_comment
comment|/*!     \fn virtual bool QNonContiguousByteDevice::atEnd()       Returns \c true if everything has been read and the read      pointer cannot be advanced anymore.      \sa readPointer(), advanceReadPointer(), reset()      \internal */
end_comment
begin_comment
comment|/*!     \fn virtual bool QNonContiguousByteDevice::reset()      Moves the internal read pointer back to the beginning.     Returns \c false if this was not possible.      \sa atEnd(), disableReset()      \internal */
end_comment
begin_comment
comment|/*!     \fn void QNonContiguousByteDevice::disableReset()      Disable the reset() call, e.g. it will always     do nothing and return false.      \sa reset()      \internal */
end_comment
begin_comment
comment|/*!     \fn virtual qint64 QNonContiguousByteDevice::size()      Returns the size of the complete device or -1 if unknown.     May also return less/more than what can be actually read with readPointer()      \internal */
end_comment
begin_comment
comment|/*!     \fn void QNonContiguousByteDevice::readyRead()      Emitted when there is data available      \internal */
end_comment
begin_comment
comment|/*!     \fn void QNonContiguousByteDevice::readProgress(qint64 current, qint64 total)      Emitted when data has been "read" by advancing the read pointer      \internal */
end_comment
begin_constructor
DECL|function|QNonContiguousByteDevice
name|QNonContiguousByteDevice
operator|::
name|QNonContiguousByteDevice
parameter_list|()
member_init_list|:
name|QObject
argument_list|(
operator|(
name|QObject
operator|*
operator|)
literal|0
argument_list|)
member_init_list|,
name|resetDisabled
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QNonContiguousByteDevice
name|QNonContiguousByteDevice
operator|::
name|~
name|QNonContiguousByteDevice
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|disableReset
name|void
name|QNonContiguousByteDevice
operator|::
name|disableReset
parameter_list|()
block|{
name|resetDisabled
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_comment
comment|// FIXME we should scrap this whole implementation and instead change the ByteArrayImpl to be able to cope with sub-arrays?
end_comment
begin_constructor
DECL|function|QNonContiguousByteDeviceBufferImpl
name|QNonContiguousByteDeviceBufferImpl
operator|::
name|QNonContiguousByteDeviceBufferImpl
parameter_list|(
name|QBuffer
modifier|*
name|b
parameter_list|)
member_init_list|:
name|QNonContiguousByteDevice
argument_list|()
block|{
name|buffer
operator|=
name|b
expr_stmt|;
name|byteArray
operator|=
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|buffer
operator|->
name|buffer
argument_list|()
operator|.
name|constData
argument_list|()
operator|+
name|buffer
operator|->
name|pos
argument_list|()
argument_list|,
name|buffer
operator|->
name|size
argument_list|()
operator|-
name|buffer
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|arrayImpl
operator|=
operator|new
name|QNonContiguousByteDeviceByteArrayImpl
argument_list|(
operator|&
name|byteArray
argument_list|)
expr_stmt|;
name|arrayImpl
operator|->
name|setParent
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|arrayImpl
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|arrayImpl
argument_list|,
name|SIGNAL
argument_list|(
name|readProgress
argument_list|(
name|qint64
argument_list|,
name|qint64
argument_list|)
argument_list|)
argument_list|,
name|SIGNAL
argument_list|(
name|readProgress
argument_list|(
name|qint64
argument_list|,
name|qint64
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QNonContiguousByteDeviceBufferImpl
name|QNonContiguousByteDeviceBufferImpl
operator|::
name|~
name|QNonContiguousByteDeviceBufferImpl
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|readPointer
specifier|const
name|char
modifier|*
name|QNonContiguousByteDeviceBufferImpl
operator|::
name|readPointer
parameter_list|(
name|qint64
name|maximumLength
parameter_list|,
name|qint64
modifier|&
name|len
parameter_list|)
block|{
return|return
name|arrayImpl
operator|->
name|readPointer
argument_list|(
name|maximumLength
argument_list|,
name|len
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|advanceReadPointer
name|bool
name|QNonContiguousByteDeviceBufferImpl
operator|::
name|advanceReadPointer
parameter_list|(
name|qint64
name|amount
parameter_list|)
block|{
return|return
name|arrayImpl
operator|->
name|advanceReadPointer
argument_list|(
name|amount
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|atEnd
name|bool
name|QNonContiguousByteDeviceBufferImpl
operator|::
name|atEnd
parameter_list|()
block|{
return|return
name|arrayImpl
operator|->
name|atEnd
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|reset
name|bool
name|QNonContiguousByteDeviceBufferImpl
operator|::
name|reset
parameter_list|()
block|{
if|if
condition|(
name|resetDisabled
condition|)
return|return
literal|false
return|;
return|return
name|arrayImpl
operator|->
name|reset
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|size
name|qint64
name|QNonContiguousByteDeviceBufferImpl
operator|::
name|size
parameter_list|()
block|{
return|return
name|arrayImpl
operator|->
name|size
argument_list|()
return|;
block|}
end_function
begin_constructor
DECL|function|QNonContiguousByteDeviceByteArrayImpl
name|QNonContiguousByteDeviceByteArrayImpl
operator|::
name|QNonContiguousByteDeviceByteArrayImpl
parameter_list|(
name|QByteArray
modifier|*
name|ba
parameter_list|)
member_init_list|:
name|QNonContiguousByteDevice
argument_list|()
member_init_list|,
name|currentPosition
argument_list|(
literal|0
argument_list|)
block|{
name|byteArray
operator|=
name|ba
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QNonContiguousByteDeviceByteArrayImpl
name|QNonContiguousByteDeviceByteArrayImpl
operator|::
name|~
name|QNonContiguousByteDeviceByteArrayImpl
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|readPointer
specifier|const
name|char
modifier|*
name|QNonContiguousByteDeviceByteArrayImpl
operator|::
name|readPointer
parameter_list|(
name|qint64
name|maximumLength
parameter_list|,
name|qint64
modifier|&
name|len
parameter_list|)
block|{
if|if
condition|(
name|atEnd
argument_list|()
condition|)
block|{
name|len
operator|=
operator|-
literal|1
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
name|maximumLength
operator|!=
operator|-
literal|1
condition|)
name|len
operator|=
name|qMin
argument_list|(
name|maximumLength
argument_list|,
name|size
argument_list|()
operator|-
name|currentPosition
argument_list|)
expr_stmt|;
else|else
name|len
operator|=
name|size
argument_list|()
operator|-
name|currentPosition
expr_stmt|;
return|return
name|byteArray
operator|->
name|constData
argument_list|()
operator|+
name|currentPosition
return|;
block|}
end_function
begin_function
DECL|function|advanceReadPointer
name|bool
name|QNonContiguousByteDeviceByteArrayImpl
operator|::
name|advanceReadPointer
parameter_list|(
name|qint64
name|amount
parameter_list|)
block|{
name|currentPosition
operator|+=
name|amount
expr_stmt|;
emit|emit
name|readProgress
argument_list|(
name|currentPosition
argument_list|,
name|size
argument_list|()
argument_list|)
emit|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|atEnd
name|bool
name|QNonContiguousByteDeviceByteArrayImpl
operator|::
name|atEnd
parameter_list|()
block|{
return|return
name|currentPosition
operator|>=
name|size
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|reset
name|bool
name|QNonContiguousByteDeviceByteArrayImpl
operator|::
name|reset
parameter_list|()
block|{
if|if
condition|(
name|resetDisabled
condition|)
return|return
literal|false
return|;
name|currentPosition
operator|=
literal|0
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|size
name|qint64
name|QNonContiguousByteDeviceByteArrayImpl
operator|::
name|size
parameter_list|()
block|{
return|return
name|byteArray
operator|->
name|size
argument_list|()
return|;
block|}
end_function
begin_constructor
DECL|function|QNonContiguousByteDeviceRingBufferImpl
name|QNonContiguousByteDeviceRingBufferImpl
operator|::
name|QNonContiguousByteDeviceRingBufferImpl
parameter_list|(
name|QSharedPointer
argument_list|<
name|QRingBuffer
argument_list|>
name|rb
parameter_list|)
member_init_list|:
name|QNonContiguousByteDevice
argument_list|()
member_init_list|,
name|currentPosition
argument_list|(
literal|0
argument_list|)
block|{
name|ringBuffer
operator|=
name|rb
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QNonContiguousByteDeviceRingBufferImpl
name|QNonContiguousByteDeviceRingBufferImpl
operator|::
name|~
name|QNonContiguousByteDeviceRingBufferImpl
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|readPointer
specifier|const
name|char
modifier|*
name|QNonContiguousByteDeviceRingBufferImpl
operator|::
name|readPointer
parameter_list|(
name|qint64
name|maximumLength
parameter_list|,
name|qint64
modifier|&
name|len
parameter_list|)
block|{
if|if
condition|(
name|atEnd
argument_list|()
condition|)
block|{
name|len
operator|=
operator|-
literal|1
expr_stmt|;
return|return
literal|0
return|;
block|}
specifier|const
name|char
modifier|*
name|returnValue
init|=
name|ringBuffer
operator|->
name|readPointerAtPosition
argument_list|(
name|currentPosition
argument_list|,
name|len
argument_list|)
decl_stmt|;
if|if
condition|(
name|maximumLength
operator|!=
operator|-
literal|1
condition|)
name|len
operator|=
name|qMin
argument_list|(
name|len
argument_list|,
name|maximumLength
argument_list|)
expr_stmt|;
return|return
name|returnValue
return|;
block|}
end_function
begin_function
DECL|function|advanceReadPointer
name|bool
name|QNonContiguousByteDeviceRingBufferImpl
operator|::
name|advanceReadPointer
parameter_list|(
name|qint64
name|amount
parameter_list|)
block|{
name|currentPosition
operator|+=
name|amount
expr_stmt|;
emit|emit
name|readProgress
argument_list|(
name|currentPosition
argument_list|,
name|size
argument_list|()
argument_list|)
emit|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|atEnd
name|bool
name|QNonContiguousByteDeviceRingBufferImpl
operator|::
name|atEnd
parameter_list|()
block|{
return|return
name|currentPosition
operator|>=
name|size
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|reset
name|bool
name|QNonContiguousByteDeviceRingBufferImpl
operator|::
name|reset
parameter_list|()
block|{
if|if
condition|(
name|resetDisabled
condition|)
return|return
literal|false
return|;
name|currentPosition
operator|=
literal|0
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|size
name|qint64
name|QNonContiguousByteDeviceRingBufferImpl
operator|::
name|size
parameter_list|()
block|{
return|return
name|ringBuffer
operator|->
name|size
argument_list|()
return|;
block|}
end_function
begin_constructor
DECL|function|QNonContiguousByteDeviceIoDeviceImpl
name|QNonContiguousByteDeviceIoDeviceImpl
operator|::
name|QNonContiguousByteDeviceIoDeviceImpl
parameter_list|(
name|QIODevice
modifier|*
name|d
parameter_list|)
member_init_list|:
name|QNonContiguousByteDevice
argument_list|()
member_init_list|,
name|currentReadBuffer
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|currentReadBufferSize
argument_list|(
literal|16
operator|*
literal|1024
argument_list|)
member_init_list|,
name|currentReadBufferAmount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|currentReadBufferPosition
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|totalAdvancements
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|eof
argument_list|(
literal|false
argument_list|)
block|{
name|device
operator|=
name|d
expr_stmt|;
name|initialPosition
operator|=
name|d
operator|->
name|pos
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|device
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|device
argument_list|,
name|SIGNAL
argument_list|(
name|readChannelFinished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QNonContiguousByteDeviceIoDeviceImpl
name|QNonContiguousByteDeviceIoDeviceImpl
operator|::
name|~
name|QNonContiguousByteDeviceIoDeviceImpl
parameter_list|()
block|{
operator|delete
name|currentReadBuffer
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|readPointer
specifier|const
name|char
modifier|*
name|QNonContiguousByteDeviceIoDeviceImpl
operator|::
name|readPointer
parameter_list|(
name|qint64
name|maximumLength
parameter_list|,
name|qint64
modifier|&
name|len
parameter_list|)
block|{
if|if
condition|(
name|eof
operator|==
literal|true
condition|)
block|{
name|len
operator|=
operator|-
literal|1
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
name|currentReadBuffer
operator|==
literal|0
condition|)
name|currentReadBuffer
operator|=
operator|new
name|QByteArray
argument_list|(
name|currentReadBufferSize
argument_list|,
literal|'\0'
argument_list|)
expr_stmt|;
comment|// lazy alloc
if|if
condition|(
name|maximumLength
operator|==
operator|-
literal|1
condition|)
name|maximumLength
operator|=
name|currentReadBufferSize
expr_stmt|;
if|if
condition|(
name|currentReadBufferAmount
operator|-
name|currentReadBufferPosition
operator|>
literal|0
condition|)
block|{
name|len
operator|=
name|currentReadBufferAmount
operator|-
name|currentReadBufferPosition
expr_stmt|;
return|return
name|currentReadBuffer
operator|->
name|data
argument_list|()
operator|+
name|currentReadBufferPosition
return|;
block|}
name|qint64
name|haveRead
init|=
name|device
operator|->
name|read
argument_list|(
name|currentReadBuffer
operator|->
name|data
argument_list|()
argument_list|,
name|qMin
argument_list|(
name|maximumLength
argument_list|,
name|currentReadBufferSize
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|haveRead
operator|==
operator|-
literal|1
operator|)
operator|||
operator|(
name|haveRead
operator|==
literal|0
operator|&&
name|device
operator|->
name|atEnd
argument_list|()
operator|&&
operator|!
name|device
operator|->
name|isSequential
argument_list|()
operator|)
condition|)
block|{
name|eof
operator|=
literal|true
expr_stmt|;
name|len
operator|=
operator|-
literal|1
expr_stmt|;
comment|// size was unknown before, emit a readProgress with the final size
if|if
condition|(
name|size
argument_list|()
operator|==
operator|-
literal|1
condition|)
emit|emit
name|readProgress
argument_list|(
name|totalAdvancements
argument_list|,
name|totalAdvancements
argument_list|)
emit|;
return|return
literal|0
return|;
block|}
name|currentReadBufferAmount
operator|=
name|haveRead
expr_stmt|;
name|currentReadBufferPosition
operator|=
literal|0
expr_stmt|;
name|len
operator|=
name|haveRead
expr_stmt|;
return|return
name|currentReadBuffer
operator|->
name|data
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|advanceReadPointer
name|bool
name|QNonContiguousByteDeviceIoDeviceImpl
operator|::
name|advanceReadPointer
parameter_list|(
name|qint64
name|amount
parameter_list|)
block|{
name|totalAdvancements
operator|+=
name|amount
expr_stmt|;
comment|// normal advancement
name|currentReadBufferPosition
operator|+=
name|amount
expr_stmt|;
if|if
condition|(
name|size
argument_list|()
operator|==
operator|-
literal|1
condition|)
emit|emit
name|readProgress
argument_list|(
name|totalAdvancements
argument_list|,
name|totalAdvancements
argument_list|)
emit|;
else|else
emit|emit
name|readProgress
argument_list|(
name|totalAdvancements
argument_list|,
name|size
argument_list|()
argument_list|)
emit|;
comment|// advancing over that what has actually been read before
if|if
condition|(
name|currentReadBufferPosition
operator|>
name|currentReadBufferAmount
condition|)
block|{
name|qint64
name|i
init|=
name|currentReadBufferPosition
operator|-
name|currentReadBufferAmount
decl_stmt|;
while|while
condition|(
name|i
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|device
operator|->
name|getChar
argument_list|(
literal|0
argument_list|)
operator|==
literal|false
condition|)
block|{
emit|emit
name|readProgress
argument_list|(
name|totalAdvancements
operator|-
name|i
argument_list|,
name|size
argument_list|()
argument_list|)
emit|;
return|return
literal|false
return|;
comment|// ### FIXME handle eof
block|}
name|i
operator|--
expr_stmt|;
block|}
name|currentReadBufferPosition
operator|=
literal|0
expr_stmt|;
name|currentReadBufferAmount
operator|=
literal|0
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|atEnd
name|bool
name|QNonContiguousByteDeviceIoDeviceImpl
operator|::
name|atEnd
parameter_list|()
block|{
return|return
name|eof
operator|==
literal|true
return|;
block|}
end_function
begin_function
DECL|function|reset
name|bool
name|QNonContiguousByteDeviceIoDeviceImpl
operator|::
name|reset
parameter_list|()
block|{
if|if
condition|(
name|resetDisabled
condition|)
return|return
literal|false
return|;
name|bool
name|reset
init|=
operator|(
name|initialPosition
operator|==
literal|0
operator|)
condition|?
name|device
operator|->
name|reset
argument_list|()
else|:
name|device
operator|->
name|seek
argument_list|(
name|initialPosition
argument_list|)
decl_stmt|;
if|if
condition|(
name|reset
condition|)
block|{
name|eof
operator|=
literal|false
expr_stmt|;
comment|// assume eof is false, it will be true after a read has been attempted
name|totalAdvancements
operator|=
literal|0
expr_stmt|;
comment|//reset the progress counter
if|if
condition|(
name|currentReadBuffer
condition|)
block|{
operator|delete
name|currentReadBuffer
expr_stmt|;
name|currentReadBuffer
operator|=
literal|0
expr_stmt|;
block|}
name|currentReadBufferAmount
operator|=
literal|0
expr_stmt|;
name|currentReadBufferPosition
operator|=
literal|0
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|size
name|qint64
name|QNonContiguousByteDeviceIoDeviceImpl
operator|::
name|size
parameter_list|()
block|{
comment|// note that this is different from the size() implementation of QIODevice!
if|if
condition|(
name|device
operator|->
name|isSequential
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|device
operator|->
name|size
argument_list|()
operator|-
name|initialPosition
return|;
block|}
end_function
begin_constructor
DECL|function|QByteDeviceWrappingIoDevice
name|QByteDeviceWrappingIoDevice
operator|::
name|QByteDeviceWrappingIoDevice
parameter_list|(
name|QNonContiguousByteDevice
modifier|*
name|bd
parameter_list|)
member_init_list|:
name|QIODevice
argument_list|(
operator|(
name|QObject
operator|*
operator|)
literal|0
argument_list|)
block|{
name|byteDevice
operator|=
name|bd
expr_stmt|;
name|connect
argument_list|(
name|bd
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|open
argument_list|(
name|ReadOnly
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QByteDeviceWrappingIoDevice
name|QByteDeviceWrappingIoDevice
operator|::
name|~
name|QByteDeviceWrappingIoDevice
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|isSequential
name|bool
name|QByteDeviceWrappingIoDevice
operator|::
name|isSequential
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|byteDevice
operator|->
name|size
argument_list|()
operator|==
operator|-
literal|1
operator|)
return|;
block|}
end_function
begin_function
DECL|function|atEnd
name|bool
name|QByteDeviceWrappingIoDevice
operator|::
name|atEnd
parameter_list|()
specifier|const
block|{
return|return
name|byteDevice
operator|->
name|atEnd
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|reset
name|bool
name|QByteDeviceWrappingIoDevice
operator|::
name|reset
parameter_list|()
block|{
return|return
name|byteDevice
operator|->
name|reset
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|size
name|qint64
name|QByteDeviceWrappingIoDevice
operator|::
name|size
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|isSequential
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|byteDevice
operator|->
name|size
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|readData
name|qint64
name|QByteDeviceWrappingIoDevice
operator|::
name|readData
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxSize
parameter_list|)
block|{
name|qint64
name|len
decl_stmt|;
specifier|const
name|char
modifier|*
name|readPointer
init|=
name|byteDevice
operator|->
name|readPointer
argument_list|(
name|maxSize
argument_list|,
name|len
argument_list|)
decl_stmt|;
if|if
condition|(
name|len
operator|==
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
name|memcpy
argument_list|(
name|data
argument_list|,
name|readPointer
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|byteDevice
operator|->
name|advanceReadPointer
argument_list|(
name|len
argument_list|)
expr_stmt|;
return|return
name|len
return|;
block|}
end_function
begin_function
DECL|function|writeData
name|qint64
name|QByteDeviceWrappingIoDevice
operator|::
name|writeData
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxSize
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|maxSize
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_comment
comment|/*!     \class QNonContiguousByteDeviceFactory     \inmodule QtCore     \since 4.6      Creates a QNonContiguousByteDevice out of a QIODevice,     QByteArray etc.      \sa QNonContiguousByteDevice      \internal */
end_comment
begin_comment
comment|/*!     \fn static QNonContiguousByteDevice* QNonContiguousByteDeviceFactory::create(QIODevice *device)      Create a QNonContiguousByteDevice out of a QIODevice.     For QFile, QBuffer and all other QIoDevice, sequential or not.      \internal */
end_comment
begin_function
DECL|function|create
name|QNonContiguousByteDevice
modifier|*
name|QNonContiguousByteDeviceFactory
operator|::
name|create
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
block|{
comment|// shortcut if it is a QBuffer
if|if
condition|(
name|QBuffer
modifier|*
name|buffer
init|=
name|qobject_cast
argument_list|<
name|QBuffer
operator|*
argument_list|>
argument_list|(
name|device
argument_list|)
condition|)
block|{
return|return
operator|new
name|QNonContiguousByteDeviceBufferImpl
argument_list|(
name|buffer
argument_list|)
return|;
block|}
comment|// ### FIXME special case if device is a QFile that supports map()
comment|// then we can actually deal with the file without using read/peek
comment|// generic QIODevice
return|return
operator|new
name|QNonContiguousByteDeviceIoDeviceImpl
argument_list|(
name|device
argument_list|)
return|;
comment|// FIXME
block|}
end_function
begin_comment
comment|/*!     Create a QNonContiguousByteDevice out of a QIODevice, return it in a QSharedPointer.     For QFile, QBuffer and all other QIODevice, sequential or not.      \internal */
end_comment
begin_function
DECL|function|createShared
name|QSharedPointer
argument_list|<
name|QNonContiguousByteDevice
argument_list|>
name|QNonContiguousByteDeviceFactory
operator|::
name|createShared
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
block|{
comment|// shortcut if it is a QBuffer
if|if
condition|(
name|QBuffer
modifier|*
name|buffer
init|=
name|qobject_cast
argument_list|<
name|QBuffer
operator|*
argument_list|>
argument_list|(
name|device
argument_list|)
condition|)
return|return
name|QSharedPointer
argument_list|<
name|QNonContiguousByteDeviceBufferImpl
argument_list|>
operator|::
name|create
argument_list|(
name|buffer
argument_list|)
return|;
comment|// ### FIXME special case if device is a QFile that supports map()
comment|// then we can actually deal with the file without using read/peek
comment|// generic QIODevice
return|return
name|QSharedPointer
argument_list|<
name|QNonContiguousByteDeviceIoDeviceImpl
argument_list|>
operator|::
name|create
argument_list|(
name|device
argument_list|)
return|;
comment|// FIXME
block|}
end_function
begin_comment
comment|/*!     \fn static QNonContiguousByteDevice* QNonContiguousByteDeviceFactory::create(QSharedPointer<QRingBuffer> ringBuffer)      Create a QNonContiguousByteDevice out of a QRingBuffer.      \internal */
end_comment
begin_function
DECL|function|create
name|QNonContiguousByteDevice
modifier|*
name|QNonContiguousByteDeviceFactory
operator|::
name|create
parameter_list|(
name|QSharedPointer
argument_list|<
name|QRingBuffer
argument_list|>
name|ringBuffer
parameter_list|)
block|{
return|return
operator|new
name|QNonContiguousByteDeviceRingBufferImpl
argument_list|(
name|ringBuffer
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Create a QNonContiguousByteDevice out of a QRingBuffer, return it in a QSharedPointer.      \internal */
end_comment
begin_function
DECL|function|createShared
name|QSharedPointer
argument_list|<
name|QNonContiguousByteDevice
argument_list|>
name|QNonContiguousByteDeviceFactory
operator|::
name|createShared
parameter_list|(
name|QSharedPointer
argument_list|<
name|QRingBuffer
argument_list|>
name|ringBuffer
parameter_list|)
block|{
return|return
name|QSharedPointer
argument_list|<
name|QNonContiguousByteDeviceRingBufferImpl
argument_list|>
operator|::
name|create
argument_list|(
name|qMove
argument_list|(
name|ringBuffer
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn static QNonContiguousByteDevice* QNonContiguousByteDeviceFactory::create(QByteArray *byteArray)      Create a QNonContiguousByteDevice out of a QByteArray.      \internal */
end_comment
begin_function
DECL|function|create
name|QNonContiguousByteDevice
modifier|*
name|QNonContiguousByteDeviceFactory
operator|::
name|create
parameter_list|(
name|QByteArray
modifier|*
name|byteArray
parameter_list|)
block|{
return|return
operator|new
name|QNonContiguousByteDeviceByteArrayImpl
argument_list|(
name|byteArray
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Create a QNonContiguousByteDevice out of a QByteArray.      \internal */
end_comment
begin_function
DECL|function|createShared
name|QSharedPointer
argument_list|<
name|QNonContiguousByteDevice
argument_list|>
name|QNonContiguousByteDeviceFactory
operator|::
name|createShared
parameter_list|(
name|QByteArray
modifier|*
name|byteArray
parameter_list|)
block|{
return|return
name|QSharedPointer
argument_list|<
name|QNonContiguousByteDeviceByteArrayImpl
argument_list|>
operator|::
name|create
argument_list|(
name|byteArray
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn static QIODevice* QNonContiguousByteDeviceFactory::wrap(QNonContiguousByteDevice* byteDevice)      Wrap the \a byteDevice (possibly again) into a QIODevice.      \internal */
end_comment
begin_function
DECL|function|wrap
name|QIODevice
modifier|*
name|QNonContiguousByteDeviceFactory
operator|::
name|wrap
parameter_list|(
name|QNonContiguousByteDevice
modifier|*
name|byteDevice
parameter_list|)
block|{
comment|// ### FIXME if it already has been based on QIoDevice, we could that one out again
comment|// and save some calling
comment|// needed for FTP backend
return|return
operator|new
name|QByteDeviceWrappingIoDevice
argument_list|(
name|byteDevice
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
