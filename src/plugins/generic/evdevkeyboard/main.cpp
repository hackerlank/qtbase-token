begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/qgenericplugin.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qevdevkeyboardmanager_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QEvdevKeyboardPlugin
class|class
name|QEvdevKeyboardPlugin
super|:
specifier|public
name|QGenericPlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
name|IID
name|QGenericPluginFactoryInterface_iid
name|FILE
literal|"evdevkeyboard.json"
argument_list|)
decl|public
range|:
name|QEvdevKeyboardPlugin
argument_list|()
decl_stmt|;
DECL|member|Q_DECL_OVERRIDE
name|QObject
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QString
modifier|&
name|specification
parameter_list|)
name|Q_DECL_OVERRIDE
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|QEvdevKeyboardPlugin
name|QEvdevKeyboardPlugin
operator|::
name|QEvdevKeyboardPlugin
parameter_list|()
member_init_list|:
name|QGenericPlugin
argument_list|()
block|{ }
end_constructor
begin_function
DECL|function|create
name|QObject
modifier|*
name|QEvdevKeyboardPlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QString
modifier|&
name|specification
parameter_list|)
block|{
if|if
condition|(
operator|!
name|key
operator|.
name|compare
argument_list|(
name|QLatin1String
argument_list|(
literal|"EvdevKeyboard"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
return|return
operator|new
name|QEvdevKeyboardManager
argument_list|(
name|key
argument_list|,
name|specification
argument_list|)
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
