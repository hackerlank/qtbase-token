begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|"../../../sql/drivers/mysql/qsql_mysql_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QMYSQLDriverPlugin
class|class
name|QMYSQLDriverPlugin
super|:
specifier|public
name|QSqlDriverPlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
name|IID
literal|"org.qt-project.Qt.QSqlDriverFactoryInterface"
name|FILE
literal|"mysql.json"
argument_list|)
decl|public
range|:
name|QMYSQLDriverPlugin
argument_list|()
decl_stmt|;
DECL|member|Q_DECL_OVERRIDE
name|QSqlDriver
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
name|Q_DECL_OVERRIDE
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|QMYSQLDriverPlugin
name|QMYSQLDriverPlugin
operator|::
name|QMYSQLDriverPlugin
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
name|QMYSQLDriverPlugin
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
literal|"QMYSQL"
argument_list|)
operator|||
name|name
operator|==
name|QLatin1String
argument_list|(
literal|"QMYSQL3"
argument_list|)
condition|)
block|{
name|QMYSQLDriver
modifier|*
name|driver
init|=
operator|new
name|QMYSQLDriver
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
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
