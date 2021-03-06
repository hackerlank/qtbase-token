begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTRINGALGORITHMS_P_H
end_ifndef
begin_define
DECL|macro|QSTRINGALGORITHMS_P_H
define|#
directive|define
name|QSTRINGALGORITHMS_P_H
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
comment|// of internal files.  This header file may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
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
file|"qstring.h"
end_include
begin_include
include|#
directive|include
file|"qlocale_p.h"
end_include
begin_comment
comment|// for ascii_isspace
end_comment
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
DECL|struct|QStringAlgorithms
name|template
operator|<
name|typename
name|StringType
operator|>
expr|struct
name|QStringAlgorithms
block|{
DECL|typedef|Char
typedef|typedef
name|typename
name|StringType
operator|::
name|value_type
name|Char
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|size_type
typedef|typedef
name|typename
name|StringType
operator|::
name|size_type
name|size_type
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|NakedStringType
typedef|typedef
name|typename
name|QtPrivate
operator|::
name|remove_cv
operator|<
name|StringType
operator|>
operator|::
name|type
name|NakedStringType
expr_stmt|;
end_typedef
begin_decl_stmt
DECL|member|isConst
specifier|static
specifier|const
name|bool
name|isConst
init|=
name|QtPrivate
operator|::
name|is_const
operator|<
name|StringType
operator|>
operator|::
name|value
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|isSpace
specifier|static
specifier|inline
name|bool
name|isSpace
parameter_list|(
name|char
name|ch
parameter_list|)
block|{
return|return
name|ascii_isspace
argument_list|(
name|ch
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isSpace
specifier|static
specifier|inline
name|bool
name|isSpace
parameter_list|(
name|QChar
name|ch
parameter_list|)
block|{
return|return
name|ch
operator|.
name|isSpace
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// Surrogate pairs are not handled in either of the functions below. That is
end_comment
begin_comment
comment|// not a problem because there are no space characters (Zs, Zl, Zp) outside the
end_comment
begin_comment
comment|// Basic Multilingual Plane.
end_comment
begin_function
DECL|function|trimmed_helper_inplace
specifier|static
specifier|inline
name|StringType
name|trimmed_helper_inplace
parameter_list|(
name|NakedStringType
modifier|&
name|str
parameter_list|,
specifier|const
name|Char
modifier|*
name|begin
parameter_list|,
specifier|const
name|Char
modifier|*
name|end
parameter_list|)
block|{
comment|// in-place trimming:
name|Char
modifier|*
name|data
init|=
name|const_cast
operator|<
name|Char
operator|*
operator|>
operator|(
name|str
operator|.
name|cbegin
argument_list|()
operator|)
decl_stmt|;
if|if
condition|(
name|begin
operator|!=
name|data
condition|)
name|memmove
argument_list|(
name|data
argument_list|,
name|begin
argument_list|,
operator|(
name|end
operator|-
name|begin
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|Char
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|.
name|resize
argument_list|(
name|end
operator|-
name|begin
argument_list|)
expr_stmt|;
return|return
name|qMove
argument_list|(
name|str
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|trimmed_helper_inplace
specifier|static
specifier|inline
name|StringType
name|trimmed_helper_inplace
parameter_list|(
specifier|const
name|NakedStringType
modifier|&
parameter_list|,
specifier|const
name|Char
modifier|*
parameter_list|,
specifier|const
name|Char
modifier|*
parameter_list|)
block|{
comment|// can't happen
name|Q_UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|StringType
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|trimmed_helper_positions
specifier|static
specifier|inline
name|void
name|trimmed_helper_positions
parameter_list|(
specifier|const
name|Char
modifier|*
modifier|&
name|begin
parameter_list|,
specifier|const
name|Char
modifier|*
modifier|&
name|end
parameter_list|)
block|{
comment|// skip white space from start
while|while
condition|(
name|begin
operator|<
name|end
operator|&&
name|isSpace
argument_list|(
operator|*
name|begin
argument_list|)
condition|)
name|begin
operator|++
expr_stmt|;
comment|// skip white space from end
if|if
condition|(
name|begin
operator|<
name|end
condition|)
block|{
while|while
condition|(
name|begin
operator|<
name|end
operator|&&
name|isSpace
argument_list|(
name|end
index|[
operator|-
literal|1
index|]
argument_list|)
condition|)
name|end
operator|--
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|trimmed_helper
specifier|static
specifier|inline
name|StringType
name|trimmed_helper
parameter_list|(
name|StringType
modifier|&
name|str
parameter_list|)
block|{
specifier|const
name|Char
modifier|*
name|begin
init|=
name|str
operator|.
name|cbegin
argument_list|()
decl_stmt|;
specifier|const
name|Char
modifier|*
name|end
init|=
name|str
operator|.
name|cend
argument_list|()
decl_stmt|;
name|trimmed_helper_positions
argument_list|(
name|begin
argument_list|,
name|end
argument_list|)
expr_stmt|;
if|if
condition|(
name|begin
operator|==
name|str
operator|.
name|cbegin
argument_list|()
operator|&&
name|end
operator|==
name|str
operator|.
name|cend
argument_list|()
condition|)
return|return
name|str
return|;
if|if
condition|(
operator|!
name|isConst
operator|&&
name|str
operator|.
name|isDetached
argument_list|()
condition|)
return|return
name|trimmed_helper_inplace
argument_list|(
name|str
argument_list|,
name|begin
argument_list|,
name|end
argument_list|)
return|;
return|return
name|StringType
argument_list|(
name|begin
argument_list|,
name|end
operator|-
name|begin
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|simplified_helper
specifier|static
specifier|inline
name|StringType
name|simplified_helper
parameter_list|(
name|StringType
modifier|&
name|str
parameter_list|)
block|{
if|if
condition|(
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|str
return|;
specifier|const
name|Char
modifier|*
name|src
init|=
name|str
operator|.
name|cbegin
argument_list|()
decl_stmt|;
specifier|const
name|Char
modifier|*
name|end
init|=
name|str
operator|.
name|cend
argument_list|()
decl_stmt|;
name|NakedStringType
name|result
init|=
name|isConst
operator|||
operator|!
name|str
operator|.
name|isDetached
argument_list|()
condition|?
name|StringType
argument_list|(
name|str
operator|.
name|size
argument_list|()
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
else|:
name|qMove
argument_list|(
name|str
argument_list|)
decl_stmt|;
name|Char
modifier|*
name|dst
init|=
name|const_cast
operator|<
name|Char
operator|*
operator|>
operator|(
name|result
operator|.
name|cbegin
argument_list|()
operator|)
decl_stmt|;
name|Char
modifier|*
name|ptr
init|=
name|dst
decl_stmt|;
name|bool
name|unmodified
init|=
name|true
decl_stmt|;
name|forever
block|{
while|while
condition|(
name|src
operator|!=
name|end
operator|&&
name|isSpace
argument_list|(
operator|*
name|src
argument_list|)
condition|)
operator|++
name|src
expr_stmt|;
while|while
condition|(
name|src
operator|!=
name|end
operator|&&
operator|!
name|isSpace
argument_list|(
operator|*
name|src
argument_list|)
condition|)
operator|*
name|ptr
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
if|if
condition|(
name|src
operator|==
name|end
condition|)
break|break;
if|if
condition|(
operator|*
name|src
operator|!=
name|QChar
operator|::
name|Space
condition|)
name|unmodified
operator|=
name|false
expr_stmt|;
operator|*
name|ptr
operator|++
operator|=
name|QChar
operator|::
name|Space
expr_stmt|;
block|}
if|if
condition|(
name|ptr
operator|!=
name|dst
operator|&&
name|ptr
index|[
operator|-
literal|1
index|]
operator|==
name|QChar
operator|::
name|Space
condition|)
operator|--
name|ptr
expr_stmt|;
name|int
name|newlen
init|=
name|ptr
operator|-
name|dst
decl_stmt|;
if|if
condition|(
name|isConst
operator|&&
name|newlen
operator|==
name|str
operator|.
name|size
argument_list|()
operator|&&
name|unmodified
condition|)
block|{
comment|// nothing happened, return the original
return|return
name|str
return|;
block|}
name|result
operator|.
name|resize
argument_list|(
name|newlen
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTRINGALGORITHMS_P_H
end_comment
end_unit
