begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"arthurwidgets.h"
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QPainterPath>
end_include
begin_include
include|#
directive|include
file|<QPixmapCache>
end_include
begin_include
include|#
directive|include
file|<QtEvents>
end_include
begin_include
include|#
directive|include
file|<QTextDocument>
end_include
begin_include
include|#
directive|include
file|<QAbstractTextDocumentLayout>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QTextBrowser>
end_include
begin_include
include|#
directive|include
file|<QBoxLayout>
end_include
begin_function_decl
specifier|extern
name|QPixmap
name|cached
parameter_list|(
specifier|const
name|QString
modifier|&
name|img
parameter_list|)
function_decl|;
end_function_decl
begin_constructor
DECL|function|ArthurFrame
name|ArthurFrame
operator|::
name|ArthurFrame
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_prefer_image
argument_list|(
literal|false
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_OPENGL_SUPPORT
name|glw
operator|=
literal|0
expr_stmt|;
name|m_use_opengl
operator|=
literal|false
expr_stmt|;
name|QGLFormat
name|f
init|=
name|QGLFormat
operator|::
name|defaultFormat
argument_list|()
decl_stmt|;
name|f
operator|.
name|setSampleBuffers
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|f
operator|.
name|setStencil
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|f
operator|.
name|setAlpha
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|f
operator|.
name|setAlphaBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|QGLFormat
operator|::
name|setDefaultFormat
argument_list|(
name|f
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|m_document
operator|=
literal|0
expr_stmt|;
name|m_show_doc
operator|=
literal|false
expr_stmt|;
name|m_tile
operator|=
name|QPixmap
argument_list|(
literal|128
argument_list|,
literal|128
argument_list|)
expr_stmt|;
name|m_tile
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|QPainter
name|pt
argument_list|(
operator|&
name|m_tile
argument_list|)
decl_stmt|;
name|QColor
name|color
argument_list|(
literal|230
argument_list|,
literal|230
argument_list|,
literal|230
argument_list|)
decl_stmt|;
name|pt
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|64
argument_list|,
literal|64
argument_list|,
name|color
argument_list|)
expr_stmt|;
name|pt
operator|.
name|fillRect
argument_list|(
literal|64
argument_list|,
literal|64
argument_list|,
literal|64
argument_list|,
literal|64
argument_list|,
name|color
argument_list|)
expr_stmt|;
name|pt
operator|.
name|end
argument_list|()
expr_stmt|;
comment|//     QPalette pal = palette();
comment|//     pal.setBrush(backgroundRole(), m_tile);
comment|//     setPalette(pal);
block|}
end_constructor
begin_ifdef
ifdef|#
directive|ifdef
name|QT_OPENGL_SUPPORT
end_ifdef
begin_function
DECL|function|enableOpenGL
name|void
name|ArthurFrame
operator|::
name|enableOpenGL
parameter_list|(
name|bool
name|use_opengl
parameter_list|)
block|{
if|if
condition|(
name|m_use_opengl
operator|==
name|use_opengl
condition|)
return|return;
if|if
condition|(
operator|!
name|glw
operator|&&
name|use_opengl
condition|)
block|{
name|glw
operator|=
operator|new
name|GLWidget
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|glw
operator|->
name|setAutoFillBackground
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|glw
operator|->
name|disableAutoBufferSwap
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|postEvent
argument_list|(
name|this
argument_list|,
operator|new
name|QResizeEvent
argument_list|(
name|size
argument_list|()
argument_list|,
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|m_use_opengl
operator|=
name|use_opengl
expr_stmt|;
if|if
condition|(
name|use_opengl
condition|)
block|{
name|glw
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|glw
condition|)
name|glw
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|paintEvent
name|void
name|ArthurFrame
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|e
parameter_list|)
block|{
specifier|static
name|QImage
modifier|*
name|static_image
init|=
literal|0
decl_stmt|;
name|QPainter
name|painter
decl_stmt|;
if|if
condition|(
name|preferImage
argument_list|()
ifdef|#
directive|ifdef
name|QT_OPENGL_SUPPORT
operator|&&
operator|!
name|m_use_opengl
endif|#
directive|endif
condition|)
block|{
if|if
condition|(
operator|!
name|static_image
operator|||
name|static_image
operator|->
name|size
argument_list|()
operator|!=
name|size
argument_list|()
condition|)
block|{
operator|delete
name|static_image
expr_stmt|;
name|static_image
operator|=
operator|new
name|QImage
argument_list|(
name|size
argument_list|()
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
expr_stmt|;
block|}
name|painter
operator|.
name|begin
argument_list|(
name|static_image
argument_list|)
expr_stmt|;
name|int
name|o
init|=
literal|10
decl_stmt|;
name|QBrush
name|bg
init|=
name|palette
argument_list|()
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Background
argument_list|)
decl_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|o
argument_list|,
name|o
argument_list|,
name|bg
argument_list|)
expr_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
name|width
argument_list|()
operator|-
name|o
argument_list|,
literal|0
argument_list|,
name|o
argument_list|,
name|o
argument_list|,
name|bg
argument_list|)
expr_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
name|height
argument_list|()
operator|-
name|o
argument_list|,
name|o
argument_list|,
name|o
argument_list|,
name|bg
argument_list|)
expr_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
name|width
argument_list|()
operator|-
name|o
argument_list|,
name|height
argument_list|()
operator|-
name|o
argument_list|,
name|o
argument_list|,
name|o
argument_list|,
name|bg
argument_list|)
expr_stmt|;
block|}
else|else
block|{
ifdef|#
directive|ifdef
name|QT_OPENGL_SUPPORT
if|if
condition|(
name|m_use_opengl
condition|)
block|{
name|painter
operator|.
name|begin
argument_list|(
name|glw
argument_list|)
expr_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|glw
operator|->
name|width
argument_list|()
argument_list|,
name|glw
operator|->
name|height
argument_list|()
argument_list|)
argument_list|,
name|palette
argument_list|()
operator|.
name|color
argument_list|(
name|backgroundRole
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|painter
operator|.
name|begin
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|painter
operator|.
name|begin
argument_list|(
name|this
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|painter
operator|.
name|setClipRect
argument_list|(
name|e
operator|->
name|rect
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|QPainterPath
name|clipPath
decl_stmt|;
name|QRect
name|r
init|=
name|rect
argument_list|()
decl_stmt|;
name|qreal
name|left
init|=
name|r
operator|.
name|x
argument_list|()
operator|+
literal|1
decl_stmt|;
name|qreal
name|top
init|=
name|r
operator|.
name|y
argument_list|()
operator|+
literal|1
decl_stmt|;
name|qreal
name|right
init|=
name|r
operator|.
name|right
argument_list|()
decl_stmt|;
name|qreal
name|bottom
init|=
name|r
operator|.
name|bottom
argument_list|()
decl_stmt|;
name|qreal
name|radius2
init|=
literal|8
operator|*
literal|2
decl_stmt|;
name|clipPath
operator|.
name|moveTo
argument_list|(
name|right
operator|-
name|radius2
argument_list|,
name|top
argument_list|)
expr_stmt|;
name|clipPath
operator|.
name|arcTo
argument_list|(
name|right
operator|-
name|radius2
argument_list|,
name|top
argument_list|,
name|radius2
argument_list|,
name|radius2
argument_list|,
literal|90
argument_list|,
operator|-
literal|90
argument_list|)
expr_stmt|;
name|clipPath
operator|.
name|arcTo
argument_list|(
name|right
operator|-
name|radius2
argument_list|,
name|bottom
operator|-
name|radius2
argument_list|,
name|radius2
argument_list|,
name|radius2
argument_list|,
literal|0
argument_list|,
operator|-
literal|90
argument_list|)
expr_stmt|;
name|clipPath
operator|.
name|arcTo
argument_list|(
name|left
argument_list|,
name|bottom
operator|-
name|radius2
argument_list|,
name|radius2
argument_list|,
name|radius2
argument_list|,
literal|270
argument_list|,
operator|-
literal|90
argument_list|)
expr_stmt|;
name|clipPath
operator|.
name|arcTo
argument_list|(
name|left
argument_list|,
name|top
argument_list|,
name|radius2
argument_list|,
name|radius2
argument_list|,
literal|180
argument_list|,
operator|-
literal|90
argument_list|)
expr_stmt|;
name|clipPath
operator|.
name|closeSubpath
argument_list|()
expr_stmt|;
name|painter
operator|.
name|save
argument_list|()
expr_stmt|;
name|painter
operator|.
name|setClipPath
argument_list|(
name|clipPath
argument_list|,
name|Qt
operator|::
name|IntersectClip
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawTiledPixmap
argument_list|(
name|rect
argument_list|()
argument_list|,
name|m_tile
argument_list|)
expr_stmt|;
comment|// client painting
name|paint
argument_list|(
operator|&
name|painter
argument_list|)
expr_stmt|;
name|painter
operator|.
name|restore
argument_list|()
expr_stmt|;
name|painter
operator|.
name|save
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_show_doc
condition|)
name|paintDescription
argument_list|(
operator|&
name|painter
argument_list|)
expr_stmt|;
name|painter
operator|.
name|restore
argument_list|()
expr_stmt|;
name|int
name|level
init|=
literal|180
decl_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|QPen
argument_list|(
name|QColor
argument_list|(
name|level
argument_list|,
name|level
argument_list|,
name|level
argument_list|)
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setBrush
argument_list|(
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawPath
argument_list|(
name|clipPath
argument_list|)
expr_stmt|;
if|if
condition|(
name|preferImage
argument_list|()
ifdef|#
directive|ifdef
name|QT_OPENGL_SUPPORT
operator|&&
operator|!
name|m_use_opengl
endif|#
directive|endif
condition|)
block|{
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
name|painter
operator|.
name|begin
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawImage
argument_list|(
name|e
operator|->
name|rect
argument_list|()
argument_list|,
operator|*
name|static_image
argument_list|,
name|e
operator|->
name|rect
argument_list|()
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|QT_OPENGL_SUPPORT
if|if
condition|(
name|m_use_opengl
operator|&&
operator|(
name|inherits
argument_list|(
literal|"PathDeformRenderer"
argument_list|)
operator|||
name|inherits
argument_list|(
literal|"PathStrokeRenderer"
argument_list|)
operator|||
name|inherits
argument_list|(
literal|"CompositionRenderer"
argument_list|)
operator|||
name|m_show_doc
operator|)
condition|)
name|glw
operator|->
name|swapBuffers
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|ArthurFrame
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|e
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_OPENGL_SUPPORT
if|if
condition|(
name|glw
condition|)
name|glw
operator|->
name|setGeometry
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|e
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
operator|-
literal|1
argument_list|,
name|e
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QWidget
operator|::
name|resizeEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setDescriptionEnabled
name|void
name|ArthurFrame
operator|::
name|setDescriptionEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
if|if
condition|(
name|m_show_doc
operator|!=
name|enabled
condition|)
block|{
name|m_show_doc
operator|=
name|enabled
expr_stmt|;
emit|emit
name|descriptionEnabledChanged
argument_list|(
name|m_show_doc
argument_list|)
emit|;
name|update
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|loadDescription
name|void
name|ArthurFrame
operator|::
name|loadDescription
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QFile
name|textFile
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
name|QString
name|text
decl_stmt|;
if|if
condition|(
operator|!
name|textFile
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
condition|)
name|text
operator|=
name|QString
argument_list|(
literal|"Unable to load resource file: '%1'"
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
else|else
name|text
operator|=
name|textFile
operator|.
name|readAll
argument_list|()
expr_stmt|;
name|setDescription
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setDescription
name|void
name|ArthurFrame
operator|::
name|setDescription
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|m_document
operator|=
operator|new
name|QTextDocument
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_document
operator|->
name|setHtml
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintDescription
name|void
name|ArthurFrame
operator|::
name|paintDescription
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_document
condition|)
return|return;
name|int
name|pageWidth
init|=
name|qMax
argument_list|(
name|width
argument_list|()
operator|-
literal|100
argument_list|,
literal|100
argument_list|)
decl_stmt|;
name|int
name|pageHeight
init|=
name|qMax
argument_list|(
name|height
argument_list|()
operator|-
literal|100
argument_list|,
literal|100
argument_list|)
decl_stmt|;
if|if
condition|(
name|pageWidth
operator|!=
name|m_document
operator|->
name|pageSize
argument_list|()
operator|.
name|width
argument_list|()
condition|)
block|{
name|m_document
operator|->
name|setPageSize
argument_list|(
name|QSize
argument_list|(
name|pageWidth
argument_list|,
name|pageHeight
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QRect
name|textRect
argument_list|(
name|width
argument_list|()
operator|/
literal|2
operator|-
name|pageWidth
operator|/
literal|2
argument_list|,
name|height
argument_list|()
operator|/
literal|2
operator|-
name|pageHeight
operator|/
literal|2
argument_list|,
name|pageWidth
argument_list|,
name|pageHeight
argument_list|)
decl_stmt|;
name|int
name|pad
init|=
literal|10
decl_stmt|;
name|QRect
name|clearRect
init|=
name|textRect
operator|.
name|adjusted
argument_list|(
operator|-
name|pad
argument_list|,
operator|-
name|pad
argument_list|,
name|pad
argument_list|,
name|pad
argument_list|)
decl_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|63
argument_list|)
argument_list|)
expr_stmt|;
name|int
name|shade
init|=
literal|10
decl_stmt|;
name|painter
operator|->
name|drawRect
argument_list|(
name|clearRect
operator|.
name|x
argument_list|()
operator|+
name|clearRect
operator|.
name|width
argument_list|()
operator|+
literal|1
argument_list|,
name|clearRect
operator|.
name|y
argument_list|()
operator|+
name|shade
argument_list|,
name|shade
argument_list|,
name|clearRect
operator|.
name|height
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRect
argument_list|(
name|clearRect
operator|.
name|x
argument_list|()
operator|+
name|shade
argument_list|,
name|clearRect
operator|.
name|y
argument_list|()
operator|+
name|clearRect
operator|.
name|height
argument_list|()
operator|+
literal|1
argument_list|,
name|clearRect
operator|.
name|width
argument_list|()
operator|-
name|shade
operator|+
literal|1
argument_list|,
name|shade
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|QColor
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|,
literal|220
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRect
argument_list|(
name|clearRect
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setClipRegion
argument_list|(
name|textRect
argument_list|,
name|Qt
operator|::
name|IntersectClip
argument_list|)
expr_stmt|;
name|painter
operator|->
name|translate
argument_list|(
name|textRect
operator|.
name|topLeft
argument_list|()
argument_list|)
expr_stmt|;
name|QAbstractTextDocumentLayout
operator|::
name|PaintContext
name|ctx
decl_stmt|;
name|QLinearGradient
name|g
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|textRect
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|g
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|g
operator|.
name|setColorAt
argument_list|(
literal|0.9
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|g
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|QPalette
name|pal
init|=
name|palette
argument_list|()
decl_stmt|;
name|pal
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Text
argument_list|,
name|g
argument_list|)
expr_stmt|;
name|ctx
operator|.
name|palette
operator|=
name|pal
expr_stmt|;
name|ctx
operator|.
name|clip
operator|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|textRect
operator|.
name|width
argument_list|()
argument_list|,
name|textRect
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|m_document
operator|->
name|documentLayout
argument_list|()
operator|->
name|draw
argument_list|(
name|painter
argument_list|,
name|ctx
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loadSourceFile
name|void
name|ArthurFrame
operator|::
name|loadSourceFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|sourceFile
parameter_list|)
block|{
name|m_sourceFileName
operator|=
name|sourceFile
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showSource
name|void
name|ArthurFrame
operator|::
name|showSource
parameter_list|()
block|{
comment|// Check for existing source
if|if
condition|(
name|findChild
argument_list|<
name|QTextBrowser
operator|*
argument_list|>
argument_list|()
condition|)
return|return;
name|QString
name|contents
decl_stmt|;
if|if
condition|(
name|m_sourceFileName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|contents
operator|=
name|QString
argument_list|(
literal|"No source for widget: '%1'"
argument_list|)
operator|.
name|arg
argument_list|(
name|objectName
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QFile
name|f
argument_list|(
name|m_sourceFileName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
condition|)
name|contents
operator|=
name|QString
argument_list|(
literal|"Could not open file: '%1'"
argument_list|)
operator|.
name|arg
argument_list|(
name|m_sourceFileName
argument_list|)
expr_stmt|;
else|else
name|contents
operator|=
name|f
operator|.
name|readAll
argument_list|()
expr_stmt|;
block|}
name|contents
operator|.
name|replace
argument_list|(
literal|'&'
argument_list|,
literal|"&amp;"
argument_list|)
expr_stmt|;
name|contents
operator|.
name|replace
argument_list|(
literal|'<'
argument_list|,
literal|"&lt;"
argument_list|)
expr_stmt|;
name|contents
operator|.
name|replace
argument_list|(
literal|'>'
argument_list|,
literal|"&gt;"
argument_list|)
expr_stmt|;
name|QStringList
name|keywords
decl_stmt|;
name|keywords
operator|<<
literal|"for "
operator|<<
literal|"if "
operator|<<
literal|"switch "
operator|<<
literal|" int "
operator|<<
literal|"#include "
operator|<<
literal|"const"
operator|<<
literal|"void "
operator|<<
literal|"uint "
operator|<<
literal|"case "
operator|<<
literal|"double "
operator|<<
literal|"#define "
operator|<<
literal|"static"
operator|<<
literal|"new"
operator|<<
literal|"this"
expr_stmt|;
foreach|foreach
control|(
name|QString
name|keyword
decl|,
name|keywords
control|)
name|contents
operator|.
name|replace
argument_list|(
name|keyword
argument_list|,
name|QLatin1String
argument_list|(
literal|"<font color=olive>"
argument_list|)
operator|+
name|keyword
operator|+
name|QLatin1String
argument_list|(
literal|"</font>"
argument_list|)
argument_list|)
expr_stmt|;
name|contents
operator|.
name|replace
argument_list|(
literal|"(int "
argument_list|,
literal|"(<font color=olive><b>int</b></font>"
argument_list|)
expr_stmt|;
name|QStringList
name|ppKeywords
decl_stmt|;
name|ppKeywords
operator|<<
literal|"#ifdef"
operator|<<
literal|"#ifndef"
operator|<<
literal|"#if"
operator|<<
literal|"#endif"
operator|<<
literal|"#else"
expr_stmt|;
foreach|foreach
control|(
name|QString
name|keyword
decl|,
name|ppKeywords
control|)
name|contents
operator|.
name|replace
argument_list|(
name|keyword
argument_list|,
name|QLatin1String
argument_list|(
literal|"<font color=navy>"
argument_list|)
operator|+
name|keyword
operator|+
name|QLatin1String
argument_list|(
literal|"</font>"
argument_list|)
argument_list|)
expr_stmt|;
name|contents
operator|.
name|replace
argument_list|(
name|QRegExp
argument_list|(
literal|"(\\d\\d?)"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"<font color=navy>\\1</font>"
argument_list|)
argument_list|)
expr_stmt|;
name|QRegExp
name|commentRe
argument_list|(
literal|"(//.+)\\n"
argument_list|)
decl_stmt|;
name|commentRe
operator|.
name|setMinimal
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|contents
operator|.
name|replace
argument_list|(
name|commentRe
argument_list|,
name|QLatin1String
argument_list|(
literal|"<font color=red>\\1</font>\n"
argument_list|)
argument_list|)
expr_stmt|;
name|QRegExp
name|stringLiteralRe
argument_list|(
literal|"(\".+\")"
argument_list|)
decl_stmt|;
name|stringLiteralRe
operator|.
name|setMinimal
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|contents
operator|.
name|replace
argument_list|(
name|stringLiteralRe
argument_list|,
name|QLatin1String
argument_list|(
literal|"<font color=green>\\1</font>"
argument_list|)
argument_list|)
expr_stmt|;
name|QString
name|html
init|=
name|contents
decl_stmt|;
name|html
operator|.
name|prepend
argument_list|(
literal|"<html><pre>"
argument_list|)
expr_stmt|;
name|html
operator|.
name|append
argument_list|(
literal|"</pre></html>"
argument_list|)
expr_stmt|;
name|QTextBrowser
modifier|*
name|sourceViewer
init|=
operator|new
name|QTextBrowser
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|sourceViewer
operator|->
name|setWindowTitle
argument_list|(
literal|"Source: "
operator|+
name|m_sourceFileName
operator|.
name|mid
argument_list|(
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|sourceViewer
operator|->
name|setParent
argument_list|(
name|this
argument_list|,
name|Qt
operator|::
name|Dialog
argument_list|)
expr_stmt|;
name|sourceViewer
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DeleteOnClose
argument_list|)
expr_stmt|;
name|sourceViewer
operator|->
name|setLineWrapMode
argument_list|(
name|QTextEdit
operator|::
name|NoWrap
argument_list|)
expr_stmt|;
name|sourceViewer
operator|->
name|setHtml
argument_list|(
name|html
argument_list|)
expr_stmt|;
name|sourceViewer
operator|->
name|resize
argument_list|(
literal|600
argument_list|,
literal|600
argument_list|)
expr_stmt|;
name|sourceViewer
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
