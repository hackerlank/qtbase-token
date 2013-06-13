begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlineedit.h"
end_include
begin_include
include|#
directive|include
file|"qlineedit_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LINEEDIT
end_ifndef
begin_include
include|#
directive|include
file|"qvariant.h"
end_include
begin_include
include|#
directive|include
file|"qabstractitemview.h"
end_include
begin_include
include|#
directive|include
file|"qdrag.h"
end_include
begin_include
include|#
directive|include
file|"qwidgetaction.h"
end_include
begin_include
include|#
directive|include
file|"qclipboard.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_include
include|#
directive|include
file|"qaccessible.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IM
end_ifndef
begin_include
include|#
directive|include
file|"qinputmethod.h"
end_include
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_include
include|#
directive|include
file|<qpropertyanimation.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
specifier|const
name|int
name|QLineEditPrivate
operator|::
name|verticalMargin
argument_list|(
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|int
name|QLineEditPrivate
operator|::
name|horizontalMargin
argument_list|(
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|adjustedControlRect
name|QRect
name|QLineEditPrivate
operator|::
name|adjustedControlRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
specifier|const
block|{
name|QRect
name|widgetRect
init|=
operator|!
name|rect
operator|.
name|isEmpty
argument_list|()
condition|?
name|rect
else|:
name|q_func
argument_list|()
operator|->
name|rect
argument_list|()
decl_stmt|;
name|QRect
name|cr
init|=
name|adjustedContentsRect
argument_list|()
decl_stmt|;
name|int
name|cix
init|=
name|cr
operator|.
name|x
argument_list|()
operator|-
name|hscroll
operator|+
name|horizontalMargin
decl_stmt|;
return|return
name|widgetRect
operator|.
name|translated
argument_list|(
name|QPoint
argument_list|(
name|cix
argument_list|,
name|vscroll
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|xToPos
name|int
name|QLineEditPrivate
operator|::
name|xToPos
parameter_list|(
name|int
name|x
parameter_list|,
name|QTextLine
operator|::
name|CursorPosition
name|betweenOrOn
parameter_list|)
specifier|const
block|{
name|QRect
name|cr
init|=
name|adjustedContentsRect
argument_list|()
decl_stmt|;
name|x
operator|-=
name|cr
operator|.
name|x
argument_list|()
operator|-
name|hscroll
operator|+
name|horizontalMargin
expr_stmt|;
return|return
name|control
operator|->
name|xToPos
argument_list|(
name|x
argument_list|,
name|betweenOrOn
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|cursorRect
name|QRect
name|QLineEditPrivate
operator|::
name|cursorRect
parameter_list|()
specifier|const
block|{
return|return
name|adjustedControlRect
argument_list|(
name|control
operator|->
name|cursorRect
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COMPLETER
end_ifndef
begin_function
DECL|function|_q_completionHighlighted
name|void
name|QLineEditPrivate
operator|::
name|_q_completionHighlighted
parameter_list|(
name|QString
name|newText
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
if|if
condition|(
name|control
operator|->
name|completer
argument_list|()
operator|->
name|completionMode
argument_list|()
operator|!=
name|QCompleter
operator|::
name|InlineCompletion
condition|)
block|{
name|q
operator|->
name|setText
argument_list|(
name|newText
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|int
name|c
init|=
name|control
operator|->
name|cursor
argument_list|()
decl_stmt|;
name|QString
name|text
init|=
name|control
operator|->
name|text
argument_list|()
decl_stmt|;
name|q
operator|->
name|setText
argument_list|(
name|text
operator|.
name|left
argument_list|(
name|c
argument_list|)
operator|+
name|newText
operator|.
name|mid
argument_list|(
name|c
argument_list|)
argument_list|)
expr_stmt|;
name|control
operator|->
name|moveCursor
argument_list|(
name|control
operator|->
name|end
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|control
operator|->
name|moveCursor
argument_list|(
name|c
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_COMPLETER
end_comment
begin_function
DECL|function|_q_handleWindowActivate
name|void
name|QLineEditPrivate
operator|::
name|_q_handleWindowActivate
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|q
operator|->
name|hasFocus
argument_list|()
operator|&&
name|control
operator|->
name|hasSelectedText
argument_list|()
condition|)
name|control
operator|->
name|deselect
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|_q_textEdited
name|void
name|QLineEditPrivate
operator|::
name|_q_textEdited
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|textEdited
argument_list|(
name|text
argument_list|)
emit|;
ifndef|#
directive|ifndef
name|QT_NO_COMPLETER
if|if
condition|(
name|control
operator|->
name|completer
argument_list|()
operator|&&
name|control
operator|->
name|completer
argument_list|()
operator|->
name|completionMode
argument_list|()
operator|!=
name|QCompleter
operator|::
name|InlineCompletion
condition|)
name|control
operator|->
name|complete
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// update the popup on cut/paste/del
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|_q_cursorPositionChanged
name|void
name|QLineEditPrivate
operator|::
name|_q_cursorPositionChanged
parameter_list|(
name|int
name|from
parameter_list|,
name|int
name|to
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
name|q
operator|->
name|update
argument_list|()
expr_stmt|;
emit|emit
name|q
operator|->
name|cursorPositionChanged
argument_list|(
name|from
argument_list|,
name|to
argument_list|)
emit|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
end_ifdef
begin_function
DECL|function|_q_editFocusChange
name|void
name|QLineEditPrivate
operator|::
name|_q_editFocusChange
parameter_list|(
name|bool
name|e
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
name|q
operator|->
name|setEditFocus
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|_q_selectionChanged
name|void
name|QLineEditPrivate
operator|::
name|_q_selectionChanged
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
if|if
condition|(
name|control
operator|->
name|preeditAreaText
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QStyleOptionFrameV2
name|opt
decl_stmt|;
name|q
operator|->
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|bool
name|showCursor
init|=
name|control
operator|->
name|hasSelectedText
argument_list|()
condition|?
name|q
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_BlinkCursorWhenTextSelected
argument_list|,
operator|&
name|opt
argument_list|,
name|q
argument_list|)
else|:
name|q
operator|->
name|hasFocus
argument_list|()
decl_stmt|;
name|setCursorVisible
argument_list|(
name|showCursor
argument_list|)
expr_stmt|;
block|}
emit|emit
name|q
operator|->
name|selectionChanged
argument_list|()
emit|;
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|QAccessibleTextSelectionEvent
name|ev
argument_list|(
name|q
argument_list|,
name|control
operator|->
name|selectionStart
argument_list|()
argument_list|,
name|control
operator|->
name|selectionEnd
argument_list|()
argument_list|)
decl_stmt|;
name|ev
operator|.
name|setCursorPosition
argument_list|(
name|control
operator|->
name|cursorPosition
argument_list|()
argument_list|)
expr_stmt|;
name|QAccessible
operator|::
name|updateAccessibility
argument_list|(
operator|&
name|ev
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|_q_updateNeeded
name|void
name|QLineEditPrivate
operator|::
name|_q_updateNeeded
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|q_func
argument_list|()
operator|->
name|update
argument_list|(
name|adjustedControlRect
argument_list|(
name|rect
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|QLineEditPrivate
operator|::
name|init
parameter_list|(
specifier|const
name|QString
modifier|&
name|txt
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
name|control
operator|=
operator|new
name|QWidgetLineControl
argument_list|(
name|txt
argument_list|)
expr_stmt|;
name|control
operator|->
name|setParent
argument_list|(
name|q
argument_list|)
expr_stmt|;
name|control
operator|->
name|setFont
argument_list|(
name|q
operator|->
name|font
argument_list|()
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|textEdited
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_textEdited
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|cursorPositionChanged
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_cursorPositionChanged
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|selectionChanged
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_selectionChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SIGNAL
argument_list|(
name|returnPressed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|editingFinished
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SIGNAL
argument_list|(
name|editingFinished
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|editFocusChange
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_editFocusChange
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|cursorPositionChanged
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|updateMicroFocus
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|updateMicroFocus
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// for now, going completely overboard with updates.
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|selectionChanged
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|update
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|displayTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|update
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|updateNeeded
argument_list|(
name|QRect
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_updateNeeded
argument_list|(
name|QRect
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QStyleOptionFrameV2
name|opt
decl_stmt|;
name|q
operator|->
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|control
operator|->
name|setPasswordCharacter
argument_list|(
name|q
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_LineEdit_PasswordCharacter
argument_list|,
operator|&
name|opt
argument_list|,
name|q
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|q
operator|->
name|setCursor
argument_list|(
name|Qt
operator|::
name|IBeamCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|q
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|StrongFocus
argument_list|)
expr_stmt|;
name|q
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_InputMethodEnabled
argument_list|)
expr_stmt|;
comment|//   Specifies that this widget can use more, but is able to survive on
comment|//   less, horizontal space; and is fixed vertically.
name|q
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|LineEdit
argument_list|)
argument_list|)
expr_stmt|;
name|q
operator|->
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|)
expr_stmt|;
name|q
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_KeyCompression
argument_list|)
expr_stmt|;
name|q
operator|->
name|setMouseTracking
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|q
operator|->
name|setAcceptDrops
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|q
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_MacShowFocusRect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|adjustedContentsRect
name|QRect
name|QLineEditPrivate
operator|::
name|adjustedContentsRect
parameter_list|()
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QLineEdit
argument_list|)
expr_stmt|;
name|QStyleOptionFrameV2
name|opt
decl_stmt|;
name|q
operator|->
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|QRect
name|r
init|=
name|q
operator|->
name|style
argument_list|()
operator|->
name|subElementRect
argument_list|(
name|QStyle
operator|::
name|SE_LineEditContents
argument_list|,
operator|&
name|opt
argument_list|,
name|q
argument_list|)
decl_stmt|;
name|r
operator|.
name|setX
argument_list|(
name|r
operator|.
name|x
argument_list|()
operator|+
name|effectiveLeftTextMargin
argument_list|()
argument_list|)
expr_stmt|;
name|r
operator|.
name|setY
argument_list|(
name|r
operator|.
name|y
argument_list|()
operator|+
name|topTextMargin
argument_list|)
expr_stmt|;
name|r
operator|.
name|setRight
argument_list|(
name|r
operator|.
name|right
argument_list|()
operator|-
name|effectiveRightTextMargin
argument_list|()
argument_list|)
expr_stmt|;
name|r
operator|.
name|setBottom
argument_list|(
name|r
operator|.
name|bottom
argument_list|()
operator|-
name|bottomTextMargin
argument_list|)
expr_stmt|;
return|return
name|r
return|;
block|}
end_function
begin_function
DECL|function|setCursorVisible
name|void
name|QLineEditPrivate
operator|::
name|setCursorVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|bool
operator|)
name|cursorVisible
operator|==
name|visible
condition|)
return|return;
name|cursorVisible
operator|=
name|visible
expr_stmt|;
if|if
condition|(
name|control
operator|->
name|inputMask
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|q
operator|->
name|update
argument_list|(
name|cursorRect
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|q
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updatePasswordEchoEditing
name|void
name|QLineEditPrivate
operator|::
name|updatePasswordEchoEditing
parameter_list|(
name|bool
name|editing
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
name|control
operator|->
name|updatePasswordEchoEditing
argument_list|(
name|editing
argument_list|)
expr_stmt|;
name|q
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_InputMethodEnabled
argument_list|,
name|shouldEnableInputMethod
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resetInputMethod
name|void
name|QLineEditPrivate
operator|::
name|resetInputMethod
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
if|if
condition|(
name|q
operator|->
name|hasFocus
argument_list|()
operator|&&
name|qApp
condition|)
block|{
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|reset
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   This function is not intended as polymorphic usage. Just a shared code   fragment that calls QInputMethod::invokeAction for this   class. */
end_comment
begin_function
DECL|function|sendMouseEventToInputContext
name|bool
name|QLineEditPrivate
operator|::
name|sendMouseEventToInputContext
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
if|#
directive|if
operator|!
name|defined
name|QT_NO_IM
if|if
condition|(
name|control
operator|->
name|composeMode
argument_list|()
condition|)
block|{
name|int
name|tmp_cursor
init|=
name|xToPos
argument_list|(
name|e
operator|->
name|pos
argument_list|()
operator|.
name|x
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|mousePos
init|=
name|tmp_cursor
operator|-
name|control
operator|->
name|cursor
argument_list|()
decl_stmt|;
if|if
condition|(
name|mousePos
argument_list|<
literal|0
operator|||
name|mousePos
argument_list|>
name|control
operator|->
name|preeditAreaText
argument_list|()
operator|.
name|length
argument_list|()
condition|)
name|mousePos
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|mousePos
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseButtonRelease
condition|)
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|invokeAction
argument_list|(
name|QInputMethod
operator|::
name|Click
argument_list|,
name|mousePos
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|e
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
end_ifndef
begin_function
DECL|function|drag
name|void
name|QLineEditPrivate
operator|::
name|drag
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
name|dndTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
name|QMimeData
modifier|*
name|data
init|=
operator|new
name|QMimeData
decl_stmt|;
name|data
operator|->
name|setText
argument_list|(
name|control
operator|->
name|selectedText
argument_list|()
argument_list|)
expr_stmt|;
name|QDrag
modifier|*
name|drag
init|=
operator|new
name|QDrag
argument_list|(
name|q
argument_list|)
decl_stmt|;
name|drag
operator|->
name|setMimeData
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|Qt
operator|::
name|DropAction
name|action
init|=
name|drag
operator|->
name|start
argument_list|()
decl_stmt|;
if|if
condition|(
name|action
operator|==
name|Qt
operator|::
name|MoveAction
operator|&&
operator|!
name|control
operator|->
name|isReadOnly
argument_list|()
operator|&&
name|drag
operator|->
name|target
argument_list|()
operator|!=
name|q
condition|)
name|control
operator|->
name|removeSelection
argument_list|()
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DRAGANDDROP
end_comment
begin_constructor
DECL|function|QLineEditIconButton
name|QLineEditIconButton
operator|::
name|QLineEditIconButton
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QToolButton
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_opacity
argument_list|(
literal|0
argument_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|setCursor
argument_list|(
name|Qt
operator|::
name|ArrowCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|NoFocus
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|paintEvent
name|void
name|QLineEditIconButton
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
comment|// Note isDown should really use the active state but in most styles
comment|// this has no proper feedback
name|QIcon
operator|::
name|Mode
name|state
init|=
name|QIcon
operator|::
name|Disabled
decl_stmt|;
if|if
condition|(
name|isEnabled
argument_list|()
condition|)
name|state
operator|=
name|isDown
argument_list|()
condition|?
name|QIcon
operator|::
name|Selected
else|:
name|QIcon
operator|::
name|Normal
expr_stmt|;
specifier|const
name|QPixmap
name|iconPixmap
init|=
name|icon
argument_list|()
operator|.
name|pixmap
argument_list|(
name|QSize
argument_list|(
name|IconButtonSize
argument_list|,
name|IconButtonSize
argument_list|)
argument_list|,
name|state
argument_list|,
name|QIcon
operator|::
name|Off
argument_list|)
decl_stmt|;
name|QRect
name|pixmapRect
init|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|iconPixmap
operator|.
name|width
argument_list|()
argument_list|,
name|iconPixmap
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|pixmapRect
operator|.
name|moveCenter
argument_list|(
name|rect
argument_list|()
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setOpacity
argument_list|(
name|m_opacity
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawPixmap
argument_list|(
name|pixmapRect
argument_list|,
name|iconPixmap
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setOpacity
name|void
name|QLineEditIconButton
operator|::
name|setOpacity
parameter_list|(
name|qreal
name|value
parameter_list|)
block|{
if|if
condition|(
operator|!
name|qFuzzyCompare
argument_list|(
name|m_opacity
argument_list|,
name|value
argument_list|)
condition|)
block|{
name|m_opacity
operator|=
name|value
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|startOpacityAnimation
name|void
name|QLineEditIconButton
operator|::
name|startOpacityAnimation
parameter_list|(
name|qreal
name|endValue
parameter_list|)
block|{
name|QPropertyAnimation
modifier|*
name|animation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|this
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"opacity"
argument_list|)
argument_list|)
decl_stmt|;
name|animation
operator|->
name|setDuration
argument_list|(
literal|160
argument_list|)
expr_stmt|;
name|animation
operator|->
name|setEndValue
argument_list|(
name|endValue
argument_list|)
expr_stmt|;
name|animation
operator|->
name|start
argument_list|(
name|QAbstractAnimation
operator|::
name|DeleteWhenStopped
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|_q_textChanged
name|void
name|QLineEditPrivate
operator|::
name|_q_textChanged
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
if|if
condition|(
name|hasSideWidgets
argument_list|()
condition|)
block|{
specifier|const
name|int
name|newTextSize
init|=
name|text
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|newTextSize
operator|||
operator|!
name|lastTextSize
condition|)
block|{
name|lastTextSize
operator|=
name|newTextSize
expr_stmt|;
specifier|const
name|bool
name|fadeIn
init|=
name|newTextSize
operator|>
literal|0
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|SideWidgetEntry
modifier|&
name|e
decl|,
name|leadingSideWidgets
control|)
block|{
if|if
condition|(
name|e
operator|.
name|flags
operator|&
name|SideWidgetFadeInWithText
condition|)
cast|static_cast
argument_list|<
name|QLineEditIconButton
operator|*
argument_list|>
argument_list|(
name|e
operator|.
name|widget
argument_list|)
operator|->
name|animateShow
argument_list|(
name|fadeIn
argument_list|)
expr_stmt|;
block|}
foreach|foreach
control|(
specifier|const
name|SideWidgetEntry
modifier|&
name|e
decl|,
name|trailingSideWidgets
control|)
block|{
if|if
condition|(
name|e
operator|.
name|flags
operator|&
name|SideWidgetFadeInWithText
condition|)
cast|static_cast
argument_list|<
name|QLineEditIconButton
operator|*
argument_list|>
argument_list|(
name|e
operator|.
name|widget
argument_list|)
operator|->
name|animateShow
argument_list|(
name|fadeIn
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|iconSize
name|QSize
name|QLineEditPrivate
operator|::
name|iconSize
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_iconSize
operator|.
name|isValid
argument_list|()
condition|)
comment|// This might require style-specific handling (pixel metric).
name|m_iconSize
operator|=
name|QSize
argument_list|(
name|QLineEditIconButton
operator|::
name|IconButtonSize
operator|+
literal|6
argument_list|,
name|QLineEditIconButton
operator|::
name|IconButtonSize
operator|+
literal|2
argument_list|)
expr_stmt|;
return|return
name|m_iconSize
return|;
block|}
end_function
begin_function
DECL|function|positionSideWidgets
name|void
name|QLineEditPrivate
operator|::
name|positionSideWidgets
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
if|if
condition|(
name|hasSideWidgets
argument_list|()
condition|)
block|{
specifier|const
name|QRect
name|contentRect
init|=
name|q
operator|->
name|rect
argument_list|()
decl_stmt|;
specifier|const
name|QSize
name|iconSize
init|=
name|QLineEditPrivate
operator|::
name|iconSize
argument_list|()
decl_stmt|;
specifier|const
name|int
name|delta
init|=
name|QLineEditIconButton
operator|::
name|IconMargin
operator|+
name|iconSize
operator|.
name|width
argument_list|()
decl_stmt|;
name|QRect
name|widgetGeometry
argument_list|(
name|QPoint
argument_list|(
name|QLineEditIconButton
operator|::
name|IconMargin
argument_list|,
operator|(
name|contentRect
operator|.
name|height
argument_list|()
operator|-
name|iconSize
operator|.
name|height
argument_list|()
operator|)
operator|/
literal|2
argument_list|)
argument_list|,
name|iconSize
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|SideWidgetEntry
modifier|&
name|e
decl|,
name|leftSideWidgetList
argument_list|()
control|)
block|{
name|e
operator|.
name|widget
operator|->
name|setGeometry
argument_list|(
name|widgetGeometry
argument_list|)
expr_stmt|;
name|widgetGeometry
operator|.
name|moveLeft
argument_list|(
name|widgetGeometry
operator|.
name|left
argument_list|()
operator|+
name|delta
argument_list|)
expr_stmt|;
block|}
name|widgetGeometry
operator|.
name|moveLeft
argument_list|(
name|contentRect
operator|.
name|width
argument_list|()
operator|-
name|iconSize
operator|.
name|width
argument_list|()
operator|-
name|QLineEditIconButton
operator|::
name|IconMargin
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|SideWidgetEntry
modifier|&
name|e
decl|,
name|rightSideWidgetList
argument_list|()
control|)
block|{
name|e
operator|.
name|widget
operator|->
name|setGeometry
argument_list|(
name|widgetGeometry
argument_list|)
expr_stmt|;
name|widgetGeometry
operator|.
name|moveLeft
argument_list|(
name|widgetGeometry
operator|.
name|left
argument_list|()
operator|-
name|delta
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|findSideWidget
name|QLineEditPrivate
operator|::
name|PositionIndexPair
name|QLineEditPrivate
operator|::
name|findSideWidget
parameter_list|(
specifier|const
name|QAction
modifier|*
name|a
parameter_list|)
specifier|const
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|leadingSideWidgets
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|a
operator|==
name|leadingSideWidgets
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|action
condition|)
return|return
name|PositionIndexPair
argument_list|(
name|QLineEdit
operator|::
name|LeadingPosition
argument_list|,
name|i
argument_list|)
return|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|trailingSideWidgets
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|a
operator|==
name|trailingSideWidgets
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|action
condition|)
return|return
name|PositionIndexPair
argument_list|(
name|QLineEdit
operator|::
name|TrailingPosition
argument_list|,
name|i
argument_list|)
return|;
block|}
return|return
name|PositionIndexPair
argument_list|(
name|QLineEdit
operator|::
name|LeadingPosition
argument_list|,
operator|-
literal|1
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|addAction
name|QWidget
modifier|*
name|QLineEditPrivate
operator|::
name|addAction
parameter_list|(
name|QAction
modifier|*
name|newAction
parameter_list|,
name|QAction
modifier|*
name|before
parameter_list|,
name|QLineEdit
operator|::
name|ActionPosition
name|position
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|newAction
condition|)
return|return
literal|0
return|;
name|QWidget
modifier|*
name|w
init|=
literal|0
decl_stmt|;
comment|// Store flags about QWidgetAction here since removeAction() may be called from ~QAction,
comment|// in which a qobject_cast<> no longer works.
if|if
condition|(
name|QWidgetAction
modifier|*
name|widgetAction
init|=
name|qobject_cast
argument_list|<
name|QWidgetAction
operator|*
argument_list|>
argument_list|(
name|newAction
argument_list|)
condition|)
block|{
if|if
condition|(
operator|(
name|w
operator|=
name|widgetAction
operator|->
name|requestWidget
argument_list|(
name|q
argument_list|)
operator|)
condition|)
name|flags
operator||=
name|SideWidgetCreatedByWidgetAction
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|w
condition|)
block|{
name|QLineEditIconButton
modifier|*
name|toolButton
init|=
operator|new
name|QLineEditIconButton
argument_list|(
name|q
argument_list|)
decl_stmt|;
name|toolButton
operator|->
name|setIcon
argument_list|(
name|newAction
operator|->
name|icon
argument_list|()
argument_list|)
expr_stmt|;
name|toolButton
operator|->
name|setOpacity
argument_list|(
name|lastTextSize
operator|>
literal|0
operator|||
operator|!
operator|(
name|flags
operator|&
name|SideWidgetFadeInWithText
operator|)
condition|?
literal|1
else|:
literal|0
argument_list|)
expr_stmt|;
name|toolButton
operator|->
name|setDefaultAction
argument_list|(
name|newAction
argument_list|)
expr_stmt|;
name|w
operator|=
name|toolButton
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|hasSideWidgets
argument_list|()
condition|)
block|{
comment|// initial setup.
name|QObject
operator|::
name|connect
argument_list|(
name|q
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|lastTextSize
operator|=
name|q
operator|->
name|text
argument_list|()
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
comment|// If there is a 'before' action, it takes preference
name|PositionIndexPair
name|positionIndex
init|=
name|before
condition|?
name|findSideWidget
argument_list|(
name|before
argument_list|)
else|:
name|PositionIndexPair
argument_list|(
name|position
argument_list|,
operator|-
literal|1
argument_list|)
decl_stmt|;
name|SideWidgetEntryList
modifier|&
name|list
init|=
name|positionIndex
operator|.
name|first
operator|==
name|QLineEdit
operator|::
name|TrailingPosition
condition|?
name|trailingSideWidgets
else|:
name|leadingSideWidgets
decl_stmt|;
if|if
condition|(
name|positionIndex
operator|.
name|second
operator|<
literal|0
condition|)
name|positionIndex
operator|.
name|second
operator|=
name|list
operator|.
name|size
argument_list|()
expr_stmt|;
name|list
operator|.
name|insert
argument_list|(
name|positionIndex
operator|.
name|second
argument_list|,
name|SideWidgetEntry
argument_list|(
name|w
argument_list|,
name|newAction
argument_list|,
name|flags
argument_list|)
argument_list|)
expr_stmt|;
name|positionSideWidgets
argument_list|()
expr_stmt|;
name|w
operator|->
name|show
argument_list|()
expr_stmt|;
return|return
name|w
return|;
block|}
end_function
begin_function
DECL|function|removeAction
name|void
name|QLineEditPrivate
operator|::
name|removeAction
parameter_list|(
specifier|const
name|QActionEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|action
init|=
name|e
operator|->
name|action
argument_list|()
decl_stmt|;
specifier|const
name|PositionIndexPair
name|positionIndex
init|=
name|findSideWidget
argument_list|(
name|action
argument_list|)
decl_stmt|;
if|if
condition|(
name|positionIndex
operator|.
name|second
operator|==
operator|-
literal|1
condition|)
return|return;
name|SideWidgetEntryList
modifier|&
name|list
init|=
name|positionIndex
operator|.
name|first
operator|==
name|QLineEdit
operator|::
name|TrailingPosition
condition|?
name|trailingSideWidgets
else|:
name|leadingSideWidgets
decl_stmt|;
name|SideWidgetEntry
name|entry
init|=
name|list
operator|.
name|takeAt
argument_list|(
name|positionIndex
operator|.
name|second
argument_list|)
decl_stmt|;
if|if
condition|(
name|entry
operator|.
name|flags
operator|&
name|SideWidgetCreatedByWidgetAction
condition|)
cast|static_cast
argument_list|<
name|QWidgetAction
operator|*
argument_list|>
argument_list|(
name|entry
operator|.
name|action
argument_list|)
operator|->
name|releaseWidget
argument_list|(
name|entry
operator|.
name|widget
argument_list|)
expr_stmt|;
else|else
operator|delete
name|entry
operator|.
name|widget
expr_stmt|;
name|positionSideWidgets
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|hasSideWidgets
argument_list|()
condition|)
comment|// Last widget, remove connection
name|QObject
operator|::
name|disconnect
argument_list|(
name|q
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|q
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
