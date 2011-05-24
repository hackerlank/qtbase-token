begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qsqldriverplugin.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|"../../../sql/drivers/oci/qsql_oci.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QOCIDriverPlugin
class|class
name|QOCIDriverPlugin
super|:
specifier|public
name|QSqlDriverPlugin
block|{
public|public:
name|QOCIDriverPlugin
parameter_list|()
constructor_decl|;
name|QSqlDriver
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|QStringList
name|keys
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|QOCIDriverPlugin
name|QOCIDriverPlugin
operator|::
name|QOCIDriverPlugin
parameter_list|()
member_init_list|:
name|QSqlDriverPlugin
argument_list|()
block|{ }
end_constructor
begin_function
DECL|function|create
name|QSqlDriver
modifier|*
name|QOCIDriverPlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
if|if
condition|(
name|name
operator|==
name|QLatin1String
argument_list|(
literal|"QOCI"
argument_list|)
operator|||
name|name
operator|==
name|QLatin1String
argument_list|(
literal|"QOCI8"
argument_list|)
condition|)
block|{
name|QOCIDriver
modifier|*
name|driver
init|=
operator|new
name|QOCIDriver
argument_list|()
decl_stmt|;
return|return
name|driver
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|keys
name|QStringList
name|QOCIDriverPlugin
operator|::
name|keys
parameter_list|()
specifier|const
block|{
name|QStringList
name|l
decl_stmt|;
name|l
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"QOCI8"
argument_list|)
argument_list|)
expr_stmt|;
name|l
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"QOCI"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|l
return|;
block|}
end_function
begin_macro
name|Q_EXPORT_STATIC_PLUGIN
argument_list|(
argument|QOCIDriverPlugin
argument_list|)
end_macro
begin_macro
name|Q_EXPORT_PLUGIN2
argument_list|(
argument|qsqloci
argument_list|,
argument|QOCIDriverPlugin
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
