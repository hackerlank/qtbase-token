begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'preferencesdialog.ui' ** ** Created: Fri Sep 4 10:17:14 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PREFERENCESDIALOG_H
end_ifndef
begin_define
DECL|macro|PREFERENCESDIALOG_H
define|#
directive|define
name|PREFERENCESDIALOG_H
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
file|<QtWidgets/QDialog>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QDialogButtonBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QFrame>
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
file|<QtWidgets/QListWidget>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QToolButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<previewconfigurationwidget_p.h>
end_include
begin_include
include|#
directive|include
file|"fontpanel.h"
end_include
begin_include
include|#
directive|include
file|"gridpanel_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_PreferencesDialog
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout1
decl_stmt|;
name|QGroupBox
modifier|*
name|m_uiModeGroupBox
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout2
decl_stmt|;
name|QComboBox
modifier|*
name|m_uiModeCombo
decl_stmt|;
name|FontPanel
modifier|*
name|m_fontPanel
decl_stmt|;
name|qdesigner_internal
operator|::
name|PreviewConfigurationWidget
operator|*
name|m_previewConfigurationWidget
expr_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout3
decl_stmt|;
name|QGroupBox
modifier|*
name|m_templatePathGroupBox
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QListWidget
modifier|*
name|m_templatePathListWidget
decl_stmt|;
name|QToolButton
modifier|*
name|m_addTemplatePathButton
decl_stmt|;
name|QToolButton
modifier|*
name|m_removeTemplatePathButton
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|qdesigner_internal
operator|::
name|GridPanel
operator|*
name|m_gridPanel
expr_stmt|;
name|QFrame
modifier|*
name|line
decl_stmt|;
name|QDialogButtonBox
modifier|*
name|m_dialogButtonBox
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|PreferencesDialog
parameter_list|)
block|{
if|if
condition|(
name|PreferencesDialog
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|PreferencesDialog
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"PreferencesDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|PreferencesDialog
operator|->
name|resize
argument_list|(
literal|455
argument_list|,
literal|359
argument_list|)
expr_stmt|;
name|PreferencesDialog
operator|->
name|setModal
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|PreferencesDialog
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"vboxLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
name|hboxLayout
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"hboxLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|=
name|new
name|QVBoxLayout
argument_list|()
expr_stmt|;
name|vboxLayout1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"vboxLayout1"
argument_list|)
argument_list|)
expr_stmt|;
name|m_uiModeGroupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|PreferencesDialog
argument_list|)
expr_stmt|;
name|m_uiModeGroupBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"m_uiModeGroupBox"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|m_uiModeGroupBox
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"vboxLayout2"
argument_list|)
argument_list|)
expr_stmt|;
name|m_uiModeCombo
operator|=
name|new
name|QComboBox
argument_list|(
name|m_uiModeGroupBox
argument_list|)
expr_stmt|;
name|m_uiModeCombo
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"m_uiModeCombo"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|addWidget
argument_list|(
name|m_uiModeCombo
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addWidget
argument_list|(
name|m_uiModeGroupBox
argument_list|)
expr_stmt|;
name|m_fontPanel
operator|=
name|new
name|FontPanel
argument_list|(
name|PreferencesDialog
argument_list|)
expr_stmt|;
name|m_fontPanel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"m_fontPanel"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addWidget
argument_list|(
name|m_fontPanel
argument_list|)
expr_stmt|;
name|m_previewConfigurationWidget
operator|=
name|new
name|qdesigner_internal
operator|::
name|PreviewConfigurationWidget
argument_list|(
name|PreferencesDialog
argument_list|)
expr_stmt|;
name|m_previewConfigurationWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"m_previewConfigurationWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addWidget
argument_list|(
name|m_previewConfigurationWidget
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addLayout
argument_list|(
name|vboxLayout1
argument_list|)
expr_stmt|;
name|vboxLayout3
operator|=
name|new
name|QVBoxLayout
argument_list|()
expr_stmt|;
name|vboxLayout3
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"vboxLayout3"
argument_list|)
argument_list|)
expr_stmt|;
name|m_templatePathGroupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|PreferencesDialog
argument_list|)
expr_stmt|;
name|m_templatePathGroupBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"m_templatePathGroupBox"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|(
name|m_templatePathGroupBox
argument_list|)
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
name|m_templatePathListWidget
operator|=
name|new
name|QListWidget
argument_list|(
name|m_templatePathGroupBox
argument_list|)
expr_stmt|;
name|m_templatePathListWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"m_templatePathListWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|m_templatePathListWidget
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|m_addTemplatePathButton
operator|=
name|new
name|QToolButton
argument_list|(
name|m_templatePathGroupBox
argument_list|)
expr_stmt|;
name|m_addTemplatePathButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"m_addTemplatePathButton"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|m_addTemplatePathButton
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
name|m_removeTemplatePathButton
operator|=
name|new
name|QToolButton
argument_list|(
name|m_templatePathGroupBox
argument_list|)
expr_stmt|;
name|m_removeTemplatePathButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"m_removeTemplatePathButton"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|m_removeTemplatePathButton
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
name|spacerItem
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
name|spacerItem
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
name|vboxLayout3
operator|->
name|addWidget
argument_list|(
name|m_templatePathGroupBox
argument_list|)
expr_stmt|;
name|m_gridPanel
operator|=
name|new
name|qdesigner_internal
operator|::
name|GridPanel
argument_list|(
name|PreferencesDialog
argument_list|)
expr_stmt|;
name|m_gridPanel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"m_gridPanel"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout3
operator|->
name|addWidget
argument_list|(
name|m_gridPanel
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addLayout
argument_list|(
name|vboxLayout3
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addLayout
argument_list|(
name|hboxLayout
argument_list|)
expr_stmt|;
name|line
operator|=
name|new
name|QFrame
argument_list|(
name|PreferencesDialog
argument_list|)
expr_stmt|;
name|line
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
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
name|m_dialogButtonBox
operator|=
name|new
name|QDialogButtonBox
argument_list|(
name|PreferencesDialog
argument_list|)
expr_stmt|;
name|m_dialogButtonBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"m_dialogButtonBox"
argument_list|)
argument_list|)
expr_stmt|;
name|m_dialogButtonBox
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|m_dialogButtonBox
operator|->
name|setStandardButtons
argument_list|(
name|QDialogButtonBox
operator|::
name|Cancel
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
name|m_dialogButtonBox
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|PreferencesDialog
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|m_dialogButtonBox
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|PreferencesDialog
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
name|m_dialogButtonBox
argument_list|,
name|SIGNAL
argument_list|(
name|rejected
argument_list|()
argument_list|)
argument_list|,
name|PreferencesDialog
argument_list|,
name|SLOT
argument_list|(
name|reject
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|PreferencesDialog
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|PreferencesDialog
parameter_list|)
block|{
name|PreferencesDialog
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PreferencesDialog"
argument_list|,
literal|"Preferences"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|m_uiModeGroupBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PreferencesDialog"
argument_list|,
literal|"User Interface Mode"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|m_templatePathGroupBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PreferencesDialog"
argument_list|,
literal|"Additional Template Paths"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|m_addTemplatePathButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PreferencesDialog"
argument_list|,
literal|"..."
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|m_removeTemplatePathButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PreferencesDialog"
argument_list|,
literal|"..."
argument_list|,
literal|0
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
name|PreferencesDialog
range|:
name|public
name|Ui_PreferencesDialog
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
comment|// PREFERENCESDIALOG_H
end_comment
end_unit
