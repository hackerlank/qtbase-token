begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QLoggingCategory>
end_include
begin_include
include|#
directive|include
file|"qxlibeglintegration_p.h"
end_include
begin_macro
name|Q_LOGGING_CATEGORY
argument_list|(
argument|lcXlibEglDebug
argument_list|,
literal|"qt.egl.xlib.debug"
argument_list|)
end_macro
begin_function
DECL|function|getCompatibleVisualId
name|VisualID
name|QXlibEglIntegration
operator|::
name|getCompatibleVisualId
parameter_list|(
name|Display
modifier|*
name|display
parameter_list|,
name|EGLDisplay
name|eglDisplay
parameter_list|,
name|EGLConfig
name|config
parameter_list|)
block|{
name|VisualID
name|visualId
init|=
literal|0
decl_stmt|;
name|EGLint
name|eglValue
init|=
literal|0
decl_stmt|;
name|EGLint
name|configRedSize
init|=
literal|0
decl_stmt|;
name|eglGetConfigAttrib
argument_list|(
name|eglDisplay
argument_list|,
name|config
argument_list|,
name|EGL_RED_SIZE
argument_list|,
operator|&
name|configRedSize
argument_list|)
expr_stmt|;
name|EGLint
name|configGreenSize
init|=
literal|0
decl_stmt|;
name|eglGetConfigAttrib
argument_list|(
name|eglDisplay
argument_list|,
name|config
argument_list|,
name|EGL_GREEN_SIZE
argument_list|,
operator|&
name|configGreenSize
argument_list|)
expr_stmt|;
name|EGLint
name|configBlueSize
init|=
literal|0
decl_stmt|;
name|eglGetConfigAttrib
argument_list|(
name|eglDisplay
argument_list|,
name|config
argument_list|,
name|EGL_BLUE_SIZE
argument_list|,
operator|&
name|configBlueSize
argument_list|)
expr_stmt|;
name|EGLint
name|configAlphaSize
init|=
literal|0
decl_stmt|;
name|eglGetConfigAttrib
argument_list|(
name|eglDisplay
argument_list|,
name|config
argument_list|,
name|EGL_ALPHA_SIZE
argument_list|,
operator|&
name|configAlphaSize
argument_list|)
expr_stmt|;
name|eglGetConfigAttrib
argument_list|(
name|eglDisplay
argument_list|,
name|config
argument_list|,
name|EGL_CONFIG_ID
argument_list|,
operator|&
name|eglValue
argument_list|)
expr_stmt|;
name|int
name|configId
init|=
name|eglValue
decl_stmt|;
comment|// See if EGL provided a valid VisualID:
name|eglGetConfigAttrib
argument_list|(
name|eglDisplay
argument_list|,
name|config
argument_list|,
name|EGL_NATIVE_VISUAL_ID
argument_list|,
operator|&
name|eglValue
argument_list|)
expr_stmt|;
name|visualId
operator|=
operator|(
name|VisualID
operator|)
name|eglValue
expr_stmt|;
if|if
condition|(
name|visualId
condition|)
block|{
comment|// EGL has suggested a visual id, so get the rest of the visual info for that id:
name|XVisualInfo
name|visualInfoTemplate
decl_stmt|;
name|memset
argument_list|(
operator|&
name|visualInfoTemplate
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|XVisualInfo
argument_list|)
argument_list|)
expr_stmt|;
name|visualInfoTemplate
operator|.
name|visualid
operator|=
name|visualId
expr_stmt|;
name|XVisualInfo
modifier|*
name|chosenVisualInfo
decl_stmt|;
name|int
name|matchingCount
init|=
literal|0
decl_stmt|;
name|chosenVisualInfo
operator|=
name|XGetVisualInfo
argument_list|(
name|display
argument_list|,
name|VisualIDMask
argument_list|,
operator|&
name|visualInfoTemplate
argument_list|,
operator|&
name|matchingCount
argument_list|)
expr_stmt|;
if|if
condition|(
name|chosenVisualInfo
condition|)
block|{
comment|// Skip size checks if implementation supports non-matching visual
comment|// and config (QTBUG-9444).
if|if
condition|(
name|q_hasEglExtension
argument_list|(
name|eglDisplay
argument_list|,
literal|"EGL_NV_post_convert_rounding"
argument_list|)
condition|)
block|{
name|XFree
argument_list|(
name|chosenVisualInfo
argument_list|)
expr_stmt|;
return|return
name|visualId
return|;
block|}
comment|// Skip also for i.MX6 where 565 visuals are suggested for the default 444 configs and it works just fine.
specifier|const
name|char
modifier|*
name|vendor
init|=
name|eglQueryString
argument_list|(
name|eglDisplay
argument_list|,
name|EGL_VENDOR
argument_list|)
decl_stmt|;
if|if
condition|(
name|vendor
operator|&&
name|strstr
argument_list|(
name|vendor
argument_list|,
literal|"Vivante"
argument_list|)
condition|)
block|{
name|XFree
argument_list|(
name|chosenVisualInfo
argument_list|)
expr_stmt|;
return|return
name|visualId
return|;
block|}
name|int
name|visualRedSize
init|=
name|qPopulationCount
argument_list|(
name|chosenVisualInfo
operator|->
name|red_mask
argument_list|)
decl_stmt|;
name|int
name|visualGreenSize
init|=
name|qPopulationCount
argument_list|(
name|chosenVisualInfo
operator|->
name|green_mask
argument_list|)
decl_stmt|;
name|int
name|visualBlueSize
init|=
name|qPopulationCount
argument_list|(
name|chosenVisualInfo
operator|->
name|blue_mask
argument_list|)
decl_stmt|;
name|int
name|visualAlphaSize
init|=
name|chosenVisualInfo
operator|->
name|depth
operator|==
literal|32
condition|?
literal|8
else|:
literal|0
decl_stmt|;
specifier|const
name|bool
name|visualMatchesConfig
init|=
name|visualRedSize
operator|==
name|configRedSize
operator|&&
name|visualGreenSize
operator|==
name|configGreenSize
operator|&&
name|visualBlueSize
operator|==
name|configBlueSize
operator|&&
name|visualAlphaSize
operator|==
name|configAlphaSize
decl_stmt|;
comment|// In some cases EGL tends to suggest a 24-bit visual for 8888
comment|// configs. In such a case we have to fall back to XGetVisualInfo.
if|if
condition|(
operator|!
name|visualMatchesConfig
condition|)
block|{
name|visualId
operator|=
literal|0
expr_stmt|;
name|qCDebug
argument_list|(
name|lcXlibEglDebug
argument_list|,
literal|"EGL suggested using X Visual ID %d (%d %d %d depth %d) for EGL config %d"
literal|"(%d %d %d %d), but this is incompatible"
argument_list|,
operator|(
name|int
operator|)
name|visualId
argument_list|,
name|visualRedSize
argument_list|,
name|visualGreenSize
argument_list|,
name|visualBlueSize
argument_list|,
name|chosenVisualInfo
operator|->
name|depth
argument_list|,
name|configId
argument_list|,
name|configRedSize
argument_list|,
name|configGreenSize
argument_list|,
name|configBlueSize
argument_list|,
name|configAlphaSize
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|qCDebug
argument_list|(
name|lcXlibEglDebug
argument_list|,
literal|"EGL suggested using X Visual ID %d for EGL config %d, but that isn't a valid ID"
argument_list|,
operator|(
name|int
operator|)
name|visualId
argument_list|,
name|configId
argument_list|)
expr_stmt|;
name|visualId
operator|=
literal|0
expr_stmt|;
block|}
name|XFree
argument_list|(
name|chosenVisualInfo
argument_list|)
expr_stmt|;
block|}
else|else
name|qCDebug
argument_list|(
name|lcXlibEglDebug
argument_list|,
literal|"EGL did not suggest a VisualID (EGL_NATIVE_VISUAL_ID was zero) for EGLConfig %d"
argument_list|,
name|configId
argument_list|)
expr_stmt|;
if|if
condition|(
name|visualId
condition|)
block|{
name|qCDebug
argument_list|(
name|lcXlibEglDebug
argument_list|,
name|configAlphaSize
operator|>
literal|0
condition|?
literal|"Using ARGB Visual ID %d provided by EGL for config %d"
else|:
literal|"Using Opaque Visual ID %d provided by EGL for config %d"
argument_list|,
operator|(
name|int
operator|)
name|visualId
argument_list|,
name|configId
argument_list|)
expr_stmt|;
return|return
name|visualId
return|;
block|}
comment|// Finally, try to use XGetVisualInfo and only use the bit depths to match on:
if|if
condition|(
operator|!
name|visualId
condition|)
block|{
name|XVisualInfo
name|visualInfoTemplate
decl_stmt|;
name|memset
argument_list|(
operator|&
name|visualInfoTemplate
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|XVisualInfo
argument_list|)
argument_list|)
expr_stmt|;
name|XVisualInfo
modifier|*
name|matchingVisuals
decl_stmt|;
name|int
name|matchingCount
init|=
literal|0
decl_stmt|;
name|visualInfoTemplate
operator|.
name|depth
operator|=
name|configRedSize
operator|+
name|configGreenSize
operator|+
name|configBlueSize
operator|+
name|configAlphaSize
expr_stmt|;
name|matchingVisuals
operator|=
name|XGetVisualInfo
argument_list|(
name|display
argument_list|,
name|VisualDepthMask
argument_list|,
operator|&
name|visualInfoTemplate
argument_list|,
operator|&
name|matchingCount
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|matchingVisuals
condition|)
block|{
comment|// Try again without taking the alpha channel into account:
name|visualInfoTemplate
operator|.
name|depth
operator|=
name|configRedSize
operator|+
name|configGreenSize
operator|+
name|configBlueSize
expr_stmt|;
name|matchingVisuals
operator|=
name|XGetVisualInfo
argument_list|(
name|display
argument_list|,
name|VisualDepthMask
argument_list|,
operator|&
name|visualInfoTemplate
argument_list|,
operator|&
name|matchingCount
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|matchingVisuals
condition|)
block|{
name|visualId
operator|=
name|matchingVisuals
index|[
literal|0
index|]
operator|.
name|visualid
expr_stmt|;
name|XFree
argument_list|(
name|matchingVisuals
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|visualId
condition|)
block|{
name|qCDebug
argument_list|(
name|lcXlibEglDebug
argument_list|,
literal|"Using Visual ID %d provided by XGetVisualInfo for EGL config %d"
argument_list|,
operator|(
name|int
operator|)
name|visualId
argument_list|,
name|configId
argument_list|)
expr_stmt|;
return|return
name|visualId
return|;
block|}
name|qWarning
argument_list|(
literal|"Unable to find an X11 visual which matches EGL config %d"
argument_list|,
name|configId
argument_list|)
expr_stmt|;
return|return
operator|(
name|VisualID
operator|)
literal|0
return|;
block|}
end_function
end_unit
