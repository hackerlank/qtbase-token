begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ** ** This file was generated by qdbusxml2cpp version 0.7 ** Command line was: qdbusxml2cpp -i chat_adaptor.h -a :chat_adaptor.cpp com.trolltech.chat.xml ** ** qdbusxml2cpp is Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** ** This is an auto-generated file. ** Do not edit! All changes made to it will be lost. ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"chat_adaptor.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QMetaObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_comment
comment|/*  * Implementation of adaptor class ChatAdaptor  */
end_comment
begin_constructor
DECL|function|ChatAdaptor
name|ChatAdaptor
operator|::
name|ChatAdaptor
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDBusAbstractAdaptor
argument_list|(
name|parent
argument_list|)
block|{
comment|// constructor
name|setAutoRelaySignals
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~ChatAdaptor
name|ChatAdaptor
operator|::
name|~
name|ChatAdaptor
parameter_list|()
block|{
comment|// destructor
block|}
end_destructor
end_unit
