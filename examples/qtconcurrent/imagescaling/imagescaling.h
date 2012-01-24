begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|IMAGESCALING_H
end_ifndef
begin_define
DECL|macro|IMAGESCALING_H
define|#
directive|define
name|IMAGESCALING_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONCURRENT
end_ifndef
begin_decl_stmt
name|class
name|Images
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|Images
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|Images
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|open
argument_list|()
block|;
name|void
name|showImage
argument_list|(
argument|int num
argument_list|)
block|;
name|void
name|finished
argument_list|()
block|;
name|private
operator|:
name|QPushButton
operator|*
name|openButton
block|;
name|QPushButton
operator|*
name|cancelButton
block|;
name|QPushButton
operator|*
name|pauseButton
block|;
name|QVBoxLayout
operator|*
name|mainLayout
block|;
name|QList
operator|<
name|QLabel
operator|*
operator|>
name|labels
block|;
name|QGridLayout
operator|*
name|imagesLayout
block|;
name|QFutureWatcher
operator|<
name|QImage
operator|>
operator|*
name|imageScaling
block|; }
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_comment
comment|// Dummy class required because QT_NO_CONCURRENT is not set when moc is run.
end_comment
begin_decl_stmt
name|class
name|Images
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
name|Q_SLOTS
operator|:
name|void
name|open
argument_list|()
block|{}
name|void
name|showImage
argument_list|(
argument|int
argument_list|)
block|{}
name|void
name|finished
argument_list|()
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CONCURRENT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// IMAGESCALING_H
end_comment
end_unit
