begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_decl_stmt
DECL|variable|listEntries
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|listEntries
index|[]
init|=
block|{
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"MainWindow"
argument_list|,
literal|"First"
argument_list|)
block|,
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"MainWindow"
argument_list|,
literal|"Second"
argument_list|)
block|,
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"MainWindow"
argument_list|,
literal|"Third"
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
name|centralWidget
operator|=
operator|new
name|QWidget
expr_stmt|;
name|setCentralWidget
argument_list|(
name|centralWidget
argument_list|)
expr_stmt|;
name|createGroupBox
argument_list|()
expr_stmt|;
name|listWidget
operator|=
operator|new
name|QListWidget
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|listEntries
index|[
name|i
index|]
condition|;
operator|++
name|i
control|)
name|listWidget
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
name|listEntries
index|[
name|i
index|]
argument_list|)
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
name|groupBox
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|listWidget
argument_list|)
expr_stmt|;
name|centralWidget
operator|->
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|exitAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|exitAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|fileMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&File"
argument_list|)
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|setPalette
argument_list|(
name|QPalette
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|exitAction
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Language: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|tr
argument_list|(
literal|"English"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"Internationalization Example"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|tr
argument_list|(
literal|"LTR"
argument_list|)
operator|==
literal|"RTL"
condition|)
name|setLayoutDirection
argument_list|(
name|Qt
operator|::
name|RightToLeft
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|createGroupBox
name|void
name|MainWindow
operator|::
name|createGroupBox
parameter_list|()
block|{
name|groupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"View"
argument_list|)
argument_list|)
expr_stmt|;
name|perspectiveRadioButton
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Perspective"
argument_list|)
argument_list|)
expr_stmt|;
name|isometricRadioButton
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Isometric"
argument_list|)
argument_list|)
expr_stmt|;
name|obliqueRadioButton
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Oblique"
argument_list|)
argument_list|)
expr_stmt|;
name|perspectiveRadioButton
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|groupBoxLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|groupBoxLayout
operator|->
name|addWidget
argument_list|(
name|perspectiveRadioButton
argument_list|)
expr_stmt|;
name|groupBoxLayout
operator|->
name|addWidget
argument_list|(
name|isometricRadioButton
argument_list|)
expr_stmt|;
name|groupBoxLayout
operator|->
name|addWidget
argument_list|(
name|obliqueRadioButton
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setLayout
argument_list|(
name|groupBoxLayout
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
