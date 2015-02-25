begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLINUXFBINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QLINUXFBINTEGRATION_H
define|#
directive|define
name|QLINUXFBINTEGRATION_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAbstractEventDispatcher
name|class
name|QAbstractEventDispatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLinuxFbScreen
name|class
name|QLinuxFbScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFbVtHandler
name|class
name|QFbVtHandler
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformIntegration
name|class
name|QLinuxFbIntegration
range|:
name|public
name|QPlatformIntegration
decl_stmt|,
name|public
name|QPlatformNativeInterface
block|{
name|public
label|:
name|QLinuxFbIntegration
argument_list|(
specifier|const
name|QStringList
operator|&
name|paramList
argument_list|)
expr_stmt|;
operator|~
name|QLinuxFbIntegration
argument_list|()
expr_stmt|;
name|void
name|initialize
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|bool
name|hasCapability
argument_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QPlatformWindow
modifier|*
name|createPlatformWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QPlatformBackingStore
modifier|*
name|createPlatformBackingStore
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QAbstractEventDispatcher
operator|*
name|createEventDispatcher
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QPlatformServices
operator|*
name|services
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QPlatformInputContext
operator|*
name|inputContext
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_inputContext
return|;
block|}
name|QPlatformNativeInterface
operator|*
name|nativeInterface
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|screens
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|void
name|createInputHandlers
parameter_list|()
function_decl|;
name|QLinuxFbScreen
modifier|*
name|m_primaryScreen
decl_stmt|;
name|QPlatformInputContext
modifier|*
name|m_inputContext
decl_stmt|;
name|QScopedPointer
operator|<
name|QPlatformFontDatabase
operator|>
name|m_fontDb
expr_stmt|;
name|QScopedPointer
operator|<
name|QPlatformServices
operator|>
name|m_services
expr_stmt|;
name|QScopedPointer
operator|<
name|QFbVtHandler
operator|>
name|m_vtHandler
expr_stmt|;
name|QScopedPointer
operator|<
name|QPlatformNativeInterface
operator|>
name|m_nativeInterface
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLINUXFBINTEGRATION_H
end_comment
end_unit
