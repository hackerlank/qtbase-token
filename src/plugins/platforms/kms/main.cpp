begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qpa/qplatformintegrationplugin.h>
end_include
begin_include
include|#
directive|include
file|"qkmsintegration.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QKmsIntegrationPlugin
class|class
name|QKmsIntegrationPlugin
super|:
specifier|public
name|QPlatformIntegrationPlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
name|IID
literal|"org.qt-project.Qt.QPlatformIntegrationFactoryInterface"
name|FILE
literal|"kms.json"
argument_list|)
decl|public
range|:
name|QStringList
name|keys
argument_list|()
specifier|const
decl_stmt|;
name|QPlatformIntegration
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QStringList
modifier|&
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|keys
name|QStringList
name|QKmsIntegrationPlugin
operator|::
name|keys
parameter_list|()
specifier|const
block|{
name|QStringList
name|list
decl_stmt|;
name|list
operator|<<
literal|"kms"
expr_stmt|;
return|return
name|list
return|;
block|}
end_function
begin_function
DECL|function|create
name|QPlatformIntegration
modifier|*
name|QKmsIntegrationPlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|system
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|paramList
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|paramList
argument_list|)
expr_stmt|;
if|if
condition|(
name|system
operator|.
name|toLower
argument_list|()
operator|==
literal|"kms"
condition|)
return|return
operator|new
name|QKmsIntegration
return|;
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
