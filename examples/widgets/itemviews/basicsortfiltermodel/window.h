begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|WINDOW_H
end_ifndef
begin_define
DECL|macro|WINDOW_H
define|#
directive|define
name|WINDOW_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAbstractItemModel
name|class
name|QAbstractItemModel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCheckBox
name|class
name|QCheckBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QComboBox
name|class
name|QComboBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGroupBox
name|class
name|QGroupBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLineEdit
name|class
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSortFilterProxyModel
name|class
name|QSortFilterProxyModel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTreeView
name|class
name|QTreeView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|Window
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|Window
argument_list|()
block|;
name|void
name|setSourceModel
argument_list|(
name|QAbstractItemModel
operator|*
name|model
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|filterRegExpChanged
argument_list|()
block|;
name|void
name|filterColumnChanged
argument_list|()
block|;
name|void
name|sortChanged
argument_list|()
block|;
name|private
operator|:
name|QSortFilterProxyModel
operator|*
name|proxyModel
block|;
name|QGroupBox
operator|*
name|sourceGroupBox
block|;
name|QGroupBox
operator|*
name|proxyGroupBox
block|;
name|QTreeView
operator|*
name|sourceView
block|;
name|QTreeView
operator|*
name|proxyView
block|;
name|QCheckBox
operator|*
name|filterCaseSensitivityCheckBox
block|;
name|QCheckBox
operator|*
name|sortCaseSensitivityCheckBox
block|;
name|QLabel
operator|*
name|filterPatternLabel
block|;
name|QLabel
operator|*
name|filterSyntaxLabel
block|;
name|QLabel
operator|*
name|filterColumnLabel
block|;
name|QLineEdit
operator|*
name|filterPatternLineEdit
block|;
name|QComboBox
operator|*
name|filterSyntaxComboBox
block|;
name|QComboBox
operator|*
name|filterColumnComboBox
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// WINDOW_H
end_comment
end_unit
