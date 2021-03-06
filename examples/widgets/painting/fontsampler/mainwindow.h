begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MAINWINDOW_H
end_ifndef
begin_define
DECL|macro|MAINWINDOW_H
define|#
directive|define
name|MAINWINDOW_H
end_define
begin_include
include|#
directive|include
file|"ui_mainwindowbase.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPrinter
name|class
name|QPrinter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextEdit
name|class
name|QTextEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTreeWidget
name|class
name|QTreeWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTreeWidgetItem
name|class
name|QTreeWidgetItem
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_typedef
DECL|typedef|StyleItems
typedef|typedef
name|QList
operator|<
name|QTreeWidgetItem
operator|*
operator|>
name|StyleItems
expr_stmt|;
end_typedef
begin_decl_stmt
DECL|variable|QMainWindow
name|class
name|MainWindow
range|:
name|public
name|QMainWindow
decl_stmt|,
name|private
name|Ui
decl|::
name|MainWindowBase
block|{
name|Q_OBJECT
name|public
range|:
name|MainWindow
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
name|public
name|slots
range|:
name|void
name|on_clearAction_triggered
argument_list|()
decl_stmt|;
name|void
name|on_markAction_triggered
parameter_list|()
function_decl|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_PRINTER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_PRINTDIALOG
argument_list|)
name|void
name|on_printAction_triggered
parameter_list|()
function_decl|;
name|void
name|on_printPreviewAction_triggered
parameter_list|()
function_decl|;
endif|#
directive|endif
name|void
name|on_unmarkAction_triggered
parameter_list|()
function_decl|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_PRINTER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_PRINTDIALOG
argument_list|)
name|void
name|printDocument
parameter_list|(
name|QPrinter
modifier|*
name|printer
parameter_list|)
function_decl|;
name|void
name|printPage
parameter_list|(
name|int
name|index
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|,
name|QPrinter
modifier|*
name|printer
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
name|showFont
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|)
function_decl|;
name|void
name|updateStyles
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|,
name|int
name|column
parameter_list|)
function_decl|;
name|private
label|:
name|QMap
operator|<
name|QString
operator|,
name|StyleItems
operator|>
name|currentPageMap
argument_list|()
expr_stmt|;
name|void
name|markUnmarkFonts
argument_list|(
name|Qt
operator|::
name|CheckState
name|state
argument_list|)
decl_stmt|;
name|void
name|setupFontTree
parameter_list|()
function_decl|;
name|QList
operator|<
name|int
operator|>
name|sampleSizes
expr_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|StyleItems
operator|>
name|pageMap
expr_stmt|;
name|int
name|markedCount
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// MAINWINDOW_H
end_comment
end_unit
