begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qgenericengine.h"
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
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QGenericEnginePlugin
class|class
name|QGenericEnginePlugin
super|:
specifier|public
name|QBearerEnginePlugin
block|{
public|public:
name|QGenericEnginePlugin
parameter_list|()
constructor_decl|;
name|~
name|QGenericEnginePlugin
parameter_list|()
destructor_decl|;
name|QStringList
name|keys
parameter_list|()
specifier|const
function_decl|;
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
DECL|function|QGenericEnginePlugin
name|QGenericEnginePlugin
operator|::
name|QGenericEnginePlugin
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~QGenericEnginePlugin
name|QGenericEnginePlugin
operator|::
name|~
name|QGenericEnginePlugin
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|keys
name|QStringList
name|QGenericEnginePlugin
operator|::
name|keys
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"generic"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|create
name|QBearerEngine
modifier|*
name|QGenericEnginePlugin
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
literal|"generic"
argument_list|)
condition|)
return|return
operator|new
name|QGenericEngine
return|;
else|else
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|Q_EXPORT_STATIC_PLUGIN
argument_list|(
argument|QGenericEnginePlugin
argument_list|)
end_macro
begin_macro
name|Q_EXPORT_PLUGIN2
argument_list|(
argument|qgenericbearer
argument_list|,
argument|QGenericEnginePlugin
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_BEARERMANAGEMENT
end_comment
end_unit
