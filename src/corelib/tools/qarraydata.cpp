begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qarraydata.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qtools_p.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|*
literal|100
operator|+
name|__GNUC_MINOR__
operator|>=
literal|406
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|push
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wmissing-field-initializers"
endif|#
directive|endif
DECL|member|shared_null
specifier|const
name|QArrayData
name|QArrayData
operator|::
name|shared_null
index|[
literal|2
index|]
init|=
block|{
block|{
name|Q_REFCOUNT_INITIALIZE_STATIC
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
expr|sizeof
operator|(
name|QArrayData
operator|)
block|}
block|,
comment|// shared null
comment|/* zero initialized terminator */
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_array
specifier|static
specifier|const
name|QArrayData
name|qt_array
index|[
literal|3
index|]
init|=
block|{
block|{
name|Q_REFCOUNT_INITIALIZE_STATIC
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
expr|sizeof
operator|(
name|QArrayData
operator|)
block|}
block|,
comment|// shared empty
block|{
block|{
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
literal|0
argument_list|)
block|}
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
expr|sizeof
operator|(
name|QArrayData
operator|)
block|}
block|,
comment|// unsharable empty
comment|/* zero initialized terminator */
block|}
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|*
literal|100
operator|+
name|__GNUC_MINOR__
operator|>=
literal|406
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
end_if
begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|pop
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|qt_array_empty
specifier|static
specifier|const
name|QArrayData
modifier|&
name|qt_array_empty
init|=
name|qt_array
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_array_unsharable_empty
specifier|static
specifier|const
name|QArrayData
modifier|&
name|qt_array_unsharable_empty
init|=
name|qt_array
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt
begin_function
name|QArrayData
modifier|*
name|QArrayData
operator|::
name|allocate
parameter_list|(
name|size_t
name|objectSize
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|size_t
name|capacity
parameter_list|,
name|AllocationOptions
name|options
parameter_list|)
name|Q_DECL_NOTHROW
block|{
comment|// Alignment is a power of two
name|Q_ASSERT
argument_list|(
name|alignment
operator|>=
name|Q_ALIGNOF
argument_list|(
name|QArrayData
argument_list|)
operator|&&
operator|!
operator|(
name|alignment
operator|&
operator|(
name|alignment
operator|-
literal|1
operator|)
operator|)
argument_list|)
expr_stmt|;
comment|// Don't allocate empty headers
if|if
condition|(
operator|!
operator|(
name|options
operator|&
name|RawData
operator|)
operator|&&
operator|!
name|capacity
condition|)
block|{
if|#
directive|if
name|QT_SUPPORTS
argument_list|(
name|UNSHARABLE_CONTAINERS
argument_list|)
if|if
condition|(
name|options
operator|&
name|Unsharable
condition|)
return|return
cast|const_cast
argument_list|<
name|QArrayData
operator|*
argument_list|>
argument_list|(
operator|&
name|qt_array_unsharable_empty
argument_list|)
return|;
endif|#
directive|endif
return|return
cast|const_cast
argument_list|<
name|QArrayData
operator|*
argument_list|>
argument_list|(
operator|&
name|qt_array_empty
argument_list|)
return|;
block|}
name|size_t
name|headerSize
init|=
sizeof|sizeof
argument_list|(
name|QArrayData
argument_list|)
decl_stmt|;
comment|// Allocate extra (alignment - Q_ALIGNOF(QArrayData)) padding bytes so we
comment|// can properly align the data array. This assumes malloc is able to
comment|// provide appropriate alignment for the header -- as it should!
comment|// Padding is skipped when allocating a header for RawData.
if|if
condition|(
operator|!
operator|(
name|options
operator|&
name|RawData
operator|)
condition|)
name|headerSize
operator|+=
operator|(
name|alignment
operator|-
name|Q_ALIGNOF
argument_list|(
name|QArrayData
argument_list|)
operator|)
expr_stmt|;
comment|// Allocate additional space if array is growing
if|if
condition|(
name|options
operator|&
name|Grow
condition|)
name|capacity
operator|=
name|qAllocMore
argument_list|(
name|int
argument_list|(
name|objectSize
operator|*
name|capacity
argument_list|)
argument_list|,
name|int
argument_list|(
name|headerSize
argument_list|)
argument_list|)
operator|/
name|int
argument_list|(
name|objectSize
argument_list|)
expr_stmt|;
name|size_t
name|allocSize
init|=
name|headerSize
operator|+
name|objectSize
operator|*
name|capacity
decl_stmt|;
name|QArrayData
modifier|*
name|header
init|=
cast|static_cast
argument_list|<
name|QArrayData
operator|*
argument_list|>
argument_list|(
operator|::
name|malloc
argument_list|(
name|allocSize
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|header
condition|)
block|{
name|quintptr
name|data
init|=
operator|(
name|quintptr
argument_list|(
name|header
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|QArrayData
argument_list|)
operator|+
name|alignment
operator|-
literal|1
operator|)
operator|&
operator|~
operator|(
name|alignment
operator|-
literal|1
operator|)
decl_stmt|;
name|header
operator|->
name|ref
operator|.
name|atomic
operator|.
name|store
argument_list|(
name|bool
argument_list|(
operator|!
operator|(
name|options
operator|&
name|Unsharable
operator|)
argument_list|)
argument_list|)
expr_stmt|;
name|header
operator|->
name|size
operator|=
literal|0
expr_stmt|;
name|header
operator|->
name|alloc
operator|=
name|capacity
expr_stmt|;
name|header
operator|->
name|capacityReserved
operator|=
name|bool
argument_list|(
name|options
operator|&
name|CapacityReserved
argument_list|)
expr_stmt|;
name|header
operator|->
name|offset
operator|=
name|data
operator|-
name|quintptr
argument_list|(
name|header
argument_list|)
expr_stmt|;
block|}
return|return
name|header
return|;
block|}
end_function
begin_function
name|void
name|QArrayData
operator|::
name|deallocate
parameter_list|(
name|QArrayData
modifier|*
name|data
parameter_list|,
name|size_t
name|objectSize
parameter_list|,
name|size_t
name|alignment
parameter_list|)
name|Q_DECL_NOTHROW
block|{
comment|// Alignment is a power of two
name|Q_ASSERT
argument_list|(
name|alignment
operator|>=
name|Q_ALIGNOF
argument_list|(
name|QArrayData
argument_list|)
operator|&&
operator|!
operator|(
name|alignment
operator|&
operator|(
name|alignment
operator|-
literal|1
operator|)
operator|)
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
argument|objectSize
argument_list|)
name|Q_UNUSED
argument_list|(
argument|alignment
argument_list|)
if|#
directive|if
name|QT_SUPPORTS
argument_list|(
name|UNSHARABLE_CONTAINERS
argument_list|)
if|if
condition|(
name|data
operator|==
operator|&
name|qt_array_unsharable_empty
condition|)
return|return;
endif|#
directive|endif
name|Q_ASSERT_X
argument_list|(
operator|!
name|data
operator|->
name|ref
operator|.
name|isStatic
argument_list|()
argument_list|,
literal|"QArrayData::deallocate"
argument_list|,
literal|"Static data can not be deleted"
argument_list|)
expr_stmt|;
operator|::
name|free
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_namespace
DECL|namespace|QtPrivate
namespace|namespace
name|QtPrivate
block|{
comment|/*!   \internal */
DECL|function|mid
name|QContainerImplHelper
operator|::
name|CutResult
name|QContainerImplHelper
operator|::
name|mid
parameter_list|(
name|int
name|originalLength
parameter_list|,
name|int
modifier|*
name|_position
parameter_list|,
name|int
modifier|*
name|_length
parameter_list|)
block|{
name|int
modifier|&
name|position
init|=
operator|*
name|_position
decl_stmt|;
name|int
modifier|&
name|length
init|=
operator|*
name|_length
decl_stmt|;
if|if
condition|(
name|position
operator|>
name|originalLength
condition|)
return|return
name|Null
return|;
if|if
condition|(
name|position
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|length
operator|<
literal|0
operator|||
name|length
operator|+
name|position
operator|>=
name|originalLength
condition|)
return|return
name|Full
return|;
if|if
condition|(
name|length
operator|+
name|position
operator|<=
literal|0
condition|)
return|return
name|Null
return|;
name|length
operator|+=
name|position
expr_stmt|;
name|position
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|uint
argument_list|(
name|length
argument_list|)
operator|>
name|uint
argument_list|(
name|originalLength
operator|-
name|position
argument_list|)
condition|)
block|{
name|length
operator|=
name|originalLength
operator|-
name|position
expr_stmt|;
block|}
if|if
condition|(
name|position
operator|==
literal|0
operator|&&
name|length
operator|==
name|originalLength
condition|)
return|return
name|Full
return|;
return|return
name|length
operator|>
literal|0
condition|?
name|Subset
else|:
name|Empty
return|;
block|}
block|}
end_namespace
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
