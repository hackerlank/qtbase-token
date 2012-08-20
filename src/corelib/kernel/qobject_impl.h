begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|Q_QDOC
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QOBJECT_H
end_ifndef
begin_error
error|#
directive|error
error|Do not include qobject_impl.h directly
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|namespace
name|QtPrivate
block|{
comment|/*         Logic to statically generate the array of qMetaTypeId         ConnectionTypes<FunctionPointer<Signal>::Arguments>::types() returns an array         of int that is suitable for the types arguments of the connection functions.          The array only exist of all the types are declared as a metatype         (detected using the TypesAreDeclaredMetaType helper struct)         If one of the type is not declared, the function return 0 and the signal         cannot be used in queued connection.     */
ifndef|#
directive|ifndef
name|Q_COMPILER_VARIADIC_TEMPLATES
name|template
operator|<
name|typename
name|ArgList
operator|>
expr|struct
name|TypesAreDeclaredMetaType
block|{ enum
block|{
name|Value
operator|=
name|false
block|}
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|TypesAreDeclaredMetaType
operator|<
name|void
operator|>
block|{ enum
block|{
name|Value
operator|=
name|true
block|}
block|; }
expr_stmt|;
name|template
operator|<
name|typename
name|Arg
operator|,
name|typename
name|Tail
operator|>
expr|struct
name|TypesAreDeclaredMetaType
operator|<
name|List
operator|<
name|Arg
operator|,
name|Tail
operator|>
expr|>
block|{ enum
block|{
name|Value
operator|=
name|QMetaTypeId2
operator|<
name|Arg
operator|>
operator|::
name|Defined
operator|&&
name|TypesAreDeclaredMetaType
operator|<
name|Tail
operator|>
operator|::
name|Value
block|}
block|; }
expr_stmt|;
name|template
operator|<
name|typename
name|ArgList
operator|,
name|bool
name|Declared
operator|=
name|TypesAreDeclaredMetaType
operator|<
name|ArgList
operator|>
operator|::
name|Value
operator|>
expr|struct
name|ConnectionTypes
block|{
specifier|static
specifier|const
name|int
operator|*
name|types
argument_list|()
block|{
return|return
literal|0
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|ConnectionTypes
operator|<
name|void
block|,
name|true
operator|>
block|{
specifier|static
specifier|const
name|int
operator|*
name|types
argument_list|()
block|{
specifier|static
specifier|const
name|int
name|t
index|[
literal|1
index|]
operator|=
block|{
literal|0
block|}
block|;
return|return
name|t
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|Arg1
operator|>
expr|struct
name|ConnectionTypes
operator|<
name|List
operator|<
name|Arg1
block|,
name|void
operator|>
block|,
name|true
operator|>
block|{
specifier|static
specifier|const
name|int
operator|*
name|types
argument_list|()
block|{
specifier|static
specifier|const
name|int
name|t
index|[
literal|2
index|]
operator|=
block|{
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg1
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
literal|0
block|}
block|;
return|return
name|t
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|Arg1
block|,
name|typename
name|Arg2
operator|>
expr|struct
name|ConnectionTypes
operator|<
name|List
operator|<
name|Arg1
block|,
name|List
operator|<
name|Arg2
block|,
name|void
operator|>
expr|>
block|,
name|true
operator|>
block|{
specifier|static
specifier|const
name|int
operator|*
name|types
argument_list|()
block|{
specifier|static
specifier|const
name|int
name|t
index|[
literal|3
index|]
operator|=
block|{
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg1
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg2
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
literal|0
block|}
block|;
return|return
name|t
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|Arg1
block|,
name|typename
name|Arg2
block|,
name|typename
name|Arg3
operator|>
expr|struct
name|ConnectionTypes
operator|<
name|List
operator|<
name|Arg1
block|,
name|List
operator|<
name|Arg2
block|,
name|List
operator|<
name|Arg3
block|,
name|void
operator|>
expr|>
operator|>
block|,
name|true
operator|>
block|{
specifier|static
specifier|const
name|int
operator|*
name|types
argument_list|()
block|{
specifier|static
specifier|const
name|int
name|t
index|[
literal|4
index|]
operator|=
block|{
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg1
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg2
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg3
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
literal|0
block|}
block|;
return|return
name|t
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|Arg1
block|,
name|typename
name|Arg2
block|,
name|typename
name|Arg3
block|,
name|typename
name|Arg4
operator|>
expr|struct
name|ConnectionTypes
operator|<
name|List
operator|<
name|Arg1
block|,
name|List
operator|<
name|Arg2
block|,
name|List
operator|<
name|Arg3
block|,
name|List
operator|<
name|Arg4
block|,
name|void
operator|>
expr|>
operator|>
expr|>
block|,
name|true
operator|>
block|{
specifier|static
specifier|const
name|int
operator|*
name|types
argument_list|()
block|{
specifier|static
specifier|const
name|int
name|t
index|[
literal|4
index|]
operator|=
block|{
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg1
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg2
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg3
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg4
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
literal|0
block|}
block|;
return|return
name|t
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|Arg1
block|,
name|typename
name|Arg2
block|,
name|typename
name|Arg3
block|,
name|typename
name|Arg4
block|,
name|typename
name|Arg5
operator|>
expr|struct
name|ConnectionTypes
operator|<
name|List
operator|<
name|Arg1
block|,
name|List
operator|<
name|Arg2
block|,
name|List
operator|<
name|Arg3
block|,
name|List
operator|<
name|Arg4
block|,
name|List
operator|<
name|Arg5
block|,
name|void
operator|>
expr|>
operator|>
expr|>
operator|>
block|,
name|true
operator|>
block|{
specifier|static
specifier|const
name|int
operator|*
name|types
argument_list|()
block|{
specifier|static
specifier|const
name|int
name|t
index|[
literal|4
index|]
operator|=
block|{
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg1
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg2
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg3
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg4
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg5
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
literal|0
block|}
block|;
return|return
name|t
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|Arg1
block|,
name|typename
name|Arg2
block|,
name|typename
name|Arg3
block|,
name|typename
name|Arg4
block|,
name|typename
name|Arg5
block|,
name|typename
name|Arg6
operator|>
expr|struct
name|ConnectionTypes
operator|<
name|List
operator|<
name|Arg1
block|,
name|List
operator|<
name|Arg2
block|,
name|List
operator|<
name|Arg3
block|,
name|List
operator|<
name|Arg4
block|,
name|List
operator|<
name|Arg5
block|,
name|List
operator|<
name|Arg6
block|,
name|void
operator|>
expr|>
operator|>
expr|>
operator|>
expr|>
block|,
name|true
operator|>
block|{
specifier|static
specifier|const
name|int
operator|*
name|types
argument_list|()
block|{
specifier|static
specifier|const
name|int
name|t
index|[
literal|4
index|]
operator|=
block|{
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg1
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg2
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg3
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg4
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg5
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Arg6
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|,
literal|0
block|}
block|;
return|return
name|t
return|;
block|}
expr|}
block|;
else|#
directive|else
name|template
operator|<
name|typename
name|ArgList
operator|>
expr|struct
name|TypesAreDeclaredMetaType
block|{ enum
block|{
name|Value
operator|=
name|false
block|}
block|; }
block|;
name|template
operator|<
operator|>
expr|struct
name|TypesAreDeclaredMetaType
operator|<
name|List
operator|<
operator|>>
block|{ enum
block|{
name|Value
operator|=
name|true
block|}
block|; }
block|;
name|template
operator|<
name|typename
name|Arg
block|,
name|typename
operator|...
name|Tail
operator|>
expr|struct
name|TypesAreDeclaredMetaType
operator|<
name|List
operator|<
name|Arg
block|,
name|Tail
operator|...
operator|>
expr|>
block|{ enum
block|{
name|Value
operator|=
name|QMetaTypeId2
operator|<
name|Arg
operator|>
operator|::
name|Defined
operator|&&
name|TypesAreDeclaredMetaType
operator|<
name|List
operator|<
name|Tail
operator|...
operator|>>
operator|::
name|Value
block|}
block|; }
block|;
name|template
operator|<
name|typename
name|ArgList
block|,
name|bool
name|Declared
operator|=
name|TypesAreDeclaredMetaType
operator|<
name|ArgList
operator|>
operator|::
name|Value
operator|>
expr|struct
name|ConnectionTypes
block|{
specifier|static
specifier|const
name|int
operator|*
name|types
argument_list|()
block|{
return|return
literal|0
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
operator|...
name|Args
operator|>
expr|struct
name|ConnectionTypes
operator|<
name|List
operator|<
name|Args
operator|...
operator|>
block|,
name|true
operator|>
block|{
specifier|static
specifier|const
name|int
operator|*
name|types
argument_list|()
block|{
specifier|static
specifier|const
name|int
name|t
index|[
sizeof|sizeof...
argument_list|(
name|Args
argument_list|)
operator|+
literal|1
index|]
operator|=
block|{
operator|(
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|Args
operator|>
operator|::
name|qt_metatype_id
argument_list|()
operator|)
operator|...
block|,
literal|0
block|}
block|;
return|return
name|t
return|;
block|}
expr|}
block|;
endif|#
directive|endif
comment|// internal base class (interface) containing functions required to call a slot managed by a pointer to function.
name|class
name|QSlotObjectBase
block|{
name|QAtomicInt
name|m_ref
block|;
comment|// don't use virtual functions here; we don't want the
comment|// compiler to create tons of per-polymorphic-class stuff that
comment|// we'll never need. We just use one function pointer.
typedef|typedef
name|void
function_decl|(
modifier|*
name|ImplFn
function_decl|)
parameter_list|(
name|int
name|which
parameter_list|,
name|QSlotObjectBase
modifier|*
name|this_
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
name|void
modifier|*
modifier|*
name|args
parameter_list|,
name|bool
modifier|*
name|ret
parameter_list|)
function_decl|;
specifier|const
name|ImplFn
name|m_impl
block|;
name|protected
operator|:
expr|enum
name|Operation
block|{
name|Destroy
block|,
name|Call
block|,
name|Compare
block|,
name|NumOperations
block|}
block|;
name|public
operator|:
name|explicit
name|QSlotObjectBase
argument_list|(
argument|ImplFn fn
argument_list|)
operator|:
name|m_ref
argument_list|(
literal|1
argument_list|)
block|,
name|m_impl
argument_list|(
argument|fn
argument_list|)
block|{}
specifier|inline
name|int
name|ref
argument_list|()
name|Q_DECL_NOTHROW
block|{
return|return
name|m_ref
operator|.
name|ref
argument_list|()
return|;
block|}
specifier|inline
name|void
name|destroyIfLastRef
argument_list|()
name|Q_DECL_NOTHROW
block|{
if|if
condition|(
operator|!
name|m_ref
operator|.
name|deref
argument_list|()
condition|)
name|m_impl
argument_list|(
name|Destroy
argument_list|,
name|this
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|bool
name|compare
argument_list|(
argument|void **a
argument_list|)
block|{
name|bool
name|ret
block|;
name|m_impl
argument_list|(
name|Compare
argument_list|,
name|this
argument_list|,
literal|0
argument_list|,
name|a
argument_list|,
operator|&
name|ret
argument_list|)
block|;
return|return
name|ret
return|;
block|}
specifier|inline
name|void
name|call
argument_list|(
argument|QObject *r
argument_list|,
argument|void **a
argument_list|)
block|{
name|m_impl
argument_list|(
name|Call
argument_list|,
name|this
argument_list|,
name|r
argument_list|,
name|a
argument_list|,
literal|0
argument_list|)
block|; }
name|protected
operator|:
operator|~
name|QSlotObjectBase
argument_list|()
block|{}
expr|}
block|;
comment|// implementation of QSlotObjectBase for which the slot is a pointer to member function of a QObject
comment|// Args and R are the List of arguments and the returntype of the signal to which the slot is connected.
name|template
operator|<
name|typename
name|Func
block|,
name|typename
name|Args
block|,
name|typename
name|R
operator|>
name|class
name|QSlotObject
operator|:
name|public
name|QSlotObjectBase
block|{
typedef|typedef
name|QtPrivate
operator|::
name|FunctionPointer
operator|<
name|Func
operator|>
name|FuncType
expr_stmt|;
name|Func
name|function
block|;
specifier|static
name|void
name|impl
argument_list|(
argument|int which
argument_list|,
argument|QSlotObjectBase *this_
argument_list|,
argument|QObject *r
argument_list|,
argument|void **a
argument_list|,
argument|bool *ret
argument_list|)
block|{
switch|switch
condition|(
name|which
condition|)
block|{
case|case
name|Destroy
case|:
name|delete
name|static_cast
operator|<
name|QSlotObject
operator|*
operator|>
operator|(
name|this_
operator|)
expr_stmt|;
break|break;
case|case
name|Call
case|:
name|FuncType
operator|::
name|template
name|call
operator|<
name|Args
operator|,
name|R
operator|>
operator|(
name|static_cast
operator|<
name|QSlotObject
operator|*
operator|>
operator|(
name|this_
operator|)
operator|->
name|function
operator|,
name|static_cast
operator|<
name|typename
name|FuncType
operator|::
name|Object
operator|*
operator|>
operator|(
name|r
operator|)
operator|,
name|a
operator|)
expr_stmt|;
break|break;
case|case
name|Compare
case|:
operator|*
name|ret
operator|=
operator|*
name|reinterpret_cast
operator|<
name|Func
operator|*
operator|>
operator|(
name|a
operator|)
operator|==
name|static_cast
operator|<
name|QSlotObject
operator|*
operator|>
operator|(
name|this_
operator|)
operator|->
name|function
expr_stmt|;
break|break;
case|case
name|NumOperations
case|:
empty_stmt|;
block|}
block|}
name|public
operator|:
name|explicit
name|QSlotObject
argument_list|(
argument|Func f
argument_list|)
operator|:
name|QSlotObjectBase
argument_list|(
operator|&
name|impl
argument_list|)
block|,
name|function
argument_list|(
argument|f
argument_list|)
block|{}
block|}
block|;
comment|// implementation of QSlotObjectBase for which the slot is a static function
comment|// Args and R are the List of arguments and the returntype of the signal to which the slot is connected.
name|template
operator|<
name|typename
name|Func
block|,
name|typename
name|Args
block|,
name|typename
name|R
operator|>
name|class
name|QStaticSlotObject
operator|:
name|public
name|QSlotObjectBase
block|{
typedef|typedef
name|QtPrivate
operator|::
name|FunctionPointer
operator|<
name|Func
operator|>
name|FuncType
expr_stmt|;
name|Func
name|function
block|;
specifier|static
name|void
name|impl
argument_list|(
argument|int which
argument_list|,
argument|QSlotObjectBase *this_
argument_list|,
argument|QObject *r
argument_list|,
argument|void **a
argument_list|,
argument|bool *ret
argument_list|)
block|{
switch|switch
condition|(
name|which
condition|)
block|{
case|case
name|Destroy
case|:
name|delete
name|static_cast
operator|<
name|QStaticSlotObject
operator|*
operator|>
operator|(
name|this_
operator|)
expr_stmt|;
break|break;
case|case
name|Call
case|:
name|FuncType
operator|::
name|template
name|call
operator|<
name|Args
operator|,
name|R
operator|>
operator|(
name|static_cast
operator|<
name|QStaticSlotObject
operator|*
operator|>
operator|(
name|this_
operator|)
operator|->
name|function
operator|,
name|r
operator|,
name|a
operator|)
expr_stmt|;
break|break;
case|case
name|Compare
case|:
operator|*
name|ret
operator|=
name|false
expr_stmt|;
comment|// not implemented
break|break;
case|case
name|NumOperations
case|:
empty_stmt|;
block|}
block|}
name|public
operator|:
name|explicit
name|QStaticSlotObject
argument_list|(
argument|Func f
argument_list|)
operator|:
name|QSlotObjectBase
argument_list|(
operator|&
name|impl
argument_list|)
block|,
name|function
argument_list|(
argument|f
argument_list|)
block|{}
block|}
block|;
comment|// implementation of QSlotObjectBase for which the slot is a functor (or lambda)
comment|// N is the number of arguments
comment|// Args and R are the List of arguments and the returntype of the signal to which the slot is connected.
name|template
operator|<
name|typename
name|Func
block|,
name|int
name|N
block|,
name|typename
name|Args
block|,
name|typename
name|R
operator|>
name|class
name|QFunctorSlotObject
operator|:
name|public
name|QSlotObjectBase
block|{
typedef|typedef
name|QtPrivate
operator|::
name|Functor
operator|<
name|Func
operator|,
name|N
operator|>
name|FuncType
expr_stmt|;
name|Func
name|function
block|;
specifier|static
name|void
name|impl
argument_list|(
argument|int which
argument_list|,
argument|QSlotObjectBase *this_
argument_list|,
argument|QObject *r
argument_list|,
argument|void **a
argument_list|,
argument|bool *ret
argument_list|)
block|{
switch|switch
condition|(
name|which
condition|)
block|{
case|case
name|Destroy
case|:
name|delete
name|static_cast
operator|<
name|QFunctorSlotObject
operator|*
operator|>
operator|(
name|this_
operator|)
expr_stmt|;
break|break;
case|case
name|Call
case|:
name|FuncType
operator|::
name|template
name|call
operator|<
name|Args
operator|,
name|R
operator|>
operator|(
name|static_cast
operator|<
name|QFunctorSlotObject
operator|*
operator|>
operator|(
name|this_
operator|)
operator|->
name|function
operator|,
name|r
operator|,
name|a
operator|)
expr_stmt|;
break|break;
case|case
name|Compare
case|:
operator|*
name|ret
operator|=
name|false
expr_stmt|;
comment|// not implemented
break|break;
case|case
name|NumOperations
case|:
empty_stmt|;
block|}
block|}
name|public
operator|:
name|explicit
name|QFunctorSlotObject
argument_list|(
specifier|const
name|Func
operator|&
name|f
argument_list|)
operator|:
name|QSlotObjectBase
argument_list|(
operator|&
name|impl
argument_list|)
block|,
name|function
argument_list|(
argument|f
argument_list|)
block|{}
block|}
block|;  }
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
