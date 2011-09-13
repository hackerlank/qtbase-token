begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdirectfbwindowsurface.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbintegration.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbblitter.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbconvenience.h"
end_include
begin_include
include|#
directive|include
file|<private/qpixmap_blitter_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QDirectFbWindowSurface
name|QDirectFbWindowSurface
operator|::
name|QDirectFbWindowSurface
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformBackingStore
argument_list|(
name|window
argument_list|)
member_init_list|,
name|m_pixmap
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_pmdata
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_dfbSurface
argument_list|(
literal|0
argument_list|)
block|{
name|IDirectFBDisplayLayer
modifier|*
name|layer
init|=
name|QDirectFbConvenience
operator|::
name|dfbDisplayLayer
argument_list|()
decl_stmt|;
name|DFBWindowID
name|id
argument_list|(
name|window
operator|->
name|winId
argument_list|()
argument_list|)
decl_stmt|;
name|IDirectFBWindow
modifier|*
name|dfbWindow
decl_stmt|;
name|layer
operator|->
name|GetWindow
argument_list|(
name|layer
argument_list|,
name|id
argument_list|,
operator|&
name|dfbWindow
argument_list|)
expr_stmt|;
name|dfbWindow
operator|->
name|GetSurface
argument_list|(
name|dfbWindow
argument_list|,
operator|&
name|m_dfbSurface
argument_list|)
expr_stmt|;
comment|//WRONGSIZE
name|QDirectFbBlitter
modifier|*
name|blitter
init|=
operator|new
name|QDirectFbBlitter
argument_list|(
name|window
operator|->
name|size
argument_list|()
argument_list|,
name|m_dfbSurface
argument_list|)
decl_stmt|;
name|m_pmdata
operator|=
operator|new
name|QDirectFbBlitterPlatformPixmap
expr_stmt|;
name|m_pmdata
operator|->
name|setBlittable
argument_list|(
name|blitter
argument_list|)
expr_stmt|;
name|m_pixmap
operator|=
operator|new
name|QPixmap
argument_list|(
name|m_pmdata
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QDirectFbWindowSurface
name|QDirectFbWindowSurface
operator|::
name|~
name|QDirectFbWindowSurface
parameter_list|()
block|{
operator|delete
name|m_pixmap
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QDirectFbWindowSurface
operator|::
name|paintDevice
parameter_list|()
block|{
return|return
name|m_pixmap
return|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QDirectFbWindowSurface
operator|::
name|flush
parameter_list|(
name|QWindow
modifier|*
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
block|{
name|m_pmdata
operator|->
name|blittable
argument_list|()
operator|->
name|unlock
argument_list|()
expr_stmt|;
name|QVector
argument_list|<
name|QRect
argument_list|>
name|rects
init|=
name|region
operator|.
name|rects
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|rects
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|QRect
name|rect
init|=
name|rects
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|DFBRegion
name|dfbReg
init|=
block|{
name|rect
operator|.
name|x
argument_list|()
operator|+
name|offset
operator|.
name|x
argument_list|()
block|,
name|rect
operator|.
name|y
argument_list|()
operator|+
name|offset
operator|.
name|y
argument_list|()
block|,
name|rect
operator|.
name|right
argument_list|()
operator|+
name|offset
operator|.
name|x
argument_list|()
block|,
name|rect
operator|.
name|bottom
argument_list|()
operator|+
name|offset
operator|.
name|y
argument_list|()
block|}
decl_stmt|;
name|m_dfbSurface
operator|->
name|Flip
argument_list|(
name|m_dfbSurface
argument_list|,
operator|&
name|dfbReg
argument_list|,
name|DFBSurfaceFlipFlags
argument_list|(
name|DSFLIP_BLIT
operator||
name|DSFLIP_ONSYNC
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QDirectFbWindowSurface
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|reg
parameter_list|)
block|{
name|QPlatformBackingStore
operator|::
name|resize
argument_list|(
name|size
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|//Have to add 1 ref ass it will be removed by deleting the old blitter in setBlittable
name|m_dfbSurface
operator|->
name|AddRef
argument_list|(
name|m_dfbSurface
argument_list|)
expr_stmt|;
name|QDirectFbBlitter
modifier|*
name|blitter
init|=
operator|new
name|QDirectFbBlitter
argument_list|(
name|size
argument_list|,
name|m_dfbSurface
argument_list|)
decl_stmt|;
name|m_pmdata
operator|->
name|setBlittable
argument_list|(
name|blitter
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|scrollSurface
specifier|static
specifier|inline
name|void
name|scrollSurface
parameter_list|(
name|IDirectFBSurface
modifier|*
name|surface
parameter_list|,
specifier|const
name|QRect
modifier|&
name|r
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
block|{
specifier|const
name|DFBRectangle
name|rect
init|=
block|{
name|r
operator|.
name|x
argument_list|()
block|,
name|r
operator|.
name|y
argument_list|()
block|,
name|r
operator|.
name|width
argument_list|()
block|,
name|r
operator|.
name|height
argument_list|()
block|}
decl_stmt|;
name|surface
operator|->
name|Blit
argument_list|(
name|surface
argument_list|,
name|surface
argument_list|,
operator|&
name|rect
argument_list|,
name|r
operator|.
name|x
argument_list|()
operator|+
name|dx
argument_list|,
name|r
operator|.
name|y
argument_list|()
operator|+
name|dy
argument_list|)
expr_stmt|;
specifier|const
name|DFBRegion
name|region
init|=
block|{
name|rect
operator|.
name|x
operator|+
name|dx
block|,
name|rect
operator|.
name|y
operator|+
name|dy
block|,
name|r
operator|.
name|right
argument_list|()
operator|+
name|dx
block|,
name|r
operator|.
name|bottom
argument_list|()
operator|+
name|dy
block|}
decl_stmt|;
name|surface
operator|->
name|Flip
argument_list|(
name|surface
argument_list|,
operator|&
name|region
argument_list|,
name|DFBSurfaceFlipFlags
argument_list|(
name|DSFLIP_BLIT
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|scroll
name|bool
name|QDirectFbWindowSurface
operator|::
name|scroll
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|area
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
block|{
name|m_pmdata
operator|->
name|blittable
argument_list|()
operator|->
name|unlock
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|m_dfbSurface
operator|||
name|area
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|false
return|;
name|m_dfbSurface
operator|->
name|SetBlittingFlags
argument_list|(
name|m_dfbSurface
argument_list|,
name|DSBLIT_NOFX
argument_list|)
expr_stmt|;
if|if
condition|(
name|area
operator|.
name|rectCount
argument_list|()
operator|==
literal|1
condition|)
block|{
name|scrollSurface
argument_list|(
name|m_dfbSurface
argument_list|,
name|area
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|dx
argument_list|,
name|dy
argument_list|)
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|QVector
argument_list|<
name|QRect
argument_list|>
name|rects
init|=
name|area
operator|.
name|rects
argument_list|()
decl_stmt|;
specifier|const
name|int
name|n
init|=
name|rects
operator|.
name|size
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
block|{
name|scrollSurface
argument_list|(
name|m_dfbSurface
argument_list|,
name|rects
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|dx
argument_list|,
name|dy
argument_list|)
expr_stmt|;
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QDirectFbWindowSurface
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|region
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endPaint
name|void
name|QDirectFbWindowSurface
operator|::
name|endPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|region
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
