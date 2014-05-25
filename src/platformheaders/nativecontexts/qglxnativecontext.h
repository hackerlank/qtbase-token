begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLXNATIVECONTEXT_H
end_ifndef
begin_define
DECL|macro|QGLXNATIVECONTEXT_H
define|#
directive|define
name|QGLXNATIVECONTEXT_H
end_define
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_include
include|#
directive|include
file|<GL/glx.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QGLXNativeContext
struct|struct
name|QGLXNativeContext
block|{
DECL|function|QGLXNativeContext
name|QGLXNativeContext
argument_list|()
operator|:
name|m_context
argument_list|(
literal|0
argument_list|)
operator|,
name|m_display
argument_list|(
literal|0
argument_list|)
operator|,
name|m_window
argument_list|(
literal|0
argument_list|)
operator|,
name|m_visualId
argument_list|(
literal|0
argument_list|)
block|{ }
DECL|function|QGLXNativeContext
name|QGLXNativeContext
argument_list|(
argument|GLXContext ctx
argument_list|,
argument|Display *dpy =
literal|0
argument_list|,
argument|Window wnd =
literal|0
argument_list|,
argument|VisualID vid =
literal|0
argument_list|)
operator|:
name|m_context
argument_list|(
name|ctx
argument_list|)
operator|,
name|m_display
argument_list|(
name|dpy
argument_list|)
operator|,
name|m_window
argument_list|(
name|wnd
argument_list|)
operator|,
name|m_visualId
argument_list|(
argument|vid
argument_list|)
block|{ }
DECL|function|context
name|GLXContext
name|context
argument_list|()
specifier|const
block|{
return|return
name|m_context
return|;
block|}
DECL|function|display
name|Display
operator|*
name|display
argument_list|()
specifier|const
block|{
return|return
name|m_display
return|;
block|}
DECL|function|window
name|Window
name|window
argument_list|()
specifier|const
block|{
return|return
name|m_window
return|;
block|}
DECL|function|visualId
name|VisualID
name|visualId
argument_list|()
specifier|const
block|{
return|return
name|m_visualId
return|;
block|}
DECL|member|private
name|private
label|:
name|GLXContext
name|m_context
decl_stmt|;
DECL|member|m_display
name|Display
modifier|*
name|m_display
decl_stmt|;
DECL|member|m_window
name|Window
name|m_window
decl_stmt|;
DECL|member|m_visualId
name|VisualID
name|m_visualId
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QGLXNativeContext
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGLXNATIVECONTEXT_H
end_comment
end_unit