begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBYTEDATA_H
end_ifndef
begin_define
DECL|macro|QBYTEDATA_H
define|#
directive|define
name|QBYTEDATA_H
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
file|<qbytearray.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// this class handles a list of QByteArrays. It is a variant of QRingBuffer
comment|// that avoid malloc/realloc/memcpy.
name|class
name|QByteDataBuffer
block|{
name|private
label|:
name|QList
operator|<
name|QByteArray
operator|>
name|buffers
expr_stmt|;
name|qint64
name|bufferCompleteSize
decl_stmt|;
name|public
label|:
name|QByteDataBuffer
argument_list|()
operator|:
name|bufferCompleteSize
argument_list|(
literal|0
argument_list|)
block|{     }
operator|~
name|QByteDataBuffer
argument_list|()
block|{
name|clear
argument_list|()
block|;     }
specifier|inline
name|void
name|append
argument_list|(
argument|QByteDataBuffer& other
argument_list|)
block|{
if|if
condition|(
name|other
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|buffers
operator|.
name|append
argument_list|(
name|other
operator|.
name|buffers
argument_list|)
expr_stmt|;
name|bufferCompleteSize
operator|+=
name|other
operator|.
name|byteAmount
argument_list|()
expr_stmt|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|void
name|append
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|bd
parameter_list|)
block|{
if|if
condition|(
name|bd
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|buffers
operator|.
name|append
argument_list|(
name|bd
argument_list|)
expr_stmt|;
name|bufferCompleteSize
operator|+=
name|bd
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|prepend
parameter_list|(
name|QByteArray
modifier|&
name|bd
parameter_list|)
block|{
if|if
condition|(
name|bd
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|buffers
operator|.
name|prepend
argument_list|(
name|bd
argument_list|)
expr_stmt|;
name|bufferCompleteSize
operator|+=
name|bd
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// return the first QByteData. User of this function has to qFree() its .data!
end_comment
begin_comment
comment|// preferably use this function to read data.
end_comment
begin_function
specifier|inline
name|QByteArray
name|read
parameter_list|()
block|{
name|bufferCompleteSize
operator|-=
name|buffers
operator|.
name|first
argument_list|()
operator|.
name|size
argument_list|()
expr_stmt|;
return|return
name|buffers
operator|.
name|takeFirst
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// return everything. User of this function has to qFree() its .data!
end_comment
begin_comment
comment|// avoid to use this, it might malloc and memcpy.
end_comment
begin_function
specifier|inline
name|QByteArray
name|readAll
parameter_list|()
block|{
return|return
name|read
argument_list|(
name|byteAmount
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// return amount. User of this function has to qFree() its .data!
end_comment
begin_comment
comment|// avoid to use this, it might malloc and memcpy.
end_comment
begin_function
specifier|inline
name|QByteArray
name|read
parameter_list|(
name|qint64
name|amount
parameter_list|)
block|{
name|amount
operator|=
name|qMin
argument_list|(
name|byteAmount
argument_list|()
argument_list|,
name|amount
argument_list|)
expr_stmt|;
name|QByteArray
name|byteData
decl_stmt|;
name|byteData
operator|.
name|resize
argument_list|(
name|amount
argument_list|)
expr_stmt|;
name|read
argument_list|(
name|byteData
operator|.
name|data
argument_list|()
argument_list|,
name|byteData
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|byteData
return|;
block|}
end_function
begin_comment
comment|// return amount bytes. User of this function has to qFree() its .data!
end_comment
begin_comment
comment|// avoid to use this, it will memcpy.
end_comment
begin_function
name|qint64
name|read
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
name|qint64
name|amount
parameter_list|)
block|{
name|amount
operator|=
name|qMin
argument_list|(
name|amount
argument_list|,
name|byteAmount
argument_list|()
argument_list|)
expr_stmt|;
name|qint64
name|originalAmount
init|=
name|amount
decl_stmt|;
name|char
modifier|*
name|writeDst
init|=
name|dst
decl_stmt|;
while|while
condition|(
name|amount
operator|>
literal|0
condition|)
block|{
name|QByteArray
name|first
init|=
name|buffers
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
if|if
condition|(
name|amount
operator|>=
name|first
operator|.
name|size
argument_list|()
condition|)
block|{
comment|// take it completely
name|bufferCompleteSize
operator|-=
name|first
operator|.
name|size
argument_list|()
expr_stmt|;
name|amount
operator|-=
name|first
operator|.
name|size
argument_list|()
expr_stmt|;
name|memcpy
argument_list|(
name|writeDst
argument_list|,
name|first
operator|.
name|constData
argument_list|()
argument_list|,
name|first
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|writeDst
operator|+=
name|first
operator|.
name|size
argument_list|()
expr_stmt|;
name|first
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|// take a part of it& it is the last one to take
name|bufferCompleteSize
operator|-=
name|amount
expr_stmt|;
name|memcpy
argument_list|(
name|writeDst
argument_list|,
name|first
operator|.
name|constData
argument_list|()
argument_list|,
name|amount
argument_list|)
expr_stmt|;
name|qint64
name|newFirstSize
init|=
name|first
operator|.
name|size
argument_list|()
operator|-
name|amount
decl_stmt|;
name|QByteArray
name|newFirstData
decl_stmt|;
name|newFirstData
operator|.
name|resize
argument_list|(
name|newFirstSize
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|newFirstData
operator|.
name|data
argument_list|()
argument_list|,
name|first
operator|.
name|constData
argument_list|()
operator|+
name|amount
argument_list|,
name|newFirstSize
argument_list|)
expr_stmt|;
name|buffers
operator|.
name|prepend
argument_list|(
name|newFirstData
argument_list|)
expr_stmt|;
name|amount
operator|=
literal|0
expr_stmt|;
name|first
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
return|return
name|originalAmount
return|;
block|}
end_function
begin_function
specifier|inline
name|char
name|getChar
parameter_list|()
block|{
name|char
name|c
decl_stmt|;
name|read
argument_list|(
operator|&
name|c
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
name|c
return|;
block|}
end_function
begin_function
specifier|inline
name|void
name|clear
parameter_list|()
block|{
name|buffers
operator|.
name|clear
argument_list|()
expr_stmt|;
name|bufferCompleteSize
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|// The byte count of all QByteArrays
end_comment
begin_expr_stmt
specifier|inline
name|qint64
name|byteAmount
argument_list|()
specifier|const
block|{
return|return
name|bufferCompleteSize
return|;
block|}
end_expr_stmt
begin_comment
comment|// the number of QByteArrays
end_comment
begin_expr_stmt
specifier|inline
name|qint64
name|bufferCount
argument_list|()
specifier|const
block|{
return|return
name|buffers
operator|.
name|length
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|byteAmount
argument_list|()
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|qint64
name|sizeNextBlock
argument_list|()
specifier|const
block|{
if|if
condition|(
name|buffers
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|0
return|;
else|else
return|return
name|buffers
operator|.
name|first
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|QByteArray
modifier|&
name|operator
function|[]
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|buffers
index|[
name|i
index|]
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|bool
name|canReadLine
argument_list|()
specifier|const
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
name|buffers
operator|.
name|length
argument_list|()
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|buffers
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|contains
argument_list|(
literal|'\n'
argument_list|)
condition|)
return|return
name|true
return|;
end_expr_stmt
begin_return
return|return
name|false
return|;
end_return
begin_empty_stmt
unit|} }
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
comment|// QBYTEDATA_H
end_comment
end_unit
