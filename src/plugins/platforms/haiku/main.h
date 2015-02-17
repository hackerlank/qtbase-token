begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2015 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Tobias Koenig<tobias.koenig@kdab.com> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qpa/qplatformintegrationplugin.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QHaikuIntegrationPlugin
range|:
name|public
name|QPlatformIntegrationPlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
argument|IID
literal|"org.qt-project.Qt.QPA.QPlatformIntegrationFactoryInterface.5.2"
argument|FILE
literal|"haiku.json"
argument_list|)
name|public
operator|:
name|QPlatformIntegration
operator|*
name|create
argument_list|(
argument|const QString&
argument_list|,
argument|const QStringList&
argument_list|)
name|Q_DECL_OVERRIDE
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit