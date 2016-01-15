begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qresource.h"
end_include
begin_include
include|#
directive|include
file|"qresource_iterator_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QResourceFileEngineIterator
name|QResourceFileEngineIterator
operator|::
name|QResourceFileEngineIterator
parameter_list|(
name|QDir
operator|::
name|Filters
name|filters
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|filterNames
parameter_list|)
member_init_list|:
name|QAbstractFileEngineIterator
argument_list|(
name|filters
argument_list|,
name|filterNames
argument_list|)
member_init_list|,
name|index
argument_list|(
operator|-
literal|1
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QResourceFileEngineIterator
name|QResourceFileEngineIterator
operator|::
name|~
name|QResourceFileEngineIterator
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|next
name|QString
name|QResourceFileEngineIterator
operator|::
name|next
parameter_list|()
block|{
if|if
condition|(
operator|!
name|hasNext
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
operator|++
name|index
expr_stmt|;
return|return
name|currentFilePath
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|hasNext
name|bool
name|QResourceFileEngineIterator
operator|::
name|hasNext
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|index
operator|==
operator|-
literal|1
condition|)
block|{
comment|// Lazy initialization of the iterator
name|QResource
name|resource
argument_list|(
name|path
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|resource
operator|.
name|isValid
argument_list|()
condition|)
return|return
literal|false
return|;
comment|// Initialize and move to the next entry.
name|entries
operator|=
name|resource
operator|.
name|children
argument_list|()
expr_stmt|;
name|index
operator|=
literal|0
expr_stmt|;
block|}
return|return
name|index
operator|<
name|entries
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|currentFileName
name|QString
name|QResourceFileEngineIterator
operator|::
name|currentFileName
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|index
operator|<=
literal|0
operator|||
name|index
operator|>
name|entries
operator|.
name|size
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|entries
operator|.
name|at
argument_list|(
name|index
operator|-
literal|1
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
