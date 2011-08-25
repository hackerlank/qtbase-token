begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"rectbutton.h"
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_constructor
DECL|function|RectButton
name|RectButton
operator|::
name|RectButton
parameter_list|(
name|QString
name|buttonText
parameter_list|)
member_init_list|:
name|m_ButtonText
argument_list|(
name|buttonText
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~RectButton
name|RectButton
operator|::
name|~
name|RectButton
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|mousePressEvent
name|void
name|RectButton
operator|::
name|mousePressEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
parameter_list|)
block|{
emit|emit
name|clicked
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|boundingRect
name|QRectF
name|RectButton
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|,
literal|90.0
argument_list|,
literal|40.0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|paint
name|void
name|RectButton
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
comment|/* option */
parameter_list|,
name|QWidget
modifier|*
comment|/* widget */
parameter_list|)
block|{
name|painter
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|gray
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRoundedRect
argument_list|(
name|boundingRect
argument_list|()
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawText
argument_list|(
literal|20
argument_list|,
literal|25
argument_list|,
name|m_ButtonText
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
