begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSFONTENGINEDIRECTWRITE_H
end_ifndef
begin_define
DECL|macro|QWINDOWSFONTENGINEDIRECTWRITE_H
define|#
directive|define
name|QWINDOWSFONTENGINEDIRECTWRITE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DIRECTWRITE
end_ifndef
begin_include
include|#
directive|include
file|<QtGui/private/qfontengine_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedPointer>
end_include
begin_struct_decl
struct_decl|struct
name|IDWriteFont
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|IDWriteFontFace
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|IDWriteFactory
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|IDWriteBitmapRenderTarget
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|IDWriteGdiInterop
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|IDWriteGlyphRunAnalysis
struct_decl|;
end_struct_decl
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindowsFontEngineData
name|class
name|QWindowsFontEngineData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsFontEngineDirectWrite
range|:
name|public
name|QFontEngine
block|{
name|public
operator|:
name|explicit
name|QWindowsFontEngineDirectWrite
argument_list|(
argument|IDWriteFontFace *directWriteFontFace
argument_list|,
argument|qreal pixelSize
argument_list|,
argument|const QSharedPointer<QWindowsFontEngineData>&d
argument_list|)
block|;
operator|~
name|QWindowsFontEngineDirectWrite
argument_list|()
block|;
name|void
name|initFontInfo
argument_list|(
argument|const QFontDef&request
argument_list|,
argument|int dpi
argument_list|)
block|;
name|QFixed
name|lineThickness
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QFixed
name|underlinePosition
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|getSfntTableData
argument_list|(
argument|uint tag
argument_list|,
argument|uchar *buffer
argument_list|,
argument|uint *length
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QFixed
name|emSquareSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|glyph_t
name|glyphIndex
argument_list|(
argument|uint ucs4
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|stringToCMap
argument_list|(
argument|const QChar *str
argument_list|,
argument|int len
argument_list|,
argument|QGlyphLayout *glyphs
argument_list|,
argument|int *nglyphs
argument_list|,
argument|ShaperFlags flags
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|recalcAdvances
argument_list|(
argument|QGlyphLayout *glyphs
argument_list|,
argument|ShaperFlags
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|addGlyphsToPath
argument_list|(
argument|glyph_t *glyphs
argument_list|,
argument|QFixedPoint *positions
argument_list|,
argument|int nglyphs
argument_list|,
argument|QPainterPath *path
argument_list|,
argument|QTextItem::RenderFlags flags
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|glyph_metrics_t
name|boundingBox
argument_list|(
argument|const QGlyphLayout&glyphs
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|glyph_metrics_t
name|boundingBox
argument_list|(
argument|glyph_t g
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|glyph_metrics_t
name|alphaMapBoundingBox
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|QFixed
argument_list|,
argument|const QTransform&matrix
argument_list|,
argument|GlyphFormat
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QFixed
name|ascent
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QFixed
name|descent
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QFixed
name|leading
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QFixed
name|xHeight
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|qreal
name|maxCharWidth
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|supportsSubPixelPositions
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QImage
name|alphaMapForGlyph
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|QFixed subPixelPosition
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QImage
name|alphaMapForGlyph
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|QFixed subPixelPosition
argument_list|,
argument|const QTransform&t
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QImage
name|alphaRGBMapForGlyph
argument_list|(
argument|glyph_t t
argument_list|,
argument|QFixed subPixelPosition
argument_list|,
argument|const QTransform&xform
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QImage
name|bitmapForGlyph
argument_list|(
argument|glyph_t
argument_list|,
argument|QFixed subPixelPosition
argument_list|,
argument|const QTransform&t
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QFontEngine
operator|*
name|cloneWithSize
argument_list|(
argument|qreal pixelSize
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
specifier|const
name|QSharedPointer
operator|<
name|QWindowsFontEngineData
operator|>
operator|&
name|fontEngineData
argument_list|()
specifier|const
block|{
return|return
name|m_fontEngineData
return|;
block|}
specifier|static
name|QString
name|fontNameSubstitute
argument_list|(
specifier|const
name|QString
operator|&
name|familyName
argument_list|)
block|;
name|IDWriteFontFace
operator|*
name|directWriteFontFace
argument_list|()
specifier|const
block|{
return|return
name|m_directWriteFontFace
return|;
block|}
name|private
operator|:
name|QImage
name|imageForGlyph
argument_list|(
argument|glyph_t t
argument_list|,
argument|QFixed subPixelPosition
argument_list|,
argument|int margin
argument_list|,
argument|const QTransform&xform
argument_list|)
block|;
name|void
name|collectMetrics
argument_list|()
block|;
name|void
name|renderGlyphRun
argument_list|(
argument|QImage *destination
argument_list|,
argument|float r
argument_list|,
argument|float g
argument_list|,
argument|float b
argument_list|,
argument|float a
argument_list|,
argument|IDWriteGlyphRunAnalysis *glyphAnalysis
argument_list|,
argument|const QRect&boundingRect
argument_list|)
block|;
specifier|const
name|QSharedPointer
operator|<
name|QWindowsFontEngineData
operator|>
name|m_fontEngineData
block|;
name|IDWriteFontFace
operator|*
name|m_directWriteFontFace
block|;
name|IDWriteBitmapRenderTarget
operator|*
name|m_directWriteBitmapRenderTarget
block|;
name|QFixed
name|m_lineThickness
block|;
name|QFixed
name|m_underlinePosition
block|;
name|int
name|m_unitsPerEm
block|;
name|QFixed
name|m_ascent
block|;
name|QFixed
name|m_descent
block|;
name|QFixed
name|m_xHeight
block|;
name|QFixed
name|m_lineGap
block|;
name|FaceId
name|m_faceId
block|; }
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
comment|// QT_NO_DIRECTWRITE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSFONTENGINEDIRECTWRITE_H
end_comment
end_unit
