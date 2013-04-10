begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2010 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_SYMBOL_TABLE_INCLUDED_
end_ifndef
begin_define
DECL|macro|_SYMBOL_TABLE_INCLUDED_
define|#
directive|define
name|_SYMBOL_TABLE_INCLUDED_
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|// Symbol table for parsing.  Has these design characteristics:
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// * Same symbol table can be used to compile many shaders, to preserve
end_comment
begin_comment
comment|//   effort of creating and loading with the large numbers of built-in
end_comment
begin_comment
comment|//   symbols.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// * Name mangling will be used to give each function a unique name
end_comment
begin_comment
comment|//   so that symbol table lookups are never ambiguous.  This allows
end_comment
begin_comment
comment|//   a simpler symbol table structure.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// * Pushing and popping of scope, so symbol table will really be a stack
end_comment
begin_comment
comment|//   of symbol tables.  Searched from the top, with new inserts going into
end_comment
begin_comment
comment|//   the top.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// * Constants:  Compile time constant symbols will keep their values
end_comment
begin_comment
comment|//   in the symbol table.  The parser can substitute constants at parse
end_comment
begin_comment
comment|//   time, including doing constant folding and constant propagation.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// * No temporaries:  Temporaries made from operations (+, --, .xy, etc.)
end_comment
begin_comment
comment|//   are tracked in the intermediate representation, not the symbol table.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<assert.h>
end_include
begin_include
include|#
directive|include
file|"compiler/InfoSink.h"
end_include
begin_include
include|#
directive|include
file|"compiler/intermediate.h"
end_include
begin_comment
comment|//
end_comment
begin_comment
comment|// Symbol base class.  (Can build functions or variables out of these...)
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|TSymbol
block|{
name|public
label|:
name|POOL_ALLOCATOR_NEW_DELETE
argument_list|(
argument|GlobalPoolAllocator
argument_list|)
name|TSymbol
argument_list|(
specifier|const
name|TString
operator|*
name|n
argument_list|)
operator|:
name|name
argument_list|(
argument|n
argument_list|)
block|{ }
name|virtual
operator|~
name|TSymbol
argument_list|()
block|{
comment|/* don't delete name, it's from the pool */
block|}
specifier|const
name|TString
operator|&
name|getName
argument_list|()
specifier|const
block|{
return|return
operator|*
name|name
return|;
block|}
name|virtual
specifier|const
name|TString
operator|&
name|getMangledName
argument_list|()
specifier|const
block|{
return|return
name|getName
argument_list|()
return|;
block|}
name|virtual
name|bool
name|isFunction
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isVariable
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|void
name|setUniqueId
parameter_list|(
name|int
name|id
parameter_list|)
block|{
name|uniqueId
operator|=
name|id
expr_stmt|;
block|}
name|int
name|getUniqueId
argument_list|()
specifier|const
block|{
return|return
name|uniqueId
return|;
block|}
name|virtual
name|void
name|dump
argument_list|(
name|TInfoSink
operator|&
name|infoSink
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|TSymbol
argument_list|(
specifier|const
name|TSymbol
operator|&
argument_list|)
expr_stmt|;
name|virtual
name|TSymbol
modifier|*
name|clone
parameter_list|(
name|TStructureMap
modifier|&
name|remapper
parameter_list|)
init|=
literal|0
function_decl|;
name|protected
label|:
specifier|const
name|TString
modifier|*
name|name
decl_stmt|;
name|unsigned
name|int
name|uniqueId
decl_stmt|;
comment|// For real comparing during code generation
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// Variable class, meaning a symbol that's not a function.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// There could be a separate class heirarchy for Constant variables;
end_comment
begin_comment
comment|// Only one of int, bool, or float, (or none) is correct for
end_comment
begin_comment
comment|// any particular use, but it's easy to do this way, and doesn't
end_comment
begin_comment
comment|// seem worth having separate classes, and "getConst" can't simply return
end_comment
begin_comment
comment|// different values for different types polymorphically, so this is
end_comment
begin_comment
comment|// just simple and pragmatic.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|TVariable
range|:
name|public
name|TSymbol
block|{
name|public
operator|:
name|TVariable
argument_list|(
argument|const TString *name
argument_list|,
argument|const TType& t
argument_list|,
argument|bool uT = false
argument_list|)
operator|:
name|TSymbol
argument_list|(
name|name
argument_list|)
block|,
name|type
argument_list|(
name|t
argument_list|)
block|,
name|userType
argument_list|(
name|uT
argument_list|)
block|,
name|unionArray
argument_list|(
literal|0
argument_list|)
block|,
name|arrayInformationType
argument_list|(
literal|0
argument_list|)
block|{ }
name|virtual
operator|~
name|TVariable
argument_list|()
block|{ }
name|virtual
name|bool
name|isVariable
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|TType
operator|&
name|getType
argument_list|()
block|{
return|return
name|type
return|;
block|}
specifier|const
name|TType
operator|&
name|getType
argument_list|()
specifier|const
block|{
return|return
name|type
return|;
block|}
name|bool
name|isUserType
argument_list|()
specifier|const
block|{
return|return
name|userType
return|;
block|}
name|void
name|setQualifier
argument_list|(
argument|TQualifier qualifier
argument_list|)
block|{
name|type
operator|.
name|setQualifier
argument_list|(
name|qualifier
argument_list|)
block|; }
name|void
name|updateArrayInformationType
argument_list|(
argument|TType *t
argument_list|)
block|{
name|arrayInformationType
operator|=
name|t
block|; }
name|TType
operator|*
name|getArrayInformationType
argument_list|()
block|{
return|return
name|arrayInformationType
return|;
block|}
name|virtual
name|void
name|dump
argument_list|(
argument|TInfoSink&infoSink
argument_list|)
specifier|const
block|;
name|ConstantUnion
operator|*
name|getConstPointer
argument_list|()
block|{
if|if
condition|(
operator|!
name|unionArray
condition|)
name|unionArray
operator|=
name|new
name|ConstantUnion
index|[
name|type
operator|.
name|getObjectSize
argument_list|()
index|]
expr_stmt|;
return|return
name|unionArray
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|ConstantUnion
operator|*
name|getConstPointer
argument_list|()
specifier|const
block|{
return|return
name|unionArray
return|;
block|}
end_expr_stmt
begin_function
name|void
name|shareConstPointer
parameter_list|(
name|ConstantUnion
modifier|*
name|constArray
parameter_list|)
block|{
if|if
condition|(
name|unionArray
operator|==
name|constArray
condition|)
return|return;
name|delete
index|[]
name|unionArray
decl_stmt|;
name|unionArray
operator|=
name|constArray
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|TVariable
argument_list|(
specifier|const
name|TVariable
operator|&
argument_list|,
name|TStructureMap
operator|&
name|remapper
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// copy constructor
end_comment
begin_function_decl
name|virtual
name|TVariable
modifier|*
name|clone
parameter_list|(
name|TStructureMap
modifier|&
name|remapper
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|protected
label|:
end_label
begin_decl_stmt
name|TType
name|type
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|userType
decl_stmt|;
end_decl_stmt
begin_comment
comment|// we are assuming that Pool Allocator will free the memory allocated to unionArray
end_comment
begin_comment
comment|// when this object is destroyed
end_comment
begin_decl_stmt
name|ConstantUnion
modifier|*
name|unionArray
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TType
modifier|*
name|arrayInformationType
decl_stmt|;
end_decl_stmt
begin_comment
comment|// this is used for updating maxArraySize in all the references to a given symbol
end_comment
begin_comment
unit|};
comment|//
end_comment
begin_comment
comment|// The function sub-class of symbols and the parser will need to
end_comment
begin_comment
comment|// share this definition of a function parameter.
end_comment
begin_comment
comment|//
end_comment
begin_struct
DECL|struct|TParameter
struct|struct
name|TParameter
block|{
DECL|member|name
name|TString
modifier|*
name|name
decl_stmt|;
DECL|member|type
name|TType
modifier|*
name|type
decl_stmt|;
DECL|function|copyParam
name|void
name|copyParam
parameter_list|(
specifier|const
name|TParameter
modifier|&
name|param
parameter_list|,
name|TStructureMap
modifier|&
name|remapper
parameter_list|)
block|{
name|name
operator|=
name|NewPoolTString
argument_list|(
name|param
operator|.
name|name
operator|->
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
name|type
operator|=
name|param
operator|.
name|type
operator|->
name|clone
argument_list|(
name|remapper
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
end_struct
begin_comment
comment|//
end_comment
begin_comment
comment|// The function sub-class of a symbol.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|TFunction
range|:
name|public
name|TSymbol
block|{
name|public
operator|:
name|TFunction
argument_list|(
argument|TOperator o
argument_list|)
operator|:
name|TSymbol
argument_list|(
literal|0
argument_list|)
block|,
name|returnType
argument_list|(
name|TType
argument_list|(
name|EbtVoid
argument_list|,
name|EbpUndefined
argument_list|)
argument_list|)
block|,
name|op
argument_list|(
name|o
argument_list|)
block|,
name|defined
argument_list|(
argument|false
argument_list|)
block|{ }
name|TFunction
argument_list|(
argument|const TString *name
argument_list|,
argument|TType& retType
argument_list|,
argument|TOperator tOp = EOpNull
argument_list|)
operator|:
name|TSymbol
argument_list|(
name|name
argument_list|)
block|,
name|returnType
argument_list|(
name|retType
argument_list|)
block|,
name|mangledName
argument_list|(
name|TFunction
operator|::
name|mangleName
argument_list|(
operator|*
name|name
argument_list|)
argument_list|)
block|,
name|op
argument_list|(
name|tOp
argument_list|)
block|,
name|defined
argument_list|(
argument|false
argument_list|)
block|{ }
name|virtual
operator|~
name|TFunction
argument_list|()
block|;
name|virtual
name|bool
name|isFunction
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
specifier|static
name|TString
name|mangleName
argument_list|(
argument|const TString& name
argument_list|)
block|{
return|return
name|name
operator|+
literal|'('
return|;
block|}
specifier|static
name|TString
name|unmangleName
argument_list|(
argument|const TString& mangledName
argument_list|)
block|{
return|return
name|TString
argument_list|(
name|mangledName
operator|.
name|c_str
argument_list|()
argument_list|,
name|mangledName
operator|.
name|find_first_of
argument_list|(
literal|'('
argument_list|)
argument_list|)
return|;
block|}
name|void
name|addParameter
argument_list|(
argument|TParameter& p
argument_list|)
block|{
name|parameters
operator|.
name|push_back
argument_list|(
name|p
argument_list|)
block|;
name|mangledName
operator|=
name|mangledName
operator|+
name|p
operator|.
name|type
operator|->
name|getMangledName
argument_list|()
block|;     }
specifier|const
name|TString
operator|&
name|getMangledName
argument_list|()
specifier|const
block|{
return|return
name|mangledName
return|;
block|}
specifier|const
name|TType
operator|&
name|getReturnType
argument_list|()
specifier|const
block|{
return|return
name|returnType
return|;
block|}
name|void
name|relateToOperator
argument_list|(
argument|TOperator o
argument_list|)
block|{
name|op
operator|=
name|o
block|; }
name|TOperator
name|getBuiltInOp
argument_list|()
specifier|const
block|{
return|return
name|op
return|;
block|}
name|void
name|relateToExtension
argument_list|(
argument|const TString& ext
argument_list|)
block|{
name|extension
operator|=
name|ext
block|; }
specifier|const
name|TString
operator|&
name|getExtension
argument_list|()
specifier|const
block|{
return|return
name|extension
return|;
block|}
name|void
name|setDefined
argument_list|()
block|{
name|defined
operator|=
name|true
block|; }
name|bool
name|isDefined
argument_list|()
block|{
return|return
name|defined
return|;
block|}
name|size_t
name|getParamCount
argument_list|()
specifier|const
block|{
return|return
name|parameters
operator|.
name|size
argument_list|()
return|;
block|}
specifier|const
name|TParameter
operator|&
name|getParam
argument_list|(
argument|size_t i
argument_list|)
specifier|const
block|{
return|return
name|parameters
index|[
name|i
index|]
return|;
block|}
name|virtual
name|void
name|dump
argument_list|(
argument|TInfoSink&infoSink
argument_list|)
specifier|const
block|;
name|TFunction
argument_list|(
specifier|const
name|TFunction
operator|&
argument_list|,
name|TStructureMap
operator|&
name|remapper
argument_list|)
block|;
name|virtual
name|TFunction
operator|*
name|clone
argument_list|(
name|TStructureMap
operator|&
name|remapper
argument_list|)
block|;
name|protected
operator|:
typedef|typedef
name|TVector
operator|<
name|TParameter
operator|>
name|TParamList
expr_stmt|;
name|TParamList
name|parameters
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TType
name|returnType
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TString
name|mangledName
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TOperator
name|op
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TString
name|extension
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|defined
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|TSymbolTableLevel
block|{
name|public
label|:
typedef|typedef
name|TMap
operator|<
name|TString
operator|,
name|TSymbol
operator|*
operator|>
name|tLevel
expr_stmt|;
typedef|typedef
name|tLevel
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
typedef|typedef
specifier|const
name|tLevel
operator|::
name|value_type
name|tLevelPair
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|tLevel
operator|::
name|iterator
operator|,
name|bool
operator|>
name|tInsertResult
expr_stmt|;
name|POOL_ALLOCATOR_NEW_DELETE
argument_list|(
argument|GlobalPoolAllocator
argument_list|)
name|TSymbolTableLevel
argument_list|()
block|{ }
operator|~
name|TSymbolTableLevel
argument_list|()
expr_stmt|;
name|bool
name|insert
parameter_list|(
name|TSymbol
modifier|&
name|symbol
parameter_list|)
block|{
comment|//
comment|// returning true means symbol was added to the table
comment|//
name|tInsertResult
name|result
decl_stmt|;
name|result
operator|=
name|level
operator|.
name|insert
argument_list|(
name|tLevelPair
argument_list|(
name|symbol
operator|.
name|getMangledName
argument_list|()
argument_list|,
operator|&
name|symbol
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|result
operator|.
name|second
return|;
block|}
name|TSymbol
modifier|*
name|find
argument_list|(
specifier|const
name|TString
operator|&
name|name
argument_list|)
decl|const
block|{
name|tLevel
operator|::
name|const_iterator
name|it
operator|=
name|level
operator|.
name|find
argument_list|(
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|it
operator|==
name|level
operator|.
name|end
argument_list|()
condition|)
return|return
literal|0
return|;
else|else
return|return
operator|(
operator|*
name|it
operator|)
operator|.
name|second
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|level
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|level
operator|.
name|end
argument_list|()
return|;
block|}
name|void
name|relateToOperator
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|TOperator
name|op
parameter_list|)
function_decl|;
name|void
name|relateToExtension
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|TString
modifier|&
name|ext
parameter_list|)
function_decl|;
name|void
name|dump
argument_list|(
name|TInfoSink
operator|&
name|infoSink
argument_list|)
decl|const
decl_stmt|;
name|TSymbolTableLevel
modifier|*
name|clone
parameter_list|(
name|TStructureMap
modifier|&
name|remapper
parameter_list|)
function_decl|;
name|protected
label|:
name|tLevel
name|level
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|TSymbolTable
block|{
name|public
label|:
name|TSymbolTable
argument_list|()
operator|:
name|uniqueId
argument_list|(
literal|0
argument_list|)
block|{
comment|//
comment|// The symbol table cannot be used until push() is called, but
comment|// the lack of an initial call to push() can be used to detect
comment|// that the symbol table has not been preloaded with built-ins.
comment|//
block|}
operator|~
name|TSymbolTable
argument_list|()
block|{
comment|// level 0 is always built In symbols, so we never pop that out
while|while
condition|(
name|table
operator|.
name|size
argument_list|()
operator|>
literal|1
condition|)
name|pop
argument_list|()
expr_stmt|;
block|}
comment|//
comment|// When the symbol table is initialized with the built-ins, there should
comment|// 'push' calls, so that built-ins are at level 0 and the shader
comment|// globals are at level 1.
comment|//
name|bool
name|isEmpty
parameter_list|()
block|{
return|return
name|table
operator|.
name|size
argument_list|()
operator|==
literal|0
return|;
block|}
name|bool
name|atBuiltInLevel
parameter_list|()
block|{
return|return
name|table
operator|.
name|size
argument_list|()
operator|==
literal|1
return|;
block|}
name|bool
name|atGlobalLevel
parameter_list|()
block|{
return|return
name|table
operator|.
name|size
argument_list|()
operator|<=
literal|2
return|;
block|}
name|void
name|push
parameter_list|()
block|{
name|table
operator|.
name|push_back
argument_list|(
argument|new TSymbolTableLevel
argument_list|)
expr_stmt|;
name|precisionStack
operator|.
name|push_back
argument_list|(
name|PrecisionStackLevel
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|void
name|pop
parameter_list|()
block|{
name|delete
name|table
index|[
name|currentLevel
argument_list|()
index|]
decl_stmt|;
name|table
operator|.
name|pop_back
argument_list|()
expr_stmt|;
name|precisionStack
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
name|bool
name|insert
parameter_list|(
name|TSymbol
modifier|&
name|symbol
parameter_list|)
block|{
name|symbol
operator|.
name|setUniqueId
argument_list|(
operator|++
name|uniqueId
argument_list|)
expr_stmt|;
return|return
name|table
index|[
name|currentLevel
argument_list|()
index|]
operator|->
name|insert
argument_list|(
name|symbol
argument_list|)
return|;
block|}
name|TSymbol
modifier|*
name|find
parameter_list|(
specifier|const
name|TString
modifier|&
name|name
parameter_list|,
name|bool
modifier|*
name|builtIn
init|=
literal|0
parameter_list|,
name|bool
modifier|*
name|sameScope
init|=
literal|0
parameter_list|)
block|{
name|int
name|level
init|=
name|currentLevel
argument_list|()
decl_stmt|;
name|TSymbol
modifier|*
name|symbol
decl_stmt|;
do|do
block|{
name|symbol
operator|=
name|table
index|[
name|level
index|]
operator|->
name|find
argument_list|(
name|name
argument_list|)
expr_stmt|;
operator|--
name|level
expr_stmt|;
block|}
do|while
condition|(
name|symbol
operator|==
literal|0
operator|&&
name|level
operator|>=
literal|0
condition|)
do|;
name|level
operator|++
expr_stmt|;
if|if
condition|(
name|builtIn
condition|)
operator|*
name|builtIn
operator|=
name|level
operator|==
literal|0
expr_stmt|;
if|if
condition|(
name|sameScope
condition|)
operator|*
name|sameScope
operator|=
name|level
operator|==
name|currentLevel
argument_list|()
expr_stmt|;
return|return
name|symbol
return|;
block|}
name|TSymbol
modifier|*
name|findBuiltIn
parameter_list|(
specifier|const
name|TString
modifier|&
name|name
parameter_list|)
block|{
return|return
name|table
index|[
literal|0
index|]
operator|->
name|find
argument_list|(
name|name
argument_list|)
return|;
block|}
name|TSymbolTableLevel
modifier|*
name|getGlobalLevel
parameter_list|()
block|{
name|assert
argument_list|(
name|table
operator|.
name|size
argument_list|()
operator|>=
literal|2
argument_list|)
expr_stmt|;
return|return
name|table
index|[
literal|1
index|]
return|;
block|}
name|TSymbolTableLevel
modifier|*
name|getOuterLevel
parameter_list|()
block|{
name|assert
argument_list|(
name|table
operator|.
name|size
argument_list|()
operator|>=
literal|2
argument_list|)
expr_stmt|;
return|return
name|table
index|[
name|currentLevel
argument_list|()
operator|-
literal|1
index|]
return|;
block|}
name|void
name|relateToOperator
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|TOperator
name|op
parameter_list|)
block|{
name|table
index|[
literal|0
index|]
operator|->
name|relateToOperator
argument_list|(
name|name
argument_list|,
name|op
argument_list|)
expr_stmt|;
block|}
name|void
name|relateToExtension
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|TString
modifier|&
name|ext
parameter_list|)
block|{
name|table
index|[
literal|0
index|]
operator|->
name|relateToExtension
argument_list|(
name|name
argument_list|,
name|ext
argument_list|)
expr_stmt|;
block|}
name|int
name|getMaxSymbolId
parameter_list|()
block|{
return|return
name|uniqueId
return|;
block|}
name|void
name|dump
argument_list|(
name|TInfoSink
operator|&
name|infoSink
argument_list|)
decl|const
decl_stmt|;
name|void
name|copyTable
parameter_list|(
specifier|const
name|TSymbolTable
modifier|&
name|copyOf
parameter_list|)
function_decl|;
name|bool
name|setDefaultPrecision
parameter_list|(
specifier|const
name|TPublicType
modifier|&
name|type
parameter_list|,
name|TPrecision
name|prec
parameter_list|)
block|{
if|if
condition|(
name|IsSampler
argument_list|(
name|type
operator|.
name|type
argument_list|)
condition|)
return|return
name|true
return|;
comment|// Skip sampler types for the time being
if|if
condition|(
name|type
operator|.
name|type
operator|!=
name|EbtFloat
operator|&&
name|type
operator|.
name|type
operator|!=
name|EbtInt
condition|)
return|return
name|false
return|;
comment|// Only set default precision for int/float
if|if
condition|(
name|type
operator|.
name|size
operator|!=
literal|1
operator|||
name|type
operator|.
name|matrix
operator|||
name|type
operator|.
name|array
condition|)
return|return
name|false
return|;
comment|// Not allowed to set for aggregate types
name|int
name|indexOfLastElement
init|=
name|static_cast
operator|<
name|int
operator|>
operator|(
name|precisionStack
operator|.
name|size
argument_list|()
operator|)
operator|-
literal|1
decl_stmt|;
name|precisionStack
index|[
name|indexOfLastElement
index|]
index|[
name|type
operator|.
name|type
index|]
operator|=
name|prec
expr_stmt|;
comment|// Uses map operator [], overwrites the current value
return|return
name|true
return|;
block|}
comment|// Searches down the precisionStack for a precision qualifier for the specified TBasicType
name|TPrecision
name|getDefaultPrecision
parameter_list|(
name|TBasicType
name|type
parameter_list|)
block|{
if|if
condition|(
name|type
operator|!=
name|EbtFloat
operator|&&
name|type
operator|!=
name|EbtInt
condition|)
return|return
name|EbpUndefined
return|;
name|int
name|level
init|=
name|static_cast
operator|<
name|int
operator|>
operator|(
name|precisionStack
operator|.
name|size
argument_list|()
operator|)
operator|-
literal|1
decl_stmt|;
name|assert
argument_list|(
name|level
operator|>=
literal|0
argument_list|)
expr_stmt|;
comment|// Just to be safe. Should not happen.
name|PrecisionStackLevel
operator|::
name|iterator
name|it
expr_stmt|;
name|TPrecision
name|prec
init|=
name|EbpUndefined
decl_stmt|;
comment|// If we dont find anything we return this. Should we error check this?
while|while
condition|(
name|level
operator|>=
literal|0
condition|)
block|{
name|it
operator|=
name|precisionStack
index|[
name|level
index|]
operator|.
name|find
argument_list|(
name|type
argument_list|)
expr_stmt|;
if|if
condition|(
name|it
operator|!=
name|precisionStack
index|[
name|level
index|]
operator|.
name|end
argument_list|()
condition|)
block|{
name|prec
operator|=
operator|(
operator|*
name|it
operator|)
operator|.
name|second
expr_stmt|;
break|break;
block|}
name|level
operator|--
expr_stmt|;
block|}
return|return
name|prec
return|;
block|}
name|protected
label|:
name|int
name|currentLevel
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|table
operator|.
name|size
argument_list|()
operator|)
operator|-
literal|1
return|;
block|}
name|std
operator|::
name|vector
operator|<
name|TSymbolTableLevel
operator|*
operator|>
name|table
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|TBasicType
operator|,
name|TPrecision
operator|>
name|PrecisionStackLevel
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|PrecisionStackLevel
operator|>
name|precisionStack
expr_stmt|;
name|int
name|uniqueId
decl_stmt|;
comment|// for unique identification in code generation
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// _SYMBOL_TABLE_INCLUDED_
end_comment
end_unit
