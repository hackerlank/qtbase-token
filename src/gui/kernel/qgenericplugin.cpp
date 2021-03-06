begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qgenericplugin.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QGenericPlugin     \ingroup plugins     \inmodule QtGui      \brief The QGenericPlugin class is an abstract base class for     plugins.      A mouse plugin can be created by subclassing     QGenericPlugin and reimplementing the pure virtual create()     function. By exporting the derived class using the     Q_PLUGIN_METADATA() macro, The default implementation of the     QGenericPluginFactory class will automatically detect the plugin and     load the driver into the server application at run-time. See \l     {How to Create Qt Plugins} for details.      The json metadata file should contain a list of keys supported by this     plugin.      \sa QGenericPluginFactory */
end_comment
begin_comment
comment|/*!     Constructs a plugin with the given \a parent.      Note that this constructor is invoked automatically by the     moc generated code that exports the plugin, so there is no need for calling it     explicitly. */
end_comment
begin_constructor
DECL|function|QGenericPlugin
name|QGenericPlugin
operator|::
name|QGenericPlugin
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the plugin.      Note that Qt destroys a plugin automatically when it is no longer     used, so there is no need for calling the destructor explicitly. */
end_comment
begin_destructor
DECL|function|~QGenericPlugin
name|QGenericPlugin
operator|::
name|~
name|QGenericPlugin
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \fn QObject* QGenericPlugin::create(const QString&key, const QString& specification)      Implement this function to create a driver matching the type     specified by the given \a key and \a specification parameters. Note that     keys are case-insensitive. */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
