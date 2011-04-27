begin_unit
begin_comment
comment|/* ********************************************************************* ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the autotests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ********************************************************************* */
end_comment
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'newactiondialog.ui' ** ** Created: Fri Sep 4 10:17:14 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|NEWACTIONDIALOG_H
end_ifndef
begin_define
DECL|macro|NEWACTIONDIALOG_H
define|#
directive|define
name|NEWACTIONDIALOG_H
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
file|<QtGui/QFormLayout>
end_include
begin_include
include|#
directive|include
file|<QtGui/QFrame>
end_include
begin_include
include|#
directive|include
file|<QtGui/QHBoxLayout>
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
file|<QtGui/QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QtGui/QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|"iconselector_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|qdesigner_internal
block|{
name|class
name|Ui_NewActionDialog
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|verticalLayout
decl_stmt|;
name|QFormLayout
modifier|*
name|formLayout
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QLineEdit
modifier|*
name|editActionText
decl_stmt|;
name|QLabel
modifier|*
name|label_3
decl_stmt|;
name|QLineEdit
modifier|*
name|editObjectName
decl_stmt|;
name|QLabel
modifier|*
name|label_2
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout
decl_stmt|;
name|qdesigner_internal
operator|::
name|IconSelector
operator|*
name|iconSelector
expr_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QSpacerItem
modifier|*
name|verticalSpacer
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
name|qdesigner_internal__NewActionDialog
parameter_list|)
block|{
if|if
condition|(
name|qdesigner_internal__NewActionDialog
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|qdesigner_internal__NewActionDialog
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"qdesigner_internal__NewActionDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|qdesigner_internal__NewActionDialog
operator|->
name|resize
argument_list|(
literal|363
argument_list|,
literal|156
argument_list|)
expr_stmt|;
name|verticalLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|qdesigner_internal__NewActionDialog
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"verticalLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|formLayout
operator|=
name|new
name|QFormLayout
argument_list|()
expr_stmt|;
name|formLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"formLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|qdesigner_internal__NewActionDialog
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
name|formLayout
operator|->
name|setWidget
argument_list|(
literal|0
argument_list|,
name|QFormLayout
operator|::
name|LabelRole
argument_list|,
name|label
argument_list|)
expr_stmt|;
name|editActionText
operator|=
name|new
name|QLineEdit
argument_list|(
name|qdesigner_internal__NewActionDialog
argument_list|)
expr_stmt|;
name|editActionText
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"editActionText"
argument_list|)
argument_list|)
expr_stmt|;
name|editActionText
operator|->
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|setWidget
argument_list|(
literal|0
argument_list|,
name|QFormLayout
operator|::
name|FieldRole
argument_list|,
name|editActionText
argument_list|)
expr_stmt|;
name|label_3
operator|=
name|new
name|QLabel
argument_list|(
name|qdesigner_internal__NewActionDialog
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
name|formLayout
operator|->
name|setWidget
argument_list|(
literal|1
argument_list|,
name|QFormLayout
operator|::
name|LabelRole
argument_list|,
name|label_3
argument_list|)
expr_stmt|;
name|editObjectName
operator|=
name|new
name|QLineEdit
argument_list|(
name|qdesigner_internal__NewActionDialog
argument_list|)
expr_stmt|;
name|editObjectName
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"editObjectName"
argument_list|)
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|setWidget
argument_list|(
literal|1
argument_list|,
name|QFormLayout
operator|::
name|FieldRole
argument_list|,
name|editObjectName
argument_list|)
expr_stmt|;
name|label_2
operator|=
name|new
name|QLabel
argument_list|(
name|qdesigner_internal__NewActionDialog
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
name|formLayout
operator|->
name|setWidget
argument_list|(
literal|2
argument_list|,
name|QFormLayout
operator|::
name|LabelRole
argument_list|,
name|label_2
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
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"horizontalLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|iconSelector
operator|=
name|new
name|qdesigner_internal
operator|::
name|IconSelector
argument_list|(
name|qdesigner_internal__NewActionDialog
argument_list|)
expr_stmt|;
name|iconSelector
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"iconSelector"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|->
name|addWidget
argument_list|(
name|iconSelector
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
name|horizontalLayout
operator|->
name|addItem
argument_list|(
name|spacerItem
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|setLayout
argument_list|(
literal|2
argument_list|,
name|QFormLayout
operator|::
name|FieldRole
argument_list|,
name|horizontalLayout
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addLayout
argument_list|(
name|formLayout
argument_list|)
expr_stmt|;
name|verticalSpacer
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
name|verticalSpacer
argument_list|)
expr_stmt|;
name|line
operator|=
name|new
name|QFrame
argument_list|(
name|qdesigner_internal__NewActionDialog
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
name|verticalLayout
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
name|qdesigner_internal__NewActionDialog
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
name|Ok
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|label
operator|->
name|setBuddy
argument_list|(
name|editActionText
argument_list|)
expr_stmt|;
name|label_3
operator|->
name|setBuddy
argument_list|(
name|editObjectName
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setBuddy
argument_list|(
name|iconSelector
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_SHORTCUT
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|editActionText
argument_list|,
name|editObjectName
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|qdesigner_internal__NewActionDialog
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
name|qdesigner_internal__NewActionDialog
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
name|qdesigner_internal__NewActionDialog
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
name|qdesigner_internal__NewActionDialog
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|qdesigner_internal__NewActionDialog
parameter_list|)
block|{
name|qdesigner_internal__NewActionDialog
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::NewActionDialog"
argument_list|,
literal|"New Action..."
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
literal|"qdesigner_internal::NewActionDialog"
argument_list|,
literal|"&Text:"
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
literal|"qdesigner_internal::NewActionDialog"
argument_list|,
literal|"Object&name:"
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
literal|"qdesigner_internal::NewActionDialog"
argument_list|,
literal|"&Icon:"
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
empty_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace qdesigner_internal
end_comment
begin_decl_stmt
name|namespace
name|qdesigner_internal
block|{
name|namespace
name|Ui
block|{
name|class
name|NewActionDialog
range|:
name|public
name|Ui_NewActionDialog
block|{}
decl_stmt|;
block|}
comment|// namespace Ui
block|}
end_decl_stmt
begin_comment
comment|// namespace qdesigner_internal
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// NEWACTIONDIALOG_H
end_comment
end_unit
