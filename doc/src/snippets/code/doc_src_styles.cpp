begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_expr_stmt
name|opt
operator|.
name|initFrom
argument_list|(
name|q
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|down
condition|)
name|opt
operator|.
name|state
operator||=
name|QStyle
operator|::
name|State_Sunken
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|tristate
operator|&&
name|noChange
condition|)
name|opt
operator|.
name|state
operator||=
name|QStyle
operator|::
name|State_NoChange
expr_stmt|;
else|else
name|opt
operator|.
name|state
operator||=
name|checked
condition|?
name|QStyle
operator|::
name|State_On
else|:
name|QStyle
operator|::
name|State_Off
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|q
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_Hover
argument_list|)
operator|&&
name|q
operator|->
name|underMouse
argument_list|()
condition|)
block|{
if|if
condition|(
name|hovering
condition|)
name|opt
operator|.
name|state
operator||=
name|QStyle
operator|::
name|State_MouseOver
expr_stmt|;
else|else
name|opt
operator|.
name|state
operator|&=
operator|~
name|QStyle
operator|::
name|State_MouseOver
expr_stmt|;
block|}
end_if
begin_expr_stmt
name|opt
operator|.
name|text
operator|=
name|text
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|opt
operator|.
name|icon
operator|=
name|icon
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|opt
operator|.
name|iconSize
operator|=
name|q
operator|->
name|iconSize
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_expr_stmt
name|state
operator|=
name|QStyle
operator|::
name|State_None
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|widget
operator|->
name|isEnabled
argument_list|()
condition|)
name|state
operator||=
name|QStyle
operator|::
name|State_Enabled
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|widget
operator|->
name|hasFocus
argument_list|()
condition|)
name|state
operator||=
name|QStyle
operator|::
name|State_HasFocus
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|widget
operator|->
name|window
argument_list|()
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_KeyboardFocusChange
argument_list|)
condition|)
name|state
operator||=
name|QStyle
operator|::
name|State_KeyboardFocusChange
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|widget
operator|->
name|underMouse
argument_list|()
condition|)
name|state
operator||=
name|QStyle
operator|::
name|State_MouseOver
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|widget
operator|->
name|window
argument_list|()
operator|->
name|isActiveWindow
argument_list|()
condition|)
name|state
operator||=
name|QStyle
operator|::
name|State_Active
expr_stmt|;
end_if
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_MAC
end_ifdef
begin_function_decl
specifier|extern
name|bool
name|qt_mac_can_clickThrough
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|w
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//qwidget_mac.cpp
end_comment
begin_if
if|if
condition|(
operator|!
operator|(
name|state
operator|&
name|QStyle
operator|::
name|State_Active
operator|)
operator|&&
operator|!
name|qt_mac_can_clickThrough
argument_list|(
name|widget
argument_list|)
condition|)
name|state
operator|&=
operator|~
name|QStyle
operator|::
name|State_Enabled
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
end_ifdef
begin_if
if|if
condition|(
name|widget
operator|->
name|hasEditFocus
argument_list|()
condition|)
name|state
operator||=
name|QStyle
operator|::
name|State_HasEditFocus
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|direction
operator|=
name|widget
operator|->
name|layoutDirection
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|rect
operator|=
name|widget
operator|->
name|rect
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|palette
operator|=
name|widget
operator|->
name|palette
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|fontMetrics
operator|=
name|widget
operator|->
name|fontMetrics
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function_decl
name|QStylePainter
name|p
parameter_list|(
name|this
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|opt
name|QStyleOptionButton
name|opt
init|=
name|d
operator|->
name|getStyleOption
argument_list|()
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|p
operator|.
name|drawControl
argument_list|(
name|QStyle
operator|::
name|CE_CheckBox
argument_list|,
name|opt
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
DECL|variable|subopt
name|QStyleOptionButton
name|subopt
init|=
operator|*
name|btn
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|subopt
operator|.
name|rect
operator|=
name|subElementRect
argument_list|(
name|SE_CheckBoxIndicator
argument_list|,
name|btn
argument_list|,
name|widget
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|drawPrimitive
argument_list|(
name|PE_IndicatorCheckBox
argument_list|,
operator|&
name|subopt
argument_list|,
name|p
argument_list|,
name|widget
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|subopt
operator|.
name|rect
operator|=
name|subElementRect
argument_list|(
name|SE_CheckBoxContents
argument_list|,
name|btn
argument_list|,
name|widget
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|drawControl
argument_list|(
name|CE_CheckBoxLabel
argument_list|,
operator|&
name|subopt
argument_list|,
name|p
argument_list|,
name|widget
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|btn
operator|->
name|state
operator|&
name|State_HasFocus
condition|)
block|{
name|QStyleOptionFocusRect
name|fropt
decl_stmt|;
name|fropt
operator|.
name|QStyleOption
operator|::
name|operator
name|=
argument_list|(
operator|*
name|btn
argument_list|)
expr_stmt|;
name|fropt
operator|.
name|rect
operator|=
name|subElementRect
argument_list|(
name|SE_CheckBoxFocusRect
argument_list|,
name|btn
argument_list|,
name|widget
argument_list|)
expr_stmt|;
name|drawPrimitive
argument_list|(
name|PE_FrameFocusRect
argument_list|,
operator|&
name|fropt
argument_list|,
name|p
argument_list|,
name|widget
argument_list|)
expr_stmt|;
block|}
end_if
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
DECL|variable|btn
specifier|const
name|QStyleOptionButton
modifier|*
name|btn
init|=
name|qstyleoption_cast
argument_list|<
specifier|const
name|QStyleOptionButton
operator|*
argument_list|>
argument_list|(
name|opt
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|alignment
name|uint
name|alignment
init|=
name|visualAlignment
argument_list|(
name|btn
operator|->
name|direction
argument_list|,
name|Qt
operator|::
name|AlignLeft
operator||
name|Qt
operator|::
name|AlignVCenter
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
operator|!
name|styleHint
argument_list|(
name|SH_UnderlineShortcut
argument_list|,
name|btn
argument_list|,
name|widget
argument_list|)
condition|)
name|alignment
operator||=
name|Qt
operator|::
name|TextHideMnemonic
expr_stmt|;
end_if
begin_decl_stmt
DECL|variable|pix
name|QPixmap
name|pix
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|textRect
name|QRect
name|textRect
init|=
name|btn
operator|->
name|rect
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
operator|!
name|btn
operator|->
name|icon
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|pix
operator|=
name|btn
operator|->
name|icon
operator|.
name|pixmap
argument_list|(
name|btn
operator|->
name|iconSize
argument_list|,
name|btn
operator|->
name|state
operator|&
name|State_Enabled
condition|?
name|QIcon
operator|::
name|Normal
else|:
name|QIcon
operator|::
name|Disabled
argument_list|)
expr_stmt|;
name|drawItemPixmap
argument_list|(
name|p
argument_list|,
name|btn
operator|->
name|rect
argument_list|,
name|alignment
argument_list|,
name|pix
argument_list|)
expr_stmt|;
if|if
condition|(
name|btn
operator|->
name|direction
operator|==
name|Qt
operator|::
name|RightToLeft
condition|)
name|textRect
operator|.
name|setRight
argument_list|(
name|textRect
operator|.
name|right
argument_list|()
operator|-
name|btn
operator|->
name|iconSize
operator|.
name|width
argument_list|()
operator|-
literal|4
argument_list|)
expr_stmt|;
else|else
name|textRect
operator|.
name|setLeft
argument_list|(
name|textRect
operator|.
name|left
argument_list|()
operator|+
name|btn
operator|->
name|iconSize
operator|.
name|width
argument_list|()
operator|+
literal|4
argument_list|)
expr_stmt|;
block|}
end_if
begin_if
if|if
condition|(
operator|!
name|btn
operator|->
name|text
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|drawItemText
argument_list|(
name|p
argument_list|,
name|textRect
argument_list|,
name|alignment
operator||
name|Qt
operator|::
name|TextShowMnemonic
argument_list|,
name|btn
operator|->
name|palette
argument_list|,
name|btn
operator|->
name|state
operator|&
name|State_Enabled
argument_list|,
name|btn
operator|->
name|text
argument_list|,
name|QPalette
operator|::
name|WindowText
argument_list|)
expr_stmt|;
block|}
end_if
begin_comment
comment|//! [4]
end_comment
end_unit
