begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2011 Thiago Macieira<thiago@kde.org> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_BOOTSTRAP_H
end_ifndef
begin_define
DECL|macro|QATOMIC_BOOTSTRAP_H
define|#
directive|define
name|QATOMIC_BOOTSTRAP_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qgenericatomic.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
literal|0
comment|// silence syncqt warnings
expr|QT_END_NAMESPACE
pragma|#
directive|pragma
name|qt_sync_skip_header_check
pragma|#
directive|pragma
name|qt_sync_stop_processing
endif|#
directive|endif
DECL|struct|T
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|QAtomicOps
operator|:
name|QGenericAtomicOps
operator|<
name|QAtomicOps
operator|<
name|T
operator|>
expr|>
block|{
DECL|typedef|Type
typedef|typedef
name|T
name|Type
typedef|;
specifier|static
name|bool
name|ref
argument_list|(
argument|T&_q_value
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
operator|++
name|_q_value
operator|!=
literal|0
return|;
block|}
specifier|static
name|bool
name|deref
argument_list|(
argument|T&_q_value
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
operator|--
name|_q_value
operator|!=
literal|0
return|;
block|}
specifier|static
name|bool
name|testAndSetRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|,
argument|T *currentValue =
literal|0
argument_list|)
name|Q_DECL_NOTHROW
block|{
if|if
condition|(
name|currentValue
condition|)
operator|*
name|currentValue
operator|=
name|_q_value
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|_q_value
operator|==
name|expectedValue
condition|)
block|{
name|_q_value
operator|=
name|newValue
expr_stmt|;
return|return
name|true
return|;
block|}
end_if
begin_return
return|return
name|false
return|;
end_return
begin_function
unit|}      static
name|T
name|fetchAndStoreRelaxed
parameter_list|(
name|T
modifier|&
name|_q_value
parameter_list|,
name|T
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
name|T
name|tmp
init|=
name|_q_value
decl_stmt|;
name|_q_value
operator|=
name|newValue
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_function
begin_expr_stmt
name|template
operator|<
name|typename
name|AdditiveType
operator|>
specifier|static
name|T
name|fetchAndAddRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|AdditiveType valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|T
name|returnValue
operator|=
name|_q_value
block|;
name|_q_value
operator|+=
name|valueToAdd
block|;
return|return
name|returnValue
return|;
block|}
end_expr_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_BOOTSTRAP_H
end_comment
end_unit
