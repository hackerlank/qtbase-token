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
file|"colorlisteditor.h"
end_include
begin_constructor
DECL|function|ColorListEditor
name|ColorListEditor
operator|::
name|ColorListEditor
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
member_init_list|:
name|QComboBox
argument_list|(
name|widget
argument_list|)
block|{
name|populateList
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|color
name|QColor
name|ColorListEditor
operator|::
name|color
parameter_list|()
specifier|const
block|{
return|return
name|qvariant_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|itemData
argument_list|(
name|currentIndex
argument_list|()
argument_list|,
name|Qt
operator|::
name|DecorationRole
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|setColor
name|void
name|ColorListEditor
operator|::
name|setColor
parameter_list|(
name|QColor
name|color
parameter_list|)
block|{
name|setCurrentIndex
argument_list|(
name|findData
argument_list|(
name|color
argument_list|,
name|int
argument_list|(
name|Qt
operator|::
name|DecorationRole
argument_list|)
argument_list|)
argument_list|)
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
DECL|function|populateList
name|void
name|ColorListEditor
operator|::
name|populateList
parameter_list|()
block|{
name|QStringList
name|colorNames
init|=
name|QColor
operator|::
name|colorNames
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|colorNames
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QColor
name|color
argument_list|(
name|colorNames
index|[
name|i
index|]
argument_list|)
decl_stmt|;
name|insertItem
argument_list|(
name|i
argument_list|,
name|colorNames
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|setItemData
argument_list|(
name|i
argument_list|,
name|color
argument_list|,
name|Qt
operator|::
name|DecorationRole
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [2]
end_comment
end_unit
