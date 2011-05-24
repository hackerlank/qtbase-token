begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPDF_P_H
end_ifndef
begin_define
DECL|macro|QPDF_P_H
define|#
directive|define
name|QPDF_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|"QtGui/qmatrix.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstring.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvector.h"
end_include
begin_include
include|#
directive|include
file|"private/qstroker_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qfontengine_p.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qprinter.h"
end_include
begin_include
include|#
directive|include
file|"private/qfontsubset_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qpaintengine_alpha_p.h"
end_include
begin_include
include|#
directive|include
file|"qprintengine.h"
end_include
begin_include
include|#
directive|include
file|"qbuffer.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_function_decl
name|QT_BEGIN_NAMESPACE
DECL|macro|PPK_CupsOptions
define|#
directive|define
name|PPK_CupsOptions
value|QPrintEngine::PrintEnginePropertyKey(0xfe00)
DECL|macro|PPK_CupsPageRect
define|#
directive|define
name|PPK_CupsPageRect
value|QPrintEngine::PrintEnginePropertyKey(0xfe01)
DECL|macro|PPK_CupsPaperRect
define|#
directive|define
name|PPK_CupsPaperRect
value|QPrintEngine::PrintEnginePropertyKey(0xfe02)
DECL|macro|PPK_CupsStringPageSize
define|#
directive|define
name|PPK_CupsStringPageSize
value|QPrintEngine::PrintEnginePropertyKey(0xfe03)
specifier|const
name|char
modifier|*
name|qt_real_to_string
parameter_list|(
name|qreal
name|val
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|char
modifier|*
name|qt_int_to_string
parameter_list|(
name|int
name|val
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|namespace
name|QPdf
block|{
name|class
name|ByteStream
block|{
name|public
label|:
comment|// fileBacking means that ByteStream will buffer the contents on disk
comment|// if the size exceeds a certain threshold. In this case, if a byte
comment|// array was passed in, its contents may no longer correspond to the
comment|// ByteStream contents.
name|explicit
name|ByteStream
parameter_list|(
name|bool
name|fileBacking
init|=
name|false
parameter_list|)
function_decl|;
name|explicit
name|ByteStream
parameter_list|(
name|QByteArray
modifier|*
name|ba
parameter_list|,
name|bool
name|fileBacking
init|=
name|false
parameter_list|)
function_decl|;
operator|~
name|ByteStream
argument_list|()
expr_stmt|;
name|ByteStream
operator|&
name|operator
operator|<<
operator|(
name|char
name|chr
operator|)
expr_stmt|;
name|ByteStream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|char
operator|*
name|str
operator|)
expr_stmt|;
name|ByteStream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QByteArray
operator|&
name|str
operator|)
expr_stmt|;
name|ByteStream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|ByteStream
operator|&
name|src
operator|)
expr_stmt|;
name|ByteStream
operator|&
name|operator
operator|<<
operator|(
name|qreal
name|val
operator|)
expr_stmt|;
name|ByteStream
operator|&
name|operator
operator|<<
operator|(
name|int
name|val
operator|)
expr_stmt|;
name|ByteStream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QPointF
operator|&
name|p
operator|)
expr_stmt|;
comment|// Note that the stream may be invalidated by calls that insert data.
name|QIODevice
modifier|*
name|stream
parameter_list|()
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
specifier|static
specifier|inline
name|int
name|maxMemorySize
parameter_list|()
block|{
return|return
literal|100000000
return|;
block|}
specifier|static
specifier|inline
name|int
name|chunkSize
parameter_list|()
block|{
return|return
literal|10000000
return|;
block|}
name|protected
label|:
name|void
name|constructor_helper
parameter_list|(
name|QIODevice
modifier|*
name|dev
parameter_list|)
function_decl|;
name|void
name|constructor_helper
parameter_list|(
name|QByteArray
modifier|*
name|ba
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|prepareBuffer
parameter_list|()
function_decl|;
name|private
label|:
name|QIODevice
modifier|*
name|dev
decl_stmt|;
name|QByteArray
name|ba
decl_stmt|;
name|bool
name|fileBackingEnabled
decl_stmt|;
name|bool
name|fileBackingActive
decl_stmt|;
name|bool
name|handleDirty
decl_stmt|;
block|}
empty_stmt|;
enum|enum
name|PathFlags
block|{
name|ClipPath
block|,
name|FillPath
block|,
name|StrokePath
block|,
name|FillAndStrokePath
block|}
enum|;
name|QByteArray
name|generatePath
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|matrix
parameter_list|,
name|PathFlags
name|flags
parameter_list|)
function_decl|;
name|QByteArray
name|generateMatrix
parameter_list|(
specifier|const
name|QTransform
modifier|&
name|matrix
parameter_list|)
function_decl|;
name|QByteArray
name|generateDashes
parameter_list|(
specifier|const
name|QPen
modifier|&
name|pen
parameter_list|)
function_decl|;
name|QByteArray
name|patternForBrush
parameter_list|(
specifier|const
name|QBrush
modifier|&
name|b
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|USE_NATIVE_GRADIENTS
name|QByteArray
name|generateLinearGradientShader
parameter_list|(
specifier|const
name|QLinearGradient
modifier|*
name|lg
parameter_list|,
specifier|const
name|QPointF
modifier|*
name|page_rect
parameter_list|,
name|bool
name|alpha
init|=
name|false
parameter_list|)
function_decl|;
endif|#
directive|endif
struct|struct
name|Stroker
block|{
name|Stroker
argument_list|()
expr_stmt|;
name|void
name|setPen
parameter_list|(
specifier|const
name|QPen
modifier|&
name|pen
parameter_list|)
function_decl|;
name|void
name|strokePath
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|)
function_decl|;
name|ByteStream
modifier|*
name|stream
decl_stmt|;
name|bool
name|first
decl_stmt|;
name|QTransform
name|matrix
decl_stmt|;
name|bool
name|cosmeticPen
decl_stmt|;
name|private
label|:
name|QStroker
name|basicStroker
decl_stmt|;
name|QDashStroker
name|dashStroker
decl_stmt|;
name|QStrokerOps
modifier|*
name|stroker
decl_stmt|;
block|}
struct|;
name|QByteArray
name|ascii85Encode
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|input
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|toHex
parameter_list|(
name|ushort
name|u
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|toHex
parameter_list|(
name|uchar
name|u
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
function_decl|;
struct|struct
name|PaperSize
block|{
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|// in postscript points
block|}
struct|;
name|Q_GUI_EXPORT
name|PaperSize
name|paperSize
argument_list|(
name|QPrinter
operator|::
name|PaperSize
name|paperSize
argument_list|)
decl_stmt|;
name|Q_GUI_EXPORT
specifier|const
name|char
modifier|*
name|paperSizeToString
argument_list|(
name|QPrinter
operator|::
name|PaperSize
name|paperSize
argument_list|)
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|class
name|QPdfPage
range|:
name|public
name|QPdf
operator|::
name|ByteStream
block|{
name|public
operator|:
name|QPdfPage
argument_list|()
block|;
name|QVector
operator|<
name|uint
operator|>
name|images
block|;
name|QVector
operator|<
name|uint
operator|>
name|graphicStates
block|;
name|QVector
operator|<
name|uint
operator|>
name|patterns
block|;
name|QVector
operator|<
name|uint
operator|>
name|fonts
block|;
name|QVector
operator|<
name|uint
operator|>
name|annotations
block|;
name|void
name|streamImage
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|int object
argument_list|)
block|;
name|QSize
name|pageSize
block|;
name|private
operator|:
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPdfBaseEnginePrivate
name|class
name|QPdfBaseEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAlphaPaintEngine
name|class
name|QPdfBaseEngine
range|:
name|public
name|QAlphaPaintEngine
decl_stmt|,
name|public
name|QPrintEngine
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPdfBaseEngine
argument_list|)
name|public
label|:
name|QPdfBaseEngine
argument_list|(
argument|QPdfBaseEnginePrivate&d
argument_list|,
argument|PaintEngineFeatures f
argument_list|)
empty_stmt|;
operator|~
name|QPdfBaseEngine
argument_list|()
block|{}
comment|// reimplementations QPaintEngine
name|bool
name|begin
argument_list|(
name|QPaintDevice
operator|*
name|pdev
argument_list|)
expr_stmt|;
name|bool
name|end
parameter_list|()
function_decl|;
name|void
name|drawPoints
parameter_list|(
specifier|const
name|QPointF
modifier|*
name|points
parameter_list|,
name|int
name|pointCount
parameter_list|)
function_decl|;
name|void
name|drawLines
parameter_list|(
specifier|const
name|QLineF
modifier|*
name|lines
parameter_list|,
name|int
name|lineCount
parameter_list|)
function_decl|;
name|void
name|drawRects
parameter_list|(
specifier|const
name|QRectF
modifier|*
name|rects
parameter_list|,
name|int
name|rectCount
parameter_list|)
function_decl|;
name|void
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
function_decl|;
name|void
name|drawPath
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|)
function_decl|;
name|void
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
function_decl|;
name|void
name|updateState
parameter_list|(
specifier|const
name|QPaintEngineState
modifier|&
name|state
parameter_list|)
function_decl|;
name|int
name|metric
argument_list|(
name|QPaintDevice
operator|::
name|PaintDeviceMetric
name|metricType
argument_list|)
decl|const
decl_stmt|;
comment|// end reimplementations QPaintEngine
comment|// Printer stuff...
name|bool
name|newPage
parameter_list|()
function_decl|;
name|void
name|setProperty
parameter_list|(
name|PrintEnginePropertyKey
name|key
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
name|QVariant
name|property
argument_list|(
name|PrintEnginePropertyKey
name|key
argument_list|)
decl|const
decl_stmt|;
name|void
name|setPen
parameter_list|()
function_decl|;
name|virtual
name|void
name|setBrush
parameter_list|()
init|=
literal|0
function_decl|;
name|void
name|setupGraphicsState
argument_list|(
name|QPaintEngine
operator|::
name|DirtyFlags
name|flags
argument_list|)
decl_stmt|;
name|private
label|:
name|void
name|updateClipPath
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|path
argument_list|,
name|Qt
operator|::
name|ClipOperation
name|op
argument_list|)
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QPdfBaseEnginePrivate
range|:
name|public
name|QAlphaPaintEnginePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QPdfBaseEngine
argument_list|)
name|public
operator|:
name|QPdfBaseEnginePrivate
argument_list|(
argument|QPrinter::PrinterMode m
argument_list|)
block|;
operator|~
name|QPdfBaseEnginePrivate
argument_list|()
block|;
name|bool
name|openPrintDevice
argument_list|()
block|;
name|void
name|closePrintDevice
argument_list|()
block|;
name|virtual
name|void
name|drawTextItem
argument_list|(
specifier|const
name|QPointF
operator|&
name|p
argument_list|,
specifier|const
name|QTextItemInt
operator|&
name|ti
argument_list|)
block|;
specifier|inline
name|uint
name|requestObject
argument_list|()
block|{
return|return
name|currentObject
operator|++
return|;
block|}
name|QRect
name|paperRect
argument_list|()
specifier|const
block|;
name|QRect
name|pageRect
argument_list|()
specifier|const
block|;
name|bool
name|postscript
block|;
name|int
name|currentObject
block|;
name|QPdfPage
operator|*
name|currentPage
block|;
name|QPdf
operator|::
name|Stroker
name|stroker
block|;
name|QPointF
name|brushOrigin
block|;
name|QBrush
name|brush
block|;
name|QPen
name|pen
block|;
name|QList
operator|<
name|QPainterPath
operator|>
name|clips
block|;
name|bool
name|clipEnabled
block|;
name|bool
name|allClipped
block|;
name|bool
name|hasPen
block|;
name|bool
name|hasBrush
block|;
name|bool
name|simplePen
block|;
name|qreal
name|opacity
block|;
name|bool
name|useAlphaEngine
block|;
name|QHash
operator|<
name|QFontEngine
operator|::
name|FaceId
block|,
name|QFontSubset
operator|*
operator|>
name|fonts
block|;
name|QPaintDevice
operator|*
name|pdev
block|;
comment|// the device the output is in the end streamed to.
name|QIODevice
operator|*
name|outDevice
block|;
name|int
name|fd
block|;
comment|// printer options
name|QString
name|outputFileName
block|;
name|QString
name|printerName
block|;
name|QString
name|printProgram
block|;
name|QString
name|selectionOption
block|;
name|QString
name|title
block|;
name|QString
name|creator
block|;
name|QPrinter
operator|::
name|DuplexMode
name|duplex
block|;
name|bool
name|collate
block|;
name|bool
name|fullPage
block|;
name|bool
name|embedFonts
block|;
name|int
name|copies
block|;
name|int
name|resolution
block|;
name|QPrinter
operator|::
name|PageOrder
name|pageOrder
block|;
name|QPrinter
operator|::
name|Orientation
name|orientation
block|;
name|QPrinter
operator|::
name|PaperSize
name|paperSize
block|;
name|QPrinter
operator|::
name|ColorMode
name|colorMode
block|;
name|QPrinter
operator|::
name|PaperSource
name|paperSource
block|;
name|QStringList
name|cupsOptions
block|;
name|QRect
name|cupsPaperRect
block|;
name|QRect
name|cupsPageRect
block|;
name|QString
name|cupsStringPageSize
block|;
name|QSizeF
name|customPaperSize
block|;
comment|// in postscript points
name|bool
name|hasCustomPageMargins
block|;
name|qreal
name|leftMargin
block|,
name|topMargin
block|,
name|rightMargin
block|,
name|bottomMargin
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_CUPS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_LIBRARY
argument_list|)
name|QString
name|cupsTempFile
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPDF_P_H
end_comment
end_unit
