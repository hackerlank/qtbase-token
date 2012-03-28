begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFLAGS_H
end_ifndef
begin_define
DECL|macro|QFLAGS_H
define|#
directive|define
name|QFLAGS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|class
name|Q_CORE_EXPORT
name|QFlag
block|{
name|int
name|i
decl_stmt|;
name|public
label|:
specifier|inline
name|QFlag
argument_list|(
argument|int i
argument_list|)
expr_stmt|;
specifier|inline
name|operator
name|int
argument_list|()
specifier|const
block|{
return|return
name|i
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|QFlag
specifier|inline
name|QFlag
operator|::
name|QFlag
argument_list|(
argument|int ai
argument_list|)
operator|:
name|i
argument_list|(
argument|ai
argument_list|)
block|{}
name|class
name|Q_CORE_EXPORT
name|QIncompatibleFlag
block|{
name|int
name|i
block|;
name|public
operator|:
specifier|inline
name|explicit
name|QIncompatibleFlag
argument_list|(
argument|int i
argument_list|)
block|;
specifier|inline
name|operator
name|int
argument_list|()
specifier|const
block|{
return|return
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
unit|};
DECL|function|QIncompatibleFlag
specifier|inline
name|QIncompatibleFlag
operator|::
name|QIncompatibleFlag
argument_list|(
argument|int ai
argument_list|)
operator|:
name|i
argument_list|(
argument|ai
argument_list|)
block|{}
ifndef|#
directive|ifndef
name|Q_NO_TYPESAFE_FLAGS
name|template
operator|<
name|typename
name|Enum
operator|>
name|class
name|QFlags
block|{
typedef|typedef
name|void
modifier|*
modifier|*
name|Zero
typedef|;
name|int
name|i
expr_stmt|;
end_expr_stmt
begin_label
name|public
label|:
end_label
begin_typedef
typedef|typedef
name|Enum
name|enum_type
typedef|;
end_typedef
begin_comment
comment|// compiler-generated copy/move ctor/assignment operators are fine!
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|qdoc
end_ifdef
begin_expr_stmt
specifier|inline
name|QFlags
argument_list|(
specifier|const
name|QFlags
operator|&
name|other
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|inline
name|QFlags
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QFlags
operator|&
name|other
operator|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|Q_DECL_CONSTEXPR
end_macro
begin_expr_stmt
specifier|inline
name|QFlags
argument_list|(
argument|Enum f
argument_list|)
operator|:
name|i
argument_list|(
argument|f
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
argument_list|(
name|Zero
operator|=
literal|0
argument_list|)
operator|:
name|i
argument_list|(
literal|0
argument_list|)
block|{}
specifier|inline
name|QFlags
argument_list|(
argument|QFlag f
argument_list|)
operator|:
name|i
argument_list|(
argument|f
argument_list|)
block|{}
specifier|inline
name|QFlags
operator|&
name|operator
operator|&=
operator|(
name|int
name|mask
operator|)
block|{
name|i
operator|&=
name|mask
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QFlags
operator|&
name|operator
operator|&=
operator|(
name|uint
name|mask
operator|)
block|{
name|i
operator|&=
name|mask
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QFlags
operator|&
name|operator
operator||=
operator|(
name|QFlags
name|f
operator|)
block|{
name|i
operator||=
name|f
operator|.
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QFlags
operator|&
name|operator
operator||=
operator|(
name|Enum
name|f
operator|)
block|{
name|i
operator||=
name|f
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QFlags
operator|&
name|operator
operator|^=
operator|(
name|QFlags
name|f
operator|)
block|{
name|i
operator|^=
name|f
operator|.
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QFlags
operator|&
name|operator
operator|^=
operator|(
name|Enum
name|f
operator|)
block|{
name|i
operator|^=
name|f
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|operator
name|int
argument_list|()
specifier|const
block|{
return|return
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
name|operator
operator||
operator|(
name|QFlags
name|f
operator|)
specifier|const
block|{
return|return
name|QFlags
argument_list|(
name|Enum
argument_list|(
name|i
operator||
name|f
operator|.
name|i
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
name|operator
operator||
operator|(
name|Enum
name|f
operator|)
specifier|const
block|{
return|return
name|QFlags
argument_list|(
name|Enum
argument_list|(
name|i
operator||
name|f
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
name|operator
modifier|^
argument_list|(
name|QFlags
name|f
argument_list|)
decl|const
block|{
return|return
name|QFlags
argument_list|(
name|Enum
argument_list|(
name|i
operator|^
name|f
operator|.
name|i
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
name|operator
modifier|^
argument_list|(
name|Enum
name|f
argument_list|)
decl|const
block|{
return|return
name|QFlags
argument_list|(
name|Enum
argument_list|(
name|i
operator|^
name|f
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
name|operator
modifier|&
argument_list|(
name|int
name|mask
argument_list|)
decl|const
block|{
return|return
name|QFlags
argument_list|(
name|Enum
argument_list|(
name|i
operator|&
name|mask
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
name|operator
modifier|&
argument_list|(
name|uint
name|mask
argument_list|)
decl|const
block|{
return|return
name|QFlags
argument_list|(
name|Enum
argument_list|(
name|i
operator|&
name|mask
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
name|operator
modifier|&
argument_list|(
name|Enum
name|f
argument_list|)
decl|const
block|{
return|return
name|QFlags
argument_list|(
name|Enum
argument_list|(
name|i
operator|&
name|f
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
name|operator
operator|~
operator|(
operator|)
specifier|const
block|{
return|return
name|QFlags
argument_list|(
name|Enum
argument_list|(
operator|~
name|i
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
operator|!
name|i
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|inline
name|bool
name|testFlag
argument_list|(
name|Enum
name|f
argument_list|)
decl|const
block|{
return|return
operator|(
name|i
operator|&
name|f
operator|)
operator|==
name|f
operator|&&
operator|(
name|f
operator|!=
literal|0
operator|||
name|i
operator|==
name|int
argument_list|(
name|f
argument_list|)
operator|)
return|;
block|}
end_decl_stmt
begin_define
DECL|macro|Q_DECLARE_FLAGS
unit|};
define|#
directive|define
name|Q_DECLARE_FLAGS
parameter_list|(
name|Flags
parameter_list|,
name|Enum
parameter_list|)
define|\
value|typedef QFlags<Enum> Flags;
end_define
begin_define
DECL|macro|Q_DECLARE_INCOMPATIBLE_FLAGS
define|#
directive|define
name|Q_DECLARE_INCOMPATIBLE_FLAGS
parameter_list|(
name|Flags
parameter_list|)
define|\
value|inline QIncompatibleFlag operator|(Flags::enum_type f1, int f2) \ { return QIncompatibleFlag(int(f1) | f2); }
end_define
begin_define
DECL|macro|Q_DECLARE_OPERATORS_FOR_FLAGS
define|#
directive|define
name|Q_DECLARE_OPERATORS_FOR_FLAGS
parameter_list|(
name|Flags
parameter_list|)
define|\
value|Q_DECL_CONSTEXPR inline QFlags<Flags::enum_type> operator|(Flags::enum_type f1, Flags::enum_type f2) \ { return QFlags<Flags::enum_type>(f1) | f2; } \ Q_DECL_CONSTEXPR inline QFlags<Flags::enum_type> operator|(Flags::enum_type f1, QFlags<Flags::enum_type> f2) \ { return f2 | f1; } Q_DECLARE_INCOMPATIBLE_FLAGS(Flags)
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* Q_NO_TYPESAFE_FLAGS */
end_comment
begin_define
DECL|macro|Q_DECLARE_FLAGS
define|#
directive|define
name|Q_DECLARE_FLAGS
parameter_list|(
name|Flags
parameter_list|,
name|Enum
parameter_list|)
define|\
value|typedef uint Flags;
end_define
begin_define
DECL|macro|Q_DECLARE_OPERATORS_FOR_FLAGS
define|#
directive|define
name|Q_DECLARE_OPERATORS_FOR_FLAGS
parameter_list|(
name|Flags
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Q_NO_TYPESAFE_FLAGS */
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFLAGS_H
end_comment
end_unit
