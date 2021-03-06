begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|"stylewidget.h"
end_include
begin_constructor
DECL|function|StyleWidget
name|StyleWidget
operator|::
name|StyleWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QFrame
argument_list|(
name|parent
argument_list|)
block|{
name|m_ui
operator|.
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|on_close_clicked
name|void
name|StyleWidget
operator|::
name|on_close_clicked
parameter_list|()
block|{
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_blueStyle_clicked
name|void
name|StyleWidget
operator|::
name|on_blueStyle_clicked
parameter_list|()
block|{
name|QFile
name|styleSheet
argument_list|(
literal|":/files/blue.qss"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|styleSheet
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to open :/files/blue.qss"
argument_list|)
expr_stmt|;
return|return;
block|}
name|qApp
operator|->
name|setStyleSheet
argument_list|(
name|styleSheet
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_khakiStyle_clicked
name|void
name|StyleWidget
operator|::
name|on_khakiStyle_clicked
parameter_list|()
block|{
name|QFile
name|styleSheet
argument_list|(
literal|":/files/khaki.qss"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|styleSheet
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to open :/files/khaki.qss"
argument_list|)
expr_stmt|;
return|return;
block|}
name|qApp
operator|->
name|setStyleSheet
argument_list|(
name|styleSheet
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_noStyle_clicked
name|void
name|StyleWidget
operator|::
name|on_noStyle_clicked
parameter_list|()
block|{
name|QFile
name|styleSheet
argument_list|(
literal|":/files/nostyle.qss"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|styleSheet
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to open :/files/nostyle.qss"
argument_list|)
expr_stmt|;
return|return;
block|}
name|qApp
operator|->
name|setStyleSheet
argument_list|(
name|styleSheet
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_transparentStyle_clicked
name|void
name|StyleWidget
operator|::
name|on_transparentStyle_clicked
parameter_list|()
block|{
name|QFile
name|styleSheet
argument_list|(
literal|":/files/transparent.qss"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|styleSheet
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to open :/files/transparent.qss"
argument_list|)
expr_stmt|;
return|return;
block|}
name|qApp
operator|->
name|setStyleSheet
argument_list|(
name|styleSheet
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
