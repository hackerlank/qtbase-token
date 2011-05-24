begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLPROPERTIES_P_H
end_ifndef
begin_define
DECL|macro|QEGLPROPERTIES_P_H
define|#
directive|define
name|QEGLPROPERTIES_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QtOpenGL and QtOpenVG modules.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qvarlengtharray.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qimage.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qegl_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QX11Info
name|class
name|QX11Info
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPaintDevice
name|class
name|QPaintDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QEglProperties
block|{
name|public
label|:
name|QEglProperties
argument_list|()
expr_stmt|;
name|QEglProperties
argument_list|(
name|EGLConfig
argument_list|)
expr_stmt|;
name|QEglProperties
argument_list|(
specifier|const
name|QEglProperties
operator|&
name|other
argument_list|)
operator|:
name|props
argument_list|(
argument|other.props
argument_list|)
block|{}
operator|~
name|QEglProperties
argument_list|()
block|{}
name|int
name|value
argument_list|(
argument|int name
argument_list|)
specifier|const
expr_stmt|;
name|void
name|setValue
parameter_list|(
name|int
name|name
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
name|bool
name|removeValue
parameter_list|(
name|int
name|name
parameter_list|)
function_decl|;
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|props
index|[
literal|0
index|]
operator|==
name|EGL_NONE
return|;
block|}
specifier|const
name|int
operator|*
name|properties
argument_list|()
specifier|const
block|{
return|return
name|props
operator|.
name|constData
argument_list|()
return|;
block|}
name|void
name|setPixelFormat
argument_list|(
name|QImage
operator|::
name|Format
name|pixelFormat
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_X11
name|void
name|setVisualFormat
parameter_list|(
specifier|const
name|QX11Info
modifier|*
name|xinfo
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
name|setDeviceType
parameter_list|(
name|int
name|devType
parameter_list|)
function_decl|;
name|void
name|setPaintDeviceFormat
parameter_list|(
name|QPaintDevice
modifier|*
name|dev
parameter_list|)
function_decl|;
name|void
name|setRenderableType
argument_list|(
name|QEgl
operator|::
name|API
name|api
argument_list|)
decl_stmt|;
name|bool
name|reduceConfiguration
parameter_list|()
function_decl|;
name|QString
name|toString
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QVarLengthArray
operator|<
name|int
operator|>
name|props
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
comment|// QEGLPROPERTIES_P_H
end_comment
end_unit
