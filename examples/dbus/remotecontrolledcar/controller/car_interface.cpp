begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ** ** This file was generated by qdbusxml2cpp version 0.7 ** Command line was: qdbusxml2cpp -i car_interface.h -p :car_interface.cpp car.xml ** ** qqdbusxml2cpp is Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** ** This is an auto-generated file. ** This file may have been hand-edited. Look for HAND-EDIT comments ** before re-generating it. ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"car_interface.h"
end_include
begin_comment
comment|/*  * Implementation of interface class ComTrolltechExamplesCarInterfaceInterface  */
end_comment
begin_constructor
DECL|function|ComTrolltechExamplesCarInterfaceInterface
name|ComTrolltechExamplesCarInterfaceInterface
operator|::
name|ComTrolltechExamplesCarInterfaceInterface
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QDBusConnection
modifier|&
name|connection
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDBusAbstractInterface
argument_list|(
name|service
argument_list|,
name|path
argument_list|,
name|staticInterfaceName
argument_list|()
argument_list|,
name|connection
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~ComTrolltechExamplesCarInterfaceInterface
name|ComTrolltechExamplesCarInterfaceInterface
operator|::
name|~
name|ComTrolltechExamplesCarInterfaceInterface
parameter_list|()
block|{ }
end_destructor
end_unit
