begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnlaengine.h"
end_include
begin_include
include|#
directive|include
file|<QtNetwork/private/qbearerplugin_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QNlaEnginePlugin
class|class
name|QNlaEnginePlugin
super|:
specifier|public
name|QBearerEnginePlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
name|IID
literal|"org.qt-project.Qt.QBearerEngineFactoryInterface"
name|FILE
literal|"nla.json"
argument_list|)
decl|public
range|:
name|QNlaEnginePlugin
argument_list|()
decl_stmt|;
name|~
name|QNlaEnginePlugin
parameter_list|()
destructor_decl|;
name|QBearerEngine
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
specifier|const
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|QNlaEnginePlugin
name|QNlaEnginePlugin
operator|::
name|QNlaEnginePlugin
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~QNlaEnginePlugin
name|QNlaEnginePlugin
operator|::
name|~
name|QNlaEnginePlugin
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|create
name|QBearerEngine
modifier|*
name|QNlaEnginePlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|key
operator|==
name|QLatin1String
argument_list|(
literal|"nla"
argument_list|)
condition|)
return|return
operator|new
name|QNlaEngine
return|;
else|else
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
