begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"fortuneserver.h"
end_include
begin_include
include|#
directive|include
file|"fortunethread.h"
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|FortuneServer
name|FortuneServer
operator|::
name|FortuneServer
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QTcpServer
argument_list|(
name|parent
argument_list|)
block|{
name|fortunes
operator|<<
name|tr
argument_list|(
literal|"You've been leading a dog's life. Stay off the furniture."
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"You've got to think about tomorrow."
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"You will be surprised by a loud noise."
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"You will feel hungry again in another hour."
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"You might have mail."
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"You cannot kill time without injuring eternity."
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Computers are not intelligent. They only think they are."
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
DECL|function|incomingConnection
name|void
name|FortuneServer
operator|::
name|incomingConnection
parameter_list|(
name|int
name|socketDescriptor
parameter_list|)
block|{
name|QString
name|fortune
init|=
name|fortunes
operator|.
name|at
argument_list|(
name|qrand
argument_list|()
operator|%
name|fortunes
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|FortuneThread
modifier|*
name|thread
init|=
operator|new
name|FortuneThread
argument_list|(
name|socketDescriptor
argument_list|,
name|fortune
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|thread
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|thread
argument_list|,
name|SLOT
argument_list|(
name|deleteLater
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|thread
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
end_unit
