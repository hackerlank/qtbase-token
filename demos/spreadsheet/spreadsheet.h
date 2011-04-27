begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SPREADSHEET_H
end_ifndef
begin_define
DECL|macro|SPREADSHEET_H
define|#
directive|define
name|SPREADSHEET_H
end_define
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAction
name|class
name|QAction
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
DECL|variable|QToolBar
name|class
name|QToolBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTableWidgetItem
name|class
name|QTableWidgetItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTableWidget
name|class
name|QTableWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|SpreadSheet
range|:
name|public
name|QMainWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|SpreadSheet
argument_list|(
argument|int rows
argument_list|,
argument|int cols
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|updateStatus
argument_list|(
name|QTableWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|updateColor
argument_list|(
name|QTableWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|updateLineEdit
argument_list|(
name|QTableWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|returnPressed
argument_list|()
block|;
name|void
name|selectColor
argument_list|()
block|;
name|void
name|selectFont
argument_list|()
block|;
name|void
name|clear
argument_list|()
block|;
name|void
name|showAbout
argument_list|()
block|;
name|void
name|print
argument_list|()
block|;
name|void
name|actionSum
argument_list|()
block|;
name|void
name|actionSubtract
argument_list|()
block|;
name|void
name|actionAdd
argument_list|()
block|;
name|void
name|actionMultiply
argument_list|()
block|;
name|void
name|actionDivide
argument_list|()
block|;
name|protected
operator|:
name|void
name|setupContextMenu
argument_list|()
block|;
name|void
name|setupContents
argument_list|()
block|;
name|void
name|setupMenuBar
argument_list|()
block|;
name|void
name|createActions
argument_list|()
block|;
name|void
name|actionMath_helper
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|,
specifier|const
name|QString
operator|&
name|op
argument_list|)
block|;
name|bool
name|runInputDialog
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|,
specifier|const
name|QString
operator|&
name|c1Text
argument_list|,
specifier|const
name|QString
operator|&
name|c2Text
argument_list|,
specifier|const
name|QString
operator|&
name|opText
argument_list|,
specifier|const
name|QString
operator|&
name|outText
argument_list|,
name|QString
operator|*
name|cell1
argument_list|,
name|QString
operator|*
name|cell2
argument_list|,
name|QString
operator|*
name|outCell
argument_list|)
block|;
name|private
operator|:
name|QToolBar
operator|*
name|toolBar
block|;
name|QAction
operator|*
name|colorAction
block|;
name|QAction
operator|*
name|fontAction
block|;
name|QAction
operator|*
name|firstSeparator
block|;
name|QAction
operator|*
name|cell_sumAction
block|;
name|QAction
operator|*
name|cell_addAction
block|;
name|QAction
operator|*
name|cell_subAction
block|;
name|QAction
operator|*
name|cell_mulAction
block|;
name|QAction
operator|*
name|cell_divAction
block|;
name|QAction
operator|*
name|secondSeparator
block|;
name|QAction
operator|*
name|clearAction
block|;
name|QAction
operator|*
name|aboutSpreadSheet
block|;
name|QAction
operator|*
name|exitAction
block|;
name|QAction
operator|*
name|printAction
block|;
name|QLabel
operator|*
name|cellLabel
block|;
name|QTableWidget
operator|*
name|table
block|;
name|QLineEdit
operator|*
name|formulaInput
block|;  }
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|decode_pos
parameter_list|(
specifier|const
name|QString
modifier|&
name|pos
parameter_list|,
name|int
modifier|*
name|row
parameter_list|,
name|int
modifier|*
name|col
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QString
name|encode_pos
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|col
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// SPREADSHEET_H
end_comment
end_unit
