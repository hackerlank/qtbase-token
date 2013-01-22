begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the config.tests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/* Sample program for configure to test STL support on target platforms.  We are mainly concerned with being able to instantiate templates for common STL container classes. */
end_comment
begin_include
include|#
directive|include
file|<iterator>
end_include
begin_include
include|#
directive|include
file|<map>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_include
include|#
directive|include
file|<iostream>
end_include
begin_include
include|#
directive|include
file|<cstddef>
end_include
begin_comment
comment|// something mean to see if the compiler and C++ standard lib are good enough
end_comment
begin_class
template|template
parameter_list|<
name|class
name|K
parameter_list|,
name|class
name|T
parameter_list|>
class|class
DECL|class|DummyClass
name|DummyClass
block|{
comment|// everything in std namespace ?
DECL|typedef|i
typedef|typedef
name|std
operator|::
name|bidirectional_iterator_tag
name|i
typedef|;
DECL|typedef|d
typedef|typedef
name|std
operator|::
name|ptrdiff_t
name|d
typedef|;
comment|// typename implemented ?
DECL|typedef|MyIterator
typedef|typedef
typename|typename
name|std
operator|::
name|map
argument_list|<
name|K
argument_list|,
name|T
argument_list|>
operator|::
name|iterator
name|MyIterator
typedef|;
block|}
class|;
end_class
begin_comment
comment|// extracted from QVector's strict iterator
end_comment
begin_class
template|template
parameter_list|<
name|class
name|T
parameter_list|>
class|class
DECL|class|DummyIterator
name|DummyIterator
block|{
DECL|typedef|iterator
typedef|typedef
name|DummyIterator
argument_list|<
name|int
argument_list|>
name|iterator
typedef|;
public|public:
DECL|member|i
name|T
modifier|*
name|i
decl_stmt|;
DECL|typedef|iterator_category
typedef|typedef
name|std
operator|::
name|random_access_iterator_tag
name|iterator_category
typedef|;
DECL|typedef|difference_type
typedef|typedef
name|std
operator|::
name|ptrdiff_t
name|difference_type
typedef|;
DECL|typedef|value_type
typedef|typedef
name|T
name|value_type
typedef|;
DECL|typedef|pointer
typedef|typedef
name|T
modifier|*
name|pointer
typedef|;
DECL|typedef|reference
typedef|typedef
name|T
modifier|&
name|reference
typedef|;
DECL|function|DummyIterator
specifier|inline
name|DummyIterator
parameter_list|()
member_init_list|:
name|i
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|DummyIterator
specifier|inline
name|DummyIterator
parameter_list|(
name|T
modifier|*
name|n
parameter_list|)
member_init_list|:
name|i
argument_list|(
name|n
argument_list|)
block|{}
DECL|function|DummyIterator
specifier|inline
name|DummyIterator
parameter_list|(
specifier|const
name|DummyIterator
modifier|&
name|o
parameter_list|)
member_init_list|:
name|i
argument_list|(
name|o
operator|.
name|i
argument_list|)
block|{}
DECL|function|operator *
specifier|inline
name|T
modifier|&
name|operator
name|*
parameter_list|()
specifier|const
block|{
return|return
operator|*
name|i
return|;
block|}
DECL|function|operator ->
specifier|inline
name|T
modifier|*
name|operator
name|->
parameter_list|()
specifier|const
block|{
return|return
name|i
return|;
block|}
DECL|function|operator []
specifier|inline
name|T
modifier|&
name|operator
name|[]
parameter_list|(
name|int
name|j
parameter_list|)
specifier|const
block|{
return|return
operator|*
operator|(
name|i
operator|+
name|j
operator|)
return|;
block|}
DECL|function|operator ==
specifier|inline
name|bool
name|operator
name|==
parameter_list|(
specifier|const
name|DummyIterator
modifier|&
name|o
parameter_list|)
specifier|const
block|{
return|return
name|i
operator|==
name|o
operator|.
name|i
return|;
block|}
DECL|function|operator !=
specifier|inline
name|bool
name|operator
name|!=
parameter_list|(
specifier|const
name|DummyIterator
modifier|&
name|o
parameter_list|)
specifier|const
block|{
return|return
name|i
operator|!=
name|o
operator|.
name|i
return|;
block|}
DECL|function|operator <
specifier|inline
name|bool
name|operator
name|<
parameter_list|(
specifier|const
name|DummyIterator
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
name|i
operator|<
name|other
operator|.
name|i
return|;
block|}
DECL|function|operator <=
specifier|inline
name|bool
name|operator
name|<=
parameter_list|(
specifier|const
name|DummyIterator
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
name|i
operator|<=
name|other
operator|.
name|i
return|;
block|}
DECL|function|operator >
specifier|inline
name|bool
name|operator
name|>
parameter_list|(
specifier|const
name|DummyIterator
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
name|i
operator|>
name|other
operator|.
name|i
return|;
block|}
DECL|function|operator >=
specifier|inline
name|bool
name|operator
name|>=
parameter_list|(
specifier|const
name|DummyIterator
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
name|i
operator|>=
name|other
operator|.
name|i
return|;
block|}
DECL|function|operator ++
specifier|inline
name|DummyIterator
modifier|&
name|operator
name|++
parameter_list|()
block|{
operator|++
name|i
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
DECL|function|operator ++
specifier|inline
name|DummyIterator
name|operator
name|++
parameter_list|(
name|int
parameter_list|)
block|{
name|T
modifier|*
name|n
init|=
name|i
decl_stmt|;
operator|++
name|i
expr_stmt|;
return|return
name|n
return|;
block|}
DECL|function|operator --
specifier|inline
name|DummyIterator
modifier|&
name|operator
name|--
parameter_list|()
block|{
name|i
operator|--
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
DECL|function|operator --
specifier|inline
name|DummyIterator
name|operator
name|--
parameter_list|(
name|int
parameter_list|)
block|{
name|T
modifier|*
name|n
init|=
name|i
decl_stmt|;
name|i
operator|--
expr_stmt|;
return|return
name|n
return|;
block|}
DECL|function|operator +=
specifier|inline
name|DummyIterator
modifier|&
name|operator
name|+=
parameter_list|(
name|int
name|j
parameter_list|)
block|{
name|i
operator|+=
name|j
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
DECL|function|operator -=
specifier|inline
name|DummyIterator
modifier|&
name|operator
name|-=
parameter_list|(
name|int
name|j
parameter_list|)
block|{
name|i
operator|-=
name|j
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
DECL|function|operator +
specifier|inline
name|DummyIterator
name|operator
name|+
parameter_list|(
name|int
name|j
parameter_list|)
specifier|const
block|{
return|return
name|DummyIterator
argument_list|(
name|i
operator|+
name|j
argument_list|)
return|;
block|}
DECL|function|operator -
specifier|inline
name|DummyIterator
name|operator
name|-
parameter_list|(
name|int
name|j
parameter_list|)
specifier|const
block|{
return|return
name|DummyIterator
argument_list|(
name|i
operator|-
name|j
argument_list|)
return|;
block|}
DECL|function|operator -
specifier|inline
name|int
name|operator
name|-
parameter_list|(
name|DummyIterator
name|j
parameter_list|)
specifier|const
block|{
return|return
name|i
operator|-
name|j
operator|.
name|i
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
name|std
operator|::
name|vector
argument_list|<
name|int
argument_list|>
name|v1
decl_stmt|;
name|v1
operator|.
name|push_back
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|v1
operator|.
name|push_back
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|v1
operator|.
name|push_back
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|v1
operator|.
name|push_back
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|v1
operator|.
name|push_back
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|int
name|v1size
init|=
name|v1
operator|.
name|size
argument_list|()
decl_stmt|;
name|v1size
operator|=
literal|0
expr_stmt|;
name|int
name|v1capacity
init|=
name|v1
operator|.
name|capacity
argument_list|()
decl_stmt|;
name|v1capacity
operator|=
literal|0
expr_stmt|;
name|std
operator|::
name|vector
argument_list|<
name|int
argument_list|>
operator|::
name|iterator
name|v1it
init|=
name|std
operator|::
name|find
argument_list|(
name|v1
operator|.
name|begin
argument_list|()
argument_list|,
name|v1
operator|.
name|end
argument_list|()
argument_list|,
literal|99
argument_list|)
decl_stmt|;
name|bool
name|v1notfound
init|=
operator|(
name|v1it
operator|==
name|v1
operator|.
name|end
argument_list|()
operator|)
decl_stmt|;
name|v1notfound
operator|=
literal|false
expr_stmt|;
name|v1it
operator|=
name|std
operator|::
name|find
argument_list|(
name|v1
operator|.
name|begin
argument_list|()
argument_list|,
name|v1
operator|.
name|end
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|bool
name|v1found
init|=
operator|(
name|v1it
operator|!=
name|v1
operator|.
name|end
argument_list|()
operator|)
decl_stmt|;
name|v1found
operator|=
literal|false
expr_stmt|;
name|std
operator|::
name|vector
argument_list|<
name|int
argument_list|>
name|v2
decl_stmt|;
name|std
operator|::
name|copy
argument_list|(
name|v1
operator|.
name|begin
argument_list|()
argument_list|,
name|v1it
argument_list|,
name|std
operator|::
name|back_inserter
argument_list|(
name|v2
argument_list|)
argument_list|)
expr_stmt|;
name|int
name|v2size
init|=
name|v2
operator|.
name|size
argument_list|()
decl_stmt|;
name|v2size
operator|=
literal|0
expr_stmt|;
name|std
operator|::
name|map
argument_list|<
name|int
argument_list|,
name|double
argument_list|>
name|m1
decl_stmt|;
name|m1
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
literal|1
argument_list|,
literal|2.0
argument_list|)
argument_list|)
expr_stmt|;
name|m1
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
literal|3
argument_list|,
literal|2.0
argument_list|)
argument_list|)
expr_stmt|;
name|m1
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
literal|5
argument_list|,
literal|2.0
argument_list|)
argument_list|)
expr_stmt|;
name|m1
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
literal|7
argument_list|,
literal|2.0
argument_list|)
argument_list|)
expr_stmt|;
name|int
name|m1size
init|=
name|m1
operator|.
name|size
argument_list|()
decl_stmt|;
name|m1size
operator|=
literal|0
expr_stmt|;
name|std
operator|::
name|map
argument_list|<
name|int
argument_list|,
name|double
argument_list|>
operator|::
name|iterator
name|m1it
init|=
name|m1
operator|.
name|begin
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|m1it
operator|!=
name|m1
operator|.
name|end
argument_list|()
condition|;
operator|++
name|m1it
control|)
block|{
name|int
name|first
init|=
operator|(
operator|*
name|m1it
operator|)
operator|.
name|first
decl_stmt|;
name|first
operator|=
literal|0
expr_stmt|;
name|double
name|second
init|=
operator|(
operator|*
name|m1it
operator|)
operator|.
name|second
decl_stmt|;
name|second
operator|=
literal|0.0
expr_stmt|;
block|}
name|std
operator|::
name|map
argument_list|<
name|int
argument_list|,
name|double
argument_list|>
name|m2
argument_list|(
name|m1
argument_list|)
decl_stmt|;
name|int
name|m2size
init|=
name|m2
operator|.
name|size
argument_list|()
decl_stmt|;
name|m2size
operator|=
literal|0
expr_stmt|;
name|DummyIterator
argument_list|<
name|int
argument_list|>
name|it1
decl_stmt|,
name|it2
decl_stmt|;
name|int
name|n
init|=
name|std
operator|::
name|distance
argument_list|(
name|it1
argument_list|,
name|it2
argument_list|)
decl_stmt|;
name|std
operator|::
name|advance
argument_list|(
name|it1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
