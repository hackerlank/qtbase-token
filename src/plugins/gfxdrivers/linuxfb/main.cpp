begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qscreendriverplugin_qws.h>
end_include
begin_include
include|#
directive|include
file|<qscreenlinuxfb_qws.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QScreenLinuxFbPlugin
class|class
name|QScreenLinuxFbPlugin
super|:
specifier|public
name|QScreenDriverPlugin
block|{
public|public:
name|QScreenLinuxFbPlugin
parameter_list|()
constructor_decl|;
name|QStringList
name|keys
parameter_list|()
specifier|const
function_decl|;
name|QScreen
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
name|int
name|displayId
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|QScreenLinuxFbPlugin
name|QScreenLinuxFbPlugin
operator|::
name|QScreenLinuxFbPlugin
parameter_list|()
member_init_list|:
name|QScreenDriverPlugin
argument_list|()
block|{ }
end_constructor
begin_function
DECL|function|keys
name|QStringList
name|QScreenLinuxFbPlugin
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
name|QLatin1String
argument_list|(
literal|"LinuxFb"
argument_list|)
expr_stmt|;
return|return
name|list
return|;
block|}
end_function
begin_function
DECL|function|create
name|QScreen
modifier|*
name|QScreenLinuxFbPlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|driver
parameter_list|,
name|int
name|displayId
parameter_list|)
block|{
if|if
condition|(
name|driver
operator|.
name|toLower
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"linuxfb"
argument_list|)
condition|)
return|return
operator|new
name|QLinuxFbScreen
argument_list|(
name|displayId
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|Q_EXPORT_PLUGIN2
argument_list|(
argument|qscreenlinuxfb
argument_list|,
argument|QScreenLinuxFbPlugin
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
