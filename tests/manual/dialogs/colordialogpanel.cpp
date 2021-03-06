begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"colordialogpanel.h"
end_include
begin_include
include|#
directive|include
file|<QGroupBox>
end_include
begin_include
include|#
directive|include
file|<QCheckBox>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|<QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QHBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QMessageBox>
end_include
begin_include
include|#
directive|include
file|<QSortFilterProxyModel>
end_include
begin_include
include|#
directive|include
file|<QComboBox>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_comment
comment|// SVG color keyword names provided by the World Wide Web Consortium
end_comment
begin_function
DECL|function|svgColorNames
specifier|static
specifier|inline
name|QStringList
name|svgColorNames
parameter_list|()
block|{
return|return
name|QStringList
argument_list|()
operator|<<
literal|"aliceblue"
operator|<<
literal|"antiquewhite"
operator|<<
literal|"aqua"
operator|<<
literal|"aquamarine"
operator|<<
literal|"azure"
operator|<<
literal|"beige"
operator|<<
literal|"bisque"
operator|<<
literal|"black"
operator|<<
literal|"blanchedalmond"
operator|<<
literal|"blue"
operator|<<
literal|"blueviolet"
operator|<<
literal|"brown"
operator|<<
literal|"burlywood"
operator|<<
literal|"cadetblue"
operator|<<
literal|"chartreuse"
operator|<<
literal|"chocolate"
operator|<<
literal|"coral"
operator|<<
literal|"cornflowerblue"
operator|<<
literal|"cornsilk"
operator|<<
literal|"crimson"
operator|<<
literal|"cyan"
operator|<<
literal|"darkblue"
operator|<<
literal|"darkcyan"
operator|<<
literal|"darkgoldenrod"
operator|<<
literal|"darkgray"
operator|<<
literal|"darkgreen"
operator|<<
literal|"darkgrey"
operator|<<
literal|"darkkhaki"
operator|<<
literal|"darkmagenta"
operator|<<
literal|"darkolivegreen"
operator|<<
literal|"darkorange"
operator|<<
literal|"darkorchid"
operator|<<
literal|"darkred"
operator|<<
literal|"darksalmon"
operator|<<
literal|"darkseagreen"
operator|<<
literal|"darkslateblue"
operator|<<
literal|"darkslategray"
operator|<<
literal|"darkslategrey"
operator|<<
literal|"darkturquoise"
operator|<<
literal|"darkviolet"
operator|<<
literal|"deeppink"
operator|<<
literal|"deepskyblue"
operator|<<
literal|"dimgray"
operator|<<
literal|"dimgrey"
operator|<<
literal|"dodgerblue"
operator|<<
literal|"firebrick"
operator|<<
literal|"floralwhite"
operator|<<
literal|"forestgreen"
operator|<<
literal|"fuchsia"
operator|<<
literal|"gainsboro"
operator|<<
literal|"ghostwhite"
operator|<<
literal|"gold"
operator|<<
literal|"goldenrod"
operator|<<
literal|"gray"
operator|<<
literal|"grey"
operator|<<
literal|"green"
operator|<<
literal|"greenyellow"
operator|<<
literal|"honeydew"
operator|<<
literal|"hotpink"
operator|<<
literal|"indianred"
operator|<<
literal|"indigo"
operator|<<
literal|"ivory"
operator|<<
literal|"khaki"
operator|<<
literal|"lavender"
operator|<<
literal|"lavenderblush"
operator|<<
literal|"lawngreen"
operator|<<
literal|"lemonchiffon"
operator|<<
literal|"lightblue"
operator|<<
literal|"lightcoral"
operator|<<
literal|"lightcyan"
operator|<<
literal|"lightgoldenrodyellow"
operator|<<
literal|"lightgray"
operator|<<
literal|"lightgreen"
operator|<<
literal|"lightgrey"
operator|<<
literal|"lightpink"
operator|<<
literal|"lightsalmon"
operator|<<
literal|"lightseagreen"
operator|<<
literal|"lightskyblue"
operator|<<
literal|"lightslategray"
operator|<<
literal|"lightslategrey"
operator|<<
literal|"lightsteelblue"
operator|<<
literal|"lightyellow"
operator|<<
literal|"lime"
operator|<<
literal|"limegreen"
operator|<<
literal|"linen"
operator|<<
literal|"magenta"
operator|<<
literal|"maroon"
operator|<<
literal|"mediumaquamarine"
operator|<<
literal|"mediumblue"
operator|<<
literal|"mediumorchid"
operator|<<
literal|"mediumpurple"
operator|<<
literal|"mediumseagreen"
operator|<<
literal|"mediumslateblue"
operator|<<
literal|"mediumspringgreen"
operator|<<
literal|"mediumturquoise"
operator|<<
literal|"mediumvioletred"
operator|<<
literal|"midnightblue"
operator|<<
literal|"mintcream"
operator|<<
literal|"mistyrose"
operator|<<
literal|"moccasin"
operator|<<
literal|"navajowhite"
operator|<<
literal|"navy"
operator|<<
literal|"oldlace"
operator|<<
literal|"olive"
operator|<<
literal|"olivedrab"
operator|<<
literal|"orange"
operator|<<
literal|"orangered"
operator|<<
literal|"orchid"
operator|<<
literal|"palegoldenrod"
operator|<<
literal|"palegreen"
operator|<<
literal|"paleturquoise"
operator|<<
literal|"palevioletred"
operator|<<
literal|"papayawhip"
operator|<<
literal|"peachpuff"
operator|<<
literal|"peru"
operator|<<
literal|"pink"
operator|<<
literal|"plum"
operator|<<
literal|"powderblue"
operator|<<
literal|"purple"
operator|<<
literal|"red"
operator|<<
literal|"rosybrown"
operator|<<
literal|"royalblue"
operator|<<
literal|"saddlebrown"
operator|<<
literal|"salmon"
operator|<<
literal|"sandybrown"
operator|<<
literal|"seagreen"
operator|<<
literal|"seashell"
operator|<<
literal|"sienna"
operator|<<
literal|"silver"
operator|<<
literal|"skyblue"
operator|<<
literal|"slateblue"
operator|<<
literal|"slategray"
operator|<<
literal|"slategrey"
operator|<<
literal|"snow"
operator|<<
literal|"springgreen"
operator|<<
literal|"steelblue"
operator|<<
literal|"tan"
operator|<<
literal|"teal"
operator|<<
literal|"thistle"
operator|<<
literal|"tomato"
operator|<<
literal|"turquoise"
operator|<<
literal|"violet"
operator|<<
literal|"wheat"
operator|<<
literal|"white"
operator|<<
literal|"whitesmoke"
operator|<<
literal|"yellow"
operator|<<
literal|"yellowgreen"
return|;
block|}
end_function
begin_function
DECL|function|addButton
specifier|static
specifier|inline
name|QPushButton
modifier|*
name|addButton
parameter_list|(
specifier|const
name|QString
modifier|&
name|description
parameter_list|,
name|QVBoxLayout
modifier|*
name|layout
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|slotFunc
parameter_list|)
block|{
name|QPushButton
modifier|*
name|button
init|=
operator|new
name|QPushButton
argument_list|(
name|description
argument_list|)
decl_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|button
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|receiver
argument_list|,
name|slotFunc
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|button
argument_list|)
expr_stmt|;
return|return
name|button
return|;
block|}
end_function
begin_class
DECL|class|ColorProxyModel
class|class
name|ColorProxyModel
super|:
specifier|public
name|QSortFilterProxyModel
block|{
public|public:
DECL|function|ColorProxyModel
name|ColorProxyModel
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QSortFilterProxyModel
argument_list|(
name|parent
argument_list|)
block|{     }
DECL|function|data
name|QVariant
name|data
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
name|int
name|role
init|=
name|Qt
operator|::
name|DisplayRole
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|DisplayRole
condition|)
block|{
name|QString
name|name
init|=
name|data
argument_list|(
name|index
argument_list|,
name|Qt
operator|::
name|EditRole
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
return|return
name|tr
argument_list|(
literal|"%1 (%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|name
argument_list|,
name|QColor
argument_list|(
name|name
argument_list|)
operator|.
name|name
argument_list|()
argument_list|)
return|;
block|}
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|DecorationRole
condition|)
return|return
name|QColor
argument_list|(
name|data
argument_list|(
name|index
argument_list|,
name|Qt
operator|::
name|EditRole
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
return|;
return|return
name|QSortFilterProxyModel
operator|::
name|data
argument_list|(
name|index
argument_list|,
name|role
argument_list|)
return|;
block|}
block|}
class|;
end_class
begin_constructor
DECL|function|ColorDialogPanel
name|ColorDialogPanel
operator|::
name|ColorDialogPanel
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
name|m_colorComboBox
argument_list|(
operator|new
name|QComboBox
argument_list|)
member_init_list|,
name|m_showAlphaChannel
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Show alpha channel"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|m_noButtons
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Don't display OK/Cancel buttons"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|m_dontUseNativeDialog
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Don't use native dialog"
argument_list|)
argument_list|)
argument_list|)
block|{
comment|// Options
name|QGroupBox
modifier|*
name|optionsGroupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Options"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QVBoxLayout
modifier|*
name|optionsLayout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|optionsGroupBox
argument_list|)
decl_stmt|;
name|optionsLayout
operator|->
name|addWidget
argument_list|(
name|m_showAlphaChannel
argument_list|)
expr_stmt|;
name|optionsLayout
operator|->
name|addWidget
argument_list|(
name|m_noButtons
argument_list|)
expr_stmt|;
name|optionsLayout
operator|->
name|addWidget
argument_list|(
name|m_dontUseNativeDialog
argument_list|)
expr_stmt|;
comment|// Color
name|QGroupBox
modifier|*
name|colorGroupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Color"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QVBoxLayout
modifier|*
name|colorLayout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|colorGroupBox
argument_list|)
decl_stmt|;
name|colorLayout
operator|->
name|addWidget
argument_list|(
name|m_colorComboBox
argument_list|)
expr_stmt|;
name|m_colorComboBox
operator|->
name|addItems
argument_list|(
name|svgColorNames
argument_list|()
argument_list|)
expr_stmt|;
name|m_colorComboBox
operator|->
name|setEditable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QAbstractItemModel
modifier|*
name|sourceModel
init|=
name|m_colorComboBox
operator|->
name|model
argument_list|()
decl_stmt|;
name|ColorProxyModel
modifier|*
name|proxyModel
init|=
operator|new
name|ColorProxyModel
argument_list|(
name|m_colorComboBox
argument_list|)
decl_stmt|;
name|proxyModel
operator|->
name|setSourceModel
argument_list|(
name|sourceModel
argument_list|)
expr_stmt|;
name|sourceModel
operator|->
name|setParent
argument_list|(
name|proxyModel
argument_list|)
expr_stmt|;
name|m_colorComboBox
operator|->
name|setModel
argument_list|(
name|proxyModel
argument_list|)
expr_stmt|;
comment|// Buttons
name|QGroupBox
modifier|*
name|buttonsGroupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Show"
argument_list|)
argument_list|)
decl_stmt|;
name|QVBoxLayout
modifier|*
name|buttonsLayout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|buttonsGroupBox
argument_list|)
decl_stmt|;
name|addButton
argument_list|(
name|tr
argument_list|(
literal|"Exec modal"
argument_list|)
argument_list|,
name|buttonsLayout
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|execModal
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|addButton
argument_list|(
name|tr
argument_list|(
literal|"Show modal"
argument_list|)
argument_list|,
name|buttonsLayout
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showModal
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_deleteModalDialogButton
operator|=
name|addButton
argument_list|(
name|tr
argument_list|(
literal|"Delete modal"
argument_list|)
argument_list|,
name|buttonsLayout
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|deleteModalDialog
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|addButton
argument_list|(
name|tr
argument_list|(
literal|"Show non-modal"
argument_list|)
argument_list|,
name|buttonsLayout
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showNonModal
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_deleteNonModalDialogButton
operator|=
name|addButton
argument_list|(
name|tr
argument_list|(
literal|"Delete non-modal"
argument_list|)
argument_list|,
name|buttonsLayout
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|deleteNonModalDialog
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|addButton
argument_list|(
name|tr
argument_list|(
literal|"Restore defaults"
argument_list|)
argument_list|,
name|buttonsLayout
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|restoreDefaults
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|buttonsLayout
operator|->
name|addStretch
argument_list|()
expr_stmt|;
comment|// Main layout
name|QHBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QHBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QVBoxLayout
modifier|*
name|leftLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|leftLayout
operator|->
name|addWidget
argument_list|(
name|optionsGroupBox
argument_list|)
expr_stmt|;
name|leftLayout
operator|->
name|addWidget
argument_list|(
name|colorGroupBox
argument_list|)
expr_stmt|;
name|leftLayout
operator|->
name|addStretch
argument_list|()
expr_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|leftLayout
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|buttonsGroupBox
argument_list|)
expr_stmt|;
name|enableDeleteModalDialogButton
argument_list|()
expr_stmt|;
name|enableDeleteNonModalDialogButton
argument_list|()
expr_stmt|;
name|restoreDefaults
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|execModal
name|void
name|ColorDialogPanel
operator|::
name|execModal
parameter_list|()
block|{
name|QColorDialog
name|dialog
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|applySettings
argument_list|(
operator|&
name|dialog
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|dialog
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|dialog
argument_list|,
name|SIGNAL
argument_list|(
name|rejected
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|rejected
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|dialog
argument_list|,
name|SIGNAL
argument_list|(
name|currentColorChanged
argument_list|(
specifier|const
name|QColor
operator|&
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|currentColorChanged
argument_list|(
specifier|const
name|QColor
operator|&
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|dialog
operator|.
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Modal Color Dialog Qt %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|QT_VERSION_STR
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|dialog
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showModal
name|void
name|ColorDialogPanel
operator|::
name|showModal
parameter_list|()
block|{
if|if
condition|(
name|m_modalDialog
operator|.
name|isNull
argument_list|()
condition|)
block|{
specifier|static
name|int
name|n
init|=
literal|0
decl_stmt|;
name|m_modalDialog
operator|=
operator|new
name|QColorDialog
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_modalDialog
operator|->
name|setModal
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_modalDialog
operator|.
name|data
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_modalDialog
operator|.
name|data
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|rejected
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|rejected
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_modalDialog
operator|.
name|data
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|currentColorChanged
argument_list|(
specifier|const
name|QColor
operator|&
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|currentColorChanged
argument_list|(
specifier|const
name|QColor
operator|&
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_modalDialog
operator|->
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Modal Color Dialog #%1 Qt %2"
argument_list|)
operator|.
name|arg
argument_list|(
operator|++
name|n
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|QT_VERSION_STR
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|enableDeleteModalDialogButton
argument_list|()
expr_stmt|;
block|}
name|applySettings
argument_list|(
name|m_modalDialog
argument_list|)
expr_stmt|;
name|m_modalDialog
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showNonModal
name|void
name|ColorDialogPanel
operator|::
name|showNonModal
parameter_list|()
block|{
if|if
condition|(
name|m_nonModalDialog
operator|.
name|isNull
argument_list|()
condition|)
block|{
specifier|static
name|int
name|n
init|=
literal|0
decl_stmt|;
name|m_nonModalDialog
operator|=
operator|new
name|QColorDialog
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_nonModalDialog
operator|.
name|data
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_nonModalDialog
operator|.
name|data
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|rejected
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|rejected
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_nonModalDialog
operator|.
name|data
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|currentColorChanged
argument_list|(
specifier|const
name|QColor
operator|&
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|currentColorChanged
argument_list|(
specifier|const
name|QColor
operator|&
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_nonModalDialog
operator|->
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Non-Modal Color Dialog #%1 Qt %2"
argument_list|)
operator|.
name|arg
argument_list|(
operator|++
name|n
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|QT_VERSION_STR
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|enableDeleteNonModalDialogButton
argument_list|()
expr_stmt|;
block|}
name|applySettings
argument_list|(
name|m_nonModalDialog
argument_list|)
expr_stmt|;
name|m_nonModalDialog
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|deleteNonModalDialog
name|void
name|ColorDialogPanel
operator|::
name|deleteNonModalDialog
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_nonModalDialog
operator|.
name|isNull
argument_list|()
condition|)
operator|delete
name|m_nonModalDialog
expr_stmt|;
name|enableDeleteNonModalDialogButton
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|deleteModalDialog
name|void
name|ColorDialogPanel
operator|::
name|deleteModalDialog
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_modalDialog
operator|.
name|isNull
argument_list|()
condition|)
operator|delete
name|m_modalDialog
expr_stmt|;
name|enableDeleteModalDialogButton
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|accepted
name|void
name|ColorDialogPanel
operator|::
name|accepted
parameter_list|()
block|{
specifier|const
name|QColorDialog
modifier|*
name|d
init|=
name|qobject_cast
argument_list|<
specifier|const
name|QColorDialog
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|m_result
operator|.
name|clear
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Current color: "
operator|<<
name|d
operator|->
name|currentColor
argument_list|()
operator|<<
literal|"Selected color: "
operator|<<
name|d
operator|->
name|selectedColor
argument_list|()
expr_stmt|;
name|QDebug
argument_list|(
operator|&
name|m_result
argument_list|)
operator|.
name|nospace
argument_list|()
operator|<<
literal|"Current color: "
operator|<<
name|d
operator|->
name|currentColor
argument_list|()
operator|<<
literal|"\nSelected color: "
operator|<<
name|d
operator|->
name|selectedColor
argument_list|()
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showAcceptedResult
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// Avoid problems with the closing (modal) dialog as parent.
block|}
end_function
begin_function
DECL|function|rejected
name|void
name|ColorDialogPanel
operator|::
name|rejected
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"rejected"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentColorChanged
name|void
name|ColorDialogPanel
operator|::
name|currentColorChanged
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
name|color
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showAcceptedResult
name|void
name|ColorDialogPanel
operator|::
name|showAcceptedResult
parameter_list|()
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Color Dialog Accepted"
argument_list|)
argument_list|,
name|m_result
argument_list|,
name|QMessageBox
operator|::
name|Ok
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|restoreDefaults
name|void
name|ColorDialogPanel
operator|::
name|restoreDefaults
parameter_list|()
block|{
name|QColorDialog
name|d
decl_stmt|;
name|m_showAlphaChannel
operator|->
name|setChecked
argument_list|(
name|d
operator|.
name|testOption
argument_list|(
name|QColorDialog
operator|::
name|ShowAlphaChannel
argument_list|)
argument_list|)
expr_stmt|;
name|m_noButtons
operator|->
name|setChecked
argument_list|(
name|d
operator|.
name|testOption
argument_list|(
name|QColorDialog
operator|::
name|NoButtons
argument_list|)
argument_list|)
expr_stmt|;
name|m_dontUseNativeDialog
operator|->
name|setChecked
argument_list|(
name|d
operator|.
name|testOption
argument_list|(
name|QColorDialog
operator|::
name|DontUseNativeDialog
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enableDeleteNonModalDialogButton
name|void
name|ColorDialogPanel
operator|::
name|enableDeleteNonModalDialogButton
parameter_list|()
block|{
name|m_deleteNonModalDialogButton
operator|->
name|setEnabled
argument_list|(
operator|!
name|m_nonModalDialog
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enableDeleteModalDialogButton
name|void
name|ColorDialogPanel
operator|::
name|enableDeleteModalDialogButton
parameter_list|()
block|{
name|m_deleteModalDialogButton
operator|->
name|setEnabled
argument_list|(
operator|!
name|m_modalDialog
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|applySettings
name|void
name|ColorDialogPanel
operator|::
name|applySettings
parameter_list|(
name|QColorDialog
modifier|*
name|d
parameter_list|)
specifier|const
block|{
name|d
operator|->
name|setOption
argument_list|(
name|QColorDialog
operator|::
name|ShowAlphaChannel
argument_list|,
name|m_showAlphaChannel
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|setOption
argument_list|(
name|QColorDialog
operator|::
name|NoButtons
argument_list|,
name|m_noButtons
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|setOption
argument_list|(
name|QColorDialog
operator|::
name|DontUseNativeDialog
argument_list|,
name|m_dontUseNativeDialog
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|setCurrentColor
argument_list|(
name|QColor
argument_list|(
name|m_colorComboBox
operator|->
name|itemData
argument_list|(
name|m_colorComboBox
operator|->
name|currentIndex
argument_list|()
argument_list|,
name|Qt
operator|::
name|EditRole
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
