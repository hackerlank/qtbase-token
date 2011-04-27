begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_HAVE_IWMMXT
end_ifdef
begin_include
include|#
directive|include
file|<mmintrin.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qplatformdefs.h"
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
name|__IWMMXT__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_include
include|#
directive|include
file|<xmmintrin.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WINCE_STD
argument_list|)
operator|&&
name|defined
argument_list|(
name|_X86_
argument_list|)
end_elif
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4391
name|)
end_pragma
begin_include
include|#
directive|include
file|<xmmintrin.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<private/qdrawhelper_sse_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|_MM_SHUFFLE
end_ifndef
begin_define
DECL|macro|_MM_SHUFFLE
define|#
directive|define
name|_MM_SHUFFLE
parameter_list|(
name|fp3
parameter_list|,
name|fp2
parameter_list|,
name|fp1
parameter_list|,
name|fp0
parameter_list|)
define|\
value|(((fp3)<< 6) | ((fp2)<< 4) | ((fp1)<< 2) | (fp0))
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_struct
DECL|struct|QIWMMXTIntrinsics
struct|struct
name|QIWMMXTIntrinsics
super|:
specifier|public
name|QMMXCommonIntrinsics
block|{
DECL|function|alpha
specifier|static
specifier|inline
name|m64
name|alpha
parameter_list|(
name|m64
name|x
parameter_list|)
block|{
return|return
name|_mm_shuffle_pi16
argument_list|(
name|x
argument_list|,
name|_MM_SHUFFLE
argument_list|(
literal|3
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|)
argument_list|)
return|;
block|}
DECL|function|_load_alpha
specifier|static
specifier|inline
name|m64
name|_load_alpha
parameter_list|(
name|uint
name|x
parameter_list|,
specifier|const
name|m64
modifier|&
name|mmx_0x0000
parameter_list|)
block|{
name|m64
name|t
init|=
name|_mm_unpacklo_pi8
argument_list|(
name|_mm_cvtsi32_si64
argument_list|(
name|x
argument_list|)
argument_list|,
name|mmx_0x0000
argument_list|)
decl_stmt|;
return|return
name|_mm_shuffle_pi16
argument_list|(
name|t
argument_list|,
name|_MM_SHUFFLE
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
return|;
block|}
DECL|function|end
specifier|static
specifier|inline
name|void
name|end
parameter_list|()
block|{     }
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|qt_functionForModeSolid_IWMMXT
name|CompositionFunctionSolid
name|qt_functionForModeSolid_IWMMXT
index|[
name|numCompositionFunctions
index|]
init|=
block|{
name|comp_func_solid_SourceOver
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_solid_DestinationOver
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_solid_Clear
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_solid_Source
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
literal|0
block|,
name|comp_func_solid_SourceIn
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_solid_DestinationIn
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_solid_SourceOut
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_solid_DestinationOut
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_solid_SourceAtop
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_solid_DestinationAtop
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_solid_XOR
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|// svg 1.2 modes
name|rasterop_solid_SourceOrDestination
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|rasterop_solid_SourceAndDestination
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|rasterop_solid_SourceXorDestination
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|rasterop_solid_NotSourceAndNotDestination
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|rasterop_solid_NotSourceOrNotDestination
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|rasterop_solid_NotSourceXorDestination
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|rasterop_solid_NotSource
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|rasterop_solid_NotSourceAndDestination
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|rasterop_solid_SourceAndNotDestination
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_functionForMode_IWMMXT
name|CompositionFunction
name|qt_functionForMode_IWMMXT
index|[]
init|=
block|{
name|comp_func_SourceOver
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_DestinationOver
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_Clear
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_Source
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_Destination
block|,
name|comp_func_SourceIn
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_DestinationIn
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_SourceOut
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_DestinationOut
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_SourceAtop
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_DestinationAtop
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_XOR
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
block|,
name|comp_func_Plus
block|,
name|comp_func_Multiply
block|,
name|comp_func_Screen
block|,
name|comp_func_Overlay
block|,
name|comp_func_Darken
block|,
name|comp_func_Lighten
block|,
name|comp_func_ColorDodge
block|,
name|comp_func_ColorBurn
block|,
name|comp_func_HardLight
block|,
name|comp_func_SoftLight
block|,
name|comp_func_Difference
block|,
name|comp_func_Exclusion
block|,
name|rasterop_SourceOrDestination
block|,
name|rasterop_SourceAndDestination
block|,
name|rasterop_SourceXorDestination
block|,
name|rasterop_NotSourceAndNotDestination
block|,
name|rasterop_NotSourceOrNotDestination
block|,
name|rasterop_NotSourceXorDestination
block|,
name|rasterop_NotSource
block|,
name|rasterop_NotSourceAndDestination
block|,
name|rasterop_SourceAndNotDestination
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qt_blend_color_argb_iwmmxt
name|void
name|qt_blend_color_argb_iwmmxt
parameter_list|(
name|int
name|count
parameter_list|,
specifier|const
name|QSpan
modifier|*
name|spans
parameter_list|,
name|void
modifier|*
name|userData
parameter_list|)
block|{
name|qt_blend_color_argb_x86
argument_list|<
name|QIWMMXTIntrinsics
argument_list|>
argument_list|(
name|count
argument_list|,
name|spans
argument_list|,
name|userData
argument_list|,
operator|(
name|CompositionFunctionSolid
operator|*
operator|)
name|qt_functionForModeSolid_IWMMXT
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_HAVE_IWMMXT
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
