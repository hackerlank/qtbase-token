begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"detailsdialog.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|DetailsDialog
name|DetailsDialog
operator|::
name|DetailsDialog
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|parent
argument_list|)
block|{
name|nameLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Name:"
argument_list|)
argument_list|)
expr_stmt|;
name|addressLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Address:"
argument_list|)
argument_list|)
expr_stmt|;
name|addressLabel
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
operator||
name|Qt
operator|::
name|AlignTop
argument_list|)
expr_stmt|;
name|nameEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|addressEdit
operator|=
operator|new
name|QTextEdit
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_SIMULATOR
argument_list|)
name|offersCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Send information about\n"
literal|"products and special offers"
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|offersCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Send information about products and "
literal|"special offers"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|setupItemsTable
argument_list|()
expr_stmt|;
name|buttonBox
operator|=
operator|new
name|QDialogButtonBox
argument_list|(
name|QDialogButtonBox
operator|::
name|Ok
operator||
name|QDialogButtonBox
operator|::
name|Cancel
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|verify
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|rejected
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|reject
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_MAEMO_5
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_SIMULATOR
argument_list|)
name|QWidget
modifier|*
name|widgetSubscriber
init|=
operator|new
name|QWidget
decl_stmt|;
name|QGridLayout
modifier|*
name|subscriberLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|subscriberLayout
operator|->
name|addWidget
argument_list|(
name|nameLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|subscriberLayout
operator|->
name|addWidget
argument_list|(
name|nameEdit
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|subscriberLayout
operator|->
name|addWidget
argument_list|(
name|addressLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|subscriberLayout
operator|->
name|addWidget
argument_list|(
name|addressEdit
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|subscriberLayout
operator|->
name|addWidget
argument_list|(
name|offersCheckBox
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|widgetSubscriber
operator|->
name|setLayout
argument_list|(
name|subscriberLayout
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|widgetOrder
init|=
operator|new
name|QWidget
decl_stmt|;
name|QVBoxLayout
modifier|*
name|orderLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|orderLayout
operator|->
name|addWidget
argument_list|(
name|itemsTable
argument_list|)
expr_stmt|;
name|widgetOrder
operator|->
name|setLayout
argument_list|(
name|orderLayout
argument_list|)
expr_stmt|;
name|QTabWidget
modifier|*
name|tabWidget
init|=
operator|new
name|QTabWidget
decl_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|widgetSubscriber
argument_list|,
literal|"Subscriber"
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|widgetOrder
argument_list|,
literal|"Order"
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|tabWidget
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
else|#
directive|else
name|QGridLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|nameLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|nameEdit
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|addressLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|addressEdit
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|itemsTable
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|offersCheckBox
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|setWindowTitle
argument_list|(
name|title
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|setupItemsTable
name|void
name|DetailsDialog
operator|::
name|setupItemsTable
parameter_list|()
block|{
name|items
operator|<<
name|tr
argument_list|(
literal|"T-shirt"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Badge"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Reference book"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Coffee cup"
argument_list|)
expr_stmt|;
name|itemsTable
operator|=
operator|new
name|QTableWidget
argument_list|(
name|items
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|items
operator|.
name|count
argument_list|()
condition|;
operator|++
name|row
control|)
block|{
name|QTableWidgetItem
modifier|*
name|name
init|=
operator|new
name|QTableWidgetItem
argument_list|(
name|items
index|[
name|row
index|]
argument_list|)
decl_stmt|;
name|name
operator|->
name|setFlags
argument_list|(
name|Qt
operator|::
name|ItemIsEnabled
operator||
name|Qt
operator|::
name|ItemIsSelectable
argument_list|)
expr_stmt|;
name|itemsTable
operator|->
name|setItem
argument_list|(
name|row
argument_list|,
literal|0
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|QTableWidgetItem
modifier|*
name|quantity
init|=
operator|new
name|QTableWidgetItem
argument_list|(
literal|"1"
argument_list|)
decl_stmt|;
name|itemsTable
operator|->
name|setItem
argument_list|(
name|row
argument_list|,
literal|1
argument_list|,
name|quantity
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|orderItems
name|QList
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
argument_list|>
name|DetailsDialog
operator|::
name|orderItems
parameter_list|()
block|{
name|QList
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
argument_list|>
name|orderList
decl_stmt|;
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|items
operator|.
name|count
argument_list|()
condition|;
operator|++
name|row
control|)
block|{
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|item
decl_stmt|;
name|item
operator|.
name|first
operator|=
name|itemsTable
operator|->
name|item
argument_list|(
name|row
argument_list|,
literal|0
argument_list|)
operator|->
name|text
argument_list|()
expr_stmt|;
name|int
name|quantity
init|=
name|itemsTable
operator|->
name|item
argument_list|(
name|row
argument_list|,
literal|1
argument_list|)
operator|->
name|data
argument_list|(
name|Qt
operator|::
name|DisplayRole
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|item
operator|.
name|second
operator|=
name|qMax
argument_list|(
literal|0
argument_list|,
name|quantity
argument_list|)
expr_stmt|;
name|orderList
operator|.
name|append
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
return|return
name|orderList
return|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|senderName
name|QString
name|DetailsDialog
operator|::
name|senderName
parameter_list|()
specifier|const
block|{
return|return
name|nameEdit
operator|->
name|text
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|senderAddress
name|QString
name|DetailsDialog
operator|::
name|senderAddress
parameter_list|()
specifier|const
block|{
return|return
name|addressEdit
operator|->
name|toPlainText
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|sendOffers
name|bool
name|DetailsDialog
operator|::
name|sendOffers
parameter_list|()
block|{
return|return
name|offersCheckBox
operator|->
name|isChecked
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|verify
name|void
name|DetailsDialog
operator|::
name|verify
parameter_list|()
block|{
if|if
condition|(
operator|!
name|nameEdit
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|addressEdit
operator|->
name|toPlainText
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|accept
argument_list|()
expr_stmt|;
return|return;
block|}
name|QMessageBox
operator|::
name|StandardButton
name|answer
decl_stmt|;
name|answer
operator|=
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Incomplete Form"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The form does not contain all the necessary information.\n"
literal|"Do you want to discard it?"
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Yes
operator||
name|QMessageBox
operator|::
name|No
argument_list|)
expr_stmt|;
if|if
condition|(
name|answer
operator|==
name|QMessageBox
operator|::
name|Yes
condition|)
name|reject
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
end_unit
