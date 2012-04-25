begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTRINGBUILDER_H
end_ifndef
begin_define
DECL|macro|QSTRINGBUILDER_H
define|#
directive|define
name|QSTRINGBUILDER_H
end_define
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|// syncqt can not handle the templates in this file, and it doesn't need to
end_comment
begin_comment
comment|// process them anyway because they are internal.
end_comment
begin_pragma
pragma|#
directive|pragma
name|qt_class
name|(
name|QStringBuilder
name|)
end_pragma
begin_pragma
pragma|#
directive|pragma
name|qt_sync_stop_processing
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
expr|struct
DECL|struct|QAbstractConcatenable
name|Q_CORE_EXPORT
name|QAbstractConcatenable
block|{
DECL|member|protected
name|protected
operator|:
DECL|member|len
DECL|member|out
specifier|static
name|void
name|convertFromAscii
argument_list|(
argument|const char *a
argument_list|,
argument|int len
argument_list|,
argument|QChar *&out
argument_list|)
block|;
DECL|function|convertFromAscii
specifier|static
specifier|inline
name|void
name|convertFromAscii
argument_list|(
argument|char a
argument_list|,
argument|QChar *&out
argument_list|)
block|{
operator|*
name|out
operator|++
operator|=
name|QLatin1Char
argument_list|(
name|a
argument_list|)
block|;     }
block|}
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|struct|QConcatenable
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|QConcatenable
block|{}
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|namespace
name|QtStringBuilder
block|{
name|template
operator|<
name|typename
name|A
operator|,
name|typename
name|B
operator|>
expr|struct
name|ConvertToTypeHelper
block|{
typedef|typedef
name|A
name|ConvertTo
typedef|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|ConvertToTypeHelper
operator|<
name|T
operator|,
name|QString
operator|>
block|{
typedef|typedef
name|QString
name|ConvertTo
typedef|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_expr_stmt
DECL|variable|Builder
name|template
operator|<
name|typename
name|Builder
operator|,
name|typename
name|T
operator|>
expr|struct
DECL|struct|QStringBuilderCommon
name|QStringBuilderCommon
block|{
DECL|function|toUpper
name|T
name|toUpper
argument_list|()
specifier|const
block|{
return|return
name|resolved
argument_list|()
operator|.
name|toUpper
argument_list|()
return|;
block|}
DECL|function|toLower
name|T
name|toLower
argument_list|()
specifier|const
block|{
return|return
name|resolved
argument_list|()
operator|.
name|toLower
argument_list|()
return|;
block|}
end_expr_stmt
begin_label
DECL|member|protected
name|protected
label|:
end_label
begin_expr_stmt
specifier|const
name|T
name|resolved
argument_list|()
specifier|const
block|{
return|return
operator|*
name|static_cast
operator|<
specifier|const
name|Builder
operator|*
operator|>
operator|(
name|this
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|Builder
operator|,
name|typename
name|T
operator|>
expr|struct
name|QStringBuilderBase
operator|:
name|public
name|QStringBuilderCommon
operator|<
name|Builder
operator|,
name|T
operator|>
block|{ }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|Builder
operator|>
expr|struct
name|QStringBuilderBase
operator|<
name|Builder
operator|,
name|QString
operator|>
operator|:
name|public
name|QStringBuilderCommon
operator|<
name|Builder
operator|,
name|QString
operator|>
block|{
name|QByteArray
name|toLatin1
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|resolved
argument_list|()
operator|.
name|toLatin1
argument_list|()
return|;
block|}
name|QByteArray
name|toLocal8Bit
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|resolved
argument_list|()
operator|.
name|toLocal8Bit
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|A
operator|,
name|typename
name|B
operator|>
name|class
name|QStringBuilder
operator|:
name|public
name|QStringBuilderBase
operator|<
name|QStringBuilder
operator|<
name|A
operator|,
name|B
operator|>
operator|,
name|typename
name|QtStringBuilder
operator|::
name|ConvertToTypeHelper
operator|<
name|typename
name|QConcatenable
operator|<
name|A
operator|>
operator|::
name|ConvertTo
operator|,
name|typename
name|QConcatenable
operator|<
name|B
operator|>
operator|::
name|ConvertTo
operator|>
operator|::
name|ConvertTo
operator|>
block|{
name|public
operator|:
name|QStringBuilder
argument_list|(
specifier|const
name|A
operator|&
name|a_
argument_list|,
specifier|const
name|B
operator|&
name|b_
argument_list|)
operator|:
name|a
argument_list|(
name|a_
argument_list|)
block|,
name|b
argument_list|(
argument|b_
argument_list|)
block|{}
name|private
operator|:
name|friend
name|class
name|QByteArray
block|;
name|friend
name|class
name|QString
block|;
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|convertTo
argument_list|()
specifier|const
block|{
specifier|const
name|uint
name|len
operator|=
name|QConcatenable
operator|<
name|QStringBuilder
operator|<
name|A
block|,
name|B
operator|>
expr|>
operator|::
name|size
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|T
name|s
argument_list|(
name|len
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
block|;
name|typename
name|T
operator|::
name|iterator
name|d
operator|=
name|s
operator|.
name|data
argument_list|()
block|;
name|typename
name|T
operator|::
name|const_iterator
specifier|const
name|start
operator|=
name|d
block|;
name|QConcatenable
operator|<
name|QStringBuilder
operator|<
name|A
block|,
name|B
operator|>
expr|>
operator|::
name|appendTo
argument_list|(
operator|*
name|this
argument_list|,
name|d
argument_list|)
block|;
if|if
condition|(
operator|!
name|QConcatenable
operator|<
name|QStringBuilder
operator|<
name|A
operator|,
name|B
operator|>
expr|>
operator|::
name|ExactSize
operator|&&
name|int
argument_list|(
name|len
argument_list|)
operator|!=
name|d
operator|-
name|start
condition|)
block|{
comment|// this resize is necessary since we allocate a bit too much
comment|// when dealing with variable sized 8-bit encodings
name|s
operator|.
name|resize
argument_list|(
name|d
operator|-
name|start
argument_list|)
expr_stmt|;
block|}
return|return
name|s
return|;
block|}
end_expr_stmt
begin_typedef
typedef|typedef
name|QConcatenable
operator|<
name|QStringBuilder
operator|<
name|A
operator|,
name|B
operator|>
expr|>
name|Concatenable
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|typename
name|Concatenable
operator|::
name|ConvertTo
name|ConvertTo
expr_stmt|;
end_typedef
begin_label
name|public
label|:
end_label
begin_expr_stmt
name|operator
name|ConvertTo
argument_list|()
specifier|const
block|{
return|return
name|convertTo
operator|<
name|ConvertTo
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|size
argument_list|()
specifier|const
block|{
return|return
name|Concatenable
operator|::
name|size
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|const
name|A
modifier|&
name|a
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|B
modifier|&
name|b
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|template
operator|<
operator|>
name|class
name|QStringBuilder
operator|<
name|QString
operator|,
name|QString
operator|>
operator|:
name|public
name|QStringBuilderBase
operator|<
name|QStringBuilder
operator|<
name|QString
operator|,
name|QString
operator|>
operator|,
name|QString
operator|>
block|{
name|public
operator|:
name|QStringBuilder
argument_list|(
specifier|const
name|QString
operator|&
name|a_
argument_list|,
specifier|const
name|QString
operator|&
name|b_
argument_list|)
operator|:
name|a
argument_list|(
name|a_
argument_list|)
block|,
name|b
argument_list|(
argument|b_
argument_list|)
block|{}
name|operator
name|QString
argument_list|()
specifier|const
block|{
name|QString
name|r
argument_list|(
name|a
argument_list|)
block|;
name|r
operator|+=
name|b
block|;
return|return
name|r
return|;
block|}
specifier|const
name|QString
operator|&
name|a
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|const
name|QString
modifier|&
name|b
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|template
operator|<
operator|>
name|class
name|QStringBuilder
operator|<
name|QByteArray
operator|,
name|QByteArray
operator|>
operator|:
name|public
name|QStringBuilderBase
operator|<
name|QStringBuilder
operator|<
name|QByteArray
operator|,
name|QByteArray
operator|>
operator|,
name|QByteArray
operator|>
block|{
name|public
operator|:
name|QStringBuilder
argument_list|(
specifier|const
name|QByteArray
operator|&
name|a_
argument_list|,
specifier|const
name|QByteArray
operator|&
name|b_
argument_list|)
operator|:
name|a
argument_list|(
name|a_
argument_list|)
block|,
name|b
argument_list|(
argument|b_
argument_list|)
block|{}
name|operator
name|QByteArray
argument_list|()
specifier|const
block|{
name|QByteArray
name|r
argument_list|(
name|a
argument_list|)
block|;
name|r
operator|+=
name|b
block|;
return|return
name|r
return|;
block|}
specifier|const
name|QByteArray
operator|&
name|a
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|const
name|QByteArray
modifier|&
name|b
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|QConcatenable
operator|<
name|char
operator|>
operator|:
name|private
name|QAbstractConcatenable
block|{
typedef|typedef
name|char
name|type
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|QByteArray
name|ConvertTo
typedef|;
end_typedef
begin_enum
enum|enum
block|{
name|ExactSize
init|=
name|true
block|}
enum|;
end_enum
begin_function
specifier|static
name|int
name|size
parameter_list|(
specifier|const
name|char
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CAST_FROM_ASCII
end_ifndef
begin_function
specifier|static
specifier|inline
name|QT_ASCII_CAST_WARN
name|void
name|appendTo
parameter_list|(
specifier|const
name|char
name|c
parameter_list|,
name|QChar
modifier|*
modifier|&
name|out
parameter_list|)
block|{
name|QAbstractConcatenable
operator|::
name|convertFromAscii
argument_list|(
name|c
argument_list|,
name|out
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|static
specifier|inline
name|void
name|appendTo
parameter_list|(
specifier|const
name|char
name|c
parameter_list|,
name|char
modifier|*
modifier|&
name|out
parameter_list|)
block|{
operator|*
name|out
operator|++
operator|=
name|c
expr_stmt|;
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|QConcatenable
operator|<
name|QLatin1Char
operator|>
block|{
typedef|typedef
name|QLatin1Char
name|type
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|QString
name|ConvertTo
typedef|;
end_typedef
begin_enum
enum|enum
block|{
name|ExactSize
init|=
name|true
block|}
enum|;
end_enum
begin_function
specifier|static
name|int
name|size
parameter_list|(
specifier|const
name|QLatin1Char
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|void
name|appendTo
parameter_list|(
specifier|const
name|QLatin1Char
name|c
parameter_list|,
name|QChar
modifier|*
modifier|&
name|out
parameter_list|)
block|{
operator|*
name|out
operator|++
operator|=
name|c
expr_stmt|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|void
name|appendTo
parameter_list|(
specifier|const
name|QLatin1Char
name|c
parameter_list|,
name|char
modifier|*
modifier|&
name|out
parameter_list|)
block|{
operator|*
name|out
operator|++
operator|=
name|c
operator|.
name|toLatin1
argument_list|()
expr_stmt|;
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|QConcatenable
operator|<
name|QChar
operator|>
operator|:
name|private
name|QAbstractConcatenable
block|{
typedef|typedef
name|QChar
name|type
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|QString
name|ConvertTo
typedef|;
end_typedef
begin_enum
enum|enum
block|{
name|ExactSize
init|=
name|true
block|}
enum|;
end_enum
begin_function
specifier|static
name|int
name|size
parameter_list|(
specifier|const
name|QChar
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|void
name|appendTo
parameter_list|(
specifier|const
name|QChar
name|c
parameter_list|,
name|QChar
modifier|*
modifier|&
name|out
parameter_list|)
block|{
operator|*
name|out
operator|++
operator|=
name|c
expr_stmt|;
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|QConcatenable
operator|<
name|QChar
operator|::
name|SpecialCharacter
operator|>
operator|:
name|private
name|QAbstractConcatenable
block|{
typedef|typedef
name|QChar
operator|::
name|SpecialCharacter
name|type
expr_stmt|;
end_expr_stmt
begin_typedef
typedef|typedef
name|QString
name|ConvertTo
typedef|;
end_typedef
begin_enum
enum|enum
block|{
name|ExactSize
init|=
name|true
block|}
enum|;
end_enum
begin_decl_stmt
specifier|static
name|int
name|size
argument_list|(
specifier|const
name|QChar
operator|::
name|SpecialCharacter
argument_list|)
block|{
return|return
literal|1
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|static
specifier|inline
name|void
name|appendTo
argument_list|(
specifier|const
name|QChar
operator|::
name|SpecialCharacter
name|c
argument_list|,
name|QChar
operator|*
operator|&
name|out
argument_list|)
block|{
operator|*
name|out
operator|++
operator|=
name|c
expr_stmt|;
block|}
end_decl_stmt
begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|QConcatenable
operator|<
name|QCharRef
operator|>
operator|:
name|private
name|QAbstractConcatenable
block|{
typedef|typedef
name|QCharRef
name|type
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|QString
name|ConvertTo
typedef|;
end_typedef
begin_enum
enum|enum
block|{
name|ExactSize
init|=
name|true
block|}
enum|;
end_enum
begin_function
specifier|static
name|int
name|size
parameter_list|(
specifier|const
name|QCharRef
modifier|&
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|void
name|appendTo
parameter_list|(
specifier|const
name|QCharRef
modifier|&
name|c
parameter_list|,
name|QChar
modifier|*
modifier|&
name|out
parameter_list|)
block|{
operator|*
name|out
operator|++
operator|=
name|QChar
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|QConcatenable
operator|<
name|QLatin1String
operator|>
block|{
typedef|typedef
name|QLatin1String
name|type
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|QString
name|ConvertTo
typedef|;
end_typedef
begin_enum
enum|enum
block|{
name|ExactSize
init|=
name|true
block|}
enum|;
end_enum
begin_function
specifier|static
name|int
name|size
parameter_list|(
specifier|const
name|QLatin1String
modifier|&
name|a
parameter_list|)
block|{
return|return
name|a
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|void
name|appendTo
parameter_list|(
specifier|const
name|QLatin1String
modifier|&
name|a
parameter_list|,
name|QChar
modifier|*
modifier|&
name|out
parameter_list|)
block|{
for|for
control|(
specifier|const
name|char
modifier|*
name|s
init|=
name|a
operator|.
name|data
argument_list|()
init|;
operator|*
name|s
condition|;
control|)
operator|*
name|out
operator|++
operator|=
name|QLatin1Char
argument_list|(
operator|*
name|s
operator|++
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|void
name|appendTo
parameter_list|(
specifier|const
name|QLatin1String
modifier|&
name|a
parameter_list|,
name|char
modifier|*
modifier|&
name|out
parameter_list|)
block|{
for|for
control|(
specifier|const
name|char
modifier|*
name|s
init|=
name|a
operator|.
name|data
argument_list|()
init|;
operator|*
name|s
condition|;
control|)
operator|*
name|out
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|QConcatenable
operator|<
name|QString
operator|>
operator|:
name|private
name|QAbstractConcatenable
block|{
typedef|typedef
name|QString
name|type
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|QString
name|ConvertTo
typedef|;
end_typedef
begin_enum
enum|enum
block|{
name|ExactSize
init|=
name|true
block|}
enum|;
end_enum
begin_function
specifier|static
name|int
name|size
parameter_list|(
specifier|const
name|QString
modifier|&
name|a
parameter_list|)
block|{
return|return
name|a
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|void
name|appendTo
parameter_list|(
specifier|const
name|QString
modifier|&
name|a
parameter_list|,
name|QChar
modifier|*
modifier|&
name|out
parameter_list|)
block|{
specifier|const
name|int
name|n
init|=
name|a
operator|.
name|size
argument_list|()
decl_stmt|;
name|memcpy
argument_list|(
name|out
argument_list|,
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|a
operator|.
name|constData
argument_list|()
operator|)
argument_list|,
sizeof|sizeof
argument_list|(
name|QChar
argument_list|)
operator|*
name|n
argument_list|)
expr_stmt|;
name|out
operator|+=
name|n
expr_stmt|;
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|QConcatenable
operator|<
name|QStringRef
operator|>
operator|:
name|private
name|QAbstractConcatenable
block|{
typedef|typedef
name|QStringRef
name|type
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|QString
name|ConvertTo
typedef|;
end_typedef
begin_enum
enum|enum
block|{
name|ExactSize
init|=
name|true
block|}
enum|;
end_enum
begin_function
specifier|static
name|int
name|size
parameter_list|(
specifier|const
name|QStringRef
modifier|&
name|a
parameter_list|)
block|{
return|return
name|a
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|void
name|appendTo
parameter_list|(
specifier|const
name|QStringRef
modifier|&
name|a
parameter_list|,
name|QChar
modifier|*
modifier|&
name|out
parameter_list|)
block|{
specifier|const
name|int
name|n
init|=
name|a
operator|.
name|size
argument_list|()
decl_stmt|;
name|memcpy
argument_list|(
name|out
argument_list|,
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|a
operator|.
name|constData
argument_list|()
operator|)
argument_list|,
sizeof|sizeof
argument_list|(
name|QChar
argument_list|)
operator|*
name|n
argument_list|)
expr_stmt|;
name|out
operator|+=
name|n
expr_stmt|;
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
name|int
name|N
operator|>
expr|struct
name|QConcatenable
operator|<
name|char
index|[
name|N
index|]
operator|>
operator|:
name|private
name|QAbstractConcatenable
block|{
typedef|typedef
name|char
name|type
index|[
name|N
index|]
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|QByteArray
name|ConvertTo
typedef|;
end_typedef
begin_enum
enum|enum
block|{
name|ExactSize
init|=
name|false
block|}
enum|;
end_enum
begin_function
specifier|static
name|int
name|size
parameter_list|(
specifier|const
name|char
index|[
name|N
index|]
parameter_list|)
block|{
return|return
name|N
operator|-
literal|1
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CAST_FROM_ASCII
end_ifndef
begin_function
specifier|static
specifier|inline
name|void
name|QT_ASCII_CAST_WARN
name|appendTo
parameter_list|(
specifier|const
name|char
name|a
index|[
name|N
index|]
parameter_list|,
name|QChar
modifier|*
modifier|&
name|out
parameter_list|)
block|{
name|QAbstractConcatenable
operator|::
name|convertFromAscii
argument_list|(
name|a
argument_list|,
name|N
operator|-
literal|1
argument_list|,
name|out
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|static
specifier|inline
name|void
name|appendTo
parameter_list|(
specifier|const
name|char
name|a
index|[
name|N
index|]
parameter_list|,
name|char
modifier|*
modifier|&
name|out
parameter_list|)
block|{
while|while
condition|(
operator|*
name|a
condition|)
operator|*
name|out
operator|++
operator|=
operator|*
name|a
operator|++
expr_stmt|;
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
name|int
name|N
operator|>
expr|struct
name|QConcatenable
operator|<
specifier|const
name|char
index|[
name|N
index|]
operator|>
operator|:
name|private
name|QAbstractConcatenable
block|{
typedef|typedef
specifier|const
name|char
name|type
index|[
name|N
index|]
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|QByteArray
name|ConvertTo
typedef|;
end_typedef
begin_enum
enum|enum
block|{
name|ExactSize
init|=
name|false
block|}
enum|;
end_enum
begin_function
specifier|static
name|int
name|size
parameter_list|(
specifier|const
name|char
index|[
name|N
index|]
parameter_list|)
block|{
return|return
name|N
operator|-
literal|1
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CAST_FROM_ASCII
end_ifndef
begin_function
specifier|static
specifier|inline
name|void
name|QT_ASCII_CAST_WARN
name|appendTo
parameter_list|(
specifier|const
name|char
name|a
index|[
name|N
index|]
parameter_list|,
name|QChar
modifier|*
modifier|&
name|out
parameter_list|)
block|{
name|QAbstractConcatenable
operator|::
name|convertFromAscii
argument_list|(
name|a
argument_list|,
name|N
operator|-
literal|1
argument_list|,
name|out
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|static
specifier|inline
name|void
name|appendTo
parameter_list|(
specifier|const
name|char
name|a
index|[
name|N
index|]
parameter_list|,
name|char
modifier|*
modifier|&
name|out
parameter_list|)
block|{
while|while
condition|(
operator|*
name|a
condition|)
operator|*
name|out
operator|++
operator|=
operator|*
name|a
operator|++
expr_stmt|;
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|QConcatenable
operator|<
specifier|const
name|char
operator|*
operator|>
operator|:
name|private
name|QAbstractConcatenable
block|{
typedef|typedef
name|char
specifier|const
modifier|*
name|type
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|QByteArray
name|ConvertTo
typedef|;
end_typedef
begin_enum
enum|enum
block|{
name|ExactSize
init|=
name|false
block|}
enum|;
end_enum
begin_function
specifier|static
name|int
name|size
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|)
block|{
return|return
name|qstrlen
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CAST_FROM_ASCII
end_ifndef
begin_function
specifier|static
specifier|inline
name|void
name|QT_ASCII_CAST_WARN
name|appendTo
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
name|QChar
modifier|*
modifier|&
name|out
parameter_list|)
block|{
name|QAbstractConcatenable
operator|::
name|convertFromAscii
argument_list|(
name|a
argument_list|,
operator|-
literal|1
argument_list|,
name|out
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|static
specifier|inline
name|void
name|appendTo
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
name|char
modifier|*
modifier|&
name|out
parameter_list|)
block|{
if|if
condition|(
operator|!
name|a
condition|)
return|return;
while|while
condition|(
operator|*
name|a
condition|)
operator|*
name|out
operator|++
operator|=
operator|*
name|a
operator|++
expr_stmt|;
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|QConcatenable
operator|<
name|QByteArray
operator|>
operator|:
name|private
name|QAbstractConcatenable
block|{
typedef|typedef
name|QByteArray
name|type
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|QByteArray
name|ConvertTo
typedef|;
end_typedef
begin_enum
enum|enum
block|{
name|ExactSize
init|=
name|false
block|}
enum|;
end_enum
begin_function
specifier|static
name|int
name|size
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ba
parameter_list|)
block|{
return|return
name|ba
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CAST_FROM_ASCII
end_ifndef
begin_function
specifier|static
specifier|inline
name|QT_ASCII_CAST_WARN
name|void
name|appendTo
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ba
parameter_list|,
name|QChar
modifier|*
modifier|&
name|out
parameter_list|)
block|{
name|QAbstractConcatenable
operator|::
name|convertFromAscii
argument_list|(
name|ba
operator|.
name|constData
argument_list|()
argument_list|,
name|ba
operator|.
name|size
argument_list|()
argument_list|,
name|out
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|static
specifier|inline
name|void
name|appendTo
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ba
parameter_list|,
name|char
modifier|*
modifier|&
name|out
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|a
init|=
name|ba
operator|.
name|constData
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|end
init|=
name|ba
operator|.
name|end
argument_list|()
decl_stmt|;
while|while
condition|(
name|a
operator|!=
name|end
condition|)
operator|*
name|out
operator|++
operator|=
operator|*
name|a
operator|++
expr_stmt|;
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|A
operator|,
name|typename
name|B
operator|>
expr|struct
name|QConcatenable
operator|<
name|QStringBuilder
operator|<
name|A
operator|,
name|B
operator|>
expr|>
block|{
typedef|typedef
name|QStringBuilder
operator|<
name|A
operator|,
name|B
operator|>
name|type
expr_stmt|;
end_expr_stmt
begin_typedef
typedef|typedef
name|typename
name|QtStringBuilder
operator|::
name|ConvertToTypeHelper
operator|<
name|typename
name|QConcatenable
operator|<
name|A
operator|>
operator|::
name|ConvertTo
operator|,
name|typename
name|QConcatenable
operator|<
name|B
operator|>
operator|::
name|ConvertTo
operator|>
operator|::
name|ConvertTo
name|ConvertTo
expr_stmt|;
end_typedef
begin_enum
enum|enum
block|{
name|ExactSize
init|=
name|QConcatenable
operator|<
name|A
operator|>
operator|::
name|ExactSize
operator|&&
name|QConcatenable
operator|<
name|B
operator|>
operator|::
name|ExactSize
block|}
enum|;
end_enum
begin_function
specifier|static
name|int
name|size
parameter_list|(
specifier|const
name|type
modifier|&
name|p
parameter_list|)
block|{
return|return
name|QConcatenable
operator|<
name|A
operator|>
operator|::
name|size
argument_list|(
name|p
operator|.
name|a
argument_list|)
operator|+
name|QConcatenable
operator|<
name|B
operator|>
operator|::
name|size
argument_list|(
name|p
operator|.
name|b
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|void
name|appendTo
argument_list|(
argument|const type&p
argument_list|,
argument|T *&out
argument_list|)
block|{
name|QConcatenable
operator|<
name|A
operator|>
operator|::
name|appendTo
argument_list|(
name|p
operator|.
name|a
argument_list|,
name|out
argument_list|)
block|;
name|QConcatenable
operator|<
name|B
operator|>
operator|::
name|appendTo
argument_list|(
name|p
operator|.
name|b
argument_list|,
name|out
argument_list|)
block|;     }
end_expr_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|A
operator|,
name|typename
name|B
operator|>
name|QStringBuilder
operator|<
name|typename
name|QConcatenable
operator|<
name|A
operator|>
operator|::
name|type
operator|,
name|typename
name|QConcatenable
operator|<
name|B
operator|>
operator|::
name|type
operator|>
name|operator
operator|%
operator|(
specifier|const
name|A
operator|&
name|a
operator|,
specifier|const
name|B
operator|&
name|b
operator|)
block|{
return|return
name|QStringBuilder
operator|<
name|typename
name|QConcatenable
operator|<
name|A
operator|>
operator|::
name|type
operator|,
name|typename
name|QConcatenable
operator|<
name|B
operator|>
operator|::
name|type
operator|>
operator|(
name|a
operator|,
name|b
operator|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// QT_USE_FAST_OPERATOR_PLUS was introduced in 4.7, QT_USE_QSTRINGBUILDER is to be used from 4.8 onwards
end_comment
begin_comment
comment|// QT_USE_FAST_OPERATOR_PLUS does not remove the normal operator+ for QByteArray
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_USE_FAST_OPERATOR_PLUS
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_USE_QSTRINGBUILDER
argument_list|)
end_if
begin_expr_stmt
name|template
operator|<
name|typename
name|A
operator|,
name|typename
name|B
operator|>
name|QStringBuilder
operator|<
name|typename
name|QConcatenable
operator|<
name|A
operator|>
operator|::
name|type
operator|,
name|typename
name|QConcatenable
operator|<
name|B
operator|>
operator|::
name|type
operator|>
name|operator
operator|+
operator|(
specifier|const
name|A
operator|&
name|a
operator|,
specifier|const
name|B
operator|&
name|b
operator|)
block|{
return|return
name|QStringBuilder
operator|<
name|typename
name|QConcatenable
operator|<
name|A
operator|>
operator|::
name|type
operator|,
name|typename
name|QConcatenable
operator|<
name|B
operator|>
operator|::
name|type
operator|>
operator|(
name|a
operator|,
name|b
operator|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|namespace
name|QtStringBuilder
block|{
name|template
operator|<
name|typename
name|A
operator|,
name|typename
name|B
operator|>
name|QByteArray
operator|&
name|appendToByteArray
argument_list|(
argument|QByteArray&a
argument_list|,
argument|const QStringBuilder<A
argument_list|,
argument|B>&b
argument_list|,
argument|char
argument_list|)
block|{
comment|// append 8-bit data to a byte array
name|int
name|len
operator|=
name|a
operator|.
name|size
argument_list|()
operator|+
name|QConcatenable
operator|<
name|QStringBuilder
operator|<
name|A
block|,
name|B
operator|>
expr|>
operator|::
name|size
argument_list|(
name|b
argument_list|)
block|;
name|a
operator|.
name|reserve
argument_list|(
name|len
argument_list|)
block|;
name|char
operator|*
name|it
operator|=
name|a
operator|.
name|data
argument_list|()
operator|+
name|a
operator|.
name|size
argument_list|()
block|;
name|QConcatenable
operator|<
name|QStringBuilder
operator|<
name|A
block|,
name|B
operator|>
expr|>
operator|::
name|appendTo
argument_list|(
name|b
argument_list|,
name|it
argument_list|)
block|;
name|a
operator|.
name|resize
argument_list|(
name|len
argument_list|)
block|;
comment|//we need to resize after the appendTo for the case str+=foo+str
return|return
name|a
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_CAST_TO_ASCII
name|template
operator|<
name|typename
name|A
operator|,
name|typename
name|B
operator|>
name|QByteArray
operator|&
name|appendToByteArray
argument_list|(
argument|QByteArray&a
argument_list|,
argument|const QStringBuilder<A
argument_list|,
argument|B>&b
argument_list|,
argument|QChar
argument_list|)
block|{
comment|// append UTF-16 data to the byte array
return|return
name|a
operator|+=
name|QString
argument_list|(
name|b
argument_list|)
return|;
block|}
endif|#
directive|endif
block|}
end_decl_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|A
operator|,
name|typename
name|B
operator|>
name|QByteArray
operator|&
name|operator
operator|+=
operator|(
name|QByteArray
operator|&
name|a
operator|,
specifier|const
name|QStringBuilder
operator|<
name|A
operator|,
name|B
operator|>
operator|&
name|b
operator|)
block|{
return|return
name|QtStringBuilder
operator|::
name|appendToByteArray
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|,
argument|typename QConcatenable< QStringBuilder<A
argument_list|,
argument|B>>::ConvertTo::value_type()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|A
operator|,
name|typename
name|B
operator|>
name|QString
operator|&
name|operator
operator|+=
operator|(
name|QString
operator|&
name|a
operator|,
specifier|const
name|QStringBuilder
operator|<
name|A
operator|,
name|B
operator|>
operator|&
name|b
operator|)
block|{
name|int
name|len
operator|=
name|a
operator|.
name|size
argument_list|()
operator|+
name|QConcatenable
operator|<
name|QStringBuilder
operator|<
name|A
block|,
name|B
operator|>
expr|>
operator|::
name|size
argument_list|(
name|b
argument_list|)
block|;
name|a
operator|.
name|reserve
argument_list|(
name|len
argument_list|)
block|;
name|QChar
operator|*
name|it
operator|=
name|a
operator|.
name|data
argument_list|()
operator|+
name|a
operator|.
name|size
argument_list|()
block|;
name|QConcatenable
operator|<
name|QStringBuilder
operator|<
name|A
block|,
name|B
operator|>
expr|>
operator|::
name|appendTo
argument_list|(
name|b
argument_list|,
name|it
argument_list|)
block|;
name|a
operator|.
name|resize
argument_list|(
name|it
operator|-
name|a
operator|.
name|constData
argument_list|()
argument_list|)
block|;
comment|//may be smaller than len if there was conversion from utf8
return|return
name|a
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTRINGBUILDER_H
end_comment
end_unit
