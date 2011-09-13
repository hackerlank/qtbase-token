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
file|"iconpreviewarea.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|IconPreviewArea
name|IconPreviewArea
operator|::
name|IconPreviewArea
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|QGridLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|stateLabels
index|[
literal|0
index|]
operator|=
name|createHeaderLabel
argument_list|(
name|tr
argument_list|(
literal|"Off"
argument_list|)
argument_list|)
expr_stmt|;
name|stateLabels
index|[
literal|1
index|]
operator|=
name|createHeaderLabel
argument_list|(
name|tr
argument_list|(
literal|"On"
argument_list|)
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|NumStates
operator|==
literal|2
argument_list|)
expr_stmt|;
name|modeLabels
index|[
literal|0
index|]
operator|=
name|createHeaderLabel
argument_list|(
name|tr
argument_list|(
literal|"Normal"
argument_list|)
argument_list|)
expr_stmt|;
name|modeLabels
index|[
literal|1
index|]
operator|=
name|createHeaderLabel
argument_list|(
name|tr
argument_list|(
literal|"Active"
argument_list|)
argument_list|)
expr_stmt|;
name|modeLabels
index|[
literal|2
index|]
operator|=
name|createHeaderLabel
argument_list|(
name|tr
argument_list|(
literal|"Disabled"
argument_list|)
argument_list|)
expr_stmt|;
name|modeLabels
index|[
literal|3
index|]
operator|=
name|createHeaderLabel
argument_list|(
name|tr
argument_list|(
literal|"Selected"
argument_list|)
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|NumModes
operator|==
literal|4
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|NumStates
condition|;
operator|++
name|j
control|)
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|stateLabels
index|[
name|j
index|]
argument_list|,
name|j
operator|+
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|NumModes
condition|;
operator|++
name|i
control|)
block|{
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|modeLabels
index|[
name|i
index|]
argument_list|,
literal|0
argument_list|,
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|NumStates
condition|;
operator|++
name|j
control|)
block|{
name|pixmapLabels
index|[
name|i
index|]
index|[
name|j
index|]
operator|=
name|createPixmapLabel
argument_list|()
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|pixmapLabels
index|[
name|i
index|]
index|[
name|j
index|]
argument_list|,
name|j
operator|+
literal|1
argument_list|,
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|setIcon
name|void
name|IconPreviewArea
operator|::
name|setIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
block|{
name|this
operator|->
name|icon
operator|=
name|icon
expr_stmt|;
name|updatePixmapLabels
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|setSize
name|void
name|IconPreviewArea
operator|::
name|setSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
if|if
condition|(
name|size
operator|!=
name|this
operator|->
name|size
condition|)
block|{
name|this
operator|->
name|size
operator|=
name|size
expr_stmt|;
name|updatePixmapLabels
argument_list|()
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
DECL|function|createHeaderLabel
name|QLabel
modifier|*
name|IconPreviewArea
operator|::
name|createHeaderLabel
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"<b>%1</b>"
argument_list|)
operator|.
name|arg
argument_list|(
name|text
argument_list|)
argument_list|)
decl_stmt|;
name|label
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignCenter
argument_list|)
expr_stmt|;
return|return
name|label
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
DECL|function|createPixmapLabel
name|QLabel
modifier|*
name|IconPreviewArea
operator|::
name|createPixmapLabel
parameter_list|()
block|{
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
decl_stmt|;
name|label
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|label
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignCenter
argument_list|)
expr_stmt|;
name|label
operator|->
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|Box
argument_list|)
expr_stmt|;
name|label
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|label
operator|->
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|)
expr_stmt|;
name|label
operator|->
name|setAutoFillBackground
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|label
operator|->
name|setMinimumSize
argument_list|(
literal|132
argument_list|,
literal|132
argument_list|)
expr_stmt|;
return|return
name|label
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
DECL|function|updatePixmapLabels
name|void
name|IconPreviewArea
operator|::
name|updatePixmapLabels
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|NumModes
condition|;
operator|++
name|i
control|)
block|{
name|QIcon
operator|::
name|Mode
name|mode
decl_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
condition|)
block|{
name|mode
operator|=
name|QIcon
operator|::
name|Normal
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|i
operator|==
literal|1
condition|)
block|{
name|mode
operator|=
name|QIcon
operator|::
name|Active
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|i
operator|==
literal|2
condition|)
block|{
name|mode
operator|=
name|QIcon
operator|::
name|Disabled
expr_stmt|;
block|}
else|else
block|{
name|mode
operator|=
name|QIcon
operator|::
name|Selected
expr_stmt|;
block|}
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|NumStates
condition|;
operator|++
name|j
control|)
block|{
name|QIcon
operator|::
name|State
name|state
init|=
operator|(
name|j
operator|==
literal|0
operator|)
condition|?
name|QIcon
operator|::
name|Off
else|:
name|QIcon
operator|::
name|On
decl_stmt|;
name|QPixmap
name|pixmap
init|=
name|icon
operator|.
name|pixmap
argument_list|(
name|size
argument_list|,
name|mode
argument_list|,
name|state
argument_list|)
decl_stmt|;
name|pixmapLabels
index|[
name|i
index|]
index|[
name|j
index|]
operator|->
name|setPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
name|pixmapLabels
index|[
name|i
index|]
index|[
name|j
index|]
operator|->
name|setEnabled
argument_list|(
operator|!
name|pixmap
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|//! [5]
end_comment
end_unit
