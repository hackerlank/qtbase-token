begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PVRQWSDRAWABLE_P_H
end_ifndef
begin_define
DECL|macro|PVRQWSDRAWABLE_P_H
define|#
directive|define
name|PVRQWSDRAWABLE_P_H
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
comment|// reasons.  This header file may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
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
file|<pvr2d.h>
end_include
begin_include
include|#
directive|include
file|"pvrqwsdrawable.h"
end_include
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
DECL|macro|PVRQWS_MAX_VISIBLE_RECTS
define|#
directive|define
name|PVRQWS_MAX_VISIBLE_RECTS
value|32
DECL|macro|PVRQWS_MAX_SCREENS
define|#
directive|define
name|PVRQWS_MAX_SCREENS
value|1
DECL|macro|PVRQWS_MAX_BACK_BUFFERS
define|#
directive|define
name|PVRQWS_MAX_BACK_BUFFERS
value|2
DECL|macro|PVRQWS_MAX_FLIP_BUFFERS
define|#
directive|define
name|PVRQWS_MAX_FLIP_BUFFERS
value|2
typedef|typedef
struct|struct
block|{
DECL|member|screenRect
name|PvrQwsRect
name|screenRect
decl_stmt|;
DECL|member|screenStride
name|int
name|screenStride
decl_stmt|;
DECL|member|pixelFormat
name|PVR2DFORMAT
name|pixelFormat
decl_stmt|;
DECL|member|bytesPerPixel
name|int
name|bytesPerPixel
decl_stmt|;
DECL|member|frameBuffer
name|PVR2DMEMINFO
modifier|*
name|frameBuffer
decl_stmt|;
DECL|member|screenDrawable
name|PvrQwsDrawable
modifier|*
name|screenDrawable
decl_stmt|;
DECL|member|mapped
name|void
modifier|*
name|mapped
decl_stmt|;
DECL|member|mappedLength
name|int
name|mappedLength
decl_stmt|;
DECL|member|screenStart
name|unsigned
name|long
name|screenStart
decl_stmt|;
DECL|member|needsUnmap
name|int
name|needsUnmap
decl_stmt|;
DECL|member|initialized
name|int
name|initialized
decl_stmt|;
block|}
DECL|typedef|PvrQwsScreenInfo
name|PvrQwsScreenInfo
typedef|;
typedef|typedef
struct|struct
block|{
DECL|member|refCount
name|int
name|refCount
decl_stmt|;
DECL|member|screens
name|PvrQwsScreenInfo
name|screens
index|[
name|PVRQWS_MAX_SCREENS
index|]
decl_stmt|;
DECL|member|context
name|PVR2DCONTEXTHANDLE
name|context
decl_stmt|;
DECL|member|numDrawables
name|int
name|numDrawables
decl_stmt|;
DECL|member|numFlipBuffers
name|unsigned
name|long
name|numFlipBuffers
decl_stmt|;
DECL|member|flipChain
name|PVR2DFLIPCHAINHANDLE
name|flipChain
decl_stmt|;
DECL|member|flipBuffers
name|PVR2DMEMINFO
modifier|*
name|flipBuffers
index|[
name|PVRQWS_MAX_FLIP_BUFFERS
index|]
decl_stmt|;
DECL|member|usePresentBlit
name|int
name|usePresentBlit
decl_stmt|;
DECL|member|firstWinId
name|PvrQwsDrawable
modifier|*
name|firstWinId
decl_stmt|;
block|}
DECL|typedef|PvrQwsDisplay
name|PvrQwsDisplay
typedef|;
specifier|extern
name|PvrQwsDisplay
name|pvrQwsDisplay
decl_stmt|;
DECL|struct|_PvrQwsDrawable
struct|struct
name|_PvrQwsDrawable
block|{
DECL|member|type
name|PvrQwsDrawableType
name|type
decl_stmt|;
DECL|member|winId
name|long
name|winId
decl_stmt|;
DECL|member|refCount
name|int
name|refCount
decl_stmt|;
DECL|member|rect
name|PvrQwsRect
name|rect
decl_stmt|;
DECL|member|screen
name|int
name|screen
decl_stmt|;
DECL|member|pixelFormat
name|PVR2DFORMAT
name|pixelFormat
decl_stmt|;
DECL|member|visibleRects
name|PvrQwsRect
name|visibleRects
index|[
name|PVRQWS_MAX_VISIBLE_RECTS
index|]
decl_stmt|;
DECL|member|numVisibleRects
name|int
name|numVisibleRects
decl_stmt|;
DECL|member|backBuffers
name|PVR2DMEMINFO
modifier|*
name|backBuffers
index|[
name|PVRQWS_MAX_BACK_BUFFERS
index|]
decl_stmt|;
DECL|member|currentBackBuffer
name|int
name|currentBackBuffer
decl_stmt|;
DECL|member|backBuffersValid
name|int
name|backBuffersValid
decl_stmt|;
DECL|member|usingFlipBuffers
name|int
name|usingFlipBuffers
decl_stmt|;
DECL|member|isFullScreen
name|int
name|isFullScreen
decl_stmt|;
DECL|member|strideBytes
name|int
name|strideBytes
decl_stmt|;
DECL|member|stridePixels
name|int
name|stridePixels
decl_stmt|;
DECL|member|rotationAngle
name|int
name|rotationAngle
decl_stmt|;
DECL|member|swapFunction
name|PvrQwsSwapFunction
name|swapFunction
decl_stmt|;
DECL|member|userData
name|void
modifier|*
name|userData
decl_stmt|;
DECL|member|nextWinId
name|PvrQwsDrawable
modifier|*
name|nextWinId
decl_stmt|;
block|}
struct|;
comment|/* Get the current source and render buffers for a drawable */
name|int
name|pvrQwsGetBuffers
parameter_list|(
name|PvrQwsDrawable
modifier|*
name|drawable
parameter_list|,
name|PVR2DMEMINFO
modifier|*
modifier|*
name|source
parameter_list|,
name|PVR2DMEMINFO
modifier|*
modifier|*
name|render
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
end_unit
