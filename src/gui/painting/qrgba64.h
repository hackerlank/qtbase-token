begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QRGBA64_H
end_ifndef
begin_define
DECL|macro|QRGBA64_H
define|#
directive|define
name|QRGBA64_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qprocessordetection.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QRgba64
block|{
name|quint64
name|rgba
decl_stmt|;
comment|// Make sure that the representation always has the order: red green blue alpha, independent
comment|// of byte order. This way, vector operations that assume 4 16-bit values see the correct ones.
enum|enum
block|{
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_BIG_ENDIAN
name|RedShift
init|=
literal|48
block|,
name|GreenShift
init|=
literal|32
block|,
name|BlueShift
init|=
literal|16
block|,
name|AlphaShift
init|=
literal|0
else|#
directive|else
comment|// little endian:
name|RedShift
operator|=
literal|0
block|,
name|GreenShift
init|=
literal|16
block|,
name|BlueShift
init|=
literal|32
block|,
name|AlphaShift
init|=
literal|48
endif|#
directive|endif
block|}
enum|;
comment|// No constructors are allowed in C++98, since this needs to be usable in a union.
comment|// We however require one for constexprs in C++11/C++14
ifdef|#
directive|ifdef
name|Q_COMPILER_CONSTEXPR
name|explicit
name|Q_ALWAYS_INLINE
name|Q_DECL_CONSTEXPR
name|QRgba64
argument_list|(
argument|quint64 c
argument_list|)
block|:
name|rgba
argument_list|(
argument|c
argument_list|)
block|{ }
endif|#
directive|endif
name|public
label|:
ifdef|#
directive|ifdef
name|Q_COMPILER_CONSTEXPR
name|Q_ALWAYS_INLINE
name|Q_DECL_CONSTEXPR
name|QRgba64
argument_list|()
operator|:
name|rgba
argument_list|(
literal|0
argument_list|)
block|{ }
endif|#
directive|endif
name|Q_DECL_CONSTEXPR
specifier|static
name|QRgba64
name|fromRgba64
argument_list|(
argument|quint64 c
argument_list|)
block|{
ifdef|#
directive|ifdef
name|Q_COMPILER_CONSTEXPR
return|return
name|QRgba64
argument_list|(
name|c
argument_list|)
return|;
else|#
directive|else
name|QRgba64
name|rgba64
expr_stmt|;
name|rgba64
operator|.
name|rgba
operator|=
name|c
expr_stmt|;
return|return
name|rgba64
return|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_function
name|Q_DECL_CONSTEXPR
specifier|static
name|QRgba64
name|fromRgba64
parameter_list|(
name|quint16
name|red
parameter_list|,
name|quint16
name|green
parameter_list|,
name|quint16
name|blue
parameter_list|,
name|quint16
name|alpha
parameter_list|)
block|{
return|return
name|fromRgba64
argument_list|(
name|quint64
argument_list|(
name|red
argument_list|)
operator|<<
name|RedShift
operator||
name|quint64
argument_list|(
name|green
argument_list|)
operator|<<
name|GreenShift
operator||
name|quint64
argument_list|(
name|blue
argument_list|)
operator|<<
name|BlueShift
operator||
name|quint64
argument_list|(
name|alpha
argument_list|)
operator|<<
name|AlphaShift
argument_list|)
return|;
block|}
end_function
begin_function
name|Q_DECL_RELAXED_CONSTEXPR
specifier|static
name|QRgba64
name|fromRgba
parameter_list|(
name|quint8
name|red
parameter_list|,
name|quint8
name|green
parameter_list|,
name|quint8
name|blue
parameter_list|,
name|quint8
name|alpha
parameter_list|)
block|{
name|QRgba64
name|rgb64
init|=
name|fromRgba64
argument_list|(
name|red
argument_list|,
name|green
argument_list|,
name|blue
argument_list|,
name|alpha
argument_list|)
decl_stmt|;
comment|// Expand the range so that 0x00 maps to 0x0000 and 0xff maps to 0xffff.
name|rgb64
operator|.
name|rgba
operator||=
name|rgb64
operator|.
name|rgba
operator|<<
literal|8
expr_stmt|;
return|return
name|rgb64
return|;
block|}
end_function
begin_function
name|Q_DECL_RELAXED_CONSTEXPR
specifier|static
name|QRgba64
name|fromArgb32
parameter_list|(
name|uint
name|rgb
parameter_list|)
block|{
return|return
name|fromRgba
argument_list|(
name|quint8
argument_list|(
name|rgb
operator|>>
literal|16
argument_list|)
argument_list|,
name|quint8
argument_list|(
name|rgb
operator|>>
literal|8
argument_list|)
argument_list|,
name|quint8
argument_list|(
name|rgb
argument_list|)
argument_list|,
name|quint8
argument_list|(
name|rgb
operator|>>
literal|24
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
name|Q_DECL_CONSTEXPR
name|bool
name|isOpaque
argument_list|()
specifier|const
block|{
return|return
operator|(
name|rgba
operator|&
name|alphaMask
argument_list|()
operator|)
operator|==
name|alphaMask
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
name|bool
name|isTransparent
argument_list|()
specifier|const
block|{
return|return
operator|(
name|rgba
operator|&
name|alphaMask
argument_list|()
operator|)
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
name|quint16
name|red
argument_list|()
specifier|const
block|{
return|return
name|quint16
argument_list|(
name|rgba
operator|>>
name|RedShift
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
name|quint16
name|green
argument_list|()
specifier|const
block|{
return|return
name|quint16
argument_list|(
name|rgba
operator|>>
name|GreenShift
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
name|quint16
name|blue
argument_list|()
specifier|const
block|{
return|return
name|quint16
argument_list|(
name|rgba
operator|>>
name|BlueShift
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
name|quint16
name|alpha
argument_list|()
specifier|const
block|{
return|return
name|quint16
argument_list|(
name|rgba
operator|>>
name|AlphaShift
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
name|void
name|setRed
parameter_list|(
name|quint16
name|_red
parameter_list|)
block|{
name|rgba
operator|=
operator|(
name|rgba
operator|&
operator|~
operator|(
name|Q_UINT64_C
argument_list|(
literal|0xffff
argument_list|)
operator|<<
name|RedShift
operator|)
operator|)
operator||
operator|(
name|quint64
argument_list|(
name|_red
argument_list|)
operator|<<
name|RedShift
operator|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|setGreen
parameter_list|(
name|quint16
name|_green
parameter_list|)
block|{
name|rgba
operator|=
operator|(
name|rgba
operator|&
operator|~
operator|(
name|Q_UINT64_C
argument_list|(
literal|0xffff
argument_list|)
operator|<<
name|GreenShift
operator|)
operator|)
operator||
operator|(
name|quint64
argument_list|(
name|_green
argument_list|)
operator|<<
name|GreenShift
operator|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|setBlue
parameter_list|(
name|quint16
name|_blue
parameter_list|)
block|{
name|rgba
operator|=
operator|(
name|rgba
operator|&
operator|~
operator|(
name|Q_UINT64_C
argument_list|(
literal|0xffff
argument_list|)
operator|<<
name|BlueShift
operator|)
operator|)
operator||
operator|(
name|quint64
argument_list|(
name|_blue
argument_list|)
operator|<<
name|BlueShift
operator|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|setAlpha
parameter_list|(
name|quint16
name|_alpha
parameter_list|)
block|{
name|rgba
operator|=
operator|(
name|rgba
operator|&
operator|~
operator|(
name|Q_UINT64_C
argument_list|(
literal|0xffff
argument_list|)
operator|<<
name|AlphaShift
operator|)
operator|)
operator||
operator|(
name|quint64
argument_list|(
name|_alpha
argument_list|)
operator|<<
name|AlphaShift
operator|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|Q_DECL_CONSTEXPR
name|quint8
name|red8
argument_list|()
specifier|const
block|{
return|return
name|div_257
argument_list|(
name|red
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
name|quint8
name|green8
argument_list|()
specifier|const
block|{
return|return
name|div_257
argument_list|(
name|green
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
name|quint8
name|blue8
argument_list|()
specifier|const
block|{
return|return
name|div_257
argument_list|(
name|blue
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
name|quint8
name|alpha8
argument_list|()
specifier|const
block|{
return|return
name|div_257
argument_list|(
name|alpha
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
name|uint
name|toArgb32
argument_list|()
specifier|const
block|{
return|return
name|uint
argument_list|(
operator|(
name|alpha8
argument_list|()
operator|<<
literal|24
operator|)
operator||
operator|(
name|red8
argument_list|()
operator|<<
literal|16
operator|)
operator||
operator|(
name|green8
argument_list|()
operator|<<
literal|8
operator|)
operator||
name|blue8
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
name|ushort
name|toRgb16
argument_list|()
specifier|const
block|{
return|return
name|ushort
argument_list|(
operator|(
name|red
argument_list|()
operator|&
literal|0xf800
operator|)
operator||
operator|(
operator|(
name|green
argument_list|()
operator|>>
literal|10
operator|)
operator|<<
literal|5
operator|)
operator||
operator|(
name|blue
argument_list|()
operator|>>
literal|11
operator|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_RELAXED_CONSTEXPR
name|QRgba64
name|premultiplied
argument_list|()
specifier|const
block|{
specifier|const
name|quint32
name|a
operator|=
name|alpha
argument_list|()
block|;
specifier|const
name|quint16
name|r
operator|=
name|div_65535
argument_list|(
name|red
argument_list|()
operator|*
name|a
argument_list|)
block|;
specifier|const
name|quint16
name|g
operator|=
name|div_65535
argument_list|(
name|green
argument_list|()
operator|*
name|a
argument_list|)
block|;
specifier|const
name|quint16
name|b
operator|=
name|div_65535
argument_list|(
name|blue
argument_list|()
operator|*
name|a
argument_list|)
block|;
return|return
name|fromRgba64
argument_list|(
name|r
argument_list|,
name|g
argument_list|,
name|b
argument_list|,
name|quint16
argument_list|(
name|a
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_RELAXED_CONSTEXPR
name|QRgba64
name|unpremultiplied
argument_list|()
specifier|const
block|{
if|#
directive|if
name|Q_PROCESSOR_WORDSIZE
operator|<
literal|8
return|return
name|unpremultiplied_32bit
argument_list|()
return|;
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_return
return|return
name|unpremultiplied_64bit
argument_list|()
return|;
end_return
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|}      Q_DECL_CONSTEXPR
name|operator
name|quint64
argument_list|()
specifier|const
block|{
return|return
name|rgba
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|QRgba64
name|operator
init|=
operator|(
name|quint64
name|_rgba
operator|)
block|{
name|rgba
operator|=
name|_rgba
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_function
specifier|static
name|Q_DECL_CONSTEXPR
name|Q_ALWAYS_INLINE
name|quint64
name|alphaMask
parameter_list|()
block|{
return|return
name|Q_UINT64_C
argument_list|(
literal|0xffff
argument_list|)
operator|<<
name|AlphaShift
return|;
block|}
end_function
begin_function
specifier|static
name|Q_DECL_CONSTEXPR
name|Q_ALWAYS_INLINE
name|quint8
name|div_257_floor
parameter_list|(
name|uint
name|x
parameter_list|)
block|{
return|return
name|quint8
argument_list|(
operator|(
name|x
operator|-
operator|(
name|x
operator|>>
literal|8
operator|)
operator|)
operator|>>
literal|8
argument_list|)
return|;
block|}
end_function
begin_function
specifier|static
name|Q_DECL_CONSTEXPR
name|Q_ALWAYS_INLINE
name|quint8
name|div_257
parameter_list|(
name|quint16
name|x
parameter_list|)
block|{
return|return
name|div_257_floor
argument_list|(
name|x
operator|+
literal|128U
argument_list|)
return|;
block|}
end_function
begin_function
specifier|static
name|Q_DECL_CONSTEXPR
name|Q_ALWAYS_INLINE
name|quint16
name|div_65535
parameter_list|(
name|uint
name|x
parameter_list|)
block|{
return|return
name|quint16
argument_list|(
operator|(
name|x
operator|+
operator|(
name|x
operator|>>
literal|16
operator|)
operator|+
literal|0x8000U
operator|)
operator|>>
literal|16
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
name|Q_DECL_RELAXED_CONSTEXPR
name|Q_ALWAYS_INLINE
name|QRgba64
name|unpremultiplied_32bit
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isOpaque
argument_list|()
operator|||
name|isTransparent
argument_list|()
condition|)
return|return
operator|*
name|this
return|;
specifier|const
name|quint32
name|a
operator|=
name|alpha
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|const
name|quint16
name|r
init|=
name|quint16
argument_list|(
operator|(
name|red
argument_list|()
operator|*
literal|0xffff
operator|+
name|a
operator|/
literal|2
operator|)
operator|/
name|a
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|quint16
name|g
init|=
name|quint16
argument_list|(
operator|(
name|green
argument_list|()
operator|*
literal|0xffff
operator|+
name|a
operator|/
literal|2
operator|)
operator|/
name|a
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|quint16
name|b
init|=
name|quint16
argument_list|(
operator|(
name|blue
argument_list|()
operator|*
literal|0xffff
operator|+
name|a
operator|/
literal|2
operator|)
operator|/
name|a
argument_list|)
decl_stmt|;
end_decl_stmt
begin_return
return|return
name|fromRgba64
argument_list|(
name|r
argument_list|,
name|g
argument_list|,
name|b
argument_list|,
name|quint16
argument_list|(
name|a
argument_list|)
argument_list|)
return|;
end_return
begin_expr_stmt
unit|}     Q_DECL_RELAXED_CONSTEXPR
name|Q_ALWAYS_INLINE
name|QRgba64
name|unpremultiplied_64bit
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isOpaque
argument_list|()
operator|||
name|isTransparent
argument_list|()
condition|)
return|return
operator|*
name|this
return|;
specifier|const
name|quint64
name|a
operator|=
name|alpha
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|const
name|quint64
name|fa
init|=
operator|(
name|Q_UINT64_C
argument_list|(
literal|0xffff00008000
argument_list|)
operator|+
name|a
operator|/
literal|2
operator|)
operator|/
name|a
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|quint16
name|r
init|=
name|quint16
argument_list|(
operator|(
name|red
argument_list|()
operator|*
name|fa
operator|+
literal|0x80000000
operator|)
operator|>>
literal|32
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|quint16
name|g
init|=
name|quint16
argument_list|(
operator|(
name|green
argument_list|()
operator|*
name|fa
operator|+
literal|0x80000000
operator|)
operator|>>
literal|32
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|quint16
name|b
init|=
name|quint16
argument_list|(
operator|(
name|blue
argument_list|()
operator|*
name|fa
operator|+
literal|0x80000000
operator|)
operator|>>
literal|32
argument_list|)
decl_stmt|;
end_decl_stmt
begin_return
return|return
name|fromRgba64
argument_list|(
name|r
argument_list|,
name|g
argument_list|,
name|b
argument_list|,
name|quint16
argument_list|(
name|a
argument_list|)
argument_list|)
return|;
end_return
begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QRgba64
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|qRgba64
name|Q_DECL_CONSTEXPR
specifier|inline
name|QRgba64
name|qRgba64
parameter_list|(
name|quint16
name|r
parameter_list|,
name|quint16
name|g
parameter_list|,
name|quint16
name|b
parameter_list|,
name|quint16
name|a
parameter_list|)
block|{
return|return
name|QRgba64
operator|::
name|fromRgba64
argument_list|(
name|r
argument_list|,
name|g
argument_list|,
name|b
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qRgba64
name|Q_DECL_CONSTEXPR
specifier|inline
name|QRgba64
name|qRgba64
parameter_list|(
name|quint64
name|c
parameter_list|)
block|{
return|return
name|QRgba64
operator|::
name|fromRgba64
argument_list|(
name|c
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qPremultiply
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|QRgba64
name|qPremultiply
parameter_list|(
name|QRgba64
name|c
parameter_list|)
block|{
return|return
name|c
operator|.
name|premultiplied
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|qUnpremultiply
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|QRgba64
name|qUnpremultiply
parameter_list|(
name|QRgba64
name|c
parameter_list|)
block|{
return|return
name|c
operator|.
name|unpremultiplied
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|qRed
specifier|inline
name|Q_DECL_CONSTEXPR
name|uint
name|qRed
parameter_list|(
name|QRgba64
name|rgb
parameter_list|)
block|{
return|return
name|rgb
operator|.
name|red8
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|qGreen
specifier|inline
name|Q_DECL_CONSTEXPR
name|uint
name|qGreen
parameter_list|(
name|QRgba64
name|rgb
parameter_list|)
block|{
return|return
name|rgb
operator|.
name|green8
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|qBlue
specifier|inline
name|Q_DECL_CONSTEXPR
name|uint
name|qBlue
parameter_list|(
name|QRgba64
name|rgb
parameter_list|)
block|{
return|return
name|rgb
operator|.
name|blue8
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|qAlpha
specifier|inline
name|Q_DECL_CONSTEXPR
name|uint
name|qAlpha
parameter_list|(
name|QRgba64
name|rgb
parameter_list|)
block|{
return|return
name|rgb
operator|.
name|alpha8
argument_list|()
return|;
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
comment|// QRGBA64_H
end_comment
end_unit
