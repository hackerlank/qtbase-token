begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"treemodelcompleter.h"
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|TreeModelCompleter
name|TreeModelCompleter
operator|::
name|TreeModelCompleter
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QCompleter
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_constructor
DECL|function|TreeModelCompleter
name|TreeModelCompleter
operator|::
name|TreeModelCompleter
parameter_list|(
name|QAbstractItemModel
modifier|*
name|model
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QCompleter
argument_list|(
name|model
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|setSeparator
name|void
name|TreeModelCompleter
operator|::
name|setSeparator
parameter_list|(
specifier|const
name|QString
modifier|&
name|separator
parameter_list|)
block|{
name|sep
operator|=
name|separator
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|separator
name|QString
name|TreeModelCompleter
operator|::
name|separator
parameter_list|()
specifier|const
block|{
return|return
name|sep
return|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|splitPath
name|QStringList
name|TreeModelCompleter
operator|::
name|splitPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|sep
operator|.
name|isNull
argument_list|()
condition|)
block|{
return|return
name|QCompleter
operator|::
name|splitPath
argument_list|(
name|path
argument_list|)
return|;
block|}
return|return
name|path
operator|.
name|split
argument_list|(
name|sep
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|pathFromIndex
name|QString
name|TreeModelCompleter
operator|::
name|pathFromIndex
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|sep
operator|.
name|isNull
argument_list|()
condition|)
block|{
return|return
name|QCompleter
operator|::
name|pathFromIndex
argument_list|(
name|index
argument_list|)
return|;
block|}
comment|// navigate up and accumulate data
name|QStringList
name|dataList
decl_stmt|;
for|for
control|(
name|QModelIndex
name|i
init|=
name|index
init|;
name|i
operator|.
name|isValid
argument_list|()
condition|;
name|i
operator|=
name|i
operator|.
name|parent
argument_list|()
control|)
block|{
name|dataList
operator|.
name|prepend
argument_list|(
name|model
argument_list|()
operator|->
name|data
argument_list|(
name|i
argument_list|,
name|completionRole
argument_list|()
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|dataList
operator|.
name|join
argument_list|(
name|sep
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
end_unit
