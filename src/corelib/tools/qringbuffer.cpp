begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2015 Alex Trotsenko<alex1973tr@gmail.com> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"private/qringbuffer_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qbytearray_p.h"
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \internal      Access the bytes at a specified position the out-variable length will     contain the amount of bytes readable from there, e.g. the amount still     the same QByteArray */
DECL|function|readPointerAtPosition
specifier|const
name|char
modifier|*
name|QRingBuffer
operator|::
name|readPointerAtPosition
parameter_list|(
name|qint64
name|pos
parameter_list|,
name|qint64
modifier|&
name|length
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|pos
operator|>=
literal|0
condition|)
block|{
name|pos
operator|+=
name|head
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|buffers
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|length
operator|=
operator|(
name|i
operator|==
name|tailBuffer
condition|?
name|tail
else|:
name|buffers
index|[
name|i
index|]
operator|.
name|size
argument_list|()
operator|)
expr_stmt|;
if|if
condition|(
name|length
operator|>
name|pos
condition|)
block|{
name|length
operator|-=
name|pos
expr_stmt|;
return|return
name|buffers
index|[
name|i
index|]
operator|.
name|constData
argument_list|()
operator|+
name|pos
return|;
block|}
name|pos
operator|-=
name|length
expr_stmt|;
block|}
block|}
name|length
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|free
name|void
name|QRingBuffer
operator|::
name|free
parameter_list|(
name|qint64
name|bytes
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|bytes
operator|<=
name|bufferSize
argument_list|)
expr_stmt|;
while|while
condition|(
name|bytes
operator|>
literal|0
condition|)
block|{
specifier|const
name|qint64
name|blockSize
init|=
name|buffers
operator|.
name|constFirst
argument_list|()
operator|.
name|size
argument_list|()
operator|-
name|head
decl_stmt|;
if|if
condition|(
name|tailBuffer
operator|==
literal|0
operator|||
name|blockSize
operator|>
name|bytes
condition|)
block|{
comment|// keep a single block around if it does not exceed
comment|// the basic block size, to avoid repeated allocations
comment|// between uses of the buffer
if|if
condition|(
name|bufferSize
operator|<=
name|bytes
condition|)
block|{
if|if
condition|(
name|buffers
operator|.
name|constFirst
argument_list|()
operator|.
name|size
argument_list|()
operator|<=
name|basicBlockSize
condition|)
block|{
name|bufferSize
operator|=
literal|0
expr_stmt|;
name|head
operator|=
name|tail
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|clear
argument_list|()
expr_stmt|;
comment|// try to minify/squeeze us
block|}
block|}
else|else
block|{
name|Q_ASSERT
argument_list|(
name|bytes
operator|<
name|MaxByteArraySize
argument_list|)
expr_stmt|;
name|head
operator|+=
name|int
argument_list|(
name|bytes
argument_list|)
expr_stmt|;
name|bufferSize
operator|-=
name|bytes
expr_stmt|;
block|}
return|return;
block|}
name|bufferSize
operator|-=
name|blockSize
expr_stmt|;
name|bytes
operator|-=
name|blockSize
expr_stmt|;
name|buffers
operator|.
name|removeFirst
argument_list|()
expr_stmt|;
operator|--
name|tailBuffer
expr_stmt|;
name|head
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|reserve
name|char
modifier|*
name|QRingBuffer
operator|::
name|reserve
parameter_list|(
name|qint64
name|bytes
parameter_list|)
block|{
if|if
condition|(
name|bytes
operator|<=
literal|0
operator|||
name|bytes
operator|>=
name|MaxByteArraySize
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|buffers
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|buffers
operator|.
name|append
argument_list|(
name|QByteArray
argument_list|()
argument_list|)
expr_stmt|;
name|buffers
operator|.
name|first
argument_list|()
operator|.
name|resize
argument_list|(
name|qMax
argument_list|(
name|basicBlockSize
argument_list|,
name|int
argument_list|(
name|bytes
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|qint64
name|newSize
init|=
name|bytes
operator|+
name|tail
decl_stmt|;
comment|// if need buffer reallocation
if|if
condition|(
name|newSize
operator|>
name|buffers
operator|.
name|constLast
argument_list|()
operator|.
name|size
argument_list|()
condition|)
block|{
if|if
condition|(
name|newSize
operator|>
name|buffers
operator|.
name|constLast
argument_list|()
operator|.
name|capacity
argument_list|()
operator|&&
operator|(
name|tail
operator|>=
name|basicBlockSize
operator|||
name|newSize
operator|>=
name|MaxByteArraySize
operator|)
condition|)
block|{
comment|// shrink this buffer to its current size
name|buffers
operator|.
name|last
argument_list|()
operator|.
name|resize
argument_list|(
name|tail
argument_list|)
expr_stmt|;
comment|// create a new QByteArray
name|buffers
operator|.
name|append
argument_list|(
name|QByteArray
argument_list|()
argument_list|)
expr_stmt|;
operator|++
name|tailBuffer
expr_stmt|;
name|tail
operator|=
literal|0
expr_stmt|;
block|}
name|buffers
operator|.
name|last
argument_list|()
operator|.
name|resize
argument_list|(
name|qMax
argument_list|(
name|basicBlockSize
argument_list|,
name|tail
operator|+
name|int
argument_list|(
name|bytes
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|char
modifier|*
name|writePtr
init|=
name|buffers
operator|.
name|last
argument_list|()
operator|.
name|data
argument_list|()
operator|+
name|tail
decl_stmt|;
name|bufferSize
operator|+=
name|bytes
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|bytes
operator|<
name|MaxByteArraySize
argument_list|)
expr_stmt|;
name|tail
operator|+=
name|int
argument_list|(
name|bytes
argument_list|)
expr_stmt|;
return|return
name|writePtr
return|;
block|}
end_function
begin_comment
comment|/*!     \internal      Allocate data at buffer head */
end_comment
begin_function
DECL|function|reserveFront
name|char
modifier|*
name|QRingBuffer
operator|::
name|reserveFront
parameter_list|(
name|qint64
name|bytes
parameter_list|)
block|{
if|if
condition|(
name|bytes
operator|<=
literal|0
operator|||
name|bytes
operator|>=
name|MaxByteArraySize
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|head
operator|<
name|bytes
condition|)
block|{
if|if
condition|(
name|buffers
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|buffers
operator|.
name|append
argument_list|(
name|QByteArray
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|buffers
operator|.
name|first
argument_list|()
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
name|head
argument_list|)
expr_stmt|;
if|if
condition|(
name|tailBuffer
operator|==
literal|0
condition|)
name|tail
operator|-=
name|head
expr_stmt|;
block|}
name|head
operator|=
name|qMax
argument_list|(
name|basicBlockSize
argument_list|,
name|int
argument_list|(
name|bytes
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|bufferSize
operator|==
literal|0
condition|)
block|{
name|tail
operator|=
name|head
expr_stmt|;
block|}
else|else
block|{
name|buffers
operator|.
name|prepend
argument_list|(
name|QByteArray
argument_list|()
argument_list|)
expr_stmt|;
operator|++
name|tailBuffer
expr_stmt|;
block|}
name|buffers
operator|.
name|first
argument_list|()
operator|.
name|resize
argument_list|(
name|head
argument_list|)
expr_stmt|;
block|}
name|head
operator|-=
name|int
argument_list|(
name|bytes
argument_list|)
expr_stmt|;
name|bufferSize
operator|+=
name|bytes
expr_stmt|;
return|return
name|buffers
operator|.
name|first
argument_list|()
operator|.
name|data
argument_list|()
operator|+
name|head
return|;
block|}
end_function
begin_function
DECL|function|chop
name|void
name|QRingBuffer
operator|::
name|chop
parameter_list|(
name|qint64
name|bytes
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|bytes
operator|<=
name|bufferSize
argument_list|)
expr_stmt|;
while|while
condition|(
name|bytes
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|tailBuffer
operator|==
literal|0
operator|||
name|tail
operator|>
name|bytes
condition|)
block|{
comment|// keep a single block around if it does not exceed
comment|// the basic block size, to avoid repeated allocations
comment|// between uses of the buffer
if|if
condition|(
name|bufferSize
operator|<=
name|bytes
condition|)
block|{
if|if
condition|(
name|buffers
operator|.
name|constFirst
argument_list|()
operator|.
name|size
argument_list|()
operator|<=
name|basicBlockSize
condition|)
block|{
name|bufferSize
operator|=
literal|0
expr_stmt|;
name|head
operator|=
name|tail
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|clear
argument_list|()
expr_stmt|;
comment|// try to minify/squeeze us
block|}
block|}
else|else
block|{
name|Q_ASSERT
argument_list|(
name|bytes
operator|<
name|MaxByteArraySize
argument_list|)
expr_stmt|;
name|tail
operator|-=
name|int
argument_list|(
name|bytes
argument_list|)
expr_stmt|;
name|bufferSize
operator|-=
name|bytes
expr_stmt|;
block|}
return|return;
block|}
name|bufferSize
operator|-=
name|tail
expr_stmt|;
name|bytes
operator|-=
name|tail
expr_stmt|;
name|buffers
operator|.
name|removeLast
argument_list|()
expr_stmt|;
operator|--
name|tailBuffer
expr_stmt|;
name|tail
operator|=
name|buffers
operator|.
name|constLast
argument_list|()
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|clear
name|void
name|QRingBuffer
operator|::
name|clear
parameter_list|()
block|{
if|if
condition|(
name|buffers
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|buffers
operator|.
name|erase
argument_list|(
name|buffers
operator|.
name|begin
argument_list|()
operator|+
literal|1
argument_list|,
name|buffers
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|buffers
operator|.
name|first
argument_list|()
operator|.
name|clear
argument_list|()
expr_stmt|;
name|head
operator|=
name|tail
operator|=
literal|0
expr_stmt|;
name|tailBuffer
operator|=
literal|0
expr_stmt|;
name|bufferSize
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|indexOf
name|qint64
name|QRingBuffer
operator|::
name|indexOf
parameter_list|(
name|char
name|c
parameter_list|,
name|qint64
name|maxLength
parameter_list|,
name|qint64
name|pos
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|maxLength
operator|<=
literal|0
operator|||
name|pos
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
name|qint64
name|index
init|=
operator|-
operator|(
name|pos
operator|+
name|head
operator|)
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
name|buffers
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|qint64
name|nextBlockIndex
init|=
name|qMin
argument_list|(
name|index
operator|+
operator|(
name|i
operator|==
name|tailBuffer
condition|?
name|tail
else|:
name|buffers
index|[
name|i
index|]
operator|.
name|size
argument_list|()
operator|)
argument_list|,
name|maxLength
argument_list|)
decl_stmt|;
if|if
condition|(
name|nextBlockIndex
operator|>
literal|0
condition|)
block|{
specifier|const
name|char
modifier|*
name|ptr
init|=
name|buffers
index|[
name|i
index|]
operator|.
name|constData
argument_list|()
decl_stmt|;
if|if
condition|(
name|index
operator|<
literal|0
condition|)
block|{
name|ptr
operator|-=
name|index
expr_stmt|;
name|index
operator|=
literal|0
expr_stmt|;
block|}
specifier|const
name|char
modifier|*
name|findPtr
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|memchr
argument_list|(
name|ptr
argument_list|,
name|c
argument_list|,
name|nextBlockIndex
operator|-
name|index
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|findPtr
condition|)
return|return
name|qint64
argument_list|(
name|findPtr
operator|-
name|ptr
argument_list|)
operator|+
name|index
operator|+
name|pos
return|;
if|if
condition|(
name|nextBlockIndex
operator|==
name|maxLength
condition|)
return|return
operator|-
literal|1
return|;
block|}
name|index
operator|=
name|nextBlockIndex
expr_stmt|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|read
name|qint64
name|QRingBuffer
operator|::
name|read
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxLength
parameter_list|)
block|{
specifier|const
name|qint64
name|bytesToRead
init|=
name|qMin
argument_list|(
name|size
argument_list|()
argument_list|,
name|maxLength
argument_list|)
decl_stmt|;
name|qint64
name|readSoFar
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|readSoFar
operator|<
name|bytesToRead
condition|)
block|{
specifier|const
name|qint64
name|bytesToReadFromThisBlock
init|=
name|qMin
argument_list|(
name|bytesToRead
operator|-
name|readSoFar
argument_list|,
name|nextDataBlockSize
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|data
condition|)
name|memcpy
argument_list|(
name|data
operator|+
name|readSoFar
argument_list|,
name|readPointer
argument_list|()
argument_list|,
name|bytesToReadFromThisBlock
argument_list|)
expr_stmt|;
name|readSoFar
operator|+=
name|bytesToReadFromThisBlock
expr_stmt|;
name|free
argument_list|(
name|bytesToReadFromThisBlock
argument_list|)
expr_stmt|;
block|}
return|return
name|readSoFar
return|;
block|}
end_function
begin_comment
comment|/*!     \internal      Read an unspecified amount (will read the first buffer) */
end_comment
begin_function
DECL|function|read
name|QByteArray
name|QRingBuffer
operator|::
name|read
parameter_list|()
block|{
if|if
condition|(
name|bufferSize
operator|==
literal|0
condition|)
return|return
name|QByteArray
argument_list|()
return|;
name|QByteArray
name|qba
argument_list|(
name|buffers
operator|.
name|takeFirst
argument_list|()
argument_list|)
decl_stmt|;
name|qba
operator|.
name|reserve
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// avoid that resizing needlessly reallocates
if|if
condition|(
name|tailBuffer
operator|==
literal|0
condition|)
block|{
name|qba
operator|.
name|resize
argument_list|(
name|tail
argument_list|)
expr_stmt|;
name|tail
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
operator|--
name|tailBuffer
expr_stmt|;
block|}
name|qba
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
name|head
argument_list|)
expr_stmt|;
comment|// does nothing if head is 0
name|head
operator|=
literal|0
expr_stmt|;
name|bufferSize
operator|-=
name|qba
operator|.
name|size
argument_list|()
expr_stmt|;
return|return
name|qba
return|;
block|}
end_function
begin_comment
comment|/*!     \internal      Peek the bytes from a specified position */
end_comment
begin_function
DECL|function|peek
name|qint64
name|QRingBuffer
operator|::
name|peek
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxLength
parameter_list|,
name|qint64
name|pos
parameter_list|)
specifier|const
block|{
name|qint64
name|readSoFar
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|pos
operator|>=
literal|0
condition|)
block|{
name|pos
operator|+=
name|head
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|readSoFar
operator|<
name|maxLength
operator|&&
name|i
operator|<
name|buffers
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|qint64
name|blockLength
init|=
operator|(
name|i
operator|==
name|tailBuffer
condition|?
name|tail
else|:
name|buffers
index|[
name|i
index|]
operator|.
name|size
argument_list|()
operator|)
decl_stmt|;
if|if
condition|(
name|pos
operator|<
name|blockLength
condition|)
block|{
name|blockLength
operator|=
name|qMin
argument_list|(
name|blockLength
operator|-
name|pos
argument_list|,
name|maxLength
operator|-
name|readSoFar
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|data
operator|+
name|readSoFar
argument_list|,
name|buffers
index|[
name|i
index|]
operator|.
name|constData
argument_list|()
operator|+
name|pos
argument_list|,
name|blockLength
argument_list|)
expr_stmt|;
name|readSoFar
operator|+=
name|blockLength
expr_stmt|;
name|pos
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|pos
operator|-=
name|blockLength
expr_stmt|;
block|}
block|}
block|}
return|return
name|readSoFar
return|;
block|}
end_function
begin_comment
comment|/*!     \internal      Append bytes from data to the end */
end_comment
begin_function
DECL|function|append
name|void
name|QRingBuffer
operator|::
name|append
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|size
parameter_list|)
block|{
name|char
modifier|*
name|writePointer
init|=
name|reserve
argument_list|(
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|size
operator|==
literal|1
condition|)
operator|*
name|writePointer
operator|=
operator|*
name|data
expr_stmt|;
elseif|else
if|if
condition|(
name|size
condition|)
operator|::
name|memcpy
argument_list|(
name|writePointer
argument_list|,
name|data
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal      Append a new buffer to the end */
end_comment
begin_function
DECL|function|append
name|void
name|QRingBuffer
operator|::
name|append
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|qba
parameter_list|)
block|{
if|if
condition|(
name|tail
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|buffers
operator|.
name|isEmpty
argument_list|()
condition|)
name|buffers
operator|.
name|append
argument_list|(
name|qba
argument_list|)
expr_stmt|;
else|else
name|buffers
operator|.
name|last
argument_list|()
operator|=
name|qba
expr_stmt|;
block|}
else|else
block|{
name|buffers
operator|.
name|last
argument_list|()
operator|.
name|resize
argument_list|(
name|tail
argument_list|)
expr_stmt|;
name|buffers
operator|.
name|append
argument_list|(
name|qba
argument_list|)
expr_stmt|;
operator|++
name|tailBuffer
expr_stmt|;
block|}
name|tail
operator|=
name|qba
operator|.
name|size
argument_list|()
expr_stmt|;
name|bufferSize
operator|+=
name|tail
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readLine
name|qint64
name|QRingBuffer
operator|::
name|readLine
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxLength
parameter_list|)
block|{
if|if
condition|(
operator|!
name|data
operator|||
operator|--
name|maxLength
operator|<=
literal|0
condition|)
return|return
operator|-
literal|1
return|;
name|qint64
name|i
init|=
name|indexOf
argument_list|(
literal|'\n'
argument_list|,
name|maxLength
argument_list|)
decl_stmt|;
name|i
operator|=
name|read
argument_list|(
name|data
argument_list|,
name|i
operator|>=
literal|0
condition|?
operator|(
name|i
operator|+
literal|1
operator|)
else|:
name|maxLength
argument_list|)
expr_stmt|;
comment|// Terminate it.
name|data
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
name|i
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
