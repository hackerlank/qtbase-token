begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfontcombobox.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FONTCOMBOBOX
end_ifndef
begin_include
include|#
directive|include
file|<qstringlistmodel.h>
end_include
begin_include
include|#
directive|include
file|<qitemdelegate.h>
end_include
begin_include
include|#
directive|include
file|<qlistview.h>
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<private/qcombobox_p.h>
end_include
begin_include
include|#
directive|include
file|<QDesktopWidget>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|writingSystemFromScript
specifier|static
name|QFontDatabase
operator|::
name|WritingSystem
name|writingSystemFromScript
parameter_list|(
name|QLocale
operator|::
name|Script
name|script
parameter_list|)
block|{
switch|switch
condition|(
name|script
condition|)
block|{
case|case
name|QLocale
operator|::
name|ArabicScript
case|:
return|return
name|QFontDatabase
operator|::
name|Arabic
return|;
case|case
name|QLocale
operator|::
name|CyrillicScript
case|:
return|return
name|QFontDatabase
operator|::
name|Cyrillic
return|;
case|case
name|QLocale
operator|::
name|GurmukhiScript
case|:
return|return
name|QFontDatabase
operator|::
name|Gurmukhi
return|;
case|case
name|QLocale
operator|::
name|SimplifiedHanScript
case|:
return|return
name|QFontDatabase
operator|::
name|SimplifiedChinese
return|;
case|case
name|QLocale
operator|::
name|TraditionalHanScript
case|:
return|return
name|QFontDatabase
operator|::
name|TraditionalChinese
return|;
case|case
name|QLocale
operator|::
name|LatinScript
case|:
return|return
name|QFontDatabase
operator|::
name|Latin
return|;
case|case
name|QLocale
operator|::
name|ArmenianScript
case|:
return|return
name|QFontDatabase
operator|::
name|Armenian
return|;
case|case
name|QLocale
operator|::
name|BengaliScript
case|:
return|return
name|QFontDatabase
operator|::
name|Bengali
return|;
case|case
name|QLocale
operator|::
name|DevanagariScript
case|:
return|return
name|QFontDatabase
operator|::
name|Devanagari
return|;
case|case
name|QLocale
operator|::
name|GeorgianScript
case|:
return|return
name|QFontDatabase
operator|::
name|Georgian
return|;
case|case
name|QLocale
operator|::
name|GreekScript
case|:
return|return
name|QFontDatabase
operator|::
name|Greek
return|;
case|case
name|QLocale
operator|::
name|GujaratiScript
case|:
return|return
name|QFontDatabase
operator|::
name|Gujarati
return|;
case|case
name|QLocale
operator|::
name|HebrewScript
case|:
return|return
name|QFontDatabase
operator|::
name|Hebrew
return|;
case|case
name|QLocale
operator|::
name|JapaneseScript
case|:
return|return
name|QFontDatabase
operator|::
name|Japanese
return|;
case|case
name|QLocale
operator|::
name|KhmerScript
case|:
return|return
name|QFontDatabase
operator|::
name|Khmer
return|;
case|case
name|QLocale
operator|::
name|KannadaScript
case|:
return|return
name|QFontDatabase
operator|::
name|Kannada
return|;
case|case
name|QLocale
operator|::
name|KoreanScript
case|:
return|return
name|QFontDatabase
operator|::
name|Korean
return|;
case|case
name|QLocale
operator|::
name|LaoScript
case|:
return|return
name|QFontDatabase
operator|::
name|Lao
return|;
case|case
name|QLocale
operator|::
name|MalayalamScript
case|:
return|return
name|QFontDatabase
operator|::
name|Malayalam
return|;
case|case
name|QLocale
operator|::
name|MyanmarScript
case|:
return|return
name|QFontDatabase
operator|::
name|Myanmar
return|;
case|case
name|QLocale
operator|::
name|TamilScript
case|:
return|return
name|QFontDatabase
operator|::
name|Tamil
return|;
case|case
name|QLocale
operator|::
name|TeluguScript
case|:
return|return
name|QFontDatabase
operator|::
name|Telugu
return|;
case|case
name|QLocale
operator|::
name|ThaanaScript
case|:
return|return
name|QFontDatabase
operator|::
name|Thaana
return|;
case|case
name|QLocale
operator|::
name|ThaiScript
case|:
return|return
name|QFontDatabase
operator|::
name|Thai
return|;
case|case
name|QLocale
operator|::
name|TibetanScript
case|:
return|return
name|QFontDatabase
operator|::
name|Tibetan
return|;
case|case
name|QLocale
operator|::
name|SinhalaScript
case|:
return|return
name|QFontDatabase
operator|::
name|Sinhala
return|;
case|case
name|QLocale
operator|::
name|SyriacScript
case|:
return|return
name|QFontDatabase
operator|::
name|Syriac
return|;
case|case
name|QLocale
operator|::
name|OriyaScript
case|:
return|return
name|QFontDatabase
operator|::
name|Oriya
return|;
case|case
name|QLocale
operator|::
name|OghamScript
case|:
return|return
name|QFontDatabase
operator|::
name|Ogham
return|;
case|case
name|QLocale
operator|::
name|RunicScript
case|:
return|return
name|QFontDatabase
operator|::
name|Runic
return|;
case|case
name|QLocale
operator|::
name|NkoScript
case|:
return|return
name|QFontDatabase
operator|::
name|Nko
return|;
default|default:
return|return
name|QFontDatabase
operator|::
name|Any
return|;
block|}
block|}
end_function
begin_function
DECL|function|writingSystemFromLocale
specifier|static
name|QFontDatabase
operator|::
name|WritingSystem
name|writingSystemFromLocale
parameter_list|()
block|{
name|QStringList
name|uiLanguages
init|=
name|QLocale
operator|::
name|system
argument_list|()
operator|.
name|uiLanguages
argument_list|()
decl_stmt|;
name|QLocale
operator|::
name|Script
name|script
decl_stmt|;
if|if
condition|(
operator|!
name|uiLanguages
operator|.
name|isEmpty
argument_list|()
condition|)
name|script
operator|=
name|QLocale
argument_list|(
name|uiLanguages
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|.
name|script
argument_list|()
expr_stmt|;
else|else
name|script
operator|=
name|QLocale
operator|::
name|system
argument_list|()
operator|.
name|script
argument_list|()
expr_stmt|;
return|return
name|writingSystemFromScript
argument_list|(
name|script
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|writingSystemForFont
specifier|static
name|QFontDatabase
operator|::
name|WritingSystem
name|writingSystemForFont
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|,
name|bool
modifier|*
name|hasLatin
parameter_list|)
block|{
name|QList
argument_list|<
name|QFontDatabase
operator|::
name|WritingSystem
argument_list|>
name|writingSystems
init|=
name|QFontDatabase
argument_list|()
operator|.
name|writingSystems
argument_list|(
name|font
operator|.
name|family
argument_list|()
argument_list|)
decl_stmt|;
comment|//     qDebug()<< font.family()<< writingSystems;
comment|// this just confuses the algorithm below. Vietnamese is Latin with lots of special chars
name|writingSystems
operator|.
name|removeOne
argument_list|(
name|QFontDatabase
operator|::
name|Vietnamese
argument_list|)
expr_stmt|;
operator|*
name|hasLatin
operator|=
name|writingSystems
operator|.
name|removeOne
argument_list|(
name|QFontDatabase
operator|::
name|Latin
argument_list|)
expr_stmt|;
if|if
condition|(
name|writingSystems
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QFontDatabase
operator|::
name|Any
return|;
name|QFontDatabase
operator|::
name|WritingSystem
name|system
init|=
name|writingSystemFromLocale
argument_list|()
decl_stmt|;
if|if
condition|(
name|writingSystems
operator|.
name|contains
argument_list|(
name|system
argument_list|)
condition|)
return|return
name|system
return|;
if|if
condition|(
name|system
operator|==
name|QFontDatabase
operator|::
name|TraditionalChinese
operator|&&
name|writingSystems
operator|.
name|contains
argument_list|(
name|QFontDatabase
operator|::
name|SimplifiedChinese
argument_list|)
condition|)
block|{
return|return
name|QFontDatabase
operator|::
name|SimplifiedChinese
return|;
block|}
if|if
condition|(
name|system
operator|==
name|QFontDatabase
operator|::
name|SimplifiedChinese
operator|&&
name|writingSystems
operator|.
name|contains
argument_list|(
name|QFontDatabase
operator|::
name|TraditionalChinese
argument_list|)
condition|)
block|{
return|return
name|QFontDatabase
operator|::
name|TraditionalChinese
return|;
block|}
name|system
operator|=
name|writingSystems
operator|.
name|last
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
operator|*
name|hasLatin
condition|)
block|{
comment|// we need to show something
return|return
name|system
return|;
block|}
if|if
condition|(
name|writingSystems
operator|.
name|count
argument_list|()
operator|==
literal|1
operator|&&
name|system
operator|>
name|QFontDatabase
operator|::
name|Cyrillic
condition|)
return|return
name|system
return|;
if|if
condition|(
name|writingSystems
operator|.
name|count
argument_list|()
operator|<=
literal|2
operator|&&
name|system
operator|>
name|QFontDatabase
operator|::
name|Armenian
operator|&&
name|system
operator|<
name|QFontDatabase
operator|::
name|Vietnamese
condition|)
return|return
name|system
return|;
if|if
condition|(
name|writingSystems
operator|.
name|count
argument_list|()
operator|<=
literal|5
operator|&&
name|system
operator|>=
name|QFontDatabase
operator|::
name|SimplifiedChinese
operator|&&
name|system
operator|<=
name|QFontDatabase
operator|::
name|Korean
condition|)
return|return
name|system
return|;
return|return
name|QFontDatabase
operator|::
name|Any
return|;
block|}
end_function
begin_class
DECL|class|QFontFamilyDelegate
class|class
name|QFontFamilyDelegate
super|:
specifier|public
name|QAbstractItemDelegate
block|{
name|Q_OBJECT
public|public:
specifier|explicit
name|QFontFamilyDelegate
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
constructor_decl|;
comment|// painting
name|void
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionViewItem
modifier|&
name|option
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
function_decl|;
name|QSize
name|sizeHint
parameter_list|(
specifier|const
name|QStyleOptionViewItem
modifier|&
name|option
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
function_decl|;
DECL|member|truetype
name|QIcon
name|truetype
decl_stmt|;
DECL|member|bitmap
name|QIcon
name|bitmap
decl_stmt|;
DECL|member|writingSystem
name|QFontDatabase
operator|::
name|WritingSystem
name|writingSystem
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QFontFamilyDelegate
name|QFontFamilyDelegate
operator|::
name|QFontFamilyDelegate
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractItemDelegate
argument_list|(
name|parent
argument_list|)
block|{
name|truetype
operator|=
name|QIcon
argument_list|(
name|QLatin1String
argument_list|(
literal|":/qt-project.org/styles/commonstyle/images/fonttruetype-16.png"
argument_list|)
argument_list|)
expr_stmt|;
name|bitmap
operator|=
name|QIcon
argument_list|(
name|QLatin1String
argument_list|(
literal|":/qt-project.org/styles/commonstyle/images/fontbitmap-16.png"
argument_list|)
argument_list|)
expr_stmt|;
name|writingSystem
operator|=
name|QFontDatabase
operator|::
name|Any
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|paint
name|void
name|QFontFamilyDelegate
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionViewItem
modifier|&
name|option
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
name|QString
name|text
init|=
name|index
operator|.
name|data
argument_list|(
name|Qt
operator|::
name|DisplayRole
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QFont
name|font
argument_list|(
name|option
operator|.
name|font
argument_list|)
decl_stmt|;
name|font
operator|.
name|setPointSize
argument_list|(
name|QFontInfo
argument_list|(
name|font
argument_list|)
operator|.
name|pointSize
argument_list|()
operator|*
literal|3
operator|/
literal|2
argument_list|)
expr_stmt|;
name|QFont
name|font2
init|=
name|font
decl_stmt|;
name|font2
operator|.
name|setFamily
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|bool
name|hasLatin
decl_stmt|;
name|QFontDatabase
operator|::
name|WritingSystem
name|system
init|=
name|writingSystemForFont
argument_list|(
name|font2
argument_list|,
operator|&
name|hasLatin
argument_list|)
decl_stmt|;
if|if
condition|(
name|hasLatin
condition|)
name|font
operator|=
name|font2
expr_stmt|;
name|QRect
name|r
init|=
name|option
operator|.
name|rect
decl_stmt|;
if|if
condition|(
name|option
operator|.
name|state
operator|&
name|QStyle
operator|::
name|State_Selected
condition|)
block|{
name|painter
operator|->
name|save
argument_list|()
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|option
operator|.
name|palette
operator|.
name|highlight
argument_list|()
argument_list|)
expr_stmt|;
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
name|drawRect
argument_list|(
name|option
operator|.
name|rect
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|option
operator|.
name|palette
operator|.
name|highlightedText
argument_list|()
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QIcon
modifier|*
name|icon
init|=
operator|&
name|bitmap
decl_stmt|;
if|if
condition|(
name|QFontDatabase
argument_list|()
operator|.
name|isSmoothlyScalable
argument_list|(
name|text
argument_list|)
condition|)
block|{
name|icon
operator|=
operator|&
name|truetype
expr_stmt|;
block|}
name|QSize
name|actualSize
init|=
name|icon
operator|->
name|actualSize
argument_list|(
name|r
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|icon
operator|->
name|paint
argument_list|(
name|painter
argument_list|,
name|r
argument_list|,
name|Qt
operator|::
name|AlignLeft
operator||
name|Qt
operator|::
name|AlignVCenter
argument_list|)
expr_stmt|;
if|if
condition|(
name|option
operator|.
name|direction
operator|==
name|Qt
operator|::
name|RightToLeft
condition|)
name|r
operator|.
name|setRight
argument_list|(
name|r
operator|.
name|right
argument_list|()
operator|-
name|actualSize
operator|.
name|width
argument_list|()
operator|-
literal|4
argument_list|)
expr_stmt|;
else|else
name|r
operator|.
name|setLeft
argument_list|(
name|r
operator|.
name|left
argument_list|()
operator|+
name|actualSize
operator|.
name|width
argument_list|()
operator|+
literal|4
argument_list|)
expr_stmt|;
name|QFont
name|old
init|=
name|painter
operator|->
name|font
argument_list|()
decl_stmt|;
name|painter
operator|->
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
comment|// If the ascent of the font is larger than the height of the rect,
comment|// we will clip the text, so it's better to align the tight bounding rect in this case
comment|// This is specifically for fonts where the ascent is very large compared to
comment|// the descent, like certain of the Stix family.
name|QFontMetricsF
name|fontMetrics
argument_list|(
name|font
argument_list|)
decl_stmt|;
if|if
condition|(
name|fontMetrics
operator|.
name|ascent
argument_list|()
operator|>
name|r
operator|.
name|height
argument_list|()
condition|)
block|{
name|QRectF
name|tbr
init|=
name|fontMetrics
operator|.
name|tightBoundingRect
argument_list|(
name|text
argument_list|)
decl_stmt|;
name|painter
operator|->
name|drawText
argument_list|(
name|r
operator|.
name|x
argument_list|()
argument_list|,
name|r
operator|.
name|y
argument_list|()
operator|+
operator|(
name|r
operator|.
name|height
argument_list|()
operator|+
name|tbr
operator|.
name|height
argument_list|()
operator|)
operator|/
literal|2.0
argument_list|,
name|text
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|painter
operator|->
name|drawText
argument_list|(
name|r
argument_list|,
name|Qt
operator|::
name|AlignVCenter
operator||
name|Qt
operator|::
name|AlignLeading
operator||
name|Qt
operator|::
name|TextSingleLine
argument_list|,
name|text
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|writingSystem
operator|!=
name|QFontDatabase
operator|::
name|Any
condition|)
name|system
operator|=
name|writingSystem
expr_stmt|;
if|if
condition|(
name|system
operator|!=
name|QFontDatabase
operator|::
name|Any
condition|)
block|{
name|int
name|w
init|=
name|painter
operator|->
name|fontMetrics
argument_list|()
operator|.
name|width
argument_list|(
name|text
operator|+
name|QLatin1String
argument_list|(
literal|"  "
argument_list|)
argument_list|)
decl_stmt|;
name|painter
operator|->
name|setFont
argument_list|(
name|font2
argument_list|)
expr_stmt|;
name|QString
name|sample
init|=
name|QFontDatabase
argument_list|()
operator|.
name|writingSystemSample
argument_list|(
name|system
argument_list|)
decl_stmt|;
if|if
condition|(
name|option
operator|.
name|direction
operator|==
name|Qt
operator|::
name|RightToLeft
condition|)
name|r
operator|.
name|setRight
argument_list|(
name|r
operator|.
name|right
argument_list|()
operator|-
name|w
argument_list|)
expr_stmt|;
else|else
name|r
operator|.
name|setLeft
argument_list|(
name|r
operator|.
name|left
argument_list|()
operator|+
name|w
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawText
argument_list|(
name|r
argument_list|,
name|Qt
operator|::
name|AlignVCenter
operator||
name|Qt
operator|::
name|AlignLeading
operator||
name|Qt
operator|::
name|TextSingleLine
argument_list|,
name|sample
argument_list|)
expr_stmt|;
block|}
name|painter
operator|->
name|setFont
argument_list|(
name|old
argument_list|)
expr_stmt|;
if|if
condition|(
name|option
operator|.
name|state
operator|&
name|QStyle
operator|::
name|State_Selected
condition|)
name|painter
operator|->
name|restore
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sizeHint
name|QSize
name|QFontFamilyDelegate
operator|::
name|sizeHint
parameter_list|(
specifier|const
name|QStyleOptionViewItem
modifier|&
name|option
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
name|QString
name|text
init|=
name|index
operator|.
name|data
argument_list|(
name|Qt
operator|::
name|DisplayRole
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QFont
name|font
argument_list|(
name|option
operator|.
name|font
argument_list|)
decl_stmt|;
comment|//     font.setFamily(text);
name|font
operator|.
name|setPointSize
argument_list|(
name|QFontInfo
argument_list|(
name|font
argument_list|)
operator|.
name|pointSize
argument_list|()
operator|*
literal|3
operator|/
literal|2
argument_list|)
expr_stmt|;
name|QFontMetrics
name|fontMetrics
argument_list|(
name|font
argument_list|)
decl_stmt|;
return|return
name|QSize
argument_list|(
name|fontMetrics
operator|.
name|width
argument_list|(
name|text
argument_list|)
argument_list|,
name|fontMetrics
operator|.
name|height
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_class
DECL|class|QFontComboBoxPrivate
class|class
name|QFontComboBoxPrivate
super|:
specifier|public
name|QComboBoxPrivate
block|{
public|public:
DECL|function|QFontComboBoxPrivate
specifier|inline
name|QFontComboBoxPrivate
parameter_list|()
block|{
name|filters
operator|=
name|QFontComboBox
operator|::
name|AllFonts
expr_stmt|;
block|}
DECL|member|filters
name|QFontComboBox
operator|::
name|FontFilters
name|filters
decl_stmt|;
DECL|member|currentFont
name|QFont
name|currentFont
decl_stmt|;
name|void
name|_q_updateModel
parameter_list|()
function_decl|;
name|void
name|_q_currentChanged
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QFontComboBox
argument_list|)
block|}
class|;
end_class
begin_function
DECL|function|_q_updateModel
name|void
name|QFontComboBoxPrivate
operator|::
name|_q_updateModel
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QFontComboBox
argument_list|)
expr_stmt|;
specifier|const
name|int
name|scalableMask
init|=
operator|(
name|QFontComboBox
operator|::
name|ScalableFonts
operator||
name|QFontComboBox
operator|::
name|NonScalableFonts
operator|)
decl_stmt|;
specifier|const
name|int
name|spacingMask
init|=
operator|(
name|QFontComboBox
operator|::
name|ProportionalFonts
operator||
name|QFontComboBox
operator|::
name|MonospacedFonts
operator|)
decl_stmt|;
name|QStringListModel
modifier|*
name|m
init|=
name|qobject_cast
argument_list|<
name|QStringListModel
operator|*
argument_list|>
argument_list|(
name|q
operator|->
name|model
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|m
condition|)
return|return;
name|QFontFamilyDelegate
modifier|*
name|delegate
init|=
name|qobject_cast
argument_list|<
name|QFontFamilyDelegate
operator|*
argument_list|>
argument_list|(
name|q
operator|->
name|view
argument_list|()
operator|->
name|itemDelegate
argument_list|()
argument_list|)
decl_stmt|;
name|QFontDatabase
operator|::
name|WritingSystem
name|system
init|=
name|delegate
condition|?
name|delegate
operator|->
name|writingSystem
else|:
name|QFontDatabase
operator|::
name|Any
decl_stmt|;
name|QFontDatabase
name|fdb
decl_stmt|;
name|QStringList
name|list
init|=
name|fdb
operator|.
name|families
argument_list|(
name|system
argument_list|)
decl_stmt|;
name|QStringList
name|result
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|QFontInfo
name|fi
argument_list|(
name|currentFont
argument_list|)
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
name|list
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|(
name|filters
operator|&
name|scalableMask
operator|)
operator|&&
operator|(
name|filters
operator|&
name|scalableMask
operator|)
operator|!=
name|scalableMask
condition|)
block|{
if|if
condition|(
name|bool
argument_list|(
name|filters
operator|&
name|QFontComboBox
operator|::
name|ScalableFonts
argument_list|)
operator|!=
name|fdb
operator|.
name|isSmoothlyScalable
argument_list|(
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
continue|continue;
block|}
if|if
condition|(
operator|(
name|filters
operator|&
name|spacingMask
operator|)
operator|&&
operator|(
name|filters
operator|&
name|spacingMask
operator|)
operator|!=
name|spacingMask
condition|)
block|{
if|if
condition|(
name|bool
argument_list|(
name|filters
operator|&
name|QFontComboBox
operator|::
name|MonospacedFonts
argument_list|)
operator|!=
name|fdb
operator|.
name|isFixedPitch
argument_list|(
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
continue|continue;
block|}
name|result
operator|+=
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|fi
operator|.
name|family
argument_list|()
operator|||
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|startsWith
argument_list|(
name|fi
operator|.
name|family
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|" ["
argument_list|)
argument_list|)
condition|)
name|offset
operator|=
name|result
operator|.
name|count
argument_list|()
operator|-
literal|1
expr_stmt|;
block|}
name|list
operator|=
name|result
expr_stmt|;
comment|//we need to block the signals so that the model doesn't emit reset
comment|//this prevents the current index from changing
comment|//it will be updated just after this
comment|///TODO: we should finda way to avoid blocking signals and have a real update of the model
block|{
specifier|const
name|QSignalBlocker
name|blocker
argument_list|(
name|m
argument_list|)
decl_stmt|;
name|m
operator|->
name|setStringList
argument_list|(
name|list
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|list
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|currentFont
operator|!=
name|QFont
argument_list|()
condition|)
block|{
name|currentFont
operator|=
name|QFont
argument_list|()
expr_stmt|;
emit|emit
name|q
operator|->
name|currentFontChanged
argument_list|(
name|currentFont
argument_list|)
emit|;
block|}
block|}
else|else
block|{
name|q
operator|->
name|setCurrentIndex
argument_list|(
name|offset
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|_q_currentChanged
name|void
name|QFontComboBoxPrivate
operator|::
name|_q_currentChanged
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QFontComboBox
argument_list|)
expr_stmt|;
if|if
condition|(
name|currentFont
operator|.
name|family
argument_list|()
operator|!=
name|text
condition|)
block|{
name|currentFont
operator|.
name|setFamily
argument_list|(
name|text
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|currentFontChanged
argument_list|(
name|currentFont
argument_list|)
emit|;
block|}
block|}
end_function
begin_comment
comment|/*!     \class QFontComboBox     \brief The QFontComboBox widget is a combobox that lets the user     select a font family.      \since 4.2     \ingroup basicwidgets     \inmodule QtWidgets      The combobox is populated with an alphabetized list of font     family names, such as Arial, Helvetica, and Times New Roman.     Family names are displayed using the actual font when possible.     For fonts such as Symbol, where the name is not representable in     the font itself, a sample of the font is displayed next to the     family name.      QFontComboBox is often used in toolbars, in conjunction with a     QComboBox for controlling the font size and two \l{QToolButton}s     for bold and italic.      When the user selects a new font, the currentFontChanged() signal     is emitted in addition to currentIndexChanged().      Call setWritingSystem() to tell QFontComboBox to show only fonts     that support a given writing system, and setFontFilters() to     filter out certain types of fonts as e.g. non scalable fonts or     monospaced fonts.      \image windowsvista-fontcombobox.png Screenshot of QFontComboBox on Windows Vista      \sa QComboBox, QFont, QFontInfo, QFontMetrics, QFontDatabase, {Character Map Example} */
end_comment
begin_comment
comment|/*!     \fn void QFontComboBox::setWritingSystem(QFontDatabase::WritingSystem script) */
end_comment
begin_comment
comment|/*!     \fn void QFontComboBox::setCurrentFont(const QFont&font); */
end_comment
begin_comment
comment|/*!     Constructs a font combobox with the given \a parent. */
end_comment
begin_constructor
DECL|function|QFontComboBox
name|QFontComboBox
operator|::
name|QFontComboBox
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QComboBox
argument_list|(
operator|*
operator|new
name|QFontComboBoxPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QFontComboBox
argument_list|)
expr_stmt|;
name|d
operator|->
name|currentFont
operator|=
name|font
argument_list|()
expr_stmt|;
name|setEditable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QStringListModel
modifier|*
name|m
init|=
operator|new
name|QStringListModel
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|setModel
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|setItemDelegate
argument_list|(
operator|new
name|QFontFamilyDelegate
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|QListView
modifier|*
name|lview
init|=
name|qobject_cast
argument_list|<
name|QListView
operator|*
argument_list|>
argument_list|(
name|view
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|lview
condition|)
name|lview
operator|->
name|setUniformItemSizes
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setWritingSystem
argument_list|(
name|QFontDatabase
operator|::
name|Any
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_currentChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|qApp
argument_list|,
name|SIGNAL
argument_list|(
name|fontDatabaseChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_updateModel
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the combobox. */
end_comment
begin_destructor
DECL|function|~QFontComboBox
name|QFontComboBox
operator|::
name|~
name|QFontComboBox
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \property QFontComboBox::writingSystem     \brief the writing system that serves as a filter for the combobox      If \a script is QFontDatabase::Any (the default), all fonts are     listed.      \sa fontFilters */
end_comment
begin_function
DECL|function|setWritingSystem
name|void
name|QFontComboBox
operator|::
name|setWritingSystem
parameter_list|(
name|QFontDatabase
operator|::
name|WritingSystem
name|script
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFontComboBox
argument_list|)
expr_stmt|;
name|QFontFamilyDelegate
modifier|*
name|delegate
init|=
name|qobject_cast
argument_list|<
name|QFontFamilyDelegate
operator|*
argument_list|>
argument_list|(
name|view
argument_list|()
operator|->
name|itemDelegate
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|delegate
condition|)
name|delegate
operator|->
name|writingSystem
operator|=
name|script
expr_stmt|;
name|d
operator|->
name|_q_updateModel
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|writingSystem
name|QFontDatabase
operator|::
name|WritingSystem
name|QFontComboBox
operator|::
name|writingSystem
parameter_list|()
specifier|const
block|{
name|QFontFamilyDelegate
modifier|*
name|delegate
init|=
name|qobject_cast
argument_list|<
name|QFontFamilyDelegate
operator|*
argument_list|>
argument_list|(
name|view
argument_list|()
operator|->
name|itemDelegate
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|delegate
condition|)
return|return
name|delegate
operator|->
name|writingSystem
return|;
return|return
name|QFontDatabase
operator|::
name|Any
return|;
block|}
end_function
begin_comment
comment|/*!   \enum QFontComboBox::FontFilter    This enum can be used to only show certain types of fonts in the font combo box.    \value AllFonts Show all fonts   \value ScalableFonts Show scalable fonts   \value NonScalableFonts Show non scalable fonts   \value MonospacedFonts Show monospaced fonts   \value ProportionalFonts Show proportional fonts */
end_comment
begin_comment
comment|/*!     \property QFontComboBox::fontFilters     \brief the filter for the combobox      By default, all fonts are listed.      \sa writingSystem */
end_comment
begin_function
DECL|function|setFontFilters
name|void
name|QFontComboBox
operator|::
name|setFontFilters
parameter_list|(
name|FontFilters
name|filters
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFontComboBox
argument_list|)
expr_stmt|;
name|d
operator|->
name|filters
operator|=
name|filters
expr_stmt|;
name|d
operator|->
name|_q_updateModel
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fontFilters
name|QFontComboBox
operator|::
name|FontFilters
name|QFontComboBox
operator|::
name|fontFilters
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFontComboBox
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|filters
return|;
block|}
end_function
begin_comment
comment|/*!     \property QFontComboBox::currentFont     \brief the currently selected font      \sa currentIndex, currentText */
end_comment
begin_function
DECL|function|currentFont
name|QFont
name|QFontComboBox
operator|::
name|currentFont
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFontComboBox
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|currentFont
return|;
block|}
end_function
begin_function
DECL|function|setCurrentFont
name|void
name|QFontComboBox
operator|::
name|setCurrentFont
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFontComboBox
argument_list|)
expr_stmt|;
if|if
condition|(
name|font
operator|!=
name|d
operator|->
name|currentFont
condition|)
block|{
name|d
operator|->
name|currentFont
operator|=
name|font
expr_stmt|;
name|d
operator|->
name|_q_updateModel
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|currentFont
operator|==
name|font
condition|)
block|{
comment|//else the signal has already be emitted by _q_updateModel
emit|emit
name|currentFontChanged
argument_list|(
name|d
operator|->
name|currentFont
argument_list|)
emit|;
block|}
block|}
block|}
end_function
begin_comment
comment|/*!     \fn QFontComboBox::currentFontChanged(const QFont&font)      This signal is emitted whenever the current font changes, with     the new \a font.      \sa currentFont */
end_comment
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QFontComboBox
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|Resize
condition|)
block|{
name|QListView
modifier|*
name|lview
init|=
name|qobject_cast
argument_list|<
name|QListView
operator|*
argument_list|>
argument_list|(
name|view
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|lview
condition|)
block|{
name|setFixedWidth
argument_list|(
name|qMin
argument_list|(
name|width
argument_list|()
operator|*
literal|5
operator|/
literal|3
argument_list|,
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|availableGeometry
argument_list|(
name|lview
argument_list|)
operator|.
name|width
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|QComboBox
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|QFontComboBox
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
name|QSize
name|sz
init|=
name|QComboBox
operator|::
name|sizeHint
argument_list|()
decl_stmt|;
name|QFontMetrics
name|fm
argument_list|(
name|font
argument_list|()
argument_list|)
decl_stmt|;
name|sz
operator|.
name|setWidth
argument_list|(
name|fm
operator|.
name|width
argument_list|(
name|QLatin1Char
argument_list|(
literal|'m'
argument_list|)
argument_list|)
operator|*
literal|14
argument_list|)
expr_stmt|;
return|return
name|sz
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"qfontcombobox.moc"
end_include
begin_include
include|#
directive|include
file|"moc_qfontcombobox.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FONTCOMBOBOX
end_comment
end_unit
