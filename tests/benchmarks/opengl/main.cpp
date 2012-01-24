begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<private/qpaintengine_opengl_p.h>
end_include
begin_class
DECL|class|OpenGLBench
class|class
name|OpenGLBench
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
name|void
name|imageDrawing_data
parameter_list|()
function_decl|;
name|void
name|imageDrawing
parameter_list|()
function_decl|;
name|void
name|pathDrawing_data
parameter_list|()
function_decl|;
name|void
name|pathDrawing
parameter_list|()
function_decl|;
name|void
name|painterOverhead
parameter_list|()
function_decl|;
name|void
name|startupCost_data
parameter_list|()
function_decl|;
name|void
name|startupCost
parameter_list|()
function_decl|;
name|void
name|lineDrawing
parameter_list|()
function_decl|;
name|void
name|textDrawing_data
parameter_list|()
function_decl|;
name|void
name|textDrawing
parameter_list|()
function_decl|;
name|void
name|clippedPainting_data
parameter_list|()
function_decl|;
name|void
name|clippedPainting
parameter_list|()
function_decl|;
name|void
name|gradients_data
parameter_list|()
function_decl|;
name|void
name|gradients
parameter_list|()
function_decl|;
name|void
name|textureUpload_data
parameter_list|()
function_decl|;
name|void
name|textureUpload
parameter_list|()
function_decl|;
private|private:
DECL|member|pb
name|QGLPixelBuffer
modifier|*
name|pb
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|OpenGLBench
operator|::
name|initTestCase
parameter_list|()
block|{
name|pb
operator|=
operator|new
name|QGLPixelBuffer
argument_list|(
literal|512
argument_list|,
literal|512
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
name|pb
argument_list|)
decl_stmt|;
name|p
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|p
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|HighQualityAntialiasing
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|QImage
argument_list|(
literal|256
argument_list|,
literal|256
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|OpenGLBench
operator|::
name|cleanupTestCase
parameter_list|()
block|{
operator|delete
name|pb
expr_stmt|;
block|}
end_function
begin_function
DECL|function|imageDrawing_data
name|void
name|OpenGLBench
operator|::
name|imageDrawing_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"smoothPixmapTransform"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"highQualityAntialiasing"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"pixmap"
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
operator|(
literal|1
operator|<<
literal|3
operator|)
condition|;
operator|++
name|i
control|)
block|{
name|bool
name|smoothPixmapTransform
init|=
name|i
operator|&
literal|1
decl_stmt|;
name|bool
name|highQualityAntialiasing
init|=
name|i
operator|&
literal|2
decl_stmt|;
name|bool
name|pixmap
init|=
name|i
operator|&
literal|4
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|QString
argument_list|(
literal|"pixmap=%1 highQualityAntialiasing=%2 smoothPixmapTransform=%3"
argument_list|)
operator|.
name|arg
argument_list|(
name|pixmap
argument_list|)
operator|.
name|arg
argument_list|(
name|highQualityAntialiasing
argument_list|)
operator|.
name|arg
argument_list|(
name|smoothPixmapTransform
argument_list|)
operator|.
name|toAscii
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
operator|<<
name|pixmap
operator|<<
name|highQualityAntialiasing
operator|<<
name|smoothPixmapTransform
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|imageDrawing
name|void
name|OpenGLBench
operator|::
name|imageDrawing
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|smoothPixmapTransform
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|highQualityAntialiasing
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
name|QImage
name|img
decl_stmt|;
name|QPixmap
name|pm
decl_stmt|;
if|if
condition|(
name|pixmap
condition|)
name|pm
operator|=
name|QPixmap
argument_list|(
literal|800
argument_list|,
literal|800
argument_list|)
expr_stmt|;
else|else
name|img
operator|=
name|QImage
argument_list|(
literal|800
argument_list|,
literal|800
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
name|pb
argument_list|)
decl_stmt|;
name|p
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|SmoothPixmapTransform
argument_list|,
name|smoothPixmapTransform
argument_list|)
expr_stmt|;
name|p
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|,
name|highQualityAntialiasing
argument_list|)
expr_stmt|;
name|p
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|HighQualityAntialiasing
argument_list|,
name|highQualityAntialiasing
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
if|if
condition|(
name|pixmap
condition|)
block|{
name|pm
operator|.
name|detach
argument_list|()
expr_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|pm
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|img
operator|.
name|detach
argument_list|()
expr_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|img
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QPainterPath
argument_list|)
end_macro
begin_function
DECL|function|pathDrawing_data
name|void
name|OpenGLBench
operator|::
name|pathDrawing_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPainterPath
argument_list|>
argument_list|(
literal|"path"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"highQualityAntialiasing"
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QPair
argument_list|<
name|QPainterPath
argument_list|,
name|QLatin1String
argument_list|>
argument_list|>
name|paths
decl_stmt|;
block|{
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|addRect
argument_list|(
operator|-
literal|100
argument_list|,
operator|-
literal|100
argument_list|,
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|paths
operator|<<
name|qMakePair
argument_list|(
name|path
argument_list|,
name|QLatin1String
argument_list|(
literal|"plain rect"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|addRoundedRect
argument_list|(
operator|-
literal|100
argument_list|,
operator|-
literal|100
argument_list|,
literal|200
argument_list|,
literal|200
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|paths
operator|<<
name|qMakePair
argument_list|(
name|path
argument_list|,
name|QLatin1String
argument_list|(
literal|"rounded rect"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|addEllipse
argument_list|(
operator|-
literal|100
argument_list|,
operator|-
literal|100
argument_list|,
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|paths
operator|<<
name|qMakePair
argument_list|(
name|path
argument_list|,
name|QLatin1String
argument_list|(
literal|"ellipse"
argument_list|)
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
operator|(
literal|1
operator|<<
literal|1
operator|)
condition|;
operator|++
name|j
control|)
block|{
name|bool
name|highQualityAntialiasing
init|=
name|j
operator|&
literal|1
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
name|paths
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QTest
operator|::
name|newRow
argument_list|(
name|QString
argument_list|(
literal|"path=%1 highQualityAntialiasing=%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|paths
index|[
name|i
index|]
operator|.
name|second
argument_list|)
operator|.
name|arg
argument_list|(
name|highQualityAntialiasing
argument_list|)
operator|.
name|toAscii
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
operator|<<
name|paths
index|[
name|i
index|]
operator|.
name|first
operator|<<
name|highQualityAntialiasing
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|pathDrawing
name|void
name|OpenGLBench
operator|::
name|pathDrawing
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPainterPath
argument_list|,
name|path
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|highQualityAntialiasing
argument_list|)
expr_stmt|;
comment|// warm-up
block|{
name|QPainterPath
name|dummy
decl_stmt|;
name|dummy
operator|.
name|addRect
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
name|pb
argument_list|)
decl_stmt|;
name|p
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|,
name|highQualityAntialiasing
argument_list|)
expr_stmt|;
name|p
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|HighQualityAntialiasing
argument_list|,
name|highQualityAntialiasing
argument_list|)
expr_stmt|;
name|p
operator|.
name|translate
argument_list|(
name|pb
operator|->
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|pb
operator|->
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|p
operator|.
name|rotate
argument_list|(
literal|30
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawPath
argument_list|(
name|dummy
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
block|}
name|QPainter
name|p
argument_list|(
name|pb
argument_list|)
decl_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|p
operator|.
name|setBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|p
operator|.
name|translate
argument_list|(
name|pb
operator|->
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|pb
operator|->
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|p
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|,
name|highQualityAntialiasing
argument_list|)
expr_stmt|;
name|p
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|HighQualityAntialiasing
argument_list|,
name|highQualityAntialiasing
argument_list|)
expr_stmt|;
name|p
operator|.
name|rotate
argument_list|(
literal|0.01
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|painterOverhead
name|void
name|OpenGLBench
operator|::
name|painterOverhead
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QPainter
name|p
argument_list|(
name|pb
argument_list|)
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|startupCost_data
name|void
name|OpenGLBench
operator|::
name|startupCost_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"highQualityAntialiasing"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"highQualityAntialiasing=0"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"highQualityAntialiasing=1"
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|startupCost
name|void
name|OpenGLBench
operator|::
name|startupCost
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|highQualityAntialiasing
argument_list|)
expr_stmt|;
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|addRoundedRect
argument_list|(
operator|-
literal|100
argument_list|,
operator|-
literal|100
argument_list|,
literal|200
argument_list|,
literal|200
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|QGLPixelBuffer
name|buffer
argument_list|(
literal|512
argument_list|,
literal|512
argument_list|)
decl_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|buffer
argument_list|)
decl_stmt|;
name|p
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|,
name|highQualityAntialiasing
argument_list|)
expr_stmt|;
name|p
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|HighQualityAntialiasing
argument_list|,
name|highQualityAntialiasing
argument_list|)
expr_stmt|;
name|p
operator|.
name|translate
argument_list|(
name|buffer
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|buffer
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|lineDrawing
name|void
name|OpenGLBench
operator|::
name|lineDrawing
parameter_list|()
block|{
name|QPainter
name|p
argument_list|(
name|pb
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|p
operator|.
name|drawLine
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|500
argument_list|,
literal|500
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|textDrawing_data
name|void
name|OpenGLBench
operator|::
name|textDrawing_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"lines"
argument_list|)
expr_stmt|;
name|int
name|lines
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|8
block|,
literal|16
block|,
literal|32
block|,
literal|64
block|,
literal|128
block|}
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"text lines=1 (warmup run)"
argument_list|)
operator|<<
literal|1
expr_stmt|;
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|lines
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
condition|;
operator|++
name|i
control|)
name|QTest
operator|::
name|newRow
argument_list|(
name|QString
argument_list|(
literal|"text lines=%0"
argument_list|)
operator|.
name|arg
argument_list|(
name|lines
index|[
name|i
index|]
argument_list|)
operator|.
name|toAscii
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
operator|<<
name|lines
index|[
name|i
index|]
expr_stmt|;
block|}
end_function
begin_function
DECL|function|textDrawing
name|void
name|OpenGLBench
operator|::
name|textDrawing
parameter_list|()
block|{
name|QPainter
name|p
argument_list|(
name|pb
argument_list|)
decl_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|lines
argument_list|)
expr_stmt|;
name|p
operator|.
name|translate
argument_list|(
literal|0
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|lines
condition|;
operator|++
name|i
control|)
name|p
operator|.
name|drawText
argument_list|(
literal|0
argument_list|,
name|i
argument_list|,
literal|"Hello World!"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|clippedPainting_data
name|void
name|OpenGLBench
operator|::
name|clippedPainting_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPainterPath
argument_list|>
argument_list|(
literal|"path"
argument_list|)
expr_stmt|;
name|QRectF
name|rect
init|=
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|pb
operator|->
name|width
argument_list|()
argument_list|,
name|pb
operator|->
name|height
argument_list|()
argument_list|)
operator|.
name|adjusted
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|,
operator|-
literal|5
argument_list|,
operator|-
literal|5
argument_list|)
decl_stmt|;
block|{
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|addRect
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rect path"
argument_list|)
operator|<<
name|path
expr_stmt|;
block|}
block|{
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|addRoundedRect
argument_list|(
name|rect
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rounded rect path"
argument_list|)
operator|<<
name|path
expr_stmt|;
block|}
block|{
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|addEllipse
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"ellipse path"
argument_list|)
operator|<<
name|path
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|clippedPainting
name|void
name|OpenGLBench
operator|::
name|clippedPainting
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPainterPath
argument_list|,
name|path
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|QPainter
name|p
argument_list|(
name|pb
argument_list|)
decl_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|p
operator|.
name|setBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|p
operator|.
name|setClipPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|pb
operator|->
name|width
argument_list|()
argument_list|,
name|pb
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QGradient::Type
argument_list|)
end_macro
begin_function
DECL|function|gradients_data
name|void
name|OpenGLBench
operator|::
name|gradients_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QGradient
operator|::
name|Type
argument_list|>
argument_list|(
literal|"gradientType"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"objectBoundingMode"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"warmup run"
argument_list|)
operator|<<
name|QGradient
operator|::
name|LinearGradient
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"linear gradient"
argument_list|)
operator|<<
name|QGradient
operator|::
name|LinearGradient
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"radial gradient"
argument_list|)
operator|<<
name|QGradient
operator|::
name|RadialGradient
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"conical gradient"
argument_list|)
operator|<<
name|QGradient
operator|::
name|ConicalGradient
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"linear gradient, object bounding mode"
argument_list|)
operator|<<
name|QGradient
operator|::
name|LinearGradient
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"radial gradient, object bounding mode"
argument_list|)
operator|<<
name|QGradient
operator|::
name|RadialGradient
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"conical gradient, object bounding mode"
argument_list|)
operator|<<
name|QGradient
operator|::
name|ConicalGradient
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|gradients
name|void
name|OpenGLBench
operator|::
name|gradients
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QGradient
operator|::
name|Type
argument_list|,
name|gradientType
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|objectBoundingMode
argument_list|)
expr_stmt|;
name|QPointF
name|a
decl_stmt|;
name|QPointF
name|b
init|=
name|objectBoundingMode
condition|?
name|QPointF
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
else|:
name|QPointF
argument_list|(
name|pb
operator|->
name|width
argument_list|()
argument_list|,
name|pb
operator|->
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|QGradient
name|gradient
decl_stmt|;
switch|switch
condition|(
name|gradientType
condition|)
block|{
case|case
name|QGradient
operator|::
name|LinearGradient
case|:
name|gradient
operator|=
name|QLinearGradient
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
break|break;
case|case
name|QGradient
operator|::
name|RadialGradient
case|:
name|gradient
operator|=
name|QRadialGradient
argument_list|(
name|a
argument_list|,
name|b
operator|.
name|x
argument_list|()
operator|/
literal|2
argument_list|,
name|b
argument_list|)
expr_stmt|;
break|break;
case|case
name|QGradient
operator|::
name|ConicalGradient
case|:
name|gradient
operator|=
name|QConicalGradient
argument_list|(
operator|(
name|a
operator|+
name|b
operator|)
operator|/
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
if|if
condition|(
name|objectBoundingMode
condition|)
name|gradient
operator|.
name|setCoordinateMode
argument_list|(
name|QGradient
operator|::
name|ObjectBoundingMode
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0.2
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0.4
argument_list|,
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0.6
argument_list|,
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0.8
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
name|pb
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|p
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|pb
operator|->
name|width
argument_list|()
argument_list|,
name|pb
operator|->
name|height
argument_list|()
argument_list|,
name|gradient
argument_list|)
expr_stmt|;
name|glFinish
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|textureUpload_data
name|void
name|OpenGLBench
operator|::
name|textureUpload_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"flags"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"format"
argument_list|)
expr_stmt|;
name|int
name|sizes
index|[]
init|=
block|{
literal|8
block|,
literal|10
block|,
literal|16
block|,
literal|20
block|,
literal|32
block|,
literal|50
block|,
literal|64
block|,
literal|100
block|,
literal|128
block|,
literal|200
block|,
literal|256
block|,
literal|500
block|,
literal|512
block|,
literal|1000
block|,
literal|1024
block|,
literal|2000
block|,
literal|2048
block|,
operator|-
literal|1
block|}
decl_stmt|;
name|int
name|flags
index|[]
init|=
block|{
name|QGLContext
operator|::
name|InternalBindOption
block|,
name|QGLContext
operator|::
name|DefaultBindOption
block|,
operator|-
literal|1
block|}
decl_stmt|;
name|int
name|formats
index|[]
init|=
block|{
name|GL_RGB
block|,
name|GL_RGBA
block|,
operator|-
literal|1
block|}
decl_stmt|;
for|for
control|(
name|int
name|s
init|=
literal|0
init|;
name|sizes
index|[
name|s
index|]
operator|!=
operator|-
literal|1
condition|;
operator|++
name|s
control|)
block|{
for|for
control|(
name|int
name|f
init|=
literal|0
init|;
name|flags
index|[
name|f
index|]
operator|!=
operator|-
literal|1
condition|;
operator|++
name|f
control|)
block|{
for|for
control|(
name|int
name|a
init|=
literal|0
init|;
name|formats
index|[
name|a
index|]
operator|!=
operator|-
literal|1
condition|;
operator|++
name|a
control|)
block|{
name|QByteArray
name|name
decl_stmt|;
name|name
operator|.
name|append
argument_list|(
literal|"size="
argument_list|)
operator|.
name|append
argument_list|(
name|QByteArray
operator|::
name|number
argument_list|(
name|sizes
index|[
name|s
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|name
operator|.
name|append
argument_list|(
literal|", flags="
argument_list|)
operator|.
name|append
argument_list|(
name|f
operator|==
literal|0
condition|?
literal|"internal"
else|:
literal|"default"
argument_list|)
expr_stmt|;
name|name
operator|.
name|append
argument_list|(
literal|", format="
argument_list|)
operator|.
name|append
argument_list|(
name|a
operator|==
literal|0
condition|?
literal|"RGB"
else|:
literal|"RGBA"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|name
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
name|sizes
index|[
name|s
index|]
operator|<<
name|flags
index|[
name|f
index|]
operator|<<
name|formats
index|[
name|a
index|]
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|textureUpload
name|void
name|OpenGLBench
operator|::
name|textureUpload
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|QPixmap
name|pixmap
argument_list|(
name|size
argument_list|,
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|format
operator|==
name|GL_RGB
condition|)
name|pixmap
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
else|else
name|pixmap
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|pb
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
name|QGLContext
modifier|*
name|context
init|=
cast|const_cast
argument_list|<
name|QGLContext
operator|*
argument_list|>
argument_list|(
name|QGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
decl_stmt|;
name|QTime
name|time
decl_stmt|;
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|context
operator|->
name|bindTexture
argument_list|(
name|pixmap
argument_list|,
name|GL_TEXTURE_2D
argument_list|,
name|format
argument_list|,
operator|(
name|QGLContext
operator|::
name|BindOptions
operator|)
name|flags
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|setBenchmarkResult
argument_list|(
name|time
operator|.
name|elapsed
argument_list|()
argument_list|,
name|QTest
operator|::
name|WalltimeMilliseconds
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|OpenGLBench
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
