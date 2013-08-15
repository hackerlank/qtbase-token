begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QANDROIDOPENGLPLATFORMWINDOW_H
end_ifndef
begin_define
DECL|macro|QANDROIDOPENGLPLATFORMWINDOW_H
define|#
directive|define
name|QANDROIDOPENGLPLATFORMWINDOW_H
end_define
begin_include
include|#
directive|include
file|"qeglfswindow.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qreadwritelock.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QAndroidOpenGLPlatformWindow
range|:
name|public
name|QEglFSWindow
block|{
name|public
operator|:
name|QAndroidOpenGLPlatformWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
operator|~
name|QAndroidOpenGLPlatformWindow
argument_list|()
block|;
name|QSize
name|scheduledResize
argument_list|()
specifier|const
block|{
return|return
name|m_scheduledResize
return|;
block|}
name|void
name|scheduleResize
argument_list|(
argument|const QSize&size
argument_list|)
block|{
name|m_scheduledResize
operator|=
name|size
block|; }
name|void
name|lock
argument_list|()
block|{
name|m_lock
operator|.
name|lock
argument_list|()
block|; }
name|void
name|unlock
argument_list|()
block|{
name|m_lock
operator|.
name|unlock
argument_list|()
block|; }
name|bool
name|isExposed
argument_list|()
specifier|const
block|;
name|void
name|raise
argument_list|()
block|;
name|void
name|invalidateSurface
argument_list|()
block|;
name|void
name|resetSurface
argument_list|()
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|destroy
argument_list|()
block|;
specifier|static
name|void
name|updateStaticNativeWindow
argument_list|()
block|;
name|private
operator|:
name|QSize
name|m_scheduledResize
block|;
name|QMutex
name|m_lock
block|;
specifier|static
name|QReadWriteLock
name|m_staticSurfaceLock
block|;
specifier|static
name|EGLSurface
name|m_staticSurface
block|;
specifier|static
name|EGLNativeWindowType
name|m_staticNativeWindow
block|;
specifier|static
name|QBasicAtomicInt
name|m_referenceCount
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QANDROIDOPENGLPLATFORMWINDOW_H
end_comment
end_unit
