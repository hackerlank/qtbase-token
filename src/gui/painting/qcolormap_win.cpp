begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcolor.h"
end_include
begin_include
include|#
directive|include
file|"qcolormap.h"
end_include
begin_include
include|#
directive|include
file|"qvector.h"
end_include
begin_include
include|#
directive|include
file|"qt_windows.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WINCE
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qguifunctions_wince.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
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
name|hpal
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
DECL|member|hpal
name|HPALETTE
name|hpal
decl_stmt|;
DECL|member|palette
name|QVector
argument_list|<
name|QColor
argument_list|>
name|palette
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
name|HDC
name|dc
init|=
name|qt_win_display_dc
argument_list|()
decl_stmt|;
name|screenMap
operator|=
operator|new
name|QColormapPrivate
expr_stmt|;
name|screenMap
operator|->
name|depth
operator|=
name|GetDeviceCaps
argument_list|(
name|dc
argument_list|,
name|BITSPIXEL
argument_list|)
expr_stmt|;
name|screenMap
operator|->
name|numcolors
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|GetDeviceCaps
argument_list|(
name|dc
argument_list|,
name|RASTERCAPS
argument_list|)
operator|&
name|RC_PALETTE
condition|)
name|screenMap
operator|->
name|numcolors
operator|=
name|GetDeviceCaps
argument_list|(
name|dc
argument_list|,
name|SIZEPALETTE
argument_list|)
expr_stmt|;
if|if
condition|(
name|screenMap
operator|->
name|numcolors
operator|<=
literal|16
operator|||
name|screenMap
operator|->
name|numcolors
operator|>
literal|256
condition|)
comment|// no need to create palette
return|return;
name|LOGPALETTE
modifier|*
name|pal
init|=
literal|0
decl_stmt|;
name|int
name|numPalEntries
init|=
literal|6
operator|*
literal|6
operator|*
literal|6
decl_stmt|;
comment|// color cube
name|pal
operator|=
operator|(
name|LOGPALETTE
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|LOGPALETTE
argument_list|)
operator|+
name|numPalEntries
operator|*
sizeof|sizeof
argument_list|(
name|PALETTEENTRY
argument_list|)
argument_list|)
expr_stmt|;
comment|// Make 6x6x6 color cube
name|int
name|idx
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|ir
init|=
literal|0x0
init|;
name|ir
operator|<=
literal|0xff
condition|;
name|ir
operator|+=
literal|0x33
control|)
block|{
for|for
control|(
name|int
name|ig
init|=
literal|0x0
init|;
name|ig
operator|<=
literal|0xff
condition|;
name|ig
operator|+=
literal|0x33
control|)
block|{
for|for
control|(
name|int
name|ib
init|=
literal|0x0
init|;
name|ib
operator|<=
literal|0xff
condition|;
name|ib
operator|+=
literal|0x33
control|)
block|{
name|pal
operator|->
name|palPalEntry
index|[
name|idx
index|]
operator|.
name|peRed
operator|=
name|ir
expr_stmt|;
name|pal
operator|->
name|palPalEntry
index|[
name|idx
index|]
operator|.
name|peGreen
operator|=
name|ig
expr_stmt|;
name|pal
operator|->
name|palPalEntry
index|[
name|idx
index|]
operator|.
name|peBlue
operator|=
name|ib
expr_stmt|;
name|pal
operator|->
name|palPalEntry
index|[
name|idx
index|]
operator|.
name|peFlags
operator|=
literal|0
expr_stmt|;
name|idx
operator|++
expr_stmt|;
block|}
block|}
block|}
name|pal
operator|->
name|palVersion
operator|=
literal|0x300
expr_stmt|;
name|pal
operator|->
name|palNumEntries
operator|=
name|numPalEntries
expr_stmt|;
name|screenMap
operator|->
name|hpal
operator|=
name|CreatePalette
argument_list|(
name|pal
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|screenMap
operator|->
name|hpal
condition|)
name|qErrnoWarning
argument_list|(
literal|"QColor::initialize: Failed to create logical palette"
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|pal
argument_list|)
expr_stmt|;
name|SelectPalette
argument_list|(
name|dc
argument_list|,
name|screenMap
operator|->
name|hpal
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|RealizePalette
argument_list|(
name|dc
argument_list|)
expr_stmt|;
name|PALETTEENTRY
name|paletteEntries
index|[
literal|256
index|]
decl_stmt|;
name|screenMap
operator|->
name|numcolors
operator|=
name|GetPaletteEntries
argument_list|(
name|screenMap
operator|->
name|hpal
argument_list|,
literal|0
argument_list|,
literal|255
argument_list|,
name|paletteEntries
argument_list|)
expr_stmt|;
name|screenMap
operator|->
name|palette
operator|.
name|resize
argument_list|(
name|screenMap
operator|->
name|numcolors
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|screenMap
operator|->
name|numcolors
condition|;
name|i
operator|++
control|)
block|{
name|screenMap
operator|->
name|palette
index|[
name|i
index|]
operator|=
name|qRgb
argument_list|(
name|paletteEntries
index|[
name|i
index|]
operator|.
name|peRed
argument_list|,
name|paletteEntries
index|[
name|i
index|]
operator|.
name|peGreen
argument_list|,
name|paletteEntries
index|[
name|i
index|]
operator|.
name|peBlue
argument_list|)
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
if|if
condition|(
operator|!
name|screenMap
condition|)
return|return;
if|if
condition|(
name|screenMap
operator|->
name|hpal
condition|)
block|{
comment|// delete application global
name|DeleteObject
argument_list|(
name|screenMap
operator|->
name|hpal
argument_list|)
expr_stmt|;
comment|// palette
name|screenMap
operator|->
name|hpal
operator|=
literal|0
expr_stmt|;
block|}
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
parameter_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|screenMap
argument_list|,
literal|"QColormap"
argument_list|,
literal|"A QApplication object needs to be constructed before QColormap is used."
argument_list|)
expr_stmt|;
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
specifier|const
name|QColor
name|c
init|=
name|color
operator|.
name|toRgb
argument_list|()
decl_stmt|;
name|COLORREF
name|rgb
init|=
name|RGB
argument_list|(
name|c
operator|.
name|red
argument_list|()
argument_list|,
name|c
operator|.
name|green
argument_list|()
argument_list|,
name|c
operator|.
name|blue
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|hpal
condition|)
return|return
name|PALETTEINDEX
argument_list|(
name|GetNearestPaletteIndex
argument_list|(
name|d
operator|->
name|hpal
argument_list|,
name|rgb
argument_list|)
argument_list|)
return|;
return|return
name|rgb
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
name|hpal
condition|)
block|{
if|if
condition|(
name|pixel
operator|<
name|uint
argument_list|(
name|d
operator|->
name|numcolors
argument_list|)
condition|)
return|return
name|d
operator|->
name|palette
operator|.
name|at
argument_list|(
name|pixel
argument_list|)
return|;
return|return
name|QColor
argument_list|()
return|;
block|}
return|return
name|QColor
argument_list|(
name|GetRValue
argument_list|(
name|pixel
argument_list|)
argument_list|,
name|GetGValue
argument_list|(
name|pixel
argument_list|)
argument_list|,
name|GetBValue
argument_list|(
name|pixel
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|hPal
name|HPALETTE
name|QColormap
operator|::
name|hPal
parameter_list|()
block|{
return|return
name|screenMap
condition|?
name|screenMap
operator|->
name|hpal
else|:
literal|0
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
name|d
operator|->
name|palette
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
