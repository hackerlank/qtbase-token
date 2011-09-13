begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ELIDEDLABEL_H
end_ifndef
begin_define
DECL|macro|ELIDEDLABEL_H
define|#
directive|define
name|ELIDEDLABEL_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/QFrame>
end_include
begin_include
include|#
directive|include
file|<QtCore/QRect>
end_include
begin_include
include|#
directive|include
file|<QtGui/QResizeEvent>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|ElidedLabel
range|:
name|public
name|QFrame
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QString text READ text WRITE setText
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool isElided READ isElided
argument_list|)
name|public
operator|:
name|ElidedLabel
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|setText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
specifier|const
name|QString
operator|&
name|text
argument_list|()
specifier|const
block|{
return|return
name|content
return|;
block|}
name|bool
name|isElided
argument_list|()
specifier|const
block|{
return|return
name|elided
return|;
block|}
name|protected
operator|:
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|event
argument_list|)
block|;
name|signals
operator|:
name|void
name|elisionChanged
argument_list|(
argument|bool elided
argument_list|)
block|;
name|private
operator|:
name|bool
name|elided
block|;
name|QString
name|content
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// TEXTWRAPPINGWIDGET_H
end_comment
end_unit
