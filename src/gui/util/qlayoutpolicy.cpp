begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the Qt Quick Layouts module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlayoutpolicy_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatastream.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|setControlType
name|void
name|QLayoutPolicy
operator|::
name|setControlType
parameter_list|(
name|ControlType
name|type
parameter_list|)
block|{
comment|/*         The control type is a flag type, with values 0x1, 0x2, 0x4, 0x8, 0x10,         etc. In memory, we pack it onto the available bits (CTSize) in         setControlType(), and unpack it here.          Example:              0x00000001 maps to 0             0x00000002 maps to 1             0x00000004 maps to 2             0x00000008 maps to 3             etc.     */
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
literal|true
condition|)
block|{
if|if
condition|(
name|type
operator|&
operator|(
literal|0x1
operator|<<
name|i
operator|)
condition|)
block|{
name|bits
operator|.
name|ctype
operator|=
name|i
expr_stmt|;
return|return;
block|}
operator|++
name|i
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|controlType
name|QLayoutPolicy
operator|::
name|ControlType
name|QLayoutPolicy
operator|::
name|controlType
parameter_list|()
specifier|const
block|{
return|return
name|QLayoutPolicy
operator|::
name|ControlType
argument_list|(
literal|1
operator|<<
name|bits
operator|.
name|ctype
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_comment
comment|/*!     \relates QLayoutPolicy      Writes the size \a policy to the data stream \a stream.      \sa{Serializing Qt Data Types}{Format of the QDataStream operators} */
end_comment
begin_function
DECL|function|operator <<
name|QDataStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|,
specifier|const
name|QLayoutPolicy
modifier|&
name|policy
parameter_list|)
block|{
comment|// The order here is for historical reasons. (compatibility with Qt4)
name|quint32
name|data
init|=
operator|(
name|policy
operator|.
name|bits
operator|.
name|horPolicy
operator||
comment|// [0, 3]
name|policy
operator|.
name|bits
operator|.
name|verPolicy
operator|<<
literal|4
operator||
comment|// [4, 7]
name|policy
operator|.
name|bits
operator|.
name|hfw
operator|<<
literal|8
operator||
comment|// [8]
name|policy
operator|.
name|bits
operator|.
name|ctype
operator|<<
literal|9
operator||
comment|// [9, 13]
name|policy
operator|.
name|bits
operator|.
name|wfh
operator|<<
literal|14
operator||
comment|// [14]
comment|//policy.bits.padding<< 15 |     // [15]
name|policy
operator|.
name|bits
operator|.
name|verStretch
operator|<<
literal|16
operator||
comment|// [16, 23]
name|policy
operator|.
name|bits
operator|.
name|horStretch
operator|<<
literal|24
operator|)
decl_stmt|;
comment|// [24, 31]
return|return
name|stream
operator|<<
name|data
return|;
block|}
end_function
begin_define
DECL|macro|VALUE_OF_BITS
define|#
directive|define
name|VALUE_OF_BITS
parameter_list|(
name|data
parameter_list|,
name|bitstart
parameter_list|,
name|bitcount
parameter_list|)
value|((data>> bitstart)& ((1<< bitcount) -1))
end_define
begin_comment
comment|/*!     \relates QLayoutPolicy      Reads the size \a policy from the data stream \a stream.      \sa{Serializing Qt Data Types}{Format of the QDataStream operators} */
end_comment
begin_function
DECL|function|operator >>
name|QDataStream
modifier|&
name|operator
name|>>
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|,
name|QLayoutPolicy
modifier|&
name|policy
parameter_list|)
block|{
name|quint32
name|data
decl_stmt|;
name|stream
operator|>>
name|data
expr_stmt|;
name|policy
operator|.
name|bits
operator|.
name|horPolicy
operator|=
name|VALUE_OF_BITS
argument_list|(
name|data
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|policy
operator|.
name|bits
operator|.
name|verPolicy
operator|=
name|VALUE_OF_BITS
argument_list|(
name|data
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|policy
operator|.
name|bits
operator|.
name|hfw
operator|=
name|VALUE_OF_BITS
argument_list|(
name|data
argument_list|,
literal|8
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|policy
operator|.
name|bits
operator|.
name|ctype
operator|=
name|VALUE_OF_BITS
argument_list|(
name|data
argument_list|,
literal|9
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|policy
operator|.
name|bits
operator|.
name|wfh
operator|=
name|VALUE_OF_BITS
argument_list|(
name|data
argument_list|,
literal|14
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|policy
operator|.
name|bits
operator|.
name|padding
operator|=
literal|0
expr_stmt|;
name|policy
operator|.
name|bits
operator|.
name|verStretch
operator|=
name|VALUE_OF_BITS
argument_list|(
name|data
argument_list|,
literal|16
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|policy
operator|.
name|bits
operator|.
name|horStretch
operator|=
name|VALUE_OF_BITS
argument_list|(
name|data
argument_list|,
literal|24
argument_list|,
literal|8
argument_list|)
expr_stmt|;
return|return
name|stream
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DATASTREAM
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|dbg
parameter_list|,
specifier|const
name|QLayoutPolicy
modifier|&
name|p
parameter_list|)
block|{
name|QDebugStateSaver
name|saver
argument_list|(
name|dbg
argument_list|)
decl_stmt|;
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QLayoutPolicy(horizontalPolicy = "
operator|<<
name|p
operator|.
name|horizontalPolicy
argument_list|()
operator|<<
literal|", verticalPolicy = "
operator|<<
name|p
operator|.
name|verticalPolicy
argument_list|()
operator|<<
literal|')'
expr_stmt|;
return|return
name|dbg
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
