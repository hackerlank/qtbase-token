begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcomposeplatforminputcontext.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QKeyEvent>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|//#define DEBUG_COMPOSING
DECL|variable|ignoreKeys
specifier|static
specifier|const
name|int
name|ignoreKeys
index|[]
init|=
block|{
name|Qt
operator|::
name|Key_Shift
block|,
name|Qt
operator|::
name|Key_Control
block|,
name|Qt
operator|::
name|Key_Meta
block|,
name|Qt
operator|::
name|Key_Alt
block|,
name|Qt
operator|::
name|Key_CapsLock
block|,
name|Qt
operator|::
name|Key_Super_L
block|,
name|Qt
operator|::
name|Key_Super_R
block|,
name|Qt
operator|::
name|Key_Hyper_L
block|,
name|Qt
operator|::
name|Key_Hyper_R
block|,
name|Qt
operator|::
name|Key_Mode_switch
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|composingKeys
specifier|static
specifier|const
name|int
name|composingKeys
index|[]
init|=
block|{
name|Qt
operator|::
name|Key_Multi_key
block|,
name|Qt
operator|::
name|Key_Dead_Grave
block|,
name|Qt
operator|::
name|Key_Dead_Acute
block|,
name|Qt
operator|::
name|Key_Dead_Circumflex
block|,
name|Qt
operator|::
name|Key_Dead_Tilde
block|,
name|Qt
operator|::
name|Key_Dead_Macron
block|,
name|Qt
operator|::
name|Key_Dead_Breve
block|,
name|Qt
operator|::
name|Key_Dead_Abovedot
block|,
name|Qt
operator|::
name|Key_Dead_Diaeresis
block|,
name|Qt
operator|::
name|Key_Dead_Abovering
block|,
name|Qt
operator|::
name|Key_Dead_Doubleacute
block|,
name|Qt
operator|::
name|Key_Dead_Caron
block|,
name|Qt
operator|::
name|Key_Dead_Cedilla
block|,
name|Qt
operator|::
name|Key_Dead_Ogonek
block|,
name|Qt
operator|::
name|Key_Dead_Iota
block|,
name|Qt
operator|::
name|Key_Dead_Voiced_Sound
block|,
name|Qt
operator|::
name|Key_Dead_Semivoiced_Sound
block|,
name|Qt
operator|::
name|Key_Dead_Belowdot
block|,
name|Qt
operator|::
name|Key_Dead_Hook
block|,
name|Qt
operator|::
name|Key_Dead_Horn
block|}
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QComposeInputContext
name|QComposeInputContext
operator|::
name|QComposeInputContext
parameter_list|()
block|{
name|TableGenerator
name|reader
decl_stmt|;
name|m_tableState
operator|=
name|reader
operator|.
name|tableState
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|m_tableState
operator|&
name|TableGenerator
operator|::
name|NoErrors
operator|)
operator|==
name|TableGenerator
operator|::
name|NoErrors
condition|)
block|{
name|m_composeTable
operator|=
name|reader
operator|.
name|composeTable
argument_list|()
expr_stmt|;
name|clearComposeBuffer
argument_list|()
expr_stmt|;
block|}
block|}
end_constructor
begin_function
DECL|function|filterEvent
name|bool
name|QComposeInputContext
operator|::
name|filterEvent
parameter_list|(
specifier|const
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
comment|// if there were errors when generating the compose table input
comment|// context should not try to filter anything, simply return false
if|if
condition|(
operator|(
name|m_tableState
operator|&
name|TableGenerator
operator|::
name|NoErrors
operator|)
operator|!=
name|TableGenerator
operator|::
name|NoErrors
condition|)
return|return
literal|false
return|;
name|QKeyEvent
modifier|*
name|keyEvent
init|=
operator|(
name|QKeyEvent
operator|*
operator|)
name|event
decl_stmt|;
comment|// should pass only the key presses
if|if
condition|(
name|keyEvent
operator|->
name|type
argument_list|()
operator|!=
name|QEvent
operator|::
name|KeyPress
condition|)
block|{
return|return
literal|false
return|;
block|}
name|int
name|keyval
init|=
name|keyEvent
operator|->
name|key
argument_list|()
decl_stmt|;
name|int
name|keysym
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|ignoreKey
argument_list|(
name|keyval
argument_list|)
condition|)
return|return
literal|false
return|;
name|QString
name|text
init|=
name|keyEvent
operator|->
name|text
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|composeKey
argument_list|(
name|keyval
argument_list|)
operator|&&
name|text
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|false
return|;
name|keysym
operator|=
name|keyEvent
operator|->
name|nativeVirtualKey
argument_list|()
expr_stmt|;
name|int
name|nCompose
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|m_composeBuffer
index|[
name|nCompose
index|]
operator|!=
literal|0
operator|&&
name|nCompose
operator|<
name|QT_KEYSEQUENCE_MAX_LEN
condition|)
name|nCompose
operator|++
expr_stmt|;
if|if
condition|(
name|nCompose
operator|==
name|QT_KEYSEQUENCE_MAX_LEN
condition|)
block|{
name|reset
argument_list|()
expr_stmt|;
name|nCompose
operator|=
literal|0
expr_stmt|;
block|}
name|m_composeBuffer
index|[
name|nCompose
index|]
operator|=
name|keysym
expr_stmt|;
comment|// check sequence
if|if
condition|(
name|checkComposeTable
argument_list|()
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|isValid
name|bool
name|QComposeInputContext
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|setFocusObject
name|void
name|QComposeInputContext
operator|::
name|setFocusObject
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|m_focusObject
operator|=
name|object
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reset
name|void
name|QComposeInputContext
operator|::
name|reset
parameter_list|()
block|{
name|clearComposeBuffer
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|update
name|void
name|QComposeInputContext
operator|::
name|update
parameter_list|(
name|Qt
operator|::
name|InputMethodQueries
name|q
parameter_list|)
block|{
name|QPlatformInputContext
operator|::
name|update
argument_list|(
name|q
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isDuplicate
specifier|static
name|bool
name|isDuplicate
parameter_list|(
specifier|const
name|QComposeTableElement
modifier|&
name|lhs
parameter_list|,
specifier|const
name|QComposeTableElement
modifier|&
name|rhs
parameter_list|)
block|{
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|QT_KEYSEQUENCE_MAX_LEN
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|lhs
operator|.
name|keys
index|[
name|i
index|]
operator|!=
name|rhs
operator|.
name|keys
index|[
name|i
index|]
condition|)
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|checkComposeTable
name|bool
name|QComposeInputContext
operator|::
name|checkComposeTable
parameter_list|()
block|{
name|QVector
argument_list|<
name|QComposeTableElement
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|std
operator|::
name|lower_bound
argument_list|(
name|m_composeTable
operator|.
name|constBegin
argument_list|()
argument_list|,
name|m_composeTable
operator|.
name|constEnd
argument_list|()
argument_list|,
name|m_composeBuffer
argument_list|,
name|Compare
argument_list|()
argument_list|)
decl_stmt|;
comment|// prevent dereferencing an 'end' iterator, which would result in a crash
if|if
condition|(
name|it
operator|==
name|m_composeTable
operator|.
name|constEnd
argument_list|()
condition|)
name|it
operator|-=
literal|1
expr_stmt|;
name|QComposeTableElement
name|elem
init|=
operator|*
name|it
decl_stmt|;
comment|// would be nicer if qLowerBound had API that tells if the item was actually found
if|if
condition|(
name|m_composeBuffer
index|[
literal|0
index|]
operator|!=
name|elem
operator|.
name|keys
index|[
literal|0
index|]
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG_COMPOSING
name|qDebug
argument_list|(
literal|"### no match ###"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|reset
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// check if compose buffer is matched
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|QT_KEYSEQUENCE_MAX_LEN
condition|;
name|i
operator|++
control|)
block|{
comment|// check if partial match
if|if
condition|(
name|m_composeBuffer
index|[
name|i
index|]
operator|==
literal|0
operator|&&
name|elem
operator|.
name|keys
index|[
name|i
index|]
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG_COMPOSING
name|qDebug
argument_list|(
literal|"### partial match ###"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|true
return|;
block|}
if|if
condition|(
name|m_composeBuffer
index|[
name|i
index|]
operator|!=
name|elem
operator|.
name|keys
index|[
name|i
index|]
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG_COMPOSING
name|qDebug
argument_list|(
literal|"### different entry ###"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|reset
argument_list|()
expr_stmt|;
return|return
name|i
operator|!=
literal|0
return|;
block|}
block|}
ifdef|#
directive|ifdef
name|DEBUG_COMPOSING
name|qDebug
argument_list|(
literal|"### match exactly ###"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// check if the key sequence is overwriten - see the comment in
comment|// TableGenerator::orderComposeTable()
name|int
name|next
init|=
literal|1
decl_stmt|;
do|do
block|{
comment|// if we are at the end of the table, then we have nothing to do here
if|if
condition|(
name|it
operator|+
name|next
operator|!=
name|m_composeTable
operator|.
name|end
argument_list|()
condition|)
block|{
name|QComposeTableElement
name|nextElem
init|=
operator|*
operator|(
name|it
operator|+
name|next
operator|)
decl_stmt|;
if|if
condition|(
name|isDuplicate
argument_list|(
name|elem
argument_list|,
name|nextElem
argument_list|)
condition|)
block|{
name|elem
operator|=
name|nextElem
expr_stmt|;
name|next
operator|++
expr_stmt|;
continue|continue;
block|}
else|else
block|{
break|break;
block|}
block|}
break|break;
block|}
do|while
condition|(
literal|true
condition|)
do|;
name|commitText
argument_list|(
name|elem
operator|.
name|value
argument_list|)
expr_stmt|;
name|reset
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|commitText
name|void
name|QComposeInputContext
operator|::
name|commitText
parameter_list|(
name|uint
name|character
parameter_list|)
specifier|const
block|{
name|QInputMethodEvent
name|event
decl_stmt|;
name|event
operator|.
name|setCommitString
argument_list|(
name|QChar
argument_list|(
name|character
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
name|m_focusObject
argument_list|,
operator|&
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|ignoreKey
name|bool
name|QComposeInputContext
operator|::
name|ignoreKey
parameter_list|(
name|int
name|keyval
parameter_list|)
specifier|const
block|{
for|for
control|(
name|uint
name|i
init|=
literal|0
init|;
name|i
operator|<
operator|(
sizeof|sizeof
argument_list|(
name|ignoreKeys
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|ignoreKeys
index|[
literal|0
index|]
argument_list|)
operator|)
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|keyval
operator|==
name|ignoreKeys
index|[
name|i
index|]
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|composeKey
name|bool
name|QComposeInputContext
operator|::
name|composeKey
parameter_list|(
name|int
name|keyval
parameter_list|)
specifier|const
block|{
for|for
control|(
name|uint
name|i
init|=
literal|0
init|;
name|i
operator|<
operator|(
sizeof|sizeof
argument_list|(
name|composingKeys
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|composingKeys
index|[
literal|0
index|]
argument_list|)
operator|)
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|keyval
operator|==
name|composingKeys
index|[
name|i
index|]
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|clearComposeBuffer
name|void
name|QComposeInputContext
operator|::
name|clearComposeBuffer
parameter_list|()
block|{
for|for
control|(
name|uint
name|i
init|=
literal|0
init|;
name|i
operator|<
operator|(
sizeof|sizeof
argument_list|(
name|m_composeBuffer
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|)
condition|;
name|i
operator|++
control|)
name|m_composeBuffer
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_destructor
DECL|function|~QComposeInputContext
name|QComposeInputContext
operator|::
name|~
name|QComposeInputContext
parameter_list|()
block|{}
end_destructor
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
