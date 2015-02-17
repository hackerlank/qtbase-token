begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2015 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Tobias Koenig<tobias.koenig@kdab.com> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qhaikuintegration.h"
end_include
begin_include
include|#
directive|include
file|"qhaikuapplication.h"
end_include
begin_include
include|#
directive|include
file|"qhaikuclipboard.h"
end_include
begin_include
include|#
directive|include
file|"qhaikurasterbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qhaikurasterwindow.h"
end_include
begin_include
include|#
directive|include
file|"qhaikuscreen.h"
end_include
begin_include
include|#
directive|include
file|"qhaikuservices.h"
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QFileInfo>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixeventdispatcher_p.h>
end_include
begin_include
include|#
directive|include
file|<Application.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|startApplicationThread
specifier|static
name|long
name|int
name|startApplicationThread
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
block|{
name|QHaikuApplication
modifier|*
name|app
init|=
cast|static_cast
argument_list|<
name|QHaikuApplication
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|app
operator|->
name|LockLooper
argument_list|()
expr_stmt|;
return|return
name|app
operator|->
name|Run
argument_list|()
return|;
block|}
end_function
begin_constructor
DECL|function|QHaikuIntegration
name|QHaikuIntegration
operator|::
name|QHaikuIntegration
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|parameters
parameter_list|)
member_init_list|:
name|m_clipboard
argument_list|(
operator|new
name|QHaikuClipboard
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|parameters
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|signature
init|=
name|QStringLiteral
argument_list|(
literal|"application/x-vnd.Qt.%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QFileInfo
argument_list|(
name|QCoreApplication
operator|::
name|applicationFilePath
argument_list|()
argument_list|)
operator|.
name|fileName
argument_list|()
argument_list|)
decl_stmt|;
name|QHaikuApplication
modifier|*
name|app
init|=
operator|new
name|QHaikuApplication
argument_list|(
name|signature
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
decl_stmt|;
name|be_app
operator|=
name|app
expr_stmt|;
specifier|const
name|thread_id
name|applicationThreadId
init|=
name|spawn_thread
argument_list|(
name|startApplicationThread
argument_list|,
literal|"app_thread"
argument_list|,
literal|1
argument_list|,
cast|static_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
name|app
argument_list|)
argument_list|)
decl_stmt|;
name|resume_thread
argument_list|(
name|applicationThreadId
argument_list|)
expr_stmt|;
name|app
operator|->
name|UnlockLooper
argument_list|()
expr_stmt|;
name|m_screen
operator|=
operator|new
name|QHaikuScreen
expr_stmt|;
name|m_services
operator|=
operator|new
name|QHaikuServices
expr_stmt|;
comment|// notify system about available screen
name|screenAdded
argument_list|(
name|m_screen
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QHaikuIntegration
name|QHaikuIntegration
operator|::
name|~
name|QHaikuIntegration
parameter_list|()
block|{
name|destroyScreen
argument_list|(
name|m_screen
argument_list|)
expr_stmt|;
name|m_screen
operator|=
name|Q_NULLPTR
expr_stmt|;
operator|delete
name|m_services
expr_stmt|;
name|m_services
operator|=
name|Q_NULLPTR
expr_stmt|;
operator|delete
name|m_clipboard
expr_stmt|;
name|m_clipboard
operator|=
name|Q_NULLPTR
expr_stmt|;
name|be_app
operator|->
name|LockLooper
argument_list|()
expr_stmt|;
name|be_app
operator|->
name|Quit
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|hasCapability
name|bool
name|QHaikuIntegration
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|capability
parameter_list|)
specifier|const
block|{
return|return
name|QPlatformIntegration
operator|::
name|hasCapability
argument_list|(
name|capability
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QHaikuIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
return|return
name|QPlatformIntegration
operator|::
name|fontDatabase
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|services
name|QPlatformServices
modifier|*
name|QHaikuIntegration
operator|::
name|services
parameter_list|()
specifier|const
block|{
return|return
name|m_services
return|;
block|}
end_function
begin_function
DECL|function|clipboard
name|QPlatformClipboard
modifier|*
name|QHaikuIntegration
operator|::
name|clipboard
parameter_list|()
specifier|const
block|{
return|return
name|m_clipboard
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QHaikuIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
name|QPlatformWindow
modifier|*
name|platformWindow
init|=
operator|new
name|QHaikuRasterWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|platformWindow
operator|->
name|requestActivateWindow
argument_list|()
expr_stmt|;
return|return
name|platformWindow
return|;
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QHaikuIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QHaikuRasterBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QHaikuIntegration
operator|::
name|createEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
name|createUnixEventDispatcher
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit