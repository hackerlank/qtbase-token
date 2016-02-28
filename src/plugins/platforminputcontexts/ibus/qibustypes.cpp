begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qibustypes.h"
end_include
begin_include
include|#
directive|include
file|<QtDBus>
end_include
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_LOGGING_CATEGORY
argument_list|(
name|qtQpaInputMethods
argument_list|,
literal|"qt.qpa.input.methods"
argument_list|)
name|Q_LOGGING_CATEGORY
argument_list|(
name|qtQpaInputMethodsSerialize
argument_list|,
literal|"qt.qpa.input.methods.serialize"
argument_list|)
DECL|function|QIBusSerializable
name|QIBusSerializable
operator|::
name|QIBusSerializable
argument_list|()
argument_list|{ }
DECL|function|deserializeFrom
name|void
name|QIBusSerializable
operator|::
name|deserializeFrom
argument_list|(
specifier|const
name|QDBusArgument
operator|&
name|argument
argument_list|)
argument_list|{
name|argument
operator|>>
name|name
argument_list|;
name|argument
operator|.
name|beginMap
argument_list|()
argument_list|;     while
operator|(
operator|!
name|argument
operator|.
name|atEnd
argument_list|()
operator|)
block|{
name|argument
operator|.
name|beginMapEntry
argument_list|()
block|;
name|QString
name|key
block|;
name|QDBusVariant
name|value
block|;
name|argument
operator|>>
name|key
block|;
name|argument
operator|>>
name|value
block|;
name|argument
operator|.
name|endMapEntry
argument_list|()
block|;
name|attachments
index|[
name|key
index|]
operator|=
name|value
operator|.
name|variant
argument_list|()
operator|.
name|value
argument_list|<
name|QDBusArgument
argument_list|>
argument_list|()
block|;     }
name|argument
operator|.
name|endMap
argument_list|()
argument_list|; }
DECL|function|serializeTo
name|void
name|QIBusSerializable
operator|::
name|serializeTo
argument_list|(
name|QDBusArgument
operator|&
name|argument
argument_list|)
decl|const
argument_list|{
name|argument
operator|<<
name|name
argument_list|;
name|argument
operator|.
name|beginMap
argument_list|(
name|qMetaTypeId
argument_list|<
name|QString
argument_list|>
argument_list|()
argument_list|,
name|qMetaTypeId
argument_list|<
name|QDBusVariant
argument_list|>
argument_list|()
argument_list|)
argument_list|;
name|QHashIterator
argument_list|<
name|QString
argument_list|,
name|QDBusArgument
argument_list|>
name|i
argument_list|(
name|attachments
argument_list|)
argument_list|;     while
operator|(
name|i
operator|.
name|hasNext
argument_list|()
operator|)
block|{
name|i
operator|.
name|next
argument_list|()
block|;
name|argument
operator|.
name|beginMapEntry
argument_list|()
block|;
name|argument
operator|<<
name|i
operator|.
name|key
argument_list|()
block|;
name|QDBusVariant
name|variant
argument_list|(
name|i
operator|.
name|value
argument_list|()
operator|.
name|asVariant
argument_list|()
argument_list|)
block|;
name|argument
operator|<<
name|variant
block|;
name|argument
operator|.
name|endMapEntry
argument_list|()
block|;     }
name|argument
operator|.
name|endMap
argument_list|()
argument_list|; }
DECL|function|QIBusAttribute
name|QIBusAttribute
operator|::
name|QIBusAttribute
argument_list|()
range|:
name|type
argument_list|(
name|Invalid
argument_list|)
decl_stmt|,
name|value
argument_list|(
literal|0
argument_list|)
decl_stmt|,
name|start
argument_list|(
literal|0
argument_list|)
decl_stmt|,
name|end
argument_list|(
literal|0
argument_list|)
argument_list|{
name|name
operator|=
literal|"IBusAttribute"
argument_list|; }
DECL|function|serializeTo
name|void
name|QIBusAttribute
operator|::
name|serializeTo
argument_list|(
name|QDBusArgument
operator|&
name|argument
argument_list|)
decl|const
argument_list|{
name|argument
operator|.
name|beginStructure
argument_list|()
argument_list|;
name|QIBusSerializable
operator|::
name|serializeTo
argument_list|(
name|argument
argument_list|)
argument_list|;
name|quint32
name|t
operator|=
operator|(
name|quint32
operator|)
name|type
argument_list|;
name|argument
operator|<<
name|t
argument_list|;
name|argument
operator|<<
name|value
argument_list|;
name|argument
operator|<<
name|start
argument_list|;
name|argument
operator|<<
name|end
argument_list|;
name|argument
operator|.
name|endStructure
argument_list|()
argument_list|; }
DECL|function|deserializeFrom
name|void
name|QIBusAttribute
operator|::
name|deserializeFrom
argument_list|(
specifier|const
name|QDBusArgument
operator|&
name|argument
argument_list|)
argument_list|{
name|argument
operator|.
name|beginStructure
argument_list|()
argument_list|;
name|QIBusSerializable
operator|::
name|deserializeFrom
argument_list|(
name|argument
argument_list|)
argument_list|;
name|quint32
name|t
argument_list|;
name|argument
operator|>>
name|t
argument_list|;
name|type
operator|=
operator|(
name|QIBusAttribute
operator|::
name|Type
operator|)
name|t
argument_list|;
name|argument
operator|>>
name|value
argument_list|;
name|argument
operator|>>
name|start
argument_list|;
name|argument
operator|>>
name|end
argument_list|;
name|argument
operator|.
name|endStructure
argument_list|()
argument_list|; }
DECL|function|format
name|QTextCharFormat
name|QIBusAttribute
operator|::
name|format
argument_list|()
decl|const
argument_list|{
name|QTextCharFormat
name|fmt
argument_list|;     switch
operator|(
name|type
operator|)
block|{
case|case
name|Invalid
case|:
break|break;
case|case
name|Underline
case|:
block|{
name|QTextCharFormat
operator|::
name|UnderlineStyle
name|style
operator|=
name|QTextCharFormat
operator|::
name|NoUnderline
block|;
switch|switch
condition|(
name|value
condition|)
block|{
case|case
name|UnderlineNone
case|:
break|break;
case|case
name|UnderlineSingle
case|:
name|style
operator|=
name|QTextCharFormat
operator|::
name|SingleUnderline
block|;
break|break;
case|case
name|UnderlineDouble
case|:
name|style
operator|=
name|QTextCharFormat
operator|::
name|DashUnderline
argument_list|;             break;         case
name|UnderlineLow
operator|:
name|style
operator|=
name|QTextCharFormat
operator|::
name|DashDotLine
argument_list|;             break;         case
name|UnderlineError
operator|:
name|style
operator|=
name|QTextCharFormat
operator|::
name|WaveUnderline
argument_list|;
name|fmt
operator|.
name|setUnderlineColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
argument_list|;             break;         }
name|fmt
operator|.
name|setUnderlineStyle
argument_list|(
name|style
argument_list|)
decl_stmt|;
end_decl_stmt
begin_break
break|break;
end_break
begin_label
unit|}     case
name|Foreground
label|:
end_label
begin_expr_stmt
name|fmt
operator|.
name|setForeground
argument_list|(
name|QColor
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_break
break|break;
end_break
begin_case
case|case
name|Background
case|:
end_case
begin_expr_stmt
name|fmt
operator|.
name|setBackground
argument_list|(
name|QColor
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_break
break|break;
end_break
begin_expr_stmt
unit|}     return
name|fmt
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  QIBusAttributeList
DECL|function|QIBusAttributeList
operator|::
name|QIBusAttributeList
operator|(
operator|)
block|{
name|name
operator|=
literal|"IBusAttrList"
block|; }
DECL|function|serializeTo
name|void
name|QIBusAttributeList
operator|::
name|serializeTo
operator|(
name|QDBusArgument
operator|&
name|argument
operator|)
specifier|const
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
block|;
name|QIBusSerializable
operator|::
name|serializeTo
argument_list|(
name|argument
argument_list|)
block|;
name|argument
operator|.
name|beginArray
argument_list|(
name|qMetaTypeId
argument_list|<
name|QDBusVariant
argument_list|>
argument_list|()
argument_list|)
block|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|attributes
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QVariant
name|variant
decl_stmt|;
name|variant
operator|.
name|setValue
argument_list|(
name|attributes
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|argument
operator|<<
name|QDBusVariant
argument_list|(
name|variant
argument_list|)
expr_stmt|;
block|}
name|argument
operator|.
name|endArray
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
end_expr_stmt
begin_macro
unit|}  void
DECL|function|deserializeFrom
name|QIBusAttributeList
end_macro
begin_expr_stmt
DECL|function|deserializeFrom
operator|::
name|deserializeFrom
operator|(
specifier|const
name|QDBusArgument
operator|&
name|arg
operator|)
block|{
name|qCDebug
argument_list|(
name|qtQpaInputMethodsSerialize
argument_list|)
operator|<<
literal|"QIBusAttributeList::fromDBusArgument()"
operator|<<
name|arg
operator|.
name|currentSignature
argument_list|()
block|;
name|arg
operator|.
name|beginStructure
argument_list|()
block|;
name|QIBusSerializable
operator|::
name|deserializeFrom
argument_list|(
name|arg
argument_list|)
block|;
name|arg
operator|.
name|beginArray
argument_list|()
block|;
while|while
condition|(
operator|!
name|arg
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QDBusVariant
name|var
decl_stmt|;
name|arg
operator|>>
name|var
expr_stmt|;
name|QIBusAttribute
name|attr
decl_stmt|;
name|var
operator|.
name|variant
argument_list|()
operator|.
name|value
argument_list|<
name|QDBusArgument
argument_list|>
argument_list|()
operator|>>
name|attr
expr_stmt|;
name|attributes
operator|.
name|append
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|attr
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|arg
operator|.
name|endArray
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|arg
operator|.
name|endStructure
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  QList
DECL|function|imAttributes
operator|<
name|QInputMethodEvent
operator|::
name|Attribute
operator|>
name|QIBusAttributeList
operator|::
name|imAttributes
operator|(
operator|)
specifier|const
block|{
name|QHash
argument_list|<
name|QPair
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
argument_list|,
name|QTextCharFormat
argument_list|>
name|rangeAttrs
block|;
specifier|const
name|int
name|numAttributes
operator|=
name|attributes
operator|.
name|size
argument_list|()
block|;
comment|// Merge text fomats for identical ranges into a single QTextFormat.
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|numAttributes
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QIBusAttribute
modifier|&
name|attr
init|=
name|attributes
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
specifier|const
name|QTextCharFormat
modifier|&
name|format
init|=
name|attr
operator|.
name|format
argument_list|()
decl_stmt|;
if|if
condition|(
name|format
operator|.
name|isValid
argument_list|()
condition|)
block|{
specifier|const
name|QPair
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|range
parameter_list|(
name|attr
operator|.
name|start
parameter_list|,
name|attr
operator|.
name|end
parameter_list|)
function_decl|;
name|rangeAttrs
index|[
name|range
index|]
operator|.
name|merge
argument_list|(
name|format
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_comment
unit|}
comment|// Assemble list in original attribute order.
end_comment
begin_expr_stmt
unit|QList
operator|<
name|QInputMethodEvent
operator|::
name|Attribute
operator|>
name|imAttrs
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|imAttrs
operator|.
name|reserve
argument_list|(
name|numAttributes
argument_list|)
expr_stmt|;
end_expr_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|numAttributes
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QIBusAttribute
modifier|&
name|attr
init|=
name|attributes
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
specifier|const
name|QTextFormat
modifier|&
name|format
init|=
name|attr
operator|.
name|format
argument_list|()
decl_stmt|;
name|imAttrs
operator|+=
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|(
name|QInputMethodEvent
operator|::
name|TextFormat
argument_list|,
name|attr
operator|.
name|start
argument_list|,
name|attr
operator|.
name|end
operator|-
name|attr
operator|.
name|start
argument_list|,
name|format
operator|.
name|isValid
argument_list|()
condition|?
name|rangeAttrs
index|[
name|QPair
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
argument_list|(
name|attr
operator|.
name|start
argument_list|,
name|attr
operator|.
name|end
argument_list|)
index|]
else|:
name|format
argument_list|)
expr_stmt|;
block|}
end_for
begin_return
return|return
name|imAttrs
return|;
end_return
begin_expr_stmt
unit|}  QIBusText
DECL|function|QIBusText
operator|::
name|QIBusText
operator|(
operator|)
block|{
name|name
operator|=
literal|"IBusText"
block|; }
DECL|function|serializeTo
name|void
name|QIBusText
operator|::
name|serializeTo
operator|(
name|QDBusArgument
operator|&
name|argument
operator|)
specifier|const
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
block|;
name|QIBusSerializable
operator|::
name|serializeTo
argument_list|(
name|argument
argument_list|)
block|;
name|argument
operator|<<
name|text
operator|<<
name|attributes
block|;
name|argument
operator|.
name|endStructure
argument_list|()
block|; }
DECL|function|deserializeFrom
name|void
name|QIBusText
operator|::
name|deserializeFrom
operator|(
specifier|const
name|QDBusArgument
operator|&
name|argument
operator|)
block|{
name|qCDebug
argument_list|(
name|qtQpaInputMethodsSerialize
argument_list|)
operator|<<
literal|"QIBusText::fromDBusArgument()"
operator|<<
name|argument
operator|.
name|currentSignature
argument_list|()
block|;
name|argument
operator|.
name|beginStructure
argument_list|()
block|;
name|QIBusSerializable
operator|::
name|deserializeFrom
argument_list|(
name|argument
argument_list|)
block|;
name|argument
operator|>>
name|text
block|;
name|QDBusVariant
name|variant
block|;
name|argument
operator|>>
name|variant
block|;
name|variant
operator|.
name|variant
argument_list|()
operator|.
name|value
argument_list|<
name|QDBusArgument
argument_list|>
argument_list|()
operator|>>
name|attributes
block|;
name|argument
operator|.
name|endStructure
argument_list|()
block|; }
DECL|function|QIBusEngineDesc
name|QIBusEngineDesc
operator|::
name|QIBusEngineDesc
argument_list|()
operator|:
name|engine_name
argument_list|(
literal|""
argument_list|)
operator|,
name|longname
argument_list|(
literal|""
argument_list|)
operator|,
name|description
argument_list|(
literal|""
argument_list|)
operator|,
name|language
argument_list|(
literal|""
argument_list|)
operator|,
name|license
argument_list|(
literal|""
argument_list|)
operator|,
name|author
argument_list|(
literal|""
argument_list|)
operator|,
name|icon
argument_list|(
literal|""
argument_list|)
operator|,
name|layout
argument_list|(
literal|""
argument_list|)
operator|,
name|rank
argument_list|(
literal|0
argument_list|)
operator|,
name|hotkeys
argument_list|(
literal|""
argument_list|)
operator|,
name|symbol
argument_list|(
literal|""
argument_list|)
operator|,
name|setup
argument_list|(
literal|""
argument_list|)
operator|,
name|layout_variant
argument_list|(
literal|""
argument_list|)
operator|,
name|layout_option
argument_list|(
literal|""
argument_list|)
operator|,
name|version
argument_list|(
literal|""
argument_list|)
operator|,
name|textdomain
argument_list|(
literal|""
argument_list|)
operator|,
name|iconpropkey
argument_list|(
literal|""
argument_list|)
block|{
name|name
operator|=
literal|"IBusEngineDesc"
block|; }
DECL|function|serializeTo
name|void
name|QIBusEngineDesc
operator|::
name|serializeTo
operator|(
name|QDBusArgument
operator|&
name|argument
operator|)
specifier|const
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
block|;
name|QIBusSerializable
operator|::
name|serializeTo
argument_list|(
name|argument
argument_list|)
block|;
name|argument
operator|<<
name|engine_name
block|;
name|argument
operator|<<
name|longname
block|;
name|argument
operator|<<
name|description
block|;
name|argument
operator|<<
name|language
block|;
name|argument
operator|<<
name|license
block|;
name|argument
operator|<<
name|author
block|;
name|argument
operator|<<
name|icon
block|;
name|argument
operator|<<
name|layout
block|;
name|argument
operator|<<
name|rank
block|;
name|argument
operator|<<
name|hotkeys
block|;
name|argument
operator|<<
name|symbol
block|;
name|argument
operator|<<
name|setup
block|;
name|argument
operator|<<
name|layout_variant
block|;
name|argument
operator|<<
name|layout_option
block|;
name|argument
operator|<<
name|version
block|;
name|argument
operator|<<
name|textdomain
block|;
name|argument
operator|<<
name|iconpropkey
block|;
name|argument
operator|.
name|endStructure
argument_list|()
block|; }
DECL|function|deserializeFrom
name|void
name|QIBusEngineDesc
operator|::
name|deserializeFrom
operator|(
specifier|const
name|QDBusArgument
operator|&
name|argument
operator|)
block|{
name|qCDebug
argument_list|(
name|qtQpaInputMethodsSerialize
argument_list|)
operator|<<
literal|"QIBusEngineDesc::fromDBusArgument()"
operator|<<
name|argument
operator|.
name|currentSignature
argument_list|()
block|;
name|argument
operator|.
name|beginStructure
argument_list|()
block|;
name|QIBusSerializable
operator|::
name|deserializeFrom
argument_list|(
name|argument
argument_list|)
block|;
name|argument
operator|>>
name|engine_name
block|;
name|argument
operator|>>
name|longname
block|;
name|argument
operator|>>
name|description
block|;
name|argument
operator|>>
name|language
block|;
name|argument
operator|>>
name|license
block|;
name|argument
operator|>>
name|author
block|;
name|argument
operator|>>
name|icon
block|;
name|argument
operator|>>
name|layout
block|;
name|argument
operator|>>
name|rank
block|;
name|argument
operator|>>
name|hotkeys
block|;
name|argument
operator|>>
name|symbol
block|;
name|argument
operator|>>
name|setup
block|;
comment|// Previous IBusEngineDesc supports the arguments between engine_name
comment|// and setup.
if|if
condition|(
name|argument
operator|.
name|currentSignature
argument_list|()
operator|==
literal|""
condition|)
goto|goto
name|olderThanV2
goto|;
name|argument
operator|>>
name|layout_variant
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|argument
operator|>>
name|layout_option
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Previous IBusEngineDesc supports the arguments between engine_name
end_comment
begin_comment
comment|// and layout_option.
end_comment
begin_if
if|if
condition|(
name|argument
operator|.
name|currentSignature
argument_list|()
operator|==
literal|""
condition|)
goto|goto
name|olderThanV3
goto|;
end_if
begin_expr_stmt
name|argument
operator|>>
name|version
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|argument
operator|.
name|currentSignature
argument_list|()
operator|==
literal|""
condition|)
goto|goto
name|olderThanV4
goto|;
end_if
begin_expr_stmt
name|argument
operator|>>
name|textdomain
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|argument
operator|.
name|currentSignature
argument_list|()
operator|==
literal|""
condition|)
goto|goto
name|olderThanV5
goto|;
end_if
begin_expr_stmt
name|argument
operator|>>
name|iconpropkey
expr_stmt|;
end_expr_stmt
begin_comment
comment|//<-- insert new member streaming here (1/2)
end_comment
begin_goto
goto|goto
name|newest
goto|;
end_goto
begin_label
name|olderThanV2
label|:
end_label
begin_expr_stmt
name|layout_variant
operator|.
name|clear
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|layout_option
operator|.
name|clear
argument_list|()
expr_stmt|;
end_expr_stmt
begin_label
name|olderThanV3
label|:
end_label
begin_expr_stmt
name|version
operator|.
name|clear
argument_list|()
expr_stmt|;
end_expr_stmt
begin_label
name|olderThanV4
label|:
end_label
begin_expr_stmt
name|textdomain
operator|.
name|clear
argument_list|()
expr_stmt|;
end_expr_stmt
begin_label
name|olderThanV5
label|:
end_label
begin_expr_stmt
name|iconpropkey
operator|.
name|clear
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//<-- insert new members here (2/2)
end_comment
begin_label
name|newest
label|:
end_label
begin_expr_stmt
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
end_expr_stmt
unit|}  QT_END_NAMESPACE
end_unit
