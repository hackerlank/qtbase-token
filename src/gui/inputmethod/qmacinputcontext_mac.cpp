begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qvarlengtharray.h>
end_include
begin_include
include|#
directive|include
file|<qwidget.h>
end_include
begin_include
include|#
directive|include
file|<private/qmacinputcontext_p.h>
end_include
begin_include
include|#
directive|include
file|"qtextformat.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<private/qapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qkeymapper_p.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
specifier|extern
name|bool
name|qt_sendSpontaneousEvent
parameter_list|(
name|QObject
modifier|*
parameter_list|,
name|QEvent
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_if
if|#
directive|if
operator|(
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|<
name|MAC_OS_X_VERSION_10_5
operator|)
end_if
begin_define
DECL|macro|typeRefCon
define|#
directive|define
name|typeRefCon
value|typeSInt32
end_define
begin_define
DECL|macro|typeByteCount
define|#
directive|define
name|typeByteCount
value|typeSInt32
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|QMacInputContext
name|QMacInputContext
operator|::
name|QMacInputContext
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QInputContext
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|composing
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|recursionGuard
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|textDocument
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|keydownEvent
argument_list|(
literal|0
argument_list|)
block|{
comment|//    createTextDocument();
block|}
end_constructor
begin_destructor
DECL|function|~QMacInputContext
name|QMacInputContext
operator|::
name|~
name|QMacInputContext
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_MAC_USE_COCOA
if|if
condition|(
name|textDocument
condition|)
name|DeleteTSMDocument
argument_list|(
name|textDocument
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_destructor
begin_function
name|void
DECL|function|createTextDocument
name|QMacInputContext
operator|::
name|createTextDocument
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_MAC_USE_COCOA
if|if
condition|(
operator|!
name|textDocument
condition|)
block|{
name|InterfaceTypeList
name|itl
init|=
block|{
name|kUnicodeDocument
block|}
decl_stmt|;
name|NewTSMDocument
argument_list|(
literal|1
argument_list|,
name|itl
argument_list|,
operator|&
name|textDocument
argument_list|,
name|SRefCon
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|language
name|QString
name|QMacInputContext
operator|::
name|language
parameter_list|()
block|{
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|mouseHandler
name|void
name|QMacInputContext
operator|::
name|mouseHandler
parameter_list|(
name|int
name|pos
parameter_list|,
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_MAC_USE_COCOA
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|!=
name|QEvent
operator|::
name|MouseButtonPress
condition|)
return|return;
if|if
condition|(
operator|!
name|composing
condition|)
return|return;
if|if
condition|(
name|pos
argument_list|<
literal|0
operator|||
name|pos
argument_list|>
name|currentText
operator|.
name|length
argument_list|()
condition|)
name|reset
argument_list|()
expr_stmt|;
comment|// ##### handle mouse position
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|pos
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|e
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_if
if|#
directive|if
operator|!
name|defined
name|QT_MAC_USE_COCOA
end_if
begin_function
DECL|function|qt_mac_compose_format
specifier|static
name|QTextFormat
name|qt_mac_compose_format
parameter_list|()
block|{
name|QTextCharFormat
name|ret
decl_stmt|;
name|ret
operator|.
name|setFontUnderline
argument_list|(
literal|true
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|reset
name|void
name|QMacInputContext
operator|::
name|reset
parameter_list|()
block|{
if|if
condition|(
name|recursionGuard
condition|)
return|return;
if|if
condition|(
operator|!
name|currentText
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QInputMethodEvent
name|e
decl_stmt|;
name|e
operator|.
name|setCommitString
argument_list|(
name|currentText
argument_list|)
expr_stmt|;
name|qt_sendSpontaneousEvent
argument_list|(
name|focusWidget
argument_list|()
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
name|currentText
operator|=
name|QString
argument_list|()
expr_stmt|;
block|}
name|recursionGuard
operator|=
literal|true
expr_stmt|;
name|createTextDocument
argument_list|()
expr_stmt|;
name|composing
operator|=
literal|false
expr_stmt|;
name|ActivateTSMDocument
argument_list|(
name|textDocument
argument_list|)
expr_stmt|;
name|FixTSMDocument
argument_list|(
name|textDocument
argument_list|)
expr_stmt|;
name|recursionGuard
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isComposing
name|bool
name|QMacInputContext
operator|::
name|isComposing
parameter_list|()
specifier|const
block|{
return|return
name|composing
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|setFocusWidget
name|void
name|QMacInputContext
operator|::
name|setFocusWidget
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
block|{
name|createTextDocument
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_MAC_USE_COCOA
if|if
condition|(
name|w
condition|)
name|ActivateTSMDocument
argument_list|(
name|textDocument
argument_list|)
expr_stmt|;
else|else
name|DeactivateTSMDocument
argument_list|(
name|textDocument
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QInputContext
operator|::
name|setFocusWidget
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_MAC_USE_COCOA
end_ifndef
begin_decl_stmt
DECL|variable|input_events
specifier|static
name|EventTypeSpec
name|input_events
index|[]
init|=
block|{
block|{
name|kEventClassTextInput
block|,
name|kEventTextInputUnicodeForKeyEvent
block|}
block|,
block|{
name|kEventClassTextInput
block|,
name|kEventTextInputOffsetToPos
block|}
block|,
block|{
name|kEventClassTextInput
block|,
name|kEventTextInputUpdateActiveInputArea
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|input_proc_handlerUPP
specifier|static
name|EventHandlerUPP
name|input_proc_handlerUPP
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|input_proc_handler
specifier|static
name|EventHandlerRef
name|input_proc_handler
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|void
DECL|function|initialize
name|QMacInputContext
operator|::
name|initialize
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_MAC_USE_COCOA
if|if
condition|(
operator|!
name|input_proc_handler
condition|)
block|{
name|input_proc_handlerUPP
operator|=
name|NewEventHandlerUPP
argument_list|(
name|QMacInputContext
operator|::
name|globalEventProcessor
argument_list|)
expr_stmt|;
name|InstallEventHandler
argument_list|(
name|GetApplicationEventTarget
argument_list|()
argument_list|,
name|input_proc_handlerUPP
argument_list|,
name|GetEventTypeCount
argument_list|(
name|input_events
argument_list|)
argument_list|,
name|input_events
argument_list|,
literal|0
argument_list|,
operator|&
name|input_proc_handler
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_function
name|void
DECL|function|cleanup
name|QMacInputContext
operator|::
name|cleanup
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_MAC_USE_COCOA
if|if
condition|(
name|input_proc_handler
condition|)
block|{
name|RemoveEventHandler
argument_list|(
name|input_proc_handler
argument_list|)
expr_stmt|;
name|input_proc_handler
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|input_proc_handlerUPP
condition|)
block|{
name|DisposeEventHandlerUPP
argument_list|(
name|input_proc_handlerUPP
argument_list|)
expr_stmt|;
name|input_proc_handlerUPP
operator|=
literal|0
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|setLastKeydownEvent
name|void
name|QMacInputContext
operator|::
name|setLastKeydownEvent
parameter_list|(
name|EventRef
name|event
parameter_list|)
block|{
name|EventRef
name|tmpEvent
init|=
name|keydownEvent
decl_stmt|;
name|keydownEvent
operator|=
name|event
expr_stmt|;
if|if
condition|(
name|keydownEvent
condition|)
name|RetainEvent
argument_list|(
name|keydownEvent
argument_list|)
expr_stmt|;
if|if
condition|(
name|tmpEvent
condition|)
name|ReleaseEvent
argument_list|(
name|tmpEvent
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|OSStatus
DECL|function|globalEventProcessor
name|QMacInputContext
operator|::
name|globalEventProcessor
parameter_list|(
name|EventHandlerCallRef
parameter_list|,
name|EventRef
name|event
parameter_list|,
name|void
modifier|*
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_MAC_USE_COCOA
name|QScopedLoopLevelCounter
name|loopLevelCounter
argument_list|(
name|QApplicationPrivate
operator|::
name|instance
argument_list|()
operator|->
name|threadData
argument_list|)
decl_stmt|;
name|SRefCon
name|refcon
init|=
literal|0
decl_stmt|;
name|GetEventParameter
argument_list|(
name|event
argument_list|,
name|kEventParamTextInputSendRefCon
argument_list|,
name|typeRefCon
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|refcon
argument_list|)
argument_list|,
literal|0
argument_list|,
operator|&
name|refcon
argument_list|)
expr_stmt|;
name|QMacInputContext
modifier|*
name|context
init|=
cast|reinterpret_cast
argument_list|<
name|QMacInputContext
operator|*
argument_list|>
argument_list|(
name|refcon
argument_list|)
decl_stmt|;
name|bool
name|handled_event
init|=
literal|true
decl_stmt|;
name|UInt32
name|ekind
init|=
name|GetEventKind
argument_list|(
name|event
argument_list|)
decl_stmt|,
name|eclass
init|=
name|GetEventClass
argument_list|(
name|event
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|eclass
condition|)
block|{
case|case
name|kEventClassTextInput
case|:
block|{
name|handled_event
operator|=
literal|false
expr_stmt|;
name|QWidget
modifier|*
name|widget
init|=
name|QApplicationPrivate
operator|::
name|focus_widget
decl_stmt|;
name|bool
name|canCompose
init|=
name|widget
operator|&&
operator|(
operator|!
name|context
operator|||
name|widget
operator|->
name|inputContext
argument_list|()
operator|==
name|context
operator|)
operator|&&
operator|!
operator|(
name|widget
operator|->
name|inputMethodHints
argument_list|()
operator|&
name|Qt
operator|::
name|ImhDigitsOnly
operator|||
name|widget
operator|->
name|inputMethodHints
argument_list|()
operator|&
name|Qt
operator|::
name|ImhFormattedNumbersOnly
operator|||
name|widget
operator|->
name|inputMethodHints
argument_list|()
operator|&
name|Qt
operator|::
name|ImhHiddenText
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|canCompose
condition|)
block|{
name|handled_event
operator|=
literal|false
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ekind
operator|==
name|kEventTextInputOffsetToPos
condition|)
block|{
if|if
condition|(
operator|!
name|widget
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_InputMethodEnabled
argument_list|)
condition|)
block|{
name|handled_event
operator|=
literal|false
expr_stmt|;
break|break;
block|}
name|QRect
name|mr
argument_list|(
name|widget
operator|->
name|inputMethodQuery
argument_list|(
name|Qt
operator|::
name|ImMicroFocus
argument_list|)
operator|.
name|toRect
argument_list|()
argument_list|)
decl_stmt|;
name|QPoint
name|mp
argument_list|(
name|widget
operator|->
name|mapToGlobal
argument_list|(
name|QPoint
argument_list|(
name|mr
operator|.
name|topLeft
argument_list|()
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|Point
name|pt
decl_stmt|;
name|pt
operator|.
name|h
operator|=
name|mp
operator|.
name|x
argument_list|()
expr_stmt|;
name|pt
operator|.
name|v
operator|=
name|mp
operator|.
name|y
argument_list|()
operator|+
name|mr
operator|.
name|height
argument_list|()
expr_stmt|;
name|SetEventParameter
argument_list|(
name|event
argument_list|,
name|kEventParamTextInputReplyPoint
argument_list|,
name|typeQDPoint
argument_list|,
sizeof|sizeof
argument_list|(
name|pt
argument_list|)
argument_list|,
operator|&
name|pt
argument_list|)
expr_stmt|;
name|handled_event
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ekind
operator|==
name|kEventTextInputUpdateActiveInputArea
condition|)
block|{
if|if
condition|(
operator|!
name|widget
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_InputMethodEnabled
argument_list|)
condition|)
block|{
name|handled_event
operator|=
literal|false
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|context
operator|->
name|recursionGuard
condition|)
break|break;
name|ByteCount
name|unilen
init|=
literal|0
decl_stmt|;
name|GetEventParameter
argument_list|(
name|event
argument_list|,
name|kEventParamTextInputSendText
argument_list|,
name|typeUnicodeText
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|unilen
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|UniChar
modifier|*
name|unicode
init|=
operator|(
name|UniChar
operator|*
operator|)
name|NewPtr
argument_list|(
name|unilen
argument_list|)
decl_stmt|;
name|GetEventParameter
argument_list|(
name|event
argument_list|,
name|kEventParamTextInputSendText
argument_list|,
name|typeUnicodeText
argument_list|,
literal|0
argument_list|,
name|unilen
argument_list|,
literal|0
argument_list|,
name|unicode
argument_list|)
expr_stmt|;
name|QString
name|text
argument_list|(
operator|(
name|QChar
operator|*
operator|)
name|unicode
argument_list|,
name|unilen
operator|/
sizeof|sizeof
argument_list|(
name|UniChar
argument_list|)
argument_list|)
decl_stmt|;
name|DisposePtr
argument_list|(
operator|(
name|char
operator|*
operator|)
name|unicode
argument_list|)
expr_stmt|;
name|ByteCount
name|fixed_length
init|=
literal|0
decl_stmt|;
name|GetEventParameter
argument_list|(
name|event
argument_list|,
name|kEventParamTextInputSendFixLen
argument_list|,
name|typeByteCount
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|fixed_length
argument_list|)
argument_list|,
literal|0
argument_list|,
operator|&
name|fixed_length
argument_list|)
expr_stmt|;
if|if
condition|(
name|fixed_length
operator|==
name|ULONG_MAX
operator|||
name|fixed_length
operator|==
name|unilen
condition|)
block|{
name|QInputMethodEvent
name|e
decl_stmt|;
name|e
operator|.
name|setCommitString
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|context
operator|->
name|currentText
operator|=
name|QString
argument_list|()
expr_stmt|;
name|qt_sendSpontaneousEvent
argument_list|(
name|context
operator|->
name|focusWidget
argument_list|()
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
name|handled_event
operator|=
literal|true
expr_stmt|;
name|context
operator|->
name|reset
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|ByteCount
name|rngSize
init|=
literal|0
decl_stmt|;
name|OSStatus
name|err
init|=
name|GetEventParameter
argument_list|(
name|event
argument_list|,
name|kEventParamTextInputSendHiliteRng
argument_list|,
name|typeTextRangeArray
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|rngSize
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QVarLengthArray
argument_list|<
name|TextRangeArray
argument_list|>
name|highlight
argument_list|(
name|rngSize
argument_list|)
decl_stmt|;
if|if
condition|(
name|noErr
operator|==
name|err
condition|)
block|{
name|err
operator|=
name|GetEventParameter
argument_list|(
name|event
argument_list|,
name|kEventParamTextInputSendHiliteRng
argument_list|,
name|typeTextRangeArray
argument_list|,
literal|0
argument_list|,
name|rngSize
argument_list|,
operator|&
name|rngSize
argument_list|,
name|highlight
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|context
operator|->
name|composing
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|fixed_length
operator|>
literal|0
condition|)
block|{
specifier|const
name|int
name|qFixedLength
init|=
name|fixed_length
operator|/
sizeof|sizeof
argument_list|(
name|UniChar
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|>
name|attrs
decl_stmt|;
name|attrs
operator|<<
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|(
name|QInputMethodEvent
operator|::
name|TextFormat
argument_list|,
name|qFixedLength
argument_list|,
name|text
operator|.
name|length
argument_list|()
operator|-
name|qFixedLength
argument_list|,
name|qt_mac_compose_format
argument_list|()
argument_list|)
expr_stmt|;
name|QInputMethodEvent
name|e
argument_list|(
name|text
argument_list|,
name|attrs
argument_list|)
decl_stmt|;
name|context
operator|->
name|currentText
operator|=
name|text
expr_stmt|;
name|e
operator|.
name|setCommitString
argument_list|(
name|text
operator|.
name|left
argument_list|(
name|qFixedLength
argument_list|)
argument_list|,
literal|0
argument_list|,
name|qFixedLength
argument_list|)
expr_stmt|;
name|qt_sendSpontaneousEvent
argument_list|(
name|widget
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
name|handled_event
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
comment|/* Apple's enums that they have removed from Tiger :(                     enum {                         kCaretPosition = 1,                         kRawText = 2,                         kSelectedRawText = 3,                         kConvertedText = 4,                         kSelectedConvertedText = 5,                         kBlockFillText = 6,                         kOutlineText = 7,                         kSelectedText = 8                     };                     */
ifndef|#
directive|ifndef
name|kConvertedText
DECL|macro|kConvertedText
define|#
directive|define
name|kConvertedText
value|4
endif|#
directive|endif
ifndef|#
directive|ifndef
name|kCaretPosition
DECL|macro|kCaretPosition
define|#
directive|define
name|kCaretPosition
value|1
endif|#
directive|endif
name|QList
argument_list|<
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|>
name|attrs
decl_stmt|;
if|if
condition|(
operator|!
name|highlight
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|TextRangeArray
modifier|*
name|data
init|=
name|highlight
operator|.
name|data
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|data
operator|->
name|fNumOfRanges
condition|;
operator|++
name|i
control|)
block|{
name|int
name|start
init|=
name|data
operator|->
name|fRange
index|[
name|i
index|]
operator|.
name|fStart
operator|/
sizeof|sizeof
argument_list|(
name|UniChar
argument_list|)
decl_stmt|;
name|int
name|len
init|=
operator|(
name|data
operator|->
name|fRange
index|[
name|i
index|]
operator|.
name|fEnd
operator|-
name|data
operator|->
name|fRange
index|[
name|i
index|]
operator|.
name|fStart
operator|)
operator|/
sizeof|sizeof
argument_list|(
name|UniChar
argument_list|)
decl_stmt|;
if|if
condition|(
name|data
operator|->
name|fRange
index|[
name|i
index|]
operator|.
name|fHiliteStyle
operator|==
name|kCaretPosition
condition|)
block|{
name|attrs
operator|<<
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|(
name|QInputMethodEvent
operator|::
name|Cursor
argument_list|,
name|start
argument_list|,
literal|0
argument_list|,
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|QTextCharFormat
name|format
decl_stmt|;
name|format
operator|.
name|setFontUnderline
argument_list|(
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
name|data
operator|->
name|fRange
index|[
name|i
index|]
operator|.
name|fHiliteStyle
operator|==
name|kConvertedText
condition|)
name|format
operator|.
name|setUnderlineColor
argument_list|(
name|Qt
operator|::
name|gray
argument_list|)
expr_stmt|;
else|else
name|format
operator|.
name|setUnderlineColor
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|attrs
operator|<<
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|(
name|QInputMethodEvent
operator|::
name|TextFormat
argument_list|,
name|start
argument_list|,
name|len
argument_list|,
name|format
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|attrs
operator|<<
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|(
name|QInputMethodEvent
operator|::
name|TextFormat
argument_list|,
literal|0
argument_list|,
name|text
operator|.
name|length
argument_list|()
argument_list|,
name|qt_mac_compose_format
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|context
operator|->
name|currentText
operator|=
name|text
expr_stmt|;
name|QInputMethodEvent
name|e
argument_list|(
name|text
argument_list|,
name|attrs
argument_list|)
decl_stmt|;
name|qt_sendSpontaneousEvent
argument_list|(
name|widget
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
name|handled_event
operator|=
literal|true
expr_stmt|;
block|}
block|}
if|#
directive|if
literal|0
block|if(!context->composing)                 handled_event = false;
endif|#
directive|endif
specifier|extern
name|bool
name|qt_mac_eat_unicode_key
decl_stmt|;
comment|//qapplication_mac.cpp
name|qt_mac_eat_unicode_key
operator|=
name|handled_event
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ekind
operator|==
name|kEventTextInputUnicodeForKeyEvent
condition|)
block|{
name|EventRef
name|key_ev
init|=
literal|0
decl_stmt|;
name|GetEventParameter
argument_list|(
name|event
argument_list|,
name|kEventParamTextInputSendKeyboardEvent
argument_list|,
name|typeEventRef
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|key_ev
argument_list|)
argument_list|,
literal|0
argument_list|,
operator|&
name|key_ev
argument_list|)
expr_stmt|;
name|QString
name|text
decl_stmt|;
name|ByteCount
name|unilen
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|GetEventParameter
argument_list|(
name|key_ev
argument_list|,
name|kEventParamKeyUnicodes
argument_list|,
name|typeUnicodeText
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|unilen
argument_list|,
literal|0
argument_list|)
operator|==
name|noErr
condition|)
block|{
name|UniChar
modifier|*
name|unicode
init|=
operator|(
name|UniChar
operator|*
operator|)
name|NewPtr
argument_list|(
name|unilen
argument_list|)
decl_stmt|;
name|GetEventParameter
argument_list|(
name|key_ev
argument_list|,
name|kEventParamKeyUnicodes
argument_list|,
name|typeUnicodeText
argument_list|,
literal|0
argument_list|,
name|unilen
argument_list|,
literal|0
argument_list|,
name|unicode
argument_list|)
expr_stmt|;
name|text
operator|=
name|QString
argument_list|(
operator|(
name|QChar
operator|*
operator|)
name|unicode
argument_list|,
name|unilen
operator|/
sizeof|sizeof
argument_list|(
name|UniChar
argument_list|)
argument_list|)
expr_stmt|;
name|DisposePtr
argument_list|(
operator|(
name|char
operator|*
operator|)
name|unicode
argument_list|)
expr_stmt|;
block|}
name|unsigned
name|char
name|chr
init|=
literal|0
decl_stmt|;
name|GetEventParameter
argument_list|(
name|key_ev
argument_list|,
name|kEventParamKeyMacCharCodes
argument_list|,
name|typeChar
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|chr
argument_list|)
argument_list|,
literal|0
argument_list|,
operator|&
name|chr
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|chr
operator|||
name|chr
operator|>=
literal|128
operator|||
operator|(
name|text
operator|.
name|length
argument_list|()
operator|>
literal|0
operator|&&
operator|(
name|text
operator|.
name|length
argument_list|()
operator|>
literal|1
operator|||
name|text
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|!=
name|QLatin1Char
argument_list|(
name|chr
argument_list|)
operator|)
operator|)
condition|)
name|handled_event
operator|=
operator|!
name|widget
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_InputMethodEnabled
argument_list|)
expr_stmt|;
name|QMacInputContext
modifier|*
name|context
init|=
name|qobject_cast
argument_list|<
name|QMacInputContext
operator|*
argument_list|>
argument_list|(
name|qApp
operator|->
name|inputContext
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|context
operator|&&
name|context
operator|->
name|lastKeydownEvent
argument_list|()
condition|)
block|{
name|qt_keymapper_private
argument_list|()
operator|->
name|translateKeyEvent
argument_list|(
name|widget
argument_list|,
literal|0
argument_list|,
name|context
operator|->
name|lastKeydownEvent
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|context
operator|->
name|setLastKeydownEvent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
block|}
default|default:
break|break;
block|}
if|if
condition|(
operator|!
name|handled_event
condition|)
comment|//let the event go through
return|return
name|eventNotHandledErr
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|noErr
return|;
comment|//we eat the event
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
