begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|"private/qpaintengine_alpha_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qpainter_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qpicture_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qfont_p.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpicture.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QAlphaPaintEngine
name|QAlphaPaintEngine
operator|::
name|QAlphaPaintEngine
parameter_list|(
name|QAlphaPaintEnginePrivate
modifier|&
name|data
parameter_list|,
name|PaintEngineFeatures
name|devcaps
parameter_list|)
member_init_list|:
name|QPaintEngine
argument_list|(
name|data
argument_list|,
name|devcaps
argument_list|)
block|{  }
end_constructor
begin_destructor
DECL|function|~QAlphaPaintEngine
name|QAlphaPaintEngine
operator|::
name|~
name|QAlphaPaintEngine
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|begin
name|bool
name|QAlphaPaintEngine
operator|::
name|begin
parameter_list|(
name|QPaintDevice
modifier|*
name|pdev
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAlphaPaintEngine
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_continueCall
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_pass
operator|!=
literal|0
condition|)
block|{
return|return
literal|true
return|;
block|}
name|d
operator|->
name|m_savedcaps
operator|=
name|gccaps
expr_stmt|;
name|d
operator|->
name|m_pdev
operator|=
name|pdev
expr_stmt|;
name|d
operator|->
name|m_alphaPen
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|m_alphaBrush
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|m_alphaOpacity
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|m_hasalpha
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|m_advancedPen
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|m_advancedBrush
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|m_complexTransform
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|m_emulateProjectiveTransforms
operator|=
literal|false
expr_stmt|;
comment|// clear alpha region
name|d
operator|->
name|m_alphargn
operator|=
name|QRegion
argument_list|()
expr_stmt|;
name|d
operator|->
name|m_cliprgn
operator|=
name|QRegion
argument_list|()
expr_stmt|;
name|d
operator|->
name|m_pen
operator|=
name|QPen
argument_list|()
expr_stmt|;
name|d
operator|->
name|m_transform
operator|=
name|QTransform
argument_list|()
expr_stmt|;
name|flushAndInit
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|end
name|bool
name|QAlphaPaintEngine
operator|::
name|end
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QAlphaPaintEngine
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_continueCall
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_pass
operator|!=
literal|0
condition|)
block|{
return|return
literal|true
return|;
block|}
name|flushAndInit
argument_list|(
literal|false
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|updateState
name|void
name|QAlphaPaintEngine
operator|::
name|updateState
parameter_list|(
specifier|const
name|QPaintEngineState
modifier|&
name|state
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAlphaPaintEngine
argument_list|)
expr_stmt|;
name|DirtyFlags
name|flags
init|=
name|state
operator|.
name|state
argument_list|()
decl_stmt|;
if|if
condition|(
name|flags
operator|&
name|QPaintEngine
operator|::
name|DirtyTransform
condition|)
block|{
name|d
operator|->
name|m_transform
operator|=
name|state
operator|.
name|transform
argument_list|()
expr_stmt|;
name|d
operator|->
name|m_complexTransform
operator|=
operator|(
name|d
operator|->
name|m_transform
operator|.
name|type
argument_list|()
operator|>
name|QTransform
operator|::
name|TxScale
operator|)
expr_stmt|;
name|d
operator|->
name|m_emulateProjectiveTransforms
operator|=
operator|!
operator|(
name|d
operator|->
name|m_savedcaps
operator|&
name|QPaintEngine
operator|::
name|PerspectiveTransform
operator|)
operator|&&
operator|!
operator|(
name|d
operator|->
name|m_savedcaps
operator|&
name|QPaintEngine
operator|::
name|AlphaBlend
operator|)
operator|&&
operator|(
name|d
operator|->
name|m_transform
operator|.
name|type
argument_list|()
operator|>=
name|QTransform
operator|::
name|TxProject
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|flags
operator|&
name|QPaintEngine
operator|::
name|DirtyPen
condition|)
block|{
name|d
operator|->
name|m_pen
operator|=
name|state
operator|.
name|pen
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_pen
operator|.
name|style
argument_list|()
operator|==
name|Qt
operator|::
name|NoPen
condition|)
block|{
name|d
operator|->
name|m_advancedPen
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|m_alphaPen
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|m_advancedPen
operator|=
operator|(
name|d
operator|->
name|m_pen
operator|.
name|brush
argument_list|()
operator|.
name|style
argument_list|()
operator|!=
name|Qt
operator|::
name|SolidPattern
operator|)
expr_stmt|;
name|d
operator|->
name|m_alphaPen
operator|=
operator|!
name|d
operator|->
name|m_pen
operator|.
name|brush
argument_list|()
operator|.
name|isOpaque
argument_list|()
expr_stmt|;
block|}
block|}
if|if
condition|(
name|d
operator|->
name|m_pass
operator|!=
literal|0
condition|)
block|{
name|d
operator|->
name|m_continueCall
operator|=
literal|true
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|m_continueCall
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|QPaintEngine
operator|::
name|DirtyOpacity
condition|)
block|{
name|d
operator|->
name|m_alphaOpacity
operator|=
operator|(
name|state
operator|.
name|opacity
argument_list|()
operator|!=
literal|1.0f
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|flags
operator|&
name|QPaintEngine
operator|::
name|DirtyBrush
condition|)
block|{
if|if
condition|(
name|state
operator|.
name|brush
argument_list|()
operator|.
name|style
argument_list|()
operator|==
name|Qt
operator|::
name|NoBrush
condition|)
block|{
name|d
operator|->
name|m_advancedBrush
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|m_alphaBrush
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|m_advancedBrush
operator|=
operator|(
name|state
operator|.
name|brush
argument_list|()
operator|.
name|style
argument_list|()
operator|!=
name|Qt
operator|::
name|SolidPattern
operator|)
expr_stmt|;
name|d
operator|->
name|m_alphaBrush
operator|=
operator|!
name|state
operator|.
name|brush
argument_list|()
operator|.
name|isOpaque
argument_list|()
expr_stmt|;
block|}
block|}
name|d
operator|->
name|m_hasalpha
operator|=
name|d
operator|->
name|m_alphaOpacity
operator|||
name|d
operator|->
name|m_alphaBrush
operator|||
name|d
operator|->
name|m_alphaPen
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_picengine
condition|)
name|d
operator|->
name|m_picengine
operator|->
name|updateState
argument_list|(
name|state
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|drawPath
name|void
name|QAlphaPaintEngine
operator|::
name|drawPath
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAlphaPaintEngine
argument_list|)
expr_stmt|;
name|QRectF
name|tr
init|=
name|d
operator|->
name|addPenWidth
argument_list|(
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|m_pass
operator|==
literal|0
condition|)
block|{
name|d
operator|->
name|m_continueCall
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_hasalpha
operator|||
name|d
operator|->
name|m_advancedPen
operator|||
name|d
operator|->
name|m_advancedBrush
operator|||
name|d
operator|->
name|m_emulateProjectiveTransforms
condition|)
block|{
name|d
operator|->
name|addAlphaRect
argument_list|(
name|tr
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|d
operator|->
name|m_picengine
condition|)
name|d
operator|->
name|m_picengine
operator|->
name|drawPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|m_continueCall
operator|=
operator|!
name|d
operator|->
name|fullyContained
argument_list|(
name|tr
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|drawPolygon
name|void
name|QAlphaPaintEngine
operator|::
name|drawPolygon
parameter_list|(
specifier|const
name|QPointF
modifier|*
name|points
parameter_list|,
name|int
name|pointCount
parameter_list|,
name|PolygonDrawMode
name|mode
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAlphaPaintEngine
argument_list|)
expr_stmt|;
name|QPolygonF
name|poly
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
name|pointCount
condition|;
operator|++
name|i
control|)
name|poly
operator|.
name|append
argument_list|(
name|points
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|addPolygon
argument_list|(
name|poly
argument_list|)
expr_stmt|;
name|QRectF
name|tr
init|=
name|d
operator|->
name|addPenWidth
argument_list|(
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|m_pass
operator|==
literal|0
condition|)
block|{
name|d
operator|->
name|m_continueCall
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_hasalpha
operator|||
name|d
operator|->
name|m_advancedPen
operator|||
name|d
operator|->
name|m_advancedBrush
operator|||
name|d
operator|->
name|m_emulateProjectiveTransforms
condition|)
block|{
name|d
operator|->
name|addAlphaRect
argument_list|(
name|tr
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|d
operator|->
name|m_picengine
condition|)
name|d
operator|->
name|m_picengine
operator|->
name|drawPolygon
argument_list|(
name|points
argument_list|,
name|pointCount
argument_list|,
name|mode
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|m_continueCall
operator|=
operator|!
name|d
operator|->
name|fullyContained
argument_list|(
name|tr
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|drawPixmap
name|void
name|QAlphaPaintEngine
operator|::
name|drawPixmap
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|r
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pm
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|sr
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAlphaPaintEngine
argument_list|)
expr_stmt|;
name|QRectF
name|tr
init|=
name|d
operator|->
name|m_transform
operator|.
name|mapRect
argument_list|(
name|r
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|m_pass
operator|==
literal|0
condition|)
block|{
name|d
operator|->
name|m_continueCall
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|pm
operator|.
name|hasAlpha
argument_list|()
operator|||
name|d
operator|->
name|m_alphaOpacity
operator|||
name|d
operator|->
name|m_complexTransform
operator|||
name|pm
operator|.
name|isQBitmap
argument_list|()
condition|)
block|{
name|d
operator|->
name|addAlphaRect
argument_list|(
name|tr
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|d
operator|->
name|m_picengine
condition|)
name|d
operator|->
name|m_picengine
operator|->
name|drawPixmap
argument_list|(
name|r
argument_list|,
name|pm
argument_list|,
name|sr
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|m_continueCall
operator|=
operator|!
name|d
operator|->
name|fullyContained
argument_list|(
name|tr
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|drawTextItem
name|void
name|QAlphaPaintEngine
operator|::
name|drawTextItem
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|,
specifier|const
name|QTextItem
modifier|&
name|textItem
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAlphaPaintEngine
argument_list|)
expr_stmt|;
name|QRectF
name|tr
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|,
name|p
operator|.
name|y
argument_list|()
operator|-
name|textItem
operator|.
name|ascent
argument_list|()
argument_list|,
name|textItem
operator|.
name|width
argument_list|()
operator|+
literal|5
argument_list|,
name|textItem
operator|.
name|ascent
argument_list|()
operator|+
name|textItem
operator|.
name|descent
argument_list|()
operator|+
literal|5
argument_list|)
decl_stmt|;
name|tr
operator|=
name|d
operator|->
name|m_transform
operator|.
name|mapRect
argument_list|(
name|tr
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_pass
operator|==
literal|0
condition|)
block|{
name|d
operator|->
name|m_continueCall
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_alphaPen
operator|||
name|d
operator|->
name|m_alphaOpacity
operator|||
name|d
operator|->
name|m_advancedPen
condition|)
block|{
name|d
operator|->
name|addAlphaRect
argument_list|(
name|tr
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|d
operator|->
name|m_picengine
condition|)
block|{
name|d
operator|->
name|m_picengine
operator|->
name|drawTextItem
argument_list|(
name|p
argument_list|,
name|textItem
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|d
operator|->
name|m_continueCall
operator|=
operator|!
name|d
operator|->
name|fullyContained
argument_list|(
name|tr
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|drawTiledPixmap
name|void
name|QAlphaPaintEngine
operator|::
name|drawTiledPixmap
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|r
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|s
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAlphaPaintEngine
argument_list|)
expr_stmt|;
name|QRectF
name|brect
init|=
name|d
operator|->
name|m_transform
operator|.
name|mapRect
argument_list|(
name|r
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|m_pass
operator|==
literal|0
condition|)
block|{
name|d
operator|->
name|m_continueCall
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|pixmap
operator|.
name|hasAlpha
argument_list|()
operator|||
name|d
operator|->
name|m_alphaOpacity
operator|||
name|d
operator|->
name|m_complexTransform
operator|||
name|pixmap
operator|.
name|isQBitmap
argument_list|()
condition|)
block|{
name|d
operator|->
name|addAlphaRect
argument_list|(
name|brect
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|d
operator|->
name|m_picengine
condition|)
name|d
operator|->
name|m_picengine
operator|->
name|drawTiledPixmap
argument_list|(
name|r
argument_list|,
name|pixmap
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|m_continueCall
operator|=
operator|!
name|d
operator|->
name|fullyContained
argument_list|(
name|brect
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|alphaClipping
name|QRegion
name|QAlphaPaintEngine
operator|::
name|alphaClipping
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAlphaPaintEngine
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|m_cliprgn
return|;
block|}
end_function
begin_function
DECL|function|continueCall
name|bool
name|QAlphaPaintEngine
operator|::
name|continueCall
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAlphaPaintEngine
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|m_continueCall
return|;
block|}
end_function
begin_function
DECL|function|flushAndInit
name|void
name|QAlphaPaintEngine
operator|::
name|flushAndInit
parameter_list|(
name|bool
name|init
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAlphaPaintEngine
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|m_pass
operator|==
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_pic
condition|)
block|{
name|d
operator|->
name|m_picpainter
operator|->
name|end
argument_list|()
expr_stmt|;
comment|// set clip region
name|d
operator|->
name|m_alphargn
operator|=
name|d
operator|->
name|m_alphargn
operator|.
name|intersected
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|d
operator|->
name|m_pdev
operator|->
name|width
argument_list|()
argument_list|,
name|d
operator|->
name|m_pdev
operator|->
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// just use the bounding rect if it's a complex region..
name|QVector
argument_list|<
name|QRect
argument_list|>
name|rects
init|=
name|d
operator|->
name|m_alphargn
operator|.
name|rects
argument_list|()
decl_stmt|;
if|if
condition|(
name|rects
operator|.
name|size
argument_list|()
operator|>
literal|10
condition|)
block|{
name|QRect
name|br
init|=
name|d
operator|->
name|m_alphargn
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|d
operator|->
name|m_alphargn
operator|=
name|QRegion
argument_list|(
name|br
argument_list|)
expr_stmt|;
name|rects
operator|.
name|clear
argument_list|()
expr_stmt|;
name|rects
operator|.
name|append
argument_list|(
name|br
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|m_cliprgn
operator|=
name|d
operator|->
name|m_alphargn
expr_stmt|;
comment|// now replay the QPicture
operator|++
name|d
operator|->
name|m_pass
expr_stmt|;
comment|// we are now doing pass #2
comment|// reset states
name|gccaps
operator|=
name|d
operator|->
name|m_savedcaps
expr_stmt|;
name|painter
argument_list|()
operator|->
name|save
argument_list|()
expr_stmt|;
name|d
operator|->
name|resetState
argument_list|(
name|painter
argument_list|()
argument_list|)
expr_stmt|;
comment|// make sure the output from QPicture is unscaled
name|QTransform
name|mtx
decl_stmt|;
name|mtx
operator|.
name|scale
argument_list|(
literal|1.0f
operator|/
operator|(
name|qreal
argument_list|(
name|d
operator|->
name|m_pdev
operator|->
name|logicalDpiX
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|qt_defaultDpiX
argument_list|()
argument_list|)
operator|)
argument_list|,
literal|1.0f
operator|/
operator|(
name|qreal
argument_list|(
name|d
operator|->
name|m_pdev
operator|->
name|logicalDpiY
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|qt_defaultDpiY
argument_list|()
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|painter
argument_list|()
operator|->
name|setTransform
argument_list|(
name|mtx
argument_list|)
expr_stmt|;
name|painter
argument_list|()
operator|->
name|drawPicture
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
operator|*
name|d
operator|->
name|m_pic
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_cliprgn
operator|=
name|QRegion
argument_list|()
expr_stmt|;
name|d
operator|->
name|resetState
argument_list|(
name|painter
argument_list|()
argument_list|)
expr_stmt|;
comment|// fill in the alpha images
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
operator|++
name|i
control|)
name|d
operator|->
name|drawAlphaImage
argument_list|(
name|rects
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_alphargn
operator|=
name|QRegion
argument_list|()
expr_stmt|;
name|painter
argument_list|()
operator|->
name|restore
argument_list|()
expr_stmt|;
operator|--
name|d
operator|->
name|m_pass
expr_stmt|;
comment|// pass #2 finished
name|cleanUp
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|init
condition|)
block|{
name|gccaps
operator|=
name|PaintEngineFeatures
argument_list|(
name|AllFeatures
operator|&
operator|~
name|QPaintEngine
operator|::
name|ObjectBoundingModeGradients
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_pic
operator|=
operator|new
name|QPicture
argument_list|()
expr_stmt|;
name|d
operator|->
name|m_pic
operator|->
name|d_ptr
operator|->
name|in_memory_only
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|m_picpainter
operator|=
operator|new
name|QPainter
argument_list|(
name|d
operator|->
name|m_pic
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_picengine
operator|=
name|d
operator|->
name|m_picpainter
operator|->
name|paintEngine
argument_list|()
expr_stmt|;
comment|// When newPage() is called and the m_picpainter is recreated
comment|// we have to copy the current state of the original printer
comment|// painter back to the m_picpainter
name|d
operator|->
name|m_picpainter
operator|->
name|setPen
argument_list|(
name|painter
argument_list|()
operator|->
name|pen
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_picpainter
operator|->
name|setBrush
argument_list|(
name|painter
argument_list|()
operator|->
name|brush
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_picpainter
operator|->
name|setBrushOrigin
argument_list|(
name|painter
argument_list|()
operator|->
name|brushOrigin
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_picpainter
operator|->
name|setFont
argument_list|(
name|painter
argument_list|()
operator|->
name|font
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_picpainter
operator|->
name|setOpacity
argument_list|(
name|painter
argument_list|()
operator|->
name|opacity
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_picpainter
operator|->
name|setTransform
argument_list|(
name|painter
argument_list|()
operator|->
name|combinedTransform
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_picengine
operator|->
name|syncState
argument_list|()
expr_stmt|;
name|QPainterState
modifier|&
name|state
init|=
operator|*
name|d
operator|->
name|m_picpainter
operator|->
name|d_func
argument_list|()
operator|->
name|state
decl_stmt|;
name|QPainter
modifier|*
name|oldPainter
init|=
name|state
operator|.
name|painter
decl_stmt|;
name|state
operator|=
operator|*
name|painter
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|state
expr_stmt|;
name|state
operator|.
name|painter
operator|=
name|oldPainter
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|cleanUp
name|void
name|QAlphaPaintEngine
operator|::
name|cleanUp
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QAlphaPaintEngine
argument_list|)
expr_stmt|;
operator|delete
name|d
operator|->
name|m_picpainter
expr_stmt|;
operator|delete
name|d
operator|->
name|m_pic
expr_stmt|;
name|d
operator|->
name|m_picpainter
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|m_pic
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|m_picengine
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QAlphaPaintEnginePrivate
name|QAlphaPaintEnginePrivate
operator|::
name|QAlphaPaintEnginePrivate
parameter_list|()
member_init_list|:
name|m_pass
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_pic
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_picengine
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_picpainter
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_hasalpha
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_alphaPen
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_alphaBrush
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_alphaOpacity
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_advancedPen
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_advancedBrush
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_complexTransform
argument_list|(
literal|false
argument_list|)
block|{  }
end_constructor
begin_destructor
DECL|function|~QAlphaPaintEnginePrivate
name|QAlphaPaintEnginePrivate
operator|::
name|~
name|QAlphaPaintEnginePrivate
parameter_list|()
block|{
operator|delete
name|m_picpainter
expr_stmt|;
operator|delete
name|m_pic
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|addPenWidth
name|QRectF
name|QAlphaPaintEnginePrivate
operator|::
name|addPenWidth
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QAlphaPaintEngine
argument_list|)
expr_stmt|;
name|QPainterPath
name|tmp
init|=
name|path
decl_stmt|;
if|if
condition|(
name|m_pen
operator|.
name|style
argument_list|()
operator|==
name|Qt
operator|::
name|NoPen
condition|)
return|return
operator|(
name|path
operator|.
name|controlPointRect
argument_list|()
operator|*
name|m_transform
operator|)
operator|.
name|boundingRect
argument_list|()
return|;
name|bool
name|cosmetic
init|=
name|qt_pen_is_cosmetic
argument_list|(
name|m_pen
argument_list|,
name|q
operator|->
name|state
operator|->
name|renderHints
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|cosmetic
condition|)
name|tmp
operator|=
name|path
operator|*
name|m_transform
expr_stmt|;
name|QPainterPathStroker
name|stroker
decl_stmt|;
if|if
condition|(
name|m_pen
operator|.
name|widthF
argument_list|()
operator|==
literal|0.0f
condition|)
name|stroker
operator|.
name|setWidth
argument_list|(
literal|1.0
argument_list|)
expr_stmt|;
else|else
name|stroker
operator|.
name|setWidth
argument_list|(
name|m_pen
operator|.
name|widthF
argument_list|()
argument_list|)
expr_stmt|;
name|stroker
operator|.
name|setJoinStyle
argument_list|(
name|m_pen
operator|.
name|joinStyle
argument_list|()
argument_list|)
expr_stmt|;
name|stroker
operator|.
name|setCapStyle
argument_list|(
name|m_pen
operator|.
name|capStyle
argument_list|()
argument_list|)
expr_stmt|;
name|tmp
operator|=
name|stroker
operator|.
name|createStroke
argument_list|(
name|tmp
argument_list|)
expr_stmt|;
if|if
condition|(
name|cosmetic
condition|)
return|return
name|tmp
operator|.
name|controlPointRect
argument_list|()
return|;
return|return
operator|(
name|tmp
operator|.
name|controlPointRect
argument_list|()
operator|*
name|m_transform
operator|)
operator|.
name|boundingRect
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|toRect
name|QRect
name|QAlphaPaintEnginePrivate
operator|::
name|toRect
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
specifier|const
block|{
name|QRect
name|r
decl_stmt|;
name|r
operator|.
name|setLeft
argument_list|(
name|int
argument_list|(
name|rect
operator|.
name|left
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|r
operator|.
name|setTop
argument_list|(
name|int
argument_list|(
name|rect
operator|.
name|top
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|r
operator|.
name|setRight
argument_list|(
name|int
argument_list|(
name|rect
operator|.
name|right
argument_list|()
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|r
operator|.
name|setBottom
argument_list|(
name|int
argument_list|(
name|rect
operator|.
name|bottom
argument_list|()
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|r
return|;
block|}
end_function
begin_function
DECL|function|addAlphaRect
name|void
name|QAlphaPaintEnginePrivate
operator|::
name|addAlphaRect
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
block|{
name|m_alphargn
operator||=
name|toRect
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|drawAlphaImage
name|void
name|QAlphaPaintEnginePrivate
operator|::
name|drawAlphaImage
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QAlphaPaintEngine
argument_list|)
expr_stmt|;
name|qreal
name|dpiX
init|=
name|qMax
argument_list|(
name|m_pdev
operator|->
name|logicalDpiX
argument_list|()
argument_list|,
literal|300
argument_list|)
decl_stmt|;
name|qreal
name|dpiY
init|=
name|qMax
argument_list|(
name|m_pdev
operator|->
name|logicalDpiY
argument_list|()
argument_list|,
literal|300
argument_list|)
decl_stmt|;
name|qreal
name|xscale
init|=
operator|(
name|dpiX
operator|/
name|m_pdev
operator|->
name|logicalDpiX
argument_list|()
operator|)
decl_stmt|;
name|qreal
name|yscale
init|=
operator|(
name|dpiY
operator|/
name|m_pdev
operator|->
name|logicalDpiY
argument_list|()
operator|)
decl_stmt|;
name|QTransform
name|picscale
decl_stmt|;
name|picscale
operator|.
name|scale
argument_list|(
name|xscale
argument_list|,
name|yscale
argument_list|)
expr_stmt|;
specifier|const
name|int
name|tileSize
init|=
literal|2048
decl_stmt|;
name|QSize
name|size
argument_list|(
operator|(
name|int
argument_list|(
name|rect
operator|.
name|width
argument_list|()
operator|*
name|xscale
argument_list|)
operator|)
argument_list|,
name|int
argument_list|(
name|rect
operator|.
name|height
argument_list|()
operator|*
name|yscale
argument_list|)
argument_list|)
decl_stmt|;
name|int
name|divw
init|=
operator|(
name|size
operator|.
name|width
argument_list|()
operator|/
name|tileSize
operator|)
decl_stmt|;
name|int
name|divh
init|=
operator|(
name|size
operator|.
name|height
argument_list|()
operator|/
name|tileSize
operator|)
decl_stmt|;
name|divw
operator|+=
literal|1
expr_stmt|;
name|divh
operator|+=
literal|1
expr_stmt|;
name|int
name|incx
init|=
name|int
argument_list|(
name|rect
operator|.
name|width
argument_list|()
operator|/
name|divw
argument_list|)
decl_stmt|;
name|int
name|incy
init|=
name|int
argument_list|(
name|rect
operator|.
name|height
argument_list|()
operator|/
name|divh
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|divh
condition|;
operator|++
name|y
control|)
block|{
name|int
name|ypos
init|=
name|int
argument_list|(
operator|(
name|incy
operator|*
name|y
operator|)
operator|+
name|rect
operator|.
name|y
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|height
init|=
name|int
argument_list|(
operator|(
name|y
operator|==
operator|(
name|divh
operator|-
literal|1
operator|)
operator|)
condition|?
operator|(
name|rect
operator|.
name|height
argument_list|()
operator|-
operator|(
name|incy
operator|*
name|y
operator|)
operator|)
else|:
name|incy
argument_list|)
operator|+
literal|1
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|divw
condition|;
operator|++
name|x
control|)
block|{
name|int
name|xpos
init|=
name|int
argument_list|(
operator|(
name|incx
operator|*
name|x
operator|)
operator|+
name|rect
operator|.
name|x
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|width
init|=
name|int
argument_list|(
operator|(
name|x
operator|==
operator|(
name|divw
operator|-
literal|1
operator|)
operator|)
condition|?
operator|(
name|rect
operator|.
name|width
argument_list|()
operator|-
operator|(
name|incx
operator|*
name|x
operator|)
operator|)
else|:
name|incx
argument_list|)
operator|+
literal|1
decl_stmt|;
name|QSize
name|imgsize
argument_list|(
call|(
name|int
call|)
argument_list|(
name|width
operator|*
name|xscale
argument_list|)
argument_list|,
call|(
name|int
call|)
argument_list|(
name|height
operator|*
name|yscale
argument_list|)
argument_list|)
decl_stmt|;
name|QImage
name|img
argument_list|(
name|imgsize
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
name|img
operator|.
name|fill
argument_list|(
literal|0xffffffff
argument_list|)
expr_stmt|;
name|QPainter
name|imgpainter
argument_list|(
operator|&
name|img
argument_list|)
decl_stmt|;
name|imgpainter
operator|.
name|setTransform
argument_list|(
name|picscale
argument_list|)
expr_stmt|;
name|QPointF
name|picpos
argument_list|(
name|qreal
argument_list|(
operator|-
name|xpos
argument_list|)
argument_list|,
name|qreal
argument_list|(
operator|-
name|ypos
argument_list|)
argument_list|)
decl_stmt|;
name|imgpainter
operator|.
name|drawPicture
argument_list|(
name|picpos
argument_list|,
operator|*
name|m_pic
argument_list|)
expr_stmt|;
name|imgpainter
operator|.
name|end
argument_list|()
expr_stmt|;
name|q
operator|->
name|painter
argument_list|()
operator|->
name|setTransform
argument_list|(
name|QTransform
argument_list|()
argument_list|)
expr_stmt|;
name|QRect
name|r
argument_list|(
name|xpos
argument_list|,
name|ypos
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
decl_stmt|;
name|q
operator|->
name|painter
argument_list|()
operator|->
name|drawImage
argument_list|(
name|r
argument_list|,
name|img
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|fullyContained
name|bool
name|QAlphaPaintEnginePrivate
operator|::
name|fullyContained
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
specifier|const
block|{
name|QRegion
name|r
argument_list|(
name|toRect
argument_list|(
name|rect
argument_list|)
argument_list|)
decl_stmt|;
return|return
operator|(
name|m_cliprgn
operator|.
name|intersected
argument_list|(
name|r
argument_list|)
operator|==
name|r
operator|)
return|;
block|}
end_function
begin_function
DECL|function|resetState
name|void
name|QAlphaPaintEnginePrivate
operator|::
name|resetState
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|)
block|{
name|p
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|->
name|setBrush
argument_list|(
name|QBrush
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|->
name|setBrushOrigin
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|p
operator|->
name|setBackground
argument_list|(
name|QBrush
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|->
name|setFont
argument_list|(
name|QFont
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|->
name|setTransform
argument_list|(
name|QTransform
argument_list|()
argument_list|)
expr_stmt|;
comment|// The view transform is already recorded and included in the
comment|// picture we're about to replay. If we don't turn if off,
comment|// the view matrix will be applied twice.
name|p
operator|->
name|setViewTransformEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|p
operator|->
name|setClipRegion
argument_list|(
name|QRegion
argument_list|()
argument_list|,
name|Qt
operator|::
name|NoClip
argument_list|)
expr_stmt|;
name|p
operator|->
name|setClipPath
argument_list|(
name|QPainterPath
argument_list|()
argument_list|,
name|Qt
operator|::
name|NoClip
argument_list|)
expr_stmt|;
name|p
operator|->
name|setClipping
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|p
operator|->
name|setOpacity
argument_list|(
literal|1.0f
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTER
end_comment
end_unit
