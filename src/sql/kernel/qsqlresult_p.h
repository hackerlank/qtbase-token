begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQLRESULT_P_H
end_ifndef
begin_define
DECL|macro|QSQLRESULT_P_H
define|#
directive|define
name|QSQLRESULT_P_H
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
comment|// of qsql*model.h .  This header file may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
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
file|<QtCore/qpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtSql/qsqldriver.h>
end_include
begin_include
include|#
directive|include
file|"qsqlerror.h"
end_include
begin_include
include|#
directive|include
file|"qsqlresult.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QHolder
struct|struct
name|QHolder
block|{
DECL|function|QHolder
name|QHolder
argument_list|(
argument|const QString&hldr = QString()
argument_list|,
argument|int index = -
literal|1
argument_list|)
block|:
name|holderName
argument_list|(
name|hldr
argument_list|)
operator|,
name|holderPos
argument_list|(
argument|index
argument_list|)
block|{ }
DECL|function|operator
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QHolder
operator|&
name|h
operator|)
specifier|const
block|{
return|return
name|h
operator|.
name|holderPos
operator|==
name|holderPos
operator|&&
name|h
operator|.
name|holderName
operator|==
name|holderName
return|;
block|}
DECL|function|operator
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QHolder
operator|&
name|h
operator|)
specifier|const
block|{
return|return
name|h
operator|.
name|holderPos
operator|!=
name|holderPos
operator|||
name|h
operator|.
name|holderName
operator|!=
name|holderName
return|;
block|}
DECL|member|holderName
name|QString
name|holderName
decl_stmt|;
DECL|member|holderPos
name|int
name|holderPos
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|Q_SQL_EXPORT
name|QSqlResultPrivate
block|{
name|public
label|:
name|QSqlResultPrivate
argument_list|()
operator|:
name|q_ptr
argument_list|(
literal|0
argument_list|)
operator|,
name|idx
argument_list|(
name|QSql
operator|::
name|BeforeFirstRow
argument_list|)
operator|,
name|active
argument_list|(
name|false
argument_list|)
operator|,
name|isSel
argument_list|(
name|false
argument_list|)
operator|,
name|forwardOnly
argument_list|(
name|false
argument_list|)
operator|,
name|precisionPolicy
argument_list|(
name|QSql
operator|::
name|LowPrecisionDouble
argument_list|)
operator|,
name|bindCount
argument_list|(
literal|0
argument_list|)
operator|,
name|binds
argument_list|(
argument|QSqlResult::PositionalBinding
argument_list|)
block|{ }
name|virtual
operator|~
name|QSqlResultPrivate
argument_list|()
block|{ }
name|void
name|clearValues
argument_list|()
block|{
name|values
operator|.
name|clear
argument_list|()
block|;
name|bindCount
operator|=
literal|0
block|;     }
name|void
name|resetBindCount
argument_list|()
block|{
name|bindCount
operator|=
literal|0
block|;     }
name|void
name|clearIndex
argument_list|()
block|{
name|indexes
operator|.
name|clear
argument_list|()
block|;
name|holders
operator|.
name|clear
argument_list|()
block|;
name|types
operator|.
name|clear
argument_list|()
block|;     }
name|void
name|clear
argument_list|()
block|{
name|clearValues
argument_list|()
block|;
name|clearIndex
argument_list|()
block|;;     }
name|virtual
name|QString
name|fieldSerial
argument_list|(
argument|int
argument_list|)
specifier|const
expr_stmt|;
name|QString
name|positionalToNamedBinding
argument_list|(
specifier|const
name|QString
operator|&
name|query
argument_list|)
decl|const
decl_stmt|;
name|QString
name|namedToPositionalBinding
parameter_list|(
specifier|const
name|QString
modifier|&
name|query
parameter_list|)
function_decl|;
name|QString
name|holderAt
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|QSqlResult
modifier|*
name|q_ptr
decl_stmt|;
name|QPointer
operator|<
name|QSqlDriver
operator|>
name|sqldriver
expr_stmt|;
name|int
name|idx
decl_stmt|;
name|QString
name|sql
decl_stmt|;
name|bool
name|active
decl_stmt|;
name|bool
name|isSel
decl_stmt|;
name|QSqlError
name|error
decl_stmt|;
name|bool
name|forwardOnly
decl_stmt|;
name|QSql
operator|::
name|NumericalPrecisionPolicy
name|precisionPolicy
expr_stmt|;
name|int
name|bindCount
decl_stmt|;
name|QSqlResult
operator|::
name|BindingSyntax
name|binds
expr_stmt|;
name|QString
name|executedQuery
decl_stmt|;
name|QHash
operator|<
name|int
operator|,
name|QSql
operator|::
name|ParamType
operator|>
name|types
expr_stmt|;
name|QVector
operator|<
name|QVariant
operator|>
name|values
expr_stmt|;
typedef|typedef
name|QHash
operator|<
name|QString
operator|,
name|QList
operator|<
name|int
operator|>
expr|>
name|IndexMap
expr_stmt|;
name|IndexMap
name|indexes
decl_stmt|;
typedef|typedef
name|QVector
operator|<
name|QHolder
operator|>
name|QHolderVector
expr_stmt|;
name|QHolderVector
name|holders
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSQLRESULT_P_H
end_comment
end_unit
