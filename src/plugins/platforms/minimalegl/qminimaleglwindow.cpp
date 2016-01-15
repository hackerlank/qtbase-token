begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|"qminimaleglwindow.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QMinimalEglWindow
name|QMinimalEglWindow
operator|::
name|QMinimalEglWindow
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
member_init_list|:
name|QPlatformWindow
argument_list|(
name|w
argument_list|)
block|{
specifier|static
name|int
name|serialNo
init|=
literal|0
decl_stmt|;
name|m_winid
operator|=
operator|++
name|serialNo
expr_stmt|;
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglWindow %p: %p 0x%x\n"
argument_list|,
name|this
argument_list|,
name|w
argument_list|,
name|uint
argument_list|(
name|m_winid
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QRect
name|screenGeometry
argument_list|(
name|screen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|w
operator|->
name|geometry
argument_list|()
operator|!=
name|screenGeometry
condition|)
block|{
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|w
argument_list|,
name|screenGeometry
argument_list|)
expr_stmt|;
block|}
name|w
operator|->
name|setSurfaceType
argument_list|(
name|QSurface
operator|::
name|OpenGLSurface
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setGeometry
name|void
name|QMinimalEglWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
parameter_list|)
block|{
comment|// We only support full-screen windows
name|QRect
name|rect
argument_list|(
name|screen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
argument_list|)
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|window
argument_list|()
argument_list|,
name|rect
argument_list|)
expr_stmt|;
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|winId
name|WId
name|QMinimalEglWindow
operator|::
name|winId
parameter_list|()
specifier|const
block|{
return|return
name|m_winid
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
