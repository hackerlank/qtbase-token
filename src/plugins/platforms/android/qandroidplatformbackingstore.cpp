begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 BogDan Vatra<bogdan@kde.org> ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qandroidplatformbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformscreen.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformwindow.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QAndroidPlatformBackingStore
name|QAndroidPlatformBackingStore
operator|::
name|QAndroidPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformBackingStore
argument_list|(
name|window
argument_list|)
block|{
if|if
condition|(
name|window
operator|->
name|handle
argument_list|()
condition|)
name|setBackingStore
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QAndroidPlatformBackingStore
operator|::
name|paintDevice
parameter_list|()
block|{
return|return
operator|&
name|m_image
return|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QAndroidPlatformBackingStore
operator|::
name|flush
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|offset
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_backingStoreSet
condition|)
name|setBackingStore
argument_list|(
name|window
argument_list|)
expr_stmt|;
operator|(
cast|static_cast
argument_list|<
name|QAndroidPlatformWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
operator|)
operator|->
name|repaint
argument_list|(
name|region
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QAndroidPlatformBackingStore
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|staticContents
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|staticContents
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_image
operator|.
name|size
argument_list|()
operator|!=
name|size
condition|)
name|m_image
operator|=
name|QImage
argument_list|(
name|size
argument_list|,
name|window
argument_list|()
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
operator|->
name|format
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setBackingStore
name|void
name|QAndroidPlatformBackingStore
operator|::
name|setBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
if|if
condition|(
name|window
operator|->
name|surfaceType
argument_list|()
operator|==
name|QSurface
operator|::
name|RasterSurface
operator|||
name|window
operator|->
name|surfaceType
argument_list|()
operator|==
name|QSurface
operator|::
name|RasterGLSurface
condition|)
block|{
operator|(
cast|static_cast
argument_list|<
name|QAndroidPlatformWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
operator|)
operator|->
name|setBackingStore
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_backingStoreSet
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QAndroidPlatformBackingStore does not support OpenGL-only windows."
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
