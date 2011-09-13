begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|VIEW_H
end_ifndef
begin_define
DECL|macro|VIEW_H
define|#
directive|define
name|VIEW_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtSql>
end_include
begin_decl_stmt
DECL|variable|ImageItem
name|class
name|ImageItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|InformationWindow
name|class
name|InformationWindow
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|View
range|:
name|public
name|QGraphicsView
block|{
name|Q_OBJECT
name|public
operator|:
name|View
argument_list|(
specifier|const
name|QString
operator|&
name|offices
argument_list|,
specifier|const
name|QString
operator|&
name|images
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|protected
operator|:
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
comment|//! [0]
comment|//! [1]
name|private
name|slots
operator|:
name|void
name|updateImage
argument_list|(
argument|int id
argument_list|,
argument|const QString&fileName
argument_list|)
block|;
comment|//! [1]
comment|//! [2]
name|private
operator|:
name|void
name|addItems
argument_list|()
block|;
name|InformationWindow
operator|*
name|findWindow
argument_list|(
argument|int id
argument_list|)
block|;
name|void
name|showInformation
argument_list|(
name|ImageItem
operator|*
name|image
argument_list|)
block|;
name|QGraphicsScene
operator|*
name|scene
block|;
name|QList
operator|<
name|InformationWindow
operator|*
operator|>
name|informationWindows
block|;
comment|//! [2] //! [3]
name|QSqlRelationalTableModel
operator|*
name|officeTable
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [3]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
