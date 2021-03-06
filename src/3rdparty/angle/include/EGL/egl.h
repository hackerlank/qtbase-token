begin_unit
begin_ifndef
ifndef|#
directive|ifndef
name|__egl_h_
end_ifndef
begin_define
DECL|macro|__egl_h_
define|#
directive|define
name|__egl_h_
value|1
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* ** Copyright (c) 2013-2015 The Khronos Group Inc. ** ** Permission is hereby granted, free of charge, to any person obtaining a ** copy of this software and/or associated documentation files (the ** "Materials"), to deal in the Materials without restriction, including ** without limitation the rights to use, copy, modify, merge, publish, ** distribute, sublicense, and/or sell copies of the Materials, and to ** permit persons to whom the Materials are furnished to do so, subject to ** the following conditions: ** ** The above copyright notice and this permission notice shall be included ** in all copies or substantial portions of the Materials. ** ** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, ** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF ** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. ** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY ** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, ** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE ** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS. */
comment|/* ** This header is generated from the Khronos OpenGL / OpenGL ES XML ** API Registry. The current version of the Registry, generator scripts ** used to make the header, and the header can be found at **   http://www.opengl.org/registry/ ** ** Khronos $Revision: 31566 $ on $Date: 2015-06-23 08:48:48 -0700 (Tue, 23 Jun 2015) $ */
include|#
directive|include
file|<EGL/eglplatform.h>
comment|/* Generated on date 20150623 */
comment|/* Generated C header for:  * API: egl  * Versions considered: .*  * Versions emitted: .*  * Default extensions included: None  * Additional extensions included: _nomatch_^  * Extensions removed: _nomatch_^  */
ifndef|#
directive|ifndef
name|EGL_VERSION_1_0
DECL|macro|EGL_VERSION_1_0
define|#
directive|define
name|EGL_VERSION_1_0
value|1
DECL|typedef|EGLBoolean
typedef|typedef
name|unsigned
name|int
name|EGLBoolean
typedef|;
DECL|typedef|EGLDisplay
typedef|typedef
name|void
modifier|*
name|EGLDisplay
typedef|;
include|#
directive|include
file|<KHR/khrplatform.h>
include|#
directive|include
file|<EGL/eglplatform.h>
DECL|typedef|EGLConfig
typedef|typedef
name|void
modifier|*
name|EGLConfig
typedef|;
DECL|typedef|EGLSurface
typedef|typedef
name|void
modifier|*
name|EGLSurface
typedef|;
DECL|typedef|EGLContext
typedef|typedef
name|void
modifier|*
name|EGLContext
typedef|;
DECL|typedef|__eglMustCastToProperFunctionPointerType
typedef|typedef
name|void
function_decl|(
modifier|*
name|__eglMustCastToProperFunctionPointerType
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
DECL|macro|EGL_ALPHA_SIZE
define|#
directive|define
name|EGL_ALPHA_SIZE
value|0x3021
DECL|macro|EGL_BAD_ACCESS
define|#
directive|define
name|EGL_BAD_ACCESS
value|0x3002
DECL|macro|EGL_BAD_ALLOC
define|#
directive|define
name|EGL_BAD_ALLOC
value|0x3003
DECL|macro|EGL_BAD_ATTRIBUTE
define|#
directive|define
name|EGL_BAD_ATTRIBUTE
value|0x3004
DECL|macro|EGL_BAD_CONFIG
define|#
directive|define
name|EGL_BAD_CONFIG
value|0x3005
DECL|macro|EGL_BAD_CONTEXT
define|#
directive|define
name|EGL_BAD_CONTEXT
value|0x3006
DECL|macro|EGL_BAD_CURRENT_SURFACE
define|#
directive|define
name|EGL_BAD_CURRENT_SURFACE
value|0x3007
DECL|macro|EGL_BAD_DISPLAY
define|#
directive|define
name|EGL_BAD_DISPLAY
value|0x3008
DECL|macro|EGL_BAD_MATCH
define|#
directive|define
name|EGL_BAD_MATCH
value|0x3009
DECL|macro|EGL_BAD_NATIVE_PIXMAP
define|#
directive|define
name|EGL_BAD_NATIVE_PIXMAP
value|0x300A
DECL|macro|EGL_BAD_NATIVE_WINDOW
define|#
directive|define
name|EGL_BAD_NATIVE_WINDOW
value|0x300B
DECL|macro|EGL_BAD_PARAMETER
define|#
directive|define
name|EGL_BAD_PARAMETER
value|0x300C
DECL|macro|EGL_BAD_SURFACE
define|#
directive|define
name|EGL_BAD_SURFACE
value|0x300D
DECL|macro|EGL_BLUE_SIZE
define|#
directive|define
name|EGL_BLUE_SIZE
value|0x3022
DECL|macro|EGL_BUFFER_SIZE
define|#
directive|define
name|EGL_BUFFER_SIZE
value|0x3020
DECL|macro|EGL_CONFIG_CAVEAT
define|#
directive|define
name|EGL_CONFIG_CAVEAT
value|0x3027
DECL|macro|EGL_CONFIG_ID
define|#
directive|define
name|EGL_CONFIG_ID
value|0x3028
DECL|macro|EGL_CORE_NATIVE_ENGINE
define|#
directive|define
name|EGL_CORE_NATIVE_ENGINE
value|0x305B
DECL|macro|EGL_DEPTH_SIZE
define|#
directive|define
name|EGL_DEPTH_SIZE
value|0x3025
DECL|macro|EGL_DONT_CARE
define|#
directive|define
name|EGL_DONT_CARE
value|((EGLint)-1)
DECL|macro|EGL_DRAW
define|#
directive|define
name|EGL_DRAW
value|0x3059
DECL|macro|EGL_EXTENSIONS
define|#
directive|define
name|EGL_EXTENSIONS
value|0x3055
DECL|macro|EGL_FALSE
define|#
directive|define
name|EGL_FALSE
value|0
DECL|macro|EGL_GREEN_SIZE
define|#
directive|define
name|EGL_GREEN_SIZE
value|0x3023
DECL|macro|EGL_HEIGHT
define|#
directive|define
name|EGL_HEIGHT
value|0x3056
DECL|macro|EGL_LARGEST_PBUFFER
define|#
directive|define
name|EGL_LARGEST_PBUFFER
value|0x3058
DECL|macro|EGL_LEVEL
define|#
directive|define
name|EGL_LEVEL
value|0x3029
DECL|macro|EGL_MAX_PBUFFER_HEIGHT
define|#
directive|define
name|EGL_MAX_PBUFFER_HEIGHT
value|0x302A
DECL|macro|EGL_MAX_PBUFFER_PIXELS
define|#
directive|define
name|EGL_MAX_PBUFFER_PIXELS
value|0x302B
DECL|macro|EGL_MAX_PBUFFER_WIDTH
define|#
directive|define
name|EGL_MAX_PBUFFER_WIDTH
value|0x302C
DECL|macro|EGL_NATIVE_RENDERABLE
define|#
directive|define
name|EGL_NATIVE_RENDERABLE
value|0x302D
DECL|macro|EGL_NATIVE_VISUAL_ID
define|#
directive|define
name|EGL_NATIVE_VISUAL_ID
value|0x302E
DECL|macro|EGL_NATIVE_VISUAL_TYPE
define|#
directive|define
name|EGL_NATIVE_VISUAL_TYPE
value|0x302F
DECL|macro|EGL_NONE
define|#
directive|define
name|EGL_NONE
value|0x3038
DECL|macro|EGL_NON_CONFORMANT_CONFIG
define|#
directive|define
name|EGL_NON_CONFORMANT_CONFIG
value|0x3051
DECL|macro|EGL_NOT_INITIALIZED
define|#
directive|define
name|EGL_NOT_INITIALIZED
value|0x3001
DECL|macro|EGL_NO_CONTEXT
define|#
directive|define
name|EGL_NO_CONTEXT
value|((EGLContext)0)
DECL|macro|EGL_NO_DISPLAY
define|#
directive|define
name|EGL_NO_DISPLAY
value|((EGLDisplay)0)
DECL|macro|EGL_NO_SURFACE
define|#
directive|define
name|EGL_NO_SURFACE
value|((EGLSurface)0)
DECL|macro|EGL_PBUFFER_BIT
define|#
directive|define
name|EGL_PBUFFER_BIT
value|0x0001
DECL|macro|EGL_PIXMAP_BIT
define|#
directive|define
name|EGL_PIXMAP_BIT
value|0x0002
DECL|macro|EGL_READ
define|#
directive|define
name|EGL_READ
value|0x305A
DECL|macro|EGL_RED_SIZE
define|#
directive|define
name|EGL_RED_SIZE
value|0x3024
DECL|macro|EGL_SAMPLES
define|#
directive|define
name|EGL_SAMPLES
value|0x3031
DECL|macro|EGL_SAMPLE_BUFFERS
define|#
directive|define
name|EGL_SAMPLE_BUFFERS
value|0x3032
DECL|macro|EGL_SLOW_CONFIG
define|#
directive|define
name|EGL_SLOW_CONFIG
value|0x3050
DECL|macro|EGL_STENCIL_SIZE
define|#
directive|define
name|EGL_STENCIL_SIZE
value|0x3026
DECL|macro|EGL_SUCCESS
define|#
directive|define
name|EGL_SUCCESS
value|0x3000
DECL|macro|EGL_SURFACE_TYPE
define|#
directive|define
name|EGL_SURFACE_TYPE
value|0x3033
DECL|macro|EGL_TRANSPARENT_BLUE_VALUE
define|#
directive|define
name|EGL_TRANSPARENT_BLUE_VALUE
value|0x3035
DECL|macro|EGL_TRANSPARENT_GREEN_VALUE
define|#
directive|define
name|EGL_TRANSPARENT_GREEN_VALUE
value|0x3036
DECL|macro|EGL_TRANSPARENT_RED_VALUE
define|#
directive|define
name|EGL_TRANSPARENT_RED_VALUE
value|0x3037
DECL|macro|EGL_TRANSPARENT_RGB
define|#
directive|define
name|EGL_TRANSPARENT_RGB
value|0x3052
DECL|macro|EGL_TRANSPARENT_TYPE
define|#
directive|define
name|EGL_TRANSPARENT_TYPE
value|0x3034
DECL|macro|EGL_TRUE
define|#
directive|define
name|EGL_TRUE
value|1
DECL|macro|EGL_VENDOR
define|#
directive|define
name|EGL_VENDOR
value|0x3053
DECL|macro|EGL_VERSION
define|#
directive|define
name|EGL_VERSION
value|0x3054
DECL|macro|EGL_WIDTH
define|#
directive|define
name|EGL_WIDTH
value|0x3057
DECL|macro|EGL_WINDOW_BIT
define|#
directive|define
name|EGL_WINDOW_BIT
value|0x0004
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglChooseConfig
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|,
name|EGLConfig
modifier|*
name|configs
parameter_list|,
name|EGLint
name|config_size
parameter_list|,
name|EGLint
modifier|*
name|num_config
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglCopyBuffers
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSurface
name|surface
parameter_list|,
name|EGLNativePixmapType
name|target
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLContext
name|EGLAPIENTRY
name|eglCreateContext
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLConfig
name|config
parameter_list|,
name|EGLContext
name|share_context
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLSurface
name|EGLAPIENTRY
name|eglCreatePbufferSurface
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLConfig
name|config
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLSurface
name|EGLAPIENTRY
name|eglCreatePixmapSurface
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLConfig
name|config
parameter_list|,
name|EGLNativePixmapType
name|pixmap
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLSurface
name|EGLAPIENTRY
name|eglCreateWindowSurface
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLConfig
name|config
parameter_list|,
name|EGLNativeWindowType
name|win
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglDestroyContext
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLContext
name|ctx
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglDestroySurface
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSurface
name|surface
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglGetConfigAttrib
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLConfig
name|config
parameter_list|,
name|EGLint
name|attribute
parameter_list|,
name|EGLint
modifier|*
name|value
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglGetConfigs
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLConfig
modifier|*
name|configs
parameter_list|,
name|EGLint
name|config_size
parameter_list|,
name|EGLint
modifier|*
name|num_config
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLDisplay
name|EGLAPIENTRY
name|eglGetCurrentDisplay
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLSurface
name|EGLAPIENTRY
name|eglGetCurrentSurface
parameter_list|(
name|EGLint
name|readdraw
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLDisplay
name|EGLAPIENTRY
name|eglGetDisplay
parameter_list|(
name|EGLNativeDisplayType
name|display_id
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLint
name|EGLAPIENTRY
name|eglGetError
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|EGLAPI
name|__eglMustCastToProperFunctionPointerType
name|EGLAPIENTRY
name|eglGetProcAddress
parameter_list|(
specifier|const
name|char
modifier|*
name|procname
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglInitialize
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLint
modifier|*
name|major
parameter_list|,
name|EGLint
modifier|*
name|minor
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglMakeCurrent
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSurface
name|draw
parameter_list|,
name|EGLSurface
name|read
parameter_list|,
name|EGLContext
name|ctx
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglQueryContext
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLContext
name|ctx
parameter_list|,
name|EGLint
name|attribute
parameter_list|,
name|EGLint
modifier|*
name|value
parameter_list|)
function_decl|;
name|EGLAPI
specifier|const
name|char
modifier|*
name|EGLAPIENTRY
name|eglQueryString
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLint
name|name
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglQuerySurface
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSurface
name|surface
parameter_list|,
name|EGLint
name|attribute
parameter_list|,
name|EGLint
modifier|*
name|value
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglSwapBuffers
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSurface
name|surface
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglTerminate
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglWaitGL
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglWaitNative
parameter_list|(
name|EGLint
name|engine
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* EGL_VERSION_1_0 */
ifndef|#
directive|ifndef
name|EGL_VERSION_1_1
DECL|macro|EGL_VERSION_1_1
define|#
directive|define
name|EGL_VERSION_1_1
value|1
DECL|macro|EGL_BACK_BUFFER
define|#
directive|define
name|EGL_BACK_BUFFER
value|0x3084
DECL|macro|EGL_BIND_TO_TEXTURE_RGB
define|#
directive|define
name|EGL_BIND_TO_TEXTURE_RGB
value|0x3039
DECL|macro|EGL_BIND_TO_TEXTURE_RGBA
define|#
directive|define
name|EGL_BIND_TO_TEXTURE_RGBA
value|0x303A
DECL|macro|EGL_CONTEXT_LOST
define|#
directive|define
name|EGL_CONTEXT_LOST
value|0x300E
DECL|macro|EGL_MIN_SWAP_INTERVAL
define|#
directive|define
name|EGL_MIN_SWAP_INTERVAL
value|0x303B
DECL|macro|EGL_MAX_SWAP_INTERVAL
define|#
directive|define
name|EGL_MAX_SWAP_INTERVAL
value|0x303C
DECL|macro|EGL_MIPMAP_TEXTURE
define|#
directive|define
name|EGL_MIPMAP_TEXTURE
value|0x3082
DECL|macro|EGL_MIPMAP_LEVEL
define|#
directive|define
name|EGL_MIPMAP_LEVEL
value|0x3083
DECL|macro|EGL_NO_TEXTURE
define|#
directive|define
name|EGL_NO_TEXTURE
value|0x305C
DECL|macro|EGL_TEXTURE_2D
define|#
directive|define
name|EGL_TEXTURE_2D
value|0x305F
DECL|macro|EGL_TEXTURE_FORMAT
define|#
directive|define
name|EGL_TEXTURE_FORMAT
value|0x3080
DECL|macro|EGL_TEXTURE_RGB
define|#
directive|define
name|EGL_TEXTURE_RGB
value|0x305D
DECL|macro|EGL_TEXTURE_RGBA
define|#
directive|define
name|EGL_TEXTURE_RGBA
value|0x305E
DECL|macro|EGL_TEXTURE_TARGET
define|#
directive|define
name|EGL_TEXTURE_TARGET
value|0x3081
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglBindTexImage
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSurface
name|surface
parameter_list|,
name|EGLint
name|buffer
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglReleaseTexImage
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSurface
name|surface
parameter_list|,
name|EGLint
name|buffer
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglSurfaceAttrib
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSurface
name|surface
parameter_list|,
name|EGLint
name|attribute
parameter_list|,
name|EGLint
name|value
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglSwapInterval
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLint
name|interval
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* EGL_VERSION_1_1 */
ifndef|#
directive|ifndef
name|EGL_VERSION_1_2
DECL|macro|EGL_VERSION_1_2
define|#
directive|define
name|EGL_VERSION_1_2
value|1
DECL|typedef|EGLenum
typedef|typedef
name|unsigned
name|int
name|EGLenum
typedef|;
DECL|typedef|EGLClientBuffer
typedef|typedef
name|void
modifier|*
name|EGLClientBuffer
typedef|;
DECL|macro|EGL_ALPHA_FORMAT
define|#
directive|define
name|EGL_ALPHA_FORMAT
value|0x3088
DECL|macro|EGL_ALPHA_FORMAT_NONPRE
define|#
directive|define
name|EGL_ALPHA_FORMAT_NONPRE
value|0x308B
DECL|macro|EGL_ALPHA_FORMAT_PRE
define|#
directive|define
name|EGL_ALPHA_FORMAT_PRE
value|0x308C
DECL|macro|EGL_ALPHA_MASK_SIZE
define|#
directive|define
name|EGL_ALPHA_MASK_SIZE
value|0x303E
DECL|macro|EGL_BUFFER_PRESERVED
define|#
directive|define
name|EGL_BUFFER_PRESERVED
value|0x3094
DECL|macro|EGL_BUFFER_DESTROYED
define|#
directive|define
name|EGL_BUFFER_DESTROYED
value|0x3095
DECL|macro|EGL_CLIENT_APIS
define|#
directive|define
name|EGL_CLIENT_APIS
value|0x308D
DECL|macro|EGL_COLORSPACE
define|#
directive|define
name|EGL_COLORSPACE
value|0x3087
DECL|macro|EGL_COLORSPACE_sRGB
define|#
directive|define
name|EGL_COLORSPACE_sRGB
value|0x3089
DECL|macro|EGL_COLORSPACE_LINEAR
define|#
directive|define
name|EGL_COLORSPACE_LINEAR
value|0x308A
DECL|macro|EGL_COLOR_BUFFER_TYPE
define|#
directive|define
name|EGL_COLOR_BUFFER_TYPE
value|0x303F
DECL|macro|EGL_CONTEXT_CLIENT_TYPE
define|#
directive|define
name|EGL_CONTEXT_CLIENT_TYPE
value|0x3097
DECL|macro|EGL_DISPLAY_SCALING
define|#
directive|define
name|EGL_DISPLAY_SCALING
value|10000
DECL|macro|EGL_HORIZONTAL_RESOLUTION
define|#
directive|define
name|EGL_HORIZONTAL_RESOLUTION
value|0x3090
DECL|macro|EGL_LUMINANCE_BUFFER
define|#
directive|define
name|EGL_LUMINANCE_BUFFER
value|0x308F
DECL|macro|EGL_LUMINANCE_SIZE
define|#
directive|define
name|EGL_LUMINANCE_SIZE
value|0x303D
DECL|macro|EGL_OPENGL_ES_BIT
define|#
directive|define
name|EGL_OPENGL_ES_BIT
value|0x0001
DECL|macro|EGL_OPENVG_BIT
define|#
directive|define
name|EGL_OPENVG_BIT
value|0x0002
DECL|macro|EGL_OPENGL_ES_API
define|#
directive|define
name|EGL_OPENGL_ES_API
value|0x30A0
DECL|macro|EGL_OPENVG_API
define|#
directive|define
name|EGL_OPENVG_API
value|0x30A1
DECL|macro|EGL_OPENVG_IMAGE
define|#
directive|define
name|EGL_OPENVG_IMAGE
value|0x3096
DECL|macro|EGL_PIXEL_ASPECT_RATIO
define|#
directive|define
name|EGL_PIXEL_ASPECT_RATIO
value|0x3092
DECL|macro|EGL_RENDERABLE_TYPE
define|#
directive|define
name|EGL_RENDERABLE_TYPE
value|0x3040
DECL|macro|EGL_RENDER_BUFFER
define|#
directive|define
name|EGL_RENDER_BUFFER
value|0x3086
DECL|macro|EGL_RGB_BUFFER
define|#
directive|define
name|EGL_RGB_BUFFER
value|0x308E
DECL|macro|EGL_SINGLE_BUFFER
define|#
directive|define
name|EGL_SINGLE_BUFFER
value|0x3085
DECL|macro|EGL_SWAP_BEHAVIOR
define|#
directive|define
name|EGL_SWAP_BEHAVIOR
value|0x3093
DECL|macro|EGL_UNKNOWN
define|#
directive|define
name|EGL_UNKNOWN
value|((EGLint)-1)
DECL|macro|EGL_VERTICAL_RESOLUTION
define|#
directive|define
name|EGL_VERTICAL_RESOLUTION
value|0x3091
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglBindAPI
parameter_list|(
name|EGLenum
name|api
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLenum
name|EGLAPIENTRY
name|eglQueryAPI
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLSurface
name|EGLAPIENTRY
name|eglCreatePbufferFromClientBuffer
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLenum
name|buftype
parameter_list|,
name|EGLClientBuffer
name|buffer
parameter_list|,
name|EGLConfig
name|config
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglReleaseThread
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglWaitClient
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* EGL_VERSION_1_2 */
ifndef|#
directive|ifndef
name|EGL_VERSION_1_3
DECL|macro|EGL_VERSION_1_3
define|#
directive|define
name|EGL_VERSION_1_3
value|1
DECL|macro|EGL_CONFORMANT
define|#
directive|define
name|EGL_CONFORMANT
value|0x3042
DECL|macro|EGL_CONTEXT_CLIENT_VERSION
define|#
directive|define
name|EGL_CONTEXT_CLIENT_VERSION
value|0x3098
DECL|macro|EGL_MATCH_NATIVE_PIXMAP
define|#
directive|define
name|EGL_MATCH_NATIVE_PIXMAP
value|0x3041
DECL|macro|EGL_OPENGL_ES2_BIT
define|#
directive|define
name|EGL_OPENGL_ES2_BIT
value|0x0004
DECL|macro|EGL_VG_ALPHA_FORMAT
define|#
directive|define
name|EGL_VG_ALPHA_FORMAT
value|0x3088
DECL|macro|EGL_VG_ALPHA_FORMAT_NONPRE
define|#
directive|define
name|EGL_VG_ALPHA_FORMAT_NONPRE
value|0x308B
DECL|macro|EGL_VG_ALPHA_FORMAT_PRE
define|#
directive|define
name|EGL_VG_ALPHA_FORMAT_PRE
value|0x308C
DECL|macro|EGL_VG_ALPHA_FORMAT_PRE_BIT
define|#
directive|define
name|EGL_VG_ALPHA_FORMAT_PRE_BIT
value|0x0040
DECL|macro|EGL_VG_COLORSPACE
define|#
directive|define
name|EGL_VG_COLORSPACE
value|0x3087
DECL|macro|EGL_VG_COLORSPACE_sRGB
define|#
directive|define
name|EGL_VG_COLORSPACE_sRGB
value|0x3089
DECL|macro|EGL_VG_COLORSPACE_LINEAR
define|#
directive|define
name|EGL_VG_COLORSPACE_LINEAR
value|0x308A
DECL|macro|EGL_VG_COLORSPACE_LINEAR_BIT
define|#
directive|define
name|EGL_VG_COLORSPACE_LINEAR_BIT
value|0x0020
endif|#
directive|endif
comment|/* EGL_VERSION_1_3 */
ifndef|#
directive|ifndef
name|EGL_VERSION_1_4
DECL|macro|EGL_VERSION_1_4
define|#
directive|define
name|EGL_VERSION_1_4
value|1
DECL|macro|EGL_DEFAULT_DISPLAY
define|#
directive|define
name|EGL_DEFAULT_DISPLAY
value|((EGLNativeDisplayType)0)
DECL|macro|EGL_MULTISAMPLE_RESOLVE_BOX_BIT
define|#
directive|define
name|EGL_MULTISAMPLE_RESOLVE_BOX_BIT
value|0x0200
DECL|macro|EGL_MULTISAMPLE_RESOLVE
define|#
directive|define
name|EGL_MULTISAMPLE_RESOLVE
value|0x3099
DECL|macro|EGL_MULTISAMPLE_RESOLVE_DEFAULT
define|#
directive|define
name|EGL_MULTISAMPLE_RESOLVE_DEFAULT
value|0x309A
DECL|macro|EGL_MULTISAMPLE_RESOLVE_BOX
define|#
directive|define
name|EGL_MULTISAMPLE_RESOLVE_BOX
value|0x309B
DECL|macro|EGL_OPENGL_API
define|#
directive|define
name|EGL_OPENGL_API
value|0x30A2
DECL|macro|EGL_OPENGL_BIT
define|#
directive|define
name|EGL_OPENGL_BIT
value|0x0008
DECL|macro|EGL_SWAP_BEHAVIOR_PRESERVED_BIT
define|#
directive|define
name|EGL_SWAP_BEHAVIOR_PRESERVED_BIT
value|0x0400
name|EGLAPI
name|EGLContext
name|EGLAPIENTRY
name|eglGetCurrentContext
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* EGL_VERSION_1_4 */
ifndef|#
directive|ifndef
name|EGL_VERSION_1_5
DECL|macro|EGL_VERSION_1_5
define|#
directive|define
name|EGL_VERSION_1_5
value|1
DECL|typedef|EGLSync
typedef|typedef
name|void
modifier|*
name|EGLSync
typedef|;
DECL|typedef|EGLAttrib
typedef|typedef
name|intptr_t
name|EGLAttrib
typedef|;
DECL|typedef|EGLTime
typedef|typedef
name|khronos_utime_nanoseconds_t
name|EGLTime
typedef|;
DECL|typedef|EGLImage
typedef|typedef
name|void
modifier|*
name|EGLImage
typedef|;
DECL|macro|EGL_CONTEXT_MAJOR_VERSION
define|#
directive|define
name|EGL_CONTEXT_MAJOR_VERSION
value|0x3098
DECL|macro|EGL_CONTEXT_MINOR_VERSION
define|#
directive|define
name|EGL_CONTEXT_MINOR_VERSION
value|0x30FB
DECL|macro|EGL_CONTEXT_OPENGL_PROFILE_MASK
define|#
directive|define
name|EGL_CONTEXT_OPENGL_PROFILE_MASK
value|0x30FD
DECL|macro|EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY
define|#
directive|define
name|EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY
value|0x31BD
DECL|macro|EGL_NO_RESET_NOTIFICATION
define|#
directive|define
name|EGL_NO_RESET_NOTIFICATION
value|0x31BE
DECL|macro|EGL_LOSE_CONTEXT_ON_RESET
define|#
directive|define
name|EGL_LOSE_CONTEXT_ON_RESET
value|0x31BF
DECL|macro|EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT
define|#
directive|define
name|EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT
value|0x00000001
DECL|macro|EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT
define|#
directive|define
name|EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT
value|0x00000002
DECL|macro|EGL_CONTEXT_OPENGL_DEBUG
define|#
directive|define
name|EGL_CONTEXT_OPENGL_DEBUG
value|0x31B0
DECL|macro|EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE
define|#
directive|define
name|EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE
value|0x31B1
DECL|macro|EGL_CONTEXT_OPENGL_ROBUST_ACCESS
define|#
directive|define
name|EGL_CONTEXT_OPENGL_ROBUST_ACCESS
value|0x31B2
DECL|macro|EGL_OPENGL_ES3_BIT
define|#
directive|define
name|EGL_OPENGL_ES3_BIT
value|0x00000040
DECL|macro|EGL_CL_EVENT_HANDLE
define|#
directive|define
name|EGL_CL_EVENT_HANDLE
value|0x309C
DECL|macro|EGL_SYNC_CL_EVENT
define|#
directive|define
name|EGL_SYNC_CL_EVENT
value|0x30FE
DECL|macro|EGL_SYNC_CL_EVENT_COMPLETE
define|#
directive|define
name|EGL_SYNC_CL_EVENT_COMPLETE
value|0x30FF
DECL|macro|EGL_SYNC_PRIOR_COMMANDS_COMPLETE
define|#
directive|define
name|EGL_SYNC_PRIOR_COMMANDS_COMPLETE
value|0x30F0
DECL|macro|EGL_SYNC_TYPE
define|#
directive|define
name|EGL_SYNC_TYPE
value|0x30F7
DECL|macro|EGL_SYNC_STATUS
define|#
directive|define
name|EGL_SYNC_STATUS
value|0x30F1
DECL|macro|EGL_SYNC_CONDITION
define|#
directive|define
name|EGL_SYNC_CONDITION
value|0x30F8
DECL|macro|EGL_SIGNALED
define|#
directive|define
name|EGL_SIGNALED
value|0x30F2
DECL|macro|EGL_UNSIGNALED
define|#
directive|define
name|EGL_UNSIGNALED
value|0x30F3
DECL|macro|EGL_SYNC_FLUSH_COMMANDS_BIT
define|#
directive|define
name|EGL_SYNC_FLUSH_COMMANDS_BIT
value|0x0001
DECL|macro|EGL_FOREVER
define|#
directive|define
name|EGL_FOREVER
value|0xFFFFFFFFFFFFFFFFull
DECL|macro|EGL_TIMEOUT_EXPIRED
define|#
directive|define
name|EGL_TIMEOUT_EXPIRED
value|0x30F5
DECL|macro|EGL_CONDITION_SATISFIED
define|#
directive|define
name|EGL_CONDITION_SATISFIED
value|0x30F6
DECL|macro|EGL_NO_SYNC
define|#
directive|define
name|EGL_NO_SYNC
value|((EGLSync)0)
DECL|macro|EGL_SYNC_FENCE
define|#
directive|define
name|EGL_SYNC_FENCE
value|0x30F9
DECL|macro|EGL_GL_COLORSPACE
define|#
directive|define
name|EGL_GL_COLORSPACE
value|0x309D
DECL|macro|EGL_GL_COLORSPACE_SRGB
define|#
directive|define
name|EGL_GL_COLORSPACE_SRGB
value|0x3089
DECL|macro|EGL_GL_COLORSPACE_LINEAR
define|#
directive|define
name|EGL_GL_COLORSPACE_LINEAR
value|0x308A
DECL|macro|EGL_GL_RENDERBUFFER
define|#
directive|define
name|EGL_GL_RENDERBUFFER
value|0x30B9
DECL|macro|EGL_GL_TEXTURE_2D
define|#
directive|define
name|EGL_GL_TEXTURE_2D
value|0x30B1
DECL|macro|EGL_GL_TEXTURE_LEVEL
define|#
directive|define
name|EGL_GL_TEXTURE_LEVEL
value|0x30BC
DECL|macro|EGL_GL_TEXTURE_3D
define|#
directive|define
name|EGL_GL_TEXTURE_3D
value|0x30B2
DECL|macro|EGL_GL_TEXTURE_ZOFFSET
define|#
directive|define
name|EGL_GL_TEXTURE_ZOFFSET
value|0x30BD
DECL|macro|EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X
define|#
directive|define
name|EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X
value|0x30B3
DECL|macro|EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_X
define|#
directive|define
name|EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_X
value|0x30B4
DECL|macro|EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Y
define|#
directive|define
name|EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Y
value|0x30B5
DECL|macro|EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
define|#
directive|define
name|EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
value|0x30B6
DECL|macro|EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Z
define|#
directive|define
name|EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Z
value|0x30B7
DECL|macro|EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
define|#
directive|define
name|EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
value|0x30B8
DECL|macro|EGL_IMAGE_PRESERVED
define|#
directive|define
name|EGL_IMAGE_PRESERVED
value|0x30D2
DECL|macro|EGL_NO_IMAGE
define|#
directive|define
name|EGL_NO_IMAGE
value|((EGLImage)0)
name|EGLAPI
name|EGLSync
name|EGLAPIENTRY
name|eglCreateSync
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLenum
name|type
parameter_list|,
specifier|const
name|EGLAttrib
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglDestroySync
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSync
name|sync
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLint
name|EGLAPIENTRY
name|eglClientWaitSync
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSync
name|sync
parameter_list|,
name|EGLint
name|flags
parameter_list|,
name|EGLTime
name|timeout
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglGetSyncAttrib
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSync
name|sync
parameter_list|,
name|EGLint
name|attribute
parameter_list|,
name|EGLAttrib
modifier|*
name|value
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLImage
name|EGLAPIENTRY
name|eglCreateImage
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
name|EGLAttrib
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglDestroyImage
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLImage
name|image
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLDisplay
name|EGLAPIENTRY
name|eglGetPlatformDisplay
parameter_list|(
name|EGLenum
name|platform
parameter_list|,
name|void
modifier|*
name|native_display
parameter_list|,
specifier|const
name|EGLAttrib
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLSurface
name|EGLAPIENTRY
name|eglCreatePlatformWindowSurface
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLConfig
name|config
parameter_list|,
name|void
modifier|*
name|native_window
parameter_list|,
specifier|const
name|EGLAttrib
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLSurface
name|EGLAPIENTRY
name|eglCreatePlatformPixmapSurface
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLConfig
name|config
parameter_list|,
name|void
modifier|*
name|native_pixmap
parameter_list|,
specifier|const
name|EGLAttrib
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglWaitSync
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSync
name|sync
parameter_list|,
name|EGLint
name|flags
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* EGL_VERSION_1_5 */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
end_unit
