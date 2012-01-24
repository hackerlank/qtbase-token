begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the utils of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|GLOBAL_H
end_ifndef
begin_define
DECL|macro|GLOBAL_H
define|#
directive|define
name|GLOBAL_H
end_define
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_include
include|#
directive|include
file|<QDataStream>
end_include
begin_include
include|#
directive|include
file|<QSet>
end_include
begin_include
include|#
directive|include
file|"configfile.h"
end_include
begin_if
if|#
directive|if
literal|1
end_if
begin_typedef
DECL|typedef|InputType
typedef|typedef
name|int
name|InputType
typedef|;
end_typedef
begin_enum
DECL|enum|SpecialInputType
enum|enum
name|SpecialInputType
block|{
DECL|enumerator|DigitInput
name|DigitInput
block|,
DECL|enumerator|SpaceInput
name|SpaceInput
block|,
DECL|enumerator|Letter
name|Letter
block|}
enum|;
end_enum
begin_else
else|#
directive|else
end_else
begin_enum
DECL|enum|SpecialInputType
enum|enum
name|SpecialInputType
block|{
DECL|enumerator|NoSpecialInput
name|NoSpecialInput
init|=
literal|0
block|,
DECL|enumerator|DigitInput
name|DigitInput
block|,
DECL|enumerator|SpaceInput
name|SpaceInput
block|,
DECL|enumerator|LetterOrNumberInput
name|LetterOrNumberInput
block|}
enum|;
end_enum
begin_struct
DECL|struct|InputType
struct|struct
name|InputType
block|{
DECL|function|InputType
specifier|inline
name|InputType
argument_list|()
operator|:
name|val
argument_list|(
literal|0
argument_list|)
operator|,
name|specialInput
argument_list|(
argument|NoSpecialInput
argument_list|)
block|{}
DECL|function|InputType
specifier|inline
name|InputType
argument_list|(
specifier|const
name|int
operator|&
name|val
argument_list|)
operator|:
name|val
argument_list|(
name|val
argument_list|)
operator|,
name|specialInput
argument_list|(
argument|NoSpecialInput
argument_list|)
block|{}
specifier|inline
name|operator
name|int
argument_list|()
specifier|const
block|{
return|return
name|val
return|;
block|}
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|InputType
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|val
operator|==
name|other
operator|.
name|val
return|;
block|}
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|InputType
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|val
operator|!=
name|other
operator|.
name|val
return|;
block|}
DECL|member|val
name|int
name|val
decl_stmt|;
DECL|member|specialInput
name|SpecialInputType
name|specialInput
decl_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|qHash
specifier|inline
name|int
name|qHash
parameter_list|(
specifier|const
name|InputType
modifier|&
name|t
parameter_list|)
block|{
return|return
name|qHash
argument_list|(
name|t
operator|.
name|val
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|stream
operator|,
specifier|const
name|InputType
operator|&
name|i
operator|)
block|{
return|return
name|stream
operator|<<
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|stream
operator|,
name|InputType
operator|&
name|i
operator|)
block|{
return|return
name|stream
operator|>>
name|i
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|Epsilon
specifier|const
name|InputType
name|Epsilon
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|Config
struct|struct
name|Config
block|{
DECL|function|Config
specifier|inline
name|Config
argument_list|()
operator|:
name|caseSensitivity
argument_list|(
name|Qt
operator|::
name|CaseSensitive
argument_list|)
operator|,
name|debug
argument_list|(
name|false
argument_list|)
operator|,
name|cache
argument_list|(
argument|false
argument_list|)
block|{}
DECL|member|maxInputSet
name|QSet
operator|<
name|InputType
operator|>
name|maxInputSet
expr_stmt|;
DECL|member|caseSensitivity
name|Qt
operator|::
name|CaseSensitivity
name|caseSensitivity
expr_stmt|;
DECL|member|className
name|QString
name|className
decl_stmt|;
DECL|member|debug
name|bool
name|debug
decl_stmt|;
DECL|member|cache
name|bool
name|cache
decl_stmt|;
DECL|member|ruleFile
name|QString
name|ruleFile
decl_stmt|;
DECL|member|configSections
name|ConfigFile
operator|::
name|SectionMap
name|configSections
expr_stmt|;
block|}
struct|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// GLOBAL_H
end_comment
end_unit
