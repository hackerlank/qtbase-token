begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcolormap.h"
end_include
begin_include
include|#
directive|include
file|"qcolor.h"
end_include
begin_include
include|#
directive|include
file|"qpaintdevice.h"
end_include
begin_include
include|#
directive|include
file|"qscreen_qws.h"
end_include
begin_include
include|#
directive|include
file|"qwsdisplay_qws.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QColormapPrivate
class|class
name|QColormapPrivate
block|{
public|public:
DECL|function|QColormapPrivate
specifier|inline
name|QColormapPrivate
parameter_list|()
member_init_list|:
name|ref
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|mode
argument_list|(
name|QColormap
operator|::
name|Direct
argument_list|)
member_init_list|,
name|depth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|numcolors
argument_list|(
literal|0
argument_list|)
block|{ }
DECL|member|ref
name|QAtomicInt
name|ref
decl_stmt|;
DECL|member|mode
name|QColormap
operator|::
name|Mode
name|mode
decl_stmt|;
DECL|member|depth
name|int
name|depth
decl_stmt|;
DECL|member|numcolors
name|int
name|numcolors
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|screenMap
specifier|static
name|QColormapPrivate
modifier|*
name|screenMap
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|initialize
name|void
name|QColormap
operator|::
name|initialize
parameter_list|()
block|{
name|screenMap
operator|=
operator|new
name|QColormapPrivate
expr_stmt|;
name|screenMap
operator|->
name|depth
operator|=
name|QPaintDevice
operator|::
name|qwsDisplay
argument_list|()
operator|->
name|depth
argument_list|()
expr_stmt|;
if|if
condition|(
name|screenMap
operator|->
name|depth
operator|<
literal|8
condition|)
block|{
name|screenMap
operator|->
name|mode
operator|=
name|QColormap
operator|::
name|Indexed
expr_stmt|;
name|screenMap
operator|->
name|numcolors
operator|=
literal|256
expr_stmt|;
block|}
else|else
block|{
name|screenMap
operator|->
name|mode
operator|=
name|QColormap
operator|::
name|Direct
expr_stmt|;
name|screenMap
operator|->
name|numcolors
operator|=
operator|-
literal|1
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|QColormap
operator|::
name|cleanup
parameter_list|()
block|{
operator|delete
name|screenMap
expr_stmt|;
name|screenMap
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|instance
name|QColormap
name|QColormap
operator|::
name|instance
parameter_list|(
name|int
comment|/*screen*/
parameter_list|)
block|{
return|return
name|QColormap
argument_list|()
return|;
block|}
end_function
begin_constructor
DECL|function|QColormap
name|QColormap
operator|::
name|QColormap
parameter_list|()
member_init_list|:
name|d
argument_list|(
name|screenMap
argument_list|)
block|{
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_constructor
DECL|function|QColormap
name|QColormap
operator|::
name|QColormap
parameter_list|(
specifier|const
name|QColormap
modifier|&
name|colormap
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|colormap
operator|.
name|d
argument_list|)
block|{
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_destructor
DECL|function|~QColormap
name|QColormap
operator|::
name|~
name|QColormap
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|mode
name|QColormap
operator|::
name|Mode
name|QColormap
operator|::
name|mode
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|mode
return|;
block|}
end_function
begin_function
DECL|function|depth
name|int
name|QColormap
operator|::
name|depth
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|depth
return|;
block|}
end_function
begin_function
DECL|function|size
name|int
name|QColormap
operator|::
name|size
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|numcolors
return|;
block|}
end_function
begin_function
DECL|function|pixel
name|uint
name|QColormap
operator|::
name|pixel
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
specifier|const
block|{
name|QRgb
name|rgb
init|=
name|color
operator|.
name|rgba
argument_list|()
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|mode
operator|==
name|QColormap
operator|::
name|Direct
condition|)
block|{
switch|switch
condition|(
name|d
operator|->
name|depth
condition|)
block|{
case|case
literal|16
case|:
return|return
name|qt_convRgbTo16
argument_list|(
name|rgb
argument_list|)
return|;
case|case
literal|24
case|:
case|case
literal|32
case|:
block|{
specifier|const
name|int
name|r
init|=
name|qRed
argument_list|(
name|rgb
argument_list|)
decl_stmt|;
specifier|const
name|int
name|g
init|=
name|qGreen
argument_list|(
name|rgb
argument_list|)
decl_stmt|;
specifier|const
name|int
name|b
init|=
name|qBlue
argument_list|(
name|rgb
argument_list|)
decl_stmt|;
specifier|const
name|int
name|red_shift
init|=
literal|16
decl_stmt|;
specifier|const
name|int
name|green_shift
init|=
literal|8
decl_stmt|;
specifier|const
name|int
name|red_mask
init|=
literal|0xff0000
decl_stmt|;
specifier|const
name|int
name|green_mask
init|=
literal|0x00ff00
decl_stmt|;
specifier|const
name|int
name|blue_mask
init|=
literal|0x0000ff
decl_stmt|;
specifier|const
name|int
name|tg
init|=
name|g
operator|<<
name|green_shift
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_QWS_DEPTH_32_BGR
if|if
condition|(
name|qt_screen
operator|->
name|pixelType
argument_list|()
operator|==
name|QScreen
operator|::
name|BGRPixel
condition|)
block|{
specifier|const
name|int
name|tb
init|=
name|b
operator|<<
name|red_shift
decl_stmt|;
return|return
literal|0xff000000
operator||
operator|(
name|r
operator|&
name|blue_mask
operator|)
operator||
operator|(
name|tg
operator|&
name|green_mask
operator|)
operator||
operator|(
name|tb
operator|&
name|red_mask
operator|)
return|;
block|}
endif|#
directive|endif
specifier|const
name|int
name|tr
init|=
name|r
operator|<<
name|red_shift
decl_stmt|;
return|return
literal|0xff000000
operator||
operator|(
name|b
operator|&
name|blue_mask
operator|)
operator||
operator|(
name|tg
operator|&
name|green_mask
operator|)
operator||
operator|(
name|tr
operator|&
name|red_mask
operator|)
return|;
block|}
block|}
block|}
return|return
name|qt_screen
operator|->
name|alloc
argument_list|(
name|qRed
argument_list|(
name|rgb
argument_list|)
argument_list|,
name|qGreen
argument_list|(
name|rgb
argument_list|)
argument_list|,
name|qBlue
argument_list|(
name|rgb
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|colorAt
specifier|const
name|QColor
name|QColormap
operator|::
name|colorAt
parameter_list|(
name|uint
name|pixel
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|mode
operator|==
name|Direct
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|depth
operator|==
literal|16
condition|)
block|{
name|pixel
operator|=
name|qt_conv16ToRgb
argument_list|(
name|pixel
argument_list|)
expr_stmt|;
block|}
specifier|const
name|int
name|red_shift
init|=
literal|16
decl_stmt|;
specifier|const
name|int
name|green_shift
init|=
literal|8
decl_stmt|;
specifier|const
name|int
name|red_mask
init|=
literal|0xff0000
decl_stmt|;
specifier|const
name|int
name|green_mask
init|=
literal|0x00ff00
decl_stmt|;
specifier|const
name|int
name|blue_mask
init|=
literal|0x0000ff
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_QWS_DEPTH_32_BGR
if|if
condition|(
name|qt_screen
operator|->
name|pixelType
argument_list|()
operator|==
name|QScreen
operator|::
name|BGRPixel
condition|)
block|{
return|return
name|QColor
argument_list|(
operator|(
name|pixel
operator|&
name|blue_mask
operator|)
argument_list|,
operator|(
name|pixel
operator|&
name|green_mask
operator|)
operator|>>
name|green_shift
argument_list|,
operator|(
name|pixel
operator|&
name|red_mask
operator|)
operator|>>
name|red_shift
argument_list|)
return|;
block|}
endif|#
directive|endif
return|return
name|QColor
argument_list|(
operator|(
name|pixel
operator|&
name|red_mask
operator|)
operator|>>
name|red_shift
argument_list|,
operator|(
name|pixel
operator|&
name|green_mask
operator|)
operator|>>
name|green_shift
argument_list|,
operator|(
name|pixel
operator|&
name|blue_mask
operator|)
argument_list|)
return|;
block|}
name|Q_ASSERT_X
argument_list|(
name|int
argument_list|(
name|pixel
argument_list|)
operator|<
name|qt_screen
operator|->
name|colorCount
argument_list|()
argument_list|,
literal|"QColormap::colorAt"
argument_list|,
literal|"pixel out of bounds of palette"
argument_list|)
expr_stmt|;
return|return
name|QColor
argument_list|(
name|qt_screen
operator|->
name|clut
argument_list|()
index|[
name|pixel
index|]
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|colormap
specifier|const
name|QVector
argument_list|<
name|QColor
argument_list|>
name|QColormap
operator|::
name|colormap
parameter_list|()
specifier|const
block|{
return|return
name|QVector
argument_list|<
name|QColor
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|operator =
name|QColormap
modifier|&
name|QColormap
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QColormap
modifier|&
name|colormap
parameter_list|)
block|{
name|qAtomicAssign
argument_list|(
name|d
argument_list|,
name|colormap
operator|.
name|d
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
