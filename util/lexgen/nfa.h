begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the utils of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|NFA_H
end_ifndef
begin_define
DECL|macro|NFA_H
define|#
directive|define
name|NFA_H
end_define
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QStack>
end_include
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_include
include|#
directive|include
file|"global.h"
end_include
begin_typedef
DECL|typedef|InputType
DECL|typedef|TransitionMap
typedef|typedef
name|QHash
operator|<
name|InputType
operator|,
name|int
operator|>
name|TransitionMap
expr_stmt|;
end_typedef
begin_struct
DECL|struct|State
struct|struct
name|State
block|{
DECL|member|symbol
name|QString
name|symbol
decl_stmt|;
DECL|member|transitions
name|TransitionMap
name|transitions
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|stream
operator|,
specifier|const
name|State
operator|&
name|state
operator|)
block|{
return|return
name|stream
operator|<<
name|state
operator|.
name|symbol
operator|<<
name|state
operator|.
name|transitions
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|stream
operator|,
name|State
operator|&
name|state
operator|)
block|{
return|return
name|stream
operator|>>
name|state
operator|.
name|symbol
operator|>>
name|state
operator|.
name|transitions
return|;
block|}
end_expr_stmt
begin_decl_stmt
DECL|struct|State
name|struct
name|DFA
range|:
name|public
name|QVector
operator|<
name|State
operator|>
block|{
name|void
name|debug
argument_list|()
specifier|const
block|;
name|DFA
name|minimize
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|NFA
block|{
name|public
label|:
specifier|static
name|NFA
name|createSingleInputNFA
parameter_list|(
name|InputType
name|input
parameter_list|)
function_decl|;
specifier|static
name|NFA
name|createSymbolNFA
parameter_list|(
specifier|const
name|QString
modifier|&
name|symbol
parameter_list|)
function_decl|;
specifier|static
name|NFA
name|createAlternatingNFA
parameter_list|(
specifier|const
name|NFA
modifier|&
name|a
parameter_list|,
specifier|const
name|NFA
modifier|&
name|b
parameter_list|)
function_decl|;
specifier|static
name|NFA
name|createConcatenatingNFA
parameter_list|(
specifier|const
name|NFA
modifier|&
name|a
parameter_list|,
specifier|const
name|NFA
modifier|&
name|b
parameter_list|)
function_decl|;
specifier|static
name|NFA
name|createOptionalNFA
parameter_list|(
specifier|const
name|NFA
modifier|&
name|a
parameter_list|)
function_decl|;
comment|// convenience
specifier|static
name|NFA
name|createStringNFA
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|str
parameter_list|)
function_decl|;
specifier|static
name|NFA
name|createSetNFA
argument_list|(
specifier|const
name|QSet
operator|<
name|InputType
operator|>
operator|&
name|set
argument_list|)
decl_stmt|;
specifier|static
name|NFA
name|createZeroOrOneNFA
parameter_list|(
specifier|const
name|NFA
modifier|&
name|a
parameter_list|)
function_decl|;
specifier|static
name|NFA
name|applyQuantity
parameter_list|(
specifier|const
name|NFA
modifier|&
name|a
parameter_list|,
name|int
name|minOccurrences
parameter_list|,
name|int
name|maxOccurrences
parameter_list|)
function_decl|;
name|void
name|setTerminationSymbol
parameter_list|(
specifier|const
name|QString
modifier|&
name|symbol
parameter_list|)
function_decl|;
name|DFA
name|toDFA
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|states
operator|.
name|isEmpty
argument_list|()
return|;
block|}
specifier|inline
name|int
name|stateCount
argument_list|()
specifier|const
block|{
return|return
name|states
operator|.
name|count
argument_list|()
return|;
block|}
name|void
name|debug
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|initialize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
name|void
name|addTransition
parameter_list|(
name|int
name|from
parameter_list|,
name|InputType
name|input
parameter_list|,
name|int
name|to
parameter_list|)
function_decl|;
name|void
name|copyFrom
parameter_list|(
specifier|const
name|NFA
modifier|&
name|other
parameter_list|,
name|int
name|baseState
parameter_list|)
function_decl|;
name|void
name|initializeFromPair
parameter_list|(
specifier|const
name|NFA
modifier|&
name|a
parameter_list|,
specifier|const
name|NFA
modifier|&
name|b
parameter_list|,
name|int
modifier|*
name|initialA
parameter_list|,
name|int
modifier|*
name|finalA
parameter_list|,
name|int
modifier|*
name|initialB
parameter_list|,
name|int
modifier|*
name|finalB
parameter_list|)
function_decl|;
name|QSet
operator|<
name|int
operator|>
name|epsilonClosure
argument_list|(
argument|const QSet<int>&initialClosure
argument_list|)
specifier|const
expr_stmt|;
specifier|inline
name|void
name|assertValidState
parameter_list|(
name|int
name|state
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|state
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|state
operator|>=
literal|0
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|state
operator|<
name|states
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|AUTOTEST
argument_list|)
name|public
label|:
endif|#
directive|endif
name|int
name|initialState
decl_stmt|;
name|int
name|finalState
decl_stmt|;
name|QVector
operator|<
name|State
operator|>
name|states
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// NFA_H
end_comment
end_unit
