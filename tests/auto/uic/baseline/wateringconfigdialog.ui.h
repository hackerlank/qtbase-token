begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'wateringconfigdialog.ui' ** ** Created: Fri Sep 4 10:17:15 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|WATERINGCONFIGDIALOG_H
end_ifndef
begin_define
DECL|macro|WATERINGCONFIGDIALOG_H
define|#
directive|define
name|WATERINGCONFIGDIALOG_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtGui/QAction>
end_include
begin_include
include|#
directive|include
file|<QtGui/QApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QButtonGroup>
end_include
begin_include
include|#
directive|include
file|<QtGui/QCheckBox>
end_include
begin_include
include|#
directive|include
file|<QtGui/QComboBox>
end_include
begin_include
include|#
directive|include
file|<QtGui/QDialog>
end_include
begin_include
include|#
directive|include
file|<QtGui/QDialogButtonBox>
end_include
begin_include
include|#
directive|include
file|<QtGui/QFrame>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QtGui/QHeaderView>
end_include
begin_include
include|#
directive|include
file|<QtGui/QLabel>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSpinBox>
end_include
begin_include
include|#
directive|include
file|<QtGui/QTimeEdit>
end_include
begin_include
include|#
directive|include
file|<QtGui/QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|"helpbrowser.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_WateringConfigDialog
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QLabel
modifier|*
name|label_3
decl_stmt|;
name|QComboBox
modifier|*
name|plantComboBox
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QLabel
modifier|*
name|label_2
decl_stmt|;
name|QCheckBox
modifier|*
name|temperatureCheckBox
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem1
decl_stmt|;
name|QSpinBox
modifier|*
name|temperatureSpinBox
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem2
decl_stmt|;
name|QCheckBox
modifier|*
name|rainCheckBox
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem3
decl_stmt|;
name|QSpinBox
modifier|*
name|rainSpinBox
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem4
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem5
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QTimeEdit
modifier|*
name|startTimeEdit
decl_stmt|;
name|QLabel
modifier|*
name|label_4
decl_stmt|;
name|QSpinBox
modifier|*
name|amountSpinBox
decl_stmt|;
name|QLabel
modifier|*
name|label_5
decl_stmt|;
name|QComboBox
modifier|*
name|sourceComboBox
decl_stmt|;
name|QLabel
modifier|*
name|label_6
decl_stmt|;
name|QCheckBox
modifier|*
name|filterCheckBox
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem6
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem7
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout1
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem8
decl_stmt|;
name|HelpBrowser
modifier|*
name|helpBrowser
decl_stmt|;
name|QLabel
modifier|*
name|helpLabel
decl_stmt|;
name|QFrame
modifier|*
name|line
decl_stmt|;
name|QDialogButtonBox
modifier|*
name|buttonBox
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|WateringConfigDialog
parameter_list|)
block|{
if|if
condition|(
name|WateringConfigDialog
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|WateringConfigDialog
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"WateringConfigDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|WateringConfigDialog
operator|->
name|resize
argument_list|(
literal|334
argument_list|,
literal|550
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"vboxLayout"
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
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"gridLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|label_3
operator|=
name|new
name|QLabel
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|label_3
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"label_3"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|label_3
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
name|plantComboBox
operator|=
name|new
name|QComboBox
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|plantComboBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"plantComboBox"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Preferred
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
decl_stmt|;
name|sizePolicy
operator|.
name|setHorizontalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy
operator|.
name|setVerticalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy
operator|.
name|setHeightForWidth
argument_list|(
name|plantComboBox
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|plantComboBox
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|plantComboBox
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|spacerItem
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|67
argument_list|,
literal|16
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addItem
argument_list|(
name|spacerItem
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
name|label_2
operator|=
name|new
name|QLabel
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"label_2"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|label_2
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
name|temperatureCheckBox
operator|=
name|new
name|QCheckBox
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|temperatureCheckBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"temperatureCheckBox"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|temperatureCheckBox
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|spacerItem1
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|16
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
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
name|spacerItem1
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|temperatureSpinBox
operator|=
name|new
name|QSpinBox
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|temperatureSpinBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"temperatureSpinBox"
argument_list|)
argument_list|)
expr_stmt|;
name|temperatureSpinBox
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|temperatureSpinBox
operator|->
name|setMinimum
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|temperatureSpinBox
operator|->
name|setMaximum
argument_list|(
literal|60
argument_list|)
expr_stmt|;
name|temperatureSpinBox
operator|->
name|setValue
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|temperatureSpinBox
argument_list|,
literal|4
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|spacerItem2
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
name|gridLayout
operator|->
name|addItem
argument_list|(
name|spacerItem2
argument_list|,
literal|4
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|rainCheckBox
operator|=
name|new
name|QCheckBox
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|rainCheckBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"rainCheckBox"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|rainCheckBox
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|spacerItem3
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|16
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
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
name|spacerItem3
argument_list|,
literal|6
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|rainSpinBox
operator|=
name|new
name|QSpinBox
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|rainSpinBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"rainSpinBox"
argument_list|)
argument_list|)
expr_stmt|;
name|rainSpinBox
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|rainSpinBox
operator|->
name|setMinimum
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|rainSpinBox
argument_list|,
literal|6
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|spacerItem4
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
name|gridLayout
operator|->
name|addItem
argument_list|(
name|spacerItem4
argument_list|,
literal|6
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|spacerItem5
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addItem
argument_list|(
name|spacerItem5
argument_list|,
literal|7
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|label
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"label"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|label
argument_list|,
literal|8
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|startTimeEdit
operator|=
name|new
name|QTimeEdit
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|startTimeEdit
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"startTimeEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|startTimeEdit
argument_list|,
literal|8
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|label_4
operator|=
name|new
name|QLabel
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|label_4
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"label_4"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|label_4
argument_list|,
literal|9
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|amountSpinBox
operator|=
name|new
name|QSpinBox
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|amountSpinBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"amountSpinBox"
argument_list|)
argument_list|)
expr_stmt|;
name|amountSpinBox
operator|->
name|setMinimum
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|amountSpinBox
operator|->
name|setMaximum
argument_list|(
literal|10000
argument_list|)
expr_stmt|;
name|amountSpinBox
operator|->
name|setSingleStep
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|amountSpinBox
operator|->
name|setValue
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|amountSpinBox
argument_list|,
literal|9
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|label_5
operator|=
name|new
name|QLabel
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|label_5
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"label_5"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|label_5
argument_list|,
literal|10
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|sourceComboBox
operator|=
name|new
name|QComboBox
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|sourceComboBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"sourceComboBox"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|sourceComboBox
argument_list|,
literal|10
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|label_6
operator|=
name|new
name|QLabel
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|label_6
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"label_6"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|label_6
argument_list|,
literal|11
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|filterCheckBox
operator|=
name|new
name|QCheckBox
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|filterCheckBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"filterCheckBox"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|filterCheckBox
argument_list|,
literal|11
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|spacerItem6
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|20
argument_list|,
literal|10
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addItem
argument_list|(
name|spacerItem6
argument_list|,
literal|12
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|spacerItem7
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
name|gridLayout
operator|->
name|addItem
argument_list|(
name|spacerItem7
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addLayout
argument_list|(
name|gridLayout
argument_list|)
expr_stmt|;
name|gridLayout1
operator|=
name|new
name|QGridLayout
argument_list|()
expr_stmt|;
name|gridLayout1
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"gridLayout1"
argument_list|)
argument_list|)
expr_stmt|;
name|spacerItem8
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
name|gridLayout1
operator|->
name|addItem
argument_list|(
name|spacerItem8
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
name|helpBrowser
operator|=
name|new
name|HelpBrowser
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|helpBrowser
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"helpBrowser"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|helpBrowser
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
name|helpLabel
operator|=
name|new
name|QLabel
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|helpLabel
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"helpLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|helpLabel
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
name|vboxLayout
operator|->
name|addLayout
argument_list|(
name|gridLayout1
argument_list|)
expr_stmt|;
name|line
operator|=
name|new
name|QFrame
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|line
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"line"
argument_list|)
argument_list|)
expr_stmt|;
name|line
operator|->
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|HLine
argument_list|)
expr_stmt|;
name|line
operator|->
name|setFrameShadow
argument_list|(
name|QFrame
operator|::
name|Sunken
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|line
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
name|new
name|QDialogButtonBox
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"buttonBox"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|setStandardButtons
argument_list|(
name|QDialogButtonBox
operator|::
name|Cancel
operator||
name|QDialogButtonBox
operator|::
name|NoButton
operator||
name|QDialogButtonBox
operator|::
name|Ok
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|WateringConfigDialog
argument_list|,
name|SLOT
argument_list|(
name|accept
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|rejected
argument_list|()
argument_list|)
argument_list|,
name|WateringConfigDialog
argument_list|,
name|SLOT
argument_list|(
name|reject
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|temperatureCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|temperatureSpinBox
argument_list|,
name|SLOT
argument_list|(
name|setEnabled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|rainCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|rainSpinBox
argument_list|,
name|SLOT
argument_list|(
name|setEnabled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|WateringConfigDialog
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|WateringConfigDialog
parameter_list|)
block|{
name|WateringConfigDialog
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Watering Configuration"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|label_3
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Plant:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|plantComboBox
operator|->
name|clear
argument_list|()
expr_stmt|;
name|plantComboBox
operator|->
name|insertItems
argument_list|(
literal|0
argument_list|,
name|QStringList
argument_list|()
operator|<<
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Squash"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
operator|<<
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Bean"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
operator|<<
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Carrot"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
operator|<<
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Strawberry"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
operator|<<
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Raspberry"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
operator|<<
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Blueberry"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Water when:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|temperatureCheckBox
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Temperature is higher than:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|temperatureSpinBox
operator|->
name|setSpecialValueText
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|temperatureSpinBox
operator|->
name|setSuffix
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"C"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|rainCheckBox
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Rain less than:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|rainSpinBox
operator|->
name|setSpecialValueText
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|rainSpinBox
operator|->
name|setSuffix
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"mm"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Starting Time:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|label_4
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Amount:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|amountSpinBox
operator|->
name|setSuffix
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"l"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|label_5
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Source:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|sourceComboBox
operator|->
name|clear
argument_list|()
expr_stmt|;
name|sourceComboBox
operator|->
name|insertItems
argument_list|(
literal|0
argument_list|,
name|QStringList
argument_list|()
operator|<<
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Foundain"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
operator|<<
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"River"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
operator|<<
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Lake"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
operator|<<
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Public Water System"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|label_6
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"Filter:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|filterCheckBox
operator|->
name|setText
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|helpLabel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WateringConfigDialog"
argument_list|,
literal|"<a href=\"test\">Show Details</a>"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
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
name|WateringConfigDialog
range|:
name|public
name|Ui_WateringConfigDialog
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
comment|// WATERINGCONFIGDIALOG_H
end_comment
end_unit
