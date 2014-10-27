begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"customstyle.h"
end_include
begin_constructor
DECL|function|CustomStyle
name|CustomStyle
operator|::
name|CustomStyle
parameter_list|()
block|{
comment|//! [0]
specifier|const
name|QSpinBox
modifier|*
name|spinBox
init|=
name|qobject_cast
argument_list|<
specifier|const
name|QSpinBox
operator|*
argument_list|>
argument_list|(
name|widget
argument_list|)
decl_stmt|;
if|if
condition|(
name|spinBox
condition|)
block|{
comment|//! [0] //! [1]
block|}
comment|//! [1]
block|}
end_constructor
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|drawPrimitive
name|void
name|CustomStyle
operator|::
name|drawPrimitive
parameter_list|(
name|PrimitiveElement
name|element
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|element
operator|==
name|PE_IndicatorSpinUp
operator|||
name|element
operator|==
name|PE_IndicatorSpinDown
condition|)
block|{
name|QPolygon
name|points
argument_list|(
literal|3
argument_list|)
decl_stmt|;
name|int
name|x
init|=
name|option
operator|->
name|rect
operator|.
name|x
argument_list|()
decl_stmt|;
name|int
name|y
init|=
name|option
operator|->
name|rect
operator|.
name|y
argument_list|()
decl_stmt|;
name|int
name|w
init|=
name|option
operator|->
name|rect
operator|.
name|width
argument_list|()
operator|/
literal|2
decl_stmt|;
name|int
name|h
init|=
name|option
operator|->
name|rect
operator|.
name|height
argument_list|()
operator|/
literal|2
decl_stmt|;
name|x
operator|+=
operator|(
name|option
operator|->
name|rect
operator|.
name|width
argument_list|()
operator|-
name|w
operator|)
operator|/
literal|2
expr_stmt|;
name|y
operator|+=
operator|(
name|option
operator|->
name|rect
operator|.
name|height
argument_list|()
operator|-
name|h
operator|)
operator|/
literal|2
expr_stmt|;
if|if
condition|(
name|element
operator|==
name|PE_IndicatorSpinUp
condition|)
block|{
name|points
index|[
literal|0
index|]
operator|=
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
operator|+
name|h
argument_list|)
expr_stmt|;
name|points
index|[
literal|1
index|]
operator|=
name|QPoint
argument_list|(
name|x
operator|+
name|w
argument_list|,
name|y
operator|+
name|h
argument_list|)
expr_stmt|;
name|points
index|[
literal|2
index|]
operator|=
name|QPoint
argument_list|(
name|x
operator|+
name|w
operator|/
literal|2
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// PE_SpinBoxDown
name|points
index|[
literal|0
index|]
operator|=
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|points
index|[
literal|1
index|]
operator|=
name|QPoint
argument_list|(
name|x
operator|+
name|w
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|points
index|[
literal|2
index|]
operator|=
name|QPoint
argument_list|(
name|x
operator|+
name|w
operator|/
literal|2
argument_list|,
name|y
operator|+
name|h
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|option
operator|->
name|state
operator|&
name|State_Enabled
condition|)
block|{
name|painter
operator|->
name|setPen
argument_list|(
name|option
operator|->
name|palette
operator|.
name|mid
argument_list|()
operator|.
name|color
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|option
operator|->
name|palette
operator|.
name|buttonText
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|painter
operator|->
name|setPen
argument_list|(
name|option
operator|->
name|palette
operator|.
name|buttonText
argument_list|()
operator|.
name|color
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|option
operator|->
name|palette
operator|.
name|mid
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|painter
operator|->
name|drawPolygon
argument_list|(
name|points
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QProxyStyle
operator|::
name|drawPrimitive
argument_list|(
name|element
argument_list|,
name|option
argument_list|,
name|painter
argument_list|,
name|widget
argument_list|)
expr_stmt|;
comment|//! [2] //! [3]
block|}
comment|//! [3] //! [4]
block|}
end_function
begin_comment
comment|//! [4]
end_comment
end_unit
