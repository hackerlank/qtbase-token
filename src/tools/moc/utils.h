begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|UTILS_H
end_ifndef
begin_define
DECL|macro|UTILS_H
define|#
directive|define
name|UTILS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|is_whitespace
specifier|inline
name|bool
name|is_whitespace
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
operator|||
name|s
operator|==
literal|'\n'
operator|)
return|;
block|}
end_function
begin_function
DECL|function|is_space
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
operator|||
name|s
operator|==
literal|'$'
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
operator|||
name|s
operator|==
literal|'$'
operator|)
return|;
block|}
end_function
begin_function
DECL|function|is_identifier
specifier|inline
name|bool
name|is_identifier
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|len
parameter_list|)
block|{
if|if
condition|(
name|len
operator|<
literal|1
condition|)
return|return
name|false
return|;
if|if
condition|(
operator|!
name|is_ident_start
argument_list|(
operator|*
name|s
argument_list|)
condition|)
return|return
name|false
return|;
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
operator|++
name|i
control|)
if|if
condition|(
operator|!
name|is_ident_char
argument_list|(
name|s
index|[
name|i
index|]
argument_list|)
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
end_function
begin_function
DECL|function|is_digit_char
specifier|inline
name|bool
name|is_digit_char
parameter_list|(
name|char
name|s
parameter_list|)
block|{
return|return
operator|(
name|s
operator|>=
literal|'0'
operator|&&
name|s
operator|<=
literal|'9'
operator|)
return|;
block|}
end_function
begin_function
DECL|function|is_octal_char
specifier|inline
name|bool
name|is_octal_char
parameter_list|(
name|char
name|s
parameter_list|)
block|{
return|return
operator|(
name|s
operator|>=
literal|'0'
operator|&&
name|s
operator|<=
literal|'7'
operator|)
return|;
block|}
end_function
begin_function
DECL|function|is_hex_char
specifier|inline
name|bool
name|is_hex_char
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
literal|'f'
operator|)
operator|||
operator|(
name|s
operator|>=
literal|'A'
operator|&&
name|s
operator|<=
literal|'F'
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
operator|)
return|;
block|}
end_function
begin_function
DECL|function|skipQuote
specifier|inline
specifier|const
name|char
modifier|*
name|skipQuote
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|)
block|{
while|while
condition|(
operator|*
name|data
operator|&&
operator|(
operator|*
name|data
operator|!=
literal|'\"'
operator|)
condition|)
block|{
if|if
condition|(
operator|*
name|data
operator|==
literal|'\\'
condition|)
block|{
operator|++
name|data
expr_stmt|;
if|if
condition|(
operator|!
operator|*
name|data
condition|)
break|break;
block|}
operator|++
name|data
expr_stmt|;
block|}
if|if
condition|(
operator|*
name|data
condition|)
comment|//Skip last quote
operator|++
name|data
expr_stmt|;
return|return
name|data
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
begin_comment
comment|// UTILS_H
end_comment
end_unit
