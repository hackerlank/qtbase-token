begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQLINDEX_H
end_ifndef
begin_define
DECL|macro|QSQLINDEX_H
define|#
directive|define
name|QSQLINDEX_H
end_define
begin_include
include|#
directive|include
file|<QtSql/qsqlrecord.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Sql
argument_list|)
name|class
name|Q_SQL_EXPORT
name|QSqlIndex
range|:
name|public
name|QSqlRecord
block|{
name|public
operator|:
name|QSqlIndex
argument_list|(
specifier|const
name|QString
operator|&
name|cursorName
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QString
operator|&
name|name
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|QSqlIndex
argument_list|(
specifier|const
name|QSqlIndex
operator|&
name|other
argument_list|)
block|;
operator|~
name|QSqlIndex
argument_list|()
block|;
name|QSqlIndex
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QSqlIndex
operator|&
name|other
operator|)
block|;
name|void
name|setCursorName
argument_list|(
specifier|const
name|QString
operator|&
name|cursorName
argument_list|)
block|;
specifier|inline
name|QString
name|cursorName
argument_list|()
specifier|const
block|{
return|return
name|cursor
return|;
block|}
name|void
name|setName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
specifier|inline
name|QString
name|name
argument_list|()
specifier|const
block|{
return|return
name|nm
return|;
block|}
name|void
name|append
argument_list|(
specifier|const
name|QSqlField
operator|&
name|field
argument_list|)
block|;
name|void
name|append
argument_list|(
argument|const QSqlField&field
argument_list|,
argument|bool desc
argument_list|)
block|;
name|bool
name|isDescending
argument_list|(
argument|int i
argument_list|)
specifier|const
block|;
name|void
name|setDescending
argument_list|(
argument|int i
argument_list|,
argument|bool desc
argument_list|)
block|;
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|QT3_SUPPORT
name|QString
name|toString
argument_list|(
argument|const QString&prefix = QString()
argument_list|,
argument|const QString&sep = QLatin1String(
literal|","
argument|)
argument_list|,
argument|bool verbose = true
argument_list|)
specifier|const
block|;
name|QT3_SUPPORT
name|QStringList
name|toStringList
argument_list|(
argument|const QString& prefix = QString()
argument_list|,
argument|bool verbose = true
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|private
operator|:
name|QString
name|createField
argument_list|(
argument|int i
argument_list|,
argument|const QString& prefix
argument_list|,
argument|bool verbose
argument_list|)
specifier|const
block|;
name|QString
name|cursor
block|;
name|QString
name|nm
block|;
name|QList
operator|<
name|bool
operator|>
name|sorts
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSQLINDEX_H
end_comment
end_unit
