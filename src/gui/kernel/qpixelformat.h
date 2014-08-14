begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPIXELFORMAT_H
end_ifndef
begin_define
DECL|macro|QPIXELFORMAT_H
define|#
directive|define
name|QPIXELFORMAT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QPixelFormat
block|{
comment|// QPixelFormat basically is a glorified quint64, split into several fields.
comment|// We could use bit-fields, but GCC at least generates horrible, horrible code for them,
comment|// so we do the bit-twiddling ourselves.
enum|enum
name|FieldWidth
block|{
name|ModelFieldWidth
init|=
literal|4
block|,
name|FirstFieldWidth
init|=
literal|6
block|,
name|SecondFieldWidth
init|=
name|FirstFieldWidth
block|,
name|ThirdFieldWidth
init|=
name|FirstFieldWidth
block|,
name|FourthFieldWidth
init|=
name|FirstFieldWidth
block|,
name|FifthFieldWidth
init|=
name|FirstFieldWidth
block|,
name|AlphaFieldWidth
init|=
name|FirstFieldWidth
block|,
name|AlphaUsageFieldWidth
init|=
literal|1
block|,
name|AlphaPositionFieldWidth
init|=
literal|1
block|,
name|PremulFieldWidth
init|=
literal|1
block|,
name|TypeInterpretationFieldWidth
init|=
literal|4
block|,
name|ByteOrderFieldWidth
init|=
literal|2
block|,
name|SubEnumFieldWidth
init|=
literal|6
block|,
name|UnusedFieldWidth
init|=
literal|9
block|,
name|TotalFieldWidthByWidths
init|=
name|ModelFieldWidth
operator|+
name|FirstFieldWidth
operator|+
name|SecondFieldWidth
operator|+
name|ThirdFieldWidth
operator|+
name|FourthFieldWidth
operator|+
name|FifthFieldWidth
operator|+
name|AlphaFieldWidth
operator|+
name|AlphaUsageFieldWidth
operator|+
name|AlphaPositionFieldWidth
operator|+
name|PremulFieldWidth
operator|+
name|TypeInterpretationFieldWidth
operator|+
name|ByteOrderFieldWidth
operator|+
name|SubEnumFieldWidth
operator|+
name|UnusedFieldWidth
block|}
enum|;
enum|enum
name|Field
block|{
name|ModelField
init|=
literal|0
block|,
comment|// work around bug in old clang versions: when building webkit
comment|// with XCode 4.6 and older this fails compilation, thus cast to int
name|FirstField
init|=
name|ModelField
operator|+
name|int
argument_list|(
name|ModelFieldWidth
argument_list|)
block|,
name|SecondField
init|=
name|FirstField
operator|+
name|FirstFieldWidth
block|,
name|ThirdField
init|=
name|SecondField
operator|+
name|SecondFieldWidth
block|,
name|FourthField
init|=
name|ThirdField
operator|+
name|ThirdFieldWidth
block|,
name|FifthField
init|=
name|FourthField
operator|+
name|FourthFieldWidth
block|,
name|AlphaField
init|=
name|FifthField
operator|+
name|FifthFieldWidth
block|,
name|AlphaUsageField
init|=
name|AlphaField
operator|+
name|AlphaFieldWidth
block|,
name|AlphaPositionField
init|=
name|AlphaUsageField
operator|+
name|AlphaUsageFieldWidth
block|,
name|PremulField
init|=
name|AlphaPositionField
operator|+
name|AlphaPositionFieldWidth
block|,
name|TypeInterpretationField
init|=
name|PremulField
operator|+
name|PremulFieldWidth
block|,
name|ByteOrderField
init|=
name|TypeInterpretationField
operator|+
name|TypeInterpretationFieldWidth
block|,
name|SubEnumField
init|=
name|ByteOrderField
operator|+
name|ByteOrderFieldWidth
block|,
name|UnusedField
init|=
name|SubEnumField
operator|+
name|SubEnumFieldWidth
block|,
name|TotalFieldWidthByOffsets
init|=
name|UnusedField
operator|+
name|UnusedFieldWidth
block|}
enum|;
name|Q_STATIC_ASSERT
argument_list|(
name|uint
argument_list|(
name|TotalFieldWidthByWidths
argument_list|)
operator|==
name|uint
argument_list|(
name|TotalFieldWidthByOffsets
argument_list|)
argument_list|)
expr_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
name|uint
argument_list|(
name|TotalFieldWidthByWidths
argument_list|)
operator|==
literal|8
operator|*
sizeof|sizeof
argument_list|(
name|quint64
argument_list|)
argument_list|)
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|uchar
name|get
argument_list|(
name|Field
name|offset
argument_list|,
name|FieldWidth
name|width
argument_list|)
decl|const
name|Q_DECL_NOTHROW
block|{
return|return
name|uchar
argument_list|(
operator|(
name|data
operator|>>
name|uint
argument_list|(
name|offset
argument_list|)
operator|)
operator|&
operator|(
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|uint
argument_list|(
name|width
argument_list|)
operator|)
operator|-
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|static
specifier|inline
name|quint64
name|set
parameter_list|(
name|Field
name|offset
parameter_list|,
name|FieldWidth
name|width
parameter_list|,
name|uchar
name|value
parameter_list|)
block|{
return|return
operator|(
name|quint64
argument_list|(
name|value
argument_list|)
operator|&
operator|(
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|uint
argument_list|(
name|width
argument_list|)
operator|)
operator|-
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|)
operator|)
operator|<<
name|uint
argument_list|(
name|offset
argument_list|)
return|;
block|}
name|public
label|:
enum|enum
name|ColorModel
block|{
name|RGB
block|,
name|BGR
block|,
name|Indexed
block|,
name|Grayscale
block|,
name|CMYK
block|,
name|HSL
block|,
name|HSV
block|,
name|YUV
block|}
enum|;
enum|enum
name|AlphaUsage
block|{
name|UsesAlpha
block|,
name|IgnoresAlpha
block|}
enum|;
enum|enum
name|AlphaPosition
block|{
name|AtBeginning
block|,
name|AtEnd
block|}
enum|;
enum|enum
name|AlphaPremultiplied
block|{
name|NotPremultiplied
block|,
name|Premultiplied
block|}
enum|;
enum|enum
name|TypeInterpretation
block|{
name|UnsignedInteger
block|,
name|UnsignedShort
block|,
name|UnsignedByte
block|,
name|FloatingPoint
block|}
enum|;
enum|enum
name|YUVLayout
block|{
name|YUV444
block|,
name|YUV422
block|,
name|YUV411
block|,
name|YUV420P
block|,
name|YUV420SP
block|,
name|YV12
block|,
name|UYVY
block|,
name|YUYV
block|,
name|NV12
block|,
name|NV21
block|,
name|IMC1
block|,
name|IMC2
block|,
name|IMC3
block|,
name|IMC4
block|,
name|Y8
block|,
name|Y16
block|}
enum|;
enum|enum
name|ByteOrder
block|{
name|LittleEndian
block|,
name|BigEndian
block|,
name|CurrentSystemEndian
block|}
enum|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPixelFormat
argument_list|()
name|Q_DECL_NOTHROW
operator|:
name|data
argument_list|(
literal|0
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPixelFormat
argument_list|(
argument|ColorModel colorModel
argument_list|,
argument|uchar firstSize
argument_list|,
argument|uchar secondSize
argument_list|,
argument|uchar thirdSize
argument_list|,
argument|uchar fourthSize
argument_list|,
argument|uchar fifthSize
argument_list|,
argument|uchar alphaSize
argument_list|,
argument|AlphaUsage alphaUsage
argument_list|,
argument|AlphaPosition alphaPosition
argument_list|,
argument|AlphaPremultiplied premultiplied
argument_list|,
argument|TypeInterpretation typeInterpretation
argument_list|,
argument|ByteOrder byteOrder = CurrentSystemEndian
argument_list|,
argument|uchar subEnum =
literal|0
argument_list|)
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|ColorModel
name|colorModel
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|ColorModel
argument_list|(
name|get
argument_list|(
name|ModelField
argument_list|,
name|ModelFieldWidth
argument_list|)
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|uchar
name|channelCount
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
operator|(
name|get
argument_list|(
name|FirstField
argument_list|,
name|FirstFieldWidth
argument_list|)
operator|>
literal|0
operator|)
operator|+
operator|(
name|get
argument_list|(
name|SecondField
argument_list|,
name|SecondFieldWidth
argument_list|)
operator|>
literal|0
operator|)
operator|+
operator|(
name|get
argument_list|(
name|ThirdField
argument_list|,
name|ThirdFieldWidth
argument_list|)
operator|>
literal|0
operator|)
operator|+
operator|(
name|get
argument_list|(
name|FourthField
argument_list|,
name|FourthFieldWidth
argument_list|)
operator|>
literal|0
operator|)
operator|+
operator|(
name|get
argument_list|(
name|FifthField
argument_list|,
name|FifthFieldWidth
argument_list|)
operator|>
literal|0
operator|)
operator|+
operator|(
name|get
argument_list|(
name|AlphaField
argument_list|,
name|AlphaFieldWidth
argument_list|)
operator|>
literal|0
operator|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|uchar
name|redSize
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|get
argument_list|(
name|FirstField
argument_list|,
name|FirstFieldWidth
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|uchar
name|greenSize
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|get
argument_list|(
name|SecondField
argument_list|,
name|SecondFieldWidth
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|uchar
name|blueSize
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|get
argument_list|(
name|ThirdField
argument_list|,
name|ThirdFieldWidth
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|uchar
name|cyanSize
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|get
argument_list|(
name|FirstField
argument_list|,
name|FirstFieldWidth
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|uchar
name|magentaSize
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|get
argument_list|(
name|SecondField
argument_list|,
name|SecondFieldWidth
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|uchar
name|yellowSize
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|get
argument_list|(
name|ThirdField
argument_list|,
name|ThirdFieldWidth
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|uchar
name|blackSize
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|get
argument_list|(
name|FourthField
argument_list|,
name|FourthFieldWidth
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|uchar
name|hueSize
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|get
argument_list|(
name|FirstField
argument_list|,
name|FirstFieldWidth
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|uchar
name|saturationSize
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|get
argument_list|(
name|SecondField
argument_list|,
name|SecondFieldWidth
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|uchar
name|lightnessSize
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|get
argument_list|(
name|ThirdField
argument_list|,
name|ThirdFieldWidth
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|uchar
name|brightnessSize
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|get
argument_list|(
name|ThirdField
argument_list|,
name|ThirdFieldWidth
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|uchar
name|alphaSize
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|get
argument_list|(
name|AlphaField
argument_list|,
name|AlphaFieldWidth
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|uchar
name|bitsPerPixel
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|get
argument_list|(
name|FirstField
argument_list|,
name|FirstFieldWidth
argument_list|)
operator|+
name|get
argument_list|(
name|SecondField
argument_list|,
name|SecondFieldWidth
argument_list|)
operator|+
name|get
argument_list|(
name|ThirdField
argument_list|,
name|ThirdFieldWidth
argument_list|)
operator|+
name|get
argument_list|(
name|FourthField
argument_list|,
name|FourthFieldWidth
argument_list|)
operator|+
name|get
argument_list|(
name|FifthField
argument_list|,
name|FifthFieldWidth
argument_list|)
operator|+
name|get
argument_list|(
name|AlphaField
argument_list|,
name|AlphaFieldWidth
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|AlphaUsage
name|alphaUsage
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|AlphaUsage
argument_list|(
name|get
argument_list|(
name|AlphaUsageField
argument_list|,
name|AlphaUsageFieldWidth
argument_list|)
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|AlphaPosition
name|alphaPosition
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|AlphaPosition
argument_list|(
name|get
argument_list|(
name|AlphaPositionField
argument_list|,
name|AlphaPositionFieldWidth
argument_list|)
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|AlphaPremultiplied
name|premultiplied
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|AlphaPremultiplied
argument_list|(
name|get
argument_list|(
name|PremulField
argument_list|,
name|PremulFieldWidth
argument_list|)
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|TypeInterpretation
name|typeInterpretation
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|TypeInterpretation
argument_list|(
name|get
argument_list|(
name|TypeInterpretationField
argument_list|,
name|TypeInterpretationFieldWidth
argument_list|)
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|ByteOrder
name|byteOrder
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|ByteOrder
argument_list|(
name|get
argument_list|(
name|ByteOrderField
argument_list|,
name|ByteOrderFieldWidth
argument_list|)
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|YUVLayout
name|yuvLayout
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|YUVLayout
argument_list|(
name|get
argument_list|(
name|SubEnumField
argument_list|,
name|SubEnumFieldWidth
argument_list|)
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|uchar
name|subEnum
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|get
argument_list|(
name|SubEnumField
argument_list|,
name|SubEnumFieldWidth
argument_list|)
return|;
block|}
name|private
label|:
name|Q_DECL_CONSTEXPR
specifier|static
specifier|inline
name|ByteOrder
name|resolveByteOrder
parameter_list|(
name|ByteOrder
name|bo
parameter_list|)
block|{
return|return
name|bo
operator|==
name|CurrentSystemEndian
condition|?
name|Q_BYTE_ORDER
operator|==
name|Q_LITTLE_ENDIAN
condition|?
name|LittleEndian
else|:
name|BigEndian
else|:
name|bo
return|;
block|}
name|private
label|:
name|quint64
name|data
decl_stmt|;
name|friend
name|Q_DECL_CONST_FUNCTION
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|QPixelFormat
name|fmt1
operator|,
name|QPixelFormat
name|fmt2
operator|)
block|{
return|return
name|fmt1
operator|.
name|data
operator|==
name|fmt2
operator|.
name|data
return|;
block|}
name|friend
name|Q_DECL_CONST_FUNCTION
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|QPixelFormat
name|fmt1
operator|,
name|QPixelFormat
name|fmt2
operator|)
block|{
return|return
operator|!
operator|(
name|fmt1
operator|==
name|fmt2
operator|)
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|variable|sizeof
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|QPixelFormat
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|quint64
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QPixelFormat
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|namespace
name|QtPrivate
block|{
name|QPixelFormat
name|Q_GUI_EXPORT
name|QPixelFormat_createYUV
argument_list|(
name|QPixelFormat
operator|::
name|YUVLayout
name|yuvLayout
argument_list|,
name|uchar
name|alphaSize
argument_list|,
name|QPixelFormat
operator|::
name|AlphaUsage
name|alphaUsage
argument_list|,
name|QPixelFormat
operator|::
name|AlphaPosition
name|alphaPosition
argument_list|,
name|QPixelFormat
operator|::
name|AlphaPremultiplied
name|premultiplied
argument_list|,
name|QPixelFormat
operator|::
name|TypeInterpretation
name|typeInterpretation
argument_list|,
name|QPixelFormat
operator|::
name|ByteOrder
name|byteOrder
argument_list|)
decl_stmt|;
block|}
end_decl_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
name|QPixelFormat
operator|::
name|QPixelFormat
argument_list|(
argument|ColorModel mdl
argument_list|,
argument|uchar firstSize
argument_list|,
argument|uchar secondSize
argument_list|,
argument|uchar thirdSize
argument_list|,
argument|uchar fourthSize
argument_list|,
argument|uchar fifthSize
argument_list|,
argument|uchar alfa
argument_list|,
argument|AlphaUsage usage
argument_list|,
argument|AlphaPosition position
argument_list|,
argument|AlphaPremultiplied premult
argument_list|,
argument|TypeInterpretation typeInterp
argument_list|,
argument|ByteOrder b_order
argument_list|,
argument|uchar s_enum
argument_list|)
name|Q_DECL_NOTHROW
operator|:
name|data
argument_list|(
argument|set(ModelField, ModelFieldWidth, uchar(mdl)) |            set(FirstField, FirstFieldWidth, firstSize) |            set(SecondField, SecondFieldWidth, secondSize) |            set(ThirdField, ThirdFieldWidth, thirdSize) |            set(FourthField, FourthFieldWidth, fourthSize) |            set(FifthField, FifthFieldWidth, fifthSize) |            set(AlphaField, AlphaFieldWidth, alfa) |            set(AlphaUsageField, AlphaUsageFieldWidth, uchar(usage)) |            set(AlphaPositionField, AlphaPositionFieldWidth, uchar(position)) |            set(PremulField, PremulFieldWidth, uchar(premult)) |            set(TypeInterpretationField, TypeInterpretationFieldWidth, uchar(typeInterp)) |            set(ByteOrderField, ByteOrderFieldWidth, uchar(resolveByteOrder(b_order))) |            set(SubEnumField, SubEnumFieldWidth, s_enum) |            set(UnusedField, UnusedFieldWidth,
literal|0
argument|)
argument_list|)
block|{ }
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPixelFormat
name|qPixelFormatRgba
argument_list|(
argument|uchar red
argument_list|,
argument|uchar green
argument_list|,
argument|uchar blue
argument_list|,
argument|uchar alfa
argument_list|,
argument|QPixelFormat::AlphaUsage usage
argument_list|,
argument|QPixelFormat::AlphaPosition position
argument_list|,
argument|QPixelFormat::AlphaPremultiplied pmul=QPixelFormat::NotPremultiplied
argument_list|,
argument|QPixelFormat::TypeInterpretation typeInt=QPixelFormat::UnsignedInteger
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|QPixelFormat
argument_list|(
name|QPixelFormat
operator|::
name|RGB
argument_list|,
name|red
argument_list|,
name|green
argument_list|,
name|blue
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|alfa
argument_list|,
name|usage
argument_list|,
name|position
argument_list|,
name|pmul
argument_list|,
name|typeInt
argument_list|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPixelFormat
name|qPixelFormatGrayscale
argument_list|(
name|uchar
name|channelSize
argument_list|,
name|QPixelFormat
operator|::
name|TypeInterpretation
name|typeInt
operator|=
name|QPixelFormat
operator|::
name|UnsignedInteger
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|QPixelFormat
argument_list|(
name|QPixelFormat
operator|::
name|Grayscale
argument_list|,
name|channelSize
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|QPixelFormat
operator|::
name|IgnoresAlpha
argument_list|,
name|QPixelFormat
operator|::
name|AtBeginning
argument_list|,
name|QPixelFormat
operator|::
name|NotPremultiplied
argument_list|,
name|typeInt
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPixelFormat
name|qPixelFormatCmyk
argument_list|(
name|uchar
name|channelSize
argument_list|,
name|uchar
name|alfa
operator|=
literal|0
argument_list|,
name|QPixelFormat
operator|::
name|AlphaUsage
name|usage
operator|=
name|QPixelFormat
operator|::
name|IgnoresAlpha
argument_list|,
name|QPixelFormat
operator|::
name|AlphaPosition
name|position
operator|=
name|QPixelFormat
operator|::
name|AtBeginning
argument_list|,
name|QPixelFormat
operator|::
name|TypeInterpretation
name|typeInt
operator|=
name|QPixelFormat
operator|::
name|UnsignedInteger
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|QPixelFormat
argument_list|(
name|QPixelFormat
operator|::
name|CMYK
argument_list|,
name|channelSize
argument_list|,
name|channelSize
argument_list|,
name|channelSize
argument_list|,
name|channelSize
argument_list|,
literal|0
argument_list|,
name|alfa
argument_list|,
name|usage
argument_list|,
name|position
argument_list|,
name|QPixelFormat
operator|::
name|NotPremultiplied
argument_list|,
name|typeInt
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPixelFormat
name|qPixelFormatHsl
argument_list|(
name|uchar
name|channelSize
argument_list|,
name|uchar
name|alfa
operator|=
literal|0
argument_list|,
name|QPixelFormat
operator|::
name|AlphaUsage
name|usage
operator|=
name|QPixelFormat
operator|::
name|IgnoresAlpha
argument_list|,
name|QPixelFormat
operator|::
name|AlphaPosition
name|position
operator|=
name|QPixelFormat
operator|::
name|AtBeginning
argument_list|,
name|QPixelFormat
operator|::
name|TypeInterpretation
name|typeInt
operator|=
name|QPixelFormat
operator|::
name|FloatingPoint
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|QPixelFormat
argument_list|(
name|QPixelFormat
operator|::
name|HSL
argument_list|,
name|channelSize
argument_list|,
name|channelSize
argument_list|,
name|channelSize
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|alfa
argument_list|,
name|usage
argument_list|,
name|position
argument_list|,
name|QPixelFormat
operator|::
name|NotPremultiplied
argument_list|,
name|typeInt
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPixelFormat
name|qPixelFormatHsv
argument_list|(
name|uchar
name|channelSize
argument_list|,
name|uchar
name|alfa
operator|=
literal|0
argument_list|,
name|QPixelFormat
operator|::
name|AlphaUsage
name|usage
operator|=
name|QPixelFormat
operator|::
name|IgnoresAlpha
argument_list|,
name|QPixelFormat
operator|::
name|AlphaPosition
name|position
operator|=
name|QPixelFormat
operator|::
name|AtBeginning
argument_list|,
name|QPixelFormat
operator|::
name|TypeInterpretation
name|typeInt
operator|=
name|QPixelFormat
operator|::
name|FloatingPoint
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|QPixelFormat
argument_list|(
name|QPixelFormat
operator|::
name|HSV
argument_list|,
name|channelSize
argument_list|,
name|channelSize
argument_list|,
name|channelSize
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|alfa
argument_list|,
name|usage
argument_list|,
name|position
argument_list|,
name|QPixelFormat
operator|::
name|NotPremultiplied
argument_list|,
name|typeInt
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
DECL|function|qPixelFormatYuv
specifier|inline
name|QPixelFormat
name|qPixelFormatYuv
argument_list|(
name|QPixelFormat
operator|::
name|YUVLayout
name|layout
argument_list|,
name|uchar
name|alfa
operator|=
literal|0
argument_list|,
name|QPixelFormat
operator|::
name|AlphaUsage
name|usage
operator|=
name|QPixelFormat
operator|::
name|IgnoresAlpha
argument_list|,
name|QPixelFormat
operator|::
name|AlphaPosition
name|position
operator|=
name|QPixelFormat
operator|::
name|AtBeginning
argument_list|,
name|QPixelFormat
operator|::
name|AlphaPremultiplied
name|p_mul
operator|=
name|QPixelFormat
operator|::
name|NotPremultiplied
argument_list|,
name|QPixelFormat
operator|::
name|TypeInterpretation
name|typeInt
operator|=
name|QPixelFormat
operator|::
name|UnsignedByte
argument_list|,
name|QPixelFormat
operator|::
name|ByteOrder
name|b_order
operator|=
name|QPixelFormat
operator|::
name|LittleEndian
argument_list|)
block|{
return|return
name|QtPrivate
operator|::
name|QPixelFormat_createYUV
argument_list|(
name|layout
argument_list|,
name|alfa
argument_list|,
name|usage
argument_list|,
name|position
argument_list|,
name|p_mul
argument_list|,
name|typeInt
argument_list|,
name|b_order
argument_list|)
return|;
block|}
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QPIXELFORMAT_H
end_comment
end_unit
