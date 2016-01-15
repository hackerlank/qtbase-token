begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<private/qcore_mac_p.h>
end_include
begin_include
include|#
directive|include
file|<new>
end_include
begin_include
include|#
directive|include
file|"qvarlengtharray.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|toQString
name|QString
name|QCFString
operator|::
name|toQString
parameter_list|(
name|CFStringRef
name|str
parameter_list|)
block|{
if|if
condition|(
operator|!
name|str
condition|)
return|return
name|QString
argument_list|()
return|;
name|CFIndex
name|length
init|=
name|CFStringGetLength
argument_list|(
name|str
argument_list|)
decl_stmt|;
specifier|const
name|UniChar
modifier|*
name|chars
init|=
name|CFStringGetCharactersPtr
argument_list|(
name|str
argument_list|)
decl_stmt|;
if|if
condition|(
name|chars
condition|)
return|return
name|QString
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|QChar
operator|*
argument_list|>
argument_list|(
name|chars
argument_list|)
argument_list|,
name|length
argument_list|)
return|;
name|QVarLengthArray
argument_list|<
name|UniChar
argument_list|>
name|buffer
argument_list|(
name|length
argument_list|)
decl_stmt|;
name|CFStringGetCharacters
argument_list|(
name|str
argument_list|,
name|CFRangeMake
argument_list|(
literal|0
argument_list|,
name|length
argument_list|)
argument_list|,
name|buffer
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|QChar
operator|*
argument_list|>
argument_list|(
name|buffer
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|,
name|length
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|operator QString
name|QCFString
operator|::
name|operator
name|QString
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|string
operator|.
name|isEmpty
argument_list|()
operator|&&
name|type
condition|)
cast|const_cast
argument_list|<
name|QCFString
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|string
operator|=
name|toQString
argument_list|(
name|type
argument_list|)
expr_stmt|;
return|return
name|string
return|;
block|}
end_function
begin_function
DECL|function|toCFStringRef
name|CFStringRef
name|QCFString
operator|::
name|toCFStringRef
parameter_list|(
specifier|const
name|QString
modifier|&
name|string
parameter_list|)
block|{
return|return
name|CFStringCreateWithCharacters
argument_list|(
literal|0
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|UniChar
operator|*
argument_list|>
argument_list|(
name|string
operator|.
name|unicode
argument_list|()
argument_list|)
argument_list|,
name|string
operator|.
name|length
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|operator CFStringRef
name|QCFString
operator|::
name|operator
name|CFStringRef
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|type
condition|)
cast|const_cast
argument_list|<
name|QCFString
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|type
operator|=
name|toCFStringRef
argument_list|(
name|string
argument_list|)
expr_stmt|;
return|return
name|type
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
