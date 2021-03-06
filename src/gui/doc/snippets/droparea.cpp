begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"droparea.h"
end_include
begin_constructor
DECL|function|DropArea
name|DropArea
operator|::
name|DropArea
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QLabel
argument_list|(
name|parent
argument_list|)
block|{
name|setMinimumSize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|setFrameStyle
argument_list|(
name|QFrame
operator|::
name|Sunken
operator||
name|QFrame
operator|::
name|StyledPanel
argument_list|)
expr_stmt|;
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignCenter
argument_list|)
expr_stmt|;
name|setAcceptDrops
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setAutoFillBackground
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|clear
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|dragEnterEvent
name|void
name|DropArea
operator|::
name|dragEnterEvent
parameter_list|(
name|QDragEnterEvent
modifier|*
name|event
parameter_list|)
block|{
name|setText
argument_list|(
name|tr
argument_list|(
literal|"<drop content>"
argument_list|)
argument_list|)
expr_stmt|;
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Highlight
argument_list|)
expr_stmt|;
name|event
operator|->
name|acceptProposedAction
argument_list|()
expr_stmt|;
emit|emit
name|changed
argument_list|(
name|event
operator|->
name|mimeData
argument_list|()
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|dragMoveEvent
name|void
name|DropArea
operator|::
name|dragMoveEvent
parameter_list|(
name|QDragMoveEvent
modifier|*
name|event
parameter_list|)
block|{
name|event
operator|->
name|acceptProposedAction
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|dropEvent
name|void
name|DropArea
operator|::
name|dropEvent
parameter_list|(
name|QDropEvent
modifier|*
name|event
parameter_list|)
block|{
specifier|const
name|QMimeData
modifier|*
name|mimeData
init|=
name|event
operator|->
name|mimeData
argument_list|()
decl_stmt|;
if|if
condition|(
name|mimeData
operator|->
name|hasImage
argument_list|()
condition|)
block|{
name|setPixmap
argument_list|(
name|qvariant_cast
argument_list|<
name|QPixmap
argument_list|>
argument_list|(
name|mimeData
operator|->
name|imageData
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|mimeData
operator|->
name|hasHtml
argument_list|()
condition|)
block|{
name|setText
argument_list|(
name|mimeData
operator|->
name|html
argument_list|()
argument_list|)
expr_stmt|;
name|setTextFormat
argument_list|(
name|Qt
operator|::
name|RichText
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|mimeData
operator|->
name|hasText
argument_list|()
condition|)
block|{
name|setText
argument_list|(
name|mimeData
operator|->
name|text
argument_list|()
argument_list|)
expr_stmt|;
name|setTextFormat
argument_list|(
name|Qt
operator|::
name|PlainText
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Cannot display data"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|)
expr_stmt|;
name|event
operator|->
name|acceptProposedAction
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//![0]
end_comment
begin_function
DECL|function|paste
name|void
name|DropArea
operator|::
name|paste
parameter_list|()
block|{
specifier|const
name|QClipboard
modifier|*
name|clipboard
init|=
name|QApplication
operator|::
name|clipboard
argument_list|()
decl_stmt|;
specifier|const
name|QMimeData
modifier|*
name|mimeData
init|=
name|clipboard
operator|->
name|mimeData
argument_list|()
decl_stmt|;
if|if
condition|(
name|mimeData
operator|->
name|hasImage
argument_list|()
condition|)
block|{
name|setPixmap
argument_list|(
name|qvariant_cast
argument_list|<
name|QPixmap
argument_list|>
argument_list|(
name|mimeData
operator|->
name|imageData
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|mimeData
operator|->
name|hasHtml
argument_list|()
condition|)
block|{
name|setText
argument_list|(
name|mimeData
operator|->
name|html
argument_list|()
argument_list|)
expr_stmt|;
name|setTextFormat
argument_list|(
name|Qt
operator|::
name|RichText
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|mimeData
operator|->
name|hasText
argument_list|()
condition|)
block|{
name|setText
argument_list|(
name|mimeData
operator|->
name|text
argument_list|()
argument_list|)
expr_stmt|;
name|setTextFormat
argument_list|(
name|Qt
operator|::
name|PlainText
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Cannot display data"
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|//![0]
emit|emit
name|changed
argument_list|(
name|mimeData
argument_list|)
emit|;
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|)
expr_stmt|;
comment|//event->acceptProposedAction();
block|}
end_function
begin_function
DECL|function|dragLeaveEvent
name|void
name|DropArea
operator|::
name|dragLeaveEvent
parameter_list|(
name|QDragLeaveEvent
modifier|*
name|event
parameter_list|)
block|{
name|clear
argument_list|()
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clear
name|void
name|DropArea
operator|::
name|clear
parameter_list|()
block|{
name|setText
argument_list|(
name|tr
argument_list|(
literal|"<drop content>"
argument_list|)
argument_list|)
expr_stmt|;
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|)
expr_stmt|;
emit|emit
name|changed
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|extractPixmap
name|QPixmap
name|DropArea
operator|::
name|extractPixmap
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|,
specifier|const
name|QString
modifier|&
name|format
parameter_list|)
block|{
specifier|const
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|imageFormats
init|=
name|QImageReader
operator|::
name|supportedImageFormats
argument_list|()
decl_stmt|;
name|QPixmap
name|pixmap
decl_stmt|;
for|for
control|(
specifier|const
name|QByteArray
modifier|&
name|imageFormat
range|:
name|imageFormats
control|)
block|{
if|if
condition|(
name|format
operator|.
name|mid
argument_list|(
literal|6
argument_list|)
operator|==
name|QString
argument_list|(
name|imageFormat
argument_list|)
condition|)
block|{
name|pixmap
operator|.
name|loadFromData
argument_list|(
name|data
argument_list|,
name|imageFormat
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
return|return
name|pixmap
return|;
block|}
end_function
end_unit
