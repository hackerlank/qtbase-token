begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONT_H
end_ifndef
begin_define
DECL|macro|QFONT_H
define|#
directive|define
name|QFONT_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFontPrivate
name|class
name|QFontPrivate
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|QFontPrivate
comment|/* don't touch */
end_comment
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QFont
block|{
name|Q_GADGET
name|public
range|:     enum
name|StyleHint
block|{
name|Helvetica
block|,
name|SansSerif
operator|=
name|Helvetica
block|,
name|Times
block|,
name|Serif
operator|=
name|Times
block|,
name|Courier
block|,
name|TypeWriter
operator|=
name|Courier
block|,
name|OldEnglish
block|,
name|Decorative
operator|=
name|OldEnglish
block|,
name|System
block|,
name|AnyStyle
block|,
name|Cursive
block|,
name|Monospace
block|,
name|Fantasy
block|}
decl_stmt|;
enum|enum
name|StyleStrategy
block|{
name|PreferDefault
init|=
literal|0x0001
block|,
name|PreferBitmap
init|=
literal|0x0002
block|,
name|PreferDevice
init|=
literal|0x0004
block|,
name|PreferOutline
init|=
literal|0x0008
block|,
name|ForceOutline
init|=
literal|0x0010
block|,
name|PreferMatch
init|=
literal|0x0020
block|,
name|PreferQuality
init|=
literal|0x0040
block|,
name|PreferAntialias
init|=
literal|0x0080
block|,
name|NoAntialias
init|=
literal|0x0100
block|,
name|OpenGLCompatible
init|=
literal|0x0200
block|,
name|ForceIntegerMetrics
init|=
literal|0x0400
block|,
name|NoSubpixelAntialias
init|=
literal|0x0800
block|,
name|NoFontMerging
init|=
literal|0x8000
block|}
enum|;
name|Q_ENUM
argument_list|(
name|StyleStrategy
argument_list|)
expr|enum
name|HintingPreference
block|{
name|PreferDefaultHinting
operator|=
literal|0
block|,
name|PreferNoHinting
operator|=
literal|1
block|,
name|PreferVerticalHinting
operator|=
literal|2
block|,
name|PreferFullHinting
operator|=
literal|3
block|}
expr_stmt|;
comment|// Mapping OpenType weight value.
enum|enum
name|Weight
block|{
name|Thin
init|=
literal|0
block|,
comment|// 100
name|ExtraLight
init|=
literal|12
block|,
comment|// 200
name|Light
init|=
literal|25
block|,
comment|// 300
name|Normal
init|=
literal|50
block|,
comment|// 400
name|Medium
init|=
literal|57
block|,
comment|// 500
name|DemiBold
init|=
literal|63
block|,
comment|// 600
name|Bold
init|=
literal|75
block|,
comment|// 700
name|ExtraBold
init|=
literal|81
block|,
comment|// 800
name|Black
init|=
literal|87
comment|// 900
block|}
enum|;
enum|enum
name|Style
block|{
name|StyleNormal
block|,
name|StyleItalic
block|,
name|StyleOblique
block|}
enum|;
enum|enum
name|Stretch
block|{
name|UltraCondensed
init|=
literal|50
block|,
name|ExtraCondensed
init|=
literal|62
block|,
name|Condensed
init|=
literal|75
block|,
name|SemiCondensed
init|=
literal|87
block|,
name|Unstretched
init|=
literal|100
block|,
name|SemiExpanded
init|=
literal|112
block|,
name|Expanded
init|=
literal|125
block|,
name|ExtraExpanded
init|=
literal|150
block|,
name|UltraExpanded
init|=
literal|200
block|}
enum|;
enum|enum
name|Capitalization
block|{
name|MixedCase
block|,
name|AllUppercase
block|,
name|AllLowercase
block|,
name|SmallCaps
block|,
name|Capitalize
block|}
enum|;
enum|enum
name|SpacingType
block|{
name|PercentageSpacing
block|,
name|AbsoluteSpacing
block|}
enum|;
enum|enum
name|ResolveProperties
block|{
name|FamilyResolved
init|=
literal|0x0001
block|,
name|SizeResolved
init|=
literal|0x0002
block|,
name|StyleHintResolved
init|=
literal|0x0004
block|,
name|StyleStrategyResolved
init|=
literal|0x0008
block|,
name|WeightResolved
init|=
literal|0x0010
block|,
name|StyleResolved
init|=
literal|0x0020
block|,
name|UnderlineResolved
init|=
literal|0x0040
block|,
name|OverlineResolved
init|=
literal|0x0080
block|,
name|StrikeOutResolved
init|=
literal|0x0100
block|,
name|FixedPitchResolved
init|=
literal|0x0200
block|,
name|StretchResolved
init|=
literal|0x0400
block|,
name|KerningResolved
init|=
literal|0x0800
block|,
name|CapitalizationResolved
init|=
literal|0x1000
block|,
name|LetterSpacingResolved
init|=
literal|0x2000
block|,
name|WordSpacingResolved
init|=
literal|0x4000
block|,
name|HintingPreferenceResolved
init|=
literal|0x8000
block|,
name|StyleNameResolved
init|=
literal|0x10000
block|,
name|AllPropertiesResolved
init|=
literal|0x1ffff
block|}
enum|;
name|QFont
argument_list|()
expr_stmt|;
name|QFont
argument_list|(
argument|const QString&family
argument_list|,
argument|int pointSize = -
literal|1
argument_list|,
argument|int weight = -
literal|1
argument_list|,
argument|bool italic = false
argument_list|)
empty_stmt|;
name|QFont
argument_list|(
specifier|const
name|QFont
operator|&
argument_list|,
name|QPaintDevice
operator|*
name|pd
argument_list|)
expr_stmt|;
name|QFont
argument_list|(
specifier|const
name|QFont
operator|&
argument_list|)
expr_stmt|;
operator|~
name|QFont
argument_list|()
expr_stmt|;
name|void
name|swap
parameter_list|(
name|QFont
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
name|qSwap
argument_list|(
name|resolve_mask
argument_list|,
name|other
operator|.
name|resolve_mask
argument_list|)
expr_stmt|;
block|}
name|QString
name|family
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setFamily
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|QString
name|styleName
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setStyleName
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|int
name|pointSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPointSize
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|qreal
name|pointSizeF
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPointSizeF
parameter_list|(
name|qreal
parameter_list|)
function_decl|;
name|int
name|pixelSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPixelSize
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|int
name|weight
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWeight
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|bold
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|void
name|setBold
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|void
name|setStyle
parameter_list|(
name|Style
name|style
parameter_list|)
function_decl|;
name|Style
name|style
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|italic
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|void
name|setItalic
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
name|bool
name|underline
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setUnderline
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|bool
name|overline
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setOverline
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|bool
name|strikeOut
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setStrikeOut
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|bool
name|fixedPitch
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setFixedPitch
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|bool
name|kerning
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setKerning
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|StyleHint
name|styleHint
argument_list|()
specifier|const
expr_stmt|;
name|StyleStrategy
name|styleStrategy
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setStyleHint
parameter_list|(
name|StyleHint
parameter_list|,
name|StyleStrategy
init|=
name|PreferDefault
parameter_list|)
function_decl|;
name|void
name|setStyleStrategy
parameter_list|(
name|StyleStrategy
name|s
parameter_list|)
function_decl|;
name|int
name|stretch
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setStretch
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|qreal
name|letterSpacing
argument_list|()
specifier|const
expr_stmt|;
name|SpacingType
name|letterSpacingType
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLetterSpacing
parameter_list|(
name|SpacingType
name|type
parameter_list|,
name|qreal
name|spacing
parameter_list|)
function_decl|;
name|qreal
name|wordSpacing
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWordSpacing
parameter_list|(
name|qreal
name|spacing
parameter_list|)
function_decl|;
name|void
name|setCapitalization
parameter_list|(
name|Capitalization
parameter_list|)
function_decl|;
name|Capitalization
name|capitalization
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setHintingPreference
parameter_list|(
name|HintingPreference
name|hintingPreference
parameter_list|)
function_decl|;
name|HintingPreference
name|hintingPreference
argument_list|()
specifier|const
expr_stmt|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|5
argument_list|)
name|bool
name|rawMode
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setRawMode
parameter_list|(
name|bool
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// dupicated from QFontInfo
name|bool
name|exactMatch
argument_list|()
specifier|const
expr_stmt|;
name|QFont
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QFont
operator|&
operator|)
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QFont
operator|&
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QFont
operator|&
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QFont
operator|&
operator|)
specifier|const
expr_stmt|;
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isCopyOf
argument_list|(
specifier|const
name|QFont
operator|&
argument_list|)
decl|const
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QFont
modifier|&
name|operator
init|=
operator|(
name|QFont
operator|&&
name|other
operator|)
name|Q_DECL_NOEXCEPT
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
name|qSwap
argument_list|(
name|resolve_mask
argument_list|,
name|other
operator|.
name|resolve_mask
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|3
argument_list|)
comment|// needed for X11
name|QT_DEPRECATED
name|void
name|setRawName
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|QT_DEPRECATED
name|QString
name|rawName
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|QString
name|key
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|toString
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|fromString
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
specifier|static
name|QString
name|substitute
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
specifier|static
name|QStringList
name|substitutes
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
specifier|static
name|QStringList
name|substitutions
parameter_list|()
function_decl|;
specifier|static
name|void
name|insertSubstitution
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
specifier|static
name|void
name|insertSubstitutions
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QStringList
modifier|&
parameter_list|)
function_decl|;
specifier|static
name|void
name|removeSubstitutions
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
specifier|static
name|QT_DEPRECATED
name|void
name|removeSubstitution
parameter_list|(
specifier|const
name|QString
modifier|&
name|family
parameter_list|)
block|{
name|removeSubstitutions
argument_list|(
name|family
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
specifier|static
name|void
name|initialize
parameter_list|()
function_decl|;
specifier|static
name|void
name|cleanup
parameter_list|()
function_decl|;
specifier|static
name|void
name|cacheStatistics
parameter_list|()
function_decl|;
name|QString
name|defaultFamily
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|lastResortFamily
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|lastResortFont
argument_list|()
specifier|const
expr_stmt|;
name|QFont
name|resolve
argument_list|(
specifier|const
name|QFont
operator|&
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|uint
name|resolve
argument_list|()
specifier|const
block|{
return|return
name|resolve_mask
return|;
block|}
specifier|inline
name|void
name|resolve
parameter_list|(
name|uint
name|mask
parameter_list|)
block|{
name|resolve_mask
operator|=
name|mask
expr_stmt|;
block|}
name|private
label|:
name|explicit
name|QFont
parameter_list|(
name|QFontPrivate
modifier|*
parameter_list|)
function_decl|;
name|void
name|detach
parameter_list|()
function_decl|;
name|friend
name|class
name|QFontPrivate
decl_stmt|;
name|friend
name|class
name|QFontDialogPrivate
decl_stmt|;
name|friend
name|class
name|QFontMetrics
decl_stmt|;
name|friend
name|class
name|QFontMetricsF
decl_stmt|;
name|friend
name|class
name|QFontInfo
decl_stmt|;
name|friend
name|class
name|QPainter
decl_stmt|;
name|friend
name|class
name|QPainterPrivate
decl_stmt|;
name|friend
name|class
name|QApplication
decl_stmt|;
name|friend
name|class
name|QWidget
decl_stmt|;
name|friend
name|class
name|QWidgetPrivate
decl_stmt|;
name|friend
name|class
name|QTextLayout
decl_stmt|;
name|friend
name|class
name|QTextEngine
decl_stmt|;
name|friend
name|class
name|QStackTextEngine
decl_stmt|;
name|friend
name|class
name|QTextLine
decl_stmt|;
name|friend
struct_decl|struct
name|QScriptLine
struct_decl|;
name|friend
name|class
name|QOpenGLContext
decl_stmt|;
name|friend
name|class
name|QWin32PaintEngine
decl_stmt|;
name|friend
name|class
name|QAlphaPaintEngine
decl_stmt|;
name|friend
name|class
name|QPainterPath
decl_stmt|;
name|friend
name|class
name|QTextItemInt
decl_stmt|;
name|friend
name|class
name|QPicturePaintEngine
decl_stmt|;
name|friend
name|class
name|QPainterReplayer
decl_stmt|;
name|friend
name|class
name|QPaintBufferEngine
decl_stmt|;
name|friend
name|class
name|QCommandLinkButtonPrivate
decl_stmt|;
name|friend
name|class
name|QFontEngine
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QFont
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QFont
operator|&
operator|)
expr_stmt|;
endif|#
directive|endif
name|QExplicitlySharedDataPointer
operator|<
name|QFontPrivate
operator|>
name|d
expr_stmt|;
name|uint
name|resolve_mask
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QFont
argument_list|)
end_macro
begin_decl_stmt
name|Q_GUI_EXPORT
name|uint
name|qHash
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|,
name|uint
name|seed
operator|=
literal|0
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|inline
name|bool
name|QFont
operator|::
name|bold
argument_list|()
specifier|const
block|{
return|return
name|weight
argument_list|()
operator|>
name|Medium
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setBold
specifier|inline
name|void
name|QFont
operator|::
name|setBold
argument_list|(
argument|bool enable
argument_list|)
block|{
name|setWeight
argument_list|(
name|enable
operator|?
name|Bold
operator|:
name|Normal
argument_list|)
block|; }
DECL|function|italic
specifier|inline
name|bool
name|QFont
operator|::
name|italic
argument_list|()
specifier|const
block|{
return|return
operator|(
name|style
argument_list|()
operator|!=
name|StyleNormal
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setItalic
specifier|inline
name|void
name|QFont
operator|::
name|setItalic
argument_list|(
argument|bool b
argument_list|)
block|{
name|setStyle
argument_list|(
name|b
operator|?
name|StyleItalic
operator|:
name|StyleNormal
argument_list|)
block|; }
comment|/*****************************************************************************   QFont stream functions  *****************************************************************************/
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QFont
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QFont
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QFont
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFONT_H
end_comment
end_unit
