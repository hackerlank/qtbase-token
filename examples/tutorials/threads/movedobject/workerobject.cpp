begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|"workerobject.h"
end_include
begin_comment
comment|/*  * represents an object that lives in another thread where it polls a resource  * and communicates with the gui thread  */
end_comment
begin_constructor
DECL|function|WorkerObject
name|WorkerObject
operator|::
name|WorkerObject
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{
name|timer
operator|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
expr_stmt|;
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
name|poll
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//---------------------------------------------------------------
end_comment
begin_function
DECL|function|doWork
name|void
name|WorkerObject
operator|::
name|doWork
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"doing work in thread "
operator|<<
name|thread
argument_list|()
operator|->
name|currentThreadId
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//---------------------------------------------------------------
end_comment
begin_destructor
DECL|function|~WorkerObject
name|WorkerObject
operator|::
name|~
name|WorkerObject
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"destruction WorkerObject in thread "
operator|<<
name|thread
argument_list|()
operator|->
name|currentThreadId
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|//---------------------------------------------------------------
end_comment
begin_function
DECL|function|startPolling
name|void
name|WorkerObject
operator|::
name|startPolling
parameter_list|(
name|int
name|milliseconds
parameter_list|)
block|{
name|count
operator|=
literal|0
expr_stmt|;
name|timer
operator|->
name|start
argument_list|(
name|milliseconds
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//---------------------------------------------------------------
end_comment
begin_function
DECL|function|stopPolling
name|void
name|WorkerObject
operator|::
name|stopPolling
parameter_list|()
block|{
name|timer
operator|->
name|stop
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//---------------------------------------------------------------
end_comment
begin_function
DECL|function|poll
name|void
name|WorkerObject
operator|::
name|poll
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
name|QString
argument_list|(
literal|"timer hit %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|count
argument_list|)
expr_stmt|;
name|count
operator|++
expr_stmt|;
block|}
end_function
end_unit
