begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'qpagesetupwidget.ui' ** ** Created: Fri Sep 4 10:17:14 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAGESETUPWIDGET_H
end_ifndef
begin_define
DECL|macro|QPAGESETUPWIDGET_H
define|#
directive|define
name|QPAGESETUPWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QAction>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QApplication>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QButtonGroup>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QComboBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QDoubleSpinBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGroupBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QHBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QHeaderView>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QLabel>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QRadioButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_QPageSetupWidget
block|{
name|public
label|:
name|QGridLayout
modifier|*
name|gridLayout_3
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout_4
decl_stmt|;
name|QComboBox
modifier|*
name|unit
decl_stmt|;
name|QSpacerItem
modifier|*
name|horizontalSpacer_3
decl_stmt|;
name|QGroupBox
modifier|*
name|groupBox_2
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout_2
decl_stmt|;
name|QLabel
modifier|*
name|pageSizeLabel
decl_stmt|;
name|QComboBox
modifier|*
name|paperSize
decl_stmt|;
name|QLabel
modifier|*
name|widthLabel
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout_3
decl_stmt|;
name|QDoubleSpinBox
modifier|*
name|paperWidth
decl_stmt|;
name|QLabel
modifier|*
name|heightLabel
decl_stmt|;
name|QDoubleSpinBox
modifier|*
name|paperHeight
decl_stmt|;
name|QLabel
modifier|*
name|paperSourceLabel
decl_stmt|;
name|QComboBox
modifier|*
name|paperSource
decl_stmt|;
name|QSpacerItem
modifier|*
name|horizontalSpacer_4
decl_stmt|;
name|QGroupBox
modifier|*
name|groupBox_3
decl_stmt|;
name|QVBoxLayout
modifier|*
name|verticalLayout
decl_stmt|;
name|QRadioButton
modifier|*
name|portrait
decl_stmt|;
name|QRadioButton
modifier|*
name|landscape
decl_stmt|;
name|QRadioButton
modifier|*
name|reverseLandscape
decl_stmt|;
name|QRadioButton
modifier|*
name|reversePortrait
decl_stmt|;
name|QSpacerItem
modifier|*
name|verticalSpacer_5
decl_stmt|;
name|QWidget
modifier|*
name|preview
decl_stmt|;
name|QGroupBox
modifier|*
name|groupBox
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout_2
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QDoubleSpinBox
modifier|*
name|topMargin
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout
decl_stmt|;
name|QSpacerItem
modifier|*
name|horizontalSpacer_7
decl_stmt|;
name|QDoubleSpinBox
modifier|*
name|leftMargin
decl_stmt|;
name|QSpacerItem
modifier|*
name|horizontalSpacer
decl_stmt|;
name|QDoubleSpinBox
modifier|*
name|rightMargin
decl_stmt|;
name|QSpacerItem
modifier|*
name|horizontalSpacer_8
decl_stmt|;
name|QDoubleSpinBox
modifier|*
name|bottomMargin
decl_stmt|;
name|QSpacerItem
modifier|*
name|horizontalSpacer_2
decl_stmt|;
name|QSpacerItem
modifier|*
name|horizontalSpacer_5
decl_stmt|;
name|QSpacerItem
modifier|*
name|verticalSpacer
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QWidget
modifier|*
name|QPageSetupWidget
parameter_list|)
block|{
if|if
condition|(
name|QPageSetupWidget
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|QPageSetupWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"QPageSetupWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|QPageSetupWidget
operator|->
name|resize
argument_list|(
literal|416
argument_list|,
literal|488
argument_list|)
expr_stmt|;
name|gridLayout_3
operator|=
name|new
name|QGridLayout
argument_list|(
name|QPageSetupWidget
argument_list|)
expr_stmt|;
name|gridLayout_3
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|gridLayout_3
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"gridLayout_3"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_4
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
name|horizontalLayout_4
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"horizontalLayout_4"
argument_list|)
argument_list|)
expr_stmt|;
name|unit
operator|=
name|new
name|QComboBox
argument_list|(
name|QPageSetupWidget
argument_list|)
expr_stmt|;
name|unit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"unit"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_4
operator|->
name|addWidget
argument_list|(
name|unit
argument_list|)
expr_stmt|;
name|horizontalSpacer_3
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|40
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|horizontalLayout_4
operator|->
name|addItem
argument_list|(
name|horizontalSpacer_3
argument_list|)
expr_stmt|;
name|gridLayout_3
operator|->
name|addLayout
argument_list|(
name|horizontalLayout_4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|groupBox_2
operator|=
name|new
name|QGroupBox
argument_list|(
name|QPageSetupWidget
argument_list|)
expr_stmt|;
name|groupBox_2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"groupBox_2"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout_2
operator|=
name|new
name|QGridLayout
argument_list|(
name|groupBox_2
argument_list|)
expr_stmt|;
name|gridLayout_2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"gridLayout_2"
argument_list|)
argument_list|)
expr_stmt|;
name|pageSizeLabel
operator|=
name|new
name|QLabel
argument_list|(
name|groupBox_2
argument_list|)
expr_stmt|;
name|pageSizeLabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"pageSizeLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout_2
operator|->
name|addWidget
argument_list|(
name|pageSizeLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|paperSize
operator|=
name|new
name|QComboBox
argument_list|(
name|groupBox_2
argument_list|)
expr_stmt|;
name|paperSize
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"paperSize"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout_2
operator|->
name|addWidget
argument_list|(
name|paperSize
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|widthLabel
operator|=
name|new
name|QLabel
argument_list|(
name|groupBox_2
argument_list|)
expr_stmt|;
name|widthLabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"widthLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout_2
operator|->
name|addWidget
argument_list|(
name|widthLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|horizontalLayout_3
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
name|horizontalLayout_3
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"horizontalLayout_3"
argument_list|)
argument_list|)
expr_stmt|;
name|paperWidth
operator|=
name|new
name|QDoubleSpinBox
argument_list|(
name|groupBox_2
argument_list|)
expr_stmt|;
name|paperWidth
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"paperWidth"
argument_list|)
argument_list|)
expr_stmt|;
name|paperWidth
operator|->
name|setMaximum
argument_list|(
literal|9999.99
argument_list|)
expr_stmt|;
name|horizontalLayout_3
operator|->
name|addWidget
argument_list|(
name|paperWidth
argument_list|)
expr_stmt|;
name|heightLabel
operator|=
name|new
name|QLabel
argument_list|(
name|groupBox_2
argument_list|)
expr_stmt|;
name|heightLabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"heightLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_3
operator|->
name|addWidget
argument_list|(
name|heightLabel
argument_list|)
expr_stmt|;
name|paperHeight
operator|=
name|new
name|QDoubleSpinBox
argument_list|(
name|groupBox_2
argument_list|)
expr_stmt|;
name|paperHeight
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"paperHeight"
argument_list|)
argument_list|)
expr_stmt|;
name|paperHeight
operator|->
name|setMaximum
argument_list|(
literal|9999.99
argument_list|)
expr_stmt|;
name|horizontalLayout_3
operator|->
name|addWidget
argument_list|(
name|paperHeight
argument_list|)
expr_stmt|;
name|gridLayout_2
operator|->
name|addLayout
argument_list|(
name|horizontalLayout_3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|paperSourceLabel
operator|=
name|new
name|QLabel
argument_list|(
name|groupBox_2
argument_list|)
expr_stmt|;
name|paperSourceLabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"paperSourceLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout_2
operator|->
name|addWidget
argument_list|(
name|paperSourceLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|paperSource
operator|=
name|new
name|QComboBox
argument_list|(
name|groupBox_2
argument_list|)
expr_stmt|;
name|paperSource
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"paperSource"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout_2
operator|->
name|addWidget
argument_list|(
name|paperSource
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|horizontalSpacer_4
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|40
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|gridLayout_2
operator|->
name|addItem
argument_list|(
name|horizontalSpacer_4
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|gridLayout_3
operator|->
name|addWidget
argument_list|(
name|groupBox_2
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|groupBox_3
operator|=
name|new
name|QGroupBox
argument_list|(
name|QPageSetupWidget
argument_list|)
expr_stmt|;
name|groupBox_3
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"groupBox_3"
argument_list|)
argument_list|)
expr_stmt|;
name|verticalLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|groupBox_3
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"verticalLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|portrait
operator|=
name|new
name|QRadioButton
argument_list|(
name|groupBox_3
argument_list|)
expr_stmt|;
name|portrait
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"portrait"
argument_list|)
argument_list|)
expr_stmt|;
name|portrait
operator|->
name|setChecked
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|portrait
argument_list|)
expr_stmt|;
name|landscape
operator|=
name|new
name|QRadioButton
argument_list|(
name|groupBox_3
argument_list|)
expr_stmt|;
name|landscape
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"landscape"
argument_list|)
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|landscape
argument_list|)
expr_stmt|;
name|reverseLandscape
operator|=
name|new
name|QRadioButton
argument_list|(
name|groupBox_3
argument_list|)
expr_stmt|;
name|reverseLandscape
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"reverseLandscape"
argument_list|)
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|reverseLandscape
argument_list|)
expr_stmt|;
name|reversePortrait
operator|=
name|new
name|QRadioButton
argument_list|(
name|groupBox_3
argument_list|)
expr_stmt|;
name|reversePortrait
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"reversePortrait"
argument_list|)
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|reversePortrait
argument_list|)
expr_stmt|;
name|verticalSpacer_5
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addItem
argument_list|(
name|verticalSpacer_5
argument_list|)
expr_stmt|;
name|gridLayout_3
operator|->
name|addWidget
argument_list|(
name|groupBox_3
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|preview
operator|=
name|new
name|QWidget
argument_list|(
name|QPageSetupWidget
argument_list|)
expr_stmt|;
name|preview
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"preview"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout_3
operator|->
name|addWidget
argument_list|(
name|preview
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|groupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|QPageSetupWidget
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"groupBox"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_2
operator|=
name|new
name|QHBoxLayout
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|horizontalLayout_2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"horizontalLayout_2"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|()
expr_stmt|;
name|gridLayout
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"gridLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|topMargin
operator|=
name|new
name|QDoubleSpinBox
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|topMargin
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"topMargin"
argument_list|)
argument_list|)
expr_stmt|;
name|topMargin
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignRight
operator||
name|Qt
operator|::
name|AlignTrailing
operator||
name|Qt
operator|::
name|AlignVCenter
argument_list|)
expr_stmt|;
name|topMargin
operator|->
name|setMaximum
argument_list|(
literal|999.99
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|topMargin
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
name|horizontalLayout
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"horizontalLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalSpacer_7
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|->
name|addItem
argument_list|(
name|horizontalSpacer_7
argument_list|)
expr_stmt|;
name|leftMargin
operator|=
name|new
name|QDoubleSpinBox
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|leftMargin
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"leftMargin"
argument_list|)
argument_list|)
expr_stmt|;
name|leftMargin
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignRight
operator||
name|Qt
operator|::
name|AlignTrailing
operator||
name|Qt
operator|::
name|AlignVCenter
argument_list|)
expr_stmt|;
name|leftMargin
operator|->
name|setMaximum
argument_list|(
literal|999.99
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|->
name|addWidget
argument_list|(
name|leftMargin
argument_list|)
expr_stmt|;
name|horizontalSpacer
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|QSizePolicy
operator|::
name|MinimumExpanding
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|->
name|addItem
argument_list|(
name|horizontalSpacer
argument_list|)
expr_stmt|;
name|rightMargin
operator|=
name|new
name|QDoubleSpinBox
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|rightMargin
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"rightMargin"
argument_list|)
argument_list|)
expr_stmt|;
name|rightMargin
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignRight
operator||
name|Qt
operator|::
name|AlignTrailing
operator||
name|Qt
operator|::
name|AlignVCenter
argument_list|)
expr_stmt|;
name|rightMargin
operator|->
name|setMaximum
argument_list|(
literal|999.99
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|->
name|addWidget
argument_list|(
name|rightMargin
argument_list|)
expr_stmt|;
name|horizontalSpacer_8
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|->
name|addItem
argument_list|(
name|horizontalSpacer_8
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addLayout
argument_list|(
name|horizontalLayout
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|bottomMargin
operator|=
name|new
name|QDoubleSpinBox
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|bottomMargin
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"bottomMargin"
argument_list|)
argument_list|)
expr_stmt|;
name|bottomMargin
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignRight
operator||
name|Qt
operator|::
name|AlignTrailing
operator||
name|Qt
operator|::
name|AlignVCenter
argument_list|)
expr_stmt|;
name|bottomMargin
operator|->
name|setMaximum
argument_list|(
literal|999.99
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|bottomMargin
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|horizontalSpacer_2
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|MinimumExpanding
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addItem
argument_list|(
name|horizontalSpacer_2
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|horizontalSpacer_5
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|MinimumExpanding
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addItem
argument_list|(
name|horizontalSpacer_5
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|horizontalLayout_2
operator|->
name|addLayout
argument_list|(
name|gridLayout
argument_list|)
expr_stmt|;
name|gridLayout_3
operator|->
name|addWidget
argument_list|(
name|groupBox
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|verticalSpacer
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|20
argument_list|,
literal|0
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|gridLayout_3
operator|->
name|addItem
argument_list|(
name|verticalSpacer
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|pageSizeLabel
operator|->
name|setBuddy
argument_list|(
name|paperSize
argument_list|)
expr_stmt|;
name|widthLabel
operator|->
name|setBuddy
argument_list|(
name|paperWidth
argument_list|)
expr_stmt|;
name|heightLabel
operator|->
name|setBuddy
argument_list|(
name|paperHeight
argument_list|)
expr_stmt|;
name|paperSourceLabel
operator|->
name|setBuddy
argument_list|(
name|paperSource
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_SHORTCUT
name|retranslateUi
argument_list|(
name|QPageSetupWidget
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|QPageSetupWidget
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QWidget
modifier|*
name|QPageSetupWidget
parameter_list|)
block|{
name|QPageSetupWidget
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"Form"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|groupBox_2
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"Paper"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|pageSizeLabel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"Page size:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|widthLabel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"Width:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|heightLabel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"Height:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|paperSourceLabel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"Paper source:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|groupBox_3
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"Orientation"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|portrait
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"Portrait"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|landscape
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"Landscape"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|reverseLandscape
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"Reverse landscape"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|reversePortrait
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"Reverse portrait"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"Margins"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|topMargin
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"top margin"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|topMargin
operator|->
name|setAccessibleName
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"top margin"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_ACCESSIBILITY
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|leftMargin
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"left margin"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|leftMargin
operator|->
name|setAccessibleName
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"left margin"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_ACCESSIBILITY
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|rightMargin
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"right margin"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|rightMargin
operator|->
name|setAccessibleName
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"right margin"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_ACCESSIBILITY
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|bottomMargin
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"bottom margin"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|bottomMargin
operator|->
name|setAccessibleName
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPageSetupWidget"
argument_list|,
literal|"bottom margin"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_ACCESSIBILITY
block|}
comment|// retranslateUi
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|namespace
name|Ui
block|{
name|class
name|QPageSetupWidget
range|:
name|public
name|Ui_QPageSetupWidget
block|{}
decl_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace Ui
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPAGESETUPWIDGET_H
end_comment
end_unit
