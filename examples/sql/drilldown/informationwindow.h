begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|INFORMATIONWINDOW_H
end_ifndef
begin_define
DECL|macro|INFORMATIONWINDOW_H
define|#
directive|define
name|INFORMATIONWINDOW_H
end_define
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QtSql>
end_include
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|InformationWindow
range|:
name|public
name|QDialog
block|{
name|Q_OBJECT
name|public
operator|:
name|InformationWindow
argument_list|(
argument|int id
argument_list|,
argument|QSqlRelationalTableModel *offices
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|)
block|;
name|int
name|id
argument_list|()
block|;
name|signals
operator|:
name|void
name|imageChanged
argument_list|(
argument|int id
argument_list|,
argument|const QString&fileName
argument_list|)
block|;
comment|//! [0]
comment|//! [1]
name|private
name|slots
operator|:
name|void
name|revert
argument_list|()
block|;
name|void
name|submit
argument_list|()
block|;
name|void
name|enableButtons
argument_list|(
argument|bool enable = true
argument_list|)
block|;
comment|//! [1]
comment|//! [2]
name|private
operator|:
name|void
name|createButtons
argument_list|()
block|;
name|int
name|locationId
block|;
name|QString
name|displayedImage
block|;
name|QComboBox
operator|*
name|imageFileEditor
block|;
name|QLabel
operator|*
name|locationText
block|;
name|QLabel
operator|*
name|countryText
block|;
name|QTextEdit
operator|*
name|descriptionEditor
block|;
name|QPushButton
operator|*
name|closeButton
block|;
name|QPushButton
operator|*
name|submitButton
block|;
name|QPushButton
operator|*
name|revertButton
block|;
name|QDialogButtonBox
operator|*
name|buttonBox
block|;
name|QDataWidgetMapper
operator|*
name|mapper
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [2]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
