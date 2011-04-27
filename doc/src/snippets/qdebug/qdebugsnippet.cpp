begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_class
DECL|class|Coordinate
class|class
name|Coordinate
super|:
specifier|public
name|QObject
block|{
public|public:
DECL|member|myX
DECL|member|myY
name|int
name|myX
decl_stmt|,
name|myY
decl_stmt|;
DECL|function|x
name|int
name|x
parameter_list|()
specifier|const
block|{
return|return
name|myX
return|;
block|}
empty_stmt|;
DECL|function|y
name|int
name|y
parameter_list|()
specifier|const
block|{
return|return
name|myY
return|;
block|}
empty_stmt|;
block|}
class|;
end_class
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|dbg
parameter_list|,
specifier|const
name|Coordinate
modifier|&
name|c
parameter_list|)
block|{
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"("
operator|<<
name|c
operator|.
name|x
argument_list|()
operator|<<
literal|", "
operator|<<
name|c
operator|.
name|y
argument_list|()
operator|<<
literal|")"
expr_stmt|;
return|return
name|dbg
operator|.
name|space
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argv
parameter_list|,
name|char
modifier|*
modifier|*
name|args
parameter_list|)
block|{
name|Coordinate
name|coordinate
decl_stmt|;
name|coordinate
operator|.
name|myX
operator|=
literal|10
expr_stmt|;
name|coordinate
operator|.
name|myY
operator|=
literal|44
expr_stmt|;
comment|//! [1]
name|qDebug
argument_list|()
operator|<<
literal|"Date:"
operator|<<
name|QDate
operator|::
name|currentDate
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Types:"
operator|<<
name|QString
argument_list|(
literal|"String"
argument_list|)
operator|<<
name|QChar
argument_list|(
literal|'x'
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|0
argument_list|,
literal|10
argument_list|,
literal|50
argument_list|,
literal|40
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Custom coordinate type:"
operator|<<
name|coordinate
expr_stmt|;
comment|//! [1]
block|}
end_function
end_unit
