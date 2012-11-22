begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FREEZETABLEWIDGET_H
end_ifndef
begin_define
DECL|macro|FREEZETABLEWIDGET_H
define|#
directive|define
name|FREEZETABLEWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QTableView>
end_include
begin_comment
comment|//! [Widget definition]
end_comment
begin_decl_stmt
name|class
name|FreezeTableWidget
range|:
name|public
name|QTableView
block|{
name|Q_OBJECT
name|public
operator|:
name|FreezeTableWidget
argument_list|(
name|QAbstractItemModel
operator|*
name|model
argument_list|)
block|;
operator|~
name|FreezeTableWidget
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|QModelIndex
name|moveCursor
argument_list|(
argument|CursorAction cursorAction
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|)
block|;
name|void
name|scrollTo
argument_list|(
argument|const QModelIndex& index
argument_list|,
argument|ScrollHint hint = EnsureVisible
argument_list|)
block|;
name|private
operator|:
name|QTableView
operator|*
name|frozenTableView
block|;
name|void
name|init
argument_list|()
block|;
name|void
name|updateFrozenTableGeometry
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|updateSectionWidth
argument_list|(
argument|int logicalIndex
argument_list|,
argument|int oldSize
argument_list|,
argument|int newSize
argument_list|)
block|;
name|void
name|updateSectionHeight
argument_list|(
argument|int logicalIndex
argument_list|,
argument|int oldSize
argument_list|,
argument|int newSize
argument_list|)
block|;  }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [Widget definition]
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// FREEZETABLEWIDGET_H
end_comment
end_unit
