begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGL_P_H
end_ifndef
begin_define
DECL|macro|QEGL_P_H
define|#
directive|define
name|QEGL_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience of
end_comment
begin_comment
comment|// the QtGui and QtOpenVG modules.  This header file may change from
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
begin_macro
name|QT_BEGIN_INCLUDE_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_EGL
end_ifndef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_GLES_EGL
argument_list|)
end_if
begin_include
include|#
directive|include
file|<GLES/egl.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EGL_VERSION_1_2
argument_list|)
end_if
begin_typedef
DECL|typedef|EGLenum
typedef|typedef
name|unsigned
name|int
name|EGLenum
typedef|;
end_typedef
begin_typedef
DECL|typedef|EGLClientBuffer
typedef|typedef
name|void
modifier|*
name|EGLClientBuffer
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_comment
comment|//types from egltypes.h for compiling stub without EGL headers
end_comment
begin_typedef
typedef|typedef
name|int
name|EGLBoolean
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|int
name|EGLint
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|int
name|EGLenum
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|int
name|NativeDisplayType
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|void
modifier|*
name|NativeWindowType
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|void
modifier|*
name|NativePixmapType
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|int
name|EGLDisplay
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|int
name|EGLConfig
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|int
name|EGLSurface
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|int
name|EGLContext
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|int
name|EGLClientBuffer
typedef|;
end_typedef
begin_define
define|#
directive|define
name|EGL_NONE
value|0x3038
end_define
begin_comment
comment|/* Attrib list terminator */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Internally we use the EGL-prefixed native types which are used in EGL>= 1.3.
end_comment
begin_comment
comment|// For older versions of EGL, we have to define these types ourselves here:
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EGL_VERSION_1_3
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QEGL_NATIVE_TYPES_DEFINED
argument_list|)
end_if
begin_undef
DECL|macro|EGLNativeWindowType
undef|#
directive|undef
name|EGLNativeWindowType
end_undef
begin_undef
DECL|macro|EGLNativePixmapType
undef|#
directive|undef
name|EGLNativePixmapType
end_undef
begin_undef
DECL|macro|EGLNativeDisplayType
undef|#
directive|undef
name|EGLNativeDisplayType
end_undef
begin_typedef
DECL|typedef|EGLNativeWindowType
typedef|typedef
name|NativeWindowType
name|EGLNativeWindowType
typedef|;
end_typedef
begin_typedef
DECL|typedef|EGLNativePixmapType
typedef|typedef
name|NativePixmapType
name|EGLNativePixmapType
typedef|;
end_typedef
begin_typedef
DECL|typedef|EGLNativeDisplayType
typedef|typedef
name|NativeDisplayType
name|EGLNativeDisplayType
typedef|;
end_typedef
begin_define
DECL|macro|QEGL_NATIVE_TYPES_DEFINED
define|#
directive|define
name|QEGL_NATIVE_TYPES_DEFINED
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_INCLUDE_NAMESPACE
include|#
directive|include
file|<QtGui/qpaintdevice.h>
include|#
directive|include
file|<QFlags>
name|QT_BEGIN_NAMESPACE
end_expr_stmt
begin_define
DECL|macro|QEGL_NO_CONFIG
define|#
directive|define
name|QEGL_NO_CONFIG
value|((EGLConfig)-1)
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|EGLAPIENTRY
end_ifndef
begin_define
DECL|macro|EGLAPIENTRY
define|#
directive|define
name|EGLAPIENTRY
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Try to get some info to debug the symbian build failues:
end_comment
begin_comment
comment|// Declare/define the bits of EGL_KHR_image_base we need:
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EGL_KHR_image
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|EGL_KHR_image_base
argument_list|)
end_if
begin_typedef
DECL|typedef|EGLImageKHR
typedef|typedef
name|void
modifier|*
name|EGLImageKHR
typedef|;
end_typedef
begin_define
DECL|macro|EGL_NO_IMAGE_KHR
define|#
directive|define
name|EGL_NO_IMAGE_KHR
value|((EGLImageKHR)0)
end_define
begin_define
DECL|macro|EGL_IMAGE_PRESERVED_KHR
define|#
directive|define
name|EGL_IMAGE_PRESERVED_KHR
value|0x30D2
end_define
begin_define
DECL|macro|EGL_KHR_image_base
define|#
directive|define
name|EGL_KHR_image_base
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EGL_KHR_image
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|EGL_KHR_image_pixmap
argument_list|)
end_if
begin_define
DECL|macro|EGL_NATIVE_PIXMAP_KHR
define|#
directive|define
name|EGL_NATIVE_PIXMAP_KHR
value|0x30B0
end_define
begin_define
DECL|macro|EGL_KHR_image_pixmap
define|#
directive|define
name|EGL_KHR_image_pixmap
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QEglProperties
name|class
name|QEglProperties
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|QEgl
block|{
enum|enum
name|API
block|{
name|OpenGL
block|,
name|OpenVG
block|}
enum|;
enum|enum
name|PixelFormatMatch
block|{
name|ExactPixelFormat
block|,
name|BestPixelFormat
block|}
enum|;
enum|enum
name|ConfigOption
block|{
name|NoOptions
init|=
literal|0
block|,
name|Translucent
init|=
literal|0x01
block|,
name|Renderable
init|=
literal|0x02
comment|// Config will be compatable with the paint engines (VG or GL)
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|ConfigOptions
argument_list|,
argument|ConfigOption
argument_list|)
comment|// Most of the time we use the same config for things like widgets& pixmaps, so rather than
comment|// go through the eglChooseConfig loop every time, we use defaultConfig, which will return
comment|// the config for a particular device/api/option combo. This function assumes that once a
comment|// config is chosen for a particular combo, it's safe to always use that combo.
name|Q_GUI_EXPORT
name|EGLConfig
name|defaultConfig
parameter_list|(
name|int
name|devType
parameter_list|,
name|API
name|api
parameter_list|,
name|ConfigOptions
name|options
parameter_list|)
function_decl|;
name|Q_GUI_EXPORT
name|EGLConfig
name|chooseConfig
argument_list|(
specifier|const
name|QEglProperties
operator|*
name|configAttribs
argument_list|,
name|QEgl
operator|::
name|PixelFormatMatch
name|match
operator|=
name|QEgl
operator|::
name|ExactPixelFormat
argument_list|)
decl_stmt|;
name|Q_GUI_EXPORT
name|EGLSurface
name|createSurface
parameter_list|(
name|QPaintDevice
modifier|*
name|device
parameter_list|,
name|EGLConfig
name|cfg
parameter_list|,
specifier|const
name|QEglProperties
modifier|*
name|surfaceAttribs
init|=
literal|0
parameter_list|)
function_decl|;
name|Q_GUI_EXPORT
name|void
name|dumpAllConfigs
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|QT_NO_EGL
name|Q_GUI_EXPORT
name|QString
name|errorString
parameter_list|(
name|EGLint
name|code
init|=
literal|0
parameter_list|)
function_decl|;
else|#
directive|else
name|Q_GUI_EXPORT
name|QString
name|errorString
parameter_list|(
name|EGLint
name|code
init|=
name|eglGetError
argument_list|()
parameter_list|)
function_decl|;
endif|#
directive|endif
name|Q_GUI_EXPORT
name|QString
name|extensions
parameter_list|()
function_decl|;
name|Q_GUI_EXPORT
name|bool
name|hasExtension
parameter_list|(
specifier|const
name|char
modifier|*
name|extensionName
parameter_list|)
function_decl|;
name|Q_GUI_EXPORT
name|EGLDisplay
name|display
parameter_list|()
function_decl|;
name|Q_GUI_EXPORT
name|EGLNativeDisplayType
name|nativeDisplay
parameter_list|()
function_decl|;
name|Q_GUI_EXPORT
name|EGLNativeWindowType
name|nativeWindow
parameter_list|(
name|QWidget
modifier|*
parameter_list|)
function_decl|;
name|Q_GUI_EXPORT
name|EGLNativePixmapType
name|nativePixmap
parameter_list|(
name|QPixmap
modifier|*
parameter_list|)
function_decl|;
comment|// Extension functions
name|Q_GUI_EXPORT
name|EGLImageKHR
name|eglCreateImageKHR
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLContext
name|ctx
parameter_list|,
name|EGLenum
name|target
parameter_list|,
name|EGLClientBuffer
name|buffer
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
name|Q_GUI_EXPORT
name|EGLBoolean
name|eglDestroyImageKHR
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLImageKHR
name|img
parameter_list|)
function_decl|;
name|Q_GUI_EXPORT
name|EGLBoolean
name|eglSwapBuffersRegion2NOK
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSurface
name|surface
parameter_list|,
name|EGLint
name|count
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|rects
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QEgl::ConfigOptions
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QEGL_P_H
end_comment
end_unit
