begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenVG module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QVG_P_H
end_ifndef
begin_define
DECL|macro|QVG_P_H
define|#
directive|define
name|QVG_P_H
end_define
begin_include
include|#
directive|include
file|"qvg.h"
end_include
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
comment|// of other Qt classes.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
begin_comment
comment|// vgDrawGlyphs() only exists in OpenVG 1.1 and higher.
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|OPENVG_VERSION_1_1
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QVG_NO_DRAW_GLYPHS
argument_list|)
end_if
begin_define
DECL|macro|QVG_NO_DRAW_GLYPHS
define|#
directive|define
name|QVG_NO_DRAW_GLYPHS
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtGui/qimage.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_EGL
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtGui/private/qeglcontext_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QVGPaintEngine
name|class
name|QVGPaintEngine
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_EGL
argument_list|)
end_if
begin_decl_stmt
DECL|variable|QEglContext
name|class
name|QEglContext
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Create an EGL context, but don't bind it to a surface.  If single-context
end_comment
begin_comment
comment|// mode is enabled, this will return the previously-created context.
end_comment
begin_comment
comment|// "devType" indicates the type of device using the context, usually
end_comment
begin_comment
comment|// QInternal::Widget or QInternal::Pixmap.
end_comment
begin_function_decl
name|Q_OPENVG_EXPORT
name|QEglContext
modifier|*
name|qt_vg_create_context
parameter_list|(
name|QPaintDevice
modifier|*
name|device
parameter_list|,
name|int
name|devType
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// Destroy an EGL context that was created by qt_vg_create_context().
end_comment
begin_comment
comment|// If single-context mode is enabled, this will decrease the reference count.
end_comment
begin_comment
comment|// "devType" indicates the type of device destroying the context, usually
end_comment
begin_comment
comment|// QInternal::Widget or QInternal::Pixmap.
end_comment
begin_function_decl
name|Q_OPENVG_EXPORT
name|void
name|qt_vg_destroy_context
parameter_list|(
name|QEglContext
modifier|*
name|context
parameter_list|,
name|int
name|devType
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// Return the shared pbuffer surface that can be made current to
end_comment
begin_comment
comment|// destroy VGImage objects when there is no other surface available.
end_comment
begin_function_decl
name|Q_OPENVG_EXPORT
name|EGLSurface
name|qt_vg_shared_surface
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// Convert the configuration format in a context to a VG or QImage format.
end_comment
begin_function_decl
name|Q_OPENVG_EXPORT
name|VGImageFormat
name|qt_vg_config_to_vg_format
parameter_list|(
name|QEglContext
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|Q_OPENVG_EXPORT
name|QImage
operator|::
name|Format
name|qt_vg_config_to_image_format
argument_list|(
name|QEglContext
operator|*
name|context
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Create a paint engine.  Returns the common engine in single-context mode.
end_comment
begin_function_decl
name|Q_OPENVG_EXPORT
name|QVGPaintEngine
modifier|*
name|qt_vg_create_paint_engine
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// Destroy a paint engine.  Does nothing in single-context mode.
end_comment
begin_function_decl
name|Q_OPENVG_EXPORT
name|void
name|qt_vg_destroy_paint_engine
parameter_list|(
name|QVGPaintEngine
modifier|*
name|engine
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// Convert between QImage and VGImage format values.
end_comment
begin_decl_stmt
name|Q_OPENVG_EXPORT
name|VGImageFormat
name|qt_vg_image_to_vg_format
argument_list|(
name|QImage
operator|::
name|Format
name|format
argument_list|)
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
