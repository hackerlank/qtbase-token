begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"digitalclock.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|DigitalClock
name|DigitalClock
operator|::
name|DigitalClock
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QLCDNumber
argument_list|(
name|parent
argument_list|)
block|{
name|setSegmentStyle
argument_list|(
name|Filled
argument_list|)
expr_stmt|;
name|QTimer
modifier|*
name|timer
init|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showTime
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|timer
operator|->
name|start
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|showTime
argument_list|()
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Digital Clock"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|150
argument_list|,
literal|60
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|showTime
name|void
name|DigitalClock
operator|::
name|showTime
parameter_list|()
comment|//! [1] //! [2]
block|{
name|QTime
name|time
init|=
name|QTime
operator|::
name|currentTime
argument_list|()
decl_stmt|;
name|QString
name|text
init|=
name|time
operator|.
name|toString
argument_list|(
literal|"hh:mm"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|time
operator|.
name|second
argument_list|()
operator|%
literal|2
operator|)
operator|==
literal|0
condition|)
name|text
index|[
literal|2
index|]
operator|=
literal|' '
expr_stmt|;
name|display
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
end_unit
