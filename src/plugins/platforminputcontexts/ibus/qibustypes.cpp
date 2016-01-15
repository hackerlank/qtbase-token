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
DECL|function|~QIBusSerializable
name|QIBusSerializable
operator|::
name|~
name|QIBusSerializable
argument_list|()
argument_list|{ }
decl|const
DECL|function|operator >>
name|QDBusArgument
modifier|&
name|operator
name|>>
argument_list|(
specifier|const
name|QDBusArgument
operator|&
name|argument
argument_list|,
name|QIBusSerializable
operator|&
name|object
argument_list|)
argument_list|{
name|argument
operator|>>
name|object
operator|.
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
name|object
operator|.
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
argument_list|;     return
name|argument
argument_list|; }
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
argument_list|(
name|QDBusArgument
operator|&
name|argument
argument_list|,
specifier|const
name|QIBusSerializable
operator|&
name|object
argument_list|)
argument_list|{
name|argument
operator|<<
name|object
operator|.
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
name|object
operator|.
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
argument_list|;     return
name|argument
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
DECL|function|~QIBusAttribute
name|QIBusAttribute
operator|::
name|~
name|QIBusAttribute
argument_list|()
argument_list|{ }
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
argument_list|(
name|QDBusArgument
operator|&
name|argument
argument_list|,
specifier|const
name|QIBusAttribute
operator|&
name|attribute
argument_list|)
argument_list|{
name|argument
operator|.
name|beginStructure
argument_list|()
argument_list|;
name|argument
operator|<<
cast|static_cast
argument_list|<
specifier|const
name|QIBusSerializable
operator|&
argument_list|>
argument_list|(
name|attribute
argument_list|)
argument_list|;
name|quint32
name|t
operator|=
operator|(
name|quint32
operator|)
name|attribute
operator|.
name|type
argument_list|;
name|argument
operator|<<
name|t
argument_list|;
name|argument
operator|<<
name|attribute
operator|.
name|value
argument_list|;
name|argument
operator|<<
name|attribute
operator|.
name|start
argument_list|;
name|argument
operator|<<
name|attribute
operator|.
name|end
argument_list|;
name|argument
operator|.
name|endStructure
argument_list|()
argument_list|;      return
name|argument
argument_list|; }
decl|const
DECL|function|operator >>
name|QDBusArgument
modifier|&
name|operator
name|>>
argument_list|(
specifier|const
name|QDBusArgument
operator|&
name|argument
argument_list|,
name|QIBusAttribute
operator|&
name|attribute
argument_list|)
argument_list|{
name|argument
operator|.
name|beginStructure
argument_list|()
argument_list|;
name|argument
operator|>>
cast|static_cast
argument_list|<
name|QIBusSerializable
operator|&
argument_list|>
argument_list|(
name|attribute
argument_list|)
argument_list|;
name|quint32
name|t
argument_list|;
name|argument
operator|>>
name|t
argument_list|;
name|attribute
operator|.
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
name|attribute
operator|.
name|value
argument_list|;
name|argument
operator|>>
name|attribute
operator|.
name|start
argument_list|;
name|argument
operator|>>
name|attribute
operator|.
name|end
argument_list|;
name|argument
operator|.
name|endStructure
argument_list|()
argument_list|;      return
name|argument
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
DECL|function|~QIBusAttributeList
name|QIBusAttributeList
operator|::
name|~
name|QIBusAttributeList
operator|(
operator|)
block|{ }
DECL|function|operator <<
name|QDBusArgument
operator|&
name|operator
name|<<
operator|(
name|QDBusArgument
operator|&
name|argument
operator|,
specifier|const
name|QIBusAttributeList
operator|&
name|attrList
operator|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
block|;
name|argument
operator|<<
cast|static_cast
argument_list|<
specifier|const
name|QIBusSerializable
operator|&
argument_list|>
argument_list|(
name|attrList
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
name|attrList
operator|.
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
name|attrList
operator|.
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
begin_return
return|return
name|argument
return|;
end_return
begin_function
unit|}  const
DECL|function|operator >>
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|QIBusAttributeList
modifier|&
name|attrList
parameter_list|)
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
expr_stmt|;
name|arg
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|arg
operator|>>
cast|static_cast
argument_list|<
name|QIBusSerializable
operator|&
argument_list|>
argument_list|(
name|attrList
argument_list|)
expr_stmt|;
name|arg
operator|.
name|beginArray
argument_list|()
expr_stmt|;
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
name|attrList
operator|.
name|attributes
operator|.
name|append
argument_list|(
name|attr
argument_list|)
expr_stmt|;
block|}
name|arg
operator|.
name|endArray
argument_list|()
expr_stmt|;
name|arg
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|imAttributes
name|QList
argument_list|<
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|>
name|QIBusAttributeList
operator|::
name|imAttributes
parameter_list|()
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
decl_stmt|;
specifier|const
name|int
name|numAttributes
init|=
name|attributes
operator|.
name|size
argument_list|()
decl_stmt|;
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
argument_list|(
name|attr
operator|.
name|start
argument_list|,
name|attr
operator|.
name|end
argument_list|)
decl_stmt|;
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
block|}
comment|// Assemble list in original attribute order.
name|QList
argument_list|<
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|>
name|imAttrs
decl_stmt|;
name|imAttrs
operator|.
name|reserve
argument_list|(
name|numAttributes
argument_list|)
expr_stmt|;
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
return|return
name|imAttrs
return|;
block|}
end_function
begin_constructor
DECL|function|QIBusText
name|QIBusText
operator|::
name|QIBusText
parameter_list|()
block|{
name|name
operator|=
literal|"IBusText"
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QIBusText
name|QIBusText
operator|::
name|~
name|QIBusText
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|QIBusText
modifier|&
name|text
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
cast|static_cast
argument_list|<
specifier|const
name|QIBusSerializable
operator|&
argument_list|>
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|argument
operator|<<
name|text
operator|.
name|text
operator|<<
name|text
operator|.
name|attributes
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
name|QIBusText
modifier|&
name|text
parameter_list|)
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
expr_stmt|;
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|>>
cast|static_cast
argument_list|<
name|QIBusSerializable
operator|&
argument_list|>
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|argument
operator|>>
name|text
operator|.
name|text
expr_stmt|;
name|QDBusVariant
name|variant
decl_stmt|;
name|argument
operator|>>
name|variant
expr_stmt|;
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
name|text
operator|.
name|attributes
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_constructor
DECL|function|QIBusEngineDesc
name|QIBusEngineDesc
operator|::
name|QIBusEngineDesc
parameter_list|()
member_init_list|:
name|engine_name
argument_list|(
literal|""
argument_list|)
member_init_list|,
name|longname
argument_list|(
literal|""
argument_list|)
member_init_list|,
name|description
argument_list|(
literal|""
argument_list|)
member_init_list|,
name|language
argument_list|(
literal|""
argument_list|)
member_init_list|,
name|license
argument_list|(
literal|""
argument_list|)
member_init_list|,
name|author
argument_list|(
literal|""
argument_list|)
member_init_list|,
name|icon
argument_list|(
literal|""
argument_list|)
member_init_list|,
name|layout
argument_list|(
literal|""
argument_list|)
member_init_list|,
name|rank
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|hotkeys
argument_list|(
literal|""
argument_list|)
member_init_list|,
name|symbol
argument_list|(
literal|""
argument_list|)
member_init_list|,
name|setup
argument_list|(
literal|""
argument_list|)
member_init_list|,
name|layout_variant
argument_list|(
literal|""
argument_list|)
member_init_list|,
name|layout_option
argument_list|(
literal|""
argument_list|)
member_init_list|,
name|version
argument_list|(
literal|""
argument_list|)
member_init_list|,
name|textdomain
argument_list|(
literal|""
argument_list|)
member_init_list|,
name|iconpropkey
argument_list|(
literal|""
argument_list|)
block|{
name|name
operator|=
literal|"IBusEngineDesc"
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QIBusEngineDesc
name|QIBusEngineDesc
operator|::
name|~
name|QIBusEngineDesc
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|QIBusEngineDesc
modifier|&
name|desc
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
cast|static_cast
argument_list|<
specifier|const
name|QIBusSerializable
operator|&
argument_list|>
argument_list|(
name|desc
argument_list|)
expr_stmt|;
name|argument
operator|<<
name|desc
operator|.
name|engine_name
expr_stmt|;
name|argument
operator|<<
name|desc
operator|.
name|longname
expr_stmt|;
name|argument
operator|<<
name|desc
operator|.
name|description
expr_stmt|;
name|argument
operator|<<
name|desc
operator|.
name|language
expr_stmt|;
name|argument
operator|<<
name|desc
operator|.
name|license
expr_stmt|;
name|argument
operator|<<
name|desc
operator|.
name|author
expr_stmt|;
name|argument
operator|<<
name|desc
operator|.
name|icon
expr_stmt|;
name|argument
operator|<<
name|desc
operator|.
name|layout
expr_stmt|;
name|argument
operator|<<
name|desc
operator|.
name|rank
expr_stmt|;
name|argument
operator|<<
name|desc
operator|.
name|hotkeys
expr_stmt|;
name|argument
operator|<<
name|desc
operator|.
name|symbol
expr_stmt|;
name|argument
operator|<<
name|desc
operator|.
name|setup
expr_stmt|;
name|argument
operator|<<
name|desc
operator|.
name|layout_variant
expr_stmt|;
name|argument
operator|<<
name|desc
operator|.
name|layout_option
expr_stmt|;
name|argument
operator|<<
name|desc
operator|.
name|version
expr_stmt|;
name|argument
operator|<<
name|desc
operator|.
name|textdomain
expr_stmt|;
name|argument
operator|<<
name|desc
operator|.
name|iconpropkey
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
name|QIBusEngineDesc
modifier|&
name|desc
parameter_list|)
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
expr_stmt|;
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|>>
cast|static_cast
argument_list|<
name|QIBusSerializable
operator|&
argument_list|>
argument_list|(
name|desc
argument_list|)
expr_stmt|;
name|argument
operator|>>
name|desc
operator|.
name|engine_name
expr_stmt|;
name|argument
operator|>>
name|desc
operator|.
name|longname
expr_stmt|;
name|argument
operator|>>
name|desc
operator|.
name|description
expr_stmt|;
name|argument
operator|>>
name|desc
operator|.
name|language
expr_stmt|;
name|argument
operator|>>
name|desc
operator|.
name|license
expr_stmt|;
name|argument
operator|>>
name|desc
operator|.
name|author
expr_stmt|;
name|argument
operator|>>
name|desc
operator|.
name|icon
expr_stmt|;
name|argument
operator|>>
name|desc
operator|.
name|layout
expr_stmt|;
name|argument
operator|>>
name|desc
operator|.
name|rank
expr_stmt|;
name|argument
operator|>>
name|desc
operator|.
name|hotkeys
expr_stmt|;
name|argument
operator|>>
name|desc
operator|.
name|symbol
expr_stmt|;
name|argument
operator|>>
name|desc
operator|.
name|setup
expr_stmt|;
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
block|{
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
name|argument
operator|>>
name|desc
operator|.
name|layout_variant
expr_stmt|;
name|argument
operator|>>
name|desc
operator|.
name|layout_option
expr_stmt|;
comment|// Previous IBusEngineDesc supports the arguments between engine_name
comment|// and layout_option.
if|if
condition|(
name|argument
operator|.
name|currentSignature
argument_list|()
operator|==
literal|""
condition|)
block|{
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
name|argument
operator|>>
name|desc
operator|.
name|version
expr_stmt|;
if|if
condition|(
name|argument
operator|.
name|currentSignature
argument_list|()
operator|==
literal|""
condition|)
block|{
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
name|argument
operator|>>
name|desc
operator|.
name|textdomain
expr_stmt|;
if|if
condition|(
name|argument
operator|.
name|currentSignature
argument_list|()
operator|==
literal|""
condition|)
block|{
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
name|argument
operator|>>
name|desc
operator|.
name|iconpropkey
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
