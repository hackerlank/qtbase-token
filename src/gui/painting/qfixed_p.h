begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFIXED_P_H
end_ifndef
begin_define
DECL|macro|QFIXED_P_H
define|#
directive|define
name|QFIXED_P_H
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
comment|// of other Qt classes.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|"QtCore/qdebug.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpoint.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qsize.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QFixed
struct|struct
name|QFixed
block|{
DECL|member|private
name|private
label|:
name|Q_DECL_CONSTEXPR
name|QFixed
argument_list|(
argument|int val
argument_list|,
argument|int
argument_list|)
block|:
name|val
argument_list|(
argument|val
argument_list|)
block|{}
comment|// 2nd int is just a dummy for disambiguation
name|public
label|:
name|Q_DECL_CONSTEXPR
name|QFixed
argument_list|()
operator|:
name|val
argument_list|(
literal|0
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
name|QFixed
argument_list|(
argument|int i
argument_list|)
operator|:
name|val
argument_list|(
argument|i *
literal|64
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
name|QFixed
argument_list|(
argument|long i
argument_list|)
operator|:
name|val
argument_list|(
argument|i *
literal|64
argument_list|)
block|{}
name|QFixed
operator|&
name|operator
operator|=
operator|(
name|int
name|i
operator|)
block|{
name|val
operator|=
name|i
operator|*
literal|64
block|;
return|return
operator|*
name|this
return|;
block|}
DECL|variable|operator
name|QFixed
modifier|&
name|operator
init|=
operator|(
name|long
name|i
operator|)
block|{
name|val
operator|=
name|i
operator|*
literal|64
block|;
return|return
operator|*
name|this
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|static
name|QFixed
name|fromReal
parameter_list|(
name|qreal
name|r
parameter_list|)
block|{
return|return
name|fromFixed
argument_list|(
call|(
name|int
call|)
argument_list|(
name|r
operator|*
name|qreal
argument_list|(
literal|64
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|static
name|QFixed
name|fromFixed
parameter_list|(
name|int
name|fixed
parameter_list|)
block|{
return|return
name|QFixed
argument_list|(
name|fixed
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|// uses private ctor
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|value
argument_list|()
specifier|const
block|{
return|return
name|val
return|;
block|}
specifier|inline
name|void
name|setValue
parameter_list|(
name|int
name|value
parameter_list|)
block|{
name|val
operator|=
name|value
expr_stmt|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|toInt
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
operator|(
name|val
operator|)
operator|+
literal|32
operator|)
operator|&
operator|-
literal|64
operator|)
operator|>>
literal|6
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|qreal
name|toReal
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|qreal
operator|)
name|val
operator|)
operator|/
operator|(
name|qreal
operator|)
literal|64
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|truncate
argument_list|()
specifier|const
block|{
return|return
name|val
operator|>>
literal|6
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixed
name|round
argument_list|()
specifier|const
block|{
return|return
name|fromFixed
argument_list|(
operator|(
operator|(
name|val
operator|)
operator|+
literal|32
operator|)
operator|&
operator|-
literal|64
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixed
name|floor
argument_list|()
specifier|const
block|{
return|return
name|fromFixed
argument_list|(
operator|(
name|val
operator|)
operator|&
operator|-
literal|64
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixed
name|ceil
argument_list|()
specifier|const
block|{
return|return
name|fromFixed
argument_list|(
operator|(
name|val
operator|+
literal|63
operator|)
operator|&
operator|-
literal|64
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixed
name|operator
operator|+
operator|(
name|int
name|i
operator|)
specifier|const
block|{
return|return
name|fromFixed
argument_list|(
name|val
operator|+
name|i
operator|*
literal|64
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixed
name|operator
operator|+
operator|(
name|uint
name|i
operator|)
specifier|const
block|{
return|return
name|fromFixed
argument_list|(
operator|(
name|val
operator|+
operator|(
name|i
operator|<<
literal|6
operator|)
operator|)
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixed
name|operator
operator|+
operator|(
specifier|const
name|QFixed
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|fromFixed
argument_list|(
operator|(
name|val
operator|+
name|other
operator|.
name|val
operator|)
argument_list|)
return|;
block|}
specifier|inline
name|QFixed
operator|&
name|operator
operator|+=
operator|(
name|int
name|i
operator|)
block|{
name|val
operator|+=
name|i
operator|*
literal|64
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QFixed
operator|&
name|operator
operator|+=
operator|(
name|uint
name|i
operator|)
block|{
name|val
operator|+=
operator|(
name|i
operator|<<
literal|6
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QFixed
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|QFixed
operator|&
name|other
operator|)
block|{
name|val
operator|+=
name|other
operator|.
name|val
block|;
return|return
operator|*
name|this
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixed
name|operator
operator|-
operator|(
name|int
name|i
operator|)
specifier|const
block|{
return|return
name|fromFixed
argument_list|(
name|val
operator|-
name|i
operator|*
literal|64
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixed
name|operator
operator|-
operator|(
name|uint
name|i
operator|)
specifier|const
block|{
return|return
name|fromFixed
argument_list|(
operator|(
name|val
operator|-
operator|(
name|i
operator|<<
literal|6
operator|)
operator|)
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixed
name|operator
operator|-
operator|(
specifier|const
name|QFixed
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|fromFixed
argument_list|(
operator|(
name|val
operator|-
name|other
operator|.
name|val
operator|)
argument_list|)
return|;
block|}
specifier|inline
name|QFixed
operator|&
name|operator
operator|-=
operator|(
name|int
name|i
operator|)
block|{
name|val
operator|-=
name|i
operator|*
literal|64
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QFixed
operator|&
name|operator
operator|-=
operator|(
name|uint
name|i
operator|)
block|{
name|val
operator|-=
operator|(
name|i
operator|<<
literal|6
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QFixed
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|QFixed
operator|&
name|other
operator|)
block|{
name|val
operator|-=
name|other
operator|.
name|val
block|;
return|return
operator|*
name|this
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixed
name|operator
operator|-
operator|(
operator|)
specifier|const
block|{
return|return
name|fromFixed
argument_list|(
operator|-
name|val
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QFixed
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
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QFixed
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
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QFixed
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|val
operator|<
name|other
operator|.
name|val
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|QFixed
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|val
operator|>
name|other
operator|.
name|val
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|QFixed
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|val
operator|<=
name|other
operator|.
name|val
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|QFixed
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|val
operator|>=
name|other
operator|.
name|val
return|;
block|}
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
name|val
return|;
block|}
specifier|inline
name|QFixed
operator|&
name|operator
operator|/=
operator|(
name|int
name|x
operator|)
block|{
name|val
operator|/=
name|x
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QFixed
operator|&
name|operator
operator|/=
operator|(
specifier|const
name|QFixed
operator|&
name|o
operator|)
block|{
if|if
condition|(
name|o
operator|.
name|val
operator|==
literal|0
condition|)
block|{
name|val
operator|=
literal|0x7FFFFFFFL
expr_stmt|;
block|}
else|else
block|{
name|bool
name|neg
init|=
name|false
decl_stmt|;
name|qint64
name|a
init|=
name|val
decl_stmt|;
name|qint64
name|b
init|=
name|o
operator|.
name|val
decl_stmt|;
if|if
condition|(
name|a
operator|<
literal|0
condition|)
block|{
name|a
operator|=
operator|-
name|a
expr_stmt|;
name|neg
operator|=
name|true
expr_stmt|;
block|}
if|if
condition|(
name|b
operator|<
literal|0
condition|)
block|{
name|b
operator|=
operator|-
name|b
expr_stmt|;
name|neg
operator|=
operator|!
name|neg
expr_stmt|;
block|}
name|int
name|res
init|=
call|(
name|int
call|)
argument_list|(
operator|(
operator|(
name|a
operator|<<
literal|6
operator|)
operator|+
operator|(
name|b
operator|>>
literal|1
operator|)
operator|)
operator|/
name|b
argument_list|)
decl_stmt|;
name|val
operator|=
operator|(
name|neg
condition|?
operator|-
name|res
else|:
name|res
operator|)
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
namespace|QFixed
name|operator
namespace|/(
name|int
name|d
struct|)
specifier|const
block|{
return|return
name|fromFixed
argument_list|(
name|val
operator|/
name|d
argument_list|)
return|;
block|}
specifier|inline
namespace|QFixed
name|operator
namespace|/(
name|QFixed
name|b
struct|)
specifier|const
block|{
name|QFixed
name|f
operator|=
operator|*
name|this
block|;
return|return
operator|(
name|f
operator|/=
name|b
operator|)
return|;
block|}
specifier|inline
namespace|QFixed
name|operator
namespace|>>(
name|int
name|d
struct|)
specifier|const
block|{
name|QFixed
name|f
operator|=
operator|*
name|this
block|;
name|f
operator|.
name|val
operator|>>=
name|d
block|;
return|return
name|f
return|;
block|}
specifier|inline
namespace|QFixed&
name|operator
namespace|*=(
name|int
name|i
struct|)
block|{
name|val
operator|*=
name|i
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
namespace|QFixed&
name|operator
namespace|*=(
name|uint
name|i
struct|)
block|{
name|val
operator|*=
name|i
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
namespace|QFixed&
name|operator
namespace|*=(const
name|QFixed
namespace|&
name|o
struct|)
block|{
name|bool
name|neg
init|=
name|false
decl_stmt|;
name|qint64
name|a
init|=
name|val
decl_stmt|;
name|qint64
name|b
init|=
name|o
operator|.
name|val
decl_stmt|;
if|if
condition|(
name|a
operator|<
literal|0
condition|)
block|{
name|a
operator|=
operator|-
name|a
expr_stmt|;
name|neg
operator|=
name|true
expr_stmt|;
block|}
if|if
condition|(
name|b
operator|<
literal|0
condition|)
block|{
name|b
operator|=
operator|-
name|b
expr_stmt|;
name|neg
operator|=
operator|!
name|neg
expr_stmt|;
block|}
name|int
name|res
init|=
call|(
name|int
call|)
argument_list|(
operator|(
name|a
operator|*
name|b
operator|+
literal|0x20L
operator|)
operator|>>
literal|6
argument_list|)
decl_stmt|;
name|val
operator|=
name|neg
condition|?
operator|-
name|res
else|:
name|res
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
namespace|QFixed
name|operator
modifier|*
namespace|(
name|int
name|i
struct|)
specifier|const
block|{
return|return
name|fromFixed
argument_list|(
name|val
operator|*
name|i
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
namespace|QFixed
name|operator
modifier|*
namespace|(
name|uint
name|i
struct|)
specifier|const
block|{
return|return
name|fromFixed
argument_list|(
name|val
operator|*
name|i
argument_list|)
return|;
block|}
specifier|inline
namespace|QFixed
name|operator
modifier|*
namespace|(const
name|QFixed
namespace|&
name|o
struct|)
specifier|const
block|{
name|QFixed
name|f
operator|=
operator|*
name|this
block|;
return|return
operator|(
name|f
operator|*=
name|o
operator|)
return|;
block|}
name|private
range|:
name|Q_DECL_CONSTEXPR
name|QFixed
argument_list|(
argument|qreal i
argument_list|)
operator|:
name|val
argument_list|(
argument|(int)(i*qreal(
literal|64
argument|))
argument_list|)
block|{}
name|QFixed
operator|&
name|operator
operator|=
operator|(
name|qreal
name|i
operator|)
block|{
name|val
operator|=
call|(
name|int
call|)
argument_list|(
name|i
operator|*
name|qreal
argument_list|(
literal|64
argument_list|)
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
namespace|QFixed
name|operator
namespace|+(
name|qreal
name|i
struct|)
specifier|const
block|{
return|return
name|fromFixed
argument_list|(
operator|(
name|val
operator|+
call|(
name|int
call|)
argument_list|(
name|i
operator|*
name|qreal
argument_list|(
literal|64
argument_list|)
argument_list|)
operator|)
argument_list|)
return|;
block|}
specifier|inline
namespace|QFixed&
name|operator
namespace|+=(
name|qreal
name|i
struct|)
block|{
name|val
operator|+=
call|(
name|int
call|)
argument_list|(
name|i
operator|*
literal|64
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
namespace|QFixed
name|operator
namespace|-(
name|qreal
name|i
struct|)
specifier|const
block|{
return|return
name|fromFixed
argument_list|(
operator|(
name|val
operator|-
call|(
name|int
call|)
argument_list|(
name|i
operator|*
name|qreal
argument_list|(
literal|64
argument_list|)
argument_list|)
operator|)
argument_list|)
return|;
block|}
specifier|inline
namespace|QFixed&
name|operator
namespace|-=(
name|qreal
name|i
struct|)
block|{
name|val
operator|-=
call|(
name|int
call|)
argument_list|(
name|i
operator|*
literal|64
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
namespace|QFixed&
name|operator
namespace|/=(
name|qreal
name|r
struct|)
block|{
name|val
operator|=
call|(
name|int
call|)
argument_list|(
name|val
operator|/
name|r
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
namespace|QFixed
name|operator
namespace|/(
name|qreal
name|d
struct|)
specifier|const
block|{
return|return
name|fromFixed
argument_list|(
call|(
name|int
call|)
argument_list|(
name|val
operator|/
name|d
argument_list|)
argument_list|)
return|;
block|}
specifier|inline
namespace|QFixed&
name|operator
namespace|*=(
name|qreal
name|d
struct|)
block|{
name|val
operator|=
call|(
name|int
call|)
argument_list|(
name|val
operator|*
name|d
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
namespace|QFixed
name|operator
modifier|*
namespace|(
name|qreal
name|d
struct|)
specifier|const
block|{
return|return
name|fromFixed
argument_list|(
call|(
name|int
call|)
argument_list|(
name|val
operator|*
name|d
argument_list|)
argument_list|)
return|;
block|}
name|int
name|val
struct|;
end_struct
begin_expr_stmt
unit|};
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QFixed
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_define
define|#
directive|define
name|QFIXED_MAX
value|(INT_MAX/256)
end_define
begin_function
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|qRound
parameter_list|(
specifier|const
name|QFixed
modifier|&
name|f
parameter_list|)
block|{
return|return
name|f
operator|.
name|toInt
argument_list|()
return|;
block|}
end_function
begin_function
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|qFloor
parameter_list|(
specifier|const
name|QFixed
modifier|&
name|f
parameter_list|)
block|{
return|return
name|f
operator|.
name|floor
argument_list|()
operator|.
name|truncate
argument_list|()
return|;
block|}
end_function
begin_function
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixed
name|operator
modifier|*
parameter_list|(
name|int
name|i
parameter_list|,
specifier|const
name|QFixed
modifier|&
name|d
parameter_list|)
block|{
return|return
name|d
operator|*
name|i
return|;
block|}
end_function
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixed
name|operator
operator|+
operator|(
name|int
name|i
operator|,
specifier|const
name|QFixed
operator|&
name|d
operator|)
block|{
return|return
name|d
operator|+
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixed
name|operator
operator|-
operator|(
name|int
name|i
operator|,
specifier|const
name|QFixed
operator|&
name|d
operator|)
block|{
return|return
operator|-
operator|(
name|d
operator|-
name|i
operator|)
return|;
block|}
end_expr_stmt
begin_function
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixed
name|operator
modifier|*
parameter_list|(
name|uint
name|i
parameter_list|,
specifier|const
name|QFixed
modifier|&
name|d
parameter_list|)
block|{
return|return
name|d
operator|*
name|i
return|;
block|}
end_function
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixed
name|operator
operator|+
operator|(
name|uint
name|i
operator|,
specifier|const
name|QFixed
operator|&
name|d
operator|)
block|{
return|return
name|d
operator|+
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixed
name|operator
operator|-
operator|(
name|uint
name|i
operator|,
specifier|const
name|QFixed
operator|&
name|d
operator|)
block|{
return|return
operator|-
operator|(
name|d
operator|-
name|i
operator|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Q_DECL_CONSTEXPR inline QFixed operator*(qreal d, const QFixed&d2) { return d2*d; }
end_comment
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QFixed
operator|&
name|f
operator|,
name|int
name|i
operator|)
block|{
return|return
name|f
operator|.
name|value
argument_list|()
operator|==
name|i
operator|*
literal|64
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|int
name|i
operator|,
specifier|const
name|QFixed
operator|&
name|f
operator|)
block|{
return|return
name|f
operator|.
name|value
argument_list|()
operator|==
name|i
operator|*
literal|64
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QFixed
operator|&
name|f
operator|,
name|int
name|i
operator|)
block|{
return|return
name|f
operator|.
name|value
argument_list|()
operator|!=
name|i
operator|*
literal|64
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|int
name|i
operator|,
specifier|const
name|QFixed
operator|&
name|f
operator|)
block|{
return|return
name|f
operator|.
name|value
argument_list|()
operator|!=
name|i
operator|*
literal|64
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|QFixed
operator|&
name|f
operator|,
name|int
name|i
operator|)
block|{
return|return
name|f
operator|.
name|value
argument_list|()
operator|<=
name|i
operator|*
literal|64
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|<=
operator|(
name|int
name|i
operator|,
specifier|const
name|QFixed
operator|&
name|f
operator|)
block|{
return|return
name|i
operator|*
literal|64
operator|<=
name|f
operator|.
name|value
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|QFixed
operator|&
name|f
operator|,
name|int
name|i
operator|)
block|{
return|return
name|f
operator|.
name|value
argument_list|()
operator|>=
name|i
operator|*
literal|64
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|>=
operator|(
name|int
name|i
operator|,
specifier|const
name|QFixed
operator|&
name|f
operator|)
block|{
return|return
name|i
operator|*
literal|64
operator|>=
name|f
operator|.
name|value
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QFixed
operator|&
name|f
operator|,
name|int
name|i
operator|)
block|{
return|return
name|f
operator|.
name|value
argument_list|()
operator|<
name|i
operator|*
literal|64
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|<
operator|(
name|int
name|i
operator|,
specifier|const
name|QFixed
operator|&
name|f
operator|)
block|{
return|return
name|i
operator|*
literal|64
operator|<
name|f
operator|.
name|value
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|QFixed
operator|&
name|f
operator|,
name|int
name|i
operator|)
block|{
return|return
name|f
operator|.
name|value
argument_list|()
operator|>
name|i
operator|*
literal|64
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|>
operator|(
name|int
name|i
operator|,
specifier|const
name|QFixed
operator|&
name|f
operator|)
block|{
return|return
name|i
operator|*
literal|64
operator|>
name|f
operator|.
name|value
argument_list|()
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|QDebug
operator|&
name|dbg
operator|,
specifier|const
name|QFixed
operator|&
name|f
operator|)
block|{
return|return
name|dbg
operator|<<
name|f
operator|.
name|toReal
argument_list|()
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_struct
struct|struct
name|QFixedPoint
block|{
name|QFixed
name|x
decl_stmt|;
name|QFixed
name|y
decl_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixedPoint
parameter_list|()
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixedPoint
argument_list|(
specifier|const
name|QFixed
operator|&
name|_x
argument_list|,
specifier|const
name|QFixed
operator|&
name|_y
argument_list|)
operator|:
name|x
argument_list|(
name|_x
argument_list|)
operator|,
name|y
argument_list|(
argument|_y
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
name|QPointF
name|toPointF
argument_list|()
specifier|const
block|{
return|return
name|QPointF
argument_list|(
name|x
operator|.
name|toReal
argument_list|()
argument_list|,
name|y
operator|.
name|toReal
argument_list|()
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|static
name|QFixedPoint
name|fromPointF
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|)
block|{
return|return
name|QFixedPoint
argument_list|(
name|QFixed
operator|::
name|fromReal
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|)
argument_list|,
name|QFixed
operator|::
name|fromReal
argument_list|(
name|p
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QFixedPoint
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixedPoint
name|operator
operator|-
operator|(
specifier|const
name|QFixedPoint
operator|&
name|p1
operator|,
specifier|const
name|QFixedPoint
operator|&
name|p2
operator|)
block|{
return|return
name|QFixedPoint
argument_list|(
name|p1
operator|.
name|x
operator|-
name|p2
operator|.
name|x
argument_list|,
name|p1
operator|.
name|y
operator|-
name|p2
operator|.
name|y
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFixedPoint
name|operator
operator|+
operator|(
specifier|const
name|QFixedPoint
operator|&
name|p1
operator|,
specifier|const
name|QFixedPoint
operator|&
name|p2
operator|)
block|{
return|return
name|QFixedPoint
argument_list|(
name|p1
operator|.
name|x
operator|+
name|p2
operator|.
name|x
argument_list|,
name|p1
operator|.
name|y
operator|+
name|p2
operator|.
name|y
argument_list|)
return|;
block|}
end_expr_stmt
begin_struct
struct|struct
name|QFixedSize
block|{
name|QFixed
name|width
decl_stmt|;
name|QFixed
name|height
decl_stmt|;
name|Q_DECL_CONSTEXPR
name|QFixedSize
parameter_list|()
block|{}
name|Q_DECL_CONSTEXPR
name|QFixedSize
argument_list|(
argument|QFixed _width
argument_list|,
argument|QFixed _height
argument_list|)
block|:
name|width
argument_list|(
name|_width
argument_list|)
operator|,
name|height
argument_list|(
argument|_height
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
name|QSizeF
name|toSizeF
argument_list|()
specifier|const
block|{
return|return
name|QSizeF
argument_list|(
name|width
operator|.
name|toReal
argument_list|()
argument_list|,
name|height
operator|.
name|toReal
argument_list|()
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|static
name|QFixedSize
name|fromSizeF
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|s
parameter_list|)
block|{
return|return
name|QFixedSize
argument_list|(
name|QFixed
operator|::
name|fromReal
argument_list|(
name|s
operator|.
name|width
argument_list|()
argument_list|)
argument_list|,
name|QFixed
operator|::
name|fromReal
argument_list|(
name|s
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QFixedSize
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTEXTENGINE_P_H
end_comment
end_unit
