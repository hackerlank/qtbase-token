begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/* This is the default Qt style sheet.     IMPORTANT: This style sheet is primarily meant for defining feature    capablities of styles. Do NOT add default styling rules here. When in    doubt ask the stylesheet maintainer.     The stylesheet in here used to be in a CSS file, but was moved here to    avoid parsing overhead. */
end_comment
begin_include
include|#
directive|include
file|"private/qcssparser_p.h"
end_include
begin_include
include|#
directive|include
file|"qstylesheetstyle_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_STYLESHEET
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_using
using|using
namespace|namespace
name|QCss
namespace|;
end_using
begin_comment
comment|// This is the class name of the selector.
end_comment
begin_comment
comment|// Use an empty string where you would use '*' in CSS.
end_comment
begin_comment
comment|// Ex. QHeaderView
end_comment
begin_define
DECL|macro|SET_ELEMENT_NAME
define|#
directive|define
name|SET_ELEMENT_NAME
parameter_list|(
name|x
parameter_list|)
define|\
value|bSelector.elementName = (x)
end_define
begin_comment
comment|// This acts as both pseudo state and sub control. The first parameter is the
end_comment
begin_comment
comment|// string name, and the second is the PseudoClass_* constant.
end_comment
begin_comment
comment|// The sub control specifier is always the first, and has the type
end_comment
begin_comment
comment|// PseudoClass_Unknown.
end_comment
begin_comment
comment|// If there is no PseudoClass_Unknown as the first pseudo, it is assumed to be
end_comment
begin_comment
comment|// a pseudo state.
end_comment
begin_comment
comment|// Ex. QComboBox::drop-down:enabled
end_comment
begin_comment
comment|//                   ^         ^
end_comment
begin_define
DECL|macro|ADD_PSEUDO
define|#
directive|define
name|ADD_PSEUDO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|pseudo.type = (y); \     pseudo.name = (x); \     bSelector.pseudos<< pseudo
end_define
begin_comment
comment|// This is attributes. The third parameter is AttributeSelector::*
end_comment
begin_comment
comment|// Ex. QComboBox[style="QWindowsXPStyle"]
end_comment
begin_comment
comment|//                 ^           ^
end_comment
begin_define
DECL|macro|ADD_ATTRIBUTE_SELECTOR
define|#
directive|define
name|ADD_ATTRIBUTE_SELECTOR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|attr.name = (x); \     attr.value = (y); \     attr.valueMatchCriterium = (z); \     bSelector.attributeSelectors<< attr
end_define
begin_comment
comment|// Adds the current basic selector to the rule.
end_comment
begin_comment
comment|// Several basic selectors behave as AND (space in CSS).
end_comment
begin_define
DECL|macro|ADD_BASIC_SELECTOR
define|#
directive|define
name|ADD_BASIC_SELECTOR
define|\
value|selector.basicSelectors<< bSelector; \     bSelector.ids.clear(); \     bSelector.pseudos.clear(); \     bSelector.attributeSelectors.clear()
end_define
begin_comment
comment|// Adds the current selector to the rule.
end_comment
begin_comment
comment|// Several selectors behave as OR (comma in CSS).
end_comment
begin_define
DECL|macro|ADD_SELECTOR
define|#
directive|define
name|ADD_SELECTOR
define|\
value|styleRule.selectors<< selector; \     selector.basicSelectors.clear()
end_define
begin_comment
comment|// Sets the name of a property.
end_comment
begin_comment
comment|// Ex. background: red;
end_comment
begin_comment
comment|//         ^
end_comment
begin_define
DECL|macro|SET_PROPERTY
define|#
directive|define
name|SET_PROPERTY
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|decl.d->property = (x); \     decl.d->propertyId = (y)
end_define
begin_comment
comment|// Adds a value to the current property.
end_comment
begin_comment
comment|// The first parameter should be Value::KnownIdentifier if the value can be
end_comment
begin_comment
comment|// found among the Value_* constants, in which case the second should be that
end_comment
begin_comment
comment|// constant. Otherwise the first parameter is Value::Identifier and the second
end_comment
begin_comment
comment|// is a string.
end_comment
begin_comment
comment|// Adding more values is the same as seperating by spaces in CSS.
end_comment
begin_comment
comment|// Ex. border: 2px solid black;
end_comment
begin_comment
comment|//              ^    ^     ^
end_comment
begin_define
DECL|macro|ADD_VALUE
define|#
directive|define
name|ADD_VALUE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|value.type = (x); \     value.variant = (y); \     decl.d->values<< value
end_define
begin_comment
comment|// Adds the current declaration to the rule.
end_comment
begin_comment
comment|// Ex. border: 2px solid black;
end_comment
begin_comment
comment|//     \----------------------/
end_comment
begin_define
DECL|macro|ADD_DECLARATION
define|#
directive|define
name|ADD_DECLARATION
define|\
value|styleRule.declarations<< decl; \     decl.d.detach(); \     decl.d->values.clear()
end_define
begin_comment
comment|// Adds the rule to the stylesheet.
end_comment
begin_comment
comment|// Use at the end of every CSS block.
end_comment
begin_define
DECL|macro|ADD_STYLE_RULE
define|#
directive|define
name|ADD_STYLE_RULE
define|\
value|sheet.styleRules<< styleRule; \     styleRule.selectors.clear(); \     styleRule.declarations.clear()
end_define
begin_function
DECL|function|getDefaultStyleSheet
name|StyleSheet
name|QStyleSheetStyle
operator|::
name|getDefaultStyleSheet
parameter_list|()
specifier|const
block|{
name|StyleSheet
name|sheet
decl_stmt|;
name|StyleRule
name|styleRule
decl_stmt|;
name|BasicSelector
name|bSelector
decl_stmt|;
name|Selector
name|selector
decl_stmt|;
name|Declaration
name|decl
decl_stmt|;
name|QCss
operator|::
name|Value
name|value
decl_stmt|;
name|Pseudo
name|pseudo
decl_stmt|;
name|AttributeSelector
name|attr
decl_stmt|;
comment|// pixmap based style doesn't support any features
name|bool
name|styleIsPixmapBased
init|=
name|baseStyle
argument_list|()
operator|->
name|inherits
argument_list|(
literal|"QMacStyle"
argument_list|)
operator|||
name|baseStyle
argument_list|()
operator|->
name|inherits
argument_list|(
literal|"QWindowsXPStyle"
argument_list|)
decl_stmt|;
comment|/*QLineEdit {         -qt-background-role: base;         border: native;         -qt-style-features: background-color;     }*/
block|{
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLineEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"-qt-background-role"
argument_list|)
argument_list|,
name|QtBackgroundRole
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Base
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"border"
argument_list|)
argument_list|,
name|Border
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Native
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"-qt-style-features"
argument_list|)
argument_list|,
name|QtStyleFeatures
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|Identifier
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"background-color"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|ADD_STYLE_RULE
expr_stmt|;
block|}
comment|/*QLineEdit:no-frame {         border: none;     }*/
block|{
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLineEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_PSEUDO
argument_list|(
name|QLatin1String
argument_list|(
literal|"no-frame"
argument_list|)
argument_list|,
name|PseudoClass_Frameless
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"border"
argument_list|)
argument_list|,
name|Border
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_None
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|ADD_STYLE_RULE
expr_stmt|;
block|}
comment|/*QFrame {         border: native;     }*/
block|{
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QFrame"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"border"
argument_list|)
argument_list|,
name|Border
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Native
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|ADD_STYLE_RULE
expr_stmt|;
block|}
comment|/*QLabel, QToolBox {         background: none;         border-image: none;     }*/
block|{
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QToolBox"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"background"
argument_list|)
argument_list|,
name|Background
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_None
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"border-image"
argument_list|)
argument_list|,
name|BorderImage
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_None
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|ADD_STYLE_RULE
expr_stmt|;
block|}
comment|/*QGroupBox {         border: native;     }*/
block|{
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QGroupBox"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"border"
argument_list|)
argument_list|,
name|Border
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Native
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|ADD_STYLE_RULE
expr_stmt|;
block|}
comment|/*QToolTip {         -qt-background-role: window;         border: native;     }*/
block|{
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QToolTip"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"-qt-background-role"
argument_list|)
argument_list|,
name|QtBackgroundRole
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Window
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"border"
argument_list|)
argument_list|,
name|Border
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Native
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|ADD_STYLE_RULE
expr_stmt|;
block|}
comment|/*QPushButton, QToolButton {         border-style: native;         -qt-style-features: background-color;  //only for not pixmap based styles     }*/
block|{
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QPushButton"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QToolButton"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"border-style"
argument_list|)
argument_list|,
name|BorderStyles
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Native
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
if|if
condition|(
operator|!
name|styleIsPixmapBased
condition|)
block|{
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"-qt-style-features"
argument_list|)
argument_list|,
name|QtStyleFeatures
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|Identifier
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"background-color"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
block|}
name|ADD_STYLE_RULE
expr_stmt|;
block|}
comment|/*QComboBox {         border: native;         -qt-style-features: background-color background-gradient;   //only for not pixmap based styles         -qt-background-role: base;     }*/
block|{
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QComboBox"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"border"
argument_list|)
argument_list|,
name|Border
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Native
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
if|if
condition|(
operator|!
name|styleIsPixmapBased
condition|)
block|{
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"-qt-style-features"
argument_list|)
argument_list|,
name|QtStyleFeatures
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|Identifier
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"background-color"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|Identifier
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"background-gradient"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
block|}
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"-qt-background-role"
argument_list|)
argument_list|,
name|QtBackgroundRole
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Base
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|ADD_STYLE_RULE
expr_stmt|;
block|}
comment|/*QComboBox[style="QPlastiqueStyle"][readOnly="true"],     QComboBox[style="QFusionStyle"][readOnly="true"],     QComboBox[style="QCleanlooksStyle"][readOnly="true"]     {         -qt-background-role: button;     }*/
if|if
condition|(
name|baseStyle
argument_list|()
operator|->
name|inherits
argument_list|(
literal|"QPlastiqueStyle"
argument_list|)
operator|||
name|baseStyle
argument_list|()
operator|->
name|inherits
argument_list|(
literal|"QCleanlooksStyle"
argument_list|)
operator|||
name|baseStyle
argument_list|()
operator|->
name|inherits
argument_list|(
literal|"QFusionStyle"
argument_list|)
condition|)
block|{
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QComboBox"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_ATTRIBUTE_SELECTOR
argument_list|(
name|QLatin1String
argument_list|(
literal|"readOnly"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"true"
argument_list|)
argument_list|,
name|AttributeSelector
operator|::
name|MatchEqual
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"-qt-background-role"
argument_list|)
argument_list|,
name|QtBackgroundRole
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Button
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|ADD_STYLE_RULE
expr_stmt|;
block|}
comment|/*QAbstractSpinBox {         border: native;         -qt-style-features: background-color;         -qt-background-role: base;     }*/
block|{
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QAbstractSpinBox"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"border"
argument_list|)
argument_list|,
name|Border
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Native
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"-qt-style-features"
argument_list|)
argument_list|,
name|QtStyleFeatures
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|Identifier
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"background-color"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"-qt-background-role"
argument_list|)
argument_list|,
name|QtBackgroundRole
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Base
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|ADD_STYLE_RULE
expr_stmt|;
block|}
comment|/*QMenu {         -qt-background-role: window;     }*/
block|{
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QMenu"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"-qt-background-role"
argument_list|)
argument_list|,
name|QtBackgroundRole
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Window
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|ADD_STYLE_RULE
expr_stmt|;
block|}
comment|/*QMenu::item {         -qt-style-features: background-color;     }*/
if|if
condition|(
operator|!
name|styleIsPixmapBased
condition|)
block|{
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QMenu"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_PSEUDO
argument_list|(
name|QLatin1String
argument_list|(
literal|"item"
argument_list|)
argument_list|,
name|PseudoClass_Unknown
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"-qt-style-features"
argument_list|)
argument_list|,
name|QtStyleFeatures
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|Identifier
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"background-color"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|ADD_STYLE_RULE
expr_stmt|;
block|}
comment|/*QHeaderView {         -qt-background-role: window;     }*/
block|{
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QHeaderView"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"-qt-background-role"
argument_list|)
argument_list|,
name|QtBackgroundRole
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Window
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|ADD_STYLE_RULE
expr_stmt|;
block|}
comment|/*QTableCornerButton::section, QHeaderView::section {         -qt-background-role: button;         -qt-style-features: background-color; //if style is not pixmap based         border: native;     }*/
block|{
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QTableCornerButton"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_PSEUDO
argument_list|(
name|QLatin1String
argument_list|(
literal|"section"
argument_list|)
argument_list|,
name|PseudoClass_Unknown
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QHeaderView"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_PSEUDO
argument_list|(
name|QLatin1String
argument_list|(
literal|"section"
argument_list|)
argument_list|,
name|PseudoClass_Unknown
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"-qt-background-role"
argument_list|)
argument_list|,
name|QtBackgroundRole
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Button
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
if|if
condition|(
operator|!
name|styleIsPixmapBased
condition|)
block|{
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"-qt-style-features"
argument_list|)
argument_list|,
name|QtStyleFeatures
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|Identifier
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"background-color"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
block|}
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"border"
argument_list|)
argument_list|,
name|Border
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Native
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|ADD_STYLE_RULE
expr_stmt|;
block|}
comment|/*QProgressBar {         -qt-background-role: base;     }*/
block|{
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QProgressBar"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"-qt-background-role"
argument_list|)
argument_list|,
name|QtBackgroundRole
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Base
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|ADD_STYLE_RULE
expr_stmt|;
block|}
comment|/*QScrollBar {         -qt-background-role: window;     }*/
block|{
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QScrollBar"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"-qt-background-role"
argument_list|)
argument_list|,
name|QtBackgroundRole
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Window
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|ADD_STYLE_RULE
expr_stmt|;
block|}
comment|/*QDockWidget {         border: native;     }*/
block|{
name|SET_ELEMENT_NAME
argument_list|(
name|QLatin1String
argument_list|(
literal|"QDockWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|ADD_BASIC_SELECTOR
expr_stmt|;
name|ADD_SELECTOR
expr_stmt|;
name|SET_PROPERTY
argument_list|(
name|QLatin1String
argument_list|(
literal|"border"
argument_list|)
argument_list|,
name|Border
argument_list|)
expr_stmt|;
name|ADD_VALUE
argument_list|(
name|Value
operator|::
name|KnownIdentifier
argument_list|,
name|Value_Native
argument_list|)
expr_stmt|;
name|ADD_DECLARATION
expr_stmt|;
name|ADD_STYLE_RULE
expr_stmt|;
block|}
name|sheet
operator|.
name|origin
operator|=
name|StyleSheetOrigin_UserAgent
expr_stmt|;
name|sheet
operator|.
name|buildIndexes
argument_list|()
expr_stmt|;
return|return
name|sheet
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// #ifndef QT_NO_STYLE_STYLESHEET
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
