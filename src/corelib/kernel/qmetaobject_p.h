begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMETAOBJECT_P_H
end_ifndef
begin_define
DECL|macro|QMETAOBJECT_P_H
define|#
directive|define
name|QMETAOBJECT_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of moc.  This header file may change from version to version without notice,
end_comment
begin_comment
comment|// or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobjectdefs.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|enum|PropertyFlags
name|enum
name|PropertyFlags
block|{
DECL|enumerator|Invalid
name|Invalid
operator|=
literal|0x00000000
operator|,
DECL|enumerator|Readable
name|Readable
operator|=
literal|0x00000001
operator|,
DECL|enumerator|Writable
name|Writable
operator|=
literal|0x00000002
operator|,
DECL|enumerator|Resettable
name|Resettable
operator|=
literal|0x00000004
operator|,
DECL|enumerator|EnumOrFlag
name|EnumOrFlag
operator|=
literal|0x00000008
operator|,
DECL|enumerator|StdCppSet
name|StdCppSet
operator|=
literal|0x00000100
operator|,
comment|//     Override = 0x00000200,
DECL|enumerator|Constant
name|Constant
operator|=
literal|0x00000400
operator|,
DECL|enumerator|Final
name|Final
operator|=
literal|0x00000800
operator|,
DECL|enumerator|Designable
name|Designable
operator|=
literal|0x00001000
operator|,
DECL|enumerator|ResolveDesignable
name|ResolveDesignable
operator|=
literal|0x00002000
operator|,
DECL|enumerator|Scriptable
name|Scriptable
operator|=
literal|0x00004000
operator|,
DECL|enumerator|ResolveScriptable
name|ResolveScriptable
operator|=
literal|0x00008000
operator|,
DECL|enumerator|Stored
name|Stored
operator|=
literal|0x00010000
operator|,
DECL|enumerator|ResolveStored
name|ResolveStored
operator|=
literal|0x00020000
operator|,
DECL|enumerator|Editable
name|Editable
operator|=
literal|0x00040000
operator|,
DECL|enumerator|ResolveEditable
name|ResolveEditable
operator|=
literal|0x00080000
operator|,
DECL|enumerator|User
name|User
operator|=
literal|0x00100000
operator|,
DECL|enumerator|ResolveUser
name|ResolveUser
operator|=
literal|0x00200000
operator|,
DECL|enumerator|Notify
name|Notify
operator|=
literal|0x00400000
operator|,
DECL|enumerator|Revisioned
name|Revisioned
operator|=
literal|0x00800000
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_enum
DECL|enum|MethodFlags
enum|enum
name|MethodFlags
block|{
DECL|enumerator|AccessPrivate
name|AccessPrivate
init|=
literal|0x00
block|,
DECL|enumerator|AccessProtected
name|AccessProtected
init|=
literal|0x01
block|,
DECL|enumerator|AccessPublic
name|AccessPublic
init|=
literal|0x02
block|,
DECL|enumerator|AccessMask
name|AccessMask
init|=
literal|0x03
block|,
comment|//mask
DECL|enumerator|MethodMethod
name|MethodMethod
init|=
literal|0x00
block|,
DECL|enumerator|MethodSignal
name|MethodSignal
init|=
literal|0x04
block|,
DECL|enumerator|MethodSlot
name|MethodSlot
init|=
literal|0x08
block|,
DECL|enumerator|MethodConstructor
name|MethodConstructor
init|=
literal|0x0c
block|,
DECL|enumerator|MethodTypeMask
name|MethodTypeMask
init|=
literal|0x0c
block|,
DECL|enumerator|MethodCompatibility
name|MethodCompatibility
init|=
literal|0x10
block|,
DECL|enumerator|MethodCloned
name|MethodCloned
init|=
literal|0x20
block|,
DECL|enumerator|MethodScriptable
name|MethodScriptable
init|=
literal|0x40
block|,
DECL|enumerator|MethodRevisioned
name|MethodRevisioned
init|=
literal|0x80
block|}
enum|;
end_enum
begin_enum
DECL|enum|MetaObjectFlags
enum|enum
name|MetaObjectFlags
block|{
DECL|enumerator|DynamicMetaObject
name|DynamicMetaObject
init|=
literal|0x01
block|}
enum|;
end_enum
begin_decl_stmt
DECL|variable|QMutex
name|class
name|QMutex
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QMetaObjectPrivate
struct|struct
name|QMetaObjectPrivate
block|{
DECL|member|revision
name|int
name|revision
decl_stmt|;
DECL|member|className
name|int
name|className
decl_stmt|;
DECL|member|classInfoCount
DECL|member|classInfoData
name|int
name|classInfoCount
decl_stmt|,
name|classInfoData
decl_stmt|;
DECL|member|methodCount
DECL|member|methodData
name|int
name|methodCount
decl_stmt|,
name|methodData
decl_stmt|;
DECL|member|propertyCount
DECL|member|propertyData
name|int
name|propertyCount
decl_stmt|,
name|propertyData
decl_stmt|;
DECL|member|enumeratorCount
DECL|member|enumeratorData
name|int
name|enumeratorCount
decl_stmt|,
name|enumeratorData
decl_stmt|;
DECL|member|constructorCount
DECL|member|constructorData
name|int
name|constructorCount
decl_stmt|,
name|constructorData
decl_stmt|;
comment|//since revision 2
DECL|member|flags
name|int
name|flags
decl_stmt|;
comment|//since revision 3
DECL|member|signalCount
name|int
name|signalCount
decl_stmt|;
comment|//since revision 4
comment|// revision 5 introduces changes in normalized signatures, no new members
comment|// revision 6 added qt_static_metacall as a member of each Q_OBJECT and inside QMetaObject itself
DECL|function|get
specifier|static
specifier|inline
specifier|const
name|QMetaObjectPrivate
modifier|*
name|get
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
name|metaobject
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|QMetaObjectPrivate
operator|*
operator|>
operator|(
name|metaobject
operator|->
name|d
operator|.
name|data
operator|)
return|;
block|}
specifier|static
name|int
name|indexOfSignalRelative
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
modifier|*
name|baseObject
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|bool
name|normalizeStringData
parameter_list|)
function_decl|;
specifier|static
name|int
name|indexOfSlotRelative
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
modifier|*
name|m
parameter_list|,
specifier|const
name|char
modifier|*
name|slot
parameter_list|,
name|bool
name|normalizeStringData
parameter_list|)
function_decl|;
specifier|static
name|int
name|originalClone
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
name|obj
parameter_list|,
name|int
name|local_method_index
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
comment|//defined in qobject.cpp
DECL|enum|DisconnectType
DECL|enumerator|DisconnectAll
DECL|enumerator|DisconnectOne
enum|enum
name|DisconnectType
block|{
name|DisconnectAll
block|,
name|DisconnectOne
block|}
enum|;
specifier|static
name|void
name|memberIndexes
parameter_list|(
specifier|const
name|QObject
modifier|*
name|obj
parameter_list|,
specifier|const
name|QMetaMethod
modifier|&
name|member
parameter_list|,
name|int
modifier|*
name|signalIndex
parameter_list|,
name|int
modifier|*
name|methodIndex
parameter_list|)
function_decl|;
specifier|static
name|bool
name|connect
parameter_list|(
specifier|const
name|QObject
modifier|*
name|sender
parameter_list|,
name|int
name|signal_index
parameter_list|,
specifier|const
name|QObject
modifier|*
name|receiver
parameter_list|,
name|int
name|method_index_relative
parameter_list|,
specifier|const
name|QMetaObject
modifier|*
name|rmeta
init|=
literal|0
parameter_list|,
name|int
name|type
init|=
literal|0
parameter_list|,
name|int
modifier|*
name|types
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|bool
name|disconnect
parameter_list|(
specifier|const
name|QObject
modifier|*
name|sender
parameter_list|,
name|int
name|signal_index
parameter_list|,
specifier|const
name|QObject
modifier|*
name|receiver
parameter_list|,
name|int
name|method_index
parameter_list|,
name|DisconnectType
init|=
name|DisconnectAll
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|bool
name|disconnectHelper
argument_list|(
name|QObjectPrivate
operator|::
name|Connection
operator|*
name|c
argument_list|,
specifier|const
name|QObject
operator|*
name|receiver
argument_list|,
name|int
name|method_index
argument_list|,
name|QMutex
operator|*
name|senderMutex
argument_list|,
name|DisconnectType
argument_list|)
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct
begin_ifndef
ifndef|#
directive|ifndef
name|UTILS_H
end_ifndef
begin_comment
comment|// mirrored in moc's utils.h
end_comment
begin_function
DECL|function|is_ident_char
specifier|static
specifier|inline
name|bool
name|is_ident_char
parameter_list|(
name|char
name|s
parameter_list|)
block|{
return|return
operator|(
operator|(
name|s
operator|>=
literal|'a'
operator|&&
name|s
operator|<=
literal|'z'
operator|)
operator|||
operator|(
name|s
operator|>=
literal|'A'
operator|&&
name|s
operator|<=
literal|'Z'
operator|)
operator|||
operator|(
name|s
operator|>=
literal|'0'
operator|&&
name|s
operator|<=
literal|'9'
operator|)
operator|||
name|s
operator|==
literal|'_'
operator|)
return|;
block|}
end_function
begin_function
DECL|function|is_space
specifier|static
specifier|inline
name|bool
name|is_space
parameter_list|(
name|char
name|s
parameter_list|)
block|{
return|return
operator|(
name|s
operator|==
literal|' '
operator|||
name|s
operator|==
literal|'\t'
operator|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// This code is shared with moc.cpp
end_comment
begin_function
DECL|function|normalizeTypeInternal
specifier|static
name|QByteArray
name|normalizeTypeInternal
parameter_list|(
specifier|const
name|char
modifier|*
name|t
parameter_list|,
specifier|const
name|char
modifier|*
name|e
parameter_list|,
name|bool
name|fixScope
init|=
name|false
parameter_list|,
name|bool
name|adjustConst
init|=
name|true
parameter_list|)
block|{
name|int
name|len
init|=
name|e
operator|-
name|t
decl_stmt|;
comment|/*       Convert 'char const *' into 'const char *'. Start at index 1,       not 0, because 'const char *' is already OK.     */
name|QByteArray
name|constbuf
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|t
index|[
name|i
index|]
operator|==
literal|'c'
operator|&&
name|strncmp
argument_list|(
name|t
operator|+
name|i
operator|+
literal|1
argument_list|,
literal|"onst"
argument_list|,
literal|4
argument_list|)
operator|==
literal|0
operator|&&
operator|(
name|i
operator|+
literal|5
operator|>=
name|len
operator|||
operator|!
name|is_ident_char
argument_list|(
name|t
index|[
name|i
operator|+
literal|5
index|]
argument_list|)
operator|)
operator|&&
operator|!
name|is_ident_char
argument_list|(
name|t
index|[
name|i
operator|-
literal|1
index|]
argument_list|)
condition|)
block|{
name|constbuf
operator|=
name|QByteArray
argument_list|(
name|t
argument_list|,
name|len
argument_list|)
expr_stmt|;
if|if
condition|(
name|is_space
argument_list|(
name|t
index|[
name|i
operator|-
literal|1
index|]
argument_list|)
condition|)
name|constbuf
operator|.
name|remove
argument_list|(
name|i
operator|-
literal|1
argument_list|,
literal|6
argument_list|)
expr_stmt|;
else|else
name|constbuf
operator|.
name|remove
argument_list|(
name|i
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|constbuf
operator|.
name|prepend
argument_list|(
literal|"const "
argument_list|)
expr_stmt|;
name|t
operator|=
name|constbuf
operator|.
name|data
argument_list|()
expr_stmt|;
name|e
operator|=
name|constbuf
operator|.
name|data
argument_list|()
operator|+
name|constbuf
operator|.
name|length
argument_list|()
expr_stmt|;
break|break;
block|}
comment|/*           We musn't convert 'char * const *' into 'const char **'           and we must beware of 'Bar<const Bla>'.         */
if|if
condition|(
name|t
index|[
name|i
index|]
operator|==
literal|'&'
operator|||
name|t
index|[
name|i
index|]
operator|==
literal|'*'
operator|||
name|t
index|[
name|i
index|]
operator|==
literal|'<'
condition|)
break|break;
block|}
if|if
condition|(
name|adjustConst
operator|&&
name|e
operator|>
name|t
operator|+
literal|6
operator|&&
name|strncmp
argument_list|(
literal|"const "
argument_list|,
name|t
argument_list|,
literal|6
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|*
operator|(
name|e
operator|-
literal|1
operator|)
operator|==
literal|'&'
condition|)
block|{
comment|// treat const reference as value
name|t
operator|+=
literal|6
expr_stmt|;
operator|--
name|e
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|is_ident_char
argument_list|(
operator|*
operator|(
name|e
operator|-
literal|1
operator|)
argument_list|)
operator|||
operator|*
operator|(
name|e
operator|-
literal|1
operator|)
operator|==
literal|'>'
condition|)
block|{
comment|// treat const value as value
name|t
operator|+=
literal|6
expr_stmt|;
block|}
block|}
name|QByteArray
name|result
decl_stmt|;
name|result
operator|.
name|reserve
argument_list|(
name|len
argument_list|)
expr_stmt|;
if|#
directive|if
literal|1
comment|// consume initial 'const '
if|if
condition|(
name|strncmp
argument_list|(
literal|"const "
argument_list|,
name|t
argument_list|,
literal|6
argument_list|)
operator|==
literal|0
condition|)
block|{
name|t
operator|+=
literal|6
expr_stmt|;
name|result
operator|+=
literal|"const "
expr_stmt|;
block|}
endif|#
directive|endif
comment|// some type substitutions for 'unsigned x'
if|if
condition|(
name|strncmp
argument_list|(
literal|"unsigned"
argument_list|,
name|t
argument_list|,
literal|8
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|// make sure "unsigned" is an isolated word before making substitutions
if|if
condition|(
operator|!
name|t
index|[
literal|8
index|]
operator|||
operator|!
name|is_ident_char
argument_list|(
name|t
index|[
literal|8
index|]
argument_list|)
condition|)
block|{
if|if
condition|(
name|strncmp
argument_list|(
literal|" int"
argument_list|,
name|t
operator|+
literal|8
argument_list|,
literal|4
argument_list|)
operator|==
literal|0
condition|)
block|{
name|t
operator|+=
literal|8
operator|+
literal|4
expr_stmt|;
name|result
operator|+=
literal|"uint"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|strncmp
argument_list|(
literal|" long"
argument_list|,
name|t
operator|+
literal|8
argument_list|,
literal|5
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|strlen
argument_list|(
name|t
operator|+
literal|8
operator|+
literal|5
argument_list|)
operator|<
literal|4
operator|||
name|strncmp
argument_list|(
name|t
operator|+
literal|8
operator|+
literal|5
argument_list|,
literal|" int"
argument_list|,
literal|4
argument_list|)
operator|!=
literal|0
operator|)
comment|// preserve '[unsigned] long int'
operator|&&
operator|(
name|strlen
argument_list|(
name|t
operator|+
literal|8
operator|+
literal|5
argument_list|)
operator|<
literal|5
operator|||
name|strncmp
argument_list|(
name|t
operator|+
literal|8
operator|+
literal|5
argument_list|,
literal|" long"
argument_list|,
literal|5
argument_list|)
operator|!=
literal|0
operator|)
comment|// preserve '[unsigned] long long'
condition|)
block|{
name|t
operator|+=
literal|8
operator|+
literal|5
expr_stmt|;
name|result
operator|+=
literal|"ulong"
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|strncmp
argument_list|(
literal|" short"
argument_list|,
name|t
operator|+
literal|8
argument_list|,
literal|6
argument_list|)
operator|!=
literal|0
comment|// preserve unsigned short
operator|&&
name|strncmp
argument_list|(
literal|" char"
argument_list|,
name|t
operator|+
literal|8
argument_list|,
literal|5
argument_list|)
operator|!=
literal|0
condition|)
block|{
comment|// preserve unsigned char
comment|//  treat rest (unsigned) as uint
name|t
operator|+=
literal|8
expr_stmt|;
name|result
operator|+=
literal|"uint"
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
comment|// discard 'struct', 'class', and 'enum'; they are optional
comment|// and we don't want them in the normalized signature
struct|struct
block|{
specifier|const
name|char
modifier|*
name|keyword
decl_stmt|;
name|int
name|len
decl_stmt|;
block|}
name|optional
index|[]
init|=
block|{
block|{
literal|"struct "
block|,
literal|7
block|}
block|,
block|{
literal|"class "
block|,
literal|6
block|}
block|,
block|{
literal|"enum "
block|,
literal|5
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
struct|;
name|int
name|i
init|=
literal|0
decl_stmt|;
do|do
block|{
if|if
condition|(
name|strncmp
argument_list|(
name|optional
index|[
name|i
index|]
operator|.
name|keyword
argument_list|,
name|t
argument_list|,
name|optional
index|[
name|i
index|]
operator|.
name|len
argument_list|)
operator|==
literal|0
condition|)
block|{
name|t
operator|+=
name|optional
index|[
name|i
index|]
operator|.
name|len
expr_stmt|;
break|break;
block|}
block|}
do|while
condition|(
name|optional
index|[
operator|++
name|i
index|]
operator|.
name|keyword
operator|!=
literal|0
condition|)
do|;
block|}
name|bool
name|star
init|=
name|false
decl_stmt|;
while|while
condition|(
name|t
operator|!=
name|e
condition|)
block|{
name|char
name|c
init|=
operator|*
name|t
operator|++
decl_stmt|;
if|if
condition|(
name|fixScope
operator|&&
name|c
operator|==
literal|':'
operator|&&
operator|*
name|t
operator|==
literal|':'
condition|)
block|{
operator|++
name|t
expr_stmt|;
name|c
operator|=
operator|*
name|t
operator|++
expr_stmt|;
name|int
name|i
init|=
name|result
operator|.
name|size
argument_list|()
operator|-
literal|1
decl_stmt|;
while|while
condition|(
name|i
operator|>=
literal|0
operator|&&
name|is_ident_char
argument_list|(
name|result
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
operator|--
name|i
expr_stmt|;
name|result
operator|.
name|resize
argument_list|(
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
name|star
operator|=
name|star
operator|||
name|c
operator|==
literal|'*'
expr_stmt|;
name|result
operator|+=
name|c
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'<'
condition|)
block|{
comment|//template recursion
specifier|const
name|char
modifier|*
name|tt
init|=
name|t
decl_stmt|;
name|int
name|templdepth
init|=
literal|1
decl_stmt|;
while|while
condition|(
name|t
operator|!=
name|e
condition|)
block|{
name|c
operator|=
operator|*
name|t
operator|++
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'<'
condition|)
operator|++
name|templdepth
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'>'
condition|)
operator|--
name|templdepth
expr_stmt|;
if|if
condition|(
name|templdepth
operator|==
literal|0
operator|||
operator|(
name|templdepth
operator|==
literal|1
operator|&&
name|c
operator|==
literal|','
operator|)
condition|)
block|{
name|result
operator|+=
name|normalizeTypeInternal
argument_list|(
name|tt
argument_list|,
name|t
operator|-
literal|1
argument_list|,
name|fixScope
argument_list|,
name|false
argument_list|)
expr_stmt|;
name|result
operator|+=
name|c
expr_stmt|;
if|if
condition|(
name|templdepth
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|*
name|t
operator|==
literal|'>'
condition|)
name|result
operator|+=
literal|' '
expr_stmt|;
comment|// avoid>>
break|break;
block|}
name|tt
operator|=
name|t
expr_stmt|;
block|}
block|}
block|}
comment|// cv qualifers can appear after the type as well
if|if
condition|(
operator|!
name|is_ident_char
argument_list|(
name|c
argument_list|)
operator|&&
name|t
operator|!=
name|e
operator|&&
operator|(
name|e
operator|-
name|t
operator|>=
literal|5
operator|&&
name|strncmp
argument_list|(
literal|"const"
argument_list|,
name|t
argument_list|,
literal|5
argument_list|)
operator|==
literal|0
operator|)
operator|&&
operator|(
name|e
operator|-
name|t
operator|==
literal|5
operator|||
operator|!
name|is_ident_char
argument_list|(
name|t
index|[
literal|5
index|]
argument_list|)
operator|)
condition|)
block|{
name|t
operator|+=
literal|5
expr_stmt|;
while|while
condition|(
name|t
operator|!=
name|e
operator|&&
name|is_space
argument_list|(
operator|*
name|t
argument_list|)
condition|)
operator|++
name|t
expr_stmt|;
if|if
condition|(
name|adjustConst
operator|&&
name|t
operator|!=
name|e
operator|&&
operator|*
name|t
operator|==
literal|'&'
condition|)
block|{
comment|// treat const ref as value
operator|++
name|t
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|adjustConst
operator|&&
operator|!
name|star
condition|)
block|{
comment|// treat const as value
block|}
elseif|else
if|if
condition|(
operator|!
name|star
condition|)
block|{
comment|// move const to the front (but not if const comes after a *)
name|result
operator|.
name|prepend
argument_list|(
literal|"const "
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// keep const after a *
name|result
operator|+=
literal|"const"
expr_stmt|;
block|}
block|}
block|}
return|return
name|result
return|;
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
