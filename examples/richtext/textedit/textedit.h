begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TEXTEDIT_H
end_ifndef
begin_define
DECL|macro|TEXTEDIT_H
define|#
directive|define
name|TEXTEDIT_H
end_define
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QPointer>
end_include
begin_macro
DECL|function|QT_FORWARD_DECLARE_CLASS
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QAction
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QComboBox
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QFontComboBox
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QTextEdit
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QTextCharFormat
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QMenu
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QPrinter
argument_list|)
end_macro
begin_decl_stmt
name|class
name|TextEdit
range|:
name|public
name|QMainWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|TextEdit
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|void
name|closeEvent
argument_list|(
name|QCloseEvent
operator|*
name|e
argument_list|)
block|;
name|private
operator|:
name|void
name|setupFileActions
argument_list|()
block|;
name|void
name|setupEditActions
argument_list|()
block|;
name|void
name|setupTextActions
argument_list|()
block|;
name|bool
name|load
argument_list|(
specifier|const
name|QString
operator|&
name|f
argument_list|)
block|;
name|bool
name|maybeSave
argument_list|()
block|;
name|void
name|setCurrentFileName
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|fileNew
argument_list|()
block|;
name|void
name|fileOpen
argument_list|()
block|;
name|bool
name|fileSave
argument_list|()
block|;
name|bool
name|fileSaveAs
argument_list|()
block|;
name|void
name|filePrint
argument_list|()
block|;
name|void
name|filePrintPreview
argument_list|()
block|;
name|void
name|filePrintPdf
argument_list|()
block|;
name|void
name|textBold
argument_list|()
block|;
name|void
name|textUnderline
argument_list|()
block|;
name|void
name|textItalic
argument_list|()
block|;
name|void
name|textFamily
argument_list|(
specifier|const
name|QString
operator|&
name|f
argument_list|)
block|;
name|void
name|textSize
argument_list|(
specifier|const
name|QString
operator|&
name|p
argument_list|)
block|;
name|void
name|textStyle
argument_list|(
argument|int styleIndex
argument_list|)
block|;
name|void
name|textColor
argument_list|()
block|;
name|void
name|textAlign
argument_list|(
name|QAction
operator|*
name|a
argument_list|)
block|;
name|void
name|currentCharFormatChanged
argument_list|(
specifier|const
name|QTextCharFormat
operator|&
name|format
argument_list|)
block|;
name|void
name|cursorPositionChanged
argument_list|()
block|;
name|void
name|clipboardDataChanged
argument_list|()
block|;
name|void
name|about
argument_list|()
block|;
name|void
name|printPreview
argument_list|(
name|QPrinter
operator|*
argument_list|)
block|;
name|private
operator|:
name|void
name|mergeFormatOnWordOrSelection
argument_list|(
specifier|const
name|QTextCharFormat
operator|&
name|format
argument_list|)
block|;
name|void
name|fontChanged
argument_list|(
specifier|const
name|QFont
operator|&
name|f
argument_list|)
block|;
name|void
name|colorChanged
argument_list|(
specifier|const
name|QColor
operator|&
name|c
argument_list|)
block|;
name|void
name|alignmentChanged
argument_list|(
argument|Qt::Alignment a
argument_list|)
block|;
name|QAction
operator|*
name|actionSave
block|,
operator|*
name|actionTextBold
block|,
operator|*
name|actionTextUnderline
block|,
operator|*
name|actionTextItalic
block|,
operator|*
name|actionTextColor
block|,
operator|*
name|actionAlignLeft
block|,
operator|*
name|actionAlignCenter
block|,
operator|*
name|actionAlignRight
block|,
operator|*
name|actionAlignJustify
block|,
operator|*
name|actionUndo
block|,
operator|*
name|actionRedo
block|,
operator|*
name|actionCut
block|,
operator|*
name|actionCopy
block|,
operator|*
name|actionPaste
block|;
name|QComboBox
operator|*
name|comboStyle
block|;
name|QFontComboBox
operator|*
name|comboFont
block|;
name|QComboBox
operator|*
name|comboSize
block|;
name|QToolBar
operator|*
name|tb
block|;
name|QString
name|fileName
block|;
name|QTextEdit
operator|*
name|textEdit
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
