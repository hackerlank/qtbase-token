begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|<qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_struct
DECL|struct|Keyword
struct|struct
name|Keyword
block|{
DECL|member|lexem
specifier|const
name|char
modifier|*
name|lexem
decl_stmt|;
DECL|member|token
specifier|const
name|char
modifier|*
name|token
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|pp_keywords
specifier|static
specifier|const
name|Keyword
name|pp_keywords
index|[]
init|=
block|{
block|{
literal|"<"
block|,
literal|"PP_LANGLE"
block|}
block|,
block|{
literal|">"
block|,
literal|"PP_RANGLE"
block|}
block|,
block|{
literal|"("
block|,
literal|"PP_LPAREN"
block|}
block|,
block|{
literal|")"
block|,
literal|"PP_RPAREN"
block|}
block|,
block|{
literal|","
block|,
literal|"PP_COMMA"
block|}
block|,
block|{
literal|"\n"
block|,
literal|"PP_NEWLINE"
block|}
block|,
block|{
literal|"#define"
block|,
literal|"PP_DEFINE"
block|}
block|,
block|{
literal|"#if"
block|,
literal|"PP_IF"
block|}
block|,
block|{
literal|"#undef"
block|,
literal|"PP_UNDEF"
block|}
block|,
block|{
literal|"#ifdef"
block|,
literal|"PP_IFDEF"
block|}
block|,
block|{
literal|"#ifndef"
block|,
literal|"PP_IFNDEF"
block|}
block|,
block|{
literal|"#elif"
block|,
literal|"PP_ELIF"
block|}
block|,
block|{
literal|"#else"
block|,
literal|"PP_ELSE"
block|}
block|,
block|{
literal|"#endif"
block|,
literal|"PP_ENDIF"
block|}
block|,
block|{
literal|"#include"
block|,
literal|"PP_INCLUDE"
block|}
block|,
block|{
literal|"defined"
block|,
literal|"PP_DEFINED"
block|}
block|,
block|{
literal|"+"
block|,
literal|"PP_PLUS"
block|}
block|,
block|{
literal|"-"
block|,
literal|"PP_MINUS"
block|}
block|,
block|{
literal|"*"
block|,
literal|"PP_STAR"
block|}
block|,
block|{
literal|"/"
block|,
literal|"PP_SLASH"
block|}
block|,
block|{
literal|"%"
block|,
literal|"PP_PERCENT"
block|}
block|,
block|{
literal|"^"
block|,
literal|"PP_HAT"
block|}
block|,
block|{
literal|"&"
block|,
literal|"PP_AND"
block|}
block|,
block|{
literal|"bitand"
block|,
literal|"PP_AND"
block|}
block|,
block|{
literal|"|"
block|,
literal|"PP_OR"
block|}
block|,
block|{
literal|"bitor"
block|,
literal|"PP_OR"
block|}
block|,
block|{
literal|"~"
block|,
literal|"PP_TILDE"
block|}
block|,
block|{
literal|"compl"
block|,
literal|"PP_TILDE"
block|}
block|,
block|{
literal|"!"
block|,
literal|"PP_NOT"
block|}
block|,
block|{
literal|"not"
block|,
literal|"PP_NOT"
block|}
block|,
block|{
literal|"<<"
block|,
literal|"PP_LTLT"
block|}
block|,
block|{
literal|">>"
block|,
literal|"PP_GTGT"
block|}
block|,
block|{
literal|"=="
block|,
literal|"PP_EQEQ"
block|}
block|,
block|{
literal|"!="
block|,
literal|"PP_NE"
block|}
block|,
block|{
literal|"not_eq"
block|,
literal|"PP_NE"
block|}
block|,
block|{
literal|"<="
block|,
literal|"PP_LE"
block|}
block|,
block|{
literal|">="
block|,
literal|"PP_GE"
block|}
block|,
block|{
literal|"&&"
block|,
literal|"PP_ANDAND"
block|}
block|,
block|{
literal|"||"
block|,
literal|"PP_OROR"
block|}
block|,
block|{
literal|"?"
block|,
literal|"PP_QUESTION"
block|}
block|,
block|{
literal|":"
block|,
literal|"PP_COLON"
block|}
block|,
block|{
literal|"##"
block|,
literal|"PP_HASHHASH"
block|}
block|,
block|{
literal|"%:%:"
block|,
literal|"PP_HASHHASH"
block|}
block|,
block|{
literal|"#"
block|,
literal|"PP_HASH"
block|}
block|,
block|{
literal|"\""
block|,
literal|"PP_QUOTE"
block|}
block|,
block|{
literal|"\'"
block|,
literal|"PP_SINGLEQUOTE"
block|}
block|,
block|{
literal|" "
block|,
literal|"PP_WHITESPACE"
block|}
block|,
block|{
literal|"\t"
block|,
literal|"PP_WHITESPACE"
block|}
block|,
block|{
literal|"//"
block|,
literal|"PP_CPP_COMMENT"
block|}
block|,
block|{
literal|"/*"
block|,
literal|"PP_C_COMMENT"
block|}
block|,
block|{
literal|"\\"
block|,
literal|"PP_BACKSLASH"
block|}
block|,
block|{
literal|0
block|,
literal|"PP_NOTOKEN"
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|keywords
specifier|static
specifier|const
name|Keyword
name|keywords
index|[]
init|=
block|{
block|{
literal|"<"
block|,
literal|"LANGLE"
block|}
block|,
block|{
literal|">"
block|,
literal|"RANGLE"
block|}
block|,
block|{
literal|"("
block|,
literal|"LPAREN"
block|}
block|,
block|{
literal|")"
block|,
literal|"RPAREN"
block|}
block|,
block|{
literal|"..."
block|,
literal|"ELIPSIS"
block|}
block|,
block|{
literal|","
block|,
literal|"COMMA"
block|}
block|,
block|{
literal|"["
block|,
literal|"LBRACK"
block|}
block|,
block|{
literal|"]"
block|,
literal|"RBRACK"
block|}
block|,
block|{
literal|"<:"
block|,
literal|"LBRACK"
block|}
block|,
block|{
literal|":>"
block|,
literal|"RBRACK"
block|}
block|,
block|{
literal|"<::"
block|,
literal|"LANGLE_SCOPE"
block|}
block|,
block|{
literal|"{"
block|,
literal|"LBRACE"
block|}
block|,
block|{
literal|"<%"
block|,
literal|"LBRACE"
block|}
block|,
block|{
literal|"}"
block|,
literal|"RBRACE"
block|}
block|,
block|{
literal|"%>"
block|,
literal|"RBRACE"
block|}
block|,
block|{
literal|"="
block|,
literal|"EQ"
block|}
block|,
block|{
literal|"::"
block|,
literal|"SCOPE"
block|}
block|,
block|{
literal|";"
block|,
literal|"SEMIC"
block|}
block|,
block|{
literal|":"
block|,
literal|"COLON"
block|}
block|,
block|{
literal|".*"
block|,
literal|"DOTSTAR"
block|}
block|,
block|{
literal|"?"
block|,
literal|"QUESTION"
block|}
block|,
block|{
literal|"."
block|,
literal|"DOT"
block|}
block|,
block|{
literal|"dynamic_cast"
block|,
literal|"DYNAMIC_CAST"
block|}
block|,
block|{
literal|"static_cast"
block|,
literal|"STATIC_CAST"
block|}
block|,
block|{
literal|"reinterpret_cast"
block|,
literal|"REINTERPRET_CAST"
block|}
block|,
block|{
literal|"const_cast"
block|,
literal|"CONST_CAST"
block|}
block|,
block|{
literal|"typeid"
block|,
literal|"TYPEID"
block|}
block|,
block|{
literal|"this"
block|,
literal|"THIS"
block|}
block|,
block|{
literal|"template"
block|,
literal|"TEMPLATE"
block|}
block|,
block|{
literal|"throw"
block|,
literal|"THROW"
block|}
block|,
block|{
literal|"try"
block|,
literal|"TRY"
block|}
block|,
block|{
literal|"catch"
block|,
literal|"CATCH"
block|}
block|,
block|{
literal|"typedef"
block|,
literal|"TYPEDEF"
block|}
block|,
block|{
literal|"friend"
block|,
literal|"FRIEND"
block|}
block|,
block|{
literal|"class"
block|,
literal|"CLASS"
block|}
block|,
block|{
literal|"namespace"
block|,
literal|"NAMESPACE"
block|}
block|,
block|{
literal|"enum"
block|,
literal|"ENUM"
block|}
block|,
block|{
literal|"struct"
block|,
literal|"STRUCT"
block|}
block|,
block|{
literal|"union"
block|,
literal|"UNION"
block|}
block|,
block|{
literal|"virtual"
block|,
literal|"VIRTUAL"
block|}
block|,
block|{
literal|"private"
block|,
literal|"PRIVATE"
block|}
block|,
block|{
literal|"protected"
block|,
literal|"PROTECTED"
block|}
block|,
block|{
literal|"public"
block|,
literal|"PUBLIC"
block|}
block|,
block|{
literal|"export"
block|,
literal|"EXPORT"
block|}
block|,
block|{
literal|"auto"
block|,
literal|"AUTO"
block|}
block|,
block|{
literal|"register"
block|,
literal|"REGISTER"
block|}
block|,
block|{
literal|"extern"
block|,
literal|"EXTERN"
block|}
block|,
block|{
literal|"mutable"
block|,
literal|"MUTABLE"
block|}
block|,
block|{
literal|"asm"
block|,
literal|"ASM"
block|}
block|,
block|{
literal|"using"
block|,
literal|"USING"
block|}
block|,
block|{
literal|"inline"
block|,
literal|"INLINE"
block|}
block|,
block|{
literal|"explicit"
block|,
literal|"EXPLICIT"
block|}
block|,
block|{
literal|"static"
block|,
literal|"STATIC"
block|}
block|,
block|{
literal|"const"
block|,
literal|"CONST"
block|}
block|,
block|{
literal|"volatile"
block|,
literal|"VOLATILE"
block|}
block|,
block|{
literal|"operator"
block|,
literal|"OPERATOR"
block|}
block|,
block|{
literal|"sizeof"
block|,
literal|"SIZEOF"
block|}
block|,
block|{
literal|"new"
block|,
literal|"NEW"
block|}
block|,
block|{
literal|"delete"
block|,
literal|"DELETE"
block|}
block|,
block|{
literal|"+"
block|,
literal|"PLUS"
block|}
block|,
block|{
literal|"-"
block|,
literal|"MINUS"
block|}
block|,
block|{
literal|"*"
block|,
literal|"STAR"
block|}
block|,
block|{
literal|"/"
block|,
literal|"SLASH"
block|}
block|,
block|{
literal|"%"
block|,
literal|"PERCENT"
block|}
block|,
block|{
literal|"^"
block|,
literal|"HAT"
block|}
block|,
block|{
literal|"&"
block|,
literal|"AND"
block|}
block|,
block|{
literal|"bitand"
block|,
literal|"AND"
block|}
block|,
block|{
literal|"|"
block|,
literal|"OR"
block|}
block|,
block|{
literal|"bitor"
block|,
literal|"OR"
block|}
block|,
block|{
literal|"~"
block|,
literal|"TILDE"
block|}
block|,
block|{
literal|"compl"
block|,
literal|"TILDE"
block|}
block|,
block|{
literal|"!"
block|,
literal|"NOT"
block|}
block|,
block|{
literal|"not"
block|,
literal|"NOT"
block|}
block|,
block|{
literal|"+="
block|,
literal|"PLUS_EQ"
block|}
block|,
block|{
literal|"-="
block|,
literal|"MINUS_EQ"
block|}
block|,
block|{
literal|"*="
block|,
literal|"STAR_EQ"
block|}
block|,
block|{
literal|"/="
block|,
literal|"SLASH_EQ"
block|}
block|,
block|{
literal|"%="
block|,
literal|"PERCENT_EQ"
block|}
block|,
block|{
literal|"^="
block|,
literal|"HAT_EQ"
block|}
block|,
block|{
literal|"&="
block|,
literal|"AND_EQ"
block|}
block|,
block|{
literal|"|="
block|,
literal|"OR_EQ"
block|}
block|,
block|{
literal|"<<"
block|,
literal|"LTLT"
block|}
block|,
block|{
literal|">>"
block|,
literal|"GTGT"
block|}
block|,
block|{
literal|">>="
block|,
literal|"GTGT_EQ"
block|}
block|,
block|{
literal|"<<="
block|,
literal|"LTLT_EQ"
block|}
block|,
block|{
literal|"=="
block|,
literal|"EQEQ"
block|}
block|,
block|{
literal|"!="
block|,
literal|"NE"
block|}
block|,
block|{
literal|"not_eq"
block|,
literal|"NE"
block|}
block|,
block|{
literal|"<="
block|,
literal|"LE"
block|}
block|,
block|{
literal|">="
block|,
literal|"GE"
block|}
block|,
block|{
literal|"&&"
block|,
literal|"ANDAND"
block|}
block|,
block|{
literal|"||"
block|,
literal|"OROR"
block|}
block|,
block|{
literal|"++"
block|,
literal|"INCR"
block|}
block|,
block|{
literal|"--"
block|,
literal|"DECR"
block|}
block|,
block|{
literal|","
block|,
literal|"COMMA"
block|}
block|,
block|{
literal|"->*"
block|,
literal|"ARROW_STAR"
block|}
block|,
block|{
literal|"->"
block|,
literal|"ARROW"
block|}
block|,
block|{
literal|"char"
block|,
literal|"CHAR"
block|}
block|,
block|{
literal|"wchar"
block|,
literal|"WCHAR"
block|}
block|,
block|{
literal|"bool"
block|,
literal|"BOOL"
block|}
block|,
block|{
literal|"short"
block|,
literal|"SHORT"
block|}
block|,
block|{
literal|"int"
block|,
literal|"INT"
block|}
block|,
block|{
literal|"long"
block|,
literal|"LONG"
block|}
block|,
block|{
literal|"signed"
block|,
literal|"SIGNED"
block|}
block|,
block|{
literal|"unsigned"
block|,
literal|"UNSIGNED"
block|}
block|,
block|{
literal|"float"
block|,
literal|"FLOAT"
block|}
block|,
block|{
literal|"double"
block|,
literal|"DOUBLE"
block|}
block|,
block|{
literal|"void"
block|,
literal|"VOID"
block|}
block|,
block|{
literal|"case"
block|,
literal|"CASE"
block|}
block|,
block|{
literal|"default"
block|,
literal|"DEFAULT"
block|}
block|,
block|{
literal|"if"
block|,
literal|"IF"
block|}
block|,
block|{
literal|"else"
block|,
literal|"ELSE"
block|}
block|,
block|{
literal|"switch"
block|,
literal|"SWITCH"
block|}
block|,
block|{
literal|"while"
block|,
literal|"WHILE"
block|}
block|,
block|{
literal|"do"
block|,
literal|"DO"
block|}
block|,
block|{
literal|"for"
block|,
literal|"FOR"
block|}
block|,
block|{
literal|"break"
block|,
literal|"BREAK"
block|}
block|,
block|{
literal|"continue"
block|,
literal|"CONTINUE"
block|}
block|,
block|{
literal|"goto"
block|,
literal|"GOTO"
block|}
block|,
block|{
literal|"return"
block|,
literal|"RETURN"
block|}
block|,
block|{
literal|"Q_OBJECT"
block|,
literal|"Q_OBJECT_TOKEN"
block|}
block|,
block|{
literal|"Q_GADGET"
block|,
literal|"Q_GADGET_TOKEN"
block|}
block|,
block|{
literal|"Q_PROPERTY"
block|,
literal|"Q_PROPERTY_TOKEN"
block|}
block|,
block|{
literal|"Q_ENUMS"
block|,
literal|"Q_ENUMS_TOKEN"
block|}
block|,
block|{
literal|"Q_FLAGS"
block|,
literal|"Q_FLAGS_TOKEN"
block|}
block|,
block|{
literal|"Q_DECLARE_FLAGS"
block|,
literal|"Q_DECLARE_FLAGS_TOKEN"
block|}
block|,
block|{
literal|"Q_DECLARE_INTERFACE"
block|,
literal|"Q_DECLARE_INTERFACE_TOKEN"
block|}
block|,
block|{
literal|"Q_DECLARE_METATYPE"
block|,
literal|"Q_DECLARE_METATYPE_TOKEN"
block|}
block|,
block|{
literal|"Q_DECLARE_EXTENSION_INTERFACE"
block|,
literal|"Q_DECLARE_INTERFACE_TOKEN"
block|}
block|,
block|{
literal|"Q_SETS"
block|,
literal|"Q_FLAGS_TOKEN"
block|}
block|,
block|{
literal|"Q_CLASSINFO"
block|,
literal|"Q_CLASSINFO_TOKEN"
block|}
block|,
block|{
literal|"Q_INTERFACES"
block|,
literal|"Q_INTERFACES_TOKEN"
block|}
block|,
block|{
literal|"signals"
block|,
literal|"SIGNALS"
block|}
block|,
block|{
literal|"slots"
block|,
literal|"SLOTS"
block|}
block|,
block|{
literal|"Q_SIGNALS"
block|,
literal|"Q_SIGNALS_TOKEN"
block|}
block|,
block|{
literal|"Q_SLOTS"
block|,
literal|"Q_SLOTS_TOKEN"
block|}
block|,
block|{
literal|"Q_PRIVATE_SLOT"
block|,
literal|"Q_PRIVATE_SLOT_TOKEN"
block|}
block|,
block|{
literal|"QT_MOC_COMPAT"
block|,
literal|"Q_MOC_COMPAT_TOKEN"
block|}
block|,
block|{
literal|"Q_INVOKABLE"
block|,
literal|"Q_INVOKABLE_TOKEN"
block|}
block|,
block|{
literal|"Q_SIGNAL"
block|,
literal|"Q_SIGNAL_TOKEN"
block|}
block|,
block|{
literal|"Q_SLOT"
block|,
literal|"Q_SLOT_TOKEN"
block|}
block|,
block|{
literal|"Q_SCRIPTABLE"
block|,
literal|"Q_SCRIPTABLE_TOKEN"
block|}
block|,
block|{
literal|"Q_PRIVATE_PROPERTY"
block|,
literal|"Q_PRIVATE_PROPERTY_TOKEN"
block|}
block|,
block|{
literal|"Q_REVISION"
block|,
literal|"Q_REVISION_TOKEN"
block|}
block|,
block|{
literal|"\n"
block|,
literal|"NEWLINE"
block|}
block|,
block|{
literal|"\""
block|,
literal|"QUOTE"
block|}
block|,
block|{
literal|"\'"
block|,
literal|"SINGLEQUOTE"
block|}
block|,
block|{
literal|" "
block|,
literal|"WHITESPACE"
block|}
block|,
block|{
literal|"\t"
block|,
literal|"WHITESPACE"
block|}
block|,
block|{
literal|"#"
block|,
literal|"HASH"
block|}
block|,
block|{
literal|"\\"
block|,
literal|"BACKSLASH"
block|}
block|,
block|{
literal|"//"
block|,
literal|"CPP_COMMENT"
block|}
block|,
block|{
literal|"/*"
block|,
literal|"C_COMMENT"
block|}
block|,
block|{
literal|0
block|,
literal|"NOTOKEN"
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|is_ident_start
specifier|inline
name|bool
name|is_ident_start
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
name|s
operator|==
literal|'_'
operator|)
return|;
block|}
end_function
begin_function
DECL|function|is_ident_char
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
begin_struct
DECL|struct|State
struct|struct
name|State
block|{
DECL|function|State
name|State
parameter_list|(
specifier|const
name|char
modifier|*
name|token
parameter_list|)
member_init_list|:
name|token
argument_list|(
name|token
argument_list|)
member_init_list|,
name|nextindex
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|defchar
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|defnext
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|ident
argument_list|(
literal|0
argument_list|)
block|{
name|memset
argument_list|(
name|next
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|next
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|member|token
name|QByteArray
name|token
decl_stmt|;
DECL|member|next
name|int
name|next
index|[
literal|128
index|]
decl_stmt|;
DECL|member|nextindex
name|int
name|nextindex
decl_stmt|;
DECL|member|defchar
name|char
name|defchar
decl_stmt|;
DECL|member|defnext
name|int
name|defnext
decl_stmt|;
DECL|member|ident
specifier|const
name|char
modifier|*
name|ident
decl_stmt|;
DECL|function|operator ==
name|bool
name|operator
name|==
parameter_list|(
specifier|const
name|State
modifier|&
name|o
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|token
operator|==
name|o
operator|.
name|token
operator|&&
name|nextindex
operator|==
name|o
operator|.
name|nextindex
operator|&&
name|defchar
operator|==
name|o
operator|.
name|defchar
operator|&&
name|defnext
operator|==
name|o
operator|.
name|defnext
operator|&&
name|ident
operator|==
name|o
operator|.
name|ident
operator|)
return|;
block|}
block|}
struct|;
end_struct
begin_function
DECL|function|newState
name|void
name|newState
parameter_list|(
name|QList
argument_list|<
name|State
argument_list|>
modifier|&
name|states
parameter_list|,
specifier|const
name|char
modifier|*
name|token
parameter_list|,
specifier|const
name|char
modifier|*
name|lexem
parameter_list|,
name|bool
name|pre
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|ident
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|is_ident_start
argument_list|(
operator|*
name|lexem
argument_list|)
condition|)
name|ident
operator|=
name|pre
condition|?
literal|"PP_CHARACTER"
else|:
literal|"CHARACTER"
expr_stmt|;
elseif|else
if|if
condition|(
operator|*
name|lexem
operator|==
literal|'#'
condition|)
name|ident
operator|=
name|pre
condition|?
literal|"PP_HASH"
else|:
literal|"HASH"
expr_stmt|;
name|int
name|state
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|*
name|lexem
condition|)
block|{
name|int
name|next
init|=
name|states
index|[
name|state
index|]
operator|.
name|next
index|[
operator|(
name|int
operator|)
operator|*
name|lexem
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|next
condition|)
block|{
specifier|const
name|char
modifier|*
name|t
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|ident
condition|)
name|t
operator|=
name|ident
expr_stmt|;
else|else
name|t
operator|=
name|pre
condition|?
literal|"PP_INCOMPLETE"
else|:
literal|"INCOMPLETE"
expr_stmt|;
name|next
operator|=
name|states
operator|.
name|size
argument_list|()
expr_stmt|;
name|states
operator|+=
name|State
argument_list|(
name|t
argument_list|)
expr_stmt|;
name|states
index|[
name|state
index|]
operator|.
name|next
index|[
operator|(
name|int
operator|)
operator|*
name|lexem
index|]
operator|=
name|next
expr_stmt|;
name|states
index|[
name|next
index|]
operator|.
name|ident
operator|=
name|ident
expr_stmt|;
block|}
name|state
operator|=
name|next
expr_stmt|;
operator|++
name|lexem
expr_stmt|;
if|if
condition|(
name|ident
operator|&&
operator|!
name|is_ident_char
argument_list|(
operator|*
name|lexem
argument_list|)
condition|)
name|ident
operator|=
literal|0
expr_stmt|;
block|}
name|states
index|[
name|state
index|]
operator|.
name|token
operator|=
name|token
expr_stmt|;
block|}
end_function
begin_function
DECL|function|newState
name|void
name|newState
parameter_list|(
name|QList
argument_list|<
name|State
argument_list|>
modifier|&
name|states
parameter_list|,
specifier|const
name|char
modifier|*
name|token
parameter_list|,
name|char
name|lexem
parameter_list|)
block|{
name|int
name|next
init|=
name|states
index|[
literal|0
index|]
operator|.
name|next
index|[
operator|(
name|int
operator|)
name|lexem
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|next
condition|)
block|{
name|next
operator|=
name|states
operator|.
name|size
argument_list|()
expr_stmt|;
name|states
operator|+=
name|State
argument_list|(
name|token
argument_list|)
expr_stmt|;
name|states
index|[
literal|0
index|]
operator|.
name|next
index|[
operator|(
name|int
operator|)
name|lexem
index|]
operator|=
name|next
expr_stmt|;
block|}
else|else
block|{
name|states
index|[
name|next
index|]
operator|.
name|token
operator|=
name|token
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|makeTable
name|void
name|makeTable
parameter_list|(
specifier|const
name|Keyword
name|keywords
index|[]
parameter_list|)
block|{
name|int
name|i
decl_stmt|,
name|c
decl_stmt|;
name|bool
name|pre
init|=
operator|(
name|keywords
operator|==
name|pp_keywords
operator|)
decl_stmt|;
name|QList
argument_list|<
name|State
argument_list|>
name|states
decl_stmt|;
name|states
operator|+=
name|State
argument_list|(
name|pre
condition|?
literal|"PP_NOTOKEN"
else|:
literal|"NOTOKEN"
argument_list|)
expr_stmt|;
comment|// identifiers
for|for
control|(
name|c
operator|=
literal|'a'
init|;
name|c
operator|<=
literal|'z'
condition|;
operator|++
name|c
control|)
name|newState
argument_list|(
name|states
argument_list|,
name|pre
condition|?
literal|"PP_CHARACTER"
else|:
literal|"CHARACTER"
argument_list|,
name|c
argument_list|)
expr_stmt|;
for|for
control|(
name|c
operator|=
literal|'A'
init|;
name|c
operator|<=
literal|'Z'
condition|;
operator|++
name|c
control|)
name|newState
argument_list|(
name|states
argument_list|,
name|pre
condition|?
literal|"PP_CHARACTER"
else|:
literal|"CHARACTER"
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|c
operator|=
literal|'_'
expr_stmt|;
name|newState
argument_list|(
name|states
argument_list|,
name|pre
condition|?
literal|"PP_CHARACTER"
else|:
literal|"CHARACTER"
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// add digits
for|for
control|(
name|c
operator|=
literal|'0'
init|;
name|c
operator|<=
literal|'9'
condition|;
operator|++
name|c
control|)
name|newState
argument_list|(
name|states
argument_list|,
name|pre
condition|?
literal|"PP_DIGIT"
else|:
literal|"DIGIT"
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// keywords
for|for
control|(
name|i
operator|=
literal|0
init|;
name|keywords
index|[
name|i
index|]
operator|.
name|lexem
condition|;
operator|++
name|i
control|)
name|newState
argument_list|(
name|states
argument_list|,
name|keywords
index|[
name|i
index|]
operator|.
name|token
argument_list|,
name|keywords
index|[
name|i
index|]
operator|.
name|lexem
argument_list|,
name|pre
argument_list|)
expr_stmt|;
comment|// some floats
for|for
control|(
name|c
operator|=
literal|'0'
init|;
name|c
operator|<=
literal|'9'
condition|;
operator|++
name|c
control|)
name|newState
argument_list|(
name|states
argument_list|,
name|pre
condition|?
literal|"PP_FLOATING_LITERAL"
else|:
literal|"FLOATING_LITERAL"
argument_list|,
name|QByteArray
argument_list|(
literal|"."
argument_list|)
operator|+
name|char
argument_list|(
name|c
argument_list|)
argument_list|,
name|pre
argument_list|)
expr_stmt|;
comment|// simplify table with default transitions
name|int
name|transindex
init|=
operator|-
literal|1
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|states
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|int
name|n
init|=
literal|0
decl_stmt|;
name|int
name|defchar
init|=
operator|-
literal|1
decl_stmt|;
for|for
control|(
name|c
operator|=
literal|0
init|;
name|c
operator|<
literal|128
condition|;
operator|++
name|c
control|)
if|if
condition|(
name|states
index|[
name|i
index|]
operator|.
name|next
index|[
name|c
index|]
condition|)
block|{
operator|++
name|n
expr_stmt|;
name|defchar
operator|=
name|c
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|n
condition|)
continue|continue;
if|if
condition|(
name|n
operator|==
literal|1
condition|)
block|{
name|states
index|[
name|i
index|]
operator|.
name|defnext
operator|=
name|states
index|[
name|i
index|]
operator|.
name|next
index|[
name|defchar
index|]
expr_stmt|;
name|states
index|[
name|i
index|]
operator|.
name|defchar
operator|=
name|defchar
expr_stmt|;
continue|continue;
block|}
name|states
index|[
name|i
index|]
operator|.
name|nextindex
operator|=
operator|++
name|transindex
expr_stmt|;
block|}
if|#
directive|if
literal|1
comment|// compress table
name|int
name|j
decl_stmt|,
name|k
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|states
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
for|for
control|(
name|j
operator|=
name|i
operator|+
literal|1
init|;
name|j
operator|<
name|states
operator|.
name|size
argument_list|()
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
name|states
index|[
name|i
index|]
operator|==
name|states
index|[
name|j
index|]
condition|)
block|{
for|for
control|(
name|k
operator|=
literal|0
init|;
name|k
operator|<
name|states
operator|.
name|size
argument_list|()
condition|;
operator|++
name|k
control|)
block|{
if|if
condition|(
name|states
index|[
name|k
index|]
operator|.
name|defnext
operator|==
name|j
condition|)
name|states
index|[
name|k
index|]
operator|.
name|defnext
operator|=
name|i
expr_stmt|;
if|if
condition|(
name|states
index|[
name|k
index|]
operator|.
name|defnext
operator|>
name|j
condition|)
operator|--
name|states
index|[
name|k
index|]
operator|.
name|defnext
expr_stmt|;
for|for
control|(
name|c
operator|=
literal|0
init|;
name|c
operator|<
literal|128
condition|;
operator|++
name|c
control|)
block|{
if|if
condition|(
name|states
index|[
name|k
index|]
operator|.
name|next
index|[
name|c
index|]
operator|==
name|j
condition|)
name|states
index|[
name|k
index|]
operator|.
name|next
index|[
name|c
index|]
operator|=
name|i
expr_stmt|;
if|if
condition|(
name|states
index|[
name|k
index|]
operator|.
name|next
index|[
name|c
index|]
operator|>
name|j
condition|)
operator|--
name|states
index|[
name|k
index|]
operator|.
name|next
index|[
name|c
index|]
expr_stmt|;
block|}
block|}
name|states
operator|.
name|removeAt
argument_list|(
name|j
argument_list|)
expr_stmt|;
operator|--
name|j
expr_stmt|;
block|}
block|}
block|}
endif|#
directive|endif
name|printf
argument_list|(
literal|"static const short %skeyword_trans[][128] = {\n"
argument_list|,
name|pre
condition|?
literal|"pp_"
else|:
literal|""
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|states
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
name|i
operator|&&
operator|!
name|states
index|[
name|i
index|]
operator|.
name|nextindex
condition|)
continue|continue;
name|printf
argument_list|(
literal|"%s    {"
argument_list|,
name|i
condition|?
literal|",\n"
else|:
literal|""
argument_list|)
expr_stmt|;
for|for
control|(
name|c
operator|=
literal|0
init|;
name|c
operator|<
literal|128
condition|;
operator|++
name|c
control|)
name|printf
argument_list|(
literal|"%s%s%d"
argument_list|,
name|c
condition|?
literal|","
else|:
literal|""
argument_list|,
operator|(
operator|!
name|c
operator|||
name|c
operator|%
literal|16
operator|)
condition|?
literal|""
else|:
literal|"\n     "
argument_list|,
name|states
index|[
name|i
index|]
operator|.
name|next
index|[
name|c
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"}"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n};\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"static const struct\n{\n"
literal|"   %sToken token;\n"
literal|"   short next;\n"
literal|"   char defchar;\n"
literal|"   short defnext;\n"
literal|"   %sToken ident;\n"
literal|"} %skeywords[] = {\n"
argument_list|,
name|pre
condition|?
literal|"PP_"
else|:
literal|""
argument_list|,
name|pre
condition|?
literal|"PP_"
else|:
literal|""
argument_list|,
name|pre
condition|?
literal|"pp_"
else|:
literal|""
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|states
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|printf
argument_list|(
literal|"%s    {%s, %d, %d, %d, %s}"
argument_list|,
name|i
condition|?
literal|",\n"
else|:
literal|""
argument_list|,
name|states
index|[
name|i
index|]
operator|.
name|token
operator|.
name|data
argument_list|()
argument_list|,
name|states
index|[
name|i
index|]
operator|.
name|nextindex
argument_list|,
name|states
index|[
name|i
index|]
operator|.
name|defchar
argument_list|,
name|states
index|[
name|i
index|]
operator|.
name|defnext
argument_list|,
name|states
index|[
name|i
index|]
operator|.
name|ident
condition|?
name|states
index|[
name|i
index|]
operator|.
name|ident
else|:
operator|(
name|pre
condition|?
literal|"PP_NOTOKEN"
else|:
literal|"NOTOKEN"
operator|)
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n};\n"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
block|{
name|printf
argument_list|(
literal|"// auto generated\n"
literal|"// DO NOT EDIT.\n\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
name|makeTable
argument_list|(
name|pp_keywords
argument_list|)
expr_stmt|;
else|else
name|makeTable
argument_list|(
name|keywords
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
